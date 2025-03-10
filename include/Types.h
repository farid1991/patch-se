#ifndef _TYPES_H
#define _TYPES_H

// base types and constants ----------------------------------------------------

typedef unsigned short u16;
typedef int BOOL;
typedef unsigned long LRESULT;
typedef int jmp_buf[11];

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;

typedef uint32_t size_t;
typedef uint32_t time_t;
typedef uint32_t color_t;

struct BOOK;
struct GUI;
struct DISP_OBJ;

#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif

#ifndef __cplusplus
typedef unsigned long LPARAM;
#else
class LPARAM
{
	unsigned long data;

public:
	LPARAM(int a) { data = a; }
	LPARAM(void *a) { data = reinterpret_cast<unsigned long>(a); }
	operator int() { return data; }
	operator void *() { return reinterpret_cast<void *>(data); }
};
#endif

typedef struct DATE
{
	u16 year;
	char mon;
	char day;
} DATE;

typedef struct WEEK
{
	char type;
	char days[7];
} WEEK;

typedef struct TIME
{
	char hour;
	char min;
	char sec;
	char msec;
} TIME;

typedef struct DATETIME
{
	DATE date;
	TIME time;
} DATETIME;

typedef struct
{
	char dummy[0x8];
	TIME time;
} CALLINFO;

typedef struct POINT
{
	int x;
	int y;
} POINT;

typedef struct POINT3D
{
	int x;
	int y;
	int z;
} POINT3D;

typedef struct RECT
{
	u16 x1;
	u16 x2;
	u16 y1;
	u16 y2;
} RECT;

#ifndef _NULL
#define _NULL 0
#endif
#ifndef NULL
#define NULL _NULL
#endif

#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0

// if( GetChipID( ) &CHIPID_MASK == CHIPID_DB... )
#define CHIPID_MASK 0xFE00
#define CHIPID_DB2000 0x7000
#define CHIPID_DB2010 0x8000
#define CHIPID_DB2020 0x9800
#define CHIPID_PNX5230 0xD000
#define CHIPID_DB3150 0xC800
#define CHIPID_DB3200 0xD800
#define CHIPID_DB3210 0xE800
#define CHIPID_DB3350 0xF000

#define MAXELEMS(x) (sizeof(x) / sizeof(x[0]))

#ifdef __cplusplus
template <typename BASETYPE, typename CHILDTYPE>
void INHERITANCECHECK()
{
	if (static_cast<BASETYPE *>(0) == static_cast<CHILDTYPE *>(0))
		;
}
#endif

// text ------------------------------------------------------------------------

typedef int TEXTID;

typedef struct TEXTID_DATA
{
	wchar_t lenght;
	char encoding;
	void *ptr;
} TEXTID_DATA;

typedef enum TEXT_ENCODING
{
	ENC_UCS2 = 0,
	ENC_GSM = 1,
	ENC_BCD = 2,
	ENC_FILE = 3,
	ENC_TEXTID = 5,
	ENC_LAT1 = 6,
	ENC_UT = 8,
	ENC_UTTF = 9,
} TEXT_ENCODING;

#define TEXTID_ANY_LEN 0xFFFF
#define EMPTY_TEXTID 0x6FFFFFFF

#define TEXT(__STR__) L##__STR__
#define _T(__STR__) L##__STR__
#define STR(__STR__) TextID_Create(_T(__STR__), ENC_UCS2, TEXTID_ANY_LEN)

typedef enum
{
	AlignLeft = 0,
	AlignRight,
	AlignCenter,
	Alignment_LeftDynamic,
	Alignment_RightDynamic
} UITextAlignment_t;

// images ----------------------------------------------------------------------
typedef wchar_t IMAGEID;

#define NOIMAGE 0xFFFF

// OSE -------------------------------------------------------------------------
union SIGNAL;

typedef unsigned char OSPRIORITY;
typedef unsigned char OSBOOLEAN;

typedef unsigned short OSVECTOR;

typedef unsigned long PROCESS;
typedef unsigned long SIGSELECT;
typedef unsigned long OSBUFSIZE;
typedef unsigned long OSUSER;
typedef unsigned long OSERRCODE;
typedef unsigned long OSADDRESS;
typedef unsigned long OSTIME;
typedef unsigned long OSTICK;
typedef unsigned long OSATTREF;
typedef unsigned long OSSEGMENT;

typedef signed long OSFSEMVAL;
typedef signed long OSSEMVAL;

typedef void(OSENTRYPOINT)(void);

typedef OSADDRESS(OSERRH)(OSBOOLEAN, OSERRCODE, OSERRCODE);

typedef enum PROCESS_TYPE
{
	OS_PRI_PROC = 0,
	OS_BG_PROC = 64,
	OS_INT_PROC = 128,
	OS_TI_PROC = 256,
	OS_PHANTOM = 512,
	OS_BLOCK = 1024,
	OS_ZOOMBIE = 2048,
	OS_ILLEGAL = 4096
} PROCESS_TYPE;

#define OS_PROCESS(x) __interwork void x(void)

// list ------------------------------------------------------------------------

typedef struct LIST
{
	u16 unk;
	u16 FirstFree;
	void **listdata;
} LIST;

typedef int (*LISTFINDCALLBACK)(void *listitem, void *itemtofind);

#define LIST_ERROR 0xFFFF

#ifdef __cplusplus
template <typename T, typename T2>
LISTFINDCALLBACK MKLISTFINDCALLBACK(int (*param)(T, T2))
{
	return reinterpret_cast<LISTFINDCALLBACK>(param);
}
#else
#define MKLISTFINDCALLBACK(fn) (LISTFINDCALLBACK) fn
#endif

#define LIST_FIND(lst, itemtofind, cmp_proc) List_Find(lst, (void *)itemtofind, MKLISTFINDCALLBACK(cmp_proc))

// disp -------------------------------------------------------------------------

typedef int (*DISP_OBJ_ONCREATE_METHOD)(DISP_OBJ *);
typedef void (*DISP_OBJ_ONCLOSE_METHOD)(DISP_OBJ *);
typedef void (*DISP_OBJ_ONREDRAW_METHOD)(DISP_OBJ *, int, int, int);
typedef void (*DISP_OBJ_ONKEY_METHOD)(DISP_OBJ *, int scan_code, int count, int repeat_num, int key_mode);
typedef void (*DISP_OBJ_ONCONFIG_METHOD)(DISP_OBJ *, int unk, int DisplayWidth, int DisplayHeight);
typedef void (*DISP_OBJ_ONLAYOUT_METHOD)(DISP_OBJ *, void *layoutstruct);
typedef void (*DISP_OBJ_METHOD)(DISP_OBJ *);

typedef struct DISP_DESC
{
	char *name;
	u16 DataSize;
	u16 field_6;
	DISP_OBJ_METHOD Constructor;
	DISP_OBJ_ONCREATE_METHOD onCreate;
	DISP_OBJ_ONCLOSE_METHOD onClose;
	DISP_OBJ_ONREDRAW_METHOD onRedraw;
	DISP_OBJ_METHOD onRefresh;
	DISP_OBJ_METHOD field_1C;
	DISP_OBJ_ONKEY_METHOD onKey;
	DISP_OBJ_METHOD field_24;
	DISP_OBJ_METHOD field_28;
	DISP_OBJ_ONLAYOUT_METHOD onLayout;
	DISP_OBJ_ONCONFIG_METHOD onConfig;
	DISP_OBJ_METHOD field_34;
	DISP_OBJ_METHOD field_38;
	DISP_OBJ_METHOD field_39;
	DISP_OBJ_METHOD field_3A;
	char field_3B;
} DISP_DESC;

#if defined(DB2000)
typedef struct DISP_OBJ // For DB2000 platform
{
	char dummy[0xC4];
} DISP_OBJ;

#elif defined(DB2010)
#ifdef OLD_PLAYER
typedef struct DISP_OBJ // For OLD DB2010 platform
{
	char dummy[0xBC];
} DISP_OBJ;
#else
typedef struct DISP_OBJ // For DB201X platform
{
	char dummy[0xB8];
} DISP_OBJ;
#endif

#elif defined(DB2020) || defined(PNX5230)
typedef struct DISP_OBJ // For DB2020 and PNX5230 platform
{
	char dummy[0xB4];
} DISP_OBJ;

#elif defined(DB3150v1)
typedef struct DISP_OBJ // For DB3150v1 platform
{
	char dummy[0x110];
} DISP_OBJ;

#elif defined(DB3150v2)
typedef struct DISP_OBJ // For DB3150v2 platform
{
	char dummy[0x120];
} DISP_OBJ;

#elif defined(DB3200)
typedef struct DISP_OBJ // For DB3200 platform
{
	char dummy[0x168];
} DISP_OBJ;

#elif defined(DB3210)
typedef struct DISP_OBJ // For DB3210 platform
{
	char dummy[0x16C];
} DISP_OBJ;

#else
typedef struct DISP_OBJ // For DB3350 platform
{
	char dummy[0x200];
} DISP_OBJ;
#endif

#define EMPTY_REDRAW_METHOD (DISP_OBJ_ONREDRAW_METHOD) - 1

// gui -------------------------------------------------------------------------

typedef struct GUI
{
	char dummy[0x90];
} GUI;

// 2do: remove these types
typedef struct GUI GUI_LIST;
typedef struct GUI GUI_TABMENUBAR;
typedef struct GUI GUI_ONEOFMANY;
typedef struct GUI GUI_NOFMANY;
typedef struct GUI GUI_FEEDBACK;

typedef enum UI_OverlayStyle_t
{
	UI_OverlayStyle_NotDefined = 0,
	UI_OverlayStyle_Default,			  // Use original frame settings
	UI_OverlayStyle_FullScreen,			  // Fullscreen
	UI_OverlayStyle_FullScreenNoStatus,	  // Fullscreen with no statusRow
	UI_OverlayStyle_TrueFullScreen,		  // True fullscreen without softkeys and statusrow
	UI_OverlayStyle_InternalFrameSmall,	  // Fullscreen with small internal frame
	UI_OverlayStyle_InternalFrameLarge,	  // Fullscreen with large internal frame
	UI_OverlayStyle_InternalFrameOutput,  // Informationtext style
	UI_OverlayStyle_PopupFrame,			  // Popup with SW rendered frame
	UI_OverlayStyle_PopupNoFrame,		  // Transparent popup window. Default popup style.
	UI_OverlayStyle_FullScreenNoSoftkeys, // Fullscreen without softkeys but with status row
	UI_OverlayStyle_Last
} UI_OverlayStyle_t;

typedef enum UI_TitleMode_t
{
	UI_TitleMode_Uninitated = 0, // Uninitiated
	UI_TitleMode_None,			 // Show no title
	UI_TitleMode_Normal,		 // Normal title size
	UI_TitleMode_Small,			 // Small title
	UI_TitleMode_Tab,			 // Show tabs instead of title.
	UI_TitleMode_Large,			 // Large two row title( different fonts for 1:st and 2:nd line )
	UI_TitleMode_Desktop,		 // Only for desktop title. Will be removed after hb107.
	UI_TitleMode_Last
} UI_TitleMode_t;

// GUIObject_SetZOrder
typedef enum GuiObjectZOrder_t
{
	GuiObjectZOrderAbove = 0, ///< Sets the GUI Z-order to Above
	GuiObjectZOrderBelow,	  ///< Sets the GUI Z-order to Below
	GuiObjectZOrderTop,		  ///< Sets the GUI Z-order to Top
	GuiObjectZOrderBottom,	  ///< Sets the GUI Z-order to Bottom
} GuiObjectZOrder_t;

/**
 * Display
 *
 * @param UIDisplay_Main    Main display
 * @param UIDisplay_Second  Second display. Used on clam phones
 * @param UIDisplay_Last    End
 */
typedef enum UI_Display_t
{
	UIDisplay_Main = 0,
	UIDisplay_Second,
	UIDisplay_TVOut,
	UIDisplay_Last
} UI_Display_t;

/**
 * Backlight mode.
 *
 * @param UIBacklightMode_On        Always on
 * @param UIBacklightMode_Off       Always off
 * @param UIBacklightMode_Automatic Automatic
 * @param UIBacklightMode_LowOff    Automatic with low instead of off
 * @param UIBacklightMode_LowOn     Automatic with low instead of on
 */
typedef enum
{
	UIBacklightMode_On,
	UIBacklightMode_Off,
	UIBacklightMode_Automatic,
	UIBacklightMode_LowOff,
	UIBacklightMode_LowOn
} UIBacklightMode_t;

/**
 * Backlight status.
 *
 * @param UIBacklightStatus_On    Backlight is on
 * @param UIBacklightStatus_Off   Backlight is off
 * @param UIBacklightStatus_Blink Backlight is blinking
 * @param UIBacklightStatus_Low   Backlight is on with low intensity
 */
typedef enum
{
	UIBacklightStatus_On,
	UIBacklightStatus_Off,
	UIBacklightStatus_Blink,
	UIBacklightStatus_Low
} UIBacklightStatus_t;

/**
 * Display Orientation
 *
 * @param UIDisplayOrientationMode_Vertical           Vertical orientation
 * @param UIDisplayOrientationMode_Horizontal         Horizontal orientation
 * @param UIDisplayOrientationMode_HorizontalReversed Reversed horizontal orientation
 * @param UIDisplayOrientationMode_Last               End
 */
typedef enum
{
	UIDisplayOrientationMode_Vertical = 0,
	UIDisplayOrientationMode_Horizontal,
	UIDisplayOrientationMode_HorizontalReversed,
	UIDisplayOrientationMode_Last
} UIDisplayOrientationMode_t;

/**
 * Theme colors.
 *
 */
typedef enum
{
	UIThemeColor_BrowserUnderline,
	UIThemeColor_BrowserTableBorder,
	UIThemeColor_CalendarWeekendText,
	UIThemeColor_CalendarWeekendHighlight,
	UIThemeColor_InputScrollBar,
	UIThemeColor_InputText,
	UIThemeColor_InputOverlay,
	UIThemeColor_InputOverlayHighlight,
	UIThemeColor_InputOverlayFrame,
	UIThemeColor_HomeScreen,
	UIThemeColor_HomeScreenNonSel,
	UIThemeColor_HomeScreenTab,
	UIThemeColor_HomeScreenTabNonSel,
	UIThemeColor_HomeScreenTabSel,
	UIThemeColor_HomeScreenTabText,
	UIThemeColor_HomeScreenHighlight,
	UIThemeColor_HomeScreenHighlightNonSel,
	UIThemeColor_HomeScreenScrollBar,
	UIThemeColor_HomeScreenFrame,
	UIThemeColor_Morelist,
	UIThemeColor_MorelistNonSel,
	UIThemeColor_MorelistHighlight,
	UIThemeColor_MorelistHighlightNonSel,
	UIThemeColor_MorelistScrollBar,
	UIThemeColor_MorelistFrame,
	UIThemeColor_TopMenu,
	UIThemeColor_Highlight,
	UIThemeColor_HighlightNonSel,
	UIThemeColor_NonSel,
	UIThemeColor_OverlayFrame,
	UIThemeColor_OverlayHighlight,
	UIThemeColor_OverlayHighlightNonSel,
	UIThemeColor_OverlayNonSel,
	UIThemeColor_OverlayScrollBar,
	UIThemeColor_OverlayText,
	UIThemeColor_OverlayTitle,
	UIThemeColor_ScrollBar,
	UIThemeColor_OverlayDim,
	UIThemeColor_SoftkeyNonSel,
	UIThemeColor_SoftkeyBarLeft,
	UIThemeColor_SoftkeyBarRight,
	UIThemeColor_SoftkeyTextLeftPressed,
	UIThemeColor_SoftkeyTextRightPressed,
	UIThemeColor_SoftkeyTextLeft,
	UIThemeColor_SoftkeyTextLeftNonSel,
	UIThemeColor_SoftkeyTextRight,
	UIThemeColor_SoftkeyTextRightNonSel,
	UIThemeColor_StandbyOperatorName,
	UIThemeColor_StandbyTime,
	UIThemeColor_Tab,
	UIThemeColor_TabText,
	UIThemeColor_TabNonSel,
	UIThemeColor_TabSel,
	UIThemeColor_Text,
	UIThemeColor_Title,
	UIThemeColor_VolumeStaples,
	UIThemeColor_ProgressBarOutline,
	UIThemeColor_ProgressBar,
	UIThemeColor_CalendarWeekViewMarkings,
	UIThemeColor_TopMenuShadow,
	UIThemeColor_Notes,
	UIThemeColor_OverlayTitleShadow,
	UIThemeColor_TabTextShadow,
	UIThemeColor_HomeScreenTabTextShadow,
	UIThemeColor_TitleShadow,
	UIThemeColor_Cursor,
	UIThemeColor_OverlayCursor,
	UIThemeColor_OverlayPrompt,
	UIThemeColor_Prompt,
	UIThemeColor_InternalFrame,
	UIThemeColor_InternalFrameText,
	UIThemeColor_InternalFrameNonSel,
	UIThemeColor_InternalFrameHighlight,
	UIThemeColor_MediaBackground,
	UIThemeColor_MediaBackgroundSearch,
	UIThemeColor_MediaIcon,
	UIThemeColor_MediaText,
	UIThemeColor_MediaHighlightIcon,
	UIThemeColor_MediaHighlightText,
	UIThemeColor_MediaLine,
	UIThemeColor_MediaWalkmanHighlight,
	UIThemeColor_MediaWalkmanParticle,
	UIThemeColor_MediaParticle,
	UIThemeColor_Last
} UIThemeColor_t;

// book ------------------------------------------------------------------------

// struct BOOK;

typedef struct UI_APP_SESSION
{
	LIST *listbook;
	TEXTID name;
	IMAGEID icon;
	int W2;
	int SessionID;
	int unk2;
	char unk3;
} UI_APP_SESSION;

typedef struct XBOOK
{
	char isDestroyed;
	char *name;
	UI_APP_SESSION *app_session;
	int parent_BookID;
	u16 unk2;
	int unk3;
	int unk4;
	char unk5;
	void *unk6;
	int unk7;
	u16 unk8;
	u16 unk9;
	char dummy7[0x8];
	char orientation;
} XBOOK;

typedef struct BOOK_SUBROUTINE
{
	const char *name;
	struct PAGE_DESC *page;
	void (*OnEnter)(void *, struct BOOK *);
	void (*OnExit)(void *, struct BOOK *);
} BOOK_SUBROUTINE;

typedef struct PAGE_MSG
{
	int msg;
	int (*proc)(void *, struct BOOK *);
} PAGE_MSG;

typedef struct PAGE_DESC
{
	const char *name;
	BOOK_SUBROUTINE *subr;
	const PAGE_MSG *msg_lst;
} PAGE_DESC;

typedef struct XGUILIST
{
	struct BOOK *book;
	LIST *guilist;
} XGUILIST;

typedef struct BOOK
{
	XBOOK *xbook;
	void (*onClose)(struct BOOK *);
	int BookID;
	struct PAGE_DESC *current_page;
	struct PAGE_DESC *base_page;
	XGUILIST *xguilist;
} BOOK;

typedef int (*IS_NEEDED_BOOK)(BOOK *);

#define NO_BOOK_ID 0xFFFFFFFF

// gui list --------------------------------------------------------------------

typedef struct GUI_MESSAGE
{
	char __msg;	  // use GUIonMessage_GetMsg( )
	GUI *__gui;	  // use GUIonMessage_GetGui( )
	BOOK *__book; // use GUIonMessage_GetBook( )
} GUI_MESSAGE;

typedef enum LISTMSGS
{
	LISTMSG_HighlightChanged = 0,
	LISTMSG_GetItem = 1,
	LISTMSG_SubItemHighlightChanged = 2,
	LISTMSG_GetSubItem = 3,
	LISTMSG_Edit = 4,
	LISTMSG_Delete = 5,
	LISTMSG_SearchIndex = 7,
	LISTMSG_GetKeyboard = 8,
	LISTMSG_ItemSelectionChanged = 9,
	LISTMSG_DrawComplete = 10,
	LISTMSG_ListBusy = 11,

	LISTMSG_KeyRepeat = 12,
	LISTMSG_StringInputCharProtYesCB = 13,
	LISTMSG_StringInputCharProtNoCB = 14,
	LISTMSG_Minipopup = 15
} LISTMSGS;

typedef enum LISTMENU_HOTKEY_MODE
{
	LKHM_SEARCH = 0,
	LKHM_SHORTCUT = 1,
	LKHM_FOCUS = 2,
	LKHM_PRESS = 3
} LISTMENU_HOTKEY_MODE;

// stringinput -----------------------------------------------------------------

enum INPUT_TYPES
{
	IT_REAL = 0,
	IT_STRING = 1,
	IT_INTEGER = 2,
	IT_PHONE_NUMBER = 3,
	IT_DIGITAL_PASS = 4,
	IT_DIGITAL_IP = 5,
	IT_URL = 6,
	IT_EMAIL = 7,
	IT_ABC_AND_DIGIT = 8,
	IT_UNSIGNED_DIGIT = 9,
	IT_EXTRA_DIGIT = 10,
	IT_ABC_OR_DIGIT = 11,
	IT_EXTRA_DIGIT_2 = 12,
	IT_ABC_OR_DIGIT_2 = 13,
};

typedef struct LANGUAGE
{
	char count;
	char *langs;
} LANGUAGE;

typedef struct DISP_OBJ_STRING_INPUT
{
	char dummy[0x424];
	LANGUAGE *lng;
	char cur_langID;
} DISP_OBJ_STRING_INPUT;

// gc/gvi/graphics -------------------------------------------------------------

typedef void *PCANVAS;

typedef struct CANVAS_DESC
{
	int unk0;
	int unk1;
	int width;
	int height;
	uint8_t *pixel_data;
	int size;
} CANVAS_DESC;

typedef struct GC
{
	PCANVAS *pcanvas;
	char unk1[0x8];
	PCANVAS *pcanvas_pen;
	int pen_color;
	char unk3[0x4];
	PCANVAS *pcanvas_brush;
	int brush_color;
	uint8_t XX;
	char unk[0x3];
	PCANVAS *pcanvas_text;
	int unk2;
	PCANVAS *pcanvas_icon;
} GC;

typedef struct GVI_BITMAP
{
	int unk0;
	int unk1;
	int unk2;
	void *unk3;
	void *unk4;
	CANVAS_DESC *pcanvas_desc;
	int unk6;
	int unk7;
} GVI_BITMAP;

typedef void *GVI_OBJ;
typedef GVI_OBJ GVI_GC;
typedef GVI_OBJ GVI_BMP;
typedef GVI_OBJ GVI_PEN;
typedef GVI_OBJ GVI_BRUSH;

typedef struct GVI_XYWH
{
	int x;
	int y;
	int w;
	int h;
} GVI_XYWH;

typedef struct SURFACE
{
	int Ifc;
	u16 Flags;
	int Width;
	int Height;
	int Buffer;
	int BufferSize;
	int Tag;
	int RefCount;
	struct SURFACE *next;
	int HWFlags;
	int BitsLock;
	int unk;
	int MemLocks;
	int unk1;
	int unk2;
	int unk3;
	int unk4;
	int unk5;
	int Display;
} SURFACE;

#pragma pack(push, 2)
typedef struct FONT_DESC
{
	u16 id;
	wchar_t name[10];
} FONT_DESC;
#pragma pack(pop)

// files -----------------------------------------------------------------------

typedef struct FSTAT
{
	u16 st_ino;
	u16 st_nlink;
	int st_mode; // was unk1
	int fsize;	 // st_size
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
	unsigned long st_attr;
} FSTAT;

typedef struct W_FSTAT
{
	int attr;
	int unk_0x4;
	int unk_0x8;
	int unk_0xC;
	int unk_0x10;
	int unk_0x14;
	int st_size;
	unsigned int unk_0x1C;
	unsigned int unk_0x20;
	unsigned int unk_0x24;
} W_FSTAT;

typedef struct FILELISTITEM
{
	int unk;
	wchar_t *path;
	wchar_t *fname;
	char *content_type;
	char unk1[0x2F0];
} FILELISTITEM; // FSX_dirent?

typedef struct DIR_HANDLE
{
	int unk_0;
	u16 unk_4;
	u16 unk_6;
	int unk_8;
	char unk_C;
	char unk_D;
	char ena_hidden;
} DIR_HANDLE; // FSX_DIR?

typedef struct VOLUMESIZE
{
	unsigned long TotalSpace;			 /* Total size of FS in bytes */
	unsigned long FreeSpace;			 /* Number of free bytes */
	unsigned long BytesPerCluster;		 /* File system block size */
	unsigned long TotalClusters;		 /* Logical file system size */
	unsigned long TotalFreeClusters;	 /* Number of free blocks, both phyical and logical */
	long free_reserved_blocks;			 /* Number of free reserved blocks. */
	unsigned long used_oversize_blocks;	 /* Number of used oversize blocks. */
	unsigned long total_oversize_blocks; /* Number of available oversize blocks. */
} VOLUMESIZE;							 // old FSX_freespace

typedef struct VOLUMESIZE_A2
{
	unsigned long long TotalSpace;		 /* Total size of FS in bytes */
	unsigned long long FreeSpace;		 /* Number of free bytes */
	unsigned long BytesPerCluster;		 /* File system block size */
	unsigned long TotalClusters;		 /* Logical file system size */
	unsigned long TotalFreeClusters;	 /* Number of free blocks, both phyical and logical */
	long free_reserved_blocks;			 /* Number of free reserved blocks. */
	unsigned long used_oversize_blocks;	 /* Number of used oversize blocks. */
	unsigned long total_oversize_blocks; /* Number of available oversize blocks. */
} VOLUMESIZE_A2;						 // FSX_freespace

// lseek
typedef enum _SEEK_SET
{
	SEEK_SET = 0,
	SEEK_CUR,
	SEEK_END
} _SEEK_SET;

// w_lseek
typedef enum W_SEEK_SET
{
	WSEEK_CUR = 0,
	WSEEK_END = 1,
	WSEEK_SET = 2
} W_SEEK_SET;

// w_fopen
typedef enum W_OPEN_ATTR
{
	WA_Read = 1,
	WA_Write = 2,
	WA_Append = 4,
	WA_Create = 8,
	WA_Truncate = 0x40
} W_OPEN_ATTR;

// fopen/_fopen (mode)
#define FSX_O_RDONLY 0x0001 /// Open for reading only.
#define FSX_O_WRONLY 0x0002 /// Open for writing only.
#define FSX_O_RDWR 0x0004	/// Open for reading and writing.

#define FSX_O_APPEND 0x0008		/// Writes done at eof.
#define FSX_O_SINGLEUSER 0x0010 /// Set file locking mechanism on
#define FSX_O_CREAT 0x0100		/// Create and open file.
#define FSX_O_TRUNC 0x0200		/// Open and truncate.
#define FSX_O_EXCL 0x0400		/// Open only if file doesn't already exist.
#define FSX_O_MULT 0x0800		/// Open for reading or writing the already opened file.
#define FSX_O_ENCRYPT 0x1000	/// Secure Storage flag.
#define FSX_O_DECRYPT 0x2000	/// Secure Storage flag.
#define FSX_O_CHKPATH 0x4000	/// Check the path length considering its subfolders.
#define FSX_O_NOROLLBACK 0x8000 /// Prevent rollback if write fails due to ENOSPC.

#define FSX_O_FS_MASK (0xF70F) /* MASK for normal file's open mode*/

// fopen/_fopen (mode), FSTAT.st_mode
#define FSX_S_IRUSR 0x00000100 /// Read access, owner.
#define FSX_S_IWUSR 0x00000080 /// Write access, owner.
#define FSX_S_IXUSR 0x00000040 /// Execute/search access, owner.
#define FSX_S_IREAD FSX_S_IRUSR
#define FSX_S_IWRITE FSX_S_IWUSR
#define FSX_S_IEXEC FSX_S_IXUSR
#define FSX_FILE_MODE_MASK (FSX_S_IRUSR | FSX_S_IWUSR | FSX_S_IXUSR)

// FSTAT.st_mode
#define FSX_S_IFUNKNOWN 0x00000000
#define FSX_S_IFREG 0x00001000
#define FSX_S_IFVOL 0x00002000
#define FSX_S_IFDIR 0x00010000
#define FSX_S_IFLINK 0x00040000

// for pAttr
#define FSX_EXT_ATTR_NONE 0x00000000	   /* No attributs */
#define FSX_FILE_ATTR_CORRUPTED 0x00000001 /* If set, the file is corrupted */
#define FSX_FILE_ATTR_PRIVATE 0x00000002   /* If set, the file is copyright protected */
#define FSX_FILE_ATTR_DECODED 0x00000004   /* If set, the file can be decoded */
#define FSX_FILE_ATTR_ENCRYPT 0x00000008   /* If set, the file will be encrypted */
#define FSX_FILE_ATTR_HIDDEN 0x10000000	   /* If set, the file will be hidden */

// for lseek mode
#define FSX_SEEK_SET 0 /// Seek to an absolute position
#define FSX_SEEK_CUR 1 /// Seek relative to current position
#define FSX_SEEK_END 2 /// Seek relative to end of file

// for action
#define FSX_ATTR_CLR 0 /// Clear attribute
#define FSX_ATTR_SET 1 /// Set attribute
#define FSX_ATTR_GET 2 /// Get attribute

// hooks -----------------------------------------------------------------------

typedef int (*KEYHOOKPROC)(int key, int repeat_count, int mode, LPARAM lparam, DISP_OBJ *disp);
typedef int (*PAGEHOOKPROC)(void *msg, BOOK *book, PAGE_DESC *page_desc, LPARAM ClientData, u16 event);

typedef enum PAGE_HOOK_MODE
{
	PAGE_HOOK_REMOVE = 0,
	PAGE_HOOK_ADD_BEFORE,
	PAGE_HOOK_ADD_AFTER
} PAGE_HOOK_MODE;

typedef enum KEY_HOOK_MODE
{
	KEY_HOOK_REMOVE = 0,
	KEY_HOOK_ADD
} KEY_HOOK_MODE;

#define BLOCK_EVENT_GLOBALLY 666
#define BLOCK_EVENT_IN_THIS_SESSION 667

#ifdef __cplusplus
template <typename T, typename T2>
KEYHOOKPROC MKKEYHOOKPROC(int (*param)(int, int, int, T *, T2 *))
{
	INHERITANCECHECK<DISP_OBJ, T2>();
	return reinterpret_cast<KEYHOOKPROC>(param);
}
#else
#define MKKEYHOOKPROC(fn) (KEYHOOKPROC) fn
#endif

#define MODIFYKEYHOOK(proc, mode, lparam) ModifyKeyHook(MKKEYHOOKPROC(proc), mode, lparam)

#ifdef __cplusplus
template <typename T, typename TBOOK>
PAGEHOOKPROC MKPAGEHOOKPROC(int (*param)(void *, TBOOK *, PAGE_DESC *, T *, u16))
{
	INHERITANCECHECK<BOOK, TBOOK>();
	return reinterpret_cast<PAGEHOOKPROC>(param);
}
#else
#define MKPAGEHOOKPROC(fn) (PAGEHOOKPROC) fn
#endif

#define MODIFYUIPAGEHOOK(event, proc, ClientData, mode) ModifyUIPageHook(event, MKPAGEHOOKPROC(proc), ClientData, mode)

// other -----------------------------------------------------------------------

typedef char *BCD_TEXT;

// events ----------------------------------------------------------------------

typedef struct CALLMANAGER_EVENT_DATA
{
	char CallID;
	char CallType;
	char CallState;
	BCD_TEXT PNUM;
	char unk1;
	char unk2;
	char CallCause;
} CALLMANAGER_EVENT_DATA;

typedef struct CALLMANAGER_EVENT_DATA_A2
{
	char CallID;
	int unk1;
	char unk2;
	char CallType;
	char CallState;
	BCD_TEXT PNUM;
	char CallCause;
	char unk3;
	char unk4;
} CALLMANAGER_EVENT_DATA_A2;

typedef struct REDRAW_RELEASE_MESSAGE
{
	DISP_OBJ_ONREDRAW_METHOD SB_OldOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SB_NewOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SI_OldOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SI_NewOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SK_OldOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SK_NewOnRedraw;
} REDRAW_RELEASE_MESSAGE;

// #define MINUTE_TICK_EVENT 999
#define ELF_BCFG_CONFIG_EVENT 994
#define ELF_SHOW_INFO_EVENT 998
#define ELF_TERMINATE_EVENT 997
#define ELF_RECONFIG_EVENT 996
#define SBY_REDRAW_RELEASE_EVENT 995

// COM -------------------------------------------------------------------------

typedef struct
{
	unsigned char data[16];
} UUID, *PUUID;

// #define IID_PPV_ARG( Type, Expr ) &IID_##Type, reinterpret_cast<void**>( static_cast<Type**>( Expr ) )
#ifdef __cplusplus
template <typename T>
void **PPINTERFACE(T **pp)
{
	return reinterpret_cast<void **>(pp);
}
#else
#define PPINTERFACE(v) (void **)v
#endif

#define SUCCEEDED(res) res >= 0

// softkeys --------------------------------------------------------------------

typedef void (*SKACTIONPROC)(BOOK *, GUI *);

typedef struct SKLABEL
{
	TEXTID text;
	wchar_t unk1;
	char unk2;
} SKLABEL;

typedef struct SOFTKEY_DESC_A2
{
	u16 action;
	u16 unk1;
	BOOK *book;
	DISP_OBJ *disp_object;
	void *IUIImage;
	TEXTID ButtonText;
	TEXTID MenuText;
	TEXTID DisabledMessage;
	TEXTID HelpText;
	TEXTID LongSKButtonText;
	u16 parent_action;
	u16 SubItemHighlight_action;
	LIST *subitems_list;
	void (*proc)(BOOK *, GUI *);
	void (*DisabledAction)(BOOK *, GUI *);
	char unk2[8];
	char enable;
	char visible;
	char SuppressDefaultAction;
	char unk3[49];
} SOFTKEY_DESC_A2;

typedef struct SOFTKEY_DESC
{
	u16 action;
	u16 unk1;
	BOOK *book;
	DISP_OBJ *disp_object;
	IMAGEID Icon;
	u16 unk2;
	TEXTID ButtonText;
	TEXTID MenuText;
	TEXTID DisabledMessage;
	TEXTID HelpText;
	u16 parent_action;
	u16 SubItemHighlight_action;
	LIST *subitems_list;
	void (*proc)(BOOK *, GUI *);
	void (*DisabledAction)(BOOK *, GUI *);
	char unk3[8];
	char enable;
	char visible;
	char SuppressDefaultAction;
	char unk4[49];
} SOFTKEY_DESC;

#ifdef __cplusplus
template <typename T, typename T2>
SKACTIONPROC MKSKACTIONPROC(void (*param)(T *, T2 *))
{
	INHERITANCECHECK<BOOK, T>();
	INHERITANCECHECK<GUI, T2>();
	return reinterpret_cast<SKACTIONPROC>(param);
}
#else
#define MKSKACTIONPROC(fn) (SKACTIONPROC) fn
#endif

// hardware/multimedia ---------------------------------------------------------

typedef enum
{
	Charging = 2,
	Completed = 8
} ChargingState;

typedef struct BATT
{
	char ChargingState;
	char ChargingMethod;
	int BatteryVoltage;
	int ChargerVoltage;
	int ChargerCurrent;
	int CurrentToBattery;
	int BatteryTemperature;
	int SystemTemperature;
	int RemainingCapacity;
	char RemainingCapacityInPercent;
	int PowerDissipation;
	int NrOfChargingCycles;
	int NrOfSecondsOnSafetyTimer;
	char SuspensionCause;
} BATT;

typedef struct NEIGHBOUR_CELLDATA
{
	short ch;
	unsigned char bsic;
	unsigned char unk3;
	unsigned short cid;
	char unk6[2];
	int unk8;
	char index;
	char unkD[3];
	int unk10;
	char unk14;
	char unk15;
	short unk16;
	int unk18;
	char unk1C[2];
	char cc[2];
	char mnc[2];
	char lac;
	signed char rxam;
	int unk24;
	int unk28;
	char unk2C;
	char cro;
	char unk2E[2];
	unsigned short unk30;
	unsigned short unk32;
	unsigned short unk34;
	unsigned short unk36;
	signed char rxlvl;
	char unk39[3];
	int unk3C;
	int unk40;
} NEIGHBOUR_CELLDATA;

typedef struct CUR_CELLDATA
{
	unsigned short cid;
	char unk2[2];
	char cc[2];
	char mnc[2];
	char lac;
	char unk09[3];
	int unk0C;
	int unk10;
	char unk14[2];
	signed char unk16;
	char unk17;
	int unk18;
	int unk1C;
	char unk20[2];
	signed char rxlev;
} CUR_CELLDATA;

typedef struct GPRS_SESSION_INFO
{
	int SesTime;
	int SentBytes;
	int RcvBytes;
} GPRS_SESSION_INFO;

typedef struct RAT_CI_DESC
{
	char unk1;
	char RAT;
	int CI;
	char dummy[0x10];
} RAT_CI_DESC;

typedef struct PLMN_LAC_DESC
{
	char MCC[3];
	char MNC[2];
	char PLMN_x;
	char unk1[2];
	char LAC[2];
	char unk2[2];
} PLMN_LAC_DESC;

typedef struct CONNECTION_INFO_DESC
{
	char ValidLAI;
	char unk1;
	char MCC[3];
	char MNC[2];
	char PLMN_x;
	wchar_t LAC;
	char ValidRAC;
	char ValidCI;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
	int unk2;
#endif
	int CI;
	char RAT;
	char Coverage;
	char CSReg;
	char PSReg;
	char Priority;
	char EPriority;
	char EGPRS;
	char DTMSup;
	char HSDPA;
	char unk3;
	char MSC;
	char SGSN;
} CONNECTION_INFO_DESC;

typedef void *PAudioControl;

typedef struct BT_FILE_2020
{
	wchar_t fname[255];
	wchar_t fpath[255];
} BT_FILE_2020;

typedef struct BT_FILE_2010
{
	wchar_t fname[252];
	wchar_t fpath[252];
} BT_FILE_2010;

typedef struct SEND_OBEX_STRUCT
{
	char is_multiple;
	int Book_ID;
	TEXTID send;
	TEXTID sent;
	u16 obex_flag;
	union
	{
		LIST *lst;
		union
		{
			BT_FILE_2020 btf2020;
			BT_FILE_2010 btf2010;
		};
	};
} SEND_OBEX_STRUCT;

// addressbook -----------------------------------------------------------------

typedef struct AB_NUM_ITEM
{
	u16 RecordID;
	char num[41]; // 2
	char xx[0x35];
} AB_NUM_ITEM;

typedef struct AB_STR_ITEM
{
	u16 len;
	char encodingID;
	char str[255];
} AB_STR_ITEM;

typedef struct AB_GET_STRUCT
{
	u16 unk_02;
	int rec_num;
} AB_GET_STRUCT;

typedef struct AB_ITEM_DESC_A2
{
	u16 num;
	u16 icon;
	int name;
	int name2;
	u16 field_C;
	u16 field_D;
	u16 big_icon;
	u16 field_10;
	u16 ID;
	u16 null;
} AB_ITEM_DESC_A2;

typedef struct AB_ITEM_DESC_2020
{
	u16 num;
	u16 tab;
	u16 num_in_tab;
	u16 icon;
	int name;
	char field_C;
	char field_D;
	u16 big_icon;
	u16 field_10;
	u16 ID;
} AB_ITEM_DESC_2020;

typedef struct AB_ITEM_DESC
{
	u16 num;
	u16 field_2;
	u16 field_4;
	u16 icon;
	int name;
	u16 field_C;
	u16 field_E;
	u16 field_10;
	char field_12;
	char field_13;
	char field_14;
	char field_15;
	u16 field_16l;
	char ID;
	char field_19;
	char field_1A;
	char field_1B;
} AB_ITEM_DESC;

// applications/shortcuts ------------------------------------------------------

typedef struct APP_DESC
{
	int (*SigHandler)(union SIGNAL **sig);
	PAGE_DESC *default_page;
	char *name;
	int (*MsgHandler)(void *msg);
	char *(*GetMsgName)(int);
} APP_DESC;

typedef struct MIDP_DESC_ITEM
{
	u16 item_name_len;
	char const_2;
	wchar_t *item_name;
} MIDP_DESC_ITEM;

typedef struct MIDP_DESC
{
	MIDP_DESC_ITEM *name;
	MIDP_DESC_ITEM *vendor;
	MIDP_DESC_ITEM *point;
} MIDP_DESC;

typedef struct JavaAppFullpath
{
	wchar_t fullpath_len;
	char unk_2;
	wchar_t *fullpath;
} JavaAppFullpath;

typedef struct SHORTCUT_DESC
{
	wchar_t name[0x31];
	wchar_t null;
	wchar_t shortcut_state;
	wchar_t erasable_flag;
} SHORTCUT_DESC;

typedef struct SHORTCUT_DESC_A2
{
	wchar_t name[0xC8];
	wchar_t vendor_name[0xC8];
	wchar_t entry_point[0xC8];
	wchar_t pos_in_list;
	char xxx1;
	char xxx2;
	char item_type;
	char lock_type; // 0 - no lock, 1 - locked, 2 - lockedposition
	IMAGEID icon;
} SHORTCUT_DESC_A2;

typedef enum SHORTCUT_STATE
{
	SC_State_None = 0,
	SC_State_OutOfUse = 1,
	SC_State_Activated = 2,
	SC_State_MainMenu = 3
} SHORTCUT_STATE;

typedef enum SHORTCUT_ITEM_TYPE
{
	SC_Type_Standard = 0,
	SC_Type_JavaItem = 1,
	SC_Type_MainMenu = 2,
	SC_Type_AddShortcut = 3
} SHORTCUT_ITEM_TYPE;

// databrowser/associations ----------------------------------------------------

struct SUB_EXECUTE;

typedef struct FILESUBROUTINE
{
	int cmd;
	union
	{
		int (*ON_CMD)(struct SUB_EXECUTE *);
		int (*ON_CMD_RUN)(struct SUB_EXECUTE *);
		int (*ON_CMD_ICON)(struct SUB_EXECUTE *, IMAGEID *iconid);
		int (*ON_CMD_TEXTID)(struct SUB_EXECUTE *, TEXTID *strid);
	};
	TEXTID StrID;
	union
	{
		int (*ON_CHECK)(struct SUB_EXECUTE *, void *);
		int (*ON_CMD_RUN_CHECK)(struct SUB_EXECUTE *);
	};
} FILESUBROUTINE;

typedef struct FILEITEM
{
	wchar_t *__fname; // use FILEITEM_SetFname / FILEITEM_GetFname
	wchar_t *__path;  // use FILEITEM_SetPath / FILEITEM_GetPath
	char *MIME_type;
	wchar_t *extension;
	int *FSTAT;
	int *DRMHandle;
	char DRM_Flag;
} FILEITEM;

typedef struct DB_EXT_FOLDERS
{
	TEXTID StrID_FolderName;
	TEXTID StrID_SavedTo;
	wchar_t *Path;
	int isInternal;
} DB_EXT_FOLDERS;

typedef struct DB_EXT
{
	char **content_type;
	wchar_t **ext_list;
	void (*GetMethods)(struct SUB_EXECUTE *);
	int sub_execute_size;
	const DB_EXT_FOLDERS *dbf;
	char type_group;
	int drm_flags;
	char unk2;
	char unk3;
} DB_EXT;

typedef struct DB_EXT_2010
{
	char **content_type;
	wchar_t **ext_list;
	void (*GetMethods)(struct SUB_EXECUTE *);
	int sub_execute_size;
	const DB_EXT_FOLDERS *dbf;
	int drm_flags;
	char unk2;
	char unk3;
} DB_EXT_2010;

typedef struct SUB_EXECUTE
{
	FILESUBROUTINE *filesub;
	FILEITEM *file_item;
	BOOK *BrowserItemBook;
	int DB_BookID;
	void *unk2;
	GUI *gui;
	GUI_FEEDBACK *gui_fb;
	void *strinp_struct;
	char dummy1[0x2D0];
#if defined(DB3150v1) || defined(DB3150v2)
	char dummy2[0x4];
#endif
	void *pIMMEPlayer; // 2F4
} SUB_EXECUTE;

typedef int (*DB_FILE_FILTER)(const wchar_t *ExtList, const wchar_t *ItemPath, const wchar_t *ItemName);

// elfloader internal ----------------------------------------------------------

typedef struct EP_DATA
{
	LIST *UserDataList; // unused
	LIST *gKbdHookList;
	PROCESS HPID;
	LIST *UIHookList;
	LIST *OseHookList; // unused
	LIST *DBExtList;
	FILESUBROUTINE *elf_ext_m;
	LIST *DLLList;
	LIST *UIPageHook_Before;
	DB_EXT *(*CreateDbExt)(void);
	IMAGEID IconSmall;
	IMAGEID IconBig;
	void **LibraryCache; // ?? ??????????!!!!!
	void *LibraryDLL;
	wchar_t LastKey;
	LIST *UIPageHook_After;
} EP_DATA;

// timers ----------------------------------------------------------------------

typedef void (*TIMERPROC)(u16 timerID, LPARAM lparam);

#ifdef __cplusplus
template <typename T>
TIMERPROC MKTIMERPROC(void (*param)(u16, T *))
{
	return reinterpret_cast<TIMERPROC>(param);
}
#else
#define MKTIMERPROC(fn) (TIMERPROC) fn
#endif

#define TIMER_RESET(timer, time, onTimer, lparam) Timer_ReSet(timer, time, MKTIMERPROC(onTimer), lparam)
#define TIMER_SET(time, onTimer, lparam) Timer_Set(time, MKTIMERPROC(onTimer), lparam)

// pb_ui_search_bk_create_search_menu
#define MODE_PB 0x0001
#define MODE_GROUPS 0x0002
#define MODE_SIM 0x0008
#define MODE_UNSAVED 0x0010

typedef enum URISchemeID
{
	file = 0,
	http = 1,
	https = 2,
	rtsp = 3,
	mailto = 4,
	smsto = 5,
	mmsto = 6,
	sms = 7,
	mms = 8,
	tel = 9,
	vcard = 10,
	vnote = 11,
	vcal = 12
} URISchemeID;

// page cache --------------------------------------------------------------------

typedef struct pageCache
{
	int virtAddr;
	wchar_t prev_i;
	wchar_t next_i;
	wchar_t swapPrio;
	wchar_t x;
} pageCache;

typedef struct pagePool
{
	wchar_t locked;
	char inuse;
	char x1;
	wchar_t usedPages;
	wchar_t x2;
	int baseAddr;
} pagePool;

#define FS_MEMMAP_WRITE 0x1
#define FS_MEMMAP_READ 0x2
#define FS_MEMMAP_UNMAPPED 0x4
#define FS_MEMMAP_CACHED 0x8
#define FS_MEMMAP_BUFFERED 0x10
#define FS_MEMMAP_NOPERMISSIONS 0x20
#define FS_MEMMAP_NONCACHED 0x40
#define FS_MEMMAP_NONBUFFERED 0x80

// menu element ----------------------------------------------------------------

typedef struct
{
	// wchar_t *elem_id;	// 0x0 use DynamicMenu_GetElementId( );
	// char dummy_1[0x4];	// 0x4
	// u16 item;			// 0x8
	// char __msg;			// 0xA Use DynamicMenu_GetElementMsg( )
	// char dummy_2;		// 0xB
	// GUI *menu_list;		// 0xC
	// BOOK *book;			// 0x10
	// char state1;		// 0x14
	// char state2;		// 0x15
	// char dummy_3;		// 0x16
	// char dummy_4;		// 0x17
	// TEXTID firstline;	// 0x18
	// TEXTID info;		// 0x1C
	// TEXTID secondline;	// 0x20
	// TEXTID unavailable; // 0x24
	// IMAGEID item_icon;	// 0x28
	char dummy[0x30];
} DYNAMIC_MENU_ELEMENT;

enum DYNAMIC_MENU_ELEMENT_MSG
{
	DYNAMIC_MENU_onCall = 0,
	DYNAMIC_MENU_onText,
	DYNAMIC_MENU_onState,
	DYNAMIC_MENU_onUnk1,
	DYNAMIC_MENU_onUnk2,
	DYNAMIC_MENU_last
};

// softkeys
typedef enum
{
	UNDEFINED_SOFTKEY = -1,	  // See documentation for CreateSoftkey
	ABORT_SOFTKEY = 4011,	  // Predefined softkey for abort
	ACCEPT_SOFTKEY,			  // Predefined master softkey for the accept family: ok, save, done, continue...
	ADD_SOFTKEY,			  // Predefined softkey for add
	ADDITEM_SOFTKEY,		  // Predefined softkey for add item
	CANCEL_SOFTKEY,			  // Predefined softkey for cancel
	CHECK_SOFTKEY,			  // Predefined softkey for check
	CONTINUE_SOFTKEY,		  // Predefined softkey for continue
	CREATE_MORELIST_SOFTKEY,  // Predefined softkey for create more list
	DESTROY_MORELIST_SOFTKEY, // Predefined softkey for destroy more list
	DELETE_SOFTKEY,			  // Predefined softkey for delete
	DONE_SOFTKEY,			  // Predefined softkey for done
	EDIT_SOFTKEY,			  // Predefined softkey for edit
	HELP_SOFTKEY,			  // Predefined softkey for help
	HYPERLINK_SOFTKEY,		  // Predefined softkey for hyperlink
	INFO_SOFTKEY,			  // Predefined softkey for info
	INPUT_EMPTY_SOFTKEY,	  // Predefined softkey for empty input
	INPUT_NOT_EMPTY_SOFTKEY,  // Predefined softkey for not empty input
	KEYLOCK_SOFTKEY,		  // Predefined softkey for key lock
	MARKSEVERAL_SOFTKEY,	  // Predefined softkey for abort
	NO_SOFTKEY,				  // Predefined softkey for no
	OK_SOFTKEY,				  // Predefined softkey for OK
	PREVIOUS_SOFTKEY,		  // Predefined softkey for previous
	SAVE_SOFTKEY,			  // Predefined softkey for save
	SELECT_SOFTKEY,			  // Predefined softkey for select
	UNCHECK_SOFTKEY,		  // Predefined softkey for uncheck
	UNMARK_ALL_SOFTKEY,		  // Predefined softkey for unmark all
	YES_SOFTKEY,			  // Predefined softkey for yes
	LAST_SOFTKEY			  // Last softkey
} TUIPredefinedSoftkey;

// registry --------------------------------------------------------------------

enum RegistryType_t
{
	RegistryType_INT = 1,
	RegistryType_CHAR = 2,
	RegistryType = 3,
	RegistryType_BIN = 4
};

enum METADATA_TAGS
{
	TAG_ARTIST,
	TAG_TITLE,
	TAG_ALBUM,
	TAG_YEAR,
	TAG_GENRE,
	TAG_X5,
	TAG_X6
};

// obsolete --------------------------------------------------------------------

/*
typedef struct
{
	int count;
	int signals[3];
}MYSIG;

typedef struct
{
	SIGSELECT signo;
	void (*HOOK)(void*);
}OSE_HOOK_ITEM;

typedef struct
{
	LIST* listbook;
	int name;
	int unk;
	int unk1;
	int app_ID;
	int unk2;
}LISTBOOK;

typedef struct
{
	int flag;
	int unk_NULL1;
	int unk_NULL2;
	TEXTID HeaderStrID;
	int unk_NULL3;
	int (*onMessage)(void*);
}PAGE_MENU_ITEMS_DESC;

typedef struct
{
	int flag;
	int unk_NULL1;
	int unk_NULL2;
	TEXTID HeaderStrID;
	int unk_NULL3;
	int (*onMessage)(void*);
	const PAGE_MENU_ITEMS_DESC* const* items;
}PAGE_MENU_DESC;


typedef struct
{
	unsigned short event;
	// int (*HOOK)(UI_MESSAGE*, BOOK*);
	int (*HOOK)(UI_MESSAGE*);
}UI_HOOK_ITEM;

typedef struct
{
	int base;
	int size;
	wchar_t* fname;
}ELF_DESC;

struct PCOLOR
{
	int pen;
	int brush;
};

typedef struct
{
	int msg;
	int submsg;
	int param1;
	void* param2;
}HELPER_MSG;

typedef struct UI_MESSAGE
{
	char mode;
	int book_or_sess_id;
	unsigned short event;

	void* data;
	void (*mfree)(void*);
}UI_MESSAGE;

typedef struct SBY_REDRAW_RELEASE_MESSAGE
{
	DISP_OBJ_ONREDRAW_METHOD OldonRedraw;
	DISP_OBJ_ONREDRAW_METHOD NewonRedraw;
}SBY_REDRAW_RELEASE_MESSAGE;

*/

#endif
