#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "String.h"

//==============================================================================

int Encoding_GetType(char *str)
{
  if (str[0] == 0xFF && str[1] == 0xFE) // unicode
  {
    return UNICODE;
  }
  else if (str[0] == 0xFE && str[1] == 0xFF) // unicode big-endian
  {
    return UNICODE_B;
  }
  else if (str[0] == 0xEF && str[1] == 0xBB && str[2] == 0xBF) // utf-8
  {
    return UTF8;
  }
  else
  {
    return ANSI;
  }
}

char *unicode2win1251(char *s, wchar_t *ws, int len)
{
  char *d = s;
  int c;
  while ((c = *ws++) && ((len--) > 0))
  {
    if (c == 0x401)
      c = 0xA8;
    if (c == 0x404)
      c = 0xAA;
    if (c == 0x407)
      c = 0xAF;
    if (c == 0x451)
      c = 0xB8;
    if (c == 0x454)
      c = 0xBA;
    if (c == 0x457)
      c = 0xBF;
    if ((c >= 0x410) && (c < 0x450))
      c -= 0x350;
    *s++ = c;
  }
  *s = 0;
  return (d);
};

void win12512unicode(wchar_t *ws, const char *s, int len)
{
  int c;
  while ((c = *s++) && ((len--) > 0))
  {
    if (c == 0xA8)
      c = 0x401;
    if (c == 0xAA)
      c = 0x404;
    if (c == 0xAF)
      c = 0x407;
    if (c == 0xB8)
      c = 0x451;
    if (c == 0xBA)
      c = 0x454;
    if (c == 0xBF)
      c = 0x457;
    if ((c >= 0xC0) && (c < 0x100))
      c += 0x350;
    *ws++ = c;
  }
  *ws = 0;
}

int utf8len(char *utf8)
{
  int len = NULL;
  for (; *utf8; utf8++)
  {
    int c = *utf8;
    if (c >= 0x0 && c <= 0x7F)
      len++;
    else if (c >= 0xC0 && c <= 0xDF)
    {
      utf8++;
      len++;
    }
  }
  return (len);
}

void UTF82unicode(wchar_t *ws, char *utf8, int len)
{
  int c;
  while ((c = *utf8++) && ((len--) > 0))
  {
    if (c >= 0x0 && c <= 0x7F)
    {
      *ws++ = c;
    }
    else if (c >= 0xC0 && c <= 0xDF)
    {
      *ws++ = ((c & 0x1F) << 6) | ((*utf8++) & 0x3F);
    }
  }
  *ws = 0;
}

void unicode2UTF8(char *utf8, wchar_t *ws, int len)
{
  int c;
  while ((c = *ws++) && ((len--) > 0))
  {
    if (c >= 0x0 && c <= 0x7F)
    {
      *utf8++ = c;
    }
    else if (c >= 0x80 && c <= 0x7FF)
    {
      *utf8++ = (0xC0 | ((c & 0x7C0) >> 6));
      *utf8++ = (0x80 | (c & 0x3F));
    }
  }
  *utf8 = 0;
}

void utf16_to_utf8(wchar_t *unicode16, char *utf8)
{
  int i;
  for (i = 0; unicode16[i]; i++)
  {
    if ((unicode16[i] & 0xFF80) == 0)
    {
      *(utf8++) = unicode16[i] & 0xFF;
    }
    else if ((unicode16[i] & 0xF800) == 0)
    {
      *(utf8++) = ((unicode16[i] >> 6) & 0xFF) | 0xC0;
      *(utf8++) = (unicode16[i] & 0x3F) | 0x80;
    }
    else if ((unicode16[i] & 0xFC00) == 0xD800 && (unicode16[i + 1] & 0xFC00) == 0xDC00)
    {
      *(utf8++) = (((unicode16[i] + 64) >> 8) & 0x3) | 0xF0;
      *(utf8++) = (((unicode16[i] >> 2) + 16) & 0x3F) | 0x80;
      *(utf8++) = ((unicode16[i] >> 4) & 0x30) | 0x80 | ((unicode16[i + 1] << 2) & 0xF);
      *(utf8++) = (unicode16[i + 1] & 0x3F) | 0x80;
      i += 1;
    }
    else
    {
      *(utf8++) = ((unicode16[i] >> 12) & 0xF) | 0xE0;
      *(utf8++) = ((unicode16[i] >> 6) & 0x3F) | 0x80;
      *(utf8++) = (unicode16[i] & 0x3F) | 0x80;
    }
  }

  *utf8 = '\0';
}

int StringLength(char *str)
{
  if (str)
    return (strlen(str));
  else
    return NULL;
}

void StringFree(char *str)
{
  if (str)
  {
    mfree(str);
    str = NULL;
  }
}

char *StringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(char);
  char *s = (char *)malloc(size);
  memset(s, NULL, size);
  return (s);
}

char *strdup(char *str)
{
  int len = StringLength(str);
  char *ret = StringAlloc(len);
  return ret;
}

int IsDigit(char c)
{
  return (c >= '0' && c <= '9');
}

int WStringLength(wchar_t *str)
{
  if (str)
    return (wstrlen(str));
  else
    return NULL;
}

void WStringFree(wchar_t *str)
{
  if (str)
  {
    mfree(str);
    str = NULL;
  }
}

wchar_t *WStringAlloc(int lenght)
{
  int size = (lenght + 1) * sizeof(wchar_t);
  wchar_t *ws = (wchar_t *)malloc(size);
  memset(ws, NULL, size);
  return (ws);
}

void WStringAllocEx(wchar_t **str, int size)
{
  WStringFree((*str));
  (*str) = WStringAlloc(size);
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

void WStringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name)
{
  WStringAllocEx(Filename, WStringLength(Path) + WStringLength(Name) + 2);
  wstrcpy((*Filename), Path);
  wstrcat((*Filename), L"/");
  wstrcat((*Filename), Name);
}

void WStringExtractFileName(wchar_t *str, wchar_t **name)
{
  WStringRealloc(str, name);
}
