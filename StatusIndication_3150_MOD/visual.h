#ifndef _VISUAL_H_
#define _VISUAL_H_

//#include "editor.h"

const int colors[4] = { clRed, clGreen, clBlue, 0x80C6AAAF };

#define MIN( a, b ) ( a < b ) ? a : b
#define MAX( a, b ) ( a  >  b ) ? a : b

#define COLOR_GET_A(x) ((unsigned int)x>>24)
#define COLOR_GET_R(x) (((unsigned int)x>>16)&0xFF)
#define COLOR_GET_G(x) (((unsigned int)x>>8)&0xFF)
#define COLOR_GET_B(x) ((unsigned int)x&0xFF)
#define COLOR_RGBA(r,g,b,a) (((unsigned int)r<<16)|((unsigned int)g<<8)|((unsigned int)b)|((unsigned int)a<<24))

static const char EditColorGuiName[] = "Gui_EditColor";

typedef struct GUI GUI_COLOR;

typedef struct _DISP_OBJ_COLOR : DISP_OBJ
{
  int r, g, b, a;
  int type;
  int current_column;
  TEXTID str_id;
  int need_str;
  int cstep;
} DISP_OBJ_COLOR;

typedef union 
{
  unsigned int int_color;
  char *char_color;
} COLOR_TYPE;

static const char FontSelectGuiName[] = "Gui_FontSelect";

const char test_str[] = "Test string 123";

typedef struct GUI GUI_FONT_SEL;

typedef struct _DISP_OBJ_FONT_SEL : DISP_OBJ
{
  int cur_font;
  int cur_offs, cur_pos;
  int total_fonts;
  TEXTID test_str_id;
  u16 *font_heights;
  int req_check_vis;
} DISP_OBJ_FONT_SEL;

GUI_COLOR* CreateEditColorGUI(MyBOOK * myBook, int type);
GUI_FONT_SEL* CreateFontSelectGUI(MyBOOK * myBook);
wchar_t* Font_GetNameByFontId(int id);
void OnOkCoordinatesEdit( BOOK* bk, void* );
void OnBackCoordinatesEdit( BOOK* bk, void* );
void OnOrientationChangeCoordinatesEdit( BOOK* bk, void* );

#endif
