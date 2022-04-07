
기존 alert 창이 안예뻐서 최종배포 디버깅 시간에 혹시 고쳐주실 수 있냐고 피드백을 받았다.

![image](https://user-images.githubusercontent.com/36508552/162218867-daf738e1-39e8-4c33-bccc-93c24d4d7f8e.png)

하지만, 이제와서 컴포넌트를 추가하는것도 늦었고, 저 ~~~ 내용 : 만 지울 수 있어도 반은 성공한거라고 생각했다.

검색해보니 `sweetalert` 라는 라이브러리가 있는데 알림창주제에 너무 이뻤다.

# 사용 방법

## 설치
```shell
npm i sweetalert
```

## 코드

```js
import SweetAlert from 'react-sweetalert';

...

swal("안녕");//alert("안녕");
```

너무 간편하다. sweetAlert2도 있다고 한다. 나중에 사용해보고싶다.

![image](https://user-images.githubusercontent.com/36508552/162218285-757c807c-d646-418d-a975-729159072c31.png)

너무 간편하게 예쁜 UI를 만들 수 있어서 편리하다. 
