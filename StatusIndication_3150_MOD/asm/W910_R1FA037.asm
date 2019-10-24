#ifdef W910_R1FA037

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x1009840C
        defadr memfree,0x10098434
        defadr memset,0x2A1C07A0
        defadr memcpy,0x100B84A8
        defadr snwprintf,0x10510688+1
        defadr _fopen,0x10FB34C4+1
        defadr fclose,0x1157A048+1
        defadr fread,0x10FB4C08+1
        defadr fwrite,0x10FB4DD4+1
        defadr fstat,0x10FB3DBC+1
        defadr Timer_ReSet,0x115CF764+1
        defadr Timer_Set,0x115CF730+1
        defadr Timer_Kill,0x115CF7BC+1
        defadr CreateBook,0x115D2B70+1
        defadr BookObj_GotoPage,0x115D28E8+1
        defadr FreeBook,0x115D317C+1
        defadr FindBook,0x115D26C8+1
        defadr Find_StandbyBook,0x115DE66C+1
        defadr GUIObject_SetTitleText,0x11676618+1
        defadr GUIObject_Show,0x116760EC+1
        defadr ListMenu_SetCursorToItem,0x116278B4+1
        defadr GUIonMessage_GetCreatedItemIndex,0x116283D8+1
        defadr GUIonMessage_SetMenuItemText,0x116283E4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11628414+1
        defadr GUIonMessage_SetMenuItemInfoText,0x116283F4+1
        defadr ListMenu_GetSelectedItem,0x116278C8+1
        defadr ListMenu_SetItemStyle,0x11627918+1
        defadr isScreenSaverBook,0x116AD471
        defadr CreateStringInputVA,0x116055B4+1
        defadr CreateOneOfMany,0x11629A10+1
        defadr OneOfMany_SetItemCount,0x11629BBC+1
        defadr OneOfMany_SetChecked,0x11629BD8+1
        defadr OneOfMany_SetTexts,0x11629C0C+1
        defadr OneOfMany_GetSelected,0x11629BE8+1
        defadr GUIObject_SoftKeys_SetAction,0x1168F908+1
        defadr GUIObject_SoftKeys_SetText,0x1168F980+1
        defadr GUIObject_SoftKeys_SetVisible,0x1168FA04+1
        defadr wstrncpy,0x10FA499C+1
        defadr wstrlen,0x10FA4940+1
        defadr int2strID,0x116535C4+1
        defadr Str2ID,0x11653784+1
        defadr TextFree,0x11653A1C+1
        defadr GUIObject_GetDispObject,0x11675F60+1
        defadr List_Create,0x113F1718+1
        defadr List_Destroy,0x113F1740+1
        defadr List_InsertFirst,0x113F188C+1
        defadr REQUEST_DATEANDTIME_GET,0x10E89044+1
        defadr GetFreeBytesOnHeap,0x115DFE54+1
        defadr ListMenu_SetOnMessage,0x116279EC+1
        defadr List_RemoveAt,0x113F1818+1
        defadr List_IndexOf,0x113F184C+1
        defadr current_process,0x100ED80C
        defadr get_envp,0x100A3120+1
        defadr set_envp,0x100A3134+1
        defadr get_bid,0x100ED844
        defadr List_Find,0x113F19E8+1
        defadr List_Get,0x113F1938+1
        defadr wstrrchr,0x10FA5CC4+1
        defadr List_InsertLast,0x113F1894+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11772AE4+1
        defadr REQUEST_DATEFORMAT_GET,0x10E89224+1
        defadr REQUEST_TIMEFORMAT_GET,0x10E89344+1
        defadr Date2ID,0x115DC250+1
        defadr Time2ID,0x115DC16C+1
        defadr CreateListMenu,0x116276AC+1
        defadr ListMenu_SetItemCount,0x116278DC+1
        defadr GUIObject_Destroy,0x11675EF0+1
        defadr GetVolumeSize,0x10FB6598+1
        defadr GetBatteryState,0x105999F0+1
        defadr get_DisplayGC,0x1167362C+1
        defadr GC_GetRect,0x11673C74+1
        defadr GC_GetXX,0x11673F78+1
        defadr GC_SetXX,0x11673F6C+1
        defadr BookObj_AddGUIObject,0x115D2EC4+1
        defadr DrawRect,0x1166E6A0+1
        defadr DrawString,0x1166E9A0+1
        defadr DispObject_InvalidateRect,0x1166B7D0+1
        defadr GUIObject_Create,0x11675E00+1
        defadr SetFont,0x1166F558+1
        defadr StatusRow_p,0x2A27E3DC
        defadr SBY_GetMainInput,0x100A5400+1
        defadr Display_GetFocusedDispObject,0x1166B010+1
        defadr DISP_DESC_SetName,0x116666AC+1
        defadr DISP_DESC_SetSize,0x116666B0+1
        defadr DISP_DESC_SetOnCreate,0x116666B4+1
        defadr DISP_DESC_SetOnClose,0x116666B8+1
        defadr DISP_DESC_SetOnRedraw,0x116666BC+1
        defadr DISP_DESC_SetOnKey,0x116666C4+1
        defadr MessageBox,0x115D886C+1
        defadr GC_GetPenColor,0x11673E80+1
        defadr GC_SetPenColor,0x11673E44+1
        defadr GC_DrawLine,0x11674904+1
        defadr GUIObject_SetTitleType,0x116765FC+1
        defadr textidname2id,0x10E7FC48+1
        defadr Disp_GetStrIdHeight,0x1166FB38+1
        defadr GetImageHeight,0x1166FB38+1
        defadr DATE_GetWeekDay,0x111B84F0+1
        defadr DispObject_SoftKeys_Get,0x1168C2B0+1
        defadr ListMenu_SetSecondLineText,0x11627CC4+1
        defadr DispObject_GetWindowHeight,0x1166C98C+1
        defadr Disp_GetStrIdWidth,0x1166FBC0+1
        defadr ImageID_GetIndirect,0x10F9D9A8+1
        defadr List_Insert,0x113F1768+1
        defadr BookObj_GetDisplayOrientation,0x115D32C8+1
        defadr Display_GetTopBook,0x115D26E4+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x10E85ABC+1
        defadr Alarm_GetTIME,0x10E852C4+1
        defadr Alarm_GetWeekSettings,0x10E86254+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11772564+1
        defadr DispObject_Show,0x1166B508+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11772C10+1
        defadr GUIonMessage_GetMsg,0x116283B4+1
        defadr GUIonMessage_GetBook,0x116283BC+1
        defadr ListMenu_SetItemTextScroll,0x1162801C+1
        defadr ListMenu_DestroyItems,0x11627DA0+1

        defadr Settings_ShowNumber_Get,0x10F2574C+1
        defadr MainInput_Hide,0x1169C270+1
        defadr isAudioPlayerBook,0x11584528+1
        
        defadr CoCreateInstance,0x116D60EC+1
        defadr DisplayGC_AddRef,0x11673A68+1

        defadr hunt,0x100ED90C
        defadr alloc,0x100ED6F8
        defadr receive,0x100ED714
        defadr send,0x100ED704
        defadr free_buf,0x100ED724

//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x10F231EC+1
        defadr FlightGetState,    0x115DD414+1
        
        defadr CallInfo_Get,      0x10788EE4+1
        defadr isTimerBook,       0x10F12D40+1

        defadr some,              0x111B7B00+1
        defadr armfunc,           0x1050CDA0

        defadr Show,              0x115DF7B0+1
        defadr Return_Clear,      0x115DF7AA+1
        defadr Show_Clear,        0x115DF7D8+1

        defadr oldRedrawStatus,   0x11671334+1
        defadr oldRedrawDisplay,  0x11680C00+1
        defadr oldRedrawSoft,     0x1168E8F8+1
        defadr oldCreateDisplay,  0x11680B48+1
        defadr oldCloseDisplay,   0x11680BC8+1
        defadr oldOnKeyMainInput, 0x1169B198+1

        defadr retSetIcon,        0x116660B8+1

        EXTERN  onRedrawStatus
        EXTERN  onRedrawDisplay
        EXTERN  onRedrawSoft
        EXTERN  onCreateDisplay
        EXTERN  onCloseDisplay
        EXTERN  myOnKey
        EXTERN  RunTimer
        EXTERN  KillTimer
        EXTERN  MySetTrayIcon

        RSEG  CODE
        CODE16

_GetCurName:
        PUSH    {R1-R7,LR}
        LDR	R0, =Find_StandbyBook
        BLX	R0
        MOV	R4, R0
        LDR	R0, [R4,#0x3C]
        LDR	R3, =0x6FFFFFFF
        CMP	R0, R3
        BNE	exit
        LDR	R0, [R4,#0x54]
        CMP	R0, R3
        BEQ	searching
        MOV	R0, SP
        LDR	R5, =GetOperatorName
        BLX	R5
        B	exit

searching:
        LDR	R0, =0x17E7
        
exit:
        POP    {R1-R7,PC}

        RSEG  CODE
        CODE16

_GetTimerTime:
        PUSH    {R0-R7,LR}
        LDR	R0, =isTimerBook
        LDR	R3, =FindBook
        BLX     R3
        MOV	R4, R0
        LDR	R3, =some
        BLX	R3
        LDR	R1, [R4,#0x2C]
        SUB	R0, R0, R1
        LDR	R1, [R4,#0x28]
        CMP	R0, R1
        BCS	loc_64tor5
        SUB	R5, R1, R0
        B	after

loc_64tor5:
        MOV	R5, #0x64

after:
        LDR	R4, [SP,#0]
        LDR	R1, =0x36EE80
        MOV	R0, R5
        LDR	R3, =armfunc
        BLX	R3
        STRB	R1,[R4,#0]
        LDR	R1, =0xEA60
        LDR	R3, =armfunc
        BLX	R3
        STRB	R1, [R4,#1]
        LDR     R1, =0x3E8
        LDR	R3, =armfunc
        BLX	R3
        STRB	R1, [R4,#2]
        MOV	R0, #0
        STRB	R1, [R4,#3]
        POP    {R0-R7,PC}
        
        RSEG  CODE
        CODE16

CallClear:
        LDR     R0, =0x6FFFFFFF
        ADD     R5, R1, #0
        CMP     R1, R0
        BEQ     loc_45426AAA
        CMP     R2, #0
        BEQ     loc_452AE5A8
        LDR     R3, =Return_Clear
        BX      R3

loc_45426AAA:
        BL      KillTimer
        LDR     R3, =Show_Clear
        BX      R3

loc_452AE5A8:
        BL      RunTimer
        MOV     R0, SP
        LDR     R1, =0xF83C
        LDR     R3, =Show
        BX      R3

_mySetTrayIcon:
        PUSH    {R0,R1}
        LDR     R3, =MySetTrayIcon
        BLX     R3
        POP     {R0,R1}
        MOV     R2, #0
        MOV     R1, R0
        LDR     R0, =StatusRow_p
        LDR     R0, [R0,#0]
        LDR     R3, =retSetIcon
        BX      R3

_mySetTrayIcon_2:
        PUSH    {R0-R2}
        MOV     R1, R2
        LDR     R3, =MySetTrayIcon
        BLX     R3
        POP     {R0-R2}
        MOV     R2, #0
        MOV     R3, R1
        MOV     R1, R0
        LSL     R0, R3, #2
        LDR     R3, =StatusRow_p
        LDR     R0, [R3,R0]
        LDR     R3, =retSetIcon
        BX      R3
        
        RSEG    PATCH_DRAWSTATUS(2)
        DATA
        DCD     onRedrawStatus

        RSEG    PATCH_DRAWDISPLAY(2)
        DATA
        DCD     onRedrawDisplay

        RSEG    PATCH_DRAWSOFT(2)
        DATA
        DCD     onRedrawSoft

        RSEG    PATCH_CREATEDISPLAY(2)
        DATA
        DCD     onCreateDisplay

        RSEG    PATCH_CLOSEDISPLAY(2)
        DATA
        DCD     onCloseDisplay

        RSEG    PATCH_ONKEYMAININPUT(2)
        DATA
        DCD     myOnKey

        RSEG    PATCH_CALLOFF_CLEAR(2)
        CODE16
        LDR     R0, =CallClear
        BX	R0

        RSEG    PATCH_SET_TRAY_ICON(2)
        CODE16
        PUSH    {LR}
        LDR     R3, =_mySetTrayIcon
        BX      R3

        RSEG    PATCH_SET_TRAY_ICON_2(2)
        CODE16
        PUSH    {LR}
        LDR     R3, =_mySetTrayIcon_2
        BX      R3
        
#endif
          END
          