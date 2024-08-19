#ifndef _IFONTSTYLEMANAGER_H_
#define _IFONTSTYLEMANAGER_H_

#include "IFontManager.h"

typedef enum
{
    UIFontParamSizeNone,
    UIFontParamSizeMedium,
    UIFontParamSizeSmall,
    UIFontParamSizeLarge
} TUIFontParamSize;

class IFontStyleManager : public IUnknown
{
public:
    virtual int GetDefaultFontSettings(TUIFontParamSize size, TUIFontData *pFontData);
    virtual int GetFontStyle(IUnknown *pIUIFontResource, TUIFontData *pFontData, IUnknown **ppIUIFontStyle);
};

#endif
