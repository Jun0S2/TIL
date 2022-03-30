submit 시 prevent default event의 타입스크립트 타입을 몰라서 한참 해맸는데, changeEventHandler가 아닌 `FormEvent<HTMLFormElement>` 를 사용해야한느거였다

### 버튼

버튼에서 onSubmit 을 바로 부르지 않고 form에서 부름

```jsx
<Button
  type="submit"
  fullWidth
  variant="contained"
  color="primary"
  size="large"
  sx={{ my: 2 }}
>
  로그인
</Button>
```

### Form

sendData의 event는 `FormEvent<HTMLFormElement>` 타입을 가졌지만, form 에서 부를 때에는 따로 인자를 안넣어주어도 된다!

```jsx
<form onSubmit={sendData}></form>
```

### Method

`FormEvent<HTMLFormElement>` 를 타입으로 로 주면, `preventDefault` 를 사용할 수 있다!!!

```jsx
const sendData = (e: React.FormEvent<HTMLFormElement>) => {
  e.preventDefault();
  if (password.length !== 0 && email.length !== 0) {
    //원래 저장된 이메일과 다른 email을 저장하는 경우 */
    if (isRemember && prevSave !== email) {
      removeCookie("rememberEmail");
      setCookie("rememberEmail", email, { maxAge: 2000 });
    }
    sendDataToParent(email, password); //전달
  }
};
```

## References

[Can't assign submit event type](https://stackoverflow.com/questions/68326000/cant-assign-submit-event-type)

type을 버튼으로도 줄 수 있지만, 나는 submit 타입이 필요했다(validation 때문에\_

[prevent refresh of page when button inside form clicked](https://stackoverflow.com/questions/7803814/prevent-refresh-of-page-when-button-inside-form-clicked)
