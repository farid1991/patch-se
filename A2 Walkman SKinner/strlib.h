#ifndef _STRLIB_H_
  #define _STRLIB_H_

int StringLength(char *Str);
void StringFree(char *Str);
char *StringAlloc(int Length);
int WStringLength(wchar_t *Str);
void WStringFree(wchar_t *Str);
wchar_t *WStringAlloc(int Length);
void WStringAllocEx(wchar_t **Str, int Size);
void WStringReallocEx(wchar_t *Src, wchar_t **Dest, int Size);
void WStringRealloc(wchar_t *Src, wchar_t **Dest);
void WStringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name);
void WStringExtractFileName(wchar_t *Str, wchar_t **Name);
void splitfilename(const wchar_t* src, wchar_t* destpath, wchar_t* destname);

#endif
