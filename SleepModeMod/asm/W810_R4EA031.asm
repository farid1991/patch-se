//W810_R4EA031

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x45453AA8+1
        defadr memfree,0x454547E0+1
        defadr memset,0x44E24360+1
        defadr memcpy,0x4418E878
        defadr sprintf,0x44E24E88+1
        defadr snwprintf,0x44E25568+1
        defadr _fopen,0x455B4268+1
        defadr fclose,0x455B54A0+1
        defadr fread,0x455B5700+1
        defadr fwrite,0x455B58E4+1
        defadr fstat,0x455B4ADC+1
        defadr AllocDirHandle,0x455B25B8+1
        defadr GetFname,0x455B273C+1
        defadr DataBrowserDesc_Create,0x4524A5E4+1
        defadr DataBrowserDesc_SetStyle,0x4524A53C+1
        defadr DataBrowserDesc_SetHeaderText,0x4524A55C+1
        defadr DataBrowserDesc_SetFolders,0x4524A54C+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x4524A564+1
        defadr DataBrowser_Create,0x45249B38+1
        defadr DataBrowserDesc_Destroy,0x4524A66C+1
        defadr getFileExtention,0x455B6DC0+1
        defadr DataBrowser_isFileInListExt,0x455B2970+1
        defadr Timer_ReSet,0x4529EAE4+1
        defadr Timer_Set,0x4529EAC0+1
        defadr Timer_Kill,0x4529EB10+1
        defadr CreateBook,0x4529F750+1
        defadr BookObj_KillBook,0x4529F848+1
        defadr BookObj_GotoPage,0x4529F4CC+1
        defadr BookObj_ReturnPage,0x4529F648+1
        defadr FreeBook,0x4529FC78+1
        defadr FindBook,0x45531160+1
        defadr Find_StandbyBook,0x452AC7B8+1
        defadr BookObj_SetFocus,0x4529F994+1
        defadr GUIObject_SetTitleText,0x45193F7C+1
        defadr GUIObject_Show,0x45193E64+1
        defadr ListMenu_SetCursorToItem,0x45170870+1
        defadr GUIObject_SetStyle,0x45193EC4+1
        defadr GUIonMessage_GetCreatedItemIndex,0x451713A4+1
        defadr GUIonMessage_SetMenuItemText,0x451713B4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x451713E4+1
        defadr GUIonMessage_SetMenuItemInfoText,0x451713C4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x451713D4+1
        defadr GUIonMessage_SetMenuItemIcon,0x451713F4+1
        defadr DispObject_SetTitleText,0x45304A34+1
        defadr ListMenu_GetSelectedItem,0x45170884+1
        defadr SetMenuItemStyle,0x451708E8+1
        defadr GC_PutChar,0x451925BC+1
        defadr IsScreenSaverBook,0x4515A0EC+1
        defadr StatusIndication_SetItemText,0x451541C4+1
        defadr StatusIndication_ShowNotes,0x452AE544+1
        defadr CreateStringInputVA,0x45165BDC+1
        defadr CreateOneOfMany,0x4517250C+1
        defadr OneOfMany_SetItemCount,0x451726A0+1
        defadr OneOfMany_SetChecked,0x451726C4+1
        defadr OneOfMany_SetTexts,0x451726F8+1
        defadr OneOfMany_GetSelected,0x451726D4+1
        defadr StatusIndication_Item8_SetText,0x452AE460+1
        defadr GUIObject_Softkey_SetAction,0x4519B824+1
        defadr GUIObject_Softkey_SetText,0x4519B90C+1
        defadr GUIObject_SoftKey_SetEnable,0x4519BA78+1
        defadr GUIObject_SoftKey_AddErrorStr,0x4519B9E8+1
        defadr GUIObject_SoftKey_RemoveItem,0x4519B7B4+1
        defadr GUIObject_SoftKey_SetVisible,0x4519B9A4+1
        defadr GUIObject_SoftKey_SuppressDefaultAction,0x4519BE20+1
        defadr wstrcpy,0x44E25C34+1
        defadr wstrncpy,0x44E25CE8+1
        defadr wstrcat,0x44E25BD4+1
        defadr wstrncat,0x44E25C84+1
        defadr wstrcmp,0x44E25C04+1
        defadr wstrlen,0x44E25C70+1
        defadr str2wstr,0x44FEAE4C+1
        defadr _strcmp,0x44E252EC+1
        defadr strlen,0x44E25354+1
        defadr wstr2strn,0x44FE9C44+1
        defadr int2strID,0x452FE300+1
        defadr TextID_Create,0x452FE69C+1
        defadr StrID2Str,0x452FF248+1
        defadr TextID2wstr,0x452FEA1C+1
        defadr TextGetLength,0x452FE8FC+1
        defadr TextID_Destroy,0x452FE86C+1
        defadr AB_DEFAULTNBR_GET,0x4521430C+1
        defadr AB_READSTRING,0x452196AC+1
        defadr AB_READPHONENBR,0x45219754+1
        defadr AB_GETNBROFITEMS,0x452197F4+1
        defadr PNUM_len,0x452FDF80+1
        defadr PNUM2str,0x454036E0+1
        defadr GUIObject_GetDispObject,0x45193C40+1
        defadr List_Create,0x4527EFAC+1
        defadr List_Destroy,0x4527EFC4+1
        defadr List_InsertFirst,0x4527F0C0+1
        defadr Gif2ID,0x4542789C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x455ADDD0+1
        defadr REQUEST_DATEANDTIME_GET,0x455953A4+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x45542E24+1
        defadr GetFreeBytesOnHeap,0x45455734+1
        defadr BookObj_Hide,0x4529F9C4+1
        defadr BookObj_Show,0x4529F9D8+1
        defadr StartAPP,0x452AC994+1
        defadr ListMenu_SetOnMessage,0x451709D8+1
        defadr manifest_GetParam,0x45565E94+1
        defadr lseek,0x455B5AA8+1
        defadr get_VBUFFER,0x4C061F5C
        defadr SetLampLevel,0x455F2464+1
        defadr List_RemoveAt,0x4527F048+1
        defadr GetCurrentPID,0x44149F14+1
        defadr List_IndexOf,0x4527F080+1
        defadr alloc,0x4418D7DC
        defadr receive,0x4418D7F8
        defadr send,0x4418D7E8
        defadr sender,0x4418D838
        defadr free_buf,0x4418D808
        defadr create_process,0x4418D8D4
        defadr start,0x4418DAF4
        defadr get_ptype,0x4418D9A4
        defadr current_process,0x4418D8F0
        defadr get_bid,0x4418D928
        defadr get_envp,0x44149CF6+1
        defadr set_envp,0x44149D0A+1
        defadr delay,0x4418D828
        defadr hunt,0x4418D9F0
        defadr kill_proc,0x4418DA10
        defadr strcpy,0x44E2531C+1
        defadr CreateMessage,0x45098750+1
        defadr SendMessage,0x450987A4+1
        defadr WaitMessage,0x45098834+1
        defadr FreeMessage,0x45098854+1
        defadr SendDispatchMessage,0x45266AD4+1
        defadr UIEventName,0x4563D1D4+1
        defadr UI_Event,0x4553127C+1
        defadr UI_Event_wData,0x45531288+1
        defadr UI_Event_toBookID,0x455312AC+1
        defadr UI_Event_toBookIDwData,0x455312BC+1
        defadr List_Find,0x4527F370+1
        defadr List_Get,0x4527F250+1
        defadr wstrrchr,0x44E25D38+1
        defadr BookObj_CallSubroutine,0x4529F548+1
        defadr List_InsertLast,0x4527F0D0+1
        defadr debug_printf,0x44C9E13C+1
        defadr PlayFile,0x45153EE0+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x4564D670+1
        defadr Profile_SetActive,0x452B263C+1
        defadr SetBrightnessOfScreen,0x452B81B0+1
        defadr isKeylocked,0x451582C4+1
        defadr IsMediaPlayerVideoBook,0x45445071
        defadr VideoOnWholeScreen,0x454465DC+1
        defadr ShuttingDown,0x45159AC8+1
        defadr Vibra,0x4545D040+1
        defadr REQUEST_DATEFORMAT_GET,0x455955BC+1
        defadr REQUEST_TIMEFORMAT_GET,0x4559565C+1
        defadr Date2ID,0x45150BE0+1
        defadr Time2ID,0x45150AF8+1
        defadr CreateListMenu,0x45170674+1
        defadr ListMenu_SetItemCount,0x4517089C+1
        defadr ROOT_APP,0x4C2DC794
        defadr GUIObject_Softkey_SetInfoText,0x4519B8D0+1
        defadr GUIObject_Softkey_SetItemAsSubItem,0x4519BAC0+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x45643FB0+1
        defadr REQUEST_SYSTEM_RESTART,0x45643FC0+1
        defadr GUIObject_Softkey_SetTexts,0x4519B954+1
        defadr IsRightNowBook,0x4563E6CC+1
        defadr IsVolumeControllerBook,0x45643CC0+1
        defadr CreateTabMenuBar,0x45153758+1
        defadr TabMenuBar_SetTabCount,0x45153868+1
        defadr TabMenuBar_SetTabGui,0x4515394C+1
        defadr TabMenuBar_SetTabIcon,0x45153A28+1
        defadr GUIObject_Destroy,0x45193BE4+1
        defadr GUIInput_SetIcon,0x4519404C+1
        defadr StringInput_GetStringAndLen,0x45166484+1
        defadr GetAudioControlPtr,0x4C2DC86C
        defadr AudioControl_Vibrate,0x4532F85C+1
        defadr GetVolumeSize,0x455B6BB0+1
        defadr CreateNOfMany,0x45171F50+1
        defadr NOfMany_SetTexts,0x45172190+1
        defadr NOfMany_SetChecked,0x451720FC+1
        defadr NOfMany_SetCursor,0x451720BC+1
        defadr NOfMany_GetCheckedCount,0x45172124+1
        defadr NOfMany_GetChecked,0x45172110+1
        defadr NOfMany_SetOnMessage,0x45172188+1
        defadr AudioControl_Init,0x45154030+1
        defadr OneOfMany_SetFocused,0x45172684+1
        defadr OneOfMany_SetOnMessage,0x451726F0+1
        defadr CreateMonitorFeedback,0x45158A90+1
        defadr FeedBack_SetText,0x45158B2C+1
        defadr GetBatteryState,0x44A2A9FC+1
        defadr get_DisplayGC,0x45191A98+1
        defadr DispObject_GetRect,0x45302C0C+1
        defadr GC_GetRect,0x451920AC+1
        defadr GC_GetXX,0x451923C0+1
        defadr GC_SetXX,0x451923B4+1
        defadr GC_ValidateRect,0x45192058+1
        defadr BookObj_AddGUIObject,0x4529FA5C+1
        defadr DrawRect,0x45306940+1
        defadr DrawString,0x45306D48+1
        defadr XGUIList_AddGUIObject,0x452A7F44+1
        defadr DispObject_InvalidateRect,0x45302A70+1
        defadr GUIObject_Create,0x45193B18+1
        defadr SetFont,0x45307888+1
        defadr StatusRow_p,0x4C2DF7AC
        defadr root_list_get_session_count,0x45531254+1
        defadr root_list_get_session,0x45531268+1
        defadr SESSION_GetTopBook,0x45530B34+1
        defadr MainInput_getVisible,0x45158E48+1
        defadr MainInput_strlen,0x45158E54+1
        defadr MainInput_getPNUM,0x45158E74+1
        defadr MainInput_isPlus,0x45158E80+1
        defadr BookObj_GetBookID,0x4529FD0C+1
        defadr wstrncmp,0x44E25CAC+1
        defadr DispObject_GetAbsoluteXPos,0x45304888+1
        defadr DispObject_GetAbsoluteYPos,0x453048C0+1
        defadr DispObject_GetWindow,0x45303114+1
        defadr GetThemeColor,0x45532A30+1
        defadr REQUEST_SETTING_SILENCE_SET,0x4564CE44+1
        defadr REQUEST_SETTING_SILENCE_GET,0x4564CDE8+1
        defadr VCALL_Init,0x4520D578+1
        defadr VCALL_SetName,0x4520D66C+1
        defadr VCALL_SetNameIcon,0x4520D6D0+1
        defadr VCALL_SetNumber,0x4520D68C+1
        defadr VCALL_SetHZ1,0x4520D6B4+1
        defadr VCALL_SetHZ2,0x4520D6C0+1
        defadr MakeVoiceCall,0x4520CDB0+1
        defadr FileDelete,0x455B4BF4+1
        defadr GUIObject_SetFocus,0x45193E0C+1
        defadr CreateSMSCont,0x454744D8+1
        defadr FreeSMSCont,0x454749E8+1
        defadr PrepareSMSCont,0x45474638+1
        defadr CteateNewMessage,0x45474938+1
        defadr get_APP_DESC_TABLE,0x445047C0
        defadr Window_GetComponentInterface,0x455454AC+1
        defadr AB_POSITIONNBR_GET,0x45219A24+1
        defadr AB_NAME_ITEM2StrID,0x452198C4+1
        defadr AB_NUM_ITEM2StrID,0x45219918+1
        defadr GetABRecNum,0x4564A9FC+1
        defadr get_AB_ITEMS_DESC,0x444DCA20
        defadr SBY_GetMainInput,0x44D7954C+1
        defadr SBY_GetStatusIndication,0x44D79548+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x45597CD0+1
        defadr PID_MMI,0x4C0BCCA4
        defadr Display_GetFocusedDispObject,0x453023D4+1
        defadr DispObject_GetVisible,0x453028F4+1
        defadr DispObject_GetDESC,0x4531E678+1
        defadr DISP_DESC_SetName,0x45301D0C+1
        defadr DispObject_GetName,0x45304690+1
        defadr DISP_DESC_SetSize,0x45301D1C+1
        defadr DISP_DESC_SetOnCreate,0x45301D20+1
        defadr DispObject_GetOnCreate,0x45301F4C+1
        defadr DISP_DESC_SetOnClose,0x45301D24+1
        defadr DispObject_GetOnClose,0x45301F6C+1
        defadr DISP_DESC_SetOnRedraw,0x45301D28+1
        defadr DispObject_GetOnRedraw,0x45301F8C+1
        defadr DISP_DESC_SetOnKey,0x45301D30+1
        defadr DispObject_GetOnKey,0x45301FCC+1
        defadr DISP_DESC_SetonRefresh,0x45301D2C+1
        defadr DispObject_GetonRefresh,0x45301FAC+1
        defadr DISP_DESC_SetMethod06,0x45301D34+1
        defadr DispObject_GetMethod06,0x45301FEC+1
        defadr DISP_DESC_SetOnLayout,0x45301D3C+1
        defadr DispObject_GetOnLayout,0x4530202C+1
        defadr JavaSession_Manager,0x4564164C+1
        defadr JavaSession_GetName,0x45641594+1
        defadr TextCopyId,0x452FE7D0+1
        defadr BookObj_GetSession,0x4529FCB0+1
        defadr GUIonMessage_SetItemAsSubitem,0x45171440+1
        defadr GUIonMessage_SetSubitemText,0x451714CC+1
        defadr GUIonMessage_GetCreatedSubItemParrentIndex,0x451714BC+1
        defadr GoMusic,0x45131894+1
        defadr Vibra_Off,0x4545D118+1
        defadr VideoOnNormalScreen,0x45446638+1
        defadr PlayFileV,0x45153EF0+1
        defadr GetSilent,0x4545C658+1
        defadr GetVibrator,0x45459D18+1
        defadr GetAudioSettings,0x4545D394+1
        defadr GetChipID,0x44DD0FFC+1
        defadr GUIonMessage_GetCurrentSubItem,0x451714AC+1
        defadr GUIonMessage_GetCurrentItemIndex,0x4517149C+1
        defadr DestroyDirHandle,0x455B28C4+1
        defadr LastExtDB,0x444EE0B8
        defadr GetOtherExtMethods,0x455C3C78+1
        defadr MessageBox,0x45533C94+1
        defadr Display_GetHeight,0x45547974+1
        defadr Display_GetWidth,0x45547984+1
        defadr PlaySystemSound,0x45153E08+1
        defadr TabMenuBar_GetFocusedTab,0x45153844+1
        defadr TabMenuBar_SetFocusedTab,0x4515381C+1
        defadr GC_GetPenColor,0x451922C0+1
        defadr GC_SetPenColor,0x45192280+1
        defadr GC_SetPixel,0x45191EFE+1
        defadr GC_DrawLine,0x45192CD0+1
        defadr GC_DrawFRect,0x45192E64+1
        defadr GC_WritePixels,0x45191F7C+1
        defadr png_create_read_struct_2,0x44E912C4+1
        defadr png_destroy_read_struct,0x44E9130A+1
        defadr png_create_info_struct,0x44E90046+1
        defadr png_destroy_info_struct,0x44E90070+1
        defadr png_set_progressive_read_fn,0x44E912A4+1
        defadr png_process_data,0x44E906C8+1
        defadr png_read_update_info,0x44E913B8+1
        defadr png_get_progressive_ptr,0x44E912C0+1
        defadr png_get_IHDR,0x44E90450+1
        defadr png_set_strip_16,0x44E91548+1
        defadr png_set_gray_1_2_4_to_8,0x44E9155C+1
        defadr png_set_gray_to_rgb,0x44E91562+1
        defadr png_get_valid,0x44E9042C+1
        defadr png_set_tRNS_to_alpha,0x44E9155E+1
        defadr png_set_filler,0x44E93B24+1
        defadr png_set_palette_to_rgb,0x44E91550+1
        defadr png_get_rowbytes,0x44E9023E+1
        defadr png_progressive_combine_row,0x44E9128A+1
        defadr png_sig_cmp,0x44E8FF68+1
        defadr setjmp,0x44192A60
        defadr longjmp,0x44192A84
        defadr inflateInit2_,0x44E94554+1
        defadr inflate,0x44E946E0+1
        defadr inflateEnd,0x44151F8E+1
        defadr memcmp,0x44E242F4+1
        defadr strncmp,0x44E2538C+1
        defadr strncpy,0x44E253C8+1
        defadr strcat,0x44E252B0+1
        defadr GUIObject_SetTitleType,0x45193F58+1
        defadr GUIonMessage_SetItemDisabled,0x4517144C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x455ADE50+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x455ADEE4+1
        defadr iconidname2id,0x45329110+1
        defadr textidname2id,0x451E879C+1
        defadr ListMenu_SetNoItemText,0x45170A5C+1
        defadr IsFmRadioBook,0x456002A5
        defadr IsAudioPlayerBook,0x4542FF58+1
        defadr PlayerControl,0x45434C78+1
        defadr SwitchRadioStationFromList,0x455FE680+1
        defadr Shortcut_Run,0x45643298+1
        defadr mkdir,0x455B1DAC+1
        defadr rmdir,0x455B2440+1
        defadr chmod,0x455B4B38+1
        defadr rename,0x455B5054+1
        defadr GetImageWidth,0x45307FC0+1
        defadr GetImageHeight,0x45307FD8+1
        defadr CallID_GetCallStatusDesc,0x4540EA70+1
        defadr CallStatusDesc_GetName,0x4540E1E8+1
        defadr List_DestroyElements,0x4527F3B4+1
        defadr strstr,0x44E2546C+1
        defadr GPRS_GetLastSessionInfo,0x451A9F04+1
        defadr wstrcmpni,0x44FEAF64+1
        defadr wtoi,0x451514DC+1
        defadr DATE_GetWeekDay,0x4526CB00+1
        defadr Cale_GetSettings,0x44FAE744+1
        defadr wstrwstr,0x44E25E48+1
        defadr wstrcmpi,0x44FEAFB4+1
        defadr wstrchr,0x44E25BF0+1
        defadr GUIObject_HideSoftkeys,0x4519BEA4+1
        defadr GUIObject_ShowSoftkeys,0x4519BEB0+1
        defadr DispObject_SoftKeys_Get,0x4519ADCC+1
        defadr StandbyBackground_SetImage,0x45541C18+1
        defadr CreateYesNoQuestionVA,0x45196C30+1
        defadr ListMenu_SetSecondLineText,0x45170C98+1
        defadr _REQUEST_OAF_START_APPLICATION,0x455BAAEC+1
        defadr FSX_isNameInvalid,0x455B69D4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x4524A554+1
        defadr DataBrowserDesc_SetActions,0x4524A530+1
        defadr DataBrowserDesc_SetSelectAction,0x4524A4C4+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x4524A4CC+1
        defadr DataBrowserDesc_SetBookID,0x4524A498+1
        defadr DataBrowserDesc_SetItemFilter,0x4524A43C+1
        defadr DataBrowserDesc_SetOption,0x4524A57C+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x4524A5C4+1
        defadr DataBrowserDesc_SetFileExtList,0x4524A444+1
        defadr FSX_RemoveIllegalSymbolsName,0x455C6AFC+1
        defadr FILEITEM_Create,0x455C6624+1
        defadr FILEITEM_Destroy,0x455C6788+1
        defadr CreateDateInputVA,0x45195228+1
        defadr CreateTimeInputVA,0x4519685C+1
        defadr StringInput_SetCursorPosition,0x451664D4+1
        defadr BookObj_CallPage,0x4529F5DC+1
        defadr DateInput_GetDateInt,0x45195410+1
        defadr TimeInput_GetTimeInt,0x45196A90+1
        defadr GetFontDesc,0x4C2DF9D0
        defadr GetFontCount,0x4C2DFB88
        defadr GC_GetBrushColor,0x451923A8+1
        defadr GC_SetBrushColor,0x45192368+1
        defadr GC_DrawRoundRect,0x45192EB0+1
        defadr MenuBook_Desktop,0x4553A4F0+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x4553B490+1
        defadr BookObj_Softkey_SetAction,0x4554A6B0+1
        defadr BookObj_Softkey_SetText,0x4554A6FC+1
        defadr FindBookByID,0x45531124+1
        defadr TextFeedbackWindow,0x4519606C+1
        defadr Feedback_SetKeyHook,0x451964E0+1
        defadr Feedback_SetOnClose,0x45196474+1
        defadr Feedback_SetTimeout,0x451964A4+1
        defadr Feedback_SetTextExtended,0x4519654C+1
        defadr TabMenuBar_SetOnTabSwitch,0x45153ABC+1
        defadr KeyCode2Name,0x450A9384+1
        defadr ImageID_Get,0x45426B54+1
        defadr ImageID_Free,0x45426B44+1
        defadr DataBrowser_CreateSubExecute,0x455BAB64+1
        defadr DataBrowser_ExecuteSubroutine,0x455BB18C+1
        defadr FILEITEM_SetFname,0x455C67DC+1
        defadr FILEITEM_SetPath,0x455C6A10+1
        defadr FILEITEM_GetFname,0x455C6A08+1
        defadr FILEITEM_GetPath,0x455C6A6C+1
        defadr FILEITEM_SetFnameAndContentType,0x455C67DC+1
        defadr FILEITEM_SetPathAndContentType,0x455C6A10+1
        defadr JavaDialog_Open,0x45020BF0+1
        defadr JavaDialog_Close,0x45023F98+1
        defadr JavaAppDesc_Get,0x45024154+1
        defadr JavaAppDesc_GetFirstApp,0x4501BE90+1
        defadr JavaAppDesc_GetNextApp,0x4501BE98+1
        defadr JavaAppDesc_GetJavaAppInfo,0x4501BB98+1
        defadr OrangeLED_Control,0x44DBF15C+1
        defadr DispObject_SetRefreshTimer,0x453025B8+1
        defadr DispObject_KillRefreshTimer,0x4530264C+1
        defadr IsDataBrowserBook,0x4524A11C+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x455C4EDC+1
        defadr Shortcut_Get_MenuItemName,0x45641074+1
        defadr Shortcut_Get_MenuItemIconID,0x4553B53C+1
        defadr FindBookEx,0x455311D8+1
        defadr FILEITEM_CreateCopy,0x45251518+1
        defadr ActionCreate,0x4529EEF0+1
        defadr BookObj_GetSessionID,0x4529FC54+1
        defadr UI_Event_toSID,0x4553129C+1
        defadr GetIMSI,0x449F33AC+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x45159B20+1
        defadr MainInput_getCurPos,0x45075C74+1
        defadr MainInput_Hide,0x45075C3A+1
        defadr DispObject_SoftKey_RestoreDefaultAction,0x45198D60+1
        defadr PNUM2Name,0x45418C3C+1
        defadr SpeedDial_GetPNUM,0x45226110+1
        defadr MetaData_Desc_Create,0x4552A13C+1
        defadr MetaData_Desc_Destroy,0x4552A23C+1
        defadr MetaData_Desc_GetTags,0x4552A194+1
        defadr MetaData_Desc_GetTrackNum,0x4552A210+1
        defadr DispObject_GetWindowWidth,0x453047E8+1
        defadr DispObject_GetWindowHeight,0x45304810+1
        defadr get_system_langID,0x45308378+1
        defadr lang_get_name,0x452D7C44+1
        defadr w_chdir,0x455E40A4+1
        defadr w_fopen,0x44B24ABC+1
        defadr w_fstat,0x44B24B64+1
        defadr w_fwrite,0x44B24B10+1
        defadr w_fread,0x44B24AF4+1
        defadr w_lseek,0x4510A2B4+1
        defadr w_fclose,0x44B24B48+1
        defadr w_mkdir,0x455E5C10+1
        defadr DirHandle_SetFilterStr,0x455B2910+1
        defadr Disp_GetStrIdWidth,0x45308098+1
        defadr MetaData_Desc_GetCoverInfo,0x4496577C+1
        defadr ImageID_GetIndirect,0x45426D24+1
        defadr unixtime2datetime,0x4526C950+1
        defadr List_Insert,0x4527EFDC+1
        defadr FileCopy,0x455B4EC4+1
        defadr FileMove,0x455B5054+1
        defadr RedLED_On,0x44C687BC+1
        defadr RedLED_Off,0x44C68810+1
        defadr DispObject_SetLayerColor,0x453060C4+1
        defadr JavaAppDesc_GetJavaAppID,0x450240C8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x455CBD7C+1
        defadr JavaApp_LogoImageID_Get,0x4544A3B8+1
        defadr CreateProgressBar,0x45195890+1
        defadr ProgressBar_SetText,0x45195BC0+1
        defadr ProgressBar_SetIcon,0x45195CC8+1
        defadr ProgressBar_SetPercentValue,0x45195B78+1
        defadr ProgressBar_SetBarDisabled,0x45195CD8+1
        defadr StringInput_DispObject_SetText,0x452C42D0+1
        defadr GUIObject_SetTitleBackgroundImage,0x45171F18+1
        defadr GUIObject_SetTitleIcon,0x45193FA8+1
        defadr GUIObject_SetCursorImage,0x45171EF8+1
        defadr GUIObject_SetBackgroundImage,0x45171F08+1
        defadr DispObject_Softkeys_GetParams,0x45199E6C+1
        defadr DispObject_Softkeys_GetList,0x45199EB4+1
        defadr BookObj_GetDisplayOrientation,0x4529FDAC+1
        defadr BookObj_SetDisplayOrientation,0x4529FD80+1
        defadr Display_GetTopBook,0x4529F01C+1
        defadr Display_SetBrightness,0x45543600+1
        defadr Display_GetBrightness,0x45543644+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x4524A4A0+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x4524A518+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x4524A4F4+1
        defadr SetTheme,0x452B5124+1
        defadr Softkeys_GetLabel,0x45315308+1
        defadr Softkeys_Update,0x45314EBC+1
        defadr get_CellData,0x4C025610
        defadr IncommingCall_Reject,0x45206B90+1
        defadr IncommingCall_Mute,0x45207E10+1
        defadr GetRadioState,0x44C20CCC+1
        defadr Bluetooth_GetState,0x4559F10C+1
        defadr Bluetooth_GetPhoneVisibility,0x4559F0E8+1
        defadr Bluetooth_isBusy,0x4559F190+1
        defadr USB_isConnected,0x4554DAA8+1
        defadr w_diropen,0x455E5DC0+1
        defadr w_dirread,0x4510AA68+1
        defadr w_dirclose,0x455E603C+1
        defadr w_rename,0x4510A770+1
        defadr w_remove,0x4510A72C+1
        defadr ConnectionManager_Connection_GetState,0x451109CC+1
        defadr GetSignalQuality,0x44C20CDC+1
        defadr IsCameraBook,0x4545FF61
        defadr IsSoundRecorderBook,0x45076159
        defadr StringInput_MenuItem_SetPriority,0x451665CC+1
        defadr VideoPlayerControl,0x454468AC+1
        defadr Video_ActionBack,0x454462E8+1
        defadr Video_ExtractFrame,0x45447804+1
        defadr Video_SetPermit,0x45446558+1
        defadr Video_Refresh,0x45446198+1
        defadr Video_Play,0x45446370+1
        defadr Video_Pause,0x454464A0+1
        defadr Video_Stop,0x45446474+1
        defadr Audio_Pause,0x45431F74+1
        defadr Audio_Play,0x45431D20+1
        defadr CreatePercentInputVA,0x45195500+1
        defadr PercentInput_GetPercent,0x4519567C+1
        defadr GUIonMessage_SetLineSeparator,0x45171464+1
        defadr PHF_GetState,0x45536C7C+1
        defadr CHF_GetState,0x45536C88+1
        defadr SetTrayIcon,0x452AE758+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x4564C9C8+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x4564CCD0+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x4564CBB0+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x4564D198+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x4564CA8C+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x4564CF58+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x4501B2B0+1
        defadr SoundRecorderDesc_Create,0x45449EC0+1
        defadr SoundRecorderDesc_Destroy,0x45449EEC+1
        defadr SoundRecorderDesc_SetBookID,0x45449EFC+1
        defadr SoundRecorderDesc_SetType,0x45449F08+1
        defadr SoundRecorderDesc_SetFolder,0x45449F1C+1
        defadr SoundRecorderDesc_SetFname,0x45449F3C+1
        defadr SoundRecorderDesc_SetRecordSize,0x45449F58+1
        defadr SoundRecorder_Create,0x45449F84+1
        defadr SoundRecorder_RecordCall,0x4540B534+1
        defadr Browser_OpenURI,0x45420918+1
        defadr GetURIScheme,0x455292F8+1
        defadr CreateURI,0x45529740+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x4524A544+1
        defadr IrDa_GetState,0x45535C3C+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x4564CEF8+1
        defadr IncommingCall_Accept,0x45206A54+1
        defadr MediaPlayer_SoftKey_SetText,0x45074FE0+1
        defadr MediaPlayer_SoftKey_SetAction,0x45074FAC+1
        defadr MediaPlayer_SoftKey_SetItemAsSubItem,0x45075050+1
        defadr MediaPlayer_SoftKey_AddHelpStr,0x45074FFC+1
        defadr MediaPlayer_ShowNowPlaying,0x45257498+1
        defadr DispObject_Show,0x453027E0+1
        defadr Request_EventChannel_Subscribe,0x44CAEF0C+1
        defadr Request_ICA_ShutdownAllConnections,0x44CB9C08+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x4564D7A4+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x4524A5C8+1
        defadr GUIonMessage_GetMsg,0x45171378+1
        defadr GUIonMessage_GetBook,0x45171380+1
        defadr GUIonMessage_GetGui,0x4517137C+1
        defadr GUIonMessage_GetSelectedItem,0x45171384+1
        defadr GUIonMessage_GetPrevSelectedItem,0x45171394+1
        defadr ObexSendFile,0x44FD356C+1
        defadr Feedback_SetManualScrollingText,0x4530DFF4
        defadr EqualizerGain_Set,0x4545D578+1
        defadr CANVAS_Get_GviGC,0x44A4CAF0+1
        defadr GVI_BitBlt,0x44B3EE38+1
        defadr GVI_StretchBlt,0x44B3EFA8+1
        defadr GVI_TransformBlt,0x44B3F054+1
        defadr GVI_CreatePen,0x44B3E498+1
        defadr GVI_CreateDashedPen,0x44B3E4D4+1
        defadr GVI_CreateSolidBrush,0x44B3E424+1
        defadr GVI_Delete_GVI_Object,0x44B3DE80+1
        defadr GVI_DrawEllipse,0x44B3E968+1
        defadr GVI_DrawLine,0x44B3F4F0+1
        defadr GVI_DrawLines,0x44B3F988+1
        defadr GVI_DrawPolyLine,0x44B3FA10+1
        defadr GVI_DrawRectangle,0x44B3FBF8+1
        defadr GVI_DrawRoundRect,0x44B3ED2C+1
        defadr GVI_DrawSolidLines,0x44B3F5F4+1
        defadr GVI_DrawSolidPolyLine,0x44B3F7D0+1
        defadr GVI_DrawSolidRectangle,0x44B3F890+1
        defadr GVI_FillEllipse,0x44B3EBE4+1
        defadr GVI_FillPolygon,0x44B3F3EC+1
        defadr GVI_FillRectangle,0x44B3FB08+1
        defadr GVI_FillRectangles,0x44B3FB68+1
        defadr GVI_FillSolidEllipse,0x44B3EC7C+1
        defadr GVI_FillSolidRectangle,0x44B3FBB4+1
        defadr GVI_FillSolidRoundRect,0x44B3EE14+1
        defadr GVI_FillSolidTriangle,0x44B3F364+1
        defadr GC_CreateMemoryGC,0x45191AA4+1
        defadr GC_FreeGC,0x45191B58+1
        defadr REQUEST_ALARMCLOCKSTATUS_GET,0x45595768+1
        defadr REQUEST_ALARMCLOCKTIME_GET,0x455956F0+1
        defadr REQUEST_ALARMDATEANDTIMESTATUS_GET,0x45595A38+1
        defadr Settings_ShowNumber_Get,0x45415F8C+1
        defadr GVI_CreateBitmap,0x44B3E56C+1
        defadr GVI_CreateMemoryGC,0x44B3FCC8+1
        defadr GVI_DeleteMemoryGC,0x44B88884+1
        defadr StringInput_DispObject_SetLanguage,0x452C8510+1
        defadr List_InsertSorted,0x4527F110+1
        defadr ListMenu_SetItemIcon,0x45170B40+1
        defadr ListMenu_SetItemTextScroll,0x45171004+1
        defadr GUIObject_SetListTextColor,0x45171F28+1
        defadr DispObject_SetListTextColor,0x452E66F4+1
        defadr DispObject_SetCursorImage,0x452E6680+1
        defadr DispObject_SetBackgroundImage,0x452E669C+1
        defadr DispObject_SetTitleImage,0x452E66C4+1

        defadr FSX_IsFileExists,0x452510D8+1

        defadr SleepMode_OnCreate,0x452AB23C+1
        defadr SleepMode_OnClose,0x452AB338+1

        EXTERN  New_SleepMode_OnCreate
        EXTERN  New_SleepMode_OnClose
        EXTERN  New_SleepMode_OnRedraw

        RSEG    PATCH_SLEEPMODE_ONCREATE
        DATA
        DCD     New_SleepMode_OnCreate

        RSEG    PATCH_SLEEPMODE_ONCLOSE
        DATA
        DCD     New_SleepMode_OnClose

        RSEG    PATCH_SLEEPMODE_ONREDRAW
        DATA
        DCD     New_SleepMode_OnRedraw
        
        END
