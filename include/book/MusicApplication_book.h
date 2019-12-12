#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

#include "..\\..\\include\classes\IMusicServer_Manager.h"
#include "..\\..\\include\types\MusicServer_types.h"

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
  char dummy_0x0[0x28];           //0
  int Track_ID;                   //0x28
  TMusicServer_Time ElapsedTime;  //0x2C
  char dummy_0x30[0x24];          //0x38
  TMusicServer_Time FullTime;     //0x5C
} NEW_TRACK_DATA;

typedef struct
{
  bool Loop;
  bool Shuffle;
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

typedef struct _X_UNKNOWN1
{
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
}X_UNKNOWN1;

typedef struct _X_UNKNOWN2
{
  char unk_0x1C4;        //0x0   //0x1C4
  char unk_0x1C5;        //0x1   //0x1C5
  char unk_0x1C6;        //0x2   //0x1C6
  char unk_0x1C7;        //0x3   //0x1C7
  char unk_0x1C8;        //0x4   //0x1C8
  char unk_0x1C9;        //0x5   //0x1C9
  char unk_0x1CA;        //0x6   //0x1CA
  char unk_0x1CB;        //0x7   //0x1CB
  int unk_0x1CC;         //0x8   //0x1CC
  int unk_0x1D0;         //0xC   //0x1D0
  int unk_0x1D4;        //0x10   //0x1D4
  int unk_0x1D8;        //0x14   //0x1D8
  int unk_0x1DC;        //0x18   //0x1DC
  int unk_0x1E0;        //0x1C   //0x1E0
  int unk_0x1E4;        //0x20   //0x1E4
  int unk_0x1E8;        //0x24   //0x1E8
  int unk_0x1EC;        //0x28   //0x1EC
  int unk_0x1F0;        //0x2C   //0x1F0
  int unk_0x1F4;        //0x30   //0x1F4
  int unk_0x1F8;        //0x34   //0x1F8
  int unk_0x1FC;        //0x38   //0x1FC
  int unk_0x200;        //0x3C   //0x200 //-1 ???
}X_UNKNOWN2;

typedef struct _X_UNKNOWN3
{
  char unk_0x204[0xF];    //0x0   //0x204
  char unk_0x213;         //0xF   //0x213
  wchar_t unk_0x214;      //0x10  //0x214
  wchar_t unk_0x216;      //0x12  //0x216
  wchar_t unk_0x218;      //0x14  //0x218
  wchar_t unk_0x21A;      //0x16  //0x21A
  int unk_0x21C;          //0x18  //0x21C
  int unk_0x220;          //0x1C  //0x220
}X_UNKNOWN3;

//X_UNKNOWN1 unknown1;        //0x18C-0x1C0      
//X_UNKNOWN2 unknown2;        //0x1C4-0x200
//X_UNKNOWN3 unknown3;        //0x204-0x220

typedef struct _DISP_OBJ_NOWPLAYING : DISP_OBJ
{
  X_TEXTID TextID;            //0x16C-0x188  
  char dummy[0x160];          //0x18C-0x2E8
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
} DISP_OBJ_NOWPLAYING;

//C510 DISP_OBJ_NOWPLAYING size 0x328
//G502 DISP_OBJ_NOWPLAYING size 0x28C

typedef struct _DISP_OBJ_PLAYQUEUE : DISP_OBJ
{
  DISP_OBJ *unk_0x0;
  DISP_OBJ *unk_0x4;
  wchar_t unk_0x8;
  wchar_t unk_0xA;
  wchar_t unk_0xC;
  wchar_t unk_0xE;
  char unk_0x10;
  char unk_0x11;
  char unk_0x12;
  char unk_0x13;
} DISP_OBJ_PLAYQUEUE;

//C510 DISP_OBJ_PLAYQUEUE size 0x180
//G502 DISP_OBJ_PLAYQUEUE size 

typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer *pMusicServer;               // 0x18
  FUint32 subscriptionHandle;               // 0x1C
  GUI *Gui_NowPlaying;                      // 0x20
  GUI *Gui_PlayQueue;                       // 0x24
  int dummy_0x28;                           // 0x28
  GUI *Gui_submenu;                         // 0x2C
  int dummy_0x30;                           // 0x30
  void *unk_0x34;                           // 0x34
  u16 current_track_id;                     // 0x38
  u16 selected_track_id;                    // 0x3A
  u16 tracks_count;                         // 0x3C
  char state;                               // 0x3E
  char state_2;                             // 0x3F
  char unk_0x40;                            // 0x40
  bool Loop;                                // 0x41
  bool Shuffle;                             // 0x42
  char unk_0x43;                            // 0x43
  TMusicServer_Time ElapsedTime;            // 0x44
  char AreTracksInQueue;                    // 0x50 ???????
  char dummy_0x51;                          // 0x51
  bool DisplayOrientation;                  // 0x52
  char unk_0x53;                            // 0x53
  SUB_EXECUTE *CurrentTrack;                // 0x54
  int unk_0x58;                             // 0x58
  TEXTID ErrorText;                         // 0x5C
  char unk_0x60[0x13];                      // 0x60
  char EQ_Preset;                           // 0x73
  int Eq_Band1;                             // 0x74
  int Eq_Band2;                             // 0x78
  int Eq_Band3;                             // 0x7C
  int Eq_Band4;                             // 0x80
  int Eq_Band5;                             // 0x84
  int Level_6_3kHz;                         // 0x88
  int Level_16kHz;                          // 0x8C
  char unk_0x90;                            // 0x90
  char unk_0x91;                            // 0x91
  char unk_0x92;                            // 0x92
  char unk_0x93;                            // 0x93
  void* SettingsBook;                       // 0x94
  int unk_0x98;                             // 0x98
}MusicApplication_Book;
/*
int Level_ClearBass1;                     // 0x74
  int Level_ClearBass2;                     // 0x78
  int Level_400Hz;                          // 0x7C
  int Level_1kHz;                           // 0x80
  int Level_2_5kHz;                         // 0x84
  int Level_6_3kHz;                         // 0x88
  int Level_16kHz;                          // 0x8C
*/
#else

typedef struct _MusicApplication_Book : BOOK
{
  IMusicServer* pMusicServer; // 0x18
  GUI *Gui_NowPlaying;        // 0x1C
  GUI *Gui_PlayQueue;         // 0x20
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
  //bool loop;                  // 0x3B TMusicServer_Settings
  //bool random;                // 0x3C TMusicServer_Settings
  MusicApp_PlayMode PlayMode; //
  char unk_0x3D;              // 0x3D
  char unk_0x3E;              // 0x3E
  char unk_0x3F;              // 0x3F
  TMusicServer_Time Time;     // 0x40
  char unk_0x4C;              // 0x4C
  char status;                // 0x4D TMusicServer_Status
  bool DisplayOrientation;    // 0x4E
  char unk_0x4F;              // 0x4F
  SUB_EXECUTE *CurrentTrack;  // 0x50
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
