#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
    void *memset(void *mem, char chr, int size);

    int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
    int fclose(int file);
    int fread(int file, void *ptr, int size);
    int fwrite(int file, const void *ptr, int size);
    int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);

    LIST *List_Create(void);
    void List_Destroy(LIST *lst);
    int List_GetCount(LIST *);
    void *List_Get(LIST *lst, int index);
    int List_InsertLast(LIST *lst, void *item);
    void List_DestroyElements(LIST *lst, int (*cmp_proc)(void *item), void (*free_proc)(void *item));

    TEXTID TextID_CreateIntegerID(int num);
    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
    void TextID_GetString(TEXTID, char *str, int maxlen);

    int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
    void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
    void BookObj_ReturnPage(BOOK *book, int);
    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);
    void FreeBook(BOOK *book);

    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
    GUI *GUIObject_Destroy(GUI *);
    void GUIObject_Show(GUI *);
    DISP_OBJ *GUIObject_GetDispObject(GUI *);
    LIST *DispObject_SoftKeys_GetList(DISP_OBJ *, BOOK *book, char __zero);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetItemAsSubItem(GUI *, u16 actionID, int subitem);
    void GUIObject_SoftKeys_ExecuteAction(GUI *, u16 actionID);

    GUI_LIST *CreateListMenu(BOOK *, int display);
    int ListMenu_GetSelectedItem(GUI_LIST *);
    void ListMenu_SetItemCount(GUI_LIST *, int item_count);
    void ListMenu_SetCursorToItem(GUI_LIST *, int item);
    void ListMenu_SetItemStyle(GUI_LIST *, int style);
    void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
    void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
    void ListMenu_DestroyItems(GUI_LIST *);

    int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
    int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
    BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
    char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
    char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);

    GUI_ONEOFMANY *CreateOneOfMany(BOOK *book);
    void OneOfMany_SetItemCount(GUI_ONEOFMANY *, int count);
    void OneOfMany_SetChecked(GUI_ONEOFMANY *, int checked);
    int OneOfMany_GetSelected(GUI_ONEOFMANY *);
    void OneOfMany_SetOnMessage(GUI_ONEOFMANY *, int (*proc)(GUI_MESSAGE *));

    void MediaPlayer_SoftKeys_SetText(GUI *player_gui, int actionID, TEXTID);
    void MediaPlayer_SoftKeys_SetAction(GUI *player_gui, int actionID, SKACTIONPROC proc);
    void MediaPlayer_SoftKeys_SetItemAsSubItem(GUI *player_gui, int item, int subitem);

     void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time_in_ms, BOOK *book);
     void debug_printf(const char *fmt, ...);
};

#endif
