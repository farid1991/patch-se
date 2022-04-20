#include "temp\target.h"

#include "..\\include\Types.h"

#include "main.h"
#include "Lib.h"

__thumb void *malloc(int size)
{
  return memalloc(size, 1, 5, BOOKNAME, 0);
}

__thumb void mfree(void *mem)
{
  memfree(mem, BOOKNAME, 0);
}

int IsQuickAccessBook(BOOK *book)
{
  if (strcmp(book->xbook->name, BOOKNAME))
    return FALSE;
  return TRUE;
}

TEXTID GetFreeHeap()
{
  wchar_t buff[64];
  snwprintf(buff, MAXELEMS(buff), L"Heap: %d Kb", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

void Menu_Back(BOOK *book, GUI *gui)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;
  FreeBook(mbk);
}

void Menu_Exit(BOOK *book, GUI *gui)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;
  FreeBook(mbk);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void Menu_Select(BOOK *book, GUI *gui)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;
  int item = ListMenu_GetSelectedItem(mbk->MainMenu);
  FreeBook(mbk);

  if (item == ITEM_RESTART)
  {
    REQUEST_SYSTEM_RESTART();
  }
  else if (item == ITEM_SHUTDOWN)
  {
    REQUEST_SYSTEM_SHUTDOWN();
  }
  else if (item == ITEM_SILENT)
  {
    int num;
    REQUEST_PROFILE_GETACTIVEPROFILE(SYNC, &num);
    if (GetSilent())
    {
      REQUEST_SETTING_SILENCE_SET(SYNC, (u16)num, OFF);
    }
    else
    {
      REQUEST_SETTING_SILENCE_SET(SYNC, (u16)num, ON);
      MessageBox(EMPTY_TEXTID, EMPTY_TEXTID, POPUP_SILENT_ICN, 1, 2500, NULL);
    }
  }
  else if (item == ITEM_BLUETOOTH)
  {
    Shortcut_Run(SETTINGS_BT_ID);
  }
  else if (item == ITEM_IRDA)
  {
    Shortcut_Run(SETTINGS_IR_ID);
  }
  else if (item == ITEM_PROFILES)
  {
    Shortcut_Run(SELECT_PROFILE_ID);
  }
  else if (item == ITEM_STANDBY)
  {
    UI_Event(RETURN_TO_STANDBY_EVENT);
  }
}

int Menu_onMessage(GUI_MESSAGE *msg)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)GUIonMessage_GetBook(msg);

  if (GUIonMessage_GetMsg(msg))
  {
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == ITEM_RESTART)
    {
      GUIonMessage_SetMenuItemText(msg, RESTART_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, RESTART_ICN);
    }
    else if (item == ITEM_SHUTDOWN)
    {
      GUIonMessage_SetMenuItemText(msg, SHUTDOWN_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SHUTDOWN_ICN);
    }
    else if (item == ITEM_SILENT)
    {
      GUIonMessage_SetMenuItemText(msg, SILENTMODE_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SILENTMODE_ICN);
    }
    else if (item == ITEM_BLUETOOTH)
    {
      GUIonMessage_SetMenuItemText(msg, BLUETOOTH_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, BLUETOOTH_ICN);
    }
    else if (item == ITEM_IRDA)
    {
      GUIonMessage_SetMenuItemText(msg, IRDA_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, IRDA_ICN);
    }
    else if (item == ITEM_PROFILES)
    {
      GUIonMessage_SetMenuItemText(msg, PROFILES_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, PROFILES_ICN);
    }
    else if (item == ITEM_STANDBY)
    {
      GUIonMessage_SetMenuItemText(msg, STR("Standby"));
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, STANDBY_ICN);
    }
  }
  return 1;
}

int pg_QuickAccess_Book_EnterEvent(void *data, BOOK *book)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;

  if (mbk->MainMenu = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleType(mbk->MainMenu, UI_TitleMode_Large);
    GUIObject_SetTitleText(mbk->MainMenu, STR("QuickAccessMenu"));
    GUIObject_SetSecondRowTitleText(mbk->MainMenu, GetFreeHeap());
    GUIObject_SetStyle(mbk->MainMenu, UI_OverlayStyle_FullScreenNoStatus);
    ListMenu_SetItemCount(mbk->MainMenu, ITEM_LAST);
    ListMenu_SetOnMessage(mbk->MainMenu, Menu_onMessage);
    ListMenu_SetCursorToItem(mbk->MainMenu, ITEM_RESTART);
    ListMenu_SetHotkeyMode(mbk->MainMenu, LKHM_SHORTCUT);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_SELECT1, Menu_Select);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_BACK, Menu_Back);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_LONG_BACK, Menu_Exit);
    GUIObject_Show(mbk->MainMenu);
  }

  return 1;
}

int pg_QuickAccess_Book_ExitEvent(void *data, BOOK *book)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;
  FREE_GUI(mbk->MainMenu);
  return 1;
}

int pg_QuickAccess_Book_CancelEvent(void *data, BOOK *book)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;
  FreeBook(mbk);
  return 1;
}

void QuickAccess_Book_onClose(BOOK *book)
{
  QuickAccess_Book *mbk = (QuickAccess_Book *)book;
  FREE_GUI(mbk->MainMenu);
}

extern "C" void Create_QuickAccess_Book()
{
  if (isKeylocked())
    return;

  QuickAccess_Book *mbk = (QuickAccess_Book *)FindBook(IsQuickAccessBook);
  if (!mbk)
  {
    mbk = (QuickAccess_Book *)malloc(sizeof(QuickAccess_Book));
    memset(mbk, NULL, sizeof(QuickAccess_Book));
    if (!CreateBook(mbk, QuickAccess_Book_onClose, &QuickAccess_Book_Base_Page, BOOKNAME, NO_BOOK_ID, NULL))
    {
      mfree(mbk);
    }
    else
    {
      BookObj_GotoPage(mbk, &QuickAccess_Book_Main_Page);
    }
  }
  else
  {
    FreeBook(mbk);
  }
}
