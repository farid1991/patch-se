#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "Draw.h"
#include "main.h"

int GetTextIDWidth(int font, TEXTID text, int len)
{
#if defined(DB3200) || defined(DB3210)
  return dll_Disp_GetTextIDWidth(font, text, TextID_GetLength(len));
#else
  SetFont(font);
  return Disp_GetTextIDWidth(text, TextID_GetLength(len));
#endif
}

void DrawText(int font, TEXTID text, int align, int XPos, int YPos, int width, int text_color)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210)
    dll_DrawString(font, text, align, XPos, YPos, XPos + width, YPos + (font & 0xFF), text_color);
#else
    SetFont(font);
    int font_h = GetImageHeight(' ');
    DrawString(text, align, XPos, YPos, XPos + width, YPos + font_h, 0, 0, text_color, text_color);
#endif
  }
}

void DrawTextEx(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int text_color)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210)
    dll_DrawString(font, text, align, x1, y1, x2, y2, text_color);
#else
    SetFont(font);
    DrawString(text, align, x1, y1, x2, y2, 0x14, 0x5, text_color, text_color);
#endif
  }
}

void DrawTextOnRect(int font, TEXTID textid, int rect_x, int rect_y, int rect_w, int rect_h, int text_color, int bg_color)
{
  int x2_rect = rect_x + rect_w;
  int y2_rect = rect_y + rect_h;
  DrawRect(rect_x, rect_y, x2_rect, y2_rect, bg_color, bg_color);

  // Calculate the position for the text to be drawn inside the rectangle
  int text_y = rect_y + (rect_h >> 2); // Centered vertically
  DrawText(font, textid, AlignCenter, rect_x, text_y, rect_w, text_color);
}

void DrawImageEx(GC *gc, int x, int y, int w, int h, IMAGEID img)
{
  if (img != NOIMAGE)
#ifdef DB3150v1
    GC_PutChar(gc, x, y, w, h, img);
#else
    dll_GC_PutChar(gc, x, y, w, h, img);
#endif
}

void DrawImage(IMAGEID img, int x, int y)
{
  GC *gc = get_DisplayGC();
  DrawImageEx(gc, x, y, 0, 0, img);
}

void DrawProgressBar(int value, int max_value, RECT rect, int bg_color, int fill_color)
{
  Internal_Function *Data = Get_Internal_Function();

  int sliderWidth = rect.x2 - rect.x1;
  int nx2 = rect.x1 + ((value * sliderWidth) / max_value);

  // Draw the ProgressBar background
  DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, bg_color, bg_color);

  // Draw the filled part of ProgressBar
  DrawRect(rect.x1, rect.y1, nx2, rect.y2, fill_color, fill_color);

  // Calculate thumb position
  int thumbX = nx2 - Data->blob_w;
  int thumbY = rect.y1 + ((rect.y2 - rect.y1) >> 1) - Data->blob_h;

  // Draw the thumb icon
  DrawImage(Data->MusicPlayer[THUMB].ImageID, thumbX, thumbY);

  // Draw overlay icons based on orientation
  if (sliderWidth < 241)
    DrawImage(Data->MusicPlayer[PROGRESSBAR_OVERLAY].ImageID, rect.x1, rect.y1);
  else if (sliderWidth > 240)
    DrawImage(Data->MusicPlayer[PROGRESSBAR_OVERLAY_LANDSCAPE].ImageID, rect.x1, rect.y1);
}

void DrawSlider(int value,
                int max_value,
                int main_y1,
                int main_height,
                TEXTID slider_text,
                int text_size,
                int text_color,
                int bg_color,
                int slider_bcolor,
                int slider_fcolor,
                int thumb_color)
{
  // Define the slider rectangle
  int disp_width = Display_GetWidth(UIDisplay_Main);
  int slider_height = main_height >> 3;

  int slider_x1 = disp_width >> 5;
  int slider_x2 = disp_width - slider_x1;
  int slider_y1 = main_y1 + (main_height >> 1) + (main_height >> 2);
  int slider_y2 = slider_y1 + slider_height;

  // Calculate the x coordinate for drawing the slider thumb
  int sliderWidth = slider_x2 - slider_x1;
  int filled_x = slider_x1 + ((value * sliderWidth) / max_value);
  int thumbWidth = slider_height * 2;
  int thumbX = filled_x - (thumbWidth >> 1); // Center the thumb horizontally

  // Draw the main background rectangle as the background
  DrawRect(0, main_y1, disp_width, main_y1 + main_height, bg_color, bg_color);

  // Draw the slider track
  DrawRect(slider_x1, slider_y1, slider_x2, slider_y2, slider_bcolor, slider_bcolor);
  // Draw the slider fill
  DrawRect(slider_x1, slider_y1, filled_x, slider_y2, slider_fcolor, slider_fcolor);

  // Draw the slider thumb and its outline
  DrawRect(thumbX, slider_y1, thumbX + thumbWidth, slider_y2, thumb_color, thumb_color);
  DrawRect(thumbX - 1, slider_y1, thumbX, slider_y2, slider_bcolor, slider_bcolor);
  DrawRect(thumbX + thumbWidth, slider_y1, thumbX + thumbWidth + 1, slider_y2, slider_bcolor, slider_bcolor);

  // Draw the slider text
  int textY = main_y1 + (main_height >> 3);
  DrawText(text_size, slider_text, AlignLeft, slider_x1, textY, sliderWidth, text_color);
}
