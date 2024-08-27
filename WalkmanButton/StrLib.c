#include "temp\target.h"

#include "..\\include\Types.h"

#include "main.h"
#include "Lib.h"
#include "StrLib.h"

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, NULL, size);
  return (wstr);
}

void WStringAllocEx(wchar_t **wstr, int size)
{
  mfree((*wstr));
  (*wstr) = WStringAlloc(size);
}

void WStringReallocEx(wchar_t *src, wchar_t **dest, int size)
{
  WStringAllocEx(dest, size);
  wstrncpy((*dest), src, size);
}

void WStringRealloc(wchar_t *src, wchar_t **dest)
{
  WStringReallocEx(src, dest, wstrlen(src));
}
