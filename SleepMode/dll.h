#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int pen_color);
int dll_GetImageWidth(IMAGEID image_id);
int dll_GetImageHeight(IMAGEID image_id);
void dll_GC_PutChar(int x, int y, int width, int height, IMAGEID image_id);
#endif

#endif
