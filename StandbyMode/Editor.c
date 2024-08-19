#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"

#include "dll.h"
#include "Data.h"
#include "Editor.h"
#include "EditColor.h"
#include "LNG.h"
#include "main.h"

TEXTID TextID_Setting(int item_id)
{
  switch (item_id)
  {
  case ITEM_Statusbar:
    return STR(STATUS_CFG_NAME);
  case ITEM_NetworkIcon:
    return STR(NET_ICN_CFG_NAME);
  case ITEM_BatteryIcon:
    return STR(BATT_ICN_CFG_NAME);
  case ITEM_MusicWidget:
    return STR(MUSIC_CFG_NAME);
  case ITEM_StandbyClock:
    return STR(TIME_CFG_NAME);
  case ITEM_StatusClock:
    return STR(TIME2_CFG_NAME);
  case ITEM_Date:
    return STR(DATE_CFG_NAME);
  case ITEM_Weekday:
    return STR(WEEKDAY_CFG_NAME);
  case ITEM_Alarm:
    return STR(ALARM_CFG_NAME);
  case ITEM_Profile:
    return STR(PROFILE_CFG_NAME);
  case ITEM_Heap:
    return STR(HEAP_CFG_NAME);
  case ITEM_Timer:
    return STR(TIMER_CFG_NAME);
  case ITEM_Call:
    return STR(CALL_CFG_NAME);
  case ITEM_Signal:
    return STR(SIGNAL_CFG_NAME);
  case ITEM_NetworkName:
    return STR(NETWORK_CFG_NAME);
  case ITEM_Batt:
    return STR(BATT_CFG_NAME);
  case ITEM_Charge:
    return STR(CHARGE_CFG_NAME);
  case ITEM_Batttemp:
    return STR(BATTTEMP_CFG_NAME);
  case ITEM_Systemp:
    return STR(SYSTEMP_CFG_NAME);
  case ITEM_Phone:
    return STR(PHONE_CFG_NAME);
  case ITEM_Card:
    return STR(CARD_CFG_NAME);
  case ITEM_Radio:
    return STR(RADIO_CFG_NAME);
  }
  return EMPTY_TEXTID;
}

//==============================================================================

void Editor_SetVisual(BOOK *book)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  STANDBY_DATA *standby_data = Get_StandbyData();
  standby_data->edit_visual = TRUE;
  standby_data->selected_item = SBYSettings_Book->selected_item;

  if (SBYSettings_Book->item_type == ItemText)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    standby_data->total_fonts = MAX_SIZE / FONT_STEP;
    standby_data->cur_pos = ((standby_data->temp.font_size & 0xFF) / FONT_STEP) - 1;
    int style_flags = standby_data->temp.font_size >> 8;
    standby_data->style_bold = (style_flags & BOLD);
    standby_data->style_italic = (style_flags & ITALIC) >> 1;
#endif
    standby_data->edit_text = TRUE;
    standby_data->edit_icon = FALSE;
    standby_data->edit_status = FALSE;
  }
  else if (SBYSettings_Book->item_type == ItemStandartIcon)
  {
    standby_data->edit_text = FALSE;
    standby_data->edit_icon = TRUE;
    standby_data->edit_status = FALSE;
  }
  else
  {
    standby_data->edit_text = FALSE;
    standby_data->edit_icon = FALSE;
    standby_data->edit_status = TRUE;
  }

  FreeBook(SBYSettings_Book);
}

//==============================================================================

void Refresh_SubMenu(BOOK *book, int count)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  ListMenu_DestroyItems(SBYSettings_Book->SubMenu);
  ListMenu_SetItemCount(SBYSettings_Book->SubMenu, count);
  ListMenu_SetCursorToItem(SBYSettings_Book->SubMenu, SBYSettings_Book->selected_subitem);
  GUIObject_SoftKeys_SetVisible(SBYSettings_Book->SubMenu, ACTION_SELECT1, TRUE);
  SBYSettings_Book->changed = TRUE;
}

void Editor_onSetEnabled(BOOK *book, int count)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  STANDBY_DATA *standby_data = Get_StandbyData();

  TEXTID TXT;
  if (standby_data->temp.state)
  {
    standby_data->temp.state = FALSE;
    TXT = TEXTID_OFF;
  }
  else
  {
    standby_data->temp.state = TRUE;
    TXT = TEXTID_ON;
  }
  Refresh_SubMenu(SBYSettings_Book, count);
  ListMenu_SetItemSecondLineText(SBYSettings_Book->SubMenu, SBYSettings_Book->selected_subitem, TXT);
  SBYSettings_Book->changed = TRUE;
}

void Editor_onSetMode(BOOK *book, int count)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  STANDBY_DATA *standby_data = Get_StandbyData();

  TEXTID TXT;
  if (standby_data->temp.mode)
  {
    standby_data->temp.mode = 0;
    TXT = STR("Mode 1");
  }
  else
  {
    standby_data->temp.mode = 1;
    TXT = STR("Mode 2");
  }
  Refresh_SubMenu(SBYSettings_Book, count);
  ListMenu_SetItemSecondLineText(SBYSettings_Book->SubMenu, SBYSettings_Book->selected_subitem, TXT);
  SBYSettings_Book->changed = TRUE;
}

TEXTID Get_TextID_Color(int color)
{
  wchar_t ustr[32];
  snwprintf(ustr, MAXELEMS(ustr), L"%X, %X, %X, %X", COLOR_GET_R(color), COLOR_GET_G(color), COLOR_GET_B(color), COLOR_GET_A(color));
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

void ColorEditor_onSelect(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  int color = GUIObject_EditColor_GetColor(SBYSettings_Book->ColorEditor);
  TEXTID second_text = Get_TextID_Color(color);

  STANDBY_DATA *standby_data = Get_StandbyData();

  int subitem = SBYSettings_Book->selected_subitem;
  switch (subitem)
  {
  case TextSubItem_TColor:
    standby_data->temp.t_color = color;
    break;
  case TextSubItem_HColor:
    standby_data->temp.h_color = color;
    break;
  case TextSubItem_UColor:
    standby_data->temp.u_color = color;
    break;
  }
  ListMenu_SetItemSecondLineText(SBYSettings_Book->SubMenu, subitem, second_text);
  DESTROY_GUI(SBYSettings_Book->ColorEditor);
}

void ColorEditor_onBack(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  DESTROY_GUI(SBYSettings_Book->ColorEditor);
}

void Editor_SelectColor(BOOK *book, int color)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  SBYSettings_Book->ColorEditor = Create_EditColor(SBYSettings_Book, color);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->ColorEditor, ACTION_SELECT1, ColorEditor_onSelect);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->ColorEditor, ACTION_BACK, ColorEditor_onBack);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->ColorEditor, ACTION_LONG_BACK, ColorEditor_onBack);
  GUIObject_SoftKeys_SetItemOnKey(SBYSettings_Book->ColorEditor, ACTION_SELECT1, KEY_DIGITAL_5, KBD_SHORT_PRESS);
  GUIObject_Show(SBYSettings_Book->ColorEditor);
}

void EditorItemText_onSelect(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  int sub_item = ListMenu_GetSelectedItem(SBYSettings_Book->SubMenu);
  SBYSettings_Book->selected_subitem = sub_item;

  STANDBY_DATA *standby_data = Get_StandbyData();

  switch (sub_item)
  {
  case TextSubItem_State:
    Editor_onSetEnabled(SBYSettings_Book, TextSubItem_Last);
    break;
  case TextSubItem_Mode:
    Editor_onSetMode(SBYSettings_Book, TextSubItem_Last);
    break;
  case TextSubItem_TColor:
    Editor_SelectColor(SBYSettings_Book, standby_data->temp.t_color);
    break;
  case TextSubItem_HColor:
    Editor_SelectColor(SBYSettings_Book, standby_data->temp.h_color);
    break;
  case TextSubItem_UColor:
    Editor_SelectColor(SBYSettings_Book, standby_data->temp.u_color);
    break;
  case TextSubItem_Visual:
    Editor_SetVisual(SBYSettings_Book);
    break;
  }
}

TEXTID Get_SecondlineVisual(STANDBY_DATA *standby_data)
{
  wchar_t ustr[64];
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int font_size_styled = standby_data->temp.font_size;
  int font_style = font_size_styled >> 8;
  switch (font_style)
  {
  case UIFontStylePlain:
    snwprintf(ustr,
              MAXELEMS(ustr),
              L"X:%d, Y:%d, align:%ls font:%d_R",
              standby_data->temp.XPos,
              standby_data->temp.YPos,
              Get_Align(standby_data->temp.align),
              font_size_styled);
    break;
  case UIFontStyleBold:
    snwprintf(ustr,
              MAXELEMS(ustr),
              L"X:%d, Y:%d, align:%ls font:%d_B",
              standby_data->temp.XPos,
              standby_data->temp.YPos,
              Get_Align(standby_data->temp.align),
              font_size_styled & 0xFF);
    break;
  case UIFontStyleItalic:
    snwprintf(ustr,
              MAXELEMS(ustr),
              L"X:%d, Y:%d, align:%ls font:%d_I",
              standby_data->temp.XPos,
              standby_data->temp.YPos,
              Get_Align(standby_data->temp.align),
              font_size_styled & 0xFF);
    break;
  case UIFontStyleBoldItalic:
    snwprintf(ustr,
              MAXELEMS(ustr),
              L"X:%d, Y:%d, align:%ls font:%d_BI",
              standby_data->temp.XPos,
              standby_data->temp.YPos,
              Get_Align(standby_data->temp.align),
              font_size_styled & 0xFF);
    break;
  }
#endif
  return TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
}

int EditorItemText_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    STANDBY_DATA *standby_data = Get_StandbyData();

    int sub_item = GUIonMessage_GetCreatedItemIndex(msg);

    TEXTID first_text;
    TEXTID second_text;

    switch (sub_item)
    {
    case TextSubItem_State:
      first_text = STR(SHOW_MSG);
      if (standby_data->temp.state)
        second_text = TEXTID_ON;
      else
        second_text = TEXTID_OFF;
      break;
    case TextSubItem_Mode:
      first_text = STR(MODE_MSG);
      if (standby_data->temp.mode)
        second_text = STR("Mode 2");
      else
        second_text = STR("Mode 1");
      break;
    case TextSubItem_TColor:
      first_text = STR(TCOLOR_MSG);
      second_text = Get_TextID_Color(standby_data->temp.t_color);
      break;
    case TextSubItem_HColor:
      first_text = STR(HCOLOR_MSG);
      second_text = Get_TextID_Color(standby_data->temp.h_color);
      break;
    case TextSubItem_UColor:
      first_text = STR(UCOLOR_MSG);
      second_text = Get_TextID_Color(standby_data->temp.u_color);
      break;
    case TextSubItem_Visual:
      first_text = STR(VISUAL_MSG);
      second_text = Get_SecondlineVisual(standby_data);
      break;
    }
    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

void EditorItem_onBack(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  if (SBYSettings_Book->changed)
    SaveData(FALSE, SBYSettings_Book->selected_item);

  DESTROY_GUI(SBYSettings_Book->SubMenu);
}

void Create_EditorItemText(BOOK *book)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  SBYSettings_Book->SubMenu = CreateListMenu(SBYSettings_Book, UIDisplay_Main);
  ListMenu_SetOnMessage(SBYSettings_Book->SubMenu, EditorItemText_onMessage);
  ListMenu_SetItemCount(SBYSettings_Book->SubMenu, TextSubItem_Last);
  ListMenu_SetCursorToItem(SBYSettings_Book->SubMenu, TextSubItem_State);
  ListMenu_SetItemStyle(SBYSettings_Book->SubMenu, 3);
  GUIObject_SetTitleText(SBYSettings_Book->SubMenu, TextID_Setting(SBYSettings_Book->selected_item));
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->SubMenu, ACTION_BACK, EditorItem_onBack);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->SubMenu, ACTION_SELECT1, EditorItemText_onSelect);
  GUIObject_Show(SBYSettings_Book->SubMenu);
}

//==============================================================================

void EditorItemIcon_onSelect(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  int sub_item = ListMenu_GetSelectedItem(SBYSettings_Book->SubMenu);
  SBYSettings_Book->selected_subitem = sub_item;

  switch (sub_item)
  {
  case IconSubItem_State:
    Editor_onSetEnabled(SBYSettings_Book, IconSubItem_Last);
    break;
  case IconSubItem_Visual:
    Editor_SetVisual(SBYSettings_Book);
    break;
  }
}

int EditorItemIcon_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    STANDBY_DATA *standby_data = Get_StandbyData();

    TEXTID first_text;
    TEXTID second_text;

    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case IconSubItem_State:
      first_text = STR(SHOW_MSG);
      if (standby_data->temp.state)
      {
        second_text = TEXTID_ON;
      }
      else
      {
        second_text = TEXTID_OFF;
      }
      break;
    case IconSubItem_Visual:
      wchar_t ustr[32];
      snwprintf(ustr, MAXELEMS(ustr), L"X:%d, Y:%d", standby_data->temp.XPos, standby_data->temp.YPos);

      first_text = STR(VISUAL_MSG);
      second_text = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
      break;
    }
    GUIonMessage_SetMenuItemText(msg, first_text);
    GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
  }
  return 1;
}

void Create_EditorItemIcon(BOOK *book)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  SBYSettings_Book->SubMenu = CreateListMenu(SBYSettings_Book, UIDisplay_Main);
  ListMenu_SetOnMessage(SBYSettings_Book->SubMenu, EditorItemIcon_onMessage);
  ListMenu_SetItemCount(SBYSettings_Book->SubMenu, IconSubItem_Last);
  ListMenu_SetCursorToItem(SBYSettings_Book->SubMenu, IconSubItem_State);
  ListMenu_SetItemStyle(SBYSettings_Book->SubMenu, 3);
  GUIObject_SetTitleText(SBYSettings_Book->SubMenu, TextID_Setting(SBYSettings_Book->selected_item));
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->SubMenu, ACTION_BACK, EditorItem_onBack);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->SubMenu, ACTION_SELECT1, EditorItemIcon_onSelect);
  GUIObject_Show(SBYSettings_Book->SubMenu);
}

//==============================================================================

void Clear_TempData(STANDBY_DATA *standby_data)
{
  standby_data->temp.state = 0;
  standby_data->temp.mode = 0;
  standby_data->temp.align = 0;
  standby_data->temp.t_color = 0;
  standby_data->temp.h_color = 0;
  standby_data->temp.highlight = 0;
  standby_data->temp.font_size = 0;
  standby_data->temp.XPos = 0;
  standby_data->temp.YPos = 0;
  standby_data->temp.Width = 0;
  standby_data->temp.Height = 0;
  standby_data->temp.MaxHeight = 0;
  standby_data->temp.underline = 0;
  standby_data->temp.u_color = 0;
}

void LoadTextData_toTemp(STANDBY_DATA *standby_data, TEXT_ITEM_DATA *item)
{
  standby_data->temp.state = (*item).state;
  standby_data->temp.mode = (*item).mode;
  standby_data->temp.align = (*item).align;
  standby_data->temp.t_color = (*item).t_color;
  standby_data->temp.h_color = (*item).h_color;
  standby_data->temp.highlight = (*item).highlight;
  standby_data->temp.font_size = (*item).font_size;
  standby_data->temp.XPos = (*item).XPos;
  standby_data->temp.YPos = (*item).YPos;
  standby_data->temp.Width = (*item).Width;
  standby_data->temp.Height = (*item).Height;
  standby_data->temp.MaxHeight = (*item).MaxHeight;
  standby_data->temp.underline = (*item).underline;
  standby_data->temp.u_color = (*item).u_color;
}

void LoadIconData_toTemp(STANDBY_DATA *standby_data, ICON_ITEM_DATA *item)
{
  standby_data->temp.state = (*item).state;
  standby_data->temp.XPos = (*item).XPos;
  standby_data->temp.YPos = (*item).YPos;
}

void LoadStatusData_toTemp(STANDBY_DATA *standby_data, STATUS_ICN_DATA *item)
{
  standby_data->temp.state = (*item).state;
  standby_data->temp.align = (*item).align;
  standby_data->temp.XPos = (*item).XPos;
  standby_data->temp.YPos = (*item).YPos;
}

void Setting_onSelect(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  int item = ListMenu_GetSelectedItem(SBYSettings_Book->MainMenu);
  SBYSettings_Book->selected_item = item;

  STANDBY_DATA *standby_data = Get_StandbyData();
  Clear_TempData(standby_data);

  switch (item)
  {
  case ITEM_Statusbar:
    LoadStatusData_toTemp(standby_data, &standby_data->settings.status);
    SBYSettings_Book->item_type = ItemStatusIcon;
    Create_EditorItemIcon(SBYSettings_Book);
    break;
  case ITEM_NetworkIcon:
    LoadIconData_toTemp(standby_data, &standby_data->settings.net_icn);
    SBYSettings_Book->item_type = ItemStandartIcon;
    Create_EditorItemIcon(SBYSettings_Book);
    break;
  case ITEM_BatteryIcon:
    LoadIconData_toTemp(standby_data, &standby_data->settings.batt_icn);
    SBYSettings_Book->item_type = ItemStandartIcon;
    Create_EditorItemIcon(SBYSettings_Book);
    break;
  case ITEM_MusicWidget:
    LoadIconData_toTemp(standby_data, &standby_data->settings.music);
    SBYSettings_Book->item_type = ItemStandartIcon;
    Create_EditorItemIcon(SBYSettings_Book);
    break;

  case ITEM_StandbyClock:
    LoadTextData_toTemp(standby_data, &standby_data->settings.standbyclock);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_StatusClock:
    LoadTextData_toTemp(standby_data, &standby_data->settings.statusclock);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Date:
    LoadTextData_toTemp(standby_data, &standby_data->settings.date);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Weekday:
    LoadTextData_toTemp(standby_data, &standby_data->settings.weekday);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Alarm:
    LoadTextData_toTemp(standby_data, &standby_data->settings.alarm);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Profile:
    LoadTextData_toTemp(standby_data, &standby_data->settings.profile);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Heap:
    LoadTextData_toTemp(standby_data, &standby_data->settings.heap);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Timer:
    LoadTextData_toTemp(standby_data, &standby_data->settings.timer);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Call:
    LoadTextData_toTemp(standby_data, &standby_data->settings.calltime);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Signal:
    LoadTextData_toTemp(standby_data, &standby_data->settings.signal);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_NetworkName:
    LoadTextData_toTemp(standby_data, &standby_data->settings.opname);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Batt:
    LoadTextData_toTemp(standby_data, &standby_data->settings.battery);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Charge:
    LoadTextData_toTemp(standby_data, &standby_data->settings.charge);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Batttemp:
    LoadTextData_toTemp(standby_data, &standby_data->settings.batttemp);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Systemp:
    LoadTextData_toTemp(standby_data, &standby_data->settings.systemp);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Phone:
    LoadTextData_toTemp(standby_data, &standby_data->settings.phone);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Card:
    LoadTextData_toTemp(standby_data, &standby_data->settings.card);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  case ITEM_Radio:
    LoadTextData_toTemp(standby_data, &standby_data->settings.radio);
    SBYSettings_Book->item_type = ItemText;
    Create_EditorItemText(SBYSettings_Book);
    break;
  }
}

void Setting_onBack(BOOK *book, GUI *gui)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;

  if (SBYSettings_Book->changed)
  {
    SaveData(TRUE, SBYSettings_Book->selected_item);

    STANDBY_DATA *standby_data = Get_StandbyData();
    LoadData(standby_data);
  }

  FreeBook(SBYSettings_Book);
}

int Setting_onMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, TextID_Setting(item));
  }
  return 1;
}

int pg_SBYSettings_EnterAction(void *data, BOOK *book)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  SBYSettings_Book->MainMenu = CreateListMenu(SBYSettings_Book, UIDisplay_Main);
  GUIObject_SetTitleText(SBYSettings_Book->MainMenu, TEXTID_LAYOUT);
  ListMenu_SetItemCount(SBYSettings_Book->MainMenu, ITEM_Last);
  ListMenu_SetOnMessage(SBYSettings_Book->MainMenu, Setting_onMessage);
  ListMenu_SetCursorToItem(SBYSettings_Book->MainMenu, SBYSettings_Book->selected_item);
  ListMenu_SetItemStyle(SBYSettings_Book->MainMenu, 0);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->MainMenu, ACTION_SELECT1, Setting_onSelect);
  GUIObject_SoftKeys_SetAction(SBYSettings_Book->MainMenu, ACTION_BACK, Setting_onBack);
  GUIObject_Show(SBYSettings_Book->MainMenu);
  return 1;
}

int pg_SBYSettings_ExitAction(void *data, BOOK *book)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  DESTROY_GUI(SBYSettings_Book->MainMenu);
  DESTROY_GUI(SBYSettings_Book->SubMenu);
  DESTROY_GUI(SBYSettings_Book->Dialog);
  DESTROY_GUI(SBYSettings_Book->OptionMenu);
  DESTROY_GUI(SBYSettings_Book->ColorEditor);
  return 1;
}

int pg_SBYSettings_PreviousAction(void *data, BOOK *book)
{
  BookObj_ReturnPage(book, CANCEL_EVENT);
  return 1;
}

//******************************************************************************

int pg_SBYSettings_CancelAction(void *data, BOOK *book)
{
  FreeBook(book);
  return 1;
}

const PAGE_MSG base_evtlst[] =
    {
        RETURN_TO_STANDBY_EVENT, pg_SBYSettings_CancelAction,
        NIL_EVENT, NULL};

const PAGE_MSG main_evtlst[] =
    {
        PAGE_ENTER_EVENT, pg_SBYSettings_EnterAction,
        PAGE_EXIT_EVENT, pg_SBYSettings_ExitAction,
        PREVIOUS_EVENT, pg_SBYSettings_PreviousAction,
        CANCEL_EVENT, pg_SBYSettings_CancelAction,
        NIL_EVENT, NULL};

const PAGE_DESC SBYSettings_Base_Page = {"SBYSettings_Base_Page", NULL, base_evtlst};
const PAGE_DESC SBYSettings_Main_Page = {"SBYSettings_Main_Page", NULL, main_evtlst};

void SettingsBook_onClose(BOOK *book)
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)book;
  DESTROY_GUI(SBYSettings_Book->MainMenu);
  DESTROY_GUI(SBYSettings_Book->SubMenu);
  DESTROY_GUI(SBYSettings_Book->Dialog);
  DESTROY_GUI(SBYSettings_Book->OptionMenu);
  DESTROY_GUI(SBYSettings_Book->ColorEditor);
  SBYSettings_Book->selected_item = 0;
  SBYSettings_Book->selected_subitem = 0;
  SBYSettings_Book->changed = 0;
  SBYSettings_Book->item_type = 0;

  InvalidateAll();
}

BOOK *Create_SBYSettings_Book()
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)malloc(sizeof(STANDBY_SETTINGS_BOOK));
  memset(SBYSettings_Book, NULL, sizeof(STANDBY_SETTINGS_BOOK));
  if (!CreateBook(SBYSettings_Book, SettingsBook_onClose, &SBYSettings_Base_Page, "SBYSettings_Book", NO_BOOK_ID, NULL))
  {
    mfree(SBYSettings_Book);
    return NULL;
  }
  SBYSettings_Book->MainMenu = 0;
  SBYSettings_Book->SubMenu = 0;
  SBYSettings_Book->Dialog = 0;
  SBYSettings_Book->OptionMenu = 0;
  SBYSettings_Book->ColorEditor = 0;
  SBYSettings_Book->selected_item = 0;
  SBYSettings_Book->selected_subitem = 0;
  SBYSettings_Book->changed = 0;
  SBYSettings_Book->item_type = 0;
  return SBYSettings_Book;
}

void Create_ItemsEditor()
{
  STANDBY_SETTINGS_BOOK *SBYSettings_Book = (STANDBY_SETTINGS_BOOK *)Create_SBYSettings_Book();

  if (SBYSettings_Book)
  {
    BookObj_GotoPage(SBYSettings_Book, &SBYSettings_Main_Page);
  }
}
