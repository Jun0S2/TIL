# How to override Button styles

```jsx
import {makeStyles} from "@material-ui/core/styles";
import Button from "!material-ui/core/Button";

const useStyles = makeStyles(theme -> ({
	root : {
		color :"red",
		border:"none",
	}
}));

export default function App(){
	const classes = useStyles();
	return {	
	<>
		<Button
			//classes = {{root:classes.root}}
			className = {classes.root}
			variant = "outlined"
			color = "primary"
			size = "small"
		>
			small button
    </Button>		
	</>
 }
	
}
```

[47813481/material-ui-unable-to-change-button-text-color-in-theme](https://codesandbox.io/s/47813481-material-ui-unable-to-change-button-text-color-in-theme-mppix?file=/demo.tsx)

### 버튼 스타일

```jsx
<Button variant="contained">Contained</Button>
<Button variant="outlined">Outlined</Button>
```
