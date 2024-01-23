//J108_R7EA011
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145C5AE8
        defadr debug_printf,0x4BC00008
        defadr snwprintf,0x145C4A3C+1
        defadr List_DestroyElements,0x1455B378+1
        defadr List_Destroy,0x1404E52C+1
        defadr List_Create,0x142CE2E0+1
        defadr List_Get,0x1446064C+1
        defadr List_InsertLast,0x1446012C+1
        defadr List_GetCount,0x14460020+1
        defadr _fopen,0x142048D8+1
        defadr fread,0x1428EA7C+1
        defadr fclose,0x14587FC0+1
        defadr fwrite,0x1428F010+1
        defadr fstat,0x145BAB14+1
        defadr TextID_Create,0x145B8610+1
        defadr TextID_CreateIntegerID,0x1427B854+1
        defadr TextID_GetString,0x145B778C+1
        defadr GUIObject_Destroy,0x14554DF4+1
        defadr GUIonMessage_GetMsg,0x140222FC+1
        defadr GUIonMessage_GetBook,0x1436E40C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x14022530+1
        defadr GUIonMessage_SetMenuItemText,0x1402281C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x14193DF4+1
        defadr CreateOneOfMany,0x14C3144C+1
        defadr OneOfMany_GetSelected,0x147DDFDC+1
        defadr OneOfMany_SetChecked,0x14C31610+1
        defadr OneOfMany_SetItemCount,0x14C3141C+1
        defadr OneOfMany_SetOnMessage,0x147DEF24+1
        defadr GUIObject_SetStyle,0x143F35FC+1
        defadr GUIObject_Show,0x1417A694+1
        defadr CreateListMenu,0x14179864+1
        defadr ListMenu_SetItemCount,0x140D9A08+1
        defadr ListMenu_SetItemStyle,0x1417BB54+1
        defadr ListMenu_SetCursorToItem,0x140030F0+1
        defadr ListMenu_SetHotkeyMode,0x1417BC0C+1
        defadr ListMenu_SetOnMessage,0x143C8F80+1
        defadr ListMenu_DestroyItems,0x1447A20C+1
        defadr ListMenu_GetSelectedItem,0x1436F420+1
        defadr GUIObject_SetTitleText,0x14053100+1
        defadr GUIObject_GetDispObject,0x1446083C+1
        defadr DispObject_SoftKeys_GetList,0x142CE5E0+1
        defadr CreateBook,0x14179108+1
        defadr FreeBook,0x1417924C+1
        defadr BookObj_CallPage,0x148AFE08+1
        defadr BookObj_GotoPage,0x1404FF00+1
        defadr BookObj_ReturnPage,0x1422D034+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x14559478+1
        defadr GUIObject_SoftKeys_SetAction,0x1455ADF0+1
        defadr GUIObject_SoftKeys_SetText,0x14559DC4+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x147659CC+1
        defadr CreateMessageBox,0x148C315C+1

        defadr MusicApplication_Keyboard,0x14A8D758+1
        defadr MusicApplication_Minimise,0x14A9F36C+1
        defadr MusicApplication_CancelAction,0x14A862AC+1

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
        add     R2, #0xE
        mov     R1, #0x6
        bl      _GUIObject_SoftKeys_SetText
        ldr     R0, [R4,#0x20]
        bl      Set_New_SoftKeys
        ldr     R3, =0x14A075CA+1
        bx	R3
CODE32
_GUIObject_SoftKeys_SetText:
        ldr     r3, =GUIObject_SoftKeys_SetText
        bx      r3
        
//------------------------------------------------------------------------------

        RSEG    PATCH_MUSIC_KEYBOARD
        DATA
        DCD     Set_New_Keyboard

        END
