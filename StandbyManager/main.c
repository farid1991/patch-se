#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\StandbyBook.h"

#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, "sm_mem", 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, "sm_mem", 0);
#else
  return memalloc(size, 1, 5, "sm_mem", 0);
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
  if (mem)
    memfree(0, mem, "sm_mem", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "sm_mem", 0);
#else
  memfree(mem, "sm_mem", 0);
#endif
}

void ReadData(void *mydata, int size)
{
  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_CREAT | FSX_O_APPEND, FSX_S_IRUSR | FSX_S_IWUSR, 0);
  if (file >= 0)
  {
    fread(file, mydata, size);
    fclose(file);
  }
}

void WriteData(BOOK *book)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;

  FILE_DATA *fd = (FILE_DATA *)malloc(sizeof(FILE_DATA));
  memset(fd, Item_NotSelected, sizeof(FILE_DATA));
  ReadData(fd, sizeof(FILE_DATA));

  StandbyBook *sby_book = (StandbyBook *)Find_StandbyBook();
  DISP_OBJ *sby_disp_obj = GUIObject_GetDispObject(sby_book->StatusIndication);
  DispObject_StatusIndication_SetItemText(sby_disp_obj, fd->item[SMBook->fileitem], EMPTY_TEXTID);

  fd->item[SMBook->fileitem] = SMBook->itemID;

  if (SMBook->fileitem == 2)
  {
    wchar_t buff[128];
    DispObject_StatusIndication_SetItemText(sby_disp_obj, SMBook->itemID, GetOperatorName(buff));
  }

  if (SMBook->fileitem == 5)
  {
    int _SYNC = NULL;
    int *SYNC = &_SYNC;
    int num;
    TEXTID_DATA GetProfile;
    wchar_t SetName[0x10];
    char error;
    GetProfile.ptr = SetName;
    REQUEST_PROFILE_GETACTIVEPROFILE(SYNC, &num);
    REQUEST_PROFILE_GETPROFILENAME(SYNC, -2, &GetProfile, &error);

    if (num > 0)
    {
      DispObject_StatusIndication_SetItemText(sby_disp_obj, SMBook->itemID, TextID_Create(GetProfile.ptr, ENC_UCS2, GetProfile.lenght));
    }
    else
    {
      DispObject_StatusIndication_SetItemText(sby_disp_obj, SMBook->itemID, EMPTY_TEXTID);
    }
  }

  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IRUSR | FSX_S_IWUSR, 0);
  if (file >= 0)
  {
    fwrite(file, fd, sizeof(FILE_DATA));
    fclose(file);
  }
  mfree(fd);
}

void RefreshEdList(BOOK *book)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;
  ListMenu_DestroyItems(SMBook->MainMenu);
  ListMenu_SetItemCount(SMBook->MainMenu, FILE_COUNT);
  ListMenu_SetCursorToItem(SMBook->MainMenu, ListMenu_GetSelectedItem(SMBook->MainMenu));
  GUIObject_SoftKeys_SetVisible(SMBook->MainMenu, ACTION_SELECT1, TRUE);
}

void onEnterSetID(BOOK *book, GUI *gui)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;
  switch (OneOfMany_GetSelected(SMBook->SubMenu))
  {
  case 0:
    SMBook->itemID = Item_NotSelected;
    break;
  case 1:
    SMBook->itemID = Item_Operator3;
    break;
  case 2:
    SMBook->itemID = Item_Operator2;
    break;
  case 3:
    SMBook->itemID = Item_Operator1;
    break;
  case 4:
    SMBook->itemID = Item_SearchAndFlightmode;
    break;
  case 5:
    SMBook->itemID = Item_NoSignal;
    break;
  case 6:
    SMBook->itemID = Item_ProfileName;
    break;
  case 7:
    SMBook->itemID = Item_Notes;
    break;
  case 8:
    SMBook->itemID = Item_BigClock;
    break;
  case 9:
    SMBook->itemID = Item_SmallClock;
    break;
  case 10:
    SMBook->itemID = Item_Date;
    break;
  case 11:
    SMBook->itemID = Item_Alarm;
    break;
  case 12:
    SMBook->itemID = Item_Timer;
    break;
  case 13:
    SMBook->itemID = Item_CallTime;
    break;
  case 14:
    SMBook->itemID = Item_Shift;
    break;
#ifdef W580_R8BE001
  case 15:
    SMBook->itemID = Item_W580_Accel;
    break;
#endif
  }
  WriteData(SMBook);
  FREE_GUI(SMBook->SubMenu);
#ifdef A2
  RefreshEdList(SMBook);
#endif
}

void Close_EditItem(BOOK *book, GUI *gui)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;
  FREE_GUI(SMBook->SubMenu);
#ifdef A2
  RefreshEdList(SMBook);
#endif
}

int Check_Num(int itemnum)
{
  int result = Item_NotSelected;

  if (itemnum != Item_NotSelected)
  {
    FSTAT _fstat;
    int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
    if (file >= 0)
    {
      int size = _fstat.fsize;
      FILE_DATA *mydata = (FILE_DATA *)malloc(size);
      ReadData(mydata, size);

      if (mydata->item[itemnum] != Item_NotSelected)
        result = mydata->item[itemnum];
      mfree(mydata);
    }
  }
  else
  {
    result = Item_UnSelected;
  }
  return result;
}

int GetPatchID(int SI_Items)
{
  int result;
  switch (SI_Items)
  {
  case Item_Operator3:
    result = 0;
    break;
  case Item_Operator2:
    result = 1;
    break;
  case Item_Operator1:
    result = 2;
    break;
  case Item_SearchAndFlightmode:
    result = 3;
    break;
  case Item_NoSignal:
    result = 4;
    break;
  case Item_ProfileName:
    result = 5;
    break;
  case Item_Notes:
    result = 6;
    break;
  case Item_BigClock:
    result = 7;
    break;
  case Item_SmallClock:
    result = 8;
    break;
  case Item_Date:
    result = 9;
    break;
  case Item_Alarm:
    result = 10;
    break;
  case Item_Timer:
    result = 11;
    break;
  case Item_CallTime:
    result = 12;
    break;
  case Item_Shift:
    result = 13;
    break;
#ifdef W580_R8BE001
  case Item_W580_Accel:
    result = 14;
    break;
#endif
  default:
    result = Item_NotSelected;
    break;
  }
  return (result);
}

int GetChecked(int itemnum)
{
  int checked;

  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA *)malloc(size);
    ReadData(mydata, size);
    checked = GetPatchID(mydata->item[itemnum]);

    if (checked == Item_NotSelected)
      checked = 0;
    else
      checked += 1;

    mfree(mydata);
  }
  return checked;
}

int CreateEditItem(BOOK *book)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;

  if (SMBook->SubMenu = CreateOneOfMany(SMBook))
  {
    GUIObject_SetTitleText(SMBook->SubMenu, TEXTID_TITLE);
    OneOfMany_SetTexts(SMBook->SubMenu, (TEXTID *)items_text, FILE_COUNT + 1);
    OneOfMany_SetChecked(SMBook->SubMenu, GetChecked(SMBook->fileitem));
    GUIObject_SetStyle(SMBook->SubMenu, 2);
    GUIObject_SoftKeys_SetAction(SMBook->SubMenu, ACTION_BACK, Close_EditItem);
    GUIObject_SoftKeys_SetAction(SMBook->SubMenu, ACTION_LONG_BACK, Close_EditItem);
    GUIObject_SoftKeys_SetAction(SMBook->SubMenu, ACTION_SELECT1, onEnterSetID);
    GUIObject_Show(SMBook->SubMenu);
  }
  return 1;
}

int GetTextID(int ItemID)
{
  int result;
  switch (ItemID)
  {
  case Item_Operator3:
    result = TEXTID_OP3;
    break;
  case Item_Operator2:
    result = TEXTID_OP2;
    break;
  case Item_Operator1:
    result = TEXTID_OP1;
    break;
  case Item_SearchAndFlightmode:
    result = TEXTID_SF;
    break;
  case Item_NoSignal:
    result = TEXTID_NO;
    break;
  case Item_ProfileName:
    result = TEXTID_PROF;
    break;
  case Item_Notes:
    result = TEXTID_NOTES;
    break;
  case Item_BigClock:
    result = TEXTID_BIG_TIME;
    break;
  case Item_SmallClock:
    result = TEXTID_TIME;
    break;
  case Item_Date:
    result = TEXTID_DATE;
    break;
  case Item_Alarm:
    result = TEXTID_ALARM;
    break;
  case Item_Timer:
    result = TEXTID_TIMER;
    break;
  case Item_CallTime:
    result = TEXTID_TALK;
    break;
  case Item_Shift:
    result = TEXTID_SHIFT;
    break;
#ifdef W580_R8BE001
  case Item_W580_Accel:
    result = TEXTID_ACCEL;
    break;
#endif
  default:
    result = TEXTID_SWITCHED_OFF;
    break;
  }
  return (result);
}

void CloseStandbyManager_Book(BOOK *book, GUI *gui)
{
  FreeBook(book);
}

void LCloseStandbyManager_Book(BOOK *book, GUI *gui)
{
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void Copyright(BOOK *book, GUI *gui)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;
  TEXTID text = STR("Standby Manager\n\n(c) Ploik & MaPkiZzz\n(p) farid");
  CreateMessageBox(EMPTY_TEXTID, text, 1, 0, SMBook);
};

void EditDayToDate(BOOK *book, GUI *gui)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;

  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA *)malloc(size);
    ReadData(mydata, size);

    if (mydata->day_en)
    {
      mydata->day_en = FALSE;
      GUIObject_SoftKeys_SetText(SMBook->MainMenu, 1, TEXTID_ON_DAY);
    }
    else
    {
      mydata->day_en = TRUE;
      GUIObject_SoftKeys_SetText(SMBook->MainMenu, 1, TEXTID_OFF_DAY);
    }
    int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IRUSR | FSX_S_IWUSR, 0);
    if (file >= 0)
    {
      fwrite(file, mydata, sizeof(FILE_DATA));
      fclose(file);
    }
    mfree(mydata);
  }
}

TEXTID Get_Text()
{
  TEXTID text;
  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA *)malloc(size);
    ReadData(mydata, size);
    if (mydata->day_en)
    {
      text = TEXTID_OFF_DAY;
    }
    else
    {
      text = TEXTID_ON_DAY;
    }
    mfree(mydata);
  }
  return text;
}

void StandbyManager_Main_PageOnSelect(BOOK *book, GUI *gui)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;
  SMBook->fileitem = ListMenu_GetSelectedItem(SMBook->MainMenu);
  CreateEditItem(SMBook);
}

int StandbyManager_Main_PageOnMessage(GUI_MESSAGE *msg)
{
  switch (GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg, items_text[item + 1]);
    GUIonMessage_SetMenuItemSecondLineText(msg, GetTextID(Check_Num(item)));
    GUIonMessage_SetMenuItemIcon(msg, AlignLeft, iconID[item]);
    break;
  }
  return 1;
};

int StandbyManager_Main_PageOnCreate(void *data, BOOK *book)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;

  if (SMBook->MainMenu = CreateListMenu(SMBook, UIDisplay_Main))
  {
    ListMenu_SetItemCount(SMBook->MainMenu, FILE_COUNT);
    ListMenu_SetCursorToItem(SMBook->MainMenu, Item_Operator3);
    ListMenu_SetOnMessage(SMBook->MainMenu, StandbyManager_Main_PageOnMessage);
    ListMenu_SetItemStyle(SMBook->MainMenu, 3);
    GUIObject_SetStyle(SMBook->MainMenu, 2);
    GUIObject_SetTitleText(SMBook->MainMenu, STR("Standby Manager"));
    GUIObject_SoftKeys_SetAction(SMBook->MainMenu, ACTION_BACK, CloseStandbyManager_Book);
    GUIObject_SoftKeys_SetAction(SMBook->MainMenu, ACTION_LONG_BACK, LCloseStandbyManager_Book);
    GUIObject_SoftKeys_SetAction(SMBook->MainMenu, ACTION_SELECT1, StandbyManager_Main_PageOnSelect);
    GUIObject_SoftKeys_SetActionAndText(SMBook->MainMenu, 0, Copyright, SOFTKEY_TEXTID);
    GUIObject_SoftKeys_SetActionAndText(SMBook->MainMenu, 1, EditDayToDate, Get_Text());
    GUIObject_Show(SMBook->MainMenu);
  }
  return 1;
}

int Cancel_BasePage(void *data, BOOK *book)
{
  FreeBook(book);
  return 1;
}

const PAGE_MSG bk_msglst_base[] =
    {
        CANCEL_EVENT, Cancel_BasePage,
        RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
        NIL_EVENT, NULL};

const PAGE_MSG bk_msglst_main[] =
    {
        PAGE_ENTER_EVENT, StandbyManager_Main_PageOnCreate,
        NIL_EVENT, NULL};

const PAGE_DESC StandbyManager_Base_Page = {"StandbyManager_Base_Page", 0, bk_msglst_base};
const PAGE_DESC StandbyManager_Main_Page = {"StandbyManager_Main_Page", 0, bk_msglst_main};

void StandbyManager_Destroy(BOOK *book)
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)book;
  FREE_GUI(SMBook->MainMenu);
  FREE_GUI(SMBook->SubMenu);
  SMBook->itemID = 0;
  SMBook->fileitem = 0;
}

BOOL isElementEnabled(int item)
{
  int result = FALSE;

  FSTAT _fstat;
  int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
  if (file >= 0)
  {
    int size = _fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA *)malloc(size);
    ReadData(mydata, size);
    for (int k = 0; k <= FILE_COUNT; k++)
    {
      if (mydata->item[k] == item)
        result = TRUE;
    }
    mfree(mydata);
  }
  return result;
}

TEXTID AddDayToDate(TEXTID textid)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  TEXTID weekday_textid[3];
  DATETIME dt;
  char day;
  REQUEST_DATEANDTIME_GET(SYNC, &dt);
  DATE_GetWeekDay(&dt.date, &day);
  weekday_textid[0] = weekdays[day];
  weekday_textid[1] = 0x78000020;
  weekday_textid[2] = textid;
  return (TextID_Create(weekday_textid, ENC_TEXTID, 3));
}

BOOL IsStandby_Book(BOOK *book, BOOK *book_cmp)
{
  if (!strcmp(book->xbook->name, book_cmp->xbook->name))
    return TRUE;
  return FALSE;
}

extern "C" void OnSetText(GUI *gui, int item, TEXTID textid)
{
  DISP_OBJ *sby_disp_obj = GUIObject_GetDispObject(gui);

#ifdef HASSECONDDISPLAY
  BOOK *book = GUIObject_GetBook(gui);
  BOOK *sby_book = Find_StandbyBook();

  if (IsStandby_Book(book, sby_book))
  {
#endif
    int ID = Check_Num(GetPatchID(item));

    if (ID == Item_UnSelected)
    {
      DispObject_StatusIndication_SetItemText(sby_disp_obj, item, textid);
    }
    else if (ID == Item_NotSelected)
    {
      if (!isElementEnabled(item))
      {
        DispObject_StatusIndication_SetItemText(sby_disp_obj, item, EMPTY_TEXTID);
      }
      TextID_Destroy(textid);
    }
    else
    {
      if (item == Item_Date)
      {
        int dateID;
        FSTAT _fstat;
        int file = fstat(FILE_PATH, FILE_NAME, &_fstat);
        if (file >= 0)
        {
          int size = _fstat.fsize;
          FILE_DATA *mydata = (FILE_DATA *)malloc(size);
          ReadData(mydata, size);
          if (mydata->day_en == 1)
            dateID = AddDayToDate(textid);
          else
            dateID = textid;
          mfree(mydata);
        }
        else
        {
          dateID = textid;
        }
        DispObject_StatusIndication_SetItemText(sby_disp_obj, ID, dateID);
      }
      else
      {
        DispObject_StatusIndication_SetItemText(sby_disp_obj, ID, textid);
      }
    }
#ifdef HASSECONDDISPLAY
  }
  else
  {
    DispObject_StatusIndication_SetItemText(sby_disp_obj, item, textid);
  }
#endif
}

__thumb BOOK *CreateStandbyManager_Book()
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)malloc(sizeof(StandbyManager_Book));
  memset(SMBook, NULL, sizeof(StandbyManager_Book));
  if (!CreateBook(SMBook, StandbyManager_Destroy, &StandbyManager_Base_Page, "StandbyManager_Book", -1, 0))
  {
    mfree(SMBook);
    return NULL;
  }
  SMBook->MainMenu = 0;
  SMBook->SubMenu = 0;
  SMBook->itemID = 0;
  SMBook->fileitem = 0;
  return SMBook;
}

void StandbyManager()
{
  StandbyManager_Book *SMBook = (StandbyManager_Book *)CreateStandbyManager_Book();
  if (SMBook)
    BookObj_GotoPage(SMBook, &StandbyManager_Main_Page);
}

__thumb void Call_StandbyManager(DYNAMIC_MENU_ELEMENT *DME)
{
  switch (DynamicMenu_GetElementMsg(DME))
  {
  case DYNAMIC_MENU_onCall:
    StandbyManager();
    break;
  case DYNAMIC_MENU_onText:
    DynamicMenu_SetElement_SecondLineText(DME, STR("Edit Standby item"));
    break;
  }
}

#pragma diag_suppress = Pe177
__root const int PATCH_Standby @ "PATCH_Standby" = (int)STANDBY_SETTINGS_ID;
__root const int PATCH_StandbyFunc @ "PATCH_StandbyFunc" = (int)Call_StandbyManager;
