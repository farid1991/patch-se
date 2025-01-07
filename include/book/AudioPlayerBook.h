#ifndef AudioPlayerBook_H
#define AudioPlayerBook_H

#include "..\classes\IUnknown.h"

typedef enum
{
  EqPreset_Normal = 0,
  EqPreset_Bass = 1,
#ifdef MEGABASS
  EqPreset_Megabass = 2,
  EqPreset_Voice = 3,
  EqPreset_TrebleBoost = 4,
#else
  EqPreset_Voice = 2,
  EqPreset_TrebleBoost = 3,
#endif
  EqPreset_Manual = 6
} EqPreset_t;

typedef enum
{
  TMusicState_Idle,           ///< Player is idle, eg is in the init phase but not yet fully initiated.
  TMusicState_Playing,        ///< Player is playing.
  TMusicState_Paused,         ///< Player is paused. Use the resume method to resume the playback.
  TMusicState_FastForwarding, ///< Player is fast forwarding.
  TMusicState_Interrupted,    ///< Player is interrupted by another playback session/player/call.
  TMusicState_Rewinding,      ///< Player is rewinding.
  TMusicState_Unknown,        ///< State is unknown to the Music Server.
  TMusicState_Last            ///< Place holder. Put new data before this!
} TMusic_State;

typedef struct PLAYLIST_ITEM
{
  wchar_t artist[31];
  wchar_t title[31];
  wchar_t album[31];
  wchar_t fpath[252];
  wchar_t fname[252];
  uint16_t unk_4AA;
  uint32_t unk_4AC;
  uint8_t unk_4B0[0xC];
} PLAYLIST_ITEM;

class IPlaylist : public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int unk_0x20();
  virtual int GetName(int playlist_id, int playlist_index, wchar_t *playlist_name);
  virtual int unk_0x28();
  virtual int Update(int _null0, int _event, int _null1, int playlist_id);
  virtual int unk_0x30();
  virtual int unk_0x34();
  virtual int Rename(int _null0, int _event, int _null1, int playlist_id, wchar_t *new_name);
  virtual int unk_0x3C();
  virtual int unk_0x40();
  virtual int unk_0x44();
  virtual int unk_0x48();
  virtual int unk_0x4C();
  virtual int unk_0x50();
  virtual int unk_0x54();
  virtual int unk_0x58();
  virtual int unk_0x5C();
  virtual int unk_0x60();
  virtual int unk_0x64();
  virtual int unk_0x68();
  virtual int unk_0x6C();
  virtual int unk_0x70();
  virtual int Add(int _null0, int _event, int _null1, int playlist_id, wchar_t *playlist_name);
  virtual int unk_0x78();
  virtual int unk_0x7C();
  virtual int unk_0x80();
  virtual int unk_0x84();
#ifdef DB2020
  virtual int unk_0x88();
  virtual int unk_0x8C();
  virtual int unk_0x90();
  virtual int unk_0x94();
  virtual int GetItem(int playlist_id, int selected_track_id, PLAYLIST_ITEM *item);
#else
  virtual int GetItem(int playlist_id, int selected_track_id, PLAYLIST_ITEM *item);
  virtual int unk_0x8C();
  virtual int unk_0x90();
  virtual int unk_0x94();
  virtual int unk_0x98();
  virtual int unk_0x9C();
  virtual int GetItemCount(int playlist_id, int *counts);
  virtual int SortItem(int _null0, int _unk16d0, int _null1, int playlist_id, int sort_by, int current_track_id);
  virtual int unk_0xA8();
  virtual int unk_0xAC();
  virtual int unk_0xB0();
  virtual int unk_0xB4();
#endif
};

class IPlaylistManager : public IUnknown
{
public:
  virtual int CreatePlaylist(IPlaylist **ppIPlaylist);
};

class IAudioControl : public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int unk_0x20();
  virtual int unk_0x24();
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int unk_0x30();
  virtual int unk_0x34();
  virtual int unk_0x38();
  virtual int unk_0x3C();
  virtual int unk_0x40();
  virtual int unk_0x44();
  virtual int unk_0x48();
  virtual int unk_0x4C();
  virtual int unk_0x50();
  virtual int unk_0x54();
  virtual int unk_0x58();
  virtual int unk_0x5C();
  virtual int unk_0x60();
  virtual int unk_0x64();
  virtual int unk_0x68();
  virtual int unk_0x6C();
  virtual int unk_0x70();
  virtual int unk_0x74();
  virtual int unk_0x78();
  virtual int unk_0x7C();
  virtual int unk_0x80();
  virtual int unk_0x84();
  virtual int unk_0x88();
  virtual int unk_0x8C();
  virtual int unk_0x90();
  virtual int unk_0x94();
  virtual int unk_0x98();
  virtual int unk_0x9C();
  virtual int unk_0xA0();
  virtual int unk_0xA4();
  virtual int unk_0xA8();
  virtual int unk_0xAC();
  virtual int unk_0xB0();
  virtual int unk_0xB4();
  virtual int unk_0xB8();
  virtual int unk_0xBC();
  virtual int unk_0xC0();
  virtual int unk_0xC4();
  virtual int unk_0xC8();
  virtual int unk_0xCC();
  virtual int Volume_Set(uint8_t volumeType, uint8_t volume);
  virtual int Volume_Get(uint8_t volumeType, uint8_t *volume);
  virtual int unk_0xD8();
  virtual int unk_0xDC();
  virtual int unk_0xE0();
  virtual int unk_0xE4();
  virtual int unk_0xE8();
  virtual int unk_0xEC();
  virtual int unk_0xF0();
  virtual int unk_0xF4();
  virtual int unk_0xF8();
  virtual int unk_0xFC();
  virtual int EqualizerGain_Set(uint32_t session_id, uint8_t equalizerBand, int8_t equalizerGain);
  virtual int unk_0x104();
  virtual int EqualizerEnable_Set(bool equalizerEnabled);
  virtual int unk_0x10C();
  virtual int unk_0x110();
  virtual int unk_0x114();
  virtual int unk_0x118();
  virtual int unk_0x11C();
  virtual int unk_0x120();
  virtual int unk_0x124();
  virtual int unk_0x128();
  virtual int unk_0x12C();
  virtual int unk_0x130();
  virtual int unk_0x134();
  virtual int unk_0x138();
  virtual int unk_0x13C();
  virtual int unk_0x140();
  virtual int unk_0x144();
  virtual int unk_0x148();
  virtual int Vibrator_Start(uint32_t period, uint32_t dutyCycle, uint32_t duration);
  virtual int Vibrator_Stop(void);
  virtual int unk_0x154();
  virtual int unk_0x158();
  virtual int unk_0x15C();
  virtual int unk_0x160();
  virtual int unk_0x164();
  virtual int unk_0x168();
  virtual int unk_0x16C();
  virtual int unk_0x170();
  virtual int unk_0x174();
};

class IAudioControlManager : public IUnknown
{
public:
  virtual int CreateAudioControl(IAudioControl **ppIAudioControl);
};

struct AudioPlayerBook;

typedef struct MEDIAPLAYER_TRACK_DESC
{
  uint16_t unk_0;       // 0
  uint16_t unk_2;       // 0x2
  wchar_t *fpath;       // 0x4
  wchar_t *fname;       // 0x8
  wchar_t *mime;        // 0xC
  uint32_t full_time;   // 0x10
  int unk_14;           // 0x14
  uint32_t sample_rate; // 0x18
  int unk_1C;           // 0x1C
  int unk_20;           // 0x20
  int unk_24;           // 0x24
} MEDIAPLAYER_TRACK_DESC;

typedef struct MEDIAPLAYER_PLAYING_TIME_DATA
{
  uint16_t unk_0;              // 0
  uint16_t unk_2;              // 0x2
  AudioPlayerBook *audio_book; // 0x4
  char unk_8[0x1C];            // 0x8
  uint32_t hours;              // 0x24
  uint32_t minutes;            // 0x28
  uint32_t seconds;            // 0x2C
} MEDIAPLAYER_PLAYING_TIME_DATA;

typedef struct MEDIAPLAYER_NEWTRACK_DATA
{
  uint16_t unk_0;              // 0
  uint16_t unk_2;              // 0x2
  AudioPlayerBook *audio_book; // 0x4
  char unk_8[0x1C];            // 0x8
} MEDIAPLAYER_NEWTRACK_DATA;

typedef struct MEDIAPLAYER_EQ
{
  int8_t band_1;
  int8_t band_2;
  int8_t band_3;
  int8_t band_4;
  int8_t band_5;
} MEDIAPLAYER_EQ;

typedef struct MEDIAPLAYER_STATE
{
  uint8_t unk_18;
  uint8_t state;
  uint8_t unk_1A;
  uint8_t unk_1B;
} MEDIAPLAYER_STATE;

#if defined(DB2010)
typedef struct MM_BrowserToplevelBook : BOOK
{
  GUI *MM_TopLevel; // 0x18
  int unk_1C;       // 0x1C
  uint16_t index;   // 0x20
  uint16_t unk_22;  // 0x22
  int unk_24;       // 0x24
  void *pShell;     // 0x28
  int unk_2C;       // 0x2c
  int unk_30;       // 0x30
  int unk_34;       // 0x34
} MM_BrowserToplevelBook;

#ifdef OLD_PLAYER
typedef struct DISP_OBJ_NOWPLAYING : DISP_OBJ
{
  char unk_BC[0x60];    // 0xBC
  TEXTID artist_textid; // 0x11C
  TEXTID title_textid;  // 0x120
  TEXTID album_textid;  // 0x124
  int full_time;        // 0x128
  int total_tracks;     // 0x12C
  int current_track_id; // 0x130
  int elapsed_time;     // 0x134
  bool is_preset;       // 0x138
  bool random;          // 0x139
  bool repeat;          // 0x13A
  char unk_13B;         // 0x13B
  uint8_t eq_preset;    // 0x13C
} DISP_OBJ_NOWPLAYING;

typedef struct DISP_OBJ_MP_AUDIO : DISP_OBJ
{
  char unk_BC[0xD0]; // 0xBC
} DISP_OBJ_MP_AUDIO;

typedef struct AudioPlayerBook : BOOK
{
  MEDIAPLAYER_STATE player;     // 0x18
  GUI *Gui_NowPlaying;          // 0x1C
  GUI *Gui_SubMenu;             // 0x20
  void *pPlayerManager;         // 0x24 Interface?
  IAudioControl *pAudioControl; // 0x28
  int audio_session_id;         // 0x2C
  void *unk_30;                 // 0x30
  uint32_t sample_rate;         // 0x34
  bool eq_enabled;              // 0x38
  char unk_39;                  // 0x39
  uint8_t eq_preset;            // 0x3A
  MEDIAPLAYER_EQ eq_active;     // 0x3B
  uint32_t unk_40;              // 0x40
  uint32_t parent_book_id;      // 0x44
  uint16_t unk_48;              // 0x48
  uint16_t unk_4A;              // 0x4A
  uint8_t window_mode;          // 0x4C
  char unk_4D;                  // 0x4D
  char unk_4E;                  // 0x4E
  char unk_4F;                  // 0x4F
  SUB_EXECUTE *sub_exec;        // 0x50
  uint32_t book_id;             // 0x54
  TEXTID error_text;            // 0x58
  uint16_t track_index;         // 0x5C
  uint16_t timer_id;            // 0x5E
  int unk_60;                   // 0x60
  void *unk_64;                 // 0x64 Interface?
  uint32_t elapsed_time;        // 0x68
  MEDIAPLAYER_TRACK_DESC *dsc;  // 0x6C
  uint16_t current_track_id;    // 0x70
  uint16_t selected_track_id;   // 0x72
  uint8_t unk_74[0x20];         // 0x74
  IPlaylist *pPlaylist;         // 0x94
  uint32_t playlist_id;         // 0x98
} AudioPlayerBook;
#else

typedef struct DISP_OBJ_NOWPLAYING : DISP_OBJ
{
  IMAGEID MP_BACKGROUND;        // 0xB8
  IMAGEID MP_MODE_NORMAL;       // 0xBA
  IMAGEID MP_MODE_RANDOM;       // 0xBC
  IMAGEID MP_MODE_REPEAT;       // 0xBE
  IMAGEID MP_EQ_ICON;           // 0xC0
  IMAGEID NOIMAGE_C2;           // 0xC2
  IMAGEID MP_EQ_MANUAL;         // 0xC4
  IMAGEID MP_EQ_NORMAL;         // 0xC6
  IMAGEID MP_EQ_BASS;           // 0xC8
  IMAGEID MP_EQ_MEGABASS;       // 0xCA
  IMAGEID MP_EQ_VOICE;          // 0xCC
  IMAGEID MP_EQ_TREBLE;         // 0xCE
  uint16_t artist_font_size;    // 0xD0
  uint16_t artist_font_height;  // 0xD2
  uint16_t album_font_size;     // 0xD4
  uint16_t album_font_height;   // 0xD6
  uint16_t title_font_size;     // 0xD8
  uint16_t title_font_height;   // 0xDA
  uint16_t other_font_size;     // 0xDC
  uint16_t other_font_height;   // 0xDE
  uint16_t elapsed_font_size;   // 0xE0
  uint16_t elapsed_font_height; // 0xE2
  uint16_t trackid_font_size;   // 0xE4
  uint16_t trackid_font_height; // 0xE6
  IMAGEID PB_PLAY_ICN;          // 0xE8
  IMAGEID image_E6;             // 0xEA
  IMAGEID PB_STOP_ICN;          // 0xEC
  IMAGEID PB_PAUSE_ICN;         // 0xEE
  int unk_F0;                   // 0xF0
  int unk_F4;                   // 0xF4
  uint32_t artist_color;        // 0xF8
  uint32_t title_color;         // 0xFC
  uint32_t additional_color;    // 0x100
  char unk_100[0x10];           // 0x104
  uint32_t brush_color;         // 0x114
  char unk_118[0x10];           // 0x118
  TEXTID artist_textid;         // 0x128
  TEXTID title_textid;          // 0x12C
  TEXTID album_textid;          // 0x130
  int full_time;                // 0x134
  int total_tracks;             // 0x138
  int current_track_id;         // 0x13C
  int elapsed_time;             // 0x140
  bool is_preset;               // 0x144
  bool random;                  // 0x145
  bool repeat;                  // 0x146
  char unk_147;                 // 0x147
  uint8_t eq_preset;            // 0x148
} DISP_OBJ_NOWPLAYING;

typedef struct DISP_OBJ_MP_AUDIO : DISP_OBJ
{
  IMAGEID MP_BACKGROUND;              // 0xB8
  IMAGEID MP_LIST_BACKGROUND;         // 0xBA
  IMAGEID NOIMAGE_BC;                 // 0xBC
  IMAGEID MP_MODE_NORMAL;             // 0xBE
  IMAGEID MP_MODE_RANDOM;             // 0xC0
  IMAGEID MP_MODE_REPEAT;             // 0xC2
  IMAGEID MP_LOW_BACKGROUND;          // 0xC4
  uint16_t FontSize_C6;               // 0xC6
  uint16_t FontHeight_C6;             // 0xC8
  uint16_t FontSize_CA;               // 0xCA
  uint16_t FontHeight_CA;             // 0xCC
  uint16_t FontSize_CE;               // 0xCE
  uint16_t FontHeight_CE;             // 0xD0
  uint16_t FontSize_D2;               // 0xD2
  uint16_t FontHeight_D2;             // 0xD4
  RECT rect_background;               // 0xD6
  RECT rect_scrollbar;                // 0xDE
  RECT rect_playerstate;              // 0xE6
  RECT rect_remaining_time;           // 0xEE
  RECT rect_progressbar;              // 0xF6
  RECT rect_volume;                   // 0xFE
  RECT rect_repeat;                   // 0x106
  RECT rect_random;                   // 0x10E
  RECT rect_progressbar_bg;           // 0x116
  char unk_11E[0xA];                  // 0x11E
  DISP_OBJ *mp_playqueue;             // 0x128
  DISP_OBJ *mp_scrolltext;            // 0x12C
  DISP_OBJ *mp_volume;                // 0x130
  DISP_OBJ_NOWPLAYING *mp_nowplaying; // 0x134
  uint16_t current_track_id;          // 0x138
  uint8_t player_state;               // 0x13A
  uint8_t unk_13B;                    // 0x13B
  uint16_t full_time;                 // 0x13C
  uint16_t elapsed_time;              // 0x13E
  uint16_t remaining_time;            // 0x140
  char unk_140[0x4];                  // 0x142
  IMAGEID MP_PLAY;                    // 0x146
  IMAGEID NOIMAGE_148;                // 0x148
  IMAGEID MP_STOP;                    // 0x14A
  IMAGEID MP_PAUSE;                   // 0x14C
  IMAGEID MP_FAST_FORWARD;            // 0x14E
  IMAGEID MP_REWIND;                  // 0x150
  IMAGEID NOIMAGE_152;                // 0x152
  IMAGEID MP_SLOW_MOTION;             // 0x154
  char unk_156[0x36];                 // 0x156
} DISP_OBJ_MP_AUDIO;

typedef struct MM_BrowserArtistsBook : BOOK
{
  GUI *MM_TopLevel; // 0x18
  char unk_1C[0xC]; // 0x1C
  void *unk_28;     // 0x28
  int unk_2C;       // 0x2c
  void **pIShell;   // 0x30
  void *unk_34;     // 0x34
  void *unk_38;     // 0x38
} MM_BrowserArtistsBook;

typedef struct AudioPlayerBook : BOOK
{
  MEDIAPLAYER_STATE player;     // 0x18
  GUI *Gui_NowPlaying;          // 0x1C
  GUI *Gui_SubMenu;             // 0x20
  void *pPlayerManager;         // 0x24 Interface?
  IAudioControl *pAudioControl; // 0x28
  int audio_session_id;         // 0x2C
  void *unk_30;                 // 0x30
  uint16_t sample_rate;         // 0x34
  char unk_36;                  // 0x36
  char unk_37;                  // 0x37
  bool eq_enabled;              // 0x38
  char unk_39;                  // 0x39
  uint8_t eq_preset;            // 0x3A
  MEDIAPLAYER_EQ eq_active;     // 0x3B
  uint32_t unk_40;              // 0x40
  uint32_t parent_book_id;      // 0x44
  uint16_t unk_48;              // 0x48
  uint16_t unk_4A;              // 0x4A
  uint8_t window_mode;          // 0x4C
  char unk_4D;                  // 0x4D
  char unk_4E;                  // 0x4E
  char unk_4F;                  // 0x4F
  SUB_EXECUTE *sub_exec;        // 0x50
  uint32_t book_id;             // 0x54
  TEXTID error_text;            // 0x58
  uint16_t track_index;         // 0x5C
  uint16_t timer_id;            // 0x5E
  int unk_60;                   // 0x60
  void *unk_64;                 // 0x64 Interface?
  uint32_t elapsed_time;        // 0x68
  MEDIAPLAYER_TRACK_DESC *dsc;  // 0x6C
  uint16_t unk_70;              // 0x70
  uint16_t current_track_id;    // 0x72
  uint16_t selected_track_id;   // 0x74
  uint16_t unk_76;              // 0x76
  uint16_t unk_78;              // 0x78
  uint16_t unk_7A;              // 0x7A
  int unk_7C;                   // 0x7C
  int unk_80;                   // 0x80
  int total_tracks;             // 0x84
  bool repeat;                  // 0x88
  bool random;                  // 0x89
  char unk_8A;                  // 0x8A
  char unk_8B;                  // 0x8B
  void *unk_8C;                 // 0x8C Interface?
  char unk_90;                  // 0x90
  uint8_t eq_state;             // 0x91
  char unk_92;                  // 0x92
  char unk_93;                  // 0x93
  MEDIAPLAYER_EQ *eq_settings;  // 0x94
  IPlaylist *pPlaylist;         // 0x98
  uint32_t playlist_id;         // 0x9C
  int unk_A0;                   // 0xA0
  int unk_A4;                   // 0xA4
  int unk_A8;                   // 0xA8
  int unk_AC;                   // 0xAC
  void *pDrmHandler;            // 0xB0 Interface?
  int unk_B4;                   // 0xB4
  uint16_t unk_B8;              // 0xB8
  uint16_t unk_BA;              // 0xBA
  int unk_BC;                   // 0xBC
  char unk_C0[0xC];             // 0xC0
} AudioPlayerBook;
#endif

#elif defined(PNX5230)
typedef struct AudioPlayerBook : BOOK
{
  MEDIAPLAYER_STATE player;    // 0x18
  GUI *Gui_NowPlaying;         // 0x1C
  GUI *Gui_PlayQueue;          // 0x20
  GUI *Gui_submenu;            // 0x24
  void *unk_28;                // 0x28
  void *pIAudioControl;        // 0x2C
  void *unk_30;                // 0x30
  uint16_t unk_34;             // 0x34
  uint16_t unk_36;             // 0x36
  uint8_t eq_preset;           // 0x38
  MEDIAPLAYER_EQ eq_active;    // 0x39
  uint16_t unk_3E;             // 0x3E
  int unk_40;                  // 0x40
  int unk_44;                  // 0x44
  int unk_48;                  // 0x48
  int unk_4C;                  // 0x4C
  int unk_50;                  // 0x50
  int unk_54;                  // 0x54
  int unk_58;                  // 0x58
  TEXTID error_text;           // 0x5C
  int unk_60;                  // 0x60
  int unk_64;                  // 0x64
  int unk_68;                  // 0x68
  int unk_6C;                  // 0x6C
  int ElapsedTime;             // 0x70
  int unk_74;                  // 0x74
  MEDIAPLAYER_TRACK_DESC *dsc; // 0x78
  uint16_t unk_7C;             // 0x7C
  uint16_t current_track_id;   // 0x7E
  uint16_t selected_track_id;  // 0x80
  uint16_t unk_82;             // 0x82
  int unk_84;                  // 0x84
  int unk_88;                  // 0x88
  int unk_8C;                  // 0x8C
  int unk_90;                  // 0x90
  int unk_94;                  // 0x94
  int total_tracks;            // 0x98
  bool repeat;                 // 0x9C
  bool random;                 // 0x9D
  uint16_t unk_9E;             // 0x9E
  void *unk_A0;                // 0xA0
  char unk_A5;                 // 0xA5
  char unk_A6;                 // 0xA6
  char unk_A7;                 // 0xA7
  MEDIAPLAYER_EQ *eq_settings; // 0xA8
  void *unk_AC;                // 0xAC
  int unk_B0;                  // 0xB0
} AudioPlayerBook;

#elif defined(DB2020)
typedef struct MM_BrowserToplevelBook : BOOK
{
  GUI *MM_TopLevel;  // 0x18
  int unk_1C;        // 0x1C
  uint16_t index;    // 0x20
  uint16_t unk_22;   // 0x22
  void *online_link; // 0x24
  void *pShell;      // 0x28
  int unk_2C;        // 0x2c
  int unk_30;        // 0x30
  int unk_34;        // 0x34
  int unk_38;        // 0x38
  int unk_3C;        // 0x3C
} MM_BrowserToplevelBook;

typedef struct MM_BrowserPlaylistBook : BOOK
{
  GUI *MM_Playlist; // 0x18
} MM_BrowserPlaylistBook;

typedef struct DISP_OBJ_NOWPLAYING : DISP_OBJ
{
  IMAGEID MP_BACKGROUND;     // 0xB4
  IMAGEID IMG_B6;            // 0xB6
  IMAGEID MP_MODE_NORMAL;    // 0xB8
  IMAGEID MP_MODE_RANDOM;    // 0xBA
  IMAGEID MP_MODE_REPEAT;    // 0xBC
  IMAGEID MP_EQ_NORMAL_1;    // 0xBE
  IMAGEID IMG_C0;            // 0xC0
  IMAGEID MP_EQ_MANUAL;      // 0xC2
  IMAGEID MP_EQ_NORMAL_2;    // 0xC4
  IMAGEID MP_EQ_BASS;        // 0xC6
  IMAGEID MP_EQ_MEGABASS;    // 0xC8
  IMAGEID MP_EQ_VOICE;       // 0xCA
  IMAGEID MP_EQ_TREBLEBOOST; // 0xCC
  uint8_t unk_CE[0x18];      // 0xCE
  IMAGEID MP_PB_PLAY1_ICN;   // 0xE6
  IMAGEID IMG_E2;            // 0xE8
  IMAGEID MP_PB_STOP_ICN;    // 0xEA
  IMAGEID MP_PB_PAUSE_ICN;   // 0xEC
  IMAGEID IMG_E8;            // 0xEE
  IMAGEID IMG_EA;            // 0xF0
  IMAGEID MP_PB_PLAY2_ICN;   // 0xF2
  uint8_t unk_F4[0x3C];      // 0xF4
  TEXTID artist_textid;      // 0x130
  TEXTID title_textid;       // 0x134
  TEXTID album_textid;       // 0x138
  uint32_t full_time;        // 0x13C
  uint32_t total_tracks;     // 0x140
  uint32_t current_track_id; // 0x144
  uint32_t elapsed_time;     // 0x148
  uint8_t unk_14C;           // 0x14C
  bool random;               // 0x14D
  bool repeat;               // 0x14E
  uint8_t unk_14F;           // 0x14F
  uint8_t unk_150;           // 0x150
  uint8_t eq_preset;         // 0x151
  uint8_t unk_152;           // 0x152
  uint8_t unk_153;           // 0x153
} DISP_OBJ_NOWPLAYING;

typedef struct AudioPlayerBook : BOOK
{
  MEDIAPLAYER_STATE player;     // 0x18
  GUI *Gui_NowPlaying;          // 0x1C
  GUI *Gui_SubMenu;             // 0x20
  GUI *Gui_External;            // 0x24
  int unk_28;                   // 0x28
  IAudioControl *pAudioControl; // 0x2C
  signed int unk_30;            // 0x30
  uint32_t sample_rate;         // 0x34
  uint8_t eq_preset;            // 0x38
  int8_t band_1;                // 0x39
  int8_t band_2;                // 0x3A
  int8_t band_3;                // 0x3B
  int8_t band_4;                // 0x3C
  int8_t band_5;                // 0x3D
  uint8_t unk_3E;               // 0x3E
  uint8_t unk_3F;               // 0x3F
  int unk_40;                   // 0x40
  int audio_session_id;         // 0x44
  uint32_t parent_book_id;      // 0x48
  char unk_48[0x8];             // 0x4C
  SUB_EXECUTE *sub_exec;        // 0x54
  uint32_t unk_58;              // 0x58
  TEXTID error_textid;          // 0x5C
  uint16_t track_index;         // 0x60
  uint16_t unk_62;              // 0x62
  uint16_t timer_id;            // 0x64
  uint16_t unk_66;              // 0x66
  uint32_t unk_68;              // 0x68
  void *unk_6C;                 // 0x6C
  uint32_t elapsed_time;        // 0x70
  MEDIAPLAYER_TRACK_DESC *dsc;  // 0x74
  uint16_t unk_78;              // 0x78
  uint16_t current_track_id;    // 0x7A
  uint16_t selected_track_id;   // 0x7C
  uint16_t unk_7E;              // 0x7E
  char unk_80[0x14];            // 0x80
  uint16_t total_tracks;        // 0x94
  uint16_t unk_96;              // 0x96
  bool repeat;                  // 0x98
  bool random;                  // 0x99
  uint16_t unk_9A;              // 0x9A
  int unk_9C;                   // 0x9C
  bool stereo_widening;         // 0xA0
  uint8_t unk_A1;               // 0xA1
  uint8_t eq_state;             // 0xA2
  uint8_t unk_A3;               // 0xA3
  MEDIAPLAYER_EQ *eq_settings;  // 0xA4
  IPlaylist *pPlaylist;         // 0xA8
  uint32_t playlist_id;         // 0xAC
} AudioPlayerBook;

#endif

#endif
