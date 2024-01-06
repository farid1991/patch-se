#ifndef _DLL_H_
#define _DLL_H_

#include "..\\include\classes\classes.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
void dll_SetFont(int font_size, int font_style, IFont **ppFont);
void dll_DrawString(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color);
int dll_Disp_GetTextIDWidth(int font, TEXTID strid, int len);
int dll_GetImageWidth(IMAGEID imageID);
int dll_GetImageHeight(IMAGEID imageID);
void dll_GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID imageID);
#endif

METADATA_DESC *dll_MetaData_Desc_Create(wchar_t *path, wchar_t *name);
void dll_MetaData_Desc_Destroy(METADATA_DESC *MetaData_Desc);
BOOL dll_MetaData_Desc_HasAlbumArt(METADATA_DESC *MetaData_Desc, wchar_t *path, wchar_t *name);
int dll_MetaData_Desc_GetCoverInfo(METADATA_DESC *MetaData_Desc, char *cover_type, int *size, int *cover_offset);

#endif
