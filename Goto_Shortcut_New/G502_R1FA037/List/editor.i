#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\Target\\G502_R1FA037.h"














#line 21 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\Target\\G502_R1FA037.h"

#line 28 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\Target\\G502_R1FA037.h"







#line 52 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\Target\\G502_R1FA037.h"

// Menu





  
// Editing



























#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"



// base types and constants ----------------------------------------------------

typedef unsigned short u16;
typedef int BOOL;
typedef unsigned long LRESULT;
typedef int jmp_buf[11];

typedef unsigned short  Uint16_t;
typedef signed short    Int16_t;
typedef unsigned int    Uint32_t;
typedef signed int      Int32_t;

typedef Uint32_t size_t;
typedef Uint32_t time_t;
typedef Uint32_t color_t;

struct BOOK;
struct GUI;
struct DISP_OBJ;








class LPARAM
{
	unsigned long data;
public:
	LPARAM( int a ) { data = a; }
	LPARAM( void* a ) { data = reinterpret_cast<unsigned long>( a ); }
	operator int(){ return data; }
	operator void*(){ return reinterpret_cast<void*>( data ); }
};


typedef struct DATE
{
	u16 year;
	char mon;
	char day;
}DATE;

typedef struct TIME
{
	char hour;
	char min;
	char sec;
	char msec;
}TIME;

typedef struct DATETIME
{
	DATE date;
	TIME time;
}DATETIME;

typedef struct
{
	char dummy[0x8];
	TIME  time;
}CALLINFO;

typedef struct
{
	char dummy[0x24];
	TIME  time;
	int full; 
	int sec;      
}TIMERBOOK;

typedef struct POINT
{
	//int x;
	//int y;
	u16 x;
	u16 y;
}POINT;

typedef struct RECT
{
	u16 x1;
	u16 x2;
	u16 y1;
	u16 y2;
}RECT;


#line 100 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"




// if( GetChipID( ) &CHIPID_MASK == CHIPID_DB... )
#line 114 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"





template<typename BASETYPE,typename CHILDTYPE>
void INHERITANCECHECK(){ if(static_cast<BASETYPE*>(0)==static_cast<CHILDTYPE*>(0)); }


// text ------------------------------------------------------------------------

typedef int TEXTID;

typedef struct TEXTID_DATA
{
	wchar_t lenght;
	char encoding;
	void* ptr;
}TEXTID_DATA;


typedef enum TEXT_ENCODING
{
	ENC_UCS2   = 0,
	ENC_GSM    = 1,
	ENC_BCD    = 2,
	ENC_FILE   = 3,
	ENC_TEXTID = 5,
	ENC_LAT1   = 6,
	ENC_UT     = 8,
	ENC_UTTF   = 9,
}TEXT_ENCODING;









typedef enum
{
	UITextAlignment_Left = 0,
        UITextAlignment_Right,
        UITextAlignment_Center,
        UITextAlignment_LeftDynamic,
        UITextAlignment_RightDynamic
}UITextAlignment_t;

// images ----------------------------------------------------------------------

typedef wchar_t IMAGEID;




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

typedef void ( OSENTRYPOINT )( void );

typedef OSADDRESS( OSERRH )( OSBOOLEAN, OSERRCODE, OSERRCODE );


typedef enum PROCESS_TYPE
{
	OS_PRI_PROC = 0,
	OS_BG_PROC  = 64,
	OS_INT_PROC = 128,
	OS_TI_PROC  = 256,
	OS_PHANTOM  = 512,
	OS_BLOCK    = 1024,
	OS_ZOOMBIE  = 2048,
	OS_ILLEGAL  = 4096
}PROCESS_TYPE;




// list ------------------------------------------------------------------------

typedef struct LIST
{
	u16 unk;
	u16 FirstFree;
	void** listdata;
}LIST;

typedef int (*LISTFINDCALLBACK)(void* listitem, void* itemtofind);






template<typename T,typename T2> LISTFINDCALLBACK MKLISTFINDCALLBACK( int(*param)(T,T2) )
{
	return reinterpret_cast<LISTFINDCALLBACK>(param);
}






//disp -------------------------------------------------------------------------

typedef int (*DISP_OBJ_ONCREATE_METHOD)(DISP_OBJ*);
typedef void (*DISP_OBJ_ONCLOSE_METHOD)(DISP_OBJ*);
typedef void (*DISP_OBJ_ONREDRAW_METHOD)(DISP_OBJ*, int, int, int);
typedef void (*DISP_OBJ_ONKEY_METHOD)(DISP_OBJ*, int scan_code, int unk, int repeat_num, int key_mode);
typedef void (*DISP_OBJ_ONCONFIG_METHOD)(DISP_OBJ*, int unk, int DisplayWidth, int DisplayHeight);
typedef void (*DISP_OBJ_ONLAYOUT_METHOD)(DISP_OBJ*, void* layoutstruct);
typedef void (*DISP_OBJ_METHOD)(DISP_OBJ*);


typedef struct DISP_DESC
{
	char* name;
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
}DISP_DESC;

typedef struct DISP_OBJ
{
	char dummy1[0x58];
        DISP_DESC* desc;    // 0x58
        char dummy4[0x48];
        GUI* gui;           // 0xA4
        char dummy5[0x110];
}DISP_OBJ;



// gui -------------------------------------------------------------------------

typedef struct GUI
{
	DISP_OBJ* disp; // use GUIObject_GetDispObject();
	BOOK* book;     // use GUIObject_GetBook();
        char dummy[0x88];
}GUI;

// 2do: remove these types
typedef struct GUI GUI_LIST;
typedef struct GUI GUI_TABMENUBAR;
typedef struct GUI GUI_ONEOFMANY;
typedef struct GUI GUI_NOFMANY;
typedef struct GUI GUI_FEEDBACK;


typedef enum UI_OverlayStyle_t
{
	UI_OverlayStyle_NotDefined = 0,
	UI_OverlayStyle_Default, // Use original frame settings
	UI_OverlayStyle_FullScreen, // Fullscreen
	UI_OverlayStyle_FullScreenNoStatus, // Fullscreen with no statusRow
	UI_OverlayStyle_TrueFullScreen, // True fullscreen without softkeys and statusrow
	UI_OverlayStyle_InternalFrameSmall, // Fullscreen with small internal frame
	UI_OverlayStyle_InternalFrameLarge, // Fullscreen with large internal frame
	UI_OverlayStyle_InternalFrameOutput, // Informationtext style
	UI_OverlayStyle_PopupFrame, // Popup with SW rendered frame
	UI_OverlayStyle_PopupNoFrame, // Transparent popup window. Default popup style.
	UI_OverlayStyle_FullScreenNoSoftkeys, // Fullscreen without softkeys but with status row
	UI_OverlayStyle_Last
} UI_OverlayStyle_t;

typedef enum UI_TitleMode_t
{
	UI_TitleMode_Uninitated = 0, // Uninitiated
	UI_TitleMode_None, // Show no title
	UI_TitleMode_Normal, // Normal title size
	UI_TitleMode_Small, // Small title
	UI_TitleMode_Tab, // Show tabs instead of title.
	UI_TitleMode_Large, // Large two row title( different fonts for 1:st and 2:nd line )
	UI_TitleMode_Desktop, // Only for desktop title. Will be removed after hb107.
	UI_TitleMode_Last
} UI_TitleMode_t;

//GUIObject_SetZOrder
typedef enum GuiObjectZOrder_t
{
	GuiObjectZOrderAbove = 0, ///< Sets the GUI Z-order to Above
	GuiObjectZOrderBelow, ///< Sets the GUI Z-order to Below
	GuiObjectZOrderTop,   ///< Sets the GUI Z-order to Top
	GuiObjectZOrderBottom, ///< Sets the GUI Z-order to Bottom
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
        UIDisplay_Last,
        UI_Display_Main = 0,
        UI_Display_Second,
        UI_Display_TVOut,
        UI_Display_Last
} UI_Display_t;

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

// book ------------------------------------------------------------------------

//struct BOOK;

typedef struct UI_APP_SESSION
{
	LIST* listbook;
	TEXTID name;
	IMAGEID icon;
	int W2;
	int SessionID;
	int unk2;
}UI_APP_SESSION;

typedef struct XBOOK
{
	char isDestroyed;             //0
	char* name;                   //1
	UI_APP_SESSION* app_session;  //5
	int parent_BookID;            //9
	u16 unk2 ;                    //D
	int unk3;                     //F
	int unk4;                     //13
	char unk5;                    //14
	void* unk6;                   //18
	int unk7;                     //1C
	u16 unk8;                     //1E
	u16 unk9;                     //20
	char dummy7[0x8];             //28
	char orientation;
}XBOOK;

typedef struct BOOK_SUBROUTINE
{
	const char* name;
	struct PAGE_DESC* page;
	void (*OnEnter)(void*, struct BOOK*);
	void (*OnExit)(void*, struct BOOK*);
}BOOK_SUBROUTINE;

typedef struct PAGE_MSG
{
	int msg;
	int (*proc)(void*, struct BOOK*);
}PAGE_MSG;

typedef struct PAGE_DESC
{
	const char* name;
	BOOK_SUBROUTINE* subr;
	const PAGE_MSG* msg_lst;
}PAGE_DESC;

typedef struct XGUILIST
{
	struct BOOK* book;
	LIST* guilist;
}XGUILIST;

typedef struct BOOK
{
	XBOOK* xbook;
	void (*onClose)(struct BOOK*);
	int BookID;
	struct PAGE_DESC* current_page;
	struct PAGE_DESC* base_page;
	XGUILIST* xguilist;
}BOOK;

typedef int (*IS_NEEDED_BOOK)(BOOK*);




// gui list --------------------------------------------------------------------

typedef struct GUI_MESSAGE
{
	char __msg; // use GUIonMessage_GetMsg( )
	GUI* __gui; // use GUIonMessage_GetGui( )
	BOOK* __book; // use GUIonMessage_GetBook( )
}GUI_MESSAGE;


typedef enum LISTMSGS
{
	LISTMSG_HighlightChanged=0,
	LISTMSG_GetItem=1,
	LISTMSG_SubItemHighlightChanged=2,
	LISTMSG_GetSubItem=3,
	LISTMSG_Edit=4,
	LISTMSG_Delete=5,
	LISTMSG_SearchIndex=7,
	LISTMSG_GetKeyboard=8,
	LISTMSG_ItemSelectionChanged=9,
	LISTMSG_DrawComplete=10,
	LISTMSG_ListBusy=11,

	LISTMSG_KeyRepeat = 12,
	LISTMSG_StringInputCharProtYesCB = 13,
	LISTMSG_StringInputCharProtNoCB = 14,
	LISTMSG_Minipopup = 15
}LISTMSGS;

typedef enum LISTMENU_HOTKEY_MODE
{
	LKHM_SEARCH = 0,
	LKHM_SHORTCUT = 1,
	LKHM_FOCUS = 2,
	LKHM_PRESS = 3
}LISTMENU_HOTKEY_MODE;

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
	char* langs;
}LANGUAGE;

typedef struct DISP_OBJ_STRING_INPUT
{
	char dummy[0x424];
	LANGUAGE* lng;
	char cur_langID;
}DISP_OBJ_STRING_INPUT;

// gc/gvi/graphics -------------------------------------------------------------

typedef void* PCANVAS;

typedef struct GC
{
	PCANVAS* pcanvas;       // 0x0
        char unk1[0xC];
        int pen_color;          // 0x10 use GC_GetPenColor()
        u16 unk2;               // 0x14
        char unk3;              // 0x16
        char unk4[0x5];
        void* unk5;             // 0x18
        int brush_color;        // 0x1C use GC_GetBrushColor()
	char GC_XX;             // 0x20
        char unk6[0x3];
	PCANVAS* pcanvas_text;  // 0x24
	int unk7;
	PCANVAS* pcanvas_icon;  // 0x2C
        char unk8[0x4];
        int unk9;               // 0x34
}GC;

typedef void* GVI_OBJ;
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
}GVI_XYWH;

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
	struct SURFACE* next;
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
}SURFACE;

#pragma pack(push, 2)
typedef struct FONT_DESC
{
	u16 id;
	wchar_t name[10];
}FONT_DESC;
#pragma pack(pop)

// files -----------------------------------------------------------------------

typedef struct FSTAT
{
	u16 st_ino;
	u16 st_nlink;
	int st_mode;//was unk1
	int fsize;//st_size
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
	unsigned long st_attr;
}FSTAT;

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
}W_FSTAT;

typedef struct FILELISTITEM
{
	int unk;
	wchar_t* path;
	wchar_t* fname;
	char* content_type;
	char unk1[0x2F0];
}FILELISTITEM; //FSX_dirent?

typedef struct DIR_HANDLE
{
	int unk_0;
	u16 unk_4;
	u16 unk_6;
	int unk_8;
	char unk_C; // на 2010 флажки отличаются...
	char unk_D;
	char ena_hidden;
}DIR_HANDLE; //FSX_DIR?

typedef struct VOLUMESIZE
{
	unsigned long TotalSpace;
	unsigned long FreeSpace;
	unsigned long BytesPerCluster;
	unsigned long TotalClusters;
	unsigned long TotalFreeClusters;
	long free_reserved_blocks;
	unsigned long used_oversize_blocks;
	unsigned long total_oversize_blocks;
}VOLUMESIZE; //old FSX_freespace

typedef struct VOLUMESIZE_A2
{
	unsigned long long TotalSpace; //total_size
	unsigned long long FreeSpace; //free_bytes
	unsigned long BytesPerCluster; //block_size
	unsigned long TotalClusters; //total_blocks
	unsigned long TotalFreeClusters; //free_blocks
	long free_reserved_blocks;
	unsigned long used_oversize_blocks;
	unsigned long total_oversize_blocks;
}VOLUMESIZE_A2; //FSX_freespace


//lseek
typedef enum _SEEK_SET {
	SEEK_SET=0,
	SEEK_CUR,
	SEEK_END
}_SEEK_SET;

//w_lseek
typedef enum W_SEEK_SET {
	WSEEK_CUR=0,
	WSEEK_END=1,
	WSEEK_SET=2
}W_SEEK_SET;

//w_fopen
typedef enum W_OPEN_ATTR {
	WA_Read=1,
	WA_Write=2,
	WA_Append=4,
	WA_Create=8,
	WA_Truncate=0x40
}W_OPEN_ATTR;

//fopen/_fopen (mode)




#line 696 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"



//fopen/_fopen (mode), FSTAT.st_mode
#line 707 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"

//FSTAT.st_mode






//for pAttr
#line 722 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"

//for action




// hooks -----------------------------------------------------------------------

typedef int (*KEYHOOKPROC)(int key, int repeat_count, int mode, LPARAM lparam, DISP_OBJ* disp);
typedef int (*PAGEHOOKPROC)(void* msg, BOOK* book, PAGE_DESC* page_desc, LPARAM ClientData, u16 event);

typedef enum PAGE_HOOK_MODE
{
	PAGE_HOOK_REMOVE=0,
	PAGE_HOOK_ADD_BEFORE,
	PAGE_HOOK_ADD_AFTER
}PAGE_HOOK_MODE;

typedef enum KEY_HOOK_MODE
{
	KEY_HOOK_REMOVE=0,
	KEY_HOOK_ADD
}KEY_HOOK_MODE;






template<typename T,typename T2> KEYHOOKPROC MKKEYHOOKPROC( int(*param)(int,int,int,T*,T2*) )
{
	INHERITANCECHECK<DISP_OBJ,T2>();
	return reinterpret_cast<KEYHOOKPROC>(param);
}







template<typename T, typename TBOOK> PAGEHOOKPROC MKPAGEHOOKPROC( int(*param)(void*,TBOOK*,PAGE_DESC*,T*,u16) )
{
	INHERITANCECHECK<BOOK,TBOOK>();
	return reinterpret_cast<PAGEHOOKPROC>(param);
}






// other -----------------------------------------------------------------------

typedef char* BCD_TEXT;

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
}CALLMANAGER_EVENT_DATA;

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
}CALLMANAGER_EVENT_DATA_A2;

typedef struct REDRAW_RELEASE_MESSAGE
{
	DISP_OBJ_ONREDRAW_METHOD SB_OldOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SB_NewOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SI_OldOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SI_NewOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SK_OldOnRedraw;
	DISP_OBJ_ONREDRAW_METHOD SK_NewOnRedraw;
}REDRAW_RELEASE_MESSAGE;


// #define MINUTE_TICK_EVENT 999





// COM -------------------------------------------------------------------------

typedef struct
{
	unsigned char data[16];
}UUID, *PUUID;


// #define IID_PPV_ARG( Type, Expr ) &IID_##Type, reinterpret_cast<void**>( static_cast<Type**>( Expr ) )

template<typename T> void** PPINTERFACE( T** pp )
{
	return reinterpret_cast<void**>( pp );
}




// softkeys --------------------------------------------------------------------

typedef void (*SKACTIONPROC)( BOOK*, GUI* );

typedef struct SKLABEL
{
	TEXTID text;
	wchar_t unk1;
	char unk2;
}SKLABEL;

typedef struct SOFTKEY_DESC_A2
{
	u16 action;
	u16 unk1;
	BOOK* book;
	DISP_OBJ* disp_object;
	void* IUIImage;
	TEXTID ButtonText;
	TEXTID MenuText;
	TEXTID DisabledMessage;
	TEXTID HelpText;
	TEXTID LongSKButtonText;
	u16 parent_action;
	u16 SubItemHighlight_action;
	LIST* subitems_list;
	void (*proc)(BOOK*, GUI*);
	void (*DisabledAction)(BOOK*, GUI*);
	char unk2[8];
	char enable;
	char visible;
	char SuppressDefaultAction;
	char unk3[49];
}SOFTKEY_DESC_A2;

typedef struct SOFTKEY_DESC
{
	u16 action;
	u16 unk1;
	BOOK* book;
	DISP_OBJ* disp_object;
	IMAGEID Icon;
	u16 unk2;
	TEXTID ButtonText;
	TEXTID MenuText;
	TEXTID DisabledMessage;
	TEXTID HelpText;
	u16 parent_action;
	u16 SubItemHighlight_action;
	LIST* subitems_list;
	void (*proc)(BOOK*, GUI*);
	void (*DisabledAction)(BOOK*, GUI*);
	char unk3[8];
	char enable;
	char visible;
	char SuppressDefaultAction;
	char unk4[49];
}SOFTKEY_DESC;



template<typename T,typename T2> SKACTIONPROC MKSKACTIONPROC( void(*param)(T*,T2*) )
{
	INHERITANCECHECK<BOOK,T>();
	INHERITANCECHECK<GUI,T2>();
	return reinterpret_cast<SKACTIONPROC>(param);
}




// hardware/multimedia ---------------------------------------------------------

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
}BATT;

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
}NEIGHBOUR_CELLDATA;

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
}CUR_CELLDATA;

typedef struct GPRS_SESSION_INFO
{
	int SesTime;
	int SentBytes;
	int RcvBytes;
}GPRS_SESSION_INFO;

typedef struct RAT_CI_DESC
{
	char unk1; // на 2010 этого нету, но пока rat никому не нужен, пусть будет так
	char RAT;
	int CI;
	char dummy[0x10]; // для 3150 достаточно 0x4, для 2020 надо 0x10, для 2010 вообще не надо
}RAT_CI_DESC;

typedef struct PLMN_LAC_DESC
{
	char MCC[3];
	char MNC[2];
	char PLMN_x;
	char unk1[2];
	char LAC[2];
	char unk2[2];
}PLMN_LAC_DESC;

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
}CONNECTION_INFO_DESC;

typedef void* PAudioControl;

typedef struct BT_FILE_2020
{
	wchar_t fname[255];
	wchar_t fpath[255];
}BT_FILE_2020;

typedef struct BT_FILE_2010
{
	wchar_t fname[252];
	wchar_t fpath[252];
}BT_FILE_2010;

typedef struct SEND_OBEX_STRUCT
{
	char is_multiple;
	int Book_ID;
	TEXTID send;
	TEXTID sent;
	u16 obex_flag;
	union
	{
		LIST* lst;
		union
		{
			BT_FILE_2020 btf2020;
			BT_FILE_2010 btf2010;
		};
	};
}SEND_OBEX_STRUCT;

// addressbook -----------------------------------------------------------------

typedef struct AB_NUM_ITEM
{
	u16 RecordID;
	char num[41]; // 2
	char xx[0x35];
}AB_NUM_ITEM;

typedef struct AB_STR_ITEM
{
	u16 len;
	char encodingID;
	char str[255];
}AB_STR_ITEM;

typedef struct AB_GET_STRUCT
{
	u16 unk_02;
	int rec_num;
}AB_GET_STRUCT;

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
}AB_ITEM_DESC_A2;

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
}AB_ITEM_DESC_2020;

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
}AB_ITEM_DESC;

// applications/shortcuts ------------------------------------------------------

typedef struct APP_DESC
{
	int (*SigHandler)(union SIGNAL** sig);
	PAGE_DESC* default_page;
	char* name;
	int (*MsgHandler)(void* msg);
	char* (*GetMsgName)(int);
}APP_DESC;

typedef struct MIDP_DESC_ITEM
{
	u16 item_name_len;
	char const_2;
	wchar_t* item_name;
}MIDP_DESC_ITEM;

typedef struct MIDP_DESC
{
	MIDP_DESC_ITEM* name;
	MIDP_DESC_ITEM* vendor;
	MIDP_DESC_ITEM* point;
}MIDP_DESC;

typedef struct JavaAppFullpath
{
	wchar_t fullpath_len;
	char unk_2;
	wchar_t* fullpath;
}JavaAppFullpath;

typedef struct SHORTCUT_DESC
{
	wchar_t name[0x31];
	wchar_t null;
	wchar_t shortcut_state;
	wchar_t erasable_flag;
}SHORTCUT_DESC;

typedef struct SHORTCUT_DESC_A2
{
	wchar_t name[0xC8];
	wchar_t vendor_name[0xC8];
	wchar_t entry_point[0xC8];
	wchar_t pos_in_list;
	char xxx1;
	char xxx2;
	char item_type;
	char lock_type;	//0 - no lock, 1 - locked, 2 - lockedposition
	IMAGEID icon;
}SHORTCUT_DESC_A2;


typedef enum SHORTCUT_STATE {
	SC_State_None=0,
	SC_State_OutOfUse=1,
	SC_State_Activated=2,
	SC_State_MainMenu=3
}SHORTCUT_STATE;


typedef enum SHORTCUT_ITEM_TYPE {
	SC_Type_Standard=0,
	SC_Type_JavaItem=1,
	SC_Type_MainMenu=2,
	SC_Type_AddShortcut=3
}SHORTCUT_ITEM_TYPE;

// databrowser/associations ----------------------------------------------------

struct SUB_EXECUTE;

typedef struct FILESUBROUTINE
{
	int cmd;
	union
	{
		int (*ON_CMD)(struct SUB_EXECUTE*);
		int (*ON_CMD_RUN)(struct SUB_EXECUTE*);
		int (*ON_CMD_ICON)(struct SUB_EXECUTE*, IMAGEID* iconid);
		int (*ON_CMD_TEXTID)(struct SUB_EXECUTE*, TEXTID* strid);
	};
	TEXTID StrID;
	union
	{
		int (*ON_CHECK)(struct SUB_EXECUTE*, void*);
		int (*ON_CMD_RUN_CHECK)(struct SUB_EXECUTE*);
	};
}FILESUBROUTINE;

typedef struct FILEITEM
{
	wchar_t* __fname; // use FILEITEM_SetFname / FILEITEM_GetFname
	wchar_t* __path; // use FILEITEM_SetPath / FILEITEM_GetPath
	char* MIME_type;
	wchar_t* extension;
	int* FSTAT;
	int* DRMHandle;
	char DRM_Flag;
}FILEITEM;

typedef struct DB_EXT_FOLDERS
{
	TEXTID StrID_FolderName;
	TEXTID StrID_SavedTo;
	wchar_t* Path;
	int isInternal;
}DB_EXT_FOLDERS;

typedef struct DB_EXT
{
	char** content_type;
	wchar_t** ext_list;
	void (*GetMethods)(struct SUB_EXECUTE*);
	int sub_execute_size;
	const DB_EXT_FOLDERS* dbf;
	char type_group;
	int drm_flags;
	char unk2;
	char unk3;
}DB_EXT;

typedef struct DB_EXT_2010
{
	char** content_type;
	wchar_t** ext_list;
	void (*GetMethods)(struct SUB_EXECUTE*);
	int sub_execute_size;
	const DB_EXT_FOLDERS* dbf;
	int drm_flags;
	char unk2;
	char unk3;
}DB_EXT_2010;

typedef struct SUB_EXECUTE
{
	FILESUBROUTINE* filesub;  // 0x0
	FILEITEM* file_item;      // 0x4
	BOOK* BrowserItemBook;    // 0x8
	int DB_BookID;            // 0xC
	void* unk2;               // 0x10
	GUI* gui;                 // 0x14
	GUI_FEEDBACK* gui_fb;     // 0x18
	void* strinp_struct;      // 0x1C
	char dummy1[0x2D0];       // 0x20

	char dummy2[0x4];         // 0x2F0

	void* pIMMEPlayer;        // 0x2F4
}SUB_EXECUTE;

typedef int (*DB_FILE_FILTER)(const wchar_t* ExtList, const wchar_t* ItemPath, const wchar_t* ItemName);

// elfloader internal ----------------------------------------------------------

typedef struct EP_DATA
{
	LIST* UserDataList;//unused
	LIST* gKbdHookList;
	PROCESS HPID;
	LIST* UIHookList;
	LIST* OseHookList;//unused
	LIST* DBExtList;
	FILESUBROUTINE* elf_ext_m;
	LIST* DLLList;
	LIST* UIPageHook_Before;
	DB_EXT* (*CreateDbExt)(void);
	IMAGEID IconSmall;
	IMAGEID IconBig;
	void** LibraryCache; // ?? ????????|!!!!
	void* LibraryDLL;
	wchar_t LastKey;
	LIST* UIPageHook_After;
}EP_DATA;

// timers ----------------------------------------------------------------------

typedef void (*TIMERPROC)( u16 timerID, LPARAM lparam );



template<typename T> TIMERPROC MKTIMERPROC( void(*param)(u16,T*) )
{
	return reinterpret_cast<TIMERPROC>(param);
}







//pb_ui_search_bk_create_search_menu






typedef enum URISchemeID {
	file=0,
	http=1,
	https=2,
	rtsp=3,
	mailto=4,
	smsto=5,
	mmsto=6,
	sms=7,
	mms=8,
	tel=9,
	vcard=10,
	vnote=11,
	vcal=12
}URISchemeID;

// page cache --------------------------------------------------------------------

typedef struct pageCache
{
	int virtAddr;
	wchar_t prev_i;
	wchar_t next_i;
	wchar_t swapPrio;
	wchar_t x;
}pageCache;


typedef struct pagePool
{
	wchar_t locked;
	char inuse;
	char x1;
	wchar_t usedPages;
	wchar_t x2;
	int baseAddr;  
}pagePool;


#line 1387 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Types.h"

// menu element ----------------------------------------------------------------

typedef struct
{
	wchar_t* elem_id;	// 0x0 use DynamicMenu_GetElementId( );
	char dummy_1[0x4];	// 0x4
	u16 item;               // 0x8
	char __msg;		// 0xA Use DynamicMenu_GetElementMsg( )
	char dummy_2;		// 0xB
	GUI* menu_list;		// 0xC
	BOOK* book;		// 0x10
	char state1;		// 0x14
	char state2;		// 0x15
	char dummy_3;		// 0x16
	char dummy_4;		// 0x17	
	TEXTID firstline;	// 0x18
	TEXTID info;		// 0x1C
	TEXTID secondline;	// 0x20
	TEXTID unavailable;	// 0x24
	IMAGEID item_icon;	// 0x28
}DYNAMIC_MENU_ELEMENT;

enum DYNAMIC_MENU_ELEMENT_MSG
{
	MENU_onCall = 0,
	MENU_onText,
	MENU_onState,
	MENU_onUnk1,
	MENU_onUnk2
};
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
	TAG_GENRE
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

#line 2 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
//#include "classes.h"








#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\Colors.h"



#line 13 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\Colors.h"


#line 11 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"

#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IUnknown.h"



class IUnknown
{
public:
  virtual void* pguid();
  virtual void* QueryInterface(PUUID iid, void** pInterface);
  virtual void* AddRef();
  virtual void* Release();
};

#line 13 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IShell.h"



class IShell: public IUnknown
{
public:
  virtual int AllocateMemory(int Size, void** ppBuffer); 
  virtual int CreateMsg(int Base, int Id, int Size, void **ppMsg); 
  virtual bool CompareUUID(UUID* pIID1, UUID* pIID2); 
  virtual int FreeMsg(void** ppMsg);  
  virtual int CreateInstance(UUID* pCid, UUID* pIid, void** ppInterfacePointer);
  virtual int FreeMemory(void** ppBuffer);
  virtual int MarkInterfacesInMsg(void** ppMsg, void** ppInterfacePointer);
  virtual int ReallocateMemory(int Size, void** ppBuffer);
  virtual int ReleaseInterfacesInMsg(void** ppMsg);
  virtual bool IsKindOfInterface(IUnknown* pInterface, UUID* pIId);
  virtual int InvalidateCallbackInterface(IUnknown* pICB);
  virtual int GetCallerExecutionShell(IUnknown** ppIExecutionShell);
};

#line 14 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IUIImageManager.h"



typedef struct
{
  long X;
  long Y;
}TUIPoint;

typedef struct
{
  long Width;
  long Height;
}TUISize;

typedef struct
{
  TUIPoint Point;
  TUISize  Size;
}TUIRectangle;

class IUIImage: public IUnknown
{
public:
  virtual int GetDimensions(long* pWidth, void* pWidthUnit, long* pHeight, void* pHeightUnit);
  virtual int CreateRenderer(IUnknown* pIUIImageRenderer);
  virtual int IsAnimation(bool* IsAnimation);
  virtual int IsScalable(bool* IsScalable);
};

class IUIImageManager: public IUnknown
{
public:
  virtual int CreateFromPath(wchar_t* fpath, wchar_t* fname, char* pMime, long mimeLength, IUIImage** pUIImage);
  virtual int CreateFromCanvas(IUnknown* pGC, IUIImage** pUIImage);
  virtual int CreateFromIcon(long imageID, IUIImage** pUIImage);



  virtual int CreateFromMemory(char* buf_image, long bufferSize, wchar_t* extension, long extensionLength, char* pMime, long mimeLength, IUIImage** pUIImage);
  virtual int CreateFromSimpleLockableBuffer(IUnknown* pISimpleLockableBuffer, long imageDataSize, wchar_t* extension, long extensionLength, char* pMime, long mimeLength, IUIImage** pUIImage);
  virtual int Draw(IUIImage* pUIImage, IUnknown* pGC, TUIRectangle rect);
};

#line 15 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IFontManager.h"



typedef struct
{
  float size;                ///< height in ppem (20.0 ppem)
  float width;               ///< width in ppem; (0 - treated as equal to size)
  float skew;                ///< skew angle (0)
  float orientation;         ///< glyph rotation, degrees clockwise (0.0)

  float bold_pct;            ///< boldness value (0)
  float stroke_pct;          ///< stroke width (0)
  float edgeThickness;       ///< edge thickness in pixels (0)
  float shadowLength_x;      ///< x-direction length of shadow in pixels (0)
  float shadowLength_y;      ///< y-direction length of shadow in pixels (0)

  u16 TUIEmphasisStyle;   ///< emphasis such as bold/italics (UI_Emphasis_Normal)
  u16 TUIBaselineStyle;   ///< text baseline style (UI_Baseline_Normal)
  u16 TUIEdgeStyle;       ///< text edge style (UI_Edge_Normal)
  u16 TUIRenderStyle;     ///< rendering style (UI_Render_Default)

}TUIFontData;

typedef unsigned char TUIFontStyle;

const TUIFontStyle UIFontStylePlain = 0;      ///<The plain style enum
const TUIFontStyle UIFontStyleBold = 1;       ///<The bold style enum.
const TUIFontStyle UIFontStyleItalic = 2;     ///<The italic style enum
const TUIFontStyle UIFontStyleUnderlined = 4; ///<The underlined style enum

typedef enum
{
  UIFontSizeMedium = 0,     ///<The "medium" system-dependent font size
  UIFontSizeSmall = 8,      ///<The "small" system-dependent font size
  UIFontSizeLarge = 16      ///<The "large" system-dependent font size
}TUIFontSize;

typedef enum
{
  UIFontFaceSystem = 0,       ///<The "system" font face
  UIFontFaceMonoSpace = 32,   ///<The "monospace" font face.
  UIFontFaceProportional = 64 ///<The "proportional" font face.
}TUIFontFace;

class IFont: public IUnknown
{
public:
  virtual int GetFace(TUIFontFace* buf);
  virtual int GetSize(TUIFontSize* buf);
  virtual int GetStyle(TUIFontStyle* buf);
  virtual int GetFontAscent(long* pAscent);
  virtual int GetFontHeight(long* font_size);
  virtual int IsBold();
  virtual int IsItalic();
  virtual int IsPlain();
  virtual int IsUnderlined();
  virtual int GetFontStyle(IUnknown* pIUIFontStyle);
};

class IFontFactory: public IUnknown
{
public:
  virtual int GetFont(TUIFontFace Face, TUIFontSize Size, TUIFontStyle Style, IFont** pFont);
  virtual int GetDefaultFont(IFont** pFont);
  virtual int GetDefaultFontSettings(TUIFontSize Size, TUIFontData* pFontData);
  virtual int CreateDefaultFont(TUIFontData* pfontData, IFont** pFont);
  virtual int CreateFontFromFamilyName(IUnknown* pIFamilyName, TUIFontData* pfontData, IFont** pFont);
  virtual int CreateFontFromFile(IUnknown* pIFullPath, TUIFontData* pfontData, IFont** pFont);
};

class IFontManager: public IUnknown
{
public:
  virtual void GetFontFactory(IFontFactory** pFontFactory);
};

#line 16 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IUIRichTextLayoutOptions.h"



typedef unsigned long FUint32;

class IRichText;

const int START_INDEX = 0x8000000A;
const int END_INDEX = 0x7FFFFFF5;

typedef struct
{
  long numGlyphs;    ///< number of glyphs on the line
  long startIndex;   ///< IUIRichText character index of first character in line
  long endIndex;     ///< IUIRichText character index of last character in line
  TUIRectangle boundingBox;  ///< actual "inked" area of the line -- relative to line's origin
  TUIRectangle advanceBox;   ///< box spanning origin to next advance point -- relative to line's origin
  unsigned char bidiBaseLevel;///< bidi base level for line -- odd if Right-To-Left, even if Left-To-Right
  TUIPoint lineOrigin;   ///< absolute coordinates for line's origin, only meaningful if lineFlags has UI_LINE_DISPLAYED set
  long lineFlags;    ///< flags like UI_LINE_COMPOSED and UI_LINE_DISPLAYED
  long baseline;     ///< amount to add to lineOrigin.y to get baseline
  long top;          ///< amount to add to lineOrigin.y to get top of line (used for overline, and background color)
  long bottom;       ///< amount to add to lineOrigin.y to get bottom of line (used for background color)
  long alignment;///< alignment of line (UIText_alignLeft, UIText_alignRight, or UIText_alignCenter)
}TUILineInfo;

typedef struct
{
  long sourceIndex; ///< character index in НUIRichText block
  long glyphID;     ///< glyph index in font
  long x;           ///< the x coordinate relative to the line's origin
  long y;           ///< the y coordinate relative to the line's origin
  TUIRectangle boundingBox; ///< bounding box relative to the glyph's position (x,y)
}TUIGlyphInfo;

typedef struct
{
  long numLines;         ///< number of lines in the layout
  long numContainersUsed;///< number of containers actually used
  TUIRectangle boundingBox;      ///< text layout bounding box
  TUIRectangle advanceBox;       ///< text layout advance box
}TUILayoutInfo;

typedef struct
{
  long numLines;          ///< count of lines in the container
  long firstLineNumber;   ///< index of first line in container
  TUIRectangle boundingBox;  ///< text container bounding box
  TUIRectangle advanceBox;   ///< text container advance box
}TUIContainerInfo;

class IRichTextLayout: public IUnknown
{
public:
  virtual int SetControl(void* pIUIRichTextLayoutControl);
  virtual int GetControl(void** pIUIRichTextLayoutControl);
  virtual int SetOptions(void* pIUIRichTextLayoutOptions);
  virtual int GetOptions(void* pIUIRichTextLayoutOptions);
  virtual int Subscribe(void* pICBUIRichTextLayout, u16 msgBase, int clientData, unsigned long* pSubscriptionHandle);
  virtual int Unsubscribe(unsigned long SubscriptionHandle);
  virtual int SetText(IRichText* pTextObject);
  virtual int GetText(IRichText** pTextObject);
  virtual int Compose(int lineWidth);
  virtual int ComposeLine(int lineWidth, int ascenderLimit, int descenderLimit, int lineNumber, long* pStartIndex, long* pEndIndex, long* pCharsLeftToCompose);
  virtual int ComposeLineInit(long x, long y, long lineNumber);
  virtual int PositionLine(long x, long y, long lineNumber);  virtual int ComposeContainers(TUIRectangle* pComposeRect);
  virtual int GetWidthOfLongestRemainingLineBreakSequence(int* pWidth, long* pStartIndex, long* pEndIndex);
  virtual int GetLineInfo(long lineNumber, TUILineInfo* pInfo);  virtual int MapCharIndex(long index, long* pLineNumber);
  virtual int GetGlyphInfo(long lineNumber, long glyphIndex, bool needBoundingBox, TUIGlyphInfo* pInfo);
  virtual int GetNumberOfLines(long* pNumberOfLines);  virtual int GetLayoutInfo(TUILayoutInfo* pLayoutInfo);
  virtual int GetContainerInfo(long containerIndex, TUIContainerInfo* pContainerInfo);
  virtual int Display(IUnknown* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int DisplayContainers(IUnknown* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int DisplayLine(IUnknown* pGC, long x, long y, TUIRectangle* pInvalidateRect);
  virtual int AddTextContainer(IUnknown* pIUITextContainer, long containerID, TUIPoint* pContainerOrigin);
  virtual int RemoveTextContainer(long containerID);
};

// IUIRichTextLayoutOptions ----------------------------------------------------

typedef enum
{
  /* layout algorithm options */
  UIRichTextLayoutOptionsTag_Disable_BiDi,                              ///< Disables the bidirectional algorithm 
  UIRichTextLayoutOptionsTag_Disable_Complex_Shaping,                   ///< Disables all complex shaping
  UIRichTextLayoutOptionsTag_Disable_Diacritics_Postitioning,           ///< Disables the diacritics positioning system
  UIRichTextLayoutOptionsTag_Disable_Normalization,                     ///< Disables Unicode text normalization
  UIRichTextLayoutOptionsTag_Disable_OpenType_Layout,                   ///< Disables OpenType layout table processing
  UIRichTextLayoutOptionsTag_Disable_Thai_Line_Breaking,                ///< Disables the Thai line breaking algorithm
  UIRichTextLayoutOptionsTag_Enable_Kerning,                            ///< Enables pairwise kerning if supported by font engine (not yet supported by layout engine)
  UIRichTextLayoutOptionsTag_Limit_Bounding_Box_To_Comp_Width,          ///< nsures that the text bounding box does not exceed the width of the text container
  UIRichTextLayoutOptionsTag_Enable_Forced_Monospace,                   ///< Enables forced monospace mode, for use in spacing grapheme choices for multi-tap input
  UIRichTextLayoutOptionsTag_Limit_Width_To_Longest_LineBreak_Sequence, ///z Limits composition width to that of longest linebreak sequence (for use in block layout mode only)

  /* substituion dictionaries */
  UIRichTextLayoutOptionsTag_Enable_Icons,                              ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutControl)
  UIRichTextLayoutOptionsTag_Enable_Emoticons,                          ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutControl)
  UIRichTextLayoutOptionsTag_Enable_Custom_Icons,                       ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutOptions)
  UIRichTextLayoutOptionsTag_Enable_Custom_Emoticons,                   ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutOptions)

  /* Enable draw options - used for layout diagnostics */
  UIRichTextLayoutOptionsTag_Draw_Line_Advance_Box,                     ///< For each text line draw a rectangle showing its advance box
  UIRichTextLayoutOptionsTag_Draw_Line_Bounding_Box,                    ///< For each text line draw a rectangle showing the bounding box 
  UIRichTextLayoutOptionsTag_Draw_Text_Direction,                       ///< For each line draw the text baseline
  UIRichTextLayoutOptionsTag_Draw_Potential_Line_Breaks,                ///< Draw a colored line indicating the text direction
  UIRichTextLayoutOptionsTag_Draw_Word_Boundaries,                      ///< Draw a vertical line between graphemes where line breaks can occur
  UIRichTextLayoutOptionsTag_Draw_Shaping_Boundaries,                   ///< Draw a vertical line at each word boundary
  UIRichTextLayoutOptionsTag_Draw_Baseline,                             ///< Draw a vertical line at each shaping boundary 
  UIRichTextLayoutOptionsTag_Draw_Text_Containers,                      ///< Draw a rectangle at edge of text containers 
  UIRichTextLayoutOptionsTag_Draw_Anchored_Objects                      ///< Draw a rectangle at edge of anchored objects 

}TUIRichTextLayoutOptionsTag;

typedef enum
{
  UIHighlight_ReverseVideoMode = 0,    ///< selected text displayed reverse video
  UIHighlight_ColorMode,               ///< selected text displayed with user-specified colors
  UIHighlight_Disabled                 ///< selected text displayed without highlighting
}TUIHighlightMode;

typedef enum
{
  UICustomDictionary_Icons = 0,         ///< icons dictionary
  UICustomDictionary_Emoticons          ///< emoticons dictionary
}TUICustomDictionary;

typedef FUint32 TColour;
typedef FUint32 TUILineBreakModel;

const TUILineBreakModel UILineBreakBit_Use_Legal_Line_Break_If_Able	= 0x0001;
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Grapheme		= 0x0002;
const TUILineBreakModel UILineBreakBit_OK_To_Break_On_Glyph		= 0x0004;
const TUILineBreakModel UILineBreakBit_Korean_Uses_East_Asian_Style	= 0x0008;
const TUILineBreakModel UILineBreakBit_Wrap_WhiteSpaces			= 0x0010;
const TUILineBreakModel UILineBreakBit_Hide_Initial_Wrapped_WhiteSpace	= 0x0020;

class IUIRichTextLayoutOptions: public IUnknown
{
public:
  virtual int Set(TUIRichTextLayoutOptionsTag tag, bool value);
  virtual int SetLineBreakModel(TUILineBreakModel Model);
  virtual int SetTabStop(float position, char alignment, char leader);
  virtual int ClearTabStop(char index);
  virtual int SetTabStopPositionDefault(float pos);
  virtual int SetHyphenChar(FUint32 HyphenChar);
  virtual int SetTruncationChar(FUint32 TruncationChar);
  virtual int SetMonospaceMinPadding(float minPadding);
  virtual int SetMonospaceMinWidth(float minWidth);
  virtual int SetHighlightMode(TUIHighlightMode Mode);
  virtual int SetHighlightBackgroundColor(TColour Value);
  virtual int SetHighlightTextColor(TColour Value);
  virtual int Get(TUIRichTextLayoutOptionsTag tag, bool* pValue);
  virtual int GetLineBreakModel(TUILineBreakModel* pModel);
  virtual int GetTabStop(char index, float* pPosition, char* pAlignment, u16* pLeader);
  virtual int GetTabStopPositionDefault(float* pPos);
  virtual int GetHyphenChar(FUint32* pHyphenChar);
  virtual int GetTruncationChar(FUint32* pTruncationChar);
  virtual int GetHighlightMode(TUIHighlightMode* pMode);
  virtual int GetHighlightBackgroundColor(TColour* pValue);
  virtual int GetHighlightTextColor(TColour* pValue);
  virtual int GetMonospaceMinPadding(float* pMinPadding);
  virtual int GetMonospaceMinWidth(float* pMinWidth);
  virtual int AddDictionary(TUICustomDictionary dictionary, IUnknown* pIFullPath);
  virtual int RemoveDictionary(TUICustomDictionary dictionary);
};

#line 17 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\ITextRenderingManager.h"



#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\Basic_types.h"



/**
  * Signed integer number. The size of this type is platform-
  * and compiler-specific but is at least 32 bits.
  */
typedef long TSigned;

/**
  * Unsigned integer number. The size of this type is platform-
  * and compiler-specific but is at least 32 bits.
  */
typedef unsigned long TUnsigned;

/**
  * The smallest floating point type. The size of this type
  * is platform- and compiler-specific.
  *
  * When mapped to C or C++, TFloat will be mapped to C/C++ fundamental type 
  * float. 
  */
typedef float TFloat;

/**
  * The largest floating point type. The size of this type
  * is platform- and compiler-specific.
  * The precision of this type is at least as good as TFloat.
  *
  * When mapped to C or C++, TDouble will be mapped to C/C++ fundamental type 
  * double. 
  */
typedef double TDouble;

/**
  * Number representing the Boolean true and false values.
  */
typedef bool TBool;

/**
  * Integer number representing character ranging according
  * to the selected character representation.
  * 0 <= TChar <= TCHAR_MAX.
  *
  * Unless otherwise stated, the format of the selected character
  * representation is UCS-2 (ISO/IEC 10646).
  */
typedef wchar_t TChar;

/**
  * A constant holding the maximum value a TChar can have.
  */
const TChar TCHAR_MAX = 0xFFFF;

/**
  * Type used to represent ASCII (ISO 8859-1, ISO Latin-1) characters. 
  * 0 <= TAscii <= TASCII_MAX.
  */
typedef char TAscii;

/**
  * A constant holding the maximum value a TAscii can have.
  */
const TAscii TASCII_MAX = 0xFF;

/**
  * Reference representing an indirection to a physical address.
  */
typedef unsigned long THnd;

/**
  * When used as a method return type, TVoid specifies that the method does not 
  * return a value. 
  * When used in the declaration of a pointer, TVoid specifies that the pointer is "universal".
  * A TVoid pointer can be converted into any other type of data pointer.
  */
typedef void TVoid;

/**
  * Signed integer (32 bit representation). FSINT32_MIN <= FSint32 <= FSINT32_MAX.
  */
typedef long FSint32;

/**
  * A constant holding the maximum value an FSint32 can have.
  */
const FSint32 FSINT32_MAX = 0x7FFFFFFF;

/**
  * A constant holding the minimum value an FSint32 can have.
  */
const FSint32 FSINT32_MIN = -FSINT32_MAX - 1;

/**
  * Signed integer (16 bit representation). FSINT16_MIN <= FSint16 <= FSINT16_MAX.
  */
typedef short FSint16;

/**
  * A constant holding the maximum value an FSint16 can have.
  */
const FSint16 FSINT16_MAX = 0x7FFF;

/**
  * A constant holding the minimum value an FSint16 can have.
  */
const FSint16 FSINT16_MIN = -FSINT16_MAX - 1;

/**
  * Signed integer (8 bit representation). FSINT8_MIN <= FSint8 <= FSINT8_MAX.
  */
typedef char FSint8;

/**
  * A constant holding the maximum value an FSint8 can have.
  */
const FSint8 FSINT8_MAX = 0x7F;

/**
  * A constant holding the minimum value an FSint8 can have.
  */
//const FSint8 FSINT8_MIN = -FSINT8_MAX - 1;

/**
  * Unsigned integer (32 bit representation). 0 <= FUint32 <= FUINT32_MAX.
  */
typedef unsigned long FUint32;

/**
  * A constant holding the maximum value an FUint32 can have.
  */
const FUint32 FUINT32_MAX = 0xFFFFFFFF;

/**
  * Unsigned integer (16 bit representation). 0 <= FUint16 <= FUINT16_MAX.
  */
typedef unsigned short FUint16;

/**
  * A constant holding the maximum value an FUint16 can have.
  */
const FUint16 FUINT16_MAX = 0xFFFF;

/**
  * Unsigned integer (8 bit representation). 0 <= FUint8 <= FUINT8_MAX.
  */
typedef unsigned char FUint8;

/**
  * A constant holding the maximum value an FUint8 can have.
  */
const FUint8 FUINT8_MAX = 0xFF;

/**
  * Return type for methods that do not return any value when the service
  * runs to a successful completion. This type contains error information in
  * case the service fails.
  */ 
typedef TSigned RVoid;

/**
  * Return type for methods that return a Boolean result when the service
  * runs to a successful completion. This type contains error information in
  * case the service fails. Value 0 represents false, value 1 represents
  * true, while other values represent failure.
  */ 
typedef TSigned RBool;

/**
  * Return type for methods that return a selector (one out of many)
  * result when the service runs to a successful completion. This type contains 
  * error information in case the service fails. 
  * The range is limited to 16 bits and is intended for results indicating
  * which of several options that have been chosen.
  */ 
typedef TSigned RSel;

/**
  * Unique identifier for Interface and Component Id:s.
  *
  * @brief Unique identifier for Interface and Component Id:s.
  *
  * @param Uuid 16 bytes that are assumed to be globally (world-wide) unique.
  */
typedef struct
{
  FUint8 Uuid[16];
}
TUuid;

#line 5 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\ITextRenderingManager.h"

const FSint32 UITEXTSTYLE_START_OF_TEXT = FSINT32_MIN;
const FSint32 UITEXTSTYLE_END_OF_TEXT = FSINT32_MAX;

const FSint32 UIRICHTEXTLAYOUT_MAX_LINE_WIDTH = 0x00007FFF;

typedef enum
{
  UIEncoding_Encoding_Not_Specified = 0,
  UIEncoding_ASCII,           ///< plain ASCII text
  UIEncoding_UTF8,            ///< text encoded in UTF-8
  UIEncoding_UTF16,           ///< text encoded in UTF-16
  UIEncoding_UTF32            ///< text encoded in UTF-32
}TUIEncoding;

typedef enum
{
  UILineSpacing_Single_Line,        ///< single spacing
  UILineSpacing_150_Line,           ///< one and a half line spacing
  UILineSpacing_Double_Line,        ///< double spacing
  UILineSpacing_Exact_Line_Spacing, ///< line spacing set to lineSpacingAmount
  UILineSpacing_Multiple_Line       ///< line spacing set to multiple of line spacing * lineSpacingAmount
}TUILineSpacing;

typedef enum
{
  UIText_alignLeft,        ///< left aligned
  UIText_alignRight,       ///< center aligned
  UIText_alignCenter,      ///< right aligned
  UIText_alignLeftDynamic, ///< left aligned but first character can override
  UIText_alignRightDynamic ///< right aligned but first character can override
}TUITextAlignment;

typedef enum
{
  UITextDirection_Netural,   ///< text with no inherent direction
  UITextDirection_LTR,       ///< left-to-right text
  UITextDirection_RTL        ///< right-to-left text
}TUITextDirection;

typedef enum
{
  UILine_None,        ///< no line
  UILine_SingleSolid  ///< single solid line
}TUILineStyle;

typedef struct
{
  float xAdvance;              ///< x-dimension advance width
  float yAdvance;              ///< y-dimension advance width
  TUIRectangle boundingBox;     ///< bounding box of image, with respect to its origin
}TUIInlineObjectMetrics;

class IRichText: public IUnknown
{
public:
  virtual int SetString(void* pIString); 										//Set a string (UTF16)
  virtual int GetString(void** ppIString); 										//Get a string (UTF16)
  virtual int InsertText(void * text,FSint32 text_len,TUIEncoding encoding,FSint32 insertIndex); 			//Inserts a text run by copy to a IUIRichText object.
  virtual int InsertTextUTF16(u16 *text, int length_text,FSint32 insertIndex); 					//Inserts a text run by copy to a IUIRichText object. 
  virtual int RemoveText(FSint32 startIndex,FSint32 endIndex); 							//Deletes text from a text object that has copied text.
  virtual int InsertRun(void *text,FSint32 text_len,TUIEncoding encoding,void *pInsertHere); 				//Insert a text run by reference.
  virtual int ChangeRun(void* new_text,FSint32 length_text, TUIEncoding encoding, void* old_text, FSint32 hints); 	//Change a referenced text run.
  virtual int RemoveRun(void* text); 											//Removes a referenced text run from a IUIRichText object.
  virtual int GetRunRange(void* text, FSint32* startIndex, FSint32* endIndex); 						//Gets the index range of a run in a IUIRichText.
  virtual int GetParagraphRange(FSint32 paragraph,FSint32 *pStartIndex,FSint32 *pEndIndex); 				//Gets the index range of a paragraph in a TsText.
  virtual int GetParagraphCount(FSint32 *pParagraphCount); 								//Gets the number of paragraphs in a TsText.
  virtual int GetParagraph(FSint32 char_index,FSint32 *pParagraphNumber); 						//Gets the paragraph number for a given index in TsText.
  virtual int GetLength(FSint32 *pLength); 										//Returns the text length in characters.
  virtual int GetChar(FSint32 index,FUint32 *pChar); 									//Returns the character at a given index as a UTF32 value.
  virtual int SetAlignment(int value,FSint32 startIndex,FSint32 endIndex); 				//Sets the paragraph alignment attribute.
  virtual int SetBackgroundColor(int color,FSint32 startIndex,FSint32 endIndex);					//Sets background color attribute.
  virtual int SetBiDiOverride(TUITextDirection textdir,FSint32 startIndex,FSint32 endIndex);				//Sets the bidirectional override attribute.
  virtual int SetCharSpacing(float value,FSint32 startIndex,FSint32 endIndex); 					//Sets additional spacing between characters.
  virtual int SetEdgeColor(int color,FSint32 startIndex,FSint32 endIndex); 						//Sets edge color attribute.
  virtual int SetFontStyle(void *pIUIFontStyle,FSint32 startIndex,FSint32 endIndex);					//Sets the font style attribute.
  virtual int SetIndent(TUITextAlignment align,FSint32 startIndex,FSint32 endIndex);					//Sets the amount the first line of each paragraph is indented.
  virtual int SetInlineObjectID(wchar_t imageID,FSint32 startIndex,FSint32 endIndex);
  virtual int SetInlineObjectMetrics(wchar_t imageID,TUIInlineObjectMetrics *pValue);
  virtual int SetJustification(bool value,FSint32 startIndex,FSint32 endIndex);
  virtual int SetLanguage(int language,FSint32 startIndex,FSint32 endIndex);
  virtual int SetLeftIndent(float value,FSint32 startIndex,FSint32 endIndex);						//Sets the amount the left side of each paragraph in the range is indented.
  virtual int SetLinePaddingAfter(float value,FSint32 startIndex,FSint32 endIndex);					//Sets an amount of extra space to pad after each line.
  virtual int SetLinePaddingBefore(float value,FSint32 startIndex,FSint32 endIndex);					//Sets an amount of extra space to pad before each line.
  virtual int SetLineSpacing(TUILineSpacing value,FSint32 startIndex,FSint32 endIndex);				//Sets line spacing attribute.
  virtual int SetLineSpacingAmount(float value,FSint32 startIndex,FSint32 endIndex);					//Sets line spacing amount attribute.
  virtual int SetLineSpacingAttributeMode(bool isParaAttrib);
  virtual int SetOverline(TUILineStyle value,FSint32 startIndex,FSint32 endIndex);					//Sets text overline attribute.
  virtual int SetOverlineColor(int color,FSint32 startIndex,FSint32 endIndex);						//Sets overline color attribute.
  virtual int SetRightIndent(float value,FSint32 startIndex,FSint32 endIndex);						//Sets the amount the right side of each paragraph in the range is indented.
  virtual int SetSpaceAfter(float value,FSint32 startIndex,FSint32 endIndex);
  virtual int SetSpaceBefore(float value,FSint32 startIndex,FSint32 endIndex);
  virtual int SetStrikeout(TUILineStyle value,FSint32 startIndex,FSint32 endIndex);
  virtual int SetStrikeoutColor(int color,FSint32 startIndex,FSint32 endIndex);
  virtual int SetTextColor(int color,FSint32 startIndex,FSint32 endIndex);
  virtual int SetTextDirection(TUITextDirection value,FSint32 startIndex,FSint32 endIndex);				//Sets the paragraph base text direction attribute.
  virtual int SetUnderline(TUILineStyle value,FSint32 startIndex, FSint32 endIndex);
  virtual int SetUnderlineColor(int color,FSint32 startIndex,FSint32 endIndex);
  virtual int SetWordSpacing(float value,FSint32 startIndex,FSint32 endIndex);						//Sets additional spacing between words.
  virtual int GetAlignment(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUITextAlignment *pAlignment);
  virtual int GetBackgroundColor(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,int *pBackgroundColor);
  virtual int GetBiDiOverride(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUITextDirection *pValue);
  virtual int GetCharSpacing(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *pSpacing);
  virtual int GetEdgeColor(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,int *pEdgeColor);
  virtual int GetFontStyle(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,void **ppIFontStyle);
  virtual int GetIndent(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *pIndent);
  virtual int GetInlineObjectID(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,wchar_t *id);
  virtual int GetInlineObjectMetrics(wchar_t id,TUIInlineObjectMetrics *pValue);
  virtual int GetJustification(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,bool *justification_value);
  virtual int GetLanguage(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,void *pLanguage);
  virtual int GetLeftIndent(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *indent_value);
  virtual int GetLinePaddingAfter(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *line_padding_value);
  virtual int GetLinePaddingBefore(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *line_padding_value);
  virtual int GetLineSpacing(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUILineSpacing *pLineSpacing);
  virtual int GetLineSpacingAmount(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *pLineSpacingAmount);
  virtual bool GetLineSpacingAttributeMode();
  virtual int GetOverline(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUILineStyle *pValue);
  virtual int GetOverlineColor(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,int *color);
  virtual int GetRightIndent(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *indent_value);
  virtual int GetSpaceAfter(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *space);
  virtual int GetSpaceBefore(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *space);
  virtual int GetStrikeout(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUILineStyle *strikeout_style);
  virtual int GetStrikeoutColor(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,int *color);
  virtual int GetTextColor(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,int *color);
  virtual int GetTextDirection(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUITextDirection *pTextDirection);
  virtual int GetUnderline(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,TUILineStyle *pUnderline);
  virtual int GetUnderlineColor(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,int *pUnderlineColor);
  virtual int GetWordSpacing(FSint32 index,FSint32 *startIndex,FSint32 *endIndex,float *word_spacing);
};									//Set a string (UTF16)  virtual int GetString(void** ppIString); 										//Get a string (UTF16)  virtual int InsertText(void* text, FSint32 text_len, TUIEncoding encoding, FSint32 insertIndex); 			//Inserts a text run by copy to a IUIRichText object.  virtual int InsertTextUTF16(u16* text, int length_text, FSint32 insertIndex); 					//Inserts a text run by copy to a IUIRichText object.  virtual int RemoveText(FSint32 startIndex, FSint32 endIndex); 							//Deletes text from a text object that has copied text.  virtual int InsertRun(void* text, FSint32 text_len, TUIEncoding encoding, void* pInsertHere); 				//Insert a text run by reference.  virtual int ChangeRun(void* new_text, FSint32 length_text, TUIEncoding encoding, void* old_text, FSint32 hints); 	//Change a referenced text run.  virtual int RemoveRun(void* text); 											//Removes a referenced text run from a IUIRichText object.  virtual int GetRunRange(void* text, FSint32* startIndex, FSint32* endIndex); 						//Gets the index range of a run in a IUIRichText.  virtual int GetParagraphRange(FSint32 paragraph, FSint32* pStartIndex, FSint32* pEndIndex); 				//Gets the index range of a paragraph in a TsText.  virtual int GetParagraphCount(FSint32* pParagraphCount); 								//Gets the number of paragraphs in a TsText.  virtual int GetParagraph(FSint32 char_index, FSint32* pParagraphNumber); 						//Gets the paragraph number for a given index in TsText.  virtual int GetLength(FSint32* pLength); 										//Returns the text length in characters.  virtual int GetChar(FSint32 index, FUint32* pChar); 									//Returns the character at a given index as a UTF32 value.  virtual int SetAlignment(TUITextAlignment value, FSint32 startIndex, FSint32 endIndex); 				//Sets the paragraph alignment attribute.  virtual int SetBackgroundColor(int color, FSint32 startIndex, FSint32 endIndex);					//Sets background color attribute.  virtual int SetBiDiOverride(TUITextDirection textdir, FSint32 startIndex, FSint32 endIndex);				//Sets the bidirectional override attribute.  virtual int SetCharSpacing(float value, FSint32 startIndex, FSint32 endIndex); 					//Sets additional spacing between characters.  virtual int SetEdgeColor(int color, FSint32 startIndex, FSint32 endIndex); 						//Sets edge color attribute.  virtual int SetFontStyle(void* pIUIFontStyle, FSint32 startIndex, FSint32 endIndex);					//Sets the font style attribute.  virtual int SetIndent(TUITextAlignment align, FSint32 startIndex, FSint32 endIndex);					//Sets the amount the first line of each paragraph is indented.  virtual int SetInlineObjectID(wchar_t imageID, FSint32 startIndex, FSint32 endIndex);  virtual int SetInlineObjectMetrics(wchar_t imageID, TUIInlineObjectMetrics* pValue);  virtual int SetJustification(bool value, FSint32 startIndex, FSint32 endIndex);  virtual int SetLanguage(int language, FSint32 startIndex, FSint32 endIndex);  virtual int SetLeftIndent(float value, FSint32 startIndex, FSint32 endIndex);						//Sets the amount the left side of each paragraph in the range is indented.  virtual int SetLinePaddingAfter(float value, FSint32 startIndex, FSint32 endIndex);					//Sets an amount of extra space to pad after each line.  virtual int SetLinePaddingBefore(float value, FSint32 startIndex, FSint32 endIndex);					//Sets an amount of extra space to pad before each line.  virtual int SetLineSpacing(TUILineSpacing value, FSint32 startIndex, FSint32 endIndex);				//Sets line spacing attribute.  virtual int SetLineSpacingAmount(float value, FSint32 startIndex, FSint32 endIndex);					//Sets line spacing amount attribute.  virtual int SetLineSpacingAttributeMode(bool isParaAttrib);  virtual int SetOverline(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);					//Sets text overline attribute.  virtual int SetOverlineColor(int color, FSint32 startIndex, FSint32 endIndex);						//Sets overline color attribute.  virtual int SetRightIndent(float value, FSint32 startIndex, FSint32 endIndex);						//Sets the amount the right side of each paragraph in the range is indented.  virtual int SetSpaceAfter(float value, FSint32 startIndex, FSint32 endIndex);  virtual int SetSpaceBefore(float value, FSint32 startIndex, FSint32 endIndex);  virtual int SetStrikeout(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);  virtual int SetStrikeoutColor(int color, FSint32 startIndex, FSint32 endIndex);  virtual int SetTextColor(int color, FSint32 startIndex, FSint32 endIndex);  virtual int SetTextDirection(TUITextDirection value, FSint32 startIndex, FSint32 endIndex);				//Sets the paragraph base text direction attribute.  virtual int SetUnderline(TUILineStyle value, FSint32 startIndex, FSint32 endIndex);  virtual int SetUnderlineColor(int color, FSint32 startIndex, FSint32 endIndex);  virtual int SetWordSpacing(float value, FSint32 startIndex, FSint32 endIndex);						//Sets additional spacing between words.  virtual int GetAlignment(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUITextAlignment* pAlignment);  virtual int GetBackgroundColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* pBackgroundColor);  virtual int GetBiDiOverride(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUITextDirection* pValue);  virtual int GetCharSpacing(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* pSpacing);  virtual int GetEdgeColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* pEdgeColor);  virtual int GetFontStyle(FSint32 index, FSint32* startIndex, FSint32* endIndex, void** ppIFontStyle);  virtual int GetIndent(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* pIndent);  virtual int GetInlineObjectID(FSint32 index, FSint32* startIndex, FSint32* endIndex, wchar_t* id);  virtual int GetInlineObjectMetrics(wchar_t id, TUIInlineObjectMetrics* pValue);  virtual int GetJustification(FSint32 index, FSint32* startIndex, FSint32* endIndex, bool* justification_value);  virtual int GetLanguage(FSint32 index, FSint32* startIndex, FSint32* endIndex, void* pLanguage);  virtual int GetLeftIndent(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* indent_value);  virtual int GetLinePaddingAfter(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* line_padding_value);  virtual int GetLinePaddingBefore(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* line_padding_value);  virtual int GetLineSpacing(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineSpacing* pLineSpacing);  virtual int GetLineSpacingAmount(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* pLineSpacingAmount);  virtual bool GetLineSpacingAttributeMode();  virtual int GetOverline(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineStyle* pValue);  virtual int GetOverlineColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* color);  virtual int GetRightIndent(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* indent_value);  virtual int GetSpaceAfter(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* space);  virtual int GetSpaceBefore(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* space);  virtual int GetStrikeout(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineStyle* strikeout_style);  virtual int GetStrikeoutColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* color);  virtual int GetTextColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* color);  virtual int GetTextDirection(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUITextDirection* pTextDirection);  virtual int GetUnderline(FSint32 index, FSint32* startIndex, FSint32* endIndex, TUILineStyle* pUnderline);  virtual int GetUnderlineColor(FSint32 index, FSint32* startIndex, FSint32* endIndex, int* pUnderlineColor);  virtual int GetWordSpacing(FSint32 index, FSint32* startIndex, FSint32* endIndex, float* word_spacing);};

class ITextRenderingFactory: public IUnknown
{
public:
  virtual int CreateFontResourceManager(IUnknown* pIUIFontResourceManager);
  virtual int CreateFontStyleManager(IUnknown* pIUIFontStyleManager);
  virtual int CreateRichText(IRichText** pRichText);
  virtual int CreateTextContainer(IUnknown* pIUITextContainer);
  virtual int CreateRichTextLayout(IRichText* pRichText, IUnknown* pIUIRichTextLayoutControl, IUnknown* pIUIRichTextLayoutOptions, IRichTextLayout** pRichTextLayout);
  virtual int CreateSingleLineLayout(IUnknown* pIUIRichTextLayoutControl, IUnknown* pIUIRichTextLayoutOptions, IUnknown** pIUISingleLineLayout);
  virtual int CreateRichTextLayoutControl(IUnknown** pIUIRichTextLayoutControl);
  virtual int CreateRichTextLayoutOptions(IUIRichTextLayoutOptions** pIUIRichTextLayoutOptions);
  virtual int CreatePolygon(IUnknown** pIUIPolygon);
  virtual int CreateBasicTextHandler(IUnknown** pIUIBasicTextHandling);};

class ITextRenderingManager: public IUnknown
{
public:
  virtual int GetTextRenderingFactory(ITextRenderingFactory** pTextRenderingFactory);
  virtual int GetFontConfigFilePath(IUnknown** pIString);
  virtual int GetFontEngineConfigFilePath(IUnknown** pIString);
};

#line 18 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IAudioControlManager.h"



#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\AudioControl_types.h"









const FUint16 AUDIOCONTROL_DEBUGMENU_STRING_MAXLENGTH = 79;
typedef wchar_t TAudioControl_DebugMenuString[AUDIOCONTROL_DEBUGMENU_STRING_MAXLENGTH+1];

typedef enum
{
  AUDIOCONTROL_UED_GENERAL_ERROR  = 0x000,    /**< Returned when none of the other error codes are applicable */

  /* AudioPlayer specific return values */
  AUDIOCONTROL_UED_NOT_AUTHORIZED = 0x001,   /**< Returned when there are not any available resources, and another ongoing activity has higher priority */
  AUDIOCONTROL_UED_FILE_NOT_FOUND = 0x002,   /**< Returned when the specified file is not found */
  AUDIOCONTROL_UED_DRM_ERROR      = 0x004,   /**< Returned when the specified file is a DRM file, and the credentials not allows playback */

  /* Internal ac channel return value */
  AUDIOCONTROL_UED_ROUTED_TO_SILENT = 0x008, /**< Returned when no channel delivered due to internal channelsetting AUDIOCONTROL_CHANNELSETTING_NO_CHANNEL_IF_SILENT  */

  /* Accessory specific return values */
  AUDIOCONTROL_UED_NO_SUCH_DEVICE = 0x010,   /**< Unknown accessory */

  /* General return values, used for all categories */
  AUDIOCONTROL_UED_NOT_SUPPORTED    = 0x020,    /**< Returned when some functionality not is supported with the current platform configuration */
  AUDIOCONTROL_UED_OPA_ERROR        = 0x040,    /**< Returned when OPA is returning an error of unknown reason */
  AUDIOCONTROL_UED_OUT_OF_MEMORY    = 0x080,    /**< Returned when some allocation failed due to lack of memory */
  AUDIOCONTROL_UED_INPUT_PARAM_ERROR= 0x100  /**< Returned when there was some error in the input parameters */
} TAudioControl_ReturnValues;

typedef enum
{
  AUDIOCONTROL_NOTIFICATION_RINGER,
  AUDIOCONTROL_NOTIFICATION_ALARM,
  AUDIOCONTROL_NOTIFICATION_REQUEST,
  AUDIOCONTROL_NOTIFICATION_REQUEST_CALL,
  AUDIOCONTROL_NOTIFICATION_SUCCESS,
  AUDIOCONTROL_NOTIFICATION_FAILURE,
  AUDIOCONTROL_NOTIFICATION_PROGRESS,
  AUDIOCONTROL_NOTIFICATION_NOTIFICATION,
  AUDIOCONTROL_NOTIFICATION_REMINDER,
  AUDIOCONTROL_NOTIFICATION_DISCONNECTED,
  AUDIOCONTROL_NOTIFICATION_DISCREET,
  AUDIOCONTROL_NOTIFICATION_LOWBATTERY,
  AUDIOCONTROL_NOTIFICATION_EMPTYBATTERY,
  AUDIOCONTROL_NOTIFICATION_CHARGING,
  AUDIOCONTROL_NOTIFICATION_VIDEO,
  AUDIOCONTROL_NOTIFICATION_RETRYSUCCESS,
  AUDIOCONTROL_NOTIFICATION_TIMER,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT_SILENT,
  AUDIOCONTROL_NOTIFICATION_MESSAGECLICK,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT1,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT2,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT3,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT4,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT5,
  AUDIOCONTROL_NOTIFICATION_MESSAGEALERT6,

  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER,
  AUDIOCONTROL_NOTIFICATION_CAMERATIMER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER2,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER3,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER4,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER2_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER3_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER4_RER,
  AUDIOCONTROL_NOTIFICATION_CAMERA_FOCUS_SUCCESS,
  AUDIOCONTROL_NOTIFICATION_CAMERA_BURST,
  AUDIOCONTROL_NOTIFICATION_CAMERA_BESTPIC,

  AUDIOCONTROL_NOTIFICATION_PTT_BUDDY_JOINED,
  AUDIOCONTROL_NOTIFICATION_PTT_BUDDY_LEFT,
  AUDIOCONTROL_NOTIFICATION_PTT_FLOOR_AVAILABLE,
  AUDIOCONTROL_NOTIFICATION_PTT_SPEAK_NOW,
  AUDIOCONTROL_NOTIFICATION_PTT_RINGTONE,
  AUDIOCONTROL_NOTIFICATION_PTT_BARGE_ALERT,
  AUDIOCONTROL_NOTIFICATION_PTT_FLOOR_TAKEN,

  AUDIOCONTROL_NOTIFICATION_SPORT_ABOVE_SPEED,
  AUDIOCONTROL_NOTIFICATION_SPORT_BELOW_SPEED,
  AUDIOCONTROL_NOTIFICATION_SPORT_START,
  AUDIOCONTROL_NOTIFICATION_SPORT_MILESTONE,
  AUDIOCONTROL_NOTIFICATION_SPORT_END,
  AUDIOCONTROL_NOTIFICATION_SPORT_FAILURE,

  AUDIOCONTROL_NOTIFICATION_IM_BUDDY_JOINED,
  AUDIOCONTROL_NOTIFICATION_IM_BUDDY_LEFT,

  AUDIOCONTROL_NOTIFICATION_PHONE_OPEN1,
  AUDIOCONTROL_NOTIFICATION_PHONE_OPEN2,
  AUDIOCONTROL_NOTIFICATION_PHONE_OPEN3,

  AUDIOCONTROL_NOTIFICATION_VIDEOCALLPREFIX,

  AUDIOCONTROL_NOTIFICATION_CALLERNAME,

  AUDIOCONTROL_NOTIFICATION_STARTUP,

  AUDIOCONTROL_NOTIFICATION_ILM_MTCALL,
  AUDIOCONTROL_NOTIFICATION_ILM_ALARM,
  AUDIOCONTROL_NOTIFICATION_ILM_MESSAGING,
  AUDIOCONTROL_NOTIFICATION_ILM_TIMER,
  AUDIOCONTROL_NOTIFICATION_ILM_CALEVENT,
  AUDIOCONTROL_NOTIFICATION_ILM_TEST,
  AUDIOCONTROL_NOTIFICATION_ILM_DEMO,
  AUDIOCONTROL_NOTIFICATION_ILM_INTRO,
  AUDIOCONTROL_NOTIFICATION_ILM_ACCESSORY,
  AUDIOCONTROL_NOTIFICATION_ILM_CHARGEBATT,
  AUDIOCONTROL_NOTIFICATION_ILM_PREVIEW,
  AUDIOCONTROL_NOTIFICATION_ILM_POWERUP,
  AUDIOCONTROL_NOTIFICATION_ILM_POWERDOWN,
  AUDIOCONTROL_NOTIFICATION_ILM_OPENFLIP,
  AUDIOCONTROL_NOTIFICATION_ILM_CLOSEFLIP,
  AUDIOCONTROL_NOTIFICATION_ILM_STARTSLEEP,
  AUDIOCONTROL_NOTIFICATION_ILM_ENDSLEEP,

  AUDIOCONTROL_NOTIFICATION_VT_SNAPSHOT,

  AUDIOCONTROL_NOTIFICATION_VC_FAILURE,
  AUDIOCONTROL_NOTIFICATION_VC_VOICETAG,

  AUDIOCONTROL_NOTIFICATION_MAM_GUIDANCE,

  AUDIOCONTROL_NOTIFICATION_LAST
} TAudioControl_Notification;

typedef enum
{
  /* Normal Tones, such as DTMF etc. They are directly mapped from OPA, see TTone in IToneManager.idl for more info */
  AUDIOCONTROL_TONE_OFF,
  AUDIOCONTROL_TONE_KEY_1,
  AUDIOCONTROL_TONE_KEY_2,
  AUDIOCONTROL_TONE_KEY_3,
  AUDIOCONTROL_TONE_KEY_4,
  AUDIOCONTROL_TONE_KEY_5,
  AUDIOCONTROL_TONE_KEY_6,
  AUDIOCONTROL_TONE_KEY_7,
  AUDIOCONTROL_TONE_KEY_8,
  AUDIOCONTROL_TONE_KEY_9,
  AUDIOCONTROL_TONE_KEY_0,
  AUDIOCONTROL_TONE_KEY_ASTERISK,
  AUDIOCONTROL_TONE_KEY_NUMBERSIGN,
  AUDIOCONTROL_TONE_KEY_A,
  AUDIOCONTROL_TONE_KEY_B,
  AUDIOCONTROL_TONE_KEY_C,
  AUDIOCONTROL_TONE_KEY_D,
  AUDIOCONTROL_TONE_SILENCE,
  AUDIOCONTROL_RING_TONE,
  AUDIOCONTROL_TRIPLE_TONE_950_HZ,
  AUDIOCONTROL_TRIPLE_TONE_1400_HZ,
  AUDIOCONTROL_TRIPLE_TONE_1800_HZ,
  AUDIOCONTROL_RING_TONE_500_HZ,
  AUDIOCONTROL_RING_TONE_1056_HZ,
  AUDIOCONTROL_RING_TONE_1750_HZ,
  AUDIOCONTROL_RING_TONE_1900_HZ,
  AUDIOCONTROL_RING_TONE_2000_HZ,
  AUDIOCONTROL_RING_TONE_2200_HZ,
  AUDIOCONTROL_RING_TONE_2800_HZ,
  AUDIOCONTROL_RING_TONE_480_620_HZ,
  AUDIOCONTROL_RING_TONE_440_HZ,
  AUDIOCONTROL_RING_TONE_440_480_HZ,

  /* Comfort Tones, directly mapped from OPA */
  AUDIOCONTROL_DIAL,                        /**< 425Hz continuous */
  AUDIOCONTROL_SUBSCRIBER_BUSY,             /**< 425Hz on 500ms, off 500ms continuous */
  AUDIOCONTROL_CONGESTION,                  /**< 425Hz on 200ms, off 200ms continuous */
  AUDIOCONTROL_RADIO_PATH_ACKNOWLEDGE,      /**< 425Hz single tone 200ms */
  AUDIOCONTROL_RADIO_PATH_NOT_AVAILABLE,    /**< 425Hz 200ms on/off for 3 burst */
  AUDIOCONTROL_ERROR_SPECIAL_INFORMATION,   /**< 950Hz, 1400Hz and 1800Hz triple tone, on 330ms, off 1s continuous */
  AUDIOCONTROL_CALL_WAITING,                /**< 425Hz on 200ms, off 600ms, on 200ms, off 3s continuous */
  AUDIOCONTROL_RINGING,                     /**< 425Hz on 1s, off 4s continuous */

  /* SAT Tones */
  AUDIOCONTROL_SAT_POSITIVEACK,
  AUDIOCONTROL_SAT_NEGATIVEACK,
  AUDIOCONTROL_SAT_GENERALBEEP,

  AUDIOCONTROL_TONE_LAST
} TAudioControl_Tone;

typedef enum
{
  AUDIOCONTROL_TONE_REDIRECTION_NEAR_END,        /**< The tone is played in the speaker */
  AUDIOCONTROL_TONE_REDIRECTION_NEAR_AND_FAR_END, /**< The tone is played in the speaker and is also sent to the remote party */
  AUDIOCONTROL_TONE_REDIRECTION_LAST
} TAudioControl_ToneRedirection;

typedef enum
{
  AUDIOCONTROL_VOLUMETYPE_CURRENT,    /**< The current volumetype */
  AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, /**< The call volume */
  AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, /**< The ring signal volume */
  AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, /**< The media volume */
  AUDIOCONTROL_VOLUMETYPE_INPUTVOLUME, /**< FOR AUDIOCONTROL INTERNAL USE ONLY */

  AUDIOCONTROL_VOLUMETYPE_LAST
} TAudioControl_VolumeType;

typedef enum
{
  AUDIOCONTROL_TTYMODE_OFF,  /**< TTY mode set to off*/
  AUDIOCONTROL_TTYMODE_STANDARD,  /**< TTY mode set to standard*/
  AUDIOCONTROL_TTYMODE_HCO,  /**< TTY mode set to hearing carry over*/
  AUDIOCONTROL_TTYMODE_VCO, /**< TTY mode set to voice carry over*/

  AUDIOCONTROL_TTYMODE_LAST
} TAudioControl_TTYMode;

typedef enum
{
  AUDIOCONTROL_HACMODE_OFF,
  AUDIOCONTROL_HACMODE_MIC,
  AUDIOCONTROL_HACMODE_TCOIL,

  AUDIOCONTROL_HACMODE_LAST
} TAudioControl_HACMode;

typedef enum
{
  AUDIOCONTROL_VIBRATORSTATE_OFF,           /**< The vibrator is always off */
  AUDIOCONTROL_VIBRATORSTATE_ON,            /**< The vibrator is used when appropriate */
  AUDIOCONTROL_VIBRATORSTATE_ON_IF_SILENT   /**< The vibrator is used when appropriate, if silentmode is on */
} TAudioControl_VibratorState;

typedef enum
{
  AUDIOCONTROL_CALLTYPE_VOICE,  /**< VoiceCall */
  AUDIOCONTROL_CALLTYPE_VIDEO,  /**< VideoCall */

  AUDIOCONTROL_CALLTYPE_LAST
} TAudioControl_CallType;

typedef enum
{
  AUDIOCONTROL_CALLSTATE_IDLE,     /**< Should be used when no call is active */
  AUDIOCONTROL_CALLSTATE_ANSWERING,/**< Should be used before ICall_Answer to indicate that a call is about to be answered*/
  AUDIOCONTROL_CALLSTATE_ALERTING, /**< Obsolete, replaced with AUDIOCONTROL_CALLSTATE_ANSWERING*/
  AUDIOCONTROL_CALLSTATE_SETUP,    /**< Should be used before initiating an outgoing call*/
  AUDIOCONTROL_CALLSTATE_ONGOING,  /**< Should be used when a call is active*/
  AUDIOCONTROL_CALLSTATE_HOLDING,  /**< Should be used when all calls are on hold*/

  AUDIOCONTROL_CALLSTATE_LAST
} TAudioControl_CallState;

typedef enum
{
  AUDIOCONTROL_FADE_DIRECTION_NONE,
  AUDIOCONTROL_FADE_DIRECTION_UP,
  AUDIOCONTROL_FADE_DIRECTION_DOWN,

  AUDIOCONTROL_FADE_DIRECTION_LAST
} TAudioControl_FadeDirection;

typedef enum
{
  AUDIOCONTROL_FADE_REASON_PLAY,
  AUDIOCONTROL_FADE_REASON_STOP,
  AUDIOCONTROL_FADE_REASON_SUSPEND,

  AUDIOCONTROL_FADE_REASON_LAST
} TAudioControl_FadeReason;

typedef enum
{
  AUDIOCONTROL_KEYSOUND_CLICK,                /**< Keyclick */

  AUDIOCONTROL_KEYSOUND_TONE_KEY_1,           /**< Key 1 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_2,           /**< Key 2 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_3,           /**< Key 3 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_4,           /**< Key 4 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_5,           /**< Key 5 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_6,           /**< Key 6 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_7,           /**< Key 7 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_8,           /**< Key 8 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_9,           /**< Key 9 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_0,           /**< Key 0 */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_ASTERISK,    /**< Key * */
  AUDIOCONTROL_KEYSOUND_TONE_KEY_NUMBERSIGN,  /**< Key # */

  AUDIOCONTROL_KEYSOUND_TONE,                 /**< General key */

  AUDIOCONTROL_KEYSOUND_LAST
} TAudioControl_KeySound;

typedef enum
{
  AUDIOCONTROL_ROUTING_PHONE,     /**< The Audio is routed to the phone */
  AUDIOCONTROL_ROUTING_ACCESSORY  /**< The Audio is routed to an accessory */
} TAudioControl_AudioRouting;

typedef enum
{
  AUDIOCONTROL_SPEAKERMODE_OFF, /**< Speaker mode set to off, normal routing rules apply */
  AUDIOCONTROL_SPEAKERMODE_FORCE_ON, /**< Speaker mode set forcefully by application and will not be turned off if an accessory is attached */
  AUDIOCONTROL_SPEAKERMODE_USER_ON,  /**< Speaker mode has been set by user but will be turned off when an accessory is attached*/
  AUDIOCONTROL_SPEAKERMODE_ON_IF_NO_ACCESSORY /**< Speaker mode will be active if there is no accessory attached */
} TAudioControl_SpeakerMode;

typedef enum
{
  AUDIOCONTROL_COMFORT_TONE_STANDARD_JAPAN,/**< Japanese comfort tone standard*/
  AUDIOCONTROL_COMFORT_TONE_STANDARD_ANSI, /**< ANSI comfort tone standard*/
  AUDIOCONTROL_COMFORT_TONE_STANDARD_CEPT, /**< CEPT comfort tone standard*/

  AUDIOCONTROL_COMFORT_TONE_STANDARD_LAST
} TAudioControl_ComfortToneStandard;

typedef enum
{
  AUDIOCONTROL_AUDIOTYPE_MEDIAPLAYER,
  AUDIOCONTROL_AUDIOTYPE_SOUNDRECORDER,
  AUDIOCONTROL_AUDIOTYPE_VIDEORECORDER,
  AUDIOCONTROL_AUDIOTYPE_VIDEOTELEPHONY,

  AUDIOCONTROL_AUDIOTYPE_VOICECALL_RX,
  AUDIOCONTROL_AUDIOTYPE_VOICECALL_TX,

  AUDIOCONTROL_AUDIOTYPE_JAVA,
  AUDIOCONTROL_AUDIOTYPE_JAVA_SOUNDRECORDER,

  AUDIOCONTROL_AUDIOTYPE_SPEECHTRAINING,
  AUDIOCONTROL_AUDIOTYPE_SPEECHRECOGNITION,
  AUDIOCONTROL_AUDIOTYPE_MAGIC_WORD,

  AUDIOCONTROL_AUDIOTYPE_FM_RADIO,
  AUDIOCONTROL_AUDIOTYPE_FM_RADIO_ALARM,

  AUDIOCONTROL_AUDIOTYPE_PTT_RX,
  AUDIOCONTROL_AUDIOTYPE_PTT_TX,
  AUDIOCONTROL_AUDIOTYPE_PTT_TX_DECODER,
  AUDIOCONTROL_AUDIOTYPE_PTT_BUFFER,

  //Internal enums.
  AUDIOCONTROL_AUDIOTYPE_RINGER,              /**< Used for Ringer_Play and for Video CLI, through AudioChannel_Open */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_ALERT,  /**< Used for Notification_Play with high prio sounds, see ac_notification.c*/
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_IMPORTANT,/**< Used for Notification_Play with medium prio sounds, see ac_notification.c*/
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_GENERAL,  /**< Used for Notification_Play with low prio sounds, see ac_notification.c*/
  AUDIOCONTROL_AUDIOTYPE_AUDIO,               /**< Used for Play */
  AUDIOCONTROL_AUDIOTYPE_KEYTONE,             /**< Used for KeySound_Play and not AUDIOCONTROL_KEYSOUND_CLICK */
  AUDIOCONTROL_AUDIOTYPE_KEYCLICK,            /**< Used for KeySound_Play and AUDIOCONTROL_KEYSOUND_TONE  */
  AUDIOCONTROL_AUDIOTYPE_ALARM,               /**< Used for Alarm_Play */
  AUDIOCONTROL_AUDIOTYPE_TONE,                /**< Used for Tone_Play */
  AUDIOCONTROL_AUDIOTYPE_SPEAKERTEST,         /**< Used for ServiceMenu_SpeakerTest_Play */
  AUDIOCONTROL_AUDIOTYPE_EARPIECETEST,        /**< Used for ServiceMenu_SpeakerTest_Play */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_CAMERA, /**< Used for camera sounds */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_VOICECTRL,   /**< Used for voice control sounds */
  AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_INCALL,  /**< Used for notification that should be played in earpiece during voice call*/

  AUDIOCONTROL_AUDIOTYPE_LAST                 /**< Keep this last*/

} AC_AudioType_t;

typedef AC_AudioType_t TAudioControl_ChannelType;

typedef enum
{
  AUDIO_CHANNEL_SAMPLE_RATE_8_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_16_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_44_1_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_48_KHZ,
  AUDIO_CHANNEL_SAMPLE_RATE_UNSPECIFIED,

  AUDIO_CHANNEL_SAMPLE_RATE_LAST
}TAudioChannelSampleRate;

typedef enum
{
  MULTIMEDIA_AUDIO_OUTPUT_MONO,
  MULTIMEDIA_AUDIO_OUTPUT_STEREO,
  MULTIMEDIA_AUDIO_OUTPUT_UNKNOWN
} TMultimediaAudioOutput;

typedef enum
{
  AUDIOCONTROL_SPEAKERTYPE_EARPIECE, /**< The earpiece speaker */
  AUDIOCONTROL_SPEAKERTYPE_SPEAKER,  /**< The builtin speaker */
  AUDIOCONTROL_SPEAKERTYPE_AUTO      /**< Automatically choose speaker */
} TAudioControl_SpeakerType;

typedef enum
{
  //aligned with parallellTable and sessionTypePriorities in ac_audiochannel.c
  AUDIOCONTROL_SESSIONTYPE_MEDIAPLAYER    /**< An audio session for a media player           */ = 0x00000001,
  AUDIOCONTROL_SESSIONTYPE_CAMERA         /**< An audio session for camera application       */ = 0x00000002,
  AUDIOCONTROL_SESSIONTYPE_FM_RADIO       /**< An audio session for FM radio                 */ = 0x00000004,
  AUDIOCONTROL_SESSIONTYPE_VOICECALL      /**< An audio session for a voicecall              */ = 0x00000008,
  AUDIOCONTROL_SESSIONTYPE_VIDEOTELEPHONY /**< An audio session for video telephony          */ = 0x00000010,
  AUDIOCONTROL_SESSIONTYPE_SOUNDRECORDER  /**< An audio session for sound recorder           */ = 0x00000020,
  AUDIOCONTROL_SESSIONTYPE_VIDEORECORDER  /**< An audio session for video recorder           */ = 0x00000040,
  AUDIOCONTROL_SESSIONTYPE_MESSAGING      /**< An audio session for messaging                */ = 0x00000080,
  AUDIOCONTROL_SESSIONTYPE_JAVA           /**< An audio session for a Java Virtual Machine   */ = 0x00000100,
  AUDIOCONTROL_SESSIONTYPE_PTT            /**< An audio session for PTT                      */ = 0x00000200,
  AUDIOCONTROL_SESSIONTYPE_SLIDESHOW      /**< An audio session for Slide show               */ = 0x00000400,
  AUDIOCONTROL_SESSIONTYPE_VOICETRAINING  /**< An audio session for Voice training           */ = 0x00000800,
  AUDIOCONTROL_SESSIONTYPE_VOICECONTROL   /**< An audio session for Voice control            */ = 0x00001000,
  AUDIOCONTROL_SESSIONTYPE_ASR_RECOGNITION_CONTINUOUS /**< An audio session for Voice control */= 0x00002000,

  //Internal, not for external use
  AUDIOCONTROL_SESSIONTYPE_SYSTEM_SOUND   /**< An audio session for system sounds            */ = 0x01000000,
  AUDIOCONTROL_SESSIONTYPE_KEYSOUNDS      /**< An audio session for Key clicks and Key tones */ = 0x02000000,
  AUDIOCONTROL_SESSIONTYPE_LAST           /**< For internal audio control use only           */ = 0x04000000,
  AUDIOCONTROL_SESSIONTYPE_NONE           /**< */ = 0x00000000,
  AUDIOCONTROL_SESSIONTYPE_ALL            /**< */ = 0xFFFFFFFF
} TAudioControl_SessionType;

typedef enum
{
  AUDIOCONTROL_AUDIOFORMAT_WAV,               /**< The audio is a wav file*/
  AUDIOCONTROL_AUDIOFORMAT_AMR,               /**< The audio is a amr file*/
  AUDIOCONTROL_AUDIOFORMAT_TONE,              /**< The audio is a tone*/
  AUDIOCONTROL_AUDIOFORMAT_MIDI,              /**< The audio is a MIDI file*/
  AUDIOCONTROL_AUDIOFORMAT_SMAF,              /**< The audio is a SMAF file*/
  AUDIOCONTROL_AUDIOFORMAT_PMR,               /**< The audio is a Nokia pmr file file*/
  AUDIOCONTROL_AUDIOFORMAT_MFI,               /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_SPEECHRECOGNITION, /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_MP3,               /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_AAC,               /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_AAC_PLUS,          /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_FM_RADIO,          /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_VOICECALL,         /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_VIDEOCALL,         /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_INPUT,             /**< Todo */
  AUDIOCONTROL_AUDIOFORMAT_OTHER              /**< Todo */
} TAudioControl_AudioFormat;

typedef enum
{
  AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYCHANGED           = 0x0001, /**< Event when the active accessory is changed, the active accessory is the accessory that currently has audio routed to */
  AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYMUTE              = 0x0002, /**< Event when the accessory is to bemuted */
  AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYCALLVOLUMECHANGED = 0x0004, /**< Event when the the call volume is changed */
  AUDIOCONTROL_ACCESSORY_EVENT_ONREQUIRECCO                 = 0x0008, /**< Obsolete */
  AUDIOCONTROL_ACCESSORY_EVENT_ONVOLUMECHANGED              = 0x0010, /**< Event sent when volume changes*/
  AUDIOCONTROL_ACCESSORY_EVENT_ONSESSIONBEGIN               = 0x0020, /**< Event when a session is started
                                                                           ICBAudioControl::OnSessionBegin */
  AUDIOCONTROL_ACCESSORY_EVENT_ONSPEAKERMODECHANGED         = 0x0040, /**< Event when the speakermode changes. */
  AUDIOCONTROL_ACCESSORY_EVENT_ONSESSIONEND                 = 0x0080, /**< Event when a session is ended
                                                                           ICBAudioControl::OnSessionEnd */
  AUDIOCONTROL_ACCESSORY_EVENT_ONMICROPHONEMUTECHANGED      = 0x0100, /**< Event when the microphone is muted. */
  AUDIOCONTROL_ACCESSORY_EVENT_ONFMTXCHANGED                = 0x0200, /**< Event when fm transmitter is disabled/enabled */
  AUDIOCONTROL_ACCESSORY_EVENT_ALL_EVENTS                   = 0xFFFF  /**< All events */
} TAudioControl_AccessoryEvents;

typedef enum
{
  AUDIOCONTROL_EVENT_NONE                         = 0x0000,
  AUDIOCONTROL_EVENT_ONSPEAKERMODECHANGED         = 0x0040,   /**< Event when the speaker mode has changed. */
  AUDIOCONTROL_EVENT_ONMICROPHONEMUTECHANGED      = 0x0100,   /**< Event when the microphone is muted. */
  AUDIOCONTROL_EVENT_ONFMTXCHANGED                = 0x0200    /**< Event when fm transmitter is disabled/enabled */
} TAudioControl_Events;

typedef enum
{
  AUDIOCONTROL_ACCESSORYID_UNKNOWN    = 0, /**< No audio capabilities */

  //Resitive identified:
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS1          = 1,
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS2          = 2,
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS3          = 3,
  AUDIOCONTROL_ACCESSORYID_PHF_CLASS4          = 4,
  AUDIOCONTROL_ACCESSORYID_LINE_IN             = 5,
  AUDIOCONTROL_ACCESSORYID_LINE_OUT            = 6,
  AUDIOCONTROL_ACCESSORYID_BT_HEADSET          = 7,
  AUDIOCONTROL_ACCESSORYID_BT_HANDSFREE        = 8,
  AUDIOCONTROL_ACCESSORYID_LINE_OUT_ADJUSTABLE = 9,

  //3.5 mm jack
  AUDIOCONTROL_ACCESSORYID_PHF_35MM_STEREO_JACK,
  AUDIOCONTROL_ACCESSORYID_HP_35MM_STEREO_JACK,
  AUDIOCONTROL_ACCESSORYID_LO_35MM_STEREO_JACK,
  AUDIOCONTROL_ACCESSORYID_LI_35MM_STEREO_JACK, 

  //1000-1999 PHF - Portable Hands Frees

  AUDIOCONTROL_ACCESSORYID_PHF_HPM_80 = 1001, /**< Accessory id for Remo (Fm radio PHF with remotecontrol and FM radio for Sakura) */
  AUDIOCONTROL_ACCESSORYID_PHF_HPM_82 = 1002, /**< Accessory id for Barret (PHF with remote control)*/

  //2000-2999 VHF - Vehicle handsfrees
  AUDIOCONTROL_ACCESSORYID_VHF_HCA_60 = 2001, /**< Advanced Vehicle handsfree ("Pooh", "HCA-60") Speech and music in mono speaker */
  AUDIOCONTROL_ACCESSORYID_VHF_HCE_60 = 2002, /**< Advanced Vehicle handsfree ("Pooh", "HCA-60") Speech and music in car stereo speakers*/
  
  AUDIOCONTROL_ACCESSORYID_PEIKER = 2500, /**< BMW car kit with no internal EC nor NC */
  AUDIOCONTROL_ACCESSORYID_PEIKER_EC_NR = 2501, /**< BMW car kit with internal EC and NC */

 //3000-3999 BVHF - Budget Vehicle Hands Free (without accessory mic)
  AUDIOCONTROL_ACCESSORYID_BVHF_HCQ_60       = 3001, /**< HCQ-60, "Tiger" */

  //4000-4999 BT - Bluetooth Headset, or Handsfree
  AUDIOCONTROL_ACCESSORYID_BT_HBH_10   =4001,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_15   =4002,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_20   =4003,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_200  =4004,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_30   =4005,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_300  =4006,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_35   =4007,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_60   =4008,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_600  =4009,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_605  =4010,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_65   =4011,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_660  =4012,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_670  =4013,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_610  =4014,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_620  =4015,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_662  =4016,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_602  =4017,
  AUDIOCONTROL_ACCESSORYID_BT_HBM_30   =4018,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_608  =4021,
  AUDIOCONTROL_ACCESSORYID_BT_HBH_PV705=4022,
  AUDIOCONTROL_ACCESSORYID_BT_MOTO_T305 =4600,  /**< Accessory id for Motorola T305, see DMS00384781. */
  AUDIOCONTROL_ACCESSORYID_BT_DSP      =4999,  /**< Accessory id for BT headsets with internal DSP. */

  //5000-5999 BTC - Bluetooth Handsfree for installation in car.
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_30  =5001,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_300 =5002,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_400 =5003,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_700 =5004,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_610 =5005,
  AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_100 =5006,

  //6000-6999 BTL - Bluetooth Leisure (BT headset supporting the Advanced Audio Distribution Profile)
  //7000-7999 BTBTL - A Bluetooth audio device supporting the Headset or the Handsfree profile and the Advanced Audio Distributionprofile.
  AUDIOCONTROL_ACCESSORYID_BTBTL_HBH_DS970=7001, //A.k.a "Hippix"

  //8000-8999 BTBTLC - A Bluetooth audio device supporting the Headset or the Handsfree profile and the Advanced Audio Distributionprofile for installation in car.
  //9000-9999 DSS - Desk Speaker Stand
  //10000-10999 BDSS - Budget Desk Speaker Stand

  //11000-11999 LO - Line out accesory
  AUDIOCONTROL_ACCESSORYID_MMR_60 = 11001, //Wadner

  //12000-12999 LI - Line in accesory

  //Last accessory
  AUDIOCONTROL_ACCESSORYID_LAST /**< Last accessory id, only for internal Audio Control use*/
} TAudioControl_AccessoryId;

typedef enum
{
  // Ordinary accessories
  AUDIOCONTROL_ACCESSORYCLASS_NONE    = 0,        /**< No audio capabilities */
  AUDIOCONTROL_ACCESSORYCLASS_PHF     = 1,        /**< PHF - Portable Hands Free */
  AUDIOCONTROL_ACCESSORYCLASS_VHF     = 2,        /**< VHF - Vehicle Hands Free */
  AUDIOCONTROL_ACCESSORYCLASS_BVHF    = 3,        /**< BVHF - Budget Vehicle Hands Free (using phone mic) */
  AUDIOCONTROL_ACCESSORYCLASS_BT      = 4,        /**< BT - Bluetooth Headset or Handsfree */
  AUDIOCONTROL_ACCESSORYCLASS_BTC     = 5,        /**< BT Car HF - Bluetooth Car Handsfree */
  AUDIOCONTROL_ACCESSORYCLASS_BTL     = 6,        /**< Bluetooth leisure headset supporting A2DP profile (like streaming mp3, currently not supported) */
  AUDIOCONTROL_ACCESSORYCLASS_DSS     = 9,        /**< Desk speaker Stand */
  AUDIOCONTROL_ACCESSORYCLASS_BDSS    = 10,       /**< Budget Desk speaker Stand (using phone mic) */
  AUDIOCONTROL_ACCESSORYCLASS_LOA     = 11,       /**< Line out signal that uses phone volume and settings*/
  AUDIOCONTROL_ACCESSORYCLASS_LI      = 12,       /**< Line in */
  AUDIOCONTROL_ACCESSORYCLASS_LO      = 13,       /**< Line out - flat signal */
  AUDIOCONTROL_ACCESSORYCLASS_HEADPHONE,

  // Virtual accessories (for internal Audio Control use only)
  AUDIOCONTROL_ACCESSORY_VIRTUAL_SPEAKER_CLOSED,  /**< Virtual speaker closed accessory (e.g. clam closed, jack closed, etc), only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_EARPIECE_CLOSED, /**< Virtual earpiece closed accessory (e.g. clam closed, jack closed, etc), only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_SPEAKER,         /**< Virtual speaker accessory, only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_EARPIECE,        /**< Virtual earpiece accessory, only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_SILENT,          /**< Virtual silent accessory, only for internal Audio Control use */
  AUDIOCONTROL_ACCESSORY_VIRTUAL_FMTX,            /**< FM Transmitter */

  // Last enum
  AUDIOCONTROL_ACCESSORYCLASS_LAST              /**< Last accessory, only for internal Audio Control use */
} TAudioControl_AccessoryClass;

typedef enum
{
} TAudioEffectFrequencyBandId;

typedef TAudioEffectFrequencyBandId TAudioControl_EqualizerBand;

typedef enum
{
} TAudioEffectLevel;

typedef TAudioEffectLevel TAudioControl_EqualizerGain;

#line 5 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IAudioControlManager.h"

//UUID CID_CAudioControlManager = {0xE2, 0, 0x10, 0x71, 0x81, 0xD3, 0x43, 0xC3, 0xAB, 0xEA, 0xD4, 0xF4, 0xEB, 0x67, 0xC8, 0x93};
//UUID IID_IAudioControlManager = {0x78, 0xE, 0x15, 0xD9, 0x40, 0xF5, 0x4F, 0x99, 0xAF, 0x93, 0x38, 0x3B, 0x38, 0x7F, 0xA7, 0xED};


class IAudioControl: public IUnknown
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int Accessory_Update(int accessoryHandle, TAudioControl_AccessoryClass accessoryClass, TAudioControl_AccessoryId accessoryId); //0x20
  virtual int Accessory_CallVolume_Set2(int accessoryHandle, char callVolume); //0x24
  virtual int Accessory_SubscribeToEvents(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_AccessoryEvents events, int* pSubscriptionHandle); //0x28
  virtual int Subscribe(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Events events, int* pSubscriptionHandle); //0x2C
  virtual int Accessory_GetCurrent(TAudioControl_AccessoryClass* pAccessoryClass, TAudioControl_AccessoryId* pAccessoryId, int* pAccessoryHandle); //0x30
  virtual int Accessory_UnsubscribeToEvents(int subscriptionHandle); //0x34
  virtual int Unsubscribe(int subscriptionHandle); //0x38
  virtual int Ringer_Play(IUnknown* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t* pFilePath, bool, bool followSilentMode, bool unk1, bool unk2, bool volumeOverride, char overrideVolume, int* pRingerHandle); //0x3C
  virtual int Ringer_Play2(IUnknown* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t* pFilePath, wchar_t* pIlluminationFileName, bool preview, bool followSilentMode, bool volumeOverride, char overrideVolume, int* pRingerHandle); //0x40
  virtual int Ringer_Stop(int ringerHandle, bool fadeDownBeforeStop); //0x44
  virtual int Ringer_Pause(int ringerHandle); //0x48
  virtual int Ringer_Resume(int ringerHandle); //0x4C
  virtual int Notification_Play(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Notification notification, bool preview, int* pNotificationHandle); //0x50
  virtual int Notification_PlayFile(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Notification notification, wchar_t* pFilePath, bool preview, int* pNotificationHandle); //0x54
  virtual int Notification_PlayFile2(IUnknown* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Notification notification, wchar_t* pFilePath, bool preview, int* pNotificationHandle); //0x58
  virtual int Notification_PlayFile3(IUnknown* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Notification notification, wchar_t* pFilePath, bool preview, int* unk, int* pNotificationHandle); //0x5C
  virtual int Notification_Stop(int notificationHandle); //0x60
  virtual int Alarm_Play(IUnknown* pICBAudioControl, u16 msgBase, int clientData, wchar_t* pFilePath, bool preview, bool followSilentMode, int* pAlarmHandle); //0x64 // 15176D72
  virtual int Alarm_Stop(int alarmHandle); //0x68
  virtual int Play2(IUnknown* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t* pFilePath, bool repeat, bool followSilentMode, int* pPlayHandle); //0x6C
  virtual int Stop(int playHandle); //0x70
  virtual int unk_0x74(); //0x74
  virtual int unk_0x78(); //0x78
  virtual int Tone_Play2(IUnknown* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Tone tone, bool followSilentMode, TAudioControl_ToneRedirection toneRedirection, int time_duration, int* pToneHandle); //0x7C
  virtual int Tone_Stop(int toneHandle); //0x80
  virtual int KeySound_Extended_Play(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_KeySound keySound, int time_duration, int* pToneHandle); //0x84
  virtual int KeySound_Extended_Stop(int toneHandle); //0x88
  virtual int ServiceMenu_SpeakerTest_Play(IUnknown* pICBAudioControl, u16 msgBase, int clientData, wchar_t* pFilePath, TAudioControl_SpeakerType speakerType, int* pChannelHandle); //0x8C
  virtual int ServiceMenu_SpeakerTest_Stop(int channelHandle); //0x90
  virtual int IsAudioPlaying(bool* pAudioPlaying, TAudioControl_VolumeType* pVolumeType); //0x94
  virtual int IsVibratorRunning(bool* pVibratorRunning); //0x98
  virtual int AudioChannel_Open2(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_ChannelType channelType, TAudioChannelSampleRate sampleRate, TMultimediaAudioOutput audioOutput, bool followSilentMode, int timeToWait, int sessionHandle, TAudioControl_AudioFormat audioFormat, int* pChannelHandle); //0x9C
  virtual int unk_0xA0(); //0xA0
  virtual int AudioChannel_Close(int channelHandle); //0xA4
  virtual int unk_0xA8(); //0xA8
  virtual int unk_0xAC(); //0xAC
  virtual int AudioSession_Begin2(IUnknown* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_SessionType sessionType, int* pSessionHandle); //0xB0
  virtual int AudioSession_End(int sessionHandle); //0xB4
  virtual int unk_0xB8(); //0xB8
  virtual int Volume_Set(TAudioControl_VolumeType volumeType, char pVolume); //0xBC
  virtual int Volume_Get(TAudioControl_VolumeType volumeType, char* pVolume); //0xC0
  virtual int ChannelVolume_Fade(int channelHandle, TAudioControl_FadeDirection fadeDirection, TAudioControl_FadeReason fadeReason); //0xC4
  virtual int ChannelVolume_Set2(int channelHandle, char relVolume); //0xC8
  virtual int ChannelVolume_Set(int channelHandle, char volume); //0xCC
  virtual int ChannelVolume_Get(int channelHandle, char* pVolume);
  virtual int IncreaseVolume(TAudioControl_VolumeType volumeType, char* pNewVolume);
  virtual int DecreaseVolume(TAudioControl_VolumeType volumeType, char* pNewVolume);
  virtual int unk_0xDC();
  virtual int IncreasingRing_Set(bool increasingRingEnabled); //0xE0
  virtual int IncreasingRing_Get(bool* pIncreasingRingEnabled); //0xE4
  virtual int MicrophoneMute_Set(bool muteOn); //0xE8
  virtual int MicrophoneMute_Get(bool* pMuteOn); //0xEC
  virtual int unk_0xF0();
  virtual int EqualizerGain_Set(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, TAudioControl_EqualizerGain equalizerGain);
  virtual int EqualizerGain_Get(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, TAudioControl_EqualizerGain* pEqualizerGain);
  virtual int unk_0xFC();
  virtual int unk_0x100();
  virtual int unk_0x104();
  virtual int unk_0x108();
  virtual int unk_0x10C();
  virtual int unk_0x110();
  virtual int unk_0x114();
  virtual int unk_0x118();
  virtual int unk_0x11C();
  virtual int unk_0x120();
  virtual int unk_0x124();
  virtual int unk_0x128();
  virtual int unk_0x12C();
  virtual int unk_0x130();
  virtual int unk_0x134();
  virtual int unk_0x138();
  virtual int unk_0x13C();
  virtual int unk_0x140();
  virtual int unk_0x144();
  virtual int unk_0x148();
  virtual int unk_0x14C();
  virtual int unk_0x150();
  virtual int EqualizerCenterFreq_Get(int sessionHandle, TAudioControl_EqualizerBand  equalizerBand, int* pEqualizerCenterFreq); //0x154
  virtual int DebugMenu_GetString(TAudioControl_DebugMenuString* pBuffer); //0x158
  virtual int AudioRouting_Get(TAudioControl_AudioRouting* pAudioRouting); //0x15C
  virtual int SpeakerPhone_Set(int sessionHandle, bool speakerPhoneEnabled); //0x160
  virtual int SpeakerPhone_Set2(int sessionHandle, TAudioControl_SpeakerMode speakerMode); //0x164
  virtual int SpeakerPhone_Get(int sessionHandle, bool* pSpeakerPhoneEnabled); //0x168
  virtual int ComfortToneStandard_Set(TAudioControl_ComfortToneStandard comfortToneStandard); //0x16C
  virtual int SilentMode_Set(bool silentModeEnabled); //0x170
  virtual int SilentMode_Get(bool* silentModeEnabled); //0x174
  virtual int TTYMode_Set(TAudioControl_TTYMode TTYMode); //0x178
  virtual int TTYMode_Get(TAudioControl_TTYMode* pTTYMode); //0x17C
  virtual int HACMode_Set(TAudioControl_HACMode HACMode); //0x180
  virtual int HACMode_Get(TAudioControl_HACMode* pHACMode); //0x184
  virtual int VibratorState_Set(TAudioControl_VibratorState vibratorState); //0x188
  virtual int VibratorState_Get(TAudioControl_VibratorState* pVibratorState); //0x18C
  virtual int Vibrator_Start(int period, int dutyCycle, int duration); //0x190
  virtual int Vibrator_Stop(void); //0x194
  virtual int Callstate_Set(TAudioControl_CallType callType, TAudioControl_CallState callState); //0x198
  virtual int unk_0x19C(); //0x19C
  virtual int Camera_FollowSilentMode_Set(bool followSilentMode); //0x1A0
  virtual int Camera_FollowSilentMode_Get(bool* pFollowSilentMode); //0x1A4
  virtual int AudioFocus_Request(int sessionHandle); //0x1A8
  virtual int LightPlayer_Enable(int sessionHandle, bool enable); //0x1AC
  virtual int AudioChannel_Mute(int channelHandle, bool mute); //0x1B0
  virtual int AudioChannel_ConnectToDevice(int channelHandle); //0x1B4
  virtual int AudioChannel_Disconnect(int channelHandle); //0x1B8
  virtual int AudioVisualizer_Enable(int channelHandle, bool enable); //0x1BC
};

class IAudioControlManager: public IUnknown
{
public:
  virtual int CreateAudioControl(IAudioControl** pIAudioControl);
};

#line 19 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IMetaData.h"



#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\IMetaData_types.h"



typedef struct
{
  char cover_type;
  int size;
  int cover_offset;
}COVER_INFO_DESC;

typedef enum
{
  TMetadataTagId_Artist,
  TMetadataTagId_Title,
  TMetadataTagId_Album,
  TMetadataTagId_Year,
  TMetadataTagId_Genre,
  TMetadataTagId_x6,
  TMetadataTagId_x7,
} TMetadata_TagId;

#line 5 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IMetaData.h"

//UUID CID_CMetaData = {0xB, 0xCD, 0x95, 0xF, 0x9F, 0xB6, 0x4E, 0x7A, 0xA7, 0xCD, 0xCA, 0x1D, 0x87, 0xBA, 0x9A, 0x27};
//UUID IID_IMetaData = {0xB1, 0xEB, 0x4F, 0x97, 0xB0, 0xDD, 0x42, 9, 0xB6, 0x96, 0xCE, 0x11, 0x2D, 0x5E, 0xD8, 0xE8};

class IMetaData: public IUnknown
{
public:
  virtual int SetFile(wchar_t* path, wchar_t* name);
  virtual int unk_0x14(void* unk1, void* unk2);
  virtual int GetTag(TMetadata_TagId tagID, wchar_t* tag);
  virtual int GetTrackNum(int unk, int* track_num);
  virtual int GetCoverInfo(COVER_INFO_DESC* cover_info);
  virtual int unk_0x24();
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int IsHaveCover(wchar_t* path, wchar_t* name);
};

#line 20 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IRegistryManager.h"



//UUID CID_CRegistryManager = {0x84, 0xA2, 0x98, 0x5A, 0x91, 0x3E, 0x4B, 0x7E, 0xBE, 0xB3, 0x7E, 0xFC, 0xFC, 0xF0, 0xB0, 0xEB};
//UUID IID_IRegistryManager = {0x42, 0x71, 0xC7, 0x45, 0xF, 0x21, 0x46, 0xB7, 0x9A, 0x29, 0x99, 0xF4, 0x21, 0x6A, 0x26, 0x2E};

typedef enum
{
  REGISTRY_UED_UNSPECIFIED,
  REGISTRY_UED_TRANSACTION_INVALID,
  REGISTRY_UED_TRANSACTION_OVERFLOW,
  REGISTRY_UED_KEY_INVALID,
  REGISTRY_UED_KEY_STATE_INVALID,
  REGISTRY_UED_KEY_DEPTH,
  REGISTRY_UED_KEY_NAME_LENGTH,
  REGISTRY_UED_KEY_NOT_FOUND,
  REGISTRY_UED_VALUE_NAME_INVALID,
  REGISTRY_UED_VALUE_NAME_LENGTH,
  REGISTRY_UED_VALUE_PATH_INVALID,
  REGISTRY_UED_VALUE_NOT_FOUND,
  REGISTRY_UED_READ_ONLY,
  REGISTRY_UED_ENUM_DONE,
  REGISTRY_UED_UNEXPECTED_TYPE,
  REGISTRY_UED_BAD_SIZE,
  REGISTRY_UED_UNEXPECTED_SIZE,
  REGISTRY_UED_IO_ERROR,
  REGISTRY_UED_UNSUPPORTED,
  REGISTRY_UED_VALIDATION_FAILED,
  REGISTRY_UED_VALIDATION_ERROR,
  REGISTRY_UED_VALIDATION_NAME_INVALID,
  REGISTRY_UED_VALIDATION_UNSPECIFIED,
  REGISTRY_UED_VALIDATION_VALIDATOR_NOT_FOUND,
  REGISTRY_UED_VALIDATION_INVALID_CID
}Registry_Ued_ErrorCode_t;

typedef enum
{
  Reg_RegistryTransactionClass_AutoCommit,
  Reg_RegistryTransactionClass_Full,
  Reg_RegistryTransactionClass_ReadOnly
}Reg_RegistryTransactionClass_t;

typedef enum
{
  Reg_RegValueType_Unspecified, ///< No data type specified.
  Reg_RegValueType_UInt,    ///< Unsigned integer value.
  Reg_RegValueType_String,  ///< 'char' (null terminated) string value.
  Reg_RegValueType_WString, ///< 'wchar' (null terminated) string value.
  Reg_RegValueType_Binary   ///< Binary/unformatted value, sized in bytes.
}Reg_RegValueType_t;

typedef struct
{
  Reg_RegValueType_t valueType; ///< The (data) type of the Value.
  int dataSize; ///< The size (in bytes) of the data (strings: incl. nullt.).
}RegKey_ValueInfo_t;

class IRegistryKey: public IUnknown
{
public:
  virtual int EnumSubkeys(char* pKeyName);
  virtual int EnumValues(char* pValueName);
  virtual int CreateSubkey(char* keyName, bool open);
  virtual int OpenSubkey(char* subkeyName);
  virtual int DeleteSubkey(char* keyName);
  virtual int RenameSubkey(char* keyName, char* newKeyName);
  virtual int GetValue(char* valueName, Reg_RegValueType_t valueType, int dataSize, void* pData, RegKey_ValueInfo_t* pValueInfo);
  virtual int SetValue(char* valueName, Reg_RegValueType_t valueType, int dataSize, void* pData);
  virtual int DeleteValue(char* valueName);
  virtual int RenameValue(char* valueName, char* newValueName);
  virtual int RestateValue(char* valueName);
  virtual int GetValueInfo(char* valueName, RegKey_ValueInfo_t* pValueInfo);
  virtual int GetKeyPath(int bufferSize, char* pKeyPath);
};

class IRegistry: public IUnknown
{
public:
  virtual int BeginTransaction(Reg_RegistryTransactionClass_t transactionClass);
  virtual int EndTransaction(bool commitChanges);
  virtual int FlushTransaction(bool commitChanges);
  virtual int OpenKey(char* keyPath, IRegistryKey** ppIRegistryKey);
  virtual int CreateKey(char* keyPath, IRegistryKey** ppIRegistryKey);
  virtual int EnableValidatingKeys(void);
  virtual int DisableValidatingKeys(void);
};

class IRegistryAccess: public IUnknown
{
public:
  virtual int ReadUnsignedInt(char* absoluteValuePath, int* pUnsigned);
  virtual int ReadString(char* absoluteValuePath, int maxLength, char* stringBuffer, int* pActualLength);
  virtual int ReadWString(char* absoluteValuePath, int maxLength, wchar_t* stringBuffer, int* pActualLength);
  virtual int ReadBinary(char* absoluteValuePath, int dataSize, void* pData, int* pActualSize);
  virtual int WriteUnsignedInt(char* absoluteValuePath, int value);
  virtual int WriteString(char* absoluteValuePath, char* strVal);
  virtual int WriteWString(char* absoluteValuePath, wchar_t* strVal);
  virtual int WriteBinary(char* absoluteValuePath, void* pData, int dataSize);
  virtual int EnableValidation(void);
  virtual int DisableValidation(void);
};

class IRegistryManager: public IUnknown
{
public:
  virtual int CreateRegistry(IRegistry** pIRegistry);
  virtual int CreateRegistryAccess(IRegistryAccess** pIRegistryAccess);
  virtual int CreateRegistryNotificationsProvider(IUnknown** pIRegistryNotificationsProvider);
};

#line 21 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IMMEManager.h"



#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\IMMETypes.h"



#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\Time_types.h"





/**
  * A time in hours.
  */
typedef FUint32 THour;

/**
  * A time in minutes.
  */
typedef FUint32 TMinute;

/**
  * A time in seconds.
  */
typedef FUint32 TSecond;

/**
  * A time in milliseconds. 
  */
typedef FUint32 TMillisecond;

/**
  * A time in microseconds.
  */
typedef FUint32 TMicrosecond;

/**
  * A time in nanoseconds.
  */
typedef FUint32 TNanosecond;

/**
  * A time in Universal Time Coordinated (UTC).
  * This value is the number of seconds elapsed since January 1, 1970, 00:00:00 GMT.
  */
typedef FUint32 TUtcTime;


/**
  * Enumerates the months.
  *
  * @param MONTH_JANUARY    Represent month January.
  * @param MONTH_FEBRUARY   Represent month February.
  * @param MONTH_MARCH      Represent month March.
  * @param MONTH_MARS       Represent month March, obsolete.
  * @param MONTH_APRIL      Represent month April.
  * @param MONTH_MAY        Represent month May.
  * @param MONTH_JUNE       Represent month June.
  * @param MONTH_JULY       Represent month July.
  * @param MONTH_AUGUST     Represent month August.
  * @param MONTH_SEPTEMBER  Represent month September.
  * @param MONTH_OCTOBER    Represent month October.
  * @param MONTH_NOVEMBER   Represent month November.
  * @param MONTH_DECEMBER   Represent month December.
  */
typedef enum
{
  MONTH_JANUARY = 1,
  MONTH_FEBRUARY,
  MONTH_MARCH,
  MONTH_MARS = MONTH_MARCH,
  MONTH_APRIL,
  MONTH_MAY,
  MONTH_JUNE,
  MONTH_JULY,
  MONTH_AUGUST,
  MONTH_SEPTEMBER,
  MONTH_OCTOBER,
  MONTH_NOVEMBER,
  MONTH_DECEMBER
} TMonth;

/**
  * Enumerates the weekdays Monday, Tuesday, Wednesday, Thursday, Friday
  * Saturday and Sunday.
  *
  * @param WEEKDAY_MONDAY     Represent weekday Monday.
  * @param WEEKDAY_TUESDAY    Represent weekday Tuesday.
  * @param WEEKDAY_WEDNESDAY  Represent weekday Wednesday.
  * @param WEEKDAY_THURSDAY   Represent weekday Thursday.
  * @param WEEKDAY_FRIDAY     Represent weekday Friday.
  * @param WEEKDAY_SATURDAY   Represent weekday Saturday.
  * @param WEEKDAY_SUNDAY     Represent weekday Sunday.
  */
typedef enum
{
  WEEKDAY_MONDAY = 0,
  WEEKDAY_TUESDAY,
  WEEKDAY_WEDNESDAY,
  WEEKDAY_THURSDAY,
  WEEKDAY_FRIDAY,
  WEEKDAY_SATURDAY,
  WEEKDAY_SUNDAY
} TWeekday;

/**
  * This type is used to store a date, which consists of year, month and day, e.g. 2003 February 10.
  * 
  * @param  Year      A year, full year e.g. 2003.
  * @param  Month     A month from the enum TMonth.
  * @param  Day       A day, between 1 and 31.
  * 
  */
typedef struct
{
  FUint16 Year;   
  TMonth  Month;  
  FUint8  Day;    
} TDate;

/**
  * The day time, expressed in hours, minutes and seconds.
  * 
  * @param  Hours   An hour, between 0 and 23.
  * @param  Minutes A minute, between 0 and 59.
  * @param  Seconds A second, between 0 and 59.
  * @param  Milliseconds A millisecond, between 0 and 999.
  */
typedef struct
{
  FUint8  Hours;  
  FUint8  Minutes;
  FUint8  Seconds;
  FUint16 Milliseconds;
} TDayTime;


/**
  * This type represents both the time and the date.
  *
  * @param Date     The date expressed in year, month and day.
  * @param DayTime  The time expressed in hours, minutes, seconds and milliseconds.
  */
typedef struct
{
  TDate     Date;
  TDayTime  DayTime;
} TDateAndTime;

#line 5 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\IMMETypes.h"

/**
 * The maximum length of a file path or a streaming URL
 */
const int MME_URL_TYPE_MAX_LENGTH = 512;

const int MME_STREAMING_SESSION_NAME_MAX_LENGTH = 512;

/**
 * The firewall traversal interval used when streaming is connected via WLAN
 */
const int MME_STREAMING_WLAN_FIREWALL_TRAVERSAL_INTERVAL = 60000;

/**
 * The set of error codes that can be sent
 * from the mutlimedia engine.
 */
typedef enum
{
  //General
  MME_UED_GENERAL_ERROR,                      ///< Returned when none of the other error codes are applicable.
  MME_UED_INTERRUPTED,                        ///< Returned when the session or the player was interrupted by another session or player (with the same or
                                              ///< higher priority) or a call.

  MME_UED_NOT_SUPPORTED,                      ///< Returned when some functionality not is supported with the current platform
                                              ///< configuration or a file format not supported with current phone project configuration.
  MME_UED_OPA_ERROR,                          ///< Returned when the platform is returning an error of unknown reason.
  MME_UED_OUT_OF_MEMORY,                      ///< Returned when some allocation failed due to lack of memory.
  MME_UED_INPUT_PARAM_ERROR,                  ///< Returned when there was some error in the input parameters.
  MME_UED_NOT_ALLOWED_ERROR,                  ///< Returned when an action is not allowed to be performed (due to wrong state etc.).

  //Player specific
  MME_UED_NOT_AUTHORIZED,                     ///< Returned when there are not any available resources, and another ongoing activity has higher priority.
  MME_UED_FILE_NOT_FOUND,                     ///< Returned when the specified file is not found, local or on media server.
  MME_UED_END_OF_FILE,                        ///< Returned when the player stopped since end of file was reached.
  MME_UED_CLIENT_TERMINATION,                 ///< Returned when the player stopped since the client called the stopped method.

  //DRM specific
  MME_UED_DRM_ERROR,                          ///< Returned when the specified file is a DRM file, and DRM is returning an error of unknown reason.
  MME_UED_DRM_PLAYRIGHTS_EXPIRED,             ///< Returned when the specified file is a DRM file, and the credentials not allows playback.
  MME_UED_DRM_AUDIO_ROUTING_FORBIDDEN,        ///< Returned when the specified file is a DRM file, and audio routing to an accessory is forbidden.
  //MME_UED_DRM_NOT_ALLOWED,                  ///< Returned when the specified DRM file is not allowed to be played.

  // Streaming specific
  MME_UED_STREAMING_NETWORK_ERROR,            ///< Returned when connection/registrating to the network failed or network initiated close.
  MME_UED_STREAMING_RADIO_OFF_ERROR,          ///< Returned when trying to connect when in Radio OFF mode a.k.a flight mode.
  MME_UED_STREAMING_SERVER_ERROR,             ///< Returned when connection to the media server failed.
  MME_UED_STREAMING_PROXY_ERROR,              ///< Returned when connection to the given proxy server failed.
  MME_UED_STREAMING_DNS_ERROR,                ///< Returned when failed to resolve a host name to an IP adress.
  MME_UED_STREAMING_ACCOUNT_MISSING,          ///< Returned when the streaming connection account is missing.
  MME_UED_STREAMING_BAD_ACCOUNT,              ///< Returned when the streaming connection account was incorrect and could not be opened.
  MME_UED_STREAMING_CONNECTION_LOST,          ///< Returned when lost network or server connection.
  MME_UED_STREAMING_AUTHENTICATION_CANCELLED, ///< Returned when authentication to the network is needed and it is cancelled.
  MME_UED_STREAMING_AUTHENTICATION_ERROR,     ///< Returned when authentication to the network or streaming server is needed and it has failed due to wrong input.
  MME_UED_PDP_MODIFICATION_FAILURE,           ///< Returned when network connection QoS modification failed.
  MME_UED_STREAMING_CLOSED,                   ///< Returned when the network or streaming connection is closed.
  MME_LAST                                    ///< Place holder. Put new data before this!
}TMMEErrorCode;

/**
 * The set of causes that can be sent
 * from the mutlimedia engine.
 */
typedef enum
{
  TMMECause_Error,                      ///< General unspecified error.
  TMMECause_OPA_Error,                  ///< Unspecified platform error
  TMMECause_Beginning_Of_File_Passed,   ///< Passed beginnig of media file (case of rewind operation).
  TMMECause_End_Of_File,                ///< End of media file reached.
  TMMECause_Client_Termination,         ///< Client terminated the session player.
  TMMECause_DRM_Credentials_Expired,    ///< DRM credentials expired.
  TMMECause_Streaming_Connection_Lost,  ///< Streaming connection lost.
  TMMECause_Streaming_Session_Ended,    ///< This concerns packet video networks only. A pre-paid account has no credit
                                        ///< left or that the current playlist has been exhausted and the client has not
                                        ///< requested an updated playlist.
  TMMECause_VideoInterrupt,             ///< Video interrupted a video -> decoder conflict.
  TMMECause_Last                        ///< Place holder. Put new data before this!
}TMMECause;

/**
 * The set of player states.
 */
typedef enum
{
  TMMEState_Idle,                   ///< Player is idle, eg is in the init phase but not yet fully initiated.
  TMMEState_Stopped,                ///< Player is stopped due to an error or EOF (end of file) and can not be used anymore.
  TMMEState_Initiated,              ///< Player is initiated and ready to be played.
  TMMEState_Playing,                ///< Player is playing.
  TMMEState_Paused,                 ///< Player is paused. Use the resume method to resume the playback.
  TMMEState_FastForwarding,         ///< Player is fast forwarding.
  TMMEState_Rewinding,              ///< Player is rewinding.
  TMMEState_Interrupted,            ///< Player is interrupted by another playback session/player/call.
  TMMEState_SlowMotion,             ///< Player is playing video in slow motion.
  // MME internal states. Will not be exposed to the clients!
  TMMEState_Delayed_Playing,        
  TMMEState_ReInitiating,        
  TMMEState_Last                    ///< Place holder. Put new data before this!
}TMMEState;

/**
 * The set of additional player features (bitwise) supported
 * for different file types. All file types do not
 * support these.
 */
typedef enum
{
  TMMEFeature_Wind = 0x01,            ///< Bit = 0001, Fast forward and rewind.
  TMMEFeature_Capture_Video = 0x02    ///< Bit = 0010, Capture video snapshot.
}TMMEFeature;

/**
 * The set of player creation configurations.
 * Some restrictions will be present though:
 *
 * 1) An audio player can be created for a video file -> play video file as audio only.
 * 2) A video player can not be created for audio only files.If this type is set
 *    for an audio only file the player created will be of type audio only!
 */
typedef enum
{
  TMMECreatePlayer_AudioOnly,       ///< Creating a player for audio only. Low priority.
  TMMECreatePlayer_VideoOnly,       ///< Creating a player for video only (sound disabled). Low priority.
  TMMECreatePlayer_VideoThumbnail,  ///< Creating a player for video only (this does not apply for streaming) and no resource handling, e.g. for playing video thumbnails, 
                                    ///< but may also be used for video playback (without sound) during voice call. 
                                    ///< The client is responsible for the resource handling. SHOULD BE USED WITH CARE. Low priority. 
  TMMECreatePlayer_AsMedia,         ///< Creating a player that follows the media file content - audio, video, audio/video.. Low priority.
  
  TMMECreatePlayer_Last             ///< Place holder. Put new data before this!
}TMMECreatePlayer;

/**
 * The set of values that determines 
 * the MME player priority.
 */
typedef enum
{
  TMMEPlayerPriority_MediaPlayer, 
  TMMEPlayerPriority_VideoTelephony,
  TMMEPlayerPriority_Java,
  TMMEPlayerPriority_FM_Radio,
  TMMEPlayerPriority_FM_Radio_Alarm,
  TMMEPlayerPriority_Ringer,
  TMMEPlayerPriority_SlideShow,
  TMMEPlayerPriority_Unknown = 0xFF ///< Place holder. Put new data before this!
}TMMEPlayerPriority;

/**
 * The set of audio configurations. The values may be used to 
 * create a mask containing all settings.
 *
 * E.g. TMMEAudioConfig_FollowSilentMode | TMMEAudioConfig_Mute_When_Rerouting_To_Speaker
 */
typedef enum
{
  TMMEAudioConfig_Normal                         = 0x0000,  ///< No special setting
  TMMEAudioConfig_FollowSilentMode               = 0x0001,  ///< Silent mode is followed, sound will only be played in discreet accessory.
  TMMEAudioConfig_Mute_When_Rerouting_To_Speaker = 0x0002,  ///< Mutes sound if it ends up in speaker and previously was in accessory (embarassing transition).  
  TMMEAudioConfig_Allow_FMTX                     = 0x0004,  ///< Specifies that the player allows audio to be sent over FM
  TMMEAudioConfig_Unknown = 0xFF  ///< Place holder. Put new data before this!
}TMMEAudioConfig;

/**
 * The set of values type that
 * determines the MME session priority. 
 */
typedef enum
{
  TMMESessionPriority_MediaPlayer, 
  TMMESessionPriority_VideoTelephony, 
  TMMESessionPriority_Java,
  TMMESessionPriority_FM_Radio, 
  TMMESessionPriority_Messaging,
  TMMESessionPriority_VoiceCall,
  TMMESessionPriority_SlideShow
}TMMESessionPriority;

/**
 * The set of player configuration description.
 */
typedef struct
{
  TMMECreatePlayer playerToCreate;    ///< Type of player to create.
  TMMEPlayerPriority playerPriority;  ///< Type of audio channel (different priorities), @see TMMEPlayerPriority.
  TMMEAudioConfig audioConfig;        ///< Audio configuration - follow silent mode/normal..., @see TMMEAudioConfig.
}TMMEPlayerConfig;

/**
 * The set of player types. Returned when a player has been created to
 * describe what sort of player that has been created.
 */
typedef enum
{
  TMMEPlayerType_Audio,                     ///< Audio player for local file.
  TMMEPlayerType_Video_And_Audio,           ///< Video player with both video and audio for local file.
  TMMEPlayerType_VideoOnly,                 ///< Video player with video and no audio for local file.
  TMMEPlayerType_VideoThumbnail,            ///< Video player with video and no audio for local file. Used mainly for video thumbnail playback, 
                                            ///< but can also be use to play a video during a voice call. RESOURCE HANDLING IS DISABLED so 
                                            ///< the client is responsible for the resource handling. SHOULD BE USED WITH CARE.
  TMMEPlayerType_StreamingAudio,            ///< Streaming audio player.
  TMMEPlayerType_StreamingVideo_And_Audio,  ///< Streaming video player with both video and audio.
  TMMEPlayerType_StreamingVideoOnly,        ///< Streaming video player with video and no audio.
  TMMEPlayerType_StreamingUnknown,          ///< Player type unknown. Will only be set in streaming before the player is initiated.
  TMMEPlayerType_Last                       ///< Place holder. Put new data before this!
}TMMEPlayerType;

/**
 * The set of data to describe the multimedia engine time
 * representation.
 */
typedef struct 
{
  THour Hours;		///< Number of hours.
  TMinute Minutes;		///< Number of minutes (0 - 59).
  TSecond Seconds;		///< Number of seconds (0 - 59).
  TMillisecond MilliSeconds;	///< Number of milliseconds (0 - 999).
}TMMETime;

/**
 * The set of content possibilities a media file can have.
 */
typedef enum 
{
  TMMEContentType_VideoAndAudio, ///< File containing both audio and video.
  TMMEContentType_VideoOnly,	 ///< File only containing video.
  TMMEContentType_AudioOnly,	 ///< File only containing audio.
  TMMEContentType_Unknown		 ///< File content type is unknown.
}TMMEContentType;

/**
 * The set of media types possible to determine from a drm protected media file.
 * Returned by interface function IMMESessionContentUtility::GetMediaFromMimeType
 */
typedef enum 
{
  TMMEMediaType_Unknown,  ///< File content type is unknown.
  TMMEMediaType_Audio,    ///< File only containing audio.
  TMMEMediaType_Video     ///< File only containing video.
}TMMEMediaType;

/**
 * The set of audio output possibilities a media file can have.
 * E.g. stereo/mono.
 */
typedef enum 
{
  TMMEAudioOutput_Mono,   ///< Mono audio output.
  TMMEAudioOutput_Stereo, ///< Stereo audio output.
  TMMEAudioOutput_Unknown ///< Unknown output.
}TMMEAudioOutput;

/**
 * The set of data to describe a video image size in pixels.
 */
typedef struct 
{
  int Height; ///< Height in pixels.
  int Width;  ///< Width in pixels.
}TMMEVideoImageSize;

/**
 * The set of data to describe a H263/H264 video encoded file.
 */
typedef struct
{
  char videoProfile;        ///< Video profile of a H263/H264 encoded video file.
  char videoProfileLevel;   ///< Video profile level of a H263/H264 encoded video file.
}TMMEVideoProfile;

/**
 * The set of file format types.
 */
typedef enum
{
  TMMEFileFormatIdType_NONE, // Probably a streaming link
  TMMEFileFormatIdType_3GA,
  TMMEFileFormatIdType_3GP,
  TMMEFileFormatIdType_AAC,
  TMMEFileFormatIdType_AMR,
  TMMEFileFormatIdType_ASF,
  TMMEFileFormatIdType_AWB, // AMR wide band
  TMMEFileFormatIdType_EMY,
  TMMEFileFormatIdType_IMY,
  TMMEFileFormatIdType_M4A,
  TMMEFileFormatIdType_M4B,
  TMMEFileFormatIdType_MIDI,
  TMMEFileFormatIdType_MMF,
  TMMEFileFormatIdType_MP3,
  TMMEFileFormatIdType_MP4,
  TMMEFileFormatIdType_MXMF,
  TMMEFileFormatIdType_RAM,
  TMMEFileFormatIdType_RA,
  TMMEFileFormatIdType_RHZ,
  TMMEFileFormatIdType_RM,
  TMMEFileFormatIdType_RV,
  TMMEFileFormatIdType_SDP,
  TMMEFileFormatIdType_WAV,
  TMMEFileFormatIdType_WMA,
  TMMEFileFormatIdType_WMV,
  TMMEFileFormatIdType_XMF,
  TMMEFileFormatIdType_Last // Put new file types before this.
}TMMEFileFormatIdType;

/**
 * The set of video format (codec) types
 * a file format may contain.
 */
typedef enum
{
  TMMEVideoCodecIdType_NONE,
  TMMEVideoCodecIdType_H263,
  TMMEVideoCodecIdType_H264,
  TMMEVideoCodecIdType_M4V,  //MPEG4
  TMMEVideoCodecIdType_WMV,
  TMMEVideoCodecIdType_REAL,
  TMMEVideoCodecIdType_UNKNOWN, // Put new codec types before this.
  TMMEVideoCodecIdType_Last
}TMMEVideoCodecIdType;

/**
 * The set of audio format (codec) types
 * a file format may contain. 
 *
 * Note: These values are re-mapped and type checks must therefore
 * be performed against audioCodecType. Will NOT work with AudioCodecId!
 */
typedef enum
{
  TMMEAudioCodecIdType_NONE,
  TMMEAudioCodecIdType_AAC,
  TMMEAudioCodecIdType_AMR,
  TMMEAudioCodecIdType_EMELODY,
  TMMEAudioCodecIdType_IMELODY,
  TMMEAudioCodecIdType_MIDI,
  TMMEAudioCodecIdType_MP3,
  TMMEAudioCodecIdType_RAWHERTZ,
  TMMEAudioCodecIdType_PCM,       // WAV
  TMMEAudioCodecIdType_SMAF,
  TMMEAudioCodecIdType_WMA,
  TMMEAudioCodecIdType_AMR_WB,
  TMMEAudioCodecIdType_AMR_WBP,
  TMMEAudioCodecIdType_REAL_SIPRO,
  TMMEAudioCodecIdType_REAL_GECKO,
  TMMEAudioCodecIdType_UNKNOWN, // Put new codec types before this.
  TMMEAudioCodecIdType_Last
}TMMEAudioCodecIdType;

/**
 * The set of data to describe content properties of a media file.
 */
typedef struct
{
  // General
  TMMEContentType contentType;         ///< Type of content, @see TMMEContentType.
  TMMETime mediaLength;                ///< Media file total playback time, @see TMMETime.

  // File format
  char fileFormatId;                 ///< Media file format identifier.
  TMMEFileFormatIdType fileFormatType; ///< File format type description, @see TMMEFileFormatIdType.

  // Audio
  TMMEAudioOutput audioOutput;         ///< Mono/stero audio output, @see TMMEAudioOutput.
  char audioCodecId;                 ///< Audio codec identifier (EMP value, to be used mainly for DRM checks).
  TMMEAudioCodecIdType audioCodecType; ///< Audio codec id type description, @see TMMEAudioCodecIdType.
  int audioSampleRate;             ///< Sample rate of the audio encoding, values from 0 to 4294967295 Hz.
  u16 bpmTempo;                    ///< Beats-per-minute tempo. Only valid for MIDI and iMelody files.

  // Video
  bool videoImageSizePresent;         ///< TRUE if there is available information about VideoImageSize.
  TMMEVideoImageSize videoImageSize;   ///< Video image size, @see TMMEVideoImageSize.
  char videoCodecId;                 ///< Video codec id of an video encoding type.
  TMMEVideoCodecIdType videoCodecType; ///< Video codec id type description, @see TMMEVideoCodecIdType.

  // Streaming
  wchar_t streamingSessionName[MME_STREAMING_SESSION_NAME_MAX_LENGTH+1]; ///< Name of the streaming session.
  int streamingContentId;          ///< Streaming content format identifier.
  bool isLiveStreaming;               ///< Description if the content is live streamig or not.

  // DRM
  bool is_DRM_Protected;			         ///< Description if the content is DRM protected or not.
}TMMEMediaProperties;

typedef struct MME_DATA
{
  char dummy[0x2C];
  TMMEMediaProperties mediaProperties;
}MME_DATA;

/**
 * The set of media formats contained in a media file.
 */
typedef struct
{
  // File format
  TMMEFileFormatIdType fileFormatType; ///< File format type description, @see TMMEFileFormatIdType.

  // Audio
  char audioCodecId;                 ///< Audio codec identifier.
  TMMEAudioCodecIdType audioCodecType; ///< Audio codec id type description, @see TMMEAudioCodecIdType.

  // Video
  char videoCodecId;                 ///< Video codec id of an video encoding type.
  TMMEVideoCodecIdType videoCodecType; ///< Video codec id type description, @see TMMEVideoCodecIdType.
}TMMEMediaFormats;

/**
 * The set of equalizer bands available.
 */
typedef enum
{
  TMMEEqBand_ClearBass1,
  TMMEEqBand_ClearBass2,
  TMMEEqBand_63,
  TMMEEqBand_250,
  TMMEEqBand_400,
  TMMEEqBand_1000,
  TMMEEqBand_2500,
  TMMEEqBand_4000,
  TMMEEqBand_6300,
  TMMEEqBand_16000,
  TMMEEqBand_Last
}TMMEEqBand;

/**
  * The different equalizer presets. Only avaialble for Clear Audio!
  */
typedef enum
{
  TMMEEqPreset_Normal,
  TMMEEqPreset_Heavy,
  TMMEEqPreset_Pops,
  TMMEEqPreset_Jazz,
  TMMEEqPreset_Unique,
  TMMEEqPreset_Soul,
  TMMEEqPreset_EasyListening,
  TMMEEqPreset_BassBoost,
  TMMEEqPreset_TrebleBoost,
  
  // Always have this as the last preset
  TMMEEqPreset_Last
} TMMEEqPreset;

/**
 * The set of display options where to show the video.
 */
typedef enum
{
  TMMEDisplay_Main,    ///< Main display
  TMMEDisplay_Second,  ///< Second display. Used on clam phones.
  TMMEDisplay_Last
}TMMEDisplay;

/**
 * The set of data to describe where to draw video on the display.
 * 
 * Contains:
 *
 * X      (TSigned)   - Start point, x-coordinate of the upper left corner of the rectangle.
 * Y      (TSigned)   - Start point, y-coordinate of the upper left corner of the rectangle.
 * Width  (TUnsigned) - Witdh of the rectangle.
 * Height (TUnsigned) - Height of the rectangle.
 */
typedef RECT TMMEVideoArea;

/**
 * The set of video display orientations,
 * i.e. how the video area will be shown on the display.
 * The video orientation can be rotated and/or mirrored.
 */
typedef enum
{
  TMMEDisplayOrientation_Portrait  = 0x00000000,   ///< Show video in portrait orientation.
  TMMEDisplayOrientation_Landscape = 0x00000001,  ///< Show video rotated 90 degrees clockwise compared
                                                  ///< to portrait orientation.
  TMMEDisplayOrientation_Mirror_X  = 0x00000002,   ///< Show video mirrored around a vertical axis located
                                                  ///< in the center of the display.
  TMMEDisplayOrientation_Mirror_Y  = 0x00000004,   ///< Show video mirrored around a horizontal axis
                                                  ///< located in the center of the display.
  TMMEDisplayOrientation_Last                     ///< Place holder. Put new data before this!
}TMMEDisplayOrientation;

/**
 * This type is used to store display orientation flags. The field is
 * computed by bitwise 'or' different TMMEDisplayOrientation together.
 * All combinations are valid.
 */
typedef int TMMEGuiDisplayOrientationFlagField;

/**
 * The set of streaming connection types.
 */
typedef enum
{
  TMMEStreamingConnectionType_Network,      ///< Network connection.
  TMMEStreamingConnectionType_MediaServer,  ///< Media server connection.
  TMMEStreamingConnectionType_Last          ///< Place holder
}TMMEStreamingConnectionType;

/**
 * The set of IP (internet protocol)
 * address family.
 */
typedef enum
{
  TMMEAddressFamily_Unspecified, ///< Address family is not specified.
  TMMEAddressFamily_IPV4,		 ///< The IPv4 address family.
  TMMEAddressFamily_IPV6,		 ///< The IPv6 address family.
  TMMEAddressFamily_Packet       ///< The packet address family.
} TMMEAddressFamily;

const int MME_AUDIOCONTROL_HANDLE_NOT_USED = 0;

/**
 * This type is used to indicate the fade direction when 
 * using fading sound in an MME player.
 */
typedef enum
{
  TMMEFadeDirection_None,
  TMMEFadeDirection_Up,
  TMMEFadeDirection_Down
}TMMEFadeDirection;

/**
 * This type is used to indicate the fade reason.
 */
typedef enum
{
  TMMEFadeReason_Play,
  TMMEFadeReason_Stop,
  TMMEFadeReason_Suspend
}TMMEFadeReason;

/**
 * This type is used to indicate mute reason received from lower layer (Audio Control).
 */
typedef enum
{
  TMMEMuteReason_Accessory_Detached
}TMMEMuteReason;

/**
 * This type is used to configure the fastforward and rewind operation when a 
 * boundary is reached (end of file or beginning of file).
 * 
 * E.g. if the TMMEWindCondition_BOF_Paused is set the player will 
 * pause, instead of stop, when the beginning of the file is reached. 
 */
typedef enum
{
  TMMEWindCondition_EOF_Stopped = 0x00000000, ///< Player will be stopped when end of file is reached.
  TMMEWindCondition_BOF_Stopped = 0x00000001, ///< Player will be stopped when beginning of file is reached.
  TMMEWindCondition_EOF_Paused  = 0x00000002, ///< Overrides TMMEWindCondition_EOF_Stopped. 
                                              ///< Player will be paused when end of file is reached.
  TMMEWindCondition_BOF_Paused  = 0x00000004, ///< Overrides TMMEWindCondition_BOF_Stopped. 
                                              ///< Player will be paused when beginning of file is reached.
  TMMEWindCondition_Last                      ///< Place holder. Put new data before this!
}TMMEWindCondition;

/**
 * This type is used to store wind condition flags. The field is
 * computed by bitwise 'or' different TMMEWindCondition together.
 */
typedef u16 TMMEWindConditionFlagField;

#line 5 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IMMEManager.h"

//UUID CID_CMMEManager = {0x12, 0xE7, 0x4B, 0x58, 0x29, 0xA0, 0x40, 0xFF, 0x80, 0x55, 0x16, 0xA0, 0x2A, 0xB6, 0xCF, 0xAF};
//UUID IID_IMMEManager = {0x32, 0xA3, 0xED, 9, 7, 0x21, 0x48, 0xE6, 0xA5, 0x3D, 0x91, 0x47, 0x79, 0xF3, 0xE6, 0xAC};
//UUID IID_IMMESessionContentUtility = {0x74, 0xF0, 0xE9, 0x93, 0x27, 0xDB, 0x4E, 0xD9, 0x8E, 0x75, 0x6E, 0xF4, 0xC7, 0x26, 0x5E, 0x3E};
//UUID IID_IMMESessionEqualizer = {0x62, 0xAE, 0xAF, 0xCC, 0x8A, 0x76, 0x4A, 0xEA, 0xA2, 0xE6, 0x54, 0x97, 0x58, 0xA7, 0x67, 0x6C};
//UUID IID_IMMESessionStreaming = {6, 0x6D, 0x7A, 0x77, 0xDB, 0xB3, 0x47, 0x9B, 0x86, 0xC, 0x7C, 0xC9, 0xEE, 0xB7, 0xB9, 0x2A};

/*
CMMESession_GetSetupInterface
CMMESession_Constructor
CMMESession_Destructor
CMMESession_IsStreamingLink
*/

class ICBMMEPlayer;

typedef struct
{
  u16 X;
  u16 Y;
  int Width;
  int Height;
} TRectangle;

class IMMESessionContentUtility: public IUnknown
{
public:
  virtual int IsFeatureValid();
  virtual int IsContentValid();
  virtual int GetMediaProperties(wchar_t* pFilePath, TMMEMediaProperties* mediaProperties);
  virtual int GetMediaFromMimeType(char* type);
  virtual int GetMediaFormats();
  virtual int GetVideoProfile();
  virtual int SaveVideoFrameAsImage();
};

class IMMESessionEqualizer: public IUnknown
{
public:
  virtual int Enable();
  virtual int Disable();
  virtual int IsEnabled();
  virtual int SetGain();
  virtual int GetGain();
  virtual int SetPreset();
};

class IMMESessionStreaming: public IUnknown
{
public:
  virtual int SetAccount();
  virtual int SetLocalBearerDetection(/*pIMMESessionStreaming, (TBool)pThis->settings.useLocalBearers*/);
  virtual int OpenNetworkConnection();
  virtual int CloseNetworkConnectionSession();
};

class IMMEPlayer: public IUnknown
{
public:
  virtual int GetHandle(int* handle);
  virtual int GetState(TMMEState* state);
  virtual int GetTime(TMMETime* elapsedTime);
  virtual int SetTime(TMMETime* offsetTime);
  virtual int SetDisplayAppearance(TRectangle* TMMEVideoArea);
  virtual int Play(int unk_null, bool repeat);
  virtual int Pause();
  virtual int SetFastForwardRewindBoundaryConditions(TMMEWindCondition windCondition);
  virtual int SetWindTimerInterval(int time);
  virtual int StartFastForward();
  virtual int StopFastForward();
  virtual int StartRewind();
  virtual int StopRewind();
  virtual int SlowMotion();
  virtual int SetFadeDownOnInterrupted(TMMEFadeDirection fadeDirection);
  virtual int StartAudioFade();
  virtual int Mute();
  virtual int UnMute();
  virtual int SetVolume();
  virtual int GetVolume();
};

class IMMESession: public IUnknown
{
public:
  virtual int BeginPlaybackSession(int unk1, int unk2, int unk3, int unk4, int* sessionHandle);
  virtual int EndPlaybackSession(int sessionHandle);
  virtual int RequestPlaybackSessionFocus();
  virtual int SetStereoWidening(bool activate);
  virtual int CreatePlayer(ICBMMEPlayer* pICBMMEPlayer, u16 msgBase, int clientData, wchar_t* pFilePath, TMMEMediaProperties* mediaProperties, int unk1_null, int unk2_null, IMMEPlayer** pIMMEPlayer);
};

class IMMEManager: public IUnknown
{
public:
  virtual int CreateSession(IMMESession** pIMMESession);
};

#line 22 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IIlluminationManager.h"



//UUID CID_CIlluminationManager = {0xD7, 0xEF, 0x2A, 0x56, 0x94, 0x72, 0x40, 0x5E, 0xBF, 0xCA, 0xA2, 0x83, 0x97, 0x79, 0xF1, 0x9A};
//UUID IID_IIlluminationManager = {0x60, 0x90, 0xF1, 0x81, 0xA5, 0x31, 0x43, 0x3A, 0x82, 0x30, 0x69, 0xF0, 8, 0xBC, 0xD1, 0xD1};

typedef enum
{
  UIBacklightStatus_On,
  UIBacklightStatus_Off,
  UIBacklightStatus_Blink,
  UIBacklightStatus_Low
} UIBacklightStatus_t;

typedef enum
{
  UIBacklightMode_On,
  UIBacklightMode_Off,
  UIBacklightMode_Automatic,
  UIBacklightMode_LowOff,
  UIBacklightMode_LowOn
} UIBacklightMode_t;

class ICBBacklight: public IUnknown
{
public:
  virtual void OnInitiated(void* statusCode, int nbrOfItems, bool random, bool loop, void* clientData);
};

class IBacklight: public IUnknown
{
public:
  virtual int GetStatus(int display, UIBacklightStatus_t* pStatus);
  virtual int GetMode(UIBacklightMode_t* pMode);
  virtual int GetOnLevel(int display, char* pLevel);
  virtual int SetOverrideMode(UIBacklightMode_t mode);
  virtual int unk_20(int);
  virtual int SetOnLevel(int display, char pLevel);
  virtual int ResetOverrideMode();
  virtual int KeyLight(bool mode);
  virtual int unk_30(int display);
  virtual int unk_34(int display);
  virtual int unk_38();
  virtual int Fade(int display);
  virtual int FadeOnTimer(int display, int time);
  virtual int unk_44(int unk1, int unk2, int unk3, int unk4, int time);
  virtual int unk_48();
  virtual int BlinkTime(int display, int onTime, int offTime);
  virtual int unk_50();
  virtual int ActiveDisplay(int display);
  virtual int DeactiveDisplay();
  virtual int unk_5C();
  virtual int unk_60();
  virtual int unk_64();
  virtual int On_TimerCB(ICBBacklight* pICBBacklight, u16 msgBase, int clientData, int* pTimerHandle);
  virtual int Off_TimerCB(int pTimerHandle);
  virtual int unk_70(int unk1, int unk2);
  virtual int unk_74();
  virtual int unk_78();
  virtual int unk_7C();
  virtual int Tally_Lamp(int id, int unk, int level);
  virtual int unk_84();
  virtual int unk_88();
  virtual int unk_8C();
  virtual int unk_90();
  virtual int unk_94();
};

/*
FadeToLevel
ActivateMode
On_State_Time
*/

class ILightEffect: public IUnknown
{
public:
  virtual int StartType(int effectTypeID);
  virtual int unk_14(int*);
  virtual int StartTypeOnLevel(int effectTypeID, char pLevel);
  virtual int StartEffectFile(wchar_t* filename);
  virtual int unk_20();
  virtual int unk_24();
  virtual int unk_28();
  virtual int unk_2C(int);
  virtual int unk_30();
  virtual int Stop();
  virtual int SetEffectColor(char* red, char* green, char* blue);
  virtual int unk_3C(void);
  virtual int unk_40();
  virtual int unk_44(int* unk);
  virtual int unk_48(/*..., int null, int null, ...*/);
  virtual int unk_4C();
  virtual int unk_50(/*int one, ...*/);
  virtual int unk_54(/*...*/);
};

class IIlluminationManager: public IUnknown
{
public:
  virtual int CreateBacklight(IBacklight** pIBacklight); //0x78
  virtual int CreateLightEffect(ILightEffect** pILightEffect); //0x74
};

#line 23 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IMusicServer_Manager.h"



#line 1 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\types\\MusicServer_types.h"







typedef enum
{
  TMusicServerEqPreset_Normal=0,
  TMusicServerEqPreset_Bass=1,
  TMusicServerEqPreset_Megabass=2,
  TMusicServerEqPreset_Voice=3,
  TMusicServerEqPreset_TrebleBoost=4,
  TMusicServerEqPreset_Manual=6
} TMusicServer_EqPreset;  //NON-CLEARBASS

typedef enum
{
  EqBand_63,
  EqBand_250,
  EqBand_1000,
  EqBand_4000,
  EqBand_16000,
  EqBand_Last
}TMusicServer_EqBand;

typedef enum
{
  MEDIAPLAYER_NONE=0,
  MEDIAPLAYER_PLAY,
  MEDIAPLAYER_STOP,
  MEDIAPLAYER_PAUSE,
  MEDIAPLAYER_FAST_FORWARD,
  MEDIAPLAYER_REWIND
} MEDIAPLAYER_STATE;

//////////////////////////////////////////////////////////////////////
/// @name Types
//@{

const TUnsigned MUSIC_SERVER_MAX_URI_LENGTH = 512;
const TUnsigned MUSIC_SERVER_MAX_PLAYLISTNAME_LENGTH = 251;


typedef enum
{
    //General
    MUSIC_SERVER_GENERAL_ERROR,               ///< Returned when none of the other error codes are applicable.
    MUSIC_SERVER_INTERRUPTED,                 ///< Returned when the session or the player was interrupted by another session
                                              ///< or player (with the same or higher priority) or a call.

    MUSIC_SERVER_NOT_SUPPORTED,               ///< Returned when some functionality not is supported with the current platform.
                                              ///< configuration or a file format not supported with current phone project configuration.
    MUSIC_SERVER_PLATFORM_ERROR,              ///< Returned when the platform is returning an error of unknown reason.
    MUSIC_SERVER_OUT_OF_MEMORY,               ///< Returned when some allocation failed due to lack of memory.
    MUSIC_SERVER_INPUT_PARAM_ERROR,           ///< Returned when there was some error in the input parameters.
    MUSIC_SERVER_NOT_ALLOWED_ERROR,           ///< Returned when an action is not allowed to be performed (due to wrong state etc.).

    //Player specific
    MUSIC_SERVER_CREATE_PLAYER_FAILED,        ///< The MME Player failed during create.
    MUSIC_SERVER_NOT_AUTHORIZED,              ///< Returned when there are not any available resources, and another ongoing activity has higher priority.
    MUSIC_SERVER_FILE_NOT_FOUND,              ///< Returned when the specified file is not found, local or on media server.
    MUSIC_SERVER_END_OF_FILE,                 ///< Returned when the player stopped since end of file was reached.
    MUSIC_SERVER_CLIENT_TERMINATION,          ///< Returned when the player stopped since the client called the stopped method.

    //DRM specific
    MUSIC_SERVER_DRM_ERROR,                   ///< Returned when the specified file is a DRM file, and DRM is returning an error of unknown reason.
    MUSIC_SERVER_DRM_PLAYRIGHTS_EXPIRED,      ///< Returned when the specified file is a DRM file, and the credentials not allows playback.
    MUSIC_SERVER_DRM_AUDIO_ROUTING_FORBIDDEN, ///< Returned when the specified file is a DRM file, and audio routing to an accessory is forbidden.
    MUSIC_SERVER_DRM_MSDRM_EXPIRED,           ///< Returned when the file is a MS DRM file and no valid license.
    MUSIC_SERVER_DRM_RIGHTS_RENEWABLE,
    MUSIC_SERVER_DRM_WAITING_FOR_RIGHTS,      ///< Returned when the specified file is a DRM file, and the DRM system is busy aquiring new license

    MUSIC_SERVER_LAST                     ///< Place holder. Put new data before this!
} TMusicServer_ErrorCode;




//*************************** Should Be Changed*****************************

/**
 * This type is used to indicate mute reason received from MME.
 */
typedef TMMEMuteReason TMusicServer_MuteReason;

//ContentProvider
//typedef TMultimediaContentProvider_LocationPath TMusicServer_LocationPath;



/**
 * The set of data to describe time.
 */
typedef struct
{
    FUint32 hours;
    FUint32 minutes;
    FUint32 seconds;
} TMusicServer_Time;



/**
 * The set of settings used in the music server
 */
typedef enum
{
    TMusicServerSetting_Loop,
    TMusicServerSetting_Random
} TMusicServer_Settings;



/**
 * The set of equalizer bands available.
 * 
 * The possible values are:
 *
 * TMMEEqBand_ClearBass1,   Only for Clear Audio
 * TMMEEqBand_ClearBass2,   Only for Clear Audio
 * TMMEEqBand_63,           Only for ordinary EQ
 * TMMEEqBand_250,          Only for ordinary EQ
 * TMMEEqBand_400,          Only for Clear Audio
 * TMMEEqBand_1000,         Both Clear Audio and ordinary EQ
 * TMMEEqBand_2500,         Only for Clear Audio
 * TMMEEqBand_4000,         Only for ordinary EQ
 * TMMEEqBand_6300,         Only for Clear Audio
 * TMMEEqBand_16000,        Both Clear Audio and ordinary EQ
 *
 */
//typedef TMMEEqBand TMusicServer_EqBand;




/**
 * The set of equalizer presets available.
 * 
 * The possible values are:
 *
 * TMMEEqPreset_Heavy,
 * TMMEEqPreset_Pops,
 * TMMEEqPreset_Jazz,
 * TMMEEqPreset_Unique,
 * TMMEEqPreset_Soul,
 * TMMEEqPreset_EasyListening,
 * TMMEEqPreset_BassBoost,
 * TMMEEqPreset_TrebleBoost,
 *
 */
//typedef TMMEEqPreset TMusicServer_EqPreset;

//**************************** End of change *****************************'




/**
 * The set of music server states.
 */
typedef enum
{
    TMusicServerState_Idle,             ///< Player is idle, eg is in the init phase but not yet fully initiated.
    TMusicServerState_Initiated,        ///< Player is initiated.
    TMusicServerState_Playing,          ///< Player is playing.
    TMusicServerState_Paused,           ///< Player is paused. Use the resume method to resume the playback.
    TMusicServerState_FastForwarding,   ///< Player is fast forwarding.
    TMusicServerState_Rewinding,        ///< Player is rewinding.
    TMusicServerState_Interrupted,      ///< Player is interrupted by another playback session/player/call.
    TMusicServerState_Unknown,          ///< State is unknown to the Music Server.
    TMusicServerState_Last              ///< Place holder. Put new data before this!
} TMusicServer_State;




/**
 * The set of music server status.
 */
typedef enum
{
    TMusicServerStatus_ActiveMaximized,   ///< Player is started in maximized mode, can be paused or playing.
    TMusicServerStatus_ActiveMinimized,   ///< Player is started in maximized mode, can only be playing in minimized.
    TMusicServerStatus_Inactive,          ///< Player is shut down.
    TMusicServerStatus_Last               ///< Place holder. Put new data before this!
} TMusicServer_Status;




/**
 * Defines an unused handle.
 *
 */
const FUint32 MUSICSERVER_HANDLE_NOT_USED = 0;




/**
 * The set of causes that can be sent
 * from the mutlimedia engine.
 */
typedef enum
{
    TMusicServerCause_Error,                      ///< General unspecified error.
    TMusicServerCause_Platform_Error,             ///< Unspecified platform error.
    TMusicServerCause_Beginning_Of_File_Passed,   ///< Passed beginnig of media file (case of rewind operation).
    TMusicServerCause_End_Of_File,                ///< End of media file reached.
    TMusicServerCause_Client_Termination,         ///< Client terminated the session player.
    TMusicServerCause_DRM_Credentials_Expired,    ///< DRM credentials expired.
    TMusicServerCause_File_Not_Found,             ///< File does not exist.
    TMusicServerCause_Last                        ///< Place holder. Put new data before this!
} TMusicServer_Cause;




/**
 * The set of actions that can be sent
 * to the mutlimedia engine.
 */
typedef enum
{
    TMusicServerAction_None,              ///< No action set.
    TMusicServerAction_CreateMaximized,   ///< Must be able to create player maximized from extern part, accessories.
    TMusicServerAction_CreateMinimized,   ///< Must be able to create player minimized from extern part, accessories.
    TMusicServerAction_Destroy,           ///< Must be able to destroy player from extern part, accessories.
    TMusicServerAction_Play,              ///< Starts player.
    TMusicServerAction_Pause,             ///< Pauses player.
    TMusicServerAction_Next,              ///< Get next file.
    TMusicServerAction_Previous,          ///< Get previous file.
    TMusicServerAction_StartFastForward,  ///< Starts fastforward of player.
    TMusicServerAction_StopFastForward,   ///< Stops fastfowardad of player, must be done before play.
    TMusicServerAction_StartRewind,       ///< Starts rewind of player.
    TMusicServerAction_StopRewind,        ///< Stops rewind of player, must be done before play.
    TMusicServerAction_Last               ///< Place holder. Put new data before this!
} TMusicServer_Action;


/**
 * Album art image types 
 */
typedef enum
{
    TMusicServer_AlbumArt_ImageType_Jpeg,
    TMusicServer_AlbumArt_ImageType_Gif,
    TMusicServer_AlbumArt_ImageType_Png,
    TMusicServer_AlbumArt_ImageType_Bmp,
    TMusicServer_AlbumArt_ImageType_None,
    TMusicServer_AlbumArt_ImageType_Embedded
} TMusicServer_AlbumArt_ImageType;

//@} End of Types

#line 5 "E:\\SE\\Port\\elf2vkp\\include\\..\\\\include\\classes\\IMusicServer_Manager.h"

//UUID CID_СMusicServer_Manager = {9, 0xE5, 0x76, 0x91, 0x7F, 0x36, 0x4B, 0x59, 0x82, 0xB9, 0x89, 0x19, 0xEA, 0x18, 0xB6, 0xF8};
//UUID IID_IMusicServer_Manager = {0xAE, 0x67, 0x65, 0x71, 0xB3, 0x99, 0x44, 0xBE, 0xA5, 0xF4, 0xE6, 0x96, 0xCA, 0x63, 0x18, 0x6B};

class IMusicServer: public IUnknown
{
public:
  virtual void* unk_0x10();
  virtual void* unk_0x14();
  virtual void* unk_0x18();
  virtual int GetItem( FUint32 itemIndex, FUint32 length, TChar* pArtist, TChar* pAlbum, TChar* pTitle );
  virtual int GetFocusedItem( FUint32 itemIndex, FUint32 length, TChar* pArtist, TChar* pAlbum, TChar* pTitle, TChar* pFilename, TMusicServer_Time* pPlaylength, TMusicServer_Time* pResumePosition, TBool* pContainsAlbumart, TBool* pIsRealMediaFile );
  virtual int GetFilename( FUint32 itemIndex, FUint32 length, TChar* pFilename );
  virtual int unk_0x28();
  virtual int unk_0x2C();
  virtual int unk_0x30();
  virtual int Play( FUint32 itemIndex );  //0x34
  virtual int Pause( void );              //0x38
  virtual int FastFoward( void );         //0x3c
  virtual int Rewind( void );             //0x40
  virtual int Next( TBool activePress );  //0x44
  virtual int Previous( void );           //0x48
  virtual int SetApplicationWindowMode( TBool maximized ); // unk_0x4C();
  virtual int unk_0x50();
  virtual int unk_0x54();
  virtual int SetEqualizerGain( int equalizerBand, TSigned equalizerGain );
  virtual int SetSettings_Boolean( TMusicServer_Settings settingType, TBool setting );//void* unk_0x5C();
  virtual int SetSettings_Int( FUint16 setting ); //void* unk_0x60();
  virtual int unk_0x64();
  virtual int SetSettings_Time( TMusicServer_Time settingTime ); // unk_0x68();
  virtual int GetSettings_Boolean( TMusicServer_Settings settingType, TBool* setting ); //unk_0x6C();
  virtual int GetCurrentItemIndex( FUint32* itemIndex ); //unk_0x70();
  virtual int unk_0x74();
  virtual int GetTime( TMusicServer_Time* time ); //0x78;
  virtual int RemoveFromPlaylist( FUint32 itemIndex );
  virtual int SavePlayQueue( TChar* pPlaylistname );
};

class IMusicServer_ExternalStart;

class IMusicServer_Manager: public IUnknown
{
public:
  virtual int CreateMusicServer(void* pIShell, IMusicServer** pIMusicServer);
  virtual int method1(IMusicServer_ExternalStart** pIMusicServer_ExternalStart);
};

#line 24 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"


__thumb void* malloc( int size );
__thumb void mfree( void* mem );

extern "C"
{
#pragma swi_number=0x10D
__swi __arm int elfload( const wchar_t* filename, void* param1, void* param2, void* param3 );

#line 41 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
  void* memalloc( int minus_one, int size, int f1, int f2, const char* fname, int fline );
  void memfree( int zero, void* mem, const char* fname, int fline );
  void* memcalloc( int minus_one, int size, int NoOfItems, int f1, int f2, const char* fname, int fline );


#line 71 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
  void Display_SetBrightness( int level );



  FONT_DESC* GetFontDesc( void );
  int* GetFontCount( void );
  int SetFont( int );
  void DrawString( TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color );
  void GC_PutChar( GC* gc, int x, int y, int width, int height, IMAGEID img );
  void GC_DrawIcon( int x, int y, IMAGEID );
  void GC_DrawImage( int x, int y, IMAGEID );
  int GetImageHeight( IMAGEID );
  int GetImageWidth( IMAGEID );
  int Disp_GetTextIDHeight( TEXTID );
  int Disp_GetTextIDWidth( TEXTID, int len );
  int GetVolumeSize( wchar_t* root_folder, VOLUMESIZE* );



  
  void* memset( void* mem, char chr, int size );
  int memcpy( void* dest, const void* source, int cnt );
  int sprintf( char* buf, const char* fmt, ... );
  int snwprintf( wchar_t* buffer, int size, const wchar_t* fmt, ... );
  int _fopen( const wchar_t* filpath, const wchar_t* filname, unsigned int mode, unsigned int rights, FILELISTITEM* destfname );
  int fclose( int file );
  int fread( int file, void* ptr, int size );
  int fwrite( int file, const void* ptr, int size );
  int fstat( const wchar_t* path, const wchar_t* fname, FSTAT* fstat_stuct );
  DIR_HANDLE* AllocDirHandle( const wchar_t* path );
  FILELISTITEM* GetFname( DIR_HANDLE*, FILELISTITEM* );
  void* DataBrowserDesc_Create( void );
  void DataBrowserDesc_SetItemStyle( void* DataBrowserDesc, int style );
  void DataBrowserDesc_SetHeaderText( void* DataBrowserDesc, TEXTID );
  void DataBrowserDesc_SetFolders( void* DataBrowserDesc, const wchar_t** FolderList );
  void DataBrowserDesc_SetOKSoftKeyText( void* DataBrowserDesc, TEXTID );
  void DataBrowser_Create( void* DataBrowserDesc );
  void DataBrowserDesc_Destroy( void* DataBrowserDesc );
  wchar_t* getFileExtention( wchar_t* fname );
  int DataBrowser_isFileInListExt( const wchar_t* ext_table, const wchar_t* path, const wchar_t* fname );
  void Timer_ReSet( u16* timer, int time, TIMERPROC onTimer, LPARAM lparam );
  u16 Timer_Set( int time, TIMERPROC onTimer, LPARAM lparam );
  void Timer_Kill( u16* timerID );
  int CreateBook( BOOK* pbook, void (*onClose)( BOOK* ), const PAGE_DESC* bp, const char* name, int ParentBookID, const APP_DESC* appdesc );
  void BookObj_KillBook( BOOK* book );
  void BookObj_GotoPage( BOOK* book, const PAGE_DESC* page );
  void BookObj_ReturnPage( BOOK* book, int );
  void FreeBook( BOOK* book );
  BOOK* FindBook( IS_NEEDED_BOOK );
  BOOK* Find_StandbyBook( void );
  void BookObj_SetFocus( BOOK* book, int display );
  void GUIObject_SetTitleText( GUI*, TEXTID );
  void GUIObject_Show( GUI* );
  void ListMenu_SetCursorToItem( GUI_LIST*, int item );
  void GUIObject_SetStyle( GUI*, int UI_OverlayStyle_t );
  int GUIonMessage_GetCreatedItemIndex( GUI_MESSAGE* msg );
  char GUIonMessage_SetMenuItemText( GUI_MESSAGE* msg, TEXTID );
  char GUIonMessage_SetMenuItemSecondLineText( GUI_MESSAGE* msg, TEXTID );
  char GUIonMessage_SetMenuItemInfoText( GUI_MESSAGE* msg, TEXTID );
  char GUIonMessage_SetMenuItemUnavailableText( GUI_MESSAGE* msg, TEXTID );
  void GUIonMessage_SetMenuItemIcon( GUI_MESSAGE* msg, int align, IMAGEID );
  void DispObject_SetTitleText( DISP_OBJ*, TEXTID );
  int ListMenu_GetSelectedItem( GUI_LIST* );
  void ListMenu_SetItemStyle( GUI_LIST*, int style );
  int IsScreenSaverBook( BOOK* bk );
  void StatusIndication_SetItemText( GUI*, int item, TEXTID );
  void StatusIndication_ShowNotes( TEXTID );
  GUI* CreateStringInputVA( int, ... );
  GUI_ONEOFMANY* CreateOneOfMany( BOOK* book );
  void OneOfMany_SetItemCount( GUI_ONEOFMANY*, int count );
  void OneOfMany_SetChecked( GUI_ONEOFMANY*, int checked );
  void OneOfMany_SetTexts( GUI_ONEOFMANY*, TEXTID* strids, int Count );
  int OneOfMany_GetSelected( GUI_ONEOFMANY* );
  void StatusIndication_Item8_SetText( TEXTID );
  void GUIObject_SoftKeys_SetAction( GUI*, u16 actionID, SKACTIONPROC proc );
  void GUIObject_SoftKeys_SetText( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_SetEnable( GUI*, u16 actionID, BOOL );
  void GUIObject_SoftKeys_AddErrorStr( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_RemoveItem( GUI*, u16 actionID );
  void GUIObject_SoftKeys_SetVisible( GUI*, u16 actionID, BOOL );
  void GUIObject_SoftKeys_SuppressDefaultAction( GUI*, u16 actionID );
  wchar_t* wstrcpy( wchar_t* dest, const wchar_t* source );
  wchar_t* wstrncpy( wchar_t* dest, const wchar_t* source, int maxlen );
  wchar_t* wstrcat( wchar_t* wstr, const wchar_t* subwstr );
  wchar_t* wstrncat( wchar_t* wstr, const wchar_t* subwstr, int maxlen );
  int wstrcmp( const wchar_t* wstr1, const wchar_t* wstr2 );
  int wstrlen( const wchar_t* wstr );
  wchar_t* str2wstr( wchar_t* wstr, const char* str );
  int strcmp( const char* str1, const char* str2 );
  int strlen( const char* str );
  char* wstr2strn( char* str, const wchar_t* wstr, int maxlen );

  TEXTID TextID_CreateIntegerID( int num );
  TEXTID TextID_Create( const void* wstr, int TEXT_ENCODING, int len );
  void TextID_GetString( TEXTID, char* str, int maxlen );
  int TextID_GetWString( TEXTID, wchar_t* dest, int maxlen );
  int TextID_GetLength( TEXTID );
  void TextID_Destroy( TEXTID txt );
  TEXTID TextID_Copy( TEXTID );
  /*
#elif defined (DB3150) || defined (DB3200) || defined (DB3210) || defined (DB3350)
  TEXTID TextID_Create( const void* wstr, TEXT_ENCODING, int len, char* filename, int line_num );
  TEXTID TextID_CreateIntegerID( int num, char* filename, int line_num );
  void TextID_GetString( TEXTID, char* str, int maxlen, int null );
  int TextID_GetWString( TEXTID, wchar_t* dest, int maxlen, char* filename, int line_num );
  int TextID_GetLength( TEXTID, char* filename, int line_num );
  void TextID_Destroy( TEXTID, char* filename, int line_num );
  TEXTID TextID_Copy( TEXTID, char* filename, int line_num );
#endif
  */
  int AB_DEFAULTNBR_GET( int rec_num, void* mem_0x30, int* unk );
  int AB_READPHONENBR( AB_NUM_ITEM*, int rec_num, int field_ID );
  int AB_GETNBROFITEMS( int get_from, int sub_id );
  int PNUM_len( BCD_TEXT pnum );
  void PNUM2str( char* str, BCD_TEXT pnum, int len, int max_len );
  DISP_OBJ* GUIObject_GetDispObject( GUI* );
  LIST* List_Create( void );
  void List_Destroy( LIST* lst );
  int List_InsertFirst( LIST* lst, void* item );
  int REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE( const int* sync, u16* ImageHandler, char* unk );
  void REQUEST_DATEANDTIME_GET( const int* sync, DATETIME* dt );
  void IndicationDevice_Backlight_FadeToLevel( int unk_zero, int bl_level );
  int GetFreeBytesOnHeap( void );
  void BookObj_Hide( BOOK* book, int display );
  void BookObj_Show( BOOK* book, int display );
  void StartAPP( const wchar_t* appname );
  void ListMenu_SetOnMessage( GUI_LIST*, int (*proc)( GUI_MESSAGE* ) );
  char* manifest_GetParam( const char* buf, const char* param_name, int unk );
  int lseek( int file, int offset, int mode );
  void SetLampLevel( int level );
  void* List_RemoveAt( LIST* lst, int index );
  PROCESS GetCurrentPID( void );
  int List_IndexOf( LIST* lst, void* item );
  union SIGNAL* alloc( OSBUFSIZE size, SIGSELECT signo );
  union SIGNAL* receive( const SIGSELECT* sigsel );
  void send( union SIGNAL** sig, PROCESS to );
  PROCESS sender( union SIGNAL** sig );
  void free_buf( union SIGNAL** sig );
  PROCESS create_process( PROCESS_TYPE proc_type, char* name, OSENTRYPOINT* entrypoint, OSADDRESS stack_size, OSPRIORITY priority, OSTIME timeslice, PROCESS pid_block, void* redir_table, OSVECTOR vector, OSUSER user );
  void start( PROCESS pid );
  int get_ptype( PROCESS pid );
  PROCESS current_process( void );
  void delay( OSTIME timeout );
  OSBOOLEAN hunt( const char* name, OSUSER user, PROCESS* name_, union SIGNAL** hunt_sig );
  void kill_proc( PROCESS pid );
  union SIGNAL* receive_w_tmo( OSTIME timeout, SIGSELECT* sel );
  void stop( PROCESS pid );
  OSADDRESS get_envp( PROCESS pid, char* name );
  OSBOOLEAN set_envp( PROCESS pid, char* name, OSADDRESS value );
  PROCESS get_bid( PROCESS pid );
  int datetime2unixtime( DATETIME* dt );
  char* strcpy( char* dest, const char* source );
  char* UIEventName( int event );
  void UI_Event( int event );
  void UI_Event_wData( int event, void* message, void (*free_proc)( void* ) );
  void UI_Event_toBookID( int event, int BookID );
  void UI_Event_toBookIDwData( int event, int BookID, void* message, void (*free_proc)( void* ) );
  int List_Find( LIST* lst, void* itemtofind, LISTFINDCALLBACK cmp_proc );
  void* List_Get( LIST* lst, int index );
  wchar_t* wstrrchr( const wchar_t* wstr, wchar_t wchar );
  void BookObj_CallSubroutine( BOOK* book, BOOK_SUBROUTINE* subr );
  int List_InsertLast( LIST* lst, void* item );
  void debug_printf( const char* fmt, ... );
  int PlayFile( const wchar_t* path, const wchar_t* fname );
  int REQUEST_PROFILE_GETACTIVEPROFILE( const int* sync, int* level );
  int Profile_SetActive( int NUMprof, int set_in_gdfs_flag );
  int isKeylocked( void );
  int IsMediaPlayerVideoBook( BOOK* bk );
  int REQUEST_DATEFORMAT_GET( const int* sync, char* DateFormat );
  int REQUEST_TIMEFORMAT_GET( const int* sync, char* TimeFormat );
  TEXTID Date2ID( DATE*, int DateFormat, int );
  TEXTID Time2ID( TIME*, char TimeFormat, int isSec );
  GUI_LIST* CreateListMenu( BOOK*, int display );
  void ListMenu_SetItemCount( GUI_LIST*, int item_count );
  void GUIObject_SoftKeys_SetInfoText( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_SetItemAsSubItem( GUI*, u16 actionID, int subitem );
  int REQUEST_SYSTEM_SHUTDOWN( void );
  int REQUEST_SYSTEM_RESTART( void );
  void GUIObject_SoftKeys_SetTexts( GUI*, u16 actionID, TEXTID short_text, TEXTID full_text );
  int IsRightNowBook( BOOK* book );
  int IsVolumeControllerBook( BOOK* book );
  GUI_TABMENUBAR* CreateTabMenuBar( BOOK* book );
  void TabMenuBar_SetTabCount( GUI_TABMENUBAR*, int count );
  void TabMenuBar_SetTabGui( GUI_TABMENUBAR*, int tab, GUI* );
  void TabMenuBar_SetTabIcon( GUI_TABMENUBAR*, int tab, IMAGEID, int for_state );
  GUI* GUIObject_Destroy( GUI* );
  void GUIInput_SetIcon( GUI*, IMAGEID );
  int StringInput_GetStringAndLen( GUI*, wchar_t**, u16* );
  int AudioControl_Vibrate( PAudioControl pIAudioControl, int vibratime, int pausetime, int totaltime );
  GUI_NOFMANY* CreateNOfMany( BOOK* book );
  void NOfMany_SetTexts( GUI_NOFMANY*, TEXTID* strids, int items_count );
  void NOfMany_SetChecked( GUI_NOFMANY*, u16* checked_table, int items_count );
  void NOfMany_SetCursor( GUI_NOFMANY*, int item );
  int NOfMany_GetCheckedCount( GUI_NOFMANY* );
  int NOfMany_GetChecked( GUI_NOFMANY*, u16* buffer );
  void NOfMany_SetOnMessage( GUI_NOFMANY*, int (*proc)( GUI_MESSAGE* ) );
  PAudioControl AudioControl_Init( void );
  void OneOfMany_SetFocused( GUI_ONEOFMANY*, int item );
  void OneOfMany_SetOnMessage( GUI_ONEOFMANY*, int (*proc)( GUI_MESSAGE* ) );
  GUI_FEEDBACK* CreateMonitorFeedback( TEXTID, BOOK*, void (*onbusy)( BOOK* ), void (*onedit)( BOOK* ), void (*ondelete)( BOOK* ) );
  void Feedback_SetText( GUI_FEEDBACK*, TEXTID );
  int GetBatteryState( void* unused, BATT* );
  GC* get_DisplayGC( void );
  void DispObject_GetRect( DISP_OBJ*, RECT* );
  void GC_GetRect( GC* gc, RECT* );
  int GC_GetXX( GC* gc );
  void GC_SetXX( GC* gc, int );
  void GC_ValidateRect( GC* gc, RECT* );
  void BookObj_AddGUIObject( BOOK* book, GUI* );
  void DrawRect( int x1, int y1, int x2, int y2, int pen_color, int brush_color );
  void XGUIList_AddGUIObject( XGUILIST* xguilist, GUI* );
  void DispObject_InvalidateRect( DISP_OBJ*, RECT* );
  int GUIObject_Create( GUI*, void (*GuiDestroy)( GUI* ), void (*DispDescCreate)( DISP_DESC* ), BOOK*, void (*DispObjCallBack)( DISP_OBJ*, void* msg, GUI* ), int display, int size_of_gui );
  int root_list_get_session_count( void );
  UI_APP_SESSION* root_list_get_session( int num_session );
  BOOK* SESSION_GetTopBook( UI_APP_SESSION* );
  int MainInput_strlen( GUI* );
  BCD_TEXT MainInput_getPNUM( GUI* );
  int BookObj_GetBookID( BOOK* book );
  int wstrncmp( const wchar_t*, const wchar_t*, int );
  int DispObject_GetAbsoluteXPos( DISP_OBJ* );
  int DispObject_GetAbsoluteYPos( DISP_OBJ* );
  int GetThemeColor( int, int );
  int REQUEST_SETTING_SILENCE_SET( const int* sync, u16 profile, u16 value );
  int REQUEST_SETTING_SILENCE_GET( const int* sync, u16 profile, char* silence_mode );
  void VCALL_Init( void* vc );
  void VCALL_SetName( void* vc, wchar_t* name, unsigned short name_len );
  void VCALL_SetNameIcon( void* vc, IMAGEID );
  void VCALL_SetNumber( void* vc, wchar_t* number, unsigned short num_len );
  void VCALL_SetHZ1( void* vc, int, u16 );
  void VCALL_SetHZ2( void* vc, u16 );void MakeVoiceCall( int SessioID, void* vc, int flag );
  void FileDelete( wchar_t* path, wchar_t* filename, int* error );
  void GUIObject_SetFocus( GUI*, int );
  int MSG_SendMessage_CreateMessage( int, void* );
  int MSG_SendMessage_DestroyMessage( void* );
  int MSG_SendMessage_AddRecipient( void*, wchar_t*, wchar_t*, int, int );
  int MSG_SendMessage_Start( int, void*, int );
  int AB_POSITIONNBR_GET( void* ab_name, char*, u16*, void* ab_num );
  TEXTID AB_NAME_ITEM2TextID( AB_STR_ITEM* ab_name );
  TEXTID AB_NUM_ITEM2TextID( AB_NUM_ITEM* ab_num_item );
  int GetABRecNum( AB_GET_STRUCT* ); //nullsub(void)
  GUI* SBY_GetMainInput( BOOK* StandBy ); // !!!!! Not real !!!!!!
  GUI* SBY_GetStatusIndication( BOOK* StandBy ); // !!!!! Not real !!!!!!
  int REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET( const int* sync, int* );
  GUI* DispObject_GetGUI( DISP_OBJ* );
  DISP_OBJ* Display_GetFocusedDispObject( int display );
  char DispObject_GetVisible( DISP_OBJ* );
  DISP_DESC* DispObject_GetDESC( DISP_OBJ* ); // !!!!! Not real !!!!!!
  void DISP_DESC_SetName( DISP_DESC*, const char* name );
  char* DispObject_GetName( DISP_OBJ* );
  void DISP_DESC_SetSize( DISP_DESC*, u16 size );
  void DISP_DESC_SetOnCreate( DISP_DESC*, DISP_OBJ_ONCREATE_METHOD );
  DISP_OBJ_ONCREATE_METHOD DispObject_GetOnCreate( DISP_OBJ* );
  void DISP_DESC_SetOnClose( DISP_DESC*, DISP_OBJ_ONCLOSE_METHOD );
  DISP_OBJ_ONCLOSE_METHOD DispObject_GetOnClose( DISP_OBJ* );
  void DISP_DESC_SetOnRedraw( DISP_DESC*, DISP_OBJ_ONREDRAW_METHOD );
  DISP_OBJ_ONREDRAW_METHOD DispObject_GetOnRedraw( DISP_OBJ* );
  void DISP_DESC_SetOnKey( DISP_DESC*, DISP_OBJ_ONKEY_METHOD );
  DISP_OBJ_ONKEY_METHOD DispObject_GetOnKey( DISP_OBJ* );
  void DISP_DESC_SetOnRefresh( DISP_DESC*, DISP_OBJ_METHOD );
  DISP_OBJ_METHOD DispObject_GetonRefresh( DISP_OBJ* );
  void DISP_DESC_SetMethod06( DISP_DESC*, DISP_OBJ_METHOD );
  DISP_OBJ_METHOD DispObject_GetMethod06( DISP_OBJ* );
  void DISP_DESC_SetOnLayout( DISP_DESC*, DISP_OBJ_ONLAYOUT_METHOD );
  DISP_OBJ_METHOD DispObject_GetOnLayout( DISP_OBJ* );
  void DISP_DESC_SetOnConfig( DISP_DESC*, DISP_OBJ_ONCONFIG_METHOD );
  DISP_OBJ_METHOD DispObject_GetOnConfig( DISP_OBJ* );
  void DISP_DESC_SetMethod0A( DISP_DESC*, DISP_OBJ_METHOD );
  DISP_OBJ_METHOD DispObject_GetMethod0A( DISP_OBJ* );
  void JavaSession_Manager( int cmd ); //nullsub(void)
  TEXTID JavaSession_GetName( void ); //nullsub(ret 0x6FFFFFFF)
  UI_APP_SESSION* BookObj_GetSession( BOOK* book );
  void GUIonMessage_SetNumberOfSubItems( GUI_MESSAGE* msg, int unk, int num_sub_items );
  void GUIonMessage_SubItem_SetText( GUI_MESSAGE* msg, TEXTID );
  int GUIonMessage_SubItem_GetCreatedParentIndex( GUI_MESSAGE* msg );
  void GoMusic( void );
  int GUIonMessage_SubItem_GetSelectedIndex( GUI_MESSAGE* msg );
  void GUIonMessage_SubItem_SetDisabled( GUI_MESSAGE* msg, BOOL state );
  int PlayFileV( const wchar_t* path, const wchar_t* fname, int vol );
  int GetSilent( void );
  int GetVibrator( int ignorevibrator, int ignoresilent );
  int GetAudioSettings( int what, char* retvalue );
  int GUIonMessage_SubItem_GetCreatedIndex( GUI_MESSAGE* msg );
  int GUIonMessage_SubItem_GetSelectedParentIndex( GUI_MESSAGE* msg );
  void DestroyDirHandle( DIR_HANDLE* handle );
  void GetOtherExtMethods( FILESUBROUTINE** );
  int MessageBox( TEXTID header_text, TEXTID message_text, IMAGEID, int style, int time, BOOK* book );
  int Display_GetHeight( int display );
  int Display_GetWidth( int display );
  void PlaySystemSound( int SndNumber );
  int TabMenuBar_GetFocusedTab( GUI_TABMENUBAR* );
  void TabMenuBar_SetFocusedTab( GUI_TABMENUBAR*, int tab_num );
  int GC_GetPenColor( GC* gc );
  void GC_SetPenColor( GC* gc, int pen_color );
  void GC_SetPixel( GC* gc, int x1, int y1, int color );
  void GC_DrawLine( GC* gc, int x1, int y1, int x2, int y2 );
  void GC_DrawFRect( GC* gc, int color, int x1, int y1, int x2, int y2 );
  int GC_WritePixels( GC* gc, int x1, int y1, int x2, int y2, int* bmp );
  
#line 391 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\..\\\\include\\Function.h"
  
  int memcmp( const void* m1, const void* m2, int n );
  int strncmp( const char* s1, const char* s2, int len );
  char* strncpy( char* dest, const char* source, int maxlen );
  char* strcat( char* dest, const char* src );
  void GUIObject_SetTitleType( GUI*, int type );
  void GUIonMessage_SetItemDisabled( GUI_MESSAGE* msg, BOOL );
  int REQUEST_IMAGEHANDLER_INTERNAL_REGISTER( const int* sync, u16 ImageHandler, wchar_t* path, wchar_t* fname, int unk, IMAGEID*, char* error );
  int REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER( const int* sync, u16 ImageHandler, u16*, u16*, IMAGEID, int unk_1, char* error );
  int iconidname2id( const wchar_t* idname, int maxnamelen, int* id );
  int textidname2id( const wchar_t* idname, int maxnamelen, TEXTID* id );
  void ListMenu_SetNoItemText( GUI_LIST*, TEXTID str );
  int IsFmRadioBook( BOOK* bk );
  IS_NEEDED_BOOK get_IsFmRadioBook( void );
  int IsAudioPlayerBook( BOOK* bk );
  IS_NEEDED_BOOK get_IsAudioPlayerBook( void );
  void PlayerControl( BOOK* AudioPlayerBook, int );
  void SwitchRadioStationFromList( BOOK* FmRadioBook, int );
  void Shortcut_Run( wchar_t* shortcut_name );
  int mkdir( const wchar_t* path );
  int rmdir( const wchar_t* path, int zero );
  int chmod( const wchar_t* path, const wchar_t* fname, int amode );
  int rename( const wchar_t* oldpath, const wchar_t* oldfname, const wchar_t* newpath, const wchar_t* newfname, int zero );
  void* CallID_GetCallStatusDesc( int CallID );
  wchar_t* CallStatusDesc_GetName( void* CallStatusDesc );
  void List_DestroyElements( LIST* lst, int (*cmp_proc)( void* item ), void (*free_proc)( void* item ) );
  char* strstr( const char* str1, const char* str2 );
  int GPRS_GetLastSessionInfo( int, GPRS_SESSION_INFO* );
  int wstrcmpni( const wchar_t* wstr1, const wchar_t* wstr2, int len );
  int wtoi( const wchar_t* wstr, int len, int* dest );
  void DATE_GetWeekDay( DATE*, char* dest );
  void Cale_GetSettings( int setID, void* );
  wchar_t* wstrwstr( const wchar_t* wstr1, const wchar_t* wstr2 );
  int wstrcmpi( const wchar_t* ws1, const wchar_t* ws2 );
  wchar_t* wstrchr( const wchar_t* source, wchar_t chr );
  void GUIObject_SoftKeys_Hide( GUI* );
  void GUIObject_SoftKeys_Show( GUI* );
  DISP_OBJ* DispObject_SoftKeys_Get( void );
  int ThemeImage_SetImage( int type, int, int, const wchar_t* path, const wchar_t* fname, int );
  GUI* CreateYesNoQuestionVA( int zero, ... );
  void ListMenu_SetItemSecondLineText( GUI_LIST*, u16 Item, TEXTID );
  void _REQUEST_OAF_START_APPLICATION( const int* sync, int __zero, MIDP_DESC*, int ___zero );
  wchar_t* FSX_GetInvalidChar( wchar_t* name );
  void DataBrowserDesc_SetFoldersNumber( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetActions( void* DataBrowserDesc, char* actions );
  void DataBrowserDesc_SetSelectAction( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetSelectActionOnFolders( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetBookID( void* DataBrowserDesc, int BookID );
  void DataBrowserDesc_SetItemFilter( void* DataBrowserDesc, DB_FILE_FILTER );
  void DataBrowserDesc_SetOption( void* DataBrowserDesc, char* option );
  void DataBrowserDesc_SetOpenEmptyFolder( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetFileExtList( void* DataBrowserDesc, const wchar_t* ExtList );
  void FSX_RemoveIllegalSymbolsName( FILEITEM* );
  FILEITEM* FILEITEM_Create( void );
  void FILEITEM_Destroy( FILEITEM* );
  GUI* CreateDateInputVA( int zero, ... );
  GUI* CreateTimeInputVA( int zero, ... );
  void StringInput_SetCursorPosition( GUI*, u16 curs_pos, char unk );
  void BookObj_CallPage( BOOK* book, const PAGE_DESC* page );
  unsigned int DateInput_GetDateInt( GUI* );
  unsigned int TimeInput_GetTimeInt( GUI* );
  int GC_GetBrushColor( GC* gc );
  void GC_SetBrushColor( GC* gc, int brush_color );
  void GC_DrawRoundRect( GC* gc, RECT*, int arcWidth, int arcHeight, int border_flag, int fill_flag );
  BOOK* MenuBook_Desktop( int mode, int BookID );
  wchar_t* MenuBook_Desktop_GetSelectedItemID( BOOK* MenuBook_Desktop );
  void BookObj_SoftKeys_SetAction( BOOK* book, int actionID, SKACTIONPROC proc );
  void BookObj_SoftKeys_SetText( BOOK* book, int actionID, TEXTID );
  BOOK* FindBookByID( int BookID );
  GUI_FEEDBACK* TextFeedbackWindow( BOOK* book, int zero );
  void Feedback_SetKeyHook( GUI_FEEDBACK*, void (*hook)( BOOK* book, int key, int unk, int unk2 ) );
  void Feedback_SetOnClose( GUI_FEEDBACK*, void (*OnClose)( BOOK* book ) );
  void Feedback_SetTimeout( GUI_FEEDBACK*, int time_ms );
  void Feedback_SetTextExtended( GUI_FEEDBACK*, TEXTID text, int where );
  void TabMenuBar_SetOnTabSwitch( GUI_TABMENUBAR*, void (*proc)( BOOK*, int act_tab ) );
  TEXTID KeyCode2Name( int key_code );
  int ImageID_Get( const wchar_t* fpath, const wchar_t* fname, IMAGEID* );
  void ImageID_Free( IMAGEID );
  SUB_EXECUTE* DataBrowser_CreateSubExecute( int BookID, FILEITEM* );
  int DataBrowser_ExecuteSubroutine( SUB_EXECUTE* sub, int action, u16* unk );
  int FILEITEM_SetFname( FILEITEM*, const wchar_t* fname );
  int FILEITEM_SetPath( FILEITEM*, const wchar_t* fpath );
  wchar_t* FILEITEM_GetFname( FILEITEM* );
  wchar_t* FILEITEM_GetPath( FILEITEM* );
  int FILEITEM_SetFnameAndContentType( FILEITEM*, const wchar_t* fname );
  int FILEITEM_SetPathAndContentType( FILEITEM*, const wchar_t* fpath );
  int JavaDialog_Open( int unk1, char* unk2, void** JavaDesc );
  void JavaDialog_Close( int unk1 );
  int JavaAppDesc_Get( int unk1, void** JavaDesc );
  int JavaAppDesc_GetFirstApp( void* JavaDesc );
  int JavaAppDesc_GetNextApp( void* JavaDesc );
  int JavaAppDesc_GetJavaAppInfo( void* JavaDesc, int ID, wchar_t** wstr );
  void DispObject_SetRefreshTimer( DISP_OBJ*, int time );
  void DispObject_KillRefreshTimer( DISP_OBJ* );
  int IsDataBrowserBook( BOOK* book );
  SUB_EXECUTE* BrowserItem_Get_SUB_EXECUTE( BOOK* BrowserItemBook );
  TEXTID Shortcut_Get_MenuItemName( void* );
  IMAGEID Shortcut_Get_MenuItemIconID( void* );
  BOOK* FindBookEx( int (*cmp_proc)( BOOK* book_from_list, int* param ), int* param );
  FILEITEM* FILEITEM_CreateCopy( FILEITEM* );
  IMAGEID ImageID_Copy( IMAGEID );
  int BookObj_GetSessionID( BOOK* book );
  void UI_Event_toSID( int event, int sess_id );
  void UI_CONTROLLED_SHUTDOWN_RESPONSE( int book_id );
  void MainInput_Hide( GUI* );
  void DispObject_SoftKeys_RestoreDefaultAction( DISP_OBJ*, int action );
  TEXTID PNUM2Name( BCD_TEXT pnum, int isIconNeeded, int only_full_number_flag );
  int SpeedDial_GetPNUM( int _zero, char charter0__9, BCD_TEXT PNUM );
  int DispObject_GetWindowWidth( DISP_OBJ* );
  int DispObject_GetWindowHeight( DISP_OBJ* );
  int get_system_langID( void );
  char* lang_get_name( int langID );
  int w_chdir( const wchar_t* path );
  int w_fopen( const wchar_t* name, int attr, int rights, int err );
  int w_fstat( const wchar_t* name, W_FSTAT* );
  int w_fwrite( int f, void* buf, int size );
  int w_fread( int f, void* buf, int size );
  int w_lseek( int f, int offs, int mode );
  int w_fclose( int f );
  int w_mkdir( const wchar_t* path, int mode );
  int DirHandle_SetFilterStr( DIR_HANDLE*, const wchar_t* filter );
  int ImageID_GetIndirect( void* buf_image, int size, int __NULL, wchar_t* image_type, IMAGEID* );
  void unixtime2datetime( int, DATETIME* );
  int List_Insert( LIST* lst, int i, void* item );
  int FileCopy( wchar_t* src_path, wchar_t* src_name, wchar_t* dest_path, wchar_t* dest_name, int );
  int FileMove( wchar_t* src_path, wchar_t* src_name, wchar_t* dest_path, wchar_t* dest_name, int );
  void DispObject_SetLayerColor( DISP_OBJ*, int color );
  int JavaAppDesc_GetJavaAppID( void* JavaDesc );
  void REQUEST_UI_OAF_START_APPLICATION( const int* sync, int appID, char* flag );
  int JavaApp_LogoImageID_Get( wchar_t* fullpath, IMAGEID* );
  GUI* CreateProgressBar( BOOK* book, int display );
  void ProgressBar_SetText( GUI*, TEXTID text );
  void ProgressBar_SetIcon( GUI*, IMAGEID );
  void ProgressBar_SetPercentValue( GUI*, int value );
  void ProgressBar_SetBarDisabled( GUI*, BOOL );
  void StringInput_DispObject_SetText( DISP_OBJ*, TEXTID );
  void GUIObject_SetTitleIcon( GUI*, IMAGEID );
  void* DispObject_SoftKeys_GetParams( DISP_OBJ* );
  LIST* DispObject_SoftKeys_GetList( DISP_OBJ*, BOOK* book, char __zero );
  int BookObj_GetDisplayOrientation( BOOK* book );
  void BookObj_SetDisplayOrientation( BOOK* book, int orientation );
  BOOK* Display_GetTopBook( int display );
  int Display_GetBrightness( int display );
  void DataBrowserDesc_Menu_AddFSFunctions( void* DataBrowserDesc, int );
  void DataBrowserDesc_Menu_AddNewFolder( void* DataBrowserDesc, int );
  void DataBrowserDesc_Menu_AddMarkFiles( void* DataBrowserDesc, int );
  void SetTheme( wchar_t* path, wchar_t* name, int bookid, int unk_1 );
  void SoftKeys_GetLabel( DISP_OBJ* softkeys, SKLABEL* lbl, int id );
  void SoftKeys_Update( DISP_OBJ* softkeys );
  void* IncommingCall_Reject( BOOK* book );
  void* IncommingCall_Mute( BOOK* book );
  int Bluetooth_GetState( void );
  int Bluetooth_GetPhoneVisibility( void );
  int Bluetooth_isBusy( void );
  int USB_isConnected( void );
  void* w_diropen( const wchar_t* dir );
  wchar_t* w_dirread( void* );
  int w_dirclose( void* );
  int w_rename( const wchar_t* dst, const wchar_t* src );
  int w_remove( const wchar_t* dir );
  int IsCameraBook( BOOK* bk );
  int IsSoundRecorderBook( BOOK* bk );
  void StringInput_MenuItem_SetPriority( GUI* strinp, int prio, int actionID );
  void Video_ActionBack( BOOK* VideoPlayerBook, void* );
  void Video_ExtractFrame( BOOK* VideoPlayerBook, void* );
  void Video_ZoomOn( BOOK* VideoPlayerBook, void* );
  void RightNow_SetActive( int flag );
  void Video_Play( BOOK* VideoPlayerBook, void* );
  void Video_Pause( BOOK* VideoPlayerBook, void* );
  void Audio_Pause( BOOK* );
  void Audio_Play( BOOK* );
  GUI* CreatePercentInputVA( int zero, ... );
  int PercentInput_GetPercent( GUI* PercentInput );
  void GUIonMessage_SetLineSeparator( GUI_MESSAGE* msg, int _unk1 );
  int PHF_GetState( void );
  int CHF_GetState( void );
  void GUIObject_SoftKeys_RemoveBackground( GUI* );
  void GUIObject_SoftKeys_RestoreBackground( GUI* );
  void SetTrayIcon( IMAGEID, char mode );
  int REQUEST_SETTING_RINGVOLUME_SET( const int* sync, int unk, int null, int vol );
  int REQUEST_SETTING_VIBRATOR_SET( const int* sync, int unk, int mode );
  int REQUEST_SETTING_RINGTYPESOUNDFILE_SET( const int* sync, int null, wchar_t* path, wchar_t* name );
  int REQUEST_SETTING_ANSWERINGMODE_SET( const int* sync, int unk, int mode );
  int REQUEST_SETTING_INCREASINGRING_SET( const int* sync, int unk, int unk2, int mode );
  int REQUEST_SETTING_ALLOWEDCALLERS_SET( const int* sync, int unk, int mode );
  int JavaAppDesc_GetJavaAppFullpath( void* JavaDesc, JavaAppFullpath* );
  void* SoundRecorderDesc_Create( void );
  void SoundRecorderDesc_Destroy( void* desc );
  int SoundRecorderDesc_SetBookID( void* desc, int BookID );
  int SoundRecorderDesc_SetType( void* desc, const int type );
  int SoundRecorderDesc_SetFolder( void* desc, const wchar_t* fpath );
  int SoundRecorderDesc_SetFname( void* desc, const wchar_t* fname );
  int SoundRecorderDesc_SetRecordSize( void* desc, const int size );
  int SoundRecorder_Create( void* desc );
  int SoundRecorder_RecordCall( BOOK* OngoingCallBook );
  
  int SoundRecorderDesc_SetRecordTime( void* sd, ... );
  int SoundRecorderDesc_SetRadioVal( void* desc, int value );
  int SoundRecorderDesc_SetTitle( void* desc, TEXTID Title );
  int SoundRecorderDesc_SetStyle( void* desc, int style );
  
  int Browser_OpenURI( BOOK* book, char* URI, int mode );
  char* GetURIScheme( int schemeID );
  char* CreateURI( wchar_t* fpath, wchar_t* fname, char* URIScheme );
  void DataBrowserDesc_SetViewModeAndSortOrder( void* DataBrowserDesc, int view_sort_ID );
  int Alarm_GetCurrentTypeAndAlarmID( char* type, wchar_t* AlarmID );
  int Alarm_GetState( char* state, int AlarmID );
  int Alarm_GetTIME( TIME* AlarmTime, int AlarmID );
  int Alarm_GetWeekSettings( void* week, int AlarmID );
  void REQUEST_SETTING_ALLOWEDCALLERS_GET( const int* sync, int ProfileNum, char* state );
  void* IncommingCall_Accept( BOOK* book );
  void MediaPlayer_SoftKeys_SetText( GUI* player_gui, int actionID, TEXTID );
  void MediaPlayer_SoftKeys_SetAction( GUI* player_gui, int actionID, SKACTIONPROC proc );
  void MediaPlayer_SoftKeys_SetItemAsSubItem( GUI* player_gui, int item, int subitem );
  void DispObject_Show( DISP_OBJ*, int mode );
  int Request_EventChannel_Subscribe( const int* sync, int mode, int event );
  void GUIObject_SoftKeys_ExecuteAction( GUI*, u16 actionID );
  int Request_ICA_ShutdownAllConnections( const int* sync );
  int REQUEST_PROFILE_GETPROFILENAME( const int* sync, int unk, TEXTID_DATA*, char* error );
  int DataBrowserDesc_SetFocusToFILEITEM( void* DataBrowserDesc, FILEITEM* );
  int GUIonMessage_GetMsg( GUI_MESSAGE* msg );
  BOOK* GUIonMessage_GetBook( GUI_MESSAGE* msg );
  GUI* GUIonMessage_GetGui( GUI_MESSAGE* msg );
  int GUIonMessage_GetSelectedItem( GUI_MESSAGE* msg );
  int GUIonMessage_GetPrevSelectedItem( GUI_MESSAGE* msg );
  void ObexSendFile( SEND_OBEX_STRUCT* );
  void Feedback_SetManualScrollingText( DISP_OBJ* feedback_disp_obj, int state );
  int EqualizerGain_Set( int AudioSessionID, int Band, int Level );
  int CANVAS_Get_GviGC( PCANVAS pcanvas, GVI_GC* dest );
  void GVI_BitBlt( GVI_GC destgc, int destx, int desty, int destxsize, int destysize, GVI_GC srcgc, int srcx, int srcy, int _204, int _0, int _0_2, int _0_3 );
  void GVI_StretchBlt( GVI_GC destgc, int destx, int desty, int destxsize, int destysize, GVI_GC srcgc, int srcx, int srcy, int srcxsize, int srcysize, int _204, int _0, int _0_2, int _0_3 );
  void GVI_TransformBlt( GVI_GC destgc, int destx, int desty, GVI_GC srcgc, int srcx, int srcy, int srcxsize, int srcysize, int orientation, int _0 );
  GVI_PEN GVI_CreatePen( char thikness, int color );
  GVI_PEN GVI_CreateDashedPen( char thikness, int color, int bitmask, int step, int offset );
  GVI_BRUSH GVI_CreateSolidBrush( int color );
  BOOL GVI_Delete_GVI_Object( GVI_OBJ* );
  void GVI_DrawEllipse( GVI_GC gc, int x, int y, int w, int h, GVI_PEN pen );
  void GVI_DrawLine( GVI_GC gc, int x1, int y1, int x2, int y2, GVI_PEN pen );
  void GVI_DrawLines( GVI_GC gc, POINT* points, int count, GVI_PEN pen );
  void GVI_DrawPolyLine( GVI_GC gc, POINT* points, int count, GVI_PEN pen, int is_closed );
  void GVI_DrawRectangle( GVI_GC gc, int x, int y, int w, int h, GVI_PEN pen );
  void GVI_DrawRoundRect( GVI_GC gc, int x, int y, int w, int h, int arcw, int arch, GVI_PEN pen );
  void GVI_DrawSolidLines( GVI_GC gc, POINT* points, int count, int color, int width );
  void GVI_DrawSolidPolyLine( GVI_GC gc, POINT* points, int count, int is_closed, int color, int width );
  void GVI_DrawSolidRectangle( GVI_GC gc, int x, int y, int w, int h, int color, int width );
  void GVI_FillEllipse( GVI_GC gc, int x, int y, int w, int h, GVI_BRUSH brush );
  void GVI_FillPolygon( GVI_GC gc, POINT* pp, int count, GVI_BRUSH brush );
  void GVI_FillRectangle( GVI_GC gc, int x, int y, int w, int h, GVI_BRUSH brush );
  void GVI_FillRectangles( GVI_GC gc, GVI_XYWH* rcs, int count, GVI_BRUSH brush );
  void GVI_FillSolidEllipse( GVI_GC gc, int x, int y, int w, int h, int color );
  void GVI_FillSolidRectangle( GVI_GC gc, int x, int y, int w, int h, int color );
  int GVI_FillSolidRoundRect( GVI_GC gc, int x, int y, int w, int h, int arcx, int arcy, int color );
  void GVI_FillSolidTriangle( GVI_GC gc, int x1, int y1, int x2, int y2, int x3, int y3, int color );
  GC* GC_CreateMemoryGC( int xsize, int ysize, int bpp, int unk, void* somefn, int unk2 );
  void GC_FreeGC( GC* gc );
  int Settings_ShowNumber_Get( char* state );
  GVI_BMP GVI_CreateBitmap( int xsize, int ysize, int bpp );
  GVI_GC GVI_CreateMemoryGC( GVI_BMP bitmap );
  void GVI_DeleteMemoryGC( GVI_GC gc );
  int StringInput_DispObject_SetLanguage( DISP_OBJ_STRING_INPUT*, int langID, int flag );
  int List_InsertSorted( LIST* list, void* item, int (*cmp_proc)( void*, void* ) );
  int ListMenu_SetItemIcon( GUI_LIST*, u16 Item, u16 unk_FFFF, int mode, IMAGEID );
  void wstrnupr( wchar_t* wstr, int maxlen );
  void wstrnlwr( wchar_t* wstr, int maxlen );
  int ListMenu_SetItemTextScroll( GUI_LIST*, int scroll );
  void GUIObject_SetListTextColor( GUI*, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro );
  void DispObject_SetTitleTextColor( DISP_OBJ*, int color );
  void DispObject_SetListTextColor( DISP_OBJ*, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro );
  void DispObject_SetCursorImage( DISP_OBJ*, IMAGEID );
  void DispObject_SetBackgroundImage( DISP_OBJ*, IMAGEID );
  void DispObject_SetTitleBackgroundImage( DISP_OBJ*, IMAGEID );
  void TabMenuBar_SetTabTitle( GUI_TABMENUBAR*, int tab_num, TEXTID );
  BOOK* GUIObject_GetBook( GUI* );
  u16 SoftKeys_GetSelectedAction( void );
  void MonitorFeedback_SetTimer( GUI_FEEDBACK*, int time, void (*callback)( BOOK*) );
  void ListMenu_DestroyItems( GUI_LIST* );
  void DispObject_SetScrollBarBackgroundColor( DISP_OBJ*, int color );
  void DispObject_SetScrollBarColor( DISP_OBJ*, int color );
  void DispObject_SetSoftkeysColor( DISP_OBJ*, int color );
  void YesNoQuestion_SetIcon( GUI*, IMAGEID );
  void GUIObject_SetBacklightTimeout( GUI*, int time );
  void ListMenu_SetHotkeyMode( GUI_LIST*, LISTMENU_HOTKEY_MODE );
  void ListMenu_SetSearchLanguageMode( GUI_LIST*, int mode );
  void ListMenu_EnableSearchHeader( GUI_LIST*, BOOL );
  wchar_t* GUIonMessage_GetSearchString( GUI_MESSAGE* msg );
  int GUIonMessage_GetSearchStringLength( GUI_MESSAGE* msg );
  int EqualizerGain_Get( int AudioSessionID, int Band, int* Level );
  int Theme_DestroyMenuIcons( void );
  void CoCreateInstance( PUUID cid, PUUID iid, void** pInterface );
  void GUIObject_SetSecondRowTitleText( GUI*, TEXTID );
  int ListMenu_GetItemCount( GUI_LIST* );
  void OSE_GetShell( void** pInterface );
  int swscanf( const wchar_t* buffer, const wchar_t* format, ... );
  int sscanf( const char* buffer, const char* format, ... );
  void BookObj_WindowSetWantsFocus( BOOK* book, int display, BOOL WantsFocus );
  void BookObj_StayOnTop( BOOK* book, int mode );
  void DispObject_WindowSetPosition( DISP_OBJ*, int x, int y );
  void DispObject_WindowSetSize( DISP_OBJ*, int w, int h );
  TEXTID Feedback_DispObject_GetText( DISP_OBJ* );
  void DispObject_SoftKeys_ExecuteAction( DISP_OBJ*, u16 actionID );
  LIST* DataBrowserBook_GetCurrentFoldersList( BOOK* DataBrowserBook );
  void DispObject_SetAnimation( DISP_OBJ*, int style );
  void GUIObject_SetZOrder( GUI*, char, GUI* );
  int StringInput_GetCursorPosition( GUI*, u16* pos, char* _zero );
  void str2PNUM( BCD_TEXT pnum, char* str, int len, int max_len );
  void pb_ui_search_bk_create_search_menu( int BookID, int mode );
  void GUIObject_SoftKeys_SubActionPressedNotification( GUI*, u16 actionID, BOOL );
  int fs_demand_cache_page( int virtAddr, int mode, int intrMask );
  int fs_demand_pagePool_alloc_mem( pagePool* pagePool_p, int intrMask );
  wchar_t fs_demand_get_page_i_from_queue( wchar_t* queue, char only_allocked_pool, int page_count );
  void fs_demand_remove_from_queue( pageCache* page_p_to_remove, wchar_t page_i_to_insert );
  int fs_demand_kick_out_page( wchar_t page_i, int intrMask );
  char* getSWAP_DATA_BASE( void );
  
// Library DLL function --------------------------------------------------------
  void DisplayGC_AddRef( GC*, void* );
  void TextObject_SetText( IRichText* pTextObject, TEXTID );
  void TextObject_SetFont( IRichText* pTextObject, void* pFont, const int _0x8000000A, const int _0x7FFFFFF5);
  int Illumination_LedID_SetLevel_Gradually( int LED_ID, int level, int fade_time );
  int Illumination_LedID_SetLevel( int LED_ID, int level );
  int Illumination_LedID_Off( int LED_ID );
  int RichTextLayout_GetTextWidth( TEXTID strid, IRichTextLayout* pRichTextLayout, IUnknown* pFont );
  int REQUEST_HPHONEBOOK_READSTRING( const int* sync, void* buf );
  void AB_STR_ITEM_Copy( AB_STR_ITEM* dest, AB_STR_ITEM* source );
  int Request_SIM_IMSI_Read(const int* sync, const int unk, char* imsi, char* error_cause );
  int get_imsi_const( void );
  int Request_SL_GetRadioState( const int* sync, char* level, char* flag, char* error_cause );
  int Network_INetworkConnection_GetConnectionInfo( CONNECTION_INFO_DESC* desc );
  int GetChipID_int( void );
  OSBOOLEAN get_mem_int( int, int, void* );
  int ConnectionManager_Connection_GetState_int( char* buf );
  
// DynamicMenu function --------------------------------------------------------
  int DynamicMenu_GetElementMsg( DYNAMIC_MENU_ELEMENT* dme );
  wchar_t* DynamicMenu_GetElementId( DYNAMIC_MENU_ELEMENT* );
  void DynamicMenu_SetElement_FirstLineText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_HelpText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_Icon(DYNAMIC_MENU_ELEMENT* dme, int mode, IMAGEID );
  void DynamicMenu_SetElement_UnavailableState( DYNAMIC_MENU_ELEMENT* dme, BOOL state );
  void DynamicMenu_SetElement_UnavailableText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_SecondLineText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_TitleText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  
// SoftKeys function -----------------------------------------------------------  
  void BookObj_SoftKeys_SetItemOnKey( BOOK* book, u16 actionID, int key, int mode );
  void BookObj_SoftKeys_SetKey_SoftAction( BOOK* book, u16 actionID, int key, int mode );
  
  void GUIObject_SoftKeys_AllowKeylock( GUI*, BOOL allow );
  void GUIObject_SoftKeys_SetLongSKButtonText( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_SetIcon( GUI*, u16 actionID, IMAGEID );
  void GUIObject_SoftKeys_MoveItemAfter( GUI*, u16 actionID, u16 after_actionID );
  void GUIObject_SoftKeys_MoveItemBefore( GUI*, u16 actionID, u16 before_actionID );
  void GUIObject_SoftKeys_MoveItemFirst( GUI*, u16 actionID);
  void GUIObject_SoftKeys_SetDisabledAction( GUI*, u16 actionID, int unk );
  void GUIObject_SoftKeys_SetSubItemHighlight( GUI*, u16 actionID, int subitem );
  void GUIObject_SoftKeys_SetItemOnKey( GUI*, u16 actionID, int key, int mode );
  void GUIObject_SoftKeys_RemoveItemFromKey( GUI*, u16 actionID, int key, int mode );
  void GUIObject_SoftKeys_SetActionAndText( GUI* gui, u16 actionID, SKACTIONPROC proc, TEXTID );
  void GUIObject_SoftKeys_SetAction_SetText_SetInfoText_SetVisible( GUI*, u16 actionID, SKACTIONPROC proc, TEXTID name, TEXTID info, BOOL visible );

  void MediaPlayer_SoftKeys_SetVisible( GUI* player_gui, u16 actionID, BOOL );
  void MediaPlayer_SoftKeys_SetInfoText( GUI* player_gui, u16 actionID, TEXTID );
  void MediaPlayer_SoftKeys_SetEnable( GUI* player_gui, u16 actionID, BOOL);
  void MediaPlayer_SoftKeys_AddErrorStr( GUI* player_gui, u16 actionID, TEXTID );
  
  void DispObject_SoftKeys_SetAction( DISP_OBJ*, BOOK*, int __zero, u16 actionID, SKACTIONPROC );
  void DispObject_SoftKeys_SetIcon( DISP_OBJ*, BOOK*, int __zero, u16 actionID, IMAGEID );
  void DispObject_SoftKeys_SetText( DISP_OBJ*, BOOK*, int __zero, u16 actionID, TEXTID );
  void DispObject_SoftKeys_SetLongSKButtonText( DISP_OBJ*, u16 actionID, TEXTID );
  void DispObject_SoftKeys_SetVisible( DISP_OBJ*, BOOK*, int __zero, u16 actionID, BOOL );
  //
  //
  //
  void DispObject_SoftKeys_AddErrorStr( DISP_OBJ*, BOOK*, int __zero, u16 actionID, TEXTID );
  //
  void DispObject_SoftKeys_MoveItemFirst( DISP_OBJ*, BOOK*, int __zero, u16 actionID);
  void DispObject_SoftKeys_MoveItemBefore( DISP_OBJ*, BOOK*, int __zero, u16 actionID, u16 before_actionID );
  void DispObject_SoftKeys_MoveItemAfter( DISP_OBJ*, BOOK*, int __zero, u16 actionID, u16 after_actionID );
  void DispObject_SoftKeys_SetItemAsSubItem( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int subitem );
  void DispObject_SoftKeys_SetSubItemHighlight( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int subitem );
  void DispObject_SoftKeys_SetItemOnKey( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int key, int mode );
  void DispObject_SoftKeys_RemoveItemFromKey( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int key, int mode );
  void DispObject_SoftKeys_RemoveItem( DISP_OBJ*, BOOK*, int __zero, u16 actionnID );
  void DispObject_SoftKeys_SuppressDefaultAction( DISP_OBJ*, u16 actionID );
  void DispObject_SoftKeys_ExecuteAction( DISP_OBJ*, u16 actionID );
  void DispObject_SoftKeys_IgnoreSoftkeyButton( DISP_OBJ*, u16 );
  void DispObject_SoftKeys_AllowKeylock( DISP_OBJ*, BOOL );
  void DispObject_SoftKeys_Hide( DISP_OBJ* );
  void DispObject_SoftKeys_Show( DISP_OBJ* );
  void DispObject_SoftKeys_RemoveBackground( DISP_OBJ* );
  void DispObject_SoftKeys_RestoreBackground( DISP_OBJ* );
  void DispObject_SoftKeys_SubActionPressedNotification( DISP_OBJ*, BOOK*, int __zero, u16 actionID, BOOL );
  void DispObject_SoftKeys_SetDisabledAction( DISP_OBJ*, int unk);
  
// DISP_OBJ function -----------------------------------------------------------
  
  void ListMenu_DispObject_SetCursorToItem( DISP_OBJ*, int item );
  int ListMenu_DispObject_GetSelectedItem( DISP_OBJ* );
  void ListMenu_DispObject_SetItemCount( DISP_OBJ*, int item_count );
  int ListMenu_DispObject_GetItemCount( DISP_OBJ* );
  void ListMenu_DispObject_SetTexts( DISP_OBJ*, const TEXTID* text, int count );
  void ListMenu_DispObject_SetHotkeyMode( DISP_OBJ*, LISTMENU_HOTKEY_MODE );
  void ListMenu_DispObject_SetNoItemText( DISP_OBJ*, TEXTID str );
  int ListMenu_DispObject_SetItemFirstLineText( DISP_OBJ*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_DispObject_SetHelpText( DISP_OBJ*, u16 Item, u16 unk_FFFF, TEXTID );
  int ListMenu_DispObject_SetItemIcon( DISP_OBJ*, u16 Item, u16 unk_FFFF, int mode, IMAGEID );
  void ListMenu_DispObject_SetItemUnavailableState( DISP_OBJ*, u16 Item, u16 unk_FFFF, char state );
  void ListMenu_DispObject_SetItemUnavailableText( DISP_OBJ*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_Disp_Object_SetItemSecondLineText( DISP_OBJ*, int elem_num, TEXTID );
  
  void DispObject_StatusIndication_SetItemText( DISP_OBJ*, int ID, TEXTID );
  
  void DispObject_SetThemeImage( DISP_OBJ*, int theme_image );
  void DispObject_SetAnimationApp( DISP_OBJ*, char* style );
  int DispObject_GetDisplay( DISP_OBJ* );
  void DispObject_SetStyle( DISP_OBJ*, int style );
  int DispObject_GetStyle( DISP_OBJ* );
  
  void DispObject_SetTitleType( DISP_OBJ*, int type );
  int DispObject_GetTitleType( DISP_OBJ* );
  void DispObject_SetTitleIconHasPriority( DISP_OBJ*, BOOL titleIconHasPrio );
  void DispObject_SetTitleAlignment( DISP_OBJ*, UITextAlignment_t titleAlignment );
  int DispObject_GetTitleAlignment( DISP_OBJ* );
  
  void DispObject_Backlight( DISP_OBJ*, int mode ); // 0 - on; 1 - off; 2 - blink; 3 - timeout; 4 - restore;
  void DispObject_BacklightBlinkTime( DISP_OBJ*, int time_on, int time_off );
  void DispObject_BacklightRestore( DISP_OBJ* );
  void DispObject_SetInternalBackground( DISP_OBJ*, IMAGEID );
  
  DISP_OBJ* Get_MediaPlayer_DispObject(DISP_OBJ*);
  int DispObject_GetStatusRowHeight( DISP_OBJ* );
  void DispObject_DateInput_MoveCursor( DISP_OBJ*, int offset );
  void DispObject_DateInput_SetDateFormat( DISP_OBJ*, char format );
  void DispObject_DateInput_SetDate( DISP_OBJ*, DATE* );
  void DispObject_TimeInput_SetTime( DISP_OBJ*, TIME*, char* format );
  void DispObject_TimeInput_SetSecEnable( DISP_OBJ*, int state );
  int DispObject_TimeInput_MoveCursor( DISP_OBJ*, int offset );

// GUI function ----------------------------------------------------------------
  GUI* CreateDateInput( BOOK*, int display );
  void DateInput_SetDateFormat( GUI*, char format );
  void DateInput_SetDate( GUI*, DATE* ) ;
  
  GUI* CreatePercentInput( BOOK*, int display );
  void PercentInput_ExecuteOnKey( GUI* PercentInput, void proc(int _unk_0, char value) );
  void PercentInput_SetCurrentPercent( GUI* PercentInput, TEXTID );
  void PercentInput_SetTitleText( GUI* PercentInput, TEXTID );
  void PercentInput_SetRowNumbers( GUI* PercentInput, int row );
  
  GUI* CreateTimeInput( BOOK*, int display );
  void TimeInput_SetTime( GUI*, TIME*, char* time_format );
  void TimeInput_SetEnableSec( GUI*, BOOL );
  
  GUI_LIST* CreateMultiChoiceMenu( BOOK* );
  void MultiChoiceMenu_SetMessage( GUI_LIST*, int offset, TEXTID );
  void MultiChoiceMenu_SetCursorToItem( GUI_LIST*, int item);
  
  GUI* CreateOnOffList( BOOK* book );
  int OnOffList_GetSelected( GUI* OnOffList );
  void OnOffList_SetChecked( GUI_ONEOFMANY*, int checked );
  void OnOffList_SetFirstText( GUI* OnOffList, TEXTID );
  void OnOffList_SetSecondText( GUI* OnOffList, TEXTID );
  
  void Feedback_SetIcon(GUI_FEEDBACK*, IMAGEID );
  void Feedback_CloseAction(GUI_FEEDBACK*, u16 actionID);
  void Feedback_SetTextAlignment(GUI_FEEDBACK*, UITextAlignment_t uiTextAlignment );
  void Feedback_SetDescriptionImage(GUI_FEEDBACK*, IMAGEID );
  
  void ProgressBar_SetDescriptionIcon( GUI*, IMAGEID );
  void ProgressBar_SetDescriptionIconOffset( GUI*, int offset);
  int ProgressBar_IsScrolling( GUI* );
  
  GUI* CreateYesNoQuestion( BOOK* book, int display );
  void YesNoQuestion_SetQuestionText( GUI*, TEXTID );
  void YesNoQuestion_SetDescriptionText( GUI*, TEXTID );
  void YesNoQuestion_SetDescriptionIconOffset( GUI*, int offset);
  
  void OneOfMany_SetInfoText( GUI_ONEOFMANY*, u16 actionID, u16 unk_FFFF, TEXTID );  
  int NOfMany_GetItemCount( GUI_NOFMANY* );
  void NOfMany_SetItemCount( GUI_NOFMANY*, int count );
  void NOfMany_ItemGetChecked( GUI_NOFMANY*, int item );
  
  GUI* CreateStringInput( BOOK* book );
  void StringInput_SetMode( GUI*, int mode);
  void StringInput_SetActionOK( GUI* strinp, void (*proc)( BOOK* book, wchar_t* string, int len ) );
  void StringInput_SetActionNo( GUI* strinp, void (*proc)( BOOK* book, wchar_t* string, int len ) );
  void StringInput_SetActionCancel( GUI* strinp, void (*proc)( BOOK* book, wchar_t* string, int len ) );
  void StringInput_SetText( GUI* strinp, TEXTID );
  void StringInput_SetFixedText( GUI* strinp, TEXTID );
  void StringInput_SetMinLen( GUI* strinp, int len );
  void StringInput_SetMaxLen( GUI* strinp, int len );
  void StringInput_SetEnableEmptyText( GUI* strinp, BOOL state );
  void StringInput_DispObject_StartSelectedText( DISP_OBJ* strinp_dispobj );
  void StringInput_DispObject_CopySelectedText( DISP_OBJ* strinp_dispobj );
  
  int ListMenu_SetFirstLineText( GUI_LIST*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_SetInfoText( GUI_LIST*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_SetItemUnavailableState( GUI_LIST*, u16 Item, u16 unk_FFFF, char state );
  void ListMenu_SetItemUnavailableText( GUI_LIST*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_SetTexts( GUI_LIST*, TEXTID* textids, int Count);
  void ListMenu_Activate_AddCount( GUI_LIST*, int mode);
  void ListMenu_SetMaxItemCount( GUI_LIST*, int count);
  void ListMenu_ErrorAddCount( GUI_LIST*, TEXTID );
  
  void GUIObject_TabTitleRemove( GUI*, BOOL );
  void GUIObject_SetAnimationApp( GUI*, char* style );
  void GUIObject_RefreshLayout( GUI* );
  int GUIObject_GetDisplay( GUI* );
  int GUIObject_GetStyle( GUI* );
  int GUIObject_GetTitleType( GUI* );
  void GUIObject_SetTitleIconHasPriority( GUI*, BOOL titleIconHasPrio);
  void GUIObject_SetTitleAlignment( GUI*, UITextAlignment_t titleAlignment);
  int GUIObject_GetTitleAlignment( GUI* );
  void GUIObject_BacklightOn( GUI* );
  void GUIObject_BacklightOff( GUI* );
  void GUIObject_BacklightTimeout( GUI* );
  void GUIObject_BacklightBlink( GUI* );
  void GUIObject_BacklightBlinkTime( GUI*, int time_on, int time_off);
  void GUIObject_BacklightRestore( GUI* );
  void GUIObject_SetInternalBackground( GUI*, IMAGEID );
  
  GUI* CreatePalette( BOOK* book, TEXTID title, const unsigned int* color, int num_of_color, char __zero, void (*onCancel)( BOOK*, void* ), void (*onBack)( BOOK*, void* ), void (*onAccept)( BOOK*, color_t color) );

  // BOOK function ---------------------------------------------------------------
  BOOL IsBook_onTop( BOOK* book );
  void* BOOK_SetFocus( UI_APP_SESSION* session, int focus );
  BOOK* GetTopBook( void );
  int IsStandbyTickerBook( BOOK* bk );
  IS_NEEDED_BOOK get_IsStandbyTickerBook( void );
  
  BOOK* DynamicMenu_GetElementBook( DYNAMIC_MENU_ELEMENT* );
  BOOK* DynamicMenu_CreateSetBook( void );
  BOOK* DynamicMenu_CreateXSetBook( int minus_one );

// SUB_EXECUTE function --------------------------------------------------------
  FILEITEM* SUB_EXECUTE_Get_FILEITEM( SUB_EXECUTE* );
  wchar_t* FILEITEM_GetFExtension( FILEITEM* );
  FSTAT* FILEITEM_GetFSTAT( FILEITEM* );
  void* FILEITEM_GetDRMHandle( FILEITEM* );
  char FILEITEM_GetDRM_Flag( FILEITEM* );
  char* FILEITEM_GetContentType( FILEITEM* );
  int FILEITEM_SetContentType( FILEITEM*, char* type );
  int GetFileLocation( wchar_t* fullpath); // 0 - card, 1 - phone
  int GetMemoryStickStatus(void);
  int DataBrowser_ItemDesc_CheckFileToCopyMove( FILEITEM* );
  
  int FSX_IsFileExists( wchar_t* pDir, wchar_t* pFile );
  wchar_t* FSX_MakeFullPath( wchar_t* pDir, wchar_t* pFile );
  void FSX_FreeFullPath( wchar_t* fullpath );
  int FSX_Attribute( const wchar_t* pDir, const wchar_t* pFile, unsigned long* pAttr, int action );
  wchar_t* MakeFullPath( wchar_t* pDir, wchar_t* pFile );
  
// other function --------------------------------------------------------------
  
  void CreateQuickInfo( DISP_OBJ* dispobj, TEXTID, int unk);
  void CreatePasswordInputWindow(int BookID, int mode_0, int password_2, TEXTID title ); // password: 2 - phone
  
  void SaveBrightness( int brightness_level );
  void Generic_DRM_Info( wchar_t* path, wchar_t* name, int BookID );
  
  int Image_SetWallpaper(const wchar_t* path, const wchar_t* fname );
  
  int SETTING_RINGTYPESOUNDFILE_SET( const int* sync, int minus_one, char zero, wchar_t* path, wchar_t* name, char* error );
  int Sound_Check(wchar_t* fname);
  int Sound_SetRingsignal( wchar_t* fpath, wchar_t* fname );
  int Sound_SetMessageAlert( wchar_t* fpath, wchar_t* fname );
  void Sound_SetAlarmsignal( BOOK* book, int one, wchar_t* fpath, wchar_t* fname );
  void Sound_AddToContact( int BookID, wchar_t* fpath, int len_path, wchar_t* fname, int len_name, int zero ); 
  
  wchar_t* MetaData_GetTags( wchar_t* path, wchar_t* name, int tagID );
  IMAGEID MetaData_GetCover( wchar_t* filename );
  
  int MusicApp_GetFocusedItem( BOOK* MusicBook, int itemIndex, int length,                                  wchar_t* pArtist, wchar_t* pAlbum, wchar_t* pTitle,                                    wchar_t* pFilename,                                      void* pPlaylength, void* pResumePosition,                                        bool* pContainsAlbumart, bool* pIsRealMediaFile );




  int MusicApp_GetItem( BOOK* MusicBook, int itemIndex, int length, wchar_t* pArtist, wchar_t* pAlbum, wchar_t* pTitle );
  int MusicApp_GetFilename( BOOK* MusicBook, int itemIndex, int length, wchar_t* pFilename );
  int MusicApp_Resume( BOOK* MusicBook );
  int MusicApp_Play( BOOK* MusicBook );
  int MusicApp_Pause( BOOK* MusicBook );
  int MusicApp_FastFoward( BOOK* MusicBook );
  int MusicApp_Rewind( BOOK* MusicBook );
  int MusicServer_Next( BOOK* MusicBook, bool activePress );
  int MusicApp_Previous( BOOK* MusicBook );
  int MusicServer_RemoveFromPlaylist( BOOK* MusicBook, int itemIndex );
  int MusicServer_SavePlayQueue( BOOK* MusicBook, wchar_t* pPlaylistName );
  int MusicApp_SetApplicationWindowMode( BOOK* MusicBook, bool maximized );

  void Volume_Set( int TAudioControl_VolumeType, char volume );
  int Volume_Get( int TAudioControl_VolumeType, char* volume ); // GetAudioSettings
  
  void MessageBox_Animation( TEXTID header_text, TEXTID message_text, IMAGEID, int style, int time, BOOK* book, char* animation );
  void MessageBox_NoImage( TEXTID header_text, TEXTID message_text, int style, int time, BOOK* book );
  
  //int Get_MediaPlayer_State( DISP_OBJ* );
  void PlaySystemSound_SendEvent(int sound, int event); 
  TEXTID TextID_CreateFromASCII( int );
  
  void Shutdown( void );
  void Reboot( void );
  void Keylock_Activate( void );
  BOOL Charging_GetState( void );
  int NewEvent_GetCount( void ); //GetNewEvent(void);
  
  BOOL FlightMode_GetState( void );
  void FlightMode_SetState( BOOL state );
  void Bluetooth_SetState( BOOL state );
  void SetOperatorName( TEXTID, int _null );
  TEXTID GetOperatorName( wchar_t* opname  );
  
  void MSG_Marked_No( BOOK* book); //Защита от удаления сообщений, v. 3
  void Create_BrowserMemory( int BookID, int unk, int mode ); // Отображение свободной памяти в заголовках вкладок Диспетчера файлов, v. 4
  void DataDownloadBook_onClose( BOOK* book ); // Добавить вопрос о замене файла после приема через Bluetooth
 
// LIST function ---------------------------------------------------------------
  void List_Init( LIST* list );
  void List_Erase( LIST* list );
  int List_InsertLast( LIST* lst, void* item );
  int List_InsertBefore( LIST* list, void* pElem, int itemno );
  int List_InsertAfter( LIST* list, void* pElem, int itemno );
  void* List_RemoveFirst( LIST* lst );
  void* List_RemoveLast( LIST* lst );
  int List_GetCount( LIST* );
  void* List_GetFirst( LIST* list );
  void* List_GetLast( LIST* list );
  void* List_FindNext( LIST* list, void* pElem );
  void* List_FindPrev( LIST* list, void* pElem );
  int List_Last( LIST* list );
  int List_Next( LIST* list, int itemno );
  
  // Registry function ----------------------------------------------------
  void Registry_Write( char* name, int type, int size, void* data );
  void Registry_Read( char* name, int type, int size, void* data );
};
#line 3 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"

#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\main.h"










enum Modes
{
  EDITING_MODE = 1,
  ADDING_MODE = 2
};



//#define F_READ 0x001
//#define F_RIGHTS 0x180
//#define F_WRITE 0x204

enum Types
{
  TYPE_SHORTCUT,
  TYPE_JAVA,
  TYPE_ELF,
  TYPE_EVENT,
  TYPE_FOLDER,
  TYPE_LAST
};

enum STYPES 
{ 
  IS_BACK,
  IS_FOLDER,
  IS_FILE
};

enum SELF 
{
  SFOLDER,
  SFILE
};

typedef struct
{
  wchar_t* Name;
  wchar_t* Fullpath;
  IMAGEID ImageID;
}JAVA_LIST_ELEM;




typedef struct
{
  char Type_f;
  wchar_t sData_f[0x1D];
  wchar_t Caption_f[0x1F]; 
  int Icon_f;
}SHORTCUT_FILE;

typedef struct
{
    char Type;
    wchar_t* sData;
    wchar_t* Caption; 
    IMAGEID Icon;
}SHORTCUT;

typedef struct GotoShortcut_Book : BOOK
{
  GUI_LIST* MainMenu;
  GUI_LIST* Editor;
  GUI_LIST* JavaMenu;
  GUI_LIST* TypesList;
  GUI* CaptionInput;
  GUI* YesNoQuestion;
  GUI* EventInput;
  
  GUI* FolderInput;
  GUI_LIST* SelectFolder;
  
  LIST* Items;
  LIST* JavaList; 
  
  char CurrentPos;
  char FType;
  
  SHORTCUT* Current;
  //IMAGEID item_icn[2];
} GotoShortcut_Book;

int IsMyBook(BOOK* bk);
int UpdateMainPage(void* r0, BOOK* bk);
void ShortcutFree(void *Item);

__thumb void* malloc (int size);
__thumb void mfree (void * mem);

#line 5 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.h"



int CreateCaptionInput(void* data, BOOK* book);
int CloseCaptionInput(void* data, BOOK* book);
int CreateTypesList(void* data, BOOK* book);
int CloseTypesList(void* data, BOOK* book);
    
const IMAGEID TypesIcons[TYPE_LAST] =
{
  0xF37A,
  0xF875,
  0xF379,
  0xF8A6,
  0xF377
};

const IMAGEID EditorIcons[2] = 
{
  0xEBE6,
  0xEB25
};











void EditorRun( BOOK* book, int mode );
int pg_SC_Editor_Main_AcceptAction( void* data, BOOK* book );




#line 6 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\utils.h"



void RunShortcut(SHORTCUT *Shortcut);
void *SHORTCUT_DESC_Init(wchar_t *param);
void *SHORTCUT_DESC_A2_Init(wchar_t *param);
void FreeList(LIST* &List, void (*FreeProc)(void *Item));
void JavaFree(void* item);
LIST* Create_JavaList();
void SaveConfig(LIST *List);
LIST *LoadConfig();

#line 7 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\strlib.h"



int StringLength(wchar_t *Str);
void StringFree(wchar_t *Str);
wchar_t *StringAlloc(int Length);
void StringAllocEx(wchar_t **Str, int Size);
void StringReallocEx(wchar_t *Src, wchar_t **Dest, int Size);
void StringRealloc(wchar_t *Src, wchar_t **Dest);
void StringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name);
void StringExtractFileName(wchar_t *Str, wchar_t **Name);

int wstr2h(wchar_t * ws, int len);

#line 8 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"
#line 1 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\FileFolder.h"





const wchar_t back[] = L"..";

typedef struct
{
  void* next;
  int is_folder;
  wchar_t* fullname;
  wchar_t* name;
}FLIST;

typedef struct 
{
  FLIST* fltop;
} F_DATA;




GUI_LIST* CreateFileFolderSelect( BOOK* book, wchar_t* str );
int isdir( wchar_t* name );

#line 9 "E:\\SE\\Port\\elf2vkp\\Goto_Shortcut_New\\editor.c"

void Action_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(book, 0);    
}

void AcceptShortcut(BOOK* book)
{
  BookObj_ReturnPage(book, 0);
  BookObj_ReturnPage(book, 0x2);
}

void Menu_SetMainMenu( BOOK* MainMenu, GUI* gui )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)FindBook(IsMyBook);
  
  wchar_t* Data = L"MainMenu";
  StringRealloc(Data, &mbk->Current->sData);
  StringFree(Data);
  mbk->Current->Type = TYPE_SHORTCUT;
  
  void* ShortcutDesc;



  ShortcutDesc = SHORTCUT_DESC_A2_Init(mbk->Current->sData);

  mbk->Current->Icon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
  
  if (!mbk->Current->Caption)
  {
    wchar_t Text[20] = L"MainMenu";
    mbk->Current->Caption = StringAlloc(StringLength(Text));
    wstrcpy(mbk->Current->Caption, Text);
  }
  mfree(ShortcutDesc);
  FreeBook(MainMenu);
  AcceptShortcut(mbk);
}

void Menu_SetShortcut(BOOK* MainMenu, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)FindBook(IsMyBook);
  wchar_t* Data = MenuBook_Desktop_GetSelectedItemID(MainMenu);
  StringRealloc(Data, &mbk->Current->sData);
  StringFree(Data);
  
  mbk->Current->Type = TYPE_SHORTCUT;
  
  void* ShortcutDesc;



  ShortcutDesc = SHORTCUT_DESC_A2_Init(mbk->Current->sData);

  
  mbk->Current->Icon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
  if (!mbk->Current->Caption)
  {
    wchar_t text[64];
    TextID_GetWString(Shortcut_Get_MenuItemName(ShortcutDesc), text, (sizeof(text)/sizeof(text[0])));
    mbk->Current->Caption = StringAlloc(StringLength(text));
    wstrcpy(mbk->Current->Caption, text);
  }
  mfree(ShortcutDesc);
  FreeBook(MainMenu);
  AcceptShortcut(mbk);
}

int Cancel_MainMenu_DB(void* data, BOOK* book)
{
  BookObj_ReturnPage(book, 0);
  return(1);
}

int CreateMainMenu(void* data, BOOK* book)
{
  BOOK* MainMenu = MenuBook_Desktop(1, BookObj_GetBookID(book));
  if (MainMenu)
  {
    BookObj_SoftKeys_SetAction(MainMenu, 0x0, Menu_SetShortcut);
    BookObj_SoftKeys_SetText(MainMenu, 0x0, 0x22BA);
    
    BookObj_SoftKeys_SetAction(MainMenu, 0x1, Menu_SetMainMenu);
    BookObj_SoftKeys_SetText(MainMenu, 0x1, 0x22B9);

    return 1;
  }
  return 0;
}

const PAGE_MSG Goto_Editor_MainMenu_PageEvents[] = 
{
  0xE, CreateMainMenu,
  0x3,   Cancel_MainMenu_DB,
  0x4,     Cancel_MainMenu_DB,
  0,        0
};
const PAGE_DESC Goto_Editor_MainMenu_PageDesc = {"SC_Editor_SelectShortcut_Page", 0, Goto_Editor_MainMenu_PageEvents};

//------------------------------------------------------------------------------

int JavaMenu_Callback(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    GotoShortcut_Book* mbk = (GotoShortcut_Book*)GUIonMessage_GetBook(msg);
    JAVA_LIST_ELEM* elem = (JAVA_LIST_ELEM*)List_Get(mbk->JavaList, GUIonMessage_GetCreatedItemIndex(msg));
    GUIonMessage_SetMenuItemText(msg, TextID_Create(elem->Name, ENC_UCS2, 0xFF));
    GUIonMessage_SetMenuItemIcon(msg, 0, elem->ImageID);
  }
  return 1;
}

void JavaMenu_Ok(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  JAVA_LIST_ELEM* Elem = (JAVA_LIST_ELEM*)List_Get(mbk->JavaList, ListMenu_GetSelectedItem(mbk->JavaMenu));
  
  StringRealloc(Elem->Name, &mbk->Current->sData);
  mbk->Current->Icon = 0xF875;
  mbk->Current->Type = TYPE_JAVA;
  
  if (!mbk->Current->Caption)
    StringRealloc(Elem->Name, &mbk->Current->Caption);
  
  AcceptShortcut(mbk);
}

/*
void JavaMenu_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(mbk, NIL_EVENT);
}
*/

int CreateJavaList(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;   
  if (mbk->JavaMenu) { GUIObject_Destroy(mbk->JavaMenu); mbk->JavaMenu = 0; };
  
  mbk->JavaList = Create_JavaList();
  mbk->JavaMenu = CreateListMenu(mbk, UIDisplay_Main);
  
  GUIObject_SetTitleText(mbk->JavaMenu, 0x69C);
  ListMenu_SetItemCount(mbk->JavaMenu, List_GetCount(mbk->JavaList));
  ListMenu_SetOnMessage(mbk->JavaMenu, JavaMenu_Callback);
  ListMenu_SetCursorToItem(mbk->JavaMenu, 0);
  GUIObject_SoftKeys_SetAction(mbk->JavaMenu, 0xFC0, Action_Back);
  GUIObject_SoftKeys_SetAction(mbk->JavaMenu, 0xFC2, JavaMenu_Ok);
  GUIObject_Show(mbk->JavaMenu);
  return 0;
}

int CloseJavaList(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  FreeList(mbk->JavaList, JavaFree); if (mbk->JavaMenu) { GUIObject_Destroy(mbk->JavaMenu); mbk->JavaMenu = 0; };;
  return 0;
}

const PAGE_MSG Goto_Editor_JavaList_PageEvents[] = 
{
  0xE,   CreateJavaList,
  0xF,    CloseJavaList,
  0, 0
};
const PAGE_DESC Goto_Editor_JavaList_PageDesc = {"SC_Editor_SetJava_Page", 0, Goto_Editor_JavaList_PageEvents};

//------------------------------------------------------------------------------

int Select_DB(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)FindBook(IsMyBook);
  FILEITEM* file_item = (FILEITEM*)data;
  
  mbk->Current->sData = FSX_MakeFullPath(FILEITEM_GetPath(file_item), FILEITEM_GetFname(file_item)); 
  mbk->Current->Icon = TypesIcons[TYPE_ELF];
  mbk->Current->Type = TYPE_ELF;

  if(!mbk->Current->Caption)
    StringRealloc(FILEITEM_GetFname(file_item), &mbk->Current->Caption);

  AcceptShortcut(mbk);
  return 0;
}

int DB_Filter(const wchar_t *ExtTable, const wchar_t* fpath, const wchar_t* fname)
{
  FSTAT fs;
  if (DataBrowser_isFileInListExt(ExtTable, fpath, fname))
    return 1;
  
  fstat(fpath, fname, &fs);
  return 0 != (fs.st_mode&0x00010000);
}

int CreateDataBrowser(void* data, BOOK* book)
{
  void* DB_Desc = DataBrowserDesc_Create();
  const wchar_t *Folders[3];
  Folders[0] = L"/usb/other/ZBin";
  Folders[1] = L"/card/other/ZBin";
  Folders[2] = 0;
  DataBrowserDesc_SetHeaderText(DB_Desc, TextID_Create(L"ELFs", ENC_UCS2, 0xFF));  
  DataBrowserDesc_SetBookID(DB_Desc, BookObj_GetBookID(book));
  DataBrowserDesc_SetFolders(DB_Desc, Folders);
  DataBrowserDesc_SetFileExtList(DB_Desc, L"*.elf");
  DataBrowserDesc_SetItemFilter(DB_Desc, DB_Filter);
  DataBrowserDesc_SetFoldersNumber(DB_Desc, 2);
  DataBrowserDesc_SetSelectAction(DB_Desc, 1);
  DataBrowser_Create(DB_Desc);
  DataBrowserDesc_Destroy(DB_Desc);
  return 0;
}

const PAGE_MSG Goto_Editor_DataBrowser_PageEvents[] = 
{
  0xE, CreateDataBrowser,
  0x2,     Select_DB,
  0x3,   Cancel_MainMenu_DB,
  0x4,     Cancel_MainMenu_DB,
  0,        0
};
const PAGE_DESC Goto_Editor_DataBrowser_PageDesc = {"SC_Editor_SelectElf_Page", 0, Goto_Editor_DataBrowser_PageEvents};

//------------------------------------------------------------------------------

void OnOkEventInput(BOOK* book, wchar_t *string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;

  if (len > 0)
  {
    StringRealloc(string, &mbk->Current->sData);
    mbk->Current->Icon = TypesIcons[TYPE_EVENT];
    mbk->Current->Type = TYPE_EVENT;
    
    int event = wstr2h(string,len);
    
    //wchar_t *EventName = StringAlloc(len); 
    //str2wstr(EventName,UIEventName(event));
    
    if(!mbk->Current->Caption)
      StringRealloc(string, &mbk->Current->Caption);
    
    //StringFree(EventName);
  }
  AcceptShortcut(mbk);
}

void OnBackEventInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->EventInput) { GUIObject_Destroy(mbk->EventInput); mbk->EventInput = 0; };
  BookObj_ReturnPage(mbk, 0);
}

int pg_SC_Editor_EventInput_EnterAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->EventInput) { GUIObject_Destroy(mbk->EventInput); mbk->EventInput = 0; };

  mbk->EventInput = CreateStringInput( mbk );
  StringInput_SetMode( mbk->EventInput, IT_ABC_AND_DIGIT);
  StringInput_SetEnableEmptyText( mbk->EventInput, 1 );
  
  if(mbk->Current->sData && (mbk->Current->Type == TYPE_EVENT))
    StringInput_SetText( mbk->EventInput, TextID_Create(mbk->Current->sData, ENC_UCS2, 0xFF) );

  StringInput_SetMinLen( mbk->EventInput, 1 );
  StringInput_SetMaxLen( mbk->EventInput, 4 );  
  StringInput_SetActionOK( mbk->EventInput, OnOkEventInput );
  StringInput_SetActionNo( mbk->EventInput, OnBackEventInput );
  
  GUIObject_SetTitleText(mbk->EventInput, 0x1BA5 );
  GUIObject_Show(mbk->EventInput);
  return 0;
}

int pg_SC_Editor_EventInput_ExitAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->EventInput) { GUIObject_Destroy(mbk->EventInput); mbk->EventInput = 0; };
  return 0;
}

const PAGE_MSG Goto_Editor_EventInput_PageEvents[] = 
{
  0xE, pg_SC_Editor_EventInput_EnterAction,
  0xF,  pg_SC_Editor_EventInput_ExitAction,
  0,        0
};
const PAGE_DESC Goto_Editor_EventInput_PageDesc = {"SC_Editor_EventInput_Page", 0, Goto_Editor_EventInput_PageEvents};

//------------------------------------------------------------------------------

void SelFolder_Enter( BOOK* book, GUI* gui )
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  mbk->FType = SFOLDER;
  wchar_t* str;
  u16 len;
  StringInput_GetStringAndLen( mbk->FolderInput, &str, &len );
  mbk->SelectFolder = CreateFileFolderSelect( mbk, str );
}

void OnBackFolderInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->FolderInput) { GUIObject_Destroy(mbk->FolderInput); mbk->FolderInput = 0; };
  BookObj_ReturnPage(mbk, 0);
}

void OnOkFolderInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  
  if (len > 0)
  {
    StringRealloc(string, &mbk->Current->sData);
    mbk->Current->Icon = TypesIcons[TYPE_FOLDER];
    mbk->Current->Type = TYPE_FOLDER;
    
    if(!mbk->Current->Caption)
      StringExtractFileName(string, &mbk->Current->Caption);
  }
  AcceptShortcut(mbk);
}

int pg_SC_Editor_SelectFolder_EnterAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->FolderInput) { GUIObject_Destroy(mbk->FolderInput); mbk->FolderInput = 0; };
  
  mbk->FolderInput =  CreateStringInput( mbk );
  StringInput_SetMode( mbk->FolderInput, IT_STRING);
  StringInput_SetEnableEmptyText( mbk->FolderInput, 0 );
  
  if(mbk->Current->sData && (mbk->Current->Type == TYPE_FOLDER))
    StringInput_SetText( mbk->FolderInput, TextID_Create(mbk->Current->sData, ENC_UCS2, 0xFF) );
  
  //StringInput_SetMinLen( mbk->FolderInput, 1 );
  StringInput_SetMaxLen( mbk->FolderInput, 255 );  
  StringInput_SetActionOK( mbk->FolderInput, OnOkFolderInput );
  StringInput_SetActionNo( mbk->FolderInput, OnBackFolderInput );
  
  GUIObject_SoftKeys_SetActionAndText( mbk->FolderInput, 0, SelFolder_Enter, 0x1820 );
  StringInput_MenuItem_SetPriority( mbk->FolderInput, 0, 0 );
  
  GUIObject_Show(mbk->FolderInput);
  return 0;
}

int pg_SC_Editor_SelectFolder_ExitAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->SelectFolder) { GUIObject_Destroy(mbk->SelectFolder); mbk->SelectFolder = 0; };
  return 0;
}

const PAGE_MSG Goto_Editor_SelectFolder_PageEvents[] = 
{
  0xE, pg_SC_Editor_SelectFolder_EnterAction,
  0xF,  pg_SC_Editor_SelectFolder_ExitAction,
  0,        0
};
const PAGE_DESC Goto_Editor_SelectFolder_PageDesc = {"SC_Editor_SelectFolder_Page", 0, Goto_Editor_SelectFolder_PageEvents};

//------------------------------------------------------------------------------

TEXTID Get_SCTypes_Text(int item)
{
  const wchar_t* TypesCaptions[TYPE_LAST] =
  {
    L"Shortcut",
    L"Java",
    L"Elf",
    L"Event",
    L"Folder"
  };
  return TextID_Create(TypesCaptions[item], ENC_UCS2, 0xFF);
}

void TypesList_onSelect(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  switch(ListMenu_GetSelectedItem(mbk->TypesList))
  {
  case TYPE_SHORTCUT:            
    BookObj_CallPage(mbk, &Goto_Editor_MainMenu_PageDesc);
    break;
  case TYPE_JAVA:
    BookObj_CallPage(mbk, &Goto_Editor_JavaList_PageDesc);
    break;
  case TYPE_ELF:
    BookObj_CallPage(mbk, &Goto_Editor_DataBrowser_PageDesc);
    break;
  case TYPE_EVENT:
    BookObj_CallPage(mbk, &Goto_Editor_EventInput_PageDesc);
    break;
  case TYPE_FOLDER:
    BookObj_CallPage(mbk, &Goto_Editor_SelectFolder_PageDesc);
    break;
  }
}

int TypesList_onMessage(GUI_MESSAGE* msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    int index = GUIonMessage_GetCreatedItemIndex(msg);    
    GUIonMessage_SetMenuItemText(msg, Get_SCTypes_Text(index));
    GUIonMessage_SetMenuItemIcon(msg, 0, TypesIcons[index]);
    break;
  }
  return 1;
}
/*
void Types_Back(BOOK* book, GUI* gui)
{
  BookObj_ReturnPage(book, NIL_EVENT);    
}
*/

int pg_SC_Editor_TypesList_EnterAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  mbk->TypesList = CreateListMenu(mbk, UIDisplay_Main);
  GUIObject_SetTitleText(mbk->TypesList, 0x2B21);
  ListMenu_SetItemCount(mbk->TypesList, TYPE_LAST);
  ListMenu_SetCursorToItem(mbk->TypesList, 0);
  ListMenu_SetOnMessage(mbk->TypesList, TypesList_onMessage); 
  GUIObject_SoftKeys_SetAction(mbk->TypesList, 0xFC2, TypesList_onSelect);
  GUIObject_SoftKeys_SetAction(mbk->TypesList, 0xFC0, Action_Back);
  GUIObject_Show(mbk->TypesList);
  return 1;
}

int pg_SC_Editor_TypesList_ExitAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->TypesList) { GUIObject_Destroy(mbk->TypesList); mbk->TypesList = 0; };
  return 0;
}

const PAGE_MSG Goto_Editor_TypesList_PageEvents[] = 
{
  0xE, pg_SC_Editor_TypesList_EnterAction,
  0xF,  pg_SC_Editor_TypesList_ExitAction,
  0,        0
};
const PAGE_DESC Goto_Editor_TypesList_PageDesc = {"SC_Editor_TypesList_Page", 0, Goto_Editor_TypesList_PageEvents};

//------------------------------------------------------------------------------

void OnOkCaptionInput(BOOK* book, wchar_t* string, int len)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;

  if (len > 0) StringReallocEx(string, &mbk->Current->Caption, len);
    
  BookObj_ReturnPage(mbk, 0x2);
}
/*
void OnBackCaptionInput(BOOK* book, wchar_t* string, int len)
{
  BookObj_ReturnPage(book, NIL_EVENT);
}
*/   
int pg_SC_Editor_LabelInput_EnterAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->CaptionInput) { GUIObject_Destroy(mbk->CaptionInput); mbk->CaptionInput = 0; };

  mbk->CaptionInput = CreateStringInput( mbk );
  StringInput_SetMode( mbk->CaptionInput, IT_STRING);
  StringInput_SetEnableEmptyText( mbk->CaptionInput, 1 );
  StringInput_SetText( mbk->CaptionInput, TextID_Create(mbk->Current->Caption, ENC_UCS2, 0xFF) );
  StringInput_SetMinLen( mbk->CaptionInput, 1 );
  StringInput_SetMaxLen( mbk->CaptionInput, 63 );  
  StringInput_SetActionOK( mbk->CaptionInput, OnOkCaptionInput );
  //StringInput_SetActionNo( mbk->CaptionInput, OnBackCaptionInput );
  GUIObject_SoftKeys_SetAction(mbk->CaptionInput, 0xFC0, Action_Back);
  GUIObject_Show(mbk->CaptionInput);
  return 0;
}

int pg_SC_Editor_LabelInput_ExitAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->CaptionInput) { GUIObject_Destroy(mbk->CaptionInput); mbk->CaptionInput = 0; };
  return 0;
}

const PAGE_MSG Goto_Editor_CaptionInput_PageEvents[] = 
{
  0xE, pg_SC_Editor_LabelInput_EnterAction,
  0xF,  pg_SC_Editor_LabelInput_ExitAction,
  0,        0
};
const PAGE_DESC Goto_Editor_CaptionInput_PageDesc = {"SC_Editor_LabelInput_Page", 0, Goto_Editor_CaptionInput_PageEvents};


//------------------------------------------------------------------------------

void Editor_onSelect(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  switch(ListMenu_GetSelectedItem(mbk->Editor))
  {
  case 0:
    BookObj_CallPage(mbk, &Goto_Editor_CaptionInput_PageDesc);
    break;
  case 1:
    BookObj_CallPage(mbk, &Goto_Editor_TypesList_PageDesc);
    break;
  }
}

void Editor_onBack(BOOK* book, GUI* gui)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if(!mbk->Current->sData || !mbk->Current->Caption)
  {
    void* Item = List_RemoveFirst(mbk->Items);
    ShortcutFree(Item);
    //UpdateMainPage(NULL, mbk);
  }
  BookObj_ReturnPage(book, 0x2);
}

int Editor_onMessage(GUI_MESSAGE *msg)
{
  switch(GUIonMessage_GetMsg(msg))
  {
  case LISTMSG_GetItem:
    GotoShortcut_Book* mbk = (GotoShortcut_Book*)GUIonMessage_GetBook(msg);
    int index = GUIonMessage_GetCreatedItemIndex(msg); 
    GUIonMessage_SetMenuItemIcon(msg, 0, EditorIcons[index]);
    if (index == 0)
    {
      GUIonMessage_SetMenuItemText(msg, 0x1EC8);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->Current->Caption, ENC_UCS2, 0xFF));
    }
    if (index == 1)
    {
      GUIonMessage_SetMenuItemText(msg, 0x22AD);
      GUIonMessage_SetMenuItemSecondLineText(msg, TextID_Create(mbk->Current->sData, ENC_UCS2, 0xFF)); 
    }
  }
  return 1;
}
int pg_SC_Editor_Main_EnterAction(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mbk->Editor) { GUIObject_Destroy(mbk->Editor); mbk->Editor = 0; };
  mbk->Editor = CreateListMenu(mbk, UIDisplay_Main);
  GUIObject_SetTitleText(mbk->Editor, 0x22AE);
  ListMenu_SetItemCount(mbk->Editor, 2);
  ListMenu_SetCursorToItem(mbk->Editor, 0);
  ListMenu_SetItemStyle(mbk->Editor, 3);
  ListMenu_SetOnMessage(mbk->Editor, Editor_onMessage); 
  GUIObject_SoftKeys_SetAction(mbk->Editor, 0xFC2, Editor_onSelect);
  GUIObject_SoftKeys_SetAction(mbk->Editor, 0xFC0, Editor_onBack);
  GUIObject_Show(mbk->Editor);
  return 1;
}

int CloseEditorMenu(void* data, BOOK* book)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  mbk->CurrentPos = ListMenu_GetSelectedItem(mbk->MainMenu);
  if (mbk->Editor) { GUIObject_Destroy(mbk->Editor); mbk->Editor = 0; };
  return 1;
}

const PAGE_MSG Goto_Editor_Main_PageEvents[] = 
{
  0xE, pg_SC_Editor_Main_EnterAction,
  0x2,     pg_SC_Editor_Main_AcceptAction,
  0xF,  CloseEditorMenu,
  0,        0
};
const PAGE_DESC Goto_Editor_Main_PageDesc = {"SC_Editor_Main_Page", 0, Goto_Editor_Main_PageEvents};

int pg_SC_Editor_Main_AcceptAction(void* data, BOOK* book)
{
  BookObj_GotoPage(book, &Goto_Editor_Main_PageDesc);
  return 0;
}

void EditorRun(BOOK* book, int mode)
{
  GotoShortcut_Book* mbk = (GotoShortcut_Book*)book;
  if (mode == ADDING_MODE)
  {
    SHORTCUT* Shortcut = (SHORTCUT *)malloc(sizeof(SHORTCUT));
    memset(Shortcut, 0, sizeof(SHORTCUT));
    List_InsertFirst(mbk->Items, Shortcut);
    mbk->Current = (SHORTCUT*)List_Get(mbk->Items, 0);
  }
  else mbk->Current = (SHORTCUT*) List_Get(mbk->Items, ListMenu_GetSelectedItem(mbk->MainMenu));
  
  BookObj_CallPage(mbk, &Goto_Editor_Main_PageDesc);
}
