//K630_R1FA032

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x10098358
        defadr memfree,0x10098380
        defadr memset,0x2A1C07A0
        defadr memcpy,0x100B83F4

        defadr snwprintf,0x104E3DB4+1
        defadr wstrlen,0x10F75F1C+1
        defadr wstrncmp,0x104E4548+1
        defadr str2wstr,0x10F771E4+1
        defadr strlen,0x104E3BE4+1
        defadr strstr,0x104E3CF0+1
        defadr strncmp,0x104E3C20+1
        defadr strcpy,0x104E3BB0+1
        defadr strcmp,0x104E3B88+1

        defadr set_envp,0x100A3080+1
        defadr get_envp,0x100A306C+1
        defadr iconidname2id,0x10CAAF14+1
        defadr BookObj_GetSession,0x11597C94+1
        defadr TextID_GetString,0x11618594+1

        defadr fstat,0x10F85398+1
        defadr _fopen,0x10F84AA0+1
        defadr fread,0x10F861E4+1
        defadr fclose,0x11542130+1

        defadr List_DestroyElements,0x113C08D8+1
        defadr List_Destroy,0x113C05EC+1
        defadr List_Create,0x113C05C4+1
        defadr List_Get,0x113C07E4+1
        defadr List_GetCount,0x113C07B8+1
        defadr List_InsertFirst,0x113C0738+1
        defadr root_list_get_session_count,0x11595814+1
        defadr root_list_get_session,0x11595820+1

        defadr Find_StandbyBook,0x115A3184+1
        defadr BookObj_GetBookID,0x11597CF4+1

        defadr UI_Event_toBookID,0x115964DC+1
        defadr UI_Event,0x11596484+1
        defadr TextID_Create,0x11617FF0+1
        defadr MessageBox,0x1159D330+1
        defadr FreeBook,0x11597C48+1
        defadr BookObj_SetFocus,0x115978DC+1
        defadr UI_Event_toBookIDwData,0x115964F0+1

        defadr GUIObject_SetStyle,0x1163AA58+1
        defadr GUIObject_Destroy,0x1163A804+1

        defadr GUIonMessage_GetMsg,0x115ECC20+1
        defadr GUIonMessage_GetCreatedItemIndex,0x115ECC44+1
        defadr GUIonMessage_SetMenuItemText,0x115ECC50+1
        defadr GUIonMessage_SetMenuItemIcon,0x115ECC90+1
        defadr GUIonMessage_SetItemDisabled,0x115ECCF0+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x115ECC70+1
        defadr GUIonMessage_GetSelectedItem,0x115ECC2C+1

        defadr CreateListMenu,0x115EBF18+1
        defadr ListMenu_SetOnMessage,0x115EC258+1
        defadr ListMenu_SetItemCount,0x115EC148+1
        defadr ListMenu_SetCursorToItem,0x115EC120+1
        defadr ListMenu_SetNoItemText,0x115EC2D8+1
        defadr ListMenu_GetSelectedItem,0x115EC134+1
        defadr GUIObject_TabTitleRemove,0x115EC898+1
        defadr GUIObject_GetDispObject,0x1163A874+1
        defadr DispObject_GetOnKey,0x1162AFF4+1
        defadr DispObject_GetDESC,0x10A16B20+1
        defadr DISP_DESC_SetOnKey,0x1162AF18+1
        defadr TabMenuBar_SetTabGui,0x11647A9C+1
        defadr TabMenuBar_SetTabTitle,0x11647B64+1
        defadr TabMenuBar_SetOnTabSwitch,0x11647B64+1
        defadr TabMenuBar_GetFocusedTab,0x11647A90+1

        defadr GUIObject_SoftKeys_SetEnable,0x116542CC+1
        defadr GUIObject_SoftKeys_SetText,0x116541DC+1
        defadr GUIObject_SoftKeys_SetAction,0x11654164+1
        defadr GUIObject_SoftKeys_SetVisible,0x11654260+1

        defadr REQUEST_SYSTEM_SHUTDOWN,0x109C4464+1
        defadr REQUEST_SYSTEM_RESTART,0x109C4484+1
        defadr Shortcut_Run,0x1165AC10+1
        defadr FlightMode_GetState,0x115A1ED8+1
        defadr FlightMode_SetState,0x115A250C+1
        defadr Request_ICA_ShutdownAllConnections,0x109672AC+1
        defadr Display_GetBrightness,0x115B9148+1
        defadr ConnectionManager_Connection_GetState,0x113DD28C+1

        defadr IsVolumeControllerBook,0x11673CC0+1
        defadr IsRightNowBook,0x11663A34+1

        defadr JavaDialog_Open,0x10F9F3A4+1
        defadr JavaAppDesc_GetFirstApp,0x10F953B0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10F94EBC+1
        defadr JavaApp_LogoImageID_Get,0x1107E240+1
        defadr JavaAppDesc_GetNextApp,0x10F953B8+1
        defadr JavaDialog_Close,0x10FA2A80+1
        defadr JavaSession_GetName,0x111072B0+1
        defadr manifest_GetParam,0x10F92170+1

        defadr NewEvents_GetCount,0x11669DCC+1
        defadr GetFreeBytesOnHeap,0x100984D4

        EXTERN GetFocusTab
        EXTERN CreateBookAndElfsLists
        EXTERN ActivityBook_onClose
        EXTERN EventsTitleText
        EXTERN CreateBookMenu
        EXTERN CreateElfMenu
        EXTERN CreateShortcutMenu


        RSEG   TAB_ICON_1
        CODE16
        ldr	r7, =_IconInternet
        bx	r7

        RSEG   TAB_ICON_2
        DATA
        DCD	0xF346

        RSEG   TAB_FOCUS
        CODE16
        ldr	r3, =_Tabfocus
        bx	r3

        RSEG   GUI_CREATE
        CODE16
        ldr	r3, =_onCreate
        bx	r3

        RSEG   BOOK_CLOSE
        CODE16
        ldr	r3, =_onClose
        bx	r3

        RSEG   EVENTS
        CODE16
        ldr	r3, =EventsTitleText
        bx	r3

        RSEG   INTERNET
        CODE16
        ldr	r3, =_Internet
        bx	r3

        RSEG   SHORTCURTS
        CODE16
        ldr	r3, =_Shortcurts
        bx	r3

        RSEG   ACTIVETASKS
        CODE16
        ldr	r3, =_Activetasks
        bx	r3

        RSEG   CODE
        CODE16
_IconInternet:
        str	r3, [r0,#4]
        ldr	r1, =0xF344
        strh	r1, [r0,#8]
        sub	r1, r1, #1
        strh	r1, [r0,#0xA]
        ldr	r1, =0xDB8
        str	r1, [r0,#0xC]
        pop	{r4,r5,pc}

_Tabfocus:
        ldr	r3, =0x11663770+1
        blx	r3
        cmp	r0, #0
        beq	set_focus
        ldr	r3, =0x11663D10+1
        bx	r3
set_focus:
        bl	GetFocusTab
        add	r5, r0, #0
        ldr	r3, =0x11663D2E+1
        bx	r3

_onCreate:
	MOV	R1, #9
	ldr	r3, =GUIObject_SetStyle
        blx	r3
        bl	CreateBookAndElfsLists
        ldr	r1, =0x11663F5C+1
        ldr	r0, [r4,#0x28]
        ldr	r3, =TabMenuBar_SetOnTabSwitch
        blx	r3
        ldr	r3, =0x11663F9A+1
        bx	r3

_onClose:
        ldr	r3, =0x115A06F8+1
        blx	r3
	bl	ActivityBook_onClose
        pop	{r4-r7,pc}

_Internet:
        add	r1, r5, #0
        add	r0, r4, #0
        bl	CreateShortcutMenu
        pop	{r4-r6,pc}

_Shortcurts:
        add	r1, r5, #0
        add	r0, r4, #0
        bl	CreateElfMenu
        pop	{r4-r6,pc}

_Activetasks:
        add	r1, r5, #0
        add	r0, r4, #0
        bl	CreateBookMenu
        pop	{r4-r6,pc}

        END
