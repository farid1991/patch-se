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

/**
 *  The font style manager object.
 *
 *  This class manages a list of IUIFontStyle objects.  IUIFontStyle objects
 *  are added to the managed list from the IUIFontStyleManager::GetFontStyle
 *  method, when necessary, or users can also add IUIFontStyle objects of
 *  their own with IUIFontStyleManager::AddFontStyle.  Each managed IUIFontStyle
 *  can be retrieved from the manager.  This class allows efficient
 *  sharing of IUIFontStyle objects.
 */

class IFontStyleManager : public IUnknown
{
public:
    virtual int GetDefaultFontSettings(TUIFontParamSize size, TUIFontData *pFontData);
    virtual int GetFontStyle(IUnknown *pIUIFontResource, TUIFontData *pFontData, IUnknown **ppIUIFontStyle);
};

#endif
