#ifndef _ACTIVITYMENUBOOK_H_
#define _ACTIVITYMENUBOOK_H_

//LIST_SHORTCURTS (LIST*)0x4BA24274
//LIST_ACTIVETASKS (LIST*)0x4BA24264

typedef struct _GUI_LIST_2TAB 
{
  void* a;        // 0
  void* b;        // 0x4
  void* c;        // 0x8
  void* d;        // 0xC
  void* e;        // 0x10
  void* f;        // 0x14
  void* g;        // 0x18
  void* h;        // 0x1C
  void* i;        // 0x20
} GUI_LIST_2TAB;

typedef struct _GUI_LIST_3TAB 
{
  void* a;        // 0
  void* b;        // 0x4
  void* c;        // 0x8
  void* d;        // 0xC
  void* e;        // 0x10
  void* f;        // 0x14
  void* g;        // 0x18
  void* h;        // 0x1C
  void* i;        // 0x20
} GUI_LIST_3TAB;

typedef struct _GUI_LIST_4TAB 
{
  void* a;        // 0
  void* b;        // 0x4
  void* c;        // 0x8
  void* d;        // 0xC
  void* e;        // 0x10
  void* f;        // 0x14
  void* g;        // 0x18
  void* h;        // 0x1C
  void* i;        // 0x20
} GUI_LIST_4TAB;

typedef struct _ActivityMenuBook : BOOK
{
  LIST* list1;                      // 0x18
  LIST* EventsList;                 // 0x1C
  LIST* InternetList;               // 0x20
  GUI_TABMENUBAR* main_tab;         // 0x24 ActivityMenu 0x24
  GUI_LIST* first_tab;              // 0x28 1st tab Events
  char unk_0x2C[0x4];               // 0x2C
  char unk_0x30[0x4];               // 0x30
  GUI_LIST* fourth_tab;             // 0x34 4th tab Internet
  GUI_LIST* third_tab;              // 0x38 3rd tab Shortcuts
  GUI_LIST* second_tab;             // 0x3C 2nd tab ActiveTasks
}ActivityMenuBook; // size 0x64(100)

/*
typedef struct _ActivityMenuBook : BOOK
{
  LIST* list1;                      // 0x18
  LIST* EventsList;                 // 0x1C
  LIST* InternetList;               // 0x20
  char dummy2[0x4];
  GUI_TABMENUBAR* ActivityMenu;     // 0x24
  GUI_LIST* Events;                 // 0x28
  char dummy3[0x4];
  GUI* gui3;                        // 0x30
  GUI_LIST* Internet;               // 0x34
  char dummy4[0x4];
  GUI_LIST* Shortcuts;              // 0x38
  GUI_LIST* ActiveTasks;            // 0x3C
  char dummy5[0x4];
  GUI_LIST* ShortcutsMove;          // 0x40
  char unk1;                        // 0x44
  char unk2;                        // 0x45
  char unk3;                        // 0x46
  char unk4;                        // 0x47
  wchar_t ActiveTasks_CursorFocus;  // 0x48
  char unk5;                        // 0x4A
  char unk6;                        // 0x4B
  char unk7;                        // 0x4C
  char unk8;                        // 0x4D
  wchar_t Shortcuts_CursorFocus;    // 0x4E
  wchar_t Shortcuts_CursorMove1;    // 0x50
  wchar_t unk9;                     // 0x52
  wchar_t Shortcuts_CursorMove2;    // 0x54
  char dummy6[0x2];
  int book_id;                      // 0x58
  char am_type;                     // 0x5C
  char unk10;                       // 0x5D
  wchar_t unk11;                    // 0x5E
  wchar_t unk12;                    // 0x60
}ActivityMenuBook; // size 0x64(100)
*/

#endif
