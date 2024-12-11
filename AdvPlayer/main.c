#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\Function.h"

#include "..\\include\book\AudioPlayerBook.h"

#include "data.h"
#include "draw.h"
#include "edit_tag.h"
#include "id3_parser.h"
#include "image.h"
#include "main.h"
#include "track_desc.h"
#include "skin_data.h"
#include "skin_selector.h"

#ifdef ENABLE_VISUALIZER
#include "timer.h"
#include "visualizer.h"
#endif

void *malloc(int size)
{
#if defined(DB2010)
  return memalloc(size, 1, 5, "AdvPlayer", NULL);
#elif defined(DB2020)
  return memalloc(NULL, size, 1, 5, "AdvPlayer", NULL);
#endif
}

void mfree(void *mem)
{
  if (mem)
#if defined(DB2010)
    memfree(mem, "AdvPlayer", NULL);
#elif defined(DB2020)
    memfree(NULL, mem, "AdvPlayer", NULL);
#endif
}

#ifdef OLD_PLAYER
BOOL FSX_IsFileExists(const wchar_t *fpath, const wchar_t *fname)
{
  FSTAT fs;
  return fstat(fpath, fname, &fs) == 0;
}
#endif

TEXTID conv_sample_rate(int freq)
{
  wchar_t freq_buffer[11] = {0};

  int digit_len = count_digit(freq);
  itow(freq, freq_buffer, digit_len);

  if (digit_len == 4)
  {
    freq_buffer[2] = freq_buffer[1];
    freq_buffer[1] = L'.';
  }
  else
  {
    freq_buffer[3] = freq_buffer[2];
    freq_buffer[2] = L'.';
  }

  int index = digit_len - 1;

  freq_buffer[index] = L' ';
  index++;
  freq_buffer[index] = L'K';
  index++;
  freq_buffer[index] = L'H';
  index++;
  freq_buffer[index] = L'z';
  index++;
  freq_buffer[index] = L'\0';

  return TextID_Create(freq_buffer, ENC_UCS2, index);
}

extern "C" int New_MediaPlayer_Audio_OnCreate(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = env_data_get();
  data->disp_obj_audio = disp_obj;

  SKIN_CONFIG *skin_cfg = skin_data_config_get(SKIN_CFG_PATH, SKIN_CFG_NAME);

  if (!data->skin_loaded)
  {
    data->skin_data = (SKIN_DATA *)malloc(sizeof(SKIN_DATA));
    memset(data->skin_data, 0, sizeof(SKIN_DATA));
    skin_data_read(data->skin_data, skin_cfg->path);

    data->skin_loaded = true;
  }

  if (!data->image_loaded)
  {
    skin_image_load(skin_cfg->path);
  }

  mfree(skin_cfg);

  MediaPlayer_Audio_OnCreate(disp_obj);
  return 1;
}

extern "C" void New_AudioPlayerBook_onClose(BOOK *book)
{
  ADVPLAYER_DATA *data = env_data_get();

  skin_image_unload();

  if (data->has_coverart)
  {
    FREE_GC(data->cv_canvas);
    FREE_GVI(data->cv_gvi);
    data->has_coverart = false;
  }

  if (data->cover_image.id != NOIMAGE)
  {
    image_unregister(&data->cover_image);
  }

#ifdef ENABLE_VISUALIZER
  KILL_TIMER(data->wait_timer);
  KILL_TIMER(data->viz_timer);
  FREE_GC(data->viz_canvas);
  FREE_GVI(data->viz_gvi);
  image_unregister(&data->viz_image);
#endif

  mfree(data->skin_data);
  mfree(data->current_track);

  env_data_destroy(data);
}

extern "C" void New_MediaPlayer_Audio_OnRedraw(DISP_OBJ *disp_obj, int a, RECT *window, RECT *c)
{
  DispObject_SetLayerColor(disp_obj, GetThemeColor(0, THEMEITEM_BACKGROUND));
}

extern "C" void New_MediaPlayer_Audio_SetStyle(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = env_data_get();
#ifdef DB2010
  int style = data->skin_data->fullscreen ? UI_OverlayStyle_FullScreenNoStatus : UI_OverlayStyle_Default;
#else
  int style = data->skin_data->fullscreen ? UI_OverlayStyle_FullScreenNoStatus : UI_OverlayStyle_FullScreen;
#endif
  DispObject_SetStyle(disp_obj, style);
}

void WalkmanDisplay_SetSize(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = env_data_get();

  int height = data->skin_data->fullscreen ? data->disp_h : (data->disp_h - SOFTKEYS_H);
  DispObject_WindowSetSize(disp_obj, data->disp_w, height);
}

extern "C" void New_MediaPlayer_PlayQueue_SetStyle(DISP_OBJ *disp_obj)
{
  WalkmanDisplay_SetSize(disp_obj);
  New_MediaPlayer_Audio_SetStyle(disp_obj);
}

extern "C" void New_MediaPlayer_PlayQueue_SetTitle(DISP_OBJ *disp_obj)
{
  ADVPLAYER_DATA *data = env_data_get();

  if (data->skin_data->fullscreen)
  {
    DispObject_SetTitleType(disp_obj, UI_TitleMode_Large);
    DispObject_SetSecondRowTitleText(disp_obj, MP_BR_LISTPLAYLIST_TXT);
  }
  else
  {
    DispObject_SetTitleType(disp_obj, UI_TitleMode_Normal);
    DispObject_SetSecondRowTitleText(disp_obj, EMPTY_TEXTID);
  }
  DispObject_SetTitleText(disp_obj, MP_BR_LISTNOWPLAYING_TXT);
}

extern "C" void New_MediaPlayer_NowPlaying_SetSize(DISP_OBJ *disp_obj)
{
  WalkmanDisplay_SetSize(disp_obj);
}

extern "C" int New_MediaPlayer_NowPlaying_OnCreate(DISP_OBJ_NOWPLAYING *disp_obj)
{
  MediaPlayer_NowPlaying_OnCreate(disp_obj);

  ADVPLAYER_DATA *data = env_data_get();
  data->disp_obj_nowplaying = disp_obj;

#ifdef ENABLE_VISUALIZER
  visualizer_image_register();
  visualizer_init();

  data->wait_timer = Timer_Set(0, MKTIMERPROC(wait_for_player), data);
#endif

  return 1;
}

extern "C" void New_MediaPlayer_NowPlaying_OnRedraw(DISP_OBJ_NOWPLAYING *disp_obj, RECT *a, RECT *b, RECT *c)
{
  ADVPLAYER_DATA *data = env_data_get();

  TEXTID text_id;
  GC *disp_gc = get_DisplayGC();

  if (data->skin_data->bg_enable)
  {
    draw_image(disp_gc,
               data->skin_data->bg_x, data->skin_data->bg_y,
               data->skin_images[BACKGROUND_ICN].id);
  }

  if (data->skin_data->coverart_enable)
  {
    if (data->has_coverart)
    {
      int cv_width = GetImageWidth(data->cover_image.id);
      int cv_height = GetImageHeight(data->cover_image.id);

      if (data->cv_gvi == NULL)
      {
        data->cv_canvas = GC_CreateMemoryGC(cv_width, cv_height, 16, 0, NULL, 0);
        CANVAS_Get_GviGC(data->cv_canvas->pcanvas, &data->cv_gvi);

        GVI_BRUSH backbrush = GVI_CreateSolidBrush(clBlack);
        GVI_FillRectangle(data->cv_gvi, 0, 0, cv_width, cv_height, backbrush);
        GVI_Delete_GVI_Object(&backbrush);

        draw_image_ex(data->cv_canvas, 0, 0, cv_width, cv_height, data->cover_image.id);
      }

      CANVAS_Get_GviGC(disp_gc->pcanvas, &data->disp_gvi);
      GVI_StretchBlt(data->disp_gvi,
                     data->skin_data->coverart_x, data->skin_data->coverart_y,
                     data->skin_data->coverart_w, data->skin_data->coverart_h,
                     data->cv_gvi,
                     0, 0,
                     cv_width, cv_height,
                     204, 0, 0, 0);
    }
#ifdef ENABLE_VISUALIZER
    else if (data->skin_data->viz_enable && data->viz_ready)
    {
      visualizer_draw_bouncing_walkman(disp_gc,
                                       data->skin_data->coverart_x, data->skin_data->coverart_y,
                                       data->skin_data->coverart_w, data->skin_data->coverart_h);
    }
#endif
    else
    {
      draw_image_ex(disp_gc,
                    data->skin_data->coverart_x, data->skin_data->coverart_y,
                    data->skin_data->coverart_w, data->skin_data->coverart_h,
                    data->skin_images[MP_NOCOVER_ICN].id);
    }
    draw_image_ex(disp_gc,
                  data->skin_data->coverart_x, data->skin_data->coverart_y,
                  data->skin_data->coverart_w, data->skin_data->coverart_h,
                  data->skin_images[MP_REFLECT_ICN].id);
  }

  if (data->skin_data->PB_enable)
  {
    DrawProgressBar(disp_gc,
                    data->skin_images[MP_PB_INDICATOR_ICN].id,
                    disp_obj->elapsed_time,
                    disp_obj->full_time,
                    data->skin_data->PB_x1,
                    data->skin_data->PB_y1,
                    data->skin_data->PB_x2,
                    data->skin_data->PB_y2,
                    data->skin_data->PB_color_b,
                    data->skin_data->PB_color_e,
                    data->skin_data->PB_enable_indicator);
  }

  if (data->skin_data->overlay_enable)
  {
    draw_image(disp_gc,
               data->skin_data->overlay_x, data->skin_data->overlay_y,
               data->skin_images[MP_OVERLAY_ICN].id);
  }

  if (data->skin_data->icon_walkman_enable)
  {
    draw_image(disp_gc,
               data->skin_data->icon_walkman_x, data->skin_data->icon_walkman_y,
               data->skin_images[WALKMAN_ICN].id);
  }

  if (data->skin_data->icon_artist_enable)
  {
    draw_image(disp_gc,
               data->skin_data->icon_artist_x, data->skin_data->icon_artist_y,
               data->skin_images[MP_ARTIST_ICN].id);
  }

  if (data->skin_data->icon_title_enable)
  {
    draw_image(disp_gc,
               data->skin_data->icon_title_x, data->skin_data->icon_title_y,
               data->skin_images[MP_TITLE_ICN].id);
  }

  if (data->skin_data->icon_album_enable)
  {
    draw_image(disp_gc,
               data->skin_data->icon_album_x, data->skin_data->icon_album_y,
               data->skin_images[MP_TITLE_ICN].id);
  }

  if (data->skin_data->icon_next_enable)
  {
    if (data->player_state == TMusicState_FastForwarding)
      draw_image(disp_gc,
                 data->skin_data->icon_next_x, data->skin_data->icon_next_y,
                 data->skin_images[MP_FF_ICN].id);
    else
      draw_image(disp_gc,
                 data->skin_data->icon_next_x, data->skin_data->icon_next_y,
                 data->skin_images[MP_NEXT_ICN].id);
  }

  if (data->skin_data->icon_prev_enable)
  {
    if (data->player_state == TMusicState_Rewinding)
      draw_image(disp_gc,
                 data->skin_data->icon_prev_x, data->skin_data->icon_prev_y,
                 data->skin_images[MP_RW_ICN].id);
    else
      draw_image(disp_gc,
                 data->skin_data->icon_prev_x, data->skin_data->icon_prev_y,
                 data->skin_images[MP_PREV_ICN].id);
  }

  if (data->skin_data->icon_playerstate_enable)
  {
    if (data->is_playing)
      draw_image(disp_gc,
                 data->skin_data->icon_playerstate_x, data->skin_data->icon_playerstate_y,
                 data->skin_images[MP_PAUSE_ICN].id);
    else
      draw_image(disp_gc,
                 data->skin_data->icon_playerstate_x, data->skin_data->icon_playerstate_y,
                 data->skin_images[MP_PLAY_ICN].id);
  }

  if (data->skin_data->icon_random_enable && disp_obj->random)
  {
    draw_image(disp_gc,
               data->skin_data->icon_random_x, data->skin_data->icon_random_y,
               data->skin_images[MP_MODE_RANDOM_ICN].id);
  }

  if (data->skin_data->icon_repeat_enable && disp_obj->repeat)
  {
    draw_image(disp_gc,
               data->skin_data->icon_repeat_x, data->skin_data->icon_repeat_y,
               data->skin_images[MP_MODE_REPEAT_ICN].id);
  }

  if (data->skin_data->icon_eq_enable)
  {
    switch (disp_obj->eq_preset)
    {
    case EqPreset_Normal:
      draw_image(disp_gc, data->skin_data->icon_eq_x, data->skin_data->icon_eq_y, data->skin_images[MP_EQ_NORMAL_ICN].id);
      break;
    case EqPreset_Bass:
      draw_image(disp_gc, data->skin_data->icon_eq_x, data->skin_data->icon_eq_y, data->skin_images[MP_EQ_BASS_ICN].id);
      break;
    case EqPreset_Megabass:
      draw_image(disp_gc, data->skin_data->icon_eq_x, data->skin_data->icon_eq_y, data->skin_images[MP_EQ_MEGABASS_ICN].id);
      break;
    case EqPreset_TrebleBoost:
      draw_image(disp_gc, data->skin_data->icon_eq_x, data->skin_data->icon_eq_y, data->skin_images[MP_EQ_TREBLEBOOST_ICN].id);
      break;
    case EqPreset_Voice:
      draw_image(disp_gc, data->skin_data->icon_eq_x, data->skin_data->icon_eq_y, data->skin_images[MP_EQ_VOICE_ICN].id);
      break;
    default:
      draw_image(disp_gc, data->skin_data->icon_eq_x, data->skin_data->icon_eq_y, data->skin_images[MP_EQ_MANUAL_ICN].id);
      break;
    }
  }

  if (data->skin_data->text_artist_enable)
  {
    DrawText(data->skin_data->text_artist_font,
             TextID_GetLength(disp_obj->artist_textid) ? disp_obj->artist_textid : UNKNOWN_TXT,
             data->skin_data->text_artist_align,
             data->skin_data->text_artist_x,
             data->skin_data->text_artist_y,
             data->skin_data->text_artist_w,
             data->skin_data->text_artist_h,
             data->skin_data->text_artist_color);
  }

  if (data->skin_data->text_title_enable)
  {
    DrawText(data->skin_data->text_title_font,
             disp_obj->title_textid,
             data->skin_data->text_title_align,
             data->skin_data->text_title_x,
             data->skin_data->text_title_y,
             data->skin_data->text_title_w,
             data->skin_data->text_title_h,
             data->skin_data->text_title_color);
  }

  if (data->skin_data->text_album_enable)
  {
    DrawText(data->skin_data->text_album_font,
             TextID_GetLength(disp_obj->album_textid) ? disp_obj->album_textid : UNKNOWN_TXT,
             data->skin_data->text_album_align,
             data->skin_data->text_album_x,
             data->skin_data->text_album_y,
             data->skin_data->text_album_w,
             data->skin_data->text_album_h,
             data->skin_data->text_album_color);
  }

  if (data->skin_data->text_trackid_enable)
  {
    wchar_t track_buffer[11];

    uint16_t total_tracks = disp_obj->total_tracks;
    uint16_t current_track = disp_obj->current_track_id;
    if (total_tracks != 0)
    {
      current_track++;
    }

    int digit_len = count_digit(total_tracks);
    int trackid_len = itow(current_track, track_buffer, digit_len);

    track_buffer[trackid_len] = L'/';
    trackid_len++;
    int next_len = itow(total_tracks, &track_buffer[trackid_len], digit_len);

    trackid_len += next_len;
    track_buffer[trackid_len] = L'\0';

    text_id = TextID_CreateFromTextIterator(track_buffer, ENC_UCS2, trackid_len);

    DrawText(data->skin_data->text_trackid_font,
             text_id,
             data->skin_data->text_trackid_align,
             data->skin_data->text_trackid_x,
             data->skin_data->text_trackid_y,
             data->skin_data->text_trackid_w,
             data->skin_data->text_trackid_h,
             data->skin_data->text_trackid_color);
    TextID_Destroy(text_id);
  }

  if (data->skin_data->text_fulltime_enable)
  {
    char time_buffer[16];
    int text_len = strftime(disp_obj->full_time, disp_obj->elapsed_time, 0, 0, time_buffer, 1);
    text_id = TextID_CreateFromTextIterator(time_buffer, ENC_LAT1, text_len);
    DrawText(data->skin_data->text_fulltime_font,
             text_id,
             data->skin_data->text_fulltime_align,
             data->skin_data->text_fulltime_x,
             data->skin_data->text_fulltime_y,
             data->skin_data->text_fulltime_w,
             data->skin_data->text_fulltime_h,
             data->skin_data->text_fulltime_color);
    TextID_Destroy(text_id);
  }

  if (data->skin_data->text_elapsedtime_enable)
  {
    char time_buffer[16];
    int text_len = strftime(disp_obj->elapsed_time, disp_obj->full_time, 0, 0, time_buffer, 1);
    text_id = TextID_CreateFromTextIterator(time_buffer, ENC_LAT1, text_len);
    DrawText(data->skin_data->text_elapsedtime_font,
             text_id,
             data->skin_data->text_elapsedtime_align,
             data->skin_data->text_elapsedtime_x,
             data->skin_data->text_elapsedtime_y,
             data->skin_data->text_elapsedtime_w,
             data->skin_data->text_elapsedtime_h,
             data->skin_data->text_elapsedtime_color);
    TextID_Destroy(text_id);
  }

  if (data->skin_data->text_remainingtime_enable)
  {
    char time_buffer[16];
    int text_len = strftime(disp_obj->elapsed_time, disp_obj->full_time, 0, 1, time_buffer, 1);
    text_id = TextID_CreateFromTextIterator(time_buffer, ENC_LAT1, text_len);
    DrawText(data->skin_data->text_remainingtime_font,
             text_id,
             data->skin_data->text_remainingtime_align,
             data->skin_data->text_remainingtime_x,
             data->skin_data->text_remainingtime_y,
             data->skin_data->text_remainingtime_w,
             data->skin_data->text_remainingtime_h,
             data->skin_data->text_remainingtime_color);
    TextID_Destroy(text_id);
  }

  if (data->skin_data->text_samplerate_enable && data->sample_rate)
  {
    text_id = conv_sample_rate(data->sample_rate);
    DrawText(data->skin_data->text_samplerate_font,
             text_id,
             data->skin_data->text_samplerate_align,
             data->skin_data->text_samplerate_x,
             data->skin_data->text_samplerate_y,
             data->skin_data->text_samplerate_w,
             data->skin_data->text_samplerate_h,
             data->skin_data->text_samplerate_color);
    TextID_Destroy(text_id);
  }
}

void GetTrackInfo(AudioPlayerBook *audio_book)
{
  ADVPLAYER_DATA *data = env_data_get();

  TRACK_DESC *new_track = track_desc_get(audio_book);
  if (!track_desc_compare(data->current_track, new_track))
  {
    mfree(data->current_track);

    if (data->has_coverart)
    {
      FREE_GC(data->cv_canvas);
      FREE_GVI(data->cv_gvi);
    }

    if (data->cover_image.id != NOIMAGE)
    {
      image_unregister(&data->cover_image);
      data->has_coverart = false;
    }

    if (wstrwstr(new_track->fname, FILETYPE_mp3))
    {
      id3v2_get_coverart(new_track);
    }

    data->current_track = new_track;

    DISP_OBJ *dispobj_nowplaying = GUIObject_GetDispObject(audio_book->Gui_NowPlaying);
    DispObject_InvalidateRect(dispobj_nowplaying, NULL);
  }
  else
  {
    track_desc_free(new_track);
  }
}

void GetPlayerState(AudioPlayerBook *audio_book)
{
  ADVPLAYER_DATA *data = env_data_get();
  data->player_state = audio_book->player.state;
  data->is_playing = (data->player_state == TMusicState_Playing) ? true : false;

  if (audio_book->dsc)
  {
    data->sample_rate = audio_book->dsc->sample_rate;
  }
}

extern "C" int New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(void *audio_data, AudioPlayerBook *audio_book)
{
  int ret = pg_MEDIAPLAYER_AUDIO_PLAYING_TIME(audio_data, audio_book);

  GetTrackInfo(audio_book);
  GetPlayerState(audio_book);
  return ret;
}

extern "C" int New_UI_MEDIAPLAYER_NEW_TRACK_EVENT(void *audio_data, AudioPlayerBook *audio_book)
{
  int ret = pg_MEDIAPLAYER_NEW_TRACK_EVENT(audio_data, audio_book);

  GetTrackInfo(audio_book);
  GetPlayerState(audio_book);
  return ret;
}

extern "C" int New_UI_MEDIAPLAYER_CREATED_EVENT(void *audio_data, AudioPlayerBook *audio_book)
{
  int ret = pg_MEDIAPLAYER_CREATED_EVENT(audio_data, audio_book);

#ifdef DB2020
  GetTrackInfo(audio_book);
#endif
  GetPlayerState(audio_book);
  return ret;
}

void save_coverart(BOOK *book, GUI *gui)
{
  AudioPlayerBook *audio_book = (AudioPlayerBook *)book;
  PLAYLIST_ITEM *item = (PLAYLIST_ITEM *)malloc(sizeof(PLAYLIST_ITEM));

  if (audio_book->pPlaylist->GetItem(audio_book->playlist_id, audio_book->selected_track_id, item) >= 0)
  {
    id3v2_extract_coverart(item);
  }
  mfree(item);
}

void enter_skinselector(BOOK *audio_book, GUI *gui)
{
  BookObj_CallPage(audio_book, &page_MediaPlayer_SkinSelectorPage);
}

void enter_mymusic(BOOK *audio_book, GUI *gui)
{
  UI_Event(MM_BRW_TOPLEVEL_STARTED_EVENT);
}

TEXTID new_softkeys_text(uint8_t type)
{
  if (type == 1)
    return TextID_Create("Skins", ENC_LAT1, TEXTID_ANY_LEN);
  else if (type == 2)
    return TextID_Create("Save coverart", ENC_LAT1, TEXTID_ANY_LEN);
  else if (type == 3)
    return TextID_Create("Edit Tag", ENC_LAT1, TEXTID_ANY_LEN);
  return TextID_Create("My Music", ENC_LAT1, TEXTID_ANY_LEN);
}

TEXTID new_softkeys_infotext(uint8_t type)
{
  if (type == 0)
    return TextID_Create("Browse Artists,Albums,Tracks,Playlists,Videos", ENC_LAT1, TEXTID_ANY_LEN);
  return TextID_Create("Change skin of WALKMAN display", ENC_LAT1, TEXTID_ANY_LEN);
}

extern "C" void New_MediaPlayer_SoftKeys_MyMusic(AudioPlayerBook *audio_book)
{
  // New softkeys MyMusic
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_MYMUSIC, enter_mymusic);
  else
    GUIObject_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_MYMUSIC, enter_mymusic);

  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_MYMUSIC, new_softkeys_text(0));
  else
    GUIObject_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_MYMUSIC, new_softkeys_text(0));

  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_AddHelpStr(audio_book->Gui_NowPlaying, MP_ACTION_MYMUSIC, new_softkeys_infotext(0));
  else
    GUIObject_SoftKeys_SetInfoText(audio_book->Gui_NowPlaying, MP_ACTION_MYMUSIC, new_softkeys_infotext(0));
}

extern "C" void New_MediaPlayer_SoftKeys(AudioPlayerBook *audio_book)
{
  // New softkeys skins selector
#ifdef DB2020
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetItemAsSubItem(audio_book->Gui_NowPlaying, MP_ACTION_SETTINGS, MP_ACTION_SKINS);
  else
    GUIObject_SoftKeys_SetItemAsSubItem(audio_book->Gui_NowPlaying, MP_ACTION_SETTINGS, MP_ACTION_SKINS);
#endif
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_SKINS, enter_skinselector);
  else
    GUIObject_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_SKINS, enter_skinselector);

  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_SKINS, new_softkeys_text(1));
  else
    GUIObject_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_SKINS, new_softkeys_text(1));

  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_AddHelpStr(audio_book->Gui_NowPlaying, MP_ACTION_SKINS, new_softkeys_infotext(1));
  else
    GUIObject_SoftKeys_SetInfoText(audio_book->Gui_NowPlaying, MP_ACTION_SKINS, new_softkeys_infotext(1));

    // New softkeys skins save coverart
#ifdef DB2020
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetItemAsSubItem(audio_book->Gui_NowPlaying, MP_ACTION_FILE, MP_ACTION_SAVECOVER);
  else
    GUIObject_SoftKeys_SetItemAsSubItem(audio_book->Gui_NowPlaying, MP_ACTION_FILE, MP_ACTION_SAVECOVER);
#endif
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_SAVECOVER, save_coverart);
  else
    GUIObject_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_SAVECOVER, save_coverart);

  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_SAVECOVER, new_softkeys_text(2));
  else
    GUIObject_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_SAVECOVER, new_softkeys_text(2));

    // New softkeys edit tag
#ifdef DB2020
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetItemAsSubItem(audio_book->Gui_NowPlaying, MP_ACTION_FILE, MP_ACTION_EDITTAG);
  else
    GUIObject_SoftKeys_SetItemAsSubItem(audio_book->Gui_NowPlaying, MP_ACTION_FILE, MP_ACTION_EDITTAG);
#endif
  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_EDITTAG, tagedit_start_elf);
  else
    GUIObject_SoftKeys_SetAction(audio_book->Gui_NowPlaying, MP_ACTION_EDITTAG, tagedit_start_elf);

  if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_NowPlaying))
    MediaPlayer_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_EDITTAG, new_softkeys_text(3));
  else
    GUIObject_SoftKeys_SetText(audio_book->Gui_NowPlaying, MP_ACTION_EDITTAG, new_softkeys_text(3));
}
