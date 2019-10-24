#ifdef K550_R8BA024

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr memalloc,0x44D28524+1
        defadr memfree,0x44D28550+1
        defadr TextID_Create,0x4530BA7C+1
        defadr snwprintf,0x4455C95C+1
        defadr REQUEST_DATEANDTIME_GET,0x44D2EAB0+1
        defadr datetime2unixtime,0x44FD7C40+1
        defadr unixtime2datetime,0x44FD7D54+1
        
        defadr backto_1,0x44DA0B54+1
        defadr backto_2,0x4528726A+1

        EXTERN  GetRemainingTimeID

        RSEG   ALARM_LIST
        CODE16
        mov	R0, r5
        add	R0, #0x54
        LDR	R3, =GetRemainingTimeID
        blx	r3
        str	r0, [sp,#0xC]
        B	backto_1
        
        RSEG   ALARM_STANDBY
        CODE16
        LDR	r3, =alarm_standby
        bx	r3
        
        RSEG   CODE
        CODE16
alarm_standby:
        MOV	R0, sp
        ADD	R0, sp, #0x14
        BL	GetRemainingTimeID
        STR	R0, [R5,#4]
        LDR	R3, =backto_2
        bx	R3
       

#endif
          END