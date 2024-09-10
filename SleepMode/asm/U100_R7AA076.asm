//U100_R7AA076

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr debug_printf,0x4BC00008
        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145F06B2+1
        defadr memcpy,0x145F05D2+1
        defadr snprintf,0x147EBE80+1
        defadr snwprintf,0x147EBEBC+1
        defadr get_envp,0x10297144+1
        defadr set_envp,0x10297158+1
        defadr current_process,0x102969F4
        defadr get_bid,0x10296A2C

        defadr _fopen,0x146C4E20+1
        defadr fwrite,0x146C5DD4+1
        defadr fclose,0x1461C0F8+1
        defadr fread,0x141AA3A8+1
        defadr fstat,0x141E5250+1
        defadr lseek,0x14115288+1
        defadr fflush,0x10280824
        defadr w_fopen,0x10146854+1
        defadr w_fwrite,0x101AAC94+1
        defadr w_fclose,0x10243A90+1

        defadr strlen,0x1437D970+1
        defadr strstr,0x147ED76A+1
        defadr strncpy,0x140DB138
        defadr strcmp,0x1029826C+1
        defadr strncmp,0x147ED49C+1
        defadr wstrlen,0x141AAA10+1
        defadr wstrrchr,0x141AAA24+1
        defadr wstrcat,0x147ECED0+1
        defadr wstr2strn,0x14246E0C+1
        defadr str2wstr,0x1418485C+1
        defadr wstrcpy,0x147ECE98+1
        defadr wstrncmp,0x147ECF30+1

        defadr FILEITEM_GetPath,0x146A12F4+1
        defadr FILEITEM_GetFname,0x146A1684+1
        defadr FILEITEM_GetFextension,0x146A1018+1
        defadr FSX_MakeFullPath,0x141E60AC+1
        defadr FSX_FreeFullPath,0x1414D9D8+1
        defadr FSX_IsFileExists,0x147002C0+1

        defadr TextID_Copy,0x142AC87C+1
        defadr TextID_GetWString,0x142AC568+1
        defadr TextID_Create,0x145128B0+1
        defadr TextID_GetLength,0x142AC9E8+1
        defadr TextID_Destroy,0x142AC5E0+1
        defadr TextID_GetString,0x142AC288+1
        defadr RichTextLayout_GetTextWidth,0x14533EA8+1

        defadr OSE_GetShell,0x143BB0D0+1
        defadr CoCreateInstance,0x1469688C+1
        defadr TextObject_SetText,0x141A07FC+1
        defadr TextObject_SetFont,0x1438ED74+1
        defadr get_DisplayGC,0x146DE6F4+1
        defadr DisplayGC_AddRef,0x142BBE38+1

        defadr GC_GetRect,0x140EEDDC+1
        defadr GC_GetXX,0x1471DC80+1
        defadr GC_SetXX,0x15069F10+1
        defadr GC_GetPenColor,0x1419F1B0+1
        defadr GC_SetPenColor,0x146DDCB8+1
        defadr GC_DrawLine,0x1405D4F8+1
        defadr DrawRect,0x142BC408+1

        defadr CreateBook,0x14157AC4+1
        defadr FreeBook,0x140FDE10+1
        defadr BookObj_CallPage,0x140FE158+1
        defadr BookObj_GotoPage,0x1457B000+1
        defadr BookObj_Hide,0x14639F38+1
        defadr BookObj_ReturnPage,0x140FE388+1
        defadr BookObj_GetSession,0x1457ACA4+1

        defadr GUIObject_Create,0x1438D998+1
        defadr BookObj_AddGUIObject,0x1463A46C+1
        defadr GUIObject_GetDispObject,0x145D0C08+1
        defadr GUIObject_SetStyle,0x140DEBD8+1
        defadr GUIObject_SetTitleType,0x1405FB1C+1
        defadr GUIObject_SetTitleText,0x1435BEDC+1
        defadr GUIObject_Show,0x1469C1AC+1
        defadr GUIObject_Destroy,0x1457BDE8+1
        defadr GUIObject_SetAnimationApp,0x145C8D0C+1

        defadr DispObject_GetGUI,0x141B1118+1
        defadr GUIObject_GetBook,0x142AAD20+1
        defadr MainDisplay_GetTopBook,0x1438B57C+1

        defadr DispObject_InvalidateRect,0x142AA360+1
        defadr DispObject_SetBacklightMode,0x1405F658+1
        defadr DispObject_SetRefreshTimer,0x1405F010+1
        defadr DispObject_KillRefreshTimer,0x1426767C+1
        defadr DispObject_SetThemeImage,0x140DC308+1
        defadr DispObject_SetLayerColor,0x140DB818+1

        defadr DISP_DESC_SetName,0x1428B868+1
        defadr DISP_DESC_SetSize,0x1428B85C+1
        defadr DISP_DESC_SetOnCreate,0x1428B864+1
        defadr DISP_DESC_SetOnClose,0x1428B86C+1
        defadr DISP_DESC_SetOnRedraw,0x1428B7D8+1
        defadr DISP_DESC_SetOnKey,0x1428B38C+1
        defadr DISP_DESC_SetOnLayout,0x1428B448+1
        defadr DISP_DESC_SetOnRefresh,0x1428B388+1

        defadr MetaData_GetTags,0x14F85808+1
        defadr DATE_GetWeekDay,0x147B71FC+1
        defadr Time2ID,0x1403A82C+1
        defadr Date2ID,0x1403B134+1

        defadr Timer_ReSet,0x142664E0+1
        defadr Timer_Set,0x142677F4+1
        defadr Timer_Kill,0x142676B0+1

        defadr ImageID_Free,0x14515040+1
        defadr ImageID_GetIndirect,0x1523DA24+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x151DAEBC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x140C8508+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1523E9B8+1

        defadr Display_GetWidth,0x140EF7CC+1
        defadr Display_GetHeight,0x140EF7DC+1
        defadr Volume_Get,0x146CC77C+1
        defadr Volume_Set,0x146CC46C+1
        defadr CreateMessageBox,0x147743D8+1

        defadr GUIObject_SoftKeys_SetText,0x1465FA8C+1
        defadr GUIObject_SoftKeys_SetAction,0x14391FA8+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143927D4+1
        defadr GUIObject_SoftKeys_Show,0x14730EC4+1
        defadr GUIObject_SoftKeys_Hide,0x14639C18+1
        defadr GUIObject_SoftKeys_SetVisible,0x143931E0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1469DA5C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x15499E3C+1

        defadr CreateListMenu,0x1463A478+1
        defadr ListMenu_DestroyItems,0x145968E8+1
        defadr ListMenu_SetItemCount,0x14156988+1
        defadr ListMenu_GetSelectedItem,0x14603A04+1
        defadr ListMenu_SetCursorToItem,0x141564B8+1
        defadr ListMenu_SetOnMessage,0x1469E1C4+1
        defadr ListMenu_SetItemStyle,0x1464DD60+1
        defadr ListMenu_SetItemSecondLineText,0x14015F5C+1
        defadr GUIonMessage_GetMsg,0x1469FA50+1
        defadr GUIonMessage_GetBook,0x1469FBF8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1469F67C+1
        defadr GUIonMessage_SetItemDisabled,0x140FE6CC+1
        defadr GUIonMessage_SetMenuItemText,0x1438CC38+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141296F4+1

        defadr CreateOneOfMany,0x147DD8D8+1
        defadr OneOfMany_SetTexts,0x142453A4+1
        defadr OneOfMany_SetChecked,0x147DD774+1
        defadr OneOfMany_GetSelected,0x14734D74+1

        defadr CreateYesNoQuestion,0x140DF6EC+1
        defadr YesNoQuestion_SetDescriptionText,0x14488D48+1
        defadr YesNoQuestion_SetQuestionText,0x145CD45C+1
        defadr YesNoQuestion_SetIcon,0x14488D3C+1

        defadr GetSilent,0x146CC824+1
        defadr FindBook,0x143BC05C+1
        defadr PlaySystemSound,0x145788C8+1
        defadr IsAudioPlayerBook,0x1432082C+1
        defadr REQUEST_DATEANDTIME_GET,0x1461F1C0+1
        defadr isKeylocked,0x142F7CC8+1

        defadr png_create_info_struct,0x1002FD1C+1
        defadr png_create_write_struct_2,0x104488DC+1
        defadr png_destroy_write_struct,0x10448C40+1
        defadr png_do_swap,0x104481BC+1
        defadr png_get_io_ptr,0x1021B338+1
        defadr png_get_rowbytes,0x146D7FB2+1
        defadr png_info_destroy,0x1002FD80+1
        defadr png_set_compression_level,0x10448F58+1
        defadr png_set_bgr,0x1002F54C+1
        defadr png_set_IHDR,0x1010F498+1
        defadr png_set_text,0x102099D0+1
        defadr png_set_write_fn,0x104483F4+1
        defadr png_write_info,0x104485D0+1
        defadr png_write_row,0x10448A70+1
        defadr png_write_end,0x104487D4+1

        defadr DispObject_GetWindow,0x143BBD04+1
        defadr Window_XX,0x143D7388+1

        EXTERN  New_SleepMode_OnRedraw
        EXTERN  SetRefreshTimer
        EXTERN  KillRefreshTimer

        RSEG    PATCH_TIMER_SET
        CODE16
        LDR     R3, =SetTimer
        BX	R3

        RSEG    PATCH_TIMER_KILL
        CODE16
        LDR     R3, =KillTimer
        BX	R3

        RSEG    PATCH_SLEEPMODE_ONREDRAW
        DATA
        DCD     New_SleepMode_OnRedraw

        RSEG  CODE
        CODE16
SetTimer:
        LDR     R3, =DispObject_GetWindow
        BLX	R3
        MOV     R1, #0
        LDR     R3, =Window_XX
        BLX	R3
        ADD     R0, R4, #0
        BL      SetRefreshTimer
        LDR     R0, [SP,#0xC]
        ADD     SP, #0x24
        POP     {R4-R7,PC}

KillTimer:
	ADD     R4, R4, #1
        LSL     R4, R4, #0x18
        LSR     R4, R4, #0x18
        CMP     R4, #8
        BCC     kill_ret
        POP     {R3-R7,PC}

kill_ret:
	LDR	R3, =0x140FD8BC+1
	BX	R3

        END
