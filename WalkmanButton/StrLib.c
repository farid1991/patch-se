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
  FREE(wstr);
}

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, NULL, size);
  return (wstr);
}
