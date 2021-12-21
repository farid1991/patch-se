#ifndef _LIB_H_
#define _LIB_H_

#include "temp\target.h"

extern "C"
{
    int AB_GETNBROFITEMS(int get_from, int sub_id);
    int snwprintf(wchar_t *buffer, int size, const wchar_t *fmt, ...);
    void GUIObject_SetTitleType(GUI *, int type);
    TEXTID TextID_Create(const void *wstr, int TEXT_ENCODING, int len);
    void GUIObject_SetTitleIcon(GUI *, IMAGEID);
    void GUIObject_SetTitleText(GUI *, TEXTID);
    void GUIObject_SetSecondRowTitleText(GUI *, TEXTID);
};

#endif
