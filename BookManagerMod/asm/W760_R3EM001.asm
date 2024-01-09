//W760_R3EM001

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB01144
        defadr set_envp,0x10005C4C+1
        defadr get_envp,0x10005C38+1
        defadr ConnectionManager_Connection_GetState_int,0x10CBFFBC+1
        defadr iconidname2id,0x115BABB0+1
        defadr BookObj_GetSession,0x10E8A278+1
        defadr TextID_GetString,0x10FFC64C+1
        defadr strncmp,0x107989A0+1
        defadr JavaSession_GetName,0x1096CED4+1
        defadr strcmp,0x10798908+1
        defadr fstat,0x109F61A4+1
        defadr _fopen,0x109F5840+1
        defadr fread,0x109F71D4+1
        defadr fclose,0x117A443C+1
        defadr w_fstat,0x11331024+1
        defadr TabMenuBar_GetFocusedTab,0x1180E95C+1
        defadr ListMenu_GetSelectedItem,0x11B107D0+1
        defadr List_Get,0x11B56EB0+1
        defadr Find_StandbyBook,0x10E28CE8+1
        defadr BookObj_GetBookID,0x10E8A318+1
        defadr List_GetCount,0x11B56E84+1
        defadr UI_Event_toBookID,0x10E889A4+1
        defadr UI_Event,0x10E8894C+1
        defadr TextID_Create,0x10FFBF40+1
        defadr TextID_Destroy,0x10FFC27C+1
        defadr TextID_GetWString,0x10FFC4D4+1
        defadr MessageBox,0x11AE853C+1
        defadr FreeBook,0x10E8A22C+1
        defadr manifest_GetParam,0x10BA3410+1
        defadr wstrlen,0x10E01180+1
        defadr wstrcmp,0x10E01194+1
        defadr strlen,0x10798964+1
        defadr strstr,0x10798A70+1
        defadr GUIonMessage_GetMsg,0x11B1136C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11B11390+1
        defadr GUIonMessage_SetMenuItemText,0x11B1139C+1
        defadr GUIonMessage_SetMenuItemIcon,0x11B113DC+1
        defadr GetFreeBytesOnHeap,0x4BB00700
        defadr CreateListMenu,0x11B105D0+1
        defadr ListMenu_SetOnMessage,0x11B108F4+1
        defadr ListMenu_SetItemCount,0x11B107E4+1
        defadr ListMenu_SetCursorToItem,0x11B107BC+1
        defadr GUIObject_SetStyle,0x10A6FD6C+1
        defadr GUIObject_TabTitleRemove,0x11B10ED4+1
        defadr GUIObject_SoftKeys_SetAction,0x108AE74C+1
        defadr GUIObject_SoftKeys_SetVisible,0x108AE848+1
        defadr GUIObject_GetDispObject,0x10A6FBAC+1
        defadr DispObject_GetOnKey,0x10A63110+1
        defadr DispObject_GetDESC,0x10014E98+1
        defadr DISP_DESC_SetOnKey,0x10A63034+1
        defadr TabMenuBar_SetTabGui,0x1180E968+1
        defadr TabMenuBar_SetTabTitle,0x1180EA30+1
        defadr BookObj_SetFocus,0x10E89E5C+1
        defadr UI_Event_toBookIDwData,0x10E889B8+1
        defadr GUIObject_SoftKeys_SetEnable,0x108AE8B4+1
        defadr ListMenu_SetNoItemText,0x11B10974+1
        defadr GUIonMessage_SetItemDisabled,0x11B11444+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11B113BC+1
        defadr GUIonMessage_GetSelectedItem,0x11B11378+1
        defadr sprintf,0x10798680+1
        defadr snwprintf,0x10798B34+1
        defadr GUIObject_SoftKeys_SetText,0x108AE7C4+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11596430+1
        defadr REQUEST_SYSTEM_RESTART,0x11596450+1
        defadr Shortcut_Run,0x10E76124+1
        defadr FlightMode_GetState,0x11AEC68C+1
        defadr FlightMode_SetState,0x11AECEA0+1
        defadr Request_ICA_ShutdownAllConnections,0x115373AC+1
        defadr Display_GetBrightness,0x10E5AA44+1
        defadr List_DestroyElements,0x11B56FA4+1
        defadr List_Destroy,0x11B56CB8+1
        defadr List_Create,0x11B56C90+1
        defadr root_list_get_session_count,0x10E87EE4+1
        defadr root_list_get_session,0x10E87EF4+1
        defadr List_InsertFirst,0x11B56E04+1
        defadr IsVolumeControllerBook,0x11B4A12C+1
        defadr IsRightNowBook,0x10BD022C+1
        defadr strcpy,0x10798930+1
        defadr JavaDialog_Open,0x10BB13A0+1
        defadr JavaAppDesc_GetFirstApp,0x10BA6D34+1
        defadr str2wstr,0x10E02448+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10BA6800+1
        defadr wstrncmp,0x107992C8+1
        defadr JavaApp_LogoImageID_Get,0x10CCB41C+1
        defadr JavaAppDesc_GetNextApp,0x10BA6D3C+1
        defadr JavaDialog_Close,0x10BB4AF4+1
        defadr GUIObject_Destroy,0x10A6FB20+1
        defadr NewEvents_GetCount,0x10BD65AC+1

        defadr TabMenuBar_SetOnTabSwitch,0x1180EA44+1

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
        ldr     r3, =0x10BD00B0+1
        blx     r3
        cmp     r0, #0
        beq     get_focus
        ldr     r3, =0x10BD0504+1
        bx      r3
get_focus:
        bl      GetFocusTab
        mov     r5, r0
        ldr     r3, =0x10BD0522+1
        bx      r3

_onCreate:
        bl      CreateBookAndElfsLists
        ldr     r1, =0x10BD072C+1
        ldr     r0, [r4,#0x24]
        ldr     r3, =TabMenuBar_SetOnTabSwitch
        blx     r3
        ldr     r3, =0x10BD076C+1
        bx      r3

_onClose:
        add     r0, r4, #0
        ldr     r3, =0x10BD008C+1
        blx     r3
        cmp     r5, #0
        beq     empty_offset_60
        mov     R0, #2
        ldr     r3, =0x10BD03D8+1
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
