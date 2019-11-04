#ifndef _MUSICAPPLICATION_BOOK_H_
#define _MUSICAPPLICATION_BOOK_H_

#include "..\\include\classes\IMusicServer_Manager.h"
#include "..\\include\types\MusicServer_types.h"

typedef struct _X_IMAGEID
{
  char dummy[0x20];
  int ImageID;
}X_IMAGEID;

typedef struct _MUSICAPP_DISP_OBJ
{
  char dummy[0x300];
  X_IMAGEID *Shuffle_Image; 
  int unk_1;
  X_IMAGEID *State_Image; 
  X_IMAGEID *Eq_Image; 
  int unk_2; 
  X_IMAGEID *Loop_Image;
}MUSICAPP_DISP_OBJ;

// MusicApp_DispObj size 0x28c

typedef struct
{
  char dummy[0x24];
  TMusicServer_Time ElapsedTime;
}UI_MEDIAPLAYER_AUDIO_PLAYING_TIME;

typedef struct _UI_MEDIAPLAYER_NEW_TRACK_DATA
{
  char dummy_0x0[0x28];
  int track_id;
  TMusicServer_Time ElapsedTime;
  char dummy_0x1[0x24];
  TMusicServer_Time FullTime;
}UI_MEDIAPLAYER_NEW_TRACK_DATA;

typedef struct
{
  TBool Loop;
  TBool Random;
} MusicApp_PlayMode;

typedef struct _MusicApp_Settings
{
  TAscii unk_0;
  TAscii unk_1;
  TAscii unk_2;
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
  IMusicServer * pMusicServer;              // 0x18
  FUint32 subscriptionHandle;               // 0x1C
  GUI * Gui_NowPlaying;                     // 0x20
  GUI * Gui_PlayQueue;                      // 0x24
  int dummy_0x28;                           // 0x28
  GUI * Gui_submenu;                        // 0x2C
  int dummy_0x30;                           // 0x30
  int dummy_0x34;                           // 0x34
  wchar_t current_track_id;                 // 0x38
  wchar_t selected_track_id;                // 0x3A
  wchar_t tracks_count;                     // 0x3C
  char state;                               // 0x3E
  char state_2;
  char unk_1;
  bool loop;                                // 0x41
  bool random;                              // 0x42
  char unk;
  TMusicServer_Time ElapsedTime;            // 0x44
  char AreTracksInQueue;                    // 0x50 ???????
  char dummy_0x4[0x3];
  SUB_EXECUTE * sub_exec;                   // 0x54
  char dummy_0x5[0x4];
  TEXTID ErrorText;                         // 0x5C
  char dummy_0x6[0x13];
  char EQ_Preset;                           // 0x73
  int Level_ClearBass1;                     // 0x74
  int Level_ClearBass2;                     // 0x78
  int Level_400Hz;                          // 0x7C
  int Level_1kHz;                           // 0x80
  int Level_2_5kHz;                         // 0x84
  int Level_6_3kHz;                         // 0x88
  int Level_16kHz;                          // 0x8C
  void * somept1;                           // 0x90
  void * somept2;                           // 0x94
  char dummy_0x7[0x4C];
}MusicApplication_Book;

#else
typedef struct GUI Music_Gui;

typedef struct _MusicApplication_Book : BOOK
{
    IMusicServer* pMusicServer;	// 0x18
    Music_Gui* Gui_NowPlaying;  // 0x1C
    Music_Gui* Gui_PlayQueue;	// 0x20
    int unk_24;                 // 0x24
    Music_Gui* Gui_submenu;	// 0x28
    int unk_2C;                 // 0x2C
    Uint16_t current_track_id;	// 0x30
    Uint16_t selected_track_id;	// 0x32
    Uint16_t tracks_count;	// 0x34
    char state;			// 0x36
    char unk_37;                // 0x37
    char play_pause;            // 0x38 TMusicServer_State
    char unk_39;                // 0x39
    char cause;                 // 0x3A TMusicServer_Cause
    bool loop;                  // 0x3B TMusicServer_Settings
    bool random;                // 0x3C TMusicServer_Settings
    char unk_3D;                // 0x3D
    char unk_3E;                // 0x3E
    char unk_3F;                // 0x3F
    TMusicServer_Time Time;	// 0x40
    char unk_4C;                // 0x4C
    char status;                // 0x4D TMusicServer_Status
    char DisplayOrientation;    // 0x4E
    char unk_4F;                // 0x4F
    SUB_EXECUTE* sub_exec;      // 0x50
    char dummy_54;              // 0x54
    char dummy_55;              // 0x55
    char dummy_56;              // 0x56
    char dummy_57;              // 0x57
    TEXTID ErrorText;		// 0x58 TMusicServer_ErrorCode
    char unk_5C;                // 0x5C
    char unk_5D;                // 0x5C
    u16 unk_5E;                 // 0x5E
    char unk_60;                // 0x60
    char unk_61;                // 0x61
    u16 timerID;                // 0x62
    char dummy_9[0x2];          // 0x64
    char Eq_State;		// 0x66
    char dummy_67;	        // 0x67
    void* pointer_68;	        // 0x68
    void (*Func)(void*, void*); // 0x6C
    void* pointer_70;           // 0x70
    char unk_74;                // 0x74
    bool unk_75;                // 0x75
    char unk_76;                // 0x76
    char unk_77;                // 0x77
    MusicApp_Settings* Settings;// 0x78
    int unk_7C;                 // 0x7C
    char unk_80;                // 0x80
    char unk_81;                // 0x81
    char unk_82;                // 0x82
}MusicApplication_Book;

#endif

#endif
