#ifndef _VISUAL_H_
#define _VISUAL_H_

//==============================================================================

static const char Gui_EditColor[] = "GUI_EditColor";

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
  //int type;
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

void Create_GUI_EditColor( BOOK* book);

//==============================================================================

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
  BOOK* mbk;
} DISP_OBJ_COORD;

typedef union {
  int xy[2];
  RECT rc;
} COORD_TYPE;

void GUI_EditCoordinates_OnOk( BOOK* book, GUI* );
void GUI_EditCoordinates_OnBack( BOOK* book, GUI* );
void GUI_EditCoordinates_OnOrientationChange( BOOK* book, GUI* gui );
void Create_GUI_EditCoordinates( BOOK* book, int type);

//==============================================================================

#define font_step 1
#define max_size 100
#define bold 1
#define italic 2

enum Font_Style 
{
  Font_Normal = 0,
  Font_Bold,
  Font_Italic,
  Font_BoldItalic,
  LastFontStyle
};

static const char Gui_FontSelect[] = "GUI_SelectFont";

typedef struct GUI GUI_FONT_SEL;

typedef struct _DISP_OBJ_FONT_SEL : DISP_OBJ
{
  int cur_font;
  int cur_offs, cur_pos;
  int total_fonts;
  TEXTID item_textid;
  u16 *font_heights;
  int req_check_vis;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int style_bold;
  int style_italic;
#endif
} DISP_OBJ_FONT_SEL;

wchar_t* GetFontNameByFontId( int id );
void Create_GUI_SelectFont( BOOK* book );

#endif
