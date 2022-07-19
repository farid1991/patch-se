#ifndef _DRAW_H_
  #define _DRAW_H_

#include "main.h"

#define str_pos(x) x+3

#define bar_x 10
#define end_bar 230
#define bar_y 8
#define bar_height 2

#define font_h(font) (font&0xFF)

void Draw_String(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int NormalColor);
void DrawString_Params(int font, TEXTID text, int align, int XPos, int YPos, int width ,int NormalColor);
void DrawString_onRect(int font, TEXTID text, int text_color, int rect_x, int rect_y, int rect_w, int rect_h, int fill_color);

void DrawIcon(IMAGEID img, int x, int y);
void DrawImage( GC* gc, int x, int y, int w, int h, IMAGEID img );

void DrawSlider( int value, int max_value, RECT rect, int Color_ProgressBarOutline, int Color_ProgressBar, IMAGEID thumb );
void DrawProgressBar( Internal_Function* Data, int value, int max_value, RECT rect, int Bcolor, int Ecolor );

void DrawRectangle(int x, int y, int w, int h, int border_color, int fill_color);
void Draw_SliderItem( int value, int max_value, int y_pos, int height, TEXTID textid, unsigned int text_color, unsigned int cursor_color, unsigned int outline_color, unsigned int slider_color );

#endif
