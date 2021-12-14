#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);

    void GUIObject_SoftKeys_SetAction(GUI *, u16 actionID, SKACTIONPROC proc);
    void GUIObject_SoftKeys_SetText(GUI *, u16 actionID, TEXTID);
    void GUIObject_SoftKeys_SetItemAsSubItem(GUI *, u16 actionID, int subitem);

    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);
    wchar_t *FSX_MakeFullPath(wchar_t *fpath, wchar_t *fname);
    void FSX_FreeFullPath(wchar_t *fullpath);

    void debug_printf(const char *fmt, ...);
};

#endif
