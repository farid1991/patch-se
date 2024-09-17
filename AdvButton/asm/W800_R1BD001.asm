//W800_R1BD001
#include "target.h"

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F8145C+1
        defadr memfree,0x44F82578+1
        defadr memset,0x44B42F8C+1
        defadr memcpy,0x44069D60
        defadr sprintf,0x44B43AB4+1
        defadr snwprintf,0x44B44198+1
        defadr sscanf,0x4402F934+1
        defadr swscanf,0x44B441F4+1
        defadr debug_printf,0x44AC8A7C+1
        defadr set_envp,0x44031AC2+1
        defadr get_envp,0x44031AAE+1
        defadr current_process,0x44068DBC
        defadr get_bid,0x44068DF4
        defadr _fopen,0x450E5728+1
        defadr fread,0x450E6C24+1
        defadr fclose,0x450E6908+1
        defadr fwrite,0x450E6EC0+1
        defadr fstat,0x450E5FE8+1
        defadr lseek,0x450E704C+1
        defadr FileDelete,0x450E613C+1
        defadr w_diropen,0x45114B54+1
        defadr w_chdir,0x4511311C+1
        defadr w_dirread,0x44CFC2AC+1
        defadr w_fstat,0x4480D50C+1
        defadr w_dirclose,0x45114DDC+1
        defadr strncmp,0x44B43FB8+1
        defadr strcmp,0x44B43F18+1
        defadr strlen,0x44B43F80+1
        defadr strcat,0x44B43EDC+1
        defadr strstr,0x44B44090+1
        defadr strncpy,0x44B43FF4+1
        defadr strcpy,0x44B43F48+1
        defadr str2wstr,0x44BF1BB0+1
        defadr wstrwstr,0x44B44804+1
        defadr wstr2strn,0x44BF0944+1
        defadr wstrncmp,0x44BF1C3C+1
        defadr wstrcpy,0x44BF075C+1
        defadr wstrcat,0x44BF0804+1
        defadr wstrlen,0x44BF06E0+1
        defadr wstrcmp,0x44BF070C+1
        defadr wstrcmpi,0x44BF1E50+1
        defadr wstrrchr,0x44BF1CC8+1
        defadr BookObj_GotoPage,0x44E827BC+1
        defadr BookObj_CallPage,0x44E828D4+1
        defadr BookObj_GetBookID,0x44E831E4+1
        defadr TextID_Create,0x44EF41C4+1
        defadr TextID_CreateIntegerID,0x44EF3DF4+1
        defadr TextID_CreateFromChar,0x44EF3DEC+1
        defadr TextID_Destroy,0x44EF449C+1
        defadr TextID_Copy,0x44EF4330+1
        defadr TextID_GetString,0x44EF4E94+1
        defadr TextID_GetWString,0x44EF4650+1
        defadr TextID_GetLength,0x44EF4530+1
        defadr Disp_GetTextIDWidth,0x44E8F0EC+1
        defadr Format_Time,0x44F6649C+1
        defadr TextIteratorSetTextId,0x44EF3F40+1
        defadr MessageBox,0x45067520+1
        defadr CreateMessageBox,0x4506756C+1
        defadr ImageID_Get,0x44F53180+1
        defadr ImageID_Free,0x44F53520+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x450DEB10+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x450DEC28+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x450DEDA8+1
        defadr Display_GetHeight,0x45063BA4+1
        defadr Display_GetWidth,0x45063BB4+1
        defadr Display_GetTopBook,0x44E82380+1
        defadr GUIObject_GetDispObject,0x44EA6780+1
        defadr DispObject_GetGUI,0x44E89D84+1
        defadr GUIObject_GetBook,0x44EA67A8+1
        defadr DispObject_GetOnKey,0x44E89920+1
        defadr DispObject_GetDESC,0x4506F5E4+1
        defadr DISP_DESC_SetOnKey,0x44E895A4+1
        defadr DispObject_SoftKeys_GetList,0x44D378B4+1
        defadr DispObject_SoftKeys_ExecuteAction,0x44D36A8C+1
        defadr get_DisplayGC,0x44D42738+1
        defadr GC_PutChar,0x44D43218+1
        defadr SetFont,0x44E8E8CC+1
        defadr DrawString,0x44E8DD78+1
        defadr DrawRect,0x44E8D970+1
        defadr GetImageWidth,0x44E8F014+1
        defadr GetImageHeight,0x44E8F02C+1
        defadr GetThemeColor,0x45062EF8+1
        defadr DispObject_SetLayerColor,0x44E8D2F0+1
        defadr DispObject_SetThemeImage,0x44E8CDB8+1
        defadr DispObject_WindowSetSize,0x44E8BCCC+1
        defadr DispObject_InvalidateRect,0x44E8A2A8+1
        defadr DispObject_SetAnimation,0x44E8D348+1
        defadr CreateListMenu,0x44D64144+1
        defadr ListMenu_SetItemCount,0x44D64300+1
        defadr ListMenu_SetCursorToItem,0x44D642D0+1
        defadr ListMenu_GetSelectedItem,0x44D642E4+1
        defadr ListMenu_SetOnMessage,0x44D64430+1
        defadr ListMenu_SetHotkeyMode,0x44D6445C+1
        defadr ListMenu_DestroyItems,0x44D6488C+1
        defadr ListMenu_SetItemStyle,0x44D64330+1
        defadr GUIonMessage_GetMsg,0x44D64978+1
        defadr GUIonMessage_GetBook,0x44D64980+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D649A4+1
        defadr GUIonMessage_SetMenuItemText,0x44D649B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x44D649F4+1
        defadr GUIonMessage_SetNumberOfSubItems,0x44D64A40+1
        defadr GUIonMessage_SetItemDisabled,0x44D64A4C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x44D649D4+1
        defadr GUIonMessage_GetSelectedItem,0x44D64984+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x44D64AA0+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x44D64A90+1
        defadr GUIonMessage_SubItem_SetText,0x44D64AB0+1
        defadr GUIonMessage_SubItem_SetDisabled,0x44D64B1C+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x44D64A70+1
        defadr GUIObject_SetTitleType,0x44D396AC+1
        defadr GUIObject_SetTitleText,0x44D396C4+1
        defadr GUIObject_SetTitleTextAlign,0x44D39700+1
        defadr GUIObject_SetSecondRowTitleText,0x44D396E0+1
        defadr GUIObject_SetTitleBackgroundImage,0x44D655DC+1
        defadr GUIObject_SetStyle,0x44D39618+1
        defadr GUIObject_Destroy,0x44EA6538+1
        defadr GUIObject_Show,0x44D395C8+1
        defadr DispObject_SetStyle,0x44E8D374+1
        defadr DispObject_SetTitleType,0x44E8BFCC+1
        defadr DispObject_SetTitleText,0x44E8BEB0+1
        defadr DispObject_SetSecondRowTitleText,0x44E8BEF8+1
        defadr GUIObject_SoftKeys_SetText,0x44D3ADF0+1
        defadr GUIObject_SoftKeys_SetAction,0x44D3AD08+1
        defadr GUIObject_SoftKeys_SetVisible,0x44D3AE88+1
        defadr REQUEST_SYSTEM_RESTART,0x44A32D88+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x44A32D64+1
        defadr REQUEST_DATEANDTIME_GET,0x450C71A4+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x4515D370+1
        defadr REQUEST_SETTING_SILENCE_SET,0x4515CB78+1
        defadr Shortcut_Run,0x4506ED90+1
        defadr GetSilent,0x44F8A538+1
        defadr GetFreeBytesOnHeap,0x44F838F0+1
        defadr CreateBook,0x44E82A64+1
        defadr FreeBook,0x44E83090+1
        defadr FindBook,0x4505B4C8+1
        defadr FindBookByID,0x4505B48C+1
        defadr UI_Event,0x4505B5E4+1
        defadr isKeylocked,0x44D47AE8+1
        defadr PlaySystemSound,0x44D3D68C+1
        defadr IsAudioPlayerBook,0x44F5BF28+1
        defadr BookObj_ReturnPage,0x44E82944+1
        defadr BookObj_GetSession,0x44E830D4+1
        defadr BookObj_SetFocus,0x44E82CF4+1
        defadr Find_StandbyBook,0x44EA79F4+1
        defadr UI_Event_toBookID,0x4505B614+1
        defadr UI_Event_toBookIDwData,0x4505B624+1
        defadr root_list_get_session_count,0x4505B5BC+1
        defadr root_list_get_session,0x4505B5D0+1
        defadr CreateStringInputVA,0x44D58960+1
        defadr CreateOneOfMany,0x44D658B0+1
        defadr OneOfMany_GetSelected,0x44D65A1C+1
        defadr OneOfMany_SetItemCount,0x44D659EC+1
        defadr OneOfMany_SetChecked,0x44D65A0C+1
        defadr OneOfMany_SetTexts,0x44D65A34+1
        defadr CreateTabMenuBar,0x44D3B5DC+1
        defadr TabMenuBar_SetTabCount,0x44D3B6FC+1
        defadr TabMenuBar_SetTabIcon,0x44D3B858+1
        defadr TabMenuBar_SetTabGui,0x44D3B7E8+1
        defadr TabMenuBar_SetTabTitle,0x44D3B88C+1
        defadr TabMenuBar_SetFocusedTab,0x44D3B6A8+1
        defadr TabMenuBar_GetFocusedTab,0x44D3B6D4+1
        defadr List_Create,0x44E57300+1
        defadr List_InsertFirst,0x44E57444+1
        defadr List_InsertLast,0x44E57454+1
        defadr List_GetCount,0x44E575AC+1
        defadr List_Get,0x44E575D4+1
        defadr List_DestroyElements,0x44E5774C+1
        defadr List_Destroy,0x44E57324+1
        defadr JavaDialog_Open,0x44C2B380+1
        defadr JavaAppDesc_GetFirstApp,0x44C255F0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44C2521C+1
        defadr JavaAppDesc_GetJavaAppID,0x44C2EDFC+1
        defadr JavaApp_LogoImageID_Get,0x44F76F1C+1
        defadr JavaAppDesc_GetNextApp,0x44C25614+1
        defadr JavaDialog_Close,0x44C2ECCC+1
        defadr JavaSession_GetName,0x45032090+1
        defadr JavaSession_Manager,0x450372A4+1
        defadr manifest_GetParam,0x4508E5E4+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x451000D0+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x4506ECD4+1
        defadr MenuBook_Desktop,0x4506DF50+1
        defadr BookObj_SoftKeys_SetAction,0x4505BEAC+1
        defadr BookObj_SoftKeys_SetText,0x4505BEF8+1
        defadr Shortcut_Get_MenuItemName,0x44D49280+1
        defadr Shortcut_Get_MenuItemIconID,0x44D49E90+1
        defadr OSE_GetShell,0x44CA1814+1
        defadr png_get_io_ptr,0x449597E0+1
        defadr png_create_write_struct_2,0x4495F014+1
        defadr png_create_info_struct,0x449596FC+1
        defadr png_destroy_write_struct,0x4495F1C4+1
        defadr png_set_IHDR,0x4495EB80+1
        defadr png_set_bgr,0x4495EDD4+1
        defadr png_set_filler,0x4495EE18+1
        defadr png_set_write_fn,0x4495EF58+1
        defadr png_write_info,0x4495EFB4+1
        defadr png_write_row,0x4495F138+1
        defadr png_write_end,0x4495EFE8+1
        defadr def_Keyhandler,0x44E823EC+1

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
