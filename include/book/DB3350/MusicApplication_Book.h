#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

#include "..\..\classes\IMusicServer.h"

typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer *pMusicServer;  // 0x18
  uint32_t subscriptionHandle; // 0x1C
  GUI *Gui_NowPlaying;         // 0x20
  uint32_t unk_0x24;           // 0x24
  GUI *Gui_submenu;            // 0x28
  uint32_t unk_0x2C;           // 0x2C
  uint32_t unk_0x30;           // 0x30
  uint16_t current_track_id;   // 0x34
  uint16_t selected_track_id;  // 0x36
  uint8_t unk_0x38;            // 0x38
  uint8_t unk_0x39;            // 0x39
  uint16_t unk_0x3A;           // 0x3A
  uint8_t State;               // 0x3C TMusicServer_State
  uint8_t unk_0x3D;            // 0x3D
  uint8_t PlayerState;         // 0x3C TMusicServer_State
  uint8_t unk_0x3F;            // 0x3F
  uint32_t unk_0x40;           // 0x40
  uint8_t unk_0x44;            // 0x44
  uint8_t unk_0x45;            // 0x45
  uint8_t unk_0x46;            // 0x46
  uint8_t unk_0x47;            // 0x47
  void *unk_0x48;              // 0x48
  uint32_t unk_0x4C;           // 0x4C
  uint8_t unk_0x50;            // 0x50
  uint8_t unk_0x51;            // 0x51
  uint8_t unk_0x52;            // 0x52
  uint8_t unk_0x53;            // 0x53
  SUB_EXECUTE *CurrentTrack;   // 0x54
  TEXTID ErrorText;            // 0x58
  uint32_t unk_0x5C;           // 0x5C
  uint32_t unk_0x60;           // 0x60
  uint32_t unk_0x64;           // 0x64
  uint16_t unk_0x68;           // 0x68
  uint16_t unk_0x6A;           // 0x6A
  uint8_t unk_0x6C;            // 0x6C
  uint8_t unk_0x6D;            // 0x6D
  uint8_t unk_0x6E;            // 0x6E
  uint8_t unk_0x6F;            // 0x6F
  uint32_t unk_0x70;           // 0x70
  uint32_t unk_0x74;           // 0x74
  uint32_t unk_0x78;           // 0x78
  uint32_t unk_0x7C;           // 0x7C
  uint32_t unk_0x80;           // 0x80
  uint32_t unk_0x84;           // 0x84
  uint32_t unk_0x88;           // 0x88
#ifdef CLEARAUDIO
  uint32_t unk_0x8C;           // 0x8C
  uint32_t unk_0x90;           // 0x90
#endif
  uint8_t Callpage;            // 0x8C & 0x94 Callpage?
} MusicApplication_Book;

#endif
