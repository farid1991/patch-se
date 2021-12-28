#ifndef _DATA_H_
#define _DATA_H_

#define FILE_PATH L"/usb/other/ZBin/Config/DBPlayer"
#define FILE_NAME L"DBPlayer.cfg"

#define EMP_NAME "DBP_emp"

#define IMG_COUNT 10

//typedef struct GUI GUI_DBP;

typedef struct TEXT_ITEM_DATA
{
  bool state;
  char align;
  uint32_t tcolor;
  uint32_t ocolor;
  char overlay;
  uint16_t font;
  RECT coord;
} TEXT_ITEM_DATA;

typedef struct IMG_ITEM_DATA
{
  uint8_t state;
  POINT pos;
} IMG_ITEM_DATA;

typedef struct PROGRESS_ITEM_DATA
{
  bool state;
  bool slider;
  bool round;
  uint32_t progress_bcolor;
  uint32_t progress_fcolor;
  RECT progress_rect;
} PROGRESS_ITEM_DATA;

typedef struct _SETTING_DATA
{
  TEXT_ITEM_DATA artist;
  TEXT_ITEM_DATA title;
  TEXT_ITEM_DATA album;
  TEXT_ITEM_DATA year;
  TEXT_ITEM_DATA genre;
  TEXT_ITEM_DATA ext;
  TEXT_ITEM_DATA time_t;
  TEXT_ITEM_DATA time_e;
  TEXT_ITEM_DATA time_r;
  TEXT_ITEM_DATA bitrate;
  TEXT_ITEM_DATA samplerate;
  TEXT_ITEM_DATA audiooutput;

  PROGRESS_ITEM_DATA time;
  PROGRESS_ITEM_DATA volume;

  bool cover;
  RECT cover_rect;

  IMG_ITEM_DATA frame;
  IMG_ITEM_DATA artist_icn;
  IMG_ITEM_DATA title_icn;
  IMG_ITEM_DATA album_icn;
  IMG_ITEM_DATA playerstate_icn;

  IMG_ITEM_DATA background;
  uint32_t background_color;

  bool screen;
  bool soft;
#ifndef DB3350
  bool animation;
#endif
} SETTING_DATA;

typedef struct _FILE_INFO
{
  wchar_t *path;
  wchar_t *name;
  wchar_t *fullpath;
} FILE_INFO;

typedef struct _TEMP_DATA
{
  uint8_t activate1;
  uint8_t activate2;
  uint8_t activate3;
  uint8_t align;
  uint32_t color1;
  uint32_t color2;
  uint8_t overlay;
  uint8_t font;
  int x1;
  int y1;
  int x2;
  int y2;
} TEMP_DATA;

typedef struct _IMG
{
  IMAGEID ID;
  uint16_t Handle;
} IMG;

typedef struct _DBP_DATA
{
  BOOK *book;
  GUI *gui;
  IMMEPlayer *pIMMEPlayer;
#ifdef DB3350
  MME_DATA *pMMEData;
#endif
  GUI *time_input;

  SETTING_DATA setting;

  FILE_INFO file;
  TEMP_DATA temp;
  IMG Image[IMG_COUNT];

  int tagger;
  bool paused;
  bool mute;
  int element;
  bool edit_visual;
  bool text;
  bool rect;
  bool icon;

  int total_fonts, cur_pos;

  bool IsCoverArt;
  int CoverSize;
  IMAGEID CoverArtID;

  TMMETime track_time;
  int full_track_time;
  TMMETime elapsed_time;
  int full_elapsed_time;

  uint32_t SampleRate;
  uint8_t AudioOutput;
  uint8_t fileFormatType;

  wchar_t buf[64];

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int style_bold;
  int style_italic;
#endif
} DBP_DATA;

DBP_DATA *GetData();
void DeleteData();
void SaveData(bool save, int item);
void LoadData(DBP_DATA *);

#endif
