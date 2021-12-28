//U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr debug_printf,0x4FC00008
	defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
	defadr memset,0x140EA530
        defadr memcpy,0x1482A864
        defadr GetFreeBytesOnHeap,0x4FC00500
	defadr snwprintf,0x148298C8+1

        defadr _fopen,0x146F6100+1
        defadr fread,0x141B4D98+1
        defadr fclose,0x14644828+1
        defadr fwrite,0x146F6F9C+1
        defadr fstat,0x141F353C+1

        defadr current_process,0x10292B7C
        defadr get_bid,0x10292BB4
	defadr get_envp,0x102932CC+1
	defadr set_envp,0x102932E0+1

        defadr FreeBook,0x141043A0+1
        defadr BookObj_SetFocus,0x14668EB8+1
        defadr BookObj_GetSession,0x145A18FC+1
	defadr BookObj_GetBookID,0x143D9B54+1
	defadr UI_Event_toBookID,0x14647524+1
	defadr UI_Event,0x1427AD8C+1

	defadr iconidname2id,0x140D0C68+1

        defadr strlen,0x10294408+1
	defadr strstr,0x1482B176+1
	defadr strcmp,0x10294370+1
        defadr strcpy,0x102943C8+1
        defadr strcat,0x10294448+1
        defadr strncmp,0x1482AEA8+1
        defadr str2wstr,0x1418E698+1
        defadr wstrlen,0x141B5400+1
        defadr wstrncmp,0x1482A93C+1

	defadr manifest_GetParam,0x1447A4F8+1
	defadr TextID_Create,0x145382A0+1
        defadr TextID_GetString,0x142C005C+1

	defadr List_DestroyElements,0x141F2D1C+1
	defadr List_Destroy,0x1427BA18+1
	defadr List_Create,0x1427B71C+1
        defadr List_InsertFirst,0x14278C5C+1
        defadr List_GetCount,0x143D9C60+1
	defadr List_Get,0x143D96FC+1

	defadr root_list_get_session_count,0x147E9428+1
	defadr root_list_get_session,0x142BF868+1

	defadr JavaAppDesc_GetFirstApp,0x143E8F44+1
        defadr JavaAppDesc_GetNextApp,0x145E27B0+1
	defadr JavaAppDesc_GetJavaAppInfo,0x1411A324+1
	defadr JavaApp_LogoImageID_Get,0x1433C900+1
        defadr JavaDialog_Open,0x1465B53C+1
	defadr JavaDialog_Close,0x14119DB8+1

	defadr IsVolumeControllerBook,0x142537F8+1
	defadr IsRightNowBook,0x14006F24+1
        defadr Find_StandbyBook,0x147D93C4+1

	defadr GUIonMessage_GetMsg,0x146D0C1C+1
	defadr GUIonMessage_GetCreatedItemIndex,0x146D08A8+1
	defadr GUIonMessage_SetMenuItemText,0x143AA0F8+1
	defadr GUIonMessage_SetMenuItemIcon,0x1453AA4C+1

	defadr CreateListMenu,0x1466A3E4+1
	defadr ListMenu_SetOnMessage,0x146CF3F0+1
	defadr ListMenu_SetItemCount,0x1415F568+1
	defadr ListMenu_SetCursorToItem,0x1415F098+1
        defadr ListMenu_SetBackgroundImage,0x152BE0B0+1
        defadr ListMenu_GetSelectedItem,0x1462B788+1
        defadr ListMenu_DestroyItems,0x145BE1F0+1

	defadr GUIObject_Show,0x146CD3DC+1
        defadr GUIObject_Destroy,0x145A2A40+1
        defadr GUIObject_SetStyle,0x140E4654+1
        defadr GUIObject_SetTitleType,0x14061680+1
        defadr GUIObject_SetTitleText,0x14378258+1
        defadr GUIObject_SetSecondRowTitleText,0x1467D39C+1
	defadr GUIObject_TabTitleRemove,0x1400561C+1
	defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
	defadr GUIObject_SoftKeys_SetVisible,0x143B067C+1
	defadr GUIObject_SoftKeys_SetItemOnKey,0x14668620+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x15116508+1

	defadr TabMenuBar_SetTabGui,0x1410ADF0+1
	defadr TabMenuBar_SetTabTitle,0x143C26B8+1
        defadr TabMenuBar_GetFocusedTab,0x1410A998+1
        defadr TabMenuBar_SetOnTabSwitch,0x145F03F8+1

        defadr NewEvent_GetCount,0x1415ED30+1

        defadr pg_QuickAccess_Main__ExitEvent,0x15643D7C+1

//------------------------------------------------------------------------------

        ; EXTERN GetFocusedTab
        ; EXTERN CreateBookAndElfsLists
        ; EXTERN ActivityBook_onClose
        ; EXTERN EventsTitleText
        ; EXTERN CreateShortcutMenu
        ; EXTERN CreateElfMenu
        ; EXTERN CreateBookMenu

        ; RSEG   TAB_ICON_1
        ; CODE16
        ; ldr   r7, =_IconInternet
        ; bx    r7

        ; RSEG   TAB_ICON_2
        ; DATA
        ; DCD   0x82E

        ; RSEG   TAB_FOCUS_FIX
        ; CODE16
        ; NOP

        ; RSEG   INTERNET
        ; CODE16
        ; ldr   r3, =_Internet
        ; bx    r3

        ; RSEG   SHORTCURTS
        ; CODE16
        ; ldr   r3, =_Shortcurts
        ; bx    r3

        ; RSEG   CODE
        ; CODE16
; _IconInternet:
;         ldr   r1, =0x834
;         strh  r1, [r0,#8]
;         sub   r1, r1, #1
;         strh  r1, [r0,#0xA]
;         ldr   r1, =0xCEF
;         str   r1, [r0,#0xC]
;         pop   {r4,r5,pc}

//------------------------------------------------------------------------------

        ; RSEG   GUI_CREATE
        ; CODE16
        ; ldr     r3, =_onCreate
        ; bx      r3

        ; RSEG   BOOK_CLOSE
        ; CODE16
        ; ldr     r3, =_onClose
        ; bx      r3

        ; RSEG   TAB_FOCUS
        ; CODE16
        ; ldr   r3, =_Tabfocus
        ; bx    r3

        ; RSEG   ACTIVETASKS
        ; CODE16
        ; ldr   r3, =_Activetasks
        ; bx    r3

        ; RSEG   EVENTS
        ; CODE16
        ; ldr   r3, =EventsTitleText
        ; bx    r3

;         RSEG   CODE
;         CODE16
; _onCreate:
;         lsl     r0, r4, #0
;         bl      CreateBookAndElfsLists
;         ldr     r1, =0x145F0154+1
;         ldr     r0, [r4,#0x24]
;         bl      _SetOnTabSwitch
;         ldr     r3, =0x145F044C+1
;         bx      r3

; _SetOnTabSwitch:
;         ldr     r3, =TabMenuBar_SetOnTabSwitch
;         bx      r3

; _onClose:
;         bl      _func_unk1
;         LDR     R0, [R4,#0x64]
;         bl      _func_unk2
;         lsl     R0, R4, #0
;         bl      ActivityBook_onClose
;         pop     {R4-R6,PC}

; _func_unk1:
;         ldr     r3, =0x145F00F4+1
;         bx      r3

; _func_unk2:
;         ldr     r3, =0x140E1D20+1
;         bx      r3

; _Tabfocus:
;         bl      _get_tab
;         cmp     r0, #0
;         beq     set_focus
;         mov     r0, #1
;         ldr     r3, =0x145F06C8+1
;         bx      r3
; set_focus:
;         bl      GetFocusedTab
;         lsl     R6, R0, #0
;         ldr     r3, =0x145F06EA+1
;         bx      r3
; _get_tab:
;         ldr     r3, =0x147E9438+1
;         bx      r3

; _Activetasks:
;         lsl     R1, R6, #0        ; tab
;         lsl     R0, R4, #0        ; BOOK*
;         bl      CreateBookMenu
;         ldr     r3, =0x1410AA1E+1
;         bx      r3

; _Internet:
;         ADD   R1, R5, #0
;         ADD   R0, R4, #0
;         bl    CreateShortcutMenu
;         pop   {r4-r6,pc}

; _Shortcurts:
;         ADD   R1, R5, #0
;         ADD   R0, R4, #0
;         bl    CreateElfMenu
;         pop   {r4-r6,pc}
//------------------------------------------------------------------------------

        EXTERN CreateBookMenu
        EXTERN DestroyBookMenu
        EXTERN CreateBooksList

        RSEG    BM_ENTER
	DATA
        DCD     CreateBookMenu

        RSEG    BM_DESTROY
	DATA
        DCD     DestroyBookMenu

        RSEG   BM_CREATE
        CODE16
        ldr     r3, =_onCreate
        bx      r3

        RSEG   CODE
;         CODE16
_onCreate:
        bl      CreateBooksList
        mov     r0, #0
        str     r0, [r4,#0x18]
        ldr     r1, =0x15BE8654
        lsl     r0, r4, #0
        bl      _bookobj_gotopage
        POP     {R2-R6,PC}

_bookobj_gotopage:
        ldr     r3, =0x145A1C58+1
        bx      r3

        END
