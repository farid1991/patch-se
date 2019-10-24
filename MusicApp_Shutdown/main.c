#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"

__thumb void *malloc(int size)
{
  return(memalloc(0xFFFFFFFF, size, 1, 5, "AT", 0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,"AT",0);
}
/*
const TEXTID items_text[] = 
{
  MODIFY_TEXT, INFORMATION_TEXT, DISABLE_TEXT
};

const IMAGEID iconID[] = 
{
  MODIFY_ICN, INFO_ICN, DISABLE_ICN
};
*/

TIMER_DATA* Create_TimerData()
{
  TIMER_DATA* Data = (TIMER_DATA*)malloc(sizeof(TIMER_DATA));
  memset(Data, NULL, sizeof(TIMER_DATA));
  set_envp(NULL, EMP_NAME, (OSADDRESS)Data);
  return Data;
}

TIMER_DATA* Get_TimerData()
{
  TIMER_DATA* Data = (TIMER_DATA*)get_envp(NULL, EMP_NAME);
  if (Data) return Data;
  return Create_TimerData();
}

extern "C"
void Kill_Timer()
{
  TIMER_DATA* Data = Get_TimerData();
  if (Data->TimerOn)
  {
    Timer_Kill(&Data->TimerID);
    Data->TimerID = NULL;
    Data->TimerOn = FALSE;
  }
}

void OnTimer(u16 timerID, LPARAM lparam)
{
  TIMER_DATA* Data = Get_TimerData();
  BOOK* MusicBook = FindBook(IsAudioPlayerBook);
  if (MusicBook)
  {  
    //FreeBook(MusicBook);
    MusicApp_CancelAction(MusicBook,NULL);
    Data->TimerID = NULL;
    Data->TimerOn = FALSE;
  }
}

void OnBackGUI(BOOK* book, GUI* gui)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  FREE_GUI(mbk->Gui_submenu)
}

void OnOkTimeInput(BOOK* book, GUI* gui)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  
  TIMER_DATA* Data = Get_TimerData();
  unsigned int i = TimeInput_GetTimeInt(mbk->Gui_submenu);
    
  int _SYNC = 0;
  int *SYNC = &_SYNC;
  
  DATETIME dt;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);
    
  Data->Hour = TI_GET_HOUR(i);
  Data->Min = TI_GET_MIN(i);
    
  if (Data->Hour == dt.time.hour && Data->Min == dt.time.min)
  {
    MessageBox_NoImage(EMPTY_TEXTID, STR( "Cannot set current time" ), 1, 1000, book);
  }
  else
  {
    int SelTime = Data->Hour * 60 * 60 + Data->Min * 60;
    int CurTime = dt.time.hour * 60 * 60 + dt.time.min * 60;
    if (SelTime < CurTime)
    {
      SelTime = SelTime + 86400;                       // + 24 hours
    }
    int Interval = (SelTime - CurTime) * 1000;
    
    Kill_Timer();    
    Data->TimerID = Timer_Set(Interval, OnTimer, NULL);
    
    Data->TimerOn = TRUE;
    MessageBox_NoImage(EMPTY_TEXTID, 0x1DEB, 1, 2000, book);
    FREE_GUI(mbk->Gui_submenu);
  }
}

void DisableTimer(BOOK* book, GUI* gui)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  
  TIMER_DATA* Data = Get_TimerData();
  
  Timer_Kill(&Data->TimerID);
  Data->TimerID = NULL;
  Data->TimerOn = FALSE;
  MessageBox_NoImage(EMPTY_TEXTID, 0x1DEA, 1, 2000, book);
  FREE_GUI(mbk->Gui_submenu);
}

void CreateTimeInput(BOOK* book, TIME* Time)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  TIMER_DATA* Data = Get_TimerData();
  
  FREE_GUI(mbk->Gui_submenu);
  
  mbk->Gui_submenu = CreateTimeInputVA(0,
                                       VAR_BOOK,mbk,
                                       VAR_HEADER_TEXT,HEADER_TEXT,
                                       VAR_TIMEINP_TIMEFORMAT,1,
                                       VAR_TIMEINP_TIME,Time,
                                       0);
    
  GUIObject_SoftKeys_SetAction(mbk->Gui_submenu, ACTION_SELECT1, OnOkTimeInput);
  GUIObject_SoftKeys_SetText(mbk->Gui_submenu, ACTION_SELECT1, SELECT_TEXT);
  GUIObject_SoftKeys_SetAction(mbk->Gui_submenu, ACTION_BACK, OnBackGUI);
  
  if (Data->TimerOn)
    GUIObject_SoftKeys_SetActionAndText(mbk->Gui_submenu, 1, DisableTimer, TURNOFF_TEXT);
  
  GUIInput_SetIcon(mbk->Gui_submenu, INPUT_ICN);
}
/*
void OnBackShutdownMenu(BOOK* book, GUI* Sh_Menu)
{
  FREE_GUI(Sh_Menu);
}

TEXTID GetRemainingTimeID()
{
  TIMER_DATA* Data = Get_TimerData();
  
  TEXTID info = EMPTY_TEXTID;
  
  if(Data->TimerOn)
  {
    int _SYNC = 0;
    int *SYNC = &_SYNC;
  
    TIME timer_time; 
    timer_time.hour = Data->Hour;
    timer_time.min = Data->Min;
    timer_time.sec = 0;
    
    DATETIME datetime_real;
    REQUEST_DATEANDTIME_GET(SYNC, &datetime_real);
    int unix_real = datetime2unixtime(&datetime_real);
    
    DATETIME* datetime_timer = (DATETIME*)malloc(sizeof(DATETIME));
    datetime_timer->date.year = datetime_real.date.year;
    datetime_timer->date.mon = datetime_real.date.mon;
    datetime_timer->date.day = datetime_real.date.day+1;
    datetime_timer->time.hour = timer_time.hour;
    datetime_timer->time.min = timer_time.min+1;
    datetime_timer->time.sec = 0;
    int unix_alarm = datetime2unixtime(datetime_timer);
    
    DATETIME datetime_back;
    unixtime2datetime(unix_alarm - unix_real, &datetime_back);
    
    mfree(datetime_timer);
  
    wchar_t buf[64];
    snwprintf(buf, MAXELEMS(buf), L"MusicApp will be closed in %02d:%02d", datetime_back.time.hour, datetime_back.time.min);
    info = TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
  }
  else
  {
    info = TextID_Create(L"Timer off", ENC_UCS2, TEXTID_ANY_LEN);
  }
  return info;
}

void OnShowInfoText(BOOK* book, GUI* Sh_Menu)
{
  TEXTID text = TextID_Create(L"MusicApp Timer\nv1.0\n\n(c) farid", ENC_UCS2, TEXTID_ANY_LEN );
  MessageBox_NoImage(EMPTY_TEXTID, text, 1, 0, book);
}

int TimerMenu_Callback(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText( msg, items_text[index] );
    GUIonMessage_SetMenuItemIcon( msg, 0, iconID[index] );
    break;
  }
  return 1;
}

void ShowInfo(BOOK* book, TIMER_DATA* Data)
{
  wchar_t InfoBuff[64];
  snwprintf(InfoBuff, MAXELEMS(InfoBuff), L"Timer Enabled\n\nTime: %02d:%02d", Data->Hour, Data->Min);
  MessageBox_NoImage(EMPTY_TEXTID, TextID_Create( InfoBuff, ENC_UCS2, TEXTID_ANY_LEN ), 1, 2000, book);
}

void DisableTimer(BOOK* book, TIMER_DATA* Data)
{
  Timer_Kill(&Data->TimerID);
  Data->TimerID = FALSE;
  Data->TimerOn = FALSE;
  MessageBox_NoImage(EMPTY_TEXTID, 0x1DEA, 1, 2000, book);
}

void ModifyTimer(BOOK* book, TIMER_DATA* Data)
{
  TIME t;
  t.hour = Data->Hour;
  t.min = Data->Min;
  t.sec = 0;
  CreateTimeInput(book, &t);
}

void OnSelectShutdownMenu( BOOK* book, GUI* Sh_Menu )
{
  TIMER_DATA* Data = Get_TimerData();
    
  switch(ListMenu_GetSelectedItem(Sh_Menu))
  {
  case 0:
    ModifyTimer(book, Data);
    break;
  case 1:
    ShowInfo(book, Data);
    break;
  case 2:
    DisableTimer(book, Data);
    FREE_GUI(Sh_Menu);
    break;
  }
}

void CreateShutdownMenu(BOOK* book)
{
  GUI* TimerMenu = CreateListMenu(book, 0);
  
  GUIObject_SetTitleText(TimerMenu, HEADER_TEXT);
  ListMenu_SetItemCount(TimerMenu, 3);
  ListMenu_SetCursorToItem(TimerMenu, 0);
  ListMenu_SetOnMessage(TimerMenu, TimerMenu_Callback);

  GUIObject_SoftKeys_SetAction(TimerMenu, ACTION_BACK, OnBackGUI);
  GUIObject_SoftKeys_SetAction(TimerMenu, ACTION_LONG_BACK, OnBackGUI);
  GUIObject_SoftKeys_SetAction(TimerMenu, ACTION_SELECT1, OnSelectShutdownMenu);
  
  GUIObject_SoftKeys_SetActionAndText(TimerMenu, 0, OnShowInfoText, ABOUT_TEXT);
  
  GUIObject_Show(TimerMenu);
};
*/
void Call_TimerPage( BOOK* book, GUI* gui )
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  
  TIMER_DATA* Data = Get_TimerData();
  
  TIME time;
  
  if (Data->TimerOn)
  {
    
    time.hour = Data->Hour;
    time.min = Data->Min;
    time.sec = 0;
    //CreateShutdownMenu(book);
  }
  else
  {
    int _SYNC = 0;
    int *SYNC = &_SYNC;
    
    DATETIME dt;
    REQUEST_DATEANDTIME_GET(SYNC, &dt);
    
    time = dt.time;
  }
  CreateTimeInput(mbk, &time);
}

extern "C"
void Set_New_Action( GUI* player_gui )
{
  GUIObject_SoftKeys_SetItemAsSubItem( player_gui, ACTION_MP_SETTINGS, ACTION_MP_TIMER);
  GUIObject_SoftKeys_SetAction( player_gui, ACTION_MP_TIMER, Call_TimerPage);
  GUIObject_SoftKeys_SetText( player_gui, ACTION_MP_TIMER, TIMER_TEXT);
  //GUIObject_SoftKeys_SetInfoText( player_gui, ACTION_MP_TIMER, GetRemainingTimeID() );
  
  MediaPlayer_SoftKeys_SetItemAsSubItem( player_gui, ACTION_MP_SETTINGS, ACTION_MP_TIMER);
  MediaPlayer_SoftKeys_SetAction( player_gui, ACTION_MP_TIMER, Call_TimerPage);
  MediaPlayer_SoftKeys_SetText( player_gui, ACTION_MP_TIMER, TIMER_TEXT);
  //MediaPlayer_SoftKeys_SetInfoText( player_gui, ACTION_MP_TIMER, GetRemainingTimeID() );
}
