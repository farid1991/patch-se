#ifndef _DRAW_H_
#define _DRAW_H_

void DrawImage(int x, int y, IMAGEID img);
void DrawProgressBar(FmRadio_Data* data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor);
void DrawString_Params( TEXTID text, int font, int align, int x1, int y1, int x2, unsigned int tcolor, unsigned int ocolor, int overlay );

#endif
