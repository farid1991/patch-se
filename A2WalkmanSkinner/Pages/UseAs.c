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
#include "..\\main.h"

#include "UseAs.h"

//==============================================================================

void onBackGui(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);
}

void CreateFeedBack(BOOK *book, TEXTID TextID)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);

  if (MusicBook->Gui_submenu = TextFeedbackWindow(MusicBook, UIDisplay_Main))
  {
    Feedback_SetTextExtended(MusicBook->Gui_submenu, TextID, 0);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, onBackGui);
    Feedback_CloseAction(MusicBook->Gui_submenu, ACTION_BACK);
    GUIObject_Show(MusicBook->Gui_submenu);
  }
}

void SetRingtone(BOOK *book, wchar_t *path, wchar_t *name)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  SETTING_RINGTYPESOUNDFILE_SET(SYNC, -1, NULL, path, name, &error_code);
  CreateFeedBack(book, TEXT_RING_CHANGED);
}

void SetSMSAlert(BOOK *book, wchar_t *path, wchar_t *name)
{
  Sound_SetMessageAlert(path, name);
  CreateFeedBack(book, TEXT_MESSAGE_CHANGED);
}

void onSelectGui(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

  wchar_t *path = FILEITEM_GetPath(MusicBook->CurrentTrack->file_item);
  wchar_t *name = FILEITEM_GetFname(MusicBook->CurrentTrack->file_item);

  switch (ListMenu_GetSelectedItem(MusicBook->Gui_submenu))
  {
  case 0:
    SetRingtone(MusicBook, path, name);
    break;
  case 1:
    SetSMSAlert(MusicBook, path, name);
    break;
  case 2:
    Sound_SetAlarmsignal(MusicBook, 1, path, name);
    break;
  case 3:
    Sound_AddToContact(BookObj_GetBookID(MusicBook), path, wstrlen(path), name, wstrlen(name), NULL);
    DESTROY_GUI(MusicBook->Gui_submenu);
    break;
  }
}

int pg_MusicApplication_UseAsFile__EnterEvent(void *Data, BOOK *book)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  DESTROY_GUI(MusicBook->Gui_submenu);

  if (MusicBook->Gui_submenu = CreateListMenu(MusicBook, UIDisplay_Main))
  {
    ListMenu_SetItemCount(MusicBook->Gui_submenu, 4);
    ListMenu_SetCursorToItem(MusicBook->Gui_submenu, 0);
    ListMenu_SetHotkeyMode(MusicBook->Gui_submenu, LKHM_SHORTCUT);
    ListMenu_SetTexts(MusicBook->Gui_submenu, (int *)items_text, 4);
    GUIObject_SetTitleText(MusicBook->Gui_submenu, TEXT_USE_AS);
    GUIObject_SetStyle(MusicBook->Gui_submenu, UI_OverlayStyle_PopupNoFrame);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, onSelectGui);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, MusicApplication_PrevAction);
    GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);
    GUIObject_Show(MusicBook->Gui_submenu);
  }
  return 1;
}

void Enter_UseAs(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  MusicBook->Callpage = TRUE;

  BookObj_CallPage(MusicBook, &MusicApplication_UseAsFile_Page);
}
