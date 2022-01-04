//W980_R3EG004

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr debug_printf,0x4BB37FED
        defadr set_envp,0x10005AEC+1
        defadr get_envp,0x10005AD8+1
        defadr current_process,0x10173890
        defadr get_bid,0x101738C8
        defadr _fopen,0x10955B80+1
        defadr fwrite,0x1095763C+1
        defadr fclose,0x1170F520+1
        defadr fread,0x10957474+1
        defadr CoCreateInstance,0x1071C028+1
        defadr get_DisplayGC,0x109CE290+1
        defadr DisplayGC_AddRef,0x109CE6C8+1
        defadr DrawRect,0x109C9FB4+1
        defadr SetFont,0x109CAEC0+1
        defadr DrawString,0x109CA300+1
        defadr GetImageHeight_int,0x109CB5D4+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr ListMenu_DestroyItems,0x11A8D4C0+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr ListMenu_SetItemSecondLineText,0x11A8D41C+1
        defadr OneOfMany_GetSelected,0x11A8F5E4+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr TextID_Create,0x10F685C0+1
        defadr CreateOneOfMany,0x11A8F42C+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr OneOfMany_SetTexts,0x11A8F608+1
        defadr OneOfMany_SetChecked,0x11A8F5D4+1
        defadr GUIObject_Show,0x109D0434+1
        defadr TextID_Destroy,0x10F688FC+1
        defadr GC_GetRect,0x109CE8D4+1
        defadr GC_GetXX,0x109CEBD0+1
        defadr GC_SetXX,0x109CEBC4+1
        defadr snwprintf,0x106F71E4+1
        defadr GC_GetPenColor,0x109CEADC+1
        defadr GC_SetPenColor,0x109CEAA0+1
        defadr GC_DrawLine,0x109CF220+1
        defadr DispObject_InvalidateRect,0x109C6B64+1
        defadr DISP_DESC_SetName,0x109C35EC+1
        defadr DISP_DESC_SetSize,0x109C35F0+1
        defadr DISP_DESC_SetOnCreate,0x109C35F4+1
        defadr DISP_DESC_SetOnClose,0x109C35F8+1
        defadr DISP_DESC_SetOnRedraw,0x109C35FC+1
        defadr DISP_DESC_SetOnKey,0x109C3604+1
        defadr GUIObject_GetDispObject,0x109D02CC+1
        defadr GUIObject_Create,0x109D007C+1
        defadr BookObj_AddGUIObject,0x10DEFD64+1
        defadr GUIObject_SetTitleType,0x109D0640+1
        defadr FreeBook,0x10DF0054+1
        defadr TextID_CreateIntegerID,0x10F683EC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107A25F0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107A2668+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107A26F0+1
        defadr FSX_IsFileExists,0x11804158+1
        defadr DispObject_GetGUI,0x109C6448+1
        defadr GUIObject_GetBook,0x109D02E0+1
        defadr Display_GetWidth,0x1178CFD4+1
        defadr Display_GetHeight,0x1178CFC8+1
        defadr CreateMessageBox,0x11A64938+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetItemDisabled,0x11A8DCC8+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr CreateYesNoQuestion,0x1178C788+1
        defadr YesNoQuestion_SetDescriptionText,0x1178CAF0+1
        defadr YesNoQuestion_SetQuestionText,0x1178CAE0+1
        defadr YesNoQuestion_SetIcon,0x1178CB10+1
        defadr BookObj_ReturnPage,0x10DEF89C+1
        defadr CreateBook,0x10DEF9D4+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6A088+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D510+1

        defadr FmRadio_Gui_OnCreate,0x10FAAB04+1
        defadr FmRadio_Gui_OnClose,0x10FAABB8+1
        defadr FmRadio_Gui_OnKey,0x10FAABDC+1
        defadr FmRadio_SetActiveSoftKeys,0x10FAD6F8+1
        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x10FAD2E0+1
        defadr pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT,0x10FADEF0+1

        EXTERN New_FmRadio_Gui_OnCreate
        EXTERN New_FmRadio_Gui_OnClose
        EXTERN New_FmRadio_Gui_OnRedraw
        EXTERN New_FmRadio_Gui_OnKey
        EXTERN FmRadio_NewSoftKeys
        EXTERN DeleteData
        EXTERN New_FmRadio_Main__PAGE_ENTER_EVENT
        EXTERN New_FmRadio_Base__UI_FMRADIO_CREATED_EVENT

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

        ; RSEG PATCH_FmRadio_Created
        ; DATA
        ; DCD New_FmRadio_Base__UI_FMRADIO_CREATED_EVENT

        RSEG PATCH_FmRadio_MainPage_Enter
        DATA
        DCD New_FmRadio_Main__PAGE_ENTER_EVENT

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_DeleteData
        CODE16
        LDR     R3, =delete_data
	BX      R3

        RSEG  CODE
        CODE16
delete_data:
        LDR     R1, [R6,#0x1C]
        CMP     R1, #0
        BEQ     nex_
        ADD     R0, R1, #0
        LDR     R1, [R1,#0]
        LDR     R1, [R1,#0xC]
        BLX     R1
        MOV     R0, #0
        STR     R0, [R6,#0x1C]

nex_:
        BL      DeleteData
        POP     {R2-R7,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_NewSoftKeys
	CODE16
	LDR     R3, =new_softkeys
	BX      R3

        RSEG  CODE
        CODE16
new_softkeys:
        LDR     R1, =0xFAF
        LDR     R0, [R4,#0x18]
        LDR     R3, =GUIObject_SoftKeys_SetAction
        BLX     R3
        LDR     R0, [R4,#0x18]
        BL      FmRadio_NewSoftKeys
        POP     {R4-R7,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_UpdateSoftKeys
	CODE16
	LDR     R3, =update_softkeys
	BX      R3

        RSEG  CODE
        CODE16
update_softkeys:
        LDR     R0, [R4,#0x18]
        ADD     R2, R5, #0
        MOV     R1, #3
        LDR     R3, =GUIObject_SoftKeys_SetVisible
        BLX     R3
        LDR     R0, [R4,#0x18]
        ADD     R2, R5, #0
        MOV     R1, #0x1F
        LDR     R3, =GUIObject_SoftKeys_SetVisible
        BLX     R3
        LDR     R3, =0x10FAD726+1
        BX      R3

        END
