//W550_R4CB020

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x45379618+1
        defadr memfree,0x4537A34C+1
        defadr memset,0x44D58238+1
        defadr memcpy,0x440E93B4
        defadr sprintf,0x44D58D60+1
        defadr snwprintf,0x44D59438+1
        defadr _fopen,0x454E2F70+1
        defadr fclose,0x454E4168+1
        defadr fread,0x454E43C8+1
        defadr fwrite,0x454E45AC+1
        defadr fstat,0x454E37E4+1
        defadr w_fstat,0x44A24F74+1
        defadr w_diropen,0x4550E3CC+1
        defadr w_chdir,0x4550CA9C+1
        defadr w_dirread,0x45038608+1
        defadr w_dirclose,0x4550E618+1
        defadr set_envp,0x440AD19A+1
        defadr get_envp,0x440AD186+1
        defadr wstrlen,0x44D59B40+1
        defadr wstrcpy,0x44D59B04+1
        defadr wstrcmpi,0x44F1D89C+1
        defadr wstrcmp,0x44D59AD4+1
        defadr wstrrchr,0x44D59C08+1
        defadr GUIonMessage_GetMsg,0x4509DA64+1
        defadr GUIonMessage_GetCreatedItemIndex,0x4509DA90+1
        defadr TextID_Create,0x45225F58+1
        defadr GUIonMessage_SetMenuItemText,0x4509DAA0+1
        defadr GUIonMessage_SetMenuItemIcon,0x4509DAE0+1
        defadr ListMenu_GetSelectedItem,0x4509D01C+1
        defadr FileDelete,0x454E38FC+1
        defadr FileCopy,0x454E3BCC+1
        defadr Set_SWF_AsFlashMenu,0x4519704C+1
        defadr MessageBox,0x45456BE4+1
        defadr FreeBook,0x451C7C7C+1
        defadr GetURIScheme,0x4544C3DC+1
        defadr CreateURI,0x4544C824+1
        defadr Browser_OpenURI,0x45345870+1
        defadr BookObj_ReturnPage,0x451C765C+1
        defadr GUIObject_Destroy,0x450C022C+1
        defadr CreateListMenu,0x4509CE0C+1
        defadr ListMenu_SetItemCount,0x4509D034+1
        defadr ListMenu_SetCursorToItem,0x4509D008+1
        defadr ListMenu_SetOnMessage,0x4509D170+1
        defadr ListMenu_SetHotkeyMode,0x4509D19C+1
        defadr GUIObject_SetTitleText,0x450C05BC+1
        defadr BookObj_CallPage,0x451C75F0+1
        defadr strcmp,0x44D591C4+1
        defadr CreateBook,0x451C7764+1
        defadr FindBook,0x4545414C+1
        defadr BookObj_SetFocus,0x451C79A8+1
        defadr BookObj_GotoPage,0x451C74E0+1
        defadr GUIObject_Show,0x450C04AC+1
        defadr GUIObject_SoftKeys_SetAction,0x450C7B44+1
        defadr GUIObject_SoftKeys_SetText,0x450C7C2C+1

        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   PATCH_MM_SOFTKEYS
        CODE16
        ldr	r3, =mm_softkeys
        bx	r3
        
        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x12D3
        mov     r1, #1
        ldr     r0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        ldr     r0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r0, [r4,#0x18]
        ldr	r3, =0x450C81DC+1
        blx	r3
        ldr     r0, [r4,#0x18]
        ldr	r3, =GUIObject_Show
        blx	r3
        ldr	r3, =0x45196EC8+1
        bx	r3

mm_softkeys:
        ldr     r2, =0x4545D4EC+1
        ldr	r1, =0xFAF
        add     r0, r5, #0
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x12D3
        mov     r1, #6
        add     r0, r5, #0
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #6
        add     r0, r5, #0
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x4545D9F2+1
        bx	r3

        END
