#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\StandbyBook.h"

#include "main.h"

__thumb void * malloc (int size)
{
#ifdef DB2020  
  return(memalloc(0,size,1,5,"st",0));
#elif A2
  return(memalloc(-1,size,1,5,"st",0));
#else
  return(memalloc(size,1,5,"st",0));
#endif
}

__thumb void mfree (void * mem)
{
#ifdef DB2020  
  if (mem) memfree(0, mem,"st",0);
#elif A2
  if (mem) memfree(0, mem,"st",0);
#else
  memfree(mem,"st",0);
#endif
}

const TEXTID items_text[] = 
{
  TEXTID_OFF,
  TEXTID_OP3,
  TEXTID_OP2,
  TEXTID_OP1,
  TEXTID_SF,
  TEXTID_NO,
  TEXTID_PROF,
  TEXTID_NOTES,
  TEXTID_BIG_TIME,
  TEXTID_TIME,
  TEXTID_DATE,
  TEXTID_ALARM,
  TEXTID_TIMER,
  TEXTID_TALK,
  TEXTID_SHIFT,
  #ifdef W580_R8BE001
  TEXTID_ACCEL
  #endif  
};

const IMAGEID iconID[] = 
{
  ICONID_OP3,
  ICONID_OP2,
  ICONID_OP1,
  ICONID_SF,
  ICONID_NO,
  ICONID_PROF,
  ICONID_NOTES,
  ICONID_BIG_TIME,
  ICONID_TIME,
  ICONID_DATE,
  ICONID_ALARM,
  ICONID_TIMER,
  ICONID_TALK,
  ICONID_SHIFT,
  #ifdef W580_R8BE001
  ICONID_ACCEL
  #endif  
};

void GetData(void* mydata, int size)
{
  int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_CREAT|FSX_O_APPEND, FSX_S_IRUSR|FSX_S_IWUSR,0);
  fread(file,mydata,size);
  fclose(file);
}

void WriteData(int numitem, int itemID)
{
  FILE_DATA* fd = (FILE_DATA*)malloc(sizeof(FILE_DATA));
  memset(fd,0xFF,sizeof(FILE_DATA));
  GetData(fd,sizeof(FILE_DATA));

  DISP_OBJ* sby = GUIObject_GetDispObject(((StandbyBook*)Find_StandbyBook())->gui);

  DispObject_StatusIndication_SetItemText(sby,fd->item[numitem],EMPTY_TEXTID); 
  fd->item[numitem] = itemID;

  if (numitem==2)
  {
    wchar_t buff[128];
    DispObject_StatusIndication_SetItemText(sby,itemID,GetOperatorName(buff));
  }

  if (numitem==5)
  {
    int *SYNC=0;
    int num;
    TEXTID_DATA GetProfile;
    wchar_t SetName[0x10];
    char error;
    GetProfile.ptr=SetName;
    REQUEST_PROFILE_GETACTIVEPROFILE( SYNC, &num );
    REQUEST_PROFILE_GETPROFILENAME( SYNC, -2, &GetProfile, &error );
    
    if(num >0)
    {
      DispObject_StatusIndication_SetItemText(sby,itemID,TextID_Create(GetProfile.ptr,0,GetProfile.lenght));
    } 
    else 
    {
      DispObject_StatusIndication_SetItemText(sby,itemID,EMPTY_TEXTID);
    }
  }
  int file =_fopen(FILE_PATH, FILE_NAME, FSX_O_TRUNC|FSX_O_RDWR, FSX_S_IRUSR|FSX_S_IWUSR, 0);
  fwrite(file,fd,sizeof(FILE_DATA));
  fclose(file);
  mfree(fd);
}

int onMessage1(GUI_MESSAGE *msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg,items_text[item]);
    break;
  }
  return 1;
}

void RefreshEdList( BOOK* book, int itemcount )
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  
  int pos = ListMenu_GetSelectedItem(SBMBook->main_menu);
  ListMenu_DestroyItems(SBMBook->main_menu);
  ListMenu_SetItemCount(SBMBook->main_menu,itemcount);
  ListMenu_SetCursorToItem(SBMBook->main_menu,pos);
  GUIObject_SoftKeys_SetVisible(SBMBook->main_menu, ACTION_SELECT1, TRUE );
}

void onEnterSetID( BOOK *book, GUI* gui )
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  switch(OneOfMany_GetSelected(SBMBook->sub_menu))
  {
  case 0:  SBMBook->itemID=0xFF;         break;
  case 1:  SBMBook->itemID=Operator3;    break;
  case 2:  SBMBook->itemID=Operator2;    break;
  case 3:  SBMBook->itemID=Operator1;    break;
  case 4:  SBMBook->itemID=SearchFlight; break;
  case 5:  SBMBook->itemID=NoSignal;     break;
  case 6:  SBMBook->itemID=Prof;         break;
  case 7:  SBMBook->itemID=Notes;        break;
  case 8:  SBMBook->itemID=BigClock;     break;
  case 9:  SBMBook->itemID=SmallClock;   break;
  case 10: SBMBook->itemID=Date;         break;
  case 11: SBMBook->itemID=Alarm;        break;
  case 12: SBMBook->itemID=Timer;        break;
  case 13: SBMBook->itemID=CallTime;     break;
  case 14: SBMBook->itemID=Shift;        break;
#ifdef W580_R8BE001
  case 15: SBMBook->itemID=W580_Accel;   break;
#endif
  }
  WriteData(SBMBook->fileitem,SBMBook->itemID);
  FREE_GUI(SBMBook->sub_menu);
#ifdef A2
  RefreshEdList(SBMBook,FILE_COUNT);
#endif
}

void Close_EditItem( BOOK* book, GUI* gui )
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  FREE_GUI(SBMBook->sub_menu);
#ifdef A2
  RefreshEdList(SBMBook,FILE_COUNT);
#endif
}

int Check_Num(int itemnum)
{
  int result=0xFF;
  
  if (itemnum!=0xFF)
  {
    FSTAT _fstat;
    if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
    {
      int size=_fstat.fsize;
      FILE_DATA *mydata = (FILE_DATA*)malloc(size);
      GetData(mydata,size);
        
      if (mydata->item[itemnum]!=0xFF)
        result=mydata->item[itemnum];
      mfree(mydata);
    }
  }
  else
  {
    result=0xFE;
  }
  return result;
}

int GetPatchID(int PhoneID)
{
  int result;
  switch(PhoneID)
  {
    case Operator3:    result=0;    break;
    case Operator2:    result=1;    break;
    case Operator1:    result=2;    break;
    case SearchFlight: result=3;    break;
    case NoSignal:     result=4;    break;
    case Prof:         result=5;    break;
    case Notes:        result=6;    break;
    case BigClock:     result=7;    break;
    case SmallClock:   result=8;    break;
    case Date:         result=9;    break;
    case Alarm:        result=10;   break;
    case Timer:        result=11;   break;
    case CallTime:     result=12;   break;
    case Shift:        result=13;   break;
    #ifdef W580_R8BE001 
    case W580_Accel:   result=14;   break;
    #endif
    default:           result=0xFF; break;
  }
 return(result);
}

int GetChecked(int itemnum)
{
  int checked;

  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    checked = GetPatchID(mydata->item[itemnum]);
     
    if (checked==0xFF) checked=0;
    else checked+=1;
    
    mfree(mydata);
  }
  return checked;
}

int CreateEditItem(BOOK* book, int itemnum)
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  SBMBook->fileitem = itemnum;
  
  SBMBook->sub_menu = CreateOneOfMany(SBMBook);
  GUIObject_SetTitleText(SBMBook->sub_menu,TEXTID_TITLE);
  OneOfMany_SetTexts(SBMBook->sub_menu,(TEXTID*)items_text,FILE_COUNT+1);
  OneOfMany_SetChecked(SBMBook->sub_menu,GetChecked(SBMBook->fileitem));
  GUIObject_SetStyle(SBMBook->sub_menu,2);
  GUIObject_SoftKeys_SetAction(SBMBook->sub_menu,ACTION_BACK, Close_EditItem);
  GUIObject_SoftKeys_SetAction(SBMBook->sub_menu,ACTION_LONG_BACK, Close_EditItem);
  GUIObject_SoftKeys_SetAction(SBMBook->sub_menu,ACTION_SELECT1,onEnterSetID);  
  GUIObject_Show(SBMBook->sub_menu);
  return(1);
}

int GetTextID(int ItemID)
{
  int result;
  switch(ItemID)
  {
   case Operator3:    result=TEXTID_OP3;          break;
   case Operator2:    result=TEXTID_OP2;          break;
   case Operator1:    result=TEXTID_OP1;          break;
   case SearchFlight: result=TEXTID_SF;           break;
   case NoSignal:     result=TEXTID_NO;           break;
   case Prof:         result=TEXTID_PROF;         break;
   case Notes:        result=TEXTID_NOTES;        break;
   case BigClock:     result=TEXTID_BIG_TIME;     break;
   case SmallClock:   result=TEXTID_TIME;         break;
   case Date:         result=TEXTID_DATE;         break;
   case Alarm:        result=TEXTID_ALARM;        break;
   case Timer:        result=TEXTID_TIMER;        break;
   case CallTime:     result=TEXTID_TALK;         break;
   case Shift:        result=TEXTID_SHIFT;        break;
   #ifdef W580_R8BE001
   case W580_Accel:   result=TEXTID_ACCEL;        break;
   #endif
   default:           result=TEXTID_SWITCHED_OFF; break;
  }
  return(result);
}

int onMessage(GUI_MESSAGE *msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg,items_text[item+1]);
    GUIonMessage_SetMenuItemSecondLineText(msg,GetTextID(Check_Num(item)));
    GUIonMessage_SetMenuItemIcon(msg ,0,iconID[item]);
    break;
  }
  return 1;
};

void onEnterSettings( BOOK* book, GUI* gui )
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  int item = ListMenu_GetSelectedItem(SBMBook->main_menu);
  CreateEditItem(SBMBook,item);
}

void CloseStandbyManager_Book( BOOK* book, GUI* gui )
{
  FreeBook(book);
}

void LCloseStandbyManager_Book( BOOK* book, GUI* gui )
{
  CloseStandbyManager_Book(book,gui);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void Copyright( BOOK* book, GUI* gui )
{
  TEXTID text = TextID_Create("Standby Manager\n\n(c) Ploik & MaPkiZzz\n(p) farid",ENC_LAT1,TEXTID_ANY_LEN);
  MessageBox_NoImage(EMPTY_TEXTID, text, 1, 0, book);
};

void EditDayToDate( BOOK* book, GUI* gui )
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat)) >= 0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
   
    if (mydata->day_en==0)
    {
      mydata->day_en=1;
      GUIObject_SoftKeys_SetText(SBMBook->main_menu,2,TEXTID_OFF_DAY);
    }
    else
    {
      mydata->day_en=0;
      GUIObject_SoftKeys_SetText(SBMBook->main_menu,2,TEXTID_ON_DAY);
    }
    int file =_fopen(FILE_PATH, FILE_NAME, FSX_O_TRUNC|FSX_O_RDWR, FSX_S_IRUSR|FSX_S_IWUSR, 0);
    fwrite(file,mydata,sizeof(FILE_DATA));
    fclose(file);
    mfree(mydata);
  }
}

TEXTID Get_Text()
{
  TEXTID text;
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    if (mydata->day_en==0)
    {
       text = TEXTID_ON_DAY;
    }
    else
    {
       text = TEXTID_OFF_DAY;
    }
    mfree(mydata);
  }
  return text;
}

int StandbyManager_Main_PageOnCreate(void *r0, BOOK *book)
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  FREE_GUI(SBMBook->main_menu);
  
  SBMBook->main_menu = CreateListMenu(SBMBook,0);
  ListMenu_SetItemCount(SBMBook->main_menu,FILE_COUNT);
  ListMenu_SetCursorToItem(SBMBook->main_menu,0);
  ListMenu_SetOnMessage(SBMBook->main_menu,onMessage);
  ListMenu_SetItemStyle(SBMBook->main_menu,3);
  
  GUIObject_SetStyle(SBMBook->main_menu,2);
  GUIObject_SetTitleText(SBMBook->main_menu,TextID_Create("Standby Manager",6,15));
  
  GUIObject_SoftKeys_SetAction(SBMBook->main_menu,ACTION_BACK, CloseStandbyManager_Book);
  GUIObject_SoftKeys_SetAction(SBMBook->main_menu,ACTION_LONG_BACK, LCloseStandbyManager_Book);
  GUIObject_SoftKeys_SetAction(SBMBook->main_menu,ACTION_SELECT1,onEnterSettings);
  GUIObject_SoftKeys_SetActionAndText(SBMBook->main_menu,1,Copyright,SOFTKEY_TEXTID);
  GUIObject_SoftKeys_SetActionAndText(SBMBook->main_menu,2,EditDayToDate,Get_Text());
  
  GUIObject_Show(SBMBook->main_menu);
  return 1;
}

int Cancel_BasePage(void* data, BOOK *book)
{
  CloseStandbyManager_Book(book,NULL);
  return(1);
}

const PAGE_MSG bk_msglst_base[] = 
{
  CANCEL_EVENT,            Cancel_BasePage,
  RETURN_TO_STANDBY_EVENT, Cancel_BasePage,
  NIL_EVENT,               NULL
};

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT, StandbyManager_Main_PageOnCreate,
  NIL_EVENT,        NULL
};

const PAGE_DESC StandbyManager_Base_Page = {"StandbyManager_Base_Page",0,bk_msglst_base};
const PAGE_DESC StandbyManager_Main_Page = {"StandbyManager_Main_Page",0,bk_msglst_main};

void StandbyManager_Destroy(BOOK *book)
{
  StandbyManager_Book* SBMBook = (StandbyManager_Book*)book;
  FREE_GUI(SBMBook->main_menu);
}

int isElementEnabled (int item)
{
  int result=0;
  
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    for (int k=0; k<=FILE_COUNT; k++)
    {
      if (mydata->item[k]==item) result=1;
    }
    mfree(mydata);
  }
  return result;
}

int AddDayToDate(int strid)
{
  const int days[7]={TEXTID_1,TEXTID_2,TEXTID_3,TEXTID_4,TEXTID_5,TEXTID_6,TEXTID_7};
  int _SYNC = 0;
  int *SYNC =&_SYNC;
  
  int newid[3];
  DATETIME dt;
  char day;
  REQUEST_DATEANDTIME_GET(SYNC,&dt);
  DATE_GetWeekDay(&dt.date,&day);
  newid[0] = days[day];
  newid[1] = 0x78000020;
  newid[2] = strid;
  return (TextID_Create(newid,ENC_TEXTID,3));
}

extern"C"
void OnSetText(GUI* gui, int item, TEXTID strid)
{
  DISP_OBJ* sbydisp = GUIObject_GetDispObject(gui);
 
  int ID = Check_Num(GetPatchID(item));
 
  if (ID==0xFE)
  {
    DispObject_StatusIndication_SetItemText(sbydisp,item,strid);
  }
  else if (ID==0xFF)
  {
    if (!isElementEnabled(item))
    {
      DispObject_StatusIndication_SetItemText(sbydisp,item,EMPTY_TEXTID);
    }
    TextID_Destroy(strid);
  }
  else
  {
    if (item==Date)
    {
      int dateID;
      FSTAT _fstat;
      if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
      {
        int size=_fstat.fsize;
        FILE_DATA *mydata = (FILE_DATA*)malloc(size);
        GetData(mydata,size);
        if (mydata->day_en==1)
          dateID=AddDayToDate(strid);
        else
          dateID=strid; 
        mfree(mydata);
      }
      else
      {
        dateID=strid; 
      }
      DispObject_StatusIndication_SetItemText(sbydisp,ID,dateID);
    }
    else
    {
      DispObject_StatusIndication_SetItemText(sbydisp,ID,strid);
    }
  }
}

__thumb void CreateStandby_Book()
{    
   StandbyManager_Book* SBMBook = (StandbyManager_Book*)malloc(sizeof(StandbyManager_Book));
   memset(SBMBook,NULL,sizeof(StandbyManager_Book));  
   if(CreateBook(SBMBook,StandbyManager_Destroy,&StandbyManager_Base_Page,"Standby_Manager",-1,0))
   {
     BookObj_GotoPage(SBMBook,&StandbyManager_Main_Page);
   }
   else mfree(SBMBook);
}

__thumb void StandbySet(DYNAMIC_MENU_ELEMENT *DME)
{
  switch(DynamicMenu_GetElementMsg(DME))
  {
  case MENU_onCall:
    CreateStandby_Book();
    break;
  case MENU_onText:
    DynamicMenu_SetElement_SecondLineText(DME, TextID_Create ( "Edit Standby item", ENC_LAT1, 0xFF ));
    break;
  }
}

#pragma diag_suppress=Pe177
__root  const int PATCH_Standby @ "PATCH_Standby" =(int)STANDBY_SETTINGS_ID;
__root  const int PATCH_StandbyFunc @ "PATCH_StandbyFunc" =(int)StandbySet;
