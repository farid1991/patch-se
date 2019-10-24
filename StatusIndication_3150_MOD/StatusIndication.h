#ifndef _STATUSINDICATION_H
#define _STATUSINDICATION_H

#define INVALIDATE_ALL_TIME     1000
#define MEMINFO_UPDATE_MAX_CNT  60

#define STATUS_ICN_ROW_MAX    64
#define STATUS_ICN_COLUMN_MAX 64
#define STATUS_ICN_STEP       1

#define MYDATAVARNAME "standbydata" 

#define MYDATAFILE    L"standbydata.bin"
#define MYDATAPATH    L"/tpa/system/settings"

#define ALARM 1
#define TIMER 2
#define CALLS 3

#define FREE_GUI(a) if (a) { GUIObject_Destroy(a); a = NULL; }

__thumb void * malloc (int size);
__thumb void mfree (void * mem);


enum music_app_t
{
  MUSIC_TITLE_ARTIST= 0,
  MUSIC_TITLE_ONLY,
  MUSIC_ARTIST_ONLY
};

enum fm_freq_name_t
{
  FM_FREQ_NAME = 0,
  FM_FREQ_ONLY,
  FM_NAME_ONLY
};

enum meminfo_t 
{
  FREE_MEM = 0,
  USED_MEN
};

enum memformat_t
{
  MEM_PERCENT = 0,
  MEM_MB,
  MEM_GB
};

enum align_t
{
  LEFT = 0,
  RIGHT,
  CENTER
};

typedef struct
{
  IMAGEID iconID;
} STATUS_ITEM_LIST;

typedef struct
{
  char  type;
  char  days[7];
} WEEK;

typedef struct
{
  int x;
  int y;
  int y_max;
  int h;
  int w;
} cfg_t;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_text_t;

typedef struct
{
  wchar_t name[16];
  cfg_text_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_TXT_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_isSec;
  int isSec;
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_time_t;

typedef struct
{
  wchar_t name[16];
  cfg_time_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_TIME_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_mode;
  int mode;
  CFG_CBOX_ITEM cfgcbox_mode[2];
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_day_t;

typedef struct
{
  wchar_t name[16];
  cfg_day_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_DAY_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_format;
  int format;
  CFG_CBOX_ITEM cfgcbox_format[2];
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_heap_t;

typedef struct
{
  wchar_t name[16];
  cfg_heap_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_HEAP_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_show_dbm;
  int show_dbm;
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_signal_t;

typedef struct
{
  wchar_t name[16];
  cfg_signal_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_SIGNAL_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_in_charge;
  int in_charge;
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_batttemp_t;

typedef struct
{
  wchar_t name[16];
  cfg_batttemp_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_BATTTEMP_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_type;
  int type;
  CFG_CBOX_ITEM cfgcbox_type[2];
  CFG_HDR cfghdr_format;
  int format;
  CFG_CBOX_ITEM cfgcbox_format[3];
  CFG_HDR cfghdr_msg;
  wchar_t msg[16];
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_meminfo_t;

typedef struct
{
  wchar_t name[16];
  cfg_meminfo_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_MEMINFO_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
}cfg_img_t;

typedef struct
{
  wchar_t name[16];
  cfg_img_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_IMG_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_row;
  unsigned int row_max;
  CFG_HDR cfghdr_col;
  unsigned int column_max;
  CFG_HDR cfghdr_fill;
  int fill_by_row;
  CFG_HDR cfghdr_fill_direction;
  int fill;
  CFG_CBOX_ITEM cfgcbox_fill_direction[2];
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_status_t;

typedef struct
{
  wchar_t name[16];
  cfg_status_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_STATUS_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_format;
  int format;
  CFG_CBOX_ITEM cfgcbox_format[3];
  CFG_HDR cfghdr_first;
  int first;
  CFG_CBOX_ITEM cfgcbox_first[2];
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_music_t;

typedef struct
{
  wchar_t name[16];
  cfg_music_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_MUSIC_DATA;

typedef struct
{
  CFG_HDR cfghdr_show;
  int show;
  CFG_HDR cfghdr_format;
  int format;
  CFG_CBOX_ITEM cfgcbox_format[3];
  CFG_HDR cfghdr_first;
  int first;
  CFG_CBOX_ITEM cfgcbox_first[2];
  CFG_HDR cfghdr_font;
  unsigned int font;
  CFG_HDR cfghdr_highlight;
  int highlight;
  CFG_CBOX_ITEM cfgcbox_highlight[4];
  CFG_HDR cfghdr_color;
  unsigned int color;
  CFG_HDR cfghdr_border;
  unsigned int border;
  CFG_HDR cfghdr_align;
  int align;
  CFG_CBOX_ITEM cfgcbox_align[3];
}cfg_radio_t;

typedef struct
{
  wchar_t name[16];
  cfg_radio_t cfg;
  int x;
  int y;
  int y_max;
  int h;
  int w;
}ITEM_RADIO_DATA;

typedef struct
{
  wchar_t *name;
  int *show;
  unsigned int *font;
  int *highlight;
  unsigned int *color;
  unsigned int *border;
  int *align;
  int *x;
  int *y;
  int *y_max;
  int *h;
  int *w;
  wchar_t TstImgID;
}ITEM_DATA;

typedef struct
{
  wchar_t icn;
  int height;
  int txt_offset;
  int icn_offset;
}ITEM_ICN_DATA;

enum item_t 
{
  TIME_ITEM = 0,
  TIME2_ITEM,
  DATE_ITEM,
  DAY_ITEM,
  ALARM_ITEM,
  PROFILE_ITEM,
  HEAP_ITEM,
  TIMER_ITEM,
  CALL_ITEM,
  SIGNAL_ITEM,
  OPERATOR_ITEM,
  BATT_ITEM,
  CHARGE_ITEM,
  BATTTEMP_ITEM,
  TEMP_ITEM,
  PHONEINFO_ITEM,
  CARDINFO_ITEM,
  NETICON_ITEM,
  BATICON_ITEM,
  STATUS_ITEM,
  //STATUSBG_ITEM,
  MUSIC_ITEM,
  RADIO_ITEM,
  LAST_ITEM
};

typedef struct
{
  ITEM_TIME_DATA time;
  ITEM_TIME_DATA time2;
  ITEM_TXT_DATA date;
  ITEM_DAY_DATA day;
  ITEM_TXT_DATA alarm;
  ITEM_TXT_DATA profile;
  ITEM_HEAP_DATA heap;
  ITEM_TXT_DATA timer;
  ITEM_TXT_DATA call;
  ITEM_SIGNAL_DATA signal;
  ITEM_TXT_DATA oper;
  ITEM_TXT_DATA batt;
  ITEM_TXT_DATA charge;
  ITEM_BATTTEMP_DATA batttemp;
  ITEM_TXT_DATA temp;
  ITEM_MEMINFO_DATA phone;
  ITEM_MEMINFO_DATA card;
  ITEM_IMG_DATA neticon;
  ITEM_IMG_DATA baticon;
  ITEM_STATUS_DATA status;
  //ITEM_IMG_DATA statusbg;
  ITEM_MUSIC_DATA music;
  ITEM_RADIO_DATA radio;
}ITEMS_DATA;

typedef struct
{
  ITEMS_DATA items_cfg;
  ITEM_DATA items[LAST_ITEM];
  ITEM_ICN_DATA items_icons[LAST_ITEM];
  int cur_item;
  int cnt;
  int flag;
  int CallEnd;
  int EditMode;
  u16 pTimer;
  int memcnt;
  TEXTID phone_memId;
  TEXTID card_memId;
  LIST * status_list;
  wchar_t status_bar[STATUS_ICN_ROW_MAX][STATUS_ICN_COLUMN_MAX];
  int status_icn_cnt[STATUS_ICN_ROW_MAX];
  int rowcnt;
  int status_was_changed;
  wchar_t CurrentIconIDNet;
  wchar_t CurrentIconIDBatt;
  
  //IMAGEID StatusRowBG;
  
  int isCharging;
  DISP_OBJ* Display_dobj;
}MY_DATA;

MY_DATA *get_mydata();
void LiteUpdateParams(MY_DATA *mydata);
void SetCurrentItem(int item);
int GetCurrentItem();
wchar_t *GetItemName(int item);
void *GetItemCfg(int item);
int GetItemCfgSize(int item);

#endif //_STATUSINDICATION_H
