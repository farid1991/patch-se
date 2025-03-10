//K800_R8BF003

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x44E4FD44+1
        defadr memfree,0x44E4FD70+1
        defadr memset,0x20003094
        defadr memcpy,0x443FCB18
        defadr debug_printf,0x4423F208+1
        defadr sprintf,0x4467A294+1
        defadr snwprintf,0x4467A85C+1
        defadr sscanf,0x443EB2A4+1
        defadr _fopen,0x44F945F0+1
        defadr fclose,0x44F95BBC+1
        defadr fread,0x44F95E44+1
        defadr fwrite,0x44F96010+1
        defadr lseek,0x44F961B8+1
        defadr _wstat,0x4498B754+1
        defadr fputs,0x452BCE40+1
        defadr fstat,0x44F94F84+1
        defadr w_diropen,0x450971A4+1
        defadr w_chdir,0x45095030+1
        defadr w_fstat,0x4498B754+1
        defadr w_dirread,0x452BD6E8+1
        defadr w_dirclose,0x45097510+1
        defadr FSX_IsFileExists,0x44FD8040+1
        defadr FSX_MakeFullPath,0x44F97808+1
        defadr FSX_FreeFullPath,0x44F97894+1
        defadr get_bid,0x44435AF4
        defadr current_process,0x44435ABC
        defadr get_envp,0x443ED0D0+1
        defadr set_envp,0x443ED0E4+1
        defadr wstrcpy,0x44F549A8+1
        defadr wstrncpy,0x44F549C0+1
        defadr wstrcat,0x44F549EC+1
        defadr wstrncat,0x44F54A08+1
        defadr wstrncmp,0x4467AFE0+1
        defadr wstrnupr,0x44F54A34+1
        defadr wstrcmp,0x44F54978+1
        defadr wstrlen,0x44F54964+1
        defadr str2wstr,0x44F55C2C+1
        defadr strcmp,0x4467A640+1
        defadr strlen,0x4467A69C+1
        defadr wstr2strn,0x44F54A84+1
        defadr wstrrchr,0x4467B068+1
        defadr wstrcmpi,0x44F55D88+1
        defadr TextID_Create,0x45446A40+1
        defadr TextID_CreateIntegerID,0x4544678C+1
        defadr TextID_GetLength,0x45446CA4+1
        defadr TextID_Destroy,0x45446C08+1
        defadr TextID_GetWString,0x45446DC4+1
        defadr TextIteratorSetTextId,0x454468CC+1
        defadr Format_Time,0x4504ADA4+1
        defadr MetaData_Desc_Create,0x4533EA14+1
        defadr MetaData_Desc_GetCoverInfo,0x4533EBC0+1
        defadr MetaData_Desc_Destroy,0x4533EAD4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x44F4DE88+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x44F4DEF0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x44F4DFA0+1
        defadr ImageID_Free,0x44F4A080+1
        defadr ImageID_GetIndirect,0x44F49800+1
        defadr BookObj_CallPage,0x453AE650+1
        defadr BookObj_GotoPage,0x453AE550+1
        defadr GetImageWidth,0x4545DD18+1
        defadr GetImageHeight,0x4545DD2C+1
        defadr get_DisplayGC,0x45461760+1
        defadr GC_PutChar,0x45462238+1
        defadr Display_GetHeight,0x45476E80+1
        defadr Display_GetWidth,0x45476E8C+1
        defadr DrawRect,0x4545CA24+1
        defadr SetFont,0x4545D780+1
        defadr DrawString,0x4545CD24+1
        defadr GC_DrawImage,0x4545CC18+1
        defadr DispObject_InvalidateRect,0x4545A060+1
        defadr DispObject_WindowSetSize,0x4545B0A0+1
        defadr DispObject_SetStyle,0x4545C360+1
        defadr GUIObject_Destroy,0x45463C74+1
        defadr CreateListMenu,0x4541D8E8+1
        defadr ListMenu_GetSelectedItem,0x4541DB04+1
        defadr ListMenu_SetItemCount,0x4541DB18+1
        defadr ListMenu_SetCursorToItem,0x4541DAF0+1
        defadr ListMenu_SetOnMessage,0x4541DC2C+1
        defadr ListMenu_SetHotKeyMode,0x4541DC58+1
        defadr ListMenu_SetItemStyle,0x4541DB54+1
        defadr ListMenu_SetHotkeyMode,0x4541DC58+1
        defadr ListMenu_SetItemTextScroll,0x4541E22C+1
        defadr ListMenu_SetNoItemText,0x4541DCA8+1
        defadr GUIonMessage_GetMsg,0x4541E5B4+1
        defadr GUIonMessage_GetBook,0x4541E5BC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x4541E5D8+1
        defadr GUIonMessage_SetMenuItemText,0x4541E5E4+1
        defadr GUIonMessage_SetMenuItemIcon,0x4541E65C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x4541E614+1
        defadr GUIObject_SetTitleType,0x45464344+1
        defadr GUIObject_SetTitleText,0x45464360+1
        defadr GUIObject_SetTitleTextAlign,0x454643B4+1
        defadr GUIObject_SetSecondRowTitleText,0x4546437C+1
        defadr GUIObject_SetStyle,0x45463F34+1
        defadr GUIObject_Show,0x45463EE4+1
        defadr GUIObject_SetFocus,0x45463E90+1
        defadr GUIObject_SoftKeys_SetAction,0x454806E0+1
        defadr GUIObject_SoftKeys_SetText,0x45480758+1
        defadr GUIObject_SoftKeys_SetVisible,0x454807A8+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x45480838+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x45480A7C+1
        defadr DispObject_SoftKeys_RemoveBackground,0x4547D5CC+1
        defadr Shortcut_Run,0x4548D810+1
        defadr Shortcut_Get_MenuItemIconID,0x454854C0+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x454853A8+1
        defadr Shortcut_Get_MenuItemName,0x4548C448+1
        defadr MenuBook_Desktop,0x45485218+1
        defadr BookObj_SoftKeys_SetAction,0x4547B8CC+1
        defadr BookObj_SoftKeys_SetText,0x4547B904+1
        defadr FILEITEM_GetFname,0x44FDC464+1
        defadr FILEITEM_GetPath,0x44FDC518+1
        defadr DataBrowser_isFileInListExt,0x44F929D0+1
        defadr DataBrowserDesc_Create,0x44FD1F28+1
        defadr DataBrowserDesc_SetHeaderText,0x44FD222C+1
        defadr DataBrowserDesc_SetBookID,0x44FD2138+1
        defadr DataBrowserDesc_SetFolders,0x44FD2214+1
        defadr DataBrowserDesc_SetFileExtList,0x44FD20E8+1
        defadr DataBrowserDesc_SetItemFilter,0x44FD20E0+1
        defadr DataBrowserDesc_SetFoldersNumber,0x44FD221C+1
        defadr DataBrowserDesc_SetSelectAction,0x44FD215C+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x44FD2140+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x44FD21CC+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x44FD21D4+1
        defadr DataBrowser_Create,0x44FCE548+1
        defadr DataBrowserDesc_Destroy,0x44FD1FDC+1
        defadr CreateStringInput,0x453F5BD0+1
        defadr StringInput_SetText,0x453F66B8+1
        defadr StringInput_SetMode,0x453F64C0+1
        defadr StringInput_SetEnableEmptyText,0x453F6634+1
        defadr StringInput_SetMinLen,0x453F6518+1
        defadr StringInput_SetMaxLen,0x453F65B8+1
        defadr StringInput_SetActionOK,0x453F650C+1
        defadr StringInput_SetActionBack,0x453F6510+1
        defadr StringInput_GetStringAndLen,0x453F6538+1
        defadr StringInput_MenuItem_SetPriority,0x453F6694+1
        defadr CreateYesNoQuestion,0x454746CC+1
        defadr YesNoQuestion_SetQuestionText,0x45474A78+1
        defadr YesNoQuestion_SetDescriptionText,0x45474A88+1
        defadr YesNoQuestion_SetIcon,0x45474AA8+1
        defadr CreateMessageBox,0x453B9A54+1
        defadr CreateBook,0x453AE7D4+1
        defadr FreeBook,0x453AEDF0+1
        defadr BookObj_GetBookID,0x453AEEB0+1
        defadr BookObj_SetFocus,0x453AEA80+1
        defadr BookObj_ReturnPage,0x453AE6B8+1
        defadr FindBook,0x453ACE94+1
        defadr FindBookByID,0x453ACE60+1
        defadr UI_Event,0x453AD25C+1
        defadr UI_Event_toBookID,0x453AD2B4+1
        defadr JavaDialog_Open,0x44FAA690+1
        defadr JavaAppDesc_GetFirstApp,0x44FA40A8+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44FA3CC8+1
        defadr JavaAppDesc_GetJavaAppID,0x44FAE264+1
        defadr JavaAppDesc_GetNextApp,0x44FA40B0+1
        defadr JavaDialog_Close,0x44FAE144+1
        defadr JavaApp_LogoImageID_Get,0x45074AE8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x4507F200+1
        defadr List_Create,0x452BF5F0+1
        defadr List_Destroy,0x452BF62C+1
        defadr List_DestroyElements,0x452BFA04+1
        defadr List_InsertLast,0x452BF7A8+1
        defadr List_Get,0x452BF8C4+1
        defadr List_GetCount,0x452BF898+1
        defadr List_RemoveAt,0x452BF72C+1
        defadr List_InsertFirst,0x452BF7A0+1
        defadr List_RemoveFirst,0x452BF7F8+1
        defadr Display_GetTopBook,0x453AE040+1
	defadr DataBrowserDesc_SetOpenEmptyFolder,0x44FD22E8+1
	defadr DataBrowserDesc_SetActions,0x44FD21EC+1
        defadr DataBrowserDesc_SetDefaultActions,0x44FD21B8+1

        EXTERN GotoShortcut

        RSEG STANDBY_SOFTKEY
        DATA
        DCD 0x8C2

        RSEG STANDBY_LINK
        DATA
        DCD GotoShortcut

        END
