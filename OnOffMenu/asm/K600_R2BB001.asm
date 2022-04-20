//K600_R2BB001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20363C0C+1
        defadr memfree,0x20364D24+1
        defadr memset,0x20D66768+1
        defadr debug_printf,0x20D28E84+1

        defadr isKeylocked,0x20760810+1
        defadr MessageBox,0x20431AA4+1
        defadr strcmp,0x20D67710+1
        defadr GetFreeBytesOnHeap,0x20366108+1
        defadr snwprintf,0x20D67990+1
        defadr TextID_Create,0x202CFF38+1
        defadr FreeBook,0x2025D550+1
        defadr ListMenu_GetSelectedItem,0x2077CB54+1
        defadr GUIonMessage_GetMsg,0x2077D538+1
        defadr GUIonMessage_GetBook,0x2077D540+1
        defadr GUIonMessage_GetCreatedItemIndex,0x2077D564+1
        defadr GUIonMessage_SetMenuItemText,0x2077D574+1
        defadr GUIonMessage_SetMenuItemIcon,0x2077D5B4+1
        defadr CreateListMenu,0x2077C9B4+1
        defadr GUIObject_SetStyle,0x20751E64+1
        defadr GUIObject_SetTitleType,0x20751EF8+1
        defadr GUIObject_SetTitleText,0x20751F10+1
        defadr GUIObject_SetSecondRowTitleText,0x20751F2C+1
        defadr ListMenu_SetItemCount,0x2077CB70+1
        defadr ListMenu_SetOnMessage,0x2077CCA0+1
        defadr ListMenu_SetCursorToItem,0x2077CB40+1
        defadr ListMenu_SetHotkeyMode,0x2077CCCC+1
        defadr GUIObject_SoftKeys_SetAction,0x20753704+1
        defadr GUIObject_Show,0x20751E14+1
        defadr GUIObject_Destroy,0x20280C7C+1
        defadr FindBook,0x20425C9C+1
        defadr CreateBook,0x2025CF38+1
        defadr BookObj_GotoPage,0x2025CC90+1
        defadr BookObj_SetFocus,0x2025D1C8+1
        defadr BookObj_Show,0x2025D20C+1
        defadr UI_Event,0x20425DB8+1
        defadr Display_GetTopGUI,0x20280DEC+1
        defadr REQUEST_SYSTEM_RESTART,0x20549450+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x20549440+1
        defadr FlightMode_GetState,0x2074C9D4+1
        defadr FlightMode_SetState,0x2074C9E8+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x2055527C+1
        defadr REQUEST_SETTING_SILENCE_SET,0x20554A20+1
        defadr GetSilent,0x20467A68+1
        defadr Shortcut_Run,0x20439390+1

        EXTERN  Create_QuickAccess_Book

        RSEG  CODE
        CODE16
OnOffButton:
	PUSH	{LR}
	CMP	R0, #0
	BNE	_other_button
	CMP	R2, #3
	BNE	_other_button
	BL      Create_QuickAccess_Book
	POP	{PC}

_other_button:
	LDR	R5, =0x2025C8A8+1
	BLX	R5
	POP	{PC}

        RSEG    PATCH_STANDBY_EVENT
        DATA
        DCD     OnOffButton

        END
