#ifndef _DRAW_H_
#define _DRAW_H_

int GetTextIDWidth(int font, TEXTID text_id, int len);
void DrawText(int font, TEXTID text_id, int align, int XPos, int YPos, int width, int text_color);
void DrawTextEx(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int text_color);
void DrawTextOnRect(int font, TEXTID text_id, int rect_x, int rect_y, int rect_w, int rect_h, int text_color, int bg_color);

void DrawImage(IMAGEID image_id, int x, int y);
void DrawImageEx(GC *gc, int x, int y, int w, int h, IMAGEID image_id);

void DrawProgressBar(int value, int max_value, RECT rect, int bg_color, int fill_color);
void DrawSlider(int value, int max_value, int main_y1, int main_height, TEXTID slider_text, int text_size, int text_color, int bg_color, int slider_bcolor, int slider_fcolor, int thumb_color);

#endif
