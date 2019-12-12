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


void RefreshList(SETTING_BOOK* FMSettings_Book, int count)
{
  int pos = ListMenu_GetSelectedItem(FMSettings_Book->SubMenu);
  ListMenu_DestroyItems(FMSettings_Book->SubMenu);
  ListMenu_SetItemCount(FMSettings_Book->SubMenu, count);
  ListMenu_SetCursorToItem(FMSettings_Book->SubMenu, pos);
  GUIObject_SoftKeys_SetVisible(FMSettings_Book->SubMenu, ACTION_SELECT1, TRUE);
  FMSettings_Book->changed = TRUE;
}

void SetActivate(BOOK* book, int count)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  
  FmRadio_Data* data = GetData();
  int item = ListMenu_GetSelectedItem(FMSettings_Book->SubMenu);
  
  TEXTID text = EMPTY_TEXTID;
  if (item == 0)
  {
    if(data->temp.state)
    {
      text = TEXT_OFF;
      data->temp.state = FALSE;
    }
    else
    {
      text = TEXT_ON;
      data->temp.state = TRUE;
    }
  }
  else if (item == 1)
  {
    if(data->temp.slider)
    {
      text = TEXT_OFF;
      data->temp.slider = FALSE;
    }
    else
    {
      text = TEXT_ON;
      data->temp.slider = TRUE;
    }
  }
  else if (item == 2)
  {
    if(data->temp.round)
    {
      if (FMSettings_Book->element == ITEM_FREQ_INDICATOR) text = TextID_Global(ID_PTYPE_1);
      else text = TEXT_OFF;
      data->temp.round = FALSE;
    }
    else
    {
      if (FMSettings_Book->element == ITEM_FREQ_INDICATOR) text = TextID_Global(ID_PTYPE_2);
      else text = TEXT_ON;
      data->temp.round = TRUE;
    }
  }
  RefreshList(FMSettings_Book,count);
  ListMenu_SetItemSecondLineText(FMSettings_Book->SubMenu, item, text);
  FMSettings_Book->changed = TRUE;
}

////////////////////////////////////////////////////////////////////////////////

void Show_OnSelect(BOOK* book, GUI* gui)
{
  FmRadio_Data* data = GetData();
  
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  data->temp.state = OneOfMany_GetSelected(FMSettings_Book->OptionMenu);
  FREE_GUI(FMSettings_Book->OptionMenu);
  
  RefreshList(FMSettings_Book, SUBITEM_TXT_LAST);
}

void Align_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FmRadio_Data* data = GetData();
  data->temp.align = OneOfMany_GetSelected(FMSettings_Book->OptionMenu);
  TEXTID text = EMPTY_TEXTID;
  
  if (data->temp.align == AlignLeft) 
  {
    text = TEXT_LEFT;
  }
  else if (data->temp.align == AlignRight) 
  {
    text = TEXT_RIGHT;
  }
  else if (data->temp.align == AlignCenter) 
  {
    text = TEXT_CENTRE;
  }
  ListMenu_SetItemSecondLineText(FMSettings_Book->SubMenu, SUBITEM_TXT_ALIGN, text);
  FREE_GUI(FMSettings_Book->OptionMenu);
  
  FMSettings_Book->changed = TRUE;
}

void OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FREE_GUI(FMSettings_Book->OptionMenu);
}

void OneOfMany_SetMode(BOOK* book, int type)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  
  FmRadio_Data* data = GetData();
  FMSettings_Book->OptionMenu = CreateOneOfMany(FMSettings_Book);

  if (type == OOM_STATE)
  {
    GUIObject_SetTitleText(FMSettings_Book->OptionMenu, TextID_Global(ID_SHOW));
    
    TEXTID texts[2];
    texts[0] = TEXT_OFF;
    texts[1] = TEXT_ON;
    OneOfMany_SetTexts(FMSettings_Book->OptionMenu, texts, MAXELEMS(texts));
    OneOfMany_SetChecked(FMSettings_Book->OptionMenu, data->temp.state);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->OptionMenu, ACTION_SELECT1, Show_OnSelect);
  }
  else if (type == OOM_ALIGN)
  {
    GUIObject_SetTitleText(FMSettings_Book->OptionMenu, TextID_Global(ID_ALIGN));
    
    TEXTID texts[3];
    texts[0] = TEXT_LEFT;
    texts[1] = TEXT_RIGHT;
    texts[2] = TEXT_CENTRE;
    OneOfMany_SetTexts(FMSettings_Book->OptionMenu, texts, MAXELEMS(texts));
    OneOfMany_SetChecked(FMSettings_Book->OptionMenu, data->temp.align);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->OptionMenu, ACTION_SELECT1, Align_OnSelect);
  }
  
  GUIObject_SoftKeys_SetAction(FMSettings_Book->OptionMenu, ACTION_BACK, OnBack);
  GUIObject_Show(FMSettings_Book->OptionMenu);
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
    snwprintf(ustr, 
              MAXELEMS(ustr), 
              L"%02X, %02X, %02X, %02X", 
              disp_obj->r, 
              disp_obj->g, 
              disp_obj->b, 
              disp_obj->a);
    TextID_Destroy(disp_obj->buf_text);
    disp_obj->buf_text = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
    disp_obj->need_str = 0;
  }

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString(FONT_E_20R,
                 disp_obj->buf_text,
                 UITextAlignment_Center,
                 x1 + 1,
                 y1 + 1,
                 x1 + scr_w - 1,
                 y1 + 1 + fsize + 1,
                 clBlack,
                 NULL,
                 NULL);
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

void Color_contruct(DISP_DESC* desc)
{
  DISP_DESC_SetName(desc, GuiName_Color);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_COLOR));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD) Color_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD) Color_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD) Color_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD) Color_OnKey);
}

void Color_destruct(GUI* gui)
{
}

void Color_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FmRadio_Data* data = GetData();
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*)GUIObject_GetDispObject(FMSettings_Book->ColorPicker);
  
  unsigned int color;
  int item;
  
  if ((disp_obj->type == 0) || (disp_obj->type == 1))
  {
    if (FMSettings_Book->element == ITEM_FREQ_INDICATOR) item = 3;
    else item = 1;
    color = data->temp.color1 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  else
  {
    if (FMSettings_Book->element == ITEM_FREQ_INDICATOR ) item = 4;
    else item = 2;
    color = data->temp.color2 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  
  snwprintf(data->buf, 
            MAXELEMS(data->buf), 
            L"%02X, %02X, %02X, %02X", 
            COLOR_GET_R(color), 
            COLOR_GET_G(color), 
            COLOR_GET_B(color), 
            COLOR_GET_A(color));
  ListMenu_SetItemSecondLineText(FMSettings_Book->SubMenu, item, TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN));
  FREE_GUI(FMSettings_Book->ColorPicker);
  FMSettings_Book->changed = TRUE;
}

void Color_onBack( BOOK* book, GUI* )
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FREE_GUI(FMSettings_Book->ColorPicker);
}

void SetColor(BOOK* book, int type)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  
  GUI* gui_color = (GUI*)malloc(sizeof(GUI));
  if(!GUIObject_Create(gui_color, Color_destruct, Color_contruct, FMSettings_Book, NULL, UIDisplay_Main, NULL)) mfree(gui_color);
  
  FMSettings_Book->ColorPicker = gui_color;
  
  FmRadio_Data* data = GetData();
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*)GUIObject_GetDispObject(FMSettings_Book->ColorPicker);
  disp_obj->type = type;
  
  unsigned int color = clEmpty;
  if ((type == 0) || (type == 1))
  {
    color = data->temp.color1;
    disp_obj->r = COLOR_GET_R(color);
    disp_obj->g = COLOR_GET_G(color);
    disp_obj->b = COLOR_GET_B(color);
    disp_obj->a = COLOR_GET_A(color);
  }
  else
  {
    color = data->temp.color2;
    disp_obj->r = COLOR_GET_R(color);
    disp_obj->g = COLOR_GET_G(color);
    disp_obj->b = COLOR_GET_B(color);
    disp_obj->a = COLOR_GET_A(color);
  }
  
  if (FMSettings_Book) BookObj_AddGUIObject(FMSettings_Book, gui_color);
  
  GUIObject_SetTitleText(FMSettings_Book->ColorPicker, TEXT_COLOR);
  GUIObject_SetTitleType(FMSettings_Book->ColorPicker, UI_TitleMode_Small);
  GUIObject_SoftKeys_SetAction(FMSettings_Book->ColorPicker, ACTION_SELECT1, Color_OnSelect);
  GUIObject_SoftKeys_SetText(FMSettings_Book->ColorPicker, ACTION_SELECT1, STR("OK"));
  GUIObject_SoftKeys_SetAction(FMSettings_Book->ColorPicker, ACTION_BACK, Color_onBack);
  GUIObject_Show(FMSettings_Book->ColorPicker);
  //set_book->color_type = type;
  //set_book->palette = CreatePalette( set_book, TEXT_COLOR, COLOR_LIST, 0x1C, 0, Color_onBack, Color_onBack, Color_OnSelect );
  //GUIObject_Show(set_book->palette);
}

////////////////////////////////////////////////////////////////////////////////

#if defined(A1) || defined(DB3150_V1) || defined(DB3150_V2)

FONT_DESC* GetFontDesc()
{
  return GetFontDesc_p;
}
   
int GetFontCount()
{
  return *GetFontCount_p;
}

wchar_t* Font_GetNameByFontId(int id)
{
  wchar_t* txt = L"Undefined";
  FONT_DESC* font = GetFontDesc();
  int total_font = GetFontCount();
  
  for (int i = 0; i < total_font; i++)
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
  int total_font = GetFontCount();
  
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

void SetVisual(BOOK* book)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  
  FmRadio_Data* data = GetData();
  data->edit_visual = TRUE;
  data->element = FMSettings_Book->element;
  
  int type = FMSettings_Book->elem_type;
  if(type==ELEM_TEXT)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    data->total_fonts = max_size / font_step;
    data->cur_pos = (data->temp.font&0xFF) / font_step - 1;
    int style_flags = data->temp.font >> 8;
    data->style_bold = style_flags&bold;
    data->style_italic = (style_flags&italic) >> 1;
#else
    data->total_fonts = GetFontCount();
    data->cur_pos = GetIdByFontId(data->temp.font);
#endif
    data->text = TRUE;
    data->rect = FALSE;
    data->icon = FALSE;
  }
  else if(type == ELEM_RECT)
  {
    data->text = FALSE;
    data->rect = TRUE;
    data->icon = FALSE;
  }
  else if(type == ELEM_ICON)
  {
    data->text = FALSE;
    data->rect = FALSE;
    data->icon = TRUE;
  }

  FreeBook(FMSettings_Book);
  
  FmRadio_Book* FMbook = (FmRadio_Book*)data->FmRadioBook;
  GUIObject_SoftKeys_SetVisible(FMbook->FmRadio_Gui,ACTION_BACK,FALSE);
  FmRadio_SetActiveSoftKeys(FMbook,FALSE);
}
