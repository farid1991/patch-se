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

int Time_OnCreate(DISP_OBJ_TIME *disp_obj)
{
  DBP_DATA *data = GetData();

  disp_obj->cstep = 1;
  disp_obj->curs = 0;
  disp_obj->buf_text = EMPTY_TEXTID;
  disp_obj->track_time_min = data->track_time.Hours * 60 + data->track_time.Minutes;
  disp_obj->track_time_sec = data->track_time.Seconds;
  disp_obj->track_time_msec =  data->track_time.MilliSeconds;
  disp_obj->elapsed_time = data->elapsed_time;
  disp_obj->buf_min = 0;
  disp_obj->buf_sec = 0;
  return 1;
}

void Time_OnClose(DISP_OBJ_TIME *disp_obj)
{
  TEXTFREE(disp_obj->buf_text);
}

void Time_OnRedraw(DISP_OBJ_TIME *disp_obj, int, int, int)
{
  DrawRect(55, 130, 185, 190, clHint, clHint2);

  snwprintf(disp_obj->buf, MAXELEMS(disp_obj->buf), L"%02d:%02d", disp_obj->buf_min, disp_obj->buf_sec);
  disp_obj->buf_text = TextID_Create(disp_obj->buf, ENC_UCS2, TEXTID_ANY_LEN);

  DrawString_Params(disp_obj->buf_text,
                    FONT_E_40R,
                    AlignCenter,
                    55,
                    135,
                    185,
                    clWhite,
                    clEmpty,
                    0);

  if (!disp_obj->curs)
    DrawRect(60, 186, 115, 188, clWhite, clHint2);
  else
    DrawRect(125, 186, 180, 188, clWhite, clHint2);
}

void Time_OnLayout(DISP_OBJ_TIME *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clEmpty);
}

void Time_OnKey(DISP_OBJ_TIME *disp_obj, int key, int, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (mode == KBD_SHORT_RELEASE)
      disp_obj->cstep = 1;
    else if (mode == KBD_REPEAT && repeat > 5)
      disp_obj->cstep = 3;

    switch (key)
    {
    case KEY_UP:
      if (!disp_obj->curs)
      {
        if ((disp_obj->buf_min += disp_obj->cstep) >= disp_obj->track_time_min)
        {
          disp_obj->buf_min = disp_obj->track_time_min;
          if (disp_obj->buf_sec > disp_obj->track_time_sec)
            disp_obj->buf_sec = disp_obj->track_time_sec;
        }
      }
      else
      {
        if (disp_obj->buf_min >= disp_obj->track_time_min)
        {
          if ((disp_obj->buf_sec += disp_obj->cstep) >= disp_obj->track_time_sec)
            disp_obj->buf_sec = disp_obj->track_time_sec;
        }
        else
        {
          if ((disp_obj->buf_sec += disp_obj->cstep) >= 59)
          {
            disp_obj->buf_min++;
            disp_obj->buf_sec = 0;
          }
        }
      }
      break;

    case KEY_DOWN:
      if (!disp_obj->curs)
      {
        if ((disp_obj->buf_min -= disp_obj->cstep) < 0)
          disp_obj->buf_min = 0;
      }
      else
      {
        if ((disp_obj->buf_sec -= disp_obj->cstep) < 0)
        {
          if (disp_obj->buf_min > 0)
          {
            disp_obj->buf_min--;
            disp_obj->buf_sec = 59;
          }
          else
            disp_obj->buf_sec = 0;
        }
      }
      break;

    case KEY_LEFT:
      if (!disp_obj->curs)
        disp_obj->curs = TIME_SEC;
      else
        disp_obj->curs = TIME_MIN;
      break;

    case KEY_RIGHT:
      if (!disp_obj->curs)
        disp_obj->curs = TIME_SEC;
      else
        disp_obj->curs = TIME_MIN;
      break;
    }

    DispObject_InvalidateRect(disp_obj, NULL);
  }
}

void Time_create(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, GuiName_Time);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_TIME));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Time_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Time_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Time_OnRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)Time_OnLayout);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Time_OnKey);
}

void Time_destroy(GUI *gui)
{
}

void Time_CallBack(DISP_OBJ *, void *msg, GUI *)
{
}

void Time_OnSelect(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();
  DISP_OBJ_TIME *disp_obj = (DISP_OBJ_TIME *)GUIObject_GetDispObject(gui);

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
  GUI *time_input = (GUI *)malloc(sizeof(GUI));
  if (!GUIObject_Create(time_input, Time_destroy, Time_create, book, Time_CallBack, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(time_input);
    return;
  }
  if (book)
    BookObj_AddGUIObject(book, time_input);

  GUIObject_SetStyle(time_input, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(time_input, UI_TitleMode_None);

  GUIObject_SoftKeys_SetAction(time_input, ACTION_SELECT1, Time_OnSelect);
  GUIObject_SoftKeys_SetText(time_input, ACTION_SELECT1, TEXT_TIME);
  GUIObject_SoftKeys_SetAction(time_input, ACTION_BACK, OnBackTime);
  GUIObject_SoftKeys_RemoveBackground(time_input);
  GUIObject_Show(time_input);

  DBP_DATA *data = GetData();
  data->time_input = time_input;
}
