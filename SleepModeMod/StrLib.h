#ifndef StrLib_h
#define StrLib_h

typedef enum
{
  UTF8,
  UTF8_BOM,
  UTF16_LE,
  UTF16_BE,
  OTHERS_ENC
} ENCODING_T;

char *unicode2win1251(char *s, wchar_t *ws, int len);
void win12512unicode(wchar_t *ws, const char *s, int len);
void UTF82unicode(wchar_t *ws, char *utf8, int len);
void unicode2UTF8(char *utf8, wchar_t *ws, int len);
void utf16_to_utf8(wchar_t *unicode16, char *utf8);

int StringLength(char *Str);
void StringFree(char *Str);
char *StringAlloc(int Length);
char* strdup(char *str);

int WStringLength(wchar_t *wstr);
void WStringFree(wchar_t *wstr);
wchar_t *WStringAlloc(int lenght);
int is_digit(char c);
int get_encoding_type(char *s);

#endif
