# React에서 Kakao map 사용하는 방법

## Public > index.html 에 

```html
 <script
      type="text/javascript"
      src="//dapi.kakao.com/v2/maps/sdk.js?appkey=%REACT_APP_KAKAOMAP_API_KEY%&libraries=services,clusterer"
    ></script>
```

위와 같이 설정해준다.

## KAKAO MAP API KEY
인증키는 .env로 설정해 두었다.

1. `dotenv` 설치

```shell
npm install dotenv
또는
yarn install dotenv
```
를 통해 dotenv 모듈을 설치한다.

2. `.env` 파일의 위치

public, build,  src ... 등이 있는 파일 위치에 생성

![image](https://user-images.githubusercontent.com/36508552/161568099-de7663db-ec60-40d5-964c-71835f76c965.png)

3. 변수명은 반드시 `REACT_APP_`으로 시작

카카오맵 api경우, 

```.env
REACT_APP_KAKAOMAP_API_KEY=인증키번호
```

와 같이 지정해주었다.

## 기본적인 코드

이후부터는, 카카오맵의 sample api를 참고하면서 생성하면 된다.

##  커스텀 마커 이미지 등록

커스텀 마커를 사용하기 위해 src 폴더 안에다가 이미지를 불러왔는데 계속 실패했다 . 찾다보니 카카오에서 답변중에 아예 절대주소 (https://user-images.githubusercontent.com/이미지.png)
로 사용해보라고 답변이 온 것을 확인하고 나도 깃에 업로드하고 사용했다 :D

### 코드

```js
 var imageSrc =
        "https://github.com/Jun0S2/TIL/blob/main/REACT/marker_red.png?raw=true", // 마커이미지의 주소
      imageSize = new kakao.maps.Size(58, 64), // 마커이미지의 크기
      imageOption = { offset: new kakao.maps.Point(27, 69) }; // 마커이미지의 옵션입니다. 마커의 좌표와 일치시킬 이미지 안에서의 좌표를 설정

    // 마커의 이미지정보를 가지고 있는 마커이미지를 생성합니다
    var markerImage = new kakao.maps.MarkerImage(
      imageSrc,
      imageSize,
      imageOption
    );

    //마커 뿌리기
    function displayMarker(place: any) {
      let marker = new kakao.maps.Marker({
        map: map,
        position: new kakao.maps.LatLng(place.y, place.x),
        image: markerImage, // 마커 이미지
      });
```
위와 같은 코드로 커스텀 마커를 사용할 수 있었다
