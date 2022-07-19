#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

#include "..\..\classes\IMusicServer.h"

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

typedef struct _X_IMAGEID
{
  char dummy[0x20];
  IMAGEID ImageID;
} X_IMAGEID;

typedef struct _X_TEXTID
{
  TEXTID Artist; // 0x120
  TEXTID Title;  // 0x124
  TEXTID Album;  // 0x128
} X_TEXTID;

typedef struct DISP_OBJ_NOWPLAYING
{
  char dummy1[0x120];    // 0
  X_TEXTID TextID;       // 0x120
  char dummy2[0x140];    // 0x12C
  X_IMAGEID *Artist;     // 0x26C
  X_IMAGEID *Album;      // 0x270
  X_IMAGEID *Walkman;    // 0x274
  X_IMAGEID *Wheel_Up;   // 0x278
  X_IMAGEID *Wheel_Down; // 0x27C
  X_IMAGEID *Shuffle;    // 0x280
  X_IMAGEID *VizFrame;   // 0x284
  X_IMAGEID *State;      // 0x288
  X_IMAGEID *Eq;         // 0x28C
  X_IMAGEID *Track;      // 0x290
  X_IMAGEID *Loop;       // 0x294
  X_IMAGEID *Wheel_Prev; // 0x298
  X_IMAGEID *Wheel_Next; // 0x29C
  X_IMAGEID *Wheel_Stop; // 0x2A0
  X_IMAGEID *Wheel_BG;   // 0x2A4
} DISP_OBJ_NOWPLAYING;

#ifdef CLEARAUDIO
typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer *pMusicServer;    // 0x18
  GUI *Gui_NowPlaying;           // 0x1C
  uint32_t subscriptionHandle;   // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  GUI *Gui_submenu;              // 0x28
  uint32_t unk_0x2C;             // 0x2C
  GUI *FMTransmitter;            // 0x30
  uint16_t current_track_id;     // 0x34
  uint16_t selected_track_id;    // 0x36
  uint16_t tracks_count;         // 0x38
  uint8_t PlayerState;           // 0x3A
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
  IMusicServer *pMusicServer;    // 0x18
  GUI *Gui_NowPlaying;           // 0x1C
  uint32_t subscriptionHandle;   // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  GUI *Gui_submenu;              // 0x28
  uint32_t unk_0x2C;             // 0x2C
  uint32_t unk_0x30;             // 0x30
  uint16_t current_track_id;     // 0x34
  uint16_t selected_track_id;    // 0x36
  uint16_t tracks_count;         // 0x38
  uint8_t PlayerState;           // 0x3A
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
  int EqBand_63;                 // 0x70
  int EqBand_250;                // 0x74
  int EqBand_1000;               // 0x78
  int EqBand_4000;               // 0x7C
  int EqBand_16000;              // 0x80
  uint32_t unk_0x84;             // 0x84
  uint32_t unk_0x88;             // 0x88
  uint8_t Callpage;              // 0x8C Callpage?
} MusicApplication_Book;
#endif

#endif
