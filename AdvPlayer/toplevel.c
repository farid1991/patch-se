#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\AudioPlayerBook.h"

#include "main.h"
#include "toplevel.h"

#if defined(OLD_PLAYER) || defined(DB2020)
void GUIObject_SetAnimation(GUI *gui, int type)
{
  int anim;
  switch (type)
  {
  case LEFT_IN_LEFT_OUT:
    anim = 0x3000000;
    break;
  case LEFT_IN_RIGHT_OUT:
    anim = 0x3000010;
    break;
  case RIGHT_IN_LEFT_OUT:
    anim = 0x3000020;
    break;
  }
  DispObject_SetAnimation(GUIObject_GetDispObject(gui), anim);
}
#endif

extern "C" void New_MainMenu_TopLevelBrowser(GUI *MM_Browser)
{
  GUIObject_SetTitleBackgroundImage(MM_Browser, MP_BRW_TOPW_ICN);
  ListMenu_SetHotkeyMode(MM_Browser, LKHM_SHORTCUT);
}

extern "C" TEXTID New_ListText_TopLevelBrowser(BOOK *book, int index)
{
  TEXTID text_id;

  if (index == MENU_NOWPLAYING)
  {
    text_id = MP_BR_LISTNOWPLAYING_TXT;
  }
  else if (index == MENU_ARTIST)
  {
    text_id = MP_BR_LISTARTIST_TXT;
  }
  else if (index == MENU_ALBUMS)
  {
    text_id = MP_BR_LISTALBUM_TXT;
  }
  else if (index == MENU_TRACKS)
  {
    text_id = MP_BR_LISTTRACK_TXT;
  }
  else if (index == MENU_PLAYLIST)
  {
    text_id = MP_BR_LISTPLAYLIST_TXT;
  }
  else if (index == MENU_VIDEOS)
  {
    text_id = MP_BR_LISTVIDEO_TXT;
  }

  return text_id;
}

extern "C" IMAGEID New_ListIcon_TopLevelBrowser(BOOK *book, int index)
{
  const IMAGEID topLevelBrowserIcons[MENU_LAST] = {
      MP_BR_LISTNOWPLAYING_ICN, // MENU_NOW_PLAYING
      MP_BR_LISTARTIST_ICN,     // MENU_ARTIST
      MP_BR_LISTALBUM_ICN,      // MENU_ALBUMS
      MP_BR_LISTTRACK_ICN,      // MENU_TRACKS
      MP_BR_LISTPLAYLIST_ICN,   // MENU_PLAYLIST
      MP_BR_LISTVIDEO_ICN       // MENU_VIDEOS
  };
  return topLevelBrowserIcons[index];
}

int pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent(void *data, BOOK *book)
{
  MM_BrowserToplevelBook *mm_book = (MM_BrowserToplevelBook *)book;

#ifdef DB2020
  if (!Call_MM_BrowserAlbumsMain(BookObj_GetBookID(mm_book), NULL, 1, &mm_book->pShell))
#else
  if (!Call_MM_BrowserAlbumsMain(BookObj_GetBookID(mm_book), NULL, &mm_book->pShell))
#endif
  {
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_ShowMessage);
  }
  return 1;
}

extern "C" void New_ListLink_TopLevelBrowser(BOOK *book, GUI *gui)
{
  MM_BrowserToplevelBook *mm_book = (MM_BrowserToplevelBook *)book;
  switch (mm_book->index)
  {
  case MENU_NOWPLAYING:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, LEFT_IN_RIGHT_OUT);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_NowPlaying);
    break;
  case MENU_ARTIST:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, RIGHT_IN_LEFT_OUT);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Artists);
    break;
  case MENU_ALBUMS:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, RIGHT_IN_LEFT_OUT);
    BookObj_CallPage(mm_book, &page_MM_Browser_Toplevel_Bk_Albums);
    break;
  case MENU_TRACKS:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, RIGHT_IN_LEFT_OUT);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Tracks);
    break;
  case MENU_PLAYLIST:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, LEFT_IN_RIGHT_OUT);
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Playlist);
    break;
  case MENU_VIDEOS:
    GUIObject_SetAnimation(mm_book->MM_TopLevel, LEFT_IN_RIGHT_OUT);
#ifdef DB2020
    Shortcut_Run(MEDIAPLAYER_VIDEO);
#else
    BookObj_CallPage(mm_book, page_MM_Browser_Toplevel_Bk_Videos);
#endif
    break;
  }
}

extern "C" TEXTID New_ListText_Track(TEXTID TrackName, GUI_MESSAGE *msg)
{
  int index = GUIonMessage_GetCreatedItemIndex(msg);

  TEXTID new_textid[3];
  new_textid[0] = TextID_CreateIntegerID(index + 1);
  new_textid[1] = 0x78000020;
  new_textid[2] = TrackName;
  return TextID_Create(new_textid, ENC_TEXTID, 3);
}

extern "C" void New_MainMenu_TopLevelBrowser_ActionBack(MM_BrowserToplevelBook *mm_book, GUI *gui)
{
  UI_Event(MEDIAPLAYERKEY_PRESSED_EVENT);
}

extern "C" int New_Toplevel_Bk_NowPlaying_PreviousEvent(void *data, MM_BrowserToplevelBook *mm_book)
{
  UI_Event(MEDIAPLAYERKEY_PRESSED_EVENT);
  return 1;
}
