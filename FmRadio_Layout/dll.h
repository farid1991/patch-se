#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210)
void dll_SetFont(int font_size, IFont **ppFont);
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color);
#endif

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210)
void dll_GC_PutChar(int x, int y, int width, int height, IMAGEID imageID);
int dll_GetImageWidth(IMAGEID imageID);
int dll_GetImageHeight(IMAGEID imageID);
#endif

#endif
