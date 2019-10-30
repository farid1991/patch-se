/*
;Fm Radio Layout Editor
;- Ability to hide/show all items.
;- Ability to change coordinates of each item in realtime.
;- Ability to choose Text color, font, etc.
;- Ability to use color or Theme Image on the background.
;v. 1.2
;(c) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\FmRadio_Book.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "main.h"
#include "data.h"
#include "setting.h"
#include "lang.h"
#include "editor.h"
#include "Function.h"


void RefreshList(SETTING_BOOK* set_book, int count)
{
  int pos = ListMenu_GetSelectedItem(set_book->gui_elem);
  ListMenu_DestroyItems(set_book->gui_elem);
  ListMenu_SetItemCount(set_book->gui_elem, count);
  ListMenu_SetCursorToItem(set_book->gui_elem, pos);
  GUIObject_SoftKeys_SetVisible(set_book->gui_elem, ACTION_SELECT1, TRUE);
  set_book->change = TRUE;
}

void SetActivate(SETTING_BOOK* set_book, int count)
{
  FmRadio_Data* data = GetData();
  int item = ListMenu_GetSelectedItem(set_book->gui_elem);
  
  TEXTID text = EMPTY_TEXTID;
  if (item == 0)
  {
    if(data->temp.activate1)
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
    if(data->temp.activate2)
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
    if(data->temp.activate3)
    {
      if (set_book->element == ITEM_FREQ_INDICATOR) text = TextID_Global(ID_PTYPE_1);
      else text = TEXT_OFF;
      data->temp.activate3 = FALSE;
    }
    else
    {
      if (set_book->element == ITEM_FREQ_INDICATOR) text = TextID_Global(ID_PTYPE_2);
      else text = TEXT_ON;
      data->temp.activate3 = TRUE;
    }
  }
  RefreshList(set_book,count);
  ListMenu_SetItemSecondLineText(set_book->gui_elem, item, text);
  set_book->change = TRUE;
}

////////////////////////////////////////////////////////////////////////////////

void BackgroundType_OnSelect(BOOK* book, GUI* gui)
{
  FmRadio_Data* data = GetData();
  
  SETTING_BOOK* set_book = (SETTING_BOOK*)book;
  data->temp.activate1 = OneOfMany_GetSelected(set_book->gui_oom);
  FREE_GUI(set_book->gui_oom);
  
  RefreshList(set_book, BACKGROUND_COUNT);
}

void Show_OnSelect(BOOK* book, GUI* gui)
{
  FmRadio_Data* data = GetData();
  
  SETTING_BOOK* set_book = (SETTING_BOOK*)book;
  data->temp.activate1 = OneOfMany_GetSelected(set_book->gui_oom);
  FREE_GUI(set_book->gui_oom);
  
  RefreshList(set_book, TEXT_COUNT);
}

void Align_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* set_book = (SETTING_BOOK*)book;
  FmRadio_Data* data = GetData();
  data->temp.align = OneOfMany_GetSelected(set_book->gui_oom);
  TEXTID text = EMPTY_TEXTID;
  if (data->temp.align == 0) text = TEXT_LEFT;
  else if (data->temp.align == 1) text = TEXT_RIGHT;
  else if (data->temp.align == 2) text = TEXT_CENTRE;
  ListMenu_SetItemSecondLineText(set_book->gui_elem, 3, text);
  FREE_GUI(set_book->gui_oom);
  
  set_book->change = TRUE;
}

void OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* set_book = (SETTING_BOOK*)book;
  FREE_GUI(set_book->gui_oom);
}

void OneOfMany_SetMode(SETTING_BOOK* set_book, int type)
{
  FmRadio_Data* data = GetData();
  set_book->gui_oom = CreateOneOfMany(set_book);
  
  if (type == 0)
  {
    GUIObject_SetTitleText(set_book->gui_oom, TEXT_MODE);
    
    TEXTID texts[3];
    texts[0] = TEXT_IMAGE;
    texts[1] = TEXT_THEME;
    texts[2] = TEXT_COLOR;
    OneOfMany_SetTexts(set_book->gui_oom, texts, 3);
    OneOfMany_SetChecked(set_book->gui_oom, data->temp.activate1);
    GUIObject_SoftKeys_SetAction(set_book->gui_oom, ACTION_SELECT1, BackgroundType_OnSelect);
  }
  else if (type == 1)
  {
    GUIObject_SetTitleText(set_book->gui_oom, TextID_Global(ID_ALIGN));
    
    TEXTID texts[3];
    texts[0] = TEXT_LEFT;
    texts[1] = TEXT_RIGHT;
    texts[2] = TEXT_CENTRE;
    OneOfMany_SetTexts(set_book->gui_oom, texts, 3);
    OneOfMany_SetChecked(set_book->gui_oom, data->temp.align);
    GUIObject_SoftKeys_SetAction(set_book->gui_oom, ACTION_SELECT1, Align_OnSelect);
  }
  else if (type == 2)
  {
    GUIObject_SetTitleText(set_book->gui_oom, TextID_Global(ID_SHOW));
    
    TEXTID texts[2];
    texts[0] = TEXT_OFF_OOM;
    texts[1] = TEXT_ON_OOM;
    OneOfMany_SetTexts(set_book->gui_oom, texts, 2);
    OneOfMany_SetChecked(set_book->gui_oom, data->temp.activate1);
    GUIObject_SoftKeys_SetAction(set_book->gui_oom, ACTION_SELECT1, Show_OnSelect);
  }
  
  GUIObject_SoftKeys_SetAction(set_book->gui_oom, ACTION_BACK, OnBack);
  GUIObject_Show(set_book->gui_oom);
}

////////////////////////////////////////////////////////////////////////////////

int Color_OnCreate(DISP_OBJ_COLOR* disp_obj)
{
  disp_obj->buf_text = EMPTY_TEXTID;
  disp_obj->need_str = 1;
  disp_obj->current_column = 0;
  disp_obj->cstep = 1;
  return 1;
}

void Color_OnClose(DISP_OBJ_COLOR* disp_obj)
{
  TEXT_FREE( disp_obj->buf_text );
}

void Color_OnRedraw(DISP_OBJ_COLOR* disp_obj, int, int, int)
{
  RECT rc_old;
  int gc_xx;
  int fsize = 20;
  GC* pGC = get_DisplayGC();
  int column_height, column_width;
  int start_column, y_line;
  wchar_t ustr[32];
  int scr_w, scr_h, x1, y1;
  
  int colors[4] =
  {
    clRed,
    clGreen,
    clBlue,
    0x80C6AAAF
  };
  
  GC_GetRect(pGC, &rc_old);
  gc_xx = GC_GetXX(pGC);
  GC_SetXX(pGC, 1);
  x1 = rc_old.x1;
  y1 = rc_old.y1;
  scr_w = rc_old.x2 - x1;
  scr_h = rc_old.y2 - y1;
  
  column_height = scr_h - fsize - fsize;
  column_width = scr_w / 9;
  DrawRect(x1, y1, x1 + scr_w, y1 + scr_h, clWhite, clWhite);
  
  if (disp_obj->need_str)
  {
    snwprintf(ustr, MAXELEMS(ustr) - 1, L"%02X, %02X, %02X, %02X", disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
    TextID_Destroy(disp_obj->buf_text);
    disp_obj->buf_text = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
    disp_obj->need_str = 0;
  }

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString(disp_obj->buf_text,
                 FONT_E_20R,
                 UITextAlignment_Center,
                 x1 + 1,
                 y1 + 1,
                 x1 + scr_w - 1,
                 y1 + 1 + fsize + 1,
                 clBlack);
#else
  SetFont(FONT_E_20R);
  DrawString(disp_obj->buf_text,
             UITextAlignment_Center,
             x1 + 1,
             y1 + 1,
             x1 + scr_w - 1,
             y1 + 1 + fsize + 1,
             0,0,
             clBlack,
             clEmpty);
#endif
  fsize += 3;
  
  for (int i = 0; i != 4; i++)
  {
    start_column = column_width + 2 * i * column_width + 4;
    column_height++;
    if (disp_obj->current_column == i) DrawRect(x1 + start_column - 2, y1 + fsize - 2 + 50, x1 + start_column + column_width + 2, y1 + fsize + column_height + 2, clBlack, clWhite); // Столбик
    DrawRect(x1 + start_column, y1 + fsize + 50, x1 + start_column + column_width, y1 + fsize + column_height, clBlack, colors[i]);
    column_height--;
    
    switch(i)
    {
    case 0: y_line = fsize + column_height - (disp_obj->r * (column_height - 50)) / 0xFF; break;
    case 1: y_line = fsize + column_height - (disp_obj->g * (column_height - 50)) / 0xFF; break;
    case 2: y_line = fsize + column_height - (disp_obj->b * (column_height - 50)) / 0xFF; break;
    case 3: y_line = fsize + column_height - (disp_obj->a * (column_height - 50)) / 0xFF; break;
    }
    
    int old_pen = GC_GetPenColor(pGC);
    GC_SetPenColor(pGC, clBlack);
    GC_DrawLine(pGC, x1 + start_column, y1 + y_line, x1 + start_column + column_width - 1, y1 + y_line);
    GC_SetPenColor(pGC, old_pen);
  }
  
  int testcolor = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  DrawRect(x1 + 20, y1 + 1 + 30, x1 + scr_w - 20, y1 + fsize + 30, clBlack, testcolor);
  GC_SetXX(pGC, gc_xx);
}

void Color_OnKey(DISP_OBJ_COLOR* disp_obj, int key, int, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (mode == KBD_SHORT_RELEASE) disp_obj->cstep = 1;
    else if (mode == KBD_REPEAT && repeat > 10) disp_obj->cstep = 8;
    
    if (key == KEY_UP || key == KEY_DIGITAL_0 + 2)
    {
      switch(disp_obj->current_column)
      {
      case 0: if ((disp_obj->r += disp_obj->cstep) > 0xFF) disp_obj->r = 0; break;
      case 1: if ((disp_obj->g += disp_obj->cstep) > 0xFF) disp_obj->g = 0; break;
      case 2: if ((disp_obj->b += disp_obj->cstep) > 0xFF) disp_obj->b = 0; break;
      case 3: if ((disp_obj->a += disp_obj->cstep) > 0xFF) disp_obj->a = 0; break;
      }
      disp_obj->need_str = 1;
    }
    else if (key == KEY_DOWN || key == KEY_DIGITAL_0 + 8)
    {
      switch(disp_obj->current_column)
      {
      case 0: if ((disp_obj->r -= disp_obj->cstep) < 0) disp_obj->r = 0xFF; break;
      case 1: if ((disp_obj->g -= disp_obj->cstep) < 0) disp_obj->g = 0xFF; break;
      case 2: if ((disp_obj->b -= disp_obj->cstep) < 0) disp_obj->b = 0xFF; break;
      case 3: if ((disp_obj->a -= disp_obj->cstep) < 0) disp_obj->a = 0xFF; break;
      }
      disp_obj->need_str = 1;
    }
    else if (key == KEY_LEFT || key == KEY_DIGITAL_0 + 4)
    {
      if (--disp_obj->current_column < 0) disp_obj->current_column = 3;
    }
    else if (key == KEY_RIGHT || key == KEY_DIGITAL_0 + 6)
    {
      if (++disp_obj->current_column > 3) disp_obj->current_column = 0;
    }
    else if (key == KEY_DEL)
    {
      switch(disp_obj->current_column)
      {
      case 0: disp_obj->r = 0; break;
      case 1: disp_obj->g = 0; break;
      case 2: disp_obj->b = 0; break;
      case 3: disp_obj->a = 0; break;
      }
      disp_obj->need_str = 1;
    }
  }
  
  if (mode == KBD_LONG_RELEASE) disp_obj->cstep = 1;
  DispObject_InvalidateRect(disp_obj, NULL);
}

void Color_create(DISP_DESC* desc)
{
  DISP_DESC_SetName(desc, GuiName_Color);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_COLOR));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD) Color_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD) Color_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD) Color_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD) Color_OnKey);
}

void Color_destroy(GUI* gui)
{
}

void Color_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* set_book = (SETTING_BOOK*)book;
  FmRadio_Data* data = GetData();
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*)GUIObject_GetDispObject(set_book->gui_color);
  
  color_t color;
  int item;
  
  if ((disp_obj->type == 0) || (disp_obj->type == 1))
  {
    if (set_book->element == ITEM_FREQ_INDICATOR) item = 3;
    else item = 1;
    color = data->temp.color1 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  else
  {
    if (set_book->element == ITEM_FREQ_INDICATOR ) item = 4;
    else item = 2;
    color = data->temp.color2 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  
  snwprintf(data->buf, MAXELEMS(data->buf), L"%02X, %02X, %02X, %02X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
  ListMenu_SetItemSecondLineText(set_book->gui_elem, item, TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN));
  FREE_GUI(set_book->gui_color);
  set_book->change = TRUE;
}

void Color_onBack( BOOK* book, GUI* )
{
  SETTING_BOOK* set_book = (SETTING_BOOK*)book;
  FREE_GUI(set_book->gui_color);
}

void SetColor(SETTING_BOOK* set_book, int type)
{
  GUI* gui_color = (GUI*)malloc(sizeof(GUI));
  if(!GUIObject_Create(gui_color, Color_destroy, Color_create, set_book, NULL, UIDisplay_Main, NULL)) mfree(gui_color);
  
  set_book->gui_color = gui_color;
  
  FmRadio_Data* data = GetData();
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*)GUIObject_GetDispObject(set_book->gui_color);
  disp_obj->type = type;
  
  if ((type == 0) || (type == 1))
  {
    color_t color = data->temp.color1;
    disp_obj->r = COLOR_GET_R(color);
    disp_obj->g = COLOR_GET_G(color);
    disp_obj->b = COLOR_GET_B(color);
    disp_obj->a = COLOR_GET_A(color);
  }
  else
  {
    color_t color = data->temp.color2;
    disp_obj->r = COLOR_GET_R(color);
    disp_obj->g = COLOR_GET_G(color);
    disp_obj->b = COLOR_GET_B(color);
    disp_obj->a = COLOR_GET_A(color);
  }
  
  if (set_book) BookObj_AddGUIObject(set_book, gui_color);
  
  GUIObject_SetTitleText(set_book->gui_color, TEXT_COLOR);
  GUIObject_SetTitleType(set_book->gui_color, UI_TitleMode_Small);
  GUIObject_SoftKeys_SetAction(set_book->gui_color, ACTION_SELECT1, Color_OnSelect);
  GUIObject_SoftKeys_SetText(set_book->gui_color, ACTION_SELECT1, STR("OK"));
  GUIObject_SoftKeys_SetAction(set_book->gui_color, ACTION_BACK, Color_onBack);
  GUIObject_Show(set_book->gui_color);
  //set_book->color_type = type;
  //set_book->palette = CreatePalette( set_book, TEXT_COLOR, COLOR_LIST, 0x1C, 0, Color_onBack, Color_onBack, Color_OnSelect );
  //GUIObject_Show(set_book->palette);
}

////////////////////////////////////////////////////////////////////////////////

#if defined(DB3150v1) || defined(DB3150) || defined(DB2020)
wchar_t* Font_GetNameByFontId(int id)
{
  wchar_t* txt = L"Undefined";
  FONT_DESC* font = GETFONTDESC;
  for (int i = 0, max = *GETFONTCOUNT; i < max; i++)
  {
    if (id == font[i].id)
    {
      txt = font[i].name;
      break;
    }
  }
  return txt;
}

int GetIdByFontId( int id )
{
  int ret = NULL;
  FONT_DESC* font_desc = GetFontDesc();
  for (int i = 0, max = *GetFontCount(); i < max; i++)
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

void SetVisual(SETTING_BOOK* set_book)
{
  FmRadio_Data* data = GetData();
  data->edit_visual = TRUE;
  data->element = set_book->element;
  
  //if (set_book->element > ITEM_RDS_DATA)
  //{
  if ( set_book->element == ITEM_FREQ_INDICATOR ) 
  {
      data->rect = TRUE;
  }
  else
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    data->total_fonts = max_size / font_step;
    data->cur_pos = (data->temp.font&0xFF) / font_step - 1;
    int style_flags = data->temp.font >> 8;
    data->style_bold = style_flags&bold;
    data->style_italic = (style_flags&italic) >> 1;
#else
    data->total_fonts = *GetFontCount();
    data->cur_pos = GetIdByFontId(data->temp.font);
#endif
    data->text = TRUE;
  }
  
  FreeBook(set_book);
  
  FmRadio_Book* FMbook = (FmRadio_Book*)data->FmRadioBook;
  GUIObject_SoftKeys_SetVisible(FMbook->FmRadio_Gui,ACTION_BACK,FALSE);
  FmRadio_SetActiveSoftKeys(FMbook,FALSE);
}
