#ifndef _MAIN_H_
#define _MAIN_H_

#define FREE_GUI(gui) if (gui) { gui=GUIObject_Destroy(gui); gui = NULL; }
#define FREE_IMAGE(a) if(a!=NOIMAGE) ImageID_Free(a);
#define TEXT_FREE(text) if(text!=EMPTY_TEXTID) TextID_Destroy(text);

#define CONFIG_PATH L"/usb/other/ZBin/Config/FmRadio"

typedef enum {
  BACKGROUND_ICN = 0,       //0
  RDS_ACTIVE_ICN,           //1
  RDS_INACTIVE_ICN,         //2
  AF_ON_ICN,                //3
  AF_OFF_ICN,               //4
  MONO_ICN,                 //5
  STEREO_ICN,               //6
  FREQUENCY_INDICATOR_ICN,  //7
  ARROW_LEFT_IDLE_ICN,      //8
  ARROW_LEFT_MANUAL_ICN,    //9
  ARROW_LEFT_AUTOSEEK_ICN,  //10
  ARROW_RIGHT_IDLE_ICN,     //11
  ARROW_RIGHT_MANUAL_ICN,   //12
  ARROW_RIGHT_AUTOSEEK_ICN, //13
  ARROW_UP_IDLE_ICN,        //14
  ARROW_UP_ACTIVE_ICN,      //15
  ARROW_DOWN_IDLE_ICN,      //16
  ARROW_DOWN_ACTIVE_ICN,    //17
  LAST_ICN
}IMAGE_LIST;

void DrawImage(int x, int y, IMAGEID img);
#endif
