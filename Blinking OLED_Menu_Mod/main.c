/*
;G502 SW-R1FA037
;Blinking LED while charging
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

;Types of entry: 1 - integer; 2 - 'char'; 3 - 'wchar'; 4 - binary
;0x1219FE9D - void Registry_Write(char* name, int type, int size, void* data)
;0x1219FF11 - void Registry_Read(char* name, int type, int size, void* data)
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"


__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF,size,1,5,"oled",0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,"oled",0);
}

BatTerY_Function* Create_BatTerY_Function()
{
  BatTerY_Function* Data = (BatTerY_Function*)malloc(sizeof(BatTerY_Function));
  memset(Data, NULL, sizeof(BatTerY_Function));
  /*
  Data->timer=NULL;
  Data->state=NULL;
  Data->Interval=NULL;
  Data->OnTime=NULL;
  Data->OffTime=NULL;
  Data->ID=NULL;
  wstrcpy(Data->title,L"Undefined");
  */
  set_envp(NULL, INTERNAL_VAR, (OSADDRESS)Data);
  return Data;
}

BatTerY_Function* Get_BatTerY_Function()
{
  BatTerY_Function* Data = (BatTerY_Function*)get_envp(NULL, INTERNAL_VAR);
  if (Data) return Data;
  return Create_BatTerY_Function();
}

BatTerY_Function* LoadData()
{
  int f;
  if ( (f=_fopen( (wchar_t*)PATH, L"OLED.bin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    BatTerY_File_Function *FileData = (BatTerY_File_Function*)malloc(sizeof(BatTerY_File_Function));
    memset(FileData,NULL,sizeof(BatTerY_File_Function));
    fread( f, FileData, sizeof(BatTerY_File_Function) );
    
    BatTerY_Function* Data = Get_BatTerY_Function();
    Data->state = FileData->state;
    Data->OnTime = FileData->OnTime;
    Data->OffTime = FileData->OffTime;
    Data->LED_ID = FileData->LED_ID;
    
    fclose(f);
    mfree(FileData);
    return Data;
  }
  return NULL;
  /*
  BatTerY_Function *Data = Get_BatTerY_Function();
  Registry_Read("oled_state", RegistryType_INT, 4, &Data->state);
  Registry_Read("oled_onTime", RegistryType_INT, 4, &Data->OnTime);
  Registry_Read("oled_offtime", RegistryType_INT, 4, &Data->OffTime);
  Registry_Read("oled_ID", RegistryType_INT, 4, &Data->LED_ID);
  */
}

void SaveData(OLED_BOOK* mbk)
{
  int f;
  if (( f=_fopen( (wchar_t*)PATH, L"OLED.bin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >=0 )
  {
    BatTerY_File_Function* FileData = (BatTerY_File_Function*)malloc(sizeof(BatTerY_File_Function));
    memset (FileData,NULL,sizeof(BatTerY_File_Function));
    FileData->state = mbk->state;
    FileData->OnTime = mbk->OnTime;
    FileData->OffTime = mbk->OffTime;
    FileData->LED_ID = mbk->LED_ID;
    fwrite(f,FileData,sizeof(BatTerY_File_Function));
    fclose (f);
    mfree(FileData);
  }
}

void BeginTimer( u16 timerID, void* unk )
{
  BatTerY_Function *Data = Get_BatTerY_Function();
  if (Charging_GetState())
  {
    Illumination_LedID_SetLevel(Data->LED_ID,100);
    Timer_ReSet(&Data->timer,Data->OnTime,MKTIMERPROC(onTimer),0);
  }
  else
  {
    Data->timer = 0;
    Illumination_LedID_Off(Data->LED_ID);
  }
}

void onTimer( u16 timerID, void* unk )
{ 
  BatTerY_Function *Data = Get_BatTerY_Function();
  Illumination_LedID_Off(Data->LED_ID);
  Timer_ReSet(&Data->timer,Data->OffTime,MKTIMERPROC(BeginTimer),0);
}

extern "C"
void StartOLED()
{
  BatTerY_Function* Data = LoadData();
  if(Data->state) BeginTimer(Data->timer, 0);
}

extern "C"
void Kill_LED()
{
  BatTerY_Function *Data = Get_BatTerY_Function();
  if(Data->timer)
  {
    Timer_Kill(&Data->timer);
    Data->timer = NULL;
  }
  Illumination_LedID_Off(Data->LED_ID);
}

//=============================================================

TEXTID Get_Time_Text(int item)
{
  TEXTID txt;
  if(item==Item_3) txt = TextID_Create("On Time",ENC_LAT1,0xFF);
  else if(item==Item_4) txt = TextID_Create("Off Time",ENC_LAT1,0xFF);
  return txt;
}

void SubMenu_PrevAction ( BOOK* book, GUI* gui )
{
  OLED_BOOK* mbk = (OLED_BOOK*) book;
  DESTROY_GUI(mbk->sub_menu);
}

void Book_CancelAction ( BOOK* book, GUI* gui )
{
  //FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void OnOkCreateStringInput( BOOK* book, wchar_t* string, int len )
{
  OLED_BOOK* mbk = (OLED_BOOK*) book;

  int ReturnData = 0;
  wtoi( string, len, &ReturnData);

  if(mbk->cursor==Item_3)
  {
    mbk->OnTime = ReturnData;
    //ListMenu_SetItemSecondLineText( mbk->main_menu, Item_3,  TextID_CreateIntegerID(mbk->OnTime) );
  }
  else if(mbk->cursor==Item_4)
  {
    mbk->OffTime = ReturnData;
    //ListMenu_SetItemSecondLineText( mbk->main_menu, Item_4,  TextID_CreateIntegerID(mbk->OffTime) );
  }
  ListMenu_SetItemSecondLineText( mbk->main_menu, mbk->cursor,  TextID_CreateIntegerID(ReturnData) );
  DESTROY_GUI(mbk->sub_menu);
}

void CreateTimeInput( BOOK * book  )
{
  OLED_BOOK* mbk = (OLED_BOOK*) book;

  int InitialVal = 0;
  if(mbk->cursor==Item_3) InitialVal = mbk->OnTime;
  else if(mbk->cursor==Item_4) InitialVal = mbk->OffTime;
  
  mbk->sub_menu = CreateStringInputVA(0,
                                       (char*)VAR_BOOK,mbk,
                                       (char*)VAR_HEADER_TEXT,Get_Time_Text(mbk->cursor),
                                       (char*)VAR_STRINP_MODE,IT_INTEGER,
                                       (char*)VAR_STRINP_NEW_LINE,1,
                                       (char*)VAR_STRINP_MAX_LEN,6,
                                       (char*)VAR_STRINP_MIN_LEN,1,
                                       (char*)VAR_STRINP_SET_INT_VAL,InitialVal,
                                       (char*)VAR_OK_PROC,OnOkCreateStringInput,0);
  GUIObject_SoftKeys_SetAction(mbk->sub_menu, ACTION_BACK, SubMenu_PrevAction);
  GUIObject_SoftKeys_SetAction(mbk->sub_menu, ACTION_LONG_BACK, Book_CancelAction );
}

TEXTID Get_LedID_Text(int item)
{
  TEXTID txt;
  if(item==0) txt = DISPLAY_TXT;
  else if(item==1 || item==2) txt = KEYBOARD_TXT;
  else if(item==3) txt = TextID_Create("Joystick",ENC_LAT1,0xFF);
  else if(item==4 || item==6) txt = TextID_Create("Red LED",ENC_LAT1,0xFF);
  return txt;
}

int onCallback_OOM(GUI_MESSAGE* msg)
{
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg,Get_LedID_Text(item));
  }
  return(1);
}

void LEDEditor_SelectAction( BOOK* book, GUI* gui )
{
  OLED_BOOK* mbk = (OLED_BOOK*) book;
  int item = OneOfMany_GetSelected(mbk->sub_menu);
  
  if(item==0) mbk->LED_ID=LED_Id_Display;
  else if(item==1) mbk->LED_ID=LED_Id_KeyboardLeft;
  else if(item==2) mbk->LED_ID=LED_Id_KeyboardRight;
  else if(item==3) mbk->LED_ID=LED_Id_Joystick;
  else if(item==4) mbk->LED_ID=LED_Id_RedLED;

  ListMenu_SetItemSecondLineText( mbk->main_menu, mbk->cursor,  Get_LedID_Text(mbk->LED_ID) );
  
  DESTROY_GUI(mbk->sub_menu);
}

int GetChecked(int id)
{
  if(id<4) return id;
  else return 4;
}

void CreateLED_Editor( BOOK* book )
{
  OLED_BOOK* mbk = (OLED_BOOK*)book;
  mbk->sub_menu = CreateOneOfMany(mbk);
  OneOfMany_SetItemCount( mbk->sub_menu, 5 );
  OneOfMany_SetOnMessage( mbk->sub_menu, onCallback_OOM );
  OneOfMany_SetChecked( mbk->sub_menu, GetChecked(mbk->LED_ID) );
  GUIObject_SetStyle( mbk->sub_menu, UI_OverlayStyle_Default);
  GUIObject_SetTitleText( mbk->sub_menu, LED_TXT );
  GUIObject_SoftKeys_SetAction( mbk->sub_menu, ACTION_SELECT1, LEDEditor_SelectAction );
  GUIObject_SoftKeys_SetAction( mbk->sub_menu, ACTION_BACK, SubMenu_PrevAction );
  GUIObject_SoftKeys_SetAction( mbk->sub_menu, ACTION_LONG_BACK, Book_CancelAction );
  GUIObject_Show( mbk->sub_menu );
}

int onCallback_List(GUI_MESSAGE * msg)
{
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    TEXTID first_text = EMPTY_TEXTID;
    TEXTID second_text = EMPTY_TEXTID;
    
    OLED_BOOK* mbk = (OLED_BOOK*)GUIonMessage_GetBook(msg);
    switch(GUIonMessage_GetCreatedItemIndex(msg))
    {
    case Item_1:
      first_text = FLASH_TXT;
      if(mbk->state) second_text = ON_TXT;
      else second_text = OFF_TXT;
      break;
    case Item_2:
      first_text = LED_TXT;
      second_text = Get_LedID_Text(mbk->LED_ID);
      break;
    case Item_3:
      first_text = Get_Time_Text(Item_3);
      second_text = TextID_CreateIntegerID(mbk->OnTime);
      break;
    case Item_4:
      first_text = Get_Time_Text(Item_4);
      second_text = TextID_CreateIntegerID(mbk->OffTime);
      break;
    }
    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text );
  }
  return(1);
}

void OnPatchInfo( BOOK * book, GUI * gui )
{
  MessageBox( EMPTY_TEXTID, TextID_Create("Blinking Orange LED v2.x\n(c) blacklizard\n(e) farid",ENC_LAT1,0xFF), NULL, 1, 0, book );
}

void onClose_List( BOOK* book, GUI * gui )
{
  OLED_BOOK* mbk = (OLED_BOOK*)book;
  SaveData(mbk);
  /*
  BatTerY_Function* Data = Get_BatTerY_Function();
  Registry_Write("oled_state", RegistryType_INT, sizeof(int), &Data->state);
  Registry_Write("oled_onTime", RegistryType_INT, sizeof(int), &Data->OnTime);
  Registry_Write("oled_offtime", RegistryType_INT, sizeof(int), &Data->OffTime);
  Registry_Write("oled_ID", RegistryType_INT, sizeof(int), &Data->LED_ID);
  */
  if (Charging_GetState()) 
  {
    Kill_LED();
    StartOLED();
  }
  FreeBook(book);
}

void SetEnabled(OLED_BOOK* mbk)
{
  TEXTID txt;
  if(mbk->state)
  {
    mbk->state = FALSE;
    //ListMenu_SetItemSecondLineText( mbk->main_menu, mbk->cursor, OFF_TXT );
    txt = OFF_TXT;
  }
  else // if(Data->state == 0)
  {
    mbk->state = TRUE;
    //ListMenu_SetItemSecondLineText( mbk->main_menu, mbk->cursor, ON_TXT );
    txt = ON_TXT;
  }
  ListMenu_SetItemSecondLineText( mbk->main_menu, mbk->cursor, txt );
}

void onEnter_List( BOOK* book, GUI* gui )
{
  OLED_BOOK* mbk = (OLED_BOOK*)book;
  
  mbk->cursor = ListMenu_GetSelectedItem(mbk->main_menu);
  switch(mbk->cursor)
  {
  case Item_1: 
    SetEnabled(mbk);
    break;
  case Item_2:
    CreateLED_Editor(mbk);
    break;
  case Item_3:
  case Item_4:
    CreateTimeInput(mbk);
    break;
  }
}

int MainPageOnCreate( void* r0, BOOK* book)
{
  OLED_BOOK* mbk = (OLED_BOOK*)book;
  mbk->main_menu = CreateListMenu(mbk,UIDisplay_Main);
  //GUIObject_SetTitleIcon( mbk->main_menu, TITLE_ICN );
  GUIObject_SetTitleType( mbk->main_menu, UI_TitleMode_Small );
  GUIObject_SetTitleText( mbk->main_menu, TextID_Create("Blinking OLED",ENC_LAT1,0xFF) );
  GUIObject_SetStyle( mbk->main_menu, UI_OverlayStyle_Default );
  ListMenu_SetItemStyle( mbk->main_menu, 3 );
  ListMenu_SetItemCount( mbk->main_menu, Item_last );
  ListMenu_SetOnMessage( mbk->main_menu, onCallback_List );
  ListMenu_SetCursorToItem( mbk->main_menu, mbk->cursor );

  GUIObject_SoftKeys_SetAction( mbk->main_menu, ACTION_BACK, onClose_List );
  GUIObject_SoftKeys_SetAction( mbk->main_menu, ACTION_SELECT1, onEnter_List );
  GUIObject_SoftKeys_SetAction( mbk->main_menu, ACTION_LONG_BACK, Book_CancelAction );

  GUIObject_SoftKeys_SetAction( mbk->main_menu, 0, OnPatchInfo );
  GUIObject_SoftKeys_SetText( mbk->main_menu, 0, ABOUT_TXT ); 

  GUIObject_Show( mbk->main_menu );
  return (1);
}

/*
int MainPageOnClose(void * r0, BOOK * bk)
{
  OLED_BOOK* mbk = (OLED_BOOK*)bk;
  DESTROY_GUI(mbk->main_menu);
  DESTROY_GUI(mbk->sub_menu);
  return 1;
}
*/
int Cancel_BasePage(void *r0, BOOK *book)
{
  FreeBook(book);
  return(1);
}

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT,            Cancel_BasePage,
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT,               NULL
};

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT,  MainPageOnCreate,
  //PAGE_EXIT_EVENT,   MainPageOnClose,
  NIL_EVENT,         NULL
};

const PAGE_DESC BlinkingOrangeLED_Base_Page = {"BlinkingOLED_Base_Page",0,bk_msglst_base};
const PAGE_DESC BlinkingOrangeLED_Main_Page = {"BlinkingOLED_Main_Page",0,bk_msglst_main};

void OLED_Destroy (BOOK* book)
{
}

extern "C"
__thumb void SettingsMenu()
{
  BatTerY_Function *Data = LoadData();
  
  OLED_BOOK* mbk = (OLED_BOOK*) malloc(sizeof(OLED_BOOK));
  memset( mbk, NULL, sizeof(mbk));
  if (!CreateBook(mbk,OLED_Destroy,&BlinkingOrangeLED_Base_Page,"BlinkingOLED_Book",-1,0)) mfree(mbk);
  {
    mbk->cursor = NULL;
    mbk->state = Data->state;
    mbk->OnTime = Data->OnTime;
    mbk->OffTime = Data->OffTime;
    mbk->LED_ID = Data->LED_ID;
    BookObj_GotoPage(mbk,&BlinkingOrangeLED_Main_Page);
  }
}

__thumb void OLED_Editor(DYNAMIC_MENU_ELEMENT *DME)
{
  switch(DynamicMenu_GetElementMsg(DME))
  {
  case MENU_onCall:
    SettingsMenu();
    break;
  case MENU_onText:
    BatTerY_Function *Data = LoadData();
    TEXTID text;
    if(Data->state) text = Get_LedID_Text(Data->LED_ID);
    else text = OFF_TXT;
    DynamicMenu_SetElement_SecondLineText(DME, text);
    break;
  }
}

#pragma diag_suppress=Pe177
__root const int Patch_OLED @ "Patch_OLED" =(int)PATCH_OLED_ID;
__root const int Patch_Run_OLED @ "Patch_Run_OLED" =(int)OLED_Editor;
