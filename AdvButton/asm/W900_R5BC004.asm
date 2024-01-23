//W900_R5BC004
#include "target.h"

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x2062C09C+1
        defadr memfree,0x2062D0CC+1
        defadr memset,0x211E97E4+1
        defadr debug_printf,0x211A8D30+1
        defadr sprintf,0x211EA31C+1
        defadr snwprintf,0x211EAA10+1
        defadr swscanf,0x211EAA6C+1
        defadr current_process,0x20138FAC
        defadr get_bid,0x20138FE4
        defadr set_envp,0x200FE506+1
        defadr get_envp,0x200FE4F2+1
        defadr _fopen,0x207AA90C+1
        defadr fstat,0x207AB1D0+1
        defadr fread,0x207ABED0+1
        defadr fwrite,0x207AC154+1
        defadr fclose,0x207ABB94+1
        defadr w_fstat,0x20CF099C+1

        defadr TextID_Create,0x204C9F04+1
        defadr TextID_Copy,0x204CA040+1
        defadr TextID_Destroy,0x204CA0F0+1
        defadr TextID_GetString,0x204CAAF4+1
        defadr TextID_GetWString,0x204CA2B0+1

        defadr root_list_get_session,0x20717948+1
        defadr root_list_get_session_count,0x20717934+1
        defadr List_Create,0x2044599C+1
        defadr List_InsertFirst,0x20445AC0+1
        defadr List_InsertLast,0x20445AD0+1
        defadr List_Get,0x20445C50+1
        defadr List_GetCount,0x20445C28+1
        defadr List_Destroy,0x204459B4+1
        defadr List_DestroyElements,0x20445DB4+1

        defadr strcat,0x211EA750+1
        defadr strstr,0x211EA90C+1
        defadr strncmp,0x211EA82C+1
        defadr strcmp,0x211EA78C+1
        defadr strlen,0x211EA7F4+1
        defadr strcpy,0x211EA7BC+1
        defadr strncpy,0x211EA868+1
        defadr wstrlen,0x211EB2A4+1
        defadr wstrcmp,0x211EB238+1
        defadr wstrncmp,0x211EB2E0+1
        defadr wstrwstr,0x211EB47C+1
        defadr wstrcpy,0x211EB268+1
        defadr wstrcat,0x211EB208+1
        defadr str2wstr,0x20A01A28+1
        defadr wstr2strn,0x20A007C0+1

        defadr ImageID_Free,0x205FBA38+1

        defadr JavaDialog_Open,0x20A3F478+1
        defadr JavaDialog_Close,0x20A42F74+1
        defadr JavaAppDesc_GetFirstApp,0x20A39868+1
        defadr JavaAppDesc_GetNextApp,0x20A39888+1
        defadr JavaAppDesc_GetJavaAppInfo,0x20A39508+1
        defadr JavaAppDesc_GetJavaAppID,0x20A430A4+1
        defadr JavaApp_LogoImageID_Get,0x20622310+1
        defadr JavaSession_GetName,0x208385D8+1
        defadr JavaSession_Manager,0x20838690+1
        defadr manifest_GetParam,0x2074ED88+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x207C5094+1

        defadr CreateBook,0x2046771C+1
        defadr FindBook,0x20717840+1
        defadr FindBookByID,0x20717804+1
        defadr FreeBook,0x20467D84+1
        defadr BookObj_SetFocus,0x204679B8+1
        defadr BookObj_GetSession,0x20467DBC+1
        defadr BookObj_GotoPage,0x20467474+1
        defadr BookObj_CallPage,0x20467594+1
        defadr BookObj_ReturnPage,0x20467608+1
        defadr BookObj_GetBookID,0x20467EA4+1
        defadr Display_GetTopBook,0x20466F98+1
        defadr UI_Event,0x2071795C+1
        defadr UI_Event_toBookID,0x2071798C+1
        defadr UI_Event_toBookIDwData,0x2071799C+1

        defadr isKeylocked,0x20B7D7A0+1
        defadr IsRightNowBook,0x20835720+1
        defadr IsVolumeControllerBook,0x2083AC4C+1
        defadr Find_StandbyBook,0x20474ED0+1

        defadr BookObj_SoftKeys_SetAction,0x207316EC+1
        defadr BookObj_SoftKeys_SetText,0x20731738+1
        defadr Shortcut_Get_MenuItemName,0x208380B8+1
        defadr Shortcut_Get_MenuItemIconID,0x20721FA0+1
        defadr MenuBook_Desktop,0x20720F54+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x20721EF4+1
        
        defadr ConnectionManager_Connection_GetState,0x20B334B0+1
        defadr GetSilent,0x2063599C+1
        defadr Bluetooth_GetState,0x20794294+1
        defadr Bluetooth_SetState,0x207942CC+1
        defadr Bluetooth_isBusy,0x20794318+1
        defadr FlightMode_GetState,0x20B769A8+1
        defadr FlightMode_SetState,0x20B769BC+1
        defadr IrDa_GetState,0x2071C2D4+1

        defadr REQUEST_PROFILE_GETPROFILENAME,0x208447F4+1
        defadr REQUEST_SYSTEM_RESTART,0x20E31E58+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x20E31E34+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x208446C0+1
        defadr REQUEST_SETTING_SILENCE_SET,0x20843E94+1

        defadr Lock_Keyboard,0x20B7D6B4+1
        defadr Shortcut_Run,0x2083A238+1
        defadr GetFreeBytesOnHeap,0x2062E34C+1

        defadr GUIObject_SetStyle,0x20BBC704+1
        defadr GUIObject_SetTitleType,0x20BBC798+1
        defadr GUIObject_SetTitleText,0x20BBC7BC+1
        defadr GUIObject_SetSecondRowTitleText,0x20BBC7D8+1
        defadr GUIObject_Show,0x20BBC6A4+1
        defadr GUIObject_Destroy,0x20BBC278+1

        defadr GUIObject_SoftKeys_SetText,0x20BC4F24+1
        defadr GUIObject_SoftKeys_SetAction,0x20BC4E30+1
        defadr GUIObject_SoftKeys_SetInfoText,0x20BC4EE4+1
        defadr GUIObject_SoftKeys_SetVisible,0x20BC4FC4+1
        defadr DispObject_SoftKeys_ExecuteAction,0x20BC237C+1

        defadr GUIObject_GetDispObject,0x20BBC31C+1
        defadr DispObject_GetGUI,0x204CDDE8+1
        defadr GUIObject_GetBook,0x20BBC340+1
        defadr DispObject_GetOnKey,0x204CD908+1
        defadr DispObject_GetDESC,0x204EA760+1
        defadr DISP_DESC_SetOnKey,0x204CD58C+1

        defadr CreateListMenu,0x20B97800+1
        defadr ListMenu_SetItemCount,0x20B97A28+1
        defadr ListMenu_GetSelectedItem,0x20B97A10+1
        defadr ListMenu_SetCursorToItem,0x20B979FC+1
        defadr ListMenu_SetHotkeyMode,0x20B97B98+1
        defadr ListMenu_SetOnMessage,0x20B97B6C+1
        defadr ListMenu_SetItemStyle,0x20B97A74+1
        defadr ListMenu_DestroyItems,0x20B980E0+1

        defadr GUIonMessage_GetBook,0x20B987B0+1
        defadr GUIonMessage_GetMsg,0x20B987A8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x20B987D4+1
        defadr GUIonMessage_SetMenuItemText,0x20B987E4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x20B98814+1
        defadr GUIonMessage_SetMenuItemIcon,0x20B98824+1
        defadr GUIonMessage_SetItemDisabled,0x20B9887C+1
        defadr GUIonMessage_SetMenuItemInfoText,0x20B987F4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x20B98804+1
        defadr GUIonMessage_SetLineSeparator,0x20B98894+1
        defadr GUIonMessage_GetSelectedItem,0x20B987B4+1
        defadr GUIonMessage_SetNumberOfSubItems,0x20B98870+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x20B988EC+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x20B988DC+1
        defadr GUIonMessage_SubItem_SetText,0x20B988FC+1
        defadr GUIonMessage_SubItem_SetDisabled,0x20B98968+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x20B988AC+1

        defadr CreateOneOfMany,0x20B99EA4+1
        defadr OneOfMany_SetItemCount,0x20B9A038+1
        defadr OneOfMany_SetChecked,0x20B9A05C+1
        defadr OneOfMany_SetTexts,0x20B9A090+1
        defadr OneOfMany_GetSelected,0x20B9A06C+1

        defadr CreateYesNoQuestion,0x20BBF90C+1
        defadr YesNoQuestion_SetQuestionText,0x20BBFC94+1
        defadr YesNoQuestion_SetIcon,0x20BBFCC0+1

        defadr CreateTabMenuBar,0x20B78554+1
        defadr TabMenuBar_SetTabCount,0x20B78670+1
        defadr TabMenuBar_SetTabIcon,0x20B7883C+1
        defadr TabMenuBar_SetTabGui,0x20B7875C+1
        defadr TabMenuBar_SetTabTitle,0x20B78870+1
        defadr TabMenuBar_SetFocusedTab,0x20B7861C+1
        defadr TabMenuBar_GetFocusedTab,0x20B78648+1

        defadr CreateStringInputVA,0x20B8C8C8+1
        defadr CreateMessageBox,0x2071A384+1
        defadr MessageBox,0x2071A338+1

        EXTERN  Patch_BookManager
        EXTERN  Patch_NextBook

        RSEG    PATCH_FIX_IKEY
        CODE16
        POP     {R3,R4,PC}
        
        RSEG    PATCH_FIX_VCKEY
        CODE16
        POP     {R3,R4,PC}

        RSEG    PATCH_KEYHANDLER
        DATA
        DCD     keyhandler

        RSEG  CODE
        CODE16
keyhandler:
	PUSH	{LR}
        CMP	R0, #KEY_INTERNET
	BNE	_vc_button
	CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
	BL      Patch_BookManager
	POP	{PC}

_vc_button:
        CMP     R0, #KEY_VIDEOCALL
        BNE     _def_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_NextBook
        POP	{PC}

_def_button:
        BL      _default
	POP	{PC}

_default:
        LDR	R3, =0x20467004+1
	BX	R3

        END
