//U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
        
        defadr debug_printf,0x4FC00008
	defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
	defadr memset,0x140EA530
        defadr memcpy,0x1482A864
        defadr current_process,0x10292B7C
        defadr get_bid,0x10292BB4
	defadr get_envp,0x102932CC+1
	defadr set_envp,0x102932E0+1

        defadr MainDisplay_GetTopBook,0x143A8A48+1
        defadr BookObj_GotoPage,0x145A1C58+1
        defadr BookObj_GetBookID,0x143D9B54+1
        defadr UI_Event_toBookID,0x14647524+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x14668620+1

        defadr TextID_Create,0x145382A0+1

        defadr FILEITEM_GetPath,0x146D2464+1
        defadr FILEITEM_GetFname,0x146D27F0+1
        defadr FILEITEM_SetPath,0x146D2380+1
        defadr FILEITEM_SetFnameAndContentType,0x146D1E2C+1
        defadr FileMove,0x1465D984+1
        defadr FileDelete,0x1465DD28+1

        defadr GetMemoryStickStatus,0x14765274+1
        defadr CreatePasswordInputWindow,0x14160EBC+1

        defadr DataBrowserDesc_Create,0x145BAA1C+1
        defadr DataBrowserDesc_SetHeaderText,0x145BAAC0+1
        defadr DataBrowserDesc_SetBookID,0x145BA95C+1
        defadr DataBrowserDesc_SetFolders,0x145BAAB8+1
        defadr DataBrowserDesc_SetFoldersNumber,0x145BA96C+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x151977F0+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x145BA964+1
        defadr DataBrowser_Create,0x1416F270+1
        defadr DataBrowserDesc_Destroy,0x145BAAC8+1
        defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x14735BD4+1

        EXTERN SetFileDelete
        EXTERN SetKey

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
        
        RSEG   CODE
        CODE16
set_key_file_1:
        ldr 	r2, =0x151C58A4+1
        ldr 	r0, [r4,#0x14]
        mov 	r1, r5
        ldr 	r3, =GUIObject_SoftKeys_SetAction
        blx 	r3
        mov 	r1, #0
        ldr 	r0, [r4,#0x14]
        bl	SetKey
	ldr 	r0, [r4,#0x14]
        ldr	r3, =0x15178636+1
        bx	r3

set_key_file_2:
        lsl     R1, R7, #0
        ldr 	r3, =GUIObject_SoftKeys_SetAction
        blx 	r3
        ldr 	r0, [r5,#0x10]
        mov 	r1, #0
        ldr 	r0, [r0,#0x10]
        bl	SetKey
        ldr 	r3, =0x15118FEA+1
        bx	r3
	
set_key_path:
        ldr 	r1, =0xFC5
        ldr 	r0, [r4,#0x14]
        ldr 	r3, =GUIObject_SoftKeys_SetAction
        blx 	r3
        mov 	r1, #1
        ldr 	r0, [r4,#0x14]
        bl	SetKey
        ldr 	r3, =0x15355818+1
        bx	r3

file_delete:
	lsl     R0, R4, #0
	mov	R2, #0
	add	R0, #0xA
        bl	SetFileDelete
        ldr	r3, =0x145AD2CA+1
        bx	r3

        END
        