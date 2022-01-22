#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"
#include "..\include\book\ScreenSaverBook.h"

#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(0, size, 1, 5, "", 0));
#elif defined(A2)
  return (memalloc(clWhite, size, 1, 5, "", 0));
#else
  return (memalloc(size, 1, 5, "", 0));
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "", 0);
#else
  if (mem)
    memfree(mem, "", 0);
#endif
}

u16 *getTimerID()
{
  return (u16 *)get_envp(get_bid(current_process()), VARNAME);
}

u16 *createTimerID()
{
  u16 *pTimerID = (u16 *)malloc(sizeof(u16));
  memset(pTimerID, NULL, sizeof(u16));
  set_envp(get_bid(current_process()), VARNAME, (OSADDRESS)pTimerID);
  return pTimerID;
}

void onTimer(u16 timerID, LPARAM param)
{
  u16 *pTimerID = getTimerID();
  ScreenSaverBook *ScrSavBook = (ScreenSaverBook *)FindBook(IsScreenSaverBook);
  DISP_OBJ *disp_sleepmode = GUIObject_GetDispObject(ScrSavBook->sleepmode);
  Timer_ReSet(pTimerID, 1000, onTimer, param);
  DispObject_InvalidateRect(disp_sleepmode, NULL);
}

extern "C" void SetRefreshTimer()
{
  u16 *pTimerID = getTimerID();
  if (!pTimerID)
    pTimerID = createTimerID();
  *pTimerID = Timer_Set(1000, onTimer, NULL);
}

extern "C" void KillRefreshTimer()
{
  u16 *pTimerID = getTimerID();
  if (pTimerID)
  {
    Timer_Kill(pTimerID);
    *pTimerID = NULL;
  }
}

extern "C" void New_SleepMode_OnRedraw(DISP_OBJ *dobj, int a, int b, int c)
{
  int _SYNC = 0;
  int *SYNC = &_SYNC;

  char weekday;

  DATETIME dt;
  TEXTID text_id;

  u16 disp_width = Display_GetWidth(UIDisplay_Main);

  REQUEST_DATEANDTIME_GET(SYNC, &dt);

  text_id = Time2ID(&dt.time, 2, FALSE);
  SetFont(FONT_TIME);
  DrawString(text_id, AlignCenter, 1, TIME_Y, disp_width, TIME_Y + GetImageHeight(30), 20, 5, clBlack, clBlack);
  TextID_Destroy(text_id);

  text_id = Date2ID(&dt.date, 0, 1);
  SetFont(FONT_DATE);
  DrawString(text_id, AlignCenter, 1, DATE_Y, disp_width, DATE_Y + GetImageHeight(30), 20, 5, clBlack, clBlack);
  TextID_Destroy(text_id);

  DATE_GetWeekDay(&dt.date, &weekday);
  text_id = days[weekday];
  SetFont(FONT_DAY);
  DrawString(text_id, AlignCenter, 1, DAY_Y, disp_width, DAY_Y + GetImageHeight(30), 20, 5, clBlack, clBlack);
  TextID_Destroy(text_id);

  int missed[ICONS_COUNT + 2];
  int *id = missed;
  int events = *((char *)MissedEvents);
  int index;

  for (index = 0; index < ICONS_COUNT; index++)
  {
    if (events & (1 << index))
    {
      *id++ = missed_icons[index];

      if (index < 2)
        *id++ = 0x78000020;
    }
  }
  text_id = TextID_Create(&missed[0], ENC_TEXTID, id - missed);
  DrawString(text_id, AlignCenter, 1, MISSED_Y, disp_width, MISSED_Y + GetImageHeight(30), 40, 1, clBlack, clBlack);
  TextID_Destroy(text_id);
}