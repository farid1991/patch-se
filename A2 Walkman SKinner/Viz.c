#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\MusicApplication_Book.h"

#include "Function.h"
#include "LNG.h"
#include "SaveLoad.h"
#include "Visual.h"
#include "Viz.h"
#include "Walkman.h"


int CreateOOMViz( void* pData, BOOK* book )
{
  WALKMAN_Function * Data = Get_WALKMAN_Function();
  //FreeViz(Data);
  //FREE_GUI(Data->VizOOM);
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FREE_GUI(MusicBook->Gui_submenu);

  if(MusicBook->Gui_submenu = CreateOneOfMany(MusicBook))
  {
    GUIObject_SetTitleText(MusicBook->Gui_submenu,STR(TXT_VISUALISATIONS));
    GUIObject_SetStyle(MusicBook->Gui_submenu,UI_OverlayStyle_PopupNoFrame);
    OneOfMany_SetItemCount(MusicBook->Gui_submenu,ITEM_LAST);
    OneOfMany_SetOnMessage(MusicBook->Gui_submenu,VIZOOM_callback);
    OneOfMany_SetChecked(MusicBook->Gui_submenu,GetChecked());
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu,ACTION_SELECT1,VizOOM_onEnter);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu,ACTION_BACK,DestroyVizOOM);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu,ACTION_LONG_BACK,MusicApp_CancelAction);
    GUIObject_Show(MusicBook->Gui_submenu);
  }
  return 1;
}

void DestroyVizOOM(BOOK* book, GUI* gui)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  //FreeViz(Data);
  //BootViz(Data);
  
  //FREE_GUI(Data->VizOOM);
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FREE_GUI(MusicBook->Gui_submenu);
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
  //BookObj_GotoPage( book, (PAGE_DESC*)page_MusicApplication_Main );
  //BookObj_ReturnPage( book, UI_MEDIAPLAYER_UPDATE_EVENT);
  MusicApp_PrevAction(MusicBook,NULL);
}

int VIZOOM_callback(GUI_MESSAGE * msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    switch(GUIonMessage_GetCreatedItemIndex(msg))
    {
    case 0: GUIonMessage_SetMenuItemText( msg, STR(TXT_ALBUM_ART) ); break;
    case 1: GUIonMessage_SetMenuItemText( msg, STR(TXT_STYLES)); break;
    case 2: GUIonMessage_SetMenuItemText( msg, STR(TXT_OFF) ); break;
    }
  }
  return 1;
}

const PAGE_MSG bk_Choose_Album_Art[] = 
{
  PAGE_ENTER_EVENT,           CreateOOMViz,
  PREVIOUS_EVENT,             pg_MusicApplication_SubMenu_PreviousAction,
  CANCEL_EVENT,               pg_MusicApplication_SubMenu_CancelAction,
  UI_MEDIAPLAYER_UPDATE_EVENT,pg_MusicApplication_SubMenu_PreviousAction,
  PAGE_EXIT_EVENT,            pg_MusicApplication_SubMenu_ExitAction,
  NIL_EVENT,                  NULL
};

const PAGE_DESC page_Choose_Album_Art = {"Choose_Album_Art_Page",NULL,bk_Choose_Album_Art};

void Enter_VizSelector(BOOK* book, GUI* gui)
{
  //SomethingToBOOK(book);
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  MusicBook->unk_75 = TRUE;
  BookObj_CallPage(MusicBook,&page_Choose_Album_Art);
}

int GetChecked()
{
  int ret = 0;
  
  int Lf;
  if( (Lf = _fopen( SKIN_PATH_EXTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL )) >=0 )
  {
    SKIN* LData  = (SKIN*)malloc(sizeof(SKIN));
    memset( LData, NULL, sizeof(SKIN) );
    fread( Lf, LData, sizeof(SKIN));
    
    int f;
    if( (f = _fopen( LData->Path, LData->Name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL )) >=0 )
    {
      SkinData* PData  = (SkinData*)malloc(sizeof(SkinData));
      memset( PData, NULL, sizeof(SkinData));
      fread( f, PData, sizeof(SkinData));
      
      if((PData->Land_AlbumArtEnable)&&(PData->AlbumArtEnable)) ret = 0;
      else if((PData->Land_VisualisationEnable)&&(PData->VisualisationEnable)) ret = 1;
      else if((!PData->Land_AlbumArtEnable)&&(!PData->Land_VisualisationEnable)&&(!PData->AlbumArtEnable)&&(!PData->VisualisationEnable)) ret=2;
      
      fclose(f);
      mfree(PData);
    }
    fclose(Lf);
    mfree(LData);
  }
  return ret;
}

void SetChecked(int level, BOOK* book)
{
  int Lf;
  WALKMAN_Function* WData = Get_WALKMAN_Function();
  if(( Lf = _fopen( SKIN_PATH_EXTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >= 0 )
  {
    SKIN* LData  = (SKIN*)malloc(sizeof(SKIN) );
    memset( LData, NULL, sizeof(SKIN) );
    fread( Lf, LData, sizeof(SKIN) );
    
    int f;
    if(( f = _fopen( LData->Path, LData->Name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >= 0 )
    {
      SkinData* Data  = (SkinData*)malloc(sizeof(SkinData));
      memset( Data, NULL, sizeof(SkinData));
      fread( f, Data, sizeof(SkinData));
      WData->VizData=*Data;
      fclose(f);
      mfree(Data);
    }
    
    if(level==ITEM_ALBUMART)
    {
      WData->VizData.Land_AlbumArtEnable = TRUE;
      WData->VizData.AlbumArtEnable = TRUE;
      WData->VizData.Land_VisualisationEnable = FALSE;
      WData->VizData.VisualisationEnable = FALSE;
    }
    else if(level==ITEM_VIZ)
    {
      WData->VizData.Land_AlbumArtEnable = FALSE;
      WData->VizData.AlbumArtEnable = FALSE;
      WData->VizData.Land_VisualisationEnable = TRUE;
      WData->VizData.VisualisationEnable = TRUE;
    }
    else if(level==ITEM_OFF)
    {
      WData->VizData.Land_AlbumArtEnable = FALSE;
      WData->VizData.AlbumArtEnable = FALSE;
      WData->VizData.Land_VisualisationEnable = FALSE;
      WData->VizData.VisualisationEnable = FALSE;
    }

    if(( f = _fopen( LData->Path, LData->Name, FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >= 0 )
    {
      SkinData* Data = (SkinData*)malloc(sizeof(SkinData));
      memset( Data, NULL, sizeof(SkinData) );	
      *Data = WData->VizData;
      fwrite( f, Data, sizeof(SkinData) );
      fclose(f);
      mfree(Data);
    }	
    fclose (Lf);
    mfree(LData);
  }
  FreeViz(WData);
  BootViz(WData);
  
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  FREE_GUI(mbk->Gui_submenu);
  
  if(WData->timer)
  {
    Timer_Kill( &WData->timer );
    WData->timer=0;
  }
  if(WData->WaitingTimer)
  {
    Timer_Kill(&WData->WaitingTimer);
    WData->WaitingTimer=0;
  }
  
  if(WData->Portrait)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }
  
  if(WData->Music_Gui_NowPlaying)DispObject_InvalidateRect(WData->Music_Gui_NowPlaying, NULL);
  
  if(WData->IsPlayingTimerData)
  {
    Timer_ReSet(&WData->timer, WData->UpdateTime, MKTIMERPROC(onfTimer), 0); 
  }
  else 
  {
    Timer_ReSet(&WData->WaitingTimer, 1000, MKTIMERPROC(WaitingForPlayer), 0); 
  }
  
  if(level==ITEM_ALBUMART)
  {
    WData->UpdateTime = 1000;
  }
  else if(level==ITEM_VIZ)
  {
    WData->UpdateTime = 200;
  }
  else if(level==ITEM_OFF)
  {
    WData->UpdateTime = 1000;
  }
}

int GetSkinID()
{
  int file;
  int ID = 0;
  if((file = _fopen( L"/card/other/ZBin/Config/WALKMAN/Viz",L"Viz", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    VizFileData* vData  = (VizFileData*)malloc(sizeof(VizFileData));
    memset( vData, NULL, sizeof(VizFileData));
    fread( file, vData, sizeof(VizFileData));
    ID = vData->ID;
    fclose(file);
    mfree(vData);
  }
  return ID;
}

int GetVizCount()
{
  int file_count = 1;

  wchar_t VizName_buf[12];
  snwprintf(VizName_buf,MAXELEMS(VizName_buf),L"%d.png",file_count);
  while (FSX_IsFileExists(L"/card/other/ZBin/Config/WALKMAN/Viz",VizName_buf))
  {
    file_count++;
    snwprintf (VizName_buf,MAXELEMS(VizName_buf),L"%d.png",file_count);
  }
  return (file_count-1);
}

void GetVizImageID(DISP_OBJ_VIZBOARD* disp_obj)
{
  wchar_t VizName_buf[12];
  snwprintf(VizName_buf,MAXELEMS(VizName_buf),L"%d.png",disp_obj->cursor);
  if(disp_obj->VizIMG_ID != NOIMAGE) ImageID_Free( disp_obj->VizIMG_ID );

  ImageID_Get( L"/card/other/ZBin/Config/WALKMAN/Viz", VizName_buf, &disp_obj->VizIMG_ID );
}

int VizBoard_OnCreate(DISP_OBJ_VIZBOARD* disp_obj)
{
  disp_obj->cursor = GetSkinID();
  disp_obj->count = GetVizCount();
  disp_obj->text_id = EMPTY_TEXTID;
  GetVizImageID(disp_obj);
  return 1;
}

void VizBoard_OnClose(DISP_OBJ_VIZBOARD* disp_obj)
{
  ImageID_Free( disp_obj->VizIMG_ID );
  disp_obj->VizIMG_ID = NOIMAGE;
}

void VizBoard_OnRedraw(DISP_OBJ_VIZBOARD* disp_obj, int r1, int r2, int r3)
{
  DrawIcon( disp_obj->VizIMG_ID, 0, 55 );

  SetFont(E_20R);
  disp_obj->text_id = TextID_Create(L"Select Style",ENC_UCS2,TEXTID_ANY_LEN);
  DrawString(disp_obj->text_id, 
             UITextAlignment_Center,
             0, 20, 240, 320,
             0, 0,
             clWhite, clEmpty );
  TextID_Destroy(disp_obj->text_id);

  wchar_t skin_text[10];
  snwprintf (skin_text,MAXELEMS(skin_text),L"Skin %d", disp_obj->cursor);
  disp_obj->text_id = TextID_Create(skin_text,ENC_UCS2,TEXTID_ANY_LEN);
  DrawString(disp_obj->text_id, 
             UITextAlignment_Center,
             0, 260, 240, 300, 
             20, 0,
             clWhite, clEmpty );
  TextID_Destroy(disp_obj->text_id);
}

void VizBoard_OnLayout(DISP_OBJ_VIZBOARD* disp_obj, void* layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clBlack);
}

void VizBoard_OnKey(DISP_OBJ_VIZBOARD* disp_obj, int key, int unk, int repeat, int mode)
{
  if(mode==KBD_SHORT_PRESS || mode==KBD_REPEAT)
  {
    switch(key)
    {
    case KEY_RIGHT:
     // if(disp_obj->cur_pos>=1 && disp_obj->cur_pos < disp_obj->count)
      //{
        //if(disp_obj->cur_pos > 0 && disp_obj->cur_pos < (disp_obj->count+1)) disp_obj->cur_pos++;
        if(disp_obj->cursor < disp_obj->count) disp_obj->cursor++;
        else  disp_obj->cursor=1;
        GetVizImageID(disp_obj);
      //}
      break;
    case KEY_LEFT:
      //if(disp_obj->cur_pos >= 1 && disp_obj->cur_pos <= disp_obj->count)
      //{
        //if(disp_obj->cur_pos > 1 && disp_obj->cur_pos<(disp_obj->count+1)) disp_obj->cur_pos--;
        if(disp_obj->cursor > 1) disp_obj->cursor--;
        else disp_obj->cursor=disp_obj->count;
        GetVizImageID(disp_obj);
      //}
      break;
    }
  }
  DispObject_InvalidateRect(disp_obj, NULL);
}

void VizBoardGUI_constr(DISP_DESC* desc)
{
  DISP_DESC_SetName(desc, Gui_VizBoard);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_VIZBOARD));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD) VizBoard_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD) VizBoard_OnClose );
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD) VizBoard_OnRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD) VizBoard_OnLayout);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD) VizBoard_OnKey);
}

void VizBoardGUI_destr( GUI* desc )
{
}

int VizBoardGUI_GetCursorPosition(GUI* gui)
{
  return ((DISP_OBJ_VIZBOARD*)GUIObject_GetDispObject(gui))->cursor;
}

void VizBoardGUI_PrevAction(BOOK* book, GUI* gui)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  FreeViz(Data);
  BootViz(Data);
  
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  FREE_GUI(mbk->Gui_submenu);
}

void VizBoardGUI_SelectAction(BOOK* book, GUI* gui)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  int cur_pos = VizBoardGUI_GetCursorPosition(mbk->Gui_submenu);
  
  int file;
  if(( file = _fopen( L"/card/other/ZBin/Config/WALKMAN/Viz", L"Viz", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >= 0 )
  {
    VizFileData* vData  = (VizFileData*)malloc(sizeof(VizFileData));
    memset( vData, NULL, sizeof(VizFileData) );	
    vData->ID = cur_pos;
    fwrite(file,vData,sizeof(VizFileData));
    fclose(file);
    mfree(vData);
  }	
  SetChecked(ITEM_VIZ, book);
}

GUI* Create_VizBoardGUI(BOOK* book)
{
  GUI* gui_board = (GUI*)malloc(sizeof(GUI));
  if(!GUIObject_Create(gui_board, VizBoardGUI_destr, VizBoardGUI_constr, book, NULL, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(gui_board);
    return NULL;
  }

  if(book) BookObj_AddGUIObject(book,gui_board);
  
  GUIObject_SetStyle(gui_board, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_board, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_board);
  GUIObject_SoftKeys_SetAction(gui_board,ACTION_SELECT1, VizBoardGUI_SelectAction);
  GUIObject_SoftKeys_SetAction(gui_board,ACTION_BACK, VizBoardGUI_PrevAction);
  GUIObject_SoftKeys_SetAction(gui_board,ACTION_LONG_BACK, MusicApp_CancelAction);
  GUIObject_Show( gui_board );
  return gui_board;
}

int Viz_Page_OnCreate( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FREE_GUI(MusicBook->Gui_submenu);
  
  if(MusicBook->Gui_submenu = Create_VizBoardGUI(MusicBook))
  {
    DispObject_SetAnimation( GUIObject_GetDispObject(MusicBook->Gui_submenu), 0xA0001021 );
  }
  return 1;
}

const PAGE_MSG Viz_msglst_main[] = 
{
  PAGE_ENTER_EVENT, Viz_Page_OnCreate,
  NIL_EVENT,        NULL
};

const PAGE_DESC MusicApplication_Viz_Page = {"MusicApplication_Viz_Page",NULL,Viz_msglst_main};

void Goto_VizGUI( BOOK* book )
{
  BookObj_GotoPage(book,&MusicApplication_Viz_Page);
}

void VizOOM_onEnter(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  int item = ListMenu_GetSelectedItem(MusicBook->Gui_submenu);
  
  if(item==ITEM_VIZ) Goto_VizGUI(MusicBook);
  else SetChecked(item,MusicBook);
}
