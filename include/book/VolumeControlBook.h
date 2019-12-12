#ifndef _VOLUMECONTROL_BOOK_H_
#define _VOLUMECONTROL_BOOK_H_

typedef struct _DISP_OBJ_VOLUME : DISP_OBJ
{
  char unknown[0x64];   // 0x16C
} DISP_OBJ_VOLUME;  // Size = 0x1D0

typedef struct _VolumeControlBook : BOOK
{
  GUI* VC_GUI;        // 0x18
  char unknown1[4];   // 0x1C
  char unknown2[4];   // 0x20
  void *unknown3;     // 0x24
  void *unknown4;     // 0x28
  char unknown[4];    // 0x20
  int level;          // 0x30
} VolumeControlBook;

#endif
