#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"
#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Target\\G502_R1FA037.h"











#line 18 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Target\\G502_R1FA037.h"

#line 25 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Target\\G502_R1FA037.h"







#line 49 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Target\\G502_R1FA037.h"


// Menu





  
// Editing













#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"
/*"Patch in C++" template by UltraShot*/

/*
;Change Right Softkey in Standby to "GoTo Shortcut".
;Items: Inbox, Music player, Alarms, Calendar, Profiles, Bluetooth
;Added Music State(Title - Artist) at 2ndLine of Music player item
;Added Alarm State(ALarmType : Hour.Minutes) at 2ndLine of Alarm item
;Added Date state(Weekday,Date-Mon-Year) at 2ndLine of Calendar item
;Added Active Profile at 2ndLine of Profiles item(new algoritm)
;Added Bluetooth state(On-Off) at 2ndLine of Bluetooth item
;Improved code
;v 2
;(c) farid
;(r) mobilefree.ru
*/

#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Types.h"



// base types and constants ----------------------------------------------------

typedef enum
{
  	UITextAlignment_Left = 0,
  	UITextAlignment_Right,
  	UITextAlignment_Center,
  	UITextAlignment_LeftDynamic,
  	UITextAlignment_RightDynamic
}UITextAlignment_t;

typedef struct
{
	char dummy[0x40];
}DYNAMIC_MENU_ELEMENT;

enum DYNAMIC_MENU_ELEMENT_MSG
{
	DYNAMIC_MENU_onCall = 0,
	DYNAMIC_MENU_onText,
	DYNAMIC_MENU_onState,
};

enum INPUT_TYPES 
{
	IT_REAL 	  = 0,
	IT_STRING 	  = 1,
        IT_INTEGER 	  = 2,
        IT_PHONE_NUMBER   = 3,
        IT_DIGITAL_PASS   = 4,
        IT_DIGITAL_IP 	  = 5,
        IT_URL 		  = 6,
        IT_UNSIGNED_DIGIT = 9,
        IT_EXTRA_DIGIT 	  = 0xA,
        IT_ABC_OR_DIGIT   = 0xB,
        IT_EXTRA_DIGIT_2  = 0xC,
        IT_ABC_OR_DIGIT_2 = 0xD,
};

typedef unsigned short u16;
typedef int BOOL;
typedef unsigned long LRESULT;
typedef int jmp_buf[11];
typedef unsigned int size_t;
typedef unsigned int time_t;








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
	char unk;
}TIME;

typedef struct DATETIME
{
	DATE date;
	TIME time;
}DATETIME;

typedef struct POINT
{
	int x;
	int y;
}POINT;

typedef struct RECT
{
	u16 x1;
	u16 x2;
	u16 y1;
	u16 y2;
}RECT;


#line 110 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Types.h"




// if( GetChipID( ) &CHIPID_MASK == CHIPID_DB... )
#line 124 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Types.h"





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

typedef struct DISP_OBJ
{
	char dummy[0x16C];
}DISP_OBJ;

typedef int (*DISP_OBJ_ONCREATE_METHOD)(DISP_OBJ*);
typedef void (*DISP_OBJ_ONCLOSE_METHOD)(DISP_OBJ*);
typedef void (*DISP_OBJ_ONREDRAW_METHOD)(DISP_OBJ*, int, int, int);
typedef void (*DISP_OBJ_ONKEY_METHOD)(DISP_OBJ*, int scan_code, int unk, int repeat_num, int key_mode);
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
	DISP_OBJ_METHOD field_18;
	DISP_OBJ_METHOD field_1C;
	DISP_OBJ_ONKEY_METHOD onKey;
	DISP_OBJ_METHOD field_24;
	DISP_OBJ_METHOD field_28;
	DISP_OBJ_METHOD field_2C;
	DISP_OBJ_METHOD field_30;
	DISP_OBJ_METHOD field_34;
	DISP_OBJ_METHOD field_38;
	DISP_OBJ_METHOD field_39;
	DISP_OBJ_METHOD field_3A;
	char field_3B;
}DISP_DESC;




// gui -------------------------------------------------------------------------

typedef struct GUI
{
	char dummy[0x90];
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

// book ------------------------------------------------------------------------

struct BOOK;

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
	char isDestroyed;
	char* name;
	UI_APP_SESSION* app_session;
	int parent_BookID;
	u16 unk2;
	int unk3;
	int unk4;
	char unk5;
	void* unk6;
	int unk7;
	u16 unk8;
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
	PCANVAS* pcanvas;
	char unk[0x20];
	PCANVAS* pcanvas_text;
	int unk2;
	PCANVAS* pcanvas_icon;
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




#line 624 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Types.h"



//fopen/_fopen (mode), FSTAT.st_mode
#line 635 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Types.h"

//FSTAT.st_mode






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






// events ----------------------------------------------------------------------

typedef struct CALLMANAGER_EVENT_DATA
{
	char CallID;
	char CallType;
	char CallState;
	int* PNUM;
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
	int* PNUM;
	char unk3;
	char unk4;
	char CallCause;
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
	wchar_t name1[0xC8];
	wchar_t name2[0xC8];
	char shortcut_state;
	char shortcutID;
	char press_mode;
	char is_name1_present;
	char name_type;
	char isEditable;
}SHORTCUT_DESC_A2;


typedef enum shortcut_state {
	SC_State_Absent=0,
	SC_State_Inactive=1,
	SC_State_Present=2,
	SC_State_MainMenu=3
}shortcut_state;

typedef enum shortcut_name_type {
	SC_Name_StandName=0,
	SC_Name_NameAbsent=1,
	SC_Name_MainMenu=2,
	SC_Name_AddShortcut=3
}shortcut_name_type;

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
	FILESUBROUTINE* filesub;
	FILEITEM* file_item;
	BOOK* BrowserItemBook;
	int DB_BookID;
	void* unk2;
	void* unk3;
	GUI* gui;
	void* strinp_struct;
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
	void** LibraryCache; // Не перемещать!!!!!
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







// other -----------------------------------------------------------------------

typedef char* BCD_TEXT;

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

#line 18 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"
#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Function.h"
extern "C"
{
  #pragma swi_number=0x10D
__swi __arm int elfload( const wchar_t* filename, void* param1, void* param2, void* param3 );





  extern __thumb void *memalloc(int minus_one, int size,int f1,int f2,const char *fname,int fline);
  extern __thumb void memfree(int zero, void * mem,const char * fname ,int fline);




  
__thumb void* malloc ( int size );
__thumb void mfree (void * mem);

void* memset( void* mem, char chr, int size );
int memcpy( void* dest, const void* source, int cnt );
int sprintf( char* buf, const char* fmt, ... );
int snwprintf( wchar_t* buffer, int size, const wchar_t* fmt, ... );
int _fopen( const wchar_t* filpath, const wchar_t* filname, unsigned int mode, unsigned int rights, FILELISTITEM* destfname);
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
DB_FILE_FILTER DataBrowser_isFileInListExt_adr( void );
void Timer_ReSet( u16* timer, int time, TIMERPROC onTimer, LPARAM lparam );
u16 Timer_Set( int time, TIMERPROC onTimer, LPARAM lparam );
void Timer_Kill( u16* timerID );
int CreateBook( BOOK* pbook, void (*onClose)( BOOK* ), const PAGE_DESC* bp, const char* name, int ParentBookID, APP_DESC* );
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
void GUIObject_SetStyle( GUI*, int style );
int GUIonMessage_GetCreatedItemIndex( GUI_MESSAGE* msg );
char GUIonMessage_SetMenuItemText( GUI_MESSAGE* msg, TEXTID );
char GUIonMessage_SetMenuItemSecondLineText( GUI_MESSAGE* msg, TEXTID );
char GUIonMessage_SetMenuItemInfoText( GUI_MESSAGE* msg, TEXTID );
char GUIonMessage_SetMenuItemUnavailableText( GUI_MESSAGE* msg, TEXTID );
void GUIonMessage_SetMenuItemIcon( GUI_MESSAGE* msg, int align, IMAGEID );
void DispObject_SetTitleText( DISP_OBJ*, TEXTID );
int ListMenu_GetSelectedItem( GUI_LIST* );
void ListMenu_SetItemStyle( GUI_LIST*, int style );
void GC_PutChar( GC* gc, int x, int y, int _zero, int zero1, wchar_t wchar );
int IsScreenSaverBook( BOOK* bk );
IS_NEEDED_BOOK get_IsScreenSaverBook( void );
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
TEXTID TextID_Create( const void* wstr, TEXT_ENCODING flag, int len );
void TextID_GetString( TEXTID, char* str, int maxlen );
int TextID_GetWString( TEXTID, wchar_t* dest, int maxlen );
int TextID_GetLength( TEXTID );
void TextID_Destroy( TEXTID );
int AB_DEFAULTNBR_GET( int rec_num, void* mem_0x30, int* unk );
int AB_READSTRING( AB_STR_ITEM*, int rec_num, int field_ID );
int AB_READPHONENBR( AB_NUM_ITEM*, int rec_num, int field_ID );
int AB_GETNBROFITEMS( int get_from, int sub_id );
int PNUM_len( void* pnum );
void PNUM2str( char* str, void* pnum, int len, int max_len );
DISP_OBJ* GUIObject_GetDispObject( GUI* );
LIST* List_Create( void );
void List_Destroy( LIST* lst );
int List_InsertFirst( LIST* lst, void* item );
int Gif2ID( u16 IMAGEHANDLE, const wchar_t* path, const wchar_t* fname, IMAGEID* );
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
int get_VBUFFER( void );
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
OSBOOLEAN get_mem( PROCESS pid, OSADDRESS from, void* to, OSADDRESS size );
OSADDRESS get_envp( PROCESS pid, char* name );
OSBOOLEAN set_envp( PROCESS pid, char* name, OSADDRESS value );
PROCESS get_bid( PROCESS pid );
int datetime2unixtime( DATETIME* dt );
char* strcpy( char* dest, const char* source );
char* UIEventName( int event );
char* MissedEvents( void );
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
IS_NEEDED_BOOK get_IsMediaPlayerVideoBook( void );
int REQUEST_DATEFORMAT_GET( const int* sync, char* DateFormat );
int REQUEST_TIMEFORMAT_GET( const int* sync, char* TimeFormat );
TEXTID Date2ID( DATE*, int DateFormat, int );
TEXTID Time2ID( TIME*, char TimeFormat, int isSec );
GUI_LIST* CreateListMenu( BOOK*, int display );
void ListMenu_SetItemCount( GUI_LIST*, int item_count );
LIST** ROOT_APP( void );
void GUIObject_SoftKeys_SetInfoText( GUI*, u16 actionID, TEXTID );
void GUIObject_SoftKeys_SetItemAsSubItem( GUI*, u16 actionID, int subitem );
int REQUEST_SYSTEM_SHUTDOWN( void );
int REQUEST_SYSTEM_RESTART( void );
void GUIObject_SoftKeys_SetTexts( GUI*, u16 actionID, TEXTID short_text, TEXTID full_text );
int IsRightNowBook( BOOK* book );
IS_NEEDED_BOOK get_IsRightNowBook( void );
int IsVolumeControllerBook( BOOK* book );
IS_NEEDED_BOOK get_IsVolumeControllerBook( void );
GUI_TABMENUBAR* CreateTabMenuBar( BOOK* book );
void TabMenuBar_SetTabCount( GUI_TABMENUBAR*, int count );
void TabMenuBar_SetTabGui( GUI_TABMENUBAR*, int tab, GUI* );
void TabMenuBar_SetTabIcon( GUI_TABMENUBAR*, int tab, IMAGEID, int for_state );
GUI* GUIObject_Destroy( GUI* );
void GUIInput_SetIcon( GUI*, IMAGEID );
int StringInput_GetStringAndLen( GUI*, wchar_t**, u16* );
PAudioControl* GetAudioControlPtr( void );
int AudioControl_Vibrate( PAudioControl pIAudioControl, int vibratime, int pausetime, int totaltime );


int GetVolumeSize( wchar_t* root_folder, VOLUMESIZE* );




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
GUI_FEEDBACK* CreateMonitorFeedback( TEXTID, BOOK*, void (*onbusy)(BOOK*), void (*onedit)(BOOK*), void (*ondelete)(BOOK*) );
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
void DrawString( TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color );
void XGUIList_AddGUIObject( XGUILIST* xguilist, GUI* );
void DispObject_InvalidateRect( DISP_OBJ*, RECT* );
int GUIObject_Create( GUI*, void (*GuiDestroy)( GUI* ), void (*DispDescCreate)( DISP_DESC* ), BOOK*, void (*DispObjCallBack)( DISP_OBJ*, void* msg, GUI* ), int display, int size_of_gui );
int SetFont( int );
DISP_OBJ** StatusRow_p( void );
int root_list_get_session_count( void );
UI_APP_SESSION* root_list_get_session( int num_session );
BOOK* SESSION_GetTopBook( UI_APP_SESSION* );
int MainInput_getVisible( GUI* );
int MainInput_strlen( GUI* );
char* MainInput_getPNUM( GUI* );
int MainInput_isPlus( GUI* );
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
void VCALL_SetHZ2( void* vc, u16 );
void MakeVoiceCall( int SessioID, void* vc, int flag );
void FileDelete( wchar_t* path, wchar_t* filename, int* error );
void GUIObject_SetFocus( GUI*, int );
int MSG_SendMessage_CreateMessage( int, void* );
int MSG_SendMessage_DestroyMessage( void* );
int MSG_SendMessage_AddRecipient( void*, wchar_t*, wchar_t*, int, int );
int MSG_SendMessage_Start( int, void*, int );
void* get_APP_DESC_TABLE( void );
int AB_POSITIONNBR_GET( void* ab_name, char*, u16*, void* ab_num );
TEXTID AB_NAME_ITEM2TextID( AB_STR_ITEM* ab_name );
TEXTID AB_NUM_ITEM2TextID( AB_NUM_ITEM* ab_num_item );
int GetABRecNum( AB_GET_STRUCT* );
AB_ITEM_DESC* get_AB_ITEMS_DESC( void );
GUI* SBY_GetMainInput( BOOK* StandBy ); // !!!!! не настоящий !!!!!!
GUI* SBY_GetStatusIndication( BOOK* StandBy ); // !!!!! не настоящий !!!!!!
int REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET( const int* sync, int* );
PROCESS* PID_MMI( void );
GUI* DispObject_GetGUI( DISP_OBJ* );
DISP_OBJ* Display_GetFocusedDispObject( int display );
char DispObject_GetVisible( DISP_OBJ* );
DISP_DESC* DispObject_GetDESC( DISP_OBJ* ); // !!!!! не настоящий !!!!!!
void DISP_DESC_SetName( DISP_DESC*, const char* name );
char* DispObject_GetName( DISP_OBJ* );
void DISP_DESC_SetSize( DISP_DESC*, u16 size );
u16 DISP_DESC_GetSize( DISP_OBJ* );
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
void DISP_DESC_SetMethod04( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetMethod04( DISP_OBJ* );
void DISP_DESC_SetMethod05( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetMethod05( DISP_OBJ* );
void DISP_DESC_SetMethod06( DISP_DESC*, DISP_OBJ_METHOD );
DISP_OBJ_METHOD DispObject_GetMethod06( DISP_OBJ* );
void DISP_DESC_SetMethod07( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetMethod07( DISP_OBJ* );
void DISP_DESC_SetOnLayout( DISP_DESC*, DISP_OBJ_METHOD );
DISP_OBJ_METHOD DispObject_GetOnLayout( DISP_OBJ* );
void DISP_DESC_SetOnConfig( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetOnConfig( DISP_OBJ* );
void DISP_DESC_SetMethod0A( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetMethod0A( DISP_OBJ* );
void DISP_DESC_SetMethod0B( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetMethod0B( DISP_OBJ* );
void DISP_DESC_SetMethod0C( DISP_DESC*, void (*)( void* ) );
DISP_OBJ_METHOD DispObject_GetMethod0C( DISP_OBJ* );
void JavaSession_Manager( int cmd );
TEXTID JavaSession_GetName( void );
TEXTID TextID_Copy( TEXTID );
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
int GetChipID( void );
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



int setjmp( jmp_buf jmpbuf );
void longjmp( jmp_buf, int );

int memcmp( const void* m1, const void* m2, int n );
int strncmp( const char* s1, const char* s2, int len );
char* strncpy( char* dest, const char* source, int maxlen );
char* strcat( char* dest, const char* src );
void GUIObject_SetTitleType( GUI*, int type );
void GUIonMessage_SetItemDisabled( GUI_MESSAGE* msg, BOOL );
int REQUEST_IMAGEHANDLER_INTERNAL_REGISTER( const int* sync, u16 ImageHandler, wchar_t* path, wchar_t* fname, int unk, IMAGEID*, char* error );
int REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER( const int* sync, u16 ImageHandler, u16*, u16*, IMAGEID, int unk_1, char* error );
SURFACE** get_Surfaces( void );
int iconidname2id( const wchar_t* idname, int maxnamelen, int* id );
int textidname2id( const wchar_t* idname, int maxnamelen, TEXTID* id );
void ListMenu_SetNoItemText( GUI_LIST*, TEXTID str );
int IsFmRadioBook( BOOK* bk );
IS_NEEDED_BOOK get_IsFmRadioBook( void );
int IsAudioPlayerBook( BOOK* bk);
IS_NEEDED_BOOK get_IsAudioPlayerBook( void );
void PlayerControl( BOOK* AudioPlayerBook, int );
void SwitchRadioStationFromList( BOOK* FmRadioBook, int );
void Shortcut_Run( wchar_t* shortcut_name );
int mkdir( const wchar_t* path );
int rmdir( const wchar_t* path, int zero );
int chmod( const wchar_t* path, const wchar_t* fname, int amode );
int rename( const wchar_t* oldpath, const wchar_t* oldfname, const wchar_t* newpath, const wchar_t* newfname, int zero );
int GetImageWidth( IMAGEID );
int GetImageHeight( IMAGEID );
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
int StandbyBackground_SetImage( int type, int, int, const wchar_t* path, const wchar_t* fname, int );
GUI* CreateYesNoQuestionVA( int zero, ... );
void ListMenu_SetItemSecondLineText( GUI_LIST*, int elem_num, TEXTID );
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
void* FILEITEM_Destroy_adr( void );
GUI* CreateDateInputVA( int zero, ... );
GUI* CreateTimeInputVA( int zero, ... );
void StringInput_SetCursorPosition( GUI*, u16 curs_pos, char unk );
void BookObj_CallPage( BOOK* book, const PAGE_DESC* page );
unsigned int DateInput_GetDateInt( GUI* );
unsigned int TimeInput_GetTimeInt( GUI* );
FONT_DESC* GetFontDesc( void );
int* GetFontCount( void );
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
void OrangeLED_Control( int _free_val, int or_LED_ID, int level, int fade_time );
void DispObject_SetRefreshTimer( DISP_OBJ*, int time );
void DispObject_KillRefreshTimer( DISP_OBJ* );
int IsDataBrowserBook( BOOK* book );
IS_NEEDED_BOOK get_IsDataBrowserBook( void );
SUB_EXECUTE* BrowserItem_Get_SUB_EXECUTE( BOOK* BrowserItemBook );
TEXTID Shortcut_Get_MenuItemName( void* );
IMAGEID Shortcut_Get_MenuItemIconID( void* );
BOOK* FindBookEx( int (*cmp_proc)( BOOK* book_from_list, int* param ), int* param );
FILEITEM* FILEITEM_CreateCopy( FILEITEM* );
int BookObj_GetSessionID( BOOK* book );
void UI_Event_toSID( int event, int sess_id );
char* GetIMSI( void );
void UI_CONTROLLED_SHUTDOWN_RESPONSE( int book_id );
int MainInput_getCurPos( GUI* );
void MainInput_Hide( GUI* );
void DispObject_SoftKeys_RestoreDefaultAction( DISP_OBJ*, int action );
TEXTID PNUM2Name( void* pnum, int isIconNeeded, int only_full_number_flag );
int SpeedDial_GetPNUM( int _zero, char charter0__9, void* PNUM );
void* MetaData_Desc_Create( wchar_t* path, wchar_t* name );
void MetaData_Desc_Destroy( void* MetaData_Desc );
wchar_t* MetaData_Desc_GetTags( void* MetaData_Desc, int tagID );
int MetaData_Desc_GetTrackNum( void* MetaData_Desc, int __NULL );
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
int Disp_GetTextIDWidth( TEXTID, int len );
int MetaData_Desc_GetCoverInfo( void* MetaData_Desc, char* cover_type, int* size, int* cover_offset );
int ImageID_GetIndirect( void* buf_image, int size, int __NULL, wchar_t* image_type, IMAGEID* );
void unixtime2datetime( int, DATETIME* );
int List_Insert( LIST* lst, int i, void* item );
int FileCopy( wchar_t* src_path, wchar_t* src_name, wchar_t* dest_path, wchar_t* dest_name, int );
int FileMove( wchar_t* src_path, wchar_t* src_name, wchar_t* dest_path, wchar_t* dest_name, int );
void RedLED_On( int __NULL );
void RedLED_Off( int __NULL );
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
void GUIObject_SetTitleBackgroundImage( GUI*, IMAGEID );
void GUIObject_SetTitleIcon( GUI*, IMAGEID );
void GUIObject_SetCursorImage( GUI*, IMAGEID );
void GUIObject_SetBackgroundImage( GUI*, IMAGEID );
void* DispObject_SoftKeys_GetParams( DISP_OBJ* );
LIST* DispObject_SoftKeys_GetList( DISP_OBJ*, BOOK* book, char __zero );
int BookObj_GetDisplayOrientation( BOOK* book );
void BookObj_SetDisplayOrientation( BOOK* book, int orientation );
BOOK* Display_GetTopBook( int display );
void Display_SetBrightness( int display, int brightness );
int Display_GetBrightness( int display );
void DataBrowserDesc_Menu_AddFSFunctions( void* DataBrowserDesc, int );
void DataBrowserDesc_Menu_AddNewFolder( void* DataBrowserDesc, int );
void DataBrowserDesc_Menu_AddMarkFiles( void* DataBrowserDesc, int );
void SetTheme( wchar_t* path, wchar_t* name, int bookid, int unk_1 );
void SoftKeys_GetLabel( DISP_OBJ* softkeys, SKLABEL* lbl, int id );
void SoftKeys_Update( DISP_OBJ* softkeys );
int get_CellData( PLMN_LAC_DESC* desc1, RAT_CI_DESC* desc2, char* CSReg );
void* IncommingCall_Reject( BOOK* book );
void* IncommingCall_Mute( BOOK* book );
int GetRadioState( char* level, char* flag );
int Bluetooth_GetState( void );
int Bluetooth_GetPhoneVisibility( void );
int Bluetooth_isBusy( void );
int USB_isConnected( void );
void* w_diropen( const wchar_t* dir );
wchar_t* w_dirread( void* );
int w_dirclose( void* );
int w_rename( const wchar_t* dst, const wchar_t* src );
int w_remove( const wchar_t* dir );
int ConnectionManager_Connection_GetState( void );
int GetSignalQuality( char* rssi, char* ber );
int IsCameraBook( BOOK* bk );
IS_NEEDED_BOOK get_IsCameraBook( void );
int IsSoundRecorderBook( BOOK* bk );
IS_NEEDED_BOOK get_IsSoundRecorderBook( void );
void StringInput_MenuItem_SetPriority( GUI* strinp, int prio, int actionID );
void VideoPlayerControl( BOOK* VideoPlayerBook, int );
void Video_ActionBack( BOOK* VideoPlayerBook, void* );
void Video_ExtractFrame( BOOK* VideoPlayerBook, void* );
void Video_ZoomOn( BOOK* VideoPlayerBook, void* );
void RightNow_SetActive( int flag );
void VideoResize_AutomateMode( BOOK* VideoPlayerBook, u16 VideoWidth, u16 VideoHeight, u16* NewWidth, u16* NewHeight );
void VideoResize_AllScreenMode( BOOK* VideoPlayerBook, u16 VideoWidth, u16 VideoHeight, u16* NewWidth, u16* NewHeight );
int Video_GetCurrentSkinID( BOOK* VideoPlayerBook );
void Video_SetSkin( GUI* VideoPlayerGUI, int skinID );
int Video_SetPermit( BOOK* VideoPlayerBook, u16 NewWidth, u16 NewHeight );
int Video_Refresh( BOOK* VideoPlayerBook, GUI* VideoPlayerGUI );
void Video_Play( BOOK* VideoPlayerBook, void* );
void Video_Pause( BOOK* VideoPlayerBook, void* );
void Video_Stop( BOOK* VideoPlayerBook, void* );
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
int Browser_OpenURI( BOOK* book, char* URI, int mode );
char* GetURIScheme( int schemeID );
char* CreateURI( wchar_t* fpath, wchar_t* fname, char* URIScheme );
void DataBrowserDesc_SetViewModeAndSortOrder( void* DataBrowserDesc, int view_sort_ID );
int Alarm_GetCurrentTypeAndAlarmID( char* type, wchar_t* AlarmID );
int Alarm_GetState( char* state, int AlarmID );
int Alarm_GetTIME( TIME* AlarmTime, int AlarmID );
int Alarm_GetWeekSettings( void* week, int AlarmID );
int IrDa_GetState( char* state );
void REQUEST_SETTING_ALLOWEDCALLERS_GET( const int* sync, int ProfileNum, char* state );
void* IncommingCall_Accept( BOOK* book );
void MediaPlayer_SoftKeys_SetText( GUI* player_gui, int actionID, TEXTID );
void MediaPlayer_SoftKeys_SetAction( GUI* player_gui, int actionID, SKACTIONPROC proc );
void MediaPlayer_SoftKeys_SetItemAsSubItem( GUI* player_gui, int item, int subitem );
void MediaPlayer_SoftKeys_AddHelpStr( GUI* player_gui, int item, TEXTID );
void MediaPlayer_ShowNowPlaying( DISP_OBJ*, int );
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
void REQUEST_ALARMCLOCKSTATUS_GET( const int* sync, char* alarm_status );
void REQUEST_ALARMCLOCKTIME_GET( const int* sync, TIME* t );
void REQUEST_ALARMDATEANDTIMESTATUS_GET( const int* sync, DATETIME* );
int Settings_ShowNumber_Get( char* state );
GVI_BMP GVI_CreateBitmap( int xsize, int ysize, int bpp );
GVI_GC GVI_CreateMemoryGC( GVI_BMP bitmap );
void GVI_DeleteMemoryGC( GVI_GC gc );
int StringInput_DispObject_SetLanguage( DISP_OBJ_STRING_INPUT*, int langID, int flag );
int List_InsertSorted( LIST* list, void* item, int (*cmp_proc)( void*, void* ) );
int ListMenu_SetItemIcon( GUI_LIST*, int Item, wchar_t unk_FFFF, int mode, IMAGEID );
void wstrnupr( wchar_t* wstr, int maxlen );
void wstrnlwr( wchar_t* wstr, int maxlen );
int ListMenu_SetItemTextScroll( GUI_LIST*, int scroll );
void GUIObject_SetTitleTextColor( GUI*, int color );
void GUIObject_SetListTextColor( GUI*, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro );
void DispObject_SetTitleTextColor( DISP_OBJ*, int color );
void DispObject_SetListTextColor( DISP_OBJ*, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro );
void DispObject_SetCursorImage( DISP_OBJ*, IMAGEID );
void DispObject_SetBackgroundImage( DISP_OBJ*, IMAGEID );
void DispObject_SetTitleBackgroundImage( DISP_OBJ*, IMAGEID );
void TabMenuBar_SetTabTitle( GUI_TABMENUBAR*, int tab_num, TEXTID );
BOOK* GUIObject_GetBook( GUI* );
u16 SoftKeys_GetSelectedAction( void );
void MonitorFeedback_SetTimer( GUI_FEEDBACK*, int time, void (*callback)(BOOK*) );
void (*getListMenuOnGuiDestroy())( GUI* );
void (*getListMenuOnDescCreate())( DISP_DESC* );
void (*getListMenuOnDispMessage())( DISP_OBJ*, void*, GUI* );
void (*getTabMenuBarOnGuiDestroy())( GUI* );
void (*getTabMenuBarOnDescCreate())( DISP_DESC* );
void (*getTabMenuBarOnDispMessage())( DISP_OBJ*, void*, GUI* );
void (*getOneOfManyOnGuiDestroy())( GUI* );
void (*getOneOfManyOnDescCreate())( DISP_DESC* );
void (*getOneOfManyOnDispMessage())( DISP_OBJ*, void*, GUI* );
void (*getNOfManyOnGuiDestroy())( GUI* );
void (*getNOfManyOnDescCreate())( DISP_DESC* );
void (*getNOfManyOnDispMessage())( DISP_OBJ*, void*, GUI* );
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

void DisplayGC_AddRef(GC*,void *);

  TEXTID TextID_CreateImageID( IMAGEID );
  int GetChargingState();
  int FlightGetState( void );
  int FlightControl( int status );
  int GetNewEvent( void );
  int ConnectionManager_Connection_GetState_int(char * buf);
  void GUIObject_SoftKeys_SetItemOnKey(GUI*, u16 actionID, int key, int mode);
  void GUIObject_TabTitleRemove(GUI* ,int mode);
  void TabMenuBar_SetTabIcon( GUI_TABMENUBAR*, int tab, IMAGEID, int for_state );
  
TEXTID SetOperatorName( TEXTID, int _null );
TEXTID GetOperatorName( wchar_t* );

void Shutdown( void );
void Restart( void );

  GUI* CreateYesNoQuestion( BOOK* , int display);
  void YesNoQuestion_CreatePreQuestion( GUI*, int );
  void YesNoQuestion_CreateQuestion( GUI*, int );
  void YesNoQuestion_SetIcon( GUI*, wchar_t );
  
  GUI* CreateStringInput(BOOK* myBook);
  void StringInput_SetText(GUI*, TEXTID);
  void StringInput_SetMaxLen(GUI*, int len);
  void StringInput_SetMode(GUI*, INPUT_TYPES);
  void StringInput_EnableEmptyStr(GUI*, BOOL);
  
};
#line 19 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"

#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\inc\\types.h"











enum Types
{
    TYPE_SHORTCUT = 0,
    TYPE_JAVA = 1,
    TYPE_ELF = 2
};

typedef struct
{
    wchar_t *Name;
    wchar_t *Fullpath;
    wchar_t ImageID;
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
    wchar_t *sData;
    wchar_t *Caption; 
    int Icon;
}SHORTCUT;

typedef struct
{
    BOOK book;
    GUI_LIST *MainMenu;
    GUI_LIST *Editor;
    GUI_LIST *JavaMenu;
    GUI_LIST *TypesList;
    GUI *CaptionInput;
    LIST *Items;
    LIST *JavaList; 
    int SelectedIndex;
    int CurrentPos;
    SHORTCUT *Current;
    wchar_t Icons[3];
}MyBOOK;

#line 21 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"
#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\inc\\editor.h"



void EditorRun(BOOK *bk);

#line 22 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"
#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\inc\\utils.h"



void RunShortcut(SHORTCUT *Shortcut);
void *SHORTCUT_DESC_Init(wchar_t *param);
void *SHORTCUT_DESC_A2_Init(wchar_t *param);
void FreeList(LIST* &List, void (*FreeProc)(void *Item));
void SaveConfig(LIST *List);
LIST *LoadConfig();

#line 23 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"
#line 1 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\inc\\strlib.h"



int StringLength(wchar_t *Str);
void StringFree(wchar_t *Str);
wchar_t *StringAlloc(int Length);
void StringAllocEx(wchar_t **Str, int Size);
void StringReallocEx(wchar_t *Src, wchar_t **Dest, int Size);
void StringRealloc(wchar_t *Src, wchar_t **Dest);
void StringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name);
void StringExtractFileName(wchar_t *Str, wchar_t **Name);

#line 24 "E:\\MOd\\ELFs\\SVN\\patch\\Patch_Goto_Shortcut_New\\Goto_Shortcut.c"




void ShortcutFree(void *Item);

__thumb void * malloc (int size)
{



  return(memalloc(0xFFFFFFFF,size,1,5,"gt",0));



}

__thumb void mfree (void * mem)
{



  if (mem) memfree(0, mem,"gt",0);



}

void* operator new(size_t sz){return malloc(sz);};
void* operator new[](size_t sz){return malloc(sz);};
void operator delete(void * p){mfree(p);};
void operator delete[](void * p){mfree(p);};

void* operator new(size_t size, void* p){ return p; }
void* operator new[](size_t size, void* p){ return p; }
void operator delete (void*, void*) { }
void operator delete[] (void*, void*) { }

int UpdateMainPage(void *, BOOK *Book);

int IsMyBook( BOOK* book )
{
  if(strcmp(book->xbook->name, "GotoShortcut_Book")) return (0);
  return (1);
}

int Menu_Callback(GUI_MESSAGE *Message)
{
  MyBOOK *mbk = (MyBOOK*)GUIonMessage_GetBook(Message);
  if (!mbk->Items->FirstFree) return(0);
    
  switch(GUIonMessage_GetMsg(Message))
  {
  case LISTMSG_GetItem:
    int Index = GUIonMessage_GetCreatedItemIndex(Message);
    SHORTCUT *Shortcut = (SHORTCUT*) List_Get(mbk->Items, Index);
    GUIonMessage_SetMenuItemText(Message, TextID_Create(Shortcut->Caption, ENC_UCS2, 0xFFFF));
    GUIonMessage_SetMenuItemIcon(Message, 0, Shortcut->Icon);
    break;
  }
  return(1);
}

void Menu_Back(BOOK *bk, GUI *)
{
  FreeBook(bk);
}

void Menu_Select(BOOK *bk, GUI *)
{
  MyBOOK *mbk = (MyBOOK*)bk;
  SHORTCUT *ShortCut = (SHORTCUT*)List_Get(mbk->Items, ListMenu_GetSelectedItem(mbk->MainMenu));
  if (ShortCut) RunShortcut(ShortCut);
  FreeBook(bk);
}

void ShortcutFree(void *Item)
{
  SHORTCUT *Shortcut = (SHORTCUT*)Item;
  if(Shortcut)
  {
    StringFree(Shortcut->sData);
    StringFree(Shortcut->Caption);   
    mfree(Shortcut);
  }
}

void Menu_Delete_Yes(BOOK *Book, GUI *)
{
  MyBOOK *mbk = (MyBOOK*)Book;
  void *Item = List_RemoveAt(mbk->Items, ListMenu_GetSelectedItem(mbk->MainMenu));
  ShortcutFree(Item);
  mbk->CurrentPos = ListMenu_GetSelectedItem(mbk->MainMenu) - 1;
  UpdateMainPage(0, (BOOK*)mbk);
}

void Menu_Delete_No(BOOK *Book, GUI *)
{
  MyBOOK *mbk = (MyBOOK*)Book;
  mbk->CurrentPos = ListMenu_GetSelectedItem(mbk->MainMenu);
  UpdateMainPage(0, Book);
}

int get_StrID(BOOK* bk)
{
  MyBOOK *mbk = (MyBOOK*)bk;
  int item = ListMenu_GetSelectedItem(mbk->MainMenu);
  SHORTCUT *Shortcut = (SHORTCUT*) List_Get(mbk->Items, item);
  return (TextID_Create(Shortcut->Caption, ENC_UCS2, 0xFFFF));
}

void Menu_Delete(BOOK *bk, GUI *)
{
  GUI *Request = CreateYesNoQuestion(bk,0);
  YesNoQuestion_CreateQuestion(Request, 0x2727);
  YesNoQuestion_CreatePreQuestion(Request, get_StrID(bk));
  GUIObject_SoftKeys_SetAction(Request, 0xFC5, Menu_Delete_Yes);
  GUIObject_SoftKeys_SetAction(Request, 0xFBE, Menu_Delete_No);
  GUIObject_SoftKeys_SetAction(Request, 0xFC0, Menu_Delete_No);
  GUIObject_Show(Request);
}

void Menu_About(BOOK *bk, GUI *)
{
  int Text = TextID_Create("GotoShortcut\nv3 rev A\n\n(c) farid\n(r) mobilefree.ru",ENC_LAT1,0xFF);
  MessageBox(0x6FFFFFFF, Text, 0xFFFF, 1, 0, bk);
}
   
void Menu_Add(BOOK *Book, GUI *)
{
  MyBOOK *mbk = (MyBOOK*)Book;
  SHORTCUT *Shortcut = (SHORTCUT *)malloc(sizeof(SHORTCUT));
  memset(Shortcut, 0, sizeof(SHORTCUT));
  List_InsertFirst(mbk->Items, Shortcut);
  mbk->Current = (SHORTCUT*) List_Get(mbk->Items, 0);
  EditorRun((BOOK*)mbk);
}

void Menu_Modify(BOOK *Book, GUI *Menu)
{
  MyBOOK *mbk = (MyBOOK*)Book;
  mbk->Current = (SHORTCUT*) List_Get(mbk->Items, ListMenu_GetSelectedItem(mbk->MainMenu));
  EditorRun((BOOK*)mbk);
}

int CreateMainPage(void *, BOOK *Book)
{
  MyBOOK *mbk = (MyBOOK*)Book;
  int count = mbk->Items->FirstFree;

  if (mbk->MainMenu) { GUIObject_Destroy(mbk->MainMenu); mbk->MainMenu = 0; };

  mbk->MainMenu = CreateListMenu((BOOK*)mbk, 0);
  GUIObject_SetTitleText(mbk->MainMenu, 0x2CB0);
  
  ListMenu_SetItemCount(mbk->MainMenu, count);
  ListMenu_SetOnMessage(mbk->MainMenu, Menu_Callback); 
  ListMenu_SetCursorToItem(mbk->MainMenu, mbk->CurrentPos);
  
  if(!count)
  {
    ListMenu_SetNoItemText(mbk->MainMenu, 0x1544);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0, Menu_Add);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 0, 0x22B3);  
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 1, Menu_About);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 1, 0x0BFA);
  }
  else
  {
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0, Menu_Add);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 0, 0x22B3);  
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 1, Menu_Modify);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 1, 0x22AE);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 2, Menu_About);
    GUIObject_SoftKeys_SetText(mbk->MainMenu, 2, 0x0BFA);
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0xFB4, Menu_Delete);  
    GUIObject_SoftKeys_SetVisible(mbk->MainMenu, 0xFB4, 0 );
    GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0xFC2, Menu_Select);
  }
  GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0xFC0, Menu_Back);
  GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0xFAF, Menu_Back);
  GUIObject_Show(mbk->MainMenu);
  return(1);
};

int Cancel_BasePage(void *r0, BOOK *bk)
{
  MyBOOK* mbk = (MyBOOK*)bk;
  FreeBook((BOOK*)mbk);
  return(1);
}

const PAGE_MSG bk_msglst_base[] = 
{
  0x4,            Cancel_BasePage,
  0x841, Cancel_BasePage,
  0,               0
};
const PAGE_DESC bk_base = {"Goto_Shortcut_Base_Page",0,bk_msglst_base};

const PAGE_MSG bk_msglst_main[] = 
{
  0xE,  CreateMainPage,
  0x2,      UpdateMainPage,
  0,         0
};
const PAGE_DESC bk_main = {"Goto_Shortcut_Main_Page",0,bk_msglst_main};

int UpdateMainPage(void *, BOOK *bk)
{
  BookObj_GotoPage(bk, &bk_main);
  return(0);
}

void onBkClose (BOOK* bk)
{
  MyBOOK* mbk = (MyBOOK*)bk;
  if (mbk->MainMenu) { GUIObject_Destroy(mbk->MainMenu); mbk->MainMenu = 0; };
  SaveConfig(mbk->Items);
  FreeList(mbk->Items, ShortcutFree);
}

extern "C"
__thumb void GotoShortcut()
{
  BOOK * bk = FindBook(IsMyBook);
  if (bk) BookObj_SetFocus(bk,0);
  else
  {
    MyBOOK* mbk = (MyBOOK*)malloc(sizeof(MyBOOK));
    memset( mbk, 0, sizeof(MyBOOK));
    if (!CreateBook((BOOK*)mbk,onBkClose,&bk_base,"GotoShortcut_Book",-1,0)) mfree(mbk);
    {
      mbk->Icons[0] = 0xEBE6;
      mbk->Icons[1] = 0xEB25;
      mbk->Icons[2] = 0xE5BE;
      //mbk->Current = NULL;
      mbk->CurrentPos = 0;
      mbk->Items = LoadConfig();
      BookObj_GotoPage((BOOK*)mbk,&bk_main);
    }
  }
}
