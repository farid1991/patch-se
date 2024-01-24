#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\QuickAccessBook.h"

#include "Lib.h"
#include "main.h"

#ifdef HAVE_BT
bool BT_isBusy()
{
  bool busy = false;
  void (*funk)(int, int *);
  void (*funk2)(int);

  int m[2];
  m[0] = 0;

  if (hz(m))
  {
    if (m[0])
    {
      int r0 = m[0];
      int *r2 = (int *)m[0];
      funk = (void (*)(int, int *))(*(int *)(r2[0] + 0x20));
      int *r1 = (int *)((int)m + 4);
      funk(r0, r1);
    }
  }
  if (m[0])
  {
    int r0 = m[0];
    int *r1 = (int *)m[0];
    funk2 = (void (*)(int))(*(int *)(r1[0] + 0xC));
    funk2(r0);
    m[0] = 0;
  }
  busy = *(char *)((int)m + 4);
  return busy;
}
#endif

int QuickAccess_onMessage(GUI_MESSAGE *msg)
{
  if (GUIonMessage_GetMsg(msg))
  {
    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case ITEM_RESTART:
      GUIonMessage_SetMenuItemText(msg, RESTART_TXT);
      GUIonMessage_SetMenuItemInfoText(msg, RESTART_INFO_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, RESTART_ICN);
      break;
    case ITEM_SHUTDOWN:
      GUIonMessage_SetMenuItemText(msg, SHUTDOWN_TXT);
      GUIonMessage_SetMenuItemInfoText(msg, SHUTDOWN_INFO_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SHUTDOWN_ICN);
      break;
    case ITEM_FLIGHTMODE:
      GUIonMessage_SetMenuItemText(msg, FLIGHTMODE_TXT);
      if (FlightMode_GetState())
      {
        if (ConnectionManager_Connection_GetState())
        {
          GUIonMessage_SetItemDisabled(msg, TRUE);
          GUIonMessage_SetMenuItemUnavailableText(msg, FLIGHTMODE_UNAVAIL_TXT);
        }
        else
        {
          GUIonMessage_SetMenuItemInfoText(msg, FLIGHTMODE_OFF_TXT);
        }
      }
      else
      {
        GUIonMessage_SetMenuItemInfoText(msg, FLIGHTMODE_ON_TXT);
      }
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, FLIGHTMODE_ICN);
      break;
    case ITEM_SEPARATOR1:
    case ITEM_SEPARATOR2:
    case ITEM_SEPARATOR3:
      GUIonMessage_SetLineSeparator(msg, 1);
      break;
    case ITEM_SILENT:
      GUIonMessage_SetMenuItemText(msg, SILENTMODE_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SILENTMODE_ICN);
      if (GetSilent())
      {
        GUIonMessage_SetMenuItemInfoText(msg, TURNOFF_SILENTMODE_TXT);
      }
      else
      {
        GUIonMessage_SetMenuItemInfoText(msg, TURNON_SILENTMODE_TXT);
      }
      break;
    case ITEM_KEYLOCK:
      GUIonMessage_SetMenuItemText(msg, KEYLOCK_TXT);
      GUIonMessage_SetMenuItemInfoText(msg, LOCKKEYS_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, KEYLOCK_ICN);
      break;
#ifdef HAVE_BT
    case ITEM_BLUETOOTH:
      GUIonMessage_SetMenuItemText(msg, BLUETOOTH_TXT);
      if (BT_isBusy())
      {
        GUIonMessage_SetMenuItemInfoText(msg, BT_BUSY_TXT);
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, BT_ACTIVE_ICN);
        GUIonMessage_SetItemDisabled(msg, TRUE);
        GUIonMessage_SetMenuItemUnavailableText(msg, BTINFO_BUSY_TXT);
      }
      else
      {
        if (Bluetooth_GetState())
        {
          GUIonMessage_SetMenuItemInfoText(msg, TURNOFF_TXT);
        }
        else
        {
          GUIonMessage_SetMenuItemInfoText(msg, TURNON_TXT);
        }
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, BLUETOOTH_ICN);
      }
      break;
#endif
#ifdef HAVE_IRDA
    case ITEM_IRDA:
      GUIonMessage_SetMenuItemText(msg, IRDA_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, IRDA_ICN);
      GUIonMessage_SetMenuItemInfoText(msg, VIA_IRDA_TXT);
      break;
#endif
    case ITEM_PROFILES:
      TEXTID_DATA GetProfile;
      wchar_t SetName[0x10];
      char error;
      GetProfile.ptr = SetName;
      REQUEST_PROFILE_GETPROFILENAME(SYNC, -2, &GetProfile, &error);

      GUIonMessage_SetMenuItemText(msg, PROFILES_TXT);
      GUIonMessage_SetMenuItemInfoText(msg, TextID_Create(GetProfile.ptr, ENC_UCS2, GetProfile.lenght));
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, PROFILE_ICN);
      break;
    case ITEM_STANDBY:
      GUIonMessage_SetMenuItemText(msg, STANDBY_TXT);
      GUIonMessage_SetMenuItemInfoText(msg, SETSTANDBY_TXT);
      GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DESKTOP_ICN);
      break;
    }
  }
  return 1;
}

void FlightMode(BOOK *book, GUI *gui)
{
  FREE_GUI(gui);
  FreeBook(book);
  FlightMode_SetState(ON);
}

void Restart(BOOK *book, GUI *gui)
{
  FREE_GUI(gui);
  FreeBook(book);
  REQUEST_SYSTEM_RESTART();
}

void ShutDown(BOOK *book, GUI *gui)
{
  FREE_GUI(gui);
  FreeBook(book);
  REQUEST_SYSTEM_SHUTDOWN();
}

void YesNoQuestion_onNo(BOOK *book, GUI *gui)
{
  FREE_GUI(gui);
}

void Create_YesNoQuestion(QuickAccessBook *qabook, int type)
{
  TEXTID text_id;
  GUI *question;

  if (question = CreateYesNoQuestion(qabook, UIDisplay_Main))
  {
    if (type == ITEM_RESTART)
    {
      text_id = STR("Restart Phone?");
      GUIObject_SoftKeys_SetAction(question, ACTION_YES, Restart);
    }
    else if (type == ITEM_SHUTDOWN)
    {
      text_id = STR("Shutdown Phone?");
      GUIObject_SoftKeys_SetAction(question, ACTION_YES, ShutDown);
    }
    else if (type == ITEM_FLIGHTMODE)
    {
      text_id = STR("Turn on FlightMode?");
      GUIObject_SoftKeys_SetAction(question, ACTION_YES, FlightMode);
    }
    YesNoQuestion_SetQuestionText(question, text_id);
    YesNoQuestion_SetIcon(question, POPUP_WARNING_ICN);
    GUIObject_SoftKeys_SetAction(question, ACTION_NO, YesNoQuestion_onNo);
    GUIObject_SoftKeys_SetAction(question, ACTION_BACK, YesNoQuestion_onNo);
    GUIObject_Show(question);
  }
}

void QuickAccess_OnSelect(BOOK *book, GUI *gui)
{
  QuickAccessBook *qabook = (QuickAccessBook *)book;
  int item = ListMenu_GetSelectedItem(qabook->menu);
  switch (item)
  {
  case ITEM_RESTART:
    Create_YesNoQuestion(qabook, item);
    break;
  case ITEM_SHUTDOWN:
    Create_YesNoQuestion(qabook, item);
    break;
  case ITEM_FLIGHTMODE:
    if (FlightMode_GetState())
    {
      FlightMode_SetState(OFF);
    }
    else
    {
      Create_YesNoQuestion(qabook, item);
    }
    break;
  case ITEM_SILENT:
    int num;
    REQUEST_PROFILE_GETACTIVEPROFILE(SYNC, &num);
    if (GetSilent())
    {
      REQUEST_SETTING_SILENCE_SET(SYNC, (u16)num, OFF);
    }
    else
    {
      REQUEST_SETTING_SILENCE_SET(SYNC, (u16)num, ON);
    }
    break;
  case ITEM_KEYLOCK:
    Lock_Keyboard();
    break;
#ifdef HAVE_BT
  case ITEM_BLUETOOTH:
    if (Bluetooth_GetState())
    {
      Bluetooth_SetState(OFF);
    }
    else
    {
      Bluetooth_SetState(ON);
    }
    break;
#endif
#ifdef HAVE_IRDA
  case ITEM_IRDA:
    Shortcut_Run(IRDA_LINK);
    break;
#endif
  case ITEM_PROFILES:
    Shortcut_Run(PROFILE_LINK);
    break;
  case ITEM_STANDBY:
    BookObj_SetFocus(Find_StandbyBook(), UIDisplay_Main);
    break;
  }

  if (item > ITEM_FLIGHTMODE)
    FreeBook(qabook);
}

void QuickAccess_OnClose(BOOK *book, GUI *gui)
{
  FreeBook(book);
}

void QuickAccess_OnLClose(BOOK *book, GUI *gui)
{
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

TEXTID GetFreeHeap()
{
  wchar_t buff[64];
  snwprintf(buff, MAXELEMS(buff), L"Heap: %d Kb", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" int New_QuickAccessMenu_EnterEvent(void *data, BOOK *book)
{
  QuickAccessBook *qabook = (QuickAccessBook *)book;
  FREE_GUI(qabook->menu);

  if (qabook->menu = CreateListMenu(qabook, UIDisplay_Main))
  {
    ListMenu_SetItemCount(qabook->menu, ITEM_LAST);
    ListMenu_SetCursorToItem(qabook->menu, ITEM_RESTART);
    ListMenu_SetHotkeyMode(qabook->menu, LKHM_SHORTCUT);
    ListMenu_SetOnMessage(qabook->menu, QuickAccess_onMessage);
    GUIObject_SetStyle(qabook->menu, UI_OverlayStyle_TrueFullScreen);
    GUIObject_SetTitleType(qabook->menu, UI_TitleMode_Large);
    GUIObject_SetTitleText(qabook->menu, STR("Quick Access Menu"));
    GUIObject_SetSecondRowTitleText(qabook->menu, GetFreeHeap());
    GUIObject_SoftKeys_SetAction(qabook->menu, ACTION_BACK, QuickAccess_OnClose);
    GUIObject_SoftKeys_SetAction(qabook->menu, ACTION_LONG_BACK, QuickAccess_OnLClose);
    GUIObject_SoftKeys_SetAction(qabook->menu, ACTION_SELECT1, QuickAccess_OnSelect);
    GUIObject_Show(qabook->menu);
  }
  return 1;
}
