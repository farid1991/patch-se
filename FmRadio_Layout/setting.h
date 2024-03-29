#ifndef _SETTING_H_
#define _SETTING_H_

enum
{
  ELEM_TEXT,
  ELEM_RECT,
  ELEM_ICON
};

enum
{
  OOM_STATE,
  OOM_ALIGN,
  OOM_LAST
};

typedef enum
{
  ITEM_FREQUENCY = 0,
  ITEM_CHANNEL,
  ITEM_CHANNELNAME,
  ITEM_RDS_DATA,

  ITEM_FREQ_INDICATOR,

  ITEM_RDS_ICN,
  ITEM_AF_ICN,
  ITEM_AUDIO_ICN,
  ITEM_ARROW_LEFT,
  ITEM_ARROW_RIGHT,
  ITEM_ARROW_UP,
  ITEM_ARROW_DOWN,
  ITEM_BACKROUND,

  ITEM_LAST
} ITEM_MAINMENU;

typedef enum
{
  SUBITEM_PB_STATE,
  SUBITEM_PB_SLIDER,
  SUBITEM_PB_ROUND,
  SUBITEM_PB_BCOLOR,
  SUBITEM_PB_FCOLOR,
  SUBITEM_PB_VISUAL,
  SUBITEM_PB_LAST
} SUBITEM_PROGRESSBAR;

typedef enum
{
  SUBITEM_TXT_STATE,
  SUBITEM_TXT_COLOR,
  SUBITEM_TXT_OVERLAY,
  SUBITEM_TXT_ALIGN,
  SUBITEM_TXT_VISUAL,
  SUBITEM_TXT_LAST
} SUBITEM_TXT;

typedef enum
{
  TXT_FREQUENCY,
  TXT_CHANNEL,
  TXT_CHANNELNAME,
  TXT_RDS_DATA,
  TXT_LAST
} ITEM_TXT;

typedef enum
{
  SUBITEM_IMG_STATE,
  SUBITEM_IMG_VISUAL,
  SUBITEM_IMG_LAST
} SUBITEM_IMG;

typedef enum
{
  IMG_RDS_ICN,
  IMG_AF_ICN,
  IMG_AUDIO_ICN,
  IMG_ARROW_LEFT,
  IMG_ARROW_RIGHT,
  IMG_ARROW_UP,
  IMG_ARROW_DOWN,
  IMG_BACKROUND,
  IMG_LAST
} ITEM_IMG;

typedef struct _SETTING_BOOK : BOOK
{
  GUI_LIST *main_menu;
  GUI_LIST *sub_menu;
  GUI_ONEOFMANY *option_menu;
  GUI *gui_question;
  GUI *color_picker;
  int color_type;
  int element;
  int elem_type;
  bool changed;
} SETTING_BOOK;

#endif
