#ifndef _Main_H_
#define _Main_H_

#define EMP_NAME "SLEEPMODE"
#define ICONS_COUNT 8
#define TEXTID_CONST 0x78000000

#define SLEEPMODE_PATH L"/usb/other/Sleepmode"

#define IMAGE_FREE(img)             \
  if (img != NOIMAGE)               \
  {                                 \
    ImageID_Free(img);              \
  }

#define TEXT_FREE(text)               \
  if (text != EMPTY_TEXTID)           \
  {                                   \
    TextID_Destroy(text);             \
  }

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

typedef struct SLEEPMODE_DATA
{
  DISP_OBJ *ScrScv;
  TEXTID text_id;
  IMAGEID Background;
  IMAGEID CoverArt;
  BOOL HasCover;
  u16 DispWidth;
  u16 TimerID;
  TRACK_DESC* CurrentTrack; 
} SLEEPMODE_DATA;

void *malloc(int size);
void mfree(void *mem);

extern "C"
{
  int SleepMode_OnCreate(DISP_OBJ *disp_obj);
  void SleepMode_OnClose(DISP_OBJ *disp_obj);
};

#endif
