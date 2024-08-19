#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210)
void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int pen_color);
int dll_Disp_GetTextIDWidth(int font, TEXTID text_id, int len);

void dll_GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID image_id);
int dll_GetImageWidth(IMAGEID image_id);
int dll_GetImageHeight(IMAGEID image_id);
#endif

void GUIObject_SetAnimation(GUI *gui, int anim);

#endif
