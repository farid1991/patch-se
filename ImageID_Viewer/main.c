#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\ServiceMenuBook.h"

#include "gui_imageviewer.h"
#include "main.h"
#include "string.h"

__thumb void * malloc (int size)
{
#ifdef DB2020
  return(memalloc(0,size,1,5,"img",0));
#elif A2
  return(memalloc(0xFFFFFFFF,size,1,5,"gt",0));
#else
  return(memalloc(size,1,5,"img",0));
#endif
}

__thumb void mfree (void * mem)
{
#ifdef DB2020  
  if (mem) memfree(0, mem,"img",0);
#elif A2
  if (mem) memfree(0, mem,"img",0);
#else
  memfree(mem,"img",0);
#endif
}

void onCancel_StrInput( BOOK* book, GUI* gui )
{
  FREE_GUI(gui);
}

bool check_input(int val)
{
   if(val < SEG1_START) return FALSE;
   else if(val>SEG1_END && val<SEG2_START) return FALSE;
   else if(val>SEG2_END && val<SEG3_START) return FALSE;
   else if(val>SEG3_END && val<SEG4_START) return FALSE;
   else if(val>SEG4_END && val<SEG5_START) return FALSE;
   else if(val>SEG5_END) return FALSE;
   else return TRUE;
}

void onAccept_StrInput( BOOK* book, GUI* gui )
{
  ServiceMenuBook * SMBook = (ServiceMenuBook*)book;
  wchar_t * text;
  u16 len;
  StringInput_GetStringAndLen(gui,&text,&len);
  int offset = wstr2h(text,len);
  if (check_input(offset))
  {
    DISP_OBJ_IMG* disp_obj = (DISP_OBJ_IMG*)GUIObject_GetDispObject(SMBook->gui);
    disp_obj->img = offset;
    DispObject_InvalidateRect(disp_obj,NULL);
    FREE_GUI(SMBook->dummy_0x64);
  }
  else MessageBox_NoImage(EMPTY_TEXTID, TXT_OUT, 0, 1000, SMBook);
}

void ImageIDViewer_ActionGo( BOOK* book, GUI* gui )
{
  ServiceMenuBook * SMBook = (ServiceMenuBook*)book;
  //GUI* strinp;
  if(SMBook->dummy_0x64 = CreateStringInput(SMBook))
  {
    StringInput_SetMode(SMBook->dummy_0x64, IT_ABC_OR_DIGIT);
    StringInput_SetMinLen(SMBook->dummy_0x64, 1 );
    StringInput_SetMaxLen(SMBook->dummy_0x64, 4 );
    StringInput_SetEnableEmptyText(SMBook->dummy_0x64, FALSE);
    GUIObject_SetTitleText(SMBook->dummy_0x64, TXT_INPUT);
    GUIObject_SoftKeys_SetAction(SMBook->dummy_0x64, ACTION_ACCEPT, onAccept_StrInput);
    GUIObject_SoftKeys_SetAction(SMBook->dummy_0x64, ACTION_BACK, onCancel_StrInput);
    GUIObject_Show(SMBook->dummy_0x64);
  }
}

int pg_ImageID_Viewer_EnterAction( void* pData, BOOK* book )
{
  ServiceMenuBook * SMBook = (ServiceMenuBook*)book;
  FREE_GUI(SMBook->gui);
  
  SMBook->gui = Create_ImageIDViewer(SMBook);  
  GUIObject_SoftKeys_SetAction(SMBook->gui, ACTION_BACK, onBackPressed);
  //GUIObject_SoftKeys_SetAction(SMBook->gui, ACTION_SELECT1, onSavePressed);
  GUIObject_SoftKeys_SetAction(SMBook->gui, ACTION_LONG_BACK, onLongBackPressed);
  GUIObject_SoftKeys_SetActionAndText(SMBook->gui,0,ImageIDViewer_ActionGo,TXT_GOTO);
  GUIObject_SetTitleType(SMBook->gui, UI_TitleMode_None);
  GUIObject_Show(SMBook->gui);
  return 1;
}

const PAGE_MSG bk_msglst_main[] = 
{
  PAGE_ENTER_EVENT,        pg_ImageID_Viewer_EnterAction,
  PAGE_EXIT_EVENT,         pg_ServiceMenu_Test_Security_ExitAction,
  RETURN_TO_STANDBY_EVENT, pg_ServiceMenu_TestMenu_ReturnStandbyAction,
  NIL_EVENT,               NULL
};

const PAGE_DESC ServiceMenu_ViewSystemGraphics_Page = {"ServiceMenu_ViewSystemGraphics_Page",NULL,bk_msglst_main};

extern "C"
void New_SetAction(BOOK* book)
{
  BookObj_GotoPage(book,&ServiceMenu_ViewSystemGraphics_Page);
}

extern "C"
void New_SetTexts(GUI_LIST* gui, int count)
{
  ListMenu_SetTexts(gui,(int*)items_text,count);
}
