//W350_R11CA002

defadr  MACRO   a,b
        PUBLIC  a
        a equ   b
        ENDM

        defadr AB_GETNBROFITEMS,0x20BF1798+1
        defadr snwprintf,0x20380BC4+1
        defadr TextID_Create,0x210EBC80+1
        defadr GUIObject_SetTitleType,0x21104658+1
        defadr GUIObject_SetTitleText,0x21104674+1
        defadr GUIObject_SetSecondRowTitleText,0x21104690+1
        defadr GUIObject_SetTitleIcon,0x211046AC+1

        EXTERN TitleText

        RSEG TITLE_PHONE
        CODE16
        ldr     r3, =set_title_1
        bx      r3

        RSEG TITLE_SIM
        CODE16
        ldr     r3, =set_title_2
        bx      r3

        RSEG CODE
        CODE16
set_title_1:
        ADD     R1, R6, #0
        bl      TitleText
        ldr     r3, =0x20BEAC8C+1
        bx      r3

set_title_2:
        ADD     R1, R5, #0
        bl      TitleText
        ldr     r3, =0x20BEB7C0+1
        bx      r3

        END
