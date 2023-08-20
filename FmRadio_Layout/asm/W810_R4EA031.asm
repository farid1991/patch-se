//W810_R4EA031

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x45453AA8+1
        defadr memfree,0x454547E0+1
        defadr memset,0x44E24360+1
        defadr debug_printf,0x44C9E13C+1
        defadr set_envp,0x44149D0A+1
        defadr get_envp,0x44149CF6+1
        defadr current_process,0x4418D8F0
        defadr get_bid,0x4418D928
        defadr snwprintf,0x44E25568+1
        defadr sscanf,0x44147BAC+1
        defadr _fopen,0x455B4268+1
        defadr fread,0x455B5700+1
        defadr fclose,0x455B54A0+1
        defadr fwrite,0x455B58E4+1
        defadr fstat,0x455B4ADC+1
        defadr lseek,0x455B5AA8+1
        defadr FileDelete,0x455B4BF4+1
        defadr w_diropen,0x455E5DC0+1
        defadr w_chdir,0x455E40A4+1
        defadr w_dirread,0x4510AA68+1
        defadr w_fstat,0x44B24B64+1
        defadr w_dirclose,0x455E603C+1
        defadr wstrlen,0x44FE9B2C+1
        defadr wstrcmpi,0x44FEAFB4+1
        defadr wstrrchr,0x44E25D38+1
        defadr strncmp,0x44E2538C+1
        defadr strcmp,0x44E252EC+1
        defadr wstrcpy,0x44E25C34+1
        defadr wstrcat,0x44E25BD4+1
        defadr Format_Time,0x454396B0+1
        defadr TextIteratorSetTextId,0x452FE434+1
        defadr TextID_Create,0x452FE69C+1
        defadr TextID_CreateIntegerID,0x452FE300+1
        defadr TextID_CreateFromChar,0x452FE2F8+1
        defadr TextID_GetLength,0x452FE8FC+1
        defadr TextID_Destroy,0x452FE86C+1
        defadr TextID_GetString,0x452FF248+1
        defadr Disp_GetTextIDWidth,0x45308098+1
        defadr CreateMessageBox,0x45533CE0+1
        defadr FSX_IsFileExists,0x452510D8+1
        defadr Display_GetTopBook,0x4529F01C+1
        defadr GUIObject_GetDispObject,0x45193C40+1
        defadr DispObject_GetGUI,0x453024AC+1
        defadr GUIObject_GetBook,0x45193C54+1
        defadr DispObject_SoftKeys_GetList,0x45199EB4+1
        defadr GUIObject_SetAnimation,0x451533E0+1
        defadr CreateBook,0x4529F750+1
        defadr FreeBook,0x4529FC78+1
        defadr BookObj_GotoPage,0x4529F4CC+1
        defadr BookObj_CallPage,0x4529F5DC+1
        defadr BookObj_GetBookID,0x4529FD0C+1
        defadr DISP_DESC_SetName,0x45301D0C+1
        defadr DISP_DESC_SetSize,0x45301D1C+1
        defadr DISP_DESC_SetOnCreate,0x45301D20+1
        defadr DISP_DESC_SetOnClose,0x45301D24+1
        defadr DISP_DESC_SetOnRedraw,0x45301D28+1
        defadr DISP_DESC_SetOnKey,0x45301D30+1
        defadr GUIObject_Create,0x45193B18+1
        defadr BookObj_AddGUIObject,0x4529FA5C+1
        defadr GetImageHeight,0x45307FC0+1
        defadr GetImageWidth,0x45307FD8+1
        defadr get_DisplayGC,0x45191A98+1
        defadr GC_GetRect,0x451920AC+1
        defadr GC_GetXX,0x451923C0+1
        defadr GC_SetXX,0x451923B4+1
        defadr GC_GetPenColor,0x451922C0+1
        defadr GC_SetPenColor,0x45192280+1
        defadr GC_DrawLine,0x45192CD0+1
        defadr GC_PutChar,0x451925BC+1
        defadr SetFont,0x45307888+1
        defadr DrawString,0x45306D48+1
        defadr DrawRect,0x45306940+1
        defadr DrawObject,0x45306B64+1
        defadr DispObject_InvalidateRect,0x45302A70+1
        defadr DispObject_SetStyle,0x45306190+1
        defadr DispObject_GetStyle,0x453062BC+1
        defadr DispObject_SetLayerColor,0x453060C4+1
        defadr DispObject_WindowSetSize,0x4530476C+1
        defadr DispObject_SetBackgroundColor,0x4530EFFC+1
        defadr DispObject_SetListTextColor,0x452E66F4+1
        defadr DispObject_SetTitleText,0x45304A34+1
        defadr DispObject_SetTitleType,0x45304B98+1
        defadr DispObject_SetSecondRowTitleText,0x45304A8C+1
        defadr DispObject_ListMenu_GetItemCount,0x452DC0FC+1
        defadr DispObject_SetThemeImage,0x45305BE4+1
        defadr DispObject_SetBackgroundImage,0x452E669C+1
        defadr List_GetCount,0x4527F228+1
        defadr List_Get,0x4527F250+1
        defadr Display_GetWidth,0x45547984+1
        defadr Display_GetHeight,0x45547974+1
        defadr GetThemeColor,0x45532A30+1
        defadr ImageID_Get,0x45426B54+1
        defadr ImageID_Free,0x45426B44+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x455ADDD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x455ADE50+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x455ADEE4+1
        defadr GUIObject_SetStyle,0x45193EC4+1
        defadr GUIObject_SetListTextColor,0x45171F28+1
        defadr GUIObject_SetCursorImage,0x45171EF8+1
        defadr GUIObject_SetBackgroundImage,0x45171F08+1
        defadr GUIObject_SetTitleBackgroundImage,0x45171F18+1
        defadr GUIObject_SetTitleType,0x45193F58+1
        defadr GUIObject_SetTitleText,0x45193F7C+1
        defadr GUIObject_SetTitleTextAlign,0x45193FC8+1
        defadr GUIObject_SetSecondRowTitleText,0x45193F98+1
        defadr GUIObject_Show,0x45193E64+1
        defadr GUIObject_Destroy,0x45193BE4+1
        defadr GUIonMessage_GetMsg,0x45171378+1
        defadr GUIonMessage_GetCreatedItemIndex,0x451713A4+1
        defadr GUIonMessage_SetMenuItemText,0x451713B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x451713F4+1
        defadr GUIonMessage_SetItemDisabled,0x4517144C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x451713E4+1
        defadr CreateListMenu,0x45170674+1
        defadr ListMenu_SetItemStyle,0x451708E8+1
        defadr ListMenu_SetItemCount,0x4517089C+1
        defadr ListMenu_SetCursorToItem,0x45170870+1
        defadr ListMenu_SetOnMessage,0x451709D8+1
        defadr ListMenu_DestroyItems,0x45170F28+1
        defadr ListMenu_SetHotKeyMode,0x45170A04+1
        defadr ListMenu_SetItemSecondLineText,0x45170C98+1
        defadr ListMenu_GetSelectedItem,0x45170884+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x45219CDC+1
        defadr GUIObject_SoftKeys_SetAction,0x4519B824+1
        defadr GUIObject_SoftKeys_SetText,0x4519B90C+1
        defadr GUIObject_SoftKeys_SetVisible,0x4519B9A4+1
        defadr MediaPlayer_SoftKeys_Validate,0x45074F90+1
        defadr CreateOneOfMany,0x4517250C+1
        defadr OneOfMany_SetItemCount,0x451726A0+1
        defadr OneOfMany_SetChecked,0x451726C4+1
        defadr OneOfMany_SetTexts,0x451726F8+1
        defadr OneOfMany_GetSelected,0x451726D4+1
        defadr CreateYesNoQuestion,0x45196AF4+1
        defadr YesNoQuestion_SetDescriptionText,0x45196E7C+1
        defadr YesNoQuestion_SetQuestionText,0x45196E8C+1
        defadr YesNoQuestion_SetIcon,0x45196EA8+1

        defadr FmRadio_Gui_OnCreate,0x452764F8+1
        defadr FmRadio_Gui_OnClose,0x45276564+1
        defadr FmRadio_Gui_OnKey,0x4527657C+1
        defadr FmRadio_SetActiveSoftKeys,0x455FE454+1
        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x455FE0FC+1
        defadr pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT,0x455FE9FC+1

        EXTERN New_FmRadio_Gui_OnCreate
        EXTERN New_FmRadio_Gui_OnClose
        EXTERN New_FmRadio_Gui_OnRedraw
        EXTERN New_FmRadio_Gui_OnKey
        EXTERN New_FmRadio_Gui_OnConfig
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

        RSEG PATCH_FmRadio_OnConfig
        DATA
        DCD New_FmRadio_Gui_OnConfig

        RSEG PATCH_FmRadio_MainPage_Enter
        DATA
        DCD New_FmRadio_Main__PAGE_ENTER_EVENT

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_RemoveTitle
        CODE16
        NOP
        NOP
        NOP
        NOP

        RSEG PATCH_FmRadio_DeleteData
        CODE16
        LDR     R3, =delete_data
	BX      R3

        RSEG  CODE
        CODE16
delete_data:
        LDR     R3, =0x45532178+1
        BLX     R3
        BL      DeleteData
        POP     {R4-R6,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_NewSoftKeys
	CODE16
	LDR     R3, =new_softkeys
	BX      R3

        RSEG  CODE
        CODE16
new_softkeys:
        LDR     R1, =0xFAF
        LDR     R2, =0x455FEC48+1
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
        ADD     R2, R5, #0
        MOV     R1, #3
        LDR     R3, =GUIObject_SoftKeys_SetVisible
        BLX     R3
        LDR     R0, [R4,#0x18]
        ADD     R2, R5, #0
        MOV     R1, #0x1F
        LDR     R3, =GUIObject_SoftKeys_SetVisible
        BLX     R3
        LDR     R3, =0x455FE48C+1
        BX      R3

        END
