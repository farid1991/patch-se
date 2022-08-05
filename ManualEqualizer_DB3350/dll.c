#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
#include "dll.h"

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
void dll_DrawString(int font_size, TEXTID text_id, int align, int x1, int y1, int x2, int y2, unsigned int pen_color)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IUIRichTextLayoutOptions * pIUIRichTextLayoutOptions = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pTextObject = NULL;
  IUnknown *pGC = NULL;
  IFont *pFont = NULL;

  int fontsize_wo_style = font_size & 0xFF;
  int font_style = font_size >> 8;
  dll_SetFont(fontsize_wo_style, font_style, &pFont);

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pIUIRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, NULL, pIUIRichTextLayoutOptions, &pRichTextLayout);

  TextObject_SetText(pTextObject, text_id);
  TextObject_SetFont(pTextObject, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  
  pTextObject->SetTextColor(pen_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

  pIUIRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);

  int lineWidth = x2 - x1;
  pRichTextLayout->Compose(lineWidth);

  TUIRectangle rect;
  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = x2 - x1;
  rect.Size.Height = y2 - y1;

  DisplayGC_AddRef(get_DisplayGC(), &pGC);
  pRichTextLayout->Display(pGC, x1, y1, &rect);

  if (pTextRenderingManager)
    pTextRenderingManager->Release();
  if (pTextRenderingFactory)
    pTextRenderingFactory->Release();
  if (pRichTextLayout)
    pRichTextLayout->Release();
  if (pTextObject)
    pTextObject->Release();
  if (pGC)
    pGC->Release();
}
#endif

// GC_PutChar ----------------------------------------------------
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
void dll_GC_PutChar(GC *gc, int x, int y, int w, int h, IMAGEID imageID)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;
  IUnknown *pGC = NULL;

  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  rect.Size.Width = w;
  rect.Size.Height = h;

  CoCreateInstance(CID_CUIImageManager, IID_IUIImageManager, PPINTERFACE(&pIUIImageManager));
  pIUIImageManager->CreateFromIcon(imageID, &pUIImage);

  DisplayGC_AddRef(gc, &pGC);

  pIUIImageManager->Draw(pUIImage, pGC, rect);

  if (pIUIImageManager)
    pIUIImageManager->Release();
  if (pUIImage)
    pUIImage->Release();
  if (pGC)
    pGC->Release();
}
#endif
