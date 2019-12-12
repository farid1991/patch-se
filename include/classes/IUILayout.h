#ifndef _IUIRICHTEXTLAYOUTOPTIONS_H_
#define _IUIRICHTEXTLAYOUTOPTIONS_H_

#include "..\\include\types\Basic_types.h"

typedef struct
{
  TSigned numGlyphs;        ///< number of glyphs on the line
  TSigned startIndex;       ///< IUIRichText character index of first character in line
  TSigned endIndex;         ///< IUIRichText character index of last character in line
  TUIRectangle boundingBox; ///< actual "inked" area of the line -- relative to line's origin
  TUIRectangle advanceBox;  ///< box spanning origin to next advance point -- relative to line's origin
  FUint8 bidiBaseLevel;     ///< bidi base level for line -- odd if Right-To-Left, even if Left-To-Right
  TUIPoint lineOrigin;      ///< absolute coordinates for line's origin, only meaningful if lineFlags has UI_LINE_DISPLAYED set
  TSigned lineFlags;        ///< flags like UI_LINE_COMPOSED and UI_LINE_DISPLAYED
  TSigned baseline;         ///< amount to add to lineOrigin.y to get baseline
  TSigned top;              ///< amount to add to lineOrigin.y to get top of line (used for overline, and background color)
  TSigned bottom;           ///< amount to add to lineOrigin.y to get bottom of line (used for background color)
  TSigned alignment;        ///< alignment of line (UIText_alignLeft, UIText_alignRight, or UIText_alignCenter)
}TUILineInfo;

typedef struct
{
  TSigned sourceIndex; ///< character index in ÍUIRichText block
  TSigned glyphID;     ///< glyph index in font
  TSigned x;           ///< the x coordinate relative to the line's origin
  TSigned y;           ///< the y coordinate relative to the line's origin
  TUIRectangle boundingBox; ///< bounding box relative to the glyph's position (x,y)
}TUIGlyphInfo;

typedef struct
{
  TSigned numLines;           ///< number of lines in the layout
  TSigned numContainersUsed;  ///< number of containers actually used
  TUIRectangle boundingBox;   ///< text layout bounding box
  TUIRectangle advanceBox;    ///< text layout advance box
}TUILayoutInfo;

typedef struct
{
  TSigned numLines;          ///< count of lines in the container
  TSigned firstLineNumber;   ///< index of first line in container
  TUIRectangle boundingBox;  ///< text container bounding box
  TUIRectangle advanceBox;   ///< text container advance box
}TUIContainerInfo;

class IUIRichTextLayout: public IRoot
{
public:
  virtual int SetControl(void* pIUIRichTextLayoutControl);
  virtual int GetControl(void** ppIUIRichTextLayoutControl);
  virtual int SetOptions(void* pIUIRichTextLayoutOptions);
  virtual int GetOptions(void** ppIUIRichTextLayoutOptions);
  virtual int Subscribe(void* pICBUIRichTextLayout, u16 msgBase, int clientData, unsigned long* pSubscriptionHandle);
  virtual int Unsubscribe(unsigned long SubscriptionHandle);
  virtual int SetText(IUIRichText* pIUIRichText);
  virtual int GetText(IUIRichText** ppIUIRichText);
  virtual int Compose(int lineWidth);
  virtual int ComposeLine(int lineWidth, int ascenderLimit, int descenderLimit, int lineNumber, long* pStartIndex, long* pEndIndex, long* pCharsLeftToCompose);
  virtual int ComposeLineInit(long x, long y, long lineNumber);
  virtual int PositionLine(long x, long y, long lineNumber);  virtual int ComposeContainers(TUIRectangle* pComposeRect);
  virtual int GetWidthOfLongestRemainingLineBreakSequence(int* pWidth, long* pStartIndex, long* pEndIndex);
  virtual int GetLineInfo(long lineNumber, TUILineInfo* pInfo);  virtual int MapCharIndex(long index, long* pLineNumber);
  virtual int GetGlyphInfo(long lineNumber, long glyphIndex, bool needBoundingBox, TUIGlyphInfo* pInfo);
  virtual int GetNumberOfLines(long* pNumberOfLines);  virtual int GetLayoutInfo(TUILayoutInfo* pLayoutInfo);
  virtual int GetContainerInfo(long containerIndex, TUIContainerInfo* pContainerInfo);
  virtual int Display(IRoot* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int DisplayContainers(IRoot* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int DisplayLine(IRoot* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int AddTextContainer(IRoot* pIUITextContainer, long containerID, TUIPoint* pContainerOrigin);
  virtual int RemoveTextContainer(long containerID);
};

// IUIRichTextLayoutOptions ----------------------------------------------------

/**
 * Line break model macros. @See SetLineBreakModel for description 
 */
typedef FUint32 TUILineBreakModel;

/**
* try to line break at legal (per Unicode) line break points 
*/
const TUILineBreakModel UILineBreakBit_Use_Legal_Line_Break_If_Able   = 0x0001;

/**
* OK to break at grapheme boundaries if not able (or not allowed) to break at legal line break points
*/
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Grapheme        = 0x0002;

/** 
* OK to break at glyphs if not able (or not allowed) to break at legal points or grapheme boundaries
*/
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Glyph           = 0x0004;

/**
* East Asian style = OK to break within a word, default is Western style (break after spaces, etc.)
*/
const TUILineBreakModel UILineBreakBit_Korean_Uses_East_Asian_Style   = 0x0008;

/**
* wrap trailing whitespace at end of line to next line if it passes composition width 
*/
const TUILineBreakModel UILineBreakBit_Wrap_WhiteSpaces                = 0x0010;

/**
* hide initial whitespace of current line if it was wrapped from previous line
*/
const TUILineBreakModel UILineBreakBit_Hide_Initial_Wrapped_WhiteSpace = 0x0020;


const TUILineBreakModel UILineBreak_Grapheme = UILineBreakBit_OK_To_Break_On_Grapheme;

/**
 *
 *  Macro indicating the maximum number of tab stops that is supported.
 *
 */
const FUint8 UIRichTextLayoutOptions_Max_TabStop_Count = 254;


/**
 *
 *  Macro indicating left alignment of a tabstop.
 *
 */
const FUint8 UIRichTextLayoutOptions_TabStop_Alignment_Left = 0;


/**
 *
 *  Macro indicating right alignment of a tabstop.
 *
 */
const FUint8 UIRichTextLayoutOptions_TabStop_Alignment_Right = 1;


/**
 *
 *  Macro indicating center alignment of a tabstop.
 *
 */
const FUint8 UIRichTextLayoutOptions_TabStop_Alignment_Center = 2;


/**
 *
 *  Enumeration of highlighting modes.
 *
 */
typedef enum
{
  UIHighlight_ReverseVideoMode = 0,    ///< selected text displayed reverse video 
  UIHighlight_ColorMode,               ///< selected text displayed with user-specified colors 
  UIHighlight_Disabled                 ///< selected text displayed without highlighting
} TUIHighlightMode;

/**
 *
 *  Enumeration of custom dictionaries.
 *
 */
typedef enum
{
  UICustomDictionary_Icons = 0,         ///< icons dictionary 
  UICustomDictionary_Emoticons          ///< emoticons dictionary
} TUICustomDictionary;

/**
 *
 *  Enumeration of boolean layout option tags.
 *
 *  The default value for all boolean options is FALSE except UIRichTextLayoutOptionsTag_Enable_Icons.
 *  The name of the option describes the affect of setting a specific option to TRUE.
 *
 *  Layout algorithm options - enable/disable specific layout algorithms.
 *  Most are self explanatory. The option 
 *  UIRichTextLayoutOptionsTag_Limit_Bounding_Box_To_Comp_Width
 *  ensures that the full glyph fits within the composition width or the
 *  the text container's x-direction boundaries. This is not recommended
 *  for general use since text will not line up properly. It may be useful
 *  when the certainty of text fitting within a container is more important
 *  than typographic accuracy. Note that some algorithms may be disabled
 *  at build time as well in order to reduce code size.
 *
 *  Substitution dictionaries - switches to enable/disable the various
 *  dictionaries. To be fully active a dictionary must (1) be added
 *  to its owner object using either IUIRichTextLayoutControl::AddDictionary or
 *  IUIRichTextLayoutOptions::AddDictionary and (2) be enabled using this
 *  function with the appropriate tag.
 *
 *  Draw options - these are used for diagnostic purposes. Certain
 *  marks, lines, and boxes will be drawn in the text area to show
 *  bounding box, baseline, text direction, and so forth. The build
 *  option CFG_WTLE_ENABLE_LAYOUT_MARKS must be defined as well.
 *
 */
typedef enum
{
  /* layout algorithm options */
  UIRichTextLayoutOptionsTag_Disable_BiDi,                              ///< Disables the bidirectional algorithm 
  UIRichTextLayoutOptionsTag_Disable_Complex_Shaping,                   ///< Disables all complex shaping
  UIRichTextLayoutOptionsTag_Disable_Diacritics_Postitioning,           ///< Disables the diacritics positioning system
  UIRichTextLayoutOptionsTag_Disable_Normalization,                     ///< Disables Unicode text normalization
  UIRichTextLayoutOptionsTag_Disable_OpenType_Layout,                   ///< Disables OpenType layout table processing
  UIRichTextLayoutOptionsTag_Disable_Thai_Line_Breaking,                ///< Disables the Thai line breaking algorithm
  UIRichTextLayoutOptionsTag_Enable_Kerning,                            ///< Enables pairwise kerning if supported by font engine (not yet supported by layout engine)
  UIRichTextLayoutOptionsTag_Limit_Bounding_Box_To_Comp_Width,          ///< nsures that the text bounding box does not exceed the width of the text container
  UIRichTextLayoutOptionsTag_Enable_Forced_Monospace,                   ///< Enables forced monospace mode, for use in spacing grapheme choices for multi-tap input
  UIRichTextLayoutOptionsTag_Limit_Width_To_Longest_LineBreak_Sequence, ///z Limits composition width to that of longest linebreak sequence (for use in block layout mode only)

  /* substituion dictionaries */
  UIRichTextLayoutOptionsTag_Enable_Icons,                              ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutControl)
  UIRichTextLayoutOptionsTag_Enable_Emoticons,                          ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutControl)
  UIRichTextLayoutOptionsTag_Enable_Custom_Icons,                       ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutOptions)
  UIRichTextLayoutOptionsTag_Enable_Custom_Emoticons,                   ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutOptions)

  /* Enable draw options - used for layout diagnostics */
  UIRichTextLayoutOptionsTag_Draw_Line_Advance_Box,                     ///< For each text line draw a rectangle showing its advance box
  UIRichTextLayoutOptionsTag_Draw_Line_Bounding_Box,                    ///< For each text line draw a rectangle showing the bounding box 
  UIRichTextLayoutOptionsTag_Draw_Text_Direction,                       ///< For each line draw the text baseline
  UIRichTextLayoutOptionsTag_Draw_Potential_Line_Breaks,                ///< Draw a colored line indicating the text direction
  UIRichTextLayoutOptionsTag_Draw_Word_Boundaries,                      ///< Draw a vertical line between graphemes where line breaks can occur
  UIRichTextLayoutOptionsTag_Draw_Shaping_Boundaries,                   ///< Draw a vertical line at each word boundary
  UIRichTextLayoutOptionsTag_Draw_Baseline,                             ///< Draw a vertical line at each shaping boundary 
  UIRichTextLayoutOptionsTag_Draw_Text_Containers,                      ///< Draw a rectangle at edge of text containers 
  UIRichTextLayoutOptionsTag_Draw_Anchored_Objects                      ///< Draw a rectangle at edge of anchored objects 

} TUIRichTextLayoutOptionsTag;

class IUIRichTextLayoutOptions: public IRoot
{
public:
  virtual int Set(TUIRichTextLayoutOptionsTag tag, bool value);
  virtual int SetLineBreakModel(TUILineBreakModel Model);
  virtual int SetTabStop(float position, char alignment, char leader);
  virtual int ClearTabStop(char index);
  virtual int SetTabStopPositionDefault(float pos);
  virtual int SetHyphenChar(FUint32 HyphenChar);
  virtual int SetTruncationChar(FUint32 TruncationChar);
  virtual int SetMonospaceMinPadding(float minPadding);
  virtual int SetMonospaceMinWidth(float minWidth);
  virtual int SetHighlightMode(TUIHighlightMode Mode);
  virtual int SetHighlightBackgroundColor(TColour Value);
  virtual int SetHighlightTextColor(TColour Value);
  virtual int Get(TUIRichTextLayoutOptionsTag tag, bool* pValue);
  virtual int GetLineBreakModel(TUILineBreakModel* pModel);
  virtual int GetTabStop(char index, float* pPosition, char* pAlignment, u16* pLeader);
  virtual int GetTabStopPositionDefault(float* pPos);
  virtual int GetHyphenChar(FUint32* pHyphenChar);
  virtual int GetTruncationChar(FUint32* pTruncationChar);
  virtual int GetHighlightMode(TUIHighlightMode* pMode);
  virtual int GetHighlightBackgroundColor(TColour* pValue);
  virtual int GetHighlightTextColor(TColour* pValue);
  virtual int GetMonospaceMinPadding(float* pMinPadding);
  virtual int GetMonospaceMinWidth(float* pMinWidth);
  virtual int AddDictionary(TUICustomDictionary dictionary, IRoot* pIFullPath);
  virtual int RemoveDictionary(TUICustomDictionary dictionary);
};

#endif
