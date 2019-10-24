#include "..\\include\Types.h"
#include "cfg_items.h"
#include "StatusIndication.h"

#pragma diag_suppress=Pe177

#define TIME_CFG_NAME     L"Time"
#define TIME2_CFG_NAME    L"Time 2"
#define DATE_CFG_NAME     L"Date"
#define DAY_CFG_NAME      L"Day"
#define ALARM_CFG_NAME    L"Alarm clock"
#define PROFILE_CFG_NAME  L"Profile name"
#define HEAP_CFG_NAME     L"Heap info"
#define TIMER_CFG_NAME    L"Timer"
#define CALL_CFG_NAME     L"Call time"
#define SIGNAL_CFG_NAME   L"Signal strenght"
#define OPERATOR_CFG_NAME L"Operator name"
#define BATT_CFG_NAME     L"Battery percent"
#define CHARGE_CFG_NAME   L"Charge. current"
#define SYSTEMP_CFG_NAME  L"System temp."
#define BATTTEMP_CFG_NAME L"Battery temp."
#define NET_ICN_CFG_NAME  L"Signal icon"
#define BATT_ICN_CFG_NAME L"Battery icon"
#define STATUS_CFG_NAME   L"Statusrow icon"
#define PHONE_CFG_NAME    L"Phone memory"
#define CARD_CFG_NAME     L"Memory card"
//#define STATUSBG_CFG_NAME L"Statusrow BG"
#define MUSIC_CFG_NAME    L"Music Player"
#define RADIO_CFG_NAME    L"FM Radio"   

#define SHOW_MSG          "Show"
#define FONT_MSG          "Font"
#define COLOR_MSG         "Text color"
#define BORDER_MSG        "Border Color"
#define HIGHLIGHT_MSG     "Border"
#define HIGHLIGHT_NO_MSG  "No"
#define HIGHLIGHT_FULLV1_MSG  "Full v1"
#define HIGHLIGHT_FULLV2_MSG  "Full v2"
#define HIGHLIGHT_SHADOW_MSG  "Shadow"
#define ALIGN_MSG         "Alignment"
#define LEFT_MSG          "Left"
#define RIGHT_MSG         "Right"
#define CENTER_MSG        "Center"
#define MODE_MSG          "Format"
#define FIRST_MSG         "Show first?"
#define REDUCED_MSG       "Short"
#define FULL_MSG          "Full"
#define SEC_MSG           "Second"
#define DBM_MSG           "Show dBm"
#define FILL_BY_ROW_MSG   "Fill on page."
#define ROW_MAX_MSG       "Max. lines"
#define COL_MAX_MSG       "Max. columns"
#define CHARGINGONLY_MSG  "Current charge"
#define MASSAGE_MSG       "Text"
#define TYPE_MSG          "Memory info"
#define FREE_MSG          "Free"
#define USED_MSG          "Used"
#define FORMAT_MSG        "Format"
#define PERCENT_MSG       "Percent"
#define KB_MSG            "Kb"
#define MB_MSG            "Mb"
#define GB_MSG            "Gb"
#define FILL_MSG          "Fill in"
#define RL_MSG            "left to right"
#define LR_MSG            "right to left"

#define TITLE_MSG         "Title"
#define ARTIST_MSG        "Artist"
#define FREQ_MSG          "Frequency"
#define NAME_MSG          "Name"

#define TITLE_ONLY_MSG        "Title only"
#define ARTIST_ONLY_MSG       "Artist only"
#define TITLE_AND_ARTIST_MSG  "Title n' Artist"

#define FREQ_ONLY_MSG        "Freq. only"
#define NAME_ONLY_MSG        "Name only"
#define FREQ_AND_NAME_MSG    "Freq and Name"

#define TEXT_ITEM_CFG(num, name, show, font, color, border, align, x, y) \
  __root const ITEM_TXT_DATA cfg##num = {name,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     show,  \
      CFG_FONT,FONT_MSG,0,0,         font,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   color, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  border,\
      CFG_CBOX,ALIGN_MSG,0,3,        align, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     x, \
                                     y, \
                                     y, \
                                     0, \
                                     0}

#define ICON_ITEM_CFG(num, name, show, x, y) \
  __root const ITEM_IMG_DATA cfg##num = {name,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     show,  \
                                     x, \
                                     y, \
                                     y, \
                                     0, \
                                     0}

  __root const ITEM_TIME_DATA cfg0 = {TIME_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1,  \
      CFG_CHECKBOX,SEC_MSG,0,0,      1,  \
      CFG_FONT,FONT_MSG,0,0,         FONT_TIME,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000,\
      CFG_CBOX,ALIGN_MSG,0,3,        TIME_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     TIME_X, \
                                     TIME_Y, \
                                     TIME_Y, \
                                     0, \
                                     0};

  __root const ITEM_TIME_DATA cfg1 = {TIME2_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1,  \
      CFG_CHECKBOX,SEC_MSG,0,0,      0,  \
      CFG_FONT,FONT_MSG,0,0,         FONT_TIME2,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000,\
      CFG_CBOX,ALIGN_MSG,0,3,        TIME2_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     TIME2_X, \
                                     TIME2_Y, \
                                     TIME2_Y, \
                                     0, \
                                     0};

  TEXT_ITEM_CFG(2, DATE_CFG_NAME, 1, FONT_DATE, 0x90FFFFFF, 0xB0000000, DATE_ALIGN, DATE_X, DATE_Y);

  __root const ITEM_DAY_DATA cfg3 = {DAY_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1, \
      CFG_CBOX,MODE_MSG,0,2,         1, REDUCED_MSG,FULL_MSG, \
      CFG_FONT,FONT_MSG,0,0,         FONT_DAY,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,        DAY_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     DAY_X, \
                                     DAY_Y, \
                                     DAY_Y, \
                                     0, \
                                     0};

  TEXT_ITEM_CFG(4, ALARM_CFG_NAME, 1, FONT_ALARM, 0x90FFFFFF, 0xB0000000, ALARM_ALIGN, ALARM_X, ALARM_Y);
  TEXT_ITEM_CFG(5, PROFILE_CFG_NAME, 1, FONT_PROFILE, 0x90FFFFFF, 0xB0000000, PROFILE_ALIGN, PROFILE_X, PROFILE_Y);

  __root const ITEM_HEAP_DATA cfg6 = {HEAP_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1, \
      CFG_CBOX,FORMAT_MSG,0,2,       0, KB_MSG, MB_MSG,  \
      CFG_FONT,FONT_MSG,0,0,         FONT_HEAP,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,        HEAP_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     HEAP_X, \
                                     HEAP_Y, \
                                     HEAP_Y, \
                                     0, \
                                     0};
    
  TEXT_ITEM_CFG(7, TIMER_CFG_NAME, 1, FONT_TIMER, 0x90FFFFFF, 0xB0000000, TIMER_ALIGN, TIMER_X, TIMER_Y);
  TEXT_ITEM_CFG(8, CALL_CFG_NAME, 1, FONT_CALL, 0x90FFFFFF, 0xB0000000, CALL_ALIGN, CALL_X, CALL_Y);

  __root const ITEM_SIGNAL_DATA cfg9 = {SIGNAL_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1,  \
      CFG_CHECKBOX,DBM_MSG,0,0,      0,  \
      CFG_FONT,FONT_MSG,0,0,         FONT_SIGNAL,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,        SIGNAL_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     SIGNAL_X, \
                                     SIGNAL_Y, \
                                     SIGNAL_Y, \
                                     0, \
                                     0};
  
  TEXT_ITEM_CFG(10, OPERATOR_CFG_NAME, 1, FONT_OPERATOR, 0x90FFFFFF, 0xB0000000, OPERATOR_ALIGN, OPERATOR_X, OPERATOR_Y);
  TEXT_ITEM_CFG(11, BATT_CFG_NAME, 1, FONT_BATT, 0x90FFFFFF, 0xB0000000, BATT_ALIGN, BATT_X, BATT_Y);
  TEXT_ITEM_CFG(12, CHARGE_CFG_NAME, 1, FONT_CHARGE, 0x90FFFFFF, 0xB0000000, CHARGE_ALIGN, CHARGE_X, CHARGE_Y);

  __root const ITEM_BATTTEMP_DATA cfg13 = {BATTTEMP_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,          1,  \
      CFG_CHECKBOX,CHARGINGONLY_MSG,0,0,  1,  \
      CFG_FONT,FONT_MSG,0,0,              FONT_BATTTEMP,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,         3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,        0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,       0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,             BATTTEMP_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                          BATTTEMP_X, \
                                          BATTTEMP_Y, \
                                          BATTTEMP_Y, \
                                          0, \
                                          0};

  TEXT_ITEM_CFG(14, SYSTEMP_CFG_NAME, 1, FONT_TEMP, 0x90FFFFFF, 0xB0000000, TEMP_ALIGN, TEMP_X, TEMP_Y);

  __root const ITEM_MEMINFO_DATA cfg15 = {PHONE_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,          1, \
      CFG_CBOX,TYPE_MSG,0,2,              0, FREE_MSG,USED_MSG, \
      CFG_CBOX,FORMAT_MSG,0,3,            1, PERCENT_MSG,MB_MSG,GB_MSG, \
      CFG_UTF16_STRING,MASSAGE_MSG,0,15,  L"Phone: ", \
      CFG_FONT,FONT_MSG,0,0,              FONT_PHONE, \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,         3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,        0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,       0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,             PHONE_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                          PHONE_X, \
                                          PHONE_Y, \
                                          PHONE_Y, \
                                          0, \
                                          0};

  __root const ITEM_MEMINFO_DATA cfg16 = {CARD_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,          1, \
      CFG_CBOX,TYPE_MSG,0,2,              0, FREE_MSG,USED_MSG, \
      CFG_CBOX,FORMAT_MSG,0,3,            1, PERCENT_MSG,MB_MSG,GB_MSG, \
      CFG_UTF16_STRING,MASSAGE_MSG,0,15,  L"Card:  ", \
      CFG_FONT,FONT_MSG,0,0,              FONT_CARD,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,         3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,        0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,       0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,             CARD_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                          CARD_X, \
                                          CARD_Y, \
                                          CARD_Y, \
                                          0, \
                                          0};

  ICON_ITEM_CFG(17, NET_ICN_CFG_NAME, 1, NET_ICON_X, NET_ICON_Y);
  ICON_ITEM_CFG(18, BATT_ICN_CFG_NAME, 1, BATT_ICON_X, BATT_ICON_Y);

  __root const ITEM_STATUS_DATA cfg19 = {STATUS_CFG_NAME,  \
      CFG_CHECKBOX,SHOW_MSG,0,0,                    1, \
      CFG_UINT,ROW_MAX_MSG,1,STATUS_ICN_ROW_MAX,    1, \
      CFG_UINT,COL_MAX_MSG,1,STATUS_ICN_COLUMN_MAX, 8, \
      CFG_CHECKBOX,FILL_BY_ROW_MSG,0,0,             1, \
      CFG_CBOX,FILL_MSG,0,2,                        0, LR_MSG,RL_MSG, \
      CFG_CBOX,ALIGN_MSG,0,3,                       STATUS_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                                    STATUS_X, \
                                                    STATUS_Y, \
                                                    STATUS_Y, \
                                                    0, \
                                                    0};
  //ICON_ITEM_CFG(20, STATUSBG_CFG_NAME , 1, 0, 0);
  
  __root const ITEM_MUSIC_DATA cfg20 = {MUSIC_CFG_NAME, \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1, \
      CFG_CBOX,MODE_MSG,0,3,         1, TITLE_AND_ARTIST_MSG,TITLE_ONLY_MSG,ARTIST_ONLY_MSG, \
      CFG_CBOX,FIRST_MSG,0,2,        1, ARTIST_MSG,TITLE_MSG, \
      CFG_FONT,FONT_MSG,0,0,         FONT_MUSIC,  \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,        MUSIC_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     MUSIC_X, \
                                     MUSIC_Y, \
                                     MUSIC_Y, \
                                     0, \
                                     0};
  
  __root const ITEM_RADIO_DATA cfg21 = {RADIO_CFG_NAME, \
      CFG_CHECKBOX,SHOW_MSG,0,0,     1, \
      CFG_CBOX,MODE_MSG,0,3,         1, FREQ_AND_NAME_MSG,FREQ_ONLY_MSG,NAME_ONLY_MSG, \
      CFG_CBOX,FIRST_MSG,0,2,        1, FREQ_MSG,NAME_MSG, \
      CFG_FONT,FONT_MSG,0,0,         FONT_RADIO, \
      CFG_CBOX,HIGHLIGHT_MSG,0,4,    3, HIGHLIGHT_NO_MSG,HIGHLIGHT_FULLV1_MSG,HIGHLIGHT_FULLV2_MSG,HIGHLIGHT_SHADOW_MSG,  \
      CFG_COLOR_INT,COLOR_MSG,0,0,   0x90FFFFFF, \
      CFG_COLOR_INT,BORDER_MSG,0,0,  0xB0000000, \
      CFG_CBOX,ALIGN_MSG,0,3,        RADIO_ALIGN, LEFT_MSG,RIGHT_MSG,CENTER_MSG, \
                                     RADIO_X, \
                                     RADIO_Y, \
                                     RADIO_Y, \
                                     0, \
                                     0};
