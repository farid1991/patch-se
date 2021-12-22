#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\DataDownloadBook.h"

#include "Lib.h"
#include "main.h"

/*
;Add the question of replacing the file after taking over Bluetooth
;(c) E1kolyan
*/

FILE_DATA *GetData()
{
  FILE_DATA *fd = (FILE_DATA *)get_envp(NULL, EMP_NAME);
  if (!fd)
  {
    fd = (FILE_DATA *)memalloc(0xFFFFFFFF, sizeof(FILE_DATA), 1, 5, VALUE_NAME, 0);
    memset(fd, NULL, sizeof(FILE_DATA));
    set_envp(NULL, EMP_NAME, (OSADDRESS)fd);
  }
  return fd;
}

void DeleteData()
{
  FILE_DATA *fd = (FILE_DATA *)get_envp(NULL, EMP_NAME);
  if (fd)
  {
    fd->mode = NULL;
    memfree(0, fd, VALUE_NAME, 0);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void Question_OnYes(BOOK *book, GUI *gui)
{
  FILE_DATA *fd = GetData();
  fd->mode = true;

  DataDownloadBook *pDDBook = (DataDownloadBook *)book;
  FREE_GUI(pDDBook->gui);
  BookObj_GotoPage(pDDBook, DataDownload_Main_Page);
}

void Question_OnNo(BOOK *book, GUI *gui)
{
  DataDownloadBook *pDDBook = (DataDownloadBook *)book;
  BookObj_GotoPage(pDDBook, DataDownload_Main_Page);
  FREE_GUI(pDDBook->gui);
}

int Question_Enter(void *data, BOOK *book)
{
  DataDownloadBook *pDDBook = (DataDownloadBook *)book;
  FREE_GUI(pDDBook->gui);

  if (pDDBook->gui = CreateYesNoQuestion(book, UIDisplay_Main))
  {
    YesNoQuestion_SetDescriptionText(pDDBook->gui, DescriptionText);
    YesNoQuestion_SetQuestionText(pDDBook->gui, QuestionText);
    GUIObject_SoftKeys_SetAction(pDDBook->gui, ACTION_YES, Question_OnYes);
    GUIObject_SoftKeys_SetAction(pDDBook->gui, ACTION_NO, Question_OnNo);
    GUIObject_Show(pDDBook->gui);
  }
  return 1;
}

int Question_Exit(void *data, BOOK *book)
{
  DataDownloadBook *pDDBook = (DataDownloadBook *)book;
  FREE_GUI(pDDBook->gui);
  return 1;
}

const PAGE_MSG evtlst_DataDownload_ReplaceFile[] =
    {
        PAGE_ENTER_EVENT, Question_Enter,
        PAGE_EXIT_EVENT, Question_Exit,
        NIL_EVENT, NULL};

const PAGE_DESC DataDownload_ReplaceFile_Page = {"DataDownload_ReplaceFile_Page", NULL, evtlst_DataDownload_ReplaceFile};

extern "C" void Question(BOOK *book)
{
  DataDownloadBook *pDDBook = (DataDownloadBook *)book;

  bool file_exist = FSX_IsFileExists(FILEITEM_GetPath(pDDBook->fi), FILEITEM_GetFname(pDDBook->fi));

  if (file_exist)
    BookObj_GotoPage(pDDBook, &DataDownload_ReplaceFile_Page);
  else
    BookObj_GotoPage(pDDBook, DataDownload_Main_Page);
}

extern "C" void File(FILEITEM *fi)
{
  FILE_DATA *fd = GetData();

  if (fd->mode)
    FileDelete(FILEITEM_GetPath(fi), FILEITEM_GetFname(fi), NULL);
  else
    DataBrowser_ItemDesc_CheckFileToCopyMove(fi);
}

extern "C" void Close(BOOK *book)
{
  DeleteData();

  DataDownloadBook *pDDBook = (DataDownloadBook *)book;
  DataDownloadBook_onClose(pDDBook);
}
