#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void debug_printf(const char *fmt, ...);
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
    void *memset(void *mem, char chr, int size);
    OSADDRESS get_envp(PROCESS pid, char *name);
    OSBOOLEAN set_envp(PROCESS pid, char *name, OSADDRESS value);

    void BookObj_GotoPage(BOOK *book, const PAGE_DESC *page);

    GUI *CreateYesNoQuestion(BOOK *book, int display);
    void YesNoQuestion_SetQuestionText(GUI *, TEXTID);
    void YesNoQuestion_SetDescriptionText(GUI *, TEXTID);
    void YesNoQuestion_SetIcon(GUI *, IMAGEID);
    void GUIObject_Show(GUI *);
    GUI *GUIObject_Destroy(GUI *);
    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);

    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);
    int DataBrowser_ItemDesc_CheckFileToCopyMove(FILEITEM *);

    void FileDelete(wchar_t *path, wchar_t *filename, int *error);
    BOOL FSX_IsFileExists(wchar_t *pDir, wchar_t *pFile);
    wchar_t *FSX_MakeFullPath(wchar_t *pDir, wchar_t *pFile);
    void FSX_FreeFullPath(wchar_t *fullpath);
    int FSX_Attribute(const wchar_t *pDir, const wchar_t *pFile, unsigned long *pAttr, int action);
    wchar_t *MakeFullPath(wchar_t *pDir, wchar_t *pFile);
};

#endif
