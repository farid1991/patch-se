//J20_R7CA064

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM

        defadr debug_printf,0x4BC00008
        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145D9ECC
        defadr CoCreateInstance,0x144FB65C+1
        defadr TextObject_SetText,0x14280D48+1
        defadr TextObject_SetFont,0x144BCE70+1
        defadr get_DisplayGC,0x142D60A8+1
        defadr DisplayGC_AddRef,0x1437CB6C+1
        defadr _fopen,0x1420C904+1
        defadr fread,0x1429733C+1
        defadr fclose,0x1459B9F0+1
        defadr fwrite,0x142978D0+1
        defadr fstat,0x145CEE28+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14815408+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x14D66FC0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14CA0FD0+1
        defadr Display_SetBrightness,0x148411CC+1
        defadr SaveBrightness,0x14FE954C+1
        defadr Display_GetBrightness,0x14B10980+1
        defadr DispObject_SetLayerColor,0x1457A1EC+1
        defadr DispObject_InvalidateRect,0x144E7D00+1
        defadr DISP_DESC_SetName,0x1449B4A0+1
        defadr DISP_DESC_SetSize,0x1449B49C+1
        defadr DISP_DESC_SetOnCreate,0x1449B514+1
        defadr DISP_DESC_SetOnClose,0x1449B4A4+1
        defadr DISP_DESC_SetOnRedraw,0x1449B498+1
        defadr DISP_DESC_SetOnLayout,0x1449B5EC+1
        defadr DISP_DESC_SetOnKey,0x1449B024+1
        defadr GUIObject_Create,0x14180798+1
        defadr BookObj_AddGUIObject,0x1418078C+1
        defadr GUIObject_SetTitleType,0x14400FC0+1
        defadr GUIObject_SoftKeys_SetAction,0x1456E1B4+1
        defadr GUIObject_SoftKeys_SetText,0x1456D190+1
        defadr GUIObject_SoftKeys_SetVisible,0x142D7C80+1
        defadr GUIObject_Show,0x14181538+1
        defadr snwprintf,0x145D8E20+1
        defadr sscanf,0x101A4BD0+1
        defadr TextID_Create,0x145CC91C+1
        defadr TextID_Destroy,0x145CBF78+1
        defadr TextID_GetWString,0x145CBF00+1
        defadr TextID_CreateIntegerID,0x14283F10+1
        defadr DynamicMenu_SetElement_SecondLineText,0x14B10B88+1
        defadr Display_GetWidth,0x144E6CD0+1
        defadr Display_GetHeight,0x144E6CE0+1
        defadr set_envp,0x101A246C+1
        defadr get_envp,0x101A2458+1
        defadr w_fstat,0x1003093C+1
        defadr w_diropen,0x4BC00164
        defadr w_chdir,0x4BFB7180
        defadr w_dirread,0x14AD1464+1
        defadr w_dirclose,0x4BC001A4
        defadr wstrlen,0x14296C80+1
        defadr wstrcpy,0x145D9EEC+1
        defadr wstrncpy,0x145D9EFE+1
        defadr wstrcmp,0x14296A60+1
        defadr wstrncmp,0x145D9F84+1
        defadr wstrcmpi,0x145CD8AC+1
        defadr wstrrchr,0x14296C08+1
        defadr wstrnupr,0x1452D610+1
        defadr FSX_IsFileExists,0x149CD5A8+1
        defadr FileDelete,0x140DEAB0+1
        defadr FileCopy,0x144DDB7C+1
        defadr MessageBox,0x153A65E0+1
        defadr CreateMessageBox,0x1490F1E8+1
        defadr GetURIScheme,0x14227E3C+1
        defadr CreateURI,0x14228000+1
        defadr Browser_OpenURI,0x14B6AB90+1
        defadr ThemeImage_Apply,0x14BF495C+1
        defadr MainMenu_SetFromUserTheme,0x148A7634+1
        defadr strcmp,0x101A34E8+1
        defadr CreateBook,0x1417FFAC+1
        defadr FindBook,0x1446C6A8+1
        defadr FindBookByID,0x1446C608+1
        defadr UI_Event,0x14023B9C+1
        defadr FreeBook,0x141800F0+1
        defadr BookObj_SetFocus,0x1417E4B8+1
        defadr BookObj_GotoPage,0x14051800+1
        defadr BookObj_ReturnPage,0x14235190+1
        defadr BookObj_CallPage,0x148FB4EC+1
        defadr BookObj_GetBookID,0x1446C764+1
        defadr UI_Event_toBookID,0x14181A84+1
        defadr CreateListMenu,0x14180708+1
        defadr ListMenu_SetItemCount,0x140DBDF4+1
        defadr ListMenu_SetCursorToItem,0x140033DC+1
        defadr ListMenu_SetHotkeyMode,0x14182AB0+1
        defadr ListMenu_SetTexts,0x1456B7B0+1
        defadr ListMenu_SetOnMessage,0x143D5068+1
        defadr ListMenu_GetSelectedItem,0x1437B204+1
        defadr ListMenu_SetItemTextScroll,0x1437A778+1
        defadr ListMenu_SetNoItemText,0x14811680+1
        defadr ListMenu_SetItemStyle,0x141829F0+1
        defadr GUIonMessage_GetMsg,0x14022620+1
        defadr GUIonMessage_GetBook,0x1437A1F0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x14022854+1
        defadr GUIonMessage_SetMenuItemText,0x14022B40+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1419AEF4+1
        defadr GUIonMessage_SetMenuItemIcon,0x1437B884+1
        defadr GUIObject_SetTitleText,0x14054A00+1
        defadr GUIObject_SetStyle,0x143FFB48+1
        defadr GUIObject_Destroy,0x145681C0+1
        defadr Shortcut_Get_MenuItemIconID,0x14181180+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x14B40E88+1
        defadr Shortcut_Get_MenuItemName,0x14A32088+1
        defadr MenuBook_Desktop,0x147E3B1C+1
        defadr Shortcut_Run,0x1485BE4C+1
        defadr BookObj_SoftKeys_SetAction,0x141D9C9C+1
        defadr BookObj_SoftKeys_SetText,0x146D1304+1
        defadr CreateStringInput,0x14BD0704+1
        defadr StringInput_SetMode,0x14BD05A0+1
        defadr StringInput_SetText,0x14A00994+1
        defadr StringInput_SetEnableEmptyText,0x14C07698+1
        defadr StringInput_SetMinLen,0x14BD0378+1
        defadr StringInput_SetMaxLen,0x14A00A54+1
        defadr StringInput_SetActionOK,0x148112A0+1
        defadr StringInput_SetActionBack,0x14811334+1
        defadr StringInput_GetStringAndLen,0x141B4228+1
        defadr StringInput_MenuItem_SetPriority,0x14A0054C+1
        defadr CreateYesNoQuestion,0x149B3D84+1
        defadr YesNoQuestion_SetQuestionText,0x149B3D64+1
        defadr YesNoQuestion_SetDescriptionText,0x149B3C08+1
        defadr YesNoQuestion_SetIcon,0x149B3C28+1
        defadr DataBrowserDesc_Create,0x14CE407C+1
        defadr DataBrowserDesc_SetHeaderText,0x14CE3DE4+1
        defadr DataBrowserDesc_SetBookID,0x14CE3FEC+1
        defadr DataBrowserDesc_SetFolders,0x14CE3FF4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x14CE3FE4+1
        defadr DataBrowserDesc_SetSelectAction,0x14CE3DEC+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x1484E544+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x14CE4510+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x14CE4134+1
        defadr DataBrowser_Create,0x14CE3318+1
        defadr DataBrowserDesc_Destroy,0x14CE3F90+1
        defadr List_InsertFirst,0x143B4AA8+1
        defadr List_InsertLast,0x1446C81C+1
        defadr List_RemoveAt,0x145CD194+1
        defadr List_RemoveFirst,0x145CD188+1
        defadr List_DestroyElements,0x1456E73C+1
        defadr List_Destroy,0x1404FE2C+1
        defadr List_Create,0x142D7608+1
        defadr List_Get,0x1446CD44+1
        defadr List_GetCount,0x1446C708+1
        defadr Display_GetTopBook,0x14052680+1
	defadr DataBrowserDesc_SetOpenEmptyFolder,0x14C243C0+1
	defadr DataBrowserDesc_SetActions,0x14CE42B4+1
	defadr DataBrowserDesc_SetDefaultActions,0x14CE4118+1
	defadr DataBrowserDesc_SetFileExtList,0x14CE4518+1
	defadr DataBrowserDesc_SetItemFilter,0x14CE42BC+1
	defadr DataBrowserDesc_SetSelectActionOnFolders,0x14A0FF50+1
	defadr DataBrowser_isFileInListExt,0x14568F10+1
	defadr FILEITEM_GetFname,0x140217D0+1
	defadr FILEITEM_GetPath,0x140216D4+1
	defadr FSX_MakeFullPath,0x145CE068+1
	defadr JavaDialog_Open,0x14330AFC+1
	defadr JavaDialog_Close,0x141ABC80+1
	defadr JavaAppDesc_GetFirstApp,0x1404B1F0+1
	defadr JavaAppDesc_GetJavaAppInfo,0x141AC90C+1
	defadr JavaAppDesc_GetJavaAppID,0x141ACC48+1
	defadr JavaAppDesc_GetNextApp,0x1447DC60+1
	defadr JavaApp_LogoImageID_Get,0x14B140CC+1
	defadr REQUEST_UI_OAF_START_APPLICATION,0x146168C4+1
	defadr ImageID_Free,0x140233F0+1

        EXTERN GotoShortcut

        RSEG STANDBY_SOFTKEY_FIX1
        CODE16
        ADD     R0, #0x18       ; Menu 0xED2

        RSEG STANDBY_SOFTKEY_FIX2(1)
        CODE16
        ADD     R0, #0x77       ; Save 0xF31

        RSEG STANDBY_SOFTKEY_FIX3
        CODE16
        SUB     R0, #0x44       ; Back 0xE76

        RSEG STANDBY_SOFTKEY_FIX4(1)
        CODE16
        SUB     R0, #0xF        ; Video 0xEC9

        RSEG STANDBY_SOFTKEY_FIX5
        CODE16
        ADD     R0, #0x3C       ; OK 0xEF6

        RSEG STANDBY_SOFTKEY_FIX6
        CODE16
        ADD     R6, #0x7E       ; Send Message 0xF38

        RSEG STANDBY_LINK_RIGHT
        DATA
        DCD GotoShortcut

        RSEG STANDBY_SOFTKEY_RIGHT
        DATA
	DCD 0xEBA

        END
