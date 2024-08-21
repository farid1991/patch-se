#ifndef _TIME_H_
#define _TIME_H_

// Screen Padding
#define PADDING 4
#define CHEIGHT 8

static const char GuiName_Time[] = "GUI_Time";

#define TIME_MIN 0
#define TIME_SEC 1

typedef struct GUI GUI_TIMEINPUT;

typedef struct _DISP_OBJ_TIMEINPUT : DISP_OBJ
{
  int buf_min;
  int buf_sec;
  int track_time_min;
  int track_time_sec;
  int track_time_msec;
  uint16_t disp_width;
  uint16_t disp_height;
  uint8_t cstep;
  uint8_t cursor;
  TEXTID text_id;
  wchar_t buf[64];
} DISP_OBJ_TIMEINPUT;

void DBPlayer_Time(BOOK *book, GUI *gui);

#endif
