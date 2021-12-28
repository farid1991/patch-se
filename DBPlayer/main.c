#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"
#include "..\\include\book\BrowserItemBook.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#endif

#include "Lib.h"
#include "data.h"
#include "draw.h"
#include "editor.h"
#include "info.h"
#include "lang.h"
#include "main.h"
#include "setting.h"
#include "time.h"

void *malloc(int size)
{
  return (memalloc(0xFFFFFFFF, size, 1, 5, "dbp", NULL));
}

void mfree(void *mem)
{
  if (mem)
    memfree(NULL, mem, "dbp", NULL);
}

void FreeIcon(DBP_DATA *data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  for (int i = 0; i < IMG_COUNT; i++)
    if (data->Image[i].ID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, data->Image[i].Handle, 0, 0, data->Image[i].ID, 1, &error_code);

  if (data->IsCoverArt)
    ImageID_Free(data->CoverArtID);
}

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ID = NOIMAGE;
  img->Handle = NOIMAGE;

  if (FSX_IsFileExists(path, fname))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->Handle, &error_code))
      if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->Handle, path, fname, 0, &img->ID, &error_code))
        if (error_code)
          img->Handle = NOIMAGE;
}

void InitIcon(DBP_DATA *Data)
{
  const wchar_t *ImageName[] =
      {
          L"BACKGROUND.png",
          L"NO_COVER.png",
          L"FRAME.png",
          L"PLAY_ICN.png",
          L"PAUSE_ICN.png",
          L"ARTIST_ICN.png",
          L"TITLE_ICN.png",
          L"ALBUM_ICN.png",
          L"SLIDER.png",
          L"MUTE_ICN.png"};

  int i;
  for (i = 0; i < IMG_COUNT; i++)
  {
    if (!fstat(FILE_PATH, ImageName[i], NULL))
      RegisterImage(&Data->Image[i], FILE_PATH, (wchar_t *)ImageName[i]);
    else
      Data->Image[i].ID = NOIMAGE;
  }

  Data->CoverArtID = GetCoverArt(Data);
}

int GetMediaVolume()
{
  char media;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  return (media - 18);
}

int TMMETime_to_Second(TMMETime Time)
{
  return ((Time.Hours * 3600) + (Time.Minutes * 60) + Time.Seconds);
}

void ResetPlayer(DBP_DATA *data)
{
  TMMETime time;
  time.Hours = 0;
  time.Minutes = 0;
  time.Seconds = 0;
  time.MilliSeconds = 0;
  data->pIMMEPlayer->SetTime(&time);
}

int DBPlayer_onCreate(DISP_OBJ_DBP *disp_obj)
{
  DBP_DATA *data = GetData();
  disp_obj->artist = GetTags(data->file.path, data->file.name, ARTIST);
  disp_obj->title = GetTags(data->file.path, data->file.name, TITLE);
  disp_obj->album = GetTags(data->file.path, data->file.name, ALBUM);
  disp_obj->year = GetTags(data->file.path, data->file.name, YEAR);
  disp_obj->genre = GetTags(data->file.path, data->file.name, GENRE);
  disp_obj->ext = GetFileExt(data);
  disp_obj->time_t = GetTotalTime(data);
  disp_obj->time_e = EMPTY_TEXTID;
  disp_obj->time_r = EMPTY_TEXTID;
  disp_obj->buf_text = EMPTY_TEXTID;
  disp_obj->bitrate = GetBitrate(data);
  disp_obj->samplerate = GetSampleRate(data);
  disp_obj->audiooutput = GetAudioOutput(data);
  disp_obj->cstep = 1;
  disp_obj->scr_w = Display_GetWidth(UIDisplay_Main);
  disp_obj->scr_h = Display_GetHeight(UIDisplay_Main);

  DispObject_SetRefreshTimer(disp_obj, 1000);
  return 1;
}

void DBPlayer_onClose(DISP_OBJ_DBP *disp_obj)
{
  TEXTFREE(disp_obj->artist);
  TEXTFREE(disp_obj->title);
  TEXTFREE(disp_obj->album);
  TEXTFREE(disp_obj->year);
  TEXTFREE(disp_obj->genre);
  TEXTFREE(disp_obj->ext);
  TEXTFREE(disp_obj->time_t);
  TEXTFREE(disp_obj->time_e);
  TEXTFREE(disp_obj->time_r);
  TEXTFREE(disp_obj->bitrate);
  TEXTFREE(disp_obj->samplerate);
  TEXTFREE(disp_obj->audiooutput);
  TEXTFREE(disp_obj->buf_text);

  DispObject_KillRefreshTimer(disp_obj);

  DBP_DATA *data = GetData();
  FreeIcon(data);
  DeleteData();
}

void DBPlayer_onRedraw(DISP_OBJ_DBP *disp_obj, int, int, int)
{
  DBP_DATA *data = GetData();
  data->pIMMEPlayer->GetTime(&data->elapsed_time);
  data->full_elapsed_time = TMMETime_to_Second(data->elapsed_time);

  disp_obj->media_volume = GetMediaVolume();

  GC *pGC = get_DisplayGC();

  if (data->setting.background.state == TYPE_IMAGE) // Background
    DrawImage(data->setting.background.pos.x,
              data->setting.background.pos.y,
              data->Image[0].ID);
  else if (data->setting.background.state == TYPE_THEME)
    DispObject_SetThemeImage(disp_obj, 0x1E);
  else if (data->setting.background.state == TYPE_COLOR)
    DispObject_SetLayerColor(disp_obj, data->setting.background_color);

  if (data->setting.cover) // Album Art
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_GC_PutChar(pGC,
#else
    GC_PutChar(pGC,
#endif
                   data->setting.cover_rect.x1,
                   data->setting.cover_rect.y1,
                   data->setting.cover_rect.x2 - data->setting.cover_rect.x1,
                   data->setting.cover_rect.y2 - data->setting.cover_rect.y1,
                   data->CoverArtID);
  }

  if (data->setting.frame.state) // Frame
    DrawImage(data->setting.frame.pos.x,
              data->setting.frame.pos.y,
              data->Image[2].ID);

  if (data->setting.playerstate_icn.state) // PlayerState (Play-Pause)
  {
    if (data->paused)
      DrawImage(data->setting.playerstate_icn.pos.x,
                data->setting.playerstate_icn.pos.y,
                data->Image[3].ID);
    else if (data->mute)
      DrawImage(data->setting.playerstate_icn.pos.x,
                data->setting.playerstate_icn.pos.y,
                data->Image[9].ID);
    else
      DrawImage(data->setting.playerstate_icn.pos.x,
                data->setting.playerstate_icn.pos.y,
                data->Image[4].ID);
  }

  if (data->setting.artist_icn.state) // Artist ICN
    DrawImage(data->setting.artist_icn.pos.x,
              data->setting.artist_icn.pos.y,
              data->Image[5].ID);
  if (data->setting.title_icn.state) // Title ICN
    DrawImage(data->setting.title_icn.pos.x,
              data->setting.title_icn.pos.y,
              data->Image[6].ID);
  if (data->setting.album_icn.state) // Album ICN
    DrawImage(data->setting.album_icn.pos.x,
              data->setting.album_icn.pos.y,
              data->Image[7].ID);

  if (data->setting.time.state) // Time Progressbar
    DrawProgressBar(data,
                    data->full_elapsed_time,
                    data->full_track_time,
                    data->setting.time.progress_rect,
                    data->setting.time.progress_bcolor,
                    data->setting.time.progress_fcolor);

  if (data->setting.volume.state) // Volume Progressbar
    DrawProgressBar(data,
                    disp_obj->media_volume,
                    MAX_MEDIAVOLUME,
                    data->setting.volume.progress_rect,
                    data->setting.volume.progress_bcolor,
                    data->setting.volume.progress_fcolor);

  if (data->setting.artist.state) // Artist TXT
    DrawString_Params(disp_obj->artist,
                      data->setting.artist.font,
                      data->setting.artist.align,
                      data->setting.artist.coord.x1,
                      data->setting.artist.coord.y1,
                      data->setting.artist.coord.x2,
                      data->setting.artist.tcolor,
                      data->setting.artist.ocolor,
                      data->setting.artist.overlay);

  if (data->setting.title.state) // Title TXT
    DrawString_Params(disp_obj->title,
                      data->setting.title.font,
                      data->setting.title.align,
                      data->setting.title.coord.x1,
                      data->setting.title.coord.y1,
                      data->setting.title.coord.x2,
                      data->setting.title.tcolor,
                      data->setting.title.ocolor,
                      data->setting.title.overlay);

  if (data->setting.album.state) // Album TXT
    DrawString_Params(disp_obj->album,
                      data->setting.album.font,
                      data->setting.album.align,
                      data->setting.album.coord.x1,
                      data->setting.album.coord.y1,
                      data->setting.album.coord.x2,
                      data->setting.album.tcolor,
                      data->setting.album.ocolor,
                      data->setting.album.overlay);

  if (data->setting.year.state) // Year TXT
    DrawString_Params(disp_obj->year,
                      data->setting.year.font,
                      data->setting.year.align,
                      data->setting.year.coord.x1,
                      data->setting.year.coord.y1,
                      data->setting.year.coord.x2,
                      data->setting.year.tcolor,
                      data->setting.year.ocolor,
                      data->setting.year.overlay);

  if (data->setting.genre.state) // Genre TXT
    DrawString_Params(disp_obj->genre,
                      data->setting.genre.font,
                      data->setting.genre.align,
                      data->setting.genre.coord.x1,
                      data->setting.genre.coord.y1,
                      data->setting.genre.coord.x2,
                      data->setting.genre.tcolor,
                      data->setting.genre.ocolor,
                      data->setting.genre.overlay);

  if (data->setting.ext.state) // Ext TXT
    DrawString_Params(disp_obj->ext,
                      data->setting.ext.font,
                      data->setting.ext.align,
                      data->setting.ext.coord.x1,
                      data->setting.ext.coord.y1,
                      data->setting.ext.coord.x2,
                      data->setting.ext.tcolor,
                      data->setting.ext.ocolor,
                      data->setting.ext.overlay);

  if (data->setting.time_t.state) // Total time
    DrawString_Params(disp_obj->time_t,
                      data->setting.time_t.font,
                      data->setting.time_t.align,
                      data->setting.time_t.coord.x1,
                      data->setting.time_t.coord.y1,
                      data->setting.time_t.coord.x2,
                      data->setting.time_t.tcolor,
                      data->setting.time_t.ocolor,
                      data->setting.time_t.overlay);

  if (data->setting.time_e.state) // Elapsed time
  {
    TextID_Destroy(disp_obj->time_e);
    disp_obj->time_e = GetElapsedTime(data);
    DrawString_Params(disp_obj->time_e,
                      data->setting.time_e.font,
                      data->setting.time_e.align,
                      data->setting.time_e.coord.x1,
                      data->setting.time_e.coord.y1,
                      data->setting.time_e.coord.x2,
                      data->setting.time_e.tcolor,
                      data->setting.time_e.ocolor,
                      data->setting.time_e.overlay);
  }

  if (data->setting.time_r.state) // Remaining time
  {
    TextID_Destroy(disp_obj->time_r);
    disp_obj->time_r = GetRemainingTime(data);
    DrawString_Params(disp_obj->time_r,
                      data->setting.time_r.font,
                      data->setting.time_r.align,
                      data->setting.time_r.coord.x1,
                      data->setting.time_r.coord.y1,
                      data->setting.time_r.coord.x2,
                      data->setting.time_r.tcolor,
                      data->setting.time_r.ocolor,
                      data->setting.time_r.overlay);
  }

  if (data->setting.bitrate.state) // Bitrate
    DrawString_Params(disp_obj->bitrate,
                      data->setting.bitrate.font,
                      data->setting.bitrate.align,
                      data->setting.bitrate.coord.x1,
                      data->setting.bitrate.coord.y1,
                      data->setting.bitrate.coord.x2,
                      data->setting.bitrate.tcolor,
                      data->setting.bitrate.ocolor,
                      data->setting.bitrate.overlay);

  if (data->setting.samplerate.state) // Samplerate
    DrawString_Params(disp_obj->samplerate,
                      data->setting.samplerate.font,
                      data->setting.samplerate.align,
                      data->setting.samplerate.coord.x1,
                      data->setting.samplerate.coord.y1,
                      data->setting.samplerate.coord.x2,
                      data->setting.samplerate.tcolor,
                      data->setting.samplerate.ocolor,
                      data->setting.samplerate.overlay);

  if (data->setting.audiooutput.state) // Audio output
    DrawString_Params(disp_obj->audiooutput,
                      data->setting.audiooutput.font,
                      data->setting.audiooutput.align,
                      data->setting.audiooutput.coord.x1,
                      data->setting.audiooutput.coord.y1,
                      data->setting.audiooutput.coord.x2,
                      data->setting.audiooutput.tcolor,
                      data->setting.audiooutput.ocolor,
                      data->setting.audiooutput.overlay);

  if (data->edit_visual)
  {
    if (data->text)
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      int font_size = (data->cur_pos + 1) * font_step + (data->style_bold << 8) + (data->style_italic << 9); //data->temp.font&0xFF;
      int style = font_size >> 8;                                                                            //data->temp.font>>8;
      if (style == UIFontStylePlain)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size,
                  font_size);
      }
      else if (style == UIFontStyleBold)
      {
        snwprintf(data->buf, MAXELEMS(data->buf),
                  L"%d, %d, %d, %d font:%d_B",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2, data->temp.y1 + font_size & 0xFF,
                  font_size & 0xFF);
      }
      else if (style == UIFontStyleItalic)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_I",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size & 0xFF,
                  font_size & 0xFF);
      }
      else if (style == UIFontStyleBoldItalic)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_B_I",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + font_size & 0xFF,
                  font_size & 0xFF);
      }
      disp_obj->buf_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#else
      snwprintf(data->buf,
                MAXELEMS(data->buf),
                L"%d, %d, %d, %d, font:%ls",
                data->temp.x1,
                data->temp.y1,
                data->temp.x2,
                data->temp.y2,
                Font_GetNameByFontId(data->temp.font));
      disp_obj->buf_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#endif
    }
    else if (data->icon)
    {
      snwprintf(data->buf,
                MAXELEMS(data->buf),
                L"X:%d, Y:%d",
                data->temp.x1,
                data->temp.y1);
      disp_obj->buf_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
    }
    else if (data->rect)
    {
      snwprintf(data->buf, MAXELEMS(data->buf),
                L"X:%d, Y:%d, W:%d, H:%d",
                data->temp.x1,
                data->temp.y1,
                data->temp.x2 - data->temp.x1,
                data->temp.y2 - data->temp.y1);
      disp_obj->buf_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
    }

    DrawRect(0, disp_obj->scr_h - FONT_E_20R, disp_obj->scr_w, disp_obj->scr_h, clBlack, clHint2);
    DrawString_Params(disp_obj->buf_text,
                      FONT_E_18R,
                      AlignCenter,
                      1,
                      disp_obj->scr_h - FONT_E_20R,
                      disp_obj->scr_w - 1,
                      clBlack,
                      clEmpty,
                      0);
    TEXTFREE(disp_obj->buf_text);
  }

  if (data->text)
  {
    DrawRect(data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + (data->temp.font & 0xFF), clBlack, 0x35FFFFFF);
  }
}

void DBPlayer_OnLayout(DISP_OBJ_DBP *disp_obj, void *layoutstruct)
{
  DBP_DATA *data = GetData();
  if (data->setting.background.state == TYPE_THEME)
    DispObject_SetThemeImage(disp_obj, 0x1E);
  else if (data->setting.background.state == TYPE_COLOR)
    DispObject_SetLayerColor(disp_obj, data->setting.background_color);
}

void DBPlayer_OnRefresh(DISP_OBJ_DBP *disp_obj)
{
  DispObject_InvalidateRect(disp_obj, NULL);
  DispObject_SetRefreshTimer(disp_obj, 1000);
}

void DBPlayer_onKey(DISP_OBJ_DBP *disp_obj, int key, int unk, int repeat, int mode)
{
  DBP_DATA *data = GetData();

  if (!data->edit_visual)
  {
    if (mode == KBD_LONG_PRESS)
    {
      switch (key)
      {
      case KEY_RIGHT:
        data->pIMMEPlayer->StartFastForward();
        break;
      case KEY_LEFT:
        data->pIMMEPlayer->StartRewind();
        break;
      }
    }
    else if (mode == KBD_LONG_RELEASE)
    {
      switch (key)
      {
      case KEY_RIGHT:
        data->pIMMEPlayer->StopFastForward();
        data->pIMMEPlayer->Play(NULL, FALSE);
        break;
      case KEY_LEFT:
        data->pIMMEPlayer->StopRewind();
        data->pIMMEPlayer->Play(NULL, FALSE);
        break;
      }
    }
    else if (mode == KBD_SHORT_PRESS)
    {
      switch (key)
      {
      case KEY_LEFT:
        ResetPlayer(data);
        break;
      case KEY_UP:
        //case KEY_VOL_UP:
        if (disp_obj->media_volume < MAX_MEDIAVOLUME)
        {
          if (data->mute)
          {
            data->pIMMEPlayer->UnMute();
            data->mute = FALSE;
          }
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, ++disp_obj->media_volume + 18);
        }
        break;
      case KEY_DOWN:
        //case KEY_VOL_DOWN:
        if (disp_obj->media_volume)
        {
          if (data->mute)
          {
            data->pIMMEPlayer->UnMute();
            data->mute = FALSE;
          }
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, --disp_obj->media_volume + 18);
        }
        break;
      case KEY_DIEZ:
        if (!data->mute && !data->paused)
        {
          data->pIMMEPlayer->Mute();
          data->mute = TRUE;
        }
        else
        {
          data->pIMMEPlayer->UnMute();
          data->mute = FALSE;
        }
        break;
      }
    }
  }
  else
  {
    if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
    {
      int rect_w = data->temp.x2 - data->temp.x1;
      int rect_h = data->temp.y2 - data->temp.y1;

      if (mode == KBD_SHORT_RELEASE)
        disp_obj->cstep = 1;
      else if (mode == KBD_REPEAT && repeat > 5)
        disp_obj->cstep = 5;

      switch (key)
      {
      case KEY_UP:
        if (data->text)
        {
          if ((--data->cur_pos) < 0)
            data->cur_pos = data->total_fonts - 1;
        }
        else
          data->temp.y2 -= disp_obj->cstep;
        break;
      case KEY_DOWN:
        if (data->text)
        {
          if (++data->cur_pos >= data->total_fonts)
            data->cur_pos = 0;
        }
        else
          data->temp.y2 += disp_obj->cstep;
        break;
      case KEY_LEFT:
        if ((data->temp.x2 -= disp_obj->cstep) < data->temp.x1)
          data->temp.x2 = data->temp.x1;
        break;
      case KEY_RIGHT:
        if ((data->temp.x2 += disp_obj->cstep) > disp_obj->scr_w)
          data->temp.x2 = disp_obj->scr_w;
        break;
      case KEY_DIGITAL_2:
        if ((data->temp.y1 -= disp_obj->cstep) < 0)
        {
          data->temp.y1 = 0;
          data->temp.y2 = rect_h;
        }
        else
          data->temp.y2 -= disp_obj->cstep;
        break;
      case KEY_DIGITAL_8:
        if (data->text)
        {
          int h_max = disp_obj->scr_h - (data->temp.font & 0xFF);
          if ((data->temp.y1 += disp_obj->cstep) > h_max)
            data->temp.y1 = h_max;
        }
        else
        {
          if ((data->temp.y1 += disp_obj->cstep) > disp_obj->scr_h)
          {
            data->temp.y1 = disp_obj->scr_h - rect_h;
            data->temp.y2 = disp_obj->scr_w;
          }
          else
            data->temp.y2 += disp_obj->cstep;
        }
        break;
      case KEY_DIGITAL_4:
        if ((data->temp.x1 -= disp_obj->cstep) < 0)
        {
          data->temp.x1 = 0;
          data->temp.x2 = rect_w;
        }
        else
          data->temp.x2 -= disp_obj->cstep;
        break;
      case KEY_DIGITAL_6:
        if ((data->temp.x2 += disp_obj->cstep) > disp_obj->scr_w)
        {
          data->temp.x1 = disp_obj->scr_w - rect_w;
          data->temp.x2 = disp_obj->scr_w;
        }
        else
          data->temp.x1 += disp_obj->cstep;
        break;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
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
          if (++data->temp.overlay == TEXTOVERLAY_LAST)
            data->temp.overlay = TEXTOVERLAY_NONE;
        }
        break;
      case KEY_DIGITAL_5:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        SaveData(TRUE, data->element);
        CreateMessageBox(EMPTY_TEXTID, TEXT_SAVE, 0, 1500, 0);
        // data->pIMMEPlayer->Play(NULL, FALSE);
        // data->paused = FALSE;
        SetActiveSoft(data, TRUE);
        break;
      case KEY_DIGITAL_0:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        LoadData(data);
        CreateMessageBox(EMPTY_TEXTID, TEXT_CANCEL, 0, 1500, 0);
        // data->pIMMEPlayer->Play(NULL, FALSE);
        // data->paused = FALSE;
        SetActiveSoft(data, TRUE);
        break;
      }

      if (data->text)
      {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        data->temp.font = (data->cur_pos + 1) * font_step + (data->style_bold << 8) + (data->style_italic << 9);
#else
        data->temp.font = GetIdByFontId(data->cur_pos);
#endif
      }

      if (mode == KBD_LONG_RELEASE)
        disp_obj->cstep = 1;
      if (data->edit_visual)
        SaveData(FALSE, data->element);
      DispObject_InvalidateRect(disp_obj, NULL);
    }
  }
}

void DBPlayer_create(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, GuiName_DBPlayer);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_DBP));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)DBPlayer_onCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)DBPlayer_onClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)DBPlayer_onRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)DBPlayer_OnLayout);
  DISP_DESC_SetOnRefresh(desc, (DISP_OBJ_METHOD)DBPlayer_OnRefresh);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)DBPlayer_onKey);
}

void DBPlayer_destroy(GUI *gui)
{
}

void DBPlayer_Pause(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();

  if (!data->paused)
  {
    data->pIMMEPlayer->Pause();
    data->paused = TRUE;
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PAUSE, FALSE);
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PLAY, TRUE);
  }
  else
  {
    data->pIMMEPlayer->Play(NULL, FALSE);
    data->paused = FALSE;
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PAUSE, TRUE);
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PLAY, FALSE);
  }
}

void DBPlayer_Stop(BOOK *book, GUI *gui)
{
  BookObj_ReturnPage(book, PREVIOUS_EVENT);
}

void DBPlayer_Minimise(BOOK *book, GUI *)
{
  BookObj_Hide(book, UIDisplay_Main);
}

#ifndef DB3350
__arm void CallElf(wchar_t *elf_path, wchar_t *file_path, wchar_t *file_name)
{
  asm("STMFD SP!, {LR}");
  asm("MOV R3, #0");
  asm("SVC 0x10D"); // int elfload( const wchar_t* filename, void* param1, void* param2, void* param3 );
  asm("LDMFD SP!, {PC}");
}

void DBPlayer_TagEditor(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();
  wchar_t *path;
  if (data->tagger)
    path = ELF_PATH_UTILS;
  else
    path = ELF_PATH_ZBIN;
  CallElf(path, data->file.path, data->file.name);
}
#endif

void DBPlayer_LongClose(BOOK *book, GUI *gui)
{
  BookObj_ReturnPage(book, CANCEL_EVENT);
}

void DBPlayer_CallBack(DISP_OBJ *, void *msg, GUI *)
{
}

GUI_DBPLAYER *CreateGUI(BOOK *book)
{
  DBP_DATA *data = GetData();

  GUI_DBPLAYER *gui_dbp = (GUI_DBPLAYER *)malloc(sizeof(GUI_DBPLAYER));

  if (!GUIObject_Create(gui_dbp, DBPlayer_destroy, DBPlayer_create, book, DBPlayer_CallBack, UIDisplay_Main, sizeof(GUI_DBPLAYER)))
    mfree(gui_dbp);
  if (book)
    BookObj_AddGUIObject(book, gui_dbp);

  if (data->setting.screen)
    GUIObject_SetStyle(gui_dbp, UI_OverlayStyle_TrueFullScreen);
  else
    GUIObject_SetStyle(gui_dbp, UI_OverlayStyle_Default);

  GUIObject_SetTitleType(gui_dbp, UI_TitleMode_None);

  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_PAUSE, DBPlayer_Pause, 0x78000020);
  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_PLAY, DBPlayer_Pause, 0x78000020);
  GUIObject_SoftKeys_SetVisible(gui_dbp, ACTION_PLAY, FALSE);

  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_STOP, DBPlayer_Stop, TEXT_STOP);
  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_SETTINGS, DBPlayer_Setting, TEXT_SETTINGS);
  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_TIME, DBPlayer_Time, TEXT_TIME);
#ifndef DB3350
  FSTAT _fstat;
  if (fstat(ELF_PATH_UTILS, NULL, &_fstat) == 0)
    data->tagger = 1;
  else if (fstat(ELF_PATH_ZBIN, NULL, &_fstat) == 0)
    data->tagger = 2;

  if (data->tagger)
    GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_TAG, DBPlayer_TagEditor, TextID_Global(ID_TAG_EDITOR));
#endif
  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_MINIMISE, DBPlayer_Minimise, TEXT_MINIMISE);
  GUIObject_SoftKeys_SetAction(gui_dbp, ACTION_LONG_BACK, DBPlayer_LongClose);

  if (!data->setting.soft)
    GUIObject_SoftKeys_Hide(gui_dbp);
#ifndef U10_R7AA071
  GUIObject_SoftKeys_AllowKeylock(gui_dbp, TRUE);
#endif

#ifndef DB3350
  if (data->setting.animation)
    DispObject_SetAnimation(GUIObject_GetDispObject(gui_dbp), 0x60021000);
#endif
  return gui_dbp;
}

#ifdef DB3350
extern "C" int Get_MME_DATA(void *pMMEData, BOOK *book)
{
  BrowserItemBook *itembook = (BrowserItemBook *)book;

  DBP_DATA *data = GetData();
  data->book = book;
  data->pMMEData = (MME_DATA *)pMMEData;
  data->pIMMEPlayer = (IMMEPlayer *)itembook->sub_exec->pIMMEPlayer;

  data->file.path = FILEITEM_GetPath(itembook->sub_exec->file_item);
  data->file.name = FILEITEM_GetFname(itembook->sub_exec->file_item);
  data->file.fullpath = FSX_MakeFullPath(data->file.path, data->file.name);

  data->track_time = data->pMMEData->mediaLength;
  data->full_track_time = TMMETime_to_Second(data->track_time);
  data->SampleRate = data->pMMEData->audioSampleRate;
  data->AudioOutput = data->pMMEData->audioOutput;
  data->fileFormatType = data->pMMEData->fileFormatType;

  pg_Sound_Run__0x17FC(pMMEData, book);
  return 1;
}

extern "C" void CreateInfo(BOOK *book)
{
  BrowserItemBook *itembook = (BrowserItemBook *)book;

  DBP_DATA *data = GetData();
  LoadData(data);
  InitIcon(data);
  itembook->sub_exec->gui = data->gui = CreateGUI(book);
  if (itembook->sub_exec->gui)
  {
    GUIObject_SetBacklightTimeout(itembook->sub_exec->gui, 0xFFFFFFFF);
    GUIObject_SoftKeys_RemoveBackground(itembook->sub_exec->gui);
    GUIObject_Show(itembook->sub_exec->gui);
  }
}
#else
extern "C" void CreateInfo(MME_DATA *pMMEData, SUB_EXECUTE *sub_execute, BOOK *book)
{
  BrowserItemBook *itembook = (BrowserItemBook *)book;

  DBP_DATA *data = GetData();
  data->pIMMEPlayer = (IMMEPlayer *)sub_execute->pIMMEPlayer;

  //TMMETime time = pMMEData->mediaProperties.mediaLength;
  data->track_time = pMMEData->mediaProperties.mediaLength;
  data->full_track_time = TMMETime_to_Second(data->track_time);

  data->SampleRate = pMMEData->mediaProperties.audioSampleRate;
  data->AudioOutput = pMMEData->mediaProperties.audioOutput;

  data->file.path = FILEITEM_GetPath(sub_execute->file_item);
  data->file.name = FILEITEM_GetFname(sub_execute->file_item);
  data->file.fullpath = FSX_MakeFullPath(data->file.path, data->file.name);

  LoadData(data);
  InitIcon(data);
  sub_execute->gui = data->gui = CreateGUI(book);
  if (sub_execute->gui)
  {
    GUIObject_SoftKeys_RemoveBackground(sub_execute->gui);
    GUIObject_Show(sub_execute->gui);
  }
}
#endif
/*extern "C"
int CloseInfo(void* event, BOOK* book)
{
  DBP_DATA* data = GetData();

  if (!data->edit_visual || !data->edit_settings) return pg_Webpage_MHTML_Run__PAGE_EXIT_EVENT(event, book);
  else return 0;
}*/
