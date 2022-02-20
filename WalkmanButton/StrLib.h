#ifndef StrLib_h
#define StrLib_h

int WStringLength(wchar_t *wstr);
void WStringFree(wchar_t *wstr);
wchar_t *WStringAlloc(int lenght);
void WStringAllocEx(wchar_t **wstr, int size);
void WStringReallocEx(wchar_t *src, wchar_t **dest, int size);
void WStringRealloc(wchar_t *src, wchar_t **dest);

#endif
