#ifndef _STRING_H_
  #define _STRING_H_

typedef enum
{
  ERROR = 0,
  ANSI = 1,
  UTF8_BOM = 2,
  UTF16_LE = 3,
  UTF16_BE = 4
} Encoding_t;

int GetEncodingType(char *str);
void UTF8_to_ANSI(char *ansi, const char *utf8, size_t max_len);
void UTF16LE_to_ANSI(const wchar_t *utf16, char *ansi, size_t max_len);
void UTF16BE_to_ANSI(const wchar_t *utf16be, char *ansi, size_t max_len);

bool is_digit(char c);

char *StringAlloc(int Length);
wchar_t *WStringAlloc(int Length);

#endif
