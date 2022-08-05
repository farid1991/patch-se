//W810_R4EA031

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
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
        defadr w_diropen,0x455E5DC0+1
        defadr w_chdir,0x455E40A4+1
        defadr w_dirread,0x4510AA68+1
        defadr w_fstat,0x44B24B64+1
        defadr w_dirclose,0x455E603C+1
        defadr wstrlen,0x44FE9B2C+1
        defadr wstrcmpi,0x44FEAFB4+1
        defadr wstrrchr,0x44E25D38+1
        defadr wstrcpy,0x44E25C34+1
        defadr wstrncmp,0x44E25CAC+1
        defadr str2wstr,0x44FEAE4C+1
        defadr strncmp,0x44E2538C+1
        defadr strcmp,0x44E252EC+1
        defadr strlen,0x44E25354+1
        defadr strcpy,0x44E2531C+1
        defadr strstr,0x44E2546C+1

        defadr BookObj_GetSession,0x4529FCB0+1
        defadr BookObj_SetFocus,0x4529F994+1
        defadr BookObj_GetBookID,0x4529FD0C+1
        defadr FreeBook,0x4529FC78+1

        defadr TextID_Create,0x452FE69C+1
        defadr TextID_GetString,0x452FF248+1

        defadr List_DestroyElements,0x4527F3B4+1
        defadr List_Destroy,0x4527EFC4+1
        defadr List_Create,0x4527EFAC+1
        defadr List_Get,0x4527F250+1
        defadr List_InsertFirst,0x4527F0C0+1
        defadr List_GetCount,0x4527F228+1
        defadr root_list_get_session_count,0x45531254+1
        defadr root_list_get_session,0x45531268+1

        defadr IsVolumeControllerBook,0x45643CC0+1
        defadr IsRightNowBook,0x4563E6CC+1
        defadr Find_StandbyBook,0x452AC7B8+1

        defadr JavaDialog_Open,0x45020BF0+1
        defadr JavaDialog_Close,0x45023F98+1
        defadr JavaAppDesc_GetFirstApp,0x4501BE90+1
        defadr JavaAppDesc_GetNextApp,0x4501BE98+1
        defadr JavaAppDesc_GetJavaAppInfo,0x4501BB98+1
        defadr JavaApp_LogoImageID_Get,0x4544A3B8+1
        defadr JavaSession_GetName,0x45641594+1
        defadr manifest_GetParam,0x45565E94+1

        defadr UI_Event_toBookID,0x455312AC+1
        defadr UI_Event,0x4553127C+1
        defadr UI_Event_toBookIDwData,0x455312BC+1
        defadr MessageBox,0x45533C94+1
        defadr GetFreeBytesOnHeap,0x45455734+1
        defadr iconidname2id,0x45329110+1

        defadr CreateListMenu,0x45170674+1
        defadr ListMenu_SetOnMessage,0x451709D8+1
        defadr ListMenu_SetItemCount,0x4517089C+1
        defadr ListMenu_SetCursorToItem,0x45170870+1
        defadr ListMenu_SetNoItemText,0x45170A5C+1
        defadr ListMenu_GetSelectedItem,0x45170884+1
        defadr GUIObject_SetStyle,0x45193EC4+1
        defadr GUIObject_TabTitleRemove,0x45171014+1
        defadr GUIObject_SoftKeys_SetAction,0x4519B824+1
        defadr GUIObject_SoftKeys_SetVisible,0x4519B9A4+1
        defadr GUIObject_SoftKeys_SetText,0x4519B90C+1
        defadr GUIObject_SoftKeys_SetEnable,0x4519BA78+1
        defadr GUIObject_Destroy,0x45193BE4+1

        defadr GUIonMessage_GetMsg,0x45171378+1
        defadr GUIonMessage_GetCreatedItemIndex,0x451713A4+1
        defadr GUIonMessage_SetMenuItemText,0x451713B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x451713F4+1
        defadr GUIonMessage_SetItemDisabled,0x4517144C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x451713D4+1
        defadr GUIonMessage_GetSelectedItem,0x45171384+1

        defadr TabMenuBar_GetFocusedTab,0x45153844+1
        defadr TabMenuBar_SetTabGui,0x4515394C+1
        defadr TabMenuBar_SetTabTitle,0x45153A58+1
        defadr TabMenuBar_SetOnTabSwitch,0x45153ABC+1

        defadr GUIObject_GetDispObject,0x45193C40+1
        defadr DispObject_GetOnKey,0x45301FCC+1
        defadr DispObject_GetDESC,0x4531E678+1
        defadr DISP_DESC_SetOnKey,0x45301D30+1

        defadr NewEvents_GetCount,0x4563FA6C+1

        EXTERN GetFocusTab
        EXTERN CreateBookAndElfsLists
        EXTERN ActivityBook_onClose
        EXTERN EventsTitleText
        EXTERN CreateBookMenu
        EXTERN CreateElfMenu
        EXTERN CreateShortcutMenu

        RSEG   ICON_TAB_ACTIVETASKS
        DATA
        DCD     0xE7F00001
        DCD     0xE7F1

        RSEG   ICON_TAB_INTERNET
        DATA
        DCD     0xE7F2
        DCD     0xE7F3

        RSEG   TAB_FOCUS
        CODE16
        LDR     R3, =_Tabfocus
        BX      R3


        RSEG   CODE
        CODE16
_Tabfocus:
        BL      GetFocusTab
        CMP     r0, #0
        BNE     _first_tab
        LDR     R3, =0x4563E424+1
        BX      R3

_first_tab:
        LDR     R3, =0x4563E42A+1
        BX      R3

        RSEG   GUI_CREATE
        CODE16
        LDR     R3, =_onCreate
        BX      R3

        RSEG   CODE
        CODE16
_onCreate:
        BL      CreateBookAndElfsLists
        LDR     R1, =0x4563E1EC+1
        LDR     R0, [R5,#0]
        LDR     R3, =TabMenuBar_SetOnTabSwitch
        BLX     R3
        LDR     R3, =0x4563E3EC+1
        BX      R3

        RSEG   BOOK_CLOSE
        CODE16
        LDR     R3, =_onClose
        BX      R3

        RSEG   CODE
        CODE16
_onClose:
        CMP     R4, #0
        BEQ     _nextOnClose
        MOV     R0, #0
        LDR     R3, =0x4563EC38+1
        BLX     R3
        BL      ActivityBook_onClose
_nextOnClose:
        POP     {R1-R7,PC}

        RSEG   TAB_EVENTS
        CODE16
        LDR     R3, =EventsTitleText
        BX      R3

        RSEG   TAB_INTERNET
        CODE16
        LDR     R3, =_Internet
        BX      R3
_Internet:
        MOV     R1, #2
        BL      CreateElfMenu
        POP     {R4-R7,PC}

        RSEG   TAB_ACTIVETASKS
        CODE16
        LDR     R3, =_Activetasks
        BX      R3
_Activetasks:
        MOV     r1, #1
        BL      CreateBookMenu
        POP     {R4-R7,PC}

        END
