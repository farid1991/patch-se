#ifndef ObExSendBook_H
#define ObExSendBook_H

#if defined(DB2010)
typedef struct ObExSendBook : BOOK
{
  GUI *ProgressBar;        // 0x18
  char dummy1[0x18];       // 0x1C
  wchar_t file_name[0xFC]; // 0x34
  wchar_t file_path[0xFC]; // 0x22C
  char dummy2[0x10];       // 0x424
  int file_sent;           // 0x434
  int file_size;           // 0x438
  u16 timer_id;            // 0x43C
  u16 unk_3C;              // 0x43E
  int current_percent;     // 0x440
  IMAGEID Receiver_ICN;    // 0x444
  wchar_t short_name[0xE]; // 0x446
} ObExSendBook;

#elif defined(DB3200) || defined(DB3210)
typedef struct ObExSendBook : BOOK
{
  GUI *ProgressBar;        // 0x18
 char dummy1[0x1C];        // 0x1C
    wchar_t file_name[0xFF];  // 0x38
    wchar_t file_path[0xFF];  // 0x236
    char dummy2[0x10];        // 0x434
    int file_sent;            // 0x444
    int file_size;            // 0x448
    char dummy3[0x8];         // 0x44C
    IMAGEID Receiver_ICN;     // 0x454
    wchar_t short_name[0x1F]; // 0x456
} ObExSendBook;
#endif

#endif
