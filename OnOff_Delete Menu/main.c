/*
;G502 R1FA037
;On/Off Delete
;(!) Add to menu.ml element id="DeleteProtection_Id"
;v.3.0(menu.ml)
;(c) ZEN
;(e) farid
*/
#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"



__thumb void * malloc (int size)
{
#ifdef DB2020  
  return(memalloc(0,size,1,5,"del",0));
#elif A2
  return(memalloc(0xFFFFFFFF,size,1,5,"del",0));
#else
  return(memalloc(size,1,5,"del",0));
#endif
}

__thumb void mfree (void * mem)
{
#ifdef DB2020  
  if (mem) memfree(0, mem,"del",0);
#elif A2
  if (mem) memfree(0, mem,"del",0);
#else
  memfree(mem,"del",0);
#endif
}

DeLeTe_Function *Create_DeLeTe_Function()
{
  DeLeTe_Function *Data = (DeLeTe_Function *)malloc(sizeof(DeLeTe_Function));
  memset(Data, 0, sizeof(DeLeTe_Function));
  Data->gen_del = 0;
  Data->mar_del = 0;
  Data->dir_del = 0;
  Data->del_pas = 0;
  set_envp(get_bid(current_process()), INTERNAL_VAR, (OSADDRESS)Data);
  return Data;
}

DeLeTe_Function *Get_DeLeTe_Function()
{
  DeLeTe_Function *Data = (DeLeTe_Function*)get_envp(get_bid(current_process()), INTERNAL_VAR);
  if (Data) return Data;
  return Create_DeLeTe_Function();
}

void LoadData()
{
  int f;
  if ( (f=_fopen( (wchar_t*)PATH,L"Delete.bin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    DeLeTe_File_Function *FileData = (DeLeTe_File_Function*) malloc(sizeof(DeLeTe_File_Function));
    memset( FileData, 0, sizeof(DeLeTe_File_Function) );
    fread( f, FileData, sizeof(DeLeTe_File_Function) );
    
    DeLeTe_Function *Data = Get_DeLeTe_Function();
    Data->gen_del = FileData->gen_del;
    Data->mar_del = FileData->mar_del;
    Data->dir_del = FileData->dir_del;
      
    fclose (f);
    mfree(FileData);
  }
}

int SetText()
{
  int text[3] = { ON_OFF_TXT,SPACE,DELETE_TXT };
  return TextID_Create(text,5,3);
}

int SetText2(int ID)
{
  int text[3];
  text[0] = PASSWORD_TXT;
  text[1] = SPACE;
  if (ID==0) text[2] = OFF_TXT;
  else text[2] = ON_TXT;
  return TextID_Create(text,5,3);
}

extern  "C"
int Generic(void *r0, BOOK *bk)
{
  LoadData();
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  
  if(Data->gen_del==1)
    MessageBox( EMPTY_TEXTID, CANT_DELETE_TXT, 0, 1, 2500, 0 );
  else 
    pg_Generic_Delete(r0,bk);

  return (1);
}

extern  "C"
int MarkSeveral(void *r0, BOOK *bk)
{
  LoadData();
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  
  if(Data->mar_del==1) 
    MessageBox( EMPTY_TEXTID, CANT_DELETE_TXT, 0, 1, 2500, 0 );
  else
    pg_MarkSeveral_Delete(r0,bk);
  
  return (1);
}

extern  "C"
int Directory(void *r0, BOOK *bk)
{
  LoadData();
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  
  if(Data->dir_del==1) 
    MessageBox( EMPTY_TEXTID, CANT_DELETE_DIR_TXT, 0, 1, 2500, 0 );  
  else 
    pg_Directory_Delete(r0,bk);
  
  return (1);
}

int onMessageList(GUI_MESSAGE * msg)
{
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  if ( GUIonMessage_GetMsg(msg) == 1 )
  {
    int item=GUIonMessage_GetCreatedItemIndex(msg);
    if(item==0)
    {
      if(Data->del_pas==0) GUIonMessage_SetItemDisabled(msg,0);
      else GUIonMessage_SetItemDisabled(msg,1);
      
      GUIonMessage_SetMenuItemText(msg,FILE_TXT);
      if(Data->gen_del == 1) GUIonMessage_SetMenuItemSecondLineText( msg, TURN_ON_TXT );
      else if(Data->gen_del == 0) GUIonMessage_SetMenuItemSecondLineText( msg, TURN_OFF_TXT );
    }
    if(item==1)
    {
      if(Data->del_pas==0) GUIonMessage_SetItemDisabled(msg,0);
      else GUIonMessage_SetItemDisabled(msg,1);
      
      GUIonMessage_SetMenuItemText(msg,MARK_TXT);
      if(Data->mar_del == 1) GUIonMessage_SetMenuItemSecondLineText( msg, TURN_ON_TXT );
      else if(Data->mar_del == 0) GUIonMessage_SetMenuItemSecondLineText( msg, TURN_OFF_TXT );
    }
    if(item==2)
    {
      if(Data->del_pas==0) GUIonMessage_SetItemDisabled(msg,0);
      else GUIonMessage_SetItemDisabled(msg,1);
      
      GUIonMessage_SetMenuItemText(msg,DIR_TXT);
      if(Data->dir_del == 1) GUIonMessage_SetMenuItemSecondLineText( msg, TURN_ON_TXT );
      else if(Data->dir_del == 0) GUIonMessage_SetMenuItemSecondLineText( msg, TURN_OFF_TXT );
    }
  }
  return(1);
}

void onAuthorInfo( BOOK* bk, GUI* gui )
{
  MessageBox( EMPTY_TEXTID, TextID_Create("On/Off Delete\nv3.0\n(c) ZEN\n(e) farid",6,0xFF),0, 1, 0, bk );
}

void onLongBack( BOOK* bk, GUI* gui )
{
  FreeBook(bk);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}
                
void onBackList( BOOK* bk, GUI* gui )
{
  int f;
  if ( (f=_fopen((wchar_t*)PATH,L"Delete.bin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE,0)) >=0 )
  {
    DeLeTe_File_Function *FileData = (DeLeTe_File_Function*)malloc(sizeof(DeLeTe_File_Function));
    memset( FileData, 0, sizeof(DeLeTe_File_Function) );
    DeLeTe_Function *Data = Get_DeLeTe_Function();
    
    FileData->mar_del = Data->mar_del;
    FileData->dir_del = Data->dir_del;
    FileData->gen_del = Data->gen_del;
    
    fwrite(f,FileData,sizeof(DeLeTe_File_Function));
    fclose (f);
    mfree(FileData);
  }
  FreeBook(bk);
}

void SetEnabled_1( GUI* list, DeLeTe_Function *Data )
{
  if(Data->gen_del == 1)
  {
    Data->gen_del = 0;
    ListMenu_SetItemSecondLineText( (GUI_LIST*)list, 0, TURN_OFF_TXT );
  }
  else if(Data->gen_del == 0)
  {
    Data->gen_del = 1;
    ListMenu_SetItemSecondLineText( (GUI_LIST*)list, 0, TURN_ON_TXT );
  }
}

void SetEnabled_2( GUI* list, DeLeTe_Function *Data )
{
  if(Data->mar_del == 1)
  {
    Data->mar_del = 0;
    ListMenu_SetItemSecondLineText( (GUI_LIST*)list, 1, TURN_OFF_TXT );
  }
  else if(Data->mar_del == 0)
  {
    Data->mar_del = 1;
    ListMenu_SetItemSecondLineText( (GUI_LIST*)list, 1, TURN_ON_TXT );
  }
}

void SetEnabled_3( GUI* list, DeLeTe_Function *Data )
{
  if(Data->dir_del == 1)
  {
    Data->dir_del = 0;
    ListMenu_SetItemSecondLineText( (GUI_LIST*)list, 2, TURN_OFF_TXT );
  }
  else if(Data->dir_del == 0)
  {
    Data->dir_del = 1;
    ListMenu_SetItemSecondLineText( (GUI_LIST*)list, 2, TURN_ON_TXT );
  }
}

void onEnterList( BOOK* bk, GUI* list_menu )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  myBook->item_ID = ListMenu_GetSelectedItem(myBook->list_menu);
  if(myBook->item_ID==0) SetEnabled_1(myBook->list_menu,Data);
  if(myBook->item_ID==1) SetEnabled_2(myBook->list_menu,Data);
  if(myBook->item_ID==2) SetEnabled_3(myBook->list_menu,Data);
}

void onSetPassword( BOOK* bk, GUI* list )
{
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  if(Data->del_pas == 1)
  {
    Data->del_pas = 0;
    GUIObject_SoftKeys_SetText( list, 0, SetText2(0) );
  }
  else if(Data->del_pas == 0)
  {
    Data->del_pas = 1;
    GUIObject_SoftKeys_SetText( list, 0, SetText2(1) );
  }
}

int MainPageOnCreate(void *r0, BOOK *bk)
{
  LoadData();
  DeLeTe_Function *Data = Get_DeLeTe_Function();
  MyBOOK* myBook = (MyBOOK*) bk;
  myBook->list_menu = CreateListMenu( myBook,0 );
  GUIObject_SetTitleType( myBook->list_menu, UI_TitleMode_Small );
  GUIObject_SetTitleText( myBook->list_menu, SetText() );
  GUIObject_SetStyle( myBook->list_menu, UI_OverlayStyle_Default);
  ListMenu_SetItemStyle( myBook->list_menu, 3 );
  ListMenu_SetItemCount( myBook->list_menu, 3 );
  ListMenu_SetCursorToItem( myBook->list_menu, 0 ); 
  ListMenu_SetOnMessage( myBook->list_menu, onMessageList );
  GUIObject_SoftKeys_SetAction( myBook->list_menu, ACTION_BACK, onBackList );
  GUIObject_SoftKeys_SetAction( myBook->list_menu, ACTION_LONG_BACK, onLongBack );
  GUIObject_SoftKeys_SetAction( myBook->list_menu, ACTION_SELECT1, onEnterList );
    
  GUIObject_SoftKeys_SetText( myBook->list_menu, 1, ABOUT_TXT);
  GUIObject_SoftKeys_SetAction( myBook->list_menu, 1, onAuthorInfo);
   
  GUIObject_Show( myBook->list_menu );
  return (1);
}

int LockMainPage(void *r0, BOOK *bk)
{
  CreatePasswordInputWindow( BookObj_GetBookID(bk), 0, 2, PROTECT_TXT );
  return (1);
}

int Cancel_BasePage(void *r0, BOOK *bk)
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FreeBook(myBook);
  return(1);
}

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT,            Cancel_BasePage,
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT,               0
};

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT, LockMainPage,
  ACCEPT_EVENT,     MainPageOnCreate,
  NIL_EVENT,        0
};

const PAGE_DESC bk_base = {"DeleteProtection_base_Page",0,bk_msglst_base};
const PAGE_DESC bk_main = {"DeleteProtection_main_Page",0,bk_msglst_main};

void onBkClose (BOOK* bk)
{
}

extern "C"
__thumb void SettingsMenu()
{
  MyBOOK* myBook = (MyBOOK*) malloc (sizeof(MyBOOK));
  memset( myBook, 0, sizeof(MyBOOK));
  if (!CreateBook((BOOK*)myBook,onBkClose,&bk_base,"DeleteProtection_bk",-1,0)) mfree(myBook);
  {
    BookObj_GotoPage(myBook,&bk_main);
  }
}

__thumb void ONOFF_Editor(DYNAMIC_MENU_ELEMENT *DME)
{
  switch(DynamicMenu_GetElementMsg(DME))
  {
  case MENU_onCall:
    SettingsMenu();
    break;
  }
}

#pragma diag_suppress=Pe177
__root const int Patch_ONOFF @ "Patch_ONOFF" =(int)PATCH_ONOFF_ID;
__root const int Patch_Run_ONOFF @ "Patch_Run_ONOFF" =(int)ONOFF_Editor;
