//W902_R3EG004

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x118B5EA8+1
        defadr memcpy,0x118B5DA8+1
        defadr sscanf,0x10003C7C+1
        defadr sprintf,0x10700200+1
        defadr snwprintf,0x107006BC+1
        defadr current_process,0x1017CBFC
        defadr get_bid,0x1017CC34
        defadr _fopen,0x10960338+1
        defadr fread,0x10961CCC+1
        defadr fclose,0x11721C80+1
        defadr fwrite,0x10961E98+1
        defadr fstat,0x10960C9C+1
        defadr w_fopen,0x112B57F4+1
        defadr w_lseek,0x11A761B0+1
        defadr w_fread,0x112B5824+1
        defadr w_fclose,0x112B5854+1
        defadr w_fstat,0x112B58AC+1
        defadr w_dirread,0x11A76840+1
        defadr w_diropen,0x4BB00354
        defadr w_chdir,0x4BB003AC
        defadr w_dirclose,0x4BB0038C
        defadr List_DestroyElements,0x11AEA1E8+1
        defadr List_Destroy,0x11AE9EFC+1
        defadr List_Create,0x11AE9ED4+1
        defadr List_InsertLast,0x11AEA050+1
        defadr List_Get,0x11AEA0F4+1
        defadr List_GetCount,0x11AEA0C8+1
        defadr List_InsertFirst,0x11AEA048+1
        defadr getFileExtention,0x109639A8+1
        defadr FSX_MakeFullPath,0x10963ADC+1
        defadr FSX_FreeFullPath,0x10963B48+1
        defadr FSX_IsFileExists,0x1181919C+1
        defadr FILEITEM_GetFname,0x1181E380+1
        defadr FILEITEM_GetPath,0x1181E414+1
        defadr ImageID_Free,0x107AE74C+1
        defadr ImageID_GetIndirect,0x107A85CC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107AA5B4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107AA62C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107AA6B4+1
        defadr strlen,0x107004E4+1
        defadr strcmp,0x10700488+1
        defadr strncmp,0x10700528+1
        defadr strcpy,0x107004B0+1
        defadr strncpy,0x1070055C+1
        defadr strstr,0x107005F8+1
        defadr str2wstr,0x10D6F8B8+1
        defadr wstrcat,0x10700D7C+1
        defadr wstrlen,0x10D6E5F0+1
        defadr wstr2strn,0x10D6E710+1
        defadr wstrnupr,0x10D6E6C0+1
        defadr wstrcpy,0x10D6E634+1
        defadr wstrrchr,0x10D6F974+1
        defadr wstrcmp,0x10D6E604+1
        defadr wstrncmp,0x10700E50+1
        defadr Timer_Kill,0x10DF4D0C+1
        defadr Timer_ReSet,0x10DF4CB4+1
        defadr Timer_Set,0x10DF4C80+1
        defadr TextID_Create,0x10F69BBC+1
        defadr TextID_GetLength,0x10F6A000+1
        defadr TextID_Destroy,0x10F69EF8+1
        defadr TextID_GetString,0x10F6A2C8+1
        defadr TextID_GetWString,0x10F6A150+1
        defadr TextID_CreateIntegerID,0x10F699E8+1
        defadr Disp_GetTextIDWidth,0x109D5A34+1
        defadr FreeBook,0x10DF8D20+1
        defadr FindBook,0x10DF68D8+1
        defadr FindBookEx,0x10DF6938+1
        defadr FreeAllBook,0x10E2F450+1
        defadr CreateBook,0x10DF86A0+1
        defadr UI_Event,0x10DF7440+1
        defadr BookObj_CallPage,0x10DF84E4+1
        defadr BookObj_GotoPage,0x10DF83B0+1
        defadr BookObj_ReturnPage,0x10DF8568+1
        defadr BookObj_AddGUIObject,0x10DF8A30+1
        defadr BookObj_GetBookID,0x10DF8E0C+1
        defadr BookObj_SetFocus,0x10DF8950+1
        defadr BookObj_GetDisplayOrientation,0x10DF8EA8+1
        defadr BookObj_SetDisplayOrientation,0x10DF8E44+1
        defadr IsAudioPlayerBook,0x10C8F7AC+1
        defadr CreateMessageBox,0x11A7B45C+1
        defadr DISP_DESC_SetName,0x109CDA88+1
        defadr DISP_DESC_SetSize,0x109CDA8C+1
        defadr DISP_DESC_SetOnCreate,0x109CDA90+1
        defadr DISP_DESC_SetOnClose,0x109CDA94+1
        defadr DISP_DESC_SetOnRedraw,0x109CDA98+1
        defadr DISP_DESC_SetOnKey,0x109CDAA0+1
        defadr DISP_DESC_SetOnLayout,0x109CDAAC+1
        defadr GUIObject_Create,0x109DA43C+1
        defadr GUIObject_SetStyle,0x109DA84C+1
        defadr GUIObject_GetStyle,0x109DA868+1
        defadr GUIObject_SetTitleType,0x109DA9EC+1
        defadr GUIObject_SetTitleText,0x109DAA08+1
        defadr GUIObject_Destroy,0x109DA600+1
        defadr GUIObject_Show,0x109DA7F4+1
        defadr GUIObject_GetDispObject,0x109DA68C+1
        defadr GUIObject_GetBook,0x109DA6A0+1
        defadr GUIObject_SetSecondRowTitleText,0x109DAA24+1
        defadr DispObject_GetGUI,0x109D08BC+1
        defadr DispObject_SetBacklightMode,0x109D3FB0+1
        defadr DispObject_InvalidateRect,0x109D0FD8+1
        defadr DispObject_SetLayerColor,0x109D31D0+1
        defadr DispObject_SetAnimation,0x109D3288+1
        defadr DispObject_GetStyle,0x109D3904+1
        defadr DispObject_SetStyle,0x109D3664+1
        defadr GetImageWidth,0x109D5980+1
        defadr GetImageHeight,0x109D5994+1
        defadr Display_GetWidth,0x1179F9B8+1
        defadr Display_GetHeight,0x1179F9AC+1
        defadr SetFont,0x109D52A8+1
        defadr DrawString,0x109D46E8+1
        defadr DrawRect,0x109D439C+1
        defadr get_DisplayGC,0x109D8650+1
        defadr GC_SetPenColor,0x109D8E60+1
        defadr GC_SetBrushColor,0x109D8F38+1
        defadr GC_DrawLine,0x109D95E0+1
        defadr GC_GetRect,0x109D8C94+1
        defadr GC_GetXX,0x109D8F90+1
        defadr GC_SetXX,0x109D8F84+1
        defadr GC_DrawFRect,0x109D976C+1
        defadr GC_DrawRoundRect,0x109D97B4+1
        defadr GC_ValidateRect,0x109D8C44+1
        defadr GC_GetPenColor,0x109D8E9C+1
        defadr CreateListMenu,0x11AA36DC+1
        defadr ListMenu_GetSelectedItem,0x11AA38DC+1
        defadr ListMenu_SetItemCount,0x11AA38F0+1
        defadr ListMenu_SetTexts,0x11AA3A08+1
        defadr ListMenu_SetHotkeyMode,0x11AA3A2C+1
        defadr ListMenu_SetOnMessage,0x11AA3A00+1
        defadr ListMenu_SetCursorToItem,0x11AA38C8+1
        defadr ListMenu_SetItemStyle,0x11AA392C+1
        defadr ListMenu_SetNoItemText,0x11AA3A80+1
        defadr ListMenu_DestroyItems,0x11AA3D48+1
        defadr ListMenu_SetItemTextScroll,0x11AA3FD0+1
        defadr ListMenu_SetItemSecondLineText,0x11AA3CA4+1
        defadr GUIonMessage_GetMsg,0x11AA4490+1
        defadr GUIonMessage_GetBook,0x11AA4498+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11AA44B4+1
        defadr GUIonMessage_SetMenuItemText,0x11AA44C0+1
        defadr GUIonMessage_SetMenuItemIcon,0x11AA4500+1
        defadr GUIonMessage_SetItemDisabled,0x11AA4568+1
        defadr GUIonMessage_GetSelectedItem,0x11AA449C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11AA44F0+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11AA44E0+1
        defadr CreateOneOfMany,0x11AA5CB8+1
        defadr OneOfMany_SetItemCount,0x11AA5E44+1
        defadr OneOfMany_SetOnMessage,0x11AA5E8C+1
        defadr OneOfMany_SetChecked,0x11AA5E60+1
        defadr OneOfMany_GetSelected,0x11AA5E70+1
        defadr OneOfMany_SetTexts,0x11AA5E94+1
        defadr CreateTabMenuBar,0x1179D350+1
        defadr TabMenuBar_SetTabGui,0x1179D420+1
        defadr TabMenuBar_SetTabTitle,0x1179D4E8+1
        defadr TabMenuBar_SetTabIcon,0x1179D4A0+1
        defadr TabMenuBar_SetTabCount,0x1179D5A8+1
        defadr TabMenuBar_SetFocusedTab,0x1179D404+1
        defadr TabMenuBar_SetOnTabSwitch,0x1179D4FC+1
        defadr TabMenuBar_GetFocusedTab,0x1179D414+1
        defadr CreateStringInput,0x1089AF5C+1
        defadr StringInput_SetMode,0x1089B814+1
        defadr StringInput_SetFixedText,0x1089B958+1
        defadr StringInput_SetMinLen,0x1089B87C+1
        defadr StringInput_SetMaxLen,0x1089B92C+1
        defadr StringInput_SetEnableEmptyText,0x1089B9A0+1
        defadr StringInput_SetActionOK,0x1089B870+1
        defadr TextFeedbackWindow,0x1179E69C+1
        defadr Feedback_SetTextExtended,0x1179EB0C+1
        defadr Feedback_CloseAction,0x1179EA6C+1
        defadr CreateYesNoQuestion,0x1179F15C+1
        defadr YesNoQuestion_SetDescriptionText,0x1179F4B4+1
        defadr YesNoQuestion_SetQuestionText,0x1179F4C4+1
        defadr YesNoQuestion_SetIcon,0x1179F4E4+1
        defadr DispObject_SoftKeys_GetList,0x10812868+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x1081577C+1
        defadr GUIObject_SoftKeys_SetText,0x1081545C+1
        defadr GUIObject_SoftKeys_SetAction,0x108153E4+1
        defadr GUIObject_SoftKeys_SetVisible,0x108154E0+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x10815700+1
        defadr GUIObject_SoftKeys_Hide,0x1081579C+1
        defadr GUIObject_SoftKeys_Show,0x108157A8+1
        defadr GUIObject_SoftKeys_SetEnable,0x1081554C+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1081564C+1
        defadr GUIObject_SoftKeys_SetInfoText,0x10815448+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x10815580+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x108157B4+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B74394+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AFB9AC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AFB904+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AFB94C+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x10AFB9DC+1
        defadr DispObject_SoftKeys_Show,0x10811944+1
        defadr DispObject_SoftKeys_Hide,0x1081190C+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x11AC04F8+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11AC039C+1
        defadr Sound_SetMessageAlert,0x10C58D54+1
        defadr Sound_SetAlarmsignal,0x1093DE10+1
        defadr Sound_AddToContact,0x10B5C100+1
        defadr OSE_GetShell,0x10E17504+1
        defadr CoCreateInstance,0x10723BF0+1
        defadr DisplayGC_AddRef,0x109D8A88+1
        defadr MetaData_GetTags,0x118197B4+1
        defadr set_envp,0x10005C4C+1
        defadr get_envp,0x10005C38+1
        defadr Volume_Get,0x11A05340+1
        defadr Volume_Set,0x11A05274+1
        defadr onBackPressed,0x10DC83E0+1
        defadr onLongBackPressed,0x10E2F450+1
        defadr onCloseBook,0x11AF0CA8+1
        defadr onStandyEvent,0x10DC99C4+1
        defadr StandartRingMenu,0x10DC8F5C+1
        defadr DynamicMenu_GetElementMsg,0x10DE2620+1
        defadr DynamicMenu_SetElement_FirstLineText,0x10DE252C+1
        defadr DynamicMenu_SetElement_SecondLineText,0x10DE25E0+1
        defadr ConnectionManager_Connection_GetState_int,0x10C2D454+1
        defadr iconidname2id,0x115384AC+1
        defadr BookObj_GetSession,0x10DF8D6C+1
        defadr UI_Event_toBookID,0x10DF7498+1
        defadr UI_Event_toBookIDwData,0x10DF74AC+1
        defadr root_list_get_session_count,0x10DF69D8+1
        defadr root_list_get_session,0x10DF69E8+1
        defadr IsVolumeControllerBook,0x11ADD448+1
        defadr IsRightNowBook,0x10B3AF34+1
        defadr Find_StandbyBook,0x10D95ADC+1
        defadr MessageBox,0x11A7B3B8+1
        defadr GetFreeBytesOnHeap,0x4BB00700
        defadr GUIObject_TabTitleRemove,0x11AA3FE0+1
        defadr DispObject_GetOnKey,0x109CDB7C+1
        defadr DispObject_GetDESC,0x10014E98+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x1151330C+1
        defadr REQUEST_SYSTEM_RESTART,0x1151332C+1
        defadr Shortcut_Run,0x10DE4C10+1
        defadr FlightMode_GetState,0x11A7F508+1
        defadr FlightMode_SetState,0x11A7FD34+1
        defadr Request_ICA_ShutdownAllConnections,0x114B63F8+1
        defadr Display_GetBrightness,0x10DC9530+1
        defadr JavaDialog_Open,0x10B1C0A0+1
        defadr JavaDialog_Close,0x10B1F7F4+1
        defadr JavaApp_LogoImageID_Get,0x10C388BC+1
        defadr JavaAppDesc_GetFirstApp,0x10B11A34+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B11500+1
        defadr JavaAppDesc_GetNextApp,0x10B11A3C+1
        defadr JavaSession_GetName,0x108E7008+1
        defadr manifest_GetParam,0x10B0E110+1
        defadr NewEvents_GetCount,0x10B412B4+1

        EXTERN GetFocusTab
        EXTERN CreateBookAndElfsLists
        EXTERN ActivityBook_onClose
        EXTERN EventsTitleText
        EXTERN CreateBookMenu
        EXTERN CreateElfMenu
        EXTERN CreateShortcutMenu

        RSEG   TAB_ICON_1
        CODE16
        ldr     r7, =_IconInternet
        bx      r7

        RSEG   TAB_ICON_2
        DATA
        DCD 0xF3E1

        RSEG   TAB_FOCUS
        CODE16
        ldr     r3, =_Tabfocus
        bx      r3

        RSEG   GUI_CREATE
        CODE16
        ldr     r3, =_onCreate
        bx      r3

        RSEG   BOOK_CLOSE
        CODE16
        ldr     r3, =_onClose
        bx      r3

        RSEG   EVENTS
        CODE16
        ldr     r3, =EventsTitleText
        bx      r3

        RSEG   INTERNET
        CODE16
        ldr     r3, =_Internet
        bx      r3

        RSEG   SHORTCURTS
        CODE16
        ldr     r3, =_Shortcurts
        bx      r3

        RSEG   ACTIVETASKS
        CODE16
        ldr     r3, =_Activetasks
        bx      r3

        RSEG   CODE
        CODE16
_IconInternet:
        ldr     r1, =0xF3E6
        strh    r1, [r0,#8]
        sub     r1, r1, #1
        strh    r1, [r0,#0xA]
        ldr     r1, =0xDC9
        str     r1, [r0,#0xC]
        pop     {r4,r5,pc}

_Tabfocus:
        ldr     r3, =0x10B3ADB8+1
        blx     r3
        cmp     r0, #0
        beq     get_focus
        ldr     r3, =0x10B3B20C+1
        bx      r3
get_focus:
        bl      GetFocusTab
        mov     r5, r0
        ldr     r3, =0x10B3B22A+1
        bx      r3

_onCreate:
        bl      CreateBookAndElfsLists
        ldr     r1, =0x10B3B434+1
        ldr     r0, [r4,#0x24]
        ldr     r3, =TabMenuBar_SetOnTabSwitch
        blx     r3
        ldr     r3, =0x10B3B474+1
        bx      r3

_onClose:
        add     r0, r4, #0
        ldr     r3, =0x10B3AD94+1
        blx     r3
        cmp     r5, #0
        beq     empty_offset_60
        mov     R0, #2
        ldr     r3, =0x10B3B0E0+1
        blx     r3
empty_offset_60:
        bl      ActivityBook_onClose
        POP     {R4-R7,PC}

_Internet:
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateShortcutMenu
        pop     {r4-r6,pc}

_Shortcurts:
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateElfMenu
        pop     {r4-r6,pc}

_Activetasks:
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateBookMenu
        pop     {r4-r6,pc}

        END
