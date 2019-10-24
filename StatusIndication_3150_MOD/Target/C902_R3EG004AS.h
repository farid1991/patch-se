#ifndef C902_R3EG004AS
#error C902_R3EG004AS configuration needed for this header!
#else
#ifndef _C902_R3EG004AS_
#define _C902_R3EG004AS_

#define DisplayWidth  240
#define DisplayHeight 320

#define STATUS_ICN_WIDTH  25
#define STATUS_ICN_HEIGHT 22

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DIEZ 0x23
#define KEY_STAR 0x22
#define KEY_ESC 0x4
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB
#define KEY_ENTER 0x8
#define KEY_DIGITAL_0 0x18

#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2

#define ACCEPT_EVENT 0x2
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define RETURN_TO_STANDBY_EVENT 0x840

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


#define GetFontDesc()  ((FONT_DESC* )0x4BBA20D4)
#define GetFontCount() ((int* )0x4BBA2444)
#define StatusRow_p()  ((DISP_OBJ**)0x4BBC5794)

#define GetSignalQuality_Send_SignalID 0x12C00080
#define GetSignalQuality_Receive_SignalID 0x12C007C0

#define IImageManager_guid                ((char *)0x11E1D958)
#define CImageManagerCreator_guid         ((char *)0x11DF3910)

#define SILENT_MODE_ICN               0xF3AA

#define C_UI_BATTERY_CHARGING_ICN     0xF430
#define C_UI_BATTERY_LEV9_ICN         0xF88B
#define C_UI_BATTERY_LEV0_ICN         0xF895

#define C_UI_EDGE_ATT_LEV0_ICN        0xE573
#define C_UI_GPRS_DET_LEV9_ICN        0xE58A
#define C_UI_RSSI_LEV0_ICN            0xE58B
#define C_UI_RSSI_LEV5_ICN            0xE590
#define FMODE_RSSI_INDICATION_ICN     0xEB62

#define CUSTOM_HIDE_NUM_ICN           0xF45F //CIPHERING_OFF_ICN
#define CUSTOM_BY_NET_NUM_ICN         0xFFFF //
#define CUSTOM_SHOW_NUM_ICN           0xFFFF //

#define CUSTOM_CALLERSFROMLIST_ICN    0xE5C4 //CALLS_SCREENED_ICN
#define CUSTOM_NONECALLERS_ICN        0xEAE6 //DIVERTED_ICN

#define MEDIAPLAYER_RUNNING_ICN       0xECFB

#define CHANGE_TEXTID           0x9D8 //�����.

//��� ������

#define TEXTID_1                0x257D  // ��
#define TEXTID_2                0x259E  // ��
#define TEXTID_3                0x25A0  // ��
#define TEXTID_4                0x259B  // ��
#define TEXTID_5                0x2576  // ��
#define TEXTID_6                0x2583  // ��
#define TEXTID_7                0x2599  // ��

#define TEXTID_F_1              0x257E  // �����������
#define TEXTID_F_2              0x259F  // �������
#define TEXTID_F_3              0x25A1  // �����
#define TEXTID_F_4              0x259C  // �������
#define TEXTID_F_5              0x2577  // �������
#define TEXTID_F_6              0x2584  // �������
#define TEXTID_F_7              0x259A  // �����������

//������
#define FONT_E_20R              0x2B
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

#endif
#endif
