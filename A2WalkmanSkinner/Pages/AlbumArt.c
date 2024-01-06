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

  int settings_file = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (settings_file >= 0)
  {
    SKIN *current_skin = (SKIN *)malloc(sizeof(SKIN));
    memset(current_skin, NULL, sizeof(SKIN));
    fread(settings_file, current_skin, sizeof(SKIN));

    int skin_file = _fopen(current_skin->Path, current_skin->Name, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (skin_file >= 0)
    {
      WALKMAN_Skin *skin_data = (WALKMAN_Skin *)malloc(sizeof(WALKMAN_Skin));
      memset(skin_data, NULL, sizeof(WALKMAN_Skin));
      fread(skin_file, skin_data, sizeof(WALKMAN_Skin));

      if ((skin_data->Land_AlbumArtEnable) && (skin_data->AlbumArtEnable))
        ret = 0;
      else if ((!skin_data->Land_AlbumArtEnable) && (!skin_data->AlbumArtEnable))
        ret = 1;

      fclose(skin_file);
      mfree(skin_data);
    }
    fclose(settings_file);
    mfree(current_skin);
  }
  return ret;
}

void SetChecked(int item)
{
  Internal_Function *Data = Get_Internal_Function();

  int settings_file = _fopen(SKIN_PATH_INTERNAL, L"CurrentSkin", FSX_O_RDWR, FSX_S_IREAD | FSX_S_IWRITE, NULL);
  if (settings_file >= 0)
  {
    SKIN *current_skin = (SKIN *)malloc(sizeof(SKIN));
    memset(current_skin, NULL, sizeof(SKIN));
    fread(settings_file, current_skin, sizeof(SKIN));

    int skin_file = _fopen(current_skin->Path, current_skin->Name, FSX_O_RDWR, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (skin_file >= 0)
    {
      WALKMAN_Skin *skin_data = (WALKMAN_Skin *)malloc(sizeof(WALKMAN_Skin));
      memset(skin_data, NULL, sizeof(WALKMAN_Skin));
      fread(skin_file, skin_data, sizeof(WALKMAN_Skin));
      Data->skin_data = *skin_data;
      fclose(skin_file);
      mfree(skin_data);
    }

    switch (item)
    {
    case ITEM_ALBUMART:
      Data->skin_data.Land_AlbumArtEnable = TRUE;
      Data->skin_data.AlbumArtEnable = TRUE;
      break;
    case ITEM_OFF:
      Data->skin_data.Land_AlbumArtEnable = FALSE;
      Data->skin_data.AlbumArtEnable = FALSE;
      break;
    }

    // Disabled
    Data->skin_data.Land_VisualisationEnable = FALSE;
    Data->skin_data.VisualisationEnable = FALSE;

    skin_file = _fopen(current_skin->Path, current_skin->Name, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (skin_file >= 0)
    {
      WALKMAN_Skin *skin_data = (WALKMAN_Skin *)malloc(sizeof(WALKMAN_Skin));
      memset(skin_data, NULL, sizeof(WALKMAN_Skin));
      *skin_data = Data->skin_data;
      fwrite(skin_file, skin_data, sizeof(WALKMAN_Skin));
      fclose(skin_file);
      mfree(skin_data);
    }
    fclose(settings_file);
    mfree(current_skin);
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

void Select_AlbumArt_onBack(BOOK *book, GUI *gui)
{
#if defined(C901_R1GA028) || defined(C903_R1GA028) || defined(T715_R1GA026)
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);
#else
  MusicApplication_PrevAction(book, gui);
#endif
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
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, Select_AlbumArt_onBack);
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
