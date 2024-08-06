//U100_R7AA076

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr debug_printf,0x4BC00008
        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145F06B2+1
        defadr memcpy,0x145F05D2+1
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
        defadr FileCopy,0x1462F07C+1
        defadr FileDelete,0x1462FF80+1
        defadr w_fstat,0x10146158+1
        defadr w_diropen,0x4BFA5DD4
        defadr w_chdir,0x4BFA5E2C
        defadr w_dirread,0x10280924
        defadr w_dirclose,0x4BFA5E0C
        defadr strcmp,0x1029826C+1
        defadr strlen,0x1437D970+1
        defadr strstr,0x147ED76A+1
        defadr strncpy,0x140DB138
        defadr wstrlen,0x141AAA10+1
        defadr wstrrchr,0x141AAA24+1
        defadr wstrcat,0x147ECED0+1
        defadr wstr2strn,0x14246E0C+1
        defadr str2wstr,0x1418485C+1
        defadr wstrcpy,0x147ECE98+1
        defadr wstrncpy,0x147ECEAA+1
        defadr wstrcmp,0x141AAA78+1
        defadr wstrcmpi,0x141AADC4+1
        defadr wstrncmp,0x147ECF30+1
        defadr wstrnupr,0x1426AE58+1
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
        defadr RichTextLayout_GetTextWidth,0x14533EA8+1
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
        defadr BookObj_GotoPage,0x1457B000+1
        defadr BookObj_Hide,0x14639F38+1
        defadr BookObj_ReturnPage,0x140FE388+1
        defadr GUIObject_Create,0x1438D998+1
        defadr BookObj_AddGUIObject,0x1463A46C+1
        defadr GUIObject_GetDispObject,0x145D0C08+1
        defadr GUIObject_SetStyle,0x140DEBD8+1
        defadr GUIObject_SetTitleType,0x1405FB1C+1
        defadr GUIObject_SetTitleText,0x1435BEDC+1
        defadr GUIObject_Show,0x1469C1AC+1
        defadr GUIObject_Destroy,0x1457BDE8+1
        defadr GUIObject_SetAnimationApp,0x145C8D0C+1
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
        defadr ListMenu_SetHotkeyMode,0x1464DE34+1
        defadr ListMenu_SetItemTextScroll,0x14302F9C+1
        defadr ListMenu_SetNoItemText,0x1514E848+1
        defadr ListMenu_SetItemSecondLineText,0x14015F5C+1
        defadr GUIonMessage_GetMsg,0x1469FA50+1
        defadr GUIonMessage_GetBook,0x1469FBF8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1469F67C+1
        defadr GUIonMessage_SetItemDisabled,0x140FE6CC+1
        defadr GUIonMessage_SetMenuItemText,0x1438CC38+1
        defadr GUIonMessage_SetMenuItemIcon,0x145150A8+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141296F4+1
        defadr CreateOneOfMany,0x147DD8D8+1
        defadr OneOfMany_SetTexts,0x142453A4+1
        defadr OneOfMany_SetChecked,0x147DD774+1
        defadr OneOfMany_GetSelected,0x14734D74+1
        defadr CreateYesNoQuestion,0x140DF6EC+1
        defadr YesNoQuestion_SetDescriptionText,0x14488D48+1
        defadr YesNoQuestion_SetQuestionText,0x145CD45C+1
        defadr YesNoQuestion_SetIcon,0x14488D3C+1
        defadr Shortcut_Run,0x142F7DC4+1
        defadr Shortcut_Get_MenuItemName,0x14157134+1
        defadr Shortcut_Get_MenuItemIconID,0x14079B08+1
        defadr MenuBook_Desktop,0x141577E4+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x14FB89C0+1
        defadr CreateStringInput,0x14433914+1
        defadr StringInput_SetMode,0x140DF440+1
        defadr StringInput_SetEnableEmptyText,0x14FA5FC4+1
        defadr StringInput_SetMinLen,0x14433640+1
        defadr StringInput_SetMaxLen,0x144339E4+1
        defadr StringInput_SetText,0x14556CDC+1
        defadr StringInput_SetActionOK,0x14433B58+1
        defadr StringInput_SetActionBack,0x14433B54+1
        defadr StringInput_GetStringAndLen,0x14639194+1
        defadr StringInput_MenuItem_SetPriority,0x1455699C+1
        defadr BookObj_GetBookID,0x143BBFAC+1
        defadr BookObj_CallPage,0x140FE158+1
        defadr BookObj_SetFocus,0x14639C60+1
        defadr FindBook,0x143BC05C+1
        defadr FindBookByID,0x143BBFD0+1
        defadr UI_Event,0x142681E4+1
        defadr UI_Event_toBookID,0x1461EDC0+1
        defadr BookObj_SoftKeys_SetAction,0x140DEF84+1
        defadr BookObj_SoftKeys_SetText,0x14EFC014+1
        defadr DataBrowser_isFileInListExt,0x141AAC60+1
        defadr DataBrowserDesc_Create,0x14593510+1
        defadr DataBrowserDesc_SetHeaderText,0x145935B4+1
        defadr DataBrowserDesc_SetBookID,0x14593450+1
        defadr DataBrowserDesc_SetFolders,0x145935AC+1
        defadr DataBrowserDesc_SetFoldersNumber,0x14593460+1
        defadr DataBrowserDesc_SetSelectAction,0x145935A4+1
        defadr DataBrowserDesc_SetFileExtList,0x14F52774+1
        defadr DataBrowserDesc_SetItemFilter,0x14F52AE8+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x14FC4D78+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x14593508+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x14593458+1
        defadr DataBrowser_Create,0x14166294+1
        defadr DataBrowserDesc_Destroy,0x145935BC+1
        defadr List_RemoveFirst,0x143BB340+1
        defadr List_RemoveAt,0x143BB34C+1
        defadr List_Get,0x143BBB3C+1
        defadr List_GetCount,0x143BC0BC+1
        defadr List_DestroyElements,0x141E4A38+1
        defadr List_Destroy,0x14268CB8+1
        defadr List_Create,0x14268A70+1
        defadr List_InsertFirst,0x142660B4+1
        defadr List_InsertLast,0x142662A8+1
        defadr MessageBox,0x1537F0C4+1

        defadr INetworkServices_GetNetworkName,0x151B86A0+1
        defadr GetOperatorName,0x147CBCF4+1
        defadr SetOperatorName,0x147CC12C+1
        defadr GUIObject_SetTitleIcon,0x1464CB0C+1

        defadr onBackPressed,0x152F4D98+1
        defadr onLongBackPressed,0x152F4D8C+1
        defadr pg_EditPhoneName_EnterEvent,0x14F84C04+1
        defadr pg_EditPhoneName_ExitEvent,0x1511BB30+1
        defadr pg_EditPhoneName_ReturnEvent,0x152F4D7C+1

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
	BL	ReadOnFile
        CMP     R0, #0
        BNE     new_name
        LSL     R0, R4, #0
        B       exit
new_name:
        MOV     R2, #0xFF
	MOV     R1, #0
        BL      j_TextID_Create
exit:
        ADD     SP, #0x84
        POP     {R4-R7,PC}

j_TextID_Create:
        LDR     R3, =TextID_Create
        BX      R3

        END
