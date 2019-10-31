#ifndef _GUI_IMAGEVIEWER_H_
#define _GUI_IMAGEVIEWER_H_

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#define SEG1_START 0x0001
#define SEG1_END 0x0F5E-1
#define SEG2_START 0x11A9
#define SEG2_END 0x127D-1
#define SEG3_START 0x209B
#define SEG3_END 0x209C-1
#define SEG4_START 0xE541
#define SEG4_END 0xE555-1
#define SEG5_START 0xF0FE
#define SEG5_END 0xF903-1
#else
#define SEG1_START 0xE541
#define SEG1_END 0xE63E-1
#define SEG2_START 0xE801
#define SEG2_END 0xE900-1
#define SEG3_START 0xEA01
#define SEG3_END 0xEEB9-1
#define SEG4_START 0xF2B9
#define SEG4_END 0xF500-1
#define SEG5_START 0xF6FF
#define SEG5_END 0xF900-1
#endif

#define FREE_GUI(gui) if (gui) { gui=GUIObject_Destroy(gui); gui = NULL; };
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a);
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

GUI* Create_ImageIDViewer(BOOK* book);

typedef struct DISP_OBJ_IMG : DISP_OBJ
{
  TEXTID textid_imgoffset;
  TEXTID textid_imgsize;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int img;
#else
  IMAGEID img;
#endif
  color_t color;
  color_t color_text;
  RECT rect;
  int height;
  int width;
  bool col_set;
}DISP_OBJ_IMG;

#endif
