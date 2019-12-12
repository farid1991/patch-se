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
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(FMSettings_Book->SubMenu);
  
  switch(item)
  {
  case SUBITEM_TXT_STATE:   OneOfMany_SetMode(FMSettings_Book, OOM_STATE); break;
  case SUBITEM_TXT_COLOR:   SetColor(FMSettings_Book, 1); break;
  case SUBITEM_TXT_OVERLAY: SetColor(FMSettings_Book, 2); break;
  case SUBITEM_TXT_ALIGN:   OneOfMany_SetMode(FMSettings_Book, OOM_ALIGN); break;
  case SUBITEM_TXT_VISUAL:  SetVisual(FMSettings_Book); break;
  }
}

void Progress_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(FMSettings_Book->SubMenu);
  
  switch(item)
  {
  case SUBITEM_PB_STATE:  SetActivate(FMSettings_Book,SUBITEM_PB_LAST); break;
  case SUBITEM_PB_SLIDER: SetActivate(FMSettings_Book,SUBITEM_PB_LAST); break;
  case SUBITEM_PB_ROUND:  SetActivate(FMSettings_Book,SUBITEM_PB_LAST); break;
  case SUBITEM_PB_BCOLOR: SetColor(FMSettings_Book, 1); break;
  case SUBITEM_PB_FCOLOR: SetColor(FMSettings_Book, 2); break;
  case SUBITEM_PB_VISUAL: SetVisual(FMSettings_Book); break;
  }
}

void Image_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(FMSettings_Book->SubMenu);
  switch(item)
  {
  case SUBITEM_IMG_STATE:   SetActivate(FMSettings_Book, SUBITEM_IMG_LAST); break;
  case SUBITEM_IMG_VISUAL:  SetVisual(FMSettings_Book); break;
  }
}

int Text_OnMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
    case LISTMSG_GetItem:
      FmRadio_Data* data = GetData();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text;
      TEXTID second_text;
      
      if (item == 0)
      {
        first_text = TextID_Global(ID_SHOW);
        if (data->temp.state) second_text = TEXT_ON;
        else second_text = TEXT_OFF;
      }
      else
      {
        if (item == 1 || item == 2)
        {
          color_t color;
          if (item == 1)
          {
            first_text = TEXT_COLOR_TEXT;
            color = data->temp.color1;
          }
          else
          {
            first_text = TextID_Global(ID_COLOR_OVERLAY);
            color = data->temp.color2;
          }
          snwprintf(data->buf, 
                    MAXELEMS(data->buf), 
                    L"%02X, %02X, %02X, %02X", 
                    COLOR_GET_R(color), 
                    COLOR_GET_G(color), 
                    COLOR_GET_B(color), 
                    COLOR_GET_A(color));
          second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        }
        else if (item == 3)
        {
          first_text = TextID_Global(ID_ALIGN);
          if (data->temp.align == 0) second_text = TEXT_LEFT;
          else if (data->temp.align == 1) second_text = TEXT_RIGHT;
          else if (data->temp.align == 2) second_text = TEXT_CENTRE;
        }
        else if (item == 4)
        {
          first_text = TextID_Global(ID_VISUAL);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
          int font_size = (data->cur_pos+1)*font_step + (data->style_bold<<8) + (data->style_italic<<9); //data->temp.font&0xFF;
          int style = font_size >> 8; //data->temp.font>>8;
          if (style == 0) 
          {
            snwprintf(data->buf, 
                      MAXELEMS(data->buf), 
                      L"%d,%d,%d,%d font:%d", 
                      data->temp.x1, 
                      data->temp.y1, 
                      data->temp.x2, 
                      data->temp.y1 + font_size, 
                      font_size);
          }
          else if (style == 1) 
          {
            snwprintf(data->buf, 
                      MAXELEMS(data->buf), 
                      L"%d,%d,%d,%d font:%d_B", 
                      data->temp.x1, 
                      data->temp.y1, 
                      data->temp.x2, 
                      data->temp.y1 + font_size&0xFF, 
                      font_size&0xFF);
          }
          else if (style == 2)
          {
            snwprintf(data->buf, 
                      MAXELEMS(data->buf), 
                      L"%d,%d,%d,%d font:%d_I", 
                      data->temp.x1, 
                      data->temp.y1, 
                      data->temp.x2, 
                      data->temp.y1 + font_size&0xFF, 
                      font_size&0xFF);
          }
          else if (style == 3) 
          {
            snwprintf(data->buf, 
                      MAXELEMS(data->buf), 
                      L"%d,%d,%d,%d font:%d_B_I", 
                      data->temp.x1, 
                      data->temp.y1, 
                      data->temp.x2, 
                      data->temp.y1 + font_size&0xFF, 
                      font_size&0xFF);
          }
#else 
          snwprintf(data->buf, 
                    MAXELEMS(data->buf), L"%d,%d,%d,%d font:%ls", 
                    data->temp.x1, 
                    data->temp.y1, 
                    data->temp.x2,
                    data->temp.y2, 
                    Font_GetNameByFontId(data->temp.font));
#endif
          second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        }
        if (!data->temp.state) GUIonMessage_SetItemDisabled(msg, TRUE);
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
      FmRadio_Data* data = GetData();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text;
      TEXTID second_text;
      
      if (item == 3 || item == 4)
      {
        unsigned int color;
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
        snwprintf(data->buf, 
                  MAXELEMS(data->buf), 
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
        case 0:
          first_text = TextID_Global(ID_SHOW);
          if (data->temp.state) second_text = TEXT_ON;
          else second_text = TEXT_OFF;
          break;
        case 1:
          first_text = TextID_Global(ID_SLIDER);
          if (data->temp.slider) second_text = TEXT_ON;
          else second_text = TEXT_OFF;
          break;
        case 2:
          first_text = TEXT_PTYPE;
          if (data->temp.round) second_text = TextID_Global(ID_PTYPE_2);
          else second_text = TextID_Global(ID_PTYPE_1);
          break;
        case 5:
          first_text = TextID_Global(ID_VISUAL);
          snwprintf(data->buf, 
                    MAXELEMS(data->buf), 
                    L"X:%d, Y:%d, W:%d, H:%d", 
                    data->temp.x1, 
                    data->temp.y1, 
                    data->temp.x2-data->temp.x1, 
                    data->temp.y2-data->temp.y1);
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
      FmRadio_Data* data = GetData();
      int item = GUIonMessage_GetCreatedItemIndex(msg);
      
      TEXTID first_text;
      TEXTID second_text;
      
      switch (item)
      {
      case 0:
        first_text = TextID_Global(ID_SHOW);
        if (data->temp.state) 
        {
          second_text = TEXT_ON;
        }
        else 
        {
          second_text = TEXT_OFF;
        }
        break;
      case 1:
        first_text = TextID_Global(ID_VISUAL);
        snwprintf(data->buf,
                  MAXELEMS(data->buf), 
                  L"X:%d, Y:%d", 
                  data->temp.x1, 
                  data->temp.y1);
        second_text = TextID_Create(data->buf, ENC_UCS2, TEXTID_ANY_LEN);
        if (!data->temp.state) GUIonMessage_SetItemDisabled(msg, TRUE);
        break;
      }
      
      GUIonMessage_SetMenuItemText(msg, first_text);
      GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

void Editor_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  if (FMSettings_Book->changed) SaveData(FALSE, FMSettings_Book->element);
  FREE_GUI (FMSettings_Book->SubMenu);
}

void CreateEditor(FmRadio_Data* data, SETTING_BOOK* FMSettings_Book, int SubItemCount)
{
  FMSettings_Book->SubMenu = CreateListMenu(FMSettings_Book, UIDisplay_Main);

  char type = FMSettings_Book->elem_type;
  if (type == ELEM_TEXT)
  {
    ListMenu_SetOnMessage(FMSettings_Book->SubMenu, Text_OnMessage);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->SubMenu, ACTION_SELECT1, Text_OnSelect);
  }
  else if (type == ELEM_RECT)
  {
    ListMenu_SetOnMessage(FMSettings_Book->SubMenu, Progress_OnMessage);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->SubMenu, ACTION_SELECT1, Progress_OnSelect);
  }
  else if (type == ELEM_ICON)
  {
    ListMenu_SetOnMessage(FMSettings_Book->SubMenu, Image_OnMessage);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->SubMenu, ACTION_SELECT1, Image_OnSelect);
  }
  
  GUIObject_SetTitleText(FMSettings_Book->SubMenu, TextID_Setting(FMSettings_Book->element));
  ListMenu_SetItemCount(FMSettings_Book->SubMenu, SubItemCount);
  ListMenu_SetCursorToItem(FMSettings_Book->SubMenu, 0);
  ListMenu_SetItemStyle(FMSettings_Book->SubMenu, 3);
  GUIObject_SoftKeys_SetAction(FMSettings_Book->SubMenu, ACTION_BACK, Editor_OnBack);
  GUIObject_SoftKeys_SetAction(FMSettings_Book->SubMenu, ACTION_LONG_BACK, Editor_OnBack);
  GUIObject_Show(FMSettings_Book->SubMenu);
}

//******************************************************************************

int Settings_OnMessage(GUI_MESSAGE* msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, TextID_Setting(item));
  }
  return 1;
}

void Settings_OnSelect(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  int item = ListMenu_GetSelectedItem(FMSettings_Book->MainMenu);
  FMSettings_Book->element = item;
  FMSettings_Book->changed = FALSE;
  
  FmRadio_Data* data = GetData();
  memset(&data->temp, NULL, sizeof(TEMP_DATA));

  if (item == ITEM_FREQUENCY)
  {
    FMSettings_Book->elem_type = ELEM_TEXT;
    data->temp.state = data->setting.frequency.state;
    data->temp.align = data->setting.frequency.align;
    data->temp.color1 = data->setting.frequency.text_color;
    data->temp.color2 = data->setting.frequency.ocolor;
    data->temp.overlay = data->setting.frequency.overlay;
    data->temp.font = data->setting.frequency.font;
    data->temp.x1 = data->setting.frequency.coord.x1;
    data->temp.y1 = data->setting.frequency.coord.y1;
    data->temp.x2 = data->setting.frequency.coord.x2;
    CreateEditor(data, FMSettings_Book, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_CHANNEL)
  {
    FMSettings_Book->elem_type = ELEM_TEXT;
    data->temp.state = data->setting.channel.state;
    data->temp.align = data->setting.channel.align;
    data->temp.color1 = data->setting.channel.text_color;
    data->temp.color2 = data->setting.channel.ocolor;
    data->temp.overlay = data->setting.channel.overlay;
    data->temp.font = data->setting.channel.font;
    data->temp.x1 = data->setting.channel.coord.x1;
    data->temp.y1 = data->setting.channel.coord.y1;
    data->temp.x2 = data->setting.channel.coord.x2;
    CreateEditor(data, FMSettings_Book, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_CHANNELNAME)
  {
    FMSettings_Book->elem_type = ELEM_TEXT;
    data->temp.state = data->setting.channel_name.state;
    data->temp.align = data->setting.channel_name.align;
    data->temp.color1 = data->setting.channel_name.text_color;
    data->temp.color2 = data->setting.channel_name.ocolor;
    data->temp.overlay = data->setting.channel_name.overlay;
    data->temp.font = data->setting.channel_name.font;
    data->temp.x1 = data->setting.channel_name.coord.x1;
    data->temp.y1 = data->setting.channel_name.coord.y1;
    data->temp.x2 = data->setting.channel_name.coord.x2;
    CreateEditor(data, FMSettings_Book, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_RDS_DATA)
  {
    FMSettings_Book->elem_type = ELEM_TEXT;
    data->temp.state = data->setting.RDS_data.state;
    data->temp.align = data->setting.RDS_data.align;
    data->temp.color1 = data->setting.RDS_data.text_color;
    data->temp.color2 = data->setting.RDS_data.ocolor;
    data->temp.overlay = data->setting.RDS_data.overlay;
    data->temp.font = data->setting.RDS_data.font;
    data->temp.x1 = data->setting.RDS_data.coord.x1;
    data->temp.y1 = data->setting.RDS_data.coord.y1;
    data->temp.x2 = data->setting.RDS_data.coord.x2;
    CreateEditor(data, FMSettings_Book, SUBITEM_TXT_LAST);
  }
  else if (item == ITEM_FREQ_INDICATOR)
  {
    FMSettings_Book->elem_type = ELEM_RECT;
    data->temp.state = data->setting.freq_indicator.state;
    data->temp.slider = data->setting.freq_indicator.slider;
    data->temp.round = data->setting.freq_indicator.round;
    data->temp.color1 = data->setting.freq_indicator.progress_bcolor;
    data->temp.color2 = data->setting.freq_indicator.progress_fcolor;
    data->temp.x1 = data->setting.freq_indicator.progress_rect.x1;
    data->temp.y1 = data->setting.freq_indicator.progress_rect.y1;
    data->temp.x2 = data->setting.freq_indicator.progress_rect.x2;
    data->temp.y2 = data->setting.freq_indicator.progress_rect.y2;
    CreateEditor(data, FMSettings_Book, SUBITEM_PB_LAST);
  }
  
  else if (item == ITEM_RDS_ICN)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.rds_icn.state;
    data->temp.x1 = data->setting.rds_icn.pos.x;
    data->temp.y1 = data->setting.rds_icn.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_AF_ICN)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.af_icn.state;
    data->temp.x1 = data->setting.af_icn.pos.x;
    data->temp.y1 = data->setting.af_icn.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_AUDIO_ICN)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.audio_icn.state;
    data->temp.x1 = data->setting.audio_icn.pos.x;
    data->temp.y1 = data->setting.audio_icn.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_ARROW_LEFT)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.arrow_left.state;
    data->temp.x1 = data->setting.arrow_left.pos.x;
    data->temp.y1 = data->setting.arrow_left.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_ARROW_RIGHT)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.arrow_right.state;
    data->temp.x1 = data->setting.arrow_right.pos.x;
    data->temp.y1 = data->setting.arrow_right.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_ARROW_UP)
  {
    data->temp.state = data->setting.arrow_up.state;
    data->temp.x1 = data->setting.arrow_up.pos.x;
    data->temp.y1 = data->setting.arrow_up.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_ARROW_DOWN)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.arrow_down.state;
    data->temp.x1 = data->setting.arrow_down.pos.x;
    data->temp.y1 = data->setting.arrow_down.pos.y,
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
  else if (item == ITEM_BACKROUND)
  {
    FMSettings_Book->elem_type = ELEM_ICON;
    data->temp.state = data->setting.background.state;
    data->temp.x1 = data->setting.background.pos.x;
    data->temp.y1 = data->setting.background.pos.y;
    CreateEditor(data, FMSettings_Book, SUBITEM_IMG_LAST);
  }
}

void Question_OnYes(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  SaveData(TRUE, FMSettings_Book->element);
  FmRadio_Data* data = GetData();
  LoadData(data);
  
  FreeBook(FMSettings_Book);
  
  if(data->DispObj_FmRadio) DispObject_InvalidateRect(data->DispObj_FmRadio,NULL);
}

void Question_OnNo(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FmRadio_Data* data = GetData();
  LoadData(data);
  
  FreeBook(FMSettings_Book);
  
  if(data->DispObj_FmRadio) DispObject_InvalidateRect(data->DispObj_FmRadio,NULL);
}

void Question_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FREE_GUI(FMSettings_Book->gui_question);
}

void Settings_OnBack(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  if (FMSettings_Book->changed)
  {
    FMSettings_Book->gui_question = CreateYesNoQuestion(book, UIDisplay_Main);
    YesNoQuestion_SetDescriptionText(FMSettings_Book->gui_question, TEXT_CHANGE);
    YesNoQuestion_SetQuestionText(FMSettings_Book->gui_question, TEXT_QUESTION);
    YesNoQuestion_SetIcon(FMSettings_Book->gui_question, POPUP_WARNING_ICN);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->gui_question, ACTION_YES, Question_OnYes);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->gui_question, ACTION_NO, Question_OnNo);
    GUIObject_SoftKeys_SetAction(FMSettings_Book->gui_question, ACTION_BACK, Question_OnBack);
    GUIObject_Show(FMSettings_Book->gui_question);
  }
  else FreeBook(FMSettings_Book);
}

int pg_FmRadio_Settings_EnterAction(void* data, BOOK* book)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  FMSettings_Book->MainMenu = CreateListMenu(FMSettings_Book, UIDisplay_Main);
  GUIObject_SetTitleText(FMSettings_Book->MainMenu, TEXT_LAYOUT);
  ListMenu_SetItemCount(FMSettings_Book->MainMenu, ITEM_LAST);
  ListMenu_SetOnMessage(FMSettings_Book->MainMenu, Settings_OnMessage);
  ListMenu_SetCursorToItem(FMSettings_Book->MainMenu, 0);
  ListMenu_SetItemStyle(FMSettings_Book->MainMenu, 0);
  GUIObject_SoftKeys_SetAction(FMSettings_Book->MainMenu, ACTION_SELECT1, Settings_OnSelect);
  GUIObject_SoftKeys_SetAction(FMSettings_Book->MainMenu, ACTION_BACK, Settings_OnBack);
  GUIObject_SoftKeys_SetAction(FMSettings_Book->MainMenu, ACTION_LONG_BACK, Settings_OnBack);
  GUIObject_Show(FMSettings_Book->MainMenu);
  return 1;
}

int pg_FmRadio_Settings_ExitAction(void* data, BOOK* book)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  
  FREE_GUI (FMSettings_Book->MainMenu);
  FREE_GUI (FMSettings_Book->SubMenu);
  FREE_GUI (FMSettings_Book->gui_question);
  FREE_GUI (FMSettings_Book->OptionMenu);
  FREE_GUI (FMSettings_Book->ColorPicker);
  
  return 1;
}

int pg_FmRadio_Settings_PreviousAction(void* data, BOOK* book)
{
  BookObj_ReturnPage(book,CANCEL_EVENT);
  return 1;
}

//******************************************************************************

int pg_FmRadio_Settings_CancelAction(void* data, BOOK* book)
{
  FreeBook(book);
  return 1;
}

const PAGE_MSG base_evlist[] =
{
  RETURN_TO_STANDBY_EVENT,  pg_FmRadio_Settings_CancelAction,
  NIL_EVENT,                NULL
};

const PAGE_MSG main_evlist[] =
{
  PAGE_ENTER_EVENT, pg_FmRadio_Settings_EnterAction,
  PAGE_EXIT_EVENT,  pg_FmRadio_Settings_ExitAction,
  PREVIOUS_EVENT,   pg_FmRadio_Settings_PreviousAction,
  CANCEL_EVENT,     pg_FmRadio_Settings_CancelAction,
  NIL_EVENT,        NULL
};

const PAGE_DESC FmRadio_Settings_Base_Page = {"FmRadio_Layout_Base_Page", NULL, base_evlist};
const PAGE_DESC FmRadio_Settings_Main_Page = {"FmRadio_Layout_Main_Page", NULL, main_evlist};

void SettingBook_onClose(BOOK* book)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)book;
  
  FREE_GUI (FMSettings_Book->MainMenu);
  FREE_GUI (FMSettings_Book->SubMenu);
  FREE_GUI (FMSettings_Book->gui_question);
  FREE_GUI (FMSettings_Book->OptionMenu);
  FREE_GUI (FMSettings_Book->ColorPicker);
}

void FmRadio_LayoutSetting(BOOK* book, GUI* gui)
{
  SETTING_BOOK* FMSettings_Book = (SETTING_BOOK*)malloc(sizeof(SETTING_BOOK));
  memset(FMSettings_Book, NULL, sizeof(SETTING_BOOK));
  if(CreateBook(FMSettings_Book, SettingBook_onClose, &FmRadio_Settings_Base_Page, "FmRadio_LayoutSettingBook", -1, 0))
  {
    BookObj_GotoPage(FMSettings_Book, &FmRadio_Settings_Main_Page);
  }
  else 
  {
    mfree(FMSettings_Book);
  }
}

extern "C"
void FmRadio_NewSoftKey(GUI* gui)
{
  GUIObject_SoftKeys_SetActionAndText(gui, FMRADIO_ACTION_LAYOUT, FmRadio_LayoutSetting, TEXT_LAYOUT);
}
