//K600_R2BB001
#include "target.h"

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20363C0C+1
        defadr memfree,0x20364D24+1
        defadr memset,0x20D66768+1
        defadr debug_printf,0x20D28E84+1
        defadr sprintf,0x20D672A0+1
        defadr snwprintf,0x20D67990+1
        defadr swscanf,0x20D679EC+1
        defadr current_process,0x200A405C
        defadr get_bid,0x200A4094
        defadr set_envp,0x2006CF5E+1
        defadr get_envp,0x2006CF4A+1
        defadr strcat,0x20D676D4+1
        defadr strcmp,0x20D67710+1
        defadr strcpy,0x20D67740+1
        defadr strlen,0x20D67778+1
        defadr strncpy,0x20D677EC+1
        defadr strncmp,0x20D677B0+1
        defadr strstr,0x20D67888+1
        defadr str2wstr,0x206105B4+1
        defadr wstrcat,0x2060F208+1
        defadr wstrlen,0x2060F0E4+1
        defadr wstrcpy,0x2060F160+1
        defadr wstrcmpi,0x20610854+1
        defadr wstrcmp,0x2060F110+1
        defadr wstrncpy,0x2060F1A8+1
        defadr wstrrchr,0x206106CC+1
        defadr wstrncmp,0x20610640+1
        defadr wstrwstr,0x20D68178+1
        defadr wstr2strn,0x2060F348+1
        defadr _fopen,0x204DBDF4+1
        defadr fread,0x204DD2F0+1
        defadr fclose,0x204DCFD4+1
        defadr fwrite,0x204DD58C+1
        defadr fstat,0x204DC6B4+1
        defadr w_diropen,0x2050A56C+1
        defadr w_chdir,0x20508C6C+1
        defadr w_dirread,0x20716280+1
        defadr w_fstat,0x208ED1D4+1
        defadr w_dirclose,0x2050A7F4+1
        defadr root_list_get_session_count,0x20425D90+1
        defadr root_list_get_session,0x20425DA4+1
        defadr List_Create,0x20231DF0+1
        defadr List_InsertFirst,0x20231F34+1
        defadr List_InsertLast,0x20231F44+1
        defadr List_GetCount,0x2023209C+1
        defadr List_Get,0x202320C4+1
        defadr List_Destroy,0x20231E14+1
        defadr List_DestroyElements,0x2023223C+1
        defadr Find_StandbyBook,0x202821FC+1
        defadr IsVolumeControllerBook,0x20549150+1
        defadr IsRightNowBook,0x20543CE8+1
        defadr GUIObject_GetDispObject,0x20280EC4+1
        defadr DispObject_SetAnimation,0x20267954+1
        defadr isKeylocked,0x20760810+1
        defadr MessageBox,0x20431AA4+1
        defadr CreateMessageBox,0x20431AF0+1
        defadr GetFreeBytesOnHeap,0x20366108+1
        defadr TextID_Create,0x202CFF38+1
        defadr TextID_Copy,0x202D00A4+1
        defadr TextID_Destroy,0x202D0210+1
        defadr TextID_GetString,0x202D0C08+1
        defadr GUIObject_SetStyle,0x20751E64+1
        defadr GUIObject_SetTitleType,0x20751EF8+1
        defadr GUIObject_SetTitleText,0x20751F10+1
        defadr GUIObject_SetSecondRowTitleText,0x20751F2C+1
        defadr GUIonMessage_GetMsg,0x2077D538+1
        defadr GUIonMessage_GetBook,0x2077D540+1
        defadr GUIonMessage_GetCreatedItemIndex,0x2077D564+1
        defadr GUIonMessage_GetSelectedItem,0x2077D544+1
        defadr GUIonMessage_SetItemDisabled,0x2077D60C+1
        defadr GUIonMessage_SetMenuItemText,0x2077D574+1
        defadr GUIonMessage_SetMenuItemIcon,0x2077D5B4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x2077D594+1
        defadr GUIonMessage_SetNumberOfSubItems,0x2077D600+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x2077D63C+1
        defadr GUIonMessage_SubItem_SetDisabled,0x2077D6F8+1
        defadr GUIonMessage_SubItem_SetText,0x2077D68C+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x2077D66C+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x2077D67C+1
        defadr CreateListMenu,0x2077C9B4+1
        defadr ListMenu_GetSelectedItem,0x2077CB54+1
        defadr ListMenu_SetItemCount,0x2077CB70+1
        defadr ListMenu_SetOnMessage,0x2077CCA0+1
        defadr ListMenu_SetCursorToItem,0x2077CB40+1
        defadr ListMenu_SetHotkeyMode,0x2077CCCC+1
        defadr ListMenu_SetItemStyle,0x2077CBA0+1
        defadr ListMenu_DestroyItems,0x2077D19C+1
        defadr GUIObject_Show,0x20751E14+1
        defadr GUIObject_Destroy,0x20280C7C+1
        defadr GUIObject_GetBook,0x20280EEC+1
        defadr DispObject_GetGUI,0x202642B0+1
        defadr DispObject_GetDESC,0x20439C24+1
        defadr DispObject_GetOnKey,0x20263E4C+1
        defadr DISP_DESC_SetOnKey,0x20263AD0+1
        defadr GUIObject_SoftKeys_SetAction,0x20753704+1
        defadr GUIObject_SoftKeys_SetText,0x207537EC+1
        defadr GUIObject_SoftKeys_SetVisible,0x20753884+1
        defadr DispObject_SoftKeys_ExecuteAction,0x2074F188+1
        defadr BookObj_SoftKeys_SetAction,0x20426610+1
        defadr BookObj_SoftKeys_SetText,0x2042665C+1
        defadr MenuBook_Desktop,0x204384D0+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x20439254+1
        defadr Shortcut_Get_MenuItemName,0x20546638+1
        defadr Shortcut_Get_MenuItemIconID,0x20439310+1
        defadr CreateTabMenuBar,0x20754020+1
        defadr TabMenuBar_SetTabCount,0x20754140+1
        defadr TabMenuBar_SetTabIcon,0x2075429C+1
        defadr TabMenuBar_SetTabGui,0x2075422C+1
        defadr TabMenuBar_SetTabTitle,0x207542D0+1
        defadr TabMenuBar_SetFocusedTab,0x207540EC+1
        defadr TabMenuBar_GetFocusedTab,0x20754118+1
        defadr CreateOneOfMany,0x2077E708+1
        defadr OneOfMany_GetSelected,0x2077E874+1
        defadr OneOfMany_SetItemCount,0x2077E844+1
        defadr OneOfMany_SetChecked,0x2077E864+1
        defadr OneOfMany_SetTexts,0x2077E88C+1
        defadr CreateStringInputVA,0x20771048+1
        defadr StringInput_GetStringAndLen,0x20771D08+1
        defadr StringInput_DispObject_SetText,0x2029C140+1
        defadr CreateYesNoQuestion,0x207572A0+1
        defadr YesNoQuestion_SetQuestionText,0x2075762C+1
        defadr YesNoQuestion_SetDescriptionText,0x2075763C+1
        defadr YesNoQuestion_SetIcon,0x20757658+1
        defadr FindBook,0x20425C9C+1
        defadr FindBookByID,0x20425C60+1
        defadr CreateBook,0x2025CF38+1
        defadr FreeBook,0x2025D550+1
        defadr BookObj_GotoPage,0x2025CC90+1
        defadr BookObj_CallPage,0x2025CDA8+1
        defadr BookObj_ReturnPage,0x2025CE18+1
        defadr BookObj_SetFocus,0x2025D1C8+1
        defadr BookObj_GetBookID,0x2025D6A4+1
        defadr BookObj_GetSession,0x2025D594+1
        defadr BookObj_Show,0x2025D20C+1
        defadr UI_Event,0x20425DB8+1
        defadr UI_Event_toBookID,0x20425DE8+1
        defadr UI_Event_toBookIDwData,0x20425DF8+1
        defadr Display_GetTopGUI,0x20280DEC+1
        defadr REQUEST_SYSTEM_RESTART,0x20549450+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x20549440+1
        defadr FlightMode_GetState,0x2074C9D4+1
        defadr FlightMode_SetState,0x2074C9E8+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x2055527C+1
        defadr REQUEST_SETTING_SILENCE_SET,0x20554A20+1
        defadr GetSilent,0x20467A68+1
        defadr Shortcut_Run,0x20439390+1
        defadr ImageID_Free,0x20336A54+1
        defadr JavaSession_GetName,0x20546B40+1
        defadr JavaDialog_Open,0x20649954+1
        defadr JavaAppDesc_GetFirstApp,0x20643D34+1
        defadr JavaAppDesc_GetJavaAppInfo,0x20643960+1
        defadr JavaApp_LogoImageID_Get,0x20359D2C+1
        defadr JavaAppDesc_GetNextApp,0x20643D58+1
        defadr JavaDialog_Close,0x2064D23C+1
        defadr JavaAppDesc_GetJavaAppID,0x2064D36C+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x204F5CFC+1
        defadr manifest_GetParam,0x20458AFC+1

        EXTERN  Patch_QuickAccess
        EXTERN  Patch_BookManager
        EXTERN  Patch_NextBook

        RSEG    PATCH_FIX_VCKEY
        CODE16
        POP     {R4,PC}

        RSEG    PATCH_KEYHANDLER
        DATA
        DCD     keyhandler

        RSEG  CODE
        CODE16
keyhandler:
	PUSH	{LR}
	CMP	R0, #KEY_POWER
	BNE	_act_button
	CMP	R2, #3
	BNE	_def_button
	BL      Patch_QuickAccess
	POP	{PC}

_act_button:
        CMP     R0, #KEY_TASK
        BNE     _vc_button
        CMP	R2, #3
	BNE	_def_button
        BL      Patch_BookManager
        POP	{PC}

_vc_button:
        CMP     R0, #KEY_VIDEOCALL
        BNE     _def_button
        CMP	R2, #3
	BNE	_def_button
        BL      Patch_NextBook
        POP	{PC}

_def_button:
        BL      _default
	POP	{PC}

_default:
        LDR	R3, =0x2025C8A8+1
	BX	R3

        END
