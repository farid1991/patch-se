#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\Color.h"

#include "..\\dll.h"

#include "..\\Draw.h"
#include "..\\main.h"

#include "SelectFont.h"
#include "TimeInput.h"

void Adjust_TimeInput(DISP_OBJ_XTIMEINPUT *disp_obj)
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

void XTimeInput_OnRedraw(DISP_OBJ_XTIMEINPUT *disp_obj, int, int, int)
{
  Adjust_TimeInput(disp_obj);
  /*--------------------------------------------------------------------------*/
  DrawString_onRect(FONT_E_24R,
                    disp_obj->title_text,
                    clAlpha,
                    0, 70, disp_obj->disp_width, 36,
                    clBlue2Dark);
  /*--------------------------------------------------------------------------*/

  if (disp_obj->time.min < disp_obj->max_time.min)
    disp_obj->temp1 = TextID_CreateIntegerID(disp_obj->time.min + 1);
  else
    disp_obj->temp1 = TextID_CreateIntegerID(0);

  DrawString_onRect(FONT_E_20R,
                    disp_obj->temp1,
                    clZeta,
                    0, 106, 120, 40,
                    clAlpha);

  if (disp_obj->time.sec < disp_obj->max_time.sec)
    disp_obj->temp2 = TextID_CreateIntegerID(disp_obj->time.sec + 1);
  else
    disp_obj->temp2 = TextID_CreateIntegerID(0);

  DrawString_onRect(FONT_E_20R,
                    disp_obj->temp2,
                    clZeta,
                    120, 106, 120, 40,
                    clAlpha);

  /*--------------------------------------------------------------------------*/

  disp_obj->mins_text = TextID_CreateIntegerID(disp_obj->time.min);
  DrawString_onRect(FONT_E_30R,
                    disp_obj->mins_text,
                    (disp_obj->cursor == TIME_MIN) ? clAlpha : clBlueMidDark,
                    0, 146, 120, 50,
                    (disp_obj->cursor == TIME_MIN) ? clBlueMidDark : clAlpha);

  disp_obj->secs_text = TextID_CreateIntegerID(disp_obj->time.sec);

  DrawString_onRect(FONT_E_30R,
                    disp_obj->secs_text,
                    (disp_obj->cursor == TIME_SEC) ? clAlpha : clBlueMidDark,
                    120, 146, 120, 50,
                    (disp_obj->cursor == TIME_SEC) ? clBlueMidDark : clAlpha);
  /*--------------------------------------------------------------------------*/

  if (disp_obj->time.min > 0)
    disp_obj->temp3 = TextID_CreateIntegerID(disp_obj->time.min - 1);
  else
    disp_obj->temp3 = TextID_CreateIntegerID(disp_obj->max_time.min);

  DrawString_onRect(FONT_E_20R,
                    disp_obj->temp3,
                    clZeta,
                    0, 196, 120, 40,
                    clAlpha);

  if (disp_obj->time.sec == 0)
    disp_obj->temp4 = TextID_CreateIntegerID(disp_obj->max_time.sec);
  else
    disp_obj->temp4 = TextID_CreateIntegerID(disp_obj->time.sec - 1);

  DrawString_onRect(FONT_E_20R,
                    disp_obj->temp4,
                    clZeta,
                    120, 196, 120, 40,
                    clAlpha);
  /*--------------------------------------------------------------------------*/
  DrawString_onRect(FONT_E_18R,
                    TEXT_MINUTES,
                    clZeta,
                    0, 236, 120, 30,
                    clAlpha);

  DrawString_onRect(FONT_E_18R,
                    TEXT_SECONDS,
                    clZeta,
                    120, 236, 120, 30,
                    clAlpha);
}

void XTimeInput_OnLayout(DISP_OBJ_XTIMEINPUT *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clEmpty);
}

void XTimeInput_OnKey(DISP_OBJ_XTIMEINPUT *disp_obj, int key, int, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (key == KEY_LEFT || key == KEY_DIGITAL_4)
    {
      if ((--disp_obj->cursor) < 0)
        disp_obj->cursor = 1;
    }
    else if (key == KEY_RIGHT || key == KEY_DIGITAL_6)
    {
      if (++disp_obj->cursor > 1)
        disp_obj->cursor = 0;
    }
    else if (key == KEY_UP || key == KEY_DIGITAL_2)
    {
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
    }
    else if (key == KEY_DOWN || key == KEY_DIGITAL_8)
    {
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
    }
    InvalidateRect(disp_obj);
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

void XTimeInput_callback(DISP_OBJ* disp, void* msg, GUI* gui)
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

  return (gui_time);
}
