#ifndef _AudioPlayerBook_H_
#define _AudioPlayerBook_H_

struct AudioPlayerBook;

typedef struct
{
  u16 unk;        // 0
  u16 unk2;       // 0x2
  wchar_t *fpath; // 0x4
  wchar_t *fname; // 0x8
  wchar_t *MIME;  // 0xC
  int full_time;  // 0x10
} MEDIAPLAYER_TRACK_DESC;

typedef struct
{
  u16 unk_00;                  // 0
  u16 unk_02;                  // 0x2
  AudioPlayerBook *audio_book; // 0x4
  char dummy[0x1C];            // 0x8
  int hours;                   // 0x24
  int minutes;                 // 0x28
  int seconds;                 // 0x2C
  int mseconds;                // 0x30
} UI_MEDIAPLAYER_PLAYING_TIME_DATA;

#ifdef DB2010
typedef struct DISP_OBJ_NOWPLAYING : DISP_OBJ
{
  IMAGEID MP_BACKGROUND;  // 0xB8
  IMAGEID MP_MODE_NORMAL; // 0xBA
  IMAGEID MP_MODE_RANDOM; // 0xBC
  IMAGEID MP_MODE_REPEAT; // 0xBE
  IMAGEID MP_EQ_NORMAL_1; // 0xC0
  IMAGEID MOIMAGE_C2;     // 0xC2
  IMAGEID MP_EQ_MANUAL;   // 0xC4
  IMAGEID MP_EQ_NORMAL_2; // 0xC6
  IMAGEID MP_EQ_BASS;     // 0xC8
  IMAGEID MP_EQ_MEGABASS; // 0xCA
  IMAGEID MP_EQ_VOICE;    // 0xCC
  IMAGEID MP_EQ_TREBLE;   // 0xCE
  u16 FontSize_Artist;    // 0xD0
  u16 FontHeight_Artist;  // 0xD2
  u16 FontSize_Album;     // 0xD4
  u16 FontHeight_Album;   // 0xD6
  u16 FontSize_Title;     // 0xD8
  u16 FontHeight_Title;   // 0xDA
  u16 FontSize_DC;        // 0xDC
  u16 FontHeight_DE;      // 0xDE
  u16 FontSize_Elapsed;   // 0xE0
  u16 FontHeight_Elapsed; // 0xE2
  u16 FontSize_TrackID;   // 0xE4
  u16 FontHeight_TrackID; // 0xE6
  IMAGEID PB_PLAY_ICN;    // 0xE8
  IMAGEID image_E6;       // 0xEA
  IMAGEID PB_STOP_ICN;    // 0xEC
  IMAGEID PB_PAUSE_ICN;   // 0xEE
  IMAGEID NOIMAGE_F0;     // 0xF0
  IMAGEID NOIMAGE_F2;     // 0xF2
  IMAGEID NOIMAGE_F4;     // 0xF4
  IMAGEID NOIMAGE_F6;     // 0xF6
  IMAGEID NOIMAGE_F8;     // 0xF8
  IMAGEID NOIMAGE_FA;     // 0xFA
  IMAGEID NOIMAGE_FC;     // 0xFC
  IMAGEID NOIMAGE_FE;     // 0xFE
  char dummy2[0x28];      // 0x100
  TEXTID Text_Artis;      // 0x128
  TEXTID Text_Title;      // 0x12C
  TEXTID Text_Album;      // 0x130
  int full_time;          // 0x134
  int total_tracks;       // 0x138
  int current_track_id;   // 0x13C
  int elapsed_time;       // 0x140
  char dummy_144;         // 0x144
  bool Random;            // 0x145
  char Repeat;            // 0x146
  char dummy_147;         // 0x147
  char EqPreset;          // 0x148
  char dummy_149;         // 0x149
  char dummy_14A;         // 0x14A
  char dummy_14B;         // 0x14B
} DISP_OBJ_NOWPLAYING;

typedef struct DISP_OBJ_MP_AUDIO : DISP_OBJ
{
  IMAGEID MP_BACKGROUND;              // 0xB8
  IMAGEID MP_LIST_BACKGROUND;         // 0xBA
  IMAGEID MOIMAGE_BC;                 // 0xBC
  IMAGEID MP_MODE_NORMAL;             // 0xBE
  IMAGEID MP_MODE_RANDOM;             // 0xC0
  IMAGEID MP_MODE_REPEAT;             // 0xC2
  IMAGEID MP_LOW_BACKGROUND;          // 0xC4
  u16 FontSize_C6;                    // 0xC6
  u16 FontHeight_C6;                  // 0xC8
  u16 FontSize_CA;                    // 0xCA
  u16 FontHeight_CA;                  // 0xCC
  u16 FontSize_CE;                    // 0xCE
  u16 FontHeight_CE;                  // 0xD0
  u16 FontSize_D2;                    // 0xD2
  u16 FontHeight_D2;                  // 0xD4
  char dummy_D6[0x52];                // 0xD6
  DISP_OBJ *mp_playqueue;             // 0x128
  DISP_OBJ *mp_scrolltext;            // 0x12C
  DISP_OBJ *mp_volume;                // 0x130
  DISP_OBJ_NOWPLAYING *mp_nowplaying; // 0x134
  u16 current_track_id;               // 0x138
  u16 total_tracks;                   // 0x13A
  u16 full_time;                      // 0x13C
  u16 elapsed_time;                   // 0x13E
  char dummy_140[0x6];                // 0x140
  IMAGEID MP_PLAY;                    // 0x146
  IMAGEID MOIMAGE_148;                // 0x148
  IMAGEID MP_STOP;                    // 0x14A
  IMAGEID MP_PAUSE;                   // 0x14C
  IMAGEID MP_FAST_FORWARD;            // 0x14E
  IMAGEID MP_REWIND;                  // 0x150
  IMAGEID MOIMAGE_152;                // 0x152
  IMAGEID MP_SLOW_MOTION;             // 0x154
  char dummy_156[0x36];               // 0x156
} DISP_OBJ_MP_AUDIO;
#endif

#if defined(DB2010)
typedef struct MM_BrowserToplevelBook : BOOK
{
  GUI *MM_TopLevel; // 0x18
  int unk_1C;       // 0x1C
  u16 index;        // 0x20
  u16 unk_22;       // 0x22
  int unk_24;       // 0x24
  int unk_28;       // 0x28
  int unk_2C;       // 0x2c
  int unk_30;       // 0x30
  int unk_34;       // 0x34
} MM_BrowserToplevelBook;

typedef struct MM_BrowserArtistsBook : BOOK
{
  GUI *MM_TopLevel; // 0x18
  char unk_18[0xC]; // 0x1C
  void *unk_28;     // 0x28
  int unk_2C;       // 0x2c
  void **pIShell;   // 0x30
  void *unk_34;     // 0x34
  void *unk_38;     // 0x38
} MM_BrowserArtistsBook;

typedef struct AudioPlayerBook : BOOK
{
  char unk_0x18;               // 0x18
  char player_state;           // 0x19
  char unk_0x1A;               // 0x1A
  char unk_0x1B;               // 0x1B
  GUI *Gui_NowPlaying;         // 0x1C
  GUI *Gui_SubMenu;            // 0x20
  void *unk_24;                // 0x24
  void *unk_28;                // 0x28
  int unk_2C;                  // 0x2C
  void *unk_30;                // 0x30
  int sample_rate;             // 0x34
  u16 unk_38;                  // 0x38
  char eq_preset;              // 0x3A
  char char_3B;                // 0x3B
  char dummy1[0x10];           // 0x3C
  char window_mode;            // 0x4C
  char unk_4D;                 // 0x4D
  char unk_4E;                 // 0x4E
  char unk_4F;                 // 0x4F
  int unk_50;                  // 0x50
  int unk_54;                  // 0x54
  int Error_TextID;            // 0x58
  u16 pos;                     // 0x5C
  u16 unk_5E;                  // 0x5E
  int unk_60;                  // 0x60
  void *unk_64;                // 0x64
  int elapsed_time;            // 0x68
  MEDIAPLAYER_TRACK_DESC *dsc; // 0x6C
  u16 unk_70;                  // 0x70
  u16 current_track_id;        // 0x72
  u16 selected_track_id;       // 0x74
  u16 unk_76;                  // 0x76
  int unk_78;                  // 0x78
  int unk_7C;                  // 0x7C
  int unk_80;                  // 0x80
  int total_tracks;            // 0x84
  bool Repeat;                 // 0x88
  bool Random;                 // 0x89
  char unk_8A;                 // 0x8A
  char unk_8B;                 // 0x8B
  void *unk_8C;                // 0x8C
} AudioPlayerBook;

#elif defined(PNX5230)
typedef struct AudioPlayerBook : BOOK
{
  char unk_0x18;               // 0x18
  char player_state;           // 0x19
  char unk_0x1A;               // 0x1A
  char unk_0x1B;               // 0x1B
  GUI *Gui_NowPlaying;         // 0x1C
  GUI *Gui_PlayQueue;          // 0x20
  GUI *Gui_submenu;            // 0x24
  void *unk_0x28;              // 0x28
  void *pIAudioControl;        // 0x2C
  void *unk_0x30;              // 0x30
  u16 unk_0x34;                // 0x34
  u16 unk_0x36;                // 0x36
  char eq_preset;              // 0x38
  signed char EQ_Band1;        // 0x39
  signed char EQ_Band2;        // 0x3A
  signed char EQ_Band3;        // 0x3B
  signed char EQ_Band4;        // 0x3C
  signed char EQ_Band5;        // 0x3D
  u16 unk_0x3E;                // 0x3E
  int unk_0x40;                // 0x40
  int unk_0x44;                // 0x44
  int unk_0x48;                // 0x48
  int unk_0x4C;                // 0x4C
  int unk_0x50;                // 0x50
  int unk_0x54;                // 0x54
  int unk_0x58;                // 0x58
  int Error_TextID;            // 0x5C
  int unk_0x60;                // 0x60
  int unk_0x64;                // 0x64
  int unk_0x68;                // 0x68
  int unk_0x6C;                // 0x6C
  int ElapsedTime;             // 0x70
  int unk_0x74;                // 0x74
  BOOK_PLAYER_TRACK_DESC *dsc; // 0x78
  u16 unk_0x7C;                // 0x7C
  u16 current_track_id;        // 0x7E
  u16 selected_track_id;       // 0x80
  u16 unk_0x82;                // 0x82
  int unk_0x84;                // 0x84
  int unk_0x88;                // 0x88
  int unk_0x8C;                // 0x8C
  int unk_0x90;                // 0x90
  int unk_0x94;                // 0x94
  int total_tracks;            // 0x98
  bool Loop;                   // 0x9C
  bool Random;                 // 0x9D
  u16 unk_0x9E;                // 0x9E
  void *unk_0xA0;              // 0xA0
  char unk_0xA5;               // 0xA5
  char unk_0xA6;               // 0xA6
  char Current_EQ_Band1;       // 0xA7
  char Current_EQ_Band2;       // 0xA8
  char Current_EQ_Band3;       // 0xA9
  char Current_EQ_Band4;       // 0xAA
  char Current_EQ_Band5;       // 0xAB
  void *unk_0xAC;              // 0xAC
  int unk_0xB0;                // 0xB0
} AudioPlayerBook;

#elif defined(DB2020)
typedef struct AudioPlayerBook : BOOK
{
  char unk_0x18;               // 0x18
  char player_state;           // 0x19
  char unk_0x1A;               // 0x1A
  char unk_0x1B;               // 0x1B
  GUI *Gui_NowPlaying;         // 0x1C
  GUI *Gui_PlayQueue;          // 0x20
  GUI *Gui_submenu;            // 0x24
  char dummy0[0x34];           // 0x28
  wchar_t pos;                 // 0x5C
  char dummy1[0xE];            // 0x5E
  int ElapsedTime;             // 0x6C
  char dummy2[0x4];            // 0x70
  MEDIAPLAYER_TRACK_DESC *dsc; // 0x74
  char dummy3[2];              // 0x78
  wchar_t pos2;                // 0x7A
  wchar_t pos3;                // 0x7C
  char dummy4[0x16];           // 0x7E
  int total_tracks;            // 0x94
} AudioPlayerBook;
#endif

#endif
