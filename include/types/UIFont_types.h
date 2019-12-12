#ifndef __UIFONT_TYPES_H__
#define __UIFONT_TYPES_H__

#include "..\\include\types\Basic_types.h"

enum Font_Style 
{
  FontStyle_Normal = 0,
  FontStyle_Bold,
  FontStyle_Italic,
  FontStyle_BoldItalic,
  UnkFontStyle
};

/**
 * @addtogroup MIDP_Font
 * @{
 */

/**
 *  Size of the font
 */
typedef enum
{
  UIFontSizeMedium = 0,     ///<The "medium" system-dependent font size
  UIFontSizeSmall = 8,      ///<The "small" system-dependent font size
  UIFontSizeLarge = 16      ///<The "large" system-dependent font size
} TUIFontSize;

/**
 *  Style of the font
 */
typedef FUint8 TUIFontStyle; 

const TUIFontStyle UIFontStylePlain = 0;      ///<The plain style enum
const TUIFontStyle UIFontStyleBold = 1;       ///<The bold style enum.
const TUIFontStyle UIFontStyleItalic = 2;     ///<The italic style enum
const TUIFontStyle UIFontStyleItalicBold = 3;     ///<The italic bold style enum
const TUIFontStyle UIFontStyleUnderlined = 4; ///<The underlined style enum

/**
 *  Face of the font
 */
typedef enum
{
  UIFontFaceSystem = 0,       ///<The "system" font face
  UIFontFaceMonoSpace = 32,   ///<The "monospace" font face.
  UIFontFaceProportional = 64 ///<The "proportional" font face.
} TUIFontFace;

/**
 *  Height of the font
 */
typedef FSint32 TUIFontHeight;

/**
 *  Ascent of the font
 */
typedef FSint32 TUIFontAscent;
/**@}*/

#endif
