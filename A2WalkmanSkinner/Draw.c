#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"

#include "dll.h"

#include "Draw.h"
#include "main.h"

void Draw_String(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int TextColor)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(font, text, align, x1, y1, x2, y2, TextColor);
#else
    SetFont(font);
    DrawString(text, align, x1, y1, x2, y2, 0x14, 0x5, TextColor, TextColor);
#endif
  }
}

void DrawString_Params(int font, TEXTID text, int align, int XPos, int YPos, int width, int TextColor)
{
  Draw_String(font, text, align, XPos, YPos, XPos + width, YPos + font_h(font), TextColor);
}

void DrawRectangle(int x, int y, int w, int h, int border_color, int fill_color)
{
  DrawRect(x, y, x + w, y + h, border_color, fill_color);
}

void DrawString_onRect(int font, TEXTID textid, int text_color, int rect_x, int rect_y, int rect_w, int rect_h, int fill_color)
{
  DrawRectangle(rect_x, rect_y, rect_w, rect_h, clEmpty, fill_color);

  DrawString_Params(font,
                    textid,
                    AlignCenter,
                    rect_x,
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
                    rect_y + division((rect_h - font_h(font)), 2),
#else
                    rect_y + division((rect_h - font), 2),
#endif
                    rect_w,
                    text_color);
}

void DrawImage(GC *gc, int x, int y, int w, int h, IMAGEID img)
{
  if (img != NOIMAGE)
#ifdef DB3150v1
    GC_PutChar(gc, x, y, w, h, img);
#else
    dll_GC_PutChar(gc, x, y, w, h, img);
#endif
}

void DrawIcon(IMAGEID img, int x, int y)
{
#ifdef DB3150v1
  if (img != NOIMAGE)
    GC_DrawImage(x, y, img);
#else
  DrawImage(get_DisplayGC(), x, y, 0, 0, img);
#endif
}

void DrawSlider(int value, int max_value, RECT rect, int Color_ProgressBarOutline, int Color_ProgressBar, IMAGEID thumb)
{
  int width = rect.x2 - rect.x1;
  int nx2 = rect.x1 + ((value * width) / max_value);

  DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Color_ProgressBarOutline, Color_ProgressBarOutline);
  DrawRect(rect.x1, rect.y1, nx2, rect.y2, Color_ProgressBar, Color_ProgressBar);

  if (thumb && thumb != NOIMAGE)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    int thumb_w = division(dll_GetImageWidth(thumb), 2);
    int thumb_h = division(dll_GetImageHeight(thumb), 2);
#else
    int thumb_w = division(GetImageWidth(thumb), 2);
    int thumb_h = division(GetImageHeight(thumb), 2);
#endif

    int thumb_x = nx2 - thumb_w;
    int thumb_y = (rect.y1 - thumb_h) + division((rect.y2 - rect.y1), 2);

    DrawIcon(thumb, thumb_x, thumb_y);
  }
}

void DrawProgressBar(Internal_Function *Data, int value, int max_value, RECT rect, int Bcolor, int Ecolor)
{
  int wid = rect.x2 - rect.x1;
  int nx2 = rect.x1 + ((value * wid) / max_value);

  DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor);
  DrawRect(rect.x1, rect.y1, nx2, rect.y2, Ecolor, Ecolor);

  int blob_x = nx2 - (Data->blob_w);
  int blob_y = (rect.y1 - Data->blob_h) + division((rect.y2 - rect.y1), 2);

  DrawIcon(Data->MusicPlayer[THUMB].ImageID, blob_x, blob_y);

  if (wid < 241)
    DrawIcon(Data->MusicPlayer[PROGRESSBAR_OVERLAY].ImageID, rect.x1, rect.y1);
  if (wid > 240)
    DrawIcon(Data->MusicPlayer[PROGRESSBAR_OVERLAY_LANDSCAPE].ImageID, rect.x1, rect.y1);
}

void Draw_SliderItem(int value, int max_value, int y_pos, int height, TEXTID textid, unsigned int text_color, unsigned int cursor_color, unsigned int outline_color, unsigned int slider_color)
{
  DrawRectangle(0, y_pos, 240, height, clEmpty, cursor_color); // selected

  int str_pos = y_pos + 3;

  DrawString_Params(FONT_E_16R,
                    textid,
                    AlignLeft,
                    bar_x,
                    str_pos(y_pos),
                    end_bar,
                    text_color);
  RECT rect;
  rect.x1 = bar_x;
  rect.x2 = end_bar;
  rect.y1 = str_pos + font_h(FONT_E_16R) + bar_y;
  rect.y2 = str_pos + font_h(FONT_E_16R) + bar_y + bar_height;
  DrawSlider(value, max_value, rect, outline_color, slider_color, PB_REC_ICN);
}
