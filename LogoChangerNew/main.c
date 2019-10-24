/*
;Logo Changer
;Ability to change the operator name
;Menu>Settings>Connectivity>Phone name
;if put empty text operator name will be back to default
;v.Final
;(c) K790alex, farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h" 

__thumb void * malloc (int size)
{
#ifdef DB2020  
  return(memalloc(0,size,1,5,"logo",0));
#elif A2
  return(memalloc(0xFFFFFFFF,size,1,5,"logo",0));
#else
  return(memalloc(size,1,5,"logo",0));
#endif
}

__thumb void mfree (void * mem)
{
#ifdef DB2020  
  if (mem) memfree(0, mem,"logo",0);
#elif A2
  if (mem) memfree(0, mem,"logo",0);
#else
  memfree(mem,"logo",0);
#endif
}

extern "C"
wchar_t* ReadOnFile()
{
  FSTAT _fstat;
  int stat = fstat((wchar_t*)FILE_PATH,(wchar_t*)FILE_NAME,&_fstat);
  
  wchar_t *string = (wchar_t*)malloc(32);

  if (stat == 0)
  {
    int f;
    if ((f = _fopen((wchar_t*)FILE_PATH,(wchar_t*)FILE_NAME,FSX_O_RDONLY,FSX_S_IREAD|FSX_S_IWRITE,0)) >= 0)
    {
      FILEDATA* FData = (FILEDATA*) malloc(sizeof(FILEDATA));
      memset(FData,0,sizeof(FILEDATA));
      fread(f,FData,sizeof(FILEDATA));
      wstrcpy(string,FData->opname);
      fclose(f);
      mfree(FData);
      
    }
  }
  if (stat < 0) return 0;
  if (wstrlen(string)==0) return 0;
  //wchar_t* oplogo;
  //Registry_Read("oplogo", int type, 32, &oplogo);
  else return string;
}

void WriteOnFile( wchar_t* string )
{
  int f;
  if ( (f=_fopen((wchar_t*)FILE_PATH,(wchar_t*)FILE_NAME, FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    FILEDATA* FData = (FILEDATA*) malloc(sizeof(FILEDATA));
    memset(FData,0,sizeof(FILEDATA) );
    wstrcpy(FData->opname,string);
    fwrite(f,FData,sizeof(FILEDATA));
    fclose(f);
  }
  //Registry_Write("oplogo", int type, 32, void* data);
}

void OnAcceptInput(BOOK* bk, GUI* gui)
{
  u16 len;
  wchar_t *wstr;
  StringInput_GetStringAndLen( gui, &wstr, &len );
  WriteOnFile(wstr);
  if (len)
  {
    MessageBox( EMPTY_TEXTID, TextID_Create(wstr,ENC_UCS2,len), 0, 1, 0, bk );
    SetOperatorName(TextID_Create(wstr,ENC_UCS2,len),0);
  }
  else
  {
    wchar_t buf;
    MessageBox( EMPTY_TEXTID, TextID_Create("Operator name will be back to default",ENC_LAT1,0xFF), 0, 1, 0, bk );
    SetOperatorName(GetOperatorName(&buf),0);
  }
  FreeBook(bk);
}

void OnPatchInfo(BOOK* bk, GUI* g)
{
  MessageBox( EMPTY_TEXTID, TextID_Create("Logo Changer\nv.Final\n\n(c) K790Alex, farid", ENC_LAT1, 0xFF), 0, 1, 0, bk );
}

extern "C"
void onBackGui(BOOK* bk, GUI* gui)
{
  if(gui) gui = GUIObject_Destroy(gui);
}

int pg_EditOperatorName(void* , BOOK* book)
{
  wchar_t buf;
  BT_Book* mbk = (BT_Book*)book;
  mbk->gui = CreateStringInput(book);
  StringInput_SetText(mbk->gui, GetOperatorName(&buf));
  StringInput_SetMaxLen(mbk->gui, 32);
  StringInput_SetMode(mbk->gui, IT_STRING);
  StringInput_SetEnableEmptyText(mbk->gui, TRUE);
  GUIObject_SetTitleText(mbk->gui, OPERATOR_TXT );
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_BACK, onBackGui);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_LONG_BACK, onLongBackPressed);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_ACCEPT, OnAcceptInput);
  GUIObject_Show(mbk->gui);
  return(1);
}

const PAGE_MSG evtlst_EditOperatorName[] = 
{
  PAGE_ENTER_EVENT, pg_EditOperatorName,
  PAGE_EXIT_EVENT,  pg_MainMenuHandsfreeAddCancelled,
  NIL_EVENT,        NULL
};

const PAGE_MSG evtlst_EditBluetoothName[] = 
{
  PAGE_ENTER_EVENT, pg_EditPhoneName,
  PAGE_EXIT_EVENT,  pg_MainMenuHandsfreeAddCancelled,
  NIL_EVENT,        NULL
};

const PAGE_DESC EditBluetoothName_page = {(char*)EditPhoneNamePage,0,evtlst_EditBluetoothName};
const PAGE_DESC EditOperatorName_page = {"EditOperatorName_Page",0,evtlst_EditOperatorName};

void onEnterList(BOOK *bk, GUI* gui)
{
  int item = ListMenu_GetSelectedItem(gui);
  if (item == 0) BookObj_GotoPage(bk, &EditOperatorName_page);
  if (item == 1) BookObj_GotoPage(bk, &EditBluetoothName_page);
}

int list_callback( GUI_MESSAGE* msg )
{
  if ( GUIonMessage_GetMsg(msg) == 1)
  {
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == 0)
    {
      GUIonMessage_SetMenuItemText( msg, OPERATOR_TXT);
      GUIonMessage_SetMenuItemIcon( msg, 0, OPERATOR_ICN );
    }
    if (item == 1)
    {
      GUIonMessage_SetMenuItemText( msg, BLUETOOTH_TXT);
      GUIonMessage_SetMenuItemIcon( msg, 0, BLUETOOTH_ICN );
    }
  }
  return (1);
}

int EditPhoneName_new(void* r0, BOOK* book)
{
  BT_Book* mbk = (BT_Book*)book;
  mbk->gui = CreateListMenu(book, 0);
  GUIObject_SetTitleText(mbk->gui, PHONE_NAME_TXT );
  GUIObject_SetTitleIcon(mbk->gui, TITLE_ICON );
  ListMenu_SetItemCount(mbk->gui, 2);
  ListMenu_SetCursorToItem(mbk->gui, 0);
  ListMenu_SetOnMessage(mbk->gui,  list_callback);
  ListMenu_SetHotkeyMode(mbk->gui, LKHM_SHORTCUT);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_BACK, onBackPressed);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_LONG_BACK, onLongBackPressed);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_SELECT1, onEnterList);
  GUIObject_SoftKeys_SetText(mbk->gui, 1, ABOUT_TXT);
  GUIObject_SoftKeys_SetAction(mbk->gui, 1, OnPatchInfo);
  GUIObject_Show(mbk->gui);
  return(1);
}

extern "C"
const PAGE_MSG evtlst_EditPhoneName_new[] = 
{
  PAGE_ENTER_EVENT, EditPhoneName_new,
  PAGE_EXIT_EVENT,  pg_MainMenuHandsfreeAddCancelled,
  NIL_EVENT,        NULL
};
