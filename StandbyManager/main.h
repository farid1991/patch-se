#ifndef _MAIN_H_
#define _MAIN_H_

#define STANDBY_SETTINGS_ID (L"Standby_Set_Id")
#define FILE_NAME L"StandbyCfg.bin"

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

// #define Operator3 0x0
// #define Operator1 0x1
// #define SearchFlight 0x2
// #define Prof 0x4
// #define Operator2 0x6
// #define NoSignal 0x7
// #define Notes 0x9
// #define BigClock 0xB
// #define SmallClock 0xC
// #define Date 0xD
// #define Alarm 0xE
// #define Timer 0xF
// #define CallTime 0x10
// #define Shift 0x11
// #define W580_Accel 0x12

const TEXTID items_text[] =
    {
        TEXTID_OFF,
        TEXTID_OP3,
        TEXTID_OP2,
        TEXTID_OP1,
        TEXTID_SF,
        TEXTID_NO,
        TEXTID_PROF,
        TEXTID_NOTES,
        TEXTID_BIG_TIME,
        TEXTID_TIME,
        TEXTID_DATE,
        TEXTID_ALARM,
        TEXTID_TIMER,
        TEXTID_TALK,
        TEXTID_SHIFT,
#ifdef W580_R8BE001
        TEXTID_ACCEL
#endif
};

const IMAGEID iconID[] =
    {
        ICONID_OP3,
        ICONID_OP2,
        ICONID_OP1,
        ICONID_SF,
        ICONID_NO,
        ICONID_PROF,
        ICONID_NOTES,
        ICONID_BIG_TIME,
        ICONID_TIME,
        ICONID_DATE,
        ICONID_ALARM,
        ICONID_TIMER,
        ICONID_TALK,
        ICONID_SHIFT,
#ifdef W580_R8BE001
        ICONID_ACCEL
#endif
};

const TEXTID weekdays[7] =
    {
        TEXTID_1,
        TEXTID_2,
        TEXTID_3,
        TEXTID_4,
        TEXTID_5,
        TEXTID_6,
        TEXTID_7};

#define Item_UnSelected 0xFE
#define Item_NotSelected 0xFF

enum StatusIndication_Item_t
{
  Item_Operator3,
  Item_Operator1,
  Item_SearchAndFlightmode,
  Item_UnUsed0x3,
  Item_ProfileName,
  Item_UnUsed0x5,
  Item_Operator2,
  Item_NoSignal,
  Item_UnUsed0x8,
  Item_Notes,
  Item_UnUsed0xA,
  Item_BigClock,
  Item_SmallClock,
  Item_Date,
  Item_Alarm,
  Item_Timer,
  Item_CallTime,
  Item_Shift,
#ifdef W580_R8BE001
  Item_W580_Accel,
#endif
  Item_Last
};

typedef struct _StandbyManager_Book : BOOK
{
  GUI *MainMenu;
  GUI *SubMenu;

  int itemID;
  int fileitem;
} StandbyManager_Book;

#ifdef W580_R8BE001
#define FILE_COUNT 15
#else
#define FILE_COUNT 14
#endif

typedef struct
{
  char item[FILE_COUNT];
  char day_en;
} FILE_DATA;

#endif
