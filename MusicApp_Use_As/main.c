#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\MusicApplication_book.h"

#include "Lib.h"
#include "main.h"

const int items_text[] =
    {
        RINGTONE_TXT,
        MESSAGEALERT_TXT,
        ALARMSIGNAL_TXT,
        CONTACTSIGNAL_TXT};

void onBackGui(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  FREE_GUI(pMusicBook->Gui_submenu);
}

void CreateFeedBack(BOOK *book, TEXTID TextID)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  FREE_GUI(pMusicBook->Gui_submenu);

  if (pMusicBook->Gui_submenu = TextFeedbackWindow(pMusicBook, UIDisplay_Main))
  {
    Feedback_SetTextExtended(pMusicBook->Gui_submenu, TextID, 0);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_BACK, onBackGui);
    Feedback_CloseAction(pMusicBook->Gui_submenu, ACTION_BACK);
    GUIObject_Show(pMusicBook->Gui_submenu);
  }
}

void SetRingtone(BOOK *book, wchar_t *path, wchar_t *name)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  SETTING_RINGTYPESOUNDFILE_SET(SYNC, -1, NULL, path, name, &error_code);
  CreateFeedBack(book, RING_CHANGED_TXT);
}

void SetSMSAlert(BOOK *book, wchar_t *path, wchar_t *name)
{
  Sound_SetMessageAlert(path, name);
  CreateFeedBack(book, MESSAGE_CHANGED_TXT);
}

void onSelectGui(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;

  wchar_t *path = FILEITEM_GetPath(pMusicBook->CurrentTrack->file_item);
  wchar_t *name = FILEITEM_GetFname(pMusicBook->CurrentTrack->file_item);

  int item = ListMenu_GetSelectedItem(pMusicBook->Gui_submenu);
  if (item == 0)
    SetRingtone(pMusicBook, path, name);
  else if (item == 1)
    SetSMSAlert(pMusicBook, path, name);
  else if (item == 2)
    Sound_SetAlarmsignal(pMusicBook, 1, path, name);
  else
  {
    Media_AddToContact(BookObj_GetBookID(pMusicBook), path, wstrlen(path), name, wstrlen(name), 0);
    FREE_GUI(pMusicBook->Gui_submenu);
  }
}

int pg_MusicApplication_UseAsFile__EnterAction(void *Data, BOOK *book)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  FREE_GUI(pMusicBook->Gui_submenu);

  if (pMusicBook->Gui_submenu = CreateListMenu(pMusicBook, UIDisplay_Main))
  {
    ListMenu_SetItemCount(pMusicBook->Gui_submenu, 4);
    ListMenu_SetCursorToItem(pMusicBook->Gui_submenu, 0);
    ListMenu_SetHotkeyMode(pMusicBook->Gui_submenu, LKHM_SHORTCUT);
    ListMenu_SetTexts(pMusicBook->Gui_submenu, (int *)items_text, 4);
    GUIObject_SetTitleText(pMusicBook->Gui_submenu, USE_AS_TXT);
    GUIObject_SetStyle(pMusicBook->Gui_submenu, UI_OverlayStyle_PopupNoFrame);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_SELECT1, onSelectGui);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_BACK, MusicApp_PrevAction);
    GUIObject_SoftKeys_SetAction(pMusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApp_CancelAction);
    GUIObject_Show(pMusicBook->Gui_submenu);
  }

  return 1;
}

const PAGE_MSG MusicApplication_UseAsFile[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_UseAsFile__EnterAction,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousAction,
        CANCEL_EVENT, pg_MusicApplication_CancelAction,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousAction,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitAction,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_UseAsFile_Page = {"MusicApplication_FileUseAs_Page", NULL, MusicApplication_UseAsFile};

void Call_UseAsPage(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
#if defined(DB3150v1)
  pMusicBook->unk_0x75 = TRUE;
#elif defined(DB3350) || defined(DB3150v2)
  pMusicBook->unk_0x94 = TRUE;
#endif
  BookObj_CallPage(pMusicBook, &MusicApplication_UseAsFile_Page);
}

extern "C" void create_new_softkeys(GUI *gui)
{
  GUIObject_SoftKeys_SetItemAsSubItem(gui, ACTION_MP_FILE, ACTION_MP_USE_AS);
  GUIObject_SoftKeys_SetAction(gui, ACTION_MP_USE_AS, Call_UseAsPage);
  GUIObject_SoftKeys_SetText(gui, ACTION_MP_USE_AS, USE_AS_TXT);
#ifndef DB3350
  MediaPlayer_SoftKeys_SetItemAsSubItem(gui, ACTION_MP_FILE, ACTION_MP_USE_AS);
  MediaPlayer_SoftKeys_SetAction(gui, ACTION_MP_USE_AS, Call_UseAsPage);
  MediaPlayer_SoftKeys_SetText(gui, ACTION_MP_USE_AS, USE_AS_TXT);
#endif
}
