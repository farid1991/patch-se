#ifndef _SELECTFONT_H_
#define _SELECTFONT_H_

#if defined(DB3200) || defined(DB3210)
#define max_size 100
#define bold 1
#define italic 2
#endif

#define FONT_HEIGHT(font) (font & 0xFF)

static const char Gui_FontSelect[] = "GUI_XFont";

typedef struct GUI GUI_FONT_SEL;

typedef struct _DISP_OBJ_FONT_SEL : DISP_OBJ
{
  int cur_pos;
  TEXTID t_textid;
  TEXTID item_textid;
  int total_fonts;
  int font_size;
  int font_height;
#if defined(DB3200) || defined(DB3210)
  bool style_bold;
  bool style_italic;
  uint8_t font_style;
  uint8_t current_style;
#endif
  uint16_t disp_width;
  uint16_t rect_height;
} DISP_OBJ_FONT_SEL;

#if defined(DB3150v1) || defined(DB3150v2)
wchar_t *GetFontNameByFontId(int id);
int GetIdByFontId(int font_id);
#endif

GUI_FONT_SEL *Create_SelectFont(BOOK *book);
void GUIObject_Font_SetDefault(GUI_FONT_SEL *gui_fontsel, int font_size);
int GUIObject_Font_GetSize(GUI_FONT_SEL *gui_fontsel);

#if defined(DB3200) || defined(DB3210)
int GUIObject_Font_GetStyle(GUI_FONT_SEL *gui_fontsel);
#endif

#endif
