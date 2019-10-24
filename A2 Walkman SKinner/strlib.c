#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "Walkman.h"
#include "strlib.h"

int StringLength(wchar_t *str)
{
  if (str) return(wstrlen(str));
  else return NULL;
}

void StringFree(wchar_t *str)
{
  if (str)
  {
    mfree(str);
    str = NULL;
  }
}

wchar_t* StringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(wchar_t);
  wchar_t *ws = (wchar_t*)malloc(size);
  memset(ws, NULL, size);
  return(ws);
}

void StringAllocEx(wchar_t **str, int size)
{
  StringFree((*str));
  (*str) = StringAlloc(size);
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
                
void StringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name)
{
  StringAllocEx(Filename, StringLength(Path) + StringLength(Name) + 2); // + L"/"
  wstrcpy((*Filename), Path);
  wstrcat((*Filename), L"/");
  wstrcat((*Filename), Name);
  //*Filename = FSX_MakeFullPath(Path,Name);
}
    
void StringExtractFileName(wchar_t *str, wchar_t **name)
{
//    if (* Name)
//    {
//        mfree((* Name));
//        (* Name) = NULL;
//    }
 //   int lenght = wstrlen(str);
 //   int Index = lenght;
 //   while (Str[Index] != L"/")
//        Index--;
 //   
 //   (* Name) = StringAlloc(lenght - Index + 1);
 //   wstrncpy((* Name), Str[Index], lenght - Index);
    StringRealloc(str, name);
}

