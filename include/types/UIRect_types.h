#ifndef __UIRECT_TYPES_H__
#define __UIRECT_TYPES_H__

#include "Basic_types.h"

/**
 *  Used for dimension, e.g width and height
 */
typedef FSint32 TUIDimension;

/**
 *  Used for positions, e.g x and y
 */
typedef FSint32 TUIPosition;

/**
 *  Used for point representation
 */
typedef struct
{
  TUIPosition X;
  TUIPosition Y;
} TUIPoint;

/**
 *  Used for size representation
 */
typedef struct
{
  TUIDimension Width;
  TUIDimension Height;
} TUISize;

/**
 *  Used for rectangles
 */
typedef struct
{
  TUIPoint Point;
  TUISize Size;
} TUIRectangle;

enum UIRectLocationEnum
{
  UI_Inside = 0,
  UI_Above = 2,
  UI_Below = 4,
  UI_Left = 8,
  UI_Right = 16
};
typedef FUint32 TUIPointLocation;

#endif
