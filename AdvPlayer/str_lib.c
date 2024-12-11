#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

inline int isspace(char c)
{
  return (c == ' ' || c >= '\t' && c <= '\r');
}

inline int isdigit(char c)
{
  return (c >= '0' && c <= '9');
}

inline int isxdigit(char c)
{
  return ((c >= '0' && c <= '9') ||
          (c >= 'a' && c <= 'f') ||
          (c >= 'A' && c <= 'F'));
}

int hex2int(const char *h)
{
  int res = 0;

  while (*h && *h != 'x')
    h++;
  if (*h == 'x')
    h++;

  while (*h && *h != ';')
  {
    char c = *h++;
    if (c >= '0' && c <= '9')
    {
      res = (res << 4) | (c - '0');
    }
    else if (c >= 'A' && c <= 'F')
    {
      res = (res << 4) | (c - 'A' + 10);
    }
    else if (c >= 'a' && c <= 'f')
    {
      res = (res << 4) | (c - 'a' + 10);
    }
  }
  return res;
}

int ascii2int(const char *s)
{
  int result = 0;

  while (isspace(*s))
    s++;

  while (isdigit(*s))
  {
    result = result * 10 + (*s - '0');
    s++;
  }

  return result;
}

wchar_t *wstr_alloc(size_t len)
{
  size_t sz = (len + 1) * sizeof(wchar_t);
  wchar_t *wstr = (wchar_t *)malloc(sz);
  memset(wstr, 0, sz);
  return wstr;
}
