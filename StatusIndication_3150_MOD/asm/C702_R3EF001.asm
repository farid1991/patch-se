#ifdef C702_R3EF001

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM


        defadr memalloc,0x2AF004F8
        defadr memfree,0x2AF00520
        defadr memset,0x2AF01020
        defadr memcpy,0x101478A4
        defadr sprintf,0x1076F12C+1
        defadr snwprintf,0x1076F5E0+1
        defadr _fopen,0x109C7E28+1
        defadr fclose,0x1177B338+1
        defadr fread,0x109C97BC+1
        defadr fwrite,0x109C9988+1
        defadr fstat,0x109C878C+1
        defadr AllocDirHandle,0x109C5C78+1
        defadr GetFname,0x109C5E48+1
        defadr DataBrowserDesc_Create,0x1186CF70+1
        defadr DataBrowserDesc_SetStyle,0x1186D1F0+1
        defadr DataBrowserDesc_SetHeaderText,0x1186D220+1
        defadr DataBrowserDesc_SetFolders,0x1186D208+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x1186D228+1
        defadr DataBrowser_Create,0x118691B8+1
        defadr DataBrowserDesc_Destroy,0x1186D020+1
        defadr getFileExtention,0x109CB498+1
        defadr DataBrowser_isFileInListExt,0x109C60AC+1
        defadr Timer_ReSet,0x10E5DAD8+1
        defadr Timer_Set,0x10E5DAA4+1
        defadr Timer_Kill,0x10E5DB30+1
        defadr CreateBook,0x10E614C4+1
        defadr BookObj_KillBook,0x10E615D8+1
        defadr BookObj_GotoPage,0x10E611D4+1
        defadr BookObj_ReturnPage,0x10E6138C+1
        defadr FreeBook,0x10E61B44+1
        defadr FindBook,0x10E5F6FC+1
        defadr Find_StandbyBook,0x10DFE918+1
        defadr BookObj_SetFocus,0x10E61774+1
        defadr GUIObject_SetTitleText,0x10A41148+1
        defadr GUIObject_Show,0x10A40F34+1
        defadr ListMenu_SetCursorToItem,0x11AF6D1C+1
        defadr GUIObject_SetStyle,0x10A40F8C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11AF7908+1
        defadr GUIonMessage_SetMenuItemText,0x11AF7914+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11AF7944+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11AF7924+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11AF7934+1
        defadr GUIonMessage_SetMenuItemIcon,0x11AF7954+1
        defadr DispObject_SetTitleText,0x10A36288+1
        defadr ListMenu_GetSelectedItem,0x11AF6D30+1
        defadr ListMenu_SetItemStyle,0x11AF6D80+1
        defadr isScreenSaverBook,0x1095852D
        defadr StatusIndication_SetItemText,0x10DFDEBC+1
        defadr StatusIndication_ShowNotes,0x10DFFAD0+1
        defadr CreateStringInputVA,0x10908604+1
        defadr CreateOneOfMany,0x11AF910C+1
        defadr OneOfMany_SetItemCount,0x11AF9298+1
        defadr OneOfMany_SetChecked,0x11AF92B4+1
        defadr OneOfMany_SetTexts,0x11AF92E8+1
        defadr OneOfMany_GetSelected,0x11AF92C4+1
        defadr StatusIndication_Item8_SetText,0x10DFF9DC+1
        defadr GUIObject_SoftKeys_SetAction,0x10882D10+1
        defadr GUIObject_SoftKeys_SetText,0x10882D88+1
        defadr GUIObject_SoftKeys_SetEnable,0x10882E78+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x10882E30+1
        defadr GUIObject_SoftKeys_RemoveItem,0x10882CC4+1
        defadr GUIObject_SoftKeys_SetVisible,0x10882E0C+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x1088307C+1
        defadr wstrcpy,0x10DD7478+1
        defadr wstrncpy,0x10DD7490+1
        defadr wstrcat,0x10DD74BC+1
        defadr wstrncat,0x1076FD60+1
        defadr wstrcmp,0x10DD7448+1
        defadr wstrlen,0x10DD7434+1
        defadr str2wstr,0x10DD86FC+1
        defadr strcmp,0x1076F3B4+1
        defadr strlen,0x1076F410+1
        defadr wstr2strn,0x10DD7554+1
        defadr StrID2Str,0x10FD4E64+1
        defadr AB_DEFAULTNBR_GET,0x10BD367C+1
        defadr AB_READPHONENBR,0x10BD9A54+1
        defadr AB_GETNBROFITEMS,0x10BD9B0C+1
        defadr PNUM_len,0x10FD3D58+1
        defadr PNUM2str,0x109A8E10+1
        defadr GUIObject_GetDispObject,0x10A40DCC+1
        defadr List_Create,0x11B3CED0+1
        defadr List_Destroy,0x11B3CEF8+1
        defadr List_InsertFirst,0x11B3D044+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10817ED0+1
        defadr REQUEST_DATEANDTIME_GET,0x10821EC4+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x10ED7D8C+1
        defadr GetFreeBytesOnHeap,0x2AF00664
        defadr BookObj_Hide,0x10E6179C+1
        defadr BookObj_Show,0x10E617AC+1
        defadr StartAPP,0x10DFEB04+1
        defadr ListMenu_SetOnMessage,0x11AF6E54+1
        defadr manifest_GetParam,0x10B74664+1
        defadr lseek,0x109C9B30+1
        defadr get_VBUFFER,0x10007F21
        defadr SetLampLevel,0x10BA714C+1
        defadr List_RemoveAt,0x11B3D0C0+1
        defadr GetCurrentPID,0x10005E64+1
        defadr List_IndexOf,0x11B3D004+1
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
        defadr strcpy,0x1076F3DC+1
        defadr CreateMessage,0x10E803FC+1
        defadr SendMessage,0x10E80450+1
        defadr WaitMessage,0x10E804D8+1
        defadr FreeMessage,0x10E804EC+1
        defadr SendDispatchMessage,0x10C47C1C+1
        defadr UIEventName,0x10E5DEC0+1
        defadr MissedEvents,0x2AF9DBCC
        defadr UI_Event,0x10E60264+1
        defadr UI_Event_wData,0x10E60274+1
        defadr UI_Event_toBookID,0x10E602BC+1
        defadr UI_Event_toBookIDwData,0x10E602D0+1
        defadr List_Find,0x11B3D1A0+1
        defadr List_Get,0x11B3D0F0+1
        defadr wstrrchr,0x10DD87B8+1
        defadr BookObj_CallSubroutine,0x10E61264+1
        defadr List_InsertLast,0x11B3D04C+1
        defadr debug_printf,0x2AF3A280+1
        defadr PlayFile,0x11A59474+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11B140F4+1
        defadr Profile_SetActive,0x11B4401C+1
        defadr isKeylocked,0x10958330+1
        defadr isMediaPlayerVideoBook,0x10E8470D
        defadr Vibra,0x11A587DC+1
        defadr REQUEST_DATEFORMAT_GET,0x108220A4+1
        defadr REQUEST_TIMEFORMAT_GET,0x10822188+1
        defadr Date2ID,0x11AD16A0+1
        defadr Time2ID,0x11AD15BC+1
        defadr CreateListMenu,0x11AF6B30+1
        defadr ListMenu_SetItemCount,0x11AF6D44+1
        defadr ROOT_APP,0x2AFA9F9C
        defadr GUIObject_SoftKeys_SetInfoText,0x10882D74+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x10882ED0+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11AD4C54+1
        defadr REQUEST_SYSTEM_RESTART,0x11AD4C64+1
        defadr GUIObject_SoftKeys_SetTexts,0x10882DE0+1
        defadr isRightNowBook,0x10BA1478+1
        defadr isVolumeControllerBook,0x11B3041C+1
        defadr CreateTabMenuBar,0x117F5688+1
        defadr TabMenuBar_SetTabCount,0x117F58E0+1
        defadr TabMenuBar_SetTabGui,0x117F5758+1
        defadr TabMenuBar_SetTabIcon,0x117F57D8+1
        defadr GUIObject_Destroy,0x10A40D40+1
        defadr GUIInput_SetIcon,0x10A41008+1
        defadr StringInput_GetStringAndLen,0x10908EB4+1
        defadr GetAudioControlPtr,0x2AFC70A0
        defadr AudioControl_Vibrate,0x115C5B44+1
        defadr GetVolumeSize,0x109CB1B0+1
        defadr CreateNOfMany,0x11AF8B18+1
        defadr NOfMany_SetTexts,0x11AF8D1C+1
        defadr NOfMany_SetChecked,0x11AF8CA0+1
        defadr NOfMany_SetCursor,0x11AF8C68+1
        defadr NOfMany_GetCheckedCount,0x11AF8CC4+1
        defadr NOfMany_GetChecked,0x11AF8CB4+1
        defadr NOfMany_SetOnMessage,0x11AF8D14+1
        defadr AudioControl_Init,0x11A595C0+1
        defadr OneOfMany_SetFocused,0x11AF927C+1
        defadr OneOfMany_SetOnMessage,0x11AF92E0+1
        defadr CreateMonitorFeedback,0x11AD0284+1
        defadr FeedBack_SetText,0x11AD033C+1
        defadr GetBatteryState,0x110F4764+1
        defadr get_DisplayGC,0x10A3ED90+1
        defadr DispObject_GetRect,0x10A37988+1
        defadr GC_GetRect,0x10A3F3D4+1
        defadr GC_GetXX,0x10A3F6D0+1
        defadr GC_SetXX,0x10A3F6C4+1
        defadr GC_ValidateRect,0x10A3F384+1
        defadr BookObj_AddGUIObject,0x10E61854+1
        defadr DrawRect,0x10A3AADC+1
        defadr DrawString,0x10A3AE28+1
        defadr XGUIList_AddGUIObject,0x10E61D54+1
        defadr DispObject_InvalidateRect,0x10A37718+1
        defadr GUIObject_Create,0x10A40B7C+1
        defadr SetFont,0x10A3B9E8+1
        defadr StatusRow_p,0x2AFC5334
        defadr root_list_get_session_count,0x10E5F7FC+1
        defadr root_list_get_session,0x10E5F80C+1
        defadr SESSION_GetTopBook,0x10E5EFDC+1
        defadr MainInput_strlen,0x10DFE418+1
        defadr BookObj_GetBookID,0x10E61C30+1
        defadr wstrncmp,0x1076FD8C+1
        defadr DispObject_GetAbsoluteXPos,0x10A38B8C+1
        defadr DispObject_GetAbsoluteYPos,0x10A38BC0+1
        defadr DispObject_GetWindow,0x10A37C9C+1
        defadr GetThemeColor,0x10ED0198+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11B13B28+1
        defadr REQUEST_SETTING_SILENCE_GET,0x11B13AD0+1
        defadr VCALL_Init,0x10BC78BC+1
        defadr VCALL_SetName,0x10BC79B4+1
        defadr VCALL_SetNameIcon,0x10BC7A14+1
        defadr VCALL_SetNumber,0x10BC79D4+1
        defadr VCALL_SetHZ1,0x10BC79F8+1
        defadr VCALL_SetHZ2,0x10BC7A04+1
        defadr MakeVoiceCall,0x10BC7454+1
        defadr FileDelete,0x109C8A1C+1
        defadr GUIObject_SetFocus,0x10A40EF8+1
        defadr CreateSMSCont,0x11A87734+1
        defadr FreeSMSCont,0x11A87E78+1
        defadr PrepareSMSCont,0x11A87914+1
        defadr CteateNewMessage,0x11A87DA0+1
        defadr get_APP_DESC_TABLE,0x11BF59F8
        defadr Window_GetComponentInterface,0x10A3E73C+1
        defadr AB_POSITIONNBR_GET,0x10BD9CF8+1
        defadr AB_NAME_ITEM2StrID,0x10BD9C0C+1
        defadr AB_NUM_ITEM2StrID,0x10BD9C70+1
        defadr GetABRecNum,0x10BEAAC4+1
        defadr get_AB_ITEMS_DESC,0x11BDE730
        defadr SBY_GetMainInput,0x10919A84+1
        defadr SBY_GetStatusIndication,0x107DF430+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10ABF2DC+1
        defadr PID_MMI,0x2AFA8474
        defadr DispObject_GetGUI,0x10A36FFC+1
        defadr Display_GetFocusedDispObject,0x10A36F48+1
        defadr DispObject_GetVisible,0x10A375BC+1
        defadr DispObject_GetDESC,0x11564534+1
        defadr DISP_DESC_SetName,0x10A341C8+1
        defadr DispObject_GetName,0x10A388E4+1
        defadr DISP_DESC_SetSize,0x10A341CC+1
        defadr DISP_DESC_SetOnCreate,0x10A341D0+1
        defadr DispObject_GetOnCreate,0x10A3424C+1
        defadr DISP_DESC_SetOnClose,0x10A341D4+1
        defadr DispObject_GetOnClose,0x10A34268+1
        defadr DISP_DESC_SetOnRedraw,0x10A341D8+1
        defadr DispObject_GetOnRedraw,0x10A34284+1
        defadr DISP_DESC_SetOnKey,0x10A341E0+1
        defadr DispObject_GetOnKey,0x10A342BC+1
        defadr DISP_DESC_SetOnRefresh,0x10A341DC+1
        defadr DispObject_GetonRefresh,0x10A342A0+1
        defadr DISP_DESC_SetMethod06,0x10A341E4+1
        defadr DispObject_GetMethod06,0x10A342D8+1
        defadr DISP_DESC_SetOnLayout,0x10A341EC+1
        defadr DispObject_GetOnLayout,0x10A34310+1
        defadr DISP_DESC_SetOnConfig,0x10A341F0+1
        defadr DispObject_GetOnConfig,0x10A3432C+1
        defadr DISP_DESC_SetMethod0A,0x10A341F4+1
        defadr DispObject_GetMethod0A,0x10A34348+1
        defadr DISP_DESC_SetMethod0B,0x10A341F8+1
        defadr DispObject_GetMethod0B,0x10A34364+1
        defadr DISP_DESC_SetMethod0C,0x10A341FC+1
        defadr JavaSession_Manager,0x10007F20+1
        defadr JavaSession_GetName,0x10007F20+1
        defadr BookObj_GetSession,0x10E61B90+1
        defadr GUIonMessage_SetNumberOfSubItems,0x11AF79B0+1
        defadr GUIonMessage_SubItem_SetText,0x11AF7A1C+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x11AF7A10+1
        defadr GoMusic,0x10E97C58+1
        defadr Vibra_Off,0x11A588B0+1
        defadr PlayFileV,0x11A59478+1
        defadr GetSilent,0x11A57960+1
        defadr GetVibrator,0x11A53808+1
        defadr GetAudioSettings,0x11A58C4C+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x11AF7A04+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x11AE5914+1
        defadr DestroyDirHandle,0x109C5FC4+1
        defadr LastExtDB,0x11EFBBF0
        defadr GetOtherExtMethods,0x118630D0+1
        defadr MessageBox,0x10E31E84+1
        defadr Display_GetHeight,0x117F7CF8+1
        defadr Display_GetWidth,0x117F7D04+1
        defadr PlaySystemSound,0x11A5941C+1
        defadr TabMenuBar_GetFocusedTab,0x117F574C+1
        defadr TabMenuBar_SetFocusedTab,0x117F573C+1
        defadr GC_GetPenColor,0x10A3F5DC+1
        defadr GC_SetPenColor,0x10A3F5A0+1
        defadr GC_SetPixel,0x10A3F224+1
        defadr GC_DrawLine,0x10A3FD20+1
        defadr GC_DrawFRect,0x10A3FEAC+1
        defadr GC_WritePixels,0x10A3F2AC+1
        defadr png_create_read_struct_2,0x118A1A00+1
        defadr png_destroy_read_struct,0x118A1B4C+1
        defadr png_create_info_struct,0x118A01A8+1
        defadr png_destroy_info_struct,0x118A01DC+1
        defadr png_set_progressive_read_fn,0x118A19D8+1
        defadr png_process_data,0x118A0998+1
        defadr png_read_update_info,0x118A1B20+1
        defadr png_get_progressive_ptr,0x118A19FC+1
        defadr png_get_IHDR,0x118A0664+1
        defadr png_set_strip_16,0x118A1CEC+1
        defadr png_set_gray_1_2_4_to_8,0x118A1D04+1
        defadr png_set_gray_to_rgb,0x118A1D1C+1
        defadr png_get_valid,0x118A0638+1
        defadr png_set_tRNS_to_alpha,0x118A1CF8+1
        defadr png_set_filler,0x118A4A80+1
        defadr png_set_palette_to_rgb,0x118A1D10+1
        defadr png_get_rowbytes,0x118A0650+1
        defadr png_progressive_combine_row,0x118A19B8+1
        defadr png_sig_cmp,0x118A00A0+1
        defadr setjmp,0x1014BB40
        defadr longjmp,0x1014BB64
        defadr inflateInit2_,0x118A5754+1
        defadr inflate,0x118A58FC+1
        defadr inflateEnd,0x118A6BF4+1
        defadr memcmp,0x12666344
        defadr strncmp,0x1076F44C+1
        defadr strncpy,0x1076F480+1
        defadr strcat,0x1076F37C+1
        defadr GUIObject_SetTitleType,0x10A4112C+1
        defadr GUIonMessage_SetItemDisabled,0x11AF79BC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10817F48+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10817FD0+1
        defadr get_Surfaces,0x2B183A50
        defadr iconidname2id,0x115929FC+1
        defadr textidname2id,0x1177B1A0+1
        defadr ListMenu_SetNoItemText,0x11AF6ED4+1
        defadr isFmRadioBook,0x1101A2BD
        defadr isAudioPlayerBook,0x10CF6101
        defadr SwitchRadioStationFromList,0x11018190+1
        defadr Shortcut_Run,0x10E4DA54+1
        defadr mkdir,0x109C53A4+1
        defadr rmdir,0x109C5798+1
        defadr chmod,0x109C8948+1
        defadr rename,0x109C8F70+1
        defadr CallID_GetCallStatusDesc,0x10E72230+1
        defadr CallStatusDesc_GetName,0x10E71868+1
        defadr List_DestroyElements,0x11B3D1E4+1
        defadr strstr,0x1076F51C+1
        defadr GPRS_GetLastSessionInfo,0x108753C8+1
        defadr wstrcmpni,0x10DD8854+1
        defadr wtoi,0x10E5D504+1
        defadr DATE_GetWeekDay,0x10C3C450+1
        defadr Cale_GetSettings,0x10995214+1
        defadr wstrwstr,0x1076FEEC+1
        defadr wstrcmpi,0x10DD8898+1
        defadr wstrchr,0x1076FCD4+1
        defadr GUIObject_SoftKeys_Hide,0x108830C8+1
        defadr GUIObject_SoftKeys_Show,0x108830D4+1
        defadr DispObject_SoftKeys_Get,0x1087F4A0+1
        defadr StandbyBackground_SetImage,0x10ECEA0C+1
        defadr CreateYesNoQuestionVA,0x117F75AC+1
        defadr ListMenu_SetSecondLineText,0x11AF70F8+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10B9A0FC+1
        defadr FSX_isNameInvalid,0x109CAFA0+1
        defadr DataBrowserDesc_SetFoldersNumber,0x1186D210+1
        defadr DataBrowserDesc_SetActions,0x1186D1E4+1
        defadr DataBrowserDesc_SetSelectAction,0x1186D18C+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x1186D194+1
        defadr DataBrowserDesc_SetBookID,0x1186D170+1
        defadr DataBrowserDesc_SetItemFilter,0x1186D114+1
        defadr DataBrowserDesc_SetOption,0x1186D240+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x1186D2A8+1
        defadr DataBrowserDesc_SetFileExtList,0x1186D11C+1
        defadr FSX_RemoveIllegalSymbolsName,0x1187698C+1
        defadr FILEITEM_Create,0x118763A4+1
        defadr FILEITEM_Destroy,0x118764D4+1
        defadr CreateDateInputVA,0x117F5A14+1
        defadr CreateTimeInputVA,0x117F7184+1
        defadr StringInput_SetCursorPosition,0x10908F00+1
        defadr BookObj_CallPage,0x10E61308+1
        defadr DateInput_GetDateInt,0x117F5C84+1
        defadr TimeInput_GetTimeInt,0x117F744C+1
        defadr GC_GetBrushColor,0x10A3F6B8+1
        defadr GC_SetBrushColor,0x10A3F678+1
        defadr GC_DrawRoundRect,0x10A3FEF4+1
        defadr MenuBook_Desktop,0x10E4D208+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10E4C53C+1
        defadr BookObj_SoftKeys_SetAction,0x1087D360+1
        defadr BookObj_SoftKeys_SetText,0x1087D398+1
        defadr FindBookByID,0x10E5F6C8+1
        defadr TextFeedbackWindow,0x117F69E8+1
        defadr Feedback_SetKeyHook,0x117F6DF4+1
        defadr Feedback_SetOnClose,0x117F6D90+1
        defadr Feedback_SetTimeout,0x117F6DC0+1
        defadr Feedback_SetTextExtended,0x117F6E58+1
        defadr TabMenuBar_SetOnTabSwitch,0x117F5834+1
        defadr KeyCode2Name,0x1101F0B4+1
        defadr ImageID_Get,0x10815E50+1
        defadr ImageID_Free,0x1081C070+1
        defadr DataBrowser_CreateSubExecute,0x11855ED8+1
        defadr DataBrowser_ExecuteSubroutine,0x118568F8+1
        defadr FILEITEM_SetFname,0x11876580+1
        defadr FILEITEM_SetPath,0x11876840+1
        defadr FILEITEM_GetFname,0x11876838+1
        defadr FILEITEM_GetPath,0x118768CC+1
        defadr FILEITEM_SetFnameAndContentType,0x118765E0+1
        defadr FILEITEM_SetPathAndContentType,0x118768A4+1
        defadr JavaDialog_Open,0x10B825F4+1
        defadr JavaDialog_Close,0x10B85D48+1
        defadr JavaAppDesc_Get,0x10B85F14+1
        defadr JavaAppDesc_GetFirstApp,0x10B77F88+1
        defadr JavaAppDesc_GetNextApp,0x10B77F90+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B77A54+1
        defadr DispObject_SetRefreshTimer,0x10A37180+1
        defadr DispObject_KillRefreshTimer,0x10A371FC+1
        defadr isDataBrowserBook,0x11869AC8+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x11865160+1
        defadr Shortcut_Get_MenuItemName,0x10BA2FD0+1
        defadr Shortcut_Get_MenuItemIconID,0x10E4D42C+1
        defadr FindBookEx,0x10E5F75C+1
        defadr FILEITEM_CreateCopy,0x118763D4+1
        defadr ActionCreate,0x10E60EEC+1
        defadr BookObj_GetSessionID,0x10E61AB8+1
        defadr UI_Event_toSID,0x10E60288+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11AD0D14+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x1087EE80+1
        defadr PNUM2Name,0x10BC2AEC+1
        defadr SpeedDial_GetPNUM,0x10BEA01C+1
        defadr DispObject_GetWindowWidth,0x10A38B0C+1
        defadr DispObject_GetWindowHeight,0x10A38B2C+1
        defadr get_system_langID,0x10E29668+1
        defadr lang_get_name,0x11AFFE7C+1
        defadr w_chdir,0x2AF00320
        defadr w_fopen,0x11308EC4+1
        defadr w_fstat,0x11308F7C+1
        defadr w_fwrite,0x11308F0C+1
        defadr w_fread,0x11308EF4+1
        defadr w_lseek,0x11AC9638+1
        defadr w_fclose,0x11308F24+1
        defadr w_mkdir,0x2AF002B8
        defadr DirHandle_SetFilterStr,0x109C601C+1
        defadr Disp_GetStrIdWidth,0x10A3C174+1
        defadr ImageID_GetIndirect,0x10815EE8+1
        defadr unixtime2datetime,0x10C3C268+1
        defadr List_Insert,0x11B3D054+1
        defadr FileCopy,0x109C8D24+1
        defadr FileMove,0x109C8F70+1
        defadr DispObject_SetLayerColor,0x10A39910+1
        defadr JavaAppDesc_GetJavaAppID,0x10B85E70+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10CAAAC4+1
        defadr JavaApp_LogoImageID_Get,0x10C9F2F4+1
        defadr CreateProgressBar,0x117F6148+1
        defadr ProgressBar_SetText,0x117F6440+1
        defadr ProgressBar_SetIcon,0x117F65B4+1
        defadr ProgressBar_SetPercentValue,0x117F63FC+1
        defadr ProgressBar_SetBarDisabled,0x117F65D4+1
        defadr StringInput_DispObject_SetText,0x108FD794+1
        defadr GUIObject_SetTitleIcon,0x10A41180+1
        defadr DispObject_SoftKeys_GetParams,0x10880150+1
        defadr DispObject_SoftKeys_GetList,0x10880194+1
        defadr BookObj_GetDisplayOrientation,0x10E61CCC+1
        defadr BookObj_SetDisplayOrientation,0x10E61C68+1
        defadr Display_GetTopBook,0x10E60FA8+1
        defadr Display_GetBrightness,0x10E323F8+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x1186D178+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x1186D1D4+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1186D1DC+1
        defadr SetTheme,0x10E7DFBC+1
        defadr SoftKeys_GetLabel,0x1088267C+1
        defadr SoftKeys_Update,0x10882234+1
        defadr IncommingCall_Reject,0x10E7B470+1
        defadr IncommingCall_Mute,0x10E7C7B0+1
        defadr Bluetooth_GetState,0x10AD319C+1
        defadr Bluetooth_GetPhoneVisibility,0x10AD3160+1
        defadr Bluetooth_isBusy,0x10AD322C+1
        defadr USB_isConnected,0x10A2ADC0+1
        defadr w_diropen,0x2AF002C8
        defadr w_dirread,0x11AC9CC8+1
        defadr w_dirclose,0x2AF00308
        defadr w_rename,0x11AC9D64+1
        defadr w_remove,0x11AC9D18+1
        defadr isCameraBook,0x10935A39
        defadr StringInput_MenuItem_SetPriority,0x10909008+1
        defadr CreatePercentInputVA,0x117F5DB4+1
        defadr PercentInput_GetPercent,0x117F5F40+1
        defadr GUIonMessage_SetLineSeparator,0x11AF79D4+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x108830E0+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x108830EC+1
        defadr SetTrayIcon,0x117FA2C8+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11B137D0+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x11B139C4+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10B77034+1
        defadr SoundRecorderDesc_Create,0x10EBB810+1
        defadr SoundRecorderDesc_Destroy,0x10EBB86C+1
        defadr SoundRecorderDesc_SetBookID,0x10EBB888+1
        defadr SoundRecorderDesc_SetType,0x10EBB8B4+1
        defadr SoundRecorderDesc_SetFolder,0x10EBB8C8+1
        defadr SoundRecorderDesc_SetFname,0x10EBB8E4+1
        defadr SoundRecorderDesc_SetRecordSize,0x10EBB900+1
        defadr SoundRecorder_Create,0x10EBB978+1
        defadr SoundRecorder_RecordCall,0x10E6E79C+1
        defadr Browser_OpenURI,0x107F25C8+1
        defadr GetURIScheme,0x10E81B7C+1
        defadr CreateURI,0x10E82018+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x1186D1F8+1
        defadr DispObject_Show,0x10A37438+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x108830A8+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1186D2B0+1
        defadr GUIonMessage_GetMsg,0x11AF78E4+1
        defadr GUIonMessage_GetBook,0x11AF78EC+1
        defadr GUIonMessage_GetGui,0x11AF78E8+1
        defadr GUIonMessage_GetSelectedItem,0x11AF78F0+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11AF78FC+1
        defadr ObexSendFile,0x10914C20+1
        defadr Feedback_SetManualScrollingText,0x117F1780+1
        defadr CANVAS_Get_GviGC,0x1144994C+1
        defadr GVI_BitBlt,0x111B0848+1
        defadr GVI_StretchBlt,0x111B09BC+1
        defadr GVI_TransformBlt,0x111B0A78+1
        defadr GVI_CreatePen,0x111AFAF0+1
        defadr GVI_CreateDashedPen,0x111AFB34+1
        defadr GVI_CreateSolidBrush,0x111AFA00+1
        defadr GVI_Delete_GVI_Object,0x111AF3D0+1
        defadr GVI_DrawEllipse,0x111B0180+1
        defadr GVI_DrawLine,0x111B106C+1
        defadr GVI_DrawLines,0x111B16FC+1
        defadr GVI_DrawPolyLine,0x111B1780+1
        defadr GVI_DrawRectangle,0x111B19FC+1
        defadr GVI_DrawRoundRect,0x111B069C+1
        defadr GVI_DrawSolidLines,0x111B12C0+1
        defadr GVI_DrawSolidPolyLine,0x111B14C8+1
        defadr GVI_DrawSolidRectangle,0x111B156C+1
        defadr GVI_FillEllipse,0x111B0568+1
        defadr GVI_FillPolygon,0x111B0F24+1
        defadr GVI_FillRectangle,0x111B187C+1
        defadr GVI_FillRectangles,0x111B1908+1
        defadr GVI_FillSolidEllipse,0x111B0614+1
        defadr GVI_FillSolidRectangle,0x111B1984+1
        defadr GVI_FillSolidRoundRect,0x111B07EC+1
        defadr GVI_FillSolidTriangle,0x111B0EB0+1
        defadr GC_CreateMemoryGC,0x10A3EDA0+1
        defadr GC_FreeGC,0x10A3EE68+1
        defadr GVI_CreateBitmap,0x111AFBEC+1
        defadr GVI_CreateMemoryGC,0x111B1B60+1
        defadr GVI_DeleteMemoryGC,0x111DF7CC+1
        defadr List_InsertSorted,0x11B3D068+1
        defadr ListMenu_SetItemIcon,0x11AF702C+1
        defadr wstrnupr,0x10DD7504+1
        defadr wstrnlwr,0x1106328C+1
        defadr ListMenu_SetItemTextScroll,0x11AF7424+1
        defadr TabMenuBar_SetTabTitle,0x117F5820+1
        defadr GUIObject_GetBook,0x10A40DE0+1
        defadr SoftKeys_GetSelectedAction,0x1087EDB0+1
        defadr MonitorFeedback_SetTimer,0x11AD0330+1
        defadr ListMenu_DestroyItems,0x11AF719C+1
        defadr YesNoQuestion_SetIcon,0x117F7830+1
        defadr GUIObject_SetBacklightTimeout,0x10A41088+1
        defadr CoCreateInstance,0x107918B0+1
        
        defadr DisplayGC_AddRef,0x10A3F1C8+1

        defadr Str2ID_int,0x10FD4758+1
        defadr int2strID_int,0x10FD4584+1
        defadr TextFree_int,0x10FD4A94+1
        
        defadr Disp_GetStrIdHeight,0x10A3C0D4+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11B13B74+1
        defadr Settings_ShowNumber_Get,0x1103595C+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11B1423C+1
        defadr MainInput_Hide,0x10DFE364+1
        
        defadr Alarm_GetCurrentTypeAndAlarmID,0x1081E928+1
        defadr Alarm_GetTIME,0x1081E134+1
        defadr Alarm_GetWeekSettings,0x1081F06C+1
        
//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x11032B80+1
        defadr FlightGetState,    0x11AD2990+1
        
        defadr CallInfo_Get,      0x112E7494+1
        defadr isTimerBook,       0x110158AC+1

        defadr some,              0x10E8054C+1
        defadr armfunc,           0x1076BC80

        defadr Show,              0x10DFFB20+1
        defadr Return_Clear,      0x10DFFB1A+1
        defadr Show_Clear,        0x10DFFB48+1

        defadr oldRedrawStatus,   0x117EAA7C+1
        defadr oldRedrawDisplay,  0x10DFD0D8+1
        defadr oldRedrawSoft,     0x10881C4C+1
        defadr oldCreateDisplay,  0x10DFD06C+1
        defadr oldCloseDisplay,   0x10DFD0C4+1
        defadr oldOnKeyMainInput, 0x10DFADBC+1

        defadr retSetIcon,        0x117FA2E0+1

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
        LDR	R0, =0x1A98
        
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
          