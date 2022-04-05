[GET - HTTP | MDN](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/GET)

`request body` 가 있는 `get` 을 사용해야 하는데, 아무리 시도해도 400에러가 났다.

찾아보니, get은 request body를 가질 수 없어서,

1. post 방식 +  request body
2. get 방식 + param

위 방식으로 연결해야 했다.

## References

[Axios GET request sends empty req.body to server](https://stackoverflow.com/questions/62811061/axios-get-request-sends-empty-req-body-to-server)

[body data not sent in axios request](https://stackoverflow.com/questions/52561124/body-data-not-sent-in-axios-request)

^ 가장 도움이 많이 됨

[React Async/Await Get data with request body](https://stackoverflow.com/questions/71688980/react-async-await-get-data-with-request-body)

^ 내 질문
