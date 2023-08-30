#ifndef _EDITOR_H_
#define _EDITOR_H_

static const char GuiName_Color[] = "GUI_SelectColor";

#define font_step 1
#define max_size 100
#define bold 1
#define italic 2

typedef struct GUI GUI_COLOR;

typedef struct _DISP_OBJ_COLOR : DISP_OBJ
{
  int r, g, b, a;
  int type;
  TEXTID buf_text;
  int need_str;
  int current_column;
  int cstep;
}DISP_OBJ_COLOR;

void SetActivate(BOOK* book, int count);
void OneOfMany_SetMode(BOOK* book, int type);
void Create_ColorPicker(BOOK *book, int type);
void Create_GUIEditor(BOOK* book);

wchar_t* Font_GetNameByFontId(int id);
int GetIdByFontId(int id);

#endif
