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
void DrawProgressBar(DBP_DATA *data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor);
void DrawString_Params(TEXTID text, int font, int align, int x1, int y1, int x2, unsigned int tcolor, unsigned int ocolor, int overlay);

#endif
