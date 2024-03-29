//W760_R3EF001

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010AC
        defadr memcpy,0x10147898
        defadr sprintf,0x10795DA0+1
        defadr snwprintf,0x10796254+1
        defadr _fopen,0x109F305C+1
        defadr fclose,0x117A7E94+1
        defadr fread,0x109F49F0+1
        defadr fwrite,0x109F4BBC+1
        defadr fstat,0x109F39C0+1
        defadr AllocDirHandle,0x109F0EAC+1
        defadr GetFname,0x109F107C+1
        defadr DataBrowserDesc_Create,0x1189A75C+1
        defadr DataBrowserDesc_SetStyle,0x10CE8E0C+1
        defadr DataBrowserDesc_SetHeaderText,0x1189AA0C+1
        defadr DataBrowserDesc_SetFolders,0x1189A9F4+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x1189AA14+1
        defadr DataBrowser_Create,0x118969A4+1
        defadr DataBrowserDesc_Destroy,0x1189A80C+1
        defadr getFileExtention,0x109F66CC+1
        defadr DataBrowser_isFileInListExt,0x109F12E0+1
        defadr Timer_ReSet,0x10E881FC+1
        defadr Timer_Set,0x10E881C8+1
        defadr Timer_Kill,0x10E88254+1
        defadr CreateBook,0x10E8BBE8+1
        defadr BookObj_KillBook,0x10E8BCFC+1
        defadr BookObj_GotoPage,0x10E8B8F8+1
        defadr BookObj_ReturnPage,0x10E8BAB0+1
        defadr FreeBook,0x10E8C268+1
        defadr FindBook,0x10E8B6B0+1
        defadr Find_StandbyBook,0x10E28C2C+1
        defadr BookObj_SetFocus,0x10E8BE98+1
        defadr GUIObject_SetTitleText,0x10A6D788+1
        defadr GUIObject_Show,0x10A6D574+1
        defadr ListMenu_SetCursorToItem,0x11B24D40+1
        defadr GUIObject_SetStyle,0x10A6D5CC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11B25914+1
        defadr GUIonMessage_SetMenuItemText,0x11B25920+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11B25950+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11B25930+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11B25940+1
        defadr GUIonMessage_SetMenuItemIcon,0x11B25960+1
        defadr DispObject_SetTitleText,0x10A628F8+1
        defadr ListMenu_GetSelectedItem,0x11B24D54+1
        defadr SetMenuItemStyle,0x11B24DA4+1
        defadr GC_PutChar,0x10A6BE0C+1
        defadr isScreenSaverBook,0x10983615
        defadr StatusIndication_SetItemText,0x10E281D0+1
        defadr StatusIndication_ShowNotes,0x10E29DD8+1
        defadr CreateStringInputVA,0x10931AD4+1
        defadr CreateOneOfMany,0x11B27118+1
        defadr OneOfMany_SetItemCount,0x11B272A4+1
        defadr OneOfMany_SetChecked,0x11B272C0+1
        defadr OneOfMany_SetTexts,0x11B272F4+1
        defadr OneOfMany_GetSelected,0x11B272D0+1
        defadr StatusIndication_Item8_SetText,0x10E29CE4+1
        defadr GUIObject_Softkey_SetAction,0x108ABE94+1
        defadr GUIObject_Softkey_SetText,0x108ABF0C+1
        defadr GUIObject_SoftKey_SetEnable,0x108ABFFC+1
        defadr GUIObject_SoftKey_AddErrorStr,0x108ABFB4+1
        defadr GUIObject_SoftKey_RemoveItem,0x108ABE48+1
        defadr GUIObject_SoftKeys_SetVisible,0x108ABF90+1
        defadr GUIObject_SoftKey_SuppressDefaultAction,0x108AC200+1
        defadr wstrcpy,0x10E01108+1
        defadr wstrncpy,0x10E01120+1
        defadr wstrcat,0x10796914+1
        defadr wstrncat,0x10E01168+1
        defadr wstrcmp,0x10E010D8+1
        defadr wstrlen,0x10E010C4+1
        defadr str2wstr,0x10E0238C+1
        defadr _strcmp,0x10796028+1
        defadr strlen,0x10796084+1
        defadr wstr2strn,0x10E011E4+1
        defadr int2strID,0x10FFF97C+1
        defadr Str2ID,0x10FFFB50+1
        defadr StrID2Str,0x1100025C+1
        defadr TextID2wstr,0x110000E4+1
        defadr TextGetLength,0x10FFFF94+1
        defadr TextFree,0x10FFFE8C+1
        defadr AB_DEFAULTNBR_GET,0x10BFFDD4+1
        defadr AB_READPHONENBR,0x10C061AC+1
        defadr AB_GETNBROFITEMS,0x10C06264+1
        defadr PNUM_len,0x10FFF150+1
        defadr PNUM2str,0x109D4044+1
        defadr GUIObject_GetDispObject,0x10A6D40C+1
        defadr List_Create,0x11B6B31C+1
        defadr List_Destroy,0x11B6B344+1
        defadr List_InsertFirst,0x11B6B490+1
        defadr REQUEST_DATEANDTIME_GET,0x1084B03C+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x10F02C30+1
        defadr GetFreeBytesOnHeap,0x4BB006F0
        defadr BookObj_Hide,0x10E8BEC0+1
        defadr BookObj_Show,0x10E8BED0+1
        defadr StartAPP,0x10E28E18+1
        defadr ListMenu_SetOnMessage,0x11B24E78+1
        defadr manifest_GetParam,0x10BA0D68+1
        defadr lseek,0x109F4D64+1
        defadr get_VBUFFER,0x1000592B
        defadr SetLampLevel,0x1000592A+1
        defadr List_RemoveAt,0x11B6B50C+1
        defadr GetCurrentPID,0x10005E58+1
        defadr List_IndexOf,0x11B6B450+1
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
        defadr strcpy,0x10796050+1
        defadr CreateMessage,0x10EAAB40+1
        defadr SendMessage,0x10EAAB94+1
        defadr WaitMessage,0x10EAAC1C+1
        defadr FreeMessage,0x10EAAC30+1
        defadr SendDispatchMessage,0x10C7412C+1
        defadr UIEventName,0x10E885E4+1
        defadr MissedEvents,0x4BB9E4A0
        defadr UI_Event,0x10E8A988+1
        defadr UI_Event_wData,0x10E8A998+1
        defadr UI_Event_toBookID,0x10E8A9E0+1
        defadr UI_Event_toBookIDwData,0x10E8A9F4+1
        defadr List_Find,0x11B6B5EC+1
        defadr List_Get,0x11B6B53C+1
        defadr wstrrchr,0x10E02448+1
        defadr BookObj_CallSubroutine,0x10E8B988+1
        defadr List_InsertLast,0x11B6B498+1
        defadr debug_printf,0x4BB3A2F0+1
        defadr PlayFile,0x11A87234+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11B42108+1
        defadr Profile_SetActive,0x11B72440+1
        defadr isKeylocked,0x10983400+1
        defadr isMediaPlayerVideoBook,0x10EAEE51
        defadr Vibra,0x11A8659C+1
        defadr REQUEST_DATEFORMAT_GET,0x1084B21C+1
        defadr REQUEST_TIMEFORMAT_GET,0x1084B300+1
        defadr Date2ID,0x11AFF824+1
        defadr Time2ID,0x11AFF740+1
        defadr CreateListMenu,0x11B24B54+1
        defadr ListMenu_SetItemCount,0x11B24D68+1
        defadr ROOT_APP,0x4BBAA8C8
        defadr GUIObject_Softkey_SetInfoText,0x108ABEF8+1
        defadr GUIObject_Softkey_SetItemAsSubItem,0x108AC030+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11B02DE8+1
        defadr REQUEST_SYSTEM_RESTART,0x11B02DF8+1
        defadr GUIObject_Softkey_SetTexts,0x108ABF64+1
        defadr isRightNowBook,0x10BCDB84+1
        defadr isVolumeControllerBook,0x11B5E858+1
        defadr CreateTabMenuBar,0x11822C80+1
        defadr TabMenuBar_SetTabCount,0x11822ED8+1
        defadr TabMenuBar_SetTabGui,0x11822D50+1
        defadr TabMenuBar_SetTabIcon,0x11822DD0+1
        defadr GUIObject_Destroy,0x10A6D380+1
        defadr GUIInput_SetIcon,0x10A6D648+1
        defadr StringInput_GetStringAndLen,0x10932384+1
        defadr GetAudioControlPtr,0x4BBC7A0C
        defadr AudioControl_Vibrate,0x115F2DD8+1
        defadr GetVolumeSize,0x109F63E4+1
        defadr CreateNOfMany,0x11B26B24+1
        defadr NOfMany_SetTexts,0x11B26D28+1
        defadr NOfMany_SetChecked,0x11B26CAC+1
        defadr NOfMany_SetCursor,0x11B26C74+1
        defadr NOfMany_GetCheckedCount,0x11B26CD0+1
        defadr NOfMany_GetChecked,0x11B26CC0+1
        defadr NOfMany_SetOnMessage,0x11B26D20+1
        defadr AudioControl_Init,0x11A87380+1
        defadr OneOfMany_SetFocused,0x11B27288+1
        defadr OneOfMany_SetOnMessage,0x11B272EC+1
        defadr CreateMonitorFeedback,0x11AFE408+1
        defadr FeedBack_SetText,0x11AFE4C0+1
        defadr GetBatteryState,0x1111FC20+1
        defadr get_DisplayGC,0x10A6B3D0+1
        defadr DispObject_GetRect,0x10A63FC8+1
        defadr GC_GetRect,0x10A6BA14+1
        defadr GC_GetXX,0x10A6BD10+1
        defadr GC_SetXX,0x10A6BD04+1
        defadr GC_ValidateRect,0x10A6B9C4+1
        defadr BookObj_AddGUIObject,0x10E8BF78+1
        defadr DrawRect,0x10A6711C+1
        defadr DrawString,0x10A67468+1
        defadr XGUIList_AddGUIObject,0x10E8C478+1
        defadr InvalidateRect,0x10A63D58+1
        defadr GUIObject_Create,0x10A6D1BC+1
        defadr SetFont,0x10A68028+1
        defadr StatusRow_p,0x4BBC5C78
        defadr root_list_get_session_count,0x10E89F20+1
        defadr root_list_get_session,0x10E89F30+1
        defadr SESSION_GetTopBook,0x10E89700+1
        defadr BookObj_GetBookID,0x10E8C354+1
        defadr wstrncmp,0x107969E8+1
        defadr DispObject_GetAbsoluteXPos,0x10A651CC+1
        defadr DispObject_GetAbsoluteYPos,0x10A65200+1
        defadr DispObject_GetWindow,0x10A642DC+1
        defadr GetThemeColor,0x10EFAD4C+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11B41B3C+1
        defadr REQUEST_SETTING_SILENCE_GET,0x11B41AE4+1
        defadr VCALL_Init,0x10BF4014+1
        defadr VCALL_SetName,0x10BF410C+1
        defadr VCALL_SetNameIcon,0x10BF416C+1
        defadr VCALL_SetNumber,0x10BF412C+1
        defadr VCALL_SetHZ1,0x10BF4150+1
        defadr VCALL_SetHZ2,0x10BF415C+1
        defadr MakeVoiceCall,0x10BF3BAC+1
        defadr FileDelete,0x109F3C50+1
        defadr GUIObject_SetFocus,0x10A6D538+1
        defadr CreateSMSCont,0x11AB54F4+1
        defadr FreeSMSCont,0x11AB5C38+1
        defadr PrepareSMSCont,0x11AB56D4+1
        defadr CteateNewMessage,0x11AB5B60+1
        defadr get_APP_DESC_TABLE,0x11C2361C
        defadr Window_GetComponentInterface,0x10A6AD7C+1
        defadr AB_POSITIONNBR_GET,0x10C06450+1
        defadr AB_NAME_ITEM2StrID,0x10C06364+1
        defadr AB_NUM_ITEM2StrID,0x10C063C8+1
        defadr GetABRecNum,0x10C0644C+1
        defadr get_AB_ITEMS_DESC,0x11C0BAF0
        defadr SBY_GetMainInput,0x10942F5C+1
        defadr SBY_GetStatusIndication,0x108072E8+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10AEB924+1
        defadr PID_MMI,0x4BBA8F04
        defadr Display_GetFocusedDispObject,0x10A63588+1
        defadr DispObject_GetVisible,0x10A63BFC+1
        defadr DispObject_GetDESC,0x10014E98+1
        defadr DISP_DESC_SetName,0x10A60838+1
        defadr DispObject_GetName,0x10A64F24+1
        defadr DISP_DESC_SetSize,0x10A6083C+1
        defadr DISP_DESC_SetOnCreate,0x10A60840+1
        defadr DispObject_GetOnCreate,0x10A608BC+1
        defadr DISP_DESC_SetOnClose,0x10A60844+1
        defadr DispObject_GetOnClose,0x10A608D8+1
        defadr DISP_DESC_SetOnRedraw,0x10A60848+1
        defadr DispObject_GetOnRedraw,0x10A608F4+1
        defadr DISP_DESC_SetOnKey,0x10A60850+1
        defadr DispObject_GetOnKey,0x10A6092C+1
        defadr DISP_DESC_SetonRefresh,0x10A6084C+1
        defadr DispObject_GetonRefresh,0x10A60910+1
        defadr DISP_DESC_SetMethod06,0x10A60854+1
        defadr DispObject_GetMethod06,0x10A60948+1
        defadr DISP_DESC_SetOnLayout,0x10A6085C+1
        defadr DispObject_GetOnLayout,0x10A60980+1
        defadr JavaSession_GetName,0x1000592A+1
        defadr TextCopyId,0x10FFFD30+1
        defadr BookObj_GetSession,0x10E8C2B4+1
        defadr GUIonMessage_SetItemAsSubitem,0x11B259BC+1
        defadr GUIonMessage_SetSubitemText,0x11B25A28+1
        defadr GUIonMessage_GetCreatedSubItemParrentIndex,0x11B25A1C+1
        defadr GoMusic,0x10EC239C+1
        defadr Vibra_Off,0x11A86670+1
        defadr PlayFileV,0x11A87238+1
        defadr GetSilent,0x11A85708+1
        defadr GetVibrator,0x11A811D0+1
        defadr GetAudioSettings,0x11A86A0C+1
        defadr GetChipID,0x126D8D3C+1
        defadr GUIonMessage_GetCurrentSubItem,0x11B25A10+1
        defadr GUIonMessage_GetCurrentItemIndex,0x11B25A04+1
        defadr DestroyDirHandle,0x109F11F8+1
        defadr LastExtDB,0x11EF9A90
        defadr GetOtherExtMethods,0x118908BC+1
        defadr MessageBox,0x11AFC9C4+1
        defadr Display_GetHeight,0x118252F0+1
        defadr Display_GetWidth,0x118252FC+1
        defadr PlaySystemSound,0x11A871DC+1
        defadr TabMenuBar_GetFocusedTab,0x11822D44+1
        defadr TabMenuBar_SetFocusedTab,0x11822D34+1
        defadr GC_GetPenColor,0x10A6BC1C+1
        defadr GC_SetPenColor,0x10A6BBE0+1
        defadr GC_SetPixel,0x10A6B864+1
        defadr GC_DrawLine,0x10A6C360+1
        defadr GC_DrawFRect,0x10A6C4EC+1
        defadr GC_WritePixels,0x10A6B8EC+1
        defadr png_create_read_struct_2,0x118CF1EC+1
        defadr png_destroy_read_struct,0x118CF338+1
        defadr png_create_info_struct,0x118CD994+1
        defadr png_destroy_info_struct,0x118CD9C8+1
        defadr png_set_progressive_read_fn,0x118CF1C4+1
        defadr png_process_data,0x118CE184+1
        defadr png_read_update_info,0x118CF30C+1
        defadr png_get_progressive_ptr,0x118CF1E8+1
        defadr png_get_IHDR,0x118CDE50+1
        defadr png_set_strip_16,0x118CF4D8+1
        defadr png_set_gray_1_2_4_to_8,0x118CF4E4+1
        defadr png_set_gray_to_rgb,0x118CF508+1
        defadr png_get_valid,0x118CDE24+1
        defadr png_set_tRNS_to_alpha,0x118CF4FC+1
        defadr png_set_filler,0x118D226C+1
        defadr png_set_palette_to_rgb,0x118CF4F0+1
        defadr png_get_rowbytes,0x118CDE3C+1
        defadr png_progressive_combine_row,0x118CF1A4+1
        defadr png_sig_cmp,0x118CD88C+1
        defadr setjmp,0x1014BB34
        defadr longjmp,0x1014BB58
        defadr inflateInit2_,0x118D2F40+1
        defadr inflate,0x118D30E8+1
        defadr inflateEnd,0x118D43E0+1
        defadr memcmp,0x126D7AC0
        defadr strncmp,0x107960C0+1
        defadr strncpy,0x107960F4+1
        defadr strcat,0x10795FF0+1
        defadr GUIObject_SetTitleType,0x10A6D76C+1
        defadr GUIonMessage_SetItemDisabled,0x11B259C8+1
        defadr get_Surfaces,0x4BD84334
        defadr iconidname2id,0x115BE574+1
        defadr textidname2id,0x117A7CFC+1
        defadr ListMenu_SetNoItemText,0x11B24EF8+1
        defadr isFmRadioBook,0x11045645
        defadr isAudioPlayerBook,0x10D21F0D
        defadr SwitchRadioStationFromList,0x11043580+1
        defadr Shortcut_Run,0x10E78160+1
        defadr mkdir,0x109F05D8+1
        defadr rmdir,0x109F09CC+1
        defadr chmod,0x109F3B7C+1
        defadr rename,0x109F41A4+1
        defadr GetImageWidth,0x10A68700+1
        defadr GetImageHeight,0x10A68714+1
        defadr CallID_GetCallStatusDesc,0x10E9C954+1
        defadr CallStatusDesc_GetName,0x10E9BF8C+1
        defadr List_DestroyElements,0x11B6B630+1
        defadr strstr,0x10796190+1
        defadr GPRS_GetLastSessionInfo,0x1089E53C+1
        defadr wstrcmpni,0x10E024E4+1
        defadr wtoi,0x10E87C28+1
        defadr DATE_GetWeekDay,0x10C68970+1
        defadr Cale_GetSettings,0x109C0448+1
        defadr wstrwstr,0x10796B48+1
        defadr wstrcmpi,0x10E02528+1
        defadr wstrchr,0x10796930+1
        defadr GUIObject_HideSoftkeys,0x108AC24C+1
        defadr GUIObject_ShowSoftkeys,0x108AC258+1
        defadr DispObject_SoftKeys_Get,0x108A8614+1
        defadr StandbyBackground_SetImage,0x10EF95C0+1
        defadr CreateYesNoQuestionVA,0x11824BA4+1
        defadr ListMenu_SetSecondLineText,0x11B2511C+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10BC6800+1
        defadr FSX_isNameInvalid,0x109F61D4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x1189A9FC+1
        defadr DataBrowserDesc_SetActions,0x1189A9B0+1
        defadr DataBrowserDesc_SetSelectAction,0x1189A978+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x1189A980+1
        defadr DataBrowserDesc_SetBookID,0x1189A95C+1
        defadr DataBrowserDesc_SetItemFilter,0x1189A900+1
        defadr DataBrowserDesc_SetOption,0x1189AA2C+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x1189AA94+1
        defadr DataBrowserDesc_SetFileExtList,0x1189A908+1
        defadr FSX_RemoveIllegalSymbolsName,0x118A4178+1
        defadr FILEITEM_Create,0x118A3B90+1
        defadr FILEITEM_Destroy,0x118A3CC0+1
        defadr CreateDateInputVA,0x1182300C+1
        defadr CreateTimeInputVA,0x1182477C+1
        defadr StringInput_SetCursorPosition,0x109323D0+1
        defadr BookObj_CallPage,0x10E8BA2C+1
        defadr DateInput_GetDateInt,0x1182327C+1
        defadr TimeInput_GetTimeInt,0x11824A44+1
        defadr GetFontDesc,0x4BBA2584
        defadr GetFontCount,0x4BBA28F4
        defadr GC_GetBrushColor,0x10A6BCF8+1
        defadr GC_SetBrushColor,0x10A6BCB8+1
        defadr GC_DrawRoundRect,0x10A6C534+1
        defadr MenuBook_Desktop,0x10E77914+1
        defadr BookObj_Softkey_SetAction,0x108A64D4+1
        defadr BookObj_Softkey_SetText,0x108A650C+1
        defadr FindBookByID,0x10E89DEC+1
        defadr TextFeedbackWindow,0x11823FE0+1
        defadr Feedback_SetKeyHook,0x118243EC+1
        defadr Feedback_SetOnClose,0x11824388+1
        defadr Feedback_SetTimeout,0x118243B8+1
        defadr Feedback_SetTextExtended,0x11824450+1
        defadr TabMenuBar_SetOnTabSwitch,0x11822E2C+1
        defadr KeyCode2Name,0x1104A454+1
        defadr ImageID_Get,0x1083EFD8+1
        defadr ImageID_Free,0x108451F0+1
        defadr DataBrowser_CreateSubExecute,0x118836C4+1
        defadr DataBrowser_ExecuteSubroutine,0x118840E4+1
        defadr FILEITEM_SetFname,0x118A3D6C+1
        defadr FILEITEM_SetPath,0x118A402C+1
        defadr FILEITEM_GetFname,0x118A4024+1
        defadr FILEITEM_GetPath,0x118A40B8+1
        defadr FILEITEM_SetFnameAndContentType,0x118A3DCC+1
        defadr FILEITEM_SetPathAndContentType,0x118A4090+1
        defadr JavaDialog_Open,0x10BAECF8+1
        defadr JavaDialog_Close,0x10BB244C+1
        defadr JavaAppDesc_Get,0x10BB2618+1
        defadr JavaAppDesc_GetFirstApp,0x10BA468C+1
        defadr JavaAppDesc_GetNextApp,0x10BA4694+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10BA4158+1
        defadr DispObject_SetRefreshTimer,0x10A637C0+1
        defadr DispObject_KillRefreshTimer,0x10A6383C+1
        defadr isDataBrowserBook,0x118972B4+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x1189294C+1
        defadr Shortcut_Get_MenuItemName,0x10BCF6DC+1
        defadr Shortcut_Get_MenuItemIconID,0x10E77B38+1
        defadr FindBookEx,0x10E89E80+1
        defadr FILEITEM_CreateCopy,0x118A3BC0+1
        defadr ActionCreate,0x10E8B610+1
        defadr BookObj_GetSessionID,0x10E8C1DC+1
        defadr UI_Event_toSID,0x10E8A9AC+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11AFEE98+1
        defadr DispObject_SoftKey_RestoreDefaultAction,0x108A7FF4+1
        defadr PNUM2Name,0x10BEF244+1
        defadr SpeedDial_GetPNUM,0x10C16774+1
        defadr DispObject_GetWindowWidth,0x10A6514C+1
        defadr DispObject_GetWindowHeight,0x10A6516C+1
        defadr get_system_langID,0x10E53BF4+1
        defadr lang_get_name,0x11B2DE88+1
        defadr w_chdir,0x4BB003AC
        defadr w_fopen,0x1133491C+1
        defadr w_fstat,0x113349D4+1
        defadr w_fwrite,0x11334964+1
        defadr w_fread,0x1133494C+1
        defadr w_lseek,0x11AF77BC+1
        defadr w_fclose,0x1133497C+1
        defadr w_mkdir,0x4BB00344
        defadr DirHandle_SetFilterStr,0x109F1250+1
        defadr Disp_GetStrIdWidth,0x10A687B4+1
        defadr ImageID_GetIndirect,0x1083F070+1
        defadr unixtime2datetime,0x10C68788+1
        defadr List_Insert,0x11B6B36C+1
        defadr FileCopy,0x109F3F58+1
        defadr FileMove,0x109F41A4+1
        defadr DispObject_SetLayerColor,0x10A65F50+1
        defadr JavaAppDesc_GetJavaAppID,0x10BB2574+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10CD68C4+1
        defadr JavaApp_LogoImageID_Get,0x10CCB0F4+1
        defadr CreateProgressBar,0x11823740+1
        defadr ProgressBar_SetText,0x11823A38+1
        defadr ProgressBar_SetIcon,0x11823BAC+1
        defadr ProgressBar_SetPercentValue,0x118239F4+1
        defadr ProgressBar_SetBarDisabled,0x11823BCC+1
        defadr StringInput_DispObject_SetText,0x10926C3C+1
        defadr DispObject_Softkeys_GetParams,0x108A92C4+1
        defadr DispObject_Softkeys_GetList,0x108A9308+1
        defadr BookObj_GetDisplayOrientation,0x10E8C3F0+1
        defadr BookObj_SetDisplayOrientation,0x10E8C38C+1
        defadr Display_GetTopBook,0x10E8B6CC+1
        defadr Display_SetBrightness,0x10E5CACC+1
        defadr Display_GetBrightness,0x10E5CB04+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x1189A964+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x1189A9C0+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1189A9C8+1
        defadr SetTheme,0x10EA8700+1
        defadr Softkeys_GetLabel,0x108AB800+1
        defadr Softkeys_Update,0x108AB3B8+1
        defadr IncommingCall_Reject,0x10EA5BAC+1
        defadr IncommingCall_Mute,0x10EA6EEC+1
        defadr Bluetooth_GetState,0x10AFF804+1
        defadr Bluetooth_GetPhoneVisibility,0x10AFF7C8+1
        defadr Bluetooth_isBusy,0x10AFF894+1
        defadr USB_isConnected,0x10A57524+1
        defadr w_diropen,0x4BB00354
        defadr w_dirread,0x11AF7E4C+1
        defadr w_dirclose,0x4BB0038C
        defadr w_rename,0x11AF7EE8+1
        defadr w_remove,0x11AF7E9C+1
        defadr ConnectionManager_Connection_GetState,0x10CBFC94+1
        defadr isCameraBook,0x10964FAD
        defadr isSoundRecorderBook,0x10EE6F41
        defadr StringInput_MenuItem_SetPriority,0x109324D8+1
        defadr CreatePercentInputVA,0x118233AC+1
        defadr PercentInput_GetPercent,0x11823538+1
        defadr GUIonMessage_SetLineSeparator,0x11B259E0+1
        defadr PHF_GetState,0x10AB408C+1
        defadr CHF_GetState,0x10AB4094+1
        defadr GUIObject_Softkeys_RemoveBackground,0x108AC264+1
        defadr GUIObject_Softkeys_RestoreBackground,0x108AC270+1
        defadr SetTrayIcon,0x118278C0+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11B417E4+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x11B419D8+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x11B41954+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11B41DBC+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x11B418EC+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x11B41BE4+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10BA3738+1
        defadr SoundRecorderDesc_Create,0x10EE63EC+1
        defadr SoundRecorderDesc_Destroy,0x10EE6448+1
        defadr SoundRecorderDesc_SetBookID,0x10EE6464+1
        defadr SoundRecorderDesc_SetType,0x10EE6490+1
        defadr SoundRecorderDesc_SetFolder,0x10EE64A4+1
        defadr SoundRecorderDesc_SetFname,0x10EE64C0+1
        defadr SoundRecorderDesc_SetRecordSize,0x10EE64DC+1
        defadr SoundRecorder_Create,0x10EE6554+1
        defadr SoundRecorder_RecordCall,0x10E98EC0+1
        defadr Browser_OpenURI,0x1081A68C+1
        defadr GetURIScheme,0x10EAC2C0+1
        defadr CreateURI,0x10EAC75C+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x1189A9E4+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x10847AA0+1
        defadr Alarm_GetState,0x108462D0+1
        defadr Alarm_GetTIME,0x108472AC+1
        defadr Alarm_GetWeekSettings,0x108481E4+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11B41B88+1
        defadr IncommingCall_Accept,0x10EA5A70+1
        defadr DispObject_Show,0x10A63A78+1
        defadr Request_EventChannel_Subscribe,0x12716A24+1
        defadr GUIObject_Softkey_ExecuteAction,0x108AC22C+1
        defadr Request_ICA_ShutdownAllConnections,0x1153AD88+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11B42250+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1189AA9C+1
        defadr GUIonMessage_GetMsg,0x11B258F0+1
        defadr GUIonMessage_GetBook,0x11B258F8+1
        defadr GUIonMessage_GetGui,0x11B258F4+1
        defadr GUIonMessage_GetSelectedItem,0x11B258FC+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11B25908+1
        defadr ObexSendFile,0x1093E0F8+1
        defadr Feedback_SetManualScrollingText,0x1181ED78+1
        defadr EqualizerGain_Set,0x11A84134+1
        defadr CANVAS_Get_GviGC,0x11475494+1
        defadr GVI_BitBlt,0x111DC2A4+1
        defadr GVI_StretchBlt,0x111DC418+1
        defadr GVI_TransformBlt,0x111DC4D4+1
        defadr GVI_CreatePen,0x111DB54C+1
        defadr GVI_CreateDashedPen,0x111DB590+1
        defadr GVI_CreateSolidBrush,0x111DB45C+1
        defadr GVI_Delete_GVI_Object,0x111DAE2C+1
        defadr GVI_DrawEllipse,0x111DBBDC+1
        defadr GVI_DrawLine,0x111DCAC8+1
        defadr GVI_DrawLines,0x111DD158+1
        defadr GVI_DrawPolyLine,0x111DD1DC+1
        defadr GVI_DrawRectangle,0x111DD458+1
        defadr GVI_DrawRoundRect,0x111DC0F8+1
        defadr GVI_DrawSolidLines,0x111DCD1C+1
        defadr GVI_DrawSolidPolyLine,0x111DCF24+1
        defadr GVI_DrawSolidRectangle,0x111DCFC8+1
        defadr GVI_FillEllipse,0x111DBFC4+1
        defadr GVI_FillPolygon,0x111DC980+1
        defadr GVI_FillRectangle,0x111DD2D8+1
        defadr GVI_FillRectangles,0x111DD364+1
        defadr GVI_FillSolidEllipse,0x111DC070+1
        defadr GVI_FillSolidRectangle,0x111DCB58+1
        defadr GVI_FillSolidRoundRect,0x111DC248+1
        defadr GVI_FillSolidTriangle,0x111DC90C+1
        defadr GC_CreateMemoryGC,0x10A6B3E0+1
        defadr GC_FreeGC,0x10A6B4A8+1
        defadr Settings_ShowNumber_Get,0x11060E24+1
        defadr List_InsertSorted,0x11B6B4B4+1
        defadr ListMenu_SetItemIcon,0x11B25050+1
        defadr wstrnupr,0x10E01194+1
        defadr wstrnlwr,0x10B6CCB0+1
        defadr ListMenu_SetItemTextScroll,0x11B25448+1
        defadr TabMenuBar_SetTabTitle,0x11822E18+1
        defadr GUIObject_GetBook,0x10A6D420+1
        defadr Softkeys_GetSelectedAction,0x108A7F24+1
        defadr MonitorFeedback_SetTimer,0x11AFE4B4+1
        defadr ListMenu_DestroyItems,0x11B251C0+1
        
        defadr ListMenu_DestroyItems,0x1
        defadr GUIObject_SoftKeys_SetVisible,0x1
        defadr REQUEST_DATEANDTIME_GET,0x1
        defadr DATE_GetWeekDay,0x1
//////////////////

        defadr GetOperatorName,0x1105E048+1
        defadr DISP_OBJ_StatusIndication_SetItemText,0x10E2569C+1

        EXTERN  OnSetText
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
        
        END
        