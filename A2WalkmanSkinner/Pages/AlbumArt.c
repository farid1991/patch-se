#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "..\\Function.h"
#include "..\\LNG.h"
#include "..\\main.h"
#include "..\\String.h"

#include "..\\Pages\Skins.h"

#include "AlbumArt.h"

//==============================================================================

int GetChecked()
{
  int ret = 0;

  int Lf;
  if ((Lf = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= 0)
  {
    SKIN *LData = (SKIN *)malloc(sizeof(SKIN));
    memset(LData, NULL, sizeof(SKIN));
    fread(Lf, LData, sizeof(SKIN));

    int f = _fopen(LData->Path, LData->Name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (f >= 0)
    {
      SkinData *PData = (SkinData *)malloc(sizeof(SkinData));
      memset(PData, NULL, sizeof(SkinData));
      fread(f, PData, sizeof(SkinData));

      if ((PData->Land_AlbumArtEnable) && (PData->AlbumArtEnable))
        ret = 0;
      else if ((!PData->Land_AlbumArtEnable) && (!PData->AlbumArtEnable))
        ret = 1;

      fclose(f);
      mfree(PData);
    }
    fclose(Lf);
    mfree(LData);
  }
  return ret;
}

void SetChecked(int item)
{
  Internal_Function *Data = Get_Internal_Function();

  int settings_file = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (settings_file >= 0)
  {
    SKIN *CurrentSkin = (SKIN *)malloc(sizeof(SKIN));
    memset(CurrentSkin, NULL, sizeof(SKIN));
    fread(settings_file, CurrentSkin, sizeof(SKIN));

    int skin_file;

    skin_file = _fopen(CurrentSkin->Path, CurrentSkin->Name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (skin_file >= 0)
    {
      SkinData *SData = (SkinData *)malloc(sizeof(SkinData));
      memset(SData, NULL, sizeof(SkinData));
      fread(skin_file, SData, sizeof(SkinData));
      Data->SData = *SData;
      fclose(skin_file);
      mfree(SData);
    }

    switch (item)
    {
    case ITEM_ALBUMART:
      Data->SData.Land_AlbumArtEnable = TRUE;
      Data->SData.AlbumArtEnable = TRUE;
      break;
    case ITEM_OFF:
      Data->SData.Land_AlbumArtEnable = FALSE;
      Data->SData.AlbumArtEnable = FALSE;
      break;
    }

    // Disabled
    Data->SData.Land_VisualisationEnable = FALSE;
    Data->SData.VisualisationEnable = FALSE;
    
    skin_file = _fopen(CurrentSkin->Path, CurrentSkin->Name, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (skin_file >= 0)
    {
      SkinData *SData = (SkinData *)malloc(sizeof(SkinData));
      memset(SData, NULL, sizeof(SkinData));
      *SData = Data->SData;
      fwrite(skin_file, SData, sizeof(SkinData));
      fclose(skin_file);
      mfree(SData);
    }
    fclose(settings_file);
    mfree(CurrentSkin);
  }

  if (Data->Portrait)
  {
    LoadPortraitData();
  }
  else
  {
    LoadLandscapeData();
  }

  RefreshScreen();
}

void Select_AlbumArt_onSelect(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  int item = ListMenu_GetSelectedItem(MusicBook->Gui_submenu);

  SetChecked(item);
  DESTROY_GUI(MusicBook->Gui_submenu);
}

int Select_AlbumArt_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case ITEM_ALBUMART:
      GUIonMessage_SetMenuItemText(msg, TEXT_ON);
      break;
    case ITEM_OFF:
      GUIonMessage_SetMenuItemText(msg, TEXT_OFF);
      break;
    }
  }
  return 1;
}

int pg_MusicApplication_Select_AlbumArt__EnterEvent(void *data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);

  if (MusicBook->Gui_submenu = CreateOneOfMany(MusicBook))
  {
    GUIObject_SetTitleText(MusicBook->Gui_submenu, TEXT_ALBUM_ART);
    GUIObject_SetStyle(MusicBook->Gui_submenu, UI_OverlayStyle_PopupNoFrame);
    OneOfMany_SetItemCount(MusicBook->Gui_submenu, ITEM_LAST);
    OneOfMany_SetOnMessage(MusicBook->Gui_submenu, Select_AlbumArt_onMessage);
    OneOfMany_SetChecked(MusicBook->Gui_submenu, GetChecked());
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, Select_AlbumArt_onSelect);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, MusicApplication_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);
    GUIObject_Show(MusicBook->Gui_submenu);
  }

  return 1;
}

void Enter_SelectAlbumArt(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;

  BookObj_CallPage(MusicBook, &page_Select_Album_Art);
}
