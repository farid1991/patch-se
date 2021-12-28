#include "..\\include\Types.h"
#include "..\\include\book\BrowserItemBook.h"

#include "Lib.h"
#include "main.h"

/*
;Корзина
;При удалении файла(-ов) в диалог удаления добавлена возможность переместить файл в "Корзину"
;При подтверждении - файл отправляется в "Корзину"
;Нажатие "Клавиши *" перед подтверждением - при подтверждении файл удалится, минуя "Корзину"
;Нажатие "Клавиши #" в диалоге удаления - вход в "Корзину"
;Для входа в "Корзину" надо ввести код телефона
;Стандартно "0000", см. Параметры -> Защита -> Блокировки -> Защита телефона
;v. 2.5
;Добавлена возможость отметить файлы в корзине
;Добавлен вход в корзину из окна удаления папки
;v. 3
;Добавлена проверка на отсутствие карты памяти
;Исправлено удаление файлов в корзину
;(c) KrasH
*/

//mkdir - делаю папку

void *malloc(int size)
{
#if defined(DB2010)
  return (memalloc(size, 1, 5, "rb" 0));
#elif defined(DB2020)
  return (memalloc(0, size, 1, 5, "rb", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "rb", 0));
#endif
}

void mfree(void *mem)
{
#if defined(DB2010)
  memfree(mem, "RB", 0);
#elif defined(DB2020)
  if (mem)
    memfree(0, mem, "rb", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "rb", 0);
#endif
}

RECYCLER *CreateData()
{
  RECYCLER *data = (RECYCLER *)malloc(sizeof(RECYCLER));
  memset(data, NULL, sizeof(RECYCLER));
  set_envp(get_bid(current_process()), EMP_NAME, (OSADDRESS)data);
  return data;
}

RECYCLER *GetData()
{
  RECYCLER *data = (RECYCLER *)get_envp(get_bid(current_process()), EMP_NAME);
  if (data)
    return data;
  return CreateData();
}

wchar_t *GetRecyclerPath()
{
  wchar_t *path = NULL;

  if (GetMemoryStickStatus())
    path = L"/card/RECYCLER";
  else
    path = L"/usb/RECYCLER";

  return path;
}

void SetState(bool state)
{
  RECYCLER *Data = GetData();
  Data->state = state;
}

int pg_DataBrowser_Recycler_EnterEvent(void *data, BOOK *book)
{
  CreatePasswordInputWindow(BookObj_GetBookID(book), 0, 2, TEXTID_LOCK);
  return 1;
}

int pg_DataBrowser_Recycler_AcceptEvent(void *data, BOOK *book)
{
  void *desc;
  int BookID = BookObj_GetBookID(book);
  if (desc = DataBrowserDesc_Create())
  {
    DataBrowserDesc_SetHeaderText(desc, STR("Recycle Bin"));
    DataBrowserDesc_SetBookID(desc, BookID);
    const wchar_t *folder_list[2];
    folder_list[0] = GetRecyclerPath();
    folder_list[1] = NULL;
    DataBrowserDesc_SetFolders(desc, folder_list);
    DataBrowserDesc_SetFoldersNumber(desc, 1);
    DataBrowserDesc_Menu_AddFSFunctions(desc, FALSE);
    DataBrowserDesc_Menu_AddNewFolder(desc, FALSE);
    DataBrowserDesc_Menu_AddMarkFiles(desc, TRUE);
    DataBrowser_Create(desc);
    DataBrowserDesc_Destroy(desc);
  }
  else
  {
    UI_Event_toBookID(PREVIOUS_EVENT, BookID);
  }
  return 1;
}

int pg_DataBrowser_Recycler_PreviousEvent(void *data, BOOK *book)
{
  BookObj_ReturnPage(book, NIL_EVENT);
  return (1);
}

const PAGE_MSG evtlst_DataBrowser_Recycler_Page[] =
    {
        PAGE_ENTER_EVENT, pg_DataBrowser_Recycler_EnterEvent,
        ACCEPT_EVENT, pg_DataBrowser_Recycler_AcceptEvent,
        PREVIOUS_EVENT, pg_DataBrowser_Recycler_PreviousEvent,
        NIL_EVENT, NULL};

const PAGE_DESC DataBrowser_Recycler_Page = {"DataBrowser_Recycler_Page", NULL, evtlst_DataBrowser_Recycler_Page};

void OpenRecycler(BOOK *book, GUI *gui)
{
  BookObj_GotoPage(book, &DataBrowser_Recycler_Page);
}

void Question_OnYes(BOOK *book, GUI *gui)
{
  SetState(true);
  FREE_GUI(gui);
  CreateMessageBox(EMPTY_TEXTID, STR("File(s) will deleted permanently"), 1, 2000, book);
}

void Question_OnNo(BOOK *book, GUI *gui)
{
  SetState(false);
  FREE_GUI(gui);
}

void OnDelete(BOOK *book, GUI *gui)
{
  RECYCLER *Data = GetData();
  BrowserItemBook *itembook = (BrowserItemBook *)book;

  if (gui = CreateYesNoQuestion(itembook, UIDisplay_Main))
  {
    if (!Data->is_marked)
    {
      wchar_t *fname = FILEITEM_GetFname(itembook->sub_exec->file_item);
      YesNoQuestion_SetDescriptionText(gui, TextID_Create(fname, ENC_UCS2, TEXTID_ANY_LEN));
      YesNoQuestion_SetQuestionText(gui, STR("Are you sure want to delete permanently this file?"));
    }
    else
    {
      YesNoQuestion_SetQuestionText(gui, STR("Are you sure want to delete permanently this marked files?"));
    }
    GUIObject_SoftKeys_SetAction(gui, ACTION_YES, Question_OnYes);
    GUIObject_SoftKeys_SetAction(gui, ACTION_NO, Question_OnNo);
    GUIObject_Show(gui);
  }
}

extern "C" void SetKey(GUI *gui, int mode, int is_marked)
{
  RECYCLER *Data = GetData();
  Data->is_marked = is_marked;
  if (!mode)
  {
    SetState(FALSE);
    GUIObject_SoftKeys_SetAction(gui, 1, OnDelete);
    GUIObject_SoftKeys_SetItemOnKey(gui, 1, KEY_STAR, KBD_SHORT_PRESS);
  }
  GUIObject_SoftKeys_SetAction(gui, 2, OpenRecycler);
  GUIObject_SoftKeys_SetItemOnKey(gui, 2, KEY_DIEZ, KBD_SHORT_PRESS);
}

extern "C" void SetFileDelete(wchar_t *path, wchar_t *filename)
{
  RECYCLER *Data = GetData();
  if (!Data->state)
  {
    FILEITEM *fi = (FILEITEM *)malloc(sizeof(FILEITEM));
    memset(fi, NULL, sizeof(FILEITEM));

    FILEITEM_SetPath(fi, GetRecyclerPath());
    FILEITEM_SetFnameAndContentType(fi, filename);

    if (DataBrowser_ItemDesc_CheckFileToCopyMove(fi))
    {
      FileMove(path, filename, FILEITEM_GetPath(fi), FILEITEM_GetFname(fi), 0);
      UI_Event_toBookID(DB_UPDATE_EVENT, BookObj_GetBookID(MainDisplay_GetTopBook()));
    }

    mfree(fi);
  }
  else
    FileDelete(path, filename, NULL);
}
