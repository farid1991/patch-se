#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\InternalFunction.h"


/*
typedef struct _FONT
{
  IFont* pFont;
}FONT;
*/
IFont* Create_IFont()
{
  IFont *pIFont = (IFont*)malloc(sizeof(IFont));
  memset(pIFont, NULL, sizeof(IFont));
  set_envp(NULL, "IFont", (OSADDRESS)pIFont);
  return pIFont;
}

IFont* Get_IFont()
{
  return (IFont*) get_envp(NULL,"IFont");
}

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
int SetFont( int font_size )
{
  UUID IID_IFontManager = {0x95,0xD0,0x5F,0xCA,0x0F,0x30,0x4F,0x92,0x94,0x3B,0x13,0x89,0x21,0x2F,0x09,0xD7};
  UUID CID_CFontManager = {0x82,0xAC,0x97,0x9B,0x58,0x44,0x41,0x39,0xA0,0xD3,0xE6,0xCF,0x72,0xB5,0x80,0x69};
  
  IFontManager * pFontManager = NULL;
  IFontFactory * pFontFactory = NULL;
  TUIFontData pFontData;
  memset(&pFontData,NULL,sizeof(TUIFontData));
  
  IFont* pFont = Get_IFont();
  if(!pFont) pFont = Create_IFont();
  if (pFont)
  {
    pFont->Release();
    pFont = NULL;
  }
  
  CoCreateInstance(&CID_CFontManager,&IID_IFontManager,PPINTERFACE(&pFontManager));
  pFontManager->GetFontFactory(&pFontFactory);
  
  int font_size_without_style = font_size&0xFF;
  
  pFontFactory->GetDefaultFontSettings(UIFontSizeLarge,&pFontData);
  pFontData.size = (float)font_size_without_style;
  pFontData.TUIEmphasisStyle = font_size>>8;
  pFontFactory->CreateDefaultFont(&pFontData,&pFont);
  
  if (pFontManager) pFontManager->Release();
  if (pFontFactory) pFontFactory->Release();
  
  return(1);
}
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void DrawString( TEXTID txt, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color )
{
  UUID IID_ITextRenderingManager={0xCE,0x91,0x7B,0x62,0xE3,0x3A,0x4D,0xC7,0x85,0x24,0x79,0x1E,0x6F,0x01,0x03,0x09};
  UUID CID_CTextRenderingManager={0xCF,0xDC,0xCD,0x9D,0xAE,0x6D,0x40,0xAE,0xB3,0x97,0x38,0xB0,0x5D,0x2D,0x35,0x9D};
  
  TUIRectangle rect;
  
  int lineWidth = x2-x1;
  
  ITextRenderingManager * pTextRenderingManager = NULL;
  ITextRenderingFactory * pTextRenderingFactory = NULL;
  IRichTextLayout * pRichTextLayout = NULL;
  IRichText * pTextObject = NULL;
  IUnknown * pGC = NULL;
  
  CoCreateInstance(&CID_CTextRenderingManager,&IID_ITextRenderingManager,PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject,NULL,NULL,&pRichTextLayout);
  
  IFont* pFont = Get_IFont();
  if (!pFont) SetFont(20);
  
  TextObject_SetText(pTextObject,txt);
  TextObject_SetFont(pTextObject, pFont, START_INDEX, END_INDEX);
  pTextObject->SetTextColor(pen_color, START_INDEX, END_INDEX);
  
  pTextObject->SetAlignment(align, START_INDEX, END_INDEX);
  
  pRichTextLayout->Compose(lineWidth);
  
  rect.Point.X=x1;
  rect.Point.Y=y1;
  rect.Size.Width=x2-x1;
  rect.Size.Height=y2-y1;
  
  DisplayGC_AddRef(get_DisplayGC(),&pGC);
  
  pRichTextLayout->Display(pGC,x1,y1,&rect);
  
  if (pTextRenderingManager) pTextRenderingManager->Release();
  if (pTextRenderingFactory) pTextRenderingFactory->Release();
  if (pRichTextLayout) pRichTextLayout->Release();
  if (pTextObject) pTextObject->Release();
  if (pGC) pGC->Release();
}
#endif

void Get_IUIImageManager(IUIImageManager** ppIImageManager)
{
  UUID IID_IImageManager={0x63,0xEF,0xA5,0x31,0xFF,0xD1,0x4E,0x25,0xA6,0x24,0x60,0x0A,0x96,0x81,0x3F,0xC5};
  UUID CID_CImageManager={0x86,0x2D,0xF9,0x95,0x1C,0x3B,0x4B,0x24,0xB7,0x4D,0x8F,0x98,0x70,0x1E,0x5D,0x14};
  CoCreateInstance(&CID_CImageManager, &IID_IImageManager, PPINTERFACE(ppIImageManager));
}

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void GC_PutChar( GC* gc, int x, int y, int width, int height, IMAGEID imageID )
{
  IUIImageManager * pIUIImageManager = NULL;
  IUIImage * pUIImage = NULL;
  IUnknown * pGC = NULL;
  
  TUIRectangle rect;
  rect.Point.X=x;
  rect.Point.Y=y;
  rect.Size.Width=width;
  rect.Size.Height=height;
  
  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(imageID,&pUIImage);
  
  DisplayGC_AddRef(gc,&pGC);
  
  pIUIImageManager->Draw(pUIImage,pGC,rect);
  
  if (pIUIImageManager) pIUIImageManager->Release();
  if (pUIImage) pUIImage->Release();
  if (pGC) pGC->Release();

}
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
int GetImageWidth( IMAGEID imageID )
{
  IUIImage * pUIImage = NULL;
  IUIImageManager * pIUIImageManager = NULL;
  long image_width = NULL;
  long image_height = NULL;
  
  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID,&pUIImage)>=0)
      pUIImage->GetDimensions(&image_width,0,&image_height,0);
  
  if (pIUIImageManager) pIUIImageManager->Release();
  if (pUIImage) pUIImage->Release();
  return(image_width);
}
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
int GetImageHeight( IMAGEID imageID )
{
  IUIImage * pUIImage = NULL;
  IUIImageManager * pIUIImageManager = NULL;
  long image_width = NULL;
  long image_height = NULL;
  
  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID,&pUIImage)>=0) pUIImage->GetDimensions(&image_width,0,&image_height,0);
 
  if (pIUIImageManager) pIUIImageManager->Release();
  if (pUIImage) pUIImage->Release();
  return(image_height);
}
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
int Disp_GetTextIDWidth( TEXTID strid, int len )
{
  UUID IID_ITextRenderingManager = {0xCE,0x91,0x7B,0x62,0xE3,0x3A,0x4D,0xC7,0x85,0x24,0x79,0x1E,0x6F,0x01,0x03,0x09};
  UUID CID_CTextRenderingManager = {0xCF,0xDC,0xCD,0x9D,0xAE,0x6D,0x40,0xAE,0xB3,0x97,0x38,0xB0,0x5D,0x2D,0x35,0x9D};
  
  ITextRenderingManager * pTextRenderingManager = NULL;
  ITextRenderingFactory * pTextRenderingFactory = NULL;
  IRichTextLayout * pRichTextLayout = NULL;
  IRichText * pTextObject = NULL;
  
  int width = 0;
  TEXTID temp_strid = EMPTY_TEXTID;

  CoCreateInstance(&CID_CTextRenderingManager,&IID_ITextRenderingManager,PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject,NULL,NULL,&pRichTextLayout);

  IFont* pFont = Get_IFont();
  if (!pFont) SetFont(20);
  
  if (len == TEXTID_ANY_LEN) temp_strid = TextID_Copy(strid);
  else
  {
    wchar_t * buf = new wchar_t[len+1];
    TextID_GetWString(strid,buf,len+1);
    temp_strid = TextID_Create(buf,ENC_UCS2,len);
    delete buf;
  }
  
  width = RichTextLayout_GetTextWidth(temp_strid, pRichTextLayout, pFont);
  
  TextID_Destroy(temp_strid);

  if (pTextRenderingManager) pTextRenderingManager->Release();
  if (pTextRenderingFactory) pTextRenderingFactory->Release();
  if (pRichTextLayout) pRichTextLayout->Release();
  if (pTextObject) pTextObject->Release();

  return(width);
}
#endif

void GC_DrawIcon( int x, int y, IMAGEID imageID)
{
  GC* gc = get_DisplayGC();
  GC_PutChar( gc, x, y, 0, 0, imageID );
}
