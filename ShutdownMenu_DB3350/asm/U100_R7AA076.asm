//U100_R7AA076

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr snwprintf,0x147EBEBC+1
        defadr DynamicMenu_CreateSetBook,0x151D88C0+1
        defadr Create_KnobOption,0x1511AA04+1
        defadr KnobOption_SetItemCount,0x1511AA98+1
        defadr KnobOption_SetCursor,0x1511A940+1
        defadr KnobOption_SetTitleText,0x1511A8A4+1
        defadr KnobOption_SetItems,0x1511A854+1
        defadr KnobOption_GetSelectedItem,0x14FA23E4+1
        defadr GUIObject_SoftKeys_Hide,0x14639C18+1
        defadr GUIObject_SoftKeys_SetAction,0x14391FA8+1
        defadr GUIObject_Show,0x1469C1AC+1
        defadr GUIObject_Destroy,0x1457BDE8+1
        defadr TextID_Create,0x145128B0+1
        defadr GetFreeBytesOnHeap,0x4BC00500
        defadr REQUEST_SYSTEM_SHUTDOWN,0x104B8E54+1
        defadr REQUEST_SYSTEM_RESTART,0x104B8E74+1
        defadr GetSilent,0x146CC824+1
        defadr FlightMode_SetState,0x141686D8+1
        defadr FlightMode_GetState,0x1412D6A0+1
        defadr FreeBook,0x140FDE10+1

        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x14158B50+1
        defadr REQUEST_SETTING_SILENCE_SET,0x14FF4A38+1

        EXTERN CreateShutdownMenu

        RSEG    PATCH_NEW_SHUTDOWN
        CODE16
        LDR	R3, =new_key
        BX	R3

        RSEG  CODE
        CODE16
new_key:
        CMP     R6, #1
        BNE     exit
        BL      CreateShutdownMenu

exit:
	ADD     SP, #0x1C
        POP     {R4-R7,PC}

        END
