//W200_R4HA014


defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x452C26B8+1
        defadr memfree,0x452C33EC+1
        defadr memset,0x44CA43B8+1
        defadr debug_printf,0x44C593F0+1
        defadr current_process,0x441841C8
        defadr get_bid,0x44184200
        defadr set_envp,0x44149F70+1
        defadr get_envp,0x44149F5C+1
        defadr snwprintf,0x44CA5594+1
        defadr _fopen,0x45426824+1
        defadr fstat,0x45427098+1
        defadr fread,0x45427CBC+1
        defadr fwrite,0x45427EA0+1
        defadr fclose,0x45427A5C+1
        defadr TextID_Create,0x451723F4+1
        defadr TextID_Copy,0x45172528+1
        defadr TextID_Destroy,0x451725C4+1
        defadr TextID_GetString,0x45172FA0+1
        defadr TextID_GetWString,0x45172774+1
        defadr CreateMessageBox,0x453A0850+1
        defadr GUIObject_GetBook,0x45003280+1
        defadr FindBook,0x4539DCD0+1
        defadr IsScreenSaverBook,0x44FD152C+1
        defadr GUIObject_GetDispObject,0x4500326C+1
        defadr DispObject_InvalidateRect,0x451767D4+1
        defadr Timer_Set,0x45112BA8+1
        defadr Timer_ReSet,0x45112BCC+1
        defadr Timer_Kill,0x45112BF8+1
        defadr Display_GetHeight,0x453B3164+1
        defadr Display_GetWidth,0x453B3174+1
        defadr GetImageHeight,0x4517BD14+1
        defadr GetImageWidth,0x4517BCFC+1
        defadr REQUEST_DATEANDTIME_GET,0x4540EB0C+1
        defadr Time2ID,0x44FC7F54+1
        defadr Date2ID,0x44FC803C+1
        defadr DATE_GetWeekDay,0x450E0CE4+1
        defadr SetFont,0x4517B5F8+1
        defadr DrawString,0x4517AAB8+1
        defadr get_DisplayGC,0x450010F0+1
        defadr GC_PutChar,0x45001C14+1
        defadr DispObject_SetBacklightMode,0x4517A41C+1
        defadr defpage,0x4511F644+1

        EXTERN  SetRefreshTimer
        EXTERN  KillRefreshTimer
        EXTERN  New_SleepMode_OnRedraw

        RSEG  CODE
        CODE16

SetTimer:
        ADD     R0, R4, #0
        LDR     R3, =DispObject_SetBacklightMode
        BLX	R3
        ADD     R0, R4, #0
        BL      SetRefreshTimer
	MOV	R0, #1
        POP	{R4-R7,PC}

        RSEG  CODE
        CODE16

KillTimer:
        LDR	R3, =TextID_Destroy
	BLX	R3
        LDR	R3, =0x45177318+1
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
