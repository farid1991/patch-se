#ifndef _STRLIB_H_
  #define _STRLIB_H_

int StringLength(wchar_t *Str);
void StringFree(wchar_t *Str);
wchar_t *StringAlloc(int Length);
void StringAllocEx(wchar_t **Str, int Size);
void StringReallocEx(wchar_t *Src, wchar_t **Dest, int Size);
void StringRealloc(wchar_t *Src, wchar_t **Dest);
void StringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name);
void StringExtractFileName(wchar_t *Str, wchar_t **Name);

#endif
