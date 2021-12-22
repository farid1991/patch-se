//U10_R7AA071

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr BrowserItem_Get_SUB_EXECUTE,0x1472A798+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1
        defadr GUIObject_SoftKeys_SetVisible,0x143A94C0+1
        
        EXTERN ActionPause

        RSEG CODE
        CODE16
softkey_add:
        ldr     r2, =ActionPause
        mov     r1, #0xFF
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetAction
        ldr     r2, =0xED9
        mov     r1, #0xFF
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetText
        mov     r2, #0
        mov     r1, #0xFF
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetVisible

        ldr     r2, =0x15408BE8+1
        ldr     r1, =0xFC0
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetAction
        ldr     r2, =0xF13
        ldr     r1, =0xFC0
        ldr     r0, [r4,#0x14]
        bl      _GUIObject_SoftKeys_SetText

        ldr     r3, =0x15109836+1
        bx      r3
        
_GUIObject_SoftKeys_SetAction:
        ldr     r3, =GUIObject_SoftKeys_SetAction
        bx      r3
_GUIObject_SoftKeys_SetText:
        ldr     r3, =GUIObject_SoftKeys_SetText
        bx      r3
_GUIObject_SoftKeys_SetVisible:
        ldr     r3, =GUIObject_SoftKeys_SetVisible
        bx      r3

        RSEG SOFTKEY_FIX_PAUSE
        CODE16
        ldr     R0, [R4,#0x14]
        sub     R2, #0xDB
        
        RSEG SOFTKEY
        DATA
        dcd     ActionPause
        
        RSEG SOFTKEY_ADD
        CODE16
        ldr     r3, =softkey_add
        bx      r3

        END