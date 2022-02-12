//W350_R11CA002

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr memset,0x20105B58
        defadr debug_printf,0x2086B1D0+1
        defadr snwprintf,0x20380BC4+1
        defadr _fopen,0x20C86CB4+1
        defadr fread,0x20C88340+1
        defadr fclose,0x20C880EC+1
        defadr fwrite,0x20C8850C+1
        defadr fstat,0x20C875A0+1
        defadr w_diropen,0x20D76378+1
        defadr w_chdir,0x20D7458C+1
        defadr w_dirread,0x20F7184C+1
        defadr w_fstat,0x2067F638+1
        defadr w_dirclose,0x20D76628+1
        defadr set_envp,0x20144BD4+1
        defadr get_envp,0x20144BC0+1
        defadr BookObj_GetSession,0x210556B4+1
        defadr TextID_GetString,0x210EC274+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x20C424C4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x20C4252C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x20C425DC+1
        defadr FSX_IsFileExists,0x20CC7C34+1
        defadr get_DisplayGC,0x21101BF4+1
        defadr GC_PutChar,0x21102714+1
        defadr DrawRect,0x210FCE28+1
        defadr GetImageHeight,0x210FE238+1
        defadr GetImageWidth,0x210FE224+1
        defadr SetFont,0x210FDBA0+1
        defadr DrawString,0x210FD128+1
        defadr wstrcpy,0x20381198+1
        defadr TextID_Destroy,0x210EBF00+1
        defadr DispObject_GetGUI,0x210F9E84+1
        defadr FindBook,0x21053808+1
        defadr TextID_CreateIntegerID,0x210EBAD0+1
        defadr TextID_Copy,0x210EBE10+1
        defadr Display_GetWidth,0x211170B4+1
        defadr MainDisplay_GetTopBook,0x210548A4+1
        defadr GUIObject_GetDispObject,0x21103F38+1
        defadr Display_GetHeight,0x211170A8+1
        defadr DispObject_WindowSetSize,0x210FB560+1
        defadr DispObject_SetLayerColor,0x210FC31C+1
        defadr DispObject_SetAnimation,0x210FC3D0+1
        defadr TextID_Create,0x210EBC80+1
        defadr TextID_GetWString,0x210EC13C+1
        defadr CreateMessageBox,0x21060634+1
        defadr GUIObject_SoftKeys_SetAction,0x21120904+1
        defadr GUIObject_SoftKeys_SetVisible,0x211209CC+1
        defadr GUIObject_SoftKeys_SetText,0x2112097C+1
        defadr GUIObject_SoftKeys_SetEnable,0x21120A38+1
        defadr GUIObject_GetBook,0x21103F4C+1

        defadr ConnectionManager_Connection_GetState,0x20F85F38+1
        defadr iconidname2id,0x20A453CC+1
        defadr ImageID_Free,0x20C3E70C+1

        defadr Find_StandbyBook,0x21068628+1
        defadr BookObj_SetFocus,0x210552FC+1
        defadr BookObj_GetBookID,0x21055714+1
        defadr UI_Event_toBookID,0x21053BF4+1
        defadr UI_Event_toBookIDwData,0x21053C08+1
        defadr UI_Event,0x21053B9C+1
        defadr MessageBox,0x210605E8+1
        defadr FreeBook,0x2105566C+1
        defadr CreateBook,0x2105506C+1
        defadr BookObj_ReturnPage,0x21054F50+1
        defadr BookObj_CallPage,0x21054EE8+1
        defadr BookObj_GotoPage,0x21054DE8+1
        defadr Shortcut_Get_MenuItemIconID,0x21125A34+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x21125930+1
        defadr Shortcut_Get_MenuItemName,0x2112CA08+1
        defadr MenuBook_Desktop,0x211257B8+1
        defadr BookObj_SoftKeys_SetAction,0x2111B9A0+1
        defadr BookObj_SoftKeys_SetText,0x2111B9D8+1

        defadr wstrlen,0x20C48D0C+1
        defadr wstrncmp,0x20381210+1
        defadr wstrcmpi,0x20C4A130+1
        defadr wstrcmp,0x20C48D20+1
        defadr wstrncpy,0x20C48D68+1
        defadr wstrrchr,0x20381298+1
        defadr str2wstr,0x20C49FD4+1
        defadr strlen,0x20380A04+1
        defadr strstr,0x20380B0C+1
        defadr strcpy,0x203809D0+1
        defadr strcmp,0x203809A8+1
        defadr strncmp,0x20380A40+1

        defadr GUIonMessage_GetMsg,0x210C3CA0+1
        defadr GUIonMessage_GetBook,0x210C3CA8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x210C3CC4+1
        defadr GUIonMessage_SetMenuItemText,0x210C3CD0+1
        defadr GUIonMessage_SetMenuItemIcon,0x210C3D48+1
        defadr GUIonMessage_SetItemDisabled,0x210C3D6C
        defadr GUIonMessage_SetMenuItemUnavailableText,0x210C3CF0+1
        defadr GUIonMessage_GetSelectedItem,0x210C3CAC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x210C3D00+1
        defadr GetFreeBytesOnHeap,0x20DACCB0+1
        defadr CreateListMenu,0x210C2F7C+1
        defadr ListMenu_SetOnMessage,0x210C32BC+1
        defadr ListMenu_SetItemCount,0x210C3190+1
        defadr ListMenu_SetCursorToItem,0x210C3168+1
        defadr ListMenu_GetSelectedItem,0x210C317C+1
        defadr ListMenu_SetItemTextScroll,0x210C38F0+1
        defadr ListMenu_SetItemStyle,0x210C31CC+1
        defadr ListMenu_SetHotkeyMode,0x210C32E8+1
        defadr GUIObject_TabTitleRemove,0x210C3900+1

        defadr DispObject_GetOnKey,0x210F63A0+1
        defadr DispObject_GetDESC,0x20EEC090+1
        defadr DISP_DESC_SetOnKey,0x210F62D0+1
        defadr ListMenu_SetNoItemText,0x210C3360+1
        defadr GUIObject_SetTitleText,0x21104674+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x20BF1B54+1
        defadr GUIObject_Show,0x21104138+1

        defadr REQUEST_SYSTEM_SHUTDOWN,0x2106B318+1
        defadr REQUEST_SYSTEM_RESTART,0x2106B328+1
        defadr Shortcut_Run,0x2112DDE8+1
        defadr FlightGetState,0x2107AA28+1
        defadr FlightControl,0x1160E8CC+1
        defadr Request_ICA_ShutdownAllConnections,0x20663B58+1
        defadr Display_GetBrightness,0x211054A4+1

        defadr List_DestroyElements,0x20F739D0+1
        defadr List_Destroy,0x20F73630+1
        defadr List_Create,0x20F7360C+1
        defadr List_Get,0x20F7388C+1
        defadr List_GetCount,0x20F73860+1
        defadr root_list_get_session_count,0x21053908+1
        defadr root_list_get_session,0x21053914+1
        defadr List_InsertFirst,0x20F73768+1
        defadr List_InsertLast,0x20F73770+1
        defadr List_RemoveAt,0x20F736F8+1
        defadr List_RemoveFirst,0x20F737C0+1

        defadr FILEITEM_GetFname,0x20CCB90C+1
        defadr FILEITEM_GetPath,0x20CCB998+1
        defadr FSX_MakeFullPath,0x20C89BC0+1

        defadr IsVolumeControllerBook,0x21067CE8+1
        defadr IsRightNowBook,0x21129E8C+1

        defadr JavaDialog_Open,0x20C9B9E8+1
        defadr JavaAppDesc_GetFirstApp,0x20C95748+1
        defadr JavaAppDesc_GetJavaAppInfo,0x20C9537C+1
        defadr JavaApp_LogoImageID_Get,0x20D56F6C+1
        defadr JavaAppDesc_GetNextApp,0x20C95750+1
        defadr JavaDialog_Close,0x20C9F268+1
        defadr JavaSession_GetName,0x20ED384C+1
        defadr JavaAppDesc_GetJavaAppID,0x20C9F388+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x20D61064+1
        defadr manifest_GetParam,0x21024398+1

        defadr GUIObject_Destroy,0x21103ECC+1
        defadr NewEvents_GetCount,0x2112B414+1

        defadr GUIObject_SetStyle,0x21104188+1
        defadr TabMenuBar_GetFocusedTab,0x21105034+1
        defadr TabMenuBar_SetTabGui,0x211050F4+1
        defadr TabMenuBar_SetTabTitle,0x2110515C+1
        defadr TabMenuBar_SetOnTabSwitch,0x21105188+1

        defadr StringInput_SetText,0x2109C6E8+1
        defadr CreateStringInput,0x2109BC48+1
        defadr StringInput_SetMode,0x2109C4F0+1
        defadr StringInput_SetEnableEmptyText,0x2109C664+1
        defadr StringInput_SetMinLen,0x2109C548+1
        defadr StringInput_SetMaxLen,0x2109C5E8+1
        defadr StringInput_SetActionOK,0x2109C53C+1
        defadr StringInput_SetActionBack,0x2109C540+1
        defadr StringInput_GetStringAndLen,0x2109C568+1
        defadr StringInput_MenuItem_SetPriority,0x2109C6C4+1
        
        defadr CreateYesNoQuestion,0x21114964+1
        defadr YesNoQuestion_SetQuestionText,0x21114CCC+1
        defadr YesNoQuestion_SetDescriptionText,0x21114CDC+1
        defadr YesNoQuestion_SetIcon,0x21114CFC+1

        defadr DataBrowser_isFileInListExt,0x20C85380+1
        defadr DataBrowserDesc_Create,0x20CC1AF8+1
        defadr DataBrowserDesc_SetHeaderText,0x20CC1DA4+1
        defadr DataBrowserDesc_SetBookID,0x20CC1CD0+1
        defadr DataBrowserDesc_SetFolders,0x20CC1D8C+1
        defadr DataBrowserDesc_SetFileExtList,0x20CC1C80+1
        defadr DataBrowserDesc_SetItemFilter,0x20CC1C78+1
        defadr DataBrowserDesc_SetFoldersNumber,0x20CC1D94+1
        defadr DataBrowserDesc_SetSelectAction,0x20CC1CF4+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x20CC1CD8+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x20CC1D4C+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x20CC1D54+1
        defadr DataBrowser_Create,0x20CBE5BC+1
        defadr DataBrowserDesc_Destroy,0x20CC1B94+1

        EXTERN GotoShortcut

	RSEG STANDBY_SOFTKEY_LEFT
        DATA
	DCD 0x997

        RSEG STANDBY_LINK_LEFT
        DATA
        DCD GotoShortcut

        END
