//T707_R1FA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA305D4
        defadr memfree,0x4BA305FC
        defadr memset,0x14BF9304
        defadr debug_printf,0x14C0ED74
        defadr current_process,0x101EBDC0
        defadr get_bid,0x101EBDF8
        defadr set_envp,0x101F298C+1
        defadr get_envp,0x101F2978+1
        defadr _fopen,0x14219C48+1
        defadr fread,0x1430F168+1
        defadr fclose,0x1410D64C+1
        defadr fwrite,0x1456DBC8+1
        defadr fstat,0x1435A500+1
        defadr w_fstat,0x10176C20+1
        defadr strlen,0x14CDE90C+1
        defadr strstr,0x141EA790+1
        defadr strcpy,0x14CDE8D8+1
        defadr str2wstr,0x1415FAD0+1
        defadr strcmp,0x14CDE8B0+1
        defadr strncmp,0x14336214+1
        defadr sprintf,0x14117098+1
        defadr wstrcpy,0x1430F0C8+1
        defadr wstrncpy,0x14358704+1
        defadr wstrcmp,0x1430F97C+1
        defadr wstrncmp,0x142C74B0+1
        defadr wstrlen,0x1430F910+1
        defadr wstrcmpi,0x14310944+1
        defadr wstrrchr,0x1409AB48+1
        defadr snwprintf,0x142C60F8+1
        defadr wtoi,0x1415EBD4+1
        defadr CreateBook,0x144678E8+1
        defadr FreeBook,0x14364DE4+1
        defadr BookObj_GotoPage,0x14026870+1
        defadr BookObj_SetFocus,0x14220970+1
        defadr BookObj_GetSession,0x14026FF0+1
        defadr BookObj_GetBookID,0x14026320+1
        defadr Find_StandbyBook,0x1444B0B8+1
        defadr UI_Event,0x1431B5F0+1
        defadr UI_Event_toBookID,0x1431C94C+1
        defadr UI_Event_toBookIDwData,0x14364D30+1
        defadr root_list_get_session_count,0x14062EBC+1
        defadr root_list_get_session,0x1419DE00+1
        defadr Battery_GetChargingState,0x142D9254+1
        defadr Illumination_LedID_SetLevel,0x145144E8+1
        defadr Illumination_LedID_Off,0x143A5488+1
        defadr TextID_Create,0x14225E0C+1
        defadr TextID_CreateIntegerID,0x14520FE0+1
        defadr TextID_Destroy,0x1422547C+1
        defadr TextID_GetString,0x14225568+1
        defadr TextID_GetWString,0x142250E8+1
        defadr CreateStringInput,0x144E2178+1
        defadr StringInput_SetMode,0x1437D5B0+1
        defadr StringInput_SetMinLen,0x14FEF3C0+1
        defadr StringInput_SetMaxLen,0x14FEF1E0+1
        defadr StringInput_SetEnableEmptyText,0x14FEEF70+1
        defadr StringInput_SetText,0x14FEEFB8+1
        defadr StringInput_SetFixedText,0x14FEF610+1
        defadr StringInput_SetActionOK,0x14FEF060+1
        defadr StringInput_SetActionBack,0x14FEF058+1
        defadr GUIObject_Show,0x144670F4+1
        defadr CreateMessageBox,0x14E901B8+1
        defadr CreateListMenu,0x142204B8+1
        defadr ListMenu_SetItemStyle,0x143645EC+1
        defadr ListMenu_SetItemCount,0x14210768+1
        defadr ListMenu_SetOnMessage,0x143E7500+1
        defadr ListMenu_SetCursorToItem,0x14364918+1
        defadr ListMenu_GetSelectedItem,0x1453E0AC+1
        defadr ListMenu_SetNoItemText,0x14F58604+1
        defadr ListMenu_SetItemSecondLineText,0x142E4E74+1
        defadr GUIonMessage_GetBook,0x1412C044+1
        defadr GUIonMessage_GetMsg,0x1412C238+1
        defadr GUIonMessage_SetItemDisabled,0x14245E70+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14F97668+1
        defadr GUIonMessage_GetSelectedItem,0x1453DB28+1
        defadr GUIonMessage_SetMenuItemIcon,0x14158FF8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412C330+1
        defadr GUIonMessage_SetMenuItemText,0x1453BD2C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453B3E4+1
        defadr GUIObject_SetTitleIcon,0x143F039C+1
        defadr GUIObject_SetTitleType,0x143BB2CC+1
        defadr GUIObject_SetTitleText,0x142E5310+1
        defadr GUIObject_SetStyle,0x14242B84+1
        defadr GUIObject_Destroy,0x14220468+1
        defadr GUIObject_SoftKeys_SetAction,0x1419D738+1
        defadr GUIObject_SoftKeys_SetText,0x1412A640+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419D784+1
        defadr GUIObject_SoftKeys_SetEnable,0x1412A994+1
        defadr TabMenuBar_GetFocusedTab,0x1453BD90+1
        defadr TabMenuBar_SetOnTabSwitch,0x1424375C+1
        defadr TabMenuBar_SetTabGui,0x142F5114+1
        defadr TabMenuBar_SetTabTitle,0x143BBE90+1
        defadr GUIObject_TabTitleRemove,0x1500595C+1
        defadr Timer_Kill,0x142D99D4+1
        defadr Timer_ReSet,0x142D9A34+1
        defadr DynamicMenu_GetElementMsg,0x141532B4+1
        defadr DynamicMenu_SetElement_SecondLineText,0x1456914C+1

        defadr GUIObject_GetDispObject,0x140481D4+1
        defadr DispObject_GetOnKey,0x14461410+1
        defadr DispObject_GetDESC,0x15042944+1
        defadr DISP_DESC_SetOnKey,0x1430A7CC+1
        defadr Shortcut_Run,0x1456B704+1
        defadr List_DestroyElements,0x1424E974+1
        defadr List_Destroy,0x14025D38+1
        defadr List_Create,0x142D9BF8+1
        defadr List_Get,0x1430FDD0+1
        defadr List_GetCount,0x1431005C+1
        defadr List_InsertFirst,0x1424BA00+1
        defadr IsVolumeControllerBook,0x141BCD70+1
        defadr IsRightNowBook,0x14009A2C+1
        defadr JavaDialog_Open,0x141C6688+1
        defadr JavaDialog_Close,0x144EB838+1
        defadr JavaAppDesc_GetFirstApp,0x141CA1A4+1
        defadr JavaAppDesc_GetNextApp,0x144EB940+1
        defadr JavaAppDesc_GetJavaAppInfo,0x144EA900+1
        defadr JavaApp_LogoImageID_Get,0x142B5E58+1
        defadr JavaSession_GetName,0x1510ECE0+1

        defadr Request_ICA_ShutdownAllConnections,0x1037C2B8+1
        defadr ConnectionManager_Connection_GetState_int,0x144BC970+1
        defadr Display_GetBrightness,0x14DAAD60+1

        defadr NewEvents_GetCount,0x14F87144+1
        defadr iconidname2id,0x1435775C+1

        defadr MessageBox,0x1580AD20+1
        defadr manifest_GetParam,0x14335B5C+1
        defadr GetFreeBytesOnHeap,0x4BA30740
        defadr REQUEST_SYSTEM_SHUTDOWN,0x10482564+1
        defadr REQUEST_SYSTEM_RESTART,0x10482584+1
        defadr FlightMode_GetState,0x141534E8+1
        defadr FlightMode_SetState,0x14D49AEC+1

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
        DCD 0x82E

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
        str     r3, [r0,#4]
        ldr     r1, =0x834
        strh    r1, [r0,#8]
        sub     r1, r1, #1
        strh    r1, [r0,#0xA]
        ldr     r1, =0xCEE
        str     r1, [r0,#0xC]
        pop     {r4,r5,pc}

_Tabfocus:
        ldr     r3, =0x14F87680+1
        blx     r3
        cmp     r0, #0
        beq     set_focus
        ldr     r3, =0x14F87344+1
        bx      r3
set_focus:
        bl      GetFocusTab
        add     r5, r0, #0
        ldr     r3, =0x14F87362+1
        bx      r3

_onCreate:
        bl      CreateBookAndElfsLists
        ldr     r1, =0x14022FD0+1
        ldr     r0, [r4,#0x24]
        ldr     r3, =TabMenuBar_SetOnTabSwitch
        blx     r3
        ldr     r3, =0x14F87208+1
        bx      r3

_onClose:
        bl      ActivityBook_onClose
        add     r0, r4, #0
        ldr     r3, =0x14F8E410+1
        blx     r3
        pop     {r4,r5,pc}

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
