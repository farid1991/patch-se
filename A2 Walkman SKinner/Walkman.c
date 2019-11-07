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
;(e) farid, D3mon
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "..\\include\book\MusicApplication_Book.h"

#include "Function.h"
#include "LNG.h"
#include "SaveLoad.h"
#include "strlib.h"
#include "Visual.h"
#include "Viz.h"
#include "Walkman.h"

__thumb void *malloc( int size )
{
  return memalloc(0xFFFFFFFF, size, 1, 5, "wsk", NULL);
}

__thumb void mfree( void *mem )
{
  if (mem) memfree(NULL, mem, "wsk", NULL);
}

WALKMAN_Function *Create_WALKMAN_Function()
{
  WALKMAN_Function* Data = (WALKMAN_Function*)malloc(sizeof(WALKMAN_Function));
  memset(Data, NULL, sizeof(WALKMAN_Function));
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
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString( text, font, align, XPos, YPos, XPos+width, YPos+(font&0xFF), NormalColor);
#else
    SetFont(font);
    DrawString(text,align,XPos,YPos,XPos+width,YPos+(font&0xFF),60,0x05,NormalColor,clEmpty); 
#endif
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
  if(Data->MusicBook->EQ_Preset==TMusicServerEqPreset_Normal) Data->EqPreset = EqPreset_Normal; 
  else if(Data->MusicBook->EQ_Preset==TMusicServerEqPreset_Bass) Data->EqPreset = EqPreset_Bass;
  else if(Data->MusicBook->EQ_Preset==TMusicServerEqPreset_Manual) Data->EqPreset = EqPreset_Manual;
  else if(Data->MusicBook->EQ_Preset==TMusicServerEqPreset_Megabass) Data->EqPreset = EqPreset_Megabass;
  else if(Data->MusicBook->EQ_Preset==TMusicServerEqPreset_TrebleBoost) Data->EqPreset = EqPreset_TrebleBoost;
  else if(Data->MusicBook->EQ_Preset==TMusicServerEqPreset_Voice) Data->EqPreset = EqPreset_Voice;
}

void GetLoopState(WALKMAN_Function* Data)
{
  if(Data->MusicBook->loop) Data->IsLoop = TRUE;
  else Data->IsLoop = FALSE;
}

void GetShuffleState(WALKMAN_Function* Data)
{
  if(Data->MusicBook->shuffle) Data->IsShuffle = TRUE;
  else Data->IsShuffle = FALSE;
}

void GetVolumeLevel(WALKMAN_Function* Data)
{
  char media;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);
  Data->VolumeLevel = media - 18;
}

void DrawImage( GC* gc, int x, int y, int w, int h, IMAGEID img )
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  if(img!=NOIMAGE) dll_GC_PutChar( gc, x, y, w, h, img );
#else
  if(img!=NOIMAGE) GC_PutChar( gc, x, y, w, h, img );
#endif
}

void DrawIcon(IMAGEID img, int x, int y)
{
  DrawImage( get_DisplayGC(), x, y, 0, 0, img );
}


extern "C"
int New_Music_Gui_NowPlaying_OnCreate(DISP_OBJ* disp_obj)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  Data->Music_Gui_NowPlaying = disp_obj;

  LoadImage(Data);
  BootViz(Data);

  return Music_Gui_NowPlaying_OnCreate(disp_obj);
}

extern "C"
void New_Music_Gui_NowPlaying_OnDestroy(DISP_OBJ* disp_obj)
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  FreeImage(Data);
  KillAllTimer(Data);
  FreeViz(Data);
  Delete_WALKMAN_Function();
  Music_Gui_NowPlaying_OnDestroy(disp_obj);
}

extern "C"
void New_Music_Gui_NowPlaying_OnRedraw(DISP_OBJ* disp_obj, int a, int b, int c)
{
  MUSIC_GUI_NOWPLAYING_DISP_OBJ* now_playing = (MUSIC_GUI_NOWPLAYING_DISP_OBJ*)disp_obj;
  int myFile1 = w_fopen( L"/usb/other/Music_Gui_NowPlaying_unk_0x1A4.bin", WA_Read+WA_Write+WA_Create+WA_Truncate, 0x1FF, NULL );
  if ( myFile1 >= NULL )
  {
    w_fwrite( myFile1, (char*)now_playing->unk_0x1A4, 0x128 );
    w_fclose( myFile1 );
  }
  
  int myFile2 = w_fopen( L"/usb/other/Music_Gui_NowPlaying_unk_0x1A8.bin", WA_Read+WA_Write+WA_Create+WA_Truncate, 0x1FF, NULL );
  if ( myFile2 >= NULL )
  {
    w_fwrite( myFile2, (char*)now_playing->unk_0x1A8, 0x128 );
    w_fclose( myFile2 );
  }
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  int scr_w = Display_GetWidth( UIDisplay_Main );
  int scr_h = Display_GetHeight( UIDisplay_Main );

  GetLoopState(Data);
  GetShuffleState(Data);
  GetEqPreset(Data);
  GetMediaPlayerState(Data);
  GetVolumeLevel(Data);
  
  char State;
  TEXTID TextID;
  GC* pGC = get_DisplayGC();
  
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
      Data->m_hMGC = GC_CreateMemoryGC( Data->gcmem_xsize, scr_h, 16, 0, 0, 0 );
      CANVAS_Get_GviGC( Data->m_hMGC->pcanvas ,&Data->m_smilgc);
      GVI_FillRectangle( Data->m_smilgc, Data->Main.VIZRect.x1,Data->Main.VIZRect.y1, Data->gcmem_xsize, scr_h, Data->m_br );
      DrawImage( Data->m_hMGC, Data->Main.VIZRect.x1, Data->Main.VIZRect.y1, 0, 0, Data->VizImageID );
    }
    GVI_GC gvigc = NULL;
    CANVAS_Get_GviGC(pGC->pcanvas, &gvigc);
    int bx = 0;
    int by = 0;
    if(!Data->Portrait)
    {
      bx = 40;
      by = 0;
    }
    GVI_BitBlt(gvigc,bx, by, scr_w, scr_h, Data->m_smilgc, (scr_w*(Data->kl)), 0, 204, 0, 2, 3);
    
    if (Data->kl > (((Data->gcmem_xsize)/scr_w)-2))
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
    DrawImage( pGC, Data->Main.ARect.x1, Data->Main.ARect.y1, Data->Main.ARect.x2-Data->Main.ARect.x1, Data->Main.ARect.y2-Data->Main.ARect.y1, Data->CoverArtID ); 
    DrawImage( pGC, Data->Main.ARect.x1, Data->Main.ARect.y1, Data->Main.ARect.x2-Data->Main.ARect.x1, Data->Main.ARect.y2-Data->Main.ARect.y1, Data->ImageID[25].ImageID ); 
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
  
  if(Data->Main.Title.Enable)
  {
    //SID = TextID_Create(Data->title,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Title.Font, 
                      now_playing->TextID.Title,
                      Data->Main.Title.Align, 
                      Data->Main.Title.x1, 
                      Data->Main.Title.y1, 
                      Data->Main.Title.x2-Data->Main.Title.x1,
                      Data->Main.Title.Color );
    //TEXT_FREE(SID);
  }
  if(Data->Main.Artist.Enable)
  {
    //SID = TextID_Create(Data->artist,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Artist.Font,
                      now_playing->TextID.Artist,
                      Data->Main.Artist.Align,
                      Data->Main.Artist.x1,
                      Data->Main.Artist.y1, 
                      Data->Main.Artist.x2-Data->Main.Artist.x1,
                      Data->Main.Artist.Color );
    //TEXT_FREE(SID);
  }
  if(Data->Main.Album.Enable)
  {
    //SID = TextID_Create(Data->album,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Album.Font, 
                      now_playing->TextID.Album,
                      Data->Main.Album.Align, 
                      Data->Main.Album.x1, 
                      Data->Main.Album.y1, 
                      Data->Main.Album.x2-Data->Main.Album.x1,
                      Data->Main.Album.Color );
    //TEXT_FREE(SID);
  }
  if(Data->Main.Extension.Enable)
  {
    TextID = TextID_Create(Data->ext,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Extension.Font,
                      TextID,
                      Data->Main.Extension.Align, 
                      Data->Main.Extension.x1, 
                      Data->Main.Extension.y1, 
                      Data->Main.Extension.x2-Data->Main.Extension.x1,
                      Data->Main.Extension.Color );
    TEXT_FREE(TextID);
  }
  
  if(Data->Main.C_TrackID.Enable)
  {
    //snwprintf(Data->buffer,MAXELEMS(Data->buffer), L"%d / ", Data->CurrentTrackNumber );
    //SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.C_TrackID.Font, 
                      now_playing->TextID.C_TrackID,
                      Data->Main.C_TrackID.Align, 
                      Data->Main.C_TrackID.x1, 
                      Data->Main.C_TrackID.y1, 
                      Data->Main.C_TrackID.x2-Data->Main.C_TrackID.x1,
                      Data->Main.C_TrackID.Color );
    //TEXT_FREE(SID);
  }
  
  if(Data->Main.TotalTrackID.Enable)
  {
    //SID = TextID_CreateIntegerID(Data->TotalTrackNumber);
    DrawString_Params(Data->Main.TotalTrackID.Font, 
                      now_playing->TextID.TotalTrackID,
                      Data->Main.TotalTrackID.Align, 
                      Data->Main.TotalTrackID.x1, 
                      Data->Main.TotalTrackID.y1, 
                      Data->Main.TotalTrackID.x2-Data->Main.TotalTrackID.x1,
                      Data->Main.TotalTrackID.Color );
    //TEXT_FREE(SID);
  }
  
  if(Data->Main.Genre.Enable)
  {
    TextID = TextID_Create(Data->genre,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.Genre.Font, 
                      TextID,
                      Data->Main.Genre.Align, 
                      Data->Main.Genre.x1, 
                      Data->Main.Genre.y1, 
                      Data->Main.Genre.x2-Data->Main.Genre.x1,
                      Data->Main.Genre.Color);
    TEXT_FREE(TextID);
  }
  
  if(Data->Main.TotalTime.Enable)
  {
    //snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"%02d:%02d", Data->FullTimeMinutes, Data->FullTimeSeconds);
    //SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.TotalTime.Font, 
                      now_playing->TextID.TotalTime,
                      Data->Main.TotalTime.Align, 
                      Data->Main.TotalTime.x1, 
                      Data->Main.TotalTime.y1, 
                      Data->Main.TotalTime.x2-Data->Main.TotalTime.x1,
                      Data->Main.TotalTime.Color);
    //TEXT_FREE(SID);
  }
  
  if(Data->Main.ElapsedTime.Enable)
  {
    //snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"%02d:%02d", Data->ElapsedTimeMinutes, Data->ElapsedTimeSeconds);
    //SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.ElapsedTime.Font, 
                      now_playing->TextID.ElapsedTime,
                      Data->Main.ElapsedTime.Align, 
                      Data->Main.ElapsedTime.x1, 
                      Data->Main.ElapsedTime.y1, 
                      Data->Main.ElapsedTime.x2-Data->Main.ElapsedTime.x1,
                      Data->Main.ElapsedTime.Color);
    //TEXT_FREE(SID);
  }
  
  if(Data->Main.RemainingTime.Enable)
  {
    //int RemainingLengthInSeconds = Data->FullTime - Data->ElapsedTime;
    //snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"-%02d:%02d", RemainingLengthInSeconds/60,RemainingLengthInSeconds%60);
    //SID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.RemainingTime.Font, 
                      now_playing->TextID.RemainingTime,
                      Data->Main.RemainingTime.Align, 
                      Data->Main.RemainingTime.x1, 
                      Data->Main.RemainingTime.y1, 
                      Data->Main.RemainingTime.x2-Data->Main.RemainingTime.x1,
                      Data->Main.RemainingTime.Color);
    //TEXT_FREE(SID);
  }
  
  if(Data->Main.BitRate.Enable)
  {
    snwprintf(Data->buffer, MAXELEMS(Data->buffer), L"%d kb/s", Data->Bitrate);
    TextID = TextID_Create(Data->buffer,ENC_UCS2,TEXTID_ANY_LEN);
    DrawString_Params(Data->Main.BitRate.Font, 
                      TextID,
                      Data->Main.BitRate.Align, 
                      Data->Main.BitRate.x1, 
                      Data->Main.BitRate.y1, 
                      Data->Main.BitRate.x2-Data->Main.BitRate.x1,
                      Data->Main.BitRate.Color);
    TEXT_FREE(TextID);
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

void FreeViz(WALKMAN_Function* Data)
{
  if(Data->m_smilgc != NULL)
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
    ImageID_Get( VIZ_CONFIG_PATH, Data->VizName, &Data->VizImageID );
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    Data->gcmem_xsize = dll_GetImageWidth( Data->VizImageID );
#else
    Data->gcmem_xsize = GetImageWidth( Data->VizImageID );
#endif
    Data->gc = get_DisplayGC();
    Data->UpdateTime = 200;
  }
  else
  {
    Data->UpdateTime = 1000;
  }
}

extern "C"
int New_pg_MusicApplication_Main_EnterAction(void* data, BOOK* book)
{
  if(pg_MusicApplication_Main_EnterAction(data, book))
  {
    onfTimer(NULL,NULL);
  }
  return 1;  
}

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
void New_SoftKeys(BOOK* book)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_SKINEDITOR);
  GUIObject_SoftKeys_SetActionAndText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, Enter_WalkmanSkinEditor, TEXT_SKINS);
  GUIObject_SoftKeys_SetInfoText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, Info_Str());
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying,ACTION_MP_SETTINGS, ACTION_MP_SKINEDITOR);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, Enter_WalkmanSkinEditor);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, TEXT_SKINS);
  MediaPlayer_SoftKeys_SetInfoText(MusicBook->Gui_NowPlaying, ACTION_MP_SKINEDITOR, Info_Str());
/* -------------------------------------------------------------------------------------*/  
  GUIObject_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_VISUALISATION);
  GUIObject_SoftKeys_SetActionAndText(MusicBook->Gui_NowPlaying, ACTION_MP_VISUALISATION, Enter_VizSelector, TEXT_VISUALISATIONS);
  GUIObject_SoftKeys_SetInfoText(MusicBook->Gui_NowPlaying, ACTION_MP_VISUALISATION, Info_Viz());
  MediaPlayer_SoftKeys_SetItemAsSubItem(MusicBook->Gui_NowPlaying, ACTION_MP_SETTINGS, ACTION_MP_VISUALISATION);
  MediaPlayer_SoftKeys_SetAction(MusicBook->Gui_NowPlaying, ACTION_MP_VISUALISATION, Enter_VizSelector);
  MediaPlayer_SoftKeys_SetText(MusicBook->Gui_NowPlaying, ACTION_MP_VISUALISATION, TEXT_VISUALISATIONS);
  MediaPlayer_SoftKeys_SetInfoText(MusicBook->Gui_NowPlaying, ACTION_MP_VISUALISATION, Info_Viz());
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
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  Data->CoverArtID = dll_MetaData_GetCover(Data->fullpath);
#else
  Data->CoverArtID = MetaData_GetCover(Data->fullpath);
#endif
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

void GetTrackData( UI_MEDIAPLAYER_NEW_TRACK_DATA* Track_Data, MusicApplication_Book* MusicBook )
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  Data->FullTime = (Track_Data->FullTime.hours*3600)+(Track_Data->FullTime.minutes*60)+Track_Data->FullTime.seconds;
  Data->ElapsedTime = (Track_Data->ElapsedTime.hours*3600)+(Track_Data->ElapsedTime.minutes*60)+Track_Data->ElapsedTime.seconds;

  wchar_t artist[MUSIC_SERVER_MAX_URI_LENGTH];
  wchar_t album[MUSIC_SERVER_MAX_URI_LENGTH];
  wchar_t title[MUSIC_SERVER_MAX_URI_LENGTH];
  TMusicServer_Time Playlength;
  TMusicServer_Time ResumePosition;
  bool IsRealMediaFile;
  
  MusicBook->pMusicServer->GetFocusedItem(Track_Data->track_id, 
                                          MUSIC_SERVER_MAX_URI_LENGTH, 
                                          artist, 
                                          album, 
                                          title, 
                                          Data->fullpath,
                                          &Playlength, 
                                          &ResumePosition, 
                                          &Data->ContainsAlbumart, 
                                          &IsRealMediaFile );

  wstrcpy(Data->tempFullPath, Data->fullpath);
  
  if(Data->ContainsAlbumart) GetCoverExist(Data);
  else GetCoverNotExist(Data);
  
  Data->Bitrate = GetTrackBitrate(Data->fullpath, Data->FullTime);
  
  char* tmpext = StringAlloc(wstrlen(Data->tempFullPath)+1);
  wchar_t* wtmpext = WStringAlloc((wstrlen(Data->tempFullPath)+1)*2);
  wstr2strn(tmpext, Data->tempFullPath, wstrlen(Data->tempFullPath));
  {
    Data->ext[0] = tmpext[strlen(tmpext)-3];
    Data->ext[1] = tmpext[strlen(tmpext)-2];
    Data->ext[2] = tmpext[strlen(tmpext)-1];
    StringFree(tmpext);
    WStringFree(wtmpext);
  }
  wstrnupr( Data->ext, wstrlen( Data->ext ));
  
  wchar_t* fname = wstrrchr(Data->tempFullPath, '/');
  *fname = 0;
  wchar_t *genre = MetaData_GetTags(Data->tempFullPath, fname+1, TMetadataTagId_Genre);
  if(genre)
  {
    wstrcpy(Data->genre,genre);
    mfree(genre);
  }
  else wstrcpy(Data->genre, L"");  
}

extern "C"
int New_ON_NEW_TRACK( void* data, BOOK* book )
{
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  UI_MEDIAPLAYER_NEW_TRACK_DATA* Track_Data =  (UI_MEDIAPLAYER_NEW_TRACK_DATA*)data;

  GetTrackData(Track_Data, MusicBook);
  
  GetLoopState(Data);
  GetShuffleState(Data);
  GetEqPreset(Data);
  GetMediaPlayerState(Data);

  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
  
  return DefaultOnNewTrack(Track_Data, MusicBook);
}

extern "C"
int New_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT( void* audio_data, BOOK* book )
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*) book;
  UI_MEDIAPLAYER_AUDIO_PLAYING_TIME* TimeData = (UI_MEDIAPLAYER_AUDIO_PLAYING_TIME*) audio_data;
  
  WALKMAN_Function* Data = Get_WALKMAN_Function();

  Data->ElapsedTime = (TimeData->ElapsedTime.hours*3600)+(TimeData->ElapsedTime.minutes*60)+TimeData->ElapsedTime.seconds; 

  GetLoopState(Data);
  GetShuffleState(Data);
  GetEqPreset(Data);
  GetMediaPlayerState(Data);

  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
  
  return Default_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT(TimeData,MusicBook);
}

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

void SetEnabled(BOOK* book, GUI* gui)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  if(mbk->Str_Enable)
  {
    mbk->Str_Enable = FALSE;
    ListMenu_SetItemSecondLineText( gui, 0, TEXT_NO );
  }
  else
  {
    mbk->Str_Enable = TRUE;
    ListMenu_SetItemSecondLineText( gui, 0, TEXT_YES );
  }
  mbk->ChangeMade = TRUE;
}

int onIconEditorMessage( GUI_MESSAGE* msg )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)GUIonMessage_GetBook(msg);
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    if (item == 0) 
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_DISABLED );
      if(mbk->Str_Enable)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_YES );
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
      SID[0] = TextID_CreateIntegerID(mbk->Str_x1);
      SID[1] = TempSID;
      SID[2] = TextID_CreateIntegerID(mbk->Str_y1);
      SID[3] = TempSID;
      SID[4] = TextID_CreateIntegerID(mbk->Str_x2);
      SID[5] = TempSID;
      SID[6] = TextID_CreateIntegerID(mbk->Str_y2);
      TEXTID IDSID = TextID_Create(SID,ENC_TEXTID,7);
      GUIonMessage_SetMenuItemSecondLineText( msg, IDSID );
    }
    if (item == 2)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_BACKGROUND_COLOR );
      snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", COLOR_GET_R(mbk->Str_Color),COLOR_GET_G(mbk->Str_Color),COLOR_GET_B(mbk->Str_Color),COLOR_GET_A(mbk->Str_Color) );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(mbk->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
    if (item == 3)  
    {
      GUIonMessage_SetMenuItemText( msg, STR(TXT_ELAPSED_BAR_COLOR) );
      snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", COLOR_GET_R(mbk->Str_Color_2),COLOR_GET_G(mbk->Str_Color_2),COLOR_GET_B(mbk->Str_Color_2),COLOR_GET_A(mbk->Str_Color_2) );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(mbk->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
  }
  return 1;
}

void OnIconEditorBackGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  FREE_GUI(mbk->IconEdit);
}

void OnIconEditorSelectGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  int item=ListMenu_GetSelectedItem(mbk->IconEdit);
  if(item==0) SetEnabled(mbk, mbk->IconEdit);
  if(item==1) Create_GUI_EditCoordinates(mbk, 0);
}

void CreateIconEditorGUI(BOOK* book)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  FREE_GUI(mbk->Alignment);
}  

void oom_onEnter(  BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  mbk->Str_Align = OneOfMany_GetSelected(mbk->Alignment);
  
  if(mbk->Str_Align==UITextAlignment_Left) ListMenu_SetItemSecondLineText( mbk->StringEdit, 2, TEXT_LEFT );
  else if(mbk->Str_Align==UITextAlignment_Right) ListMenu_SetItemSecondLineText( mbk->StringEdit, 2, TEXT_RIGHT );
  else if(mbk->Str_Align==UITextAlignment_Center) ListMenu_SetItemSecondLineText( mbk->StringEdit, 2, STR(TXT_CENTER) );
  
  mbk->ChangeMade = TRUE;
  FREE_GUI(mbk->Alignment);
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  mbk->Alignment = CreateOneOfMany(mbk);
  GUIObject_SetTitleText(mbk->Alignment,TEXT_ALIGN);
  OneOfMany_SetItemCount(mbk->Alignment,3);
  OneOfMany_SetOnMessage(mbk->Alignment,oom_callback);
  OneOfMany_SetChecked(mbk->Alignment,mbk->Str_Align);
  GUIObject_SoftKeys_SetAction(mbk->Alignment,ACTION_BACK,DestroyOOM);
  GUIObject_SoftKeys_SetAction(mbk->Alignment,ACTION_SELECT1,oom_onEnter);
  GUIObject_Show(mbk->Alignment);
}

int onStringEditorMessage( GUI_MESSAGE* msg )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)GUIonMessage_GetBook(msg);
  switch( GUIonMessage_GetMsg(msg) )
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex( msg );
    if (item == 0) 
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_ENABLED );
      if(mbk->Str_Enable)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_YES );
      else 
      {
        GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_NO );
      }
    }
    if (item == 1)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_POSITION );
      snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"X: %d, Y: %d, Width: %d",mbk->Str_x1,mbk->Str_y1,mbk->Str_x2-mbk->Str_x1);
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(mbk->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
    if (item == 2)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_ALIGN );
      if(mbk->Str_Align==UITextAlignment_Left)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_LEFT );
      else if(mbk->Str_Align==UITextAlignment_Right)GUIonMessage_SetMenuItemSecondLineText( msg, TEXT_RIGHT );
      else if(mbk->Str_Align==UITextAlignment_Center)GUIonMessage_SetMenuItemSecondLineText( msg, STR(TXT_CENTER) ); 
    }
    if (item == 3)
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_FONT_SIZE );
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      int Style = mbk->Str_Font_Size>>8;
      if (Style == Font_Normal)
      {
        snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_R",mbk->Str_Font_Size);///< normal
      }
      else if (Style == Font_Bold)
      {
        snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_B",mbk->Str_Font_Size&0xFF);///< bold
      }
      else if (Style == Font_Italic)
      {
        snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_I",mbk->Str_Font_Size&0xFF);///< italic
      }
      else if (Style == Font_BoldItalic)
      {
        snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_%d_B_I",mbk->Str_Font_Size&0xFF);///< bold italic
      }
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(mbk->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
#else
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(GetFontNameByFontId( mbk->Str_Font_Size ),ENC_UCS2,TEXTID_ANY_LEN) );
#endif
    }
    if (item == 4)  
    {
      GUIonMessage_SetMenuItemText( msg, TEXT_TEXT_COLOR );  
      snwprintf( mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", COLOR_GET_R(mbk->Str_Color),COLOR_GET_G(mbk->Str_Color),COLOR_GET_B(mbk->Str_Color),COLOR_GET_A(mbk->Str_Color) );
      GUIonMessage_SetMenuItemSecondLineText( msg, TextID_Create(mbk->buffer,ENC_UCS2,TEXTID_ANY_LEN) );
    }
  }
  return TRUE;
}

void OnStringEditorBackGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  FREE_GUI(mbk->StringEdit);
}

void OnStringEditorSelectGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  int item = ListMenu_GetSelectedItem(mbk->StringEdit);
  if(item==0) SetEnabled(mbk, mbk->StringEdit);
  if(item==1) 
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = FALSE;
    mbk->IsString = TRUE;
    Create_GUI_EditCoordinates(mbk, 1);
  }
  if(item==2) CreateOOMList( mbk );
  if(item==3) Create_GUI_SelectFont( mbk );
  if(item==4) 
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = FALSE;
    mbk->IsString = TRUE;
    Create_GUI_EditColor( mbk );
  }
}

void CreateStringEditorGUI(BOOK* book)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  int item = ListMenu_GetSelectedItem(mbk->ProgressBar);
  if(item==0) SetEnabled(mbk, mbk->ProgressBar);
  if(item==1) 
  {
    mbk->IsBbar = TRUE;
    mbk->IsFbar = TRUE;
    mbk->IsString = FALSE;
    Create_GUI_EditCoordinates(mbk, 1);
  }
  if(item==2) 
  {
    mbk->IsBbar = TRUE;
    mbk->IsFbar = FALSE;
    mbk->IsString = FALSE;
    Create_GUI_EditColor( mbk );
  }
  if(item==3) 
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = TRUE;
    mbk->IsString = FALSE;
    Create_GUI_EditColor( mbk );
  }
}

void OnProgressBarBackGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;  
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  FREE_GUI(mbk->ProgressBar);
}

void CreateProgressBarEditorGUI(BOOK* book)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book; 
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
  WalkmanSkinEditor_Book* book = (WalkmanSkinEditor_Book*)GUIonMessage_GetBook( msg );
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

void OnLinksEditorSelectGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  wstrcpy(mbk->Title_Str,L"UNDEFINED");
  int item = ListMenu_GetSelectedItem(mbk->portrait);
  mbk->ItemID = item;
  if(item==0) 
  {
    //book->ItemID=0;
    wstrcpy(mbk->Title_Str,L"Title");
    mbk->Str_Align = mbk->Title_Align;
    mbk->Str_Enable = mbk->Title_Enable;
    mbk->Str_Font_Size = mbk->Title_Font;
    mbk->Str_Color = mbk->Title_Color;
    mbk->Str_x1 = mbk->Title_x1;
    mbk->Str_x2 = mbk->Title_x2;
    mbk->Str_y1 = mbk->Title_y1;
    mbk->Str_y2 = mbk->Title_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==1) 
  {
    //book->ItemID=1;
    wstrcpy(mbk->Title_Str,L"Artist");
    mbk->Str_Align = mbk->Artist_Align;
    mbk->Str_Enable = mbk->Artist_Enable;
    mbk->Str_Font_Size = mbk->Artist_Font;
    mbk->Str_Color = mbk->Artist_Color;
    mbk->Str_x1 = mbk->Artist_x1;
    mbk->Str_x2 = mbk->Artist_x2;
    mbk->Str_y1 = mbk->Artist_y1;
    mbk->Str_y2 = mbk->Artist_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==2) 
  {
    //book->ItemID=2;
    wstrcpy(mbk->Title_Str,L"Album");
    mbk->Str_Align = mbk->Album_Align;
    mbk->Str_Enable = mbk->Album_Enable;
    mbk->Str_Font_Size = mbk->Album_Font;
    mbk->Str_Color = mbk->Album_Color;
    mbk->Str_x1 = mbk->Album_x1;
    mbk->Str_x2 = mbk->Album_x2;
    mbk->Str_y1 = mbk->Album_y1;
    mbk->Str_y2 = mbk->Album_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==3) 
  {
    //book->ItemID=3;
    wstrcpy(mbk->Title_Str,L"Genre");
    mbk->Str_Align=mbk->Genre_Align;
    mbk->Str_Enable=mbk->Genre_Enable;
    mbk->Str_Font_Size=mbk->Genre_Font;
    mbk->Str_Color=mbk->Genre_Color;
    mbk->Str_x1=mbk->Genre_x1;
    mbk->Str_x2=mbk->Genre_x2;
    mbk->Str_y1=mbk->Genre_y1;
    mbk->Str_y2=mbk->Genre_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==4) 
  {
    //book->ItemID=4;
    wstrcpy(mbk->Title_Str,L"Total Time");
    mbk->Str_Align=mbk->TotalTime_Align;
    mbk->Str_Enable=mbk->TotalTime_Enable;
    mbk->Str_Font_Size=mbk->TotalTime_Font;
    mbk->Str_Color=mbk->TotalTime_Color;
    mbk->Str_x1=mbk->TotalTime_x1;
    mbk->Str_x2=mbk->TotalTime_x2;
    mbk->Str_y1=mbk->TotalTime_y1;
    mbk->Str_y2=mbk->TotalTime_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==5) 
  {
    //book->ItemID=5;
    wstrcpy(mbk->Title_Str,L"Elapsed Time");
    mbk->Str_Align=mbk->ElapsedTime_Align;
    mbk->Str_Enable=mbk->ElapsedTime_Enable;
    mbk->Str_Font_Size=mbk->ElapsedTime_Font;
    mbk->Str_Color=mbk->ElapsedTime_Color;
    mbk->Str_x1=mbk->ElapsedTime_x1;
    mbk->Str_x2=mbk->ElapsedTime_x2;
    mbk->Str_y1=mbk->ElapsedTime_y1;
    mbk->Str_y2=mbk->ElapsedTime_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==6) 
  {
    //book->ItemID=6;
    wstrcpy(mbk->Title_Str,L"Remaining Time");
    mbk->Str_Align=mbk->RemainingTime_Align;
    mbk->Str_Enable=mbk->RemainingTime_Enable;
    mbk->Str_Font_Size=mbk->RemainingTime_Font;
    mbk->Str_Color=mbk->RemainingTime_Color;
    mbk->Str_x1=mbk->RemainingTime_x1;
    mbk->Str_x2=mbk->RemainingTime_x2;
    mbk->Str_y1=mbk->RemainingTime_y1;
    mbk->Str_y2=mbk->RemainingTime_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==7) 
  {
    //book->ItemID=7;
    wstrcpy(mbk->Title_Str,L"Extension");
    mbk->Str_Align=mbk->Extension_Align;
    mbk->Str_Enable=mbk->Extension_Enable;
    mbk->Str_Font_Size=mbk->Extension_Font;
    mbk->Str_Color=mbk->Extension_Color;
    mbk->Str_x1=mbk->Extension_x1;
    mbk->Str_x2=mbk->Extension_x2;
    mbk->Str_y1=mbk->Extension_y1;
    mbk->Str_y2=mbk->Extension_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==8) 
  {
    //book->ItemID=8;
    wstrcpy(mbk->Title_Str,L"Bitrate");
    mbk->Str_Align=mbk->BitRate_Align;
    mbk->Str_Enable=mbk->BitRate_Enable;
    mbk->Str_Font_Size=mbk->BitRate_Font;
    mbk->Str_Color=mbk->BitRate_Color;
    mbk->Str_x1=mbk->BitRate_x1;
    mbk->Str_x2=mbk->BitRate_x2;
    mbk->Str_y1=mbk->BitRate_y1;
    mbk->Str_y2=mbk->BitRate_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==9) 
  {
    //book->ItemID=9;
    wstrcpy(mbk->Title_Str,L"Total Track");
    mbk->Str_Align = mbk->TotalTrackID_Align;
    mbk->Str_Enable = mbk->TotalTrackID_Enable;
    mbk->Str_Font_Size = mbk->TotalTrackID_Font;
    mbk->Str_Color = mbk->TotalTrackID_Color;
    mbk->Str_x1 = mbk->TotalTrackID_x1;
    mbk->Str_x2 = mbk->TotalTrackID_x2;
    mbk->Str_y1 = mbk->TotalTrackID_y1;
    mbk->Str_y2 = mbk->TotalTrackID_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==10) 
  {
    //book->ItemID=10;
    wstrcpy(mbk->Title_Str,L"Current Track ID");
    mbk->Str_Align = mbk->C_TrackID_Align;
    mbk->Str_Enable = mbk->C_TrackID_Enable;
    mbk->Str_Font_Size=mbk->C_TrackID_Font;
    mbk->Str_Color=mbk->C_TrackID_Color;
    mbk->Str_x1=mbk->C_TrackID_x1;
    mbk->Str_x2=mbk->C_TrackID_x2;
    mbk->Str_y1=mbk->C_TrackID_y1;
    mbk->Str_y2=mbk->C_TrackID_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==11) 
  {
    //book->ItemID=11;
    wstrcpy(mbk->Title_Str,L"Shuffle Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Shuffle_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Shuffle_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Shuffle_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==12) 
  {
    //book->ItemID=12;
    wstrcpy(mbk->Title_Str,L"Loop Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Loop_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Loop_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Loop_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  if(item==13) 
  {
    //book->ItemID=13;
    wstrcpy(mbk->Title_Str,L"EQ Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->EQ_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->EQ_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->EQ_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }    
  if(item==14) 
  {
    //book->ItemID=14;
    wstrcpy(mbk->Title_Str,L"Player State Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->PlayerState_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->PlayerState_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->PlayerState_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }  
  
  if(item==15) 
  {
    //book->ItemID=15;
    wstrcpy(mbk->Title_Str,L"Title Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Title_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Title_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Title_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==16) 
  {
    //book->ItemID=16;
    wstrcpy(mbk->Title_Str,L"Artist Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Artist_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Artist_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Artist_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==17) 
  {
    //book->ItemID=17;
    wstrcpy(mbk->Title_Str,L"Album Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Album_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Album_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Album_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==18)
  {
    //book->ItemID=18;
    wstrcpy(mbk->Title_Str,L"Wheel BG Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellBG_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellBG_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellBG_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  
  if(item==19)
  {
    //book->ItemID=19;
    wstrcpy(mbk->Title_Str,L"Wheel Up Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellUP_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellUP_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellUP_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if(item==20)
  {
    //book->ItemID=20;
    wstrcpy(mbk->Title_Str,L"Wheel Down Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellDOWN_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellDOWN_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellDOWN_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==21)
  {
    //book->ItemID=21;
    wstrcpy(mbk->Title_Str,L"Wheel Left Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellLEFT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellLEFT_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellLEFT_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==22)
  {
    //book->ItemID=22;
    wstrcpy(mbk->Title_Str,L"Wheel Right Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellRIGHT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellRIGHT_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellRIGHT_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if(item==23)
  {
    //book->ItemID=23;
    wstrcpy(mbk->Title_Str,L"Wheel Center Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellCENTER_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellCENTER_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellCENTER_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if (item == 24)   
  {
    //book->ItemID=24;
    wstrcpy(mbk->Title_Str,L"Background Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Background_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Background_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Background_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  if (item == 25)   
  {
    //book->ItemID=25;
    wstrcpy(mbk->Title_Str,L"Overlay Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Overlay_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Overlay_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Overlay_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(book);
  }
  
  if (item == 26)
  {
    //book->ItemID=26;
    wstrcpy(mbk->Title_Str,L"Progress Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->ProgressBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=mbk->PBColor;
    mbk->Str_Color_2=mbk->PFColor;
    mbk->Str_x1=mbk->PRect.x1;
    mbk->Str_x2=mbk->PRect.x2;
    mbk->Str_y1=mbk->PRect.y1;
    mbk->Str_y2=mbk->PRect.y2;
    CreateProgressBarEditorGUI(mbk);
  }
  if (item == 27)
  {
    //book->ItemID=27;
    wstrcpy(mbk->Title_Str,L"Volume Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->VolumeBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=mbk->VBColor;
    mbk->Str_Color_2=mbk->VFColor;
    mbk->Str_x1=mbk->VRect.x1;
    mbk->Str_x2=mbk->VRect.x2;
    mbk->Str_y1=mbk->VRect.y1;
    mbk->Str_y2=mbk->VRect.y2;
    CreateProgressBarEditorGUI(mbk);
  }
  if (item == 28)
  {
    //book->ItemID=28;
    mbk->IsCover = TRUE;
    mbk->Str_x1=mbk->ARect.x1;
    mbk->Str_x2=mbk->ARect.x2;
    mbk->Str_y1=mbk->ARect.y1;
    mbk->Str_y2=mbk->ARect.y2;
    Create_GUI_EditCoordinates( mbk, 1 );
  }
  if (item == 29)
  {
    //book->ItemID=29;
    mbk->IsCover = TRUE;
    mbk->Str_x1=mbk->VRect.x1;
    mbk->Str_x2=mbk->VRect.x2;
    mbk->Str_y1=mbk->VRect.y1;
    mbk->Str_y2=mbk->VRect.y2;
    Create_GUI_EditCoordinates( mbk, 1 );
  }
}

void OnLinksLandEditorSelectGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  wstrcpy(mbk->Title_Str,L"UNDEFINED");
  int item = ListMenu_GetSelectedItem(mbk->landscape);
  mbk->ItemID = item+30;
  if(item == 0) 
  {
    //book->ItemID=30;
    wstrcpy(mbk->Title_Str,L"Title");
    mbk->Str_Align=mbk->Land_Title_Align;
    mbk->Str_Enable=mbk->Land_Title_Enable;
    mbk->Str_Font_Size=mbk->Land_Title_Font;
    mbk->Str_Color=mbk->Land_Title_Color;
    mbk->Str_x1=mbk->Land_Title_x1;
    mbk->Str_x2=mbk->Land_Title_x2;
    mbk->Str_y1=mbk->Land_Title_y1;
    mbk->Str_y2=mbk->Land_Title_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==1) 
  {
    //book->ItemID=31;
    wstrcpy(mbk->Title_Str,L"Artist");
    mbk->Str_Align=mbk->Land_Artist_Align;
    mbk->Str_Enable=mbk->Land_Artist_Enable;
    mbk->Str_Font_Size=mbk->Land_Artist_Font;
    mbk->Str_Color=mbk->Land_Artist_Color;
    mbk->Str_x1=mbk->Land_Artist_x1;
    mbk->Str_x2=mbk->Land_Artist_x2;
    mbk->Str_y1=mbk->Land_Artist_y1;
    mbk->Str_y2=mbk->Land_Artist_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==2) 
  {
    //book->ItemID=32;
    wstrcpy(mbk->Title_Str,L"Album");
    mbk->Str_Align=mbk->Land_Album_Align;
    mbk->Str_Enable=mbk->Land_Album_Enable;
    mbk->Str_Font_Size=mbk->Land_Album_Font;
    mbk->Str_Color=mbk->Land_Album_Color;
    mbk->Str_x1=mbk->Land_Album_x1;
    mbk->Str_x2=mbk->Land_Album_x2;
    mbk->Str_y1=mbk->Land_Album_y1;
    mbk->Str_y2=mbk->Land_Album_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==3)
  {
    //book->ItemID=33;
    wstrcpy(mbk->Title_Str,L"Genre");
    mbk->Str_Align=mbk->Land_Genre_Align;
    mbk->Str_Enable=mbk->Land_Genre_Enable;
    mbk->Str_Font_Size=mbk->Land_Genre_Font;
    mbk->Str_Color=mbk->Land_Genre_Color;
    mbk->Str_x1=mbk->Land_Genre_x1;
    mbk->Str_x2=mbk->Land_Genre_x2;
    mbk->Str_y1=mbk->Land_Genre_y1;
    mbk->Str_y2=mbk->Land_Genre_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==4) 
  {
    //book->ItemID=34;
    wstrcpy(mbk->Title_Str,L"Total Time");
    mbk->Str_Align=mbk->Land_TotalTime_Align;
    mbk->Str_Enable=mbk->Land_TotalTime_Enable;
    mbk->Str_Font_Size=mbk->Land_TotalTime_Font;
    mbk->Str_Color=mbk->Land_TotalTime_Color;
    mbk->Str_x1=mbk->Land_TotalTime_x1;
    mbk->Str_x2=mbk->Land_TotalTime_x2;
    mbk->Str_y1=mbk->Land_TotalTime_y1;
    mbk->Str_y2=mbk->Land_TotalTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==5) 
  {
    //book->ItemID=35;
    wstrcpy(mbk->Title_Str,L"Elapsed Time");
    mbk->Str_Align=mbk->Land_ElapsedTime_Align;
    mbk->Str_Enable=mbk->Land_ElapsedTime_Enable;
    mbk->Str_Font_Size=mbk->Land_ElapsedTime_Font;
    mbk->Str_Color=mbk->Land_ElapsedTime_Color;
    mbk->Str_x1=mbk->Land_ElapsedTime_x1;
    mbk->Str_x2=mbk->Land_ElapsedTime_x2;
    mbk->Str_y1=mbk->Land_ElapsedTime_y1;
    mbk->Str_y2=mbk->Land_ElapsedTime_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==6) 
  {
    //book->ItemID=36;
    wstrcpy(mbk->Title_Str,L"Remaining Time");
    mbk->Str_Align=mbk->Land_RemainingTime_Align;
    mbk->Str_Enable=mbk->Land_RemainingTime_Enable;
    mbk->Str_Font_Size=mbk->Land_RemainingTime_Font;
    mbk->Str_Color=mbk->Land_RemainingTime_Color;
    mbk->Str_x1=mbk->Land_RemainingTime_x1;
    mbk->Str_x2=mbk->Land_RemainingTime_x2;
    mbk->Str_y1=mbk->Land_RemainingTime_y1;
    mbk->Str_y2=mbk->Land_RemainingTime_y2;
    CreateStringEditorGUI(book);
  }
  if(item==7) 
  {
    //book->ItemID=37;
    wstrcpy(mbk->Title_Str,L"Extension");
    mbk->Str_Align=mbk->Land_Extension_Align;
    mbk->Str_Enable=mbk->Land_Extension_Enable;
    mbk->Str_Font_Size=mbk->Land_Extension_Font;
    mbk->Str_Color=mbk->Land_Extension_Color;
    mbk->Str_x1=mbk->Land_Extension_x1;
    mbk->Str_x2=mbk->Land_Extension_x2;
    mbk->Str_y1=mbk->Land_Extension_y1;
    mbk->Str_y2=mbk->Land_Extension_y2;
    CreateStringEditorGUI(book);
  }
  if(item==8) 
  {
    //book->ItemID=38;
    wstrcpy(mbk->Title_Str,L"Bitrate");
    mbk->Str_Align=mbk->Land_BitRate_Align;
    mbk->Str_Enable=mbk->Land_BitRate_Enable;
    mbk->Str_Font_Size=mbk->Land_BitRate_Font;
    mbk->Str_Color=mbk->Land_BitRate_Color;
    mbk->Str_x1=mbk->Land_BitRate_x1;
    mbk->Str_x2=mbk->Land_BitRate_x2;
    mbk->Str_y1=mbk->Land_BitRate_y1;
    mbk->Str_y2=mbk->Land_BitRate_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==9) 
  {
    //book->ItemID=39;
    wstrcpy(mbk->Title_Str,L"Total Track");
    mbk->Str_Align=mbk->Land_TotalTrackID_Align;
    mbk->Str_Enable=mbk->Land_TotalTrackID_Enable;
    mbk->Str_Font_Size=mbk->Land_TotalTrackID_Font;
    mbk->Str_Color=mbk->Land_TotalTrackID_Color;
    mbk->Str_x1=mbk->Land_TotalTrackID_x1;
    mbk->Str_x2=mbk->Land_TotalTrackID_x2;
    mbk->Str_y1=mbk->Land_TotalTrackID_y1;
    mbk->Str_y2=mbk->Land_TotalTrackID_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==10) 
  {
    //book->ItemID=40;
    wstrcpy(mbk->Title_Str,L"Current Track ID");
    mbk->Str_Align=mbk->Land_C_TrackID_Align;
    mbk->Str_Enable=mbk->Land_C_TrackID_Enable;
    mbk->Str_Font_Size=mbk->Land_C_TrackID_Font;
    mbk->Str_Color=mbk->Land_C_TrackID_Color;
    mbk->Str_x1=mbk->Land_C_TrackID_x1;
    mbk->Str_x2=mbk->Land_C_TrackID_x2;
    mbk->Str_y1=mbk->Land_C_TrackID_y1;
    mbk->Str_y2=mbk->Land_C_TrackID_y2;
    CreateStringEditorGUI(mbk);
  }
  if(item==11) 
  {
    //book->ItemID=41;
    wstrcpy(mbk->Title_Str,L"Shuffle Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Shuffle_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Shuffle_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Shuffle_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }  
  if(item==12) 
  {
    //book->ItemID=42;
    wstrcpy(mbk->Title_Str,L"Loop Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Loop_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Loop_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Loop_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }  
  if(item==13) 
  {
    //book->ItemID=43;
    wstrcpy(mbk->Title_Str,L"EQ Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_EQ_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_EQ_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_EQ_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }  
  if(item==14) 
  {
    //book->ItemID=44;
    wstrcpy(mbk->Title_Str,L"Player State Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_PlayerState_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_PlayerState_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_PlayerState_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }  
  if(item==15) 
  {
    //book->ItemID=45;
    wstrcpy(mbk->Title_Str,L"Title Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Title_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Title_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Title_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==16) 
  {
    //book->ItemID=46;
    wstrcpy(mbk->Title_Str,L"Artist Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Artist_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Artist_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Artist_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==17) 
  {
    //book->ItemID=47;
    wstrcpy(mbk->Title_Str,L"Album Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Album_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Album_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Album_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==18)
  {
    //book->ItemID=48;
    wstrcpy(mbk->Title_Str,L"Wheel BG Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_WhellBG_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_WhellBG_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_WhellBG_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  
  if(item==19)
  {
    //book->ItemID=49;
    wstrcpy(mbk->Title_Str,L"Wheel Up Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_WhellUP_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_WhellUP_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_WhellUP_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==20)
  {
    //book->ItemID=50;
    wstrcpy(mbk->Title_Str,L"Wheel Down Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_WhellDOWN_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_WhellDOWN_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_WhellDOWN_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==21)
  {
    //book->ItemID=51;
    wstrcpy(mbk->Title_Str,L"Wheel Left Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_WhellLEFT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_WhellLEFT_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_WhellLEFT_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if(item==22)
  {
    //book->ItemID=52;
    wstrcpy(mbk->Title_Str,L"Wheel Right Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_WhellRIGHT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_WhellRIGHT_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_WhellRIGHT_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  
  if(item==23)
  {
    //book->ItemID=53;
    wstrcpy(mbk->Title_Str,L"Wheel Center Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->WhellCENTER_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->WhellCENTER_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->WhellCENTER_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  } 
  
  if (item == 24)   
  {
    //book->ItemID=54;
    wstrcpy(mbk->Title_Str,L"Background Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Background_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Background_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Background_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  if (item == 25)   
  {
    //book->ItemID=55;
    wstrcpy(mbk->Title_Str,L"Overlay Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable=mbk->Land_Overlay_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color=0;
    mbk->Str_x1=mbk->Land_Overlay_Image_x1;
    mbk->Str_x2=0;
    mbk->Str_y1=mbk->Land_Overlay_Image_y1;
    mbk->Str_y2=0;
    CreateIconEditorGUI(mbk);
  }
  
  if (item == 26)
  {
    //book->ItemID=56;
    wstrcpy(mbk->Title_Str,L"Progress Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_ProgressBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = mbk->Land_PBColor;
    mbk->Str_Color_2 = mbk->Land_PFColor;
    mbk->Str_x1 = mbk->Land_PRect.x1;
    mbk->Str_x2 = mbk->Land_PRect.x2;
    mbk->Str_y1 = mbk->Land_PRect.y1;
    mbk->Str_y2 = mbk->Land_PRect.y2;
    CreateProgressBarEditorGUI(mbk);
  }
  if (item == 27)
  {
    //book->ItemID=57;
    wstrcpy(mbk->Title_Str,L"Volume Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_VolumeBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = mbk->Land_VBColor;
    mbk->Str_Color_2 = mbk->Land_VFColor;
    mbk->Str_x1 = mbk->Land_VRect.x1;
    mbk->Str_x2 = mbk->Land_VRect.x2;
    mbk->Str_y1 = mbk->Land_VRect.y1;
    mbk->Str_y2 = mbk->Land_VRect.y2;
    CreateProgressBarEditorGUI(mbk);
  }
  if (item == 28)
  {
    //book->ItemID=58;
    mbk->IsCover = TRUE;
    mbk->Str_x1 = mbk->Land_ARect.x1;
    mbk->Str_x2 = mbk->Land_ARect.x2;
    mbk->Str_y1 = mbk->Land_ARect.y1;
    mbk->Str_y2 = mbk->Land_ARect.y2;
    Create_GUI_EditCoordinates( mbk, 1 );
  }
  if (item == 29)
  {
    //book->ItemID=59;
    mbk->IsCover = TRUE;
    mbk->Str_x1 = mbk->Land_VRect.x1;
    mbk->Str_x2 = mbk->Land_VRect.x2;
    mbk->Str_y1 = mbk->Land_VRect.y1;
    mbk->Str_y2 = mbk->Land_VRect.y2;
    Create_GUI_EditCoordinates( mbk, 1 );
  }
}

void FreeTabGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  FREE_GUI(gui);
  FREE_GUI(mbk->portrait);
  FREE_GUI(mbk->landscape);
  FREE_GUI(mbk->WalkmanGUI);
  FREE_GUI(mbk->tab);
}

void OnEditorLongBackGui( BOOK* book, GUI* gui )
{
  //FreeTabGui(book,gui);
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void OnEditorBackGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  if(mbk->ChangeMade) YesNoSaveSkinData(mbk);
  else FreeTabGui(book,gui);
}

void OnSave(BOOK* book, GUI* gui)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  SaveSkinData(mbk, mbk->path, mbk->name);
  
  FreeTabGui(book,gui);
  
  if(mbk->CreateNew) CreateSkinChooser(mbk);
}

void OnLinksWalkmanGUIEditorSelectGui( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  TEXTID txt;
  
  int item = ListMenu_GetSelectedItem(mbk->WalkmanGUI);
  if(item==0)
  {
    if(mbk->FullScreen) 
    {
      mbk->FullScreen = FALSE;
      txt = TEXT_NO;
    }
    else
    {
      mbk->FullScreen = TRUE;
      txt = TEXT_YES;
    }
    mbk->GuiChanged = TRUE;
  }
  
  if(item==1)
  {
    if(mbk->ShowSoftKey) 
    {
      mbk->ShowSoftKey = FALSE;
      txt = TEXT_NO;
    }
    else
    {
      mbk->ShowSoftKey = TRUE;
      txt = TEXT_YES;
    }
  }
  ListMenu_SetItemSecondLineText( mbk->WalkmanGUI, item, txt );
  mbk->ChangeMade = TRUE;
}

void CreateTabGui( BOOK* book )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  mbk->tab = CreateTabMenuBar( mbk );
  TabMenuBar_SetTabCount( mbk->tab, 3 );
  TabMenuBar_SetTabIcon( mbk->tab, 0, MC_PORTRAIT_ICN, 0 );
  TabMenuBar_SetTabIcon( mbk->tab, 0, MC_PORTRAIT_ICN, 1 );
  TabMenuBar_SetTabIcon( mbk->tab, 1, MC_LANDSCAPE_ICN, 0 );
  TabMenuBar_SetTabIcon( mbk->tab, 1, MC_LANDSCAPE_ICN, 1 );
  TabMenuBar_SetTabIcon( mbk->tab, 2, RN_TAB_SESSION_MANAGER_DESELECTED_ICN, 0 );
  TabMenuBar_SetTabIcon( mbk->tab, 2, RN_TAB_SESSION_MANAGER_SELECTED_ICN, 1 );  
  
  mbk->portrait = CreateListMenu( mbk, UIDisplay_Main );
  ListMenu_SetItemCount( mbk->portrait, 30 );
  ListMenu_SetOnMessage( mbk->portrait, onLinksLBMessage );
  ListMenu_SetCursorToItem( mbk->portrait, 0 );
  ListMenu_SetItemStyle( mbk->portrait, 0 );
  ListMenu_SetItemTextScroll( mbk->portrait, 1 );
  GUIObject_SoftKeys_SetAction( mbk->portrait, ACTION_BACK, OnEditorBackGui );
  GUIObject_SoftKeys_SetAction( mbk->portrait, ACTION_LONG_BACK, OnEditorLongBackGui );
  GUIObject_SoftKeys_SetAction( mbk->portrait, ACTION_SELECT1, OnLinksEditorSelectGui );
  GUIObject_SoftKeys_SetAction( mbk->portrait, 0, OnSave );  
  GUIObject_SoftKeys_SetText( mbk->portrait, 0, TEXT_SAVE );  
  TabMenuBar_SetTabGui( mbk->tab, 0, mbk->portrait );
  TabMenuBar_SetTabTitle( mbk->tab, 0, TEXT_PORTRAIT );
  
  mbk->landscape = CreateListMenu( mbk, UIDisplay_Main );
  ListMenu_SetItemCount( mbk->landscape, 30);
  ListMenu_SetOnMessage( mbk->landscape, onLinksLBMessage );
  ListMenu_SetCursorToItem( mbk->landscape, 0 );
  ListMenu_SetItemStyle( mbk->landscape, 0 );
  ListMenu_SetItemTextScroll( mbk->landscape, 1 );
  GUIObject_SoftKeys_SetAction( mbk->landscape, ACTION_BACK, OnEditorBackGui );
  GUIObject_SoftKeys_SetAction( mbk->landscape, ACTION_LONG_BACK, OnEditorLongBackGui );
  GUIObject_SoftKeys_SetAction( mbk->landscape, ACTION_SELECT1, OnLinksLandEditorSelectGui );  
  GUIObject_SoftKeys_SetAction( mbk->landscape, 0, OnSave );  
  GUIObject_SoftKeys_SetText( mbk->landscape, 0, TEXT_SAVE );  
  TabMenuBar_SetTabGui( mbk->tab, 1, mbk->landscape );
  TabMenuBar_SetTabTitle( mbk->tab, 1, TEXT_LANDSCAPE );
  
  mbk->WalkmanGUI = CreateListMenu( mbk, UIDisplay_Main );
  ListMenu_SetItemCount( mbk->WalkmanGUI, 2);
  ListMenu_SetOnMessage( mbk->WalkmanGUI, onLinksGUI );
  ListMenu_SetCursorToItem( mbk->WalkmanGUI, 0 );
  ListMenu_SetItemStyle( mbk->WalkmanGUI, 1 );
  ListMenu_SetItemTextScroll( mbk->WalkmanGUI, 1 );
  GUIObject_SoftKeys_SetAction( mbk->WalkmanGUI, ACTION_BACK, OnEditorBackGui );
  GUIObject_SoftKeys_SetAction( mbk->WalkmanGUI, ACTION_LONG_BACK, OnEditorLongBackGui );
  GUIObject_SoftKeys_SetAction( mbk->WalkmanGUI, ACTION_SELECT1, OnLinksWalkmanGUIEditorSelectGui );  
  GUIObject_SoftKeys_SetAction( mbk->WalkmanGUI, 0, OnSave );  
  GUIObject_SoftKeys_SetText( mbk->WalkmanGUI, 0, TEXT_SAVE );
  TabMenuBar_SetTabGui( mbk->tab, 2, mbk->WalkmanGUI );
  TabMenuBar_SetTabTitle( mbk->tab, 2, STR(TXT_WALKMAN_GUI) );
  
  TabMenuBar_SetFocusedTab( mbk->tab, 0 );
  GUIObject_Show(mbk->tab);
}

int SelBcfg_BcfgFilter( const wchar_t* ExtList, const wchar_t* ItemPath, const wchar_t* ItemName )
{
  return DataBrowser_isFileInListExt( ExtList, ItemPath, ItemName );
}

int SelBcfgPageOnCreate( void* data, BOOK* book )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  void* DB_Desc = DataBrowserDesc_Create();
  const wchar_t* folder_list[1]={SKIN_PATH_INTERNAL};
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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

  if(!Data->ContainsAlbumart)
  {
    GetCoverNotExist(Data);  
  }
  else
  {
    GetCoverExist(Data);
  }
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
  
  return 1;
}

int Cancel_BasePage( void* data, BOOK* book )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  SaveSkinData(mbk, mbk->path, mbk->name);
  FreeTabGui(mbk,gui);
  
  mbk->ChangeMade = FALSE; //reset
    
  if(mbk->CreateNew) CreateSkinChooser(mbk);
}

void AskSave_On_No(BOOK* book, GUI *gui)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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

int SetSkin(WalkmanSkinEditor_Book* book)
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
  if(( File = _fopen( SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, NULL )) >=0 )
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
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
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book; 
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

//==============================================================================

void OnOkCreateStringInput(BOOK* book, wchar_t* wstring, int len)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  wstrcpy(mbk->AuthorName, wstring);
  FREE_GUI(mbk->StringInput);
  CreateTabGui(mbk);
}

void OnBackCreateStringInput( BOOK* book, GUI* gui )
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  FREE_GUI(mbk->StringInput);
  
  BookObj_GotoPage(mbk,&SkinEditor_Main_Page);
}

void EnterAuthorName(BOOK* book)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  mbk->StringInput = CreateStringInputVA(0,
                                         VAR_BOOK,mbk,
                                         VAR_STRINP_MODE,IT_STRING,
                                         VAR_STRINP_NEW_LINE,1,
                                         VAR_STRINP_MAX_LEN,100,
                                         VAR_STRINP_MIN_LEN,1,
                                         VAR_STRINP_FIXED_TEXT,STR(TXT_AUTHORS_NAME),
                                         VAR_OK_PROC,OnOkCreateStringInput,
                                         0);
  GUIObject_SoftKeys_SetAction(mbk->StringInput,ACTION_BACK,OnBackCreateStringInput);
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

//=============================================================================

void SkinEditor_Destroy(BOOK *book)
{
}

void Enter_WalkmanSkinEditor( BOOK* book, GUI* gui )
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
  
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)malloc(sizeof(WalkmanSkinEditor_Book));
  memset(mbk, NULL, sizeof(WalkmanSkinEditor_Book) );  
  if(!CreateBook(mbk, SkinEditor_Destroy, &SkinEditor_Base_Page, "WalkmanSkinEditor_Book", -1, 0)) mfree(mbk);
  else
  {
    BookObj_GotoPage(mbk,&SkinEditor_Main_Page);
  }
}

//=============================================================================

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
  int File;
  if ( (File = _fopen( SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
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
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    WData->blob_w = (dll_GetImageWidth( WData->ImageID[4].ImageID ))/2;
    WData->blob_h = (dll_GetImageHeight( WData->ImageID[4].ImageID ))/2;
#else
    WData->blob_w = (GetImageWidth( WData->ImageID[4].ImageID ))/2;
    WData->blob_h = (GetImageHeight( WData->ImageID[4].ImageID ))/2;
#endif
    fclose(File);
    mfree(SkinData);
  }
}

void FreeImage(WALKMAN_Function * WData)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  
  if(WData->CoverArtID != WData->ImageID[2].ImageID)
  {
    ImageID_Free(WData->CoverArtID);
  }
  WData->CoverArtID = NULL;
  
  int File;
  if ( (File = _fopen( SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
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

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
extern "C"
void New_SecondLine( GUI_LIST*list, int elem_num, int id )
{
  ListMenu_SetItemSecondLineText( list, elem_num, id );
  WALKMAN_Function* Data = Get_WALKMAN_Function();
  
  if(id==TURNON) Data->IsShuffle=TRUE;
  else if (id==TURNOFF) Data->IsShuffle=FALSE;
  
  if(Data->Music_Gui_NowPlaying) DispObject_InvalidateRect(Data->Music_Gui_NowPlaying, NULL);
}
#else
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
#endif

extern "C"
int New_PATCH_UI_MEDIAPLAYER_CREATED_EVENT( void* pUIMediaPlayer, BOOK* book)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;

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
  return Default_PATCH_UI_MEDIAPLAYER_CREATED_EVENT(pUIMediaPlayer,MusicBook);
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

extern "C"
void Set_WALKMAN_GUI_STYLE(GUI* gui)
{
  int File;
  if(( File = _fopen( SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >= 0 )
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
