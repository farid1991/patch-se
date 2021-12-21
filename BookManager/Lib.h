#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
#if defined(DB2010)
    void *memalloc(int size, int f1, int f2, const char *fname, int fline);
    void memfree(void *mem, const char *fname, int fline);
#elif defined(DB2020)
    void *memalloc(int zero, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
#elif defined(A2)
    void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
#endif

    PROCESS current_process(void);
    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);
    PROCESS get_bid(PROCESS pid);

    void debug_printf(const char *fmt, ...);
    void *memset(void *mem, char chr, int size);
    int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

    int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
    int fclose(int file);
    int fread(int file, void *ptr, int size);
    int fwrite(int file, const void *ptr, int size);
    int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);

    void FreeBook(BOOK *book);
    void UI_Event(int event);
    void UI_Event_toBookID(int event, int BookID);
    int BookObj_GetBookID(BOOK *book);
    void BookObj_SetFocus(BOOK *book, int display);
    UI_APP_SESSION *BookObj_GetSession(BOOK *book);
    int root_list_get_session_count(void);
    UI_APP_SESSION *root_list_get_session(int num_session);

    int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
    int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
    char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
    void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);
    void GUIObject_SoftKeys_SetItemOnKey(GUI *, u16 actionID, int key, int mode);
    void GUIObject_SoftKeys_ExecuteAction(GUI *, u16 actionID);

    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
    void TextID_GetString(TEXTID, char *str, int maxlen);

    GUI_LIST *CreateListMenu(BOOK *, int display);
    void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
    void ListMenu_SetItemCount(GUI_LIST *, int item_count);
    void ListMenu_SetItemStyle(GUI_LIST *, int style);
    void ListMenu_SetCursorToItem(GUI_LIST *, int item);
    void ListMenu_SetBackgroundImage(GUI_LIST *, IMAGEID);
    int ListMenu_GetSelectedItem(GUI_LIST *);
    void ListMenu_DestroyItems(GUI_LIST *);

    void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
    GUI *GUIObject_Destroy(GUI *);
    void GUIObject_Show(GUI *);
    void GUIObject_SetTitleType(GUI *, int type);
    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_SetSecondRowTitleText(GUI *, TEXTID);

    void TabMenuBar_SetTabGui(GUI_TABMENUBAR *, int tab, GUI *);
    int TabMenuBar_GetFocusedTab(GUI_TABMENUBAR *);
    void TabMenuBar_SetTabTitle(GUI_TABMENUBAR *, int tab_num, TEXTID);
    void GUIObject_TabTitleRemove(GUI *, BOOL);

    int strcmp(const char *str1, const char *str2);
    int strlen(const char *str);
    char *strstr(const char *str1, const char *str2);
    char *strcpy(char *dest, const char *source);
    wchar_t *str2wstr(wchar_t *wstr, const char *str);
    int strncmp(const char *s1, const char *s2, int len);
    int wstrncmp(const wchar_t *, const wchar_t *, int);
    int wstrlen(const wchar_t *wstr);

    int JavaDialog_Open(int unk1, char *unk2, void **JavaDesc);
    void JavaDialog_Close(int unk1);
    int JavaAppDesc_GetFirstApp(void *JavaDesc);
    int JavaAppDesc_GetNextApp(void *JavaDesc);
    int JavaAppDesc_GetJavaAppInfo(void *JavaDesc, int ID, wchar_t **wstr);
    int JavaApp_LogoImageID_Get(wchar_t *fullpath, IMAGEID *);
    // TEXTID JavaSession_GetName(void); //nullsub(ret 0x6FFFFFFF)

    int iconidname2id(const wchar_t *idname, int maxnamelen, int *id);

    int IsRightNowBook(BOOK *book);
    int IsVolumeControllerBook(BOOK *book);
    BOOK *Find_StandbyBook(void);

    LIST *List_Create(void);
    int List_InsertFirst(LIST *lst, void *item);
    void *List_Get(LIST *lst, int index);
    int List_GetCount(LIST *);
    void List_Destroy(LIST *lst);
    void List_DestroyElements(LIST *lst, int (*cmp_proc)(void *item), void (*free_proc)(void *item));

    char *manifest_GetParam(const char *buf, const char *param_name, int unk);
    int GetFreeBytesOnHeap(void);
    int NewEvent_GetCount(void);
};

#endif
