#ifndef SetBook_H_
#define SetBook_H_

typedef struct _SetBook : BOOK
{
  char dummy_1[0x4];
  GUI *gui;
  char dummy_2[0x1C];
  char *bright;
} SetBook;

#endif
