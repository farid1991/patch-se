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

//----------------------------------------------------------------------------------------------//

void onEnterPressed_Shortcuts(BOOK* book, GUI* gui)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK_MANAGER* data = GetData();
  
  SHORTCUT* Shortcut = (SHORTCUT*)List_Get(data->shortcut_list, ListMenu_GetSelectedItem(data->tab_shortcut));
  if (Shortcut)
  {
    switch(Shortcut->Type)
    {
    case TYPE_SHORTCUT:
      Shortcut_Run(Shortcut->sData);
      break;
    case TYPE_JAVA:
      StartJava_ByName(Shortcut->sData);
      break;
    case TYPE_EVENT:
      ExecuteEvent(Shortcut->sData);
      break;
    case TYPE_ELF:
      runElf(Shortcut->sData,NULL,NULL);
      break;
    case TYPE_FOLDER:
      OpenFolder(Shortcut->sData);
      break;
    }
  }
  FreeBook( ActivityMenu );
}

int onCallback_Shortcut(GUI_MESSAGE* msg)
{
  BOOK_MANAGER* data = GetData();
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    SHORTCUT* Shortcut = (SHORTCUT*) List_Get(data->shortcut_list, index);
    
    GUIonMessage_SetMenuItemText(msg, TextID_Create(Shortcut->Caption,ENC_UCS2,TEXTID_ANY_LEN));
    GUIonMessage_SetMenuItemIcon(msg, 0, Shortcut->Icon);
    break;
  }
  return 1;
}

extern "C"
void CreateShortcutMenu(BOOK* book, int tab)
{
  ActivityMenuBook* ActivityMenu = (ActivityMenuBook*)book;
  BOOK_MANAGER* data = GetData();
  
  FREE_GUI(data->tab_shortcut);
  data->tab_shortcut = CreateListMenu( ActivityMenu, UIDisplay_Main );
  ListMenu_SetCursorToItem( data->tab_shortcut, 1 );
  ListMenu_SetOnMessage( data->tab_shortcut, onCallback_Shortcut );
  ListMenu_SetItemCount( data->tab_shortcut, data->slistcnt );
  ListMenu_SetItemTextScroll( data->tab_shortcut, FALSE);
  ListMenu_SetHotkeyMode( data->tab_shortcut, LKHM_SHORTCUT );
  ListMenu_SetNoItemText( data->tab_shortcut, EMPTY_LIST_TXT);
  
  GUIObject_SetStyle( data->tab_shortcut, UI_OverlayStyle_PopupNoFrame );
  GUIObject_TabTitleRemove( data->tab_shortcut, TRUE );

  GUIObject_SoftKeys_SetAction(data->tab_shortcut, ACTION_BACK, onCloseBook);
  GUIObject_SoftKeys_SetAction(data->tab_shortcut, ACTION_LONG_BACK, onCloseAllBook);
  
  if(data->slistcnt)
  {
    GUIObject_SoftKeys_SetAction(data->tab_shortcut, ACTION_SELECT1, onEnterPressed_Shortcuts);
  }

  TabMenuBar_SetTabGui( ActivityMenu->main_tab, tab, data->tab_shortcut);
  TabMenuBar_SetTabTitle( ActivityMenu->main_tab, tab, MY_SHORTCUT_TXT );
}

//----------------------------------------------------------------------------------------------//
