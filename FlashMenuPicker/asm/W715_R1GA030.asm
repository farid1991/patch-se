//W715_R1GA030

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x4BA32A7C
        defadr memfree,0x4BA32AA4
        defadr memset,0x10839C30
        defadr memcpy,0x1428EA8C
        defadr snwprintf,0x143F5418+1
        defadr set_envp,0x101EB10C+1
        defadr get_envp,0x101EB0F8+1
        defadr ThemeImage_Apply,0x14075628+1
        defadr MainMenu_SetFromUserTheme,0x142AD878+1
        defadr w_fstat,0x100B2D70+1   
        defadr w_diropen,0x4BA3284C
        defadr w_chdir,0x4BA80C30
        defadr w_dirread,0x142ECFDC+1
        defadr w_dirclose,0x4BA80C10
        defadr wstrcmp,0x1417C45C+1
        defadr wstrlen,0x1417C3F0+1
        defadr wstrcpy,0x1417BBA8+1
        defadr wstrcmpi,0x1417D03C+1
        defadr wstrrchr,0x1417C404+1
        defadr TextID_Create,0x14184D2C+1
        defadr FSX_IsFileExists,0x144180A0+1
        defadr FileCopy,0x141FDFD0+1
        defadr FileDelete,0x1417A13C+1
        defadr MessageBox,0x1596AC60+1
        defadr GetURIScheme,0x143C9788+1
        defadr CreateURI,0x143C9130+1
        defadr FreeURI,0x140D6DF0+1
        defadr Browser_OpenURI,0x1405CC1C+1
        defadr GUIObject_Destroy,0x144D3EFC+1
        defadr CreateListMenu,0x14289814+1
        defadr ListMenu_SetItemCount,0x14284158+1
        defadr ListMenu_SetCursorToItem,0x1441E788+1
        defadr ListMenu_SetOnMessage,0x143073E8+1
        defadr ListMenu_SetHotkeyMode,0x1441E820+1
        defadr ListMenu_GetSelectedItem,0x14283C40+1
        defadr GUIonMessage_GetMsg,0x142CA26C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142CA17C+1
        defadr GUIonMessage_SetMenuItemText,0x14390474+1
        defadr GUIonMessage_SetMenuItemIcon,0x144D49F8+1
        defadr GUIObject_SetTitleText,0x14446B3C+1
        defadr GUIObject_Show,0x144D3B34+1
        defadr strcmp,0x14CC8BA0+1
        defadr CreateBook,0x1428A418+1
        defadr FreeBook,0x1412AA0C+1
        defadr FindBook,0x140CD27C+1
        defadr BookObj_SetFocus,0x144D3314+1
        defadr BookObj_CallPage,0x140209A0+1
        defadr BookObj_GotoPage,0x144897F0+1
        defadr BookObj_ReturnPage,0x14216508+1
        defadr GUIObject_SoftKeys_SetText,0x141C8864+1
        defadr GUIObject_SoftKeys_SetAction,0x1417EFA0+1

        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x1552C44C+1
        ldr	r1, =0xFC0
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x1861
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x14DA1ECC+1
        bx	r3

        END
