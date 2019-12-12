#ifdef W580_R8BE001

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x44D432A4+1
        defadr memfree,0x44D432D0+1
        defadr memset,0x44145350
        defadr memcpy,0x442D0844
        defadr sprintf,0x44557078+1
        defadr snwprintf,0x44557640+1
        defadr _fopen,0x44E87A4C+1
        defadr fclose,0x44E89018+1
        defadr fread,0x44E892A0+1
        defadr fwrite,0x44E8946C+1
        defadr fstat,0x44E883E0+1
        defadr AllocDirHandle,0x44E85A00+1
        defadr GetFname,0x44E85BC0+1
        defadr DataBrowserDesc_Create,0x44EC51C0+1
        defadr DataBrowserDesc_SetStyle,0x44EC5484+1
        defadr DataBrowserDesc_SetHeaderText,0x44EC54B4+1
        defadr DataBrowserDesc_SetFolders,0x44EC549C+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x44EC54BC+1
        defadr DataBrowser_Create,0x44EC1A68+1
        defadr DataBrowserDesc_Destroy,0x44EC5274+1
        defadr getFileExtention,0x44E8AB30+1
        defadr DataBrowser_isFileInListExt,0x44E85E2C+1
        defadr Timer_ReSet,0x452AB438+1
        defadr Timer_Set,0x452AB404+1
        defadr Timer_Kill,0x452AB490+1
        defadr CreateBook,0x452AE448+1
        defadr BookObj_KillBook,0x452AE570+1
        defadr BookObj_GotoPage,0x452AE1C4+1
        defadr BookObj_ReturnPage,0x452AE32C+1
        defadr FreeBook,0x452AEA64+1
        defadr FindBook,0x452ACB08+1
        defadr Find_StandbyBook,0x452C1A34+1
        defadr BookObj_SetFocus,0x452AE6F4+1
        defadr GUIObject_SetTitleText,0x453653C8+1
        defadr GUIObject_Show,0x45364E98+1
        defadr ListMenu_SetCursorToItem,0x4531E448+1
        defadr GUIObject_SetStyle,0x45364EE8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x4531EF98+1
        defadr GUIonMessage_SetMenuItemText,0x4531EFA4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x4531EFD4+1
        defadr GUIonMessage_SetMenuItemInfoText,0x4531EFB4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x4531EFC4+1
        defadr GUIonMessage_SetMenuItemIcon,0x4531F01C+1
        defadr DispObject_SetTitleText,0x45359D3C+1
        defadr ListMenu_GetSelectedItem,0x4531E45C+1
        defadr ListMenu_SetItemStyle,0x4531E4AC+1
        defadr GC_PutChar,0x453631EC+1
        defadr isScreenSaverBook,0x453940A5
        defadr StatusIndication_SetItemText,0x45374998+1
        defadr StatusIndication_ShowNotes,0x452C36EC+1
        defadr CreateStringInputVA,0x452F6518+1
        defadr CreateOneOfMany,0x453203FC+1
        defadr OneOfMany_SetItemCount,0x453205C4+1
        defadr OneOfMany_SetChecked,0x453205E0+1
        defadr OneOfMany_SetTexts,0x45320614+1
        defadr OneOfMany_GetSelected,0x453205F0+1
        defadr StatusIndication_Item8_SetText,0x452C361C+1
        defadr GUIObject_SoftKeys_SetAction,0x45381700+1
        defadr GUIObject_SoftKeys_SetText,0x45381778+1
        defadr GUIObject_SoftKeys_SetEnable,0x45381834+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x453817EC+1
        defadr GUIObject_SoftKeys_RemoveItem,0x453816C4+1
        defadr GUIObject_SoftKeys_SetVisible,0x453817C8+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x45381A38+1
        defadr wstrcpy,0x44557D4C+1
        defadr wstrncpy,0x44557DF8+1
        defadr wstrcat,0x44557CF0+1
        defadr wstrncat,0x44557D98+1
        defadr wstrcmp,0x44557D24+1
        defadr wstrlen,0x44E47DC8+1
        defadr str2wstr,0x44E49090+1
        defadr strcmp,0x44557424+1
        defadr strlen,0x44557480+1
        defadr wstr2strn,0x44E47EE8+1
        defadr TextID_CreateIntegerID,0x45347180+1
        defadr TextID_Create,0x45347434+1
        defadr TextID_GetString,0x453478C8+1
        defadr TextID_GetWString,0x453477B8+1
        defadr TextID_GetLength,0x45347698+1
        defadr TextID_Destroy,0x453475FC+1
        defadr AB_DEFAULTNBR_GET,0x44DE6D88+1
        defadr AB_READSTRING,0x44DEBE58+1
        defadr AB_READPHONENBR,0x44DEBF24+1
        defadr AB_GETNBROFITEMS,0x44DEBFDC+1
        defadr PNUM_len,0x45346AA4+1
        defadr PNUM2str,0x452340A0+1
        defadr GUIObject_GetDispObject,0x45364C98+1
        defadr List_Create,0x451B5814+1
        defadr List_Destroy,0x451B5850+1
        defadr List_InsertFirst,0x451B59C4+1
        defadr Gif2ID,0x44E3D814+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x44E412EC+1
        defadr REQUEST_DATEANDTIME_GET,0x44D49830+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x4539102C+1
        defadr GetFreeBytesOnHeap,0x44F7DD64+1
        defadr BookObj_Hide,0x452AE71C+1
        defadr BookObj_Show,0x452AE72C+1
        defadr StartAPP,0x452C1BB0+1
        defadr ListMenu_SetOnMessage,0x4531E59C+1
        defadr manifest_GetParam,0x4527CB98+1
        defadr lseek,0x44E89614+1
        defadr get_VBUFFER,0x441425B7
        defadr SetLampLevel,0x452E1B1C+1
        defadr List_RemoveAt,0x451B5950+1
        defadr GetCurrentPID,0x442C0E9C+1
        defadr List_IndexOf,0x451B5984+1
        defadr alloc,0x443096D4
        defadr receive,0x443096F0
        defadr send,0x443096E0
        defadr sender,0x44309730
        defadr free_buf,0x44309700
        defadr create_process,0x443097CC
        defadr start,0x443099EC
        defadr get_ptype,0x4430989C
        defadr current_process,0x443097E8
        defadr delay,0x44309720
        defadr hunt,0x443098E8
        defadr kill_proc,0x44309914
        defadr stop,0x443099FC
        defadr get_mem,0x44309868
        defadr get_envp,0x442C0C7C+1
        defadr set_envp,0x442C0C90+1
        defadr get_bid,0x44309820
        defadr strcpy,0x4455744C+1
        defadr CreateMessage,0x44FF58F8+1
        defadr SendMessage,0x44FF594C+1
        defadr WaitMessage,0x44FF59D4+1
        defadr FreeMessage,0x44FF59E8+1
        defadr SendDispatchMessage,0x44FCC1F8+1
        defadr UIEventName,0x452ABA14+1
        defadr MissedEvents,0x20187DA8
        defadr UI_Event,0x452ACED0+1
        defadr UI_Event_wData,0x452ACEE0+1
        defadr UI_Event_toBookID,0x452ACF28+1
        defadr UI_Event_toBookIDwData,0x452ACF3C+1
        defadr List_Find,0x451B5BE4+1
        defadr List_Get,0x451B5AE8+1
        defadr wstrrchr,0x44557E4C+1
        defadr BookObj_CallSubroutine,0x452AE238+1
        defadr List_InsertLast,0x451B59CC+1
        defadr debug_printf,0x44236C50+1
        defadr PlayFile,0x45004830+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x452E5C50+1
        defadr Profile_SetActive,0x452D65D0+1
        defadr SetBrightnessOfScreen,0x452DE764+1
        defadr isKeylocked,0x45394124+1
        defadr isMediaPlayerVideoBook,0x44F508B5
        defadr ShuttingDown,0x452BDC3E+1
        defadr Vibra,0x44FD604C+1
        defadr REQUEST_DATEFORMAT_GET,0x44D49A10+1
        defadr REQUEST_TIMEFORMAT_GET,0x44D49AA4+1
        defadr Date2ID,0x452AA5E0+1
        defadr Time2ID,0x452AA508+1
        defadr CreateListMenu,0x4531E240+1
        defadr ListMenu_SetItemCount,0x4531E470+1
        defadr ROOT_APP,0x201820C0
        defadr GUIObject_SoftKeys_SetInfoText,0x45381764+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x45381858+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x452C4668+1
        defadr REQUEST_SYSTEM_RESTART,0x452C4678+1
        defadr GUIObject_SoftKeys_SetTexts,0x4538179C+1
        defadr IsRightNowBook,0x4538B1A0+1
        defadr IsVolumeControllerBook,0x452C0FA0+1
        defadr CreateTabMenuBar,0x45365D00+1
        defadr TabMenuBar_SetTabCount,0x45365DD4+1
        defadr TabMenuBar_SetTabGui,0x45365E88+1
        defadr TabMenuBar_SetTabIcon,0x45365EC4+1
        defadr GUIObject_Destroy,0x45364C28+1
        defadr GUIInput_SetIcon,0x45364FA4+1
        defadr StringInput_GetStringAndLen,0x452F6DBC+1
        defadr GetAudioControlPtr,0x2017ECCC
        defadr AudioControl_Vibrate,0x44C530B8+1
        defadr GetVolumeSize,0x44E8A84C+1
        defadr CreateNOfMany,0x4531FE3C+1
        defadr NOfMany_SetTexts,0x4532007C+1
        defadr NOfMany_SetChecked,0x45320000+1
        defadr NOfMany_SetCursor,0x4531FFC8+1
        defadr NOfMany_GetCheckedCount,0x45320024+1
        defadr NOfMany_GetChecked,0x45320014+1
        defadr NOfMany_SetOnMessage,0x45320074+1
        defadr AudioControl_Init,0x45004980+1
        defadr OneOfMany_SetFocused,0x453205A8+1
        defadr OneOfMany_SetOnMessage,0x4532060C+1
        defadr CreateMonitorFeedback,0x452BCB6C+1
        defadr FeedBack_SetText,0x452BCC38+1
        defadr GetBatteryState,0x449C5C88+1
        defadr get_DisplayGC,0x45362714+1
        defadr DispObject_GetRect,0x4535B1D0+1
        defadr GC_GetRect,0x45362DEC+1
        defadr GC_GetXX,0x453630F0+1
        defadr GC_SetXX,0x453630E4+1
        defadr GC_ValidateRect,0x45362D9C+1
        defadr BookObj_AddGUIObject,0x452AE7A8+1
        defadr DrawRect,0x4535DA00+1
        defadr DrawString,0x4535DD00+1
        defadr XGUIList_AddGUIObject,0x452AEC84+1
        defadr DispObject_InvalidateRect,0x4535B03C+1
        defadr GUIObject_Create,0x45364B4C+1
        defadr SetFont,0x4535E75C+1
        defadr StatusRow_p,0x20186E98
        defadr root_list_get_session_count,0x452ACC08+1
        defadr root_list_get_session,0x452ACC14+1
        defadr SESSION_GetTopBook,0x452AC4F8+1
        defadr MainInput_getVisible,0x452BCFC8+1
        defadr MainInput_strlen,0x452BCFD4+1
        defadr MainInput_getPNUM,0x452BCFEC+1
        defadr MainInput_isPlus,0x452BCFF8+1
        defadr BookObj_GetBookID,0x452AEB24+1
        defadr wstrncmp,0x44557DC4+1
        defadr DispObject_GetAbsoluteXPos,0x4535C1C0+1
        defadr DispObject_GetAbsoluteYPos,0x4535C1F4+1
        defadr DispObject_GetWindow,0x4535B4EC+1
        defadr GetThemeColor,0x45384460+1
        defadr REQUEST_SETTING_SILENCE_SET,0x452E5528+1
        defadr REQUEST_SETTING_SILENCE_GET,0x452E54D0+1
        defadr VCALL_Init,0x44DDEF00+1
        defadr VCALL_SetName,0x44DDEFF8+1
        defadr VCALL_SetNameIcon,0x44DDF058+1
        defadr VCALL_SetNumber,0x44DDF018+1
        defadr VCALL_SetHZ1,0x44DDF03C+1
        defadr VCALL_SetHZ2,0x44DDF048+1
        defadr MakeVoiceCall,0x44DDEAD8+1
        defadr isDirectory,0x45005828+1
        defadr FileDelete,0x44E88524+1
        defadr GUIObject_SetFocus,0x45364E44+1
        defadr CreateSMSCont,0x45028260+1
        defadr FreeSMSCont,0x45028900+1
        defadr PrepareSMSCont,0x45028438+1
        defadr CteateNewMessage,0x45028860+1
        defadr get_APP_DESC_TABLE,0x45AF75F4
        defadr Window_GetComponentInterface,0x45361E48+1
        defadr AB_POSITIONNBR_GET,0x44DEC1B4+1
        defadr AB_NAME_ITEM2StrID,0x44DEC0DC+1
        defadr AB_NUM_ITEM2StrID,0x44DEC124+1
        defadr GetABRecNum,0x44A5B4AE+1
        defadr get_AB_ITEMS_DESC,0x45AAD118
        defadr SBY_GetMainInput,0x44A69804+1
        defadr SBY_GetStatusIndication,0x44A69800+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x44D677A8+1
        defadr PID_MMI,0x2009D044
        defadr DispObject_GetGUI,0x4535A9CC+1
        defadr Display_GetFocusedDispObject,0x4535A91C+1
        defadr DispObject_GetVisible,0x4535AED0+1
        defadr DispObject_GetDESC,0x448EEDE8+1
        defadr DISP_DESC_SetName,0x45356A24+1
        defadr DispObject_GetName,0x4535BF80+1
        defadr DISP_DESC_SetSize,0x45356A28+1
        defadr DISP_DESC_SetOnCreate,0x45356A2C+1
        defadr DispObject_GetOnCreate,0x45356AB4+1
        defadr DISP_DESC_SetOnClose,0x45356A30+1
        defadr DispObject_GetOnClose,0x45356AD0+1
        defadr DISP_DESC_SetOnRedraw,0x45356A34+1
        defadr DispObject_GetOnRedraw,0x45356AEC+1
        defadr DISP_DESC_SetOnKey,0x45356A3C+1
        defadr DispObject_GetOnKey,0x45356B24+1
        defadr DISP_DESC_SetOnRefresh,0x45356A38+1
        defadr DispObject_GetonRefresh,0x45356B08+1
        defadr DISP_DESC_SetMethod06,0x45356A40+1
        defadr DispObject_GetMethod06,0x45356B40+1
        defadr DISP_DESC_SetOnLayout,0x45356A48+1
        defadr DispObject_GetOnLayout,0x45356B78+1
        defadr DISP_DESC_SetOnConfig,0x45356A4C+1
        defadr JavaSession_Manager,0x441405DA+1
        defadr JavaSession_GetName,0x441405D8+1
        defadr TextCopyId,0x45347564+1
        defadr BookObj_GetSession,0x452AEAC4+1
        defadr GUIonMessage_SetNumberOfSubItems,0x4531F034+1
        defadr GUIonMessage_SubItem_SetText,0x4531F0AC+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x4531F0A0+1
        defadr GoMusic,0x4521632C+1
        defadr Vibra_Off,0x44FD6120+1
        defadr PlayFileV,0x45004834+1
        defadr GetSilent,0x44FD5504+1
        defadr GetVibrator,0x44FD2B6C+1
        defadr GetAudioSettings,0x44FD6398+1
        defadr GetChipID,0x44235F30+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x4531F094+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x4531F088+1
        defadr DestroyDirHandle,0x44E85D3C+1
        defadr GetOtherExtMethods,0x44EBBEEC+1
        defadr MessageBox,0x452B987C+1
        defadr Display_GetHeight,0x45377E80+1
        defadr Display_GetWidth,0x45377E8C+1
        defadr PlaySystemSound,0x450047E0+1
        defadr TabMenuBar_GetFocusedTab,0x45365DC8+1
        defadr TabMenuBar_SetFocusedTab,0x45365DB8+1
        defadr GC_GetPenColor,0x45362FF8+1
        defadr GC_SetPenColor,0x45362FBC+1
        defadr GC_SetPixel,0x45362BFC+1
        defadr GC_DrawLine,0x45363774+1
        defadr GC_DrawFRect,0x45363900+1
        defadr GC_WritePixels,0x45362CC8+1
        defadr png_create_read_struct_2,0x44AEA5B0+1
        defadr png_destroy_read_struct,0x44AEA6FC+1
        defadr png_create_info_struct,0x44AE8D54+1
        defadr png_destroy_info_struct,0x44AE8D88+1
        defadr png_set_progressive_read_fn,0x44AEA588+1
        defadr png_process_data,0x44AE9548+1
        defadr png_read_update_info,0x44AEA6D0+1
        defadr png_get_progressive_ptr,0x44AEA5AC+1
        defadr png_get_IHDR,0x44AE9210+1
        defadr png_set_strip_16,0x44AEA89C+1
        defadr png_set_gray_1_2_4_to_8,0x44AEA8B4+1
        defadr png_set_gray_to_rgb,0x44AEA8CC+1
        defadr png_get_valid,0x44AE91E4+1
        defadr png_set_tRNS_to_alpha,0x44AEA8C0+1
        defadr png_set_filler,0x44AED604+1
        defadr png_set_palette_to_rgb,0x44AEA8A8+1
        defadr png_get_rowbytes,0x44AE91FC+1
        defadr png_progressive_combine_row,0x44AEA568+1
        defadr png_sig_cmp,0x44AE8C4C+1
        defadr setjmp,0x442D4B68
        defadr longjmp,0x442D4B8C
        defadr inflateInit2_,0x44AEE268+1
        defadr inflate,0x44AEE408+1
        defadr inflateEnd,0x44AEF668+1
        defadr memcmp,0x2000310C
        defadr strncmp,0x445574BC+1
        defadr strncpy,0x445574F0+1
        defadr strcat,0x445573EC+1
        defadr GUIObject_SetTitleType,0x453653AC+1
        defadr GUIonMessage_SetItemDisabled,0x4531F040+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x44E41354+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x44E41404+1
        defadr get_Surfaces,0x202F78D8
        defadr iconidname2id,0x44C34E98+1
        defadr textidname2id,0x44D41774+1
        defadr ListMenu_SetNoItemText,0x4531E640+1
        defadr IsFmRadioBook,0x450FAD09
        defadr IsAudioPlayerBook,0x44F34E55
        defadr PlayerControl,0x44F3B088+1
        defadr SwitchRadioStationFromList,0x450F8EF0+1
        defadr Shortcut_Run,0x4538F018+1
        defadr mkdir,0x44E84F88+1
        defadr rmdir,0x44E85674+1
        defadr chmod,0x44E88454+1
        defadr rename,0x44E88A44+1
        defadr GetImageWidth,0x4535ECF4+1
        defadr GetImageHeight,0x4535ED08+1
        defadr CallID_GetCallStatusDesc,0x44DAFA0C+1
        defadr CallStatusDesc_GetName,0x44DAF0B4+1
        defadr List_DestroyElements,0x451B5C28+1
        defadr strstr,0x44557588+1
        defadr GPRS_GetLastSessionInfo,0x453B7110+1
        defadr wstrcmpni,0x44E491A8+1
        defadr wtoi,0x452AADD4+1
        defadr DATE_GetWeekDay,0x44FF64A0+1
        defadr Cale_GetSettings,0x44D75258+1
        defadr wstrwstr,0x44557E8C+1
        defadr wstrcmpi,0x44E491EC+1
        defadr wstrchr,0x44557D0C+1
        defadr GUIObject_SoftKeys_Hide,0x45381A84+1
        defadr GUIObject_SoftKeys_Show,0x45381A90+1
        defadr DispObject_SoftKeys_Get,0x45380214+1
        defadr StandbyBackground_SetImage,0x45353800+1
        defadr CreateYesNoQuestionVA,0x453757F0+1
        defadr ListMenu_SetItemSecondLineText,0x4531E864+1
        defadr _REQUEST_OAF_START_APPLICATION,0x44EAF244+1
        defadr FSX_isNameInvalid,0x44E8A634+1
        defadr DataBrowserDesc_SetFoldersNumber,0x44EC54A4+1
        defadr DataBrowserDesc_SetActions,0x44EC547C+1
        defadr DataBrowserDesc_SetSelectAction,0x44EC53F4+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x44EC53FC+1
        defadr DataBrowserDesc_SetBookID,0x44EC53D0+1
        defadr DataBrowserDesc_SetItemFilter,0x44EC5378+1
        defadr DataBrowserDesc_SetOption,0x44EC54DC+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x44EC5570+1
        defadr DataBrowserDesc_SetFileExtList,0x44EC5380+1
        defadr FSX_RemoveIllegalSymbolsName,0x44ECF8C8+1
        defadr FILEITEM_Create,0x44ECF130+1
        defadr FILEITEM_Destroy,0x44ECF220+1
        defadr CreateDateInputVA,0x45373C20+1
        defadr CreateTimeInputVA,0x45375418+1
        defadr StringInput_SetCursorPosition,0x452F6E08+1
        defadr BookObj_CallPage,0x452AE2C4+1
        defadr DateInput_GetDateInt,0x45373E24+1
        defadr TimeInput_GetTimeInt,0x45375660+1
        defadr GC_GetBrushColor,0x453630D8+1
        defadr GC_SetBrushColor,0x45363098+1
        defadr GC_DrawRoundRect,0x45363948+1
        defadr MenuBook_Desktop,0x453868C8+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x45386A5C+1
        defadr BookObj_SoftKeys_SetAction,0x4537C8CC+1
        defadr BookObj_SoftKeys_SetText,0x4537C904+1
        defadr FindBookByID,0x452ACAD4+1
        defadr TextFeedbackWindow,0x45374C98+1
        defadr Feedback_SetKeyHook,0x453750D0+1
        defadr Feedback_SetOnClose,0x45375070+1
        defadr Feedback_SetTimeout,0x4537509C+1
        defadr Feedback_SetTextExtended,0x45375134+1
        defadr TabMenuBar_SetOnTabSwitch,0x45365F1C+1
        defadr KeyCode2Name,0x4501D060+1
        defadr ImageID_Get,0x44E3CA40+1
        defadr ImageID_Free,0x44E3CA34+1
        defadr DataBrowser_CreateSubExecute,0x44EAFB04+1
        defadr DataBrowser_ExecuteSubroutine,0x44EB0524+1
        defadr FILEITEM_SetFname,0x44ECF31C+1
        defadr FILEITEM_SetPath,0x44ECF72C+1
        defadr FILEITEM_GetFname,0x44ECF724+1
        defadr FILEITEM_GetPath,0x44ECF7D8+1
        defadr FILEITEM_SetFnameAndContentType,0x44ECF3A4+1
        defadr FILEITEM_SetPathAndContentType,0x44ECF7B0+1
        defadr JavaDialog_Open,0x44E9DA80+1
        defadr JavaDialog_Close,0x44EA1534+1
        defadr JavaAppDesc_Get,0x44EA16F8+1
        defadr JavaAppDesc_GetFirstApp,0x44E97498+1
        defadr JavaAppDesc_GetNextApp,0x44E974A0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44E970B8+1
        defadr OrangeLED_Control,0x452D473C+1
        defadr DispObject_SetRefreshTimer,0x4535AB00+1
        defadr DispObject_KillRefreshTimer,0x4535AB80+1
        defadr isDataBrowserBook,0x44EC2248+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x44EBDAE8+1
        defadr Shortcut_Get_MenuItemName,0x4538DC50+1
        defadr Shortcut_Get_MenuItemIconID,0x45386B78+1
        defadr FindBookEx,0x452ACB68+1
        defadr FILEITEM_CreateCopy,0x44ECF170+1
        defadr ActionCreate,0x452ADBEC+1
        defadr BookObj_GetSessionID,0x452AEA14+1
        defadr UI_Event_toSID,0x452ACEF4+1
        defadr GetIMSI,0x4422EA00+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x452BDC60+1
        defadr MainInput_getCurPos,0x452BCFE0+1
        defadr MainInput_Hide,0x452BCFB0+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x4537E0F8+1
        defadr PNUM2Name,0x44DDB70C+1
        defadr SpeedDial_GetPNUM,0x44DF99D4+1
        defadr MetaData_Desc_Create,0x452346C4+1
        defadr MetaData_Desc_Destroy,0x45234784+1
        defadr MetaData_Desc_GetTags,0x452347C4+1
        defadr MetaData_Desc_GetTrackNum,0x45234824+1
        defadr DispObject_GetWindowWidth,0x4535C140+1
        defadr DispObject_GetWindowHeight,0x4535C160+1
        defadr get_system_langID,0x452D3D6C+1
        defadr lang_get_name,0x453032FC+1
        defadr w_chdir,0x44F8C638+1
        defadr w_fopen,0x44850DD0+1
        defadr w_fstat,0x44850E88+1
        defadr w_fwrite,0x44850E18+1
        defadr w_fread,0x44850E00+1
        defadr w_lseek,0x451B3224+1
        defadr w_fclose,0x44850E30+1
        defadr w_mkdir,0x44F8E5F4+1
        defadr DirHandle_SetFilterStr,0x44E85D9C+1
        defadr Disp_GetStrIdWidth,0x4535ED90+1
        defadr MetaData_Desc_GetCoverInfo,0x45234870+1
        defadr ImageID_GetIndirect,0x44E3CC64+1
        defadr unixtime2datetime,0x44FF62B8+1
        defadr List_Insert,0x451B5890+1
        defadr FileCopy,0x44E88820+1
        defadr FileMove,0x44E88A44+1
        defadr RedLED_On,0x44235358+1
        defadr RedLED_Off,0x442353A4+1
        defadr DispObject_SetLayerColor,0x4535CEC0+1
        defadr JavaAppDesc_GetJavaAppID,0x44EA1654+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x44F75AE0+1
        defadr JavaApp_LogoImageID_Get,0x44F6B44C+1
        defadr CreateProgressBar,0x453742EC+1
        defadr ProgressBar_SetText,0x45374634+1
        defadr ProgressBar_SetIcon,0x45374728+1
        defadr ProgressBar_SetPercentValue,0x453745F0+1
        defadr ProgressBar_SetBarDisabled,0x45374738+1
        defadr StringInput_DispObject_SetText,0x452ECC5C+1
        defadr GUIObject_SetTitleBackgroundImage,0x45365468+1
        defadr GUIObject_SetTitleIcon,0x45365400+1
        defadr GUIObject_SetCursorImage,0x4531FAC8+1
        defadr GUIObject_SetBackgroundImage,0x4531FAD8+1
        defadr DispObject_SoftKeys_GetParams,0x4537F324+1
        defadr DispObject_SoftKeys_GetList,0x4537F36C+1
        defadr BookObj_GetDisplayOrientation,0x452AEC2C+1
        defadr BookObj_SetDisplayOrientation,0x452AEB88+1
        defadr Display_GetTopBook,0x452ADCB4+1
        defadr Display_SetBrightness,0x453661B8+1
        defadr Display_GetBrightness,0x45366238+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x44EC53D8+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x44EC545C+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x44EC5464+1
        defadr SetTheme,0x4538270C+1
        defadr SoftKeys_GetLabel,0x45381260+1
        defadr SoftKeys_Update,0x45380E24+1
        defadr get_CellData,0x2018EC78
        defadr IncommingCall_Reject,0x44DB6EFC+1
        defadr IncommingCall_Mute,0x44DB8180+1
        defadr GetRadioState,0x441A44C0+1
        defadr Bluetooth_GetState,0x44D83E78+1
        defadr Bluetooth_GetPhoneVisibility,0x44D83E40+1
        defadr Bluetooth_isBusy,0x44D83F00+1
        defadr USB_isConnected,0x451C7F54+1
        defadr w_diropen,0x44F8E7AC+1
        defadr w_dirread,0x451B3920+1
        defadr w_dirclose,0x44F8EB18+1
        defadr w_rename,0x451B39C8+1
        defadr w_remove,0x451B396C+1
        defadr ConnectionManager_Connection_GetState,0x451CA090+1
        defadr GetSignalQuality,0x441A44CC+1
        defadr isCameraBook,0x4500DC89
        defadr isSoundRecorderBook,0x44F57E49
        defadr StringInput_MenuItem_SetPriority,0x452F6F18+1
        defadr VideoPlayerControl,0x44F528F4+1
        defadr Video_ActionBack,0x44F51F70+1
        defadr Video_ExtractFrame,0x44F53924+1
        defadr Video_ZoomOn,0x44F52328+1
        defadr RightNow_SetActive,0x4538B99C+1
        defadr VideoResize_AutomateMode,0x44F5227C+1
        defadr VideoResize_AllScreenMode,0x44F52214+1
        defadr Video_GetCurrentSkinID,0x44F532D4+1
        defadr Video_SetSkin,0x44F50650+1
        defadr Video_SetPermit,0x44F521A4+1
        defadr Video_Refresh,0x44F51D40+1
        defadr Video_Play,0x44F51FF0+1
        defadr Video_Pause,0x44F52128+1
        defadr Video_Stop,0x44F520F4+1
        defadr Audio_Pause,0x44F376CC+1
        defadr Audio_Play,0x44F373CC+1
        defadr CreatePercentInputVA,0x45373F50+1
        defadr PercentInput_GetPercent,0x453740F0+1
        defadr GUIonMessage_SetLineSeparator,0x4531F058+1
        defadr PHF_GetState,0x452E69A8+1
        defadr CHF_GetState,0x452E69B0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x45381A9C+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x45381AA8+1
        defadr SetTrayIcon,0x452C38CC+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x452E50D8+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x452E53C8+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x452E52C8+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x452E5864+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x452E5194+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x452E5638+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x44E96718+1
        defadr SoundRecorderDesc_Create,0x44F57504+1
        defadr SoundRecorderDesc_Destroy,0x44F5757C+1
        defadr SoundRecorderDesc_SetBookID,0x44F575A4+1
        defadr SoundRecorderDesc_SetType,0x44F575D0+1
        defadr SoundRecorderDesc_SetFolder,0x44F575E4+1
        defadr SoundRecorderDesc_SetFname,0x44F57600+1
        defadr SoundRecorderDesc_SetRecordSize,0x44F5761C+1
        defadr SoundRecorder_Create,0x44F57694+1
        defadr SoundRecorder_RecordCall,0x44DAC464+1
        defadr Browser_OpenURI,0x44E1772C+1
        defadr GetURIScheme,0x45232ED4+1
        defadr CreateURI,0x4523336C+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x44EC548C+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x44D47B9C+1
        defadr Alarm_GetState,0x44D466F0+1
        defadr Alarm_GetTIME,0x44D4753C+1
        defadr Alarm_GetWeekSettings,0x44D48238+1
        defadr IrDa_GetState,0x452DC7C0+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x452E55DC+1
        defadr IncommingCall_Accept,0x44DB6DBC+1
        defadr MediaPlayer_SoftKeys_SetText,0x44F3490C+1
        defadr MediaPlayer_SoftKeys_SetAction,0x44F348D8+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x44F34998+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x44F34928+1
        defadr MediaPlayer_ShowNowPlaying,0x44F33EE4+1
        defadr DispObject_Show,0x4535AD50+1
        defadr Request_EventChannel_Subscribe,0x441CB6AC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x45381A64+1
        defadr Request_ICA_ShutdownAllConnections,0x44836A20+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x452E5D7C+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x44EC5578+1
        defadr GUIonMessage_GetMsg,0x4531EF74+1
        defadr GUIonMessage_GetBook,0x4531EF7C+1
        defadr GUIonMessage_GetGui,0x4531EF78+1
        defadr GUIonMessage_GetSelectedItem,0x4531EF80+1
        defadr GUIonMessage_GetPrevSelectedItem,0x4531EF8C+1
        defadr ObexSendFile,0x44DD83F0+1
        defadr Feedback_SetManualScrollingText,0x4536BD9C+1
        defadr EqualizerGain_Set,0x44FCDEA0+1
        defadr CANVAS_Get_GviGC,0x445FDC04+1
        defadr GVI_BitBlt,0x449EE4AC+1
        defadr GVI_StretchBlt,0x449EE618+1
        defadr GVI_TransformBlt,0x449EE6CC+1
        defadr GVI_CreatePen,0x449ED6D0+1
        defadr GVI_CreateDashedPen,0x449ED720+1
        defadr GVI_CreateSolidBrush,0x449ED5C4+1
        defadr GVI_Delete_GVI_Object,0x449ECF84+1
        defadr GVI_DrawEllipse,0x449EDDA4+1
        defadr GVI_DrawLine,0x449EEC78+1
        defadr GVI_DrawLines,0x449EF384+1
        defadr GVI_DrawPolyLine,0x449EF418+1
        defadr GVI_DrawRectangle,0x449EF69C+1
        defadr GVI_DrawRoundRect,0x449EE2E4+1
        defadr GVI_DrawSolidLines,0x449EEF38+1
        defadr GVI_DrawSolidPolyLine,0x449EF154+1
        defadr GVI_DrawSolidRectangle,0x449EF20C+1
        defadr GVI_FillEllipse,0x449EE17C+1
        defadr GVI_FillPolygon,0x449EEAEC+1
        defadr GVI_FillRectangle,0x449EF528+1
        defadr GVI_FillRectangles,0x449EF5C0+1
        defadr GVI_FillSolidEllipse,0x449EE248+1
        defadr GVI_FillSolidRectangle,0x449EF638+1
        defadr GVI_FillSolidRoundRect,0x449EE438+1
        defadr GVI_FillSolidTriangle,0x449EEA5C+1
        defadr GC_CreateMemoryGC,0x45362724+1
        defadr GC_FreeGC,0x453627FC+1
        defadr Settings_ShowNumber_Get,0x44DD339C+1
        defadr GVI_CreateBitmap,0x449ED804+1
        defadr GVI_CreateMemoryGC,0x449EF844+1
        defadr GVI_DeleteMemoryGC,0x450493C8+1
        defadr StringInput_DispObject_SetLanguage,0x452F0E50+1
        defadr List_InsertSorted,0x451B59E8+1
        defadr ListMenu_SetItemIcon,0x4531E774+1
        defadr wstrnupr,0x44E47E98+1
        defadr wstrnlwr,0x450D5330+1
        defadr ListMenu_SetItemTextScroll,0x4531F650+1
        defadr GUIObject_SetTitleTextColor,0x45365458+1
        defadr GUIObject_SetListTextColor,0x4531FAE8+1
        defadr DispObject_SetTitleTextColor,0x4535A0A4+1
        defadr DispObject_SetListTextColor,0x453112D8+1
        defadr DispObject_SetCursorImage,0x45311294+1
        defadr DispObject_SetBackgroundImage,0x453112B0+1
        defadr DispObject_SetTitleImage,0x4535A0BC+1
        defadr TabMenuBar_SetTabTitle,0x45365EF0+1
        defadr GUIObject_GetBook,0x45364CAC+1
        defadr SoftKeys_GetSelectedAction,0x4537E030+1
        defadr MonitorFeedback_SetTimer,0x452BCC2C+1
        defadr ListMenu_DestroyItems,0x4531E944+1
        defadr DispObject_SetScrollBarBackgroundColor,0x4535C444+1
        defadr DispObject_SetScrollBarColor,0x4535C420+1
        defadr DispObject_SetSoftkeysColor,0x4537E624+1
        defadr YesNoQuestion_SetIcon,0x45375AA8+1
        defadr GUIObject_SetBacklightTimeout,0x4536500C+1
        defadr ListMenu_SetHotkeyMode,0x4531E5C8+1
        
        defadr CreateYesNoQuestion,0x453756CC+1
	defadr YesNoQuestion_SetDescriptionText,0x45375A88+1
	defadr YesNoQuestion_SetQuestionText,0x45375A78+1
        
        defadr CreateStringInput,0x452F6454+1
        defadr StringInput_SetText,0x452F6F48+1
        defadr StringInput_SetMinLen,0x452F6D9C+1
        defadr StringInput_SetMaxLen,0x452F6E3C+1
        defadr StringInput_SetMode,0x452F6D44+1
        defadr StringInput_SetEnableEmptyText,0x452F6EB8+1
        defadr StringInput_SetFixedText,0x452F6E6C+1
        defadr StringInput_SetActionOK,0x452F6D90+1
        defadr StringInput_SetActionBack,0x452F6D94+1
        
        defadr DispObject_SetThemeImage,0x4535CA9C+1
        
        defadr GC_DrawIcon,0x4535DBF4+1
        
        defadr Free_RightNowBook,0x4538B200+1
        
        defadr Find_RightNowBook,0x4538B1B4+1
        defadr Find_ScreenSaverBook,0x45394098+1
        
        defadr List_GetCount,0x451B5ABC+1
        defadr List_RemoveFirst,0x451B5A1C+1
        
        defadr FSX_MakeFullPath,0x44E8AC64+1
        defadr FSX_IsFileExists,0x44ECB654+1
        
        defadr CreateToast,0x452B98C8+1
        
        defadr GUIObject_TabTitleRemove,0x4531EBD4+1
        
        defadr GUIObject_SoftKeys_SetItemOnKey,0x453818C4+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x44DEC378+1
        
        defadr NewEvent_GetCount,0x4538C6A4+1
        
        defadr CreateEventMenu,0x4538C284+1
        
        defadr ActivityMenu_SetTab,0x4538AA9C+1
        defadr ActivityMenu_SendEvent,0x4538AB60+1
        defadr ActivityMenu_GotoPage,0x4538AAB8+1    
        defadr ActivityMenu_RefreshBook,0x4538B87C+1
        
        defadr FMRADIO_ACTION_LAYOUT,0x11
        
        defadr FmRadio_SetActiveSoftKeys,0x450F8C44+1

        defadr FmRadio_Gui_OnCreate,0x450F7A44+1
        defadr FmRadio_Gui_OnClose,0x450F7AA4+1
        defadr FmRadio_Gui_OnRedraw,0x450F7BFC+1
        defadr FmRadio_Gui_OnKey,0x450F7AB8+1
        defadr FmRadio_Gui_OnConfig,0x450F7BA4+1
        defadr FmRadio_Gui_OnLayout,0x450F7BB4+1
        
        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x450F88A0+1
        defadr pg_FmRadio_Main__PAGE_EXIT_EVENT,0x450F8A00+1
        defadr pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT,0x450F9210+1
        
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
        
        //RSEG PATCH_FmRadio_OnLayout
        //DATA
        //DCD New_FmRadio_Gui_OnLayout
        
        //RSEG PATCH_FmRadio_MainPage_Enter
        //DATA
        //DCD New_FmRadio_Main__PAGE_ENTER_EVENT
        
        RSEG PATCH_FmRadio_Created
        DATA
        DCD New_FmRadio_Base__UI_FMRADIO_CREATED_EVENT
        
//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_DeleteData
        CODE16
        LDR	R3, =delete_data
	BX	R3

        RSEG  CODE
        CODE16
delete_data: 
        CMP     R0, #0
        BEQ     nex_
        LDR	R3, =0x450FB648+1
	BLX	R3
nex_:
        BL      DeleteData
        POP     {R4-R6,PC}

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
        LDR	R3, =0x450F8B24+1
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
         MOV    R1, #5
         LDR	R3, =GUIObject_SoftKeys_SetVisible
         BLX	R3
         LDR    R0, [R4,#0x18]
         MOV    R1, #FMRADIO_ACTION_LAYOUT
         ADD    R2, R5, #0
         LDR	R3, =GUIObject_SoftKeys_SetVisible
         BLX	R3
         LDR	R3, =0x450F8C86+1
         BX	R3
         
#endif
        END
