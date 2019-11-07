#ifndef __WALKMAN_H__
#define __WALKMAN_H__

#include "..\\include\book\MusicApplication_Book.h"

void DrawIcon( IMAGEID img, int x, int y );
void DrawImage( GC* gc, int x, int y, int w, int h, IMAGEID img );
void onfTimer ( u16 unk, void* RLBook );
void WaitingForPlayer( u16 tmr, void* );
void CreateTabGui( BOOK* book, int selected_tab );
void onTimer( u16 unk, void* );
void BeginTimer( u16 unk, void* );
void Enter_WalkmanSkinEditor( BOOK* book, GUI* gui );
void DrawString_Params(int font, TEXTID text, int align, int XPos, int YPos, int width ,int NormalColor);

#define FREE_GUI(gui) if (gui) { gui=GUIObject_Destroy(gui); gui=NULL; };
#define FREE_IMAGE(img) if(img!=NOIMAGE) ImageID_Free(img);
#define TEXT_FREE(text) if( text!=EMPTY_TEXTID ) TextID_Destroy(text);

//#define SKIN_PATH_EXTERNAL   L"/card/other/ZBin/Config/WALKMAN"
#define SKIN_PATH_INTERNAL   L"/usb/other/ZBin/Config/WALKMAN"

typedef enum
{
  PlayerState_Stop = 1,
  PlayerState_Play = 2,
  PlayerState_Pause = 2,
  PlayerState_FastForward =3,
  PlayerState_Rewind = 4
} Player_State_t;

typedef enum
{
  EqPreset_Bass=0,
  EqPreset_Manual,
  EqPreset_Megabass,
  EqPreset_Normal,
  EqPreset_TrebleBoost,
  EqPreset_Voice,
} EqPreset_t;

typedef struct _SKIN
{
  wchar_t SkinDataPath[512];
  wchar_t Path[512];
  wchar_t Name[512];
}SKIN;

typedef struct _SKIN_TXT_DATA
{
  int x1;
  int y1;
  int x2;
  int y2;
  int Align;
  int Color;
  int Font;
  int Enable;
}SKIN_TXT_DATA;

typedef struct _WalkmanSkinEditor_Book : BOOK
{
  GUI_TABMENUBAR *tab;
  GUI_LIST *portrait;
  GUI_LIST *landscape;
  GUI_LIST *WalkmanGUI;
  
  GUI *color;
  GUI *coord;
  GUI *font_select;
  
  GUI *StringEdit;
  GUI_ONEOFMANY *Alignment;
  GUI *IconEdit;
  GUI *SkinChooser;
  GUI *StringInput;
  GUI *ProgressBar;
  
  bool IsBbar;
  bool IsFbar;
  bool IsString;
  bool IsCover;
  
  wchar_t path[256];
  wchar_t name[256]; 
  wchar_t SkinName[100];
  wchar_t AuthorName[100];
  
  wchar_t temp[256];   
  int Orientation;
  char ItemID;
  bool CreateNew;
  bool GuiChanged;
  bool ChangeMade;
  
  wchar_t Title_Str[50];
  wchar_t buffer[50];
  int Str_Align;
  int Str_Enable;
  int Str_Font_Size;
  int Str_Color;
  int Str_Color_2;
  int Str_x1;
  int Str_x2;
  int Str_y1;
  int Str_y2;
  
  //Title
  int Title_x1;
  int Title_y1;
  int Title_x2;
  int Title_y2;
  int Title_Align;
  int Title_Color;
  int Title_Font;
  int Title_Enable;
  
  //Artist
  int Artist_x1;
  int Artist_y1;
  int Artist_x2;
  int Artist_y2;
  int Artist_Align;
  int Artist_Font;
  int Artist_Color;
  int Artist_Enable;
  
  //Album
  int Album_x1;
  int Album_y1;
  int Album_x2;
  int Album_y2;
  int Album_Align;
  int Album_Color;
  int Album_Font;
  int Album_Enable;
  
  //Genre
  int Genre_x1;
  int Genre_y1;
  int Genre_x2;
  int Genre_y2;
  int Genre_Align;
  int Genre_Color;
  int Genre_Font;
  int Genre_Enable;
  
  //TotalTime
  int TotalTime_x1;
  int TotalTime_y1;
  int TotalTime_x2;
  int TotalTime_y2;
  int TotalTime_Align;
  int TotalTime_Color;
  int TotalTime_Font;
  int TotalTime_Enable;
  
  //ElapsedTime
  int ElapsedTime_x1;
  int ElapsedTime_y1;
  int ElapsedTime_x2;
  int ElapsedTime_y2;
  int ElapsedTime_Align;
  int ElapsedTime_Color;
  int ElapsedTime_Font;
  int ElapsedTime_Enable;
  
  //RemainingTime
  int RemainingTime_x1;
  int RemainingTime_y1;
  int RemainingTime_x2;
  int RemainingTime_y2;
  int RemainingTime_Align;
  int RemainingTime_Color;
  int RemainingTime_Font;
  int RemainingTime_Enable;
  
  //Extension
  int Extension_x1;
  int Extension_y1;
  int Extension_x2;
  int Extension_y2;
  int Extension_Align;
  int Extension_Color;
  int Extension_Font;
  int Extension_Enable;
  
  //BitRate
  int BitRate_x1;
  int BitRate_y1;
  int BitRate_x2;
  int BitRate_y2;
  int BitRate_Align;
  int BitRate_Color;
  int BitRate_Font;
  int BitRate_Enable;
  
  //TotalTrackID
  int TotalTrackID_x1;
  int TotalTrackID_y1;
  int TotalTrackID_x2;
  int TotalTrackID_y2;
  int TotalTrackID_Align;
  int TotalTrackID_Color;
  int TotalTrackID_Font;
  int TotalTrackID_Enable;
  
  //C_TrackID
  int C_TrackID_x1;
  int C_TrackID_y1;
  int C_TrackID_x2;
  int C_TrackID_y2;
  int C_TrackID_Align;
  int C_TrackID_Color;
  int C_TrackID_Font;
  int C_TrackID_Enable;
  
  //Shuffle_Image
  int Shuffle_Image_x1;
  int Shuffle_Image_y1;
  int Shuffle_Image_Enable;
  
  //Loop_Image
  int Loop_Image_x1;
  int Loop_Image_y1;
  int Loop_Image_Enable;  
  
  //EQ_Image
  int EQ_Image_x1;
  int EQ_Image_y1;
  int EQ_Image_Enable;
  
  //PlayerState_Image
  int PlayerState_Image_x1;
  int PlayerState_Image_y1;
  int PlayerState_Image_Enable;
  
  //Title_Image
  int Title_Image_x1;
  int Title_Image_y1;
  int Title_Image_Enable;
  
  //Artist_Image
  int Artist_Image_x1;
  int Artist_Image_y1;
  int Artist_Image_Enable;
  
  //Album_Image
  int Album_Image_x1;
  int Album_Image_y1;
  int Album_Image_Enable;
  
  //Whell BG_Image
  int WhellBG_Image_x1;
  int WhellBG_Image_y1;
  int WhellBG_Image_Enable;
  
  //Whell UP_Image
  int WhellUP_Image_x1;
  int WhellUP_Image_y1;
  int WhellUP_Image_Enable;
  
  //Whell DOWN_Image
  int WhellDOWN_Image_x1;
  int WhellDOWN_Image_y1;
  int WhellDOWN_Image_Enable;
  
  //Whell LEFT_Image
  int WhellLEFT_Image_x1;
  int WhellLEFT_Image_y1;
  int WhellLEFT_Image_Enable;
  
  //Whell RIGHT_Image
  int WhellRIGHT_Image_x1;
  int WhellRIGHT_Image_y1;
  int WhellRIGHT_Image_Enable;

  //Whell CENTER_Image
  int WhellCENTER_Image_x1;
  int WhellCENTER_Image_y1;
  int WhellCENTER_Image_Enable;
  
  //Background_Image
  int Background_Image_x1;
  int Background_Image_y1;
  int Background_Image_Enable;
  
  //Overlay_Image
  int Overlay_Image_x1;
  int Overlay_Image_y1;
  int Overlay_Image_Enable;
  
  //Progress Bar
  int ProgressBarEnable;
  RECT PRect;
  int PBColor;
  int PFColor;
  
  //VolumeBar
  int VolumeBarEnable;
  RECT VRect;
  int VBColor;
  int VFColor;
  
  //AlbumArt
  int AlbumArtEnable;
  RECT ARect;
  
  //Visualisation
  int VisualisationEnable;
  RECT VIZRect;
  
  //=========================
  //Title
  int Land_Title_x1;
  int Land_Title_y1;
  int Land_Title_x2;
  int Land_Title_y2;
  int Land_Title_Align;
  int Land_Title_Color;
  int Land_Title_Font;
  int Land_Title_Enable;
  
  //Artist
  int Land_Artist_x1;
  int Land_Artist_y1;
  int Land_Artist_x2;
  int Land_Artist_y2;
  int Land_Artist_Align;
  int Land_Artist_Font;
  int Land_Artist_Color;
  int Land_Artist_Enable;
  
  //Album
  int Land_Album_x1;
  int Land_Album_y1;
  int Land_Album_x2;
  int Land_Album_y2;
  int Land_Album_Align;
  int Land_Album_Color;
  int Land_Album_Font;
  int Land_Album_Enable;
  
  //Genre
  int Land_Genre_x1;
  int Land_Genre_y1;
  int Land_Genre_x2;
  int Land_Genre_y2;
  int Land_Genre_Align;
  int Land_Genre_Color;
  int Land_Genre_Font;
  int Land_Genre_Enable;
  
  //TotalTime
  int Land_TotalTime_x1;
  int Land_TotalTime_y1;
  int Land_TotalTime_x2;
  int Land_TotalTime_y2;
  int Land_TotalTime_Align;
  int Land_TotalTime_Color;
  int Land_TotalTime_Font;
  int Land_TotalTime_Enable;
  
  //ElapsedTime
  int Land_ElapsedTime_x1;
  int Land_ElapsedTime_y1;
  int Land_ElapsedTime_x2;
  int Land_ElapsedTime_y2;
  int Land_ElapsedTime_Align;
  int Land_ElapsedTime_Color;
  int Land_ElapsedTime_Font;
  int Land_ElapsedTime_Enable;
  
  //RemainingTime
  int Land_RemainingTime_x1;
  int Land_RemainingTime_y1;
  int Land_RemainingTime_x2;
  int Land_RemainingTime_y2;
  int Land_RemainingTime_Align;
  int Land_RemainingTime_Color;
  int Land_RemainingTime_Font;
  int Land_RemainingTime_Enable;
  
  //Extension
  int Land_Extension_x1;
  int Land_Extension_y1;
  int Land_Extension_x2;
  int Land_Extension_y2;
  int Land_Extension_Align;
  int Land_Extension_Color;
  int Land_Extension_Font;
  int Land_Extension_Enable;
  
  //BitRate
  int Land_BitRate_x1;
  int Land_BitRate_y1;
  int Land_BitRate_x2;
  int Land_BitRate_y2;
  int Land_BitRate_Align;
  int Land_BitRate_Color;
  int Land_BitRate_Font;
  int Land_BitRate_Enable;
  
  //TotalTrackID
  int Land_TotalTrackID_x1;
  int Land_TotalTrackID_y1;
  int Land_TotalTrackID_x2;
  int Land_TotalTrackID_y2;
  int Land_TotalTrackID_Align;
  int Land_TotalTrackID_Color;
  int Land_TotalTrackID_Font;
  int Land_TotalTrackID_Enable;
  
  //C_TrackID
  int Land_C_TrackID_x1;
  int Land_C_TrackID_y1;
  int Land_C_TrackID_x2;
  int Land_C_TrackID_y2;
  int Land_C_TrackID_Align;
  int Land_C_TrackID_Color;
  int Land_C_TrackID_Font;
  int Land_C_TrackID_Enable;
  
  //Shuffle_Image
  int Land_Shuffle_Image_x1;
  int Land_Shuffle_Image_y1;
  int Land_Shuffle_Image_Enable;
  
  //Loop_Image
  int Land_Loop_Image_x1;
  int Land_Loop_Image_y1;
  int Land_Loop_Image_Enable;
  
  //EQ_Image
  int Land_EQ_Image_x1;
  int Land_EQ_Image_y1;
  int Land_EQ_Image_Enable;
  
  //PlayerState_Image
  int Land_PlayerState_Image_x1;
  int Land_PlayerState_Image_y1;
  int Land_PlayerState_Image_Enable;
  
  //Title_Image
  int Land_Title_Image_x1;
  int Land_Title_Image_y1;
  int Land_Title_Image_Enable;
  
  //Artist_Image
  int Land_Artist_Image_x1;
  int Land_Artist_Image_y1;
  int Land_Artist_Image_Enable;
  
  //Album_Image
  int Land_Album_Image_x1;
  int Land_Album_Image_y1;
  int Land_Album_Image_Enable;
  
  //Whell BG_Image
  int Land_WhellBG_Image_x1;
  int Land_WhellBG_Image_y1;
  int Land_WhellBG_Image_Enable;
  
  //Whell UP_Image
  int Land_WhellUP_Image_x1;
  int Land_WhellUP_Image_y1;
  int Land_WhellUP_Image_Enable;
  
  //Whell DOWN_Image
  int Land_WhellDOWN_Image_x1;
  int Land_WhellDOWN_Image_y1;
  int Land_WhellDOWN_Image_Enable;
  
  //Whell LEFT_Image
  int Land_WhellLEFT_Image_x1;
  int Land_WhellLEFT_Image_y1;
  int Land_WhellLEFT_Image_Enable;
  
  //Whell RIGHT_Image
  int Land_WhellRIGHT_Image_x1;
  int Land_WhellRIGHT_Image_y1;
  int Land_WhellRIGHT_Image_Enable;

  //Whell CENTER_Image
  int Land_WhellCENTER_Image_x1;
  int Land_WhellCENTER_Image_y1;
  int Land_WhellCENTER_Image_Enable;
  
  //Background_Image
  int Land_Background_Image_x1;
  int Land_Background_Image_y1;
  int Land_Background_Image_Enable;
  
  //Overlay_Image
  int Land_Overlay_Image_x1;
  int Land_Overlay_Image_y1;
  int Land_Overlay_Image_Enable;
  
  //Progress Bar
  int Land_ProgressBarEnable;
  RECT Land_PRect;
  int Land_PBColor;
  int Land_PFColor;
  
  //VolumeBar
  int Land_VolumeBarEnable;
  RECT Land_VRect;
  int Land_VBColor;
  int Land_VFColor;
  
  //AlbumArt
  int Land_AlbumArtEnable;
  RECT Land_ARect;
  
  //Visualisation
  int Land_VisualisationEnable;
  RECT Land_VIZRect;
  
  bool FullScreen;
  bool ShowSoftKey;
}WalkmanSkinEditor_Book;

typedef struct TEXT_ITEM_DATA
{
  int x1;
  int y1;
  int x2;
  int y2;
  int Align;
  color_t Color;
  int Font;
  BOOL Enable;
  TEXTID TextID;
} TEXT_ITEM_DATA;

typedef struct IMG_ITEM_DATA
{
  bool state;
  POINT pos;
} IMG_ITEM_DATA;

typedef struct PROGRESS_ITEM_DATA
{
  bool state;
  bool slider;
  bool round;
  color_t progress_bcolor;
  color_t progress_fcolor;
  RECT progress_rect;
} PROGRESS_ITEM_DATA;

typedef struct _WalkmanDrawData
{
  TEXT_ITEM_DATA Title;
  TEXT_ITEM_DATA Artist;
  TEXT_ITEM_DATA Album;
  TEXT_ITEM_DATA Genre;
  
  TEXT_ITEM_DATA TotalTime;
  TEXT_ITEM_DATA ElapsedTime;
  TEXT_ITEM_DATA RemainingTime;
  
  TEXT_ITEM_DATA Extension;
  TEXT_ITEM_DATA BitRate;
  TEXT_ITEM_DATA TotalTrackID;
  TEXT_ITEM_DATA C_TrackID;
  
  //Shuffle_Image
  int Shuffle_Image_x1;
  int Shuffle_Image_y1;
  int Shuffle_Image_Enable;
  
  //Loop_Image
  int Loop_Image_x1;
  int Loop_Image_y1;
  int Loop_Image_Enable;  
  //EQ_Image
  int EQ_Image_x1;
  int EQ_Image_y1;
  int EQ_Image_Enable;
  
  //PlayerState_Image
  int PlayerState_Image_x1;
  int PlayerState_Image_y1;
  int PlayerState_Image_Enable;
  
  //Title_Image
  int Title_Image_x1;
  int Title_Image_y1;
  int Title_Image_Enable;
  
  //Artist_Image
  int Artist_Image_x1;
  int Artist_Image_y1;
  int Artist_Image_Enable;
  
  //Album_Image
  int Album_Image_x1;
  int Album_Image_y1;
  int Album_Image_Enable;
  
  //Whell BG_Image
  int WhellBG_Image_x1;
  int WhellBG_Image_y1;
  int WhellBG_Image_Enable;
  
  //Whell UP_Image
  int WhellUP_Image_x1;
  int WhellUP_Image_y1;
  int WhellUP_Image_Enable;
  
  //Whell DOWN_Image
  int WhellDOWN_Image_x1;
  int WhellDOWN_Image_y1;
  int WhellDOWN_Image_Enable;
  
  //Whell LEFT_Image
  int WhellLEFT_Image_x1;
  int WhellLEFT_Image_y1;
  int WhellLEFT_Image_Enable;
  
  //Whell RIGHT_Image
  int WhellRIGHT_Image_x1;
  int WhellRIGHT_Image_y1;
  int WhellRIGHT_Image_Enable;
 
  //Whell CENTER_Image
  int WhellCENTER_Image_x1;
  int WhellCENTER_Image_y1;
  int WhellCENTER_Image_Enable;
  
  //Background_Image
  int Background_Image_x1;
  int Background_Image_y1;
  int Background_Image_Enable;
  
  //Overlay_Image
  int Overlay_Image_x1;
  int Overlay_Image_y1;
  int Overlay_Image_Enable;
  
  //Progress Bar
  int ProgressBarEnable;
  RECT PRect;
  int PBColor;
  int PFColor;
  
  //VolumeBar
  int VolumeBarEnable;
  RECT VRect;
  int VBColor;
  int VFColor;
  
  //AlbumArt
  int AlbumArtEnable;
  RECT ARect;
  
  //Visualisation
  int VisualisationEnable;
  RECT VIZRect;
}WalkmanDrawData;

typedef struct _IMG
{
  IMAGEID ImageID;
  u16 ImageHandle;
}IMG;

typedef struct _SkinData
{
  wchar_t Author[100];
  //Title
  int Title_x1;
  int Title_y1;
  int Title_x2;
  int Title_y2;
  int Title_Align;
  int Title_Color;
  int Title_Font;
  int Title_Enable;
  
  //Artist
  int Artist_x1;
  int Artist_y1;
  int Artist_x2;
  int Artist_y2;
  int Artist_Align;
  int Artist_Font;
  int Artist_Color;
  int Artist_Enable;
  
  //Album
  int Album_x1;
  int Album_y1;
  int Album_x2;
  int Album_y2;
  int Album_Align;
  int Album_Color;
  int Album_Font;
  int Album_Enable;
  
  //Genre
  int Genre_x1;
  int Genre_y1;
  int Genre_x2;
  int Genre_y2;
  int Genre_Align;
  int Genre_Color;
  int Genre_Font;
  int Genre_Enable;
  
  //TotalTime
  int TotalTime_x1;
  int TotalTime_y1;
  int TotalTime_x2;
  int TotalTime_y2;
  int TotalTime_Align;
  int TotalTime_Color;
  int TotalTime_Font;
  int TotalTime_Enable;
  
  //ElapsedTime
  int ElapsedTime_x1;
  int ElapsedTime_y1;
  int ElapsedTime_x2;
  int ElapsedTime_y2;
  int ElapsedTime_Align;
  int ElapsedTime_Color;
  int ElapsedTime_Font;
  int ElapsedTime_Enable;
  
  //RemainingTime
  int RemainingTime_x1;
  int RemainingTime_y1;
  int RemainingTime_x2;
  int RemainingTime_y2;
  int RemainingTime_Align;
  int RemainingTime_Color;
  int RemainingTime_Font;
  int RemainingTime_Enable;
  
  //Extension
  int Extension_x1;
  int Extension_y1;
  int Extension_x2;
  int Extension_y2;
  int Extension_Align;
  int Extension_Color;
  int Extension_Font;
  int Extension_Enable;
  
  //BitRate
  int BitRate_x1;
  int BitRate_y1;
  int BitRate_x2;
  int BitRate_y2;
  int BitRate_Align;
  int BitRate_Color;
  int BitRate_Font;
  int BitRate_Enable;
  
  //TotalTrackID
  int TotalTrackID_x1;
  int TotalTrackID_y1;
  int TotalTrackID_x2;
  int TotalTrackID_y2;
  int TotalTrackID_Align;
  int TotalTrackID_Color;
  int TotalTrackID_Font;
  int TotalTrackID_Enable;
  
  //C_TrackID
  int C_TrackID_x1;
  int C_TrackID_y1;
  int C_TrackID_x2;
  int C_TrackID_y2;
  int C_TrackID_Align;
  int C_TrackID_Color;
  int C_TrackID_Font;
  int C_TrackID_Enable;
  
  //Shuffle_Image
  int Shuffle_Image_x1;
  int Shuffle_Image_y1;
  int Shuffle_Image_Enable;
  
  //Loop_Image
  int Loop_Image_x1;
  int Loop_Image_y1;
  int Loop_Image_Enable;  
  
  //EQ_Image
  int EQ_Image_x1;
  int EQ_Image_y1;
  int EQ_Image_Enable;
  
  //PlayerState_Image
  int PlayerState_Image_x1;
  int PlayerState_Image_y1;
  int PlayerState_Image_Enable;
  
  //Title_Image
  int Title_Image_x1;
  int Title_Image_y1;
  int Title_Image_Enable;
  
  //Artist_Image
  int Artist_Image_x1;
  int Artist_Image_y1;
  int Artist_Image_Enable;
  
  //Album_Image
  int Album_Image_x1;
  int Album_Image_y1;
  int Album_Image_Enable;
  
  //Whell BG_Image
  int WhellBG_Image_x1;
  int WhellBG_Image_y1;
  int WhellBG_Image_Enable;
  
  //Whell UP_Image
  int WhellUP_Image_x1;
  int WhellUP_Image_y1;
  int WhellUP_Image_Enable;
  
  //Whell DOWN_Image
  int WhellDOWN_Image_x1;
  int WhellDOWN_Image_y1;
  int WhellDOWN_Image_Enable;
  
  //Whell LEFT_Image
  int WhellLEFT_Image_x1;
  int WhellLEFT_Image_y1;
  int WhellLEFT_Image_Enable;
  
  //Whell RIGHT_Image
  int WhellRIGHT_Image_x1;
  int WhellRIGHT_Image_y1;
  int WhellRIGHT_Image_Enable;

  //Whell CENTER_Image
  int WhellCENTER_Image_x1;
  int WhellCENTER_Image_y1;
  int WhellCENTER_Image_Enable;
  
  //Background_Image
  int Background_Image_x1;
  int Background_Image_y1;
  int Background_Image_Enable;
  
  //Overlay_Image
  int Overlay_Image_x1;
  int Overlay_Image_y1;
  int Overlay_Image_Enable;
  
  //Progress Bar
  int ProgressBarEnable;
  RECT PRect;
  int PBColor;
  int PFColor;
  
  //VolumeBar
  int VolumeBarEnable;
  RECT VRect;
  int VBColor;
  int VFColor;
  
  //AlbumArt
  int AlbumArtEnable;
  RECT ARect;
  
  //Visualisation
  int VisualisationEnable;
  RECT VIZRect;
  
  //=========================
  //Title
  int Land_Title_x1;
  int Land_Title_y1;
  int Land_Title_x2;
  int Land_Title_y2;
  int Land_Title_Align;
  int Land_Title_Color;
  int Land_Title_Font;
  int Land_Title_Enable;
  
  //Artist
  int Land_Artist_x1;
  int Land_Artist_y1;
  int Land_Artist_x2;
  int Land_Artist_y2;
  int Land_Artist_Align;
  int Land_Artist_Font;
  int Land_Artist_Color;
  int Land_Artist_Enable;
  
  //Album
  int Land_Album_x1;
  int Land_Album_y1;
  int Land_Album_x2;
  int Land_Album_y2;
  int Land_Album_Align;
  int Land_Album_Color;
  int Land_Album_Font;
  int Land_Album_Enable;
  
  //Genre
  int Land_Genre_x1;
  int Land_Genre_y1;
  int Land_Genre_x2;
  int Land_Genre_y2;
  int Land_Genre_Align;
  int Land_Genre_Color;
  int Land_Genre_Font;
  int Land_Genre_Enable;
  
  //TotalTime
  int Land_TotalTime_x1;
  int Land_TotalTime_y1;
  int Land_TotalTime_x2;
  int Land_TotalTime_y2;
  int Land_TotalTime_Align;
  int Land_TotalTime_Color;
  int Land_TotalTime_Font;
  int Land_TotalTime_Enable;
  
  //ElapsedTime
  int Land_ElapsedTime_x1;
  int Land_ElapsedTime_y1;
  int Land_ElapsedTime_x2;
  int Land_ElapsedTime_y2;
  int Land_ElapsedTime_Align;
  int Land_ElapsedTime_Color;
  int Land_ElapsedTime_Font;
  int Land_ElapsedTime_Enable;
  
  //RemainingTime
  int Land_RemainingTime_x1;
  int Land_RemainingTime_y1;
  int Land_RemainingTime_x2;
  int Land_RemainingTime_y2;
  int Land_RemainingTime_Align;
  int Land_RemainingTime_Color;
  int Land_RemainingTime_Font;
  int Land_RemainingTime_Enable;
  
  //Extension
  int Land_Extension_x1;
  int Land_Extension_y1;
  int Land_Extension_x2;
  int Land_Extension_y2;
  int Land_Extension_Align;
  int Land_Extension_Color;
  int Land_Extension_Font;
  int Land_Extension_Enable;
  
  //BitRate
  int Land_BitRate_x1;
  int Land_BitRate_y1;
  int Land_BitRate_x2;
  int Land_BitRate_y2;
  int Land_BitRate_Align;
  int Land_BitRate_Color;
  int Land_BitRate_Font;
  int Land_BitRate_Enable;
  
  //TotalTrackID
  int Land_TotalTrackID_x1;
  int Land_TotalTrackID_y1;
  int Land_TotalTrackID_x2;
  int Land_TotalTrackID_y2;
  int Land_TotalTrackID_Align;
  int Land_TotalTrackID_Color;
  int Land_TotalTrackID_Font;
  int Land_TotalTrackID_Enable;
  
  //C_TrackID
  int Land_C_TrackID_x1;
  int Land_C_TrackID_y1;
  int Land_C_TrackID_x2;
  int Land_C_TrackID_y2;
  int Land_C_TrackID_Align;
  int Land_C_TrackID_Color;
  int Land_C_TrackID_Font;
  int Land_C_TrackID_Enable;
  
  //Shuffle_Image
  int Land_Shuffle_Image_x1;
  int Land_Shuffle_Image_y1;
  int Land_Shuffle_Image_Enable;
  
  //Loop_Image
  int Land_Loop_Image_x1;
  int Land_Loop_Image_y1;
  int Land_Loop_Image_Enable;
  
  //EQ_Image
  int Land_EQ_Image_x1;
  int Land_EQ_Image_y1;
  int Land_EQ_Image_Enable;
  
  //PlayerState_Image
  int Land_PlayerState_Image_x1;
  int Land_PlayerState_Image_y1;
  int Land_PlayerState_Image_Enable;
  
  //Title_Image
  int Land_Title_Image_x1;
  int Land_Title_Image_y1;
  int Land_Title_Image_Enable;
  
  //Artist_Image
  int Land_Artist_Image_x1;
  int Land_Artist_Image_y1;
  int Land_Artist_Image_Enable;
  
  //Album_Image
  int Land_Album_Image_x1;
  int Land_Album_Image_y1;
  int Land_Album_Image_Enable;
  
  //Whell BG_Image
  int Land_WhellBG_Image_x1;
  int Land_WhellBG_Image_y1;
  int Land_WhellBG_Image_Enable;
  
  //Whell UP_Image
  int Land_WhellUP_Image_x1;
  int Land_WhellUP_Image_y1;
  int Land_WhellUP_Image_Enable;
  
  //Whell DOWN_Image
  int Land_WhellDOWN_Image_x1;
  int Land_WhellDOWN_Image_y1;
  int Land_WhellDOWN_Image_Enable;
  
  //Whell LEFT_Image
  int Land_WhellLEFT_Image_x1;
  int Land_WhellLEFT_Image_y1;
  int Land_WhellLEFT_Image_Enable;
  
  //Whell RIGHT_Image
  int Land_WhellRIGHT_Image_x1;
  int Land_WhellRIGHT_Image_y1;
  int Land_WhellRIGHT_Image_Enable;

  //Whell CENTER_Image
  int Land_WhellCENTER_Image_x1;
  int Land_WhellCENTER_Image_y1;
  int Land_WhellCENTER_Image_Enable;
  
  //Background_Image
  int Land_Background_Image_x1;
  int Land_Background_Image_y1;
  int Land_Background_Image_Enable;
  
  //Overlay_Image
  int Land_Overlay_Image_x1;
  int Land_Overlay_Image_y1;
  int Land_Overlay_Image_Enable;
  
  //Progress Bar
  int Land_ProgressBarEnable;
  RECT Land_PRect;
  int Land_PBColor;
  int Land_PFColor;
  
  //VolumeBar
  int Land_VolumeBarEnable;
  RECT Land_VRect;
  int Land_VBColor;
  int Land_VFColor;
  
  //AlbumArt
  int Land_AlbumArtEnable;
  RECT Land_ARect;
  
  //Visualisation
  int Land_VisualisationEnable;
  RECT Land_VIZRect;
  
  bool FullScreen;
  bool ShowSoftKey;
}SkinData;

typedef struct _VizFileData
{
  int ID;
}VizFileData;

typedef struct _WALKMAN_Function
{
  MusicApplication_Book* MusicBook;
  DISP_OBJ* Music_Gui_NowPlaying;
  
  bool Portrait;
  //bool IsAlbumArt;
  bool IsShuffle;
  bool IsLoop;
  bool IsPlaying;
  char EqPreset;
  char PlayState;
  
  bool FullScreen;
  bool ShowSoftKey;
  
  char VizID;
  bool IsPlayingTimerData;
  
  wchar_t buffer[256];
  wchar_t tempFullPath[256];
  wchar_t fullpath[256];
  //wchar_t artist[256];
  //wchar_t album[256];
  //wchar_t title[256];
  wchar_t genre[256];
  wchar_t ext[3];
  
  //int TempTimeData;
  int FullTime;
  //int FullTimeSeconds;
  //int FullTimeMinutes;
  int ElapsedTime;
  //int ElapsedTimeSeconds;
  //int ElapsedTimeMinutes;
  
  u16 timer;
  u16 WaitingTimer;
  int UpdateTime;
  
  IMG ImageID[35];
  wchar_t* ImageDataName[35];
  IMAGEID VizIMG_ID;
  wchar_t VizName[12];
  
  wchar_t SkinPath[512];
  wchar_t* SkinItemName[15];
  IMG SkinItemImageID[15];
  
  //int Offset;
  //int Size;
  //char pImageType;
  //bool IsDRMProtected;
  //TMusicServer_Time Playlength;
  //TMusicServer_Time ResumePosition;
  bool ContainsAlbumart;
  //bool IsRealMediaFile;
  IMAGEID CoverArtID;
  
  //u16 CurrentTrackNumber;
  //u16 TotalTrackNumber;

  int VolumeLevel;
  int Bitrate;
  
  int blob_w;
  int blob_h;
  
  IMAGEID VizImageID;
  //IMG VizImage;
  GVI_GC m_smilgc;// = NULL;
  GVI_BRUSH m_br;
  GC* gc;
  GC* m_hMGC;
  int kl;//=0;
  int gcmem_xsize;//=0;

  SkinData VizData;
  WalkmanDrawData Main;
}WALKMAN_Function;

#define EMP_NAME "WALKMAN_Function"

__thumb void* malloc( int size );
__thumb void mfree( void* mem );

WALKMAN_Function* Create_WALKMAN_Function();
WALKMAN_Function* Get_WALKMAN_Function();

void YesNoConfigSkin( BOOK * book );
void Close_SkinChooser( BOOK* book, GUI* gui );
int SkinChooser_callback( GUI_MESSAGE* msg );
void onEnter_SkinChooser( BOOK* book, GUI* gui );
int CreateSkinChooser( BOOK* book );
void YesNoSaveSkinData( BOOK* book );

void DrawProgressBar( WALKMAN_Function* Data, int value, int max_value, RECT rect, int Bcolor, int Ecolor );
void FreeViz( WALKMAN_Function* Data );
void BootViz( WALKMAN_Function* Data );
void KillAllTimer( WALKMAN_Function* Data );
void RegisterImage( IMG* img , wchar_t* path, wchar_t* fname );

void FreeImage(WALKMAN_Function* Data);
void LoadImage(WALKMAN_Function* Data);

void SetGUIData(GUI* gui);

#define INDEX(x) x/8
#define SHIFT(x) x%8
#define GETBIT(v,x) ((v[INDEX(x)] << SHIFT(x)) & 0x80)>>7

#endif
