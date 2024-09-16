#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\DataDownloadBook.h"

#include "main.h"

FILE_DATA *get_env_data()
{
  FILE_DATA *fdata = (FILE_DATA *)get_envp(NULL, EMP_NAME);
  if (!fdata)
  {
    fdata = (FILE_DATA *)memalloc(-1, sizeof(FILE_DATA), 1, 5, MEM_NAME, NULL);
    memset(fdata, NULL, sizeof(FILE_DATA));
    set_envp(NULL, EMP_NAME, (OSADDRESS)fdata);
  }
  return fdata;
}

void destroy_env_data()
{
  FILE_DATA *fdata = (FILE_DATA *)get_envp(NULL, EMP_NAME);
  if (fdata)
  {
    memfree(NULL, fdata, MEM_NAME, NULL);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void pg_ReplaceFile_onYes(BOOK *book, GUI *gui)
{
  FILE_DATA *fdata = get_env_data();
  fdata->state = true;

  DataDownloadBook *dl_book = (DataDownloadBook *)book;
  GUIObject_Destroy(dl_book->gui);
  BookObj_GotoPage(dl_book, DataDownload_Main_Page);
}

void pg_ReplaceFile_onNo(BOOK *book, GUI *gui)
{
  DataDownloadBook *dl_book = (DataDownloadBook *)book;
  BookObj_GotoPage(dl_book, DataDownload_Main_Page);
  GUIObject_Destroy(dl_book->gui);
}

int pg_ReplaceFile_EnterEvent(void *data, BOOK *book)
{
  DataDownloadBook *dl_book = (DataDownloadBook *)book;
  if (dl_book->gui = CreateYesNoQuestion(dl_book, UIDisplay_Main))
  {
    YesNoQuestion_SetDescriptionText(dl_book->gui, DescriptionText);
    YesNoQuestion_SetQuestionText(dl_book->gui, QuestionText);
    GUIObject_SoftKeys_SetAction(dl_book->gui, ACTION_YES, pg_ReplaceFile_onYes);
    GUIObject_SoftKeys_SetAction(dl_book->gui, ACTION_NO, pg_ReplaceFile_onNo);
    GUIObject_Show(dl_book->gui);
  }
  return 1;
}

int pg_ReplaceFile_ExitEvent(void *data, BOOK *book)
{
  DataDownloadBook *dl_book = (DataDownloadBook *)book;
  GUIObject_Destroy(dl_book->gui);
  return 1;
}

extern "C" void Patch_ReplaceFile_Page(BOOK *book)
{
  DataDownloadBook *dl_book = (DataDownloadBook *)book;

  if (FSX_IsFileExists(FILEITEM_GetPath(dl_book->fi), FILEITEM_GetFname(dl_book->fi)))
  {
    BookObj_GotoPage(dl_book, &DataDownload_ReplaceFile_Page);
  }
  else
  {
    BookObj_GotoPage(dl_book, DataDownload_Main_Page);
  }
}

extern "C" void New_ReplaceFile(FILEITEM *fileitem)
{
  FILE_DATA *fd = get_env_data();

  if (fd->state)
  {
    FileDelete(FILEITEM_GetPath(fileitem), FILEITEM_GetFname(fileitem), NULL);
  }
  else
  {
    DataBrowser_ItemDesc_CheckFileToCopyMove(fileitem);
  }
}

extern "C" void Close_DataDownloadBook(BOOK *book)
{
  destroy_env_data();

  DataDownloadBook *dl_book = (DataDownloadBook *)book;
  DataDownloadBook_onClose(dl_book);
}
