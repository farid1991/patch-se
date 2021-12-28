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
    void *memcalloc(int minus_one, int size, int NoOfItems, int f1, int f2, const char *fname, int fline);
#endif
    void *memset(void *mem, char chr, int size);
    void debug_printf(const char *fmt, ...);
    int List_GetCount(LIST *);

    PROCESS current_process(void);
    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);
    PROCESS get_bid(PROCESS pid);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetItemOnKey(GUI *, u16 actionID, int key, int mode);
    GUI *GUIObject_Destroy(GUI *);
    void GUIObject_Show(GUI *);

    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);

    void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);
    void BookObj_ReturnPage(BOOK *book, int);
    int BookObj_GetBookID(BOOK *book);
    void UI_Event_toBookID(int event, int BookID);
    BOOK *MainDisplay_GetTopBook(void);

    int FILEITEM_SetFname(FILEITEM *, const wchar_t *fname);
    int FILEITEM_SetPath(FILEITEM *, const wchar_t *fpath);
    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);
    int FILEITEM_SetFnameAndContentType(FILEITEM *, const wchar_t *fname);
    int FILEITEM_SetPathAndContentType(FILEITEM *, const wchar_t *fpath);
    int DataBrowser_ItemDesc_CheckFileToCopyMove(FILEITEM *);
    int GetMemoryStickStatus(void);

    GUI *CreateYesNoQuestion(BOOK *book, int display);
    void YesNoQuestion_SetQuestionText(GUI *, TEXTID);
    void YesNoQuestion_SetDescriptionText(GUI *, TEXTID);
    void YesNoQuestion_SetIcon(GUI *, IMAGEID);

    void CreatePasswordInputWindow(int BookID, int mode_0, int password_2, TEXTID title); // password: 2 - phone
    void CreateMessageBox(TEXTID header_text, TEXTID message_text, int style, int time_in_ms, BOOK *book);

    void *DataBrowserDesc_Create(void);
    void DataBrowserDesc_SetItemStyle(void *DataBrowserDesc, int style);
    void DataBrowserDesc_SetHeaderText(void *DataBrowserDesc, TEXTID);
    void DataBrowserDesc_SetFolders(void *DataBrowserDesc, const wchar_t **FolderList);
    void DataBrowserDesc_SetOKSoftKeyText(void *DataBrowserDesc, TEXTID);
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
    void DataBrowser_Create(void *DataBrowserDesc);
    void DataBrowserDesc_Destroy(void *DataBrowserDesc);

    int FileMove(wchar_t *src_path, wchar_t *src_name, wchar_t *dest_path, wchar_t *dest_name, int);
    void FileDelete(wchar_t *path, wchar_t *filename, int *error);
};

#endif
