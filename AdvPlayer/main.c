#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "cover.h"
#include "CurrentTrack.h"
#include "data.h"
#include "draw.h"
#include "main.h"
#include "skinselect.h"

void *malloc(int size)
{
  return memalloc(size, 1, 5, "MP", NULL);
}

void mfree(void *mem)
{
  memfree(mem, "MP", NULL);
}

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error;

  img->id = NOIMAGE;
  img->handle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->handle, &error))
  {
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->handle, path, fname, 0, &img->id, &error))
    {
      if (error)
      {
        img->handle = NOIMAGE;
      }
    }
  }
}

int UnLoadSkinImage(ADVPLAYER_DATA *data)
{
  for (int i = 0; i < MP_LAST_IMG; i++)
  {
    int _SYNC = NULL;
    int *SYNC = &_SYNC;
    char error;
    REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, data->skin_image[i].handle, NULL, NULL, data->skin_image[i].id, 1, &error);
  }
  return 1;
}

void LoadSkinImage(ADVPLAYER_DATA *data, wchar_t *skinpath)
{
  const wchar_t *icons[MP_LAST_IMG] =
      {
          L"MP_BACKGROUND_ICN.png",
          L"MP_ARTIST_ICN.png",
          L"MP_TITLE_ICN.png",
          L"MP_ALBUM_ICN.png",
          L"MP_COVERART_ICN.png",
          L"MP_PLAY_ICN.png",
          L"MP_PAUSE_ICN.png",
          L"MP_NEXT_ICN.png",
          L"MP_PREVIOUS_ICN.png",
          L"MP_MODE_RANDOM_ICN.png",
          L"MP_MODE_REPEAT_ICN.png",
          L"MP_EQ_BASS_ICN.png",
          L"MP_EQ_MANUAL_ICN.png",
          L"MP_EQ_MEGABASS_ICN.png",
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

extern "C" int New_MediaPlayer_Audio_OnCreate(DISP_OBJ_MP_AUDIO *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();
  wstrcpy(data->SkinPath, GetCurrentSkinPath());
  data->Skin = (SKIN_DATA *)malloc(sizeof(SKIN_DATA));
  ReadConfig(data->Skin, data->SkinPath);

  data->MediaPlayer_Audio = disp_obj;
  data->fullscreen = data->Skin->fullscreen;

  if (UnLoadSkinImage(data))
    LoadSkinImage(data, data->SkinPath);

  MediaPlayer_Audio_OnCreate(disp_obj);
  return 1;
}

extern "C" void New_MediaPlayer_Audio_OnClose(DISP_OBJ_MP_AUDIO *disp_obj)
{
  MediaPlayer_Audio_OnClose(disp_obj);

  ADVPLAYER_DATA *data = GetData();
  UnLoadSkinImage(data);
  mfree(data->Skin);
  IMAGE_FREE(data->CoverArt);
  data->HasCover = FALSE;
  TrackDesc_Free(data->CurrentTrack);
  FreeData();
}

extern "C" void New_MediaPlayer_Audio_OnRedraw(DISP_OBJ_MP_AUDIO *disp_obj, int a, int b, int c)
{
}

extern "C" void New_MediaPlayer_Audio_SetStyle(DISP_OBJ_MP_AUDIO *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();
  if (data->Skin->fullscreen)
  {
    DispObject_SetStyle(disp_obj, UI_OverlayStyle_FullScreenNoStatus);
  }
  else
  {
    DispObject_SetStyle(disp_obj, UI_OverlayStyle_Default);
  }
}

void WalkmanDisplay_SetSize(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();
  if (data->Skin->fullscreen)
  {
    DispObject_WindowSetSize(disp_obj, 176, 196);
  }
  else
  {
    DispObject_WindowSetSize(disp_obj, 176, 176);
  }
}

extern "C" void New_MediaPlayer_PlayQueue_SetStyle(DISP_OBJ *disp_obj)
{
  WalkmanDisplay_SetSize(disp_obj);
  DispObject_SetLayerColor(disp_obj, GetThemeColor(3, 1));
  DispObject_SetThemeImage(disp_obj, THEMEITEM_BACKGROUND);
}

extern "C" void New_MediaPlayer_PlayQueue_SetTitle(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();

  if (data->Skin->fullscreen)
  {
    DispObject_SetTitleType(disp_obj, UI_TitleMode_Large);
    DispObject_SetSecondRowTitleText(disp_obj, STR("Song list"));
  }
  else
  {
    DispObject_SetTitleType(disp_obj, UI_TitleMode_Normal);
  }
  InvalidateNowPlaying(disp_obj);
}

extern "C" void New_MediaPlayer_NowPlaying_SetSize(DISP_OBJ_NOWPLAYING *disp_obj)
{
  WalkmanDisplay_SetSize(disp_obj);
}

extern "C" int New_MediaPlayer_NowPlaying_OnCreate(DISP_OBJ_NOWPLAYING *disp_obj)
{
  MediaPlayer_NowPlaying_OnCreate(disp_obj);

  ADVPLAYER_DATA *data = GetData();
  data->text_id = EMPTY_TEXTID;
  data->MediaPlayer_NowPlaying = disp_obj;
  return 1;
}

extern "C" void New_MediaPlayer_NowPlaying_OnClose(DISP_OBJ_NOWPLAYING *disp_obj)
{
  ADVPLAYER_DATA *data = GetData();

  TEXT_FREE(data->text_id);
  MediaPlayer_NowPlaying_OnClose(disp_obj);
}

extern "C" void New_MediaPlayer_NowPlaying_OnRedraw(DISP_OBJ_NOWPLAYING *disp_obj, int a, int b, int c)
{
  ADVPLAYER_DATA *data = GetData();

  if (data->Skin->bg_enable)
  {
    DrawImage(data->Skin->bg_x,
              data->Skin->bg_y,
              data->skin_image[BACKGROUND_ICN].id);
  }

  if (data->Skin->coverart_enable)
  {
    DrawCoverArt(data);
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
    DrawImage(data->Skin->icon_next_x, data->Skin->icon_next_y, data->skin_image[MP_NEXT_ICN].id);
  }

  if (data->Skin->icon_prev_enable)
  {
    DrawImage(data->Skin->icon_prev_x, data->Skin->icon_prev_y, data->skin_image[MP_PREVIOUS_ICN].id);
  }

  if (data->Skin->icon_playpause_enable)
  {
    DrawPlayerState(data);
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
    case 0:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_NORMAL_ICN].id);
      break;
    case 1:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_BASS_ICN].id);
      break;
    case 2:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_MEGABASS_ICN].id);
      break;
    case 3:
      DrawImage(data->Skin->icon_eq_x, data->Skin->icon_eq_y, data->skin_image[MP_EQ_TREBLEBOOST_ICN].id);
      break;
    case 4:
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
             TextID_GetLength(disp_obj->Text_Artis) ? disp_obj->Text_Artis : UNKNOWN_TXT,
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
             TextID_GetLength(disp_obj->Text_Album) ? disp_obj->Text_Album : UNKNOWN_TXT,
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
      snwprintf(data->buffer, MAXELEMS(data->buffer), L"%.1fKHz", data->SampleRate);
      data->text_id = TextID_Create(data->buffer, ENC_UCS2, TEXTID_ANY_LEN);
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
    RECT rect;
    rect.x1 = data->Skin->PB_x1;
    rect.x2 = data->Skin->PB_x2;
    rect.y1 = data->Skin->PB_y1;
    rect.y2 = data->Skin->PB_y2;
    DrawProgressBar(data->skin_image[MP_PB_INDICATOR_ICN].id,
                    disp_obj->elapsed_time,
                    disp_obj->full_time,
                    rect,
                    data->Skin->PB_color_b,
                    data->Skin->PB_color_e,
                    data->Skin->PB_enable_indicator);
  }
}

void GetAlbumArtData(BOOK *book)
{
  ADVPLAYER_DATA *data = GetData();

  AudioPlayerBook *audioBook = (AudioPlayerBook *)book;
  TRACK_DESC *NewTrack = TrackDesc_Get(audioBook);
  if (TrackDesc_Compare(data->CurrentTrack, NewTrack) == false)
  {
    if (data->HasCover)
      IMAGE_FREE(data->CoverArt);

    TrackDesc_Free(data->CurrentTrack);
    data->CurrentTrack = NewTrack;

    if (MetaData_ExtractCover(data->CurrentTrack->path, data->CurrentTrack->name))
    {
      ImageID_Get(SKIN_CFG_PATH, L"albumart.png", &data->CoverArt);
      data->HasCover = TRUE;
    }
    else
    {
      data->CoverArt = NOIMAGE;
      data->HasCover = FALSE;
    }
  }
  else
  {
    TrackDesc_Free(NewTrack);
  }
  InvalidateNowPlaying(data->MediaPlayer_NowPlaying);
}

extern "C" int New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(void *data, BOOK *book)
{
  GetAlbumArtData(book);
  GetMediaPlayerState(book);
  pg_MEDIAPLAYER_AUDIO_PLAYING_TIME(data, book);
  return 1;
}

extern "C" int New_UI_MEDIAPLAYER_NEW_TRACK_EVENT(void *data, BOOK *book)
{
  GetMediaPlayerState(book);
  pg_MEDIAPLAYER_NEW_TRACK_EVENT(data, book);
  return 1;
}

extern "C" int New_UI_MEDIAPLAYER_CREATED_EVENT(void *data, BOOK *book)
{
  pg_MEDIAPLAYER_CREATED_EVENT(data, book);
  GetMediaPlayerState(book);
  return 1;
}

extern "C" void CallSkinSelector(BOOK *book, GUI *gui)
{
  BookObj_CallPage(book, &page_MediaPlayer_SkinSelectorPage);
}

extern "C" TEXTID SkinSelect_GetText()
{
  return STR("Skins");
}
