#ifndef _MAIN_H_
#define _MAIN_H_

#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#define MEM_NAME "WSK_MEM"
#define EMP_NAME "WSK_EMP"

#define DESTROY_GUI(gui)             \
  if (gui)                           \
  {                                  \
    GUI *g = GUIObject_Destroy(gui); \
    gui = g;                         \
  };

#define DESTROY_TEXTID(text) \
  if (text != EMPTY_TEXTID)  \
    TextID_Destroy(text);

#define FREE_IMAGE(img) \
  if (img != NOIMAGE)   \
    ImageID_Free(img);

enum MusicPlayer_Image
{
  MP_BG_LD,
  MP_BG_PT,
  NO_COVER_ICN,
  OVERLAY_IMAGE_P,
  THUMB,
  MP_EQ_STATUS_ICON,
  MP_MODE_LOOP_ICN,
  MP_MODE_RANDOM_ICN,
  MP_PAUSE_ICN,
  MP_PLAY_ICN,
  MP_REWIND_ICN,
  MP_FAST_FORWARD_ICN,
  MP_ALBUM_ICN,
  MP_ARTIST_ICN,
  MP_TRACK_ICN,
  MC_WHEEL_BACKGROUND_ICN,
  MC_WHEEL_DOWN_ICN,
  MC_WHEEL_FF_ICN,
  MC_WHEEL_NEXT_ICN,
  MC_WHEEL_PAUSE_ICN,
  MC_WHEEL_PLAY_ICN,
  MC_WHEEL_PREV_ICN,
  MC_WHEEL_REW_ICN,
  MC_WHEEL_UP_ICN,
  OVERLAY_IMAGE_L,
  REFLECT,
  MP_EQ_BASS_ICON,
  MP_EQ_MANUAL_ICON,
  MP_EQ_MEGABASS_ICON,
  MP_EQ_NORMAL_ICON,
  MP_EQ_TREBLEBOOST_ICON,
  MP_EQ_VOICE_ICON,
  PROGRESSBAR_OVERLAY,
  PROGRESSBAR_OVERLAY_LANDSCAPE,
  MP_MODE_REPEAT_ONE_ICN,
  LastImage
};

typedef struct IMG
{
  IMAGEID ImageID;
  u16 ImageHandle;
} IMG;

typedef struct TEXT_ITEM_DATA
{
  int x1;
  int y1;
  int x2;
  int y2;
  int Align;
  unsigned int Color;
  int Font;
  BOOL Enable;
  TEXTID TextID;
} TEXT_ITEM_DATA;

typedef struct IMG_ITEM_DATA
{
  int x;
  int y;
  BOOL Enable;
} IMG_ITEM_DATA;

typedef struct PROGRESS_ITEM_DATA
{
  BOOL Enable;
  RECT Rect;
  unsigned int BColor;
  unsigned int FColor;
} PROGRESS_ITEM_DATA;

typedef struct _SkinDrawData
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

  IMG_ITEM_DATA Shuffle_Image;
  IMG_ITEM_DATA Loop_Image;
  IMG_ITEM_DATA EQ_Image;
  IMG_ITEM_DATA PlayerState_Image;
  IMG_ITEM_DATA Title_Image;
  IMG_ITEM_DATA Artist_Image;
  IMG_ITEM_DATA Album_Image;
  IMG_ITEM_DATA WhellBG_Image;
  IMG_ITEM_DATA WhellUP_Image;
  IMG_ITEM_DATA WhellDOWN_Image;
  IMG_ITEM_DATA WhellLEFT_Image;
  IMG_ITEM_DATA WhellRIGHT_Image;
  IMG_ITEM_DATA WhellCENTER_Image;
  IMG_ITEM_DATA Background_Image;
  IMG_ITEM_DATA Overlay_Image;

  PROGRESS_ITEM_DATA ProgressBar;
  PROGRESS_ITEM_DATA VolumeBar;

  // AlbumArt
  int AlbumArtEnable;
  RECT ARect;

  // Visualisation
  int VisualisationEnable;
  RECT VIZRect;
} SkinDrawData;

typedef struct _SkinData
{
  wchar_t Author[100];
  // Title
  int Title_x1;
  int Title_y1;
  int Title_x2;
  int Title_y2;
  int Title_Align;
  int Title_Color;
  int Title_Font;
  int Title_Enable;

  // Artist
  int Artist_x1;
  int Artist_y1;
  int Artist_x2;
  int Artist_y2;
  int Artist_Align;
  int Artist_Font;
  int Artist_Color;
  int Artist_Enable;

  // Album
  int Album_x1;
  int Album_y1;
  int Album_x2;
  int Album_y2;
  int Album_Align;
  int Album_Color;
  int Album_Font;
  int Album_Enable;

  // Genre
  int Genre_x1;
  int Genre_y1;
  int Genre_x2;
  int Genre_y2;
  int Genre_Align;
  int Genre_Color;
  int Genre_Font;
  int Genre_Enable;

  // TotalTime
  int TotalTime_x1;
  int TotalTime_y1;
  int TotalTime_x2;
  int TotalTime_y2;
  int TotalTime_Align;
  int TotalTime_Color;
  int TotalTime_Font;
  int TotalTime_Enable;

  // ElapsedTime
  int ElapsedTime_x1;
  int ElapsedTime_y1;
  int ElapsedTime_x2;
  int ElapsedTime_y2;
  int ElapsedTime_Align;
  int ElapsedTime_Color;
  int ElapsedTime_Font;
  int ElapsedTime_Enable;

  // RemainingTime
  int RemainingTime_x1;
  int RemainingTime_y1;
  int RemainingTime_x2;
  int RemainingTime_y2;
  int RemainingTime_Align;
  int RemainingTime_Color;
  int RemainingTime_Font;
  int RemainingTime_Enable;

  // Extension
  int Extension_x1;
  int Extension_y1;
  int Extension_x2;
  int Extension_y2;
  int Extension_Align;
  int Extension_Color;
  int Extension_Font;
  int Extension_Enable;

  // BitRate
  int BitRate_x1;
  int BitRate_y1;
  int BitRate_x2;
  int BitRate_y2;
  int BitRate_Align;
  int BitRate_Color;
  int BitRate_Font;
  int BitRate_Enable;

  // TotalTrackID
  int TotalTrackID_x1;
  int TotalTrackID_y1;
  int TotalTrackID_x2;
  int TotalTrackID_y2;
  int TotalTrackID_Align;
  int TotalTrackID_Color;
  int TotalTrackID_Font;
  int TotalTrackID_Enable;

  // C_TrackID
  int C_TrackID_x1;
  int C_TrackID_y1;
  int C_TrackID_x2;
  int C_TrackID_y2;
  int C_TrackID_Align;
  int C_TrackID_Color;
  int C_TrackID_Font;
  int C_TrackID_Enable;

  // Shuffle_Image
  int Shuffle_Image_x1;
  int Shuffle_Image_y1;
  int Shuffle_Image_Enable;

  // Loop_Image
  int Loop_Image_x1;
  int Loop_Image_y1;
  int Loop_Image_Enable;

  // EQ_Image
  int EQ_Image_x1;
  int EQ_Image_y1;
  int EQ_Image_Enable;

  // PlayerState_Image
  int PlayerState_Image_x1;
  int PlayerState_Image_y1;
  int PlayerState_Image_Enable;

  // Title_Image
  int Title_Image_x1;
  int Title_Image_y1;
  int Title_Image_Enable;

  // Artist_Image
  int Artist_Image_x1;
  int Artist_Image_y1;
  int Artist_Image_Enable;

  // Album_Image
  int Album_Image_x1;
  int Album_Image_y1;
  int Album_Image_Enable;

  // Whell BG_Image
  int WhellBG_Image_x1;
  int WhellBG_Image_y1;
  int WhellBG_Image_Enable;

  // Whell UP_Image
  int WhellUP_Image_x1;
  int WhellUP_Image_y1;
  int WhellUP_Image_Enable;

  // Whell DOWN_Image
  int WhellDOWN_Image_x1;
  int WhellDOWN_Image_y1;
  int WhellDOWN_Image_Enable;

  // Whell LEFT_Image
  int WhellLEFT_Image_x1;
  int WhellLEFT_Image_y1;
  int WhellLEFT_Image_Enable;

  // Whell RIGHT_Image
  int WhellRIGHT_Image_x1;
  int WhellRIGHT_Image_y1;
  int WhellRIGHT_Image_Enable;

  // Whell CENTER_Image
  int WhellCENTER_Image_x1;
  int WhellCENTER_Image_y1;
  int WhellCENTER_Image_Enable;

  // Background_Image
  int Background_Image_x1;
  int Background_Image_y1;
  int Background_Image_Enable;

  // Overlay_Image
  int Overlay_Image_x1;
  int Overlay_Image_y1;
  int Overlay_Image_Enable;

  // Progress Bar
  int ProgressBarEnable;
  RECT PRect;
  int PBColor;
  int PFColor;

  // VolumeBar
  int VolumeBarEnable;
  RECT VRect;
  int VBColor;
  int VFColor;

  // AlbumArt
  int AlbumArtEnable;
  RECT ARect;

  // Visualisation
  int VisualisationEnable;
  RECT VIZRect;

  //=========================
  // Title
  int Land_Title_x1;
  int Land_Title_y1;
  int Land_Title_x2;
  int Land_Title_y2;
  int Land_Title_Align;
  int Land_Title_Color;
  int Land_Title_Font;
  int Land_Title_Enable;

  // Artist
  int Land_Artist_x1;
  int Land_Artist_y1;
  int Land_Artist_x2;
  int Land_Artist_y2;
  int Land_Artist_Align;
  int Land_Artist_Font;
  int Land_Artist_Color;
  int Land_Artist_Enable;

  // Album
  int Land_Album_x1;
  int Land_Album_y1;
  int Land_Album_x2;
  int Land_Album_y2;
  int Land_Album_Align;
  int Land_Album_Color;
  int Land_Album_Font;
  int Land_Album_Enable;

  // Genre
  int Land_Genre_x1;
  int Land_Genre_y1;
  int Land_Genre_x2;
  int Land_Genre_y2;
  int Land_Genre_Align;
  int Land_Genre_Color;
  int Land_Genre_Font;
  int Land_Genre_Enable;

  // TotalTime
  int Land_TotalTime_x1;
  int Land_TotalTime_y1;
  int Land_TotalTime_x2;
  int Land_TotalTime_y2;
  int Land_TotalTime_Align;
  int Land_TotalTime_Color;
  int Land_TotalTime_Font;
  int Land_TotalTime_Enable;

  // ElapsedTime
  int Land_ElapsedTime_x1;
  int Land_ElapsedTime_y1;
  int Land_ElapsedTime_x2;
  int Land_ElapsedTime_y2;
  int Land_ElapsedTime_Align;
  int Land_ElapsedTime_Color;
  int Land_ElapsedTime_Font;
  int Land_ElapsedTime_Enable;

  // RemainingTime
  int Land_RemainingTime_x1;
  int Land_RemainingTime_y1;
  int Land_RemainingTime_x2;
  int Land_RemainingTime_y2;
  int Land_RemainingTime_Align;
  int Land_RemainingTime_Color;
  int Land_RemainingTime_Font;
  int Land_RemainingTime_Enable;

  // Extension
  int Land_Extension_x1;
  int Land_Extension_y1;
  int Land_Extension_x2;
  int Land_Extension_y2;
  int Land_Extension_Align;
  int Land_Extension_Color;
  int Land_Extension_Font;
  int Land_Extension_Enable;

  // BitRate
  int Land_BitRate_x1;
  int Land_BitRate_y1;
  int Land_BitRate_x2;
  int Land_BitRate_y2;
  int Land_BitRate_Align;
  int Land_BitRate_Color;
  int Land_BitRate_Font;
  int Land_BitRate_Enable;

  // TotalTrackID
  int Land_TotalTrackID_x1;
  int Land_TotalTrackID_y1;
  int Land_TotalTrackID_x2;
  int Land_TotalTrackID_y2;
  int Land_TotalTrackID_Align;
  int Land_TotalTrackID_Color;
  int Land_TotalTrackID_Font;
  int Land_TotalTrackID_Enable;

  // C_TrackID
  int Land_C_TrackID_x1;
  int Land_C_TrackID_y1;
  int Land_C_TrackID_x2;
  int Land_C_TrackID_y2;
  int Land_C_TrackID_Align;
  int Land_C_TrackID_Color;
  int Land_C_TrackID_Font;
  int Land_C_TrackID_Enable;

  // Shuffle_Image
  int Land_Shuffle_Image_x1;
  int Land_Shuffle_Image_y1;
  int Land_Shuffle_Image_Enable;

  // Loop_Image
  int Land_Loop_Image_x1;
  int Land_Loop_Image_y1;
  int Land_Loop_Image_Enable;

  // EQ_Image
  int Land_EQ_Image_x1;
  int Land_EQ_Image_y1;
  int Land_EQ_Image_Enable;

  // PlayerState_Image
  int Land_PlayerState_Image_x1;
  int Land_PlayerState_Image_y1;
  int Land_PlayerState_Image_Enable;

  // Title_Image
  int Land_Title_Image_x1;
  int Land_Title_Image_y1;
  int Land_Title_Image_Enable;

  // Artist_Image
  int Land_Artist_Image_x1;
  int Land_Artist_Image_y1;
  int Land_Artist_Image_Enable;

  // Album_Image
  int Land_Album_Image_x1;
  int Land_Album_Image_y1;
  int Land_Album_Image_Enable;

  // Whell BG_Image
  int Land_WhellBG_Image_x1;
  int Land_WhellBG_Image_y1;
  int Land_WhellBG_Image_Enable;

  // Whell UP_Image
  int Land_WhellUP_Image_x1;
  int Land_WhellUP_Image_y1;
  int Land_WhellUP_Image_Enable;

  // Whell DOWN_Image
  int Land_WhellDOWN_Image_x1;
  int Land_WhellDOWN_Image_y1;
  int Land_WhellDOWN_Image_Enable;

  // Whell LEFT_Image
  int Land_WhellLEFT_Image_x1;
  int Land_WhellLEFT_Image_y1;
  int Land_WhellLEFT_Image_Enable;

  // Whell RIGHT_Image
  int Land_WhellRIGHT_Image_x1;
  int Land_WhellRIGHT_Image_y1;
  int Land_WhellRIGHT_Image_Enable;

  // Whell CENTER_Image
  int Land_WhellCENTER_Image_x1;
  int Land_WhellCENTER_Image_y1;
  int Land_WhellCENTER_Image_Enable;

  // Background_Image
  int Land_Background_Image_x1;
  int Land_Background_Image_y1;
  int Land_Background_Image_Enable;

  // Overlay_Image
  int Land_Overlay_Image_x1;
  int Land_Overlay_Image_y1;
  int Land_Overlay_Image_Enable;

  // Progress Bar
  int Land_ProgressBarEnable;
  RECT Land_PRect;
  int Land_PBColor;
  int Land_PFColor;

  // VolumeBar
  int Land_VolumeBarEnable;
  RECT Land_VRect;
  int Land_VBColor;
  int Land_VFColor;

  // AlbumArt
  int Land_AlbumArtEnable;
  RECT Land_ARect;

  // Visualisation
  int Land_VisualisationEnable;
  RECT Land_VIZRect;

  bool FullScreen;
  bool SoftKeys;
} SkinData;

#include "CurrentTrack.h"
#include "GUI\AdvLyric.h"
#include "Pages\Lyric.h"

typedef struct _Internal_Function
{
  MusicApplication_Book *MusicBook;
  DISP_OBJ *Music_Gui_NowPlaying;

  TEXTID TextID;

  bool Portrait;
  bool Fullscreen;
  bool SoftKeys;

  wchar_t Buffer[128];
  wchar_t *Extension;
  wchar_t *Genre;

  int FullTimeInSeconds;
  int ElapsedTimeInSeconds;

  TMusicServer_Time FullTime;
  TMusicServer_Time ElapsedTime;

  uint16_t AutoOffTimer;
  bool TimerOn;
  int Counter;

  IMG MusicPlayer[LastImage];
  IMAGEID CoverArtID;

  int VolumeLevel;
  int Bitrate;

  uint16_t blob_w;
  uint16_t blob_h;

  SkinData SData;
  SkinDrawData Main;
} Internal_Function;

Internal_Function *Create_Internal_Function();
Internal_Function *Get_Internal_Function();
void Delete_Internal_Function(Internal_Function *Data);

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname);
void SetGUIData(GUI *gui);
void InvalidateRect(DISP_OBJ *disp_obj);
int GetMediaVolume();
int division(int num1, int num2);

extern "C" void RefreshScreen();

#endif
