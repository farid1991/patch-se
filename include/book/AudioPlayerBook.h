#ifndef _AudioPlayerBook_H_
#define _AudioPlayerBook_H_

typedef struct
{
    u16 unk;        // 0
    u16 unk2;       // 0x2
    wchar_t *fpath; // 0x4
    wchar_t *fname; // 0x8
    wchar_t *MIME;  // 0xC
    int fulltime;   // 0x10
} BOOK_PLAYER_TRACK_DESC;

#if defined(PNX5230)
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
    char EQ_State;               // 0x38
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
    BOOK_PLAYER_TRACK_DESC *dsc; // 0x74
    char dummy3[2];              // 0x78
    wchar_t pos2;                // 0x7A
    wchar_t pos3;                // 0x7C
    char dummy4[0x16];           // 0x7E
    int total_tracks;            // 0x94
} AudioPlayerBook;
#endif

#endif
