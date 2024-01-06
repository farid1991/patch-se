#ifndef _STRING_H_
#define _STRING_H_

typedef enum
{
  ERROR = 0,
  ANSI = 1,
  UTF16_LE = 2,
  UTF16_BE = 3,
  UTF8 = 4
} Encoding_t;

int GetTextIDWidth(int font, TEXTID text, int len);
int Encoding_GetType(char *str);
char *unicode2win1251(char *s, wchar_t *ws, size_t len);
void win12512unicode(wchar_t *ws, const char *s, size_t len);
void UTF8_to_ANSI(char *ansi, const char *utf8, size_t max_len);
void UTF16LE_to_ANSI(const wchar_t *utf16, char *ansi, size_t max_len);
void UTF16BE_to_ANSI(const wchar_t *utf16be, char *ansi, size_t max_len);

BOOL is_digit(char c);

char *StringAlloc(int Length);
wchar_t *WStringAlloc(int Length);

#endif
