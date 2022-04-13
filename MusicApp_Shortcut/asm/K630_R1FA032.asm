//K630_R1FA032
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x10098358
        defadr memfree,0x10098380
        defadr memset,0x2A1C07A0
        defadr memcpy,0x100B83F4

        defadr fstat,0x10F85398+1
        defadr _fopen,0x10F84AA0+1
        defadr fread,0x10F861E4+1
        defadr fwrite,0x10F863B0+1
        defadr fclose,0x11542130+1

        defadr List_DestroyElements,0x113C08D8+1
        defadr List_Destroy,0x113C05EC+1
        defadr List_Create,0x113C05C4+1
        defadr List_Get,0x113C07E4+1
        defadr List_GetCount,0x113C07B8+1
        defadr List_InsertFirst,0x113C0738+1
        defadr List_InsertLast,0x113C0740+1

        defadr GUIObject_SoftKeys_SetEnable,0x116542CC+1
        defadr GUIObject_SoftKeys_SetText,0x116541DC+1
        defadr GUIObject_SoftKeys_SetAction,0x11654164+1
        defadr GUIObject_SoftKeys_SetVisible,0x11654260+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x11654300+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x11654510+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x115522D8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x11552230+1
        defadr MediaPlayer_SoftKeys_SetText,0x11552278+1

        defadr TextID_Create,0x11617FF0+1
        defadr TextID_CreateIntegerID,0x11617E30+1

        defadr CreateBook,0x1159763C+1
        defadr CreateMessageBox,0x1159D37C+1
        defadr BookObj_ReturnPage,0x1159751C+1
        defadr BookObj_GotoPage,0x115973B4+1
        defadr BookObj_CallPage,0x115974B4+1
        defadr FreeBook,0x11597C48+1

        defadr GUIonMessage_GetBook,0x115ECC28+1
        defadr GUIonMessage_GetMsg,0x115ECC20+1
        defadr GUIonMessage_GetCreatedItemIndex,0x115ECC44+1
        defadr GUIonMessage_SetMenuItemText,0x115ECC50+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x115ECC80+1

        defadr CreateOneOfMany,0x115EE27C+1
        defadr GUIObject_SetTitleText,0x1163AF2C+1
        defadr GUIObject_SetStyle,0x1163AA58+1
        defadr OneOfMany_GetSelected,0x115EE454+1
        defadr OneOfMany_SetChecked,0x115EE444+1
        defadr OneOfMany_SetItemCount,0x115EE428+1
        defadr OneOfMany_SetOnMessage,0x115EE470+1
        defadr GUIObject_Show,0x1163AA00+1
        defadr GUIObject_Destroy,0x1163A804+1
        
        defadr CreateListMenu,0x115EBF18+1
        defadr ListMenu_SetOnMessage,0x115EC258+1
        defadr ListMenu_SetItemCount,0x115EC148+1
        defadr ListMenu_SetCursorToItem,0x115EC120+1
        defadr ListMenu_SetNoItemText,0x115EC2D8+1
        defadr ListMenu_GetSelectedItem,0x115EC134+1
        defadr ListMenu_DestroyItems,0x115EC60C+1
        defadr ListMenu_SetItemStyle,0x115EC184+1
        defadr ListMenu_SetHotkeyMode,0x115EC284+1

        defadr GUIObject_GetDispObject,0x1163A874+1
        defadr DispObject_SoftKeys_GetList,0x116517D4+1

        defadr MusicApplication_Minimise,0x1154DD04+1
        defadr MusicApplication_CancelAction,0x1154DD30+1
        defadr MusicApplication_Keyboard,0x1154E028+1


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
        ldr     R3, =0x1154D52E+1
        bx      R3

//------------------------------------------------------------------------------

        RSEG    PATCH_MUSIC_KEYBOARD1
        DATA
        dcd     Set_New_Keyboard

        RSEG    PATCH_MUSIC_KEYBOARD2
        DATA
        dcd     Set_New_Keyboard

        END
