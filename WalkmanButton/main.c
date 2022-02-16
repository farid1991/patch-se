#include "temp\target.h"

#include "..\\include\Types.h"

#include "bookman.h"
#include "main.h"
#include "Lib.h"
#include "screenshot.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "wb", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "wb", 0);
#else
  return memalloc(size, 1, 5, "wb", 0);
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "wb", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "wb", 0);
#else
  if (mem)
    memfree(mem, "wb", 0);
#endif
}

int GetChecked(int mode)
{
  int ret = 0;
  int file;
  if ((file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
  {
    CFG_DATA *fdata = (CFG_DATA *)malloc(sizeof(CFG_DATA));
    memset(fdata, NULL, sizeof(CFG_DATA));
    fread(file, fdata, sizeof(CFG_DATA));
    if (mode == SHORT_PRESS)
      ret = fdata->short_press;
    else
      ret = fdata->long_press;
    fclose(file);
    mfree(fdata);
  }
  return ret;
}

void SaveConfig(BOOK *book, int selected_item)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  int file;
  if ((file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL)) >= 0)
  {
    CFG_DATA *fdata = (CFG_DATA *)malloc(sizeof(CFG_DATA));
    memset(fdata, NULL, sizeof(CFG_DATA));
    if (wsbook->KeyMode == SHORT_PRESS)
    {
      wsbook->short_press = selected_item;
      fdata->short_press = selected_item;
      fdata->long_press = wsbook->long_press;
    }
    else
    {
      fdata->short_press = wsbook->short_press;
      fdata->long_press = selected_item;
      wsbook->long_press = selected_item;
    }
    fwrite(file, fdata, sizeof(CFG_DATA));
    fclose(file);
    mfree(fdata);
  }
}

void LinkSelector_SelectItem(BOOK *book, GUI *gui)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  int item = OneOfMany_GetSelected(wsbook->SubMenu);
  SaveConfig(wsbook, item);
  FREE_GUI(wsbook->SubMenu);
}

void LinkSelector_Close(BOOK *book, GUI *gui)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  FREE_GUI(wsbook->SubMenu);
}

TEXTID GetSubMenuTitle(int KeyMode)
{
  if (KeyMode == SHORT_PRESS)
    return STR("Short Press");
  else
    return STR("Long Press");
}

void CreateLinkSelector(BOOK *book)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  TEXTID items_text[SUBITEM_COUNT] = {
      BUTTON_TXT,
      WALKMAN_TXT,
      STR("QuickAccess Menu"),
      STR("Activity Menu"),
      STR("Book Manager"),
      STR("Next Book"),
      STR("Screenshoter")};

  if (wsbook->SubMenu = CreateOneOfMany(wsbook))
  {
    GUIObject_SetTitleText(wsbook->SubMenu, GetSubMenuTitle(wsbook->KeyMode));
    GUIObject_SetStyle(wsbook->SubMenu, UI_OverlayStyle_FullScreen);
    OneOfMany_SetItemCount(wsbook->SubMenu, SUBITEM_COUNT);
    OneOfMany_SetTexts(wsbook->SubMenu, items_text, SUBITEM_COUNT);
    OneOfMany_SetChecked(wsbook->SubMenu, GetChecked(wsbook->KeyMode));
    GUIObject_SoftKeys_SetAction(wsbook->SubMenu, ACTION_BACK, LinkSelector_Close);
    GUIObject_SoftKeys_SetAction(wsbook->SubMenu, ACTION_LONG_BACK, LinkSelector_Close);
    GUIObject_SoftKeys_SetAction(wsbook->SubMenu, ACTION_SELECT1, LinkSelector_SelectItem);
    GUIObject_Show(wsbook->SubMenu);
  }
}

void LinkEditor_SelectItem(BOOK *book, GUI *gui)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  wsbook->KeyMode = ListMenu_GetSelectedItem(wsbook->MainMenu);
  CreateLinkSelector(wsbook);
}

void LinkEditor_Close(BOOK *book, GUI *gui)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  FreeBook(wsbook);
}

int pg_WalkmanShortcut_EnterEvent(void *data, BOOK *book)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  if (wsbook->MainMenu = CreateListMenu(book, UIDisplay_Main))
  {
    TEXTID items_text[KEY_LAST] = {STR("Short Press"), STR("Long Press")};
    GUIObject_SetTitleText(wsbook->MainMenu, BUTTON_TXT);
    GUIObject_SetStyle(wsbook->MainMenu, UI_OverlayStyle_FullScreen);
    ListMenu_SetItemCount(wsbook->MainMenu, KEY_LAST);
    ListMenu_SetTexts(wsbook->MainMenu, items_text, KEY_LAST);
    ListMenu_SetCursorToItem(wsbook->MainMenu, SHORT_PRESS);
    GUIObject_SoftKeys_SetAction(wsbook->MainMenu, ACTION_BACK, LinkEditor_Close);
    GUIObject_SoftKeys_SetAction(wsbook->MainMenu, ACTION_LONG_BACK, LinkEditor_Close);
    GUIObject_SoftKeys_SetAction(wsbook->MainMenu, ACTION_SELECT1, LinkEditor_SelectItem);
    GUIObject_Show(wsbook->MainMenu);
  }
  return 1;
}

int pg_WalkmanShortcut_CancelEvent(void *data, BOOK *book)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  FREE_GUI(wsbook->MainMenu);
  return 1;
}

void WalkmanShortcutBook_onClose(BOOK *book)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)book;
  FREE_GUI(wsbook->MainMenu);
  FREE_GUI(wsbook->SubMenu);
}

extern "C" void LinkEditor(BOOK *book, GUI *gui)
{
  WalkmanShortcutBook *wsbook = (WalkmanShortcutBook *)malloc(sizeof(WalkmanShortcutBook));
  memset(wsbook, NULL, sizeof(WalkmanShortcutBook));
  if (CreateBook(wsbook, WalkmanShortcutBook_onClose, &WalkmanShortcut_Base_Page, "WalkmanShortcutBook", -1, NULL))
  {
    wsbook->short_press = GetChecked(SHORT_PRESS);
    wsbook->long_press = GetChecked(LONG_PRESS);
    BookObj_GotoPage(wsbook, &WalkmanShortcut_Main_Page);
  }
  else
  {
    mfree(wsbook);
  }
}

void NewAction(int item)
{
  if (item == 0)
    UI_Event(KEYPLAYSTOP_PRESSED_EVENT);
  else if (item == 1)
  {
    BOOK *audioBook = FindBook(IsAudioPlayerBook);
    if (audioBook && (MainDisplay_GetTopBook() != audioBook))
    {
      UI_Event(KEYPLAYSTOP_PRESSED_EVENT);
    }
    else if (audioBook && (MainDisplay_GetTopBook() == audioBook))
    {
      MediaPlayer_Audio_Minimize(audioBook, NULL);
    }
    else
    {
      Shortcut_Run(MEDIAPLAYER_LINK);
    }
  }
  else if (item == 2)
    Create_QuickAccessBook(-1);
  else if (item == 3)
    Create_RightNowBook(4, 0);
  else if (item == 4)
    Create_BookManager();
  else if (item == 5)
    NextBook();
  else if (item == 6)
    Screenshoter(Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main));
}

extern "C" int New_OnOffKey_Long_Pressed(void *data, BOOK *book)
{
  NewAction(GetChecked(LONG_PRESS));
  return 1;
}

extern "C" void New_OnOffKey_Short_Pressed()
{
  NewAction(GetChecked(SHORT_PRESS));
}
