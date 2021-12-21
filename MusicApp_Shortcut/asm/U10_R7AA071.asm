//U10_R7AA071
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr memset,0x140E2D1C
        defadr debug_printf,0x4FC00008
        defadr snwprintf,0x1481CAFC+1
        defadr List_DestroyElements,0x141F01D8+1
        defadr List_Destroy,0x142754E4+1
        defadr List_Create,0x142751FC+1
        defadr List_Get,0x143D2790+1
        defadr List_InsertLast,0x1427292C+1
        defadr List_GetCount,0x143D2D10+1
        defadr _fopen,0x146EE4EC+1
        defadr fread,0x141B254C+1
        defadr fclose,0x1463D0D0+1
        defadr fwrite,0x146EF4A0+1
        defadr fstat,0x141F09F0+1
        defadr TextID_Create,0x14530A4C+1
        defadr TextID_CreateIntegerID,0x145308EC+1
        defadr TextID_GetString,0x142B98A0+1
        defadr GUIObject_Destroy,0x1459AF78+1
        defadr GUIonMessage_GetMsg,0x146C8FE8+1
        defadr GUIonMessage_GetBook,0x146C9190+1
        defadr GUIonMessage_GetCreatedItemIndex,0x146C8C18+1
        defadr GUIonMessage_SetMenuItemText,0x143A2F18+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1412D4D4+1
        defadr CreateOneOfMany,0x1480E308+1
        defadr OneOfMany_GetSelected,0x1475F954+1
        defadr OneOfMany_SetChecked,0x1480E1A4+1
        defadr OneOfMany_SetItemCount,0x1480E2D8+1
        defadr OneOfMany_SetOnMessage,0x1480E1B4+1
        defadr GUIObject_SetStyle,0x140E20C4+1
        defadr GUIObject_Show,0x146C5748+1
        defadr CreateListMenu,0x146628FC+1
        defadr ListMenu_SetItemCount,0x1415CAB0+1
        defadr ListMenu_SetItemStyle,0x146765A4+1
        defadr ListMenu_SetCursorToItem,0x1415C5E0+1
        defadr ListMenu_SetHotkeyMode,0x14676678+1
        defadr ListMenu_SetOnMessage,0x146C7760+1
        defadr ListMenu_DestroyItems,0x145B6598+1
        defadr ListMenu_GetSelectedItem,0x14623F80+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr GUIObject_GetDispObject,0x145F106C+1
        defadr DispObject_SoftKeys_GetList,0x142725F8+1
        defadr CreateBook,0x1415DBEC+1
        defadr FreeBook,0x141016DC+1
        defadr BookObj_GotoPage,0x1459A190+1
        defadr BookObj_ReturnPage,0x14101C54+1
        defadr BookObj_CallPage,0x14101A24+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143A8AB4+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x15137CBC+1
        defadr CreateMessageBox,0x147A0C28+1

        defadr MusicApplication_Keyboard,0x147AC474+1
        defadr MusicApplication_Minimise,0x1527575C+1

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
        ldr     R3, =0x14650FE2+1
        bx	R3
_GUIObject_SoftKeys_SetItemAsSubItem:
        ldr     r3, =GUIObject_SoftKeys_SetItemAsSubItem
        bx      r3
//------------------------------------------------------------------------------
        
        RSEG    PATCH_MUSIC_KEYBOARD
        DATA
        dcd     Set_New_Keyboard

        END
