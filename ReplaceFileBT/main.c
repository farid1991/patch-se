#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "main.h"

/*
;Add the question of replacing the file after taking over Bluetooth
;(c) E1kolyan
*/

FILE_DATA* GetData()
{
  FILE_DATA* fd = (FILE_DATA*)get_envp(NULL, EMP_NAME);
  if (!fd)
  {
    fd = (FILE_DATA*)memalloc(0xFFFFFFFF, sizeof(FILE_DATA), 1, 5, VALUE_NAME, 0);
    memset(fd, NULL, sizeof(FILE_DATA));
    //fd->mode = FALSE;
    //fd->gui = NULL;
    set_envp(NULL, EMP_NAME, (OSADDRESS)fd);
  }
  return fd;
}

void DeleteData()
{
  FILE_DATA* fd = (FILE_DATA*)get_envp(NULL, EMP_NAME);
  if (fd)
  {
    if (fd->gui) fd->gui = GUIObject_Destroy(fd->gui);
    fd->mode = FALSE;
    memfree(0, fd, VALUE_NAME, 0);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void Question_OnYes(BOOK* book, GUI* gui)
{
  FILE_DATA* fd = GetData();
  fd->mode = TRUE;
  BookObj_GotoPage(book, DataDownload_Main_Page);
}

void Question_OnNo(BOOK* book, GUI* gui)
{
  BookObj_GotoPage(book, DataDownload_Main_Page);
}

int Question_Enter(void* data, BOOK* book)
{
  FILE_DATA* fd = GetData();
  if (fd->gui) fd->gui = GUIObject_Destroy(fd->gui);
  
  if (fd->gui = CreateYesNoQuestion(book, 0))
  {
    YesNoQuestion_SetDescriptionText(fd->gui, DescriptionText);
    YesNoQuestion_SetQuestionText(fd->gui, QuestionText);
    GUIObject_SoftKeys_SetAction(fd->gui, ACTION_YES, Question_OnYes);
    GUIObject_SoftKeys_SetAction(fd->gui, ACTION_NO, Question_OnNo);
    GUIObject_Show(fd->gui);
  }
  
  return 1;
}

int Question_Exit(void* data, BOOK* book)
{
  FILE_DATA* fd = GetData();
  if (fd->gui) fd->gui = GUIObject_Destroy(fd->gui);
  return 1;
}

const PAGE_MSG evtlst_DataDownload_ReplaceFile[] =
{
  PAGE_ENTER_EVENT, Question_Enter,
  PAGE_EXIT_EVENT,  Question_Exit,
  NIL_EVENT,        NULL
};

const PAGE_DESC DataDownload_ReplaceFile_Page = {"DataDownload_ReplaceFile_Page", NULL, evtlst_DataDownload_ReplaceFile};

extern "C"
void Question(BOOK* book, FILEITEM* fi)
{
  if (FSX_IsFileExists(FILEITEM_GetPath(fi), FILEITEM_GetFname(fi))) BookObj_GotoPage(book, &DataDownload_ReplaceFile_Page);
  else BookObj_GotoPage(book, DataDownload_Main_Page);
}

extern "C"
void File(FILEITEM* fi)
{
  FILE_DATA* fd = GetData();
  if (fd->mode) FileDelete(FILEITEM_GetPath(fi), FILEITEM_GetFname(fi), 0);
  else DataBrowser_ItemDesc_CheckFileToCopyMove(fi);
}

extern "C"
void Close(BOOK* book)
{
  DeleteData();
  DataDownloadBook_onClose(book);
}
