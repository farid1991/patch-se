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

#include "Function.h"
#include "LNG.h"
#include "SaveLoad.h"
#include "Visual.h"
#include "Viz.h"
#include "Walkman.h"

void SaveSkinData(BOOK* book, wchar_t* path, wchar_t *name)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  int f;
  if(( f = _fopen( path,name, FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    SkinData* Data  = (SkinData*)malloc(sizeof(SkinData));
    memset( Data, NULL, sizeof(SkinData) );
    
    wstrcpy(Data->Author, mbk->AuthorName);
    //Title
    Data->Title_x1 = mbk->Title_x1;
    Data->Title_y1 = mbk->Title_y1;
    Data->Title_x2 = mbk->Title_x2;
    Data->Title_y2 = mbk->Title_y2 ;
    Data->Title_Align = mbk->Title_Align;
    Data->Title_Color = mbk->Title_Color;
    Data->Title_Font = mbk->Title_Font;
    Data->Title_Enable = mbk->Title_Enable;
    
    //Artist
    Data->Artist_x1 = mbk->Artist_x1;
    Data->Artist_y1 = mbk->Artist_y1;
    Data->Artist_x2 = mbk->Artist_x2;
    Data->Artist_y2 = mbk->Artist_y2;
    Data->Artist_Align = mbk->Artist_Align;
    Data->Artist_Font = mbk->Artist_Font;
    Data->Artist_Color = mbk->Artist_Color;
    Data->Artist_Enable = mbk->Artist_Enable;
    
    //Album
    Data->Album_x1 = mbk->Album_x1;
    Data->Album_y1 = mbk->Album_y1;
    Data->Album_x2 = mbk->Album_x2;
    Data->Album_y2 = mbk->Album_y2;
    Data->Album_Align = mbk->Album_Align;
    Data->Album_Color = mbk->Album_Color;
    Data->Album_Font = mbk->Album_Font;
    Data->Album_Enable = mbk->Album_Enable;
    
    //Genre
    Data->Genre_x1 = mbk->Genre_x1;
    Data->Genre_y1 = mbk->Genre_y1;
    Data->Genre_x2 = mbk->Genre_x2;
    Data->Genre_y2 = mbk->Genre_y2;
    Data->Genre_Align = mbk->Genre_Align;
    Data->Genre_Color = mbk->Genre_Color;
    Data->Genre_Font = mbk->Genre_Font;
    Data->Genre_Enable = mbk->Genre_Enable;
    
    //TotalTime
    Data->TotalTime_x1 = mbk->TotalTime_x1;
    Data->TotalTime_y1 = mbk->TotalTime_y1;
    Data->TotalTime_x2 = mbk->TotalTime_x2;
    Data->TotalTime_y2 = mbk->TotalTime_y2;
    Data->TotalTime_Align = mbk->TotalTime_Align;
    Data->TotalTime_Color = mbk->TotalTime_Color;
    Data->TotalTime_Font = mbk->TotalTime_Font;
    Data->TotalTime_Enable = mbk->TotalTime_Enable;
    
    //ElapsedTime
    Data->ElapsedTime_x1 = mbk->ElapsedTime_x1;
    Data->ElapsedTime_y1 = mbk->ElapsedTime_y1;
    Data->ElapsedTime_x2 = mbk->ElapsedTime_x2;
    Data->ElapsedTime_y2 = mbk->ElapsedTime_y2;
    Data->ElapsedTime_Align = mbk->ElapsedTime_Align;
    Data->ElapsedTime_Color = mbk->ElapsedTime_Color;
    Data->ElapsedTime_Font = mbk->ElapsedTime_Font;
    Data->ElapsedTime_Enable = mbk->ElapsedTime_Enable;
    
    //RemainingTime
    Data->RemainingTime_x1 = mbk->RemainingTime_x1;
    Data->RemainingTime_y1 = mbk->RemainingTime_y1;
    Data->RemainingTime_x2 = mbk->RemainingTime_x2;
    Data->RemainingTime_y2 = mbk->RemainingTime_y2;
    Data->RemainingTime_Align = mbk->RemainingTime_Align;
    Data->RemainingTime_Color = mbk->RemainingTime_Color;
    Data->RemainingTime_Font = mbk->RemainingTime_Font;
    Data->RemainingTime_Enable = mbk->RemainingTime_Enable;
    
    //Extension
    Data->Extension_x1 = mbk->Extension_x1;
    Data->Extension_y1 = mbk->Extension_y1;
    Data->Extension_x2 = mbk->Extension_x2;
    Data->Extension_y2 = mbk->Extension_y2;
    Data->Extension_Align = mbk->Extension_Align;
    Data->Extension_Color = mbk->Extension_Color;
    Data->Extension_Font = mbk->Extension_Font;
    Data->Extension_Enable = mbk->Extension_Enable;
    
    //BitRate
    Data->BitRate_x1 = mbk->BitRate_x1;
    Data->BitRate_y1 = mbk->BitRate_y1;
    Data->BitRate_x2 = mbk->BitRate_x2;
    Data->BitRate_y2 = mbk->BitRate_y2;
    Data->BitRate_Align = mbk->BitRate_Align;
    Data->BitRate_Color = mbk->BitRate_Color;
    Data->BitRate_Font = mbk->BitRate_Font;
    Data->BitRate_Enable = mbk->BitRate_Enable;
    
    //TotalTrackID
    Data->TotalTrackID_x1 = mbk->TotalTrackID_x1;
    Data->TotalTrackID_y1 = mbk->TotalTrackID_y1;
    Data->TotalTrackID_x2 = mbk->TotalTrackID_x2;
    Data->TotalTrackID_y2 = mbk->TotalTrackID_y2;
    Data->TotalTrackID_Align = mbk->TotalTrackID_Align;
    Data->TotalTrackID_Color = mbk->TotalTrackID_Color;
    Data->TotalTrackID_Font = mbk->TotalTrackID_Font;
    Data->TotalTrackID_Enable = mbk->TotalTrackID_Enable;
    
    //C_TrackID
    Data->C_TrackID_x1 = mbk->C_TrackID_x1;
    Data->C_TrackID_y1 = mbk->C_TrackID_y1;
    Data->C_TrackID_x2 = mbk->C_TrackID_x2;
    Data->C_TrackID_y2 = mbk->C_TrackID_y2;
    Data->C_TrackID_Align = mbk->C_TrackID_Align;
    Data->C_TrackID_Color = mbk->C_TrackID_Color;
    Data->C_TrackID_Font = mbk->C_TrackID_Font;
    Data->C_TrackID_Enable = mbk->C_TrackID_Enable;
    
    //Shuffle_Image
    Data->Shuffle_Image_x1 = mbk->Shuffle_Image_x1;
    Data->Shuffle_Image_y1 = mbk->Shuffle_Image_y1;
    Data->Shuffle_Image_Enable = mbk->Shuffle_Image_Enable;
    
    //Loop_Image
    Data->Loop_Image_x1 = mbk->Loop_Image_x1;
    Data->Loop_Image_y1 = mbk->Loop_Image_y1;
    Data->Loop_Image_Enable = mbk->Loop_Image_Enable;
    
    //EQ_Image
    Data->EQ_Image_x1 = mbk->EQ_Image_x1;
    Data->EQ_Image_y1 = mbk->EQ_Image_y1;
    Data->EQ_Image_Enable = mbk->EQ_Image_Enable;
    
    //PlayerState_Image
    Data->PlayerState_Image_x1 = mbk->PlayerState_Image_x1;
    Data->PlayerState_Image_y1 = mbk->PlayerState_Image_y1;
    Data->PlayerState_Image_Enable = mbk->PlayerState_Image_Enable;
    
    //Title_Image
    Data->Title_Image_x1 = mbk->Title_Image_x1;
    Data->Title_Image_y1 = mbk->Title_Image_y1;
    Data->Title_Image_Enable = mbk->Title_Image_Enable;
    
    //Artist_Image
    Data->Artist_Image_x1 = mbk->Artist_Image_x1;
    Data->Artist_Image_y1 = mbk->Artist_Image_y1;
    Data->Artist_Image_Enable = mbk->Artist_Image_Enable;
    
    //Album_Image
    Data->Album_Image_x1 = mbk->Album_Image_x1;
    Data->Album_Image_y1 = mbk->Album_Image_y1;
    Data->Album_Image_Enable = mbk->Album_Image_Enable;
    
    Data->WhellBG_Image_Enable = mbk->WhellBG_Image_Enable;
    Data->WhellBG_Image_x1 = mbk->WhellBG_Image_x1;
    Data->WhellBG_Image_y1 = mbk->WhellBG_Image_y1;
    
    
    Data->WhellUP_Image_Enable = mbk->WhellUP_Image_Enable;
    Data->WhellUP_Image_x1 = mbk->WhellUP_Image_x1;
    Data->WhellUP_Image_y1 = mbk->WhellUP_Image_y1;
    
    
    Data->WhellDOWN_Image_Enable = mbk->WhellDOWN_Image_Enable;
    Data->WhellDOWN_Image_x1 = mbk->WhellDOWN_Image_x1;
    Data->WhellDOWN_Image_y1 = mbk->WhellDOWN_Image_y1;
    
    
    Data->WhellLEFT_Image_Enable = mbk->WhellLEFT_Image_Enable;
    Data->WhellLEFT_Image_x1 = mbk->WhellLEFT_Image_x1;
    Data->WhellLEFT_Image_y1 = mbk->WhellLEFT_Image_y1;
    
    Data->WhellRIGHT_Image_Enable = mbk->WhellRIGHT_Image_Enable;
    Data->WhellRIGHT_Image_x1 = mbk->WhellRIGHT_Image_x1;
    Data->WhellRIGHT_Image_y1 = mbk->WhellRIGHT_Image_y1;
    
    Data->WhellCENTER_Image_Enable = mbk->WhellCENTER_Image_Enable;
    Data->WhellCENTER_Image_x1 = mbk->WhellCENTER_Image_x1;
    Data->WhellCENTER_Image_y1 = mbk->WhellCENTER_Image_y1;
    
    Data->Background_Image_Enable = mbk->Background_Image_Enable;
    Data->Background_Image_x1 = mbk->Background_Image_x1;
    Data->Background_Image_y1 = mbk->Background_Image_y1;
    
    Data->Overlay_Image_Enable = mbk->Overlay_Image_Enable;
    Data->Overlay_Image_x1 = mbk->Overlay_Image_x1;
    Data->Overlay_Image_y1 = mbk->Overlay_Image_y1;
    
    //Progress Bar
    Data->ProgressBarEnable = mbk->ProgressBarEnable;
    Data->PRect = mbk->PRect;
    Data->PBColor = mbk->PBColor;
    Data->PFColor = mbk->PFColor;
    
	//VolumeBar
    Data->VolumeBarEnable = mbk->VolumeBarEnable;
    Data->VRect = mbk->VRect;
    Data->VBColor = mbk->VBColor;
    Data->VFColor = mbk->VFColor;
    //AlbumArt
    Data->AlbumArtEnable = mbk->AlbumArtEnable;
    Data->ARect = mbk->ARect;
	
    //Visualisation
    Data->VisualisationEnable = mbk->VisualisationEnable;
    Data->VIZRect = mbk->VIZRect;
//============================================================

    //Title
    Data->Land_Title_x1 = mbk->Land_Title_x1;
    Data->Land_Title_y1 = mbk->Land_Title_y1;
    Data->Land_Title_x2 = mbk->Land_Title_x2;
    Data->Land_Title_y2 = mbk->Land_Title_y2;
    Data->Land_Title_Align = mbk->Land_Title_Align;
    Data->Land_Title_Color = mbk->Land_Title_Color;
    Data->Land_Title_Font = mbk->Land_Title_Font;
    Data->Land_Title_Enable = mbk->Land_Title_Enable;
    
    //Artist
    Data->Land_Artist_x1 = mbk->Land_Artist_x1;
    Data->Land_Artist_y1 = mbk->Land_Artist_y1;
    Data->Land_Artist_x2 = mbk->Land_Artist_x2;
    Data->Land_Artist_y2 = mbk->Land_Artist_y2;
    Data->Land_Artist_Align = mbk->Land_Artist_Align;
    Data->Land_Artist_Font = mbk->Land_Artist_Font;
    Data->Land_Artist_Color = mbk->Land_Artist_Color;
    Data->Land_Artist_Enable = mbk->Land_Artist_Enable;
    
    //Album
    Data->Land_Album_x1 = mbk->Land_Album_x1;
    Data->Land_Album_y1 = mbk->Land_Album_y1;
    Data->Land_Album_x2 = mbk->Land_Album_x2;
    Data->Land_Album_y2 = mbk->Land_Album_y2;
    Data->Land_Album_Align = mbk->Land_Album_Align;
    Data->Land_Album_Color = mbk->Land_Album_Color;
    Data->Land_Album_Font = mbk->Land_Album_Font;
    Data->Land_Album_Enable = mbk->Land_Album_Enable;
    
    //Genre
    Data->Land_Genre_x1 = mbk->Land_Genre_x1;
    Data->Land_Genre_y1 = mbk->Land_Genre_y1;
    Data->Land_Genre_x2 = mbk->Land_Genre_x2;
    Data->Land_Genre_y2 = mbk->Land_Genre_y2;
    Data->Land_Genre_Align = mbk->Land_Genre_Align;
    Data->Land_Genre_Color = mbk->Land_Genre_Color;
    Data->Land_Genre_Font = mbk->Land_Genre_Font;
    Data->Land_Genre_Enable = mbk->Land_Genre_Enable;
    
    //TotalTime
    Data->Land_TotalTime_x1 = mbk->Land_TotalTime_x1;
    Data->Land_TotalTime_y1 = mbk->Land_TotalTime_y1;
    Data->Land_TotalTime_x2 = mbk->Land_TotalTime_x2;
    Data->Land_TotalTime_y2 = mbk->Land_TotalTime_y2;
    Data->Land_TotalTime_Align = mbk->Land_TotalTime_Align;
    Data->Land_TotalTime_Color = mbk->Land_TotalTime_Color;
    Data->Land_TotalTime_Font = mbk->Land_TotalTime_Font;
    Data->Land_TotalTime_Enable = mbk->Land_TotalTime_Enable;
    
    //ElapsedTime
    Data->Land_ElapsedTime_x1 = mbk->Land_ElapsedTime_x1;
    Data->Land_ElapsedTime_y1 = mbk->Land_ElapsedTime_y1;
    Data->Land_ElapsedTime_x2 = mbk->Land_ElapsedTime_x2;
    Data->Land_ElapsedTime_y2 = mbk->Land_ElapsedTime_y2;
    Data->Land_ElapsedTime_Align = mbk->Land_ElapsedTime_Align;
    Data->Land_ElapsedTime_Color = mbk->Land_ElapsedTime_Color;
    Data->Land_ElapsedTime_Font = mbk->Land_ElapsedTime_Font;
    Data->Land_ElapsedTime_Enable = mbk->Land_ElapsedTime_Enable;
    
    //RemainingTime
    Data->Land_RemainingTime_x1 = mbk->Land_RemainingTime_x1;
    Data->Land_RemainingTime_y1 = mbk->Land_RemainingTime_y1;
    Data->Land_RemainingTime_x2 = mbk->Land_RemainingTime_x2;
    Data->Land_RemainingTime_y2 = mbk->Land_RemainingTime_y2;
    Data->Land_RemainingTime_Align = mbk->Land_RemainingTime_Align;
    Data->Land_RemainingTime_Color = mbk->Land_RemainingTime_Color;
    Data->Land_RemainingTime_Font = mbk->Land_RemainingTime_Font;
    Data->Land_RemainingTime_Enable = mbk->Land_RemainingTime_Enable;
    
    //Extension
    Data->Land_Extension_x1 = mbk->Land_Extension_x1;
    Data->Land_Extension_y1 = mbk->Land_Extension_y1;
    Data->Land_Extension_x2 = mbk->Land_Extension_x2;
    Data->Land_Extension_y2 = mbk->Land_Extension_y2;
    Data->Land_Extension_Align = mbk->Land_Extension_Align;
    Data->Land_Extension_Color = mbk->Land_Extension_Color;
    Data->Land_Extension_Font = mbk->Land_Extension_Font;
    Data->Land_Extension_Enable = mbk->Land_Extension_Enable;
    
    //BitRate
    Data->Land_BitRate_x1 = mbk->Land_BitRate_x1;
    Data->Land_BitRate_y1 = mbk->Land_BitRate_y1;
    Data->Land_BitRate_x2 = mbk->Land_BitRate_x2;
    Data->Land_BitRate_y2 = mbk->Land_BitRate_y2;
    Data->Land_BitRate_Align = mbk->Land_BitRate_Align;
    Data->Land_BitRate_Color = mbk->Land_BitRate_Color;
    Data->Land_BitRate_Font = mbk->Land_BitRate_Font;
    Data->Land_BitRate_Enable = mbk->Land_BitRate_Enable;
    
    //TotalTrackID
    Data->Land_TotalTrackID_x1 = mbk->Land_TotalTrackID_x1;
    Data->Land_TotalTrackID_y1 = mbk->Land_TotalTrackID_y1;
    Data->Land_TotalTrackID_x2 = mbk->Land_TotalTrackID_x2;
    Data->Land_TotalTrackID_y2 = mbk->Land_TotalTrackID_y2;
    Data->Land_TotalTrackID_Align = mbk->Land_TotalTrackID_Align;
    Data->Land_TotalTrackID_Color = mbk->Land_TotalTrackID_Color;
    Data->Land_TotalTrackID_Font = mbk->Land_TotalTrackID_Font;
    Data->Land_TotalTrackID_Enable = mbk->Land_TotalTrackID_Enable;
    
    //C_TrackID
    Data->Land_C_TrackID_x1 = mbk->Land_C_TrackID_x1;
    Data->Land_C_TrackID_y1 = mbk->Land_C_TrackID_y1;
    Data->Land_C_TrackID_x2 = mbk->Land_C_TrackID_x2;
    Data->Land_C_TrackID_y2 = mbk->Land_C_TrackID_y2;
    Data->Land_C_TrackID_Align = mbk->Land_C_TrackID_Align;
    Data->Land_C_TrackID_Color = mbk->Land_C_TrackID_Color;
    Data->Land_C_TrackID_Font = mbk->Land_C_TrackID_Font;
    Data->Land_C_TrackID_Enable = mbk->Land_C_TrackID_Enable;
    
    //Shuffle_Image
    Data->Land_Shuffle_Image_x1 = mbk->Land_Shuffle_Image_x1;
    Data->Land_Shuffle_Image_y1 = mbk->Land_Shuffle_Image_y1;
    Data->Land_Shuffle_Image_Enable = mbk->Land_Shuffle_Image_Enable;
    
    //Loop_Image
    Data->Land_Loop_Image_x1 = mbk->Land_Loop_Image_x1;
    Data->Land_Loop_Image_y1 = mbk->Land_Loop_Image_y1;
    Data->Land_Loop_Image_Enable = mbk->Land_Loop_Image_Enable;
    
    //EQ_Image
    Data->Land_EQ_Image_x1 = mbk->Land_EQ_Image_x1;
    Data->Land_EQ_Image_y1 = mbk->Land_EQ_Image_y1;
    Data->Land_EQ_Image_Enable = mbk->Land_EQ_Image_Enable;
    
    //PlayerState_Image
    Data->Land_PlayerState_Image_x1 = mbk->Land_PlayerState_Image_x1;
    Data->Land_PlayerState_Image_y1 = mbk->Land_PlayerState_Image_y1;
    Data->Land_PlayerState_Image_Enable = mbk->Land_PlayerState_Image_Enable;
    
    //Title_Image
    Data->Land_Title_Image_x1 = mbk->Land_Title_Image_x1;
    Data->Land_Title_Image_y1 = mbk->Land_Title_Image_y1;
    Data->Land_Title_Image_Enable = mbk->Land_Title_Image_Enable;
    
    //Artist_Image
    Data->Land_Artist_Image_x1 = mbk->Land_Artist_Image_x1;
    Data->Land_Artist_Image_y1 = mbk->Land_Artist_Image_y1;
    Data->Land_Artist_Image_Enable = mbk->Land_Artist_Image_Enable;
    
    //Album_Image
    Data->Land_Album_Image_x1 = mbk->Land_Album_Image_x1;
    Data->Land_Album_Image_y1 = mbk->Land_Album_Image_y1;
    Data->Land_Album_Image_Enable = mbk->Land_Album_Image_Enable;
    
    Data->Land_WhellBG_Image_Enable = mbk->Land_WhellBG_Image_Enable;
    Data->Land_WhellBG_Image_x1 = mbk->Land_WhellBG_Image_x1;
    Data->Land_WhellBG_Image_y1 = mbk->Land_WhellBG_Image_y1;
    
    
    Data->Land_WhellUP_Image_Enable = mbk->Land_WhellUP_Image_Enable;
    Data->Land_WhellUP_Image_x1 = mbk->Land_WhellUP_Image_x1;
    Data->Land_WhellUP_Image_y1 = mbk->Land_WhellUP_Image_y1;
    
    
    Data->Land_WhellDOWN_Image_Enable = mbk->Land_WhellDOWN_Image_Enable;
    Data->Land_WhellDOWN_Image_x1 = mbk->Land_WhellDOWN_Image_x1;
    Data->Land_WhellDOWN_Image_y1 = mbk->Land_WhellDOWN_Image_y1;
    
    
    Data->Land_WhellLEFT_Image_Enable = mbk->Land_WhellLEFT_Image_Enable;
    Data->Land_WhellLEFT_Image_x1 = mbk->Land_WhellLEFT_Image_x1;
    Data->Land_WhellLEFT_Image_y1 = mbk->Land_WhellLEFT_Image_y1;
    
    Data->Land_WhellRIGHT_Image_Enable = mbk->Land_WhellRIGHT_Image_Enable;
    Data->Land_WhellRIGHT_Image_x1 = mbk->Land_WhellRIGHT_Image_x1;
    Data->Land_WhellRIGHT_Image_y1 = mbk->Land_WhellRIGHT_Image_y1;
    
    Data->Land_WhellCENTER_Image_Enable = mbk->Land_WhellCENTER_Image_Enable;
    Data->Land_WhellCENTER_Image_x1 = mbk->Land_WhellCENTER_Image_x1;
    Data->Land_WhellCENTER_Image_y1 = mbk->Land_WhellCENTER_Image_y1;
    
    Data->Land_Background_Image_Enable = mbk->Land_Background_Image_Enable;
    Data->Land_Background_Image_x1 = mbk->Land_Background_Image_x1;
    Data->Land_Background_Image_y1 = mbk->Land_Background_Image_y1;
    
    Data->Land_Overlay_Image_Enable = mbk->Land_Overlay_Image_Enable;
    Data->Land_Overlay_Image_x1 = mbk->Land_Overlay_Image_x1;
    Data->Land_Overlay_Image_y1 = mbk->Land_Overlay_Image_y1;
    
    //Progress Bar
    Data->Land_ProgressBarEnable = mbk->Land_ProgressBarEnable;
    Data->Land_PRect = mbk->Land_PRect;
    Data->Land_PBColor = mbk->Land_PBColor;
    Data->Land_PFColor = mbk->Land_PFColor;
    
	//VolumeBar
    Data->Land_VolumeBarEnable = mbk->Land_VolumeBarEnable;
    Data->Land_VRect = mbk->Land_VRect;
    Data->Land_VBColor = mbk->Land_VBColor;
    Data->Land_VFColor = mbk->Land_VFColor;
    
    //AlbumArt
    Data->Land_AlbumArtEnable = mbk->Land_AlbumArtEnable;
    Data->Land_ARect = mbk->Land_ARect;
    
    //Visualisation
    Data->Land_VisualisationEnable = mbk->Land_VisualisationEnable;
    Data->Land_VIZRect = mbk->Land_VIZRect;
    Data->FullScreen = mbk->FullScreen;
    Data->ShowSoftKey = mbk->ShowSoftKey;
    
    fwrite(f,Data,sizeof(SkinData));
    fclose (f);
    mfree(Data);
  }
}

void LoadSkinData(BOOK* book, wchar_t* path,wchar_t* name)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  
  int f;
  if ( (f = _fopen( path, name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >= 0 )
  {
    SkinData* Data  = (SkinData*)malloc(sizeof(SkinData));
    memset( Data, NULL, sizeof(SkinData));
    fread( f, Data, sizeof(SkinData));
    
    wstrcpy(mbk->AuthorName ,Data->Author);
    
    //Title
    mbk->Title_x1 = Data->Title_x1;
    mbk->Title_y1 = Data->Title_y1;
    mbk->Title_x2 = Data->Title_x2;
    mbk->Title_y2  = Data->Title_y2;
    mbk->Title_Align = Data->Title_Align;
    mbk->Title_Color = Data->Title_Color;
    mbk->Title_Font = Data->Title_Font;
    mbk->Title_Enable = Data->Title_Enable;
    
    //Artist
    mbk->Artist_x1 = Data->Artist_x1;
    mbk->Artist_y1 = Data->Artist_y1;
    mbk->Artist_x2 = Data->Artist_x2;
    mbk->Artist_y2 = Data->Artist_y2;
    mbk->Artist_Align = Data->Artist_Align;
    mbk->Artist_Font = Data->Artist_Font;
    mbk->Artist_Color = Data->Artist_Color;
    mbk->Artist_Enable = Data->Artist_Enable;
    
    //Album
    mbk->Album_x1 = Data->Album_x1;
    mbk->Album_y1 = Data->Album_y1;
    mbk->Album_x2 = Data->Album_x2;
    mbk->Album_y2 = Data->Album_y2;
    mbk->Album_Align = Data->Album_Align;
    mbk->Album_Color = Data->Album_Color;
    mbk->Album_Font = Data->Album_Font;
    mbk->Album_Enable = Data->Album_Enable;
    
    //Genre
    mbk->Genre_x1 = Data->Genre_x1;
    mbk->Genre_y1 = Data->Genre_y1;
    mbk->Genre_x2 = Data->Genre_x2;
    mbk->Genre_y2 = Data->Genre_y2;
    mbk->Genre_Align = Data->Genre_Align;
    mbk->Genre_Color = Data->Genre_Color;
    mbk->Genre_Font = Data->Genre_Font;
    mbk->Genre_Enable = Data->Genre_Enable;
    
    //TotalTime
    mbk->TotalTime_x1 = Data->TotalTime_x1;
    mbk->TotalTime_y1 = Data->TotalTime_y1;
    mbk->TotalTime_x2 = Data->TotalTime_x2;
    mbk->TotalTime_y2 = Data->TotalTime_y2;
    mbk->TotalTime_Align = Data->TotalTime_Align;
    mbk->TotalTime_Color = Data->TotalTime_Color;
    mbk->TotalTime_Font = Data->TotalTime_Font;
    mbk->TotalTime_Enable = Data->TotalTime_Enable;
    
    //ElapsedTime
    mbk->ElapsedTime_x1 = Data->ElapsedTime_x1;
    mbk->ElapsedTime_y1 = Data->ElapsedTime_y1;
    mbk->ElapsedTime_x2 = Data->ElapsedTime_x2;
    mbk->ElapsedTime_y2 = Data->ElapsedTime_y2;
    mbk->ElapsedTime_Align = Data->ElapsedTime_Align;
    mbk->ElapsedTime_Color = Data->ElapsedTime_Color;
    mbk->ElapsedTime_Font = Data->ElapsedTime_Font;
    mbk->ElapsedTime_Enable = Data->ElapsedTime_Enable;
    
    //RemainingTime
    mbk->RemainingTime_x1 = Data->RemainingTime_x1;
    mbk->RemainingTime_y1 = Data->RemainingTime_y1;
    mbk->RemainingTime_x2 = Data->RemainingTime_x2;
    mbk->RemainingTime_y2 = Data->RemainingTime_y2;
    mbk->RemainingTime_Align = Data->RemainingTime_Align;
    mbk->RemainingTime_Color = Data->RemainingTime_Color;
    mbk->RemainingTime_Font = Data->RemainingTime_Font;
    mbk->RemainingTime_Enable = Data->RemainingTime_Enable;
    
    //Extension
    mbk->Extension_x1 = Data->Extension_x1;
    mbk->Extension_y1 = Data->Extension_y1;
    mbk->Extension_x2 = Data->Extension_x2;
    mbk->Extension_y2 = Data->Extension_y2;
    mbk->Extension_Align = Data->Extension_Align;
    mbk->Extension_Color = Data->Extension_Color;
    mbk->Extension_Font = Data->Extension_Font;
    mbk->Extension_Enable = Data->Extension_Enable;
    
    //BitRate
    mbk->BitRate_x1 = Data->BitRate_x1;
    mbk->BitRate_y1 = Data->BitRate_y1;
    mbk->BitRate_x2 = Data->BitRate_x2;
    mbk->BitRate_y2 = Data->BitRate_y2;
    mbk->BitRate_Align = Data->BitRate_Align;
    mbk->BitRate_Color = Data->BitRate_Color;
    mbk->BitRate_Font = Data->BitRate_Font;
    mbk->BitRate_Enable = Data->BitRate_Enable;
    
    //TotalTrackID
    mbk->TotalTrackID_x1 = Data->TotalTrackID_x1;
    mbk->TotalTrackID_y1 = Data->TotalTrackID_y1;
    mbk->TotalTrackID_x2 = Data->TotalTrackID_x2;
    mbk->TotalTrackID_y2 = Data->TotalTrackID_y2;
    mbk->TotalTrackID_Align = Data->TotalTrackID_Align;
    mbk->TotalTrackID_Color = Data->TotalTrackID_Color;
    mbk->TotalTrackID_Font = Data->TotalTrackID_Font;
    mbk->TotalTrackID_Enable = Data->TotalTrackID_Enable;
    
    //C_TrackID
    mbk->C_TrackID_x1 = Data->C_TrackID_x1;
    mbk->C_TrackID_y1 = Data->C_TrackID_y1;
    mbk->C_TrackID_x2 = Data->C_TrackID_x2;
    mbk->C_TrackID_y2 = Data->C_TrackID_y2;
    mbk->C_TrackID_Align = Data->C_TrackID_Align;
    mbk->C_TrackID_Color = Data->C_TrackID_Color;
    mbk->C_TrackID_Font = Data->C_TrackID_Font;
    mbk->C_TrackID_Enable = Data->C_TrackID_Enable;
    
    //Shuffle_Image
    mbk->Shuffle_Image_x1 = Data->Shuffle_Image_x1;
    mbk->Shuffle_Image_y1 = Data->Shuffle_Image_y1;
    mbk->Shuffle_Image_Enable = Data->Shuffle_Image_Enable;
    
    //Loop_Image
    mbk->Loop_Image_x1 = Data->Loop_Image_x1;
    mbk->Loop_Image_y1 = Data->Loop_Image_y1;
    mbk->Loop_Image_Enable = Data->Loop_Image_Enable;
    
    //EQ_Image
    mbk->EQ_Image_Enable = Data->EQ_Image_Enable;
    mbk->EQ_Image_x1 = Data->EQ_Image_x1;
    mbk->EQ_Image_y1 = Data->EQ_Image_y1;
    
    //PlayerState_Image
    mbk->PlayerState_Image_x1 = Data->PlayerState_Image_x1;
    mbk->PlayerState_Image_y1 = Data->PlayerState_Image_y1;
    mbk->PlayerState_Image_Enable = Data->PlayerState_Image_Enable;
    
    //Title_Image
    mbk->Title_Image_x1 = Data->Title_Image_x1;
    mbk->Title_Image_y1 = Data->Title_Image_y1;
    mbk->Title_Image_Enable = Data->Title_Image_Enable;
    
    //Artist_Image
    mbk->Artist_Image_x1 = Data->Artist_Image_x1;
    mbk->Artist_Image_y1 = Data->Artist_Image_y1;
    mbk->Artist_Image_Enable = Data->Artist_Image_Enable;
    
    //Album_Image
    mbk->Album_Image_x1 = Data->Album_Image_x1;
    mbk->Album_Image_y1 = Data->Album_Image_y1;
    mbk->Album_Image_Enable = Data->Album_Image_Enable;
    
    mbk->WhellBG_Image_Enable = Data->WhellBG_Image_Enable;
    mbk->WhellBG_Image_x1 = Data->WhellBG_Image_x1;
    mbk->WhellBG_Image_y1 = Data->WhellBG_Image_y1;
    
    
    mbk->WhellUP_Image_Enable = Data->WhellUP_Image_Enable;
    mbk->WhellUP_Image_x1 = Data->WhellUP_Image_x1;
    mbk->WhellUP_Image_y1 = Data->WhellUP_Image_y1;
    
    
    mbk->WhellDOWN_Image_Enable = Data->WhellDOWN_Image_Enable;
    mbk->WhellDOWN_Image_x1 = Data->WhellDOWN_Image_x1;
    mbk->WhellDOWN_Image_y1 = Data->WhellDOWN_Image_y1;
    
    
    mbk->WhellLEFT_Image_Enable = Data->WhellLEFT_Image_Enable;
    mbk->WhellLEFT_Image_x1 = Data->WhellLEFT_Image_x1;
    mbk->WhellLEFT_Image_y1 = Data->WhellLEFT_Image_y1;
    
    mbk->WhellRIGHT_Image_Enable = Data->WhellRIGHT_Image_Enable;
    mbk->WhellRIGHT_Image_x1 = Data->WhellRIGHT_Image_x1;
    mbk->WhellRIGHT_Image_y1 = Data->WhellRIGHT_Image_y1;
    
    mbk->WhellCENTER_Image_Enable = Data->WhellCENTER_Image_Enable;
    mbk->WhellCENTER_Image_x1 = Data->WhellCENTER_Image_x1;
    mbk->WhellCENTER_Image_y1 = Data->WhellCENTER_Image_y1;
    
    mbk->Background_Image_Enable = Data->Background_Image_Enable;
    mbk->Background_Image_x1 = Data->Background_Image_x1;
    mbk->Background_Image_y1 = Data->Background_Image_y1;
    
    mbk->Overlay_Image_Enable = Data->Overlay_Image_Enable;
    mbk->Overlay_Image_x1 = Data->Overlay_Image_x1;
    mbk->Overlay_Image_y1 = Data->Overlay_Image_y1;
    
    //Progress Bar
    mbk->ProgressBarEnable = Data->ProgressBarEnable;
    mbk->PRect = Data->PRect;
    mbk->PBColor = Data->PBColor;
    mbk->PFColor = Data->PFColor;
    
	//VolumeBar
    mbk->VolumeBarEnable = Data->VolumeBarEnable;
    mbk->VRect = Data->VRect;
    mbk->VBColor = Data->VBColor;
    mbk->VFColor = Data->VFColor;
    
    //AlbumArt
    mbk->AlbumArtEnable = Data->AlbumArtEnable;
    mbk->ARect = Data->ARect;
    
    //Visualisation
    mbk->VisualisationEnable = Data->VisualisationEnable;
    mbk->VIZRect = Data->VIZRect;
    //===========================================================
    //Title
    mbk->Land_Title_x1 = Data->Land_Title_x1;
    mbk->Land_Title_y1 = Data->Land_Title_y1;
    mbk->Land_Title_x2 = Data->Land_Title_x2;
    mbk->Land_Title_y2 = Data->Land_Title_y2;
    mbk->Land_Title_Align = Data->Land_Title_Align;
    mbk->Land_Title_Color = Data->Land_Title_Color;
    mbk->Land_Title_Font = Data->Land_Title_Font;
    mbk->Land_Title_Enable = Data->Land_Title_Enable;
    
    //Artist
    mbk->Land_Artist_x1 = Data->Land_Artist_x1;
    mbk->Land_Artist_y1 = Data->Land_Artist_y1;
    mbk->Land_Artist_x2 = Data->Land_Artist_x2;
    mbk->Land_Artist_y2 = Data->Land_Artist_y2;
    mbk->Land_Artist_Align = Data->Land_Artist_Align;
    mbk->Land_Artist_Font = Data->Land_Artist_Font;
    mbk->Land_Artist_Color = Data->Land_Artist_Color;
    mbk->Land_Artist_Enable = Data->Land_Artist_Enable;
    
    //Album
    mbk->Land_Album_x1 = Data->Land_Album_x1;
    mbk->Land_Album_y1 = Data->Land_Album_y1;
    mbk->Land_Album_x2 = Data->Land_Album_x2;
    mbk->Land_Album_y2 = Data->Land_Album_y2;
    mbk->Land_Album_Align = Data->Land_Album_Align;
    mbk->Land_Album_Color = Data->Land_Album_Color;
    mbk->Land_Album_Font = Data->Land_Album_Font;
    mbk->Land_Album_Enable = Data->Land_Album_Enable;
    
    //Genre
    mbk->Land_Genre_x1 = Data->Land_Genre_x1;
    mbk->Land_Genre_y1 = Data->Land_Genre_y1;
    mbk->Land_Genre_x2 = Data->Land_Genre_x2;
    mbk->Land_Genre_y2 = Data->Land_Genre_y2;
    mbk->Land_Genre_Align = Data->Land_Genre_Align;
    mbk->Land_Genre_Color = Data->Land_Genre_Color;
    mbk->Land_Genre_Font = Data->Land_Genre_Font;
    mbk->Land_Genre_Enable = Data->Land_Genre_Enable;
    
    //TotalTime
    mbk->Land_TotalTime_x1 = Data->Land_TotalTime_x1;
    mbk->Land_TotalTime_y1 = Data->Land_TotalTime_y1;
    mbk->Land_TotalTime_x2 = Data->Land_TotalTime_x2;
    mbk->Land_TotalTime_y2 = Data->Land_TotalTime_y2;
    mbk->Land_TotalTime_Align = Data->Land_TotalTime_Align;
    mbk->Land_TotalTime_Color = Data->Land_TotalTime_Color;
    mbk->Land_TotalTime_Font = Data->Land_TotalTime_Font;
    mbk->Land_TotalTime_Enable = Data->Land_TotalTime_Enable;
    
    //ElapsedTime
    mbk->Land_ElapsedTime_x1 = Data->Land_ElapsedTime_x1;
    mbk->Land_ElapsedTime_y1 = Data->Land_ElapsedTime_y1;
    mbk->Land_ElapsedTime_x2 = Data->Land_ElapsedTime_x2;
    mbk->Land_ElapsedTime_y2 = Data->Land_ElapsedTime_y2;
    mbk->Land_ElapsedTime_Align = Data->Land_ElapsedTime_Align;
    mbk->Land_ElapsedTime_Color = Data->Land_ElapsedTime_Color;
    mbk->Land_ElapsedTime_Font = Data->Land_ElapsedTime_Font;
    mbk->Land_ElapsedTime_Enable = Data->Land_ElapsedTime_Enable;
    
    //RemainingTime
    mbk->Land_RemainingTime_x1 = Data->Land_RemainingTime_x1;
    mbk->Land_RemainingTime_y1 = Data->Land_RemainingTime_y1;
    mbk->Land_RemainingTime_x2 = Data->Land_RemainingTime_x2;
    mbk->Land_RemainingTime_y2 = Data->Land_RemainingTime_y2;
    mbk->Land_RemainingTime_Align = Data->Land_RemainingTime_Align;
    mbk->Land_RemainingTime_Color = Data->Land_RemainingTime_Color;
    mbk->Land_RemainingTime_Font = Data->Land_RemainingTime_Font;
    mbk->Land_RemainingTime_Enable = Data->Land_RemainingTime_Enable;
    
    //Extension
    mbk->Land_Extension_x1 = Data->Land_Extension_x1;
    mbk->Land_Extension_y1 = Data->Land_Extension_y1;
    mbk->Land_Extension_x2 = Data->Land_Extension_x2;
    mbk->Land_Extension_y2 = Data->Land_Extension_y2;
    mbk->Land_Extension_Align = Data->Land_Extension_Align;
    mbk->Land_Extension_Color = Data->Land_Extension_Color;
    mbk->Land_Extension_Font = Data->Land_Extension_Font;
    mbk->Land_Extension_Enable = Data->Land_Extension_Enable;
    
    //BitRate
    mbk->Land_BitRate_x1 = Data->Land_BitRate_x1;
    mbk->Land_BitRate_y1 = Data->Land_BitRate_y1;
    mbk->Land_BitRate_x2 = Data->Land_BitRate_x2;
    mbk->Land_BitRate_y2 = Data->Land_BitRate_y2;
    mbk->Land_BitRate_Align = Data->Land_BitRate_Align;
    mbk->Land_BitRate_Color = Data->Land_BitRate_Color;
    mbk->Land_BitRate_Font = Data->Land_BitRate_Font;
    mbk->Land_BitRate_Enable = Data->Land_BitRate_Enable;
    
    //TotalTrackID
    mbk->Land_TotalTrackID_x1 = Data->Land_TotalTrackID_x1;
    mbk->Land_TotalTrackID_y1 = Data->Land_TotalTrackID_y1;
    mbk->Land_TotalTrackID_x2 = Data->Land_TotalTrackID_x2;
    mbk->Land_TotalTrackID_y2 = Data->Land_TotalTrackID_y2;
    mbk->Land_TotalTrackID_Align = Data->Land_TotalTrackID_Align;
    mbk->Land_TotalTrackID_Color = Data->Land_TotalTrackID_Color;
    mbk->Land_TotalTrackID_Font = Data->Land_TotalTrackID_Font;
    mbk->Land_TotalTrackID_Enable = Data->Land_TotalTrackID_Enable;
    
    //C_TrackID
    mbk->Land_C_TrackID_x1 = Data->Land_C_TrackID_x1;
    mbk->Land_C_TrackID_y1 = Data->Land_C_TrackID_y1;
    mbk->Land_C_TrackID_x2 = Data->Land_C_TrackID_x2;
    mbk->Land_C_TrackID_y2 = Data->Land_C_TrackID_y2;
    mbk->Land_C_TrackID_Align = Data->Land_C_TrackID_Align;
    mbk->Land_C_TrackID_Color = Data->Land_C_TrackID_Color;
    mbk->Land_C_TrackID_Font = Data->Land_C_TrackID_Font;
    mbk->Land_C_TrackID_Enable = Data->Land_C_TrackID_Enable;
    
    //Shuffle_Image
    mbk->Land_Shuffle_Image_x1 = Data->Land_Shuffle_Image_x1;
    mbk->Land_Shuffle_Image_y1 = Data->Land_Shuffle_Image_y1;
    mbk->Land_Shuffle_Image_Enable = Data->Land_Shuffle_Image_Enable;
    
    //Loop_Image
    mbk->Land_Loop_Image_x1 = Data->Land_Loop_Image_x1;
    mbk->Land_Loop_Image_y1 = Data->Land_Loop_Image_y1;
    mbk->Land_Loop_Image_Enable = Data->Land_Loop_Image_Enable;
    
    //EQ_Image
    mbk->Land_EQ_Image_Enable = Data->Land_EQ_Image_Enable;
    mbk->Land_EQ_Image_x1 = Data->Land_EQ_Image_x1;
    mbk->Land_EQ_Image_y1 = Data->Land_EQ_Image_y1;
    
    //PlayerState_Image
    mbk->Land_PlayerState_Image_x1 = Data->Land_PlayerState_Image_x1;
    mbk->Land_PlayerState_Image_y1 = Data->Land_PlayerState_Image_y1;
    mbk->Land_PlayerState_Image_Enable = Data->Land_PlayerState_Image_Enable;
    
    //Title_Image
    mbk->Land_Title_Image_x1 = Data->Land_Title_Image_x1;
    mbk->Land_Title_Image_y1 = Data->Land_Title_Image_y1;
    mbk->Land_Title_Image_Enable = Data->Land_Title_Image_Enable;
    
    //Artist_Image
    mbk->Land_Artist_Image_x1 = Data->Land_Artist_Image_x1;
    mbk->Land_Artist_Image_y1 = Data->Land_Artist_Image_y1;
    mbk->Land_Artist_Image_Enable = Data->Land_Artist_Image_Enable;
    
    //Album_Image
    mbk->Land_Album_Image_x1 = Data->Land_Album_Image_x1;
    mbk->Land_Album_Image_y1 = Data->Land_Album_Image_y1;
    mbk->Land_Album_Image_Enable = Data->Land_Album_Image_Enable;
    
    mbk->Land_WhellBG_Image_Enable = Data->Land_WhellBG_Image_Enable;
    mbk->Land_WhellBG_Image_x1 = Data->Land_WhellBG_Image_x1;
    mbk->Land_WhellBG_Image_y1 = Data->Land_WhellBG_Image_y1;
    
    
    mbk->Land_WhellUP_Image_Enable = Data->Land_WhellUP_Image_Enable;
    mbk->Land_WhellUP_Image_x1 = Data->Land_WhellUP_Image_x1;
    mbk->Land_WhellUP_Image_y1 = Data->Land_WhellUP_Image_y1;
    
    
    mbk->Land_WhellDOWN_Image_Enable = Data->Land_WhellDOWN_Image_Enable;
    mbk->Land_WhellDOWN_Image_x1 = Data->Land_WhellDOWN_Image_x1;
    mbk->Land_WhellDOWN_Image_y1 = Data->Land_WhellDOWN_Image_y1;
    
    
    mbk->Land_WhellLEFT_Image_Enable = Data->Land_WhellLEFT_Image_Enable;
    mbk->Land_WhellLEFT_Image_x1 = Data->Land_WhellLEFT_Image_x1;
    mbk->Land_WhellLEFT_Image_y1 = Data->Land_WhellLEFT_Image_y1;
    
    mbk->Land_WhellRIGHT_Image_Enable = Data->Land_WhellRIGHT_Image_Enable;
    mbk->Land_WhellRIGHT_Image_x1 = Data->Land_WhellRIGHT_Image_x1;
    mbk->Land_WhellRIGHT_Image_y1 = Data->Land_WhellRIGHT_Image_y1;
    
    mbk->Land_WhellCENTER_Image_Enable = Data->Land_WhellCENTER_Image_Enable;
    mbk->Land_WhellCENTER_Image_x1 = Data->Land_WhellCENTER_Image_x1;
    mbk->Land_WhellCENTER_Image_y1 = Data->Land_WhellCENTER_Image_y1;
    
    mbk->Land_Background_Image_Enable = Data->Land_Background_Image_Enable;
    mbk->Land_Background_Image_x1 = Data->Land_Background_Image_x1;
    mbk->Land_Background_Image_y1 = Data->Land_Background_Image_y1;
    
    mbk->Land_Overlay_Image_Enable = Data->Land_Overlay_Image_Enable;
    mbk->Land_Overlay_Image_x1 = Data->Land_Overlay_Image_x1;
    mbk->Land_Overlay_Image_y1 = Data->Land_Overlay_Image_y1;
    
    //Progress Bar
    mbk->Land_ProgressBarEnable = Data->Land_ProgressBarEnable;
    mbk->Land_PRect = Data->Land_PRect;
    mbk->Land_PBColor = Data->Land_PBColor;
    mbk->Land_PFColor = Data->Land_PFColor;
    
    //VolumeBar
    mbk->Land_VolumeBarEnable = Data->Land_VolumeBarEnable;
    mbk->Land_VRect = Data->Land_VRect;
    mbk->Land_VBColor = Data->Land_VBColor;
    mbk->Land_VFColor = Data->Land_VFColor;
    
    //AlbumArt
    mbk->Land_AlbumArtEnable = Data->Land_AlbumArtEnable;
    mbk->Land_ARect = Data->Land_ARect;
    
    //Visualisation
    mbk->Land_VisualisationEnable = Data->Land_VisualisationEnable;
    mbk->Land_VIZRect = Data->Land_VIZRect;

    mbk->FullScreen = Data->FullScreen;
    mbk->ShowSoftKey = Data->ShowSoftKey;
    
    fclose (f);
    mfree(Data);
  }
}

void LoadTempDataToBookHeader(BOOK *book, int ID)
{
  WalkmanSkinEditor_Book* mbk = (WalkmanSkinEditor_Book*)book;
  if(ID==0) 
  {
    mbk->Title_Align = mbk->Str_Align;
    mbk->Title_Enable = mbk->Str_Enable;
    mbk->Title_Font = mbk->Str_Font_Size;
    mbk->Title_Color = mbk->Str_Color;
    mbk->Title_x1 = mbk->Str_x1;
    mbk->Title_x2 = mbk->Str_x2;
    mbk->Title_y1 = mbk->Str_y1;
    mbk->Title_y2 = mbk->Str_y2;    
  }
  if(ID==1) 
  {
    mbk->Artist_Align = mbk->Str_Align;
    mbk->Artist_Enable = mbk->Str_Enable;
    mbk->Artist_Font = mbk->Str_Font_Size;
    mbk->Artist_Color = mbk->Str_Color;
    mbk->Artist_x1 = mbk->Str_x1;
    mbk->Artist_x2 = mbk->Str_x2;
    mbk->Artist_y1 = mbk->Str_y1;
    mbk->Artist_y2 = mbk->Str_y2;   
  }
  if(ID==2) 
  {
    mbk->Album_Align = mbk->Str_Align;
    mbk->Album_Enable = mbk->Str_Enable;
    mbk->Album_Font = mbk->Str_Font_Size;
    mbk->Album_Color = mbk->Str_Color;
    mbk->Album_x1 = mbk->Str_x1;
    mbk->Album_x2 = mbk->Str_x2;
    mbk->Album_y1 = mbk->Str_y1;
    mbk->Album_y2 = mbk->Str_y2;  
  }
  if(ID==3) 
  {
    mbk->Genre_Align = mbk->Str_Align;
    mbk->Genre_Enable = mbk->Str_Enable;
    mbk->Genre_Font = mbk->Str_Font_Size;
    mbk->Genre_Color = mbk->Str_Color;
    mbk->Genre_x1 = mbk->Str_x1;
    mbk->Genre_x2 = mbk->Str_x2;
    mbk->Genre_y1 = mbk->Str_y1;
    mbk->Genre_y2 = mbk->Str_y2;    
  }
  if(ID==4) 
  {
    mbk->TotalTime_Align = mbk->Str_Align;
    mbk->TotalTime_Enable = mbk->Str_Enable;
    mbk->TotalTime_Font = mbk->Str_Font_Size;
    mbk->TotalTime_Color = mbk->Str_Color;
    mbk->TotalTime_x1 = mbk->Str_x1;
    mbk->TotalTime_x2 = mbk->Str_x2;
    mbk->TotalTime_y1 = mbk->Str_y1;
    mbk->TotalTime_y2 = mbk->Str_y2;  
  }
  if(ID==5) 
  {
    mbk->ElapsedTime_Align = mbk->Str_Align;
    mbk->ElapsedTime_Enable = mbk->Str_Enable;
    mbk->ElapsedTime_Font = mbk->Str_Font_Size;
    mbk->ElapsedTime_Color = mbk->Str_Color;
    mbk->ElapsedTime_x1 = mbk->Str_x1;
    mbk->ElapsedTime_x2 = mbk->Str_x2;
    mbk->ElapsedTime_y1 = mbk->Str_y1;
    mbk->ElapsedTime_y2 = mbk->Str_y2;   
  }
  if(ID==6) 
  {
    mbk->RemainingTime_Align = mbk->Str_Align;
    mbk->RemainingTime_Enable = mbk->Str_Enable;
    mbk->RemainingTime_Font = mbk->Str_Font_Size;
    mbk->RemainingTime_Color = mbk->Str_Color;
    mbk->RemainingTime_x1 = mbk->Str_x1;
    mbk->RemainingTime_x2 = mbk->Str_x2;
    mbk->RemainingTime_y1 = mbk->Str_y1;
    mbk->RemainingTime_y2 = mbk->Str_y2;   
  }
  if(ID==7) 
  {
    mbk->Extension_Align = mbk->Str_Align;
    mbk->Extension_Enable = mbk->Str_Enable;
    mbk->Extension_Font = mbk->Str_Font_Size;
    mbk->Extension_Color = mbk->Str_Color;
    mbk->Extension_x1 = mbk->Str_x1;
    mbk->Extension_x2 = mbk->Str_x2;
    mbk->Extension_y1 = mbk->Str_y1;
    mbk->Extension_y2 = mbk->Str_y2;   
  }
  if(ID==8) 
  {
    mbk->BitRate_Align = mbk->Str_Align;
    mbk->BitRate_Enable = mbk->Str_Enable;
    mbk->BitRate_Font = mbk->Str_Font_Size;
    mbk->BitRate_Color = mbk->Str_Color;
    mbk->BitRate_x1 = mbk->Str_x1;
    mbk->BitRate_x2 = mbk->Str_x2;
    mbk->BitRate_y1 = mbk->Str_y1;
    mbk->BitRate_y2 = mbk->Str_y2;  
  }
  if(ID==9) 
  {
    mbk->TotalTrackID_Align = mbk->Str_Align;
    mbk->TotalTrackID_Enable = mbk->Str_Enable;
    mbk->TotalTrackID_Font = mbk->Str_Font_Size;
    mbk->TotalTrackID_Color = mbk->Str_Color;
    mbk->TotalTrackID_x1 = mbk->Str_x1;
    mbk->TotalTrackID_x2 = mbk->Str_x2;
    mbk->TotalTrackID_y1 = mbk->Str_y1;
    mbk->TotalTrackID_y2 = mbk->Str_y2;
  }
  if(ID==10) 
  {
    mbk->C_TrackID_Align = mbk->Str_Align;
    mbk->C_TrackID_Enable = mbk->Str_Enable;
    mbk->C_TrackID_Font = mbk->Str_Font_Size;
    mbk->C_TrackID_Color = mbk->Str_Color;
    mbk->C_TrackID_x1 = mbk->Str_x1;
    mbk->C_TrackID_x2 = mbk->Str_x2;
    mbk->C_TrackID_y1 = mbk->Str_y1;
    mbk->C_TrackID_y2 = mbk->Str_y2;  
  }
  if(ID==11) 
  {
    mbk->Shuffle_Image_Enable = mbk->Str_Enable;
    mbk->Shuffle_Image_x1 = mbk->Str_x1;
    mbk->Shuffle_Image_y1 = mbk->Str_y1;  
  }  
  if(ID==12) 
  {
    mbk->Loop_Image_Enable = mbk->Str_Enable;
    mbk->Loop_Image_x1 = mbk->Str_x1;
    mbk->Loop_Image_y1 = mbk->Str_y1;
  }  
  if(ID==13) 
  {
    mbk->EQ_Image_Enable = mbk->Str_Enable;
    mbk->EQ_Image_x1 = mbk->Str_x1;
    mbk->EQ_Image_y1 = mbk->Str_y1;
  } 
  if(ID==14) 
  {
    mbk->PlayerState_Image_Enable = mbk->Str_Enable;
    mbk->PlayerState_Image_x1 = mbk->Str_x1;
    mbk->PlayerState_Image_y1 = mbk->Str_y1; 
  }  
  if(ID==15) 
  {
    mbk->Title_Image_Enable = mbk->Str_Enable;
    mbk->Title_Image_x1 = mbk->Str_x1;
    mbk->Title_Image_y1 = mbk->Str_y1;
  }
  if(ID==16) 
  {
    mbk->Artist_Image_Enable = mbk->Str_Enable;
    mbk->Artist_Image_x1 = mbk->Str_x1;
    mbk->Artist_Image_y1 = mbk->Str_y1;
  }
  if(ID==17) 
  {
    mbk->Album_Image_Enable = mbk->Str_Enable;
    mbk->Album_Image_x1 = mbk->Str_x1;
    mbk->Album_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==18)
  {
    mbk->WhellBG_Image_Enable = mbk->Str_Enable;
    mbk->WhellBG_Image_x1 = mbk->Str_x1;
    mbk->WhellBG_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==19)
  {
    mbk->WhellUP_Image_Enable = mbk->Str_Enable;
    mbk->WhellUP_Image_x1 = mbk->Str_x1;
    mbk->WhellUP_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==20)
  {
    mbk->WhellDOWN_Image_Enable = mbk->Str_Enable;
    mbk->WhellDOWN_Image_x1 = mbk->Str_x1;
    mbk->WhellDOWN_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==21)
  {
    mbk->WhellLEFT_Image_Enable = mbk->Str_Enable;
    mbk->WhellLEFT_Image_x1 = mbk->Str_x1;
    mbk->WhellLEFT_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==22)
  {
    mbk->WhellRIGHT_Image_Enable = mbk->Str_Enable;
    mbk->WhellRIGHT_Image_x1 = mbk->Str_x1;
    mbk->WhellRIGHT_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==23)
  {
    mbk->WhellCENTER_Image_Enable = mbk->Str_Enable;
    mbk->WhellCENTER_Image_x1 = mbk->Str_x1;
    mbk->WhellCENTER_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==24)
  {
    mbk->Background_Image_Enable = mbk->Str_Enable;
    mbk->Background_Image_x1 = mbk->Str_x1;
    mbk->Background_Image_y1 = mbk->Str_y1;
  }
  if(ID==25)
  {
    mbk->Overlay_Image_Enable = mbk->Str_Enable;
    mbk->Overlay_Image_x1 = mbk->Str_x1;
    mbk->Overlay_Image_y1 = mbk->Str_y1;
  }
  if(ID==26)
  {
    mbk->ProgressBarEnable = mbk->Str_Enable;
    mbk->PBColor = mbk->Str_Color;
    mbk->PFColor = mbk->Str_Color_2;
    mbk->PRect.x1 = mbk->Str_x1;
    mbk->PRect.x2 = mbk->Str_x2;
    mbk->PRect.y1 = mbk->Str_y1;
    mbk->PRect.y2 = mbk->Str_y2;
  }
  
  if(ID==27)
  {
    mbk->VolumeBarEnable = mbk->Str_Enable;
    mbk->VBColor = mbk->Str_Color;
    mbk->VFColor = mbk->Str_Color_2;
    mbk->VRect.x1 = mbk->Str_x1;
    mbk->VRect.x2 = mbk->Str_x2;
    mbk->VRect.y1 = mbk->Str_y1;
    mbk->VRect.y2 = mbk->Str_y2;
  }
  if(ID==28)
  {
    mbk->ARect.x1 = mbk->Str_x1;
    mbk->ARect.x2 = mbk->Str_x2;
    mbk->ARect.y1 = mbk->Str_y1;
    mbk->ARect.y2 = mbk->Str_y2;
  }


  if(ID==29)
  {
    mbk->VRect.x1 = mbk->Str_x1;
    mbk->VRect.x2 = mbk->Str_x2;
    mbk->VRect.y1 = mbk->Str_y1;
    mbk->VRect.y2 = mbk->Str_y2;
  }

// --------------------------------------------
  
  if(ID==30) 
  {
    mbk->Land_Title_Align = mbk->Str_Align;
    mbk->Land_Title_Enable = mbk->Str_Enable;
    mbk->Land_Title_Font = mbk->Str_Font_Size;
    mbk->Land_Title_Color = mbk->Str_Color;
    mbk->Land_Title_x1 = mbk->Str_x1;
    mbk->Land_Title_x2 = mbk->Str_x2;
    mbk->Land_Title_y1 = mbk->Str_y1;
    mbk->Land_Title_y2 = mbk->Str_y2;    
  }
  if(ID==31) 
  {
    mbk->Land_Artist_Align = mbk->Str_Align;
    mbk->Land_Artist_Enable = mbk->Str_Enable;
    mbk->Land_Artist_Font = mbk->Str_Font_Size;
    mbk->Land_Artist_Color = mbk->Str_Color;
    mbk->Land_Artist_x1 = mbk->Str_x1;
    mbk->Land_Artist_x2 = mbk->Str_x2;
    mbk->Land_Artist_y1 = mbk->Str_y1;
    mbk->Land_Artist_y2 = mbk->Str_y2;   
  }
  if(ID==32) 
  {
    mbk->Land_Album_Align = mbk->Str_Align;
    mbk->Land_Album_Enable = mbk->Str_Enable;
    mbk->Land_Album_Font = mbk->Str_Font_Size;
    mbk->Land_Album_Color = mbk->Str_Color;
    mbk->Land_Album_x1 = mbk->Str_x1;
    mbk->Land_Album_x2 = mbk->Str_x2;
    mbk->Land_Album_y1 = mbk->Str_y1;
    mbk->Land_Album_y2 = mbk->Str_y2;  
  }
  if(ID==33) 
  {
    mbk->Land_Genre_Align = mbk->Str_Align;
    mbk->Land_Genre_Enable = mbk->Str_Enable;
    mbk->Land_Genre_Font = mbk->Str_Font_Size;
    mbk->Land_Genre_Color = mbk->Str_Color;
    mbk->Land_Genre_x1 = mbk->Str_x1;
    mbk->Land_Genre_x2 = mbk->Str_x2;
    mbk->Land_Genre_y1 = mbk->Str_y1;
    mbk->Land_Genre_y2 = mbk->Str_y2;    
  }
  if(ID==34) 
  {
    mbk->Land_TotalTime_Align = mbk->Str_Align;
    mbk->Land_TotalTime_Enable = mbk->Str_Enable;
    mbk->Land_TotalTime_Font = mbk->Str_Font_Size;
    mbk->Land_TotalTime_Color = mbk->Str_Color;
    mbk->Land_TotalTime_x1 = mbk->Str_x1;
    mbk->Land_TotalTime_x2 = mbk->Str_x2;
    mbk->Land_TotalTime_y1 = mbk->Str_y1;
    mbk->Land_TotalTime_y2 = mbk->Str_y2;  
  }
  if(ID==35) 
  {
    mbk->Land_ElapsedTime_Align = mbk->Str_Align;
    mbk->Land_ElapsedTime_Enable = mbk->Str_Enable;
    mbk->Land_ElapsedTime_Font = mbk->Str_Font_Size;
    mbk->Land_ElapsedTime_Color = mbk->Str_Color;
    mbk->Land_ElapsedTime_x1 = mbk->Str_x1;
    mbk->Land_ElapsedTime_x2 = mbk->Str_x2;
    mbk->Land_ElapsedTime_y1 = mbk->Str_y1;
    mbk->Land_ElapsedTime_y2 = mbk->Str_y2;   
  }
  if(ID==36) 
  {
    mbk->Land_RemainingTime_Align = mbk->Str_Align;
    mbk->Land_RemainingTime_Enable = mbk->Str_Enable;
    mbk->Land_RemainingTime_Font = mbk->Str_Font_Size;
    mbk->Land_RemainingTime_Color = mbk->Str_Color;
    mbk->Land_RemainingTime_x1 = mbk->Str_x1;
    mbk->Land_RemainingTime_x2 = mbk->Str_x2;
    mbk->Land_RemainingTime_y1 = mbk->Str_y1;
    mbk->Land_RemainingTime_y2 = mbk->Str_y2;   
  }
  if(ID==37) 
  {
    mbk->Land_Extension_Align = mbk->Str_Align;
    mbk->Land_Extension_Enable = mbk->Str_Enable;
    mbk->Land_Extension_Font = mbk->Str_Font_Size;
    mbk->Land_Extension_Color = mbk->Str_Color;
    mbk->Land_Extension_x1 = mbk->Str_x1;
    mbk->Land_Extension_x2 = mbk->Str_x2;
    mbk->Land_Extension_y1 = mbk->Str_y1;
    mbk->Land_Extension_y2 = mbk->Str_y2;   
  }
  if(ID==38) 
  {
    mbk->Land_BitRate_Align = mbk->Str_Align;
    mbk->Land_BitRate_Enable = mbk->Str_Enable;
    mbk->Land_BitRate_Font = mbk->Str_Font_Size;
    mbk->Land_BitRate_Color = mbk->Str_Color;
    mbk->Land_BitRate_x1 = mbk->Str_x1;
    mbk->Land_BitRate_x2 = mbk->Str_x2;
    mbk->Land_BitRate_y1 = mbk->Str_y1;
    mbk->Land_BitRate_y2 = mbk->Str_y2;  
  }
  if(ID==39) 
  {
    mbk->Land_TotalTrackID_Align = mbk->Str_Align;
    mbk->Land_TotalTrackID_Enable = mbk->Str_Enable;
    mbk->Land_TotalTrackID_Font = mbk->Str_Font_Size;
    mbk->Land_TotalTrackID_Color = mbk->Str_Color;
    mbk->Land_TotalTrackID_x1 = mbk->Str_x1;
    mbk->Land_TotalTrackID_x2 = mbk->Str_x2;
    mbk->Land_TotalTrackID_y1 = mbk->Str_y1;
    mbk->Land_TotalTrackID_y2 = mbk->Str_y2;
  }
  if(ID==40) 
  {
    mbk->Land_C_TrackID_Align = mbk->Str_Align;
    mbk->Land_C_TrackID_Enable = mbk->Str_Enable;
    mbk->Land_C_TrackID_Font = mbk->Str_Font_Size;
    mbk->Land_C_TrackID_Color = mbk->Str_Color;
    mbk->Land_C_TrackID_x1 = mbk->Str_x1;
    mbk->Land_C_TrackID_x2 = mbk->Str_x2;
    mbk->Land_C_TrackID_y1 = mbk->Str_y1;
    mbk->Land_C_TrackID_y2 = mbk->Str_y2;  
  }
  if(ID==41) 
  {
    mbk->Land_Shuffle_Image_Enable = mbk->Str_Enable;
    mbk->Land_Shuffle_Image_x1 = mbk->Str_x1;
    mbk->Land_Shuffle_Image_y1 = mbk->Str_y1;  
  }  
  if(ID==42) 
  {
    mbk->Land_Loop_Image_Enable = mbk->Str_Enable;
    mbk->Land_Loop_Image_x1 = mbk->Str_x1;
    mbk->Land_Loop_Image_y1 = mbk->Str_y1;
  }   
  if(ID==43) 
  {
    mbk->Land_EQ_Image_Enable = mbk->Str_Enable;
    mbk->Land_EQ_Image_x1 = mbk->Str_x1;
    mbk->Land_EQ_Image_y1 = mbk->Str_y1;
  }  
  
  if(ID==44) 
  {
    mbk->Land_PlayerState_Image_Enable = mbk->Str_Enable;
    mbk->Land_PlayerState_Image_x1 = mbk->Str_x1;
    mbk->Land_PlayerState_Image_y1 = mbk->Str_y1; 
  }  
  if(ID==45) 
  {
    mbk->Land_Title_Image_Enable = mbk->Str_Enable;
    mbk->Land_Title_Image_x1 = mbk->Str_x1;
    mbk->Land_Title_Image_y1 = mbk->Str_y1;
  }
  if(ID==46) 
  {
    mbk->Land_Artist_Image_Enable = mbk->Str_Enable;
    mbk->Land_Artist_Image_x1 = mbk->Str_x1;
    mbk->Land_Artist_Image_y1 = mbk->Str_y1;
  }
  if(ID==47) 
  {
    mbk->Land_Album_Image_Enable = mbk->Str_Enable;
    mbk->Land_Album_Image_x1 = mbk->Str_x1;
    mbk->Land_Album_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==48)
  {
    mbk->Land_WhellBG_Image_Enable = mbk->Str_Enable;
    mbk->Land_WhellBG_Image_x1 = mbk->Str_x1;
    mbk->Land_WhellBG_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==49)
  {
    mbk->Land_WhellUP_Image_Enable = mbk->Str_Enable;
    mbk->Land_WhellUP_Image_x1 = mbk->Str_x1;
    mbk->Land_WhellUP_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==50)
  {
    mbk->Land_WhellDOWN_Image_Enable = mbk->Str_Enable;
    mbk->Land_WhellDOWN_Image_x1 = mbk->Str_x1;
    mbk->Land_WhellDOWN_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==51)
  {
    mbk->Land_WhellLEFT_Image_Enable = mbk->Str_Enable;
    mbk->Land_WhellLEFT_Image_x1 = mbk->Str_x1;
    mbk->Land_WhellLEFT_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==52)
  {
    mbk->Land_WhellRIGHT_Image_Enable = mbk->Str_Enable;
    mbk->Land_WhellRIGHT_Image_x1 = mbk->Str_x1;
    mbk->Land_WhellRIGHT_Image_y1 = mbk->Str_y1;
  }
  
  
  if(ID==53)
  {
    mbk->Land_WhellCENTER_Image_Enable = mbk->Str_Enable;
    mbk->Land_WhellCENTER_Image_x1 = mbk->Str_x1;
    mbk->Land_WhellCENTER_Image_y1 = mbk->Str_y1;
  }
  
  if(ID==54)
  {
    mbk->Land_Background_Image_Enable = mbk->Str_Enable;
    mbk->Land_Background_Image_x1 = mbk->Str_x1;
    mbk->Land_Background_Image_y1 = mbk->Str_y1;
  }
  if(ID==55)
  {
    mbk->Land_Overlay_Image_Enable = mbk->Str_Enable;
    mbk->Land_Overlay_Image_x1 = mbk->Str_x1;
    mbk->Land_Overlay_Image_y1 = mbk->Str_y1;
  }
  if(ID==56)
  {
    mbk->Land_ProgressBarEnable = mbk->Str_Enable;
    mbk->Land_PBColor = mbk->Str_Color;
    mbk->Land_PFColor = mbk->Str_Color_2;
    mbk->Land_PRect.x1 = mbk->Str_x1;
    mbk->Land_PRect.x2 = mbk->Str_x2;
    mbk->Land_PRect.y1 = mbk->Str_y1;
    mbk->Land_PRect.y2 = mbk->Str_y2;
  }
  if(ID==57)
  {
    mbk->Land_VolumeBarEnable = mbk->Str_Enable;
    mbk->Land_VBColor = mbk->Str_Color;
    mbk->Land_VFColor = mbk->Str_Color_2;
    mbk->Land_VRect.x1 = mbk->Str_x1;
    mbk->Land_VRect.x2 = mbk->Str_x2;
    mbk->Land_VRect.y1 = mbk->Str_y1;
    mbk->Land_VRect.y2 = mbk->Str_y2;
  }
  if(ID==58)
  {
    mbk->Land_ARect.x1 = mbk->Str_x1;
    mbk->Land_ARect.x2 = mbk->Str_x2;
    mbk->Land_ARect.y1 = mbk->Str_y1;
    mbk->Land_ARect.y2 = mbk->Str_y2;
  }
  if(ID==59)
  {
    mbk->Land_VRect.x1 = mbk->Str_x1;
    mbk->Land_VRect.x2 = mbk->Str_x2;
    mbk->Land_VRect.y1 = mbk->Str_y1;
    mbk->Land_VRect.y2 = mbk->Str_y2;
  }  
}

extern "C"
void LoadPortraitData()
{
  //wchar_t path[256]=L"";
  // wchar_t name[256]=L"";
  
  int Lf;
  if(( Lf = _fopen( SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    SKIN* LData  = (SKIN*)malloc(sizeof(SKIN));
    memset( LData, NULL, sizeof(SKIN));
    fread( Lf, LData, sizeof(SKIN));
    //wstrcpy(path, Data->Path);
    //wstrcpy(name, Data->Name);
    
    int f;
    if(( f = _fopen( LData->Path, LData->Name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
    {
      SkinData* Data  = (SkinData*)malloc(sizeof(SkinData));
      memset( Data, NULL, sizeof(SkinData));
      fread( f, Data, sizeof(SkinData));
      WALKMAN_Function * WData = Get_WALKMAN_Function();
      
      WData->Portrait = TRUE;
      //Title
      WData->Main.Title.x1 = Data->Title_x1;
      WData->Main.Title.y1 = Data->Title_y1;
      WData->Main.Title.x2 = Data->Title_x2;
      WData->Main.Title.y2  = Data->Title_y2;
      WData->Main.Title.Align = Data->Title_Align;
      WData->Main.Title.Color = Data->Title_Color;
      WData->Main.Title.Font = Data->Title_Font;
      WData->Main.Title.Enable = Data->Title_Enable;
      
      //Artist
      WData->Main.Artist.x1 = Data->Artist_x1;
      WData->Main.Artist.y1 = Data->Artist_y1;
      WData->Main.Artist.x2 = Data->Artist_x2;
      WData->Main.Artist.y2 = Data->Artist_y2;
      WData->Main.Artist.Align = Data->Artist_Align;
      WData->Main.Artist.Font = Data->Artist_Font;
      WData->Main.Artist.Color = Data->Artist_Color;
      WData->Main.Artist.Enable = Data->Artist_Enable;
      
      //Album
      WData->Main.Album.x1 = Data->Album_x1;
      WData->Main.Album.y1 = Data->Album_y1;
      WData->Main.Album.x2 = Data->Album_x2;
      WData->Main.Album.y2 = Data->Album_y2;
      WData->Main.Album.Align = Data->Album_Align;
      WData->Main.Album.Color = Data->Album_Color;
      WData->Main.Album.Font = Data->Album_Font;
      WData->Main.Album.Enable = Data->Album_Enable;
      
      //Genre
      WData->Main.Genre.x1 = Data->Genre_x1;
      WData->Main.Genre.y1 = Data->Genre_y1;
      WData->Main.Genre.x2 = Data->Genre_x2;
      WData->Main.Genre.y2 = Data->Genre_y2;
      WData->Main.Genre.Align = Data->Genre_Align;
      WData->Main.Genre.Color = Data->Genre_Color;
      WData->Main.Genre.Font = Data->Genre_Font;
      WData->Main.Genre.Enable = Data->Genre_Enable;
      
      //TotalTime
      WData->Main.TotalTime.x1 = Data->TotalTime_x1;
      WData->Main.TotalTime.y1 = Data->TotalTime_y1;
      WData->Main.TotalTime.x2 = Data->TotalTime_x2;
      WData->Main.TotalTime.y2 = Data->TotalTime_y2;
      WData->Main.TotalTime.Align = Data->TotalTime_Align;
      WData->Main.TotalTime.Color = Data->TotalTime_Color;
      WData->Main.TotalTime.Font = Data->TotalTime_Font;
      WData->Main.TotalTime.Enable = Data->TotalTime_Enable;
      
      //ElapsedTime
      WData->Main.ElapsedTime.x1 = Data->ElapsedTime_x1;
      WData->Main.ElapsedTime.y1 = Data->ElapsedTime_y1;
      WData->Main.ElapsedTime.x2 = Data->ElapsedTime_x2;
      WData->Main.ElapsedTime.y2 = Data->ElapsedTime_y2;
      WData->Main.ElapsedTime.Align = Data->ElapsedTime_Align;
      WData->Main.ElapsedTime.Color = Data->ElapsedTime_Color;
      WData->Main.ElapsedTime.Font = Data->ElapsedTime_Font;
      WData->Main.ElapsedTime.Enable = Data->ElapsedTime_Enable;
      
      //RemainingTime
      WData->Main.RemainingTime.x1 = Data->RemainingTime_x1;
      WData->Main.RemainingTime.y1 = Data->RemainingTime_y1;
      WData->Main.RemainingTime.x2 = Data->RemainingTime_x2;
      WData->Main.RemainingTime.y2 = Data->RemainingTime_y2;
      WData->Main.RemainingTime.Align = Data->RemainingTime_Align;
      WData->Main.RemainingTime.Color = Data->RemainingTime_Color;
      WData->Main.RemainingTime.Font = Data->RemainingTime_Font;
      WData->Main.RemainingTime.Enable = Data->RemainingTime_Enable;
      
      //Extension
      WData->Main.Extension.x1 = Data->Extension_x1;
      WData->Main.Extension.y1 = Data->Extension_y1;
      WData->Main.Extension.x2 = Data->Extension_x2;
      WData->Main.Extension.y2 = Data->Extension_y2;
      WData->Main.Extension.Align = Data->Extension_Align;
      WData->Main.Extension.Color = Data->Extension_Color;
      WData->Main.Extension.Font = Data->Extension_Font;
      WData->Main.Extension.Enable = Data->Extension_Enable;
      
      //BitRate
      WData->Main.BitRate.x1 = Data->BitRate_x1;
      WData->Main.BitRate.y1 = Data->BitRate_y1;
      WData->Main.BitRate.x2 = Data->BitRate_x2;
      WData->Main.BitRate.y2 = Data->BitRate_y2;
      WData->Main.BitRate.Align = Data->BitRate_Align;
      WData->Main.BitRate.Color = Data->BitRate_Color;
      WData->Main.BitRate.Font = Data->BitRate_Font;
      WData->Main.BitRate.Enable = Data->BitRate_Enable;
      
      //TotalTrackID
      WData->Main.TotalTrackID.x1 = Data->TotalTrackID_x1;
      WData->Main.TotalTrackID.y1 = Data->TotalTrackID_y1;
      WData->Main.TotalTrackID.x2 = Data->TotalTrackID_x2;
      WData->Main.TotalTrackID.y2 = Data->TotalTrackID_y2;
      WData->Main.TotalTrackID.Align = Data->TotalTrackID_Align;
      WData->Main.TotalTrackID.Color = Data->TotalTrackID_Color;
      WData->Main.TotalTrackID.Font = Data->TotalTrackID_Font;
      WData->Main.TotalTrackID.Enable = Data->TotalTrackID_Enable;
      
      //C_TrackID
      WData->Main.C_TrackID.x1 = Data->C_TrackID_x1;
      WData->Main.C_TrackID.y1 = Data->C_TrackID_y1;
      WData->Main.C_TrackID.x2 = Data->C_TrackID_x2;
      WData->Main.C_TrackID.y2 = Data->C_TrackID_y2;
      WData->Main.C_TrackID.Align = Data->C_TrackID_Align;
      WData->Main.C_TrackID.Color = Data->C_TrackID_Color;
      WData->Main.C_TrackID.Font = Data->C_TrackID_Font;
      WData->Main.C_TrackID.Enable = Data->C_TrackID_Enable;
      
      //Shuffle_Image
      WData->Main.Shuffle_Image_x1 = Data->Shuffle_Image_x1;
      WData->Main.Shuffle_Image_y1 = Data->Shuffle_Image_y1;
      WData->Main.Shuffle_Image_Enable = Data->Shuffle_Image_Enable;
      
      //Loop_Image
      WData->Main.Loop_Image_x1 = Data->Loop_Image_x1;
      WData->Main.Loop_Image_y1 = Data->Loop_Image_y1;
      WData->Main.Loop_Image_Enable = Data->Loop_Image_Enable;
      
      //EQ_Image
      WData->Main.EQ_Image_Enable = Data->EQ_Image_Enable;
      WData->Main.EQ_Image_x1 = Data->EQ_Image_x1;
      WData->Main.EQ_Image_y1 = Data->EQ_Image_y1;
      
      //PlayerState_Image
      WData->Main.PlayerState_Image_x1 = Data->PlayerState_Image_x1;
      WData->Main.PlayerState_Image_y1 = Data->PlayerState_Image_y1;
      WData->Main.PlayerState_Image_Enable = Data->PlayerState_Image_Enable;
      
      //Title_Image
      WData->Main.Title_Image_x1 = Data->Title_Image_x1;
      WData->Main.Title_Image_y1 = Data->Title_Image_y1;
      WData->Main.Title_Image_Enable = Data->Title_Image_Enable;
      
      //Artist_Image
      WData->Main.Artist_Image_x1 = Data->Artist_Image_x1;
      WData->Main.Artist_Image_y1 = Data->Artist_Image_y1;
      WData->Main.Artist_Image_Enable = Data->Artist_Image_Enable;
      
      //Album_Image
      WData->Main.Album_Image_x1 = Data->Album_Image_x1;
      WData->Main.Album_Image_y1 = Data->Album_Image_y1;
      WData->Main.Album_Image_Enable = Data->Album_Image_Enable;
      
      WData->Main.WhellBG_Image_Enable = Data->WhellBG_Image_Enable;
      WData->Main.WhellBG_Image_x1 = Data->WhellBG_Image_x1;
      WData->Main.WhellBG_Image_y1 = Data->WhellBG_Image_y1;
      
      
      WData->Main.WhellUP_Image_Enable = Data->WhellUP_Image_Enable;
      WData->Main.WhellUP_Image_x1 = Data->WhellUP_Image_x1;
      WData->Main.WhellUP_Image_y1 = Data->WhellUP_Image_y1;
      
      
      WData->Main.WhellDOWN_Image_Enable = Data->WhellDOWN_Image_Enable;
      WData->Main.WhellDOWN_Image_x1 = Data->WhellDOWN_Image_x1;
      WData->Main.WhellDOWN_Image_y1 = Data->WhellDOWN_Image_y1;
      
      
      WData->Main.WhellLEFT_Image_Enable = Data->WhellLEFT_Image_Enable;
      WData->Main.WhellLEFT_Image_x1 = Data->WhellLEFT_Image_x1;
      WData->Main.WhellLEFT_Image_y1 = Data->WhellLEFT_Image_y1;
      
      WData->Main.WhellRIGHT_Image_Enable = Data->WhellRIGHT_Image_Enable;
      WData->Main.WhellRIGHT_Image_x1 = Data->WhellRIGHT_Image_x1;
      WData->Main.WhellRIGHT_Image_y1 = Data->WhellRIGHT_Image_y1;
      
      WData->Main.WhellCENTER_Image_Enable = Data->WhellCENTER_Image_Enable;
      WData->Main.WhellCENTER_Image_x1 = Data->WhellCENTER_Image_x1;
      WData->Main.WhellCENTER_Image_y1 = Data->WhellCENTER_Image_y1;
      
      WData->Main.Background_Image_Enable = Data->Background_Image_Enable;
      WData->Main.Background_Image_x1 = Data->Background_Image_x1;
      WData->Main.Background_Image_y1 = Data->Background_Image_y1;
      
      WData->Main.Overlay_Image_Enable = Data->Overlay_Image_Enable;
      WData->Main.Overlay_Image_x1 = Data->Overlay_Image_x1;
      WData->Main.Overlay_Image_y1 = Data->Overlay_Image_y1;
      
      //Progress Bar
      WData->Main.ProgressBarEnable = Data->ProgressBarEnable;
      WData->Main.PRect = Data->PRect;
      WData->Main.PBColor = Data->PBColor;
      WData->Main.PFColor = Data->PFColor;
      
      //VolumeBar
      WData->Main.VolumeBarEnable = Data->VolumeBarEnable;
      WData->Main.VRect = Data->VRect;
      WData->Main.VBColor = Data->VBColor;
      WData->Main.VFColor = Data->VFColor;
      
      //AlbumArt
      WData->Main.AlbumArtEnable = Data->AlbumArtEnable;
      WData->Main.ARect = Data->ARect;
      
      //Visualisation
      WData->Main.VisualisationEnable = Data->VisualisationEnable;
      WData->Main.VIZRect = Data->VIZRect;
      
      WData->FullScreen = Data->FullScreen;
      WData->ShowSoftKey = Data->ShowSoftKey;
    
      fclose (f);
      mfree(Data);
    }
    fclose (Lf);
    mfree(LData);
  }
}

extern "C"
void LoadLandscapeData()
{
  //  wchar_t path[256]=L"";
  //  wchar_t name[256]=L"";

  int Lf;
  if ( (Lf = _fopen( SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    SKIN* LData  = (SKIN*)malloc(sizeof(SKIN));
    memset( LData, NULL, sizeof(SKIN) );
    fread( Lf, LData, sizeof(SKIN) );
    //wstrcpy(path, LData->Path);
    //wstrcpy(name, LData->Name);
    
    int f;
    if(( f = _fopen( LData->Path, LData->Name, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
    {
      SkinData* Data  = (SkinData*)malloc(sizeof(SkinData));
      memset( Data, NULL, sizeof(SkinData));
      fread( f, Data, sizeof(SkinData));
      
      WALKMAN_Function * WData = Get_WALKMAN_Function();
      
      WData->Portrait = FALSE;
      WData->Main.Title.x1 = Data->Land_Title_x1;
      WData->Main.Title.y1 = Data->Land_Title_y1;
      WData->Main.Title.x2 = Data->Land_Title_x2;
      WData->Main.Title.y2  = Data->Land_Title_y2;
      WData->Main.Title.Align = Data->Land_Title_Align;
      WData->Main.Title.Color = Data->Land_Title_Color;
      WData->Main.Title.Font = Data->Land_Title_Font;
      WData->Main.Title.Enable = Data->Land_Title_Enable;
      
      //Artist
      WData->Main.Artist.x1 = Data->Land_Artist_x1;
      WData->Main.Artist.y1 = Data->Land_Artist_y1;
      WData->Main.Artist.x2 = Data->Land_Artist_x2;
      WData->Main.Artist.y2 = Data->Land_Artist_y2;
      WData->Main.Artist.Align = Data->Land_Artist_Align;
      WData->Main.Artist.Font = Data->Land_Artist_Font;
      WData->Main.Artist.Color = Data->Land_Artist_Color;
      WData->Main.Artist.Enable = Data->Land_Artist_Enable;
      
      //Album
      WData->Main.Album.x1 = Data->Land_Album_x1;
      WData->Main.Album.y1 = Data->Land_Album_y1;
      WData->Main.Album.x2 = Data->Land_Album_x2;
      WData->Main.Album.y2 = Data->Land_Album_y2;
      WData->Main.Album.Align = Data->Land_Album_Align;
      WData->Main.Album.Color = Data->Land_Album_Color;
      WData->Main.Album.Font = Data->Land_Album_Font;
      WData->Main.Album.Enable = Data->Land_Album_Enable;
      
      //Genre
      WData->Main.Genre.x1 = Data->Land_Genre_x1;
      WData->Main.Genre.y1 = Data->Land_Genre_y1;
      WData->Main.Genre.x2 = Data->Land_Genre_x2;
      WData->Main.Genre.y2 = Data->Land_Genre_y2;
      WData->Main.Genre.Align = Data->Land_Genre_Align;
      WData->Main.Genre.Color = Data->Land_Genre_Color;
      WData->Main.Genre.Font = Data->Land_Genre_Font;
      WData->Main.Genre.Enable = Data->Land_Genre_Enable;
      
      //TotalTime
      WData->Main.TotalTime.x1 = Data->Land_TotalTime_x1;
      WData->Main.TotalTime.y1 = Data->Land_TotalTime_y1;
      WData->Main.TotalTime.x2 = Data->Land_TotalTime_x2;
      WData->Main.TotalTime.y2 = Data->Land_TotalTime_y2;
      WData->Main.TotalTime.Align = Data->Land_TotalTime_Align;
      WData->Main.TotalTime.Color = Data->Land_TotalTime_Color;
      WData->Main.TotalTime.Font = Data->Land_TotalTime_Font;
      WData->Main.TotalTime.Enable = Data->Land_TotalTime_Enable;
      
      //ElapsedTime
      WData->Main.ElapsedTime.x1 = Data->Land_ElapsedTime_x1;
      WData->Main.ElapsedTime.y1 = Data->Land_ElapsedTime_y1;
      WData->Main.ElapsedTime.x2 = Data->Land_ElapsedTime_x2;
      WData->Main.ElapsedTime.y2 = Data->Land_ElapsedTime_y2;
      WData->Main.ElapsedTime.Align = Data->Land_ElapsedTime_Align;
      WData->Main.ElapsedTime.Color = Data->Land_ElapsedTime_Color;
      WData->Main.ElapsedTime.Font = Data->Land_ElapsedTime_Font;
      WData->Main.ElapsedTime.Enable = Data->Land_ElapsedTime_Enable;
      
      //RemainingTime
      WData->Main.RemainingTime.x1 = Data->Land_RemainingTime_x1;
      WData->Main.RemainingTime.y1 = Data->Land_RemainingTime_y1;
      WData->Main.RemainingTime.x2 = Data->Land_RemainingTime_x2;
      WData->Main.RemainingTime.y2 = Data->Land_RemainingTime_y2;
      WData->Main.RemainingTime.Align = Data->Land_RemainingTime_Align;
      WData->Main.RemainingTime.Color = Data->Land_RemainingTime_Color;
      WData->Main.RemainingTime.Font = Data->Land_RemainingTime_Font;
      WData->Main.RemainingTime.Enable = Data->Land_RemainingTime_Enable;
      
      //Extension
      WData->Main.Extension.x1 = Data->Land_Extension_x1;
      WData->Main.Extension.y1 = Data->Land_Extension_y1;
      WData->Main.Extension.x2 = Data->Land_Extension_x2;
      WData->Main.Extension.y2 = Data->Land_Extension_y2;
      WData->Main.Extension.Align = Data->Land_Extension_Align;
      WData->Main.Extension.Color = Data->Land_Extension_Color;
      WData->Main.Extension.Font = Data->Land_Extension_Font;
      WData->Main.Extension.Enable = Data->Land_Extension_Enable;
      
      //BitRate
      WData->Main.BitRate.x1 = Data->Land_BitRate_x1;
      WData->Main.BitRate.y1 = Data->Land_BitRate_y1;
      WData->Main.BitRate.x2 = Data->Land_BitRate_x2;
      WData->Main.BitRate.y2 = Data->Land_BitRate_y2;
      WData->Main.BitRate.Align = Data->Land_BitRate_Align;
      WData->Main.BitRate.Color = Data->Land_BitRate_Color;
      WData->Main.BitRate.Font = Data->Land_BitRate_Font;
      WData->Main.BitRate.Enable = Data->Land_BitRate_Enable;
      
      //TotalTrackID
      WData->Main.TotalTrackID.x1 = Data->Land_TotalTrackID_x1;
      WData->Main.TotalTrackID.y1 = Data->Land_TotalTrackID_y1;
      WData->Main.TotalTrackID.x2 = Data->Land_TotalTrackID_x2;
      WData->Main.TotalTrackID.y2 = Data->Land_TotalTrackID_y2;
      WData->Main.TotalTrackID.Align = Data->Land_TotalTrackID_Align;
      WData->Main.TotalTrackID.Color = Data->Land_TotalTrackID_Color;
      WData->Main.TotalTrackID.Font = Data->Land_TotalTrackID_Font;
      WData->Main.TotalTrackID.Enable = Data->Land_TotalTrackID_Enable;
      
      //C_TrackID
      WData->Main.C_TrackID.x1 = Data->Land_C_TrackID_x1;
      WData->Main.C_TrackID.y1 = Data->Land_C_TrackID_y1;
      WData->Main.C_TrackID.x2 = Data->Land_C_TrackID_x2;
      WData->Main.C_TrackID.y2 = Data->Land_C_TrackID_y2;
      WData->Main.C_TrackID.Align = Data->Land_C_TrackID_Align;
      WData->Main.C_TrackID.Color = Data->Land_C_TrackID_Color;
      WData->Main.C_TrackID.Font = Data->Land_C_TrackID_Font;
      WData->Main.C_TrackID.Enable = Data->Land_C_TrackID_Enable;
      
      //Shuffle_Image
      WData->Main.Shuffle_Image_x1 = Data->Land_Shuffle_Image_x1;
      WData->Main.Shuffle_Image_y1 = Data->Land_Shuffle_Image_y1;
      WData->Main.Shuffle_Image_Enable = Data->Land_Shuffle_Image_Enable;
      
      //Loop_Image
      WData->Main.Loop_Image_x1 = Data->Land_Loop_Image_x1;
      WData->Main.Loop_Image_y1 = Data->Land_Loop_Image_y1;
      WData->Main.Loop_Image_Enable = Data->Land_Loop_Image_Enable;
      
      //EQ_Image
      WData->Main.EQ_Image_Enable = Data->Land_EQ_Image_Enable;
      WData->Main.EQ_Image_x1 = Data->Land_EQ_Image_x1;
      WData->Main.EQ_Image_y1 = Data->Land_EQ_Image_y1;
      
      //PlayerState_Image
      WData->Main.PlayerState_Image_x1 = Data->Land_PlayerState_Image_x1;
      WData->Main.PlayerState_Image_y1 = Data->Land_PlayerState_Image_y1;
      WData->Main.PlayerState_Image_Enable = Data->Land_PlayerState_Image_Enable;
      
      //Title_Image
      WData->Main.Title_Image_x1 = Data->Land_Title_Image_x1;
      WData->Main.Title_Image_y1 = Data->Land_Title_Image_y1;
      WData->Main.Title_Image_Enable = Data->Land_Title_Image_Enable;
      
      //Artist_Image
      WData->Main.Artist_Image_x1 = Data->Land_Artist_Image_x1;
      WData->Main.Artist_Image_y1 = Data->Land_Artist_Image_y1;
      WData->Main.Artist_Image_Enable = Data->Land_Artist_Image_Enable;
      
      //Album_Image
      WData->Main.Album_Image_x1 = Data->Land_Album_Image_x1;
      WData->Main.Album_Image_y1 = Data->Land_Album_Image_y1;
      WData->Main.Album_Image_Enable = Data->Land_Album_Image_Enable;
      
      WData->Main.WhellBG_Image_Enable = Data->Land_WhellBG_Image_Enable;
      WData->Main.WhellBG_Image_x1 = Data->Land_WhellBG_Image_x1;
      WData->Main.WhellBG_Image_y1 = Data->Land_WhellBG_Image_y1;
      
      WData->Main.WhellUP_Image_Enable = Data->Land_WhellUP_Image_Enable;
      WData->Main.WhellUP_Image_x1 = Data->Land_WhellUP_Image_x1;
      WData->Main.WhellUP_Image_y1 = Data->Land_WhellUP_Image_y1;
      
      WData->Main.WhellDOWN_Image_Enable = Data->Land_WhellDOWN_Image_Enable;
      WData->Main.WhellDOWN_Image_x1 = Data->Land_WhellDOWN_Image_x1;
      WData->Main.WhellDOWN_Image_y1 = Data->Land_WhellDOWN_Image_y1;
      
      WData->Main.WhellLEFT_Image_Enable = Data->Land_WhellLEFT_Image_Enable;
      WData->Main.WhellLEFT_Image_x1 = Data->Land_WhellLEFT_Image_x1;
      WData->Main.WhellLEFT_Image_y1 = Data->Land_WhellLEFT_Image_y1;
      
      WData->Main.WhellRIGHT_Image_Enable = Data->Land_WhellRIGHT_Image_Enable;
      WData->Main.WhellRIGHT_Image_x1 = Data->Land_WhellRIGHT_Image_x1;
      WData->Main.WhellRIGHT_Image_y1 = Data->Land_WhellRIGHT_Image_y1;
      
      WData->Main.WhellCENTER_Image_Enable = Data->Land_WhellCENTER_Image_Enable;
      WData->Main.WhellCENTER_Image_x1 = Data->Land_WhellCENTER_Image_x1;
      WData->Main.WhellCENTER_Image_y1 = Data->Land_WhellCENTER_Image_y1; 
      
      WData->Main.Background_Image_Enable = Data->Land_Background_Image_Enable;
      WData->Main.Background_Image_x1 = Data->Land_Background_Image_x1;
      WData->Main.Background_Image_y1 = Data->Land_Background_Image_y1;
      
      WData->Main.Overlay_Image_Enable = Data->Land_Overlay_Image_Enable;
      WData->Main.Overlay_Image_x1 = Data->Land_Overlay_Image_x1;
      WData->Main.Overlay_Image_y1 = Data->Land_Overlay_Image_y1;
      
      //Progress Bar
      WData->Main.ProgressBarEnable = Data->Land_ProgressBarEnable;
      WData->Main.PRect = Data->Land_PRect;
      WData->Main.PBColor = Data->Land_PBColor;
      WData->Main.PFColor = Data->Land_PFColor;
      
	  //VolumeBar
      WData->Main.VolumeBarEnable = Data->Land_VolumeBarEnable;
      WData->Main.VRect = Data->Land_VRect;
      WData->Main.VBColor = Data->Land_VBColor;
      WData->Main.VFColor = Data->Land_VFColor;
      
      //AlbumArt
      WData->Main.AlbumArtEnable = Data->Land_AlbumArtEnable;
      WData->Main.ARect = Data->Land_ARect;
      
      //Visualisation
      WData->Main.VisualisationEnable = Data->Land_VisualisationEnable;
      WData->Main.VIZRect = Data->Land_VIZRect;
      
      WData->FullScreen = Data->FullScreen;
      WData->ShowSoftKey = Data->ShowSoftKey;
      
      fclose (f);
      mfree(Data);
    }
    fclose (Lf);
    mfree(LData);
  }
}
