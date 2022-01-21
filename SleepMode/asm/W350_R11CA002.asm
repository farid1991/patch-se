//W350_R11CA002


defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr memset,0x20105B58
        defadr debug_printf,0x2086B1D0+1

        defadr current_process,0x20186DDC
        defadr get_bid,0x20186E14
        defadr set_envp,0x20144BD4+1
        defadr get_envp,0x20144BC0+1

        defadr snwprintf,0x20380BC4+1
        defadr _fopen,0x20C86CB4+1
        defadr fread,0x20C88340+1
        defadr fclose,0x20C880EC+1
        defadr fwrite,0x20C8850C+1
        defadr fstat,0x20C875A0+1
        defadr TextID_Create,0x210EBC80+1
        defadr TextID_Destroy,0x210EBF00+1
        defadr CreateMessageBox,0x21060634+1
        defadr GUIObject_SoftKeys_SetVisible,0x211209CC+1
        defadr GUIObject_GetBook,0x21103F4C+1

        defadr FindBook,0x21053808+1
        defadr IsScreenSaverBook,0x21132970+1
        defadr GUIObject_GetDispObject,0x21103F38+1
        defadr DispObject_InvalidateRect,0x210FA4F0+1

        defadr Timer_Set,0x21052104+1
        defadr Timer_ReSet,0x21052138+1
        defadr Timer_Kill,0x21052190+1

        defadr Display_GetWidth,0x211170B4+1
        defadr GetImageHeight,0x210FE238+1
        defadr REQUEST_DATEANDTIME_GET,0x20B54AE0+1
        defadr Time2ID,0x21051220+1
        defadr Date2ID,0x21051314+1
        defadr DATE_GetWeekDay,0x20DD61F4+1

        defadr SetFont,0x210FDBA0+1
        defadr DrawString,0x210FD128+1

        EXTERN  SetRefreshTimer
        EXTERN  KillRefreshTimer
        EXTERN  New_SleepMode_OnRedraw

        RSEG  CODE
        CODE16

SetTimer:
        LDR     R3, =0x21101608+1
        BLX	R3
        BL      SetRefreshTimer
	MOV	R0, #1
        POP	{R2-R7,PC}

        RSEG  CODE
        CODE16

KillTimer:
        LDR	R3, =TextID_Destroy
	BLX	R3
        BL      KillRefreshTimer
	POP	{R4-R6,PC}

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
