#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"

__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF, size, 1, 5, "key", 0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem, "key", 0);
}

int ItemFilter(void* elem)
{
  return(elem != NULL);
}

void FreeList(LIST* &List, void (*FreeProc)(void *Item))
{
  if (List)
  {
    List_DestroyElements(List, ItemFilter, FreeProc);
    List_Destroy(List);
  }
}

void SoftkeyFree(void* item)
{
  SOFTKEY_LIST_ELEM* elem = (SOFTKEY_LIST_ELEM*)item;
  if(elem)
  {
    elem->action=NULL;
    elem->textid=EMPTY_TEXTID;
    mfree(elem);
  }
}
/*
BOOL SortByNumber(void* elem1, void* elem2 )
{
  int pos_1 = ((SOFTKEY_LIST_ELEM*)elem1)->action;
  int pos_2 = ((SOFTKEY_LIST_ELEM*)elem2)->action;
  
  if(pos_2 > pos_1) return FALSE;
  else return TRUE;
}
*/
SOFTKEY_LIST_ELEM* CreateElem(SOFTKEY_DESC_A2* SoftkeyDesc)
{
  SOFTKEY_LIST_ELEM* elem = (SOFTKEY_LIST_ELEM*)malloc(sizeof(SOFTKEY_LIST_ELEM));
  elem->action = SoftkeyDesc->action;
  elem->textid = SoftkeyDesc->ButtonText;
  return(elem);
}

LIST* Create_SoftkeyList(LIST* slist)
{
  LIST* sk_list = List_Create();
  
  int index = 0;
  while( index < List_GetCount(slist) )
  {
    SOFTKEY_DESC_A2* SoftkeyDesc = (SOFTKEY_DESC_A2*)List_Get(slist,index);
    if( SoftkeyDesc->visible && SoftkeyDesc->enable )
    {
      if( SoftkeyDesc->ButtonText!=EMPTY_TEXTID )
      {
        if( SoftkeyDesc->ButtonText!=TEXTID_SPACE )
        {
          List_InsertLast(sk_list, CreateElem(SoftkeyDesc));
        }
      }
    }
    index++;
  }
  return sk_list;
}

void GetData(void* mydata, int size)
{
  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_CREAT|FSX_O_APPEND, FSX_S_IRUSR|FSX_S_IWUSR,0);
  fread(file,mydata,size);
  fclose(file);
}

void WriteData( char key_id, u16 action_id )
{
  FILE_DATA* fdata = (FILE_DATA*)malloc(sizeof(FILE_DATA));
  memset(fdata,0xFF,sizeof(FILE_DATA));
  GetData(fdata,sizeof(FILE_DATA));

  fdata->action[key_id] = action_id;

  int file =_fopen(FILE_PATH, FILE_NAME, FSX_O_TRUNC|FSX_O_RDWR, FSX_S_IRUSR|FSX_S_IWUSR, 0);
  fwrite(file,fdata,sizeof(FILE_DATA));
  fclose(file);
  mfree(fdata);
}


int GetChecked(LIST* list, char item_pos)
{
  int ret = 0xFF;
  
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size = _fstat.fsize;
    FILE_DATA* mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    
    for (int i=0; i<=List_GetCount(list); i++)
    {
      SOFTKEY_LIST_ELEM* elem = (SOFTKEY_LIST_ELEM*)List_Get(list, i);
      if (mydata->action[item_pos] == elem->action)
      {
        ret = i;
        break;
      }
    }
    mfree(mydata);
  }
  return ret;
}

TEXTID GetSecondLine(LIST* list, char item_num)
{
  TEXTID ret = EMPTY_TEXTID;
  int index = GetChecked( list, item_num );
  SOFTKEY_LIST_ELEM* elem = (SOFTKEY_LIST_ELEM*)List_Get(list, index);
  ret = elem->textid;
  return ret;
}

char GetKeyID(char key)
{
  char key_id;
  switch(key)
  {
  case KEY_DIGITAL_0+0: key_id = Item_Key_0; break;
  case KEY_DIGITAL_0+1: key_id = Item_Key_1; break;
  case KEY_DIGITAL_0+2: key_id = Item_Key_2; break;
  case KEY_DIGITAL_0+3: key_id = Item_Key_3; break;
  case KEY_DIGITAL_0+4: key_id = Item_Key_4; break;
  case KEY_DIGITAL_0+5: key_id = Item_Key_5; break;
  case KEY_DIGITAL_0+6: key_id = Item_Key_6; break;
  case KEY_DIGITAL_0+7: key_id = Item_Key_7; break;
  case KEY_DIGITAL_0+8: key_id = Item_Key_8; break;
  case KEY_DIGITAL_0+9: key_id = Item_Key_9; break;
  }
 return key_id;
}

extern "C"
void Set_New_Key( GUI* gui, char key )
{
  u16 actionID;
  char key_id = GetKeyID(key);
  
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size = _fstat.fsize;
    FILE_DATA* mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    actionID = mydata->action[key_id];
    mfree(mydata);
  }
  if(actionID != 0xFF) GUIObject_SoftKeys_ExecuteAction( gui, actionID );
}

TEXTID Get_Menu_Text(int item)
{
  /*
  const wchar_t* Menu_Text[Item_Key_Last] =
  {
    L"Button 0",
    L"Button 1",
    L"Button 2",
    L"Button 3",
    L"Button 4",
    L"Button 5",
    L"Button 6",
    L"Button 7",
    L"Button 8",
    L"Button 9"
  };
  */
  TEXTID txt[3];
  txt[0] = TextID_Create(L"Key",ENC_UCS2,3);
  txt[1] = TEXTID_SPACE;
  txt[2] = TextID_CreateIntegerID(item);
  
  TEXTID ret = TextID_Create(txt, ENC_TEXTID, 3);
  return ret;
}

void Select_Item( BOOK* book, GUI* gui )
{
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)book;
  int item = OneOfMany_GetSelected(mbk->SubMenu);
    
  SOFTKEY_LIST_ELEM* elem = (SOFTKEY_LIST_ELEM*)List_Get(mbk->SoftkeyList, item);
  
  WriteData( mbk->CurrentItem, elem->action );
  FREE_GUI(mbk->SubMenu);
}

void Close_EditItem(BOOK* book, GUI* gui)
{
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)book;
  FREE_GUI(mbk->SubMenu);
}

int EditItem_Callback( GUI_MESSAGE* msg )
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    MusicShortcut_Book* mbk = (MusicShortcut_Book*)GUIonMessage_GetBook(msg);
    
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    SOFTKEY_LIST_ELEM* elem = (SOFTKEY_LIST_ELEM*)List_Get(mbk->SoftkeyList, index);
    GUIonMessage_SetMenuItemText(msg, elem->textid);
    break;
  }
  return 1;
}

void CreateEditItem(BOOK* book, int itemnum)
{
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)book;
  FREE_GUI(mbk->SubMenu);
  
  mbk->CurrentItem = itemnum;
  char checked = GetChecked(mbk->SoftkeyList,mbk->CurrentItem);
  
  if(mbk->SubMenu = CreateOneOfMany(mbk))
  {
    GUIObject_SetTitleText( mbk->SubMenu, Get_Menu_Text(mbk->CurrentItem) );
    OneOfMany_SetChecked( mbk->SubMenu, checked );
    OneOfMany_SetItemCount( mbk->SubMenu, List_GetCount(mbk->SoftkeyList) );
    OneOfMany_SetOnMessage( mbk->SubMenu, EditItem_Callback );
    GUIObject_SetStyle( mbk->SubMenu, UI_OverlayStyle_FullScreen );
    GUIObject_SoftKeys_SetAction( mbk->SubMenu, ACTION_BACK, Close_EditItem);
    GUIObject_SoftKeys_SetAction( mbk->SubMenu, ACTION_LONG_BACK, Close_EditItem);
    GUIObject_SoftKeys_SetAction( mbk->SubMenu, ACTION_SELECT1, Select_Item);
    GUIObject_Show( mbk->SubMenu );
  }
}

void Shortcut_EnterAction(BOOK* book, GUI* gui)
{
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)book;
  CreateEditItem(mbk, ListMenu_GetSelectedItem(mbk->MainMenu));
}

void Shortcut_PrevAction(BOOK* book, GUI* gui)
{
  FreeBook(book);
}

int Shortcut_Callback( GUI_MESSAGE* msg )
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    MusicShortcut_Book* mbk = (MusicShortcut_Book*)GUIonMessage_GetBook(msg);
    
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText( msg, Get_Menu_Text(index) );
    GUIonMessage_SetMenuItemSecondLineText( msg, GetSecondLine(mbk->SoftkeyList,index) );
    break;
  }
  return 1;
}

int pg_MusicShortcut_EnterAction(void* data, BOOK* book)
{
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)book;
  FREE_GUI(mbk->MainMenu);

  if(mbk->MainMenu = CreateListMenu( mbk, UIDisplay_Main ))
  {
    ListMenu_SetItemCount( mbk->MainMenu, Item_Key_Last );
    ListMenu_SetItemStyle( mbk->MainMenu, 3 );
    ListMenu_SetCursorToItem( mbk->MainMenu, mbk->CurrentItem );
    ListMenu_SetHotkeyMode( mbk->MainMenu, LKHM_SHORTCUT );
    ListMenu_SetOnMessage( mbk->MainMenu, Shortcut_Callback );
    GUIObject_SetTitleText( mbk->MainMenu, SHORTCUT_TXT);
    GUIObject_SetStyle( mbk->MainMenu, UI_OverlayStyle_FullScreen );
    GUIObject_SoftKeys_SetAction( mbk->MainMenu, ACTION_SELECT1, Shortcut_EnterAction );
    GUIObject_SoftKeys_SetAction( mbk->MainMenu, ACTION_BACK, Shortcut_PrevAction );
    GUIObject_SoftKeys_SetAction( mbk->MainMenu, ACTION_LONG_BACK, Shortcut_PrevAction );
    GUIObject_Show( mbk->MainMenu );
  }
  return 1;
}

int pg_MusicShortcut_CancelAction(void* data, BOOK* book)
{
  FreeBook(book);
  return 1;
}

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT,            pg_MusicShortcut_CancelAction,
  RETURN_TO_STANDBY_EVENT, pg_MusicShortcut_CancelAction,
  NIL_EVENT,               NULL
};
const PAGE_DESC MusicShortcut_Base_Page = {BASE_PAGE_NAME,NULL,bk_msglst_base};


const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT,  pg_MusicShortcut_EnterAction,
  NIL_EVENT,         NULL
};
const PAGE_DESC MusicShortcut_Main_Page = {MAIN_PAGE_NAME,NULL,bk_msglst_main};

void Goto_Shortcut_Destroy(BOOK* book)
{
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)book;
  FREE_GUI(mbk->MainMenu);
  FreeList(mbk->SoftkeyList, SoftkeyFree);
}
/*
void SomethingToBOOK(BOOK* book)
{
  asm("PUSH {LR}"); 
  asm("MOVS R1, #0x75"); 
  asm("MOVS R2, #1");      
  asm("STRB R2, [R0,R1]");               
  asm("POP {PC}");
}
*/
void Call_ShortcutPage( BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  #ifdef WALKMAN
  MusicBook->unk_0x98 = TRUE;
  #else
  MusicBook->unk_0x90 = TRUE;
  #endif
#elif defined(DB3150)
  MusicBook->unk_0x8C = TRUE;
#else
  MusicBook->unk_0x75 = TRUE;
#endif  
  //SomethingToBOOK(MusicBook);
  
  MusicShortcut_Book* mbk = (MusicShortcut_Book*)malloc(sizeof(MusicShortcut_Book));
  memset( mbk, NULL, sizeof(MusicShortcut_Book));
  if(!CreateBook(mbk,Goto_Shortcut_Destroy,&MusicShortcut_Base_Page,BOOKNAME,-1,NULL)) 
    mfree(mbk);
  else
  {
    DISP_OBJ* DispObj = GUIObject_GetDispObject(MusicBook->Gui_NowPlaying);
    LIST* SoftKeys_List = DispObject_SoftKeys_GetList(DispObj, MusicBook, 0);
    mbk->SoftkeyList = Create_SoftkeyList(SoftKeys_List);
    BookObj_GotoPage(mbk,&MusicShortcut_Main_Page);
  }
}
/*
extern "C"
void Set_New_Key( GUI* gui, char key, char mode )
{
  Exec_Key(gui,key);
}
*/
extern "C"
void Set_New_Action(BOOK* book)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SHORTCUT);
  GUIObject_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, Call_ShortcutPage);
  GUIObject_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, SHORTCUT_TXT);
  
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SHORTCUT);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, Call_ShortcutPage);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SHORTCUT, SHORTCUT_TXT);
}
