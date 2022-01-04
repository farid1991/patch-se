//G502_R1FA037

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x1009ED08
        defadr memfree,0x1009ED30
        defadr memset,0x2A1C07A0
        defadr memcpy,0x100BEDA4
        defadr sprintf,0x10554018+1
        defadr snwprintf,0x105544CC+1
        defadr _fopen,0x10FDBE10+1
        defadr fclose,0x115AE044+1
        defadr fread,0x10FDD554+1
        defadr fwrite,0x10FDD720+1
        defadr fstat,0x10FDC708+1
        defadr AllocDirHandle,0x10FD9E08+1
        defadr GetFname,0x10FD9FD8+1
        defadr DataBrowserDesc_Create,0x11022DC0+1
        defadr DataBrowserDesc_SetItemStyle,0x11023040+1
        defadr DataBrowserDesc_SetHeaderText,0x11023070+1
        defadr DataBrowserDesc_SetFolders,0x11023058+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x11023078+1
        defadr DataBrowser_Create,0x1101F2D0+1
        defadr DataBrowserDesc_Destroy,0x11022E70+1
        defadr getFileExtention,0x10FDF150+1
        defadr DataBrowser_isFileInListExt,0x10FDA23C+1
        defadr Timer_ReSet,0x116005E0+1
        defadr Timer_Set,0x116005AC+1
        defadr Timer_Kill,0x11600638+1
        defadr CreateBook,0x116039F4+1
        defadr BookObj_KillBook,0x11603B10+1
        defadr BookObj_GotoPage,0x1160376C+1
        defadr BookObj_ReturnPage,0x116038D4+1
        defadr FreeBook,0x11604000+1
        defadr FindBook,0x1160354C+1
        defadr Find_StandbyBook,0x1160F55C+1
        defadr BookObj_SetFocus,0x11603C94+1
        defadr GUIObject_SetTitleText,0x116A7178+1
        defadr GUIObject_Show,0x116A6C4C+1
        defadr ListMenu_SetCursorToItem,0x1165854C+1
        defadr GUIObject_SetStyle,0x116A6CA4+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11659070+1
        defadr GUIonMessage_SetMenuItemText,0x1165907C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x116590AC+1
        defadr GUIonMessage_SetMenuItemInfoText,0x1165908C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x1165909C+1
        defadr GUIonMessage_SetMenuItemIcon,0x116590BC+1
        defadr DispObject_SetTitleText,0x1169AF70+1
        defadr ListMenu_GetSelectedItem,0x11658560+1
        defadr ListMenu_SetItemStyle,0x116585B0+1
        defadr GC_PutChar,0x116A4BD4+1
        defadr IsScreenSaverBook,0x116DDAEC+1
        defadr StatusIndication_SetItemText,0x116B4D98+1
        defadr StatusIndication_ShowNotes,0x11610664+1
        defadr CreateStringInputVA,0x11636244+1
        defadr CreateOneOfMany,0x1165A6A8+1
        defadr OneOfMany_SetItemCount,0x1165A854+1
        defadr OneOfMany_SetChecked,0x1165A870+1
        defadr OneOfMany_SetTexts,0x1165A8A4+1
        defadr OneOfMany_GetSelected,0x1165A880+1
        defadr StatusIndication_Item8_SetText,0x11610570+1
        defadr GUIObject_SoftKeys_SetAction,0x116C046C+1
        defadr GUIObject_SoftKeys_SetText,0x116C04E4+1
        defadr GUIObject_SoftKeys_SetEnable,0x116C05D4+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x116C058C+1
        defadr GUIObject_SoftKeys_RemoveItem,0x116C0420+1
        defadr GUIObject_SoftKeys_SetVisible,0x116C0568+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x116C07EC+1
        defadr wstrcpy,0x10FCD2D0+1
        defadr wstrncpy,0x10FCD2E8+1
        defadr wstrcat,0x10FCD314+1
        defadr wstrncat,0x10554C34+1
        defadr wstrcmp,0x10FCD2A0+1
        defadr wstrlen,0x10FCD28C+1
        defadr str2wstr,0x10FCE554+1
        defadr strcmp,0x105542A0+1
        defadr strlen,0x105542FC+1
        defadr wstr2strn,0x10FCD3AC+1
        defadr TextID_CreateIntegerID,0x1168426C+1
        defadr TextID_Create,0x1168442C+1
        defadr TextID_GetString,0x116849D0+1
        defadr TextID_GetWString,0x11684898+1
        defadr TextID_GetLength,0x11684798+1
        defadr TextID_Destroy,0x116846C4+1
        defadr AB_DEFAULTNBR_GET,0x10F62A38+1
        defadr AB_READSTRING,0x10F68000+1
        defadr AB_READPHONENBR,0x10F680D0+1
        defadr AB_GETNBROFITEMS,0x10F68188+1
        defadr PNUM_len,0x11683A30+1
        defadr PNUM2str,0x114ADA50+1
        defadr GUIObject_GetDispObject,0x116A6AC0+1
        defadr List_Create,0x1142AC9C+1
        defadr List_Destroy,0x1142ACC4+1
        defadr List_InsertFirst,0x1142AE10+1
        defadr Gif2ID,0x10FC259C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10FC27CC+1
        defadr REQUEST_DATEANDTIME_GET,0x10EB0E84+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x116DA648+1
        defadr GetFreeBytesOnHeap,0x11610D54+1
        defadr BookObj_Hide,0x11603CBC+1
        defadr BookObj_Show,0x11603CCC+1
        defadr StartAPP,0x1160F70C+1
        defadr ListMenu_SetOnMessage,0x11658684+1
        defadr manifest_GetParam,0x10FE94D8+1
        defadr lseek,0x10FDD8C8+1
        defadr get_VBUFFER,0x100ABCF9
        defadr List_RemoveAt,0x1142AD9C+1
        defadr GetCurrentPID,0x100A9C3C+1
        defadr List_IndexOf,0x1142ADD0+1
        defadr alloc,0x100F3FF4
        defadr receive,0x100F4010
        defadr send,0x100F4000
        defadr sender,0x100F4050
        defadr free_buf,0x100F4020
        defadr create_process,0x100F40EC
        defadr start,0x100F430C
        defadr get_ptype,0x100F41BC
        defadr current_process,0x100F4108
        defadr delay,0x100F4040
        defadr hunt,0x100F4208
        defadr kill_proc,0x100F4234
        defadr receive_w_tmo,0x100F406C
        defadr stop,0x100F431C
        defadr get_mem,0x100F4188
        defadr get_envp,0x100A9A1C+1
        defadr set_envp,0x100A9A30+1
        defadr get_bid,0x100F4140
        defadr datetime2unixtime,0x111E0800+1
        defadr strcpy,0x105542C8+1
        defadr CreateMessage,0x111DFFAC+1
        defadr SendMessage,0x111E0000+1
        defadr WaitMessage,0x111E0088+1
        defadr FreeMessage,0x111E009C+1
        defadr SendDispatchMessage,0x111ACE54+1
        defadr UIEventName,0x11600B08+1
        defadr MissedEvents,0x2A285648
        defadr UI_Event,0x1160283C+1
        defadr UI_Event_wData,0x1160284C+1
        defadr UI_Event_toBookID,0x11602894+1
        defadr UI_Event_toBookIDwData,0x116028A8+1
        defadr List_Find,0x1142AF6C+1
        defadr List_Get,0x1142AEBC+1
        defadr wstrrchr,0x10FCE610+1
        defadr BookObj_CallSubroutine,0x116037E0+1
        defadr List_InsertLast,0x1142AE18+1
        defadr debug_printf,0x2A20E3E1
        defadr PlayFile,0x111EB278+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x1179F4A8+1
        defadr Profile_SetActive,0x117A19C8+1
        defadr SetBrightnessOfScreen,0x11625698+1
        defadr isKeylocked,0x116DDB28+1
        defadr IsMediaPlayerVideoBook,0x115E7940+1
        defadr Vibra,0x111B905C+1
        defadr REQUEST_DATEFORMAT_GET,0x10EB1064+1
        defadr REQUEST_TIMEFORMAT_GET,0x10EB1184+1
        defadr Date2ID,0x1160D0DC+1
        defadr Time2ID,0x1160CFF8+1
        defadr CreateListMenu,0x11658344+1
        defadr ListMenu_SetItemCount,0x11658574+1
        defadr ROOT_APP,0x2A281BD0
        defadr GUIObject_SoftKeys_SetInfoText,0x116C04D0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x116C0608+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11610D9C+1
        defadr REQUEST_SYSTEM_RESTART,0x11610DAC+1
        defadr GUIObject_SoftKeys_SetTexts,0x116C053C+1
        defadr IsRightNowBook,0x116CFD44+1
        defadr IsVolumeControllerBook,0x116DFFC0+1
        defadr CreateTabMenuBar,0x116B3C20+1
        defadr TabMenuBar_SetTabCount,0x116B3E38+1
        defadr TabMenuBar_SetTabGui,0x116B3CF0+1
        defadr TabMenuBar_SetTabIcon,0x116B3D70+1
        defadr GUIObject_Destroy,0x116A6A50+1
        defadr GUIInput_SetIcon,0x116A6D30+1
        defadr StringInput_GetStringAndLen,0x11636AC8+1
        defadr GetAudioControlPtr,0x2A2780C4
        defadr AudioControl_Vibrate,0x10D28234+1
        defadr GetVolumeSize,0x10FDEEE4+1
        defadr CreateNOfMany,0x1165A108+1
        defadr NOfMany_SetTexts,0x1165A32C+1
        defadr NOfMany_SetChecked,0x1165A2B0+1
        defadr NOfMany_SetCursor,0x1165A278+1
        defadr NOfMany_GetCheckedCount,0x1165A2D4+1
        defadr NOfMany_GetChecked,0x1165A2C4+1
        defadr NOfMany_SetOnMessage,0x1165A324+1
        defadr AudioControl_Init,0x111EB3C4+1
        defadr OneOfMany_SetFocused,0x1165A838+1
        defadr OneOfMany_SetOnMessage,0x1165A89C+1
        defadr CreateMonitorFeedback,0x1160ABE4+1
        defadr Feedback_SetText,0x1160AC98+1
        defadr GetBatteryState,0x105DD82C+1
        defadr get_DisplayGC,0x116A418C+1
        defadr DispObject_GetRect,0x1169C560+1
        defadr GC_GetRect,0x116A47D4+1
        defadr GC_GetXX,0x116A4AD8+1
        defadr GC_SetXX,0x116A4ACC+1
        defadr GC_ValidateRect,0x116A4784+1
        defadr BookObj_AddGUIObject,0x11603D48+1
        defadr DrawRect,0x1169F1F0+1
        defadr DrawString,0x1169F4F0+1
        defadr XGUIList_AddGUIObject,0x11604194+1
        defadr DispObject_InvalidateRect,0x1169C320+1
        defadr GUIObject_Create,0x116A6960+1
        defadr SetFont,0x116A00A8+1
        defadr StatusRow_p,0x2A2841D8
        defadr root_list_get_session_count,0x11601BC4+1
        defadr root_list_get_session,0x11601BD0+1
        defadr SESSION_GetTopBook,0x116014C0+1
        defadr MainInput_strlen,0x116CCEA8+1
        defadr MainInput_getPNUM,0x116CCED8+1
        defadr BookObj_GetBookID,0x116040AC+1
        defadr wstrncmp,0x10554C60+1
        defadr DispObject_GetAbsoluteXPos,0x1169D53C+1
        defadr DispObject_GetAbsoluteYPos,0x1169D570+1
        defadr DispObject_GetWindow,0x1169C850+1
        defadr GetThemeColor,0x116C4554+1
        defadr REQUEST_SETTING_SILENCE_SET,0x1179EEDC+1
        defadr REQUEST_SETTING_SILENCE_GET,0x1179EE84+1
        defadr VCALL_Init,0x10F5A1C0+1
        defadr VCALL_SetName,0x10F5A2B8+1
        defadr VCALL_SetNameIcon,0x10F5A318+1
        defadr VCALL_SetNumber,0x10F5A2D8+1
        defadr VCALL_SetHZ1,0x10F5A2FC+1
        defadr VCALL_SetHZ2,0x10F5A308+1
        defadr MakeVoiceCall,0x10F59D78+1
        defadr FileDelete,0x10FDC830+1
        defadr GUIObject_SetFocus,0x116A6BEC+1
        defadr MSG_SendMessage_CreateMessage,0x11264574+1
        defadr MSG_SendMessage_DestroyMessage,0x11264C8C+1
        defadr MSG_SendMessage_AddRecipient,0x11264750+1
        defadr MSG_SendMessage_Start,0x11264BC4+1
        defadr get_APP_DESC_TABLE,0x11A69DD8
        defadr AB_POSITIONNBR_GET,0x10F68370+1
        defadr AB_NAME_ITEM2TextID,0x10F68284+1
        defadr AB_NUM_ITEM2TextID,0x10F682E8+1
        defadr GetABRecNum,0x10F7B8CA+1
        defadr get_AB_ITEMS_DESC,0x11A20184
        defadr SBY_GetMainInput,0x100ABCFC+1
        defadr SBY_GetStatusIndication,0x10FB4C24+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10EDAF98+1
        defadr PID_MMI,0x2A2775F0
        defadr DispObject_GetGUI,0x1169BC14+1
        defadr Display_GetFocusedDispObject,0x1169BB60+1
        defadr DispObject_GetVisible,0x1169C1B8+1
        defadr DispObject_GetDESC,0x100B8C68+1
        defadr DISP_DESC_SetName,0x116971FC+1
        defadr DispObject_GetName,0x1169D2AC+1
        defadr DISP_DESC_SetSize,0x11697200+1
        defadr DISP_DESC_SetOnCreate,0x11697204+1
        defadr DispObject_GetOnCreate,0x11697280+1
        defadr DISP_DESC_SetOnClose,0x11697208+1
        defadr DispObject_GetOnClose,0x1169729C+1
        defadr DISP_DESC_SetOnRedraw,0x1169720C+1
        defadr DispObject_GetOnRedraw,0x116972B8+1
        defadr DISP_DESC_SetOnKey,0x11697214+1
        defadr DispObject_GetOnKey,0x116972F0+1
        defadr DISP_DESC_SetOnRefresh,0x11697210+1
        defadr DispObject_GetonRefresh,0x116972D4+1
        defadr DISP_DESC_SetMethod06,0x11697218+1
        defadr DispObject_GetMethod06,0x1169730C+1
        defadr DISP_DESC_SetOnLayout,0x11697220+1
        defadr DispObject_GetOnLayout,0x11697344+1
        defadr DISP_DESC_SetOnConfig,0x11697224+1
        defadr DispObject_GetOnConfig,0x11697360+1
        defadr DISP_DESC_SetMethod0A,0x11697228+1
        defadr DispObject_GetMethod0A,0x1169737C+1
        defadr DISP_DESC_SetMethod0B,0x1169722C+1
        defadr DispObject_GetMethod0B,0x11697398+1
        defadr DISP_DESC_SetMethod0C,0x11697230+1
        defadr JavaSession_Manager,0x1114AF10+1
        defadr JavaSession_GetName,0x1115F714+1
        defadr TextID_Copy,0x116845D0+1
        defadr BookObj_GetSession,0x1160404C+1
        defadr GUIonMessage_SetNumberOfSubItems,0x11659110+1
        defadr GUIonMessage_SubItem_SetText,0x11659188+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x1165917C+1
        defadr GoMusic,0x11493130+1
        defadr GUIonMessage_SubItem_GetSelectedIndex,0x11659158+1
        defadr GUIonMessage_SubItem_SetDisabled,0x116591F8+1
        defadr PlayFileV,0x111EB27C+1
        defadr GetSilent,0x111B8574+1
        defadr GetVibrator,0x111B4450+1
        defadr GetAudioSettings,0x111B93F8+1
        defadr GUIonMessage_SubItem_GetCreatedIndex,0x11659170+1
        defadr GUIonMessage_SubItem_GetSelectedParentIndex,0x11659164+1
        defadr DestroyDirHandle,0x10FDA154+1
        defadr LastExtDB,0x11A364D8
        defadr GetOtherExtMethods,0x11019448+1
        defadr MessageBox,0x116096F0+1
        defadr Display_GetHeight,0x116B61FC+1
        defadr Display_GetWidth,0x116B6208+1
        defadr PlaySystemSound,0x111EB220+1
        defadr TabMenuBar_GetFocusedTab,0x116B3CE4+1
        defadr TabMenuBar_SetFocusedTab,0x116B3CD4+1
        defadr GC_GetPenColor,0x116A49E0+1
        defadr GC_SetPenColor,0x116A49A4+1
        defadr GC_SetPixel,0x116A4624+1
        defadr GC_DrawLine,0x116A5464+1
        defadr GC_DrawFRect,0x116A55EC+1
        defadr GC_WritePixels,0x116A46B0+1
        defadr png_create_read_struct_2,0x10B5FB3C+1
        defadr png_destroy_read_struct,0x10B5FC88+1
        defadr png_create_info_struct,0x10B5E2E4+1
        defadr png_destroy_info_struct,0x10B5E318+1
        defadr png_set_progressive_read_fn,0x10B5FB14+1
        defadr png_process_data,0x10B5EAD4+1
        defadr png_read_update_info,0x10B5FC5C+1
        defadr png_get_progressive_ptr,0x10B5FB38+1
        defadr png_get_IHDR,0x10B5E7A0+1
        defadr png_set_strip_16,0x10B5FE28+1
        defadr png_set_gray_1_2_4_to_8,0x10B5FE34+1
        defadr png_set_gray_to_rgb,0x10B5FE58+1
        defadr png_get_valid,0x10B5E774+1
        defadr png_set_tRNS_to_alpha,0x10B5FE4C+1
        defadr png_set_filler,0x10B62BB4+1
        defadr png_set_palette_to_rgb,0x10B5FE40+1
        defadr png_get_rowbytes,0x10B5E78C+1
        defadr png_progressive_combine_row,0x10B5FAF4+1
        defadr png_sig_cmp,0x10B5E1DC+1
        defadr setjmp,0x100C3040
        defadr longjmp,0x100C3064
        defadr inflateInit2_,0x10B63874+1
        defadr inflate,0x10B63A1C+1
        defadr inflateEnd,0x10B64D14+1
        defadr memcmp,0x2A1C0820
        defadr strncmp,0x10554338+1
        defadr strncpy,0x1055436C+1
        defadr strcat,0x10554268+1
        defadr GUIObject_SetTitleType,0x116A715C+1
        defadr GUIonMessage_SetItemDisabled,0x1165911C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10FC2844+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10FC28CC+1
        defadr get_Surfaces,0x2A443154
        defadr iconidname2id,0x10CFB8F8+1
        defadr textidname2id,0x10EA71D8+1
        defadr ListMenu_SetNoItemText,0x11658704+1
        defadr IsFmRadioBook,0x1132CF6C+1
        defadr IsAudioPlayerBook,0x115B8270+1
        defadr PlayerControl,0x115B7E34+1
        defadr SwitchRadioStationFromList,0x1132B0B8+1
        defadr Shortcut_Run,0x116C6F18+1
        defadr mkdir,0x10FD95E8+1
        defadr rmdir,0x10FD99B4+1
        defadr chmod,0x10FDC76C+1
        defadr rename,0x10FDCD4C+1
        defadr GetImageWidth,0x116A0674+1
        defadr GetImageHeight,0x116A0688+1
        defadr CallID_GetCallStatusDesc,0x10F23FB0+1
        defadr CallStatusDesc_GetName,0x10F235D4+1
        defadr List_DestroyElements,0x1142AFB0+1
        defadr strstr,0x10554408+1
        defadr GPRS_GetLastSessionInfo,0x117161E8+1
        defadr wstrcmpni,0x10FCE6AC+1
        defadr wtoi,0x11600004+1
        defadr DATE_GetWeekDay,0x111E0AFC+1
        defadr Cale_GetSettings,0x10EE8204+1
        defadr wstrwstr,0x10554DC0+1
        defadr wstrcmpi,0x10FCE6F0+1
        defadr wstrchr,0x10554BA8+1
        defadr GUIObject_SoftKeys_Hide,0x116C0838+1
        defadr GUIObject_SoftKeys_Show,0x116C0844+1
        defadr DispObject_SoftKeys_Get,0x116BCE0C+1
        defadr StandbyBackground_SetImage,0x11693FC0+1
        defadr CreateYesNoQuestionVA,0x116B5BFC+1
        defadr ListMenu_SetItemSecondLineText,0x1165895C+1
        defadr _REQUEST_OAF_START_APPLICATION,0x1100B774+1
        defadr FSX_GetInvalidChar,0x10FDECD4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x11023060+1
        defadr DataBrowserDesc_SetActions,0x11023034+1
        defadr DataBrowserDesc_SetSelectAction,0x11022FDC+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x11022FE4+1
        defadr DataBrowserDesc_SetBookID,0x11022FC0+1
        defadr DataBrowserDesc_SetItemFilter,0x11022F64+1
        defadr DataBrowserDesc_SetOption,0x11023090+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x110230F8+1
        defadr DataBrowserDesc_SetFileExtList,0x11022F6C+1
        defadr FSX_RemoveIllegalSymbolsName,0x1102C078+1
        defadr FILEITEM_Create,0x1102BA90+1
        defadr FILEITEM_Destroy,0x1102BBC0+1
        defadr CreateDateInputVA,0x116B3F6C+1
        defadr CreateTimeInputVA,0x116B57C0+1
        defadr StringInput_SetCursorPosition,0x11636B14+1
        defadr BookObj_CallPage,0x1160386C+1
        defadr DateInput_GetDateInt,0x116B41DC+1
        defadr TimeInput_GetTimeInt,0x116B5A88+1
        defadr GetFontDesc,0x2A2846AC
        defadr GetFontCount,0x2A284A1C
        defadr GC_GetBrushColor,0x116A4AC0+1
        defadr GC_SetBrushColor,0x116A4A80+1
        defadr GC_DrawRoundRect,0x116A5634+1
        defadr MenuBook_Desktop,0x116C6838+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x116C5E8C+1
        defadr BookObj_SoftKeys_SetAction,0x116BAC20+1
        defadr BookObj_SoftKeys_SetText,0x116BAC58+1
        defadr FindBookByID,0x11601A90+1
        defadr TextFeedbackWindow,0x116B5078+1
        defadr Feedback_SetKeyHook,0x116B5480+1
        defadr Feedback_SetOnClose,0x116B5420+1
        defadr Feedback_SetTimeout,0x116B533C+1
        defadr Feedback_SetTextExtended,0x116B54E4+1
        defadr TabMenuBar_SetOnTabSwitch,0x116B3DCC+1
        defadr KeyCode2Name,0x11253844+1
        defadr ImageID_Get,0x10FC627C+1
        defadr ImageID_Free,0x10FC68AC+1
        defadr DataBrowser_CreateSubExecute,0x1100C4E4+1
        defadr DataBrowser_ExecuteSubroutine,0x1100D064+1
        defadr FILEITEM_SetFname,0x1102BC6C+1
        defadr FILEITEM_SetPath,0x1102BF2C+1
        defadr FILEITEM_GetFname,0x1102BF24+1
        defadr FILEITEM_GetPath,0x1102BFB8+1
        defadr FILEITEM_SetFnameAndContentType,0x1102BCCC+1
        defadr FILEITEM_SetPathAndContentType,0x1102BF90+1
        defadr JavaDialog_Open,0x10FF670C+1
        defadr JavaDialog_Close,0x10FF9DE8+1
        defadr JavaAppDesc_Get,0x10FF9FAC+1
        defadr JavaAppDesc_GetFirstApp,0x10FEC718+1
        defadr JavaAppDesc_GetNextApp,0x10FEC720+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10FEC224+1
        defadr DispObject_SetRefreshTimer,0x1169BDA0+1
        defadr DispObject_KillRefreshTimer,0x1169BE1C+1
        defadr IsDataBrowserBook,0x1101FB94+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x1101B308+1
        defadr Shortcut_Get_MenuItemName,0x116D1CC8+1
        defadr Shortcut_Get_MenuItemIconID,0x116C6A28+1
        defadr FindBookEx,0x11601B24+1
        defadr FILEITEM_CreateCopy,0x1102BAC0+1
        defadr BookObj_GetSessionID,0x11603FB0+1
        defadr UI_Event_toSID,0x11602860+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x1160B5D4+1
        defadr MainInput_Hide,0x116CCDD4+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x116BC7B4+1
        defadr PNUM2Name,0x10F55AC8+1
        defadr SpeedDial_GetPNUM,0x10F76640+1
        defadr DispObject_GetWindowWidth,0x1169D4BC+1
        defadr DispObject_GetWindowHeight,0x1169D4DC+1
        defadr get_system_langID,0x1161B990+1
        defadr lang_get_name,0x116F5400+1
        defadr w_chdir,0x1009EB30
        defadr w_fopen,0x107E9F1C+1
        defadr w_fstat,0x107E9FD4+1
        defadr w_fwrite,0x107E9F64+1
        defadr w_fread,0x107E9F4C+1
        defadr w_lseek,0x11429EC8+1
        defadr w_fclose,0x107E9F7C+1
        defadr w_mkdir,0x1009EAC8
        defadr DirHandle_SetFilterStr,0x10FDA1AC+1
        defadr Disp_GetTextIDWidth,0x116A0710+1
        defadr ImageID_GetIndirect,0x10FC62F4+1
        defadr unixtime2datetime,0x111E0914+1
        defadr List_Insert,0x1142ACEC+1
        defadr FileCopy,0x10FDCB10+1
        defadr FileMove,0x10FDCD4C+1
        defadr DispObject_SetLayerColor,0x1169E1C8+1
        defadr JavaAppDesc_GetJavaAppID,0x10FF9F08+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x110E1C6C+1
        defadr JavaApp_LogoImageID_Get,0x110D66B4+1
        defadr CreateProgressBar,0x116B46A4+1
        defadr ProgressBar_SetText,0x116B49BC+1
        defadr ProgressBar_SetIcon,0x116B4AD8+1
        defadr ProgressBar_SetPercentValue,0x116B4978+1
        defadr ProgressBar_SetBarDisabled,0x116B4AE8+1
        defadr StringInput_DispObject_SetText,0x1162BDF4+1
        defadr GUIObject_SetTitleIcon,0x116A71B0+1
        defadr DispObject_SoftKeys_GetParams,0x116BDA80+1
        defadr DispObject_SoftKeys_GetList,0x116BDAC4+1
        defadr BookObj_GetDisplayOrientation,0x1160414C+1
        defadr BookObj_SetDisplayOrientation,0x116040E4+1
        defadr Display_GetTopBook,0x11603568+1
        defadr Display_GetBrightness,0x116255C4+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x11022FC8+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x11023024+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1102302C+1
        defadr SetTheme,0x116C13D4+1
        defadr SoftKeys_GetLabel,0x116BFDF4+1
        defadr SoftKeys_Update,0x116BFA08+1
        defadr get_CellData,0x11758F84+1
        defadr IncommingCall_Reject,0x10F2C4E4+1
        defadr IncommingCall_Mute,0x10F2D820+1
        defadr Bluetooth_GetState,0x10EF6DA0+1
        defadr Bluetooth_GetPhoneVisibility,0x10EF6D68+1
        defadr Bluetooth_isBusy,0x10EF6E28+1
        defadr USB_isConnected,0x11443CDC+1
        defadr w_diropen,0x1009EAD8
        defadr w_dirread,0x1142A558+1
        defadr w_dirclose,0x1009EB18
        defadr w_rename,0x1142A5F4+1
        defadr w_remove,0x1142A5A8+1
        defadr IsCameraBook,0x114ED09C+1
        defadr IsSoundRecorderBook,0x110B3F1C+1
        defadr StringInput_MenuItem_SetPriority,0x11636C1C+1
        defadr Video_ActionBack,0x115E7338+1
        defadr Video_ExtractFrame,0x115E7AE8+1
        defadr Video_ZoomOn,0x115E7308+1
        defadr RightNow_SetActive,0x116D06B4+1
        defadr Video_Play,0x115E7240+1
        defadr Video_Pause,0x115E7250+1
        defadr Audio_Pause,0x115B9B14+1
        defadr Audio_Play,0x115B9A90+1
        defadr CreatePercentInputVA,0x116B42FC+1
        defadr PercentInput_GetPercent,0x116B4488+1
        defadr GUIonMessage_SetLineSeparator,0x11659134+1
        defadr PHF_GetState,0x116260A0+1
        defadr CHF_GetState,0x116260A8+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x116C0850+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x116C085C+1
        defadr SetTrayIcon,0x11696BF0+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x1179EB9C+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x1179ED78+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x1179ECF4+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x1179F15C+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x1179EC58+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x1179EF84+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10FEB78C+1
        defadr SoundRecorderDesc_Create,0x110B3458+1
        defadr SoundRecorderDesc_Destroy,0x110B34B4+1
        defadr SoundRecorderDesc_SetBookID,0x110B34D0+1
        defadr SoundRecorderDesc_SetType,0x110B34FC+1
        defadr SoundRecorderDesc_SetFolder,0x110B3510+1
        defadr SoundRecorderDesc_SetFname,0x110B352C+1
        defadr SoundRecorderDesc_SetRecordSize,0x110B3548+1
        defadr SoundRecorder_Create,0x110B35C0+1
        defadr SoundRecorder_RecordCall,0x10F20A68+1
        defadr Browser_OpenURI,0x10F975A4+1
        defadr GetURIScheme,0x114ACC78+1
        defadr CreateURI,0x114AD114+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x11023048+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x10EAD91C+1
        defadr Alarm_GetState,0x10EAC2CC+1
        defadr Alarm_GetTIME,0x10EAD124+1
        defadr Alarm_GetWeekSettings,0x10EAE0B4+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x1179EF28+1
        defadr IncommingCall_Accept,0x10F2C3A8+1
        defadr MediaPlayer_SoftKeys_SetText,0x115BE1F4+1
        defadr MediaPlayer_SoftKeys_SetAction,0x115BE1AC+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x115BE254+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x115BE284+1
        defadr DispObject_Show,0x1169C058+1
        defadr Request_EventChannel_Subscribe,0x1003F198+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x116C0818+1
        defadr Request_ICA_ShutdownAllConnections,0x109D81BC+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x1179F5D4+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x11023100+1
        defadr GUIonMessage_GetMsg,0x1165904C+1
        defadr GUIonMessage_GetBook,0x11659054+1
        defadr GUIonMessage_GetGui,0x11659050+1
        defadr GUIonMessage_GetSelectedItem,0x11659058+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11659064+1
        defadr ObexSendFile,0x10F523C0+1
        defadr Feedback_SetManualScrollingText,0x116AF52C+1
        defadr EqualizerGain_Set,0x111B7200+1
        defadr CANVAS_Get_GviGC,0x105EA71C+1
        defadr GVI_BitBlt,0x10696734+1
        defadr GVI_StretchBlt,0x106968A8+1
        defadr GVI_TransformBlt,0x10696964+1
        defadr GVI_CreatePen,0x106959DC+1
        defadr GVI_CreateDashedPen,0x10695A20+1
        defadr GVI_CreateSolidBrush,0x106958EC+1
        defadr GVI_Delete_GVI_Object,0x106952BC+1
        defadr GVI_DrawEllipse,0x1069606C+1
        defadr GVI_DrawLine,0x10696F48+1
        defadr GVI_DrawLines,0x106975D8+1
        defadr GVI_DrawPolyLine,0x1069765C+1
        defadr GVI_DrawRectangle,0x106978D8+1
        defadr GVI_DrawRoundRect,0x10696588+1
        defadr GVI_DrawSolidLines,0x1069719C+1
        defadr GVI_DrawSolidPolyLine,0x106973A4+1
        defadr GVI_DrawSolidRectangle,0x10697448+1
        defadr GVI_FillEllipse,0x10696454+1
        defadr GVI_FillPolygon,0x10696E00+1
        defadr GVI_FillRectangle,0x10697758+1
        defadr GVI_FillRectangles,0x106977E4+1
        defadr GVI_FillSolidEllipse,0x10696500+1
        defadr GVI_FillSolidRectangle,0x10697860+1
        defadr GVI_FillSolidRoundRect,0x106966D8+1
        defadr GVI_FillSolidTriangle,0x10696D8C+1
        defadr GC_CreateMemoryGC,0x116A419C+1
        defadr GC_FreeGC,0x116A4260+1
        defadr Settings_ShowNumber_Get,0x10F4D4E4+1
        defadr GVI_CreateBitmap,0x10695AD8+1
        defadr GVI_CreateMemoryGC,0x10697A3C+1
        defadr GVI_DeleteMemoryGC,0x106C3678+1
        defadr StringInput_DispObject_SetLanguage,0x11630188+1
        defadr List_InsertSorted,0x1142AE34+1
        defadr ListMenu_SetItemIcon,0x1165886C+1
        defadr wstrnupr,0x10FCD35C+1
        defadr wstrnlwr,0x11317738+1
        defadr ListMenu_SetItemTextScroll,0x11658CB4+1
        defadr GUIObject_SetListTextColor,0x11659B94+1
        defadr DispObject_SetTitleTextColor,0x1169B0A0+1
        defadr DispObject_SetListTextColor,0x1164CD20+1
        defadr DispObject_SetCursorImage,0x1164CCDC+1
        defadr DispObject_SetBackgroundImage,0x1164CCF8+1
        defadr DispObject_SetTitleBackgroundImage,0x1169B21C+1
        defadr TabMenuBar_SetTabTitle,0x116B3DB8+1
        defadr GUIObject_GetBook,0x116A6AD4+1
        defadr SoftKeys_GetSelectedAction,0x116BC6EC+1
        defadr MonitorFeedback_SetTimer,0x1160AC8C+1
        defadr ListMenu_DestroyItems,0x11658A38+1
        defadr DispObject_SetScrollBarBackgroundColor,0x1169D7BC+1
        defadr DispObject_SetScrollBarColor,0x1169D794+1
        defadr DispObject_SetSoftkeysColor,0x116BCC84+1
        defadr YesNoQuestion_SetIcon,0x116B5E98+1
        defadr GUIObject_SetBacklightTimeout,0x116A6DB0+1
        defadr ListMenu_SetHotkeyMode,0x116586B0+1
        defadr ListMenu_SetSearchLanguageMode,0x11658B98+1
        defadr ListMenu_EnableSearchHeader,0x11658BC0+1
        defadr GUIonMessage_GetSearchString,0x1165926C+1
        defadr GUIonMessage_GetSearchStringLength,0x1165928C+1
        defadr EqualizerGain_Get,0x111B71D8+1
        defadr Theme_DestroyMenuIcons,0x116C515C+1
        defadr CoCreateInstance,0x117065BC+1
        defadr GUIObject_SetSecondRowTitleText,0x116A7194+1
        defadr ListMenu_GetItemCount,0x11658588+1
        defadr OSE_GetShell,0x111DFEE0+1
        defadr swscanf,0x10554500+1
        defadr sscanf,0x100A7A60+1

        defadr DispObject_WindowSetSize,0x1169D3B0+1
        defadr Feedback_DispObject_GetText,0x116AFC48+1
        defadr DispObject_SoftKeys_ExecuteAction,0x116BC9F4+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x1101F1DC+1
        defadr DispObject_SetAnimation,0x1169E280+1
        
        defadr MainDisplay_GetTopBook,0x11603564+1
        defadr GC_DrawIcon,0x1169F3E4+1
        defadr DisplayGC_AddRef,0x116A45C8+1
        defadr DynamicMenu_SetElement_SecondLineText,0x116C4F90+1
        defadr DynamicMenu_GetElementMsg,0x116C4FCC+1

        defadr FSX_IsFileExists,0x110272DC+1

	defadr VolumeControl_OnCreate,0x116DF218+1
        defadr VolumeControl_OnClose,0x116DF2FC+1
        defadr VolumeControl_OnRedraw,0x116DF370+1
	defadr pg_VolumeControl_Active_EnterEvent,0x116DFB24+1
	defadr pg_VolumeControl_Active_ExitEvent,0x116DFB68+1

//-----------

        EXTERN New_VolumeControl_OnCreate
        EXTERN New_VolumeControl_OnClose
        EXTERN New_VolumeControl_OnRedraw
        
        EXTERN New_pg_VolumeControl_Active_EnterEvent
        
        RSEG PATCH_VOLUMEONPAGENTER
        DATA
        DCD New_pg_VolumeControl_Active_EnterEvent
        
        RSEG PATCH_VOLUMEONCREATE
        DATA
        DCD New_VolumeControl_OnCreate
        
        RSEG PATCH_VOLUMEONCLOSE
        DATA
        DCD New_VolumeControl_OnClose
        
        RSEG PATCH_VOLUMEONREDRAW
        DATA
        DCD New_VolumeControl_OnRedraw
	
        END
