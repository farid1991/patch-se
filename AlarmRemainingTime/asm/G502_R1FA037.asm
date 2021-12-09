//#ifdef G502_R1FA037
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr memalloc,0x1009ED08
        defadr memfree,0x1009ED30
        defadr snwprintf,0x105544CC+1
        defadr REQUEST_DATEANDTIME_GET,0x10EB0E84+1
        defadr datetime2unixtime,0x111E0800+1
        defadr unixtime2datetime,0x111E0914+1
        defadr TextID_Create,0x1168442C+1

        EXTERN  GetRemainingTimeID

        
        RSEG   ALARM_LIST
        CODE16
        mov r0,	r5
        add r0,	#0x50
        ldr r3,	=GetRemainingTimeID
        blx r3
        str r0,	[sp,#0xC]
        b	0x10F33D28+1
        
        RSEG   ALARM_STANDBY
        CODE16
        ldr	r3,	=alarm_standby
        bx	r3
        
        RSEG   CODE
        CODE16
alarm_standby:
        mov	r0, sp
        add	r0, sp, #0x14
        bl	GetRemainingTimeID
        ldr r3,	=0x1160F9F4+1
        bx	r3

        END