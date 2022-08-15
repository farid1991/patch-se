//F100_R1HA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA31A94
        defadr memfree,0x4BA31ABC
        defadr memset,0x10781038
        defadr set_envp,0x101F12F4+1
        defadr get_envp,0x101F12E0+1
        defadr w_fstat,0x10175F54+1
        defadr w_diropen,0x4BA31864
        defadr w_dirread,0x143B06D0+1
        defadr w_dirclose,0x4BA80C10
        defadr w_chdir,0x4BA80C30
        defadr snwprintf,0x142C9AE4+1
        defadr strcmp,0x14CF2500+1
        defadr wstrlen,0x143134B0+1
        defadr wstrcpy,0x14312C58+1
        defadr wstrcmp,0x1431351C+1
        defadr wstrrchr,0x143134C4+1
        defadr wstrcmpi,0x143144EC+1
        defadr FileDelete,0x1435EBE0+1
        defadr FileCopy,0x1421C480+1
        defadr FSX_IsFileExists,0x144C2764+1
        defadr ThemeImage_Apply,0x140B6D94+1
        defadr MainMenu_SetFromUserTheme,0x14E0AA2C+1
        defadr TextID_Create,0x14228F28+1
        defadr MessageBox,0x1582ECE8+1
        defadr GetURIScheme,0x145B9008+1
        defadr CreateURI,0x145B8A80+1
        defadr FreeURI,0x14382340+1
        defadr Browser_OpenURI,0x1424639+1
        defadr GUIObject_Destroy,0x14223460+1
        defadr CreateListMenu,0x142234B0+1
        defadr ListMenu_SetItemCount,0x14213648+1
        defadr ListMenu_SetCursorToItem,0x14368A8C+1
        defadr ListMenu_SetOnMessage,0x143EC1C8+1
        defadr ListMenu_SetHotkeyMode,0x14368AA0+1
        defadr GUIonMessage_GetMsg,0x1412E49C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412E594+1
        defadr GUIonMessage_SetMenuItemText,0x14542BEC+1
        defadr GUIonMessage_SetMenuItemIcon,0x1415B684+1
        defadr ListMenu_GetSelectedItem,0x14545020+1
        defadr GUIObject_SetTitleText,0x142E8CF4+1
        defadr GUIObject_Show,0x1446C474+1
        defadr CreateBook,0x1446CC64+1
        defadr FindBook,0x14313900+1
        defadr FreeBook,0x14368F58+1
        defadr BookObj_SetFocus,0x14223970+1
        defadr BookObj_CallPage,0x142498B4+1
        defadr BookObj_GotoPage,0x1402741C+1
        defadr BookObj_ReturnPage,0x142499AC+1
        defadr GUIObject_SoftKeys_SetText,0x1412C884+1
        defadr GUIObject_SoftKeys_SetAction,0x141A02B0+1
        
        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x153EDC84+1
        ldr	r1, =0xFC0
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x1862
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x153EDD4C+1
        bx	r3

        END
