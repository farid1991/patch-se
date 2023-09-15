//C901_R1GA028

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA322A0
        defadr memfree,0x4BA322C8
        defadr memset,0x14B963E8
        defadr memcpy,0x15020818
        defadr sprintf,0x142D6C4C+1
        defadr snwprintf,0x144A1298+1
        defadr _fopen,0x1403EC8C+1
        defadr fclose,0x140FC858+1
        defadr fread,0x144C11BC+1
        defadr fwrite,0x141BFE70+1
        defadr fstat,0x14290474+1
        defadr AllocDirHandle,0x144C04AC+1
        defadr GetFname,0x144C0E00+1
        defadr DataBrowserDesc_Create,0x1426A8E4+1
        defadr DataBrowserDesc_SetItemStyle,0x14187314+1
        defadr DataBrowserDesc_SetHeaderText,0x1426AA84+1
        defadr DataBrowserDesc_SetFolders,0x1426A878+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x1426A858+1
        defadr DataBrowser_Create,0x14449F20+1
        defadr DataBrowserDesc_Destroy,0x1426A994+1
        defadr getFileExtention,0x144DCC70+1
        defadr DataBrowser_isFileInListExt,0x140E16F0+1
        defadr Timer_ReSet,0x14169C08+1
        defadr Timer_Set,0x1423CE6C+1
        defadr Timer_Kill,0x14169EF8+1
        defadr CreateBook,0x144AA4FC+1
        defadr BookObj_KillBook,0x14045810+1
        defadr BookObj_GotoPage,0x1404559C+1
        defadr BookObj_ReturnPage,0x142C9B50+1
        defadr FreeBook,0x14132BCC+1
        defadr FindBook,0x1416DA64+1
        defadr Find_StandbyBook,0x14386DBC+1
        defadr BookObj_SetFocus,0x1450FD74+1
        defadr GUIObject_SetTitleText,0x1410F8F0+1
        defadr GUIObject_Show,0x144AB150+1
        defadr ListMenu_SetCursorToItem,0x14131CB8+1
        defadr GUIObject_SetStyle,0x141320D8+1
        defadr DispObject_SetStyle,0x141A88BC+1
        defadr GUIObject_GetStyle,0x1416CEB8+1
        defadr DispObject_GetStyle,0x1416CE50+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142EFB80+1
        defadr GUIonMessage_SetMenuItemText,0x142EF65C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FDDAC+1
        defadr GUIonMessage_SetMenuItemInfoText,0x1406799C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14EE9D88+1
        defadr GUIonMessage_SetMenuItemIcon,0x14044EB0+1
        defadr DispObject_SetTitleText,0x1410FAB0+1
        defadr ListMenu_GetSelectedItem,0x1411B32C+1
        defadr ListMenu_SetItemStyle,0x140F5D1C+1
        defadr IsScreenSaverBook,0x143C32E4+1
        defadr StatusIndication_SetItemText,0x1434DD20+1
        defadr StatusIndication_ShowNotes,0x153E7F90+1
        defadr CreateStringInputVA,0x1512E448+1
        defadr CreateOneOfMany,0x140F5CA0+1
        defadr OneOfMany_SetItemCount,0x15011E10+1
        defadr OneOfMany_SetChecked,0x14110A9C+1
        defadr OneOfMany_SetTexts,0x141ACEE0+1
        defadr OneOfMany_GetSelected,0x14FE1FE4+1
        defadr StatusIndication_Item8_SetText,0x14D91388+1
        defadr GUIObject_SoftKeys_SetAction,0x141047B0+1
        defadr GUIObject_SoftKeys_SetText,0x141044E8+1
        defadr GUIObject_SoftKeys_SetEnable,0x14104BBC+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x144A7110+1
        defadr GUIObject_SoftKeys_RemoveItem,0x143CBE3C+1
        defadr GUIObject_SoftKeys_SetVisible,0x1410478C+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x140465D8+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x150233B4+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x141C4620+1
        defadr wstrcpy,0x1428FE70+1
        defadr wstrncpy,0x144A13E4+1
        defadr wstrcat,0x1428FDC8+1
        defadr wstrncat,0x144C175C+1
        defadr wstrcmp,0x144BF47C+1
        defadr wstrlen,0x144C1510+1
        defadr str2wstr,0x1428E948+1
        defadr strcmp,0x14C80394+1
        defadr strlen,0x14C803F0+1
        defadr wstr2strn,0x1409DB7C+1
        defadr AB_DEFAULTNBR_GET,0x14490024+1
        defadr AB_READPHONENBR,0x15278BE8+1
        defadr AB_GETNBROFITEMS,0x1450E45C+1
        defadr PNUM_len,0x140F735C+1
        defadr PNUM2str,0x14D75F78+1
        defadr GUIObject_GetDispObject,0x1416CEAC+1
        defadr List_Create,0x14103984+1
        defadr List_Destroy,0x14103A7C+1
        defadr List_InsertFirst,0x14103BE8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14DF8334+1
        defadr REQUEST_DATEANDTIME_GET,0x1434E558+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x14487AB8+1
        defadr GetFreeBytesOnHeap,0x142F20E4+1
        defadr BookObj_Hide,0x142009DC+1
        defadr BookObj_Show,0x14036010+1
        defadr StartAPP,0x14F8C180+1
        defadr ListMenu_SetOnMessage,0x142D9214+1
        defadr manifest_GetParam,0x141A9A84+1
        defadr lseek,0x144C3468+1
        defadr get_VBUFFER,0x00000000
        defadr SetLampLevel,0x141A7708+1
        defadr List_RemoveAt,0x1416A258+1
        defadr GetCurrentPID,0x101D58A0+1
        defadr List_IndexOf,0x1416A574+1
        defadr alloc,0x101CE960
        defadr receive,0x101CE97C
        defadr send,0x101CE96C
        defadr sender,0x101CE9BC
        defadr free_buf,0x101CE98C
        defadr create_process,0x101CEA58
        defadr start,0x101CEC64
        defadr get_ptype,0x101CEB18
        defadr current_process,0x101CEA68
        defadr delay,0x101CE9AC
        defadr hunt,0x101CEB64
        defadr kill_proc,0x101CEB90
        defadr receive_w_tmo,0x101CE9D8
        defadr stop,0x101CEC74
        defadr get_envp,0x101D5524+1
        defadr set_envp,0x101D5538+1
        defadr get_bid,0x101CEAA0
        defadr datetime2unixtime,0x14497BF0+1
        defadr strcpy,0x14C803BC+1
        defadr UIEventName,0x144F6E60+1
        defadr MissedEvents,0x4BA1B16C
        defadr UI_Event,0x1439F6E8+1
        defadr UI_Event_wData,0x141054D4+1
        defadr UI_Event_toBookID,0x1439CE14+1
        defadr UI_Event_toBookIDwData,0x142A8394+1
        defadr List_Find,0x1416D8A8+1
        defadr List_Get,0x1416DA4C+1
        defadr List_GetCount,0x1416DA60+1
        defadr wstrrchr,0x1409EB58+1
        defadr BookObj_CallSubroutine,0x142C9CE8+1
        defadr List_InsertLast,0x14169E04+1
        defadr debug_printf,0x14BAE55C
        defadr PlayFile,0x158028AC+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x141D3568+1
        defadr Profile_SetActive,0x15875B5C+1
        defadr isKeylocked,0x1449D040+1
        defadr IsMediaPlayerVideoBook,0x144F87AC+1
        defadr REQUEST_DATEFORMAT_GET,0x1434E66C+1
        defadr REQUEST_TIMEFORMAT_GET,0x1434E6CC+1
        defadr Date2ID,0x14387ABC+1
        defadr Time2ID,0x1434DFF4+1
        defadr CreateListMenu,0x141322D4+1
        defadr ListMenu_SetItemCount,0x142D9228+1
        defadr ROOT_APP,0x4BA26820
        defadr GUIObject_SoftKeys_SetInfoText,0x140A6774+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x141047FC+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x10469A3C+1
        defadr REQUEST_SYSTEM_RESTART,0x10469A5C+1
        defadr GUIObject_SoftKeys_SetTexts,0x140A67AC+1
        defadr IsRightNowBook,0x1400F594+1
        defadr IsVolumeControllerBook,0x141A6568+1
        defadr CreateTabMenuBar,0x1433BC58+1
        defadr TabMenuBar_SetTabCount,0x1426E1D8+1
        defadr TabMenuBar_SetTabGui,0x145113D0+1
        defadr TabMenuBar_SetTabIcon,0x142F22F0+1
        defadr GUIObject_Destroy,0x14510368+1
        defadr GUIInput_SetIcon,0x14E60884+1
        defadr StringInput_GetStringAndLen,0x1410D648+1
        defadr GetAudioControlPtr,0x4BA2CB68
        defadr AudioControl_Vibrate,0x143C7508+1
        defadr GetVolumeSize,0x14290BEC+1
        defadr CreateNOfMany,0x14F610D4+1
        defadr NOfMany_SetTexts,0x14F60FDC+1
        defadr NOfMany_SetChecked,0x1584E160+1
        defadr NOfMany_SetCursor,0x14FD69C4+1
        defadr NOfMany_GetCheckedCount,0x1501E664+1
        defadr NOfMany_GetChecked,0x1584E174+1
        defadr NOfMany_SetOnMessage,0x1584E198+1
        defadr AudioControl_Init,0x143D85F8+1
        defadr OneOfMany_SetFocused,0x15011BC8+1
        defadr OneOfMany_SetOnMessage,0x14CFCE40+1
        defadr CreateMonitorFeedback,0x158410F0+1
        defadr Feedback_SetText,0x158411A0+1
        defadr GetBatteryState,0x101690EC+1
        defadr get_DisplayGC,0x1416BB04+1
        defadr DispObject_GetRect,0x1416AE14+1
        defadr GC_GetRect,0x14116F48+1
        defadr GC_GetXX,0x142320E0+1
        defadr GC_SetXX,0x1419BFB4+1
        defadr GC_ValidateRect,0x143CEE68+1
        defadr BookObj_AddGUIObject,0x141322C8+1
        defadr DrawRect,0x14107010+1
        defadr XGUIList_AddGUIObject,0x140456B8+1
        defadr DispObject_InvalidateRect,0x1416AB80+1
        defadr GUIObject_Create,0x144AB648+1
        defadr StatusRow_p,0x4BA2B414
        defadr root_list_get_session_count,0x1406F774+1
        defadr root_list_get_session,0x14104DDC+1
        defadr SESSION_GetTopBook,0x144BE69C+1
        defadr MainInput_strlen,0x1439FC2C+1
        defadr MainInput_getPNUM,0x140F6F98+1
        defadr BookObj_GetBookID,0x1416DFD4+1
        defadr wstrncmp,0x14120ACC+1
        defadr DispObject_GetAbsoluteXPos,0x141170D0+1
        defadr DispObject_GetAbsoluteYPos,0x14117018+1
        defadr GetThemeColor,0x1416BB10+1
        defadr REQUEST_SETTING_SILENCE_SET,0x15861B74+1
        defadr REQUEST_SETTING_SILENCE_GET,0x141D3B38+1
        defadr VCALL_Init,0x14D0EDD8+1
        defadr VCALL_SetName,0x1526E798+1
        defadr VCALL_SetNameIcon,0x15127E4A+1
        defadr VCALL_SetNumber,0x14D0F2F0+1
        defadr VCALL_SetHZ1,0x1526E7B8+1
        defadr VCALL_SetHZ2,0x1526E7C4+1
        defadr MakeVoiceCall,0x14D0EEC8+1
        defadr FileDelete,0x1428F4EC+1
        defadr GUIObject_SetFocus,0x144AB19C+1
        defadr MSG_SendMessage_CreateMessage,0x1429A488+1
        defadr MSG_SendMessage_DestroyMessage,0x143E3B3C+1
        defadr MSG_SendMessage_AddRecipient,0x15821580+1
        defadr MSG_SendMessage_Start,0x14EAE22C+1
        defadr get_APP_DESC_TABLE,0x15B0AA9C
        defadr AB_POSITIONNBR_GET,0x15278D44+1
        defadr AB_NAME_ITEM2TextID,0x15278CD0+1
        defadr AB_NUM_ITEM2TextID,0x1400E818+1
        defadr GetABRecNum,0x1424EC32+1
        defadr get_AB_ITEMS_DESC,0x15913050+1
        defadr SBY_GetMainInput,0x143F9B9A+1
        defadr SBY_GetStatusIndication,0x143F9B96+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x142A811C+1
        defadr PID_MMI,0x4BA2B1D4
        defadr DispObject_GetGUI,0x14386110+1
        defadr Display_GetFocusedDispObject,0x1416C778+1
        defadr DispObject_GetVisible,0x1416D73C+1
        defadr DispObject_GetDESC,0x15080484+1
        defadr DISP_DESC_SetName,0x145076E0+1
        defadr DispObject_GetName,0x1416C9B0+1
        defadr DISP_DESC_SetSize,0x1450772C+1
        defadr DISP_DESC_SetOnCreate,0x145076D4+1
        defadr DispObject_GetOnCreate,0x144AB8F0+1
        defadr DISP_DESC_SetOnClose,0x145076DC+1
        defadr DispObject_GetOnClose,0x14118658+1
        defadr DISP_DESC_SetOnRedraw,0x14507730+1
        defadr DispObject_GetOnRedraw,0x143C6DDC+1
        defadr DISP_DESC_SetOnKey,0x14507B38+1
        defadr DispObject_GetOnKey,0x141311AC+1
        defadr DISP_DESC_SetOnRefresh,0x14507B34+1
        defadr DispObject_GetonRefresh,0x14024B74+1
        defadr DISP_DESC_SetMethod06,0x14507998+1
        defadr DispObject_GetMethod06,0x1411743C+1
        defadr DISP_DESC_SetOnLayout,0x14507ADC+1
        defadr DispObject_GetOnLayout,0x142643D4+1
        defadr DISP_DESC_SetOnConfig,0x1450799C+1
        defadr DispObject_GetOnConfig,0x142557C0+1
        defadr DISP_DESC_SetMethod0A,0x14507A0C+1
        defadr DispObject_GetMethod0A,0x141A9604+1
        defadr DISP_DESC_SetMethod0B,0x14507F38+1
        defadr DISP_DESC_SetMethod0C,0x14507BFC+1
        defadr JavaSession_Manager,0x1424EC32+1
        defadr JavaSession_GetName,0x14E1F540+1
        defadr BookObj_GetSession,0x140457D4+1
        defadr GUIonMessage_SetNumberOfSubItems,0x142D923C+1
        defadr GUIonMessage_SubItem_SetText,0x142AAA00+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x142AA75C+1
        defadr GoMusic,0x15433A58+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x1584D8AC+1
        defadr GUIonMessage_SubItem_SetDisabled,0x1584D8D0+1
        defadr PlayFileV,0x143D8544+1
        defadr GetSilent,0x142730E8+1
        defadr GetVibrator,0x142738F4+1
        defadr GetAudioSettings,0x14273244+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x141F5554+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x1584D8B8+1
        defadr DestroyDirHandle,0x141B40D4+1
        defadr LastExtDB,0x15B415AC
        defadr GetOtherExtMethods,0x1449DE18+1
        defadr MessageBox,0x15840928+1
        defadr Display_GetHeight,0x1411A5F8+1
        defadr Display_GetWidth,0x141A9130+1
        defadr PlaySystemSound,0x14478F78+1
        defadr TabMenuBar_GetFocusedTab,0x141FE8E0+1
        defadr TabMenuBar_SetFocusedTab,0x145110E0+1
        defadr GC_GetPenColor,0x14E1AE08+1
        defadr GC_SetPenColor,0x14107384+1
        defadr GC_SetPixel,0x144E05E0+1
        defadr GC_DrawLine,0x144E0344+1
        defadr GC_DrawFRect,0x1428BBB8+1
        defadr GC_WritePixels,0x142A7FD0+1
        defadr png_create_read_struct_2,0x14022BFC+1
        defadr png_destroy_read_struct,0x1412B310+1
        defadr png_create_info_struct,0x14023044+1
        defadr png_destroy_info_struct,0x15754D60+1
        defadr png_set_progressive_read_fn,0x14022B3C+1
        defadr png_process_data,0x14022650+1
        defadr png_read_update_info,0x14023164+1
        defadr png_get_progressive_ptr,0x1404F430+1
        defadr png_get_IHDR,0x140235C8+1
        defadr png_set_strip_16,0x157550C4+1
        defadr png_set_gray_1_2_4_to_8,0x157550D0+1
        defadr png_set_gray_to_rgb,0x157550E8+1
        defadr png_get_valid,0x14DD564C+1
        defadr png_set_tRNS_to_alpha,0x157550DC+1
        defadr png_set_filler,0x14F5F390+1
        defadr png_set_palette_to_rgb,0x14EA24C4+1
        defadr png_get_rowbytes,0x14023730+1
        defadr png_progressive_combine_row,0x14028810+1
        defadr png_sig_cmp,0x1452BFF8+1
        defadr setjmp,0x1429E27C+1
        defadr longjmp,0x14C7F774+1
        defadr inflateInit2_,0x14289788+1
        defadr inflate,0x14029558+1
        defadr inflateEnd,0x1412B18C+1
        defadr memcmp,0x107617E8
        defadr strncmp,0x141AA128+1
        defadr strncpy,0x14442270+1
        defadr strcat,0x1000188C+1
        defadr GUIObject_SetTitleType,0x143A114C+1
        defadr GUIonMessage_SetItemDisabled,0x14257F3C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150A1E5C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x150A1EE4+1
        defadr get_Surfaces,0x4BD57DC8
        defadr iconidname2id,0x144BE870+1
        defadr textidname2id,0x144BEC00+1
        defadr ListMenu_SetNoItemText,0x15011AF0+1
        defadr IsFmRadioBook,0x14EE591C+1
        defadr IsAudioPlayerBook,0x14270984+1
        defadr PlayerControl,0x14CCE0D4+1
        defadr SwitchRadioStationFromList,0x14DB8354+1
        defadr Shortcut_Run,0x14F5A128+1
        defadr mkdir,0x140A0018+1
        defadr rmdir,0x141B398C+1
        defadr chmod,0x14342BA4+1
        defadr rename,0x141B2608+1
        defadr CallID_GetCallStatusDesc,0x141A5260+1
        defadr CallStatusDesc_GetName,0x1003F664+1
        defadr List_DestroyElements,0x144DC760+1
        defadr strstr,0x142C3AE4+1
        defadr GPRS_GetLastSessionInfo,0x150E2CEC+1
        defadr wstrcmpni,0x144C2220+1
        defadr wtoi,0x14121418+1
        defadr DATE_GetWeekDay,0x1434E714+1
        defadr Cale_GetSettings,0x14EE239C+1
        defadr wstrwstr,0x140F0350+1
        defadr wstrcmpi,0x144C2264+1
        defadr wstrchr,0x144A0E24+1
        defadr GUIObject_SoftKeys_Hide,0x14510224+1
        defadr GUIObject_SoftKeys_Show,0x1439FF34+1
        defadr DispObject_SoftKeys_Show,0x14510238+1
        defadr DispObject_SoftKeys_Hide,0x1439FF40+1
        defadr DispObject_SoftKeys_Get,0x14463CC8+1
        defadr StandbyBackground_SetImage,0x144DED68+1
        defadr CreateYesNoQuestionVA,0x14F22198+1
        defadr ListMenu_SetItemSecondLineText,0x142D9098+1
        defadr _REQUEST_OAF_START_APPLICATION,0x14D11CE4+1
        defadr FSX_GetInvalidChar,0x140E0C60+1
        defadr DataBrowserDesc_SetFoldersNumber,0x1426AA14+1
        defadr DataBrowserDesc_SetActions,0x14CFB778+1
        defadr DataBrowserDesc_SetSelectAction,0x1426A868+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x14EA3F60+1
        defadr DataBrowserDesc_SetBookID,0x1426A9F8+1
        defadr DataBrowserDesc_SetItemFilter,0x14EA3E00+1
        defadr DataBrowserDesc_SetOption,0x1426AA1C+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x14EA3F58+1
        defadr DataBrowserDesc_SetFileExtList,0x1426A850+1
        defadr FSX_RemoveIllegalSymbolsName,0x14EFF494+1
        defadr FILEITEM_Create,0x142DA754+1
        defadr FILEITEM_Destroy,0x142D9C68+1
        defadr CreateDateInputVA,0x14E60578+1
        defadr CreateTimeInputVA,0x14E609C8+1
        defadr StringInput_SetCursorPosition,0x14E98714+1
        defadr BookObj_CallPage,0x142C9EBC+1
        defadr DateInput_GetDateInt,0x15036DE8+1
        defadr TimeInput_GetTimeInt,0x14E1F17C+1
        defadr GC_GetBrushColor,0x144E2B84+1
        defadr GC_SetBrushColor,0x1410726C+1
        defadr GC_DrawRoundRect,0x1450176C+1
        defadr MenuBook_Desktop,0x14122578+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x14FE4178+1
        defadr BookObj_SoftKeys_SetAction,0x14066FCC+1
        defadr BookObj_SoftKeys_SetText,0x14CA59B4+1
        defadr FindBookByID,0x1416DE8C+1
        defadr TextFeedbackWindow,0x14234A68+1
        defadr Feedback_SetKeyHook,0x14D4C8C0+1
        defadr Feedback_SetOnClose,0x14234A3C+1
        defadr Feedback_SetTimeout,0x14C998A4+1
        defadr Feedback_SetTextExtended,0x142348F4+1
        defadr TabMenuBar_SetOnTabSwitch,0x1406ABB8+1
        defadr KeyCode2Name,0x15541010+1
        defadr ImageID_Get,0x14453B38+1
        defadr ImageID_Free,0x1447FEEC+1
        defadr DataBrowser_CreateSubExecute,0x142DA3F4+1
        defadr DataBrowser_ExecuteSubroutine,0x14044190+1
        defadr FILEITEM_SetFname,0x142DA66C+1
        defadr FILEITEM_SetPath,0x142DA184+1
        defadr FILEITEM_GetFname,0x142DAC0C+1
        defadr FILEITEM_GetPath,0x142DAC10+1
        defadr FILEITEM_SetFnameAndContentType,0x142DA804+1
        defadr FILEITEM_SetPathAndContentType,0x142DA15C+1
        defadr JavaDialog_Open,0x14032514+1
        defadr JavaDialog_Close,0x14147D2C+1
        defadr JavaAppDesc_Get,0x14147CC4+1
        defadr JavaAppDesc_GetFirstApp,0x140322E0+1
        defadr JavaAppDesc_GetNextApp,0x14147E90+1
        defadr JavaAppDesc_GetJavaAppInfo,0x14148A28+1
        defadr DispObject_SetRefreshTimer,0x14233F70+1
        defadr DispObject_KillRefreshTimer,0x14118678+1
        defadr IsDataBrowserBook,0x14043D78+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x142A8794+1
        defadr Shortcut_Get_MenuItemName,0x14510A24+1
        defadr Shortcut_Get_MenuItemIconID,0x14510838+1
        defadr FindBookEx,0x1439D200+1
        defadr FILEITEM_CreateCopy,0x142DA2F0+1
        defadr ImageID_Copy,0x14044F58+1
        defadr BookObj_GetSessionID,0x141332B4+1
        defadr UI_Event_toSID,0x14016464+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x140760A0+1
        defadr MainInput_Hide,0x14D755DC+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x14234B5C+1
        defadr PNUM2Name,0x14EF04E0+1
        defadr SpeedDial_GetPNUM,0x15282BD8+1
        defadr DispObject_GetWindowWidth,0x1416B120+1
        defadr DispObject_GetWindowHeight,0x1416CFE0+1
        defadr get_system_langID,0x1450D138+1
        defadr lang_get_name,0x14354004+1
        defadr w_chdir,0x104FB3C4+1
        defadr w_fopen,0x100A6A24+1
        defadr w_fstat,0x100A6A68+1
        defadr w_fwrite,0x100F1F80+1
        defadr w_fread,0x100F27D8+1
        defadr w_lseek,0x10586FD8+1
        defadr w_fclose,0x10139508+1
        defadr w_mkdir,0x104F6BB0+1
        defadr DirHandle_SetFilterStr,0x14E5C980+1
        defadr ImageID_GetIndirect,0x150A0228+1
        defadr unixtime2datetime,0x1434E3F0+1
        defadr List_Insert,0x144A90E4+1
        defadr FileCopy,0x1403F314+1
        defadr FileMove,0x141B2608+1
        defadr DispObject_SetLayerColor,0x144ABD2C+1
        defadr JavaAppDesc_GetJavaAppID,0x14148840+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x153025BC+1
        defadr JavaApp_LogoImageID_Get,0x14E38D3C+1
        defadr CreateProgressBar,0x143DBAA8+1
        defadr ProgressBar_SetText,0x14234860+1
        defadr ProgressBar_SetIcon,0x14F1FACC+1
        defadr ProgressBar_SetPercentValue,0x142345C0+1
        defadr ProgressBar_SetBarDisabled,0x142A8100+1
        defadr StringInput_DispObject_SetText,0x1422D9DC+1
        defadr GUIObject_SetTitleIcon,0x14F2F560+1
        defadr DispObject_SoftKeys_GetParams,0x1416E130+1
        defadr DispObject_SoftKeys_GetList,0x1416E178+1
        defadr BookObj_GetDisplayOrientation,0x140466D8+1
        defadr BookObj_SetDisplayOrientation,0x1439FE80+1
        defadr Display_GetTopBook,0x14EBCBD0+1
        defadr Display_GetBrightness,0x14FC95E0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x14CFB02C+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x1426A870+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1426AA0C+1
        defadr SetTheme,0x14D10D28+1
        defadr SoftKeys_GetLabel,0x1416C790+1
        defadr SoftKeys_Update,0x1416C4E8+1
        defadr IncommingCall_Reject,0x154224D4+1
        defadr IncommingCall_Mute,0x14CA87B4+1
        defadr Bluetooth_GetState,0x1450DDE0+1
        defadr Bluetooth_GetPhoneVisibility,0x14D8B0A8+1
        defadr Bluetooth_isBusy,0x1450DFF8+1
        defadr USB_isConnected,0x151A5D6C+1
        defadr w_diropen,0x141152AC+1
        defadr w_dirread,0x1409D354+1
        defadr w_dirclose,0x104FA45C+1
        defadr w_rename,0x141B2DDC+1
        defadr w_remove,0x141B312C+1
        defadr IsCameraBook,0x14162918+1
        defadr IsSoundRecorderBook,0x154466A8+1
        defadr StringInput_MenuItem_SetPriority,0x14F1B14C+1
        defadr Video_ActionBack,0x154266DC+1
        defadr Video_ExtractFrame,0x15426C68+1
        defadr Video_ZoomOn,0x154266A0+1
        defadr RightNow_SetActive,0x14490D04+1
        defadr Video_Play,0x14CF8FF0+1
        defadr Video_Pause,0x14E29118+1
        defadr Audio_Pause,0x14CCE0B0+1
        defadr Audio_Play,0x1502354C+1
        defadr CreatePercentInputVA,0x15705118+1
        defadr PercentInput_GetPercent,0x157052B8+1
        defadr GUIonMessage_SetLineSeparator,0x1584D8A0+1
        defadr PHF_GetState,0x151C63A4+1
        defadr CHF_GetState,0x151C6430+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A0014+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1439FE74+1
        defadr SetTrayIcon,0x14169980+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x15861A10+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x15861B0C+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x15861AD0+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x15861BE0+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x15861A70+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x14EF2114+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x1524BBF8+1
        defadr SoundRecorderDesc_Create,0x15445BF4+1
        defadr SoundRecorderDesc_Destroy,0x15445C50+1
        defadr SoundRecorderDesc_SetBookID,0x15445C6C+1
        defadr SoundRecorderDesc_SetType,0x15445C98+1
        defadr SoundRecorderDesc_SetFolder,0x15445CAC+1
        defadr SoundRecorderDesc_SetFname,0x15445CC8+1
        defadr SoundRecorderDesc_SetRecordSize,0x15445CE4+1
        defadr SoundRecorder_Create,0x15445D5C+1
        defadr SoundRecorder_RecordCall,0x1541D640+1
        defadr Browser_OpenURI,0x14295990+1
        defadr GetURIScheme,0x140B36FC+1
        defadr CreateURI,0x140B33C8+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x14CFB590+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x14F9A7A4+1
        defadr Alarm_GetState,0x1434EB08+1
        defadr Alarm_GetTIME,0x150A3960+1
        defadr Alarm_GetWeekSettings,0x1434E9A8+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x141D388C+1
        defadr IncommingCall_Accept,0x14D9E558+1
        defadr MediaPlayer_SoftKeys_SetText,0x140B3CF0+1
        defadr MediaPlayer_SoftKeys_SetAction,0x140B3D20+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x140B3F20+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x140B3F50+1
        defadr DispObject_Show,0x1416AA08+1
        defadr Request_EventChannel_Subscribe,0x107ADDE4+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x14D0B9F0+1
        defadr Request_ICA_ShutdownAllConnections,0x104F7ECC+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x15012044+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1573D3F0+1
        defadr GUIonMessage_GetMsg,0x142EFC74+1
        defadr GUIonMessage_GetBook,0x142EFB8C+1
        defadr GUIonMessage_GetGui,0x142EF7C8+1
        defadr GUIonMessage_GetSelectedItem,0x140674EC+1
        defadr GUIonMessage_GetPrevSelectedItem,0x1584D888+1
        defadr ObexSendFile,0x14FF76BC+1
        defadr Feedback_SetManualScrollingText,0x14CDB9B0+1
        defadr EqualizerGain_Set,0x1431A5FC+1
        defadr CANVAS_Get_GviGC,0x100A2624+1
        defadr GVI_BitBlt,0x100A2308+1
        defadr GVI_StretchBlt,0x104BCAC8+1
        defadr GVI_TransformBlt,0x1011B3E0+1
        defadr GVI_CreatePen,0x1015D538+1
        defadr GVI_CreateDashedPen,0x10280878+1
        defadr GVI_CreateSolidBrush,0x100ADC8C+1
        defadr GVI_Delete_GVI_Object,0x10048B8C+1
        defadr GVI_DrawEllipse,0x104BC5AC+1
        defadr GVI_DrawLine,0x10096468+1
        defadr GVI_DrawLines,0x104BD49C+1
        defadr GVI_DrawPolyLine,0x104BD520+1
        defadr GVI_DrawRectangle,0x10174EBC+1
        defadr GVI_DrawRoundRect,0x100979A4+1
        defadr GVI_DrawSolidLines,0x104BD0CC+1
        defadr GVI_DrawSolidPolyLine,0x104BD2D0+1
        defadr GVI_DrawSolidRectangle,0x10174C38+1
        defadr GVI_FillEllipse,0x104BC990+1
        defadr GVI_FillPolygon,0x100983CC+1
        defadr GVI_FillRectangle,0x10096184+1
        defadr GVI_FillRectangles,0x104BD61C+1
        defadr GVI_FillSolidEllipse,0x104BCA40+1
        defadr GVI_FillSolidRectangle,0x10028B40+1
        defadr GVI_FillSolidRoundRect,0x102463F8+1
        defadr GVI_FillSolidTriangle,0x1000D070+1
        defadr GC_CreateMemoryGC,0x144DFC98+1
        defadr GC_FreeGC,0x141184D4+1
        defadr Settings_ShowNumber_Get,0x153F9E74+1
        defadr GVI_CreateBitmap,0x104BC2A0+1
        defadr GVI_CreateMemoryGC,0x10049610+1
        defadr GVI_DeleteMemoryGC,0x10108038+1
        defadr StringInput_DispObject_SetLanguage,0x1410E204+1
        defadr List_InsertSorted,0x144A9490+1
        defadr ListMenu_SetItemIcon,0x142F0C50+1
        defadr wstrnupr,0x141B00C4+1
        defadr wstrnlwr,0x1400CB34+1
        defadr ListMenu_SetItemTextScroll,0x1410FF04+1
        defadr GUIObject_SetListTextColor,0x1584DE3C+1
        defadr DispObject_SetTitleTextColor,0x14D82DD4+1
        defadr DispObject_SetListTextColor,0x14D81B7C+1
        defadr DispObject_SetCursorImage,0x14D82568+1
        defadr DispObject_SetBackgroundImage,0x14FE6EC0+1
        defadr DispObject_SetTitleBackgroundImage,0x14D82E00+1
        defadr TabMenuBar_SetTabTitle,0x1402C04C+1
        defadr GUIObject_GetBook,0x141047F0+1
        defadr SoftKeys_GetSelectedAction,0x14478994+1
        defadr MonitorFeedback_SetTimer,0x15841194+1
        defadr getListMenuOnGuiDestroy,0x14D79428+1
        defadr getListMenuOnDescCreate,0x14507818+1
        defadr getListMenuOnDispMessage,0x142EFF40+1
        defadr getTabMenuBarOnGuiDestroy,0x150FA890+1
        defadr getTabMenuBarOnDescCreate,0x14507C78+1
        defadr getTabMenuBarOnDispMessage,0x14510D08+1
        defadr getOneOfManyOnGuiDestroy,0x1400D304+1
        defadr getOneOfManyOnDescCreate,0x143BD3E4+1
        defadr getOneOfManyOnDispMessage,0x14166E20+1
        defadr getNOfManyOnGuiDestroy,0x1400D304+1
        defadr getNOfManyOnDescCreate,0x14F7E6B0+1
        defadr getNOfManyOnDispMessage,0x14017934+1
        defadr ListMenu_DestroyItems,0x143C2398+1
        defadr DispObject_SetScrollBarBackgroundColor,0x144212C0+1
        defadr DispObject_SetScrollBarColor,0x14420AF4+1
        defadr DispObject_SetSoftkeysColor,0x1411B010+1
        defadr YesNoQuestion_SetIcon,0x15009C94+1
        defadr GUIObject_SetBacklightTimeout,0x1423608C+1
        defadr ListMenu_SetHotkeyMode,0x1411B090+1
        defadr ListMenu_SetSearchLanguageMode,0x145095D8+1
        defadr ListMenu_EnableSearchHeader,0x143C715C+1
        defadr GUIonMessage_GetSearchString,0x1584D92C+1
        defadr GUIonMessage_GetSearchStringLength,0x1584D94C+1
        defadr EqualizerGain_Get,0x15802560+1
        defadr Theme_DestroyMenuIcons,0x14DCBB5C+1
        defadr CoCreateInstance,0x14460170+1
        defadr GUIObject_SetSecondRowTitleText,0x144D4C00+1
        defadr ListMenu_GetItemCount,0x1413D7CC+1
        defadr OSE_GetShell,0x141692C4+1
        defadr swscanf,0x14397820+1
        defadr sscanf,0x101D2B0C+1
        defadr BookObj_WindowSetWantsFocus,0x14E5E30C+1
        defadr BookObj_StayOnTop,0x144F5144+1
        defadr DispObject_WindowSetPosition,0x14117108+1
        defadr DispObject_WindowSetSize,0x1411745C+1
        defadr Feedback_DispObject_GetText,0x157022D8+1
        defadr DispObject_SoftKeys_ExecuteAction,0x1439C0CC+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x142D9938+1
        defadr DispObject_SetAnimation,0x14E2EEE0+1
        defadr GUIObject_SetZOrder,0x143A0108+1
        defadr DisplayGC_AddRef,0x143CEE40+1
        defadr TextObject_SetText,0x1416F57C+1
        defadr TextObject_SetFont,0x14172478+1
	defadr RichTextLayout_GetTextWidth,0x14421A98+1
        defadr MetaData_GetTags,0x14DD9954+1
        defadr CreateYesNoQuestion,0x14234CB8+1
        defadr YesNoQuestion_SetDescriptionText,0x14082B70+1
        defadr YesNoQuestion_SetQuestionText,0x14082B60+1
        defadr CreateMessageBox,0x14E082FC+1
        defadr GetIMEI,0x1442CB74+1
	defadr FILEITEM_GetFextension,0x142DA668+1
	defadr FSX_IsFileExists,0x14EFF400+1
	defadr FSX_MakeFullPath,0x144C033C+1
	defadr FSX_FreeFullPath,0x14043000+1
	defadr Volume_Get,0x14273244+1
	defadr Volume_Set,0x14273440+1
	defadr DispObject_SetBacklightMode,0x14236290+1
	defadr DispObject_SetThemeImage,0x144ADF60+1
	defadr GUIObject_SoftKeys_SetActionAndText,0x143F32EC+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x140B3F50+1
	defadr TextID_Create,0x142D6F24+1
	defadr TextID_CreateIntegerID,0x143D4FA4+1
	defadr TextID_Copy,0x1416E374+1
	defadr TextID_Destroy,0x1416EC2C+1
	defadr TextID_GetLength,0x1416F444+1
	defadr TextID_GetWString,0x1416E898+1
        defadr FreeAllBook,0x154341C0+1
        defadr CreateStringInput,0x14FB5E00+1
        defadr StringInput_SetMode,0x14001148+1
        defadr StringInput_SetActionOK,0x14288BAC+1
        defadr StringInput_SetActionBack,0x14FB5EC0+1
        defadr StringInput_SetActionLongBack,0x14FB5EE4+1
        defadr StringInput_SetText,0x14E60160+1
        defadr StringInput_SetFixedText,0x14015804+1
        defadr StringInput_SetMinLen,0x14FB6248+1
        defadr StringInput_SetMaxLen,0x14317D30+1
        defadr StringInput_SetEnableEmptyText,0x14E60180+1

        defadr Feedback_CloseAction,0x1414C488+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x15861AD0+1
        defadr Sound_SetMessageAlert,0x14D78E00+1
        defadr Sound_SetAlarmsignal,0x1516E5B0+1
        defadr Sound_AddToContact,0x1526B0C0+1
        defadr ListMenu_SetTexts,0x141ACFB4+1

        defadr MusicApplication_PrevAction,0x14CA5168+1
        defadr MusicApplication_CancelAction,0x14F3863C+1
        defadr MusicApplication_ShowMyMusic,0x14E5DC20+1
        defadr MusicApplication_Minimize,0x14EF8980+1
        defadr MusicApplication_Keyboard,0x140B3F98+1

        defadr pg_MusicApplication_PreviousEvent,0x15333D78+1
        defadr pg_MusicApplication_CancelEvent,0x14FF3FCC+1
        defadr pg_MusicApplication_ExitEvent,0x14E96754+1

        defadr Music_Gui_NowPlaying_OnRedraw,0x14494E84+1
        defadr Music_Gui_NowPlaying_OnCreate,0x14E05870+1
        defadr Music_Gui_NowPlaying_OnClose,0x14FEED70+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x140B4238+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x140B475C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x14D872DC+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x15022D88+1

        defadr FeedbackTicker_OnRedraw,0x141FFF70+1

        EXTERN New_Music_Gui_NowPlaying_OnRedraw
        EXTERN New_Music_Gui_NowPlaying_OnCreate
        EXTERN New_Music_Gui_NowPlaying_OnClose
        EXTERN New_Music_Gui_NowPlaying_OnKey
        EXTERN Set_New_Keyboard

	EXTERN PATCH_UI_MEDIAPLAYER_AUDIO_ON_NEW_TRACK_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_CREATED_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_ON_ENTER_EVENT

	EXTERN New_Action
        EXTERN New_SoftKeys
	EXTERN Set_WALKMAN_GUI_STYLE
	EXTERN RefreshScreen

	EXTERN LoadLandscapeData
	EXTERN LoadPortraitData

        EXTERN Feedback_DrawCoverArt

//------------------------------------------------------------------------------

        RSEG PATCH_ONCREATE_HOOK
	DATA
	DCD New_Music_Gui_NowPlaying_OnCreate

        RSEG PATCH_ONCLOSE_HOOK
	DATA
	DCD New_Music_Gui_NowPlaying_OnClose

        RSEG PATCH_ONREDRAW_HOOK
	DATA
	DCD New_Music_Gui_NowPlaying_OnRedraw

        RSEG PATCH_MUSIC_KEYBOARD1
        DATA
        DCD New_Music_Gui_NowPlaying_OnKey

        RSEG PATCH_MUSIC_KEYBOARD2
        DATA
        DCD New_Music_Gui_NowPlaying_OnKey

//------------------------------------------------------------------------------

	RSEG PATCH_UI_MEDIAPLAYER_ON_NEW_TRACK_HOOK
	DATA
	DCD PATCH_UI_MEDIAPLAYER_AUDIO_ON_NEW_TRACK_EVENT

	RSEG PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT_HOOK
	DATA
	DCD PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT

        RSEG PATCH_UI_MEDIAPLAYER_CREATED_EVENT_HOOK
	DATA
	DCD PATCH_UI_MEDIAPLAYER_CREATED_EVENT

	RSEG PATCH_UI_MEDIAPLAYER_ON_ENTER_PAGE_HOOK
	DATA
	DCD PATCH_UI_MEDIAPLAYER_ON_ENTER_EVENT

//------------------------------------------------------------------------------

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_2
        CODE16
	CMP     R1, R5
	BEQ     EndFunc

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_3
        CODE16
	CMP     R0, #0
	BEQ     Continue

        RSEG PATCH_UPDATE_ORIENTATION_HOOK
        CODE16
	ADD     r0, r4, #0
	LDR     r3, =IsAudioPlayerBook
	BLX     r3
	CMP     r0, #0
	BEQ     Continue
	CMP     r5,#0
	BEQ     loadVerticalData
	CMP     r5,#1
	BEQ     loadHorizontalData
	CMP     r5,#2
	BEQ     loadHorizontalData
	B       Continue
loadHorizontalData:
	LDR     R3, =LoadLandscapeData
	BLX     R3
	B       Continue
loadVerticalData:
	LDR     R3, =LoadPortraitData
	BLX     R3
Continue:
	LDR     R3, = 0x140459F0+1
	BLX     R3
EndFunc:
	POP     {R4,R5,PC}

//------------------------------------------------------------------------------

        RSEG    PATCH_Feedback_DrawCoverArt
        DATA
        DCD     Feedback_DrawCoverArt

        RSEG PATCH_Feedback_RemoveIcon
        CODE16
        NOP
        ADD     SP, #0x18
	POP     {R4-R7,PC}

//------------------------------------------------------------------------------

 	RSEG PATCH_Walkman_SoftKeys
	CODE16
	ldr     r3, =AddNew_SoftKeys
	bx      r3

        RSEG  CODE
        CODE16
AddNew_SoftKeys:
        LDR     R0, [R4,#0x20]
        ADD     R2, R7, #0
        MOV     R1, #7
	LDR	R3, =MediaPlayer_SoftKeys_SetInfoText
	BLX	R3
	ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR	R3, =0x14D11286+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_Walkman_GUI
	CODE16
	LDR     R3, =_walkman
	BX      R3

        RSEG  CODE
        CODE16
_walkman:
	ADD     R0, R7, #0
	BL      Set_WALKMAN_GUI_STYLE
        ADD     R0, R7, #0
        LDR	R3, =GUIObject_SoftKeys_RemoveBackground
	BLX	R3
	ADD     R0, R7, #0
	POP     {R1-R7,PC}

//------------------------------------------------------------------------------

	RSEG PATCH_StereoWidening
	CODE16
	NOP

        RSEG PATCH_UPDATE_SHUFFLE_HOOK
	CODE16
	LDR     R3, =_shuffle_fix
	BX      R3

        RSEG  CODE
        CODE16
_shuffle_fix:
        LDR     R3, =ListMenu_SetItemSecondLineText
	BLX     R3
        BL      RefreshScreen
	LDRB    R1, [R6,#1]
	LDR     R0, [R5,#0]
	LDR     R3, =0x14E495F8+1
	BX      R3

        RSEG PATCH_UPDATE_LOOP_HOOK
	CODE16
	LDR     R3, =_loop_fix
	BX      R3

        RSEG  CODE
        CODE16
_loop_fix:
        LDR     R3, =ListMenu_SetItemSecondLineText
	BLX     R3
        BL      RefreshScreen
	LDRB    R1, [R6,#0]
	LDR     R0, [R5,#0]
	LDR     R3, =0x14E4962C+1
	BX      R3

//------------------------------------------------------------------------------

        EXTERN New_MusicApplication_Equalizer_EnterEvent
        EXTERN New_MusicApplication_Equalizer_CancelEvent

        EXTERN New_SetEqualizerGain

        RSEG PATCH_Equalizer_EnterEvent
        DATA
        DCD New_MusicApplication_Equalizer_EnterEvent

        RSEG PATCH_Equalizer_CancelEvent
        DATA
        DCD New_MusicApplication_Equalizer_CancelEvent

        RSEG PATCH_SetEqualizerGain
        CODE16
        PUSH    {LR}
        LDR     R3,=New_SetEqualizerGain
        BLX     R3
        MOV     R0, #1
        POP     {PC}

        END
