#ifndef _IFONTSTYLEMANAGER_H_
#define _IFONTSTYLEMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\UIFont_types.h"

#include "IFontManager.h"
#include "IFontResourceManager.h"

typedef enum
{
  UIFontParamSizeNone,
  UIFontParamSizeMedium,
  UIFontParamSizeSmall,
  UIFontParamSizeLarge
} TUIFontParamSize;

class IFontStyle : public IUnknown
{
public:
  virtual int GetAscender(TFloat *pAscender);
  virtual int GetDescender(TFloat *pDescender);
  virtual int GetLeading(TFloat *pLeading);
  virtual int GetXSize(TFloat *pXSize);
  virtual int GetYSize(TFloat *pYSize);
  virtual int MapChar(FSint32 charID, FSint32 *pGlyphID);
  virtual int GetGlyphMetrics(FSint32 glyphID, IUnknown *pMetrics);
  virtual int GetFont(IFontResource **ppIFontResource);
  virtual int GetFontParams(TUIFontData *pFontData);
};

class IFontStyleManager : public IUnknown
{
public:
  virtual int GetDefaultFontSettings(TUIFontParamSize size, TUIFontData *pFontData);
  virtual int GetFontStyle(IFontResource *pIFontResource, TUIFontData *pFontData, IFontStyle **ppIFontStyle);
};

#endif
