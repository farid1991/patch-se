#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"
#include "strlib.h"

int WStringLength(wchar_t * wstr)
{
  if (wstr) return(wstrlen(wstr));
  else return NULL;
}

void WStringFree(wchar_t *wstr)
{
  if (wstr)
  {
    mfree(wstr);
    wstr = NULL;
  }
}

wchar_t* WStringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(wchar_t);
  wchar_t* wstr = (wchar_t*)malloc(size);
  memset(wstr, NULL, size);
  return(wstr);
}

void WStringAllocEx(wchar_t **wstr, int size)
{
  WStringFree((*wstr));
  (*wstr) = WStringAlloc(size);
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
/*            
void StringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name)
{
  StringAllocEx(Filename, WStringLength(Path) + WStringLength(Name) + sizeof(wchar_t)); // + L"/"
  wstrcpy((*Filename), Path);
  wstrcat((*Filename), L"/");
  wstrcat((*Filename), Name);
  *Filename = FSX_MakeFullPath(Path,Name);
}
*/    
void WStringExtractFileName(wchar_t *str, wchar_t **name)
{
  wchar_t* pos = wstrrchr(str, '/');
  *pos = NULL;
  WStringRealloc(pos+1, name);
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

