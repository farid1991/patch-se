#ifndef __UIRICHTEXT_TYPES_H__
#define __UIRICHTEXT_TYPES_H__

/**
 *  Macro to indicate an index that is always less than or equal to the
 *  start of the text.
 *
 */
const FSint32 UITEXTSTYLE_START_OF_TEXT = (FSINT32_MIN + 10); /* +- 10 to avoid wrapping edge */

/**
 *  Macro to indicate an index that is always greater than or equal to the
 *  end of the text.
 *
 */
const FSint32 UITEXTSTYLE_END_OF_TEXT = (FSINT32_MAX - 10);

/**
 *
 *  Enumeration of text encodings.
 *
 */
typedef enum
{
  UIEncoding_Encoding_Not_Specified = 0,
  UIEncoding_ASCII, ///< plain ASCII text
  UIEncoding_UTF8,  ///< text encoded in UTF-8
  UIEncoding_UTF16, ///< text encoded in UTF-16
  UIEncoding_UTF32  ///< text encoded in UTF-32
} TUIEncoding;

/**
 *  Typedef for text alignment type.
 *
 */
typedef enum
{
  UIText_alignLeft,        ///< left aligned
  UIText_alignRight,       ///< center aligned
  UIText_alignCenter,      ///< right aligned
  UIText_alignLeftDynamic, ///< left aligned but first character can override
  UIText_alignRightDynamic ///< right aligned but first character can override
} TUITextAlignment;

/**
 *
 *  Typedef for text flow direction.
 */
typedef enum
{
  UITextDirection_Netural, ///< text with no inherent direction
  UITextDirection_LTR,     ///< left-to-right text
  UITextDirection_RTL      ///< right-to-left text
} TUITextDirection;

/**
 *
 *  Typedef for line spacing settings.
 *
 */
typedef enum
{
  UILineSpacing_Single_Line,        ///< single spacing
  UILineSpacing_150_Line,           ///< one and a half line spacing
  UILineSpacing_Double_Line,        ///< double spacing
  UILineSpacing_Exact_Line_Spacing, ///< line spacing set to lineSpacingAmount
  UILineSpacing_Multiple_Line       ///< line spacing set to multiple of line spacing * lineSpacingAmount
} TUILineSpacing;

/**
 *
 *  Typedef for line styles.
 */
typedef enum
{
  UILine_None,       ///< no line
  UILine_SingleSolid ///< single solid line
} TUILineStyle;

/**
 *
 *  A structure that defines inline image metrics needed for layout
 *
 */
typedef struct
{
  TFloat xAdvance;          ///< x-dimension advance width
  TFloat yAdvance;          ///< y-dimension advance width
  TUIRectangle boundingBox; ///< bounding box of image, with respect to its origin
} TUIInlineObjectMetrics;

#endif
