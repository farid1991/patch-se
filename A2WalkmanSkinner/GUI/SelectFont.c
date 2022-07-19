#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\Color.h"
#include "..\\..\\include\classes\classes.h"

#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\Function.h"

#include "EditColor.h"
#include "SelectFont.h"

//==============================================================================

#if defined(DB3150v1) || defined(DB3150v2)
wchar_t *GetFontNameByFontId(int id)
{
  wchar_t *txt = L"Undefined";
  FONT_DESC *font_desc = GetFontDesc;
  int count = *GetFontCount;
  for (int i = 0, max = count; i < max; i++)
  {
    if (id == font_desc[i].id)
    {
      txt = font_desc[i].name;
      break;
    }
  }
  return txt;
}

int GetIdByFontId(int font_id)
{
  int id = 0;
  FONT_DESC *font_desc = GetFontDesc;
  int count = *GetFontCount;
  for (int i = 0, max = count; i < max; i++)
  {
    if (font_id == font_desc[i].id)
    {
      id = i;
      break;
    }
  }
  return id;
}
#endif

int SelectFont_OnCreate(DISP_OBJ_FONT_SEL *disp_obj)
{
  disp_obj->item_textid = EMPTY_TEXTID;
  disp_obj->t_textid = STR("Sample Text");

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  disp_obj->total_fonts = max_size / font_step;
#else
  disp_obj->total_fonts = *GetFontCount;
#endif

  return 1;
}

void SelectFont_OnClose(DISP_OBJ_FONT_SEL *disp_obj)
{
  DESTROY_TEXTID(disp_obj->t_textid);
  DESTROY_TEXTID(disp_obj->item_textid);
}

void SelectFont_OnRedraw(DISP_OBJ_FONT_SEL *disp_obj, int a, int b, int c)
{
  wchar_t ustr[32];
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  switch (disp_obj->font_style)
  {
  case UIFontStylePlain:
    snwprintf(ustr, MAXELEMS(ustr), L"FONT_E_%dR", disp_obj->font_size);
    break;
  case UIFontStyleBold:
    snwprintf(ustr, MAXELEMS(ustr), L"FONT_E_%dB", disp_obj->font_size & 0xFF);
    break;
  case UIFontStyleItalic:
    snwprintf(ustr, MAXELEMS(ustr), L"FONT_E_%dI", disp_obj->font_size & 0xFF);
    break;
  case UIFontStyleBoldItalic:
    snwprintf(ustr, MAXELEMS(ustr), L"FONT_E_%dBI", disp_obj->font_size & 0xFF);
    break;
  }
#else
  FONT_DESC *font_desc = GetFontDesc;
  snwprintf(ustr, MAXELEMS(ustr), L"%ls", GetFontNameByFontId(font_desc[disp_obj->cur_pos].id));
#endif
  disp_obj->item_textid = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);

  Draw_SliderItem(disp_obj->cur_pos, disp_obj->total_fonts,
                  40, 40,
                  disp_obj->item_textid,
                  clAlpha,
                  clBlueMidDark,
                  clGamma,
                  clCyan);

  DrawString_onRect(disp_obj->font_size,
                    disp_obj->t_textid,
                    clZeta,
                    0, 85, 240, 20 + disp_obj->font_height,
                    clAlpha);
}

void SelectFont_OnKey(DISP_OBJ_FONT_SEL *disp_obj, int key, int, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (key == KEY_LEFT || key == KEY_DIGITAL_4)
    {
      if ((--disp_obj->cur_pos) < 0)
        disp_obj->cur_pos = disp_obj->total_fonts - 1;
    }
    else if (key == KEY_RIGHT || key == KEY_DIGITAL_6)
    {
      if (++disp_obj->cur_pos >= disp_obj->total_fonts)
        disp_obj->cur_pos = 0;
    }
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    else if (key == KEY_DEL)
    {
      if (++disp_obj->style > UIFontStyleBoldItalic)
        disp_obj->style = 0;
      switch (disp_obj->style)
      {
      case UIFontStylePlain:
        disp_obj->style_bold = FALSE;
        disp_obj->style_italic = FALSE;
        break;
      case UIFontStyleBold:
        disp_obj->style_bold = TRUE;
        disp_obj->style_italic = FALSE;
        break;
      case UIFontStyleItalic:
        disp_obj->style_bold = FALSE;
        disp_obj->style_italic = TRUE;
        break;
      case UIFontStyleBoldItalic:
        disp_obj->style_bold = TRUE;
        disp_obj->style_italic = TRUE;
        break;
      }
    }
    disp_obj->font_height = (disp_obj->cur_pos + 1) * font_step;
    disp_obj->font_size = disp_obj->font_height + (disp_obj->style_bold << 8) + (disp_obj->style_italic << 9);
    disp_obj->font_style = disp_obj->font_size >> 8;
#else
    FONT_DESC *font_desc = GetFontDesc;
    disp_obj->font_size = font_desc[disp_obj->cur_pos].id;
    disp_obj->font_height = FONT_HEIGHT(disp_obj->font_size);
#endif
    InvalidateRect(disp_obj);
  }
}

void SelectFont_OnLayout(DISP_OBJ_FONT_SEL *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clWhite);
}

void SelectFont_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_FontSelect);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_FONT_SEL));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)SelectFont_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)SelectFont_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)SelectFont_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)SelectFont_OnKey);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)SelectFont_OnLayout);
}

void SelectFont_destruct(GUI *gui)
{
}

void SelectFont_callback(DISP_OBJ *disp, void *msg, GUI *gui)
{
}

void GUIObject_Font_SetDefault(GUI *gui_fontsel, int font_size)
{
  DISP_OBJ_FONT_SEL *disp_obj = (DISP_OBJ_FONT_SEL *)GUIObject_GetDispObject(gui_fontsel);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  disp_obj->cur_pos = FONT_HEIGHT(font_size) / font_step - 1;
  int style_flags = font_size >> 8;
  disp_obj->style_bold = style_flags & bold;
  disp_obj->style_italic = (style_flags & italic) >> 1;
  disp_obj->font_height = (disp_obj->cur_pos + 1) * font_step;
  disp_obj->font_size = disp_obj->font_height + (disp_obj->style_bold << 8) + (disp_obj->style_italic << 9);
  disp_obj->font_style = disp_obj->font_size >> 8;
#else
  disp_obj->cur_pos = GetIdByFontId(font_size);
#endif
}

int GUIObject_Font_GetSize(GUI *gui_fontsel)
{
  DISP_OBJ_FONT_SEL *disp_obj = (DISP_OBJ_FONT_SEL *)GUIObject_GetDispObject(gui_fontsel);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  return disp_obj->font_size;
#else
  FONT_DESC *font = GetFontDesc;
  return font[disp_obj->cur_pos].id;
#endif
}

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
int GUIObject_Font_GetStyle(GUI *gui_fontsel)
{
  DISP_OBJ_FONT_SEL *disp_obj = (DISP_OBJ_FONT_SEL *)GUIObject_GetDispObject(gui_fontsel);
  return disp_obj->font_style;
}
#endif

GUI *Create_SelectFont(BOOK *book)
{
  GUI_FONT_SEL *gui_fontsel = (GUI_FONT_SEL *)malloc(sizeof(GUI_FONT_SEL));
  if (!GUIObject_Create(gui_fontsel, SelectFont_destruct, SelectFont_construct, book, SelectFont_callback, UIDisplay_Main, sizeof(GUI_FONT_SEL)))
  {
    mfree(gui_fontsel);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gui_fontsel);

  GUIObject_SetTitleText(gui_fontsel, TEXT_FONT_SIZE);
  GUIObject_SetTitleType(gui_fontsel, UI_TitleMode_Small);

  return gui_fontsel;
}
