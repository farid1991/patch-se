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
  return (memalloc(NULL, size, 1, 5, GT_MEM, NULL));
#elif defined(A2)
  return (memalloc(-1, size, 1, 5, GT_MEM, NULL));
#else
  return (memalloc(size, 1, 5, GT_MEM, NULL));
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, GT_MEM, NULL);
#elif defined(A2)
    memfree(NULL, mem, GT_MEM, NULL);
#else
    memfree(mem, GT_MEM, NULL);
#endif
}

#if defined(DB2000)
BOOL FSX_IsFileExists(const wchar_t *fpath, const wchar_t *fname)
{
  FSTAT fs;
  if (!fstat(fpath, fname, &fs))
    return TRUE;
  return FALSE;
}
#endif

void ShortcutFree(void *item)
{
  SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)item;
  if (Shortcut)
  {
    mfree(Shortcut->ShortcutLink);
    mfree(Shortcut->ShortcutText);
    mfree(Shortcut);
  }
}

void Menu_Delete_Yes(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);

  void *item = List_RemoveAt(mbk->ShortcutList, mbk->CurrentItem);
  ShortcutFree(item);

  SaveConfig(mbk->ShortcutList);
  pg_Goto_Shortcut_AcceptEvent(NULL, mbk);
}

void Menu_Delete_No(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);
  pg_Goto_Shortcut_AcceptEvent(NULL, mbk);
}

void Menu_DeleteItem(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

  if (List_GetCount(mbk->ShortcutList))
  {
    SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, ListMenu_GetSelectedItem(mbk->MainMenu));

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
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  EditorRun(mbk, ADDING_MODE);
}

void Menu_ModifyItem(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  if (List_GetCount(mbk->ShortcutList))
  {
    EditorRun(mbk, EDITING_MODE);
  }
  else
  {
    CreateMessageBox(EMPTY_TEXTID, EMPTY_LIST_TXT, 1, 0, mbk);
  }
}

void Menu_About(BOOK *book, GUI *gui)
{
  TEXTID Text = TextID_Get(L"GotoShortcut\nv3.5\n(c) farid");
  CreateMessageBox(EMPTY_TEXTID, Text, 1, 0, book);
}

void Menu_Select(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, ListMenu_GetSelectedItem(mbk->MainMenu));
  if (Shortcut)
  {
    RunShortcut(Shortcut);
  }

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
    SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, index);

    GUIonMessage_SetMenuItemText(msg, TextID_Get(Shortcut->ShortcutText));
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, Shortcut->ShortcutIcon);
    break;
  }
  return 1;
}

int pg_Goto_Shortcut_EnterEvent(void *data, BOOK *book)
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
    ListMenu_SetHotkeyMode(mbk->MainMenu, LKHM_SHORTCUT);
#ifndef DB2000
    ListMenu_SetItemTextScroll(mbk->MainMenu, 0);
#endif
#if defined(DB2020) || defined(A2)
    ListMenu_SetNoItemText(mbk->MainMenu, EMPTY_LIST_TXT);
#endif
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 0, MENU_ADD_TXT);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0, Menu_AddItem);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 1, MENU_MODIFY_TXT);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 1, Menu_ModifyItem);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 2, MENU_ABOUT_TXT);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 2, Menu_About);
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

int pg_Goto_Shortcut_CancelEvent(void *data, BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  FREE_GUI(mbk->MainMenu);
  return 1;
}

int pg_Goto_Shortcut_AcceptEvent(void *data, BOOK *book)
{
  BookObj_GotoPage(book, &Goto_Shortcut_Main_Page);
  return 0;
}

void Goto_Shortcut_onClose(BOOK *book)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
  SaveConfig(mbk->ShortcutList);
  FREE_GUI(mbk->MainMenu);
  FREE_GUI(mbk->Editor);
#ifdef USE_JAVA
  FREE_GUI(mbk->JavaMenu);
#endif
  FREE_GUI(mbk->TypesList);
  FREE_GUI(mbk->CaptionInput);
  FREE_GUI(mbk->YesNoQuestion);
  FREE_GUI(mbk->EventInput);
  FreeList(mbk->ShortcutList, ShortcutFree);
}

BOOL IsGotoShortcutBook(BOOK *book)
{
  if (book->onClose == Goto_Shortcut_onClose)
    return TRUE;
  return FALSE;
}

GotoShortcut_Book *Create_GotoShortcutBook()
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)malloc(sizeof(GotoShortcut_Book));
  memset(mbk, NULL, sizeof(GotoShortcut_Book));

  if (!CreateBook(mbk, Goto_Shortcut_onClose, &Goto_Shortcut_Base_Page, BOOKNAME, NO_BOOK_ID, NULL))
  {
    mfree(mbk);
    return NULL;
  }
  mbk->MainMenu = NULL;
  mbk->Editor = NULL;
#ifdef USE_JAVA
  mbk->JavaMenu = NULL;
  mbk->JavaList = NULL;
#endif
  mbk->TypesList = NULL;
  mbk->CaptionInput = NULL;
  mbk->YesNoQuestion = NULL;
  mbk->EventInput = NULL;
  mbk->CurrentItem = NULL;
  mbk->ShortcutList = NULL;
  mbk->FType = NULL;
  return mbk;
}

extern "C" void GotoShortcut(BOOK *book, GUI *gui)
{
  GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsGotoShortcutBook);
  if (!mbk)
  {
    mbk = Create_GotoShortcutBook();
    mbk->ShortcutList = LoadConfig();
    BookObj_GotoPage(mbk, &Goto_Shortcut_Main_Page);
  }
  else
  {
    BookObj_SetFocus(mbk, UIDisplay_Main);
  }
}
