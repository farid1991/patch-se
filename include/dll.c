#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)

// SetFont ----------------------------------------------------
int dll_SetFont(int font_size, IFont** ppFont)
{
  UUID IID_IUIFontManager = {0x95,0xD0,0x5F,0xCA,0x0F,0x30,0x4F,0x92,0x94,0x3B,0x13,0x89,0x21,0x2F,0x09,0xD7};
  UUID CID_CUIFontManager = {0x82,0xAC,0x97,0x9B,0x58,0x44,0x41,0x39,0xA0,0xD3,0xE6,0xCF,0x72,0xB5,0x80,0x69};
  
  IFontManager* pFontManager = NULL;
  IFontFactory* pFontFactory = NULL;
  TUIFontData pFontData;
  memset(&pFontData, NULL, sizeof(TUIFontData));
  
  CoCreateInstance(&CID_CUIFontManager, &IID_IUIFontManager, PPINTERFACE(&pFontManager));
  pFontManager->GetFontFactory(&pFontFactory);
  
  int font_size_without_style = font_size&0xFF;
  
  pFontFactory->GetDefaultFontSettings(UIFontSizeLarge, &pFontData);
  pFontData.size = (float) font_size_without_style;
  pFontData.TUIEmphasisStyle = font_size>>8;
  pFontFactory->CreateDefaultFont(&pFontData, ppFont);
  
  if (pFontManager) pFontManager->Release();
  if (pFontFactory) pFontFactory->Release();
  
  return 1;
}

// DrawString ----------------------------------------------------
void dll_DrawString(TEXTID text, int font, int align, int x1, int y1, int x2, int y2, int pen_color)
{
  UUID IID_ITextRenderingManager={0xCE,0x91,0x7B,0x62,0xE3,0x3A,0x4D,0xC7,0x85,0x24,0x79,0x1E,0x6F,0x01,0x03,0x09};
  UUID CID_CTextRenderingManager={0xCF,0xDC,0xCD,0x9D,0xAE,0x6D,0x40,0xAE,0xB3,0x97,0x38,0xB0,0x5D,0x2D,0x35,0x9D};
  
  TUIRectangle rect;
  int lineWidth = x2 - x1;
  
  ITextRenderingManager* pTextRenderingManager = NULL;
  ITextRenderingFactory* pTextRenderingFactory = NULL;
  IRichText* pTextObject = NULL;
  IRichTextLayout* pRichTextLayout = NULL;
  IUIRichTextLayoutOptions * pIUIRichTextLayoutOptions = NULL;
  IUnknown* pGC = NULL;
  
  //if(!pFont) dll_SetFont(20, &pFont);
  IFont* pFont = NULL;
  dll_SetFont(font, &pFont);
  
  CoCreateInstance(&CID_CTextRenderingManager, &IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pTextObject);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pIUIRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pTextObject,0,pIUIRichTextLayoutOptions,&pRichTextLayout);
  
  TextObject_SetText(pTextObject, text);
  TextObject_SetFont(pTextObject, pFont, START_INDEX, END_INDEX);
  pTextObject->SetTextColor(pen_color, START_INDEX, END_INDEX);
  
  pTextObject->SetAlignment(align, START_INDEX, END_INDEX);
  
  pIUIRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);
  
  pRichTextLayout->Compose(lineWidth);
  
  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = x2 - x1;
  rect.Size.Height = y2 - y1;
  
  DisplayGC_AddRef(get_DisplayGC(), &pGC);
  pRichTextLayout->Display(pGC, x1, y1, &rect);
  
  if (pTextRenderingManager) pTextRenderingManager->Release();
  if (pTextRenderingFactory) pTextRenderingFactory->Release();
  if (pRichTextLayout) pRichTextLayout->Release();
  if (pIUIRichTextLayoutOptions) pIUIRichTextLayoutOptions->Release();
  if (pTextObject) pTextObject->Release();
  if (pGC) pGC->Release();
}

// GC_PutChar & GetImageWidthHeight --------------------------------------------
void Get_IUIImageManager(IUIImageManager** ppIUIImageManager)
{
  UUID IID_IUIImageManager={0x63,0xEF,0xA5,0x31,0xFF,0xD1,0x4E,0x25,0xA6,0x24,0x60,0x0A,0x96,0x81,0x3F,0xC5};
  UUID CID_CUIImageManager={0x86,0x2D,0xF9,0x95,0x1C,0x3B,0x4B,0x24,0xB7,0x4D,0x8F,0x98,0x70,0x1E,0x5D,0x14};
  CoCreateInstance(&CID_CUIImageManager, &IID_IUIImageManager, PPINTERFACE(ppIUIImageManager));
}

int dll_GetImageHeight(IMAGEID imageID)
{
  IUIImage* pUIImage = NULL;
  IUIImageManager* pIUIImageManager = NULL;
  long image_width = NULL;
  long image_height = NULL;
  
  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);
  
  if (pIUIImageManager) pIUIImageManager->Release();
  if (pUIImage) pUIImage->Release();
  
  return image_height;
}

int dll_GetImageWidth(IMAGEID imageID)
{
  IUIImage* pUIImage = NULL;
  IUIImageManager* pIUIImageManager = NULL;
  long image_width = NULL;
  long image_height = NULL;
  
  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);
  
  if (pIUIImageManager) pIUIImageManager->Release();
  if (pUIImage) pUIImage->Release();
  
  return image_width;
}

void dll_GC_PutChar(GC* gc, int x, int y, int width, int height, IMAGEID imageID)
{  
  IUIImageManager* pIUIImageManager = NULL;
  IUIImage* pUIImage = NULL;
  IUnknown* pGC = NULL;
  
  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  
  rect.Size.Width = width;
  rect.Size.Height = height;
  
  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(imageID, &pUIImage);
  
  DisplayGC_AddRef(gc, &pGC);
  
  pIUIImageManager->Draw(pUIImage, pGC, rect);
  
  if (pIUIImageManager) pIUIImageManager->Release();
  if (pUIImage) pUIImage->Release();
  if (pGC) pGC->Release();
}

wchar_t* Get_CoverType(int cover_type)
{
  if (cover_type<=3)
  {
    switch(cover_type)
    {
      case 0: return L"jpg";
      case 1: return L"gif";
      case 2: return L"png";
      case 3: return L"bmp";
    }
    return NULL;
  }
  return NULL;
}

IMAGEID dll_MetaData_GetCover( wchar_t* fullpath )
{
  UUID IID_IMetaData={0xB1,0xEB,0x4F,0x97,0xB0,0xDD,0x42,0x09,0xB6,0x96,0xCE,0x11,0x2D,0x5E,0xD8,0xE8};
  UUID CID_CMetaData={0x0B,0xCD,0x95,0x0F,0x9F,0xB6,0x4E,0x7A,0xA7,0xCD,0xCA,0x1D,0x87,0xBA,0x9A,0x27};
  
  int CoverSize;
  int CoverOffset;
  char pImageType;
  
  int size = (wstrlen(fullpath)+1) * sizeof(wchar_t);
  wchar_t *CoverPath = (wchar_t*)malloc(size);
  memset(CoverPath, NULL, size);
  
  wstrcpy(CoverPath, fullpath);
  
  METADATA_DESC * MetaData_Desc = (METADATA_DESC*)malloc(sizeof(METADATA_DESC));
  MetaData_Desc->pMetaData = NULL;
  CoCreateInstance(&CID_CMetaData, &IID_IMetaData, PPINTERFACE(&MetaData_Desc->pMetaData));
  wchar_t * CoverName = wstrrchr(CoverPath, '/');
  *CoverName = 0;
  MetaData_Desc->pMetaData->SetFile(CoverPath,CoverName+1);
  COVER_INFO_DESC cover_info;
  if (((METADATA_DESC*)MetaData_Desc)->pMetaData->GetCoverInfo(&cover_info) < 0) 
    return NOIMAGE;
  
  pImageType = cover_info.cover_type;
  CoverSize = cover_info.size;
  CoverOffset = cover_info.cover_offset;
  
  if (((METADATA_DESC*)MetaData_Desc)->pMetaData) 
  {
    ((METADATA_DESC*)MetaData_Desc)->pMetaData->Release();
    mfree(MetaData_Desc);
  }
  
  int file;
  IMAGEID ImageID;
  if ((file = w_fopen(fullpath, WA_Read, 0x1FF, 0)))
  {
    if (w_lseek(file,CoverOffset,WSEEK_SET))
    {
      char* CoverBuff = (char*) malloc(CoverSize+1);
      memset(CoverBuff,0,CoverSize+1);
      w_fread(file,CoverBuff,CoverSize);
      ImageID_GetIndirect(CoverBuff,CoverSize,0,Get_CoverType(pImageType),&ImageID);
    }
    w_fclose(file);
  }
  mfree(CoverPath);
  
  return ImageID;
}
#endif

#ifdef USE_GETSIGNAL
struct GET_SIGNAL_QUALITY_SIGNAL
{
  SIGSELECT signo;
  int null;
  char unk_er;
  char rssi;
  char ber;
  char error_cause;
};

union SIGNAL
{
  SIGSELECT signo;
  struct GET_SIGNAL_QUALITY_SIGNAL hsig;
};

int dll_GetSignalQuality( char * rssi, char * ber )
{
  static const SIGSELECT sg[]={1,GetSignalQuality_Receive_SignalID};
  char res = 0;
  PROCESS pid;
  
  hunt("LNH_ACC_SIDE/SL_Process",0,&pid,0);
  union SIGNAL * mem = alloc(8,GetSignalQuality_Send_SignalID);
  mem->hsig.null = 0;
  send(&mem,pid);
  union SIGNAL * rec_buf = receive(sg);
  if (rec_buf->signo==GetSignalQuality_Receive_SignalID)
  {
    rssi[0]=rec_buf->hsig.rssi;
    ber[0]=rec_buf->hsig.ber;
    res=rec_buf->hsig.unk_er;
  }
  free_buf(&rec_buf);
  return(res);
}
#endif

#ifdef A2
void dll_GUIObject_SetCursorImage( GUI* gui, IMAGEID imageID )
{
  DispObject_SetCursorImage( GUIObject_GetDispObject(gui), imageID );
}
#endif

#ifdef A2
void dll_GUIObject_SetBackgroundImage( GUI* gui, IMAGEID imageID )
{
  DispObject_SetBackgroundImage( GUIObject_GetDispObject(gui), imageID );
}
#endif

#ifdef A2
void dll_GUIObject_SetTitleTextColor( GUI* gui, int color )
{
  DispObject_SetTitleTextColor( GUIObject_GetDispObject(gui), color );
}
#endif
