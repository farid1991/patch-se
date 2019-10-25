/*
;A2 Walkman skinner
;Adds possibility to edit the Position,Color,Font
;Enable/Disable Title,Artist,Album,Genre,Total/Elapsed/Remaining time,Extension,Bit-rate,Total/Current track number,progress-bar,Album art
;Adds new items of Genre,Extension,Bit-rate,Overlay image to Walkman
;Adds possibility to edit position of icons shuffle/EQ/loop/state/wheel,Title/Artist/Album/Background/Overlay image
;Adds possibility to use skins in Walkman Player
;Adds skin editor for easy loading & editing of skins
;Adds possibility to use Walkman 4 visualization
;Redraws everything in Walkman,optimized for better Walkman experience
;v.1.3.3 mod
;(c) blacklizard
;(r) KreN
;(e) farid, D3mon, blacklizard
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

//#include "..\\include\MetaData.h"
#include "..\\include\classes\IMetaData.h"
#include "..\\include\types\AudioControl_types.h"

#include "..\\include\book\MusicApplication_Book.h"

#include "Function.h"
#include "LNG.h"
#include "SaveLoad.h"
#include "Visual.h"
#include "Viz.h"
#include "Walkman.h"

__thumb void* malloc( int size )
{
  return memalloc(0xFFFFFFFF, size, 1, 5, "wsk", NULL);
}

__thumb void mfree( void* mem )
{
  if (mem) memfree(NULL, mem, "wsk", NULL);
}

/*
void* operator new(size_t sz){return malloc(sz);};
void* operator new[](size_t sz){return malloc(sz);};
void operator delete(void * p){mfree(p);};
void operator delete[](void * p){mfree(p);};
*/

WALKMAN_Function *Create_WALKMAN_Function()
{
  WALKMAN_Function* Data = (WALKMAN_Function*)malloc(sizeof(WALKMAN_Function));
  memset(Data, NULL, sizeof(WALKMAN_Function));
  /*
  Data->CoverArtID = NULL;
  Data->IsAlbumArt = NULL;
  Data->Offset = NULL;
  Data->Size = NULL;
  Data->pImageType = NULL;
  Data->IsDRMProtected=0;
  Data->VolumeLevel=0;
  Data->CurrentTrackID = NULL;
  Data->TotalTrackID = NULL;
  Data->Bitrate = NULL;
  Data->VizIMG_ID = NOIMAGE;
  Data->VizID = 1;
  Data->m_smilgc = NULL;
  Data->kl = NULL;
  Data->gcmem_xsize = NULL;
  Data->timer = NULL;
  Data->WaitingTimer = NULL;
  Data->PlayState = NULL;
  Data->EqPreset = NULL;
  */  
  set_envp(NULL, EMP_NAME, (OSADDRESS)Data);
  return Data;
}

WALKMAN_Function* Get_WALKMAN_Function()
{
  WALKMAN_Function* Data = (WALKMAN_Function*) get_envp(NULL, EMP_NAME);
  if (Data) return Data;
  return Create_WALKMAN_Function();
}

extern "C"
void Delete_WALKMAN_Function()
{
  WALKMAN_Function* Data = (WALKMAN_Function*)get_envp(NULL, EMP_NAME);
  if (Data)
  {
    mfree(Data);
    set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
  }
}


void DrawString_Params(int font, TEXTID text, int align, int XPos, int YPos, int width ,int NormalColor)
{
  if (text && (text!=EMPTY_TEXTID))
  {
    SetFont(font);
    DrawString(text,align,XPos,YPos,XPos+width,YPos+(font&0xFF),60,0x05,NormalColor,clEmpty); 
  }
}

void GetMediaPlayerState(WALKMAN_Function* Data)
{
  if(Data->MusicBook->state==MEDIAPLAYER_STOP) Data->PlayState = PlayerState_Stop; //return 1;
  else if(Data->MusicBook->state==MEDIAPLAYER_PLAY) Data->PlayState = PlayerState_Play;//return 2;
  else if(Data->MusicBook->state==MEDIAPLAYER_PAUSE) Data->PlayState = PlayerState_Pause; //return 2;
  else if(Data->MusicBook->state==MEDIAPLAYER_FAST_FORWARD) Data->PlayState = PlayerState_FastForward; //return 3;
  else if(Data->MusicBook->state==MEDIAPLAYER_REWIND) Data->PlayState = PlayerState_Rewind; //return 4;
  //return 0;
}

void GetEqPreset(WALKMAN_Function* Data)
{
  if(Data->MusicBook->Eq_State==TMusicServerEqPreset_Normal) Data->EqPreset = EqPreset_Normal; 
  else if(Data->MusicBook->Eq_State==TMusicServerEqPreset_Bass) Data->EqPreset = EqPreset_Bass;
  else if(Data->MusicBook->Eq_State==TMusicServerEqPreset_Manual) Data->EqPreset = EqPreset_Manual;
  else if(Data->MusicBook->Eq_State==TMusicServerEqPreset_Megabass) Data->EqPreset = EqPreset_Megabass;
  else if(Data->MusicBook->Eq_State==TMusicServerEqPreset_TrebleBoost) Data->EqPreset = EqPreset_TrebleBoost;
  else if(Data->MusicBook->Eq_State==TMusicServerEqPreset_Voice) Data->EqPreset = EqPreset_Voice;
}

void GetLoopState(WALKMAN_Function* Data)
{
  if(Data->MusicBook->loop) Data->IsLoop = TRUE;
  else Data->IsLoop = FALSE;
}

void GetVolumeLevel(WALKMAN_Function* Data)
{
  char media;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  
  Data->VolumeLevel = media - 18;
}

void DrawIcon(IMAGEID img, int x, int y)
{
  if(img!=NOIMAGE) GC_DrawIcon( x, y, img );
}

void DrawImage( GC* gc, int x, int y, int w, int h, IMAGEID img )
{
  if(img!=NOIMAGE) GC_PutChar( gc, x, y, w, h, img );	
}

extern "C"
void New_WALKMAN_REDRAW(DISP_OBJ* obj, int a, int b, int c)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();

  GetLoopState(Data);
  GetEqPreset(Data);
  GetMediaPlayerState(Data);
  GetVolumeLevel(Data);
  
  char State;
  TEXTID SID;
  GC* gc = get_DisplayGC();
  
  if(Data->Main.Background_Image_Enable)
  {
    if(Data->Portrait) DrawIcon(Data->ImageID[1].ImageID, Data->Main.Background_Image_x1, Data->Main.Background_Image_y1);
    else
    {
      DrawIcon(Data->ImageID[0].ImageID, Data->Main.Background_Image_x1, Data->Main.Background_Image_y1);
    }
  }
  
  if(Data->Main.VisualisationEnable)
  {
    if(!Data->m_smilgc)
    {
      Data->m_br = GVI_CreateSolidBrush(clBlack);
      Data->m_hMGC = GC_CreateMemoryGC( Data->gcmem_xsize, 320, 16, 0, 0, 0 );
      CANVAS_Get_GviGC( Data->m_hMGC->pcanvas ,&Data->m_smilgc);
      GVI_FillRectangle( Data->m_smilgc, Data->Main.VIZRect.x1,Data->Main.VIZRect.y1, Data->gcmem_xsize, SCN_HEIGHT, Data->m_br );
      DrawImage( Data->m_hMGC, Data->Main.VIZRect.x1, Data->Main.VIZRect.y1, 0, 0, Data->VizImageID );
    }
    GVI_GC gvigc = NULL;
    CANVAS_Get_GviGC(gc->pcanvas, &gvigc);
    int bx = 0;
    int by = 0;
    if(!Data->Portrait)
    {
      bx = 40;
      by = 0;
    }
    GVI_BitBlt(gvigc,bx, by, SCN_WIDTH, SCN_HEIGHT, Data->m_smilgc, (SCN_WIDTH*(Data->kl)), 0, 204, 0, 2, 3);
    
    if (Data->kl > (((Data->gcmem_xsize)/SCN_WIDTH)-2))
    {
      Data->kl = 0;
    }
    else
    {
      Data->kl++;
    }
  }  
  
  if(Data->Main.AlbumArtEnable)
  {
    DrawImage( gc, Data->Main.ARect.x1, Data->Main.ARect.y1, Data->Main.ARect.x2-Data->Main.ARect.x1, Data->Main.ARect.y2-Data->Main.ARect.y1, Data->CoverArtID ); 
    DrawImage( gc, Data->Main.ARect.x1, Data->Main.ARect.y1, Data->Main.ARect.x2-Data->Main.ARect.x1, Data->Main.ARect.y2-Data->Main.ARect.y1, Data->ImageID[25].ImageID ); 
  }
  
  if(Data->Main.Overlay_Image_Enable)
  {
    if(Data->Portrait) DrawIcon(Data->ImageID[3].ImageID, Data->Main.Overlay_Image_x1, Data->Main.Overlay_Image_y1);
    else DrawIcon(Data->ImageID[24].ImageID, Data->Main.Overlay_Image_x1, Data->Main.Overlay_Image_y1);
  }
  
  if(Data->Main.EQ_Image_Enable)
  {
    State = Data->EqPreset;
    //if(State == TEqPreset_Voice) DrawIcon( Data->ImageID[5].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
    if(State == EqPreset_Bass) DrawIcon( Data->ImageID[26].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
    else if(State == EqPreset_Manual) DrawIcon( Data->ImageID[27].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
    else if(State == EqPreset_Megabass) DrawIcon( Data->ImageID[28].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
    else if(State == EqPreset_Normal) DrawIcon( Data->ImageID[29].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
    else if(State == EqPreset_TrebleBoost) DrawIcon( Data->ImageID[30].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
    else if(State == EqPreset_Voice) DrawIcon( Data->ImageID[31].ImageID, Data->Main.EQ_Image_x1, Data->Main.EQ_Image_y1);
  }
  
  if(Data->Main.Loop_Image_Enable)
  {
    if(Data->IsLoop) DrawIcon( Data->ImageID[6].ImageID, Data->Main.Loop_Image_x1, Data->Main.Loop_Image_y1);
    else if (get_envp(NULL,"RepeatOne")) DrawIcon( Data->ImageID[34].ImageID, Data->Main.Loop_Image_x1, Data->Main.Loop_Image_y1);
  }
  if(Data->Main.Shuffle_Image_Enable)
  {
    if(Data->IsShuffle) DrawIcon( Data->ImageID[7].ImageID, Data->Main.Shuffle_Image_x1, Data->Main.Shuffle_Image_y1);
  }
  
  if(Data->Main.Title_Image_Enable)
  {
    DrawIcon( Data->ImageID[14].ImageID, Data->Main.Title_Image_x1, Data->Main.Title_Image_y1);
  }
  if(Data->Main.Artist_Image_Enable)
  {
    DrawIcon( Data->ImageID[13].ImageID, Data->Main.Artist_Image_x1, Data->Main.Artist_Image_y1);
  }
  if(Data->Main.Album_Image_Enable)
  {
    DrawIcon( Data->ImageID[12].ImageID, Data->Main.Album_Image_x1, Data->Main.Album_Image_y1);
  }
  
  State = Data->PlayState;
  if(State == 1)
  {
    Data->IsPlaying = TRUE;
  }
  else if(State == 2)
  {
    Data->IsPlaying = FALSE;
  }
  if(Data->Main.PlayerState_Image_Enable)
  {
    State = Data->PlayState;
    if(State == 1) DrawIcon( Data->ImageID[9].ImageID, Data->Main.PlayerState_Image_x1, Data->Main.PlayerState_Image_y1);
    if(State == 2)
    {
      Data->IsPlayingTimerData = FALSE;
      DrawIcon( Data->ImageID[8].ImageID, Data->Main.PlayerState_Image_x1, Data->Main.PlayerState_Image_y1);
    }
    if(State == 3)
    {
      Data->IsPlayingTimerData = TRUE;
      DrawIcon( Data->ImageID[11].ImageID, Data->Main.PlayerState_Image_x1, Data->Main.PlayerState_Image_y1);
    }
    if(State == 4)
    {
      Data->IsPlayingTimerData =TRUE;
      DrawIcon( Data->ImageID[10].ImageID, Data->Main.PlayerState_Image_x1, Data->Main.PlayerState_Image_y1);
    }
  }
  
  if(Data->Main.WhellBG_Image_Enable)
  {
    DrawIcon( Data->ImageID[15].ImageID, Data->Main.WhellBG_Image_x1, Data->Main.WhellBG_Image_y1);
  }
  if(Data->Main.WhellUP_Image_Enable)
  {
    DrawIcon( Data->ImageID[23].ImageID, Data->Main.WhellUP_Image_x1, Data->Main.WhellUP_Image_y1);
  }
  if(Data->Main.WhellDOWN_Image_Enable)
  {
    DrawIcon( Data->ImageID[16].ImageID, Data->Main.WhellDOWN_Image_x1, Data->Main.WhellDOWN_Image_y1);
  }
  if(Data->Main.WhellLEFT_Image_Enable)
  {
    if(State == 4)DrawIcon( Data->ImageID[22].ImageID, Data->Main.WhellLEFT_Image_x1, Data->Main.WhellLEFT_Image_y1);
    else
    {
      DrawIcon( Data->ImageID[21].ImageID, Data->Main.WhellLEFT_Image_x1, Data->Main.WhellLEFT_Image_y1);
    }
  }
  if(Data->Main.WhellRIGHT_Image_Enable)
  {
    if(State == 3)DrawIcon( Data->ImageID[17].ImageID, Data->Main.WhellRIGHT_Image_x1, Data->Main.WhellRIGHT_Image_y1);
    else
    {
      DrawIcon( Data->ImageID[18].ImageID, Data->Main.WhellRIGHT_Image_x1, Data->Main.WhellRIGHT_Image_y1);
    }
  }
  if(Data->Main.WhellCENTER_Image_Enable)
  {
    if(Data->IsPlaying) DrawIcon( Data->ImageID[19].ImageID, Data->Main.WhellCENTER_Image_x1, Data->Main.WhellCENTER_Image_y1);
    else DrawIcon( Data->ImageID[20].ImageID, Data->Main.WhellCENTER_Image_x1, Data->Main.WhellCENTER_Image_y1);
  }
  
  if(Data->Main.Title_Enable)
  {
    SID = TextID_Create(Data->title,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Title_Font, SID ,Data->Main.Title_Align, Data->Main.Title_x1, Data->Main.Title_y1, Data->Main.Title_x2-Data->Main.Title_x1 ,Data->Main.Title_Color);
    TextID_Destroy(SID);
  }
  if(Data->Main.Artist_Enable)
  {
    SID = TextID_Create(Data->artist,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Artist_Font, SID ,Data->Main.Artist_Align, Data->Main.Artist_x1, Data->Main.Artist_y1, Data->Main.Artist_x2-Data->Main.Artist_x1 ,Data->Main.Artist_Color);
    TextID_Destroy(SID);
  }
  if(Data->Main.Album_Enable)
  {
    SID = TextID_Create(Data->album,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Album_Font, SID ,Data->Main.Album_Align, Data->Main.Album_x1, Data->Main.Album_y1, Data->Main.Album_x2-Data->Main.Album_x1 ,Data->Main.Album_Color);
    TextID_Destroy(SID);
  }
  if(Data->Main.Extension_Enable)
  {
    SID = TextID_Create(Data->ext,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Extension_Font, SID ,Data->Main.Extension_Align, Data->Main.Extension_x1, Data->Main.Extension_y1, Data->Main.Extension_x2-Data->Main.Extension_x1 ,Data->Main.Extension_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.C_TrackID_Enable)
  {
    snwprintf(Data->buffer,MAXELEMS(Data->buffer), L"%d / ", Data->CurrentTrackNumber );
    SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.C_TrackID_Font, SID ,Data->Main.C_TrackID_Align, Data->Main.C_TrackID_x1, Data->Main.C_TrackID_y1, Data->Main.C_TrackID_x2-Data->Main.C_TrackID_x1 ,Data->Main.C_TrackID_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.TotalTrackID_Enable)
  {
    SID = TextID_CreateIntegerID(Data->TotalTrackNumber);
    DrawString_Params(Data->Main.TotalTrackID_Font, SID ,Data->Main.TotalTrackID_Align, Data->Main.TotalTrackID_x1, Data->Main.TotalTrackID_y1, Data->Main.TotalTrackID_x2-Data->Main.TotalTrackID_x1 ,Data->Main.TotalTrackID_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.Genre_Enable)
  {
    SID = TextID_Create(Data->genre,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Genre_Font, SID ,Data->Main.Genre_Align, Data->Main.Genre_x1, Data->Main.Genre_y1, Data->Main.Genre_x2-Data->Main.Genre_x1 ,Data->Main.Genre_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.TotalTime_Enable)
  {
    //snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"0x%X:0x%X", Data->MusicBook->dummy_68, Data->MusicBook->dummy_69);
    snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"%02d:%02d", Data->FullTimeMinutes, Data->FullTimeSeconds);
    SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.TotalTime_Font, SID ,Data->Main.TotalTime_Align, Data->Main.TotalTime_x1, Data->Main.TotalTime_y1, Data->Main.TotalTime_x2-Data->Main.TotalTime_x1 ,Data->Main.TotalTime_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.ElapsedTime_Enable)
  {  
    //snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"0x%X:0x%X", Data->MusicBook->dummy_6A, Data->MusicBook->dummy_6B);
    snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"%02d:%02d", Data->ElapsedTimeMinutes, Data->ElapsedTimeSeconds);
    SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.ElapsedTime_Font, SID ,Data->Main.ElapsedTime_Align, Data->Main.ElapsedTime_x1, Data->Main.ElapsedTime_y1, Data->Main.ElapsedTime_x2-Data->Main.ElapsedTime_x1 ,Data->Main.ElapsedTime_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.RemainingTime_Enable)
  {
    int RemainingLengthInSeconds;
    RemainingLengthInSeconds = Data->FullTime - Data->ElapsedTime;
    snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"-%02d:%02d", RemainingLengthInSeconds/60,RemainingLengthInSeconds%60);
    SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.RemainingTime_Font, SID ,Data->Main.RemainingTime_Align, Data->Main.RemainingTime_x1, Data->Main.RemainingTime_y1, Data->Main.RemainingTime_x2-Data->Main.RemainingTime_x1 ,Data->Main.RemainingTime_Color);
    TextID_Destroy(SID);
  }  
  
  if(Data->Main.BitRate_Enable)
  {
    snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"%d kbps", Data->Bitrate);
    SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.BitRate_Font, SID ,Data->Main.BitRate_Align, Data->Main.BitRate_x1, Data->Main.BitRate_y1, Data->Main.BitRate_x2-Data->Main.BitRate_x1 ,Data->Main.BitRate_Color);
    TextID_Destroy(SID);
  }
  
  if(Data->Main.ProgressBarEnable)
  {
    DrawProgressBar( Data, Data->ElapsedTime, Data->FullTime, Data->Main.PRect, Data->Main.PBColor, Data->Main.PFColor);  
  }
  
  if(Data->Main.VolumeBarEnable)
  {
    DrawProgressBar( Data, Data->VolumeLevel, MAX_MEDIAVOLUME, Data->Main.VRect, Data->Main.VBColor, Data->Main.VFColor);  
  }
}

extern "C"
void TimerStart()
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->IsPlayingTimerData = TRUE;
}

extern "C"
void TimerKill()
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->IsPlayingTimerData = FALSE;
}

extern "C"
void New_WALKMAN_ONCREATE(DISP_OBJ* disp)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->Music_Gui_NowPlaying = disp;

  LoadImage(Data);
  BootViz(Data);

  WALKMAN_Default_ONCREATE(disp);
}


void KillAllTimer(WALKMAN_Function* Data)
{
  if(Data->timer)
  {
    Timer_Kill(&Data->timer);
    Data->timer = NULL;
  }
  
  if(Data->WaitingTimer)
  {
    Timer_Kill(&Data->WaitingTimer);
    Data->WaitingTimer = NULL;
  }
}


extern "C"
void New_ON_DESTROY(DISP_OBJ* disp)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  FreeImage(Data);
  KillAllTimer(Data);
  FreeViz(Data);
  WALKMAN_Default_ONDESTROY(disp);
}
/*
wchar_t* GetWSKPath()
{
  if (GetMemoryStickStatus()) return L"/card/other/ZBin/Config/WALKMAN";
  else return L"/usb/other/ZBin/Config/WALKMAN";
}
*/
void FreeViz(WALKMAN_Function* Data)
{
  if(Data->m_smilgc!=NULL)
  {
    Data->m_smilgc = NULL;
    GVI_Delete_GVI_Object( &Data->m_br );
    GC_FreeGC( Data->m_hMGC );
    
    ImageID_Free(Data->VizImageID);
  }
}

void BootViz(WALKMAN_Function* Data)
{
  Data->m_smilgc = NULL;
  if(GetChecked()==ITEM_VIZ)
  {    
    snwprintf(Data->VizName, MAXELEMS(Data->VizName), L"%d_Viz.png", GetSkinID());
    ImageID_Get( L"/card/other/ZBin/Config/WALKMAN/Viz", Data->VizName, &Data->VizImageID );
    Data->gcmem_xsize = GetImageWidth( Data->VizImageID );
    Data->gc = get_DisplayGC();
    Data->UpdateTime = 200;
  }
  else
  {
    Data->UpdateTime = 1000;
  }
}

extern "C"
int New_MUSIC_APP_ON_ENTER_PAGE_HOOK(void* data, BOOK* book)
{
  if(Default_MUSIC_APP_ON_ENTER_PAGE(data, book))
  {
    onfTimer(NULL,NULL);
  }
  return 1;  
}
/*
extern "C"
int New_MUSIC_APP_ON_EXIT_PAGE_HOOK(void* mess, BOOK* pMusicBook)
{
  if(Default_MUSIC_APP_ON_ENTER_PAGE(mess, pMusicBook))
  {
    onfTimer(NULL,NULL);
  }
  return 1;  
}
*/

TEXTID Info_Str()
{
  return STR(TXT_EDIT_THE_APPEARANCE_OF_WALKMAN_LAYOUT);
}

TEXTID Info_Viz()
{
  wchar_t skin_text[32];
  snwprintf(skin_text, MAXELEMS(skin_text), L"Total Style: %d", GetVizCount());
  return TextID_Create(skin_text,ENC_UCS2,TEXTID_ANY_LEN);
}

extern "C"
void SetNewSoftkey(GUI* mp_gui)
{
  GUIObject_SoftKeys_SetItemAsSubItem(mp_gui, ACTION_MP_SETTINGS, ACTION_MP_SKINEDITOR);
  GUIObject_SoftKeys_SetActionAndText(mp_gui, ACTION_MP_SKINEDITOR, Enter_WalkmanSkinEditor, TEXT_SKINS);
  GUIObject_SoftKeys_SetInfoText(mp_gui, ACTION_MP_SKINEDITOR, Info_Str());
  MediaPlayer_SoftKeys_SetItemAsSubItem(mp_gui,ACTION_MP_SETTINGS, ACTION_MP_SKINEDITOR);
  MediaPlayer_SoftKeys_SetAction(mp_gui, ACTION_MP_SKINEDITOR, Enter_WalkmanSkinEditor);
  MediaPlayer_SoftKeys_SetText(mp_gui, ACTION_MP_SKINEDITOR, TEXT_SKINS);
  MediaPlayer_SoftKeys_SetInfoText(mp_gui, ACTION_MP_SKINEDITOR, Info_Str());
/* -------------------------------------------------------------------------------------*/  
  GUIObject_SoftKeys_SetItemAsSubItem(mp_gui, ACTION_MP_SETTINGS, ACTION_MP_VISUALISATION);
  GUIObject_SoftKeys_SetActionAndText(mp_gui, ACTION_MP_VISUALISATION, Enter_VizSelector, TEXT_VISUALISATIONS);
  GUIObject_SoftKeys_SetInfoText(mp_gui, ACTION_MP_VISUALISATION, Info_Viz());
  MediaPlayer_SoftKeys_SetItemAsSubItem(mp_gui, ACTION_MP_SETTINGS, ACTION_MP_VISUALISATION);
  MediaPlayer_SoftKeys_SetAction(mp_gui, ACTION_MP_VISUALISATION, Enter_VizSelector);
  MediaPlayer_SoftKeys_SetText(mp_gui, ACTION_MP_VISUALISATION, TEXT_VISUALISATIONS);
  MediaPlayer_SoftKeys_SetInfoText(mp_gui, ACTION_MP_VISUALISATION, Info_Viz());

/* -------------------------------------------------------------------------------------
  GUIObject_SoftKeys_SetItemAsSubItem(mp_gui,ACTION_MP_SETTINGS,0x15);
  GUIObject_SoftKeys_SetActionAndText(mp_gui,0x15,New_Action_Test,STR("TEST"));
  MediaPlayer_SoftKeys_SetItemAsSubItem(mp_gui,ACTION_MP_SETTINGS,0x15);
  MediaPlayer_SoftKeys_SetAction(mp_gui,0x15,New_Action_Test);
  MediaPlayer_SoftKeys_SetText(mp_gui,0x15,STR("TEST"));
*/
}

int synchsafeToNormal(char tagSize[4])
{
  int synchsafe, sizeloc, size, power, x;
  
  size = sizeloc = 0;
  for(synchsafe = 31; synchsafe >= 0; synchsafe--)
  {
    if(GETBIT(tagSize, synchsafe))
    {
      power = 1;
      for(x = 0; x < sizeloc; x++) power *= 2;
      size += power;
    }
    if(SHIFT(synchsafe)) sizeloc++;
  }
  return size;
}

int get_tag_size(wchar_t* fullpath)
{
  int tag_size = NULL;
  int file = w_fopen(fullpath, WA_Read, FSX_S_IWRITE|FSX_S_IREAD, NULL);
  
  char buf[10 + 1];
  w_fread(file, buf, 10);
  if(buf[0]=='I' && buf[1]=='D' && buf[2]=='3')
  {
    char tagSize[4];
    tagSize[0] = buf[6];
    tagSize[1] = buf[7];
    tagSize[2] = buf[8];
    tagSize[3] = buf[9];
    tag_size = synchsafeToNormal(tagSize);
  }
  w_fclose(file);
  return tag_size;
}

int GetTrackBitrate(wchar_t* fullpath, int fulltime)
{
  int tag_size = get_tag_size(fullpath);
  
  W_FSTAT wstat;
  w_fstat(fullpath, &wstat );
  int SizeInKB = (wstat.st_size - tag_size)/1000;
  return (SizeInKB*8)/fulltime;
}

void GetCoverExist(WALKMAN_Function* Data)
{
  if(Data->CoverArtID && (Data->CoverArtID != Data->ImageID[2].ImageID))
  {
      ImageID_Free(Data->CoverArtID);
      Data->CoverArtID = NULL;
  }
  Data->CoverArtID = MetaData_GetCover(Data->fullpath);
}

void GetCoverNotExist(WALKMAN_Function* Data)
{
  if(Data->CoverArtID && (Data->CoverArtID != Data->ImageID[2].ImageID))
  {
      ImageID_Free(Data->CoverArtID);
      Data->CoverArtID = NULL;
  }
  Data->CoverArtID = Data->ImageID[2].ImageID;
}
/*
wchar_t* GetType_str(int cover_type)
{
  if (cover_type <= 3)
  {
    switch(cover_type)
    {
    case TMusicServer_AlbumArt_ImageType_Jpeg: return L"jpg";
    case TMusicServer_AlbumArt_ImageType_Gif: return L"gif";
    case TMusicServer_AlbumArt_ImageType_Png: return L"png";
    case TMusicServer_AlbumArt_ImageType_Bmp: return L"bmp";
    }
    return NULL;
  }
  return NULL;
}

void GetCover( wchar_t* ImageID, wchar_t* fullpath, int CoverSize, int CoverOffset, char cover_type)
{
  int file;
  if ((file = w_fopen(fullpath, WA_Read, 0x1FF, 0)))
  {
    if (w_lseek(file,CoverOffset,WSEEK_SET))
    {
      char* CoverBuff = (char*)malloc(CoverSize+1);
      memset(CoverBuff, NULL, CoverSize+1);
      w_fread(file,CoverBuff,CoverSize);
      ImageID_GetIndirect(CoverBuff,CoverSize,0,GetType_str(cover_type),&*ImageID);
    }
    w_fclose(file);
  } 
}
*/
bool isTagEmpty (wchar_t *tag)
{
  if (tag[0] == NULL) return TRUE;
  return FALSE;
}

void GetTrackData( UI_MEDIAPLAYER_NEW_TRACK_DATA* Track_Data, MusicApplication_Book* MusicBook )
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  //Data->IsLoop = Book_Data->Settings.Loop;
  //Data->IsShuffle = Book_Data->Settings.Random;
  MusicBook->pMusicServer->GetSettings_Boolean( TMusicServerSetting_Loop, &Data->IsLoop );
  MusicBook->pMusicServer->GetSettings_Boolean( TMusicServerSetting_Random, &Data->IsShuffle );
  
  Data->FullTime = (Track_Data->FullTime.hours*3600)+(Track_Data->FullTime.minutes*60)+Track_Data->FullTime.seconds;
  Data->FullTimeSeconds = Data->FullTime % 60;
  Data->TempTimeData = Data->FullTime - Data->FullTimeSeconds;
  Data->FullTimeMinutes = (Data->TempTimeData/60)%60;  
  
  Data->ElapsedTime = (Track_Data->ElapsedTime.hours*3600)+(Track_Data->ElapsedTime.minutes*60)+Track_Data->ElapsedTime.seconds;
  Data->ElapsedTimeSeconds = Data->ElapsedTime % 60;
  Data->TempTimeData = Data->ElapsedTime - Data->ElapsedTimeSeconds;
  Data->ElapsedTimeMinutes = (Data->TempTimeData/60)%60;  
  //
  //Book_Data->pMusicServer->GetFilename(Track_Data->track_id,128, Data->fullpath);
  //Book_Data->pMusicServer->GetItem(Track_Data->track_id,128,Data->artist,Data->album,Data->title);
  
  //TMusicServer_Time pPlaylength, pResumePosition;
  //TBool pContainsAlbumart, pIsRealMediaFile;
  //Data->CurrentTrackID = Track_Data->track_id;
  
  MusicBook->pMusicServer->GetFocusedItem(Track_Data->track_id, MUSIC_SERVER_MAX_URI_LENGTH, Data->artist, Data->album, Data->title, Data->fullpath,&Data->Playlength, &Data->ResumePosition, &Data->ContainsAlbumart, &Data->IsRealMediaFile);
  wstrcpy(Data->tempFullPath,Data->fullpath);
  
  if(isTagEmpty(Data->artist)) wstrcpy(Data->artist,L"Unknown Artist");  
  if(isTagEmpty(Data->album)) wstrcpy(Data->album,L"Unknown Album");  
  
  //Book_Data->pMusicServer->GetTrackFullpath(Track_Data->track_id, 128, Data->fullpath);
  //if(!MetaData_Desc_GetCoverInfo(MetaData_Desc,&Data->pImageType,&Data->Size, &Data->Offset))
  
  //IMAGEID image_id = ;
  
  if(Data->ContainsAlbumart) //image_id==NOIMAGE
  {
    //Data->IsAlbumArt = TRUE;
    //Book_Data->pMusicServer->GetTrackFullpath(Track_Data->track_id, 128, Data->fullpath);
    GetCoverExist(Data);
  }
  else
  {
    //Data->IsAlbumArt = FALSE;
    //Book_Data->pMusicServer->GetTrackFullpath(Track_Data->track_id, 128, Data->fullpath);
    GetCoverNotExist(Data);
  }
  
  //Book_Data->pMusicServer->GetTrackFullpath(Track_Data->track_id, 128, Data->fullpath);
  Data->Bitrate = GetTrackBitrate(Data->fullpath, Data->FullTime);
  
  Data->CurrentTrackNumber =  Track_Data->track_id+1;
  Data->TotalTrackNumber = MusicBook->tracks_count;
  
  wstrcpy(Data->ext,MusicBook->sub_exec->file_item->extension);
  wstrnupr(Data->ext, wstrlen(Data->ext));
  
  /*
  wstrnupr( Data->fullpath, wstrlen( Data->fullpath ));
  char* tmpext = new char[wstrlen(Data->fullpath)+1];
  wchar_t* wtmpext = new wchar_t[(wstrlen(Data->fullpath))*2+1];
  wstr2strn(tmpext,Data->fullpath,wstrlen(Data->fullpath));
  {
    Data->ext[0] = tmpext[strlen(tmpext)-3];
    Data->ext[1] = tmpext[strlen(tmpext)-2];
    Data->ext[2] = tmpext[strlen(tmpext)-1];
    delete tmpext;
    delete wtmpext;
    tmpext=0;
    wtmpext=0;
  }
  */
  
  //wstrcpy(Data->genre,MetaData_GetGenre(Data->fullpath));
  //wchar_t* name = wstrrchr(Data->fullpath, '/');
  //*name = NULL;
  //METADATA_DESC* MetaData_Desc = (METADATA_DESC*)MetaData_Desc_Create(Data->fullpath,name+1);
  //wstrcpy(Data->genre,MetaData_Desc_GetTags(MetaData_Desc,TMetadataTagId_Genre));
  //MetaData_Desc_Destroy(MetaData_Desc);
  //MetaData_GetGenre(Data, Data->tempFullPath);
  
  wchar_t* name = wstrrchr(Data->tempFullPath, '/');
  *name = 0;
  wchar_t* genre = MetaData_GetTags(Data->tempFullPath,name+1,TMetadataTagId_Genre);
  if(genre)
  {
    wstrcpy(Data->genre,genre);
    mfree(genre);
  }
  else wstrcpy(Data->genre,L"");
}

extern "C"
void New_ON_NEW_TRACK( void* data, BOOK* book )
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  UI_MEDIAPLAYER_NEW_TRACK_DATA* Track_Data =  (UI_MEDIAPLAYER_NEW_TRACK_DATA*)data;
   
  DefaultOnNewTrack(Track_Data, MusicBook);
  GetTrackData(Track_Data, MusicBook);
  
  GetLoopState(Data);
  GetEqPreset(Data);
  GetMediaPlayerState(Data);

  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
}

extern "C"
void New_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT( void* data, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*) book;
  UI_MEDIAPLAYER_AUDIO_PLAYING_TIME* TimeData = (UI_MEDIAPLAYER_AUDIO_PLAYING_TIME*) data;
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  //Data->MusicBook = MusicBook;
    
  Data->ElapsedTime = (TimeData->ElapsedTime.hours*3600)+(TimeData->ElapsedTime.minutes*60)+TimeData->ElapsedTime.seconds;
  Data->ElapsedTimeSeconds = Data->ElapsedTime % 60;
  Data->TempTimeData = Data->ElapsedTime - Data->ElapsedTimeSeconds;
  Data->ElapsedTimeMinutes = (Data->TempTimeData/60)%60;  
  
  //MusicApplication_Book* Book_Data = (MusicApplication_Book*)pMusicBook;
  //Data->IsLoop = Book_Data->Settings.Loop;
  //Data->IsShuffle = Book_Data->Settings.Random;
  MusicBook->pMusicServer->GetSettings_Boolean( TMusicServerSetting_Loop, &Data->IsLoop );
  MusicBook->pMusicServer->GetSettings_Boolean( TMusicServerSetting_Random, &Data->IsShuffle );
  
  wstrcpy(Data->ext,MusicBook->sub_exec->file_item->extension);
  wstrnupr(Data->ext, wstrlen(Data->ext));
  
  //GetLoopState(Data);
  GetEqPreset(Data);
  GetMediaPlayerState(Data);

  Default_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(TimeData,MusicBook);
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
}

/*
extern "C"
void New_PATCH_UI_MEDIAPLAYER_CREATED_EVENT(void *mess, BOOK *bk)
{
  Default_PATCH_UI_MEDIAPLAYER_CREATED_EVENT(mess, bk);
}
*/

void DrawProgressBar( WALKMAN_Function* Data, int value, int max_value, RECT rect, int Bcolor, int Ecolor )
{	
  int wid = rect.x2-rect.x1;
  int nx2 = rect.x1 + (value * wid / max_value);
  
  DrawRect( rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor );
  DrawRect( rect.x1, rect.y1, nx2, rect.y2, Ecolor, Ecolor );
  
  int blob_x = nx2-(Data->blob_w);
  int blob_y = (rect.y1-(Data->blob_h)) + ((rect.y2-rect.y1)/2);
  DrawIcon( Data->ImageID[4].ImageID, blob_x, blob_y);
  
  if(wid<=241) DrawIcon( Data->ImageID[32].ImageID, rect.x1, rect.y1 );		
  if(wid>=241) DrawIcon( Data->ImageID[33].ImageID, rect.x1, rect.y1 );		
}


void WaitingForPlayer (u16 timerID , void* )
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  if (Data->IsPlayingTimerData)
  {
    Timer_Kill(&Data->WaitingTimer);
    Data->WaitingTimer=0;
    Timer_ReSet(&Data->timer, Data->UpdateTime, MKTIMERPROC(onfTimer), 0); 
  }
  else
  {
    Timer_ReSet(&Data->WaitingTimer, 1000, MKTIMERPROC(WaitingForPlayer), 0); 
  }
}


void onfTimer (u16 timerID, void* )
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  if(Data->IsPlayingTimerData)
  {
    if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
    Timer_ReSet(&Data->timer, Data->UpdateTime, MKTIMERPROC(onfTimer), 0); 
  }
  else 
  {
    Timer_Kill(&Data->timer);
    Data->timer = 0;
    Timer_ReSet(&Data->WaitingTimer, 1000, MKTIMERPROC(WaitingForPlayer), 0); 
  }
}

void SetEnabled(MyBOOK* book, GUI* gui)
{
  if(book->Str_Enable)
  {
    book->Str_Enable = FALSE;
    ListMenu_SetItemSecondLineText( gui, 0, TEXT_NO );
  }
  else
  {
    book->Str_Enable = TRUE;
    ListMenu_SetItemSecondLineText( gui, 0, TEXT_YES );
  }
  book->ChangeMade = TRUE;
}

int onIconEditorMessage( GUI_MESSAGE* msg )
{
  MyBOOK* book = (MyBOOK*)GUIonMessage_GetBook(msg);
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    if (item == 0) 
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_DISABLED );
      if(book->Str_Enable)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_YES );
      else 
      {
        GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_NO );
      }
    }
    if (item == 1)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_POSITION );
      TEXTID SID[7];
      TEXTID TempSID = TextID_Create(", ",ENC_GSM,2);
      SID[0] = TextID_CreateIntegerID(book->Str_x1);
      SID[1] = TempSID;
      SID[2] = TextID_CreateIntegerID(book->Str_y1);
      SID[3] = TempSID;
      SID[4] = TextID_CreateIntegerID(book->Str_x2);
      SID[5] = TempSID;
      SID[6] = TextID_CreateIntegerID(book->Str_y2);
      TEXTID IDSID = TextID_Create(SID,ENC_TEXTID,7);
      GUIonMessage_SetMenuItemSecondLineText( msg, IDSID );
    }
    if (item == 2)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_BACKGROUND_COLOR );
      snwprintf( book->buffer, MAXELEMS(book->buffer), L"%X, %X, %X, %X", COLOR_GET_R(book->Str_Color),COLOR_GET_G(book->Str_Color),COLOR_GET_B(book->Str_Color),COLOR_GET_A(book->Str_Color) );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(book->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
    if (item == 3)  
    {
      GUIonMessage_SetMenuItemText( msg, STR(TXT_ELAPSED_BAR_COLOR) );
      snwprintf( book->buffer, MAXELEMS(book->buffer), L"%X, %X, %X, %X", COLOR_GET_R(book->Str_Color_2),COLOR_GET_G(book->Str_Color_2),COLOR_GET_B(book->Str_Color_2),COLOR_GET_A(book->Str_Color_2) );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(book->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
  }
  return 1;
}

void OnIconEditorBackGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  FREE_GUI(mbk->IconEdit);
}

void OnIconEditorSelectGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  int item=ListMenu_GetSelectedItem(mbk->IconEdit);
  if(item==0) SetEnabled(mbk, mbk->IconEdit);
  if(item==1) CreateEditCoordinatesGUI(mbk, 0);
}

void CreateIconEditorGUI(BOOK* book)
{
  MyBOOK* mbk = (MyBOOK*)book;
  mbk->IconEdit = CreateListMenu( mbk, UIDisplay_Main );
  GUIObject_SetTitleText( mbk->IconEdit, TextID_Create(mbk->Title_Str,ENC_UCS2,TEXTID_ANY_LEN) );
  GUIObject_SetTitleType( mbk->IconEdit, UI_TitleMode_Small );
  ListMenu_SetItemCount( mbk->IconEdit , 2 );
  ListMenu_SetOnMessage( mbk->IconEdit , onIconEditorMessage );
  ListMenu_SetCursorToItem( mbk->IconEdit , 0 );
  ListMenu_SetItemStyle( mbk->IconEdit , 3 );
  ListMenu_SetItemTextScroll( mbk->IconEdit , 1 );
  GUIObject_SoftKeys_SetAction( mbk->IconEdit , ACTION_BACK, OnIconEditorBackGui );
  GUIObject_SoftKeys_SetAction( mbk->IconEdit , ACTION_SELECT1, OnIconEditorSelectGui );
  GUIObject_Show(mbk->IconEdit);
}

void DestroyOOM( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FREE_GUI(mbk->Align_oom_menu);
}  

void oom_onEnter(  BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  mbk->Str_Align = OneOfMany_GetSelected(mbk->Align_oom_menu);
  
  if(mbk->Str_Align==UITextAlignment_Left) ListMenu_SetItemSecondLineText( mbk->StringEdit, 2, TEXT_LEFT );
  else if(mbk->Str_Align==UITextAlignment_Right) ListMenu_SetItemSecondLineText( mbk->StringEdit, 2, TEXT_RIGHT );
  else if(mbk->Str_Align==UITextAlignment_Center) ListMenu_SetItemSecondLineText( mbk->StringEdit, 2, STR(TXT_CENTER) );
  
  mbk->ChangeMade = TRUE;
  FREE_GUI(mbk->Align_oom_menu);
}

int oom_callback(GUI_MESSAGE* msg)
{
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    switch(GUIonMessage_GetCreatedItemIndex(msg))
    {
    case 0: GUIonMessage_SetMenuItemText( msg, TEXT_LEFT ); break;
    case 1: GUIonMessage_SetMenuItemText( msg, TEXT_RIGHT ); break;
    case 2: GUIonMessage_SetMenuItemText( msg, STR(TXT_CENTER) ); break;
    }
  }
  return(1);
}

void CreateOOMList(BOOK* book)
{
  MyBOOK* mbk = (MyBOOK*)book;
  mbk->Align_oom_menu = CreateOneOfMany(mbk);
  GUIObject_SetTitleText(mbk->Align_oom_menu,TEXT_ALIGN);
  OneOfMany_SetItemCount(mbk->Align_oom_menu,3);
  OneOfMany_SetOnMessage(mbk->Align_oom_menu,oom_callback);
  OneOfMany_SetChecked(mbk->Align_oom_menu,mbk->Str_Align);
  GUIObject_SoftKeys_SetAction(mbk->Align_oom_menu,ACTION_BACK,DestroyOOM);
  GUIObject_SoftKeys_SetAction(mbk->Align_oom_menu,ACTION_SELECT1,oom_onEnter);
  GUIObject_Show(mbk->Align_oom_menu);
}

int onStringEditorMessage( GUI_MESSAGE* msg )
{
  MyBOOK* book = (MyBOOK*)GUIonMessage_GetBook(msg);
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    if (item == 0) 
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_ENABLED );
      if(book->Str_Enable)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_YES );
      else 
      {
        GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_NO );
      }
    }
    if (item == 1)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_POSITION );
      snwprintf( book->buffer, MAXELEMS(book->buffer), L"X: %d, Y: %d, Width: %d",book->Str_x1,book->Str_y1,book->Str_x2-book->Str_x1);
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(book->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
    if (item == 2)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_ALIGN );
      if(book->Str_Align==UITextAlignment_Left)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_LEFT );
      else if(book->Str_Align==UITextAlignment_Right)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_RIGHT );
      else if(book->Str_Align==UITextAlignment_Center)GUIonMessage_SetMenuItemSecondLineText( msg, STR(TXT_CENTER) ); 
    }
    if (item == 3)
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_FONT_SIZE );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(Font_GetNameByFontId( book->Str_Font_Size ),ENC_UCS2,TEXTID_ANY_LEN) );
    }
    if (item == 4)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_TEXT_COLOR );  
      snwprintf( book->buffer, MAXELEMS(book->buffer), L"%X, %X, %X, %X", COLOR_GET_R(book->Str_Color),COLOR_GET_G(book->Str_Color),COLOR_GET_B(book->Str_Color),COLOR_GET_A(book->Str_Color) );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(book->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
  }
  return TRUE;
}

void OnStringEditorBackGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  FREE_GUI(mbk->StringEdit);
}

void OnStringEditorSelectGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  
  int item = ListMenu_GetSelectedItem(mbk->StringEdit);
  if(item==0) SetEnabled(mbk, mbk->StringEdit);
  if(item==1) 
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = FALSE;
    mbk->IsString = TRUE;
    CreateEditCoordinatesGUI(mbk, 1);
  }
  if(item==2) CreateOOMList( mbk );
  if(item==3) CreateFontSelectGUI( mbk );
  if(item==4) 
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = FALSE;
    mbk->IsString = TRUE;
    CreateEditColorGUI( mbk, 1 );
  }
}

void CreateStringEditorGUI(BOOK* book)
{
  MyBOOK* mbk = (MyBOOK*)book;
  mbk->StringEdit = CreateListMenu( mbk, UIDisplay_Main );
  GUIObject_SetTitleText( mbk->StringEdit, TextID_Create(mbk->Title_Str,ENC_UCS2,TEXTID_ANY_LEN) );
  GUIObject_SetTitleType( mbk->StringEdit, UI_TitleMode_Small );
  ListMenu_SetItemCount( mbk->StringEdit , 5 );
  ListMenu_SetOnMessage( mbk->StringEdit , onStringEditorMessage );
  ListMenu_SetCursorToItem( mbk->StringEdit , 0 );
  ListMenu_SetItemStyle( mbk->StringEdit , 3 );
  ListMenu_SetItemTextScroll( mbk->StringEdit , 1 );
  GUIObject_SoftKeys_SetAction( mbk->StringEdit , ACTION_BACK, OnStringEditorBackGui );
  GUIObject_SoftKeys_SetAction( mbk->StringEdit , ACTION_SELECT1, OnStringEditorSelectGui );
  GUIObject_Show( mbk->StringEdit );
}

void OnProgressBarSelectGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  
  int item = ListMenu_GetSelectedItem(mbk->ProgressBar);
  if(item==0) SetEnabled(mbk, mbk->ProgressBar);
  if(item==1) 
  {
    mbk->IsBbar = TRUE;
    mbk->IsFbar = TRUE;
    mbk->IsString = FALSE;
    CreateEditCoordinatesGUI(mbk, 1);
  }
  if(item==2) 
  {
    mbk->IsBbar = TRUE;
    mbk->IsFbar = FALSE;
    mbk->IsString = FALSE;
    CreateEditColorGUI( mbk, 1 );
  }
  if(item==3) 
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = TRUE;
    mbk->IsString = FALSE;
    CreateEditColorGUI( mbk, 1 );
  }
}

void OnProgressBarBackGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;  
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  FREE_GUI(mbk->ProgressBar);
}

void CreateProgressBarEditorGUI(BOOK* book)
{
  MyBOOK* mbk = (MyBOOK*)book; 
  mbk->ProgressBar = CreateListMenu( mbk, UIDisplay_Main );
  GUIObject_SetTitleText( mbk->ProgressBar, TextID_Create(mbk->Title_Str,ENC_UCS2,TEXTID_ANY_LEN) );
  GUIObject_SetTitleType( mbk->ProgressBar, UI_TitleMode_Small );
  ListMenu_SetItemCount( mbk->ProgressBar , 4 );
  ListMenu_SetOnMessage( mbk->ProgressBar , onIconEditorMessage );
  ListMenu_SetCursorToItem( mbk->ProgressBar , 0 );
  ListMenu_SetItemStyle( mbk->ProgressBar , 3 );
  ListMenu_SetItemTextScroll( mbk->ProgressBar , 1 );
  GUIObject_SoftKeys_SetAction( mbk->ProgressBar , ACTION_BACK, OnProgressBarBackGui );
  GUIObject_SoftKeys_SetAction( mbk->ProgressBar , ACTION_SELECT1, OnProgressBarSelectGui );
  GUIObject_Show(mbk->ProgressBar);
}

int onLinksLBMessage( GUI_MESSAGE* msg )
{
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    if (item == 0) GUIonMessage_SetMenuItemText( msg, TEXT_TITLE );
    if (item == 1) GUIonMessage_SetMenuItemText( msg, TEXT_ARTIST );
    if (item == 2) GUIonMessage_SetMenuItemText( msg, TEXT_ALBUM );
    if (item == 3) GUIonMessage_SetMenuItemText( msg, TEXT_GENRE );
    if (item == 4) GUIonMessage_SetMenuItemText( msg, STR(TXT_TOTAL_TIME) );
    if (item == 5) GUIonMessage_SetMenuItemText( msg, STR(TXT_ELAPSED_TIME) );
    if (item == 6) GUIonMessage_SetMenuItemText( msg, STR(TXT_REMAINING_TIME) );
    if (item == 7) GUIonMessage_SetMenuItemText( msg, STR(TXT_EXTENSION) );
    if (item == 8) GUIonMessage_SetMenuItemText( msg, STR(TXT_BITRATE) );
    if (item == 9) GUIonMessage_SetMenuItemText( msg, STR(TXT_TOTAL_TRACK_NUMBER) );
    if (item == 10) GUIonMessage_SetMenuItemText( msg, STR(TXT_CURRENT_TRACK_NUMBER) );
    if (item == 11) GUIonMessage_SetMenuItemText( msg, STR(TXT_SHUFFLE_ICON) );
    if (item == 12) GUIonMessage_SetMenuItemText( msg, STR(TXT_LOOP_ICON) );
    if (item == 13) GUIonMessage_SetMenuItemText( msg, STR(TXT_EQ_ICON) );
    if (item == 14) GUIonMessage_SetMenuItemText( msg, STR(TXT_PLAYER_STATE_ICON) );
    if (item == 15) GUIonMessage_SetMenuItemText( msg, STR(TXT_TITLE_ICON) );
    if (item == 16) GUIonMessage_SetMenuItemText( msg, STR(TXT_ARTIST_ICON) );
    if (item == 17) GUIonMessage_SetMenuItemText( msg, STR(TXT_ALBUM_ICON) );
    if (item == 18) GUIonMessage_SetMenuItemText( msg, STR(TXT_WHEEL_BG_ICON) );
    if (item == 19) GUIonMessage_SetMenuItemText( msg, STR(TXT_WHEEL_UP_ICON) );
    if (item == 20) GUIonMessage_SetMenuItemText( msg, STR(TXT_WHEEL_DOWN_ICON) );
    if (item == 21) GUIonMessage_SetMenuItemText( msg, STR(TXT_WHEEL_LEFT_ICON) );
    if (item == 22) GUIonMessage_SetMenuItemText( msg, STR(TXT_WHEEL_RIGHT_ICON) );
    if (item == 23) GUIonMessage_SetMenuItemText( msg, STR(TXT_WHEEL_CENTER_ICON) );
    if (item == 24) GUIonMessage_SetMenuItemText( msg, STR(TXT_BACKGROUND_IMAGE) );
    if (item == 25) GUIonMessage_SetMenuItemText( msg, STR(TXT_OVERLAY_IMAGE) );
    if (item == 26) GUIonMessage_SetMenuItemText( msg, STR(TXT_PROGRESS_BAR) );
    if (item == 27) 
    {
      GUIonMessage_SetMenuItemText( msg, STR(TXT_VOLUME_BAR) );
      //GUIonMessage_SetItemDisabled( msg, 1 );
      //GUIonMessage_SetMenuItemUnavailableText( msg, TEXT_DISABLED );
    }
    if (item == 28) GUIonMessage_SetMenuItemText( msg, TEXT_ALBUM_ART );
    
    if (item == 29) 
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_VISUALISATIONS );
      GUIonMessage_SetItemDisabled( msg, 1 );
      GUIonMessage_SetMenuItemUnavailableText( msg, TEXT_DISABLED );
    }
  }
  return 1;
}



int onLinksGUI( GUI_MESSAGE* msg )
{ 
  MyBOOK* book = (MyBOOK*)GUIonMessage_GetBook( msg );
  switch( GUIonMessage_GetMsg( msg ) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    if (item == 0)
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_FULLSCREEN );
      if(book->FullScreen)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_YES );
      else 
      {
        GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_NO );
      }
    }     
    if (item == 1) 
    {
      GUIonMessage_SetMenuItemText( msg, STR(TXT_SHOW_SOFTKEY) );
      if(book->ShowSoftKey)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_YES );
      else 
      {
        GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_NO );
      }
    }   
  }
  return 1;
}


void OnLinksEditorSelectGui( BOOK* bk, GUI* gui )
{
  MyBOOK* book = (MyBOOK*)bk;
  
  wstrcpy(book->Title_Str,L"UNDEFINED");
  int item = ListMenu_GetSelectedItem(book->portrait);
  book->ItemID=item;
  if(item==0) 
  {
    //book->ItemID=0;
    wstrcpy(book->Title_Str,L"Title");
    book->Str_Align=book->Title_Align;
    book->Str_Enable=book->Title_Enable;
    book->Str_Font_Size=book->Title_Font;
    book->Str_Color=book->Title_Color;
    book->Str_x1=book->Title_x1;
    book->Str_x2=book->Title_x2;
    book->Str_y1=book->Title_y1;
    book->Str_y2=book->Title_y2;
    CreateStringEditorGUI(book);
  }
  if(item==1) 
  {
    //book->ItemID=1;
    wstrcpy(book->Title_Str,L"Artist");
    book->Str_Align=book->Artist_Align;
    book->Str_Enable=book->Artist_Enable;
    book->Str_Font_Size=book->Artist_Font;
    book->Str_Color=book->Artist_Color;
    book->Str_x1=book->Artist_x1;
    book->Str_x2=book->Artist_x2;
    book->Str_y1=book->Artist_y1;
    book->Str_y2=book->Artist_y2;
    CreateStringEditorGUI(book);
  }
  if(item==2) 
  {
    //book->ItemID=2;
    wstrcpy(book->Title_Str,L"Album");
    book->Str_Align=book->Album_Align;
    book->Str_Enable=book->Album_Enable;
    book->Str_Font_Size=book->Album_Font;
    book->Str_Color=book->Album_Color;
    book->Str_x1=book->Album_x1;
    book->Str_x2=book->Album_x2;
    book->Str_y1=book->Album_y1;
    book->Str_y2=book->Album_y2;
    CreateStringEditorGUI(book);
  }
  if(item==3) 
  {
    //book->ItemID=3;
    wstrcpy(book->Title_Str,L"Genre");
    book->Str_Align=book->Genre_Align;
    book->Str_Enable=book->Genre_Enable;
    book->Str_Font_Size=book->Genre_Font;
    book->Str_Color=book->Genre_Color;
    book->Str_x1=book->Genre_x1;
    book->Str_x2=book->Genre_x2;
    book->Str_y1=book->Genre_y1;
    book->Str_y2=book->Genre_y2;
    CreateStringEditorGUI(book);
  }
  if(item==4) 
  {
    //book->ItemID=4;
    wstrcpy(book->Title_Str,L"Total Time");
    book->Str_Align=book->TotalTime_Align;
    book->Str_Enable=book->TotalTime_Enable;
    book->Str_Font_Size=book->TotalTime_Font;
    book->Str_Color=book->TotalTime_Color;
    book->Str_x1=book->TotalTime_x1;
    book->Str_x2=book->TotalTime_x2;
    book->Str_y1=book->TotalTime_y1;
    book->Str_y2=book->TotalTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==5) 
  {
    //book->ItemID=5;
    wstrcpy(book->Title_Str,L"Elapsed Time");
    book->Str_Align=book->ElapsedTime_Align;
    book->Str_Enable=book->ElapsedTime_Enable;
    book->Str_Font_Size=book->ElapsedTime_Font;
    book->Str_Color=book->ElapsedTime_Color;
    book->Str_x1=book->ElapsedTime_x1;
    book->Str_x2=book->ElapsedTime_x2;
    book->Str_y1=book->ElapsedTime_y1;
    book->Str_y2=book->ElapsedTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==6) 
  {
    //book->ItemID=6;
    wstrcpy(book->Title_Str,L"Remaining Time");
    book->Str_Align=book->RemainingTime_Align;
    book->Str_Enable=book->RemainingTime_Enable;
    book->Str_Font_Size=book->RemainingTime_Font;
    book->Str_Color=book->RemainingTime_Color;
    book->Str_x1=book->RemainingTime_x1;
    book->Str_x2=book->RemainingTime_x2;
    book->Str_y1=book->RemainingTime_y1;
    book->Str_y2=book->RemainingTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==7) 
  {
    //book->ItemID=7;
    wstrcpy(book->Title_Str,L"Extension");
    book->Str_Align=book->Extension_Align;
    book->Str_Enable=book->Extension_Enable;
    book->Str_Font_Size=book->Extension_Font;
    book->Str_Color=book->Extension_Color;
    book->Str_x1=book->Extension_x1;
    book->Str_x2=book->Extension_x2;
    book->Str_y1=book->Extension_y1;
    book->Str_y2=book->Extension_y2;
    CreateStringEditorGUI(book);
  }
  if(item==8) 
  {
    //book->ItemID=8;
    wstrcpy(book->Title_Str,L"Bitrate");
    book->Str_Align=book->BitRate_Align;
    book->Str_Enable=book->BitRate_Enable;
    book->Str_Font_Size=book->BitRate_Font;
    book->Str_Color=book->BitRate_Color;
    book->Str_x1=book->BitRate_x1;
    book->Str_x2=book->BitRate_x2;
    book->Str_y1=book->BitRate_y1;
    book->Str_y2=book->BitRate_y2;
    CreateStringEditorGUI(book);
  }
  if(item==9) 
  {
    //book->ItemID=9;
    wstrcpy(book->Title_Str,L"Total Track");
    book->Str_Align=book->TotalTrackID_Align;
    book->Str_Enable=book->TotalTrackID_Enable;
    book->Str_Font_Size=book->TotalTrackID_Font;
    book->Str_Color=book->TotalTrackID_Color;
    book->Str_x1=book->TotalTrackID_x1;
    book->Str_x2=book->TotalTrackID_x2;
    book->Str_y1=book->TotalTrackID_y1;
    book->Str_y2=book->TotalTrackID_y2;
    CreateStringEditorGUI(book);
  }
  if(item==10) 
  {
    //book->ItemID=10;
    wstrcpy(book->Title_Str,L"Current Track ID");
    book->Str_Align=book->C_TrackID_Align;
    book->Str_Enable=book->C_TrackID_Enable;
    book->Str_Font_Size=book->C_TrackID_Font;
    book->Str_Color=book->C_TrackID_Color;
    book->Str_x1=book->C_TrackID_x1;
    book->Str_x2=book->C_TrackID_x2;
    book->Str_y1=book->C_TrackID_y1;
    book->Str_y2=book->C_TrackID_y2;
    CreateStringEditorGUI(book);
  }
  if(item==11) 
  {
    //book->ItemID=11;
    wstrcpy(book->Title_Str,L"Shuffle Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Shuffle_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Shuffle_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Shuffle_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==12) 
  {
    //book->ItemID=12;
    wstrcpy(book->Title_Str,L"Loop Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Loop_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Loop_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Loop_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==13) 
  {
    //book->ItemID=13;
    wstrcpy(book->Title_Str,L"EQ Icon");
    book->Str_Align=0;
    book->Str_Enable=book->EQ_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->EQ_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->EQ_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }    
  if(item==14) 
  {
    //book->ItemID=14;
    wstrcpy(book->Title_Str,L"Player State Icon");
    book->Str_Align=0;
    book->Str_Enable=book->PlayerState_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->PlayerState_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->PlayerState_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  
  if(item==15) 
  {
    //book->ItemID=15;
    wstrcpy(book->Title_Str,L"Title Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Title_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Title_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Title_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==16) 
  {
    //book->ItemID=16;
    wstrcpy(book->Title_Str,L"Artist Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Artist_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Artist_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Artist_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==17) 
  {
    //book->ItemID=17;
    wstrcpy(book->Title_Str,L"Album Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Album_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Album_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Album_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==18)
  {
    //book->ItemID=18;
    wstrcpy(book->Title_Str,L"Wheel BG Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellBG_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellBG_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellBG_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==19)
  {
    //book->ItemID=19;
    wstrcpy(book->Title_Str,L"Wheel Up Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellUP_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellUP_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellUP_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==20)
  {
    //book->ItemID=20;
    wstrcpy(book->Title_Str,L"Wheel Down Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellDOWN_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellDOWN_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellDOWN_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==21)
  {
    //book->ItemID=21;
    wstrcpy(book->Title_Str,L"Wheel Left Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellLEFT_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellLEFT_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellLEFT_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==22)
  {
    //book->ItemID=22;
    wstrcpy(book->Title_Str,L"Wheel Right Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellRIGHT_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellRIGHT_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellRIGHT_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==23)
  {
    //book->ItemID=23;
    wstrcpy(book->Title_Str,L"Wheel Center Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellCENTER_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellCENTER_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellCENTER_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if (item == 24)   
  {
    //book->ItemID=24;
    wstrcpy(book->Title_Str,L"Background Image");
    book->Str_Align=0;
    book->Str_Enable=book->Background_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Background_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Background_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if (item == 25)   
  {
    //book->ItemID=25;
    wstrcpy(book->Title_Str,L"Overlay Image");
    book->Str_Align=0;
    book->Str_Enable=book->Overlay_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Overlay_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Overlay_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if (item == 26)
  {
    //book->ItemID=26;
    wstrcpy(book->Title_Str,L"Progress Bar");
    book->Str_Align=0;
    book->Str_Enable=book->ProgressBarEnable;
    book->Str_Font_Size=0;
    book->Str_Color=book->PBColor;
    book->Str_Color_2=book->PFColor;
    book->Str_x1=book->PRect.x1;
    book->Str_x2=book->PRect.x2;
    book->Str_y1=book->PRect.y1;
    book->Str_y2=book->PRect.y2;
    CreateProgressBarEditorGUI(book);
  }
  if (item == 27)
  {
    //book->ItemID=27;
    wstrcpy(book->Title_Str,L"Volume Bar");
    book->Str_Align=0;
    book->Str_Enable=book->VolumeBarEnable;
    book->Str_Font_Size=0;
    book->Str_Color=book->VBColor;
    book->Str_Color_2=book->VFColor;
    book->Str_x1=book->VRect.x1;
    book->Str_x2=book->VRect.x2;
    book->Str_y1=book->VRect.y1;
    book->Str_y2=book->VRect.y2;
    CreateProgressBarEditorGUI(book);
  }
  if (item == 28)
  {
    //book->ItemID=28;
    book->IsCover = TRUE;
    book->Str_x1=book->ARect.x1;
    book->Str_x2=book->ARect.x2;
    book->Str_y1=book->ARect.y1;
    book->Str_y2=book->ARect.y2;
    CreateEditCoordinatesGUI( book, 1 );
  }
  if (item == 29)
  {
    //book->ItemID=29;
    book->IsCover = TRUE;
    book->Str_x1=book->VRect.x1;
    book->Str_x2=book->VRect.x2;
    book->Str_y1=book->VRect.y1;
    book->Str_y2=book->VRect.y2;
    CreateEditCoordinatesGUI( book, 1 );
  }
}

void OnLinksLandEditorSelectGui( BOOK* bk, GUI* gui )
{
  MyBOOK* book = (MyBOOK*)bk;
  
  wstrcpy(book->Title_Str,L"UNDEFINED");
  int item = ListMenu_GetSelectedItem(book->land);
  book->ItemID=item+30;
  if(item==0) 
  {
    //book->ItemID=30;
    wstrcpy(book->Title_Str,L"Title");
    book->Str_Align=book->Land_Title_Align;
    book->Str_Enable=book->Land_Title_Enable;
    book->Str_Font_Size=book->Land_Title_Font;
    book->Str_Color=book->Land_Title_Color;
    book->Str_x1=book->Land_Title_x1;
    book->Str_x2=book->Land_Title_x2;
    book->Str_y1=book->Land_Title_y1;
    book->Str_y2=book->Land_Title_y2;
    CreateStringEditorGUI(book);
  }
  if(item==1) 
  {
    //book->ItemID=31;
    wstrcpy(book->Title_Str,L"Artist");
    book->Str_Align=book->Land_Artist_Align;
    book->Str_Enable=book->Land_Artist_Enable;
    book->Str_Font_Size=book->Land_Artist_Font;
    book->Str_Color=book->Land_Artist_Color;
    book->Str_x1=book->Land_Artist_x1;
    book->Str_x2=book->Land_Artist_x2;
    book->Str_y1=book->Land_Artist_y1;
    book->Str_y2=book->Land_Artist_y2;
    CreateStringEditorGUI(book);
  }
  if(item==2) 
  {
    //book->ItemID=32;
    wstrcpy(book->Title_Str,L"Album");
    book->Str_Align=book->Land_Album_Align;
    book->Str_Enable=book->Land_Album_Enable;
    book->Str_Font_Size=book->Land_Album_Font;
    book->Str_Color=book->Land_Album_Color;
    book->Str_x1=book->Land_Album_x1;
    book->Str_x2=book->Land_Album_x2;
    book->Str_y1=book->Land_Album_y1;
    book->Str_y2=book->Land_Album_y2;
    CreateStringEditorGUI(book);
  }
  if(item==3)
  {
    //book->ItemID=33;
    wstrcpy(book->Title_Str,L"Genre");
    book->Str_Align=book->Land_Genre_Align;
    book->Str_Enable=book->Land_Genre_Enable;
    book->Str_Font_Size=book->Land_Genre_Font;
    book->Str_Color=book->Land_Genre_Color;
    book->Str_x1=book->Land_Genre_x1;
    book->Str_x2=book->Land_Genre_x2;
    book->Str_y1=book->Land_Genre_y1;
    book->Str_y2=book->Land_Genre_y2;
    CreateStringEditorGUI(book);
  }
  if(item==4) 
  {
    //book->ItemID=34;
    wstrcpy(book->Title_Str,L"Total Time");
    book->Str_Align=book->Land_TotalTime_Align;
    book->Str_Enable=book->Land_TotalTime_Enable;
    book->Str_Font_Size=book->Land_TotalTime_Font;
    book->Str_Color=book->Land_TotalTime_Color;
    book->Str_x1=book->Land_TotalTime_x1;
    book->Str_x2=book->Land_TotalTime_x2;
    book->Str_y1=book->Land_TotalTime_y1;
    book->Str_y2=book->Land_TotalTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==5) 
  {
    //book->ItemID=35;
    wstrcpy(book->Title_Str,L"Elapsed Time");
    book->Str_Align=book->Land_ElapsedTime_Align;
    book->Str_Enable=book->Land_ElapsedTime_Enable;
    book->Str_Font_Size=book->Land_ElapsedTime_Font;
    book->Str_Color=book->Land_ElapsedTime_Color;
    book->Str_x1=book->Land_ElapsedTime_x1;
    book->Str_x2=book->Land_ElapsedTime_x2;
    book->Str_y1=book->Land_ElapsedTime_y1;
    book->Str_y2=book->Land_ElapsedTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==6) 
  {
    //book->ItemID=36;
    wstrcpy(book->Title_Str,L"Remaining Time");
    book->Str_Align=book->Land_RemainingTime_Align;
    book->Str_Enable=book->Land_RemainingTime_Enable;
    book->Str_Font_Size=book->Land_RemainingTime_Font;
    book->Str_Color=book->Land_RemainingTime_Color;
    book->Str_x1=book->Land_RemainingTime_x1;
    book->Str_x2=book->Land_RemainingTime_x2;
    book->Str_y1=book->Land_RemainingTime_y1;
    book->Str_y2=book->Land_RemainingTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==7) 
  {
    //book->ItemID=37;
    wstrcpy(book->Title_Str,L"Extension");
    book->Str_Align=book->Land_Extension_Align;
    book->Str_Enable=book->Land_Extension_Enable;
    book->Str_Font_Size=book->Land_Extension_Font;
    book->Str_Color=book->Land_Extension_Color;
    book->Str_x1=book->Land_Extension_x1;
    book->Str_x2=book->Land_Extension_x2;
    book->Str_y1=book->Land_Extension_y1;
    book->Str_y2=book->Land_Extension_y2;
    CreateStringEditorGUI(book);
  }
  if(item==8) 
  {
    //book->ItemID=38;
    wstrcpy(book->Title_Str,L"Bitrate");
    book->Str_Align=book->Land_BitRate_Align;
    book->Str_Enable=book->Land_BitRate_Enable;
    book->Str_Font_Size=book->Land_BitRate_Font;
    book->Str_Color=book->Land_BitRate_Color;
    book->Str_x1=book->Land_BitRate_x1;
    book->Str_x2=book->Land_BitRate_x2;
    book->Str_y1=book->Land_BitRate_y1;
    book->Str_y2=book->Land_BitRate_y2;
    CreateStringEditorGUI(book);
  }
  if(item==9) 
  {
    //book->ItemID=39;
    wstrcpy(book->Title_Str,L"Total Track");
    book->Str_Align=book->Land_TotalTrackID_Align;
    book->Str_Enable=book->Land_TotalTrackID_Enable;
    book->Str_Font_Size=book->Land_TotalTrackID_Font;
    book->Str_Color=book->Land_TotalTrackID_Color;
    book->Str_x1=book->Land_TotalTrackID_x1;
    book->Str_x2=book->Land_TotalTrackID_x2;
    book->Str_y1=book->Land_TotalTrackID_y1;
    book->Str_y2=book->Land_TotalTrackID_y2;
    CreateStringEditorGUI(book);
  }
  if(item==10) 
  {
    //book->ItemID=40;
    wstrcpy(book->Title_Str,L"Current Track ID");
    book->Str_Align=book->Land_C_TrackID_Align;
    book->Str_Enable=book->Land_C_TrackID_Enable;
    book->Str_Font_Size=book->Land_C_TrackID_Font;
    book->Str_Color=book->Land_C_TrackID_Color;
    book->Str_x1=book->Land_C_TrackID_x1;
    book->Str_x2=book->Land_C_TrackID_x2;
    book->Str_y1=book->Land_C_TrackID_y1;
    book->Str_y2=book->Land_C_TrackID_y2;
    CreateStringEditorGUI(book);
  }
  if(item==11) 
  {
    //book->ItemID=41;
    wstrcpy(book->Title_Str,L"Shuffle Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Shuffle_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Shuffle_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Shuffle_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==12) 
  {
    //book->ItemID=42;
    wstrcpy(book->Title_Str,L"Loop Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Loop_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Loop_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Loop_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==13) 
  {
    //book->ItemID=43;
    wstrcpy(book->Title_Str,L"EQ Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_EQ_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_EQ_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_EQ_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==14) 
  {
    //book->ItemID=44;
    wstrcpy(book->Title_Str,L"Player State Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_PlayerState_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_PlayerState_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_PlayerState_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==15) 
  {
    //book->ItemID=45;
    wstrcpy(book->Title_Str,L"Title Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Title_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Title_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Title_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==16) 
  {
    //book->ItemID=46;
    wstrcpy(book->Title_Str,L"Artist Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Artist_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Artist_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Artist_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==17) 
  {
    //book->ItemID=47;
    wstrcpy(book->Title_Str,L"Album Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Album_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Album_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Album_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==18)
  {
    //book->ItemID=48;
    wstrcpy(book->Title_Str,L"Wheel BG Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_WhellBG_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_WhellBG_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_WhellBG_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==19)
  {
    //book->ItemID=49;
    wstrcpy(book->Title_Str,L"Wheel Up Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_WhellUP_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_WhellUP_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_WhellUP_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==20)
  {
    //book->ItemID=50;
    wstrcpy(book->Title_Str,L"Wheel Down Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_WhellDOWN_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_WhellDOWN_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_WhellDOWN_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==21)
  {
    //book->ItemID=51;
    wstrcpy(book->Title_Str,L"Wheel Left Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_WhellLEFT_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_WhellLEFT_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_WhellLEFT_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==22)
  {
    //book->ItemID=52;
    wstrcpy(book->Title_Str,L"Wheel Right Icon");
    book->Str_Align=0;
    book->Str_Enable=book->Land_WhellRIGHT_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_WhellRIGHT_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_WhellRIGHT_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==23)
  {
    //book->ItemID=53;
    wstrcpy(book->Title_Str,L"Wheel Center Icon");
    book->Str_Align=0;
    book->Str_Enable=book->WhellCENTER_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->WhellCENTER_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->WhellCENTER_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  } 
  
  if (item == 24)   
  {
    //book->ItemID=54;
    wstrcpy(book->Title_Str,L"Background Image");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Background_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Background_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Background_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if (item == 25)   
  {
    //book->ItemID=55;
    wstrcpy(book->Title_Str,L"Overlay Image");
    book->Str_Align=0;
    book->Str_Enable=book->Land_Overlay_Image_Enable;
    book->Str_Font_Size=0;
    book->Str_Color=0;
    book->Str_x1=book->Land_Overlay_Image_x1;
    book->Str_x2=0;
    book->Str_y1=book->Land_Overlay_Image_y1;
    book->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if (item == 26)
  {
    //book->ItemID=56;
    wstrcpy(book->Title_Str,L"Progress Bar");
    book->Str_Align=0;
    book->Str_Enable=book->Land_ProgressBarEnable;
    book->Str_Font_Size=0;
    book->Str_Color=book->Land_PBColor;
    book->Str_Color_2=book->Land_PFColor;
    book->Str_x1=book->Land_PRect.x1;
    book->Str_x2=book->Land_PRect.x2;
    book->Str_y1=book->Land_PRect.y1;
    book->Str_y2=book->Land_PRect.y2;
    CreateProgressBarEditorGUI(book);
  }
  if (item == 27)
  {
    //book->ItemID=57;
    wstrcpy(book->Title_Str,L"Volume Bar");
    book->Str_Align=0;
    book->Str_Enable=book->Land_VolumeBarEnable;
    book->Str_Font_Size=0;
    book->Str_Color=book->Land_VBColor;
    book->Str_Color_2=book->Land_VFColor;
    book->Str_x1=book->Land_VRect.x1;
    book->Str_x2=book->Land_VRect.x2;
    book->Str_y1=book->Land_VRect.y1;
    book->Str_y2=book->Land_VRect.y2;
    CreateProgressBarEditorGUI(book);
  }
  if (item == 28)
  {
    //book->ItemID=58;
    book->IsCover = TRUE;
    book->Str_x1=book->Land_ARect.x1;
    book->Str_x2=book->Land_ARect.x2;
    book->Str_y1=book->Land_ARect.y1;
    book->Str_y2=book->Land_ARect.y2;
    CreateEditCoordinatesGUI( book, 1 );
  }
  if (item == 29)
  {
    //book->ItemID=59;
    book->IsCover = TRUE;
    book->Str_x1=book->Land_VRect.x1;
    book->Str_x2=book->Land_VRect.x2;
    book->Str_y1=book->Land_VRect.y1;
    book->Str_y2=book->Land_VRect.y2;
    CreateEditCoordinatesGUI( book, 1 );
  }
}

void FreeTabGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  
  FREE_GUI(gui);
  FREE_GUI(mbk->portrait);
  FREE_GUI(mbk->land);
  FREE_GUI(mbk->WalkmanGUI);
  FREE_GUI(mbk->tb);
}

void OnEditorLongBackGui( BOOK* book, GUI* gui )
{
  //FreeTabGui(book,gui);
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void OnEditorBackGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  if(mbk->ChangeMade) YesNoSaveSkinData(mbk);
  else FreeTabGui(book,gui);
}

void OnSave(BOOK* book, GUI* gui)
{
  MyBOOK* mbk = (MyBOOK*)book;
  SaveSkinData(mbk, mbk->path, mbk->name);
  
  FreeTabGui(book,gui);
  
  if(mbk->CreateNew) CreateSkinChooser(mbk);
}

void OnLinksWalkmanGUIEditorSelectGui( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  
  TEXTID txt;
  
  int item = ListMenu_GetSelectedItem(mbk->WalkmanGUI);
  if(item==0)
  {
    if(mbk->FullScreen) 
    {
      mbk->FullScreen = FALSE;
      txt = TEXT_NO;
      //ListMenu_SetItemSecondLineText( book->WalkmanGUI,0,STR(TXT_NO) );
    }
    else //if(!book->FullScreen) 
    {
      mbk->FullScreen = TRUE;
      txt = TEXT_YES;
      //ListMenu_SetItemSecondLineText( book->WalkmanGUI,0,STR(TXT_YES) );
    }
    mbk->GuiChanged = TRUE;
  }
  
  if(item==1)
  {
    if(mbk->ShowSoftKey) 
    {
      mbk->ShowSoftKey = FALSE;
      txt = TEXT_NO;
      //ListMenu_SetItemSecondLineText( book->WalkmanGUI,1,STR(TXT_NO) );
    }
    else //if(!book->ShowSoftKey) 
    {
      mbk->ShowSoftKey = TRUE;
      txt = TEXT_YES;
      //ListMenu_SetItemSecondLineText( book->WalkmanGUI,1,STR(TXT_YES) );
    }
  }
  ListMenu_SetItemSecondLineText( mbk->WalkmanGUI, item, txt );
  mbk->ChangeMade = TRUE;
}

void CreateTabGui( MyBOOK* book )
{
  //MyBOOK* book = (MyBOOK*)bk;
  book->tb = CreateTabMenuBar( book );
  TabMenuBar_SetTabCount( book->tb, 3 );
  TabMenuBar_SetTabIcon( book->tb, 0, MC_PORTRAIT_ICN, 0 );
  TabMenuBar_SetTabIcon( book->tb, 0, MC_PORTRAIT_ICN, 1 );
  TabMenuBar_SetTabIcon( book->tb, 1, MC_LANDSCAPE_ICN, 0 );
  TabMenuBar_SetTabIcon( book->tb, 1, MC_LANDSCAPE_ICN, 1 );
  TabMenuBar_SetTabIcon( book->tb, 2, RN_TAB_SESSION_MANAGER_DESELECTED_ICN, 0 );
  TabMenuBar_SetTabIcon( book->tb, 2, RN_TAB_SESSION_MANAGER_SELECTED_ICN, 1 );  
  
  book->portrait = CreateListMenu( book, UIDisplay_Main );
  ListMenu_SetItemCount( book->portrait, 30 );
  ListMenu_SetOnMessage( book->portrait, onLinksLBMessage );
  ListMenu_SetCursorToItem( book->portrait, 0 );
  ListMenu_SetItemStyle( book->portrait, 0 );
  ListMenu_SetItemTextScroll( book->portrait, 1 );
  GUIObject_SoftKeys_SetAction( book->portrait, ACTION_BACK, OnEditorBackGui );
  GUIObject_SoftKeys_SetAction( book->portrait, ACTION_LONG_BACK, OnEditorLongBackGui );
  GUIObject_SoftKeys_SetAction( book->portrait, ACTION_SELECT1, OnLinksEditorSelectGui );
  GUIObject_SoftKeys_SetAction( book->portrait, 0, OnSave );  
  GUIObject_SoftKeys_SetText( book->portrait, 0, TEXT_SAVE );  
  TabMenuBar_SetTabGui( book->tb, 0, book->portrait );
  TabMenuBar_SetTabTitle( book->tb, 0, TEXT_PORTRAIT );
  
  book->land = CreateListMenu( book, UIDisplay_Main );
  ListMenu_SetItemCount( book->land, 30);
  ListMenu_SetOnMessage( book->land, onLinksLBMessage );
  ListMenu_SetCursorToItem( book->land, 0 );
  ListMenu_SetItemStyle( book->land, 0 );
  ListMenu_SetItemTextScroll( book->land, 1 );
  GUIObject_SoftKeys_SetAction( book->land, ACTION_BACK, OnEditorBackGui );
  GUIObject_SoftKeys_SetAction( book->land, ACTION_LONG_BACK, OnEditorLongBackGui );
  GUIObject_SoftKeys_SetAction( book->land, ACTION_SELECT1, OnLinksLandEditorSelectGui );  
  GUIObject_SoftKeys_SetAction( book->land, 0, OnSave );  
  GUIObject_SoftKeys_SetText( book->land, 0, TEXT_SAVE );  
  TabMenuBar_SetTabGui( book->tb, 1, book->land );
  TabMenuBar_SetTabTitle( book->tb, 1, TEXT_LANDSCAPE );
  
  book->WalkmanGUI = CreateListMenu( book, UIDisplay_Main );
  ListMenu_SetItemCount( book->WalkmanGUI, 2);
  ListMenu_SetOnMessage( book->WalkmanGUI, onLinksGUI );
  ListMenu_SetCursorToItem( book->WalkmanGUI, 0 );
  ListMenu_SetItemStyle( book->WalkmanGUI, 1 );
  ListMenu_SetItemTextScroll( book->WalkmanGUI, 1 );
  GUIObject_SoftKeys_SetAction( book->WalkmanGUI, ACTION_BACK, OnEditorBackGui );
  GUIObject_SoftKeys_SetAction( book->WalkmanGUI, ACTION_LONG_BACK, OnEditorLongBackGui );
  GUIObject_SoftKeys_SetAction( book->WalkmanGUI, ACTION_SELECT1, OnLinksWalkmanGUIEditorSelectGui );  
  GUIObject_SoftKeys_SetAction( book->WalkmanGUI, 0, OnSave );  
  GUIObject_SoftKeys_SetText( book->WalkmanGUI, 0, TEXT_SAVE );
  TabMenuBar_SetTabGui( book->tb, 2, book->WalkmanGUI );
  TabMenuBar_SetTabTitle( book->tb, 2, STR(TXT_WALKMAN_GUI) );
  
  TabMenuBar_SetFocusedTab( book->tb, 0 );
  GUIObject_Show(book->tb);
}

int SelBcfg_BcfgFilter( const wchar_t* ExtList, const wchar_t* ItemPath, const wchar_t* ItemName )
{
  return DataBrowser_isFileInListExt( ExtList, ItemPath, ItemName );
}

int SelBcfgPageOnCreate( void* data, BOOK* book )
{
  MyBOOK* mbk = (MyBOOK*)book;
  
  void* DB_Desc = DataBrowserDesc_Create();
  const wchar_t* folder_list[2]={SKIN_PATH_EXTERNAL, SKIN_PATH_INTERNAL};
  DataBrowserDesc_SetHeaderText( DB_Desc, TEXT_SKINS );
  DataBrowserDesc_SetBookID( DB_Desc, BookObj_GetBookID(mbk) );
  DataBrowserDesc_SetFolders( DB_Desc, folder_list );
  DataBrowserDesc_SetFoldersNumber( DB_Desc, 2 );
  
  DataBrowserDesc_SetSelectAction( DB_Desc, 1 );
  DataBrowserDesc_SetFileExtList( DB_Desc, L"*.wsk" );
  DataBrowserDesc_SetItemFilter( DB_Desc, SelBcfg_BcfgFilter );
  
  DataBrowser_Create( DB_Desc );
  DataBrowserDesc_Destroy( DB_Desc );
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  /*
  if(Data->CoverArtID != Data->ImageID[2].ImageID)
  {
    ImageID_Free(Data->CoverArtID);
  }
  Data->CoverArtID = NULL;
  */
  return 1;
}

static int SelBcfgPageOnAccept( void* data, BOOK* book )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FILEITEM* fi = (FILEITEM*)data;
  wstrcpy( mbk->path, FILEITEM_GetPath(fi) );
  wstrcpy( mbk->name, FILEITEM_GetFname(fi) );
    
  FSTAT STAT;
  fstat( mbk->path, mbk->name, &STAT );
  if(STAT.fsize == NULL)
  {
    //goto config skin
    mbk->CreateNew = TRUE;
    YesNoConfigSkin(mbk);
  }
  else
  {
    //show list menu to apply or edit
    mbk->CreateNew = FALSE;
    LoadSkinData(mbk, mbk->path, mbk->name);
    CreateSkinChooser(mbk);
  }
  return 1;
}


static int SelBcfgPageOnCancel( void* data, BOOK* book )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FreeBook(mbk);
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  if(Data->Portrait)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }
  
  if(mbk->GuiChanged) BookObj_GotoPage( Data->MusicBook, (PAGE_DESC*)page_MusicApplication_Main );
  //MusicApp_PrevAction(Data->MusicBook,NULL);
  
  //wstrcpy(Data->fullpath,Data->tempFullPath);
  
  //METADATA_DESC* MetaData_Desc = (METADATA_DESC*)MetaData_Desc_Create(Data->fullpath);
  //if(!MetaData_Desc_GetCoverInfo(MetaData_Desc,&Data->pImageType,&Data->Size, &Data->Offset))
  //IMAGEID image_id;
  //image_id = MetaData_GetCover(Data->fullpath);
  if(!Data->ContainsAlbumart)
  {
    //Data->IsAlbumArt=FALSE;
    //wstrcpy(Data->fullpath,Data->tempFullPath);
    GetCoverNotExist(Data);  
  }
  else
  {
    //Data->IsAlbumArt=TRUE;
    //wstrcpy(Data->fullpath,Data->tempFullPath);
    GetCoverExist(Data);
  }
  //MetaData_Desc_Destroy(MetaData_Desc);
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
  
  return 1;
}

int Cancel_BasePage( void* data, BOOK* book )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FreeBook(mbk);
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  if(Data->Portrait)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }
  //MusicApp_PrevAction(Data->MusicBook,NULL);
  return 1;
}

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT,            Cancel_BasePage,
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT,               NULL
};

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT, SelBcfgPageOnCreate,
  ACCEPT_EVENT,     SelBcfgPageOnAccept,
  CANCEL_EVENT,     SelBcfgPageOnCancel,
  PREVIOUS_EVENT,   SelBcfgPageOnCancel,
  NIL_EVENT,        NULL
};

const PAGE_DESC SkinEditor_Base_Page = {"SkinEditor_Base_Page",0,bk_msglst_base};
const PAGE_DESC SkinEditor_Main_Page = {"SkinEditor_Main_Page",0,bk_msglst_main};

//===================================

void AskSave_OnBack(BOOK* book, GUI* gui)
{
  FREE_GUI(gui);
}

void AskSave_On_Yes(BOOK* book, GUI *gui)
{
  MyBOOK* mbk = (MyBOOK*)book;
  SaveSkinData(mbk, mbk->path, mbk->name);
  FreeTabGui(mbk,gui);
  
  mbk->ChangeMade = FALSE; //reset
    
  if(mbk->CreateNew) CreateSkinChooser(mbk);
}

void AskSave_On_No(BOOK* book, GUI *gui)
{
  MyBOOK* mbk = (MyBOOK*)book;
  FreeTabGui(mbk,gui);
  
  mbk->ChangeMade = FALSE; //reset
  mbk->GuiChanged= FALSE; //reset
  if(mbk->CreateNew) BookObj_GotoPage(mbk,&SkinEditor_Main_Page);
}

void YesNoSaveSkinData(BOOK* book)
{
  GUI* Question = CreateYesNoQuestionVA(0,
                                       VAR_BOOK,book,
                                       VAR_YESNO_PRE_QUESTION,TEXT_CHANGES_MADE,
                                       VAR_YESNO_QUESTION,TEXT_SAVE2,
                                       0);
  GUIObject_SoftKeys_SetAction(Question,ACTION_YES,AskSave_On_Yes);
  GUIObject_SoftKeys_SetAction(Question,ACTION_NO,AskSave_On_No);
  GUIObject_SoftKeys_SetAction(Question,ACTION_BACK,AskSave_OnBack);
}

void SaveSelectedPath(wchar_t* SkinPath, wchar_t* SkinName)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  wchar_t* Skin_FullPath = FSX_MakeFullPath(SkinPath,SkinName);
  wstrcpy( Data->SkinPath, Skin_FullPath );
  FSX_FreeFullPath(Skin_FullPath);
}

int CreateSkinChooser(BOOK* book)
{
  MyBOOK* mbk = (MyBOOK*)book;
  wstrcpy(mbk->temp, mbk->name);
  wchar_t* pos = wstrrchr(mbk->temp, '.');
  *pos = 0;
  wstrcpy(mbk->SkinName, mbk->temp);
  
  SaveSelectedPath(mbk->path, mbk->SkinName); 
  
  mbk->SkinChooser = CreateListMenu(mbk,UIDisplay_Main);
  GUIObject_SetTitleType(mbk->SkinChooser, UI_TitleMode_Large);
  GUIObject_SetTitleText(mbk->SkinChooser,TextID_Create(mbk->SkinName,ENC_UCS2,TEXTID_ANY_LEN));
  GUIObject_SetSecondRowTitleText(mbk->SkinChooser, TextID_Create(mbk->AuthorName,ENC_UCS2,TEXTID_ANY_LEN) );
  ListMenu_SetItemStyle(mbk->SkinChooser, 1);
  ListMenu_SetItemCount(mbk->SkinChooser, 2);
  ListMenu_SetOnMessage(mbk->SkinChooser,SkinChooser_callback);
  ListMenu_SetCursorToItem(mbk->SkinChooser, 0); 
  GUIObject_SoftKeys_SetAction(mbk->SkinChooser, ACTION_BACK, Close_SkinChooser);
  GUIObject_SoftKeys_SetAction(mbk->SkinChooser, ACTION_SELECT1, onEnter_SkinChooser);
  GUIObject_Show(mbk->SkinChooser);
  return 1;
}

int SetSkin(MyBOOK* book)
{
  WALKMAN_Function* WData = Get_WALKMAN_Function();
  FreeImage(WData);
  
  wchar_t Name[128] = L"";
  wstrcat(Name,book->SkinName); // Original
  wstrcat(Name,L".wsk");        // Original.wsk
  
 // wstrcat(SkinDataPath,book->path);     // /card/other/ZBin/Config/WALKMAN
  //wstrcat(SkinDataPath,L"/");           // /card/other/ZBin/Config/WALKMAN/
  //wstrcat(SkinDataPath,book->SkinName); // /card/other/ZBin/Config/WALKMAN/Original
  wchar_t* SkinDataPath = FSX_MakeFullPath(book->path,book->SkinName);
    
  int File;
  if(( File = _fopen( SKIN_PATH_EXTERNAL, L"CurrentSkin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL )) >=0 )
  {
    SKIN* SkinData = (SKIN*)malloc(sizeof(SKIN));
    memset(SkinData, NULL, sizeof(SKIN));
    
    wstrcpy(SkinData->SkinDataPath,SkinDataPath);
    wstrcpy(SkinData->Path,book->path);
    wstrcpy(SkinData->Name,Name);
    
    fwrite(File,SkinData,sizeof(SKIN));
    fclose(File);
    mfree(SkinData);
  }
  FSX_FreeFullPath(SkinDataPath);
  
  if(WData->Portrait)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }
  LoadImage(WData);
  
  SetGUIData(WData->MusicBook->Gui_NowPlaying);
  
  FreeViz(WData);
  if(GetChecked()==ITEM_VIZ) BootViz(WData);
  
  if(WData->Music_Gui_NowPlaying) DispObject_InvalidateRect(WData->Music_Gui_NowPlaying, NULL);
  
  return 1;
}

void onEnter_SkinChooser( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  switch(ListMenu_GetSelectedItem(mbk->SkinChooser))
  {
  case 0:
    if(SetSkin(mbk))
    {
      FREE_GUI(mbk->SkinChooser);
      SelBcfgPageOnCancel(NULL, mbk);
      MessageBox_NoImage( EMPTY_TEXTID, STR(TXT_SKIN_UPDATED), 0, 1000, book );
    }
    else 
    {
      MessageBox_NoImage( EMPTY_TEXTID, STR(TXT_SKIN_NOT_UPDATED), 0, 1000, book );
    }
    break;
  case 1:
    CreateTabGui(mbk);
    break;
  }
}

void Close_SkinChooser( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book; 
  FREE_GUI(mbk->SkinChooser);
  
  BookObj_GotoPage(mbk,&SkinEditor_Main_Page);
}

int SkinChooser_callback(GUI_MESSAGE * msg)
{
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    switch(GUIonMessage_GetCreatedItemIndex(msg))
    {
    case 0: 
      GUIonMessage_SetMenuItemText(msg,STR(TXT_SET_THIS_SKIN));
      GUIonMessage_SetMenuItemSecondLineText( msg,STR(TXT_SET_THIS_SKIN) );
      break;
    case 1:
      GUIonMessage_SetMenuItemText(msg,STR(TXT_EDIT_SKIN));
      GUIonMessage_SetMenuItemSecondLineText( msg, STR(TXT_EDIT_SKIN) );
      break;
    }
  }
  return 1;
}

//======================================================================

void OnOkCreateStringInput(BOOK* book, wchar_t* string, int len)
{
  MyBOOK* mbk = (MyBOOK*)book;
  wstrcpy(mbk->AuthorName, string);
  FREE_GUI(mbk->SI);
  CreateTabGui(mbk);
}

void OnBackCreateStringInput( BOOK* book, GUI* gui )
{
  MyBOOK* mbk = (MyBOOK*)book;
  FREE_GUI(mbk->SI);
  
  BookObj_GotoPage(mbk,&SkinEditor_Main_Page);
}

void EnterAuthorName(BOOK* book)
{
  MyBOOK* mbk = (MyBOOK*)book;
  mbk->SI = CreateStringInputVA(0,
                               VAR_BOOK,mbk,
                               VAR_STRINP_MODE,IT_STRING,
                               VAR_STRINP_NEW_LINE,1,
                               VAR_STRINP_MAX_LEN,100,
                               VAR_STRINP_MIN_LEN,1,
                               VAR_STRINP_FIXED_TEXT,STR(TXT_AUTHORS_NAME),
                               VAR_OK_PROC,OnOkCreateStringInput,
                               0);
  GUIObject_SoftKeys_SetAction(mbk->SI,ACTION_BACK,OnBackCreateStringInput);
}

//=============================================================================

void Self_OnBack(BOOK* book, GUI* gui)
{
  FREE_GUI(gui);
  BookObj_GotoPage(book,&SkinEditor_Main_Page);
}

void Self_On_Yes(BOOK* book, GUI* gui)
{
  FREE_GUI(gui);
  EnterAuthorName(book);
}

void YesNoConfigSkin(BOOK * book)
{
  GUI* Request = CreateYesNoQuestionVA(0,
                                       VAR_BOOK,book,
                                       VAR_YESNO_PRE_QUESTION,STR(TXT_SKIN_HASNT_BEEN_CONFIGURED_YET),
                                       VAR_YESNO_QUESTION,STR(TXT_CONFIGURE_NOW),
                                       0);
  GUIObject_SoftKeys_SetAction(Request,ACTION_YES,Self_On_Yes);
  GUIObject_SoftKeys_SetAction(Request,ACTION_NO,Self_OnBack);
  //GUIObject_SoftKeys_SetAction(Request,ACTION_BACK,Self_OnBack);
}

//======================================================================

void SkinEditor_Destroy(BOOK *book)
{
}

void Enter_WalkmanSkinEditor( BOOK* book, GUI* gui )
{
  //SomethingToBOOK(book);
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  MusicBook->unk_75 = TRUE;
  
  MyBOOK* mbk = (MyBOOK*)malloc(sizeof(MyBOOK));
  memset(mbk, NULL, sizeof(MyBOOK) );  
  if(!CreateBook(mbk, SkinEditor_Destroy, &SkinEditor_Base_Page, "WalkmanSkinEditor_Book", -1, 0)) mfree(mbk);
  else
  {
    BookObj_GotoPage(mbk,&SkinEditor_Main_Page);
  }
}

//==================================================
/*
void SomethingToBOOK(BOOK* book)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  MusicBook->unk_75 = TRUE;
}

extern "C"
void GetVolumeLevel(int level)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->VolumeLevel=level;
}
*/

void RegisterImage(IMG* img , wchar_t* path, wchar_t* fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->ImageID = NOIMAGE;
  img->ImageHandle = NOIMAGE;
  
  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC,&img->ImageHandle,&error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC,img->ImageHandle,path,fname,NULL,&img->ImageID,&error_code))
      if (error_code)
        img->ImageHandle = NOIMAGE;
}

void LoadImage(WALKMAN_Function* WData)
{
  //WALKMAN_Function* WData = Get_WALKMAN_Function();
  int File;
  if ( (File = _fopen( SKIN_PATH_EXTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    SKIN* SkinData = (SKIN*) malloc(sizeof(SKIN));
    memset( SkinData, NULL, sizeof(SKIN));
    fread( File, SkinData, sizeof(SKIN));
    WData->ImageDataName[0]=L"MP_BG_LD.png";
    WData->ImageDataName[1]=L"MP_BG_PT.png";
    WData->ImageDataName[2]=L"NO_COVER_ICN.png";
    WData->ImageDataName[3]=L"OVERLAY_IMAGE_P.png";
    WData->ImageDataName[4]=L"BLOB.png";
    WData->ImageDataName[5]=L"MP_EQ_STATUS_ICN.png";
    WData->ImageDataName[6]=L"MP_MODE_LOOP_ICN.png";
    WData->ImageDataName[7]=L"MP_MODE_RANDOM_ICN.png";
    WData->ImageDataName[8]=L"MP_PAUSE_ICN.png";
    WData->ImageDataName[9]=L"MP_PLAY_ICN.png";
    WData->ImageDataName[10]=L"MP_REWIND_ICN.png";
    WData->ImageDataName[11]=L"MP_FAST_FORWARD_ICN.png";
    WData->ImageDataName[12]=L"MP_ALBUM_ICN.png";
    WData->ImageDataName[13]=L"MP_ARTIST_ICN.png";
    WData->ImageDataName[14]=L"MP_TRACK_ICN.png";
    WData->ImageDataName[15]=L"MC_WHEEL_BACKGROUND_ICN.png";
    WData->ImageDataName[16]=L"MC_WHEEL_DOWN_ICN.png";
    WData->ImageDataName[17]=L"MC_WHEEL_FF_ICN.png";
    WData->ImageDataName[18]=L"MC_WHEEL_NEXT_ICN.png";
    WData->ImageDataName[19]=L"MC_WHEEL_PAUSE_ICN.png";
    WData->ImageDataName[20]=L"MC_WHEEL_PLAY_ICN.png";
    WData->ImageDataName[21]=L"MC_WHEEL_PREV_ICN.png";
    WData->ImageDataName[22]=L"MC_WHEEL_REW_ICN.png";
    WData->ImageDataName[23]=L"MC_WHEEL_UP_ICN.png";
    WData->ImageDataName[24]=L"OVERLAY_IMAGE_L.png";
    WData->ImageDataName[25]=L"REFLECT.png";
    WData->ImageDataName[26]=L"MP_EQ_BASS_ICN.png";
    WData->ImageDataName[27]=L"MP_EQ_MANUAL_ICN.png";
    WData->ImageDataName[28]=L"MP_EQ_MEGABASS_ICN.png";
    WData->ImageDataName[29]=L"MP_EQ_NORMAL_ICN.png";
    WData->ImageDataName[30]=L"MP_EQ_TREBLEBOOST_ICN.png";
    WData->ImageDataName[31]=L"MP_EQ_VOICE_ICN.png";
    WData->ImageDataName[32]=L"PROGRESSBAR_OVERLAY.png";
    WData->ImageDataName[33]=L"PROGRESSBAR_OVERLAY_LANDSCAPE.png";
    WData->ImageDataName[34]=L"MP_MODE_REPEAT_ONE_ICN.png";
    
    for (int i = 0 ; i < 35 ; i++)
    {
      if( FSX_IsFileExists( SkinData->SkinDataPath, WData->ImageDataName[i] ) )  
      {
        RegisterImage(&WData->ImageID[i], SkinData->SkinDataPath, WData->ImageDataName[i]);
      }
      else
      {
        WData->ImageID[i].ImageID = NOIMAGE;
      }
    }
    
    WData->blob_w = (GetImageWidth( WData->ImageID[4].ImageID ))/2;
    WData->blob_h = (GetImageHeight( WData->ImageID[4].ImageID ))/2;
    
    fclose(File);
    mfree(SkinData);
  }
}

void FreeImage(WALKMAN_Function * WData)
{
  //WALKMAN_Function * WData = Get_WALKMAN_Function();
  
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  
  if(WData->CoverArtID != WData->ImageID[2].ImageID)
  {
    ImageID_Free(WData->CoverArtID);
    //WData->CoverArtID = NULL;
  }
  //else
  //{
    WData->CoverArtID = NULL;
  //}
  
  int File;
  if ( (File = _fopen( SKIN_PATH_EXTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    SKIN* SkinData = (SKIN*)malloc(sizeof(SKIN));
    memset( SkinData, NULL, sizeof(SKIN) );
    fread( File, SkinData, sizeof(SKIN));
    WData->ImageDataName[0]=L"MP_BG_LD.png";
    WData->ImageDataName[1]=L"MP_BG_PT.png";
    WData->ImageDataName[2]=L"NO_COVER_ICN.png";
    WData->ImageDataName[3]=L"OVERLAY_IMAGE_P.png";
    WData->ImageDataName[4]=L"BLOB.png";
    WData->ImageDataName[5]=L"MP_EQ_STATUS_ICN.png";
    WData->ImageDataName[6]=L"MP_MODE_LOOP_ICN.png";
    WData->ImageDataName[7]=L"MP_MODE_RANDOM_ICN.png";
    WData->ImageDataName[8]=L"MP_PAUSE_ICN.png";
    WData->ImageDataName[9]=L"MP_PLAY_ICN.png";
    WData->ImageDataName[10]=L"MP_REWIND_ICN.png";
    WData->ImageDataName[11]=L"MP_FAST_FORWARD_ICN.png";
    WData->ImageDataName[12]=L"MP_ALBUM_ICN.png";
    WData->ImageDataName[13]=L"MP_ARTIST_ICN.png";
    WData->ImageDataName[14]=L"MP_TRACK_ICN.png";
    WData->ImageDataName[15]=L"MC_WHEEL_BACKGROUND_ICN.png";
    WData->ImageDataName[16]=L"MC_WHEEL_DOWN_ICN.png";
    WData->ImageDataName[17]=L"MC_WHEEL_FF_ICN.png";
    WData->ImageDataName[18]=L"MC_WHEEL_NEXT_ICN.png";
    WData->ImageDataName[19]=L"MC_WHEEL_PAUSE_ICN.png";
    WData->ImageDataName[20]=L"MC_WHEEL_PLAY_ICN.png";
    WData->ImageDataName[21]=L"MC_WHEEL_PREV_ICN.png";
    WData->ImageDataName[22]=L"MC_WHEEL_REW_ICN.png";
    WData->ImageDataName[23]=L"MC_WHEEL_UP_ICN.png";
    WData->ImageDataName[24]=L"OVERLAY_IMAGE_L.png";
    WData->ImageDataName[25]=L"REFLECT.png";
    WData->ImageDataName[26]=L"MP_EQ_BASS_ICN.png";
    WData->ImageDataName[27]=L"MP_EQ_MANUAL_ICN.png";
    WData->ImageDataName[28]=L"MP_EQ_MEGABASS_ICN.png";
    WData->ImageDataName[29]=L"MP_EQ_NORMAL_ICN.png";
    WData->ImageDataName[30]=L"MP_EQ_TREBLEBOOST_ICN.png";
    WData->ImageDataName[31]=L"MP_EQ_VOICE_ICN.png";
    WData->ImageDataName[32]=L"PROGRESSBAR_OVERLAY.png";
    WData->ImageDataName[33]=L"PROGRESSBAR_OVERLAY_LANDSCAPE.png";
    WData->ImageDataName[34]=L"MP_MODE_REPEAT_ONE_ICN.png";
    
    for (int i = 0 ; i < 35 ; i++)
    {
      if( FSX_IsFileExists(SkinData->SkinDataPath,WData->ImageDataName[i])) 
      {
        REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC,WData->ImageID[i].ImageHandle,0,0,WData->ImageID[i].ImageID,1,&error_code);
      }
      else
      {
        WData->ImageID[i].ImageID = NOIMAGE;
      }
    }
    fclose (File);
    mfree(SkinData);
  }
}
/*
extern "C"
void NewSecondLine( GUI_LIST* list, int elem_num, TEXTID id )
{
  ListMenu_SetItemSecondLineText( list, elem_num, id );
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  if(id==TURNON) Data->IsShuffle=TRUE;
  else if (id==TURNOFF) Data->IsShuffle=FALSE;
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
}
*/
extern "C"
void FixShuffle(bool state)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->IsShuffle = state;

  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
}

extern "C"
void FixLoop(bool state)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->IsLoop = state;
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
}

extern "C"
int New_PATCH_UI_MEDIAPLAYER_CREATED_EVENT( void* pUIMediaPlayer, BOOK* book)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  Default_PATCH_UI_MEDIAPLAYER_CREATED_EVENT(pUIMediaPlayer,MusicBook);
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->MusicBook = MusicBook;
  if(MusicBook->DisplayOrientation==UIDisplayOrientationMode_Vertical)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }
  return 1;
}

void SetGUIData(GUI* gui)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  if(Data->FullScreen)
  {
    GUIObject_SetStyle( gui, UI_OverlayStyle_TrueFullScreen);
    DispObject_SetStyle( Data->Music_Gui_NowPlaying, UI_OverlayStyle_TrueFullScreen);
  }
  else
  {
    GUIObject_SetStyle( gui, UI_OverlayStyle_Default);
    DispObject_SetStyle( Data->Music_Gui_NowPlaying, UI_OverlayStyle_Default);
  }
  
  if(Data->ShowSoftKey)
  {
    GUIObject_SoftKeys_Show(gui);
    DispObject_SoftKeys_Show(Data->Music_Gui_NowPlaying);
  }
  else
  {
    GUIObject_SoftKeys_Hide(gui);
    DispObject_SoftKeys_Hide(Data->Music_Gui_NowPlaying);
  }
}

/*
void LoadGUIData( wchar_t* path, wchar_t* name, GUI* gui)
{
  int file;
  if(( file = _fopen( path, name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    SkinData* skinData  = (SkinData*)malloc(sizeof(SkinData));
    memset( skinData, NULL, sizeof(SkinData) );
    fread( file, skinData, sizeof(SkinData) );
    
    WALKMAN_Function* Data = Get_WALKMAN_Function();
    Data->FullScreen = skinData->FullScreen;
    Data->ShowSoftKey = skinData->ShowSoftKey;
    
    SetGUIData(gui);
    
    if(!skinData->FullScreen)
    {
      GUIObject_SetStyle( gui, UI_OverlayStyle_FullScreenNoSoftkeys);
      DispObject_SetStyle( Data->Music_Gui_NowPlaying, UI_OverlayStyle_FullScreenNoSoftkeys);
    }
    else
    {
      GUIObject_SetStyle( gui, UI_OverlayStyle_TrueFullScreen);
      DispObject_SetStyle( Data->Music_Gui_NowPlaying, UI_OverlayStyle_TrueFullScreen);
    }
    if(!skinData->ShowSoftKey)
    {
      GUIObject_SoftKeys_Hide(gui);
      DispObject_SoftKeys_Hide(Data->Music_Gui_NowPlaying);
    }
    else
    {
      GUIObject_SoftKeys_Show(gui);
      DispObject_SoftKeys_Show(Data->Music_Gui_NowPlaying);
    }
    
    fclose(file);
    mfree(skinData);
  }
}
*/

extern "C"
void Set_WALKMAN_GUI_STYLE(GUI* gui)
{
  int File;
  if(( File = _fopen( SKIN_PATH_EXTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >= 0 )
  {
    SKIN* CurrentSkin = (SKIN*)malloc(sizeof(SKIN));
    memset(CurrentSkin, NULL, sizeof(SKIN));
    fread(File, CurrentSkin, sizeof(SKIN));
    //LoadGUIData( CurrentSkin->Path, CurrentSkin->Name, gui );
    int FSkin;
    if(( FSkin = _fopen( CurrentSkin->Path, CurrentSkin->Name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
    {
      SkinData* FSkinData = (SkinData*)malloc(sizeof(SkinData));
      memset(FSkinData, NULL, sizeof(SkinData));
      fread(FSkin, FSkinData, sizeof(SkinData));
      fclose(FSkin);
      
      WALKMAN_Function* Data = Get_WALKMAN_Function();
      Data->FullScreen = FSkinData->FullScreen;
      Data->ShowSoftKey = FSkinData->ShowSoftKey;
      mfree(FSkinData);
    }
    fclose(File);
    mfree(CurrentSkin);
  }
  SetGUIData(gui);
}
