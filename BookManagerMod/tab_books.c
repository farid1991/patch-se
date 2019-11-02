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

//===========================================================

void onCloseBook(BOOK* book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  FreeBook(ActivityMenu);
}

void onEnterPressed_Books(BOOK* book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BookObj_SetFocus(GetBook(ActivityMenu, BOOKLIST), UIDisplay_Main);
  
  FreeBook(ActivityMenu);
}

void onTurnAllBook(BOOK* book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  
  BOOK* StandbyBook = Find_StandbyBook();
  if (StandbyBook) BookObj_SetFocus(StandbyBook, UIDisplay_Main);
  
  FreeBook(ActivityMenu);
}

void onCloseAllBook(BOOK* book, GUI* gui)
{
  UI_Event(RETURN_TO_STANDBY_EVENT);
  FreeBook(book);
}

int onCallback_Books(GUI_MESSAGE* msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      BOOK_MANAGER* data = GetData();

      int item = GUIonMessage_GetCreatedItemIndex(msg);
      BOOK_LIST_ITEM* elem = (BOOK_LIST_ITEM*)List_Get(data->books_list, item);
      GUIonMessage_SetMenuItemText(msg, GetBookName(elem->book_name));
      
      if(elem->isJava) GUIonMessage_SetMenuItemIcon( msg, 0, elem->book_icon);
      else GUIonMessage_SetMenuItemIcon( msg, 0, GetBookIcon(elem->book_name,BOOK_ITEM_ICON));
      
      break;
  }
  return 1;
}

extern "C"
void CreateBookMenu(BOOK* book, int tab)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK_MANAGER* data = GetData();
  
  if (data->blistpos > data->blistcnt - 1) data->blistpos = data->blistcnt - 1;
  
  FREE_GUI(data->tab_books);
  data->tab_books = CreateListMenu(ActivityMenu, UIDisplay_Main);
  ListMenu_SetOnMessage(data->tab_books, onCallback_Books);
  ListMenu_SetItemCount(data->tab_books, data->blistcnt);
  ListMenu_SetCursorToItem(data->tab_books, data->blistpos);
  GUIObject_SetStyle(data->tab_books, UI_OverlayStyle_PopupNoFrame);
  GUIObject_TabTitleRemove(data->tab_books, TRUE);
  GUIObject_SoftKeys_SetAction(data->tab_books, ACTION_BACK, onCloseBook);
  GUIObject_SoftKeys_SetAction(data->tab_books, ACTION_LONG_BACK, onCloseAllBook);
  GUIObject_SoftKeys_SetAction(data->tab_books, ACTION_SELECT1, onEnterPressed_Books);
  
  GUIObject_SoftKeys_SetAction(data->tab_books, ACTION_DELETE, onDelete_BookAndElfs);
  GUIObject_SoftKeys_SetVisible(data->tab_books, ACTION_DELETE, FALSE);
  GUIObject_SoftKeys_SetAction(data->tab_books, 0, onTurnAllBook);
  GUIObject_SoftKeys_SetItemOnKey(data->tab_books, 0, KEY_DIEZ, KBD_SHORT_PRESS);
  GUIObject_SoftKeys_SetAction(data->tab_books, 1, onCloseAllBook);
  GUIObject_SoftKeys_SetItemOnKey(data->tab_books, 1, KEY_STAR, KBD_SHORT_PRESS);
  
  //GUIObject_SoftKeys_SetAction(data->elist, 0, onSettings);
  //GUIObject_SoftKeys_SetText(data->elist, 0, STR("Settings"));
  
  //data->oldOnKey = DispObject_GetOnKey( GUIObject_GetDispObject( data->blist ) );
  //DISP_DESC_SetOnKey( DispObject_GetDESC ( GUIObject_GetDispObject( data->blist ) ), myOnKey );

  wchar_t buf[64];
  snwprintf(buf, MAXELEMS(buf), L"Heap: %dKB", GetFreeBytesOnHeap()/1024);
  TabMenuBar_SetTabGui(ActivityMenu->main_tab, tab, data->tab_books);
  TabMenuBar_SetTabTitle(ActivityMenu->main_tab, tab, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}
