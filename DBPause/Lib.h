#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    void GUIObject_SoftKeys_SetVisible(GUI *, u16 actionID, BOOL);
    SUB_EXECUTE *BrowserItem_Get_SUB_EXECUTE(BOOK *BrowserItemBook);
}

#endif
