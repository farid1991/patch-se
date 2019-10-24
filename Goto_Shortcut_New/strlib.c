#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "strlib.h"

int StringLength(wchar_t * wstr)
{
  if (wstr) return(wstrlen(wstr));
  else return NULL;
}

void StringFree(wchar_t *wstr)
{
  if (wstr)
  {
    mfree(wstr);
    wstr = NULL;
  }
}

wchar_t* StringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(wchar_t);
  wchar_t* wstr = (wchar_t*)malloc(size);
  memset(wstr, NULL, size);
  return(wstr);
}

void StringAllocEx(wchar_t **wstr, int size)
{
  StringFree((*wstr));
  (*wstr) = StringAlloc(size);
}

void StringReallocEx(wchar_t *src, wchar_t **dest, int size)
{
  StringAllocEx(dest, size);
  wstrncpy((*dest), src, size);
}

void StringRealloc(wchar_t *src, wchar_t **dest)
{
  StringReallocEx(src, dest, StringLength(src));
}
/*            
void StringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name)
{
  StringAllocEx(Filename, StringLength(Path) + StringLength(Name) + sizeof(wchar_t)); // + L"/"
  wstrcpy((*Filename), Path);
  wstrcat((*Filename), L"/");
  wstrcat((*Filename), Name);
  *Filename = FSX_MakeFullPath(Path,Name);
}
*/    
void StringExtractFileName(wchar_t *str, wchar_t **name)
{
  wchar_t* pos = wstrrchr(str, '/');
  *pos = NULL;
  StringRealloc(pos+1, name);
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

