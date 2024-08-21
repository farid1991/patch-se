#ifndef _DRAW_H_
#define _DRAW_H_

enum TEXTOVERLAY_TYPE
{
  TEXTOVERLAY_NONE,
  TEXTOVERLAY_TYPE1,
  TEXTOVERLAY_TYPE2,
  TEXTOVERLAY_TYPE3,
  TEXTOVERLAY_LAST
};

void DrawImage(int x, int y, IMAGEID image_id);
void DrawImageEx(GC *gc, int x, int y, int w, int h, IMAGEID image_id);
void DrawProgressBar(DBP_DATA *data, int cur_value, int total_value, RECT rect, uint32_t b_color, uint32_t e_color);
void DrawText(int font, TEXTID text_id, int align, int x1, int y1, int x2, uint32_t t_color);
void DrawTextEx(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, uint32_t t_color);
void DrawTextWithStyle(TEXTID text_id, int font, int align, int x1, int y1, int x2, uint32_t t_color, uint32_t h_color, int overlay);

#endif
