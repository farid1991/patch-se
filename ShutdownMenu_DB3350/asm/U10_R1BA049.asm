//U10_R1BA049

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr snwprintf,0x14829814+1
        defadr DynamicMenu_CreateSetBook,0x153CE9AC+1

        defadr Create_KnobOption,0x153058E0+1
        defadr KnobOption_SetItemCount,0x15305974+1
        defadr KnobOption_SetCursor,0x15305824+1
        defadr KnobOption_SetTitleText,0x15305788+1
        defadr KnobOption_SetItems,0x15305738+1
        defadr KnobOption_GetSelectedItem,0x15172234+1

        defadr CreateYesNoQuestion,0x140E5184+1
        defadr YesNoQuestion_SetQuestionText,0x145F5040+1
        defadr YesNoQuestion_SetIcon,0x144A9E0C+1

        defadr GUIObject_SoftKeys_Hide,0x14668E70+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_Show,0x146CD3DC+1
        defadr GUIObject_Destroy,0x145A2A40+1

        defadr TextID_Create,0x145382A0+1
        defadr GetFreeBytesOnHeap,0x4FC00500
        defadr Shutdown,0x104D1EBC+1
        defadr Restart,0x104D1ED8+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x140ED6FC+1
        defadr REQUEST_SYSTEM_RESTART,0x15098A6C+1
        defadr GetSilent,0x146FDBC4+1
        defadr FlightMode_SetState,0x14171764+1
        defadr FlightMode_GetState,0x141345E0+1
        defadr FreeBook,0x141043A0+1

        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x14161700+1
        defadr REQUEST_SETTING_SILENCE_SET,0x151CDD14+1

        ////////////////

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
	ADD     SP, #0x1C
        POP     {R4-R7,PC}

        END
