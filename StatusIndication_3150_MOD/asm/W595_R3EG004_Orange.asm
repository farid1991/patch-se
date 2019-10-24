#ifdef W595_R3EG004_Orange

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr GetChipID_int,0x12615345
	defadr memalloc,0x4BB00584
	defadr memfree,0x4BB005AC       
        defadr memset,0x4BB010C4
        defadr memcpy,0x10147898
        defadr sprintf,0x1075FBE0+1
        defadr snwprintf,0x10760094+1
        defadr _fopen,0x109C49A8+1
        defadr fclose,0x11783BE0+1
        defadr fread,0x109C633C+1
        defadr fwrite,0x109C6508+1
        defadr fstat,0x109C530C+1
        defadr AllocDirHandle,0x109C27F8+1
        defadr GetFname,0x109C29C8+1
        defadr DataBrowserDesc_Create,0x1187622C+1
        defadr DataBrowserDesc_SetStyle,0x118764AC+1
        defadr DataBrowserDesc_SetHeaderText,0x118764DC+1
        defadr DataBrowserDesc_SetFolders,0x118764C4+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x118764E4+1
        defadr DataBrowser_Create,0x118723FC+1
        defadr DataBrowserDesc_Destroy,0x118762DC+1
        defadr getFileExtention,0x109C8018+1
        defadr DataBrowser_isFileInListExt,0x109C2C2C+1
        defadr Timer_ReSet,0x10E59ABC+1
        defadr Timer_Set,0x10E59A88+1
        defadr Timer_Kill,0x10E59B14+1
        defadr CreateBook,0x10E5D4A8+1
        defadr BookObj_KillBook,0x10E5D5BC+1
        defadr BookObj_GotoPage,0x10E5D1B8+1
        defadr BookObj_ReturnPage,0x10E5D370+1
        defadr FreeBook,0x10E5DB28+1
        defadr FindBook,0x10E5CF70+1
        defadr Find_StandbyBook,0x10DFA50C+1
        defadr BookObj_SetFocus,0x10E5D758+1
        defadr GUIObject_SetTitleText,0x10A3F1C4+1
        defadr GUIObject_Show,0x10A3EFB0+1
        defadr ListMenu_SetCursorToItem,0x11B0136C+1
        defadr GUIObject_SetStyle,0x10A3F008+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11B01F58+1
        defadr GUIonMessage_SetMenuItemText,0x11B01F64+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11B01F94+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11B01F74+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11B01F84+1
        defadr GUIonMessage_SetMenuItemIcon,0x11B01FA4+1
        defadr DispObject_SetTitleText,0x10A34304+1
        defadr ListMenu_GetSelectedItem,0x11B01380+1
        defadr ListMenu_SetItemStyle,0x11B013D0+1
        defadr isScreenSaverBook,0x10954F10+1
        defadr StatusIndication_SetItemText,0x10DF9AB0+1
        defadr StatusIndication_ShowNotes,0x10DFB6B8+1
        defadr CreateStringInputVA,0x108FAAA4+1
        defadr CreateOneOfMany,0x11B0375C+1
        defadr OneOfMany_SetItemCount,0x11B038E8+1
        defadr OneOfMany_SetChecked,0x11B03904+1
        defadr OneOfMany_SetTexts,0x11B03938+1
        defadr OneOfMany_GetSelected,0x11B03914+1
        defadr StatusIndication_Item8_SetText,0x10DFB5C4+1
        defadr GUIObject_SoftKeys_SetAction,0x10874D8C+1
        defadr GUIObject_SoftKeys_SetText,0x10874E04+1
        defadr GUIObject_SoftKeys_SetEnable,0x10874EF4+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x10874EAC+1
        defadr GUIObject_SoftKeys_RemoveItem,0x10874D40+1
        defadr GUIObject_SoftKeys_SetVisible,0x10874E88+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x108750F8+1
        defadr wstrcpy,0x10DD2F64+1
        defadr wstrncpy,0x10DD2F7C+1
        defadr wstrcat,0x10760754+1
        defadr wstrncat,0x10DD2FC4+1
        defadr wstrcmp,0x10DD2F34+1
        defadr wstrlen,0x10DD2F20+1
        defadr str2wstr,0x10DD41E8+1
        defadr strcmp,0x1075FE68+1
        defadr strlen,0x1075FEC4+1
        defadr wstr2strn,0x10DD3040+1
        defadr StrID2Str,0x10FCF708+1
        defadr AB_DEFAULTNBR_GET,0x10BD19A0+1
        defadr AB_READPHONENBR,0x10BD7D78+1
        defadr AB_GETNBROFITEMS,0x10BD7E30+1
        defadr PNUM_len,0x10FCE5FC+1
        defadr PNUM2str,0x109A5980+1
        defadr GUIObject_GetDispObject,0x10A3EE48+1
        defadr List_Create,0x11B47988+1
        defadr List_Destroy,0x11B479B0+1
        defadr List_InsertFirst,0x11B47AFC+1
        defadr Gif2ID,0x10809D2C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10809F5C+1
        defadr REQUEST_DATEANDTIME_GET,0x10813F40+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x10ED1F9C+1
        defadr GetFreeBytesOnHeap,0x4BB00700
        defadr BookObj_Hide,0x10E5D780+1
        defadr BookObj_Show,0x10E5D790+1
        defadr StartAPP,0x10DFA6F8+1
        defadr ListMenu_SetOnMessage,0x11B014A4+1
        defadr manifest_GetParam,0x10B72860+1
        defadr lseek,0x109C66B0+1
        defadr get_VBUFFER,0x00000000+1
        defadr SetLampLevel,0x1000592A+1
        defadr List_RemoveAt,0x11B47B78+1
        defadr GetCurrentPID,0x10005E58+1
        defadr List_IndexOf,0x11B47ABC+1
        defadr alloc,0x1017CAE8
        defadr receive,0x1017CB04
        defadr send,0x1017CAF4
        defadr sender,0x1017CB44
        defadr free_buf,0x1017CB14
        defadr create_process,0x1017CBE0
        defadr start,0x1017CE00
        defadr get_ptype,0x1017CCB0
        defadr current_process,0x1017CBFC
        defadr delay,0x1017CB34
        defadr hunt,0x1017CCFC
        defadr kill_proc,0x1017CD28
        defadr receive_w_tmo,0x1017CB60
        defadr stop,0x1017CE10
        defadr get_mem,0x1017CC7C
        defadr get_envp,0x10005C38+1
        defadr set_envp,0x10005C4C+1
        defadr get_bid,0x1017CC34
        defadr datetime2unixtime,0x10C3A2D4+1
        defadr strcpy,0x1075FE90+1
        defadr CreateMessage,0x10E7C358+1
        defadr SendMessage,0x10E7C3AC+1
        defadr WaitMessage,0x10E7C434+1
        defadr FreeMessage,0x10E7C448+1
        defadr SendDispatchMessage,0x10C45D4C+1
        defadr UIEventName,0x10E59EA4+1
        defadr MissedEvents,0x4BB9E034
        defadr UI_Event,0x10E5C248+1
        defadr UI_Event_wData,0x10E5C258+1
        defadr UI_Event_toBookID,0x10E5C2A0+1
        defadr UI_Event_toBookIDwData,0x10E5C2B4+1
        defadr List_Find,0x11B47C58+1
        defadr List_Get,0x11B47BA8+1
        defadr wstrrchr,0x10DD42A4+1
        defadr BookObj_CallSubroutine,0x10E5D248+1
        defadr List_InsertLast,0x11B47B04+1
        defadr debug_printf,0x4BB39FA4+1
        defadr PlayFile,0x11A636E4+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11B1E75C+1
        defadr Profile_SetActive,0x11B4EACC+1
        defadr SetBrightnessOfScreen,0x10E2E47C
        defadr isKeylocked,0x10954CFC+1
        defadr isMediaPlayerVideoBook,0x10E80668+1
        defadr ShuttingDown,0x11ADB670+1
        defadr Vibra,0x11A62A4C+1
        defadr REQUEST_DATEFORMAT_GET,0x10814120+1
        defadr REQUEST_TIMEFORMAT_GET,0x10814204+1
        defadr Date2ID,0x11ADBCE0+1
        defadr Time2ID,0x11ADBBFC+1
        defadr CreateListMenu,0x11B01180+1
        defadr ListMenu_SetItemCount,0x11B01394+1
        defadr ROOT_APP,0x4BBAA448
        defadr GUIObject_SoftKeys_SetInfoText,0x10874DF0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x10874F28+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11567E0C+1
        defadr REQUEST_SYSTEM_RESTART,0x11567E2C+1
        defadr GUIObject_SoftKeys_SetTexts,0x10874E5C+1
        defadr isRightNowBook,0x10B9F768+1
        defadr IsVolumeControllerBook,0x11B3AEC4+1
        defadr CreateTabMenuBar,0x117FEAD4+1
        defadr TabMenuBar_SetTabCount,0x117FED2C+1
        defadr TabMenuBar_SetTabGui,0x117FEBA4+1
        defadr TabMenuBar_SetTabIcon,0x117FEC24+1
        defadr GUIObject_Destroy,0x10A3EDBC+1
        defadr GUIInput_SetIcon,0x10A3F084+1
        defadr StringInput_GetStringAndLen,0x108FB354+1
        defadr GetAudioControlPtr,0x4BBC74C0
        defadr AudioControl_Vibrate,0x115C10CC+1
        defadr GetVolumeSize,0x109C7D30+1
        defadr CreateNOfMany,0x11B03168+1
        defadr NOfMany_SetTexts,0x11B0336C+1
        defadr NOfMany_SetChecked,0x11B032F0+1
        defadr NOfMany_SetCursor,0x11B032B8+1
        defadr NOfMany_GetCheckedCount,0x11B03314+1
        defadr NOfMany_GetChecked,0x11B03304+1
        defadr NOfMany_SetonMessage,0x11B03364+1
        defadr AudioControl_Init,0x11A63830+1
        defadr OneOfMany_SetFocused,0x11B038CC+1
        defadr OneOfMany_SetOnMessage,0x11B03930+1
        defadr CreateMonitorFeedback,0x11ADA8C4+1
        defadr FeedBack_SetText,0x11ADA97C+1
        defadr GetBatteryState,0x110EF178+1
        defadr get_DisplayGC,0x10A3CE0C+1
        defadr DispObject_GetRect,0x10A35A04+1
        defadr GC_GetRect,0x10A3D450+1
        defadr GC_GetXX,0x10A3D74C+1
        defadr GC_SetXX,0x10A3D740+1
        defadr GC_ValidateRect,0x10A3D400+1
        defadr BookObj_AddGUIObject,0x10E5D838+1
        defadr DrawRect,0x10A38B58+1
        defadr DrawString,0x10A38EA4+1
        defadr XGUIList_AddGUIObject,0x10E5DD38+1
        defadr DispObject_InvalidateRect,0x10A35794+1
        defadr GUIObject_Create,0x10A3EBF8+1
        defadr SetFont,0x10A39A64+1
        defadr StatusRow_p,0x4BBC5620
        defadr root_list_get_session_count,0x10E5B7E0+1
        defadr root_list_get_session,0x10E5B7F0+1
        defadr SESSION_GetTopBook,0x10E5AFC0+1
        defadr MainInput_strlen,0x10DFA00C+1
        defadr MainInput_getPNUM,0x10DFA03C+1
        defadr BookObj_GetBookID,0x10E5DC14+1
        defadr wstrncmp,0x10760828+1
        defadr DispObject_GetAbsoluteXPos,0x10A36C08+1
        defadr DispObject_GetAbsoluteYPos,0x10A36C3C+1
        defadr DispObject_GetWindow,0x10A35D18+1
        defadr GetThemeColor,0x10ECC544+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11B1E190+1
        defadr REQUEST_SETTING_SILENCE_GET,0x11B1E138+1
        defadr VCALL_Init,0x10BC5BE8+1
        defadr VCALL_SetName,0x10BC5CE0+1
        defadr VCALL_SetNameIcon,0x10BC5D40+1
        defadr VCALL_SetNumber,0x10BC5D00+1
        defadr VCALL_SetHZ1,0x10BC5D24+1
        defadr VCALL_SetHZ2,0x10BC5D30+1
        defadr MakeVoiceCall,0x10BC5780+1
        defadr FileDelete,0x109C559C+1
        defadr GUIObject_SetFocus,0x10A3EF74+1
        defadr CreateSMSCont,0x11A919B0+1
        defadr FreeSMSCont,0x11A920F4+1
        defadr PrepareSMSCont,0x11A91B90+1
        defadr CteateNewMessage,0x11A9201C+1
        defadr get_APP_DESC_TABLE,0x11C03434
        defadr Window_GetComponentInterface,0x10A3C7B8+1
        defadr AB_POSITIONNBR_GET,0x10BD801C+1
        defadr AB_NAME_ITEM2StrID,0x10BD7F30+1
        defadr AB_NUM_ITEM2StrID,0x10BD7F94+1
        defadr GetABRecNum,0x10BE8DE8+1
        defadr get_AB_ITEMS_DESC,0x11BEB6D4
        defadr SBY_GetMainInput,0x1090BF24+1
        defadr SBY_GetStatusIndication,0x107D1128+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10ABD4E0+1
        defadr PID_MMI,0x4BBA8A90
        defadr DispObject_GetGUI,0x10A35078+1
        defadr Display_GetFocusedDispObject,0x10A34FC4+1
        defadr DispObject_GetVisible,0x10A35638+1
        defadr DispObject_GetDESC,0x10014E98+1
        defadr DISP_DESC_SetName,0x10A32244+1
        defadr DispObject_GetName,0x10A36960+1
        defadr DISP_DESC_SetSize,0x10A32248+1
        defadr DISP_DESC_SetOnCreate,0x10A3224C+1
        defadr DispObject_GetOnCreate,0x10A322C8+1
        defadr DISP_DESC_SetOnClose,0x10A32250+1
        defadr DispObject_GetOnClose,0x10A322E4+1
        defadr DISP_DESC_SetOnRedraw,0x10A32254+1
        defadr DispObject_GetOnRedraw,0x10A32300+1
        defadr DISP_DESC_SetOnKey,0x10A3225C+1
        defadr DispObject_GetOnKey,0x10A32338+1
        defadr DISP_DESC_SetOnRefresh,0x10A32258+1
        defadr DispObject_GetonRefresh,0x10A3231C+1
        defadr DISP_DESC_SetMethod06,0x10A32260+1
        defadr DispObject_GetMethod06,0x10A32354+1
        defadr DISP_DESC_SetOnLayout,0x10A32268+1
        defadr DispObject_GetOnLayout,0x10A3238C+1
        defadr DISP_DESC_SetOnConfig,0x10A3226C+1
        defadr DispObject_GetOnConfig,0x10A323A8+1
        defadr DISP_DESC_SetMethod0A,0x10A32270+1
        defadr DispObject_GetMethod0A,0x10A323C4+1
        defadr DISP_DESC_SetMethod0B,0x10A32274+1
        defadr DispObject_GetMethod0B,0x10A323E0+1
        defadr DISP_DESC_SetMethod0C,0x10A32278+1
        defadr JavaSession_Manager,0x10BD8018+1
        defadr JavaSession_GetName,0x1094B18C+1
        defadr BookObj_GetSession,0x10E5DB74+1
        defadr GUIonMessage_SetItemAsSubitem,0x11B02000+1
        defadr GUIonMessage_SetSubitemText,0x11B0206C+1
        defadr GUIonMessage_GetCreatedSubItemParentIndex,0x11B02060+1
        defadr GoMusic,0x10E93BB4+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x11B0203C+1
        defadr GUIonMessage_SubItem_SetDisabled,0x11B020D4+1
        defadr PlayFileV,0x11A636E8+1
        defadr GetSilent,0x11A61BB8+1
        defadr GetVibrator,0x11A5D7A8+1
        defadr GetAudioSettings,0x11A62EBC+1
        defadr GUIonMessage_GetCurrentSubItem,0x11B02054+1
        defadr GUIonMessage_GetCurrentItemIndex,0x11B02048+1
        defadr DestroyDirHandle,0x109C2B44+1
        defadr LastExtDB,0x11ED8808
        defadr GetOtherExtMethods,0x1186C3D4+1
        defadr MessageBox,0x11AD8E80+1
        defadr Display_GetHeight,0x11801130+1
        defadr Display_GetWidth,0x1180113C+1
        defadr PlaySystemSound,0x11A6368C+1
        defadr TabMenuBar_GetFocusedTab,0x117FEB98+1
        defadr TabMenuBar_SetFocusedTab,0x117FEB88+1
        defadr GC_GetPenColor,0x10A3D658+1
        defadr GC_SetPenColor,0x10A3D61C+1
        defadr GC_SetPixel,0x10A3D2A0+1
        defadr GC_DrawLine,0x10A3DD9C+1
        defadr GC_DrawFRect,0x10A3DF28+1
        defadr GC_WritePixels,0x10A3D328+1
        defadr png_create_read_struct_2,0x118AAC54+1
        defadr png_destroy_read_struct,0x118AADA0+1
        defadr png_create_info_struct,0x118A93FC+1
        defadr png_destroy_info_struct,0x118A9430+1
        defadr png_set_progressive_read_fn,0x118AAC2C+1
        defadr png_process_data,0x118A9BEC+1
        defadr png_read_update_info,0x118AAD74+1
        defadr png_get_progressive_ptr,0x118AAC50+1
        defadr png_get_IHDR,0x118A98B8+1
        defadr png_set_strip_16,0x118AAF40+1
        defadr png_set_gray_1_2_4_to_8,0x118AAF4C+1
        defadr png_set_gray_to_rgb,0x118AAF70+1
        defadr png_get_valid,0x118A988C+1
        defadr png_set_tRNS_to_alpha,0x118AAF64+1
        defadr png_set_filler,0x118ADCD4+1
        defadr png_set_palette_to_rgb,0x118AAF58+1
        defadr png_get_rowbytes,0x118A98A4+1
        defadr png_progressive_combine_row,0x118AAC0C+1
        defadr png_sig_cmp,0x118A92F4+1
        defadr setjmp,0x1014BB34
        defadr longjmp,0x1014BB58
        defadr inflateInit2_,0x118AE9A8+1
        defadr inflate,0x118AEB50+1
        defadr inflateEnd,0x118AFE48+1
        defadr memcmp,0x126140C8
        defadr strncmp,0x1075FF00+1
        defadr strncpy,0x1075FF34+1
        defadr strcat,0x1075FE30+1
        defadr GUIObject_SetTitleType,0x10A3F1A8+1
        defadr GUIonMessage_SetItemDisabled,0x11B0200C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10809FD4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1080A05C+1
        defadr get_Surfaces,0x4BD83DBC
        defadr iconidname2id,0x1158C514+1
        defadr StrIDname2id,0x11783A48+1
        defadr ListMenu_SetNoItemText,0x11B01524+1
        defadr IsFmRadioBook,0x11014B58+1
        defadr IsAudioPlayerBook,0x10CF3870+1
        defadr PlayerControl,0x10CF328C+1
        defadr SwitchRadioStationFromList,0x11012A2C+1
        defadr Shortcut_Run,0x10E49A08+1
        defadr mkdir,0x109C1F24+1
        defadr rmdir,0x109C2318+1
        defadr chmod,0x109C54C8+1
        defadr rename,0x109C5AF0+1
        defadr CallID_GetCallStatusDesc,0x10E6E234+1
        defadr CallStatusDesc_GetName,0x10E6D86C+1
        defadr List_DestroyElements,0x11B47C9C+1
        defadr strstr,0x1075FFD0+1
        defadr GPRS_GetLastSessionInfo,0x10867444+1
        defadr wstrcmpni,0x10DD4340+1
        defadr wtoi,0x10E594E8+1
        defadr DATE_GetWeekDay,0x10C3A5D0+1
        defadr Cale_GetSettings,0x10991D44+1
        defadr wstrwstr,0x10760988+1
        defadr wstrcmpi,0x10DD4384+1
        defadr wstrchr,0x10760770+1
        defadr GUIObject_SoftKeys_Hide,0x10875144+1
        defadr GUIObject_SoftKeys_Show,0x10875150+1
        defadr DispObject_SoftKeys_Get,0x1087151C+1
        defadr StandbyBackground_SetImage,0x10ECADB0+1
        defadr CreateYesNoQuestionVA,0x118009E4+1
        defadr ListMenu_SetItemSecondLineText,0x11B01748+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10B9840C+1
        defadr FSX_GetInvalidChar,0x109C7B20+1
        defadr DataBrowserDesc_SetFoldersNumber,0x118764CC+1
        defadr DataBrowserDesc_SetActions,0x11876480+1
        defadr DataBrowserDesc_SetSelectAction,0x11876448+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x11876450+1
        defadr DataBrowserDesc_SetBookID,0x1187642C+1
        defadr DataBrowserDesc_SetItemFilter,0x118763D0+1
        defadr DataBrowserDesc_SetOption,0x118764FC+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x11876564+1
        defadr DataBrowserDesc_SetFileExtList,0x118763D8+1
        defadr FSX_RemoveIllegalSymbolsName,0x1187FC40+1
        defadr FILEITEM_Create,0x1187F658+1
        defadr FILEITEM_Destroy,0x1187F788+1
        defadr CreateDateInputVA,0x117FEE60+1
        defadr CreateTimeInputVA,0x118005BC+1
        defadr StringInput_SetCursorPosition,0x108FB3A0+1
        defadr BookObj_CallPage,0x10E5D2EC+1
        defadr DateInput_GetDateInt,0x117FF0D0+1
        defadr TimeInput_GetTimeInt,0x11800884+1
        defadr GetFontDesc,0x4BBA2110
        defadr GetFontCount,0x4BBA2480
        defadr GC_GetBrushColor,0x10A3D734+1
        defadr GC_SetBrushColor,0x10A3D6F4+1
        defadr GC_DrawRoundRect,0x10A3DF70+1
        defadr MenuBook_Desktop,0x10E491BC+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10E484F0+1
        defadr BookObj_Softkey_SetAction,0x1086F3DC+1
        defadr BookObj_Softkey_SetText,0x1086F414+1
        defadr FindBookByID,0x10E5CF80+1
        defadr TextFeedbackWindow,0x117FFE20+1
        defadr Feedback_SetKeyHook,0x1180022C+1
        defadr Feedback_SetOnClose,0x118001C8+1
        defadr Feedback_SetTimeout,0x118001F8+1
        defadr Feedback_SetTextExtended,0x11800290+1
        defadr TabMenuBar_SetOnTabSwitch,0x117FEC80+1
        defadr KeyCode2Name,0x11019960+1
        defadr ImageID_Get,0x10807EDC+1
        defadr ImageID_Free,0x1080E0F4+1
        defadr DataBrowser_CreateSubExecute,0x1185F2B8+1
        defadr DataBrowser_ExecuteSubroutine,0x1185FCD8+1
        defadr FILEITEM_SetFname,0x1187F834+1
        defadr FILEITEM_SetPath,0x1187FAF4+1
        defadr FILEITEM_GetFname,0x1187FAEC+1
        defadr FILEITEM_GetPath,0x1187FB80+1
        defadr FILEITEM_SetFnameAndContentType,0x1187F894+1
        defadr FILEITEM_SetPathAndContentType,0x1187FB58+1
        defadr JavaDialog_Open,0x10B808F4+1
        defadr JavaDialog_Close,0x10B84048+1
        defadr JavaAppDesc_Get,0x10B84214+1
        defadr JavaAppDesc_GetFirstApp,0x10B76280+1
        defadr JavaAppDesc_GetNextApp,0x10B76288+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B75D4C+1
        defadr DispObject_SetRefreshTimer,0x10A351FC+1
        defadr DispObject_KillRefreshTimer,0x10A35278+1
        defadr IsDataBrowserBook,0x11872CFC+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x1186E464+1
        defadr Shortcut_Get_MenuItemName,0x10BA1290+1
        defadr Shortcut_Get_MenuItemIconID,0x10E493E0+1
        defadr FindBookEx,0x10E5B740+1
        defadr FILEITEM_CreateCopy,0x1187F688+1
        defadr ActionCreate,0x10E5CED0+1
        defadr BookObj_GetSessionID,0x10E5DA9C+1
        defadr UI_Event_toSID,0x10E5C26C+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11ADB354+1
        defadr MainInput_Hide,0x10DF9F58+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x10870EFC+1
        defadr PNUM2Name,0x10BC0E00+1
        defadr SpeedDial_GetPNUM,0x10BE8340+1
        defadr DispObject_GetWindowWidth,0x10A36B88+1
        defadr DispObject_GetWindowHeight,0x10A36BA8+1
        defadr get_system_langID,0x10E25490+1
        defadr lang_get_name,0x11B0A4CC+1
        defadr w_chdir,0x4BB003AC
        defadr w_fopen,0x11308E74+1
        defadr w_fstat,0x11308F2C+1
        defadr w_fwrite,0x11308EBC+1
        defadr w_fread,0x11308EA4+1
        defadr w_lseek,0x11AD3C78+1
        defadr w_fclose,0x11308ED4+1
        defadr w_mkdir,0x4BB00344
        defadr DirHandle_SetFilterStr,0x109C2B9C+1
        defadr Disp_GetStrIDWidth,0x10A3A1F0+1
        defadr ImageID_GetIndirect,0x10807F74+1
        defadr unixtime2datetime,0x10C3A3E8+1
        defadr List_Insert,0x11B479D8+1
        defadr FileCopy,0x109C58A4+1
        defadr FileMove,0x109C5AF0+1
        defadr DispObject_SetLayerColor,0x10A3798C+1
        defadr JavaAppDesc_GetJavaAppID,0x10B84170+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10CA8178+1
        defadr JavaApp_LogoImageID_Get,0x10C9CD14+1
        defadr CreateProgressBar,0x117FF594+1
        defadr ProgressBar_SetText,0x117FF88C+1
        defadr ProgressBar_SetIcon,0x117FFA00+1
        defadr ProgressBar_SetPercentValue,0x117FF848+1
        defadr ProgressBar_SetBarDisabled,0x117FFA20+1
        defadr StringInput_DispObject_SetText,0x108EFC34+1
        defadr GUIObject_SetTitleIcon,0x10A3F1FC+1
        defadr DispObject_Softkeys_GetParams,0x108721CC+1
        defadr DispObject_Softkeys_GetList,0x10872210+1
        defadr BookObj_GetDisplayOrientation,0x10E5DCB0+1
        defadr BookObj_SetDisplayOrientation,0x10E5DC4C+1
        defadr Display_GetTopBook,0x10E5CF8C+1
        defadr Display_GetBrightness,0x10E2E3A0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x11876434+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x11876490+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x11876498+1
        defadr SetTheme,0x10E79FE0+1
        defadr Softkeys_GetLabel,0x108746F8+1
        defadr Softkeys_Update,0x108742B0+1
        defadr get_CellData,0x1095888C+1
        defadr IncommingCall_Reject,0x10E7748C+1
        defadr IncommingCall_Mute,0x10E787CC+1
        defadr Bluetooth_GetState,0x10AD13D0+1
        defadr Bluetooth_GetPhoneVisibility,0x10AD1394+1
        defadr Bluetooth_isBusy,0x10AD1460+1
        defadr USB_isConnected,0x10A28E64+1
        defadr w_diropen,0x4BB00354
        defadr w_dirread,0x11AD4308+1
        defadr w_dirclose,0x4BB0038C
        defadr w_rename,0x11AD43A4+1
        defadr w_remove,0x11AD4358+1
        defadr isCameraBook,0x10933344+1
        defadr isSoundRecorderBook,0x10EB8740+1
        defadr StringInput_MenuItem_SetPriority,0x108FB4A8+1
        defadr Video_ActionBack,0x10E80004+1
        defadr Video_ExtractFrame,0x10E8090C+1
        defadr Video_ZoomOn,0x10E7FFD4+1
        defadr RightNow_SetActive,0x10B9FD9C+1
        defadr Video_Play,0x10E7FF0C+1
        defadr Video_Pause,0x10E7FF1C+1
        defadr Audio_Pause,0x10CF54E0+1
        defadr Audio_Play,0x10CF5484+1
        defadr CreatePercentInputVA,0x117FF200+1
        defadr PercentInput_GetPercent,0x117FF38C+1
        defadr GUIonMessage_SetLineSeparator,0x11B02024+1
        defadr PHF_GetState,0x10A85AD8+1
        defadr CHF_GetState,0x10A85AE0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1087515C+1
        defadr GUIObject_Softkeys_RestoreBackground,0x10875168+1
        defadr SetTrayIcon,0x10DFB894+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11B1DE38+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x11B1E02C+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x11B1DFA8+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11B1E410+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x11B1DF40+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x11B1E238+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10B7532C+1
        defadr SoundRecorderDesc_Create,0x10EB7BEC+1
        defadr SoundRecorderDesc_Destroy,0x10EB7C48+1
        defadr SoundRecorderDesc_SetBookID,0x10EB7C64+1
        defadr SoundRecorderDesc_SetType,0x10EB7C90+1
        defadr SoundRecorderDesc_SetFolder,0x10EB7CA4+1
        defadr SoundRecorderDesc_SetFname,0x10EB7CC0+1
        defadr SoundRecorderDesc_SetRecordSize,0x10EB7CDC+1
        defadr SoundRecorder_Create,0x10EB7D54+1
        defadr SoundRecorder_RecordCall,0x10E6A790+1
        defadr Browser_OpenURI,0x107E44AC+1
        defadr GetURIScheme,0x10E7DAD8+1
        defadr CreateURI,0x10E7DF74+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x118764B4+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x108109A4+1
        defadr Alarm_GetState,0x1080F1D4+1
        defadr Alarm_GetTIME,0x108101B0+1
        defadr Alarm_GetWeekSettings,0x108110E8+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11B1E1DC+1
        defadr IncommingCall_Accept,0x10E77350+1
        defadr MediaPlayer_SoftKey_SetText,0x10B600DC+1
        defadr MediaPlayer_SoftKey_SetAction,0x10B60094+1
        defadr MediaPlayer_SoftKey_SetItemAsSubItem,0x10B6013C+1
        defadr MediaPlayer_SoftKey_AddHelpStr,0x10B6016C+1
        defadr DispObject_Show,0x10A354B4+1
        defadr Request_EventChannel_Subscribe,0x12652CB4+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x10875124+1
        defadr Request_ICA_ShutdownAllConnections,0x1150AED0+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11B1E8A4+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1187656C+1
        defadr GUIonMessage_GetMsg,0x11B01F34+1
        defadr GUIonMessage_GetBook,0x11B01F3C+1
        defadr GUIonMessage_GetGui,0x11B01F38+1
        defadr GUIonMessage_GetSelectedItem,0x11B01F40+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11B01F4C+1
        defadr ObexSendFile,0x109070C0+1
        defadr Feedback_SetManualScrollingText,0x117FABCC+1
        defadr EqualizerGain_Set,0x11A6070C+1
        defadr CANVAS_Get_GviGC,0x11447014+1
        defadr GVI_BitBlt,0x111AA3A8+1
        defadr GVI_StretchBlt,0x111AA51C+1
        defadr GVI_TransformBlt,0x111AA5D8+1
        defadr GVI_CreatePen,0x111A9650+1
        defadr GVI_CreateDashedPen,0x111A9694+1
        defadr GVI_CreateSolidBrush,0x111A9560+1
        defadr GVI_Delete_GVI_Object,0x111A8F30+1
        defadr GVI_DrawEllipse,0x111A9CE0+1
        defadr GVI_DrawLine,0x111AABCC+1
        defadr GVI_DrawLines,0x111AB25C+1
        defadr GVI_DrawPolyLine,0x111AB2E0+1
        defadr GVI_DrawRectangle,0x111AB55C+1
        defadr GVI_DrawRoundRect,0x111AA1FC+1
        defadr GVI_DrawSolidLines,0x111AAE20+1
        defadr GVI_DrawSolidPolyLine,0x111AB028+1
        defadr GVI_DrawSolidRectangle,0x111AB0CC+1
        defadr GVI_FillEllipse,0x111AA0C8+1
        defadr GVI_FillPolygon,0x111AAA84+1
        defadr GVI_FillRectangle,0x111AB3DC+1
        defadr GVI_FillRectangles,0x111AB468+1
        defadr GVI_FillSolidEllipse,0x111AA174+1
        defadr GVI_FillSolidRectangle,0x111AAC5C+1
        defadr GVI_FillSolidRoundRect,0x111AA34C+1
        defadr GVI_FillSolidTriangle,0x111AAA10+1
        defadr GC_CreateMemoryGC,0x10A3CE1C+1
        defadr GC_FreeGC,0x10A3CEE4+1
        defadr Settings_ShowNumber_Get,0x11030368+1
        defadr GVI_CreateBitmap,0x111A974C+1
        defadr GVI_CreateMemoryGC,0x111AB6C0+1
        defadr GVI_DeleteMemoryGC,0x111D9360+1
        defadr StringInput_DispObject_SetLanguage,0x108F4368+1
        defadr List_InsertSorted,0x11B47B20+1
        defadr ListMenu_SetItemIcon,0x11B0167C+1
        defadr wstrnupr,0x10DD2FF0+1
        defadr wstrnlwr,0x10B3E7D0+1
        defadr ListMenu_SetItemTextScroll,0x11B01A74+1
        defadr GuiObject_SetListTextColor,0x11B02B54+1
        defadr DispObject_SetTitleTextColor,0x10A34598+1
        defadr DispObject_SetListTextColor,0x11AF45DC+1
        defadr DispObject_SetCursorImage,0x11AF4598+1
        defadr DispObject_SetBackgroundImage,0x11AF45B4+1
        defadr DispObject_SetTitleBackgroundImage,0x10A345B0+1
        defadr TabMenuBar_SetTabTitle,0x117FEC6C+1
        defadr GUIObject_GetBook,0x10A3EE5C+1
        defadr Softkeys_GetSelectedAction,0x10870E2C+1
        defadr MonitorFeedback_SetTimer,0x11ADA970+1
        defadr getListMenuOnDestroy,0x11B011FC+1
        defadr getListMenuOnCreate,0x11AEF804+1
        defadr getListMenuOnDispMessage,0x11B01200+1
        defadr getTabMenuBarOnDestroy,0x117FEAD0+1
        defadr getTabMenuBarOnCreate,0x117F59D0+1
        defadr getTabMenuBarOnDispMessage,0x117FEA20+1
        defadr getOneOfManyOnGuiDestroy,0x11B037D0+1
        defadr getOneOfManyOnDescCreate,0x11AF6090+1
        defadr getOneOfManyOnDispMessage,0x11B037D4+1
        defadr getNOfManyOnGuiDestroy,0x11B031DC+1
        defadr getNOfManyOnDescCreate,0x11AF54F4+1
        defadr getNOfManyOnDispMessage,0x11B031E0+1
        defadr ListMenu_DestroyItems,0x11B017EC+1
        defadr DispObject_SetScrollBarBackgroundColor,0x10A36E88+1
        defadr DispObject_SetScrollBarColor,0x10A36E60+1
        defadr DispObject_SetSoftkeysColor,0x10871398+1
        defadr YesNoQuestion_SetIcon,0x11800C68+1
        defadr GUIObject_SetBacklightTimeout,0x10A3F104+1
        defadr ListMenu_SetHotkeyMode,0x11B014D0+1
        defadr ListMenu_SetSearchLanguageMode,0x11B0194C+1
        defadr ListMenu_EnableSearchHeader,0x11B01974+1
        defadr GUIonMessage_GetSearchString,0x11B0213C+1
        defadr GUIonMessage_GetSearchStringLength,0x11B0215C+1
        defadr EqualizerGain_Get,0x11A606E4+1
        defadr Theme_DestroyMenuIcons,0x10E475A8+1
        defadr CoCreateInstance,0x107835B0+1
        defadr GUIObject_SetSecondRowTitleText,0x10A3F1E0+1
        defadr ListMenu_GetItemCount,0x11B013A8+1
        defadr OSE_GetShell,0x10E7C28C+1
        defadr swscanf,0x107600C8+1
        defadr sscanf,0x10003C7C+1
        defadr BookObj_WindowSetWantsFocus,0x10E5D7B4+1
        defadr BookObj_StayOnTop,0x10E5DC24+1
        defadr DispObject_WindowSetPosition,0x10A36B10+1
        defadr DispObject_WindowSetSize,0x10A36A7C+1
        defadr Feedback_DispObject_GetText,0x117FB4A4+1
        defadr DispObject_SoftKeys_ExecuteAction,0x10871130+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x11872308+1
        defadr DispObject_SetAnimation,0x10A37A44+1
        defadr DispObject_ObjectAnimation,0x10A37A44+1
        defadr socket_create,0x11565EF8+1
        defadr socket_close,0x11565C14+1
        defadr socket_connect,0x11565C34+1
        defadr socket_send,0x11565E20+1
        defadr socket_recv,0x11565D4C+1
        defadr socket_setopt,0x11565EA4+1
        defadr socket_getopt,0x11565CDC+1
        defadr socket_getpeername,0x11565C8C+1
        defadr socket_getsockname,0x11565CB4+1
        defadr socket_shutdown,0x11565ED4+1
        defadr socket_accept,0x11564F60+1
        defadr socket_bind,0x11565BEC+1
        defadr socket_listen,0x11565D0C+1
        defadr socket_sendto,0x11565E60+1
        defadr socket_recvfrom,0x11565D64+1
        defadr fcntl,0x11565C5C+1
        defadr select,0x11565DF0+1
        defadr socket_lasterror,0x11475350+1
        defadr REQUEST_OAF_START_APPLICATION_BY_ID,0x10B984D4+1
        defadr DispObj_Create,0x10A34ACC+1
        defadr DispObj_Destroy,0x10A34BA4+1
        defadr DispObject_SetTitleType,0x10A343CC+1
        defadr DispObject_SetStyle,0x10A37E20+1
	defadr TextFeedBack_SetIcon,0x11340264+1
        defadr SetHorizontalViewVideo,0x10E7FF68+1
        defadr SetVerticalViewVideo,0x10E7FF3C+1
        defadr FlightModeControl,0x11ADD7FC+1
        defadr isFlightMode,0x11ADCFD0+1
        defadr SetOperatorName,0x10DFB640+1
        defadr GetImageHeight,0x10A3A150+1
        defadr Disp_GetStrIdHeight,0x10A3A150+1
        defadr Disp_GetStrIdWidth,0x10A3A1F0+1
        defadr Display_GetTopBook,0x10E5CF8C+1
        defadr ListMenu_SetSecondLineText,0x11B01748+1
        defadr textidname2id,0x11783A48+1
		
        defadr Str2ID,0x10FCEFFC+1
        defadr int2strID,0x10FCEE28+1
        defadr TextFree,0x10FCF338+1

        defadr DisplayGC_AddRef,0x10A3D244+1
        defadr GC_PutChar,0x109D89BC+1

//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x1102D540+1
        defadr FlightGetState,    0x11ADCFD0+1
        
        defadr CallInfo_Get,      0x112E9008+1
        defadr isTimerBook,       0x11010148+1

        defadr some,              0x10E7C4A8+1
        defadr armfunc,           0x1075C734

        defadr Show,              0x10DFB708+1
        defadr Return_Clear,      0x10DFB702+1
        defadr Show_Clear,        0x10DFB730+1

        defadr oldRedrawStatus,   0x117F3EC8+1
        defadr oldRedrawDisplay,  0x10DF8CCC+1
        defadr oldRedrawSoft,     0x10873CC8+1
        defadr oldCreateDisplay,  0x10DF8C60+1
        defadr oldCloseDisplay,   0x10DF8CB8+1
        defadr oldOnKeyMainInput, 0x10DF69B0+1

        defadr retSetIcon,        0x11803718+1

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
          