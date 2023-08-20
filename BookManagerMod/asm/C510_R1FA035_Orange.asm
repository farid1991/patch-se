//C510_R1FA035_Orange

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA31378
        defadr memfree,0x4BA313A0
        defadr memset,0x14BA26B8
        defadr snwprintf,0x143E9868+1
        defadr FreeBook,0x14127DE4+1
        defadr Find_StandbyBook,0x141AA460+1
        defadr BookObj_SetFocus,0x144C518C+1
        defadr ListMenu_SetCursorToItem,0x14412628+1
        defadr GUIObject_SetStyle,0x14128260+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142C20B4+1
        defadr GUIonMessage_SetMenuItemText,0x14385D48+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14074AD4+1
        defadr ListMenu_GetSelectedItem,0x1427C72C+1
        defadr GUIObject_SoftKeys_SetAction,0x1417996C+1
        defadr GUIObject_SoftKeys_SetText,0x141C29F8+1
        defadr GUIObject_SoftKeys_SetVisible,0x141C275C+1
        defadr str2wstr,0x141C7378+1
        defadr strcmp,0x14C7A774+1
        defadr strlen,0x14C7A7D0+1
        defadr TextID_Create,0x1417F6A4+1
        defadr TextID_GetString,0x1417FE88+1
        defadr List_Create,0x1430A17C+1
        defadr List_Destroy,0x1430A2E0+1
        defadr List_InsertFirst,0x1430A548+1
        defadr GetFreeBytesOnHeap,0x14215F10+1
        defadr ListMenu_SetOnMessage,0x142FE898+1
        defadr get_envp,0x101D6CD4+1
        defadr set_envp,0x101D6CE8+1
        defadr strcpy,0x14C7A79C+1
        defadr UI_Event,0x140C45D4+1
        defadr UI_Event_toBookID,0x141F1C24+1
        defadr UI_Event_toBookIDwData,0x14127D44+1
        defadr List_Get,0x140CB03C+1
        defadr CreateListMenu,0x14282300+1
        defadr ListMenu_SetItemCount,0x1427CC44+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x1047B7C0+1
        defadr REQUEST_SYSTEM_RESTART,0x1047B7E0+1
        defadr IsRightNowBook,0x1400473C+1
        defadr IsVolumeControllerBook,0x1419795C+1
        defadr TabMenuBar_SetTabGui,0x141263F8+1
        defadr GUIObject_Destroy,0x144C5D5C+1
        defadr root_list_get_session_count,0x1447C8E0+1
        defadr root_list_get_session,0x1447CB84+1
        defadr BookObj_GetBookID,0x140CA8A4+1
        defadr BookObj_GetSession,0x1447C498+1
        defadr MessageBox,0x158C9E2C+1
        defadr TabMenuBar_GetFocusedTab,0x14228EC0+1
        defadr GUIonMessage_SetItemDisabled,0x144D9760+1
        defadr ListMenu_SetNoItemText,0x1419CE40+1
        defadr Shortcut_Run,0x142757EC+1
        defadr List_DestroyElements,0x140EDDC8+1
        defadr TabMenuBar_SetOnTabSwitch,0x140419B8+1
        defadr Display_GetBrightness,0x14DA36D4+1
        defadr Request_ICA_ShutdownAllConnections,0x10512DA0+1
        defadr GUIonMessage_GetMsg,0x142C21A4+1
        defadr GUIonMessage_GetSelectedItem,0x14168994+1
        defadr TabMenuBar_SetTabTitle,0x14284654+1
        defadr ListMenu_DestroyItems,0x1427CFB4+1
        defadr FlightGetState,0x141B2E50+1
        defadr FlightControl,0x144CC008+1
        defadr NewEvents_GetCount,0x14385228+1
        defadr ConnectionManager_Connection_GetState_int,0x1440BB74+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x14279C5C+1
        defadr GUIObject_TabTitleRemove,0x143BCED0+1
        defadr TabMenuBar_SetTabIcon,0x14126530+1

        EXTERN SetFocusTab
        EXTERN CreateBookAndElfsLists
        EXTERN ActivityBook_onClose
        EXTERN EventsTitleText
        EXTERN CreateBMenu
        EXTERN CreateEMenu
        EXTERN CreateAMenu

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
        ldr     r3, =0x14E7257C+1
        blx     r3
        cmp     r0, #0
        beq     set_focus
        ldr     r3, =0x14E726E4+1
        bx      r3
set_focus:
        bl      SetFocusTab
        mov     r5, r0
        ldr     r3, =0x14E72702+1
        bx      r3

_onCreate:
        ldr     r1, [r4,#0x24]
        mov     r0, r4
        bl      CreateBookAndElfsLists
        ldr     r1, =0x14024CF4+1
        ldr     r0, [r4,#0x24]
        ldr     r3, =TabMenuBar_SetOnTabSwitch
        blx     r3
        ldr     r3, =0x14E7250C+1
        bx      r3

_onClose:
        bl ActivityBook_onClose
        mov r0, r4
        ldr r3, =0x14DCCE50+1
        blx r3
        pop {r4,r5,pc}

_Internet:
        mov     r1, r5
        mov     r0, r4
        bl      CreateAMenu
        pop     {r4-r6,pc}

_Shortcurts:
        mov     r1, r5
        mov     r0, r4
        bl      CreateEMenu
        pop     {r4-r6,pc}

_Activetasks:
        mov     r1, r5
        mov     r0, r4
        bl      CreateBMenu
        pop     {r4-r6,pc}

        END