#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "book_list.h"
#include "main.h"
#include "Data.h"
#include "time_input.h"

void BookLists_FreeList(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  LIST *list = BCBook->book_list;
  BOOK_ITEM *book_item;

  if (BCBook->book_list)
  {
    while (List_GetCount(list))
    {
      book_item = (BOOK_ITEM *)List_RemoveFirst(list);
      TextID_Destroy(book_item->book_name);
      book_item->book_icon = NULL;
      mfree(book_item);
    }
    List_Destroy(list);
    BCBook->bookcount = NULL;
  }
}

int GetJavaName(BOOK *book)
{
  char javaname[BOOKNAME_MAX_LEN + 1];
  TextID_GetString(BookObj_GetSession(book)->name, javaname, BOOKNAME_MAX_LEN);

  if (!strncmp(javaname, "Foreign app", 11))
  {
    return JavaSession_GetName();
  }
  if (!strcmp(javaname, "Java"))
  {
    return JavaSession_GetName();
  }
  return NULL;
}

TEXTID GetBookName(BOOK *book)
{
  TEXTID BookName;
  if (!strcmp(book->xbook->name, "CUIDisplayableBook"))
  {
    BookName = TextID_Copy(BookObj_GetSession(book)->name);
  }
  else
  {
    BookName = TextID_Create(book->xbook->name, ENC_LAT1, TEXTID_ANY_LEN);
  }
#ifndef DB3350
  if (int JavaName = GetJavaName(book))
  {
    TextID_Destroy(BookName);
    return JavaName;
  }
#endif
  return BookName;
}

BOOL IsRSSTickerBook(BOOK *book)
{
  return FALSE == strcmp(book->xbook->name, "RSSTicker_Book");
}

void BookLists_CreateList(BOOK *bk)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)bk;
  BookLists_FreeList(BCBook);
  BCBook->book_list = List_Create();

  BOOK *book;
  UI_APP_SESSION *session;
  BOOK_ITEM *book_item;

  int mask = ((int)LASTEXTDB) & FLASH_MASK;

  int session_count, session_index, listbook_index;

  session_count = root_list_get_session_count();
  for (session_index = 0; session_index < session_count; session_index++)
  {
    book_item = NULL;
    session = root_list_get_session(session_index);
    for (listbook_index = 0; listbook_index < List_GetCount(session->listbook); listbook_index++)
    {
      book = (BOOK *)List_Get(session->listbook, listbook_index);

      if (List_GetCount(book->xguilist->guilist) || (((int)book->onClose) & FLASH_MASK) != mask)
      {
        if ((!IsVolumeControllerBook(book)) && (!IsRightNowBook(book)) && (!IsRSSTickerBook(book)))
        {
          book_item = (BOOK_ITEM *)malloc(sizeof(BOOK_ITEM));
          book_item->book_name = GetBookName(book);
          book_item->book_icon = ITEM_BOOK_ICN;
          List_InsertFirst(BCBook->book_list, book_item);
        }
      }
    }
  }
  BCBook->bookcount = List_GetCount(BCBook->book_list);
}

int onCallback_BookList(GUI_MESSAGE *msg)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)GUIonMessage_GetBook(msg);
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    BOOK_ITEM *book_item = (BOOK_ITEM *)List_Get(BCBook->book_list, item);
    GUIonMessage_SetMenuItemText(msg, TextID_Copy(book_item->book_name));
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, book_item->book_icon);
    break;
  }
  return 1;
}

void BookLists_Prev_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->books_list);
}

void BookLists_Select_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;

  int book_index = ListMenu_GetSelectedItem(BCBook->books_list);
  BOOK_ITEM *book_item = (BOOK_ITEM *)List_Get(BCBook->book_list, book_index);
  TextID_GetString(book_item->book_name, BCBook->fdata.bookname, BOOKNAME_MAX_LEN);

  TIME time;
  time.hour = 0;
  time.min = 0;
  time.sec = 0;
  BCBook->time = &time;
  Backlight_TimeInput(BCBook);
}

void Backlight_BookListsMenu(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;

  BookLists_CreateList(BCBook);

  FREE_GUI(BCBook->books_list);
  if (BCBook->books_list = CreateListMenu(BCBook, UIDisplay_Main))
  {
    GUIObject_SetStyle(BCBook->books_list, UI_OverlayStyle_FullScreen);
    GUIObject_SetTitleText(BCBook->books_list, STR("Open Books"));
    ListMenu_SetOnMessage(BCBook->books_list, onCallback_BookList);
    ListMenu_SetItemCount(BCBook->books_list, BCBook->bookcount);
    ListMenu_SetCursorToItem(BCBook->books_list, 0);
    GUIObject_SoftKeys_SetAction(BCBook->books_list, ACTION_BACK, BookLists_Prev_Action);
    GUIObject_SoftKeys_SetAction(BCBook->books_list, ACTION_LONG_BACK, BookLists_Prev_Action);
    if (List_GetCount(BCBook->book_list))
    {
      GUIObject_SoftKeys_SetAction(BCBook->books_list, ACTION_SELECT1, BookLists_Select_Action);
    }
    GUIObject_Show(BCBook->books_list);
  }
}
