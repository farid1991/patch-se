//J20_R7CA064
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145D9ECC
        defadr debug_printf,0x4BC00008
        defadr snwprintf,0x145D8E20+1
        defadr List_DestroyElements,0x1456E73C+1
        defadr List_Destroy,0x1404FE2C+1
        defadr List_Create,0x142D7608+1
        defadr List_Get,0x1446CD44+1
        defadr List_InsertLast,0x1446C81C+1
        defadr List_GetCount,0x1446C708+1
        defadr _fopen,0x1420C904+1
        defadr fread,0x1429733C+1
        defadr fclose,0x1459B9F0+1
        defadr fwrite,0x142978D0+1
        defadr fstat,0x145CEE28+1
        defadr TextID_Create,0x145CC91C+1
        defadr TextID_CreateIntegerID,0x14283F10+1
        defadr TextID_GetString,0x145CBA98+1
        defadr GUIObject_Destroy,0x145681C0+1
        defadr GUIonMessage_GetMsg,0x14022620+1
        defadr GUIonMessage_GetBook,0x1437A1F0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x14022854+1
        defadr GUIonMessage_SetMenuItemText,0x14022B40+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1419AEF4+1
        defadr CreateOneOfMany,0x14CBC844+1
        defadr OneOfMany_GetSelected,0x148106C4+1
        defadr OneOfMany_SetChecked,0x14CBCA08+1
        defadr OneOfMany_SetItemCount,0x14CBC814+1
        defadr OneOfMany_SetOnMessage,0x14811614+1
        defadr GUIObject_SetStyle,0x143FFB48+1
        defadr GUIObject_Show,0x14181538+1
        defadr CreateListMenu,0x14180708+1
        defadr ListMenu_SetItemCount,0x140DBDF4+1
        defadr ListMenu_SetItemStyle,0x141829F0+1
        defadr ListMenu_SetCursorToItem,0x140033DC+1
        defadr ListMenu_SetHotkeyMode,0x14182AB0+1
        defadr ListMenu_SetOnMessage,0x143D5068+1
        defadr ListMenu_DestroyItems,0x14487868+1
        defadr ListMenu_GetSelectedItem,0x1437B204+1
        defadr GUIObject_SetTitleText,0x14054A00+1
        defadr GUIObject_GetDispObject,0x1446CF34+1
        defadr DispObject_SoftKeys_GetList,0x142D7908+1
        defadr CreateBook,0x1417FFAC+1
        defadr FreeBook,0x141800F0+1
        defadr BookObj_GotoPage,0x14051800+1
        defadr BookObj_ReturnPage,0x14235190+1
        defadr BookObj_CallPage,0x148FB4EC+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1456C844+1
        defadr GUIObject_SoftKeys_SetAction,0x1456E1B4+1
        defadr GUIObject_SoftKeys_SetText,0x1456D190+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x147871BC+1
        defadr CreateMessageBox,0x1490F1E8+1

        defadr MusicApplication_Keyboard,0x14AF56D8+1
        defadr MusicApplication_Minimise,0x14B07D18+1
        defadr MusicApplication_CancelAction,0x14AED838+1

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
        ldr     R3, =0x14A67952+1
        bx	R3

_GUIObject_SoftKeys_SetText:
        ldr     r3, =GUIObject_SoftKeys_SetText
        bx      r3

//------------------------------------------------------------------------------

        RSEG    PATCH_MUSIC_KEYBOARD
        DATA
        dcd     Set_New_Keyboard

        END
