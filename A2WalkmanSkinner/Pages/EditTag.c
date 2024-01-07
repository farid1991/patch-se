#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#if defined(DB3150v1)
#include "..\\..\\include\book\DB3150v1\MusicApplication_Book.h"
#elif defined(DB3150v2)
#include "..\\..\\include\book\DB3150v2\MusicApplication_Book.h"
#elif defined(DB3200) || defined(DB3210)
#include "..\\..\\include\book\DB3210\MusicApplication_Book.h"
#endif

#include "..\\main.h"

#include "EditTag.h"

//==============================================================================

__arm void StartElf(wchar_t *arg1, wchar_t *arg2, wchar_t *arg3)
{
  elfload(arg1, arg2, arg3, NULL);
}

void Enter_EditTag(BOOK *book, GUI *gui)
{
  MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
  FILEITEM *fi = MusicBook->CurrentTrack->file_item;

  if (FSX_IsFileExists(ZBIN_INT, L"MusicTagger.elf"))
  {
    StartElf(L"/usb/other/ZBin/MusicTagger.elf", fi->__path, fi->__fname);
  }
  else if (FSX_IsFileExists(ZBIN_INT, L"TagEditor.elf"))
  {
    StartElf(L"/usb/other/ZBin/TagEditor.elf", fi->__path, fi->__fname);
  }
  else if (FSX_IsFileExists(ZBIN_EXT, L"MusicTagger.elf"))
  {
    StartElf(L"/card/other/ZBin/TagEditor.elf", fi->__path, fi->__fname);
  }
  else if (FSX_IsFileExists(ZBIN_EXT, L"TagEditor.elf"))
  {
    StartElf(L"/card/other/ZBin/TagEditor.elf", fi->__path, fi->__fname);
  }
}
