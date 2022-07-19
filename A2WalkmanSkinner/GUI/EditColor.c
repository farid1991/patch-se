#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\Color.h"

#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\Function.h"
#include "..\\SaveLoad.h"

#include "EditColor.h"

//==============================================================================

void DisplayText(DISP_OBJ_COLOR *disp_obj)
{
  wchar_t ustr[32];

  snwprintf(ustr, MAXELEMS(ustr), L"RED: %d (%02X)", disp_obj->r, disp_obj->r);
  disp_obj->r_textid = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);

  snwprintf(ustr, MAXELEMS(ustr), L"GREEN: %d (%02X)", disp_obj->g, disp_obj->g);
  disp_obj->g_textid = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);

  snwprintf(ustr, MAXELEMS(ustr), L"BLUE: %d (%02X)", disp_obj->b, disp_obj->b);
  disp_obj->b_textid = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);

  snwprintf(ustr, MAXELEMS(ustr), L"ALPHA: %d (%02X)", disp_obj->a, disp_obj->a);
  disp_obj->a_textid = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

int EditColor_OnCreate(DISP_OBJ_COLOR *disp_obj)
{
  disp_obj->t_textid = STR("Sample Text");
  disp_obj->r_textid = EMPTY_TEXTID;
  disp_obj->g_textid = EMPTY_TEXTID;
  disp_obj->b_textid = EMPTY_TEXTID;
  disp_obj->a_textid = EMPTY_TEXTID;

  disp_obj->r = clEmpty;
  disp_obj->g = clEmpty;
  disp_obj->b = clEmpty;
  disp_obj->a = clEmpty;
  disp_obj->text_color = clEmpty;

  disp_obj->current_row = 0;

  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main);

  return 1;
}

void EditColor_OnClose(DISP_OBJ_COLOR *disp_obj)
{
  DESTROY_TEXTID(disp_obj->t_textid);
  DESTROY_TEXTID(disp_obj->r_textid);
  DESTROY_TEXTID(disp_obj->g_textid);
  DESTROY_TEXTID(disp_obj->b_textid);
  DESTROY_TEXTID(disp_obj->a_textid);
}

void EditColor_OnRedraw(DISP_OBJ_COLOR *disp_obj, int, int, int)
{
  DisplayText(disp_obj);

  Draw_SliderItem(disp_obj->r, MAX_COLOR,
                  42, 42,
                  disp_obj->r_textid,
                  (disp_obj->current_row == ROW_1) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_1) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clTheta);

  Draw_SliderItem(disp_obj->g, MAX_COLOR,
                  84, 42,
                  disp_obj->g_textid,
                  (disp_obj->current_row == ROW_2) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_2) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clTheta);

  Draw_SliderItem(disp_obj->b, MAX_COLOR,
                  126, 42,
                  disp_obj->b_textid,
                  (disp_obj->current_row == ROW_3) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_3) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clTheta);

  Draw_SliderItem(disp_obj->a, MAX_COLOR,
                  168, 42,
                  disp_obj->a_textid,
                  (disp_obj->current_row == ROW_4) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_4) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clTheta);

  disp_obj->text_color = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);

  DrawString_onRect(FONT_E_24R,
                    disp_obj->t_textid,
                    disp_obj->text_color,
                    0, 210, disp_obj->disp_width, 66,
                    clAlpha);
}

void EditColor_OnKey(DISP_OBJ_COLOR *disp_obj, int key, int, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (key == KEY_UP || key == KEY_DIGITAL_2)
    {
      if ((--disp_obj->current_row) < ROW_1)
        disp_obj->current_row = ROW_4;
    }
    else if (key == KEY_DOWN || key == KEY_DIGITAL_8)
    {
      if (++disp_obj->current_row > ROW_4)
        disp_obj->current_row = ROW_1;
    }
    else if (key == KEY_LEFT || key == KEY_DIGITAL_4)
    {
      switch (disp_obj->current_row)
      {
      case ROW_1:
        if ((--disp_obj->r) < 0)
          disp_obj->r = 255;
        break;
      case ROW_2:
        if ((--disp_obj->g) < 0)
          disp_obj->g = 255;
        break;
      case ROW_3:
        if ((--disp_obj->b) < 0)
          disp_obj->b = 255;
        break;
      case ROW_4:
        if ((--disp_obj->a) < 0)
          disp_obj->a = 255;
        break;
      }
    }
    else if (key == KEY_RIGHT || key == KEY_DIGITAL_6)
    {
      switch (disp_obj->current_row)
      {
      case ROW_1:
        if (++disp_obj->r > 255)
          disp_obj->r = 0;
        break;
      case ROW_2:
        if (++disp_obj->g > 255)
          disp_obj->g = 0;
        break;
      case ROW_3:
        if (++disp_obj->b > 255)
          disp_obj->b = 0;
        break;
      case ROW_4:
        if (++disp_obj->a > 255)
          disp_obj->a = 0;
        break;
      }
    }
    else if (key == KEY_DEL)
    {
      switch (disp_obj->current_row)
      {
      case ROW_1:
        disp_obj->r = 0;
        break;
      case ROW_2:
        disp_obj->g = 0;
        break;
      case ROW_3:
        disp_obj->b = 0;
        break;
      case ROW_4:
        disp_obj->a = 0;
        break;
      }
    }
    InvalidateRect(disp_obj);
  }
}

void EditColor_OnLayout(DISP_OBJ_COLOR *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clWhite);
}

void EditColor_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_EditColor);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_COLOR));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)EditColor_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)EditColor_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)EditColor_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)EditColor_OnKey);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)EditColor_OnLayout);
}

void EditColor_destruct(GUI *gui_color)
{
}

void EditColor_callback(DISP_OBJ* disp, void* msg, GUI* gui)
{
}

void GUIObject_EditColor_SetColor(GUI *gui_color, int color)
{
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  disp_obj->r = COLOR_GET_R(color);
  disp_obj->g = COLOR_GET_G(color);
  disp_obj->b = COLOR_GET_B(color);
  disp_obj->a = COLOR_GET_A(color);
  disp_obj->text_color = color;
}

unsigned int GUIObject_EditColor_GetColor(GUI *gui_color)
{
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  return disp_obj->text_color;
}

int GUIObject_EditColor_GetRed(GUI *gui_color)
{
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  return disp_obj->r;
}

int GUIObject_EditColor_GetGreen(GUI *gui_color)
{
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  return disp_obj->g;
}

int GUIObject_EditColor_GetBlue(GUI *gui_color)
{
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  return disp_obj->b;
}

int GUIObject_EditColor_GetAlpha(GUI *gui_color)
{
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  return disp_obj->a;
}

GUI *Create_EditColor(BOOK *book, int color)
{
  GUI_COLOR *gui_color = (GUI_COLOR *)malloc(sizeof(GUI_COLOR));
  if (!GUIObject_Create(gui_color, EditColor_destruct, EditColor_construct, book, EditColor_callback, UIDisplay_Main, sizeof(GUI_COLOR)))
  {
    mfree(gui_color);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gui_color);

  GUIObject_EditColor_SetColor(gui_color, color);

  GUIObject_SetTitleText(gui_color, TEXT_COLOR);
  GUIObject_SetTitleType(gui_color, UI_TitleMode_Small);

  return (gui_color);
}
