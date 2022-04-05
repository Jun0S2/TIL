<aside>

  🖥️ Dialog 만들기

</aside>

MUI 문서에는 따로 컴포넌트로 빠져있지 않아서 모듈로 뺐다.

## Parent.tsx

```jsx
import DialogComponent from "./component/DialogComponent";//Modal 컴포넌트

export default function Parent(){
/* Modal의 상태 관리*/
const [open, setOpen] = useState(false);
/* Modal OPEN */
const handleOpen = () => {
    setOpen(true);
 };
/* Modal CLOSE*/
const handleClose = () => {
    setOpen(false);
};

/* 화면 구성 */
return(
	<>
				<Button onClick={handleOpen} >모달열기</Button>
				<DialogComponent open={open} handleClose={handleClose} />
	</>
);
}
```

## Child.tsx(Dialog 컴포넌트)

```jsx
import React from "react";
import DialogTitle from "@mui/material/DialogTitle";
import DialogContent from "@mui/material/DialogContent";
import DialogActions from "@mui/material/DialogActions";
import Dialog from "@mui/material/Dialog";
import { Button, Grid } from "@mui/material";
/* 모달 인터페이스 */
interface IProps {
  open: boolean;
  handleClose: () => void;
}

const ConfirmDialog = ({ open, handleClose }: IProps) => {
  return 
    <Dialog
      open={open}
      onClose={handleClose}
      sx={{ "& .MuiDialog-paper": { width: "80%", maxHeight: 435 } }}
      maxWidth="xs"
    >
      <DialogTitle>RBRB</DialogTitle>
      <DialogContent >얍얍</DialogContent>

      <DialogActions>
        <Button variant="contained" onClick={handleClose}>
          닫기
        </Button>
        <Button type="submit" variant="contained" color="primary">
          오케
        </Button>
      </DialogActions>
    </Dialog>
  );
};

export default ConfirmDialog;
```
