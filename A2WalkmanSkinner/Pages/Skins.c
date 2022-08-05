#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\Editor.h"
#include "..\\FilesList.h"
#include "..\\Function.h"
#include "..\\LNG.h"
#include "..\\main.h"
#include "..\\SaveLoad.h"
#include "..\\String.h"

#include "..\\GUI\Dialog.h"
#include "..\\GUI\NowPlaying.h"

#include "AlbumArt.h"
#include "Skins.h"

//==============================================================================

BOOL IsSkinEditorBook(BOOK *book)
{
  if (strcmp(book->xbook->name, SkinEditorBook_Name) == 0)
    return 1;
  return 0;
}

SkinEditor_Book *Find_SkinEditor_Book()
{
  return (SkinEditor_Book *)FindBook(IsSkinEditorBook);
}

void Free_SkinEditor_Book()
{
  SkinEditor_Book *SkinEditor = Find_SkinEditor_Book();
  if (SkinEditor)
    FreeBook(SkinEditor);
}

//==============================================================================

void Destroy_TabGUI(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  DESTROY_GUI(mbk->Tab_Portrait);
  DESTROY_GUI(mbk->Tab_Landscape);
  DESTROY_GUI(mbk->Tab_PlayerGUI);
  DESTROY_GUI(mbk->Main_Tab);
  DESTROY_GUI(mbk->DialogSaveSkin);
}

//==============================================================================

void DialogSaveSkin_onBack(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->DialogSaveSkin);
}

void DialogSaveSkin_onYes(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  SaveSkinData(mbk, mbk->fpath, mbk->fname);
  Destroy_TabGUI(mbk);

  mbk->ChangeMade = FALSE; // reset
}

void DialogSaveSkin_onNo(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  Destroy_TabGUI(mbk);

  mbk->ChangeMade = FALSE; // reset
  mbk->GuiChanged = FALSE; // reset
}

void Create_DialogSaveSkin(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  mbk->DialogSaveSkin = CreateDialog(mbk);
  Dialog_SetTitleText(mbk->DialogSaveSkin, TEXT_CHANGES_MADE);
  Dialog_SetDialogText(mbk->DialogSaveSkin, TEXT_SAVE_BEFORE_EXIT);

  GUIObject_SoftKeys_SetAction(mbk->DialogSaveSkin, ACTION_YES, DialogSaveSkin_onYes);
  GUIObject_SoftKeys_SetAction(mbk->DialogSaveSkin, ACTION_NO, DialogSaveSkin_onNo);
  GUIObject_SoftKeys_SetAction(mbk->DialogSaveSkin, ACTION_BACK, DialogSaveSkin_onBack);
  GUIObject_Show(mbk->DialogSaveSkin);
}

//=============================================================================

int onLinksLBMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == 0)
      GUIonMessage_SetMenuItemText(msg, TEXT_TITLE);
    if (item == 1)
      GUIonMessage_SetMenuItemText(msg, TEXT_ARTIST);
    if (item == 2)
      GUIonMessage_SetMenuItemText(msg, TEXT_ALBUM);
    if (item == 3)
      GUIonMessage_SetMenuItemText(msg, TEXT_GENRE);
    if (item == 4)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_TOTAL_TIME));
    if (item == 5)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_ELAPSED_TIME));
    if (item == 6)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_REMAINING_TIME));
    if (item == 7)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_EXTENSION));
    if (item == 8)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_BITRATE));
    if (item == 9)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_TOTAL_TRACK_NUMBER));
    if (item == 10)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_CURRENT_TRACK_NUMBER));
    if (item == 11)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_SHUFFLE_ICON));
    if (item == 12)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_LOOP_ICON));
    if (item == 13)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_EQ_ICON));
    if (item == 14)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_PLAYER_STATE_ICON));
    if (item == 15)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_TITLE_ICON));
    if (item == 16)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_ARTIST_ICON));
    if (item == 17)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_ALBUM_ICON));
    if (item == 18)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_WHEEL_BG_ICON));
    if (item == 19)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_WHEEL_UP_ICON));
    if (item == 20)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_WHEEL_DOWN_ICON));
    if (item == 21)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_WHEEL_LEFT_ICON));
    if (item == 22)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_WHEEL_RIGHT_ICON));
    if (item == 23)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_WHEEL_CENTER_ICON));
    if (item == 24)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_BACKGROUND_IMAGE));
    if (item == 25)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_OVERLAY_IMAGE));
    if (item == 26)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_PROGRESS_BAR));
    if (item == 27)
      GUIonMessage_SetMenuItemText(msg, STR(TXT_VOLUME_BAR));
    if (item == 28)
      GUIonMessage_SetMenuItemText(msg, TEXT_ALBUM_ART);

    if (item == 29)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_VIZ);
      GUIonMessage_SetItemDisabled(msg, 1);
      GUIonMessage_SetMenuItemUnavailableText(msg, TEXT_DISABLED);
    }
  }
  return 1;
}

int onLinksGUI(GUI_MESSAGE *msg)
{
  SkinEditor_Book *book = (SkinEditor_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == 0)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_FULLSCREEN);
      if (book->FullScreen)
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_YES);
      else
      {
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_NO);
      }
    }
    if (item == 1)
    {
      GUIonMessage_SetMenuItemText(msg, STR(TXT_SHOW_SOFTKEY));
      if (book->SoftKeys)
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_YES);
      else
      {
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_NO);
      }
    }
  }
  return 1;
}

void OnLinksEditorSelectGui(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  wstrcpy(mbk->Title_Str, L"UNDEFINED");
  int item = ListMenu_GetSelectedItem(mbk->Tab_Portrait);
  mbk->ItemID = item;
  if (item == 0)
  {
    // book->ItemID=0;
    wstrcpy(mbk->Title_Str, L"Title");
    mbk->Str_Align = mbk->Title_Align;
    mbk->Str_Enable = mbk->Title_Enable;
    mbk->Str_Font_Size = mbk->Title_Font;
    mbk->Str_Color = mbk->Title_Color;
    mbk->Str_x1 = mbk->Title_x1;
    mbk->Str_x2 = mbk->Title_x2;
    mbk->Str_y1 = mbk->Title_y1;
    mbk->Str_y2 = mbk->Title_y2;
    Editor_ItemText(mbk);
  }
  if (item == 1)
  {
    // book->ItemID=1;
    wstrcpy(mbk->Title_Str, L"Artist");
    mbk->Str_Align = mbk->Artist_Align;
    mbk->Str_Enable = mbk->Artist_Enable;
    mbk->Str_Font_Size = mbk->Artist_Font;
    mbk->Str_Color = mbk->Artist_Color;
    mbk->Str_x1 = mbk->Artist_x1;
    mbk->Str_x2 = mbk->Artist_x2;
    mbk->Str_y1 = mbk->Artist_y1;
    mbk->Str_y2 = mbk->Artist_y2;
    Editor_ItemText(mbk);
  }
  if (item == 2)
  {
    // book->ItemID=2;
    wstrcpy(mbk->Title_Str, L"Album");
    mbk->Str_Align = mbk->Album_Align;
    mbk->Str_Enable = mbk->Album_Enable;
    mbk->Str_Font_Size = mbk->Album_Font;
    mbk->Str_Color = mbk->Album_Color;
    mbk->Str_x1 = mbk->Album_x1;
    mbk->Str_x2 = mbk->Album_x2;
    mbk->Str_y1 = mbk->Album_y1;
    mbk->Str_y2 = mbk->Album_y2;
    Editor_ItemText(mbk);
  }
  if (item == 3)
  {
    // book->ItemID=3;
    wstrcpy(mbk->Title_Str, L"Genre");
    mbk->Str_Align = mbk->Genre_Align;
    mbk->Str_Enable = mbk->Genre_Enable;
    mbk->Str_Font_Size = mbk->Genre_Font;
    mbk->Str_Color = mbk->Genre_Color;
    mbk->Str_x1 = mbk->Genre_x1;
    mbk->Str_x2 = mbk->Genre_x2;
    mbk->Str_y1 = mbk->Genre_y1;
    mbk->Str_y2 = mbk->Genre_y2;
    Editor_ItemText(mbk);
  }
  if (item == 4)
  {
    // book->ItemID=4;
    wstrcpy(mbk->Title_Str, L"Total Time");
    mbk->Str_Align = mbk->TotalTime_Align;
    mbk->Str_Enable = mbk->TotalTime_Enable;
    mbk->Str_Font_Size = mbk->TotalTime_Font;
    mbk->Str_Color = mbk->TotalTime_Color;
    mbk->Str_x1 = mbk->TotalTime_x1;
    mbk->Str_x2 = mbk->TotalTime_x2;
    mbk->Str_y1 = mbk->TotalTime_y1;
    mbk->Str_y2 = mbk->TotalTime_y2;
    Editor_ItemText(mbk);
  }
  if (item == 5)
  {
    // book->ItemID=5;
    wstrcpy(mbk->Title_Str, L"Elapsed Time");
    mbk->Str_Align = mbk->ElapsedTime_Align;
    mbk->Str_Enable = mbk->ElapsedTime_Enable;
    mbk->Str_Font_Size = mbk->ElapsedTime_Font;
    mbk->Str_Color = mbk->ElapsedTime_Color;
    mbk->Str_x1 = mbk->ElapsedTime_x1;
    mbk->Str_x2 = mbk->ElapsedTime_x2;
    mbk->Str_y1 = mbk->ElapsedTime_y1;
    mbk->Str_y2 = mbk->ElapsedTime_y2;
    Editor_ItemText(mbk);
  }
  if (item == 6)
  {
    // book->ItemID=6;
    wstrcpy(mbk->Title_Str, L"Remaining Time");
    mbk->Str_Align = mbk->RemainingTime_Align;
    mbk->Str_Enable = mbk->RemainingTime_Enable;
    mbk->Str_Font_Size = mbk->RemainingTime_Font;
    mbk->Str_Color = mbk->RemainingTime_Color;
    mbk->Str_x1 = mbk->RemainingTime_x1;
    mbk->Str_x2 = mbk->RemainingTime_x2;
    mbk->Str_y1 = mbk->RemainingTime_y1;
    mbk->Str_y2 = mbk->RemainingTime_y2;
    Editor_ItemText(mbk);
  }
  if (item == 7)
  {
    // book->ItemID=7;
    wstrcpy(mbk->Title_Str, L"Extension");
    mbk->Str_Align = mbk->Extension_Align;
    mbk->Str_Enable = mbk->Extension_Enable;
    mbk->Str_Font_Size = mbk->Extension_Font;
    mbk->Str_Color = mbk->Extension_Color;
    mbk->Str_x1 = mbk->Extension_x1;
    mbk->Str_x2 = mbk->Extension_x2;
    mbk->Str_y1 = mbk->Extension_y1;
    mbk->Str_y2 = mbk->Extension_y2;
    Editor_ItemText(mbk);
  }
  if (item == 8)
  {
    // book->ItemID=8;
    wstrcpy(mbk->Title_Str, L"Bitrate");
    mbk->Str_Align = mbk->BitRate_Align;
    mbk->Str_Enable = mbk->BitRate_Enable;
    mbk->Str_Font_Size = mbk->BitRate_Font;
    mbk->Str_Color = mbk->BitRate_Color;
    mbk->Str_x1 = mbk->BitRate_x1;
    mbk->Str_x2 = mbk->BitRate_x2;
    mbk->Str_y1 = mbk->BitRate_y1;
    mbk->Str_y2 = mbk->BitRate_y2;
    Editor_ItemText(mbk);
  }
  if (item == 9)
  {
    // book->ItemID=9;
    wstrcpy(mbk->Title_Str, L"Total Track");
    mbk->Str_Align = mbk->TotalTrackID_Align;
    mbk->Str_Enable = mbk->TotalTrackID_Enable;
    mbk->Str_Font_Size = mbk->TotalTrackID_Font;
    mbk->Str_Color = mbk->TotalTrackID_Color;
    mbk->Str_x1 = mbk->TotalTrackID_x1;
    mbk->Str_x2 = mbk->TotalTrackID_x2;
    mbk->Str_y1 = mbk->TotalTrackID_y1;
    mbk->Str_y2 = mbk->TotalTrackID_y2;
    Editor_ItemText(mbk);
  }
  if (item == 10)
  {
    // book->ItemID=10;
    wstrcpy(mbk->Title_Str, L"Current Track ID");
    mbk->Str_Align = mbk->C_TrackID_Align;
    mbk->Str_Enable = mbk->C_TrackID_Enable;
    mbk->Str_Font_Size = mbk->C_TrackID_Font;
    mbk->Str_Color = mbk->C_TrackID_Color;
    mbk->Str_x1 = mbk->C_TrackID_x1;
    mbk->Str_x2 = mbk->C_TrackID_x2;
    mbk->Str_y1 = mbk->C_TrackID_y1;
    mbk->Str_y2 = mbk->C_TrackID_y2;
    Editor_ItemText(mbk);
  }
  if (item == 11)
  {
    // book->ItemID=11;
    wstrcpy(mbk->Title_Str, L"Shuffle Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Shuffle_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Shuffle_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Shuffle_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(book);
  }
  if (item == 12)
  {
    // book->ItemID=12;
    wstrcpy(mbk->Title_Str, L"Loop Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Loop_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Loop_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Loop_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 13)
  {
    // book->ItemID=13;
    wstrcpy(mbk->Title_Str, L"EQ Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->EQ_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->EQ_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->EQ_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 14)
  {
    // book->ItemID=14;
    wstrcpy(mbk->Title_Str, L"Player State Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->PlayerState_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->PlayerState_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->PlayerState_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 15)
  {
    // book->ItemID=15;
    wstrcpy(mbk->Title_Str, L"Title Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Title_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Title_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Title_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 16)
  {
    // book->ItemID=16;
    wstrcpy(mbk->Title_Str, L"Artist Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Artist_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Artist_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Artist_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 17)
  {
    // book->ItemID=17;
    wstrcpy(mbk->Title_Str, L"Album Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Album_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Album_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Album_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 18)
  {
    // book->ItemID=18;
    wstrcpy(mbk->Title_Str, L"Wheel BG Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellBG_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellBG_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellBG_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 19)
  {
    // book->ItemID=19;
    wstrcpy(mbk->Title_Str, L"Wheel Up Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellUP_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellUP_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellUP_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 20)
  {
    // book->ItemID=20;
    wstrcpy(mbk->Title_Str, L"Wheel Down Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellDOWN_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellDOWN_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellDOWN_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 21)
  {
    // book->ItemID=21;
    wstrcpy(mbk->Title_Str, L"Wheel Left Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellLEFT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellLEFT_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellLEFT_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 22)
  {
    // book->ItemID=22;
    wstrcpy(mbk->Title_Str, L"Wheel Right Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellRIGHT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellRIGHT_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellRIGHT_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 23)
  {
    // book->ItemID=23;
    wstrcpy(mbk->Title_Str, L"Wheel Center Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellCENTER_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellCENTER_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellCENTER_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 24)
  {
    // book->ItemID=24;
    wstrcpy(mbk->Title_Str, L"Background Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Background_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Background_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Background_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 25)
  {
    // book->ItemID=25;
    wstrcpy(mbk->Title_Str, L"Overlay Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Overlay_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Overlay_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Overlay_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 26)
  {
    // book->ItemID=26;
    wstrcpy(mbk->Title_Str, L"Progress Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->ProgressBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = mbk->PBColor;
    mbk->Str_Color_2 = mbk->PFColor;
    mbk->Str_x1 = mbk->PRect.x1;
    mbk->Str_x2 = mbk->PRect.x2;
    mbk->Str_y1 = mbk->PRect.y1;
    mbk->Str_y2 = mbk->PRect.y2;
    Editor_Slider(mbk);
  }
  if (item == 27)
  {
    // book->ItemID=27;
    wstrcpy(mbk->Title_Str, L"Volume Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->VolumeBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = mbk->VBColor;
    mbk->Str_Color_2 = mbk->VFColor;
    mbk->Str_x1 = mbk->VRect.x1;
    mbk->Str_x2 = mbk->VRect.x2;
    mbk->Str_y1 = mbk->VRect.y1;
    mbk->Str_y2 = mbk->VRect.y2;
    Editor_Slider(mbk);
  }
  if (item == 28)
  {
    // book->ItemID=28;
    mbk->IsCover = TRUE;
    mbk->Str_x1 = mbk->ARect.x1;
    mbk->Str_x2 = mbk->ARect.x2;
    mbk->Str_y1 = mbk->ARect.y1;
    mbk->Str_y2 = mbk->ARect.y2;
    EditCoordinates(mbk, 1);
  }
  if (item == 29)
  {
    // book->ItemID=29;
    mbk->IsCover = TRUE;
    mbk->Str_x1 = mbk->VRect.x1;
    mbk->Str_x2 = mbk->VRect.x2;
    mbk->Str_y1 = mbk->VRect.y1;
    mbk->Str_y2 = mbk->VRect.y2;
    EditCoordinates(mbk, 1);
  }
}

void OnLinksLandEditorSelectGui(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  wstrcpy(mbk->Title_Str, L"UNDEFINED");
  int item = ListMenu_GetSelectedItem(mbk->Tab_Landscape);
  mbk->ItemID = item + 30;
  if (item == 0)
  {
    // book->ItemID=30;
    wstrcpy(mbk->Title_Str, L"Title");
    mbk->Str_Align = mbk->Land_Title_Align;
    mbk->Str_Enable = mbk->Land_Title_Enable;
    mbk->Str_Font_Size = mbk->Land_Title_Font;
    mbk->Str_Color = mbk->Land_Title_Color;
    mbk->Str_x1 = mbk->Land_Title_x1;
    mbk->Str_x2 = mbk->Land_Title_x2;
    mbk->Str_y1 = mbk->Land_Title_y1;
    mbk->Str_y2 = mbk->Land_Title_y2;
    Editor_ItemText(mbk);
  }
  if (item == 1)
  {
    // book->ItemID=31;
    wstrcpy(mbk->Title_Str, L"Artist");
    mbk->Str_Align = mbk->Land_Artist_Align;
    mbk->Str_Enable = mbk->Land_Artist_Enable;
    mbk->Str_Font_Size = mbk->Land_Artist_Font;
    mbk->Str_Color = mbk->Land_Artist_Color;
    mbk->Str_x1 = mbk->Land_Artist_x1;
    mbk->Str_x2 = mbk->Land_Artist_x2;
    mbk->Str_y1 = mbk->Land_Artist_y1;
    mbk->Str_y2 = mbk->Land_Artist_y2;
    Editor_ItemText(mbk);
  }
  if (item == 2)
  {
    // book->ItemID=32;
    wstrcpy(mbk->Title_Str, L"Album");
    mbk->Str_Align = mbk->Land_Album_Align;
    mbk->Str_Enable = mbk->Land_Album_Enable;
    mbk->Str_Font_Size = mbk->Land_Album_Font;
    mbk->Str_Color = mbk->Land_Album_Color;
    mbk->Str_x1 = mbk->Land_Album_x1;
    mbk->Str_x2 = mbk->Land_Album_x2;
    mbk->Str_y1 = mbk->Land_Album_y1;
    mbk->Str_y2 = mbk->Land_Album_y2;
    Editor_ItemText(mbk);
  }
  if (item == 3)
  {
    // book->ItemID=33;
    wstrcpy(mbk->Title_Str, L"Genre");
    mbk->Str_Align = mbk->Land_Genre_Align;
    mbk->Str_Enable = mbk->Land_Genre_Enable;
    mbk->Str_Font_Size = mbk->Land_Genre_Font;
    mbk->Str_Color = mbk->Land_Genre_Color;
    mbk->Str_x1 = mbk->Land_Genre_x1;
    mbk->Str_x2 = mbk->Land_Genre_x2;
    mbk->Str_y1 = mbk->Land_Genre_y1;
    mbk->Str_y2 = mbk->Land_Genre_y2;
    Editor_ItemText(mbk);
  }
  if (item == 4)
  {
    // book->ItemID=34;
    wstrcpy(mbk->Title_Str, L"Total Time");
    mbk->Str_Align = mbk->Land_TotalTime_Align;
    mbk->Str_Enable = mbk->Land_TotalTime_Enable;
    mbk->Str_Font_Size = mbk->Land_TotalTime_Font;
    mbk->Str_Color = mbk->Land_TotalTime_Color;
    mbk->Str_x1 = mbk->Land_TotalTime_x1;
    mbk->Str_x2 = mbk->Land_TotalTime_x2;
    mbk->Str_y1 = mbk->Land_TotalTime_y1;
    mbk->Str_y2 = mbk->Land_TotalTime_y2;
    Editor_ItemText(book);
  }
  if (item == 5)
  {
    // book->ItemID=35;
    wstrcpy(mbk->Title_Str, L"Elapsed Time");
    mbk->Str_Align = mbk->Land_ElapsedTime_Align;
    mbk->Str_Enable = mbk->Land_ElapsedTime_Enable;
    mbk->Str_Font_Size = mbk->Land_ElapsedTime_Font;
    mbk->Str_Color = mbk->Land_ElapsedTime_Color;
    mbk->Str_x1 = mbk->Land_ElapsedTime_x1;
    mbk->Str_x2 = mbk->Land_ElapsedTime_x2;
    mbk->Str_y1 = mbk->Land_ElapsedTime_y1;
    mbk->Str_y2 = mbk->Land_ElapsedTime_y2;
    Editor_ItemText(mbk);
  }
  if (item == 6)
  {
    // book->ItemID=36;
    wstrcpy(mbk->Title_Str, L"Remaining Time");
    mbk->Str_Align = mbk->Land_RemainingTime_Align;
    mbk->Str_Enable = mbk->Land_RemainingTime_Enable;
    mbk->Str_Font_Size = mbk->Land_RemainingTime_Font;
    mbk->Str_Color = mbk->Land_RemainingTime_Color;
    mbk->Str_x1 = mbk->Land_RemainingTime_x1;
    mbk->Str_x2 = mbk->Land_RemainingTime_x2;
    mbk->Str_y1 = mbk->Land_RemainingTime_y1;
    mbk->Str_y2 = mbk->Land_RemainingTime_y2;
    Editor_ItemText(book);
  }
  if (item == 7)
  {
    // book->ItemID=37;
    wstrcpy(mbk->Title_Str, L"Extension");
    mbk->Str_Align = mbk->Land_Extension_Align;
    mbk->Str_Enable = mbk->Land_Extension_Enable;
    mbk->Str_Font_Size = mbk->Land_Extension_Font;
    mbk->Str_Color = mbk->Land_Extension_Color;
    mbk->Str_x1 = mbk->Land_Extension_x1;
    mbk->Str_x2 = mbk->Land_Extension_x2;
    mbk->Str_y1 = mbk->Land_Extension_y1;
    mbk->Str_y2 = mbk->Land_Extension_y2;
    Editor_ItemText(mbk);
  }
  if (item == 8)
  {
    // book->ItemID=38;
    wstrcpy(mbk->Title_Str, L"Bitrate");
    mbk->Str_Align = mbk->Land_BitRate_Align;
    mbk->Str_Enable = mbk->Land_BitRate_Enable;
    mbk->Str_Font_Size = mbk->Land_BitRate_Font;
    mbk->Str_Color = mbk->Land_BitRate_Color;
    mbk->Str_x1 = mbk->Land_BitRate_x1;
    mbk->Str_x2 = mbk->Land_BitRate_x2;
    mbk->Str_y1 = mbk->Land_BitRate_y1;
    mbk->Str_y2 = mbk->Land_BitRate_y2;
    Editor_ItemText(mbk);
  }
  if (item == 9)
  {
    // book->ItemID=39;
    wstrcpy(mbk->Title_Str, L"Total Track");
    mbk->Str_Align = mbk->Land_TotalTrackID_Align;
    mbk->Str_Enable = mbk->Land_TotalTrackID_Enable;
    mbk->Str_Font_Size = mbk->Land_TotalTrackID_Font;
    mbk->Str_Color = mbk->Land_TotalTrackID_Color;
    mbk->Str_x1 = mbk->Land_TotalTrackID_x1;
    mbk->Str_x2 = mbk->Land_TotalTrackID_x2;
    mbk->Str_y1 = mbk->Land_TotalTrackID_y1;
    mbk->Str_y2 = mbk->Land_TotalTrackID_y2;
    Editor_ItemText(mbk);
  }
  if (item == 10)
  {
    // book->ItemID=40;
    wstrcpy(mbk->Title_Str, L"Current Track ID");
    mbk->Str_Align = mbk->Land_C_TrackID_Align;
    mbk->Str_Enable = mbk->Land_C_TrackID_Enable;
    mbk->Str_Font_Size = mbk->Land_C_TrackID_Font;
    mbk->Str_Color = mbk->Land_C_TrackID_Color;
    mbk->Str_x1 = mbk->Land_C_TrackID_x1;
    mbk->Str_x2 = mbk->Land_C_TrackID_x2;
    mbk->Str_y1 = mbk->Land_C_TrackID_y1;
    mbk->Str_y2 = mbk->Land_C_TrackID_y2;
    Editor_ItemText(mbk);
  }
  if (item == 11)
  {
    // book->ItemID=41;
    wstrcpy(mbk->Title_Str, L"Shuffle Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Shuffle_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Shuffle_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Shuffle_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 12)
  {
    // book->ItemID=42;
    wstrcpy(mbk->Title_Str, L"Loop Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Loop_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Loop_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Loop_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 13)
  {
    // book->ItemID=43;
    wstrcpy(mbk->Title_Str, L"EQ Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_EQ_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_EQ_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_EQ_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 14)
  {
    // book->ItemID=44;
    wstrcpy(mbk->Title_Str, L"Player State Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_PlayerState_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_PlayerState_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_PlayerState_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 15)
  {
    // book->ItemID=45;
    wstrcpy(mbk->Title_Str, L"Title Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Title_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Title_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Title_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 16)
  {
    // book->ItemID=46;
    wstrcpy(mbk->Title_Str, L"Artist Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Artist_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Artist_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Artist_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 17)
  {
    // book->ItemID=47;
    wstrcpy(mbk->Title_Str, L"Album Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Album_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Album_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Album_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 18)
  {
    // book->ItemID=48;
    wstrcpy(mbk->Title_Str, L"Wheel BG Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_WhellBG_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_WhellBG_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_WhellBG_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 19)
  {
    // book->ItemID=49;
    wstrcpy(mbk->Title_Str, L"Wheel Up Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_WhellUP_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_WhellUP_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_WhellUP_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 20)
  {
    // book->ItemID=50;
    wstrcpy(mbk->Title_Str, L"Wheel Down Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_WhellDOWN_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_WhellDOWN_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_WhellDOWN_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 21)
  {
    // book->ItemID=51;
    wstrcpy(mbk->Title_Str, L"Wheel Left Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_WhellLEFT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_WhellLEFT_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_WhellLEFT_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 22)
  {
    // book->ItemID=52;
    wstrcpy(mbk->Title_Str, L"Wheel Right Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_WhellRIGHT_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_WhellRIGHT_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_WhellRIGHT_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 23)
  {
    // book->ItemID=53;
    wstrcpy(mbk->Title_Str, L"Wheel Center Icon");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->WhellCENTER_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->WhellCENTER_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->WhellCENTER_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 24)
  {
    // book->ItemID=54;
    wstrcpy(mbk->Title_Str, L"Background Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Background_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Background_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Background_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }
  if (item == 25)
  {
    // book->ItemID=55;
    wstrcpy(mbk->Title_Str, L"Overlay Image");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_Overlay_Image_Enable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = 0;
    mbk->Str_x1 = mbk->Land_Overlay_Image_x1;
    mbk->Str_x2 = 0;
    mbk->Str_y1 = mbk->Land_Overlay_Image_y1;
    mbk->Str_y2 = 0;
    Editor_ItemIcon(mbk);
  }

  if (item == 26)
  {
    // book->ItemID=56;
    wstrcpy(mbk->Title_Str, L"Progress Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_ProgressBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = mbk->Land_PBColor;
    mbk->Str_Color_2 = mbk->Land_PFColor;
    mbk->Str_x1 = mbk->Land_PRect.x1;
    mbk->Str_x2 = mbk->Land_PRect.x2;
    mbk->Str_y1 = mbk->Land_PRect.y1;
    mbk->Str_y2 = mbk->Land_PRect.y2;
    Editor_Slider(mbk);
  }
  if (item == 27)
  {
    // book->ItemID=57;
    wstrcpy(mbk->Title_Str, L"Volume Bar");
    mbk->Str_Align = 0;
    mbk->Str_Enable = mbk->Land_VolumeBarEnable;
    mbk->Str_Font_Size = 0;
    mbk->Str_Color = mbk->Land_VBColor;
    mbk->Str_Color_2 = mbk->Land_VFColor;
    mbk->Str_x1 = mbk->Land_VRect.x1;
    mbk->Str_x2 = mbk->Land_VRect.x2;
    mbk->Str_y1 = mbk->Land_VRect.y1;
    mbk->Str_y2 = mbk->Land_VRect.y2;
    Editor_Slider(mbk);
  }
  if (item == 28)
  {
    // book->ItemID=58;
    mbk->IsCover = TRUE;
    mbk->Str_x1 = mbk->Land_ARect.x1;
    mbk->Str_x2 = mbk->Land_ARect.x2;
    mbk->Str_y1 = mbk->Land_ARect.y1;
    mbk->Str_y2 = mbk->Land_ARect.y2;
    EditCoordinates(mbk, 1);
  }
  if (item == 29)
  {
    // book->ItemID=59;
    mbk->IsCover = TRUE;
    mbk->Str_x1 = mbk->Land_VRect.x1;
    mbk->Str_x2 = mbk->Land_VRect.x2;
    mbk->Str_y1 = mbk->Land_VRect.y1;
    mbk->Str_y2 = mbk->Land_VRect.y2;
    EditCoordinates(mbk, 1);
  }
}

void OnEditorLongBackGui(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  FreeBook(mbk);
}

void OnEditorBackGui(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  if (mbk->ChangeMade)
  {
    Create_DialogSaveSkin(mbk);
  }
  else
  {
    Destroy_TabGUI(mbk);
  }
}

void OnSave(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  SaveSkinData(mbk, mbk->fpath, mbk->fname);

  Destroy_TabGUI(mbk);
}

void OnLinksWalkmanGUIEditorSelectGui(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  TEXTID txt;

  int item = ListMenu_GetSelectedItem(mbk->Tab_PlayerGUI);
  if (item == 0)
  {
    if (mbk->FullScreen)
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

  if (item == 1)
  {
    if (mbk->SoftKeys)
    {
      mbk->SoftKeys = FALSE;
      txt = TEXT_NO;
    }
    else
    {
      mbk->SoftKeys = TRUE;
      txt = TEXT_YES;
    }
  }
  ListMenu_SetItemSecondLineText(mbk->Tab_PlayerGUI, item, txt);
  mbk->ChangeMade = TRUE;
}

void Set_1stTab(BOOK *book, int tab)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  mbk->Tab_Portrait = CreateListMenu(mbk, UIDisplay_Main);
  ListMenu_SetItemCount(mbk->Tab_Portrait, 30);
  ListMenu_SetOnMessage(mbk->Tab_Portrait, onLinksLBMessage);
  ListMenu_SetCursorToItem(mbk->Tab_Portrait, 0);
  ListMenu_SetItemStyle(mbk->Tab_Portrait, 0);
  ListMenu_SetItemTextScroll(mbk->Tab_Portrait, TRUE);
  ListMenu_SetHotkeyMode(mbk->Tab_Portrait, LKHM_SHORTCUT);

  GUIObject_SoftKeys_SetAction(mbk->Tab_Portrait, ACTION_BACK, OnEditorBackGui);
  GUIObject_SoftKeys_SetAction(mbk->Tab_Portrait, ACTION_LONG_BACK, OnEditorLongBackGui);
  GUIObject_SoftKeys_SetAction(mbk->Tab_Portrait, ACTION_SELECT1, OnLinksEditorSelectGui);

  GUIObject_SoftKeys_SetText(mbk->Tab_Portrait, 0, TEXT_SAVE);
  GUIObject_SoftKeys_SetAction(mbk->Tab_Portrait, 0, OnSave);
  GUIObject_SoftKeys_AllowKeylock(mbk->Tab_Portrait, TRUE);

  TabMenuBar_SetTabGui(mbk->Main_Tab, tab, mbk->Tab_Portrait);
  TabMenuBar_SetTabTitle(mbk->Main_Tab, tab, TEXT_PORTRAIT);
  TabMenuBar_SetTabIcon(mbk->Main_Tab, tab, MC_PORTRAIT_ICN, Tab_NotSelected);
  TabMenuBar_SetTabIcon(mbk->Main_Tab, tab, MC_PORTRAIT_ICN, Tab_Selected);
}

void Set_2ndTab(BOOK *book, int tab)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  mbk->Tab_Landscape = CreateListMenu(mbk, UIDisplay_Main);
  ListMenu_SetItemCount(mbk->Tab_Landscape, 30);
  ListMenu_SetOnMessage(mbk->Tab_Landscape, onLinksLBMessage);
  ListMenu_SetCursorToItem(mbk->Tab_Landscape, 0);
  ListMenu_SetItemStyle(mbk->Tab_Landscape, 0);
  ListMenu_SetItemTextScroll(mbk->Tab_Landscape, TRUE);
  ListMenu_SetHotkeyMode(mbk->Tab_Landscape, LKHM_SHORTCUT);

  GUIObject_SoftKeys_SetAction(mbk->Tab_Landscape, ACTION_BACK, OnEditorBackGui);
  GUIObject_SoftKeys_SetAction(mbk->Tab_Landscape, ACTION_LONG_BACK, OnEditorLongBackGui);
  GUIObject_SoftKeys_SetAction(mbk->Tab_Landscape, ACTION_SELECT1, OnLinksLandEditorSelectGui);

  GUIObject_SoftKeys_SetText(mbk->Tab_Landscape, 0, TEXT_SAVE);
  GUIObject_SoftKeys_SetAction(mbk->Tab_Landscape, 0, OnSave);
  GUIObject_SoftKeys_AllowKeylock(mbk->Tab_Landscape, TRUE);

  TabMenuBar_SetTabGui(mbk->Main_Tab, tab, mbk->Tab_Landscape);
  TabMenuBar_SetTabTitle(mbk->Main_Tab, tab, TEXT_LANDSCAPE);
  TabMenuBar_SetTabIcon(mbk->Main_Tab, tab, MC_LANDSCAPE_ICN, Tab_NotSelected);
  TabMenuBar_SetTabIcon(mbk->Main_Tab, tab, MC_LANDSCAPE_ICN, Tab_Selected);
}

void Set_3rdTab(BOOK *book, int tab)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  mbk->Tab_PlayerGUI = CreateListMenu(mbk, UIDisplay_Main);
  ListMenu_SetItemCount(mbk->Tab_PlayerGUI, 2);
  ListMenu_SetOnMessage(mbk->Tab_PlayerGUI, onLinksGUI);
  ListMenu_SetCursorToItem(mbk->Tab_PlayerGUI, 0);
  ListMenu_SetItemStyle(mbk->Tab_PlayerGUI, 1);
  ListMenu_SetItemTextScroll(mbk->Tab_PlayerGUI, TRUE);
  ListMenu_SetHotkeyMode(mbk->Tab_PlayerGUI, LKHM_SHORTCUT);

  GUIObject_SoftKeys_SetAction(mbk->Tab_PlayerGUI, ACTION_BACK, OnEditorBackGui);
  GUIObject_SoftKeys_SetAction(mbk->Tab_PlayerGUI, ACTION_LONG_BACK, OnEditorLongBackGui);
  GUIObject_SoftKeys_SetAction(mbk->Tab_PlayerGUI, ACTION_SELECT1, OnLinksWalkmanGUIEditorSelectGui);

  GUIObject_SoftKeys_SetText(mbk->Tab_PlayerGUI, 0, TEXT_SAVE);
  GUIObject_SoftKeys_SetAction(mbk->Tab_PlayerGUI, 0, OnSave);
  GUIObject_SoftKeys_AllowKeylock(mbk->Tab_PlayerGUI, TRUE);

  TabMenuBar_SetTabGui(mbk->Main_Tab, tab, mbk->Tab_PlayerGUI);
  TabMenuBar_SetTabTitle(mbk->Main_Tab, tab, STR(TXT_WALKMAN_GUI));
  TabMenuBar_SetTabIcon(mbk->Main_Tab, tab, RN_TAB_SESSION_MANAGER_DESELECTED_ICN, Tab_NotSelected);
  TabMenuBar_SetTabIcon(mbk->Main_Tab, tab, RN_TAB_SESSION_MANAGER_SELECTED_ICN, Tab_Selected);
}

void CreateTabGui(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  mbk->Main_Tab = CreateTabMenuBar(mbk);
  TabMenuBar_SetTabCount(mbk->Main_Tab, Tab_Last_t);

  Set_1stTab(mbk, Tab_Portrait_t);
  Set_2ndTab(mbk, Tab_Landscape_t);
  Set_3rdTab(mbk, Tab_GUI_t);

  TabMenuBar_SetFocusedTab(mbk->Main_Tab, Tab_Portrait_t);
  GUIObject_Show(mbk->Main_Tab);
}

//==============================================================================

void InputAuthorName_OnAccept(BOOK *book, wchar_t *wstring, int len)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  wstrcpy(mbk->AuthorName, wstring);
  DESTROY_GUI(mbk->InputAuthorName);
  CreateTabGui(mbk);
}

void InputAuthorName_OnBack(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->InputAuthorName);
}

void Create_InputAuthorName(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  if (mbk->InputAuthorName = CreateStringInput(mbk))
  {
    StringInput_SetMode(mbk->InputAuthorName, IT_STRING);
    StringInput_SetFixedText(mbk->InputAuthorName, STR(TXT_AUTHORS_NAME));
    StringInput_SetMinLen(mbk->InputAuthorName, 1);
    StringInput_SetMaxLen(mbk->InputAuthorName, 100);
    StringInput_SetEnableEmptyText(mbk->InputAuthorName, FALSE);
    StringInput_SetActionOK(mbk->InputAuthorName, InputAuthorName_OnAccept);
    GUIObject_SoftKeys_SetAction(mbk->InputAuthorName, ACTION_BACK, InputAuthorName_OnBack);
    GUIObject_Show(mbk->InputAuthorName);
  }
}

//==============================================================================

void Refresh_MusicApp(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  Internal_Function *Data = Get_Internal_Function();
  if (Data->Portrait)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }

  if (mbk->GuiChanged)
    BookObj_GotoPage(Data->MusicBook, page_MusicApplication_Main);

  InvalidateRect(Data->Music_Gui_NowPlaying);
}

int SetSkin(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  Internal_Function *Data = Get_Internal_Function();
  FreeImage(Data);

  wchar_t *sname_fullpath = FSX_MakeFullPath(mbk->fpath, mbk->sname);

  int File = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_WRONLY, (FSX_S_IREAD | FSX_S_IWRITE), NULL);
  if (File >= 0)
  {
    SKIN *SkinData = (SKIN *)malloc(sizeof(SKIN));
    memset(SkinData, NULL, sizeof(SKIN));

    wstrcpy(SkinData->SkinDataPath, sname_fullpath);
    wstrcpy(SkinData->Path, mbk->fpath);
    wstrcpy(SkinData->Name, mbk->fname);

    fwrite(File, SkinData, sizeof(SKIN));
    fclose(File);
    mfree(SkinData);
  }
  FSX_FreeFullPath(sname_fullpath);

  LoadImage(Data);

  Refresh_MusicApp(mbk);
  SetGUIData(Data->MusicBook->Gui_NowPlaying);
  InvalidateRect(Data->Music_Gui_NowPlaying);
  return 1;
}

//=============================================================================

void DialogNewSkin_OnBack(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->DialogNewSkin);
}

void DialogNewSkin_OnYes(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->DialogNewSkin);

  Create_InputAuthorName(mbk);
}

void Create_DialogNewSkin(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  if (mbk->DialogNewSkin = CreateDialog(mbk))
  {
    Dialog_SetTitleText(mbk->DialogNewSkin, STR(TXT_CONFIGURE_NOW));
    Dialog_SetDialogText(mbk->DialogNewSkin, STR(TXT_SKIN_HASNT_BEEN_CONFIGURED_YET));

    GUIObject_SoftKeys_SetAction(mbk->DialogNewSkin, ACTION_YES, DialogNewSkin_OnYes);
    GUIObject_SoftKeys_SetAction(mbk->DialogNewSkin, ACTION_BACK, DialogNewSkin_OnBack);
    GUIObject_Show(mbk->DialogNewSkin);
  }
}

//=============================================================================

void DialogApplySkin_OnBack(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->DialogApplySkin);
}

void DialogApplySkin_OnYes(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->DialogApplySkin);

  if (SetSkin(mbk))
  {
    CreateMessageBox(EMPTY_TEXTID, STR(TXT_SKIN_UPDATED), 0, 1000, mbk);
  }
  else
  {
    CreateMessageBox(EMPTY_TEXTID, STR(TXT_SKIN_NOT_UPDATED), 0, 1000, mbk);
  }
  FreeBook(mbk);
}

void Create_DialogApplySkin(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  FILELIST *files = (FILELIST *)List_Get(mbk->SkinList, ListMenu_GetSelectedItem(mbk->SkinsList));

  mbk->DialogApplySkin = CreateDialog(mbk);
  Dialog_SetTitleText(mbk->DialogApplySkin, TextID_Create(files->name, ENC_UCS2, TEXTID_ANY_LEN));
  Dialog_SetDialogText(mbk->DialogApplySkin, TEXT_USE_NOW);

  GUIObject_SoftKeys_SetAction(mbk->DialogApplySkin, ACTION_YES, DialogApplySkin_OnYes);
  GUIObject_SoftKeys_SetAction(mbk->DialogApplySkin, ACTION_BACK, DialogApplySkin_OnBack);
  GUIObject_Show(mbk->DialogApplySkin);
}

//=============================================================================

int SelectSkin_OnMessage(GUI_MESSAGE *msg)
{

  SkinEditor_Book *mbk = (SkinEditor_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    FILELIST *files = (FILELIST *)List_Get(mbk->SkinList, index);

    GUIonMessage_SetMenuItemText(msg, TextID_Create(files->name, ENC_UCS2, TEXTID_ANY_LEN));
    break;
  }
  return 1;
}

void SelectSkin_OnBack(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  FreeBook(mbk);
}

void SelectSkin_OnEdit(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  int index = ListMenu_GetSelectedItem(mbk->SkinsList);

  FILELIST *files = (FILELIST *)List_Get(mbk->SkinList, index);

  wstrcpy(mbk->fpath, files->fpath);
  wstrcpy(mbk->fname, files->fname);
  wstrcpy(mbk->sname, files->name);
  LoadSkinData(mbk, mbk->fpath, mbk->fname);
  CreateTabGui(mbk);
}

void SelectSkin_OnAuthor(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  int index = ListMenu_GetSelectedItem(mbk->SkinsList);

  FILELIST *files = (FILELIST *)List_Get(mbk->SkinList, index);

  wchar_t *AuthorName = WStringAlloc(100);
  int file = _fopen(files->fpath, files->fname, FSX_O_RDONLY, (FSX_S_IREAD | FSX_S_IWRITE), 0);
  if (file >= 0)
  {
    SkinData *SData = (SkinData *)malloc(sizeof(SkinData));
    memset(SData, NULL, sizeof(SkinData));
    fread(file, SData, sizeof(SkinData));

    wstrcpy(AuthorName, SData->Author);
    fclose(file);
    mfree(SData);
  }
  wchar_t ustr[64];
  snwprintf(ustr, MAXELEMS(ustr), L"Skin created by: %ls", AuthorName);
  CreateMessageBox(EMPTY_TEXTID, TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN), 0, 0, mbk);
  WStringFree(AuthorName);
}

void SelectSkin_onEnterPressed(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  int index = ListMenu_GetSelectedItem(mbk->SkinsList);

  FILELIST *files = (FILELIST *)List_Get(mbk->SkinList, index);

  wstrcpy(mbk->fpath, files->fpath);
  wstrcpy(mbk->fname, files->fname);
  wstrcpy(mbk->sname, files->name);

  FSTAT STAT;
  fstat(mbk->fpath, mbk->fname, &STAT);
  if (STAT.fsize == NULL)
  {
    // goto config skin
    mbk->CreateNew = TRUE;
    Create_DialogNewSkin(mbk);
  }
  else
  {
    // show list menu to apply or edit
    mbk->CreateNew = FALSE;
    LoadSkinData(mbk, mbk->fpath, mbk->fname);
    Create_DialogApplySkin(mbk);
  }
}

TEXTID SelectSkin_GetTitle(int count)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"Total skins: %d", count);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

int SelectSkin_MainPage_EnterEvent(void *data, BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  int count = List_GetCount(mbk->SkinList);

  if (mbk->SkinsList = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetStyle(mbk->SkinsList, UI_OverlayStyle_TrueFullScreen);
    GUIObject_SetTitleType(mbk->SkinsList, UI_TitleMode_Large);
    GUIObject_SetTitleText(mbk->SkinsList, STR("Select Skin"));
    GUIObject_SetSecondRowTitleText(mbk->SkinsList, SelectSkin_GetTitle(count));

    ListMenu_SetItemCount(mbk->SkinsList, count);
    ListMenu_SetCursorToItem(mbk->SkinsList, 0);
    ListMenu_SetOnMessage(mbk->SkinsList, SelectSkin_OnMessage);
    ListMenu_SetNoItemText(mbk->SkinsList, STR("Empty"));

    if (count)
    {
      GUIObject_SoftKeys_SetText(mbk->SkinsList, ACTION_SELECT1, TEXT_USE);
      GUIObject_SoftKeys_SetAction(mbk->SkinsList, ACTION_SELECT1, SelectSkin_onEnterPressed);
      GUIObject_SoftKeys_SetText(mbk->SkinsList, 0, TEXT_EDIT);
      GUIObject_SoftKeys_SetAction(mbk->SkinsList, 0, SelectSkin_OnEdit);
      GUIObject_SoftKeys_SetText(mbk->SkinsList, 1, STR("Author"));
      GUIObject_SoftKeys_SetAction(mbk->SkinsList, 1, SelectSkin_OnAuthor);
    }
    GUIObject_SoftKeys_SetAction(mbk->SkinsList, ACTION_BACK, SelectSkin_OnBack);
    GUIObject_SoftKeys_SetAction(mbk->SkinsList, ACTION_LONG_BACK, SelectSkin_OnBack);

    GUIObject_Show(mbk->SkinsList);
  }

  return 1;
}

int SelectSkin_MainPage_ExitEvent(void *data, BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->SkinsList);
  Refresh_MusicApp(mbk);
  return 1;
}

int SelectSkin_BasePage_CancelEvent(void *data, BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  FreeBook(mbk);
  UI_Event(RETURN_TO_STANDBY_EVENT);
  return 1;
}

void SkinEditor_Destroy(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  DESTROY_GUI(mbk->SkinsList);
  DESTROY_GUI(mbk->DialogApplySkin);
  DESTROY_GUI(mbk->DialogNewSkin);
  DESTROY_GUI(mbk->InputAuthorName);
  DESTROY_GUI(mbk->color);
  DESTROY_GUI(mbk->coord);
  DESTROY_GUI(mbk->font_select);
  DESTROY_GUI(mbk->Alignment);
  DESTROY_GUI(mbk->ProgressBar);
  DESTROY_GUI(mbk->IconEdit);
  DESTROY_GUI(mbk->StringEdit);
  Destroy_TabGUI(mbk);

  Refresh_MusicApp(mbk);
  FreeList(mbk->SkinList, FilesFree);
}

SkinEditor_Book *Create_SkinEditor_Book()
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)malloc(sizeof(SkinEditor_Book));
  memset(mbk, NULL, sizeof(SkinEditor_Book));
  if (!CreateBook(mbk, SkinEditor_Destroy, &SkinEditor_Base_Page, SkinEditorBook_Name, NO_BOOK_ID, NULL))
  {
    mfree(mbk);
    return NULL;
  }
  mbk->SkinsList = NULL;
  mbk->DialogApplySkin = NULL;
  mbk->DialogNewSkin = NULL;
  mbk->DialogSaveSkin = NULL;
  mbk->InputAuthorName = NULL;
  mbk->Main_Tab = NULL;
  mbk->Tab_Portrait = NULL;
  mbk->Tab_Landscape = NULL;
  mbk->Tab_PlayerGUI = NULL;
  mbk->color = NULL;
  mbk->coord = NULL;
  mbk->font_select = NULL;
  mbk->Alignment = NULL;
  mbk->ProgressBar = NULL;
  mbk->IconEdit = NULL;
  mbk->StringEdit = NULL;
  mbk->SkinList = NULL;
  return mbk;
}

void debug_skins(wchar_t *Folder)
{
  void *dir = w_diropen(Folder);
  if (dir)
  {
    wchar_t *next;
    w_chdir(Folder);
    while (next = w_dirread(dir))
    {
      if (!IsDir(next))
      {
        debug_printf("\nFiles: %ls", next);
      }
      else
      {
        debug_printf("\nFolder: %ls", next);
      }
    }
    w_dirclose(dir);
  }
}

void Enter_SkinEditor(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;

  SkinEditor_Book *mbk = Create_SkinEditor_Book();
  if (mbk)
  {
    mbk->SkinList = LoadFiles(SKIN_PATH_INTERNAL);
    BookObj_GotoPage(mbk, &SkinEditor_Main_Page);
  }
}
