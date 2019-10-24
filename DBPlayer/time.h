#ifndef _TIME_H_
#define _TIME_H_

static const char GuiName_Time[] = "GUI_Time";

#define TIME_MIN 0
#define TIME_SEC 1

typedef struct _DISP_OBJ_TIME : DISP_OBJ
{
  int buf_min;
  int buf_sec;
  
  int track_time_min;
  int track_time_sec;
  
  TMMETime elapsed_time;
  int cstep;
  int curs;
  TEXTID buf_text;
  wchar_t buf[64];
}DISP_OBJ_TIME;

void DBPlayer_Time(BOOK* book, GUI* gui);

#endif
