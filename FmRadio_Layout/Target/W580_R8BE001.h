#ifndef W580_R8BE001
#error W580_R8BE001 configuration needed for this header!
#else
#ifndef _W580_R8BE001_
#define _W580_R8BE001_

#define FILE_NAME L"FMRadio_Display.cfg"
#define CONFIG_PATH L"/tpa/user/other/ZBin/Config/FmRadio"

#define POPUP_WARNING_ICN 0xEE35

#define TEXT_LAYOUT           0xFF6
#define TEXT_SETTING          0xD56
#define TEXT_ON               0x1AD
#define TEXT_OFF              0x1AC
#define TEXT_CHANGE           0x1FC
#define TEXT_QUESTION         0x1FD 
#define TEXT_SAVE             0x299
#define TEXT_LEFT             0x7CC
#define TEXT_RIGHT            0x7DC
#define TEXT_CENTRE           0x7AC
#define TEXT_IMAGE            0x39
#define TEXT_CANCEL           0x1224

#define TEXT_BACKROUND        0x1FD5
#define TEXT_ADDITIONAL       0x13BB    // L"Display Mode"

#define TEXT_COLOR            0x15F9
#define TEXT_COLOR_TEXT       0x1A04
#define TEXT_PTYPE            0x1170 
#define TEXT_COLOR_B          0x1998
#define TEXT_MODE             0x13BB
#define TEXT_SCREEN           0x106A
#define TEXT_ANIMATION        0x1A3F
#define TEXT_THEME            0xDAC

#define TEXT_RDS          0x83A
#define TEXT_NAV_LEFT     0x18FA
#define TEXT_NAV_RIGHT    0x1902
#define TEXT_NAV_UP       0x1906
#define TEXT_NAV_DOWN     0x18F6
  
#define GetFontDesc_p     ((FONT_DESC* )0x20187200)
#define GetFontCount_p    ((int* )0x20187494)
#define StatusRow_p()     ((DISP_OBJ**)0x20186E98)

#define FMRADIO_ACTION_LAYOUT 0x11

//W580_R8BE001
#define AB_ITEM_DESC_ICON_DISPLACE 0x6
#define AB_ITEM_DESC_ID_DISPLACE 0x12
#define AB_ITEM_DESC_NUM_DISPLACE 0x0
#define AB_ITEM_DESC_SIZE 0x14
#define AB_ITEM_FIELD_CITY 0x16
#define AB_ITEM_FIELD_COMPANY 0x14
#define AB_ITEM_FIELD_COUNTRY 0x19
#define AB_ITEM_FIELD_DR 0x1B
#define AB_ITEM_FIELD_EMAIL1 0x7
#define AB_ITEM_FIELD_EMAIL2 0x8
#define AB_ITEM_FIELD_EMAIL3 0x9
#define AB_ITEM_FIELD_IMAGE 0xC
#define AB_ITEM_FIELD_INFO 0x1A
#define AB_ITEM_FIELD_NAME 0x0
#define AB_ITEM_FIELD_NEW_ITEM 0x1
#define AB_ITEM_FIELD_N_FAX 0x5
#define AB_ITEM_FIELD_N_HOME 0x3
#define AB_ITEM_FIELD_N_MOBILE 0x2
#define AB_ITEM_FIELD_N_OTHER 0x6
#define AB_ITEM_FIELD_N_WORK 0x4
#define AB_ITEM_FIELD_POST_INDEX 0x18
#define AB_ITEM_FIELD_REGION 0x17
#define AB_ITEM_FIELD_RINGTONE 0xD
#define AB_ITEM_FIELD_STREET 0x15
#define AB_ITEM_FIELD_TITLE 0x13
#define AB_ITEM_FIELD_USERNAME 0xA
#define AB_ITEM_FIELD_VOICE_CMD1 0xE
#define AB_ITEM_FIELD_VOICE_CMD2 0xF
#define AB_ITEM_FIELD_VOICE_CMD3 0x10
#define AB_ITEM_FIELD_VOICE_CMD4 0x11
#define AB_ITEM_FIELD_VOICE_CMD5 0x12
#define AB_ITEM_FIELD_WEB 0xB
#define AB_ITEM_FPI 0x1C
#define ACCEPT_EVENT 0x2
#define ACCESSORIES_ACCESSORY_CONNECTED_EVENT 0x517
#define ACCESSORIES_ACCESSORY_DISCONNECTED_EVENT 0x518
#define ACCESSORIES_APPLICATION_INQUIRY_EVENT 0x523
#define ACCESSORIES_CALENDAR_APPLICATION_START_EVENT 0x51D
//#define ACCESSORIES_CREATE_DIALOG_EVENT UNDEFINED
#define ACCESSORIES_CREATE_STATUS_TEXT_EVENT 0x515
#define ACCESSORIES_EMAIL_APPLICATION_START_EVENT 0x51B
#define ACCESSORIES_IMAGEBROWSER_APPLICATION_START_EVENT 0x51E
#define ACCESSORIES_MESSAGE_APPLICATION_START_EVENT 0x519
//#define ACCESSORIES_NEW_ACCESSORY_EVENT UNDEFINED
//#define ACCESSORIES_NEW_SUBMENU_EVENT UNDEFINED
#define ACCESSORIES_NOTES_APPLICATION_START_EVENT 0x51F
#define ACCESSORIES_PHONEBOOK_APPLICATION_START_EVENT 0x51A
//#define ACCESSORIES_REMOVE_ACCESSORY_EVENT UNDEFINED
#define ACCESSORIES_STATUS_TEXT_READ_EVENT 0x516
#define ACCESSORIES_WAP_APPLICATION_START_EVENT 0x51C
#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
//#define ACTION_CLIPBOARD_COPYALL UNDEFINED
//#define ACTION_CLIPBOARD_MARKANDCOPY UNDEFINED
//#define ACTION_CLIPBOARD_PASTE UNDEFINED
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
//#define ACTION_DB_MANAGEFILE UNDEFINED
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
#define ACTIVE_PROFILE_CHANGED_EVENT 0x4C92
#define ALIEN_BATTERY_CHARGER_CONNECTED_EVENT 0x790
#define ALIEN_BATTERY_CHARGER_DISCONNECTED_EVENT 0x791
#define ALL_LOCKS_UNLOCKED_EVENT 0x772
#define APP_NEEDS_VIDEOMEMORY_EVENT 0x17
#define ASR_PLAY_STORED_SPEECH_RESULT_EVENT 0x5BCC
#define ASR_TAG_PLAYED_EVENT 0x781
#define BACKLIGHT_RESTORE_EVENT 0x783
#define BATTERY_CAPACITY_CHANGED_EVENT 0x78B
#define BATTERY_CHARGER_CONNECTED_EVENT 0x78E
#define BATTERY_CHARGER_DISCONNECTED_EVENT 0x78F
#define BATTERY_CHARGING_ALERT_EVENT 0x793
#define BATTERY_CHARGING_STATE_EVENT 0x792
#define BATTERY_CONNECTED_EVENT 0x78C
#define BATTERY_DISCONNECTED_EVENT 0x78D
#define BATTERY_SYSTEM_VOLTAGE_STATUS_EVENT 0x794
#define BOOK_DESTROYED_EVENT 0x13
#define CALENDAR_APPLICATION_START_EVENT 0x5E1
#define CALLMANAGER_CALL_END_SET_CALLTIME_EVENT 0xE1A
#define CALLMANAGER_KILL_CALLBOOK_EVENT 0xE10
//#define CALL_OFF_EVENT UNDEFINED
//#define CALL_ON_EVENT UNDEFINED
#define CAMERACAPTUREKEY_LONG_PRESS_EVENT 0x38
#define CAMERACAPTUREKEY_LONG_RELEASE_EVENT 0x39
#define CAMERACAPTUREKEY_PRESSED_EVENT 0x36
#define CAMERACAPTUREKEY_RELEASE_EVENT 0x37
#define CAMERAFOCUSKEY_LONG_PRESS_EVENT 0x34
#define CAMERAFOCUSKEY_LONG_RELEASE_EVENT 0x35
#define CAMERAFOCUSKEY_PRESSED_EVENT 0x32
#define CAMERAFOCUSKEY_RELEASE_EVENT 0x33
#define CAMERAKEY_LONG_PRESS_EVENT 0x30
#define CAMERAKEY_LONG_RELEASE_EVENT 0x31
#define CAMERAKEY_PRESSED_EVENT 0x2E
#define CAMERAKEY_RELEASE_EVENT 0x2F
#define CAMERA_APPLICATION_START_EVENT 0x5E4
#define CAMERA_LENSCOVER_CLOSE_EVENT 0x2A
#define CAMERA_LENSCOVER_OPEN_EVENT 0x29
#define CANCEL_EVENT 0x4
#define CHF_CONNECTED_EVENT 0x5E7
#define CHF_DISCONNECTED_EVENT 0x5E8
#define CLOCK_ALARMCLOCK_STATUS_EVENT 0x76E
#define CLOCK_DATEANDTIME_IND_EVENT 0x76D
#define CT_CORDLESS_INRANGE_EVENT 0x77E
#define CT_CORDLESS_OUTRANGE_EVENT 0x77F
#define DATA_DOWNLOAD_ERROR_EVENT 0x1328
#define DB_CMD_DELETE 0x9
#define DB_CMD_DESTROY_SUBROUTINE 0x2D
//#define DB_CMD_EDIT UNDEFINED
#define DB_CMD_INFO 0x1E
#define DB_CMD_LAST 0x4D
#define DB_CMD_RENAME 0xD
#define DB_CMD_RUN 0x1
//#define DB_CMD_SETITEMTEXT UNDEFINED
//#define DB_CMD_SETSAVEDICON UNDEFINED
#define DB_CMD_SETSMALLICON 0x3B
#define DB_CMD_SETTHUMBNAILICON 0x3C
//#define DB_UPDATE_EVENT UNDEFINED
#define DISPATCH_ALARMRECURSTATUS_IND_EVENT 0x76F
#define DISPATCH_NITZTIMEINFORMATION_IND_EVENT 0x4C93
#define DISPATCH_NITZ_NETWORK_NAME_IND_EVENT 0x770
#define DISPATCH_OFFICE_HF_STATE_CHANGED_EVENT 0x4C99
//#define DISPATCH_SIM_SELECTED_LINE_CHANGED_EVENT UNDEFINED
#define DOWNLOAD_COMPLETED_EVENT 0x5E5C
#define DOWNLOAD_ERROR_EVENT 0x5E5A
#define DOWNLOAD_PROGRESS_EVENT 0x5E5B
#define EMAIL_APPLICATION_START_EVENT 0x5DF
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
#define FLIP_CLOSE_EVENT 0x23
#define FLIP_CLOSE_SHIFT_EVENT 0x24
#define FLIP_OPEN_EVENT 0x21
#define FLIP_OPEN_SHIFT_EVENT 0x22
#define FMRADIO_MODE_CHANGED_EVENT 0x1902
#define FMRADIO_RDS_DATA_RECEIVED_EVENT 0x1908
//#define FONT_D_18B UNDEFINED
#define FONT_D_24B 0x3F
#define FONT_D_29B 0x40
#define FONT_D_7R 0x1
#define FONT_E_100R 0x5E
#define FONT_E_12B 0xD
#define FONT_E_12R 0xC
#define FONT_E_14B 0x12
//#define FONT_E_14BI UNDEFINED
//#define FONT_E_14I UNDEFINED
#define FONT_E_14R 0x11
#define FONT_E_16B 0x19
#define FONT_E_16BI 0x1B
#define FONT_E_16I 0x1A
#define FONT_E_16R 0x18
//#define FONT_E_18B UNDEFINED
//#define FONT_E_18BI UNDEFINED
//#define FONT_E_18I UNDEFINED
//#define FONT_E_18R UNDEFINED
#define FONT_E_20B 0x2C
#define FONT_E_20BI 0x2E
#define FONT_E_20I 0x2D
#define FONT_E_20R 0x2B
//#define FONT_E_22B UNDEFINED
//#define FONT_E_22BI UNDEFINED
//#define FONT_E_22I UNDEFINED
//#define FONT_E_22R UNDEFINED
#define FONT_E_24B 0x36
#define FONT_E_24BI 0x38
#define FONT_E_24I 0x37
#define FONT_E_24R 0x35
//#define FONT_E_25B UNDEFINED
//#define FONT_E_25BI UNDEFINED
//#define FONT_E_25I UNDEFINED
//#define FONT_E_25R UNDEFINED
#define FONT_E_30R 0x55
//#define FONT_E_36R UNDEFINED
#define FONT_E_40R 0x57
#define FONT_E_60R 0x5B
#define FONT_E_75R 0x5C
#define FONT_E_8R 0x2
#define FONT_ICON_16BIT_V2 0x48
//#define FONT_ICON_2BIT_V2_2NDLCD UNDEFINED
#define FS_STATUS_EVENT 0x782
#define GAMEINTERNALKEYA_PRESSED_EVENT 0x62
#define GAMEINTERNALKEYB_PRESSED_EVENT 0x63
#define GOMUSICKEY_LONG_PRESSED_EVENT 0x43
#define GOMUSICKEY_PRESSED_EVENT 0x42
#define HANDLE_TIMEZONE_RESULT_EVENT 0x4D58
//#define ICON_OLD_GREEN_PHONE UNDEFINED
//#define ICON_WRITE_NEW UNDEFINED
#define IMAGEBROWSER_APPLICATION_START_EVENT 0x5E2
#define IMODEKEY_LONG_PRESSED_EVENT 0x40
#define IMODEKEY_PRESSED_EVENT 0x3F
//#define INCOMING_MT_CALL_EVENT UNDEFINED
#define IR_AUTO_OFF_TIMER_EVENT 0x4C94
#define JACKKNIFE_CLOSE_EVENT 0x26
#define JACKKNIFE_OPEN_EVENT 0x25
#define JOYSTICK_DOWN_PRESSED_EVENT 0x5F
#define JOYSTICK_LEFT_PRESSED_EVENT 0x60
#define JOYSTICK_RIGHT_PRESSED_EVENT 0x61
#define JOYSTICK_UP_PRESSED_EVENT 0x5E
#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_LONG_PRESSED_EVENT 0x85A
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_LONG_RELEASE_EVENT 0x85B
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_PRESSED_EVENT 0x859
#define KEYLOCK_BYPASS_MEDIAPLAYERKEY_PRESS_EVENT 0x858
#define KEYLOCK_BYPASS_VOLUMEDOWN_LONG_EVENT 0x7A6
#define KEYLOCK_BYPASS_VOLUMEDOWN_REPEAT_EVENT 0x7A8
//#define KEYLOCK_BYPASS_VOLUMEDOWN_SHORT_EVENT UNDEFINED
#define KEYLOCK_BYPASS_VOLUMEUP_LONG_EVENT 0x7A5
#define KEYLOCK_BYPASS_VOLUMEUP_REPEAT_EVENT 0x7A7
#define KEYLOCK_BYPASS_VOLUMEUP_SHORT_EVENT 0x7A3
#define KEYLOCK_BYPASS_VOLUME_10_SEC_EVENT 0x7A9
#define KEYPLAYSTOP_LONG_PRESSED_EVENT 0x45
#define KEYPLAYSTOP_PRESSED_EVENT 0x44
//#define KEY_CAMERA_FOCUS UNDEFINED
//#define KEY_CAMERA_SHOT UNDEFINED
#define KEY_DEL 0x5
#define KEY_DIEZ 0x1E
#define KEY_DIGITAL_0 0x13
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4
#define KEY_FLIP_CLOSE 0x40
#define KEY_FLIP_OPEN 0x3F
//#define KEY_GAME_A UNDEFINED
//#define KEY_GAME_B UNDEFINED
//#define KEY_JACKKNIFE_CLOSE UNDEFINED
//#define KEY_JACKKNIFE_OPEN UNDEFINED
#define KEY_LEFT 0xF
#define KEY_LEFT_SOFT 0x2
//#define KEY_LENS_COVER_CLOSE UNDEFINED
//#define KEY_LENS_COVER_OPEN UNDEFINED
#define KEY_MEDIAPLAYER 0x23
//#define KEY_OPERATOR UNDEFINED
//#define KEY_PHF UNDEFINED
//#define KEY_PHF1 UNDEFINED
//#define KEY_PHF_ENDOF UNDEFINED
//#define KEY_PLAY UNDEFINED
#define KEY_POWER 0x1
#define KEY_RIGHT 0xB
#define KEY_RIGHT_SOFT 0x3
#define KEY_SLIDER_CLOSE 0x40
#define KEY_SLIDER_OPEN 0x3F
#define KEY_STAR 0x1D
#define KEY_TASK 0x1F
#define KEY_UP 0x9
#define KEY_VOL_DOWN 0x12
#define KEY_VOL_UP 0x11
#define LAMPKEY_LONG_PRESS_EVENT 0x5D
#define LAMPKEY_PRESSED_EVENT 0x5C
#define LOCKKEYSWITCH_OFF_EVENT 0x3C
#define LOCKKEYSWITCH_ON_EVENT 0x3B
#define LOCKKEY_EVENT 0x3A
#define LONG_ACCEPT_EVENT 0x6
#define LONG_PHONE_NUMBER_SEND_EVENT 0x842
#define MAGIC_WORD_DETECT_EVENT 0x780
#define MAIN_DISPLAY_OVERLAY_MODE_OFF 0x1A
#define MAIN_DISPLAY_OVERLAY_MODE_ON 0x19
#define MAIN_WINDOW_GOT_FOCUS_EVENT 0x9
#define MAIN_WINDOW_LOST_FOCUS_EVENT 0xA
#define MAIN_WINDOW_MINIMIZED_EVENT 0xD
#define MAIN_WINDOW_RESTORED_EVENT 0xE
#define MASTER_RESET_ALL_EVENT 0x4D5A
#define MASTER_RESET_VALUES_EVENT 0x4D59
#define MASTER_SESSION_WINDOW_GOT_FOCUS_EVENT 0x11
#define MASTER_SESSION_WINDOW_LOST_FOCUS_EVENT 0x12
#define MC_PHONE_LOCK_OPEN_CNF_EVENT 0x774
#define MC_PHONE_LOCK_STATUS_IND_EVENT 0x773
#define MEDIAPLAYERKEY_LONG_PRESSED_EVENT 0x48
#define MEDIAPLAYERKEY_LONG_RELEASE_EVENT 0x49
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x47
#define MEDIAPLAYERKEY_PRESS_EVENT 0x46
#define MEDIAPLAYER_APPLICATION_START_EVENT 0x5E5
#define MEMORYMANAGER_FILESYSTEM_FULL_EVENT 0x4C9F
#define MEMORYSTICK_INSERTED_EVENT 0x31B4
#define MEMORYSTICK_REMOVED_EVENT 0x31B5
#define MESSAGE_APPLICATION_START_EVENT 0x5DD
#define MESSAGINGKEY_PRESSED_EVENT 0x64
#define MISSED_CALL_EVENT 0xE18
#define MMI_LANGUAGE_CHANGED_EVENT 0x4C98
#define MONITOR_HEAP_EVENT 0x797
#define MSGBOX_ACCEPT_EVENT 0x83D
#define MSGBOX_CANCEL_EVENT 0x83F
#define MSGBOX_PREVIOUS_EVENT 0x83E
#define MSG_CONSUMED_META_EVENT 0x1
#define MULTIKEY_LONG_PRESSED_EVENT 0x5A
#define MULTIKEY_PRESSED_EVENT 0x59
#define MUTE_EVENT 0x845
#define NEW_UNIQUE_ACCESSORY_EVENT 0x4C95
#define NIL_EVENT 0x0
#define NOTES_APPLICATION_START_EVENT 0x5E3
#define ONGOINGCALL_CALL_CONNECTED_EVENT 0xD57
#define ONGOINGCALL_CALL_START_EVENT 0xD58
#define ONGOINGCALL_SET_CALLCOST_EVENT 0xD80
#define ONGOINGCALL_SET_CALLTIME_EVENT 0xD7F
#define ONGOINGCALL_SPEAKER_ONOFF_EVENT 0xD82
#define ONOFFKEY_LONG_PRESS_EVENT 0x1D
#define ONOFFKEY_SHORT_PRESS_EVENT 0x1E
#define ON_CALLMANAGER_EVENT 0xE19
#define OPERATORKEY_LONG_PRESSED_EVENT 0x3E
#define OPERATORKEY_PRESSED_EVENT 0x3D
#define PAGE_ENTER_EVENT 0x7
#define PAGE_EXIT_EVENT 0x8
//#define PB_STATUS_CHANGED_EVENT UNDEFINED
#define PHF_ENDOF_PRESSED_EVENT 0x2D
#define PHF_PRESSED_EVENT 0x2B
#define PHF_SEND_PRESSED_EVENT 0x2C
#define PHONEBOOK_APPLICATION_START_EVENT 0x5DE
#define PHONEBOOK_CONTACT_CHANGED_EVENT 0x3C3F
#define PHONEBOOK_CONTACT_CREATED_EVENT 0x3C3E
#define PHONEBOOK_CONTACT_DELETED_EVENT 0x3C40
//#define PHONE_IN_STBY_EVENT UNDEFINED
#define PHONE_NUMBER_SEND_EVENT 0x841
#define PREVIOUS_EVENT 0x3
#define PREVIOUS_IN_STBY_IDLE_EVENT 0x84E
#define PROFILE_ACTIVATED_EVENT 0x77D
#define PROFILE_ACTIVATED_SECOND_EVENT 0x4C96
#define PROFILE_CHANGED_EVENT 0x4C97
#define PROFILE_SETTING_CHANGED_EVENT 0x4C90
#define PROFILE_UPDATE_TIMEOUT_EVENT 0x4C91
#define PTT_INITIATE_EVENT 0x844
#define PTT_KEY_LONG_PRESSED_EVENT 0x57
#define PTT_KEY_LONG_RELEASE_EVENT 0x58
#define PTT_KEY_PRESSED_EVENT 0x55
#define PTT_KEY_RELEASE_EVENT 0x56
#define RADIO_ACTIVATING_EVENT 0x778
#define RADIO_DEACTIVATING_EVENT 0x779
#define RADIO_OFF_EVENT 0x777
#define RADIO_ON_EVENT 0x776
#define RADIO_RECEIVE_STATUS_EVENT 0x775
#define REQUEST_CONSUMER_END_OF_DATA_EVENT 0x786
//#define REQUEST_CONSUMER_END_OF_DATA_SECOND_EVENT UNDEFINED
#define REQUEST_CONSUMER_GET_APPSKILL_EVENT 0x784
//#define REQUEST_CONSUMER_GET_APPSKILL_SECOND_EVENT UNDEFINED
#define REQUEST_CONSUMER_GET_FILENAME_EVENT 0x785
//#define REQUEST_CONSUMER_GET_FILENAME_SECOND_EVENT UNDEFINED
//#define RESPONSE_ALS_MSISDN_STATUS_EVENT UNDEFINED
#define RESPONSE_BTPORTSTATUS_EVENT 0x78A
//#define RESPONSE_IMAGEHANDLER_DECODE_EVENT UNDEFINED
#define RESPONSE_PROFILE_RESETPROFILES_EVENT 0x4CA1
#define RETURN_TO_STANDBY_EVENT 0x848
#define RETURN_TO_STANDBY_REFUSED_EVENT 0x849
#define RIGHTNOW_BUILD_OPERATOR_TAB_EVENT 0x79A
#define RIGHTNOW_START_HOOK_EVENT 0x79C
#define RIGHTNOW_START_OPERATOR_ACTION_EVENT 0x79E
#define RIGHTNOW_START_SHORTCUT_EVENT 0x79B
#define RIGHTNOW_START_URL_EVENT 0x79D
#define RIGHTNOW_UPDATE_DATA_EVENT 0x799
#define SCREENSAVER_FINISHED_EVENT 0x77C
#define SECOND_DISPLAY_OVERLAY_MODE_OFF 0x1C
#define SECOND_DISPLAY_OVERLAY_MODE_ON 0x1B
#define SECOND_WINDOW_GOT_FOCUS_EVENT 0xB
#define SECOND_WINDOW_LOST_FOCUS_EVENT 0xC
#define SECOND_WINDOW_MINIMIZED_EVENT 0xF
#define SECOND_WINDOW_RESTORED_EVENT 0x10
#define SEND_EVENT 0x843
#define SESSION_CREATED_EVENT 0x14
#define SESSION_DESTROYED_EVENT 0x15
#define SIM_INITDATA_READ_EVENT 0x77B
#define SIM_STATE_ACTIVE_EVENT 0x771
#define SLIDER_CLOSE_EVENT 0x28
#define SLIDER_OPEN_EVENT 0x27
#define SOUNDHANDLER_APPLICATION_START_EVENT 0x5E6
#define SPEECH_AUDIO_TERMINATED_EVENT 0x5BD9
#define SPEECH_RECOGNITION_FINISHED_EVENT 0x5BE0
#define SPEECH_RECOGNITION_SETUP_FAILURE_EVENT 0x5BDE
#define SPEECH_RECOGNITION_SETUP_FINISHED_EVENT 0x5BDF
#define SPEECH_RECOGNITION_STOPPED_EVENT 0x5BDD
#define SPEECH_TRAINING_FINISHED_EVENT 0x5BDC
#define SPEECH_TRAINING_STARTED_EVENT 0x5BDA
#define SPEECH_TRAINING_STOPPED_EVENT 0x5BDB
#define STANDBY_DISPLAY_DESKTOP_EVENT 0x798
#define STANDBY_IDLE_EVENT 0x84C
#define STANDBY_NOT_IDLE_EVENT 0x84D
#define STARKEY_PRESSED_EVENT 0x54
#define SYSTEM_MODE_CHANGED_EVENT 0x16
#define SYS_CTL_ON_SYSTEM_MODE_CHANGED_EVENT 0x795
#define TERMINATE_SESSION_EVENT 0x84A
#define TERMINATE_SESSION_REFUSED_EVENT 0x84B
#define TEST_SAT_EVENT 0x847
//#define THEMEITEM_APP_GEN_BACKGROUND UNDEFINED
//#define THEMEITEM_APP_GEN_SCROLLBAR_BACKGROUND UNDEFINED
//#define THEMEITEM_APP_GEN_SCROLLBAR_SLIDER UNDEFINED
//#define THEMEITEM_APP_GEN_TITLE_BACKGROUND UNDEFINED
//#define THEMEITEM_APP_GEN_TITLE_TEXT UNDEFINED
//#define THEMEITEM_APP_PANEL1_BACKGROUND UNDEFINED
//#define THEMEITEM_APP_PANEL1_MMS_DATE UNDEFINED
//#define THEMEITEM_APP_PANEL1_MMS_NAME UNDEFINED
//#define THEMEITEM_APP_PANEL1_OUTLINE UNDEFINED
//#define THEMEITEM_APP_PANEL1_TEXT UNDEFINED
//#define THEMEITEM_APP_PANEL2_BACKGROUND UNDEFINED
//#define THEMEITEM_APP_PANEL2_MMS_DATE UNDEFINED
//#define THEMEITEM_APP_PANEL2_MMS_NAME UNDEFINED
//#define THEMEITEM_APP_PANEL2_OUTLINE UNDEFINED
//#define THEMEITEM_APP_PANEL2_TEXT UNDEFINED
//#define THEMEITEM_APP_TOOLBAR_BACKGROUND UNDEFINED
//#define THEMEITEM_APP_TOOLBAR_HIGHLIGHT UNDEFINED
//#define THEMEITEM_APP_TOOLBAR_TEXT UNDEFINED
//#define THEMEITEM_APP_TOOLBAR_TITLE_TEXT UNDEFINED
#define THEMEITEM_BACKGROUND 0x1
#define THEMEITEM_CALENDAR_WEEKVIEW_MARKINGS 0x72
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
#define THEMEITEM_ILLUMINATION 0x74
#define THEMEITEM_INPUT_MARKED_TEXT 0xB
#define THEMEITEM_INPUT_POPUP 0xD
#define THEMEITEM_INPUT_POPUP_FRAME 0x10
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT 0xF
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT_TEXT 0xE
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_BACKGROUND 0x9
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_SLIDER 0x8
#define THEMEITEM_INPUT_POPUP_TEXT 0xC
#define THEMEITEM_INPUT_TEXT 0xA
//#define THEMEITEM_MEDIA_BACKGROUND UNDEFINED
//#define THEMEITEM_MEDIA_BACKGROUND_SEARCH UNDEFINED
//#define THEMEITEM_MEDIA_HIGHLIGHT_ICON UNDEFINED
//#define THEMEITEM_MEDIA_HIGHLIGHT_TEXT UNDEFINED
//#define THEMEITEM_MEDIA_HIGHLIGHT_TEXT_BACKGROUND UNDEFINED
//#define THEMEITEM_MEDIA_HISTORY_BAR UNDEFINED
//#define THEMEITEM_MEDIA_ICON UNDEFINED
//#define THEMEITEM_MEDIA_LINE UNDEFINED
//#define THEMEITEM_MEDIA_MULTILETTER_SEARCH UNDEFINED
//#define THEMEITEM_MEDIA_PARTICLE UNDEFINED
//#define THEMEITEM_MEDIA_PROGRESSBAR UNDEFINED
//#define THEMEITEM_MEDIA_PROGRESSBAR_BACKGROUND UNDEFINED
//#define THEMEITEM_MEDIA_PROGRESSBAR_BUFFER UNDEFINED
//#define THEMEITEM_MEDIA_TEXT UNDEFINED
//#define THEMEITEM_MEDIA_TEXT_BACKGROUND UNDEFINED
//#define THEMEITEM_MEDIA_WALKMAN_HIGHLIGHT UNDEFINED
//#define THEMEITEM_MEDIA_WALKMAN_ICON UNDEFINED
//#define THEMEITEM_MEDIA_WALKMAN_MODE_ICON UNDEFINED
//#define THEMEITEM_MEDIA_WALKMAN_PARTICLE UNDEFINED
//#define THEMEITEM_MEDIA_WALKMAN_STATE_ICON UNDEFINED
//#define THEMEITEM_MEDIA_WHEEL_ICON UNDEFINED
//#define THEMEITEM_MINIPOPUP_BACKGROUND UNDEFINED
//#define THEMEITEM_MINIPOPUP_OUTLINE UNDEFINED
//#define THEMEITEM_MINIPOPUP_TEXT UNDEFINED
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
#define THEMEITEM_PROGRESS_BAR_FILL 0x71
#define THEMEITEM_PROGRESS_BAR_OUTLINE 0x6E
#define THEMEITEM_PROGRESS_BAR_SLIDER 0x70
#define THEMEITEM_SCROLLBAR_BACKGROUND 0x49
#define THEMEITEM_SCROLLBAR_SLIDER 0x48
#define THEMEITEM_SOFTKEY_LEFT 0x4C
#define THEMEITEM_SOFTKEY_RIGHT 0x4E
#define THEMEITEM_SOFTKEY_TEXT_LEFT 0x54
#define THEMEITEM_SOFTKEY_TEXT_LEFT_PRESSED 0x50
//#define THEMEITEM_SOFTKEY_TEXT_MIDDLE UNDEFINED
//#define THEMEITEM_SOFTKEY_TEXT_MIDDLE_PRESSED UNDEFINED
#define THEMEITEM_SOFTKEY_TEXT_RIGHT 0x58
#define THEMEITEM_SOFTKEY_TEXT_RIGHT_PRESSED 0x52
#define THEMEITEM_STANDBY_OPERATORNAME_OUTLINE 0x5D
#define THEMEITEM_STANDBY_OPERATORNAME_TEXT 0x5C
#define THEMEITEM_STANDBY_TIME 0x5E
#define THEMEITEM_STANDBY_TIME_OUTLINE 0x5F
#define THEMEITEM_STATUSBAR_CLOCK 0x7E
#define THEMEITEM_TAB 0x60
#define THEMEITEM_TAB_SELECTED 0x66
#define THEMEITEM_TAB_TEXT 0x62
#define THEMEITEM_TAB_UNSELECTED 0x64
#define THEMEITEM_TEXT 0x4
#define THEMEITEM_TITLE_TEXT 0x6A
#define THEMEITEM_VOLUME_STAPLES 0x6C
#define THEMEITEM_WAPBROWSER_TABLEBORDER 0x2
#define THEMEITEM_WAPBROWSER_UNDERLINE 0x0
#define THEMES_CHANGED_PROFILE_EVENT 0x4CA0
#define THEMES_CORRUPT_FILE_EVENT 0x4D5E
#define THEME_CHANGED_EVENT 0x4D5F
#define THEME_DOWNLOADED_EVENT 0x4D5D
//#define TIMER_SLIDERRELEASED_TIMEOUT_EVENT UNDEFINED
//#define UIBASIC_MC_ETSI_LOCK_SIM_OK_IND_EVENT UNDEFINED
#define UI_APPLICATION_VOLUMEDOWN_EVENT 0x855
#define UI_APPLICATION_VOLUMEDOWN_LONG_EVENT 0x857
#define UI_APPLICATION_VOLUMEUP_EVENT 0x854
#define UI_APPLICATION_VOLUMEUP_LONG_EVENT 0x856
#define UI_BLUETOOTH_ACTIVITY_CHANGED_EVENT 0xB18
#define UI_BLUETOOTH_STATE_CHANGED_EVENT 0xB17
#define UI_CALLMANAGER_IDLE_EVENT 0xE11
#define UI_CONNECTIONMANAGER_SESSION_ACTIVE_EVENT 0x10D9
#define UI_CONNECTIONMANAGER_SESSION_ACTIVITY_EVENT 0x10DA
#define UI_CONNECTIONMANAGER_SESSION_CREATED_EVENT 0x10D2
#define UI_CONNECTIONMANAGER_SESSION_ESTABLISHED_EVENT 0x10D4
#define UI_CONNECTIONMANAGER_SESSION_SUSPENDED_EVENT 0x10DC
#define UI_CONNECTIONMANAGER_SESSION_TERMINATED_EVENT 0x10D6
#define UI_CONTROLLED_SHUTDOWN_CONTINUE_OK_EVENT 0x788
#define UI_CONTROLLED_SHUTDOWN_OK_EVENT 0x789
#define UI_CONTROLLED_SHUTDOWN_REQUESTED_EVENT 0x840
#define UI_EXTERNAL_KEYLOCK_ACTIVATE_EVENT 0x7B6
#define UI_EXTERNAL_KEYLOCK_DEACTIVATE_EVENT 0x7B7
#define UI_FLIGHTMODE_SELECTION_EVENT 0x7AA
#define UI_FMRADIO_CONTROL_EVENT 0x1C22
#define UI_FMRADIO_CREATED_EVENT 0x1914
#define UI_INITIATED_EVENT 0x839
#define UI_INITIATED_SPECIAL_EVENT 0x83A
#define UI_INITIATING_ALARM_EVENT 0x837
#define UI_INITIATING_CHARGING_EVENT 0x836
#define UI_INITIATING_CUSTOMIZATION_EVENT 0x838
#define UI_INITIATING_EVENT 0x835
#define UI_KEYLOCK_ACTIVATE_EVENT 0x7B3
#define UI_KEYLOCK_DEACTIVATE_EVENT 0x7B4
#define UI_KEYLOCK_REACTIVATE_EVENT 0x7B5
#define UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT 0x2974
#define UI_MEDIAPLAYER_CONTROL_EVENT 0x1C21
#define UI_MEDIAPLAYER_CREATED_EVENT 0x299A
#define UI_MEDIAPLAYER_DESTROYED_EVENT 0x299B
#define UI_MEDIAPLAYER_NEXT_TRACK_EVENT 0x29A7
#define UI_MEDIAPLAYER_PAUSE_PRESSED_EVENT 0x2979
#define UI_MEDIAPLAYER_PLAY_PRESSED_EVENT 0x2977
#define UI_MEDIAPLAYER_PREV_TRACK_EVENT 0x29A6
#define UI_MEDIAPLAYER_STOP_PRESSED_EVENT 0x2973
#define UI_MEDIAPLAYER_VIDEO_CREATED_EVENT 0x2970
#define UI_MEDIAPLAYER_VIDEO_PLAYING_TIME_EVENT 0x296B
//#define UI_MEDIAPLAYER_VOLUMEDOWN_EVENT UNDEFINED
//#define UI_MEDIAPLAYER_VOLUMEUP_EVENT UNDEFINED
#define UI_MESSAGING_MMS_RECEIVED_EVENT 0x3016
#define UI_MESSAGING_MMS_SENDING_CANCELED_EVENT 0x300F
#define UI_MESSAGING_MMS_SENDING_EVENT 0x301A
#define UI_MESSAGING_MMS_SENT_EVENT 0x301B
#define UI_MESSAGING_SMS_RECEIVED_EVENT 0x3011
#define UI_MESSAGING_SMS_SENDING_ERROR_EVENT 0x3019
#define UI_MESSAGING_SMS_SENDING_EVENT 0x3018
#define UI_MESSAGING_SMS_SENT_EVENT 0x3017
#define UI_NEW_CALL_CONNECTED_EVENT 0xE10
#define UI_OBEX_ACCEPT_FILE_REQUEST_EVENT 0x39D1
#define UI_OBEX_CONNECTING_STATE_EVENT 0x39DD
#define UI_OBEX_FILE_ACCEPTED_EVENT 0x39D0
#define UI_OBEX_FTP_SEND_FILE_EVENT 0x39D7
#define UI_OBEX_RECEIVE_FAILED_EVENT 0x39D5
#define UI_OBEX_REFRESH_RECEIVE_PROGRESS_EVENT 0x39D2
#define UI_OBEX_REFRESH_TRANSFER_PROGRESS_EVENT 0x39DC
#define UI_OBEX_STATE_CHANGED_EVENT 0x39D3
#define UI_OBEX_TRANSFER_FAILED_EVENT 0x39DE
#define UI_OBEX_UPD_STATE_EVENT 0x39DF
#define UI_PRELOCK_ACTIVATE_EVENT 0x7B1
#define UI_PRELOCK_DEACTIVATE_EVENT 0x7B2
#define UI_SCREENSAVER_ACTIVATE_EVENT 0x7AB
#define UI_SCREENSAVER_DEACTIVATE_EVENT 0x7AC
#define UI_SCREENSAVER_FINISHED_EVENT 0x7AD
#define UI_SCREENSAVER_SHOW_INFO_EVENT 0x7AE
#define UI_SECRET_SEQ_DETECTED_EVENT 0x83C
#define UI_SETTINGS_ICB_SIM_APPLICATION_TOOLKIT_REFRESH_EVENT 0x4C9A
#define UI_SLEEPMODE_ACTIVATED_EVENT 0x851
#define UI_SLEEPMODE_ACTIVATE_EVENT 0x7AF
#define UI_SLEEPMODE_DEACTIVATED_EVENT 0x852
#define UI_SLEEPMODE_DEACTIVATE_EVENT 0x7B0
#define UI_STANDBY_TICKER_CREATED_EVENT 0x84F
//#define UI_STANDBY_TICKER_OPEN_BROWSER_EVENT UNDEFINED
#define UI_STANDBY_UNFOCUS_EVENT 0x853
#define UI_TRANSFER_FOCUS_BY_SESSION_MANAGER_EVENT 0x85C
#define UI_UTIL_SIM_GREETING_READ_EVENT 0x796
#define UNMUTE_EVENT 0x846
#define UPDATE_BATTERY_ICON_EVENT 0x77A
#define UPDATE_CUSTOMIZATION_PROGRESS_EVENT 0x787
#define USER_INACTIVITY_EVENT 0x18
#define USSD_RECIEVED_EVENT 0x340D
#define USSD_REQUEST_RECIEVED_EVENT 0x3412
#define VAD_DELETED_EVENT 0x5BCD
#define VAD_TAG_PLAYED_EVENT 0x5C95
#define VAR_ARG_BOOK 0x51
#define VAR_ARG_CALL_BACK_LONG_BACK 0x56
#define VAR_ARG_CALL_BACK_OK 0x44
#define VAR_ARG_CALL_BACK_PREV_ACT 0xAC
#define VAR_ARG_DATEINP_DATE 0x63
#define VAR_ARG_DATEINP_DATE_FORMAT 0x5E
#define VAR_ARG_HTEXT 0xBE
#define VAR_ARG_PERINP_CUR_PERCENT 0x68
#define VAR_ARG_PERINP_ROW_NUMBERS 0xB7
#define VAR_ARG_STRINP_EMPTY_STR_EN 0x7D
#define VAR_ARG_STRINP_FIXED_TEXT 0xAA
#define VAR_ARG_STRINP_IS_PASS_MODE 0xAF
#define VAR_ARG_STRINP_MAX_INT_VAL 0x8F
#define VAR_ARG_STRINP_MAX_LEN 0x8C
#define VAR_ARG_STRINP_MIN_INT_VAL 0x95
#define VAR_ARG_STRINP_MIN_LEN 0x93
#define VAR_ARG_STRINP_MODE 0x7F
#define VAR_ARG_STRINP_NEW_LINE 0x6D
#define VAR_ARG_STRINP_OK_ON_DIEZ 0x47
#define VAR_ARG_STRINP_SET_INT_VAL 0x65
#define VAR_ARG_STRINP_TEXT 0x66
#define VAR_ARG_TIMEINP_TIME 0x67
#define VAR_ARG_TIMEINP_TIME_FORMAT 0xBB
#define VAR_ARG_TIMEINP_TIME_FORMAT_SEC 0xBA
#define VAR_ARG_YESNO_NO_ACTION 0x9D
#define VAR_ARG_YESNO_PRE_QUESTION 0x6B
#define VAR_ARG_YESNO_QUESTION 0xAD
#define VAR_ARG_YESNO_YES_ACTION 0xC7
#define VC_ANSWER_ACCEPT_RECOGNISED_EVENT 0x5CA1
#define VC_ANSWER_ACTIVATED_EVENT 0x5C9E
#define VC_ANSWER_DEACTIVATED_EVENT 0x5C9F
#define VC_ANSWER_REJECT_RECOGNISED_EVENT 0x5CA2
#define VC_ANSWER_SERVICE_FAILED_EVENT 0x5CA0
#define VC_MAGICWORD_ACTIVATED_EVENT 0x5C96
#define VC_MAGICWORD_DEACTIVATED_EVENT 0x5C97
#define VC_MAGICWORD_RECOGNISED_EVENT 0x5C99
#define VC_MAGICWORD_SERVICE_FAILED_EVENT 0x5C98
#define VC_NAMEDIAL_ACTIVATED_EVENT 0x5C9A
#define VC_NAMEDIAL_DEACTIVATED_EVENT 0x5C9B
#define VC_NAMEDIAL_RECOGNISED_EVENT 0x5C9D
#define VC_NAMEDIAL_SERVICE_FAILED_EVENT 0x5C9C
#define VC_START_ANSWER_EVENT 0x5BD6
#define VC_START_MAGICWORD_EVENT 0x5BCF
#define VC_START_NAMEDIAL_EVENT 0x5BD4
#define VC_STOP_ANSWER_EVENT 0x5BD7
#define VC_STOP_MAGICWORD_EVENT 0x5BD0
#define VC_STOP_NAMEDIAL_EVENT 0x5BD5
//#define VIDEOCALLKEY_LONG_PRESS_EVENT UNDEFINED
#define VIDEOCALLKEY_PRESSED_EVENT 0x41
#define VN_BUTTON_LONG_PRESS_EVENT 0x20
#define VN_BUTTON_SHORT_PRESS_EVENT 0x1F
#define VOLUMECONTROL_DECREASE_EVENT 0x7A0
#define VOLUMECONTROL_DECREASE_REPEAT_EVENT 0x7A4
#define VOLUMECONTROL_INCREASE_EVENT 0x79F
#define VOLUMECONTROL_INCREASE_REPEAT_EVENT 0x7A1
#define VOLUMEDOWNKEY_LONG_PRESS_EVENT 0x4E
#define VOLUMEDOWNKEY_LONG_RELEASE_EVENT 0x53
#define VOLUMEDOWNKEY_PRESSED_EVENT 0x52
#define VOLUMEDOWNKEY_REPEAT_EVENT 0x4F
#define VOLUMEDOWNKEY_SHORT_PRESS_EVENT 0x4D
#define VOLUMEUPKEY_LONG_PRESS_EVENT 0x4B
#define VOLUMEUPKEY_LONG_RELEASE_EVENT 0x51
#define VOLUMEUPKEY_PRESSED_EVENT 0x50
#define VOLUMEUPKEY_REPEAT_EVENT 0x4C
#define VOLUMEUPKEY_SHORT_PRESS_EVENT 0x4A
#define WAP_APPLICATION_START_EVENT 0x5E0


#endif
#endif
