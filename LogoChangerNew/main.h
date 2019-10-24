#ifndef _MAIN_H_
#define _MAIN_H_

typedef struct
{
  wchar_t opname[32];
}FILEDATA;

typedef struct : BOOK
{
  //char dummy0[0x18];
  GUI* gui;
}BT_Book;

extern "C"
{
 void onBackPressed(BOOK *bk, GUI* gui);
 void onLongBackPressed(BOOK *bk, GUI* gui);
 
 int pg_EditPhoneName(void* mess, BOOK* bk);
 int pg_MainMenuHandsfreeAddCancelled(void* mess, BOOK* bk);
};

#endif
