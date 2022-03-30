여러가지 해봤지만 다 안됐다.

아래로 해결했다.

```jsx
import { RootStateOrAny, useSelector } from "react-redux";
const auth = useSelector((state: RootStateOrAny) => state.isLogin);
```

[TS2339: Property 'tsReducer' does not exist on type 'DefaultRootState'](https://stackoverflow.com/questions/60777859/ts2339-property-tsreducer-does-not-exist-on-type-defaultrootstate)
