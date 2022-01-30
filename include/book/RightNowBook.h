#ifndef RightNowBook_h
#define RightNowBook_h

#if defined(DB2010)
//0x2AA0
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

#endif

#endif
