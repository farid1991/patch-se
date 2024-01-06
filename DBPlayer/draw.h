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

void DrawImage(int x, int y, IMAGEID img);
void DrawImageEx(GC *gc, int x, int y, int w, int h, IMAGEID img);
void DrawProgressBar(DBP_DATA *data, int cur_value, int total_value, RECT rect, uint32_t Bcolor, uint32_t Ecolor);
void DrawText(int font, TEXTID text, int align, int x1, int y1, int x2, uint32_t TextColor);
void DrawTextEx(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, uint32_t TextColor);
void DrawTextWithStyle(TEXTID text, int font, int align, int x1, int y1, int x2, unsigned int tcolor, unsigned int ocolor, int overlay);

#endif
