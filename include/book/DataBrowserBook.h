#ifndef DataBrowserBook_H
#define DataBrowserBook_H

typedef struct DataBrowserBook : BOOK
{
#if defined(DB2010)
  int unk_18;            // 0x18
  GUI_LIST *DB_GUI;      // 0x1C
  char dummy_1[0x204];   // 0x20
  SUB_EXECUTE *sub_exec; // 0x224
  char dummy_2[0x58];    // 0x228
  LIST *list;            // 0x280
#elif defined(DB3150v1)
  char dummy_1[0x214];   // 0x18
  SUB_EXECUTE *sub_exec; // 0x22C
  char dummy_2[0x5C];    // 0x230
  LIST *list;            // 0x28C
#endif
} DataBrowserBook;

#endif
