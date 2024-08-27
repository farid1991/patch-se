#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"

#include "dll.h"
#include "draw.h"
#include "edit_color.h"
#include "LNG.h"
#include "main.h"

//==============================================================================

TEXTID GetText(const wchar_t* mask, int value)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), mask, value, value);
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

int EditColor_OnCreate(DISP_OBJ_COLOR *disp_obj)
{
  disp_obj->t_textid = STR("Test String");
  disp_obj->r = clEmpty;
  disp_obj->g = clEmpty;
  disp_obj->b = clEmpty;
  disp_obj->a = clEmpty;
  disp_obj->text_color = clEmpty;
  disp_obj->current_row = 0;
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
  disp_obj->r_textid = GetText(L"RED: %d (%02X)", disp_obj->r);
  Draw_SliderItem(disp_obj->r, MAX_COLOR,
                  40, 40,
                  disp_obj->r_textid,
                  (disp_obj->current_row == ROW_1) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_1) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clRed);

  disp_obj->g_textid = GetText(L"GREEN: %d (%02X)", disp_obj->g);
  Draw_SliderItem(disp_obj->g, MAX_COLOR,
                  80, 40,
                  disp_obj->g_textid,
                  (disp_obj->current_row == ROW_2) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_2) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clGreen);

  disp_obj->b_textid = GetText(L"BLUE: %d (%02X)", disp_obj->b);
  Draw_SliderItem(disp_obj->b, MAX_COLOR,
                  120, 40,
                  disp_obj->b_textid,
                  (disp_obj->current_row == ROW_3) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_3) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clBlue);

  disp_obj->a_textid = GetText(L"ALPHA: %d (%02X)", disp_obj->a);
  Draw_SliderItem(disp_obj->a, MAX_COLOR,
                  160, 40,
                  disp_obj->a_textid,
                  (disp_obj->current_row == ROW_4) ? clAlpha : clBlueMidDark,
                  (disp_obj->current_row == ROW_4) ? clBlueMidDark : clAlpha,
                  clCyan,
                  clOrangeMidDark);

  DrawString_onRect(FONT_E_30R,
                    disp_obj->t_textid,
                    disp_obj->text_color,
                    0, 200, 240, 66,
                    clAlpha);
}

void EditColor_OnKey(DISP_OBJ_COLOR *disp_obj, int key, int count, int repeat, int mode)
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
    disp_obj->text_color = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
    DispObject_InvalidateRect(disp_obj, NULL);
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
  if (!GUIObject_Create(gui_color, EditColor_destruct, EditColor_construct, book, NULL, UIDisplay_Main, sizeof(GUI_COLOR)))
  {
    mfree(gui_color);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gui_color);

  GUIObject_EditColor_SetColor(gui_color, color);
  GUIObject_SetTitleText(gui_color, STR("Color"));
  GUIObject_SetTitleType(gui_color, UI_TitleMode_Small);

  return gui_color;
}
