#include "temp\target.h"

#include "..\\include\Types.h"

#include "main.h"
#include "Lib.h"
#include "StrLib.h"

int WStringLength(wchar_t *wstr)
{
  if (wstr)
    return wstrlen(wstr);
  return NULL;
}

void WStringFree(wchar_t *wstr)
{
  if (wstr)
  {
    mfree(wstr);
    wstr = 0;
  }
}

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, NULL, size);
  return (wstr);
}

void WStringAllocEx(wchar_t **wstr, int size)
{
  WStringFree((*wstr));
  (*wstr) = WStringAlloc(size);
}

void WStringReallocEx(wchar_t *src, wchar_t **dest, int size)
{
  WStringAllocEx(dest, size);
  wstrncpy((*dest), src, size);
}

void WStringRealloc(wchar_t *src, wchar_t **dest)
{
  WStringReallocEx(src, dest, WStringLength(src));
}
