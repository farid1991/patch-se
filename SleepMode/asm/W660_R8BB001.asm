//W660_R8BB001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44E6C3FC+1
        defadr memfree,0x44E6C428+1
        defadr memset,0x441452B8
        defadr memcpy,0x443F42E8
        defadr get_envp,0x443E4720+1
        defadr set_envp,0x443E4734+1        
        defadr TextID_Destroy,0x4546E31C+1        
        defadr DispObject_InvalidateRect,0x45481BF8+1
        defadr Timer_ReSet,0x453D2BE8+1
        defadr Timer_Set,0x453D2BB4+1
        defadr Timer_Kill,0x453D2C40+1
        defadr SetFont,0x45485370+1
        defadr DrawString,0x45484914+1
        defadr Display_GetWidth,0x4549EB6C+1
        defadr Date2ID,0x453D1D68+1
        defadr Time2ID,0x453D1C90+1
        defadr DATE_GetWeekDay,0x4512DC2C+1
        defadr REQUEST_DATEANDTIME_GET,0x44E72988+1
        defadr GetImageWidth,0x454858E8+1
        defadr GetImageHeight,0x454858FC+1
        defadr get_DisplayGC,0x45489330+1
        defadr GC_PutChar,0x45489E08+1

        EXTERN  SetRefreshTimer
        EXTERN  KillRefreshTimer
        EXTERN  New_SleepMode_OnRedraw

        RSEG  CODE
        CODE16
SetTimer:
        LDR     R3, =0x45488CF8+1
        BLX	R3
        ADD     R0, R4, #0
        BL      SetRefreshTimer
        MOV     R0, #1
        POP     {R2-R7,PC}

KillTimer:
        LDR     R0, [R5, #0]
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
