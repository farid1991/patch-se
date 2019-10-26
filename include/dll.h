#ifndef _DLL_H_
#define _DLL_H_

void dll_DrawString(TEXTID text, int font, TUITextAlignment align, int x1, int y1, int x2, int y2, int pen_color);
void dll_GC_PutChar(GC* gc, int x, int y, int width, int height, wchar_t imageID);
int dll_GetImageHeight(wchar_t imageID);
int dll_GetImageWidth(wchar_t imageID);
int GetSignalQuality_dll( char * rssi, char * ber );

#endif
