#ifndef _DATA_H_
#define _DATA_H_

#define EMP_NAME "FmRadio"

typedef enum
{
  BACKGROUND_ICN = 0,       //0
  RDS_ACTIVE_ICN,           //1
  RDS_INACTIVE_ICN,         //2
  AF_ON_ICN,                //3
  AF_OFF_ICN,               //4
  MONO_ICN,                 //5
  STEREO_ICN,               //6
  FREQUENCY_INDICATOR_ICN,  //7
  ARROW_LEFT_IDLE_ICN,      //8
  ARROW_LEFT_MANUAL_ICN,    //9
  ARROW_LEFT_AUTOSEEK_ICN,  //10
  ARROW_RIGHT_IDLE_ICN,     //11
  ARROW_RIGHT_MANUAL_ICN,   //12
  ARROW_RIGHT_AUTOSEEK_ICN, //13
  ARROW_UP_IDLE_ICN,        //14
  ARROW_UP_ACTIVE_ICN,      //15
  ARROW_DOWN_IDLE_ICN,      //16
  ARROW_DOWN_ACTIVE_ICN,    //17
  LAST_ICN
} IMAGE_LIST;

typedef struct TEXT_ITEM_DATA
{
  bool state;
  int font;
  uint8_t align;
  uint32_t text_color;
  uint8_t overlay;
  uint32_t ocolor;
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
  uint32_t progress_bcolor;
  uint32_t progress_fcolor;
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

} SETTING_DATA;

typedef struct _FILE_INFO
{
  wchar_t *path;
  wchar_t *name;
  wchar_t *fullpath;
} FILE_INFO;

typedef struct _TEMP_DATA
{
  bool state;
  bool slider;
  bool round;
  uint8_t align;
  uint32_t color1;
  uint32_t color2;
  uint8_t overlay;
  int font;
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

typedef struct _FmRadio_Data
{
  BOOK *FmRadioBook;
  DISP_OBJ *DispObj_FmRadio;

  TEMP_DATA temp;
  SETTING_DATA setting;

  int element;
  bool edit_visual;
  bool text;
  bool rect;
  bool icon;
  int total_fonts, cur_pos;
  int cstep;

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int style_bold;
  int style_italic;
#endif

  //FmRadio_Settings Fm_Settings;

  IMG Image[LAST_ICN];

  TEXTID Channel;
  TEXTID Frequency;
  TEXTID ChannelName;
  TEXTID PSName;

  TEXTID Buffer_Text;
  int scr_w;
  int scr_h;

  wchar_t buf[0xFF];

  //bool IsPotrait;

} FmRadio_Data;

FmRadio_Data *GetData();
void SaveData(bool save, int item);
void LoadData(FmRadio_Data *data);

#endif
