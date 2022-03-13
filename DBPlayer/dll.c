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
  pTextRenderingFactory->CreateRichTextLayout(pTextObject, NULL, NULL, &pRichTextLayout);

  TextObject_SetText(pTextObject, text);
  TextObject_SetFont(pTextObject, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetTextColor(text_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pTextObject->SetAlignment(align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

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

int dll_Disp_GetTextIDWidth(TEXTID strid, int len)
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

  int font_size = FONT_E_20R & 0xFF;
  int font_style = FONT_E_20R >> 8;
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
#endif

// GC_PutChar ----------------------------------------------------
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
void Get_IUIImageManager(IUIImageManager **ppIUIImageManager)
{
  CoCreateInstance(CID_CUIImageManager, IID_IUIImageManager, PPINTERFACE(ppIUIImageManager));
}

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

  Get_IUIImageManager(&pIUIImageManager);
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

void *dll_MetaData_Desc_Create(wchar_t *path, wchar_t *name)
{
  METADATA_DESC *MetaData_Desc = (METADATA_DESC *)malloc(sizeof(METADATA_DESC));
  MetaData_Desc->pIMetaData = 0;
  MetaData_Desc->artist[0] = 0;
  MetaData_Desc->title[0] = 0;
  MetaData_Desc->album[0] = 0;
  MetaData_Desc->year[0] = 0;
  MetaData_Desc->genre[0] = 0;
  MetaData_Desc->x6[0] = 0;
  MetaData_Desc->x7[0] = 0;
  CoCreateInstance(CID_CMetaData, IID_IMetaData, PPINTERFACE(&MetaData_Desc->pIMetaData));
  MetaData_Desc->pIMetaData->SetFile(path, name);
  return (MetaData_Desc);
}

void dll_MetaData_Desc_Destroy(void *MetaData_Desc)
{
  if (((METADATA_DESC *)MetaData_Desc)->pIMetaData)
    ((METADATA_DESC *)MetaData_Desc)->pIMetaData->Release();
  if (MetaData_Desc)
    mfree(MetaData_Desc);
}

wchar_t *dll_MetaData_Desc_GetTags(void *MetaData_Desc, int tagID)
{
  METADATA_DESC *mdd = (METADATA_DESC *)MetaData_Desc;
  wchar_t *buf;
  switch (tagID)
  {
  case TMetadataTagId_Artist:
    buf = mdd->artist;
    break;
  case TMetadataTagId_Title:
    buf = mdd->title;
    break;
  case TMetadataTagId_Album:
    buf = mdd->album;
    break;
  case TMetadataTagId_Year:
    buf = mdd->year;
    break;
  case TMetadataTagId_Genre:
    buf = mdd->genre;
    break;
  case TMetadataTagId_x6:
    buf = mdd->x6;
    break;
  case TMetadataTagId_x7:
    buf = mdd->x7;
    break;
  }
  mdd->pIMetaData->GetTag(tagID, buf);
  return (buf);
}

int dll_MetaData_Desc_GetTrackNum(void *MetaData_Desc)
{
  int track_num;
  ((METADATA_DESC *)MetaData_Desc)->pIMetaData->GetTrackNum(NULL, &track_num);
  return (track_num);
}

int dll_MetaData_Desc_HasAlbumArt(void *MetaData_Desc, wchar_t *path, wchar_t *name)
{
  if (((METADATA_DESC *)MetaData_Desc)->pIMetaData->HasAlbumArt(path, name))
    return TRUE;
  return FALSE;
}

int dll_MetaData_Desc_GetCoverInfo(void *MetaData_Desc, char *cover_type, int *size, int *cover_offset)
{
  COVER_INFO_DESC cover_info;
  if (((METADATA_DESC *)MetaData_Desc)->pIMetaData->GetCoverInfo(&cover_info) < 0)
    return FALSE;
  *cover_type = cover_info.cover_type;
  *size = cover_info.size;
  *cover_offset = cover_info.cover_offset;
  return TRUE;
}
