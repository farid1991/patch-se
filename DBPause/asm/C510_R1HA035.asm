//#ifdef C510_R1HA035
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr GUIObject_SoftKeys_SetVisible,0x141C4E24+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x1436542C+1
        defadr GUIObject_SoftKeys_SetAction_SetText,0x143AA4E8+1
        
        EXTERN ActionPause
        
        RSEG CODE
        CODE16
softkey_add:
        ldr r3, =0x631
        ldr r2, =ActionPause
        mov r1, #0xFF
        ldr r0, [r6,#0x14]
        bl  _GUIObject_SoftKeys_SetAction_SetText
        mov r2, #0
        mov r1, #0xFF
        ldr r0, [r6,#0x14]
        ldr r3, =GUIObject_SoftKeys_SetVisible
        blx r3
        ldr r3, =0xCC0
        ldr r2, =0x144C0684+1
        ldr r1, =0xFC0
        ldr r0, [r6,#0x14]
        bl _GUIObject_SoftKeys_SetAction_SetText
        ldr r3, =0x14CC0E2E+1
        bx r3
        
_GUIObject_SoftKeys_SetAction_SetText:
        bx pc
        CODE32
        ldr pc, =GUIObject_SoftKeys_SetAction_SetText
        
        RSEG SOFTKEY
        DATA
        dcd ActionPause
        dcd 0x1390
        
        RSEG SOFTKEY_ADD
        CODE16
        ldr r3, =softkey_add
        bx r3
        
        END