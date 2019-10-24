#define BOOK_NAME                     "VS_Book"       
#define ImagePath                     L"/usb/other/ZBin/Config/VolumeSettings"
#define CfgName                       L"VolumeSettings.ini"

typedef struct _MyBOOK : BOOK
{
  GUI* Gui;
}MyBOOK;

typedef struct
{
  IMAGEID ImageID;
  u16 ImageHandle;
}IMG;

#define img_count 8

typedef struct _MyDISP_OBJ : DISP_OBJ
{
  char Media;
  char Ring;
  char Call;
  char isData;
  int cursor;
  IMG Images[img_count];
  FILE_DATA * data;
}MyDISP_OBJ;


__thumb void * malloc (int size);
__thumb void mfree (void * mem);

extern "C"
{
  void onBackPressed(BOOK *bk, GUI* gui);
  void onLongBackPressed(BOOK *bk, GUI* gui);
  void onCloseBook( BOOK* );
  int OnStandyEvent(void*,BOOK*);
  void StandartRingMenu(DYNAMIC_MENU_ELEMENT* DME);
};
