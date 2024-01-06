#ifndef _Main_H_
#define _Main_H_

static const uint8_t vol_table_call[9] = {0, 12, 25, 37, 50, 62, 75, 87, 100};
static const uint8_t vol_table_media[16] = {0, 6, 13, 20, 26, 33, 40, 46, 53, 60, 66, 73, 80, 86, 93, 100};

extern "C"
{
  int VolumeControl_OnCreate(DISP_OBJ *disp);
  void VolumeControl_OnRedraw(DISP_OBJ *disp, int a, int b, int c);
  void VolumeControl_OnClose(DISP_OBJ *disp);

  int pg_VolumeControl_Active_EnterEvent(void *, BOOK *);
  int pg_VolumeControl_Active_ExitEvent(void *, BOOK *);
};

#define FREE_GUI(gui)       \
  if (gui)                  \
  {                         \
    GUIObject_Destroy(gui); \
    gui = NULL;             \
  };

#define FREE_IMAGE(img) \
  if (img != NOIMAGE)   \
    ImageID_Free(img);

#define TEXT_FREE(text)     \
  if (text != EMPTY_TEXTID) \
    TextID_Destroy(text);

#define EMP_NAME "V_EMP"

enum VOLUME_IMAGE
{
  BACKGROUND_IMG,
  CALL_IMG,
  MUSIC_IMG,
  OFF_IMG,
  BLOB_IMG,
  LAST_IMG
};

typedef struct _CPATH
{
  wchar_t path[256];
} CPATH;

typedef struct _COLOR
{
  unsigned int font;
  unsigned int border;
} COLOR;

typedef struct _SkinConfig
{
  BOOL Anim;
  BOOL Manual;
  unsigned int AnimationStyle;
  POINT text_pos;
  int Font_size;
  unsigned int text_color;
  BOOL TextEnable;
  BOOL PercentageEnable;
  POINT bg_image;
  POINT state_image;
  BOOL EnableProgressbar;
  RECT progressbar;
  BOOL EnableB;
  unsigned int progressbar_bg_color;
  unsigned int progressbar_elapsed_color;
  int AnimID[4];
} SkinConfig;

typedef struct _IMG
{
  IMAGEID ID;
  u16 Handle;
} IMG;

typedef struct _VolumeFunction
{
  SkinConfig Config;
  TEXTID vol_textid;
  wchar_t buffer[32];
  wchar_t ConfigPath[256];
  bool IsJava;
  IMG Vol_Image[LAST_IMG];
} Volume_Function;

#endif
