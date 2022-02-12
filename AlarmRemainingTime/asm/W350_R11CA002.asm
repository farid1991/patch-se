//W350_R11CA002

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr snwprintf,0x20380BC4+1
        defadr REQUEST_DATEANDTIME_GET,0x20B54AE0+1
        defadr datetime2unixtime,0x20DD5EF8+1
        defadr unixtime2datetime,0x20DD600C+1
        defadr TextID_Create,0x210EBC80+1

        EXTERN  GetRemainingTimeID


        RSEG   ALARM_LIST
        CODE16
        mov     r0, r5
        add     r0, #0x54
        ldr     r3, =GetRemainingTimeID
        blx     r3
        str     r0, [sp,#0xC]
        b	0x20BC1F8C+1

        RSEG   ALARM_STANDBY
        CODE16
        ldr	r3, =alarm_standby
        bx	r3

        RSEG   CODE
        CODE16
alarm_standby:
        mov	r0, sp
        add	r0, sp, #0x14
        bl	GetRemainingTimeID
        ldr     r3,=0x21068B3C+1
        bx	r3

        END