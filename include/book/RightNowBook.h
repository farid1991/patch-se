#ifndef RightNowBook_h
#define RightNowBook_h

#if defined(DB2010)
// 0x2AA0
typedef struct ActivityMenuBook : BOOK
{
  char dummy_1[0x2A58];     // 0x18
  GUI_TABMENUBAR *main_tab; // 0x2A70
  int unk_2A74;             // 0x2A74
  GUI_LIST *first_tab;      // 0x2A78 1st tab Events
  int unk_2A7C;             // 0x2A7C
  int unk_2A80;             // 0x2A80
  GUI_LIST *third_tab;      // 0x2A84 3rd tab Internet
  GUI_LIST *second_tab;     // 0x2A8C 2nd tab ActiveTask & Shortcuts
  char dummy_2[0x14];       // 0x2A8C
} ActivityMenuBook;

#elif defined(DB2020) || defined(PNX5230)
typedef struct ActivityMenuBook : BOOK
{
  char dummy1[0x2934];  // 0x18
  GUI *main_tab;        // 0x294C
  char dummy2[0x4];     // 0x2950
  GUI_LIST *first_tab;  // 0x2954 1st tab Events
  char dummy3[0x4];     // 0x2958
  char dummy4[0x4];     // 0x295C
  GUI_LIST *second_tab; // 0x2960 2nd tab ActiveTasks
  GUI_LIST *third_tab;  // 0x2964 3rd tab Shortcuts
  GUI_LIST *fourth_tab; // 0x2968 4th tab Internet
  char dummy5[0x28];
} ActivityMenuBook; // 0x2980

#endif

#endif
