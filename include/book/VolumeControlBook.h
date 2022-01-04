#ifndef _VOLUMECONTROL_BOOK_H_
#define _VOLUMECONTROL_BOOK_H_

typedef struct _VolumeControlBook : BOOK
{
  GUI *VC_GUI; 
  int unk_0x1C;
  int unk_0x20;
  void *unk_0x24;
  void *unk_0x28;
#if defined(DB3200) || defined(DB3210)
  int unk_0x2C;
#endif
  int level;
} VolumeControlBook;

#endif
