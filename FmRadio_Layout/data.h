#ifndef _DATA_H_
#define _DATA_H_

#include "..\\include\book\FmRadio_Book.h"

#define FILE_PATH L"/usb/other/ZBin/Config/FmRadio"
#define FILE_NAME L"FMRadio_Display.cfg"

//#define EMP_NAME "DBP_emp"

#define IMG_COUNT 18

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
  bool state;
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
  TEXT_ITEM_DATA frequency;
  TEXT_ITEM_DATA channel;
  TEXT_ITEM_DATA channel_name;
  TEXT_ITEM_DATA RDS_data;
  
  PROGRESS_ITEM_DATA freq_indicator;

  IMG_ITEM_DATA rds_icn;
  IMG_ITEM_DATA af_icn;
  IMG_ITEM_DATA audio_icn;
  
  IMG_ITEM_DATA arrow_left;
  IMG_ITEM_DATA arrow_right;
  IMG_ITEM_DATA arrow_up;
  IMG_ITEM_DATA arrow_down;
    
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
  char activate1;
  char activate2;
  char activate3;
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

typedef struct NEW_KEY
{
  bool left;
  bool right;
  bool up;
  bool down;
} NEW_KEY;

typedef struct _FmRadio_Data
{
  BOOK* FmRadioBook;
  DISP_OBJ* DispObj_FmRadio;

  TEMP_DATA temp;
  SETTING_DATA setting;
  
  int element;
  bool edit_visual;
  bool text;
  bool rect;
  int total_fonts, cur_pos;
  int cstep;
  
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  IFont* pFont;
  int style_bold;
  int style_italic;
#endif
  
  //FmRadio_Settings Fm_Settings;
  
  IMG Image[IMG_COUNT];
  
  TEXTID Channel;
  TEXTID Frequency;
  TEXTID ChannelName;
  TEXTID PSName;
  
  TEXTID Buffer_Text;
  
  wchar_t buf[64];
  
  //bool IsPotrait;
  
} FmRadio_Data;

FmRadio_Data* Get_Data();
void SaveData(bool save, int item);

//extern "C"
void LoadData();

#endif
