#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
    void *memset(void *mem, char chr, int size);
    int memcpy(void *dest, const void *source, int cnt);

    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);

    void Timer_ReSet(u16 *timer, int time, TIMERPROC onTimer, LPARAM lparam);
    u16 Timer_Set(int time, TIMERPROC onTimer, LPARAM lparam);
    void Timer_Kill(u16 *timerID);

    TEXTID TextID_CreateIntegerID(int num);
    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
    void TextID_GetString(TEXTID, char *str, int maxlen);
    int TextID_GetWString(TEXTID, wchar_t *dest, int maxlen);
    int TextID_GetLength(TEXTID);
    void TextID_Destroy(TEXTID);
    TEXTID TextID_Copy(TEXTID);

    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);
    void BookObj_ReturnPage(BOOK *book, int);

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
    void ListMenu_SetItemStyle(GUI_LIST *, int style);
    void ListMenu_SetTexts(GUI_LIST *, TEXTID *textids, int Count);
    void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
    void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));

    int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
    int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
    BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
    GUI *GUIonMessage_GetGui(GUI_MESSAGE *msg);
    int GUIonMessage_GetSelectedItem(GUI_MESSAGE *msg);
    int GUIonMessage_GetPrevSelectedItem(GUI_MESSAGE *msg);
    char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
    char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);
    char GUIonMessage_SetMenuItemInfoText(GUI_MESSAGE *msg, TEXTID);
    char GUIonMessage_SetMenuItemUnavailableText(GUI_MESSAGE *msg, TEXTID);
    void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);

    GUI *CreateTimeInputVA(int zero, ...);
    GUI *CreateTimeInput(BOOK *, int display);
    unsigned int TimeInput_GetTimeInt(GUI *);
    void TimeInput_SetTime(GUI *, TIME *, char *time_format);
    void TimeInput_SetEnableSec(GUI *, BOOL);
    void GUIInput_SetIcon(GUI *, IMAGEID);
    void TIME_SWAP(TIME *dest, TIME *source);

    void MediaPlayer_SoftKeys_SetText(GUI *player_gui, int actionID, TEXTID);
    void MediaPlayer_SoftKeys_SetAction(GUI *player_gui, int actionID, SKACTIONPROC proc);
    void MediaPlayer_SoftKeys_SetItemAsSubItem(GUI *player_gui, int item, int subitem);

    FILEITEM *SUB_EXECUTE_Get_FILEITEM(SUB_EXECUTE *);
    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);
    wchar_t *FSX_MakeFullPath(wchar_t *fpath, wchar_t *fname);
    void FSX_FreeFullPath(wchar_t *fullpath);

    BOOK *FindBook(IS_NEEDED_BOOK);
    int IsAudioPlayerBook(BOOK *book);
    int IsMusicApplication_Book(BOOK *book);

    void CreateToast(TEXTID header_text, TEXTID message_text, int style, int time, BOOK *book);

    void REQUEST_DATEANDTIME_GET(const int *sync, DATETIME *dt);
    int REQUEST_TIMEFORMAT_GET(const int *sync, char *);

    void debug_printf(const char *fmt, ...);
};

#endif
