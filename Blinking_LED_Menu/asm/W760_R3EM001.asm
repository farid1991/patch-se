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
        defadr current_process,0x1017CBFC
        defadr get_bid,0x1017CC34
        defadr fstat,0x109F61A4+1
        defadr _fopen,0x109F5840+1
        defadr fread,0x109F71D4+1
        defadr fclose,0x117A443C+1
        defadr fwrite,0x109F73A0+1
        defadr Battery_GetChargingState,0x10C8FB68+1
        defadr Illumination_LedID_SetLevel,0x10C6827C+1
        defadr Illumination_LedID_Off,0x10C6847C+1
        defadr Timer_Kill,0x10E86218+1
        defadr GUIObject_Destroy,0x10A6FB20+1
        defadr wtoi,0x10E85BEC+1
        defadr TextID_CreateIntegerID,0x10FFBD6C+1
        defadr ListMenu_SetItemSecondLineText,0x11B10B98+1
        defadr TextID_Create,0x10FFBF40+1
        defadr CreateStringInput,0x109342CC+1
        defadr StringInput_SetMode,0x10934B84+1
        defadr StringInput_SetMinLen,0x10934BEC+1
        defadr StringInput_SetMaxLen,0x10934C9C+1
        defadr StringInput_SetEnableEmptyText,0x10934D10+1
        defadr StringInput_SetText,0x10934DA0+1
        defadr StringInput_SetFixedText,0x10934CC8+1
        defadr StringInput_SetActionOK,0x10934BE0+1
        defadr StringInput_SetActionBack,0x10934BE4+1
        defadr GUIObject_Show,0x10A6FD14+1
        defadr CreateMessageBox,0x11AE85E0+1
        defadr ListMenu_GetSelectedItem,0x11B107D0+1
        defadr GUIonMessage_GetBook,0x11B11374+1
        defadr GUIonMessage_GetMsg,0x11B1136C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11B11390+1
        defadr GUIonMessage_SetMenuItemText,0x11B1139C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11B113CC+1
        defadr CreateListMenu,0x11B105D0+1
        defadr GUIObject_SetTitleIcon,0x10A6FF60+1
        defadr GUIObject_SetTitleType,0x10A6FF0C+1
        defadr GUIObject_SetTitleText,0x10A6FF28+1
        defadr GUIObject_SetStyle,0x10A6FD6C+1
        defadr ListMenu_SetItemStyle,0x11B10820+1
        defadr ListMenu_SetItemCount,0x11B107E4+1
        defadr ListMenu_SetOnMessage,0x11B108F4+1
        defadr ListMenu_SetCursorToItem,0x11B107BC+1
        defadr GUIObject_SoftKeys_SetAction,0x108AE74C+1
        defadr GUIObject_SoftKeys_SetText,0x108AE7C4+1
        defadr CreateBook,0x10E89BAC+1
        defadr BookObj_GotoPage,0x10E898BC+1
        defadr DynamicMenu_GetElementMsg,0x10E73B34+1
        defadr DynamicMenu_SetElement_SecondLineText,0x10E73AF4+1
        defadr Timer_ReSet,0x10E861C0+1
        defadr FreeBook,0x10E8A22C+1
        defadr TurnOff_Sleepmode,0x10985E40+1


        EXTERN Start_LED
        EXTERN Kill_LED

        RSEG PATCH_KILL_TIMER
        CODE16
        LDR     R3, =Kill_Timer
        BLX     R3

        RSEG  CODE
        CODE16
Kill_Timer:
        BL      Kill_LED
        LDR     R3, =TurnOff_Sleepmode
        BLX     R3
        ADD     R0, R4, #0
        LDR     R3, =FreeBook
        BLX     R3
        MOV     R0, #1
        POP     {R4-R7,PC}

        RSEG PATCH_START_TIMER
        CODE16
        LDR     R7, =Start_Timer
        BLX     R7

        RSEG  CODE
        CODE16
Start_Timer:
        ADD     R6, #0x14
        ADD     R0, R6, #0
        BL      sub_Timer_ReSet
        BL      Start_LED
        LDR     R7, =0x10C8F4DA+1
        BLX     R7

sub_Timer_ReSet:
        PUSH    {R3}
        LDR     R3, =Timer_ReSet
        MOV     R12, R3
        POP     {R3}
        BX      R12
        NOP

        END
