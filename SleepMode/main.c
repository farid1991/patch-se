#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"

#include "dll.h"
#include "Lib.h"
#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(NULL, size, 1, 5, MEM_NAME, NULL);
#elif defined(A2)
  return memalloc(-1, size, 1, 5, MEM_NAME, NULL);
#else
  return memalloc(size, 1, 5, MEM_NAME, NULL);
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, MEM_NAME, NULL);
#elif defined(A2)
    memfree(NULL, mem, MEM_NAME, NULL);
#else
    memfree(mem, MEM_NAME, NULL);
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
  *pTimerID = Timer_Set(0, onTimer, (LPARAM *)disp_obj);
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

void DrawText(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color)
{
#if defined(DB3200) || defined(DB3210)
  dll_DrawString(font, text, align, x1, y1, x2, y2 + (font & 0xFF), pen_color);
#else
  SetFont(font);
  DrawString(text, align, x1, y1, x2, y2 + GetImageHeight(30), 20, 5, pen_color, pen_color);
#endif
}

extern "C" void New_SleepMode_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  uint16_t disp_width = Display_GetWidth(UIDisplay_Main);
  TEXTID text_id;

  DATETIME dt;
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);

  text_id = Time2ID(&dt.time, 2, FALSE);
  DrawText(FONT_TIME, text_id, AlignCenter, 0, TIME_Y, disp_width, TIME_Y, clBlack);
  TextID_Destroy(text_id);

  text_id = Date2ID(&dt.date, 0, 1);
  DrawText(FONT_DATE, text_id, AlignCenter, 0, DATE_Y, disp_width, DATE_Y, clBlack);
  TextID_Destroy(text_id);

  char weekday;
  DATE_GetWeekDay(&dt.date, &weekday);
  text_id = days[weekday];
  DrawText(FONT_DAY, text_id, AlignCenter, 0, DAY_Y, disp_width, DAY_Y, clBlack);
  TextID_Destroy(text_id);

  int missed[ICONS_COUNT];
  int *p = missed;
  int m = *(MissedEvents);
  int i;
  for (i = 0; i < ICONS_COUNT; i++)
  {
    if (m & (1 << i))
    {
      *p++ = missed_icons[i];
    }
  }

  int x = 0;
  for (i = 0; i < (p - missed); i++)
  {
#if defined(DB3200) || defined(DB3210)
    x = x + dll_GetImageWidth(missed[i]);
#else
    x = x + GetImageWidth(missed[i]);
#endif
  }

  x = (disp_width - (x + (i - 1) * 10)) / 2;
  for (i = 0; i < (p - missed); i++)
  {
#if defined(DB3200) || defined(DB3210)
    dll_GC_PutChar(x, MISSED_Y, 0, 0, missed[i]);
    x = x + 10 + dll_GetImageWidth(missed[i]);
#else
    GC_PutChar(get_DisplayGC(), x, MISSED_Y, 0, 0, missed[i]);
    x = x + 10 + GetImageWidth(missed[i]);
#endif
  }
}
