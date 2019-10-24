#ifdef K850_R1FA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x11028C74+1
        defadr memfree,0x11028C44+1
        defadr memset,0x100016BC
        defadr memcpy,0x100B7410
        defadr sprintf,0x104F8E1C+1
        defadr snwprintf,0x104F92D0+1
        defadr _fopen,0x10F9DA48+1
        defadr fclose,0x1155FFC8+1
        defadr fread,0x10F9F18C+1
        defadr fwrite,0x10F9F358+1
        defadr fstat,0x10F9E340+1
        defadr AllocDirHandle,0x10F9BA40+1
        defadr GetFname,0x10F9BC10+1
        defadr DataBrowserDesc_Create,0x10FE4A68+1
        defadr DataBrowserDesc_SetStyle,0x10FE4CE8+1
        defadr DataBrowserDesc_SetHeaderText,0x10FE4D18+1
        defadr DataBrowserDesc_SetFolders,0x10FE4D00+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x10FE4D20+1
        defadr DataBrowser_Create,0x10FE0F78+1
        defadr DataBrowserDesc_Destroy,0x10FE4B18+1
        defadr getFileExtention,0x10FA0D88+1
        defadr DataBrowser_isFileInListExt,0x10F9BE74+1
        defadr Timer_ReSet,0x115B6DC0+1
        defadr Timer_Set,0x115B6D8C+1
        defadr Timer_Kill,0x115B6E18+1
        defadr CreateBook,0x115BA1CC+1
        defadr BookObj_KillBook,0x115BA2E8+1
        defadr BookObj_GotoPage,0x115B9F44+1
        defadr BookObj_ReturnPage,0x115BA0AC+1
        defadr FreeBook,0x115BA7D8+1
        defadr FindBook,0x115B9D24+1
        defadr Find_StandbyBook,0x115C5D14+1
        defadr BookObj_SetFocus,0x115BA46C+1
        defadr GUIObject_SetTitleText,0x1165DB78+1
        defadr GUIObject_Show,0x1165D64C+1
        defadr ListMenu_SetCursorToItem,0x1160EE40+1
        defadr GUIObject_SetStyle,0x1165D6A4+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1160F964+1
        defadr GUIonMessage_SetMenuItemText,0x1160F970+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1160F9A0+1
        defadr GUIonMessage_SetMenuItemInfoText,0x1160F980+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x1160F990+1
        defadr GUIonMessage_SetMenuItemIcon,0x1160F9B0+1
        defadr DispObject_SetTitleText,0x116518E4+1
        defadr ListMenu_GetSelectedItem,0x1160EE54+1
        defadr ListMenu_SetItemStyle,0x1160EEA4+1
        defadr isScreenSaverBook,0x116945F9
        defadr StatusIndication_SetItemText,0x1166B798+1
        defadr StatusIndication_ShowNotes,0x115C6E1C+1
        defadr CreateStringInputVA,0x115ECB40+1
        defadr CreateOneOfMany,0x11610F9C+1
        defadr OneOfMany_SetItemCount,0x11611148+1
        defadr OneOfMany_SetChecked,0x11611164+1
        defadr OneOfMany_SetTexts,0x11611198+1
        defadr OneOfMany_GetSelected,0x11611174+1
        defadr StatusIndication_Item8_SetText,0x115C6D28+1
        defadr GUIObject_SoftKeys_SetAction,0x11676F78+1
        defadr GUIObject_SoftKeys_SetText,0x11676FF0+1
        defadr GUIObject_SoftKeys_SetEnable,0x116770E0+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x11677098+1
        defadr GUIObject_SoftKeys_RemoveItem,0x11676F2C+1
        defadr GUIObject_SoftKeys_SetVisible,0x11677074+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x116772F8+1
        defadr wstrcpy,0x10F8EF08+1
        defadr wstrncpy,0x10F8EF20+1
        defadr wstrcat,0x10F8EF4C+1
        defadr wstrncat,0x104F9A38+1
        defadr wstrcmp,0x10F8EED8+1
        defadr wstrlen,0x10F8EEC4+1
        defadr str2wstr,0x10F9018C+1
        defadr strcmp,0x104F90A4+1
        defadr strlen,0x104F9100+1
        defadr wstr2strn,0x10F8EFE4+1
        defadr int2strID,0x1163AB50+1
        defadr Str2ID,0x1163AD10+1
        defadr StrID2Str,0x1163B2B4+1
        defadr TextID2wstr,0x1163B17C+1
        defadr TextGetLength,0x1163B07C+1
        defadr TextFree,0x1163AFA8+1
        defadr AB_DEFAULTNBR_GET,0x10F25018+1
        defadr AB_READSTRING,0x10F2A5B4+1
        defadr AB_READPHONENBR,0x10F2A684+1
        defadr AB_GETNBROFITEMS,0x10F2A73C+1
        defadr PNUM_len,0x1163A314+1
        defadr PNUM2str,0x1145F30C+1
        defadr GUIObject_GetDispObject,0x1165D4C0+1
        defadr List_Create,0x113DC618+1
        defadr List_Destroy,0x113DC640+1
        defadr List_InsertFirst,0x113DC78C+1
        defadr Gif2ID,0x10F841D4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10F84404+1
        defadr REQUEST_DATEANDTIME_GET,0x10E737E8+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x11691154+1
        defadr GetFreeBytesOnHeap,0x115C750C+1
        defadr BookObj_Hide,0x115BA494+1
        defadr BookObj_Show,0x115BA4A4+1
        defadr StartAPP,0x115C5EC4+1
        defadr ListMenu_SetOnMessage,0x1160EF78+1
        defadr manifest_GetParam,0x10FAB18C+1
        defadr lseek,0x10F9F500+1
        defadr SetLampLevel,0x115D7B0C+1
        defadr List_RemoveAt,0x113DC718+1
        defadr GetCurrentPID,0x100A22A8+1
        defadr List_IndexOf,0x113DC74C+1
        defadr alloc,0x100EC660
        defadr receive,0x100EC67C
        defadr send,0x100EC66C
        defadr sender,0x100EC6BC
        defadr free_buf,0x100EC68C
        defadr create_process,0x100EC758
        defadr start,0x100EC978
        defadr get_ptype,0x100EC828
        defadr current_process,0x100EC774
        defadr delay,0x100EC6AC
        defadr hunt,0x100EC874
        defadr kill_proc,0x100EC8A0
        defadr receive_w_tmo,0x100EC6D8+1
        defadr stop,0x100EC988
        defadr get_mem,0x100EC7F4
        defadr get_envp,0x100A2088+1
        defadr set_envp,0x100A209C+1
        defadr get_bid,0x100EC7AC
        defadr datetime2unixtime,0x111A292C+1
        defadr strcpy,0x104F90CC+1
        defadr CreateMessage,0x111A20D8+1
        defadr SendMessage,0x111A212C+1
        defadr WaitMessage,0x111A21B4+1
        defadr FreeMessage,0x111A21C8+1
        defadr SendDispatchMessage,0x1116E87C+1
        defadr UIEventName,0x115B72E8+1
        defadr MissedEvents,0x29C84D18
        defadr UI_Event,0x115B9014+1
        defadr UI_Event_wData,0x115B9024+1
        defadr UI_Event_toBookID,0x115B906C+1
        defadr UI_Event_toBookIDwData,0x115B9080+1
        defadr List_Find,0x113DC8E8+1
        defadr List_Get,0x113DC838+1
        defadr wstrrchr,0x10F90248+1
        defadr BookObj_CallSubroutine,0x115B9FB8+1
        defadr List_InsertLast,0x113DC794+1
        defadr debug_printf,0x29C134E0+1
        defadr PlayFile,0x111AD37C+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11758BDC+1
        defadr Profile_SetActive,0x1175B0F4+1
        defadr SetBrightnessOfScreen,0x115DB154+1
        defadr isKeylocked,0x11694634+1
        defadr isMediaPlayerVideoBook,0x115996C1
        defadr ShuttingDown,0x115C1D7A+1
        defadr Vibra,0x1117AA74+1
        defadr REQUEST_DATEFORMAT_GET,0x10E739C8+1
        defadr REQUEST_TIMEFORMAT_GET,0x10E73AE8+1
        defadr Date2ID,0x115C38AC+1
        defadr Time2ID,0x115C37C8+1
        defadr CreateListMenu,0x1160EC38+1
        defadr ListMenu_SetItemCount,0x1160EE68+1
        defadr GUIObject_SoftKeys_SetInfoText,0x11676FDC+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x11677114+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x115C754C+1
        defadr REQUEST_SYSTEM_RESTART,0x115C755C+1
        defadr GUIObject_SoftKeys_SetTexts,0x11677048+1
        defadr isRightNowBook,0x11686848+1
        defadr isVolumeControllerBook,0x11696ACC+1
        defadr CreateTabMenuBar,0x1166A620+1
        defadr TabMenuBar_SetTabCount,0x1166A838+1
        defadr TabMenuBar_SetTabGui,0x1166A6F0+1
        defadr TabMenuBar_SetTabIcon,0x1166A770+1
        defadr GUIObject_Destroy,0x1165D450+1
        defadr GUIInput_SetIcon,0x1165D730+1
        defadr StringInput_GetStringAndLen,0x115ED3C4+1
        defadr GetAudioControlPtr,0x29C776A4
        defadr AudioControl_Vibrate,0x10D15F00+1
        defadr GetVolumeSize,0x10FA0B1C+1
        defadr CreateNOfMany,0x116109FC+1
        defadr NOfMany_SetTexts,0x11610C20+1
        defadr NOfMany_SetChecked,0x11610BA4+1
        defadr NOfMany_SetCursor,0x11610B6C+1
        defadr NOfMany_GetCheckedCount,0x11610BC8+1
        defadr NOfMany_GetChecked,0x11610BB8+1
        defadr NOfMany_SetOnMessage,0x11610C18+1
        defadr AudioControl_Init,0x111AD4C8+1
        defadr OneOfMany_SetFocused,0x1161112C+1
        defadr OneOfMany_SetOnMessage,0x11611190+1
        defadr CreateMonitorFeedback,0x115C13AC+1
        defadr FeedBack_SetText,0x115C1460+1
        defadr GetBatteryState,0x10582660+1
        defadr get_DisplayGC,0x1165AB8C+1
        defadr DispObject_GetRect,0x11652ED4+1
        defadr GC_GetRect,0x1165B1D4+1
        defadr GC_GetXX,0x1165B4D8+1
        defadr GC_SetXX,0x1165B4CC+1
        defadr GC_ValidateRect,0x1165B184+1
        defadr BookObj_AddGUIObject,0x115BA520+1
        defadr DrawRect,0x11655C00+1
        defadr DrawString,0x11655F40+1
        defadr XGUIList_AddGUIObject,0x115BA96C+1
        defadr DispObject_InvalidateRect,0x11652C94+1
        defadr GUIObject_Create,0x1165D360+1
        defadr SetFont,0x11656AB8+1
        defadr StatusRow_p,0x29C8389C
        defadr root_list_get_session_count,0x115B83A4+1
        defadr root_list_get_session,0x115B83B0+1
        defadr SESSION_GetTopBook,0x115B7CA0+1
        defadr BookObj_GetBookID,0x115BA884+1
        defadr wstrncmp,0x104F9A64+1
        defadr DispObject_GetWindow,0x116531C4+1
        defadr GetThemeColor,0x1167B060+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11758610+1
        defadr REQUEST_SETTING_SILENCE_GET,0x117585B8+1
        defadr VCALL_Init,0x10F1C7A0+1
        defadr VCALL_SetName,0x10F1C898+1
        defadr VCALL_SetNameIcon,0x10F1C8F8+1
        defadr VCALL_SetNumber,0x10F1C8B8+1
        defadr VCALL_SetHZ1,0x10F1C8DC+1
        defadr VCALL_SetHZ2,0x10F1C8E8+1
        defadr MakeVoiceCall,0x10F1C358+1
        defadr FileDelete,0x10F9E468+1
        defadr GUIObject_SetFocus,0x1165D5EC+1
        defadr CreateSMSCont,0x11228374+1
        defadr FreeSMSCont,0x11228A8C+1
        defadr PrepareSMSCont,0x11228550+1
        defadr CteateNewMessage,0x112289C4+1
        defadr get_APP_DESC_TABLE,0x11A2BA20
        defadr get_AB_ITEMS_DESC,0x119E2038
        defadr DispObject_GetGUI,0x11652588+1
        defadr Display_GetFocusedDispObject,0x116524D4+1
        defadr DispObject_GetVisible,0x11652B2C+1
        defadr DispObject_GetDESC,0x109D1DB0+1
        defadr DISP_DESC_SetName,0x1164DB70+1
        defadr DispObject_GetName,0x11653C28+1
        defadr DISP_DESC_SetSize,0x1164DB74+1
        defadr DISP_DESC_SetOnCreate,0x1164DB78+1
        defadr DispObject_GetOnCreate,0x1164DBF4+1
        defadr DISP_DESC_SetOnClose,0x1164DB7C+1
        defadr DispObject_GetOnClose,0x1164DC10+1
        defadr DISP_DESC_SetOnRedraw,0x1164DB80+1
        defadr DispObject_GetOnRedraw,0x1164DC2C+1
        defadr DISP_DESC_SetOnKey,0x1164DB88+1
        defadr DispObject_GetOnKey,0x1164DC64+1
        defadr DISP_DESC_SetOnRefresh,0x1164DB84+1
        defadr DispObject_GetonRefresh,0x1164DC48+1
        defadr DISP_DESC_SetMethod06,0x1164DB8C+1
        defadr DispObject_GetMethod06,0x1164DC80+1
        defadr DISP_DESC_SetOnLayout,0x1164DB94+1
        defadr DispObject_GetOnLayout,0x1164DCB8+1
        defadr DISP_DESC_SetOnConfig,0x1164DB98+1
        defadr DispObject_GetOnConfig,0x1164DCD4+1
        defadr DISP_DESC_SetMethod0A,0x1164DB9C+1
        defadr DispObject_GetMethod0A,0x1164DCF0+1
        defadr DISP_DESC_SetMethod0B,0x1164DBA0+1
        defadr DispObject_GetMethod0B,0x1164DD0C+1
        defadr DISP_DESC_SetMethod0C,0x1164DBA4+1
        defadr JavaSession_Manager,0x1110BF88+1
        defadr JavaSession_GetName,0x1112078C+1
        defadr TextCopyId,0x1163AEB4+1
        defadr BookObj_GetSession,0x115BA824+1
        defadr GUIonMessage_SetNumberOfSubItems,0x1160FA04+1
        defadr GUIonMessage_SubItem_SetText,0x1160FA7C+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x1160FA70+1
        defadr GoMusic,0x115EA5FC+1
        defadr PlayFileV,0x111AD380+1
        defadr GetSilent,0x11179F8C+1
        defadr GetChipID,0x10002A00+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x1160FA64+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x1160FA58+1
        defadr DestroyDirHandle,0x10F9BD8C+1
        defadr LastExtDB,0x119F81C0
        defadr GetOtherExtMethods,0x10FDB0F4+1
        defadr MessageBox,0x115BFEC0+1
        defadr Display_GetHeight,0x1166CBFC+1
        defadr Display_GetWidth,0x1166CC08+1
        defadr PlaySystemSound,0x111AD324+1
        defadr TabMenuBar_GetFocusedTab,0x1166A6E4+1
        defadr TabMenuBar_SetFocusedTab,0x1166A6D4+1
        defadr GC_GetPenColor,0x1165B3E0+1
        defadr GC_SetPenColor,0x1165B3A4+1
        defadr GC_SetPixel,0x1165B024+1
        defadr GC_DrawLine,0x1165BE64+1
        defadr GC_DrawFRect,0x1165BFEC+1
        defadr inflateInit2_,0x10B08CDC+1
        defadr inflate,0x10B08E84+1
        defadr inflateEnd,0x10B0A17C+1
        defadr memcmp,0x29BC08B8
        defadr strncmp,0x104F913C+1
        defadr strncpy,0x104F9170+1
        defadr strcat,0x104F906C+1
        defadr GUIObject_SetTitleType,0x1165DB5C+1
        defadr GUIonMessage_SetItemDisabled,0x1160FA10+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10F8447C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10F84504+1
        defadr get_Surfaces,0x29E42734
        defadr iconidname2id,0x10CC1A58+1
        defadr textidname2id,0x10E6A010+1
        defadr ListMenu_SetNoItemText,0x1160EFF8+1
        defadr IsFmRadioBook,0x112F0D35
        defadr SwitchRadioStationFromList,0x112EEE80+1
        defadr Shortcut_Run,0x1167DA24+1
        defadr mkdir,0x10F9B220+1
        defadr rmdir,0x10F9B5EC+1
        defadr chmod,0x10F9E3A4+1
        defadr rename,0x10F9E984+1
        defadr Disp_GetStrIdHeight,0x11657098+1
        defadr CallID_GetCallStatusDesc,0x10EE66F0+1
        defadr CallStatusDesc_GetName,0x10EE5D14+1
        defadr List_DestroyElements,0x113DC92C+1
        defadr strstr,0x104F920C+1
        defadr GPRS_GetLastSessionInfo,0x116CCD00+1
        defadr wstrcmpni,0x10F902E4+1
        defadr wtoi,0x115B67E4+1
        defadr DATE_GetWeekDay,0x111A2C28+1
        defadr Cale_GetSettings,0x10EAAA7C+1
        defadr wstrwstr,0x104F9BC4+1
        defadr wstrcmpi,0x10F90328+1
        defadr wstrchr,0x104F99AC+1
        defadr GUIObject_SoftKeys_Hide,0x11677344+1
        defadr GUIObject_SoftKeys_Show,0x11677350+1
        defadr DispObject_SoftKeys_Get,0x11673810+1
        defadr StandbyBackground_SetImage,0x1164A8A4+1
        defadr CreateYesNoQuestionVA,0x1166C5FC+1
        defadr ListMenu_SetSecondLineText,0x1160F250+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10FCD428+1
        defadr FSX_isNameInvalid,0x10FA090C+1
        defadr DataBrowserDesc_SetFoldersNumber,0x10FE4D08+1
        defadr DataBrowserDesc_SetActions,0x10FE4CDC+1
        defadr DataBrowserDesc_SetSelectAction,0x10FE4C84+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x10FE4C8C+1
        defadr DataBrowserDesc_SetBookID,0x10FE4C68+1
        defadr DataBrowserDesc_SetItemFilter,0x10FE4C0C+1
        defadr DataBrowserDesc_SetOption,0x10FE4D38+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x10FE4DA0+1
        defadr DataBrowserDesc_SetFileExtList,0x10FE4C14+1
        defadr FSX_RemoveIllegalSymbolsName,0x10FEDD14+1
        defadr FILEITEM_Create,0x10FED72C+1
        defadr FILEITEM_Destroy,0x10FED85C+1
        defadr CreateDateInputVA,0x1166A96C+1
        defadr CreateTimeInputVA,0x1166C1C0+1
        defadr StringInput_SetCursorPosition,0x115ED410+1
        defadr BookObj_CallPage,0x115BA044+1
        defadr DateInput_GetDateInt,0x1166ABDC+1
        defadr TimeInput_GetTimeInt,0x1166C488+1
        defadr GetFontDesc,0x29C83D74
        defadr GetFontCount,0x29C840E4
        defadr GC_GetBrushColor,0x1165B4C0+1
        defadr GC_SetBrushColor,0x1165B480+1
        defadr GC_DrawRoundRect,0x1165C034+1
        defadr MenuBook_Desktop,0x1167D344+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x1167D494+1
        defadr BookObj_SoftKeys_SetAction,0x11671624+1
        defadr BookObj_SoftKeys_SetText,0x1167165C+1
        defadr FindBookByID,0x115B8270+1
        defadr TextFeedbackWindow,0x1166BA78+1
        defadr Feedback_SetKeyHook,0x1166BE80+1
        defadr Feedback_SetOnClose,0x1166BE20+1
        defadr Feedback_SetTimeout,0x1166BD3C+1
        defadr Feedback_SetTextExtended,0x1166BEE4+1
        defadr TabMenuBar_SetOnTabSwitch,0x1166A7CC+1
        defadr KeyCode2Name,0x1121710C+1
        defadr ImageID_Get,0x10F87EB4+1
        defadr ImageID_Free,0x10F87EA8+1
        defadr DataBrowser_CreateSubExecute,0x10FCE10C+1
        defadr DataBrowser_ExecuteSubroutine,0x10FCEC8C+1
        defadr FILEITEM_SetFname,0x10FED908+1
        defadr FILEITEM_SetPath,0x10FEDBC8+1
        defadr FILEITEM_GetFname,0x10FEDBC0+1
        defadr FILEITEM_GetPath,0x10FEDC54+1
        defadr FILEITEM_SetFnameAndContentType,0x10FED968+1
        defadr FILEITEM_SetPathAndContentType,0x10FEDC2C+1
        defadr JavaDialog_Open,0x10FB83C0+1
        defadr JavaDialog_Close,0x10FBBA9C+1
        defadr JavaAppDesc_Get,0x10FBBC60+1
        defadr JavaAppDesc_GetFirstApp,0x10FAE3CC+1
        defadr JavaAppDesc_GetNextApp,0x10FAE3D4+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10FADED8+1
        defadr isDataBrowserBook,0x10FE183C+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x10FDCFB0+1
        defadr Shortcut_Get_MenuItemName,0x116887C4+1
        defadr Shortcut_Get_MenuItemIconID,0x1167D534+1
        defadr FindBookEx,0x115B8304+1
        defadr FILEITEM_CreateCopy,0x10FED75C+1
        defadr BookObj_GetSessionID,0x115BA788+1
        defadr UI_Event_toSID,0x115B9038+1
        defadr DispObject_GetWindowWidth,0x11653ECC+1
        defadr DispObject_GetWindowHeight,0x11653EEC+1
        defadr get_system_langID,0x115D2140+1
        defadr lang_get_name,0x116ABEF0+1
        defadr w_chdir,0x1175B468
        defadr w_fopen,0x10799114+1
        defadr w_fstat,0x107991CC+1
        defadr w_fwrite,0x1079915C+1
        defadr w_fread,0x10799144+1
        defadr w_lseek,0x113DB844+1
        defadr w_fclose,0x10799174+1
        defadr w_mkdir,0x1175B400
        defadr DirHandle_SetFilterStr,0x10F9BDE4+1
        defadr Disp_GetStrIdWidth,0x11657120+1
        defadr unixtime2datetime,0x111A2A40+1
        defadr List_Insert,0x113DC668+1
        defadr FileCopy,0x10F9E748+1
        defadr FileMove,0x10F9E984+1
        defadr RedLED_On,0x1004445C+1
        defadr RedLED_Off,0x100444A8+1
        defadr DispObject_SetLayerColor,0x11654BD8+1
        defadr JavaAppDesc_GetJavaAppID,0x10FBBBBC+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x110A2818+1
        defadr JavaApp_LogoImageID_Get,0x11097260+1
        defadr StringInput_DispObject_SetText,0x115E26F0+1
        defadr GUIObject_SetTitleIcon,0x1165DBB0+1
        defadr DispObject_SoftKeys_GetList,0x116744C8+1
        defadr BookObj_GetDisplayOrientation,0x115BA924+1
        defadr BookObj_SetDisplayOrientation,0x112147E0+1
        defadr Display_SetBrightness,0x115DBE8C+1
        defadr Display_GetBrightness,0x115DBEC0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x10FE4C70+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x10FE4CCC+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x10FE4CD4+1
        defadr Bluetooth_GetState,0x10EB95E8+1
        defadr Bluetooth_GetPhoneVisibility,0x10EB95B0+1
        defadr w_diropen,0x1175B410
        defadr w_dirread,0x113DBED4+1
        defadr w_dirclose,0x1175B450
        defadr ConnectionManager_Connection_GetState,0x113F92C0+1
        defadr RightNow_SetActive,0x116871B8+1
        defadr CreatePercentInputVA,0x1166ACFC+1
        defadr PercentInput_GetPercent,0x1166AE88+1
        defadr GUIonMessage_SetLineSeparator,0x1160FA28+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1167735C+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x11677368+1
        defadr SetTrayIcon,0x115C6FF8+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x117582D0+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x117584AC+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11758890+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x1175838C+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x117586B8+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10FAD440+1
        defadr SoundRecorderDesc_Create,0x11074144+1
        defadr SoundRecorderDesc_Destroy,0x110741A0+1
        defadr SoundRecorderDesc_SetBookID,0x110741BC+1
        defadr SoundRecorderDesc_SetType,0x110741E8+1
        defadr SoundRecorderDesc_SetFolder,0x110741FC+1
        defadr SoundRecorderDesc_SetFname,0x11074218+1
        defadr SoundRecorderDesc_SetRecordSize,0x11074234+1
        defadr SoundRecorder_Create,0x110742AC+1
        defadr SoundRecorder_RecordCall,0x10EE31A8+1
        defadr Browser_OpenURI,0x10F591EC+1
        defadr GetURIScheme,0x1145E534+1
        defadr CreateURI,0x1145E9D0+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x10FE4CF0+1
        defadr DispObject_Show,0x116529CC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x11677324+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11758D08+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x10FE4DA8+1
        defadr GUIonMessage_GetMsg,0x1160F940+1
        defadr GUIonMessage_GetBook,0x1160F948+1
        defadr GUIonMessage_GetGui,0x1160F944+1
        defadr GUIonMessage_GetSelectedItem,0x1160F94C+1
        defadr GUIonMessage_GetPrevSelectedItem,0x1160F958+1
        defadr ObexSendFile,0x10F149A0+1
        defadr GC_CreateMemoryGC,0x1165AB9C+1
        defadr GC_FreeGC,0x1165AC60+1
        defadr List_InsertSorted,0x113DC7B0+1
        defadr ListMenu_SetItemIcon,0x1160F160+1
        defadr wstrnupr,0x10F8EF94+1
        defadr wstrnlwr,0x112DB500+1
        defadr TabMenuBar_SetTabTitle,0x1166A7B8+1
        defadr GUIObject_GetBook,0x1165D4D4+1
        defadr MonitorFeedback_SetTimer,0x115C1454+1
        defadr void,0x11610AA1
        defadr ListMenu_DestroyItems,0x1160F32C+1
        defadr YesNoQuestion_SetIcon,0x1166C898+1

        defadr ImageID_GetIndirect,0x10F87F2C+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x10E70268+1
        defadr Alarm_GetTIME,0x10E6FA70+1
        defadr Alarm_GetWeekSettings,0x10E70A00+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x1175865C+1
        defadr Settings_ShowNumber_Get,0x10F0FCC8+1
        defadr SBY_GetMainInput,0x1000A804+1
        defadr MainInput_Hide,0x116838E0+1
        defadr Display_GetTopBook,0x115B9D40+1
        defadr ListMenu_SetItemTextScroll,0x1160F5A8+1
        defadr IsAudioPlayerBook,0x1156A18C+1
        defadr GetImageHeight,0x11657098+1
        
        defadr CoCreateInstance,0x116BD0BC+1
        defadr DisplayGC_AddRef,0x1165AFC8+1
        defadr GC_PutChar,0x1165B5D4+1

//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x10F0D768+1
        defadr FlightGetState,    0x115C4A70+1
        
        defadr CallInfo_Get,      0x1077483C+1
        defadr isTimerBook,       0x10EFD2BC+1

        defadr some,              0x111A2228+1
        defadr armfunc,           0x104F59E8

        defadr Show,              0x115C6E68+1
        defadr Return_Clear,      0x115C6E62+1
        defadr Show_Clear,        0x115C6E90+1

        defadr oldRedrawStatus,   0x11658894+1
        defadr oldRedrawDisplay,  0x11668160+1
        defadr oldRedrawSoft,     0x11675E58+1
        defadr oldCreateDisplay,  0x116680A8+1
        defadr oldCloseDisplay,   0x11668128+1
        defadr oldOnKeyMainInput, 0x11682808+1

        defadr retSetIcon,        0x1164D57C+1

        EXTERN  onRedrawStatus
        EXTERN  onRedrawDisplay
        EXTERN  onRedrawSoft
        EXTERN  onCreateDisplay
        EXTERN  onCloseDisplay
        EXTERN  myOnKey
        EXTERN  RunTimer
        EXTERN  KillTimer
        EXTERN  MySetTrayIcon

        RSEG  CODE
        CODE16

_GetCurName:
        PUSH    {R1-R7,LR}
        LDR	R0, =Find_StandbyBook
        BLX	R0
        MOV	R4, R0
        LDR	R0, [R4,#0x3C]
        LDR	R3, =0x6FFFFFFF
        CMP	R0, R3
        BNE	exit
        LDR	R0, [R4,#0x54]
        CMP	R0, R3
        BEQ	searching
        MOV	R0, SP
        LDR	R5, =GetOperatorName
        BLX	R5
        B	exit

searching:
        LDR	R0, =0x17E7
        
exit:
        POP    {R1-R7,PC}

        RSEG  CODE
        CODE16

_GetTimerTime:
        PUSH    {R0-R7,LR}
        LDR	R0, =isTimerBook
        LDR	R3, =FindBook
        BLX     R3
        MOV	R4, R0
        LDR	R3, =some
        BLX	R3
        LDR	R1, [R4,#0x2C]
        SUB	R0, R0, R1
        LDR	R1, [R4,#0x28]
        CMP	R0, R1
        BCS	loc_64tor5
        SUB	R5, R1, R0
        B	after

loc_64tor5:
        MOV	R5, #0x64

after:
        LDR	R4, [SP,#0]
        LDR	R1, =0x36EE80
        MOV	R0, R5
        LDR	R3, =armfunc
        BLX	R3
        STRB	R1,[R4,#0]
        LDR	R1, =0xEA60
        LDR	R3, =armfunc
        BLX	R3
        STRB	R1, [R4,#1]
        LDR     R1, =0x3E8
        LDR	R3, =armfunc
        BLX	R3
        STRB	R1, [R4,#2]
        MOV	R0, #0
        STRB	R1, [R4,#3]
        POP    {R0-R7,PC}
        
        RSEG  CODE
        CODE16

CallClear:
        LDR     R0, =0x6FFFFFFF
        ADD     R5, R1, #0
        CMP     R1, R0
        BEQ     loc_45426AAA
        CMP     R2, #0
        MOV     R0, SP
        BEQ     loc_452AE5A8
        LDR     R3, =Return_Clear
        BX      R3

loc_45426AAA:
        PUSH    {R0-R2}
        BL      KillTimer
        POP     {R0-R2}
        LDR     R3, =Show_Clear
        BX      R3

loc_452AE5A8:
        PUSH    {R0-R2}
        BL      RunTimer
        POP     {R0-R2}
        LDR     R1, =0xF83C
        LDR     R3, =Show
        BX      R3

_mySetTrayIcon:
        PUSH    {R0,R1}
        LDR     R3, =MySetTrayIcon
        BLX     R3
        POP     {R0,R1}
        MOV     R2, #0
        MOV     R1, R0
        LDR     R0, =StatusRow_p
        LDR     R0, [R0,#0]
        B       RetSet

_mySetTrayIcon_2:
        PUSH    {R0-R2}
        MOV     R1, R2
        LDR     R3, =MySetTrayIcon
        BLX     R3
        POP     {R0-R2}
        MOV     R2, #0
        MOV     R3, R1
        MOV     R1, R0
        LSL     R0, R3, #2
        LDR     R3, =StatusRow_p
        LDR     R0, [R3,R0]
        
RetSet:        
        LDR     R3, =retSetIcon
        BX      R3
        
        RSEG    PATCH_DRAWSTATUS(2)
        DATA
        DCD     onRedrawStatus

        RSEG    PATCH_DRAWDISPLAY(2)
        DATA
        DCD     onRedrawDisplay

        RSEG    PATCH_DRAWSOFT(2)
        DATA
        DCD     onRedrawSoft

        RSEG    PATCH_CREATEDISPLAY(2)
        DATA
        DCD     onCreateDisplay

        RSEG    PATCH_CLOSEDISPLAY(2)
        DATA
        DCD     onCloseDisplay

        RSEG    PATCH_ONKEYMAININPUT(2)
        DATA
        DCD     myOnKey

        RSEG    PATCH_CALLOFF_CLEAR(2)
        CODE16
        LDR     R0, =CallClear
        BX	R0

        RSEG    PATCH_SET_TRAY_ICON(2)
        CODE16
        PUSH    {LR}
        LDR     R3, =_mySetTrayIcon
        BX      R3

        RSEG    PATCH_SET_TRAY_ICON_2(2)
        CODE16
        PUSH    {LR}
        LDR     R3, =_mySetTrayIcon_2
        BX      R3
        
#endif
          END
          