#ifndef _SERVICEMENUBOOK_H_
#define _SERVICEMENUBOOK_H_

typedef struct _ServiceMenuBook : BOOK
{
  char dummy_01[0x4];
  char dummy_02[0x4];
  GUI* gui;
  u16  cur_pos;
}ServiceMenuBook;

#endif
