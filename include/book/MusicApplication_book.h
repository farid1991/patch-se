#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

typedef struct
{
  uint32_t hours;
  uint32_t minutes;
  uint32_t seconds;
} TMusicServer_Time;

/**
 * The set of music server states.
 */
typedef enum
{
  TMusicServerState_Idle,           ///< Player is idle, eg is in the init phase but not yet fully initiated.
  TMusicServerState_Initiated,      ///< Player is initiated.
  TMusicServerState_Playing,        ///< Player is playing.
  TMusicServerState_Paused,         ///< Player is paused. Use the resume method to resume the playback.
  TMusicServerState_FastForwarding, ///< Player is fast forwarding.
  TMusicServerState_Rewinding,      ///< Player is rewinding.
  TMusicServerState_Interrupted,    ///< Player is interrupted by another playback session/player/call.
  TMusicServerState_Unknown,        ///< State is unknown to the Music Server.
  TMusicServerState_Last            ///< Place holder. Put new data before this!
} TMusicServer_State;

/**
 * The set of music server status.
 */
typedef enum
{
  TMusicServerCause_Error,                    ///< General unspecified error.
  TMusicServerCause_Platform_Error,           ///< Unspecified platform error.
  TMusicServerCause_Beginning_Of_File_Passed, ///< Passed beginnig of media file (case of rewind operation).
  TMusicServerCause_End_Of_File,              ///< End of media file reached.
  TMusicServerCause_Client_Termination,       ///< Client terminated the session player.
  TMusicServerCause_DRM_Credentials_Expired,  ///< DRM credentials expired.
  TMusicServerCause_File_Not_Found,           ///< File does not exist.
  TMusicServerCause_Last                      ///< Place holder. Put new data before this!
} TMusicServer_Cause;

/**
 * The set of music server status.
 */
typedef enum
{
  TMusicServerStatus_ActiveMaximized, ///< Player is started in maximized mode, can be paused or playing.
  TMusicServerStatus_ActiveMinimized, ///< Player is started in maximized mode, can only be playing in minimized.
  TMusicServerStatus_Inactive,        ///< Player is shut down.
  TMusicServerStatus_Last             ///< Place holder. Put new data before this!
} TMusicServer_Status;

/**
 * Album art image types 
 */
typedef enum
{
  TMusicServer_AlbumArt_ImageType_Jpeg,
  TMusicServer_AlbumArt_ImageType_Gif,
  TMusicServer_AlbumArt_ImageType_Png,
  TMusicServer_AlbumArt_ImageType_Bmp,
  TMusicServer_AlbumArt_ImageType_None,
  TMusicServer_AlbumArt_ImageType_Embedded
} TMusicServer_AlbumArt_ImageType;

/**
 * The set of settings used in the music server
 */
typedef enum
{
    TMusicServerSetting_Loop,
    TMusicServerSetting_Random
} TMusicServer_Settings;

typedef struct _PLAYING_TIME_DATA
{
  uint8_t dummy[0x24];
  TMusicServer_Time PlayingTime;
} PLAYING_TIME_DATA;

typedef struct _NEW_TRACK_DATA
{
  uint8_t dummy_0x0[0x28];       //0
  int Track_ID;                  //0x28
  TMusicServer_Time ElapsedTime; //0x2C
  uint8_t dummy_0x30[0x24];      //0x38
  TMusicServer_Time FullTime;    //0x5C
} NEW_TRACK_DATA;

typedef struct _MusicApp_PlayMode
{
  bool Loop;
  bool Shuffle;
} MusicApp_PlayMode;

typedef struct _MusicApp_Settings
{
  uint8_t unk_0;
  uint8_t unk_1;
  uint8_t unk_2;
  bool StereoWidening;
} MusicApp_Settings;

typedef struct _Equalizer_Band
{
  uint8_t Band_63;
  uint8_t Band_250;
  uint8_t Band_1000;
  uint8_t Band_4000;
  uint8_t Band_16000;
} Equalizer_Band;

#if defined(DB3150v1)
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;          // 0x18
  GUI *Gui_NowPlaying;         // 0x1C
  GUI *Gui_PlayQueue;          // 0x20
  uint32_t unk_0x24;           // 0x24
  GUI *Gui_submenu;            // 0x28
  uint32_t unk_0x2C;           // 0x2C
  uint16_t current_track_id;   // 0x30
  uint16_t selected_track_id;  // 0x32
  uint16_t tracks_count;       // 0x34
  uint8_t state;               // 0x36
  uint8_t unk_0x37;            // 0x37
  uint8_t PlayerState;         // 0x38 TMusicServer_State
  uint8_t unk_0x39;            // 0x39
  uint8_t cause;               // 0x3A TMusicServer_Cause
  MusicApp_PlayMode PlayMode;  // 0x3B
  uint8_t unk_0x3D;            // 0x3D
  uint8_t unk_0x3E;            // 0x3E
  uint8_t unk_0x3F;            // 0x3F
  TMusicServer_Time Time;      // 0x40
  uint8_t unk_0x4C;            // 0x4C
  uint8_t status;              // 0x4D TMusicServer_Status
  uint8_t DisplayOrientation;  // 0x4E
  uint8_t unk_0x4F;            // 0x4F
  SUB_EXECUTE *CurrentTrack;   // 0x50
  uint8_t unk_0x54;            // 0x54
  uint8_t unk_0x55;            // 0x55
  uint8_t unk_0x56;            // 0x56
  uint8_t unk_0x57;            // 0x57
  TEXTID ErrorText;            // 0x58 TMusicServer_ErrorCode
  uint8_t unk_0x5C;            // 0x5C
  uint8_t unk_0x5D;            // 0x5C
  uint16_t unk_0x5E;           // 0x5E
  uint8_t unk_0x60;            // 0x60
  uint8_t unk_0x61;            // 0x61
  uint16_t timerID;            // 0x62
  uint16_t unk_0x64;           // 0x64
  uint8_t EQ_Preset;           // 0x66
  uint8_t unk_0x67;            // 0x67
  void *unk_0x68;              // 0x68
  void *unk_0x6C;              // 0x6C
  void *unk_0x70;              // 0x70
  uint8_t unk_0x74;            // 0x74
  uint8_t unk_0x75;            // 0x75
  uint8_t unk_0x76;            // 0x76
  uint8_t unk_0x77;            // 0x77
  MusicApp_Settings *Settings; // 0x78
  uint32_t unk_0x7C;           // 0x7C
  uint8_t unk_0x80[0xC];       // 0x80
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
  uint8_t EQ_Preset;             // 0x73
  uint32_t Eq_Band1;             // 0x74
  uint32_t Eq_Band2;             // 0x78
  uint32_t Eq_Band3;             // 0x7C
  uint32_t Eq_Band4;             // 0x80
  uint32_t Eq_Band5;             // 0x84
  uint32_t Level_6_3kHz;         // 0x88
  uint32_t Level_16kHz;          // 0x8C
  uint8_t unk_0x90;              // 0x90
  uint8_t unk_0x91;              // 0x91
  uint8_t unk_0x92;              // 0x92
  uint8_t unk_0x93;              // 0x93
  void *SettingsBook;            // 0x94
  uint8_t unk_0x98;              // 0x98
  uint8_t unk_0x99;              // 0x99
  uint8_t unk_0x9A;              // 0x9A
  uint8_t unk_0x9B;              // 0x9b
  uint32_t unk_0x9C;             // 0x9C
} MusicApplication_Book;

#elif defined(DB3350)
typedef struct _MusicApplication_Book : BOOK
{
  void *pMusicServer;         // 0x18
  uint32_t unk_0x1C;          // 0x1C
  GUI *Gui_NowPlaying;        // 0x20
  GUI *Gui_PlayQueue;         // 0x24
  GUI *Gui_submenu;           // 0x28
  uint32_t unk_0x2C;          // 0x2C
  uint32_t unk_0x30;          // 0x30
  uint16_t current_track_id;  // 0x34
  uint16_t selected_track_id; // 0x36
  uint8_t unk_0x38;           // 0x38
  uint8_t unk_0x39;           // 0x39
  uint16_t unk_0x3A;          // 0x3A
  uint8_t State;              // 0x3C TMusicServer_State
  uint8_t unk_0x3D;           // 0x3D
  uint8_t PlayerState;        // 0x3C TMusicServer_State
  uint8_t unk_0x3F;           // 0x3F
  uint32_t unk_0x40;          // 0x40
  uint8_t unk_0x44;           // 0x44
  uint8_t unk_0x45;           // 0x45
  uint8_t unk_0x46;           // 0x46
  uint8_t unk_0x47;           // 0x47
  uint32_t unk_0x48;          // 0x48
  uint32_t unk_0x4C;          // 0x4C
  uint8_t unk_0x50;           // 0x50
  uint8_t unk_0x51;           // 0x51
  uint8_t unk_0x52;           // 0x52
  uint8_t unk_0x53;           // 0x53
  SUB_EXECUTE *CurrentTrack;  // 0x54
  TEXTID ErrorText;           // 0x58
  uint32_t unk_0x5C;          // 0x5C
  uint32_t unk_0x60;          // 0x60
  uint32_t unk_0x64;          // 0x64
  uint16_t unk_0x68;          // 0x68
  uint16_t unk_0x6A;          // 0x6A
  uint8_t unk_0x6C;           // 0x6C
  uint8_t unk_0x6D;           // 0x6D
  uint8_t unk_0x6E;           // 0x6E
  uint8_t unk_0x6F;           // 0x6F
  uint32_t unk_0x70;          // 0x70
  uint32_t unk_0x74;          // 0x74
  uint32_t unk_0x78;          // 0x78
  uint32_t unk_0x7C;          // 0x7C
  uint32_t unk_0x80;          // 0x80
  uint32_t unk_0x84;          // 0x84
  uint32_t unk_0x88;          // 0x88
  uint32_t unk_0x8C;          // 0x8C
  uint32_t unk_0x90;          // 0x90
  uint8_t unk_0x94;           // 0x94
  uint8_t unk_0x95;           // 0x95
  uint8_t unk_0x96;           // 0x96
  uint8_t unk_0x97;           // 0x97
  void *unk_0x98;             // 0x98
  uint32_t unk_0x9C;          // 0x9C
  uint32_t unk_0xA0;          // 0xA0
  uint32_t unk_0xA4;          // 0xA4
  uint32_t unk_0xA8;          // 0xA8
  uint32_t unk_0xAC;          // 0xAC

} MusicApplication_Book;
#endif

#endif
