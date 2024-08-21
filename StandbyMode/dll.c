#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
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
void Get_TextRenderingManager(ITextRenderingManager **ppTextRenderingManager)
{
  CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(ppTextRenderingManager));
}

void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int pen_color, bool underline, int u_color)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IUIRichTextLayoutOptions *pRichTextLayoutOptions = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pRichText = NULL;
  IUnknown *pCanvas = NULL;
  IFont *pFont = NULL;

  Get_TextRenderingManager(&pTextRenderingManager);
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pRichText);
  pTextRenderingFactory->CreateRichTextLayoutOptions(&pRichTextLayoutOptions);
  pTextRenderingFactory->CreateRichTextLayout(pRichText, NULL, pRichTextLayoutOptions, &pRichTextLayout);

  dll_SetFont(font, &pFont);

  TextObject_SetText(pRichText, text_id);
  TextObject_SetFont(pRichText, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichText->SetTextColor(pen_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichText->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichText->SetUnderline((TUILineStyle)underline, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
  pRichText->SetUnderlineColor(u_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

  pRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);

  DisplayGC_AddRef(get_DisplayGC(), &pCanvas);

  TUIRectangle rect;
  rect.Point.X = x1;
  rect.Point.Y = y1;
  rect.Size.Width = x2 - x1;
  rect.Size.Height = y2 - y1;
  pRichTextLayout->Compose(rect.Size.Width);
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

int dll_Disp_GetTextIDWidth(int font, TEXTID strid, int len)
{
  ITextRenderingManager *pTextRenderingManager = NULL;
  ITextRenderingFactory *pTextRenderingFactory = NULL;
  IRichTextLayout *pRichTextLayout = NULL;
  IRichText *pRichText = NULL;
  IFont *pFont = NULL;

  Get_TextRenderingManager(&pTextRenderingManager);
  pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
  pTextRenderingFactory->CreateRichText(&pRichText);
  pTextRenderingFactory->CreateRichTextLayout(pRichText, NULL, NULL, &pRichTextLayout);

  dll_SetFont(font, &pFont);

  TEXTID temp_strid = EMPTY_TEXTID;
  if (len == TEXTID_ANY_LEN)
  {
    temp_strid = TextID_Copy(strid);
  }
  else
  {
    wchar_t *buf = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
    TextID_GetWString(strid, buf, len + 1);
    temp_strid = TextID_Create(buf, ENC_UCS2, len);
    mfree(buf);
  }

  int text_width = RichTextLayout_GetTextWidth(temp_strid, pRichTextLayout, pFont);
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

  return (text_width);
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

  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(image_id, &pUIImage);

  DisplayGC_AddRef(gc, &pCanvas);
  TUIRectangle rect;
  rect.Point.X = x;
  rect.Point.Y = y;
  rect.Size.Width = width;
  rect.Size.Height = height;
  pIUIImageManager->Draw(pUIImage, pCanvas, rect);

  if (pCanvas)
    pCanvas->Release();
  if (pUIImage)
    pUIImage->Release();
  if (pIUIImageManager)
    pIUIImageManager->Release();
}

// GetImageWidthHeight ----------------------------------------------------
int dll_GetImageWidth(IMAGEID image_id)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(image_id, &pUIImage);
  int image_width;
  int image_height;
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
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  pIUIImageManager->CreateFromIcon(image_id, &pUIImage);
  int image_width;
  int image_height;
  if (pIUIImageManager->CreateFromIcon(image_id, &pUIImage) >= 0)
    pUIImage->GetDimensions(&image_width, 0, &image_height, 0);

  if (pUIImage)
    pUIImage->Release();
  if (pIUIImageManager)
    pIUIImageManager->Release();

  return image_height;
}

void DrawImageFromPath(wchar_t *fname, int x, int y)
{
  IUIImageManager *pIUIImageManager = NULL;
  IUIImage *pUIImage = NULL;
  IUnknown *pCanvas = NULL;

  Get_IUIImageManager(&pIUIImageManager);
  if (pIUIImageManager->CreateFromPath(L"/usb/other/ZBin/Config/Widget/Music", fname, "image/png", 9, &pUIImage) >= 0)
  {
    DisplayGC_AddRef(get_DisplayGC(), &pCanvas);
    TUIRectangle rect;
    rect.Point.X = x;
    rect.Point.Y = y;
    rect.Size.Width = 0;
    rect.Size.Height = 0;
    pIUIImageManager->Draw(pUIImage, pCanvas, rect);
  }

  if (pCanvas)
    pCanvas->Release();
  if (pUIImage)
    pUIImage->Release();
  if (pIUIImageManager)
    pIUIImageManager->Release();
}
#endif

#ifdef A2
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

int dll_GetSignalQuality(char *rssi, char *ber)
{
  static const SIGSELECT sg[] = {1, GetSignalQuality_Receive_SignalID};
  char res = 0;
  PROCESS pid;

  hunt("LNH_ACC_SIDE/SL_Process", 0, &pid, 0);
  union SIGNAL *mem = alloc(8, GetSignalQuality_Send_SignalID);
  mem->hsig.null = 0;
  send(&mem, pid);
  union SIGNAL *rec_buf = receive(sg);
  if (rec_buf->signo == GetSignalQuality_Receive_SignalID)
  {
    rssi[0] = rec_buf->hsig.rssi;
    ber[0] = rec_buf->hsig.ber;
    res = rec_buf->hsig.unk_er;
  }
  free_buf(&rec_buf);
  return res;
}
#endif

void Get_IClock(IClock **ppIClock)
{
  IClockManager *pIClockManager = NULL;
  CoCreateInstance(CID_CClockManager, IID_IClockManager, PPINTERFACE(&pIClockManager));
  pIClockManager->CreateClock(ppIClock);

  if (pIClockManager)
    pIClockManager->Release();
}

void Get_IAlarm(IAlarmItem **ppIAlarmItem, IAlarmRecurrent **ppIAlarmRecurrent)
{
  IAlarmManager *pIAlarmManager = NULL;
  CoCreateInstance(CID_CAlarmManager, IID_IAlarmManager, PPINTERFACE(&pIAlarmManager));
  pIAlarmManager->CreateAlarmItem(ppIAlarmItem);
  pIAlarmManager->CreateAlarmRecurrent(ppIAlarmRecurrent);

  if (pIAlarmManager)
    pIAlarmManager->Release();
}
