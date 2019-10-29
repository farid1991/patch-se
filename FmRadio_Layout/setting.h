#ifndef _SETTING_H_
#define _SETTING_H_

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
  ITEM_ADDITIONAL,
  ITEM_LAST
}ITEM_SETTING;

typedef enum
{
  TYPE_IMAGE = 0,
  TYPE_THEME,
  TYPE_COLOR
}BACKGROUND_TYPE;

#define SETTING_COUNT ITEM_LAST
#define TEXT_COUNT 5
#define IMAGE_COUNT 2
#define PROGRESS_COUNT 6
#define BACKGROUND_COUNT 3
#define ADDITIONAL_COUNT 3

typedef struct _SETTING_BOOK : BOOK
{
  GUI_LIST* gui_set;
  GUI_LIST* gui_elem;
  GUI* gui_question;
  GUI_ONEOFMANY* gui_oom;
  GUI* color;
  int color_type;
  
  int element;
  bool change;
}SETTING_BOOK;

void FmRadio_Setting(BOOK* book, GUI* gui);

#endif
