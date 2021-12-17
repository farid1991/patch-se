//G502_R1FA037

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
        
        defadr memalloc,0x1009ED08
        defadr memfree,0x1009ED30
        defadr memset,0x2A1C07A0
        defadr getFileExtention,0x10FDF150+1
        defadr FILEITEM_SetFname,0x1102BC6C+1
        defadr FILEITEM_SetPath,0x1102BF2C+1
        defadr FILEITEM_GetFname,0x1102BF24+1
        defadr FILEITEM_GetPath,0x1102BFB8+1
        defadr FILEITEM_SetFnameAndContentType,0x1102BCCC+1
        defadr FILEITEM_SetPathAndContentType,0x1102BF90+1
        defadr DataBrowserDesc_Create,0x11022DC0+1
        defadr DataBrowserDesc_SetHeaderText,0x11023070+1
        defadr DataBrowserDesc_SetBookID,0x11022FC0+1
        defadr DataBrowserDesc_SetFolders,0x11023058+1
        defadr DataBrowserDesc_SetFoldersNumber,0x11023060+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x11022FC8+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1102302C+1
        defadr DataBrowser_Create,0x1101F2D0+1
        defadr DataBrowserDesc_Destroy,0x11022E70+1
        defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x1100D4A8+1
        defadr TextID_Create,0x1168442C+1
        defadr BookObj_GotoPage,0x1160376C+1
        defadr BookObj_GetBookID,0x116040AC+1
        defadr CreatePasswordInputWindow,0x10F3C304+1
        defadr get_envp,0x100A9A1C+1
        defadr set_envp,0x100A9A30+1
        defadr get_bid,0x100F4140
        defadr current_process,0x100F4108
        defadr wstrcmp,0x10FCD2A0+1
        defadr GUIObject_SoftKeys_SetAction,0x116C046C+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x116C06A8+1
        defadr FileDelete,0x10FDC830+1
        defadr FileMove,0x10FDCD4C+1
        defadr debug_printf,0x2A20E3E1
        defadr wstrcat,0x10FCD314+1
        defadr wstrlen,0x10FCD28C+1
        defadr GetMemoryStickStatus,0x10F6B2B4+1
        defadr MainDisplay_GetTopBook,0x11603564+1
        defadr UI_Event_toBookID,0x11602894+1

        RSEG   SET_KEY_FILE_1
        CODE16
        LDR    R3, =set_key_file_1
        BX     R3
        
        RSEG   SET_KEY_FILE_2
        CODE16
        LDR    R3, =set_key_file_2
        BX     R3
        
        RSEG   SET_KEY_PATH
        CODE16
        LDR    R3, =set_key_path
        BX     R3
        
        RSEG   FILE_DELETE
        CODE16
        LDR    R3, =file_delete
        BX     R3
        
        EXTERN SetFileDelete
        EXTERN SetKey
        
        RSEG   CODE
        CODE16
set_key_file_1:
        ldr 	r2, =0x1100F870+1
        ldr 	r0, [r4,#0x10]
        mov 	r1, r5
        ldr 	r3, =GUIObject_SoftKeys_SetAction
        blx 	r3
        mov 	r1, #0
        ldr 	r0, [r4,#0x10]
        bl	SetKey
	ldr 	r0, [r4,#0x10]
        ldr	r3, =0x11011EBC+1
        bx	r3
set_key_file_2:
        ldr 	r1, =0xFAF
        ldr 	r0, [r0,#0x10]
        ldr 	r3, =GUIObject_SoftKeys_SetAction
        blx 	r3
        mov 	r1, #0
        ldr 	r0, [r5,#0]
        ldr 	r0, [r0,#0x10]
        bl	SetKey
        ldr 	r3, =0x110246E4+1
        bx	r3
		
set_key_path:
        ldr 	r2, =0x1100E600+1
        ldr 	r1, =0xFC5
        ldr 	r0, [r5,#0x14]
        ldr 	r3, =GUIObject_SoftKeys_SetAction
        blx 	r3
        mov 	r1, #1
        ldr 	r0, [r5,#0x14]
        bl	SetKey
        ldr 	r3, =0x1100E5A6+1
        bx	r3
		
file_delete:
	LDR	R0, [SP,#4]
	MOV	R2, #0
	ADD	R0, #0xA
        bl	SetFileDelete
        ldr	r3, =0x1102D94E+1
        bx	r3

        END
        