#ifndef Main_H
#define Main_H

#define ENV_NAME "SleepmodeEnv"
#define ICONS_COUNT 8
#define TEXTID_CONST 0x78000000

#define REFRESH_TIME 1
#define BACKLIGHT_TIMEOUT 10
#define BACKLIGHT_MAX_TIMEOUT 86399
#define SECOND(tm) tm * 1000

#define SLEEPMODE_PATH L"/usb/other/Sleepmode"

#define FREE(mem) \
  if (mem)        \
    mfree(mem);

#define IMAGE_FREE(img) \
  if (img != NOIMAGE)   \
    ImageID_Free(img);  
  
#define TEXT_FREE(text)     \
  if (text != EMPTY_TEXTID) \
    TextID_Destroy(text);   

const int days[7] = {TEXTID_1, TEXTID_2, TEXTID_3, TEXTID_4, TEXTID_5, TEXTID_6, TEXTID_7};
const int missed_icons[ICONS_COUNT] = {
    KEYLOCK_SLEEPMODE_ICN + TEXTID_CONST,
    SILENT_SLEEPMODE_ICN + TEXTID_CONST,
    CALLS_MISSED_SLEEPMODE_ICN + TEXTID_CONST,
    SMS_SLEEPMODE_ICN + TEXTID_CONST,
    MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN + TEXTID_CONST,
    MMS_NEW_MESSAGE_SLEEPMODE_ICN + TEXTID_CONST,
    APPOINTMENT_REMINDER_SLEEPMODE_ICN + TEXTID_CONST,
    TASK_REMINDER_SLEEPMODE_ICN + TEXTID_CONST};

typedef struct
{
  unsigned int timer;
  wchar_t *lrcinfo;
} TimerList;

typedef struct SLEEPMODE_DATA
{
  DISP_OBJ *sleepmode;
  TEXTID text_id;
  IMAGEID Background;
  IMAGEID CoverArt;
  BOOL has_cover;
  u16 disp_width;
  u16 disp_height;
  u16 TimerID;
  u16 TimerLyric;
  TRACK_DESC *CurrentTrack;
  char *lrcbuf;
  TimerList *lrclist;
  int lrc_state;
  int current_offset;
  int total_offset;
  int offset_len;
} SLEEPMODE_DATA;

void *malloc(int size);
void mfree(void *mem);
SLEEPMODE_DATA *GetData();
void refresh_screen(DISP_OBJ *disp_obj);

extern "C"
{
  int SleepMode_OnCreate(DISP_OBJ *disp_obj);
  void SleepMode_OnClose(DISP_OBJ *disp_obj);
};

#endif
