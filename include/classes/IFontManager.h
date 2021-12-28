#ifndef _IFONTMANAGER_H_
#define _IFONTMANAGER_H_

#include "IUIRichTextLayoutOptions.h"

typedef unsigned short FUint16;
typedef FUint16 TUIRenderStyle;
/**
 *
 *  Typedef for text emphasis style
 *
 */
typedef enum
{
  UI_Emphasis_Normal,    ///< normal
  UI_Emphasis_Bold,      ///< bold
  UI_Emphasis_Italic,    ///< italic
  UI_Emphasis_BoldItalic ///< bold italic
} TUIEmphasisStyle;

/**
 *
 *  Typedef for baseline style.
 *
 */
typedef enum
{
  UI_Baseline_Normal,      ///< normal baseline
  UI_Baseline_Superscript, ///< superscript
  UI_Baseline_Subscript    ///< subscript
} TUIBaselineStyle;
/**
 *
 *  Typedef for text edge style.
 *
 */
typedef enum
{
  UI_Edge_Normal,      ///< normal text without any edge effect
  UI_Edge_Embossed,    ///< text has a raised appearance
  UI_Edge_Engrayed,    ///< text has a depressed appearance
  UI_Edge_Outlined,    ///< text is just an outline
  UI_Edge_Drop_Shadow, ///< text has a shadow
  UI_Edge_Raised,      ///< similar to embossed, but more of a shadow effect
  UI_Edge_Depressed,   ///< similar to engraved, but more of a shadow effect
  UI_Edge_Uniform      ///< normal text with a colored edge around it, "cartoon style"
} TUIEdgeStyle;

typedef struct
{
  float size;        ///< height in ppem (20.0 ppem)
  float width;       ///< width in ppem; (0 - treated as equal to size)
  float skew;        ///< skew angle (0)
  float orientation; ///< glyph rotation, degrees clockwise (0.0)

  float bold_pct;       ///< boldness value (0)
  float stroke_pct;     ///< stroke width (0)
  float edgeThickness;  ///< edge thickness in pixels (0)
  float shadowLength_x; ///< x-direction length of shadow in pixels (0)
  float shadowLength_y; ///< y-direction length of shadow in pixels (0)

  TUIEmphasisStyle emphasis; ///< emphasis such as bold/italics (UI_Emphasis_Normal)
  TUIBaselineStyle baseline; ///< text baseline style (UI_Baseline_Normal)
  TUIEdgeStyle edge;         ///< text edge style (UI_Edge_Normal)
  TUIRenderStyle render;     ///< rendering style (UI_Render_Default)

} TUIFontData;

typedef unsigned char TUIFontStyle;

const TUIFontStyle UIFontStylePlain = 0;      ///<The plain style enum
const TUIFontStyle UIFontStyleBold = 1;       ///<The bold style enum.
const TUIFontStyle UIFontStyleItalic = 2;     ///<The italic style enum
const TUIFontStyle UIFontStyleBoldItalic = 3; ///<The bold italic style enum
const TUIFontStyle UIFontStyleUnderlined = 4; ///<The underlined style enum

typedef enum
{
  UIFontSizeMedium = 0, ///<The "medium" system-dependent font size
  UIFontSizeSmall = 8,  ///<The "small" system-dependent font size
  UIFontSizeLarge = 16  ///<The "large" system-dependent font size
} TUIFontSize;

typedef enum
{
  UIFontFaceSystem = 0,       ///<The "system" font face
  UIFontFaceMonoSpace = 32,   ///<The "monospace" font face.
  UIFontFaceProportional = 64 ///<The "proportional" font face.
} TUIFontFace;

class IFont : public IUnknown
{
public:
  virtual int GetFace(TUIFontFace *buf);
  virtual int GetSize(TUIFontSize *buf);
  virtual int GetStyle(TUIFontStyle *buf);
  virtual int GetFontAscent(long *pAscent);
  virtual int GetFontHeight(long *font_size);
  virtual int IsBold();
  virtual int IsItalic();
  virtual int IsPlain();
  virtual int IsUnderlined();
  virtual int GetFontStyle(IUnknown *pIUIFontStyle);
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
