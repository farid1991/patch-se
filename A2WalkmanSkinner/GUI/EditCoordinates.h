#ifndef _EDITCOORDINATES_H_
#define _EDITCOORDINATES_H_

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

static const char Gui_Coordinates[] = "GUI_EditCoordinates";

typedef struct GUI GUI_COORDINATES;

typedef struct _DISP_OBJ_COORD : DISP_OBJ
{
  int x, y, x2, y2;
  int type;
  int is_first_set;
  RECT old_rect;
  TEXTID str_id;
  int need_str;
  int cstep;
  u16 disp_width;
  u16 disp_height;
} DISP_OBJ_COORD;

typedef union
{
  int xy[2];
  RECT rc;
} COORD_TYPE;

GUI_COORDINATES *Create_EditCoordinates(BOOK *book, int type);

#endif
