#include "..\\include\Types.h"

#include "Lib.h"

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
  return (memalloc(size, 1, 5, "RB" 0));
#elif defined(DB2020)
  return (memalloc(0, size, 1, 5, "RB", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "RB", 0));
#endif
}

void mfree(void *mem)
{
#if defined(DB2010)
  memfree(mem, "RB", 0);
#elif defined(DB2020)
  if (mem)
    memfree(0, mem, "RB", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "RB", 0);
#endif
}

wchar_t *GetRecyclerPath()
{
  wchar_t *path = NULL;

  if (GetMemoryStickStatus())
    path = L"/card/other/RECYCLER";
  else
    path = L"/usb/other/RECYCLER";

  return path;
}

void SetEnvp(bool state)
{
  set_envp(get_bid(current_process()), "RB", state);
}

int CheckPassword(void *data, BOOK *book)
{
  CreatePasswordInputWindow(BookObj_GetBookID(book), 0, 2, TEXTID_LOCK);
  return 1;
}

int CreateBrowser(void *data, BOOK *book)
{
  // debug_printf("\n\n\n[BOOKNAME]: %s\n\n\n", book->xbook->name);
  void *desc = DataBrowserDesc_Create();
  const wchar_t *folder_list[2];
  folder_list[0] = GetRecyclerPath();
  folder_list[1] = NULL;
  DataBrowserDesc_SetHeaderText(desc, STR("Recycle Bin"));
  DataBrowserDesc_SetBookID(desc, BookObj_GetBookID(book));
  DataBrowserDesc_SetFolders(desc, folder_list);
  DataBrowserDesc_SetFoldersNumber(desc, 1);
  DataBrowserDesc_Menu_AddFSFunctions(desc, FALSE);
  DataBrowserDesc_Menu_AddMarkFiles(desc, TRUE);
  DataBrowser_Create(desc);
  DataBrowserDesc_Destroy(desc);
  return 1;
}

const PAGE_MSG main_evlist[] =
    {
        PAGE_ENTER_EVENT, CheckPassword,
        ACCEPT_EVENT, CreateBrowser,
        NIL_EVENT, NULL};

const PAGE_DESC DataBrowser_Recycler_Page = {"DataBrowser_Recycler_Page", NULL, main_evlist};

void OpenRecycler(BOOK *book, GUI *gui)
{
  BookObj_GotoPage(book, &DataBrowser_Recycler_Page);
}

void OnDelete(BOOK *book, GUI *gui)
{
  SetEnvp(TRUE);
  //MessageBox_NoImage( EMPTY_TEXTID, TextID_Create(L"File will deleted permanently",ENC_UCS2,0xFF), 0, 0, book );
}

extern "C" void SetKey(GUI *gui, int mode)
{
  if (!mode)
  {
    SetEnvp(FALSE);
    GUIObject_SoftKeys_SetAction(gui, 1, OnDelete);
    GUIObject_SoftKeys_SetItemOnKey(gui, 1, KEY_STAR, KBD_SHORT_PRESS);
  }

  GUIObject_SoftKeys_SetAction(gui, 2, OpenRecycler);
  GUIObject_SoftKeys_SetItemOnKey(gui, 2, KEY_DIEZ, KBD_SHORT_PRESS);
}

extern "C" void SetFileDelete(wchar_t *path, wchar_t *filename, int* error)
{
  if (!get_envp(get_bid(current_process()), "RB"))
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
    FileDelete(path, filename, error);
}

/*extern "C"
void filewrite(wchar_t* path)
{
  MessageBox(EMPTY_TEXTID, TextID_Create(path, ENC_UCS2, TEXTID_ANY_LEN), NOIMAGE, 1, 0, 0);
}*/
