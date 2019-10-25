/*
;Ability to move,show/hide items on standby
;(c) Ploik, BigHercules
;(e) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "cfg_items.h"
#include "StatusIndication.h"
#include "editor.h"
#include "visual.h"

void win12512unicode( wchar_t* ws, const char* s, int len )
{
  int c;
  while( ( c = *s++ ) && len -- > 0 )
  {
    if( c == 0xA8 )
      c = 0x401;
    if( c == 0xAA )
      c = 0x404;
    if( c == 0xAF )
      c = 0x407;
    if( c == 0xB8 )
      c = 0x451;
    if( c == 0xBA )
      c = 0x454;
    if( c == 0xBF )
      c = 0x457;
    if( c >= 0xC0 && c < 0x100 )
      c += 0x350;
    *ws++ = c;
  }
  * ws = 0;
}

int getnumwidth( unsigned int num )
{
  int i = 1;
  while( num >= 10 )
  {
    num /= 10;
    i++ ;
  }
  return i;
}

int onMessageItems(GUI_MESSAGE *msg)
{
  switch(GUIonMessage_GetMsg( msg ))
  {
   case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg,TextID_Create(GetItemName(item),ENC_UCS2,TEXTID_ANY_LEN));
   break;
  }
  return(1);
};

void CloseMyBook(BOOK *book, GUI *gui)
{
  FreeBook(book);
}

void onChangeItems( BOOK* book, GUI *gui )
{
  ITEMSBOOK* mbk = (ITEMSBOOK*)book;
  SetCurrentItem(ListMenu_GetSelectedItem(mbk->gui));
  CreateItemsEditor();
}

void onEnterItems(BOOK *book, GUI *r1)
{
  ITEMSBOOK* mbk = (ITEMSBOOK*)book;
  //GUI_LIST *list_menu = (GUI_LIST *)(m_bk->gui);
  SetCurrentItem(ListMenu_GetSelectedItem(mbk->gui));
  FreeBook(mbk);
}

int Cancel_BasePage(void *r0, BOOK *book)
{
  FreeBook(book);
  return(1);
}

int ItemsMainPageOnCreate(void *r0, BOOK *book)
{
  ITEMSBOOK* mbk = (ITEMSBOOK*)book;
  FREE_GUI(mbk->gui);
  
  if(!(mbk->gui = CreateListMenu(mbk,UIDisplay_Main)))
  {
    FreeBook(mbk);
    return(1);
  }
  
  int CurItem = GetCurrentItem();
  ListMenu_SetItemCount(mbk->gui,LAST_ITEM);
  
  if(CurItem < 0)
    ListMenu_SetCursorToItem(mbk->gui,0);
  else
    ListMenu_SetCursorToItem(mbk->gui,CurItem);
  
  ListMenu_SetOnMessage(mbk->gui,onMessageItems);
  GUIObject_SetTitleText(mbk->gui, STR("Select an item"));
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_BACK, CloseMyBook);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_LONG_BACK, CloseMyBook);
  GUIObject_SoftKeys_SetAction(mbk->gui, ACTION_SELECT1, onEnterItems);
  GUIObject_SoftKeys_SetAction(mbk->gui, 1, onChangeItems);
  GUIObject_SoftKeys_SetText(mbk->gui, 1, CHANGE_TEXTID);
  GUIObject_Show(mbk->gui);
  return 1;
}

void OnBackCreateTextInputGui( BOOK* bk, u16* string, int len )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FREE_GUI( myBook->text_input );
}

void OnOkCreateUnsignedNumberGui( BOOK* book, wchar_t* string, int len )
{
  MyBOOK* mbk = (MyBOOK*) book;
  wchar_t ustr[64];
  unsigned int ui;
  ui = wcstoul( string, 0, 10 );
  if( ui < mbk->cur_hp.unsignedint->min || ui > mbk->cur_hp.unsignedint->max)
  {
    snwprintf( ustr, MAXELEMS(ustr) - 1, L"min: %u\nmax: %u", mbk->cur_hp.unsignedint->min, mbk->cur_hp.unsignedint->max );
    MessageBox_NoImage( EMPTY_TEXTID, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ), 1, 5000, mbk );
    
  }
  else
  {
    mbk->cur_hp.unsignedint->unsignedint = ui;
    FREE_GUI( mbk->text_input );
    RefreshEdList(mbk);
  }
}

void CreateUnsignedNumberInput( MyBOOK* mbk )
{
  wchar_t ustr[64];
  TEXTID text, header_name;
  
  snwprintf( ustr, MAXELEMS(ustr) - 1, L"%u", mbk->cur_hp.unsignedint->unsignedint );
  text = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
  win12512unicode( ustr, mbk->cur_hp.unsignedint->name, MAXELEMS(ustr) - 1 );
  header_name = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
  mbk->text_input = CreateStringInputVA(0,
                                        VAR_BOOK,mbk,
                                        VAR_HEADER_TEXT,header_name,
                                        VAR_STRINP_MAX_LEN,getnumwidth(mbk->cur_hp.unsignedint->max),
                                        VAR_STRINP_MODE,IT_UNSIGNED_DIGIT,
                                        VAR_STRINP_ENABLE_EMPTY_STR,0,
                                        VAR_STRINP_TEXT,text,
                                        VAR_PREV_ACTION_PROC,OnBackCreateTextInputGui,
                                        VAR_OK_PROC,OnOkCreateUnsignedNumberGui,
                                        0 );
}

void OnCloseCBoxGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FREE_GUI( mbk->cbox_gui );
}

void OnSelectCBoxGui( BOOK* book, GUI* )
{
  MyBOOK* mbk = (MyBOOK*)book;
  int item = OneOfMany_GetSelected( mbk->cbox_gui );
  
  if( item < mbk->cur_hp.cbox->max )
    mbk->cur_hp.cbox->selected = item;
  
  FREE_GUI( mbk->cbox_gui );
  RefreshEdList(mbk);
}

void CreateCBoxGui( MyBOOK* mbk )
{
  mbk->cbox_gui = CreateOneOfMany( mbk );
  
  wchar_t ustr[64];
  win12512unicode( ustr, mbk->cur_hp.cbox->name, MAXELEMS(ustr) - 1 );
  GUIObject_SetTitleText( mbk->cbox_gui, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ) );
  TEXTID* strid = (TEXTID*)malloc(sizeof(TEXTID)* mbk->cur_hp.cbox->max );
  
  for ( int i = 0; i < mbk->cur_hp.cbox->max; i ++ )
  {
    win12512unicode( ustr, mbk->cur_hp.cbox->items[i].cbox_text, MAXELEMS(ustr) - 1 );
    strid[i] = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
  }
  
  OneOfMany_SetTexts( mbk->cbox_gui, strid, mbk->cur_hp.cbox->max );
  mfree( strid );
  OneOfMany_SetChecked( mbk->cbox_gui, mbk->cur_hp.cbox->selected );
  GUIObject_SoftKeys_SetAction( mbk->cbox_gui, ACTION_BACK, OnCloseCBoxGui );
  GUIObject_SoftKeys_SetAction( mbk->cbox_gui, ACTION_SELECT1, OnSelectCBoxGui );
  GUIObject_Show( mbk->cbox_gui );
}

void OnBackBcfgGui( BOOK* bk, GUI* )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  BCFG_DATA* bdata = &mbk->bdata;
  CFG_HDR* hp;
  if( bdata->level )
  {
    hp = bdata->levelstack[ bdata->level ];
    bdata->levelstack[ bdata->level ] = 0;
    bdata->level -- ;
    FREE_GUI( mbk->bcfg );
    create_ed( bk, hp );
  }
  else
  {
    FreeBook( bk );
  }
}

void OnOkCreateUnicodeGui( BOOK* bk, wchar_t* string, int len )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  wchar_t ustr[64];
  if( len < mbk->cur_hp.wstr->min || len > mbk->cur_hp.wstr->max )
  {
    snwprintf( ustr, MAXELEMS(ustr) - 1, L"min_string_len: %d\nmax_string_len: %d", mbk->cur_hp.wstr->min, mbk->cur_hp.wstr->max );
    MessageBox_NoImage( EMPTY_TEXTID, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ), 1, 5000, mbk );
  }
  else
  {
    wstrncpy( &mbk->cur_hp.wstr->chars[0], string, mbk->cur_hp.wstr->max - 1 );
    FREE_GUI( mbk->text_input );
    RefreshEdList(mbk);
  }
}

void CreateUnicodeSI( MyBOOK* myBook, int is_pass )
{
  wchar_t ustr[64];
  int len;
  TEXTID text, header_name;
  
  len = myBook->cur_hp.wstr->max;
  
  if( len < 63 )
    len = 63;
  
  win12512unicode( ustr, myBook->cur_hp.wstr->name, len );
  header_name = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
  wstrncpy( ustr, &myBook->cur_hp.wstr->chars[0], len );
  text = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
  myBook->text_input = CreateStringInputVA(0,
                                           VAR_BOOK,myBook,
                                           VAR_HEADER_TEXT,header_name,
                                           VAR_STRINP_MIN_LEN,myBook->cur_hp.wstr->min,
                                           VAR_STRINP_MAX_LEN,myBook->cur_hp.wstr->max,
                                           VAR_STRINP_MODE,IT_STRING,
                                           VAR_STRINP_TEXT,text,
                                           VAR_PREV_ACTION_PROC,OnBackCreateTextInputGui,
                                           VAR_OK_PROC,OnOkCreateUnicodeGui,
                                           VAR_STRINP_IS_PASS_MODE,is_pass,
                                           0 );
}

void OnSelect1GuiBcfg( BOOK* bk, GUI* )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  BCFG_DATA* bdata = &mbk->bdata;
  int item = ListMenu_GetSelectedItem( mbk->bcfg );
  mbk->cur_hp.hdr = (CFG_HDR*) List_Get( mbk->list, item );
  switch( mbk->cur_hp.hdr->type )
  {
  case CFG_UINT:
    CreateUnsignedNumberInput( mbk );
    break;
  case CFG_CBOX:
    CreateCBoxGui( mbk );
    break;
  case CFG_COLOR_INT:
    CreateEditColorGUI( mbk, 1 );
    break;
  case CFG_LEVEL:
    bdata->level ++ ;
    bdata->levelstack[bdata->level] = mbk->cur_hp.hdr;
    GUIObject_Destroy( mbk->bcfg );
    mbk->bcfg = 0;
    create_ed( bk, 0 );
    return;
  case CFG_CHECKBOX:
    mbk->cur_hp.checkbox->isChecked = !mbk->cur_hp.checkbox->isChecked;
    ListMenu_SetItemSecondLineText( mbk->bcfg, item, (mbk->cur_hp.checkbox->isChecked ? mbk->check_box_checked : mbk->check_box_unchecked) );
    break;
  case CFG_FONT:
    CreateFontSelectGUI( mbk );
    break;
  case CFG_UTF16_STRING:
    CreateUnicodeSI( mbk, 0 );
    break;
  default:
    return;
  }
}

TEXTID GetSubItemText( MyBOOK* myBook, CFG_HDR* hp )
{
  wchar_t ustr[64];
  TEXTID str_id = EMPTY_TEXTID;
  if( hp )
  {
    switch( hp->type )
    {
    case CFG_UINT:
      snwprintf( ustr, MAXELEMS(ustr) - 1, L"%u", ((CFG_HDR_UNSIGNEDINT*)hp)->unsignedint );
      str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      break;
    case CFG_CBOX:
      win12512unicode( ustr, &((CFG_HDR_CBOX*)hp)->items[ ((CFG_HDR_CBOX*)hp)->selected ].cbox_text[0], MAXELEMS(ustr) - 1 );
      str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      break;
    case CFG_COLOR_INT:
      {
        unsigned int color = ((CFG_HDR_COLOR*)hp)->color;
        snwprintf( ustr, MAXELEMS(ustr) - 1, L"%02X, %02X, %02X, %02X", COLOR_GET_R( color ), COLOR_GET_G( color ), COLOR_GET_B( color ), COLOR_GET_A( color ) );
        str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      }
      break;
    case CFG_LEVEL:
      {
        win12512unicode( ustr, "[Enter]", MAXELEMS(ustr) - 1 );
        str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      }
      break;
    case CFG_CHECKBOX:
      str_id = ( ((CFG_HDR_CHECKBOX*)hp)->isChecked ? myBook->check_box_checked : myBook->check_box_unchecked );
      break;
    case CFG_FONT:
      str_id = TextID_Create( Font_GetNameByFontId( ((CFG_HDR_FONT*)hp)->font ), ENC_UCS2, TEXTID_ANY_LEN );
      break;
    case CFG_UTF16_STRING:
      str_id = TextID_Create( &((CFG_HDR_WSTR*)hp)->chars[0], ENC_UCS2, TEXTID_ANY_LEN );
      break;
    default:
      snwprintf( ustr, MAXELEMS(ustr) - 1, L"Type %d is not supporting yet", hp->type );
      str_id = TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN );
      break;
    }
  }
  return str_id;
}

// устанавливаем тексты в пунктах меню
int onLBMessage( GUI_MESSAGE* msg )
{
  MyBOOK* myBook = (MyBOOK*) GUIonMessage_GetBook( msg );
  
  switch( GUIonMessage_GetMsg( msg ) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    CFG_HDR* hp = (CFG_HDR*) List_Get( myBook->list, item );
    wchar_t ustr[32];
    win12512unicode( ustr, hp->name, MAXELEMS(ustr) - 1 );
    GUIonMessage_SetMenuItemText( msg, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ) );
    GUIonMessage_SetMenuItemInfoText( msg, TextID_Create( ustr, ENC_UCS2, TEXTID_ANY_LEN ) );
    int str_id = GetSubItemText( myBook, hp );
    
    if( str_id == EMPTY_TEXTID ) 
      str_id = TextID_Create ( L"Trash", ENC_UCS2, TEXTID_ANY_LEN );
    
    GUIonMessage_SetMenuItemSecondLineText( msg, str_id );
  }
  return 1;
};

TEXTID GetParentName( BCFG_DATA* bdata )
{
  wchar_t ustr[32];
  if( bdata->level )
  {
    CFG_HDR* hp = bdata->levelstack[bdata->level];
    win12512unicode( ustr, hp->name, MAXELEMS(ustr) - 1 );
  }
  else
  {
    wchar_t* ext = wstrrchr( bdata->name, '.' );
    int len = ext ? ext-bdata->name : MAXELEMS(ustr)-1;
    wstrncpy( ustr, bdata->name, len );
    ustr[len] = 0;
  }
  return TextID_Create( ustr, ENC_UCS2, MAXELEMS(ustr) - 1 );
}

// создание меню
GUI_LIST* CreateGuiList( MyBOOK* mbk, int set_focus )
{
  //GUI_LIST* lo;
  mbk->bcfg = CreateListMenu( mbk, UIDisplay_Main );
  //bk->bcfg = lo;
  GUIObject_SetTitleText( mbk->bcfg, GetParentName( &mbk->bdata ) );
  ListMenu_SetItemCount( mbk->bcfg, mbk->list->FirstFree );
  ListMenu_SetOnMessage( mbk->bcfg, onLBMessage );
  ListMenu_SetCursorToItem( mbk->bcfg, set_focus );
  ListMenu_SetItemStyle( mbk->bcfg, 3 );
  ListMenu_SetItemTextScroll( mbk->bcfg, 1 );
  GUIObject_SoftKeys_SetAction( mbk->bcfg, ACTION_BACK, OnBackBcfgGui );
  GUIObject_SoftKeys_SetAction( mbk->bcfg, ACTION_LONG_BACK, OnBackBcfgGui );
  GUIObject_SoftKeys_SetAction( mbk->bcfg, ACTION_SELECT1, OnSelect1GuiBcfg );
  return mbk->bcfg;
};

void RefreshEdList(BOOK * bk)
{
  MyBOOK* mbk = (MyBOOK*) bk;
  int pos = ListMenu_GetSelectedItem(mbk->bcfg);
  ListMenu_DestroyItems(mbk->bcfg);
  ListMenu_SetItemCount( mbk->bcfg, mbk->list->FirstFree );
  ListMenu_SetCursorToItem( mbk->bcfg, pos );
  GUIObject_SoftKeys_SetVisible( mbk->bcfg, ACTION_SELECT1, 1 );
}


GUI* create_ed( BOOK* book, CFG_HDR* need_to_focus )
{
  MyBOOK* mbk = (MyBOOK*) book;
  BCFG_DATA* bdata = &mbk->bdata;
  unsigned char* p = bdata->cfg;
  int n = bdata->size_cfg;
  CFG_HDR* hp;
  int need_to_jump = 0;
  LIST* list = mbk->list;
  
  while( list->FirstFree )
    List_RemoveAt( list, 0 );
  
  GUI* gui = NULL;
  
  int i;
  unsigned int curlev = 0;
  CFG_HDR* parent = 0;
  CFG_HDR* parents[16];
  
  bool error = false;
  
  while( !error && n >= sizeof( CFG_HDR ) )
  {
    hp = (CFG_HDR*) p;
    if( hp->type == CFG_LEVEL )
    {
      if( hp->min )
      {
        if( curlev == bdata->level && parent == bdata->levelstack[bdata->level] )
        {
          List_InsertLast( list, hp );
        }
      }
      else if( curlev )
      {
        parent = parents[curlev -- ];
      }
    }
    else
    {
      if( curlev == bdata->level && parent == bdata->levelstack[bdata->level] )
      {
        List_InsertLast( list, hp );
      }
    }
    n -= sizeof( CFG_HDR );
    p += sizeof( CFG_HDR );
    
    switch( hp->type )
    {
    case CFG_UINT:
      n -= sizeof( unsigned int );
      if( n < 0 )
        error = true;
      else
        p += sizeof( unsigned int );
      break;
    case CFG_CBOX:
      n -= hp->max * sizeof( CFG_CBOX_ITEM ) + 4;
      if( n < 0 )
        error = true;
      else
      {
        i =* ( ( int*)p );
        if( i >= hp->max )
          error = true;
        else
          p += hp->max * sizeof( CFG_CBOX_ITEM ) + 4;
      }
      break;
    case CFG_LEVEL:
      if( n < 0 )
      {
        error = true;
        break;
      }
      if( hp->min )
      {
        if( curlev == bdata->level && parent == bdata->levelstack[bdata->level] )
        {
          if( need_to_focus )
          {
            if( need_to_focus == hp )
              need_to_jump = list->FirstFree - 1;
          }
        }
        curlev ++ ;
        parents[curlev] = parent;
        parent = hp;
      }
      continue;
    case CFG_CHECKBOX:
      n -= sizeof(int) ;
      if( n < 0 )
        error = true;
      else
        p += sizeof(int) ;
      break;
      
    case CFG_COLOR_INT:
      n -= sizeof(int) ;
      if( n < 0 )
        error = true;
      else
        p += sizeof(int) ;
      break;
    case CFG_FONT:
      n -= sizeof(int) ;
      if( n < 0 )
        error = true;
      else
        p += sizeof(int) ;
      break;
    case CFG_UTF16_STRING:
      n -= ( ( ( hp->max + 1 )* 2 ) + 3 )&( ~3 );
      if( n < 0 )
        error = true;
      else
        p += ( ( ( hp->max + 1 )* 2 ) + 3 )&( ~3 );
      break;
    default:
      error = true;
      break;
    }
  }
  
  gui = CreateGuiList( mbk, need_to_jump );
  GUIObject_Show( gui );
  return gui;
}

static int RecreateEdPage( void* mess , BOOK* bk )
{
  RefreshEdList(bk);
  return 1;
}

static int CreateEdPageOnCreate( void* mess , BOOK* bk )
{
  MyBOOK* mbk = (MyBOOK*) bk;
  BCFG_DATA* bdata = &mbk->bdata;
  mbk->list = List_Create();
  
  textidname2id( IDN_CHECKBOX_UNCHECKED_ICON, - 1, &mbk->check_box_unchecked );
  textidname2id( IDN_CHECKBOX_CHECKED_ICON, - 1, &mbk->check_box_checked );

  int item = GetCurrentItem();
  wstrncpy( bdata->name, GetItemName(item), MAXELEMS(bdata->name) );
  bdata->cfg = (unsigned char*)GetItemCfg(item);
  bdata->size_cfg = GetItemCfgSize(item);

  create_ed( mbk, 0 );
  return 1;
}

const PAGE_MSG itemsbk_msglst_base[] = 
{
  CANCEL_EVENT,            Cancel_BasePage,
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT,               NULL
};

const PAGE_MSG itemsbk_msglst_main[] = 
{
  PAGE_ENTER_EVENT, ItemsMainPageOnCreate,
  NIL_EVENT,        NULL
};

const PAGE_DESC itemsbk_base = {"Items_Manager_Base_Page",0,itemsbk_msglst_base};
const PAGE_DESC itemsbk_main = {"Items_Manager_Main_Page",0,itemsbk_msglst_main};

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT,            Cancel_BasePage,
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT,               NULL
};

const PAGE_MSG bk_msglst_editor[] =
{
  PAGE_ENTER_EVENT, CreateEdPageOnCreate,
  ACCEPT_EVENT,     RecreateEdPage,
  NIL_EVENT,        NULL
};

const PAGE_DESC bk_editor = { "ItemsEdit_CreateEditor_Page", 0, bk_msglst_editor };
const PAGE_DESC bk_base = { "ItemsEdit_Base_Page", 0, bk_msglst_base };

static void onItemsBookClose(BOOK *book)
{
  ITEMSBOOK* m_bk = (ITEMSBOOK*)book;
  FREE_GUI(m_bk->gui);
}

void CreateItemsList()
{
   BOOK* myBook = (BOOK*) malloc(sizeof(ITEMSBOOK));
   memset(myBook,NULL,sizeof(ITEMSBOOK));  
   if(!CreateBook(myBook,onItemsBookClose,&itemsbk_base,"Items_Manager",-1,0)) mfree(myBook);
   else BookObj_GotoPage(myBook,&itemsbk_main);
}

static void onMyBookClose( BOOK* book )
{
  MyBOOK* mbk = (MyBOOK*) book;
  List_Destroy( mbk->list );
  LiteUpdateParams(get_mydata());
}

void CreateItemsEditor()
{
   MyBOOK* myBook = (MyBOOK *)malloc(sizeof(MyBOOK));
   memset(myBook,NULL,sizeof(MyBOOK));  
   if(!CreateBook(myBook,onMyBookClose,&bk_base,"Items_Editor",-1,NULL)) mfree(myBook);
   else BookObj_GotoPage(myBook,&bk_editor);
}

