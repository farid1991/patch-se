//W980_R3EG004

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x118A0324+1
        defadr memcpy,0x118A0224+1
        defadr debug_printf,0x4BB37FED
        defadr set_envp,0x10005AEC+1
        defadr get_envp,0x10005AD8+1
        defadr current_process,0x10173890
        defadr get_bid,0x101738C8
        defadr _fopen,0x10955B80+1
        defadr fwrite,0x1095763C+1
        defadr fclose,0x1170F520+1
        defadr fread,0x10957474+1
        defadr fstat,0x109564E4+1
        defadr lseek,0x109577A0+1
        defadr w_fstat,0x112A40E4+1
        defadr w_fopen,0x112A402C+1
        defadr w_lseek,0x11A5F694+1
        defadr w_fread,0x112A405C+1
        defadr w_fclose,0x112A408C+1
        defadr CoCreateInstance,0x1071C028+1
        defadr get_DisplayGC,0x109CE290+1
        defadr DisplayGC_AddRef,0x109CE6C8+1
        defadr DrawRect,0x109C9FB4+1
        defadr SetFont,0x109CAEC0+1
        defadr DrawString,0x109CA300+1
        defadr GC_PutChar,0x109CECCC+1
        defadr GetImageHeight,0x109CB5D4+1
        defadr GetImageWidth,0x109CB5C0+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr ListMenu_DestroyItems,0x11A8D4C0+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr ListMenu_SetItemSecondLineText,0x11A8D41C+1
        defadr OneOfMany_GetSelected,0x11A8F5E4+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr TextID_Create,0x10F685C0+1
        defadr CreateOneOfMany,0x11A8F42C+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr OneOfMany_SetTexts,0x11A8F608+1
        defadr OneOfMany_SetChecked,0x11A8F5D4+1
        defadr GUIObject_Show,0x109D0434+1
        defadr TextID_Destroy,0x10F688FC+1
        defadr GC_GetRect,0x109CE8D4+1
        defadr GC_GetXX,0x109CEBD0+1
        defadr GC_SetXX,0x109CEBC4+1
        defadr snwprintf,0x106F71E4+1
        defadr GC_GetPenColor,0x109CEADC+1
        defadr GC_SetPenColor,0x109CEAA0+1
        defadr GC_DrawLine,0x109CF220+1
        defadr DispObject_InvalidateRect,0x109C6B64+1
        defadr DISP_DESC_SetName,0x109C35EC+1
        defadr DISP_DESC_SetSize,0x109C35F0+1
        defadr DISP_DESC_SetOnCreate,0x109C35F4+1
        defadr DISP_DESC_SetOnClose,0x109C35F8+1
        defadr DISP_DESC_SetOnRedraw,0x109C35FC+1
        defadr DISP_DESC_SetOnKey,0x109C3604+1
        defadr DISP_DESC_SetOnLayout,0x109C3610+1
        defadr DISP_DESC_SetOnRefresh,0x109C3600+1
        defadr DispObject_SetRefreshTimer,0x109C65CC+1
        defadr DispObject_KillRefreshTimer,0x109C6648+1
        defadr DispObject_SetThemeImage,0x109C8980+1
        defadr DispObject_SetLayerColor,0x109C8E24+1
        defadr DispObject_SetAnimation,0x109C8EDC+1
        defadr DispObject_SetBacklightMode,0x109C9C04+1
        defadr GUIObject_SetBacklightOn,0x109D0580+1
        defadr GUIObject_SetBacklightOff,0x109D05AC+1
        defadr GUIObject_GetDispObject,0x109D02CC+1
        defadr GUIObject_Create,0x109D007C+1
        defadr BookObj_AddGUIObject,0x10DEFD64+1
        defadr GUIObject_SetTitleType,0x109D0640+1
        defadr FreeBook,0x10DF0054+1
        defadr TextID_CreateIntegerID,0x10F683EC+1
        defadr TextID_GetLength,0x10F68A04+1
        defadr Disp_GetTextIDWidth,0x109CB674+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107A25F0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107A2668+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107A26F0+1
        defadr FSX_IsFileExists,0x11804158+1
        defadr DispObject_GetGUI,0x109C6448+1
        defadr GUIObject_GetBook,0x109D02E0+1
        defadr Display_GetWidth,0x1178CFD4+1
        defadr Display_GetHeight,0x1178CFC8+1
        defadr CreateMessageBox,0x11A64938+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetItemDisabled,0x11A8DCC8+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr CreateYesNoQuestion,0x1178C788+1
        defadr YesNoQuestion_SetDescriptionText,0x1178CAF0+1
        defadr YesNoQuestion_SetQuestionText,0x1178CAE0+1
        defadr YesNoQuestion_SetIcon,0x1178CB10+1
        defadr BookObj_ReturnPage,0x10DEF89C+1
        defadr CreateBook,0x10DEF9D4+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr BookObj_Hide,0x10DEFCAC+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6A088+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D510+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x1080D730+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1080D7E4+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1080D7F0+1
        defadr GUIObject_SoftKeys_Show,0x1080D7D8+1
        defadr GUIObject_SoftKeys_Hide,0x1080D7CC+1
        defadr FILEITEM_GetPath,0x11808D90+1
        defadr FILEITEM_GetFname,0x11808CFC+1
        defadr FILEITEM_GetFextension,0x11808D00+1
        defadr FSX_MakeFullPath,0x109590A4+1
        defadr FSX_FreeFullPath,0x10959110+1
        defadr ImageID_GetIndirect,0x107A0608+1
        defadr ImageID_Free,0x107A6788+1
        defadr MetaData_GetTags,0x11804760+1
        defadr strcpy,0x106F6FE0+1
        defadr strlen,0x106F7014+1
        defadr strncpy,0x106F7084+1
        defadr strstr,0x106F7120+1
        defadr str2wstr,0x10D662F8+1
        defadr wstrlen,0x106F7938+1
        defadr wstrcpy,0x106F7900+1
        defadr wstrncmp,0x106F7978+1
        defadr wstrrchr,0x10D663B4+1
        defadr wstrcat,0x106F78A4+1
        defadr wstr2strn,0x10D65150+1
        defadr Timer_Set,0x10DEBF78+1
        defadr Timer_ReSet,0x10DEBFAC+1
        defadr Timer_Kill,0x10DEC004+1
        defadr Volume_Set,0x119EEA3C+1
        defadr Volume_Get,0x119EEB0C+1
        defadr KeygrabberWindow,0x109D0A1C+1

        EXTERN CreateInfo

        RSEG   CODE
        CODE16
create_gui:
        ldr     r0, [r6,#4]
        ldr     r3, =FILEITEM_GetFextension
        blx     r3
        ldr     r1, =0x11EEC5C0
        mov     r2, #3
        ldr     r3, =wstrncmp
        blx     r3
        cmp     r0, #0
        beq     isMID
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateInfo
        b       empty_gui
isMID:
        add     r0, r5, #0
        ldr     r3, =KeygrabberWindow
        blx     r3
        str     r0, [r6,#0x14]
        cmp     r0, #0
        beq     empty_gui
        ldr     r3, =0x117F5DFC+1
        bx      r3

empty_gui:
        mov     r0, #1
        pop     {r4-r7,pc}

        RSEG   CREATE_GUI
        CODE16
        ldr     r3, =create_gui
        bx      r3

        END
