#ifndef _STRING_H_
  #define _STRING_H_

int wcharh2int( wchar_t n );
int wstr2h(wchar_t * ws, int len);
void win12512unicode( wchar_t *ws, char *s, int len );
char *unicode2win1251( char *s, wchar_t *ws, int len );

wchar_t* WStringAlloc(int lenght);
int WStringLength(wchar_t * wstr);
void WStringFree(wchar_t *wstr);
void WStringRealloc(wchar_t *src, wchar_t **dest);

char* StringAlloc(int lenght);

#endif
