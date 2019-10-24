#ifndef _VOLUMECONTROLLER_BOOK_H_
#define _VOLUMECONTROLLER_BOOK_H_

typedef struct _VC_GUI
{
  DISP_OBJ* disp;	// 0
  void* vcgui_b;	// 4
  void* vcgui_c;	// 8
  char	dummy_1[0x4];	// C
  char	dummy_2[0x4];	//10
  char	dummy_3[0x4];	//14
  char	dummy_4[0x4];	//18
  void* vcgui_d;	//1C
  void* vcgui_e;	//20
  void* vcgui_f;	//28
  void* vcgui_g;	//2C
  char  dummy_5[0x4];	//30
  char  dummy_6[0x4];	//34
}VC_GUI;

typedef struct _VolumeControllerBook : BOOK
{
  VC_GUI* vc_gui;   // 0x18
  char	  dummy0[4];// 0x1C
  char	  dummy1[4];// 0x20
  void*	  dummy2;   // 0x24
  void*	  dummy3;   // 0x28
  char	  level;    // 0x2C
} VolumeControllerBook;

#endif
