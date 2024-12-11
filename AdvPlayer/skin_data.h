#ifndef _SkinData_h_
#define _SkinData_h_

#define MAX_PATH 252

typedef struct SKIN_CONFIG
{
  wchar_t path[MAX_PATH];
} SKIN_CONFIG;

typedef struct _SKIN_DATA
{
  bool bg_enable;
  uint16_t bg_x;
  uint16_t bg_y;

  bool overlay_enable;
  uint16_t overlay_x;
  uint16_t overlay_y;

  bool text_artist_enable;
  uint8_t text_artist_font;
  uint8_t text_artist_align;
  uint16_t text_artist_x;
  uint16_t text_artist_y;
  uint16_t text_artist_w;
  uint16_t text_artist_h;
  uint32_t text_artist_color;
  bool icon_artist_enable;
  uint16_t icon_artist_x;
  uint16_t icon_artist_y;

  bool text_title_enable;
  uint8_t text_title_font;
  uint8_t text_title_align;
  uint16_t text_title_x;
  uint16_t text_title_y;
  uint16_t text_title_w;
  uint16_t text_title_h;
  uint32_t text_title_color;
  bool icon_title_enable;
  uint16_t icon_title_x;
  uint16_t icon_title_y;

  bool text_album_enable;
  uint8_t text_album_font;
  uint8_t text_album_align;
  uint16_t text_album_x;
  uint16_t text_album_y;
  uint16_t text_album_w;
  uint16_t text_album_h;
  uint32_t text_album_color;
  bool icon_album_enable;
  uint16_t icon_album_x;
  uint16_t icon_album_y;

  bool text_trackid_enable;
  uint8_t text_trackid_font;
  uint8_t text_trackid_align;
  uint16_t text_trackid_x;
  uint16_t text_trackid_y;
  uint16_t text_trackid_w;
  uint16_t text_trackid_h;
  uint32_t text_trackid_color;

  bool text_fulltime_enable;
  uint8_t text_fulltime_font;
  uint8_t text_fulltime_align;
  uint16_t text_fulltime_x;
  uint16_t text_fulltime_y;
  uint16_t text_fulltime_w;
  uint16_t text_fulltime_h;
  uint32_t text_fulltime_color;

  bool text_elapsedtime_enable;
  uint8_t text_elapsedtime_font;
  uint8_t text_elapsedtime_align;
  uint16_t text_elapsedtime_x;
  uint16_t text_elapsedtime_y;
  uint16_t text_elapsedtime_w;
  uint16_t text_elapsedtime_h;
  uint32_t text_elapsedtime_color;

  bool text_remainingtime_enable;
  uint8_t text_remainingtime_font;
  uint8_t text_remainingtime_align;
  uint16_t text_remainingtime_x;
  uint16_t text_remainingtime_y;
  uint16_t text_remainingtime_w;
  uint16_t text_remainingtime_h;
  uint32_t text_remainingtime_color;

  bool text_samplerate_enable;
  uint8_t text_samplerate_font;
  uint16_t text_samplerate_align;
  uint16_t text_samplerate_x;
  uint16_t text_samplerate_y;
  uint16_t text_samplerate_w;
  uint16_t text_samplerate_h;
  uint32_t text_samplerate_color;

  bool coverart_enable;
  uint16_t coverart_x;
  uint16_t coverart_y;
  uint16_t coverart_w;
  uint16_t coverart_h;

  bool icon_playerstate_enable;
  uint16_t icon_playerstate_x;
  uint16_t icon_playerstate_y;

  bool icon_next_enable;
  uint16_t icon_next_x;
  uint16_t icon_next_y;

  bool icon_prev_enable;
  uint16_t icon_prev_x;
  uint16_t icon_prev_y;

  bool icon_random_enable;
  uint16_t icon_random_x;
  uint16_t icon_random_y;

  bool icon_repeat_enable;
  uint16_t icon_repeat_x;
  uint16_t icon_repeat_y;

  bool icon_eq_enable;
  uint16_t icon_eq_x;
  uint16_t icon_eq_y;

  bool PB_enable;
  bool PB_enable_indicator;
  uint16_t PB_x1;
  uint16_t PB_x2;
  uint16_t PB_y1;
  uint16_t PB_y2;
  uint32_t PB_color_b;
  uint32_t PB_color_e;

  bool icon_walkman_enable;
  uint16_t icon_walkman_x;
  uint16_t icon_walkman_y;

  bool viz_enable;
  bool fullscreen;

} SKIN_DATA;

void skin_data_path_save(wchar_t *skin_path);
SKIN_CONFIG *skin_data_config_get(wchar_t *cfg_path, wchar_t *cfg_name);
void skin_data_read(SKIN_DATA *skin_data, wchar_t *skin_path);

#ifndef OLD_PLAYER
void skin_data_reload(AudioPlayerBook *audio_book, wchar_t *new_skin_path);
#endif

wchar_t *skin_images_getname(int index);
void skin_image_unload();
void skin_image_load(wchar_t *skin_path);

#endif
