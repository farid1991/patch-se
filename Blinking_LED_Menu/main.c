/*
;Blinking Orange LED while charging
;Stop Charging when battery is full/unplug charger
;v.2 (menu.ml version)
;(c) blacklizard
;(p) farid
*/
/*
;Add to menu.ml
;<element id="OLEDEditor_Id">
;<label type="name"><text>OLED Editor</text>
;</label><link type="internal" />
;</element>
*/

#include "temp\target.h"

#include "..\\include\Types.h"
#include "Lib.h"
#include "main.h"

__thumb void *malloc(int size)
{
  return (memalloc(MINUS_ONE, size, 1, 5, "oled", 0));
}

__thumb void mfree(void *mem)
{
  if (mem)
    memfree(0, mem, "oled", 0);
}

BATT_DATA *Create_BATT_DATA()
{
  BATT_DATA *Data = (BATT_DATA *)malloc(sizeof(BATT_DATA));
  memset(Data, NULL, sizeof(BATT_DATA));
  set_envp(get_bid(current_process()), EMP_NAME, (OSADDRESS)Data);
  return Data;
}

BATT_DATA *Get_BATT_DATA()
{
  BATT_DATA *Data = (BATT_DATA *)get_envp(get_bid(current_process()), EMP_NAME);
  if (Data)
    return Data;
  return Create_BATT_DATA();
}

void LoadData()
{
  int file = _fopen(FILEPATH, L"OLED.bin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    FILEDATA *FData = (FILEDATA *)malloc(sizeof(FILEDATA));
    memset(FData, NULL, sizeof(FILEDATA));
    fread(file, FData, sizeof(FILEDATA));

    BATT_DATA *Data = Get_BATT_DATA();
    Data->state = FData->state;
    Data->OnTime = FData->OnTime;
    Data->OffTime = FData->OffTime;
    Data->LED_ID = FData->LED_ID;

    fclose(file);
    mfree(FData);
  }
}

void SaveData(BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  int file = _fopen(FILEPATH, L"OLED.bin", FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (file >= 0)
  {
    FILEDATA *FData = (FILEDATA *)malloc(sizeof(FILEDATA));
    memset(FData, NULL, sizeof(FILEDATA));
    FData->state = oledBook->state;
    FData->OnTime = oledBook->OnTime;
    FData->OffTime = oledBook->OffTime;
    FData->LED_ID = oledBook->LED_ID;
    fwrite(file, FData, sizeof(FILEDATA));
    fclose(file);
    mfree(FData);
  }
}

void BeginTimer(u16 timerID, LPARAM param)
{
  BATT_DATA *Data = Get_BATT_DATA();
  if (Battery_GetChargingState())
  {
    Illumination_LedID_SetLevel(Data->LED_ID, 100);
    Timer_ReSet(&Data->timerID, Data->OnTime, onTimer, param);
  }
  else
  {
    Data->timerID = 0;
    Illumination_LedID_Off(Data->LED_ID);
  }
}

void onTimer(u16 timerID, LPARAM param)
{
  BATT_DATA *Data = Get_BATT_DATA();
  Illumination_LedID_Off(Data->LED_ID);
  Timer_ReSet(&Data->timerID, Data->OffTime, BeginTimer, param);
}

extern "C" void Start_LED()
{
  LoadData();
  BATT_DATA *Data = Get_BATT_DATA();
  if (Data->state)
    BeginTimer(Data->timerID, NULL);
}

extern "C" void Kill_LED()
{
  BATT_DATA *Data = Get_BATT_DATA();
  if (Data->timerID)
  {
    Timer_Kill(&Data->timerID);
    Data->timerID = 0;
  }
  Illumination_LedID_Off(Data->LED_ID);
}

//=============================================================

void OnBackCreateStringInput(BOOK *book, wchar_t *string, int len)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  FREE_GUI(oledBook->StringInput);
}

void onOKStringInput(BOOK *book, wchar_t *string, int len)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  int value = 0;
  wtoi(string, len, &value);

  if (oledBook->itemID == 1)
    oledBook->LED_ID = value;
  else if (oledBook->itemID == 2)
    oledBook->OnTime = value;
  else if (oledBook->itemID == 3)
    oledBook->OffTime = value;

  ListMenu_SetItemSecondLineText(oledBook->MainMenu, oledBook->itemID, TextID_CreateIntegerID(value));
  FREE_GUI(oledBook->StringInput);
}

int Get_InitialVal(BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  switch (oledBook->itemID)
  {
  case ITEM_2:
    return TextID_CreateIntegerID(oledBook->LED_ID);
  case ITEM_3:
    return TextID_CreateIntegerID(oledBook->OnTime);
  case ITEM_4:
    return TextID_CreateIntegerID(oledBook->OffTime);
  default:
    return TextID_CreateIntegerID(0);
  }
}

TEXTID Get_TitleText(BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  switch (oledBook->itemID)
  {
  case ITEM_2:
    return STR("LED ID");
  case ITEM_3:
    return STR("On Time (ms)");
  case ITEM_4:
    return STR("Off Time (ms)");
  default:
    return EMPTY_TEXTID;
  }
}

void CreateTimeInput(BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  if (oledBook->StringInput = CreateStringInput(oledBook))
  {
    StringInput_SetMode(oledBook->StringInput, IT_INTEGER);
    StringInput_SetMinLen(oledBook->StringInput, 1);
    StringInput_SetMaxLen(oledBook->StringInput, 6);
    StringInput_SetEnableEmptyText(oledBook->StringInput, FALSE);
    StringInput_SetText(oledBook->StringInput, Get_InitialVal(oledBook));
    StringInput_SetFixedText(oledBook->MainMenu, Get_TitleText(oledBook));
    StringInput_SetActionOK(oledBook->StringInput, onOKStringInput);
    StringInput_SetActionBack(oledBook->StringInput, OnBackCreateStringInput);
    GUIObject_Show(oledBook->StringInput);
  }
}

void OnPatchInfo(BOOK *book, GUI *gui)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  CreateMessageBox(EMPTY_TEXTID, STR("Blinking LED v2\n(c) blacklizard\n(p) farid"), 1, 1000, oledBook);
}

void BlinkingOled_Mainpage_onClose(BOOK *book, GUI *gui)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  BATT_DATA *Data = Get_BATT_DATA();
  Data->state = oledBook->state;
  Data->OnTime = oledBook->OnTime;
  Data->OffTime = oledBook->OffTime;
  Data->LED_ID = oledBook->LED_ID;
  SaveData(oledBook);
  Kill_LED();
  if (Battery_GetChargingState())
  {
    Start_LED();
  }
  FreeBook(oledBook);
}

void SetEnabled(BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  if (oledBook->state)
  {
    oledBook->state = FALSE;
    ListMenu_SetItemSecondLineText(oledBook->MainMenu, ITEM_1, DISABLED_TXT);
  }
  else
  {
    oledBook->state = TRUE;
    ListMenu_SetItemSecondLineText(oledBook->MainMenu, ITEM_1, ENABLED_TXT);
  }
}

void BlinkingOled_Mainpage_onSelect(BOOK *book, GUI *gui)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;

  oledBook->itemID = ListMenu_GetSelectedItem(oledBook->MainMenu);
  switch (oledBook->itemID)
  {
  case ITEM_1:
    SetEnabled(oledBook);
    break;
  case ITEM_2:
  case ITEM_3:
  case ITEM_4:
    CreateTimeInput(oledBook);
    break;
  }
}

int BlinkingOled_Mainpage_onMessage(GUI_MESSAGE *msg)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case ITEM_1:
      GUIonMessage_SetMenuItemText(msg, FLASH_TXT);
      if (oledBook->state)
        GUIonMessage_SetMenuItemSecondLineText(msg, ENABLED_TXT);
      else
        GUIonMessage_SetMenuItemSecondLineText(msg, DISABLED_TXT);
      break;
    case ITEM_2:
      GUIonMessage_SetMenuItemText(msg, STR("Led ID"));
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_CreateIntegerID(oledBook->LED_ID));
      break;
    case ITEM_3:
      GUIonMessage_SetMenuItemText(msg, STR("On Time"));
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_CreateIntegerID(oledBook->OnTime));
      break;
    case ITEM_4:
      GUIonMessage_SetMenuItemText(msg, STR("Off Time"));
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_CreateIntegerID(oledBook->OffTime));
      break;
    }
  }
  return 1;
}

int pg_BlinkingOled_Mainpage_EnterEvent(void *data, BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  if (oledBook->MainMenu = CreateListMenu(oledBook, UIDisplay_Main))
  {
    GUIObject_SetTitleIcon(oledBook->MainMenu, TITLE_ICN);
    GUIObject_SetTitleType(oledBook->MainMenu, UI_TitleMode_Small);
    GUIObject_SetTitleText(oledBook->MainMenu, STR("Blinking OLED"));
    GUIObject_SetStyle(oledBook->MainMenu, UI_OverlayStyle_PopupNoFrame);
    ListMenu_SetItemStyle(oledBook->MainMenu, 3);
    ListMenu_SetItemCount(oledBook->MainMenu, ITEM_LAST);
    ListMenu_SetOnMessage(oledBook->MainMenu, BlinkingOled_Mainpage_onMessage);
    ListMenu_SetCursorToItem(oledBook->MainMenu, oledBook->itemID);
    GUIObject_SoftKeys_SetAction(oledBook->MainMenu, ACTION_BACK, BlinkingOled_Mainpage_onClose);
    GUIObject_SoftKeys_SetAction(oledBook->MainMenu, ACTION_SELECT1, BlinkingOled_Mainpage_onSelect);
    GUIObject_SoftKeys_SetAction(oledBook->MainMenu, 0, OnPatchInfo);
    GUIObject_SoftKeys_SetText(oledBook->MainMenu, 0, ABOUT_TXT);
    GUIObject_Show(oledBook->MainMenu);
  }
  return 1;
}

int pg_BlinkingOled_Mainpage_ExitEvent(void *data, BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  FREE_GUI(oledBook->MainMenu);
  return 1;
}

int pg_BlinkingOled_Mainpage_CancelEvent(void *data, BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  FreeBook(oledBook);
  return 1;
}

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_BlinkingOled_Mainpage_CancelEvent,
        RETURN_TO_STANDBY_EVENT, pg_BlinkingOled_Mainpage_CancelEvent,
        NIL_EVENT, NULL};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_BlinkingOled_Mainpage_EnterEvent,
        PAGE_EXIT_EVENT, pg_BlinkingOled_Mainpage_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC BlinkingOled_Base_Page = {"BlinkingOrangeLED_Base_Page", 0, bk_msglst_base};
const PAGE_DESC BlinkingOled_Main_Page = {"BlinkingOrangeLED_Main_Page", 0, bk_msglst_main};

void BlinkingOled_onBookDestroy(BOOK *book)
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)book;
  oledBook->state = 0;
  oledBook->OnTime = 0;
  oledBook->OffTime = 0;
  oledBook->LED_ID = 0;
  FREE_GUI(oledBook->MainMenu);
  FREE_GUI(oledBook->StringInput);
}

extern "C" __thumb void CreateOLED_Menu()
{
  BlinkingOledBook *oledBook = (BlinkingOledBook *)malloc(sizeof(BlinkingOledBook));
  memset(oledBook, NULL, sizeof(BlinkingOledBook));
  if (!CreateBook(oledBook, BlinkingOled_onBookDestroy, &BlinkingOled_Base_Page, "BlinkingOled_Book", NO_BOOK_ID, NULL))
  {
    mfree(oledBook);
  }
  else
  {
    LoadData();
    BATT_DATA *Data = Get_BATT_DATA();
    oledBook->state = Data->state;
    oledBook->OnTime = Data->OnTime;
    oledBook->OffTime = Data->OffTime;
    oledBook->LED_ID = Data->LED_ID;
    BookObj_GotoPage(oledBook, &BlinkingOled_Main_Page);
  }
}

__thumb void OLED_Menu(DYNAMIC_MENU_ELEMENT *DME)
{
  switch (DynamicMenu_GetElementMsg(DME))
  {
  case DYNAMIC_MENU_onCall:
    CreateOLED_Menu();
    break;
  case DYNAMIC_MENU_onText:
    DynamicMenu_SetElement_SecondLineText(DME, STR("Blinking OLED"));
    break;
  }
}

#pragma diag_suppress = Pe177
__root const int Patch_OLED @ "Patch_OLED" = (int)DYNMENU_ID;
__root const int Patch_Run_OLED @ "Patch_Run_OLED" = (int)OLED_Menu;
