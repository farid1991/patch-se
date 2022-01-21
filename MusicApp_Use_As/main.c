#include "temp\target.h"

#include "..\\include\Types.h"
#if defined(DB3150v1)
#include "..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\include\book\DB3210\MusicApplication_Book.h"
#elif defined(DB3350)
#include "..\\include\book\DB3350\MusicApplication_Book.h"
#endif

#include "Lib.h"
#include "main.h"

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

    if (pMusicBook->CurrentTrack)
    {
        wchar_t *path = FILEITEM_GetPath(pMusicBook->CurrentTrack->file_item);
        wchar_t *name = FILEITEM_GetFname(pMusicBook->CurrentTrack->file_item);

        int item = ListMenu_GetSelectedItem(pMusicBook->Gui_submenu);
        if (item == ITEM_1)
            SetRingtone(pMusicBook, path, name);
        else if (item == ITEM_2)
            SetSMSAlert(pMusicBook, path, name);
        else if (item == ITEM_3)
            Sound_SetAlarmsignal(pMusicBook, 1, path, name);
        else if (item == ITEM_4)
        {
            Media_AddToContact(BookObj_GetBookID(pMusicBook), path, wstrlen(path), name, wstrlen(name), 0);
            onBackGui(pMusicBook, gui);
        }
    }
    else
    {
        pMusicBook->ErrorText = ERROR_TXT;
        BookObj_CallPage(pMusicBook, page_MusicApplication_ShowMessage);
    }
}

int pg_MusicApplication_UseAsFile_EnterEvent(void *Data, BOOK *book)
{
    MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;

    if (pMusicBook->Gui_submenu = CreateListMenu(pMusicBook, UIDisplay_Main))
    {
        ListMenu_SetItemCount(pMusicBook->Gui_submenu, ITEM_LAST);
        ListMenu_SetCursorToItem(pMusicBook->Gui_submenu, ITEM_1);
        ListMenu_SetHotkeyMode(pMusicBook->Gui_submenu, LKHM_SHORTCUT);
        ListMenu_SetTexts(pMusicBook->Gui_submenu, (int *)items_text, ITEM_LAST);
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
        PAGE_ENTER_EVENT, pg_MusicApplication_UseAsFile_EnterEvent,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
        CANCEL_EVENT, pg_MusicApplication_CancelEvent,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
        NIL_EVENT, NULL
    };

const PAGE_DESC MusicApplication_UseAsFile_Page = {"MusicApplication_FileUseAs_Page", NULL, MusicApplication_UseAsFile};

void Call_UseAsPage(BOOK *book, GUI *gui)
{
    MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
    pMusicBook->Callpage = TRUE;
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
