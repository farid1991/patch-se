#ifndef W580_R8BE001
#error W580_R8BE001 configuration needed for this header!
#else
#ifndef _W580_R8BE001_
#define _W580_R8BE001_

#define ACTION_LONG_BACK        0xFAF
#define ACTION_SELECT1          0xFC2
#define ACTION_DELETE           0xFB4
#define ACTION_BACK             0xFC0
#define ACTION_YES              0xFC5
#define ACTION_NO               0xFBE

#define RETURN_TO_STANDBY_EVENT 0x848
#define CANCEL_EVENT            0x4
#define PAGE_ENTER_EVENT        0x7

#define TEXTID_OP3              0x13E0 // �������� 3
#define TEXTID_OP2              0x13E1 // �������� 2
#define TEXTID_OP1              0x13E2 // �������� 1
#define TEXTID_SF               0x13E3 // ����� � Flight
#define TEXTID_BIG_TIME         0x13E4 // ������� ����
#define TEXTID_TALK             0x13E5 // ����� ���������
#define TEXTID_SHIFT            0x13E6 // ��������

#define TEXTID_TITLE            0x13F7
#define SOFTKEY_TEXTID          0x3E9
#define TEXTID_SWITCHED_OFF     0x1534 // ���������
#define TEXTID_OFF              0x09CB // ���������
#define TEXTID_NOTES            0x0E91 // �������
#define TEXTID_TIME             0x196E // ����
#define TEXTID_DATE             0x01CC // ����
#define TEXTID_ALARM            0x1C8E // ���������
#define TEXTID_TIMER            0x1CDA // ������
#define TEXTID_ACCEL            0x1B5D // ������� �����
#define TEXTID_NO               0x1409
#define TEXTID_PROF             0x165D

#define ICONID_NO               0xE621
#define ICONID_PROF             0xEE46
#define ICONID_OP3              0xE5E4 // �������� 3
#define ICONID_OP2              0xE5E4 // �������� 2
#define ICONID_OP1              0xE5E4 // �������� 1
#define ICONID_SF               0xEEAF // ����� � Flight
#define ICONID_NOTES            0xEDF7 // �������
#define ICONID_BIG_TIME         0xF355 // ������� ����
#define ICONID_TIME             0xF364 // ����
#define ICONID_DATE             0xED55 // ����
#define ICONID_ALARM            0xF35A // ���������
#define ICONID_TIMER            0xF333 // ������
#define ICONID_TALK             0xEDFC // ����� ���������
#define ICONID_SHIFT            0xECC1 // ��������
#define ICONID_ACCEL            0xF301 // ������� �����

#endif
#endif
