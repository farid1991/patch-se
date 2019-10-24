#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\MusicApplication_book.h"

#include "main.h"

const int items_text[] = 
{
  RINGTONE_TXT,
  MESSAGEALERT_TXT,
  ALARMSIGNAL_TXT, 
  CONTACTSIGNAL_TXT
}; 

#define FREE_GUI(a) a=GUIObject_Destroy(a);

void onBackGui(BOOK* book, GUI *gui)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  FREE_GUI(mbk->Gui_submenu)
}

void CreateFeedBack( BOOK* book , TEXTID TextID)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  FREE_GUI(mbk->Gui_submenu);
  
  mbk->Gui_submenu = TextFeedbackWindow( mbk, UIDisplay_Main );
  Feedback_SetTextExtended( mbk->Gui_submenu, TextID, 0 );
  GUIObject_SoftKeys_SetAction( mbk->Gui_submenu, ACTION_BACK, onBackGui );
  Feedback_CloseAction( mbk->Gui_submenu, ACTION_BACK );
  GUIObject_Show( mbk->Gui_submenu );
}

typedef struct SND
{
  char unk1;
  char unk2;
}SND;

void SetRingtone(BOOK* book, wchar_t* path, wchar_t* name)
{
  int _SYNC = NULL;
  int* SYNC = &_SYNC;
  char error_code;
  
  SETTING_RINGTYPESOUNDFILE_SET(SYNC,-1,NULL,path,name,&error_code);
  CreateFeedBack(book,RING_CHANGED_TXT);
}

void SetSMSAlert(BOOK* book, wchar_t *path, wchar_t *name)
{
  Sound_SetMessageAlert( path, name );
  CreateFeedBack(book,MESSAGE_CHANGED_TXT);
}

void onSelectGui(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  
  wchar_t* path = FILEITEM_GetPath(MusicBook->sub_exec->file_item);
  wchar_t* name = FILEITEM_GetFname(MusicBook->sub_exec->file_item);
  
  int item = ListMenu_GetSelectedItem(MusicBook->Gui_submenu);
  if(item==0) SetRingtone(MusicBook,path,name);
  else if(item==1) SetSMSAlert(MusicBook,path,name);
  else if(item==2) Sound_SetAlarmsignal(MusicBook,1,path,name);
  else if(item==3)
  {
    Sound_AddToContact(BookObj_GetBookID(MusicBook),path,wstrlen(path),name,wstrlen(name),NULL);
    FREE_GUI(MusicBook->Gui_submenu);
  }
}

int pg_MusicApplication_UseAsFile__EnterAction(void* Data, BOOK* book)
{
  MusicApplication_Book* mbk = (MusicApplication_Book*)book;
  FREE_GUI(mbk->Gui_submenu);
  
  mbk->Gui_submenu = CreateListMenu( mbk, UIDisplay_Main );
  ListMenu_SetItemCount( mbk->Gui_submenu, 4 );
  ListMenu_SetCursorToItem( mbk->Gui_submenu, 0 );
  ListMenu_SetHotkeyMode( mbk->Gui_submenu, LKHM_SHORTCUT );
  ListMenu_SetTexts( mbk->Gui_submenu,(int*)items_text,4);
  GUIObject_SetTitleText( mbk->Gui_submenu, USE_AS_TXT);
  GUIObject_SetStyle( mbk->Gui_submenu, UI_OverlayStyle_PopupNoFrame );
  GUIObject_SoftKeys_SetAction( mbk->Gui_submenu, ACTION_SELECT1, onSelectGui );
  GUIObject_SoftKeys_SetAction( mbk->Gui_submenu, ACTION_BACK, MusicApp_PrevAction );
  GUIObject_SoftKeys_SetAction( mbk->Gui_submenu, ACTION_LONG_BACK, MusicApp_CancelAction );
  GUIObject_Show( mbk->Gui_submenu );
  return 1;
}

const PAGE_MSG MusicApplication_UseAsFile[] = 
{
  PAGE_ENTER_EVENT,           pg_MusicApplication_UseAsFile__EnterAction,
  PREVIOUS_EVENT,             pg_MusicApplication_UnplugPHF__PreviousAction,
  CANCEL_EVENT,               pg_MusicApplication_UnplugPHF__CancelAction,
  UI_MEDIAPLAYER_UPDATE_EVENT,pg_MusicApplication_UnplugPHF__PreviousAction,
  PAGE_EXIT_EVENT,            pg_MusicApplication_UnplugPHF__ExitAction,
  NIL_EVENT,                  NULL
};

const PAGE_DESC MusicApplication_UseAsFile_Page = {"MusicApplication_UseAsFile_Page",NULL,MusicApplication_UseAsFile};

void Call_UseAsPage( BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  MusicBook->unk_75 = TRUE;
  BookObj_CallPage(MusicBook,&MusicApplication_UseAsFile_Page);
}

extern "C"
void create_new_softkeys(GUI* gui)
{
  GUIObject_SoftKeys_SetItemAsSubItem( gui, ACTION_MP_FILE, ACTION_MP_USE_AS );
  GUIObject_SoftKeys_SetAction( gui, ACTION_MP_USE_AS, Call_UseAsPage );
  GUIObject_SoftKeys_SetText( gui, ACTION_MP_USE_AS, USE_AS_TXT  );
  MediaPlayer_SoftKeys_SetItemAsSubItem( gui, ACTION_MP_FILE, ACTION_MP_USE_AS );
  MediaPlayer_SoftKeys_SetAction( gui, ACTION_MP_USE_AS, Call_UseAsPage );
  MediaPlayer_SoftKeys_SetText( gui, ACTION_MP_USE_AS, USE_AS_TXT  );
}
