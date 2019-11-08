/*
;A2 Walkman skinner
;Adds possibility to edit the Position,Color,Font
;Enable/Disable Title,Artist,Album,Genre,Total/Elapsed/Remaining time,Extension,Bit-rate,Total/Current track number,progress-bar,Album art
;Adds new items of Genre,Extension,Bit-rate,Overlay image to Walkman
;Adds possibility to edit position of icons shuffle/EQ/loop/state/wheel,Title/Artist/Album/Background/Overlay image
;Adds possibility to use skins in Walkman Player
;Adds skin editor for easy loading & editing of skins
;Adds possibility to use Walkman 4 visualization
;Redraws everything in Walkman,optimized for better Walkman experience
;v.1.5
;(c) blacklizard
;(r) KreN
;(e) farid, D3mon
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "Walkman.h"
#include "strlib.h"

int StringLength(char *str)
{
  if (str) return(strlen(str));
  else return NULL;
}

void StringFree(char *str)
{
  if (str)
  {
    mfree(str);
    str = NULL;
  }
}

char* StringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(char);
  char *s = (char*)malloc(size);
  memset(s, NULL, size);
  return(s);
}

int WStringLength(wchar_t *str)
{
  if (str) return(wstrlen(str));
  else return NULL;
}

void WStringFree(wchar_t *str)
{
  if (str)
  {
    mfree(str);
    str = NULL;
  }
}

wchar_t* WStringAlloc(int lenght)
{
  int size = (lenght+1) * sizeof(wchar_t);
  wchar_t *ws = (wchar_t*)malloc(size);
  memset(ws, NULL, size);
  return(ws);
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
  WStringAllocEx(Filename, WStringLength(Path) + WStringLength(Name) + 2); // + L"/"
  wstrcpy((*Filename), Path);
  wstrcat((*Filename), L"/");
  wstrcat((*Filename), Name);
  //*Filename = FSX_MakeFullPath(Path,Name);
}
    
void WStringExtractFileName(wchar_t *str, wchar_t **name)
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
  WStringRealloc(str, name);
}

void splitfilename(const wchar_t* src, wchar_t* destpath, wchar_t* destname)
{
  wchar_t* fname=wstrrchr(src,'/');
  if(fname)
  {
    wstrncpy(destpath,src,fname-src);
    destpath[fname-src] = 0;
    wstrcpy(destname,fname+1);
  }
  else
  {
    destpath[0] = 0;
    wstrcpy(destname,src);
  }
}
