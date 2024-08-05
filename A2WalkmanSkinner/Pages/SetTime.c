#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\FilesList.h"
#include "..\\Function.h"
#include "..\\LNG.h"
#include "..\\main.h"

#include "..\\GUI\TimeInput.h"

#include "SetTime.h"

//==============================================================================
#if defined(DB3200) || defined(DB3210)
void SetTime_OnSelect(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  if (MusicBook->PlayerState == TMusicServerState_Playing || MusicBook->PlayerState == TMusicServerState_Interrupted)
  {
    TMusicServer_Time Time;
    Time.hours = XTimeInput_GetHour(MusicBook->Gui_submenu);
    Time.minutes = XTimeInput_GetMinute(MusicBook->Gui_submenu);
    Time.seconds = XTimeInput_GetSecond(MusicBook->Gui_submenu);
    MusicBook->pMusicServer->SetElapsedTime(Time);
  }
  else
  {
    CreateMessageBox(EMPTY_TEXTID, STR(TXT_MUSIC_NOT_PLAYING), 0, 1500, MusicBook);
  }
  DESTROY_GUI(MusicBook->Gui_submenu);
}

void SetTime_onBack(BOOK *book, GUI *gui)
{
#if defined(C901_R1GA028) || defined(C903_R1GA028) || defined(T715_R1GA026)
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);
#else
  MusicApplication_PrevAction(book, gui);
#endif
}

int pg_MusicApplication_SetTime_EnterEvent(void *r1, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);

  if (MusicBook->Gui_submenu = CreateXTimeInput(MusicBook))
  {
    TIME time_limit;
    Internal_Function *Data = Get_Internal_Function();
    time_limit.min = Data->FullTime.minutes;
    time_limit.sec = Data->FullTime.seconds;
    XTimeInput_SetTimeLimit(MusicBook->Gui_submenu, time_limit);
    XTimeInput_SetTitleText(MusicBook->Gui_submenu, TEXT_GO_TO);

    GUIObject_SetStyle(MusicBook->Gui_submenu, GUIObject_GetStyle(MusicBook->Gui_NowPlaying));
    
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, SetTime_OnSelect);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, SetTime_onBack);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);

    GUIObject_Show(MusicBook->Gui_submenu);
  }

  return 1;
}

void Enter_SetTime(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;
  BookObj_CallPage(MusicBook, &page_Music_Time);
}
#endif
