#ifndef _MAIN_H_
#define _MAIN_H_

extern "C"
{
  void StatusRow_OnRedraw(DISP_OBJ *disp_obj, int r1, RECT *rect, int r3);

  int pg_ObEx_ReceiveFile(void *data, BOOK *book);

  int pg_ObEx_SendFile(void *data, BOOK *book);
  int pg_ObEx_SendMultipleFiles(void *data, BOOK *book);
  int pg_ObEx_FileSent(void *data, BOOK *book);
}

#endif
