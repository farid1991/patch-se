#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\IUnknown.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "data.h"
#include "main.h"

ADVPLAYER_DATA *InitData()
{
  ADVPLAYER_DATA *data = (ADVPLAYER_DATA *)malloc(sizeof(ADVPLAYER_DATA));
  memset(data, NULL, sizeof(ADVPLAYER_DATA));
  set_envp(NULL, EMP_NAME, (OSADDRESS)data);
  return (data);
}

ADVPLAYER_DATA *GetData()
{
  ADVPLAYER_DATA *data = (ADVPLAYER_DATA *)get_envp(NULL, EMP_NAME);
  if (data)
    return data;
  return InitData();
}

void FreeData(ADVPLAYER_DATA *data)
{
  if (data)
  {
    mfree(data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}

void SetCurrentSkinPath(wchar_t *skin_path)
{
  int file = _fopen(SKIN_CFG_PATH, SKIN_CFG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    SKINCONFIG *ConfigData = (SKINCONFIG *)malloc(sizeof(SKINCONFIG));
    memset(ConfigData, NULL, sizeof(SKINCONFIG));
    wstrcpy(ConfigData->path, skin_path);
    fwrite(file, ConfigData, sizeof(SKINCONFIG));
    fclose(file);
  }
}

wchar_t *GetCurrentSkinPath()
{
  wchar_t *skin_path = DEFAULT_SKIN_PATH;
  int file = _fopen(SKIN_CFG_PATH, SKIN_CFG_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    SKINCONFIG *ConfigData = (SKINCONFIG *)malloc(sizeof(SKINCONFIG));
    memset(ConfigData, NULL, sizeof(SKINCONFIG));
    fread(file, ConfigData, sizeof(SKINCONFIG));
    skin_path = ConfigData->path;
    fclose(file);
    mfree(ConfigData);
  }
  return skin_path;
}

void Free_SkinData(SKIN_DATA *Skin)
{
  if (Skin)
  {
    Skin->bg_enable = NULL;
    Skin->bg_x = NULL;
    Skin->bg_y = NULL;

    Skin->overlay_enable = NULL;
    Skin->overlay_x = NULL;
    Skin->overlay_y = NULL;

    Skin->text_artist_enable = NULL;
    Skin->text_artist_font = NULL;
    Skin->text_artist_align = NULL;
    Skin->text_artist_x = NULL;
    Skin->text_artist_y = NULL;
    Skin->text_artist_w = NULL;
    Skin->text_artist_h = NULL;
    Skin->text_artist_color = NULL;
    Skin->icon_artist_enable = NULL;
    Skin->icon_artist_x = NULL;
    Skin->icon_artist_y = NULL;

    Skin->text_title_enable = NULL;
    Skin->text_title_font = NULL;
    Skin->text_title_align = NULL;
    Skin->text_title_x = NULL;
    Skin->text_title_y = NULL;
    Skin->text_title_w = NULL;
    Skin->text_title_h = NULL;
    Skin->text_title_color = NULL;
    Skin->icon_title_enable = NULL;
    Skin->icon_title_x = NULL;
    Skin->icon_title_y = NULL;

    Skin->text_album_enable = NULL;
    Skin->text_album_font = NULL;
    Skin->text_album_align = NULL;
    Skin->text_album_x = NULL;
    Skin->text_album_y = NULL;
    Skin->text_album_w = NULL;
    Skin->text_album_h = NULL;
    Skin->text_album_color = NULL;
    Skin->icon_album_enable = NULL;
    Skin->icon_album_x = NULL;
    Skin->icon_album_y = NULL;

    Skin->text_trackid_enable = NULL;
    Skin->text_trackid_font = NULL;
    Skin->text_trackid_align = NULL;
    Skin->text_trackid_x = NULL;
    Skin->text_trackid_y = NULL;
    Skin->text_trackid_w = NULL;
    Skin->text_trackid_h = NULL;
    Skin->text_trackid_color = NULL;

    Skin->text_fulltime_enable = NULL;
    Skin->text_fulltime_font = NULL;
    Skin->text_fulltime_align = NULL;
    Skin->text_fulltime_x = NULL;
    Skin->text_fulltime_y = NULL;
    Skin->text_fulltime_w = NULL;
    Skin->text_fulltime_h = NULL;
    Skin->text_fulltime_color = NULL;

    Skin->text_elapsedtime_enable = NULL;
    Skin->text_elapsedtime_font = NULL;
    Skin->text_elapsedtime_align = NULL;
    Skin->text_elapsedtime_x = NULL;
    Skin->text_elapsedtime_y = NULL;
    Skin->text_elapsedtime_w = NULL;
    Skin->text_elapsedtime_h = NULL;
    Skin->text_elapsedtime_color = NULL;

    Skin->text_remainingtime_enable = NULL;
    Skin->text_remainingtime_font = NULL;
    Skin->text_remainingtime_align = NULL;
    Skin->text_remainingtime_x = NULL;
    Skin->text_remainingtime_y = NULL;
    Skin->text_remainingtime_w = NULL;
    Skin->text_remainingtime_h = NULL;
    Skin->text_remainingtime_color = NULL;

    Skin->text_samplerate_enable = NULL;
    Skin->text_samplerate_font = NULL;
    Skin->text_samplerate_align = NULL;
    Skin->text_samplerate_x = NULL;
    Skin->text_samplerate_y = NULL;
    Skin->text_samplerate_w = NULL;
    Skin->text_samplerate_h = NULL;
    Skin->text_samplerate_color = NULL;

    Skin->coverart_enable = NULL;
    Skin->coverart_x = NULL;
    Skin->coverart_y = NULL;
    Skin->coverart_w = NULL;
    Skin->coverart_h = NULL;

    Skin->icon_playpause_enable = NULL;
    Skin->icon_playpause_x = NULL;
    Skin->icon_playpause_y = NULL;

    Skin->icon_next_enable = NULL;
    Skin->icon_next_x = NULL;
    Skin->icon_next_y = NULL;

    Skin->icon_prev_enable = NULL;
    Skin->icon_prev_x = NULL;
    Skin->icon_prev_y = NULL;

    Skin->icon_random_enable = NULL;
    Skin->icon_random_x = NULL;
    Skin->icon_random_y = NULL;

    Skin->icon_repeat_enable = NULL;
    Skin->icon_repeat_x = NULL;
    Skin->icon_repeat_y = NULL;

    Skin->icon_eq_enable = NULL;
    Skin->icon_eq_x = NULL;
    Skin->icon_eq_y = NULL;

    Skin->PB_enable = NULL;
    Skin->PB_enable_indicator = NULL;
    Skin->PB_x1 = NULL;
    Skin->PB_x2 = NULL;
    Skin->PB_y1 = NULL;
    Skin->PB_y2 = NULL;
    Skin->PB_color_b = NULL;
    Skin->PB_color_e = NULL;

    Skin->icon_walkman_enable = NULL;
    Skin->icon_walkman_x = NULL;
    Skin->icon_walkman_y = NULL;

    Skin->fullscreen = NULL;

    mfree(Skin);
  }
}

void ReadConfig(SKIN_DATA *Skin, wchar_t *skin_path)
{
  const char *format = "[Background]: %d,%d,%d\r\n"
                       "[Overlay]: %d,%d,%d\r\n"
                       "[ArtistText]: %d,0x%x,%d\r\n"
                       "[ArtistPos]: %d,%d,%d,%d\r\n"
                       "[ArtistColor]: 0x%x\r\n"
                       "[ArtistIcon]: %d,%d,%d\r\n"
                       "[TitleText]: %d,0x%x,%d\r\n"
                       "[TitlePos]: %d,%d,%d,%d\r\n"
                       "[TitleColor]: 0x%x\r\n"
                       "[TitleIcon]: %d,%d,%d\r\n"
                       "[AlbumText]: %d,0x%x,%d\r\n"
                       "[AlbumPos]: %d,%d,%d,%d\r\n"
                       "[AlbumColor]: 0x%x\r\n"
                       "[AlbumIcon]: %d,%d,%d\r\n"
                       "[TrackID]: %d,0x%x,%d\r\n"
                       "[TrackIDPos]: %d,%d,%d,%d\r\n"
                       "[TrackIDColor]: 0x%x\r\n"
                       "[Fulltime]: %d,0x%x,%d\r\n"
                       "[FulltimePos]: %d,%d,%d,%d\r\n"
                       "[FulltimeColor]: 0x%x\r\n"
                       "[Elapsed]: %d,0x%x,%d\r\n"
                       "[ElapsedPos]: %d,%d,%d,%d\r\n"
                       "[ElapsedColor]: 0x%x\r\n"
                       "[Remaining]: %d,0x%x,%d\r\n"
                       "[RemainingPos]: %d,%d,%d,%d\r\n"
                       "[RemainingColor]: 0x%x\r\n"
                       "[SampleRate]: %d,0x%x,%d\r\n"
                       "[SampleRatePos]: %d,%d,%d,%d\r\n"
                       "[SampleRateColor]: 0x%x\r\n"
                       "[CoverArt]: %d\r\n"
                       "[CoverPos]: %d,%d,%d,%d\r\n"
                       "[PlayPause]: %d,%d,%d\r\n"
                       "[NextIcon]: %d,%d,%d\r\n"
                       "[PrevIcon]: %d,%d,%d\r\n"
                       "[RandomIcon]: %d,%d,%d\r\n"
                       "[RepeatIcon]: %d,%d,%d\r\n"
                       "[EQIcon]: %d,%d,%d\r\n"
                       "[ProgressBar]: %d,%d\r\n"
                       "[PB_Pos]: %d,%d,%d,%d\r\n"
                       "[PBColor_B]: 0x%x\r\n"
                       "[PBColor_E]: 0x%x\r\n"
                       "[WALKMAN]: %d,%d,%d\r\n"
                       "[FULLSCREEN]: %d";

  FSTAT fs;
  if (!fstat(skin_path, SKIN_NAME, &fs))
  {
    int fsize = fs.fsize;
    if (fsize)
    {
      char *buffer = (char *)malloc(fsize + 1);
      memset(buffer, NULL, fsize);
      int file = _fopen(skin_path, SKIN_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
      fread(file, buffer, fsize);
      fclose(file);

      sscanf(buffer, format,
             &Skin->bg_enable, &Skin->bg_x, &Skin->bg_y,
             &Skin->overlay_enable, &Skin->overlay_x, &Skin->overlay_y,

             &Skin->text_artist_enable, &Skin->text_artist_font, &Skin->text_artist_align,
             &Skin->text_artist_x, &Skin->text_artist_y, &Skin->text_artist_w, &Skin->text_artist_h,
             &Skin->text_artist_color,
             &Skin->icon_artist_enable, &Skin->icon_artist_x, &Skin->icon_artist_y,

             &Skin->text_title_enable, &Skin->text_title_font, &Skin->text_title_align,
             &Skin->text_title_x, &Skin->text_title_y, &Skin->text_title_w, &Skin->text_title_h,
             &Skin->text_title_color,
             &Skin->icon_title_enable, &Skin->icon_title_x, &Skin->icon_title_y,

             &Skin->text_album_enable, &Skin->text_album_font, &Skin->text_album_align,
             &Skin->text_album_x, &Skin->text_album_y, &Skin->text_album_w, &Skin->text_album_h,
             &Skin->text_album_color,
             &Skin->icon_album_enable, &Skin->icon_album_x, &Skin->icon_album_y,

             &Skin->text_trackid_enable, &Skin->text_trackid_font, &Skin->text_trackid_align,
             &Skin->text_trackid_x, &Skin->text_trackid_y, &Skin->text_trackid_w, &Skin->text_trackid_h,
             &Skin->text_trackid_color,

             &Skin->text_fulltime_enable, &Skin->text_fulltime_font, &Skin->text_fulltime_align,
             &Skin->text_fulltime_x, &Skin->text_fulltime_y, &Skin->text_fulltime_w, &Skin->text_fulltime_h,
             &Skin->text_fulltime_color,

             &Skin->text_elapsedtime_enable, &Skin->text_elapsedtime_font, &Skin->text_elapsedtime_align,
             &Skin->text_elapsedtime_x, &Skin->text_elapsedtime_y, &Skin->text_elapsedtime_w, &Skin->text_elapsedtime_h,
             &Skin->text_elapsedtime_color,

             &Skin->text_remainingtime_enable, &Skin->text_remainingtime_font, &Skin->text_remainingtime_align,
             &Skin->text_remainingtime_x, &Skin->text_remainingtime_y, &Skin->text_remainingtime_w, &Skin->text_remainingtime_h,
             &Skin->text_remainingtime_color,

             &Skin->text_samplerate_enable, &Skin->text_samplerate_font, &Skin->text_samplerate_align,
             &Skin->text_samplerate_x, &Skin->text_samplerate_y, &Skin->text_samplerate_w, &Skin->text_samplerate_h,
             &Skin->text_samplerate_color,

             &Skin->coverart_enable,
             &Skin->coverart_x, &Skin->coverart_y, &Skin->coverart_w, &Skin->coverart_h,

             &Skin->icon_playpause_enable, &Skin->icon_playpause_x, &Skin->icon_playpause_y,
             &Skin->icon_next_enable, &Skin->icon_next_x, &Skin->icon_next_y,
             &Skin->icon_prev_enable, &Skin->icon_prev_x, &Skin->icon_prev_y,

             &Skin->icon_random_enable, &Skin->icon_random_x, &Skin->icon_random_y,
             &Skin->icon_repeat_enable, &Skin->icon_repeat_x, &Skin->icon_repeat_y,
             &Skin->icon_eq_enable, &Skin->icon_eq_x, &Skin->icon_eq_y,

             &Skin->PB_enable, &Skin->PB_enable_indicator,
             &Skin->PB_x1, &Skin->PB_x2, &Skin->PB_y1, &Skin->PB_y2,
             &Skin->PB_color_b,
             &Skin->PB_color_e,

             &Skin->icon_walkman_enable, &Skin->icon_walkman_x, &Skin->icon_walkman_y,

             &Skin->fullscreen);
      mfree(buffer);
    }
  }
}

void ReloadSkinData(wchar_t *new_skin_path)
{
  ADVPLAYER_DATA *data = GetData();
  Free_SkinData(data->Skin);
  data->Skin = (SKIN_DATA *)malloc(sizeof(SKIN_DATA));
  ReadConfig(data->Skin, new_skin_path);

  if (UnLoadSkinImage(data))
    LoadSkinImage(data, new_skin_path);

  if (data->Skin->fullscreen)
  {
    DispObject_SetStyle(data->MediaPlayer_Audio, UI_OverlayStyle_TrueFullScreen);
    DispObject_WindowSetSize(data->MediaPlayer_NowPlaying, Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main));
  }
  else
  {
    DispObject_SetStyle(data->MediaPlayer_Audio, UI_OverlayStyle_Default);
    DispObject_WindowSetSize(data->MediaPlayer_NowPlaying, Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main) - STATUSBAR_H);
  }
  InvalidateNowPlaying(data->MediaPlayer_Audio);
  InvalidateNowPlaying(data->MediaPlayer_NowPlaying);
}
