#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

typedef struct
{
  uint32_t hours;
  uint32_t minutes;
  uint32_t seconds;
} TMusicServer_Time;

typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;            // 0x18
  GUI *Gui_NowPlaying;           // 0x1C
  GUI *Gui_PlayQueue;            // 0x20
  uint32_t unk_0x24;             // 0x24
  GUI *Gui_submenu;              // 0x28
  uint32_t unk_0x2C;             // 0x2C
  uint16_t current_track_id;     // 0x30
  uint16_t selected_track_id;    // 0x32
  uint16_t tracks_count;         // 0x34
  uint8_t state;                 // 0x36
  uint8_t unk_0x37;              // 0x37
  uint8_t PlayerState;           // 0x38 TMusicServer_State
  uint8_t unk_0x39;              // 0x39
  uint8_t PlayerCause;           // 0x3A TMusicServer_Cause
  bool Loop;                     // 0x3B
  bool Random;                   // 0x3C
  uint8_t unk_0x3D;              // 0x3D
  uint8_t unk_0x3E;              // 0x3E
  uint8_t unk_0x3F;              // 0x3F
  TMusicServer_Time ElapsedTime; // 0x40
  uint8_t unk_0x4C;              // 0x4C
  uint8_t status;                // 0x4D TMusicServer_Status
  uint8_t DisplayOrientation;    // 0x4E
  uint8_t unk_0x4F;              // 0x4F
  SUB_EXECUTE *CurrentTrack;     // 0x50
  uint8_t unk_0x54;              // 0x54
  uint8_t unk_0x55;              // 0x55
  uint8_t unk_0x56;              // 0x56
  uint8_t unk_0x57;              // 0x57
  TEXTID ErrorText;              // 0x58 TMusicServer_ErrorCode
  uint8_t unk_0x5C;              // 0x5C
  uint8_t unk_0x5D;              // 0x5C
  uint16_t unk_0x5E;             // 0x5E
  uint8_t unk_0x60;              // 0x60
  uint8_t unk_0x61;              // 0x61
  uint16_t timerID;              // 0x62
  uint16_t unk_0x64;             // 0x64
  uint8_t EqPreset;              // 0x66
  uint8_t unk_0x67;              // 0x67
  void *unk_0x68;                // 0x68
  void *unk_0x6C;                // 0x6C
  void *unk_0x70;                // 0x70
  uint8_t unk_0x74;              // 0x74
  uint8_t Callpage;              // 0x75 Callpage?
  uint8_t unk_0x76;              // 0x76
  uint8_t unk_0x77;              // 0x77
  uint8_t unk_0x78;              // 0x78
  uint8_t unk_0x79;              // 0x79
  uint8_t unk_0x7A;              // 0x7A
  bool StereoWidening;           // 0x7B
  uint32_t unk_0x7C;             // 0x7C
  uint32_t unk_0x80;             // 0x80
  uint32_t unk_0x84;             // 0x84
  uint32_t unk_0x88;             // 0x88
} MusicApplication_Book;

#endif
