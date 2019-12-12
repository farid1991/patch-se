/*
;Improved Activity Menu
;1st tab corrected for the title "New Events: %d"
;2nd tab displays running books GUI + header "Heap: %dKB"
;3rd tab displays running elf + in the title count of the elves in the memory
;4th tab add shortcut menu (add, edit, and delete shortcut)
;Support for custom names of the books, on file bookman.ini (/usb/other/ini/bookman.ini)
;Hotkeys:
;* - close all the books and goto Standby
;# - Minimize all the books and goto Standby
;C - Kill the book / Elf
;(c) E1kolyan
;(r) IronMaster, den_po
;(e) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\ActivityMenuBook.h"

#include "main.h"
#include "string.h"
#include "utils.h"

//===========================================================

__thumb void * malloc (int size)
{
#if defined(DB2020) || defined(PNX5230)  
  return(memalloc(0,size,1,5,"bm",0));
#elif defined(A2)
  return(memalloc(0xFFFFFFFF,size,1,5,"bm",0));
#else
  return(memalloc(size,1,5,"bm",0));
#endif
}

__thumb void mfree (void * mem)
{
#if defined(DB2020) || defined(PNX5230)  
  if (mem) memfree(0, mem,"bm",0);
#elif defined(A2)
  if (mem) memfree(0, mem,"bm",0);
#else
  memfree(mem,"bm",0);
#endif
}

//===========================================================

BOOK_MANAGER* CreateData()
{
  BOOK_MANAGER* data = (BOOK_MANAGER*)malloc(sizeof(BOOK_MANAGER));
  memset(data, NULL, sizeof(BOOK_MANAGER));
  set_envp(NULL, EMP_NAME, (OSADDRESS)data);
  return data;
}

BOOK_MANAGER* GetData() 
{
  BOOK_MANAGER* data = (BOOK_MANAGER*)get_envp(NULL, EMP_NAME);
  if (data) return data;
  return CreateData();
}

void DeleteData()
{
  BOOK_MANAGER* data = (BOOK_MANAGER*)get_envp(NULL, EMP_NAME);
  if (data)
  {
    mfree(data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

int GetActiveTab(BOOK* book)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  return TabMenuBar_GetFocusedTab(ActivityMenu->main_tab);
}

void onDelete_BookAndElfs(BOOK* book, GUI* gui)
{
  BOOK_MANAGER* data = GetData();
  
  if (GetActiveTab(book) == BOOKLIST)
  {
    BOOK_LIST_ITEM* elem = GetBookListItem(BOOKLIST);
    if (elem)
    {
      BOOK* SelectedBook = elem->book;
      if (SelectedBook != Find_StandbyBook())
      {
        if (elem->isJava) UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(SelectedBook));
        else
        {
          if (CheckEv(SelectedBook, TERMINATE_SESSION_EVENT))
            UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID((BOOK*)List_Get(SelectedBook->xbook->app_session->listbook, List_GetCount(SelectedBook->xbook->app_session->listbook)-1)));
          else if (CheckEv(SelectedBook, RETURN_TO_STANDBY_EVENT))
            UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID((BOOK*)List_Get(SelectedBook->xbook->app_session->listbook, List_GetCount(SelectedBook->xbook->app_session->listbook)-1)));
        }
        UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
      }  
    }
  }
  else
  {
    if (data->elistcnt)
    {
      BOOK* elf_book = GetBook(book, ELFLIST);
      if (elf_book)
      {
        if (CheckEv(elf_book, RETURN_TO_STANDBY_EVENT)) UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID(elf_book));
        else
        {
          if (CheckEv(elf_book, ELF_TERMINATE_EVENT)) UI_Event_toBookID(ELF_TERMINATE_EVENT, BookObj_GetBookID(elf_book));
          else MessageBox_NoImage(EMPTY_TEXTID, STR("TerminateEvent not supported by elf..."), 1, 2000, elf_book);
        }
        UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
        data->elf = TRUE;
      }
    }
  }
}

BOOK_LIST_ITEM* GetBookListItem(int list)
{
  BOOK_MANAGER* data = GetData();
  
  BOOK_LIST_ITEM* elem;
  switch (list)
  {
  case BOOKLIST:
    data->blistpos = ListMenu_GetSelectedItem(data->tab_books);
    elem = (BOOK_LIST_ITEM*) List_Get( data->books_list, data->blistpos );
    break;
  case ELFLIST:
    if (data->elistcnt) elem = (BOOK_LIST_ITEM*) List_Get( data->elfs_list, data->elistpos );
    else return 0;
    break;
  }
  return elem;
}

BOOK* GetBook(BOOK* book, int list)
{
  BOOK_LIST_ITEM* elem = GetBookListItem(list);
  return (elem ? elem->book : 0);
}

int CheckEv(BOOK* book, int event)
{
  if (book->base_page)
  {
    const PAGE_MSG* pm = book->base_page->msg_lst;
    if (pm)
    {
      while (pm->msg && pm->proc)
      {
        if (pm->msg == event) return 1;
        pm++;
      }
    }
  }
  return 0;
}

TEXTID GetBookName(char* section)
{
  BOOK_MANAGER* data = GetData();
  
  wchar_t buffer[50];
  TEXTID text_id = 0;
  
  if (data->buf_ini)
  {
    char* param;
    if (param = manifest_GetParam(data->buf_ini,section,0))
    {
      win12512unicode(buffer,param,49);
      text_id = TextID_Create(buffer, ENC_UCS2, TEXTID_ANY_LEN);
      mfree(param);
    }
  }
  if(!text_id)
  {
    win12512unicode(buffer,section,49);
    text_id = TextID_Create(buffer ,ENC_UCS2, wstrlen(buffer));
  }
  return text_id;
}

IMAGEID GetBookIcon(char* book_name, int default_img)
{
  BOOK_MANAGER* data = GetData();
  
  char* pos;
  char* end_pos;
  wchar_t ws[50];
 
  int image_id = 0;
  int len = strlen(book_name);
  
  if (data->buf_ini)
  {
    char* param;
    pos = strstr( data->buf_ini, book_name );
    end_pos = pos + len + sizeof("\r\n") - sizeof("");
    if ( param = manifest_GetParam( end_pos, "ICON", 0 ) )
    {
      win12512unicode(ws,param,49);
      GetIconByName( ws, image_id );
      mfree(param);
    }
  }
  if(!image_id) image_id = default_img;
  return image_id;
}

//----------------------------------------------------------------------------------------------//

int LIST_ITEM_Filter(void* elem)
{
  return (elem ? 1 : 0);
}

void BOOK_LIST_ITEM_Destroy(void* data)
{
  BOOK_LIST_ITEM* elem = (BOOK_LIST_ITEM*)data;
  if (elem)
  {
    if (elem->book_name) mfree(elem->book_name);
    mfree(elem);
  }
}

void SHORTCUT_LIST_ITEM_Destroy(void* data)
{
  SHORTCUT* Shortcut = (SHORTCUT*)data;
  if(Shortcut)
  {
    mfree(Shortcut->sData);
    mfree(Shortcut->Caption);   
    mfree(Shortcut);
  }
}

void DestroyLists(BOOK_MANAGER* data)
{
  if (data->books_list)
  {
    List_DestroyElements(data->books_list, LIST_ITEM_Filter, BOOK_LIST_ITEM_Destroy);
    List_Destroy(data->books_list);
    data->books_list = NULL;
  }
  if (data->elfs_list)
  {
    List_DestroyElements(data->elfs_list, LIST_ITEM_Filter, BOOK_LIST_ITEM_Destroy);
    List_Destroy(data->elfs_list);
    data->elfs_list = NULL;
  }
  if (data->shortcut_list)
  {
    List_DestroyElements(data->shortcut_list, LIST_ITEM_Filter, SHORTCUT_LIST_ITEM_Destroy);
    List_Destroy(data->shortcut_list);
    data->shortcut_list = NULL;
  }
}

void DestroyConfigBuffers(BOOK_MANAGER* data)
{
  if (data->buf_ini)
  {
    mfree(data->buf_ini);
    data->buf_ini = NULL;
  }
}

int isRSSTickerBook(BOOK* book)
{
  return 0 == strcmp(book->xbook->name, RSSTicker_Book);
}

int GetConfig(char **buf_set)
{
  int file;
  char* buf = NULL;
  int size = 0;
  FSTAT _fstat;
  if (fstat(BOOKMAN_PATH,BOOKMAN_INI,&_fstat)==0)
  {
    if ((file = _fopen(BOOKMAN_PATH,BOOKMAN_INI,FSX_O_RDONLY,FSX_S_IREAD|FSX_S_IWRITE,0)) >= 0)
    {
      buf = StringAlloc(_fstat.fsize);
      fread( file, buf, _fstat.fsize );
      fclose( file );
      size = _fstat.fsize;
    }
  }
  buf_set[0] = buf;
  return size;
}

void Init_ConfigFile(BOOK_MANAGER* data)
{
  char* sp;
  data->buf_size = GetConfig(&sp);
  data->buf_ini = sp;
}

extern "C"
void CreateBookAndElfsLists(BOOK* book)
{
  BOOK_MANAGER* data = GetData();

  DestroyConfigBuffers(data);
  DestroyLists(data);
  
  //=============================Ini inisializaton=============================
  
  Init_ConfigFile(data);

  //===============================Create List=================================
  
  data->books_list = List_Create();
  data->elfs_list = List_Create();
  data->shortcut_list = List_Create();

  //===========================================================================

  int fgui;

  //===========================Start List Counter==============================

  int books_cnt = NULL;
  int elfs_cnt = NULL;
  
  //========================Add item to  Books and Elfs List===================
  
  char buf_name[MAX_BOOK_NAME_LEN + 1];
  
  DB_EXT* _mask = LastExtDB;
  int mask = ((int)_mask)&FLASH_MASK;
  
  int i = root_list_get_session_count();
  
  for (int j = 0; j < i; j++)
  {
    UI_APP_SESSION* session = root_list_get_session(j);
    for (int k = 0; k < List_GetCount(session->listbook); k++)
    {
      BOOK* book = (BOOK*)List_Get(session->listbook, k);
      if((fgui = List_GetCount(book->xguilist->guilist) || (((int)book->onClose)&FLASH_MASK ) != mask))
      {
        if (!IsVolumeControllerBook(book) && !IsRightNowBook(book) && !isRSSTickerBook(book))
        {
          BOOK_LIST_ITEM* elem = (BOOK_LIST_ITEM*)malloc(sizeof(BOOK_LIST_ITEM));
          elem->book = book;
          elem->gui_count = fgui;
          elem->isJava = FALSE;
          
          if (strcmp(book->xbook->name, JAVA_BOOK_NAME))
          {
            char* bookname = StringAlloc(strlen(book->xbook->name));
            strcpy(bookname, book->xbook->name);
            elem->book_name = bookname;
          }
          else
          {
            TextID_GetString(BookObj_GetSession(book)->name, buf_name, MAXELEMS(buf_name));
            char* bookname = StringAlloc(strlen(buf_name));
            strcpy(bookname, buf_name);
            elem->book_name = bookname;
            elem->isJava = TRUE;
          }
          
          if(elem->isJava)
          {
            elem->book_icon = DB_LIST_JAVA_ICN;
            char sp1;
	    void * JavaDesc;
            JavaDialog_Open(0,&sp1,&JavaDesc);
            if (!JavaAppDesc_GetFirstApp(JavaDesc))
            {
              wchar_t* book_name = WStringAlloc(strlen(elem->book_name));
              str2wstr(book_name,elem->book_name);
              bool next = true;
              while (next)
              {
                wchar_t* JavaAppName;
                JavaAppDesc_GetJavaAppInfo(JavaDesc, 0, &JavaAppName);

                if(!wstrncmp(book_name, JavaAppName, 8))
                {
                  wchar_t* JavaAppPath;
                  JavaAppDesc_GetJavaAppInfo(JavaDesc,5,&JavaAppPath);
                  JavaApp_LogoImageID_Get(JavaAppPath,&elem->book_icon);
                  mfree(JavaAppPath);
                  next = false;
                }
                mfree(JavaAppName);

                if (JavaAppDesc_GetNextApp(JavaDesc)) next = false;
              }
              mfree(book_name);
            }
            JavaDialog_Close(sp1);
          }
          
          TEXTID tmp = GetJavaName(book);
          if ( tmp )
          {
            mfree(elem->book_name);
            TextID_GetString( tmp, buf_name, MAXELEMS(buf_name));
            char* java_name = StringAlloc(strlen(buf_name));
            strcpy(java_name,buf_name);
            elem->book_name = java_name;
          }
            
          if ((((int)book->onClose)&FLASH_MASK) == mask)
          {
            List_InsertFirst(data->books_list, elem);
            books_cnt++;
          }
          else
          {
            List_InsertFirst(data->elfs_list, elem);
            elfs_cnt++;
          }
        }
      }
    }
  }
  //========================Add item to shortcut list===========================
  
  data->shortcut_list = LoadShortcut();
  
  //============================ List Counter ==================================
  
  data->blistcnt = books_cnt;
  data->elistcnt = elfs_cnt;
  data->slistcnt = List_GetCount(data->shortcut_list);
}

void DestroyAllGUIs(BOOK_MANAGER* data)
{
  FREE_GUI (data->tab_books);
  data->blistpos = NULL;
  
  FREE_GUI (data->tab_elfs );
  data->elistpos = NULL;
  
  FREE_GUI (data->tab_shortcut);
}

extern "C"
void ActivityBook_onClose(BOOK* book)
{
  BOOK_MANAGER* data = GetData();
  DestroyConfigBuffers(data);
  DestroyAllGUIs(data);
  DestroyLists(data);
}

extern "C"
TEXTID EventsTitleText()
{
  wchar_t buf[32];
  snwprintf(buf, MAXELEMS(buf), L"New events: %d", NewEvent_GetCount());
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C"
int SetFocusTab()
{
  BOOK_MANAGER* data = GetData();
  return (data->elf ? ELFLIST : BOOKLIST);
}
