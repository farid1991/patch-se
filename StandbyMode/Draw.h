#ifndef _DRAW_H_
#define _DRAW_H_

#include "standby_data.h"

enum
{
  HighlightOff,
  HighlightFullV1,
  HighlightFullV2,
  HighlightShadow,

  HighlightLast
};

void DrawIconsArray(GC* gc, int align, int x, int y, IMAGEID *icons, int len, int width);

void draw_string_with_params(int font, TEXTID text, int align, int XPos, int YPos, int MaxXPos, int MaxYPos, int t_color, int h_color, int highlight, bool IsUnderlined, int u_color);
void draw_string_no_style(int font, TEXTID text, int align, int XPos, int YPos, int Width, int t_color);

void DrawItem(TEXT_ITEM_DATA *item, TEXTID text_id, int height_start);
void DrawItemWithIcon(GC* gc, TEXT_ITEM_DATA *item, TEXTID text_id, IMAGEID image_id, int height_start);

int font_get_height(int font);

void DrawIcon(GC* gc, int XPos, int YPos, IMAGEID image_id, int height_start);
void DrawString_onRect(int font, TEXTID textid, int text_color, int rect_x, int rect_y, int rect_w, int rect_h, int fill_color);
void Draw_SliderItem(int value, int max_value, int y_pos, int height, TEXTID textid, int text_color, int cursor_color, int outline_color, int slider_color);

#endif
