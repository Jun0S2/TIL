> 그냥 혼자 앱 만들어보다가 local.properties 보고 발작 버튼 눌려서 정리한 TIL

# Background
`local.properties`는 Android 프로젝트에서만 사용하는 설정 파일인데, 개발자 PC마다 달라질 수 있는 로컬 개발 환경 정보를 담는 용도.

=>  즉, 안드로이드 프로젝트의 variant 를 리눅스 환경처럼 따로 파티션으로 저장하는게 아니라 local.properties 에다가 저장을 하고 있었는데 이 용도로 저장한 것 같음.

“이 프로젝트에서 Android SDK가 어디 있는지 알려주는 메모장” 같은 파일 => Git에 커밋되지 않음 (.gitignore로 자동 무시됨)

=> 인데? 그냥 배리언트 용으로 쓰고 있던 건 가봄.

----

# local.properties의 본질

Gradle만 참고하는 빌드 도구용 로컬 설정파일

APK 실행 시에는 앱 안에 포함되지 않음

즉, 런타임 환경(Android 앱 내부, 시스템 서비스 등)에서는 접근할 수 없음

👉 그래서 이걸 설정 파일처럼 사용하는 건 매우 제한적이고 비표준적인 사용임

# 차량용 안드로이드(Automotive/IVI)에서 왜 이렇게 했을까?

차량용 Android IVI 환경에서는 내부에 표준 config 저장소가 없거나, 내부 app에서 쓰기 어려운 구조일 수 있음 (왜 이런 설계인지는 아마도 이전 담당 책임님이 알고 있겠지)

그래서 Gradle 빌드 단계에서 변수를 집어넣고 그걸 Java 코드에 반영하는 용도로 쓰는 경우가 있음 (ex. BuildConfig.java로 export)

## Example

```java
// build.gradle
def variantType = project.hasProperty("variant_type") ? project.property("variant_type") : "default"

android {
  defaultConfig {
    buildConfigField "String", "VARIANT_TYPE", "\"${variantType}\""
  }
}
```
그리고 실행 시 BuildConfig.VARIANT_TYPE 로 접근 가능

# QNX 는 local.properties 를 읽지 못하는 충돌 발생함

## QNX는 local.properties 못 읽는 이유?
QNX는 아예 Android 파티션 구조랑 독립적이고

`local.properties`는 프로젝트 빌드 경로 안에 존재하므로, 런타임 시스템(OS 레벨)에서는 존재조차 안 함

# 대안
## 1. 런타임 접근 가능한 config 저장 위치

* A. Android SharedPreferences	: 앱 내부에서 JSON 등으로 저장 가능
* B. /vendor/etc/variant.conf 같은 위치	: 커스텀 파일 직접 마운트해서 파싱 가능 (읽기전용)
* C. BuildConfig export	: Gradle 빌드시 변수 삽입해서 앱에서 읽도록

## 2. QNX ↔ Android 통신 필요 시
* A. Binder / HAL (AIDL)	공식적 IPC, 안정성 있음
* B. Unix Socket	빠르고 가벼움, C++ ↔ Java 연동 용이
* C. 공유 메모리	빠르지만 구현 복잡도 있음
* D. 가상파일 기반 (/data/vendor 등)	양쪽에서 파일 읽는 구조 가능

-> 참으로 기묘한 구조인게, vendor 는 PM 들이 쓰는 영역으로 되어있는 이상한 설계임.

### ChatGPT 선생님 의견,,
"QNX ↔ Android ↔ 하이퍼바이저 경계 넘는 통신" 이거 완전 시스템 통합급 문제인데, 지금 상황에서 Binder / HAL 과 Unix Socket의 쓰임을 정확히 짚고, QNX랑 어떻게 다리 놓을 수 있는지도 현실적으로 정리해줄게.

1. AIDL / Binder / HAL (너 이미 있음)
✔️ Binder IPC란?
안드로이드 앱 ↔ 시스템 서비스 간 통신을 위한 IPC(Inter-Process Communication) 메커니즘

AIDL (Android Interface Definition Language)을 이용해 정의

예: App → CarService → HAL Module → JNI → Native Layer

✔️ 너 상황에선?
안드로이드 앱이나 system service ↔ HAL 모듈 (JNI / native) ↔ 차량 하드웨어 제어 구조가 이미 구축돼 있음

BUT 이 구조는 QNX랑 직접 통신은 불가능함
→ QNX는 Android의 Binder를 모름. 완전 별도 OS.

✅ 2. Unix Domain Socket (C++ ↔ Java 가능)
✔️ 이게 뭔데?
동일 디바이스 안에서 OS 레벨 통신 가능 (파일 기반의 빠른 IPC)

QNX ↔ Android 간에는 공유되는 파일 시스템 경로를 전제로 할 수 있음 (예: /dev/socket/, /data/vendor/ 같은 영역)
=> 근데 PM 꺼임.. ㅡㅡ

✔️ Android에서 사용 예시 (Java):
java
```
LocalSocket socket = new LocalSocket();
socket.connect(new LocalSocketAddress("your_socket_name", LocalSocketAddress.Namespace.RESERVED));
OutputStream os = socket.getOutputStream();
os.write("hello".getBytes());
```

✔️ QNX에서 사용 예시 (C/C++):
cpp
```
int sock = socket(AF_UNIX, SOCK_STREAM, 0);
struct sockaddr_un addr;
addr.sun_family = AF_UNIX;
strcpy(addr.sun_path, "/dev/socket/your_socket_name");
connect(sock, (struct sockaddr*)&addr, sizeof(addr));
```

💡 핵심: 양쪽 OS가 동일한 파일 경로(/dev/socket/...)를 공유해야 가능
→ 대부분 하이퍼바이저 설정 또는 shared mount point 필요

🔥 QNX ↔ Android 하이퍼바이저가 다르다?
그럼 경로 공유 불가능일 확률 높음.
→ Socket도, File도 직접적인 공유 불가

✅ 현실적인 대안: "중계자 만들기"
방식	구조	설명
🅰️ Shared Memory or VirtIO	QNX ↔ Hypervisor ↔ Android	하이퍼바이저가 공유 메모리 지원할 경우
🅱️ MQTT or TCP Loopback	QNX ↔ (broker or VM bridge) ↔ Android	브로커 기반 메시지 통신
🅲️ Custom Relay Daemon (Linux side)	QNX ↔ Custom Linux ↔ Android	두 VM 사이에 공유 자원 가진 "메시지 중계자" 프로세스 운영

🚨 핵심 요약

* AIDL/Binder	✅ Android 내부용	Android ↔ HAL ↔ Native 에 적합
* Unix Socket	⚠️ 공유 경로 있을 때만 가능	하이퍼바이저 분리면 불가
* Shared file/partition	⚠️ QNX ↔ Android 모두 접근 가능할 때만	대부분 하이퍼바이저 커스터마이징 필요
* 중계자 패턴	✅	가장 현실적인 연결 방식

# 대안
1. Android에서 특정 procfs 또는 sysfs 시뮬레이션 파일 쓰기

```
/mn네


3. Android → CAN/UART 에 "flag 전송" → QNX에서 수신
```
Android → HAL → MCU → QNX
```
* Android는 MCU에 variant 전송
* QNX는 CAN 또는 UART 인터럽트 기반으로 수신


MCU 경유	❌ MCU 쪽과 협의 필요	⭐⭐⭐	중
