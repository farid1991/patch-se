#ifndef ObExReceiveBook_H
#define ObExReceiveBook_H

// DB2010
typedef struct OBEX_REFRESH_RECEIVE_PROGRESS_DATA
{
  char dummy[0x28];
  int received_bytes;
} OBEX_REFRESH_RECEIVE_PROGRESS_EVENT;

#if defined(DB2010)
typedef struct ObExReceiveBook : BOOK
{
  void *unk_18;              // 0x18
  GUI *ProgressBar;          // 0x1C
  int unk_24;                // 0x20
  wchar_t file_name[0xFC];   // 0x24
  wchar_t file_path[0xFC];   // 0x21C
  wchar_t sender_name[0xFC]; // 0x414
  int file_size;             // 0x60C
  int free_memory;           // 0x610
  int unk_614;               // 0x614
  int unk_618;               // 0x618
  int percentage;            // 0x61C
  u16 unk_620;               // 0x620
  wchar_t short_name[0xE];   // 0x622
  char unk_63E;              // 0x63E
  char unk_63F;              // 0x63F
} ObExReceiveBook;

#elif defined(DB3150v1)
typedef struct ObExReceiveBook : BOOK
{
  GUI *ProgressBar; // 0x18
} ObExReceiveBook;

#elif defined(DB3150v2) || defined(DB3200) || defined(DB3210)
typedef struct ObExReceiveBook : BOOK
{
  GUI *ProgressBar;        // 0x18
  void *unk_1C;            // 0x1C
  void *unk_20;            // 0x20
  wchar_t short_name[0xE]; // 0x24
  int file_size;           // 0x40
} ObExReceiveBook;
#endif

#endif
