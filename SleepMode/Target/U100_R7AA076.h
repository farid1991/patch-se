#ifndef U100_R7AA076
#define U100_R7AA076

#define A2
#define DB3350
#define REV1

#define CID_CDisplayManager (PUUID)0x15D5E628
#define IID_IDisplayManager (PUUID)0x15D5F7F8
#define CID_CUIImageManager (PUUID)0x15A1F9F4
#define IID_IUIImageManager (PUUID)0x15A560FC
#define CID_CUIFontManager (PUUID)0x15A1AB6C
#define IID_IUIFontManager (PUUID)0x15A5315C
#define CID_CTextRenderingManager (PUUID)0x15A21A50
#define IID_ITextRenderingManager (PUUID)0x15A58D64

#define MissedEvents (char *)0x4BC02B48

#define KEYLOCK_SLEEPMODE_ICN 0x1043
#define SILENT_SLEEPMODE_ICN 0x1C65
#define CALLS_MISSED_SLEEPMODE_ICN 0x47B
#define SMS_SLEEPMODE_ICN 0x16F2
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0x1682
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN 0x1C3E
#define TASK_REMINDER_SLEEPMODE_ICN 0x1AF6
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0x1E64

#define TEXTID_1 0x20E // Monday
#define TEXTID_2 0x290 // Tuesday 
#define TEXTID_3 0x2AC // Wednesday
#define TEXTID_4 0x281 // Thursday
#define TEXTID_5 0x1DB // Friday
#define TEXTID_6 0x250 // Saturday
#define TEXTID_7 0x27E // Sunday

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
#define UI_MEDIAPLAYER_UPDATE_EVENT 0x40EC

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE
#define KEY_NEXTTRACK 0x2C
#define KEY_PREVTRACK 0x2B
#define KEY_CAMERA_FOCUS 0x30
#define KEY_CAMERA_SHOT 0x31
#define KEY_GAME_A 0x4C
#define KEY_GAME_B 0x4D

#define KBD_SHORT_PRESS 0x0
#define KBD_LONG_PRESS 0x1
#define KBD_REPEAT 0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE 0x4

#define KEY_ESC 0x4
#define KEY_DEL 0x5
#define KEY_ENTER 0x8
#define KEY_UP 0x9
#define KEY_RIGHT 0xB
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_DIGITAL_0 0x13
#define KEY_STAR 0x1D
#define KEY_DIEZ 0x1E

#define ACTION_MP_FILE 0x8
#define ACTION_MP_SETTINGS 0xE
#define ACTION_MP_MANUALEQ 0x15

#define FONT_D_18B 0x112
#define FONT_D_24B 0x118
#define FONT_D_29B 0x11D
#define FONT_D_7R 0x7
#define FONT_E_100R 0x64
#define FONT_E_12B 0x10C
#define FONT_E_12R 0xC
#define FONT_E_14B 0x10E
#define FONT_E_14BI 0x30E
#define FONT_E_14I 0x20E
#define FONT_E_14R 0xE
#define FONT_E_16B 0x110
#define FONT_E_16BI 0x310
#define FONT_E_16I 0x210
#define FONT_E_16R 0x10
#define FONT_E_18B 0x112
#define FONT_E_18BI 0x312
#define FONT_E_18I 0x212
#define FONT_E_18R 0x12
#define FONT_E_20B 0x114
#define FONT_E_20BI 0x314
#define FONT_E_20I 0x214
#define FONT_E_20R 0x14
#define FONT_E_22B 0x116
#define FONT_E_22BI 0x316
#define FONT_E_22I 0x216
#define FONT_E_22R 0x16
#define FONT_E_24B 0x118
#define FONT_E_24BI 0x318
#define FONT_E_24I 0x218
#define FONT_E_24R 0x18
#define FONT_E_25B 0x119
#define FONT_E_25BI 0x319
#define FONT_E_25I 0x219
#define FONT_E_25R 0x19
#define FONT_E_30R 0x1E
#define FONT_E_30B 0x11E
#define FONT_E_36R 0x24
#define FONT_E_40R 0x28
#define FONT_E_60R 0x3C
#define FONT_E_60B 0x13C
#define FONT_E_75R 0x49
#define FONT_E_8R 0x8

#define FONT_TIME FONT_E_60B
#define FONT_DATE FONT_E_30B
#define FONT_DAY FONT_E_30B

#define MISSED_STEP 5
#define MISSED_Y 5
#define TIME_Y 115
#define DATE_Y 60
#define DAY_Y 230

#endif
