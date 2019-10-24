#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "setting.h"
#include "data.h"
#include "lang.h"
#include "editor.h"
#include "main.h"

void RefreshList( BOOK* book, int count )
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  
  int pos = ListMenu_GetSelectedItem(m_bk->gui_elem);
  ListMenu_DestroyItems(m_bk->gui_elem);
  ListMenu_SetItemCount(m_bk->gui_elem, count);
  ListMenu_SetCursorToItem(m_bk->gui_elem, pos);
  GUIObject_SoftKeys_SetVisible(m_bk->gui_elem, ACTION_SELECT1, TRUE);
  m_bk->change = TRUE;
}

void SetActivate(SETTING_BOOK* m_bk, int count)
{
  DBP_DATA* data = GetData();
  int item = ListMenu_GetSelectedItem(m_bk->gui_elem);
  
  TEXTID text = EMPTY_TEXTID;
  if (item == 0)
  {
    if(data->temp.activate1)
    {
      text = TEXT_OFF;
      data->temp.activate1 = 0;
    }
    else
    {
      text = TEXT_ON;
      data->temp.activate1 = 1;
    }
  }
  else if (item == 1)
  {
    if(data->temp.activate2)
    {
      text = TEXT_OFF;
      data->temp.activate2 = 0;
    }
    else
    {
      text = TEXT_ON;
      data->temp.activate2 = 1;
    }
  }
  else if (item == 2)
  {
    if(data->temp.activate3)
    {
      if (m_bk->element == ITEM_TIME_PROGRESS) text = TextID_Global(ID_PTYPE_1);
      else if (m_bk->element == ITEM_VOLUME_PROGRESS) text = TextID_Global(ID_PTYPE_1);
      else text = TEXT_OFF;
      data->temp.activate3 = 0;
    }
    else
    {
      if (m_bk->element == ITEM_TIME_PROGRESS) text = TextID_Global(ID_PTYPE_2);
      else if (m_bk->element == ITEM_VOLUME_PROGRESS) text = TextID_Global(ID_PTYPE_2);
      else text = TEXT_ON;
      data->temp.activate3 = 1;
    }
  } 
  
  RefreshList( m_bk, count );
  ListMenu_SetItemSecondLineText(m_bk->gui_elem, item, text);
}

void ProgressBar_OnSelect(BOOK* book, GUI* gui)
{
  DBP_DATA* data = GetData();
  
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  data->temp.activate1 = OneOfMany_GetSelected(m_bk->gui_oom);
  GUIObject_Destroy(m_bk->gui_oom);
  
  RefreshList(book, BACKGROUND_COUNT);
}

void Show_OnSelect(BOOK* book, GUI* gui)
{
  DBP_DATA* data = GetData();
  
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  data->temp.activate1 = OneOfMany_GetSelected(m_bk->gui_oom);
  GUIObject_Destroy(m_bk->gui_oom);
  
  RefreshList(book, TEXT_COUNT);
}

void Align_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  DBP_DATA* data = GetData();
  data->temp.align = OneOfMany_GetSelected(m_bk->gui_oom);
  TEXTID text = EMPTY_TEXTID;
  if (data->temp.align == 0) text = TEXT_LEFT;
  else if (data->temp.align == 1) text = TEXT_RIGHT;
  else if (data->temp.align == 2) text = TEXT_CENTRE;
  ListMenu_SetItemSecondLineText(m_bk->gui_elem, 3, text);
  GUIObject_Destroy(m_bk->gui_oom);
  m_bk->change = TRUE;
}

void OnBack(BOOK* book, GUI* gui)
{
  GUIObject_Destroy(gui);
}

void OneOfMany_SetMode(SETTING_BOOK* m_bk, int type)
{
  DBP_DATA* data = GetData();
  m_bk->gui_oom = CreateOneOfMany(m_bk);
  
  if (type == 0)
  {
    GUIObject_SetTitleText(m_bk->gui_oom, TEXT_MODE);
    
    TEXTID strid[3];
    strid[0] = TEXT_IMAGE;
    strid[1] = TEXT_THEME;
    strid[2] = TEXT_COLOR;
    OneOfMany_SetTexts(m_bk->gui_oom, strid, 3);
    OneOfMany_SetChecked(m_bk->gui_oom, data->temp.activate1);
    GUIObject_SoftKeys_SetAction(m_bk->gui_oom, ACTION_SELECT1, ProgressBar_OnSelect);
  }
  else if (type == 1)
  {
    GUIObject_SetTitleText(m_bk->gui_oom, TextID_Global(ID_ALIGN));
    
    TEXTID strid[3];
    strid[0] = TEXT_LEFT;
    strid[1] = TEXT_RIGHT;
    strid[2] = TEXT_CENTRE;
    OneOfMany_SetTexts(m_bk->gui_oom, strid, 3);
    OneOfMany_SetChecked(m_bk->gui_oom, data->temp.align);
    GUIObject_SoftKeys_SetAction(m_bk->gui_oom, ACTION_SELECT1, Align_OnSelect);
  }
  else if (type == 2)
  {
    GUIObject_SetTitleText(m_bk->gui_oom, TextID_Global(ID_SHOW));
    
    TEXTID strid[2];
    strid[0] = TEXT_OFF_OOM;
    strid[1] = TEXT_ON_OOM;
    OneOfMany_SetTexts(m_bk->gui_oom, strid, 2);
    OneOfMany_SetChecked(m_bk->gui_oom, data->temp.activate1);
    GUIObject_SoftKeys_SetAction(m_bk->gui_oom, ACTION_SELECT1, Show_OnSelect);
  }
  
  GUIObject_SoftKeys_SetAction(m_bk->gui_oom, ACTION_BACK, OnBack);
  GUIObject_Show(m_bk->gui_oom);
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
  TEXTFREE( disp_obj->buf_text );
}

void Color_OnRedraw(DISP_OBJ_COLOR* disp_obj, int, int, int)
{
  RECT rc_old;
  int gc_xx;
  int fsize = 20;
  GC* gc = get_DisplayGC();
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
  
  GC_GetRect(gc, &rc_old);
  gc_xx = GC_GetXX(gc);
  GC_SetXX(gc, 1);
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
  fsize += 3;
  
  for (int i = 0; i != 4; i++)
  {
    start_column = column_width + 2 * i * column_width + 4;
    column_height++; // ����� �� ����� � DrawRect, ���������� �� ��������� � DrawLine. ��� � �������, DrawRect �� GC_.
    if (disp_obj->current_column == i) DrawRect(x1 + start_column - 2, y1 + fsize - 2 + 50, x1 + start_column + column_width + 2, y1 + fsize + column_height + 2, clBlack, clWhite); // �������
    DrawRect(x1 + start_column, y1 + fsize + 50, x1 + start_column + column_width, y1 + fsize + column_height, clBlack, colors[i]); // �����
    column_height--;
    
    switch(i)
    {
    case 0: y_line = fsize + column_height - (disp_obj->r * (column_height - 50)) / 0xFF; break;
    case 1: y_line = fsize + column_height - (disp_obj->g * (column_height - 50)) / 0xFF; break;
    case 2: y_line = fsize + column_height - (disp_obj->b * (column_height - 50)) / 0xFF; break;
    case 3: y_line = fsize + column_height - (disp_obj->a * (column_height - 50)) / 0xFF; break;
    }
    
    int old_pen = GC_GetPenColor(gc);
    GC_SetPenColor(gc, clBlack);
    GC_DrawLine(gc, x1 + start_column, y1 + y_line, x1 + start_column + column_width - 1, y1 + y_line);
    GC_SetPenColor(gc, old_pen);
  }
  
  int testcolor = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  DrawRect(x1 + 20, y1 + 1 + 30, x1 + scr_w - 20, y1 + fsize + 30, clBlack, testcolor);
  GC_SetXX(gc, gc_xx);
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
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  DBP_DATA* data = GetData();
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*)GUIObject_GetDispObject(gui);
  
  color_t color;
  int item;
  
  if ((disp_obj->type == 0) || (disp_obj->type == 1))
  {
    if (m_bk->element == ITEM_TIME_PROGRESS) item = 3;
    else if ( m_bk->element == ITEM_VOLUME_PROGRESS) item =4;
    else item = 1;
    color = data->temp.color1 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  else
  {
    if (m_bk->element == ITEM_TIME_PROGRESS ) item = 4;
    else if ( m_bk->element == ITEM_VOLUME_PROGRESS) item =4;
    else item = 2;
    color = data->temp.color2 = COLOR_RGBA(disp_obj->r, disp_obj->g, disp_obj->b, disp_obj->a);
  }
  
  snwprintf(data->buf, MAXELEMS(data->buf), L"%02X, %02X, %02X, %02X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
  ListMenu_SetItemSecondLineText(m_bk->gui_elem, item, TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN));
  GUIObject_Destroy(gui);
  m_bk->change = TRUE;
}

void SetColor(SETTING_BOOK* m_bk, int type)
{
  GUI* gui_color = (GUI*)malloc(sizeof(GUI));
  if(!GUIObject_Create(gui_color, Color_destroy, Color_create, m_bk, NULL, UIDisplay_Main, NULL)) mfree(gui_color);
  
  DBP_DATA* data = GetData();
  DISP_OBJ_COLOR* disp_obj = (DISP_OBJ_COLOR*)GUIObject_GetDispObject(gui_color);
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
  
  if (m_bk) BookObj_AddGUIObject(m_bk, gui_color);
  
  GUIObject_SetTitleText(gui_color, TEXT_COLOR);
  GUIObject_SetTitleType(gui_color, UI_TitleMode_Small);
  GUIObject_SoftKeys_SetAction(gui_color, ACTION_SELECT1, Color_OnSelect);
  GUIObject_SoftKeys_SetText(gui_color, ACTION_SELECT1, STR("OK"));
  GUIObject_SoftKeys_SetAction(gui_color, ACTION_BACK, OnBack);
  GUIObject_Show(gui_color);
}

////////////////////////////////////////////////////////////////////////////////

void SetActiveSoft(DBP_DATA* data, BOOL mode)
{
  if (!data->pause) GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PAUSE, mode);
  else GUIObject_SoftKeys_SetVisible(data->gui, ACTION_PLAY, mode);
  
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_STOP, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_SETTINGS, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_TAG, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_TIME, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_TURN, mode);
  GUIObject_SoftKeys_SetVisible(data->gui, ACTION_LONG_BACK, mode);
  
  if (data->setting.soft)
  {
    if (mode) GUIObject_SoftKeys_Show(data->gui);
    else GUIObject_SoftKeys_Hide(data->gui);
  }
}

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
  int r = NULL;
  FONT_DESC* font = GETFONTDESC;
  for (int i = 0, max = *GETFONTCOUNT; i < max; i++)
  {
    if (id == font[i].id)
    {
      r = i;
      break;
    }
  }
  return r;
}

void SetVisual(SETTING_BOOK* m_bk)
{
  DBP_DATA* data = GetData();
  data->edit_visual = TRUE;
  data->element = m_bk->element;
  
  //data->pIMMEPlayer->Pause();
  //data->pause = TRUE;
  
  if (m_bk->element > ITEM_AUDIOOUTPUT)
  {
    if ( m_bk->element == ITEM_TIME_PROGRESS || m_bk->element == ITEM_VOLUME_PROGRESS || m_bk->element == ITEM_COVER ) data->rect = TRUE;
  }
  else
  {
    data->total_fonts = *GETFONTCOUNT;
    data->cur_pos = GetIdByFontId(data->temp.font);
    data->text = TRUE;
  }
  
  FreeBook(m_bk);
  SetActiveSoft(data, FALSE);
}
