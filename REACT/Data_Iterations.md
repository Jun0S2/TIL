### Data iterations

- 참고한 사이트
- 그러니까 `v-for` 같은애고, 뷰티파이 v-data-iterator 처럼 쓰면 될것같다.

[Lists and Keys - React](https://reactjs.org/docs/lists-and-keys.html)

```jsx
import { Container, Grid } from "@mui/material";
import { useState } from "react";
import 카드컴포넌트 from "./component/카드컴포넌트";

export default function Main() {
  const [dataList, setDataList] = useState(tempData.dataList);
  //데이터를 카드에 보내준다
  return (
    <Container>
      <Grid>
        {dataList.map((데이터) => (
          <카드컴포넌트 key={데이터.dataNo} 데이터={데이터}></BoardCard>
        ))}
      </Grid>
    </Container>
  );
}

// 임시 데이터
const tempData = {
  dataList: [
    {
      dataNo: 1,
      dataName: "데이터1",
      dataYear: "2022-03-25",
      dataStatus: true,
    }
  ],
};
```
