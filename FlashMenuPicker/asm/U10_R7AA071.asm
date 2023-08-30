//U10_R7AA071

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr debug_printf,0x4FC00008
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr memset,0x14610C2E+1
        defadr memcpy,0x14610B4E+1
        defadr get_envp,0x1029A4E4+1
        defadr set_envp,0x1029A4F8+1
        defadr current_process,0x10299D94
        defadr get_bid,0x10299DCC
	defadr strlen,0x14392AC0+1
	defadr strstr,0x1481E3AA+1
	defadr strncpy,0x140E03DC
        defadr strcmp,0x1029B60C+1
        defadr wstrcmp,0x141B2C1C+1
        defadr wstrcmpi,0x141B2F68+1
	defadr wstrrchr,0x141B2BC8+1
	defadr wstrcat,0x1481DB10+1
	defadr str2wstr,0x1418BAEC+1
	defadr wstrcpy,0x1481DAD8+1
        defadr wstrlen,0x141B2BB4+1
        defadr wstrnupr,0x14277684+1
        defadr wstrncmp,0x1481DB70+1
        defadr wstr2strn,0x14253098+1
        defadr _fopen,0x146EE4EC+1
        defadr fread,0x141B254C+1
        defadr fclose,0x1463D0D0+1
        defadr fwrite,0x146EF4A0+1
        defadr fstat,0x141F09F0+1
        defadr lseek,0x14118B30+1
        defadr FileCopy,0x146557B4+1
        defadr FileDelete,0x146566B8+1
        defadr w_fopen,0x10147900+1
	defadr w_lseek,0x14817918+1
	defadr w_fclose,0x10244F18+1
	defadr w_fread,0x101AC33C+1
        defadr w_fstat,0x10147204+1
        defadr w_diropen,0x4FFA7DEC
        defadr w_chdir,0x4FFA7E44
        defadr w_dirread,0x10283CC4
        defadr w_dirclose,0x4FFA7E24
        defadr Timer_ReSet,0x14272B64+1
        defadr Timer_Set,0x14273E78+1
        defadr Timer_Kill,0x14273D34+1
        defadr snwprintf,0x1481CAFC+1
        defadr TextID_Create,0x14530A4C+1
        defadr TextID_Copy,0x142B9E94+1
        defadr TextID_Destroy,0x142B9BF8+1
        defadr TextID_GetLength,0x142BA000+1
        defadr TextID_GetWString,0x142B9B80+1
        defadr CoCreateInstance,0x146BFD3C+1
        defadr TextObject_SetText,0x141A85A8+1
        defadr TextObject_SetFont,0x143A5054+1
	defadr RichTextLayout_GetTextWidth,0x14552934+1
        defadr get_DisplayGC,0x1470812C+1
        defadr DisplayGC_AddRef,0x142C9540+1
        defadr DrawRect,0x142C9B10+1
        defadr GC_GetRect,0x140F25EC+1
        defadr GC_GetXX,0x14747C7C+1
        defadr GC_SetXX,0x1526B744+1
        defadr GC_GetPenColor,0x141A6F5C+1
        defadr GC_SetPenColor,0x147076E8+1
        defadr GC_DrawLine,0x1405EECC+1
        defadr ListMenu_GetSelectedItem,0x14623F80+1
        defadr ListMenu_DestroyItems,0x145B6598+1
        defadr ListMenu_SetItemCount,0x1415CAB0+1
        defadr ListMenu_SetCursorToItem,0x1415C5E0+1
        defadr GUIObject_SoftKeys_SetVisible,0x143A94C0+1
        defadr ListMenu_SetItemSecondLineText,0x14016060+1
        defadr OneOfMany_GetSelected,0x1475F954+1
        defadr GUIObject_Destroy,0x1459AF78+1
        defadr CreateOneOfMany,0x1480E308+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr OneOfMany_SetTexts,0x14251630+1
        defadr OneOfMany_SetChecked,0x1480E1A4+1
        defadr GUIObject_Show,0x146C5748+1
        defadr DispObject_InvalidateRect,0x142B7978+1
        defadr DispObject_SetBacklightMode,0x1406102C+1
        defadr DISP_DESC_SetName,0x142987BC+1
        defadr DISP_DESC_SetSize,0x142987B0+1
        defadr DISP_DESC_SetOnCreate,0x142987B8+1
        defadr DISP_DESC_SetOnClose,0x142987C0+1
        defadr DISP_DESC_SetOnRedraw,0x1429872C+1
        defadr DISP_DESC_SetOnLayout,0x1429839C+1
        defadr DISP_DESC_SetOnKey,0x142982E0+1
        defadr DISP_DESC_SetOnRefresh,0x142982DC+1
        defadr GUIObject_GetDispObject,0x145F106C+1
        defadr GUIObject_Create,0x143A3C78+1
        defadr BookObj_AddGUIObject,0x146628F0+1
        defadr GUIObject_SetTitleType,0x140614F0+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1
        defadr GUIObject_SoftKeys_Show,0x1475B098+1
        defadr GUIObject_SoftKeys_Hide,0x14661398+1
        defadr GUIObject_SetAnimationApp,0x145E8DF4+1
        defadr FreeBook,0x141016DC+1
        defadr FindBook,0x143D2CB0+1
        defadr BookObj_CallPage,0x14101A24+1
        defadr BookObj_SetFocus,0x146613E0+1
        defadr ImageID_GetIndirect,0x15458770+1
        defadr getFileExtention,0x141F2374+1
        defadr ImageID_Free,0x141909A4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x140CAB00+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15459704+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x153F1088+1
        defadr Volume_Set,0x146F5C44+1
        defadr Volume_Get,0x146F5F58+1
        defadr DispObject_SetRefreshTimer,0x140609E4+1
        defadr DispObject_KillRefreshTimer,0x14273D00+1
        defadr DispObject_SetThemeImage,0x140D99C0+1
        defadr DispObject_SetLayerColor,0x140D8ED0+1
        defadr Display_GetWidth,0x140F2FDC+1
        defadr Display_GetHeight,0x140F2FEC+1
        defadr CreateMessageBox,0x147A0C28+1
        defadr BookObj_Hide,0x146623BC+1
        defadr BookObj_ReturnPage,0x14101C54+1
        defadr GUIObject_SetStyle,0x140E20C4+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x156B3298+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x146C6FF8+1
        defadr GUIObject_SetBacklightTimeout,0x14008440+1
        defadr GUIObject_SetBacklightOn,0x1406105C+1
        defadr FILEITEM_GetPath,0x146CA88C+1
        defadr FILEITEM_GetFname,0x146CAC1C+1
        defadr FSX_MakeFullPath,0x141F184C+1
        defadr FSX_FreeFullPath,0x14152CFC+1
        defadr FSX_IsFileExists,0x14729F3C+1
        defadr GUIonMessage_GetMsg,0x146C8FE8+1
        defadr GUIonMessage_GetBook,0x146C9190+1
        defadr GUIonMessage_GetCreatedItemIndex,0x146C8C18+1
        defadr GUIonMessage_SetMenuItemText,0x143A2F18+1
        defadr GUIonMessage_SetMenuItemIcon,0x14533244+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1412D4D4+1
        defadr GUIonMessage_SetItemDisabled,0x14101F98+1
        defadr CreateListMenu,0x146628FC+1
        defadr ListMenu_SetHotkeyMode,0x14676678+1
        defadr ListMenu_SetOnMessage,0x146C7760+1
        defadr ListMenu_SetItemStyle,0x146765A4+1
        defadr ListMenu_SetItemTextScroll,0x14313144+1
        defadr ListMenu_SetNoItemText,0x1535CE50+1
        defadr CreateYesNoQuestion,0x140E2BCC+1
        defadr YesNoQuestion_SetDescriptionText,0x144A23F8+1
        defadr YesNoQuestion_SetQuestionText,0x145ED8A4+1
        defadr YesNoQuestion_SetIcon,0x144A23EC+1
        defadr CreateBook,0x1415DBEC+1
        defadr BookObj_GotoPage,0x1459A190+1
        defadr MetaData_GetTags,0x151752E0+1
        defadr FILEITEM_GetFextension,0x146CA5B0+1
        defadr Create_KeyGrabber,0x15109B44+1
        defadr MessageBox,0x1559794C+1
        defadr GetURIScheme,0x1407C8F0+1
        defadr CreateURI,0x1407C60C+1
        defadr FreeURI,0x1407CA98+1
        defadr Browser_OpenURI,0x1530D3D8+1
        defadr ThemeImage_Apply,0x140D1800+1
        defadr MainMenu_SetFromUserTheme,0x153F0C40+1

        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x12B8
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        bl      _SetText
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        LDR     R0, [r4,#0x18]
        bl      _SetAction
        ldr     r2, =0x15668F38+1
        ldr	r1, =0xFAF
        LDR     R0, [r4,#0x18]
        bl      _SetAction
        ldr	r3, =0x15668E1C+1
        bx	r3

_SetText:
        ldr     r3, =GUIObject_SoftKeys_SetText
        bx      r3
_SetAction:
        ldr     r3, =GUIObject_SoftKeys_SetAction
        bx      r3

        END
