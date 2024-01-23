//W700_R1CA021
#include "target.h"

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F89D7C+1
        defadr memfree,0x44F8AE98+1
        defadr memset,0x44B46898+1
        defadr memcpy,0x44069D54
        defadr sprintf,0x44B473C0+1
        defadr snwprintf,0x44B47AA4+1
        defadr sscanf,0x4402F928+1
        defadr swscanf,0x44B47B00+1
        defadr debug_printf,0x44AF7014+1
        defadr set_envp,0x44031AB6+1
        defadr get_envp,0x44031AA2+1
        defadr current_process,0x44068DB0
        defadr get_bid,0x44068DE8
        defadr _fopen,0x450EC374+1
        defadr fread,0x450ED870+1
        defadr fclose,0x450ED554+1
        defadr fwrite,0x450EDB0C+1
        defadr fstat,0x450ECC34+1
        defadr lseek,0x450EDC98+1
        defadr FileDelete,0x450ECD88+1
        defadr w_diropen,0x4511B760+1
        defadr w_chdir,0x45119D28+1
        defadr w_dirread,0x44D00464+1
        defadr w_fstat,0x4476D184+1
        defadr w_dirclose,0x4511B9E8+1
        defadr strlen,0x44B4788C+1
        defadr strcpy,0x44B47854+1
        defadr strncmp,0x44B478C4+1
        defadr strcmp,0x44B47824+1
        defadr strcat,0x44B477E8+1
        defadr strncpy,0x44B47900+1
        defadr strstr,0x44B4799C+1
        defadr str2wstr,0x44BF5EC4+1
        defadr wstrwstr,0x44B48110+1
        defadr wstr2strn,0x44BF4C58+1
        defadr wstrncmp,0x44BF5F50+1
        defadr wstrlen,0x44BF49F4+1
        defadr wstrcmp,0x44BF4A20+1
        defadr wstrcmpi,0x44BF6164+1
        defadr wstrrchr,0x44BF5FDC+1
        defadr wstrcpy,0x44BF4A70+1
        defadr wstrcat,0x44BF4B18+1
        defadr BookObj_GotoPage,0x44E88854+1
        defadr BookObj_CallPage,0x44E8896C+1
        defadr BookObj_GetBookID,0x44E8927C+1
        defadr TextID_Create,0x44EFA32C+1
        defadr TextID_CreateIntegerID,0x44EF9F5C+1
        defadr TextID_CreateFromChar,0x44EF9F54+1
        defadr TextID_Destroy,0x44EFA604+1
        defadr TextID_Copy,0x44EFA498+1
        defadr TextID_GetLength,0x44EFA698+1
        defadr TextID_GetString,0x44EFAFFC+1
        defadr TextID_GetWString,0x44EFA7B8+1
        defadr Disp_GetTextIDWidth,0x44E95184+1
        defadr Format_Time,0x44F6D9B4+1
        defadr TextIteratorSetTextId,0x44EFA0A8+1
        defadr CreateMessageBox,0x4506E1CC+1
        defadr ImageID_Get,0x44F5A660+1
        defadr ImageID_Free,0x44F5AA00+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x450E575C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x450E5874+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x450E59F4+1
        defadr Display_GetHeight,0x4506A804+1
        defadr Display_GetWidth,0x4506A814+1
        defadr Display_GetTopBook,0x44E88418+1
        defadr GUIObject_GetDispObject,0x44EAC810+1
        defadr DispObject_GetGUI,0x44E8FE1C+1
        defadr GUIObject_GetBook,0x44EAC838+1
        defadr DispObject_GetOnKey,0x44E8F9B8+1
        defadr DispObject_GetDESC,0x45076248+1
        defadr DISP_DESC_SetOnKey,0x44E8F63C+1
        defadr DispObject_SoftKeys_GetList,0x44D3BA80+1
        defadr DispObject_SoftKeys_ExecuteAction,0x44D3AC58+1
        defadr get_DisplayGC,0x44D46904+1
        defadr GC_PutChar,0x44D473E4+1
        defadr SetFont,0x44E94964+1
        defadr DrawString,0x44E93E10+1
        defadr DrawRect,0x44E93A08+1
        defadr GetImageWidth,0x44E950AC+1
        defadr GetImageHeight,0x44E950C4+1
        defadr GetThemeColor,0x45069B58+1
        defadr DispObject_SetLayerColor,0x44E93388+1
        defadr DispObject_SetThemeImage,0x44E92E50+1
        defadr DispObject_WindowSetSize,0x44E91D64+1
        defadr DispObject_InvalidateRect,0x44E90340+1
        defadr DispObject_SetAnimation,0x44E933E0+1
        defadr CreateListMenu,0x44D68400+1
        defadr ListMenu_SetItemCount,0x44D685BC+1
        defadr ListMenu_SetCursorToItem,0x44D6858C+1
        defadr ListMenu_GetSelectedItem,0x44D685A0+1
        defadr ListMenu_SetOnMessage,0x44D686EC+1
        defadr ListMenu_SetHotkeyMode,0x44D68718+1
        defadr ListMenu_DestroyItems,0x44D68B48+1
        defadr ListMenu_SetItemStyle,0x44D685EC+1
        defadr GUIonMessage_GetMsg,0x44D68C34+1
        defadr GUIonMessage_GetBook,0x44D68C3C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D68C60+1
        defadr GUIonMessage_SetMenuItemText,0x44D68C70+1
        defadr GUIonMessage_SetMenuItemIcon,0x44D68CB0+1
        defadr GUIonMessage_SetItemDisabled,0x44D68D08+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x44D68C90+1
        defadr GUIonMessage_GetSelectedItem,0x44D68C40+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x44D68D5C+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x44D68D4C+1
        defadr GUIonMessage_SubItem_SetText,0x44D68D6C+1
        defadr GUIonMessage_SubItem_SetDisabled,0x44D68DD8+1
        defadr GUIonMessage_SetNumberOfSubItems,0x44D68CFC+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x44D68D2C+1
        defadr GUIObject_SetTitleType,0x44D3D878+1
        defadr GUIObject_SetTitleText,0x44D3D890+1
        defadr GUIObject_SetTitleTextAlign,0x44D3D8CC+1
        defadr GUIObject_SetSecondRowTitleText,0x44D3D8AC+1
        defadr GUIObject_SetTitleBackgroundImage,0x44D698A8+1
        defadr GUIObject_SetStyle,0x44D3D7E4+1
        defadr GUIObject_Destroy,0x44EAC5C8+1
        defadr GUIObject_Show,0x44D3D794+1
        defadr DispObject_SetStyle,0x44E9340C+1
        defadr DispObject_SetTitleType,0x44E92064+1
        defadr DispObject_SetTitleText,0x44E91F48+1+1
        defadr DispObject_SetSecondRowTitleText,0x44E91F90+1
        defadr GUIObject_SoftKeys_SetText,0x44D3EFBC+1
        defadr GUIObject_SoftKeys_SetAction,0x44D3EED4+1
        defadr GUIObject_SoftKeys_SetVisible,0x44D3F054+1
        defadr GetFreeBytesOnHeap,0x44F8C220+1
        defadr isKeylocked,0x44D4E2E0+1
        defadr REQUEST_SYSTEM_RESTART,0x449B7904+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x449B78E0+1
        defadr REQUEST_DATEANDTIME_GET,0x450CDDEC+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x45163F74+1
        defadr REQUEST_SETTING_SILENCE_SET,0x4516377C+1
        defadr MessageBox,0x4506E180+1
        defadr Shortcut_Run,0x450759F4+1
        defadr MenuBook_Desktop,0x45074BB4+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x45075938+1
        defadr Shortcut_Get_MenuItemName,0x44D4D44C+1
        defadr Shortcut_Get_MenuItemIconID,0x450758B4+1
        defadr BookObj_SoftKeys_SetAction,0x45062AEC+1
        defadr BookObj_SoftKeys_SetText,0x45062B38+1
        defadr GetSilent,0x44F92E68+1
        defadr CreateBook,0x44E88AFC+1
        defadr FreeBook,0x44E89128+1
        defadr FindBook,0x45062108+1
        defadr FindBookByID,0x450620CC+1
        defadr UI_Event,0x45062224+1
        defadr BookObj_ReturnPage,0x44E889DC+1
        defadr BookObj_GetSession,0x44E8916C+1
        defadr BookObj_SetFocus,0x44E88D8C+1
        defadr Find_StandbyBook,0x44EADA8C+1
        defadr UI_Event_toBookID,0x45062254+1
        defadr UI_Event_toBookIDwData,0x45062264+1
        defadr IsAudioPlayerBook,0x44F63450+1
        defadr root_list_get_session_count,0x450621FC+1
        defadr root_list_get_session,0x45062210+1
        defadr CreateStringInputVA,0x44D5CBDC+1
        defadr CreateOneOfMany,0x44D69B7C+1
        defadr OneOfMany_GetSelected,0x44D69CE8+1
        defadr OneOfMany_SetItemCount,0x44D43048+1
        defadr OneOfMany_SetChecked,0x44D69CD8+1
        defadr OneOfMany_SetTexts,0x44D69D00+1
        defadr CreateTabMenuBar,0x44D3F7A8+1
        defadr TabMenuBar_SetTabCount,0x44D3F8C8+1
        defadr TabMenuBar_SetTabIcon,0x44D3FA24+1
        defadr TabMenuBar_SetTabGui,0x44D3F9B4+1
        defadr TabMenuBar_SetTabTitle,0x44D3FA58+1
        defadr TabMenuBar_SetFocusedTab,0x44D3F874+1
        defadr TabMenuBar_GetFocusedTab,0x44D3F8A0+1
        defadr List_Create,0x44E5D390+1
        defadr List_InsertFirst,0x44E5D4D4+1
        defadr List_InsertLast,0x44E5D4E4+1
        defadr List_GetCount,0x44E5D63C+1
        defadr List_Get,0x44E5D664+1
        defadr List_DestroyElements,0x44E5D7DC+1
        defadr List_Destroy,0x44E5D3B4+1
        defadr JavaDialog_Open,0x44C2F694+1
        defadr JavaDialog_Close,0x44C32FE0+1
        defadr JavaAppDesc_GetFirstApp,0x44C29904+1
        defadr JavaAppDesc_GetNextApp,0x44C29928+1
        defadr JavaAppDesc_GetJavaAppID,0x44C33110+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44C29530+1
        defadr JavaApp_LogoImageID_Get,0x44F7E42C+1
        defadr JavaSession_GetName,0x45038CA4+1
        defadr JavaSession_Manager,0x4503DECC+1
        defadr manifest_GetParam,0x45095244+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x45106CDC+1
        defadr PlaySystemSound,0x44D41864+1
        defadr def_Keyhandler,0x44E88484+1

        EXTERN  Patch_QuickAccess
        EXTERN  Patch_BookManager
        EXTERN  Patch_Screenshoter

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
	BNE	_mp_button
	CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
	BL      Patch_QuickAccess
	POP	{PC}

_mp_button:
        CMP     R0, #KEY_MEDIAPLAYER
        BNE     _cam_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_BookManager
        POP	{PC}

_cam_button:
        CMP     R0, #KEY_CAMERA_SHOT
        BNE     _def_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_Screenshoter
        POP	{PC}

_def_button:
        BL      def_Keyhandler
	POP	{PC}

        END
