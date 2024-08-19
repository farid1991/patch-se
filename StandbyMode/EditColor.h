#ifndef _EDITCOLOR_H_
#define _EDITCOLOR_H_

static const char Gui_EditColor[] = "GUI_EditColor";

#define FRAME_COLOR 0xB0000000

enum 
{
  ROW_1,
  ROW_2,
  ROW_3,
  ROW_4,
  LAST_ROW
};

typedef struct GUI GUI_COLOR;

typedef struct _DISP_OBJ_COLOR : DISP_OBJ
{
  int r, g, b, a;
  int current_row;
  TEXTID t_textid;
  TEXTID r_textid;
  TEXTID g_textid;
  TEXTID b_textid;
  TEXTID a_textid;
  int r_color;
  int g_color;
  int b_color;
  int a_color;
  int text_color;
} DISP_OBJ_COLOR;

typedef union 
{
  color_t int_color;
  char* char_color;
} COLOR_TYPE;

GUI *Create_EditColor( BOOK* book, int color );
unsigned int GUIObject_EditColor_GetColor( GUI *gui_color );
int GUIObject_EditColor_GetRed( GUI *gui_color );
int GUIObject_EditColor_GetGreen( GUI *gui_color );
int GUIObject_EditColor_GetBlue( GUI *gui_color );
int GUIObject_EditColor_GetAlpha( GUI *gui_color );

#endif
