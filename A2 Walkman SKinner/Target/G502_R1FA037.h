#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define MC_LANDSCAPE_ICN	0xECBA
#define MC_PORTRAIT_ICN		0xECD5

#define RN_TAB_SESSION_MANAGER_SELECTED_ICN	0xF39E
#define RN_TAB_SESSION_MANAGER_DESELECTED_ICN	0xF39D

//#define GETFONTDESC		(FONT_DESC*)0x2A2846AC
//#define GETFONTCOUNT		(int*)0x2A284A1C

#define IID_IMetaData             (UUID*)0x119C7578
#define CID_CMetaData             (UUID*)0x1199A854
#define CID_CMusicServer_Manager  (UUID*)0x119A61F0
#define IID_IMusicServer_Manager  (UUID*)0x119CE310

#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CLIPBOARD_COPYALL 0xFD8
#define ACTION_CLIPBOARD_MARKANDCOPY 0xFD9
#define ACTION_CLIPBOARD_PASTE 0xFDA
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
#define ACTION_DB_MANAGEFILE 0x5A
#define ACTION_DELETE 0xFB4
#define ACTION_DONE 0xFB5
#define ACTION_EDIT 0xFB6
#define ACTION_EXPAND 0xFA2
#define ACTION_HELP 0xFB7
#define ACTION_INFO 0xFB9
#define ACTION_LONG_BACK 0xFAF
#define ACTION_MORE 0xFA0
#define ACTION_MORE1 0xFA1
#define ACTION_MORELIST 0xFB2
#define ACTION_NO 0xFBE
#define ACTION_NOT_EMPTY 0xFBB
#define ACTION_OK 0xFBF
#define ACTION_SAVE 0xFC1
#define ACTION_SELECT 0xFB8
#define ACTION_SELECT1 0xFC2
#define ACTION_UNCHECK 0xFC3
#define ACTION_YES 0xFC5

#define ACTION_MP_FILE          0x8
#define ACTION_MP_SETTINGS      0xF
#define ACTION_MP_SKINEDITOR    0x13
#define ACTION_MP_VISUALISATION 0x14

#define UI_MEDIAPLAYER_UPDATE_EVENT 0x3C36
#define RETURN_TO_STANDBY_EVENT 0x841
#define PAGE_EXIT_EVENT         0xF
#define PAGE_ENTER_EVENT        0xE
#define CANCEL_EVENT            0x4
#define PREVIOUS_EVENT          0x3
#define ACCEPT_EVENT            0x2
#define NIL_EVENT               0

#define TEXT_FONT_SIZE  0xB4B
#define TEXT_OK         0x8D8
#define TEXT_COLOR      0x2E01

#define TEXT_SKINS      0x160E
#define TEXT_VISUALISATIONS   0x163C

#define TEXT_YES        0x63
#define TEXT_NO         0x61
#define TEXT_ENABLE     0x85E
#define TEXT_DISABLE    0x85C
#define TEXT_ENABLED    0xA74
#define TEXT_DISABLED   0xA72
#define TEXT_SAVE       0x121

#define TEXT_CHANGES_MADE  0x218
#define TEXT_SAVE2    0x219

#define TEXT_ALIGN      0xAD4
#define TEXT_LEFT       0x17D3
#define TEXT_RIGHT      0x17D4

#define TEXT_PORTRAIT   0x1637
#define TEXT_LANDSCAPE  0x1635

#define TEXT_POSITION   0x1D9A

#define TEXT_TITLE      0x1615
#define TEXT_ARTIST     0x153B
#define TEXT_ALBUM      0x1532
#define TEXT_GENRE      0x1648
#define TEXT_ALBUM_ART  0x1639

#define TEXT_FULLSCREEN 0x1631
#define TEXT_TEXT_COLOR 0x23D9
#define TEXT_BACKGROUND_COLOR 0x2385

#define TURNON          0x1BE8
#define TURNOFF         0x1B89
#define PATH            0x11987FC4

#define page_MusicApplication_Main  (PAGE_DESC*)0x11B652DC

//G502 fonts
#define D_7R 	  	0x01
#define E_8R	  	0x02
#define E_12R	  	0x0D
#define E_12B	  	0x0E
#define E_14R	  	0x12
#define E_14B	  	0x13
#define E_16R	  	0x19
#define E_16B	  	0x1A
#define E_16I	  	0x1B
#define E_16BI	  	0x1C
#define E_18R	  	0x22
#define E_20R	  	0x2B
#define E_20B	  	0x2C
#define E_20I	  	0x2D
#define E_20BI	  	0x2E
#define E_24R	  	0x35
#define E_24B	  	0x36
#define E_24I	  	0x37
#define E_24BI	  	0x38
#define D_24B	  	0x3F
#define D_29B	  	0x40
#define ICON_16BI 	0x48
#define E_30R	  	0x55
#define E_40R	  	0x57
#define E_60R	  	0x5B
#define E_75R	  	0x5C
#define E_100R	  	0x5E

#define FONT_E_20B      0x2C
#define FONT_E_20R      0x2B

#define KBD_LONG_PRESS    0x1
#define KBD_LONG_RELEASE  0x4
#define KBD_REPEAT        0x2
#define KBD_SHORT_PRESS   0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DEL         0x5
#define KEY_DIEZ        0x1E
#define KEY_DIGITAL_0   0x13
#define KEY_DOWN        0xD
#define KEY_ENTER       0x8
#define KEY_ESC         0x4

#define KEY_LEFT        0xF
#define KEY_LEFT_SOFT   0x2

#define KEY_RIGHT       0xB
#define KEY_RIGHT_SOFT  0x3
#define KEY_STAR        0x1D
#define KEY_TASK        0x1F
#define KEY_UP          0x9
#define KEY_VOL_DOWN    0x12
#define KEY_VOL_UP      0x11


#define VAR_BOOK 		(char*)0x1205FDE7
#define VAR_STRINP_MODE 	(char*)0x1205FE0F
#define VAR_STRINP_NEW_LINE	(char*)0x1205FE05
#define VAR_STRINP_MAX_LEN 	(char*)0x1205FE19
#define VAR_STRINP_MIN_LEN 	(char*)0x1205FE21
#define VAR_STRINP_SET_INT_VAL 	(char*)0x1205FDF9
#define VAR_STRINP_FIXED_TEXT 	(char*)0x1205FE35
#define VAR_OK_PROC 		(char*)0x1205FDD5
#define VAR_HEADER_TEXT 	(char*)0x1205FE4F
#define VAR_YESNO_PRE_QUESTION 	(char*)0x1205FE01
#define VAR_YESNO_QUESTION 	(char*)0x1205FE39
#define VAR_YESNO_YES_ACTION 	(char*)0x1205FE55
#define VAR_YESNO_NO_ACTION 	(char*)0x1205FE2D

#define SCN_WIDTH 240
#define SCN_HEIGHT 320

#endif
#endif
