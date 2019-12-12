#ifndef _DLL_H_
#define _DLL_H_

// Text Rendering --------------------------------------------------------------
int dll_SetFont(int FontSize, TUIEmphasisStyle FontStyle, IUIFont** ppFont);
void dll_DrawString(int FontSize, 
                    TEXTID text_id, 
                    int align, 
                    int x1, 
                    int y1, 
                    int x2, 
                    int y2, 
                    int pen_color, 
                    bool IsUnderlined, 
                    int u_color);

int dll_Disp_GetTextIDWidth( int font, TEXTID strid, int len );

// Image & Graphic -------------------------------------------------------------
void dll_DrawWString(int FontSize, 
                     wchar_t* pString,
                     int alignment,
                     int XPos,
                     int YPos,
                     int Width,
                     unsigned int Color);
void dll_DrawIUIText(int FontSize, 
                     wchar_t* pString,
                     int alignment,
                     int XPos,
                     int YPos,
                     int Width,
                     int Height,
                     unsigned int Color);

void dll_GC_PutChar(GC* GraphicCanvas, 
                    int XPos, 
                    int YPos, 
                    int Width, 
                    int Height, 
                    IMAGEID image_id);

int dll_GetImageHeight( IMAGEID image_id );
int dll_GetImageWidth( IMAGEID image_id );

TColour dll_GetForegroundColor(UIThemeColor_t ThemeColor);
TColour dll_GetBackgroundColor(UIThemeColor_t ColorType);
int dll_GetStringWidth( int FontSize, TChar* pString );

void dll_GetBackgroundImageSize(UIBackgroundManagerImage_t image, 
                                TUnsigned* pWidth, 
                                TUnsigned* pHeight);

void dll_SetTrayIcon( wchar_t icon, bool show );
void dll_BlinkTrayIcon( IMAGEID icon, char BlinkMode );
void dll_ShowTrayClock( int display, bool show );

// GUIObject -------------------------------------------------------------------
void dll_GUIObject_SetCursorImage( GUI* gui, IMAGEID imageID );
void dll_GUIObject_SetBackgroundImage( GUI* gui, IMAGEID imageID );
void dll_GUIObject_SetTitleTextColor( GUI* gui, int color );
void GUIObject_SetAnimation(GUI* gui, int anim);

// Misc ------------------------------------------------------------------------
int dll_GetSignalQuality( char * rssi, char * ber );

#endif
