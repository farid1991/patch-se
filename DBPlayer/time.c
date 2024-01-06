#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
#include "time.h"
#include "data.h"
#include "draw.h"
#include "lang.h"
#include "main.h"

void IncreaseTime(DISP_OBJ_TIMEINPUT *disp_obj, int cursor, int step)
{
  int *buffer = (cursor == TIME_MIN) ? &disp_obj->buf_min : &disp_obj->buf_sec;
  int *track_value = (cursor == TIME_MIN) ? &disp_obj->track_time_min : &disp_obj->track_time_sec;

  switch (cursor)
  {
  case TIME_MIN:
    *buffer += step;

    // Cap buf_sec at track_min
    if ((*buffer == *track_value) && (disp_obj->buf_sec > disp_obj->track_time_sec))
    {
      disp_obj->buf_sec = disp_obj->track_time_sec;
    }

    // Cap buf_min at track_min
    if (*buffer > *track_value)
    {
      *buffer = *track_value;
    }
    break;
  case TIME_SEC:
    int max_seconds = (disp_obj->buf_min < disp_obj->track_time_min) ? 59 : disp_obj->track_time_sec;
    *buffer += step;

    // Cap buf_sec at 59 when buf_min is less than track_min
    if (*buffer > max_seconds)
    {
      *buffer = (disp_obj->buf_min < disp_obj->track_time_min) ? 59 : max_seconds;
    }

    // If buf_min equals track_min and buf_sec exceeds track_sec, cap buf_sec at track_sec
    if (disp_obj->buf_min == disp_obj->track_time_min && *buffer > disp_obj->track_time_sec)
    {
      *buffer = disp_obj->track_time_sec;
    }
    break;
  }
}

void DecreaseTime(DISP_OBJ_TIMEINPUT *disp_obj, int cursor, int step)
{
  int *buffer = (cursor == TIME_MIN) ? &disp_obj->buf_min : &disp_obj->buf_sec;

  if ((*buffer -= step) < 0)
  {
    *buffer = 0;

    if (cursor == TIME_SEC && disp_obj->buf_min > 0)
    {
      disp_obj->buf_min--;
      disp_obj->buf_sec = 59;
    }
  }
}

void ToggleCursorPosition(DISP_OBJ_TIMEINPUT *disp_obj)
{
  disp_obj->cursor = (disp_obj->cursor == TIME_MIN) ? TIME_SEC : TIME_MIN;
}

int Time_OnCreate(DISP_OBJ_TIMEINPUT *disp_obj)
{
  disp_obj->cstep = 1;
  disp_obj->cursor = TIME_MIN;
  disp_obj->text_id = EMPTY_TEXTID;
  disp_obj->track_time_min = 0;
  disp_obj->track_time_sec = 0;
  disp_obj->track_time_msec = 0;
  disp_obj->buf_min = 0;
  disp_obj->buf_sec = 0;
  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main);
  return 1;
}

void Time_OnClose(DISP_OBJ_TIMEINPUT *disp_obj)
{
  TEXTFREE(disp_obj->text_id);
}

void Time_OnRedraw(DISP_OBJ_TIMEINPUT *disp_obj, int r1, int r2, int r3)
{
  int font = FONT_E_40R;
  int rext_x1 = disp_obj->disp_width >> 2;
  int rext_x2 = disp_obj->disp_width - rext_x1;
  int rect_w = rext_x2 - rext_x1;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int font_h = FONTHEIGHT(font);
#else
  font = SetFont(font);
  int font_h = GetImageHeight(' ');
#endif
  int rect_h = font_h + (padding << 1);
  int rext_y1 = disp_obj->disp_height >> 2;
  int rext_y2 = rext_y1 + rect_h;

  // Draw Background Rectangle
  DrawRect(rext_x1, rext_y1, rext_x2, rext_y2, clWhite, clBlack);

  // Format and Draw Time
  snwprintf(disp_obj->buf, MAXELEMS(disp_obj->buf), L"%02d:%02d", disp_obj->buf_min, disp_obj->buf_sec);
  disp_obj->text_id = TextID_Create(disp_obj->buf, ENC_UCS2, TEXTID_ANY_LEN);
  DrawTextEx(font,
             disp_obj->text_id,
             AlignCenter,
             rext_x1,
             rext_y1 + padding,
             rext_x2,
             rext_y2 - padding,
             clWhite);

  // Highlight the Selected Cursor
  int highlight_x1 = (disp_obj->cursor == TIME_MIN) ? rext_x1 : (rext_x1 + (rect_w >> 1));
  int highlight_x2 = highlight_x1 + (rect_w >> 1);
  DrawRect(highlight_x1,
           rext_y2,
           highlight_x2,
           rext_y2 + cursor_height,
           clBlack,
           clWhite);
}

void Time_OnLayout(DISP_OBJ_TIMEINPUT *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clEmpty);
}

void Time_OnKey(DISP_OBJ_TIMEINPUT *disp_obj, int key, int count, int repeat, int mode)
{
  if (mode != KBD_SHORT_RELEASE && mode != KBD_REPEAT)
    return;

  if (mode == KBD_SHORT_RELEASE)
    disp_obj->cstep = 1;
  else if (repeat > 5)
    disp_obj->cstep = 3;

  switch (key)
  {
  case KEY_UP:
    IncreaseTime(disp_obj, disp_obj->cursor, disp_obj->cstep);
    break;

  case KEY_DOWN:
    DecreaseTime(disp_obj, disp_obj->cursor, disp_obj->cstep);
    break;

  case KEY_LEFT:
  case KEY_RIGHT:
    ToggleCursorPosition(disp_obj);
    break;
  }

  DispObject_InvalidateRect(disp_obj, NULL);
}

void Time_create(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, GuiName_Time);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_TIMEINPUT));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Time_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Time_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Time_OnRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)Time_OnLayout);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Time_OnKey);
}

void Time_destroy(GUI_TIMEINPUT *gui)
{
}

void Time_CallBack(DISP_OBJ *, void *msg, GUI *)
{
}

void SetTimeInput(DBP_DATA *data, GUI_TIMEINPUT *gui)
{
  DISP_OBJ_TIMEINPUT *disp_obj = (DISP_OBJ_TIMEINPUT *)GUIObject_GetDispObject(gui);

  disp_obj->track_time_min = data->track_time.Hours * 60 + data->track_time.Minutes;
  disp_obj->track_time_sec = data->track_time.Seconds;
  disp_obj->track_time_msec = data->track_time.MilliSeconds;
}

void Time_OnSelect(BOOK *book, GUI *gui)
{
  DISP_OBJ_TIMEINPUT *disp_obj = (DISP_OBJ_TIMEINPUT *)GUIObject_GetDispObject(gui);

  DBP_DATA *data = GetData();

  TMMETime Time;
  Time.Hours = 0;
  Time.Minutes = disp_obj->buf_min;
  Time.Seconds = disp_obj->buf_sec;
  Time.MilliSeconds = disp_obj->track_time_msec;
  data->pIMMEPlayer->SetTime(&Time);
  FREE_GUI(data->time_input);
}

void OnBackTime(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();
  FREE_GUI(data->time_input);
}

void DBPlayer_Time(BOOK *book, GUI *gui)
{
  GUI_TIMEINPUT *time_input = (GUI_TIMEINPUT *)malloc(sizeof(GUI_TIMEINPUT));
  if (!GUIObject_Create(time_input, Time_destroy, Time_create, book, Time_CallBack, UIDisplay_Main, sizeof(GUI_TIMEINPUT)))
  {
    mfree(time_input);
    return;
  }
  if (book)
    BookObj_AddGUIObject(book, time_input);

  DBP_DATA *data = GetData();
  SetTimeInput(data, time_input);

  GUIObject_SetStyle(time_input, data->setting.screen ? UI_OverlayStyle_TrueFullScreen : UI_OverlayStyle_Default);
  GUIObject_SetTitleType(time_input, UI_TitleMode_None);

  GUIObject_SoftKeys_SetText(time_input, ACTION_SELECT1, TEXT_TIME);
  GUIObject_SoftKeys_SetAction(time_input, ACTION_SELECT1, Time_OnSelect);
  GUIObject_SoftKeys_SetAction(time_input, ACTION_BACK, OnBackTime);
  GUIObject_SoftKeys_SetAction(time_input, ACTION_LONG_BACK, OnBackTime);
  GUIObject_SoftKeys_RemoveBackground(time_input);
  GUIObject_Show(time_input);

  data->time_input = time_input;
}
