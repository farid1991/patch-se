#ifndef _MAIN_H_
#define _MAIN_H_

#define MUSICWIDGET_PATH L"/usb/other/ZBin/Config/Widget/Music"

#define SECRET_CODES 6

#define MAX_ROW 1
#define MAX_COLOMN 5

#define DESTROY_GUI(gui)    \
  if (gui)                  \
  {                         \
    GUIObject_Destroy(gui); \
    gui = NULL;             \
  };

#define DESTROY_TEXTID(textid)            \
  if (textid != EMPTY_TEXTID) \
    TextID_Destroy(textid);

#define FREE_IMAGE(img) \
  if (img != NOIMAGE)   \
    ImageID_Free(img);

/*
??? ?? ?????? ??????. ??? ?? 760

typedef struct
{
  char unk[0x2];
  char Level;              //5-5 4-4 3-3 2-2 1-1 0-0
  char Type;               //01-gprs 2-edge/?? 1 ?? 2 ????? ? ????
  char TypeActive;         //2-Active 3-Not A?tive/ ?? 2 ?? 3 - usual
  char unk1[0x1];
  wchar_t CurrentIconID;   //??????? ??????
}0x4BB91582;

typedef struct
{
  char unk[0xC];
  char ChargeBatt;           //??????? ??????
  char unk1[0x1];
  wchar_t CurrentIconIDBatt; //??????? ??????
}0x4BB7A73C;

?? ???? ?2 ???
*/

enum
{
  StatusIndication_Operator3 = 0x0,
  StatusIndication_Operator1 = 0x1,
  StatusIndication_SearchFlight = 0x2,
  StatusIndication_Prof = 0x4,
  StatusIndication_Operator2 = 0x6,
  StatusIndication_NoSignal = 0x7,
  StatusIndication_Notes = 0x9,
  StatusIndication_BigClock = 0xB,
  StatusIndication_SmallClock = 0xC,
  StatusIndication_Date = 0xD,
  StatusIndication_Alarm = 0xE,
  StatusIndication_Timer = 0xF,
  StatusIndication_CallTime = 0x10
};

typedef struct
{
  IMAGEID imageID;
} STATUS_ITEM_LIST;

void InvalidateAll();
wchar_t *Get_Align(int align);

extern "C"
{
  void old_StatusRow_onRedraw(DISP_OBJ *disp_obj, int a, int b, int c);
  void old_Softkeys_onRedraw(DISP_OBJ *disp_obj, int a, int b, int c);
  void old_StatusIndication_onRedraw(DISP_OBJ *disp_obj, int a, int b, int c);
  int old_StatusIndication_onCreate(DISP_OBJ *disp_obj);
  void old_StatusIndication_onClose(DISP_OBJ *disp_obj);
  void old_MainInput_onKey(DISP_OBJ *disp_obj, int key, int unk, int repeat, int mode);

  bool New_SetTrayIcon(IMAGEID imageID, char mode);
  TEXTID INetworkServices_GetNetworkName();
  int CallInfo_Get(const int *SYNC, int CallType, CALLINFO *, signed char *error);

  int get_sys_uptime();
};

#endif
