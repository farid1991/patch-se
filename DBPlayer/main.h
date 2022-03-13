#ifndef _MAIN_H_
#define _MAIN_H_

//#define IMEI_CHECK_ON

const int IMEI = 93;

/*
   - -    --  - -
35638503-386525-9; 108 - E1kolyan C510_R1FA035_Orange
35638503-573139-2; 87 - Vov4ik C510_R1FA035_Orange
35402203-491105-3; 60 - D3mon W995_R1GA026
35467703-224195-9; 99 - Velikii C901_R1GA028
35204503-446262-1; 54 - MrGraL C510_R1HA035
35681303-142773-1; 63 - G@S J105_R1HA035
01224900-415550-2; 57 - .:DOC:. J105_R1HA035
35681303-277705-0; 90 - gordan33-92 J105_R1HA035
35467703-238133-4; 93 - Hypnotic C901_R1GA028
   - -    --  - -
*/

#define FREE(b) \
  if (b)        \
    mfree(b);

#define TEXTFREE(a)      \
  if (a != EMPTY_TEXTID) \
    TextID_Destroy(a);

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define FONTHEIGHT(f) (f & 0xFF)

#define ELF_PATH L"/usb/other/ZBin"
#define ELF_PATH_ZBIN L"/usb/other/ZBin/MusicTagger.elf"

static const char GuiName_DBPlayer[] = "GUI_DBPlayer";
typedef struct GUI GUI_DBPLAYER;

enum DBPLAYER_TAB
{
  PLAYER_TAB,
  LYRIC_TAB
};

typedef struct
{
  unsigned int timer;
  wchar_t *lrcinfo;
} TimerList;
typedef struct _DISP_OBJ_DBP : DISP_OBJ
{
  TEXTID artist;
  TEXTID title;
  TEXTID album;
  TEXTID year;
  TEXTID genre;
  TEXTID ext;
  TEXTID time_f;
  TEXTID time_e;
  TEXTID time_r;
  TEXTID bitrate;
  TEXTID samplerate;
  TEXTID audiooutput;
  TEXTID buf_text;
  int media_volume;
  int cstep;
  int disp_width;
  int disp_height;
  char *lrcbuf;
  TimerList *lrclist;
  u16 TimerLyric;
  int lrc_state;
  int current_offset;
  int total_offset;
  int offset_len;
  int tab;
} DISP_OBJ_DBP;

enum DBP_ACTION_ID
{
  ACTION_PAUSE,
  ACTION_PLAY,
  ACTION_STOP,
  ACTION_SETTINGS,
#ifndef DB3350
  ACTION_TAG,
#endif
  ACTION_TIME,
  ACTION_MINIMISE,
  ACTION_LAST
};

void *malloc(int size);
void mfree(void *mem);

extern "C"
{
  int pg_Sound_Run__0x17FC(void *pMMEData, BOOK *book);
}
#endif
