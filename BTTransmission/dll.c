#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
#include "dll.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
// SetFont ----------------------------------------------------
void dll_SetFont(int font_size, uint16_t font_style, IFont **ppFont)
{
  IFontManager *pFontManager = NULL;
  IFontFactory *pFontFactory = NULL;
  TUIFontData pFontData;
  memset(&pFontData, NULL, sizeof(TUIFontData));

  CoCreateInstance(CID_CUIFontManager, IID_IUIFontManager, PPINTERFACE(&pFontManager));
  pFontManager->GetFontFactory(&pFontFactory);

  pFontFactory->GetDefaultFontSettings(UIFontSizeLarge, &pFontData);
  pFontData.size = font_size;
  TUIEmphasisStyle fontstyle;
  switch (font_style)
  {
  case 1:
    fontstyle = UI_Emphasis_Bold;
    break;
  case 2:
    fontstyle = UI_Emphasis_Italic;
    break;
  case 3:
    fontstyle = UI_Emphasis_BoldItalic;
    break;
  default:
    fontstyle = UI_Emphasis_Normal;
    break;
  }
  pFontData.emphasis = fontstyle;

  pFontFactory->CreateDefaultFont(&pFontData, ppFont);

  if (pFontManager)
    pFontManager->Release();
  if (pFontFactory)
    pFontFactory->Release();
}

// DrawString ----------------------------------------------------
void dll_DrawString(int font_size, TEXTID text, int align, int x1, int y1, int x2, int y2, int text_color)
{
  TUIRectangle rect;
  int lineWidth = x2 - x1;

  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pTextObject = NULL;
  IUnknown *pGC = NULL;
  IFont *pFont = NULL;

  int fontsize_wo_style = (font_size & 0xFF);
  int font_style = font_size >> 8;
  dll_SetFont(fontsize_wo_style, font_style, &pFont);

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, 0, 0, &pRichTextLayout);

  TextObject_SetText(pTextObject, text);
  TextObject_SetFont(pTextObject, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetTextColor(text_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetAlignment(align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichTextLayout->Compose(lineWidth);

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
void dll_GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID imageID)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;
  IUnknown *pGC = NULL;

  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  rect.Size.Width = width;
  rect.Size.Height = height;

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
