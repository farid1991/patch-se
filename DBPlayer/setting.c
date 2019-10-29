#include "..\\include\Types.h"
#include "..\\include\Function.h"

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
      DBP_DATA* data = GetData();
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
          int font_size = (data->cur_pos+1)*font_step + (data->style_bold<<8) + (data->style_italic<<9); //data->temp.font&0xFF;
          int style = font_size >> 8; //data->temp.font>>8;
          if (style == 0) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
          else if (style == 1) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_B", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size&0xFF, font_size&0xFF);
          else if (style == 2) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size&0xFF, font_size&0xFF);
          else if (style == 3) snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_B_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size&0xFF, font_size&0xFF);
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
      DBP_DATA* data = GetData();
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
      DBP_DATA* data = GetData();
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
      DBP_DATA* data = GetData();
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
      DBP_DATA* data = GetData();
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

void CreateEditor(DBP_DATA* data, SETTING_BOOK* m_bk, int type, int count)
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
  
  DBP_DATA* data = GetData();
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
  
  if (item == ITEM_ARTIST)
  {
    data->temp.activate1 = data->setting.artist.state;
    data->temp.align = data->setting.artist.align;
    data->temp.color1 = data->setting.artist.tcolor;
    data->temp.color2 = data->setting.artist.ocolor;
    data->temp.overlay = data->setting.artist.overlay;
    data->temp.font = data->setting.artist.font;
    data->temp.x1 = data->setting.artist.coord.x1;
    data->temp.y1 = data->setting.artist.coord.y1;
    data->temp.x2 = data->setting.artist.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_TITLE)
  {
    data->temp.activate1 = data->setting.title.state;
    data->temp.align = data->setting.title.align;
    data->temp.color1 = data->setting.title.tcolor;
    data->temp.color2 = data->setting.title.ocolor;
    data->temp.overlay = data->setting.title.overlay;
    data->temp.font = data->setting.title.font;
    data->temp.x1 = data->setting.title.coord.x1;
    data->temp.y1 = data->setting.title.coord.y1;
    data->temp.x2 = data->setting.title.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_ALBUM)
  {
    data->temp.activate1 = data->setting.album.state;
    data->temp.align = data->setting.album.align;
    data->temp.color1 = data->setting.album.tcolor;
    data->temp.color2 = data->setting.album.ocolor;
    data->temp.overlay = data->setting.album.overlay;
    data->temp.font = data->setting.album.font;
    data->temp.x1 = data->setting.album.coord.x1;
    data->temp.y1 = data->setting.album.coord.y1;
    data->temp.x2 = data->setting.album.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_YEAR)
  {
    data->temp.activate1 = data->setting.year.state;
    data->temp.align = data->setting.year.align;
    data->temp.color1 = data->setting.year.tcolor;
    data->temp.color2 = data->setting.year.ocolor;
    data->temp.overlay = data->setting.year.overlay;
    data->temp.font = data->setting.year.font;
    data->temp.x1 = data->setting.year.coord.x1;
    data->temp.y1 = data->setting.year.coord.y1;
    data->temp.x2 = data->setting.year.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_GENRE)
  {
    data->temp.activate1 = data->setting.genre.state;
    data->temp.align = data->setting.genre.align;
    data->temp.color1 = data->setting.genre.tcolor;
    data->temp.color2 = data->setting.genre.ocolor;
    data->temp.overlay = data->setting.genre.overlay;
    data->temp.font = data->setting.genre.font;
    data->temp.x1 = data->setting.genre.coord.x1;
    data->temp.y1 = data->setting.genre.coord.y1;
    data->temp.x2 = data->setting.genre.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_EXT)
  {
    data->temp.activate1 = data->setting.ext.state;
    data->temp.align = data->setting.ext.align;
    data->temp.color1 = data->setting.ext.tcolor;
    data->temp.color2 = data->setting.ext.ocolor;
    data->temp.overlay = data->setting.ext.overlay;
    data->temp.font = data->setting.ext.font;
    data->temp.x1 = data->setting.ext.coord.x1;
    data->temp.y1 = data->setting.ext.coord.y1;
    data->temp.x2 = data->setting.ext.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_TOTAL)
  {
    data->temp.activate1 = data->setting.time_t.state;
    data->temp.align = data->setting.time_t.align;
    data->temp.color1 = data->setting.time_t.tcolor;
    data->temp.color2 = data->setting.time_t.ocolor;
    data->temp.overlay = data->setting.time_t.overlay;
    data->temp.font = data->setting.time_t.font;
    data->temp.x1 = data->setting.time_t.coord.x1;
    data->temp.y1 = data->setting.time_t.coord.y1;
    data->temp.x2 = data->setting.time_t.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_ELAPSED)
  {
    data->temp.activate1 = data->setting.time_e.state;
    data->temp.align = data->setting.time_e.align;
    data->temp.color1 = data->setting.time_e.tcolor;
    data->temp.color2 = data->setting.time_e.ocolor;
    data->temp.overlay = data->setting.time_e.overlay;
    data->temp.font = data->setting.time_e.font;
    data->temp.x1 = data->setting.time_e.coord.x1;
    data->temp.y1 = data->setting.time_e.coord.y1;
    data->temp.x2 = data->setting.time_e.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_REMAINING)
  {
    data->temp.activate1 = data->setting.time_r.state;
    data->temp.align = data->setting.time_r.align;
    data->temp.color1 = data->setting.time_r.tcolor;
    data->temp.color2 = data->setting.time_r.ocolor;
    data->temp.overlay = data->setting.time_r.overlay;
    data->temp.font = data->setting.time_r.font;
    data->temp.x1 = data->setting.time_r.coord.x1;
    data->temp.y1 = data->setting.time_r.coord.y1;
    data->temp.x2 = data->setting.time_r.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_BITRATE)
  {
    data->temp.activate1 = data->setting.bitrate.state;
    data->temp.align = data->setting.bitrate.align;
    data->temp.color1 = data->setting.bitrate.tcolor;
    data->temp.color2 = data->setting.bitrate.ocolor;
    data->temp.overlay = data->setting.bitrate.overlay;
    data->temp.font = data->setting.bitrate.font;
    data->temp.x1 = data->setting.bitrate.coord.x1;
    data->temp.y1 = data->setting.bitrate.coord.y1;
    data->temp.x2 = data->setting.bitrate.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_SAMPLERATE)
  {
    data->temp.activate1 = data->setting.samplerate.state;
    data->temp.align = data->setting.samplerate.align;
    data->temp.color1 = data->setting.samplerate.tcolor;
    data->temp.color2 = data->setting.samplerate.ocolor;
    data->temp.overlay = data->setting.samplerate.overlay;
    data->temp.font = data->setting.samplerate.font;
    data->temp.x1 = data->setting.samplerate.coord.x1;
    data->temp.y1 = data->setting.samplerate.coord.y1;
    data->temp.x2 = data->setting.samplerate.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_AUDIOOUTPUT)
  {
    data->temp.activate1 = data->setting.audiooutput.state;
    data->temp.align = data->setting.audiooutput.align;
    data->temp.color1 = data->setting.audiooutput.tcolor;
    data->temp.color2 = data->setting.audiooutput.ocolor;
    data->temp.overlay = data->setting.audiooutput.overlay;
    data->temp.font = data->setting.audiooutput.font;
    data->temp.x1 = data->setting.audiooutput.coord.x1;
    data->temp.y1 = data->setting.audiooutput.coord.y1;
    data->temp.x2 = data->setting.audiooutput.coord.x2;
    CreateEditor(data, m_bk, 0, TEXT_COUNT);
  }
  else if (item == ITEM_TIME_PROGRESS)
  {
    data->temp.activate1 = data->setting.time.state;
    data->temp.activate2 = data->setting.time.slider;
    data->temp.activate3 = data->setting.time.round;
    data->temp.color1 = data->setting.time.progress_bcolor;
    data->temp.color2 = data->setting.time.progress_fcolor;
    data->temp.x1 = data->setting.time.progress_rect.x1;
    data->temp.y1 = data->setting.time.progress_rect.y1;
    data->temp.x2 = data->setting.time.progress_rect.x2;
    data->temp.y2 = data->setting.time.progress_rect.y2;
    CreateEditor(data, m_bk, 1, PROGRESS_COUNT);
  }
  else if (item == ITEM_VOLUME_PROGRESS)
  {
    data->temp.activate1 = data->setting.volume.state;
    data->temp.activate2 = data->setting.volume.slider;
    data->temp.activate3 = data->setting.volume.round;
    data->temp.color1 = data->setting.volume.progress_bcolor;
    data->temp.color2 = data->setting.volume.progress_fcolor;
    data->temp.x1 = data->setting.volume.progress_rect.x1;
    data->temp.y1 = data->setting.volume.progress_rect.y1;
    data->temp.x2 = data->setting.volume.progress_rect.x2;
    data->temp.y2 = data->setting.volume.progress_rect.y2;
    CreateEditor(data, m_bk, 1, PROGRESS_COUNT);
  }
  else if (item == ITEM_COVER)
  {
    data->temp.activate1 = data->setting.cover;
    data->temp.x1 = data->setting.cover_rect.x1;
    data->temp.y1 = data->setting.cover_rect.y1;
    data->temp.x2 = data->setting.cover_rect.x2;
    data->temp.y2 = data->setting.cover_rect.y2;
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_FRAME)
  {
    data->temp.activate1 = data->setting.frame.state;
    data->temp.x1 = data->setting.frame.pos.x;
    data->temp.y1 = data->setting.frame.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_ARTIST_ICN)
  {
    data->temp.activate1 = data->setting.artist_icn.state;
    data->temp.x1 = data->setting.artist_icn.pos.x;
    data->temp.y1 = data->setting.artist_icn.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_TITLE_ICN)
  {
    data->temp.activate1 = data->setting.title_icn.state;
    data->temp.x1 = data->setting.title_icn.pos.x;
    data->temp.y1 = data->setting.title_icn.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_ALBUM_ICN)
  {
    data->temp.activate1 = data->setting.album_icn.state;
    data->temp.x1 = data->setting.album_icn.pos.x;
    data->temp.y1 = data->setting.album_icn.pos.y,
    CreateEditor(data, m_bk, 2, IMAGE_COUNT);
  }
  else if (item == ITEM_PLAYERSTATE_ICN)
  {
    data->temp.activate1 = data->setting.playerstate_icn.state;
    data->temp.x1 = data->setting.playerstate_icn.pos.x;
    data->temp.y1 = data->setting.playerstate_icn.pos.y,
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
  FreeBook(m_bk);
  
  DBP_DATA* data = GetData();
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
}

void Question_OnNo(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  DBP_DATA* data = GetData();
  LoadData(data);
  FreeBook(m_bk);
}

void Question_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  if (m_bk->gui_question)
  {
    GUIObject_Destroy(m_bk->gui_question);
    m_bk->gui_question = NULL;
  }
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
  else FreeBook(book);
}

int DBPlayer_Settings_onCreate(void* data, BOOK* book)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)book;
  m_bk->gui_set = CreateListMenu(m_bk, UIDisplay_Main);
  GUIObject_SetTitleText(m_bk->gui_set, TEXT_SETTING);
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
  PAGE_ENTER_EVENT, DBPlayer_Settings_onCreate,
  NIL_EVENT,        NULL
};

const PAGE_DESC DBPlayer_Settings_Base_Page = {"DBPlayer_Settings_Base_Page", NULL, base_evlist};
const PAGE_DESC DBPlayer_Settings_Main_Page = {"DBPlayer_Settings_Main_Page", NULL, main_evlist};

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

void DBPlayer_Setting(BOOK* book, GUI* gui)
{
  SETTING_BOOK* m_bk = (SETTING_BOOK*)malloc(sizeof(SETTING_BOOK));
  memset(m_bk, NULL, sizeof(SETTING_BOOK));
  if(!CreateBook(m_bk, SettingBook_onClose, &DBPlayer_Settings_Base_Page, "DBPlayer_SettingBook", -1, 0)) mfree(m_bk);
  else BookObj_GotoPage(m_bk, &DBPlayer_Settings_Main_Page);
}
