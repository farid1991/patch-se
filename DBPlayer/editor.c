#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"

#ifndef DB3150v1
#include "dll.h"
#endif

#include "Lib.h"
#include "setting.h"
#include "data.h"
#include "draw.h"
#include "lang.h"
#include "editor.h"
#include "main.h"

void RefreshList(BOOK *book, int count)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;

  ListMenu_DestroyItems(setbook->sub_menu);
  ListMenu_SetItemCount(setbook->sub_menu, count);
  ListMenu_SetCursorToItem(setbook->sub_menu, ListMenu_GetSelectedItem(setbook->sub_menu));
  GUIObject_SoftKeys_SetVisible(setbook->sub_menu, ACTION_SELECT1, TRUE);
  setbook->changed = TRUE;
}

void SetActivate(BOOK *book, int count)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  DBP_DATA *data = GetData();
  int item = ListMenu_GetSelectedItem(setbook->sub_menu);

  TEXTID text = EMPTY_TEXTID;
  if (item == 0)
  {
    if (data->temp.activate1)
    {
      text = TEXT_OFF;
      data->temp.activate1 = FALSE;
    }
    else
    {
      text = TEXT_ON;
      data->temp.activate1 = TRUE;
    }
  }
  else if (item == 1)
  {
    if (data->temp.activate2)
    {
      text = TEXT_OFF;
      data->temp.activate2 = FALSE;
    }
    else
    {
      text = TEXT_ON;
      data->temp.activate2 = TRUE;
    }
  }
  else if (item == 2)
  {
    if (data->temp.activate3)
    {
      if (setbook->element == ITEM_TIME_PROGRESS)
        text = TextID_Global(ID_PTYPE_1);
      else if (setbook->element == ITEM_VOLUME_PROGRESS)
        text = TextID_Global(ID_PTYPE_1);
      else
        text = TEXT_OFF;
      data->temp.activate3 = FALSE;
    }
    else
    {
      if (setbook->element == ITEM_TIME_PROGRESS)
        text = TextID_Global(ID_PTYPE_2);
      else if (setbook->element == ITEM_VOLUME_PROGRESS)
        text = TextID_Global(ID_PTYPE_2);
      else
        text = TEXT_ON;
      data->temp.activate3 = TRUE;
    }
  }

  RefreshList(setbook, count);
  ListMenu_SetItemSecondLineText(setbook->sub_menu, item, text);
}

void ProgressBar_OnSelect(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();

  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  data->temp.activate1 = OneOfMany_GetSelected(setbook->options_menu);
  FREE_GUI(setbook->options_menu);

  RefreshList(setbook, SUBITEM_BG_LAST);
}

void Show_OnSelect(BOOK *book, GUI *gui)
{
  DBP_DATA *data = GetData();

  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  data->temp.activate1 = OneOfMany_GetSelected(setbook->options_menu);
  FREE_GUI(setbook->options_menu);

  RefreshList(setbook, SUBITEM_TXT_LAST);
}

void Align_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  DBP_DATA *data = GetData();
  data->temp.align = OneOfMany_GetSelected(setbook->options_menu);
  TEXTID text = EMPTY_TEXTID;
  if (data->temp.align == AlignLeft)
  {
    text = TextID_Global(ID_ALIGN_LEFT);
  }
  else if (data->temp.align == AlignRight)
  {
    text = TextID_Global(ID_ALIGN_RIGHT);
  }
  else if (data->temp.align == AlignCenter)
  {
    text = TextID_Global(ID_ALIGN_CENTER);
  }
  ListMenu_SetItemSecondLineText(setbook->sub_menu, 3, text);
  FREE_GUI(setbook->options_menu);
  setbook->changed = TRUE;
}

void OneOfMany_OnBack(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  FREE_GUI(setbook->options_menu);
}

void OneOfMany_SetMode(BOOK *book, int type)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  DBP_DATA *data = GetData();
  if (setbook->options_menu = CreateOneOfMany(setbook))
  {
    if (type == 0)
    {
      GUIObject_SetTitleText(setbook->options_menu, TEXT_MODE);

      TEXTID strid[3];
      strid[0] = TextID_Global(ID_BACKGROUND_IMAGE);
      strid[1] = TextID_Global(ID_BACKGROUND_THEME);
      strid[2] = TextID_Global(ID_BACKGROUND_COLOR);
      OneOfMany_SetTexts(setbook->options_menu, strid, 3);
      OneOfMany_SetChecked(setbook->options_menu, data->temp.activate1);
      GUIObject_SoftKeys_SetAction(setbook->options_menu, ACTION_SELECT1, ProgressBar_OnSelect);
    }
    else if (type == 1)
    {
      GUIObject_SetTitleText(setbook->options_menu, TextID_Global(ID_ALIGN));

      TEXTID strid[3];
      strid[0] = TextID_Global(ID_ALIGN_LEFT);
      strid[1] = TextID_Global(ID_ALIGN_RIGHT);
      strid[2] = TextID_Global(ID_ALIGN_CENTER);
      OneOfMany_SetTexts(setbook->options_menu, strid, 3);
      OneOfMany_SetChecked(setbook->options_menu, data->temp.align);
      GUIObject_SoftKeys_SetAction(setbook->options_menu, ACTION_SELECT1, Align_OnSelect);
    }
    else if (type == 2)
    {
      GUIObject_SetTitleText(setbook->options_menu, TextID_Global(ID_STATE));

      TEXTID strid[2];
      strid[0] = TEXT_OFF_OOM;
      strid[1] = TEXT_ON_OOM;
      OneOfMany_SetTexts(setbook->options_menu, strid, 2);
      OneOfMany_SetChecked(setbook->options_menu, data->temp.activate1);
      GUIObject_SoftKeys_SetAction(setbook->options_menu, ACTION_SELECT1, Show_OnSelect);
    }

    GUIObject_SoftKeys_SetAction(setbook->options_menu, ACTION_BACK, OneOfMany_OnBack);
    GUIObject_Show(setbook->options_menu);
  }
}

////////////////////////////////////////////////////////////////////////////////

int Color_OnCreate(DISP_OBJ_COLOR *disp_obj)
{
  disp_obj->buf_text = EMPTY_TEXTID;
  disp_obj->need_str = 1;
  disp_obj->current_column = 0;
  disp_obj->cstep = 1;
  return 1;
}

void Color_OnClose(DISP_OBJ_COLOR *disp_obj)
{
  TEXTFREE(disp_obj->buf_text);
}

void Color_OnRedraw(DISP_OBJ_COLOR *disp_obj, int, int, int)
{
  RECT rc_old;
  int gc_xx;
  int f_size = 20;
  GC *gc = get_DisplayGC();
  int column_height, column_width;
  int start_column, y_line;
  wchar_t ustr[32];
  int scr_w, scr_h, x1, y1;

  int colors[4] = {clRed, clGreen, clBlue, 0x80C6AAAF};

  GC_GetRect(gc, &rc_old);
  gc_xx = GC_GetXX(gc);
  GC_SetXX(gc, 1);
  x1 = rc_old.x1;
  y1 = rc_old.y1;
  scr_w = rc_old.x2 - x1;
  scr_h = rc_old.y2 - y1;

  column_height = scr_h - (f_size << 1);
  column_width = scr_w >> 3;
  DrawRect(x1, y1, x1 + scr_w, y1 + scr_h, clWhite, clWhite);

  if (disp_obj->need_str)
  {
    snwprintf(ustr, MAXELEMS(ustr) - 1, L"%02X, %02X, %02X, %02X", disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
    TextID_Destroy(disp_obj->buf_text);
    disp_obj->buf_text = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
    disp_obj->need_str = 0;
  }
  DrawTextEx(FONT_E_20R,
             disp_obj->buf_text,
             AlignCenter,
             x1 + 1,
             y1 + 1,
             x1 + scr_w - 1,
             y1 + 1 + f_size + 1,
             clBlack);

  f_size += 3;

  for (int i = 0; i != 4; i++)
  {
    start_column = column_width + 2 * i * column_width + 4;
    column_height++; // Какая то фигня с DrawRect, координаты не совпадают с DrawLine. Оно и понятно, DrawRect не GC_.
    if (disp_obj->current_column == i)
      DrawRect(x1 + start_column - 2, y1 + f_size - 2 + 50, x1 + start_column + column_width + 2, y1 + f_size + column_height + 2, clBlack, clWhite); // Столбик
    DrawRect(x1 + start_column, y1 + f_size + 50, x1 + start_column + column_width, y1 + f_size + column_height, clBlack, colors[i]);                 // Рамка
    column_height--;

    switch (i)
    {
    case 0:
      y_line = f_size + column_height - (disp_obj->r * (column_height - 50)) / 0xFF;
      break;
    case 1:
      y_line = f_size + column_height - (disp_obj->g * (column_height - 50)) / 0xFF;
      break;
    case 2:
      y_line = f_size + column_height - (disp_obj->b * (column_height - 50)) / 0xFF;
      break;
    case 3:
      y_line = f_size + column_height - (disp_obj->a * (column_height - 50)) / 0xFF;
      break;
    }

    int old_pen = GC_GetPenColor(gc);
    GC_SetPenColor(gc, clBlack);
    GC_DrawLine(gc, x1 + start_column, y1 + y_line, x1 + start_column + column_width - 1, y1 + y_line);
    GC_SetPenColor(gc, old_pen);
  }

  int testcolor = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  DrawRect(x1 + 20, y1 + 1 + 30, x1 + scr_w - 20, y1 + f_size + 30, clBlack, testcolor);
  GC_SetXX(gc, gc_xx);
}

void Color_OnKey(DISP_OBJ_COLOR *disp_obj, int key, int, int repeat, int mode)
{
  if (mode != KBD_SHORT_RELEASE && mode != KBD_REPEAT)
  {
    if (mode == KBD_LONG_RELEASE)
      disp_obj->cstep = 1;
    return;
  }

  if (mode == KBD_SHORT_RELEASE)
    disp_obj->cstep = 1;
  else if (repeat > 10)
    disp_obj->cstep = 8;

  switch (key)
  {
  case KEY_UP:
  case KEY_DIGITAL_2:
    switch (disp_obj->current_column)
    {
    case 0:
      disp_obj->r = (disp_obj->r + disp_obj->cstep) & 0xFF;
      break;
    case 1:
      disp_obj->g = (disp_obj->g + disp_obj->cstep) & 0xFF;
      break;
    case 2:
      disp_obj->b = (disp_obj->b + disp_obj->cstep) & 0xFF;
      break;
    case 3:
      disp_obj->a = (disp_obj->a + disp_obj->cstep) & 0xFF;
      break;
    }
    break;

  case KEY_DOWN:
  case KEY_DIGITAL_8:
    switch (disp_obj->current_column)
    {
    case 0:
      disp_obj->r = (disp_obj->r - disp_obj->cstep) & 0xFF;
      break;
    case 1:
      disp_obj->g = (disp_obj->g - disp_obj->cstep) & 0xFF;
      break;
    case 2:
      disp_obj->b = (disp_obj->b - disp_obj->cstep) & 0xFF;
      break;
    case 3:
      disp_obj->a = (disp_obj->a - disp_obj->cstep) & 0xFF;
      break;
    }
    break;

  case KEY_LEFT:
  case KEY_DIGITAL_4:
    disp_obj->current_column = (disp_obj->current_column - 1 + 4) % 4;
    break;

  case KEY_RIGHT:
  case KEY_DIGITAL_6:
    disp_obj->current_column = (disp_obj->current_column + 1) % 4;
    break;

  case KEY_DEL:
    switch (disp_obj->current_column)
    {
    case 0:
      disp_obj->r = 0;
      break;
    case 1:
      disp_obj->g = 0;
      break;
    case 2:
      disp_obj->b = 0;
      break;
    case 3:
      disp_obj->a = 0;
      break;
    }
    break;
  }

  disp_obj->need_str = 1;

  DispObject_InvalidateRect(disp_obj, NULL);
}

void Color_create(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, GuiName_Color);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_COLOR));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Color_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Color_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Color_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Color_OnKey);
}

void Color_destroy(GUI *gui)
{
}

void Color_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(setbook->color_picker);

  uint32_t color;
  int item;

  DBP_DATA *data = GetData();
  if ((disp_obj->type == 0) || (disp_obj->type == 1))
  {
    if (setbook->element == ITEM_TIME_PROGRESS)
      item = 3;
    else if (setbook->element == ITEM_VOLUME_PROGRESS)
      item = 4;
    else
      item = 1;
    color = data->temp.color1 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  else
  {
    if (setbook->element == ITEM_TIME_PROGRESS)
      item = 4;
    else if (setbook->element == ITEM_VOLUME_PROGRESS)
      item = 4;
    else
      item = 2;
    color = data->temp.color2 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }

  snwprintf(data->buf, MAXELEMS(data->buf), L"%02X, %02X, %02X, %02X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
  ListMenu_SetItemSecondLineText(setbook->sub_menu, item, TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN));
  FREE_GUI(setbook->color_picker);
  setbook->changed = TRUE;
}

void Color_OnBack(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  FREE_GUI(setbook->color_picker);
}

void Color_CallBack(DISP_OBJ *, void *msg, GUI *)
{
}

void SetColor(BOOK *book, int type)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  GUI *gui_color = (GUI *)malloc(sizeof(GUI));
  if (!GUIObject_Create(gui_color, Color_destroy, Color_create, setbook, Color_CallBack, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(gui_color);
    return;
  }

  DBP_DATA *data = GetData();
  DISP_OBJ_COLOR *disp_obj = (DISP_OBJ_COLOR *)GUIObject_GetDispObject(gui_color);
  disp_obj->type = type;

  setbook->color_picker = gui_color;

  if ((type == 0) || (type == 1))
  {
    uint32_t color = data->temp.color1;
    disp_obj->r = COLOR_GET_R(color);
    disp_obj->g = COLOR_GET_G(color);
    disp_obj->b = COLOR_GET_B(color);
    disp_obj->a = COLOR_GET_A(color);
  }
  else
  {
    uint32_t color = data->temp.color2;
    disp_obj->r = COLOR_GET_R(color);
    disp_obj->g = COLOR_GET_G(color);
    disp_obj->b = COLOR_GET_B(color);
    disp_obj->a = COLOR_GET_A(color);
  }

  if (setbook)
    BookObj_AddGUIObject(setbook, setbook->color_picker);

  GUIObject_SetTitleText(setbook->color_picker, TEXT_COLOR);
  GUIObject_SetTitleType(setbook->color_picker, UI_TitleMode_Small);
  GUIObject_SoftKeys_SetAction(setbook->color_picker, ACTION_SELECT1, Color_OnSelect);
  GUIObject_SoftKeys_SetText(setbook->color_picker, ACTION_SELECT1, TextID_Create("OK", ENC_LAT1, 2));
  GUIObject_SoftKeys_SetAction(setbook->color_picker, ACTION_BACK, Color_OnBack);
  GUIObject_Show(setbook->color_picker);
}

////////////////////////////////////////////////////////////////////////////////

void SetActiveSoftkeys(BOOL mode)
{
  DBP_DATA *data = GetData();

  if (!data->paused)
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PAUSE, mode);
  else
    GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PLAY, mode);

  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_STOP, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_SETTINGS, mode);
#ifndef DB3350
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_TAG, mode);
#endif
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_TIME, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_MINIMISE, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_LONG_BACK, mode);
#ifndef DB3350
  if (data->setting.screen)
    GUIObject_SoftKeys_RemoveBackground(data->gui);
  else
    GUIObject_SoftKeys_RestoreBackground(data->gui);
#endif
  if (data->setting.soft)
  {
    if (mode)
      GUIObject_SoftKeys_Show(data->gui);
    else
      GUIObject_SoftKeys_Hide(data->gui);
  }
}

wchar_t *Font_GetNameByFontId(int font_size)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  wchar_t *font_name = (wchar_t *)malloc(16 * sizeof(wchar_t)); // Allocate memory

  // Handle memory allocation error
  if (font_name == NULL)
    return NULL;

  switch (font_size >> 8)
  {
  case UIFontStylePlain:
    snwprintf(font_name, 16, L"%d_R", font_size);
    break;
  case UIFontStyleBold:
    snwprintf(font_name, 16, L"%d_B", FONTHEIGHT(font_size));
    break;
  case UIFontStyleItalic:
    snwprintf(font_name, 16, L"%d_I", FONTHEIGHT(font_size));
    break;
  case UIFontStyleBoldItalic:
    snwprintf(font_name, 16, L"%d_B_I", FONTHEIGHT(font_size));
    break;
  }
  return font_name;
}
#else
  wchar_t *font_name = L"Undefined";
  FONT_DESC *font_desc = PGetFontDesc;
  int total_font = *PGetFontCount;

  for (int i = 0; i < total_font; i++)
  {
    if (font_size == font_desc[i].id)
    {
      font_name = font_desc[i].name;
      break;
    }
  }
  return font_name;
}
int GetIdByFontId(int id)
{
  int ret = 0;
  FONT_DESC *font_desc = PGetFontDesc;
  int total_font = *PGetFontCount;

  for (int i = 0; i < total_font; i++)
  {
    if (id == font_desc[i].id)
    {
      ret = i;
      break;
    }
  }
  return ret;
}
#endif

void SetVisual(BOOK *book)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  DBP_DATA *data = GetData();
  data->edit_visual = TRUE;
  data->element = setbook->element;

  data->pIMMEPlayer->Pause();
  data->paused = TRUE;
  int type = setbook->elem_type;

  if (type == ELEM_TEXT)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    data->total_fonts = max_size;
    data->cur_pos = FONTHEIGHT(data->temp.font) - 1;
    int style_flags = data->temp.font >> 8;
    data->style_bold = style_flags & bold;
    data->style_italic = (style_flags & italic) >> 1;
#else
    data->total_fonts = *PGetFontCount;
    data->cur_pos = GetIdByFontId(data->temp.font);
#endif
    data->edit_text_mode = TRUE;
    data->edit_rect_mode = FALSE;
    data->edit_image_mode = FALSE;
  }
  else if (type == ELEM_RECT)
  {
    data->edit_text_mode = FALSE;
    data->edit_rect_mode = TRUE;
    data->edit_image_mode = FALSE;
  }
  else if (type == ELEM_ICON)
  {
    data->edit_text_mode = FALSE;
    data->edit_rect_mode = FALSE;
    data->edit_image_mode = TRUE;
  }

  FreeBook(setbook);
  SetActiveSoftkeys(FALSE);
}
