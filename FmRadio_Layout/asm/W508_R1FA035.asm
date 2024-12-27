//W508_R1FA035
#include "target.h"

defadr	MACRO	a,b
        PUBLIC	a
a       equ	b
        ENDM

        defadr memalloc,0x4BA30DE8
        defadr memfree,0x4BA30E10
        defadr memset,0x14C23C5C
        defadr debug_printf,0x14C39CD0
        defadr set_envp,0x101F3448+1
        defadr get_envp,0x101F3434+1
        defadr current_process,0x101EC87C
        defadr get_bid,0x101EC8B4
        defadr _fopen,0x1421A92C+1
        defadr fclose,0x1410E040+1
        defadr fread,0x14310608+1
        defadr fwrite,0x14572374+1
        defadr FSX_IsFileExists,0x144BFCC0+1
        defadr CreateBook,0x1446A50C+1
        defadr BookObj_GotoPage,0x14027124+1
        defadr BookObj_ReturnPage,0x14247260+1
        defadr FreeBook,0x14366418+1
        defadr FindBook,0x143111F8+1
        defadr IsFmRadioBook,0x143C6264+1
        defadr GUIObject_GetBook,0x1419E1BC+1
        defadr GUIObject_GetDispObject,0x14048B1C+1
        defadr GUIObject_SetTitleText,0x142E6810+1
        defadr GUIObject_SetTitleType,0x143BD238+1
        defadr GUIObject_Show,0x14469D18+1
        defadr GUIObject_Destroy,0x14221158+1
        defadr GUIonMessage_GetMsg,0x1412CC2C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CD24+1
        defadr GUIonMessage_SetMenuItemText,0x14540388+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453FA40+1
        defadr GUIonMessage_SetItemDisabled,0x14246CC4+1
        defadr CreateListMenu,0x142211A8+1
        defadr ListMenu_SetCursorToItem,0x14365EBC+1
        defadr ListMenu_SetItemCount,0x1421144C+1
        defadr ListMenu_GetSelectedItem,0x14542708+1
        defadr ListMenu_SetItemStyle,0x14365B90+1
        defadr ListMenu_SetOnMessage,0x143E9E50+1
        defadr ListMenu_SetItemSecondLineText,0x142E6374+1
        defadr ListMenu_DestroyItems,0x144318D0+1
        defadr CreateOneOfMany,0x141BD674+1
        defadr OneOfMany_SetItemCount,0x14F8421C+1
        defadr OneOfMany_SetChecked,0x142889B4+1
        defadr OneOfMany_SetTexts,0x141C1F1C+1
        defadr OneOfMany_GetSelected,0x1451EC9C+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E17C+1
        defadr GUIObject_SoftKeys_SetText,0x1412B034+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E1C8+1
        defadr GUIObject_SoftKeys_SetInfoText,0x143EB194+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EBD40+1
        defadr TextID_Create,0x14226B70+1
        defadr TextID_Destroy,0x142261D0+1
        defadr TextID_CreateIntegerID,0x1452561C+1
        defadr snwprintf,0x142C75F0+1
        defadr CreateMessageBox,0x14EBC290+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E40DE0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15092030+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14ED5D30+1
        defadr get_DisplayGC,0x14049D50+1
        defadr GC_GetRect,0x142E9A94+1
        defadr GC_GetXX,0x140EF134+1
        defadr GC_SetXX,0x1415CBC4+1
        defadr GC_GetPenColor,0x140FECE4+1
        defadr GC_SetPenColor,0x14049DB0+1
        defadr GC_DrawLine,0x1433B55C+1
        defadr BookObj_AddGUIObject,0x1422119C+1
        defadr DrawRect,0x141158F4+1
        defadr DispObject_InvalidateRect,0x1404A6A0+1
        defadr GUIObject_Create,0x14469D60+1
        defadr DispObject_GetGUI,0x140B8700+1
        defadr DISP_DESC_SetName,0x1430C188+1
        defadr DISP_DESC_SetSize,0x1430C184+1
        defadr DISP_DESC_SetOnCreate,0x1430C104+1
        defadr DISP_DESC_SetOnClose,0x1430C18C+1
        defadr DISP_DESC_SetOnRedraw,0x1430C180+1
        defadr DISP_DESC_SetOnKey,0x1430BC7C+1
        defadr Display_GetHeight,0x142E9D88+1
        defadr Display_GetWidth,0x142E9D78+1
        defadr CreateYesNoQuestion,0x143F2514+1
        defadr YesNoQuestion_SetDescriptionText,0x14074A00+1
        defadr YesNoQuestion_SetQuestionText,0x140749F0+1
        defadr YesNoQuestion_SetIcon,0x14EEF27C+1
        defadr CoCreateInstance,0x14150FB8+1
        defadr DisplayGC_AddRef,0x1419BDB8+1
        defadr TextObject_SetText,0x14225564+1
        defadr TextObject_SetFont,0x1419C6D0+1

        defadr FmRadio_SetActiveSoftKeys,0x15537238+1

        defadr FmRadio_Gui_OnCreate,0x15535318+1
        defadr FmRadio_Gui_OnClose,0x155353C8+1
        defadr FmRadio_Gui_OnRedraw,0x155355D8+1
        defadr FmRadio_Gui_OnKey,0x15535418+1
        defadr FmRadio_Gui_OnMethod0A,0x15535508+1

        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x15536E2C+1

//------------------------------------------------------------------------------

        EXTERN New_FmRadio_Gui_OnCreate
        EXTERN New_FmRadio_Gui_OnClose
        EXTERN New_FmRadio_Gui_OnRedraw
        EXTERN New_FmRadio_Gui_OnKey
        EXTERN FmRadio_NewSoftKeys
        EXTERN FmRadio_UpdateSoftKeys
        EXTERN DeleteData
        EXTERN New_FmRadio_Main__PAGE_ENTER_EVENT

        RSEG PATCH_FmRadio_OnCreate
        DATA
        DCD New_FmRadio_Gui_OnCreate

        RSEG PATCH_FmRadio_OnClose
        DATA
        DCD New_FmRadio_Gui_OnClose

        RSEG PATCH_FmRadio_OnRedraw
        DATA
        DCD New_FmRadio_Gui_OnRedraw

        RSEG PATCH_FmRadio_OnKey
        DATA
        DCD New_FmRadio_Gui_OnKey

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_DeleteData
        CODE16
        LDR	R3, =delete_data
        BX	R3

        RSEG  CODE
        CODE16
delete_data:
        CMP     R1, #0
        BEQ     cont_
        ADD     R0, R1, #0
        LDR     R1, [R1,#0]
        LDR     R1, [R1,#0xC]
        BLX     R1
        MOV     R0, #0
        STR     R0, [R4,#8]
cont_:
        BL      DeleteData
        POP     {R2-R7,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_NewSoftKeys
        CODE16
        LDR	R3, =new_softkeys
        BX	R3

        RSEG  CODE
        CODE16
new_softkeys:
        LDR     R2, =0x95A
        LDR     R0, [R4,#0x18]
        MOV     R1, #2
        LDR	R3, =GUIObject_SoftKeys_SetText
        BLX     R3
        LDR     R0, [R4,#0x18]
        BL      FmRadio_NewSoftKeys
        LDR	R3, =0x15537036+1
        BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_UpdateSoftKeys
        CODE16
        LDR	R3, =update_softkeys
        BX	R3

        RSEG  CODE
        CODE16
update_softkeys:
        LDR     R0, [R4,#0x18]
        ADD     R2, R5, #0
        MOV     R1, #3
        LDR	R3, =GUIObject_SoftKeys_SetVisible
        BLX	R3
        LDR     R0, [R4,#0x18]
        MOV     R1, #FMRADIO_ACTION_LAYOUT
        ADD     R2, R5, #0
        LDR	R3, =GUIObject_SoftKeys_SetVisible
        BLX	R3
        LDR	R3, =0x15537266+1
        BX	R3

        END
