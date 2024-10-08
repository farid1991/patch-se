//W200_R4HA014
#include "target.h"

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x452C26B8+1
        defadr memfree,0x452C33EC+1
        defadr memset,0x44CA43B8+1
        defadr memcmp,0x44CA434C+1
        defadr memcpy,0x4418515C
        defadr debug_printf,0x44C593F0+1
        defadr sprintf,0x44CA4EBC+1
        defadr snwprintf,0x44CA5594+1
        defadr swscanf,0x44CA55F0+1
        defadr strcmp,0x44CA5320+1
        defadr strlen,0x44CA5388+1
        defadr strcpy,0x44CA5350+1
        defadr strncmp,0x44CA53C0+1
        defadr strcat,0x44CA52E4+1
        defadr strstr,0x44CA5498+1
        defadr strncpy,0x44CA53FC+1
        defadr str2wstr,0x44E6A2E8+1
        defadr wstr2strn,0x44E690E0+1
        defadr wstrlen,0x44CA5C9C+1
        defadr wstrcpy,0x44CA5C60+1
        defadr wstrcat,0x44CA5C00+1
        defadr wstrcmp,0x44CA5C30+1
        defadr wstrncmp,0x44CA5CD8+1
        defadr wstrwstr,0x44CA5E74+1
        defadr _fopen,0x45426824+1
        defadr fstat,0x45427098+1
        defadr fread,0x45427CBC+1
        defadr fwrite,0x45427EA0+1
        defadr fclose,0x45427A5C+1
        defadr w_fstat,0x449723F4+1
        defadr root_list_get_session_count,0x4539DDC4+1
        defadr root_list_get_session,0x4539DDD8+1
        defadr List_Create,0x450F3958+1
        defadr List_GetCount,0x450F3BD4+1
        defadr List_Get,0x450F3BFC+1
        defadr List_InsertLast,0x450F3A7C+1
        defadr List_InsertFirst,0x450F3A6C+1
        defadr List_DestroyElements,0x450F3D60+1
        defadr List_Destroy,0x450F3970+1
        defadr GetFreeBytesOnHeap,0x452C4344+1
        defadr TextID_Create,0x451723F4+1
        defadr TextID_Copy,0x45172528+1
        defadr TextID_Destroy,0x451725C4+1
        defadr TextID_GetString,0x45172FA0+1
        defadr TextID_GetWString,0x45172774+1
        defadr REQUEST_SYSTEM_RESTART,0x44BC0DD4+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x44BC0DB0+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x454B15C8+1
        defadr REQUEST_SETTING_SILENCE_SET,0x454B0D9C+1
        defadr GetSilent,0x452CB250+1
        defadr MessageBox,0x453A0804+1
        defadr CreateMessageBox,0x453A0850+1
        defadr Shortcut_Run,0x454A7294+1
        defadr MenuBook_Desktop,0x453A5CC8+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x453A6C68+1
        defadr Shortcut_Get_MenuItemName,0x454A507C+1
        defadr Shortcut_Get_MenuItemIconID,0x453A6D14+1
        defadr BookObj_SoftKeys_SetAction,0x453B5E9C+1
        defadr BookObj_SoftKeys_SetText,0x453B5EE8+1
        defadr DispObject_SoftKeys_ExecuteAction,0x4500872C+1
        defadr DispObject_GetGUI,0x45176210+1
        defadr DispObject_SetAnimation,0x45179EA4+1
        defadr DispObject_GetOnKey,0x45175D2C+1
        defadr DispObject_GetDESC,0x45198430+1
        defadr DISP_DESC_SetOnKey,0x45175A88+1
        defadr GUIObject_GetBook,0x45003280+1
        defadr GUIObject_GetDispObject,0x4500326C+1
        defadr GUIObject_SetTitleType,0x45003584+1
        defadr GUIObject_SetTitleText,0x450035A8+1
        defadr GUIObject_SetSecondRowTitleText,0x450035C4+1
        defadr GUIObject_SetStyle,0x450034F0+1
        defadr GUIObject_Show,0x45003490+1
        defadr GUIObject_Destroy,0x45003210+1
        defadr GUIObject_SoftKeys_SetText,0x4500B01C+1
        defadr GUIObject_SoftKeys_SetAction,0x4500AF34+1
        defadr GUIObject_SoftKeys_SetVisible,0x4500B0B4+1
        defadr GUIObject_SoftKeys_SetInfoText,0x4500AFE0+1
        defadr CreateListMenu,0x44FDFA8C+1
        defadr ListMenu_SetItemCount,0x44FDFCB4+1
        defadr ListMenu_SetOnMessage,0x44FDFDF0+1
        defadr ListMenu_SetCursorToItem,0x44FDFC88+1
        defadr ListMenu_SetHotkeyMode,0x44FDFE1C+1
        defadr ListMenu_GetSelectedItem,0x44FDFC9C+1
        defadr ListMenu_DestroyItems,0x44FE0340+1
        defadr ListMenu_SetItemStyle,0x44FDFD00+1
        defadr GUIonMessage_GetBook,0x44FE0798+1
        defadr GUIonMessage_GetMsg,0x44FE0790+1
        defadr GUIonMessage_GetSelectedItem,0x44FE079C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44FE07BC+1
        defadr GUIonMessage_SetMenuItemText,0x44FE07CC+1
        defadr GUIonMessage_SetMenuItemIcon,0x44FE080C+1
        defadr GUIonMessage_SetItemDisabled,0x44FE0864+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x44FE07EC+1
        defadr GUIonMessage_SetNumberOfSubItems,0x44FE0858+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x44FE08D4+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x44FE08C4+1
        defadr GUIonMessage_SubItem_SetText,0x44FE08E4+1
        defadr GUIonMessage_SubItem_SetDisabled,0x44FE094C+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x44FE0894+1
        defadr CreateBook,0x45113814+1
        defadr isKeylocked,0x44FCF70C+1
        defadr FreeBook,0x45113D3C+1
        defadr FindBook,0x4539DCD0+1
        defadr FindBookByID,0x4539DC94+1
        defadr BookObj_GetBookID,0x45113DD0+1
        defadr BookObj_GetSession,0x45113D74+1
        defadr BookObj_CallPage,0x451136A0+1
        defadr BookObj_GotoPage,0x45113590+1
        defadr BookObj_ReturnPage,0x4511370C+1
        defadr BookObj_SetFocus,0x45113A58+1
        defadr UI_Event,0x4539DDEC+1
        defadr UI_Event_toBookID,0x4539DE1C+1
        defadr UI_Event_toBookIDwData,0x4539DE2C+1
        defadr IsVolumeControllerBook,0x454A7CBC+1
        defadr IsRightNowBook,0x454A2718+1
        defadr Find_StandbyBook,0x45120864+1
        defadr Display_GetTopBook,0x451130E8+1
        defadr CreateStringInputVA,0x44FDCF50+1
        defadr ImageID_Free,0x45295CB0+1
        defadr CreateOneOfMany,0x44FE1B84+1
        defadr OneOfMany_GetSelected,0x44FE1D4C+1
        defadr OneOfMany_SetItemCount,0x44FE1D18+1
        defadr OneOfMany_SetChecked,0x44FE1D3C+1
        defadr OneOfMany_SetTexts,0x44FE1D70+1
        defadr CreateTabMenuBar,0x44FCABA0+1
        defadr TabMenuBar_SetTabCount,0x44FCACB0+1
        defadr TabMenuBar_SetTabIcon,0x44FCAE70+1
        defadr TabMenuBar_SetTabGui,0x44FCAD94+1
        defadr TabMenuBar_SetTabTitle,0x44FCAEA0+1
        defadr TabMenuBar_SetFocusedTab,0x44FCAC64+1
        defadr TabMenuBar_GetFocusedTab,0x44FCAC8C+1
        defadr JavaDialog_Open,0x44EA0060+1
        defadr JavaDialog_Close,0x44EA3408+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44E9B008+1
        defadr JavaAppDesc_GetJavaAppID,0x44EA3538+1
        defadr JavaAppDesc_GetFirstApp,0x44E9B300+1
        defadr JavaAppDesc_GetNextApp,0x44E9B308+1
        defadr JavaApp_LogoImageID_Get,0x452B8FC8+1
        defadr JavaSession_Manager,0x454A5654+1
        defadr JavaSession_GetName,0x454A559C+1
        defadr manifest_GetParam,0x453D397C+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x4543E2D8+1
        defadr Display_GetHeight,0x453B3164+1
        defadr Display_GetWidth,0x453B3174+1
        defadr PlaySystemSound,0x44FCB25C+1
        defadr IsAudioPlayerBook,0x4529F19C+1
        defadr REQUEST_DATEANDTIME_GET,0x4540EB0C+1
        defadr OSE_GetShell,0x44F18430+1
        defadr png_get_io_ptr,0x44ABB4E4+1
        defadr png_create_write_struct_2,0x44AC0D10+1
        defadr png_create_info_struct,0x44ABB400+1
        defadr png_destroy_write_struct,0x44AC0EC0+1
        defadr png_set_IHDR,0x44AC087C+1
        defadr png_set_bgr,0x44AC0AD0+1
        defadr png_set_filler,0x44AC0B14+1
        defadr png_set_write_fn,0x44AC0C54+1
        defadr png_write_info,0x44AC0CB0+1
        defadr png_write_row,0x44AC0E34+1
        defadr png_write_end,0x44AC0CE4+1
        defadr def_Keyhandler,0x4511315C+1

        EXTERN  Patch_QuickAccess
        EXTERN  Patch_BookManager
        EXTERN  Patch_Screenshoter

        RSEG    PATCH_FIX_MPKEY
        CODE16
        POP     {R3,R4,PC}

        RSEG    PATCH_KEYHANDLER
        DATA
        DCD     keyhandler

        RSEG  CODE
        CODE16
keyhandler:
	PUSH	{LR}
        CMP     R0, #KEY_MEDIAPLAYER
        BNE     _def_button
        CMP	R2, #KBD_SHORT_RELEASE
	BNE	_def_button
        BL      Patch_Screenshoter
        POP	{PC}

_def_button:
        BL      default
	POP	{PC}

default:
        LDR     R3, =def_Keyhandler
        BX      R3

        END
