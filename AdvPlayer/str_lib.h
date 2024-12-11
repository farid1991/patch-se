#ifndef _StrLib_h_
#define _StrLib_h_

int isspace(char c);
int isdigit(char c);
int isxdigit(char c);

int hex2int(const char *h);
int ascii2int(const char *s);
wchar_t *wstr_alloc(size_t len);

#endif
