#ifndef ObExSendBook_H
#define ObExSendBook_H

// DB2010
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

#endif
