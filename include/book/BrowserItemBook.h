#ifndef _BROWSERITEMBOOK_H_
#define _BROWSERITEMBOOK_H_

typedef struct _BrowserItemBook : BOOK
{
  SUB_EXECUTE* sub;
  char dummy[0x210];
  SUB_EXECUTE* sub_2;
}BrowserItemBook;

#endif
