#ifndef _IUIRICHTEXTLAYOUTOPTIONS_H_
#define _IUIRICHTEXTLAYOUTOPTIONS_H_

typedef unsigned long FUint32;

class IRichText;

typedef struct
{
  long numGlyphs;    ///< number of glyphs on the line
  long startIndex;   ///< IUIRichText character index of first character in line
  long endIndex;     ///< IUIRichText character index of last character in line
  TUIRectangle boundingBox;  ///< actual "inked" area of the line -- relative to line's origin
  TUIRectangle advanceBox;   ///< box spanning origin to next advance point -- relative to line's origin
  unsigned char bidiBaseLevel;///< bidi base level for line -- odd if Right-To-Left, even if Left-To-Right
  TUIPoint lineOrigin;   ///< absolute coordinates for line's origin, only meaningful if lineFlags has UI_LINE_DISPLAYED set
  long lineFlags;    ///< flags like UI_LINE_COMPOSED and UI_LINE_DISPLAYED
  long baseline;     ///< amount to add to lineOrigin.y to get baseline
  long top;          ///< amount to add to lineOrigin.y to get top of line (used for overline, and background color)
  long bottom;       ///< amount to add to lineOrigin.y to get bottom of line (used for background color)
  long alignment;///< alignment of line (UIText_alignLeft, UIText_alignRight, or UIText_alignCenter)
}TUILineInfo;

typedef struct
{
  long sourceIndex; ///< character index in ÍUIRichText block
  long glyphID;     ///< glyph index in font
  long x;           ///< the x coordinate relative to the line's origin
  long y;           ///< the y coordinate relative to the line's origin
  TUIRectangle boundingBox; ///< bounding box relative to the glyph's position (x,y)
}TUIGlyphInfo;

typedef struct
{
  long numLines;         ///< number of lines in the layout
  long numContainersUsed;///< number of containers actually used
  TUIRectangle boundingBox;      ///< text layout bounding box
  TUIRectangle advanceBox;       ///< text layout advance box
}TUILayoutInfo;

typedef struct
{
  long numLines;          ///< count of lines in the container
  long firstLineNumber;   ///< index of first line in container
  TUIRectangle boundingBox;  ///< text container bounding box
  TUIRectangle advanceBox;   ///< text container advance box
}TUIContainerInfo;

class IRichTextLayout: public IUnknown
{
public:
  virtual int SetControl(void* pIUIRichTextLayoutControl);
  virtual int GetControl(void** pIUIRichTextLayoutControl);
  virtual int SetOptions(void* pIUIRichTextLayoutOptions);
  virtual int GetOptions(void* pIUIRichTextLayoutOptions);
  virtual int Subscribe(void* pICBUIRichTextLayout, u16 msgBase, int clientData, unsigned long* pSubscriptionHandle);
  virtual int Unsubscribe(unsigned long SubscriptionHandle);
  virtual int SetText(IRichText* pTextObject);
  virtual int GetText(IRichText** pTextObject);
  virtual int Compose(int lineWidth);
  virtual int ComposeLine(int lineWidth, int ascenderLimit, int descenderLimit, int lineNumber, long* pStartIndex, long* pEndIndex, long* pCharsLeftToCompose);
  virtual int ComposeLineInit(long x, long y, long lineNumber);
  virtual int PositionLine(long x, long y, long lineNumber);  virtual int ComposeContainers(TUIRectangle* pComposeRect);
  virtual int GetWidthOfLongestRemainingLineBreakSequence(int* pWidth, long* pStartIndex, long* pEndIndex);
  virtual int GetLineInfo(long lineNumber, TUILineInfo* pInfo);  virtual int MapCharIndex(long index, long* pLineNumber);
  virtual int GetGlyphInfo(long lineNumber, long glyphIndex, bool needBoundingBox, TUIGlyphInfo* pInfo);
  virtual int GetNumberOfLines(long* pNumberOfLines);  virtual int GetLayoutInfo(TUILayoutInfo* pLayoutInfo);
  virtual int GetContainerInfo(long containerIndex, TUIContainerInfo* pContainerInfo);
  virtual int Display(IUnknown* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int DisplayContainers(IUnknown* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int DisplayLine(IUnknown* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int AddTextContainer(IUnknown* pIUITextContainer, long containerID, TUIPoint* pContainerOrigin);
  virtual int RemoveTextContainer(long containerID);
};

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

}TUIRichTextLayoutOptionsTag;

typedef enum
{
  UIHighlight_ReverseVideoMode = 0,    ///< selected text displayed reverse video
  UIHighlight_ColorMode,               ///< selected text displayed with user-specified colors
  UIHighlight_Disabled                 ///< selected text displayed without highlighting
}TUIHighlightMode;

typedef enum
{
  UICustomDictionary_Icons = 0,         ///< icons dictionary
  UICustomDictionary_Emoticons          ///< emoticons dictionary
}TUICustomDictionary;

typedef FUint32 TColour;
typedef FUint32 TUILineBreakModel;

const TUILineBreakModel UILineBreakBit_Use_Legal_Line_Break_If_Able	= 0x0001;
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Grapheme		= 0x0002;
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Glyph		= 0x0004;
const TUILineBreakModel UILineBreakBit_Korean_Uses_East_Asian_Style	= 0x0008;
const TUILineBreakModel UILineBreakBit_Wrap_WhiteSpaces			= 0x0010;
const TUILineBreakModel UILineBreakBit_Hide_Initial_Wrapped_WhiteSpace	= 0x0020;

class IUIRichTextLayoutOptions: public IUnknown
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
  virtual int AddDictionary(TUICustomDictionary dictionary, IUnknown* pIFullPath);
  virtual int RemoveDictionary(TUICustomDictionary dictionary);
};

#endif
