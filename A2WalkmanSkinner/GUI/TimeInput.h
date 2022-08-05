#ifndef _TIMEINPUT_H_
#define _TIMEINPUT_H_

#define MAX_MINUTE 59
#define MAX_SECOND 59

enum
{
  TIME_MIN,
  TIME_SEC
};

static const char GuiName_Time[] = "Gui_XTimeInput";

typedef struct GUI GUI_XTime;

typedef struct _DISP_OBJ_XTIMEINPUT : DISP_OBJ
{
  TEXTID title_text;
  TEXTID mins_text;
  TEXTID secs_text;

  TEXTID temp1;
  TEXTID temp2;
  TEXTID temp3;
  TEXTID temp4;

  TIME time;
  TIME max_time;
  char temp;

  int cursor;

  uint16_t disp_width;
  uint16_t disp_height;

} DISP_OBJ_XTIMEINPUT;

GUI_XTime *CreateXTimeInput(BOOK *book);
void XTimeInput_SetTime(GUI_XTime *gui_time, TIME time);
void XTimeInput_SetTimeLimit(GUI_XTime *gui_time, TIME max_time);
void XTimeInput_GetTime(GUI_XTime *gui_time, TIME *time);
int XTimeInput_GetHour(GUI_XTime *gui_time);
int XTimeInput_GetMinute(GUI_XTime *gui_time);
int XTimeInput_GetSecond(GUI_XTime *gui_time);
void XTimeInput_SetTitleText(GUI_XTime *gui_time, TEXTID title);

#endif
