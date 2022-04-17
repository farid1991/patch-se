//K600_R2BB001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20363C0C+1
        defadr memfree,0x20364D24+1
        defadr memset,0x20D66768+1
        defadr debug_printf,0x20D28E84+1

        defadr current_process,0x200A405C
        defadr get_bid,0x200A4094
        defadr set_envp,0x2006CF5E+1
        defadr get_envp,0x2006CF4A+1

        defadr snwprintf,0x20D67990+1
        defadr _fopen,0x204DBDF4+1
        defadr fread,0x204DD2F0+1
        defadr fclose,0x204DCFD4+1
        defadr fwrite,0x204DD58C+1
        defadr fstat,0x204DC6B4+1
        defadr TextID_Create,0x202CFF38+1
        defadr TextID_Destroy,0x202D0210+1
        defadr CreateMessageBox,0x20431AF0+1
        defadr GUIObject_SoftKeys_SetVisible,0x20753884+1
        defadr GUIObject_GetBook,0x20280EEC+1

        defadr FindBook,0x20425C9C+1
        defadr IsScreenSaverBook,0x20761A1C+1
        defadr GUIObject_GetDispObject,0x20280EC4+1
        defadr DispObject_InvalidateRect,0x202647D4+1
        defadr DispObject_SetBacklightMode,0x20267D8C+1

        defadr Timer_Set,0x2025C1A0+1
        defadr Timer_ReSet,0x2025C1D8+1
        defadr Timer_Kill,0x2025C228+1

        defadr Display_GetWidth,0x2042E154+1
        defadr GetImageHeight,0x20269660+1
        defadr REQUEST_DATEANDTIME_GET,0x204BD5DC+1
        defadr Time2ID,0x2074B830+1
        defadr Date2ID,0x2074B918+1
        defadr DATE_GetWeekDay,0x20223624+1

        defadr SetFont,0x20268F18+1
        defadr DrawString,0x202683C4+1

        EXTERN  SetRefreshTimer
        EXTERN  KillRefreshTimer
        EXTERN  New_SleepMode_OnRedraw

        RSEG  CODE
        CODE16

SetTimer:
        LDR     R3, =DispObject_SetBacklightMode
        BLX	R3
        ADD     R0, R4, #0
        BL      SetRefreshTimer
	MOV	R0, #1
        POP	{R4-R7,PC}

        RSEG  CODE
        CODE16

KillTimer:
        LDR	R3, =0x202651A8+1
	BLX	R3
        BL      KillRefreshTimer
	POP	{R4,R5,PC}

        RSEG    PATCH_TIMER_SET
        CODE16
        LDR     R3, =SetTimer
        BX	R3

        RSEG    PATCH_TIMER_KILL
        CODE16
        LDR     R3, =KillTimer
        BX	R3

        RSEG    PATCH_SLEEPMODE_ONREDRAW
        DATA
        DCD     New_SleepMode_OnRedraw

        END
