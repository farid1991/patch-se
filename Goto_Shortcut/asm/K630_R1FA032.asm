//K630_R1FA032

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x10098358
        defadr memfree,0x10098380
        defadr memset,0x2A1C07A0
        defadr memcpy,0x100B83F4

        defadr set_envp,0x100A3080+1
        defadr get_envp,0x100A306C+1

        defadr snwprintf,0x104E3DB4+1
        defadr wstrlen,0x10F75F1C+1
        defadr wstrncmp,0x104E4548+1
        defadr wstrcpy,0x10F75F60+1
        defadr wstrcmpi,0x10F77380+1
        defadr wstrcmp,0x10F75F30+1
        defadr wstrrchr,0x10F772A0+1
        defadr wstrncpy,0x10F75F78+1
        defadr str2wstr,0x10F771E4+1
        defadr strlen,0x104E3BE4+1
        defadr strstr,0x104E3CF0+1
        defadr strncmp,0x104E3C20+1
        defadr strcpy,0x104E3BB0+1
        defadr strcmp,0x104E3B88+1

        defadr w_diropen,0x10098128
        defadr w_chdir,0x10098180
        defadr w_dirclose,0x10098168
        defadr w_dirread,0x113BFE80+1
        defadr w_fstat,0x1077F130+1
        
        defadr fstat,0x10F85398+1
        defadr _fopen,0x10F84AA0+1
        defadr fread,0x10F861E4+1
        defadr fwrite,0x10F863B0+1
        defadr fclose,0x11542130+1

        defadr List_DestroyElements,0x113C08D8+1
        defadr List_Destroy,0x113C05EC+1
        defadr List_Create,0x113C05C4+1
        defadr List_Get,0x113C07E4+1
        defadr List_GetCount,0x113C07B8+1
        defadr List_InsertFirst,0x113C0738+1
        defadr List_InsertLast,0x113C0740+1
        defadr List_RemoveAt,0x113C06C4+1
        defadr List_RemoveFirst,0x113C0790+1

        defadr GUIonMessage_GetMsg,0x115ECC20+1
        defadr GUIonMessage_GetBook,0x115ECC28+1
        defadr GUIonMessage_GetCreatedItemIndex,0x115ECC44+1
        defadr GUIonMessage_SetMenuItemText,0x115ECC50+1
        defadr GUIonMessage_SetMenuItemIcon,0x115ECC90+1
        defadr GUIonMessage_SetItemDisabled,0x115ECCF0+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x115ECC70+1
        defadr GUIonMessage_GetSelectedItem,0x115ECC2C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x115ECC80+1

        defadr CreateListMenu,0x115EBF18+1
        defadr ListMenu_SetOnMessage,0x115EC258+1
        defadr ListMenu_SetItemCount,0x115EC148+1
        defadr ListMenu_SetCursorToItem,0x115EC120+1
        defadr ListMenu_SetNoItemText,0x115EC2D8+1
        defadr ListMenu_GetSelectedItem,0x115EC134+1
        defadr ListMenu_SetItemStyle,0x115EC184+1
        defadr ListMenu_SetItemTextScroll,0x115EC888+1
        defadr ListMenu_SetHotkeyMode,0x115EC284+1

        defadr GUIObject_SetTitleText,0x1163AF2C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10F11B48+1
        defadr GUIObject_Show,0x1163AA00+1
        defadr GUIObject_Destroy,0x1163A804+1
        defadr GUIObject_SoftKeys_SetEnable,0x116542CC+1
        defadr GUIObject_SoftKeys_SetText,0x116541DC+1
        defadr GUIObject_SoftKeys_SetAction,0x11654164+1
        defadr GUIObject_SoftKeys_SetVisible,0x11654260+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x11654300+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x11654510+1

        defadr CreateBook,0x1159763C+1
        defadr FindBook,0x11595714+1
        defadr CreateMessageBox,0x1159D37C+1
        defadr BookObj_ReturnPage,0x1159751C+1
        defadr BookObj_GotoPage,0x115973B4+1
        defadr BookObj_CallPage,0x115974B4+1
        defadr BookObj_SetFocus,0x115978DC+1
        defadr BookObj_GetBookID,0x11597CF4+1
        defadr FreeBook,0x11597C48+1
        defadr UI_Event_toBookID,0x115964DC+1
        defadr UI_Event,0x11596484+1
        defadr UI_Event_toBookIDwData,0x115964F0+1

        defadr TextID_Create,0x11617FF0+1
        defadr TextID_CreateIntegerID,0x11617E30+1
        defadr TextID_GetWString,0x1161845C+1
        defadr MessageBox,0x1159D330+1

        defadr IsVolumeControllerBook,0x11673CC0+1
        defadr IsRightNowBook,0x11663A34+1

        defadr JavaDialog_Open,0x10F9F3A4+1
        defadr JavaAppDesc_GetFirstApp,0x10F953B0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10F94EBC+1
        defadr JavaApp_LogoImageID_Get,0x1107E240+1
        defadr JavaAppDesc_GetNextApp,0x10F953B8+1
        defadr JavaDialog_Close,0x10FA2A80+1
        defadr JavaSession_GetName,0x111072B0+1
        defadr manifest_GetParam,0x10F92170+1
        defadr JavaAppDesc_GetJavaAppID,0x10FA2BA0+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x110897F8+1

        defadr DataBrowser_isFileInListExt,0x10F82ECC+1
        defadr DataBrowserDesc_Create,0x10FCBA54+1
        defadr DataBrowserDesc_SetHeaderText,0x10FCBD04+1
        defadr DataBrowserDesc_SetBookID,0x10FCBC54+1
        defadr DataBrowserDesc_SetFolders,0x10FCBCEC+1
        defadr DataBrowserDesc_SetFileExtList,0x10FCBC00+1
        defadr DataBrowserDesc_SetItemFilter,0x10FCBBF8+1
        defadr DataBrowserDesc_SetFoldersNumber,0x10FCBCF4+1
        defadr DataBrowserDesc_SetSelectAction,0x10FCBC70+1
        defadr DataBrowser_Create,0x10FC7F64+1
        defadr DataBrowserDesc_Destroy,0x10FCBB04+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x10FCBC5C+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x10FCBCB8+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x10FCBCC0+1

        defadr Shortcut_Get_MenuItemIconID,0x1165A720+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x11659B84+1
        defadr Shortcut_Get_MenuItemName,0x116659B0+1
        defadr Shortcut_Run,0x1165AC10+1
        defadr MenuBook_Desktop,0x1165A530+1
        defadr BookObj_SoftKeys_SetAction,0x1164E9CC+1
        defadr BookObj_SoftKeys_SetText,0x1164EA04+1

        defadr FILEITEM_GetFname,0x10FD4BAC+1
        defadr FILEITEM_GetPath,0x10FD4C40+1
        defadr FSX_MakeFullPath,0x10F87F14+1

        defadr CreateStringInput,0x115C9D8C+1
        defadr StringInput_SetText,0x115CA83C+1
        defadr StringInput_SetMode,0x115CA62C+1
        defadr StringInput_SetEnableEmptyText,0x115CA7AC+1
        defadr StringInput_SetMinLen,0x115CA688+1
        defadr StringInput_SetMaxLen,0x115CA738+1
        defadr StringInput_SetActionOK,0x115CA67C+1
        defadr StringInput_SetActionBack,0x115CA680+1
        defadr StringInput_GetStringAndLen,0x115CA6B8+1
        defadr StringInput_MenuItem_SetPriority,0x115CA80C+1

        defadr CreateYesNoQuestion,0x11649890+1
        defadr YesNoQuestion_SetQuestionText,0x11649C14+1
        defadr YesNoQuestion_SetDescriptionText,0x11649C24+1
        defadr YesNoQuestion_SetIcon,0x11649C44+1

        defadr ImageID_Free,0x10F6F53C+1


        EXTERN GotoShortcut

        RSEG STANDBY_SOFTKEY_RIGHT
        DATA
	DCD 0x2CB0

        RSEG STANDBY_LINK_RIGHT
        DATA
        DCD GotoShortcut

        END
