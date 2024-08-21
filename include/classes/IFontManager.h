#ifndef _IFONTMANAGER_H_
#define _IFONTMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\UIFont_types.h"

#include "IRichTextLayout.h"
#include "IFontStyleManager.h"

class IFont : public IUnknown
{
public:
  virtual int GetFace(TUIFontFace *buf);
  virtual int GetSize(TUIFontSize *buf);
  virtual int GetStyle(TUIFontStyle *buf);
  virtual int GetFontAscent(FSint32 *pAscent);
  virtual int GetFontHeight(FSint32 *font_size);
  virtual int IsBold();
  virtual int IsItalic();
  virtual int IsPlain();
  virtual int IsUnderlined();
  virtual int GetFontStyle(IFontStyle *pIUIFontStyle);
};

class IFontFactory : public IUnknown
{
public:
  virtual int GetFont(TUIFontFace Face, TUIFontSize Size, TUIFontStyle Style, IFont **pFont);
  virtual int GetDefaultFont(IFont **pFont);
  virtual int GetDefaultFontSettings(TUIFontSize Size, TUIFontData *pFontData);
  virtual int CreateDefaultFont(TUIFontData *pfontData, IFont **pFont);
  virtual int CreateFontFromFamilyName(IUnknown *pIFamilyName, TUIFontData *pfontData, IFont **pFont);
  virtual int CreateFontFromFile(IUnknown *pIFullPath, TUIFontData *pfontData, IFont **pFont);
};

class IFontManager : public IUnknown
{
public:
  virtual void GetFontFactory(IFontFactory **pFontFactory);
};

#endif
