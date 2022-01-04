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
  uint32_t subscriptionHandle;   // 0x1C
  GUI *Gui_NowPlaying;           // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  uint32_t unk_0x28;             // 0x28
  GUI *Gui_submenu;              // 0x2C
  uint32_t unk_0x30;             // 0x30
  void *unk_0x34;                // 0x34
  uint16_t current_track_id;     // 0x38
  uint16_t selected_track_id;    // 0x3A
  uint16_t tracks_count;         // 0x3C
  uint8_t PlayerState;           // 0x3E
  uint8_t state_2;               // 0x3F
  uint8_t unk_0x40;              // 0x40
  MusicApp_PlayMode PlayMode;    // 0x41
  uint8_t unk_0x43;              // 0x43
  TMusicServer_Time ElapsedTime; // 0x44
  bool AreTracksInQueue;         // 0x50
  uint8_t unk_0x51;              // 0x51
  bool DisplayOrientation;       // 0x52
  uint8_t unk_0x53;              // 0x53
  SUB_EXECUTE *CurrentTrack;     // 0x54
  uint32_t unk_0x58;             // 0x58
  TEXTID ErrorText;              // 0x5C
  uint8_t unk_0x60[0x13];        // 0x60
  uint8_t EqPreset;              // 0x73
  int EqBand_ClearBass1;         // 0x74
  int EqBand_ClearBass2;         // 0x78
  int EqBand_400;                // 0x7C
  int EqBand_1000;               // 0x80
  int EqBand_2500;               // 0x84
  int EqBand_6300;               // 0x88
  int EqBand_16000;              // 0x8C
  uint8_t unk_0x90;              // 0x90
  uint8_t unk_0x91;              // 0x91
  uint8_t unk_0x92;              // 0x92
  uint8_t unk_0x93;              // 0x93
  uint32_t unk_0x94;             // 0x94
  uint8_t Callpage;              // 0x98 Callpage?
#else
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;            // 0x18
  uint32_t subscriptionHandle;   // 0x1C
  GUI *Gui_NowPlaying;           // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  uint32_t unk_0x28;             // 0x28
  GUI *Gui_submenu;              // 0x2C
  uint32_t unk_0x30;             // 0x30
  void *unk_0x34;                // 0x34
  uint16_t current_track_id;     // 0x38
  uint16_t selected_track_id;    // 0x3A
  uint16_t tracks_count;         // 0x3C
  uint8_t PlayerState;           // 0x3E
  uint8_t state_2;               // 0x3F
  uint8_t unk_0x40;              // 0x40
  MusicApp_PlayMode PlayMode;    // 0x41
  uint8_t unk_0x43;              // 0x43
  TMusicServer_Time ElapsedTime; // 0x44
  bool AreTracksInQueue;         // 0x50
  uint8_t unk_0x51;              // 0x51
  bool DisplayOrientation;       // 0x52
  uint8_t unk_0x53;              // 0x53
  SUB_EXECUTE *CurrentTrack;     // 0x54
  uint32_t unk_0x58;             // 0x58
  TEXTID ErrorText;              // 0x5C
  uint8_t unk_0x60[0x13];        // 0x60
  uint8_t EqPreset;              // 0x73
  int EqBand_63;                 // 0x74
  int EqBand_250;                // 0x78
  int EqBand_1000;               // 0x7C
  int EqBand_4000;               // 0x80
  int EqBand_16000;              // 0x84
  uint32_t unk_0x88;             // 0x88
  uint32_t unk_0x8C;             // 0x8C
  uint8_t Callpage;              // 0x90 Callpage?
} MusicApplication_Book;
#endif

#endif
