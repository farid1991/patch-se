//C510_R1HA035

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr memalloc,0x4BA32698
        defadr memfree,0x4BA326C0
        defadr snwprintf,0x143EEBC4+1
        defadr REQUEST_DATEANDTIME_GET,0x140C4E48+1
        defadr datetime2unixtime,0x140B6DF4+1
        defadr unixtime2datetime,0x144281A4+1
        defadr TextID_Create,0x141818E4+1

        
        RSEG   ALARM_LIST
        CODE16
        mov     r0, r5
        add     r0, #0x54
        ldr     r3, =GetRemainingTimeID
        blx     r3
        str     r0, [sp,#0xC]
        b       0x1517A71E+1
        
        RSEG   ALARM_STANDBY
        CODE16
        ldr     r3, =alarm_standby
        bx      r3
        
        RSEG   CODE
        CODE16
alarm_standby:
        mov     r0, sp
        add     r0, sp, #0xC
        bl      GetRemainingTimeID
        str     r0, [sp,#4]
        ldr     r3, =0x141ACA38+1
        bx      r3
       
        EXTERN  GetRemainingTimeID

        END
        