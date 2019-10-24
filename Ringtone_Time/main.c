/*
;G502 R1FA037
;Message Alert Time Selection
;Visual Timing
;Message Alert -> Option -> Ringtone TIme
;v2
;(c) Ploik, farid
;(r) RaANdOoM
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#define INTERNAL_VAR "Sms_Function"
#define FREE_GUI(a) if (a) a=GUIObject_Destroy(a)


typedef struct
{
  int Time;
}RingTone_File_Function;

typedef struct _MyBOOK : BOOK
{
  GUI * Interval;
  GUI_LIST * list_menu;
}MyBOOK;

__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF,size,1,5,"rg",0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,"rg",0);
}

extern "C"
int GetTime()
{
  int f;
  int Time = 10000;
  if ( (f=_fopen( (wchar_t*)PATH,L"SmsTone.bin", FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    RingTone_File_Function *FileData = (RingTone_File_Function*)malloc(sizeof(RingTone_File_Function));
    memset (FileData,0,sizeof(RingTone_File_Function));
    fread( f, FileData, sizeof(RingTone_File_Function) );
    Time = FileData->Time;
    fclose (f);
    mfree(FileData);
  }
  return Time;
}

void WriteOnFIle(int Time)
{
  int f;
  if ( (f=_fopen( (wchar_t*)PATH,L"SmsTone.bin", FSX_O_WRONLY, FSX_S_IREAD|FSX_S_IWRITE, 0)) >=0 )
  {
    RingTone_File_Function* FileData = (RingTone_File_Function*)malloc(sizeof(RingTone_File_Function));
    memset (FileData,0,sizeof(RingTone_File_Function));
    FileData->Time = Time;
    fwrite(f,FileData,sizeof(RingTone_File_Function));
    fclose (f);
    mfree(FileData);
  }
}

void OnLongBackCreateStringInput(BOOK *bk, GUI* gui)
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FREE_GUI(myBook->Interval);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void OnBackCreateStringInput( BOOK* bk, GUI* gui )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  FREE_GUI(myBook->Interval);
  BookObj_GotoPage(bk,(PAGE_DESC*)page_MSG_UI_MessageAlert);
}

void OnOkCreateStringInput( BOOK* bk, GUI* gui )
{
  MyBOOK* myBook = (MyBOOK*) bk;
  
  u16 len;
  wchar_t *string;
  wchar_t InfoBuff[32];
  int Time = 0;
  
  StringInput_GetStringAndLen( gui, &string, &len );

  wtoi( string, len, &Time);
  int Second = Time/1000;
  snwprintf(InfoBuff, 31, L"Message Alert Time\n %d sec.", Second);
  MessageBox( EMPTY_TEXTID, TextID_Create(InfoBuff,0,0xFF), 0, 1, 0, bk );
  
  WriteOnFIle(Time);
  
  FREE_GUI(myBook->Interval);
  BookObj_GotoPage(bk,(PAGE_DESC*)page_MSG_UI_MessageAlert);
}

void OnAuthorInfo(BOOK * bk, GUI *)
{
  MessageBox( EMPTY_TEXTID, TextID_Create("Message Alert Time Selection v2\n(c) ploik, farid\n(r) RaANdOoM",6,0xFF), 0, 1, 0, bk );
}

int MainPageOnCreate(void * r0, BOOK * bk)
{
  MyBOOK* myBook = (MyBOOK*) bk;

  myBook->Interval = CreateStringInput(myBook);
  StringInput_SetText( myBook->Interval, TextID_CreateIntegerID(GetTime()) );
  StringInput_SetMaxLen( myBook->Interval, 6 );
  StringInput_SetMinLen( myBook->Interval, 1);
  StringInput_SetMode( myBook->Interval, IT_INTEGER );
  
  GUIObject_SetTitleText( myBook->Interval,TextID_Create("Time (ms)",6,9 ));

  GUIObject_SoftKeys_SetAction( myBook->Interval, ACTION_BACK, OnBackCreateStringInput );
  GUIObject_SoftKeys_SetAction( myBook->Interval, ACTION_LONG_BACK, OnLongBackCreateStringInput );
  GUIObject_SoftKeys_SetAction( myBook->Interval, ACTION_ACCEPT, OnOkCreateStringInput );

  GUIObject_SoftKeys_SetText( myBook->Interval, 0, TextID_Create("Patch Info",6,10) );  
  GUIObject_SoftKeys_SetAction( myBook->Interval, 0, OnAuthorInfo );

  GUIObject_Show(myBook->Interval);
  return (1);
}

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT,  MainPageOnCreate,
  NIL_EVENT,         0
};

const PAGE_DESC bk_main = {"MSG_UI_MessageAlert_TimeSound_Page",0,bk_msglst_main};

extern "C"
void CreateMyGui( BOOK * myBook, void* mess )
{
  BookObj_GotoPage( myBook, &bk_main );
}

extern "C"
int SetText()
{
  return TextID_Create("Ringtone Time",6,0xD);
}

extern "C"
int SetInfoText()
{
  int txt[3] = { TextID_Create("Message Alert ",6,14), TextID_CreateIntegerID(GetTime()), TextID_Create(" sec.",6,5) };
  return TextID_Create(txt,5,3);
}
