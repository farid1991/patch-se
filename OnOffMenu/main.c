#include "temp\target.h"

#include "..\\include\Types.h"

#include "main.h"
#include "Lib.h"
#include "bookman.h"
#include "quickaccessmenu.h"
#include "shortcut.h"

__thumb void *malloc(int size)
{
  return memalloc(size, 1, 5, "mem", 0);
}

__thumb void mfree(void *mem)
{
  memfree(mem, "mem", 0);
}

TEXTID GetFreeHeap()
{
  wchar_t buff[64];
  snwprintf(buff, MAXELEMS(buff), L"Heap: %d Kb", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" void Patch_OnOffButton()
{
  if (!isKeylocked())
    Create_QuickAccess_Book();
}

extern "C" void Patch_ActButton()
{
  if (!isKeylocked())
    Create_BookManager();
}

extern "C" void Patch_VCButton()
{
  if (!isKeylocked())
    NextBook();
}
