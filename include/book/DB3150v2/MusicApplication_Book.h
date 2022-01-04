#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

typedef struct
{
  uint32_t hours;
  uint32_t minutes;
  uint32_t seconds;
} TMusicServer_Time;

#ifdef CLEARAUDIO
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;            // 0x18
  GUI *Gui_NowPlaying;           // 0x1C
  uint32_t unk_0x20;             // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  GUI *Gui_submenu;              // 0x28
  uint32_t unk_0x2C;             // 0x2C
  GUI *FMTransmitter;            // 0x30
  uint16_t current_track_id;     // 0x34
  uint16_t selected_track_id;    // 0x36
  uint16_t tracks_count;         // 0x38
  uint8_t state;                 // 0x3A
  uint8_t unk_0x3B;              // 0x3B
  uint8_t unk_0x3C;              // 0x3C
  uint8_t unk_0x3D;              // 0x3D
  bool Loop;                     // 0x3E
  bool Random;                   // 0x3F
  TMusicServer_Time ElapsedTime; // 0x40
  uint8_t unk_0x4C;              // 0x4C
  uint8_t unk_0x4D;              // 0x4D
  bool DisplayOrientation;       // 0x4E
  uint8_t unk_0x4F;              // 0x4F
  SUB_EXECUTE *CurrentTrack;     // 0x50
  uint32_t unk_0x54;             // 0x54
  TEXTID ErrorText;              // 0x58 TMusicServer_ErrorCode
  uint32_t unk_0x5C;             // 0x5C
  uint32_t unk_0x60;             // 0x60
  uint32_t unk_0x64;             // 0x64
  uint32_t unk_0x68;             // 0x68
  uint8_t unk_0x6C;              // 0x6C
  uint8_t unk_0x6D;              // 0x6D
  uint8_t unk_0x6E;              // 0x6E
  uint8_t EqPreset;              // 0x6F
  int EqBand_ClearBass1;         // 0x70
  int EqBand_ClearBass2;         // 0x74
  int EqBand_400;                // 0x78
  int EqBand_1000;               // 0x7C
  int EqBand_2500;               // 0x80
  int EqBand_6300;               // 0x84
  int EqBand_16000;              // 0x88
  void *unk_0x8C;                // 0x8C
  void *unk_0x90;                // 0x90
  uint8_t Callpage;              // 0x94 Callpage?
  uint8_t unk_0x95;              // 0x95
  uint8_t unk_0x96;              // 0x96
  uint8_t unk_0x97;              // 0x97
  void *unk_0x98;                // 0x98
  uint32_t unk_0x9C;             // 0x9C
  void *unk_0xA0;                // 0xA0
} MusicApplication_Book;
#else
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;         // 0x18
  GUI *Gui_NowPlaying;        // 0x1C
  uint32_t unk_0x20;          // 0x20
  GUI *Gui_PlayQueue;         // 0x24
  GUI *Gui_submenu;           // 0x28
  uint32_t unk_0x2C;          // 0x2C
  uint32_t unk_0x30;          // 0x30
  uint16_t current_track_id;  // 0x34
  uint16_t selected_track_id; // 0x36
  uint16_t tracks_count;      // 0x38
  uint8_t unk_0x3A;           // 0x3A
  uint8_t unk_0x3B;           // 0x3B
  uint32_t unk_0x3C;          // 0x3C
  uint32_t unk_0x40;          // 0x50
  uint32_t unk_0x44;          // 0x54
  uint32_t unk_0x48;          // 0x58
  uint32_t unk_0x4C;          // 0x4C
  uint32_t unk_0x50;          // 0x50
  uint32_t unk_0x54;          // 0x54
  uint32_t unk_0x58;          // 0x58
  uint32_t unk_0x5C;          // 0x5C
  uint32_t unk_0x60;          // 0x60
  uint32_t unk_0x64;          // 0x64
  uint32_t unk_0x68;          // 0x68
  uint32_t unk_0x6C;          // 0x6C
  uint32_t unk_0x70;          // 0x70
  uint32_t unk_0x74;          // 0x74
  uint32_t unk_0x78;          // 0x78
  uint32_t unk_0x7C;          // 0x7C
  uint32_t unk_0x80;          // 0x80
  uint32_t unk_0x84;          // 0x84
  uint32_t unk_0x88;          // 0x88
  uint8_t Callpage;           // 0x8C Callpage?
} MusicApplication_Book;
#endif

#endif
