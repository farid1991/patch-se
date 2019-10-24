#ifndef _DROW_H_
#define _DROW_H_

void DrawProgressBar(DBP_DATA* data, int cur_value, int total_value, RECT rect, int Bcolor, int Ecolor);
void DrawString_Params( TEXTID text, int font, int align, int x1, int y1, int x2, unsigned int tcolor, unsigned int ocolor, int overlay );

#endif
