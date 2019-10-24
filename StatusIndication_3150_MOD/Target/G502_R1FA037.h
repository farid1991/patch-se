#ifndef G502_R1FA037
#error G502_R1FA037 configuration needed for this header!
#else
#ifndef _G502_R1FA037_
#define _G502_R1FA037_

#define VAR_BOOK 		(char*)0x1205FDE7
#define VAR_STRINP_MODE 	(char*)0x1205FE0F
#define VAR_STRINP_NEW_LINE	(char*)0x1205FE05
#define VAR_STRINP_MAX_LEN 	(char*)0x1205FE19
#define VAR_STRINP_MIN_LEN 	(char*)0x1205FE21
#define VAR_STRINP_SET_INT_VAL 	(char*)0x1205FDF9
#define VAR_STRINP_FIXED_TEXT 	(char*)0x1205FE35
#define VAR_OK_PROC 		(char*)0x1205FDD5
#define VAR_BACK_PROC 		(char*)0x1205FE37
#define VAR_LONG_BACK_PROC 	(char*)0x1205FDE9
#define VAR_HEADER_TEXT 	(char*)0x1205FE4F
#define VAR_YESNO_PRE_QUESTION 	(char*)0x1205FE01
#define VAR_YESNO_QUESTION 	(char*)0x1205FE39
#define VAR_YESNO_YES_ACTION 	(char*)0x1205FE55
#define VAR_YESNO_NO_ACTION 	(char*)0x1205FE2D
#define VAR_STRINP_TEXT         (char*)0x1205FDFB
#define VAR_PREV_ACTION_PROC    (char*)0x1205FE37
#define VAR_STRINP_IS_PASS_MODE (char*)0x1205FE3B
#define VAR_STRINP_ENABLE_EMPTY_STR (char*)0x1205FE0D

#define Display_Width      240
#define Display_Height     320

#define STATUS_ICN_WIDTH  25
#define STATUS_ICN_HEIGHT 22

#define KBD_LONG_PRESS    0x1
#define KBD_LONG_RELEASE  0x4
#define KBD_REPEAT        0x2
#define KBD_SHORT_PRESS   0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DIEZ      0x1E
#define KEY_STAR      0x1D
#define KEY_ESC       0x4
#define KEY_UP        0x9
#define KEY_DOWN      0xD
#define KEY_LEFT      0xF
#define KEY_RIGHT     0xB
#define KEY_ENTER     0x8
#define KEY_DIGITAL_0 0x13

#define ACTION_BACK       0xFC0
#define ACTION_LONG_BACK  0xFAF
#define ACTION_SELECT1    0xFC2

#define NIL_EVENT         0
#define ACCEPT_EVENT      0x2
#define CANCEL_EVENT      0x4
#define PAGE_ENTER_EVENT  0xE
#define RETURN_TO_STANDBY_EVENT 0x841

/*
#define _VAR_ARG_HTEXT 0xBE
#define _VAR_ARG_STRINP_MAX_LEN 0x8C
#define _VAR_ARG_STRINP_MIN_LEN 0x93
#define _VAR_ARG_STRINP_MODE 0x7F
#define _VAR_ARG_STRINP_IS_PASS_MODE 0xAF
#define _VAR_ARG_BOOK 0x51
#define _VAR_ARG_STRINP_EMPTY_STR_EN 0x7D
#define _VAR_ARG_STRINP_TEXT 0x66
#define _VAR_ARG_CALL_BACK_PREV_ACT 0xAC
#define _VAR_ARG_CALL_BACK_OK 0x44
*/

#define GETFONTDESC  (FONT_DESC*)0x2A2846AC
#define GETFONTCOUNT (int*)0x2A284A1C
#define StatusRow_p()  ((DISP_OBJ**)0x2A2841D8)

#define GetSignalQuality_Send_SignalID    0x12C00080
#define GetSignalQuality_Receive_SignalID 0x12C007C0

#define _SYNC_          0x11A8331C

#define ALARM_ICN 0xF8CE
#define TIMER_ICN 0xF825
#define CALL_ICN  0xF83C

#define SILENT_MODE_ICN               0xF3C4

#define C_UI_BATTERY_CHARGING_ICN     0xE580
#define C_UI_BATTERY_LEV9_ICN         0xF88B
#define C_UI_BATTERY_LEV0_ICN         0xF895

#define C_UI_EDGE_ATT_LEV0_ICN        0xE581
#define C_UI_GPRS_DET_LEV9_ICN        0xE598
#define C_UI_RSSI_LEV0_ICN            0xE59A
#define C_UI_RSSI_LEV5_ICN            0xE59F
#define FMODE_RSSI_INDICATION_ICN     0xEB6B

#define CUSTOM_HIDE_NUM_ICN           0xEA37 //CIPHERING_OFF_ICN
#define CUSTOM_BY_NET_NUM_ICN         0xFFFF //
#define CUSTOM_SHOW_NUM_ICN           0xFFFF //

#define CUSTOM_CALLERSFROMLIST_ICN    0xE5D6 //CALLS_SCREENED_ICN
#define CUSTOM_NONECALLERS_ICN        0xEADE //DIVERTED_ICN

#define CUSTOM_USB_CONNECTED_ICN      0xF46C // USB_CABLE_ICN

#define MEDIAPLAYER_RUNNING_ICN       0xECFF
#define FM_RADIO_STATUSBAR_RADIO_ICN  0xEB66

#define CHANGE_TEXTID           0x9C8 //»змен.

//ƒни недели
#define SEARCHING_TEXTID        0x1DBA

#define TEXTID_1                0x255C  // пн
#define TEXTID_2                0x257D  // вт
#define TEXTID_3                0x257F  // ср
#define TEXTID_4                0x257A  // чт
#define TEXTID_5                0x2555  // пт
#define TEXTID_6                0x2562  // сб
#define TEXTID_7                0x2578  // вс

#define TEXTID_F_1              0x255D  // понедельник
#define TEXTID_F_2              0x257E  // вторник
#define TEXTID_F_3              0x2580  // среда
#define TEXTID_F_4              0x257B  // четверг
#define TEXTID_F_5              0x2556  // п€тница
#define TEXTID_F_6              0x2563  // суббота
#define TEXTID_F_7              0x2579  // воскресенье

//Ўрифты
#define FONT_E_20R              0x35
#define FONT_E_14R              0x12

#define FONT_TIMER              0x1A //FONT_E_16B
#define FONT_CALL               0x2C //FONT_E_20B
#define FONT_HEAP               0x0E //FONT_E_12B
#define FONT_TEMP               0x13 //FONT_E_14B
#define FONT_BATT               0x0D //FONT_E_12R
#define FONT_CHARGE             0x13 //FONT_E_14B
#define FONT_BATTTEMP           0x13 //FONT_E_14B
#define FONT_ALARM              0x38 //FONT_E_24BI
#define FONT_OPERATOR           0x13 //FONT_E_14B
#define FONT_SIGNAL             0x0D //FONT_E_12B 
#define FONT_PROFILE            0x13 //FONT_E_14B 
#define FONT_TIME               0x40 //FONT_D_29B 
#define FONT_TIME2              0x13 //FONT_E_14B
#define FONT_DATE               0x2C //FONT_E_20B
#define FONT_DAY                0x2C //FONT_E_20B
#define FONT_PHONE              0x0E //FONT_E_12B
#define FONT_CARD               0x0E //FONT_E_12B
#define FONT_MUSIC              0x2C //FONT_E_20B
#define FONT_RADIO              0x2C //FONT_E_20B

#define PHONE_X                 5   //
#define PHONE_Y                 70  //
#define PHONE_ALIGN             LEFT

#define CARD_X                  5   //
#define CARD_Y                  90  //
#define CARD_ALIGN              LEFT

#define OPERATOR_X              235 //
#define OPERATOR_Y              136 //
#define OPERATOR_ALIGN          RIGHT
                 
#define SIGNAL_X                12 //
#define SIGNAL_Y                5  //
#define SIGNAL_ALIGN            LEFT

#define PROFILE_X               235  //
#define PROFILE_Y               120  //
#define PROFILE_ALIGN           RIGHT

#define TIME_X                  235 //
#define TIME_Y                  219 //
#define TIME_ALIGN              RIGHT

#define TIME2_X                 165 //
#define TIME2_Y                 5   //
#define TIME2_ALIGN             LEFT

#define DATE_X                  235 //
#define DATE_Y                  247 //
#define DATE_ALIGN              RIGHT

#define DAY_X                   235 //
#define DAY_Y                   200 //
#define DAY_ALIGN               RIGHT

#define ALARM_X                 235 //
#define ALARM_Y                 180 //
#define ALARM_ALIGN             RIGHT

#define BATT_X                  210 //
#define BATT_Y                  4   //
#define BATT_ALIGN              LEFT

#define CHARGE_X                235 //
#define CHARGE_Y                40   //
#define CHARGE_ALIGN            RIGHT

#define BATTTEMP_X              235  //
#define BATTTEMP_Y              25 //
#define BATTTEMP_ALIGN          RIGHT

#define TEMP_X                  5  //
#define TEMP_Y                  52 //
#define TEMP_ALIGN              LEFT

#define HEAP_X                  5  //
#define HEAP_Y                  38 //
#define HEAP_ALIGN              LEFT

#define CALL_X                  3   //
#define CALL_Y                  240 //
#define CALL_ALIGN              LEFT

#define TIMER_X                 3   //
#define TIMER_Y                 226 //
#define TIMER_ALIGN             LEFT

#define NET_ICON_X              3
#define NET_ICON_Y              0

#define BATT_ICON_X             202
#define BATT_ICON_Y             0

#define STATUS_X                35
#define STATUS_Y                0
#define STATUS_ALIGN            LEFT

#define STATUS_BG_X             0
#define STATUS_BG_Y             0

#define MUSIC_X                 3
#define MUSIC_Y                 205
#define MUSIC_ALIGN             LEFT

#define RADIO_X                 3
#define RADIO_Y                 230
#define RADIO_ALIGN             LEFT

#endif
#endif
