#ifndef Data_h
#define Data_h

#define EMP_NAME "MP_EMP"

enum MP_NOWPLAYING_IMAGE
{
  BACKGROUND_ICN,
  MP_NOCOVER_ICN,
  MP_REFLECT_ICN,
  MP_OVERLAY_ICN,
  MP_ARTIST_ICN,
  MP_TITLE_ICN,
  MP_ALBUM_ICN,
  MP_PLAY_ICN,
  MP_PAUSE_ICN,
  MP_NEXT_ICN,
  MP_PREV_ICN,
  MP_FF_ICN,
  MP_RW_ICN,
  MP_MODE_RANDOM_ICN,
  MP_MODE_REPEAT_ICN,
  MP_EQ_BASS_ICN,
  MP_EQ_MEGABASS_ICN,
  MP_EQ_MANUAL_ICN,
  MP_EQ_NORMAL_ICN,
  MP_EQ_TREBLEBOOST_ICN,
  MP_EQ_VOICE_ICN,
  MP_PB_INDICATOR_ICN,
  WALKMAN_ICN,
  MP_LAST_IMG
};

typedef struct SKINCONFIG
{
  wchar_t path[256];
} SKINCONFIG;

typedef struct FILELIST
{
  void *next;
  int is_folder;
  wchar_t *fullname;
  wchar_t *name;
} FILELIST;

typedef struct _SKIN_DATA
{
  int bg_enable;
  int bg_x;
  int bg_y;

  int overlay_enable;
  int overlay_x;
  int overlay_y;

  int text_artist_enable;
  int text_artist_font;
  int text_artist_align;
  int text_artist_x;
  int text_artist_y;
  int text_artist_w;
  int text_artist_h;
  unsigned int text_artist_color;
  int icon_artist_enable;
  int icon_artist_x;
  int icon_artist_y;

  int text_title_enable;
  int text_title_font;
  int text_title_align;
  int text_title_x;
  int text_title_y;
  int text_title_w;
  int text_title_h;
  unsigned int text_title_color;
  int icon_title_enable;
  int icon_title_x;
  int icon_title_y;

  int text_album_enable;
  int text_album_font;
  int text_album_align;
  int text_album_x;
  int text_album_y;
  int text_album_w;
  int text_album_h;
  unsigned int text_album_color;
  int icon_album_enable;
  int icon_album_x;
  int icon_album_y;

  int text_trackid_enable;
  int text_trackid_font;
  int text_trackid_align;
  int text_trackid_x;
  int text_trackid_y;
  int text_trackid_w;
  int text_trackid_h;
  unsigned int text_trackid_color;

  int text_fulltime_enable;
  int text_fulltime_font;
  int text_fulltime_align;
  int text_fulltime_x;
  int text_fulltime_y;
  int text_fulltime_w;
  int text_fulltime_h;
  unsigned int text_fulltime_color;

  int text_elapsedtime_enable;
  int text_elapsedtime_font;
  int text_elapsedtime_align;
  int text_elapsedtime_x;
  int text_elapsedtime_y;
  int text_elapsedtime_w;
  int text_elapsedtime_h;
  unsigned int text_elapsedtime_color;

  int text_remainingtime_enable;
  int text_remainingtime_font;
  int text_remainingtime_align;
  int text_remainingtime_x;
  int text_remainingtime_y;
  int text_remainingtime_w;
  int text_remainingtime_h;
  unsigned int text_remainingtime_color;

  int text_samplerate_enable;
  int text_samplerate_font;
  int text_samplerate_align;
  int text_samplerate_x;
  int text_samplerate_y;
  int text_samplerate_w;
  int text_samplerate_h;
  unsigned int text_samplerate_color;

  int coverart_enable;
  int coverart_x;
  int coverart_y;
  int coverart_w;
  int coverart_h;

  int icon_playerstate_enable;
  int icon_playerstate_x;
  int icon_playerstate_y;

  int icon_next_enable;
  int icon_next_x;
  int icon_next_y;

  int icon_prev_enable;
  int icon_prev_x;
  int icon_prev_y;

  int icon_random_enable;
  int icon_random_x;
  int icon_random_y;

  int icon_repeat_enable;
  int icon_repeat_x;
  int icon_repeat_y;

  int icon_eq_enable;
  int icon_eq_x;
  int icon_eq_y;

  int PB_enable;
  int PB_enable_indicator;
  int PB_x1;
  int PB_x2;
  int PB_y1;
  int PB_y2;
  unsigned int PB_color_b;
  unsigned int PB_color_e;

  int icon_walkman_enable;
  int icon_walkman_x;
  int icon_walkman_y;

  int fullscreen;
} SKIN_DATA;

typedef struct _IMG
{
  IMAGEID id;
  u16 handle;
} IMG;

typedef struct _ADVPLAYER_DATA
{
  DISP_OBJ *MediaPlayer_Audio;
  DISP_OBJ_NOWPLAYING *MediaPlayer_NowPlaying;
  SKIN_DATA *Skin;
  FILELIST *fltop;

  bool IsPlaying;
  char PlayerState;
  int SampleRate;
  int fullscreen;
  TEXTID text_id;

  TRACK_DESC* CurrentTrack; 

  IMAGEID CoverArt;
  bool HasCover;
  int CoverSize;

  IMG skin_image[MP_LAST_IMG];
  wchar_t buffer[64];
  wchar_t SkinPath[256];

  bool firstStart;
} ADVPLAYER_DATA;

ADVPLAYER_DATA *InitData();
ADVPLAYER_DATA *GetData();
void FreeData(ADVPLAYER_DATA *);

void SaveCurrentSkinPath(wchar_t *walkman_skin);
wchar_t *LoadCurrentSkinPath();
void ReadConfig(SKIN_DATA *Skin, wchar_t *skin_path);
void ReloadSkinData(ADVPLAYER_DATA *data, wchar_t *new_skin_path);
void Free_SkinData(SKIN_DATA *Skin);
wchar_t *getSampleRate(int index);
void GetCoverArt(ADVPLAYER_DATA *);
void GetMediaPlayerState(BOOK *book);

#endif
