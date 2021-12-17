#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
    void *memset(void *mem, char chr, int size);

    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);

    void Timer_ReSet(u16 *timer, int time, TIMERPROC onTimer, LPARAM lparam);
    // u16 Timer_Set(int time, TIMERPROC onTimer, LPARAM lparam);
    void Timer_Kill(u16 *timerID);

    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);

    void FreeBook(BOOK *book);
    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);

    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
    GUI *GUIObject_Destroy(GUI *);
    void GUIObject_Show(GUI *);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetItemAsSubItem(GUI *, u16 actionID, int subitem);
    void GUIObject_SoftKeys_SetActionAndText(GUI *gui, u16 actionID, SKACTIONPROC proc, TEXTID);
    void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);

    GUI_LIST *CreateListMenu(BOOK *, int display);
    int ListMenu_GetSelectedItem(GUI_LIST *);
    void ListMenu_SetItemCount(GUI_LIST *, int item_count);
    void ListMenu_SetCursorToItem(GUI_LIST *, int item);
    void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
    void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));

    int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
    int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
    char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);

    void MediaPlayer_SoftKeys_SetText(GUI *player_gui, int actionID, TEXTID);
    void MediaPlayer_SoftKeys_SetAction(GUI *player_gui, int actionID, SKACTIONPROC proc);
    void MediaPlayer_SoftKeys_SetItemAsSubItem(GUI *player_gui, int item, int subitem);


    BOOK *FindBook(IS_NEEDED_BOOK);
    // int IsAudioPlayerBook(BOOK *book);
    int IsMusicApplication_Book(BOOK *book);

    void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time, BOOK *book);


    void debug_printf(const char *fmt, ...);
};

#endif
