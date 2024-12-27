#ifndef _DRAW_H_
#define _DRAW_H_

void DrawImage(int x, int y, IMAGEID image_id);
void DrawProgressBar(FmRadio_Data *data, int cur_value, int total_value, RECT rect, uint32_t b_color, uint32_t e_color);
void DrawString_Params(TEXTID text_id, int font, int align, int x1, int y1, int x2, uint32_t t_color, uint32_t h_color, uint8_t overlay);

#endif
