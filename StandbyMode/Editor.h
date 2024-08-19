#ifndef _EDITOR_H_
#define _EDITOR_H_

//==============================================================================

#define FONT_STEP 1
#define MAX_SIZE 100
#define BOLD 1
#define ITALIC 2

enum VisualType
{
  ItemStatusIcon,
  ItemStandartIcon,
  ItemText
};

typedef enum
{
  ITEM_Statusbar,
  
  ITEM_NetworkIcon,
  ITEM_BatteryIcon,
  
  ITEM_MusicWidget,
  
  ITEM_StandbyClock,
  ITEM_StatusClock,
  ITEM_Date,
  ITEM_Weekday,
  ITEM_Alarm,
  ITEM_Profile,
  ITEM_Heap,
  ITEM_Timer,
  ITEM_Call,
  ITEM_Signal,
  ITEM_NetworkName,
  ITEM_Batt,
  ITEM_Charge,
  ITEM_Batttemp,
  ITEM_Systemp,
  ITEM_Phone,
  ITEM_Card,
  ITEM_Radio,
  
  ITEM_Last
} ITEM_LIST;

typedef enum
{
  TextSubItem_State,
  TextSubItem_Mode,
  TextSubItem_TColor,
  TextSubItem_HColor,
  TextSubItem_UColor,
  TextSubItem_Visual,
  TextSubItem_Last,
} TextSubItem;

typedef enum
{
  IconSubItem_State,
  IconSubItem_Visual,
  IconSubItem_Last,
} IconSubItem;

typedef struct _STANDBY_SETTINGS_BOOK : BOOK
{
  GUI_LIST *MainMenu;
  GUI_LIST *SubMenu;
  GUI *Dialog;
  GUI *OptionMenu;
  GUI *ColorEditor;
  
  int selected_item;
  int selected_subitem;
  bool changed;
  char item_type;
  
} STANDBY_SETTINGS_BOOK;

void Create_ItemsEditor();
void SettingsBook_onClose(BOOK* book);
void Clear_TempData(STANDBY_DATA *standby_data);
TEXTID Get_SecondlineVisual(STANDBY_DATA *standby_data);

#endif
