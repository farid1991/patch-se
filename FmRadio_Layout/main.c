/*
;Fm Radio Layout Editor
;- Ability to hide/show all items.
;- Ability to change coordinates of each item in realtime.
;- Ability to choose Text color, font, etc.
;- Ability to use color or Theme Image on the background.
;v. 1.2
;(c) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "..\\include\book\FmRadio_Book.h"

#include "data.h"
#include "draw.h"
#include "editor.h"
#include "info.h"
#include "main.h"
#include "setting.h"
#include "Function.h"

__thumb void * malloc (int size)
{
#ifdef DB2020  
  return(memalloc(0,size,1,5,"fm",0));
#elif A2
  return(memalloc(0xFFFFFFFF,size,1,5,"fm",0));
#else
  return(memalloc(size,1,5,"fm",0));
#endif
}

__thumb void mfree (void* mem)
{
#ifdef DB2020  
  if (mem) memfree(0, mem,"fm",0);
#elif A2
  if (mem) memfree(0, mem,"fm",0);
#else
  memfree(mem,"fm",0);
#endif
}

void RegisterImage(IMG* img, wchar_t* path, wchar_t* fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ID = NOIMAGE;
  img->Handle = NOIMAGE;
  
  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->Handle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->Handle, path, fname, 0, &img->ID, &error_code))
      if (error_code) img->Handle = NOIMAGE;
}

void FreeImage(FmRadio_Data* Data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  
  for (int i = 0; i < IMG_COUNT; i++)
    if (Data->Image[i].ID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, Data->Image[i].Handle, 0, 0, Data->Image[i].ID, 1, &error_code);
}

void LoadImage(FmRadio_Data* Data)
{
  const wchar_t* ImageName[] =
  {
    L"BACKGROUND_ICN.png",          //0
    L"RDS_ACTIVE_ICN.png",          //1
    L"RDS_INACTIVE_ICN.png",        //2
    L"AF_ON_ICN.png",               //3
    L"AF_OFF_ICN.png",              //4
    L"MONO_ICN.png",                //5
    L"STEREO_ICN.png",              //6
    L"FREQUENCY_INDICATOR_ICN.png", //7
    L"ARROW_LEFT_IDLE_ICN.png",     //8
    L"ARROW_LEFT_MANUAL_ICN.png",   //9
    L"ARROW_LEFT_AUTOSEEK_ICN.png", //10
    L"ARROW_RIGHT_IDLE_ICN.png",    //11
    L"ARROW_RIGHT_MANUAL_ICN.png",  //12
    L"ARROW_RIGHT_AUTOSEEK_ICN.png",//13
    L"ARROW_UP_IDLE_ICN.png",       //14
    L"ARROW_UP_ACTIVE_ICN.png",     //15
    L"ARROW_DOWN_IDLE_ICN.png",     //16
    L"ARROW_DOWN_ACTIVE_ICN.png",   //17
  };
  
  int i;
  for (i = 0; i < IMG_COUNT; i++)
  {
    if( FSX_IsFileExists(CONFIG_PATH, (wchar_t*)ImageName[i]))
    {
      RegisterImage(&Data->Image[i], CONFIG_PATH, (wchar_t*)ImageName[i]);
    }
    else Data->Image[i].ID = NOIMAGE;
  }
}

extern "C"
int New_FmRadio_Gui_OnCreate(DISP_OBJ* disp_obj)
{
  LoadData();
  
  FmRadio_Data* Data = Get_Data();
  Data->DispObj_FmRadio = (DISP_OBJ_FMRADIO*)disp_obj;
  
  Data->Channel = EMPTY_TEXTID;
  Data->ChannelName = EMPTY_TEXTID;
  Data->Frequency = EMPTY_TEXTID;
  Data->Buffer_Text = EMPTY_TEXTID;
  
  Data->cstep = 1;
  
  LoadImage(Data);
  DispObject_SetRefreshTimer(disp_obj, 1000);
  
  FmRadio_Gui_OnCreate(disp_obj);
  return 1;
}

extern "C"
void New_FmRadio_Gui_OnClose(DISP_OBJ* disp_obj)
{
  FmRadio_Data* Data = Get_Data();
  
  TEXT_FREE(Data->Frequency);
  TEXT_FREE(Data->Channel);
  TEXT_FREE(Data->ChannelName);
  TEXT_FREE(Data->PSName);
  TEXT_FREE(Data->Buffer_Text);
  
  DispObject_KillRefreshTimer(disp_obj);
  
  FreeImage(Data);
  FmRadio_Gui_OnClose(disp_obj);
}

void DrawImage(int x, int y, IMAGEID img)
{
#if defined (DB3200) || defined (DB3210) || defined (DB3350)
  if(img!=NOIMAGE) dll_GC_PutChar(get_DisplayGC(), x, y, 0, 0, img );
#else
  if(img!=NOIMAGE) GC_DrawIcon(x,y,img);
#endif
}
/*
void dump(FmRadio_Book* FmRadio)
{
  int myFile = w_fopen( L"/usb/other/FmRadio.bin", WA_Read+WA_Write+WA_Create+WA_Truncate, 0x1FF, NULL );
    if ( myFile >= NULL )
    {
      w_fwrite( myFile, FmRadio, 0x512 );
      w_fclose( myFile );
    }
}
*/
extern "C"
void New_FmRadio_Gui_OnRedraw(DISP_OBJ* disp_obj, int r1, RECT* rect, int r3)
{
  DISP_OBJ_FMRADIO* disp_fm = (DISP_OBJ_FMRADIO*)disp_obj;
  
  FmRadio_Data* data = Get_Data();
  
  if (data->setting.background.state == TYPE_IMAGE) // Background
  {
    DrawImage(data->setting.background.pos.x,
              data->setting.background.pos.y,
              data->Image[0].ID);
  }
  else if (data->setting.background.state == TYPE_THEME)
  {
    //DispObject_SetThemeImage(disp_obj, 0x1E);
  }
  else if (data->setting.background.state == TYPE_COLOR)
  {
    DispObject_SetLayerColor(disp_obj, data->setting.background_color);
  }
  
  if (data->setting.rds_icn.state) // RDS ICN
  {
    DrawImage(data->setting.rds_icn.pos.x,
              data->setting.rds_icn.pos.y,
              Get_RDS_State(data));
  }
  if (data->setting.af_icn.state) // AF ICN
  {
    DrawImage(data->setting.af_icn.pos.x,
              data->setting.af_icn.pos.y,
              Get_AF_State(data));
  }
  if (data->setting.audio_icn.state) // Audio ICN
  {
    DrawImage(data->setting.audio_icn.pos.x,
              data->setting.audio_icn.pos.y,
              Get_Audio_State(data));
  }
  
  char mode = disp_fm->key_mode;
  FUint16 key_pressed = disp_fm->key_pressed;
  if (data->setting.arrow_left.state) // Left ICN
  {
    DrawImage(data->setting.arrow_left.pos.x,
              data->setting.arrow_left.pos.y,
              data->Image[8].ID );
    if(key_pressed==KEY_LEFT)
    {
      if(disp_fm->key_mode == KBD_SHORT_PRESS)
      {
        DrawImage(data->setting.arrow_left.pos.x,
                  data->setting.arrow_left.pos.y,
                  data->Image[9].ID );
      }
      else if(mode == KBD_LONG_PRESS || mode == KBD_REPEAT)
      {
        DrawImage(data->setting.arrow_left.pos.x,
                  data->setting.arrow_left.pos.y,
                  data->Image[10].ID );
      }
    }
  }
  if (data->setting.arrow_right.state) // Right ICN
  {
    DrawImage(data->setting.arrow_right.pos.x,
              data->setting.arrow_right.pos.y,
              data->Image[11].ID );
    if(disp_fm->key_pressed==KEY_RIGHT)
    {
      if(disp_fm->key_mode == KBD_SHORT_PRESS)
      {
        DrawImage(data->setting.arrow_right.pos.x,
                  data->setting.arrow_right.pos.y,
                  data->Image[12].ID );
      }
      else if(mode == KBD_LONG_PRESS || mode == KBD_REPEAT)
      {
        DrawImage(data->setting.arrow_right.pos.x,
                  data->setting.arrow_right.pos.y,
                  data->Image[13].ID );
      }
    }
  }
  if (data->setting.arrow_up.state) // Up ICN
  {
    DrawImage(data->setting.arrow_up.pos.x,
                data->setting.arrow_up.pos.y,
                data->Image[14].ID );
    if((mode == KBD_SHORT_PRESS || mode == KBD_REPEAT) && key_pressed==KEY_UP)
    {
      DrawImage(data->setting.arrow_up.pos.x,
                data->setting.arrow_up.pos.y,
                data->Image[15].ID );
    }
  }
  if (data->setting.arrow_down.state) // Down ICN
  {
    DrawImage(data->setting.arrow_down.pos.x,
                data->setting.arrow_down.pos.y,
                data->Image[16].ID );
    if((mode == KBD_SHORT_PRESS || mode == KBD_REPEAT) && key_pressed==KEY_DOWN)
    {
      DrawImage(data->setting.arrow_down.pos.x,
                data->setting.arrow_down.pos.y,
                data->Image[17].ID );
    }
  }
  
  if (data->setting.freq_indicator.state) // Freq Indicator
  {
    DrawProgressBar(data,
                    (data->FmRadioBook->CurrentFrequency)-875,
                    (1080-875),
                    data->setting.freq_indicator.progress_rect,
                    data->setting.freq_indicator.progress_bcolor,
                    data->setting.freq_indicator.progress_fcolor);
  }
  
  if (data->setting.frequency.state)     // Current Freq
  {
    data->Frequency = Get_CurrentFrequency(data);
    DrawString_Params(data->Frequency,
                      data->setting.frequency.font,
                      data->setting.frequency.align,
                      data->setting.frequency.coord.x1, 
                      data->setting.frequency.coord.y1, 
                      data->setting.frequency.coord.x2,
                      data->setting.frequency.tcolor,
                      data->setting.frequency.ocolor,
                      data->setting.frequency.overlay );
  }
  
  if (data->setting.channel.state)      // Channel Number
  {
    data->Channel = Get_Channel(data);
    DrawString_Params(data->Channel,
                      data->setting.channel.font,
                      data->setting.channel.align,
                      data->setting.channel.coord.x1, 
                      data->setting.channel.coord.y1, 
                      data->setting.channel.coord.x2,
                      data->setting.channel.tcolor,
                      data->setting.channel.ocolor,
                      data->setting.channel.overlay );
  }
  
  if (data->setting.channel_name.state)   // Chanel Name
  {
    data->ChannelName = Get_ChannelName(data);
    DrawString_Params(data->ChannelName,
                      data->setting.channel_name.font,
                      data->setting.channel_name.align,
                      data->setting.channel_name.coord.x1, 
                      data->setting.channel_name.coord.y1, 
                      data->setting.channel_name.coord.x2,
                      data->setting.channel_name.tcolor,
                      data->setting.channel_name.ocolor,
                      data->setting.channel_name.overlay );
  }
  
  if (data->setting.RDS_data.state)   // PS Name
  {
    data->PSName = Get_GetPSName(data);
    DrawString_Params(data->PSName,
                      data->setting.RDS_data.font,
                      data->setting.RDS_data.align,
                      data->setting.RDS_data.coord.x1, 
                      data->setting.RDS_data.coord.y1, 
                      data->setting.RDS_data.coord.x2,
                      data->setting.RDS_data.tcolor,
                      data->setting.RDS_data.ocolor,
                      data->setting.RDS_data.overlay );
  }
  
  if (data->edit_visual)
  {
    if (data->text)
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      int style = data->temp.font>>8;
      int font_size = data->temp.font&0xFF;
      if (style == 0) snwprintf(data->buf, MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, data->temp.font);
      else if (style == 1) snwprintf(data->buf, MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_B", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
      else if (style == 2) snwprintf(data->buf, MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
      else if (style == 3) snwprintf(data->buf, MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_B_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
      data->Buffer_Text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#else
      data->Buffer_Text = TextID_Create(Font_GetNameByFontId(data->temp.font), ENC_UCS2, TEXTID_ANY_LEN);
#endif
    }
    else
    {
      snwprintf(data->buf, MAXELEMS(data->buf) - 1, L"%d, %d, %d, %d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y2);
      data->Buffer_Text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
    }
    
    //DrawRect(0, 297, 240, 319, clBlack, 0x35FFFFFF);
    DrawRect(0, 247, 240, 272, clBlack, 0x35FFFFFF);
    
    //2a3f6d30
    
    DrawString_Params(data->Buffer_Text,
                      FONT_E_18R,
                      UITextAlignment_Center,
                      1,
                      248, //298,
                      239,
                      clBlack,
                      clEmpty,
                      0);
    TextID_Destroy(data->Buffer_Text);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    if(data->pFont) data->pFont->Release();
#endif
  }
  
  if (data->text)
  {
    DrawRect(data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + (data->temp.font&0xFF), clBlack, 0x35FFFFFF);
  }
}

extern "C"
void New_FmRadio_Gui_OnKey(DISP_OBJ* disp_obj, int key, int unk, int repeat, int mode)
{
  DISP_OBJ_FMRADIO* disp_fm = (DISP_OBJ_FMRADIO*)disp_obj;
  
  disp_fm->key_mode = mode;
  disp_fm->key_pressed = key;
  
  FmRadio_Data* data = Get_Data();
  
  if(data->edit_visual)
  {
    if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
    {
      int scr_w = Display_GetWidth(UIDisplay_Main);
      int scr_h = Display_GetHeight(UIDisplay_Main);
      
      int rect_w = data->temp.x2 - data->temp.x1;
      int rect_h = data->temp.y2 - data->temp.y1;
      
      if (mode == KBD_SHORT_RELEASE) data->cstep = 1;
      else if (mode == KBD_REPEAT && repeat > 5) data->cstep = 5;
      
      switch (key)
      {
      case KEY_UP:
        if (data->text)
        {
          if ((--data->cur_pos) < 0) data->cur_pos = data->total_fonts - 1;
        }
        else data->temp.y2 -= data->cstep;
        break;
      case KEY_DOWN:
        if (data->text)
        {
          if (++data->cur_pos >= data->total_fonts) data->cur_pos = 0;
        }
        else data->temp.y2 += data->cstep;
        break;
      case KEY_LEFT:
        if ((data->temp.x2 -= data->cstep) < data->temp.x1) data->temp.x2 = data->temp.x1;
        break;
      case KEY_RIGHT:
        if ((data->temp.x2 += data->cstep) > scr_w) data->temp.x2 = scr_w;
        break;
      case KEY_DIGITAL_0 + 2:
        if ((data->temp.y1 -= data->cstep) < 0)
        {
          data->temp.y1 = 0;
          data->temp.y2 = rect_h;
        }
        else data->temp.y2 -= data->cstep;
        break;
      case KEY_DIGITAL_0 + 8:
        if (data->text)
        {
          int h_max = scr_h - (data->temp.font&0xFF);
          if ((data->temp.y1 += data->cstep) > h_max) data->temp.y1 = h_max;
        }
        else
        {
          if ((data->temp.y1 += data->cstep) > scr_h)
          {
            data->temp.y1 = scr_h - rect_h;
            data->temp.y2 = scr_w;
          }
          else data->temp.y2 += data->cstep;
        }
        break;
      case KEY_DIGITAL_0 + 4:
        if ((data->temp.x1 -= data->cstep) < 0)
        {
          data->temp.x1 = 0;
          data->temp.x2 = rect_w;
        }
        else data->temp.x2 -= data->cstep;
        break;
      case KEY_DIGITAL_0 + 6:
        if ((data->temp.x2 += data->cstep) > scr_w)
        {
          data->temp.x1 = scr_w - rect_w;
          data->temp.x2 = scr_w;
        }
        else data->temp.x1 += data->cstep;
        break;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      case KEY_DEL:
        if (data->text)
        {
          if ((!data->style_bold) && (!data->style_italic))
          {
            data->style_bold = 1;
          }
          else if ((data->style_bold) && (!data->style_italic))
          {
            data->style_bold = 0;
            data->style_italic = 1;
          }
          else if ((!data->style_bold) && (data->style_italic))
          {
            data->style_bold = 1;
          }
          else if ((data->style_bold) && (data->style_italic))
          {
            data->style_bold = 0;
            data->style_italic = 0;
          }
        }
        break;
#endif
      case KEY_ENTER:
        if (data->text)
        {
          if (++data->temp.overlay == 4) data->temp.overlay = 0;
        }
        break;
      case KEY_DIGITAL_0 + 5:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        SaveData(TRUE, data->element);
        MessageBox_NoImage(EMPTY_TEXTID, TEXT_SAVE, 0, 1500, NULL);
        GUIObject_SoftKeys_SetVisible(data->FmRadioBook->FmRadio_Gui,ACTION_BACK,TRUE);
        FmRadio_SetActiveSoftKeys(data->FmRadioBook,TRUE);
        break;
      case KEY_DIGITAL_0:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        LoadData();
        MessageBox_NoImage(EMPTY_TEXTID, TEXT_CANCEL, 0, 1500, NULL);
        GUIObject_SoftKeys_SetVisible(data->FmRadioBook->FmRadio_Gui,ACTION_BACK,TRUE);
        FmRadio_SetActiveSoftKeys(data->FmRadioBook,TRUE);
        break;
      }
      
      if (data->text)
      {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        data->temp.font = (data->cur_pos + 1) * font_step + (data->style_bold<<8) + (data->style_italic<<9);
#else
        data->temp.font = GetFontDesc()[data->cur_pos].id;
#endif
      }
      
      if (mode == KBD_LONG_RELEASE) data->cstep = 1;
      if (data->edit_visual) SaveData(FALSE, data->element);
      DispObject_InvalidateRect(disp_obj, NULL);
    }
  }
  else
  {
    FmRadio_Gui_OnKey(disp_obj, key, unk, repeat, mode);
  }
}

extern "C"
void New_FmRadio_Gui_OnLayout(DISP_OBJ* disp_obj, void* layoutstruct)
{
  FmRadio_Data* Data = Get_Data();
  if (Data->setting.background.state== TYPE_COLOR)
    DispObject_SetLayerColor(disp_obj, Data->setting.background_color);
  //FmRadio_Gui_OnLayout(disp_obj,layoutstruct);
}

extern "C"
void New_FmRadio_Gui_OnRefresh(DISP_OBJ* disp_obj)
{
  DispObject_InvalidateRect(disp_obj, NULL);
  DispObject_SetRefreshTimer(disp_obj, 1000);
}

extern "C"
int New_FmRadio_Main__PAGE_ENTER_EVENT(void* data, BOOK* book)
{
  FmRadio_Data* Data = Get_Data();
  Data->FmRadioBook = (FmRadio_Book*)book;
  //dump(Data->FmRadioBook);
  pg_FmRadio_Main__PAGE_ENTER_EVENT(data,book);
  return 1;
}

/*
extern "C"
int New_FmRadio_Base__UI_FMRADIO_CREATED_EVENT(void* data, BOOK* book)
{
  pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT(data,book);
  return 1;
}

*/
