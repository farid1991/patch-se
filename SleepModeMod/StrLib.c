#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "main.h"
#include "StrLib.h"

int is_digit(char c)
{
  return (c >= '0' && c <= '9');
}

int get_encoding_type(char *s)
{
  if (s[0] == 0xFF && s[1] == 0xFE) // unicode little-endian
  {
    return UTF16_LE;
  }
  else if (s[0] == 0xFE && s[1] == 0xFF) // unicode big-endian
  {
    return UTF16_BE;
  }
  else if (s[0] == 0xEF && s[1] == 0xBB && s[2] == 0xBF) // utf-8 with BOM
  {
    return UTF8_BOM;
  }
  else // expecting ANSI encoding =)
    return UTF8;
}

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
    wstr = NULL;
  }
}

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(size);
  memset(wstr, NULL, size);
  return (wstr);
}
