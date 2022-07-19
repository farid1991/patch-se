#ifndef _ITEXTRENDERINGMANAGER_H_
#define _ITEXTRENDERINGMANAGER_H_

#include "..\types\Basic_types.h"

const FSint32 FSINT32_MIN = 0x8000000A;
const FSint32 FSINT32_MAX = 0x7FFFFFF5;

const FSint32 UITEXTSTYLE_START_OF_TEXT = FSINT32_MIN;
const FSint32 UITEXTSTYLE_END_OF_TEXT = FSINT32_MAX;

const FSint32 UIRICHTEXTLAYOUT_MAX_LINE_WIDTH = 0x00007FFF;

typedef enum
{
  UIEncoding_Encoding_Not_Specified = 0,
  UIEncoding_ASCII, ///< plain ASCII text
  UIEncoding_UTF8,  ///< text encoded in UTF-8
  UIEncoding_UTF16, ///< text encoded in UTF-16
  UIEncoding_UTF32  ///< text encoded in UTF-32
} TUIEncoding;

typedef enum
{
  UILineSpacing_Single_Line,        ///< single spacing
  UILineSpacing_150_Line,           ///< one and a half line spacing
  UILineSpacing_Double_Line,        ///< double spacing
  UILineSpacing_Exact_Line_Spacing, ///< line spacing set to lineSpacingAmount
  UILineSpacing_Multiple_Line       ///< line spacing set to multiple of line spacing * lineSpacingAmount
} TUILineSpacing;

typedef enum
{
  UIText_alignLeft,        ///< left aligned
  UIText_alignRight,       ///< center aligned
  UIText_alignCenter,      ///< right aligned
  UIText_alignLeftDynamic, ///< left aligned but first character can override
  UIText_alignRightDynamic ///< right aligned but first character can override
} TUITextAlignment;

typedef enum
{
  UITextDirection_Netural, ///< text with no inherent direction
  UITextDirection_LTR,     ///< left-to-right text
  UITextDirection_RTL      ///< right-to-left text
} TUITextDirection;

typedef enum
{
  UILine_None,       ///< no line
  UILine_SingleSolid ///< single solid line
} TUILineStyle;

typedef struct
{
  float xAdvance;           ///< x-dimension advance width
  float yAdvance;           ///< y-dimension advance width
  TUIRectangle boundingBox; ///< bounding box of image, with respect to its origin
} TUIInlineObjectMetrics;

class IRichText : public IUnknown
{
public:
  virtual int SetString(void *pIString);                                                                           // 0x10 Set a string (UTF16)
  virtual int GetString(void **ppIString);                                                                         // 0x14 Get a string (UTF16)
  virtual int InsertText(void *text, FSint32 text_len, TUIEncoding encoding, FSint32 insertIndex);                 // 0x18 Inserts a text run by copy to a IUIRichText object.
  virtual int InsertTextUTF16(u16 *text, int length_text, FSint32 insertIndex);                                    // 0x1C Inserts a text run by copy to a IUIRichText object.
  virtual int RemoveText(FSint32 startIndex, FSint32 endIndex);                                                    // 0x20 Deletes text from a text object that has copied text.
  virtual int InsertRun(void *text, FSint32 text_len, TUIEncoding encoding, void *pInsertHere);                    // 0x24 Insert a text run by reference.
  virtual int ChangeRun(void *new_text, FSint32 length_text, TUIEncoding encoding, void *old_text, FSint32 hints); // 0x28 Change a referenced text run.
  virtual int RemoveRun(void *text);                                                                               // 0x2C Removes a referenced text run from a IUIRichText object.
  virtual int GetRunRange(void *text, FSint32 *startIndex, FSint32 *endIndex);                                     // 0x30 Gets the index range of a run in a IUIRichText.
  virtual int GetParagraphRange(FSint32 paragraph, FSint32 *pStartIndex, FSint32 *pEndIndex);                      // 0x34 Gets the index range of a paragraph in a TsText.
  virtual int GetParagraphCount(FSint32 *pParagraphCount);                                                         // 0x38 Gets the number of paragraphs in a TsText.
  virtual int GetParagraph(FSint32 char_index, FSint32 *pParagraphNumber);                                         // 0x3C Gets the paragraph number for a given index in TsText.
  virtual int GetLength(FSint32 *pLength);                                                                         // 0x40 Returns the text length in characters.
  virtual int GetChar(FSint32 index, FUint32 *pChar);                                                              // 0x44 Returns the character at a given index as a UTF32 value.
#ifdef DB3350
  virtual int unk_0x48();
#endif
  virtual int SetAlignment(TUITextAlignment align, FSint32 startIndex, FSint32 endIndex); // 0x48 0x4C Sets the paragraph alignment attribute.
  virtual int SetBackgroundColor(int color, FSint32 startIndex, FSint32 endIndex);        // 0x4C 0x50 Sets background color attribute.
  virtual int SetBiDiOverride(int textdir, FSint32 startIndex, FSint32 endIndex);         // 0x50 0x54 Sets the bidirectional override attribute.
  virtual int SetCharSpacing(float value, FSint32 startIndex, FSint32 endIndex);          // 0x54 0x58 Sets additional spacing between characters.
  virtual int SetEdgeColor(int color, FSint32 startIndex, FSint32 endIndex);              // 0x58 0x5C Sets edge color attribute.
  virtual int SetFontStyle(void *pIUIFontStyle, FSint32 startIndex, FSint32 endIndex);    // 0x5C 0x60 Sets the font style attribute.
  virtual int SetIndent(TUITextAlignment align, FSint32 startIndex, FSint32 endIndex);    // 0x60 0x64 Sets the amount the first line of each paragraph is indented.
  virtual int SetInlineObjectID(wchar_t imageID, FSint32 startIndex, FSint32 endIndex);   // 0x64 0x68
  virtual int SetInlineObjectMetrics(wchar_t imageID, TUIInlineObjectMetrics *pValue);    // 0x68 0x6C
  virtual int SetJustification(bool value, FSint32 startIndex, FSint32 endIndex);         // 0x6C 0x70
  virtual int SetLanguage(int language, FSint32 startIndex, FSint32 endIndex);            // 0x70 0x74
  virtual int SetLeftIndent(float value, FSint32 startIndex, FSint32 endIndex);           // 0x74 0x78 Sets the amount the left side of each paragraph in the range is indented.
  virtual int SetLinePaddingAfter(float value, FSint32 startIndex, FSint32 endIndex);     // 0x78 0x7C Sets an amount of extra space to pad after each line.
  virtual int SetLinePaddingBefore(float value, FSint32 startIndex, FSint32 endIndex);    // 0x7C 0x80 Sets an amount of extra space to pad before each line.
  virtual int SetLineSpacing(TUILineSpacing value, FSint32 startIndex, FSint32 endIndex); // 0x80 0x84 Sets line spacing attribute.
  virtual int SetLineSpacingAmount(float value, FSint32 startIndex, FSint32 endIndex);    // 0x84 0x88 Sets line spacing amount attribute.
  virtual int SetLineSpacingAttributeMode(bool isParaAttrib);                             // 0x88 0x8C
  virtual int SetOverline(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);      // 0x8C 0x90 Sets text overline attribute.
  virtual int SetOverlineColor(int color, FSint32 startIndex, FSint32 endIndex);          // 0x90 0x94 Sets overline color attribute.
  virtual int SetRightIndent(float value, FSint32 startIndex, FSint32 endIndex);          // 0x94 0x98 Sets the amount the right side of each paragraph in the range is indented.
  virtual int SetSpaceAfter(float value, FSint32 startIndex, FSint32 endIndex);           // 0x98 0x9C
  virtual int SetSpaceBefore(float value, FSint32 startIndex, FSint32 endIndex);          // 0x9C 0xA0
  virtual int SetStrikeout(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);     // 0xA0 0xA4
  virtual int SetStrikeoutColor(int color, FSint32 startIndex, FSint32 endIndex);         // 0xA4 0xA8
#ifdef DB3350v2
  virtual int unk_0xAC();
  virtual int unk_0xB0();
#endif
  virtual int SetTextColor(uint32_t color, FSint32 startIndex, FSint32 endIndex);                                        // 0xA8 0xAC 0xB4
  virtual int SetTextDirection(uint32_t value, FSint32 startIndex, FSint32 endIndex);                                    // 0xAC 0xB0 Sets the paragraph base text direction attribute.
  virtual int SetUnderline(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);                                    // 0xB0 0xB4
  virtual int SetUnderlineColor(uint32_t color, FSint32 startIndex, FSint32 endIndex);                                   // 0xB4 0xB8
  virtual int SetWordSpacing(float value, FSint32 startIndex, FSint32 endIndex);                                         // 0xB8 0xBC Sets additional spacing between words.
  virtual int GetAlignment(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUITextAlignment *pAlignment);         // 0xBC
  virtual int GetBackgroundColor(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, int *pBackgroundColor);          // 0xC0
  virtual int GetBiDiOverride(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUITextDirection *pValue);          // 0xC4
  virtual int GetCharSpacing(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *pSpacing);                    // 0xC8
  virtual int GetEdgeColor(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, int *pEdgeColor);                      // 0xCC
  virtual int GetFontStyle(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, void **ppIFontStyle);                  // 0xD0
  virtual int GetIndent(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *pIndent);                          // 0xD4
  virtual int GetInlineObjectID(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, wchar_t *id);                     // 0xD8
  virtual int GetInlineObjectMetrics(wchar_t id, TUIInlineObjectMetrics *pValue);                                        // 0xDC
  virtual int GetJustification(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, bool *justification_value);        // 0xE0
  virtual int GetLanguage(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, void *pLanguage);                       // 0xE4
  virtual int GetLeftIndent(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *indent_value);                 // 0xE8
  virtual int GetLinePaddingAfter(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *line_padding_value);     // 0xEC
  virtual int GetLinePaddingBefore(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *line_padding_value);    // 0xF0
  virtual int GetLineSpacing(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUILineSpacing *pLineSpacing);       // 0xF4
  virtual int GetLineSpacingAmount(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *pLineSpacingAmount);    // 0xF8
  virtual bool GetLineSpacingAttributeMode();                                                                            // 0xFC
  virtual int GetOverline(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUILineStyle *pValue);                  // 0x100
  virtual int GetOverlineColor(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, int *color);                       // 0x104
  virtual int GetRightIndent(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *indent_value);                // 0x108
  virtual int GetSpaceAfter(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *space);                        // 0x10C
  virtual int GetSpaceBefore(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *space);                       // 0x110
  virtual int GetStrikeout(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUILineStyle *strikeout_style);        // 0x114
  virtual int GetStrikeoutColor(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, int *color);                      // 0x118
  virtual int GetTextColor(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, int *color);                           // 0x11C
  virtual int GetTextDirection(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUITextDirection *pTextDirection); // 0x120
  virtual int GetUnderline(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, TUILineStyle *pUnderline);             // 0x124
  virtual int GetUnderlineColor(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, int *pUnderlineColor);            // 0x128
  virtual int GetWordSpacing(FSint32 index, FSint32 *startIndex, FSint32 *endIndex, float *word_spacing);                // 0x12C Get a string (UTF16)  virtual int InsertText(void* text, FSint32 text_len, TUIEncoding encoding, FSint32 insertIndex); 			//Inserts a text run by copy to a IUIRichText object.  virtual int InsertTextUTF16(u16* text, int length_text, FSint32 insertIndex); 					//Inserts a text run by copy to a IUIRichText object.  virtual int RemoveText(FSint32 startIndex, FSint32 endIndex); 							//Deletes text from a text object that has copied text.  virtual int InsertRun(void* text, FSint32 text_len, TUIEncoding encoding, void* pInsertHere); 				//Insert a text run by reference.  virtual int ChangeRun(void* new_text, FSint32 length_text, TUIEncoding encoding, void* old_text, FSint32 hints); 	//Change a referenced text run.  virtual int RemoveRun(void* text); 											//Removes a referenced text run from a IUIRichText object.  virtual int GetRunRange(void* text, FSint32* startIndex, FSint32* endIndex); 						//Gets the index range of a run in a IUIRichText.  virtual int GetParagraphRange(FSint32 paragraph, FSint32* pStartIndex, FSint32* pEndIndex); 				//Gets the index range of a paragraph in a TsText.  virtual int GetParagraphCount(FSint32* pParagraphCount); 								//Gets the number of paragraphs in a TsText.  virtual int GetParagraph(FSint32 char_index, FSint32* pParagraphNumber); 						//Gets the paragraph number for a given index in TsText.  virtual int GetLength(FSint32* pLength); 										//Returns the text length in characters.  virtual int GetChar(FSint32 index, FUint32* pChar); 									//Returns the character at a given index as a UTF32 value.  virtual int SetAlignment(TUITextAlignment value, FSint32 startIndex, FSint32 endIndex); 				//Sets the paragraph alignment attribute.  virtual int SetBackgroundColor(int color, FSint32 startIndex, FSint32 endIndex);					//Sets background color attribute.  virtual int SetBiDiOverride(TUITextDirection textdir, FSint32 startIndex, FSint32 endIndex);				//Sets the bidirectional override attribute.  virtual int SetCharSpacing(float value, FSint32 startIndex, FSint32 endIndex); 					//Sets additional spacing between characters.  virtual int SetEdgeColor(int color, FSint32 startIndex, FSint32 endIndex); 						//Sets edge color attribute.  virtual int SetFontStyle(void* pIUIFontStyle, FSint32 startIndex, FSint32 endIndex);					//Sets the font style attribute.  virtual int SetIndent(TUITextAlignment align, FSint32 startIndex, FSint32 endIndex);					//Sets the amount the first line of each paragraph is indented.  virtual int SetInlineObjectID(wchar_t imageID, FSint32 startIndex, FSint32 endIndex);  virtual int SetInlineObjectMetrics(wchar_t imageID, TUIInlineObjectMetrics* pValue);  virtual int SetJustification(bool value, FSint32 startIndex, FSint32 endIndex);  virtual int SetLanguage(int language, FSint32 startIndex, FSint32 endIndex);  virtual int SetLeftIndent(float value, FSint32 startIndex, FSint32 endIndex);						//Sets the amount the left side of each paragraph in the range is indented.  virtual int SetLinePaddingAfter(float value, FSint32 startIndex, FSint32 endIndex);					//Sets an amount of extra space to pad after each line.  virtual int SetLinePaddingBefore(float value, FSint32 startIndex, FSint32 endIndex);					//Sets an amount of extra space to pad before each line.  virtual int SetLineSpacing(TUILineSpacing value, FSint32 startIndex, FSint32 endIndex);				//Sets line spacing attribute.  virtual int SetLineSpacingAmount(float value, FSint32 startIndex, FSint32 endIndex);					//Sets line spacing amount attribute.  virtual int SetLineSpacingAttributeMode(bool isParaAttrib);  virtual int SetOverline(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);					//Sets text overline attribute.  virtual int SetOverlineColor(int color, FSint32 startIndex, FSint32 endIndex);						//Sets overline color attribute.  virtual int SetRightIndent(float value, FSint32 startIndex, FSint32 endIndex);						//Sets the amount the right side of each paragraph in the range is indented.  virtual int SetSpaceAfter(float value, FSint32 startIndex, FSint32 endIndex);  virtual int SetSpaceBefore(float value, FSint32 startIndex, FSint32 endIndex);  virtual int SetStrikeout(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);  virtual int SetStrikeoutColor(int color, FSint32 startIndex, FSint32 endIndex);  virtual int SetTextColor(int color, FSint32 startIndex, FSint32 endIndex);  virtual int SetTextDirection(TUITextDirection value, FSint32 startIndex, FSint32 endIndex);				//Sets the paragraph base text direction attribute.  virtual int SetUnderline(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);  virtual int SetUnderlineColor(int color, FSint32 startIndex, FSint32 endIndex);  virtual int SetWordSpacing(float value, FSint32 startIndex, FSint32 endIndex);						//Sets additional spacing between words.  virtual int GetAlignment(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUITextAlignment* pAlignment);  virtual int GetBackgroundColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* pBackgroundColor);  virtual int GetBiDiOverride(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUITextDirection* pValue);  virtual int GetCharSpacing(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* pSpacing);  virtual int GetEdgeColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* pEdgeColor);  virtual int GetFontStyle(FSint32 index, FSint32* startIndex, FSint32* endIndex, void** ppIFontStyle);  virtual int GetIndent(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* pIndent);  virtual int GetInlineObjectID(FSint32 index, FSint32* startIndex, FSint32* endIndex, wchar_t* id);  virtual int GetInlineObjectMetrics(wchar_t id, TUIInlineObjectMetrics* pValue);  virtual int GetJustification(FSint32 index, FSint32* startIndex, FSint32* endIndex, bool* justification_value);  virtual int GetLanguage(FSint32 index, FSint32* startIndex, FSint32* endIndex, void* pLanguage);  virtual int GetLeftIndent(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* indent_value);  virtual int GetLinePaddingAfter(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* line_padding_value);  virtual int GetLinePaddingBefore(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* line_padding_value);  virtual int GetLineSpacing(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineSpacing* pLineSpacing);  virtual int GetLineSpacingAmount(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* pLineSpacingAmount);  virtual bool GetLineSpacingAttributeMode();  virtual int GetOverline(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineStyle* pValue);  virtual int GetOverlineColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* color);  virtual int GetRightIndent(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* indent_value);  virtual int GetSpaceAfter(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* space);  virtual int GetSpaceBefore(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* space);  virtual int GetStrikeout(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineStyle* strikeout_style);  virtual int GetStrikeoutColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* color);  virtual int GetTextColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* color);  virtual int GetTextDirection(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUITextDirection* pTextDirection);  virtual int GetUnderline(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineStyle* pUnderline);  virtual int GetUnderlineColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* pUnderlineColor);  virtual int GetWordSpacing(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* word_spacing);};
};

class ITextRenderingFactory : public IUnknown
{
public:
  virtual int CreateFontResourceManager(IUnknown *pIUIFontResourceManager);
  virtual int CreateFontStyleManager(IUnknown *pIUIFontStyleManager);
  virtual int CreateRichText(IRichText **pRichText);
  virtual int CreateTextContainer(IUnknown *pIUITextContainer);
  virtual int CreateRichTextLayout(IRichText *pRichText, IUIRichTextLayoutControl *pIUIRichTextLayoutControl, IUIRichTextLayoutOptions *pIUIRichTextLayoutOptions, IRichTextLayout **pRichTextLayout);
  virtual int CreateSingleLineLayout(IUIRichTextLayoutControl *pIUIRichTextLayoutControl, IUIRichTextLayoutOptions *pIUIRichTextLayoutOptions, IUnknown **pIUISingleLineLayout);
  virtual int CreateRichTextLayoutControl(IUIRichTextLayoutControl **pIUIRichTextLayoutControl);
  virtual int CreateRichTextLayoutOptions(IUIRichTextLayoutOptions **pIUIRichTextLayoutOptions);
  virtual int CreatePolygon(IUnknown **pIUIPolygon);
  virtual int CreateBasicTextHandler(IUnknown **pIUIBasicTextHandling);
};

class ITextRenderingManager : public IUnknown
{
public:
  virtual int GetTextRenderingFactory(ITextRenderingFactory **pTextRenderingFactory);
  virtual int GetFontConfigFilePath(IUnknown **pIString);
  virtual int GetFontEngineConfigFilePath(IUnknown **pIString);
};

#endif
