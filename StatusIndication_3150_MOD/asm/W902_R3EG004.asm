#ifdef W902_R3EG004

defadr	MACRO	a,b
	PUBLIC	a
a	EQU	b
	ENDM

	defadr int2strID,0x10F699E8+1
	defadr Str2ID,0x10F69BBC+1
	defadr TextFree,0x10F69EF8+1

	defadr memalloc,0x4BB00584
	defadr memfree,0x4BB005AC
	defadr memset,0x4BB010C4
	defadr memcpy,0x10147898
	defadr sprintf,0x10700200+1
	defadr snwprintf,0x107006BC+1
	defadr _fopen,0x10960338+1
	defadr fclose,0x11721C80+1
	defadr fread,0x10961CCC+1
	defadr fwrite,0x10961E98+1
	defadr fstat,0x10960C9C+1
	defadr AllocDirHandle,0x1095E188+1
	defadr GetFname,0x1095E358+1
	defadr DataBrowserDesc_Create,0x11814AC0+1
	defadr DataBrowserDesc_SetItemStyle,0x11814D40+1
	defadr DataBrowserDesc_SetHeaderText,0x11814D70+1
	defadr DataBrowserDesc_SetFolders,0x11814D58+1
	defadr DataBrowserDesc_SetOKSoftKeyText,0x11814D78+1
	defadr DataBrowser_Create,0x11810D2C+1
	defadr DataBrowserDesc_Destroy,0x11814B70+1
	defadr getFileExtention,0x109639A8+1
	defadr DataBrowser_isFileInListExt,0x1095E5BC+1
	defadr Timer_ReSet,0x10DF4CB4+1
	defadr Timer_Set,0x10DF4C80+1
	defadr Timer_Kill,0x10DF4D0C+1
	defadr CreateBook,0x10DF86A0+1
	defadr BookObj_KillBook,0x10DF87B4+1
	defadr BookObj_GotoPage,0x10DF83B0+1
	defadr BookObj_ReturnPage,0x10DF8568+1
	defadr FreeBook,0x10DF8D20+1
	defadr FindBook,0x10DF8168+1
	defadr Find_StandbyBook,0x10D95ADC+1
	defadr BookObj_SetFocus,0x10DF8950+1
	defadr GUIObject_SetTitleText,0x109DAA08+1
	defadr GUIObject_Show,0x109DA7F4+1
	defadr ListMenu_SetCursorToItem,0x11AA38C8+1
	defadr GUIObject_SetStyle,0x109DA84C+1
	defadr GUIonMessage_GetCreatedItemIndex,0x11AA44B4+1
	defadr GUIonMessage_SetMenuItemText,0x11AA44C0+1
	defadr GUIonMessage_SetMenuItemSecondLineText,0x11AA44F0+1
	defadr GUIonMessage_SetMenuItemInfoText,0x11AA44D0+1
	defadr GUIonMessage_SetMenuItemUnavailableText,0x11AA44E0+1
	defadr GUIonMessage_SetMenuItemIcon,0x11AA4500+1
	defadr DispObject_SetTitleText,0x109CFB48+1
	defadr ListMenu_GetSelectedItem,0x11AA38DC+1
	defadr ListMenu_SetItemStyle,0x11AA392C+1
  	defadr GC_PutChar,0x109D908C+1
	defadr isScreenSaverBook,0x108F0CFD
	defadr StatusIndication_SetItemText,0x10D95080+1
	defadr StatusIndication_ShowNotes,0x10D96C90+1
	defadr CreateStringInputVA,0x1089AFFC+1
	defadr CreateOneOfMany,0x11AA5CB8+1
	defadr OneOfMany_SetItemCount,0x11AA5E44+1
	defadr OneOfMany_SetChecked,0x11AA5E60+1
	defadr OneOfMany_SetTexts,0x11AA5E94+1
	defadr OneOfMany_GetSelected,0x11AA5E70+1
	defadr StatusIndication_Item8_SetText,0x10D96B9C+1
	defadr GUIObject_SoftKeys_SetAction,0x108153E4+1
	defadr GUIObject_SoftKeys_SetText,0x1081545C+1
	defadr GUIObject_SoftKeys_SetEnable,0x1081554C+1
	defadr GUIObject_SoftKeys_AddErrorStr,0x10815504+1
	defadr GUIObject_SoftKeys_RemoveItem,0x10815398+1
	defadr GUIObject_SoftKeys_SetVisible,0x108154E0+1
	defadr GUIObject_SoftKeys_SuppressDefaultAction,0x10815750+1
	defadr wstrcpy,0x10D6E634+1
	defadr wstrncpy,0x10D6E64C+1
	defadr wstrcat,0x10700D7C+1
	defadr wstrncat,0x10D6E694+1
	defadr wstrcmp,0x10D6E604+1
	defadr wstrlen,0x10D6E5F0+1
	defadr str2wstr,0x10D6F8B8+1
	defadr strcmp,0x10700488+1
	defadr strlen,0x107004E4+1
	defadr wstr2strn,0x10D6E710+1
	defadr TextID_CreateIntegerID,0x10F699E8+1
	defadr TextID_Create,0x10F69BBC+1
	defadr TextID_GetString,0x10F6A2C8+1
	defadr TextID_GetWString,0x10F6A150+1
	defadr TextID_GetLength,0x10F6A000+1
	defadr TextID_Destroy,0x10F69EF8+1
	defadr AB_DEFAULTNBR_GET,0x10B6D17C+1
	defadr AB_READSTRING,0x10B83EA8+1
	defadr AB_READPHONENBR,0x10B73554+1
	defadr AB_GETNBROFITEMS,0x10B7360C+1
	defadr PNUM_len,0x10F691BC+1
	defadr PNUM2str,0x10941320+1
	defadr GUIObject_GetDispObject,0x109DA68C+1
	defadr List_Create,0x11AE9ED4+1
	defadr List_Destroy,0x11AE9EFC+1
	defadr List_InsertFirst,0x11AEA048+1
	defadr Gif2ID,0x107AA384+1
	defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107AA5B4+1
	defadr REQUEST_DATEANDTIME_GET,0x107B4598+1
	defadr IndicationDevice_Backlight_FadeToLevel,0x10E6D154+1
	defadr GetFreeBytesOnHeap,0x4BB00700
	defadr BookObj_Hide,0x10DF8978+1
	defadr BookObj_Show,0x10DF8988+1
	defadr StartAPP,0x10D95CC8+1
	defadr ListMenu_SetOnMessage,0x11AA3A00+1
	defadr manifest_GetParam,0x10B0E110+1
	defadr lseek,0x10962040+1
	defadr get_VBUFFER,0x0
	defadr SetLampLevel,0x1000592A+1
	defadr List_RemoveAt,0x11AEA0C4+1
	defadr GetCurrentPID,0x10005E58+1
	defadr List_IndexOf,0x11AEA008+1
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
	defadr datetime2unixtime,0x10BD5E2C+1
	defadr strcpy,0x107004B0+1
	defadr CreateMessage,0x10E175D0+1
	defadr SendMessage,0x10E17624+1
	defadr WaitMessage,0x10E176AC+1
	defadr FreeMessage,0x10E176C0+1
	defadr SendDispatchMessage,0x10BE18F4+1
	defadr UIEventName,0x10DF509C+1
	defadr MissedEvents,0x4BBA9F40
	defadr UI_Event,0x10DF7440+1
	defadr UI_Event_wData,0x10DF7450+1
	defadr UI_Event_toBookID,0x10DF7498+1
	defadr UI_Event_toBookIDwData,0x10DF74AC+1
	defadr List_Find,0x11AEA1A4+1
	defadr List_Get,0x11AEA0F4+1
	defadr wstrrchr,0x10D6F974+1
	defadr BookObj_CallSubroutine,0x10DF8440+1
	defadr List_InsertLast,0x11AEA050+1
	defadr debug_printf,0x4BB3FB10+1
	defadr PlayFile,0x11A05BA8+1
	defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11AC0CC0+1
	defadr Profile_SetActive,0x11AF1018+1
	defadr SetBrightnessOfScreen,0x10DC9684+1
	defadr isKeylocked,0x108F0B00+1
	defadr IsMediaPlayerVideoBook,0x10E1B8E0+1
	defadr ShuttingDown,0x11A7DBA8+1
	defadr Vibra,0x11A04ED0+1
	defadr REQUEST_DATEFORMAT_GET,0x107B4778+1
	defadr REQUEST_TIMEFORMAT_GET,0x107B485C+1
	defadr Date2ID,0x11A7E218+1
	defadr Time2ID,0x11A7E134+1
	defadr CreateListMenu,0x11AA36DC+1
	defadr ListMenu_SetItemCount,0x11AA38F0+1
	defadr ROOT_APP,0x4BBB6348
	defadr GUIObject_SoftKeys_SetInfoText,0x10815448+1
	defadr GUIObject_SoftKeys_SetItemAsSubItem,0x10815580+1
	defadr REQUEST_SYSTEM_SHUTDOWN,0x11A81800+1
	defadr REQUEST_SYSTEM_RESTART,0x11A81810+1
	defadr GUIObject_SoftKeys_SetTexts,0x108154B4+1
	defadr IsRightNowBook,0x10B3AF34+1
	defadr IsVolumeControllerBook,0x11ADD448+1
	defadr CreateTabMenuBar,0x1179D350+1
	defadr TabMenuBar_SetTabCount,0x1179D5A8+1
	defadr TabMenuBar_SetTabGui,0x1179D420+1
	defadr TabMenuBar_SetTabIcon,0x1179D4A0+1
	defadr GUIObject_Destroy,0x109DA600+1
	defadr GUIInput_SetIcon,0x109DA8C8+1
	defadr StringInput_GetStringAndLen,0x1089B8AC+1
	defadr GetAudioControlPtr,0x4BBD3638
	defadr AudioControl_Vibrate,0x1156CE04+1
	defadr GetVolumeSize,0x109636C0+1
	defadr CreateNOfMany,0x11AA56C4+1
	defadr NOfMany_SetTexts,0x11AA58C8+1
	defadr NOfMany_SetChecked,0x11AA584C+1
	defadr NOfMany_SetCursor,0x11AA5814+1
	defadr NOfMany_GetCheckedCount,0x11AA5870+1
	defadr NOfMany_GetChecked,0x11AA5860+1
	defadr NOfMany_SetOnMessage,0x11AA58C0+1
	defadr AudioControl_Init,0x11A05CF4+1
	defadr OneOfMany_SetFocused,0x11AA5E28+1
	defadr OneOfMany_SetOnMessage,0x11AA5E8C+1
	defadr CreateMonitorFeedback,0x11A7CDFC+1
	defadr Feedback_SetText,0x11A7CEB4+1
	defadr GetBatteryState,0x1108F5D4+1
	defadr get_DisplayGC,0x109D8650+1
	defadr DispObject_GetRect,0x109D1248+1
	defadr GC_GetRect,0x109D8C94+1
	defadr GC_GetXX,0x109D8F90+1
	defadr GC_SetXX,0x109D8F84+1
	defadr GC_ValidateRect,0x109D8C44+1
	defadr BookObj_AddGUIObject,0x10DF8A30+1
	defadr DrawRect,0x109D439C+1
	defadr DrawString,0x109D46E8+1
	defadr XGUIList_AddGUIObject,0x10DF8F30+1
	defadr DispObject_InvalidateRect,0x109D0FD8+1
	defadr GUIObject_Create,0x109DA43C+1
	defadr SetFont,0x109D52A8+1
	defadr StatusRow_p,0x4BBD17DC
	defadr root_list_get_session_count,0x10DF69D8+1
	defadr root_list_get_session,0x10DF69E8+1
	defadr SESSION_GetTopBook,0x10DF61B8+1
	defadr MainInput_strlen,0x10D955DC+1
	defadr MainInput_getPNUM,0x10D9560C+1
	defadr BookObj_GetBookID,0x10DF8E0C+1
	defadr wstrncmp,0x10700E50+1
	defadr DispObject_GetAbsoluteXPos,0x109D244C+1
	defadr DispObject_GetAbsoluteYPos,0x109D2480+1
	defadr DispObject_GetWindow,0x109D155C+1
	defadr GetThemeColor,0x10E677D4+1
	defadr REQUEST_SETTING_SILENCE_SET,0x11AC06F4+1
	defadr REQUEST_SETTING_SILENCE_GET,0x11AC069C+1
	defadr VCALL_Init,0x10B613C4+1
	defadr VCALL_SetName,0x10B614BC+1
	defadr VCALL_SetNameIcon,0x10B6151C+1
	defadr VCALL_SetNumber,0x10B614DC+1
	defadr VCALL_SetHZ1,0x10B61500+1
	defadr VCALL_SetHZ2,0x10B6150C+1
	defadr MakeVoiceCall,0x10B60F5C+1
	defadr FileDelete,0x10960F2C+1
	defadr GUIObject_SetFocus,0x109DA7B8+1
	defadr MSG_SendMessage_CreateMessage,0x11A33E68+1
	defadr MSG_SendMessage_DestroyMessage,0x11A345AC+1
	defadr MSG_SendMessage_AddRecipient,0x11A34048+1
	defadr MSG_SendMessage_Start,0x11A344D4+1
	defadr get_APP_DESC_TABLE,0x11BA4EC4
	defadr Window_GetComponentInterface,0x109D7FFC+1
	defadr AB_POSITIONNBR_GET,0x10B737F8+1
	defadr AB_NAME_ITEM2TextID,0x10B7370C+1
	defadr AB_NUM_ITEM2TextID,0x10B73770+1
	defadr GetABRecNum,0x10B737F4+1
	defadr get_AB_ITEMS_DESC,0x11B8DACC
	defadr SBY_GetMainInput,0x108AC484+1
	defadr SBY_GetStatusIndication,0x10771768+1
	defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10A58BAC+1
	defadr PID_MMI,0x4BBB4994
	defadr DispObject_GetGUI,0x109D08BC+1
	defadr Display_GetFocusedDispObject,0x109D0808+1
	defadr DispObject_GetVisible,0x109D0E7C+1
	defadr DispObject_GetDESC,0x10014E98+1
	defadr DISP_DESC_SetName,0x109CDA88+1
	defadr DispObject_GetName,0x109D21A4+1
	defadr DISP_DESC_SetSize,0x109CDA8C+1
	defadr DISP_DESC_SetOnCreate,0x109CDA90+1
	defadr DispObject_GetOnCreate,0x109CDB0C+1
	defadr DISP_DESC_SetOnClose,0x109CDA94+1
	defadr DispObject_GetOnClose,0x109CDB28+1
	defadr DISP_DESC_SetOnRedraw,0x109CDA98+1
	defadr DispObject_GetOnRedraw,0x109CDB44+1
	defadr DISP_DESC_SetOnKey,0x109CDAA0+1
	defadr DispObject_GetOnKey,0x109CDB7C+1
	defadr DISP_DESC_SetOnRefresh,0x109CDA9C+1
	defadr DispObject_GetonRefresh,0x109CDB60+1
	defadr DISP_DESC_SetMethod06,0x109CDAA4+1
	defadr DispObject_GetMethod06,0x109CDB98+1
	defadr DISP_DESC_SetOnLayout,0x109CDAAC+1
	defadr DispObject_GetOnLayout,0x109CDBD0+1
	defadr DISP_DESC_SetOnConfig,0x109CDAB0+1
	defadr DispObject_GetOnConfig,0x109CDBEC+1
	defadr DISP_DESC_SetMethod0A,0x109CDAB4+1
	defadr DispObject_GetMethod0A,0x109CDC08+1
	defadr DISP_DESC_SetMethod0B,0x109CDAB8+1
	defadr DispObject_GetMethod0B,0x109CDC24+1
	defadr DISP_DESC_SetMethod0C,0x109CDABC+1
	defadr JavaSession_Manager,0x10B737F4+1
	defadr JavaSession_GetName,0x108E7008+1
	defadr TextID_Copy,0x10F69D9C+1
	defadr BookObj_GetSession,0x10DF8D6C+1
	defadr GUIonMessage_SetNumberOfSubItems,0x11AA455C+1
	defadr GUIonMessage_SubItem_SetText,0x11AA45C8+1
	defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x11AA45BC+1
	defadr GoMusic,0x10E2EE2C+1
	defadr Vibra_Off,0x11A04FA4+1
	defadr GUIonMessage_SubItem_SetDisabled,0x11AA4630+1
	defadr PlayFileV,0x11A05BAC+1
	defadr GetSilent,0x11A04024+1
	defadr GetVibrator,0x119FF920+1
	defadr GetAudioSettings,0x11A05340+1
	defadr GetChipID,0x12700A30+1
	defadr GUIonMessage_SubItem_GetCreatedIndex,0x11AA45B0+1
	defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x11AA45A4+1
	defadr DestroyDirHandle,0x1095E4D4+1
	defadr LastExtDB,0x11F1AFEC
	defadr GetOtherExtMethods,0x1180AD2C+1
	defadr MessageBox,0x11A7B3B8+1
	defadr Display_GetHeight,0x1179F9AC+1
	defadr Display_GetWidth,0x1179F9B8+1
	defadr PlaySystemSound,0x11A05B50+1
	defadr TabMenuBar_GetFocusedTab,0x1179D414+1
	defadr TabMenuBar_SetFocusedTab,0x1179D404+1
	defadr GC_GetPenColor,0x109D8E9C+1
	defadr GC_SetPenColor,0x109D8E60+1
	defadr GC_SetPixel,0x109D8AE4+1
	defadr GC_DrawLine,0x109D95E0+1
	defadr GC_DrawFRect,0x109D976C+1
	defadr GC_WritePixels,0x109D8B6C+1
	defadr png_create_read_struct_2,0x118494D0+1
	defadr png_destroy_read_struct,0x1184961C+1
	defadr png_create_info_struct,0x11847C78+1
	defadr png_destroy_info_struct,0x11847CAC+1
	defadr png_set_progressive_read_fn,0x118494A8+1
	defadr png_process_data,0x11848468+1
	defadr png_read_update_info,0x118495F0+1
	defadr png_get_progressive_ptr,0x118494CC+1
	defadr png_get_IHDR,0x11848134+1
	defadr png_set_strip_16,0x118497BC+1
	defadr png_set_gray_1_2_4_to_8,0x118497C8+1
	defadr png_set_gray_to_rgb,0x118497EC+1
	defadr png_get_valid,0x11848108+1
	defadr png_set_tRNS_to_alpha,0x118497E0+1
	defadr png_set_filler,0x1184C550+1
	defadr png_set_palette_to_rgb,0x118497D4+1
	defadr png_get_rowbytes,0x11848120+1
	defadr png_progressive_combine_row,0x11849488+1
	defadr png_sig_cmp,0x11847B70+1
	defadr setjmp,0x1014BB34
	defadr longjmp,0x1014BB58
	defadr inflateInit2_,0x1184D224+1
	defadr inflate,0x1184D3CC+1
	defadr inflateEnd,0x1184E6C4+1
	defadr memcmp,0x126FB514
	defadr strncmp,0x10700528+1
	defadr strncpy,0x1070055C+1
	defadr strcat,0x10700450+1
	defadr GUIObject_SetTitleType,0x109DA9EC+1
	defadr GUIonMessage_SetItemDisabled,0x11AA4568+1
	defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107AA62C+1
	defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107AA6B4+1
	defadr get_Surfaces,0x4BD90290
	defadr iconidname2id,0x115384AC+1
	defadr textidname2id,0x11721AE8+1
	defadr ListMenu_SetNoItemText,0x11AA3A80+1
	defadr IsFmRadioBook,0x10FAF718+1
	defadr IsAudioPlayerBook,0x10C8F7AC+1
	defadr PlayerControl,0x10C8F148+1
	defadr SwitchRadioStationFromList,0x10FAD5EC+1
	defadr Shortcut_Run,0x10DE4C10+1
	defadr mkdir,0x1095D8B4+1
	defadr rmdir,0x1095DCA8+1
	defadr chmod,0x10960E58+1
	defadr rename,0x10961480+1
	defadr GetImageWidth,0x109D5980+1

	defadr Disp_GetStrIdHeight,0x109D5994+1
	defadr CallID_GetCallStatusDesc,0x10E0940C+1
	defadr CallStatusDesc_GetName,0x10E08A44+1
	defadr List_DestroyElements,0x11AEA1E8+1
	defadr strstr,0x107005F8+1
	defadr GPRS_GetLastSessionInfo,0x10807A9C+1
	defadr wstrcmpni,0x10D6FA10+1
	defadr wtoi,0x10DF46E0+1
	defadr DATE_GetWeekDay,0x10BD6128+1
	defadr Cale_GetSettings,0x1092D724+1
	defadr wstrwstr,0x10700FB0+1
	defadr wstrcmpi,0x10D6FA54+1
	defadr wstrchr,0x10700D98+1
	defadr GUIObject_SoftKeys_Hide,0x1081579C+1
	defadr GUIObject_SoftKeys_Show,0x108157A8+1
	defadr DispObject_SoftKeys_Get,0x10811B74+1
	defadr StandbyBackground_SetImage,0x10E66048+1
	defadr CreateYesNoQuestionVA,0x1179F260+1
	defadr ListMenu_SetSecondLineText,0x11AA3CA4+1
	defadr _REQUEST_OAF_START_APPLICATION,0x10B33BB0+1
	defadr FSX_GetInvalidChar,0x109634B0+1
	defadr DataBrowserDesc_SetFoldersNumber,0x11814D60+1
	defadr DataBrowserDesc_SetActions,0x11814D14+1
	defadr DataBrowserDesc_SetSelectAction,0x11814CDC+1
	defadr DataBrowserDesc_SetSelectActionOnFolders,0x11814CE4+1
	defadr DataBrowserDesc_SetBookID,0x11814CC0+1
	defadr DataBrowserDesc_SetItemFilter,0x11814C64+1
	defadr DataBrowserDesc_SetOption,0x11814D90+1
	defadr DataBrowserDesc_SetOpenEmptyFolder,0x11814DF8+1
	defadr DataBrowserDesc_SetFileExtList,0x11814C6C+1
	defadr FSX_RemoveIllegalSymbolsName,0x1181E4D4+1
	defadr FILEITEM_Create,0x1181DEEC+1
	defadr FILEITEM_Destroy,0x1181E01C+1
	defadr CreateDateInputVA,0x1179D6DC+1
	defadr CreateTimeInputVA,0x1179EE38+1
	defadr StringInput_SetCursorPosition,0x1089B8F8+1
	defadr BookObj_CallPage,0x10DF84E4+1
	defadr DateInput_GetDateInt,0x1179D94C+1
	defadr TimeInput_GetTimeInt,0x1179F100+1
	defadr GetFontDesc,0x4BBAE01C
	defadr GetFontCount,0x4BBAE38C
	defadr GC_GetBrushColor,0x109D8F78+1
	defadr GC_SetBrushColor,0x109D8F38+1
	defadr GC_DrawRoundRect,0x109D97B4+1
	defadr MenuBook_Desktop,0x10DE43C4+1
	defadr MenuBook_Desktop_GetSelectedItemID,0x10DE36F8+1
	defadr BookObj_SoftKeys_SetAction,0x1080FA34+1
	defadr BookObj_SoftKeys_SetText,0x1080FA6C+1
	defadr FindBookByID,0x10DF68A4+1
	defadr TextFeedbackWindow,0x1179E69C+1
	defadr Feedback_SetKeyHook,0x1179EAA8+1
	defadr Feedback_SetOnClose,0x1179EA44+1
	defadr Feedback_SetTimeout,0x1179EA74+1
	defadr Feedback_SetTextExtended,0x1179EB0C+1
	defadr TabMenuBar_SetOnTabSwitch,0x1179D4FC+1
	defadr KeyCode2Name,0x10FB4544+1
	defadr ImageID_Get,0x107A8534+1
	defadr ImageID_Free,0x107AE74C+1
	defadr DataBrowser_CreateSubExecute,0x117FDB34+1
	defadr DataBrowser_ExecuteSubroutine,0x117FE554+1
	defadr FILEITEM_SetFname,0x1181E0C8+1
	defadr FILEITEM_SetPath,0x1181E388+1
	defadr FILEITEM_GetFname,0x1181E380+1
	defadr FILEITEM_GetPath,0x1181E414+1
	defadr FILEITEM_SetFnameAndContentType,0x1181E128+1
	defadr FILEITEM_SetPathAndContentType,0x1181E3EC+1
	defadr JavaDialog_Open,0x10B1C0A0+1
	defadr JavaDialog_Close,0x10B1F7F4+1
	defadr JavaAppDesc_Get,0x10B1F9C0+1
	defadr JavaAppDesc_GetFirstApp,0x10B11A34+1
	defadr JavaAppDesc_GetNextApp,0x10B11A3C+1
	defadr JavaAppDesc_GetJavaAppInfo,0x10B11500+1
	defadr DispObject_SetRefreshTimer,0x109D0A40+1
	defadr DispObject_KillRefreshTimer,0x109D0ABC+1
	defadr IsDataBrowserBook,0x1181162C+1
	defadr BrowserItem_Get_SUB_EXECUTE,0x1180CDBC+1
	defadr Shortcut_Get_MenuItemName,0x10B3CA94+1
	defadr Shortcut_Get_MenuItemIconID,0x10DE45E8+1
	defadr FindBookEx,0x10DF6938+1
	defadr FILEITEM_CreateCopy,0x1181DF1C+1
	defadr ActionCreate,0x10DF80C8+1
	defadr BookObj_GetSessionID,0x10DF8C94+1
	defadr UI_Event_toSID,0x10DF7464+1
	defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11A7D88C+1
	defadr DispObject_SoftKeys_RestoreDefaultAction,0x10811554+1
	defadr PNUM2Name,0x10B5C5F4+1
	defadr SpeedDial_GetPNUM,0x10B83B1C+1
	defadr DispObject_GetWindowWidth,0x109D23CC+1
	defadr DispObject_GetWindowHeight,0x109D23EC+1
	defadr get_system_langID,0x10DC0818+1
	defadr lang_get_name,0x11AACA20+1
	defadr w_chdir,0x4BB003AC
	defadr w_fopen,0x112B57F4+1
	defadr w_fstat,0x112B58AC+1
	defadr w_fwrite,0x112B583C+1
	defadr w_fread,0x112B5824+1
	defadr w_lseek,0x11A761B0+1
	defadr w_fclose,0x112B5854+1
	defadr w_mkdir,0x4BB00344
	defadr DirHandle_SetFilterStr,0x1095E52C+1
	defadr Disp_GetStrIdWidth,0x109D5A34+1
	defadr ImageID_GetIndirect,0x107A85CC+1
	defadr unixtime2datetime,0x10BD5F40+1
	defadr List_Insert,0x11AE9F24+1
	defadr FileCopy,0x10961234+1
	defadr FileMove,0x10961480+1
	defadr DispObject_SetLayerColor,0x109D31D0+1
	defadr JavaAppDesc_GetJavaAppID,0x10B1F91C+1
	defadr REQUEST_UI_OAF_START_APPLICATION,0x10C4408C+1
	defadr JavaApp_LogoImageID_Get,0x10C388BC+1
	defadr CreateProgressBar,0x1179DE10+1
	defadr ProgressBar_SetText,0x1179E108+1
	defadr ProgressBar_SetIcon,0x1179E27C+1
	defadr ProgressBar_SetPercentValue,0x1179E0C4+1
	defadr ProgressBar_SetBarDisabled,0x1179E29C+1
	defadr StringInput_DispObject_SetText,0x1089018C+1
	defadr GUIObject_SetTitleIcon,0x109DAA40+1
	defadr DispObject_SoftKeys_GetParams,0x10812824+1
	defadr DispObject_SoftKeys_GetList,0x10812868+1
	defadr BookObj_GetDisplayOrientation,0x10DF8EA8+1
	defadr BookObj_SetDisplayOrientation,0x10DF8E44+1
	defadr Display_GetTopBook,0x10DF8184+1
	defadr Display_SetBrightness,0x10DC9570+1
	defadr Display_GetBrightness,0x10DC9530+1
	defadr DataBrowserDesc_Menu_AddFSFunctions,0x11814CC8+1
	defadr DataBrowserDesc_Menu_AddNewFolder,0x11814D24+1
	defadr DataBrowserDesc_Menu_AddMarkFiles,0x11814D2C+1
	defadr SetTheme,0x10E15190+1
	defadr SoftKeys_GetLabel,0x10814D50+1
	defadr SoftKeys_Update,0x10814908+1
	defadr get_CellData,0x108F426C+1
	defadr IncommingCall_Reject,0x10E12644+1
	defadr IncommingCall_Mute,0x10E13984+1
	defadr Bluetooth_GetState,0x10A6CA8C+1
	defadr Bluetooth_GetPhoneVisibility,0x10A6CA50+1
	defadr Bluetooth_isBusy,0x10A6CB1C+1
	defadr USB_isConnected,0x109C47FC+1
	defadr w_diropen,0x4BB00354
	defadr w_dirread,0x11A76840+1
	defadr w_dirclose,0x4BB0038C
	defadr w_rename,0x11A768DC+1
	defadr w_remove,0x11A76890+1
	defadr ConnectionManager_Connection_GetState,0x10C2D454+1
	defadr IsCameraBook,0x108CE574+1
	defadr IsSoundRecorderBook,0x10E539C8+1
	defadr StringInput_MenuItem_SetPriority,0x1089BA00+1
	defadr Video_ActionBack,0x10E1B27C+1
	defadr Video_ExtractFrame,0x10E1BB84+1
	defadr Video_ZoomOn,0x10E1B24C+1
	defadr RightNow_SetActive,0x10B3B568+1
	defadr Video_Play,0x10E1B184+1
	defadr Video_Pause,0x10E1B194+1
	defadr Audio_Pause,0x10C911C0+1
	defadr Audio_Play,0x10C91164+1
	defadr CreatePercentInputVA,0x1179DA7C+1
	defadr PercentInput_GetPercent,0x1179DC08+1
	defadr GUIonMessage_SetLineSeparator,0x11AA4580+1
	defadr PHF_GetState,0x10A21314+1
	defadr CHF_GetState,0x10A2131C+1
	defadr GUIObject_SoftKeys_RemoveBackground,0x108157B4+1
	defadr GUIObject_SoftKeys_RestoreBackground,0x108157C0+1
	defadr SetTrayIcon,0x117A1F7C+1
	defadr REQUEST_SETTING_RINGVOLUME_SET,0x11AC039C+1
	defadr REQUEST_SETTING_VIBRATOR_SET,0x11AC0590+1
	defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x11AC050C+1
	defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11AC0974+1
	defadr REQUEST_SETTING_INCREASINGRING_SET,0x11AC04A4+1
	defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x11AC079C+1
	defadr JavaAppDesc_GetJavaAppFullpath,0x10B10AE0+1
	defadr SoundRecorderDesc_Create,0x10E52E74+1
	defadr SoundRecorderDesc_Destroy,0x10E52ED0+1
	defadr SoundRecorderDesc_SetBookID,0x10E52EEC+1
	defadr SoundRecorderDesc_SetType,0x10E52F18+1
	defadr SoundRecorderDesc_SetFolder,0x10E52F2C+1
	defadr SoundRecorderDesc_SetFname,0x10E52F48+1
	defadr SoundRecorderDesc_SetRecordSize,0x10E52F64+1
	defadr SoundRecorder_Create,0x10E52FDC+1
	defadr SoundRecorder_RecordCall,0x10E05968+1
	defadr Browser_OpenURI,0x10784B0C+1
	defadr GetURIScheme,0x10E18D50+1
	defadr CreateURI,0x10E191EC+1
	defadr DataBrowserDesc_SetViewModeAndSortOrder,0x11814D48+1
	defadr Alarm_GetCurrentTypeAndAlarmID,0x107B0FFC+1
	defadr Alarm_GetState,0x107AF82C+1
	defadr Alarm_GetTIME,0x107B0808+1
	defadr Alarm_GetWeekSettings,0x107B1740+1
	defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11AC0740+1
	defadr IncommingCall_Accept,0x10E12508+1
	defadr MediaPlayer_SoftKey_SetText,0x10AFB94C+1
	defadr MediaPlayer_SoftKey_SetAction,0x10AFB904+1
	defadr MediaPlayer_SoftKey_SetItemAsSubItem,0x10AFB9AC+1
	defadr MediaPlayer_SoftKey_AddHelpStr,0x10AFB9DC+1
	defadr DispObject_Show,0x109D0CF8+1
	defadr Request_EventChannel_Subscribe,0x1273FC74+1
	defadr GUIObject_SoftKeys_ExecuteAction,0x1081577C+1
	defadr Request_ICA_ShutdownAllConnections,0x114B63F8+1
	defadr REQUEST_PROFILE_GETPROFILENAME,0x11AC0E08+1
	defadr DataBrowserDesc_SetFocusToFILEITEM,0x11814E00+1
	defadr GUIonMessage_GetMsg,0x11AA4490+1
	defadr GUIonMessage_GetBook,0x11AA4498+1
	defadr GUIonMessage_GetGui,0x11AA4494+1
	defadr GUIonMessage_GetSelectedItem,0x11AA449C+1
	defadr GUIonMessage_GetPrevSelectedItem,0x11AA44A8+1
	defadr ObexSendFile,0x108A7620+1
	defadr Feedback_SetManualScrollingText,0x11799448+1
	defadr EqualizerGain_Set,0x11A02758+1
	defadr CANVAS_Get_GviGC,0x113F4080+1
	defadr GVI_BitBlt,0x1114E01C+1
	defadr GVI_StretchBlt,0x1114E190+1
	defadr GVI_TransformBlt,0x1114E24C+1
	defadr GVI_CreatePen,0x1114D2C4+1
	defadr GVI_CreateDashedPen,0x1114D308+1
	defadr GVI_CreateSolidBrush,0x1114D1D4+1
	defadr GVI_Delete_GVI_Object,0x1114CBA4+1
	defadr GVI_DrawEllipse,0x1114D954+1
	defadr GVI_DrawLine,0x1114E840+1
	defadr GVI_DrawLines,0x1114EED0+1
	defadr GVI_DrawPolyLine,0x1114EF54+1
	defadr GVI_DrawRectangle,0x1114F1D0+1
	defadr GVI_DrawRoundRect,0x1114DE70+1
	defadr GVI_DrawSolidLines,0x1114EA94+1
	defadr GVI_DrawSolidPolyLine,0x1114EC9C+1
	defadr GVI_DrawSolidRectangle,0x1114ED40+1
	defadr GVI_FillEllipse,0x1114DD3C+1
	defadr GVI_FillPolygon,0x1114E6F8+1
	defadr GVI_FillRectangle,0x1114F050+1
	defadr GVI_FillRectangles,0x1114F0DC+1
	defadr GVI_FillSolidEllipse,0x1114DDE8+1
	defadr GVI_FillSolidRectangle,0x1114F158+1
	defadr GVI_FillSolidRoundRect,0x1114DFC0+1
	defadr GVI_FillSolidTriangle,0x1114E684+1
	defadr GC_CreateMemoryGC,0x109D8660+1
	defadr GC_FreeGC,0x109D8728+1
	defadr Settings_ShowNumber_Get,0x10FCB0CC+1
	defadr GVI_CreateBitmap,0x1114D3C0+1
	defadr GVI_CreateMemoryGC,0x1114F334+1
	defadr GVI_DeleteMemoryGC,0x1117CFCC+1
	defadr StringInput_DispObject_SetLanguage,0x108948C0+1
	defadr List_InsertSorted,0x11AEA06C+1
	defadr ListMenu_SetItemIcon,0x11AA3BD8+1
	defadr wstrnupr,0x10D6E6C0+1
	defadr wstrnlwr,0x10ADA1C0+1
	defadr ListMenu_SetItemTextScroll,0x11AA3FD0+1
	defadr GUIObject_SetListTextColor,0x11AA50B0+1
	defadr DispObject_SetTitleTextColor,0x109CFDDC+1
	defadr DispObject_SetListTextColor,0x11A96B38+1
	defadr DispObject_SetCursorImage,0x11A96AF4+1
	defadr DispObject_SetBackgroundImage,0x11A96B10+1
	defadr DispObject_SetTitleBackgroundImage,0x109CFDF4+1
	defadr TabMenuBar_SetTabTitle,0x1179D4E8+1
	defadr GUIObject_GetBook,0x109DA6A0+1
	defadr SoftKeys_GetSelectedAction,0x10811484+1
	defadr MonitorFeedback_SetTimer,0x11A7CEA8+1
	defadr ListMenu_DestroyItems,0x11AA3D48+1
	defadr DispObject_SetScrollBarBackgroundColor,0x109D26CC+1
	defadr DispObject_SetScrollBarColor,0x109D26A4+1
	defadr DispObject_SetSoftkeysColor,0x108119F0+1
	defadr YesNoQuestion_SetIcon,0x1179F4E4+1
	defadr GUIObject_SetBacklightTimeout,0x109DA948+1
	defadr ListMenu_SetHotkeyMode,0x11AA3A2C+1
	defadr ListMenu_SetSearchLanguageMode,0x11AA3EA8+1
	defadr ListMenu_EnableSearchHeader,0x11AA3ED0+1
	defadr GUIonMessage_GetSearchString,0x11AA4698+1
	defadr GUIonMessage_GetSearchStringLength,0x11AA46B8+1
	defadr EqualizerGain_Get,0x11A02730+1
	defadr Theme_DestroyMenuIcons,0x10DE27B0+1

	defadr GUIObject_SetSecondRowTitleText,0x109DAA24+1
	defadr ListMenu_GetItemCount,0x11AA3904+1
	defadr OSE_GetShell,0x10E17504+1
	defadr swscanf,0x107006F0+1
	defadr sscanf,0x10003C7C+1
	defadr BookObj_WindowSetWantsFocus,0x10DF89AC+1
	defadr BookObj_StayOnTop,0x10DF8E1C+1
	defadr DispObject_WindowSetPosition,0x109D2354+1
	defadr DispObject_WindowSetSize,0x109D22C0+1
	defadr Feedback_DispObject_GetText,0x11799D20+1
	defadr DispObject_SoftKeys_ExecuteAction,0x10811788+1
	defadr DataBrowserBook_GetCurrentFoldersList,0x11810C38+1
	defadr OneOfMany_SetInfoTexts,0x11AA5EC0+1
	defadr GUIObject_SetZOrder,0x109DA888+1
	defadr socket_create,0x115113F8+1
	defadr socket_close,0x11511114+1
	defadr socket_connect,0x11511134+1
	defadr socket_send,0x11511320+1
	defadr socket_recv,0x1151124C+1
	defadr socket_setopt,0x115113A4+1
	defadr socket_getopt,0x115111DC+1
	defadr socket_getpeername,0x1151118C+1
	defadr socket_getsockname,0x115111B4+1
	defadr socket_shutdown,0x1151125C+1
	defadr socket_accept,0x11510460+1
	defadr socket_bind,0x115110EC+1
	defadr socket_listen,0x1151120C+1
	defadr socket_sendto,0x11511360+1
	defadr socket_recvfrom,0x11511264+1
	defadr fcntl,0x1151115C+1
	defadr select,0x115112F0+1
	defadr socket_lasterror,0x114223BC+1
	defadr REQUEST_OAF_START_APPLICATION_BY_ID,0x10B33C78+1
	defadr DispObj_Create,0x109D0310+1
	defadr DispObj_Destroy,0x109D03E8+1
	defadr DispObject_SetTitleType,0x109CFC10+1
	defadr DispObject_SetStyle,0x109D3664+1
	defadr SetHorizontalViewVideo,0x10E1B1E0+1
	defadr SetVerticalViewVideo,0x10E1B1B4+1
	defadr FlightModeControl,0x11A7FD34+1
	defadr isFlightMode,0x11A7F508+1
	defadr SetOperatorName,0x10D96C18+1
	
	defadr MainInput_Hide,0x10D95528+1
	
	defadr CoCreateInstance,0x10723BF0+1
	defadr DisplayGC_AddRef,0x109D8A88+1

//------

	defadr GetTimerTime,	  _GetTimerTime
	defadr GetCurName,	  _GetCurName
	defadr GetOperatorName,   0x10FC82F0+1
	defadr FlightGetState,	  0x11A7F508+1
	
	defadr CallInfo_Get,	  0x11293C90+1
	defadr isTimerBook,	  0x10FAAD08+1

	defadr some,		  0x10E17720+1
	defadr armfunc, 	  0x106FCD54

	defadr Show,		  0x10D96CE0+1
	defadr Return_Clear,	  0x10D96CDA+1
	defadr Show_Clear,	  0x10D96D08+1

	defadr oldRedrawStatus,   0x11792744+1
	defadr oldRedrawDisplay,  0x10D9429C+1
	defadr oldRedrawSoft,	  0x10814320+1
	defadr oldCreateDisplay,  0x10D94230+1
	defadr oldCloseDisplay,   0x10D94288+1
	defadr oldOnKeyMainInput, 0x10D91F80+1

	defadr retSetIcon,	  0x117A1F94+1

	EXTERN	onRedrawStatus
	EXTERN	onRedrawDisplay
	EXTERN	onRedrawSoft
	EXTERN	onCreateDisplay
	EXTERN	onCloseDisplay
	EXTERN	myOnKey
	EXTERN	RunTimer
	EXTERN	KillTimer
	EXTERN	MySetTrayIcon

	RSEG  CODE
	CODE16

_GetCurName:
	PUSH	{R1-R7,LR}
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
	PUSH	{R0-R7,LR}
	LDR	R0, =isTimerBook
	LDR	R3, =FindBook
	BLX	R3
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
	LDR	R1, =0x3E8
	LDR	R3, =armfunc
	BLX	R3
	STRB	R1, [R4,#2]
	MOV	R0, #0
	STRB	R1, [R4,#3]
	POP    {R0-R7,PC}
	
	RSEG  CODE
	CODE16

CallClear:
	LDR	R0, =0x6FFFFFFF
	ADD	R5, R1, #0
	CMP	R1, R0
	BEQ	loc_45426AAA
	CMP	R2, #0
	BEQ	loc_452AE5A8
	LDR	R3, =Return_Clear
	BX	R3

loc_45426AAA:
	BL	KillTimer
	LDR	R3, =Show_Clear
	BX	R3

loc_452AE5A8:
	BL	RunTimer
	MOV	R0, SP
	LDR	R1, =0xF83C
	LDR	R3, =Show
	BX	R3

_mySetTrayIcon:
	PUSH	{R0,R1}
	LDR	R3, =MySetTrayIcon
	BLX	R3
	POP	{R0,R1}
	MOV	R2, #0
	MOV	R1, R0
	LDR	R0, =StatusRow_p
	LDR	R0, [R0,#0]
	LDR	R3, =retSetIcon
	BX	R3

_mySetTrayIcon_2:
	PUSH	{R0-R2}
	MOV	R1, R2
	LDR	R3, =MySetTrayIcon
	BLX	R3
	POP	{R0-R2}
	MOV	R2, #0
	MOV	R3, R1
	MOV	R1, R0
	LSL	R0, R3, #3
	LDR	R3, =StatusRow_p
	LDR	R0, [R3,R0]
	LDR	R3, =retSetIcon
	BX	R3
	
	RSEG	PATCH_DRAWSTATUS(2)
	DATA
	DCD	onRedrawStatus

	RSEG	PATCH_DRAWDISPLAY(2)
	DATA
	DCD	onRedrawDisplay

	RSEG	PATCH_DRAWSOFT(2)
	DATA
	DCD	onRedrawSoft

	RSEG	PATCH_CREATEDISPLAY(2)
	DATA
	DCD	onCreateDisplay

	RSEG	PATCH_CLOSEDISPLAY(2)
	DATA
	DCD	onCloseDisplay

	RSEG	PATCH_ONKEYMAININPUT(2)
	DATA
	DCD	myOnKey

	RSEG	PATCH_CALLOFF_CLEAR(2)
	CODE16
	LDR	R0, =CallClear
	BX	R0

	RSEG	PATCH_SET_TRAY_ICON(2)
	CODE16
	PUSH	{LR}
	LDR	R3, =_mySetTrayIcon
	BX	R3

	RSEG	PATCH_SET_TRAY_ICON_2(2)
	CODE16
	PUSH	{LR}
	LDR	R3, =_mySetTrayIcon_2
	BX	R3
	
#endif
	  END
	  