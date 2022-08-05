#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"

#include "Lib.h"
#include "main.h"
#include "data.h"
#include "setting.h"
#include "lang.h"
#include "editor.h"

void Text_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  int item = ListMenu_GetSelectedItem(setbook->sub_menu);
  if (item == SUBITEM_TXT_STATE)
  {
    OneOfMany_SetMode(setbook, 2);
  }
  else if (item == SUBITEM_TXT_COLOR)
  {
    SetColor(setbook, 1);
  }
  else if (item == SUBITEM_TXT_OVERLAY)
  {
    SetColor(setbook, 2);
  }
  else if (item == SUBITEM_TXT_ALIGN)
  {
    OneOfMany_SetMode(setbook, 1);
  }
  else if (item == SUBITEM_TXT_VISUAL)
  {
    SetVisual(setbook);
  }
}

void Progress_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  int item = ListMenu_GetSelectedItem(setbook->sub_menu);
  if (item == SUBITEM_PB_STATE)
  {
    SetActivate(setbook, SUBITEM_PB_LAST);
  }
  else if (item == SUBITEM_PB_SLIDER)
  {
    SetActivate(setbook, SUBITEM_PB_LAST);
  }
  else if (item == SUBITEM_PB_ROUND)
  {
    SetActivate(setbook, SUBITEM_PB_LAST);
  }
  else if (item == SUBITEM_PB_BCOLOR)
  {
    SetColor(setbook, 1);
  }
  else if (item == SUBITEM_PB_FCOLOR)
  {
    SetColor(setbook, 2);
  }
  else if (item == SUBITEM_PB_VISUAL)
  {
    SetVisual(setbook);
  }
}

void Image_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  int item = ListMenu_GetSelectedItem(setbook->sub_menu);
  if (item == SUBITEM_IMG_STATE)
  {
    SetActivate(setbook, SUBITEM_IMG_LAST);
  }
  else if (item == SUBITEM_IMG_VISUAL)
  {
    SetVisual(setbook);
  }
}

void Background_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  int item = ListMenu_GetSelectedItem(setbook->sub_menu);
  if (item == SUBITEM_BG_TYPE)
  {
    OneOfMany_SetMode(setbook, 0);
  }
  else if (item == SUBITEM_BG_COLOR)
  {
    SetColor(setbook, 0);
  }
  else if (item == SUBITEM_BG_VISUAL)
  {
    SetVisual(setbook);
  }
}

void Additional_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  int item = ListMenu_GetSelectedItem(setbook->sub_menu);
  if (item == SUBITEM_ADDITIONAL_1)
  {
    SetActivate(setbook, SUBITEM_ADDITIONAL_LAST);
  }
  else if (item == SUBITEM_ADDITIONAL_2)
  {
    SetActivate(setbook, SUBITEM_ADDITIONAL_LAST);
  }
#ifndef DB3350
  else if (item == SUBITEM_ADDITIONAL_3)
  {
    SetActivate(setbook, SUBITEM_ADDITIONAL_LAST);
  }
#endif
}

int Text_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    DBP_DATA *data = GetData();
    int item = GUIonMessage_GetCreatedItemIndex(msg);

    TEXTID first_text = EMPTY_TEXTID;
    TEXTID second_text = EMPTY_TEXTID;

    if (item == SUBITEM_TXT_STATE) // Отображение
    {
      first_text = TextID_Global(ID_STATE);
      if (data->temp.activate1)
        second_text = TEXT_ON;
      else
        second_text = TEXT_OFF;
    }
    else
    {
      if (item == SUBITEM_TXT_COLOR || item == SUBITEM_TXT_OVERLAY)
      {
        uint32_t color;
        if (item == 1) // Цвет текста
        {
          first_text = TextID_Global(ID_TEXT_COLOR);
          color = data->temp.color1;
        }
        else // Цвет обводки
        {
          first_text = TextID_Global(ID_COLOR_OVERLAY);
          color = data->temp.color2;
        }
        snwprintf(data->buf,
                  MAXELEMS(data->buf) - 1,
                  L"%02X, %02X, %02X, %02X",
                  COLOR_GET_R(color),
                  COLOR_GET_G(color),
                  COLOR_GET_B(color),
                  COLOR_GET_A(color));
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
      }
      else if (item == SUBITEM_TXT_ALIGN) // Выравнивание
      {
        first_text = TextID_Global(ID_ALIGN);
        if (data->temp.align == AlignLeft)
          second_text = TextID_Global(ID_ALIGN_LEFT);
        else if (data->temp.align == AlignRight)
          second_text = TextID_Global(ID_ALIGN_RIGHT);
        else if (data->temp.align == AlignCenter)
          second_text = TextID_Global(ID_ALIGN_CENTER);
      }
      else if (item == SUBITEM_TXT_VISUAL) // Визуальные
      {
        first_text = TextID_Global(ID_VISUAL_CONFIG);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        int font_size = data->temp.font & 0xFF;
        int font_style = data->temp.font >> 8;
        if (font_style == UIFontStylePlain)
        {
          snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_R", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size, font_size);
        }
        else if (font_style == UIFontStyleBold)
        {
          snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_B", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size & 0xFF, font_size & 0xFF);
        }
        else if (font_style == UIFontStyleItalic)
        {
          snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size & 0xFF, font_size & 0xFF);
        }
        else if (font_style == UIFontStyleBoldItalic)
        {
          snwprintf(data->buf, MAXELEMS(data->buf), L"%d,%d,%d,%d font:%d_B_I", data->temp.x1, data->temp.y1, data->temp.x2, data->temp.y1 + font_size & 0xFF, font_size & 0xFF);
        }
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
#else
        second_text = TextID_Create(Font_GetNameByFontId(data->temp.font), ENC_UCS2, TEXTID_ANY_LEN);
#endif
      }
      if (!data->temp.activate1)
        GUIonMessage_SetItemDisabled(msg, TRUE);
    }

    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Progress_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    DBP_DATA *data = GetData();
    int item = GUIonMessage_GetCreatedItemIndex(msg);

    TEXTID first_text = EMPTY_TEXTID;
    TEXTID second_text = EMPTY_TEXTID;

    if (item == SUBITEM_PB_BCOLOR || item == SUBITEM_PB_FCOLOR) // Цвет фона // Цвет заполнения
    {
      uint32_t color;
      if (item == SUBITEM_PB_BCOLOR)
      {
        first_text = TEXT_COLOR_B;
        color = data->temp.color1;
      }
      else
      {
        first_text = TextID_Global(ID_COLOR_F);
        color = data->temp.color2;
      }
      snwprintf(data->buf,
                MAXELEMS(data->buf) - 1,
                L"%02X, %02X, %02X, %02X",
                COLOR_GET_R(color),
                COLOR_GET_G(color),
                COLOR_GET_B(color),
                COLOR_GET_A(color));
      second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
    }
    else
    {
      switch (item)
      {
      case SUBITEM_PB_STATE: // Отображение
        first_text = TextID_Global(ID_STATE);
        if (data->temp.activate1)
          second_text = TEXT_ON;
        else
          second_text = TEXT_OFF;
        break;
      case SUBITEM_PB_SLIDER: // Ползунок
        first_text = TextID_Global(ID_SLIDER);
        if (data->temp.activate2)
          second_text = TEXT_ON;
        else
          second_text = TEXT_OFF;
        break;
      case SUBITEM_PB_ROUND: // Закругление
        first_text = TextID_Global(ID_PTYPE);
        if (data->temp.activate3)
          second_text = TextID_Global(ID_PTYPE_2);
        else
          second_text = TextID_Global(ID_PTYPE_1);
        break;
      case SUBITEM_PB_VISUAL: // Визуальные
        first_text = TextID_Global(ID_VISUAL_CONFIG);
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"X:%d, Y:%d, W:%d, H:%d",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2 - data->temp.x1,
                  data->temp.y2 - data->temp.y1);
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        break;
      }
    }
    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Image_OnMessage(GUI_MESSAGE *msg)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    DBP_DATA *data = GetData();

    TEXTID first_text = EMPTY_TEXTID;
    TEXTID second_text = EMPTY_TEXTID;

    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case SUBITEM_IMG_STATE: // Отображение
      first_text = TextID_Global(ID_STATE);
      if (data->temp.activate1)
        second_text = TEXT_ON;
      else
        second_text = TEXT_OFF;
      break;
    case SUBITEM_IMG_VISUAL: // Визуальные
      first_text = TextID_Global(ID_VISUAL_CONFIG);
      if (setbook->is_cover_art)
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"X:%d, Y:%d, W:%d, H:%d",
                  data->temp.x1,
                  data->temp.y1,
                  data->temp.x2 - data->temp.x1,
                  data->temp.y2 - data->temp.y1);
      }
      else
      {
        snwprintf(data->buf,
                  MAXELEMS(data->buf),
                  L"X:%d, Y:%d",
                  data->temp.x1,
                  data->temp.y1);
      }
      second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
      if (!data->temp.activate1)
        GUIonMessage_SetItemDisabled(msg, TRUE);
      break;
    }

    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Background_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    DBP_DATA *data = GetData();
    int item = GUIonMessage_GetCreatedItemIndex(msg);

    TEXTID first_text = EMPTY_TEXTID;
    TEXTID second_text = EMPTY_TEXTID;

    if (item == SUBITEM_BG_TYPE)
    {
      // case 0: // Режим отображения
      first_text = TEXT_MODE;
      if (data->temp.activate1 == TYPE_IMAGE)
        second_text = TextID_Global(ID_BACKGROUND_IMAGE);
      else if (data->temp.activate1 == TYPE_THEME)
        second_text = TextID_Global(ID_BACKGROUND_THEME);
      else if (data->temp.activate1 == TYPE_COLOR)
        second_text = TextID_Global(ID_BACKGROUND_COLOR);
    }
    else if (item == SUBITEM_BG_COLOR)
    {
      // case 1: // Цвет
      first_text = TEXT_COLOR;
      uint32_t color = data->temp.color1;
      snwprintf(data->buf,
                MAXELEMS(data->buf),
                L"%02X, %02X, %02X, %02X",
                COLOR_GET_R(color),
                COLOR_GET_G(color),
                COLOR_GET_B(color),
                COLOR_GET_A(color));
      second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
      if (data->temp.activate1 == TYPE_IMAGE || data->temp.activate1 == TYPE_THEME)
        GUIonMessage_SetItemDisabled(msg, TRUE);
    }
    else if (item == SUBITEM_BG_VISUAL)
    {
      // case 2: // Визуальные
      first_text = TextID_Global(ID_VISUAL_CONFIG);
      snwprintf(data->buf,
                MAXELEMS(data->buf),
                L"%d, %d, %d, %d",
                data->temp.x1,
                data->temp.y1,
                data->temp.x2,
                data->temp.y2);
      second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
      if (data->temp.activate1 == TYPE_THEME || data->temp.activate1 == TYPE_COLOR)
        GUIonMessage_SetItemDisabled(msg, TRUE);
    }
    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

int Additional_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    DBP_DATA *data = GetData();

    TEXTID first_text = EMPTY_TEXTID;
    TEXTID second_text = EMPTY_TEXTID;

    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case SUBITEM_ADDITIONAL_1: // На весь экран
      first_text = TextID_Global(ID_FULLSCREEN);
      if (data->temp.activate1)
        second_text = TEXT_ON;
      else
        second_text = TEXT_OFF;
      break;
    case SUBITEM_ADDITIONAL_2: // Софты
      first_text = TextID_Global(ID_SOFTKEYS);
      if (data->temp.activate2)
        second_text = TEXT_ON;
      else
        second_text = TEXT_OFF;
      break;
#ifndef DB3350
    case SUBITEM_ADDITIONAL_3: // Анимация
      first_text = TEXT_ANIMATION;
      if (data->temp.activate3)
        second_text = TEXT_ON;
      else
        second_text = TEXT_OFF;
      break;
#endif
    }
    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

void Editor_OnBack(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  if (setbook->changed)
    SaveData(FALSE, setbook->element);
  FREE_GUI(setbook->sub_menu);
}

void CreateEditor(SETTING_BOOK *setbook, int type, int count)
{
  if (setbook->sub_menu = CreateListMenu(setbook, UIDisplay_Main))
  {
    if (type == EDIT_TEXT) // Текст
    {
      ListMenu_SetOnMessage(setbook->sub_menu, Text_OnMessage);
      GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Text_OnSelect);
    }
    else if (type == EDIT_SLIDER) // Прогрессбар
    {
      ListMenu_SetOnMessage(setbook->sub_menu, Progress_OnMessage);
      GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Progress_OnSelect);
    }
    else if (type == EDIT_ICON) // Обложка и рамка
    {
      ListMenu_SetOnMessage(setbook->sub_menu, Image_OnMessage);
      GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Image_OnSelect);
    }
    else if (type == EDIT_BACKGROUND) // Фон
    {
      ListMenu_SetOnMessage(setbook->sub_menu, Background_OnMessage);
      GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Background_OnSelect);
    }
    else if (type == EDIT_EXTENDED) // Дополнительно
    {
      ListMenu_SetOnMessage(setbook->sub_menu, Additional_OnMessage);
      GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Additional_OnSelect);
    }

    GUIObject_SetTitleText(setbook->sub_menu, TextID_Setting(setbook->element));
    ListMenu_SetItemCount(setbook->sub_menu, count);
    ListMenu_SetCursorToItem(setbook->sub_menu, 0);
    ListMenu_SetItemStyle(setbook->sub_menu, 3);
    GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_BACK, Editor_OnBack);
    GUIObject_Show(setbook->sub_menu);
  }
}

//******************************************************************************
//Настройки

int Setting_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, TextID_Setting(item));
  }
  return 1;
}

void Setting_OnSelect(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  int item = ListMenu_GetSelectedItem(setbook->main_menu);
  setbook->element = item;
  setbook->changed = FALSE;

  DBP_DATA *data = GetData();
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
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.artist.state;
    data->temp.align = data->setting.artist.align;
    data->temp.color1 = data->setting.artist.tcolor;
    data->temp.color2 = data->setting.artist.ocolor;
    data->temp.overlay = data->setting.artist.overlay;
    data->temp.font = data->setting.artist.font;
    data->temp.x1 = data->setting.artist.coord.x1;
    data->temp.y1 = data->setting.artist.coord.y1;
    data->temp.x2 = data->setting.artist.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_TITLE)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.title.state;
    data->temp.align = data->setting.title.align;
    data->temp.color1 = data->setting.title.tcolor;
    data->temp.color2 = data->setting.title.ocolor;
    data->temp.overlay = data->setting.title.overlay;
    data->temp.font = data->setting.title.font;
    data->temp.x1 = data->setting.title.coord.x1;
    data->temp.y1 = data->setting.title.coord.y1;
    data->temp.x2 = data->setting.title.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_ALBUM)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.album.state;
    data->temp.align = data->setting.album.align;
    data->temp.color1 = data->setting.album.tcolor;
    data->temp.color2 = data->setting.album.ocolor;
    data->temp.overlay = data->setting.album.overlay;
    data->temp.font = data->setting.album.font;
    data->temp.x1 = data->setting.album.coord.x1;
    data->temp.y1 = data->setting.album.coord.y1;
    data->temp.x2 = data->setting.album.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_YEAR)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.year.state;
    data->temp.align = data->setting.year.align;
    data->temp.color1 = data->setting.year.tcolor;
    data->temp.color2 = data->setting.year.ocolor;
    data->temp.overlay = data->setting.year.overlay;
    data->temp.font = data->setting.year.font;
    data->temp.x1 = data->setting.year.coord.x1;
    data->temp.y1 = data->setting.year.coord.y1;
    data->temp.x2 = data->setting.year.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_GENRE)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.genre.state;
    data->temp.align = data->setting.genre.align;
    data->temp.color1 = data->setting.genre.tcolor;
    data->temp.color2 = data->setting.genre.ocolor;
    data->temp.overlay = data->setting.genre.overlay;
    data->temp.font = data->setting.genre.font;
    data->temp.x1 = data->setting.genre.coord.x1;
    data->temp.y1 = data->setting.genre.coord.y1;
    data->temp.x2 = data->setting.genre.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_FILEFORMAT)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.ext.state;
    data->temp.align = data->setting.ext.align;
    data->temp.color1 = data->setting.ext.tcolor;
    data->temp.color2 = data->setting.ext.ocolor;
    data->temp.overlay = data->setting.ext.overlay;
    data->temp.font = data->setting.ext.font;
    data->temp.x1 = data->setting.ext.coord.x1;
    data->temp.y1 = data->setting.ext.coord.y1;
    data->temp.x2 = data->setting.ext.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_TOTAL)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.time_t.state;
    data->temp.align = data->setting.time_t.align;
    data->temp.color1 = data->setting.time_t.tcolor;
    data->temp.color2 = data->setting.time_t.ocolor;
    data->temp.overlay = data->setting.time_t.overlay;
    data->temp.font = data->setting.time_t.font;
    data->temp.x1 = data->setting.time_t.coord.x1;
    data->temp.y1 = data->setting.time_t.coord.y1;
    data->temp.x2 = data->setting.time_t.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_ELAPSED)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.time_e.state;
    data->temp.align = data->setting.time_e.align;
    data->temp.color1 = data->setting.time_e.tcolor;
    data->temp.color2 = data->setting.time_e.ocolor;
    data->temp.overlay = data->setting.time_e.overlay;
    data->temp.font = data->setting.time_e.font;
    data->temp.x1 = data->setting.time_e.coord.x1;
    data->temp.y1 = data->setting.time_e.coord.y1;
    data->temp.x2 = data->setting.time_e.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_REMAINING)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.time_r.state;
    data->temp.align = data->setting.time_r.align;
    data->temp.color1 = data->setting.time_r.tcolor;
    data->temp.color2 = data->setting.time_r.ocolor;
    data->temp.overlay = data->setting.time_r.overlay;
    data->temp.font = data->setting.time_r.font;
    data->temp.x1 = data->setting.time_r.coord.x1;
    data->temp.y1 = data->setting.time_r.coord.y1;
    data->temp.x2 = data->setting.time_r.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_BITRATE)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.bitrate.state;
    data->temp.align = data->setting.bitrate.align;
    data->temp.color1 = data->setting.bitrate.tcolor;
    data->temp.color2 = data->setting.bitrate.ocolor;
    data->temp.overlay = data->setting.bitrate.overlay;
    data->temp.font = data->setting.bitrate.font;
    data->temp.x1 = data->setting.bitrate.coord.x1;
    data->temp.y1 = data->setting.bitrate.coord.y1;
    data->temp.x2 = data->setting.bitrate.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_SAMPLERATE)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.samplerate.state;
    data->temp.align = data->setting.samplerate.align;
    data->temp.color1 = data->setting.samplerate.tcolor;
    data->temp.color2 = data->setting.samplerate.ocolor;
    data->temp.overlay = data->setting.samplerate.overlay;
    data->temp.font = data->setting.samplerate.font;
    data->temp.x1 = data->setting.samplerate.coord.x1;
    data->temp.y1 = data->setting.samplerate.coord.y1;
    data->temp.x2 = data->setting.samplerate.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_AUDIOOUTPUT)
  {
    setbook->elem_type = ELEM_TEXT;
    data->temp.activate1 = data->setting.audiooutput.state;
    data->temp.align = data->setting.audiooutput.align;
    data->temp.color1 = data->setting.audiooutput.tcolor;
    data->temp.color2 = data->setting.audiooutput.ocolor;
    data->temp.overlay = data->setting.audiooutput.overlay;
    data->temp.font = data->setting.audiooutput.font;
    data->temp.x1 = data->setting.audiooutput.coord.x1;
    data->temp.y1 = data->setting.audiooutput.coord.y1;
    data->temp.x2 = data->setting.audiooutput.coord.x2;
    CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_TIME_PROGRESS)
  {
    setbook->elem_type = ELEM_RECT;
    data->temp.activate1 = data->setting.time.state;
    data->temp.activate2 = data->setting.time.slider;
    data->temp.activate3 = data->setting.time.round;
    data->temp.color1 = data->setting.time.progress_bcolor;
    data->temp.color2 = data->setting.time.progress_fcolor;
    data->temp.x1 = data->setting.time.progress_rect.x1;
    data->temp.y1 = data->setting.time.progress_rect.y1;
    data->temp.x2 = data->setting.time.progress_rect.x2;
    data->temp.y2 = data->setting.time.progress_rect.y2;
    CreateEditor(setbook, EDIT_SLIDER, SUBITEM_PB_LAST);
  }
  else if (item == ITEM_VOLUME_PROGRESS)
  {
    setbook->elem_type = ELEM_RECT;
    data->temp.activate1 = data->setting.volume.state;
    data->temp.activate2 = data->setting.volume.slider;
    data->temp.activate3 = data->setting.volume.round;
    data->temp.color1 = data->setting.volume.progress_bcolor;
    data->temp.color2 = data->setting.volume.progress_fcolor;
    data->temp.x1 = data->setting.volume.progress_rect.x1;
    data->temp.y1 = data->setting.volume.progress_rect.y1;
    data->temp.x2 = data->setting.volume.progress_rect.x2;
    data->temp.y2 = data->setting.volume.progress_rect.y2;
    CreateEditor(setbook, EDIT_SLIDER, SUBITEM_PB_LAST);
  }
  else if (item == ITEM_COVERART)
  {
    setbook->elem_type = ELEM_RECT;
    setbook->is_cover_art = TRUE;
    data->temp.activate1 = data->setting.cover;
    data->temp.x1 = data->setting.cover_rect.x1;
    data->temp.y1 = data->setting.cover_rect.y1;
    data->temp.x2 = data->setting.cover_rect.x2;
    data->temp.y2 = data->setting.cover_rect.y2;
    CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_FRAME)
  {
    setbook->elem_type = ELEM_ICON;
    setbook->is_cover_art = FALSE;
    data->temp.activate1 = data->setting.frame.state;
    data->temp.x1 = data->setting.frame.pos.x;
    data->temp.y1 = data->setting.frame.pos.y,
    CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_ARTIST_ICN)
  {
    setbook->elem_type = ELEM_ICON;
    setbook->is_cover_art = FALSE;
    data->temp.activate1 = data->setting.artist_icn.state;
    data->temp.x1 = data->setting.artist_icn.pos.x;
    data->temp.y1 = data->setting.artist_icn.pos.y,
    CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_TITLE_ICN)
  {
    setbook->elem_type = ELEM_ICON;
    setbook->is_cover_art = FALSE;
    data->temp.activate1 = data->setting.title_icn.state;
    data->temp.x1 = data->setting.title_icn.pos.x;
    data->temp.y1 = data->setting.title_icn.pos.y,
    CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_ALBUM_ICN)
  {
    setbook->elem_type = ELEM_ICON;
    setbook->is_cover_art = FALSE;
    data->temp.activate1 = data->setting.album_icn.state;
    data->temp.x1 = data->setting.album_icn.pos.x;
    data->temp.y1 = data->setting.album_icn.pos.y,
    CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_PLAYERSTATE_ICN)
  {
    setbook->elem_type = ELEM_ICON;
    setbook->is_cover_art = FALSE;
    data->temp.activate1 = data->setting.playerstate_icn.state;
    data->temp.x1 = data->setting.playerstate_icn.pos.x;
    data->temp.y1 = data->setting.playerstate_icn.pos.y,
    CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_BACKROUND)
  {
    setbook->elem_type = ELEM_ICON;
    setbook->is_cover_art = FALSE;
    data->temp.activate1 = data->setting.background.state;
    data->temp.color1 = data->setting.background_color;
    data->temp.x1 = data->setting.background.pos.x;
    data->temp.y1 = data->setting.background.pos.y;
    CreateEditor(setbook, EDIT_BACKGROUND, SUBITEM_BG_LAST);
  }
  else if (item == ITEM_ADDITIONAL)
  {
    data->temp.activate1 = data->setting.screen;
    data->temp.activate2 = data->setting.soft;
#ifndef DB3350
    data->temp.activate3 = data->setting.animation;
#endif
    CreateEditor(setbook, EDIT_EXTENDED, SUBITEM_ADDITIONAL_LAST);
  }
}

void Question_OnYes(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  SaveData(TRUE, setbook->element);
  FreeBook(setbook);

  DBP_DATA *data = GetData();
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

void Question_OnNo(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  DBP_DATA *Data = GetData();
  LoadData(Data);
  FreeBook(setbook);
}

void Question_OnBack(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  FREE_GUI(setbook->question_menu);
}

void Setting_OnBack(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  if (setbook->changed)
  {
    if (setbook->question_menu = CreateYesNoQuestion(setbook, UIDisplay_Main))
    {
      YesNoQuestion_SetDescriptionText(setbook->question_menu, TEXT_CHANGE);
      YesNoQuestion_SetQuestionText(setbook->question_menu, TEXT_QUESTION);
      YesNoQuestion_SetIcon(setbook->question_menu, POPUP_WARNING_ICN);
      GUIObject_SoftKeys_SetAction(setbook->question_menu, ACTION_YES, Question_OnYes);
      GUIObject_SoftKeys_SetAction(setbook->question_menu, ACTION_NO, Question_OnNo);
      GUIObject_SoftKeys_SetAction(setbook->question_menu, ACTION_BACK, Question_OnBack);
      GUIObject_Show(setbook->question_menu);
    }
  }
  else
  {
    FreeBook(setbook);
  }
}

int DBPlayer_Settings_onEnter(void *data, BOOK *book)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  if (setbook->main_menu = CreateListMenu(setbook, UIDisplay_Main))
  {
    GUIObject_SetTitleText(setbook->main_menu, TEXT_SETTINGS);
    ListMenu_SetItemCount(setbook->main_menu, ITEM_LAST);
    ListMenu_SetOnMessage(setbook->main_menu, Setting_OnMessage);
    ListMenu_SetCursorToItem(setbook->main_menu, 0);
    ListMenu_SetItemStyle(setbook->main_menu, 0);
    GUIObject_SoftKeys_SetAction(setbook->main_menu, ACTION_SELECT1, Setting_OnSelect);
    GUIObject_SoftKeys_SetAction(setbook->main_menu, ACTION_BACK, Setting_OnBack);
    GUIObject_Show(setbook->main_menu);
  }
  return 1;
}

int DBPlayer_Settings_onExit(void *data, BOOK *book)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  FREE_GUI(setbook->main_menu);
  FREE_GUI(setbook->sub_menu);
  FREE_GUI(setbook->options_menu);
  FREE_GUI(setbook->question_menu);
  return 1;
}

int DBPlayer_Settings_onPrev(void *data, BOOK *book)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  BookObj_ReturnPage(setbook, PREVIOUS_EVENT);
  return 1;
}

int DBPlayer_Settings_onCancel(void *data, BOOK *book)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  BookObj_ReturnPage(setbook, CANCEL_EVENT);
  return 1;
}

void SettingBook_onClose(BOOK *book)
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)book;
  FREE_GUI(setbook->main_menu);
  FREE_GUI(setbook->sub_menu);
  FREE_GUI(setbook->options_menu);
  FREE_GUI(setbook->question_menu);
  setbook->element = NULL;
  setbook->elem_type = NULL;
  setbook->changed = NULL;
  setbook->is_cover_art = NULL;
}

SETTING_BOOK *Create_DBPlayer_SettingBook()
{
  SETTING_BOOK *setbook = (SETTING_BOOK *)malloc(sizeof(SETTING_BOOK));
  memset(setbook, NULL, sizeof(SETTING_BOOK));
  if (!CreateBook(setbook, SettingBook_onClose, &DBPlayer_Settings_Base_Page, "DBPlayer_SettingBook", NO_BOOK_ID, NULL))
  {
    mfree(setbook);
    return NULL;
  }
  setbook->main_menu = NULL;
  setbook->sub_menu = NULL;
  setbook->options_menu = NULL;
  setbook->question_menu = NULL;
  setbook->color_picker = NULL;

  setbook->element = NULL;
  setbook->elem_type = NULL;
  setbook->changed = NULL;
  setbook->is_cover_art = NULL;
  return setbook;
}

void DBPlayer_Setting(BOOK *book, GUI *gui)
{
  SETTING_BOOK *setbook = Create_DBPlayer_SettingBook();
  if (setbook)
    BookObj_GotoPage(setbook, &DBPlayer_Settings_Main_Page);
}
