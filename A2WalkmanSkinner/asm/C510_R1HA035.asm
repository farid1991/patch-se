//C510_R1HA035

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
        defadr memalloc,0x4BA32698
        defadr memfree,0x4BA326C0
        defadr memset,0x14B31C80
        defadr memcpy,0x1428AD94
        defadr sprintf,0x14405D14+1
        defadr snwprintf,0x143EEBC4+1
        defadr _fopen,0x141FA214+1
        defadr fclose,0x143CD0A0+1
        defadr fread,0x14178B8C+1
        defadr fwrite,0x143326C8+1
        defadr fstat,0x144D8BBC+1
        defadr AllocDirHandle,0x14177B2C+1
        defadr GetFname,0x141787E0+1
        defadr DataBrowserDesc_Create,0x142DB880+1
        defadr DataBrowserDesc_SetItemStyle,0x1416796C+1
        defadr DataBrowserDesc_SetHeaderText,0x1423743C+1
        defadr DataBrowserDesc_SetFolders,0x14259B2C+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x142996A8+1
        defadr DataBrowser_Create,0x14FC2290+1
        defadr DataBrowserDesc_Destroy,0x14167908+1
        defadr getFileExtention,0x144D94F8+1
        defadr DataBrowser_isFileInListExt,0x1441D5EC+1
        defadr Timer_ReSet,0x1417A1C4+1
        defadr Timer_Set,0x1449FF70+1
        defadr Timer_Kill,0x1417A7F0+1
        defadr CreateBook,0x142866FC+1
        defadr BookObj_KillBook,0x14481D3C+1
        defadr BookObj_GotoPage,0x14481B20+1
        defadr BookObj_ReturnPage,0x14212A58+1
        defadr FreeBook,0x141293FC+1
        defadr FindBook,0x140CC010+1
        defadr Find_StandbyBook,0x141ACACC+1
        defadr BookObj_SetFocus,0x144CB1A0+1
        defadr GUIObject_SetTitleText,0x1443F740+1
        defadr GUIObject_Show,0x144CB9BC+1
        defadr ListMenu_SetCursorToItem,0x14417A80+1
        defadr GUIObject_SetStyle,0x14129878+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142C5BB4+1
        defadr GUIonMessage_SetMenuItemText,0x1438A538+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141326FC+1
        defadr GUIonMessage_SetMenuItemInfoText,0x1438A684+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14075940+1
        defadr GUIonMessage_SetMenuItemIcon,0x144CC8B4+1
        defadr DispObject_SetTitleText,0x1443F9FC+1
        defadr ListMenu_GetSelectedItem,0x142800F8+1
        defadr ListMenu_SetItemStyle,0x140B9BF0+1
        defadr IsScreenSaverBook,0x144822D8+1
        defadr StatusIndication_SetItemText,0x14309EF0+1
        defadr StatusIndication_ShowNotes,0x15400B40+1
        defadr CreateStringInputVA,0x14DB0C3C+1
        defadr CreateOneOfMany,0x140B9B74+1
        defadr OneOfMany_SetItemCount,0x1442AE94+1
        defadr OneOfMany_SetChecked,0x1422CD38+1
        defadr OneOfMany_SetTexts,0x1419F5AC+1
        defadr OneOfMany_GetSelected,0x14457AA8+1
        defadr StatusIndication_Item8_SetText,0x15400B20+1
        defadr GUIObject_SoftKeys_SetAction,0x1417BACC+1
        defadr GUIObject_SoftKeys_SetText,0x141C50C8+1
        defadr GUIObject_SoftKeys_SetEnable,0x141C5108+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x144309F4+1
        defadr GUIObject_SoftKeys_RemoveItem,0x1417F180+1
        defadr GUIObject_SoftKeys_SetVisible,0x141C4E24+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x142CD5B4+1
        defadr wstrcpy,0x144D851C+1
        defadr wstrncpy,0x143EEBF8+1
        defadr wstrcat,0x144D8474+1
        defadr wstrncat,0x14178F90+1
        defadr wstrcmp,0x144D9600+1
        defadr wstrlen,0x14178EC8+1
        defadr str2wstr,0x141C9A44+1
        defadr strcmp,0x14C0BA78+1
        defadr strlen,0x14C0BAD4+1
        defadr wstr2strn,0x140C1BF4+1
        defadr TextID_CreateIntegerID,0x1401F5BC+1
        defadr TextID_Create,0x141818E4+1
        defadr TextID_GetString,0x14182108+1
        defadr TextID_GetWString,0x1418243C+1
        defadr TextID_GetLength,0x14183014+1
        defadr TextID_Destroy,0x14182788+1
        defadr AB_DEFAULTNBR_GET,0x1416AEC8+1
        defadr AB_READPHONENBR,0x1527FBF0+1
        defadr AB_GETNBROFITEMS,0x1431F9CC+1
        defadr PNUM_len,0x14090A3C+1
        defadr PNUM2str,0x1437EF38+1
        defadr GUIObject_GetDispObject,0x140CACD8+1
        defadr List_Create,0x1430E0E0+1
        defadr List_Destroy,0x1430E244+1
        defadr List_InsertFirst,0x1430E4B0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x144B9C9C+1
        defadr REQUEST_DATEANDTIME_GET,0x140C4E48+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x143F2FD4+1
        defadr GetFreeBytesOnHeap,0x142188E8+1
        defadr BookObj_Hide,0x142753C4+1
        defadr BookObj_Show,0x14028CD4+1
        defadr StartAPP,0x14E6BC70+1
        defadr ListMenu_SetOnMessage,0x14302734+1
        defadr manifest_GetParam,0x141F620C+1
        defadr lseek,0x141782E0+1
        defadr SetLampLevel,0x14DE5BA8+1
        defadr List_RemoveAt,0x1430CEDC+1
        defadr GetCurrentPID,0x101D6C24+1
        defadr List_IndexOf,0x1430D21C+1
        defadr alloc,0x101CFCE4
        defadr receive,0x101CFD00
        defadr send,0x101CFCF0
        defadr sender,0x101CFD40
        defadr free_buf,0x101CFD10
        defadr create_process,0x101CFDDC
        defadr start,0x101CFFE8
        defadr get_ptype,0x101CFE9C
        defadr current_process,0x101CFDEC
        defadr delay,0x101CFD30
        defadr hunt,0x101CFEE8
        defadr kill_proc,0x101CFF14
        defadr receive_w_tmo,0x101CFD5C
        defadr stop,0x101CFD50
        defadr get_mem,0xEDA51BD1
        defadr get_envp,0x101D68A8+1
        defadr set_envp,0x101D68BC+1
        defadr get_bid,0x101CFE24
        defadr datetime2unixtime,0x140B6DF4+1
        defadr strcpy,0x14C0BAA0+1
        defadr UIEventName,0x141D9518+1
        defadr UI_Event,0x140C5938+1
        defadr UI_Event_wData,0x1449FA68+1
        defadr UI_Event_toBookID,0x141F464C+1
        defadr UI_Event_toBookIDwData,0x1412935C+1
        defadr List_Find,0x14179CB4+1
        defadr List_Get,0x140CC3EC+1
        defadr wstrrchr,0x143F196C+1
        defadr BookObj_CallSubroutine,0x1448175C+1
        defadr List_InsertLast,0x1417A03C+1
        defadr debug_printf,0x14B49D0C
        defadr PlayFile,0x15822774+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x141ACFB0+1
        defadr Profile_SetActive,0x158901A0+1
        defadr isKeylocked,0x14071644+1
        defadr IsMediaPlayerVideoBook,0x1448A268+1
        defadr REQUEST_DATEFORMAT_GET,0x1430947C+1
        defadr REQUEST_TIMEFORMAT_GET,0x14309434+1
        defadr Date2ID,0x143A0B38+1
        defadr Time2ID,0x1430989C+1
        defadr CreateListMenu,0x14285AF8+1
        defadr ListMenu_SetItemCount,0x14280610+1
        defadr GUIObject_SoftKeys_SetInfoText,0x141283F0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1419D6B4+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x1585CAA4+1
        defadr REQUEST_SYSTEM_RESTART,0x14C15F28+1
        defadr GUIObject_SoftKeys_SetTexts,0x140760A8+1
        defadr IsRightNowBook,0x14004888+1
        defadr IsVolumeControllerBook,0x14199E64+1
        defadr CreateTabMenuBar,0x142E53B4+1
        defadr TabMenuBar_SetTabCount,0x141EA0CC+1
        defadr TabMenuBar_SetTabGui,0x14127A08+1
        defadr TabMenuBar_SetTabIcon,0x14127B40+1
        defadr GUIObject_Destroy,0x144CBD98+1
        defadr GUIInput_SetIcon,0x14311788+1
        defadr StringInput_GetStringAndLen,0x14202700+1
        defadr AudioControl_Vibrate,0x14409BF0+1
        defadr GetVolumeSize,0x1435A23C+1
        defadr CreateNOfMany,0x14FEA8BC+1
        defadr NOfMany_SetTexts,0x14CBCD24+1
        defadr NOfMany_SetChecked,0x158684B4+1
        defadr NOfMany_SetCursor,0x14FEA938+1
        defadr NOfMany_GetCheckedCount,0x144A6C34+1
        defadr NOfMany_GetChecked,0x158684C8+1
        defadr NOfMany_SetOnMessage,0x142354E0+1
        defadr AudioControl_Init,0x14298B6C+1
        defadr OneOfMany_SetFocused,0x1422CC04+1
        defadr OneOfMany_SetOnMessage,0x1407EA9C+1
        defadr CreateMonitorFeedback,0x1585B9A4+1
        defadr Feedback_SetText,0x1585BA54+1
        defadr GetBatteryState,0x1016A564+1
        defadr get_DisplayGC,0x1449E09C+1
        defadr DispObject_GetRect,0x140CAEDC+1
        defadr GC_GetRect,0x140C9E80+1
        defadr GC_GetXX,0x1419CE14+1
        defadr GC_SetXX,0x140B2DB8+1
        defadr GC_ValidateRect,0x1445A2D8+1
        defadr BookObj_AddGUIObject,0x14285AEC+1
        defadr DrawRect,0x1445A7BC+1
        defadr XGUIList_AddGUIObject,0x14481C60+1
        defadr DispObject_InvalidateRect,0x140CA948+1
        defadr GUIObject_Create,0x144CB8B0+1
        defadr root_list_get_session_count,0x14482300+1
        defadr root_list_get_session,0x144825A4+1
        defadr SESSION_GetTopBook,0x14482498+1
        defadr MainInput_strlen,0x140C51D4+1
        defadr MainInput_getPNUM,0x14090884+1
        defadr BookObj_GetBookID,0x140CBC54+1
        defadr wstrncmp,0x14325C10+1
        defadr DispObject_GetAbsoluteXPos,0x140CA274+1
        defadr DispObject_GetAbsoluteYPos,0x140CA200+1
        defadr GetThemeColor,0x1430BDD4+1
        defadr REQUEST_SETTING_SILENCE_SET,0x15876848+1
        defadr REQUEST_SETTING_SILENCE_GET,0x141AD0BC+1
        defadr VCALL_Init,0x14040524+1
        defadr VCALL_SetName,0x14C19448+1
        defadr VCALL_SetNameIcon,0x143BB4A4+1
        defadr VCALL_SetNumber,0x1506CC88+1
        defadr VCALL_SetHZ1,0x141F3F2C+1
        defadr VCALL_SetHZ2,0x1527530C+1
        defadr MakeVoiceCall,0x1506CA3C+1
        defadr FileDelete,0x14176C04+1
        defadr GUIObject_SetFocus,0x144CB990+1
        defadr MSG_SendMessage_CreateMessage,0x143F7388+1
        defadr MSG_SendMessage_DestroyMessage,0x1439E5E8+1
        defadr MSG_SendMessage_AddRecipient,0x15838D44+1
        defadr MSG_SendMessage_Start,0x14E2FBE0+1
        defadr AB_POSITIONNBR_GET,0x1527FD2C+1
        defadr AB_NAME_ITEM2TextID,0x1527FCDA+1
        defadr AB_NUM_ITEM2TextID,0x14E0506C+1
        defadr GetABRecNum,0x141B87EA+1
        defadr SBY_GetMainInput,0x14499F66+1
        defadr SBY_GetStatusIndication,0x14499F62+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x142E0014+1
        defadr DispObject_GetGUI,0x142A8F2C+1
        defadr Display_GetFocusedDispObject,0x1417AE84+1
        defadr DispObject_GetVisible,0x140CBC48+1
        defadr DispObject_GetDESC,0x150AFF30+1
        defadr DISP_DESC_SetName,0x142957C4+1
        defadr DispObject_GetName,0x144829BC+1
        defadr DISP_DESC_SetSize,0x142958A8+1
        defadr DISP_DESC_SetOnCreate,0x14295844+1
        defadr DispObject_GetOnCreate,0x140C685C+1
        defadr DISP_DESC_SetOnClose,0x14295840+1
        defadr DispObject_GetOnClose,0x1449EF6C+1
        defadr DISP_DESC_SetOnRedraw,0x14295848+1
        defadr DispObject_GetOnRedraw,0x1438E780+1
        defadr DISP_DESC_SetOnKey,0x14295990+1
        defadr DispObject_GetOnKey,0x1449FFD4+1
        defadr DISP_DESC_SetOnRefresh,0x1429540C+1
        defadr DispObject_GetonRefresh,0x14466F1C+1
        defadr DISP_DESC_SetMethod06,0x14295630+1
        defadr DispObject_GetMethod06,0x140CA478+1
        defadr DISP_DESC_SetOnLayout,0x14295474+1
        defadr DispObject_GetOnLayout,0x14235754+1
        defadr DISP_DESC_SetOnConfig,0x14295530+1
        defadr DispObject_GetOnConfig,0x141C6994+1
        defadr DISP_DESC_SetMethod0A,0x142954CC+1
        defadr DispObject_GetMethod0A,0x141C6E94+1
        defadr JavaSession_Manager,0x141B87EA+1
        defadr JavaSession_GetName,0x140A74D8+1
        defadr TextID_Copy,0x14181E88+1
        defadr BookObj_GetSession,0x14481EB8+1
        defadr GUIonMessage_SetNumberOfSubItems,0x1404B3E8+1
        defadr GUIonMessage_SubItem_SetText,0x1404B288+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x142D14D4+1
        defadr GoMusic,0x14F11EEC+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x14485F2C+1
        defadr GUIonMessage_SubItem_SetDisabled,0x15867C14+1
        defadr PlayFileV,0x14298AC4+1
        defadr GetSilent,0x1432F740+1
        defadr GetVibrator,0x144046F8+1
        defadr GetAudioSettings,0x1432FD48+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x141D4D40+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x15867BF0+1
        defadr DestroyDirHandle,0x14358A24+1
        defadr GetOtherExtMethods,0x14431E30+1
        defadr MessageBox,0x1585B1CC+1
        defadr Display_GetHeight,0x140C93BC+1
        defadr Display_GetWidth,0x140C93AC+1
        defadr PlaySystemSound,0x141748C4+1
        defadr TabMenuBar_GetFocusedTab,0x1422B9E4+1
        defadr TabMenuBar_SetFocusedTab,0x1412741C+1
        defadr GC_GetPenColor,0x14435440+1
        defadr GC_SetPenColor,0x1449E18C+1
        defadr GC_SetPixel,0x140CE39C+1
        defadr GC_DrawLine,0x140917BC+1
        defadr GC_DrawFRect,0x140CDB50+1
        defadr GC_WritePixels,0x1403F158+1
        //defadr png_create_read_struct_2,0x14043534+1
        //defadr png_destroy_read_struct,0x14043BBC+1
        //defadr png_create_info_struct,0x14043978+1
        //defadr png_destroy_info_struct,0x1576A43C+1
        //defadr png_set_progressive_read_fn,0x14043138+1
        //defadr png_process_data,0x14042F08+1
        //defadr png_read_update_info,0x142CFE54+1
        //defadr png_get_progressive_ptr,0x143D7478+1
        //defadr png_get_IHDR,0x142CFD18+1
        //defadr png_set_strip_16,0x1576A7C8+1
        //defadr png_set_gray_1_2_4_to_8,0x1576A7D4+1
        //defadr png_set_gray_to_rgb,0x1576A7EC+1
        //defadr png_get_valid,0x142CFF70+1
        //defadr png_set_tRNS_to_alpha,0x1576A7E0+1
        //defadr png_set_filler,0x14F67870+1
        //defadr png_set_palette_to_rgb,0x142CFF88+1
        //defadr png_get_rowbytes,0x142CFD04+1
        //defadr png_progressive_combine_row,0x143D7344+1
        //defadr png_sig_cmp,0x144C7934+1
        defadr setjmp,0x14057464+1
        defadr longjmp,0x14C0AE08+1
        //defadr inflateInit2_,0x14043728+1
        //defadr inflate,0x143D8110+1
        //defadr inflateEnd,0x14043A30+1
        defadr memcmp,0x4BA32F18
        defadr strncmp,0x141C7A0C+1
        defadr strncpy,0x1408B810+1
        defadr strcat,0x1000188C+1
        defadr GUIObject_SetTitleType,0x14093534+1
        defadr GUIonMessage_SetItemDisabled,0x144DF9F4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150D4864+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x150D48EC+1
        defadr iconidname2id,0x144DA158+1
        defadr textidname2id,0x144D9F6C+1
        defadr ListMenu_SetNoItemText,0x1419F41C+1
        defadr IsFmRadioBook,0x14301DB0+1
        defadr get_IsAudioPlayerBook,0x1423F7F8+1
        defadr IsAudioPlayerBook,0x1423F7F8+1
        defadr PlayerControl,0x14C5A364+1
        defadr SwitchRadioStationFromList,0x1554AEF8+1
        defadr Shortcut_Run,0x14278FCC+1
        defadr mkdir,0x141C9C20+1
        defadr rmdir,0x140F56F8+1
        defadr chmod,0x14122E50+1
        defadr rename,0x141E3948+1
        defadr CallID_GetCallStatusDesc,0x1412A11C+1
        defadr CallStatusDesc_GetName,0x144C8634+1
        defadr List_DestroyElements,0x140EF194+1
        defadr strstr,0x143329AC+1
        defadr GPRS_GetLastSessionInfo,0x150F95B0+1
        defadr wstrcmpni,0x14179B48+1
        defadr wtoi,0x143258B0+1
        defadr DATE_GetWeekDay,0x14428310+1
        defadr Cale_GetSettings,0x14EC1C64+1
        defadr wstrwstr,0x141700F8+1
        defadr wstrcmpi,0x14179B14+1
        defadr wstrchr,0x143EE750+1
        defadr GUIObject_SoftKeys_Hide,0x144CB138+1
        defadr GUIObject_SoftKeys_Show,0x1412982C+1
        defadr DispObject_SoftKeys_Get,0x143FB5F8+1
        defadr StandbyBackground_SetImage,0x144795B8+1
        defadr CreateYesNoQuestionVA,0x14D1B834+1
        defadr ListMenu_SetItemSecondLineText,0x142A8E24+1
        defadr _REQUEST_OAF_START_APPLICATION,0x140637FC+1
        defadr FSX_GetInvalidChar,0x140A3C04+1
        defadr DataBrowserDesc_SetFoldersNumber,0x141F9644+1
        defadr DataBrowserDesc_SetActions,0x14390D30+1
        defadr DataBrowserDesc_SetSelectAction,0x142996A0+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x1574F9D4+1
        defadr DataBrowserDesc_SetBookID,0x1430687C+1
        defadr DataBrowserDesc_SetItemFilter,0x14D80664+1
        defadr DataBrowserDesc_SetOption,0x14299638+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x1574FA14+1
        defadr DataBrowserDesc_SetFileExtList,0x141A535C+1
        defadr FSX_RemoveIllegalSymbolsName,0x14DDA7BC+1
        defadr FILEITEM_Create,0x142C8428+1
        defadr FILEITEM_Destroy,0x142C68F4+1
        defadr CreateDateInputVA,0x14FAACF4+1
        defadr CreateTimeInputVA,0x14CB792C+1
        defadr StringInput_SetCursorPosition,0x142E80D4+1
        defadr BookObj_CallPage,0x1402068C+1
        defadr DateInput_GetDateInt,0x14064E98+1
        defadr TimeInput_GetTimeInt,0x141FBDD4+1
        defadr GC_GetBrushColor,0x144CD1B8+1
        defadr GC_SetBrushColor,0x1449E134+1
        defadr GC_DrawRoundRect,0x144A8C78+1
        defadr MenuBook_Desktop,0x14124B8C+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x14FC1690+1
        defadr BookObj_SoftKeys_SetAction,0x142CE2D4+1
        defadr BookObj_SoftKeys_SetText,0x14C377B4+1
        defadr FindBookByID,0x140CBCEC+1
        defadr TextFeedbackWindow,0x142CD724+1
        defadr Feedback_SetKeyHook,0x14477C08+1
        defadr Feedback_SetOnClose,0x140207E8+1
        defadr Feedback_SetTimeout,0x14C4D2C0+1
        defadr Feedback_SetTextExtended,0x140200C8+1
        defadr TabMenuBar_SetOnTabSwitch,0x14041F44+1
        defadr KeyCode2Name,0x15550554+1
        defadr ImageID_Get,0x1447947C+1
        defadr ImageID_Free,0x14410D58+1
        defadr DataBrowser_CreateSubExecute,0x142C7D7C+1
        defadr DataBrowser_ExecuteSubroutine,0x142C6B5C+1
        defadr FILEITEM_SetFname,0x142C8228+1
        defadr FILEITEM_SetPath,0x142C831C+1
        defadr FILEITEM_GetFname,0x142C7D74+1
        defadr FILEITEM_GetPath,0x142C7CA0+1
        defadr FILEITEM_SetFnameAndContentType,0x142C8288+1
        defadr FILEITEM_SetPathAndContentType,0x142C84EC+1
        defadr JavaDialog_Open,0x142CEAF8+1
        defadr JavaDialog_Close,0x143F042C+1
        defadr JavaAppDesc_Get,0x143F04C8+1
        defadr JavaAppDesc_GetFirstApp,0x14028628+1
        defadr JavaAppDesc_GetNextApp,0x143F0258+1
        defadr JavaAppDesc_GetJavaAppInfo,0x144D7ECC+1
        defadr DispObject_SetRefreshTimer,0x1412E1BC+1
        defadr DispObject_KillRefreshTimer,0x1449F134+1
        defadr IsDataBrowserBook,0x142C6D84+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x1436542C+1
        defadr Shortcut_Get_MenuItemName,0x142CE0FC+1
        defadr Shortcut_Get_MenuItemIconID,0x141289FC+1
        defadr FindBookEx,0x14430F2C+1
        defadr FILEITEM_CreateCopy,0x142C7FF4+1
        defadr ImageID_Copy,0x144CC668+1
        defadr BookObj_GetSessionID,0x1430E224+1
        defadr UI_Event_toSID,0x14013058+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x143C81DC+1
        defadr MainInput_Hide,0x14278634+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x142CD6D4+1
        defadr PNUM2Name,0x14CEA3D8+1
        defadr SpeedDial_GetPNUM,0x152880F8+1
        defadr DispObject_GetWindowWidth,0x140CB140+1
        defadr DispObject_GetWindowHeight,0x140CB278+1
        defadr get_system_langID,0x141AE37C+1
        defadr lang_get_name,0x14359220+1
        defadr w_chdir,0x104F943C+1
        defadr w_fopen,0x100A6E5C+1
        defadr w_fstat,0x100A6EA0+1
        defadr w_fwrite,0x100F2624+1
        defadr w_fread,0x100F2E7C+1
        defadr w_lseek,0x10589418+1
        defadr w_fclose,0x1013A908+1
        defadr w_mkdir,0x104F62FC+1
        defadr DirHandle_SetFilterStr,0x14CCE138+1
        defadr ImageID_GetIndirect,0x150D2C38+1
        defadr unixtime2datetime,0x144281A4+1
        defadr List_Insert,0x14480CEC+1
        defadr FileCopy,0x141FA7F0+1
        defadr FileMove,0x141E3948+1
        defadr DispObject_SetLayerColor,0x140C6CA0+1
        defadr JavaAppDesc_GetJavaAppID,0x144D82FC+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x15314650+1
        defadr JavaApp_LogoImageID_Get,0x14EB08B4+1
        defadr CreateProgressBar,0x142CDD08+1
        defadr ProgressBar_SetText,0x1401FC88+1
        defadr ProgressBar_SetIcon,0x14FB6948+1
        defadr ProgressBar_SetPercentValue,0x14430E1C+1
        defadr ProgressBar_SetBarDisabled,0x1403F238+1
        defadr StringInput_DispObject_SetText,0x14D682D8+1
        defadr GUIObject_SetTitleIcon,0x141F29A8+1
        defadr DispObject_SoftKeys_GetParams,0x14179BE4+1
        defadr DispObject_SoftKeys_GetList,0x14179B8C+1
        defadr BookObj_GetDisplayOrientation,0x140CAED4+1
        defadr BookObj_SetDisplayOrientation,0x14129758+1
        defadr Display_GetTopBook,0x14EB0010+1
        defadr Display_GetBrightness,0x14D35A70+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x1574F9C0+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x143F9830+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x143115B0+1
        defadr SetTheme,0x154422BC+1
        defadr SoftKeys_GetLabel,0x1417AE9C+1
        defadr SoftKeys_Update,0x1417AC88+1
        defadr IncommingCall_Reject,0x1544059C+1
        defadr IncommingCall_Mute,0x14CF00E0+1
        defadr Bluetooth_GetState,0x141518B4+1
        defadr Bluetooth_GetPhoneVisibility,0x14CFCEB8+1
        defadr Bluetooth_isBusy,0x1415183C+1
        defadr USB_isConnected,0x151B70A4+1
        defadr w_diropen,0x140F1B08+1
        defadr w_dirread,0x142E855C+1
        defadr w_dirclose,0x104F84D4+1
        defadr w_rename,0x141E428C+1
        defadr w_remove,0x141E45AC+1
        defadr IsCameraBook,0x14153494+1
        defadr IsSoundRecorderBook,0x141DE3D0+1
        defadr StringInput_MenuItem_SetPriority,0x14012E6C+1
        defadr Video_ActionBack,0x1422F1A4+1
        defadr Video_ExtractFrame,0x15445528+1
        defadr Video_ZoomOn,0x15444DC4+1
        defadr RightNow_SetActive,0x1412949C+1
        defadr Video_Play,0x15444CA8+1
        defadr Video_Pause,0x14DA417C+1
        defadr Audio_Pause,0x1405A58C+1
        defadr Audio_Play,0x14CDA5CC+1
        defadr CreatePercentInputVA,0x15020028+1
        defadr PercentInput_GetPercent,0x15708DB8+1
        defadr GUIonMessage_SetLineSeparator,0x15867BE4+1
        defadr PHF_GetState,0x151DAD20+1
        defadr CHF_GetState,0x151DADAC+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14129628+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1412974C+1
        defadr SetTrayIcon,0x1417A598+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x158766E4+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x158767E0+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x158767A4+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x158768B4+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x15876744+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x1403A184+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x15252988+1
        defadr SoundRecorderDesc_Create,0x15065AFC+1
        defadr SoundRecorderDesc_Destroy,0x15463B5C+1
        defadr SoundRecorderDesc_SetBookID,0x15463B74+1
        defadr SoundRecorderDesc_SetType,0x15463BA0+1
        defadr SoundRecorderDesc_SetFolder,0x15463BB4+1
        defadr SoundRecorderDesc_SetFname,0x15040E30+1
        defadr SoundRecorderDesc_SetRecordSize,0x15463BDC+1
        defadr SoundRecorder_Create,0x15463C54+1
        defadr SoundRecorder_RecordCall,0x15065944+1
        defadr Browser_OpenURI,0x1405C658+1
        defadr GetURIScheme,0x143C31FC+1
        defadr CreateURI,0x143C2BA4+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x1428873C+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x142171AC+1
        defadr Alarm_GetState,0x142FEBA8+1
        defadr Alarm_GetTIME,0x150D672C+1
        defadr Alarm_GetWeekSettings,0x142FEA58+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x141ACB58+1
        defadr IncommingCall_Accept,0x1544023C+1
        defadr MediaPlayer_SoftKeys_SetText,0x14430570+1
        defadr MediaPlayer_SoftKeys_SetAction,0x14430528+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x144302E8+1
        defadr DispObject_Show,0x140CA870+1
        defadr Request_EventChannel_Subscribe,0x107B2150+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x150FDF64+1
        defadr Request_ICA_ShutdownAllConnections,0x1048F540+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x14235D1C+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1574FA1C+1
        defadr GUIonMessage_GetMsg,0x142C5CA4+1
        defadr GUIonMessage_GetBook,0x142C5E94+1
        defadr GUIonMessage_GetGui,0x1416A568+1
        defadr GUIonMessage_GetSelectedItem,0x1416A898+1
        defadr GUIonMessage_GetPrevSelectedItem,0x15867BD8+1
        defadr ObexSendFile,0x15139940+1
        defadr Feedback_SetManualScrollingText,0x14C419F8+1
        defadr EqualizerGain_Set,0x14404AE0+1
        defadr CANVAS_Get_GviGC,0x100A2A5C+1
        defadr GVI_BitBlt,0x100A2740+1
        defadr GVI_StretchBlt,0x104BB5F0+1
        defadr GVI_TransformBlt,0x1011BFE4+1
        defadr GVI_CreatePen,0x1015E9C8+1
        defadr GVI_CreateDashedPen,0x10283D44+1
        defadr GVI_CreateSolidBrush,0x100AE104+1
        defadr GVI_Delete_GVI_Object,0x10048E84+1
        defadr GVI_DrawEllipse,0x104BB0D4+1
        defadr GVI_DrawLine,0x1009686C+1
        defadr GVI_DrawLines,0x104BBFC4+1
        defadr GVI_DrawPolyLine,0x104BC048+1
        defadr GVI_DrawRectangle,0x101763F0+1
        defadr GVI_DrawRoundRect,0x10097DA8+1
        defadr GVI_DrawSolidLines,0x104BBBF4+1
        defadr GVI_DrawSolidPolyLine,0x104BBDF8+1
        defadr GVI_DrawSolidRectangle,0x1017616C+1
        defadr GVI_FillEllipse,0x104BB4B8+1
        defadr GVI_FillPolygon,0x100987D0+1
        defadr GVI_FillRectangle,0x10096588+1
        defadr GVI_FillRectangles,0x104BC144+1
        defadr GVI_FillSolidEllipse,0x104BB568+1
        defadr GVI_FillSolidRectangle,0x101217F0+1
        defadr GVI_FillSolidRoundRect,0x10247EE8+1
        defadr GVI_FillSolidTriangle,0x1000D0BC+1
        defadr GC_CreateMemoryGC,0x1403EBB4+1
        defadr GC_FreeGC,0x1449EEC0+1
        defadr Settings_ShowNumber_Get,0x1541474C+1
        defadr GVI_CreateBitmap,0x104BADC8+1
        defadr GVI_CreateMemoryGC,0x10049908+1
        defadr GVI_DeleteMemoryGC,0x101086F8+1
        defadr StringInput_DispObject_SetLanguage,0x14C58230+1
        defadr List_InsertSorted,0x14480C90+1
        defadr ListMenu_SetItemIcon,0x1427C808+1
        defadr wstrnupr,0x1418E8A0+1
        defadr wstrnlwr,0x142E82F0+1
        defadr ListMenu_SetItemTextScroll,0x1442FA78+1
        defadr GUIObject_SetListTextColor,0x1586815C+1
        defadr DispObject_SetTitleTextColor,0x151BA724+1
        defadr DispObject_SetListTextColor,0x14E4FB50+1
        defadr DispObject_SetCursorImage,0x14D6C860+1
        defadr DispObject_SetBackgroundImage,0x158641B0+1
        defadr DispObject_SetTitleBackgroundImage,0x151BA740+1
        defadr TabMenuBar_SetTabTitle,0x14287DDC+1
        defadr GUIObject_GetBook,0x140CAEC8+1
        defadr SoftKeys_GetSelectedAction,0x14278DEC+1
        defadr MonitorFeedback_SetTimer,0x1585BA48+1
        defadr ListMenu_DestroyItems,0x14280984+1
        defadr DispObject_SetScrollBarBackgroundColor,0x143C1F0C+1
        defadr DispObject_SetScrollBarColor,0x143C1EE4+1
        defadr DispObject_SetSoftkeysColor,0x14417D48+1
        defadr YesNoQuestion_SetIcon,0x14337428+1
        defadr GUIObject_SetBacklightTimeout,0x142F0B80+1
        defadr ListMenu_SetHotkeyMode,0x14417B18+1
        defadr ListMenu_SetSearchLanguageMode,0x144ACCE0+1
        defadr ListMenu_EnableSearchHeader,0x1438EBF4+1
        defadr GUIonMessage_GetSearchString,0x14E68EDC+1
        defadr GUIonMessage_GetSearchStringLength,0x1429D9E8+1
        defadr EqualizerGain_Get,0x158223AC+1
        defadr Theme_DestroyMenuIcons,0x14EAC3DC+1
        defadr CoCreateInstance,0x1401106C+1
        defadr GUIObject_SetSecondRowTitleText,0x1443F3D0+1
        defadr ListMenu_GetItemCount,0x1416A720+1
        defadr OSE_GetShell,0x1415EC44+1
        defadr swscanf,0x140C0938+1
        defadr sscanf,0x101D3E90+1
        defadr BookObj_WindowSetWantsFocus,0x142D1044+1
        defadr BookObj_StayOnTop,0x142C28A4+1
        defadr DispObject_WindowSetPosition,0x140CA2EC+1
        defadr DispObject_WindowSetSize,0x140CA498+1
        defadr Feedback_DispObject_GetText,0x157061C0+1
        defadr DispObject_SoftKeys_ExecuteAction,0x144171DC+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x144401A0+1
        defadr DispObject_SetAnimation,0x14E1B408+1
        defadr GUIObject_SetZOrder,0x140947A4+1
        defadr StringInput_GetCursorPosition,0x14203580+1
        defadr str2PNUM,0x14090974+1
        defadr pb_ui_search_bk_create_search_menu,0x14DCCCF4+1
        defadr GUIObject_SoftKeys_SubActionPressedNotification,0x1419D54C+1
        // dll function ----------------------------------------------------
        defadr DisplayGC_AddRef,0x144CDAA4+1
        defadr TextObject_SetText,0x14183164+1
        defadr TextObject_SetFont,0x1449CD74+1
        defadr RichTextLayout_GetTextWidth,0x14335244+1

        defadr Illumination_LedID_SetLevel_Gradually,0x143A0420+1
        defadr Illumination_LedID_SetLevel,0x1444D9C4+1
        defadr Illumination_LedID_Off,0x142E2904+1

        defadr REQUEST_HPHONEBOOK_READSTRING,0x140B6BD8+1
        defadr AB_STR_ITEM_Copy,0x1527FCAC+1
        defadr Display_SetBrightnessLevel,0x1541F1C8+1
        defadr Request_SIM_IMSI_Read,0x100DFA0C+1
        defadr get_imsi_const,0x100E9460+1
        defadr Request_SL_GetRadioState,0x1055B494+1
        defadr Network_INetworkConnection_GetConnectionInfo,0x141CC76C+1
        defadr GetChipID_int,0x10777BA0+1
        defadr get_mem_int,0x101CFE6C
        defadr ConnectionManager_Connection_GetState_int,0x144110A4+1
        // my function ----------------------------------------------------
        defadr Registry_Write,0x15D84034+1
        defadr Registry_Read,0x15D84080+1
        // menu function ----------------------------------------------------
        defadr DynamicMenu_GetElementMsg,0x1431E418+1
        defadr DynamicMenu_SetElement_FirstLineText,0x14166EB4+1
        defadr DynamicMenu_SetElement_SecondLineText,0x141ADFFC+1
        defadr DynamicMenu_SetElement_UnavailableState,0x1431EFC0+1
        defadr DynamicMenu_SetElement_UnavailableText,0x1431EBEC+1
        defadr DynamicMenu_SetElement_InfoText,0x143AB2A0+1
        // gui function ----------------------------------------------------
	defadr GUIObject_TabTitleRemove,0x143C1DAC+1
        defadr GUIObject_SetAnimationApp,0x1423B684+1
        defadr GUIObject_RefreshLayout,0x140930CC+1
        defadr GUIObject_GetDisplay,0x14482AB8+1
        defadr GUIObject_GetStyle,0x140CACE4+1
        defadr GUIObject_GetTitleType,0x151BB0CC+1
        defadr GUIObject_SetTitleIconHasPriority,0x142D8694+1
        defadr GUIObject_SetTitleAlignment,0x1443F348+1
        defadr GUIObject_GetTitleAlignment,0x151BB0F0+1
        defadr GUIObject_BacklightOn,0x142EFF34+1
        defadr GUIObject_BacklightOff,0x151BB080+1
        defadr GUIObject_BacklightTimeout,0x142F02B0+1
        defadr GUIObject_BacklightBlink,0x1437BB34+1
        defadr GUIObject_BacklightBlinkTime,0x151BB08C+1
        defadr GUIObject_BacklightRestore,0x142F02A4+1
        defadr GUIObject_SetInternalBackground,0x141A215C+1
        defadr GUIObject_SoftKeys_SetLongSKButtonText,0x144344F4+1
        defadr GUIObject_SoftKeys_SetIcon,0x1419DC4C+1
        defadr GUIObject_SoftKeys_MoveItemAfter,0x1419CEF0+1
        defadr GUIObject_SoftKeys_MoveItemBefore,0x150FDF40+1
        defadr GUIObject_SoftKeys_MoveItemFirst,0x1427D920+1
        defadr GUIObject_SoftKeys_SetDisabledAction,0x150FDF1C+1
        defadr GUIObject_SoftKeys_SetSubItemHighlight,0x1419D758+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1427D5D4+1
        defadr GUIObject_SoftKeys_RemoveItemFromKey,0x1420309C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143AA4E8+1
        defadr GUIObject_SoftKeys_SetAction_SetText_SetInfoText_SetVisible,0x154653C8+1
        // disp_obj function ----------------------------------------------------
        defadr DispObject_SetThemeImage,0x144815C4+1
        defadr DispObject_SetAnimationApp,0x1423B694+1
        defadr DispObject_GetDisplay,0x140CAB60+1
        defadr DispObject_GetStyle,0x140CADB0+1
        defadr DispObject_SetStyle,0x1430BBA4+1
        defadr DispObject_GetTitleType,0x141C69B4+1
        defadr DispObject_SetTitleIconHasPriority,0x142D86D8+1
        defadr DispObject_SetTitleAlignment,0x1443F394+1
        defadr DispObject_GetTitleAlignment,0x151BA6D0+1
        defadr DispObject_Backlight,0x142F0190+1
        defadr DispObject_BacklightBlinkTime,0x14D770D8+1
        defadr DispObject_BacklightRestore,0x142F027C+1
        defadr DispObject_SetInternalBackground,0x141A2180+1
        defadr DispObject_SoftKeys_SetLongSKButtonText,0x15003D20+1
        defadr DispObject_SoftKeys_SetIcon,0x1419DCB0+1
        defadr DispObject_SoftKeys_MoveItemAfter,0x1419D248+1
        defadr DispObject_SoftKeys_MoveItemBefore,0x1425C7A4+1
        defadr DispObject_SoftKeys_MoveItemFirst,0x1417BB40+1
        defadr DispObject_SoftKeys_SetDisabledAction,0x14CBD528+1
        defadr DispObject_SoftKeys_SetSubItemHighlight,0x1419D77C+1
        defadr DispObject_SoftKeys_SubActionPressedNotification,0x1419D528+1
        defadr DispObject_SoftKeys_SetItemOnKey,0x1427D820+1
        defadr DispObject_SoftKeys_RemoveItemFromKey,0x142030C8+1
        defadr DispObject_GetStatusRowHeight,0x14252400+1
        defadr DispObject_TimeInput_MoveCursor,0x14DA0F7C+1
        defadr DispObject_DateInput_MoveCursor,0x15705F7C+1
        defadr DispObject_DateInput_SetDateFormat,0x14FAAC5C+1
        defadr DispObject_DateInput_SetDate,0x14FAACA0+1
        defadr DispObject_TimeInput_SetTime,0x15708934+1
        defadr DispObject_TimeInput_SetSecEnable,0x141EA424+1
        defadr GUIObject_DateInput_SetDateFormat,0x15708C90+1
        defadr GUIObject_DateInput_SetDate,0x15708CA0+1
        defadr GUIObject_TimeInput_SetTime,0x157091B4+1
        defadr GUIObject_TimeInput_SetSecEnable,0x157091C8+1
        // other function ----------------------------------------------------
        defadr BookObj_SoftKeys_SetItemOnKey,0x141A7E10+1
        defadr BookObj_SoftKeys_SetKey_SoftAction,0x15265360+1
        defadr CreateQuickInfo,0x14E71C2C+1
        defadr CreatePasswordInputWindow,0x14EB9698+1
        defadr CreateMultiChoiceMenu,0x14F00F58+1
        defadr MultiChoiceMenu_SetMessage,0x14F01168+1
        defadr MultiChoiceMenu_SetCursorToItem,0x141E9E80+1
        defadr Feedback_SetTimerClose,0x140203F8+1
        defadr Feedback_SetIcon,0x14212698+1
        defadr Feedback_CloseAction,0x1414B048+1
        defadr Feedback_SetTextAlignment,0x157090AC+1
        defadr Feedback_SetDescriptionImage,0x14D91E10+1
        defadr ProgressBar_SetDescriptionIcon,0x14212740+1
        defadr ProgressBar_IsScrolling,0x140723C0+1
        defadr CreateYesNoQuestion,0x142CD924+1
        defadr YesNoQuestion_SetQuestionText,0x14337434+1
        defadr YesNoQuestion_SetDescriptionText,0x14337444+1
        defadr NOfMany_SetItemCount,0x144AA700+1
        defadr NOfMany_GetCheckedItem,0x144946B4+1
        defadr CreateStringInput,0x14062C90+1
        defadr StringInput_SetMode,0x142CD5A4+1
        defadr StringInput_SetActionOK,0x142CD43C+1
        defadr StringInput_SetActionBack,0x1408E9B8+1
        defadr StringInput_SetActionLongBack,0x142CD440+1
        defadr StringInput_SetText,0x1401CDA4+1
        defadr StringInput_SetFixedText,0x142DB614+1
        defadr StringInput_SetMinLen,0x144A99F8+1
        defadr StringInput_SetMaxLen,0x14062D6C+1
        defadr StringInput_SetEnableEmptyText,0x142CEB28+1
        defadr StringInput_DispObject_StartSelecteText,0x1512E4C8+1
        defadr StringInput_DispObject_CopySelecteText,0x1512E554+1
        defadr ListMenu_SetTexts,0x14280BC8+1
        defadr ListMenu_Activate_AddCount,0x1404AF28+1
        defadr ListMenu_SetNameFistItem,0x142883DC+1
        defadr ListMenu_SetMaxCount,0x143D414C+1
        defadr ListMenu_ErroreAddCount,0x1404ADEC+1
        defadr MediaPlayer_SoftKeys_SetVisible,0x144304E8+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x144302A8+1
        defadr MediaPlayer_SoftKeys_SetEnable,0x144304B0+1
        defadr MediaPlayer_SoftKeys_AddErrorStr,0x144305B0+1
        defadr IsStandbyTickerBook,0x14482288+1
        defadr ChargingGetState,0x141CE354+1
        defadr FlightGetState,0x141B5508+1
        defadr FlightControl,0x144D2134+1
        defadr GetNewEvent,0x14389A0C+1
        defadr SaveBrightness,0x1541AF94+1
        defadr Generic_DRM_Info,0x15111B40+1
        defadr Keylock_Activate,0x15161088+1
        defadr Alarm_SetSignal,0x1517C564+1
        defadr FILEITEM_GetFExtension,0x142C7EEC+1
        defadr FILEITEM_GetContentType,0x142C7FF0+1
        defadr FILEITEM_SetContentType,0x142C82B0+1
        defadr GetFileLocation,0x1444000C+1
        defadr Volume_Set,0x1432EA7C+1
        defadr Volume_Get,0x1432FD48+1
        defadr FSX_MakeFullPath,0x141779BC+1
        defadr FSX_FreeFullPath,0x14336024+1
        defadr MakeFullPath,0x14298BE0+1
        defadr MessageBox_Animation,0x1585B1EC+1
        defadr CreateMessageBox,0x14CE140C+1
        defadr PlaySystemSound_SendEvent,0x14FA9150+1
        defadr GetMemoryStickStatus,0x142CE30C+1
        defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x14DDA4CC+1
        defadr FSX_IsFileExists,0x14411678+1

        defadr GUIObject_SoftKeys_AllowKeylock,0x1439DA94+1

        defadr List_RemoveFirst,0x1430DCFC+1
        defadr List_RemoveLast,0x1430E428+1
        defadr List_GetCount,0x140CC074+1

        defadr DispObject_SetBacklightMode,0x142F0190+1
        defadr DispObject_SoftKeys_Show,0x141297F4+1
        defadr DispObject_SoftKeys_Hide,0x144CB14C+1

        defadr MetaData_GetTags,0x157523B8+1

        defadr Sound_Check,0x1541B2BC+1
        defadr Sound_SetRingsignal,0x1541B334+1
        defadr Sound_SetMessageAlert,0x14C8C2D8+1
        defadr Sound_SetAlarmsignal,0x1517C564+1
        defadr Sound_AddToContact,0x15271BCC+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x158767A4+1

        defadr CurrentBattery_GetImageID, 0x1417A4FC+1

///////////////

        defadr FreeAllBook,0x154528E4+1

        defadr MusicApplication_PrevAction,0x140229F8+1
        defadr MusicApplication_CancelAction,0x14F3B420+1
        defadr MusicApplication_ShowMyMusic,0x15348024+1  //(BOOK*, GUI*)
        defadr MusicApplication_Minimize,0x14E39300+1     //(BOOK*, GUI*)
        defadr MusicApplication_Keyboard,0x14430140+1

        defadr pg_MusicApplication_PreviousEvent,0x153474EC+1
        defadr pg_MusicApplication_CancelEvent,0x1534782C+1
        defadr pg_MusicApplication_ExitEvent,0x14F15900+1

        defadr Music_Gui_NowPlaying_OnRedraw,0x1405FDA0+1
        defadr Music_Gui_NowPlaying_OnCreate,0x14F3119C+1
        defadr Music_Gui_NowPlaying_OnClose,0x14FA9B60+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x14F4B6BC+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x1442F898+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x14E0FCB8+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x14F151B4+1

        defadr FeedbackTicker_OnRedraw,0x14CFD6C4+1

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
	LDR     R3, = 0x1448174C+1
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
        LDR	R3, =0x14F14D76+1
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
	LDR     R3, =0x14E1FA00+1
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
	LDR     R3, =0x14E1FA34+1
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