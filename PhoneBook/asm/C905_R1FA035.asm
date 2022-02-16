//C905_R1FA035

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr AB_GETNBROFITEMS,0x14275754+1
        defadr snwprintf,0x14B77F24+1
        defadr GUIObject_SetTitleText,0x1441DDB8+1
        defadr GUIObject_SetTitleType,0x14389EB4+1
        defadr TextID_Create,0x14100290+1
        defadr GUIObject_SetSecondRowTitleText,0x1441E754+1
        defadr GUIObject_SetTitleIcon,0x140DF918+1
        
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
        mov     r1, r6
        bl      TitleText
        ldr     r3, =0x14D6AF52+1
        bx      r3
        
set_title_2:
        mov     r1, r6
        bl      TitleText
        ldr     r3, =0x14D6B2A4+1
        bx      r3
        
        END
