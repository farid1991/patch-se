#ifndef StrLib_h
#define StrLib_h

wchar_t *WStringAlloc(int lenght);
void WStringAllocEx(wchar_t **wstr, int size);
void WStringReallocEx(wchar_t *src, wchar_t **dest, int size);
void WStringRealloc(wchar_t *src, wchar_t **dest);

#endif
