#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void dll_SetFont(int font, IFont **ppFont);
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color, bool underline, int u_color);
int dll_Disp_GetTextIDWidth(int font, TEXTID strid, int len);

int dll_GetImageWidth(IMAGEID imageID);
int dll_GetImageHeight(IMAGEID imageID);
void dll_GC_PutChar(GC* gc, int x, int y, int width, int height, IMAGEID imageID);
void DrawImageFromPath(wchar_t *fname, int x, int y);
#endif

#ifdef A2
int dll_GetSignalQuality( char * rssi, char * ber );
#endif

void Get_IClock(IClock **ppIClock);
void Get_IAlarm(IAlarmItem **ppIAlarmItem, IAlarmRecurrent **ppIAlarmRecurrent);

#endif
