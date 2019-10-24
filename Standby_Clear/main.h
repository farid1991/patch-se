#ifndef _MAIN_H_
#define _MAIN_H_

#define STANDBY_SETTINGS_ID  (L"Standby_Set_Id")

#define FREE_GUI(a) if(a) a=GUIObject_Destroy(a)

#define Operator3               0x0
#define Operator1               0x1
#define SearchFlight            0x2
#define Prof                    0x4
#define Operator2               0x6
#define NoSignal                0x7
#define Notes                   0x9
#define BigClock                0xB
#define SmallClock              0xC
#define Date                    0xD
#define Alarm                   0xE
#define Timer                   0xF
#define CallTime                0x10
#define Shift                   0x11
#define W580_Accel              0x12

typedef struct _StandbyManager_Book : BOOK
{
  GUI* main_menu;
  GUI* sub_menu;
  
  int itemID;
  int fileitem;
}StandbyManager_Book;

#ifdef W580_R8BE001 
#define FILE_COUNT 15
#else
#define FILE_COUNT 14
#endif

typedef struct{
  char item[FILE_COUNT];
  char day_en;
}FILE_DATA;

#endif
