//Z520_R3J017
#include "target.h"

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F4E00C+1
        defadr memfree,0x44F4F128+1
        defadr memset,0x44B0D8A8+1
        defadr memcmp,0x44B0D83C+1
        defadr memcpy,0x44069C88
        defadr debug_printf,0x44A9ACA4+1
        defadr sprintf,0x44B0E3D0+1
        defadr snwprintf,0x44B0EAB4+1
        defadr swscanf,0x44B0EB10+1
        defadr strcmp,0x44B0E834+1
        defadr strlen,0x44B0E89C+1
        defadr strcpy,0x44B0E864+1
        defadr strncmp,0x44B0E8D4+1
        defadr strcat,0x44B0E7F8+1
        defadr strstr,0x44B0E9AC+1
        defadr strncpy,0x44B0E910+1
        defadr str2wstr,0x44BBE4CC+1
        defadr wstr2strn,0x44BBD260+1
        defadr wstrlen,0x44BBCFFC+1
        defadr wstrcpy,0x44BBD078+1
        defadr wstrcat,0x44BBD120+1
        defadr wstrcmp,0x44BBD028+1
        defadr wstrncmp,0x44BBE558+1
        defadr wstrwstr,0x44B0F120+1
        defadr _fopen,0x450AAE04+1
        defadr fstat,0x450AB6C4+1
        defadr fread,0x450AC300+1
        defadr fwrite,0x450AC59C+1
        defadr fclose,0x450ABFE4+1
        defadr w_fstat,0x4479F68C+1
        defadr root_list_get_session_count,0x450209AC+1
        defadr root_list_get_session,0x450209C0+1
        defadr List_Create,0x44E258DC+1
        defadr List_GetCount,0x44E25B88+1
        defadr List_Get,0x44E25BB0+1
        defadr List_InsertLast,0x44E25A30+1
        defadr List_InsertFirst,0x44E25A20+1
        defadr List_DestroyElements,0x44E25D28+1
        defadr List_Destroy,0x44E25900+1
        defadr GetFreeBytesOnHeap,0x44F5049C+1
        defadr TextID_Create,0x44EC21EC+1
        defadr TextID_Copy,0x44EC2358+1
        defadr TextID_Destroy,0x44EC24C4+1
        defadr TextID_GetString,0x44EC2EBC+1
        defadr TextID_GetWString,0x44EC2678+1
        defadr REQUEST_SYSTEM_RESTART,0x449A3D84+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x449A3D60+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x45120E08+1
        defadr REQUEST_SETTING_SILENCE_SET,0x45120610+1
        defadr GetSilent,0x44F57138+1
        defadr MessageBox,0x4502CB38+1
        defadr CreateMessageBox,0x4502CB84+1
        defadr Shortcut_Run,0x450343A8+1
        defadr MenuBook_Desktop,0x450334E8+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x4503426C+1
        defadr Shortcut_Get_MenuItemName,0x45111E28+1
        defadr Shortcut_Get_MenuItemIconID,0x45034328+1
        defadr BookObj_SoftKeys_SetAction,0x4502122C+1
        defadr BookObj_SoftKeys_SetText,0x45021278+1
        defadr DispObject_SoftKeys_ExecuteAction,0x44D029A4+1
        defadr DispObject_GetGUI,0x44E5742C+1
        defadr GUIObject_GetBook,0x44E73A3C+1
        defadr GUIObject_GetDispObject,0x44E73A14+1
        defadr DispObject_SetAnimation,0x44E5AA3C+1
        defadr DispObject_GetOnKey,0x44E56FC8+1
        defadr DispObject_GetDESC,0x44EC1834+1
        defadr DISP_DESC_SetOnKey,0x44E56C4C+1
        defadr GUIObject_SetTitleType,0x44D055C4+1
        defadr GUIObject_SetTitleText,0x44D055DC+1
        defadr GUIObject_SetSecondRowTitleText,0x44D055F8+1
        defadr GUIObject_SetStyle,0x44D05530+1
        defadr GUIObject_Show,0x44D054E0+1
        defadr GUIObject_Destroy,0x44E737BC+1
        defadr GUIObject_SoftKeys_SetText,0x44D06DB4+1
        defadr GUIObject_SoftKeys_SetAction,0x44D06CCC+1
        defadr GUIObject_SoftKeys_SetVisible,0x44D06E4C+1
        defadr GUIObject_SoftKeys_SetInfoText,0x44D06D78+1
        defadr CreateListMenu,0x44D3077C+1
        defadr ListMenu_SetItemCount,0x44D30938+1
        defadr ListMenu_SetOnMessage,0x44D30A68+1
        defadr ListMenu_SetCursorToItem,0x44D30908+1
        defadr ListMenu_SetHotkeyMode,0x44D30A94+1
        defadr ListMenu_GetSelectedItem,0x44D3091C+1
        defadr ListMenu_DestroyItems,0x44D30F40+1
        defadr ListMenu_SetItemStyle,0x44D30968+1
        defadr GUIonMessage_GetBook,0x44D31090+1
        defadr GUIonMessage_GetMsg,0x44D31088+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D310B4+1
        defadr GUIonMessage_SetMenuItemText,0x44D310C4+1
        defadr GUIonMessage_SetMenuItemIcon,0x44D31104+1
        defadr GUIonMessage_SetNumberOfSubItems,0x44D31150+1
        defadr GUIonMessage_SetItemDisabled,0x44D3115C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x44D310E4+1
        defadr GUIonMessage_GetSelectedItem,0x44D31094+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x44D311CC+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x44D311BC+1
        defadr GUIonMessage_SubItem_SetText,0x44D311DC+1
        defadr GUIonMessage_SubItem_SetDisabled,0x44D31248+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x44D3118C+1
        defadr CreateBook,0x44E500D0+1
        defadr isKeylocked,0x44D13908+1
        defadr FreeBook,0x44E506E8+1
        defadr FindBook,0x450208B8+1
        defadr FindBookByID,0x4502087C+1
        defadr BookObj_GetBookID,0x44E5083C+1
        defadr BookObj_GetSession,0x44E5072C+1
        defadr BookObj_CallPage,0x44E4FF40+1
        defadr BookObj_GotoPage,0x44E4FE28+1
        defadr BookObj_ReturnPage,0x44E4FFB0+1
        defadr BookObj_SetFocus,0x44E50360+1
        defadr UI_Event,0x450209D4+1
        defadr UI_Event_toBookID,0x45020A04+1
        defadr UI_Event_toBookIDwData,0x45020A14+1
        defadr IsVolumeControllerBook,0x45114A0C+1
        defadr IsRightNowBook,0x4510EF80+1
        defadr Find_StandbyBook,0x44E748E4+1
        defadr Display_GetTopBook,0x44E4F9EC+1
        defadr CreateStringInputVA,0x44D24F98+1
        defadr ImageID_Free,0x44F21370+1
        defadr CreateOneOfMany,0x44D31FA8+1
        defadr OneOfMany_GetSelected,0x44D32114+1
        defadr OneOfMany_SetItemCount,0x44D320E4+1
        defadr OneOfMany_SetChecked,0x44D32104+1
        defadr OneOfMany_SetTexts,0x44D3212C+1
        defadr CreateTabMenuBar,0x44D07578+1
        defadr TabMenuBar_SetTabCount,0x44D07698+1
        defadr TabMenuBar_SetTabIcon,0x44D077F4+1
        defadr TabMenuBar_SetTabGui,0x44D07784+1
        defadr TabMenuBar_SetTabTitle,0x44D07828+1
        defadr TabMenuBar_SetFocusedTab,0x44D07644+1
        defadr TabMenuBar_GetFocusedTab,0x44D07670+1
        defadr JavaDialog_Open,0x44BF7BD4+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44BF1B38+1
        defadr JavaAppDesc_GetJavaAppID,0x44BFB61C+1
        defadr JavaAppDesc_GetFirstApp,0x44BF1F0C+1
        defadr JavaAppDesc_GetNextApp,0x44BF1F30+1
        defadr JavaApp_LogoImageID_Get,0x44F44194+1
        defadr JavaDialog_Close,0x44BFB4EC+1
        defadr JavaSession_GetName,0x4511233C+1
        defadr JavaSession_Manager,0x451123F4+1
        defadr manifest_GetParam,0x45053ADC+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x450C467C+1
        defadr Display_GetHeight,0x4502917C+1
        defadr Display_GetWidth,0x4502918C+1
        defadr PlaySystemSound,0x44D095A8+1
        defadr IsAudioPlayerBook,0x44F29D68+1
        defadr IsExternalDisplay,0x44D058E4+1
        defadr REQUEST_DATEANDTIME_GET,0x4508C684+1

        defadr def_Keyhandler,0x44E4FA58+1

        EXTERN  Patch_QuickAccess
        EXTERN  Patch_BookManager
        EXTERN  Patch_NextBook

        RSEG    PATCH_FIX_MPKEY
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
	BNE	_op_button
	CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
	BL      Patch_QuickAccess
	POP	{PC}

_op_button:
        CMP     R0, #KEY_OPERATOR
        BNE     _cam_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_BookManager
        POP	{PC}

_cam_button:
        CMP     R0, #KEY_CAMERA
        BNE     _def_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_NextBook
        POP	{PC}

_def_button:
        BL      def_Keyhandler
	POP	{PC}

        END
