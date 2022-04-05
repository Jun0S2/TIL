### `@keyframes` 사용

어쩐지 백날 천날 이것저것해봐도 안되더니 이미지와 마찬가지로, css도 `const` 로 받아와야하나보다. 그리고, `<>` 태그와  사용한다. ~~어제 이미지 사용할때눈치챘어야하는데...~~
회원가입 완료 페이지 콘페티 효과 포기했었는데 다시 한번 수정해봐야겠다.

```jsx
import { styled } from "@mui/material/styles";

const StyledCard = styled(Card)(() => ({
  "&:hover": {
    animation: "circlemove 1.5s infinite linear",
  },
  "@keyframes circlemove": {
    "0%,100%": { transform: "translate(-1%,-1%)" },
    "50%": {
      transform: "translate(-1%,-2%)",
      boxShadow: "rgba(0, 0, 0, 0.35) 0px 5px 15px",
    },
  },
}));

...
function () => {
			<StyledCard variant="outlined">
						...이미지 등
			</StyledCard>
}
```
