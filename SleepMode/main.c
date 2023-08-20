#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"

#include "main.h"
#include "Lib.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(NULL, size, 1, 5, "", NULL);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "", NULL);
#else
  return memalloc(size, 1, 5, "", NULL);
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, "", NULL);
#elif defined(A2)
    memfree(NULL, mem, "", NULL);
#else
    memfree(mem, "", NULL);
#endif
}

uint16_t *getTimerID()
{
  return (uint16_t *)get_envp(NULL, EMP_NAME);
}

uint16_t *createTimerID()
{
  uint16_t *pTimerID = (uint16_t *)malloc(sizeof(uint16_t));
  memset(pTimerID, NULL, sizeof(uint16_t));
  set_envp(NULL, EMP_NAME, (OSADDRESS)pTimerID);
  return pTimerID;
}

void onTimer(uint16_t timerID, LPARAM disp_obj)
{
  uint16_t *pTimerID = getTimerID();
  DispObject_InvalidateRect((DISP_OBJ *)disp_obj, NULL);
  Timer_ReSet(pTimerID, 1000, onTimer, disp_obj);
}

extern "C" void SetRefreshTimer(DISP_OBJ *disp_obj)
{
  uint16_t *pTimerID = getTimerID();
  if (!pTimerID)
    pTimerID = createTimerID();
  *pTimerID = Timer_Set(1000, onTimer, (LPARAM *)disp_obj);
}

extern "C" void KillRefreshTimer()
{
  uint16_t *pTimerID = getTimerID();
  if (pTimerID)
  {
    Timer_Kill(pTimerID);
    *pTimerID = NULL;
  }
}

extern "C" void New_SleepMode_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  uint16_t disp_width = Display_GetWidth(UIDisplay_Main);
  TEXTID text_id;

  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  char weekday;

  DATETIME dt;
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
  int events = *(MissedEvents);
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
