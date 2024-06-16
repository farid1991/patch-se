#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
#include "dll.h"

#if defined(DB3200) || defined(DB3210)
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
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color)
{
  TUIRectangle rect;
  int lineWidth = x2 - x1;

  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IUIRichTextLayoutOptions * pIUIRichTextLayoutOptions = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pTextObject = NULL;
  IUnknown *pGC = NULL;
  IFont *pFont = NULL;

  int font_size = font & 0xFF;
  int font_style = font >> 8;
  dll_SetFont(font_size, font_style, &pFont);

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pIUIRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, 0, 0, &pRichTextLayout);

  TextObject_SetText(pTextObject, text);
  TextObject_SetFont(pTextObject, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetTextColor(pen_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

  pIUIRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);
  pRichTextLayout->Compose(lineWidth);

  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = lineWidth;
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

// GC_PutChar ----------------------------------------------------
void Get_IUIImageManager(IUIImageManager **ppIUIImageManager)
{
  CoCreateInstance(CID_CUIImageManager, IID_IUIImageManager, PPINTERFACE(ppIUIImageManager));
}

void dll_GC_PutChar(int x, int y, int width, int height, IMAGEID imageID)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;
  IUnknown *pGC = NULL;

  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  rect.Size.Width = width;
  rect.Size.Height = height;

  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(imageID, &pUIImage);

  DisplayGC_AddRef(get_DisplayGC(), &pGC);

  pIUIImageManager->Draw(pUIImage, pGC, rect);

  if (pIUIImageManager)
    pIUIImageManager->Release();
  if (pUIImage)
    pUIImage->Release();
  if (pGC)
    pGC->Release();
}
// GetImageWidthHeight ----------------------------------------------------
int dll_GetImageWidth(IMAGEID imageID)
{
  IUIImage *pUIImage = NULL;
  IUIImageManager *pIUIImageManager = NULL;
  int image_width = NULL;
  int image_height = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);

  if (pIUIImageManager)
    pIUIImageManager->Release();
  if (pUIImage)
    pUIImage->Release();

  return image_width;
}

int dll_GetImageHeight(IMAGEID imageID)
{
  IUIImage *pUIImage = NULL;
  IUIImageManager *pIUIImageManager = NULL;
  int image_width = NULL;
  int image_height = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);

  if (pIUIImageManager)
    pIUIImageManager->Release();
  if (pUIImage)
    pUIImage->Release();

  return image_height;
}
#endif
