#ifndef __UIUTIL_TYPES_H__
#define __UIUTIL_TYPES_H__

/**
 * Backlight mode.
 *
 * @param UIBacklightMode_On        Always on
 * @param UIBacklightMode_Off       Always off
 * @param UIBacklightMode_Automatic Automatic
 * @param UIBacklightMode_LowOff    Automatic with low instead of off
 * @param UIBacklightMode_LowOn     Automatic with low instead of on
 */
typedef enum
{
  UIBacklightMode_On,
  UIBacklightMode_Off,
  UIBacklightMode_Automatic,
  UIBacklightMode_LowOff,
  UIBacklightMode_LowOn
} UIBacklightMode_t;

/**
 * Backlight status.
 *
 * @param UIBacklightStatus_On    Backlight is on
 * @param UIBacklightStatus_Off   Backlight is off
 * @param UIBacklightStatus_Blink Backlight is blinking
 * @param UIBacklightStatus_Low   Backlight is on with low intensity
 */
typedef enum
{
  UIBacklightStatus_On,
  UIBacklightStatus_Off,
  UIBacklightStatus_Blink,
  UIBacklightStatus_Low
} UIBacklightStatus_t;

/**
 * Display Orientation
 *
 * @param UIDisplayOrientationMode_Vertical           Vertical orientation
 * @param UIDisplayOrientationMode_Horizontal         Horizontal orientation
 * @param UIDisplayOrientationMode_HorizontalReversed Reversed horizontal orientation
 * @param UIDisplayOrientationMode_Last               End
 */
typedef enum
{
  UIDisplayOrientationMode_Vertical = 0,
  UIDisplayOrientationMode_Horizontal,
  UIDisplayOrientationMode_HorizontalReversed,
  UIDisplayOrientationMode_Last,
  UI_Display_OrientationMode_Vertical = 0,
  UI_Display_OrientationMode_Horizontal,
  UI_Display_OrientationMode_Horizontal_Reversed,
  UI_Display_OrientationMode_Last
} UIDisplayOrientationMode_t;

typedef UIDisplayOrientationMode_t UI_Display_OrientationMode_t;

/**
 * Layout mode
 *
 * @param UILayoutMode_Normal         Normal layout
 * @param UILayoutMode_Asian          Asian layout
 * @param UILayoutMode_Last           End
 */
typedef enum
{
  UILayoutMode_Normal,
  UILayoutMode_Asian,
  UILayoutMode_Last 
} UILayoutMode_t;

/**
 * ScrollBar mode.
 */
typedef enum
{
  DispScrollBarMode_None,             ///< Show no scroll bar
  DispScrollBarMode_AlwaysRight,      ///< Always show the scroll bar on the right side of the object.  
  DispScrollBarMode_DynamicRight,     ///< Show scroll bar only if neccessary on the right side of the object. Mark that the scrollbar is layered above the focused object.
  DispScrollBarMode_AlwaysLeft,       ///< Always show the scrollbar on the left side of the object.
  DispScrollBarMode_DynamicLeft,      ///< Show scroll bar only if neccessary on the left side of the object. Mark that the scrollbar is layered above the focused object.
  DispScrollBarMode_HorizontalAlways, ///< Always show the horizontal scroll bar
  DispScrollBarMode_HorizontalDynamic ///< Show the horizontal scroll bar only if neccessary. Mark that the scrollbar is layered above the focused object.
} DispScrollBarMode_t;

/*@}*/

#endif
