#ifndef _IUIUTILMANAGER_H_
#define _IUIUTILMANAGER_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\UIUtil_types.h"

class IUIDisplay : public IRoot
{
public:
  /**
   * Get the display session for a display.
   *
   * @param display           [in]  The display index.
   * @param ppIDisplaySession [out] Pointer to the display session.
   * @return This method returns an RVoid status code.
   */
  virtual int GetDisplaySession( UIDisplay_t display, IRoot** ppIDisplaySession);

  /**
   * Get active display index.
   *
   * @param pDisplay [out] Pointer to the active display index.
   * @return This method returns an RVoid status code.
   */
  virtual int GetActive( UIDisplay_t* pDisplay );

  /**
   * Check if redraw is allowed on display.
   *
   * @param display        [in]  The display index.
   * @param pRedrawAllowed [out] Pointer to a flag that tells if redraw is allowed or not.
   * @return This method returns an RVoid status code.
   * @see IUIDisplay::SetRedrawAllowed
   */
  virtual int GetRedrawAllowed( UIDisplay_t display, TBool* pRedrawAllowed);

  /**
   * Get display orientation mode.
   *
   * @param display      [in]  The display index.
   * @param pOrientation [out] Pointer to the orientation mode.
   * @return This method returns an RVoid status code.
   */
  virtual int GetOrientationMode( UIDisplay_t display, UIDisplayOrientationMode_t* pOrientation);

  /**
   * Check if display is powered on.
   *
   * @param display    [in]  The display index.
   * @param pPoweredOn [out] Pointer to a flag that tells if the display is powered on.
   * @return This method returns an RVoid status code.
   * @see IUIDisplay::PowerOn, IUIDisplay::PowerOff
   */
  virtual int GetPoweredOn( UIDisplay_t display, TBool* pPoweredOn );

  /**
   * Set if redraw should be allowed on display.
   *
   * @param display [in] The display index.
   * @param allowed [in] Set if redraw should be allowed.
   * @return This method returns an RVoid status code.
   * @see IUIDisplay::GetRedrawAllowed
   */
  virtual int SetRedrawAllowed( UIDisplay_t display, TBool allowed );

  /**
   * Power on display.
   *
   * @param display [in] The display index.
   * @return This method returns an RVoid status code.
   * @see IUIDisplay::GetPoweredOn, IUIDisplay::PowerOff
   */
  virtual int PowerOn( UIDisplay_t display );

  /**
   * Power off display.
   *
   * @param display [in] The display index.
   * @param prepare [in] Prepare for power off if current HW configuration requires this.
   * @return This method returns an RVoid status code.
   * @see IUIDisplay::GetPoweredOn, IUIDisplay::PowerOn
   */
  virtual int PowerOff( UIDisplay_t display, TBool prepare );

};

class IUILayoutHandler : public IRoot
{
public:
  /**
   * Get the display object layout settings.
   *
   * @param pObjectName [in]  Name of the object.
   * @param layout      [in]  Current layout.
   * @param display     [in]  Current display.
   * @param orientation [in]  Current orientation.
   * @param pSettings   [out] Destination settings object.
   */
  virtual int GetLayoutSettings(TAscii* pObjectName,
                                UILayoutMode_t layout,
                                UIDisplay_t display,
                                UIDisplayOrientationMode_t orientation,
                                UIDispSettings_t* pSettings); 
  /**
   * Get the display object layout attributes.
   *
   * Observe: UILayoutAttributes_t contains a quite large buffer of integers, 
   * be aware if you're planning on storing it on the stack.
   *
   * @param pObjectName [in]  Name of the object.
   * @param layout      [in]  Current layout.
   * @param display     [in]  Current display.
   * @param orientation [in]  Current orientation.
   * @param pAttributes [out] Destination attributes object.
   */
  virtual int GetLayoutAttributes(TAscii* pObjectName,
                                  UILayoutMode_t layout,
                                  UIDisplay_t display,
                                  UIDisplayOrientationMode_t orientation,
                                  UILayoutAttributes_t* pAttributes);

  /**
   * Get the font defined in layout settings.
   *
   * @param pObjectName [in]  Name of the object.
   * @param layout      [in]  Current layout.
   * @param display     [in]  Current display.
   * @param orientation [in]  Current orientation.
   * @param ppIFont     [out] The defined font for the object.
   */
  virtual int GetLayoutFont(TAscii* pObjectName, 
                            UILayoutMode_t layout,
                            UIDisplay_t display,
                            UIDisplayOrientationMode_t orientation,
                            IUIFont** ppIUIFont);
};

class IUIUtilManager : public IRoot
{
public:
  /**
   * Create backlight interface
   *
   */
  virtual int CreateBacklight( IUIBacklight** ppIUIBacklight);

  /**
   * Create display interface
   *
   */
  virtual int CreateDisplay( IUIDisplay** ppIUIDisplay);

  /** 
   * Create layouthandler interface
   *
   */
  virtual int CreateLayoutHandler( IUILayoutHandler** ppIUILayoutHandler);
};

#endif
