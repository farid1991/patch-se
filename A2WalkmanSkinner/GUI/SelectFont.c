#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\classes\classes.h"

#include "..\\Colors.h"
#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\Function.h"

#include "EditColor.h"
#include "SelectFont.h"

//==============================================================================

wchar_t *GetFontNameByFontId(int font_size)
{
#if defined(DB3200) || defined(DB3210)
  wchar_t *font_name = (wchar_t *)malloc(16 * sizeof(wchar_t)); // Allocate memory

  // Handle memory allocation error
  if (font_name == NULL)
    return NULL;

  switch (font_size >> 8)
  {
  case UIFontStylePlain:
    snwprintf(font_name, 16, L"Font_E_%dR", font_size);
    break;
  case UIFontStyleBold:
    snwprintf(font_name, 16, L"Font_E_%dB", font_size & 0xFF);
    break;
  case UIFontStyleItalic:
    snwprintf(font_name, 16, L"Font_E_%dI", font_size & 0xFF);
    break;
  case UIFontStyleBoldItalic:
    snwprintf(font_name, 16, L"Font_E_%dBI", font_size & 0xFF);
    break;
  }
  return font_name;
}
#else
  wchar_t *txt = L"Undefined";
  FONT_DESC *font_desc = GetFontDesc;
  int count = *GetFontCount;
  for (int i = 0, max = count; i < max; i++)
  {
    if (font_size == font_desc[i].id)
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
  disp_obj->t_textid = STR("String 123");

#if defined(DB3200) || defined(DB3210)
  disp_obj->total_fonts = max_size;
#else
  disp_obj->total_fonts = *GetFontCount;
#endif

  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->rect_height = ((Display_GetHeight(UIDisplay_Main) - softkeys_h) >> 3) + 5;

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
#if defined(DB3200) || defined(DB3210)
  wchar_t *font_name = GetFontNameByFontId(disp_obj->font_size);
#else
  FONT_DESC *font_desc = GetFontDesc;
  wchar_t *font_name = GetFontNameByFontId(font_desc[disp_obj->cur_pos].id);
#endif
  snwprintf(ustr, MAXELEMS(ustr), L"%ls", font_name);
  disp_obj->item_textid = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);

  DrawSlider(disp_obj->cur_pos,
             disp_obj->total_fonts,
             disp_obj->rect_height * 1,
             disp_obj->rect_height,
             disp_obj->item_textid,
             FONT_E_16R,
             SELECTED_TEXT_COLOR,
             SELECTED_CURSOR_COLOR,
             BORDER_COLOR,
             SELECTED_SLIDER_COLOR,
             SELECTED_THUMB_COLOR);

  DrawTextOnRect(disp_obj->font_size,
                 disp_obj->t_textid,
                 0,
                 (disp_obj->rect_height * 2),
                 disp_obj->disp_width,
                 disp_obj->rect_height,
                 TITLE_TEXT_COLOR,
                 TITLE_BACKGROUND_COLOR);
}

void SelectFont_OnKey(DISP_OBJ_FONT_SEL *disp_obj, int key, int count, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    switch (key)
    {
    case KEY_LEFT:
    case KEY_DIGITAL_4:
      if ((--disp_obj->cur_pos) < 0)
        disp_obj->cur_pos = disp_obj->total_fonts - 1;
      break;
    case KEY_RIGHT:
    case KEY_DIGITAL_6:
      if (++disp_obj->cur_pos >= disp_obj->total_fonts)
        disp_obj->cur_pos = 0;
      break;
#if defined(DB3200) || defined(DB3210)
    case KEY_DEL:
      if (++disp_obj->current_style > UIFontStyleBoldItalic)
        disp_obj->current_style = 0;
      switch (disp_obj->current_style)
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
      break;
#endif
    }

#if defined(DB3200) || defined(DB3210)
    disp_obj->font_height = disp_obj->cur_pos + 1;
    disp_obj->font_size = disp_obj->font_height + (disp_obj->style_bold << 8) + (disp_obj->style_italic << 9);
    disp_obj->font_style = disp_obj->font_size >> 8;
#else
    FONT_DESC *font_desc = GetFontDesc;
    disp_obj->font_size = font_desc[disp_obj->cur_pos].id;
    disp_obj->font_height = GetImageHeight(' ');
#endif
    DispObject_InvalidateRect(disp_obj, NULL);
  }
}

void SelectFont_OnLayout(DISP_OBJ_FONT_SEL *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, DARK_BACKGROUND_COLOR);
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
#if defined(DB3200) || defined(DB3210)
  disp_obj->cur_pos = FONT_HEIGHT(font_size) - 1;
  int style_flags = font_size >> 8;
  disp_obj->style_bold = style_flags & bold;
  disp_obj->style_italic = (style_flags & italic) >> 1;
  disp_obj->font_height = (disp_obj->cur_pos + 1);
  disp_obj->font_size = disp_obj->font_height + (disp_obj->style_bold << 8) + (disp_obj->style_italic << 9);
  disp_obj->font_style = disp_obj->font_size >> 8;
#else
  disp_obj->cur_pos = GetIdByFontId(font_size);
#endif
}

int GUIObject_Font_GetSize(GUI *gui_fontsel)
{
  DISP_OBJ_FONT_SEL *disp_obj = (DISP_OBJ_FONT_SEL *)GUIObject_GetDispObject(gui_fontsel);
#if defined(DB3200) || defined(DB3210)
  return disp_obj->font_size;
#else
  FONT_DESC *font = GetFontDesc;
  return font[disp_obj->cur_pos].id;
#endif
}

#if defined(DB3200) || defined(DB3210)
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
