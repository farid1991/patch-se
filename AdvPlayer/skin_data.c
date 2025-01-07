#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "data.h"
#include "draw.h"
#include "main.h"
#include "track_desc.h"
#include "skin_data.h"
#include "skin_parser.h"
#include "timer.h"

wchar_t *skin_images_getname(int index)
{
  wchar_t *icons[MP_LAST_IMG] =
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

  return icons[index];
}

void skin_image_unload()
{
  ADVPLAYER_DATA *data = env_data_get();

  for (int i = 0; i < MP_LAST_IMG; i++)
  {
    image_unregister(&data->skin_images[i]);
  }
  data->image_loaded = false;
}

void skin_image_load(wchar_t *skin_path)
{
  ADVPLAYER_DATA *data = env_data_get();

  for (int i = 0; i < MP_LAST_IMG; i++)
  {
    if (FSX_IsFileExists(skin_path, skin_images_getname(i)))
    {
      image_register(&data->skin_images[i], skin_path, skin_images_getname(i));
    }
    else
    {
      data->skin_images[i].handle = NOIMAGE;
      data->skin_images[i].id = NOIMAGE;
      data->skin_images[i].exist = FALSE;
    }
  }
  data->image_loaded = true;
}

void skin_data_path_save(wchar_t *skin_path)
{
  int file = _fopen(SKIN_CFG_PATH, SKIN_CFG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    SKIN_CONFIG *skin_cfg = (SKIN_CONFIG *)malloc(sizeof(SKIN_CONFIG));
    memset(skin_cfg, NULL, sizeof(SKIN_CONFIG));
    wstrcpy(skin_cfg->path, skin_path);
    fwrite(file, skin_cfg, sizeof(SKIN_CONFIG));
    fclose(file);
  }
}

SKIN_CONFIG *skin_data_config_get(wchar_t *cfg_path, wchar_t *cfg_name)
{
  SKIN_CONFIG *skin_cfg = (SKIN_CONFIG *)malloc(sizeof(SKIN_CONFIG));
  memset(skin_cfg, 0, sizeof(SKIN_CONFIG));

  FSTAT fs;
  fstat(cfg_path, cfg_name, &fs);
  if (fs.fsize != sizeof(SKIN_CONFIG))
  {
    wstrcpy(skin_cfg->path, DEFAULT_SKIN_PATH);
    return skin_cfg;
  }

  int file = _fopen(cfg_path, cfg_name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    fread(file, skin_cfg, sizeof(SKIN_CONFIG));
    fclose(file);
  }
  return skin_cfg;
}

void skin_data_read(SKIN_DATA *skin_data, wchar_t *skin_path)
{
  FSTAT fs;
  if (fstat(skin_path, SKIN_NAME, &fs) == 0)
  {
    int fsize = fs.fsize;
    int file = _fopen(skin_path, SKIN_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (file >= 0)
    {
      char *buf = (char *)malloc(fsize + 1);
      memset(buf, 0, fsize + 1);
      fread(file, buf, fsize);
      fclose(file);

      char *param;
      if (param = manifest_GetParam(buf, "[Background]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->bg_enable = values[0];
        skin_data->bg_x = values[1];
        skin_data->bg_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[Overlay]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->overlay_enable = values[0];
        skin_data->overlay_x = values[1];
        skin_data->overlay_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[ArtistText]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_artist_enable = values[0];
        skin_data->text_artist_font = values[1];
        skin_data->text_artist_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[ArtistPos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_artist_x = values[0];
        skin_data->text_artist_y = values[1];
        skin_data->text_artist_w = values[2];
        skin_data->text_artist_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[ArtistColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_artist_color = value;
        DBG("\n[ArtistColor]: 0x%X", value);
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[ArtistIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_artist_enable = values[0];
        skin_data->icon_artist_x = values[1];
        skin_data->icon_artist_y = values[2];
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[TitleText]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_title_enable = values[0];
        skin_data->text_title_font = values[1];
        skin_data->text_title_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[TitlePos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_title_x = values[0];
        skin_data->text_title_y = values[1];
        skin_data->text_title_w = values[2];
        skin_data->text_title_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[TitleColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_title_color = value;
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[TitleIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_title_enable = values[0];
        skin_data->icon_title_x = values[1];
        skin_data->icon_title_y = values[2];
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[AlbumText]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_album_enable = values[0];
        skin_data->text_album_font = values[1];
        skin_data->text_album_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[AlbumPos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_album_x = values[0];
        skin_data->text_album_y = values[1];
        skin_data->text_album_w = values[2];
        skin_data->text_album_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[AlbumColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_album_color = value;
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[AlbumIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_album_enable = values[0];
        skin_data->icon_album_x = values[1];
        skin_data->icon_album_y = values[2];
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[TrackID]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_trackid_enable = values[0];
        skin_data->text_trackid_font = values[1];
        skin_data->text_trackid_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[TrackIDPos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_trackid_x = values[0];
        skin_data->text_trackid_y = values[1];
        skin_data->text_trackid_w = values[2];
        skin_data->text_trackid_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[TrackIDColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_trackid_color = value;
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[Fulltime]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_fulltime_enable = values[0];
        skin_data->text_fulltime_font = values[1];
        skin_data->text_fulltime_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[FulltimePos]", 0))
      {
        int values[4];

        parse_values(param, values);
        skin_data->text_fulltime_x = values[0];
        skin_data->text_fulltime_y = values[1];
        skin_data->text_fulltime_w = values[2];
        skin_data->text_fulltime_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[FulltimeColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_fulltime_color = value;
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[Elapsed]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_elapsedtime_enable = values[0];
        skin_data->text_elapsedtime_font = values[1];
        skin_data->text_elapsedtime_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[ElapsedPos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_elapsedtime_x = values[0];
        skin_data->text_elapsedtime_y = values[1];
        skin_data->text_elapsedtime_w = values[2];
        skin_data->text_elapsedtime_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[ElapsedColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_elapsedtime_color = value;
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[Remaining]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_remainingtime_enable = values[0];
        skin_data->text_remainingtime_font = values[1];
        skin_data->text_remainingtime_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[RemainingPos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_remainingtime_x = values[0];
        skin_data->text_remainingtime_y = values[1];
        skin_data->text_remainingtime_w = values[2];
        skin_data->text_remainingtime_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[RemainingColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_remainingtime_color = value;
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[SampleRate]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->text_samplerate_enable = values[0];
        skin_data->text_samplerate_font = values[1];
        skin_data->text_samplerate_align = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[SampleRatePos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->text_samplerate_x = values[0];
        skin_data->text_samplerate_y = values[1];
        skin_data->text_samplerate_w = values[2];
        skin_data->text_samplerate_h = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[SampleRateColor]", 0))
      {
        int value = parse_value(param);
        skin_data->text_samplerate_color = value;
        DBG("\n[SampleRateColor]: 0x%X", value);
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[CoverArt]", 0))
      {
        int value = parse_value(param);
        skin_data->coverart_enable = value;
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[CoverPos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->coverart_x = values[0];
        skin_data->coverart_y = values[1];
        skin_data->coverart_w = values[2];
        skin_data->coverart_h = values[3];
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[PlayerState]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_playerstate_enable = values[0];
        skin_data->icon_playerstate_x = values[1];
        skin_data->icon_playerstate_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[NextIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_next_enable = values[0];
        skin_data->icon_next_x = values[1];
        skin_data->icon_next_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[PrevIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_prev_enable = values[0];
        skin_data->icon_prev_x = values[1];
        skin_data->icon_prev_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[RandomIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_random_enable = values[0];
        skin_data->icon_random_x = values[1];
        skin_data->icon_random_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[RepeatIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_repeat_enable = values[0];
        skin_data->icon_repeat_x = values[1];
        skin_data->icon_repeat_y = values[2];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[EQIcon]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_eq_enable = values[0];
        skin_data->icon_eq_x = values[1];
        skin_data->icon_eq_y = values[2];
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[ProgressBar]", 0))
      {
        int values[2];
        parse_values(param, values);
        skin_data->PB_enable = values[0];
        skin_data->PB_enable_indicator = values[1];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[PB_Pos]", 0))
      {
        int values[4];
        parse_values(param, values);
        skin_data->PB_x1 = values[0];
        skin_data->PB_x2 = values[1];
        skin_data->PB_y1 = values[2];
        skin_data->PB_y2 = values[3];
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[PBColor_B]", 0))
      {
        int value = parse_value(param);
        skin_data->PB_color_b = value;
        mfree(param);
      }
      if (param = manifest_GetParam(buf, "[PBColor_E]", 0))
      {
        int value = parse_value(param);
        skin_data->PB_color_e = value;
        mfree(param);
      }

      if (param = manifest_GetParam(buf, "[WALKMAN]", 0))
      {
        int values[3];
        parse_values(param, values);
        skin_data->icon_walkman_enable = values[0];
        skin_data->icon_walkman_x = values[1];
        skin_data->icon_walkman_y = values[2];
        mfree(param);
      }
#ifdef ENABLE_VISUALIZER
      if (param = manifest_GetParam(buf, "[VISUALIZATION]", 0))
      {
        int value = parse_value(param);
        skin_data->viz_enable = value;
        mfree(param);
      }
#endif
      if (param = manifest_GetParam(buf, "[FULLSCREEN]", 0))
      {
        int value = parse_value(param);
        skin_data->fullscreen = value;
        mfree(param);
      }

      mfree(buf);
    }
  }
}

#ifndef OLD_PLAYER
void skin_data_reload(AudioPlayerBook *audio_book, wchar_t *new_skin_path)
{
  ADVPLAYER_DATA *data = env_data_get();

  if (data->skin_loaded)
  {
    mfree(data->skin_data);
  }

  if (data->image_loaded)
  {
    skin_image_unload();
  }

  data->skin_data = (SKIN_DATA *)malloc(sizeof(SKIN_DATA));
  memset(data->skin_data, 0, sizeof(SKIN_DATA));
  skin_data_read(data->skin_data, new_skin_path);
  skin_image_load(new_skin_path);
  data->skin_loaded = true;

  DISP_OBJ *dispobj_nowplaying = GUIObject_GetDispObject(audio_book->Gui_NowPlaying);

#ifdef DB2010
  int style = data->skin_data->fullscreen ? UI_OverlayStyle_FullScreenNoStatus : UI_OverlayStyle_Default;
#else
  int style = data->skin_data->fullscreen ? UI_OverlayStyle_FullScreenNoStatus : UI_OverlayStyle_FullScreen;
#endif
  DispObject_SetStyle(dispobj_nowplaying, style);

  int height = data->skin_data->fullscreen ? data->disp_h : (data->disp_h - SOFTKEYS_H);
  DispObject_WindowSetSize(dispobj_nowplaying, data->disp_w, height);

#ifdef ENABLE_VISUALIZER
  KILL_TIMER(data->viz_timer);
  visualizer_init();
  Timer_ReSet(&data->wait_timer, 1000, MKTIMERPROC(wait_for_player), data);
#endif

  DispObject_InvalidateRect(dispobj_nowplaying, NULL);
}
#endif
