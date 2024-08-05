#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#include "..\\Colors.h"
#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"

#include "SelectFont.h"
#include "TimeInput.h"

void Update_TimeInput(DISP_OBJ_XTIMEINPUT *disp_obj)
{
  if (disp_obj->time.min == disp_obj->max_time.min)
  {
    if (disp_obj->time.sec > disp_obj->temp)
      disp_obj->time.sec = disp_obj->temp;
    disp_obj->max_time.sec = disp_obj->temp;
  }
  else
  {
    disp_obj->max_time.sec = MAX_SECOND;
  }
}

int XTimeInput_OnCreate(DISP_OBJ_XTIMEINPUT *disp_obj)
{
  disp_obj->title_text = EMPTY_TEXTID;
  disp_obj->mins_text = EMPTY_TEXTID;
  disp_obj->secs_text = EMPTY_TEXTID;

  disp_obj->temp1 = EMPTY_TEXTID;
  disp_obj->temp2 = EMPTY_TEXTID;
  disp_obj->temp3 = EMPTY_TEXTID;
  disp_obj->temp4 = EMPTY_TEXTID;

  disp_obj->cursor = TIME_MIN;

  disp_obj->time.hour = 0;
  disp_obj->time.min = 0;
  disp_obj->time.sec = 0;

  disp_obj->max_time.hour = 3;
  disp_obj->max_time.min = MAX_MINUTE;
  disp_obj->max_time.sec = MAX_SECOND;

  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main);
  disp_obj->rect_ypos = disp_obj->disp_height >> 2;
  disp_obj->rect_height = disp_obj->disp_height >> 3;

  return 1;
}

void XTimeInput_OnClose(DISP_OBJ_XTIMEINPUT *disp_obj)
{
  DESTROY_TEXTID(disp_obj->title_text);
  DESTROY_TEXTID(disp_obj->mins_text);
  DESTROY_TEXTID(disp_obj->secs_text);

  DESTROY_TEXTID(disp_obj->temp1);
  DESTROY_TEXTID(disp_obj->temp2);
  DESTROY_TEXTID(disp_obj->temp3);
  DESTROY_TEXTID(disp_obj->temp4);
}

void XTimeInput_OnRedraw(DISP_OBJ_XTIMEINPUT *disp_obj, int r1, int r2, int r3)
{
  Update_TimeInput(disp_obj);
  /*--------------------------------------------------------------------------1*/
  DrawTextOnRect(FONT_E_20R,
                 disp_obj->title_text,
                 0,
                 disp_obj->rect_ypos,
                 disp_obj->disp_width,
                 disp_obj->rect_height,
                 TITLE_TEXT_COLOR,
                 TITLE_BACKGROUND_COLOR);
  /*--------------------------------------------------------------------------2*/

  if (disp_obj->time.min < disp_obj->max_time.min)
    disp_obj->temp1 = TextID_CreateIntegerID(disp_obj->time.min + 1);
  else
    disp_obj->temp1 = TextID_CreateIntegerID(0);

  DrawTextOnRect(FONT_E_16R,
                 disp_obj->temp1,
                 0,
                 disp_obj->rect_ypos + (disp_obj->rect_height * 1),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 UNSELECTED_TEXT_COLOR,
                 UNSELECTED_CURSOR_COLOR);

  if (disp_obj->time.sec < disp_obj->max_time.sec)
    disp_obj->temp2 = TextID_CreateIntegerID(disp_obj->time.sec + 1);
  else
    disp_obj->temp2 = TextID_CreateIntegerID(0);

  DrawTextOnRect(FONT_E_16R,
                 disp_obj->temp2,
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_ypos + (disp_obj->rect_height * 1),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 UNSELECTED_TEXT_COLOR,
                 UNSELECTED_CURSOR_COLOR);

  /*--------------------------------------------------------------------------3*/

  disp_obj->mins_text = TextID_CreateIntegerID(disp_obj->time.min);
  DrawTextOnRect(FONT_E_16B,
                 disp_obj->mins_text,
                 0,
                 disp_obj->rect_ypos + (disp_obj->rect_height * 2),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 (disp_obj->cursor == TIME_MIN) ? SELECTED_TEXT_COLOR : UNSELECTED_TEXT_COLOR,
                 (disp_obj->cursor == TIME_MIN) ? SELECTED_CURSOR_COLOR : UNSELECTED_CURSOR_COLOR);

  disp_obj->secs_text = TextID_CreateIntegerID(disp_obj->time.sec);

  DrawTextOnRect(FONT_E_16B,
                 disp_obj->secs_text,
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_ypos + (disp_obj->rect_height * 2),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 (disp_obj->cursor == TIME_SEC) ? SELECTED_TEXT_COLOR : UNSELECTED_TEXT_COLOR,
                 (disp_obj->cursor == TIME_SEC) ? SELECTED_CURSOR_COLOR : UNSELECTED_CURSOR_COLOR);
  /*--------------------------------------------------------------------------4*/

  if (disp_obj->time.min > 0)
    disp_obj->temp3 = TextID_CreateIntegerID(disp_obj->time.min - 1);
  else
    disp_obj->temp3 = TextID_CreateIntegerID(disp_obj->max_time.min);

  DrawTextOnRect(FONT_E_16R,
                 disp_obj->temp3,
                 0,
                 disp_obj->rect_ypos + (disp_obj->rect_height * 3),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 UNSELECTED_TEXT_COLOR,
                 UNSELECTED_CURSOR_COLOR);

  if (disp_obj->time.sec == 0)
    disp_obj->temp4 = TextID_CreateIntegerID(disp_obj->max_time.sec);
  else
    disp_obj->temp4 = TextID_CreateIntegerID(disp_obj->time.sec - 1);

  DrawTextOnRect(FONT_E_16R,
                 disp_obj->temp4,
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_ypos + (disp_obj->rect_height * 3),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 UNSELECTED_TEXT_COLOR,
                 UNSELECTED_CURSOR_COLOR);
  /*--------------------------------------------------------------------------5*/
  DrawTextOnRect(FONT_E_16R,
                 TEXT_MINUTES,
                 0,
                 disp_obj->rect_ypos + (disp_obj->rect_height * 4),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 LINK_COLOR,
                 TITLE_BACKGROUND_COLOR);

  DrawTextOnRect(FONT_E_16R,
                 TEXT_SECONDS,
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_ypos + (disp_obj->rect_height * 4),
                 (disp_obj->disp_width >> 1),
                 disp_obj->rect_height,
                 LINK_COLOR,
                 TITLE_BACKGROUND_COLOR);
}

void XTimeInput_OnLayout(DISP_OBJ_XTIMEINPUT *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, TRANSPARENT_COLOR);
}

void XTimeInput_OnKey(DISP_OBJ_XTIMEINPUT *disp_obj, int key, int count, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    switch (key)
    {
    case KEY_LEFT:
    case KEY_DIGITAL_4:
      if ((--disp_obj->cursor) < TIME_MIN)
        disp_obj->cursor = TIME_SEC;
      break;
    case KEY_RIGHT:
    case KEY_DIGITAL_6:
      if (++disp_obj->cursor > TIME_SEC)
        disp_obj->cursor = TIME_MIN;
      break;
    case KEY_UP:
    case KEY_DIGITAL_2:
      switch (disp_obj->cursor)
      {
      case TIME_MIN:
        if ((++disp_obj->time.min) > disp_obj->max_time.min)
          disp_obj->time.min = 0;
        break;
      case TIME_SEC:
        if ((++disp_obj->time.sec) > disp_obj->max_time.sec)
          disp_obj->time.sec = 0;
        break;
      }
      break;
    case KEY_DOWN:
    case KEY_DIGITAL_8:
      switch (disp_obj->cursor)
      {
      case TIME_MIN:
        if (disp_obj->time.min > 0)
          disp_obj->time.min--;
        else
          disp_obj->time.min = disp_obj->max_time.min;
        break;
      case TIME_SEC:
        if (disp_obj->time.sec > 0)
          disp_obj->time.sec--;
        else
          disp_obj->time.sec = disp_obj->max_time.sec;
        break;
      }
      break;
    }
    DispObject_InvalidateRect(disp_obj, NULL);
  }
}

void XTimeInput_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, GuiName_Time);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_XTIMEINPUT));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)XTimeInput_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)XTimeInput_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)XTimeInput_OnRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)XTimeInput_OnLayout);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)XTimeInput_OnKey);
}

void XTimeInput_destruct(GUI *gui_time)
{
}

void XTimeInput_callback(DISP_OBJ *disp, void *msg, GUI *gui)
{
}

void XTimeInput_SetTitleText(GUI *gui_time, TEXTID title)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);
  disp_obj->title_text = title;
}

void XTimeInput_SetTimeLimit(GUI *gui_time, TIME time)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);
  disp_obj->max_time = time;
  disp_obj->temp = disp_obj->max_time.sec;
}

void XTimeInput_SetTime(GUI *gui_time, TIME max_time)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);
  disp_obj->time = max_time;
}

void XTimeInput_GetTime(GUI *gui_time, TIME *time)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);

  (*time).hour = disp_obj->time.hour;
  (*time).min = disp_obj->time.min;
  (*time).sec = disp_obj->time.sec;
}

int XTimeInput_GetHour(GUI *gui_time)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);
  return disp_obj->time.hour;
}

int XTimeInput_GetMinute(GUI *gui_time)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);
  return disp_obj->time.min;
}

int XTimeInput_GetSecond(GUI *gui_time)
{
  DISP_OBJ_XTIMEINPUT *disp_obj = (DISP_OBJ_XTIMEINPUT *)GUIObject_GetDispObject(gui_time);
  return disp_obj->time.sec;
}

GUI_XTime *CreateXTimeInput(BOOK *book)
{
  GUI_XTime *gui_time = (GUI_XTime *)malloc(sizeof(GUI_XTime));
  if (!GUIObject_Create(gui_time, XTimeInput_destruct, XTimeInput_construct, book, XTimeInput_callback, UIDisplay_Main, sizeof(GUI_XTime)))
  {
    mfree(gui_time);
    return NULL;
  }
  if (book)
    BookObj_AddGUIObject(book, gui_time);

  GUIObject_SetTitleType(gui_time, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_time);

  return gui_time;
}
