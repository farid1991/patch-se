#ifndef _DATA_H_
#define _DATA_H_

#define REFRESH_TIMER 1000

#define STATUS_ICN_ROW_MAX 16
#define STATUS_ICN_COLUMN_MAX 16
#define STATUS_ICN_STEP 1

#define EMP_NAME "STANDBY_DATA"

#define FILE_NAME L"standbydata.bin"
#define FILE_PATH L"/tpa/system/settings"

enum APPWIDGET_POS
{
  POS_1,
  POS_2,
  POS_3,
  LAST_POS
};

typedef struct TEXT_ITEM_DATA
{
  bool state;
  int mode;
  int align;
  int t_color;
  int h_color;
  int highlight;
  int font_size;
  int XPos;
  int YPos;
  int Width;
  int Height;
  int MaxHeight;
  bool underline;
  int u_color;
} TEXT_ITEM_DATA;

typedef struct ICON_ITEM_DATA
{
  bool state;
  int XPos;
  int YPos;
} ICON_ITEM_DATA;

typedef struct STATUS_ICN_DATA
{
  bool state;
  int align;
  int XPos;
  int YPos;
} STATUS_ICN_DATA;

typedef struct PROGRESS_ITEM_DATA
{
  bool state;
  int XPos;
  int YPos;
} MUSIC_ITEM_DATA;

typedef struct _SETTING_DATA
{
  TEXT_ITEM_DATA standbyclock;
  TEXT_ITEM_DATA statusclock;
  TEXT_ITEM_DATA date;
  TEXT_ITEM_DATA weekday;
  TEXT_ITEM_DATA alarm;
  TEXT_ITEM_DATA profile;
  TEXT_ITEM_DATA heap;
  TEXT_ITEM_DATA timer;
  TEXT_ITEM_DATA calltime;
  TEXT_ITEM_DATA signal;
  TEXT_ITEM_DATA opname;
  TEXT_ITEM_DATA battery;
  TEXT_ITEM_DATA charge;
  TEXT_ITEM_DATA batttemp;
  TEXT_ITEM_DATA systemp;
  TEXT_ITEM_DATA phone;
  TEXT_ITEM_DATA card;
  TEXT_ITEM_DATA radio;

  ICON_ITEM_DATA music;

  ICON_ITEM_DATA net_icn;
  ICON_ITEM_DATA batt_icn;

  STATUS_ICN_DATA status;

} SETTINGS_DATA;

typedef struct _TEMP_DATA
{
  bool state;
  int mode;
  int align;
  int t_color;
  int h_color;
  int highlight;
  int font_size;
  int XPos;
  int YPos;
  int Width;
  int Height;
  int MaxHeight;
  bool underline;
  int u_color;
} TEMP_DATA;

typedef struct IMG
{
  IMAGEID ImageID;
  uint16_t ImageHandle;
} IMG;

typedef struct
{
  char count;
  bool flag;
  bool edit_mode;
  bool edit_visual;
  bool edit_text;
  bool edit_icon;
  bool edit_status;
  int selected_item;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int total_fonts, cur_pos;
  int cstep;
  char style;
  bool style_bold;
  bool style_italic;
#endif
  int font_style;

  uint16_t refresh_timer;

  LIST *status_list;
  bool status_was_changed;
  IMAGEID status_bar[STATUS_ICN_ROW_MAX][STATUS_ICN_COLUMN_MAX];
  int status_icn_count[STATUS_ICN_ROW_MAX];
  int row_count;

  IMAGEID CurrentIconIDNet;
  IMAGEID CurrentIconIDBatt;

  bool IsCharging;
  int CallEnd;
  bool CallState;
  DISP_OBJ *StatusIndication;

  uint16_t scr_w;
  uint16_t scr_h;

  SETTINGS_DATA settings;
  TEMP_DATA temp;

  bool widget_mode;
  int widget_pos;
} STANDBY_DATA;

STANDBY_DATA *Get_StandbyData();
void SaveData(bool save, int item);
void LoadData(STANDBY_DATA *standby_data);

#endif
