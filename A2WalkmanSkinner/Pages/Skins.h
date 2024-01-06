#ifndef __SKINS_H__
#define __SKINS_H__

#include "..\\main.h"

#define SKIN_PATH_EXTERNAL L"/card/other/ZBin/Config/WALKMAN"
#define SKIN_PATH_INTERNAL L"/usb/other/ZBin/Config/WALKMAN"

static const char SkinEditorBook_Name[] = "SkinEditor_Book";
static const char SkinEditor_Base_Page_Name[] = "SkinEditor_Base_Page";
static const char SkinEditor_Main_Page_Name[] = "SkinEditor_Main_Page";
static const char SkinEditor_ApplySkin_Page_Name[] = "SkinEditor_ApplySkin_Page";

typedef enum
{
  Tab_NotSelected = 0,
  Tab_Selected
} TabMenu_State_t;

typedef enum
{
  Tab_Portrait_t = 0,
  Tab_Landscape_t,
  Tab_GUI_t,
  Tab_Last_t
} TabMenu_Type_t;

typedef struct _SKIN
{
  wchar_t SkinDataPath[512];
  wchar_t Path[512];
  wchar_t Name[512];
} SKIN;

typedef struct _SkinEditor_Book : BOOK
{
  GUI *SkinsList;
  GUI *DialogApplySkin;
  GUI *DialogNewSkin;
  GUI *DialogSaveSkin;

  GUI *InputAuthorName;

  GUI_TABMENUBAR *Main_Tab;
  GUI_LIST *Tab_Portrait;
  GUI_LIST *Tab_Landscape;
  GUI_LIST *Tab_PlayerGUI;

  GUI *color;
  GUI *coord;
  GUI *font_select;

  GUI *Alignment;
  GUI *ProgressBar;
  GUI *IconEdit;
  GUI *StringEdit;

  bool IsBbar;
  bool IsFbar;
  bool IsString;
  bool IsCover;

  wchar_t fpath[256];
  wchar_t fname[256];
  wchar_t sname[100];
  wchar_t AuthorName[100];

  bool Orientation;
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
  RECT PRect;
  int PBColor;
  int PFColor;
  int ProgressBarEnable;

  // VolumeBar
  RECT VRect;
  int VBColor;
  int VFColor;
  int VolumeBarEnable;

  // AlbumArt
  RECT ARect;
  int AlbumArtEnable;

  // Visualisation
  RECT VIZRect;
  int VisualisationEnable;

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
  RECT Land_PRect;
  int Land_PBColor;
  int Land_PFColor;
  int Land_ProgressBarEnable;

  // VolumeBar
  RECT Land_VRect;
  int Land_VBColor;
  int Land_VFColor;
  int Land_VolumeBarEnable;

  // AlbumArt
  RECT Land_ARect;
  int Land_AlbumArtEnable;

  // Visualisation
  RECT Land_VIZRect;
  int Land_VisualisationEnable;

  bool FullScreen;
  bool SoftKeys;

  LIST *SkinList;

} SkinEditor_Book;

//==============================================================================

void Enter_SkinEditor(BOOK *book, GUI *gui);
BOOL IsSkinEditorBook(BOOK *book);
SkinEditor_Book *Find_SkinEditor_Book();
void Free_SkinEditor_Book();

int SelectSkin_ApplySkin_EnterEvent(void *data, BOOK *book);
int SelectSkin_ApplySkin_AcceptEvent(void *data, BOOK *book);
int SelectSkin_ApplySkin_PrevEvent(void *data, BOOK *book);
int SelectSkin_ApplySkin_CancelEvent(void *data, BOOK *book);

const PAGE_MSG bk_skins_apply[] =
    {
        PAGE_ENTER_EVENT, SelectSkin_ApplySkin_EnterEvent,
        ACCEPT_EVENT, SelectSkin_ApplySkin_AcceptEvent,
        PREVIOUS_EVENT, SelectSkin_ApplySkin_PrevEvent,
        CANCEL_EVENT, SelectSkin_ApplySkin_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC SkinEditor_Apply_Page = {SkinEditor_ApplySkin_Page_Name, NULL, bk_skins_apply};

//==============================================================================

int SelectSkin_MainPage_EnterEvent(void *data, BOOK *book);
int SelectSkin_MainPage_ExitEvent(void *data, BOOK *book);

const PAGE_MSG bk_skins_main[] =
    {
        PAGE_ENTER_EVENT, SelectSkin_MainPage_EnterEvent,
        PAGE_EXIT_EVENT, SelectSkin_MainPage_ExitEvent,
        NIL_EVENT, NULL};
const PAGE_DESC SkinEditor_Main_Page = {SkinEditor_Main_Page_Name, NULL, bk_skins_main};

//==============================================================================

int SelectSkin_BasePage_CancelEvent(void *data, BOOK *book);

const PAGE_MSG bk_skins_base[] =
    {
        CANCEL_EVENT, SelectSkin_BasePage_CancelEvent,
        RETURN_TO_STANDBY_EVENT, SelectSkin_BasePage_CancelEvent,
        NIL_EVENT, NULL};
const PAGE_DESC SkinEditor_Base_Page = {SkinEditor_Base_Page_Name, NULL, bk_skins_base};

//==============================================================================

#endif
