//W810_R4EA031

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x45453AA8+1
        defadr memfree,0x454547E0+1
        defadr memset,0x44E24360+1
        defadr debug_printf,0x44C9E13C+1
        defadr set_envp,0x44149D0A+1
        defadr get_envp,0x44149CF6+1
        defadr current_process,0x4418D8F0
        defadr get_bid,0x4418D928
        defadr snwprintf,0x44E25568+1
        defadr sscanf,0x44147BAC+1
        defadr _fopen,0x455B4268+1
        defadr fread,0x455B5700+1
        defadr fclose,0x455B54A0+1
        defadr fwrite,0x455B58E4+1
        defadr fstat,0x455B4ADC+1
        defadr lseek,0x455B5AA8+1
        defadr FileCopy,0x455B4EC4+1
        defadr FileDelete,0x455B4BF4+1
        defadr w_diropen,0x455E5DC0+1
        defadr w_chdir,0x455E40A4+1
        defadr w_dirread,0x4510AA68+1
        defadr w_fstat,0x44B24B64+1
        defadr w_dirclose,0x455E603C+1
        defadr wstrlen,0x44FE9B2C+1
        defadr wstrcmp,0x44E25C04+1
        defadr wstrcmpi,0x44FEAFB4+1
        defadr wstrrchr,0x44E25D38+1
        defadr strncmp,0x44E2538C+1
        defadr strcmp,0x44E252EC+1
        defadr wstrcpy,0x44E25C34+1
        defadr wstrcat,0x44E25BD4+1
        defadr Format_Time,0x454396B0+1
        defadr TextIteratorSetTextId,0x452FE434+1
        defadr TextID_Create,0x452FE69C+1
        defadr TextID_CreateIntegerID,0x452FE300+1
        defadr TextID_CreateFromChar,0x452FE2F8+1
        defadr TextID_GetLength,0x452FE8FC+1
        defadr TextID_Destroy,0x452FE86C+1
        defadr TextID_GetString,0x452FF248+1
        defadr Disp_GetTextIDWidth,0x45308098+1
        defadr CreateMessageBox,0x45533CE0+1
        defadr FSX_IsFileExists,0x452510D8+1
        defadr Display_GetTopBook,0x4529F01C+1
        defadr GUIObject_GetDispObject,0x45193C40+1
        defadr DispObject_GetGUI,0x453024AC+1
        defadr GUIObject_GetBook,0x45193C54+1
        defadr DispObject_SoftKeys_GetList,0x45199EB4+1
        defadr GUIObject_SetAnimation,0x451533E0+1
        defadr BookObj_GotoPage,0x4529F4CC+1
        defadr BookObj_CallPage,0x4529F5DC+1
        defadr BookObj_GetBookID,0x4529FD0C+1
        defadr Display_GetHeight,0x45547974+1
        defadr Display_GetWidth,0x45547984+1
        defadr GetImageHeight,0x45307FC0+1
        defadr GetImageWidth,0x45307FD8+1
        defadr get_DisplayGC,0x45191A98+1
        defadr GC_PutChar,0x451925BC+1
        defadr SetFont,0x45307888+1
        defadr DrawString,0x45306D48+1
        defadr DrawRect,0x45306940+1
        defadr DrawObject,0x45306B64+1
        defadr DispObject_InvalidateRect,0x45302A70+1
        defadr DispObject_SetStyle,0x45306190+1
        defadr DispObject_GetStyle,0x453062BC+1
        defadr DispObject_SetLayerColor,0x453060C4+1
        defadr DispObject_WindowSetSize,0x4530476C+1
        defadr DispObject_SetBackgroundColor,0x4530EFFC+1
        defadr DispObject_SetListTextColor,0x452E66F4+1
        defadr DispObject_SetTitleText,0x45304A34+1
        defadr DispObject_SetTitleType,0x45304B98+1
        defadr DispObject_SetSecondRowTitleText,0x45304A8C+1
        defadr DispObject_ListMenu_GetItemCount,0x452DC0FC+1
        defadr DispObject_SetThemeImage,0x45305BE4+1
        defadr DispObject_SetBackgroundImage,0x452E669C+1
        defadr List_GetCount,0x4527F228+1
        defadr List_Get,0x4527F250+1
        defadr ImageID_Get,0x45426B54+1
        defadr ImageID_Free,0x45426B44+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x455ADDD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x455ADE50+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x455ADEE4+1
        defadr GUIObject_SetStyle,0x45193EC4+1
        defadr ListMenu_SetHotkeyMode,0x45170A04+1
        defadr ListMenu_SetItemSecondLineText,0x45170C98+1
        defadr GUIObject_SetListTextColor,0x45171F28+1
        defadr GUIObject_SetCursorImage,0x45171EF8+1
        defadr GUIObject_SetBackgroundImage,0x45171F08+1
        defadr GUIObject_SetTitleBackgroundImage,0x45171F18+1
        defadr GUIObject_SetTitleType,0x45193F58+1
        defadr GUIObject_SetTitleText,0x45193F7C+1
        defadr GUIObject_SetTitleTextAlign,0x45193FC8+1
        defadr GUIObject_SetSecondRowTitleText,0x45193F98+1
        defadr GUIObject_Show,0x45193E64+1
        defadr GUIObject_Destroy,0x45193BE4+1
        defadr GUIonMessage_GetMsg,0x45171378+1
        defadr GUIonMessage_GetCreatedItemIndex,0x451713A4+1
        defadr GUIonMessage_SetMenuItemText,0x451713B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x451713F4+1
        defadr ListMenu_GetSelectedItem,0x45170884+1
        defadr CreateListMenu,0x45170674+1
        defadr ListMenu_SetItemCount,0x4517089C+1
        defadr ListMenu_SetCursorToItem,0x45170870+1
        defadr ListMenu_SetOnMessage,0x451709D8+1
        defadr ListMenu_SetItemTextScroll,0x45171004+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x45219CDC+1
        defadr GUIObject_SoftKeys_SetAction,0x4519B824+1
        defadr GUIObject_SoftKeys_SetText,0x4519B90C+1
        defadr MediaPlayer_SoftKeys_Validate,0x45074F90+1
        defadr CreateOneOfMany,0x4517250C+1
        defadr OneOfMany_SetItemCount,0x451726A0+1
        defadr OneOfMany_SetChecked,0x451726C4+1
        defadr OneOfMany_SetTexts,0x451726F8+1
        defadr OneOfMany_GetSelected,0x451726D4+1
        defadr Set_SWF_AsFlashMenu,0x4526F9F8+1
        defadr MessageBox,0x45533C94+1
        defadr GetURIScheme,0x455292F8+1
        defadr CreateURI,0x45529740+1
        defadr FreeURI,0x4552986C+1
        defadr Browser_OpenURI,0x45420918+1
        defadr CreateBook,0x4529F750+1
        defadr FreeBook,0x4529FC78+1
        defadr FindBook,0x45531160+1
        defadr BookObj_ReturnPage,0x4529F648+1
        defadr BookObj_SetFocus,0x4529F994+1
        defadr GetThemeColor,0x45532A30+1

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
        mov     r1, #0xE
        ldr     r0, [r4,#0x18]
        ldr	r3, =0x45199228+1
        blx	r3
        ldr     r0, [r4,#0x18]
        ldr	r3, =0x4519BEBC+1
        blx	r3
        ldr     r2, =0x12DE
        mov     r1, #1
        ldr     r0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        ldr     r0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x4526F874+1
        bx	r3

mm_softkeys:
        ldr     r2, =0x4553A5A0+1
        ldr	r1, =0xFAF
        add     r0, r5, #0
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x12DE
        mov     r1, #6
        add     r0, r5, #0
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #6
        add     r0, r5, #0
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x4553AAA6+1
        bx	r3

        END
