//K800_R8BF003

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr memalloc,0x44E4FD44+1
        defadr memfree,0x44E4FD70+1
        defadr TextID_Create,0x45446A40+1
        defadr snwprintf,0x4467A85C+1
        defadr REQUEST_DATEANDTIME_GET,0x44E562D0+1
        defadr datetime2unixtime,0x4510FAD4+1
        defadr unixtime2datetime,0x4510FBE8+1

        EXTERN  GetRemainingTimeID
        
        RSEG   ALARM_LIST
        CODE16
        mov r0, r5
        add r0, #0x54
        ldr r3, =GetRemainingTimeID
        blx r3
        str r0, [sp,#0xC]
        b 0x44EC9A98+1
        
        RSEG   ALARM_STANDBY
        CODE16
        ldr r3, =alarm_standby
        bx r3
        
        RSEG   CODE
        CODE16
alarm_standby:
        mov r0, sp
        add r0, sp, #0x14
        bl GetRemainingTimeID
        str r0, [r5,#4]
        ldr r3, =0x453C21C6+1
        bx r3

        END