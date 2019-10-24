#ifndef _INTERNALFUNCTION_H_
#define _INTERNALFUNCTION_H_

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
int SetFont( int font_size );
void DrawString( TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color );
void GC_PutChar(GC* gc, int x, int y, int width, int height, IMAGEID);
int GetImageHeight(IMAGEID);
int GetImageWidth(IMAGEID);
int Disp_GetTextIDWidth( TEXTID strid, int len );
void GC_DrawIcon( int x, int y, IMAGEID imageID);
#endif

#if defined(A2)
void* MetaData_Desc_Create( wchar_t* fullpath );
void MetaData_Desc_Destroy( void* MetaData_Desc );
int MetaData_Desc_GetCoverInfo( void* MetaData_Desc, char* cover_type, int* size, int* cover_offset );
wchar_t* MetaData_Desc_GetTags( void* MetaData_Desc, int tagID );
#endif

#endif
