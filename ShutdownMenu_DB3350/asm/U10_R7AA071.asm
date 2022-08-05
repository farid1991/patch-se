//U10_R7AA071

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr snwprintf,0x1481CA0C+1
        defadr DynamicMenu_CreateSetBook,0x153EEA40+1

        defadr Create_KnobOption,0x15325FA4+1
        defadr KnobOption_SetItemCount,0x15326038+1
        defadr KnobOption_SetCursor,0x15325EE8+1
        defadr KnobOption_SetTitleText,0x15325E4C+1
        defadr KnobOption_SetItems,0x15325DF8+1
        defadr KnobOption_GetSelectedItem,0x151932F4+1

        ; defadr CreateYesNoQuestion,+1
        ; defadr YesNoQuestion_SetQuestionText,+1
        ; defadr YesNoQuestion_SetIcon,+1

        defadr GUIObject_SoftKeys_Hide,0x14661398+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_Show,0x146C5748+1
        defadr GUIObject_Destroy,0x1459AF78+1

        defadr TextID_Create,0x14530A4C+1
        defadr GetFreeBytesOnHeap,0x4FC00500
        defadr REQUEST_SYSTEM_SHUTDOWN,0x1520A354+1
        defadr REQUEST_SYSTEM_RESTART,0x150B9A64+1
        defadr GetSilent,0x146F6000+1
        defadr FlightMode_SetState,0x1416EBB8+1
        defadr FlightMode_GetState,0x14131814+1
        defadr FreeBook,0x141016DC+1

        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x1415EC78+1
        defadr REQUEST_SETTING_SILENCE_SET,0x151EE18C+1

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
