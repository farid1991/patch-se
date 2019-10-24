/*
;G502 R1FA037
;Dynamic display of Data Counter
;Automatically display in Bytes, Kilo bytes, Mega bytes
;(c) Sic
;(e) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

extern "C"
int new_int2strID(int num, char* filename, int line_num)
{
  if(num) 
  {
    TEXTID ret[3];
    ret[1] = 0x78000000|0x20;

    if (num < 1024)
    {
      ret[0] = TextID_CreateIntegerID_int(num, filename, line_num);
      ret[2] = BYTE;
    }
    else if (num < (1024*1024))
    {
      ret[0] = TextID_CreateIntegerID_int(num/1024, filename, line_num);
      ret[2] = KBYTE;
    }
    else if (num >= (1024*1024))
    {
      ret[0] = TextID_CreateIntegerID_int(num/(1024*1024), filename, line_num);
      ret[2] = MBYTE;
    }
    return TextID_Create_int(ret, ENC_TEXTID, 3, filename, line_num);
  }
  return TextID_CreateIntegerID_int(num, filename, line_num);
}
