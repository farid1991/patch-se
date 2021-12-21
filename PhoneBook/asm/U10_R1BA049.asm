//U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr AB_GETNBROFITEMS,0x1415E484+1
        defadr snwprintf,0x148298C8+1
        defadr GUIObject_SetTitleType,0x14061680+1
        defadr GUIObject_SetTitleText,0x14378258+1
        defadr TextID_Create,0x145382A0+1
        defadr GUIObject_SetSecondRowTitleText,0x1467D39C+1
        defadr GUIObject_SetTitleIcon,0x1467D168+1
        
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
        ldr     r3, =0x14016240+1
        bx      r3
        
set_title_2:
        ldr     r1, [SP,#0x24]
        bl      TitleText
        ldr     r3, =0x152F5696+1
        bx      r3
        
        END