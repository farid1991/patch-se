#ifndef _IUIGRAPHICMANAGER_H_
#define _IUIGRAPHICMANAGER_H_

#include "..\\include\classes\IUIFontManager.h"

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\UIGraphic_types.h"
#include "..\\include\types\UIGUI_types.h"

const UUID CID_CUIGraphicManager = {0x27,0xCF,0x8C,0xE0,0x23,0x6A,0x45,0xCF,0xA3,0xF2,0xCB,0x3B,0xC6,0x62,0xEE,0x13};
const UUID IID_IUIGraphicManager = {0x60,0x1A,0x56,0x0B,0x35,0x46,0x4E,0x26,0xBF,0xDE,0x28,0x5F,0x97,0xC4,0x18,0xA4};

const UUID IID_IUIStatusrow={0x5D,0xFE,0x94,0xA1,0x93,0x80,0x49,0x27,0x84,0x62,0xA3,0xA1,0xEF,0xD5,0x72,0x43};
const UUID CID_CUIStatusrow={0x50,0xD7,0xBA,0x40,0x0A,0x19,0x47,0x3C,0xAA,0x51,0xF9,0x5E,0xDF,0xFB,0x4E,0x29};

class IUIGraphics : public IRoot
{
public:
  /**
   * Get current foreground color of specified object.
   *
   * @param colorType [in]  The theme color type.
   * @param pColor    [out] Pointer to the color.
   * @return This method returns an RVoid status code.
   */
  virtual int GetForegroundColor( UIThemeColor_t colorType, TColour* pColor );
  
  /**
   * Get current background color of specified object.
   *
   * @param colorType [in]  The theme color type.
   * @param pColor    [out] Pointer to the color. 
   * @return This method returns an RVoid status code.
   */
  virtual int GetBackgroundColor( UIThemeColor_t colorType, TColour* pColor );
  
  /**
   * Get the string width in pixels.
   *
   * @param pIFont    [in]  Pointer to the font to use.
   * @param pString   [in]  UCS2 encoded string.
   * @param strLen    [in]  Number of characters (not including NULL).
   * @param pStrWidth [out] The string width.
   * @return This method returns an RVoid status code.
   */
  virtual int  GetStringWidth(IUIFont* pIUIFont, 
                              TChar* pString, 
                              TUnsigned strLen, 
                              FUint16* pStrWidth );
  
  /**
   * Draws the specified string in a rectangle.
   *
   * @param pICanvas  [in] Pointer to the destination canvas.
   * @param pIFont    [in] Pointer to the font to use.
   * @param color     [in] The color to draw the text with.
   * @param pString   [in] UCS2 encoded string.
   * @param strLen    [in] Number of characters (not including NULL).
   * @param alignment [in] The alignment.
   * @param x         [in] The x coordinate.
   * @param y         [in] The y coordinate.
   * @param width     [in] The width of the containing rectangle.
   * @param height    [in] The height of the containing rectangle.
   * @return This method returns an RVoid status code.
   */
  virtual int  DrawString(IRoot *pICanvas, 
                          IUIFont *pIUIFont, 
                          TColour color, 
                          TChar *pString, 
                          TUnsigned strLen, 
                          UITextAlignment_t alignment, 
                          TCoordinate x, 
                          TCoordinate y, 
                          TUnsigned width, 
                          TUnsigned height );
  
  /**
   * Draws the specified IUIText in a rectangle.
   *
   * @param pICanvas  [in] Pointer to the destination canvas.
   * @param pIFont    [in] Pointer to the font to use.
   * @param color     [in] The color to draw the text with.
   * @param pIUIText  [in] The IUIText instance to draw.
   * @param alignment [in] The alignment.
   * @param x         [in] The x coordinate.
   * @param y         [in] The y coordinate.
   * @param width     [in] The width of the containing rectangle.
   * @param height    [in] The height of the containing rectangle.
   * @return This method returns an RVoid status code.
   */
  virtual int  DrawIUIText(IRoot * pICanvas,
                           IUIFont* pIUIFont, 
                           TColour color, 
                           IUIText* pIUIText, 
                           UITextAlignment_t alignment, 
                           TCoordinate x, 
                           TCoordinate y, 
                           TUnsigned width, 
                           TUnsigned height );  
  
  /**
   * Draws the background associated with a particular object type.
   * If the image is smaller than width and/or height it will be drawn
   * from the top left corner.
   *
   * @param pICanvas [in] Pointer to the destination canvas.
   * @param image    [in] The type of image to draw.
   * @param color    [in] If there is no bitmap image associated with the background
   *                      or if the bitmap does not cover width*height pixels, the remaining
   *                      pixels will be filled with this color.
   * @param srcX     [in] X-offset from top left corner of the source.
   * @param srcY     [in] Y-offset from top left corner of the source.
   * @param dstX     [in] X-offset from top left corner of the destination.
   * @param dstY     [in] Y-offset from top left corner of the destination.
   * @param width    [in] The width of the background to be drawn.
   * @param height   [in] The height of the background to be drawn.
   * @return This method returns an RVoid status code.
   */
  virtual int  DrawBackground(IRoot *pICanvas,
                              UIBackgroundManagerImage_t image, 
                              TColour color, 
                              TCoordinate srcX, 
                              TCoordinate srcY, 
                              TCoordinate dstX, 
                              TCoordinate dstY, 
                              TUnsigned width, 
                              TUnsigned height );
  
  /**
   * Draw frame
   * 
   * @param pICanvas   [in] Pointer to the destination canvas.
   * @param x          [in] Left x position.
   * @param y          [in] Top y position.
   * @param width      [in] The width of the rectangle.
   * @param height     [in] The height of the rectangle.
   * @param foreground [in] Foreground color.
   * @param background [in] Background (shadow) color.
   * @return This method returns an RVoid status code.
   */
  virtual int  DrawFrame(IRoot * pICanvas,
                         TCoordinate x,
                         TCoordinate y,
                         TUnsigned width, 
                         TUnsigned height, 
                         TColour foreground, 
                         TColour background );
  
  /**
   * Flush the caches
   */
  virtual int  FlushCaches(void);
  
  /**
   * Try to match a font by the given input
   *
   * @param face     [in] Face of the font to match
   * @param style    [in] Style of the font
   * @param size     [in] Size of the font
   * @param ppIFont  [out] When a match is found ppIFont will be filled.
   * @return This method returns an RVoid status code.
   */
  virtual int  MatchFont(UIGraphicsFontFace_t face, 
                         UIGraphicsFontStyle_t style, 
                         UIGraphicsFontSize_t size, 
                         IUIFont** ppIUIFont);
  
  /**
   * Get background image size
   *
   * @param image    [in]  The type of image.
   * @param pWidth   [out] The width of the image
   * @param pHeight  [out] The height of the image
   * @return This method returns an RVoid status code.
   */
  virtual int  GetBackgroundImageSize(UIBackgroundManagerImage_t image, TUnsigned* pWidth, TUnsigned* pHeight);    
};

class IUIStatusrow : public IRoot
{
public:
  /**
   * Show or hide a statusrow icon.
   *
   * @param icon [in] The icon to show/hide.
   * @param show [in] TRUE if the icon should be shown.
   * @return This method returns an RVoid status code.
   */
  virtual int ShowTrayIcon(TChar icon, TBool show);
  
  /**
   * Set the blink behaviour for an icon. Default is off.
   *
   * @param icon [in] The icon to show/hide.
   * @param mode [in] The blink mode.
   * @return This method returns an RVoid status code.
   */
  virtual int BlinkTrayIcon(TChar icon, char mode);
  
  /**
   * Show or hide statusrow clock.
   *
   * @param display [in] Which display it concerns.
   * @param show [in] TRUE if the clock should be shown.
   * @return This method returns an RVoid status code.
   */
  virtual int ShowTrayClock(UI_Display_t display, TBool show);
};

class IUIGraphicManager : public IRoot
{
public:
  /**
   * Create graphics interface
   *
   */
  virtual int CreateGraphics(IUIGraphics** pIUIGraphics);
  
  /**
   * Create status row interface
   *
   */
  virtual int CreateStatusrow(IUIStatusrow** pIUIStatusrow);
};

#endif
