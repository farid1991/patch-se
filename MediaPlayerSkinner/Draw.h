#ifndef _Draw_H_
#define _Draw_H_

void DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, unsigned int text_color);
void DrawImage(int x, int y, IMAGEID img);
void DrawImageEx(int x, int y, int w, int h, IMAGEID img);
void DrawProgressBar(IMAGEID blob_id, int value, int max_value, int x1, int y1, int x2, int y2, int Bcolor, int Ecolor, bool enable_indicator);

#endif
