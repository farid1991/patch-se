#ifndef _AUDIOPLAYERBOOK_H_
#define _AUDIOPLAYERBOOK_H_

typedef struct
{
  char dummy6[0x70];
  TEXTID Artist;        // 
  TEXTID Title;         // 
  TEXTID Album;         // 
  TEXTID FullTime;      // 
  TEXTID unk_t1;        // 
  TEXTID unk_t2;        // 
  TEXTID CurrentTime;   // 
}MM_INFO;

typedef  struct
{
  char dummy[0xB6];     // 0
  IMAGEID imageID;      // 0xB6
  char dummy2[0xA];     // 0xB8
  char status;          // 0xC2
  char dummy3[0x11];    // 0xC3
  IMAGEID artist_icn;   // 0xD4
  IMAGEID title_icn;    // 0xD6
  IMAGEID album_icn;    // 0xD8
  char dummy4[0x74];    // 0xDA
  IMAGEID prev_icn;     // 0x14E
  IMAGEID prev_icn2;    // 0x150
  IMAGEID next_icn;     // 0x152
  IMAGEID next_icn2;    // 0x154
  IMAGEID play_icn;     // 0x156
  IMAGEID stop_icn;     // 0x158
  char dummy5[0x42];    // 0x15A
  MM_INFO mm_info;
} DISP_OBJ_WALKMAN;

typedef struct
{
  wchar_t Title[1024];
  wchar_t Album[1024];
  wchar_t Artist[1024];
  wchar_t Year[1024];
  wchar_t Genre[1024];
  int TrackNum;
  IMAGEID ImageID;
} METADATA;

typedef struct
{
  char dummy[0x24];
  int hour;
  int min;
  int sec;
} PLAY_TIME;

typedef struct
{
  wchar_t *path;
  wchar_t *name;
  int fulltime;
  int pos;
  int tracks_count;
} TRACK_DESC;

typedef struct
{
  u16 unk;
  u16 unk2;
  wchar_t *path;
  wchar_t *name;
  wchar_t *MIME;
  int fulltime;
} BOOK_PLAYER_TRACK_DESC;

typedef struct
{
  IMAGEID ImageID;
} IMG_DESC;


#ifdef DB2020
typedef struct _AudioPlayerBook : BOOK
{
  char dummy1[0x4];       // 0x18
  GUI *NowPlaying;        // 0x1C
  GUI *SubMenu;           // 0x20
  char dummy2[0x68];      // 0x24
  int TotalTrack;         // 0x8C
  char dummy3[0x8];       // 0x90
  char RepeatMode;        // 0x98
  char ShuffleMode;       // 0x99
} AudioPlayerBook;

#elif DB2010
typedef struct
{
  char dummy[0x5C];
  u16 pos;
  u16 unk1;
  char dummy2[0x8];
  int time;
  BOOK_PLAYER_TRACK_DESC *dsc;
  u16 unk2;
  u16 pos2;
  char unk3[0xC];
  u16 tracks_count;
  u16 unk4;
  u16 tracks_count2;
} AudioPlayerBook;
#endif

#endif
