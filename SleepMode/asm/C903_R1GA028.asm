//C903_R1GA028

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BA326F4
        defadr memfree,0x4BA3271C
        defadr memset,0x14C2C310
        defadr memcpy,0x150B80F4
        defadr set_envp,0x101EB5CC+1
        defadr get_envp,0x101EB5B8+1

        defadr Timer_Kill,0x1416A038+1
        defadr Timer_ReSet,0x14169D48+1
        defadr Timer_Set,0x1423D298+1

        defadr snwprintf,0x144A1D24+1
        defadr wstrlen,0x144C1FE4+1
        defadr wstrcat,0x1429020C+1
        defadr wstrcpy,0x142902B4+1
        defadr wstrncpy,0x144A1E70+1
        defadr wstrcmp,0x144BFF50+1
        defadr wstrcmpi,0x144C2D38+1
        defadr wstrncmp,0x14120B94+1
        defadr wstrrchr,0x1409EBA4+1
        defadr wstrnupr,0x141B0464+1
        defadr wstr2strn,0x1409DBC8+1
        defadr str2wstr,0x1428ED8C+1
        defadr strlen,0x14D16468+1
        defadr strstr,0x142C3FAC+1
        defadr strcmp,0x14D1640C+1
        defadr strncmp,0x141AA4C8+1
        defadr strcpy,0x14D16434+1
        defadr strncpy,0x144429AC+1

        defadr fstat,0x142908B8+1
        defadr _fopen,0x1403ECBC+1
        defadr fread,0x144C1C90+1
        defadr fwrite,0x141C0210+1
        defadr fclose,0x140FC8DC+1
        defadr w_fopen,0x100B2F14+1
        defadr w_fread,0x100FFCA4+1
        defadr w_fclose,0x10147554+1
        defadr w_fstat,0x100B2F58+1
        defadr w_lseek,0x100FFDA4
        defadr w_chdir,0x4BA80C30
        defadr w_diropen,0x4BA324C4
        defadr w_dirclose,0x4BA80C10
        defadr w_dirread,0x1409D3A0+1

        defadr FSX_MakeFullPath,0x144C0E10+1
        defadr FSX_FreeFullPath,0x14043040+1
        defadr FSX_IsFileExists,0x14F96954+1
        defadr FILEITEM_GetFname,0x142DB0CC+1
        defadr FILEITEM_GetPath,0x142DB0D0+1
        defadr getFileExtention,0x144DD730+1

        defadr ImageID_Free,0x1448090C+1
        defadr ImageID_GetIndirect,0x15136CF8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E8F368+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1513892C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x151389B4+1
        defadr iconidname2id,0x144BF344+1

        defadr Display_GetWidth,0x141A94D0+1
        defadr Display_GetHeight,0x1411A6C0+1

        defadr List_DestroyElements,0x144DD220+1
        defadr List_Destroy,0x14103B00+1
        defadr List_Create,0x14103A08+1
        defadr List_Get,0x1416DB8C+1
        defadr List_GetCount,0x1416DBA0+1
        defadr List_InsertFirst,0x14103C6C+1
        defadr List_InsertLast,0x14169F44+1
        defadr root_list_get_session_count,0x1406F7B0+1
        defadr root_list_get_session,0x14104E60+1

        defadr UI_Event,0x1439FE18+1
        defadr UI_Event_toBookID,0x1439D53C+1
        defadr UI_Event_toBookIDwData,0x142A87D8+1

        defadr IsAudioPlayerBook,0x14270DB0+1
        defadr Find_StandbyBook,0x14387450+1
        defadr CreateBook,0x144AAFC0+1
        defadr FindBook,0x1416DBA4+1
        defadr FreeBook,0x14132CB4+1
        defadr FreeAllBook,0x154CB11C+1
        defadr BookObj_CallPage,0x142CA384+1
        defadr BookObj_GotoPage,0x140455DC+1
        defadr BookObj_ReturnPage,0x142CA018+1
        defadr BookObj_SetFocus,0x14510834+1
        defadr BookObj_GetBookID,0x1416E114+1
        defadr BookObj_SetDisplayOrientation,0x143A05A8+1
        defadr BookObj_GetDisplayOrientation,0x14046718+1
        defadr BookObj_GetSession,0x14045814+1

        defadr TextID_Create,0x142D73EC+1
        defadr TextID_CreateIntegerID,0x143D56D4+1
        defadr TextID_Copy,0x1416E4B4+1
        defadr TextID_GetLength,0x1416F584+1
        defadr TextID_Destroy,0x1416ED6C+1
        defadr TextID_GetString,0x1416E6FC+1
        defadr TextID_GetWString,0x1416E9D8+1
        defadr TextObject_SetText,0x1416F6BC+1
        defadr TextObject_SetFont,0x141725B8+1
        defadr RichTextLayout_GetTextWidth,0x144221C8+1

        defadr DISP_DESC_SetName,0x145081A0+1
        defadr DISP_DESC_SetSize,0x145081EC+1
        defadr DISP_DESC_SetOnCreate,0x14508194+1
        defadr DISP_DESC_SetOnClose,0x1450819C+1
        defadr DISP_DESC_SetOnRedraw,0x145081F0+1
        defadr DISP_DESC_SetOnKey,0x145085F8+1
        defadr DISP_DESC_SetOnLayout,0x1450859C+1

        defadr DispObject_GetGUI,0x1438679C+1
        defadr DispObject_SetStyle,0x141A8C5C+1
        defadr DispObject_GetStyle,0x1416CF90+1
        defadr DispObject_SetLayerColor,0x144AC7F4+1
        defadr DispObject_InvalidateRect,0x1416ACC0+1
        defadr DispObject_SetAnimation,0x14EC5F14+1
        defadr DispObject_SetBacklightMode,0x142366BC+1
        defadr DispObject_SoftKeys_Show,0x143A0668+1
        defadr DispObject_SoftKeys_Hide,0x14510CF8+1
        defadr DispObject_SoftKeys_GetList,0x1416E2B8+1

        defadr get_DisplayGC,0x1416BC44+1
        defadr DisplayGC_AddRef,0x143CF570+1
        defadr DrawRect,0x14107094+1
        defadr GC_DrawLine,0x144E0E04+1
        defadr GC_GetPenColor,0x14EB1E34+1
        defadr GC_SetPenColor,0x14107408+1
        defadr GC_SetBrushColor,0x141072F0+1
        defadr GC_GetXX,0x14232504+1
        defadr GC_SetXX,0x1419C3A8+1
        defadr GC_GetRect,0x14117008+1
        defadr GC_ValidateRect,0x143CF598+1

        defadr BookObj_AddGUIObject,0x141323B0+1
        defadr GUIObject_Create,0x144AC104+1
        defadr GUIObject_GetDispObject,0x1416CFEC+1
        defadr GUIObject_SetStyle,0x141321C0+1
        defadr GUIObject_GetStyle,0x1416CFF8+1
        defadr GUIObject_SetTitleType,0x143A1884+1
        defadr GUIObject_SetTitleText,0x1410F974+1
        defadr GUIObject_SetSecondRowTitleText,0x144D56C0+1
        defadr GUIObject_Show,0x144ABC0C+1
        defadr GUIObject_GetBook,0x14104874+1
        defadr GUIObject_Destroy,0x14510E28+1

        defadr CreateListMenu,0x141323BC+1
        defadr ListMenu_SetItemStyle,0x140F5D88+1
        defadr ListMenu_SetHotkeyMode,0x1411B158+1
        defadr ListMenu_SetOnMessage,0x142D96DC+1
        defadr ListMenu_SetItemCount,0x142D96F0+1
        defadr ListMenu_SetCursorToItem,0x14131DA0+1
        defadr ListMenu_SetNoItemText,0x150A93CC+1
        defadr ListMenu_GetSelectedItem,0x1411B3F4+1
        defadr ListMenu_SetTexts,0x141AD354+1
        defadr ListMenu_SetItemTextScroll,0x1410FF88+1
        defadr ListMenu_DestroyItems,0x143C2AC8+1
        defadr ListMenu_SetItemSecondLineText,0x142D9560+1

        defadr GUIonMessage_GetBook,0x142F01B8+1
        defadr GUIonMessage_GetMsg,0x142F02A0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142F01AC+1
        defadr GUIonMessage_SetMenuItemText,0x142EFC88+1
        defadr GUIonMessage_SetMenuItemIcon,0x14044EF0+1
        defadr GUIonMessage_SetItemDisabled,0x14258370+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FE1D0+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14F8126C+1
        defadr GUIonMessage_GetSelectedItem,0x14067528+1

        defadr CreateOneOfMany,0x140F5D0C+1
        defadr OneOfMany_SetItemCount,0x150A96EC+1
        defadr OneOfMany_SetOnMessage,0x14D93110+1
        defadr OneOfMany_SetChecked,0x14110B20+1
        defadr OneOfMany_GetSelected,0x15079824+1

        defadr CreateTabMenuBar,0x1433C27C+1
        defadr TabMenuBar_SetTabGui,0x14511E90+1
        defadr TabMenuBar_SetTabTitle,0x1402C07C+1
        defadr TabMenuBar_SetTabIcon,0x142F291C+1
        defadr TabMenuBar_SetTabCount,0x1426E604+1
        defadr TabMenuBar_SetOnTabSwitch,0x1406ABF4+1
        defadr TabMenuBar_GetFocusedTab,0x141FED04+1
        defadr TabMenuBar_SetFocusedTab,0x14511BA0+1

        defadr CreateStringInput,0x1504D540+1
        defadr StringInput_SetMode,0x14001148+1
        defadr StringInput_SetFixedText,0x14015804+1
        defadr StringInput_SetMinLen,0x1504D988+1
        defadr StringInput_SetMaxLen,0x14318354+1
        defadr StringInput_SetEnableEmptyText,0x14EF71F8+1
        defadr StringInput_SetActionOK,0x14288FDC+1

        defadr TextFeedbackWindow,0x14234E8C+1
        defadr Feedback_SetTextExtended,0x14234D18+1
        defadr Feedback_CloseAction,0x1414C5B8+1

        defadr GUIObject_SoftKeys_SetEnable,0x140437C8+1
        defadr GUIObject_SoftKeys_SetText,0x1410456C+1
        defadr GUIObject_SoftKeys_SetAction,0x14104834+1
        defadr GUIObject_SoftKeys_SetVisible,0x14104810+1
        defadr GUIObject_SoftKeys_SetInfoText,0x140A67BC+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x14046618+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x150BAC90+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x14DA1D00+1
        defadr GUIObject_SoftKeys_Hide,0x14510CE4+1
        defadr GUIObject_SoftKeys_Show,0x143A065C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x14104880+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A073C+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x143A059C+1

        defadr MediaPlayer_SoftKeys_AddHelpStr,0x140B3FA8+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x140B3F78+1
        defadr MediaPlayer_SoftKeys_SetAction,0x140B3D78+1
        defadr MediaPlayer_SoftKeys_SetText,0x140B3D48+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x140B3FA8+1

        defadr SETTING_RINGTYPESOUNDFILE_SET,0x158FC5E8+1
        defadr Sound_SetMessageAlert,0x14E0FC28+1
        defadr Sound_SetAlarmsignal,0x1520500C+1
        defadr Sound_AddToContact,0x15301964+1
        defadr CreateMessageBox,0x14E9F328+1

        defadr Volume_Set,0x14273870+1
        defadr Volume_Get,0x14273674+1
        defadr MetaData_GetTags,0x14E70910+1
        defadr OSE_GetShell,0x14169404+1
        defadr CoCreateInstance,0x14460B7C+1
        defadr REQUEST_DATEANDTIME_GET,0x1434EB94+1
        defadr Time2ID,0x1434E630+1
        defadr Date2ID,0x14388150+1
        defadr DATE_GetWeekDay,0x1434ED50+1

        EXTERN  New_SleepMode_OnRedraw
        EXTERN  SetRefreshTimer
        EXTERN  KillRefreshTimer

        RSEG  CODE
        CODE16
SetTimer:
        LDR     R3, =0x1426CFE8+1
        BLX	R3
        ADD     R0, R4, #0
        BL      SetRefreshTimer
        MOV	R0, SP
        LDRB    R0, [R0,#0]
        LDR     R3, =0x142D8970+1
        BX      R3

        RSEG  CODE
        CODE16
KillTimer:
	CMP	R5, #0xD
	BCC	kill_ret
	BL	KillRefreshTimer
	POP	{R4-R7,PC}
kill_ret:
	LDR	R3, =0x14236C10+1
	BX	R3

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

        END
