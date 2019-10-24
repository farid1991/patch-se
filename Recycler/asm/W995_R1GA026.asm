#ifdef W995_R1GA026

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
        
        defadr DataBrowserDesc_Create,0x1426B850+1
        defadr DataBrowserDesc_SetHeaderText,0x1426B9F0+1
        defadr DataBrowserDesc_SetBookID,0x1430687C+1
        defadr DataBrowserDesc_SetFolders,0x1426B7E4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x1426B980+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x14DB4B64+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1426B978+1
        defadr DataBrowser_Create,0x1444B784+1
        defadr DataBrowserDesc_Destroy,0x1426B900+1
        defadr TextID_Create,0x142D8068+1
        defadr BookObj_GetBookID,0x1416EA50+1
        defadr CreatePasswordInputWindow,0x150456DC+1
        defadr BookObj_GotoPage,0x1404570C+1
        defadr get_envp,0x101EB37C+1
        defadr set_envp,0x101EB390+1
        defadr get_bid,0x101E48F8
        defadr current_process,0x101E48C0
        defadr GUIObject_SoftKeys_SetAction,0x1410527C+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x14046748+1
        defadr FileDelete,0x14290664+1
        defadr FileMove,0x141B33A4+1
		defadr FreeBook,0x1413366C+1
        
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
        
        EXTERN SetFile
        EXTERN SetKey
        
        RSEG   CODE
        CODE16
set_key_file_1:
        ldr r2, =0x14E2CD2C+1
        ldr r0, [r4,#0x10]
        mov r1, r5
        ldr r3, =GUIObject_SoftKeys_SetAction
        blx r3
        mov r1, #0
        ldr r0, [r4,#0x10]
        bl SetKey
        ldr r3, =0x14E28D56+1
        bx r3
set_key_file_2:
        ldr r0, [r0,#0x10]
        ldr r3, =GUIObject_SoftKeys_SetAction
        blx r3
        mov r1, #0
        ldr r0, [r5,#0]
        ldr r0, [r0,#0x10]
        bl SetKey
        ldr r3, =0x14DC6C22+1
        bx r3
set_key_path:
        ldr r2, =0x14EF6934+1
        ldr r1, =0xFC5
        ldr r0, [r5,#0x14]
        ldr r3, =GUIObject_SoftKeys_SetAction
        blx r3
        mov r1, #1
        ldr r0, [r5,#0x14]
        bl SetKey
        ldr r3, =0x15040092+1
        bx r3
file_delete:
        ldr r0, =0x208
        add r1, r4, r0
        mov r0, r4
        add r0, #0xA
        bl SetFile
        ldr r3, =0x144D54E2+1
        bx r3 
#endif
        END