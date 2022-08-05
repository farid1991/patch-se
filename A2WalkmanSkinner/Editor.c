#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"

#include "Editor.h"
#include "Function.h"
#include "LNG.h"
#include "main.h"
#include "SaveLoad.h"

#include "GUI\EditColor.h"
#include "GUI\EditCoordinates.h"
#include "GUI\SelectFont.h"
#include "Pages\Skins.h"

//==============================================================================

void EditColor_PrevAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->color);
}

void EditColor_AcceptAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  mbk->ChangeMade = TRUE;

  unsigned int color = GUIObject_EditColor_GetColor(mbk->color);
  int red = GUIObject_EditColor_GetRed(mbk->color);
  int green = GUIObject_EditColor_GetGreen(mbk->color);
  int blue = GUIObject_EditColor_GetBlue(mbk->color);
  int alpha = GUIObject_EditColor_GetAlpha(mbk->color);
  snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", red, green, blue, alpha);
  TEXTID second_text = TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN);

  if (mbk->IsBbar)
  {
    mbk->Str_Color = color;
    ListMenu_SetItemSecondLineText(mbk->ProgressBar, 2, second_text);
  }
  else if (mbk->IsFbar)
  {
    mbk->Str_Color_2 = color;
    ListMenu_SetItemSecondLineText(mbk->ProgressBar, 3, second_text);
  }
  else if (mbk->IsString)
  {
    mbk->Str_Color = color;
    ListMenu_SetItemSecondLineText(mbk->StringEdit, 4, second_text);
  }

  DESTROY_GUI(mbk->color);
}

void EditColor(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  int color = clWhite;
  if ((mbk->IsBbar) || (mbk->IsString))
  {
    color = mbk->Str_Color;
  }
  else if (mbk->IsFbar)
  {
    color = mbk->Str_Color_2;
  }
  
  if (mbk->color = Create_EditColor(mbk, color))
  {
    GUIObject_SoftKeys_SetAction(mbk->color, ACTION_SELECT1, EditColor_AcceptAction);
    GUIObject_SoftKeys_SetAction(mbk->color, ACTION_BACK, EditColor_PrevAction);
    GUIObject_SoftKeys_SetAction(mbk->color, ACTION_LONG_BACK, EditColor_PrevAction);
    GUIObject_SoftKeys_SetItemOnKey(mbk->color, ACTION_SELECT1, KEY_DIGITAL_5, KBD_SHORT_PRESS);
    GUIObject_Show(mbk->color);
  }
}

//==============================================================================

void EditCoordinates_ChangeOrientation(BOOK *book, GUI *gui)
{
  BookObj_SetDisplayOrientation(book, BookObj_GetDisplayOrientation(book) ? UIDisplayOrientationMode_Vertical : UIDisplayOrientationMode_Horizontal);
}

void EditCoordinates_CancelAction(BOOK *book, GUI *)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DISP_OBJ_COORD *disp_obj = (DISP_OBJ_COORD *)GUIObject_GetDispObject(mbk->coord);
  int f = 0;

  if (disp_obj->type)
  {
    if (disp_obj->is_first_set)
    {
      disp_obj->is_first_set = 0;
      f = 1;
      DispObject_InvalidateRect(disp_obj, NULL);
    }
  }

  if (!f)
  {
    BookObj_SetDisplayOrientation(mbk, UIDisplayOrientationMode_Vertical);
    DESTROY_GUI(mbk->coord);
  }
}

void EditCoordinates_AcceptAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DISP_OBJ_COORD *disp_obj = (DISP_OBJ_COORD *)GUIObject_GetDispObject(mbk->coord);
  int f = 0;
  if (disp_obj->type)
  {
    if (!disp_obj->is_first_set)
    {
      disp_obj->x2 = disp_obj->x;
      disp_obj->y2 = disp_obj->y;
      disp_obj->is_first_set = 1;
      f = 1;
    }
    else
    {
      mbk->Str_x1 = MIN(disp_obj->x2, disp_obj->x);
      mbk->Str_y1 = MIN(disp_obj->y2, disp_obj->y);
      mbk->Str_x2 = MAX(disp_obj->x2, disp_obj->x);
      mbk->Str_y2 = MAX(disp_obj->y2, disp_obj->y);

      if (mbk->IsBbar || mbk->IsFbar)
      {
        TEXTID SID[7];
        TEXTID TempSID = TextID_Create(", ", ENC_GSM, 2);
        SID[0] = TextID_CreateIntegerID(mbk->Str_x1);
        SID[1] = TempSID;
        SID[2] = TextID_CreateIntegerID(mbk->Str_y1);
        SID[3] = TempSID;
        SID[4] = TextID_CreateIntegerID(mbk->Str_x2);
        SID[5] = TempSID;
        SID[6] = TextID_CreateIntegerID(mbk->Str_y2);
        TEXTID IDSID = TextID_Create(SID, ENC_TEXTID, 7);
        ListMenu_SetItemSecondLineText(mbk->ProgressBar, 1, IDSID);
      }
      else if (mbk->IsString)
      {
        snwprintf(mbk->buffer, 50, L"X: %d, Y: %d, Width: %d", mbk->Str_x1, mbk->Str_y1, mbk->Str_x2 - mbk->Str_x1);
        ListMenu_SetItemSecondLineText(mbk->StringEdit, 1, TextID_Create(mbk->buffer, ENC_UCS2, 0xFF));
      }
      else if (mbk->IsCover)
      {
        LoadTempDataToBookHeader(mbk, mbk->ItemID);
        mbk->IsCover = 0;
      }
    }
  }
  else
  {
    mbk->Str_x1 = disp_obj->x;
    mbk->Str_y1 = disp_obj->y;
    snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"X: %d, Y: %d", mbk->Str_x1, mbk->Str_y1);
    ListMenu_SetItemSecondLineText(mbk->IconEdit, 1, TextID_Create(mbk->buffer, ENC_UCS2, 0xFF));
  }

  if (!f)
  {
    BookObj_SetDisplayOrientation(mbk, UIDisplayOrientationMode_Vertical);
    DESTROY_GUI(mbk->coord);
  }
  mbk->ChangeMade = TRUE;
}

void EditCoordinates(BOOK *book, int type)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  if (mbk->coord = Create_EditCoordinates(mbk, type))
  {
    DISP_OBJ_COORD *disp_obj = (DISP_OBJ_COORD *)GUIObject_GetDispObject(mbk->coord);
    if (type == COORD_POINT)
    {
      disp_obj->x = mbk->Str_x1;
      disp_obj->y = mbk->Str_y1;
    }
    else
    {
      disp_obj->old_rect.x1 = disp_obj->x = mbk->Str_x1;
      disp_obj->old_rect.y1 = disp_obj->y = mbk->Str_y1;
      disp_obj->old_rect.x2 = disp_obj->x2 = mbk->Str_x2;
      disp_obj->old_rect.y2 = disp_obj->y2 = mbk->Str_y2;
    }

    GUIObject_SoftKeys_SetAction(mbk->coord, ACTION_SELECT1, EditCoordinates_AcceptAction);
    GUIObject_SoftKeys_SetAction(mbk->coord, ACTION_BACK, EditCoordinates_ChangeOrientation);
    GUIObject_SoftKeys_SetAction(mbk->coord, ACTION_LONG_BACK, EditCoordinates_CancelAction);
    GUIObject_SoftKeys_SetItemOnKey(mbk->coord, ACTION_SELECT1, KEY_ENTER, KBD_SHORT_RELEASE);
    GUIObject_SoftKeys_SetItemOnKey(mbk->coord, ACTION_SELECT1, KEY_LEFT_SOFT, KBD_SHORT_RELEASE);
    GUIObject_SoftKeys_SetItemOnKey(mbk->coord, ACTION_SELECT1, KEY_DIGITAL_0 + 5, KBD_SHORT_RELEASE);
    GUIObject_SoftKeys_SetItemOnKey(mbk->coord, ACTION_BACK, KEY_ESC, KBD_SHORT_RELEASE);
    GUIObject_Show(mbk->coord);
  }
}

//==============================================================================

void SelectFont_OnBack(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->font_select);
}

void SelectFont_OnSelect(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  mbk->ChangeMade = TRUE;

  DISP_OBJ_FONT_SEL *disp_obj = (DISP_OBJ_FONT_SEL *)GUIObject_GetDispObject(mbk->font_select);
  mbk->Str_Font_Size = GUIObject_Font_GetSize(mbk->font_select);
#if defined(DB3200) || defined(DB3210)
  switch (GUIObject_Font_GetStyle(mbk->font_select))
  {
  case UIFontStylePlain:
    snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dR", mbk->Str_Font_Size); ///< normal
    break;
  case UIFontStyleBold:
    snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dB", FONT_HEIGHT(mbk->Str_Font_Size)); ///< bold
    break;
  case UIFontStyleItalic:
    snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dI", FONT_HEIGHT(mbk->Str_Font_Size)); ///< italic
    break;
  case UIFontStyleBoldItalic:
    snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dBI", FONT_HEIGHT(mbk->Str_Font_Size)); ///< bold italic
    break;
  }
  ListMenu_SetItemSecondLineText(mbk->StringEdit, 3, TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN));
#else
  ListMenu_SetItemSecondLineText(mbk->StringEdit, 3, TextID_Create(GetFontNameByFontId(mbk->Str_Font_Size), ENC_UCS2, TEXTID_ANY_LEN));
#endif
  DESTROY_GUI(mbk->font_select);
}

void SelectFont(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  if (mbk->font_select = Create_SelectFont(mbk))
  {
    GUIObject_Font_SetDefault(mbk->font_select, mbk->Str_Font_Size);
    GUIObject_SoftKeys_SetAction(mbk->font_select, ACTION_BACK, SelectFont_OnBack);
    GUIObject_SoftKeys_SetAction(mbk->font_select, ACTION_SELECT1, SelectFont_OnSelect);
    GUIObject_SoftKeys_SetItemOnKey(mbk->font_select, ACTION_SELECT1, KEY_DIGITAL_5, KBD_SHORT_PRESS);
    GUIObject_Show(mbk->font_select);
  }
}

//==============================================================================

void SetEnabled(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  TEXTID TXT;
  if (mbk->Str_Enable)
  {
    mbk->Str_Enable = FALSE;
    TXT = TEXT_NO;
  }
  else
  {
    mbk->Str_Enable = TRUE;
    TXT = TEXT_YES;
  }
  ListMenu_SetItemSecondLineText(gui, 0, TXT);
  mbk->ChangeMade = TRUE;
}

//==============================================================================

int EditorSlider_OnMessage(GUI_MESSAGE *msg)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == 0)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_ENABLED);
      if (mbk->Str_Enable)
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_YES);
      else
      {
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_NO);
      }
    }
    if (item == 1)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_POSITION);
      TEXTID SID[7];
      TEXTID TempSID = TextID_Create(", ", ENC_GSM, 2);
      SID[0] = TextID_CreateIntegerID(mbk->Str_x1);
      SID[1] = TempSID;
      SID[2] = TextID_CreateIntegerID(mbk->Str_y1);
      SID[3] = TempSID;
      SID[4] = TextID_CreateIntegerID(mbk->Str_x2);
      SID[5] = TempSID;
      SID[6] = TextID_CreateIntegerID(mbk->Str_y2);
      TEXTID IDSID = TextID_Create(SID, ENC_TEXTID, 7);
      GUIonMessage_SetMenuItemSecondLineText(msg, IDSID);
    }
    if (item == 2)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_BACKGROUND_COLOR);
      snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", COLOR_GET_R(mbk->Str_Color), COLOR_GET_G(mbk->Str_Color), COLOR_GET_B(mbk->Str_Color), COLOR_GET_A(mbk->Str_Color));
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN));
    }
    if (item == 3)
    {
      GUIonMessage_SetMenuItemText(msg, STR(TXT_ELAPSED_BAR_COLOR));
      snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", COLOR_GET_R(mbk->Str_Color_2), COLOR_GET_G(mbk->Str_Color_2), COLOR_GET_B(mbk->Str_Color_2), COLOR_GET_A(mbk->Str_Color_2));
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN));
    }
  }
  return 1;
}

void EditorSlider_SelectAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  int item = ListMenu_GetSelectedItem(mbk->ProgressBar);
  if (item == 0)
    SetEnabled(mbk, mbk->ProgressBar);
  if (item == 1)
  {
    mbk->IsBbar = TRUE;
    mbk->IsFbar = TRUE;
    mbk->IsString = FALSE;
    EditCoordinates(mbk, COORD_RECT);
  }
  if (item == 2)
  {
    mbk->IsBbar = TRUE;
    mbk->IsFbar = FALSE;
    mbk->IsString = FALSE;
    EditColor(mbk);
  }
  if (item == 3)
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = TRUE;
    mbk->IsString = FALSE;
    EditColor(mbk);
  }
}

void EditorSlider_PrevAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  DESTROY_GUI(mbk->ProgressBar);
}

void Editor_Slider(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  if (mbk->ProgressBar = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->ProgressBar, TextID_Create(mbk->Title_Str, ENC_UCS2, TEXTID_ANY_LEN));
    GUIObject_SetTitleType(mbk->ProgressBar, UI_TitleMode_Small);
    ListMenu_SetItemCount(mbk->ProgressBar, 4);
    ListMenu_SetHotkeyMode(mbk->ProgressBar, LKHM_SHORTCUT);
    ListMenu_SetOnMessage(mbk->ProgressBar, EditorSlider_OnMessage);
    ListMenu_SetCursorToItem(mbk->ProgressBar, 0);
    ListMenu_SetItemStyle(mbk->ProgressBar, 3);
    ListMenu_SetItemTextScroll(mbk->ProgressBar, 1);
    GUIObject_SoftKeys_SetAction(mbk->ProgressBar, ACTION_BACK, EditorSlider_PrevAction);
    GUIObject_SoftKeys_SetAction(mbk->ProgressBar, ACTION_SELECT1, EditorSlider_SelectAction);
    GUIObject_Show(mbk->ProgressBar);
  }
}

//==============================================================================

int EditorItemIcon_OnMessage(GUI_MESSAGE *msg)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == 0)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_ENABLED);
      if (mbk->Str_Enable)
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_YES);
      else
      {
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_NO);
      }
    }
    if (item == 1)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_POSITION);
      TEXTID SID[7];
      TEXTID TempSID = TextID_Create(", ", ENC_GSM, 2);
      SID[0] = TextID_CreateIntegerID(mbk->Str_x1);
      SID[1] = TempSID;
      SID[2] = TextID_CreateIntegerID(mbk->Str_y1);
      SID[3] = TempSID;
      SID[4] = TextID_CreateIntegerID(mbk->Str_x2);
      SID[5] = TempSID;
      SID[6] = TextID_CreateIntegerID(mbk->Str_y2);
      TEXTID IDSID = TextID_Create(SID, ENC_TEXTID, 7);
      GUIonMessage_SetMenuItemSecondLineText(msg, IDSID);
    }
  }
  return 1;
}

void EditorItemIcon_PrevAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  DESTROY_GUI(mbk->IconEdit);
}

void EditorItemIcon_SelectAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  int item = ListMenu_GetSelectedItem(mbk->IconEdit);
  if (item == 0)
    SetEnabled(mbk, mbk->IconEdit);
  if (item == 1)
    EditCoordinates(mbk, COORD_POINT);
}

void Editor_ItemIcon(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  if (mbk->IconEdit = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->IconEdit, TextID_Create(mbk->Title_Str, ENC_UCS2, TEXTID_ANY_LEN));
    GUIObject_SetTitleType(mbk->IconEdit, UI_TitleMode_Small);
    ListMenu_SetItemCount(mbk->IconEdit, 2);
    ListMenu_SetHotkeyMode(mbk->IconEdit, LKHM_SHORTCUT);
    ListMenu_SetOnMessage(mbk->IconEdit, EditorItemIcon_OnMessage);
    ListMenu_SetCursorToItem(mbk->IconEdit, 0);
    ListMenu_SetItemStyle(mbk->IconEdit, 3);
    ListMenu_SetItemTextScroll(mbk->IconEdit, 1);
    GUIObject_SoftKeys_SetAction(mbk->IconEdit, ACTION_BACK, EditorItemIcon_PrevAction);
    GUIObject_SoftKeys_SetAction(mbk->IconEdit, ACTION_SELECT1, EditorItemIcon_SelectAction);
    GUIObject_Show(mbk->IconEdit);
  }
}

//==============================================================================

void SetAlign_PrevAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  DESTROY_GUI(mbk->Alignment);
}

void SetAlign_SelectAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  mbk->Str_Align = OneOfMany_GetSelected(mbk->Alignment);

  int align = mbk->Str_Align;
  switch (align)
  {
  case AlignLeft:
    ListMenu_SetItemSecondLineText(mbk->StringEdit, 2, TEXT_LEFT);
    break;
  case AlignRight:
    ListMenu_SetItemSecondLineText(mbk->StringEdit, 2, TEXT_RIGHT);
    break;
  case AlignCenter:
    ListMenu_SetItemSecondLineText(mbk->StringEdit, 2, STR(TXT_CENTER));
    break;
  }

  mbk->ChangeMade = TRUE;
  DESTROY_GUI(mbk->Alignment);
}

int SetAlign_OnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    switch (GUIonMessage_GetCreatedItemIndex(msg))
    {
    case 0:
      GUIonMessage_SetMenuItemText(msg, TEXT_LEFT);
      break;
    case 1:
      GUIonMessage_SetMenuItemText(msg, TEXT_RIGHT);
      break;
    case 2:
      GUIonMessage_SetMenuItemText(msg, STR(TXT_CENTER));
      break;
    }
  }
  return (1);
}

void SetAlign(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  mbk->Alignment = CreateOneOfMany(mbk);
  GUIObject_SetTitleText(mbk->Alignment, TEXT_ALIGN);
  OneOfMany_SetItemCount(mbk->Alignment, 3);
  OneOfMany_SetOnMessage(mbk->Alignment, SetAlign_OnMessage);
  OneOfMany_SetChecked(mbk->Alignment, mbk->Str_Align);
  GUIObject_SoftKeys_SetAction(mbk->Alignment, ACTION_BACK, SetAlign_PrevAction);
  GUIObject_SoftKeys_SetAction(mbk->Alignment, ACTION_SELECT1, SetAlign_SelectAction);
  GUIObject_Show(mbk->Alignment);
}

//==============================================================================

int EditorItemText_OnMessage(GUI_MESSAGE *msg)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == 0)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_ENABLED);
      if (mbk->Str_Enable)
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_YES);
      else
      {
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_NO);
      }
    }
    if (item == 1)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_POSITION);
      snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"X: %d, Y: %d, Width: %d", mbk->Str_x1, mbk->Str_y1, mbk->Str_x2 - mbk->Str_x1);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN));
    }
    if (item == 2)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_ALIGN);
      int align = mbk->Str_Align;
      switch (align)
      {
      case AlignLeft:
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_LEFT);
        break;
      case AlignRight:
        GUIonMessage_SetMenuItemSecondLineText(msg, TEXT_RIGHT);
        break;
      case AlignCenter:
        GUIonMessage_SetMenuItemSecondLineText(msg, STR(TXT_CENTER));
        break;
      }
    }
    if (item == 3)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_FONT_SIZE);
#if defined(DB3200) || defined(DB3210)
      int style = mbk->Str_Font_Size >> 8;
      switch (style)
      {
      case UI_Emphasis_Normal:
        snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dR", mbk->Str_Font_Size); ///< normal
        break;
      case UI_Emphasis_Bold:
        snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dB", mbk->Str_Font_Size & 0xFF); ///< bold
        break;
      case UI_Emphasis_Italic:
        snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dI", mbk->Str_Font_Size & 0xFF); ///< italic
        break;
      case UI_Emphasis_BoldItalic:
        snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"FONT_E_%dBI", mbk->Str_Font_Size & 0xFF); ///< bold italic
        break;
      }
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN));
#else
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(GetFontNameByFontId(mbk->Str_Font_Size), ENC_UCS2, TEXTID_ANY_LEN));
#endif
    }
    if (item == 4)
    {
      GUIonMessage_SetMenuItemText(msg, TEXT_TEXT_COLOR);
      snwprintf(mbk->buffer, MAXELEMS(mbk->buffer), L"%X, %X, %X, %X", COLOR_GET_R(mbk->Str_Color), COLOR_GET_G(mbk->Str_Color), COLOR_GET_B(mbk->Str_Color), COLOR_GET_A(mbk->Str_Color));
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->buffer, ENC_UCS2, TEXTID_ANY_LEN));
    }
  }
  return TRUE;
}

void EditorItemText_PrevAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  LoadTempDataToBookHeader(mbk, mbk->ItemID);
  DESTROY_GUI(mbk->StringEdit);
}

void EditorItemText_SelectAction(BOOK *book, GUI *gui)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;

  int item = ListMenu_GetSelectedItem(mbk->StringEdit);
  if (item == 0)
    SetEnabled(mbk, mbk->StringEdit);
  if (item == 1)
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = FALSE;
    mbk->IsString = TRUE;
    EditCoordinates(mbk, COORD_RECT);
  }
  if (item == 2)
  {
    SetAlign(mbk);
  }
  if (item == 3)
  {
    SelectFont(mbk);
  }
  if (item == 4)
  {
    mbk->IsBbar = FALSE;
    mbk->IsFbar = FALSE;
    mbk->IsString = TRUE;
    EditColor(mbk);
  }
}

void Editor_ItemText(BOOK *book)
{
  SkinEditor_Book *mbk = (SkinEditor_Book *)book;
  if (mbk->StringEdit = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->StringEdit, TextID_Create(mbk->Title_Str, ENC_UCS2, TEXTID_ANY_LEN));
    GUIObject_SetTitleType(mbk->StringEdit, UI_TitleMode_Small);
    ListMenu_SetItemCount(mbk->StringEdit, 5);
    ListMenu_SetHotkeyMode(mbk->StringEdit, LKHM_SHORTCUT);
    ListMenu_SetOnMessage(mbk->StringEdit, EditorItemText_OnMessage);
    ListMenu_SetCursorToItem(mbk->StringEdit, 0);
    ListMenu_SetItemStyle(mbk->StringEdit, 3);
    ListMenu_SetItemTextScroll(mbk->StringEdit, 1);
    GUIObject_SoftKeys_SetAction(mbk->StringEdit, ACTION_BACK, EditorItemText_PrevAction);
    GUIObject_SoftKeys_SetAction(mbk->StringEdit, ACTION_SELECT1, EditorItemText_SelectAction);
    GUIObject_Show(mbk->StringEdit);
  }
}

//==============================================================================
