#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
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
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int text_color)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IUIRichTextLayoutOptions * pIUIRichTextLayoutOptions = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pTextObject = NULL;
  IUnknown *pICanvas = NULL;
  IFont *pFont = NULL;

  int font_size = font & 0xFF;
  int font_style = font >> 8;
  dll_SetFont(font_size, font_style, &pFont);

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pIUIRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, NULL, pIUIRichTextLayoutOptions, &pRichTextLayout);

  TextObject_SetText(pTextObject, text);
  TextObject_SetFont(pTextObject, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetTextColor(text_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

  pIUIRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);

  int lineWidth = x2 - x1;
  pRichTextLayout->Compose(lineWidth);

  TUIRectangle rect;
  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = x2 - x1;
  rect.Size.Height = y2 - y1;

  DisplayGC_AddRef(get_DisplayGC(), &pICanvas);
  pRichTextLayout->Display(pICanvas, x1, y1, &rect);

  if (pTextRenderingManager)
    pTextRenderingManager->Release();
  if (pTextRenderingFactory)
    pTextRenderingFactory->Release();
  if (pRichTextLayout)
    pRichTextLayout->Release();
  if (pTextObject)
    pTextObject->Release();
  if (pICanvas)
    pICanvas->Release();
}

int dll_Disp_GetTextIDWidth(int font, TEXTID strid, int len)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pTextObject = NULL;

  int width = 0;
  TEXTID temp_strid = EMPTY_TEXTID;

  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, NULL, NULL, &pRichTextLayout);

  IFont *pFont = NULL;

  int font_size = font & 0xFF;
  int font_style = font >> 8;
  dll_SetFont(font_size, font_style, &pFont);

  if (len == TEXTID_ANY_LEN)
    temp_strid = TextID_Copy(strid);
  else
  {
    wchar_t *buf = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
    TextID_GetWString(strid, buf, len + 1);
    temp_strid = TextID_Create(buf, ENC_UCS2, len);
    mfree(buf);
  }

  width = RichTextLayout_GetTextWidth(temp_strid, pRichTextLayout, pFont);

  TextID_Destroy(temp_strid);

  if (pTextRenderingManager)
    pTextRenderingManager->Release();
  if (pTextRenderingFactory)
    pTextRenderingFactory->Release();
  if (pRichTextLayout)
    pRichTextLayout->Release();
  if (pTextObject)
    pTextObject->Release();

  return (width);
}

// GC_PutChar ----------------------------------------------------
void Get_IUIImageManager(IUIImageManager **ppIUIImageManager)
{
  CoCreateInstance(CID_CUIImageManager, IID_IUIImageManager, PPINTERFACE(ppIUIImageManager));
}

void dll_GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID imageID)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;
  IUnknown *pICanvas = NULL;

  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  rect.Size.Width = width;
  rect.Size.Height = height;

  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(imageID, &pUIImage);

  DisplayGC_AddRef(gc, &pICanvas);

  pIUIImageManager->Draw(pUIImage, pICanvas, rect);

  if (pIUIImageManager)
    pIUIImageManager->Release();
  if (pUIImage)
    pUIImage->Release();
  if (pICanvas)
    pICanvas->Release();
}

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

METADATA_DESC *dll_MetaData_Desc_Create(wchar_t *path, wchar_t *name)
{
  METADATA_DESC *MetaData_Desc = (METADATA_DESC *)malloc(sizeof(METADATA_DESC));
  MetaData_Desc->pIMetaData = NULL;
  MetaData_Desc->artist[0] = NULL;
  MetaData_Desc->title[0] = NULL;
  MetaData_Desc->album[0] = NULL;
  MetaData_Desc->year[0] = NULL;
  MetaData_Desc->genre[0] = NULL;
  MetaData_Desc->x6[0] = NULL;
  MetaData_Desc->x7[0] = NULL;
  CoCreateInstance(CID_CMetaData, IID_IMetaData, PPINTERFACE(&MetaData_Desc->pIMetaData));
  MetaData_Desc->pIMetaData->SetFile(path, name);
  return MetaData_Desc;
}

void dll_MetaData_Desc_Destroy(METADATA_DESC *MetaData_Desc)
{
  if (MetaData_Desc->pIMetaData)
    MetaData_Desc->pIMetaData->Release();
  if (MetaData_Desc)
    mfree(MetaData_Desc);
}

BOOL dll_MetaData_Desc_HasAlbumArt(METADATA_DESC *MetaData_Desc, wchar_t *path, wchar_t *name)
{
  if (MetaData_Desc->pIMetaData->HasAlbumArt(path, name))
    return TRUE;
  return FALSE;
}

int dll_MetaData_Desc_GetCoverInfo(METADATA_DESC *MetaData_Desc, char *cover_type, int *size, int *cover_offset)
{
  COVER_INFO_DESC cover_info;
  if (MetaData_Desc->pIMetaData->GetCoverInfo(&cover_info) < 0)
    return FALSE;
  *cover_type = cover_info.cover_type;
  *size = cover_info.size;
  *cover_offset = cover_info.cover_offset;
  return TRUE;
}
