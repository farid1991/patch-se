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
#include "utils.h"

//===========================================================

void onEnterPressed_Elfs(BOOK* book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK* elf_book = GetBook(ActivityMenu, ELFLIST);
  if (elf_book)
  {
    BookObj_SetFocus(elf_book, 0);
    FreeBook(ActivityMenu);
  }
}

void onAuthor(BOOK* book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK* elf_book = GetBook(ActivityMenu, ELFLIST);
  if (elf_book)
  {
    if (CheckEv(elf_book, ELF_SHOW_INFO_EVENT))
    {
      MSG* msg = (MSG*)malloc(sizeof(MSG));
      msg->book = book;
      UI_Event_toBookIDwData(ELF_SHOW_INFO_EVENT, BookObj_GetBookID(elf_book), msg, (void(*)(void*))mfree_adr());
    }
    else MessageBox_NoImage(EMPTY_TEXTID, STR("Author [unknown]"), 1, 2000, elf_book);
  }
}

void RefreshElfSoftkeys(BOOK* book)
{
  BOOK_MANAGER* data = GetData();
  if (data->elistcnt)
  {
    BOOK_LIST_ITEM* elem = (BOOK_LIST_ITEM*)List_Get(data->elfs_list, data->elistpos);
    if (!elem->gui_count) GUIObject_SoftKeys_SetVisible(data->tab_elfs, ACTION_SELECT1, FALSE);
    else GUIObject_SoftKeys_SetVisible(data->tab_elfs, ACTION_SELECT1, TRUE);
    GUIObject_SoftKeys_SetVisible(data->tab_elfs, 0, TRUE);
  }
  else
  {
    ListMenu_SetNoItemText(data->tab_elfs, STR("No elfs in memory"));
    GUIObject_SoftKeys_SetVisible(data->tab_elfs, ACTION_SELECT1, FALSE);
    GUIObject_SoftKeys_SetVisible(data->tab_elfs, 0, FALSE);
    data->elistpos = NULL;
  }
}

int Elf_OpenFile(const wchar_t* filepath, const wchar_t* filename)
{
  FSTAT _fstat;
  
  if(!fstat(L"/usb/other/ZBin", L"BcfgEdit.elf", &_fstat))
  {}
  else
  {
    return 1; // BcfgEdit not found
  }
  if(!filepath || !filename) return 2; // success
  
  LoadBcfgedit(filepath,filename);
  return 0;
}

void onBcfgConfig(BOOK * book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK * elf_book = GetBook(ActivityMenu, ELFLIST);
  
  if (elf_book)
  {
    if (CheckEv(elf_book,ELF_BCFG_CONFIG_EVENT))
    {
      int err = Elf_OpenFile(0,0);
      if(err==2)
      {
        wchar_t bcfg_path[256];
        wchar_t bcfg_name[256];
  
        MSG_BCFG * msg = (MSG_BCFG*)malloc(sizeof(MSG_BCFG));
        msg->book = book;
        msg->bcfg_p = bcfg_path;
        msg->bcfg_n = bcfg_name;
        UI_Event_toBookIDwData(ELF_BCFG_CONFIG_EVENT,BookObj_GetBookID(elf_book),msg,(void(*)(void*))mfree_adr());
      }
      else if(err==1) 
      {
        MessageBox_NoImage(EMPTY_TEXTID, STR("BcfgEdit.elf not found!"), 1, 2000, ActivityMenu);
      }
    }
    else 
    {
      MessageBox_NoImage(EMPTY_TEXTID, STR("Elf doesn't support BcfgConfigEvent"), 1, 2000, ActivityMenu);
    }
  }
}

int onCallback_Elfs(GUI_MESSAGE* msg)
{
  BOOK_MANAGER* data = GetData();
  
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    if (data->elistcnt)
    {
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      BOOK_LIST_ITEM* elem = (BOOK_LIST_ITEM*)List_Get(data->elfs_list, item);
      
      GUIonMessage_SetMenuItemText(msg, GetBookName(elem->book_name));
      GUIonMessage_SetMenuItemIcon(msg, 0, GetBookIcon(elem->book_name,ELFS_ITEM_ICON));
      if (!elem->gui_count)
      {
        GUIonMessage_SetItemDisabled(msg, TRUE);
        GUIonMessage_SetMenuItemUnavailableText(msg, STR("Can't set focus to elf without GUI..."));
      }
    }
    break;
  case LISTMSG_HighlightChanged:
    data->elistpos = GUIonMessage_GetSelectedItem(msg);
    BOOK* book = GUIonMessage_GetBook(msg);
    RefreshElfSoftkeys(book);
    break;
  }
  return 1;
}

extern "C"
void CreateElfMenu(BOOK* book, int tab)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK_MANAGER* data = GetData();
  
  data->elf = FALSE;
  if (data->elistpos > data->elistcnt - 1) data->elistpos = data->elistcnt - 1;
  
  FREE_GUI(data->tab_elfs);
  data->tab_elfs = CreateListMenu( ActivityMenu, UIDisplay_Main );
  ListMenu_SetOnMessage( data->tab_elfs, onCallback_Elfs );
  ListMenu_SetCursorToItem( data->tab_elfs, data->elistpos );
  ListMenu_SetItemCount( data->tab_elfs, data->elistcnt );
  GUIObject_SetStyle( data->tab_elfs, UI_OverlayStyle_PopupNoFrame );
  GUIObject_TabTitleRemove( data->tab_elfs, TRUE);
  GUIObject_SoftKeys_SetAction( data->tab_elfs, ACTION_BACK, onCloseBook );
  GUIObject_SoftKeys_SetAction( data->tab_elfs, ACTION_LONG_BACK, onCloseAllBook );
  GUIObject_SoftKeys_SetAction( data->tab_elfs, ACTION_SELECT1, onEnterPressed_Elfs );
  
  //GUIObject_SoftKeys_SetAction(data->elist, 0, onSettings);
  //GUIObject_SoftKeys_SetText(data->elist, 0, STR("Settings"));
  
  if (data->elistcnt)
  {
    GUIObject_SoftKeys_SetAction( data->tab_elfs, ACTION_DELETE, onDelete_BookAndElfs );
    GUIObject_SoftKeys_SetVisible( data->tab_elfs, ACTION_DELETE, FALSE );
    GUIObject_SoftKeys_SetAction( data->tab_elfs, 0, onBcfgConfig );
    GUIObject_SoftKeys_SetText( data->tab_elfs, 0, STR("Config") );
    GUIObject_SoftKeys_SetAction( data->tab_elfs, 1, onAuthor );
    GUIObject_SoftKeys_SetText( data->tab_elfs, 1, STR("Author") );
  }
  RefreshElfSoftkeys(ActivityMenu);
  
  wchar_t buf[32];
  if(data->elistcnt > 1)
  {
    snwprintf(buf, MAXELEMS(buf), L"Elfs: %d", data->elistcnt);
  }
  else
  {
    snwprintf(buf, MAXELEMS(buf), L"Elf: %d", data->elistcnt);
  }
  TabMenuBar_SetTabGui(ActivityMenu->main_tab, tab, data->tab_elfs);
  TabMenuBar_SetTabTitle(ActivityMenu->main_tab, tab, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}
