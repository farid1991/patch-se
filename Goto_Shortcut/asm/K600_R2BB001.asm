//K600_R2BB001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20363C0C+1
        defadr memfree,0x20364D24+1
        defadr memset,0x20D66768+1
        defadr debug_printf,0x20D28E84+1

        defadr current_process,0x200A405C
        defadr get_bid,0x200A4094
        defadr set_envp,0x2006CF5E+1
        defadr get_envp,0x2006CF4A+1

        defadr wstrlen,0x2060F0E4+1
        defadr wstrcpy,0x2060F160+1
        defadr wstrcmpi,0x20610854+1
        defadr wstrcmp,0x2060F110+1
        defadr wstrncpy,0x2060F1A8+1
        defadr wstrrchr,0x20D68068+1

        defadr _fopen,0x204DBDF4+1
        defadr fread,0x204DD2F0+1
        defadr fclose,0x204DCFD4+1
        defadr fwrite,0x204DD58C+1
        defadr fstat,0x204DC6B4+1
        defadr w_diropen,0x2050A56C+1
        defadr w_chdir,0x20508C6C+1
        defadr w_dirread,0x20716280+1
        defadr w_fstat,0x208ED1D4+1
        defadr w_dirclose,0x2050A7F4+1

        defadr isKeylocked,0x20760810+1
        defadr MessageBox,0x20431AA4+1
        defadr strcmp,0x20D67710+1
        defadr GetFreeBytesOnHeap,0x20366108+1
        defadr snwprintf,0x20D67990+1
        defadr TextID_Create,0x202CFF38+1
        defadr FreeBook,0x2025D550+1
        defadr ListMenu_GetSelectedItem,0x2077CB54+1
        defadr GUIonMessage_GetMsg,0x2077D538+1
        defadr GUIonMessage_GetBook,0x2077D540+1
        defadr GUIonMessage_GetCreatedItemIndex,0x2077D564+1
        defadr GUIonMessage_SetMenuItemText,0x2077D574+1
        defadr GUIonMessage_SetMenuItemIcon,0x2077D5B4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x2077D5A4+1
        defadr CreateListMenu,0x2077C9B4+1
        defadr GUIObject_SetStyle,0x20751E64+1
        defadr GUIObject_SetTitleType,0x20751EF8+1
        defadr GUIObject_SetTitleText,0x20751F10+1
        defadr GUIObject_SetSecondRowTitleText,0x20751F2C+1
        defadr ListMenu_SetItemCount,0x2077CB70+1
        defadr ListMenu_SetOnMessage,0x2077CCA0+1
        defadr ListMenu_SetCursorToItem,0x2077CB40+1
        defadr ListMenu_SetHotkeyMode,0x2077CCCC+1
        defadr ListMenu_SetItemStyle,0x2077CBA0+1
        defadr GUIObject_SoftKeys_SetAction,0x20753704+1
        defadr GUIObject_Show,0x20751E14+1
        defadr GUIObject_Destroy,0x20280C7C+1
        defadr FindBook,0x20425C9C+1
        defadr CreateBook,0x2025CF38+1
        defadr BookObj_GotoPage,0x2025CC90+1
        defadr BookObj_SetFocus,0x2025D1C8+1
        defadr BookObj_Show,0x2025D20C+1
        defadr UI_Event,0x20425DB8+1
        defadr Display_GetTopGUI,0x20280DEC+1
        defadr REQUEST_SYSTEM_RESTART,0x20549450+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x20549440+1
        defadr FlightMode_GetState,0x2074C9D4+1
        defadr FlightMode_SetState,0x2074C9E8+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x2055527C+1
        defadr REQUEST_SETTING_SILENCE_SET,0x20554A20+1
        defadr GetSilent,0x20467A68+1
        defadr Shortcut_Run,0x20439390+1

        defadr GUIObject_GetDispObject,0x20280EC4+1
        
        defadr GUIObject_SoftKeys_SetActionAndText,0x201D2588+1
        defadr BookObj_ReturnPage,0x2025CE18+1
        defadr Shortcut_Get_MenuItemIconID,0x20439310+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x20439254+1
        defadr Shortcut_Get_MenuItemName,0x20546638+1
        defadr TextID_GetWString,0x202D03C4+1
        defadr BookObj_GetBookID,0x2025D6A4+1
        defadr MenuBook_Desktop,0x204384D0+1
        defadr BookObj_SoftKeys_SetAction,0x20426610+1
        defadr BookObj_SoftKeys_SetText,0x2042665C+1
        
        defadr FILEITEM_GetFname,0x204F0DBC+1
        defadr FILEITEM_GetPath,0x204F0EA4+1
        defadr FSX_MakeFullPath,0x204DE790+1

        defadr DataBrowser_isFileInListExt,0x204DA7AC+1
        defadr DataBrowserDesc_Create,0x201FF800+1
        defadr DataBrowserDesc_SetHeaderText,0x201FF6A8+1
        defadr DataBrowserDesc_SetBookID,0x201FF3C4+1
        defadr DataBrowserDesc_SetFolders,0x201FF660+1
        defadr DataBrowserDesc_SetFileExtList,0x201FF380+1
        defadr DataBrowserDesc_SetItemFilter,0x201FF35C+1
        defadr DataBrowserDesc_SetFoldersNumber,0x201FF684+1
        defadr DataBrowserDesc_SetSelectAction,0x201FF440+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x201FF3E8+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x201FF53C+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x201FF560+1
        defadr DataBrowser_Create,0x201FE868+1
        defadr DataBrowserDesc_Destroy,0x201FF888+1

        defadr CreateStringInputVA,0x20771048+1
        defadr StringInput_GetStringAndLen,0x20771D08+1
        defadr StringInput_DispObject_SetText,0x2029C140+1
        defadr BookObj_CallPage,0x2025CDA8+1
        
        defadr CreateYesNoQuestion,0x207572A0+1
        defadr YesNoQuestion_SetQuestionText,0x2075762C+1
        defadr YesNoQuestion_SetDescriptionText,0x2075763C+1
        defadr YesNoQuestion_SetIcon,0x20757658+1

        defadr CreateMessageBox,0x20431AF0+1
        
        defadr GUIObject_SoftKeys_SetVisible,0x20753884+1
        defadr JavaDialog_Open,0x20649954+1
        defadr JavaAppDesc_GetFirstApp,0x20643D34+1
        defadr JavaAppDesc_GetJavaAppInfo,0x20643960+1
        defadr JavaAppDesc_GetJavaAppID,0x2064D36C+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x204F5CFC+1
        defadr JavaAppDesc_GetNextApp,0x20643D58+1
        defadr JavaDialog_Close,0x2064D23C+1
        
        defadr UI_Event_toBookID,0x20425DE8+1
        defadr ImageID_Free,0x20336A54+1
        defadr JavaApp_LogoImageID_Get,0x20359D2C+1

        defadr List_Get,0x202320C4+1
        defadr List_GetCount,0x2023209C+1
        defadr List_Create,0x20231DF0+1
        defadr List_InsertLast,0x20231F44+1
        defadr List_DestroyElements,0x2023223C+1
        defadr List_Destroy,0x20231E14+1
        defadr List_RemoveFirst,0x20231FBC+1
        defadr List_InsertFirst,0x20231F34+1
        defadr List_RemoveAt,0x20231EBC+1

        EXTERN GotoShortcut

        RSEG STANDBY_SOFTKEY_LEFT
        DATA
	DCD 0x63E

        RSEG STANDBY_LINK_LEFT
        DATA
        DCD GotoShortcut

        END