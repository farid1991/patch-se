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
        defadr CreateStringInputVA,0x10894B50+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr MessageBox,0x11A64894+1
        defadr CreateMessageBox,0x11A64938+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr GUIObject_SetTitleIcon,0x109D0694+1
        defadr GUIObject_SetTitleType,0x109D0640+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
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
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_Show,0x109D0434+1
        defadr CreateBook,0x10DEF9D4+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr DynamicMenu_GetElementMsg,0x10DD9918+1
        defadr DynamicMenu_SetElement_SecondLineText,0x10DD98D8+1
        defadr Timer_Kill,0x10DEC004+1
        defadr Timer_ReSet,0x10DEBFAC+1
        defadr TurnOff_Sleepmode,0x108E6410+1
        defadr FreeBook,0x10DF0054+1

        EXTERN Start_LED
        EXTERN Kill_LED

        RSEG PATCH_START_TIMER
        CODE16
        LDR     R3, =Start_Timer
        BLX     R3

        RSEG PATCH_KILL_TIMER
        CODE16
        LDR     R3, =Kill_Timer
        BLX     R3

        RSEG  CODE
        CODE16
Kill_Timer:
        LDR     R3, =TurnOff_Sleepmode
        BLX     R3
        BL      Kill_LED
        ADD     R0, R4, #0
        LDR     R3, =FreeBook
        BLX     R3
        MOV     R0, #1
        POP     {R4-R7,PC}

        RSEG  CODE
        CODE16
Start_Timer:
        ADD     R7, #0x14
        ADD     R0, R7, #0
        BL      sub_Timer_ReSet
        BL      Start_LED
        LDR     R7, =0x10BF23AA+1
        BLX     R7

sub_Timer_ReSet:                         
        PUSH    {R3}            
        LDR     R3, =Timer_ReSet
        MOV     R12, R3         
        POP     {R3}            
        BX      R12            
        NOP

        END
