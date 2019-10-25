#ifdef W995_R1HA035

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
       
	defadr  memalloc,0x4BA33B64
        defadr  memfree,0x4BA33B8C  
	defadr memset,0x108F2864
        defadr memcpy,0x150DD514
        defadr sprintf,0x142D807C+1
        defadr snwprintf,0x144A2EF0+1
        defadr _fopen,0x1403EB5C+1
        defadr fclose,0x140FD63C+1
        defadr fread,0x144C2D80+1
        defadr fwrite,0x141C1358+1
        defadr fstat,0x14291AC4+1
        defadr AllocDirHandle,0x144C2068+1
        defadr GetFname,0x144C29C4+1
        defadr DataBrowserDesc_Create,0x1426BD68+1
        defadr DataBrowserDesc_SetStyle,0x15412778+1
        defadr DataBrowserDesc_SetHeaderText,0x1426BF08+1
        defadr DataBrowserDesc_SetFolders,0x1426BCFC+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x1426BCDC+1
        defadr DataBrowser_Create,0x1444B574+1
        defadr DataBrowserDesc_Destroy,0x1426BE18+1
        defadr getFileExtention,0x144DE868+1
        defadr DataBrowser_isFileInListExt,0x140E246C+1
        defadr Timer_ReSet,0x1416AB10+1
        defadr Timer_Set,0x1423E2EC+1
        defadr Timer_Kill,0x1416AE00+1
        defadr CreateBook,0x144ABFCC+1
        defadr BookObj_KillBook,0x14045BF4+1
        defadr BookObj_GotoPage,0x14045980+1
        defadr BookObj_ReturnPage,0x142CAF34+1
        defadr FreeBook,0x14133830+1
        defadr FindBook,0x1416E970+1
        defadr Find_StandbyBook,0x143887A8+1
        defadr BookObj_SetFocus,0x145125E8+1
        defadr GUIObject_SetTitleText,0x141105C8+1
        defadr GUIObject_Show,0x144ACC2C+1
        defadr ListMenu_SetCursorToItem,0x141328FC+1
        defadr GUIObject_SetStyle,0x14132D3C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142F1284+1
        defadr GUIonMessage_SetMenuItemText,0x142F0CFC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FF338+1
        defadr GUIonMessage_SetMenuItemInfoText,0x14067DC8+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14FA5DDC+1
        defadr GUIonMessage_SetMenuItemIcon,0x14045284+1
        defadr DispObject_SetTitleText,0x14110790+1
        defadr ListMenu_GetSelectedItem,0x1411BF24+1
        defadr ListMenu_SetItemStyle,0x140F6AE8+1
        defadr IsScreenSaverBook,0x142BF40C+1
        defadr StatusIndication_SetItemText,0x1434F614+1
        defadr StatusIndication_ShowNotes,0x154EDC38+1
        defadr CreateStringInputVA,0x151F873C+1
        defadr CreateOneOfMany,0x140F6A6C+1
        defadr OneOfMany_SetItemCount,0x150CE954+1
        defadr OneOfMany_SetChecked,0x141117A0+1
        defadr OneOfMany_SetTexts,0x141AE38C+1
        defadr OneOfMany_GetSelected,0x1509EAB8+1
        defadr StatusIndication_Item8_SetText,0x14E4CACC+1
        defadr GUIObject_SoftKeys_SetAction,0x14105420+1
        defadr GUIObject_SoftKeys_SetText,0x14105150+1
        defadr GUIObject_SoftKeys_SetEnable,0x1410582C+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x144A8B98+1
        defadr GUIObject_SoftKeys_RemoveItem,0x143CD2E8+1
        defadr GUIObject_SoftKeys_SetVisible,0x141053FC+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x141C5B08+1
        defadr wstrcpy,0x144C27CC+1
        defadr wstrncpy,0x144C11C0+1
        defadr wstrcat,0x144C22B8+1
        defadr wstrncat,0x144C3320+1
        defadr wstrcmp,0x144C3140+1
        defadr wstrlen,0x144C353C+1
        defadr str2wstr,0x1428FF98+1
        defadr strcmp,0x14D3B45C+1
        defadr strlen,0x14D3B4B8+1
        defadr wstr2strn,0x1409E950+1
        defadr int2strID,0x143D6484+1
        defadr Str2ID,0x142D8380+1
        defadr StrID2Str,0x1416F518+1
        defadr TextID2wstr,0x1416F7EC+1
        defadr TextGetLength,0x14170438+1
        defadr TextFree,0x1416FB98+1
        defadr AB_DEFAULTNBR_GET,0x14491D10+1
        defadr AB_READPHONENBR,0x15371868+1
        defadr AB_GETNBROFITEMS,0x14510CC8+1
        defadr PNUM_len,0x140F8124+1
        defadr PNUM2str,0x14241714+1
        defadr GUIObject_GetDispObject,0x1416DDB4+1
        defadr List_Create,0x141045D8+1
        defadr List_Destroy,0x141046D0+1
        defadr List_InsertFirst,0x14104840+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14EB3BFC+1
        defadr REQUEST_DATEANDTIME_GET,0x1434FEA0+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x14489884+1
        defadr GetFreeBytesOnHeap,0x4BA33CD0
        defadr BookObj_Hide,0x14202008+1
        defadr BookObj_Show,0x14035D80+1
        defadr StartAPP,0x15048B20+1
        defadr ListMenu_SetOnMessage,0x142DA720+1
        defadr manifest_GetParam,0x141AAF0C+1
        defadr lseek,0x144C502C+1
        defadr get_VBUFFER,0x0
        defadr SetLampLevel,0x150C59F4+1
        defadr List_RemoveAt,0x1416B160+1
        defadr GetCurrentPID,0x101ECAB8+1
        defadr List_IndexOf,0x1416B47C+1
        defadr alloc,0x101E5B78
        defadr receive,0x101E5B94
        defadr send,0x101E5B84
        defadr sender,0x101E5BD4
        defadr free_buf,0x101E5BA4
        defadr create_process,0x101E5C70
        defadr start,0x101E5E7C
        defadr get_ptype,0x101E5D30
        defadr current_process,0x101E5C80
        defadr delay,0x101E5BC4
        defadr hunt,0x101E5D7C
        defadr kill_proc,0x101E5DA8
        defadr receive_w_tmo,0x101E5BF0
        defadr stop,0x101E5E8C
        defadr get_envp,0x101EC73C+1
        defadr set_envp,0x101EC750+1
        defadr get_bid,0x101E5CB8
        defadr strcpy,0x14D3B484+1
        defadr CreateMessage,0x141B7EE4+1
        defadr SendMessage,0x141B7E94+1
        defadr WaitMessage,0x1434FF08+1
        defadr FreeMessage,0x141B73AC+1
        defadr SendDispatchMessage,0x1447C1F4+1
        defadr UIEventName,0x144F94BC+1
        defadr MissedEvents,0x4BA1BAF8
        defadr UI_Event,0x143A0D70+1
        defadr UI_Event_wData,0x14106144+1
        defadr UI_Event_toBookID,0x1439E4B0+1
        defadr UI_Event_toBookIDwData,0x142A9784+1
        defadr List_Find,0x1416E7B4+1
        defadr List_Get,0x1416E9D4+1
        defadr wstrrchr,0x144C30E8+1
        defadr BookObj_CallSubroutine,0x142CB0CC+1
        defadr List_InsertLast,0x1416AD0C+1
        defadr debug_printf,0x14C69610
        defadr PlayFile,0x15927D68+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x141D4A70+1
        defadr Profile_SetActive,0x1599C6E4+1
        defadr SetBrightnessOfScreen,0x1550B87C+1
        defadr isKeylocked,0x1449EC88+1
        defadr IsMediaPlayerVideoBook,0x144FAE08+1
        defadr ShuttingDown,0x1506B2E8+1
        defadr Vibra,0x1427507C+1
        defadr REQUEST_DATEFORMAT_GET,0x1434FFB4+1
        defadr REQUEST_TIMEFORMAT_GET,0x14350014+1
        defadr Date2ID,0x143894D0+1
        defadr Time2ID,0x1434F8F8+1
        defadr CreateListMenu,0x14132F38+1
        defadr ListMenu_SetItemCount,0x142DA734+1
        defadr ROOT_APP,0x4BA27970
        defadr GUIObject_SoftKeys_SetInfoText,0x140A7538+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1410546C+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x104CCCA8+1
        defadr REQUEST_SYSTEM_RESTART,0x104CCCC8+1
        defadr GUIObject_SoftKeys_SetTexts,0x140A7570+1
        defadr IsRightNowBook,0x1400F654+1
        defadr IsVolumeControllerBook,0x141A7A34+1
        defadr CreateTabMenuBar,0x1433D6D8+1
        defadr TabMenuBar_SetTabCount,0x1426F670+1
        defadr TabMenuBar_SetTabGui,0x14513C60+1
        defadr TabMenuBar_SetTabIcon,0x142F3A8C+1
        defadr GUIObject_Destroy,0x14512BE0+1
        defadr GUIInput_SetIcon,0x14F1C364+1
        defadr StringInput_GetStringAndLen,0x1410E310+1
        defadr GetAudioControlPtr,0x4BA2E418
        defadr AudioControl_Vibrate,0x143C8A04+1
        defadr GetVolumeSize,0x1429223C+1
        defadr CreateNOfMany,0x1501D6E8+1
        defadr NOfMany_SetTexts,0x1501D5F0+1
        defadr NOfMany_SetChecked,0x15974928+1
        defadr NOfMany_SetCursor,0x150934DC+1
        defadr NOfMany_GetCheckedCount,0x150DB354+1
        defadr NOfMany_GetChecked,0x1597493C+1
        defadr NOfMany_SetOnMessage,0x15974960+1
        defadr AudioControl_Init,0x143D9AD8+1
        defadr OneOfMany_SetFocused,0x150CE70C+1
        defadr OneOfMany_SetOnMessage,0x14DB8908+1
        defadr CreateMonitorFeedback,0x1596776C+1
        defadr FeedBack_SetText,0x1596781C+1
        defadr GetBatteryState,0x1017C060+1
        defadr get_DisplayGC,0x1416CA0C+1
        defadr DispObject_GetRect,0x1416BD1C+1
        defadr GC_GetRect,0x14117B70+1
        defadr GC_GetXX,0x142337A4+1
        defadr GC_SetXX,0x1419D3B0+1
        defadr GC_ValidateRect,0x143D0314+1
        defadr BookObj_AddGUIObject,0x14132F2C+1
        defadr DrawRect,0x14107C80+1
        defadr XGUIList_AddGUIObject,0x14045A9C+1
        defadr DispObject_InvalidateRect,0x1416BA88+1
        defadr GUIObject_Create,0x144AD124+1
        defadr StatusRow_p,0x4BA2CE80
        defadr root_list_get_session_count,0x1406FB74+1
        defadr root_list_get_session,0x14105A4C+1
        defadr SESSION_GetTopBook,0x150C6F30+1
        defadr MainInput_strlen,0x143A12B4+1
        defadr MainInput_getPNUM,0x140F7D78+1
        defadr BookObj_GetBookID,0x1416EEE8+1
        defadr wstrncmp,0x14121710+1
        defadr DispObject_GetAbsoluteXPos,0x14117CF8+1
        defadr DispObject_GetAbsoluteYPos,0x14117C40+1
        defadr DispObject_GetWindow,0x1416E350+1
        defadr GetThemeColor,0x1416CA18+1
        defadr REQUEST_SETTING_SILENCE_SET,0x15988374+1
        defadr REQUEST_SETTING_SILENCE_GET,0x141D5040+1
        defadr VCALL_Init,0x14DCA998+1
        defadr VCALL_SetName,0x15367234+1
        defadr VCALL_SetNameIcon,0x15367270+1
        defadr VCALL_SetNumber,0x14DCAED4+1
        defadr VCALL_SetHZ1,0x15367254+1
        defadr VCALL_SetHZ2,0x15367260+1
        defadr MakeVoiceCall,0x14DCAA88+1
        defadr FileDelete,0x14290B3C+1
        defadr GUIObject_SetFocus,0x144ACC78+1
        defadr MSG_SendMessage_CreateMessage,0x1429BA40+1
        defadr MSG_SendMessage_DestroyMessage,0x143E50AC+1
        defadr MSG_SendMessage_AddRecipient,0x15946AE0+1
        defadr MSG_SendMessage_Start,0x14F6A104+1
        defadr get_APP_DESC_TABLE,0x15C48DDC
        defadr Window_GetComponentInterface,0x141A98F0+1
        defadr AB_POSITIONNBR_GET,0x153719D0+1
        defadr AB_NAME_ITEM2StrID,0x15371950+1
        defadr AB_NUM_ITEM2StrID,0x1400E8C4+1
        defadr GetABRecNum,0x142B842C+1
        defadr get_AB_ITEMS_DESC,0x15A4A404
        defadr SBY_GetMainInput,0x1406D170+1
        defadr SBY_GetStatusIndication,0x140722BC+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x142A950C+1
        defadr PID_MMI,0x4BA2CC3C
        defadr DispObject_GetGUI,0x14387AF8+1
        defadr Display_GetFocusedDispObject,0x1416D680+1
        defadr DispObject_GetVisible,0x1416E644+1
        defadr DispObject_GetDESC,0x1556F1F4
        defadr DISP_DESC_SetName,0x14509ED0+1
        defadr DispObject_GetName,0x1416D8B8+1
        defadr DISP_DESC_SetSize,0x14509F1C+1
        defadr DISP_DESC_SetOnCreate,0x14509EC4+1
        defadr DispObject_GetOnCreate,0x144AD3CC+1
        defadr DISP_DESC_SetOnClose,0x14509ECC+1
        defadr DispObject_GetOnClose,0x14119228+1
        defadr DISP_DESC_SetOnRedraw,0x14509F20+1
        defadr DispObject_GetOnRedraw,0x143C82D8+1
        defadr DISP_DESC_SetOnKey,0x1450A328+1
        defadr DispObject_GetOnKey,0x14131DEC+1
        defadr DISP_DESC_SetOnRefresh,0x1450A324+1
        defadr DispObject_GetonRefresh,0x14024894+1
        defadr DISP_DESC_SetMethod06,0x1450A188+1
        defadr DispObject_GetMethod06,0x14118064+1
        defadr DISP_DESC_SetOnLayout,0x1450A2CC+1
        defadr DispObject_GetOnLayout,0x14265910+1
        defadr DISP_DESC_SetOnConfig,0x1450A18C+1
        defadr DispObject_GetOnConfig,0x14256C3C+1
        defadr DISP_DESC_SetMethod0A,0x1450A1FC+1
        defadr DispObject_GetMethod0A,0x141AAA8C+1
        defadr DISP_DESC_SetMethod0B,0x1450A728+1
        defadr DispObject_GetMethod0B,0x15279C08+1
        defadr DISP_DESC_SetMethod0C,0x1450A3EC+1
        defadr JavaSession_Manager,0x142B842C+1
        defadr JavaSession_GetName,0x14000020+1
        defadr BookObj_GetSession,0x14045BB8+1
        defadr GUIonMessage_SetNumberOfSubItems,0x142DA748+1
        defadr GUIonMessage_SubItem_SetText,0x142ABE04+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x142ABB34+1
        defadr GoMusic,0x1553F278+1
        defadr Vibra_Off,0x14277148+1
        defadr PlayFileV,0x15927D6C+1
        defadr GetSilent,0x14274768+1
        defadr GetVibrator,0x14274FA4+1
        defadr GetAudioSettings,0x142748C4+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x141F6AC0+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x15974080+1
        defadr DestroyDirHandle,0x141B5580+1
        defadr LastExtDB,0x15C81490
        defadr GetOtherExtMethods,0x1449FA64+1
        defadr MessageBox,0x15966F9C+1
        defadr Display_GetHeight,0x1411B1D0+1
        defadr Display_GetWidth,0x141AA5B8+1
        defadr PlaySystemSound,0x1447AD20+1
        defadr TabMenuBar_GetFocusedTab,0x141FFEC0+1
        defadr TabMenuBar_SetFocusedTab,0x14513970+1
        defadr GC_GetPenColor,0x144E2224+1
        defadr GC_SetPenColor,0x14107FF4+1
        defadr GC_SetPixel,0x144E21E0+1
        defadr GC_DrawLine,0x144E1F44+1
        defadr GC_DrawFRect,0x1428D204+1
        defadr GC_WritePixels,0x142A93C0+1
        defadr png_create_read_struct_2,0x1402290C+1
        defadr png_destroy_read_struct,0x1412BF34+1
        defadr png_create_info_struct,0x14022D54+1
        defadr png_destroy_info_struct,0x15879F0C+1
        defadr png_set_progressive_read_fn,0x1402284C+1
        defadr png_process_data,0x14022360+1
        defadr png_read_update_info,0x14022E74+1
        defadr png_get_progressive_ptr,0x14028538+1
        defadr png_get_IHDR,0x140232D8+1
        defadr png_set_strip_16,0x1587A270+1
        defadr png_set_gray_1_2_4_to_8,0x1587A27C+1
        defadr png_set_gray_to_rgb,0x1587A294+1
        defadr png_get_valid,0x14E90E84+1
        defadr png_set_tRNS_to_alpha,0x14F5E3B8+1
        defadr png_set_filler,0x1501B960+1
        defadr png_set_palette_to_rgb,0x1587A288+1
        defadr png_get_rowbytes,0x14023440+1
        defadr png_progressive_combine_row,0x1402853C+1
        defadr png_sig_cmp,0x1452E94C+1
        defadr setjmp,0x1014ADA8+1
        defadr longjmp,0x10030310+1
        defadr inflateInit2_,0x1428AED8+1
        defadr inflate,0x14029284+1
        defadr inflateEnd,0x1412BDB0+1
        defadr memcmp,0x14C50D6C
        defadr strncmp,0x141AB5B0+1
        defadr strncpy,0x14443898+1
        defadr strcat,0x1547AE90+1
        defadr GUIObject_SetTitleType,0x143A26B0+1
        defadr GUIonMessage_SetItemDisabled,0x142593D8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1515F1C8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1515F250+1
        defadr get_Surfaces,0x4BD7CCE8
        defadr iconidname2id,0x144C041C+1
        defadr textidname2id,0x144C07AC+1
        defadr ListMenu_SetNoItemText,0x150CE634+1
        defadr IsFmRadioBook,0x14FA18B8+1
        defadr isAudioPlayerBook,0x14271E28+1
        defadr PlayerControl,0x14D899D0+1
        defadr SwitchRadioStationFromList,0x14E73B34+1
        defadr Shortcut_Run,0x1501669C+1
        defadr mkdir,0x140A0DEC+1
        defadr rmdir,0x141B4E38+1
        defadr chmod,0x14344438+1
        defadr rename,0x141B3AC4+1
        defadr CallID_GetCallStatusDesc,0x141A6720+1
        defadr CallStatusDesc_GetName,0x15100658+1
        defadr List_DestroyElements,0x144DE364+1
        defadr strstr,0x142C4EE0+1
        defadr GPRS_GetLastSessionInfo,0x151A0C9C+1
        defadr wstrcmpni,0x144C3DE4+1
        defadr wtoi,0x14122064+1
        defadr DATE_GetWeekDay,0x1435005C+1
        defadr Cale_GetSettings,0x14F9E32C+1
        defadr wstrwstr,0x140F111C+1
        defadr wstrcmpi,0x144C3E28+1
        defadr wstrchr,0x144A2A7C+1
        defadr GUIObject_SoftKeys_Hide,0x14512A9C+1
        defadr GUIObject_SoftKeys_Show,0x143A15B0+1
        defadr DispObject_SoftKeys_Get,0x144659A8+1
        defadr StandbyBackground_SetImage,0x144E0968+1
        defadr CreateYesNoQuestionVA,0x14FDE79C+1
        defadr ListMenu_SetSecondLineText,0x142DA5A4+1
        defadr _REQUEST_OAF_START_APPLICATION,0x14DCD904+1
        defadr FSX_GetInvalidChar,0x140E19DC+1
        defadr DataBrowserDesc_SetFoldersNumber,0x1426BE98+1
        defadr DataBrowserDesc_SetActions,0x1426BE84+1
        defadr DataBrowserDesc_SetSelectAction,0x1426BCEC+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x14F5FE6C+1
        defadr DataBrowserDesc_SetBookID,0x1426BE7C+1
        defadr DataBrowserDesc_SetItemFilter,0x14F5FD0C+1
        defadr DataBrowserDesc_SetOption,0x15862518+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x14F5FE64+1
        defadr DataBrowserDesc_SetFileExtList,0x1426BCD4+1
        defadr FSX_RemoveIllegalSymbolsName,0x14FBB6F0+1
        defadr FILEITEM_Create,0x142DBC60+1
        defadr FILEITEM_Destroy,0x142DB174+1
        defadr CreateDateInputVA,0x14F1C058+1
        defadr CreateTimeInputVA,0x14F1C4A0+1
        defadr StringInput_SetCursorPosition,0x14F544D0+1
        defadr BookObj_CallPage,0x142CB2A0+1
        defadr DateInput_GetDateInt,0x150F3D78+1
        defadr TimeInput_GetTimeInt,0x14EDAB50+1
        defadr GC_GetBrushColor,0x144E4780+1
        defadr GC_SetBrushColor,0x14107EDC+1
        defadr GC_DrawRoundRect,0x14503E08+1
        defadr MenuBook_Desktop,0x141231C4+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x150A0C44+1
        defadr BookObj_SoftKeys_SetAction,0x140673E4+1
        defadr BookObj_SoftKeys_SetText,0x14D610F0+1
        defadr FindBookByID,0x1416ED98+1
        defadr TextFeedbackWindow,0x1423613C+1
        defadr Feedback_SetKeyHook,0x14E08514+1
        defadr Feedback_SetOnClose,0x14236110+1
        defadr Feedback_SetTimeout,0x14D54E30+1
        defadr Feedback_SetTextExtended,0x14235FC8+1
        defadr TabMenuBar_SetOnTabSwitch,0x1406AFB8+1
        defadr KeyCode2Name,0x15652F8C+1
        defadr ImageID_Get,0x144551A8+1
        defadr ImageID_Free,0x14481C98+1
        defadr DataBrowser_CreateSubExecute,0x142DB900+1
        defadr DataBrowser_ExecuteSubroutine,0x14044554+1
        defadr FILEITEM_SetFname,0x142DBB78+1
        defadr FILEITEM_SetPath,0x142DB690+1
        defadr FILEITEM_GetFname,0x142DC118+1
        defadr FILEITEM_GetPath,0x142DC11C+1
        defadr FILEITEM_SetFnameAndContentType,0x142DBD10+1
        defadr FILEITEM_SetPathAndContentType,0x142DB668+1
        defadr JavaDialog_Open,0x14032268+1
        defadr JavaDialog_Close,0x14148DCC+1
        defadr JavaAppDesc_Get,0x14148D64+1
        defadr JavaAppDesc_GetFirstApp,0x14032024+1
        defadr JavaAppDesc_GetNextApp,0x14148F30+1
        defadr JavaAppDesc_GetJavaAppInfo,0x14149AC8+1
        defadr DispObject_SetRefreshTimer,0x14235624+1
        defadr DispObject_KillRefreshTimer,0x14119248+1
        defadr IsDataBrowserBook,0x1404413C+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x142A9B84+1
        defadr Shortcut_Get_MenuItemName,0x145132A8+1
        defadr Shortcut_Get_MenuItemIconID,0x145130B8+1
        defadr FindBookEx,0x1439E89C+1
        defadr FILEITEM_CreateCopy,0x142DB7FC+1
        defadr BookObj_GetSessionID,0x14133F1C+1
        defadr UI_Event_toSID,0x14016150+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x140764B0+1
        defadr MainInput_Hide,0x140FD088+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x14236230+1
        defadr PNUM2Name,0x14FAC5C0+1
        defadr SpeedDial_GetPNUM,0x1537BB3C+1
        defadr DispObject_GetWindowWidth,0x14117C94+1
        defadr DispObject_GetWindowHeight,0x1416DEE8+1
        defadr get_system_langID,0x1450F978+1
        defadr lang_get_name,0x14355920+1
        defadr w_chdir,0x4BA80C30
        defadr w_fopen,0x100B3184+1
        defadr w_fstat,0x100B31C8+1
        defadr w_fwrite,0x100FFA2C+1
        defadr w_fread,0x10100284+1
        defadr w_lseek,0x10646848+1
        defadr w_fclose,0x101487F8+1
        defadr w_mkdir,0x10566A54+1
        defadr DirHandle_SetFilterStr,0x14F18428+1
        defadr ImageID_GetIndirect,0x1515D594+1
        defadr unixtime2datetime,0x1434FD38+1
        defadr List_Insert,0x14104834+1
        defadr FileCopy,0x1403F1E4+1
        defadr FileMove,0x141B3AC4+1
        defadr DispObject_SetLayerColor,0x144AD814+1
        defadr JavaAppDesc_GetJavaAppID,0x141498E0+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x15406254+1
        defadr JavaApp_LogoImageID_Get,0x14EF476C+1
        defadr CreateProgressBar,0x143DCF88+1
        defadr ProgressBar_SetText,0x1597D3DC+1
        defadr ProgressBar_SetIcon,0x14FDBEE8+1
        defadr ProgressBar_SetPercentValue,0x14235C74+1
        defadr ProgressBar_SetBarDisabled,0x1597D3E4+1
        defadr StringInput_DispObject_SetText,0x1422F09C+1
        defadr GUIObject_SetTitleIcon,0x14FEBC74+1
        defadr DispObject_SoftKeys_GetParams,0x1416F044+1
        defadr DispObject_SoftKeys_GetList,0x1416F08C+1
        defadr BookObj_GetDisplayOrientation,0x14046ADC+1
        defadr BookObj_SetDisplayOrientation,0x143A14FC+1
        defadr Display_GetTopBook,0x14F78C3C+1

        defadr Display_GetBrightness,0x150860F0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x14DB6AF8+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x1426BCF4+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1426BE90+1
        defadr SetTheme,0x14DCC90C+1
        defadr SoftKeys_GetLabel,0x1416D698+1
        defadr SoftKeys_Update,0x1416D3F0+1

        defadr IncommingCall_Reject,0x1552DAB0+1
        defadr IncommingCall_Mute,0x14D63EE0+1

        defadr Bluetooth_GetState,0x14510644+1
        defadr Bluetooth_GetPhoneVisibility,0x14E46778+1
        defadr Bluetooth_isBusy,0x1451085C+1
        defadr USB_isConnected,0x15276D30+1
        defadr w_diropen,0x14115ED4+1
        defadr w_dirread,0x1409E128+1
        defadr w_dirclose,0x4BA80C10
        defadr w_rename,0x141B4298+1
        defadr w_remove,0x141B45E8+1


        defadr IsCameraBook,0x141637EC+1
        defadr IsSoundRecorderBook,0x15552494+1
        defadr StringInput_MenuItem_SetPriority,0x14FD7550+1
        defadr RightNow_SetActive,0x14492A84+1
        defadr CreatePercentInputVA,0x15829A8C+1
        defadr PercentInput_GetPercent,0x15829C2C+1
        defadr GUIonMessage_SetLineSeparator,0x15974050+1
        defadr PHF_GetState,0x15297434+1
        defadr CHF_GetState,0x152974C0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A1690+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x143A14F0+1
        defadr SetTrayIcon,0x1416A86C+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x159881B8+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x1598830C+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x159882D0+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x159883E0+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x15988270+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x14FAE214+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x1534444C+1
        defadr SoundRecorderDesc_Create,0x155519E0+1
        defadr SoundRecorderDesc_Destroy,0x15551A3C+1
        defadr SoundRecorderDesc_SetBookID,0x15551A54+1
        defadr SoundRecorderDesc_SetType,0x15551A80+1
        defadr SoundRecorderDesc_SetFolder,0x15551A94+1
        defadr SoundRecorderDesc_SetFname,0x15551AB0+1
        defadr SoundRecorderDesc_SetRecordSize,0x15551ACC+1
        defadr SoundRecorder_Create,0x15551B44+1
        defadr SoundRecorder_RecordCall,0x15528BC0+1
        defadr Browser_OpenURI,0x14296F50+1
        defadr GetURIScheme,0x140B4538+1
        defadr CreateURI,0x140B41FC+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x14DB705C+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x15056FDC+1
        defadr Alarm_GetState,0x14350450+1
        defadr Alarm_GetTIME,0x15160CCC+1
        defadr Alarm_GetWeekSettings,0x143502F0+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x141D4D94+1
        defadr IncommingCall_Accept,0x14E59D3C+1
        defadr MediaPlayer_SoftKeys_SetText,0x140B4B28+1
        defadr MediaPlayer_SoftKeys_SetAction,0x140B4B58+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x140B4D58+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x140B4D88+1
        defadr DispObject_Show,0x1416B910+1
        defadr Request_EventChannel_Subscribe,0x10941B7C+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x14DC75A8+1
        defadr Request_ICA_ShutdownAllConnections,0x104FD120+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x150CEB88+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x15862518+1
        defadr GUIonMessage_GetMsg,0x142F1378+1
        defadr GUIonMessage_GetBook,0x142F1290+1
        defadr GUIonMessage_GetGui,0x142F0E68+1
        defadr GUIonMessage_GetSelectedItem,0x14067918+1
        defadr GUIonMessage_GetPrevSelectedItem,0x1597405C+1
        defadr ObexSendFile,0x150B43C4+1
        defadr Feedback_SetManualScrollingText,0x14D97444+1
        defadr EqualizerGain_Set,0x1431BD98+1
        defadr CANVAS_Get_GviGC,0x100AED74+1
        defadr GVI_BitBlt,0x100AEA58+1
        defadr GVI_StretchBlt,0x1052BB60+1
        defadr GVI_TransformBlt,0x10129944+1
        defadr GVI_CreatePen,0x1016D73C+1
        defadr GVI_CreateDashedPen,0x102C2764+1
        defadr GVI_CreateSolidBrush,0x100BA498+1
        defadr GVI_Delete_GVI_Object,0x1004DC6C+1
        defadr GVI_DrawEllipse,0x1052B644+1
        defadr GVI_DrawLine,0x100A2AE0+1
        defadr GVI_DrawLines,0x1052C534+1
        defadr GVI_DrawPolyLine,0x1052C5B8+1
        defadr GVI_DrawRectangle,0x101881EC+1
        defadr GVI_DrawRoundRect,0x100A401C+1
        defadr GVI_DrawSolidLines,0x1052C164+1
        defadr GVI_DrawSolidPolyLine,0x1052C368+1
        defadr GVI_DrawSolidRectangle,0x10187F68+1
        defadr GVI_FillEllipse,0x1052BA28+1
        defadr GVI_FillPolygon,0x100A4A44+1
        defadr GVI_FillRectangle,0x100A27FC+1
        defadr GVI_FillRectangles,0x1052C6B4+1
        defadr GVI_FillSolidEllipse,0x1052BAD8+1
        defadr GVI_FillSolidRectangle,0x1012F15C+1
        defadr GVI_FillSolidRoundRect,0x10273AD8+1
        defadr GVI_FillSolidTriangle,0x1000F274+1
        defadr GC_CreateMemoryGC,0x144E1898+1
        defadr GC_FreeGC,0x141190A4+1
        defadr Settings_ShowNumber_Get,0x154FF9A0+1
        defadr GVI_CreateBitmap,0x1052A338+1
        defadr GVI_CreateMemoryGC,0x1004D700+1
        defadr GVI_DeleteMemoryGC,0x10114B28+1
        defadr StringInput_DispObject_SetLanguage,0x1410EECC+1
        defadr List_InsertSorted,0x144AAF54+1
        defadr ListMenu_SetItemIcon,0x142F2394+1
        defadr wstrnupr,0x141B1570+1
        defadr wstrnlwr,0x1400CBB0+1
        defadr ListMenu_SetItemTextScroll,0x14110BEC+1

        defadr GUIObject_SetListTextColor,0x15974604+1
        defadr DispObject_SetTitleTextColor,0x14E3E77C+1
        defadr DispObject_SetListTextColor,0x14E3D4D4+1
        defadr DispObject_SetCursorImage,0x14E3DEFC+1
        defadr DispObject_SetBackgroundImage,0x150A39A0+1
        defadr DispObject_SetTitleBackgroundImage,0x14E3E7A8+1
        defadr TabMenuBar_SetTabTitle,0x1402BD70+1
        defadr GUIObject_GetBook,0x14105460+1
        defadr SoftKeys_GetSelectedAction,0x1447A728+1
        defadr MonitorFeedback_SetTimer,0x15967810+1
        defadr ListMenu_DestroyItems,0x143C3870+1
        defadr DispObject_SetScrollBarBackgroundColor,0x15422864+1
        defadr DispObject_SetScrollBarColor,0x14422098+1
        defadr DispObject_SetSoftkeysColor,0x1411BC00+1
        defadr YesNoQuestion_SetIcon,0x150C67E4+1
        defadr GUIObject_SetBacklightTimeout,0x142377AC+1
        defadr ListMenu_SetHotkeyMode,0x1411BC80+1
        defadr ListMenu_SetSearchLanguageMode,0x1450BDC8+1
        defadr ListMenu_EnableSearchHeader,0x58863C14+1
        defadr GUIonMessage_GetSearchString,0x159740F4+1
        defadr GUIonMessage_GetSearchStringLength,0x15974114+1
        defadr EqualizerGain_Get,0x15927598+1
        defadr Theme_DestroyMenuIcons,0x14E8737C+1
        defadr CoCreateInstance,0x14461E40+1
        defadr GUIObject_SetSecondRowTitleText,0x144D6804+1
        defadr ListMenu_GetItemCount,0x1413E840+1
        defadr OSE_GetShell,0x1416A1B0+1
        defadr swscanf,0x143992B4+1
        defadr sscanf,0x101E9D24+1
	defadr DisplayGC_AddRef,0x143D02EC+1
//////////////////
	defadr DefaultRedraw,0x14201574+1
        defadr DefaultOnNewTrack,0x140B5070+1
///////////////
        
        defadr FmRadio_Gui_OnCreate,0x14EE8714+1 
        defadr FmRadio_Gui_OnClose,0x14F6D2C0+1
        defadr FmRadio_Gui_OnRedraw,0x15040D34+1
        defadr FmRadio_Gui_OnKey,0x15089570+1
        defadr FmRadio_Gui_OnMethod0A,0x14D4A868+1
        
        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x14F5472C+1
        //defadr pg_FmRadio_Main__PAGE_EXIT_EVENT,0x1564EA48+1
        //defadr pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT,0x1132B580+1
        
        EXTERN New_FmRadio_Gui_OnCreate
        EXTERN New_FmRadio_Gui_OnClose
        EXTERN New_FmRadio_Gui_OnRedraw
        EXTERN New_FmRadio_Gui_OnKey
        EXTERN New_FmRadio_Gui_OnLayout
        EXTERN New_FmRadio_Gui_OnRefresh
        
        EXTERN FmRadio_NewSoftKey
        
        EXTERN LoadData
        EXTERN DeleteData
        
        EXTERN New_FmRadio_Main__PAGE_ENTER_EVENT
        EXTERN New_FmRadio_Main__PAGE_EXIT_EVENT
        EXTERN New_FmRadio_Base__UI_FMRADIO_CREATED_EVENT

        RSEG PATCH_FmRadio_OnCreate
        DATA
        DCD New_FmRadio_Gui_OnCreate

        RSEG PATCH_FmRadio_OnClose
        DATA
        DCD New_FmRadio_Gui_OnClose
        
        RSEG PATCH_FmRadio_OnRedraw
        DATA
        DCD New_FmRadio_Gui_OnRedraw
        
        RSEG PATCH_FmRadio_OnKey
        DATA
        DCD New_FmRadio_Gui_OnKey

        
        RSEG PATCH_FmRadio_MainPage_Enter
        DATA
        DCD New_FmRadio_Main__PAGE_ENTER_EVENT
        
//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_DeleteData
        CODE16
        LDR	R3, =delete_data
	BX	R3

        RSEG  CODE
        CODE16
delete_data: 
        CMP     R1, #0
        BEQ     nex_
        ADD     R0, R1, #0
        LDR     R1, [R1,#0]
        LDR     R1, [R1,#0xC]
        BLX     R1
        MOV     R0, #0
        STR     R0, [R4,#8]
        
nex_:
        BL      DeleteData
        POP     {R3-R7,PC}

//------------------------------------------------------------------------------
        
        RSEG PATCH_FmRadio_NewRefresh
	CODE16
	LDR	R3, =new_disp_desc
	BX	R3

        RSEG  CODE
        CODE16
new_disp_desc:
        LDR     R1, =FmRadio_Gui_OnMethod0A
        ADD     R0, R4, #0
        LDR	R3, =DISP_DESC_SetMethod0A
	BLX	R3
        ADD     R0, R4, #0
        BL      New_FmRadio_Gui_OnRefresh
        MOV     R1, #0
        ADD     R0, R4, #0
        BL      New_FmRadio_Gui_OnLayout
        POP     {R4,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_NewSoftKey
	CODE16
	LDR	R3, =new_softkey
	BX	R3

        RSEG  CODE
        CODE16
new_softkey:
        LDR     R0, [R4,#0x18]
        MOV     R1, #5
        LDR	R3, =GUIObject_SoftKeys_SetInfoText 
        BLX     R3
        LDR     R0, [R4,#0x18]
        BL      FmRadio_NewSoftKey
        LDR	R3, =0x1132ACE4+1
	BX	R3

//------------------------------------------------------------------------------
        
        RSEG PATCH_FmRadio_UpdateSoftKey
	CODE16
	LDR	R3, =update_softkey
	BX	R3

        RSEG  CODE
        CODE16
update_softkey:
         LDR    R0, [R4,#0x18]
         ADD    R2, R5, #0
         MOV    R1, #3
         LDR	R3, =GUIObject_SoftKeys_SetVisible
         BLX	R3
         LDR    R0, [R4,#0x18]
         ADD    R2, R5, #0
         MOV    R1, #0x1F
         LDR	R3, =GUIObject_SoftKeys_SetVisible
         BLX	R3
         LDR	R3, =0x1132AE2E+1
         BX	R3
        
#endif
          END
          