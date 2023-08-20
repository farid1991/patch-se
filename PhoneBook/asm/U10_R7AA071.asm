//U10_R7AA071

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM

        defadr AB_GETNBROFITEMS,0x1415B974+1
        defadr snwprintf,0x1481CAFC+1
        defadr GUIObject_SetTitleType,0x140614F0+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr TextID_Create,0x14530A4C+1
        defadr GUIObject_SetSecondRowTitleText,0x14675584+1
        defadr GUIObject_SetTitleIcon,0x14675350+1

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
        ldr     r1, [R4,#0]
        bl      TitleText
        ldr     r3, =0x1401636E+1
        bx      r3

set_title_2:
        ldr     r1, [SP,#0x24]
        bl      TitleText
        ldr     r3, =0x15315CBC+1
        bx      r3

        END
