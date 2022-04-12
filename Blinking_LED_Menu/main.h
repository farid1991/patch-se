#ifndef _MAIN_H_
#define _MAIN_H_

#define EMP_NAME "BATT_EMP"
#define DYNMENU_ID L"OLEDEditor_Id"

#define MINUS_ONE 0xFFFFFFFF

enum ITEMID
{
  ITEM_1,
  ITEM_2,
  ITEM_3,
  ITEM_4,
  ITEM_LAST
};

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

typedef struct
{
  u16 timerID;
  bool state;
  int OnTime;
  int OffTime;
  uint8_t LED_ID;
} BATT_DATA;

typedef struct
{
  bool state;
  int OnTime;
  int OffTime;
  uint8_t LED_ID;
} FILEDATA;

typedef struct _BlinkingOledBook : BOOK
{
  GUI *MainMenu;
  GUI *StringInput;
  uint8_t itemID;
  bool state;
  int OnTime;
  int OffTime;
  uint8_t LED_ID;
} BlinkingOledBook;

void onTimer(u16 timerID, LPARAM param);

#endif
