#include "..\\include\Types.h"
#include "..\\include\Function.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"

// Text
void Get_IUITextFactory ( IUITextFactory** ppIUITextFactory )
{
  CoCreateInstance((UUID*)&CID_CUITextFactory, 
                   (UUID*)&IID_IUITextFactory, 
                   PPINTERFACE(ppIUITextFactory));
}

// SetFont ---------------------------------------------------------------------
int dll_SetFont(int FontSize, TUIEmphasisStyle FontStyle, IUIFont** ppFont)
{  
  IUIFontManager* pIUIFontManager = NULL;
  IUIFontFactory* pIUIFontFactory = NULL;
  TUIFontData pUIFontData;
  memset(&pUIFontData, NULL, sizeof(TUIFontData));
  
  CoCreateInstance((UUID*)&CID_CUIFontManager, 
                   (UUID*)&IID_IUIFontManager, 
                   PPINTERFACE(&pIUIFontManager));
  
  pIUIFontManager->GetFontFactory(&pIUIFontFactory);
  
  pIUIFontFactory->GetDefaultFontSettings(UIFontSizeLarge, &pUIFontData);
  pUIFontData.size = FontSize;
  pUIFontData.emphasis = FontStyle;
  
  pIUIFontFactory->CreateDefaultFont(&pUIFontData, ppFont);
  
  if (pIUIFontManager) pIUIFontManager->Release();
  if (pIUIFontFactory) pIUIFontFactory->Release();
  
  return FontSize;
}

int GetFontStyle(IUIFont* pFont)
{
  TUIFontStyle pStyle;
  if(pFont) pFont->GetStyle(&pStyle);
  
  return pStyle;
}

// DrawString ------------------------------------------------------------------

void Get_ITextRenderingManager( IUITextRenderingManager** ppIUITextRenderingManager )
{
  CoCreateInstance((UUID*)&CID_CTextRenderingManager, 
                   (UUID*)&IID_ITextRenderingManager, 
                   PPINTERFACE(ppIUITextRenderingManager));
}

void dll_DrawString(int FontSize, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int pen_color, bool IsUnderlined, int u_color)
{  
  TUIRectangle rect;
  int Width = x2 - x1;
  int Height = y2 - y1;
  
  IUITextRenderingManager* pIUITextRenderingManager = NULL;
  IUITextRenderingFactory* pIUITextRenderingFactory = NULL;
  IUIRichText* pIUIRichText = NULL;
  IUIRichTextLayout* pIUIRichTextLayout = NULL;
  IUIRichTextLayoutOptions * pIUIRichTextLayoutOptions = NULL;
  IRoot* pICanvas = NULL;
  
  int FontSize_wo_Style = (FontSize&0xFF);
  TUIEmphasisStyle FontStyle;
  int font_style = FontSize >> 8;
  switch(font_style)
  {
  case 1: FontStyle = UI_Emphasis_Bold; break;
  case 2: FontStyle = UI_Emphasis_Italic; break;
  case 3: FontStyle = UI_Emphasis_BoldItalic; break;
  default: FontStyle = UI_Emphasis_Normal; break;
  }
  
  IUIFont* pIUIFont = NULL;
  dll_SetFont(FontSize_wo_Style, FontStyle, &pIUIFont); 
  
  Get_ITextRenderingManager(&pIUITextRenderingManager);
  
  pIUITextRenderingManager->GetTextRenderingFactory(&pIUITextRenderingFactory);
  pIUITextRenderingFactory->CreateRichText(&pIUIRichText);
  pIUITextRenderingFactory->CreateRichTextLayoutOptions(&pIUIRichTextLayoutOptions);
  pIUITextRenderingFactory->CreateRichTextLayout(pIUIRichText,0,pIUIRichTextLayoutOptions,&pIUIRichTextLayout);
  
  IUIRichText_SetText(pIUIRichText, text_id);
  IUIRichText_SetFont(pIUIRichText, pIUIFont, START_INDEX, END_INDEX);
  
  pIUIRichText->SetTextColor(pen_color, START_INDEX, END_INDEX);
  pIUIRichText->SetAlignment(align, START_INDEX, END_INDEX);

  if(IsUnderlined)
  {
    pIUIRichText->SetUnderline(UILine_SingleSolid, START_INDEX, END_INDEX);
    pIUIRichText->SetUnderlineColor(u_color, START_INDEX, END_INDEX);
  }
  
  pIUIRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);
  
  pIUIRichTextLayout->Compose(Width);
  
  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = Width;
  rect.Size.Height = Height;
  
  DisplayGC_GetCanvas(get_DisplayGC(), &pICanvas);
  pIUIRichTextLayout->Display(pICanvas, x1, y1, &rect);
  
  if (pIUITextRenderingManager) pIUITextRenderingManager->Release();
  if (pIUITextRenderingFactory) pIUITextRenderingFactory->Release();
  if (pIUIRichTextLayout) pIUIRichTextLayout->Release();
  if (pIUIRichTextLayoutOptions) pIUIRichTextLayoutOptions->Release();
  if (pIUIRichText) pIUIRichText->Release();
  if (pICanvas) pICanvas->Release();
}

int dll_Disp_GetTextIDWidth( int FontSize, TEXTID textid, int len )
{  
  IUITextRenderingManager * pIUITextRenderingManager = NULL;
  IUITextRenderingFactory * pIUITextRenderingFactory = NULL;
  IUIRichTextLayout * pIUIRichTextLayout = NULL;
  IUIRichText * pIUIRichText = NULL;
  
  int width = NULL;
  TEXTID temp_strid=EMPTY_TEXTID;

  Get_ITextRenderingManager(&pIUITextRenderingManager);
  
  pIUITextRenderingManager->GetTextRenderingFactory(&pIUITextRenderingFactory);
  pIUITextRenderingFactory->CreateRichText(&pIUIRichText);
  pIUITextRenderingFactory->CreateRichTextLayout(pIUIRichText,0,0,&pIUIRichTextLayout);

  int FontSize_wo_Style = (FontSize&0xFF);
  TUIEmphasisStyle FontStyle;
  int font_style = FontSize >> 8;
  switch(font_style)
  {
  case 1: FontStyle = UI_Emphasis_Bold; break;
  case 2: FontStyle = UI_Emphasis_Italic; break;
  case 3: FontStyle = UI_Emphasis_BoldItalic; break;
  default: FontStyle = UI_Emphasis_Normal; break;
  }
  
  IUIFont* pIUIFont = NULL;
  dll_SetFont(FontSize_wo_Style, FontStyle, &pIUIFont); 
  
  if (len==TEXTID_ANY_LEN) temp_strid = TextID_Copy(textid);
  else
  {
    wchar_t *buf = (wchar_t*)malloc((sizeof(wchar_t)*len)+1);
    TextID_GetWString(textid,buf,len+1);
    temp_strid=TextID_Create(buf,ENC_UCS2,len);
    mfree(buf);
  }
  
  width = IUIRichTextLayout_GetTextWidth(temp_strid, pIUIRichTextLayout, pIUIFont);
  
  TextID_Destroy(temp_strid);

  if (pIUITextRenderingManager) pIUITextRenderingManager->Release();
  if (pIUITextRenderingFactory) pIUITextRenderingFactory->Release();
  if (pIUIRichTextLayout) pIUIRichTextLayout->Release();
  if (pIUIRichText) pIUIRichText->Release();

  return(width);
}

// GC_PutChar & GetImageWidthHeight --------------------------------------------
void Get_IUIImageManager( IUIImageManager** ppIUIImageManager )
{
  CoCreateInstance((UUID*)&CID_CUIImageManager, 
                   (UUID*)&IID_IUIImageManager, 
                   PPINTERFACE(ppIUIImageManager));
}

int dll_GetImageHeight( IMAGEID imageID )
{
  IUIImage* pUIImage = NULL;
  IUIImageManager* pIUIImageManager = NULL;
  TUnsigned width = NULL;
  TUnsigned height = NULL;
  
  Get_IUIImageManager(&pIUIImageManager);
  
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= OPA_OK)
  {
    pUIImage->GetDimensions(&width, 0, &height, 0);
  }
  if (pUIImage) pUIImage->Release();
  if (pIUIImageManager) pIUIImageManager->Release();
  
  return height;
}

int dll_GetImageWidth( IMAGEID imageID )
{
  IUIImage* pUIImage = NULL;
  IUIImageManager* pIUIImageManager = NULL;
  TUnsigned width = NULL;
  TUnsigned height = NULL;
  
  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromIcon(imageID, &pUIImage) >= OPA_OK)
  {
    pUIImage->GetDimensions(&width, 0, &height, 0);
  }
  if (pUIImage) pUIImage->Release();
  if (pIUIImageManager) pIUIImageManager->Release();

  return width;
}

void dll_GC_PutChar(GC* gc, int x, int y, int width, int height, IMAGEID imageID)
{  
  IUIImageManager* pIUIImageManager = NULL;
  IUIImage* pUIImage = NULL;
  IRoot* pICanvas = NULL;
  
  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  
  rect.Size.Width = width;
  rect.Size.Height = height;
  
  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(imageID, &pUIImage);
  
  DisplayGC_GetCanvas(gc, &pICanvas);
  pIUIImageManager->Draw(pUIImage, pICanvas, rect);
  
  if(pIUIImageManager) pIUIImageManager->Release();
  if(pUIImage) pUIImage->Release();
  if(pICanvas) pICanvas->Release();
}

// GraphicManager --------------------------------------------------------------
void Get_IUIGraphicManager( IUIGraphicManager** ppIUIGraphicManager )
{
  CoCreateInstance((UUID*)&CID_CUIGraphicManager, 
                   (UUID*)&IID_IUIGraphicManager, 
                   PPINTERFACE(ppIUIGraphicManager));
}

void Get_IUIGraphics( IUIGraphics** ppIUIGraphics )
{
  IUIGraphicManager * pIUIGraphicManager = NULL;
  Get_IUIGraphicManager(&pIUIGraphicManager);
  
  if(pIUIGraphicManager) 
  {
    pIUIGraphicManager->CreateGraphics(ppIUIGraphics);
    pIUIGraphicManager->Release();
  }
}

TColour dll_GetForegroundColor(UIThemeColor_t ThemeColor)
{
  IUIGraphics* pIUIGraphics = NULL;
  Get_IUIGraphics(&pIUIGraphics);
  
  TColour pColor = clEmpty;
  pIUIGraphics->GetForegroundColor(ThemeColor,&pColor);
  
  if(pIUIGraphics) pIUIGraphics->Release();

  return pColor;
}

TColour dll_GetBackgroundColor(UIThemeColor_t ThemeColor)
{
  IUIGraphics* pIUIGraphics = NULL;
  Get_IUIGraphics(&pIUIGraphics);
  
  TColour pColor = NULL;
  pIUIGraphics->GetBackgroundColor(ThemeColor,&pColor);
  
  if(pIUIGraphics) pIUIGraphics->Release();
  
  return pColor;
}

int dll_GetStringWidth( int font_size, wchar_t* pString )
{
  IUIFont* pIUIFont = NULL;
  dll_SetFont(font_size, UI_Emphasis_Normal, &pIUIFont);
  
  FUint16 pStrWidth = 0;
  TUnsigned strLen = wstrlen(pString);
  
  IUIGraphics* pIUIGraphics = NULL;
  Get_IUIGraphics(&pIUIGraphics);
  
  if(!pIUIGraphics) return pStrWidth;
  
  pIUIGraphics->GetStringWidth(pIUIFont,
                               pString,
                               strLen,
                               &pStrWidth );
  
  if(pIUIGraphics) pIUIGraphics->Release();
  
  return pStrWidth;
}

void dll_GetBackgroundImageSize(UIBackgroundManagerImage_t image, TUnsigned* pWidth, TUnsigned* pHeight)
{
  IUIGraphics* pIUIGraphics = NULL;
  Get_IUIGraphics(&pIUIGraphics);
  
  if(pIUIGraphics) 
  {
    pIUIGraphics->GetBackgroundImageSize(image, &*pWidth, &*pHeight);
    pIUIGraphics->Release();
  }
}

void dll_DrawWString(int FontSize, wchar_t* pString, int alignment, int XPos, int YPos, int Width, unsigned int Color)
{
  IUIGraphics* pIUIGraphics = NULL;
  Get_IUIGraphics(&pIUIGraphics);
  
  if(pIUIGraphics)
  {
    GC* GraphicCanvas = get_DisplayGC();
    IRoot* pICanvas = NULL;
    DisplayGC_GetCanvas(GraphicCanvas, &pICanvas);
    
    int FontSize_wo_Style = (FontSize&0xFF);
    TUIEmphasisStyle FontStyle;
    int font_style = FontSize >> 8;
    switch(font_style)
    {
    case 1: FontStyle = UI_Emphasis_Bold; break;
    case 2: FontStyle = UI_Emphasis_Italic; break;
    case 3: FontStyle = UI_Emphasis_BoldItalic; break;
    default: FontStyle = UI_Emphasis_Normal; break;
    }
    
    IUIFont* pIUIFont = NULL;
    dll_SetFont(FontSize_wo_Style, FontStyle, &pIUIFont); 
    
    pIUIGraphics->DrawString(pICanvas, 
                             pIUIFont,
                             Color,
                             pString,
                             wstrlen(pString),
                             alignment,
                             XPos,
                             YPos,
                             Width,
                             FontSize_wo_Style );
    pIUIGraphics->Release();
    
    if(pIUIFont) pIUIFont->Release();
    if(pICanvas) pICanvas->Release();
  }
  
}

void dll_DrawIUIText(int FontSize, wchar_t* pString, int alignment, int XPos, int YPos, int Width, int Height, unsigned int Color)
{
  IUIText *pIUIText = NULL;
  IUIGraphics* pIUIGraphics = NULL;
  IUITextFactory *pIUITextFactory = NULL;
  IRoot* pICanvas = NULL;
  IUIFont* pIUIFont = NULL;
  
  GC* GraphicCanvas = get_DisplayGC();
  
  Get_IUITextFactory(&pIUITextFactory);

  DisplayGC_GetCanvas(GraphicCanvas, &pICanvas);
    
  if(pIUITextFactory)
  {
    debug_printf("\n\n pIUITextFactory \n\n");
    
    pIUITextFactory->CreateFromRaw(pString, wstrlen(pString), &pIUIText);
    
    if(pIUIText)
    {
      debug_printf("\n\n pIUIText \n\n");
      
      int FontSize_wo_Style = (FontSize&0xFF);
      TUIEmphasisStyle FontStyle;
      int font_style = FontSize >> 8;
      switch(font_style)
      {
      case 1: FontStyle = UI_Emphasis_Bold; break;
      case 2: FontStyle = UI_Emphasis_Italic; break;
      case 3: FontStyle = UI_Emphasis_BoldItalic; break;
      default: FontStyle = UI_Emphasis_Normal; break;
      }
      
      dll_SetFont(FontSize_wo_Style, FontStyle, &pIUIFont); 
  
      Get_IUIGraphics(&pIUIGraphics);
      if(pIUIGraphics)
      {
        debug_printf("\n\n pIUIGraphics \n\n");
        
        pIUIGraphics->DrawIUIText(pICanvas,
                                  pIUIFont, 
                                  Color, 
                                  pIUIText, 
                                  alignment, 
                                  XPos, 
                                  YPos, 
                                  Width, 
                                  Height );  
      }
    }
  }
  
  if(pIUIGraphics) pIUIGraphics->Release();
  if(pIUIText) pIUIText->Release();
  if(pIUITextFactory) pIUITextFactory->Release();
  if(pICanvas) pICanvas->Release();
}

// Clipboard  ------------------------------------------------------------------

void Get_IUIStatusrow( IUIStatusrow** ppIUIStatusrow )
{
  CoCreateInstance((UUID*)&CID_CUIStatusrow, 
                   (UUID*)&IID_IUIStatusrow, 
                   PPINTERFACE(ppIUIStatusrow));
}

void dll_SetTrayIcon( wchar_t icon, bool show )
{
  IUIStatusrow * pIUIStatusrow = NULL;
  Get_IUIStatusrow(&pIUIStatusrow);
  
  if(pIUIStatusrow) 
  {
    pIUIStatusrow->ShowTrayIcon(icon,show);
    pIUIStatusrow->Release();
  }
}

void dll_BlinkTrayIcon( IMAGEID icon, char BlinkMode )
{
  IUIStatusrow * pIUIStatusrow = NULL;
  Get_IUIStatusrow(&pIUIStatusrow);
  
  if(pIUIStatusrow)
  {
    pIUIStatusrow->BlinkTrayIcon(icon,BlinkMode);
    pIUIStatusrow->Release();  
  }
}

void dll_ShowTrayClock( int display, bool show )
{
  IUIStatusrow * pIUIStatusrow = NULL;
  Get_IUIStatusrow(&pIUIStatusrow);

  if(pIUIStatusrow) 
  {
    pIUIStatusrow->ShowTrayClock(display,show);
    pIUIStatusrow->Release();  
  }
}


// Clipboard  ------------------------------------------------------------------

void Get_IUIClipboard ( IUIClipboard ** ppIUIClipboard )
{
  IShell *pIShell = NULL;
  OSE_GetShell(PPINTERFACE(&pIShell));
  
  IUIClipboardManager *pIUIClipboardManager = NULL;
  pIShell->CreateInstance((UUID*)&CID_CUIClipboardManager, 
                          (UUID*)&IID_IUIClipboardManager, 
                          PPINTERFACE(&pIUIClipboardManager));
 
  if(pIUIClipboardManager)
  {
    pIUIClipboardManager->GetIUIClipboard(ppIUIClipboard);
    pIUIClipboardManager->Release();
  }
  if(pIShell) pIShell->Release();
}


bool Clipboard_ExistsText(void)
{
  bool result = true;
  IUIClipboard *pIUIClipboard = NULL;
  Get_IUIClipboard(&pIUIClipboard);
  
  if(pIUIClipboard)
  {
    result = pIUIClipboard->isEmpty();
    pIUIClipboard->Release();
  }
  return(!result);
}

void Clipboard_SetText(wchar_t *pText, int Lenght)
{
  IUITextFactory *pIUITextFactory = NULL;
  Get_IUITextFactory(&pIUITextFactory);
    
  if(pIUITextFactory)
  {
    IUIText *pIUIText = NULL;
    pIUITextFactory->CreateFromRaw(pText, Lenght, &pIUIText);
    
    if(pIUIText)
    {
      IUIClipboard *pIUIClipboard = NULL;
      Get_IUIClipboard ( &pIUIClipboard );
      if(pIUIClipboard)
      {
        pIUIClipboard->SetText(pIUIText);
        pIUIClipboard->Release();
        return;
      }
      pIUIText->Release();
    }
    pIUITextFactory->Release();
  }
}

wchar_t *Clipboard_GetText( void )
{
  wchar_t *ret_ws = NULL;
  IUIText *pIUIText = NULL;
  IUIClipboard *pIUIClipboard = NULL;

  Get_IUIClipboard(&pIUIClipboard);
  
  if(!pIUIClipboard) return(ret_ws);
  
  pIUIClipboard->GetText(&pIUIText);
  pIUIClipboard->Release();

  if(pIUIText)
  {
    int len = 0;
    if(pIUIText->GetLenght(&len) >= 0)
    {
      int new_len = 0;
      ret_ws = (wchar_t*)malloc((sizeof(wchar_t)*len)+1);
      pIUIText->GetText(ret_ws, len+1, &new_len);
      if(!new_len)
      {
        mfree(ret_ws);
        ret_ws = NULL;
      }
      pIUIText->Release();
    }
  }
  return(ret_ws);
}

void Clipboard_Clear(void)
{
  IUIClipboard *pIUIClipboard = NULL;
  Get_IUIClipboard(&pIUIClipboard);
  
  if(pIUIClipboard)
  {
    pIUIClipboard->Clear();
    pIUIClipboard->Release();
  }
}
#endif

#ifdef USESIGNAL
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
  static const SIGSELECT sg[] = {1, GetSignalQuality_Receive_SignalID};
  char res = 0;
  PROCESS pid;
  
  hunt("LNH_ACC_SIDE/SL_Process",0,&pid,0);
  union SIGNAL * mem = alloc(8,GetSignalQuality_Send_SignalID);
  mem->hsig.null = 0;
  send(&mem,pid);
  union SIGNAL * rec_buf = receive(sg);
  if (rec_buf->signo==GetSignalQuality_Receive_SignalID)
  {
    rssi[0] = rec_buf->hsig.rssi;
    ber[0] = rec_buf->hsig.ber;
    res = rec_buf->hsig.unk_er;
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

void dll_GUIObject_SetBackgroundImage( GUI* gui, IMAGEID imageID )
{
  DispObject_SetBackgroundImage( GUIObject_GetDispObject(gui), imageID );
}

void dll_GUIObject_SetTitleTextColor( GUI* gui, int color )
{
  DispObject_SetTitleTextColor( GUIObject_GetDispObject(gui), color );
}
#endif

void GUIObject_SetAnimation(GUI* gui, int anim)
{
  DispObject_SetAnimation( GUIObject_GetDispObject(gui), anim );
}

#ifdef DB2010
int dll_Browser_OpenURI( BOOK* book, char* URI, int mode )
{
  int one = 1;
  return REQUEST_WAP_URL_LOAD(&one, 0, 6, URI);
}
#endif
