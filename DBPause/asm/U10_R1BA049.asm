//U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr GUIObject_SoftKeys_SetVisible,0x143B067C+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x147363F4+1
        defadr GUIObject_SoftKeys_SetAction_SetText,0x15696220+1
        
        EXTERN ActionPause
        
        RSEG CODE
        CODE16
softkey_add:
        ldr     r3, =0xEDA
        ldr     r2, =ActionPause
        mov     r1, #0xFF
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetAction_SetText
        mov     r2, #0
        mov     r1, #0xFF
        ldr     r0, [r4,#0x14]
        ldr     r3, =GUIObject_SoftKeys_SetVisible
        blx     r3
        ldr     r3, =0xF0F
        ldr     r2, =0x153E8BEC+1
        ldr     r1, =0xFC0
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetAction_SetText
        ldr     r3, =0x150E80BA+1
        bx      r3
        
_GUIObject_SoftKeys_SetAction_SetText:
        bx      pc
        CODE32
        ldr     pc, =GUIObject_SoftKeys_SetAction_SetText

        RSEG SOFTKEY_FIX
        CODE16
        ldr     R0, [R4,#0x14]
        sub     R2, #0xDF
        
        RSEG SOFTKEY
        DATA
        dcd     ActionPause
        
        RSEG SOFTKEY_ADD
        CODE16
        ldr     r3, =softkey_add
        bx      r3
        
        END