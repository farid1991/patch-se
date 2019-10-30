#ifndef _DLL_H_
#define _DLL_H_

void dll_SetFont(int font_size, IFont** ppFont);
void dll_DrawString(TEXTID text, int font, int align, int x1, int y1, int x2, int y2, int pen_color);
void dll_GC_PutChar(GC* gc, int x, int y, int width, int height, wchar_t imageID);
int dll_GetImageHeight(wchar_t imageID);
int dll_GetImageWidth(wchar_t imageID);
int dll_GetImageWidth(wchar_t imageID);
int dll_GetSignalQuality( char * rssi, char * ber );

#endif
