#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

#include "..\..\classes\IMusicServer.h"

typedef struct _X_IMAGEID
{
  char dummy[0x20];
  IMAGEID ImageID;
} X_IMAGEID;

typedef struct _X_TEXTID
{
  TEXTID Artist;        // 0x0   //0x16C
  TEXTID Title;         // 0x4   //0x170
  TEXTID Album;         // 0x8   //0x174
  TEXTID ElapsedTime;   // 0xC   //0x178
  TEXTID RemainingTime; // 0x10  //0x17C
  TEXTID TotalTime;     // 0x14  //0x180
  TEXTID C_TrackID;     // 0x18  //0x184
  TEXTID TotalTrackID;  // 0x1C  //0x188
} X_TEXTID;

typedef struct DISP_OBJ_NOWPLAYING
{
#if defined(DB3200)
  char dummy1[0x168];
#elif defined(DB3210)
  char dummy1[0x16C];
#endif
  X_TEXTID TextID;       // 0x16C
  char dummy2[0x160];    // 0x18C
  X_IMAGEID *Artist;     // 0x2EC
  X_IMAGEID *Album;      // 0x2F0
  X_IMAGEID *Walkman;    // 0x2F4
  X_IMAGEID *Wheel_Up;   // 0x2F8
  X_IMAGEID *Wheel_Down; // 0x2FC
  X_IMAGEID *Shuffle;    // 0x300
  X_IMAGEID *VizFrame;   // 0x304
  X_IMAGEID *State;      // 0x308
  X_IMAGEID *Eq;         // 0x30C
  X_IMAGEID *Track;      // 0x310
  X_IMAGEID *Loop;       // 0x314
  X_IMAGEID *Wheel_Prev; // 0x318
  X_IMAGEID *Wheel_Next; // 0x31C
  X_IMAGEID *Wheel_Stop; // 0x320
  X_IMAGEID *Wheel_BG;   // 0x324
  void *unk_0x328;       // 0x328
} DISP_OBJ_NOWPLAYING;

typedef struct _PLAYING_TIME_DATA
{
  char dummy[0x24];
  int Hours;
  int Minutes;
  int Seconds;
  int MilliSeconds;
} PLAYING_TIME_DATA;

typedef struct _NEW_TRACK_DATA
{
  char dummy_0x0[0x28];          // 0
  int Track_ID;                  // 0x28
  TMusicServer_Time ElapsedTime; // 0x2C
  char dummy_0x30[0x24];         // 0x38
  TMusicServer_Time FullTime;    // 0x5C
} NEW_TRACK_DATA;

#ifdef CLEARAUDIO
typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer *pMusicServer;    // 0x18
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
  bool Loop;                     // 0x41
  bool Random;                   // 0x42
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
} MusicApplication_Book;
#else
typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer *pMusicServer;    // 0x18
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
  bool Loop;                     // 0x41
  bool Random;                   // 0x42
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
