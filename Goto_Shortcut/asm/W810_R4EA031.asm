//W810_R4EA031

defadr  MACRO a,b
        PUBLIC a
a       EQU b
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
        defadr wstrcpy,0x44E25C34+1
        defadr wstrcat,0x44E25BD4+1
        defadr wstrcmp,0x44E25C04+1
        defadr wstrncpy,0x44E25CE8+1
        defadr strncmp,0x44E2538C+1
        defadr strcmp,0x44E252EC+1

        defadr BookObj_GetSession,0x4529FCB0+1
        defadr BookObj_SetFocus,0x4529F994+1
        defadr BookObj_GotoPage,0x4529F4CC+1
        defadr BookObj_CallPage,0x4529F5DC+1
        defadr BookObj_ReturnPage,0x4529F648+1
        defadr BookObj_GetBookID,0x4529FD0C+1
        defadr CreateBook,0x4529F750+1
        defadr FreeBook,0x4529FC78+1
        defadr FindBook,0x45531160+1

        defadr UI_Event_toBookID,0x455312AC+1
        defadr UI_Event,0x4553127C+1
        defadr UI_Event_toBookIDwData,0x455312BC+1

        defadr TextID_Create,0x452FE69C+1
        defadr TextID_GetString,0x452FF248+1
        defadr TextID_GetWString,0x452FEA1C+1

        defadr List_DestroyElements,0x4527F3B4+1
        defadr List_Destroy,0x4527EFC4+1
        defadr List_Create,0x4527EFAC+1
        defadr List_Get,0x4527F250+1
        defadr List_InsertFirst,0x4527F0C0+1
        defadr List_GetCount,0x4527F228+1
        defadr List_RemoveFirst,0x4527F148+1
        defadr List_RemoveAt,0x4527F048+1
        defadr List_InsertLast,0x4527F0D0+1

        defadr CreateListMenu,0x45170674+1
        defadr ListMenu_SetItemStyle,0x451708E8+1
        defadr ListMenu_SetItemCount,0x4517089C+1
        defadr ListMenu_SetCursorToItem,0x45170870+1
        defadr ListMenu_SetOnMessage,0x451709D8+1
        defadr ListMenu_DestroyItems,0x45170F28+1
        defadr ListMenu_SetHotkeyMode,0x45170A04+1
        defadr ListMenu_SetItemTextScroll,0x45171004+1
        defadr ListMenu_SetNoItemText,0x45170A5C+1
        defadr ListMenu_SetItemSecondLineText,0x45170C98+1
        defadr ListMenu_GetSelectedItem,0x45170884+1
        defadr GUIObject_SetTitleText,0x45193F7C+1
        defadr GUIObject_Show,0x45193E64+1
        defadr GUIObject_Destroy,0x45193BE4+1
        defadr GUIObject_GetDispObject,0x45193C40+1

        defadr GUIonMessage_GetMsg,0x45171378+1
        defadr GUIonMessage_GetBook,0x45171380+1
        defadr GUIonMessage_GetCreatedItemIndex,0x451713A4+1
        defadr GUIonMessage_SetMenuItemText,0x451713B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x451713F4+1
        defadr GUIonMessage_SetItemDisabled,0x4517144C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x451713D4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x451713E4+1
        defadr GUIonMessage_GetSelectedItem,0x45171384+1

        defadr GUIObject_SoftKeys_SetActionAndText,0x45219CDC+1
        defadr GUIObject_SoftKeys_SetAction,0x4519B824+1
        defadr GUIObject_SoftKeys_SetText,0x4519B90C+1
        defadr GUIObject_SoftKeys_SetVisible,0x4519B9A4+1

        defadr CreateYesNoQuestion,0x45196AF4+1
        defadr YesNoQuestion_SetDescriptionText,0x45196E8C+1
        defadr YesNoQuestion_SetQuestionText,0x45196E7C+1
        defadr YesNoQuestion_SetIcon,0x45196EA8+1

        defadr ImageID_Get,0x45426B54+1
        defadr ImageID_Free,0x45426B44+1

        defadr JavaDialog_Open,0x45020BF0+1
        defadr JavaDialog_Close,0x45023F98+1
        defadr JavaAppDesc_GetFirstApp,0x4501BE90+1
        defadr JavaAppDesc_GetNextApp,0x4501BE98+1
        defadr JavaAppDesc_GetJavaAppInfo,0x4501BB98+1
        defadr JavaApp_LogoImageID_Get,0x4544A3B8+1
        defadr JavaSession_GetName,0x45641594+1
        defadr JavaAppDesc_GetJavaAppID,0x450240C8+1
        defadr manifest_GetParam,0x45565E94+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x455CBD7C+1

        defadr Shortcut_Get_MenuItemIconID,0x4553B53C+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x4553B490+1
        defadr Shortcut_Get_MenuItemName,0x45641074+1
        defadr Shortcut_Run,0x45643298+1
        defadr MenuBook_Desktop,0x4553A4F0+1
        defadr BookObj_SoftKeys_SetAction,0x4554A6B0+1
        defadr BookObj_SoftKeys_SetText,0x4554A6FC+1

        defadr FILEITEM_GetFname,0x455C6A08+1
        defadr FILEITEM_GetPath,0x455C6A6C+1
        defadr FSX_MakeFullPath,0x455B6EE0+1

        defadr DataBrowser_isFileInListExt,0x455B2970+1
        defadr DataBrowserDesc_Create,0x4524A5E4+1
        defadr DataBrowserDesc_SetHeaderText,0x4524A55C+1
        defadr DataBrowserDesc_SetBookID,0x4524A498+1
        defadr DataBrowserDesc_SetFolders,0x4524A54C+1
        defadr DataBrowserDesc_SetFileExtList,0x4524A444+1
        defadr DataBrowserDesc_SetItemFilter,0x4524A43C+1
        defadr DataBrowserDesc_SetFoldersNumber,0x4524A554+1
        defadr DataBrowserDesc_SetSelectAction,0x4524A4C4+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x4524A4A0+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x4524A518+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x4524A4F4+1
        defadr DataBrowser_Create,0x45249B38+1
        defadr DataBrowserDesc_Destroy,0x4524A66C+1

        defadr CreateStringInputVA,0x45165BDC+1
        defadr StringInput_GetStringAndLen,0x45166484+1
        defadr StringInput_MenuItem_SetPriority,0x451665CC+1
        defadr StringInput_DispObject_SetText,0x452C42D0+1

        defadr CreateMessageBox,0x45533CE0+1

        EXTERN GotoShortcut

	RSEG STANDBY_SOFTKEY_LEFT
        DATA
	DCD 0x6D9

        RSEG STANDBY_LINK_LEFT
        DATA
        DCD GotoShortcut

        END
