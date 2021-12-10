#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

typedef struct
{
  Uint32_t hours;
  Uint32_t minutes;
  Uint32_t seconds;
} TMusicServer_Time;

typedef struct _PLAYING_TIME_DATA
{
  char dummy[0x24];
  TMusicServer_Time PlayingTime;
} PLAYING_TIME_DATA;

typedef struct _NEW_TRACK_DATA
{
  char dummy_0x0[0x28];          //0
  int Track_ID;                  //0x28
  TMusicServer_Time ElapsedTime; //0x2C
  char dummy_0x30[0x24];         //0x38
  TMusicServer_Time FullTime;    //0x5C
} NEW_TRACK_DATA;

typedef struct _MusicApp_PlayMode
{
  bool Loop;
  bool Shuffle;
} MusicApp_PlayMode;

typedef struct _MusicApp_Settings
{
  Uint8_t unk_0;
  Uint8_t unk_1;
  Uint8_t unk_2;
  bool StereoWidening;
} MusicApp_Settings;

typedef struct _Equalizer_Band
{
  Uint8_t Band_63;
  Uint8_t Band_250;
  Uint8_t Band_1000;
  Uint8_t Band_4000;
  Uint8_t Band_16000;
} Equalizer_Band;

#if defined(DB3150v1)
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;          // 0x18
  GUI *Gui_NowPlaying;         // 0x1C
  GUI *Gui_PlayQueue;          // 0x20
  int unk_0x24;                // 0x24
  GUI *Gui_submenu;            // 0x28
  int unk_0x2C;                // 0x2C
  Uint16_t current_track_id;   // 0x30
  Uint16_t selected_track_id;  // 0x32
  Uint16_t tracks_count;       // 0x34
  Uint8_t state;               // 0x36
  char unk_0x37;               // 0x37
  Uint8_t PlayerState;         // 0x38 TMusicServer_State
  char unk_0x39;               // 0x39
  Uint8_t cause;               // 0x3A TMusicServer_Cause
  MusicApp_PlayMode PlayMode;  // 0x3B
  char unk_0x3D;               // 0x3D
  char unk_0x3E;               // 0x3E
  char unk_0x3F;               // 0x3F
  TMusicServer_Time Time;      // 0x40
  char unk_0x4C;               // 0x4C
  Uint8_t status;              // 0x4D TMusicServer_Status
  Uint8_t DisplayOrientation;  // 0x4E
  char unk_0x4F;               // 0x4F
  SUB_EXECUTE *CurrentTrack;   // 0x50
  char unk_0x54;               // 0x54
  char unk_0x55;               // 0x55
  char unk_0x56;               // 0x56
  char unk_0x57;               // 0x57
  TEXTID ErrorText;            // 0x58 TMusicServer_ErrorCode
  char unk_0x5C;               // 0x5C
  char unk_0x5D;               // 0x5C
  Uint16_t unk_0x5E;           // 0x5E
  char unk_0x60;               // 0x60
  char unk_0x61;               // 0x61
  Uint16_t timerID;            // 0x62
  Uint16_t unk_0x64;           // 0x64
  Uint8_t EQ_Preset;           // 0x66
  char unk_0x67;               // 0x67
  void *unk_0x68;              // 0x68
  void *unk_0x6C;              // 0x6C
  void *unk_0x70;              // 0x70
  char unk_0x74;               // 0x74
  Uint8_t unk_0x75;            // 0x75
  char unk_0x76;               // 0x76
  char unk_0x77;               // 0x77
  MusicApp_Settings *Settings; // 0x78
  int unk_0x7C;                // 0x7C
  char unk_0x80[0xC];          // 0x80
  bool unk_0x8C;               // 0x8C
} MusicApplication_Book;

#elif defined(DB3150v2)
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer; // 0x18
} MusicApplication_Book;

#elif defined(DB3200) || defined(DB3210)
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;            // 0x18
  Uint32_t subscriptionHandle;   // 0x1C
  GUI *Gui_NowPlaying;           // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  int unk_0x28;                  // 0x28
  GUI *Gui_submenu;              // 0x2C
  int unk_0x30;                  // 0x30
  void *unk_0x34;                // 0x34
  Uint16_t current_track_id;     // 0x38
  Uint16_t selected_track_id;    // 0x3A
  Uint16_t tracks_count;         // 0x3C
  char state;                    // 0x3E
  char state_2;                  // 0x3F
  char unk_0x40;                 // 0x40
  MusicApp_PlayMode PlayMode;    // 0x41
  char unk_0x43;                 // 0x43
  TMusicServer_Time ElapsedTime; // 0x44
  char AreTracksInQueue;         // 0x50
  char unk_0x51;                 // 0x51
  bool DisplayOrientation;       // 0x52
  char unk_0x53;                 // 0x53
  SUB_EXECUTE *CurrentTrack;     // 0x54
  int unk_0x58;                  // 0x58
  TEXTID ErrorText;              // 0x5C
  char unk_0x60[0x13];           // 0x60
  Uint8_t EQ_Preset;             // 0x73
  Uint32_t Eq_Band1;             // 0x74
  Uint32_t Eq_Band2;             // 0x78
  Uint32_t Eq_Band3;             // 0x7C
  Uint32_t Eq_Band4;             // 0x80
  Uint32_t Eq_Band5;             // 0x84
  Uint32_t Level_6_3kHz;         // 0x88
  Uint32_t Level_16kHz;          // 0x8C
  char unk_0x90;                 // 0x90
  char unk_0x91;                 // 0x91
  char unk_0x92;                 // 0x92
  char unk_0x93;                 // 0x93
  void *SettingsBook;            // 0x94
  int unk_0x98;                  // 0x98
} MusicApplication_Book;

#elif defined(DB3350)
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;            // 0x18
  int unk_0x1C;                  // 0x1C
  GUI *Gui_NowPlaying;           // 0x20
  GUI *Gui_PlayQueue;            // 0x24
  GUI *Gui_submenu;              // 0x28
  int unk_0x2C;                  // 0x2C
  int unk_0x30;                  // 0x30
  Uint16_t current_track_id;     // 0x34
  Uint16_t selected_track_id;    // 0x36
  Uint16_t tracks_count;         // 0x38
  char unk_0x3A;                 // 0x3A
  char unk_0x3B;                 // 0x3B
  int unk_0x3C;                  // 0x3C
  int unk_0x40;                  // 0x40
  TMusicServer_Time ElapsedTime; // 0x44
  int unk_0x50;                  // 0x50
  SUB_EXECUTE *CurrentTrack;     // 0x54
  TEXTID ErrorText;              // 0x58
  char unk_0x5C[0x38];           // 0x5C
  char unk_0x94;                 // 0x94
  char unk_0x95;                 // 0x95
  char unk_0x96;                 // 0x96
  char unk_0x97;                 // 0x97
} MusicApplication_Book;
#endif

#endif
