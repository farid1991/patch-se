#ifdef C902_R3EG004AO

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr memcpy,0x101478A0
        defadr sprintf,0x106DDF88+1
        defadr snwprintf,0x106DE444+1
        defadr _fopen,0x10938A30+1
        defadr fclose,0x11701088+1
        defadr fread,0x1093A3C4+1
        defadr fwrite,0x1093A590+1
        defadr fstat,0x10939394+1
        defadr AllocDirHandle,0x10936880+1
        defadr GetFname,0x10936A50+1
        defadr DataBrowserDesc_Create,0x117F2EF4+1
        defadr DataBrowserDesc_SetItemStyle,0x117F3174+1
        defadr DataBrowserDesc_SetHeaderText,0x117F31A4+1
        defadr DataBrowserDesc_SetFolders,0x117F318C+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x117F31AC+1
        defadr DataBrowser_Create,0x117EF13C+1
        defadr DataBrowserDesc_Destroy,0x117F2FA4+1
        defadr getFileExtention,0x1093C0A0+1
        defadr DataBrowser_isFileInListExt,0x10936CB4+1
        defadr Timer_ReSet,0x10DD0A3C+1
        defadr Timer_Set,0x10DD0A08+1
        defadr Timer_Kill,0x10DD0A94+1
        defadr CreateBook,0x10DD4428+1
        defadr BookObj_KillBook,0x10DD453C+1
        defadr BookObj_GotoPage,0x10DD4138+1
        defadr BookObj_ReturnPage,0x10DD42F0+1
        defadr FreeBook,0x10DD4AA8+1
        defadr FindBook,0x10DD2660+1
        defadr Find_StandbyBook,0x10D71878+1
        defadr BookObj_SetFocus,0x10DD46D8+1
        defadr GUIObject_SetTitleText,0x109B3274+1
        defadr GUIObject_Show,0x109B3060+1
        defadr ListMenu_SetCursorToItem,0x11A7EDE0+1
        defadr GUIObject_SetStyle,0x109B30B8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A7F9CC+1
        defadr GUIonMessage_SetMenuItemText,0x11A7F9D8+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A7FA08+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11A7F9E8+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A7F9F8+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A7FA18+1
        defadr DispObject_SetTitleText,0x109A83B4+1
        defadr ListMenu_GetSelectedItem,0x11A7EDF4+1
        defadr ListMenu_SetItemStyle,0x11A7EE44+1
        defadr isScreenSaverBook,0x108C9134+1
        defadr StatusIndication_SetItemText,0x10D70E1C+1
        defadr StatusIndication_ShowNotes,0x10D72A30+1
        defadr CreateStringInputVA,0x10878CDC+1
        defadr CreateOneOfMany,0x11A811D0+1
        defadr OneOfMany_SetItemCount,0x11A8135C+1
        defadr OneOfMany_SetChecked,0x11A81378+1
        defadr OneOfMany_SetTexts,0x11A813AC+1
        defadr OneOfMany_GetSelected,0x11A81388+1
        defadr StatusIndication_Item8_SetText,0x10D7293C+1
        defadr GUIObject_SoftKeys_SetAction,0x107F3094+1
        defadr GUIObject_SoftKeys_SetText,0x107F310C+1
        defadr GUIObject_SoftKeys_SetEnable,0x107F31FC+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x107F31B4+1
        defadr GUIObject_SoftKeys_RemoveItem,0x107F3048+1
        defadr GUIObject_SoftKeys_SetVisible,0x107F3190+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x107F3400+1
        defadr wstrcpy,0x10D4A3C8+1
        defadr wstrncpy,0x10D4A3E0+1
        defadr wstrcat,0x106DEB1C+1
        defadr wstrncat,0x10D4A428+1
        defadr wstrcmp,0x10D4A398+1
        defadr wstrlen,0x10D4A384+1
        defadr str2wstr,0x10D4B64C+1
        defadr strcmp,0x106DE210+1
        defadr strlen,0x106DE26C+1
        defadr wstr2strn,0x10D4A4A4+1
        defadr int2strID_int,0x10F45F3C+1
        defadr Str2ID_int,0x10F46110+1
        defadr StrID2Str,0x10F4681C+1
        defadr TextID2wstr,0x10F466A4+1
        defadr TextGetLength,0x10F46554+1
        defadr TextFree_int,0x10F4644C+1
        defadr AB_DEFAULTNBR_GET,0x10B46028+1
        defadr AB_READSTRING,0xEDA51BD1
        defadr AB_READPHONENBR,0x10B4C400+1
        defadr AB_GETNBROFITEMS,0x10B4C4B8+1
        defadr PNUM_len,0x10F45710+1
        defadr PNUM2str,0x10919A18+1
        defadr GUIObject_GetDispObject,0x109B2EF8+1
        defadr List_Create,0x11AC4F9C+1
        defadr List_Destroy,0x11AC4FC4+1
        defadr List_InsertFirst,0x11AC5110+1
        defadr Gif2ID,0x10788024+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10788254+1
        defadr REQUEST_DATEANDTIME_GET,0x10792248+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x10E48A08+1
        defadr GetFreeBytesOnHeap,0x4BB00700
        defadr BookObj_Hide,0x10DD4700+1
        defadr BookObj_Show,0x10DD4710+1
        defadr StartAPP,0x10D71A64+1
        defadr ListMenu_SetOnMessage,0x11A7EF18+1
        defadr manifest_GetParam,0x10AE6FAC+1
        defadr lseek,0x1093A738+1
        defadr get_VBUFFER,0x0
        defadr SetLampLevel,0x10005932+1
        defadr List_RemoveAt,0x11AC518C+1
        defadr GetCurrentPID,0x10005E60+1
        defadr List_IndexOf,0x11AC50D0+1
        defadr alloc,0x1017CAF0
        defadr receive,0x1017CB0C
        defadr send,0x1017CAFC
        defadr sender,0x1017CB4C
        defadr free_buf,0x1017CB1C
        defadr create_process,0x1017CBE8
        defadr start,0x1017CE08
        defadr get_ptype,0x1017CCB8
        defadr current_process,0x1017CC04
        defadr delay,0x1017CB3C
        defadr hunt,0x1017CD04
        defadr kill_proc,0x1017CD30
        defadr receive_w_tmo,0x1017CB68
        defadr stop,0x1017CE18
        defadr get_mem,0x1017CC84
        defadr get_envp,0x10005C40+1
        defadr set_envp,0x10005C54+1
        defadr get_bid,0x1017CC3C
        defadr datetime2unixtime,0x10BAECD4+1
        defadr strcpy,0x106DE238+1
        defadr CreateMessage,0x10DF3350+1
        defadr SendMessage,0x10DF33A4+1
        defadr WaitMessage,0x10DF342C+1
        defadr FreeMessage,0x10DF3440+1
        defadr SendDispatchMessage,0x10BBA79C+1
        defadr UIEventName,0x10DD0E24+1
        defadr MissedEvents,0x4BBA9F90
        defadr UI_Event,0x10DD31C8+1
        defadr UI_Event_wData,0x10DD31D8+1
        defadr UI_Event_toBookID,0x10DD3220+1
        defadr UI_Event_toBookIDwData,0x10DD3234+1
        defadr List_Find,0x11AC526C+1
        defadr List_Get,0x11AC51BC+1
        defadr wstrrchr,0x10D4B708+1
        defadr BookObj_CallSubroutine,0x10DD41C8+1
        defadr List_InsertLast,0x11AC5118+1
        defadr debug_printf,0x4BB3FD40+1
        defadr PlayFile,0x119E1140+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11A9C1E0+1
        defadr Profile_SetActive,0x11ACC0E0+1
        defadr SetBrightnessOfScreen,0x10DA5424+1
        defadr isKeylocked,0x108C8F38+1
        defadr IsMediaPlayerVideoBook,0x10DF7660+1
        defadr ShuttingDown,0x11A590C0+1
        defadr Vibra,0x119E04A8+1
        defadr REQUEST_DATEFORMAT_GET,0x10792428+1
        defadr REQUEST_TIMEFORMAT_GET,0x1079250C+1
        defadr Date2ID,0x11A59730+1
        defadr Time2ID,0x11A5964C+1
        defadr CreateListMenu,0x11A7EBF4+1
        defadr ListMenu_SetItemCount,0x11A7EE08+1
        defadr ROOT_APP,0x4BBB6510
        defadr GUIObject_SoftKeys_SetInfoText,0x107F30F8+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x107F3230+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11A5CD18+1
        defadr REQUEST_SYSTEM_RESTART,0x11A5CD28+1
        defadr GUIObject_SoftKeys_SetTexts,0x107F3164+1
        defadr IsRightNowBook,0x10B13DC8+1
        defadr IsVolumeControllerBook,0x11AB8518+1
        defadr CreateTabMenuBar,0x1177B3DC+1
        defadr TabMenuBar_SetTabCount,0x1177B634+1
        defadr TabMenuBar_SetTabGui,0x1177B4AC+1
        defadr TabMenuBar_SetTabIcon,0x1177B52C+1
        defadr GUIObject_Destroy,0x109B2E6C+1
        defadr GUIInput_SetIcon,0x109B3134+1
        defadr StringInput_GetStringAndLen,0x1087958C+1
        defadr GetAudioControlPtr,0x4BBD3A40
        defadr AudioControl_Vibrate,0x1154ACD0+1
        defadr GetVolumeSize,0x1093BDB8+1
        defadr CreateNOfMany,0x11A80BDC+1
        defadr NOfMany_SetTexts,0x11A80DE0+1
        defadr NOfMany_SetChecked,0x11A80D64+1
        defadr NOfMany_SetCursor,0x11A80D2C+1
        defadr NOfMany_GetCheckedCount,0x11A80D88+1
        defadr NOfMany_GetChecked,0x11A80D78+1
        defadr NOfMany_SetOnMessage,0x11A80DD8+1
        defadr AudioControl_Init,0x119E128C+1
        defadr OneOfMany_SetFocused,0x11A81340+1
        defadr OneOfMany_SetOnMessage,0x11A813A4+1
        defadr CreateMonitorFeedback,0x11A58314+1
        defadr Feedback_SetText,0x11A583CC+1
        defadr GetBatteryState,0x1106CA60+1
        defadr get_DisplayGC,0x109B0EBC+1
        defadr DispObject_GetRect,0x109A9AB4+1
        defadr GC_GetRect,0x109B1500+1
        defadr GC_GetXX,0x109B17FC+1
        defadr GC_SetXX,0x109B17F0+1
        defadr GC_ValidateRect,0x109B14B0+1
        defadr BookObj_AddGUIObject,0x10DD47B8+1
        defadr DrawRect,0x109ACC08+1
        defadr DrawString,0x109ACF54+1
        defadr XGUIList_AddGUIObject,0x10DD4CB8+1
        defadr DispObject_InvalidateRect,0x109A9844+1
        defadr GUIObject_Create,0x109B2CA8+1
        defadr SetFont,0x109ADB14+1
        defadr StatusRow_p,0x4BBD19C4
        defadr root_list_get_session_count,0x10DD2760+1
        defadr root_list_get_session,0x10DD2770+1
        defadr SESSION_GetTopBook,0x10DD1F40+1
        defadr MainInput_getVisible,0xEDA51BD1
        defadr MainInput_strlen,0x10D71378+1
        defadr MainInput_getPNUM,0x10D713A8+1
        defadr MainInput_isPlus,0xEDA51BD1
        defadr BookObj_GetBookID,0x10DD4B94+1
        defadr wstrncmp,0x106DEBF0+1
        defadr DispObject_GetAbsoluteXPos,0x109AACB8+1
        defadr DispObject_GetAbsoluteYPos,0x109AACEC+1
        defadr DispObject_GetWindow,0x109A9DC8+1
        defadr GetThemeColor,0x10E430FC+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11A9BC14+1
        defadr REQUEST_SETTING_SILENCE_GET,0x11A9BBBC+1
        defadr VCALL_Init,0x10B3A268+1
        defadr VCALL_SetName,0x10B3A360+1
        defadr VCALL_SetNameIcon,0x10B3A3C0+1
        defadr VCALL_SetNumber,0x10B3A380+1
        defadr VCALL_SetHZ1,0x10B3A3A4+1
        defadr VCALL_SetHZ2,0x10B3A3B0+1
        defadr MakeVoiceCall,0x10B39E00+1
        defadr FileDelete,0x10939624+1
        defadr GUIObject_SetFocus,0x109B3024+1
        defadr MSG_SendMessage_CreateMessage,0x11A0F400+1
        defadr MSG_SendMessage_DestroyMessage,0x11A0FB44+1
        defadr MSG_SendMessage_AddRecipient,0x11A0F5E0+1
        defadr MSG_SendMessage_Start,0x11A0FA6C+1
        defadr get_APP_DESC_TABLE,0x11B7D43C
        defadr Window_GetComponentInterface,0x109B0868+1
        defadr AB_POSITIONNBR_GET,0x10B4C6A4+1
        defadr AB_NAME_ITEM2TextID,0x10B4C5B8+1
        defadr AB_NUM_ITEM2TextID,0x10B4C61C+1
        defadr GetABRecNum,0x10B4C6A0+1
        defadr get_AB_ITEMS_DESC,0x11B65FD8
        defadr SBY_GetMainInput,0x1088A15C+1
        defadr SBY_GetStatusIndication,0x1074F408+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10A31408+1
        defadr PID_MMI,0x4BBB49E8
        defadr DispObject_GetGUI,0x109A9128+1
        defadr Display_GetFocusedDispObject,0x109A9074+1
        defadr DispObject_GetVisible,0x109A96E8+1
        defadr DispObject_GetDESC,0x10014EA0+1
        defadr DISP_DESC_SetName,0x109A62F4+1
        defadr DispObject_GetName,0x109AAA10+1
        defadr DISP_DESC_SetSize,0x109A62F8+1
        defadr DISP_DESC_SetOnCreate,0x109A62FC+1
        defadr DispObject_GetOnCreate,0x109A6378+1
        defadr DISP_DESC_SetOnClose,0x109A6300+1
        defadr DispObject_GetOnClose,0x109A6394+1
        defadr DISP_DESC_SetOnRedraw,0x109A6304+1
        defadr DispObject_GetOnRedraw,0x109A63B0+1
        defadr DISP_DESC_SetOnKey,0x109A630C+1
        defadr DispObject_GetOnKey,0x109A63E8+1
        defadr DISP_DESC_SetOnRefresh,0x109A6308+1
        defadr DispObject_GetonRefresh,0x109A63CC+1
        defadr DISP_DESC_SetMethod06,0x109A6310+1
        defadr DispObject_GetMethod06,0x109A6404+1
        defadr DISP_DESC_SetOnLayout,0x109A6318+1
        defadr DispObject_GetOnLayout,0x109A643C+1
        defadr DISP_DESC_SetOnConfig,0x109A631C+1
        defadr DispObject_GetOnConfig,0x109A6458+1
        defadr DISP_DESC_SetMethod0A,0x109A6320+1
        defadr DispObject_GetMethod0A,0x109A6474+1
        defadr DISP_DESC_SetMethod0B,0x109A6324+1
        defadr DispObject_GetMethod0B,0x109A6490+1
        defadr DISP_DESC_SetMethod0C,0x109A6328+1
        defadr JavaSession_Manager,0x10B5D470+1
        defadr JavaSession_GetName,0x108BF440+1
        defadr TextCopyId,0x10F462F0+1
        defadr BookObj_GetSession,0x10DD4AF4+1
        defadr GUIonMessage_SetNumberOfSubItems,0x11A7FA74+1
        defadr GUIonMessage_SubItem_SetText,0x11A7FAE0+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x11A7FAD4+1
        defadr GoMusic,0x10E0ABAC+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x11A7FAB0+1
        defadr GUIonMessage_SubItem_SetDisabled,0x11A7FB48+1
        defadr PlayFileV,0x119E1144+1
        defadr GetSilent,0x119DF5FC+1
        defadr GetVibrator,0x119DB3E8+1
        defadr GetAudioSettings,0x119E0918+1
        defadr GetChipID,0xEDA51BD1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x11A7FAC8+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x11A7FABC+1
        defadr DestroyDirHandle,0x10936BCC+1
        defadr LastExtDB,0x11F24BD8
        defadr GetOtherExtMethods,0x117E9054+1
        defadr MessageBox,0x11A568D0+1
        defadr Display_GetHeight,0x1177DA38+1
        defadr Display_GetWidth,0x1177DA44+1
        defadr PlaySystemSound,0x119E10E8+1
        defadr TabMenuBar_GetFocusedTab,0x1177B4A0+1
        defadr TabMenuBar_SetFocusedTab,0x1177B490+1
        defadr GC_GetPenColor,0x109B1708+1
        defadr GC_SetPenColor,0x109B16CC+1
        defadr GC_SetPixel,0x109B1350+1
        defadr GC_DrawLine,0x109B1E4C+1
        defadr GC_DrawFRect,0x109B1FD8+1
        defadr GC_WritePixels,0x109B13D8+1
        defadr png_create_read_struct_2,0x1182796C+1
        defadr png_destroy_read_struct,0x11827AB8+1
        defadr png_create_info_struct,0x11826114+1
        defadr png_destroy_info_struct,0x11826148+1
        defadr png_set_progressive_read_fn,0x11827944+1
        defadr png_process_data,0x11826904+1
        defadr png_read_update_info,0x11827A8C+1
        defadr png_get_progressive_ptr,0x11827968+1
        defadr png_get_IHDR,0x118265D0+1
        defadr png_set_strip_16,0x11827C58+1
        defadr png_set_gray_1_2_4_to_8,0x11827C64+1
        defadr png_set_gray_to_rgb,0x11827C88+1
        defadr png_get_valid,0x118265A4+1
        defadr png_set_tRNS_to_alpha,0x11827C7C+1
        defadr png_set_filler,0x1182A9EC+1
        defadr png_set_palette_to_rgb,0x11827C70+1
        defadr png_get_rowbytes,0x118265BC+1
        defadr png_progressive_combine_row,0x11827924+1
        defadr png_sig_cmp,0x1182600C+1
        defadr setjmp,0x1014BB3C
        defadr longjmp,0x1014BB60
        defadr inflateInit2_,0x1182B6C0+1
        defadr inflate,0x1182B868+1
        defadr inflateEnd,0x1182CB60+1
        defadr memcmp,0x12690564
        defadr strncmp,0x106DE2B0+1
        defadr strncpy,0x106DE2E4+1
        defadr strcat,0x106DE1D8+1
        defadr GUIObject_SetTitleType,0x109B3258+1
        defadr GUIonMessage_SetItemDisabled,0x11A7FA80+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107882CC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10788354+1
        defadr get_Surfaces,0x4BD9069C
        defadr iconidname2id,0x11516324+1
        defadr textidname2id,0x11700570+1
        defadr ListMenu_SetNoItemText,0x11A7EF98+1
        defadr IsFmRadioBook,0x10F8BC6C+1
        defadr IsAudioPlayerBook,0x10C68CD0+1
        defadr PlayerControl,0x10C686E4+1
        defadr SwitchRadioStationFromList,0x10F89B40+1
        defadr Shortcut_Run,0x10DC09A8+1
        defadr mkdir,0x10935FAC+1
        defadr rmdir,0x109363A0+1
        defadr chmod,0x10939550+1
        defadr rename,0x10939B78+1
        defadr CallID_GetCallStatusDesc,0x10DE5184+1
        defadr CallStatusDesc_GetName,0x10DE47BC+1
        defadr List_DestroyElements,0x11AC52B0+1
        defadr strstr,0x106DE380+1
        defadr GPRS_GetLastSessionInfo,0x107E574C+1
        defadr wstrcmpni,0x10D4B7A4+1
        defadr wtoi,0x10DD0468+1
        defadr DATE_GetWeekDay,0x10BAEFD0+1
        defadr Cale_GetSettings,0x10905E1C+1
        defadr wstrwstr,0x106DED50+1
        defadr wstrcmpi,0x10D4B7E8+1
        defadr wstrchr,0x106DEB38+1
        defadr GUIObject_SoftKeys_Hide,0x107F344C+1
        defadr GUIObject_SoftKeys_Show,0x107F3458+1
        defadr DispObject_SoftKeys_Get,0x107EF824+1
        defadr StandbyBackground_SetImage,0x10E41970+1
        defadr CreateYesNoQuestionVA,0x1177D2EC+1
        defadr ListMenu_SetItemSecondLineText,0x11A7F1BC+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10B0CA44+1
        defadr FSX_GetInvalidChar,0x1093BBA8+1
        defadr DataBrowserDesc_SetFoldersNumber,0x117F3194+1
        defadr DataBrowserDesc_SetActions,0x117F3148+1
        defadr DataBrowserDesc_SetSelectAction,0x117F3110+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x117F3118+1
        defadr DataBrowserDesc_SetBookID,0x117F30F4+1
        defadr DataBrowserDesc_SetItemFilter,0x117F3098+1
        defadr DataBrowserDesc_SetOption,0x117F31C4+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x117F322C+1
        defadr DataBrowserDesc_SetFileExtList,0x117F30A0+1
        defadr FSX_RemoveIllegalSymbolsName,0x117FC908+1
        defadr FILEITEM_Create,0x117FC320+1
        defadr FILEITEM_Destroy,0x117FC450+1
        defadr CreateDateInputVA,0x1177B768+1
        defadr CreateTimeInputVA,0x1177CEC4+1
        defadr StringInput_SetCursorPosition,0x108795D8+1
        defadr BookObj_CallPage,0x10DD426C+1
        defadr DateInput_GetDateInt,0x1177B9D8+1
        defadr TimeInput_GetTimeInt,0x1177D18C+1
        defadr GetFontDesc,0x4BBAE06C
        defadr GetFontCount,0x4BBAE3DC
        defadr GC_GetBrushColor,0x109B17E4+1
        defadr GC_SetBrushColor,0x109B17A4+1
        defadr GC_DrawRoundRect,0x109B2020+1
        defadr MenuBook_Desktop,0x10DC015C+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10DBF490+1
        defadr BookObj_SoftKeys_SetAction,0x107ED6E4+1
        defadr BookObj_SoftKeys_SetText,0x107ED71C+1
        defadr FindBookByID,0x10DD262C+1
        defadr TextFeedbackWindow,0x1177C728+1
        defadr Feedback_SetKeyHook,0x1177CB34+1
        defadr Feedback_SetOnClose,0x1177CAD0+1
        defadr Feedback_SetTimeout,0x1177CB00+1
        defadr Feedback_SetTextExtended,0x1177CB98+1
        defadr TabMenuBar_SetOnTabSwitch,0x1177B588+1
        defadr KeyCode2Name,0x10F90A98+1
        defadr ImageID_Get,0x107861D4+1
        defadr ImageID_Free,0x1078C3F4+1
        defadr DataBrowser_CreateSubExecute,0x117DBE5C+1
        defadr DataBrowser_ExecuteSubroutine,0x117DC87C+1
        defadr FILEITEM_SetFname,0x117FC4FC+1
        defadr FILEITEM_SetPath,0x117FC7BC+1
        defadr FILEITEM_GetFname,0x117FC7B4+1
        defadr FILEITEM_GetPath,0x117FC848+1
        defadr FILEITEM_SetFnameAndContentType,0x117FC55C+1
        defadr FILEITEM_SetPathAndContentType,0x117FC820+1
        defadr JavaDialog_Open,0x10AF4F3C+1
        defadr JavaDialog_Close,0x10AF8690+1
        defadr JavaAppDesc_Get,0x10AF885C+1
        defadr JavaAppDesc_GetFirstApp,0x10AEA8D0+1
        defadr JavaAppDesc_GetNextApp,0x10AEA8D8+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10AEA39C+1
        defadr OrangeLED_Control,0xEDA51BD1
        defadr DispObject_SetRefreshTimer,0x109A92AC+1
        defadr DispObject_KillRefreshTimer,0x109A9328+1
        defadr IsDataBrowserBook,0x117EFA4C+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x117EB0E4+1
        defadr Shortcut_Get_MenuItemName,0x10B15920+1
        defadr Shortcut_Get_MenuItemIconID,0x10DC0380+1
        defadr FindBookEx,0x10DD26C0+1
        defadr FILEITEM_CreateCopy,0x117FC350+1
        defadr ImageID_Copy,0x1078C3B0+1
        defadr BookObj_GetSessionID,0x10DD4A1C+1
        defadr UI_Event_toSID,0x10DD31EC+1
        defadr GetIMSI,0xEDA51BD1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11A58DA4+1
        defadr MainInput_getCurPos,0xEDA51BD1
        defadr MainInput_Hide,0x10D712C4+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x107EF204+1
        defadr PNUM2Name,0x10B35498+1
        defadr SpeedDial_GetPNUM,0x10B5C9C8+1
        defadr MetaData_Desc_Create,0xEDA51BD1
        defadr MetaData_Desc_Destroy,0xEDA51BD1
        defadr MetaData_Desc_GetTags,0xEDA51BD1
        defadr MetaData_Desc_GetTrackNum,0xEDA51BD1
        defadr DispObject_GetWindowWidth,0x109AAC38+1
        defadr DispObject_GetWindowHeight,0x109AAC58+1
        defadr get_system_langID,0x10D9C5B8+1
        defadr lang_get_name,0x11A87F40+1
        defadr w_chdir,0x4BB003AC
        defadr w_fopen,0x11293FE4+1
        defadr w_fstat,0x1129409C+1
        defadr w_fwrite,0x1129402C+1
        defadr w_fread,0x11294014+1
        defadr w_lseek,0x11A516C8+1
        defadr w_fclose,0x11294044+1
        defadr w_mkdir,0x4BB00344
        defadr DirHandle_SetFilterStr,0x10936C24+1
        defadr Disp_GetTextIDWidth,0x109AE2A0+1
        defadr MetaData_Desc_GetCoverInfo,0xEDA51BD1
        defadr ImageID_GetIndirect,0x1078626C+1
        defadr unixtime2datetime,0x10BAEDE8+1
        defadr List_Insert,0x11AC4FEC+1
        defadr FileCopy,0x1093992C+1
        defadr FileMove,0x10939B78+1
        defadr RedLED_On,0xEDA51BD1
        defadr RedLED_Off,0xEDA51BD1
        defadr DispObject_SetLayerColor,0x109ABA3C+1
        defadr JavaAppDesc_GetJavaAppID,0x10AF87B8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10C1D678+1
        defadr JavaApp_LogoImageID_Get,0x10C11EA8+1
        defadr CreateProgressBar,0x1177BE9C+1
        defadr ProgressBar_SetText,0x1177C194+1
        defadr ProgressBar_SetIcon,0x1177C308+1
        defadr ProgressBar_SetPercentValue,0x1177C150+1
        defadr ProgressBar_SetBarDisabled,0x1177C328+1
        defadr StringInput_DispObject_SetText,0x1086DE6C+1
        defadr GUIObject_SetTitleBackgroundImage,0xEDA51BD1
        defadr GUIObject_SetTitleIcon,0x109B32AC+1
        defadr GUIObject_SetCursorImage,0xEDA51BD1
        defadr GUIObject_SetBackgroundImage,0xEDA51BD1
        defadr DispObject_SoftKeys_GetParams,0x107F04D4+1
        defadr DispObject_SoftKeys_GetList,0x107F0518+1
        defadr BookObj_GetDisplayOrientation,0x10DD4C30+1
        defadr BookObj_SetDisplayOrientation,0x10DD4BCC+1
        defadr Display_GetTopBook,0x10DD3F0C+1
        defadr Display_SetBrightness,0xEDA51BD1
        defadr Display_GetBrightness,0x10DA52D0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x117F30FC+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x117F3158+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x117F3160+1
        defadr SetTheme,0x10DF0F10+1
        defadr SoftKeys_GetLabel,0x107F2A00+1
        defadr SoftKeys_Update,0x107F25B8+1
        defadr get_CellData,0x108CC964+1
        defadr IncommingCall_Reject,0x10DEE3C4+1
        defadr IncommingCall_Mute,0x10DEF704+1
        defadr GetRadioState,0xEDA51BD1
        defadr Bluetooth_GetState,0x10A452C8+1
        defadr Bluetooth_GetPhoneVisibility,0x10A4528C+1
        defadr Bluetooth_isBusy,0x10A45358+1
        defadr USB_isConnected,0x1099CEEC+1
        defadr w_diropen,0x4BB00354
        defadr w_dirread,0x11A51D58+1
        defadr w_dirclose,0x4BB0038C
        defadr w_rename,0x11A51DF4+1
        defadr w_remove,0x11A51DA8+1
        defadr ConnectionManager_Connection_GetState,0xEDA51BD1
        defadr IsCameraBook,0x108A6578+1
        defadr IsSoundRecorderBook,0x10E2F2E8+1
        defadr StringInput_MenuItem_SetPriority,0x108796E0+1
        defadr Video_ActionBack,0x10DF6FFC+1
        defadr Video_ExtractFrame,0x10DF7904+1
        defadr Video_ZoomOn,0x10DF6FCC+1
        defadr RightNow_SetActive,0x10B143FC+1
        defadr Video_Play,0x10DF6F04+1
        defadr Video_Pause,0x10DF6F14+1
        defadr Audio_Pause,0x10C6A6E8+1
        defadr Audio_Play,0x10C6A68C+1
        defadr CreatePercentInputVA,0x1177BB08+1
        defadr PercentInput_GetPercent,0x1177BC94+1
        defadr GUIonMessage_SetLineSeparator,0x11A7FA98+1
        defadr PHF_GetState,0x109F9B70+1
        defadr CHF_GetState,0x109F9B78+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x107F3464+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x107F3470+1
        defadr SetTrayIcon,0x11780008+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11A9B8BC+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x11A9BAB0+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x11A9BA2C+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11A9BE94+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x11A9B9C4+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x11A9BCBC+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10AE997C+1
        defadr SoundRecorderDesc_Create,0x10E2E794+1
        defadr SoundRecorderDesc_Destroy,0x10E2E7F0+1
        defadr SoundRecorderDesc_SetBookID,0x10E2E80C+1
        defadr SoundRecorderDesc_SetType,0x10E2E838+1
        defadr SoundRecorderDesc_SetFolder,0x10E2E84C+1
        defadr SoundRecorderDesc_SetFname,0x10E2E868+1
        defadr SoundRecorderDesc_SetRecordSize,0x10E2E884+1
        defadr SoundRecorder_Create,0x10E2E8FC+1
        defadr SoundRecorder_RecordCall,0x10DE16F0+1
        defadr Browser_OpenURI,0x107627AC+1
        defadr GetURIScheme,0x10DF4AD0+1
        defadr CreateURI,0x10DF4F6C+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x117F317C+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x1078ECAC+1
        defadr Alarm_GetState,0x1078D4DC+1
        defadr Alarm_GetTIME,0x1078E4B8+1
        defadr Alarm_GetWeekSettings,0x1078F3F0+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11A9BC60+1
        defadr IncommingCall_Accept,0x10DEE288+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AD47E8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AD47A0+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AD4848+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x10AD4878+1
        defadr DispObject_Show,0x109A9564+1
        defadr Request_EventChannel_Subscribe,0x126D4EF4+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x107F342C+1
        defadr Request_ICA_ShutdownAllConnections,0x11493EF0+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11A9C328+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x117F3234+1
        defadr GUIonMessage_GetMsg,0x11A7F9A8+1
        defadr GUIonMessage_GetBook,0x11A7F9B0+1
        defadr GUIonMessage_GetGui,0x11A7F9AC+1
        defadr GUIonMessage_GetSelectedItem,0x11A7F9B4+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11A7F9C0+1
        defadr ObexSendFile,0x108852F8+1
        defadr Feedback_SetManualScrollingText,0x117774D4+1
        defadr EqualizerGain_Set,0x119DE220+1
        defadr CANVAS_Get_GviGC,0x113D286C+1
        defadr GVI_BitBlt,0x1112BC3C+1
        defadr GVI_StretchBlt,0x1112BDB0+1
        defadr GVI_TransformBlt,0x1112BE6C+1
        defadr GVI_CreatePen,0x1112AEE4+1
        defadr GVI_CreateDashedPen,0x1112AF28+1
        defadr GVI_CreateSolidBrush,0x1112ADF4+1
        defadr GVI_Delete_GVI_Object,0x1112A7C4+1
        defadr GVI_DrawEllipse,0x1112B574+1
        defadr GVI_DrawLine,0x1112C460+1
        defadr GVI_DrawLines,0x1112CAF0+1
        defadr GVI_DrawPolyLine,0x1112CB74+1
        defadr GVI_DrawRectangle,0x1112CDF0+1
        defadr GVI_DrawRoundRect,0x1112BA90+1
        defadr GVI_DrawSolidLines,0x1112C6B4+1
        defadr GVI_DrawSolidPolyLine,0x1112C8BC+1
        defadr GVI_DrawSolidRectangle,0x1112C960+1
        defadr GVI_FillEllipse,0x1112B95C+1
        defadr GVI_FillPolygon,0x1112C318+1
        defadr GVI_FillRectangle,0x1112CC70+1
        defadr GVI_FillRectangles,0x1112CCFC+1
        defadr GVI_FillSolidEllipse,0x1112BA08+1
        defadr GVI_FillSolidRectangle,0x1112CD78+1
        defadr GVI_FillSolidRoundRect,0x1112BBE0+1
        defadr GVI_FillSolidTriangle,0x1112C2A4+1
        defadr GC_CreateMemoryGC,0x109B0ECC+1
        defadr GC_FreeGC,0x109B0F94+1
        defadr Settings_ShowNumber_Get,0x10FA7628+1
        defadr GVI_CreateBitmap,0x1112AFE0+1
        defadr GVI_CreateMemoryGC,0x1112CF54+1
        defadr GVI_DeleteMemoryGC,0x1115ABD4+1
        defadr StringInput_DispObject_SetLanguage,0x108725A0+1
        defadr List_InsertSorted,0x11AC5134+1
        defadr ListMenu_SetItemIcon,0x11A7F0F0+1
        defadr wstrnupr,0x10D4A454+1
        defadr wstrnlwr,0x10AB2EFC+1
        defadr ListMenu_SetItemTextScroll,0x11A7F4E8+1
        defadr GUIObject_SetTitleTextColor,0xEDA51BD1
        defadr GUIObject_SetListTextColor,0x11A805C8+1
        defadr DispObject_SetTitleTextColor,0x109A8648+1
        defadr DispObject_SetListTextColor,0x11A72050+1
        defadr DispObject_SetCursorImage,0x11A7200C+1
        defadr DispObject_SetBackgroundImage,0x11A72028+1
        defadr DispObject_SetTitleBackgroundImage,0x109A8660+1
        defadr TabMenuBar_SetTabTitle,0x1177B574+1
        defadr GUIObject_GetBook,0x109B2F0C+1
        defadr SoftKeys_GetSelectedAction,0x107EF134+1
        defadr MonitorFeedback_SetTimer,0x11A583C0+1
        defadr void,0x11A80C55
        defadr ListMenu_DestroyItems,0x11A7F260+1
        defadr DispObject_SetScrollBarBackgroundColor,0x109AAF38+1
        defadr DispObject_SetScrollBarColor,0x109AAF10+1
        defadr DispObject_SetSoftkeysColor,0x107EF6A0+1
        defadr YesNoQuestion_SetIcon,0x1177D570+1
        defadr GUIObject_SetBacklightTimeout,0x109B31B4+1
        defadr ListMenu_SetHotkeyMode,0x11A7EF44+1
        defadr ListMenu_SetSearchLanguageMode,0x11A7F3C0+1
        defadr ListMenu_EnableSearchHeader,0x11A7F3E8+1
        defadr GUIonMessage_GetSearchString,0x11A7FBB0+1
        defadr GUIonMessage_GetSearchStringLength,0x11A7FBD0+1
        defadr EqualizerGain_Get,0x119DE1F8+1
        defadr Theme_DestroyMenuIcons,0x10DBE548+1
        defadr CoCreateInstance,0x10701890+1
        defadr GUIObject_SetSecondRowTitleText,0x109B3290+1
        defadr ListMenu_GetItemCount,0x11A7EE1C+1
        defadr OSE_GetShell,0x10DF3284+1
        defadr swscanf,0x106DE478+1
        defadr sscanf,0x10003C84+1
        defadr BookObj_WindowSetWantsFocus,0x10DD4734+1
        defadr BookObj_StayOnTop,0x10DD4BA4+1
        defadr DispObject_WindowSetPosition,0x109AABC0+1
        defadr DispObject_WindowSetSize,0x109AAB2C+1
        defadr Feedback_DispObject_GetText,0x11777DAC+1
        defadr DispObject_SoftKeys_ExecuteAction,0x107EF438+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x117EF048+1
        defadr DispObject_SetAnimation,0x109ABAF4+1
        defadr GUIObject_SetZOrder,0x109B30F4+1
        defadr StringInput_GetCursorPosition,0x108795F0+1
        defadr str2PNUM,0x10919AC8+1
        defadr pb_ui_search_bk_create_search_menu,0x10B57AB0+1
        defadr ThemeImage_Delete,0x10E41C34+1
        defadr GUIObject_SoftKeys_AllowPerformAction,0x107F3278+1
        defadr socket_create,0x114EFBDC+1
        defadr socket_close,0x114EF8F8+1
        defadr socket_connect,0x114EF918+1
        defadr socket_send,0x114EFB04+1
        defadr socket_recv,0x114EFA30+1
        defadr socket_setopt,0x114EFB88+1
        defadr socket_getopt,0x114EF9C0+1
        defadr socket_getpeername,0x114EF970+1
        defadr socket_getsockname,0x114EF998+1
        defadr socket_shutdown,0x114EFBB8+1
        defadr socket_accept,0x114EEC44+1
        defadr socket_bind,0x114EF8D0+1
        defadr socket_listen,0x114EF9F0+1
        defadr socket_sendto,0x114EFB44+1
        defadr socket_recvfrom,0x114EFA48+1
        defadr fcntl,0x114EF940+1
        defadr select,0x114EFAD4+1
        defadr socket_lasterror,0x11400BB8+1
        defadr REQUEST_OAF_START_APPLICATION_BY_ID,0x10B0CB0C+1
        defadr DispObj_Create,0x109A8B7C+1
        defadr DispObj_Destroy,0x109A8C54+1
        defadr DispObject_SetTitleType,0x109A847C+1
        defadr DispObject_SetStyle,0x109ABED0+1
        defadr SetHorizontalViewVideo,0x10DF6F60+1
        defadr SetVerticalViewVideo,0x10DF6F34+1
        defadr FlightModeControl,0x11A5B24C+1
        defadr isFlightMode,0x11A5AA20+1
        defadr SetOperatorName,0x10D729B8+1       		
		defadr DisplayGC_AddRef,0x109B12F4+1
        defadr Disp_GetStrIdHeight,0x109AE200+1        
        defadr Disp_GetStrIdWidth,0x109AE2A0+1       
        defadr ListMenu_SetSecondLineText,0x11A7F1BC+1      
        

//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x10FA484C+1
        defadr FlightGetState,    0x11A5AA20+1
        
        defadr CallInfo_Get,      0x11272310+1
        defadr isTimerBook,       0x10F8725C+1

        defadr some,              0x10DF34A0+1
        defadr armfunc,           0x106DAADC

        defadr Show,              0x10D72A80+1
        defadr Return_Clear,      0x10D72A7A+1
        defadr Show_Clear,        0x10D72AA8+1

        defadr oldRedrawStatus,   0x117707D0+1
        defadr oldRedrawDisplay,  0x10D70038+1
        defadr oldRedrawSoft,     0x107F1FD0+1
        defadr oldCreateDisplay,  0x10D6FFCC+1
        defadr oldCloseDisplay,   0x10D70024+1
        defadr oldOnKeyMainInput, 0x10D6DD1C+1

        defadr retSetIcon,        0x11780020+1

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
          