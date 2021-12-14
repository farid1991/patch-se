//#U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr debug_printf,0x4FC00008
	defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
	defadr memset,0x140EA530
        defadr memcpy,0x1482A864
	defadr get_envp,0x102932CC+1
	defadr set_envp,0x102932E0+1

        defadr Timer_Set,0x1427A39C+1
        defadr Timer_ReSet,0x14279088+1
        defadr Timer_Kill,0x1427A258+1

        defadr TextID_Create,0x145382A0+1
        defadr REQUEST_DATEANDTIME_GET,0x14647928+1
        defadr REQUEST_TIMEFORMAT_GET,0x143C96D8+1

        defadr GUIObject_SetTitleText,0x14378258+1
        defadr GUIObject_SetStyle,0x140E4654+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_SoftKeys_SetText,0x14690210+1
        defadr GUIObject_SoftKeys_SetVisible,0x143B067C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143AFC70+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x15696220+1
        defadr GUIObject_Destroy,0x145A2A40+1
        defadr GUIObject_Show,0x146CD3DC+1
        defadr GUIInput_SetIcon,0x14001B68+1

        defadr CreateListMenu,0x1466A3E4+1
        defadr ListMenu_SetItemCount,0x1415F568+1
        defadr ListMenu_SetCursorToItem,0x1415F098+1
        defadr ListMenu_SetHotkeyMode,0x1467E490+1
        defadr ListMenu_SetTexts,0x1481E19C+1
        defadr ListMenu_GetSelectedItem,0x1462B788+1
        defadr ListMenu_SetOnMessage,0x146CF3F0+1

        defadr GUIonMessage_GetMsg,0x146D0C1C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x146D08A8+1
        defadr GUIonMessage_SetMenuItemText,0x143AA0F8+1

        defadr CreateTimeInput,0x158F86E0+1
        defadr TimeInput_GetTimeInt,0x151EF524+1
        defadr TimeInput_SetTime,0x158F8754+1 
        defadr TimeInput_SetEnableSec,0x158F8768+1
        defadr TIME_SWAP,0x156B2CA8+1

        defadr FindBook,0x143D9C00+1
        defadr IsMusicApplication_Book,0x1433799C+1
        defadr BookObj_CallPage,0x141046E8+1
        defadr BookObj_ReturnPage,0x14104918+1

        defadr SUB_EXECUTE_Get_FILEITEM,0x146D24D0+1
        defadr FILEITEM_GetPath,0x146D2464+1
        defadr FILEITEM_GetFname,0x146D27F0+1
        defadr FSX_MakeFullPath,0x141F4398+1
        defadr FSX_FreeFullPath,0x1415584C+1

        defadr CreateMessageBox,0x147AD51C+1

        defadr pg_MusicApplication_PreviousAction,0x155AD0EC+1
        defadr pg_MusicApplication_CancelAction,0x152C2890+1
        defadr pg_MusicApplication_ExitAction,0x151D3464+1

        defadr MusicApplication_PrevAction,0x155AD08C+1
        defadr MusicApplication_CancelAction,0x1530F414+1
        defadr MusicApplication_ExecuteSubroutine,0x155AE2A8+1
        
//------------------------------------------------------------------------------

        EXTERN Set_New_SoftKeys
        EXTERN Kill_Timer

        RSEG    PATCH_MUSIC_SOFTKEYS
        CODE16
        ldr     R3, =PATCH_Music_Softkeys
        bx      R3

        RSEG   PATCH_MUSIC_DESTROY
        CODE16
        ldr     R3, =PATCH_Music_Timer
        bx      R3

        RSEG  CODE
        CODE16
PATCH_Music_Timer:
        LDR     R0, [R0,#0]
        LDR     R1, [R0,#0x14]
        LSL     R0, R4, #0
        BLX     R1
        BL      Kill_Timer
        POP     {R3-R7,PC}

PATCH_Music_Softkeys:
        ldr     r2, =0x1678
        mov     R1, #6
        ldr     R0, [R4,#0x20]
        bl      _GUIObject_SoftKeys_SetText
        ldr     R0, [R4,#0x20]
        bl      Set_New_SoftKeys
        ldr     R3, =0x146586CC+1
        bx      R3

_GUIObject_SoftKeys_SetText:
        bx      pc
        CODE32
        ldr     pc, =GUIObject_SoftKeys_SetText

        END
