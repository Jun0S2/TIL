<aside>

  ๐ฅ๏ธ Dialog ๋ง๋ค๊ธฐ

</aside>

MUI ๋ฌธ์์๋ ๋ฐ๋ก ์ปดํฌ๋ํธ๋ก ๋น ์ ธ์์ง ์์์ ๋ชจ๋๋ก ๋บ๋ค.

## Parent.tsx

```jsx
import DialogComponent from "./component/DialogComponent";//Modal ์ปดํฌ๋ํธ

export default function Parent(){
/* Modal์ ์ํ ๊ด๋ฆฌ*/
const [open, setOpen] = useState(false);
/* Modal OPEN */
const handleOpen = () => {
    setOpen(true);
 };
/* Modal CLOSE*/
const handleClose = () => {
    setOpen(false);
};

/* ํ๋ฉด ๊ตฌ์ฑ */
return(
	<>
				<Button onClick={handleOpen} >๋ชจ๋ฌ์ด๊ธฐ</Button>
				<DialogComponent open={open} handleClose={handleClose} />
	</>
);
}
```

## Child.tsx(Dialog ์ปดํฌ๋ํธ)

```jsx
import React from "react";
import DialogTitle from "@mui/material/DialogTitle";
import DialogContent from "@mui/material/DialogContent";
import DialogActions from "@mui/material/DialogActions";
import Dialog from "@mui/material/Dialog";
import { Button, Grid } from "@mui/material";
/* ๋ชจ๋ฌ ์ธํฐํ์ด์ค */
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
      <DialogContent >์์</DialogContent>

      <DialogActions>
        <Button variant="contained" onClick={handleClose}>
          ๋ซ๊ธฐ
        </Button>
        <Button type="submit" variant="contained" color="primary">
          ์ค์ผ
        </Button>
      </DialogActions>
    </Dialog>
  );
};

export default ConfirmDialog;
```
