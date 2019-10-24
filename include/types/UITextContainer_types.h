#ifndef __UITEXTCONTAINER_TYPES_H__
#define __UITEXTCONTAINER_TYPES_H__

#include "..\\include\types\Basic_types.h"

/**
 * @addtogroup Layout
 * @{
 */

const FSint32 UITEXTCONTAINER_NO_SIZE_LIMIT = FSINT16_MAX;

/**
 *
 *  An enumeration of the possible values for the direction in which glyphs
 *  flow in the text container 
 *
 */
typedef enum {
  UIGlyphsFlowLeftToRight, ///< default (needed for Latin, Greek, etc.)  
  UIGlyphsFlowRightToLeft, ///< needed for Arabic, Hebrew, etc.               
  UIGlyphsFlowTopToBottom, ///< not implemented yet, needed for vertical CJK, etc
  UIGlyphsFlowBottomToTop  ///< not implemented yet, needed for Ogham(?)
} TUIGlyphsFlow;

/**
 *
 *  An enumeration of the possible values for the direction in which lines
 *  flow in the text container 
 *
 */
typedef enum {
  UILinesFlowTopToBottom, ///< default
  UILinesFlowBottomToTop, ///< @note not implemented, not needed(?) 
  UILinesFlowLeftToRight, ///< @note not implemented yet, needed for vertical Mongolian
  UILinesFlowRightToLeft, ///< @note not implemented yet, needed for vertical CJK
  UILinesFlowNone         ///< if used, do not advance line if no fit
} TUILinesFlow;

/**
 *
 *  A structure containing the TsGlyphsFlow and TsLinesFlow values for the
 *  text container. Passed into TsTextContainer_getRect.
 *
 */
typedef struct 
{
  TUIGlyphsFlow glyphsFlow;
  TUILinesFlow  linesFlow;
} TUITextFlow;
/**@}*/

#endif
