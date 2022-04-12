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

int WStringLength(wchar_t *wstr);
void WStringFree(wchar_t *wstr);
wchar_t *WStringAlloc(int lenght);
int is_digit(char c);
int get_encoding_type(char *s);

#endif
