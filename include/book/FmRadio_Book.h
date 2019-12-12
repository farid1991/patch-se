#ifndef _FMRADIO_BOOK_H_
#define _FMRADIO_BOOK_H_

#include "..\\include\types\FMRadio_types.h"

typedef struct _DISP_OBJ_FMRADIO
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  char dummy_1[0x194];
#elif defined(DB3150_V1)
  char dummy_1[0x134];
#elif defined(DB2020)
  char dummy_1[0xD8];
#endif
  unsigned short key_pressed;
  char key_mode;
} DISP_OBJ_FMRADIO;

typedef struct FmRadio_Settings
{
  bool SpeakerMode;
  bool StereoReception;   // true=stereo //false=mono
  bool FmRadio_Settings_3;
  bool FmRadio_Settings_4;
} FmRadio_Settings;

typedef struct FmRadio_Channel
{
  FUint16 Frequency;
  FUint16 FmRadio_Channel;
  wchar_t Name[17] ;
} FmRadio_Channel;

typedef struct _FmRadio_Book : BOOK
{
  GUI* FmRadio_Gui;             // 0x18
  GUI* FmRadio_Gui_Submenu1;    // 0x1C
  GUI* FmRadio_Gui_Submenu2;    // 0x20
  int unk_0x24;                 // 0x24 
  char CurrentChannel;          // 0x28
  char unk_0x29;                // 0x29
  unsigned short CurrentFrequency;// 0x2A
  unsigned short unk_0x2C;      // 0x2C
  wchar_t ProgramServiceName[9];// 0x2E
  unsigned short unk_0x40;      // 0x40
  FmRadio_Channel Channel[20];  // 0x42
  unsigned short unk_0x33A;     // 0x33A
  int RadioVal;			// 0x33C
  int unk_0x340;                // 0x340
  int unk_0x344;                // 0x344
  void* pIAudioControl;         // 0x348
  int unk_0x34C;                // 0x34C
  void* pIFMRadio;              // 0x350
  int unk_0x354;                // 0x354
  void* pIAccessoryServer;	// 0x358
  FmRadio_Settings Settings;    // 0x35C
  unsigned short unk_0x362;     // 0x360
  unsigned short TimerID;       // 0x362
  unsigned short FrequencySearch;// 0x364
  unsigned short unk_0x366;     // 0x366
  char dummy_4[0x2E];           // 0x368
  bool RDS;                     // 0x396
  bool AF;                      // 0x397
  char unk_0x398;               // 0x398
} FmRadio_Book;

#endif
