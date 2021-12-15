//U10_R1BA049
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr debug_printf,0x4FC00008
        defadr snwprintf,0x148298C8+1
        defadr List_DestroyElements,0x141F2D1C+1
        defadr List_Destroy,0x1427BA18+1
        defadr List_Create,0x1427B71C+1
        defadr List_Get,0x143D96FC+1
        defadr List_InsertLast,0x14278E50+1
        defadr List_GetCount,0x143D9C60+1
        defadr _fopen,0x146F6100+1
        defadr fread,0x141B4D98+1
        defadr fclose,0x14644828+1
        defadr memset,0x140EA530
        defadr fwrite,0x146F6F9C+1
        defadr fstat,0x141F353C+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x15116508+1
        defadr TextID_Create,0x145382A0+1
        defadr TextID_CreateIntegerID,0x14538140+1
        defadr TextID_GetString,0x142C005C+1
        defadr OneOfMany_GetSelected,0x1476B51C+1
        defadr GUIObject_Destroy,0x145A2A40+1
        defadr GUIonMessage_GetMsg,0x146D0C1C+1
        defadr GUIonMessage_GetBook,0x146D0DC4+1
        defadr GUIonMessage_GetCreatedItemIndex,0x146D08A8+1
        defadr GUIonMessage_SetMenuItemText,0x143AA0F8+1
        defadr CreateOneOfMany,0x1481B1E8+1
        defadr GUIObject_SetTitleText,0x14378258+1
        defadr OneOfMany_SetChecked,0x1481B084+1
        defadr OneOfMany_SetItemCount,0x1481B1B8+1
        defadr OneOfMany_SetOnMessage,0x1481B094+1
        defadr GUIObject_SetStyle,0x140E4654+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_Show,0x146CD3DC+1
        defadr ListMenu_GetSelectedItem,0x1462B788+1
        defadr FreeBook,0x141043A0+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141302AC+1
        defadr CreateListMenu,0x1466A3E4+1
        defadr ListMenu_SetItemCount,0x1415F568+1
        defadr ListMenu_SetItemStyle,0x1467E3BC+1
        defadr ListMenu_SetCursorToItem,0x1415F098+1
        defadr ListMenu_SetHotkeyMode,0x1467E490+1
        defadr ListMenu_SetOnMessage,0x146CF3F0+1
        defadr ListMenu_DestroyItems,0x145BE1F0+1
        defadr CreateBook,0x1416066C+1
        defadr GUIObject_GetDispObject,0x145F87F8+1
        defadr DispObject_SoftKeys_GetList,0x14278B1C+1
        defadr BookObj_GotoPage,0x145A1C58+1
        defadr BookObj_ReturnPage,0x14104918+1
        defadr BookObj_CallPage,0x141046E8+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143AFC70+1
        defadr GUIObject_SoftKeys_SetText,0x14690210+1
        defadr CreateMessageBox,0x147AD51C+1

        defadr MusicApplication_Keyboard,0x147B8D14+1
        defadr MusicApplication_Pause,0x150CF1EC+1
        defadr MusicApplication_FastForward,0x153ABA94+1
        defadr MusicApplication_Rewind,0x155ACFAC+1
        defadr MusicApplication_NextTrack,0x15137B30+1
        defadr MusicApplication_PreviousTrack,0x152FED58+1
        defadr MusicApplication_Minimise,0x15255068+1

//------------------------------------------------------------------------------

        EXTERN Set_New_Keyboard
        EXTERN Set_New_SoftKeys
        
        RSEG    PATCH_MUSIC_SOFTKEYS
        CODE16
        ldr	R3, =PATCH_Music_Softkeys
        bx	R3
        
        RSEG  CODE
        CODE16
PATCH_Music_Softkeys:
        ldr     R0, [R4,#0x20]
        bl      Set_New_SoftKeys
        ldr     R0, [R4,#0x20]
        mov     R2, #7
        mov     R1, #0xE
        bl      _GUIObject_SoftKeys_SetItemAsSubItem
        ldr     R3, =0x146586D6+1
        bx	R3
_GUIObject_SoftKeys_SetItemAsSubItem:
        bx      pc
        CODE32
        ldr     pc, =GUIObject_SoftKeys_SetItemAsSubItem
//------------------------------------------------------------------------------
        
        RSEG    PATCH_MUSIC_KEYBOARD
        DATA
        dcd     Set_New_Keyboard
;         CODE16
;         ldr	R3, =PATCH_Music_keyboard
;         bx	R3
        
;         RSEG  CODE
;         CODE16
; PATCH_Music_keyboard:
;         lsl    R5, R4, #0
;         ldr    R1, =0xFFFF
;         lsl    R3, R6, #0
;         mov    R2, #0
;         add    R5, #0x20

;         cmp	R3, #KEY_UP
;         beq	key_up_down
;         cmp	R3, #KEY_DOWN
;         beq	key_up_down
;         cmp	R3, #KEY_LEFT
;         beq	key_left
;         cmp	R3, #KEY_RIGHT
;         beq	key_right
        
;         cmp	R3, #KEY_DIGITAL_0
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_1
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_2
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_3
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_4
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_5
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_6
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_7
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_8
;         beq	set_new_kb
;         cmp	R3, #KEY_DIGITAL_9
;         beq	set_new_kb
;         B	nex

; key_left:
; 	ldr	R7, =0x147B8E5E+1
; 	bx	R7
        
; key_right:
; 	ldr	R7, =0x147B8E36+1
; 	bx	R7

; key_up_down:
; 	ldr	R3, =0x147B8D66+1
; 	bx	R3
        
; set_new_kb:
;         add     R1, R6, #0      // Key
;         ldr     R0, [R4,#0x20]  // GUI*
;         bl      Set_New_Keyboard
; nex:
;         ldr     R0, =0x14430234+1
;         bx      R0

        END
