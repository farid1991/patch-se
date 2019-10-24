#ifndef _VISUAL_H_
#define _VISUAL_H_

//#define font_step 1
//#define max_size 100
//#define bold 1
//#define italic 2

static const char Gui_EditColor[] = "Gui_EditColor";
static const char Gui_Coordinates[] = "Gui_Coordinates";
static const char Gui_FontSelect[] = "Gui_FontSelect";

#define COLOR_GET_A(a) ((color_t)a>>24)
#define COLOR_GET_R(r) (((color_t)r>>16)&0xFF)
#define COLOR_GET_G(g) (((color_t)g>>8)&0xFF)
#define COLOR_GET_B(b) ((color_t)b&0xFF)

#define MIN( a, b ) ( a < b ) ? a : b
#define MAX( a, b ) ( a > b ) ? a : b

#define COLOR_RGBA(r,g,b,a) (((color_t)r<<16)|((color_t)g<<8)|((color_t)b)|((color_t)a<<24))


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
  color_t int_color;
  char* char_color;
} COLOR_TYPE;

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
  BOOK* mb;
} DISP_OBJ_COORD;

typedef union {
  int xy[2];
  RECT rc;
} COORD_TYPE;

typedef struct GUI GUI_FONT_SEL;

typedef struct _DISP_OBJ_FONT_SEL : DISP_OBJ
{
  int cur_font;
  int cur_offs, cur_pos;
  int total_fonts;
  TEXTID test_str_id;
  u16 *font_heights;
  int req_check_vis;
  //int platform_flag;
  //int style_bold;
  //int style_italic;
} DISP_OBJ_FONT_SEL;

void OnOkCoordinatesEdit( BOOK* book, GUI* );
void OnBackCoordinatesEdit( BOOK* book, GUI* );
void OnOrientationChangeCoordinatesEdit( BOOK* book, GUI* gui );

wchar_t* Font_GetNameByFontId( int font_id );

#endif
