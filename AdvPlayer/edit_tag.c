#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\AudioPlayerBook.h"

#include "edit_tag.h"

__arm void start_elf(wchar_t *arg1, wchar_t *arg2, wchar_t *arg3)
{
  elfload(arg1, arg2, arg3, NULL);
}

void tagedit_start_elf(BOOK *book, GUI *gui)
{
  AudioPlayerBook *audio_book = (AudioPlayerBook *)book;
  PLAYLIST_ITEM *item = (PLAYLIST_ITEM *)malloc(sizeof(PLAYLIST_ITEM));

  if (audio_book->pPlaylist->GetItem(audio_book->playlist_id, audio_book->selected_track_id, item) >= 0)
  {
    if (FSX_IsFileExists(ZBIN_PATH, L"MusicTagger.elf"))
    {
      start_elf(ELF("MusicTagger.elf"), item->fpath, item->fname);
    }
    else if (FSX_IsFileExists(ZBIN_PATH, L"TagEditor.elf"))
    {
      start_elf(ELF("TagEditor.elf"), item->fpath, item->fname);
    }
    else
    {
      MessageBox(EMPTY_TEXTID, TextID_Create("ELF not found", ENC_LAT1, 14), NOIMAGE, 0, 0, audio_book);
    }
  }
  mfree(item);
}
