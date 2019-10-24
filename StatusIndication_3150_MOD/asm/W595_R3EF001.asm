#ifdef W595_R3EF001

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010AC
        defadr memcpy,0x10147898
        defadr sprintf,0x106F81E0+1
        defadr snwprintf,0x106F8694+1
        defadr _fopen,0x10957B7C+1
        defadr fclose,0x11700750+1
        defadr fread,0x10959510+1
        defadr fwrite,0x109596DC+1
        defadr _wstat,0x11293A1C+1
        defadr fputs,0x11A50590+1
        defadr fstat,0x109584E0+1
        defadr AllocDirHandle,0x109559CC+1
        defadr GetFname,0x10955B9C+1
        defadr DataBrowserDesc_Create,0x117F2CF4+1
        defadr DataBrowserDesc_SetStyle,0x117F2F74+1
        defadr DataBrowserDesc_SetHeaderText,0x117F2FA4+1
        defadr DataBrowserDesc_SetFolders,0x117F2F8C+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x117F2FAC+1
        defadr DataBrowser_Create,0x117EEF60+1
        defadr DataBrowserDesc_Destroy,0x117F2DA4+1
        defadr getFileExtention,0x1095B1EC+1
        defadr DataBrowser_isFileInListExt,0x10955E00+1
        defadr Timer_ReSet,0x10DECD40+1
        defadr Timer_Set,0x10DECD0C+1
        defadr Timer_Kill,0x10DECD98+1
        defadr CreateBook,0x10DF072C+1
        defadr BookObj_KillBook,0x10DF0840+1
        defadr BookObj_GotoPage,0x10DF043C+1
        defadr BookObj_ReturnPage,0x10DF05F4+1
        defadr FreeBook,0x10DF0DAC+1
        defadr FindBook,0x10DF01F4+1
        defadr Find_StandbyBook,0x10D8D768+1
        defadr BookObj_SetFocus,0x10DF09DC+1
        defadr GUIObject_SetTitleText,0x109D2398+1
        defadr GUIObject_Show,0x109D2184+1
        defadr ListMenu_SetCursorToItem,0x11A7DE30+1
        defadr GUIObject_SetStyle,0x109D21DC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A7EA1C+1
        defadr GUIonMessage_SetMenuItemText,0x11A7EA28+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A7EA58+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11A7EA38+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A7EA48+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A7EA68+1
        defadr DispObject_SetTitleText,0x109C74D8+1
        defadr ListMenu_GetSelectedItem,0x11A7DE44+1
        defadr ListMenu_SetItemStyle,0x11A7DE94+1
        defadr isScreenSaverBook,0x108E8135
        defadr StatusIndication_SetItemText,0x10D8CD0C+1
        defadr StatusIndication_ShowNotes,0x10D8E914+1
        defadr CreateStringInputVA,0x10892FBC+1
        defadr CreateOneOfMany,0x11A80220+1
        defadr OneOfMany_SetItemCount,0x11A803AC+1
        defadr OneOfMany_SetChecked,0x11A803C8+1
        defadr OneOfMany_SetTexts,0x11A803FC+1
        defadr OneOfMany_GetSelected,0x11A803D8+1
        defadr StatusIndication_Item8_SetText,0x10D8E820+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D3A4+1
        defadr GUIObject_SoftKeys_SetText,0x1080D41C+1
        defadr GUIObject_SoftKeys_SetEnable,0x1080D50C+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x1080D4C4+1
        defadr GUIObject_SoftKeys_RemoveItem,0x1080D358+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D4A0+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x1080D710+1
        defadr wstrcpy,0x10D661EC+1
        defadr wstrncpy,0x10D66204+1
        defadr wstrcat,0x106F8D54+1
        defadr wstrncat,0x10D6624C+1
        defadr wstrcmp,0x10D661BC+1
        defadr wstrlen,0x10D661A8+1
        defadr str2wstr,0x10D67470+1
        defadr strcmp,0x106F8468+1
        defadr strlen,0x106F84C4+1
        defadr wstr2strn,0x10D662C8+1
        defadr int2strID,0x10F61C68+1
        defadr Str2ID,0x10F61E3C+1
        defadr StrID2Str,0x10F62548+1
        defadr TextID2wstr,0x10F623D0+1
        defadr TextGetLength,0x10F62280+1
        defadr TextFree,0x10F62178+1
        defadr AB_DEFAULTNBR_GET,0x10B64920+1
        defadr AB_READSTRING,0x10B7B64C+1
        defadr AB_READPHONENBR,0x10B6ACF8+1
        defadr AB_GETNBROFITEMS,0x10B6ADB0+1
        defadr PNUM_len,0x10F6143C+1
        defadr PNUM2str,0x10938B64+1
        defadr GUIObject_GetDispObject,0x109D201C+1
        defadr List_Create,0x11AC443C+1
        defadr List_Destroy,0x11AC4464+1
        defadr List_InsertFirst,0x11AC45B0+1
        defadr Gif2ID,0x107A2344+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107A2574+1
        defadr REQUEST_DATEANDTIME_GET,0x107AC558+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x10E6524C+1
        defadr GetFreeBytesOnHeap,0x4BB006F0
        defadr BookObj_Hide,0x10DF0A04+1
        defadr BookObj_Show,0x10DF0A14+1
        defadr StartAPP,0x10D8D954+1
        defadr ListMenu_SetOnMessage,0x11A7DF68+1
        defadr manifest_GetParam,0x10B058BC+1
        defadr lseek,0x10959884+1
        defadr get_VBUFFER,0x10007F15
        defadr SetLampLevel,0x1000592A+1
        defadr List_RemoveAt,0x11AC462C+1
        defadr GetCurrentPID,0x10005E58+1
        defadr List_IndexOf,0x11AC4570+1
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
        defadr strcpy,0x106F8490+1
        defadr CreateMessage,0x10E0F694+1
        defadr SendMessage,0x10E0F6E8+1
        defadr WaitMessage,0x10E0F770+1
        defadr FreeMessage,0x10E0F784+1
        defadr SendDispatchMessage,0x10BD8C88+1
        defadr UIEventName,0x10DED128+1
        defadr MissedEvents,0x4BB9DBD4
        defadr UI_Event,0x10DEF4CC+1
        defadr UI_Event_wData,0x10DEF4DC+1
        defadr UI_Event_toBookID,0x10DEF524+1
        defadr UI_Event_toBookIDwData,0x10DEF538+1
        defadr List_Find,0x11AC470C+1
        defadr List_Get,0x11AC465C+1
        defadr wstrrchr,0x10D6752C+1
        defadr BookObj_CallSubroutine,0x10DF04CC+1
        defadr List_InsertLast,0x11AC45B8+1
        defadr debug_printf,0x4BB39F20+1
        defadr PlayFile,0x119E01B4+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11A9B210+1
        defadr Profile_SetActive,0x11ACB580+1
        defadr SetBrightnessOfScreen,0x10DC171C
        defadr isKeylocked,0x108E7F20+1
        defadr isMediaPlayerVideoBook,0x10E139A5
        defadr ShuttingDown,0x11A58134+1
        defadr Vibra,0x119DF51C+1
        defadr REQUEST_DATEFORMAT_GET,0x107AC738+1
        defadr REQUEST_TIMEFORMAT_GET,0x107AC81C+1
        defadr Date2ID,0x11A587A4+1
        defadr Time2ID,0x11A586C0+1
        defadr CreateListMenu,0x11A7DC44+1
        defadr ListMenu_SetItemCount,0x11A7DE58+1
        defadr ROOT_APP,0x4BBA9FE8
        defadr GUIObject_SoftKeys_SetInfoText,0x1080D408+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1080D540+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11A5BD68+1
        defadr REQUEST_SYSTEM_RESTART,0x11A5BD78+1
        defadr GUIObject_SoftKeys_SetTexts,0x1080D474+1
        defadr isRightNowBook,0x10B326E0+1
        defadr isVolumeControllerBook,0x11AB7978+1
        defadr CreateTabMenuBar,0x1177B598+1
        defadr TabMenuBar_SetTabCount,0x1177B7F0+1
        defadr TabMenuBar_SetTabGui,0x1177B668+1
        defadr TabMenuBar_SetTabIcon,0x1177B6E8+1
        defadr GUIObject_Destroy,0x109D1F90+1
        defadr GUIInput_SetIcon,0x109D2258+1
        defadr StringInput_GetStringAndLen,0x1089386C+1
        defadr GetAudioControlPtr,0x4BBC7048
        defadr AudioControl_Vibrate,0x1154B8D4+1
        defadr GetVolumeSize,0x1095AF04+1
        defadr CreateNOfMany,0x11A7FC2C+1
        defadr NOfMany_SetTexts,0x11A7FE30+1
        defadr NOfMany_SetChecked,0x11A7FDB4+1
        defadr NOfMany_SetCursor,0x11A7FD7C+1
        defadr NOfMany_GetCheckedCount,0x11A7FDD8+1
        defadr NOfMany_GetChecked,0x11A7FDC8+1
        defadr NOfMany_SetonMessage,0x11A7FE28+1
        defadr AudioControl_Init,0x119E0300+1
        defadr OneOfMany_SetFocused,0x11A80390+1
        defadr OneOfMany_SetonMessage,0x11A803F4+1
        defadr CreateMonitorFeedback,0x11A57388+1
        defadr FeedBack_SetText,0x11A57440+1
        defadr GetBatteryState,0x11081F58+1
        defadr get_DisplayGC,0x109CFFE0+1
        defadr DispObject_GetRect,0x109C8BD8+1
        defadr GC_GetRect,0x109D0624+1
        defadr GC_GetXX,0x109D0920+1
        defadr GC_SetXX,0x109D0914+1
        defadr GC_ValidateRect,0x109D05D4+1
        defadr BookObj_AddGUIObject,0x10DF0ABC+1
        defadr DrawRect,0x109CBD2C+1
        defadr DrawString,0x109CC078+1
        defadr XGUIList_AddGUIObject,0x10DF0FBC+1
        defadr DispObject_InvalidateRect,0x109C8968+1
        defadr GUIObject_Create,0x109D1DCC+1
        defadr SetFont,0x109CCC38+1
        defadr StatusRow_p,0x4BBC51A8
        defadr root_list_get_session_count,0x10DEEA64+1
        defadr root_list_get_session,0x10DEEA74+1
        defadr SESSION_GetTopBook,0x10DEE244+1
        defadr MainInput_strlen,0x10D8D268+1
        defadr MainInput_getPNUM,0x10D8D298+1
        defadr BookObj_GetBookID,0x10DF0E98+1
        defadr wstrncmp,0x106F8E28+1
        defadr DispObject_GetAbsoluteXPos,0x109C9DDC+1
        defadr DispObject_GetAbsoluteYPos,0x109C9E10+1
        defadr DispObject_GetWindow,0x109C8EEC+1
        defadr GetThemeColor,0x10E5F898+1
        defadr REQUEST_SETTING_SILENCE_SET,0x11A9AC44+1
        defadr REQUEST_SETTING_SILENCE_GET,0x11A9ABEC+1
        defadr VCALL_Init,0x10B58B68+1
        defadr VCALL_SetName,0x10B58C60+1
        defadr VCALL_SetNameIcon,0x10B58CC0+1
        defadr VCALL_SetNumber,0x10B58C80+1
        defadr VCALL_SetHZ1,0x10B58CA4+1
        defadr VCALL_SetHZ2,0x10B58CB0+1
        defadr MakeVoiceCall,0x10B58700+1
        defadr FileDelete,0x10958770+1
        defadr GUIObject_SetFocus,0x109D2148+1
        defadr CreateSMSCont,0x11A0E474+1
        defadr FreeSMSCont,0x11A0EBB8+1
        defadr PrepareSMSCont,0x11A0E654+1
        defadr CteateNewMessage,0x11A0EAE0+1
        defadr get_APP_DESC_TABLE,0x11B7F7E0
        defadr Window_GetComponentInterface,0x109CF98C+1
        defadr AB_POSITIONNBR_GET,0x10B6AF9C+1
        defadr AB_NAME_ITEM2StrID,0x10B6AEB0+1
        defadr AB_NUM_ITEM2StrID,0x10B6AF14+1
        defadr GetABRecNum,0x10B7BD68+1
        defadr get_AB_ITEMS_DESC,0x11B67CDC
        defadr SBY_GetMainInput,0x108A443C+1
        defadr SBY_GetStatusIndication,0x10769728+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10A5053C+1
        defadr PID_MMI,0x4BBA8630
        defadr DispObject_GetGUI,0x109C824C+1
        defadr Display_GetFocusedDispObject,0x109C8198+1
        defadr DispObject_GetVisible,0x109C880C+1
        defadr DispObject_GetDESC,0x10014E98+1
        defadr DISP_DESC_SetName,0x109C5418+1
        defadr DispObject_GetName,0x109C9B34+1
        defadr DISP_DESC_SetSize,0x109C541C+1
        defadr DISP_DESC_SetOnCreate,0x109C5420+1
        defadr DispObject_GetOnCreate,0x109C549C+1
        defadr DISP_DESC_SetOnClose,0x109C5424+1
        defadr DispObject_GetOnClose,0x109C54B8+1
        defadr DISP_DESC_SetOnRedraw,0x109C5428+1
        defadr DispObject_GetOnRedraw,0x109C54D4+1
        defadr DISP_DESC_SetOnKey,0x109C5430+1
        defadr DispObject_GetOnKey,0x109C550C+1
        defadr DISP_DESC_SetonRefresh,0x109C542C+1
        defadr DispObject_GetonRefresh,0x109C54F0+1
        defadr DISP_DESC_SetMethod06,0x109C5434+1
        defadr DispObject_GetMethod06,0x109C5528+1
        defadr DISP_DESC_SetOnLayout,0x109C543C+1
        defadr DispObject_GetOnLayout,0x109C5560+1
        defadr DISP_DESC_SetOnConfig,0x109C5440+1
        defadr DispObject_GetOnConfig,0x109C557C+1
        defadr DISP_DESC_SetMethod0A,0x109C5444+1
        defadr DispObject_GetMethod0A,0x109C5598+1
        defadr DISP_DESC_SetMethod0B,0x109C5448+1
        defadr DispObject_GetMethod0B,0x109C55B4+1
        defadr DISP_DESC_SetMethod0C,0x109C544C+1
        defadr JavaSession_Manager,0x1000592A+1
        defadr JavaSession_GetName,0x1000592A+1
        defadr TextCopyId,0x10F6201C+1
        defadr BookObj_GetSession,0x10DF0DF8+1
        defadr GUIonMessage_SetItemAsSubitem,0x11A7EAC4+1
        defadr GUIonMessage_SetSubitemText,0x11A7EB30+1
        defadr GUIonMessage_GetCreatedSubItemParentIndex,0x11A7EB24+1
        defadr GoMusic,0x10E26EF0+1
        defadr Vibra_Off,0x119DF5F0+1
        defadr PlayFileV,0x119E01B8+1
        defadr GetSilent,0x119DE688+1
        defadr GetVibrator,0x119DA278+1
        defadr GetAudioSettings,0x119DF98C+1
        defadr GetChipID,0x12632EB4+1
        defadr GUIonMessage_GetCurrentSubItem,0x11A7EB18+1
        defadr GUIonMessage_GetCurrentItemIndex,0x11A7EB0C+1
        defadr DestroyDirHandle,0x10955D18+1
        defadr LastExtDB,0x11E532DC
        defadr GetOtherExtMethods,0x117E8F60+1
        defadr MessageBox,0x11A55944+1
        defadr Display_GetHeight,0x1177DBF4+1
        defadr Display_GetWidth,0x1177DC00+1
        defadr PlaySystemSound,0x119E015C+1
        defadr TabMenuBar_GetFocusedTab,0x1177B65C+1
        defadr TabMenuBar_SetFocusedTab,0x1177B64C+1
        defadr GC_GetPenColor,0x109D082C+1
        defadr GC_SetPenColor,0x109D07F0+1
        defadr GC_SetPixel,0x109D0474+1
        defadr GC_DrawLine,0x109D0F70+1
        defadr GC_DrawFRect,0x109D10FC+1
        defadr GC_WritePixels,0x109D04FC+1
        defadr png_create_read_struct_2,0x1182771C+1
        defadr png_destroy_read_struct,0x11827868+1
        defadr png_create_info_struct,0x11825EC4+1
        defadr png_destroy_info_struct,0x11825EF8+1
        defadr png_set_progressive_read_fn,0x118276F4+1
        defadr png_process_data,0x118266B4+1
        defadr png_read_update_info,0x1182783C+1
        defadr png_get_progressive_ptr,0x11827718+1
        defadr png_get_IHDR,0x11826380+1
        defadr png_set_strip_16,0x11827A08+1
        defadr png_set_gray_1_2_4_to_8,0x11827A14+1
        defadr png_set_gray_to_rgb,0x11827A38+1
        defadr png_get_valid,0x11826354+1
        defadr png_set_tRNS_to_alpha,0x11827A2C+1
        defadr png_set_filler,0x1182A79C+1
        defadr png_set_palette_to_rgb,0x11827A20+1
        defadr png_get_rowbytes,0x1182636C+1
        defadr png_progressive_combine_row,0x118276D4+1
        defadr png_sig_cmp,0x11825DBC+1
        defadr setjmp,0x1014BB34
        defadr longjmp,0x1014BB34
        defadr inflateInit2_,0x1182B470+1
        defadr inflate,0x1182B618+1
        defadr inflateEnd,0x1182C910+1
        defadr memcmp,0x12631C38
        defadr strncmp,0x106F8500+1
        defadr strncpy,0x106F8534+1
        defadr strcat,0x106F8430+1
        defadr GUIObject_SetTitleType,0x109D237C+1
        defadr GUIonMessage_SetItemDisabled,0x11A7EAD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107A25EC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107A2674+1
        defadr get_Surfaces,0x4BD83940
        defadr iconidname2id,0x11517048+1
        defadr textidname2id,0x117005B8+1
        defadr ListMenu_SetNoItemText,0x11A7DFE8+1
        defadr IsFmRadioBook,0x10FA7998+1
        defadr IsAudioPlayerBook,0x10C86AE8+1
        defadr PlayerControl,0x10C86504+1
        defadr SwitchRadioStationFromList,0x10FA586C+1
        defadr Shortcut_Run,0x10DDCC9C+1
        defadr mkdir,0x109550F8+1
        defadr rmdir,0x109554EC+1
        defadr chmod,0x1095869C+1
        defadr rename,0x10958CC4+1
        defadr Disp_GetStrIdHeight,0x109CD324+1
        defadr GetImageHeight,0x109CD324+1
        defadr CallID_GetCallStatusDesc,0x10E014A8+1
        defadr CallStatusDesc_GetName,0x10E00AE0+1
        defadr List_DestroyElements,0x11AC4750+1
        defadr strstr,0x106F85D0+1
        defadr GPRS_GetLastSessionInfo,0x107FFA5C+1
        defadr wstrcmpni,0x10D675C8+1
        defadr wtoi,0x10DEC76C+1
        defadr DATE_GetWeekDay,0x10BCD4BC+1
        defadr Cale_GetSettings,0x10924F68+1
        defadr wstrwstr,0x106F8F88+1
        defadr wstrcmpi,0x10D6760C+1
        defadr wstrchr,0x106F8D70+1
        defadr GUIObject_SoftKeys_Hide,0x1080D75C+1
        defadr GUIObject_SoftKeys_Show,0x1080D768+1
        defadr DispObject_SoftKeys_Get,0x10809B34+1
        defadr StandbyBackground_SetImage,0x10E5E10C+1
        defadr CreateYesNoQuestionVA,0x1177D4A8+1
        defadr ListMenu_SetSecondLineText,0x11A7E20C+1
        defadr _REQUEST_OAF_START_APPLICATION,0x10B2B35C+1
        defadr FSX_isNameInvalid,0x1095ACF4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x117F2F94+1
        defadr DataBrowserDesc_SetActions,0x117F2F48+1
        defadr DataBrowserDesc_SetSelectAction,0x117F2F10+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x117F2F18+1
        defadr DataBrowserDesc_SetBookID,0x117F2EF4+1
        defadr DataBrowserDesc_SetItemFilter,0x117F2E98+1
        defadr DataBrowserDesc_SetOption,0x117F2FC4+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x117F302C+1
        defadr DataBrowserDesc_SetFileExtList,0x117F2EA0+1
        defadr FSX_RemoveIllegalSymbolsName,0x117FC708+1
        defadr FILEITEM_Create,0x117FC120+1
        defadr FILEITEM_Destroy,0x117FC250+1
        defadr CreateDateInputVA,0x1177B924+1
        defadr CreateTimeInputVA,0x1177D080+1
        defadr StringInput_SetCursorPosition,0x108938B8+1
        defadr BookObj_CallPage,0x10DF0570+1
        defadr DateInput_GetDateInt,0x1177BB94+1
        defadr TimeInput_GetTimeInt,0x1177D348+1
        defadr GC_GetBrushColor,0x109D0908+1
        defadr GC_SetBrushColor,0x109D08C8+1
        defadr GC_DrawRoundRect,0x109D1144+1
        defadr MenuBook_Desktop,0x10DDC450+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10DDB784+1
        defadr BookObj_Softkey_SetAction,0x108079F4+1
        defadr BookObj_Softkey_SetText,0x10807A2C+1
        defadr FindBookByID,0x10DF0204+1
        defadr TextFeedbackWindow,0x1177C8E4+1
        defadr Feedback_SetKeyHook,0x1177CCF0+1
        defadr Feedback_SetOnClose,0x1177CC8C+1
        defadr Feedback_SetTimeout,0x1177CCBC+1
        defadr Feedback_SetTextExtended,0x1177CD54+1
        defadr TabMenuBar_SetOnTabSwitch,0x1177B744+1
        defadr KeyCode2Name,0x10FAC7A8+1
        defadr ImageID_Get,0x107A04F4+1
        defadr ImageID_Free,0x107A670C+1
        defadr DataBrowser_CreateSubExecute,0x117DBD68+1
        defadr DataBrowser_ExecuteSubroutine,0x117DC788+1
        defadr FILEITEM_SetFname,0x117FC2FC+1
        defadr FILEITEM_SetPath,0x117FC5BC+1
        defadr FILEITEM_GetFname,0x117FC5B4+1
        defadr FILEITEM_GetPath,0x117FC648+1
        defadr FILEITEM_SetFnameAndContentType,0x117FC35C+1
        defadr FILEITEM_SetPathAndContentType,0x117FC620+1
        defadr JavaDialog_Open,0x10B1384C+1
        defadr JavaDialog_Close,0x10B16FA0+1
        defadr JavaAppDesc_Get,0x10B1716C+1
        defadr JavaAppDesc_GetFirstApp,0x10B091E0+1
        defadr JavaAppDesc_GetNextApp,0x10B091E8+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B08CAC+1
        defadr DispObject_SetRefreshTimer,0x109C83D0+1
        defadr DispObject_KillRefreshTimer,0x109C844C+1
        defadr isDataBrowserBook,0x117EF860+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x117EAFF0+1
        defadr Shortcut_Get_MenuItemName,0x10B34240+1
        defadr Shortcut_Get_MenuItemIconID,0x10DDC674+1
        defadr FindBookEx,0x10DEE9C4+1
        defadr FILEITEM_CreateCopy,0x117FC150+1
        defadr ActionCreate,0x10DF0154+1
        defadr BookObj_GetSessionID,0x10DF0D20+1
        defadr UI_Event_toSID,0x10DEF4F0+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x11A57E18+1
        defadr DispObject_SoftKey_RestoreDefaultAction,0x10809514+1
        defadr PNUM2Name,0x10B53D98+1
        defadr SpeedDial_GetPNUM,0x10B7B2C0+1
        defadr DispObject_GetWindowWidth,0x109C9D5C+1
        defadr DispObject_GetWindowHeight,0x109C9D7C+1
        defadr get_system_langID,0x10DB8730+1
        defadr lang_get_name,0x11A86F90+1
        defadr w_chdir,0x4BB003AC
        defadr w_fopen,0x11293964+1
        defadr w_fstat,0x11293A1C+1
        defadr w_fwrite,0x112939AC+1
        defadr w_fread,0x11293994+1
        defadr w_lseek,0x11A5073C+1
        defadr w_fclose,0x112939C4+1
        defadr w_mkdir,0x4BB00344
        defadr DirHandle_SetFilterStr,0x10955D70+1
        defadr Disp_GetStrIdWidth,0x109CD3C4+1
        defadr ImageID_GetIndirect,0x107A058C+1
        defadr unixtime2datetime,0x10BCD2D4+1
        defadr List_Insert,0x11AC448C+1
        defadr FileCopy,0x10958A78+1
        defadr FileMove,0x10958CC4+1
        defadr DispObject_SetLayerColor,0x109CAB60+1
        defadr JavaAppDesc_GetJavaAppID,0x10B170C8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10C3B420+1
        defadr JavaApp_LogoImageID_Get,0x10C2FC50+1
        defadr CreateProgressBar,0x1177C058+1
        defadr ProgressBar_SetText,0x1177C350+1
        defadr ProgressBar_SetIcon,0x1177C4C4+1
        defadr ProgressBar_SetPercentValue,0x1177C30C+1
        defadr ProgressBar_SetBarDisabled,0x1177C4E4+1
        defadr StringInput_DispObject_SetText,0x1088814C+1
        defadr GUIObject_SetTitleIcon,0x109D23D0+1
        defadr GuiObject_SetBackgroundImage,0x127D7000+1
        defadr DispObject_Softkeys_GetParams,0x1080A7E4+1
        defadr DispObject_Softkeys_GetList,0x1080A828+1
        defadr BookObj_GetDisplayOrientation,0x10DF0F34+1
        defadr BookObj_SetDisplayOrientation,0x10DF0ED0+1
        defadr Display_GetTopBook,0x10DF0210+1
        defadr Display_SetBrightness,0x10DC1608+1
        defadr Display_GetBrightness,0x10DC1640+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x117F2EFC+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x117F2F58+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x117F2F60+1
        defadr SetTheme,0x10E0D254+1
        defadr Softkeys_GetLabel,0x1080CD10+1
        defadr Softkeys_Update,0x1080C8C8+1
        defadr IncommingCall_Reject,0x10E0A700+1
        defadr IncommingCall_Mute,0x10E0BA40+1
        defadr Bluetooth_GetState,0x10A6441C+1
        defadr Bluetooth_GetPhoneVisibility,0x10A643E0+1
        defadr Bluetooth_isBusy,0x10A644AC+1
        defadr USB_isConnected,0x109BC038+1
        defadr w_diropen,0x4BB00354
        defadr w_dirread,0x11A50DCC+1
        defadr w_dirclose,0x4BB0038C
        defadr w_rename,0x11A50E68+1
        defadr w_remove,0x11A50E1C+1
        defadr ConnectionManager_Connection_GetState,0x10C247E8+1
        defadr isCameraBook,0x108C6591
        defadr isSoundRecorderBook,0x10E4BA8D
        defadr StringInput_MenuItem_SetPriority,0x108939C0+1
        defadr Video_ActionBack,0x10E13340+1
        defadr Video_ExtractFrame,0x10E13C48+1
        defadr Video_ZoomOn,0x10E13310+1
        defadr RightNow_SetActive,0x10B32D14+1
        defadr Video_Play,0x10E13248+1
        defadr Video_Pause,0x10E13258+1
        defadr Audio_Pause,0x10C88758+1
        defadr Audio_Play,0x10C886FC+1
        defadr CreatePercentInputVA,0x1177BCC4+1
        defadr PercentInput_GetPercent,0x1177BE50+1
        defadr GUIonMessage_SetLineSeparator,0x11A7EAE8+1
        defadr PHF_GetState,0x10A18CA4+1
        defadr CHF_GetState,0x10A18CAC+1
        defadr GUIObject_Softkeys_RemoveBackground,0x1080D774+1
        defadr GUIObject_Softkeys_RestoreBackground,0x1080D780+1
        defadr SetTrayIcon,0x10D8EAF0+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x11A9A8EC+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x11A9AAE0+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x11A9AA5C+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x11A9AEC4+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x11A9A9F4+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x11A9ACEC+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x10B0828C+1
        defadr SoundRecorderDesc_Create,0x10E4AF38+1
        defadr SoundRecorderDesc_Destroy,0x10E4AF94+1
        defadr SoundRecorderDesc_SetBookID,0x10E4AFB0+1
        defadr SoundRecorderDesc_SetType,0x10E4AFDC+1
        defadr SoundRecorderDesc_SetFolder,0x10E4AFF0+1
        defadr SoundRecorderDesc_SetFname,0x10E4B00C+1
        defadr SoundRecorderDesc_SetRecordSize,0x10E4B028+1
        defadr SoundRecorder_Create,0x10E4B0A0+1
        defadr SoundRecorder_RecordCall,0x10DFDA04+1
        defadr Browser_OpenURI,0x1077CACC+1
        defadr GetURIScheme,0x10E10E14+1
        defadr CreateURI,0x10E112B0+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x117F2F7C+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x107A8FBC+1
        defadr Alarm_GetState,0x107A77EC+1
        defadr Alarm_GetTIME,0x107A87C8+1
        defadr Alarm_GetWeekSettings,0x107A9700+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x11A9AC90+1
        defadr IncommingCall_Accept,0x10E0A5C4+1
        defadr MediaPlayer_SoftKey_SetText,0x10AF30F8+1
        defadr MediaPlayer_SoftKey_SetAction,0x10AF30B0+1
        defadr MediaPlayer_SoftKey_SetItemAsSubItem,0x10AF3158+1
        defadr MediaPlayer_SoftKey_AddHelpStr,0x10AF3188+1
        defadr DispObject_Show,0x109C8688+1
        defadr Request_EventChannel_Subscribe,0x126707B8+1
        defadr GUIObject_Softkey_ExecuteAction,0x1080D73C+1
        defadr Request_ICA_ShutdownAllConnections,0x11494D18+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11A9B358+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x117F3034+1
        defadr GUIonMessage_GetMsg,0x11A7E9F8+1
        defadr GUIonMessage_GetBook,0x11A7EA00+1
        defadr GUIonMessage_GetGui,0x11A7E9FC+1
        defadr GUIonMessage_GetSelectedItem,0x11A7EA04+1
        defadr GUIonMessage_GetPrevSelectedItem,0x11A7EA10+1
        defadr ObexSendFile,0x1089F5D8+1
        defadr Feedback_SetManualScrollingText,0x11777690+1
        defadr EqualizerGain_Set,0x119DD1DC+1
        defadr CANVAS_Get_GviGC,0x113D1B6C+1
        defadr GVI_BitBlt,0x1113CEA0+1
        defadr GVI_StretchBlt,0x1113D014+1
        defadr GVI_TransformBlt,0x1113D0D0+1
        defadr GVI_CreatePen,0x1113C148+1
        defadr GVI_CreateDashedPen,0x1113C18C+1
        defadr GVI_CreateSolidBrush,0x1113C058+1
        defadr GVI_Delete_GVI_Object,0x1113BA28+1
        defadr GVI_DrawEllipse,0x1113C7D8+1
        defadr GVI_DrawLine,0x1113D6C4+1
        defadr GVI_DrawLines,0x1113DD54+1
        defadr GVI_DrawPolyLine,0x1113DDD8+1
        defadr GVI_DrawRectangle,0x1113E054+1
        defadr GVI_DrawRoundRect,0x1113CCF4+1
        defadr GVI_DrawSolidLines,0x1113D918+1
        defadr GVI_DrawSolidPolyLine,0x1113DB20+1
        defadr GVI_DrawSolidRectangle,0x1113DBC4+1
        defadr GVI_FillEllipse,0x1113CBC0+1
        defadr GVI_FillPolygon,0x1113D57C+1
        defadr GVI_FillRectangle,0x1113DED4+1
        defadr GVI_FillRectangles,0x1113DF60+1
        defadr GVI_FillSolidEllipse,0x1113CC6C+1
        defadr GVI_FillSolidRectangle,0x1113D754+1
        defadr GVI_FillSolidRoundRect,0x1113CE44+1
        defadr GVI_FillSolidTriangle,0x1113D508+1
        defadr GC_CreateMemoryGC,0x109CFFF0+1
        defadr GC_FreeGC,0x109D00B8+1
        defadr Settings_ShowNumber_Get,0x10FC316C+1
        defadr GVI_CreateBitmap,0x1113C244+1
        defadr GVI_CreateMemoryGC,0x1113E1B8+1
        defadr GVI_DeleteMemoryGC,0x1116BE50+1
        defadr StringInput_DispObject_SetLanguage,0x1088C880+1
        defadr List_InsertSorted,0x11AC45D4+1
        defadr ListMenu_SetItemIcon,0x11A7E140+1
        defadr wstrnupr,0x10D66278+1
        defadr wstrnlwr,0x10AD1804+1
        defadr ListMenu_SetItemTextScroll,0x11A7E538+1
        defadr GuiObject_SetListTextColor,0x11A7F618+1
        defadr DispObject_SetListTextColor,0x11A710A0+1
        defadr DispObject_SetCursorImage,0x11A7105C+1
        defadr DispObject_SetBackgroundImage,0x11A71078+1
        defadr TabMenuBar_SetTabTitle,0x1177B730+1
        defadr GUIObject_GetBook,0x109D2030+1
        defadr Softkeys_GetSelectedAction,0x10809444+1
        defadr MonitorFeedback_SetTimer,0x11A57434+1
        defadr void,0x11A7FCA5
        defadr ListMenu_DestroyItems,0x11A7E2B0+1
        defadr DispObject_SetScrollBarBackgroundColor,0x109CA05C+1
        defadr DispObject_SetScrollBarColor,0x109CA034+1
        defadr DispObject_SetSoftkeysColor,0x108099B0+1
        defadr YesNoQuestion_SetIcon,0x1177D72C+1
        defadr GUIObject_SetBacklightTimeout,0x109D22D8+1
        defadr ListMenu_SetHotkeyMode,0x11A7DF94+1
        defadr ListMenu_SetSearchLanguageMode,0x11A7E410+1
        defadr ListMenu_EnableSearchHeader,0x11A7E438+1
        defadr GUIonMessage_GetSearchString,0x11A7EC00+1
        defadr GUIonMessage_GetSearchStringLength,0x11A7EC20+1
        defadr EqualizerGain_Get,0x119DD1B4+1
        defadr Theme_DestroyMenuIcons,0x10DDA83C+1
        
        defadr MainInput_Hide,0x10D8D1B4+1
        
        defadr CoCreateInstance,0x1071BBB0+1
        defadr DisplayGC_AddRef,0x109D0418+1
        defadr GC_PutChar,0x109D0A1C+1

//------

        defadr GetTimerTime,      _GetTimerTime
        defadr GetCurName,        _GetCurName
        defadr GetOperatorName,   0x10FC0390+1
        defadr FlightGetState,    0x11A59A94+1
        
        defadr CallInfo_Get,      0x11273AF8+1
        defadr isTimerBook,       0x10FA2F88+1

        defadr some,              0x10E0F7E4+1
        defadr armfunc,           0x106F4D34

        defadr Show,              0x10D8E964+1
        defadr Return_Clear,      0x10D8E95E+1
        defadr Show_Clear,        0x10D8E98C+1

        defadr oldRedrawStatus,   0x1177098C+1
        defadr oldRedrawDisplay,  0x10D8BF28+1
        defadr oldRedrawSoft,     0x1080C2E0+1
        defadr oldCreateDisplay,  0x10D8BEBC+1
        defadr oldCloseDisplay,   0x10D8BF14+1
        defadr oldOnKeyMainInput, 0x10D89C0C+1

        defadr retSetIcon,        0x117801DC+1

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
          