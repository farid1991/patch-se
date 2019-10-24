#include "..\\include\Types.h"
#include "..\\include\Function.h"

BOOL isDirectory(wchar_t* filename)
{
  W_FSTAT fs;
  if (w_fstat(filename,&fs)!=-1)
    return(fs.attr&0x4000);
  else return FALSE;
}

TEXTID getFileSize(wchar_t* filename, TEXTID space)
{
  W_FSTAT fs;
  w_fstat(filename,&fs);
/*
  FSTAT fst;
  fstat(fpath,fname,&fst);
*/
  TEXTID tmp2[3];
  
  int size;
  if(fs.st_size<1024)
  {
    size = fs.st_size;
    tmp2[2] = TXT_BYTES;
  }
  else if(fs.st_size < (1024*1024))
  {
    size = fs.st_size/1024;
    tmp2[2] = TXT_KBYTES;
  }
  else if(fs.st_size >= (1024*1024))
  {
    size = fs.st_size/1024/1024;
    tmp2[2] = TXT_MBYTES;
  }
  tmp2[0] = TextID_CreateIntegerID(size);
  tmp2[1] = space;
  return TextID_Create(tmp2,ENC_TEXTID,3);
}

extern "C"
TEXTID SetSecondlineItemText( wchar_t* filename, TEXTID space )
{
  TEXTID tmp2[3];
  tmp2[0] = TextID_CreateFromASCII(0xF8F0);
  tmp2[1] = space;
  
  if(isDirectory(filename))
  {
    tmp2[2] = TXT_FOLDER;
  }
  else
  {
    tmp2[2] = getFileSize(filename,space);
  }
  return TextID_Create(tmp2,ENC_TEXTID,3);
}
