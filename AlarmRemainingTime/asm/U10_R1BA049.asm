//#ifdef U10_R1BA049
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr snwprintf,0x148298C8+1
        defadr REQUEST_DATEANDTIME_GET,0x14647928+1
        defadr datetime2unixtime,0x147F3594+1
        defadr unixtime2datetime,0x147F38D0+1
        defadr TextID_Create,0x145382A0+1

        EXTERN  GetRemainingTimeID
        
        RSEG   ALARM_LIST
        CODE16
        ldr     r3, =alarm_list
        bx      r3
        
        RSEG   ALARM_STANDBY
        CODE16
        ldr     r3, =alarm_standby
        bx      r3
        
        RSEG   CODE
        CODE16
alarm_standby:
        mov     r0, sp
        add     r0, sp, #0x10
        bl      GetRemainingTimeID
        ldr     r3, =0x145EF67C+1
        bx      r3

alarm_list:
        bl      GetRemainingTimeID
        str     r0, [SP,#0x1C]
        mov     r0, #1
        str     r0, [SP,#0x18]
        ldr     r3, =0x14130020+1
        bx      r3
        
        END
        