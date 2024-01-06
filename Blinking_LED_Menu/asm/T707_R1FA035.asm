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
        defadr strlen,0x14CDE90C+1
        defadr strstr,0x141EA790+1
        defadr strcpy,0x14CDE8D8+1
        defadr str2wstr,0x1415FAD0+1
        defadr strcmp,0x14CDE8B0+1
        defadr strncmp,0x14336214+1
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
        defadr Battery_GetChargingState,0x142D9254+1
        defadr Illumination_LedID_SetLevel,0x145144E8+1
        defadr Illumination_LedID_Off,0x143A5488+1
        defadr TextID_Create,0x14225E0C+1
        defadr TextID_CreateIntegerID,0x14520FE0+1
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
        defadr ListMenu_SetItemSecondLineText,0x142E4E74+1
        defadr GUIonMessage_GetBook,0x1412C044+1
        defadr GUIonMessage_GetMsg,0x1412C238+1
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
        defadr Timer_Kill,0x142D99D4+1
        defadr Timer_ReSet,0x142D9A34+1
        defadr DynamicMenu_GetElementMsg,0x141532B4+1
        defadr DynamicMenu_SetElement_SecondLineText,0x1456914C+1

        EXTERN Start_LED
        EXTERN Kill_LED

	RSEG PATCH_START_TIMER(2)
        CODE16
        LDR 	R6, =Set_Orange_LED
        BLX 	R6

        RSEG PATCH_KILL_TIMER(2)
        CODE16
        LDR	R3, =Kill_Timer
        BLX	R3

        RSEG  CODE
        CODE16
Kill_Timer:
        BL 	Kill_LED
        BEQ 	BOOK_AlreadyFree
        ADD 	R0, R4, #0
        LDR     R3, =FreeBook
        BLX     R3
BOOK_AlreadyFree:
        MOV 	R0, #1
        POP 	{R4-R6,PC}

        RSEG  CODE
        CODE16
Set_Orange_LED:
        ADD 	R0, R4, #0
        BL 	_Timer_ReSet
        BL 	Start_LED
        ADD     SP, #8
        LDR 	R6, =0x141B575C+1
        BLX 	R6
_Timer_ReSet:
        PUSH    {R3}
        LDR     R3, = Timer_ReSet
        MOV     R12, R3
        POP     {R3}
        BX      R12
        NOP

        END
