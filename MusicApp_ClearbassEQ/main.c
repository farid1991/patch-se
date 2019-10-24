#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"

__thumb void* malloc( int size )
{
  return(memalloc(0xFFFFFFFF, size, 1, 5, "eq", NULL));
}

__thumb void mfree( void* mem )
{
  if(mem) memfree(NULL, mem, "eq", NULL);
}

const int settings_table [9][5] = {
  {   0,    0,   2,   4,   6   },  //Treble
  {   0,   -2,   2,   2,   0   },  //Heavy
  {   2,    2,   0,   0,  -2   },  //Pop
  {   0,    0,  -2,   0,   2   },  //Jazz
  {   0,    0,   0,   0,   0   },  //Normal
  {   0,    2,   0,  -2,   4   },  //Special
  {   0,    0,   4,   0,   0   },  //Soul
  {  -2,    0,   2,   0,   4   },  //Light
  {   6,    4,   0,   0,  -2   }   //Bass
};

void Set_ClearbassEq(MusicApplication_Book* MusicBook, int pos)
{
  MusicBook->pMusicServer->SetEqualizerGain(EqBand_63,settings_table[pos][0]);
  MusicBook->pMusicServer->SetEqualizerGain(EqBand_250,settings_table[pos][1]);
  MusicBook->pMusicServer->SetEqualizerGain(EqBand_1000,settings_table[pos][2]);
  MusicBook->pMusicServer->SetEqualizerGain(EqBand_4000,settings_table[pos][3]);
  MusicBook->pMusicServer->SetEqualizerGain(EqBand_16000,settings_table[pos][4]); 
}

void Save_LastEq(int EqPreset)
{
  int file;
  if (( file =_fopen( FPATH, L"EqPreset.bin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL)) >=0 )
  {
    EqPreset_File* FileData = (EqPreset_File*)malloc(sizeof(EqPreset_File));
    memset(FileData,NULL,sizeof(EqPreset_File));
    
    FileData->EqPreset = EqPreset;
    fwrite(file,FileData,sizeof(EqPreset_File));
    
    fclose(file);
    mfree(FileData);
  }
}

int Get_LastEq()
{
  int file, ret = 0;
  if ( (file=_fopen( FPATH, L"EqPreset.bin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    EqPreset_File *FileData = (EqPreset_File*)malloc(sizeof(EqPreset_File));
    memset(FileData,NULL,sizeof(EqPreset_File));
    fread(file, FileData, sizeof(EqPreset_File) );
    
    ret = FileData->EqPreset;

    fclose(file);
    mfree(FileData);
  }
  return ret;
}

void GetEqImageID(DISP_OBJ_CLEARBASS* disp_obj)
{
  wchar_t ImgName_buf[12];
  snwprintf(ImgName_buf,MAXELEMS(ImgName_buf),L"Img%d.png",disp_obj->cursor);
  FREE_IMAGE( disp_obj->EqIMG_ID );

  ImageID_Get( FPATH, ImgName_buf, &disp_obj->EqIMG_ID );
}

void DrawString_Params(int font, TEXTID text , int align, int XPos, int YPos, int width ,int NormalColor)
{
  SetFont(font);
  DrawString(text,align,XPos,YPos,XPos+width,YPos+(font&0xFF),0,0,NormalColor,clEmpty); 
}

int ClearbassGUI_OnCreate(DISP_OBJ_CLEARBASS* disp_obj)
{
  disp_obj->cursor = Get_LastEq()+1;
  disp_obj->count = 9;
  GetEqImageID(disp_obj);
  return 1;
}

void ClearbassGUI_OnClose(DISP_OBJ_CLEARBASS* disp_obj)
{
  FREE_IMAGE( disp_obj->EqIMG_ID );
}

void ClearbassGUI_OnRedraw(DISP_OBJ_CLEARBASS* disp_obj, int r1, int r2, int r3)
{
  int height = 320;
  int width = 240;
  
  int img_w = GetImageWidth(disp_obj->EqIMG_ID);
  int img_h = GetImageHeight(disp_obj->EqIMG_ID);
  GC_PutChar( get_DisplayGC(),
              (width-img_w)/2, (height-img_h)/2,
              img_w, img_h,
              disp_obj->EqIMG_ID );

  DrawString_Params(E_20R, TXT_EQUALIZER, UITextAlignment_Center, 0, 20, height, clWhite);
}

void ClearbassGUI_OnLayout(DISP_OBJ_CLEARBASS* disp_obj, void* layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clBlack);
}

void ClearbassGUI_OnKey(DISP_OBJ_CLEARBASS* disp_obj, int key, int unk, int repeat, int mode)
{
  if(mode==KBD_SHORT_PRESS || mode==KBD_REPEAT)
  {
    switch(key)
    {
    case KEY_RIGHT:
      if(disp_obj->cursor < disp_obj->count) disp_obj->cursor++;
      else disp_obj->cursor = 1;
      Set_ClearbassEq(disp_obj->MusicBook,disp_obj->cursor-1);
      GetEqImageID(disp_obj);
      break;
    case KEY_LEFT:
      if(disp_obj->cursor > 1) disp_obj->cursor--;
      else disp_obj->cursor = disp_obj->count;
      Set_ClearbassEq(disp_obj->MusicBook,disp_obj->cursor-1);
      GetEqImageID(disp_obj);
      break;
    }
  }
  DispObject_InvalidateRect(disp_obj, NULL);
}

void ClearbassGUI_constr(DISP_DESC* desc)
{
  DISP_DESC_SetName(desc, Gui_Clearbass);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_CLEARBASS));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD) ClearbassGUI_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD) ClearbassGUI_OnClose );
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD) ClearbassGUI_OnRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD) ClearbassGUI_OnLayout);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD) ClearbassGUI_OnKey);
}

void ClearbassGUI_destr( GUI* desc )
{
}

int ClearbassGUI_GetCurPos(DISP_OBJ_CLEARBASS* disp_obj)
{
  return disp_obj->cursor;
}

int ClearbassGUI_GetCurPos(GUI* gui)
{
  int ret = ClearbassGUI_GetCurPos((DISP_OBJ_CLEARBASS*)GUIObject_GetDispObject(gui));
  return ret-1;
}
/*
void Get_EqGain(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;

  //int a,b,c,d;
  //a = music_book->unk_37;
  //b = music_book->unk_4C;
  //c = music_book->unk_4D;
  //d = music_book->unk_60;
  //e=music_book->Eq.Band_16000;
  
  TMusicServer_Time time;
  MusicBook->pMusicServer->GetTime(&time);
  
  FUint32 Index;
  MusicBook->pMusicServer->GetCurrentItemIndex( &Index );
  
  wchar_t buf[512];
  snwprintf(buf,MAXELEMS(buf),L"%02d %02d %02d %d",time.hours,time.minutes,time.seconds,Index);
  MessageBox_NoImage(EMPTY_TEXTID,TextID_Create(buf,ENC_UCS2,TEXTID_ANY_LEN),0,0,book);
}
*/
void ClearbassGUI_SelectAction(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  int cur_pos = ClearbassGUI_GetCurPos(MusicBook->Gui_submenu);
  Set_ClearbassEq(MusicBook,cur_pos);
  Save_LastEq(cur_pos);
  FREE_GUI(MusicBook->Gui_submenu);
}

void ClearbassGUI_PrevAction(BOOK* book, GUI* gui)
{  
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  Set_ClearbassEq(MusicBook, Get_LastEq());
  FREE_GUI(MusicBook->Gui_submenu);
}

GUI* Create_ClearbassGUI(BOOK* book)
{
  GUI* gui_cb = (GUI*)malloc(sizeof(GUI));
  if(!GUIObject_Create(gui_cb, ClearbassGUI_destr, ClearbassGUI_constr, book, NULL, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(gui_cb);
    return NULL;
  }
  DISP_OBJ_CLEARBASS* disp_obj = (DISP_OBJ_CLEARBASS*) GUIObject_GetDispObject( gui_cb );
  
  disp_obj->MusicBook = (MusicApplication_Book*) book ;
    
  if(book) BookObj_AddGUIObject(book,gui_cb);
  
  GUIObject_SetStyle(gui_cb, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_cb, UI_TitleMode_None);
  GUIObject_SoftKeys_RemoveBackground(gui_cb);
  
  //GUIObject_SoftKeys_SetText(gui_cb, 0, STR("Set"));
  //GUIObject_SoftKeys_SetAction(gui_cb, 0, ClearbassGUI_SelectAction);
  //GUIObject_SoftKeys_SetText(gui_cb, 1, STR("Get"));
  //GUIObject_SoftKeys_SetAction(gui_cb, 1, Get_EqGain);
  
  GUIObject_SoftKeys_SetAction(gui_cb, ACTION_SELECT1, ClearbassGUI_SelectAction);
  GUIObject_SoftKeys_SetAction(gui_cb, ACTION_BACK, ClearbassGUI_PrevAction);
  GUIObject_SoftKeys_SetAction(gui_cb, ACTION_LONG_BACK, MusicApp_CancelAction);
  GUIObject_Show( gui_cb );
  return gui_cb;
}

extern "C"
int New_MusicApplication_Equalizer_MainPage( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FREE_GUI(MusicBook->Gui_submenu);
  
  if(MusicBook->Gui_submenu = Create_ClearbassGUI(MusicBook))
  {
    DispObject_SetAnimation( MusicBook->Gui_submenu->disp, 0xA0001021 );
  }
  return 1;
}

extern "C"
int New_MusicApplication_Equalizer_CancelAction( void* pData, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  Set_ClearbassEq(MusicBook, Get_LastEq());
  
  BookObj_ReturnPage(MusicBook,CANCEL_EVENT);
  return 1;
}

extern "C"
void New_SetEqualizerGain(MusicApplication_Book* MusicBook)
{
  Set_ClearbassEq(MusicBook, Get_LastEq());
}

/*
const PAGE_MSG MusicApplication_Equalizer[] = 
{
  PAGE_ENTER_EVENT,           New_MusicApplication_Equalizer_MainPage,
  PREVIOUS_EVENT,             pg_MusicApplication_UnplugPHF__PreviousAction,
  CANCEL_EVENT,               New_MusicApplication_Equalizer_CancelAction,
  UI_MEDIAPLAYER_UPDATE_EVENT,pg_MusicApplication_UnplugPHF__PreviousAction,
  PAGE_EXIT_EVENT,            pg_MusicApplication_UnplugPHF__ExitAction,
  NIL_EVENT,                  NULL
};

const PAGE_DESC MusicApplication_Equalizer_Page = {"MusicApplication_Equalizer_Page",NULL,MusicApplication_Equalizer};

*/
