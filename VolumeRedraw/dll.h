#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210)
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color);
void dll_GC_PutChar( GC *pGC , int x, int y, int width, int height, IMAGEID imageID);
int dll_GetImageWidth(IMAGEID imageID);
int dll_GetImageHeight(IMAGEID imageID);
#endif

#endif
