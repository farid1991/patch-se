#ifndef ObExSendBook_H
#define ObExSendBook_H

typedef struct OBEX_REFRESH_SEND_PROGRESS_DATA
{
  char dummy[0x24];
  int sent_bytes;
} OBEX_REFRESH_SEND_PROGRESS_DATA;

#if defined(DB2010)
typedef struct ObExSendBook : BOOK
{
  GUI *ProgressBar;        // 0x18
  void *unk_1C;            // 0x1C Interface
  char unk_20[0x14];       // 0x20
  BT_FILE_2010 bt_file;    // 0x34
  char unk_424[0x10];      // 0x424
  int file_sent;           // 0x434
  int file_size;           // 0x438
  u16 timer_id;            // 0x43C
  u16 unk_43E;             // 0x43E
  int current_percent;     // 0x440
  IMAGEID Receiver_ICN;    // 0x444
  wchar_t short_name[0xE]; // 0x446
} ObExSendBook;

#elif defined(DB3150v1)
typedef struct ObExSendBook : BOOK
{
  GUI *ProgressBar; // 0x18
} ObExSendBook;

#elif defined(DB3150v2) || defined(DB3200) || defined(DB3210)
typedef struct ObExSendBook : BOOK
{
  GUI *ProgressBar;         // 0x18
  char unk_1C[0x1C];        // 0x1C
  BT_FILE_2020 bt_file;     // 0x38
  char unk_434[0x10];       // 0x434
  int file_sent;            // 0x444
  int file_size;            // 0x448
  char unk_44C[0x8];        // 0x44C
  IMAGEID Receiver_ICN;     // 0x454
  wchar_t short_name[0x1F]; // 0x456
} ObExSendBook;
#endif

#endif
