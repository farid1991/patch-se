#ifndef _EDITOR_H_
#define _EDITOR_H_

#define COLOR_GET_A(x) ((unsigned int)x>>24)
#define COLOR_GET_R(x) (((unsigned int)x>>16)&0xFF)
#define COLOR_GET_G(x) (((unsigned int)x>>8)&0xFF)
#define COLOR_GET_B(x) ((unsigned int)x&0xFF)
#define COLOR_RGBA(r, g, b, a) (((unsigned int)r<<16)|((unsigned int)g<<8)|((unsigned int)b)|((unsigned int)a<<24))

static const char GuiName_Color[] = "GUI_Color";

#define font_step 1
#define max_size 100
#define bold 1
#define italic 2

typedef struct _DISP_OBJ_COLOR : DISP_OBJ
{
  int r, g, b, a;
  int type;
  TEXTID buf_text;
  int need_str;
  int current_column;
  int cstep;
}DISP_OBJ_COLOR;

void SetActivate(SETTING_BOOK* m_bk, int count);
void OneOfMany_SetMode(SETTING_BOOK* m_bk, int type);
void SetColor(SETTING_BOOK* m_bk, int type);
void SetActiveSoft(DBP_DATA* data, BOOL mode);
wchar_t* Font_GetNameByFontId(int id);
void SetVisual(SETTING_BOOK* m_bk);

#endif
