//U10_R7AA071

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr debug_printf,0x4FC00008
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr memset,0x140E2D1C
        defadr get_envp,0x1029A4E4+1
	defadr set_envp,0x1029A4F8+1
        defadr wstrlen,0x141B2BB4+1
        defadr wstrcpy,0x1481DAD8+1
        defadr wstrcmpi,0x141B2F68+1
        defadr w_diropen,0x4FFA7DEC
        defadr w_chdir,0x4FFA7E44
        defadr snwprintf,0x1481CAFC+1
        defadr w_dirread,0x10283CC4
        defadr w_fstat,0x10147204+1
        defadr w_dirclose,0x4FC001A4
        defadr GUIonMessage_GetMsg,0x146C8FE8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x146C8C18+1
        defadr TextID_Create,0x14530A4C+1
        defadr GUIonMessage_SetMenuItemText,0x143A2F18+1
        defadr wstrcmp,0x141B2C1C+1
        defadr GUIonMessage_SetMenuItemIcon,0x14533244+1
        defadr GUIObject_Destroy,0x1459AF78+1
        defadr ListMenu_GetSelectedItem,0x14623F80+1
        defadr wstrncpy,0x1481DAEA+1
        defadr GUIObject_GetDispObject,0x145F106C+1
        defadr StringInput_DispObject_SetText,0x14575C0C+1
        defadr wstrrchr,0x141B2BC8+1
        defadr CreateListMenu,0x146628FC+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr ListMenu_SetItemCount,0x1415CAB0+1
	defadr ListMenu_SetCursorToItem,0x1415C5E0+1
        defadr ListMenu_SetOnMessage,0x146C7760+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x156B3298+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_Show,0x146C5748+1
        defadr BookObj_ReturnPage,0x14101C54+1
        defadr FindBook,0x143D2CB0+1
        defadr BookObj_SetFocus,0x146613E0+1
        defadr Shortcut_Get_MenuItemIconID,0x1407B614+1
        defadr FreeBook,0x141016DC+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x151AB5D0+1
        defadr Shortcut_Get_MenuItemName,0x1415D25C+1
        defadr TextID_GetWString,0x142B9B80+1
        defadr BookObj_GetBookID,0x143D2C00+1
        defadr MenuBook_Desktop,0x1415D90C+1
        defadr BookObj_SoftKeys_SetAction,0x140E245C+1
        defadr BookObj_SoftKeys_SetText,0x150D7C1C+1
        defadr CreateStringInput,0x1444B96C+1
        defadr StringInput_SetMode,0x140E2918+1
        defadr StringInput_SetEnableEmptyText,0x15196E54+1
        defadr StringInput_SetText,0x14575BB8+1
        defadr StringInput_SetMinLen,0x1444B698+1
        defadr StringInput_SetMaxLen,0x1444BA3C+1
        defadr StringInput_SetActionOK,0x1444BBB0+1
        defadr StringInput_SetActionBack,0x1444BBAC+1
        defadr StringInput_GetStringAndLen,0x14660914+1
        defadr StringInput_MenuItem_SetPriority,0x14575878+1
        defadr BookObj_CallPage,0x14101A24+1
        defadr List_RemoveFirst,0x143D1F94+1
        defadr GUIonMessage_GetBook,0x146C9190+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1412D4D4+1
        defadr ListMenu_SetItemStyle,0x146765A4+1
        defadr BookObj_GotoPage,0x1459A190+1
        defadr List_InsertFirst,0x14272738+1
        defadr List_Get,0x143D2790+1
        defadr strcmp,0x1029B60C+1
        defadr List_RemoveAt,0x143D1FA0+1
        defadr List_GetCount,0x143D2D10+1
        defadr CreateYesNoQuestion,0x140E2BCC+1
        defadr YesNoQuestion_SetDescriptionText,0x144A23F8+1
	defadr YesNoQuestion_SetQuestionText,0x145ED8A4+1
	defadr YesNoQuestion_SetIcon,0x144A23EC+1
        defadr CreateMessageBox,0x147A0C28+1
        defadr ListMenu_SetItemTextScroll,0x14313144+1
        defadr ListMenu_SetHotkeyMode,0x14676678+1
        defadr ListMenu_SetNoItemText,0x1535CE50+1
        defadr GUIObject_SoftKeys_SetVisible,0x143A94C0+1
        defadr CreateBook,0x1415DBEC+1
        defadr UI_Event,0x14274868+1
        defadr UI_Event_toBookID,0x1463FD98+1
        defadr DataBrowserDesc_Create,0x145B2E18+1
	defadr DataBrowserDesc_SetHeaderText,0x145B2EBC+1
	defadr DataBrowserDesc_SetBookID,0x145B2D58+1
	defadr DataBrowserDesc_SetFolders,0x145B2EB4+1
	defadr DataBrowserDesc_SetFoldersNumber,0x145B2D68+1
        defadr DataBrowserDesc_SetSelectAction,0x145B2EAC+1
	defadr DataBrowserDesc_Menu_AddFSFunctions,0x151B81E8+1
	defadr DataBrowserDesc_Menu_AddNewFolder, 0x145B2E10+1
	defadr DataBrowserDesc_Menu_AddMarkFiles,0x145B2D60+1
	defadr DataBrowser_Create,0x1416C6CC+1
	defadr DataBrowserDesc_Destroy,0x145B2EC4+1
        defadr Shortcut_Run,0x14307EE0+1
        defadr List_DestroyElements,0x141F01D8+1
        defadr List_Destroy,0x142754E4+1
        defadr _fopen,0x146EE4EC+1
	defadr fread,0x141B254C+1
	defadr fclose,0x1463D0D0+1
	defadr fwrite,0x146EF4A0+1
	defadr fstat,0x141F09F0+1
        defadr List_Create,0x142751FC+1
        defadr List_InsertLast,0x1427292C+1

////////

        EXTERN GotoShortcut

	//RSEG STANDBY_SOFTKEY_LEFT
        //DATA
	//DCD 0x2CB0

        //RSEG STANDBY_SOFTKEY_RIGHT
        //DATA
	//DCD 0x2CB0

        RSEG STANDBY_LINK_RIGHT
        DATA
        DCD GotoShortcut

        END
