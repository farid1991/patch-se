#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\MusicApplication_book.h"

#include "Lib.h"
#include "main.h"

TIMER_DATA *Create_TimerData()
{
  TIMER_DATA *Data = (TIMER_DATA *)memalloc(0xFFFFFFFF, sizeof(TIMER_DATA), 1, 5, "tm", 0);
  memset(Data, NULL, sizeof(TIMER_DATA));
  set_envp(NULL, EMP_NAME, (OSADDRESS)Data);
  return Data;
}

TIMER_DATA *Get_TimerData()
{
  TIMER_DATA *Data = (TIMER_DATA *)get_envp(NULL, EMP_NAME);
  if (Data)
    return Data;
  return Create_TimerData();
}

extern "C" void Kill_Timer()
{
  TIMER_DATA *Data = Get_TimerData();
  if (Data)
  {
    if (Data->TimerID)
    {
      Timer_Kill(&Data->TimerID);
      Data->TimerID = NULL;
      Data->TimerOn = FALSE;
    }
    memfree(0, Data, "tm", 0);
  }
}

void onTimer(u16 timerID, LPARAM lparam)
{
  TIMER_DATA *Data = Get_TimerData();

  if (Data->Interval == 0)
  {
    Kill_Timer();
    BOOK *MusicBook = FindBook(IsMusicApplication_Book);
    if (MusicBook)
    {
      FreeBook(MusicBook);
    }
  }

  if (Data->TimerOn)
  {
    Data->Interval--;
    Timer_ReSet(&Data->TimerID, 1000, onTimer, lparam);
  }
}

void MusicApplication_ShutdownTimer__OnAcceptTimeInput(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;

  TIMER_DATA *Data = Get_TimerData();

  int selected = ListMenu_GetSelectedItem(pMusicBook->Gui_submenu);
  switch (selected)
  {
  case 0:
    Data->Interval = 5 * 60;
    break;
  case 1:
    Data->Interval = 10 * 60;
    break;
  case 2:
    Data->Interval = 15 * 60;
    break;
  case 3:
    Data->Interval = 20 * 60;
    break;
  case 4:
    Data->Interval = 30 * 60;
    break;
  case 5:
    Data->Interval = 40 * 60;
    break;
  case 6:
    Data->Interval = 50 * 60;
    break;
  case 7:
    Data->Interval = 60 * 60;
    break;
  }

  Data->TimerOn = TRUE;
  onTimer(0, 0);
  CreateMessageBox(EMPTY_TEXTID, TURNEDON_TXT, 1, 1500, pMusicBook);
  FREE_GUI(pMusicBook->Gui_submenu);
}

void MusicApplication_ShutdownTimer__OnDisableTimer(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;

  TIMER_DATA *Data = Get_TimerData();

  if (Data->TimerID)
  {
    Timer_Kill(&Data->TimerID);
    Data->TimerID = NULL;
    Data->TimerOn = FALSE;
    CreateMessageBox(EMPTY_TEXTID, TURNEDOFF_TXT, 1, 2000, pMusicBook);
  }
  FREE_GUI(pMusicBook->Gui_submenu);
}

int MusicApplication_ShutdownTimer__OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    switch (item)
    {
    case 0:
      GUIonMessage_SetMenuItemText(msg, STR("5 Minutes"));
      break;
    case 1:
      GUIonMessage_SetMenuItemText(msg, STR("10 Minutes"));
      break;
    case 2:
      GUIonMessage_SetMenuItemText(msg, STR("15 Minutes"));
      break;
    case 3:
      GUIonMessage_SetMenuItemText(msg, STR("20 Minutes"));
      break;
    case 4:
      GUIonMessage_SetMenuItemText(msg, STR("30 Minutes"));
      break;
    case 5:
      GUIonMessage_SetMenuItemText(msg, STR("40 Minutes"));
      break;
    case 6:
      GUIonMessage_SetMenuItemText(msg, STR("50 Minutes"));
      break;
    case 7:
      GUIonMessage_SetMenuItemText(msg, STR("60 Minutes"));
      break;
    }
  }
  return 1;
}

int pg_MusicApplication_ShutdownTimer__EnterAction(void *wData, BOOK *book)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  if (pMusicBook->Gui_submenu = CreateListMenu(pMusicBook, UIDisplay_Main))
  {
    GUIObject_SetTitleText(pMusicBook->Gui_submenu, TIMER_TXT);
    GUIObject_SetStyle(pMusicBook->Gui_submenu, UI_OverlayStyle_PopupNoFrame);
    ListMenu_SetItemCount(pMusicBook->Gui_submenu, 8);
    ListMenu_SetCursorToItem(pMusicBook->Gui_submenu, 0);
    ListMenu_SetHotkeyMode(pMusicBook->Gui_submenu, LKHM_SHORTCUT);
    ListMenu_SetOnMessage(pMusicBook->Gui_submenu, MusicApplication_ShutdownTimer__OnMessage);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_SELECT1, MusicApplication_ShutdownTimer__OnAcceptTimeInput);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_BACK, MusicApplication_PrevAction);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);

    GUIObject_SoftKeys_SetActionAndText(pMusicBook->Gui_submenu, 1, MusicApplication_ShutdownTimer__OnDisableTimer, TURNOFF_TXT);

    TIMER_DATA *Data = Get_TimerData();
    if (Data->TimerOn)
      GUIObject_SoftKeys_SetVisible(pMusicBook->Gui_submenu, 1, TRUE);
    else
      GUIObject_SoftKeys_SetVisible(pMusicBook->Gui_submenu, 1, FALSE);

    GUIObject_Show(pMusicBook->Gui_submenu);
  }
  return 1;
}

const PAGE_MSG MusicApplication_ShutdownTimer[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_ShutdownTimer__EnterAction,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousAction,
        CANCEL_EVENT, pg_MusicApplication_CancelAction,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousAction,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitAction,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_ShutdownTimer_Page = {"MusicApplication_ShutdownTimer_Page", NULL, MusicApplication_ShutdownTimer};

void Call_TimerPage(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
#if defined(DB3150v1)
  pMusicBook->unk_0x75 = TRUE;
#elif defined(DB3350) || defined(DB3150v2)
  pMusicBook->unk_0x94 = TRUE;
#endif
  BookObj_CallPage(pMusicBook, &MusicApplication_ShutdownTimer_Page);
}

extern "C" void Set_New_SoftKeys(GUI *player_gui)
{
  GUIObject_SoftKeys_SetItemAsSubItem(player_gui, ACTION_MP_SETTINGS, ACTION_MP_SHUTDOWNTIMER);
  GUIObject_SoftKeys_SetAction(player_gui, ACTION_MP_SHUTDOWNTIMER, Call_TimerPage);
  GUIObject_SoftKeys_SetText(player_gui, ACTION_MP_SHUTDOWNTIMER, TIMER_TXT);
  //GUIObject_SoftKeys_SetInfoText( player_gui, ACTION_MP_SHUTDOWNTIMER, GetRemainingTimeID() );
#ifndef DB3350
  MediaPlayer_SoftKeys_SetItemAsSubItem(player_gui, ACTION_MP_SETTINGS, ACTION_MP_SHUTDOWNTIMER);
  MediaPlayer_SoftKeys_SetAction(player_gui, ACTION_MP_SHUTDOWNTIMER, Call_TimerPage);
  MediaPlayer_SoftKeys_SetText(player_gui, ACTION_MP_SHUTDOWNTIMER, TIMER_TXT);
  //MediaPlayer_SoftKeys_SetInfoText( player_gui, ACTION_MP_SHUTDOWNTIMER, GetRemainingTimeID() );
#endif
}
