#ifndef _STRING_H_
  #define _STRING_H_

typedef enum
{
  ERROR = 0,
  ANSI = 1,
  UNICODE = 2,
  UNICODE_B = 3,
  UTF8 = 4
} Encoding_t;

int Encoding_GetType(char *str);
char *unicode2win1251(char *s, wchar_t *ws, int len);
void win12512unicode(wchar_t *ws, const char *s, int len);
void UTF82unicode(wchar_t *ws, char *utf8, int len);
void unicode2UTF8(char *utf8, wchar_t *ws, int len);
void utf16_to_utf8(wchar_t *unicode16, char *utf8);

int StringLength(char *Str);
void StringFree(char *Str);
char *StringAlloc(int Length);
char* strdup(char *str);
BOOL IsDigit(char c);

int WStringLength(wchar_t *Str);
void WStringFree(wchar_t *Str);
wchar_t *WStringAlloc(int Length);
void WStringAllocEx(wchar_t **Str, int Size);
void WStringReallocEx(wchar_t *Src, wchar_t **Dest, int Size);
void WStringRealloc(wchar_t *Src, wchar_t **Dest);
void WStringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name);
void WStringExtractFileName(wchar_t *Str, wchar_t **Name);

#endif
