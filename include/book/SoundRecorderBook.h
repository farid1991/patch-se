#ifndef _SOUNDRECORDERBOOK_H_
#define _SOUNDRECORDERBOOK_H_

typedef struct _SoundRecorderBook : BOOK
{
  char dummy[0x64];
}SoundRecorderBook;

typedef struct
{
  char type;
  char unk_type; //always 1
}RecorderType;

typedef struct
{
  int BookID;			// 0
  RecorderType	type;   // 0x4
  char dummy_1[0x3FA];  // 0x6
  char FNameFlag;		// 0x400
  char FPathFlag;		// 0x401
  char dummy_2;		    // 0x402
  char dummy_3;		    // 0x403
  int RecordSize;		// 0x404
  char dummy_4[0x4];    // 0x408
  char t[0x10];         // 0x40C
  char RecordTimeFlag;  // 0x41C
  char RecordOpenFlag;  // 0x41D
  u16  _unk;            // 0x41E
  int  RadioVal;        // 0x420
  TEXTID RecorderTitle; // 0x424
  char RecorderStyle;   // 0x428
}SOUND_RECORDER_DESC;

#endif
