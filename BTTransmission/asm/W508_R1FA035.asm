//W508_R1FA035

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BA30DE8
        defadr memfree,0x4BA30E10
        defadr memset,0x14C23C5C
        defadr debug_printf,0x14C39CD0
        defadr set_envp,0x101F3448+1
        defadr get_envp,0x101F3434+1

        defadr strncmp,0x1433778C+1
        defadr strcmp,0x14D0980C+1
        defadr wstrcpy,0x14310568+1
        defadr wstrncpy,0x14359CB0+1
        defadr wstrcmp,0x14310E1C+1
        defadr wstrlen,0x14311500+1
        defadr wstrcmpi,0x14311DE4+1
        defadr wstrrchr,0x1409B4A4+1
        defadr snwprintf,0x142C75F0+1
        
        defadr _fopen,0x1421A92C+1
        defadr fread,0x14310608+1
        defadr fclose,0x1410E040+1
        defadr fwrite,0x14572374+1
        defadr fstat,0x1435BA9C+1
        defadr w_diropen,0x4BA30BB8
        defadr w_chdir,0x4BA80C30
        defadr w_dirread,0x143AD8EC+1
        defadr w_fstat,0x10177468+1
        defadr w_dirclose,0x4BA80C10
        defadr FSX_IsFileExists,0x144BFCC0+1
        defadr FSX_MakeFullPath,0x142F18E0+1

        defadr GUIonMessage_GetBook,0x1412CA38+1
        defadr GUIonMessage_GetMsg,0x1412CC2C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CD24+1
        defadr GUIonMessage_SetMenuItemText,0x14540388+1
        defadr GUIonMessage_SetMenuItemIcon,0x14159AE8+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453FA40+1

        defadr MenuBook_Desktop,0x14148198+1
        defadr Shortcut_Get_MenuItemIconID,0x142E15F4+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x14FB9F58+1
        defadr Shortcut_Get_MenuItemName,0x1455D97C+1
        defadr Shortcut_Run,0x1456FEB0+1

        defadr TextID_GetString,0x142262BC+1
        defadr TextID_GetWString,0x14225E3C+1
        defadr TextID_CreateIntegerID,0x1452561C+1
        defadr TextID_Create,0x14226B70+1
        defadr TextID_Copy,0x142264CC+1
        defadr TextID_Destroy,0x142261D0+1
        
        defadr FILEITEM_GetFname,0x144DD63C+1
        defadr FILEITEM_GetPath,0x144DD638+1

        defadr DataBrowser_isFileInListExt,0x1421BA8C+1
        defadr DataBrowserDesc_Create,0x141AE618+1
        defadr DataBrowserDesc_SetHeaderText,0x141AE600+1
        defadr DataBrowserDesc_SetBookID,0x141AE390+1
        defadr DataBrowserDesc_SetFolders,0x141AE730+1
        defadr DataBrowserDesc_SetFileExtList,0x141AE78C+1
        defadr DataBrowserDesc_SetItemFilter,0x14E0BCF4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x141AE608+1
        defadr DataBrowserDesc_SetSelectAction,0x141AE610+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x14E0B878+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x141AE738+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x141AE578+1
        defadr DataBrowser_Create,0x143678FC+1
        defadr DataBrowserDesc_Destroy,0x141AE580+1

        defadr CreateStringInput,0x144E4F48+1
        defadr StringInput_SetMode,0x1437F368+1
        defadr StringInput_SetText,0x1501B2A0+1
        defadr StringInput_SetEnableEmptyText,0x1501B258+1
        defadr StringInput_SetMinLen,0x1501B6A8+1
        defadr StringInput_SetMaxLen,0x1501B4C8+1
        defadr StringInput_SetActionOK,0x1501B348+1
        defadr StringInput_SetActionBack,0x1501B340+1
        defadr StringInput_GetStringAndLen,0x140B2CEC+1
        defadr StringInput_MenuItem_SetPriority,0x14F27670+1

        defadr CreateBook,0x1446A50C+1
        defadr FindBook,0x143111F8+1
        defadr FreeBook,0x14366418+1
        defadr BookObj_SetFocus,0x14221660+1
        defadr BookObj_CallPage,0x14247168+1
        defadr BookObj_GotoPage,0x14027124+1
        defadr BookObj_ReturnPage,0x14247260+1
        defadr BookObj_GetBookID,0x14026BD4+1
        defadr BookObj_SoftKeys_SetAction,0x144DA404+1
        defadr BookObj_SoftKeys_SetText,0x14D271A8+1
        defadr UI_Event,0x1431CA88+1
        defadr UI_Event_toBookID,0x1431DDE4+1

        defadr List_Create,0x142DB0F8+1
        defadr List_Get,0x140480B0+1
        defadr List_GetCount,0x143114FC+1
        defadr List_InsertLast,0x142DAFB0+1
        defadr List_InsertFirst,0x1424C85C+1
        defadr List_RemoveAt,0x142C8564+1
        defadr List_RemoveFirst,0x14026BB8+1
        defadr List_DestroyElements,0x1424F7D0+1
        defadr List_Destroy,0x140265EC+1

        defadr CreateYesNoQuestion,0x143F2514+1
        defadr YesNoQuestion_SetQuestionText,0x140749F0+1
        defadr YesNoQuestion_SetDescriptionText,0x14074A00+1
        defadr YesNoQuestion_SetIcon,0x14EEF27C+1
        defadr CreateMessageBox,0x14EBC290+1

        defadr CreateListMenu,0x142211A8+1
        defadr GUIObject_SetTitleText,0x142E6810+1
        defadr ListMenu_SetItemCount,0x1421144C+1
        defadr ListMenu_SetCursorToItem,0x14365EBC+1
        defadr ListMenu_SetOnMessage,0x143E9E50+1
        defadr ListMenu_SetItemTextScroll,0x14541A0C+1
        defadr ListMenu_SetHotkeyMode,0x14365ED0+1
        defadr ListMenu_SetNoItemText,0x14F848D8+1
        defadr ListMenu_SetItemStyle,0x14365B90+1
        defadr ListMenu_GetSelectedItem,0x14542708+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E1C8+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EBD40+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E17C+1
        defadr GUIObject_Show,0x14469D18+1
        defadr GUIObject_Destroy,0x14221158+1

        defadr JavaDialog_Open,0x141C731C+1
        defadr JavaAppDesc_GetFirstApp,0x141CAEE4+1
        defadr JavaAppDesc_GetJavaAppInfo,0x144ED6D0+1
        defadr JavaAppDesc_GetJavaAppID,0x144EDCA8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x152FBF7C+1
        defadr JavaAppDesc_GetNextApp,0x144EE720+1
        defadr JavaDialog_Close,0x144EE618+1
        defadr JavaApp_LogoImageID_Get,0x142B7350+1
        defadr ImageID_Free,0x144BF648+1

        defadr DispObject_InvalidateRect,0x1404A6A0+1
        defadr FindBookEx,0x1431E218+1
        defadr Display_GetTopBook,0x14ED9DE0+1

        defadr CoCreateInstance,0x14150FB8+1
        defadr TextObject_SetText,0x14225564+1
        defadr TextObject_SetFont,0x1419C6D0+1
        defadr get_DisplayGC,0x14049D50+1
        defadr DisplayGC_AddRef,0x1419BDB8+1

        defadr StatusRow_OnRedraw,0x1417B194+1

        defadr pg_ObEx_ReceiveFile,0x1441509C+1
        defadr pg_ObEx_SendFile,0x1512AD94+1
        defadr pg_ObEx_SendMultipleFiles,0x1512AD94+1
        defadr pg_ObEx_FileSent,0x1512B1BC+1

        EXTERN  New_StatusRow_OnRedraw
        EXTERN  New_ObEx_ReceiveFile
        EXTERN  New_ObEx_SendFile
        EXTERN  New_ObEx_SendMultipleFiles
        EXTERN  New_ObEx_FileSent

        RSEG    PATCH_StatusRow_OnRedraw
        DATA
        DCD     New_StatusRow_OnRedraw

        RSEG    PATCH_ObEx_ReceiveFile
        DATA
        DCD     New_ObEx_ReceiveFile

        RSEG    PATCH_ObEx_SendFile
        DATA
        DCD     New_ObEx_SendFile

        RSEG    PATCH_ObEx_SendMultipleFiles
        DATA
        DCD     New_ObEx_SendMultipleFiles

        RSEG    PATCH_ObEx_FileSent
        DATA
        DCD     New_ObEx_FileSent

        END
