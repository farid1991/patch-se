#ifndef _GUI_H_
#define _GUI_H_

typedef struct _GUI
{
   DISP_OBJ* disp;
   BOOK* book;
   char dummy[0x84];
}GUI;

#endif