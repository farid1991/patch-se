#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\StandbyBook.h"

#ifdef C510_R1HA035 
#define FILE_PATH L"/tpa/"
#define FILE_NAME L"Cfg.bin"
#elif C510_R1FA035
#define FILE_PATH L"/tpa/"
#define FILE_NAME L"Cfg.bin"
#elif C905_R1FA035
#define FILE_PATH L"/tpa/"
#define FILE_NAME L"Cfg.bin"
#else
#define FILE_PATH L"/tpa/system/settings/"
#define FILE_NAME L"StandbyCfg.bin"
#endif

//#define SID_ANY_LEN 0xFFFF
//#define EMPTY_TEXTID   0x6FFFFFFF

#define STANDBY_SETTINGS_ID  (L"Standby_Set_Id")

#define FREE_GUI(a) if(a) a=GUIObject_Destroy(a)

__thumb void * malloc (int size)
{
#ifdef DB2020  
 return(memalloc(0,size,1,5,"st",0));
#elif A2
 return(memalloc(0xFFFFFFFF,size,1,5,"st",0));
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

#define Operator3               0x0
#define Operator1               0x1
#define SearchFlight            0x2
#define Prof                    0x4
#define Operator2               0x6
#define NoSignal                0x7
#define Notes                   0x9
#define BigClock                0xB
#define SmallClock              0xC
#define Date                    0xD
#define Alarm                   0xE
#define Timer                   0xF
#define CallTime                0x10
#define Shift                   0x11
#define W580_Accel              0x12

typedef struct _StandbyManager_Book : BOOK
{
  BOOK  book;
  GUI *gui;
  GUI *gui2;
  int itemID;
  int fileitem;
}StandbyManager_Book;

#ifdef W580_R8BE001 
#define FILE_COUNT 15
#else
#define FILE_COUNT 14
#endif

typedef struct{
  char item[FILE_COUNT];
  char day_en;
}FILE_DATA;

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
  int file = _fopen(FILE_PATH,FILE_NAME,0x108,0x180,0);
  fread(file,mydata,size);
  fclose(file);
}

void WriteData(int numitem,int itemID)
{
  int f;
  wchar_t *path=FILE_PATH;
  wchar_t *name=FILE_NAME;
  FILE_DATA *fd=(FILE_DATA*)malloc(sizeof(FILE_DATA));
  memset(fd,0xFF,sizeof(FILE_DATA));
  GetData(fd,sizeof(FILE_DATA));

  DISP_OBJ* sby = GUIObject_GetDispObject(((StandbyBook*)Find_StandbyBook())->gui);

  DispObject_StatusIndication_SetItemText(sby,fd->item[numitem],EMPTY_TEXTID); 
  fd->item[numitem]=itemID;

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
    REQUEST_PROFILE_GETPROFILENAME( SYNC,-2, &GetProfile, &error );
    
    if(num >0)
    {
      DispObject_StatusIndication_SetItemText(sby,itemID,TextID_Create(GetProfile.ptr,0,GetProfile.lenght));
    } 
    else 
    {
      DispObject_StatusIndication_SetItemText(sby,itemID,EMPTY_TEXTID);
    }
  }
  
  f=_fopen(path,name,0x204,0x180,0);
  fwrite(f,fd,sizeof(FILE_DATA));
  fclose(f);
  mfree(fd);
}

int onMessage1(GUI_MESSAGE *msg)
{
  StandbyManager_Book *m_bk = (StandbyManager_Book *)GUIonMessage_GetBook(msg);
  int item;
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg,items_text[item]);
    break;
  }
  return 1;
}

void RefreshEdList(GUI_LIST * g,int itemcount)
{
  int pos = ListMenu_GetSelectedItem(g);
  ListMenu_DestroyItems(g);
  ListMenu_SetItemCount(g,itemcount);
  ListMenu_SetCursorToItem(g,pos);
  GUIObject_SoftKeys_SetVisible((GUI*)g, ACTION_SELECT1, 1 );
}

void onEnterSetID( BOOK *book, GUI* gui )
{
  StandbyManager_Book *m_bk = (StandbyManager_Book*)book;
  GUI_LIST *list_menu = (GUI_LIST *)(m_bk->gui2);
  int item = ListMenu_GetSelectedItem(list_menu);
  switch(item)
   {
     case 0:  m_bk->itemID=0xFF;         break;
     case 1:  m_bk->itemID=Operator3;    break;
     case 2:  m_bk->itemID=Operator2;    break;
     case 3:  m_bk->itemID=Operator1;    break;
     case 4:  m_bk->itemID=SearchFlight; break;
     case 5:  m_bk->itemID=NoSignal;     break;
     case 6:  m_bk->itemID=Prof;         break;
     case 7:  m_bk->itemID=Notes;        break;
     case 8:  m_bk->itemID=BigClock;     break;
     case 9:  m_bk->itemID=SmallClock;   break;
     case 10: m_bk->itemID=Date;         break;
     case 11: m_bk->itemID=Alarm;        break;
     case 12: m_bk->itemID=Timer;        break;
     case 13: m_bk->itemID=CallTime;     break;
     case 14: m_bk->itemID=Shift;        break;
     #ifdef W580_R8BE001
     case 15: m_bk->itemID=W580_Accel;   break;
     #endif
   }
  WriteData(m_bk->fileitem,m_bk->itemID);
  FREE_GUI(m_bk->gui2);
  #ifdef A2
  RefreshEdList((GUI_LIST*)m_bk->gui,FILE_COUNT);
  #endif
}

void CloseMyGUI( BOOK *book, GUI* gui )
{
  StandbyManager_Book *m_bk = (StandbyManager_Book *)book;
  FREE_GUI(m_bk->gui2);
  #ifdef A2
  RefreshEdList((GUI_LIST*)m_bk->gui,FILE_COUNT);
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
 return (result);
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

int CreateEditItem(BOOK *book,int itemnum)
{
  StandbyManager_Book *m_bk = (StandbyManager_Book *)book;
  GUI_ONEOFMANY *om=CreateOneOfMany(&m_bk->book);
  GUIObject_SetTitleText(om,TEXTID_TITLE);
  OneOfMany_SetTexts(om,(TEXTID*)items_text,FILE_COUNT+1);
  int checked;

  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    checked=GetPatchID(mydata->item[itemnum]);
     
    if (checked==0xFF)
    {
      checked=0;
    }
    else
    {
      checked+=1; 
    }
    mfree(mydata);
  }

  OneOfMany_SetChecked(om,checked);
  GUIObject_SetStyle(om,2);
  GUIObject_SoftKeys_SetAction(om,ACTION_BACK, CloseMyGUI);
  GUIObject_SoftKeys_SetAction(om,ACTION_LONG_BACK, CloseMyGUI);
  GUIObject_SoftKeys_SetAction(om,ACTION_SELECT1,onEnterSetID);
  m_bk->gui2 = (GUI *)om;
  m_bk->fileitem=itemnum;
  GUIObject_Show(om);
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
  StandbyManager_Book *m_bk = (StandbyManager_Book *)GUIonMessage_GetBook(msg);
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    GUIonMessage_SetMenuItemText(msg,items_text[item+1]);
    GUIonMessage_SetMenuItemSecondLineText(msg,GetTextID(Check_Num(item)));
    GUIonMessage_SetMenuItemIcon(msg ,0,iconID[item]);
    break;
  }
  return(1);
};

void onEnterSettings( BOOK* book, GUI* gui )
{
  StandbyManager_Book *m_bk = (StandbyManager_Book *)book;
  GUI_LIST *list_menu = (GUI_LIST *)(m_bk->gui);
  int item = ListMenu_GetSelectedItem(list_menu);
  CreateEditItem(book,item);
}

void CloseStandbyManager_Book( BOOK* book, GUI* gui )
{
  FreeBook(book);
}

void LCloseStandbyManager_Book( BOOK* book, GUI* gui )
{
  FreeBook(book);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

int Cancel_BasePage(void *r0, BOOK *book)
{
  FreeBook(book);
  return(1);
}

void Copyright( BOOK* book, GUI* gui )
{
  MessageBox(EMPTY_TEXTID,TextID_Create("Standby Manager\n\n(c) Ploik & MaPkiZzz\n(p) farid",6,TEXTID_ANY_LEN),0, 1, 0, 0);
};

void EditDayToDate( BOOK* book, GUI* gui )
{
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
   
    if (mydata->day_en==0)
    {
      mydata->day_en=1;
      GUIObject_SoftKeys_SetText(((StandbyManager_Book*)book)->gui,2,TEXTID_OFF_DAY);
    }
    else
    {
      mydata->day_en=0;
      GUIObject_SoftKeys_SetText(((StandbyManager_Book*)book)->gui,2,TEXTID_ON_DAY);
    }
       
    int f=_fopen(FILE_PATH,FILE_NAME,0x204,0x180,0);
    fwrite(f,mydata,sizeof(FILE_DATA));
    fclose(f);
    mfree(mydata);
  }
}

int MainPageOnCreate(void *r0, BOOK *book)
{
  StandbyManager_Book *m_bk = (StandbyManager_Book *)book;
  GUI_LIST *list_menu;
  FREE_GUI(m_bk->gui);
  
  if(!(list_menu = CreateListMenu(book,0)))
  {
    FreeBook(book);
    return(1);
  }

  ListMenu_SetItemCount(list_menu,FILE_COUNT);
  ListMenu_SetCursorToItem(list_menu,0);
  ListMenu_SetOnMessage(list_menu,onMessage);
  ListMenu_SetItemStyle(list_menu,3);
  GUIObject_SetStyle(list_menu,2);
  GUIObject_SetTitleText(list_menu,TextID_Create("Standby Manager",6,15));
  GUIObject_SoftKeys_SetAction(list_menu,ACTION_BACK, CloseStandbyManager_Book);
  GUIObject_SoftKeys_SetAction(list_menu,ACTION_LONG_BACK, LCloseStandbyManager_Book);
  GUIObject_SoftKeys_SetAction(list_menu,ACTION_SELECT1,onEnterSettings);
  GUIObject_SoftKeys_SetAction(list_menu,1,Copyright);
  GUIObject_SoftKeys_SetText(list_menu,1,SOFTKEY_TEXTID);
  FSTAT _fstat;
  if ((fstat(FILE_PATH,FILE_NAME,&_fstat))>=0)
  {
    int size=_fstat.fsize;
    FILE_DATA *mydata = (FILE_DATA*)malloc(size);
    GetData(mydata,size);
    if (mydata->day_en==0)
    {
       GUIObject_SoftKeys_SetText(list_menu,2,TEXTID_ON_DAY);
    }
    else
    {
       GUIObject_SoftKeys_SetText(list_menu,2,TEXTID_OFF_DAY);
    }
    mfree(mydata);
  }
  GUIObject_SoftKeys_SetAction(list_menu,2,EditDayToDate);
  GUIObject_Show(list_menu);
  m_bk->gui = (GUI *)list_menu;
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
  PAGE_ENTER_EVENT, MainPageOnCreate,
  NIL_EVENT,        NULL
};

const PAGE_DESC bk_base = {"Standby_Set_Base_Page",0,bk_msglst_base};
const PAGE_DESC bk_main = {"Standby_Set_Main_Page",0,bk_msglst_main};

void onStandbyManager_BookClose(BOOK *book)
{
  StandbyManager_Book *m_bk = (StandbyManager_Book*)book;
  if(m_bk->gui)
  {
    FREE_GUI(m_bk->gui);
    m_bk->gui = 0;
  }
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
      for (int k=0;k<=FILE_COUNT;k++)
       {
        if (mydata->item[k]==item) result=1;
       }
     mfree(mydata);
   }
  return result;
}

extern const int *SYNC;

int AddDayToDate(int strid)
{
  const int days[7]={TEXTID_1,TEXTID_2,TEXTID_3,TEXTID_4,TEXTID_5,TEXTID_6,TEXTID_7};
  int *SYNC=0;
  int newid[3];
  DATETIME dt;
  char day;
  REQUEST_DATEANDTIME_GET(SYNC,&dt);
  DATE_GetWeekDay(&dt.date,&day);
  newid[0]=days[day];
  newid[1]=0x78000020;
  newid[2]=strid;
  return (TextID_Create(newid,5,3));
}

extern"C"
void OnSetText(GUI *gui,int item, int strid)
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
   BOOK *StandbyManager_Book = (BOOK *)malloc(sizeof(StandbyManager_Book));
   memset(StandbyManager_Book,0,sizeof(StandbyManager_Book));  
   if(!CreateBook(StandbyManager_Book,onStandbyManager_BookClose,&bk_base,"Standby_Manager",-1,0)) mfree(StandbyManager_Book);
   else BookObj_GotoPage(StandbyManager_Book,&bk_main);
}

__thumb void StandbySet(DYNAMIC_MENU_ELEMENT *DME)
{
  switch(DynamicMenu_GetElementMsg(DME))
  {
  case MENU_onCall:
    CreateStandby_Book();
    break;
  case MENU_onText:
    DynamicMenu_SetElement_SecondLineText(DME, TextID_Create ( L"Edit Standby", ENC_UCS2, 0xFF ));
    break;
  }
}

#pragma diag_suppress=Pe177
__root  const int PATCH_Standby @ "PATCH_Standby" =(int)STANDBY_SETTINGS_ID;
__root  const int PATCH_StandbyFunc @ "PATCH_StandbyFunc" =(int)StandbySet;
