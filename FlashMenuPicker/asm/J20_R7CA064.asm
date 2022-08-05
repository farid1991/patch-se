//J20_R7CA064

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
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
        defadr _fopen,0x1420C904+1
        defadr fread,0x1429733C+1
        defadr fclose,0x1459B9F0+1
        defadr fwrite,0x142978D0+1
        defadr fstat,0x145CEE28+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14815408+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x14D66FC0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14CA0FD0+1
        defadr Display_SetBrightness,0x148411CC+1
        defadr SaveBrightness,0x14FE954C+1
        defadr Display_GetBrightness,0x14B10980+1
        defadr DispObject_SetLayerColor,0x1457A1EC+1
        defadr DispObject_InvalidateRect,0x144E7D00+1
        defadr DISP_DESC_SetName,0x1449B4A0+1
        defadr DISP_DESC_SetSize,0x1449B49C+1
        defadr DISP_DESC_SetOnCreate,0x1449B514+1
        defadr DISP_DESC_SetOnClose,0x1449B4A4+1
        defadr DISP_DESC_SetOnRedraw,0x1449B498+1
        defadr DISP_DESC_SetOnLayout,0x1449B5EC+1
        defadr DISP_DESC_SetOnKey,0x1449B024+1
        defadr UI_Event,0x14023B9C+1
        defadr FreeBook,0x141800F0+1
        defadr GUIObject_Create,0x14180798+1
        defadr BookObj_AddGUIObject,0x1418078C+1
        defadr GUIObject_SetTitleType,0x14400FC0+1
        defadr GUIObject_SoftKeys_SetAction,0x1456E1B4+1
        defadr GUIObject_SoftKeys_SetText,0x1456D190+1
        defadr GUIObject_Show,0x14181538+1
        defadr snwprintf,0x145D8E20+1
        defadr sscanf,0x101A4BD0+1
        defadr TextID_Create,0x145CC91C+1
        defadr TextID_Destroy,0x145CBF78+1
        defadr TextID_CreateIntegerID,0x14283F10+1
        defadr DynamicMenu_SetElement_SecondLineText,0x14B10B88+1
        defadr Display_GetWidth,0x144E6CD0+1
        defadr Display_GetHeight,0x144E6CE0+1

        defadr set_envp,0x101A246C+1
        defadr get_envp,0x101A2458+1
        defadr w_fstat,0x1003093C+1
        defadr w_diropen,0x4BC00164
        defadr w_chdir,0x4BFB7180
        defadr w_dirread,0x14AD1464+1
        defadr w_dirclose,0x4BC001A4
        defadr wstrcmp,0x14296A60+1
        defadr wstrlen,0x14296C80+1
        defadr wstrcpy,0x145D9EEC+1
        defadr wstrcmpi,0x145CD8AC+1
        defadr wstrrchr,0x14296C08+1
        defadr GUIonMessage_GetMsg,0x14022620+1
        defadr GUIonMessage_GetCreatedItemIndex,0x14022854+1
        defadr GUIonMessage_SetMenuItemText,0x14022B40+1
        defadr GUIonMessage_SetMenuItemIcon,0x1437B884+1
        defadr FSX_IsFileExists,0x149CD5A8+1
        defadr FileDelete,0x140DEAB0+1
        defadr FileCopy,0x144DDB7C+1
        defadr MessageBox,0x153A65E0+1
        defadr GetURIScheme,0x14227E3C+1
        defadr CreateURI,0x14228000+1
        defadr Browser_OpenURI,0x14B6AB90+1
        defadr ThemeImage_Apply,0x14BF495C+1
        defadr MainMenu_SetFromUserTheme,0x148A7634+1

        defadr strcmp,0x101A34E8+1
        defadr CreateBook,0x1417FFAC+1
        defadr FindBook,0x1446C6A8+1
        defadr BookObj_SetFocus,0x1417E4B8+1
        defadr BookObj_GotoPage,0x14051800+1
        defadr BookObj_ReturnPage,0x14235190+1
        defadr BookObj_CallPage,0x148FB4EC+1

        defadr CreateListMenu,0x14180708+1
        defadr ListMenu_SetItemCount,0x140DBDF4+1
        defadr ListMenu_SetCursorToItem,0x140033DC+1
        defadr ListMenu_SetHotkeyMode,0x14182AB0+1
        defadr ListMenu_SetTexts,0x1456B7B0+1
        defadr ListMenu_SetOnMessage,0x143D5068+1
        defadr ListMenu_GetSelectedItem,0x1437B204+1
        defadr GUIObject_SetTitleText,0x14054A00+1
        defadr GUIObject_SetStyle,0x143FFB48+1
        defadr GUIObject_Destroy,0x145681C0+1

        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x12E9
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        bl      _SetText
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        bl      _SetAction
        ldr     r2, =0x14FF8AAC+1
        ldr	r1, =0xFAF
        LDR     R0, [r4,#0x18]
        bl      _SetAction
        ldr	r3, =0x14FF8964+1
        bx	r3

_SetText:
        ldr     r3, =GUIObject_SoftKeys_SetText
        bx      r3
_SetAction:
        ldr     r3, =GUIObject_SoftKeys_SetAction
        bx      r3

        END
