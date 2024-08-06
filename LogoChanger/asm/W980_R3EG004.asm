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
        defadr wstrlen,0x10D65030+1
        defadr wstrcpy,0x10D65074+1
        defadr wstrcmpi,0x10D66494+1
        defadr w_diropen,0x4BB00354
        defadr w_chdir,0x4BB003AC
        defadr w_dirread,0x11A5FD24+1
        defadr w_fstat,0x112A40E4+1
        defadr w_dirclose,0x4BB0038C
        defadr wstrcmp,0x10D65044+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A8DC60+1
        defadr wstrncpy,0x10D6508C+1
        defadr wstrncmp,0x106F7978+1
        defadr wstrnupr,0x10D65100+1
        defadr StringInput_SetText,0x10895584+1
        defadr wstrrchr,0x10D663B4+1
        defadr FindBook,0x10DEDC1C+1
        defadr FindBookByID,0x10DEDBE8+1
        defadr Shortcut_Get_MenuItemIconID,0x10DDB8E0+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10DDA9F0+1
        defadr Shortcut_Get_MenuItemName,0x10B3255C+1
        defadr TextID_GetWString,0x10F68B54+1
        defadr BookObj_GetBookID,0x10DF0140+1
        defadr MenuBook_Desktop,0x10DDB6BC+1
        defadr BookObj_SoftKeys_SetAction,0x10807A70+1
        defadr BookObj_SoftKeys_SetText,0x10807AA8+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr List_Get,0x11AD3928+1
        defadr List_GetCount,0x11AD38FC+1
        defadr FILEITEM_GetFname,0x11808CFC+1
        defadr FILEITEM_GetPath,0x11808D90+1
        defadr FSX_MakeFullPath,0x109590A4+1
        defadr DataBrowser_isFileInListExt,0x10953E04+1
        defadr fstat,0x109564E4+1
        defadr DataBrowserDesc_Create,0x118004C0+1
        defadr DataBrowserDesc_SetHeaderText,0x11800770+1
        defadr DataBrowserDesc_SetBookID,0x118006C0+1
        defadr DataBrowserDesc_SetFolders,0x11800758+1
        defadr DataBrowserDesc_SetFileExtList,0x1180066C+1
        defadr DataBrowserDesc_SetItemFilter,0x11800664+1
        defadr DataBrowserDesc_SetFoldersNumber,0x11800760+1
        defadr DataBrowserDesc_SetSelectAction,0x118006DC+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x118006C8+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x11800724+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1180072C+1
        defadr DataBrowser_Create,0x117FCB18+1
        defadr DataBrowserDesc_Destroy,0x11800570+1
        defadr CreateStringInput,0x10894AB0+1
        defadr StringInput_SetMode,0x10895368+1
        defadr StringInput_SetEnableEmptyText,0x108954F4+1
        defadr StringInput_SetMinLen,0x108953D0+1
        defadr StringInput_SetMaxLen,0x10895480+1
        defadr StringInput_SetActionOK,0x108953C4+1
        defadr StringInput_SetActionBack,0x108953C8+1
        defadr StringInput_GetStringAndLen,0x10895400+1
        defadr StringInput_MenuItem_SetPriority,0x10895554+1
        defadr BookObj_CallPage,0x10DEF818+1
        defadr List_RemoveFirst,0x11AD38D4+1
        defadr List_InsertFirst,0x11AD387C+1
        defadr List_RemoveAt,0x11AD3808+1
        defadr ListMenu_SetItemTextScroll,0x11A8D748+1
        defadr ListMenu_SetHotkeyMode,0x11A8D1A4+1
        defadr ListMenu_SetNoItemText,0x11A8D1F8+1
        defadr strcmp,0x106F6FB8+1
        defadr BookObj_SetFocus,0x10DEFC84+1
        defadr JavaDialog_Open,0x10B12910+1
        defadr JavaAppDesc_GetFirstApp,0x10B083CC+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B07E98+1
        defadr JavaAppDesc_GetJavaAppID,0x10B16138+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10C39B98+1
        defadr JavaAppDesc_GetNextApp,0x10B083D4+1
        defadr JavaDialog_Close,0x10B16010+1
        defadr UI_Event,0x10DEE77C+1
        defadr UI_Event_toBookID,0x10DEE7D4+1
        defadr Shortcut_Run,0x10DDBF08+1
        defadr List_DestroyElements,0x11AD3A1C+1
        defadr List_Destroy,0x11AD3730+1
        defadr ImageID_Free,0x107A6788+1
        defadr JavaApp_LogoImageID_Get,0x10C2E4E4+1
        defadr List_Create,0x11AD3708+1
        defadr List_InsertLast,0x11AD3884+1
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

        defadr MessageBox,0x11A64894+1
        defadr FileDelete,0x10956774+1
        defadr INetworkServices_GetNetworkName,0x10FC8D14+1
        defadr GetOperatorName,0x10FC8BF0+1
        defadr SetOperatorName,0x10FC9D3C+1
        defadr GUIObject_SetTitleIcon,0x109D0694+1

        defadr onBackPressed,0x10A5CAB0+1
        defadr onLongBackPressed,0x10E296E4+1
        defadr pg_EditPhoneName_EnterEvent,0x10A5C934+1
        defadr pg_EditPhoneName_ExitEvent,0x10A5AAA4+1

	EXTERN ReadOnFile
        EXTERN evtlst_EditPhoneName_new

//--------------------------------------

	RSEG	PATCH_NEW_EVENTLIST
	DATA
	DCD	evtlst_EditPhoneName_new

//--------------------------------------

	RSEG	PATCH_GET_NEWOPNAME
	CODE16
	LDR	R3, =Get_NewOpName
	BX	R3

	RSEG	CODE
        CODE16
Get_NewOpName:
        ADD     R5, R2, #0
	BL	ReadOnFile
        CMP     R0, #0
        BEQ     No_Patch
        MOV     R1, #0
        MOV     R2, #0xFF
        B       SetName
No_Patch:
        ADD     R2, R5,	#0
        MOV	R1, #0
	ADD     R0, R6,	#0
SetName:
        BL      j_TextID_Create
	ADD     R4, R0,	#0
        LDR     R3, =0x10FC8CCC+1
        BX      R3

j_TextID_Create:
        LDR     R3, =TextID_Create
        BX      R3

        END
