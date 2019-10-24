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
  color_t tcolor;
  color_t ocolor;
  char overlay;
  Uint16_t font;
  RECT coord;
} TEXT_ITEM_DATA;

typedef struct IMG_ITEM_DATA
{
  char state;
  POINT pos;
} IMG_ITEM_DATA;

typedef struct PROGRESS_ITEM_DATA
{
  bool state;
  bool slider;
  bool round;
  color_t progress_bcolor;
  color_t progress_fcolor;
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
  color_t background_color;
  
  bool screen;
  bool soft;
  bool animation;
} SETTING_DATA;

typedef struct _FILE_INFO
{
  wchar_t* path;
  wchar_t* name;
  wchar_t* fullpath;
} FILE_INFO;

typedef struct _TEMP_DATA
{
  bool activate1;
  bool activate2;
  bool activate3;
  char align;
  color_t color1;
  color_t color2;
  char overlay;
  char font;
  Int16_t x1;
  Int16_t y1;
  Int16_t x2;
  Int16_t y2;
} TEMP_DATA;

typedef struct _IMG
{
  IMAGEID ID;
  Uint16_t Handle;
} IMG;

typedef struct _DBP_DATA
{
  BOOK* book;
  GUI* gui;
  IMMEPlayer* pIMMEPlayer;
  
  GUI* gui_time;
  
  SETTING_DATA setting;
  
  FILE_INFO file;
  TEMP_DATA temp;
  IMG Image[IMG_COUNT];
  
  int tagger;
  bool pause;
  bool mute;
  int element;
  bool edit_visual;
  bool text;
  bool rect;
  
  int total_fonts, cur_pos;
  
  bool IsCoverArt;
  IMAGEID CoverArtID;
  
  TMMETime track_time;
  int full_track_time;
  TMMETime elapsed_time;
  int full_elapsed_time;
  
  int SampleRate;
  int AudioOutput;
  
  wchar_t buf[64];
} DBP_DATA;

DBP_DATA* GetData();
void DeleteData();
void SaveData(bool save, int item);
void LoadData(DBP_DATA* data);

#endif
