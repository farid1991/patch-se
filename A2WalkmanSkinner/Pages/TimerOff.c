#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#include "..\\dll.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "..\\Function.h"
#include "..\\main.h"

#include "..\\GUI\TimeInput.h"

#include "Lyric.h"
#include "Skins.h"
#include "TimerOff.h"

void Kill_TimerOff()
{
  Internal_Function *Data = Get_Internal_Function();
  if (Data->TimerOn)
  {
    Timer_Kill(&Data->AutoOffTimer);
    Data->AutoOffTimer = NULL;
    Data->TimerOn = FALSE;
  }
}

void onTimer(u16 timerID, LPARAM lparam)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)lparam;

  Internal_Function *Data = Get_Internal_Function();

  if ((Data->Counter == 0) && Data->TimerOn)
  {
    Kill_TimerOff();
    Free_AdvLyricBook();
    Free_SkinEditor_Book();
    MusicApplication_CancelAction(MusicBook, NULL);
  }
  else
  {
    (Data->Counter)--;
    Timer_ReSet(&Data->AutoOffTimer, 1000, onTimer, (LPARAM *)MusicBook);
  }
}

void TimerOff_OnSelect(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  Internal_Function *Data = Get_Internal_Function();

  int min = XTimeInput_GetMinute(MusicBook->Gui_submenu);
  int sec = XTimeInput_GetSecond(MusicBook->Gui_submenu);

  Data->Counter = (min * 60) + sec;

  Kill_TimerOff();
  Data->AutoOffTimer = Timer_Set(1000, onTimer, (LPARAM *)MusicBook);
  Data->TimerOn = TRUE;

  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"Close MusicApp in %02d:%02d", min, sec);
  CreateMessageBox(EMPTY_TEXTID, TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN), 0, 1500, MusicBook);

  DESTROY_GUI(MusicBook->Gui_submenu);
}

void DisableTimer(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  Kill_TimerOff();
  CreateMessageBox(EMPTY_TEXTID, STR("Timer Off"), 0, 1500, MusicBook);
  DESTROY_GUI(MusicBook->Gui_submenu);
}

int pg_MusicApplication_TimerOff_EnterEvent(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);

  if (MusicBook->Gui_submenu = CreateXTimeInput(MusicBook))
  {
    TIME time_limit;
    time_limit.min = 59;
    time_limit.sec = 59;
    XTimeInput_SetTimeLimit(MusicBook->Gui_submenu, time_limit);
    XTimeInput_SetTitleText(MusicBook->Gui_submenu, TEXT_TIMER);
    GUIObject_SetStyle(MusicBook->Gui_submenu, GUIObject_GetStyle(MusicBook->Gui_NowPlaying));
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, TimerOff_OnSelect);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, MusicApplication_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);

    Internal_Function *Data = Get_Internal_Function();
    if (Data->TimerOn)
    {
      GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, 0, DisableTimer);
      GUIObject_SoftKeys_SetText(MusicBook->Gui_submenu, 0, STR("Turn Off"));
    }

    GUIObject_Show(MusicBook->Gui_submenu);
  }

  return 1;
}

void Call_TimerOff(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;

  BookObj_CallPage(MusicBook, &page_Music_TimerOff);
}
