#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\MusicApplication_book.h"

__arm void StartElf(wchar_t* a, wchar_t* b, wchar_t* c)
{
  elfload(a,b,c,NULL);
}

void Call_Musictagger(BOOK* book, GUI* gui)
{
  MusicApplication_Book* MusicBook = (MusicApplication_Book*)book;
  FILEITEM* fi = MusicBook->sub_exec->file_item;
  StartElf(L"/usb/other/ZBin/MusicTagger.elf",fi->__path,fi->__fname);
}

extern "C"
void create_new_softkeys(GUI* gui)
{
  GUIObject_SoftKeys_SetItemAsSubItem( gui, ACTION_MP_FILE, ACTION_MP_EDITTAG );
  GUIObject_SoftKeys_SetAction( gui, ACTION_MP_EDITTAG, Call_Musictagger );
  GUIObject_SoftKeys_SetText( gui, ACTION_MP_EDITTAG, STR("EditTag") );
  MediaPlayer_SoftKeys_SetItemAsSubItem( gui, ACTION_MP_FILE, ACTION_MP_EDITTAG );
  MediaPlayer_SoftKeys_SetAction( gui, ACTION_MP_EDITTAG, Call_Musictagger );
  MediaPlayer_SoftKeys_SetText( gui, ACTION_MP_EDITTAG, STR("EditTag") );
}
