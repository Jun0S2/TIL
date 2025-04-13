```
hp000@DESKTOP-BNVRTUJ MINGW64 /c/Workspace/consent-app/android (main)
$ vi local.properties
```

일단 local.properties 를 만들 나면, 빌드


# ✅ Android 앱 테스트 - Emulator에 APK 설치

##  1. `app-debug.apk` 빌드하기

VSCode에서 작성한 프로젝트 기준:

```bash
cd android
./gradlew assembleDebug
android/app/build/outputs/apk/debug/app-debug.apk
```

## 2. adb install이란?
adb (Android Debug Bridge)는 Android Emulator나 실제 디바이스와 명령어 기반으로 통신하는 도구

adb install은:

📲 기기/에뮬레이터에 APK 파일을 설치하는 명령어

에뮬레이터 실행 중이면 자동으로 연결됨

별도 마켓 없이 직접 설치 가능

##  3. 사용 방법
```
adb install android/app/build/outputs/apk/debug/app-debug.apk
```
리눅스보다 안드를 먼저 배웠다면 이게 더 쉬웠을까?
