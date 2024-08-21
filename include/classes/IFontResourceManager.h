#ifndef _IFONTRESOURCEMANAGER_H_
#define _IFONTRESOURCEMANAGER_H_

#include "..\types\Basic_types.h"

typedef enum
{
  UIFontResourceStylePlain,     ///< Regular system font
  UIFontResourceStyleBold,      ///< Bold system font
  UIFontResourceStyleItalic,    ///< Italic system font
  UIFontResourceStyleBoldItalic ///< Bold italic system font
} TUIFontResourceStyle;

class IFontResource : public IUnknown
{
public:
  virtual int GetName(IUnknown **ppIString);
  virtual int GetStyle(TUIFontResourceStyle *pStyle);
};

class IFontResourceManager : public IUnknown
{
public:
  virtual int GetDefaultFont(TUIFontResourceStyle style, IFontResource **ppIFontResource);
  virtual int GetFontFromFamilyName(IUnknown *pIFamilyName, TUIFontResourceStyle style, IFontResource **ppIFontResource);
  virtual int AddFontResource(IUnknown *pIFamilyName, IUnknown *pIFontPath, TUIFontResourceStyle style, IFontResource **ppIFontResource);
  virtual int SetDefaultFont(IUnknown *pIFamilyName);
  virtual int GetFontFromFile(IUnknown *pIPath, IFontResource **ppIFontResource);
};

#endif
