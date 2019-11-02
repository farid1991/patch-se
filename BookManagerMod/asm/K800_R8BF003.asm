#ifdef K800_R8BF003

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
       
        defadr memalloc,0x44E4FD44+1
        defadr memfree,0x44E4FD70+1
        defadr memset,0x20003094
        defadr memcpy,0x443FCB18
        defadr sprintf,0x4467A294+1
        defadr snwprintf,0x4467A85C+1
        defadr _fopen,0x44F945F0+1
        defadr fclose,0x44F95BBC+1
        defadr fread,0x44F95E44+1
        defadr fwrite,0x44F96010+1
        defadr fstat,0x44F94F84+1
        defadr AllocDirHandle,0x44F925A4+1
        defadr GetFname,0x44F92764+1
        defadr DataBrowserDesc_Create,0x44FD1F28+1
        defadr DataBrowserDesc_SetItemStyle,0x44FD21F4+1
        defadr DataBrowserDesc_SetHeaderText,0x44FD222C+1
        defadr DataBrowserDesc_SetFolders,0x44FD2214+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x44FD2234+1
        defadr DataBrowser_Create,0x44FCE548+1
        defadr DataBrowserDesc_Destroy,0x44FD1FDC+1
        defadr getFileExtention,0x44F976D4+1
        defadr DataBrowser_isFileInListExt,0x44F929D0+1
        defadr Timer_ReSet,0x453AB5B4+1
        defadr Timer_Set,0x453AB580+1
        defadr Timer_Kill,0x453AB60C+1
        defadr CreateBook,0x453AE7D4+1
        defadr BookObj_KillBook,0x453AE8FC+1
        defadr BookObj_GotoPage,0x453AE550+1
        defadr BookObj_ReturnPage,0x453AE6B8+1
        defadr FreeBook,0x453AEDF0+1
        defadr FindBook,0x453ACE94+1
        defadr Find_StandbyBook,0x453C1D00+1
        defadr BookObj_SetFocus,0x453AEA80+1
        defadr GUIObject_SetTitleText,0x45464360+1
        defadr GUIObject_Show,0x45463EE4+1
        defadr ListMenu_SetCursorToItem,0x4541DAF0+1
        defadr GUIObject_SetStyle,0x45463F34+1
        defadr GUIonMessage_GetCreatedItemIndex,0x4541E5D8+1
        defadr GUIonMessage_SetMenuItemText,0x4541E5E4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x4541E614+1
        defadr GUIonMessage_SetMenuItemInfoText,0x4541E5F4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x4541E604+1
        defadr GUIonMessage_SetMenuItemIcon,0x4541E65C+1
        defadr DispObject_SetTitleText,0x45458D78+1
        defadr ListMenu_GetSelectedItem,0x4541DB04+1
        defadr ListMenu_SetItemStyle,0x4541DB54+1
        defadr GC_PutChar,0x45462238+1
        defadr isScreenSaverBook,0x454923A1
        defadr StatusIndication_SetItemText,0x45473998+1
        defadr StatusIndication_ShowNotes,0x453C3944+1
        defadr CreateStringInputVA,0x453F5C94+1
        defadr CreateOneOfMany,0x4541FA24+1
        defadr OneOfMany_SetItemCount,0x4541FBEC+1
        defadr OneOfMany_SetChecked,0x4541FC08+1
        defadr OneOfMany_SetTexts,0x4541FC3C+1
        defadr OneOfMany_GetSelected,0x4541FC18+1
        defadr StatusIndication_Item8_SetText,0x453C3874+1
        defadr GUIObject_SoftKeys_SetAction,0x454806E0+1
        defadr GUIObject_SoftKeys_SetText,0x45480758+1
        defadr GUIObject_SoftKeys_SetEnable,0x45480814+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x454807CC+1
        defadr GUIObject_SoftKeys_RemoveItem,0x454806A4+1
        defadr GUIObject_SoftKeys_SetVisible,0x454807A8+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x45480A18+1
        defadr wstrcpy,0x44F549A8+1
        defadr wstrncpy,0x44F549C0+1
        defadr wstrcat,0x44F549EC+1
        defadr wstrncat,0x44F54A08+1
        defadr wstrcmp,0x44F54978+1
        defadr wstrlen,0x44F54964+1
        defadr str2wstr,0x44F55C2C+1
        defadr strcmp,0x4467A640+1
        defadr strlen,0x4467A69C+1
        defadr wstr2strn,0x44F54A84+1
        defadr TextID_CreateIntegerID,0x4544678C+1
        defadr TextID_Create,0x45446A40+1
        defadr TextID_GetString,0x45446ED4+1
        defadr TextID_GetWString,0x45446DC4+1
        defadr TextID_GetLength,0x45446CA4+1
        defadr TextID_Destroy,0x45446C08+1
        defadr AB_DEFAULTNBR_GET,0x44EF4D0C+1
        defadr AB_READSTRING,0x44EF9CA4+1
        defadr AB_READPHONENBR,0x44EF9D70+1
        defadr AB_GETNBROFITEMS,0x44EF9E28+1
        defadr PNUM_len,0x454460B0+1
        defadr PNUM2str,0x4533E3F0+1
        defadr GUIObject_GetDispObject,0x45463CE4+1
        defadr List_Create,0x452BF5F0+1
        defadr List_Destroy,0x452BF62C+1
        defadr List_InsertFirst,0x452BF7A0+1
        defadr Gif2ID,0x44F4A3B0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x44F4DE88+1
        defadr REQUEST_DATEANDTIME_GET,0x44E562D0+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x4548F5C4+1
        defadr GetFreeBytesOnHeap,0x45087488+1
        defadr BookObj_Hide,0x453AEAA8+1
        defadr BookObj_Show,0x453AEAB8+1
        defadr StartAPP,0x453C1EBC+1
        defadr ListMenu_SetOnMessage,0x4541DC2C+1
        defadr manifest_GetParam,0x4537F700+1
        defadr lseek,0x44F961B8+1
        defadr get_VBUFFER,0x441424E3
        defadr SetLampLevel,0x4504F3F8+1
        defadr List_RemoveAt,0x452BF72C+1
        defadr GetCurrentPID,0x443ED2F0+1
        defadr List_IndexOf,0x452BF760+1
        defadr alloc,0x444359A8
        defadr receive,0x444359C4
        defadr send,0x444359B4
        defadr sender,0x44435A04
        defadr free_buf,0x444359D4
        defadr create_process,0x44435AA0
        defadr start,0x44435CC0
        defadr get_ptype,0x44435B70
        defadr current_process,0x44435ABC
        defadr delay,0x444359F4
        defadr hunt,0x44435BBC
        defadr kill_proc,0x44435BE8
        defadr stop,0x44435CD0
        defadr get_mem,0x44435B3C
        defadr strcpy,0x4467A668+1
        defadr CreateMessage,0x4510F218+1
        defadr SendMessage,0x4510F26C+1
        defadr WaitMessage,0x4510F2F4+1
        defadr FreeMessage,0x4510F308+1
        defadr SendDispatchMessage,0x450D66D0+1
        defadr UIEventName,0x453ABDB0+1
        defadr MissedEvents,0x2017040C
        defadr UI_Event,0x453AD25C+1
        defadr UI_Event_wData,0x453AD26C+1
        defadr UI_Event_toBookID,0x453AD2B4+1
        defadr UI_Event_toBookIDwData,0x453AD2C8+1
        defadr List_Find,0x452BF9C0+1
        defadr List_Get,0x452BF8C4+1
        defadr wstrrchr,0x4467B068+1
        defadr BookObj_CallSubroutine,0x453AE5C4+1
        defadr List_InsertLast,0x452BF7A8+1
        defadr debug_printf,0x4423F208+1
        defadr PlayFile,0x4511E26C+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x453E53A0+1
        defadr Profile_SetActive,0x453D6820+1
        defadr SetBrightnessOfScreen,0x453DDF84+1
        defadr isKeylocked,0x45492028+1
        defadr isMediaPlayerVideoBook,0x45059F39
        defadr ShuttingDown,0x453BDDC4+1
        defadr Vibra,0x450E0298+1
        defadr REQUEST_DATEFORMAT_GET,0x44E564B0+1
        defadr REQUEST_TIMEFORMAT_GET,0x44E56544+1
        defadr Date2ID,0x453AA754+1
        defadr Time2ID,0x453AA67C+1
        defadr CreateListMenu,0x4541D8E8+1
        defadr ListMenu_SetItemCount,0x4541DB18+1
        defadr ROOT_APP,0x2016AA84
        defadr GUIObject_SoftKeys_SetInfoText,0x45480744+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x45480838+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x453C48C8+1
        defadr REQUEST_SYSTEM_RESTART,0x453C48D8+1
        defadr GUIObject_SoftKeys_SetTexts,0x4548077C+1
        defadr IsRightNowBook,0x45489988+1
        defadr IsVolumeControllerBook,0x453C12DC+1
        defadr CreateTabMenuBar,0x45464C78+1
        defadr TabMenuBar_SetTabCount,0x45464D4C+1
        defadr TabMenuBar_SetTabGui,0x45464E00+1
        defadr TabMenuBar_SetTabIcon,0x45464E3C+1
        defadr GUIObject_Destroy,0x45463C74+1
        defadr GUIInput_SetIcon,0x45463FF0+1
        defadr StringInput_GetStringAndLen,0x453F6538+1
        defadr GetAudioControlPtr,0x20167890
        defadr AudioControl_Vibrate,0x44D6159C+1
        defadr GetVolumeSize,0x44F973F0+1
        defadr CreateNOfMany,0x4541F464+1
        defadr NOfMany_SetTexts,0x4541F6A4+1
        defadr NOfMany_SetChecked,0x4541F628+1
        defadr NOfMany_SetCursor,0x4541F5F0+1
        defadr NOfMany_GetCheckedCount,0x4541F64C+1
        defadr NOfMany_GetChecked,0x4541F63C+1
        defadr NOfMany_SetOnMessage,0x4541F69C+1
        defadr AudioControl_Init,0x4511E3BC+1
        defadr OneOfMany_SetFocused,0x4541FBD0+1
        defadr OneOfMany_SetOnMessage,0x4541FC34+1
        defadr CreateMonitorFeedback,0x453BCCF4+1
        defadr FeedBack_SetText,0x453BCDC0+1
        defadr GetBatteryState,0x44AF5378+1
        defadr get_DisplayGC,0x45461760+1
        defadr DispObject_GetRect,0x4545A1F4+1
        defadr GC_GetRect,0x45461E38+1
        defadr GC_GetXX,0x4546213C+1
        defadr GC_SetXX,0x45462130+1
        defadr GC_ValidateRect,0x45461DE8+1
        defadr BookObj_AddGUIObject,0x453AEB34+1
        defadr DrawRect,0x4545CA24+1
        defadr DrawString,0x4545CD24+1
        defadr XGUIList_AddGUIObject,0x453AF010+1
        defadr DispObject_InvalidateRect,0x4545A060+1
        defadr GUIObject_Create,0x45463B98+1
        defadr SetFont,0x4545D780+1
        defadr StatusRow_p,0x2016F844
        defadr root_list_get_session_count,0x453ACF94+1
        defadr root_list_get_session,0x453ACFA0+1
        defadr SESSION_GetTopBook,0x453AC89C+1
        defadr MainInput_getVisible,0x453BD150+1
        defadr MainInput_strlen,0x453BD15C+1
        defadr MainInput_getPNUM,0x453BD174+1
        defadr MainInput_isPlus,0x453BD180+1
        defadr BookObj_GetBookID,0x453AEEB0+1
        defadr wstrncmp,0x4467AFE0+1
        defadr DispObject_GetAbsoluteXPos,0x4545B1E4+1
        defadr DispObject_GetAbsoluteYPos,0x4545B218+1
        defadr DispObject_GetWindow,0x4545A510+1
        defadr GetThemeColor,0x45483290+1
        defadr REQUEST_SETTING_SILENCE_SET,0x453E4C78+1
        defadr REQUEST_SETTING_SILENCE_GET,0x453E4C20+1
        defadr VCALL_Init,0x44EECDB0+1
        defadr VCALL_SetName,0x44EECEA8+1
        defadr VCALL_SetNameIcon,0x44EECF08+1
        defadr VCALL_SetNumber,0x44EECEC8+1
        defadr VCALL_SetHZ1,0x44EECEEC+1
        defadr VCALL_SetHZ2,0x44EECEF8+1
        defadr MakeVoiceCall,0x44EEC908+1
        defadr isDirectory,0x441424E2+1
        defadr FileDelete,0x44F950C8+1
        defadr GUIObject_SetFocus,0x45463E90+1
        defadr CreateSMSCont,0x4513FF5C+1
        defadr FreeSMSCont,0x451405FC+1
        defadr PrepareSMSCont,0x45140134+1
        defadr CteateNewMessage,0x4514055C+1
        defadr get_APP_DESC_TABLE,0x45B8FAA0
        defadr Window_GetComponentInterface,0x45460E94+1
        defadr AB_POSITIONNBR_GET,0x44EFA000+1
        defadr AB_NAME_ITEM2TextID,0x44EF9F28+1
        defadr AB_NUM_ITEM2TextID,0x44EF9F70+1
        defadr GetABRecNum,0x44142572+1
        defadr get_AB_ITEMS_DESC,0x45B460EC
        defadr SBY_GetMainInput,0x44B9EBF8+1
        defadr SBY_GetStatusIndication,0x44B9EBF4+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x44E73E04+1
        defadr PID_MMI,0x20085BFC
        defadr DispObject_GetGUI,0x454599F0+1
        defadr Display_GetFocusedDispObject,0x45459940+1
        defadr DispObject_GetVisible,0x45459EF4+1
        defadr DispObject_GetDESC,0x44A1EC18+1
        defadr DISP_DESC_SetName,0x45455FA0+1
        defadr DispObject_GetName,0x4545AFA4+1
        defadr DISP_DESC_SetSize,0x45455FA4+1
        defadr DISP_DESC_SetOnCreate,0x45455FA8+1
        defadr DispObject_GetOnCreate,0x45456030+1
        defadr DISP_DESC_SetOnClose,0x45455FAC+1
        defadr DispObject_GetOnClose,0x4545604C+1
        defadr DISP_DESC_SetOnRedraw,0x45455FB0+1
        defadr DispObject_GetOnRedraw,0x45456068+1
        defadr DISP_DESC_SetOnKey,0x45455FB8+1
        defadr DispObject_GetOnKey,0x454560A0+1
        defadr DISP_DESC_SetOnRefresh,0x45455FB4+1
        defadr DispObject_GetonRefresh,0x45456084+1
        defadr DISP_DESC_SetMethod06,0x45455FBC+1
        defadr DispObject_GetMethod06,0x454560BC+1
        defadr DISP_DESC_SetOnLayout,0x45455FC4+1
        defadr DispObject_GetOnLayout,0x454560F4+1
        defadr DISP_DESC_SetOnConfig,0x454560F4+1
        defadr JavaSession_Manager,0x44F707FC+1
        defadr JavaSession_GetName,0x452DE98C+1
        defadr TextID_Copy,0x45446B70+1
        defadr BookObj_GetSession,0x453AEE50+1
        defadr GUIonMessage_SetNumberOfSubItems,0x4541E674+1
        defadr GUIonMessage_SubItem_SetText,0x4541E6EC+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x4541E6E0+1
        defadr GoMusic,0x45320684+1
        defadr Vibra_Off,0x450E036C+1
        defadr PlayFileV,0x4511E270+1
        defadr GetSilent,0x450DF76C+1
        defadr GetVibrator,0x450DCFA4+1
        defadr GetAudioSettings,0x450E05E4+1
        defadr GetChipID,0x4423DB64+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x4541E6D4+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x4541E6C8+1
        defadr DestroyDirHandle,0x44F928E0+1
        defadr LastExtDB,0x45B62488
        defadr GetOtherExtMethods,0x44FC88A4+1
        defadr MessageBox,0x453B9A08+1
        defadr Display_GetHeight,0x45476E80+1
        defadr Display_GetWidth,0x45476E8C+1
        defadr PlaySystemSound,0x4511E21C+1
        defadr TabMenuBar_GetFocusedTab,0x45464D40+1
        defadr TabMenuBar_SetFocusedTab,0x45464D30+1
        defadr GC_GetPenColor,0x45462044+1
        defadr GC_SetPenColor,0x45462008+1
        defadr GC_SetPixel,0x45461C48+1
        defadr GC_DrawLine,0x454627C0+1
        defadr GC_DrawFRect,0x4546294C+1
        defadr GC_WritePixels,0x45461D14+1
        defadr png_create_read_struct_2,0x44BF8368+1
        defadr png_destroy_read_struct,0x44BF84B4+1
        defadr png_create_info_struct,0x44BF6B0C+1
        defadr png_destroy_info_struct,0x44BF6B40+1
        defadr png_set_progressive_read_fn,0x44BF8340+1
        defadr png_process_data,0x44BF7300+1
        defadr png_read_update_info,0x44BF8488+1
        defadr png_get_progressive_ptr,0x44BF8364+1
        defadr png_get_IHDR,0x44BF6FC8+1
        defadr png_set_strip_16,0x44BF8654+1
        defadr png_set_gray_1_2_4_to_8,0x44BF8660+1
        defadr png_set_gray_to_rgb,0x44BF8684+1
        defadr png_get_valid,0x44BF6F9C+1
        defadr png_set_tRNS_to_alpha,0x44BF8678+1
        defadr png_set_filler,0x44BFB3BC+1
        defadr png_set_palette_to_rgb,0x44BF8660+1
        defadr png_get_rowbytes,0x44BF6FB4+1
        defadr png_progressive_combine_row,0x44BF8320+1
        defadr png_sig_cmp,0x44BF6A04+1
        defadr setjmp,0x44400E3C
        defadr longjmp,0x44400E60
        defadr inflateInit2_,0x44BFC020+1
        defadr inflate,0x44BFC1C0+1
        defadr inflateEnd,0x44BFD420+1
        defadr memcmp,0x2000310C
        defadr strncmp,0x4467A6D8+1
        defadr strncpy,0x4467A70C+1
        defadr strcat,0x4467A608+1
        defadr GUIObject_SetTitleType,0x45464344+1
        defadr GUIonMessage_SetItemDisabled,0x4541E680+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x44F4DEF0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x44F4DFA0+1
        defadr get_Surfaces,0x202E6CA0
        defadr iconidname2id,0x44D43994+1
        defadr textidname2id,0x44E4E220+1
        defadr ListMenu_SetNoItemText,0x4541DCBC+1
        defadr IsFmRadioBook,0x452125E4+1
        defadr IsAudioPlayerBook,0x4504031C+1
        defadr PlayerControl,0x4504568C+1
        defadr SwitchRadioStationFromList,0x4521080C+1
        defadr Shortcut_Run,0x4548D810+1
        defadr mkdir,0x44F91B2C+1
        defadr rmdir,0x44F92218+1
        defadr chmod,0x44F94FF8+1
        defadr rename,0x44F955E8+1
        defadr GetImageWidth,0x4545DD18+1
        defadr GetImageHeight,0x4545DD2C+1
        defadr CallID_GetCallStatusDesc,0x44EBCAE0+1
        defadr CallStatusDesc_GetName,0x44EBC104+1
        defadr List_DestroyElements,0x452BFA04+1
        defadr strstr,0x4467A7A4+1
        defadr GPRS_GetLastSessionInfo,0x454B4F9C+1
        defadr wstrcmpni,0x44F55D44+1
        defadr wtoi,0x453AAF50+1
        defadr DATE_GetWeekDay,0x4510FDD0+1
        defadr Cale_GetSettings,0x44E818C4+1
        defadr wstrwstr,0x4467B0A8+1
        defadr wstrcmpi,0x44F55D88+1
        defadr wstrchr,0x4467AF28+1
        defadr GUIObject_SoftKeys_Hide,0x45480A64+1
        defadr GUIObject_SoftKeys_Show,0x45480A70+1
        defadr DispObject_SoftKeys_Get,0x4547D820+1
        defadr StandbyBackground_SetImage,0x45452E0C+1
        defadr CreateYesNoQuestionVA,0x454747F0+1
        defadr ListMenu_SetSecondLineText,0x4541DECC+1
        defadr _REQUEST_OAF_START_APPLICATION,0x44FBBE54+1
        defadr FSX_isNameInvalid,0x44F971D8+1
        defadr DataBrowserDesc_SetFoldersNumber,0x44FD221C+1
        defadr DataBrowserDesc_SetActions,0x44FD21EC+1
        defadr DataBrowserDesc_SetSelectAction,0x44FD215C+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x44FD2164+1
        defadr DataBrowserDesc_SetBookID,0x44FD2138+1
        defadr DataBrowserDesc_SetItemFilter,0x44FD20E0+1
        defadr DataBrowserDesc_SetOption,0x44FD2254+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x44FD22E8+1
        defadr DataBrowserDesc_SetFileExtList,0x44FD20E8+1
        defadr FSX_RemoveIllegalSymbolsName,0x44FDC608+1
        defadr FILEITEM_Create,0x44FDBE70+1
        defadr FILEITEM_Destroy,0x44FDBF60+1
        defadr CreateDateInputVA,0x45472C20+1
        defadr CreateTimeInputVA,0x45474410+1
        defadr StringInput_SetCursorPosition,0x453F6584+1
        defadr BookObj_CallPage,0x453AE650+1
        defadr DateInput_GetDateInt,0x45472E24+1
        defadr TimeInput_GetTimeInt,0x45474658+1
        defadr GetFontDesc,0x2016FBAC
        defadr GetFontCount,0x2016FE40
        defadr GC_GetBrushColor,0x45462124+1
        defadr GC_SetBrushColor,0x454620E4+1
        defadr GC_DrawRoundRect,0x45462994+1
        defadr MenuBook_Desktop,0x45485218+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x454853A8+1
        defadr BookObj_SoftKeys_SetAction,0x4547B8CC+1
        defadr BookObj_SoftKeys_SetText,0x4547B904+1
        defadr FindBookByID,0x453ACE60+1
        defadr TextFeedbackWindow,0x45473C90+1
        defadr Feedback_SetKeyHook,0x454740C8+1
        defadr Feedback_SetOnClose,0x45474068+1
        defadr Feedback_SetTimeout,0x45473F88+1
        defadr Feedback_SetTextExtended,0x4547412C+1
        defadr TabMenuBar_SetOnTabSwitch,0x45464E94+1
        defadr KeyCode2Name,0x4513A730+1
        defadr ImageID_Get,0x44F495DC+1
        defadr ImageID_Free,0x44F495D0+1
        defadr DataBrowser_CreateSubExecute,0x44FBC744+1
        defadr DataBrowser_ExecuteSubroutine,0x44FBD164+1
        defadr FILEITEM_SetFname,0x44FDC05C+1
        defadr FILEITEM_SetPath,0x44FDC46C+1
        defadr FILEITEM_GetFname,0x44FDC464+1
        defadr FILEITEM_GetPath,0x44FDC518+1
        defadr FILEITEM_SetFnameAndContentType,0x44FDC0E4+1
        defadr FILEITEM_SetPathAndContentType,0x44FDC4F0+1
        defadr JavaDialog_Open,0x44FAA690+1
        defadr JavaDialog_Close,0x44FAE144+1
        defadr JavaAppDesc_Get,0x44FAE308+1
        defadr JavaAppDesc_GetFirstApp,0x44FA40A8+1
        defadr JavaAppDesc_GetNextApp,0x44FA40B0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x44FA3CC8+1
        defadr DispObject_SetRefreshTimer,0x45459B24+1
        defadr DispObject_KillRefreshTimer,0x45459BA4+1
        defadr isDataBrowserBook,0x44FCEE24+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x44FCA4A0+1
        defadr Shortcut_Get_MenuItemName,0x4548C448+1
        defadr Shortcut_Get_MenuItemIconID,0x454854C0+1
        defadr FindBookEx,0x453AE02C+1
        defadr FILEITEM_CreateCopy,0x44FDBEB0+1
        defadr ActionCreate,0x453ADF78+1
        defadr BookObj_GetSessionID,0x453AEDA0+1
        defadr UI_Event_toSID,0x453AD280+1
        defadr GetIMSI,0x44235CC8+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x453BDDE8+1
        defadr MainInput_getCurPos,0x453BD168+1
        defadr MainInput_Hide,0x453BD138+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x4547D0F8+1
        defadr PNUM2Name,0x44EE9534+1
        defadr SpeedDial_GetPNUM,0x44F06EEC+1
        defadr MetaData_Desc_Create,0x4533EA14+1
        defadr MetaData_Desc_Destroy,0x4533EAD4+1
        defadr MetaData_Desc_GetTags,0x4533EB14+1
        defadr MetaData_Desc_GetTrackNum,0x4533EB74+1
        defadr DispObject_GetWindowWidth,0x4545B164+1
        defadr DispObject_GetWindowHeight,0x4545B184+1
        defadr get_system_langID,0x453D3FBC+1
        defadr lang_get_name,0x45402A5C+1
        defadr w_chdir,0x45095030+1
        defadr w_fopen,0x4498B69C+1
        defadr w_fstat,0x4498B754+1
        defadr w_fwrite,0x4498B6E4+1
        defadr w_fread,0x4498B6CC+1
        defadr w_lseek,0x452BCFEC+1
        defadr w_fclose,0x4498B6FC+1
        defadr w_mkdir,0x45096FEC+1
        defadr DirHandle_SetFilterStr,0x44F92940+1
        defadr Disp_GetTextIDWidth,0x4545DDB4+1
        defadr MetaData_Desc_GetCoverInfo,0x4533EBC0+1
        defadr ImageID_GetIndirect,0x44F49800+1
        defadr unixtime2datetime,0x4510FBE8+1
        defadr List_Insert,0x452BF66C+1
        defadr FileCopy,0x44F953C4+1
        defadr FileMove,0x44F955E8+1
        defadr RedLED_On,0x4423CF8C+1
        defadr RedLED_Off,0x4423CFD8+1
        defadr DispObject_SetLayerColor,0x4545BEE4+1
        defadr JavaAppDesc_GetJavaAppID,0x44FAE264+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x4507F200+1
        defadr JavaApp_LogoImageID_Get,0x45074AE8+1
        defadr CreateProgressBar,0x454732EC+1
        defadr ProgressBar_SetText,0x45473634+1
        defadr ProgressBar_SetIcon,0x45473728+1
        defadr ProgressBar_SetPercentValue,0x454735F0+1
        defadr ProgressBar_SetBarDisabled,0x45473738+1
        defadr StringInput_DispObject_SetText,0x453EC3D8+1
        defadr GUIObject_SetTitleBackgroundImage,0x454643F0+1
        defadr GUIObject_SetTitleIcon,0x45464398+1
        defadr GUIObject_SetCursorImage,0x4541F108+1
        defadr GUIObject_SetBackgroundImage,0x4541F118+1
        defadr DispObject_SoftKeys_GetParams,0x4547E30C+1
        defadr DispObject_SoftKeys_GetList,0x4547E354+1
        defadr BookObj_GetDisplayOrientation,0x453AEFB8+1
        defadr BookObj_SetDisplayOrientation,0x453AEF14+1
        defadr Display_GetTopBook,0x453AE040+1
        defadr Display_SetBrightness,0x45465130+1
        defadr Display_GetBrightness,0x454651B0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x44FD2140+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x44FD21CC+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x44FD21D4+1
        defadr SetTheme,0x454816D4+1
        defadr SoftKeys_GetLabel,0x45480240+1
        defadr SoftKeys_Update,0x4547FE04+1
        defadr get_CellData,0x20184B70
        defadr IncommingCall_Reject,0x44EC4694+1
        defadr IncommingCall_Mute,0x44EC581C+1
        defadr GetRadioState,0x441B2BF8+1
        defadr Bluetooth_GetState,0x44E904E4+1
        defadr Bluetooth_GetPhoneVisibility,0x44E904AC+1
        defadr Bluetooth_isBusy,0x44E9056C+1
        defadr USB_isConnected,0x452D1C7C+1
        defadr w_diropen,0x450971A4+1
        defadr w_dirread,0x452BD6E8+1
        defadr w_dirclose,0x45097510+1
        defadr w_rename,0x452BD790+1
        defadr w_remove,0x452BD734+1
        defadr ConnectionManager_Connection_GetState,0x452D3DB8+1
        defadr GetSignalQuality,0x441B2C04+1
        defadr IsCameraBook,0x451288F1
        defadr IsSoundRecorderBook,0x450614B4+1
        defadr StringInput_MenuItem_SetPriority,0x453F6694+1
        defadr VideoPlayerControl,0x4505BF78+1
        defadr Video_ActionBack,0x4505B5F4+1
        defadr Video_ExtractFrame,0x4505CFC0+1
        defadr Video_ZoomOn,0x4505B9AC+1
        defadr RightNow_SetActive,0x4548A184+1
        defadr VideoResize_AutomateMode,0x4505B900+1
        defadr VideoResize_AllScreenMode,0x4505B898+1
        defadr Video_GetCurrentSkinID,0x4505C970+1
        defadr Video_SetSkin,0x45059CD4+1
        defadr Video_SetPermit,0x4505B828+1
        defadr Video_Refresh,0x4505B3C4+1
        defadr Video_Play,0x4505B674+1
        defadr Video_Pause,0x4505B7AC+1
        defadr Video_Stop,0x4505B778+1
        defadr Audio_Pause,0x45042404+1
        defadr Audio_Play,0x45042148+1
        defadr CreatePercentInputVA,0x45472F50+1
        defadr PercentInput_GetPercent,0x454730F0+1
        defadr GUIonMessage_SetLineSeparator,0x4541E698+1
        defadr PHF_GetState,0x453E6124+1
        defadr CHF_GetState,0x453E612C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x45480A7C+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x45480A88+1
        defadr SetTrayIcon,0x453C3B24+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x453E4828+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x453E4B18+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x453E4A18+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x453E4FB4+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x453E48E4+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x453E4D88+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x44FA3328+1
        defadr SoundRecorderDesc_Create,0x45060BD0+1
        defadr SoundRecorderDesc_Destroy,0x45060C48+1
        defadr SoundRecorderDesc_SetBookID,0x45060C70+1
        defadr SoundRecorderDesc_SetType,0x45060C7C+1
        defadr SoundRecorderDesc_SetFolder,0x45060C90+1
        defadr SoundRecorderDesc_SetFname,0x45060CAC+1
        defadr SoundRecorderDesc_SetRecordSize,0x45060CC8+1
        defadr SoundRecorder_Create,0x45060D00+1
        defadr SoundRecorder_RecordCall,0x44EB93FC+1
        defadr Browser_OpenURI,0x44F24C7C+1
        defadr GetURIScheme,0x4533D224+1
        defadr CreateURI,0x4533D6BC+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x44FD2204+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x44E5463C+1
        defadr Alarm_GetState,0x44E53190+1
        defadr Alarm_GetTIME,0x44E53FDC+1
        defadr Alarm_GetWeekSettings,0x44E54CD8+1
        defadr IrDa_GetState,0x453DC15C+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x453E4D2C+1
        defadr IncommingCall_Accept,0x44EC4554+1
        defadr MediaPlayer_SoftKeys_SetText,0x4503FDE8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x4503FDB4+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x4503FE74+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x4503FE04+1
        defadr MediaPlayer_ShowNowPlaying,0x4503F618+1
        defadr DispObject_Show,0x45459D74+1
        defadr Request_EventChannel_Subscribe,0x441DCECC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x45480A44+1
        defadr Request_ICA_ShutdownAllConnections,0x44970D28+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x453E54CC+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x44FD22F0+1
        defadr GUIonMessage_GetMsg,0x4541E5B4+1
        defadr GUIonMessage_GetBook,0x4541E5BC+1
        defadr GUIonMessage_GetGui,0x4541E5B8+1
        defadr GUIonMessage_GetSelectedItem,0x4541E5C0+1
        defadr GUIonMessage_GetPrevSelectedItem,0x4541E5CC+1
        defadr ObexSendFile,0x44EE60A4+1
        defadr Feedback_SetManualScrollingText,0x4546AD0C+1
        defadr EqualizerGain_Set,0x450D8364+1
        defadr CANVAS_Get_GviGC,0x44723EF8+1
        defadr GVI_BitBlt,0x44B1D4E8+1
        defadr GVI_StretchBlt,0x44B1D654+1
        defadr GVI_TransformBlt,0x44B1D708+1
        defadr GVI_CreatePen,0x44B1C70C+1
        defadr GVI_CreateDashedPen,0x44B1C75C+1
        defadr GVI_CreateSolidBrush,0x44B1C600+1
        defadr GVI_Delete_GVI_Object,0x44B1BFC0+1
        defadr GVI_DrawEllipse,0x44B1CDE0+1
        defadr GVI_DrawLine,0x44B1DCB4+1
        defadr GVI_DrawLines,0x44B1E3C0+1
        defadr GVI_DrawPolyLine,0x44B1E454+1
        defadr GVI_DrawRectangle,0x44B1E6D8+1
        defadr GVI_DrawRoundRect,0x44B1D320+1
        defadr GVI_DrawSolidLines,0x44B1DF74+1
        defadr GVI_DrawSolidPolyLine,0x44B1E190+1
        defadr GVI_DrawSolidRectangle,0x44B1E248+1
        defadr GVI_FillEllipse,0x44B1D1B8+1
        defadr GVI_FillPolygon,0x44B1DB28+1
        defadr GVI_FillRectangle,0x44B1E564+1
        defadr GVI_FillRectangles,0x44B1E5FC+1
        defadr GVI_FillSolidEllipse,0x44B1D284+1
        defadr GVI_FillSolidRectangle,0x44B1E674+1
        defadr GVI_FillSolidRoundRect,0x44B1D474+1
        defadr GVI_FillSolidTriangle,0x44B1DA98+1
        defadr GC_CreateMemoryGC,0x45461770+1
        defadr GC_FreeGC,0x45461848+1
        defadr Settings_ShowNumber_Get,0x44EE1020+1
        defadr GVI_CreateBitmap,0x44B1C840+1
        defadr GVI_CreateMemoryGC,0x44B1E880+1
        defadr GVI_DeleteMemoryGC,0x4485EB34+1
        defadr StringInput_DispObject_SetLanguage,0x453F05CC+1
        defadr GUIObject_SetTitleTextColor,0x454643E0+1
        defadr GUIObject_SetListTextColor,0x4541F128+1
        defadr DispObject_SetTitleTextColor,0x454590C0+1
        defadr DispObject_SetListTextColor,0x454109CC+1
        defadr DispObject_SetCursorImage,0x45410988+1
        defadr DispObject_SetBackgroundImage,0x454109A4+1
        defadr DispObject_SetTitleImage,0x454590E0+1
        defadr DispObject_SetScrollBarBackgroundColor,0x4545B468+1
        defadr DispObject_SetScrollBarColor,0x4545B444+1
        defadr DispObject_SetSoftkeysColor,0x4547D60C+1
        defadr ListMenu_DestroyItems,0x4541DFAC+1
        defadr ListMenu_SetItemTextScroll,0x4541E22C+1
        defadr get_envp,0x443ED0D0+1
        defadr set_envp,0x443ED0E4+1
        defadr get_bid,0x44435AF4
        
        defadr GetNewEvent,0x4548AE9C+1

//----------------------------------------------

        //RSEG   INTERNET
        ORG	0x454893DA
        CODE16
        ldr	r3, =_Internet
        bx	r3
        
        //RSEG   SHORTCURTS
	ORG	0x454893E4
        CODE16
        ldr	r3, =_Shortcurts
        bx	r3
        
        //RSEG   ACTIVETASKS
	ORG	0x454893EE
        CODE16
        ldr	r3, =_Activetasks
        bx	r3

        //RSEG   TAB_ICON_1
        //CODE16
        //ldr	r7, =_IconInternet
        //bx	r7
        
        //RSEG   TAB_ICON_2
        //DATA
        //DCD	0xF394
        
        RSEG   TAB_FOCUS
        CODE16
        ldr	r3, =_Tabfocus
        bx	r3
        
        RSEG   GUI_CREATE
        CODE16
        ldr	r3, =_onCreate
        bx	r3
        
        RSEG   BOOK_CLOSE
        CODE16
        ldr	r3, =_onClose
        bx	r3
        
        RSEG   EVENTS
        CODE16
        ldr	r3, =EventsTitleText
        bx	r3
        
//----------------------------------------------
      
        EXTERN SetFocusTab
        EXTERN CreateBookAndElfsLists
        EXTERN ActivityBook_onClose
        EXTERN EventsTitleText
        EXTERN CreateBookMenu
        EXTERN CreateElfMenu
        EXTERN CreateShortcutMenu

//----------------------------------------------
        RSEG   CODE
        CODE16
/*
_IconInternet:
        str	r3, [r0,#0x4]
        ldr	r1, =0xF39A
        strh	r1, [r0,#0x8]
        sub	r1, r1, #1
        strh	r1, [r0,#0xA]
        ldr	r1, =0xDB8
        str	r1, [r0,#0xC]
        pop	{r4,r5,pc}
*/
_Tabfocus:
        bl	SetFocusTab
        ADD	R1, R0, #0
	LDR     R0, [R5]
        ldr	r3, =0x45489770+1
        bx	r3

_onCreate:
	MOV	R1, #9
	ldr	r3, =GUIObject_SetStyle
        blx	r3
        ldr	r1, [r5]
        ldr	r0, [r5]
        bl	CreateBookAndElfsLists	// (BOOK* rn_bk, GUI* gui_tab)
        ldr	r1, =0x454892A0+1
        ldr	r0, [r5]
        ldr	r3, =TabMenuBar_SetOnTabSwitch
        blx	r3
        ldr	r3, =0x45489706+1
        bx	r3

_onClose:
        CMP     R5, #0
	BEQ     _close
	MOV	R0, #2
        ldr	r3, =0x4548A198+1
        blx	r3

  _close: 
	bl	ActivityBook_onClose
        pop	{r4-r7,pc}

_Internet:
        mov	r1, r5
        mov	r0, r4
        bl	CreateShortcutMenu	// (BOOK* book, int tab)
	LDR     R2, [R7,#0x14]
        ldr	r3, =0x454893F8+1
        bx	r3

_Shortcurts:
        mov	r1, r5
        mov	r0, r4
        bl	CreateElfMenu		// (BOOK* book, int tab)
	LDR     R2, [R7,#0x18]
        ldr	r3, =0x454893F8+1
        bx	r3

_Activetasks:
        mov	r1, r5
        mov	r0, r4
        bl	CreateBookMenu		// (BOOK* book, int tab)
	LDR     R2, [R7,#0x1C]
        ldr	r3, =0x454893F8+1
        bx	r3

#endif
        END