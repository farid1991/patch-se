#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);
    int BookObj_GetBookID(BOOK *book);

    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
    GUI *GUIObject_Destroy(GUI *);
    void GUIObject_Show(GUI *);
    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetItemAsSubItem(GUI *, u16 actionID, int subitem);

    void MediaPlayer_SoftKeys_SetText(GUI *player_gui, int actionID, TEXTID);
    void MediaPlayer_SoftKeys_SetAction(GUI *player_gui, int actionID, SKACTIONPROC proc);
    void MediaPlayer_SoftKeys_SetItemAsSubItem(GUI *player_gui, int item, int subitem);

    GUI_LIST *CreateListMenu(BOOK *, int display);
    int ListMenu_GetSelectedItem(GUI_LIST *);
    void ListMenu_SetItemCount(GUI_LIST *, int item_count);
    void ListMenu_SetCursorToItem(GUI_LIST *, int item);
    // void ListMenu_SetItemStyle(GUI_LIST *, int style);
    void ListMenu_SetTexts(GUI_LIST *, TEXTID *textids, int Count);
    void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);

    GUI_FEEDBACK *TextFeedbackWindow(BOOK *book, int zero);
    void Feedback_SetTextExtended(GUI_FEEDBACK *, TEXTID text, int where);
    void Feedback_CloseAction(GUI_FEEDBACK *, u16 actionID);
    
    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);

    int SETTING_RINGTYPESOUNDFILE_SET(const int *sync, int minus_one, char zero, wchar_t *path, wchar_t *name, char *error);
    int Sound_SetRingsignal(wchar_t *fpath, wchar_t *fname);
    int Sound_SetMessageAlert(wchar_t *fpath, wchar_t *fname);
    void Sound_SetAlarmsignal(BOOK *book, int one, wchar_t *fpath, wchar_t *fname);
    void Media_AddToContact(int BookID, wchar_t *fpath, int len_path, wchar_t *fname, int len_name, int type);

    int wstrlen(const wchar_t *wstr);
};

#endif
