//W980_R3EG004
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr debug_printf,0x4BB37FED
        defadr snwprintf,0x106F71E4+1
        defadr List_DestroyElements,0x11AD3A1C+1
        defadr List_Destroy,0x11AD3730+1
        defadr List_Create,0x11AD3708+1
        defadr List_Get,0x11AD3928+1
        defadr List_InsertLast,0x11AD3884+1
        defadr List_GetCount,0x11AD38FC+1
        defadr _fopen,0x10955B80+1
        defadr fread,0x10957474+1
        defadr fclose,0x1170F520+1
        defadr fwrite,0x1095763C+1
        defadr fstat,0x109564E4+1
        defadr TextID_Create,0x10F685C0+1
        defadr TextID_CreateIntegerID,0x10F683EC+1
        defadr TextID_GetString,0x10F68CCC+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr CreateOneOfMany,0x11A8F42C+1
        defadr OneOfMany_GetSelected,0x11A8F5E4+1
        defadr OneOfMany_SetChecked,0x11A8F5D4+1
        defadr OneOfMany_SetItemCount,0x11A8F5B8+1
        defadr OneOfMany_SetOnMessage,0x11A8F600+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr GUIObject_Show,0x109D0434+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr ListMenu_SetHotkeyMode,0x11A8D1A4+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_DestroyItems,0x11A8D4C0+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_GetDispObject,0x109D02CC+1
        defadr DispObject_SoftKeys_GetList,0x1080A888+1
        defadr CreateBook,0x10DEF9D4+1
        defadr FreeBook,0x10DF0054+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr BookObj_ReturnPage,0x10DEF89C+1
        defadr BookObj_CallPage,0x10DEF818+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1080D5B0+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AF236C+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AF2324+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AF23CC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x1080D7AC+1
        defadr CreateMessageBox,0x11A64938+1

        defadr MusicApplication_Keyboard,0x10C87818+1
        defadr MusicApplication_Minimise,0x10C87484+1

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
        ldr     R3, =0x10C86A22+1
        bx      R3
        
//------------------------------------------------------------------------------
        
        RSEG    PATCH_MUSIC_KEYBOARD1
        DATA
        dcd     Set_New_Keyboard
        
        RSEG    PATCH_MUSIC_KEYBOARD2
        DATA
        dcd     Set_New_Keyboard

        END