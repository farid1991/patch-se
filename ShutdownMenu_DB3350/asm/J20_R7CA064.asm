//J20_R7CA064

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr snwprintf,0x145D8E20+1
        defadr DynamicMenu_CreateSetBook,0x14B11764+1
        defadr Create_KnobOption,0x14BF97B4+1
        defadr KnobOption_SetItemCount,0x14772030+1
        defadr KnobOption_SetCursor,0x14EA1E3C+1
        defadr KnobOption_SetTitleText,0x14EA1DF4+1
        defadr KnobOption_SetItems,0x14BF9794+1
        defadr KnobOption_GetSelectedItem,0x14B4CEA0+1
        defadr CreateYesNoQuestion,0x149B3D84+1
        defadr YesNoQuestion_SetQuestionText,0x149B3D64+1
        defadr YesNoQuestion_SetIcon,0x149B3C28+1
        defadr GUIObject_SoftKeys_Hide,0x1417E414+1
        defadr GUIObject_SoftKeys_SetAction,0x1456E1B4+1
        defadr GUIObject_Show,0x14181538+1
        defadr GUIObject_Destroy,0x145681C0+1
        defadr TextID_Create,0x145CC91C+1
        defadr GetFreeBytesOnHeap,0x4BC00500
        defadr REQUEST_SYSTEM_SHUTDOWN,0x147E9B78+1
        defadr REQUEST_SYSTEM_RESTART,0x153A803C+1
        defadr GetSilent,0x144EADAC+1
        defadr FlightMode_SetState,0x14B269C8+1
        defadr FlightMode_GetState,0x14097098+1
        defadr FreeBook,0x141800F0+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x148140F4+1
        defadr REQUEST_SETTING_SILENCE_SET,0x14A40230+1

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
