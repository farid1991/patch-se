#ifndef C905_R1FA035
#define C905_R1FA035

#define A2
#define DB3210

#define POPUP_WARNING_ICN 0xF831

#define TEXT_STOP             0xCC0   // L"����"
#define TEXT_MINIMISE         0x728   // L"��������"
#define TEXT_SETTINGS         0x268A  // L"���������"
#define TEXT_ON               0x869   // L"��������"
#define TEXT_OFF              0x1EC6  // L"���������"
#define TEXT_ON_OOM           0xF     // L"��������"
#define TEXT_OFF_OOM          0x104   // L"���������"
#define TEXT_CHANGE           0x218   // L"������� ���������"
#define TEXT_QUESTION         0x656   // L"���������?"
#define TEXT_SAVE             0x291   // L"���������"
#define TEXT_LEFT             0xFC7   // L"�����"
#define TEXT_RIGHT            0x1063  // L"������"
#define TEXT_CENTRE           0x2C3   // L"�����"
#define TEXT_IMAGE            0xBFA   // L"�����������"
#define TEXT_CANCEL           0x89    // L"��������"
#define TEXT_PLAY             0x631   // L"�����."
#define TEXT_PAUSE            0x138F  // L"�����"
#define TEXT_TIME             0xC48   // L"�������"
#define TEXT_YEAR             0x140A  // L"���"
#define TEXT_GENRE            0x745   // L"����"
#define TEXT_COVER            0x13EE  // L"������� ����."
#define TEXT_BACKROUND        0x24E0  // L"���"
#define TEXT_ADDITIONAL       0x7D    // L"�������������"
//#define TEXT_ACTIVATE         0xCD7   // L"��������"
#define TEXT_COLOR            0x1D17  // L"����"
#define TEXT_COLOR_TEXT       0x1D63  // L"���� ������"
#define TEXT_PTYPE            0x103E  // L"���"
#define TEXT_COLOR_B          0x1D13  // L"���� ����"
#define TEXT_MODE             0x174F  // L"����� �������."
#define TEXT_SCREEN           0x4ED   // L"�� ���� �����"
#define TEXT_ANIMATION        0x14CE  // L"��������"
#define TEXT_THEME            0x78C   // L"�� ����"

// interface id ----------------------------------------------------

#define CID_CUIFontManager (PUUID)0x15B8C860
#define IID_IUIFontManager (PUUID)0x15BC6850
#define CID_CUIImageManager (PUUID)0x15B8F524
#define IID_IUIImageManager (PUUID)0x15BC8C0C
#define CID_CTextRenderingManager (PUUID)0x15B94018
#define IID_ITextRenderingManager (PUUID)0x15BCB778
#define CID_CMetaData (PUUID)0x15B68E94
#define IID_IMetaData (PUUID)0x15BAE500

// function ----------------------------------------------------

#define GET_IMEI (char*)0x4BA019D0

// base events ----------------------------------------------------

#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF
#define ACTION_NO 0xFBE
#define ACTION_SELECT1 0xFC2
#define ACTION_YES 0xFC5
#define CANCEL_EVENT 0x4
#define FONT_E_18R 0x12
#define FONT_E_20R 0x14
#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3
#define KEY_DEL 0x5
#define KEY_DIEZ 0x23
#define KEY_DIGITAL_0 0x18
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB
#define KEY_STAR 0x22
#define KEY_UP 0x9
#define NIL_EVENT 0x0
#define PAGE_ENTER_EVENT 0xF
#define PREVIOUS_EVENT 0x3
#define RETURN_TO_STANDBY_EVENT 0x840
#define UI_KEYLOCK_ACTIVATE_EVENT 0x5E27
#define VOLUMEDOWNKEY_SHORT_PRESS_EVENT 0x63
#define VOLUMEUPKEY_SHORT_PRESS_EVENT 0x60

#endif
