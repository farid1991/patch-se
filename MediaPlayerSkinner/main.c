#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "data.h"
#include "Draw.h"
#include "main.h"
#include "skinselect.h"

void *malloc(int size)
{
  return memalloc(NULL, size, 1, 5, "MP", NULL);
}

void mfree(void *mem)
{
  if (mem)
    memfree(NULL, mem, "MP", NULL);
}

wchar_t *getSampleRate(int index)
{
  switch (index)
  {
  case 8000:
    return L"8.0KHz";
  case 11025:
    return L"11.02KHz";
  case 16000:
    return L"16.0KHz";
  case 22050:
    return L"22.05KHz";
  case 24000:
    return L"24.0KHz";
  case 32000:
    return L"32.0KHz";
  case 44100:
    return L"44.1KHz";
  case 48000:
    return L"48.0KHz";
  }
  return NULL;
}

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error;

  img->id = NOIMAGE;
  img->handle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->handle, &error))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->handle, path, fname, 0, &img->id, &error))
      if (error)
        img->handle = NOIMAGE;
}

int UnLoadSkinImage(ADVPLAYER_DATA *data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error;
  for (int i = 0; i < MP_LAST_IMG; i++)
  {
    REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, data->skin_image[i].handle, NULL, NULL, data->skin_image[i].id, 1, &error);
  }
  return 1;
}

void LoadSkinImage(ADVPLAYER_DATA *data, wchar_t *skinpath)
{
  const wchar_t *icons[MP_LAST_IMG] =
      {
          L"MP_BACKGROUND_ICN.png",
          L"MP_COVERART_ICN.png",
          L"MP_REFLECT_ICN.png",
          L"MP_OVERLAY_ICN.png",
          L"MP_ARTIST_ICN.png",
          L"MP_TITLE_ICN.png",
          L"MP_ALBUM_ICN.png",
          L"MP_PLAY_ICN.png",
          L"MP_PAUSE_ICN.png",
          L"MP_NEXT_ICN.png",
          L"MP_PREVIOUS_ICN.png",
          L"MP_FF_ICN.png",
          L"MP_RW_ICN.png",
          L"MP_MODE_RANDOM_ICN.png",
          L"MP_MODE_REPEAT_ICN.png",
          L"MP_EQ_BASS_ICN.png",
          L"MP_EQ_MEGABASS_ICN.png",
          L"MP_EQ_MANUAL_ICN.png",
          L"MP_EQ_NORMAL_ICN.png",
          L"MP_EQ_TREBLEBOOST_ICN.png",
          L"MP_EQ_VOICE_ICN.png",
          L"MP_PROGRESS_INDICATOR_ICN.png",
          L"WALKMAN_ICN.png"};

  for (int i = 0; i < MP_LAST_IMG; i++)
  {
    if (FSX_IsFileExists(skinpath, (wchar_t *)icons[i]))
    {
      RegisterImage(&data->skin_image[i], skinpath, (wchar_t *)icons[i]);
    }
    else
    {
      data->skin_image[i].handle = NOIMAGE;
      data->skin_image[i].id = NOIMAGE;
    }
  }
}

extern "C" int New_MediaPlayer_Audio_OnCreate(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();

  wstrcpy(data->SkinPath, GetCurrentSkinPath());
  data->Skin = (SKIN_DATA *)malloc(sizeof(SKIN_DATA));
  ReadConfig(data->Skin, data->SkinPath);

  data->MediaPlayer_Audio = disp_obj;
  data->fullscreen = data->Skin->fullscreen;

  if (UnLoadSkinImage(data))
    LoadSkinImage(data, data->SkinPath);

  int ret = MediaPlayer_Audio_OnCreate(disp_obj);
  return ret;
}

extern "C" void New_MediaPlayer_Audio_OnClose(DISP_OBJ *disp_obj)
{
  MediaPlayer_Audio_OnClose(disp_obj);

  ADVPLAYER_DATA *data = GetData();
  UnLoadSkinImage(data);
  IMAGE_FREE(data->CoverArt);
  Free_SkinData(data->Skin);
  TrackDesc_Free(data->CurrentTrack);
  FreeData(data);
}

extern "C" void New_MediaPlayer_Audio_OnRedraw(DISP_OBJ *disp_obj)
{
}

extern "C" void New_MediaPlayer_Audio_SetStyle(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();
  if (data->Skin->fullscreen)
  {
    DispObject_SetStyle(disp_obj, UI_OverlayStyle_TrueFullScreen);
  }
  else
  {
    DispObject_SetStyle(disp_obj, UI_OverlayStyle_Default);
  }
}

extern "C" int New_MediaPlayer_NowPlaying_OnCreate(DISP_OBJ *dobj)
{
  DISP_OBJ_NOWPLAYING *disp_obj = (DISP_OBJ_NOWPLAYING *)dobj;

  int ret = MediaPlayer_NowPlaying_OnCreate(disp_obj);

  ADVPLAYER_DATA *data = GetData();
  data->text_id = EMPTY_TEXTID;
  data->MediaPlayer_NowPlaying = disp_obj;

  return ret;
}

extern "C" void New_MediaPlayer_NowPlaying_OnClose(DISP_OBJ *disp_obj)
{
  MediaPlayer_NowPlaying_OnClose(disp_obj);

  ADVPLAYER_DATA *data = GetData();
  TEXT_FREE(data->text_id);
}

extern "C" void New_MediaPlayer_NowPlaying_OnRedraw(DISP_OBJ *dobj)
{
  DISP_OBJ_NOWPLAYING *disp_obj = (DISP_OBJ_NOWPLAYING *)dobj;

  ADVPLAYER_DATA *data = GetData();

  if (data->Skin->bg_enable)
  {
    DrawImage(data->Skin->bg_x,
              data->Skin->bg_y,
              data->skin_image[BACKGROUND_ICN].id);
  }

  if (data->Skin->coverart_enable)
  {
    if (data->HasCover)
    {
      DrawImageEx(data->Skin->coverart_x, data->Skin->coverart_y,
                  data->Skin->coverart_w, data->Skin->coverart_h,
                  data->CoverArt);
    }
    else
    {
      DrawImageEx(data->Skin->coverart_x, data->Skin->coverart_y,
                  data->Skin->coverart_w, data->Skin->coverart_h,
                  data->skin_image[MP_NOCOVER_ICN].id);
    }
    DrawImageEx(data->Skin->coverart_x, data->Skin->coverart_y,
                data->Skin->coverart_w, data->Skin->coverart_h,
                data->skin_image[MP_REFLECT_ICN].id);
  }

  if (data->Skin->overlay_enable)
  {
    DrawImage(data->Skin->overlay_x,
              data->Skin->overlay_y,
              data->skin_image[MP_OVERLAY_ICN].id);
  }

  if (data->Skin->icon_walkman_enable)
  {
    DrawImage(data->Skin->icon_walkman_x,
              data->Skin->icon_walkman_y,
              data->skin_image[WALKMAN_ICN].id);
  }

  if (data->Skin->icon_artist_enable)
  {
    DrawImage(data->Skin->icon_artist_x,
              data->Skin->icon_artist_y,
              data->skin_image[MP_ARTIST_ICN].id);
  }

  if (data->Skin->icon_title_enable)
  {
    DrawImage(data->Skin->icon_title_x,
              data->Skin->icon_title_y,
              data->skin_image[MP_TITLE_ICN].id);
  }

  if (data->Skin->icon_album_enable)
  {
    DrawImage(data->Skin->icon_album_x,
              data->Skin->icon_album_y,
              data->skin_image[MP_TITLE_ICN].id);
  }

  if (data->Skin->icon_next_enable)
  {
    if (data->PlayerState == TMusicState_FastForwarding)
    {
      DrawImage(data->Skin->icon_next_x, data->Skin->icon_next_y, data->skin_image[MP_FF_ICN].id);
    }
    else
    {
      DrawImage(data->Skin->icon_next_x, data->Skin->icon_next_y, data->skin_image[MP_NEXT_ICN].id);
    }
  }

  if (data->Skin->icon_prev_enable)
  {
    if (data->PlayerState == TMusicState_Rewinding)
    {
      DrawImage(data->Skin->icon_prev_x, data->Skin->icon_prev_y, data->skin_image[MP_RW_ICN].id);
    }
    else
    {
      DrawImage(data->Skin->icon_prev_x, data->Skin->icon_prev_y, data->skin_image[MP_PREV_ICN].id);
    }
  }

  if (data->Skin->icon_playpause_enable)
  {
    if (data->IsPlaying)
      DrawImage(data->Skin->icon_playpause_x, data->Skin->icon_playpause_y, data->skin_image[MP_PAUSE_ICN].id);
    else
      DrawImage(data->Skin->icon_playpause_x, data->Skin->icon_playpause_y, data->skin_image[MP_PLAY_ICN].id);
  }

  if (data->Skin->icon_random_enable)
  {
    if (disp_obj->Random)
      DrawImage(data->Skin->icon_random_x, data->Skin->icon_random_y, data->skin_image[MP_MODE_RANDOM_ICN].id);
  }

  if (data->Skin->icon_repeat_enable)
  {
    if (disp_obj->Repeat)
      DrawImage(data->Skin->icon_repeat_x, data->Skin->icon_repeat_y, data->skin_image[MP_MODE_REPEAT_ICN].id);
  }

  if (data->Skin->icon_eq_enable)
  {
    switch (disp_obj->EqPreset)
    {
    case EqPreset_Normal:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_NORMAL_ICN].id);
      break;
    case EqPreset_Bass:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_BASS_ICN].id);
      break;
#ifdef MEGABASS
    case EqPreset_Megabass:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_MEGABASS_ICN].id);
      break;
#endif
    case EqPreset_TrebleBoost:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_TREBLEBOOST_ICN].id);
      break;
    case EqPreset_Voice:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_VOICE_ICN].id);
      break;
    default:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_MANUAL_ICN].id);
      break;
    }
  }

  if (data->Skin->text_artist_enable)
  {
    DrawText(data->Skin->text_artist_font,
             TextID_GetLength(disp_obj->Text_Artis) ? disp_obj->Text_Artis : UNKNOWN_ARTIST,
             data->Skin->text_artist_align,
             data->Skin->text_artist_x,
             data->Skin->text_artist_y,
             data->Skin->text_artist_w,
             data->Skin->text_artist_h,
             data->Skin->text_artist_color);
  }

  if (data->Skin->text_title_enable)
  {
    DrawText(data->Skin->text_title_font,
             disp_obj->Text_Title,
             data->Skin->text_title_align,
             data->Skin->text_title_x,
             data->Skin->text_title_y,
             data->Skin->text_title_w,
             data->Skin->text_title_h,
             data->Skin->text_title_color);
  }

  if (data->Skin->text_album_enable)
  {
    DrawText(data->Skin->text_album_font,
             TextID_GetLength(disp_obj->Text_Album) ? disp_obj->Text_Album : UNKNOWN_ALBUM,
             data->Skin->text_album_align,
             data->Skin->text_album_x,
             data->Skin->text_album_y,
             data->Skin->text_album_w,
             data->Skin->text_album_h,
             data->Skin->text_album_color);
  }

  if (data->Skin->text_trackid_enable)
  {
    snwprintf(data->buffer,
              MAXELEMS(data->buffer),
              L"%02d/%02d",
              disp_obj->current_track_id + 1,
              disp_obj->total_tracks);
    data->text_id = TextID_Create(data->buffer, ENC_UCS2, TEXTID_ANY_LEN);
    DrawText(data->Skin->text_trackid_font,
             data->text_id,
             data->Skin->text_trackid_align,
             data->Skin->text_trackid_x,
             data->Skin->text_trackid_y,
             data->Skin->text_trackid_w,
             data->Skin->text_trackid_h,
             data->Skin->text_trackid_color);
    TEXT_FREE(data->text_id);
  }

  if (data->Skin->text_fulltime_enable)
  {
    char *text;
    int len = Format_Time(disp_obj->full_time, disp_obj->elapsed_time, 0, 0, &text, 1);
    data->text_id = TextIteratorSetTextId(&text, ENC_LAT1, len);
    DrawText(data->Skin->text_fulltime_font,
             data->text_id,
             data->Skin->text_fulltime_align,
             data->Skin->text_fulltime_x,
             data->Skin->text_fulltime_y,
             data->Skin->text_fulltime_w,
             data->Skin->text_fulltime_h,
             data->Skin->text_fulltime_color);
    TEXT_FREE(data->text_id);
  }

  if (data->Skin->text_elapsedtime_enable)
  {
    char *text;
    int len = Format_Time(disp_obj->elapsed_time, disp_obj->full_time, 0, 0, &text, 1);
    data->text_id = TextIteratorSetTextId(&text, ENC_LAT1, len);
    DrawText(data->Skin->text_elapsedtime_font,
             data->text_id,
             data->Skin->text_elapsedtime_align,
             data->Skin->text_elapsedtime_x,
             data->Skin->text_elapsedtime_y,
             data->Skin->text_elapsedtime_w,
             data->Skin->text_elapsedtime_h,
             data->Skin->text_elapsedtime_color);
    TEXT_FREE(data->text_id);
  }

  if (data->Skin->text_remainingtime_enable)
  {
    char *text;
    int len = Format_Time(disp_obj->full_time - disp_obj->elapsed_time, disp_obj->full_time, 0, 0, &text, 1);
    data->text_id = TextIteratorSetTextId(&text, ENC_LAT1, len);
    DrawText(data->Skin->text_remainingtime_font,
             data->text_id,
             data->Skin->text_remainingtime_align,
             data->Skin->text_remainingtime_x,
             data->Skin->text_remainingtime_y,
             data->Skin->text_remainingtime_w,
             data->Skin->text_remainingtime_h,
             data->Skin->text_remainingtime_color);
    TEXT_FREE(data->text_id);
  }

  if (data->Skin->text_samplerate_enable)
  {
    if (data->SampleRate)
    {
      data->text_id = TextID_Create(getSampleRate(data->SampleRate), ENC_UCS2, TEXTID_ANY_LEN);
    }
    else
    {
      data->text_id = STR("no-data");
    }
    DrawText(data->Skin->text_samplerate_font,
             data->text_id,
             data->Skin->text_samplerate_align,
             data->Skin->text_samplerate_x,
             data->Skin->text_samplerate_y,
             data->Skin->text_samplerate_w,
             data->Skin->text_samplerate_h,
             data->Skin->text_samplerate_color);
    TEXT_FREE(data->text_id);
  }

  if (data->Skin->PB_enable)
  {
    DrawProgressBar(data->skin_image[MP_PB_INDICATOR_ICN].id,
                    disp_obj->elapsed_time,
                    disp_obj->full_time,
                    data->Skin->PB_x1,
                    data->Skin->PB_y1,
                    data->Skin->PB_x2,
                    data->Skin->PB_y2,
                    data->Skin->PB_color_b,
                    data->Skin->PB_color_e,
                    data->Skin->PB_enable_indicator);
  }
}

extern "C" void New_MediaPlayer_NowPlaying_SetSize(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();
  if (data->Skin->fullscreen)
  {
    DispObject_WindowSetSize(disp_obj, Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main));
  }
  else
  {
    DispObject_WindowSetSize(disp_obj, Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main) - STATUSBAR_H);
  }
}

extern "C" void CallSkinSelector(BOOK *book, GUI *gui)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  BookObj_CallPage(audioBook, &page_MediaPlayer_SkinSelectorPage);
}

extern "C" TEXTID SkinSelect_GetText()
{
  return STR("Skins");
}

wchar_t *GetCoverType(char cover_type)
{
  if (cover_type <= 3)
  {
    switch (cover_type)
    {
    case 0:
      return L"jpg";
    case 1:
      return L"gif";
    case 2:
      return L"png";
    case 3:
      return L"bmp";
    }
    return NULL;
  }
  return NULL;
}

void GetPlayerData(BOOK *book)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;

  ADVPLAYER_DATA *data = GetData();
  TRACK_DESC *NewTrack = TrackDesc_Get(audioBook);
  if (!TrackDesc_Compare(data->CurrentTrack, NewTrack))
  {
    TrackDesc_Free(data->CurrentTrack);
    data->CurrentTrack = NewTrack;

    if (data->HasCover)
      IMAGE_FREE(data->CoverArt);

    data->HasCover = FALSE;
    data->CoverArt = NOIMAGE;

    void *MetaData_Desc = MetaData_Desc_Create(data->CurrentTrack->path, data->CurrentTrack->name);

    char cover_type;
    int size;
    int cover_offset;
    if (MetaData_Desc_GetCoverInfo(MetaData_Desc, &cover_type, &size, &cover_offset))
    {
      int file = _fopen(data->CurrentTrack->path, data->CurrentTrack->name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
      if (file >= NULL)
      {
        if (lseek(file, cover_offset, SEEK_SET))
        {
          char *buf = (char *)malloc(size);
          fread(file, buf, size);
          ImageID_GetIndirect(buf, size, NULL, GetCoverType(cover_type), &data->CoverArt);
          data->CoverSize = size;
          data->HasCover = TRUE;
        }
        fclose(file);
      }
    }
    MetaData_Desc_Destroy(MetaData_Desc);
    InvalidateNowPlaying(data->MediaPlayer_NowPlaying);
  }
  else
  {
    TrackDesc_Free(NewTrack);
  }
}

void GetMediaPlayerState(BOOK *book)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;

  ADVPLAYER_DATA *data = GetData();
  data->PlayerState = audioBook->player_state;
  data->SampleRate = audioBook->sample_rate;

  if (data->PlayerState == TMusicState_Playing)
    data->IsPlaying = TRUE;
  else
    data->IsPlaying = FALSE;

  InvalidateNowPlaying(data->MediaPlayer_NowPlaying);
}

extern "C" int New_MEDIAPLAYER_CREATED_EVENT(void *data, BOOK *book)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  int ret = pg_MEDIAPLAYER_CREATED_EVENT(data, audioBook);

  GetPlayerData(audioBook);
  return ret;
}

extern "C" int New_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(void *data, BOOK *book)
{
  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  int ret = pg_MEDIAPLAYER_AUDIO_PLAYING_TIME(data, audioBook);

  GetPlayerData(audioBook);
  GetMediaPlayerState(audioBook);
  return ret;
}
