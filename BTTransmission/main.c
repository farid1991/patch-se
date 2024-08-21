#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\Function.h"

#include "..\\include\book\ObExReceiveBook.h"
#include "..\\include\book\ObExSendBook.h"

#include "dll.h"
#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "ObEx", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "ObEx", 0);
#else
  return memalloc(size, 1, 5, "ObEx", 0);
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(0, mem, "ObEx", 0);
#elif defined(A2)
    memfree(0, mem, "ObEx", 0);
#else
    memfree(mem, "ObEx", 0);
#endif
}

int *GetReceivedBytes()
{
  return (int *)get_envp(NULL, "ObExEnv");
}

int *CreateData()
{
  int *received_bytes = (int *)malloc(sizeof(int));
  memset(received_bytes, NULL, sizeof(int));
  set_envp(NULL, "ObExEnv", (OSADDRESS)received_bytes);
  return received_bytes;
}

void UpdateData(void *data)
{
  OBEX_REFRESH_RECEIVE_PROGRESS_DATA *pRData = (OBEX_REFRESH_RECEIVE_PROGRESS_DATA *)data;
  int *received_bytes = GetReceivedBytes();
  if (!received_bytes)
    received_bytes = CreateData();
  *received_bytes = pRData->received_bytes;
}

void RefreshStatusRow()
{
  DISP_OBJ **StatusRowP = StatusRow_p;
  DispObject_InvalidateRect(*StatusRowP, NULL);
}

extern "C" int New_ObEx_ReceiveFile(void *data, BOOK *book)
{
  pg_ObEx_ReceiveFile(data, book);
  UpdateData(data);
  RefreshStatusRow();
  return 1;
}

extern "C" int New_ObEx_SendFile(void *data, BOOK *book)
{
  pg_ObEx_SendFile(data, book);
  RefreshStatusRow();
  return 1;
}

extern "C" int New_ObEx_SendMultipleFiles(void *data, BOOK *book)
{
  pg_ObEx_SendMultipleFiles(data, book);
  RefreshStatusRow();
  return 1;
}

extern "C" int New_ObEx_FileSent(void *data, BOOK *book)
{
  pg_ObEx_FileSent(data, book);
  RefreshStatusRow();
  return 1;
}

int cmp_proc(BOOK *book, int *bookname)
{
  return strcmp(book->xbook->name, (char *)bookname) == NULL;
}

extern "C" void New_StatusRow_OnRedraw(DISP_OBJ *disp_obj, int r1, RECT *rect, int r3)
{
  ObExSendBook *ObexSBook = (ObExSendBook *)FindBookEx(cmp_proc, (int *)OBEXSENDBOOK);
  if (ObexSBook && (Display_GetTopBook(UIDisplay_Main) != ObexSBook))
  {
    wchar_t buff[32];
    snwprintf(buff,
              MAXELEMS(buff),
              L"%d/%d KB",
              ObexSBook->file_sent >> 10,
              ObexSBook->file_size >> 10);
    TEXTID text_id = TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(FONT_E_16R, text_id, AlignCenter, 0, 0, DISP_WIDTH, STATUS_HEIGHT, clWhite);
#else
    SetFont(FONT_E_14R);
    DrawString(text_id, AlignCenter, 0, 0, DISP_WIDTH, STATUS_HEIGHT, 20, 5, clWhite, clEmpty);
#endif
    TextID_Destroy(text_id);
  }

  ObExReceiveBook *ObexRBook = (ObExReceiveBook *)FindBookEx(cmp_proc, (int *)OBEXRECEIVEBOOK);
  if (ObexRBook && (Display_GetTopBook(UIDisplay_Main) != ObexRBook))
  {
    int *received_bytes = GetReceivedBytes();

    wchar_t buff[32];
    snwprintf(buff,
              MAXELEMS(buff),
              L"%d/%d KB",
              *received_bytes >> 10,
              ObexRBook->file_size >> 10);
    TEXTID text_id = TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(FONT_E_16R, text_id, AlignCenter, 0, 0, DISP_WIDTH, STATUS_HEIGHT, clWhite);
#else
    SetFont(FONT_E_14R);
    DrawString(text_id, AlignCenter, 0, 0, DISP_WIDTH, STATUS_HEIGHT, 20, 5, clWhite, clEmpty);
#endif
    TextID_Destroy(text_id);
  }

  StatusRow_OnRedraw(disp_obj, r1, rect, r3);
}
