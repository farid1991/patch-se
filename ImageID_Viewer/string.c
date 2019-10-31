#include "..\\include\Types.h"

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
