#ifndef W890_R1FA035
#error W890_R1FA035 configuration needed for this header!
#else
#ifndef _W890_R1FA035_
#define _W890_R1FA035_

#define MC_LANDSCAPE_ICN	0xEC9D
#define MC_PORTRAIT_ICN		0xECBA

#define RN_TAB_SESSION_MANAGER_SELECTED_ICN	0xF376
#define RN_TAB_SESSION_MANAGER_DESELECTED_ICN	0xF375

#define GETFONTDESC		0x2A2858DC
#define GETFONTCOUNT		0x2A285C4C

#define IID_IMetaData             0x11A10370
#define CID_CMetaData             0x119E3514
#define CID_CMusicServer_Manager  0x119EEEB0
#define IID_IMusicServer_Manager  0x11A17108

#define ACTION_LONG_BACK        	0xFAF
#define ACTION_SELECT1          	0xFC2
#define ACTION_DELETE           	0xFB4
#define ACTION_BACK             	0xFC0
#define ACTION_YES              	0xFC5
#define ACTION_NO               	0xFBE

#define RETURN_TO_STANDBY_EVENT 	0x841
#define ACCEPT_EVENT 			0x2
#define PREVIOUS_EVENT 			0x3
#define CANCEL_EVENT            	0x4
#define PAGE_ENTER_EVENT        	0xE
#define NIL_EVENT                       0

#define TURNON				0x1BE8
#define TURNOFF				0x1B89

#define PATH                        	0x119D06E0
#define page_MusicApplication_Main	0x11BB14EC

#define MEDIAPLAYER_PAUSE_ICN 	      	0xF850
#define MEDIAPLAYER_REWIND_ICN 		0xF851
#define MEDIAPLAYER_PLAY_ICN 		0xF852
#define MEDIAPLAYER_FAST_FORWARD_ICN  	0xF853

#define MEDIAPLAYER_MODE_RANDOM_ICN     0xECE2
#define MEDIAPLAYER_MODE_LOOP_ICN       0xECE0

#define MP_EQ_STATUS_ICN	0xED89
#define MP_EQ_BASS_ICN 		0xED86
#define MP_EQ_MANUAL_ICN 	0xED87
#define MP_EQ_MEGABASS_ICN 	0xED88
#define MP_EQ_NORMAL_ICN 	0xED89
#define MP_EQ_TREBLEBOOST_ICN 	0xED8A
#define MP_EQ_VOICE_ICN 	0xED8B

//W890 fonts
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


#define VAR_BOOK 		0x120AD02D
#define VAR_STRINP_MODE 	0x120AD055
#define VAR_STRINP_NEW_LINE	0x120AD04B
#define VAR_STRINP_MAX_LEN 	0x120AD05F
#define VAR_STRINP_MIN_LEN 	0x120AD067
#define VAR_STRINP_SET_INT_VAL 	0x120AD03F
#define VAR_STRINP_FIXED_TEXT 	0x120AD07B
#define VAR_OK_PROC 		0x120AD01B
#define VAR_HEADER_TEXT 	0x120AD095
#define VAR_YESNO_PRE_QUESTION 	0x120AD047
#define VAR_YESNO_QUESTION 	0x120AD07F
#define VAR_YESNO_YES_ACTION 	0x120AD09B
#define VAR_YESNO_NO_ACTION 	0x120AD073

#endif
#endif
