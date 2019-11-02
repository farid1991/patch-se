#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "utils.h"

void win12512unicode(wchar_t *ws, char *s, int len)
{
  int c;
  while((c=*s++)&&((len--)>0))
  {
    if (c==0xA8) c=0x401;
    if (c==0xAA) c=0x404;
    if (c==0xAF) c=0x407;
    if (c==0xB8) c=0x451;
    if (c==0xBA) c=0x454;
    if (c==0xBF) c=0x457;
    if ((c>=0xC0)&&(c<0x100)) c+=0x350;
    *ws++=c;
  }
  *ws=0;
}

char* unicode2win1251(char *s, wchar_t *ws, int len)
{
  char *d=s;
  int c;
  while((c=*ws++)&&((len--)>0))
  {
    if (c==0x401) c=0xA8;
    if (c==0x404) c=0xAA;
    if (c==0x407) c=0xAF;
    if (c==0x451) c=0xB8;
    if (c==0x454) c=0xBA;
    if (c==0x457) c=0xBF;
    if ((c>=0x410)&&(c<0x450)) c-=0x350;
    *s++=c;
  }
  *s=0;
  return(d);
}

int wcharh2int(wchar_t n)
{
  int r = 0;
  if(n >= '0' && n <= '9') r = n - 0x30;
  if(n == 'a' || n == 'A') r = 10;
  if(n == 'b' || n == 'B') r = 11;
  if(n == 'c' || n == 'C') r = 12;
  if(n == 'd' || n == 'D') r = 13;
  if(n == 'e' || n == 'E') r = 14;
  if(n == 'f' || n == 'F') r = 15;
  return r;
}

int wstr2h(wchar_t * ws, int len)
{
  u16 w;
  int res=0;
  while(len--)
  {
    w=*ws++;
    if ((w>=0x30) && (w<0x40)) w-=0x30;
    else if((w>=0x41) && (w<0x47)) w-=0x37;
    else if((w>=0x61) && (w<0x67)) w-=0x57;
    res<<=4;
    res|=w;
  }
  return(res);
}

wchar_t* WStringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(wchar_t);
  wchar_t *ws = (wchar_t*)malloc(size);
  memset(ws, NULL, size);
  return(ws);
}

char* StringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(char);
  char *s = (char*)malloc(size);
  memset(s, NULL, size);
  return(s);
}
