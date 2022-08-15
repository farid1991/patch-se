#include "temp\target.h"

#include "..\\include\Types.h"

#include "main.h"
#include "Lib.h"
#include "bookman.h"
#include "quickaccessmenu.h"
#include "screenshot.h"
#include "shortcut.h"

__thumb void *malloc(int size)
{
  return memalloc(size, 1, 5, "mem", NULL);
}

__thumb void mfree(void *mem)
{
  if (mem)
    memfree(mem, "mem", NULL);
}

TEXTID GetFreeHeap()
{
  wchar_t buff[64];
  snwprintf(buff, MAXELEMS(buff), L"Heap: %d Kb", GetFreeBytesOnHeap() >> 10);
  return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

extern "C" void Patch_QuickAccess()
{
  if (!isKeylocked())
    Create_QuickAccess_Book();
}

extern "C" void Patch_BookManager()
{
  if (!isKeylocked())
    Create_BookManager();
}

extern "C" void Patch_NextBook()
{
  if (!isKeylocked())
#ifdef DB2010
    Screenshoter(Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main));
#else
    NextBook();
#endif
}
