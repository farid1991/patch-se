/*
;Show remaining time before the alarm
,Displayed on the first line in the list, and alarm clocks on your desktop
;Display format "hh:mm (hh:mm)"
;(c) E1kolyan
;(r) IronMaster
*/
#include "..\\include\Types.h"

#include "Lib.h"
#include "temp\target.h"

void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(0, size, 1, 5, "br", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "br", 0));
#else
  return (memalloc(size, 1, 5, "br", 0));
#endif
}

void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "br", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "br", 0);
#else
  memfree(mem, "br", 0);
#endif
}

extern "C" 
TEXTID GetRemainingTimeID(TIME *alarm)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  DATETIME datetime_real;
  REQUEST_DATEANDTIME_GET(SYNC, &datetime_real);
  int unix_real = datetime2unixtime(&datetime_real);

  DATETIME *datetime_alarm = (DATETIME *)malloc(sizeof(DATETIME));
  datetime_alarm->date.year = datetime_real.date.year;
  datetime_alarm->date.mon = datetime_real.date.mon;
  datetime_alarm->date.day = datetime_real.date.day + 1;
  datetime_alarm->time.hour = alarm->hour;
  datetime_alarm->time.min = alarm->min + 1;
  datetime_alarm->time.sec = 0;
  int unix_alarm = datetime2unixtime(datetime_alarm);

  DATETIME datetime_back;
  unixtime2datetime(unix_alarm - unix_real, &datetime_back);

  mfree(datetime_alarm);

  wchar_t buf[64];
  snwprintf(buf, MAXELEMS(buf), L"%02d:%02d (%02d:%02d)", alarm->hour, alarm->min, datetime_back.time.hour, datetime_back.time.min);
// #ifdef A2
  // return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN, NULL, NULL);
// #else
  return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
// #endif
}
