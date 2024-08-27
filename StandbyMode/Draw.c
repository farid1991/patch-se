#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"

#include "dll.h"
#include "draw.h"
#include "main.h"

void DrawIconsArray(GC* gc, int align, int x, int y, IMAGEID *icons, int len, int width)
{
  if (align == AlignLeft)
  {
    int new_x = x;
    for (int i = 0; i < len; i++)
    {
      DrawIcon(gc, new_x, y, icons[i], 0);
      new_x = new_x + width;
    }
  }
  else if (align == AlignRight)
  {
    int new_x = x - width;
    for (int i = len - 1; i >= 0; i--)
    {
      DrawIcon(gc, new_x, y, icons[i], 0);
      new_x = new_x - width;
    }
  }
  else
  {
    int full_width = len * width;
    int new_x = x + ((240 - x - full_width) >> 1);
    for (int i = 0; i < len; i++)
    {
      DrawIcon(gc, new_x, y, icons[i], 0);
      new_x = new_x + width;
    }
  }
}

void draw_string_with_params(int font, TEXTID text, int align, int XPos, int YPos, int MaxXPos, int MaxYPos, int t_color, int h_color, int highlight, bool underline, int u_color)
{
  if (text == EMPTY_TEXTID)
    return;

  switch (highlight)
  {
  case HighlightOff:
    dll_DrawString(font, text, align, XPos, YPos, MaxXPos, MaxYPos, t_color, underline, u_color);
    break;
  case HighlightFullV1:
    dll_DrawString(font, text, align, XPos - 1, YPos - 1, MaxXPos - 1, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos - 1, YPos + 1, MaxXPos - 1, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos + 1, YPos - 1, MaxXPos + 1, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos + 1, YPos + 1, MaxXPos + 1, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos, YPos, MaxXPos, MaxYPos, t_color, underline, u_color);
    break;
  case HighlightFullV2:
    dll_DrawString(font, text, align, XPos + 1, YPos, MaxXPos, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos, YPos + 1, MaxXPos, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos - 1, YPos, MaxXPos, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos, YPos - 1, MaxXPos, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos, YPos, MaxXPos, MaxYPos, t_color, underline, u_color);
    break;
  case HighlightShadow:
    dll_DrawString(font, text, align, XPos + 1, YPos + 1, MaxXPos, MaxYPos, h_color, underline, u_color);
    dll_DrawString(font, text, align, XPos, YPos, MaxXPos, MaxYPos, t_color, underline, u_color);
    break;
  }
}

void draw_string_no_style(int font, TEXTID text, int align, int XPos, int YPos, int Width, int t_color)
{
  if (text == EMPTY_TEXTID)
    return;

  dll_DrawString(font, text, align, XPos, YPos, XPos + Width, YPos + font_get_height(font), t_color, UILine_None, clEmpty);
}

void DrawItem(TEXT_ITEM_DATA *item, TEXTID text_id, int height_start)
{
  int disp_width = Display_GetWidth(UIDisplay_Main);
  int disp_height = Display_GetHeight(UIDisplay_Main);

  if ((*item).align == AlignRight)
  {
    draw_string_with_params((*item).font_size,
                            text_id,
                            (*item).align,
                            0, ((*item).YPos) - height_start,
                            (*item).XPos, disp_height,
                            (*item).t_color,
                            (*item).h_color,
                            (*item).highlight,
                            (*item).underline,
                            (*item).u_color);
  }
  else
  {
    draw_string_with_params((*item).font_size,
                            text_id,
                            (*item).align,
                            (*item).XPos, ((*item).YPos) - height_start,
                            disp_width, disp_height,
                            (*item).t_color,
                            (*item).h_color,
                            (*item).highlight,
                            (*item).underline,
                            (*item).u_color);
  }
}

int font_get_height(int font_size)
{
  return font_size & 0xFF;
}

void Disp_GetItemOffset(int font_size, TEXTID text_id, IMAGEID image_id, int align, int *txt_offset, int *icn_offset)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int height = dll_GetImageHeight(font_size);
  int width = dll_Disp_GetTextIDWidth(font_size, text_id, TextID_GetLength(text_id));
#else
  int height = GetImageHeight(font_size);
  int width = Disp_GetTextIDWidth(font_size, text_id, TextID_GetLength(text_id));
#endif

  int disp_width = Display_GetWidth(UIDisplay_Main);
  if (align == AlignRight)
  {
    *icn_offset = -width - height - 2;
    *txt_offset = 0;
  }
  else if (align == AlignLeft)
  {
    *icn_offset = 0;
    *txt_offset = height + 2;
  }
  else
  {
    *icn_offset = (disp_width - width - height) / 2;
    *txt_offset = height + 4;
  }
}

void DrawItemWithIcon(GC* gc, TEXT_ITEM_DATA *item, TEXTID text_id, IMAGEID image_id, int height_start)
{
  if (text_id == EMPTY_TEXTID)
    return;

  int txt_offset;
  int icn_offset;
  Disp_GetItemOffset((*item).font_size, text_id, image_id, (*item).align, &txt_offset, &icn_offset);

  int disp_height = Display_GetHeight(UIDisplay_Main);
  int disp_width = Display_GetWidth(UIDisplay_Main);

  if ((*item).align == AlignRight)
  {
    draw_string_with_params((*item).font_size,
                            text_id,
                            (*item).align,
                            0, (*item).YPos - height_start,
                            (*item).XPos + txt_offset, disp_height,
                            (*item).t_color,
                            (*item).h_color,
                            (*item).highlight,
                            (*item).underline,
                            (*item).u_color);
  }
  else
  {
    draw_string_with_params((*item).font_size,
                            text_id,
                            (*item).align,
                            (*item).XPos + txt_offset, (*item).YPos - height_start,
                            disp_width, disp_height,
                            (*item).t_color,
                            (*item).h_color,
                            (*item).highlight,
                            (*item).underline,
                            (*item).u_color);
  }

  if ((*item).align == AlignCenter)
  {
    DrawIcon(gc, ((*item).XPos / 2) + icn_offset,
             (*item).YPos,
             image_id,
             height_start);
  }
  else
  {
    DrawIcon(gc, (*item).XPos + icn_offset,
             (*item).YPos,
             image_id,
             height_start);
  }
}

void DrawIcon(GC* gc, int XPos, int YPos, IMAGEID image_id, int height_start)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_GC_PutChar(gc, XPos, YPos - height_start, 0, 0, image_id);
#else
  GC_PutChar(gc, XPos, YPos - height_start, 0, 0, image_id);
#endif
}

void DrawSlider(int value, int max_value, RECT rect, int Color_ProgressBarOutline, int Color_ProgressBar, IMAGEID thumb)
{
  int width = rect.x2 - rect.x1;
  int nx2 = rect.x1 + (value * width / max_value);

  DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Color_ProgressBarOutline, Color_ProgressBarOutline);
  DrawRect(rect.x1, rect.y1, nx2, rect.y2, Color_ProgressBar, Color_ProgressBar);

  if (thumb != NOIMAGE)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    int thumb_w = dll_GetImageWidth(thumb) / 2;
    int thumb_h = dll_GetImageHeight(thumb) / 2;
#else
    int thumb_w = GetImageWidth(thumb) / 2;
    int thumb_h = GetImageHeight(thumb) / 2;
#endif
    int thumb_x = nx2 - thumb_w;
    int thumb_y = (rect.y1 - thumb_h) + ((rect.y2 - rect.y1) / 2);

    DrawIcon(get_DisplayGC(), thumb, thumb_x, thumb_y, 0);
  }
}

void DrawString_onRect(int font, TEXTID text_id, int text_color, int rect_x, int rect_y, int rect_w, int rect_h, int fill_color)
{
  DrawRect(rect_x, rect_y, rect_x + rect_w, rect_y + rect_h, clEmpty, fill_color);
  draw_string_no_style(font, text_id, AlignCenter, rect_x, rect_y + ((rect_h - font_get_height(font)) / 2), rect_w, text_color);
}

void Draw_SliderItem(int value, int max_value, int y_pos, int height, TEXTID text_id, int text_color, int cursor_color, int outline_color, int slider_color)
{
  DrawRect(0, y_pos, 240, y_pos + height, clEmpty, cursor_color); // selected
  draw_string_no_style(FONT_E_18R, text_id, AlignLeft, 10, y_pos + 3, 220, text_color);

  RECT rect;
  rect.x1 = 10;
  rect.x2 = 230;
  rect.y1 = y_pos + 3 + font_get_height(FONT_E_18R) + 8;
  rect.y2 = y_pos + 3 + font_get_height(FONT_E_18R) + 8 + 2;
  DrawSlider(value, max_value, rect, outline_color, slider_color, 0x7F2);
}
