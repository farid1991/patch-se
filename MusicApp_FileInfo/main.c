#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\MusicApplication_book.h"
#include "..\\include\classes\IMusicServer.h"
#include "Lib.h"
#include "main.h"

int pg_MusicApplication_FileInfo__EnterAction(void *Data, BOOK *book)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  if (pMusicBook)
  {
    if (pMusicBook->CurrentTrack)
    {
      wchar_t *fpath = FILEITEM_GetPath(pMusicBook->CurrentTrack->file_item);
      wchar_t *fname = FILEITEM_GetFname(pMusicBook->CurrentTrack->file_item);

      wchar_t *fullpath = FSX_MakeFullPath(fpath, fname);
      MusicApplication_ExecuteSubroutine(pMusicBook, DB_ACTION_INFO, fullpath);
      FSX_FreeFullPath(fullpath);
    }
    else
    {
      pMusicBook->ErrorText = 0x1644;
      BookObj_CallPage(pMusicBook, page_MusicApplication_ShowMessage);
    }
  }
  return 1;
}

const PAGE_MSG MusicApplication_FileInfo[] =
    {
        PAGE_ENTER_EVENT, pg_MusicApplication_FileInfo__EnterAction,
        PREVIOUS_EVENT, pg_MusicApplication_PreviousAction,
        CANCEL_EVENT, pg_MusicApplication_CancelAction,
        UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousAction,
        PAGE_EXIT_EVENT, pg_MusicApplication_ExitAction,
        NIL_EVENT, NULL};

const PAGE_DESC MusicApplication_FileInfo_Page = {"MusicApplication_FileInfo_Page", NULL, MusicApplication_FileInfo};

void Call_FileInfoPage(BOOK *book, GUI *gui)
{
  MusicApplication_Book *pMusicBook = (MusicApplication_Book *)book;
  pMusicBook->unk_0x94 = TRUE;
  BookObj_CallPage(pMusicBook, &MusicApplication_FileInfo_Page);
}

extern "C" void create_new_softkeys(GUI *Gui_submenu)
{
  GUIObject_SoftKeys_SetItemAsSubItem(Gui_submenu, ACTION_MP_FILE, ACTION_MP_FILEINFO);
  GUIObject_SoftKeys_SetAction(Gui_submenu, ACTION_MP_FILEINFO, Call_FileInfoPage);
  GUIObject_SoftKeys_SetText(Gui_submenu, ACTION_MP_FILEINFO, FILEINFO_TXT);
}
