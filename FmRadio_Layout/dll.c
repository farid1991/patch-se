#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
#include "dll.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
// SetFont ----------------------------------------------------
void Get_IUIFontManager(IFontManager **ppIFontManager)
{
  CoCreateInstance(CID_IUIFontManager, IID_IUIFontManager, PPINTERFACE(ppIFontManager));
}

void dll_SetFont(int font_size, uint16_t font_style, IFont **ppFont)
{
  IFontManager *pFontManager = NULL;
  IFontFactory *pFontFactory = NULL;
  TUIFontData pFontData;
  memset(&pFontData, NULL, sizeof(TUIFontData));

  Get_IUIFontManager(&pFontManager);
  pFontManager->GetFontFactory(&pFontFactory);

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

void Get_ITextRenderingManager(ITextRenderingManager **ppITextRenderingManager)
{
  CoCreateInstance(CID_ITextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(ppITextRenderingManager));
}

void dll_DrawString(int font_size, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color)
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

  Get_ITextRenderingManager(&pTextRenderingManager);

  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, 0, 0, &pRichTextLayout);

  TextObject_SetText(pTextObject, text);
  TextObject_SetFont(pTextObject, pFont, FSINT32_MIN, FSINT32_MAX);
  pTextObject->SetTextColor(pen_color, FSINT32_MIN, FSINT32_MAX);
  pTextObject->SetAlignment((TUITextAlignment)align, FSINT32_MIN, FSINT32_MAX);
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
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210)
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
  long image_width = NULL;
  long image_height = NULL;

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
#ifdef DB3150v2
  return GetImageHeight_int(imageID);
#else
  IUIImage *pUIImage = NULL;
  IUIImageManager *pIUIImageManager = NULL;
  long image_width = NULL;
  long image_height = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);

  if (pIUIImageManager)
    pIUIImageManager->Release();
  if (pUIImage)
    pUIImage->Release();

  return image_height;
#endif
}
#endif
