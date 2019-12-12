#ifndef __UIFONTPARAM_TYPES_H__
#define __UIFONTPARAM_TYPES_H__

#include "..\\include\types\Basic_types.h"

/**
 * @addtogroup Font
 * @{
 */

/**
 *
 *  Typedef for text emphasis style
 *
 */
typedef enum
{
  UI_Emphasis_Normal,     ///< normal
  UI_Emphasis_Bold,       ///< bold
  UI_Emphasis_Italic,     ///< italic
  UI_Emphasis_BoldItalic  ///< bold italic
} TUIEmphasisStyle;

/**
 *
 *  Typedef for baseline style.
 *
 */
typedef enum
{
  UI_Baseline_Normal,       ///< normal baseline
  UI_Baseline_Superscript,  ///< superscript
  UI_Baseline_Subscript     ///< subscript
} TUIBaselineStyle;

/**
 *
 *  Typedef for text edge style.
 *
 */
typedef enum
{
  UI_Edge_Normal,          ///< normal text without any edge effect
  UI_Edge_Embossed,        ///< text has a raised appearance
  UI_Edge_Engrayed,        ///< text has a depressed appearance 
  UI_Edge_Outlined,        ///< text is just an outline  
  UI_Edge_Drop_Shadow,     ///< text has a shadow 
  UI_Edge_Raised,          ///< similar to embossed, but more of a shadow effect 
  UI_Edge_Depressed,       ///< similar to engraved, but more of a shadow effect 
  UI_Edge_Uniform          ///< normal text with a colored edge around it, "cartoon style" 
} TUIEdgeStyle;

/**
 *
 *  Typedef for rendering style.
 *      
 */
typedef FUint16 TUIRenderStyle;

/**
 *
 *  Rendering style. 
 *      
 */
enum EUIRenderStyle
{
  UI_Render_Default     = 0x0000,   ///< use the font engine's default rendering 
  UI_Render_Binary      = 0x0001,   ///< binary,    1 bit per pixel 
  UI_Render_Grayscale2  = 0x0002,   ///< grayscale, 2 bits per pixel 
  UI_Render_Grayscale4  = 0x0004,   ///< grayscale, 4 bits per pixel (grayscale antialiasing)
  UI_Render_Grayscale8  = 0x0008,   ///< grayscale, 4 bits per pixel 
  UI_Render_ADF_Graymap = 0x0010,   ///< ADF rendering 
  UI_Render_Vactor_Icon = 0x0020    ///< vector icon 
};


/**
 *
 *  A structure that describes font style parameters.  
 * 
 *  This structure is used to create IUIFontStyle objects;
 *
 */
typedef struct
{
  TFloat size;                ///< height in ppem (20.0 ppem)
  TFloat width;               ///< width in ppem; (0 - treated as equal to size)
  TFloat skew;                ///< skew angle (0)
  TFloat orientation;         ///< glyph rotation, degrees clockwise (0.0)

  TFloat bold_pct;            ///< boldness value (0)
  TFloat stroke_pct;          ///< stroke width (0)
  TFloat edgeThickness;       ///< edge thickness in pixels (0)
  TFloat shadowLength_x;      ///< x-direction length of shadow in pixels (0)
  TFloat shadowLength_y;      ///< y-direction length of shadow in pixels (0)

  TUIEmphasisStyle emphasis;   ///< emphasis such as bold/italics (UI_Emphasis_Normal)
  TUIBaselineStyle baseline;   ///< text baseline style (UI_Baseline_Normal)
  TUIEdgeStyle     edge;       ///< text edge style (UI_Edge_Normal)
  TUIRenderStyle   render;     ///< rendering style (UI_Render_Default)

} TUIFontParam;

#endif
