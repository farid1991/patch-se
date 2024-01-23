//K750_R1CA021
#include "target.h"

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F7B500+1
        defadr memfree,0x44F7C61C+1
        defadr memset,0x44B376B4+1
        defadr memcpy,0x44069D44
        defadr sprintf,0x44B381DC+1
        defadr snwprintf,0x44B388C0+1
        defadr swscanf,0x44B3891C+1
        defadr strcat,0x44B38604+1
        defadr strlen,0x44B386A8+1
        defadr strcpy,0x44B38670+1
        defadr strstr,0x44B387B8+1
        defadr strcmp,0x44B38640+1
        defadr strncmp,0x44B386E0+1
        defadr strncpy,0x44B3871C+1
        defadr str2wstr,0x44BE8670+1
        defadr wstrlen,0x44BE71A0+1
        defadr wstrcmp,0x44BE71CC+1
        defadr wstrwstr,0x44B38F2C+1
        defadr wstrcpy,0x44BE721C+1
        defadr wstrcat,0x44BE72C4+1
        defadr wstr2strn,0x44BE7404+1
        defadr wstrncmp,0x44BE86FC+1
        defadr _fopen,0x450D74A8+1
        defadr fread,0x450D89A4+1
        defadr fwrite,0x450D8C40+1
        defadr fclose,0x450D8688+1
        defadr fstat,0x450D7D68+1
        defadr w_fstat,0x4475F918+1
        defadr List_Create,0x44E4ED64+1
        defadr List_InsertFirst,0x44E4EEA8+1
        defadr List_InsertLast,0x44E4EEB8+1
        defadr List_GetCount,0x44E4F010+1
        defadr List_Get,0x44E4F038+1
        defadr List_DestroyElements,0x44E4F1B0+1
        defadr List_Destroy,0x44E4ED88+1
        defadr TextID_Create,0x44EEC3B0+1
        defadr TextID_Copy,0x44EEC5DC+1
        defadr TextID_Destroy,0x44EEC680+1
        defadr TextID_GetString,0x44EED078+1
        defadr TextID_GetWString,0x44EEC834+1
        defadr GUIObject_SetTitleType,0x44D2F66C+1
        defadr GUIObject_SetTitleText,0x44D2F684+1
        defadr GUIObject_SetSecondRowTitleText,0x44D2F6A0+1
        defadr GUIObject_SetStyle,0x44D2F5D8+1
        defadr GUIObject_Destroy,0x44E9DF88+1
        defadr GUIObject_Show,0x44D2F588+1
        defadr GUIObject_GetDispObject,0x44E9E1D0+1
        defadr DispObject_GetGUI,0x44E817CC+1
        defadr GUIObject_GetBook,0x44E9E1F8+1
        defadr DispObject_GetOnKey,0x44E81360+1
        defadr DispObject_GetDESC,0x45061378+1
        defadr DISP_DESC_SetOnKey,0x44E80FBC+1
        defadr CreateStringInputVA,0x44D4E2D8+1
        defadr CreateListMenu,0x44D59B10+1
        defadr ListMenu_DestroyItems,0x44D5A2F8+1
        defadr ListMenu_SetItemCount,0x44D59CCC+1
        defadr ListMenu_SetItemStyle,0x44D59CFC+1
        defadr ListMenu_SetHotkeyMode,0x44D59E28+1
        defadr ListMenu_SetCursorToItem,0x44D59C9C+1
        defadr ListMenu_SetOnMessage,0x44D59DFC+1
        defadr ListMenu_GetSelectedItem,0x44D59CB0+1
        defadr GUIonMessage_GetBook,0x44D5A448+1
        defadr GUIonMessage_GetMsg,0x44D5A440+1
        defadr GUIonMessage_GetSelectedItem,0x44D5A44C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D5A46C+1
        defadr GUIonMessage_SetNumberOfSubItems,0x44D5A508+1
        defadr GUIonMessage_SetMenuItemText,0x44D5A47C+1
        defadr GUIonMessage_SetMenuItemIcon,0x44D5A4BC+1
        defadr GUIonMessage_SetItemDisabled,0x44D5A514+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x44D5A49C+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x44D5A564+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x44D5A574+1
        defadr GUIonMessage_SubItem_SetText,0x44D5A594+1
        defadr GUIonMessage_SubItem_SetDisabled,0x44D5A600+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x44D5A544+1
        defadr CreateOneOfMany,0x44D5B370+1
        defadr OneOfMany_GetSelected,0x44D5B4DC+1
        defadr OneOfMany_SetItemCount,0x44D5B4AC+1
        defadr OneOfMany_SetChecked,0x44D5B4CC+1
        defadr OneOfMany_SetTexts,0x44D5B4F4+1
        defadr GUIObject_SoftKeys_SetAction,0x44D30BD0+1
        defadr GUIObject_SoftKeys_SetText,0x44D30CC4+1
        defadr GUIObject_SoftKeys_SetVisible,0x44D30D64+1
        defadr DispObject_SoftKeys_ExecuteAction,0x44D2CA84+1
        defadr CreateTabMenuBar,0x44D314F8+1
        defadr TabMenuBar_SetTabCount,0x44D31618+1
        defadr TabMenuBar_SetTabIcon,0x44D31774+1
        defadr TabMenuBar_SetTabGui,0x44D31704+1
        defadr TabMenuBar_SetTabTitle,0x44D317A8+1
        defadr TabMenuBar_SetFocusedTab,0x44D315C4+1
        defadr TabMenuBar_GetFocusedTab,0x44D315F0+1
        defadr CreateBook,0x44E7A4B4+1
        defadr FreeBook,0x44E7AAA4+1
        defadr BookObj_SetFocus,0x44E7A73C+1
        defadr BookObj_GetBookID,0x44E7ABE0+1
        defadr BookObj_GetSession,0x44E7AAE4+1
        defadr BookObj_GotoPage,0x44E7A210+1
        defadr BookObj_CallPage,0x44E7A328+1
        defadr BookObj_ReturnPage,0x44E7A39C+1
        defadr UI_Event,0x4504D4D4+1
        defadr UI_Event_toBookID,0x4504D504+1
        defadr UI_Event_toBookIDwData,0x4504D514+1
        defadr FindBook,0x4504D3B8+1
        defadr FindBookByID,0x4504D37C+1
        defadr Find_StandbyBook,0x44E9F09C+1
        defadr IsAudioPlayerBook,0x44F55518+1
        defadr IsVolumeControllerBook,0x45147B08+1
        defadr IsRightNowBook,0x4514240C+1
        defadr isKeylocked,0x44D3D9A4+1
        defadr root_list_get_session_count,0x4504D4AC+1
        defadr root_list_get_session,0x4504D4C0+1
        defadr Display_GetTopBook,0x44E79DDC+1
        defadr GetFreeBytesOnHeap,0x44F7D9A8+1
        defadr Shortcut_Run,0x45060B24+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x450609E8+1
        defadr MenuBook_Desktop,0x4505FC64+1
        defadr Shortcut_Get_MenuItemName,0x45144F08+1
        defadr Shortcut_Get_MenuItemIconID,0x45060AA4+1
        defadr BookObj_SoftKeys_SetAction,0x4504DD34+1
        defadr BookObj_SoftKeys_SetText,0x4504DD80+1
        defadr JavaSession_GetName,0x45145410+1
        defadr JavaSession_Manager,0x451454C8+1
        defadr JavaDialog_Open,0x44C21D6C+1
        defadr JavaDialog_Close,0x44C256D8+1
        defadr JavaAppDesc_GetFirstApp,0x44C1BFDC+1
        defadr JavaAppDesc_GetNextApp,0x44C1C000+1
        defadr JavaAppDesc_GetJavaAppID,0x44C25808+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44C1BC08+1
        defadr JavaApp_LogoImageID_Get,0x44F6FB24+1
        defadr manifest_GetParam,0x45080384+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x450F1DD4+1
        defadr Display_GetHeight,0x45055A1C+1
        defadr Display_GetWidth,0x45055A2C+1
        defadr REQUEST_SYSTEM_RESTART,0x449ABF3C+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x449ABF18+1
        defadr REQUEST_DATEANDTIME_GET,0x450B8F68+1
        defadr REQUEST_SETTING_SILENCE_SET,0x451536E8+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x45153EE0+1
        defadr GetSilent,0x44F845F4+1
        defadr MessageBox,0x450592AC+1
        defadr ImageID_Free,0x44F4CAB4+1
        defadr PlaySystemSound,0x44D335F0+1
        defadr CreateMessageBox,0x450592F8+1
        defadr get_system_langID,0x44D2A018+1
        defadr lang_get_name,0x44ECB4CC+1

        defadr def_Keyhandler,0x44E79E48+1

        EXTERN  Patch_QuickAccess
        EXTERN  Patch_BookManager
        EXTERN  Patch_NextBook
        EXTERN  Patch_Screenshoter

        RSEG    PATCH_FIX_TASKKEY
        CODE16
        POP     {R4,PC}

        RSEG    PATCH_FIX_PLAYKEY
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
	BNE	_mp_button
	CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
	BL      Patch_QuickAccess
	POP	{PC}

_mp_button:
        CMP     R0, #KEY_TASK
        BNE     _play_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_BookManager
        POP	{PC}

_play_button:
        CMP     R0, #KEY_PLAY
        BNE     _def_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_NextBook
        POP	{PC}

_def_button:
        BL      def_Keyhandler
	POP	{PC}

        END
