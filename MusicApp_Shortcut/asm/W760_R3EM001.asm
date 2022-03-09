//W760_R3EM001
//W980_R3EG004
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB01144
        defadr debug_printf,0x4BB3A365
        defadr snwprintf,0x10798B34+1
        defadr List_DestroyElements,0x11B56FA4+1
        defadr List_Destroy,0x11B56CB8+1
        defadr List_Create,0x11B56C90+1
        defadr List_Get,0x11B56EB0+1
        defadr List_InsertLast,0x11B56E0C+1
        defadr List_GetCount,0x11B56E84+1
        defadr _fopen,0x109F5840+1
        defadr fread,0x109F71D4+1
        defadr fclose,0x117A443C+1
        defadr fwrite,0x109F73A0+1
        defadr fstat,0x109F61A4+1
        defadr TextID_Create,0x10FFBF40+1
        defadr TextID_CreateIntegerID,0x10FFBD6C+1
        defadr OneOfMany_GetSelected,0x11B12D4C+1
        defadr CreateMessageBox,0x11AE85E0+1
        defadr BookObj_ReturnPage,0x10E89A74+1
        defadr ListMenu_DestroyItems,0x11B10C3C+1
        defadr FreeBook,0x10E8A22C+1
        defadr GUIonMessage_GetBook,0x11B11374+1
        defadr GUIonMessage_GetMsg,0x11B1136C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11B11390+1
        defadr GUIonMessage_SetMenuItemText,0x11B1139C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11B113CC+1
        defadr CreateOneOfMany,0x11B12B94+1
        defadr GUIObject_SetTitleText,0x10A6FF28+1
        defadr GUIObject_SetStyle,0x10A6FD6C+1
        defadr OneOfMany_SetChecked,0x11B12D3C+1
        defadr OneOfMany_SetItemCount,0x11B12D20+1
        defadr OneOfMany_SetOnMessage,0x11B12D68+1
        defadr GUIObject_Show,0x10A6FD14+1
        defadr GUIObject_Destroy,0x10A6FB20+1
        defadr ListMenu_GetSelectedItem,0x11B107D0+1
        defadr BookObj_CallPage,0x10E899F0+1
        defadr CreateListMenu,0x11B105D0+1
        defadr ListMenu_SetItemCount,0x11B107E4+1
        defadr ListMenu_SetItemStyle,0x11B10820+1
        defadr ListMenu_SetCursorToItem,0x11B107BC+1
        defadr ListMenu_SetHotkeyMode,0x11B10920+1
        defadr ListMenu_SetOnMessage,0x11B108F4+1
        defadr CreateBook,0x10E89BAC+1
        defadr GUIObject_GetDispObject,0x10A6FBAC+1
        defadr DispObject_SoftKeys_GetList,0x108ABBC0+1
        defadr BookObj_GotoPage,0x10E898BC+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10B90CAC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10B90C04+1
        defadr MediaPlayer_SoftKeys_SetText,0x10B90C4C+1
        defadr GUIObject_SoftKeys_SetAction,0x108AE74C+1
        defadr GUIObject_SoftKeys_SetText,0x108AE7C4+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x108AE8E8+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x108AEAE4+1
        defadr MusicApplication_CancelAction,0x10D23E10+1
        defadr MusicApplication_Keyboard,0x10D24134+1
        defadr MusicApplication_Minimise,0x10D23DDC+1

//------------------------------------------------------------------------------

        EXTERN Set_New_Keyboard
        EXTERN Set_New_SoftKeys

        RSEG    PATCH_MUSIC_SOFTKEYS
        CODE16
        ldr     R3, =PATCH_Music_Softkeys
        bx      R3

        RSEG  CODE
        CODE16
PATCH_Music_Softkeys:
        ldr     R0, [R4,#0x1C]
        bl      Set_New_SoftKeys
        ldr     R0, [R4,#0x1C]
        mov     R2, #7
        mov     R1, #0xF
        ldr     r3, =GUIObject_SoftKeys_SetItemAsSubItem
        blx     r3
        ldr     R3, =0x10D2341A+1
        bx      R3

//------------------------------------------------------------------------------

        RSEG    PATCH_MUSIC_KEYBOARD1
        DATA
        dcd     Set_New_Keyboard

        RSEG    PATCH_MUSIC_KEYBOARD2
        DATA
        dcd     Set_New_Keyboard

        END