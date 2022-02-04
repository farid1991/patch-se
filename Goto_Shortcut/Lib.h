#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
#ifndef DB3350
#pragma swi_number = 0x10D
    __swi __arm int elfload(const wchar_t *filename, void *param1, void *param2, void *param3);
#endif
#if defined(DB2020)
    void *memalloc(int zero, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
#elif defined(A2)
    void *memalloc(int minus_one, int size, int f1, int f2, const char *fname, int fline);
    void memfree(int zero, void *mem, const char *fname, int fline);
#else
    void *memalloc(int size, int f1, int f2, const char *fname, int fline);
    void memfree(void *mem, const char *fname, int fline);
#endif

    void debug_printf(const char *fmt, ...);
    void *memset(void *mem, char chr, int size);
    int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);

    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);

    int _fopen(const wchar_t *filpath, const wchar_t *filname, unsigned int mode, unsigned int rights, FILELISTITEM *destfname);
    int fclose(int file);
    int fread(int file, void *ptr, int size);
    int fwrite(int file, const void *ptr, int size);
    int fstat(const wchar_t *path, const wchar_t *fname, FSTAT *fstat_stuct);
    int lseek(int file, int offset, int mode);
    int w_chdir(const wchar_t *path);
    int w_fopen(const wchar_t *name, int attr, int rights, int err);
    int w_fstat(const wchar_t *name, W_FSTAT *);
    int w_fwrite(int f, void *buf, int size);
    int w_fread(int f, void *buf, int size);
    int w_lseek(int f, int offs, int mode);
    int w_fclose(int f);
    int w_mkdir(const wchar_t *path, int mode);
    void *w_diropen(const wchar_t *dir);
    wchar_t *w_dirread(void *);
    int w_dirclose(void *);
    int w_rename(const wchar_t *dst, const wchar_t *src);
    int w_remove(const wchar_t *dir);

    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);
    int FSX_IsFileExists(wchar_t *path, wchar_t *name);
    wchar_t *FSX_MakeFullPath(wchar_t *path, wchar_t *name);
    void FSX_FreeFullPath(wchar_t *fullpath);

    void *DataBrowserDesc_Create(void);
    void DataBrowserDesc_SetItemStyle(void *DataBrowserDesc, int style);
    void DataBrowserDesc_SetHeaderText(void *DataBrowserDesc, TEXTID);
    void DataBrowserDesc_SetFolders(void *DataBrowserDesc, const wchar_t **FolderList);
    void DataBrowserDesc_SetOKSoftKeyText(void *DataBrowserDesc, TEXTID);
    void DataBrowser_Create(void *DataBrowserDesc);
    void DataBrowserDesc_Destroy(void *DataBrowserDesc);
    int DataBrowser_isFileInListExt(const wchar_t *ext_table, const wchar_t *path, const wchar_t *fname);
    void DataBrowserDesc_SetFoldersNumber(void *DataBrowserDesc, int state);
    void DataBrowserDesc_SetActions(void *DataBrowserDesc, char *actions);
    void DataBrowserDesc_SetSelectAction(void *DataBrowserDesc, int state);
    void DataBrowserDesc_SetSelectActionOnFolders(void *DataBrowserDesc, int state);
    void DataBrowserDesc_SetBookID(void *DataBrowserDesc, int BookID);
    void DataBrowserDesc_SetItemFilter(void *DataBrowserDesc, DB_FILE_FILTER);
    void DataBrowserDesc_SetOption(void *DataBrowserDesc, char *option);
    void DataBrowserDesc_SetOpenEmptyFolder(void *DataBrowserDesc, int state);
    void DataBrowserDesc_SetFileExtList(void *DataBrowserDesc, const wchar_t *ExtList);
    void DataBrowserDesc_Menu_AddFSFunctions(void *DataBrowserDesc, int);
    void DataBrowserDesc_Menu_AddNewFolder(void *DataBrowserDesc, int);
    void DataBrowserDesc_Menu_AddMarkFiles(void *DataBrowserDesc, int);

    TEXTID TextID_CreateIntegerID(int num);
    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
    void TextID_GetString(TEXTID, char *str, int maxlen);
    int TextID_GetWString(TEXTID, wchar_t *dest, int maxlen);
    int TextID_GetLength(TEXTID);
    void TextID_Destroy(TEXTID);
    TEXTID TextID_Copy(TEXTID);

    int strcmp(const char *str1, const char *str2);
    int strlen(const char *str);

    wchar_t *wstrcpy(wchar_t *dest, const wchar_t *source);
    wchar_t *wstrncpy(wchar_t *dest, const wchar_t *source, int maxlen);
    int wstrcmp(const wchar_t *wstr1, const wchar_t *wstr2);
    int wstrlen(const wchar_t *wstr);
    wchar_t *wstrrchr(const wchar_t *wstr, wchar_t wchar);
    int wstrcmpi(const wchar_t *ws1, const wchar_t *ws2);

    LIST *List_Create(void);
    void List_Destroy(LIST *lst);
    int List_InsertFirst(LIST *lst, void *item);
    int List_InsertLast(LIST *lst, void *item);
    void *List_Get(LIST *lst, int index);
    void *List_RemoveAt(LIST *lst, int index);
    void *List_RemoveFirst(LIST *lst);
    int List_GetCount(LIST *);
    void List_DestroyElements(LIST *lst, int (*cmp_proc)(void *item), void (*free_proc)(void *item));

    void UI_Event(int event);

    int CreateBook(BOOK *pbook, void (*onClose)(BOOK *), const PAGE_DESC *bp, const char *name, int ParentBookID, const APP_DESC *appdesc);
    void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
    void BookObj_ReturnPage(BOOK *book, int);
    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);
    void BookObj_SetFocus(BOOK *book, int display);
    void FreeBook(BOOK *book);
    BOOK *FindBook(IS_NEEDED_BOOK);
    int BookObj_GetBookID(BOOK *book);
    void UI_Event_toBookID(int event, int BookID);
    BOOK *MenuBook_Desktop(int mode, int BookID);
    wchar_t *MenuBook_Desktop_GetSelectedItemID(BOOK *MenuBook_Desktop);
    void BookObj_SoftKeys_SetAction(BOOK *book, int actionID, SKACTIONPROC proc);
    void BookObj_SoftKeys_SetText(BOOK *book, int actionID, TEXTID);
    TEXTID Shortcut_Get_MenuItemName(void *);
    IMAGEID Shortcut_Get_MenuItemIconID(void *);
    void Shortcut_Run(wchar_t *shortcut_name);

    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_Show(GUI *);
    void GUIObject_SetStyle(GUI *, int UI_OverlayStyle_t);
    GUI *GUIObject_Destroy(GUI *);
    DISP_OBJ *GUIObject_GetDispObject(GUI *);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetActionAndText(GUI *gui, u16 actionID, SKACTIONPROC proc, TEXTID);
    void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);

    GUI_LIST *CreateListMenu(BOOK *, int display);
    void ListMenu_SetOnMessage(GUI_LIST *, int (*proc)(GUI_MESSAGE *));
    void ListMenu_SetItemCount(GUI_LIST *, int item_count);
    void ListMenu_SetCursorToItem(GUI_LIST *, int item);
    int ListMenu_GetSelectedItem(GUI_LIST *);
    void ListMenu_SetItemStyle(GUI_LIST *, int style);
    int ListMenu_SetItemTextScroll(GUI_LIST *, int scroll);
    void ListMenu_SetHotkeyMode(GUI_LIST *, LISTMENU_HOTKEY_MODE);
    void ListMenu_SetNoItemText(GUI_LIST *, TEXTID);

    BOOK *GUIonMessage_GetBook(GUI_MESSAGE *msg);
    int GUIonMessage_GetMsg(GUI_MESSAGE *msg);
    int GUIonMessage_GetCreatedItemIndex(GUI_MESSAGE *msg);
    char GUIonMessage_SetMenuItemText(GUI_MESSAGE *msg, TEXTID);
    void GUIonMessage_SetMenuItemIcon(GUI_MESSAGE *msg, int align, IMAGEID);
    char GUIonMessage_SetMenuItemSecondLineText(GUI_MESSAGE *msg, TEXTID);

    GUI *CreateStringInputVA(int, ...);
    GUI *CreateStringInput(BOOK *book);
    void StringInput_SetMode(GUI *, int mode);
    void StringInput_SetText(GUI *strinp, TEXTID);
    void StringInput_DispObject_SetText(DISP_OBJ *, TEXTID);
    void StringInput_SetMinLen(GUI *strinp, int len);
    void StringInput_SetMaxLen(GUI *strinp, int len);
    void StringInput_SetEnableEmptyText(GUI *strinp, BOOL state);
    void StringInput_SetActionOK(GUI *strinp, void (*proc)(BOOK *book, wchar_t *string, int len));
    void StringInput_SetActionBack(GUI *strinp, void (*proc)(BOOK *book, wchar_t *string, int len));
    int StringInput_GetStringAndLen(GUI *, wchar_t **, u16 *);
    void StringInput_MenuItem_SetPriority(GUI *strinp, int prio, int actionID);

    GUI *CreateYesNoQuestion(BOOK *book, int display);
    void YesNoQuestion_SetQuestionText(GUI *, TEXTID);
    void YesNoQuestion_SetDescriptionText(GUI *, TEXTID);
    void YesNoQuestion_SetIcon(GUI *, IMAGEID);

    void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time_in_ms, BOOK *book);

    int JavaDialog_Open(int unk1, char *unk2, void **JavaDesc);
    void JavaDialog_Close(int unk1);
    int JavaAppDesc_Get(int unk1, void **JavaDesc);
    int JavaAppDesc_GetFirstApp(void *JavaDesc);
    int JavaAppDesc_GetNextApp(void *JavaDesc);
    int JavaAppDesc_GetJavaAppID(void *JavaDesc);
    int JavaAppDesc_GetJavaAppInfo(void *JavaDesc, int ID, wchar_t **wstr);
    int JavaApp_LogoImageID_Get(wchar_t *fullpath, IMAGEID *);
    void REQUEST_UI_OAF_START_APPLICATION(const int *sync, int appID, char *flag);

    void ImageID_Free(IMAGEID);
};

#endif
