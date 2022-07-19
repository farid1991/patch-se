#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "data.h"
#include "main.h"
#include "toplevel.h"

#ifdef OLD_PLAYER
void GUIObject_SetAnimation(GUI *gui, int anim)
{
  DISP_OBJ *disp_obj = GUIObject_GetDispObject(gui);
  if (anim == 0)
  {
    DispObject_SetAnimation(disp_obj, 0x3000000);
  }
  else if (anim == 1)
  {
    DispObject_SetAnimation(disp_obj, 0x3000010);
  }
  else if (anim == 2)
  {
    DispObject_SetAnimation(disp_obj, 0x3000020);
  }
}
#endif

extern "C" void New_MainMenu_TopLevelBrowser(GUI *MM_Browser)
{
  GUIObject_SetTitleBackgroundImage(MM_Browser, MP_BRW_TOPW_ICN);
  ListMenu_SetHotKeyMode(MM_Browser, LKHM_SHORTCUT);
}

extern "C" TEXTID New_ListText_TopLevelBrowser(BOOK *book, int index)
{
  switch (index)
  {
  case MENU_NOW_PLAYING:
    return MP_BR_LISTNOWPLAYING_TXT;
  case MENU_ARTIST:
    return MP_BR_LISTARTIST_TXT;
  case MENU_ALBUMS:
    return MP_BR_LISTALBUM_TXT;
  case MENU_TRACKS:
    return MP_BR_LISTTRACK_TXT;
  case MENU_PLAYLIST:
    return MP_BR_LISTPLAYLIST_TXT;
  case MENU_VIDEOS:
    return MP_BR_LISTVIDEO_TXT;
  default:
    return EMPTY_TEXTID;
  }
}
extern "C" IMAGEID New_ListIcon_TopLevelBrowser(BOOK *book, int index)
{
  switch (index)
  {
  case MENU_NOW_PLAYING:
    return MP_BR_LISTNOWPLAYING_ICN;
  case MENU_ARTIST:
    return MP_BR_LISTARTIST_ICN;
  case MENU_ALBUMS:
    return MP_BR_LISTALBUM_ICN;
  case MENU_TRACKS:
    return MP_BR_LISTTRACK_ICN;
  case MENU_PLAYLIST:
    return MP_BR_LISTPLAYLIST_ICN;
  case MENU_VIDEOS:
    return MP_BR_LISTVIDEO_ICN;
  default:
    return NOIMAGE;
  }
}

int pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent(void *data, BOOK *book)
{
  void *pIshell = NULL;
  int ret = Call_MM_BrowserAlbumsMain(BookObj_GetBookID(book), NULL, &pIshell);
  if (!ret)
    BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_ShowMessage);
  return 1;
}

extern "C" void New_ListLink_TopLevelBrowser(BOOK *book, GUI *gui)
{
  MM_BrowserToplevelBook *mm_book = (MM_BrowserToplevelBook *)book;
  switch (mm_book->index)
  {
  case MENU_NOW_PLAYING:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, 1);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_NowPlaying);
    break;
  case MENU_ARTIST:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, 2);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Artists);
    break;
  case MENU_ALBUMS:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, 2);
    BookObj_CallPage(mm_book, &page_MM_Browser_Toplevel_Bk_Albums);
    break;
  case MENU_TRACKS:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, 1);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Tracks);
    break;
  case MENU_PLAYLIST:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, 1);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Playlist);
    break;
  case MENU_VIDEOS:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, 1);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Videos);
    break;
  }
}

extern "C" TEXTID New_ListText_Track(TEXTID TrackName, GUI_MESSAGE *msg)
{
  int index = GUIonMessage_GetCreatedItemIndex(msg);

  TEXTID new_textid[3];
  new_textid[0] = TextID_CreateIntegerID(index + 1);
  new_textid[1] = TextID_CreateFromChar(' ');
  new_textid[2] = TrackName;
  return TextID_Create(new_textid, ENC_TEXTID, 3);
}
