#ifndef _DATABROWSERBOOK_H_
#define _DATABROWSERBOOK_H_

typedef struct _DataBrowserBook : BOOK
{
  char dummy_1[0x214];
  SUB_EXECUTE* sub_exec;
  char dummy_2[0x5C];
  LIST* list;
}DataBrowserBook;

#endif
