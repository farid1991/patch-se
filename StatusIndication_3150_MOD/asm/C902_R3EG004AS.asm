#ifdef C902_R3EG004AS

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr memcpy,0x101478A4
        defadr sprintf,0x106DDFAC+1
        defadr snwprintf,0x106DE460+1
        defadr _fopen,0x10938A50+1
        defadr fclose,0x116EF3D8+1
        defadr fread,0x1093A3E4+1
        defadr fwrite,0x1093A5B0+1
        defadr fstat,0x109393B4+1
        defadr AllocDirHandle,0x109368A0+1
        defadr GetFname,0x10936A70+1
        defadr DataBrowserDesc_Create,0x117E1244+1
        defadr DataBrowserDesc_SetStyle,0x10C2FBD8+1
        defadr DataBrowserDesc_SetHeaderText,0x117E14F4+1
        defadr DataBrowserDesc_SetFolders,0x117E14DC+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x117E14FC+1
        defadr DataBrowser_Create,0x117DD48C+1
        defadr DataBrowserDesc_Destroy,0x117E12F4+1
        defadr getFileExtention,0x1093C0C0+1
        defadr DataBrowser_isFileInListExt,0x10936CD4+1
        defadr Timer_ReSet,0x10DD0A5C+1
        defadr Timer_Set,0x10DD0A28+1
        defadr Timer_Kill,0x10DD0AB4+1
        defadr CreateBook,0x10DD4448+1
        defadr BookObj_KillBook,0x10DD455C+1
        defadr BookObj_GotoPage,0x10DD4158+1
        defadr BookObj_ReturnPage,0x10DD4310+1
        defadr FreeBook,0x10DD4AC8+1
        defadr FindBook,0x10DD2680+1
        defadr Find_StandbyBook,0x10D71898+1
        defadr BookObj_SetFocus,0x10DD46F8+1
        defadr GUIObject_SetTitleText,0x109B3294+1
        defadr GUIObject_Show,0x109B3080+1
        defadr ListMenu_SetCursorToItem,0x11A6D130+1
        defadr GUIObject_SetStyle,0x109B30D8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A6DD1C+1
        defadr GUIonMessage_SetMenuItemText,0x11A6DD28+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A6DD58+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11A6DD38+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A6DD48+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A6DD68+1
        defadr DispObject_SetTitleText,0x109A83D4+1
        defadr ListMenu_GetSelectedItem,0x11A6D144+1
        defadr ListMenu_SetItemStyle,0x11A6D194+1
        defadr isScreenSaverBook,0x108C9154+1
        defadr StatusIndication_SetItemText,0x10D70E3C+1
        defadr StatusIndication_ShowNotes,0x10D72A50+1
        defadr CreateStringInputVA,0x10878CFC+1
        defadr CreateOneOfMany,0x11A6F520+1
        defadr OneOfMany_SetItemCount,0x11A6F6AC+1
        defadr OneOfMany_SetChecked,0x11A6F6C8+1
        defadr OneOfMany_SetTexts,0x11A6F6FC+1
        defadr OneOfMany_GetSelected,0x11A6F6D8+1
        defadr StatusIndication_Item8_SetText,0x10D7295C+1
        defadr GUIObject_SoftKeys_SetAction,0x107F30B4+1
        defadr GUIObject_SoftKeys_SetText,0x107F312C+1
        defadr GUIObject_SoftKeys_SetEnable,0x107F321C+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x107F31D4+1
        defadr GUIObject_SoftKeys_RemoveItem,0x107F3068+1
        defadr GUIObject_SoftKeys_SetVisible,0x107F31B0+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x107F3420+1
        defadr wstrcpy,0x10D4A3E8+1
        defadr wstrncpy,0x10D4A400+1
        defadr wstrcat,0x10D4A42C+1
        defadr wstrncat,0x10D4A448+1
        defadr wstrcmp,0x10D4A3B8+1
        defadr wstrlen,0x10D4A3A4+1
        defadr str2wstr,0x10D4B66C+1
        defadr strcmp,0x106DE234+1
        defadr strlen,0x106DE290+1
        defadr wstr2strn,0x10D4A4C4+1
        defadr int2strID_int,0x10F45F6C+1
        defadr Str2ID_int,0x10F46140+1
        defadr StrID2Str,0x10F4684C+1
        defadr TextID2wstr,0x10F466D4+1
        defadr TextGetLength,0x10F46584+1
        defadr TextFree_int,0x10F4647C+1
        defadr AB_DEFAULTNBR_GET,0x10B46048+1
        defadr AB_READSTRING,0xEDA51BD1
        defadr AB_READPHONENBR,0x10B4C420+1
        defadr AB_GETNBROFITEMS,0x10B4C4D8+1
        defadr PNUM_len,0x10F45740+1
        defadr PNUM2str,0x10919A38+1
        defadr GUIObject_GetDispObject,0x109B2F18+1
        defadr List_Create,0x11AB32EC+1
        defadr List_Destroy,0x11AB3314+1
        defadr List_InsertFirst,0x11AB3460+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10788274+1
        defadr REQUEST_DATEANDTIME_GET,0x10792268+1
        defadr GetFreeBytesOnHeap,0x4BB00700
        defadr BookObj_Hide,0x10DD4720+1
        defadr BookObj_Show,0x10DD4730+1
        defadr StartAPP,0x10D71A84+1
        defadr ListMenu_SetOnMessage,0x11A6D268+1
        defadr manifest_GetParam,0x10AE6FCC+1
        defadr lseek,0x1093A758+1
        defadr get_VBUFFER,0x0
        defadr SetLampLevel,0x119C211C+1
        defadr List_RemoveAt,0x11AB34DC+1
        defadr GetCurrentPID,0x10005E64+1
        defadr List_IndexOf,0x11AB3420+1
        defadr alloc,0x1017CAF4
        defadr receive,0x1017CB10
        defadr send,0x1017CB00
        defadr sender,0x1017CB50
        defadr free_buf,0x1017CB20
        defadr create_process,0x1017CBEC
        defadr start,0x1017CE0C
        defadr get_ptype,0x1017CCBC
        defadr current_process,0x1017CC08
        defadr delay,0x1017CB40
        defadr hunt,0x1017CD08
        defadr kill_proc,0x1017CD34
        defadr receive_w_tmo,0x1017CB6C
        defadr stop,0x1017CE1C
        defadr get_mem,0x1017CC88
        defadr get_envp,0x10005C44+1
        defadr set_envp,0x10005C58+1
        defadr get_bid,0x1017CC40
        defadr strcpy,0x106DE25C+1
        defadr CreateMessage,0x10DF3380+1
        defadr SendMessage,0x10DF33D4+1
        defadr WaitMessage,0x10DF345C+1
        defadr FreeMessage,0x10DF3470+1
        defadr SendDispatchMessage,0x10BBA7BC+1
        defadr UIEventName,0x10DD0E44+1
        defadr MissedEvents,0x4BB9DFF8
        defadr UI_Event,0x10DD31E8+1
        defadr UI_Event_wData,0x10DD31F8+1
        defadr UI_Event_toBookID,0x10DD3240+1
        defadr UI_Event_toBookIDwData,0x10DD3254+1
        defadr List_Find,0x11AB35BC+1
        defadr List_Get,0x11AB350C+1
        defadr wstrrchr,0x10D4B728+1
        defadr BookObj_CallSubroutine,0x10DD41E8+1
        defadr List_InsertLast,0x11AB3468+1
        defadr debug_printf,0x4BB38C2C+1
        defadr PlayFile,0x119CF490+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11A8A530+1
        defadr Profile_SetActive,0x11ABA430+1
        defadr isKeylocked,0x108C8F58+1
        defadr IsMediaPlayerVideoBook,0x10DF7690+1
        defadr Vibra,0x119CE7F8+1
        defadr REQUEST_DATEFORMAT_GET,0x10792448+1
        defadr REQUEST_TIMEFORMAT_GET,0x1079252C+1
        defadr Date2ID,0x11A47A80+1
        defadr Time2ID,0x11A4799C+1
        defadr CreateListMenu,0x11A6CF44+1
        defadr ListMenu_SetItemCount,0x11A6D158+1
        defadr ROOT_APP,0x4BBAA578
        defadr GUIObject_SoftKeys_SetInfoText,0x107F3118+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x107F3250+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11A4B068+1
        defadr REQUEST_SYSTEM_RESTART,0x11A4B078+1
        defadr GUIObject_SoftKeys_SetTexts,0x107F3184+1
        defadr IsRightNowBook,0x10B13DE8+1
        defadr IsVolumeControllerBook,0x11AA6860+1
        defadr CreateTabMenuBar,0x1176972C+1
        defadr TabMenuBar_SetTabCount,0x11769984+1
        defadr TabMenuBar_SetTabGui,0x117697FC+1
        defadr TabMenuBar_SetTabIcon,0x1176987C+1
        defadr GUIObject_Destroy,0x109B2E8C+1
        defadr GUIInput_SetIcon,0x109B3154+1
        defadr StringInput_GetStringAndLen,0x108795AC+1
        defadr GetAudioControlPtr,0x4BBC7810
        defadr AudioControl_Vibrate,0x11539020+1
        defadr GetVolumeSize,0x1093BDD8+1
        defadr CreateNOfMany,0x11A6EF2C+1
        defadr NOfMany_SetTexts,0x11A6F130+1
        defadr NOfMany_SetChecked,0x11A6F0B4+1
        defadr NOfMany_SetCursor,0x11A6F07C+1
        defadr NOfMany_GetCheckedCount,0x11A6F0D8+1
        defadr NOfMany_GetChecked,0x11A6F0C8+1
        defadr NOfMany_SetOnMessage,0x11A6F128+1
        defadr AudioControl_Init,0x119CF5DC+1
        defadr OneOfMany_SetFocused,0x11A6F690+1
        defadr OneOfMany_SetOnMessage,0x11A6F6F4+1
        defadr CreateMonitorFeedback,0x11A46664+1
        defadr FeedBack_SetText,0x11A4671C+1
        defadr GetBatteryState,0x11066478+1
        defadr get_DisplayGC,0x109B0EDC+1
        defadr DispObject_GetRect,0x109A9AD4+1
        defadr GC_GetRect,0x109B1520+1
        defadr GC_GetXX,0x109B181C+1
        defadr GC_SetXX,0x109B1810+1
        defadr GC_ValidateRect,0x109B14D0+1
        defadr BookObj_AddGUIObject,0x10DD47D8+1
        defadr DrawRect,0x109ACC28+1
        defadr DrawString,0x109ACF74+1
        defadr XGUIList_AddGUIObject,0x10DD4CD8+1
        defadr DispObject_InvalidateRect,0x109A9864+1
        defadr GUIObject_Create,0x109B2CC8+1
        defadr SetFont,0x109ADB34+1
        defadr StatusRow_p,0x4BBC5794
        defadr root_list_get_session_count,0x10DD2780+1
        defadr root_list_get_session,0x10DD2790+1
        defadr SESSION_GetTopBook,0x10DD1F60+1
        defadr MainInput_getVisible,0xEDA51BD1
        defadr MainInput_strlen,0x10D71398+1
        defadr MainInput_getPNUM,0x10D713C8+1
        defadr MainInput_isPlus,0xEDA51BD1
        defadr BookObj_GetBookID,0x10DD4BB4+1
        defadr wstrncmp,0x106DEC0C+1
        defadr DispObject_GetAbsoluteXPos,0x109AACD8+1
        defadr DispObject_GetAbsoluteYPos,0x109AAD0C+1
        defadr DispObject_GetWindow,0x109A9DE8+1
        defadr GetThemeColor,0x10E4312C+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11A89F64+1
        defadr REQUEST_SETTING_SILENCE_GET,0x11A89F0C+1
        defadr VCALL_Init,0x10B3A288+1
        defadr VCALL_SetName,0x10B3A380+1
        defadr VCALL_SetNameIcon,0x10B3A3E0+1
        defadr VCALL_SetNumber,0x10B3A3A0+1
        defadr VCALL_SetHZ1,0x10B3A3C4+1
        defadr VCALL_SetHZ2,0x10B3A3D0+1
        defadr MakeVoiceCall,0x10B39E20+1
        defadr FileDelete,0x10939644+1
        defadr GUIObject_SetFocus,0x109B3044+1
        defadr CreateSMSCont,0x119FD750+1
        defadr FreeSMSCont,0x119FDE94+1
        defadr PrepareSMSCont,0x119FD930+1
        defadr CteateNewMessage,0x119FDDBC+1
        defadr get_APP_DESC_TABLE,0x11B6B78C
        defadr Window_GetComponentInterface,0x109B0888+1
        defadr AB_POSITIONNBR_GET,0x10B4C6C4+1
        defadr AB_NAME_ITEM2StrID,0x10B4C5D8+1
        defadr AB_NUM_ITEM2StrID,0x10B4C63C+1
        defadr GetABRecNum,0x10B4C6C0+1
        defadr get_AB_ITEMS_DESC,0x11B54328
        defadr SBY_GetMainInput,0x1088A17C+1
        defadr SBY_GetStatusIndication,0x1074F428+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10A31428+1
        defadr PID_MMI,0x4BBA8A50
        defadr DispObject_GetGUI,0x109A9148+1
        defadr Display_GetFocusedDispObject,0x109A9094+1
        defadr DispObject_GetVisible,0x109A9708+1
        defadr DispObject_GetDESC,0x10014EA4+1
        defadr DISP_DESC_SetName,0x109A6314+1
        defadr DispObject_GetName,0x109AAA30+1
        defadr DISP_DESC_SetSize,0x109A6318+1
        defadr DISP_DESC_SetOnCreate,0x109A631C+1
        defadr DispObject_GetOnCreate,0x109A6398+1
        defadr DISP_DESC_SetOnClose,0x109A6320+1
        defadr DispObject_GetOnClose,0x109A63B4+1
        defadr DISP_DESC_SetOnRedraw,0x109A6324+1
        defadr DispObject_GetOnRedraw,0x109A63D0+1
        defadr DISP_DESC_SetOnKey,0x109A632C+1
        defadr DispObject_GetOnKey,0x109A6408+1
        defadr DISP_DESC_SetOnRefresh,0x109A6328+1
        defadr DispObject_GetonRefresh,0x109A63EC+1
        defadr DISP_DESC_SetMethod06,0x109A6330+1
        defadr DispObject_GetMethod06,0x109A6424+1
        defadr DISP_DESC_SetOnLayout,0x109A6338+1
        defadr DispObject_GetOnLayout,0x109A645C+1
        defadr DISP_DESC_SetOnConfig,0x109A633C+1
        defadr DispObject_GetOnConfig,0x109A6478+1
        defadr DISP_DESC_SetMethod0A,0x109A6340+1
        defadr DispObject_GetMethod0A,0x109A6494+1
        defadr DISP_DESC_SetMethod0B,0x109A6344+1
        defadr DispObject_GetMethod0B,0x109A64B0+1
        defadr DISP_DESC_SetMethod0C,0x109A6348+1
        defadr TextCopyId,0x10F46320+1
        defadr BookObj_GetSession,0x10DD4B14+1
        defadr GUIonMessage_SetNumberOfSubItems,0x11A6DDC4+1
        defadr GUIonMessage_SubItem_SetText,0x11A6DE30+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x11A6DE24+1
        defadr GoMusic,0x10E0ABDC+1
        defadr Vibra_Off,0x119CE8CC+1
        defadr PlayFileV,0x119CF494+1
        defadr GetSilent,0x119CD94C+1
        defadr GetVibrator,0x119C9738+1
        defadr GetAudioSettings,0x119CEC68+1
        defadr GetChipID,0xEDA51BD1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x11A6DE18+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x11A6DE0C+1
        defadr DestroyDirHandle,0x10936BEC+1
        defadr LastExtDB,0x11E71218
        defadr GetOtherExtMethods,0x117D73A4+1
        defadr MessageBox,0x11A44C20+1
        defadr Display_GetHeight,0x1176BD88+1
        defadr Display_GetWidth,0x1176BD94+1
        defadr PlaySystemSound,0x119CF438+1
        defadr TabMenuBar_GetFocusedTab,0x117697F0+1
        defadr TabMenuBar_SetFocusedTab,0x117697E0+1
        defadr GC_GetPenColor,0x109B1728+1
        defadr GC_SetPenColor,0x109B16EC+1
        defadr GC_SetPixel,0x109B1370+1
        defadr GC_DrawLine,0x109B1E6C+1
        defadr GC_DrawFRect,0x109B1FF8+1
        defadr GC_WritePixels,0x109B13F8+1
        defadr png_create_read_struct_2,0x11815CBC+1
        defadr png_destroy_read_struct,0x11815E08+1
        defadr png_create_info_struct,0x11814464+1
        defadr png_destroy_info_struct,0x11814498+1
        defadr png_set_progressive_read_fn,0x11815C94+1
        defadr png_process_data,0x11814C54+1
        defadr png_read_update_info,0x11815DDC+1
        defadr png_get_progressive_ptr,0x11815CB8+1
        defadr png_get_IHDR,0x11814920+1
        defadr png_set_strip_16,0x11815FA8+1
        defadr png_set_gray_1_2_4_to_8,0x11815FB4+1
        defadr png_set_gray_to_rgb,0x11815FD8+1
        defadr png_get_valid,0x118148F4+1
        defadr png_set_tRNS_to_alpha,0x11815FCC+1
        defadr png_set_filler,0x11818D3C+1
        defadr png_set_palette_to_rgb,0x11815FC0+1
        defadr png_get_rowbytes,0x1181490C+1
        defadr png_progressive_combine_row,0x11815C74+1
        defadr png_sig_cmp,0x1181435C+1
        defadr setjmp,0x1014BB40
        defadr longjmp,0x1014BB64
        defadr inflateInit2_,0x11819A10+1
        defadr inflate,0x11819BB8+1
        defadr inflateEnd,0x1181AEB0+1
        defadr memcmp,0x125DCB58
        defadr strncmp,0x106DE2CC+1
        defadr strncpy,0x106DE300+1
        defadr strcat,0x106DE1FC+1
        defadr GUIObject_SetTitleType,0x109B3278+1
        defadr GUIonMessage_SetItemDisabled,0x11A6DDD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107882EC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10788374+1
        defadr get_Surfaces,0x4BD84114
        defadr iconidname2id,0x11504674+1
        defadr textidname2id,0x116EE8C0+1
        defadr ListMenu_SetNoItemText,0x11A6D2E8+1
        defadr IsFmRadioBook,0x10F8BC9C+1
        defadr IsAudioPlayerBook,0x10C68CDC+1
        defadr PlayerControl,0x10C68704+1
        defadr SwitchRadioStationFromList,0x10F89B70+1
        defadr Shortcut_Run,0x10DC09C8+1
        defadr mkdir,0x10935FCC+1
        defadr rmdir,0x109363C0+1
        defadr chmod,0x10939570+1
        defadr rename,0x10939B98+1
        defadr Disp_GetStrIdHeight,0x109AE220+1
        defadr CallID_GetCallStatusDesc,0x10DE51B4+1
        defadr CallStatusDesc_GetName,0x10DE47EC+1
        defadr List_DestroyElements,0x11AB3600+1
        defadr strstr,0x106DE39C+1
        defadr GPRS_GetLastSessionInfo,0x107E576C+1
        defadr wstrcmpni,0x10D4B7C4+1
        defadr wtoi,0x10DD0488+1
        defadr DATE_GetWeekDay,0x10BAEFF0+1
        defadr Cale_GetSettings,0x10905E3C+1
        defadr wstrwstr,0x106DED6C+1
        defadr wstrcmpi,0x10D4B808+1
        defadr wstrchr,0x106DEB54+1
        defadr GUIObject_SoftKeys_Hide,0x107F346C+1
        defadr GUIObject_SoftKeys_Show,0x107F3478+1
        defadr DispObject_SoftKeys_Get,0x107EF844+1
        defadr StandbyBackground_SetImage,0x10E419A0+1
        defadr CreateYesNoQuestionVA,0x1176B63C+1
        defadr ListMenu_SetSecondLineText,0x11A6D50C+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10B0CA64+1
        defadr FSX_GetInvalidChar,0x1093BBC8+1
        defadr DataBrowserDesc_SetFoldersNumber,0x117E14E4+1
        defadr DataBrowserDesc_SetActions,0x117E1498+1
        defadr DataBrowserDesc_SetSelectAction,0x117E1460+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x117E1468+1
        defadr DataBrowserDesc_SetBookID,0x117E1444+1
        defadr DataBrowserDesc_SetItemFilter,0x117E13E8+1
        defadr DataBrowserDesc_SetOption,0x117E1514+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x117E157C+1
        defadr DataBrowserDesc_SetFileExtList,0x117E13F0+1
        defadr FSX_RemoveIllegalSymbolsName,0x117EAC58+1
        defadr FILEITEM_Create,0x117EA670+1
        defadr FILEITEM_Destroy,0x117EA7A0+1
        defadr CreateDateInputVA,0x11769AB8+1
        defadr CreateTimeInputVA,0x1176B214+1
        defadr StringInput_SetCursorPosition,0x108795F8+1
        defadr BookObj_CallPage,0x10DD428C+1
        defadr DateInput_GetDateInt,0x11769D28+1
        defadr TimeInput_GetTimeInt,0x1176B4DC+1
        defadr GC_GetBrushColor,0x109B1804+1
        defadr GC_SetBrushColor,0x109B17C4+1
        defadr GC_DrawRoundRect,0x109B2040+1
        defadr MenuBook_Desktop,0x10DC017C+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10DBF4B0+1
        defadr BookObj_SoftKeys_SetAction,0x107ED704+1
        defadr BookObj_SoftKeys_SetText,0x107ED73C+1
        defadr FindBookByID,0x10DD264C+1
        defadr TextFeedbackWindow,0x1176AA78+1
        defadr Feedback_SetKeyHook,0x1176AE84+1
        defadr Feedback_SetOnClose,0x1176AE20+1
        defadr Feedback_SetTimeout,0x1176AE50+1
        defadr Feedback_SetTextExtended,0x1176AEE8+1
        defadr TabMenuBar_SetOnTabSwitch,0x117698D8+1
        defadr KeyCode2Name,0x10F90AC8+1
        defadr ImageID_Get,0x107861F4+1
        defadr ImageID_Free,0x1078C414+1
        defadr DataBrowser_CreateSubExecute,0x117CA1AC+1
        defadr DataBrowser_ExecuteSubroutine,0x117CABCC+1
        defadr FILEITEM_SetFname,0x117EA84C+1
        defadr FILEITEM_SetPath,0x117EAB0C+1
        defadr FILEITEM_GetFname,0x117EAB04+1
        defadr FILEITEM_GetPath,0x117EAB98+1
        defadr FILEITEM_SetFnameAndContentType,0x117EA8AC+1
        defadr FILEITEM_SetPathAndContentType,0x117EAB70+1
        defadr JavaDialog_Open,0x10AF4F5C+1
        defadr JavaDialog_Close,0x10AF86B0+1
        defadr JavaAppDesc_Get,0x10AF887C+1
        defadr JavaAppDesc_GetFirstApp,0x10AEA8F0+1
        defadr JavaAppDesc_GetNextApp,0x10AEA8F8+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10AEA3BC+1
        defadr DispObject_SetRefreshTimer,0x109A92CC+1
        defadr DispObject_KillRefreshTimer,0x109A9348+1
        defadr IsDataBrowserBook,0x117DDD9C+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x117D9434+1
        defadr Shortcut_Get_MenuItemName,0x10B15940+1
        defadr Shortcut_Get_MenuItemIconID,0x10DC03A0+1
        defadr FindBookEx,0x10DD26E0+1
        defadr FILEITEM_CreateCopy,0x117EA6A0+1
        defadr ActionCreate,0x10DD3E70+1
        defadr BookObj_GetSessionID,0x10DD4A3C+1
        defadr UI_Event_toSID,0x10DD320C+1
        defadr GetIMSI,0xEDA51BD1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11A470F4+1
        defadr MainInput_getCurPos,0xEDA51BD1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x107EF224+1
        defadr PNUM2Name,0x10B354B8+1
        defadr SpeedDial_GetPNUM,0x10B5C9E8+1
        defadr MetaData_Desc_Create,0xEDA51BD1
        defadr MetaData_Desc_Destroy,0xEDA51BD1
        defadr MetaData_Desc_GetTags,0xEDA51BD1
        defadr MetaData_Desc_GetTrackNum,0xEDA51BD1
        defadr DispObject_GetWindowWidth,0x109AAC58+1
        defadr DispObject_GetWindowHeight,0x109AAC78+1
        defadr get_system_langID,0x10D9C5D8+1
        defadr lang_get_name,0x11A76290+1
        defadr w_chdir,0x4BB003AC
        defadr w_fopen,0x112852E4+1
        defadr w_fstat,0x1128539C+1
        defadr w_fwrite,0x1128532C+1
        defadr w_fread,0x11285314+1
        defadr w_lseek,0x11A3FA18+1
        defadr w_fclose,0x11285344+1
        defadr w_mkdir,0x4BB00344
        defadr DirHandle_SetFilterStr,0x10936C44+1
        defadr Disp_GetStrIdWidth,0x109AE2C0+1
        defadr MetaData_Desc_GetCoverInfo,0xEDA51BD1
        defadr ImageID_GetIndirect,0x1078628C+1
        defadr unixtime2datetime,0x10BAEE08+1
        defadr List_Insert,0x11AB333C+1
        defadr FileCopy,0x1093994C+1
        defadr FileMove,0x10939B98+1
        defadr RedLED_On,0xEDA51BD1
        defadr RedLED_Off,0xEDA51BD1
        defadr DispObject_SetLayerColor,0x109ABA5C+1
        defadr JavaAppDesc_GetJavaAppID,0x10AF87D8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10C1D698+1
        defadr JavaApp_LogoImageID_Get,0x10C11EC8+1
        defadr CreateProgressBar,0x1176A1EC+1
        defadr ProgressBar_SetText,0x1176A4E4+1
        defadr ProgressBar_SetIcon,0x1176A658+1
        defadr ProgressBar_SetPercentValue,0x1176A4A0+1
        defadr ProgressBar_SetBarDisabled,0x1176A678+1
        defadr StringInput_DispObject_SetText,0x1086DE8C+1
        defadr GUIObject_SetTitleBackgroundImage,0xEDA51BD1
        defadr GUIObject_SetTitleIcon,0x109B32CC+1
        defadr GUIObject_SetCursorImage,0xEDA51BD1
        defadr GUIObject_SetBackgroundImage,0xEDA51BD1
        defadr DispObject_SoftKeys_GetParams,0x107F04F4+1
        defadr DispObject_SoftKeys_GetList,0x107F0538+1
        defadr BookObj_GetDisplayOrientation,0x10DD4C50+1
        defadr BookObj_SetDisplayOrientation,0x10DD4BEC+1
        defadr Display_GetTopBook,0x10DD3F2C+1
        defadr Display_SetBrightness,0xEDA51BD1
        defadr Display_GetBrightness,0x10DA5368+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x117E144C+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x117E14A8+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x117E14B0+1
        defadr SetTheme,0x10DF0F40+1
        defadr SoftKeys_GetLabel,0x107F2A20+1
        defadr SoftKeys_Update,0x107F25D8+1
        defadr get_CellData,0x108CC984+1
        defadr IncommingCall_Reject,0x10DEE3F4+1
        defadr IncommingCall_Mute,0x10DEF734+1
        defadr GetRadioState,0xEDA51BD1
        defadr Bluetooth_GetState,0x10A452E8+1
        defadr Bluetooth_GetPhoneVisibility,0x10A452AC+1
        defadr Bluetooth_isBusy,0x10A45378+1
        defadr USB_isConnected,0x1099CF0C+1
        defadr w_diropen,0x4BB00354
        defadr w_dirread,0x11A400A8+1
        defadr w_dirclose,0x4BB0038C
        defadr w_rename,0x11A40144+1
        defadr w_remove,0x11A400F8+1
        defadr ConnectionManager_Connection_GetState,0xEDA51BD1
        defadr IsCameraBook,0x108A6598+1
        defadr IsSoundRecorderBook,0x10E2F318+1
        defadr StringInput_MenuItem_SetPriority,0x10879700+1
        defadr Audio_Pause,0x10C6A708+1
        defadr Audio_Play,0x10C6A6AC+1
        defadr CreatePercentInputVA,0x11769E58+1
        defadr PercentInput_GetPercent,0x11769FE4+1
        defadr GUIonMessage_SetLineSeparator,0x11A6DDE8+1
        defadr PHF_GetState,0x109F9B90+1
        defadr CHF_GetState,0x109F9B98+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x107F3484+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x107F3490+1
        defadr SetTrayIcon,0x1176E358+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11A89C0C+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x11A89E00+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x11A89D7C+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11A8A1E4+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x11A89D14+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x11A8A00C+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10AE999C+1
        defadr SoundRecorderDesc_Create,0x10E2E7C4+1
        defadr SoundRecorderDesc_Destroy,0x10E2E820+1
        defadr SoundRecorderDesc_SetBookID,0x10E2E83C+1
        defadr SoundRecorderDesc_SetType,0x10E2E868+1
        defadr SoundRecorderDesc_SetFolder,0x10E2E87C+1
        defadr SoundRecorderDesc_SetFname,0x10E2E898+1
        defadr SoundRecorderDesc_SetRecordSize,0x10E2E8B4+1
        defadr SoundRecorder_Create,0x10E2E92C+1
        defadr SoundRecorder_RecordCall,0x10DE1720+1
        defadr Browser_OpenURI,0x107627CC+1
        defadr GetURIScheme,0x10DF4B00+1
        defadr CreateURI,0x10DF4F9C+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x117E14CC+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x1078ECCC+1
        defadr Alarm_GetState,0x1078D4FC+1
        defadr Alarm_GetTIME,0x1078E4D8+1
        defadr Alarm_GetWeekSettings,0x1078F410+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11A89FB0+1
        defadr IncommingCall_Accept,0x10DEE2B8+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AD4808+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AD47C0+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AD4868+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x10AD4898+1
        defadr DispObject_Show,0x109A9584+1
        defadr Request_EventChannel_Subscribe,0x1261A3D4+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x107F344C+1
        defadr Request_ICA_ShutdownAllConnections,0x11483084+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11A8A678+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x117E1584+1
        defadr GUIonMessage_GetMsg,0x11A6DCF8+1
        defadr GUIonMessage_GetBook,0x11A6DD00+1
        defadr GUIonMessage_GetGui,0x11A6DCFC+1
        defadr GUIonMessage_GetSelectedItem,0x11A6DD04+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11A6DD10+1
        defadr ObexSendFile,0x10885318+1
        defadr Feedback_SetManualScrollingText,0x11765824+1
        defadr EqualizerGain_Set,0x119CC570+1
        defadr CANVAS_Get_GviGC,0x113C34AC+1
        defadr GVI_BitBlt,0x11124B40+1
        defadr GVI_StretchBlt,0x11124CB4+1
        defadr GVI_TransformBlt,0x11124D70+1
        defadr GVI_CreatePen,0x11123DE8+1
        defadr GVI_CreateDashedPen,0x11123E2C+1
        defadr GVI_CreateSolidBrush,0x11123CF8+1
        defadr GVI_Delete_GVI_Object,0x111236C8+1
        defadr GVI_DrawEllipse,0x11124478+1
        defadr GVI_DrawLine,0x11125364+1
        defadr GVI_DrawLines,0x111259F4+1
        defadr GVI_DrawPolyLine,0x11125A78+1
        defadr GVI_DrawRectangle,0x11125CF4+1
        defadr GVI_DrawRoundRect,0x11124994+1
        defadr GVI_DrawSolidLines,0x111255B8+1
        defadr GVI_DrawSolidPolyLine,0x111257C0+1
        defadr GVI_DrawSolidRectangle,0x11125864+1
        defadr GVI_FillEllipse,0x11124860+1
        defadr GVI_FillPolygon,0x1112521C+1
        defadr GVI_FillRectangle,0x11125B74+1
        defadr GVI_FillRectangles,0x11125C00+1
        defadr GVI_FillSolidEllipse,0x1112490C+1
        defadr GVI_FillSolidRectangle,0x11125C7C+1
        defadr GVI_FillSolidRoundRect,0x11124AE4+1
        defadr GVI_FillSolidTriangle,0x111251A8+1
        defadr GC_CreateMemoryGC,0x109B0EEC+1
        defadr GC_FreeGC,0x109B0FB4+1
        defadr Settings_ShowNumber_Get,0x10FA7658+1
        defadr GVI_CreateBitmap,0x11123EE4+1
        defadr GVI_CreateMemoryGC,0x11125E58+1
        defadr GVI_DeleteMemoryGC,0x11153AC0+1
        defadr StringInput_DispObject_SetLanguage,0x108725C0+1
        defadr List_InsertSorted,0x11AB3484+1
        defadr ListMenu_SetItemIcon,0x11A6D440+1
        defadr wstrnupr,0x10D4A474+1
        defadr wstrnlwr,0x10AB2F1C+1
        defadr ListMenu_SetItemTextScroll,0x11A6D838+1
        defadr GUIObject_SetTitleTextColor,0xEDA51BD1
        defadr GUIObject_SetListTextColor,0x11A6E918+1
        defadr DispObject_SetTitleTextColor,0x109A8668+1
        defadr DispObject_SetListTextColor,0x11A603A0+1
        defadr DispObject_SetCursorImage,0x11A6035C+1
        defadr DispObject_SetBackgroundImage,0x11A60378+1
        defadr DispObject_SetTitleBackgroundImage,0x109A8680+1
        defadr TabMenuBar_SetTabTitle,0x117698C4+1
        defadr GUIObject_GetBook,0x109B2F2C+1
        defadr SoftKeys_GetSelectedAction,0x107EF154+1
        defadr MonitorFeedback_SetTimer,0x11A46710+1
        defadr ListMenu_DestroyItems,0x11A6D5B0+1
        defadr DispObject_SetScrollBarBackgroundColor,0x109AAF58+1
        defadr DispObject_SetScrollBarColor,0x109AAF30+1
        defadr DispObject_SetSoftkeysColor,0x107EF6C0+1
        defadr YesNoQuestion_SetIcon,0x1176B8C0+1
        defadr GUIObject_SetBacklightTimeout,0x109B31D4+1
        defadr ListMenu_SetHotkeyMode,0x11A6D294+1
        defadr ListMenu_SetSearchLanguageMode,0x11A6D710+1
        defadr ListMenu_EnableSearchHeader,0x11A6D738+1
        defadr GUIonMessage_GetSearchString,0x11A6DF00+1
        defadr GUIonMessage_GetSearchStringLength,0x11A6DF20+1
        defadr EqualizerGain_Get,0x119CC548+1
        defadr Theme_DestroyMenuIcons,0x10DBE568+1
        defadr CoCreateInstance,0x107018B0+1
        defadr GUIObject_SetSecondRowTitleText,0x109B32B0+1
        defadr ListMenu_GetItemCount,0x11A6D16C+1
        defadr OSE_GetShell,0x10DF32B4+1
        defadr swscanf,0x106DE494+1
        defadr sscanf,0x10003C88+1

        defadr MainInput_Hide,0x10D712E4+1

        defadr DisplayGC_AddRef,0x109B1314+1

//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x10FA487C+1
        defadr FlightGetState,    0x11A48D70+1
        
        defadr CallInfo_Get,      0x1126377C+1
        defadr isTimerBook,       0x10F8728C+1

        defadr some,              0x10DF34D0+1
        defadr armfunc,           0x106DAB00

        defadr Show,              0x10D72AA0+1
        defadr Return_Clear,      0x10D72A9A+1
        defadr Show_Clear,        0x10D72AC8+1

        defadr oldRedrawStatus,   0x1175EB20+1
        defadr oldRedrawDisplay,  0x10D70058+1
        defadr oldRedrawSoft,     0x107F1FF0+1
        defadr oldCreateDisplay,  0x10D6FFEC+1
        defadr oldCloseDisplay,   0x10D70044+1
        defadr oldOnKeyMainInput, 0x10D6DD3C+1

        defadr retSetIcon,        0x1176E370+1

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
        BEQ     loc_452AE5A8
        LDR     R3, =Return_Clear
        BX      R3

loc_45426AAA:
        BL      KillTimer
        LDR     R3, =Show_Clear
        BX      R3

loc_452AE5A8:
        BL      RunTimer
        MOV     R0, SP
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
        LDR     R3, =retSetIcon
        BX      R3

_mySetTrayIcon_2:
        PUSH    {R0-R2}
        MOV     R1, R2
        LDR     R3, =MySetTrayIcon
        BLX     R3
        POP     {R0-R2}
        MOV     R2, #0
        MOV     R3, R1
        MOV     R1, R0
        LSL     R0, R3, #3
        LDR     R3, =StatusRow_p
        LDR     R0, [R3,R0]
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
          