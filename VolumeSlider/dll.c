#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "main.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
// SetFont ----------------------------------------------------
void dll_SetFont(int font_size, int font_style, IFont **ppFont)
{
  IFontManager *pFontManager = NULL;
  IFontFactory *pFontFactory = NULL;
  TUIFontData pFontData;
  memset(&pFontData, NULL, sizeof(TUIFontData));

  CoCreateInstance(CID_CUIFontManager, IID_IUIFontManager, PPINTERFACE(&pFontManager));
  pFontManager->GetFontFactory(&pFontFactory);

  pFontFactory->GetDefaultFontSettings(UIFontSizeLarge, &pFontData);
  pFontData.size = (float)font_size;
  pFontData.emphasis = (TUIEmphasisStyle)font_style;
  pFontFactory->CreateDefaultFont(&pFontData, ppFont);

  if (pFontManager)
    pFontManager->Release();
  if (pFontFactory)
    pFontFactory->Release();
}

// DrawString ----------------------------------------------------
void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int text_color)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IUIRichTextLayoutOptions * pRichTextLayoutOptions = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pRichText = NULL;
  IUnknown *pCanvas = NULL;
  IFont *pFont = NULL;

  int font_size = font & 0xFF;
  int font_style = font >> 8;
  dll_SetFont(font_size, font_style, &pFont);

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pRichText);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pRichText, NULL, pRichTextLayoutOptions, &pRichTextLayout);

  TextObject_SetText(pRichText, text_id);
  TextObject_SetFont(pRichText, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichText->SetTextColor(text_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichText->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

  pRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);

  TUIRectangle rect;
  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = x2 - x1;
  rect.Size.Height = y2 - y1;
  pRichTextLayout->Compose(rect.Size.Width);
  DisplayGC_AddRef(get_DisplayGC(), &pCanvas);
  pRichTextLayout->Display(pCanvas, x1, y1, &rect);

  if (pTextRenderingManager)
    pTextRenderingManager->Release();
  if (pTextRenderingFactory)
    pTextRenderingFactory->Release();
  if (pRichTextLayoutOptions)
    pRichTextLayoutOptions->Release();
  if (pRichTextLayout)
    pRichTextLayout->Release();
  if (pRichText)
    pRichText->Release();
  if (pCanvas)
    pCanvas->Release();
  if (pFont)
    pFont->Release();
}

#endif
