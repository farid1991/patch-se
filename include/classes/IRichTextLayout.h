#ifndef _IUIRICHTEXTLAYOUT_H_
#define _IUIRICHTEXTLAYOUT_H_

#include "..\types\Basic_types.h"
#include "..\types\OPA_types.h"
#include "..\types\UIRect_types.h"
#include "..\types\UIRichText_types.h"

class IRichText;

const FSint32 UIRICHTEXTLAYOUT_CONTAINER_NO_SIZE_LIMIT = FSINT32_MAX;
const FSint32 UIRICHTEXTLAYOUT_MAX_LINE_WIDTH = 0x00007FFF;

typedef struct
{
  FSint32 numLines;          ///< number of lines in the layout
  FSint32 numContainersUsed; ///< number of containers actually used
  TUIRectangle boundingBox;  ///< text layout bounding box
  TUIRectangle advanceBox;   ///< text layout advance box
} TUILayoutInfo;

typedef struct
{
  FSint32 numLines;         ///< count of lines in the container
  FSint32 firstLineNumber;  ///< index of first line in container
  TUIRectangle boundingBox; ///< text container bounding box
  TUIRectangle advanceBox;  ///< text container advance box
} TUIContainerInfo;

typedef struct
{
  FSint32 numGlyphs;          ///< number of glyphs on the line
  FSint32 startIndex;         ///< IUIRichText character index of first character in line
  FSint32 endIndex;           ///< IUIRichText character index of last character in line
  TUIRectangle boundingBox;   ///< actual "inked" area of the line -- relative to line's origin
  TUIRectangle advanceBox;    ///< box spanning origin to next advance point -- relative to line's origin
  FUint8 bidiBaseLevel;       ///< bidi base level for line -- odd if Right-To-Left, even if Left-To-Right
  TUIPoint lineOrigin;        ///< absolute coordinates for line's origin, only meaningful if lineFlags has UI_LINE_DISPLAYED set
  FSint32 lineFlags;          ///< flags like UI_LINE_COMPOSED and UI_LINE_DISPLAYED
  FSint32 baseline;           ///< amount to add to lineOrigin.y to get baseline
  FSint32 top;                ///< amount to add to lineOrigin.y to get top of line (used for overline, and background color)
  FSint32 bottom;             ///< amount to add to lineOrigin.y to get bottom of line (used for background color)
  TUITextAlignment alignment; ///< alignment of line (UIText_alignLeft, UIText_alignRight, or UIText_alignCenter)
} TUILineInfo;

typedef struct
{
  FSint32 sourceIndex;      ///< character index in ÍUIRichText block
  FSint32 glyphID;          ///< glyph index in font
  TUIPosition x;            ///< the x coordinate relative to the line's origin
  TUIPosition y;            ///< the y coordinate relative to the line's origin
  TUIRectangle boundingBox; ///< bounding box relative to the glyph's position (x,y)
} TUIGlyphInfo;

// IUIRichTextLayoutOptions ----------------------------------------------------

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
  UIRichTextLayoutOptionsTag_Limit_Width_To_Longest_LineBreak_Sequence, /// z Limits composition width to that of longest linebreak sequence (for use in block layout mode only)

  /* substituion dictionaries */
  UIRichTextLayoutOptionsTag_Enable_Icons,            ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutControl)
  UIRichTextLayoutOptionsTag_Enable_Emoticons,        ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutControl)
  UIRichTextLayoutOptionsTag_Enable_Custom_Icons,     ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutOptions)
  UIRichTextLayoutOptionsTag_Enable_Custom_Emoticons, ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutOptions)

  /* Enable draw options - used for layout diagnostics */
  UIRichTextLayoutOptionsTag_Draw_Line_Advance_Box,      ///< For each text line draw a rectangle showing its advance box
  UIRichTextLayoutOptionsTag_Draw_Line_Bounding_Box,     ///< For each text line draw a rectangle showing the bounding box
  UIRichTextLayoutOptionsTag_Draw_Text_Direction,        ///< For each line draw the text baseline
  UIRichTextLayoutOptionsTag_Draw_Potential_Line_Breaks, ///< Draw a colored line indicating the text direction
  UIRichTextLayoutOptionsTag_Draw_Word_Boundaries,       ///< Draw a vertical line between graphemes where line breaks can occur
  UIRichTextLayoutOptionsTag_Draw_Shaping_Boundaries,    ///< Draw a vertical line at each word boundary
  UIRichTextLayoutOptionsTag_Draw_Baseline,              ///< Draw a vertical line at each shaping boundary
  UIRichTextLayoutOptionsTag_Draw_Text_Containers,       ///< Draw a rectangle at edge of text containers
  UIRichTextLayoutOptionsTag_Draw_Anchored_Objects       ///< Draw a rectangle at edge of anchored objects

} TUIRichTextLayoutOptionsTag;

typedef enum
{
  UIHighlight_ReverseVideoMode = 0, ///< selected text displayed reverse video
  UIHighlight_ColorMode,            ///< selected text displayed with user-specified colors
  UIHighlight_Disabled              ///< selected text displayed without highlighting
} TUIHighlightMode;

typedef enum
{
  UICustomDictionary_Icons = 0, ///< icons dictionary
  UICustomDictionary_Emoticons  ///< emoticons dictionary
} TUICustomDictionary;

typedef FUint32 TColour;
typedef FUint32 TUILineBreakModel;

const TUILineBreakModel UILineBreakBit_Use_Legal_Line_Break_If_Able = 0x0001;
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Grapheme = 0x0002;
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Glyph = 0x0004;
const TUILineBreakModel UILineBreakBit_Korean_Uses_East_Asian_Style = 0x0008;
const TUILineBreakModel UILineBreakBit_Wrap_WhiteSpaces = 0x0010;
const TUILineBreakModel UILineBreakBit_Hide_Initial_Wrapped_WhiteSpace = 0x0020;

class IUIRichTextLayoutOptions : public IUnknown
{
public:
  virtual int Set(TUIRichTextLayoutOptionsTag tag, TBool value);
  virtual int SetLineBreakModel(TUILineBreakModel Model);
  virtual int SetTabStop(TFloat position, FUint8 alignment, FUint8 leader);
  virtual int ClearTabStop(char index);
  virtual int SetTabStopPositionDefault(TFloat pos);
  virtual int SetHyphenChar(FUint32 HyphenChar);
  virtual int SetTruncationChar(FUint32 TruncationChar);
  virtual int SetMonospaceMinPadding(TFloat minPadding);
  virtual int SetMonospaceMinWidth(TFloat minWidth);
  virtual int SetHighlightMode(TUIHighlightMode Mode);
  virtual int SetHighlightBackgroundColor(TColour Value);
  virtual int SetHighlightTextColor(TColour Value);
  virtual int Get(TUIRichTextLayoutOptionsTag tag, bool *pValue);
  virtual int GetLineBreakModel(TUILineBreakModel *pModel);
  virtual int GetTabStop(FUint8 index, TFloat *pPosition, FUint8 *pAlignment, FUint16 *pLeader);
  virtual int GetTabStopPositionDefault(TFloat *pPos);
  virtual int GetHyphenChar(FUint32 *pHyphenChar);
  virtual int GetTruncationChar(FUint32 *pTruncationChar);
  virtual int GetHighlightMode(TUIHighlightMode *pMode);
  virtual int GetHighlightBackgroundColor(TColour *pValue);
  virtual int GetHighlightTextColor(TColour *pValue);
  virtual int GetMonospaceMinPadding(TFloat *pMinPadding);
  virtual int GetMonospaceMinWidth(TFloat *pMinWidth);
  virtual int AddDictionary(TUICustomDictionary dictionary, IUnknown *pIFullPath);
  virtual int RemoveDictionary(TUICustomDictionary dictionary);
};

typedef enum
{
  UIRichTextLayoutControlTag_THA, ///< Thai
  UIRichTextLayoutControlTag_ICN, ///< Icons
  UIRichTextLayoutControlTag_EMOT ///< Emoticons
} TUIRichTextLayoutControlTag;

class IUIRichTextLayoutControl : public IUnknown
{
  virtual int AddDictionary(TUIRichTextLayoutControlTag tag, IUnknown *pIFullPath);
  virtual int RemoveDictionary(TUIRichTextLayoutControlTag tag);
};

class IRichTextLayout : public IUnknown
{
public:
  virtual int SetControl(IUIRichTextLayoutControl *pIUIRichTextLayoutControl);                                                                                                                        // 0x10
  virtual int GetControl(IUIRichTextLayoutControl **pIUIRichTextLayoutControl);                                                                                                                       // 0x14
  virtual int SetOptions(IUIRichTextLayoutOptions *pIUIRichTextLayoutOptions);                                                                                                                        // 0x18
  virtual int GetOptions(IUIRichTextLayoutOptions *pIUIRichTextLayoutOptions);                                                                                                                        // 0x1C
  virtual int Subscribe(void *pICBUIRichTextLayout, TMsgBase msgBase, TClientData clientData, THnd *pSubscriptionHandle);                                                                             // 0x20
  virtual int Unsubscribe(THnd SubscriptionHandle);                                                                                                                                                   // 0x24
  virtual int SetText(IRichText *pTextObject);                                                                                                                                                        // 0x28
  virtual int GetText(IRichText **pTextObject);                                                                                                                                                       // 0x2C
  virtual int Compose(TUIDimension lineWidth);                                                                                                                                                        // 0x30
  virtual int ComposeLine(TUIDimension lineWidth, TUIPosition ascenderLimit, TUIPosition descenderLimit, FSint32 lineNumber, FSint32 *pStartIndex, FSint32 *pEndIndex, FSint32 *pCharsLeftToCompose); // 0x34
  virtual int ComposeLineInit(FSint32 x, FSint32 y, FSint32 lineNumber);                                                                                                                              // 0x38
  virtual int PositionLine(FSint32 x, FSint32 y, FSint32 lineNumber);                                                                                                                                 // 0x3C
  virtual int ComposeContainers(TUIRectangle *pComposeRect);                                                                                                                                          // 0x40
  virtual int GetWidthOfLongestRemainingLineBreakSequence(TUIDimension *pWidth, FSint32 *pStartIndex, FSint32 *pEndIndex);                                                                            // 0x44
  virtual int GetLineInfo(FSint32 lineNumber, TUILineInfo *pInfo);                                                                                                                                    // 0x48
  virtual int MapCharIndex(FSint32 index, FSint32 *pLineNumber);                                                                                                                                      // 0x4C
  virtual int GetGlyphInfo(FSint32 lineNumber, FSint32 glyphIndex, TBool needBoundingBox, TUIGlyphInfo *pInfo);                                                                                       // 0x50
  virtual int GetNumberOfLines(FSint32 *pNumberOfLines);                                                                                                                                              // 0x54
  virtual int GetLayoutInfo(TUILayoutInfo *pLayoutInfo);                                                                                                                                              // 0x58
  virtual int GetContainerInfo(FSint32 containerIndex, TUIContainerInfo *pContainerInfo);                                                                                                             // 0x5C
  virtual int Display(IUnknown *pGC, FSint32 x, FSint32 y, TUIRectangle *pInvalidateRect);                                                                                                            // 0x60
  virtual int DisplayContainers(IUnknown *pGC, FSint32 x, FSint32 y, TUIRectangle *pInvalidateRect);                                                                                                  // 0x64
  virtual int DisplayLine(IUnknown *pGC, FSint32 x, FSint32 y, TUIRectangle *pInvalidateRect);                                                                                                        // 0x68
  virtual int AddTextContainer(IUnknown *pIUITextContainer, FSint32 containerID, TUIPoint *pContainerOrigin);                                                                                         // 0x6C
  virtual int RemoveTextContainer(FSint32 containerID);
};

#endif
