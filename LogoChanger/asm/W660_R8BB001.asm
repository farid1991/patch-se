//W660_R8BB001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44E6C3FC+1
        defadr memfree,0x44E6C428+1
        defadr memset,0x441452B8
        defadr memcpy,0x443F42E8
        defadr get_envp,0x443E4720+1
        defadr set_envp,0x443E4734+1
        defadr TextID_Destroy,0x4546E31C+1
        defadr DispObject_InvalidateRect,0x45481BF8+1
        defadr Timer_ReSet,0x453D2BE8+1
        defadr Timer_Set,0x453D2BB4+1
        defadr Timer_Kill,0x453D2C40+1
        defadr SetFont,0x45485370+1
        defadr DrawString,0x45484914+1
        defadr Display_GetWidth,0x4549EB6C+1
        defadr TextID_Create,0x4546E154+1
        defadr Date2ID,0x453D1D68+1
        defadr Time2ID,0x453D1C90+1
        defadr DATE_GetWeekDay,0x4512DC2C+1
        defadr REQUEST_DATEANDTIME_GET,0x44E72988+1
        defadr GetImageWidth,0x454858E8+1
        defadr GetImageHeight,0x454858FC+1
        defadr get_DisplayGC,0x45489330+1
        defadr GC_PutChar,0x45489E08+1
        defadr FSX_IsFileExists,0x44FF5158+1
        defadr _fopen,0x44FB14D4+1
        defadr fclose,0x44FB2AA0+1
        defadr fread,0x44FB2D28+1
        defadr fwrite,0x44FB2EF4+1
        defadr _wstat,0x4498D17C+1
        defadr fputs,0x452DBB4C+1
        defadr fstat,0x44FB1E68+1
        defadr wstrcpy,0x4467B814+1
        defadr wstrlen,0x44F71848+1
        defadr MessageBox,0x453E112C+1
        defadr FileDelete,0x44FB1FAC+1
        defadr BookObj_KillBook,0x453D6010+1
        defadr BookObj_GotoPage,0x453D5C64+1
        defadr BookObj_ReturnPage,0x453D5DCC+1
        defadr FreeBook,0x453D6504+1
        defadr FindBook,0x453D45A8+1
        defadr CreateStringInput,0x4541D1F0+1
        defadr StringInput_SetText,0x4541DCD8+1
        defadr StringInput_SetMaxLen,0x4541DBD8+1
        defadr StringInput_SetMode,0x4541DAE0+1
        defadr StringInput_SetEnableEmptyText,0x4541DC54+1
        defadr StringInput_SetActionOK,0x4541DB2C+1
        defadr StringInput_GetStringAndLen,0x4541DB58+1
        defadr GUIObject_Show,0x4548BAB4+1
        defadr GUIonMessage_GetMsg,0x45445CC8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x45445CEC+1
        defadr GUIonMessage_SetMenuItemText,0x45445CF8+1
        defadr GUIonMessage_SetMenuItemIcon,0x45445D70+1
        defadr CreateListMenu,0x45444F94+1
        defadr ListMenu_SetItemCount,0x454451C4+1
        defadr ListMenu_SetCursorToItem,0x4544519C+1
        defadr ListMenu_SetOnMessage,0x454452F0+1
        defadr ListMenu_SetHotkeyMode,0x4544531C+1
        defadr ListMenu_GetSelectedItem,0x454451B0+1
        defadr GUIObject_SoftKeys_SetText,0x454A8440+1
        defadr GUIObject_SoftKeys_SetAction,0x454A83C8+1
        defadr GUIObject_SetTitleIcon,0x4548C01C+1
        defadr GUIObject_SetTitleText,0x4548BFE4+1

        defadr SetOperatorName,0x453EB014+1
        defadr GetOperatorName,0x44EFB8A0+1

        defadr onBackPressed,0x44EA77B8+1
        defadr onLongBackPressed,0x4533F080+1
        defadr pg_EditPhoneName_EnterEvent,0x44EA7650+1
        defadr pg_EditPhoneName_ExitEvent,0x44EA5C80+1

        EXTERN ReadOnFile
        EXTERN evtlst_EditPhoneName_new

//--------------------------------------

	RSEG	PATCH_NEW_EVENTLIST
	DATA
	DCD	evtlst_EditPhoneName_new

//--------------------------------------

	RSEG	PATCH_GET_NEWOPNAME
	CODE16
	LDR	R3, =GetOpName
	BX	R3

	RSEG	CODE
        CODE16
GetOpName:
        ADD     R5, R2, #0
	BL	ReadOnFile
        CMP     R0, #0
        BEQ     No_Patch
        MOV	R1, #0
        MOV     R2, #0xFF
        B       SetName
No_Patch:
	ADD	R2, R5,	#0
	MOV	R1, #0
	ADD	R0, R6,	#0
SetName:
        BL      j_TextID_Create
        LDR     R3, =0x44EFB96C+1
        BX      R3

j_TextID_Create:
        LDR     R3, =TextID_Create
        BX      R3

        END
