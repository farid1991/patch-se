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

#include "main.h"
#include "data.h"
#include "setting.h"
#include "lang.h"
#include "editor.h"

void Text_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(m_bk->gui_elem);
  if (item == 0) OneOfMany_SetMode(m_bk, 2);
  else if (item == 1) SetColor(m_bk, 1);
  else if (item == 2) SetColor(m_bk, 2);
  else if (item == 3) OneOfMany_SetMode(m_bk, 1);
  else if (item == 4) SetVisual(m_bk);
}

void Progress_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(m_bk->gui_elem);
  if (item == 0) SetActivate(m_bk,PROGRESS_COUNT);
  else if (item == 1) SetActivate(m_bk,PROGRESS_COUNT);
  else if (item == 2) SetActivate(m_bk,PROGRESS_COUNT);
  else if (item == 3) SetColor(m_bk, 1);
  else if (item == 4) SetColor(m_bk, 2);
  else if (item == 5) SetVisual(m_bk);
}

void Image_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(m_bk->gui_elem);
  if (item == 0) SetActivate(m_bk,IMAGE_COUNT);
  else if (item == 1) SetVisual(m_bk);
}

void Background_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(m_bk->gui_elem);
  if (item == 0) OneOfMany_SetMode(m_bk, 0);
  else if (item == 1) SetColor(m_bk, 0);
  else if (item == 2) SetVisual(m_bk);
}

void Additional_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(m_bk->gui_elem);
  if (item == 0) SetActivate(m_bk,ADDITIONAL_COUNT);
  else if (item == 1) SetActivate(m_bk,ADDITIONAL_COUNT);
  else if (item == 2) SetActivate(m_bk,ADDITIONAL_COUNT);
}

int Text_OnMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      FmRadio_Data* data = Get_Data();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text = EMPTY_TEXTID;
      TEXTID second_text = EMPTY_TEXTID;
      
      if (item == 0) // Отображение
      {
        first_text = TextID_Global(ID_SHOW);
        if (data->temp.activate1) second_text = TEXT_ON;
        else second_text = TEXT_OFF;
      }
      else
      {
        if (item == 1 || item == 2)
        {
          color_t color;
          if (item == 1) // Цвет текста
          {
            first_text = TEXT_COLOR_TEXT;
            color = data->temp.color1;
          }
          else // Цвет обводки
          {
            first_text = TextID_Global(ID_COLOR_OVERLAY);
            color = data->temp.color2;
          }
          snwprintf(data->buf, MAXELEMS(data->buf)-1, L"%02X, %02X, %02X, %02X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
          second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        }
        else if (item == 3) // Выравнивание
        {
          first_text = TextID_Global(ID_ALIGN);
          if (data->temp.align == 0) second_text = TEXT_LEFT;
          else if (data->temp.align == 1) second_text = TEXT_RIGHT;
          else if (data->temp.align == 2) second_text = TEXT_CENTRE;
        }
        else if (item == 4) // Визуальные
        {
          first_text = TextID_Global(ID_VISUAL);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
          int style = data->temp.font>>8;
          int font_size = data->temp.font&0xFF;
          if (style == 0) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, data->temp.font);
          else if (style == 1) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_B", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
          else if (style == 2) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
          else if (style == 3) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_B_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
          second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#else 
          second_text = TextID_Create(Font_GetNameByFontId(data->temp.font), ENC_UCS2, TEXTID_ANY_LEN);
#endif
        }
        if (!data->temp.activate1) GUIonMessage_SetItemDisabled(msg, TRUE);
      }
      
      GUIonMessage_SetMenuItemText(msg, first_text);
      GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Progress_OnMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      FmRadio_Data* data = Get_Data();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text = EMPTY_TEXTID;
      TEXTID second_text = EMPTY_TEXTID;
      
      if (item == 3 || item == 4) // Цвет фона // Цвет заполнения
      {
        color_t color;
        if (item == 3)
        {
          first_text = TEXT_COLOR_B;
          color = data->temp.color1;
        }
        else
        {
          first_text = TextID_Global(ID_COLOR_F);
          color = data->temp.color2;
        }
        snwprintf(data->buf, MAXELEMS(data->buf)-1, L"%02X, %02X, %02X, %02X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
      }
      else
      {
        switch (item)
        {
        case 0: // Отображение
          first_text = TextID_Global(ID_SHOW);
          if (data->temp.activate1) second_text = TEXT_ON;
          else second_text = TEXT_OFF;
          break;
        case 1: // Ползунок
          first_text = TextID_Global(ID_SLIDER);
          if (data->temp.activate2) second_text = TEXT_ON;
          else second_text = TEXT_OFF;
          break;
        case 2: // Закругление
          first_text = TEXT_PTYPE;
          if (data->temp.activate3) second_text = TextID_Global(ID_PTYPE_2);
          else second_text = TextID_Global(ID_PTYPE_1);
          break;
        case 5: // Визуальные
          first_text = TextID_Global(ID_VISUAL);
          snwprintf(data->buf, MAXELEMS(data->buf) - 1, L"%d, %d, %d, %d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y2);
          second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
          break;
        }
      }
      GUIonMessage_SetMenuItemText(msg, first_text);
      GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Image_OnMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      FmRadio_Data* data = Get_Data();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text = EMPTY_TEXTID;
      TEXTID second_text = EMPTY_TEXTID;
      
      switch (item)
      {
      case 0: // Отображение
        first_text = TextID_Global(ID_SHOW);
        if (data->temp.activate1) second_text = TEXT_ON;
        else second_text = TEXT_OFF;
        break;
      case 1: // Визуальные
        first_text = TextID_Global(ID_VISUAL);
        snwprintf(data->buf, MAXELEMS(data->buf) - 1, L"%d, %d, %d, %d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y2);
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        if (!data->temp.activate1) GUIonMessage_SetItemDisabled(msg, TRUE);
        break;
      }
      
      GUIonMessage_SetMenuItemText(msg, first_text);
      GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Background_OnMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      FmRadio_Data* data = Get_Data();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text = EMPTY_TEXTID;
      TEXTID second_text = EMPTY_TEXTID;
      
      if (item==0)
      {
      //case 0: // Режим отображения
        first_text = TEXT_MODE;
        if (data->temp.activate1 == TYPE_IMAGE) second_text = TEXT_IMAGE;
        else if (data->temp.activate1 == TYPE_THEME) second_text = TEXT_THEME;
        else if (data->temp.activate1 == TYPE_COLOR) second_text = TEXT_COLOR;
      }
      else if (item==1)
      {
      //case 1: // Цвет
        first_text = TEXT_COLOR;
        color_t color = data->temp.color1;
        snwprintf(data->buf, MAXELEMS(data->buf) - 1, L"%02X, %02X, %02X, %02X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        if (data->temp.activate1 == TYPE_IMAGE || data->temp.activate1 == TYPE_THEME) GUIonMessage_SetItemDisabled(msg, TRUE);
      }
      else if (item==2)
      {
      //case 2: // Визуальные
        first_text = TextID_Global(ID_VISUAL);
        snwprintf(data->buf, MAXELEMS(data->buf) - 1, L"%d, %d, %d, %d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y2);
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        if (data->temp.activate1 == TYPE_THEME || data->temp.activate1 == TYPE_COLOR) GUIonMessage_SetItemDisabled(msg, TRUE);
      }
      GUIonMessage_SetMenuItemText(msg, first_text);
      GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Additional_OnMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      FmRadio_Data* data = Get_Data();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text = EMPTY_TEXTID;
      TEXTID second_text = EMPTY_TEXTID;
      
      switch (item)
      {
      case 0: // На весь экран
        first_text = TEXT_SCREEN;
        if (data->temp.activate1) second_text = TEXT_ON;
        else second_text = TEXT_OFF;
        break;
      case 1: // Софты
        first_text = TextID_Global(ID_SOFT);
        if (data->temp.activate2) second_text = TEXT_ON;
        else second_text = TEXT_OFF;
        break;
      case 2: // Анимация
        first_text = TEXT_ANIMATION;
        if (data->temp.activate3) second_text = TEXT_ON;
        else second_text = TEXT_OFF;
        break;
      }
      GUIonMessage_SetItemDisabled(msg, TRUE);
      GUIonMessage_SetMenuItemText(msg, first_text);
      GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

void Editor_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  if (m_bk->change) SaveData(FALSE, m_bk->element);
  if (m_bk->gui_elem)
  {
    GUIObject_Destroy(m_bk->gui_elem);
    m_bk->gui_elem = NULL;
  }
}

void CreateEditor(FmRadio_Data* data, SETTING_BOOK* m_bk, int type, int count)
{
  m_bk->gui_elem = CreateListMenu(m_bk, UIDisplay_Main);
  //m_bk->gui_elem = gui;
  
  if (type == 0) // Текст
  {
    ListMenu_SetOnMessage(m_bk->gui_elem, Text_OnMessage);
    GUIObject_SoftKeys_SetAction(m_bk->gui_elem, ACTION_SELECT1, Text_OnSelect);
  }
  else if (type == 1) // Прогрессбар
  {
    ListMenu_SetOnMessage(m_bk->gui_elem, Progress_OnMessage);
    GUIObject_SoftKeys_SetAction(m_bk->gui_elem, ACTION_SELECT1, Progress_OnSelect);
  }
  else if (type == 2) // Обложка и рамка
  {
    ListMenu_SetOnMessage(m_bk->gui_elem, Image_OnMessage);
    GUIObject_SoftKeys_SetAction(m_bk->gui_elem, ACTION_SELECT1, Image_OnSelect);
  }
  else if (type == 3) // Фон
  {
    ListMenu_SetOnMessage(m_bk->gui_elem, Background_OnMessage);
    GUIObject_SoftKeys_SetAction(m_bk->gui_elem, ACTION_SELECT1, Background_OnSelect);
  }
  else if (type == 4) // Дополнительно
  {
    ListMenu_SetOnMessage(m_bk->gui_elem, Additional_OnMessage);
    GUIObject_SoftKeys_SetAction(m_bk->gui_elem, ACTION_SELECT1, Additional_OnSelect);
  }
  
  GUIObject_SetTitleText(m_bk->gui_elem, TextID_Setting(m_bk->element));
  ListMenu_SetItemCount(m_bk->gui_elem, count);
  ListMenu_SetCursorToItem(m_bk->gui_elem, 0);
  ListMenu_SetItemStyle(m_bk->gui_elem, 3);
  GUIObject_SoftKeys_SetAction(m_bk->gui_elem, ACTION_BACK, Editor_OnBack);
  GUIObject_Show(m_bk->gui_elem);
}

//******************************************************************************
//Настройки

int Setting_OnMessage(GUI_MESSAGE* msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, TextID_Setting(item));
  }
  return 1;
}

void Setting_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(m_bk->gui_set);
  m_bk->element = item;
  m_bk->change = FALSE;
  
  FmRadio_Data* data = Get_Data();
  data->temp.activate1 = NULL;
  data->temp.activate2 = NULL;
  data->temp.activate3 = NULL;
  data->temp.align = NULL;
  data->temp.color1 = NULL;
  data->temp.color2 = NULL;
  data->temp.overlay = NULL;
  data->temp.font = NULL;
  data->temp.x1 = NULL;
  data->temp.y1 = NULL;
  data->temp.x2 = NULL;
  data->temp.y2 = NULL;
  
  if (item == ITEM_FREQUENCY)
  {
    data->temp.activate1 = data->setting.frequency.state;
    data->temp.align = data->setting.frequency.align;
    data->temp.color1 = data->setting.frequency.tcolor;
    data->temp.color2 = data->setting.frequency.ocolor;
    data->temp.overlay = data->setting.frequency.overlay;
    data->temp.font = data->setting.frequency.font;
    data->temp.x1 = data->setting.frequency.coord.x1;
    data->temp.y1 = data->setting.frequency.coord.y1;
    data->temp.x2 = data->setting.frequency.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_CHANNEL)
  {
    data->temp.activate1 = data->setting.channel.state;
    data->temp.align = data->setting.channel.align;
    data->temp.color1 = data->setting.channel.tcolor;
    data->temp.color2 = data->setting.channel.ocolor;
    data->temp.overlay = data->setting.channel.overlay;
    data->temp.font = data->setting.channel.font;
    data->temp.x1 = data->setting.channel.coord.x1;
    data->temp.y1 = data->setting.channel.coord.y1;
    data->temp.x2 = data->setting.channel.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_CHANNELNAME)
  {
    data->temp.activate1 = data->setting.channel_name.state;
    data->temp.align = data->setting.channel_name.align;
    data->temp.color1 = data->setting.channel_name.tcolor;
    data->temp.color2 = data->setting.channel_name.ocolor;
    data->temp.overlay = data->setting.channel_name.overlay;
    data->temp.font = data->setting.channel_name.font;
    data->temp.x1 = data->setting.channel_name.coord.x1;
    data->temp.y1 = data->setting.channel_name.coord.y1;
    data->temp.x2 = data->setting.channel_name.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_RDS_DATA)
  {
    data->temp.activate1 = data->setting.RDS_data.state;
    data->temp.align = data->setting.RDS_data.align;
    data->temp.color1 = data->setting.RDS_data.tcolor;
    data->temp.color2 = data->setting.RDS_data.ocolor;
    data->temp.overlay = data->setting.RDS_data.overlay;
    data->temp.font = data->setting.RDS_data.font;
    data->temp.x1 = data->setting.RDS_data.coord.x1;
    data->temp.y1 = data->setting.RDS_data.coord.y1;
    data->temp.x2 = data->setting.RDS_data.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  
  else if (item == ITEM_FREQ_INDICATOR)
  {
    data->temp.activate1 = data->setting.freq_indicator.state;
    data->temp.activate2 = data->setting.freq_indicator.slider;
    data->temp.activate3 = data->setting.freq_indicator.round;
    data->temp.color1 = data->setting.freq_indicator.progress_bcolor;
    data->temp.color2 = data->setting.freq_indicator.progress_fcolor;
    data->temp.x1 = data->setting.freq_indicator.progress_rect.x1;
    data->temp.y1 = data->setting.freq_indicator.progress_rect.y1;
    data->temp.x2 = data->setting.freq_indicator.progress_rect.x2;
    data->temp.y2 = data->setting.freq_indicator.progress_rect.y2;
    CreateEditor(data, m_bk, 1, PROGRESS_COUNT);
  }
  
  else if (item == ITEM_RDS_ICN)
  {
    data->temp.activate1 = data->setting.rds_icn.state;
    data->temp.x1 = data->setting.rds_icn.pos.x;
    data->temp.y1 = data->setting.rds_icn.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_AF_ICN)
  {
    data->temp.activate1 = data->setting.af_icn.state;
    data->temp.x1 = data->setting.af_icn.pos.x;
    data->temp.y1 = data->setting.af_icn.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_AUDIO_ICN)
  {
    data->temp.activate1 = data->setting.audio_icn.state;
    data->temp.x1 = data->setting.audio_icn.pos.x;
    data->temp.y1 = data->setting.audio_icn.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  
  else if (item == ITEM_ARROW_LEFT)
  {
    data->temp.activate1 = data->setting.arrow_left.state;
    data->temp.x1 = data->setting.arrow_left.pos.x;
    data->temp.y1 = data->setting.arrow_left.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_ARROW_RIGHT)
  {
    data->temp.activate1 = data->setting.arrow_right.state;
    data->temp.x1 = data->setting.arrow_right.pos.x;
    data->temp.y1 = data->setting.arrow_right.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_ARROW_UP)
  {
    data->temp.activate1 = data->setting.arrow_up.state;
    data->temp.x1 = data->setting.arrow_up.pos.x;
    data->temp.y1 = data->setting.arrow_up.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_ARROW_DOWN)
  {
    data->temp.activate1 = data->setting.arrow_down.state;
    data->temp.x1 = data->setting.arrow_down.pos.x;
    data->temp.y1 = data->setting.arrow_down.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  
  else if (item == ITEM_BACKROUND)
  {
    data->temp.activate1 = data->setting.background.state;
    data->temp.color1 = data->setting.background_color;
    data->temp.x1 = data->setting.background.pos.x;
    data->temp.y1 = data->setting.background.pos.y;
    CreateEditor(data, m_bk, 3, BACKGROUND_COUNT);
  }
  else if (item == ITEM_ADDITIONAL)
  {
    data->temp.activate1 = data->setting.screen;
    data->temp.activate2 = data->setting.soft;
    data->temp.activate3 = data->setting.animation;
    CreateEditor(data, m_bk, 4, ADDITIONAL_COUNT);
  }
}

void Question_OnYes(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  SaveData(TRUE, m_bk->element);
  FmRadio_Data* data = Get_Data();
  LoadData();
  
  if((DISP_OBJ*)data->DispObj_FmRadio) DispObject_InvalidateRect((DISP_OBJ*)data->DispObj_FmRadio,NULL);
  FreeBook(m_bk);
  /*
  FmRadio_Data* data = GetData();
  if (data->setting.screen)
  {
    GUIObject_SetStyle(data->gui, UI_OverlayStyle_TrueFullScreen);
  }
  else
  {
    GUIObject_SetStyle(data->gui, UI_OverlayStyle_Default);
  }
  
  if (!data->setting.soft)
  {
    GUIObject_SoftKeys_Hide(data->gui);
  }
  else
  {
    GUIObject_SoftKeys_Show(data->gui);
  }
  */
}

void Question_OnNo(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  FmRadio_Data* data = Get_Data();
  LoadData();
  
  if((DISP_OBJ*)data->DispObj_FmRadio) DispObject_InvalidateRect((DISP_OBJ*)data->DispObj_FmRadio,NULL);
  FreeBook(m_bk);
}

void Question_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  FREE_GUI(m_bk->gui_question);
}

void Setting_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  if (m_bk->change)
  {
    m_bk->gui_question = CreateYesNoQuestion(book, UIDisplay_Main);
    YesNoQuestion_SetDescriptionText(m_bk->gui_question, TEXT_CHANGE);
    YesNoQuestion_SetQuestionText(m_bk->gui_question, TEXT_QUESTION);
    YesNoQuestion_SetIcon(m_bk->gui_question, POPUP_WARNING_ICN);
    GUIObject_SoftKeys_SetAction(m_bk->gui_question, ACTION_YES, Question_OnYes);
    GUIObject_SoftKeys_SetAction(m_bk->gui_question, ACTION_NO, Question_OnNo);
    GUIObject_SoftKeys_SetAction(m_bk->gui_question, ACTION_BACK, Question_OnBack);
    GUIObject_Show(m_bk->gui_question);
  }
  else FreeBook(m_bk);
}

int FmRadio_Settings_onCreate(void* data, BOOK* book)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  m_bk->gui_set = CreateListMenu(m_bk, UIDisplay_Main);
  GUIObject_SetTitleText(m_bk->gui_set, TEXT_LAYOUT);
  ListMenu_SetItemCount(m_bk->gui_set, SETTING_COUNT);
  ListMenu_SetOnMessage(m_bk->gui_set, Setting_OnMessage);
  ListMenu_SetCursorToItem(m_bk->gui_set, 0);
  ListMenu_SetItemStyle(m_bk->gui_set, 0);
  GUIObject_SoftKeys_SetAction(m_bk->gui_set, ACTION_SELECT1, Setting_OnSelect);
  GUIObject_SoftKeys_SetAction(m_bk->gui_set, ACTION_BACK, Setting_OnBack);
  GUIObject_Show(m_bk->gui_set);
  return 1;
}

//******************************************************************************

int Cancel_BasePage(void* data, BOOK* book)
{
  FreeBook(book);
  return 1;
}

const PAGE_MSG base_evlist[] =
{
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT, NULL
};

const PAGE_MSG main_evlist[] =
{
  PAGE_ENTER_EVENT, FmRadio_Settings_onCreate,
  NIL_EVENT,        NULL
};

const PAGE_DESC FmRadio_Settings_Base_Page = {"FmRadio_Layout_Base_Page", NULL, base_evlist};
const PAGE_DESC FmRadio_Settings_Main_Page = {"FmRadio_Layout_Main_Page", NULL, main_evlist};

void SettingBook_onClose(BOOK* book)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  
  if (m_bk->gui_set)
  {
    GUIObject_Destroy(m_bk->gui_set);
    m_bk->gui_set = NULL;
  }
  
  if (m_bk->gui_elem) 
  {
    GUIObject_Destroy(m_bk->gui_elem);
    m_bk->gui_elem = NULL;
  }
}

void FmRadio_LayoutSetting(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)malloc(sizeof(SETTING_BOOK));
  memset(m_bk, NULL, sizeof(SETTING_BOOK));
  if(!CreateBook(m_bk, SettingBook_onClose, &FmRadio_Settings_Base_Page, "FmRadio_LayoutSettingBook", -1, 0)) mfree(m_bk);
  else BookObj_GotoPage(m_bk, &FmRadio_Settings_Main_Page);
}

extern "C"
void FmRadio_NewSoftKey(GUI* gui)
{
  GUIObject_SoftKeys_SetActionAndText(gui, 0x1F, FmRadio_LayoutSetting, TEXT_LAYOUT);
}
