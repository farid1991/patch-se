/*$T indentinput.h GC 1.140 08/16/11 02:54:15 */


/*$6
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

extern "C"
{
  //=========================
  int oldonCreateStatus(DISP_OBJ * db);
  int oldCreateIndication(DISP_OBJ * db);
  int oldCreateSoftkey(DISP_OBJ * db);
  void oldonExitStatus(DISP_OBJ * db);
  void oldRedrawStatus(DISP_OBJ *dobj,int a ,int b,int c);
  void oldRedrawIndication(DISP_OBJ *dobj,int a ,int b,int c);
  void oldRedrawSoftkey(DISP_OBJ *dobj,int a ,int b,int c);
  void oldMainInputOnClose(DISP_OBJ*db);
  void oldMainInputOnKey(DISP_OBJ*db, int scan_code, int unk, int repeat_num, int key_mode);
  
  int DEFAULT_VOLUMEONCREATE(DISP_OBJ*disp);
  void DEFAULT_VOLUMEONREDRAW(DISP_OBJ*disp,int a,int b,int c);
  void DEFAULT_VOLUMEONDESTROY(DISP_OBJ*disp);
  int DEFAULT_VOLUMEONPAGENTER(void*,BOOK*);
  int DEFAULT_VOLUMEONPAGEXIT(void*,BOOK*);
};


#define DELETE(x) \
	mfree(x); \
	x = 0
#define VOLUME_VAR	"vol"
#define UNDEFINED	0xFFFFFFFF

typedef struct _CPATH
{
  wchar_t path[256];
}CPATH;

typedef struct _COLOR
{
  unsigned int font;
  unsigned int border;
} COLOR;

typedef struct _SkinConfig
{
  BOOL	        Anim;
  BOOL		Manual;
  unsigned int	AnimationStyle;
  POINT		text_pos;
  int		Font_size;
  unsigned int	text_color;
  BOOL		FontEnable;
  BOOL		PercentageEnable;
  POINT		bg_image;
  POINT		state_image;
  BOOL		EnableProgressbar;
  RECT		progressbar;
  BOOL		EnableB;
  unsigned int	progressbar_bg_color;
  unsigned int	progressbar_elapsed_color;
  int		AnimID[4];
} SkinConfig;

typedef struct _VolumeFunction
{
  IMAGEID	image[5];
  IMAGEID	State;
  int		blob_w;
  int		blob_h;
  SkinConfig	Config;
  wchar_t	cpath[256];
  //GC		*gc;
  BOOL IsJava;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  IFont		*pFont;
#endif
}VolumeFunction;

VolumeFunction *Get_VolumeFunction();
void DrawProgressBar(VolumeFunction *Data, int value, int max_value, RECT rect, int Bcolor, int Ecolor, int);
IMAGEID VolState_GetImageID(VolumeFunction *Data, int level, int book);

void DrawShadowStr (
                    int StrID,
                    int CEN,
                    int XPos,
                    int YPos,
                    int MaxXPos,
                    int MaxYPos,
                    int borderColor,
                    int NormalColor
                      );

void DrawHighlightStrV2(
                        int StrID,
                        int CEN,
                        int XPos,
                        int YPos,
                        int MaxXPos,
                        int MaxYPos,
                        int borderColor,
                        int NormalColor
                          );

void DrawHighlightStrV1(
                        int StrID,
                        int CEN,
                        int XPos,
                        int YPos,
                        int MaxXPos,
                        int MaxYPos,
                        int borderColor,
                        int NormalColor
                          );

void DrawStr(
             int StrID,
             int CEN,
             int XPos,
             int YPos,
             int MaxXPos,
             int MaxYPos,
             int borderColor,
             int NormalColor
               );
