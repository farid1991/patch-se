//W350_R11CA002


defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr memset,0x20105B58
        defadr debug_printf,0x2086B1D0+1
        defadr _fopen,0x20C86CB4+1
        defadr fread,0x20C88340+1
        defadr fclose,0x20C880EC+1
        defadr fwrite,0x20C8850C+1
        defadr fstat,0x20C875A0+1

        defadr TextID_Create,0x210EBC80+1

        defadr CreateListMenu,0x210C2F7C+1
        defadr ListMenu_SetOnMessage,0x210C32BC+1
        defadr ListMenu_SetItemCount,0x210C3190+1
        defadr ListMenu_SetCursorToItem,0x210C3168+1
        defadr ListMenu_GetSelectedItem,0x210C317C+1
        defadr ListMenu_SetItemTextScroll,0x210C38F0+1
        defadr ListMenu_SetItemStyle,0x210C31CC+1
        defadr ListMenu_SetHotkeyMode,0x210C32E8+1
        defadr ListMenu_SetTexts,0x210C32C4+1

        defadr CreateOneOfMany,0x210C50EC+1
        defadr OneOfMany_GetSelected,0x210C52BC+1
        defadr OneOfMany_SetItemCount,0x210C5290+1
        defadr OneOfMany_SetTexts,0x210C52E0+1
        defadr OneOfMany_SetChecked,0x210C52AC+1
        defadr GUIObject_SetTitleText,0x21104674+1
        defadr GUIObject_SetStyle,0x21104188+1
        
        defadr GUIObject_Show,0x21104138+1
        defadr GUIObject_Destroy,0x21103ECC+1

        defadr UI_Event,0x21053B9C+1
        defadr Shortcut_Run,0x2112DDE8+1

        defadr CreateBook,0x2105506C+1
        defadr FreeBook,0x2105566C+1
        defadr BookObj_GotoPage,0x21054DE8+1

        defadr IsAudioPlayerBook,0x20D2E30C+1
        defadr FindBook,0x21053808+1
        defadr IsScreenSaverBook,0x21132970+1
        defadr MainDisplay_GetTopBook,0x210548A4+1
        defadr MediaPlayer_Audio_Minimize,0x20D30A68+1

        defadr Create_QuickAccessBook,0x2108203C+1
        defadr Create_RightNowBook,0x21129B10+1

        defadr GUIObject_SoftKeys_SetAction,0x21120904+1
        defadr GUIObject_SoftKeys_SetText,0x2112097C+1

        EXTERN  LinkEditor
        EXTERN  New_OnOffKey_Short_Pressed
        EXTERN  New_OnOffKey_Long_Pressed

        ORG     0x21129B22      ; Fix ActivityMenu
        CODE16
	BEQ     0x21129B34      ; RightNowBook Not Exist => Create One
	BL      0x2105566C      ; RightNowBook Exist => Free RightNowBook
	B       0x21129B30      ; Exit

        RSEG    PATCH_WALKMANKEY1
        CODE16
	NOP
        
        RSEG    PATCH_WALKMANKEY2(1)
        CODE16
	MOV	R0, #0x1E

        RSEG    PATCH_WALKMANKEY3
        CODE16
	NOP

        RSEG    PATCH_WALKMANKEY4(1)
        CODE16
	MOV	R0, #0x1D

        RSEG    PATCH_ONOFFKEY
        DATA
	DCD     New_OnOffKey_Long_Pressed

        RSEG    PATCH_QUICKACCESS
        CODE16
        LDR     R3, =_quickaccess
        BX	R3

        RSEG    PATCH_SC_SOFTKEYS
        CODE16
        LDR     R3, =_softkeys
        BX	R3

        RSEG  CODE
        CODE16
_quickaccess:
        BNE     _exit
        BL      New_OnOffKey_Short_Pressed
_exit:
        MOV     R0, #1
        POP     {PC}

_softkeys:
        LDR     R2, =0x1A80
        MOV     R1, #0x21
        LDR     R0, [R6,#4]
        LDR     R3, =GUIObject_SoftKeys_SetText
        BLX     R3
        LDR     R2, =LinkEditor
        MOV     R1, #0x24
        LDR     R0, [R6,#4]
        LDR     R3, =GUIObject_SoftKeys_SetAction
        BLX     R3
        LDR     R2, =0xED4
        MOV     R1, #0x24
        LDR     R0, [R6,#4]
        LDR     R3, =GUIObject_SoftKeys_SetText
        BLX     R3
        LDR     R3, =0x2112E978+1
        BX	R3

        END
