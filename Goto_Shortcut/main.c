#include "temp\target.h"

#include "..\\include\Types.h"

#include "Lib.h"
#include "main.h"
#include "editor.h"
#include "utils.h"
#include "strlib.h"
#include "FileFolder.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(0, size, 1, 5, "sc", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "sc", 0));
#else
  return (memalloc(size, 1, 5, "sc", 0));
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "sc", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "sc", 0);
#else
  memfree(mem, "sc", 0);
#endif
}

void ShortcutFree(void *Item)
{
  SHORTCUT *Shortcut = (SHORTCUT *)Item;
  if (Shortcut)
  {
    WStringFree(Shortcut->ShortcutLink);
    WStringFree(Shortcut->ShortcutText);
    mfree(Shortcut);
  }
}

void Menu_Delete_Yes(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);

  void *Item = List_RemoveAt(mbk->ShortcutList, mbk->CurrentItem);
  ShortcutFree(Item);
  UpdateMainPage(NULL, mbk);
}

void Menu_Delete_No(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);
  UpdateMainPage(NULL, mbk);
}

void Menu_DeleteItem(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

  if (List_GetCount(mbk->ShortcutList))
  {
    SHORTCUT *Shortcut = (SHORTCUT *)List_Get(mbk->ShortcutList, ListMenu_GetSelectedItem(mbk->MainMenu));

    if (mbk->YesNoQuestion = CreateYesNoQuestion(mbk, UIDisplay_Main))
    {
      YesNoQuestion_SetQuestionText(mbk->YesNoQuestion, DELETEQ_TXT);
      YesNoQuestion_SetDescriptionText(mbk->YesNoQuestion, TextID_Get(Shortcut->ShortcutText));
      YesNoQuestion_SetIcon(mbk->YesNoQuestion, Shortcut->ShortcutIcon);
      GUIObject_SoftKeys_SetAction(mbk->YesNoQuestion, ACTION_YES, Menu_Delete_Yes);
      GUIObject_SoftKeys_SetAction(mbk->YesNoQuestion, ACTION_NO, Menu_Delete_No);
      GUIObject_Show(mbk->YesNoQuestion);
    }
  }
}

void Menu_AddItem(BOOK *book, GUI *gui)
{
  EditorRun(book, ADDING_MODE);
}

void Menu_ModifyItem(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  if (List_GetCount(mbk->ShortcutList))
  {
    EditorRun(mbk, EDITING_MODE);
  }
  else
    CreateMessageBox(EMPTY_TEXTID, EMPTY_LIST_TXT, 1, 3000, mbk);
}

void Menu_About(BOOK *book, GUI *gui)
{
  TEXTID Text = TextID_Get(L"GotoShortcut\nv3.0\n(c) farid");
  CreateMessageBox(EMPTY_TEXTID, Text, 1, 0, book);
}

void Menu_Select(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  SHORTCUT *sc = (SHORTCUT *)List_Get(mbk->ShortcutList, ListMenu_GetSelectedItem(mbk->MainMenu));
  if (sc)
    RunShortcut(sc);

  FreeBook(mbk);
}

void Menu_Exit(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FreeBook(mbk);
}

int Menu_onMessage(GUI_MESSAGE *msg)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);
  int count = List_GetCount(mbk->ShortcutList);
  if (!count)
    return 0;

  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);
    SHORTCUT *Shortcut = (SHORTCUT *)List_Get(mbk->ShortcutList, index);

    GUIonMessage_SetMenuItemText(msg, TextID_Get(Shortcut->ShortcutText));
    GUIonMessage_SetMenuItemIcon(msg, 0, Shortcut->ShortcutIcon);
    break;
  }
  return 1;
}

int pg_Goto_Shortcut_EnterAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->MainMenu);

  int count = List_GetCount(mbk->ShortcutList);

  if (mbk->MainMenu = CreateListMenu(mbk, UIDisplay_Main))
  {
    GUIObject_SetTitleText(mbk->MainMenu, TITLE_TXT);

    ListMenu_SetItemCount(mbk->MainMenu, count);
    ListMenu_SetOnMessage(mbk->MainMenu, Menu_onMessage);
    ListMenu_SetCursorToItem(mbk->MainMenu, mbk->CurrentItem);
    ListMenu_SetItemTextScroll(mbk->MainMenu, 0);
    ListMenu_SetHotkeyMode(mbk->MainMenu, LKHM_SHORTCUT);
    ListMenu_SetNoItemText(mbk->MainMenu, EMPTY_LIST_TXT);

    GUIObject_SoftKeys_SetActionAndText(mbk->MainMenu, 0, Menu_AddItem, MENU_ADD_TXT);
    GUIObject_SoftKeys_SetActionAndText(mbk->MainMenu, 1, Menu_ModifyItem, MENU_MODIFY_TXT);
    GUIObject_SoftKeys_SetActionAndText(mbk->MainMenu, 2, Menu_About, MENU_ABOUT_TXT);

    if (count)
    {
      GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_DELETE, Menu_DeleteItem);
      GUIObject_SoftKeys_SetVisible(mbk->MainMenu, ACTION_DELETE, FALSE);
      GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_SELECT1, Menu_Select);
    }
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_BACK, Menu_Exit);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_LONG_BACK, Menu_Exit);
    GUIObject_Show(mbk->MainMenu);
  }
  return 1;
};

int pg_Goto_Shortcut_CancelAction(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->MainMenu);
  FreeBook(mbk);
  return 1;
}

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, pg_Goto_Shortcut_CancelAction,
        RETURN_TO_STANDBY_EVENT, pg_Goto_Shortcut_CancelAction,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Shortcut_Base_Page = {BASE_PAGE_NAME, NULL, bk_msglst_base};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, pg_Goto_Shortcut_EnterAction,
        PAGE_EXIT_EVENT, pg_Goto_Shortcut_EnterAction,
        ACCEPT_EVENT, UpdateMainPage,
        NIL_EVENT, NULL};
const PAGE_DESC Goto_Shortcut_Main_Page = {MAIN_PAGE_NAME, NULL, bk_msglst_main};

int UpdateMainPage(void *data, BOOK *book)
{
  BookObj_GotoPage(book, &Goto_Shortcut_Main_Page);
  return 0;
}

void Goto_Shortcut_onClose(BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->MainMenu);
  FREE_GUI(mbk->Editor);
#ifndef DB3350
  FREE_GUI(mbk->JavaMenu);
#endif
  FREE_GUI(mbk->TypesList);
  FREE_GUI(mbk->CaptionInput);
  FREE_GUI(mbk->YesNoQuestion);
  FREE_GUI(mbk->EventInput);
  SaveConfig(mbk->ShortcutList);
  FreeList(mbk->ShortcutList, ShortcutFree);
}

int IsMyBook(BOOK *book)
{
  if (strcmp(book->xbook->name, BOOKNAME))
    return FALSE;
  return TRUE;
}

extern "C" void GotoShortcut(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsMyBook);
  if (!mbk)
  {
    mbk = (GotoShortcut_Book *)malloc(sizeof(GotoShortcut_Book));
    memset(mbk, NULL, sizeof(GotoShortcut_Book));
    if (CreateBook(mbk, Goto_Shortcut_onClose, &Goto_Shortcut_Base_Page, BOOKNAME, -1, NULL))
    {
      mbk->CurrentItem = 0;
      mbk->ShortcutList = LoadConfig();
      BookObj_GotoPage(mbk, &Goto_Shortcut_Main_Page);
    }
    else
      mfree(mbk);
  } else
  {
    BookObj_SetFocus(mbk, UIDisplay_Main);
  }
}
