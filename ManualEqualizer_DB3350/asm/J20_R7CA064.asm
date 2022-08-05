//J20_R7CA064

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr debug_printf,0x4BC00008
        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145D9ECC
        defadr CoCreateInstance,0x144FB65C+1
        defadr TextObject_SetText,0x14280D48+1
        defadr TextObject_SetFont,0x144BCE70+1
        defadr get_DisplayGC,0x142D60A8+1
        defadr DisplayGC_AddRef,0x1437CB6C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14815408+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x14D66FC0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14CA0FD0+1
        defadr FILEITEM_GetPath,0x140216D4+1
	defadr FILEITEM_GetFname,0x140217D0+1
        defadr FILEITEM_CreateCopy,0x14021144+1
        defadr FILEITEM_Destroy,0x14021C30+1
        defadr SUB_EXECUTE_Get_FILEITEM,0x1402170C+1
        defadr DataBrowser_ExecuteSubroutine,0x140217D4+1
        defadr FSX_MakeFullPath,0x145CE068+1
        defadr FSX_FreeFullPath,0x1411AFD8+1
        defadr FSX_IsFileExists,0x149CD5A8+1

        defadr GUIObject_Create,0x14180798+1
        defadr BookObj_AddGUIObject,0x1418078C+1
        defadr GUIObject_SetTitleType,0x14400FC0+1

        defadr DrawRect,0x141AB3D8+1
        defadr Display_GetWidth,0x144E6CD0+1
        defadr Display_GetHeight,0x144E6CE0+1

        defadr DISP_DESC_SetName,0x1449B4A0+1
        defadr DISP_DESC_SetSize,0x1449B49C+1
        defadr DISP_DESC_SetOnCreate,0x1449B514+1
        defadr DISP_DESC_SetOnClose,0x1449B4A4+1
        defadr DISP_DESC_SetOnRedraw,0x1449B498+1
        defadr DISP_DESC_SetOnLayout,0x1449B5EC+1
        defadr DISP_DESC_SetOnKey,0x1449B024+1

        defadr DispObject_GetGUI,0x14C069D4+1
        defadr GUIObject_GetBook,0x1446D188+1
        defadr DispObject_SetLayerColor,0x1457A1EC+1
        defadr DispObject_InvalidateRect,0x144E7D00+1

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
        defadr GUIObject_SoftKeys_RemoveBackground,0x144F0D88+1
        defadr CreateMessageBox,0x1490F1E8+1

        defadr pg_MusicApplication_PreviousEvent,0x14F6FB0C+1
        defadr pg_MusicApplication_CancelEvent,0x14F6FA24+1
        defadr pg_MusicApplication_ExitEvent,0x14AF5240+1
        defadr pg_MusicApplication_SendFile__0x189F,0x14F6FAD8+1

        defadr MusicApplication_PrevAction,0x14F704B0+1
        defadr MusicApplication_CancelAction,0x14AED838+1
        defadr MusicApplication_ExecuteSubroutine,0x14F70B18+1

        defadr MusicApplication_EnableEqualizer,0x147C20C4+1
        defadr MusicApplication_SetEqualizerGain,0x147C1FB8+1

//------------------------------------------------------------------------------

        EXTERN create_new_softkeys
        EXTERN GetEqualizerState
        EXTERN SetManualEQ
        EXTERN SetEqualizerState

        org     0x147C1CC4
        CODE16
        beq     0x147C1C4E
        
        org     0x147C1CC8
        CODE16
        beq     0x147C1C4E

        RSEG    PATCH_SET_EQ
        CODE16
        ldr     r3, =set_equalizer
	bx      r3

        RSEG    PATCH_EQ_SOFTKEYS
        CODE16
	ldr     r3, =add_softkeys
	bx      r3

        RSEG    PATCH_SET_EQGAIN
        CODE16
        push    {lr}
        ldr     r3,=New_SetEqualizerGain
        blx     r3
        pop     {pc}

        RSEG  CODE
        CODE16
set_equalizer:
        bl      SetEqualizerState
        add     r0, r4, #0
        bl      New_SetEqualizerGain
        pop     {r4-r6,PC}

New_SetEqualizerGain:
        push    {r4,lr}
        add     r4, r0, #0
        cmp     r0, #0
        beq     empty_book
        add     r0, r4, #0
        bl      _EnableEqualizer
        bl      GetEqualizerState
        cmp     r0, #0
        beq     eq_preset
        add     r0, r4, #0
        bl      SetManualEQ
        pop     {r4,pc}

eq_preset:
        add     R1, r4, #0
        add     R1, #0x70
        add     r0, r4, #0
        bl      _SetEqualizerGain
empty_book:
        pop     {r4,pc}

add_softkeys:
        ldr     r0, [r4,#0x20]
        bl      create_new_softkeys
        ldr     r0, [r4,#0x20]
        mov     r2, #0xA
        mov     r1, #0x8
        bl      _SetItemAsSubItem
        ldr     r3, =0x14A67A0A+1
        bx      r3

_EnableEqualizer:
        ldr     r3, =MusicApplication_EnableEqualizer
        bx      r3
_SetEqualizerGain:
        ldr     r3, =MusicApplication_SetEqualizerGain
        bx      r3
_SetItemAsSubItem:
        ldr     r3, =GUIObject_SoftKeys_SetItemAsSubItem
        bx      r3

        END
