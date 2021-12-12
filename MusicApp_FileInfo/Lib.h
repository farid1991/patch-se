#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void BookObj_CallPage(BOOK *book, const PAGE_DESC *page);

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

    FILEITEM *SUB_EXECUTE_Get_FILEITEM(SUB_EXECUTE *);
    wchar_t *FILEITEM_GetFname(FILEITEM *);
    wchar_t *FILEITEM_GetPath(FILEITEM *);
    wchar_t *FSX_MakeFullPath(wchar_t *fpath, wchar_t *fname);
    void FSX_FreeFullPath(wchar_t *fullpath);

    void debug_printf(const char *fmt, ...);
};

#endif
