//J108_R7EA011

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr snwprintf,0x145C4A3C+1
        defadr DynamicMenu_CreateSetBook,0x14AA82C8+1
        defadr Create_KnobOption,0x14B76B50+1
        defadr KnobOption_SetItemCount,0x14751058+1
        defadr KnobOption_SetCursor,0x14E09C24+1
        defadr KnobOption_SetTitleText,0x14E09BDC+1
        defadr KnobOption_SetItems,0x14B76B30+1
        defadr KnobOption_GetSelectedItem,0x14ADD370+1
        defadr CreateYesNoQuestion,0x1495DA80+1
        defadr YesNoQuestion_SetQuestionText,0x1495DA60+1
        defadr YesNoQuestion_SetIcon,0x1495D924+1
        defadr GUIObject_SoftKeys_Hide,0x14177518+1
        defadr GUIObject_SoftKeys_SetAction,0x1455ADF0+1
        defadr GUIObject_Show,0x1417A694+1
        defadr GUIObject_Destroy,0x14554DF4+1
        defadr TextID_Create,0x145B8610+1
        defadr GetFreeBytesOnHeap,0x4BC00500
        defadr REQUEST_SYSTEM_SHUTDOWN,0x147BB85C+1
        defadr REQUEST_SYSTEM_RESTART,0x152ED4E4+1
        defadr GetSilent,0x144DA140+1
        defadr FlightMode_SetState,0x14AB9920+1
        defadr FlightMode_GetState,0x140954B0+1
        defadr FreeBook,0x1417924C+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x147E16AC+1
        defadr REQUEST_SETTING_SILENCE_SET,0x149E13F4+1

        EXTERN CreateShutdownMenu

        RSEG    PATCH_NEW_SHUTDOWN
        CODE16
        LDR	R3, =new_key
        BX	R3

        RSEG  CODE
        CODE16
new_key:
        CMP     R6, #1
        BNE     _exit
        BL      CreateShutdownMenu

_exit:
	ADD     SP, #0x24
        POP     {R4-R7,PC}

        END
