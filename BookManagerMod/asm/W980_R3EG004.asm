//W980_R3EG004

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr debug_printf,0x4BB37FED
        defadr set_envp,0x10005AEC+1
        defadr get_envp,0x10005AD8+1
        defadr current_process,0x10173890
        defadr get_bid,0x101738C8
        defadr _fopen,0x10955B80+1
        defadr fwrite,0x1095763C+1
        defadr fclose,0x1170F520+1
        defadr FSX_Close,0x109571E4+1
        defadr fread,0x10957474+1
        defadr fstat,0x109564E4+1
        defadr Battery_GetChargingState,0x10BF2ADC+1
        defadr Illumination_LedID_SetLevel,0x10BCAD58+1
        defadr Illumination_LedID_Off,0x10BCAF58+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr wtoi,0x10DEB9D8+1
        defadr TextID_CreateIntegerID,0x10F683EC+1
        defadr ListMenu_SetItemSecondLineText,0x11A8D41C+1
        defadr TextID_Create,0x10F685C0+1
        defadr TextID_GetString,0x10F68CCC+1
        defadr CreateStringInputVA,0x10894B50+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr MessageBox,0x11A64894+1
        defadr CreateMessageBox,0x11A64938+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A8DC60+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr GUIonMessage_SetItemDisabled,0x11A8DCC8+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A8DC40+1
        defadr GUIonMessage_GetSelectedItem,0x11A8DBFC+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr GUIObject_SetTitleIcon,0x109D0694+1
        defadr GUIObject_SetTitleType,0x109D0640+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr ListMenu_SetNoItemText,0x11A8D1F8+1
        defadr CreateStringInput,0x10894AB0+1
        defadr StringInput_SetMode,0x10895368+1
        defadr StringInput_SetEnableEmptyText,0x108954F4+1
        defadr StringInput_SetMinLen,0x108953D0+1
        defadr StringInput_SetMaxLen,0x10895480+1
        defadr StringInput_SetText,0x10895584+1
        defadr StringInput_SetFixedText,0x108954AC+1
        defadr StringInput_SetActionOK,0x108953C4+1
        defadr StringInput_SetActionBack,0x108953C8+1
        defadr StringInput_GetStringAndLen,0x10895400+1
        defadr GUIObject_TabTitleRemove,0x11A8D758+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D510+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1080D650+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_Show,0x109D0434+1

        defadr CreateBook,0x10DEF9D4+1
        defadr FreeBook,0x10DF0054+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr BookObj_GetSession,0x10DF00A0+1
        defadr BookObj_GetBookID,0x10DF0140+1
        defadr BookObj_SetFocus,0x10DEFC84+1
        defadr Find_StandbyBook,0x10D8C5D0+1
        defadr IsVolumeControllerBook,0x11AC6BFC+1
        defadr IsRightNowBook,0x10B309FC+1
        defadr UI_Event_toBookID,0x10DEE7D4+1
        defadr UI_Event,0x10DEE77C+1
        defadr UI_Event_toBookIDwData,0x10DEE7E8+1
        defadr root_list_get_session_count,0x10DEDD1C+1
        defadr root_list_get_session,0x10DEDD2C+1

        defadr DynamicMenu_GetElementMsg,0x10DD9918+1
        defadr DynamicMenu_SetElement_SecondLineText,0x10DD98D8+1
        defadr Timer_Kill,0x10DEC004+1
        defadr Timer_ReSet,0x10DEBFAC+1
        defadr TurnOff_Sleepmode,0x108E6410+1

        defadr TabMenuBar_SetTabGui,0x1178AA4C+1
        defadr TabMenuBar_SetTabTitle,0x1178AB14+1
        defadr TabMenuBar_SetOnTabSwitch,0x1178AB28+1
        defadr TabMenuBar_GetFocusedTab,0x1178AA40+1

        defadr iconidname2id,0x11524088+1
        defadr GetFreeBytesOnHeap,0x4BB00700
        defadr snwprintf,0x106F71E4+1
        defadr str2wstr,0x10D662F8+1
        defadr wstrncmp,0x106F7978+1
        defadr strcpy,0x106F6FE0+1
        defadr strncmp,0x106F7050+1
        defadr strcmp,0x106F6FB8+1
        defadr wstrlen,0x10D65030+1
        defadr strlen,0x106F7014+1
        defadr strstr,0x106F7120+1

        defadr List_DestroyElements,0x11AD3A1C+1
        defadr List_Destroy,0x11AD3730+1
        defadr List_Create,0x11AD3708+1
        defadr List_InsertFirst,0x11AD387C+1
        defadr List_Get,0x11AD3928+1
        defadr List_GetCount,0x11AD38FC+1

        defadr JavaDialog_Open,0x10B12910+1
        defadr JavaAppDesc_GetFirstApp,0x10B083CC+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B07E98+1
        defadr JavaApp_LogoImageID_Get,0x10C2E4E4+1
        defadr JavaAppDesc_GetNextApp,0x10B083D4+1
        defadr JavaDialog_Close,0x10B16010+1
        defadr manifest_GetParam,0x10B04B10+1
        defadr JavaSession_GetName,0x108DCEAC+1

        defadr ConnectionManager_Connection_GetState_int,0x10C23094+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x114FF020+1
        defadr REQUEST_SYSTEM_RESTART,0x114FF040+1
        defadr Shortcut_Run,0x10DDBF08+1
        defadr FlightGetState,0x11A68ED0+1
        defadr FlightControl,0x11A696E4+1
        defadr Request_ICA_ShutdownAllConnections,0x114A1408+1
        defadr Display_GetBrightness,0x10DC06B8+1
        defadr GetNewEvent,0x10B37018+1

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
        ldr     r3, =0x10B30888+1
        blx     r3
        cmp     r0, #0
        beq     get_focus
        ldr     r3, =0x10B30CD4+1
        bx      r3
get_focus:
        bl      GetFocusTab
        mov     r5, r0
        ldr     r3, =0x10B30CF2+1
        bx      r3

_onCreate:
        bl      CreateBookAndElfsLists
        ldr     r1, =0x10B30EFC+1
        ldr     r0, [r4,#0x24]
        ldr     r3, =TabMenuBar_SetOnTabSwitch
        blx     r3
        ldr     r3, =0x10B30F3C+1
        bx      r3

_onClose:
        add     r0, r4, #0
        ldr     r3, =0x10B30864+1
        blx     r3
        cmp     r5, #0
        beq     empty_offset_60
        mov     R0, #2
        ldr     r3, =0x10B30BA8+1
        blx     r3
empty_offset_60:
        bl      ActivityBook_onClose
        POP     {R4-R7,PC}

_Internet:
        mov     r1, r5
        mov     r0, r4
        bl      CreateShortcutMenu
        pop     {r4-r6,pc}

_Shortcurts:
        mov     r1, r5
        mov     r0, r4
        bl      CreateElfMenu
        pop     {r4-r6,pc}

_Activetasks:
        mov     r1, r5
        mov     r0, r4
        bl      CreateBookMenu
        pop     {r4-r6,pc}

        END
