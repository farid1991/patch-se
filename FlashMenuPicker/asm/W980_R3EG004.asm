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
        defadr FileCopy,0x10956A78+1
        defadr FileDelete,0x10956774+1
        defadr w_fstat,0x112A40E4+1
        defadr w_fopen,0x112A402C+1
        defadr w_lseek,0x11A5F694+1
        defadr w_fread,0x112A405C+1
        defadr w_fclose,0x112A408C+1
        defadr w_diropen,0x4BB00354
        defadr w_chdir,0x4BB003AC
        defadr w_dirread,0x11A5FD24+1
        defadr w_dirclose,0x4BB0038C
        defadr getFileExtention,0x10958F70+1
        defadr List_DestroyElements,0x11AD3A1C+1
        defadr List_Destroy,0x11AD3730+1
        defadr List_Create,0x11AD3708+1
        defadr List_Get,0x11AD3928+1
        defadr List_InsertLast,0x11AD3884+1
        defadr List_GetCount,0x11AD38FC+1
        defadr OSE_GetShell,0x10E117D8+1
        defadr CoCreateInstance,0x1071C028+1
        defadr get_DisplayGC,0x109CE290+1
        defadr DisplayGC_AddRef,0x109CE6C8+1
        defadr DrawRect,0x109C9FB4+1
        defadr SetFont,0x109CAEC0+1
        defadr DrawString,0x109CA300+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr ListMenu_DestroyItems,0x11A8D4C0+1
        defadr ListMenu_SetHotkeyMode,0x11A8D1A4+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr ListMenu_SetTexts,0x11A8D180+1
        defadr ListMenu_SetNoItemText,0x11A8D1F8+1
        defadr ListMenu_SetItemTextScroll,0x11A8D748+1
        defadr ListMenu_SetItemSecondLineText,0x11A8D41C+1
        defadr DispObject_SetStyle,0x109C92B8+1
        defadr DispObject_GetStyle,0x109C9558+1
        defadr OneOfMany_GetSelected,0x11A8F5E4+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr TextID_Create,0x10F685C0+1
        defadr CreateOneOfMany,0x11A8F42C+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_SetSecondRowTitleText,0x109D0678+1
        defadr OneOfMany_SetTexts,0x11A8F608+1
        defadr OneOfMany_SetChecked,0x11A8F5D4+1
        defadr OneOfMany_SetItemCount,0x11A8F5B8+1
        defadr OneOfMany_SetOnMessage,0x11A8F600+1
        defadr GUIObject_Show,0x109D0434+1
        defadr TextID_Destroy,0x10F688FC+1
        defadr GC_GetRect,0x109CE8D4+1
        defadr GC_GetXX,0x109CEBD0+1
        defadr GC_SetXX,0x109CEBC4+1
        defadr snwprintf,0x106F71E4+1
        defadr GC_GetPenColor,0x109CEADC+1
        defadr GC_SetPenColor,0x109CEAA0+1
        defadr GC_DrawLine,0x109CF220+1
        defadr GC_SetBrushColor,0x109CEB78+1
        defadr GC_ValidateRect,0x109CE884+1
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
        defadr DispObject_SetBacklightTimeout,0x109C9C3C+1
        defadr GUIObject_SetBacklightOn,0x109D0580+1
        defadr GUIObject_SetBacklightOff,0x109D05AC+1
        defadr GUIObject_GetDispObject,0x109D02CC+1
        defadr GUIObject_Create,0x109D007C+1
        defadr BookObj_AddGUIObject,0x10DEFD64+1
        defadr GUIObject_SetTitleType,0x109D0640+1
        defadr FindBook,0x10DEDC1C+1
        defadr FreeBook,0x10DF0054+1
        defadr FreeAllBook,0x10E296E4+1
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
        defadr GetImageWidth,0x109CB5C0+1
        defadr GetImageHeight,0x109CB5D4+1
        defadr CreateMessageBox,0x11A64938+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetItemDisabled,0x11A8DCC8+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A8DC60+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A8DC40+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr CreateYesNoQuestion,0x1178C788+1
        defadr YesNoQuestion_SetDescriptionText,0x1178CAF0+1
        defadr YesNoQuestion_SetQuestionText,0x1178CAE0+1
        defadr YesNoQuestion_SetIcon,0x1178CB10+1
        defadr BookObj_CallPage,0x10DEF818+1
        defadr BookObj_ReturnPage,0x10DEF89C+1
        defadr BookObj_GetBookID,0x10DF0140+1
        defadr BookObj_SetFocus,0x10DEFC84+1
        defadr UI_Event,0x10DEE77C+1
        defadr CreateBook,0x10DEF9D4+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr BookObj_Hide,0x10DEFCAC+1
        defadr BookObj_SetDisplayOrientation,0x10DF0178+1
        defadr BookObj_GetDisplayOrientation,0x10DF01DC+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr GUIObject_GetStyle,0x109D04A8+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6A088+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D510+1
        defadr GUIObject_SoftKeys_SetInfoText,0x1080D478+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1080D650+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x1080D730+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1080D7E4+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1080D7F0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1080D5B0+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x1080D7AC+1
        defadr GUIObject_SoftKeys_Show,0x1080D7D8+1
        defadr GUIObject_SoftKeys_Hide,0x1080D7CC+1
        defadr DispObject_SoftKeys_Show,0x10809968+1
        defadr DispObject_SoftKeys_Hide,0x10809930+1
        defadr DispObject_SoftKeys_GetList,0x1080A888+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AF23CC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AF2324+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AF236C+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x10AF23FC+1
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
        defadr strcmp,0x106F6FB8+1
        defadr strncpy,0x106F7084+1
        defadr strstr,0x106F7120+1
        defadr str2wstr,0x10D662F8+1
        defadr wstrcmpi,0x10D66494+1
        defadr wstrlen,0x106F7938+1
        defadr wstrcpy,0x106F7900+1
        defadr wstrcmp,0x10D65044+1
        defadr wstrncmp,0x106F7978+1
        defadr wstrrchr,0x10D663B4+1
        defadr wstrcat,0x106F78A4+1
        defadr wstr2strn,0x10D65150+1
        defadr wstrnupr,0x10D65100+1
        defadr Timer_Set,0x10DEBF78+1
        defadr Timer_ReSet,0x10DEBFAC+1
        defadr Timer_Kill,0x10DEC004+1
        defadr Volume_Set,0x119EEA3C+1
        defadr Volume_Get,0x119EEB0C+1
        defadr IsAudioPlayerBook,0x10C85608+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x11AA9C9C+1
        defadr Sound_SetMessageAlert,0x10C4E930+1
        defadr Sound_SetAlarmsignal,0x1093366C+1
        defadr Sound_AddToContact,0x10B51EAC+1
        defadr CreateTabMenuBar,0x1178A97C+1
        defadr TabMenuBar_SetTabGui,0x1178AA4C+1
        defadr TabMenuBar_SetTabTitle,0x1178AB14+1
        defadr TabMenuBar_SetTabIcon,0x1178AACC+1
        defadr TabMenuBar_SetTabCount,0x1178ABD4+1
        defadr TabMenuBar_SetFocusedTab,0x1178AA30+1
        defadr CreateStringInput,0x10894AB0+1
        defadr StringInput_SetMode,0x10895368+1
        defadr StringInput_SetFixedText,0x108954AC+1
        defadr StringInput_SetMinLen,0x108953D0+1
        defadr StringInput_SetMaxLen,0x10895480+1
        defadr StringInput_SetEnableEmptyText,0x108954F4+1
        defadr StringInput_SetActionOK,0x108953C4+1
        defadr TextFeedbackWindow,0x1178BCC8+1
        defadr Feedback_SetTextExtended,0x1178C138+1
        defadr Feedback_CloseAction,0x1178C098+1
        defadr MainMenu_SetFromUserTheme,0x10DDC7B0+1
        defadr Set_SWF_AsFlashMenu,0x10D2DDE4+1
        defadr MessageBox,0x11A64894+1
        defadr GetURIScheme,0x10E13024+1
        defadr CreateURI,0x10E134C0+1
        defadr FreeURI,0x10E13614+1
        defadr Browser_OpenURI,0x1077CCD4+1

        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x10DDC414+1
        ldr	r1, =0xFC2
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x1B0F
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x10DDC336+1
        bx	r3

        END
