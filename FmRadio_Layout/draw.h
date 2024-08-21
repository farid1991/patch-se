#ifndef _DRAW_H_
#define _DRAW_H_

void DrawImage(int x, int y, IMAGEID image_id);
void DrawProgressBar(FmRadio_Data* data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor);
void DrawString_Params(TEXTID text_id, int font, int align, int x1, int y1, int x2, unsigned int t_color, unsigned int h_color, int overlay);

#endif
