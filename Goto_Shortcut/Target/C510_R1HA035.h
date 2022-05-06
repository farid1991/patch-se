#ifndef C510_R1HA035
#define C510_R1HA035

#define A2
#define DB3210

#define ELFS_INT_PATH L"/usb/other/ZBin"
#define ELFS_EXT_PATH L"/card/other/ZBin"
#define ELFS_PATH_COUNT 2

// Menu
#define TITLE_TXT           0xAA2   // L"Goto"
#define MENU_ADD_TXT        0x193A  // L"New shortcut"
#define MENU_MODIFY_TXT     0x1754  // L"Edit shortcut"
#define EMPTY_LIST_TXT      0x89A   // L"No shortcuts"
#define MENU_ABOUT_TXT      0x251C  // L"About"
  
// Editing
#define EDITOR_TITLE_TXT    0x2755  // L"Editor"
#define EDITOR_LABEL_TXT    0xEA1   // L"Name"
#define EDITOR_SHORTCUT_TXT 0x198F  // L"Shortcut"
#define TYPES_TITLE_TXT     0x103F // L"Type"

#define SHC_SET_MM          0x1C5C
#define SHC_SET_SHORTCUT_SK 0xB5C
#define DELETEQ_TXT         0x198C

#define OPEN_TXT            0x531
#define SELECT_TXT          0xB5C

#define JAVA_APP_TXT        0x5D8
#define EVENT_TXT           0x103D
#define FOLDER_TXT          0x610
#define SELECT_FOLDER_TXT   0x610

#define HPB_OTHER_ICN       0xF761
#define MENU_SETTINGS_ICN   0x0519
#define ANIMALS_MOUSE_ICN   0x00BA

#define SHORTCUT_LIST_ICN   0x0808
#define ENTERTAINMENT_ICN   0x0807
#define DB_LIST_JAVA_ICN    0xF875
#define GUI_UNAVAILABLE_ICN 0xF8A6
#define DB_LIST_FOLDER_ICN  0x016A

#define SHC_DESKTOP_WATERMARK_ICN 0x0861

#define F_PATH 		  (wchar_t*)0x15A86E38
#define MAIN_MENU         (wchar_t*)0x15B2C28C
#define JAVA_TXT          (wchar_t*)0x15927760
#define SHORTCUT_TXT      (wchar_t*)0x15924F36

// interface id ----------------------------------------------------
/*
#define CID_CUIFontManager (PUUID)0x15AC227C
#define IID_IUIFontManager (PUUID)0x15AFB108
#define CID_CUIImageManager (PUUID)0x15AC4F1C
#define IID_IUIImageManager (PUUID)0x15AFD4C4
#define CID_CTextRenderingManager (PUUID)0x15AC99C4
#define IID_ITextRenderingManager (PUUID)0x15AFFFA4
#define CID_CRegistryManager (PUUID)0x15AB0808
#define IID_IRegistryManager (PUUID)0x15AF0B20
#define CID_CMetaData (PUUID)0x15A9EEE0
#define IID_IMetaData (PUUID)0x15AE2FFC
#define CID_CPlayerManager (PUUID)0x15A83AE8
#define IID_IPlayerManager (PUUID)0x15A84F90
#define CID_CAudioControlManager (PUUID)0x15A915C4
#define IID_IAudioControlManager (PUUID)0x15ACC7A0
#define CID_CCopsManager (PUUID)0x15A839A8
#define IID_ICopsManager (PUUID)0x15A84A20
#define CID_CIndicationDeviceManager (PUUID)0x15A83A28
#define IID_IIndicationDeviceManager (PUUID)0x15A84C00
#define CID_CIlluminationControl (PUUID)0x15A97F4C
#define IID_IIlluminationControl (PUUID)0x15ADE21C
#define CID_CFlashLightControl (PUUID)0x15A97F00
#define IID_IFlashLightControl (PUUID)0x15ADE1EC
*/
// function ----------------------------------------------------

#define GET_IMEI (char*)0x4BA019D0
#define GetSignalQuality_Send_SignalID 0x12C00040
#define GetSignalQuality_Receive_SignalID 0x12C007C0
#define MainInput_data (char*)0x4BA2654C
#define MainInput_CurPos_Offset 0x8
#define MissedEvents (char*)0x4BA1B07C
#define ROOT_APP (LIST**)0x4BA26730
#define GetAudioControlPtr (PAudioControl*)0x4BA2CE98
#define StatusRow_p (DISP_OBJ**)0x4BA2B924
#define get_APP_DESC_TABLE (void*)0x15B25D68
#define get_AB_ITEMS_DESC (AB_ITEM_DESC*)0x1592DC7C
#define PID_MMI (PROCESS*)0x4BA2B6E4
#define LastExtDB (DB_EXT*)0x15B5CE04
#define get_Surfaces (SURFACE**)0x4BD57DB4
#define mfree_adr() mfree

// var_arg ----------------------------------------------------
#define VAR_BOOK (char*)0x45C4BD52
#define VAR_ARG_YESNO_QUESTION (char*)0x45C4BDC0
#define VAR_SOME (char*)0x45C4BDB4

//#define VAR_BOOK (char*)0x15CAB83E
#define VAR_HEADER_TEXT (char*)0x15CAB89E
#define VAR_OK_PROC (char*)0x15CAB82C
#define VAR_PREV_ACTION_PROC (char*)0x15CAB888
#define VAR_LONG_BACK_PROC (char*)0x15CAB840
#define VAR_STRINP_MODE (char*)0x15CAB866
#define VAR_STRINP_FIXED_TEXT (char*)0x15CAB886
#define VAR_STRINP_TEXT (char*)0x15CAB852
#define VAR_STRINP_NEW_LINE (char*)0x15CAB85C
#define VAR_STRINP_ENABLE_EMPTY_STR (char*)0x15CAB864
#define VAR_STRINP_MAX_LEN (char*)0x15CAB86E
#define VAR_STRINP_MIN_LEN (char*)0x15CAB876
#define VAR_STRINP_IS_PASS_MODE (char*)0x15CAB88C
#define VAR_STRINP_OK_ON_DIEZ (char*)0x15CAB82E
#define VAR_STRINP_SET_INT_VAL (char*)0x15CAB850
#define VAR_STRINP_MIN_INT_VAL (char*)0x15CAB87A
#define VAR_STRINP_MAX_INT_VAL (char*)0x15CAB872
#define VAR_YESNO_PRE_QUESTION (char*)0x15CAB858
//#define VAR_YESNO_QUESTION (char*)0x15CAB88A
#define VAR_YESNO_YES_ACTION (char*)0x15CAB8A4
#define VAR_YESNO_NO_ACTION (char*)0x15CAB880
#define VAR_PERINP_ROWNUM (char*)0x15CAB892
#define VAR_PERINP_CURPERC (char*)0x15CAB856
#define VAR_DATEINP_DATEFORMAT (char*)0x15CAB848
#define VAR_DATEINP_DATE (char*)0x15CAB84C
#define VAR_TIMEINP_TIMEFORMAT_SEC (char*)0x15CAB898
#define VAR_TIMEINP_TIMEFORMAT (char*)0x15CAB89A
#define VAR_TIMEINP_TIME (char*)0x15CAB854

// my events ----------------------------------------------------

#define SHUTDOWN_SYSTEM_1 0x962
#define SHUTDOWN_SYSTEM_2 0x963

// base events ----------------------------------------------------

#define AB_ITEM_DESC_ICON_DISPLACE 0x2
//#define AB_ITEM_DESC_ID_DISPLACE UNDEFINED
#define AB_ITEM_DESC_NUM_DISPLACE 0x0
#define AB_ITEM_DESC_SIZE 0x18
#define AB_ITEM_FIELD_CITY 0x2D
#define AB_ITEM_FIELD_COMPANY 0x25
#define AB_ITEM_FIELD_COUNTRY 0x30
#define AB_ITEM_FIELD_DR 0x33
#define AB_ITEM_FIELD_EMAIL1 0x13
#define AB_ITEM_FIELD_EMAIL2 0x14
#define AB_ITEM_FIELD_EMAIL3 0x15
//#define AB_ITEM_FIELD_IMAGE UNDEFINED
#define AB_ITEM_FIELD_INFO 0x32
#define AB_ITEM_FIELD_NAME 0x2
#define AB_ITEM_FIELD_NEW_ITEM 0x4
#define AB_ITEM_FIELD_N_FAX 0xA
#define AB_ITEM_FIELD_N_HOME 0x8
#define AB_ITEM_FIELD_N_MOBILE 0x5
#define AB_ITEM_FIELD_N_OTHER 0xB
//#define AB_ITEM_FIELD_N_WORK UNDEFINED
#define AB_ITEM_FIELD_POST_INDEX 0x2F
#define AB_ITEM_FIELD_REGION 0x2E
//#define AB_ITEM_FIELD_RINGTONE UNDEFINED
#define AB_ITEM_FIELD_STREET 0x35
#define AB_ITEM_FIELD_TITLE 0x24
//#define AB_ITEM_FIELD_USERNAME UNDEFINED
//#define AB_ITEM_FIELD_VOICE_CMD1 UNDEFINED
//#define AB_ITEM_FIELD_VOICE_CMD2 UNDEFINED
//#define AB_ITEM_FIELD_VOICE_CMD3 UNDEFINED
//#define AB_ITEM_FIELD_VOICE_CMD4 UNDEFINED
//#define AB_ITEM_FIELD_VOICE_CMD5 UNDEFINED
#define AB_ITEM_FIELD_WEB 0x17
#define AB_ITEM_FPI 0x36
#define ACCEPT_EVENT 0x2
#define ACCESSORIES_ACCESSORY_CONNECTED_EVENT 0x517
#define ACCESSORIES_ACCESSORY_DISCONNECTED_EVENT 0x518
//#define ACCESSORIES_APPLICATION_INQUIRY_EVENT UNDEFINED
//#define ACCESSORIES_CALENDAR_APPLICATION_START_EVENT UNDEFINED
//#define ACCESSORIES_CREATE_DIALOG_EVENT UNDEFINED
//#define ACCESSORIES_CREATE_STATUS_TEXT_EVENT UNDEFINED
//#define ACCESSORIES_EMAIL_APPLICATION_START_EVENT UNDEFINED
//#define ACCESSORIES_IMAGEBROWSER_APPLICATION_START_EVENT UNDEFINED
//#define ACCESSORIES_MESSAGE_APPLICATION_START_EVENT UNDEFINED
//#define ACCESSORIES_NEW_ACCESSORY_EVENT UNDEFINED
//#define ACCESSORIES_NEW_SUBMENU_EVENT UNDEFINED
//#define ACCESSORIES_NOTES_APPLICATION_START_EVENT UNDEFINED
//#define ACCESSORIES_PHONEBOOK_APPLICATION_START_EVENT UNDEFINED
//#define ACCESSORIES_REMOVE_ACCESSORY_EVENT UNDEFINED
//#define ACCESSORIES_STATUS_TEXT_READ_EVENT UNDEFINED
//#define ACCESSORIES_WAP_APPLICATION_START_EVENT UNDEFINED
#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
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
#define ACTIVE_PROFILE_CHANGED_EVENT 0x571E
//#define ALIEN_BATTERY_CHARGER_CONNECTED_EVENT UNDEFINED
//#define ALIEN_BATTERY_CHARGER_DISCONNECTED_EVENT UNDEFINED
#define ALL_LOCKS_UNLOCKED_EVENT 0x76E
#define APP_NEEDS_VIDEOMEMORY_EVENT 0x25
//#define ASR_PLAY_STORED_SPEECH_RESULT_EVENT UNDEFINED
#define ASR_TAG_PLAYED_EVENT 0x77A
#define BACKLIGHT_RESTORE_EVENT 0x77C
//#define BATTERY_CAPACITY_CHANGED_EVENT UNDEFINED
#define BATTERY_CHARGER_CONNECTED_EVENT 0x89D
#define BATTERY_CHARGER_DISCONNECTED_EVENT 0x89E
//#define BATTERY_CHARGING_ALERT_EVENT UNDEFINED
#define BATTERY_CHARGING_STATE_EVENT 0x89F
#define BATTERY_CONNECTED_EVENT 0x89B
//#define BATTERY_DISCONNECTED_EVENT UNDEFINED
//#define BATTERY_SYSTEM_VOLTAGE_STATUS_EVENT UNDEFINED
#define BOOK_DESTROYED_EVENT 0x21
//#define CALENDAR_APPLICATION_START_EVENT UNDEFINED
#define CALLMANAGER_CALL_END_SET_CALLTIME_EVENT 0xF47
#define CALLMANAGER_KILL_CALLBOOK_EVENT 0xF42
//#define CALL_OFF_EVENT UNDEFINED
//#define CALL_ON_EVENT UNDEFINED
#define CAMERACAPTUREKEY_LONG_PRESS_EVENT 0x4A
#define CAMERACAPTUREKEY_LONG_RELEASE_EVENT 0x4B
#define CAMERACAPTUREKEY_PRESSED_EVENT 0x48
#define CAMERACAPTUREKEY_RELEASE_EVENT 0x49
#define CAMERAFOCUSKEY_LONG_PRESS_EVENT 0x46
#define CAMERAFOCUSKEY_LONG_RELEASE_EVENT 0x47
#define CAMERAFOCUSKEY_PRESSED_EVENT 0x44
#define CAMERAFOCUSKEY_RELEASE_EVENT 0x45
#define CAMERAKEY_LONG_PRESS_EVENT 0x42
#define CAMERAKEY_LONG_RELEASE_EVENT 0x43
#define CAMERAKEY_PRESSED_EVENT 0x40
#define CAMERAKEY_RELEASE_EVENT 0x41
//#define CAMERA_APPLICATION_START_EVENT UNDEFINED
#define CAMERA_LENSCOVER_CLOSE_EVENT 0x38
#define CAMERA_LENSCOVER_OPEN_EVENT 0x37
#define CANCEL_EVENT 0x4
#define CHF_CONNECTED_EVENT 0x5E2
#define CHF_DISCONNECTED_EVENT 0x5E3
#define CLOCK_ALARMCLOCK_STATUS_EVENT 0x851
#define CLOCK_DATEANDTIME_IND_EVENT 0x850
#define CT_CORDLESS_INRANGE_EVENT 0x777
#define CT_CORDLESS_OUTRANGE_EVENT 0x778
#define DATA_DOWNLOAD_ERROR_EVENT 0x17D8
#define DB_CMD_DELETE 0x9
#define DB_CMD_DESTROY_SUBROUTINE 0x2B
#define DB_CMD_EDIT 0x6
#define DB_CMD_INFO 0x1C
#define DB_CMD_LAST 0x4B
#define DB_CMD_RENAME 0xD
#define DB_CMD_RUN 0x1
#define DB_CMD_SETITEMTEXT 0x41
#define DB_CMD_SETSAVEDICON 0x38
#define DB_CMD_SETSMALLICON 0x39
#define DB_CMD_SETTHUMBNAILICON 0x3A
#define DB_UPDATE_EVENT 0x189C
#define DISPATCH_ALARMRECURSTATUS_IND_EVENT 0x852
//#define DISPATCH_NITZTIMEINFORMATION_IND_EVENT UNDEFINED
//#define DISPATCH_NITZ_NETWORK_NAME_IND_EVENT UNDEFINED
#define DISPATCH_OFFICE_HF_STATE_CHANGED_EVENT 0x6786
//#define DISPATCH_SIM_SELECTED_LINE_CHANGED_EVENT UNDEFINED
//#define DOWNLOAD_COMPLETED_EVENT UNDEFINED
//#define DOWNLOAD_ERROR_EVENT UNDEFINED
//#define DOWNLOAD_PROGRESS_EVENT UNDEFINED
//#define EMAIL_APPLICATION_START_EVENT UNDEFINED
#define ERROR_EVENT 0x5
//#define EVENT_ID_ICA_AUTHENTICATIONSTATUSINFORMATION_REQUEST UNDEFINED
//#define EVENT_ID_ICA_AUTHENTICATIONSTATUSINFORMATION_RESPONSE UNDEFINED
//#define EVENT_ID_ICA_CONNECTIONSTATUSINFORMATION_REQUEST UNDEFINED
//#define EVENT_ID_ICA_CONNECTIONSTATUSINFORMATION_RESPONSE UNDEFINED
//#define EVENT_ID_ICA_DATACOUNTERS_ENDSESSION_REQUEST UNDEFINED
//#define EVENT_ID_ICA_DATACOUNTERS_ENDSESSION_RESPONSE UNDEFINED
//#define EVENT_ID_ICA_DATACOUNTERS_REQUEST UNDEFINED
//#define EVENT_ID_ICA_DATACOUNTERS_RESPONSE UNDEFINED
//#define EXTERNAL_ACCESSORY_EVENT UNDEFINED
#define FLIP_CLOSE_EVENT 0x32
//#define FLIP_CLOSE_SHIFT_EVENT UNDEFINED
#define FLIP_OPEN_EVENT 0x30
#define FLIP_OPEN_SHIFT_EVENT 0x31
//#define FMRADIO_MODE_CHANGED_EVENT UNDEFINED
//#define FMRADIO_RDS_DATA_RECEIVED_EVENT UNDEFINED
#define FONT_D_18B 0x112
#define FONT_D_24B 0x118
#define FONT_D_29B 0x11D
#define FONT_D_7R 0x7
#define FONT_E_100R 0x64
#define FONT_E_12B 0x10C
#define FONT_E_12R 0xC
#define FONT_E_14B 0x10E
#define FONT_E_14BI 0x30E
#define FONT_E_14I 0x20E
#define FONT_E_14R 0xE
#define FONT_E_16B 0x110
#define FONT_E_16BI 0x310
#define FONT_E_16I 0x210
#define FONT_E_16R 0x10
#define FONT_E_18B 0x112
#define FONT_E_18BI 0x312
#define FONT_E_18I 0x212
#define FONT_E_18R 0x12
#define FONT_E_20B 0x114
#define FONT_E_20BI 0x314
#define FONT_E_20I 0x214
#define FONT_E_20R 0x14
#define FONT_E_22B 0x116
#define FONT_E_22BI 0x316
#define FONT_E_22I 0x216
#define FONT_E_22R 0x16
#define FONT_E_24B 0x118
#define FONT_E_24BI 0x318
#define FONT_E_24I 0x218
#define FONT_E_24R 0x18
#define FONT_E_25B 0x119
#define FONT_E_25BI 0x319
#define FONT_E_25I 0x219
#define FONT_E_25R 0x19
#define FONT_E_30R 0x1E
#define FONT_E_36R 0x24
#define FONT_E_40R 0x28
#define FONT_E_60R 0x3C
#define FONT_E_75R 0x49
#define FONT_E_8R 0x8
//#define FONT_ICON_16BIT_V2 UNDEFINED
//#define FONT_ICON_2BIT_V2_2NDLCD UNDEFINED
#define FS_STATUS_EVENT 0x77B
#define GAMEINTERNALKEYA_PRESSED_EVENT 0x7E
#define GAMEINTERNALKEYB_PRESSED_EVENT 0x7F
#define GOMUSICKEY_LONG_PRESSED_EVENT 0x59
#define GOMUSICKEY_PRESSED_EVENT 0x58
#define HANDLE_TIMEZONE_RESULT_EVENT 0x684C
#define ICON_OLD_GREEN_PHONE 0xF87F
#define ICON_WRITE_NEW 0x52D
//#define IMAGEBROWSER_APPLICATION_START_EVENT UNDEFINED
#define IMODEKEY_LONG_PRESSED_EVENT 0x56
#define IMODEKEY_PRESSED_EVENT 0x55
//#define INCOMING_MT_CALL_EVENT UNDEFINED
#define IR_AUTO_OFF_TIMER_EVENT 0x6785
#define JACKKNIFE_CLOSE_EVENT 0x34
#define JACKKNIFE_OPEN_EVENT 0x33
#define JOYSTICK_DOWN_PRESSED_EVENT 0x77
#define JOYSTICK_LEFT_PRESSED_EVENT 0x78
#define JOYSTICK_RIGHT_PRESSED_EVENT 0x79
#define JOYSTICK_UP_PRESSED_EVENT 0x76
#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_LONG_PRESSED_EVENT 0x5EF5
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_LONG_RELEASE_EVENT 0x5EF6
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_PRESSED_EVENT 0x5EF4
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_PRESS_EVENT 0x5EF3
#define KEYLOCK_BYPASS_VOLUMEDOWN_LONG_EVENT 0x5EFA
#define KEYLOCK_BYPASS_VOLUMEDOWN_REPEAT_EVENT 0x5EFC
#define KEYLOCK_BYPASS_VOLUMEDOWN_SHORT_EVENT 0x5EF8
#define KEYLOCK_BYPASS_VOLUMEUP_LONG_EVENT 0x5EF9
#define KEYLOCK_BYPASS_VOLUMEUP_REPEAT_EVENT 0x5EFB
#define KEYLOCK_BYPASS_VOLUMEUP_SHORT_EVENT 0x5EF7
//#define KEYLOCK_BYPASS_VOLUME_10_SEC_EVENT UNDEFINED
#define KEYPLAYSTOP_LONG_PRESSED_EVENT 0x5B
#define KEYPLAYSTOP_PRESSED_EVENT 0x5A
#define KEY_CAMERA_FOCUS 0x30
#define KEY_CAMERA_SHOT 0x31
#define KEY_DEL 0x5
#define KEY_DIEZ 0x23
#define KEY_DIGITAL_0 0x18
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4
#define KEY_FLIP_CLOSE 0x4E
#define KEY_FLIP_OPEN 0x4D
#define KEY_GAME_A 0x4B
#define KEY_GAME_B 0x4C
#define KEY_JACKKNIFE_CLOSE 0x50
#define KEY_JACKKNIFE_OPEN 0x4F
#define KEY_LEFT 0xF
#define KEY_LEFT_SOFT 0x2
#define KEY_LENS_COVER_CLOSE 0x54
#define KEY_LENS_COVER_OPEN 0x53
#define KEY_MEDIAPLAYER 0x28
#define KEY_OPERATOR 0x25
#define KEY_PHF 0x56
#define KEY_PHF1 0x57
#define KEY_PHF_ENDOF 0x58
//#define KEY_PLAY UNDEFINED
#define KEY_POWER 0x1
#define KEY_RIGHT 0xB
#define KEY_RIGHT_SOFT 0x3
#define KEY_SLIDER_CLOSE 0x52
#define KEY_SLIDER_OPEN 0x51
#define KEY_STAR 0x22
#define KEY_TASK 0x24
#define KEY_UP 0x9
#define KEY_VOL_DOWN 0x17
#define KEY_VOL_UP 0x16
#define LAMPKEY_LONG_PRESS_EVENT 0x75
#define LAMPKEY_PRESSED_EVENT 0x74
#define LOCKKEYSWITCH_OFF_EVENT 0x52
#define LOCKKEYSWITCH_ON_EVENT 0x51
#define LOCKKEY_EVENT 0x50
#define LONG_ACCEPT_EVENT 0x6
#define LONG_PHONE_NUMBER_SEND_EVENT 0x83A
#define MAGIC_WORD_DETECT_EVENT 0x779
#define MAIN_DISPLAY_OVERLAY_MODE_OFF 0x29
#define MAIN_DISPLAY_OVERLAY_MODE_ON 0x28
#define MAIN_WINDOW_GOT_FOCUS_EVENT 0x11
#define MAIN_WINDOW_LOST_FOCUS_EVENT 0x12
#define MAIN_WINDOW_MINIMIZED_EVENT 0x15
#define MAIN_WINDOW_RESTORED_EVENT 0x16
#define MASTER_RESET_ALL_EVENT 0x684E
#define MASTER_RESET_VALUES_EVENT 0x684D
//#define MASTER_SESSION_WINDOW_GOT_FOCUS_EVENT UNDEFINED
//#define MASTER_SESSION_WINDOW_LOST_FOCUS_EVENT UNDEFINED
#define MC_PHONE_LOCK_OPEN_CNF_EVENT 0x770
#define MC_PHONE_LOCK_STATUS_IND_EVENT 0x76F
#define MEDIAPLAYERKEY_LONG_PRESSED_EVENT 0x5E
#define MEDIAPLAYERKEY_LONG_RELEASE_EVENT 0x5F
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x5D
#define MEDIAPLAYERKEY_PRESS_EVENT 0x5C
//#define MEDIAPLAYER_APPLICATION_START_EVENT UNDEFINED
#define MEMORYMANAGER_FILESYSTEM_FULL_EVENT 0x678C
//#define MEMORYSTICK_INSERTED_EVENT UNDEFINED
//#define MEMORYSTICK_REMOVED_EVENT UNDEFINED
//#define MESSAGE_APPLICATION_START_EVENT UNDEFINED
//#define MESSAGINGKEY_PRESSED_EVENT UNDEFINED
#define MISSED_CALL_EVENT 0xF45
//#define MMI_LANGUAGE_CHANGED_EVENT UNDEFINED
#define MONITOR_HEAP_EVENT 0x7211
#define MSGBOX_ACCEPT_EVENT 0x835
#define MSGBOX_CANCEL_EVENT 0x837
#define MSGBOX_PREVIOUS_EVENT 0x836
#define MSG_CONSUMED_META_EVENT 0x1
#define MULTIKEY_LONG_PRESSED_EVENT 0x71
#define MULTIKEY_PRESSED_EVENT 0x6F
#define MUTE_EVENT 0x83D
//#define NEW_UNIQUE_ACCESSORY_EVENT UNDEFINED
#define NIL_EVENT 0x0
//#define NOTES_APPLICATION_START_EVENT UNDEFINED
#define ONGOINGCALL_CALL_CONNECTED_EVENT 0xE83
#define ONGOINGCALL_CALL_START_EVENT 0xE84
#define ONGOINGCALL_SET_CALLCOST_EVENT 0xF4A
#define ONGOINGCALL_SET_CALLTIME_EVENT 0xF49
#define ONGOINGCALL_SPEAKER_ONOFF_EVENT 0xEB0
#define ONOFFKEY_LONG_PRESS_EVENT 0x2C
#define ONOFFKEY_SHORT_PRESS_EVENT 0x2D
#define ON_CALLMANAGER_EVENT 0xF46
#define OPERATORKEY_LONG_PRESSED_EVENT 0x54
#define OPERATORKEY_PRESSED_EVENT 0x53
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
//#define PB_STATUS_CHANGED_EVENT UNDEFINED
#define PHF_ENDOF_PRESSED_EVENT 0x3B
#define PHF_PRESSED_EVENT 0x39
#define PHF_SEND_PRESSED_EVENT 0x3A
//#define PHONEBOOK_APPLICATION_START_EVENT UNDEFINED
#define PHONEBOOK_CONTACT_CHANGED_EVENT 0x502A
#define PHONEBOOK_CONTACT_CREATED_EVENT 0x5029
#define PHONEBOOK_CONTACT_DELETED_EVENT 0x502B
//#define PHONE_IN_STBY_EVENT UNDEFINED
#define PHONE_NUMBER_SEND_EVENT 0x839
#define PREVIOUS_EVENT 0x3
//#define PREVIOUS_IN_STBY_IDLE_EVENT UNDEFINED
#define PROFILE_ACTIVATED_EVENT 0x853
#define PROFILE_ACTIVATED_SECOND_EVENT 0x5720
#define PROFILE_CHANGED_EVENT 0x5721
//#define PROFILE_SETTING_CHANGED_EVENT UNDEFINED
#define PROFILE_UPDATE_TIMEOUT_EVENT 0x571D
#define PTT_INITIATE_EVENT 0x83C
#define PTT_KEY_LONG_PRESSED_EVENT 0x6D
#define PTT_KEY_LONG_RELEASE_EVENT 0x6E
#define PTT_KEY_PRESSED_EVENT 0x6B
#define PTT_KEY_RELEASE_EVENT 0x6C
#define RADIO_ACTIVATING_EVENT 0x774
#define RADIO_DEACTIVATING_EVENT 0x775
#define RADIO_OFF_EVENT 0x773
#define RADIO_ON_EVENT 0x772
#define RADIO_RECEIVE_STATUS_EVENT 0x771
#define REQUEST_CONSUMER_END_OF_DATA_EVENT 0x77F
#define REQUEST_CONSUMER_END_OF_DATA_SECOND_EVENT 0x678B
#define REQUEST_CONSUMER_GET_APPSKILL_EVENT 0x77D
#define REQUEST_CONSUMER_GET_APPSKILL_SECOND_EVENT 0x6789
#define REQUEST_CONSUMER_GET_FILENAME_EVENT 0x77E
#define REQUEST_CONSUMER_GET_FILENAME_SECOND_EVENT 0x678A
//#define RESPONSE_ALS_MSISDN_STATUS_EVENT UNDEFINED
#define RESPONSE_BTPORTSTATUS_EVENT 0x783
//#define RESPONSE_IMAGEHANDLER_DECODE_EVENT UNDEFINED
#define RESPONSE_PROFILE_RESETPROFILES_EVENT 0x5723
#define RETURN_TO_STANDBY_EVENT 0x840
#define RETURN_TO_STANDBY_REFUSED_EVENT 0x841
//#define RIGHTNOW_BUILD_OPERATOR_TAB_EVENT UNDEFINED
//#define RIGHTNOW_START_HOOK_EVENT UNDEFINED
//#define RIGHTNOW_START_OPERATOR_ACTION_EVENT UNDEFINED
//#define RIGHTNOW_START_SHORTCUT_EVENT UNDEFINED
//#define RIGHTNOW_START_URL_EVENT UNDEFINED
//#define RIGHTNOW_UPDATE_DATA_EVENT UNDEFINED
//#define SCREENSAVER_FINISHED_EVENT UNDEFINED
#define SECOND_DISPLAY_OVERLAY_MODE_OFF 0x2B
#define SECOND_DISPLAY_OVERLAY_MODE_ON 0x2A
#define SECOND_WINDOW_GOT_FOCUS_EVENT 0x13
#define SECOND_WINDOW_LOST_FOCUS_EVENT 0x14
#define SECOND_WINDOW_MINIMIZED_EVENT 0x17
#define SECOND_WINDOW_RESTORED_EVENT 0x18
#define SEND_EVENT 0x83B
#define SESSION_CREATED_EVENT 0x22
#define SESSION_DESTROYED_EVENT 0x23
#define SIM_INITDATA_READ_EVENT 0x776
#define SIM_STATE_ACTIVE_EVENT 0x76D
#define SLIDER_CLOSE_EVENT 0x36
#define SLIDER_OPEN_EVENT 0x35
//#define SOUNDHANDLER_APPLICATION_START_EVENT UNDEFINED
#define SPEECH_AUDIO_TERMINATED_EVENT 0x84DE
#define SPEECH_RECOGNITION_FINISHED_EVENT 0x84E6
#define SPEECH_RECOGNITION_SETUP_FAILURE_EVENT 0x84E4
#define SPEECH_RECOGNITION_SETUP_FINISHED_EVENT 0x84E5
#define SPEECH_RECOGNITION_STOPPED_EVENT 0x84E2
#define SPEECH_TRAINING_FINISHED_EVENT 0x84E1
#define SPEECH_TRAINING_STARTED_EVENT 0x84DF
#define SPEECH_TRAINING_STOPPED_EVENT 0x84E0
#define STANDBY_DISPLAY_DESKTOP_EVENT 0x7216
#define STANDBY_IDLE_EVENT 0x844
#define STANDBY_NOT_IDLE_EVENT 0x845
#define STARKEY_PRESSED_EVENT 0x6A
#define SYSTEM_MODE_CHANGED_EVENT 0x24
#define SYS_CTL_ON_SYSTEM_MODE_CHANGED_EVENT 0x84F
#define TERMINATE_SESSION_EVENT 0x842
#define TERMINATE_SESSION_REFUSED_EVENT 0x843
#define TEST_SAT_EVENT 0x83F
#define THEMEITEM_APP_GEN_BACKGROUND 0xB0
#define THEMEITEM_APP_GEN_SCROLLBAR_BACKGROUND 0xB5
#define THEMEITEM_APP_GEN_SCROLLBAR_SLIDER 0xB4
#define THEMEITEM_APP_GEN_TITLE_BACKGROUND 0xB3
#define THEMEITEM_APP_GEN_TITLE_TEXT 0xB2
#define THEMEITEM_APP_PANEL1_BACKGROUND 0xBD
#define THEMEITEM_APP_PANEL1_MMS_DATE 0xC7
#define THEMEITEM_APP_PANEL1_MMS_NAME 0xC4
#define THEMEITEM_APP_PANEL1_OUTLINE 0xBE
#define THEMEITEM_APP_PANEL1_TEXT 0xBC
#define THEMEITEM_APP_PANEL2_BACKGROUND 0xC1
#define THEMEITEM_APP_PANEL2_MMS_DATE 0xCB
#define THEMEITEM_APP_PANEL2_MMS_NAME 0xC8
#define THEMEITEM_APP_PANEL2_OUTLINE 0xC2
#define THEMEITEM_APP_PANEL2_TEXT 0xC0
#define THEMEITEM_APP_TOOLBAR_BACKGROUND 0xB7
#define THEMEITEM_APP_TOOLBAR_HIGHLIGHT 0xB8
#define THEMEITEM_APP_TOOLBAR_TEXT 0xB6
#define THEMEITEM_APP_TOOLBAR_TITLE_TEXT 0xBA
#define THEMEITEM_BACKGROUND 0x1
#define THEMEITEM_CALENDAR_WEEKVIEW_MARKINGS 0x78
#define THEMEITEM_DESKTOP 0x33
#define THEMEITEM_DESKTOP_TITLE_TEXT 0x32
#define THEMEITEM_HIGHLIGHT 0x7
#define THEMEITEM_HIGHLIGHT_TEXT 0x6
#define THEMEITEM_HOME_SCREEN 0x13
#define THEMEITEM_HOME_SCREEN_FRAME 0x24
#define THEMEITEM_HOME_SCREEN_HIGHLIGHT 0x1F
#define THEMEITEM_HOME_SCREEN_HIGHLIGHT_TEXT 0x1E
#define THEMEITEM_HOME_SCREEN_SCROLLBAR_BACKGROUND 0x23
#define THEMEITEM_HOME_SCREEN_SCROLLBAR_SLIDER 0x22
#define THEMEITEM_HOME_SCREEN_TAB 0x16
#define THEMEITEM_HOME_SCREEN_TAB_SELECTED 0x1A
#define THEMEITEM_HOME_SCREEN_TAB_TEXT 0x1C
#define THEMEITEM_HOME_SCREEN_TAB_UNSELECTED 0x18
#define THEMEITEM_HOME_SCREEN_TEXT 0x12
#define THEMEITEM_ILLUMINATION 0x7A
#define THEMEITEM_INPUT_MARKED_TEXT 0xB
#define THEMEITEM_INPUT_POPUP 0xD
#define THEMEITEM_INPUT_POPUP_FRAME 0x10
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT 0xF
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT_TEXT 0xE
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_BACKGROUND 0x9
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_SLIDER 0x8
#define THEMEITEM_INPUT_POPUP_TEXT 0xC
#define THEMEITEM_INPUT_TEXT 0xA
#define THEMEITEM_MEDIA_BACKGROUND 0x86
#define THEMEITEM_MEDIA_BACKGROUND_SEARCH 0x88
#define THEMEITEM_MEDIA_HIGHLIGHT_ICON 0x8E
#define THEMEITEM_MEDIA_HIGHLIGHT_TEXT 0x90
#define THEMEITEM_MEDIA_HIGHLIGHT_TEXT_BACKGROUND 0x91
#define THEMEITEM_MEDIA_HISTORY_BAR 0x9C
#define THEMEITEM_MEDIA_ICON 0x8A
#define THEMEITEM_MEDIA_LINE 0x92
#define THEMEITEM_MEDIA_MULTILETTER_SEARCH 0x9A
#define THEMEITEM_MEDIA_PARTICLE 0x98
#define THEMEITEM_MEDIA_PROGRESSBAR 0x9E
#define THEMEITEM_MEDIA_PROGRESSBAR_BACKGROUND 0x9F
#define THEMEITEM_MEDIA_PROGRESSBAR_BUFFER 0xA0
#define THEMEITEM_MEDIA_TEXT 0x8C
#define THEMEITEM_MEDIA_TEXT_BACKGROUND 0x8D
#define THEMEITEM_MEDIA_WALKMAN_HIGHLIGHT 0x94
#define THEMEITEM_MEDIA_WALKMAN_ICON 0xA4
#define THEMEITEM_MEDIA_WALKMAN_MODE_ICON 0xA8
#define THEMEITEM_MEDIA_WALKMAN_PARTICLE 0x96
#define THEMEITEM_MEDIA_WALKMAN_STATE_ICON 0xA6
#define THEMEITEM_MEDIA_WHEEL_ICON 0xA2
#define THEMEITEM_MINIPOPUP_BACKGROUND 0xAA
#define THEMEITEM_MINIPOPUP_OUTLINE 0xAC
#define THEMEITEM_MINIPOPUP_TEXT 0xAE
#define THEMEITEM_MORELIST 0x27
#define THEMEITEM_MORELIST_FRAME 0x30
#define THEMEITEM_MORELIST_HIGHLIGHT 0x2B
#define THEMEITEM_MORELIST_HIGHLIGHT_TEXT 0x2A
#define THEMEITEM_MORELIST_SCROLLBAR_BACKGROUND 0x2F
#define THEMEITEM_MORELIST_SCROLLBAR_SLIDER 0x2E
#define THEMEITEM_MORELIST_TEXT 0x26
#define THEMEITEM_POPUP 0x41
#define THEMEITEM_POPUP_DIM 0x4A
#define THEMEITEM_POPUP_FRAME 0x3A
#define THEMEITEM_POPUP_HIGHLIGHT 0x3D
#define THEMEITEM_POPUP_HIGHLIGHT_TEXT 0x3C
#define THEMEITEM_POPUP_SCROLLBAR_BACKGROUND 0x43
#define THEMEITEM_POPUP_SCROLLBAR_SLIDER 0x42
#define THEMEITEM_POPUP_TEXT 0x40
#define THEMEITEM_POPUP_TITLE_TEXT 0x46
#define THEMEITEM_PROGRESS_BAR_FILL 0x77
#define THEMEITEM_PROGRESS_BAR_OUTLINE 0x74
#define THEMEITEM_PROGRESS_BAR_SLIDER 0x76
#define THEMEITEM_SCROLLBAR_BACKGROUND 0x49
#define THEMEITEM_SCROLLBAR_SLIDER 0x48
#define THEMEITEM_SOFTKEY_LEFT 0x4C
#define THEMEITEM_SOFTKEY_RIGHT 0x4E
#define THEMEITEM_SOFTKEY_TEXT_LEFT 0x56
#define THEMEITEM_SOFTKEY_TEXT_LEFT_PRESSED 0x50
#define THEMEITEM_SOFTKEY_TEXT_MIDDLE 0x5A
#define THEMEITEM_SOFTKEY_TEXT_MIDDLE_PRESSED 0x54
#define THEMEITEM_SOFTKEY_TEXT_RIGHT 0x58
#define THEMEITEM_SOFTKEY_TEXT_RIGHT_PRESSED 0x52
#define THEMEITEM_STANDBY_OPERATORNAME_OUTLINE 0x63
#define THEMEITEM_STANDBY_OPERATORNAME_TEXT 0x62
#define THEMEITEM_STANDBY_TIME 0x64
#define THEMEITEM_STANDBY_TIME_OUTLINE 0x65
#define THEMEITEM_STATUSBAR_CLOCK 0x84
#define THEMEITEM_TAB 0x66
#define THEMEITEM_TAB_SELECTED 0x6C
#define THEMEITEM_TAB_TEXT 0x68
#define THEMEITEM_TAB_UNSELECTED 0x6A
#define THEMEITEM_TEXT 0x4
#define THEMEITEM_TITLE_TEXT 0x70
#define THEMEITEM_VOLUME_STAPLES 0x72
#define THEMEITEM_WAPBROWSER_TABLEBORDER 0x2
#define THEMEITEM_WAPBROWSER_UNDERLINE 0x0
#define THEMES_CHANGED_PROFILE_EVENT 0x5725
#define THEMES_CORRUPT_FILE_EVENT 0x6852
#define THEME_CHANGED_EVENT 0x6853
#define THEME_DOWNLOADED_EVENT 0x6851
//#define TIMER_SLIDERRELEASED_TIMEOUT_EVENT UNDEFINED
//#define UIBASIC_MC_ETSI_LOCK_SIM_OK_IND_EVENT UNDEFINED
#define UI_APPLICATION_VOLUMEDOWN_EVENT 0x87F2
#define UI_APPLICATION_VOLUMEDOWN_LONG_EVENT 0x87F4
#define UI_APPLICATION_VOLUMEUP_EVENT 0x87F1
#define UI_APPLICATION_VOLUMEUP_LONG_EVENT 0x87F3
#define UI_BLUETOOTH_ACTIVITY_CHANGED_EVENT 0xC44
#define UI_BLUETOOTH_STATE_CHANGED_EVENT 0xC43
//#define UI_CALLMANAGER_IDLE_EVENT UNDEFINED
#define UI_CONNECTIONMANAGER_SESSION_ACTIVE_EVENT 0x1589
#define UI_CONNECTIONMANAGER_SESSION_ACTIVITY_EVENT 0x158A
//#define UI_CONNECTIONMANAGER_SESSION_CREATED_EVENT UNDEFINED
#define UI_CONNECTIONMANAGER_SESSION_ESTABLISHED_EVENT 0x1584
#define UI_CONNECTIONMANAGER_SESSION_SUSPENDED_EVENT 0x158C
#define UI_CONNECTIONMANAGER_SESSION_TERMINATED_EVENT 0x1586
#define UI_CONTROLLED_SHUTDOWN_CONTINUE_OK_EVENT 0x781
#define UI_CONTROLLED_SHUTDOWN_OK_EVENT 0x782
#define UI_CONTROLLED_SHUTDOWN_REQUESTED_EVENT 0x838
//#define UI_EXTERNAL_KEYLOCK_ACTIVATE_EVENT UNDEFINED
//#define UI_EXTERNAL_KEYLOCK_DEACTIVATE_EVENT UNDEFINED
#define UI_FLIGHTMODE_SELECTION_EVENT 0x788
#define UI_FMRADIO_CONTROL_EVENT 0x26B1
//#define UI_FMRADIO_CREATED_EVENT UNDEFINED
#define UI_INITIATED_EVENT 0xC
#define UI_INITIATED_SPECIAL_EVENT 0xD
#define UI_INITIATING_ALARM_EVENT 0x9
#define UI_INITIATING_CHARGING_EVENT 0x8
#define UI_INITIATING_CUSTOMIZATION_EVENT 0xA
#define UI_INITIATING_EVENT 0x7
#define UI_KEYLOCK_ACTIVATE_EVENT 0x5E27
//#define UI_KEYLOCK_DEACTIVATE_EVENT UNDEFINED
#define UI_KEYLOCK_REACTIVATE_EVENT 0x5E29
#define UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT 0x40DF
#define UI_MEDIAPLAYER_CONTROL_EVENT 0x26AD
#define UI_MEDIAPLAYER_CREATED_EVENT 0x40D9
//#define UI_MEDIAPLAYER_DESTROYED_EVENT UNDEFINED
#define UI_MEDIAPLAYER_NEXT_TRACK_EVENT 0x40E5
//#define UI_MEDIAPLAYER_PAUSE_PRESSED_EVENT UNDEFINED
//#define UI_MEDIAPLAYER_PLAY_PRESSED_EVENT UNDEFINED
#define UI_MEDIAPLAYER_PREV_TRACK_EVENT 0x40E4
//#define UI_MEDIAPLAYER_STOP_PRESSED_EVENT UNDEFINED
//#define UI_MEDIAPLAYER_VIDEO_CREATED_EVENT UNDEFINED
//#define UI_MEDIAPLAYER_VIDEO_PLAYING_TIME_EVENT UNDEFINED
//#define UI_MEDIAPLAYER_VOLUMEDOWN_EVENT UNDEFINED
//#define UI_MEDIAPLAYER_VOLUMEUP_EVENT UNDEFINED
#define UI_MESSAGING_MMS_RECEIVED_EVENT 0x3BCF
#define UI_MESSAGING_MMS_SENDING_CANCELED_EVENT 0x3BC8
#define UI_MESSAGING_MMS_SENDING_EVENT 0x3BD3
#define UI_MESSAGING_MMS_SENT_EVENT 0x3BD4
#define UI_MESSAGING_SMS_RECEIVED_EVENT 0x3BCA
#define UI_MESSAGING_SMS_SENDING_ERROR_EVENT 0x3BD2
#define UI_MESSAGING_SMS_SENDING_EVENT 0x3BD1
#define UI_MESSAGING_SMS_SENT_EVENT 0x3BD0
//#define UI_NEW_CALL_CONNECTED_EVENT UNDEFINED
#define UI_OBEX_ACCEPT_FILE_REQUEST_EVENT 0x4C92
#define UI_OBEX_CONNECTING_STATE_EVENT 0x4C9D
#define UI_OBEX_FILE_ACCEPTED_EVENT 0x4C93
#define UI_OBEX_FTP_SEND_FILE_EVENT 0x4C94
#define UI_OBEX_RECEIVE_FAILED_EVENT 0x4C91
#define UI_OBEX_REFRESH_RECEIVE_PROGRESS_EVENT 0x4C95
#define UI_OBEX_REFRESH_TRANSFER_PROGRESS_EVENT 0x4C9C
#define UI_OBEX_STATE_CHANGED_EVENT 0x4C96
#define UI_OBEX_TRANSFER_FAILED_EVENT 0x4C9E
#define UI_OBEX_UPD_STATE_EVENT 0x4C9F
#define UI_PRELOCK_ACTIVATE_EVENT 0x5E25
#define UI_PRELOCK_DEACTIVATE_EVENT 0x5E26
#define UI_SCREENSAVER_ACTIVATE_EVENT 0x5E2D
#define UI_SCREENSAVER_DEACTIVATE_EVENT 0x5E2E
#define UI_SCREENSAVER_FINISHED_EVENT 0x5E2F
#define UI_SCREENSAVER_SHOW_INFO_EVENT 0x5E30
//#define UI_SECRET_SEQ_DETECTED_EVENT UNDEFINED
#define UI_SETTINGS_ICB_SIM_APPLICATION_TOOLKIT_REFRESH_EVENT 0x6787
#define UI_SLEEPMODE_ACTIVATED_EVENT 0x5EFE
#define UI_SLEEPMODE_ACTIVATE_EVENT 0x5E2B
#define UI_SLEEPMODE_DEACTIVATED_EVENT 0x5EFF
#define UI_SLEEPMODE_DEACTIVATE_EVENT 0x5E2C
#define UI_STANDBY_TICKER_CREATED_EVENT 0x846
//#define UI_STANDBY_TICKER_OPEN_BROWSER_EVENT UNDEFINED
#define UI_STANDBY_UNFOCUS_EVENT 0x848
//#define UI_TRANSFER_FOCUS_BY_SESSION_MANAGER_EVENT UNDEFINED
//#define UI_UTIL_SIM_GREETING_READ_EVENT UNDEFINED
#define UNMUTE_EVENT 0x83E
#define UPDATE_BATTERY_ICON_EVENT 0x899
#define UPDATE_CUSTOMIZATION_PROGRESS_EVENT 0x780
#define USER_INACTIVITY_EVENT 0x26
#define USSD_RECIEVED_EVENT 0x46CE
//#define USSD_REQUEST_RECIEVED_EVENT UNDEFINED
#define VAD_DELETED_EVENT 0x84D1
#define VAD_TAG_PLAYED_EVENT 0x8599
#define VC_ANSWER_ACCEPT_RECOGNISED_EVENT 0x85A5
#define VC_ANSWER_ACTIVATED_EVENT 0x85A2
#define VC_ANSWER_DEACTIVATED_EVENT 0x85A3
#define VC_ANSWER_REJECT_RECOGNISED_EVENT 0x85A6
#define VC_ANSWER_SERVICE_FAILED_EVENT 0x85A4
#define VC_MAGICWORD_ACTIVATED_EVENT 0x859A
#define VC_MAGICWORD_DEACTIVATED_EVENT 0x859B
#define VC_MAGICWORD_RECOGNISED_EVENT 0x859D
#define VC_MAGICWORD_SERVICE_FAILED_EVENT 0x859C
#define VC_NAMEDIAL_ACTIVATED_EVENT 0x859E
#define VC_NAMEDIAL_DEACTIVATED_EVENT 0x859F
#define VC_NAMEDIAL_RECOGNISED_EVENT 0x85A1
#define VC_NAMEDIAL_SERVICE_FAILED_EVENT 0x85A0
#define VC_START_ANSWER_EVENT 0x84D7
#define VC_START_MAGICWORD_EVENT 0x84D3
#define VC_START_NAMEDIAL_EVENT 0x84D5
#define VC_STOP_ANSWER_EVENT 0x84D8
#define VC_STOP_MAGICWORD_EVENT 0x84D4
#define VC_STOP_NAMEDIAL_EVENT 0x84D6
//#define VIDEOCALLKEY_LONG_PRESS_EVENT UNDEFINED
#define VIDEOCALLKEY_PRESSED_EVENT 0x57
#define VN_BUTTON_LONG_PRESS_EVENT 0x2F
#define VN_BUTTON_SHORT_PRESS_EVENT 0x2E
#define VOLUMECONTROL_DECREASE_EVENT 0x785
#define VOLUMECONTROL_DECREASE_REPEAT_EVENT 0x787
#define VOLUMECONTROL_INCREASE_EVENT 0x784
#define VOLUMECONTROL_INCREASE_REPEAT_EVENT 0x786
#define VOLUMEDOWNKEY_LONG_PRESS_EVENT 0x64
#define VOLUMEDOWNKEY_LONG_RELEASE_EVENT 0x69
#define VOLUMEDOWNKEY_PRESSED_EVENT 0x68
#define VOLUMEDOWNKEY_REPEAT_EVENT 0x65
#define VOLUMEDOWNKEY_SHORT_PRESS_EVENT 0x63
#define VOLUMEUPKEY_LONG_PRESS_EVENT 0x61
#define VOLUMEUPKEY_LONG_RELEASE_EVENT 0x67
#define VOLUMEUPKEY_PRESSED_EVENT 0x66
#define VOLUMEUPKEY_REPEAT_EVENT 0x62
#define VOLUMEUPKEY_SHORT_PRESS_EVENT 0x60
//#define WAP_APPLICATION_START_EVENT UNDEFINED


//unused ----------------------
#define CAMERAONOFFKEY_LONG_PRESS_EVENT 0x4E
#define CAMERAONOFFKEY_LONG_RELEASE_EVENT 0x4F
#define CAMERAONOFFKEY_PRESSED_EVENT 0x4C
#define CAMERAONOFFKEY_RELEASE_EVENT 0x4D
#define ENABLELIST_REFRESH_EVENT 0x82
#define FM_RADIO_ACCESSORY_CONNECTED_EVENT 0x214B
#define FM_RADIO_ACCESSORY_DISCONNECTED_EVENT 0x214C
#define FM_RADIO_ACCESSORY_REPORT_EVENT 0x214D
#define FM_RADIO_APPLICATION_EXIT_EVENT 0x2155
#define FM_RADIO_APPLICATION_STARTED_EVENT 0x21FD
#define FM_RADIO_AUDIOCONTROL_CHANNEL_OPENED_EVENT 0x2148
#define FM_RADIO_AUDIOCONTROL_OPENRESULT_EVENT 0x2149
#define FM_RADIO_AUDIOCONTROL_RESUME_EVENT 0x2147
#define FM_RADIO_AUDIOCONTROL_SUSPEND_EVENT 0x2146
#define FM_RADIO_AUDIOCONTROL_WATCHDOG_EVENT 0x214A
#define FM_RADIO_FIRST_EXTEVENT 0x21FC
#define FM_RADIO_LAST_EVENT 0x2156
#define FM_RADIO_LAST_EXTEVENT 0x21FE
#define FM_RADIO_MEDIA_CENTER_GRAB_RESOURCE_FAILURE_EVENT 0x2153
#define FM_RADIO_MEDIA_CENTER_GRAB_RESOURCE_SUCCESS_EVENT 0x2152
#define FM_RADIO_MEDIA_CENTER_ONCLOSE_EVENT 0x2154
#define FM_RADIO_MINIMIZE_REQUESTED_EVENT 0x2150
#define FM_RADIO_ON_AF_SWITCH_FREQUENCY_EVENT 0x2138
#define FM_RADIO_ON_AF_UPDATE_EVENT 0x2139
#define FM_RADIO_ON_AF_UPDATE_FINISHED_EVENT 0x213A
#define FM_RADIO_ON_AUTO_STORE_FINISHED_EVENT 0x2137
#define FM_RADIO_ON_ERROR_OCCURED_EVENT 0x213D
#define FM_RADIO_ON_PI_FOUND_EVENT 0x2145
#define FM_RADIO_ON_PI_SEARCH_EVENT 0x2143
#define FM_RADIO_ON_PI_SEARCH_FINISHED_EVENT 0x2144
#define FM_RADIO_ON_PS_NAME_CHANGED_EVENT 0x213C
#define FM_RADIO_ON_PTY_TYPE_CHANGED_EVENT 0x213B
#define FM_RADIO_ON_RDS_STATUS_CHANGED_EVENT 0x2141
#define FM_RADIO_ON_RECEPTION_LEVEL_CHANGED_EVENT 0x213E
#define FM_RADIO_ON_SEARCH_FREQUENCY_FINISHED_EVENT 0x2135
#define FM_RADIO_ON_STEREO_RECEPTION_CHANGED_EVENT 0x2136
#define FM_RADIO_ON_TA_END_TRANSMISSION_EVENT 0x2140
#define FM_RADIO_ON_TA_SWITCH_FREQUENCY_EVENT 0x213F
#define FM_RADIO_ON_TP_STATUS_CHANGED_EVENT 0x2142
#define FM_RADIO_REMOTE_CONTROL_SERVICE_ON_COMMAND_RECEIVED 0x214F
#define FM_RADIO_REMOTE_CONTROL_SERVICE_ON_KEY_ACTIVATED_EVENT 0x214E
#define FM_RADIO_SHUTDOWN_REQUESTED_EVENT 0x2151
#define KEYEXTERNALNAVIGATIONDOWN_PRESSED_EVENT 0x7C
#define KEYEXTERNALNAVIGATIONLEFT_PRESSED_EVENT 0x7D
#define KEYEXTERNALNAVIGATIONRIGHT_PRESSED_EVENT 0x7B
#define KEYEXTERNALNAVIGATIONUP_PRESSED_EVENT 0x7A
#define KEYLOCK_BYPASS_KEY_LONG_PRESS_EVENT 0x5EF1
#define KEYLOCK_BYPASS_KEY_LONG_RELEASE_EVENT 0x5EF2
#define KEYLOCK_BYPASS_KEY_PRESS_EVENT 0x5EEF
#define KEYLOCK_BYPASS_KEY_RELEASE_EVENT 0x5EF0
#define KEY_LONG_PRESS_EVENT 0x3E
#define KEY_LONG_RELEASE_EVENT 0x3F
#define KEY_PRESS_EVENT 0x3C
#define KEY_RELEASE_EVENT 0x3D
#define MAIN_WINDOW_MASTER_GOT_FOCUS_EVENT 0x19
#define MAIN_WINDOW_MASTER_LOST_FOCUS_EVENT 0x1A
#define MC_LAST_EVENT 0x377D
#define MC_MME_PLAYER_INITIATED_EVENT 0x3779
#define MC_MME_PLAYER_STATE_CHANGED_EVENT 0x377B
#define MC_MME_PLAYER_STOPPED_EVENT 0x377A
#define MC_PLAY_SOUND_SUBR_SUCCESS_EVENT 0x377C
#define MULTIKEY_LONG_RELEASE_EVENT 0x72
#define MULTIKEY_RELEASE_EVENT 0x70
#define MUSIC_RECOGNITION_LAST_EVENT 0x445F
#define MUSIC_RECOGNITION_SERVICE_ON_RESULT_EVENT 0x445D
#define MUSIC_RECOGNITION_WAP_PROFILE_SELECTED_EVENT 0x445E
#define SOUND_RECORDER_FIRST_EXT_EVENT 0x6F54
#define SOUND_RECORDER_LAST_EVENT 0x6F57
#define SOUND_RECORDER_START_EVENT 0x6F55
#define SOUND_RECORDER_STOP_EVENT 0x6F56
#define SR_AC_CHANNEL_OPENED_EVENT 0x6E95
#define SR_AC_CHANNEL_SUSPEND_EVENT 0x6E94
#define SR_AC_ON_TONE_STOPPED_EVENT 0x6E96
#define SR_LAST_EVENT 0x6E9B
#define SR_MEMORYSTICK_STATUSCHANGED_EVENT 0x6E97
#define SR_MME_PLAYER_INITIATED_EVENT 0x6E98
#define SR_MME_PLAYER_STATE_CHANGED_EVENT 0x6E9A
#define SR_MME_PLAYER_STOPPED_EVENT 0x6E99
#define SR_PLAY_SOUND_SUBR_SUCCESS_EVENT 0x6E90
#define SR_RECORDING_INTERRUPTED_EVENT 0x6E91
#define SR_RECORDING_STOPPED_EVENT 0x6E92
#define SR_RECORDING_TIME_FEEDBACK_EVENT 0x6E93
#define SR_RECORD_SOUND_SUBR_FAILED_EVENT 0x6E8F
#define SR_RECORD_SOUND_SUBR_FAILED_MEMORY_FULL_EVENT 0x6E8E
#define SR_RECORD_SOUND_SUBR_SUCCESS_EVENT 0x6E8D
#define UI_BASIC_CLOCK_ALARMCLOCK_STATUS_EVENT 0x851
#define UI_BASIC_CLOCK_DATEANDTIME_IND_EVENT 0x850
#define UI_BASIC_DISPATCH_ALARMRECURSTATUS_IND_EVENT 0x852
#define UI_BASIC_PROFILE_ACTIVATED_EVENT 0x853
#define UI_BASIC_SYS_CTL_ON_SYSTEM_MODE_CHANGED_EVENT 0x84F
#define UI_CONNECTIONMANAGER_SESSION_TERMINATE_EVENT 0x1586
#define UI_INITIATE_FLIGHT_MODE_EVENT 0xE
#define UI_KEYLOCK_ACTIVATED_EVENT 0x5EED
#define UI_KEYLOCK_DEACTIVATED_EVENT 0x5EEE
#define UI_SCREENSAVER_PROFILE_ACTIVATED_EVENT 0x5E31
#define UI_SCREENSAVER_SLIDER_CLOSE_BOOK_DESTROYED_EVENT 0x5E2A
#define UI_SETTINGS_ICBMMEPLAYER_INITIATED_EVENT 0x678F
#define USER_INACTIVITY_KEYLOCK_EVENT 0x27
#define VC_ALLOW_MAGICWORD_EVENT 0x84DA
#define VC_BTHF_PRESSED_EVENT 0x84D2
#define VC_DESTROY_VAD_BOOK_EVENT 0x84DD
#define VC_MEMORY_FULL_EVENT 0x84DC
#define VC_STARTMAGICWORDRECOGNITION_EVENT 0x84D9
#define VC_SUPPRESS_MAGICWORD_EVENT 0x84DB
#define VOLUMECONTROL_DECREASE_REPEAT_SECOND_EVENT 0x5EF8

#define TEXT_RDS          0xB97
#define TEXT_NAV_LEFT     0x22B0
#define TEXT_NAV_RIGHT    0x22B8
#define TEXT_NAV_UP       0x22BC
#define TEXT_NAV_DOWN     0x22AC

#endif
