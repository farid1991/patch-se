#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define NIL_EVENT               0
#define CANCEL_EVENT            4
#define PAGE_ENTER_EVENT        0xE
#define PAGE_EXIT_EVENT         0xF
#define RETURN_TO_STANDBY_EVENT 0x841

#define ACTION_BACK             0xFC0
#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_ACCEPT           0xFAC   
  
#define KEY_1	0x14
#define KEY_2	0x15
#define KEY_3	0x16
#define KEY_4	0x17
#define KEY_5	0x18
#define KEY_6	0x19
#define KEY_7	0x1A
#define KEY_8	0x1B
#define KEY_9	0x1C
#define KEY_0	0x1D

#define KEY_STAR 0x1D
#define KEY_DIEZ 0x1E

#define KEY_UP		0x9
#define KEY_DOWN	0xD
#define KEY_LEFT 	0xF
#define KEY_RIGHT 	0xB

#define KBD_SHORT_PRESS   0x0
#define KBD_LONG_PRESS    0x1
#define KBD_REPEAT        0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE  0x4

#define ACTION_VIEW 0x34
#define ACTION_REPLY 0x3B
#define ACTION_FORWARD 0x3D
#define ACTION_DETAIL  0x44
#define ACTION_CALL 0x9F
#define ACTION_VIDEOCALL 0xA0

#endif
#endif
