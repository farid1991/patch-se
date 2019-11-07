#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

#include "..\\include\classes\IMusicServer_Manager.h"
#include "..\\include\types\MusicServer_types.h"

#define XDISP_OBJ 0x4BA30607

typedef struct _X_IMAGEID
{
  char dummy[0x20];
  IMAGEID ImageID;
}X_IMAGEID;

typedef struct _X_TEXTID
{
  TEXTID Artist;        //0x0   //0x16C
  TEXTID Title;         //0x4   //0x170
  TEXTID Album;         //0x8   //0x174
  TEXTID ElapsedTime;   //0xC   //0x178
  TEXTID RemainingTime; //0x10  //0x17C
  TEXTID TotalTime;     //0x14  //0x180
  TEXTID C_TrackID;     //0x18  //0x184
  TEXTID TotalTrackID;  //0x1C  //0x188
}X_TEXTID;

typedef struct _MUSIC_GUI_NOWPLAYING_DISP_OBJ : DISP_OBJ
{
  X_TEXTID TextID;            //0x16C
  void* unk_0x18C;            //0x18C
  void* unk_0x190;            //0x190
  void* unk_0x194;            //0x194
  void* unk_0x198;            //0x198
  void* unk_0x19C;            //0x19C
  void* unk_0x1A0;            //0x1A0
  void* unk_0x1A4;            //0x1A4
  void* unk_0x1A8;            //0x1A8
  void* unk_0x1AC;            //0x1AC
  void* unk_0x1B0;            //0x1B0
  void* unk_0x1B4;            //0x1B4
  void* unk_0x1B8;            //0x1B8
  void* unk_0x1BC;            //0x1BC    
  void* unk_0x1C0;            //0x1C0      
  char dummy[0x128];          //0x1C4
  X_IMAGEID *Artist;          //0x2EC //0590
  X_IMAGEID *Album;           //0x2F0 //058F
  X_IMAGEID *Walkman;         //0x2F4 //0048
  X_IMAGEID *Wheel_Up;        //0x2F8 //04E5
  X_IMAGEID *Wheel_Down;      //0x2FC //04D4
  X_IMAGEID *Shuffle;         //0x300
  void *unk_0x304;            //0x304
  X_IMAGEID *State;           //0x308
  X_IMAGEID *Eq;              //0x30C
  X_IMAGEID *Track;           //0x310 //05E1
  X_IMAGEID *Loop;            //0x314
  X_IMAGEID *Wheel_Prev;      //0x318 //04DB
  X_IMAGEID *Wheel_Next;      //0x31C //04D7
  X_IMAGEID *Wheel_Stop;      //0x320 //04E2
  X_IMAGEID *Wheel_BG;        //0x324 //04D2
  void *unk_0x328;            //0x328
}MUSIC_GUI_NOWPLAYING_DISP_OBJ;

//C510 MusicApp_DispObj size 0x328
//G502 MusicApp_DispObj size 0x28c

typedef struct
{
  char dummy[0x24];
  TMusicServer_Time ElapsedTime;
}UI_MEDIAPLAYER_AUDIO_PLAYING_TIME;

typedef struct _UI_MEDIAPLAYER_NEW_TRACK_DATA
{
  char dummy_0x0[0x28];           //0
  int track_id;                   //0x28
  TMusicServer_Time ElapsedTime;  //0x2C
  char dummy_0x1[0x24];           //0x30
  TMusicServer_Time FullTime;     //0x54
}UI_MEDIAPLAYER_NEW_TRACK_DATA;

typedef struct
{
  TBool Loop;
  TBool Random;
} MusicApp_PlayMode;

typedef struct _MusicApp_Settings
{
  TBool unk_0;
  TBool unk_1;
  TBool unk_2;
  TBool StereoWidening ;
} MusicApp_Settings;

typedef struct
{
  FUint8 Band_63;
  FUint8 Band_250;
  FUint8 Band_1000;
  FUint8 Band_4000;
  FUint8 Band_16000;
} Equalizer_Band;

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer *pMusicServer;               // 0x18
  FUint32 subscriptionHandle;               // 0x1C
  GUI *Gui_NowPlaying;                      // 0x20
  GUI *Gui_PlayQueue;                       // 0x24
  int dummy_0x28;                           // 0x28
  GUI *Gui_submenu;                         // 0x2C
  int dummy_0x30;                           // 0x30
  int dummy_0x34;                           // 0x34
  wchar_t current_track_id;                 // 0x38
  wchar_t selected_track_id;                // 0x3A
  wchar_t tracks_count;                     // 0x3C
  char state;                               // 0x3E
  char state_2;                             // 0x3F
  char unk_0x40;                            // 0x40
  bool loop;                                // 0x41
  bool shuffle;                             // 0x42
  char unk_0x43;                            // 0x43
  TMusicServer_Time ElapsedTime;            // 0x44
  char AreTracksInQueue;                    // 0x50 ???????
  char dummy_0x51;                          // 0x51
  bool DisplayOrientation;                  // 0x52
  char dummy_0x53;                          // 0x53
  SUB_EXECUTE *sub_exec;                    // 0x54
  char dummy_0x5[0x4];                      // 0x58
  TEXTID ErrorText;                         // 0x5C
  char dummy_0x6[0x13];                     // 0x60
  char EQ_Preset;                           // 0x73
  int Level_ClearBass1;                     // 0x74
  int Level_ClearBass2;                     // 0x78
  int Level_400Hz;                          // 0x7C
  int Level_1kHz;                           // 0x80
  int Level_2_5kHz;                         // 0x84
  int Level_6_3kHz;                         // 0x88
  int Level_16kHz;                          // 0x8C
  char unk_0x90;                            // 0x90
  char unk_0x91[0x7];                       // 0x91
  char unk_0x98;                            // 0x98
}MusicApplication_Book;

#else
typedef struct GUI Music_Gui;

typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer* pMusicServer; // 0x18
  Music_Gui *Gui_NowPlaying;  // 0x1C
  Music_Gui *Gui_PlayQueue;   // 0x20
  int unk_0x24;               // 0x24
  Music_Gui* Gui_submenu;     // 0x28
  int unk_0x2C;               // 0x2C
  Uint16_t current_track_id;  // 0x30
  Uint16_t selected_track_id; // 0x32
  Uint16_t tracks_count;      // 0x34
  char state;                 // 0x36
  char unk_0x37;              // 0x37
  char play_pause;            // 0x38 TMusicServer_State
  char unk_0x39;              // 0x39
  char cause;                 // 0x3A TMusicServer_Cause
  bool loop;                  // 0x3B TMusicServer_Settings
  bool random;                // 0x3C TMusicServer_Settings
  char unk_0x3D;              // 0x3D
  char unk_0x3E;              // 0x3E
  char unk_0x3F;              // 0x3F
  TMusicServer_Time Time;     // 0x40
  char unk_0x4C;              // 0x4C
  char status;                // 0x4D TMusicServer_Status
  bool DisplayOrientation;    // 0x4E
  char unk_0x4F;              // 0x4F
  SUB_EXECUTE* sub_exec;      // 0x50
  char unk_0x54;              // 0x54
  char unk_0x55;              // 0x55
  char unk_0x56;              // 0x56
  char unk_0x57;              // 0x57
  TEXTID ErrorText;           // 0x58 TMusicServer_ErrorCode
  char unk_0x5C;              // 0x5C
  char unk_0x5D;              // 0x5C
  u16 unk_0x5E;               // 0x5E
  char unk_0x60;              // 0x60
  char unk_0x61;              // 0x61
  u16 timerID;                // 0x62
  u16 unk_0x64;               // 0x64
  char EQ_Preset;             // 0x66
  char unk_0x67;              // 0x67
  void *pointer_0x68;         // 0x68
  void (*Func)(void*, void*); // 0x6C
  void *pointer_0x70;         // 0x70
  char unk_0x74;              // 0x74
  bool unk_0x75;              // 0x75
  char unk_0x76;              // 0x76
  char unk_0x77;              // 0x77
  MusicApp_Settings *Settings;// 0x78
  int unk_0x7C;               // 0x7C
  char unk_0x80[0xC];         // 0x80
  bool unk_0x8C;              // 0x8C
}MusicApplication_Book;

#endif

#endif
