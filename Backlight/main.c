//;Добавить возможность изменять время удержания подсветки для каждой BOOK
//;Установка параметров осуществляется в
//;Настройки -> Дисплей -> Яркость -> Настр.
//;(c) MaPkiZzz & ploik & BigHercules

/*<element id="Backlight_Set_Id">
 <label type="name"><text>Яркость в книгах</text>
 </label><link type="internal" />
</element>*/

#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "string_input.h"
#include "book_list.h"
#include "time_input.h"
#include "bright_input.h"

#include "Function.h"
#include "Data.h"
#include "Pages.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(0, size, 1, 5, "bc", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "bc", 0));
#else
  return (memalloc(size, 1, 5, "bc", 0));
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "bc", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "bc", 0);
#else
  memfree(mem, "bc", 0);
#endif
}

extern "C" int New_pg_Screensaver_Sleep(void *data, BOOK *book)
{
  if (IsBook_onTop(book) || IsBook_onTop(Find_StandbyBook()))
  {
    pg_Screensaver_Sleep(data, book);
  }
  return 1;
}

int Cancel_BasePage(void *r0, BOOK *book)
{
  FreeBook(book);
  return 1;
}

//-----------------------------------------------------------------------------------------------

int onCallback_MainList(GUI_MESSAGE *msg)
{
  TEXTID textid_name, textid_bright, textid_time;

  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
  {
    BacklightControlBook *BCBook = (BacklightControlBook *)GUIonMessage_GetBook(msg);
    FILEDATA *fdata = &((TEMPDATA *)BCBook->mydata)->fdata;
    int index = GUIonMessage_GetCreatedItemIndex(msg);

    textid_name = TextID_Create(GetNameFromData(fdata, index), ENC_LAT1, 0xFF);

    int brightness = (GetBrightFromData(fdata, index) * 10) + 10;
    textid_bright = TextID_CreateIntegerID(brightness);

    int timeint = GetTimeFromData(fdata, index);

    if (timeint == TIME_LIMIT)
    {
      textid_time = STR("Always On");
    }
    else
    {
      DATETIME dt;
      unixtime2datetime(timeint, &dt);
      dt.time.hour += (dt.date.day - 1) * 24;
      wchar_t timebuff[64];

      if (timeint <= 59)
      {
        snwprintf(timebuff, MAXELEMS(timebuff), L"%d sec.", dt.time.sec);
      }
      else if (timeint < (60 * 60))
      {
        snwprintf(timebuff, MAXELEMS(timebuff), L"%02d:%02d", dt.time.min, dt.time.sec);
      }
      else
      {
        snwprintf(timebuff, MAXELEMS(timebuff), L"%02d:%02d:%02d", dt.time.hour, dt.time.min, dt.time.sec);
      }
      textid_time = TextID_Create(timebuff, ENC_UCS2, TEXTID_ANY_LEN);
    }
#ifdef A2
    int strid[4];
    GUIonMessage_SetMenuItemText(msg, textid_name);
    GUIonMessage_SetMenuItemIcon(msg, 0, TEXT0_ICN);
    strid[3] = TextID_CreateCharacterID('%');
    strid[2] = textid_bright;
    strid[1] = TextID_CreateCharacterID('/');
    strid[0] = textid_time;
    textid_time = TextID_Create(strid, ENC_TEXTID, 4);
    GUIonMessage_SetMenuItemSecondLineText(msg, textid_time);
#else
    int strid[3];
    strid[2] = name;
    strid[1] = TextID_CreateCharacterID(' ');
    strid[0] = 0x78000000 + TEXT0_ICN;
    name = TextID_Create(strid, 5, 3);
    GUIonMessage_SetMenuItemText(msg, name);
    int secondline[6];
    secondline[5] = TextID_CreateCharacterID('%');
    secondline[4] = textid_bright;
    secondline[3] = TextID_CreateCharacterID(' ');
    secondline[2] = textid_time;
    secondline[1] = TextID_CreateCharacterID(' ');
    secondline[0] = 0x78000000 + TEXT1_ICN;
    textid_time = TextID_Create(secondline, ENC_TEXTID, 6);
    GUIonMessage_SetMenuItemSecondLineText(msg, textid_time);
#endif
    break;
  }
  }
  return 1;
}

void MainList_Select_Action(BOOK *bk, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)bk;
  FILEDATA *fdata = &((TEMPDATA *)BCBook->mydata)->fdata;

  int index = ListMenu_GetSelectedItem(BCBook->main_menu);

  strncpy(BCBook->fdata.bookname, GetNameFromData(fdata, index), BOOKNAME_MAX_LEN);

  unsigned int timeint = GetTimeFromData(fdata, index);
  if (timeint == 0xFFFFFFFF)
    timeint = NULL;

  DATETIME dt;
  unixtime2datetime(timeint, &dt);
  dt.time.hour += (dt.date.day - 1) * 24;

  BCBook->time = &dt.time;
  Backlight_TimeInput(BCBook);
}

//-------------------------------------------------------------------------

void MainList_OnDelete_Yes(BOOK *bk, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)bk;
  int index = ListMenu_GetSelectedItem(BCBook->main_menu);
  DeleteData(index, BCBook, BCBook->itemcount);
  BookObj_GotoPage(BCBook, &BacklightControlBook_Main_Page);
}

void MainList_OnDelete_No(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  BookObj_GotoPage(BCBook, &BacklightControlBook_Main_Page);
}

void MainList_OnDelete(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;

  if (BCBook->delete_item = CreateYesNoQuestion(BCBook, UIDisplay_Main))
  {
    YesNoQuestion_SetIcon(BCBook->delete_item, REQUEST_ICN);
    YesNoQuestion_SetQuestionText(BCBook->delete_item, STR("Do you want to remove this Book from list?"));
    GUIObject_SoftKeys_SetAction(BCBook->delete_item, ACTION_YES, MainList_OnDelete_Yes);
    GUIObject_SoftKeys_SetAction(BCBook->delete_item, ACTION_NO, MainList_OnDelete_No);
    GUIObject_SoftKeys_SetAction(BCBook->delete_item, ACTION_LONG_BACK, MainList_OnDelete_No);
    GUIObject_Show(BCBook->delete_item);
  }
}

//-------------------------------------------------------------------------

void MainList_EnterBooksList_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  Backlight_BookListsMenu(BCBook);
}

void MainList_AddSI_Action(BOOK *book, GUI *gui)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  Backlight_BooknameInput(BCBook);
}

void MainList_Close_Action(BOOK *book, GUI *gui)
{
  FreeBook(book);
}

void MainList_Cancel_Action(BOOK *book, GUI *gui)
{
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void Clear_TempData(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  if (BCBook->mydata)
  {
    mfree(BCBook->mydata);
    BCBook->mydata = NULL;
    BCBook->itemcount = NULL;
  }
}

void Get_CurrentData(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    TEMPDATA *mydata = (TEMPDATA *)malloc(size);
    BCBook->mydata = mydata;
    GetData(mydata, size);
    BCBook->itemcount = mydata->count;
  }
  else
  {
    BCBook->mydata = NULL;
    BCBook->itemcount = NULL;
  }
}

int BacklightControlBook_Main_Page_Enter_Event(void *r0, BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->main_menu);

  Clear_TempData(BCBook);
  Get_CurrentData(BCBook);

  if (BCBook->main_menu = CreateListMenu(BCBook, UIDisplay_Main))
  {
    GUIObject_SetStyle(BCBook->main_menu, UI_OverlayStyle_FullScreen);
    GUIObject_SetTitleType(BCBook->main_menu, UI_TitleMode_Large);
    GUIObject_SetTitleText(BCBook->main_menu, STR("Brightness Settings"));
    GUIObject_SetSecondRowTitleText(BCBook->main_menu, STR("Menu|Time|Bright"));
    ListMenu_SetItemCount(BCBook->main_menu, BCBook->itemcount);
    ListMenu_SetCursorToItem(BCBook->main_menu, 0);
    ListMenu_SetOnMessage(BCBook->main_menu, onCallback_MainList);
    ListMenu_SetItemStyle(BCBook->main_menu, 3);
    ListMenu_SetItemTextScroll(BCBook->main_menu, 1);
    GUIObject_SoftKeys_SetAction(BCBook->main_menu, ACTION_BACK, MainList_Close_Action);
    GUIObject_SoftKeys_SetAction(BCBook->main_menu, ACTION_LONG_BACK, MainList_Cancel_Action);
    GUIObject_SoftKeys_SetActionAndText(BCBook->main_menu, 0, MainList_AddSI_Action, STR("Add"));
    GUIObject_SoftKeys_SetActionAndText(BCBook->main_menu, 1, MainList_EnterBooksList_Action, STR("Open"));

    if (BCBook->itemcount)
    {
      GUIObject_SoftKeys_SetActionAndText(BCBook->main_menu, ACTION_SELECT1, MainList_Select_Action, STR("Edit"));
      GUIObject_SoftKeys_SetAction(BCBook->main_menu, ACTION_DELETE, MainList_OnDelete);
      GUIObject_SoftKeys_SetVisible(BCBook->main_menu, ACTION_DELETE, FALSE);
    }
    else
    {
      ListMenu_SetNoItemText(BCBook->main_menu, STR("No Book(s) selected"));
    }
    GUIObject_Show(BCBook->main_menu);
  }
  return 1;
}

void BacklightControlBook_Destroy(BOOK *book)
{
  BacklightControlBook *BCBook = (BacklightControlBook *)book;
  FREE_GUI(BCBook->main_menu);
  FREE_GUI(BCBook->books_list);
  FREE_GUI(BCBook->string_input);
  FREE_GUI(BCBook->time_input);
  FREE_GUI(BCBook->bright_input);
  FREE_GUI(BCBook->delete_item);

  if (BCBook->mydata)
    mfree(BCBook->mydata);
  BCBook->time = NULL;
  BCBook->bright = NULL;

  BookLists_FreeList(BCBook);
}

BOOK *CreateBacklightControlBook()
{
  BacklightControlBook *BCBook = (BacklightControlBook *)malloc(sizeof(BacklightControlBook));
  memset(BCBook, NULL, sizeof(BacklightControlBook));
  CreateBook(BCBook, BacklightControlBook_Destroy, &BacklightControlBook_Base_Page, "BacklightControlBook", -1, 0);
  BCBook->main_menu = NULL;
  BCBook->books_list = NULL;
  BCBook->string_input = NULL;
  BCBook->time_input = NULL;
  BCBook->bright_input = NULL;
  BCBook->delete_item = NULL;
  BCBook->mydata = NULL;
  BCBook->itemcount = NULL;
  BCBook->bookcount = NULL;
  BCBook->time = NULL;
  BCBook->bright = NULL;
  BCBook->book_list = NULL;
  return BCBook;
}

void BacklightControlMenu()
{
  BacklightControlBook *BCBook = (BacklightControlBook *)CreateBacklightControlBook();
  if (BCBook)
    BookObj_GotoPage(BCBook, &BacklightControlBook_Main_Page);
}

TEXTID GetSecondLine()
{
  int count;
  TEXTID SecondLine;
  FSTAT _fstat;

  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    char *mydata = (char *)malloc(size);
    TEMPDATA *tmpdata = (TEMPDATA *)mydata;
    GetData(mydata, size);
    count = tmpdata->count;

    if (count)
    {
      TEXTID txt_id[2];
      txt_id[0] = STR("Book(s) count: ");
      txt_id[1] = TextID_CreateIntegerID(count);
      SecondLine = TextID_Create(txt_id, ENC_TEXTID, 2);
    }
    else
    {
      SecondLine = STR("No Book selected");
    }
  }
  else
    SecondLine = STR("No Data =)");
  return SecondLine;
}

extern "C" void New_GUIObject_SetFocus(GUI *gui)
{
  int count;
  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int fsize = _fstat.fsize;
    char *mydata = (char *)malloc(fsize);
    TEMPDATA *tmpdata = (TEMPDATA *)mydata;
    GetData(mydata, fsize);
    count = tmpdata->count;

    char bookname[BOOKNAME_MAX_LEN + 1];
    TextID_GetString(GetBookName(GUIObject_GetBook(gui)), bookname, BOOKNAME_MAX_LEN);

    for (int index = 0; index < count; index++)
    {
      if (!strcmp(GetNameFromData((FILEDATA *)(mydata + 4), index), bookname))
      {
        int brightness = (GetBrightFromData((FILEDATA *)(mydata + 4), index) * 10) + 10;
        int timeout = GetTimeFromData((FILEDATA *)(mydata + 4), index) * 1000;

        GUIObject_SetBacklightTimeout(gui, timeout);
#ifdef A1
        Display_SetBrightness(UIDisplay_Main, brightness);
#else
        Display_SetBrightness(brightness);
#endif
      }
    }
    mfree(mydata);
  }
  else
  {
    GUIObject_SetBacklightTimeout(gui, 20000);
#ifdef A1
    Display_SetBrightness(UIDisplay_Main, 60);
#else
    Display_SetBrightness(60);
#endif
  }
}

extern "C" void New_BookObj_SetFocus(BOOK *book, int display)
{
  int count;
  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);

  if (file >= 0)
  {
    int size = _fstat.fsize;
    char *mydata = (char *)malloc(size);
    TEMPDATA *tmpdata = (TEMPDATA *)mydata;
    GetData(mydata, size);
    count = tmpdata->count;

    char bookname[BOOKNAME_MAX_LEN + 1];
    TextID_GetString(GetBookName(book), bookname, BOOKNAME_MAX_LEN);

    if (book)
    {
      for (int index = 0; index < count; index++)
      {
        if (!strcmp(GetNameFromData((FILEDATA *)(mydata + 4), index), bookname))
        {
          int brightness = (GetBrightFromData((FILEDATA *)(mydata + 4), index) * 10) + 10;
#ifdef A1
          Display_SetBrightness(UIDisplay_Main, brightness);
#else
          Display_SetBrightness(brightness);
#endif
          Session_SetFocus(BookObj_GetSession(book), display);
        }
        else
        {
#ifdef A1
          Display_SetBrightness(UIDisplay_Main, 60);
#else
          Display_SetBrightness(60);
#endif
          Session_SetFocus(BookObj_GetSession(book), display);
        }
      }
    }
  }
}

__thumb void BacklightSetttings(DYNAMIC_MENU_ELEMENT *DME)
{
  switch (DynamicMenu_GetElementMsg(DME))
  {
  case DYNAMIC_MENU_onCall:
    BacklightControlMenu();
    break;
  case DYNAMIC_MENU_onText:
    TEXTID SecondLine = GetSecondLine();
    DynamicMenu_SetElement_SecondLineText(DME, SecondLine);
    break;
  }
}

#define MENU_Backlight_ID (L"Backlight_Set_Id")

#pragma diag_suppress = Pe177
__root const int PATCH_Backlight @ "PATCH_Backlight" = (int)MENU_Backlight_ID;
__root const int PATCH_RUN_Backlight @ "PATCH_RUN_Backlight" = (int)BacklightSetttings;
