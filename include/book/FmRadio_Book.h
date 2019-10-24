#ifndef _FMRADIO_BOOK_H_
#define _FMRADIO_BOOK_H_

#include "..\\include\types\IFMRadio_types.h"

typedef struct _DISP_OBJ_FMRADIO
{
  char dummy_1[0xF8];
  void* pointer_1;
  char dummy_2[0x10];
  void* pointer_2;
  char dummy_3[0x28];
  FUint16 key_pressed;
  char key_mode;
  char dummy_13B;  
  char dummy_4[0x8];
  color_t dummy_144;
  color_t dummy_148;
} DISP_OBJ_FMRADIO;

typedef struct FmRadio_Settings
{
  bool SpeakerMode;
  bool StereoReception;   // true=stereo //false=mono
  char unk_3;
  char unk_4;
} FmRadio_Settings;


typedef struct FmRadio_Channel
{
  FUint16 Frequency;
  FUint16 Unk;
  wchar_t Name[0x11] ;
} FmRadio_Channel;


typedef struct _FmRadio_Book : BOOK
{
  GUI* FmRadio_Gui;             // 0x18
  GUI* FmRadio_Gui_Submenu;     // 0x1C
  GUI* FmRadio_Gui_unk;         // 0x20
  char dummy_1[0x4];            // 0x24 
  char CurrentChannel;          // 0x28
  //char unk_c;                   // 0x29
  //Uint16_t CurrentFrequency;    // 0x2A
  FmRadio_ProgramInfo_t ProgramInfo;
  FUint16 unk_2C;               // 0x2C
  wchar_t ProgramServiceName[9];// 0x2E
  FUint16 unk_40;               // 0x40
  FmRadio_Channel Channel[20];  // 0x42
  FUint16 unk16;                // 0x33A
  int RadioVal;			// 0x33C
  int unk_1;			// 0x340
  int unk_2;			// 0x344
  void* pIAudioControl;		// 0x348
  int ID_34C;			// 0x34C
  void* pIFMRadio;              // 0x350
  int unk_4;			// 0x354
  void* pIAccessoryServer;	// 0x358
  FmRadio_Settings Settings;    // 0x35C
  char dummy_3[0x2];            // 0x360
  FUint16 TimerID;             // 0x362
  FUint16 FrequencySearch;     // 0x364
  FUint16 unk_5;               // 0x366
  char dummy_4[0x2E];           // 
  bool RDS;                     // 0x396
  bool AF;                      // 0x397
  char unk_398;                 // 0x398
}FmRadio_Book;

#endif
