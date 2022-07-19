#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"
#include "..\\include\book\BrowserItemBook.h"

#ifndef DB3150v1
#include "dll.h"
#endif

#include "Lib.h"
#include "data.h"
#include "draw.h"
#include "editor.h"
#include "info.h"
#include "lang.h"
#include "lyric.h"
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

  for (int i = IMG_BACKGROUND; i < IMG_LAST; i++)
    if (data->Image[i].ID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, data->Image[i].Handle, 0, 0, data->Image[i].ID, 1, &error_code);

  if (data->HasCoverArt)
    ImageID_Free(data->CoverArtID);
}

void RegisterImage(IMG *img, wchar_t *fpath, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ID = NOIMAGE;
  img->Handle = NOIMAGE;

  if (FSX_IsFileExists(fpath, fname))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->Handle, &error_code))
      if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->Handle, fpath, fname, 0, &img->ID, &error_code))
        if (error_code)
          img->Handle = NOIMAGE;
}

void InitIcon(DBP_DATA *Data)
{
  const wchar_t *ImageName[IMG_LAST] =
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

  for (int i = IMG_BACKGROUND; i < IMG_LAST; i++)
  {
    if (FSX_IsFileExists(FILE_PATH, (wchar_t *)ImageName[i]))
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

int TMMETime_to_Seconds(TMMETime Time)
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

void Draw_LyricViewer(DISP_OBJ_DBP *disp_obj)
{
  if (disp_obj->lrclist)
  {
    if (disp_obj->current_offset == WAIT)
    {
      int strr = STR("Please wait...");
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      dll_DrawString(FONT_E_16R, strr, AlignCenter, 0, disp_obj->disp_height >> 1, disp_obj->disp_width, disp_obj->disp_height, clYellow);
#else
      SetFont(FONT_E_16R);
      DrawString(strr, AlignCenter, 0, disp_obj->disp_height >> 1, disp_obj->disp_width, disp_obj->disp_height, 20, 5, clYellow, clYellow);
#endif
      TextID_Destroy(strr);
    }
    else if (disp_obj->current_offset >= READY)
    {
      int stridd[100];
      int pos1 = 0;
      int pos = 0;

      for (int i = disp_obj->current_offset - 1; i >= 0; i--)
      {
        stridd[i] = TextID_Create(disp_obj->lrclist[i].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        int width1 = dll_Disp_GetTextIDWidth(stridd[i], TextID_GetLength(stridd[i]));
#else
        int width1 = Disp_GetTextIDWidth(stridd[i], TextID_GetLength(stridd[i]));
#endif
        if (width1 <= disp_obj->disp_width)
          pos1 -= 20;
        if (width1 > disp_obj->disp_width && width1 <= disp_obj->disp_width * 2)
          pos1 -= 40;
        if (width1 > disp_obj->disp_width * 2 && width1 <= disp_obj->disp_width * 3)
          pos1 -= 60;
        if (width1 > disp_obj->disp_width * 3 && width1 <= disp_obj->disp_width * 4)
          pos1 -= 80;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        dll_DrawString(FONT_E_16R, stridd[i], AlignLeft, 0, 100 + pos1 - disp_obj->offset_len, disp_obj->disp_width, disp_obj->disp_height, clWhite);
#else
        SetFont(FONT_E_16R);
        DrawString(stridd[i], AlignLeft, 0, 100 + pos1 - disp_obj->offset_len, disp_obj->disp_width, disp_obj->disp_height, 20, 5, clWhite, clWhite);
#endif
        TextID_Destroy(stridd[i]);
        if (100 + pos1 - disp_obj->offset_len < -60)
          break;
      }

      if (disp_obj->current_offset >= READY)
      {
        stridd[disp_obj->current_offset] = TextID_Create(disp_obj->lrclist[disp_obj->current_offset].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        dll_DrawString(FONT_E_16B, stridd[disp_obj->current_offset], AlignLeft, 0, 100 - disp_obj->offset_len, disp_obj->disp_width, disp_obj->disp_height, clYellow);
        int width2 = dll_Disp_GetTextIDWidth(stridd[disp_obj->current_offset], TextID_GetLength(stridd[disp_obj->current_offset]));
#else
        SetFont(FONT_E_16B);
        DrawString(stridd[disp_obj->current_offset], AlignLeft, 0, 100 - disp_obj->offset_len, disp_obj->disp_width, disp_obj->disp_height, 20, 5, clYellow, clYellow);
        int width2 = Disp_GetTextIDWidth(stridd[disp_obj->current_offset], TextID_GetLength(stridd[disp_obj->current_offset]));
#endif
        TextID_Destroy(stridd[disp_obj->current_offset]);
        if (width2 <= disp_obj->disp_width)
          pos += 20;
        if (width2 > disp_obj->disp_width && width2 <= disp_obj->disp_width * 2)
          pos += 40;
        if (width2 > disp_obj->disp_width * 2 && width2 <= disp_obj->disp_width * 3)
          pos += 60;
        if (width2 > disp_obj->disp_width * 3 && width2 <= disp_obj->disp_width * 4)
          pos += 80;
      }
      for (int i = (disp_obj->current_offset + 1); i < 100 && i >= 0; i++)
      {
        stridd[i] = TextID_Create(disp_obj->lrclist[i].lrcinfo, ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        dll_DrawString(FONT_E_16R, stridd[i], AlignLeft, 0, 100 + pos - disp_obj->offset_len, disp_obj->disp_width, disp_obj->disp_height, clWhite);
        int width3 = dll_Disp_GetTextIDWidth(stridd[i], TextID_GetLength(stridd[i]));
#else
        SetFont(FONT_E_16R);
        DrawString(stridd[i], AlignLeft, 0, 100 + pos - disp_obj->offset_len, disp_obj->disp_width, disp_obj->disp_height, 20, 5, clWhite, clWhite);
        int width3 = Disp_GetTextIDWidth(stridd[i], TextID_GetLength(stridd[i]));
#endif
        TextID_Destroy(stridd[i]);
        if (100 + pos - disp_obj->offset_len > 280)
          break;
        if (width3 <= disp_obj->disp_width)
          pos += 20;
        if (width3 > disp_obj->disp_width && width3 <= disp_obj->disp_width * 2)
          pos += 40;
        if (width3 > disp_obj->disp_width * 2 && width3 <= disp_obj->disp_width * 3)
          pos += 60;
        if (width3 > disp_obj->disp_width * 3 && width3 <= disp_obj->disp_width * 4)
          pos += 80;
      }
    }
  }
  else
  {
    int strr = TextID_Create(L"No Lyric found", ENC_UCS2, TEXTID_ANY_LEN);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(FONT_E_16R, strr, AlignCenter, 0, disp_obj->disp_height >> 1, disp_obj->disp_width, disp_obj->disp_height, clYellow);
#else
    SetFont(FONT_E_16R);
    DrawString(strr, AlignCenter, 0, disp_obj->disp_height >> 1, disp_obj->disp_width, disp_obj->disp_height, 20, 5, clYellow, clYellow);
#endif
    TextID_Destroy(strr);
  }
}

void DBP_GetLyric(GUI_DBPLAYER *dbp, wchar_t *path, wchar_t *name)
{
  DISP_OBJ_DBP *disp_obj = (DISP_OBJ_DBP *)GUIObject_GetDispObject(dbp);
  GetLyric(disp_obj, path, name);
}

int DBPlayer_onCreate(DISP_OBJ_DBP *disp_obj)
{
  DBP_DATA *data = GetData();
  disp_obj->artist = GetTags(data->path, data->name, ARTIST);
  disp_obj->title = GetTags(data->path, data->name, TITLE);
  disp_obj->album = GetTags(data->path, data->name, ALBUM);
  disp_obj->year = GetTags(data->path, data->name, YEAR);
  disp_obj->genre = GetTags(data->path, data->name, GENRE);
  disp_obj->ext = GetFileExt(data);
  disp_obj->time_f = GetTotalTime(data);
  disp_obj->time_e = EMPTY_TEXTID;
  disp_obj->time_r = EMPTY_TEXTID;
  disp_obj->buf_text = EMPTY_TEXTID;
  disp_obj->bitrate = GetBitrate(data);
  disp_obj->samplerate = GetSampleRate(data);
  disp_obj->audiooutput = GetAudioOutput(data);
  disp_obj->cstep = 1;
  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main);

  disp_obj->lrcbuf = NULL;
  disp_obj->lrclist = NULL;
  disp_obj->TimerLyric = NULL;
  disp_obj->lrc_state = NULL;
  disp_obj->current_offset = NULL;
  disp_obj->total_offset = NULL;
  disp_obj->offset_len = NULL;
  disp_obj->tab = PLAYER_TAB;

  DispObject_SetBacklightMode(disp_obj, UIBacklightMode_On);
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
  TEXTFREE(disp_obj->time_f);
  TEXTFREE(disp_obj->time_e);
  TEXTFREE(disp_obj->time_r);
  TEXTFREE(disp_obj->bitrate);
  TEXTFREE(disp_obj->samplerate);
  TEXTFREE(disp_obj->audiooutput);
  TEXTFREE(disp_obj->buf_text);

  DispObject_SetBacklightMode(disp_obj, UIBacklightMode_Automatic);
  DispObject_KillRefreshTimer(disp_obj);

  if (disp_obj->lrc_state == READ_OK)
  {
    Lyric_FreeData(disp_obj);
    Kill_LyricTimer(disp_obj);
  }

  DBP_DATA *data = GetData();
  FreeIcon(data);
  DeleteData(data);
}

void DBPlayer_onRedraw(DISP_OBJ_DBP *disp_obj, int, int, int)
{
  DBP_DATA *data = GetData();
  data->pIMMEPlayer->GetTime(&data->elapsed_time);

  int currenttime = TMMETime_to_Seconds(data->elapsed_time);
  data->full_elapsed_time = currenttime;

  if (disp_obj->lrc_state == READ_OK && !data->paused && disp_obj->tab == LYRIC_TAB)
  {
    int current_offset = find_current_timer_list(disp_obj, currenttime * 1000);
    if (current_offset <= disp_obj->total_offset && current_offset >= READY)
    {
      disp_obj->current_offset = current_offset;
      Kill_LyricTimer(disp_obj);
      disp_obj->offset_len = 0;
      Start_LyricTimer(disp_obj);
    }
  }

  disp_obj->media_volume = GetMediaVolume();

  if (data->setting.background.state == TYPE_IMAGE)
    DrawImage(data->setting.background.pos.x,
              data->setting.background.pos.y,
              data->Image[IMG_BACKGROUND].ID);
  else if (data->setting.background.state == TYPE_THEME)
    DispObject_SetThemeImage(disp_obj, 0x1E);
  else if (data->setting.background.state == TYPE_COLOR)
    DispObject_SetLayerColor(disp_obj, data->setting.background_color);

  if (data->setting.cover && (data->CoverArtID != NOIMAGE)) // Album Art
  {
#ifdef DB3150v1
    GC_PutChar(get_DisplayGC(),
#else
    dll_GC_PutChar(get_DisplayGC(),
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
              data->Image[IMG_FRAME].ID);

  if (data->setting.playerstate_icn.state) // PlayerState (Play-Pause)
  {
    if (data->paused)
      DrawImage(data->setting.playerstate_icn.pos.x,
                data->setting.playerstate_icn.pos.y,
                data->Image[IMG_PLAY].ID);
    else if (data->mute)
      DrawImage(data->setting.playerstate_icn.pos.x,
                data->setting.playerstate_icn.pos.y,
                data->Image[IMG_MUTE].ID);
    else
      DrawImage(data->setting.playerstate_icn.pos.x,
                data->setting.playerstate_icn.pos.y,
                data->Image[IMG_PAUSE].ID);
  }

  if (disp_obj->tab == LYRIC_TAB && !data->edit_visual)
  {
    Draw_LyricViewer(disp_obj);
  }
  else if (disp_obj->tab == PLAYER_TAB)
  {
    if (data->setting.artist_icn.state)
      DrawImage(data->setting.artist_icn.pos.x,
                data->setting.artist_icn.pos.y,
                data->Image[IMG_ARTIST].ID);

    if (data->setting.title_icn.state)
      DrawImage(data->setting.title_icn.pos.x,
                data->setting.title_icn.pos.y,
                data->Image[IMG_TITLE].ID);

    if (data->setting.album_icn.state)
      DrawImage(data->setting.album_icn.pos.x,
                data->setting.album_icn.pos.y,
                data->Image[IMG_ALBUM].ID);

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
      DrawString_Params(disp_obj->time_f,
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

    if (data->setting.time.state) // Time Progressbar
      DrawProgressBar(data,
                      data->full_elapsed_time,
                      data->full_track_time,
                      data->setting.time.progress_rect,
                      data->setting.time.progress_bcolor,
                      data->setting.time.progress_fcolor);
  }

  if (data->setting.volume.state) // Volume Progressbar
    DrawProgressBar(data,
                    disp_obj->media_volume,
                    MAX_MEDIAVOLUME,
                    data->setting.volume.progress_rect,
                    data->setting.volume.progress_bcolor,
                    data->setting.volume.progress_fcolor);

  if (data->edit_visual)
  {
    if (data->text)
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      int font_size = ((data->cur_pos + 1) * font_step) + (data->style_bold << 8) + (data->style_italic << 9);
      int style = font_size >> 8;
      if (style == UIFontStylePlain)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_R",
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
                  data->temp.x2,
                  data->temp.y1 + FONTHEIGHT(font_size),
                  FONTHEIGHT(font_size));
      }
      else if (style == UIFontStyleItalic)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_I",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + FONTHEIGHT(font_size),
                  FONTHEIGHT(font_size));
      }
      else if (style == UIFontStyleBoldItalic)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf), L"%d, %d, %d, %d font:%d_B_I",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2,
                  data->temp.y1 + FONTHEIGHT(font_size),
                  FONTHEIGHT(font_size));
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

    DrawRect(0, disp_obj->disp_height - FONT_E_20R, disp_obj->disp_width, disp_obj->disp_height, clBlack, clHint2);
    DrawString_Params(disp_obj->buf_text,
                      FONT_E_16R,
                      AlignCenter,
                      1,
                      disp_obj->disp_height - FONT_E_16R,
                      disp_obj->disp_width - 1,
                      clBlack,
                      clEmpty,
                      0);
    TEXTFREE(disp_obj->buf_text);
  }

  if (data->text)
  {
    DrawRect(data->temp.x1, data->temp.y1,
             data->temp.x2, data->temp.y1 + FONTHEIGHT(data->temp.font),
             clBlack, 0x35FFFFFF);
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
    if (mode == KBD_LONG_PRESS && disp_obj->tab == PLAYER_TAB)
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
    else if (mode == KBD_LONG_RELEASE && disp_obj->tab == PLAYER_TAB)
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
    else if (mode == KBD_SHORT_RELEASE)
    {
      switch (key)
      {
      case KEY_LEFT:
        if (disp_obj->tab == PLAYER_TAB)
          ResetPlayer(data);
        else
          disp_obj->tab = PLAYER_TAB;
        break;
      case KEY_RIGHT:
        if (disp_obj->tab == PLAYER_TAB)
          disp_obj->tab = LYRIC_TAB;
        break;
      case KEY_UP:
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
        if ((data->temp.x2 += disp_obj->cstep) > disp_obj->disp_width)
          data->temp.x2 = disp_obj->disp_width;
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
          int h_max = disp_obj->disp_height - FONTHEIGHT(data->temp.font);
          if ((data->temp.y1 += disp_obj->cstep) > h_max)
            data->temp.y1 = h_max;
        }
        else
        {
          if ((data->temp.y1 += disp_obj->cstep) > disp_obj->disp_height)
          {
            data->temp.y1 = disp_obj->disp_height - rect_h;
            data->temp.y2 = disp_obj->disp_width;
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
        if ((data->temp.x2 += disp_obj->cstep) > disp_obj->disp_width)
        {
          data->temp.x1 = disp_obj->disp_width - rect_w;
          data->temp.x2 = disp_obj->disp_width;
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
        CreateMessageBox(EMPTY_TEXTID, TEXT_SAVE, 0, 1500, NULL);
        // data->pIMMEPlayer->Play(NULL, FALSE);
        // data->paused = FALSE;
        SetActiveSoft(data, TRUE);
        break;
      case KEY_DIGITAL_0:
        data->edit_visual = FALSE;
        data->text = FALSE;
        data->rect = FALSE;
        LoadData(data);
        CreateMessageBox(EMPTY_TEXTID, TEXT_CANCEL, 0, 1500, NULL);
        // data->pIMMEPlayer->Play(NULL, FALSE);
        // data->paused = FALSE;
        SetActiveSoft(data, TRUE);
        break;
      }

      if (data->text)
      {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        data->temp.font = ((data->cur_pos + 1) * font_step) + (data->style_bold << 8) + (data->style_italic << 9);
#else
        FONT_DESC *font_desc = PGetFontDesc;
        data->temp.font = font_desc[data->cur_pos].id;
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

void DBPlayer_onDescCreate(DISP_DESC *desc)
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

void DBPlayer_onDestroy(GUI *gui)
{
}

void DBPlayer_Pause(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();
  DISP_OBJ_DBP *dbp = (DISP_OBJ_DBP *)GUIObject_GetDispObject(gui);

  if (!data->paused)
  {
    data->pIMMEPlayer->Pause();
    data->paused = TRUE;
    Kill_LyricTimer(dbp);
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PAUSE, FALSE);
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PLAY, TRUE);
  }
  else
  {
    data->pIMMEPlayer->Play(NULL, FALSE);
    data->paused = FALSE;
    Start_LyricTimer(dbp);
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
__arm void CallElf(wchar_t *elf_path, wchar_t *fpath, wchar_t *fname)
{
  elfload(elf_path, fpath, fname, NULL);
}

void DBPlayer_TagEditor(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();
  CallElf(ELF_PATH_ZBIN, data->path, data->name);
}
#endif

void DBPlayer_LongClose(BOOK *book, GUI *gui)
{
  BookObj_ReturnPage(book, CANCEL_EVENT);
}

void DBPlayer_onCallBack(DISP_OBJ *, void *msg, GUI *)
{
}

GUI_DBPLAYER *CreateGUI(BOOK *book)
{
  DBP_DATA *data = GetData();

  GUI_DBPLAYER *gui_dbp = (GUI_DBPLAYER *)malloc(sizeof(GUI_DBPLAYER));

  if (!GUIObject_Create(gui_dbp, DBPlayer_onDestroy, DBPlayer_onDescCreate, book, DBPlayer_onCallBack, UIDisplay_Main, sizeof(GUI_DBPLAYER)))
  {
    mfree(gui_dbp);
    return NULL;
  }

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
  if (data->tagger)
    GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_TAG, DBPlayer_TagEditor, TextID_Global(ID_TAG_EDITOR));
#endif
  GUIObject_SoftKeys_SetActionAndText(gui_dbp, ACTION_MINIMISE, DBPlayer_Minimise, TEXT_MINIMISE);
  GUIObject_SoftKeys_SetAction(gui_dbp, ACTION_LONG_BACK, DBPlayer_LongClose);

  if (!data->setting.soft)
    GUIObject_SoftKeys_Hide(gui_dbp);
    // #ifndef U10_R7AA071
    //   GUIObject_SoftKeys_AllowKeylock(gui_dbp, TRUE);
    // #endif

#ifdef DB3350
  GUIObject_SetAnimationApp(gui_dbp, L"FromStatusrow");
#else
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

  data->path = FILEITEM_GetPath(itembook->sub_exec->file_item);
  data->name = FILEITEM_GetFname(itembook->sub_exec->file_item);
  data->fullpath = FSX_MakeFullPath(data->path, data->name);

  data->track_time = data->pMMEData->mediaLength;
  data->full_track_time = TMMETime_to_Seconds(data->track_time);
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
    DBP_GetLyric(itembook->sub_exec->gui, data->path, data->name);
    GUIObject_SoftKeys_RemoveBackground(itembook->sub_exec->gui);
    GUIObject_Show(itembook->sub_exec->gui);
  }
}
#else
extern "C" void CreateInfo(MME_DATA *pMMEData, BOOK *book)
{
  BrowserItemBook *itembook = (BrowserItemBook *)book;

  DBP_DATA *data = GetData();
  data->pIMMEPlayer = (IMMEPlayer *)itembook->sub_exec->pIMMEPlayer;

  data->track_time = pMMEData->mediaLength;
  data->full_track_time = TMMETime_to_Seconds(data->track_time);

  data->SampleRate = pMMEData->audioSampleRate;
  data->AudioOutput = pMMEData->audioOutput;
  data->fileFormatType = pMMEData->fileFormatType;

  data->path = FILEITEM_GetPath(itembook->sub_exec->file_item);
  data->name = FILEITEM_GetFname(itembook->sub_exec->file_item);
  data->fullpath = FSX_MakeFullPath(data->path, data->name);

  if (FSX_IsFileExists(ELF_PATH, L"MusicTagger.elf"))
    data->tagger = TRUE;

  LoadData(data);
  InitIcon(data);
  itembook->sub_exec->gui = data->gui = CreateGUI(itembook);
  if (itembook->sub_exec->gui)
  {
    DBP_GetLyric(itembook->sub_exec->gui, data->path, data->name);
    GUIObject_SoftKeys_RemoveBackground(itembook->sub_exec->gui);
    GUIObject_Show(itembook->sub_exec->gui);
  }
}
#endif
