/*
;SMS Backup v2.5
;
;+Added auto reboot after Restore SMS
;+Added ability to delete backup file at list menu by pressing button "C"
;+Added question before Restore sms
;+Added question before Delete backup file
;+Added ability to choose Backup Folder
;+Changed Gui List Interface
;
;+Code rewritten and optimized for A2
;
;(i) default Backup file saved in "/card/system/SMSBackup"
;(!) Add to menu.ml element id="SMS_Backup_Patch_Id"
;
;(c) Laura_P
;(e) farid
;Original idea by mcming1989
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#define FREE_GUI(gui) if(gui) gui=GUIObject_Destroy(gui);
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a);
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

#define PATCH_INFO "SMS Backup v2.5\n(c) Laura_P\n(e) farid\nOriginal idea by mcming1989"

#define SMS_BACKUP_NAME "SMS_Backup_Book"
#define PATCH_SMSBACKUP_ID  L"SMS_Backup_Patch_Id"

#define SmsFileName L"msg_int.dbf"
#define SmsPathName L"/tpa/system/messaging/db"
#define SmsBackupPath L"/card/system/SMSBackup"

#define SavedBackup L"sms_backup.bin"


typedef struct 
{
  wchar_t BackupPath[32];
}BackupFile;

typedef struct _MyBOOK : BOOK
{
  GUI_LIST * list;
  GUI * yesno;
  GUI * input;
}MyBOOK;

typedef enum YES_NO 
{
  OVERWRITE = 0,
  RESTORE,
  DELETE,
  REBOOT
}YES_NO;

//---------------------------Memory Opeation------------------------------------

__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF,size,1,5,"sms",0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,"sms",0);
}

//---------------------------File Opeation--------------------------------------

int DeleteFile( wchar_t* path )
{
  int error;
  FileDelete(path,SmsFileName,&error);
  if(error) return 1;
  else return 0;
}    

int CopyFile( wchar_t* from, wchar_t* to )
{
  int *error;
  FileCopy(from,SmsFileName,to,SmsFileName,error);
  if(error) return 1;
  else return 0;
}

int CheckFile( wchar_t* path, wchar_t* name)
{
  FSTAT fst;
  if (fstat(path,name,&fst) < 0) return 0;
  return 1;
}

//-------------------------------Misc------------------------------------------

void MsgBox( int text, int time )
{
  MessageBox(EMPTY_TEXTID,text,NOIMAGE,1,time,NULL);
}

//------------------------------SoftKeys---------------------------------------

void onBackPressed( BOOK* bk, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  FreeBook(mbk);
}

void onLongBackPressed( BOOK* bk, GUI* gui )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FREE_GUI(gui);
  FreeBook(myBook);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void onNoPressed( BOOK* bk, GUI* gui )
{
  FREE_GUI(gui);
}

//-----------------------------GUI---------------------------------------

wchar_t* ReadBackupPath()
{
  int f;
  FSTAT _fstat;
  wchar_t* wstr = (wchar_t*)malloc(32);

  if (fstat((wchar_t*)PATH,L"sms_backup.bin",&_fstat) == 0)
  {
    if ((f = _fopen((wchar_t*)PATH,L"sms_backup.bin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >= 0)
    {
      BackupFile *FileData = (BackupFile*) malloc(sizeof(BackupFile) );
      memset ( FileData, 0, sizeof(BackupFile) );
      fread( f,FileData,sizeof(BackupFile) );
      wstrcpy( wstr, FileData->BackupPath );
      fclose(f);
      mfree(FileData);
    }
  }
  return wstr;
}

void Write_to_File( wchar_t *wstr )
{
  int f;
  if ( (f = _fopen((wchar_t*)PATH,L"sms_backup.bin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >= 0 )
  {
    BackupFile* FileData = (BackupFile*) malloc(sizeof(BackupFile));
    memset( FileData, 0, sizeof(BackupFile) );
    wstrcpy( FileData->BackupPath, wstr );
    fwrite( f, FileData, sizeof(BackupFile));
    fclose(f);
  }
}

void onAcceptInput( BOOK * bk, GUI* gui )
{
  u16 len;
  wchar_t *wstr;
  StringInput_GetStringAndLen( gui, &wstr, &len );
  if (len)
  {
    Write_to_File(wstr);
    int text[2] = { TextID_Create("Backup Folder: ",0,15), TextID_Create(wstr,0,len) };
    MsgBox(TextID_Create(text,5,2),2000);
  } 
  else
  {
    Write_to_File(SmsBackupPath);
    MsgBox(TextID_Create("Backup Folder back to default",6,0xFF),2000); 
  }
  FREE_GUI( gui );
}

void Create_GuiInput(BOOK *bk)
{
  MyBOOK* myBook = (MyBOOK*) bk;
  myBook->input = (GUI*) CreateStringInput(myBook);
  
  if (!CheckFile((wchar_t*)PATH,SavedBackup))
    StringInput_SetText(myBook->input, TextID_Create(SmsBackupPath,0,0xFF));
  else StringInput_SetText(myBook->input, TextID_Create(ReadBackupPath(),0,0xFF));
  
  StringInput_SetMaxLen(myBook->input, 32);
  StringInput_SetMode(myBook->input, IT_STRING);
  StringInput_SetMinLen(myBook->input, 1);
  GUIObject_SoftKeys_SetAction(myBook->input, ACTION_BACK, onNoPressed);
  GUIObject_SoftKeys_SetAction(myBook->input, ACTION_LONG_BACK, onLongBackPressed);
  GUIObject_SoftKeys_SetAction(myBook->input, ACTION_ACCEPT, onAcceptInput);
 
  GUIObject_Show(myBook->input);
}

//-----------------------------Create_GuiYesNo----------------------------------------

void Create_GuiYesNo( BOOK* bk, YES_NO mode );

void onOverWrite( BOOK* bk, GUI* gui )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  if (!CheckFile((wchar_t*)PATH,SavedBackup))
  {
    DeleteFile(SmsBackupPath);
    CopyFile(SmsPathName,SmsBackupPath);
  } else
  {
    DeleteFile(ReadBackupPath());
    CopyFile(SmsPathName,ReadBackupPath());
  }
  MsgBox(0xDE0,2000); //Backup completed
  FREE_GUI(myBook->yesno);
}

void onRestore( BOOK* bk, GUI* gui )
{
  DeleteFile(SmsPathName);
  if (!CheckFile((wchar_t*)PATH,SavedBackup)) CopyFile(SmsBackupPath,SmsPathName);
  else CopyFile(ReadBackupPath(),SmsPathName);
  Create_GuiYesNo(bk,REBOOT);
}  
  
void onDelete( BOOK* bk, GUI* gui )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  
  if (!CheckFile((wchar_t*)PATH,SavedBackup)) DeleteFile(SmsBackupPath);
  else DeleteFile(ReadBackupPath());
  
  MsgBox(0x1B51,2000); //File deleted
  FREE_GUI(myBook->yesno);
}

void onReboot( BOOK* bk, GUI* gui )
{
  Reboot();
}

void Create_GuiYesNo( BOOK* bk, YES_NO mode )
{ 
  MyBOOK* myBook = (MyBOOK*) bk;
  myBook->yesno = (GUI*)CreateYesNoQuestion(bk,0);
  YesNoQuestion_SetIcon( myBook->yesno,0xF831 );
  if (mode == OVERWRITE)
  {
    YesNoQuestion_SetDescriptionText( myBook->yesno, 0xF11 );
    YesNoQuestion_SetQuestionText( myBook->yesno, 0xF12 );
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_YES, onOverWrite );
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_NO, onNoPressed );
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_LONG_BACK, onLongBackPressed );
  }
  else if (mode == RESTORE)
  {
    YesNoQuestion_SetDescriptionText( myBook->yesno, TextID_Create("Phone will restart to load changes",6,0xFF) );
    YesNoQuestion_SetQuestionText( myBook->yesno, 0xF12 );
    GUIObject_SoftKeys_SetAction( myBook->yesno,ACTION_YES, onRestore );
    GUIObject_SoftKeys_SetAction( myBook->yesno,ACTION_NO,onNoPressed );
    GUIObject_SoftKeys_SetAction( myBook->yesno,ACTION_LONG_BACK,onLongBackPressed );
  }
  else if (mode == DELETE)
  {
    YesNoQuestion_SetDescriptionText( myBook->yesno, 0x671 );
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_YES, onDelete );
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_NO, onNoPressed );
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_LONG_BACK, onLongBackPressed );
  }
  else if (mode == REBOOT)
  {
    YesNoQuestion_SetDescriptionText( myBook->yesno, TextID_Create("Backup is restored, press OK to restart",6,0xFF) );
    GUIObject_SoftKeys_SetText( myBook->yesno, ACTION_YES, 0x8D8 ); // OK
    GUIObject_SoftKeys_SetAction( myBook->yesno, ACTION_YES, onReboot );
    GUIObject_SoftKeys_SetVisible( myBook->yesno, ACTION_BACK,0);
  }
  GUIObject_Show( myBook->yesno );
}

//-----------------------------GUI_LIST-----------------------------------------

void onPatchInfo( BOOK* bk, GUI* gui )
{
  MsgBox(TextID_Create(PATCH_INFO,6,0xFF),0);
}

void onCreateInput( BOOK* bk, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  Create_GuiInput(mbk);
}

void onDeleteBackup( BOOK* bk, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  
  if (!CheckFile((wchar_t*)PATH,SavedBackup))
  {
    if (CheckFile(SmsBackupPath, SmsFileName)) Create_GuiYesNo(mbk,DELETE);
    else MsgBox(0xF3A,0); //No backup file exist
  }
  else
  {
    if (CheckFile(ReadBackupPath(), SmsFileName)) Create_GuiYesNo(mbk,DELETE);
    else MsgBox(0xF3A,0); //No backup file exist
  }
}

int List_onMessage( GUI_MESSAGE * msg )
{
  if ( GUIonMessage_GetMsg(msg) == 1 )
  {
    int item=GUIonMessage_GetCreatedItemIndex(msg);
    if(item==0)
    {
      GUIonMessage_SetMenuItemText( msg, TextID_Create("Backup",6,6) );
      GUIonMessage_SetMenuItemIcon( msg , 0, 0xED26);
    }
    if(item==1)
    {
      GUIonMessage_SetMenuItemText( msg, TextID_Create("Restore",6,7) );
      GUIonMessage_SetMenuItemIcon( msg , 0, 0xED22);
    }
  }
  return(1);
}

void onEnterList( BOOK* bk, GUI* gui )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  int item = ListMenu_GetSelectedItem(myBook->list);
  if(item==0)
  {
    if (!CheckFile((wchar_t*)PATH,SavedBackup))
    {
      if (!CheckFile(SmsBackupPath, SmsFileName))
      {
        CopyFile(SmsPathName,SmsBackupPath);
        MsgBox(0xDE0,0); //Backup completed
      } else
      {
        MsgBox( 0x834, 2000); //File Already exist
        Create_GuiYesNo(bk,OVERWRITE);
      }
    } else
    {
      if (!CheckFile(ReadBackupPath(), SmsFileName))
      {
        CopyFile(SmsPathName,ReadBackupPath());
        MsgBox(0xDE0,0); //Backup completed
      } else
      {
        MsgBox( 0x834, 2000); //File Already exist
        Create_GuiYesNo(bk,OVERWRITE);
      }
    }
  }
  if(item==1)
  {
    if (!CheckFile((wchar_t*)PATH,SavedBackup))
    {
      if (!CheckFile(SmsBackupPath, SmsFileName)) MsgBox(0xF3A,0);
      else Create_GuiYesNo(bk,RESTORE);
    }
    else
    {
      if (!CheckFile(ReadBackupPath(), SmsFileName)) MsgBox(0xF3A,0);
      else Create_GuiYesNo(bk,RESTORE); 
    }
  }
}

int MainPageOnCreate(void * r0, BOOK * bk)
{
  MyBOOK* myBook = (MyBOOK*) bk;
  myBook->list = (GUI_LIST *)CreateListMenu(bk,0);
  ListMenu_SetItemCount( myBook->list, 2 );
  ListMenu_SetOnMessage( myBook->list, List_onMessage );
  ListMenu_SetCursorToItem( myBook->list, 0);
  ListMenu_SetBackgroundImage( myBook->list, 0xEE3F );
  ListMenu_SetHotkeyMode( myBook->list, LKHM_SHORTCUT );
    
  GUIObject_SetTitleType( myBook->list, UI_TitleMode_Small);
  GUIObject_SetTitleText( myBook->list, TextID_Create("SMS Management",6,14) );
  GUIObject_SetStyle( myBook->list, UI_OverlayStyle_Default);
  
  GUIObject_SoftKeys_SetAction( myBook->list,ACTION_BACK,onBackPressed );
  GUIObject_SoftKeys_SetAction( myBook->list,ACTION_LONG_BACK,onLongBackPressed );
  GUIObject_SoftKeys_SetAction( myBook->list,ACTION_SELECT1,onEnterList );
  GUIObject_SoftKeys_SetAction( myBook->list, ACTION_DELETE,onDeleteBackup);
  GUIObject_SoftKeys_SetVisible( myBook->list, ACTION_DELETE,0);
    
  GUIObject_SoftKeys_SetText( myBook->list, 0, TextID_Create("Set Backup Path",6,0xFF) );
  GUIObject_SoftKeys_SetAction( myBook->list, 0, onCreateInput );
  GUIObject_SoftKeys_SetText( myBook->list, 1, 0x19ED );
  GUIObject_SoftKeys_SetAction( myBook->list, 1, onPatchInfo );
  
  GUIObject_Show( myBook->list );
  return (1);
}

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT, NULL,
  NIL_EVENT,    NULL
};

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT,  MainPageOnCreate,
  NIL_EVENT,         NULL
};

const PAGE_DESC bk_base = {"SMS_Backup_Base_Page",0,bk_msglst_base};
const PAGE_DESC bk_main = {"SMS_Backup_Main_Page",0,bk_msglst_main};

void onBkClose ( BOOK* bk )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  FreeBook(mbk);
}

int IsSMSBackupBook( BOOK* book )
{
  if(strcmp(book->xbook->name,SMS_BACKUP_NAME)) return (0);
  return (1);
}

void CreateMyBook()
{
  MyBOOK* myBook = (MyBOOK*) malloc(sizeof(MyBOOK));
  memset( myBook, 0, sizeof(MyBOOK));
  if (!CreateBook((BOOK*)myBook,onBkClose,&bk_base,SMS_BACKUP_NAME,-1,0)) mfree(myBook);
  else BookObj_GotoPage(myBook,&bk_main);
}

extern "C"
void SMSBackup_Editor(DYNAMIC_MENU_ELEMENT *DME)
{
  switch(DynamicMenu_GetElementMsg(DME))
  {
  case MENU_onCall:
    BOOK* bk = FindBook(IsSMSBackupBook);
    if (bk) BookObj_SetFocus(bk,0);
    else CreateMyBook();
    break;
  }
}

#pragma diag_suppress=Pe177
__root const int Patch_SMSBackup @ "Patch_SMSBackup" =(int)PATCH_SMSBACKUP_ID;
__root const int Patch_Run_SMSBackup @ "Patch_Run_SMSBackup" =(int)SMSBackup_Editor;
