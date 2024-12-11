#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\AudioPlayerBook.h"

#include "data.h"
#include "main.h"
#include "skin_data.h"
#include "skin_list.h"
#include "skin_selector.h"

int SkinSelect_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    ADVPLAYER_DATA *data = env_data_get();
    SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)List_Get(data->skin_list, index);

    GUIonMessage_SetMenuItemText(msg, TextID_Create(skin->fname, ENC_UCS2, skin->name_len));
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SKINSELECT_LIST_ICN);
    GUIonMessage_SetMenuItemIcon(msg, AlignRight, SKINSELECT_ARROW_ICN);
    break;
  }
  return 1;
}

void SkinSelect_onSelectPressed(BOOK *book, GUI *gui)
{
  AudioPlayerBook *audio_book = (AudioPlayerBook *)book;
  int item = ListMenu_GetSelectedItem(audio_book->Gui_SubMenu);

  ADVPLAYER_DATA *data = env_data_get();
  if (data->skin_list)
  {
    SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)List_Get(data->skin_list, item);

    skin_data_path_save(skin->fpath);
#ifndef OLD_PLAYER
    skin_data_reload(audio_book, skin->fpath);
#endif

    skin_list_destroy(data->skin_list);
#ifdef OLD_PLAYER
    FreeBook(audio_book);
#else
    FREE_GUI(audio_book->Gui_SubMenu);

    BookObj_GotoPage(audio_book, page_MediaPlayer_Audio_Bk_Main);
#endif
  }
}

TEXTID GetTitleText(int count)
{
  char str[20];
  sprintf(str, "Total Skins: %d", count);
  return TextID_Create(str, ENC_LAT1, 20);
}

int pg_MediaPlayer_SkinSelector_EnterEvent(void *r0, BOOK *book)
{
  ADVPLAYER_DATA *data = env_data_get();
  if (data->skin_list)
  {
    skin_list_destroy(data->skin_list);
  }
  data->skin_list = skin_list_create(SKIN_PATH);
  int count = List_GetCount(data->skin_list);

  AudioPlayerBook *audio_book = (AudioPlayerBook *)book;
  FREE_GUI(audio_book->Gui_SubMenu);

  if (audio_book->Gui_SubMenu = CreateListMenu(audio_book, UIDisplay_Main))
  {
    ListMenu_SetItemCount(audio_book->Gui_SubMenu, count);
    ListMenu_SetCursorToItem(audio_book->Gui_SubMenu, 0);
    ListMenu_SetHotkeyMode(audio_book->Gui_SubMenu, LKHM_SHORTCUT);

    GUIObject_SetTitleType(audio_book->Gui_SubMenu, UI_TitleMode_Large);
    TEXTID title_txt = TextID_Create("Select Skin", ENC_LAT1, 12);
    GUIObject_SetTitleText(audio_book->Gui_SubMenu, title_txt);

    GUIObject_SetTitleTextAlign(audio_book->Gui_SubMenu, AlignLeft);
    GUIObject_SetSecondRowTitleText(audio_book->Gui_SubMenu, GetTitleText(count));
    GUIObject_SetStyle(audio_book->Gui_SubMenu, UI_OverlayStyle_FullScreenNoStatus);
    if (count)
    {
      ListMenu_SetOnMessage(audio_book->Gui_SubMenu, SkinSelect_OnMessage);
      if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_SubMenu))
        MediaPlayer_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_SELECT1, SkinSelect_onSelectPressed);
      else
        GUIObject_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_SELECT1, SkinSelect_onSelectPressed);
    }
    if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_SubMenu))
      MediaPlayer_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_BACK, MediaPlayer_Audio_ActionBack);
    else
      GUIObject_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_BACK, MediaPlayer_Audio_ActionBack);

    if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_SubMenu))
      MediaPlayer_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_LONG_BACK, MediaPlayer_Audio_ActionLongBack);
    else
      GUIObject_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_LONG_BACK, MediaPlayer_Audio_ActionLongBack);
    GUIObject_Show(audio_book->Gui_SubMenu);
  }
  else
  {
    FreeBook(audio_book);
  }
  return 1;
}
