#ifndef S700_R3M008
#define S700_R3M008

#define A1
#define DB2010

#define SYNC_PTR ((int**)0x4410C9B0)
#define SYNC (*SYNC_PTR)

#define SOUND_PATH (wchar_t*)0x44210330
#define SETTINGS_PATH (wchar_t*)0x4420FBA4

#endif
