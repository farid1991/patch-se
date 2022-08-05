#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void dll_SetFont(int font_size, uint16_t font_style, IFont **ppFont);
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, unsigned pen_color);
#endif

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
void dll_GC_PutChar(GC* gc, int x, int y, int width, int height, IMAGEID imageID);
int dll_GetImageWidth(IMAGEID imageID);
int dll_GetImageHeight(IMAGEID imageID);
#endif

#endif
