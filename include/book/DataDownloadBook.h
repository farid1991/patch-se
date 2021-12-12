#ifndef _DataDownloadBook_H_
#define _DataDownloadBook_H_

typedef struct _DataDownloadBook : BOOK
{
  void *unk_0x18; // 0x18
  FILEITEM *fi;   // 0x1C
  void *unk_0x20; // 0x20
  GUI *gui;       // 0x24
} DataDownloadBook;

#endif
