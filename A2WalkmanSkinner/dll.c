#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "main.h"

#if defined(DB3200) || defined(DB3210)
// SetFont ----------------------------------------------------
void dll_SetFont(int font, IFont **ppFont)
{
  IFontManager *pFontManager = NULL;
  IFontFactory *pFontFactory = NULL;
  TUIFontData pFontData;
  memset(&pFontData, NULL, sizeof(TUIFontData));

  CoCreateInstance(CID_CUIFontManager, IID_IUIFontManager, PPINTERFACE(&pFontManager));
  pFontManager->GetFontFactory(&pFontFactory);
  pFontFactory->GetDefaultFontSettings(UIFontSizeLarge, &pFontData);

  int font_size = font & 0xFF;
  int font_style = font >> 8;
  pFontData.size = (float)font_size;
  pFontData.emphasis = (TUIEmphasisStyle)font_style;
  pFontFactory->CreateDefaultFont(&pFontData, ppFont);

  if (pFontFactory)
    pFontFactory->Release();
  if (pFontManager)
    pFontManager->Release();
}

// DrawString ----------------------------------------------------
void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int text_color)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IUIRichTextLayoutOptions *pRichTextLayoutOptions = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pRichText = NULL;
  IUnknown *pCanvas = NULL;
  IFont *pFont = NULL;

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pRichText);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pRichText, NULL, pRichTextLayoutOptions, &pRichTextLayout);

  dll_SetFont(font, &pFont);

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

int dll_Disp_GetTextIDWidth(int font, TEXTID text_id, int len)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pRichText = NULL;
  IFont *pFont = NULL;

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pRichText);
  pTextRenderingFactory->CreateRichTextLayout(pRichText, NULL, NULL, &pRichTextLayout);

  dll_SetFont(font, &pFont);

  TEXTID temp_strid;
  if (len == TEXTID_ANY_LEN)
  {
    temp_strid = TextID_Copy(text_id);
  }
  else
  {
    wchar_t *buf = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
    TextID_GetWString(text_id, buf, len + 1);
    temp_strid = TextID_Create(buf, ENC_UCS2, len);
    mfree(buf);
  }

  int width = RichTextLayout_GetTextWidth(temp_strid, pRichTextLayout, pFont);
  TextID_Destroy(temp_strid);

  if (pTextRenderingManager)
    pTextRenderingManager->Release();
  if (pTextRenderingFactory)
    pTextRenderingFactory->Release();
  if (pRichTextLayout)
    pRichTextLayout->Release();
  if (pRichText)
    pRichText->Release();
  if (pFont)
    pFont->Release();

  return (width);
}

// GC_PutChar ----------------------------------------------------
void Get_IUIImageManager(IUIImageManager **ppIUIImageManager)
{
  CoCreateInstance(CID_CUIImageManager, IID_IUIImageManager, PPINTERFACE(ppIUIImageManager));
}

void dll_GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID image_id)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;
  IUnknown *pCanvas = NULL;

  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  rect.Size.Width = width;
  rect.Size.Height = height;

  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(image_id, &pUIImage);

  DisplayGC_AddRef(gc, &pCanvas);
  pIUIImageManager->Draw(pUIImage, pCanvas, rect);

  if (pCanvas)
    pCanvas->Release();
  if (pUIImage)
    pUIImage->Release();
  if (pIUIImageManager)
    pIUIImageManager->Release();
}

int dll_GetImageWidth(IMAGEID image_id)
{
  IUIImage *pUIImage = NULL;
  IUIImageManager *pIUIImageManager = NULL;
  int image_width = NULL;
  int image_height = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(image_id, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);

  if (pUIImage)
    pUIImage->Release();
  if (pIUIImageManager)
    pIUIImageManager->Release();

  return image_width;
}

int dll_GetImageHeight(IMAGEID image_id)
{
  IUIImage *pUIImage = NULL;
  IUIImageManager *pIUIImageManager = NULL;
  int image_width = NULL;
  int image_height = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(image_id, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);

  if (pUIImage)
    pUIImage->Release();
  if (pIUIImageManager)
    pIUIImageManager->Release();

  return image_height;
}
#endif

void GUIObject_SetAnimation(GUI *gui, int anim)
{
  DispObject_SetAnimation(GUIObject_GetDispObject(gui), anim);
}
