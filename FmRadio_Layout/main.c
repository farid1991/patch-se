#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\Function.h"

#include "..\\include\book\FmRadio_Book.h"

#include "dll.h"
#include "data.h"
#include "draw.h"
#include "editor.h"
#include "info.h"
#include "main.h"
#include "setting.h"

void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(0, size, 1, 5, "fm", 0));
#elif defined(A2)
  return (memalloc(-1, size, 1, 5, "fm", 0));
#else
  return (memalloc(size, 1, 5, "fm", 0));
#endif
}

void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(0, mem, "fm", 0);
#elif defined(A2)
    memfree(0, mem, "fm", 0);
#else
    memfree(mem, "fm", 0);
#endif
}

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ID = NOIMAGE;
  img->Handle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->Handle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->Handle, path, fname, 0, &img->ID, &error_code))
      if (error_code)
        img->Handle = NOIMAGE;
}

void UnRegisterImage(FmRadio_Data *data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  for (int i = 0; i < LAST_ICN; i++)
    if (data->Image[i].ID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, data->Image[i].Handle, 0, 0, data->Image[i].ID, 1, &error_code);
}

void LoadImage(FmRadio_Data *data)
{
  const wchar_t *ImageName[LAST_ICN] =
      {
          L"BACKGROUND_ICN.png",           // 0
          L"RDS_ACTIVE_ICN.png",           // 1
          L"RDS_INACTIVE_ICN.png",         // 2
          L"AF_ON_ICN.png",                // 3
          L"AF_OFF_ICN.png",               // 4
          L"MONO_ICN.png",                 // 5
          L"STEREO_ICN.png",               // 6
          L"FREQUENCY_INDICATOR_ICN.png",  // 7
          L"ARROW_LEFT_IDLE_ICN.png",      // 8
          L"ARROW_LEFT_MANUAL_ICN.png",    // 9
          L"ARROW_LEFT_AUTOSEEK_ICN.png",  // 10
          L"ARROW_RIGHT_IDLE_ICN.png",     // 11
          L"ARROW_RIGHT_MANUAL_ICN.png",   // 12
          L"ARROW_RIGHT_AUTOSEEK_ICN.png", // 13
          L"ARROW_UP_IDLE_ICN.png",        // 14
          L"ARROW_UP_ACTIVE_ICN.png",      // 15
          L"ARROW_DOWN_IDLE_ICN.png",      // 16
          L"ARROW_DOWN_ACTIVE_ICN.png",    // 17
      };

  int i;
  for (i = 0; i < LAST_ICN; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)ImageName[i]))
    {
      RegisterImage(&data->Image[i], CONFIG_PATH, (wchar_t *)ImageName[i]);
    }
    else
      data->Image[i].ID = NOIMAGE;
  }
}

extern "C" int New_FmRadio_Gui_OnCreate(DISP_OBJ_FMRADIO *disp_obj)
{
  FmRadio_Data *data = GetData();
  LoadData(data);

  data->DispObj_FmRadio = disp_obj;

  data->Channel = EMPTY_TEXTID;
  data->ChannelName = EMPTY_TEXTID;
  data->Frequency = EMPTY_TEXTID;
  data->PSName = EMPTY_TEXTID;
  data->Buffer_Text = EMPTY_TEXTID;

  data->scr_w = Display_GetWidth(UIDisplay_Main);
  data->scr_h = Display_GetHeight(UIDisplay_Main);

  data->cstep = 1;

  LoadImage(data);
  FmRadio_Gui_OnCreate(disp_obj);
  return 1;
}

extern "C" void New_FmRadio_Gui_OnClose(DISP_OBJ_FMRADIO *disp_obj)
{
  FmRadio_Data *data = GetData();

  TEXT_FREE(data->Frequency);
  TEXT_FREE(data->Channel);
  TEXT_FREE(data->ChannelName);
  TEXT_FREE(data->PSName);
  TEXT_FREE(data->Buffer_Text);

  UnRegisterImage(data);
  FmRadio_Gui_OnClose(disp_obj);
}

extern "C" void New_FmRadio_Gui_OnRedraw(DISP_OBJ_FMRADIO *disp_obj, int r1, RECT *rect, int r3)
{
  GUI *FMRadio_gui = DispObject_GetGUI(disp_obj);
  FmRadio_Book *fmbook = (FmRadio_Book *)GUIObject_GetBook(FMRadio_gui);

  FmRadio_Data *data = GetData();

  if (data->setting.background.state)
  {
    DrawImage(data->setting.background.pos.x,
              data->setting.background.pos.y,
              data->Image[BACKGROUND_ICN].ID);
  }

  if (data->setting.rds_icn.state) // RDS ICN
  {
    DrawImage(data->setting.rds_icn.pos.x,
              data->setting.rds_icn.pos.y,
              Get_RDS_State(data, fmbook));
  }
  if (data->setting.af_icn.state) // AF ICN
  {
    DrawImage(data->setting.af_icn.pos.x,
              data->setting.af_icn.pos.y,
              Get_AF_State(data, fmbook));
  }
  if (data->setting.audio_icn.state) // Audio ICN
  {
    DrawImage(data->setting.audio_icn.pos.x,
              data->setting.audio_icn.pos.y,
              Get_Audio_State(data, fmbook));
  }

  if (data->setting.arrow_left.state)
  {
    DrawImage(data->setting.arrow_left.pos.x,
              data->setting.arrow_left.pos.y,
              data->Image[ARROW_LEFT_IDLE_ICN].ID);
    if (disp_obj->key_pressed == KEY_LEFT)
    {
      if (disp_obj->key_mode == KBD_SHORT_PRESS)
      {
        DrawImage(data->setting.arrow_left.pos.x,
                  data->setting.arrow_left.pos.y,
                  data->Image[ARROW_LEFT_MANUAL_ICN].ID);
      }
      else if (disp_obj->key_mode == KBD_LONG_PRESS || disp_obj->key_mode == KBD_REPEAT)
      {
        DrawImage(data->setting.arrow_left.pos.x,
                  data->setting.arrow_left.pos.y,
                  data->Image[ARROW_LEFT_AUTOSEEK_ICN].ID);
      }
    }
  }
  if (data->setting.arrow_right.state)
  {
    DrawImage(data->setting.arrow_right.pos.x,
              data->setting.arrow_right.pos.y,
              data->Image[ARROW_RIGHT_IDLE_ICN].ID);
    if (disp_obj->key_pressed == KEY_RIGHT)
    {
      if (disp_obj->key_mode == KBD_SHORT_PRESS)
      {
        DrawImage(data->setting.arrow_right.pos.x,
                  data->setting.arrow_right.pos.y,
                  data->Image[ARROW_RIGHT_MANUAL_ICN].ID);
      }
      else if (disp_obj->key_mode == KBD_LONG_PRESS || disp_obj->key_mode == KBD_REPEAT)
      {
        DrawImage(data->setting.arrow_right.pos.x,
                  data->setting.arrow_right.pos.y,
                  data->Image[ARROW_RIGHT_AUTOSEEK_ICN].ID);
      }
    }
  }
  if (data->setting.arrow_up.state)
  {
    DrawImage(data->setting.arrow_up.pos.x,
              data->setting.arrow_up.pos.y,
              data->Image[ARROW_UP_IDLE_ICN].ID);
    if (disp_obj->key_pressed == KEY_UP)
    {
      if (disp_obj->key_mode == KBD_SHORT_PRESS || disp_obj->key_mode == KBD_REPEAT)
      {
        DrawImage(data->setting.arrow_up.pos.x,
                  data->setting.arrow_up.pos.y,
                  data->Image[ARROW_UP_ACTIVE_ICN].ID);
      }
    }
  }
  if (data->setting.arrow_down.state)
  {
    DrawImage(data->setting.arrow_down.pos.x,
              data->setting.arrow_down.pos.y,
              data->Image[ARROW_DOWN_IDLE_ICN].ID);
    if (disp_obj->key_pressed == KEY_DOWN)
    {
      if (disp_obj->key_mode == KBD_SHORT_PRESS || disp_obj->key_mode == KBD_REPEAT)
      {
        DrawImage(data->setting.arrow_down.pos.x,
                  data->setting.arrow_down.pos.y,
                  data->Image[ARROW_DOWN_ACTIVE_ICN].ID);
      }
    }
  }

  if (data->setting.freq_indicator.state) // Freq Indicator
  {
    DrawProgressBar(data,
                    (fmbook->CurrentFrequency) - 875,
                    (1080 - 875),
                    data->setting.freq_indicator.progress_rect,
                    data->setting.freq_indicator.progress_bcolor,
                    data->setting.freq_indicator.progress_fcolor);
  }

  if (data->setting.frequency.state) // Current Freq
  {
    Get_CurrentFrequency(data, fmbook);
    DrawString_Params(data->Frequency,
                      data->setting.frequency.font,
                      data->setting.frequency.align,
                      data->setting.frequency.coord.x1,
                      data->setting.frequency.coord.y1,
                      data->setting.frequency.coord.x2,
                      data->setting.frequency.text_color,
                      data->setting.frequency.ocolor,
                      data->setting.frequency.overlay);
  }

  if (data->setting.channel.state) // Channel Number
  {
    Get_Channel(data, fmbook);
    DrawString_Params(data->Channel,
                      data->setting.channel.font,
                      data->setting.channel.align,
                      data->setting.channel.coord.x1,
                      data->setting.channel.coord.y1,
                      data->setting.channel.coord.x2,
                      data->setting.channel.text_color,
                      data->setting.channel.ocolor,
                      data->setting.channel.overlay);
  }

  if (data->setting.channel_name.state) // Channel Name
  {
    Get_ChannelName(data, fmbook);
    DrawString_Params(data->ChannelName,
                      data->setting.channel_name.font,
                      data->setting.channel_name.align,
                      data->setting.channel_name.coord.x1,
                      data->setting.channel_name.coord.y1,
                      data->setting.channel_name.coord.x2,
                      data->setting.channel_name.text_color,
                      data->setting.channel_name.ocolor,
                      data->setting.channel_name.overlay);
  }

  if (data->setting.RDS_data.state) // PS Name
  {
    Get_GetPSName(data, fmbook);
    DrawString_Params(data->PSName,
                      data->setting.RDS_data.font,
                      data->setting.RDS_data.align,
                      data->setting.RDS_data.coord.x1,
                      data->setting.RDS_data.coord.y1,
                      data->setting.RDS_data.coord.x2,
                      data->setting.RDS_data.text_color,
                      data->setting.RDS_data.ocolor,
                      data->setting.RDS_data.overlay);
  }

  if (data->edit_visual)
  {
    if (data->text)
    {
#if defined(DB3200) || defined(DB3210)
      int font_size = (data->cur_pos + 1) * font_step + (data->style_bold << 8) + (data->style_italic << 9);
      int style = font_size >> 8;
      if (style == 0)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"%d,%d,%d,%d font:%d_R",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size,
                  font_size);
      }
      else if (style == 1)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"%d,%d,%d,%d font:%d_B",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size & 0xFF,
                  font_size & 0xFF);
      }
      else if (style == 2)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"%d,%d,%d,%d font:%d_I",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size & 0xFF,
                  font_size & 0xFF);
      }
      else if (style == 3)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"%d,%d,%d,%d font:%d_BI",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size & 0xFF,
                  font_size & 0xFF);
      }
      data->Buffer_Text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#else
      snwprintf(data->buf,
                MAXELEMS(data->buf),
                L"%d,%d,%d,%d, font:%ls",
                data->temp.x1,
                data->temp.y1,
                data->temp.x2,
                data->temp.y2,
                Font_GetNameByFontId(data->temp.font));
      data->Buffer_Text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#endif
    }
    else if (data->icon)
    {
      snwprintf(data->buf,
                MAXELEMS(data->buf),
                L"X:%d, Y:%d",
                data->temp.x1,
                data->temp.y1);
      data->Buffer_Text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
    }
    else if (data->rect)
    {
      snwprintf(data->buf, MAXELEMS(data->buf),
                L"X:%d, Y:%d, W:%d, H:%d",
                data->temp.x1,
                data->temp.y1,
                data->temp.x2 - data->temp.x1,
                data->temp.y2 - data->temp.y1);
      data->Buffer_Text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
    }

    DrawRect(0,
             (DISP_MAX_HEIGHT - SOFTKEYS_HEIGHT - STATUSROW_HEIGHT),
             data->scr_w, (DISP_MAX_HEIGHT - STATUSROW_HEIGHT),
             clBlack,
             0x50FFFFFF);
    DrawString_Params(data->Buffer_Text,
                      FONT_E_16R,
                      AlignCenter,
                      1,
                      (DISP_MAX_HEIGHT - SOFTKEYS_HEIGHT - STATUSROW_HEIGHT),
                      (data->scr_w - 1),
                      clBlack,
                      clEmpty,
                      0);
    TEXT_FREE(data->Buffer_Text);
  }

  if (data->text)
  {
    DrawRect(data->temp.x1, data->temp.y1,
             data->temp.x2, data->temp.y1 + (data->temp.font & 0xFF),
             clBlack, 0x35FFFFFF);
  }
}

extern "C" void New_FmRadio_Gui_OnKey(DISP_OBJ_FMRADIO *disp_obj, int key, int count, int repeat, int mode)
{
  FmRadio_Data *data = GetData();

  if (!data->edit_visual)
  {
    FmRadio_Gui_OnKey(disp_obj, key, count, repeat, mode);
  }
  else
  {
    GUI *FMRadio_gui = DispObject_GetGUI(disp_obj);
    FmRadio_Book *fmbook = (FmRadio_Book *)GUIObject_GetBook(FMRadio_gui);

    if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
    {
      int rect_w = data->temp.x2 - data->temp.x1;
      int rect_h = data->temp.y2 - data->temp.y1;

      if (mode == KBD_SHORT_RELEASE)
        data->cstep = 1;
      else if (mode == KBD_REPEAT && repeat > 5)
        data->cstep = 5;

      switch (key)
      {
      case KEY_UP:
        if (data->text)
        {
          if ((--data->cur_pos) < 0)
            data->cur_pos = data->total_fonts - 1;
        }
        else if (data->rect)
        {
          data->temp.y2 -= data->cstep;
        }
        break;
      case KEY_DOWN:
        if (data->text)
        {
          if (++data->cur_pos >= data->total_fonts)
            data->cur_pos = 0;
        }
        else if (data->rect)
        {
          data->temp.y2 += data->cstep;
        }
        break;
      case KEY_LEFT:
        if (data->text || data->rect)
        {
          if ((data->temp.x2 -= data->cstep) < data->temp.x1)
            data->temp.x2 = data->temp.x1;
        }
        break;
      case KEY_RIGHT:
        if (data->text || data->rect)
        {
          if ((data->temp.x2 += data->cstep) > data->scr_w)
            data->temp.x2 = data->scr_w;
        }
        break;
      case KEY_DIGITAL_2:
        if ((data->temp.y1 -= data->cstep) < 0)
        {
          data->temp.y1 = 0;
          data->temp.y2 = rect_h;
        }
        else
          data->temp.y2 -= data->cstep;
        break;
      case KEY_DIGITAL_8:
        if (data->text)
        {
          int h_max = data->scr_h - (data->temp.font & 0xFF);
          if ((data->temp.y1 += data->cstep) > h_max)
            data->temp.y1 = h_max;
        }
        else
        {
          if ((data->temp.y1 += data->cstep) > data->scr_h)
          {
            data->temp.y1 = data->scr_h - rect_h;
            data->temp.y2 = data->scr_w;
          }
          else
            data->temp.y2 += data->cstep;
        }
        break;
      case KEY_DIGITAL_4:
        if ((data->temp.x1 -= data->cstep) < 0)
        {
          data->temp.x1 = 0;
          data->temp.x2 = rect_w;
        }
        else
          data->temp.x2 -= data->cstep;
        break;
      case KEY_DIGITAL_6:
        if ((data->temp.x2 += data->cstep) > data->scr_w)
        {
          data->temp.x1 = data->scr_w - rect_w;
          data->temp.x2 = data->scr_w;
        }
        else
          data->temp.x1 += data->cstep;
        break;
#if defined(DB3200) || defined(DB3210)
      case KEY_DEL:
        if (data->text)
        {
          if ((!data->style_bold) && (!data->style_italic))
          {
            data->style_bold = TRUE;
          }
          else if ((data->style_bold) && (!data->style_italic))
          {
            data->style_bold = FALSE;
            data->style_italic = TRUE;
          }
          else if ((!data->style_bold) && (data->style_italic))
          {
            data->style_bold = TRUE;
          }
          else if ((data->style_bold) && (data->style_italic))
          {
            data->style_bold = FALSE;
            data->style_italic = FALSE;
          }
        }
        break;
#endif
      case KEY_ENTER:
        if (data->text)
        {
          if (++data->temp.overlay == 4)
            data->temp.overlay = 0;
        }
        break;
      case KEY_DIGITAL_5:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        SaveData(TRUE, data->element);
        CreateMessageBox(EMPTY_TEXTID, TEXT_SAVE, 0, 1500, fmbook);
        GUIObject_SoftKeys_SetVisible(fmbook->FmRadio_Gui, ACTION_BACK, TRUE);
        FmRadio_SetActiveSoftKeys(fmbook, TRUE);
        break;
      case KEY_DIGITAL_0:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        LoadData(data);
        CreateMessageBox(EMPTY_TEXTID, TEXT_CANCEL, 0, 1500, fmbook);
        GUIObject_SoftKeys_SetVisible(fmbook->FmRadio_Gui, ACTION_BACK, TRUE);
        FmRadio_SetActiveSoftKeys(fmbook, TRUE);
        break;
      }

      if (data->text)
      {
#if defined(DB3200) || defined(DB3210)
        data->temp.font = (data->cur_pos + 1) * font_step + (data->style_bold << 8) + (data->style_italic << 9);
#else
        FONT_DESC *font_desc = PGetFontDesc;
        data->temp.font = font_desc[data->cur_pos].id;
#endif
      }

      if (mode == KBD_LONG_RELEASE)
        data->cstep = 1;
      if (data->edit_visual)
        SaveData(FALSE, data->element);
      DispObject_InvalidateRect(disp_obj, NULL);
    }
  }
}

#ifdef DB2010
extern "C" void New_FmRadio_Gui_OnConfig(DISP_OBJ *disp_obj)
{
  DispObject_SetTitleType(disp_obj ? disp_obj : NULL, UI_TitleMode_None);
}
#endif
