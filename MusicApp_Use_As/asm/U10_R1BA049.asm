//#ifdef U10_R1BA049
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr wstrlen,0x141B5400+1
        defadr FILEITEM_GetPath,0x146D2464+1
        defadr FILEITEM_GetFname,0x146D27F0+1

        defadr TextFeedbackWindow,0x140E4F18+1
        defadr Feedback_SetTextExtended,0x140DB89C+1
        defadr Feedback_CloseAction,0x140E4A18+1
        
        defadr CreateListMenu,0x1466A3E4+1
        defadr ListMenu_SetItemCount,0x1415F568+1
        defadr ListMenu_SetCursorToItem,0x1415F098+1
        defadr ListMenu_SetHotkeyMode,0x1467E490+1
        defadr ListMenu_SetTexts,0x1481E19C+1
        defadr ListMenu_GetSelectedItem,0x1462B788+1

        defadr GUIObject_SetTitleText,0x14378258+1
        defadr GUIObject_SetStyle,0x140E4654+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_SoftKeys_SetText,0x14690210+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143AFC70+1
        defadr GUIObject_Destroy,0x145A2A40+1
        defadr GUIObject_Show,0x146CD3DC+1

        defadr BookObj_CallPage,0x141046E8+1
        defadr BookObj_GetBookID,0x143D9B54+1
        defadr SUB_EXECUTE_Get_FILEITEM,0x146D24D0+1

        defadr Sound_Check,0x152A1420+1
        defadr Sound_SetRingsignal,0x1563DE7C+1
        defadr Sound_SetMessageAlert,0x1515DB98+1
        defadr Sound_SetAlarmsignal,0x154945E8+1
        defadr Media_AddToContact,0x152CF590+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x15982490+1

        defadr MediaPlayer_SoftKeys_SetText,0x146585A8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x146582F4+1

        defadr pg_MusicApplication_PreviousAction,0x155AD0EC+1
        defadr pg_MusicApplication_CancelAction,0x152C2890+1
        defadr pg_MusicApplication_ExitAction,0x151D3464+1

        defadr MusicApp_PrevAction,0x155AD08C+1
        defadr MusicApp_CancelAction,0x1530F414+1
        
//------------------------------------------------------------------------------

        EXTERN create_new_softkeys

        RSEG  CODE
        CODE16
add_softkeys:
        bl      create_new_softkeys
        mov     R2, #0xA
        mov     R1, #8
        ldr     R0, [R4,#0x20]
        bl      _GUIObject_SoftKeys_SetItemAsSubItem
        ldr     R3, =0x14658784+1
        bx      R3

_GUIObject_SoftKeys_SetItemAsSubItem:
        bx      pc
        CODE32
        ldr     pc, =GUIObject_SoftKeys_SetItemAsSubItem

        RSEG    PATCH_ADD_SOFTKEYS
        CODE16
	ldr     R3, =add_softkeys
	bx      R3

        END
