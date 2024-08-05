//W715_R1GA030

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x4BA32A7C
        defadr memfree,0x4BA32AA4
        defadr memset,0x10839C30
        defadr memcpy,0x1428EA8C
        defadr sprintf,0x1440C668+1
        defadr snwprintf,0x143F5418+1
        defadr _fopen,0x141FD9F4+1
        defadr fclose,0x143D3628+1
        defadr fread,0x1417C0C4+1
        defadr fwrite,0x14337468+1
        defadr fstat,0x144E0CF0+1
        defadr AllocDirHandle,0x1417B064+1
        defadr GetFname,0x1417BD18+1
        defadr DataBrowserDesc_Create,0x142E0044+1
        defadr DataBrowserDesc_SetItemStyle,0x1416AE70+1
        defadr DataBrowserDesc_SetHeaderText,0x1423B2A0+1
        defadr DataBrowserDesc_SetFolders,0x1425DB78+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x1429DBF8+1
        defadr DataBrowser_Create,0x1508C760+1
        defadr DataBrowserDesc_Destroy,0x1416AE0C+1
        defadr getFileExtention,0x144E162C+1
        defadr DataBrowser_isFileInListExt,0x144243A8+1
        defadr Timer_ReSet,0x1417D6E8+1
        defadr Timer_Set,0x144A7E18+1
        defadr Timer_Kill,0x1417DCF8+1
        defadr CreateBook,0x1428A418+1
        defadr BookObj_KillBook,0x14489A0C+1
        defadr BookObj_GotoPage,0x144897F0+1
        defadr BookObj_ReturnPage,0x14216508+1
        defadr FreeBook,0x1412AA0C+1
        defadr FindBook,0x140CD27C+1
        defadr Find_StandbyBook,0x141B0094+1
        defadr BookObj_SetFocus,0x144D3314+1
        defadr GUIObject_SetTitleText,0x14446B3C+1
        defadr GUIObject_Show,0x144D3B34+1
        defadr ListMenu_SetCursorToItem,0x1441E788+1
        defadr GUIObject_SetStyle,0x1412AE88+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142CA17C+1
        defadr GUIonMessage_SetMenuItemText,0x14390474+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x14133D30+1
        defadr GUIonMessage_SetMenuItemInfoText,0x143905C0+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x140763C4+1
        defadr GUIonMessage_SetMenuItemIcon,0x144D49F8+1
        defadr DispObject_SetTitleText,0x14446DF0+1
        defadr ListMenu_GetSelectedItem,0x14283C40+1
        defadr ListMenu_SetItemStyle,0x140BADCC+1
        defadr IsScreenSaverBook,0x142770C0+1
        defadr StatusIndication_SetItemText,0x1430EB64+1
        defadr StatusIndication_ShowNotes,0x154FFBF8+1
        defadr CreateStringInputVA,0x14E73F5C+1
        defadr CreateOneOfMany,0x140BAD50+1
        defadr OneOfMany_SetItemCount,0x14431FB4+1
        defadr OneOfMany_SetChecked,0x14230970+1
        defadr OneOfMany_SetTexts,0x141A2B1C+1
        defadr OneOfMany_GetSelected,0x1445F610+1
        defadr StatusIndication_Item8_SetText,0x154FFBDC+1
        defadr GUIObject_SoftKeys_SetAction,0x1417EFA0+1
        defadr GUIObject_SoftKeys_SetText,0x141C8864+1
        defadr GUIObject_SoftKeys_SetEnable,0x141C88A4+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x14437C48+1
        defadr GUIObject_SoftKeys_RemoveItem,0x1418261C+1
        defadr GUIObject_SoftKeys_SetVisible,0x141C85C8+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x142D1B38+1
        defadr wstrcpy,0x1417BBA8+1
        defadr wstrncpy,0x1431248C+1
        defadr wstrcat,0x1417B684+1
        defadr wstrncat,0x1417C4B8+1
        defadr wstrcmp,0x1417C45C+1
        defadr wstrlen,0x1417C3F0+1
        defadr str2wstr,0x141CD200+1
        defadr strcmp,0x14CC8BA0+1
        defadr strlen,0x14CC8BFC+1
        defadr wstr2strn,0x140C2E64+1
        defadr AB_DEFAULTNBR_GET,0x1416E36C+1
        defadr AB_READPHONENBR,0x1537D7FC+1
        defadr AB_GETNBROFITEMS,0x14324670+1
        defadr PNUM_len,0x140916F0+1
        defadr PNUM2str,0x14384E50+1
        defadr GUIObject_GetDispObject,0x140CBF34+1
        defadr List_Create,0x14312CEC+1
        defadr List_Destroy,0x14312E50+1
        defadr List_InsertFirst,0x143130B8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x144C1D50+1
        defadr REQUEST_DATEANDTIME_GET,0x140C60A8+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x143F98AC+1
        defadr GetFreeBytesOnHeap,0x4BA32BE8
        defadr BookObj_Hide,0x14278FEC+1
        defadr BookObj_Show,0x1402906C+1
        defadr StartAPP,0x14F31744+1
        defadr ListMenu_SetOnMessage,0x143073E8+1
        defadr manifest_GetParam,0x141F99A8+1
        defadr lseek,0x1417B818+1
        defadr get_VBUFFER,0x14000020+1
        defadr SetLampLevel,0x14366F80+1
        defadr List_RemoveAt,0x14311AF8+1
        defadr GetCurrentPID,0x101EB474+1
        defadr List_IndexOf,0x14311E38+1
        defadr alloc,0x101E4534
        defadr receive,0x101E4550
        defadr send,0x101E4540
        defadr sender,0x101E4590
        defadr free_buf,0x101E4560
        defadr create_process,0x101E462C
        defadr start,0x101E4838
        defadr get_ptype,0x101E46EC
        defadr current_process,0x101E463C
        defadr delay,0x101E4580
        defadr hunt,0x101E4738
        defadr kill_proc,0x101E4764
        defadr receive_w_tmo,0x101E45AC
        defadr stop,0x101E4848
        defadr get_envp,0x101EB0F8+1
        defadr set_envp,0x101EB10C+1
        defadr get_bid,0x101E4674
        defadr datetime2unixtime,0x140B7F48+1
        defadr strcpy,0x14CC8BC8+1
        defadr UIEventName,0x141DCD00+1
        defadr MissedEvents,0x4BA1B2D4
        defadr UI_Event,0x140C6B94+1
        defadr UI_Event_wData,0x144A7920+1
        defadr UI_Event_toBookID,0x141F7DE4+1
        defadr UI_Event_toBookIDwData,0x1412A96C+1
        defadr List_Find,0x1417D1DC+1
        defadr List_Get,0x140CD658+1
        defadr wstrrchr,0x1417C404+1
        defadr BookObj_CallSubroutine,0x1448942C+1
        defadr List_InsertLast,0x1417D560+1
        defadr debug_printf,0x14C07038
        defadr PlayFile,0x159313BC+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x141B0570+1
        defadr Profile_SetActive,0x1599FDBC+1
        defadr isKeylocked,0x14072030+1
        defadr IsMediaPlayerVideoBook,0x14492104+1
        defadr REQUEST_DATEFORMAT_GET,0x1430E14C+1
        defadr REQUEST_TIMEFORMAT_GET,0x1430E104+1
        defadr Date2ID,0x143A712C+1
        defadr Time2ID,0x1430E548+1
        defadr CreateListMenu,0x14289814+1
        defadr ListMenu_SetItemCount,0x14284158+1
        defadr ROOT_APP,0x4BA26E94
        defadr GUIObject_SoftKeys_SetInfoText,0x14129A04+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x141A0C04+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x104C8F74+1
        defadr REQUEST_SYSTEM_RESTART,0x104C8F94+1
        defadr GUIObject_SoftKeys_SetTexts,0x14076B14+1
        defadr IsRightNowBook,0x140048D4+1
        defadr IsVolumeControllerBook,0x1419D314+1
        defadr CreateTabMenuBar,0x142E9B30+1
        defadr TabMenuBar_SetTabCount,0x141ED860+1
        defadr TabMenuBar_SetTabGui,0x14129020+1
        defadr TabMenuBar_SetTabIcon,0x14129158+1
        defadr GUIObject_Destroy,0x144D3EFC+1
        defadr GUIInput_SetIcon,0x1431636C+1
        defadr StringInput_GetStringAndLen,0x14205F30+1
        defadr GetAudioControlPtr,0x4BA2D334
        defadr AudioControl_Vibrate,0x14410554+1
        defadr GetVolumeSize,0x1435F168+1
        defadr CreateNOfMany,0x150B7B04+1
        defadr NOfMany_SetTexts,0x14D7D950+1
        defadr NOfMany_SetChecked,0x15977EA0+1
        defadr NOfMany_SetCursor,0x150B7B80+1
        defadr NOfMany_GetCheckedCount,0x144AEBBC+1
        defadr NOfMany_GetChecked,0x15977EB4+1
        defadr NOfMany_SetOnMessage,0x14239314+1
        defadr AudioControl_Init,0x1429D06C+1
        defadr OneOfMany_SetFocused,0x1423083C+1
        defadr OneOfMany_SetOnMessage,0x1407F580+1
        defadr CreateMonitorFeedback,0x1596B430+1
        defadr Feedback_SetText,0x1596B4E0+1
        defadr GetBatteryState,0x1017A92C+1
        defadr get_DisplayGC,0x144A5FAC+1
        defadr DispObject_GetRect,0x140CC138+1
        defadr GC_GetRect,0x140CB0DC+1
        defadr GC_GetXX,0x141A0364+1
        defadr GC_SetXX,0x140B3F30+1
        defadr GC_ValidateRect,0x14461E34+1
        defadr BookObj_AddGUIObject,0x14289808+1
        defadr DrawRect,0x14462318+1
        defadr XGUIList_AddGUIObject,0x14489930+1
        defadr DispObject_InvalidateRect,0x140CBBA4+1
        defadr GUIObject_Create,0x144D3A28+1
        defadr StatusRow_p,0x4BA2BDA0
        defadr root_list_get_session_count,0x14489FD8+1
        defadr root_list_get_session,0x1448A27C+1
        defadr SESSION_GetTopBook,0x15536B8C+1
        defadr MainInput_strlen,0x140C6438+1
        defadr MainInput_getPNUM,0x14091538+1
        defadr BookObj_GetBookID,0x140CCEC0+1
        defadr wstrncmp,0x1432A8E8+1
        defadr DispObject_GetAbsoluteXPos,0x140CB4D0+1
        defadr DispObject_GetAbsoluteYPos,0x140CB45C+1
        defadr GetThemeColor,0x143109F4+1
        defadr REQUEST_SETTING_SILENCE_SET,0x15986218+1
        defadr REQUEST_SETTING_SILENCE_GET,0x141B067C+1
        defadr VCALL_Init,0x14040AE8+1
        defadr VCALL_SetName,0x14CD6110+1
        defadr VCALL_SetNameIcon,0x143C1A04+1
        defadr VCALL_SetNumber,0x1513AE24+1
        defadr VCALL_SetHZ1,0x141F76C8+1
        defadr VCALL_SetHZ2,0x153730EC+1
        defadr MakeVoiceCall,0x1513ABD0+1
        defadr FileDelete,0x1417A13C+1
        defadr GUIObject_SetFocus,0x144D3B08+1
        defadr MSG_SendMessage_CreateMessage,0x143FDC6C+1
        defadr MSG_SendMessage_DestroyMessage,0x143A46B8+1
        defadr MSG_SendMessage_AddRecipient,0x15947940+1
        defadr MSG_SendMessage_Start,0x14EF49E8+1
        defadr get_APP_DESC_TABLE,0x15B9C2D0
        defadr AB_POSITIONNBR_GET,0x1537D934+1
        defadr AB_NAME_ITEM2TextID,0x1537D8E4+1
        defadr AB_NUM_ITEM2TextID,0x14EC9720+1
        defadr GetABRecNum,0x14000548+1
        defadr get_AB_ITEMS_DESC,0x15A4CD40
        defadr SBY_GetMainInput,0x14421038+1
        defadr SBY_GetStatusIndication,0x1400D7E0+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x142E47D4+1
        defadr PID_MMI,0x4BA2BB5C
        defadr DispObject_GetGUI,0x142AD4E0+1
        defadr Display_GetFocusedDispObject,0x1417E38C+1
        defadr DispObject_GetVisible,0x140CCEB4+1
        defadr DispObject_GetDESC,0x15580AF8
        defadr DISP_DESC_SetName,0x142994FC+1
        defadr DispObject_GetName,0x1448A694+1
        defadr DISP_DESC_SetSize,0x142995E0+1
        defadr DISP_DESC_SetOnCreate,0x1429957C+1
        defadr DispObject_GetOnCreate,0x140C7AB8+1
        defadr DISP_DESC_SetOnClose,0x14299578+1
        defadr DispObject_GetOnClose,0x144A6E24+1
        defadr DISP_DESC_SetOnRedraw,0x14299580+1
        defadr DispObject_GetOnRedraw,0x1439468C+1
        defadr DISP_DESC_SetOnKey,0x142996C8+1
        defadr DispObject_GetOnKey,0x144A7E7C+1
        defadr DISP_DESC_SetOnRefresh,0x14299144+1
        defadr DispObject_GetonRefresh,0x1446EB3C+1
        defadr DISP_DESC_SetMethod06,0x14299368+1
        defadr DispObject_GetMethod06,0x140CB6D4+1
        defadr DISP_DESC_SetOnLayout,0x142991AC+1
        defadr DispObject_GetOnLayout,0x14239588+1
        defadr DISP_DESC_SetOnConfig,0x14299268+1
        defadr DispObject_GetOnConfig,0x141CA130+1
        defadr DISP_DESC_SetMethod0A,0x14299204+1
        defadr DispObject_GetMethod0A,0x141CA630+1
        defadr DISP_DESC_SetMethod0B,0x14299A04+1
        defadr DispObject_GetMethod0B,0x15292034+1
        defadr DISP_DESC_SetMethod0C,0x14299140+1
        defadr JavaSession_Manager,0x14000548+1
        defadr JavaSession_GetName,0x140A8400+1
        defadr BookObj_GetSession,0x14489B8C+1
        defadr GUIonMessage_SetNumberOfSubItems,0x1404B99C+1
        defadr GUIonMessage_SubItem_SetText,0x1404B844+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x142D5A04+1
        defadr GoMusic,0x155530CC+1
        defadr PlayFileV,0x1429CFC4+1
        defadr GetSilent,0x1433453C+1
        defadr GetVibrator,0x1440B094+1
        defadr GetAudioSettings,0x14334BDC+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x141D84A4+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x159775DC+1
        defadr DestroyDirHandle,0x1435D938+1
        defadr LastExtDB,0x15BD4448
        defadr GetOtherExtMethods,0x14439078+1
        defadr MessageBox,0x1596AC60+1
        defadr Display_GetHeight,0x140CA618+1
        defadr Display_GetWidth,0x140CA608+1
        defadr PlaySystemSound,0x14177DD0+1
        defadr TabMenuBar_GetFocusedTab,0x1422F62C+1
        defadr TabMenuBar_SetFocusedTab,0x14128A3C+1
        defadr GC_GetPenColor,0x144D52F0+1
        defadr GC_SetPenColor,0x144A609C+1
        defadr GC_SetPixel,0x140CF608+1
        defadr GC_DrawLine,0x14092470+1
        defadr GC_DrawFRect,0x140CEDBC+1
        defadr GC_WritePixels,0x1403F634+1
        defadr png_create_read_struct_2,0x14043B14+1
        defadr png_destroy_read_struct,0x1404419C+1
        defadr png_create_info_struct,0x14043F58+1
        defadr png_destroy_info_struct,0x15878750+1
        defadr png_set_progressive_read_fn,0x14043718+1
        defadr png_process_data,0x140434E8+1
        defadr png_read_update_info,0x142D4398+1
        defadr png_get_progressive_ptr,0x143DDB78+1
        defadr png_get_IHDR,0x142D425C+1
        defadr png_set_strip_16,0x15878ADC+1
        defadr png_set_gray_1_2_4_to_8,0x15878AE8+1
        defadr png_set_gray_to_rgb,0x15878B00+1
        defadr png_get_valid,0x142D44B4+1
        defadr png_set_tRNS_to_alpha,0x142D44CC+1
        defadr png_set_filler,0x150312B8+1
        defadr png_set_palette_to_rgb,0x15878AF4+1
        defadr png_get_rowbytes,0x142D4248+1
        defadr png_progressive_combine_row,0x143DDA44+1
        defadr png_sig_cmp,0x144CFA9C+1
        defadr setjmp,0x10149724+1
        defadr longjmp,0x10030214+1
        defadr inflateInit2_,0x14043D08+1
        defadr inflate,0x143DE810+1
        defadr inflateEnd,0x14044010+1
        defadr memcmp,0x14BEEF90
        defadr strncmp,0x141CB1A8+1
        defadr strncpy,0x1408C308+1
        defadr strcat,0x10001A84+1
        defadr GUIObject_SetTitleType,0x140941E0+1
        defadr GUIonMessage_SetItemDisabled,0x144E7B30+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x151A359C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x151A3624+1
        defadr get_Surfaces,0x4BD706C8
        defadr iconidname2id,0x144E227C+1
        defadr textidname2id,0x144E2090+1
        defadr ListMenu_SetNoItemText,0x141A298C+1
        defadr IsFmRadioBook,0x14306A64+1
        defadr IsAudioPlayerBook,0x142438A4+1
        defadr PlayerControl,0x14D19D0C+1
        defadr SwitchRadioStationFromList,0x1564B508+1
        defadr Shortcut_Run,0x1427CC04+1
        defadr mkdir,0x141CD3CC+1
        defadr rmdir,0x140F6C90+1
        defadr chmod,0x14124404+1
        defadr rename,0x141E70BC+1
        defadr CallID_GetCallStatusDesc,0x1412B72C+1
        defadr CallStatusDesc_GetName,0x144D079C+1
        defadr List_DestroyElements,0x140F0700+1
        defadr strstr,0x1433774C+1
        defadr GPRS_GetLastSessionInfo,0x151C8828+1
        defadr wstrcmpni,0x1417D070+1
        defadr wtoi,0x1432A588+1
        defadr DATE_GetWeekDay,0x1442F2DC+1
        defadr Cale_GetSettings,0x14F8A7DC+1
        defadr wstrwstr,0x1417358C+1
        defadr wstrcmpi,0x1417D03C+1
        defadr wstrchr,0x143F4FA4+1
        defadr GUIObject_SoftKeys_Hide,0x144D32AC+1
        defadr GUIObject_SoftKeys_Show,0x1412AE3C+1
        defadr DispObject_SoftKeys_Get,0x14401F58+1
        defadr StandbyBackground_SetImage,0x14481264+1
        defadr CreateYesNoQuestionVA,0x14DDD114+1
        defadr ListMenu_SetItemSecondLineText,0x142AD3D8+1
        defadr _REQUEST_OAF_START_APPLICATION,0x14063E90+1
        defadr FSX_GetInvalidChar,0x140A4AA4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x141FCDE0+1
        defadr DataBrowserDesc_SetActions,0x14396C54+1
        defadr DataBrowserDesc_SetSelectAction,0x1429DBF0+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x1585DD40+1
        defadr DataBrowserDesc_SetBookID,0x1430B524+1
        defadr DataBrowserDesc_SetItemFilter,0x14E42EE0+1
        defadr DataBrowserDesc_SetOption,0x1429DB64+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x1585DD80+1
        defadr DataBrowserDesc_SetFileExtList,0x141A88B8+1
        defadr FSX_RemoveIllegalSymbolsName,0x14E9E9B4+1
        defadr FILEITEM_Create,0x142CC9C0+1
        defadr FILEITEM_Destroy,0x142CAEAC+1
        defadr CreateDateInputVA,0x150753B0+1
        defadr CreateTimeInputVA,0x14D784B4+1
        defadr StringInput_SetCursorPosition,0x142ECB54+1
        defadr BookObj_CallPage,0x140209A0+1
        defadr DateInput_GetDateInt,0x14065558+1
        defadr TimeInput_GetTimeInt,0x141FF60C+1
        defadr GC_GetBrushColor,0x144D52FC+1
        defadr GC_SetBrushColor,0x144A6044+1
        defadr GC_DrawRoundRect,0x144B0C38+1
        defadr MenuBook_Desktop,0x14126130+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x1508BB5C+1
        defadr BookObj_SoftKeys_SetAction,0x142D2824+1
        defadr BookObj_SoftKeys_SetText,0x14CF5A6C+1
        defadr FindBookByID,0x140CCF58+1
        defadr TextFeedbackWindow,0x142D1CA8+1
        defadr Feedback_SetKeyHook,0x1447F8A0+1
        defadr Feedback_SetOnClose,0x14020B0C+1
        defadr Feedback_SetTimeout,0x14D0B8B0+1
        defadr Feedback_SetTextExtended,0x140203E8+1
        defadr TabMenuBar_SetOnTabSwitch,0x14042524+1
        defadr KeyCode2Name,0x15650AD4+1
        defadr ImageID_Get,0x14481128+1
        defadr ImageID_Free,0x14417780+1
        defadr DataBrowser_CreateSubExecute,0x142CC314+1
        defadr DataBrowser_ExecuteSubroutine,0x142CB10C+1
        defadr FILEITEM_SetFname,0x142CC7C0+1
        defadr FILEITEM_SetPath,0x142CC8B4+1
        defadr FILEITEM_GetFname,0x142CC30C+1
        defadr FILEITEM_GetPath,0x142CC238+1
        defadr FILEITEM_SetFnameAndContentType,0x142CC820+1
        defadr FILEITEM_SetPathAndContentType,0x142CCA84+1
        defadr JavaDialog_Open,0x142D304C+1
        defadr JavaDialog_Close,0x143F6CB4+1
        defadr JavaAppDesc_Get,0x143F6D50+1
        defadr JavaAppDesc_GetFirstApp,0x140289C0+1
        defadr JavaAppDesc_GetNextApp,0x143F6AC0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x144E0004+1
        defadr DispObject_SetRefreshTimer,0x1412F788+1
        defadr DispObject_KillRefreshTimer,0x144A6FEC+1
        defadr IsDataBrowserBook,0x142CB334+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x1436B0BC+1
        defadr Shortcut_Get_MenuItemName,0x142D2658+1
        defadr Shortcut_Get_MenuItemIconID,0x1412A00C+1
        defadr FindBookEx,0x14438180+1
        defadr FILEITEM_CreateCopy,0x142CC58C+1
        defadr BookObj_GetSessionID,0x14312E30+1
        defadr UI_Event_toSID,0x1401348C+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x143CE754+1
        defadr MainInput_Hide,0x1427C26C+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x14181FC8+1
        defadr PNUM2Name,0x14DAB534+1
        defadr SpeedDial_GetPNUM,0x15385BE0+1
        defadr DispObject_GetWindowWidth,0x140CC39C+1
        defadr DispObject_GetWindowHeight,0x140CC4D4+1
        defadr get_system_langID,0x141B1924+1
        defadr lang_get_name,0x1435E13C+1
        defadr w_chdir,0x4BA80C30
        defadr w_fopen,0x100B2D2C+1
        defadr w_fstat,0x100B2D70+1
        defadr w_fwrite,0x100FF0F8+1
        defadr w_fread,0x100FF950+1
        defadr w_lseek,0x141E87C4+1
        defadr w_fclose,0x10147170+1
        defadr w_mkdir,0x4BA3283C
        defadr DirHandle_SetFilterStr,0x14D8F0F4+1
        defadr ImageID_GetIndirect,0x151A1970+1
        defadr unixtime2datetime,0x1442F170+1
        defadr List_Insert,0x144889BC+1
        defadr FileCopy,0x141FDFD0+1
        defadr FileMove,0x141E70BC+1
        defadr DispObject_SetLayerColor,0x140C7EFC+1
        defadr JavaAppDesc_GetJavaAppID,0x144E0430+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x1541ACC0+1
        defadr JavaApp_LogoImageID_Get,0x14F785AC+1
        defadr CreateProgressBar,0x142D2264+1
        defadr ProgressBar_SetText,0x1401FFFC+1
        defadr ProgressBar_SetIcon,0x15080EB0+1
        defadr ProgressBar_SetPercentValue,0x14438070+1
        defadr ProgressBar_SetBarDisabled,0x1403F714+1
        defadr StringInput_DispObject_SetText,0x14E2A85C+1
        defadr GUIObject_SetTitleIcon,0x141F6144+1
        defadr DispObject_SoftKeys_GetParams,0x1417D10C+1
        defadr DispObject_SoftKeys_GetList,0x1417D0B4+1
        defadr BookObj_GetDisplayOrientation,0x140CC130+1
        defadr BookObj_SetDisplayOrientation,0x1412AD68+1
        defadr Display_GetTopBook,0x14F77D28+1
        defadr Display_GetBrightness,0x14DF78B0+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x1585DD2C+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x144001A4+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x14316194+1
        defadr SetTheme,0x14E66800+1
        defadr SoftKeys_GetLabel,0x1417E3A4+1
        defadr SoftKeys_Update,0x1417E190+1
        defadr IncommingCall_Reject,0x155413F4+1
        defadr IncommingCall_Mute,0x14DB12FC+1
        defadr Bluetooth_GetState,0x141534AC+1
        defadr Bluetooth_GetPhoneVisibility,0x14DBE1F4+1
        defadr Bluetooth_isBusy,0x14153434+1
        defadr USB_isConnected,0x1528F14C+1
        defadr w_diropen,0x4BA3284C
        defadr w_dirread,0x142ECFDC+1
        defadr w_dirclose,0x4BA80C10
        defadr w_rename,0x141E7A00+1
        defadr w_remove,0x141E7D20+1
        defadr IsCameraBook,0x1415508C+1
        defadr IsSoundRecorderBook,0x141E1B8C+1
        defadr StringInput_MenuItem_SetPriority,0x140132A0+1
        defadr Video_ActionBack,0x14232FC8+1
        defadr Video_ExtractFrame,0x15546264+1
        defadr Video_ZoomOn,0x15545B1C+1
        defadr RightNow_SetActive,0x1412AB30+1
        defadr Video_Play,0x15545A00+1
        defadr Video_Pause,0x14E66B28+1
        defadr Audio_Pause,0x1405AB24+1
        defadr Audio_Play,0x14D9B770+1
        defadr CreatePercentInputVA,0x150EE184+1
        defadr PercentInput_GetPercent,0x15817AD0+1
        defadr GUIonMessage_SetLineSeparator,0x159775D0+1
        defadr PHF_GetState,0x152B2D64+1
        defadr CHF_GetState,0x152B2DF0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1412AC38+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1412AD5C+1
        defadr SetTrayIcon,0x1417DAA0+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x159860B4+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x159861B0+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x15986174+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x15986284+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x15986114+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x1403A604+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x15350948+1
        defadr SoundRecorderDesc_Create,0x15133B68+1
        defadr SoundRecorderDesc_Destroy,0x15564804+1
        defadr SoundRecorderDesc_SetBookID,0x15564820+1
        defadr SoundRecorderDesc_SetType,0x1556484C+1
        defadr SoundRecorderDesc_SetFolder,0x15564860+1
        defadr SoundRecorderDesc_SetFname,0x1510EF24+1
        defadr SoundRecorderDesc_SetRecordSize,0x15564888+1
        defadr SoundRecorder_Create,0x15564900+1
        defadr SoundRecorder_RecordCall,0x151339BC+1
        defadr Browser_OpenURI,0x1405CC1C+1
        defadr GetURIScheme,0x143C9788+1
        defadr CreateURI,0x143C9130+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x1428C434+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x1421AC74+1
        defadr Alarm_GetState,0x1430377C+1
        defadr Alarm_GetTIME,0x151A5464+1
        defadr Alarm_GetWeekSettings,0x1430362C+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x141B0120+1
        defadr IncommingCall_Accept,0x155410A0+1
        defadr MediaPlayer_SoftKeys_SetText,0x144377C4+1
        defadr MediaPlayer_SoftKeys_SetAction,0x1443777C+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x1443753C+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x144374FC+1
        defadr DispObject_Show,0x140CBACC+1
        defadr Request_EventChannel_Subscribe,0x108862E0+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x151CD1DC+1
        defadr Request_ICA_ShutdownAllConnections,0x10557908+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x14239B50+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1585DD88+1
        defadr GUIonMessage_GetMsg,0x142CA26C+1
        defadr GUIonMessage_GetBook,0x142CA45C+1
        defadr GUIonMessage_GetGui,0x1416DA14+1
        defadr GUIonMessage_GetSelectedItem,0x1416DD4C+1
        defadr GUIonMessage_GetPrevSelectedItem,0x159775C4+1
        defadr ObexSendFile,0x1520D4C0+1
        defadr Feedback_SetManualScrollingText,0x14CFFC04+1
        defadr EqualizerGain_Set,0x1440B47C+1
        defadr CANVAS_Get_GviGC,0x100AE91C+1
        defadr GVI_BitBlt,0x100AE600+1
        defadr GVI_StretchBlt,0x1051C17C+1
        defadr GVI_TransformBlt,0x10128AB0+1
        defadr GVI_CreatePen,0x1016C004+1
        defadr GVI_CreateDashedPen,0x102BEEA8+1
        defadr GVI_CreateSolidBrush,0x100BA000+1
        defadr GVI_Delete_GVI_Object,0x1004D978+1
        defadr GVI_DrawEllipse,0x1051BC60+1
        defadr GVI_DrawLine,0x100A26C0+1
        defadr GVI_DrawLines,0x1051CB50+1
        defadr GVI_DrawPolyLine,0x1051CBD4+1
        defadr GVI_DrawRectangle,0x101869E8+1
        defadr GVI_DrawRoundRect,0x100A3BFC+1
        defadr GVI_DrawSolidLines,0x1051C780+1
        defadr GVI_DrawSolidPolyLine,0x1051C984+1
        defadr GVI_DrawSolidRectangle,0x10186764+1
        defadr GVI_FillEllipse,0x1051C044+1
        defadr GVI_FillPolygon,0x100A4624+1
        defadr GVI_FillRectangle,0x100A23DC+1
        defadr GVI_FillRectangles,0x1051CCD0+1
        defadr GVI_FillSolidEllipse,0x1051C0F4+1
        defadr GVI_FillSolidRectangle,0x1002C560+1
        defadr GVI_FillSolidRoundRect,0x10271C5C+1
        defadr GVI_FillSolidTriangle,0x1000F20C+1
        defadr GC_CreateMemoryGC,0x1403F090+1
        defadr GC_FreeGC,0x144A6D78+1
        defadr Settings_ShowNumber_Get,0x15513540+1
        defadr GVI_CreateBitmap,0x1051B954+1
        defadr GVI_CreateMemoryGC,0x1004E414+1
        defadr GVI_DeleteMemoryGC,0x101151E0+1
        defadr StringInput_DispObject_SetLanguage,0x14D17BD8+1
        defadr List_InsertSorted,0x14488960+1
        defadr ListMenu_SetItemIcon,0x14280418+1
        defadr wstrnupr,0x14191CC8+1
        defadr wstrnlwr,0x142ECD70+1
        defadr ListMenu_SetItemTextScroll,0x14436C88+1
        defadr GUIObject_SetListTextColor,0x15977B48+1
        defadr DispObject_SetTitleTextColor,0x15292784+1
        defadr DispObject_SetListTextColor,0x14F15378+1
        defadr DispObject_SetCursorImage,0x14E2ED14+1
        defadr DispObject_SetBackgroundImage,0x15973B9C+1
        defadr DispObject_SetTitleBackgroundImage,0x152927A0+1
        defadr TabMenuBar_SetTabTitle,0x1428BAD4+1
        defadr GUIObject_GetBook,0x140CC124+1
        defadr SoftKeys_GetSelectedAction,0x1427CA24+1
        defadr MonitorFeedback_SetTimer,0x1596B4D4+1
        defadr ListMenu_DestroyItems,0x142844C8+1
        defadr DispObject_SetScrollBarBackgroundColor,0x143C8498+1
        defadr DispObject_SetScrollBarColor,0x143C8470+1
        defadr DispObject_SetSoftkeysColor,0x1441EA68+1
        defadr YesNoQuestion_SetIcon,0x1433C1E8+1
        defadr GUIObject_SetBacklightTimeout,0x142F5710+1
        defadr ListMenu_SetHotkeyMode,0x1441E820+1
        defadr ListMenu_SetSearchLanguageMode,0x144B4DD4+1
        defadr ListMenu_EnableSearchHeader,0x14394B00+1
        defadr GUIonMessage_GetSearchString,0x14F2E9AC+1
        defadr GUIonMessage_GetSearchStringLength,0x142A1F64+1
        defadr EqualizerGain_Get,0x15930B94+1
        defadr Theme_DestroyMenuIcons,0x14F73FB0+1
        defadr CoCreateInstance,0x14011498+1
        defadr GUIObject_SetSecondRowTitleText,0x144467DC+1
        defadr ListMenu_GetItemCount,0x140272FC+1
        defadr OSE_GetShell,0x14162134+1
        defadr swscanf,0x140C1BA8+1
        defadr sscanf,0x101E86E0+1
        defadr BookObj_WindowSetWantsFocus,0x142D5574+1
        defadr BookObj_StayOnTop,0x142C6E94+1
        defadr DispObject_WindowSetPosition,0x140CB548+1
        defadr DispObject_WindowSetSize,0x140CB6F4+1
        defadr Feedback_DispObject_GetText,0x15814F34+1
        defadr DispObject_SoftKeys_ExecuteAction,0x1441DEA8+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x14447578+1
        defadr DispObject_SetAnimation,0x14EDFB38+1
        defadr GUIObject_SetZOrder,0x14095578+1
        defadr DisplayGC_AddRef,0x144D5BE4+1
        defadr TextObject_SetText,0x141864EC+1
        defadr TextObject_SetFont,0x144A4C94+1
        defadr RichTextLayout_GetTextWidth,0x14339FF4+1
        defadr TextID_Destroy,0x14185B90+1
        defadr TextID_Create,0x14184D2C+1
        defadr TextID_CreateIntegerID,0x1401F994+1
        defadr TextID_Copy,0x141852DC+1
        defadr TextID_GetLength,0x14186394+1
        defadr TextID_GetWString,0x14185858+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x14281180+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x143A3B70+1
        defadr GUIObject_GetStyle,0x140CBF40+1
        defadr DispObject_GetStyle,0x140CC00C+1
        defadr DispObject_SetStyle,0x143107C4+1
        defadr DispObject_SoftKeys_Show,0x1412AE04+1
        defadr DispObject_SoftKeys_Hide,0x144D32C0+1
        defadr DispObject_SetBacklightMode,0x142F4D38+1
        defadr FSX_MakeFullPath,0x1417AEF4+1
        defadr FSX_FreeFullPath,0x1433ADD4+1
        defadr FSX_IsFileExists,0x144180A0+1
        defadr Volume_Set,0x14333858+1
        defadr Volume_Get,0x14334BDC+1
        defadr MetaData_GetTags,0x15860700+1
        defadr CreateMessageBox,0x14DA25D0+1
        defadr List_GetCount,0x140CD2E0+1
        defadr Feedback_CloseAction,0x1414C8FC+1
        defadr ListMenu_SetTexts,0x1428470C+1
        defadr CreateStringInput,0x1406326C+1
        defadr StringInput_SetMode,0x142D1B28+1
        defadr StringInput_SetFixedText,0x42DFDD8+1
        defadr StringInput_SetMinLen,0x144B1A6C+1
        defadr StringInput_SetMaxLen,0x14063348+1
        defadr StringInput_SetEnableEmptyText,0x142D307C+1
        defadr StringInput_SetActionOK,0x142D19C0+1
        defadr Sound_SetMessageAlert,0x14D4CAE0+1
        defadr Sound_SetAlarmsignal,0x15254328+1
        defadr Sound_AddToContact,0x1536F9E4+1

        defadr FreeAllBook,0x155535E8+1

        defadr MusicApplication_PrevAction,0x14022D40+1
        defadr MusicApplication_CancelAction,0x15004BBC+1
        defadr MusicApplication_ShowMyMusic,0x1544E38C+1
        defadr MusicApplication_Minimize,0x14EFE2F0+1
        defadr MusicApplication_Keyboard,0x14437394+1

        defadr pg_MusicApplication_PreviousEvent,0x1544D9EC+1
        defadr pg_MusicApplication_CancelEvent,0x1544DA4C+1
        defadr pg_MusicApplication_ExitEvent,0x14FDEF90+1

        defadr Music_Gui_NowPlaying_OnRedraw,0x1406036C+1
        defadr Music_Gui_NowPlaying_OnCreate,0x14FFAB90+1
        defadr Music_Gui_NowPlaying_OnClose,0x150741D4+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x15014EB0+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x14436AB0+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x14ED4498+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x14FDE708+1

        defadr FeedbackTicker_OnRedraw,0x14DBE9E0+1

//------------------------------------------------------------------------------

        EXTERN New_Music_Gui_NowPlaying_OnRedraw
        EXTERN New_Music_Gui_NowPlaying_OnCreate
        EXTERN New_Music_Gui_NowPlaying_OnClose
        EXTERN New_Music_Gui_NowPlaying_OnKey

        EXTERN PATCH_UI_MEDIAPLAYER_AUDIO_ON_NEW_TRACK_EVENT
        EXTERN PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        EXTERN PATCH_UI_MEDIAPLAYER_CREATED_EVENT
        EXTERN PATCH_UI_MEDIAPLAYER_ON_ENTER_EVENT

        EXTERN New_Action
        EXTERN New_SoftKeys
        EXTERN Set_WALKMAN_GUI_STYLE
        EXTERN refresh_gui

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
        BEQ     exit_code

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_3
        CODE16
        CMP     R0, #0
        BEQ     Continue

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_1
        CODE16
        ADD     r0, r4, #0
        LDR     r3, =IsAudioPlayerBook
        BLX     r3
        CMP     r0, #0
        BEQ     Continue
        CMP     r5, #0
        beq     loadVerticalData
        CMP     r5, #1
        beq     loadHorizontalData
        CMP     r5, #2
        beq     loadHorizontalData
        B       Continue
loadHorizontalData:
        LDR     r3, =LoadLandscapeData
        BLX     r3
        B       Continue
loadVerticalData:
        LDR     r3, =LoadPortraitData
        BLX     r3
Continue:
        ldr     r3, =0x1448941C+1
        blx     r3
exit_code:
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
        LDR     r3, =AddNew_SoftKeys
        BX      r3

        RSEG  CODE
        CODE16
AddNew_SoftKeys:
        LDR     R0, [R4,#0x20]
        ADD     R2, R7, #0
        MOV     R1, #7
        LDR	R3, =MediaPlayer_SoftKeys_AddHelpStr
        BLX	R3
        ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR	R3, =0x14FDE28A+1
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
        BL      refresh_gui
        LDRB    R1, [R6,#1]
        LDR     R0, [R5,#0]
        LDR     R3, =0x14EE444C+1
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
        BL      refresh_gui
        LDRB    R1, [R6,#0]
        LDR     R0, [R5,#0]
        LDR     R3, =0x14EE4480+1
        BX      R3

//------------------------------------------------------------------------------

        END
