#ifndef _MAIN_H_
#define _MAIN_H_

#define DESTROY_GUI(a) if(a) a=GUIObject_Destroy(a)

#define INTERNAL_VAR "OLED"
#define PATCH_OLED_ID L"OLEDEditor_Id"

typedef struct 
{
  u16 timer;
  bool state;
  time_t OnTime;
  time_t OffTime;
  char LED_ID;
}BatTerY_Function;

typedef struct
{
  bool state;
  time_t OnTime;
  time_t OffTime;
  char LED_ID;
}BatTerY_File_Function;

typedef struct _OLED_BOOK : BOOK
{
  GUI* main_menu;
  GUI* sub_menu;
  
  int cursor;
  bool state;
  time_t OnTime;
  time_t OffTime;
  char LED_ID;
}OLED_BOOK;

typedef enum
{
  Item_1=0,
  Item_2,
  Item_3,
  Item_4,
  Item_last,
}MenuItem_t;

typedef enum
{
  LED_Id_Display=0,
  LED_Id_KeyboardLeft=1,
  LED_Id_KeyboardRight=2,
  LED_Id_Joystick=3,
  LED_Id_RedLED=6
} LED_Id_t;

void onTimer( u16 unk, void* );
void BeginTimer( u16 unk, void* );

#endif
