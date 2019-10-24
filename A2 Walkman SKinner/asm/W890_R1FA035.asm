#ifdef W890_R1FA035

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

	defadr memalloc,0x1009F36C
	defadr memfree,0x1009F394
        defadr memset,0x1000162C
        defadr memcpy,0x100BF408
        defadr sprintf,0x10567DF4+1
        defadr snwprintf,0x105682A8+1
        defadr _fopen,0x110155A4+1
        defadr fclose,0x115EE4F4+1
        defadr fread,0x11016CE8+1
        defadr fwrite,0x11016EB4+1
        defadr fstat,0x11015E9C+1
        defadr AllocDirHandle,0x1101359C+1
        defadr GetFname,0x1101376C+1
        defadr DataBrowserDesc_Create,0x1105C438+1
        defadr DataBrowserDesc_SetStyle,0x1105C6B8+1
        defadr DataBrowserDesc_SetHeaderText,0x1105C6E8+1
        defadr DataBrowserDesc_SetFolders,0x1105C6D0+1
        defadr DataBrowserDesc_SetOKSoftKeyText,0x1105C6F0+1
        defadr DataBrowser_Create,0x1105896C+1
        defadr DataBrowserDesc_Destroy,0x1105C4E8+1
        defadr getFileExtention,0x110188E4+1
        defadr DataBrowser_isFileInListExt,0x110139D0+1
        defadr Timer_ReSet,0x116426B4+1
        defadr Timer_Set,0x11642680+1
        defadr Timer_Kill,0x1164270C+1
        defadr CreateBook,0x11645AC0+1
        defadr BookObj_KillBook,0x11645BDC+1
        defadr BookObj_GotoPage,0x11645838+1
        defadr BookObj_ReturnPage,0x116459A0+1
        defadr FreeBook,0x116460CC+1
        defadr FindBook,0x11645618+1
        defadr Find_StandbyBook,0x11651608+1
        defadr BookObj_SetFocus,0x11645D60+1
        defadr GUIObject_SetTitleText,0x116E9228+1
        defadr GUIObject_Show,0x116E8CFC+1
        defadr ListMenu_SetCursorToItem,0x1169A61C+1
        defadr GUIObject_SetStyle,0x116E8D54+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1169B140+1
        defadr GUIonMessage_SetMenuItemText,0x1169B14C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1169B17C+1
        defadr GUIonMessage_SetMenuItemInfoText,0x1169B15C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x1169B16C+1
        defadr GUIonMessage_SetMenuItemIcon,0x1169B18C+1
        defadr DispObject_SetTitleText,0x116DD030+1
        defadr ListMenu_GetSelectedItem,0x1169A630+1
        defadr ListMenu_SetItemStyle,0x1169A680+1
        defadr GC_PutChar,0x116E6C84+1
        defadr IsScreenSaverBook,0x117200FC+1
        defadr StatusIndication_SetItemText,0x116F6E48+1
        defadr StatusIndication_ShowNotes,0x11652710+1
        defadr CreateStringInputVA,0x11678314+1
        defadr CreateOneOfMany,0x1169C778+1
        defadr OneOfMany_SetItemCount,0x1169C924+1
        defadr OneOfMany_SetChecked,0x1169C940+1
        defadr OneOfMany_SetTexts,0x1169C974+1
        defadr OneOfMany_GetSelected,0x1169C950+1
        defadr StatusIndication_Item8_SetText,0x1165261C+1
        defadr GUIObject_SoftKeys_SetAction,0x1170251C+1
        defadr GUIObject_SoftKeys_SetText,0x11702594+1
        defadr GUIObject_SoftKeys_SetEnable,0x11702684+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x1170263C+1
        defadr GUIObject_SoftKeys_RemoveItem,0x117024D0+1
        defadr GUIObject_SoftKeys_SetVisible,0x11702618+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x1170289C+1
        defadr wstrcpy,0x11006A64+1
        defadr wstrncpy,0x11006A7C+1
        defadr wstrcat,0x11006AA8+1
        defadr wstrncat,0x10568A10+1
        defadr wstrcmp,0x11006A34+1
        defadr wstrlen,0x11006A20+1
        defadr str2wstr,0x11007CE8+1
        defadr strcmp,0x1056807C+1
        defadr strlen,0x105680D8+1
        defadr wstr2strn,0x11006B40+1
        defadr TextID_CreateIntegerID,0x116C6324+1
        defadr TextID_Create,0x116C64E4+1
        defadr TextID_GetString,0x116C6A88+1
        defadr TextID_GetWString,0x116C6950+1
        defadr TextID_GetLength,0x116C6850+1
        defadr TextID_Destroy,0x116C677C+1
        defadr AB_DEFAULTNBR_GET,0x10F9C414+1
        defadr AB_READSTRING,0x10FA19B0+1
        defadr AB_READPHONENBR,0x10FA1A80+1
        defadr AB_GETNBROFITEMS,0x10FA1B38+1
        defadr PNUM_len,0x116C5AE8+1
        defadr PNUM2str,0x114E81D4+1
        defadr GUIObject_GetDispObject,0x116E8B70+1
        defadr List_Create,0x11465394+1
        defadr List_Destroy,0x114653BC+1
        defadr List_InsertFirst,0x11465508+1
        defadr Gif2ID,0x10FFBD30+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10FFBF60+1
        defadr REQUEST_DATEANDTIME_GET,0x10EEAAF4+1
        defadr IndicationDevice_Backlight_FadeToLevel,0x1171C9A0+1
        defadr GetFreeBytesOnHeap,0x11652E00+1
        defadr BookObj_Hide,0x11645D88+1
        defadr BookObj_Show,0x11645D98+1
        defadr StartAPP,0x116517B8+1
        defadr ListMenu_SetOnMessage,0x1169A754+1
        defadr manifest_GetParam,0x11022C74+1
        defadr lseek,0x1101705C+1
        defadr get_VBUFFER,0x100AC35C+1
        defadr List_RemoveAt,0x11465494+1
        defadr GetCurrentPID,0x100AA2A0+1
        defadr List_IndexOf,0x114654C8+1
        defadr alloc,0x100F4658
        defadr receive,0x100F4674
        defadr send,0x100F4664
        defadr sender,0x100F46B4
        defadr free_buf,0x100F4684
        defadr create_process,0x100F4750
        defadr start,0x100F4970
        defadr get_ptype,0x100F4820
        defadr current_process,0x100F476C
        defadr delay,0x100F46A4
        defadr hunt,0x100F486C
        defadr kill_proc,0x100F4898
        defadr receive_w_tmo,0x100F46D0
        defadr stop,0x100F4980
        defadr get_mem,0x100F47EC
        defadr get_envp,0x100AA080+1
        defadr set_envp,0x100AA094+1
        defadr get_bid,0x100F47A4
        defadr datetime2unixtime,0x1121AEB4+1
        defadr strcpy,0x105680A4+1
        defadr CreateMessage,0x1121A660+1
        defadr SendMessage,0x1121A6B4+1
        defadr WaitMessage,0x1121A73C+1
        defadr FreeMessage,0x1121A750+1
        defadr SendDispatchMessage,0x111E71A4+1
        defadr UIEventName,0x11642BDC+1
        defadr MissedEvents,0x2A28687C
        defadr UI_Event,0x11644908+1
        defadr UI_Event_wData,0x11644918+1
        defadr UI_Event_toBookID,0x11644960+1
        defadr UI_Event_toBookIDwData,0x11644974+1
        defadr List_Find,0x11465664+1
        defadr List_Get,0x114655B4+1
        defadr wstrrchr,0x11007DA4+1
        defadr BookObj_CallSubroutine,0x116458AC+1
        defadr List_InsertLast,0x11465510+1
        defadr debug_printf,0x2A20E2D0+1
        defadr PlayFile,0x11225944+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x117E550C+1
        defadr Profile_SetActive,0x117E7A24+1
        defadr SetBrightnessOfScreen,0x11667768+1
        defadr isKeylocked,0x11720138+1
        defadr IsMediaPlayerVideoBook,0x11629290+1
        defadr ShuttingDown,0x1164D676+1
        defadr Vibra,0x111F33DC+1
        defadr REQUEST_DATEFORMAT_GET,0x10EEACD4+1
        defadr REQUEST_TIMEFORMAT_GET,0x10EEADF4+1
        defadr Date2ID,0x1164F1A0+1
        defadr Time2ID,0x1164F0BC+1
        defadr CreateListMenu,0x1169A414+1
        defadr ListMenu_SetItemCount,0x1169A644+1
        defadr ROOT_APP,0x2A282E00
        defadr GUIObject_SoftKeys_SetInfoText,0x11702580+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x117026B8+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x11652E40+1
        defadr REQUEST_SYSTEM_RESTART,0x11652E50+1
        defadr SoftKeys_SetText,0x117025EC+1
        defadr IsRightNowBook,0x11711E04+1
        defadr IsVolumeControllerBook,0x117225D8+1
        defadr CreateTabMenuBar,0x116F5CD0+1
        defadr TabMenuBar_SetTabCount,0x116F5EE8+1
        defadr TabMenuBar_SetTabGui,0x116F5DA0+1
        defadr TabMenuBar_SetTabIcon,0x116F5E20+1
        defadr GUIObject_Destroy,0x116E8B00+1
        defadr GUIInput_SetIcon,0x116E8DE0+1
        defadr StringInput_GetStringAndLen,0x11678B98+1
        defadr GetAudioControlPtr,0x2A2792C4
        defadr AudioControl_Vibrate,0x10D88D44+1
        defadr GetVolumeSize,0x11018678+1
        defadr CreateNOfMany,0x1169C1D8+1
        defadr NOfMany_SetTexts,0x1169C3FC+1
        defadr NOfMany_SetChecked,0x1169C380+1
        defadr NOfMany_SetCursor,0x1169C348+1
        defadr NOfMany_GetCheckedCount,0x1169C3A4+1
        defadr NOfMany_GetChecked,0x1169C394+1
        defadr NOfMany_SetonMessage,0x1169C3F4+1
        defadr AudioControl_Init,0x11225A90+1
        defadr OneOfMany_SetFocused,0x1169C908+1
        defadr OneOfMany_SetOnMessage,0x1169C96C+1
        defadr CreateMonitorFeedback,0x1164CCA8+1
        defadr FeedBack_SetText,0x1164CD5C+1
        defadr GetBatteryState,0x105F1610+1
        defadr get_DisplayGC,0x116E623C+1
        defadr DispObject_GetRect,0x116DE620+1
        defadr GC_GetRect,0x116E6884+1
        defadr GC_GetXX,0x116E6B88+1
        defadr GC_SetXX,0x116E6B7C+1
        defadr GC_ValidateRect,0x116E6834+1
        defadr BookObj_AddGUIObject,0x11645E14+1
        defadr DrawRect,0x116E12B0+1
        defadr DrawString,0x116E15B0+1
        defadr XGUIList_AddGUIObject,0x11646260+1
        defadr DispObject_InvalidateRect,0x116DE3E0+1
        defadr GUIObject_Create,0x116E8A10+1
        defadr SetFont,0x116E2168+1
        defadr StatusRow_p,0x2A285408
        defadr root_list_get_session_count,0x11643C98+1
        defadr root_list_get_session,0x11643CA4+1
        defadr SESSION_GetTopBook,0x11643594+1
        defadr MainInput_getVisible,0x1170EEA4+1
        defadr MainInput_strlen,0x1170EF68+1
        defadr MainInput_getPNUM,0x1170EF98+1
        defadr BOOK_GetBookID,0x11646178+1
        defadr wstrncmp,0x10568A3C+1
        defadr DISP_OBJ_GetAbsoluteXPos,0x116DF5FC+1
        defadr DISP_OBJ_GetAbsoluteYPos,0x116DF630+1
        defadr DISP_OBJ_GetWindow,0x116DE910+1
        defadr GetThemeColor,0x1170660C+1
        defadr REQUEST_SETTING_SILENCE_SET,0x117E4F40+1
        defadr REQUEST_SETTING_SILENCE_GET,0x117E4EE8+1
        defadr VCALL_Init,0x10F93B9C+1
        defadr VCALL_SetName,0x10F93C94+1
        defadr VCALL_SetNameIcon,0x10F93CF4+1
        defadr VCALL_SetNumber,0x10F93CB4+1
        defadr VCALL_SetHZ1,0x10F93CD8+1
        defadr VCALL_SetHZ2,0x10F93CE4+1
        defadr MakeVoiceCall,0x10F93754+1
        defadr FileDelete,0x11015FC4+1
        defadr GUIObject_SetFocus,0x116E8C9C+1
        defadr MSG_SendMessage_CreateMessage,0x1129ECE4+1
        defadr MSG_SendMessage_DestroyMessage,0x1129F3FC+1
        defadr MSG_SendMessage_AddRecipient,0x1129EEC0+1
        defadr MSG_SendMessage_Start,0x1129F334+1
        defadr get_APP_DESC_TABLE,0x11AB2D2C
        defadr AB_POSITIONNBR_GET,0x10FA1D20+1
        defadr AB_NAME_ITEM2TextID,0x10FA1C34+1
        defadr AB_NUM_ITEM2TextID,0x10FA1C98+1
        defadr GetABRecNum,0x10FB527E+1
        defadr get_AB_ITEMS_DESC,0x11A69128
        defadr SBY_GetMainInput,0x100AC360+1
        defadr SBY_GetStatusIndication,0x10FEE3B8+1
        defadr REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET,0x10F14B1C+1
        defadr PID_MMI,0x2A2787EC
        defadr DispObject_GetGUI,0x116DDCD4+1
        defadr Display_GetFocusedDispObject,0x116DDC20+1
        defadr DispObject_GetVisible,0x116DE278+1
        defadr DispObject_GetDESC,0x100B92CC+1
        defadr DISP_DESC_SetName,0x116D92BC+1
        defadr DispObject_GetName,0x116DF36C+1
        defadr DISP_DESC_SetSize,0x116D92C0+1
        defadr DISP_DESC_SetOnCreate,0x116D92C4+1
        defadr DispObject_GetOnCreate,0x116D9340+1
        defadr DISP_DESC_SetOnClose,0x116D92C8+1
        defadr DispObject_GetOnClose,0x116D935C+1
        defadr DISP_DESC_SetOnRedraw,0x116D92CC+1
        defadr DispObject_GetOnRedraw,0x116D9378+1
        defadr DISP_DESC_SetOnKey,0x116D92D4+1
        defadr DispObject_GetOnKey,0x116D93B0+1
        defadr DISP_DESC_SetOnRefresh,0x116D92D0+1
        defadr DispObject_GetonRefresh,0x116D9394+1
        defadr DISP_DESC_SetMethod06,0x116D92D8+1
        defadr DispObject_GetMethod06,0x116D93CC+1
        defadr DISP_DESC_SetOnLayout,0x116D92E0+1
        defadr DispObject_GetOnLayout,0x116D9404+1
        defadr DISP_DESC_SetOnConfig,0x116D92E4+1
        defadr DispObject_GetOnConfig,0x116D9420+1
        defadr DISP_DESC_SetMethod0A,0x116D92E8+1
        defadr DispObject_GetMethod0A,0x116D943C+1
        defadr DISP_DESC_SetMethod0B,0x116D92EC+1
        defadr DispObject_GetMethod0B,0x116D9458+1
        defadr DISP_DESC_SetMethod0C,0x116D92F0+1
        defadr JavaSession_Manager,0x10FB79B4+1
        defadr JavaSession_GetName,0x10F63AB8+1
        defadr TextID_Copy,0x116C6688+1
        defadr BookObj_GetSession,0x11646118+1
        defadr GUIonMessage_SetNumberOfSubItems,0x1169B1E0+1
        defadr GUIonMessage_SubItem_SetText,0x1169B258+1
        defadr GUIonMessage_SubItem_GetCreatedParentIndex,0x1169B24C+1
        defadr GoMusic,0x114CD820+1
		defadr Vibra_Off,0x111F34AC+1
        defadr PlayFileV,0x11225948+1
        defadr GetSilent,0x111F28F4+1
        defadr GetVibrator,0x111EE7D0+1
        defadr GetAudioSettings,0x111F3778+1
        defadr GUIonMessage_GetCurrentSubItem,0x1169B240+1
        defadr GUIonMessage_GetCurrentItemIndex,0x1169B234+1
        defadr DestroyDirHandle,0x110138E8+1
        defadr LastExtDB,0x11A7F408
        defadr GetOtherExtMethods,0x11052BCC+1
        defadr MessageBox,0x1164B7BC+1
        defadr Display_GetHeight,0x116F82AC+1
        defadr Display_GetWidth,0x116F82B8+1
        defadr PlaySystemSound,0x112258EC+1
        defadr TabMenuBar_GetFocusedTab,0x116F5D94+1
        defadr TabMenuBar_SetFocusedTab,0x116F5D84+1
        defadr GC_GetPenColor,0x116E6A90+1
        defadr GC_SetPenColor,0x116E6A54+1
        defadr GC_SetPixel,0x116E66D4+1
        defadr GC_DrawLine,0x116E7514+1
        defadr GC_DrawFRect,0x116E769C+1
        defadr GC_DrawBitmap,0x116E6760+1
        defadr png_create_read_struct_2,0x10B73660+1
        defadr png_destroy_read_struct,0x10B737AC+1
        defadr png_create_info_struct,0x10B71E08+1
        defadr png_destroy_info_struct,0x10B71E3C+1
        defadr png_set_progressive_read_fn,0x10B73638+1
        defadr png_process_data,0x10B725F8+1
        defadr png_read_update_info,0x10B73780+1
        defadr png_get_progressive_ptr,0x10B7365C+1
        defadr png_get_IHDR,0x10B722C4+1
        defadr png_set_strip_16,0x10B7394C+1
        defadr png_set_gray_1_2_4_to_8,0x10B73958+1
        defadr png_set_gray_to_rgb,0x10B7397C+1
        defadr png_get_valid,0x10B72298+1
        defadr png_set_tRNS_to_alpha,0x10B73970+1
        defadr png_set_filler,0x10B766D8+1
        defadr png_set_palette_to_rgb,0x10B73964+1
        defadr png_get_rowbytes,0x10B722B0+1
        defadr png_progressive_combine_row,0x10B73618+1
        defadr png_sig_cmp,0x10B71D00+1
        defadr setjmp,0x100C36A4
        defadr longjmp,0x100C36C8
        defadr inflateInit2_,0x10B77398+1
        defadr inflate,0x10B77540+1
        defadr inflateEnd,0x10B78838+1
        defadr memcmp,0x2A1C0820
        defadr strncmp,0x10568114+1
        defadr strncpy,0x10568148+1
        defadr strcat,0x10568044+1
        defadr GUIObject_SetTitleType,0x116E920C+1
        defadr GUIonMessage_SetItemDisabled,0x1169B1EC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10FFBFD8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10FFC060+1
        defadr get_Surfaces,0x2A444380
        defadr iconidname2id,0x10D35820+1
        defadr textidname2id,0x10EE1720+1
        defadr ListMenu_SetNoItemText,0x1169A7D4+1
        defadr IsFmRadioBook,0x1136763C+1
        defadr IsAudioPlayerBook,0x115F8A3C+1
		defadr get_IsAudioPlayerBook,0x115F8A3C+1
        defadr PlayerControl,0x115F85FC+1
        defadr SwitchRadioStationFromList,0x11365804+1
        defadr Shortcut_Run,0x11708FD0+1
        defadr mkdir,0x11012D7C+1
        defadr rmdir,0x11013148+1
        defadr chmod,0x11015F00+1
        defadr rename,0x110164E0+1
        defadr GetImageWidth,0x116E2734+1
        defadr GetImageHeight,0x116E2748+1
        defadr CallID_GetCallStatusDesc,0x10F5DA94+1
        defadr CallStatusDesc_GetName,0x10F5D0B8+1
        defadr List_FreeElements,0x114656A8+1
        defadr strstr,0x105681E4+1
        defadr GPRS_GetLastSessionInfo,0x11758888+1
        defadr wstrcmpni,0x11007E40+1
        defadr wtoi,0x116420D8+1
        defadr DATE_GetWeekDay,0x1121B1B0+1
        defadr Cale_GetSettings,0x10F21D88+1
        defadr wstrwstr,0x10568B9C+1
        defadr wstrcmpi,0x11007E84+1
        defadr wstrchr,0x10568984+1
        defadr GUIObject_SoftKeys_Hide,0x117028E8+1
        defadr GUIObject_SoftKeys_Show,0x117028F4+1
        defadr DispObject_SoftKeys_Get,0x116FEEBC+1
        defadr StandbyBackground_SetImage,0x116D6078+1
        defadr CreateYesNoQuestionVA,0x116F7CAC+1
        defadr ListMenu_SetItemSecondLineText,0x1169AA2C+1
        defadr _REQUEST_OAF_START_APPLICATION,0x11044F10+1
        defadr FSX_isNameInvalid,0x11018468+1
        defadr DataBrowserDesc_SetFoldersNumber,0x1105C6D8+1
        defadr DataBrowserDesc_SetActions,0x1105C6AC+1
        defadr DataBrowserDesc_SetSelectAction,0x1105C654+1
        defadr DataBrowserDesc_SetSelectActionOnFolders,0x1105C65C+1
        defadr DataBrowserDesc_SetBookID,0x1105C638+1
        defadr DataBrowserDesc_SetItemFilter,0x1105C5DC+1
        defadr DataBrowserDesc_SetOption,0x1105C708+1
        defadr DataBrowserDesc_SetOpenEmptyFolder,0x1105C770+1
        defadr DataBrowserDesc_SetFileExtList,0x1105C5E4+1
        defadr FSX_RemoveIllegalSymbolsName,0x110656E4+1
        defadr FILEITEM_Create,0x110650FC+1
        defadr FILEITEM_Destroy,0x1106522C+1
        defadr CreateDateInputVA,0x116F601C+1
        defadr CreateTimeInputVA,0x116F7870+1
        defadr StringInput_SetCursorPosition,0x11678BE4+1
        defadr BookObj_CallPage,0x11645938+1
        defadr DateInput_GetDateInt,0x116F628C+1
        defadr TimeInput_GetTimeInt,0x116F7B38+1
        defadr GetFontDesc,0x2A2858DC
        defadr GetFontCount,0x2A285C4C
        defadr GC_GetBrushColor,0x116E6B70+1
        defadr GC_SetBrushColor,0x116E6B30+1
        defadr GC_DrawRoundRect,0x116E76E4+1
        defadr MenuBook_Desktop,0x117088F0+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x11707F44+1
        defadr BookObj_Softkey_SetAction,0x116FCCD0+1
        defadr BookObj_Softkey_SetText,0x116FCD08+1
        defadr FindBookByID,0x11643B64+1
        defadr TextFeedbackWindow,0x116F7128+1
        defadr Feedback_SetKeyHook,0x116F7530+1
        defadr Feedback_SetOnClose,0x116F74D0+1
        defadr Feedback_SetTimeout,0x116F73EC+1
        defadr Feedback_SetTextExtended,0x116F7594+1
        defadr TabMenuBar_SetOnTabSwitch,0x116F5E7C+1
        defadr KeyCode2Name,0x1128DF9C+1
        defadr ImageID_Get,0x10FFFA10+1
        defadr ImageID_Free,0x11000040+1
        defadr DataBrowser_CreateSubExecute,0x11045BF4+1
        defadr DataBrowser_ExecuteSubroutine,0x11046774+1
        defadr FILEITEM_SetFname,0x110652D8+1
        defadr FILEITEM_SetPath,0x11065598+1
        defadr FILEITEM_GetFname,0x11065590+1
        defadr FILEITEM_GetPath,0x11065624+1
        defadr FILEITEM_SetFnameAndContentType,0x11065338+1
        defadr FILEITEM_SetPathAndContentType,0x110655FC+1
        defadr JavaDialog_Open,0x1102FEA8+1
        defadr JavaDialog_Close,0x11033584+1
        defadr JavaAppDesc_Get,0x11033748+1
        defadr JavaAppDesc_GetFirstApp,0x11025EB4+1
        defadr JavaAppDesc_GetNextApp,0x11025EBC+1
        defadr JavaAppDesc_GetJavaAppInfo,0x110259C0+1
        defadr DispObject_SetRefreshTimer,0x116DDE60+1
        defadr DispObject_KillRefreshTimer,0x116DDEDC+1
        defadr IsDataBrowserBook,0x11059220+1
        defadr BrowserItem_Get_SUB_EXECUTE,0x11054A8C+1
        defadr Shortcut_Get_MenuItemName,0x11713D88+1
        defadr Shortcut_Get_MenuItemIconID,0x11708AE0+1
        defadr FindBookEx,0x11643BF8+1
        defadr FILEITEM_CreateCopy,0x1106512C+1
        defadr ImageID_Copy,0x10FFFFFC+1
        defadr BookObj_GetSessionID,0x1164607C+1
        defadr UI_Event_toSID,0x1164492C+1
        defadr UI_CONTROLLED_SHUTDOWN_RESPONSE,0x1164D698+1
        defadr MainInput_getCurPos,0xEDA51BD1
        defadr MainInput_Hide,0x1170EE94+1
        defadr DispObject_SoftKeys_RestoreDefaultAction,0x116FE864+1
        defadr PNUM2Name,0x10F8F4A4+1
        defadr SpeedDial_GetPNUM,0x10FAFFF4+1
        defadr DispObject_GetWindowWidth,0x116DF57C+1
        defadr DispObject_GetWindowHeight,0x116DF59C+1
        defadr get_system_langID,0x1165DA5C+1
        defadr lang_get_name,0x11737A00+1
        defadr w_chdir,0x1009F194
        defadr w_fopen,0x10801A14+1
        defadr w_fstat,0x10801ACC+1
        defadr w_fwrite,0x10801A5C+1
        defadr w_fread,0x10801A44+1
        defadr w_lseek,0x114645B0+1
        defadr w_fclose,0x10801A74+1
        defadr w_mkdir,0x1009F12C
        defadr DirHandle_SetFilterStr,0x11013940+1
        defadr Disp_GetTextIDWidth,0x116E27D0+1
        defadr ImageID_GetIndirect,0x10FFFA88+1
        defadr unixtime2datetime,0x1121AFC8+1
        defadr List_Insert,0x114653E4+1
        defadr FileCopy,0x110162A4+1
        defadr FileMove,0x110164E0+1
        defadr DispObject_SetLayerColor,0x116E0288+1
        defadr JavaAppDesc_GetJavaAppID,0x110336A4+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x1111B138+1
        defadr JavaApp_LogoImageID_Get,0x1110FB80+1
        defadr CreateProgressBar,0x116F6754+1
        defadr ProgressBar_SetText,0x116F6A6C+1
        defadr ProgressBar_SetIcon,0x116F6B88+1
        defadr ProgressBar_SetPercentValue,0x116F6A28+1
        defadr ProgressBar_SetBarDisabled,0x116F6B98+1
        defadr StringInput_DispObject_SetText,0x1166DEC4+1
        defadr GUIObject_SetTitleIcon,0x116E9260+1
        defadr DispObject_SoftKeys_GetParams,0x116FFB30+1
        defadr DispObject_SoftKeys_GetList,0x116FFB74+1
        defadr BookObj_GetDisplayOrientation,0x11646218+1
        defadr BookObj_SetDisplayOrientation,0x116461B0+1
        defadr Display_GetTopBook,0x11645634+1
        defadr Display_GetBrightness,0x11667628+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x1105C640+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x1105C69C+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x1105C6A4+1
        defadr SetTheme,0x11703484+1
        defadr SoftKeys_GetLabel,0x11701EA4+1
        defadr SoftKeys_Update,0x11701AB8+1
        defadr get_CellData,0x1179E418+1
        defadr IncommingCall_Reject,0x10F65FC8+1
        defadr IncommingCall_Mute,0x10F67304+1
        defadr Bluetooth_GetState,0x10F30924+1
        defadr Bluetooth_GetPhoneVisibility,0x10F308EC+1
        defadr Bluetooth_isBusy,0x10F309AC+1
        defadr USB_isConnected,0x1147E3EC+1
        defadr w_diropen,0x1009F13C
        defadr w_dirread,0x11464C40+1
        defadr w_dirclose,0x1009F17C
        defadr w_rename,0x11464CDC+1
        defadr w_remove,0x11464C90+1
        defadr IsCameraBook,0x1152D410+1
        defadr IsSoundRecorderBook,0x110ED528+1
        defadr StringInput_MenuItem_SetPriority,0x11678CEC+1
        defadr Video_ActionBack,0x11628C88+1
        defadr Video_ExtractFrame,0x11629438+1
        defadr Video_ZoomOn,0x11628C58+1
        defadr RightNow_SetActive,0x11712774+1
        defadr Video_Play,0x11628B90+1
        defadr Video_Pause,0x11628BA0+1
        defadr Audio_Pause,0x115FA45C+1
        defadr Audio_Play,0x115FA3D8+1
        defadr CreatePercentInputVA,0x116F63AC+1
        defadr PercentInput_GetPercent,0x116F6538+1
        defadr GUIonMessage_SetLineSeparator,0x1169B204+1
        defadr PHF_GetState,0x11668170+1
        defadr CHF_GetState,0x11668178+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x11702900+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1170290C+1
        defadr SetTrayIcon,0x116D8CB0+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x117E4C00+1
        defadr REQUEST_SETTING_VIBRATOR_SET,0x117E4DDC+1
        defadr REQUEST_SETTING_RINGTYPESOUNDFILE_SET,0x117E4D58+1
        defadr REQUEST_SETTING_ANSWERINGMODE_SET,0x117E51C0+1
        defadr REQUEST_SETTING_INCREASINGRING_SET,0x117E4CBC+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_SET,0x117E4FE8+1
        defadr JavaAppDesc_GetJavaAppFullpath,0x11024F28+1
        defadr SoundRecorderDesc_Create,0x110ECA64+1
        defadr SoundRecorderDesc_Destroy,0x110ECAC0+1
        defadr SoundRecorderDesc_SetBookID,0x110ECADC+1
        defadr SoundRecorderDesc_SetType,0x110ECB08+1
        defadr SoundRecorderDesc_SetFolder,0x110ECB1C+1
        defadr SoundRecorderDesc_SetFname,0x110ECB38+1
        defadr SoundRecorderDesc_SetRecordSize,0x110ECB54+1
        defadr SoundRecorder_Create,0x110ECBCC+1
        defadr SoundRecorder_RecordCall,0x10F5A54C+1
        defadr Browser_OpenURI,0x10FD0C6C+1
        defadr GetURIScheme,0x114E73FC+1
        defadr CreateURI,0x114E7898+1
        defadr DataBrowserDesc_SetViewModeAndSortOrder,0x1105C6C0+1
        defadr Alarm_GetCurrentTypeAndAlarmID,0x10EE758C+1
        defadr Alarm_GetState,0x10EE5F3C+1
        defadr Alarm_GetTIME,0x10EE6D94+1
        defadr Alarm_GetWeekSettings,0x10EE7D24+1
        defadr REQUEST_SETTING_ALLOWEDCALLERS_GET,0x117E4F8C+1
        defadr IncommingCall_Accept,0x10F65E8C+1
        defadr MediaPlayer_SoftKeys_SetText,0x115FEEB8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x115FEE70+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x115FEF18+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x115FEF48+1
        defadr DispObject_Show,0x116DE118+1
        defadr Request_EventChannel_Subscribe,0x1003F2FC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x117028C8+1
        defadr Request_ICA_ShutdownAllConnections,0x109ECB44+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x117E5638+1
        defadr DataBrowserDesc_SetFocusToFILEITEM,0x1105C778+1
        defadr GUIonMessage_GetMsg,0x1169B11C+1
        defadr GUIonMessage_GetBook,0x1169B124+1
        defadr GUIonMessage_GetGui,0x1169B120+1
        defadr GUIonMessage_GetSelectedItem,0x1169B128+1
        defadr GUIonMessage_GetPrevSelectedItem,0x1169B134+1
        defadr ObexSendFile,0x10F8BD9C+1
        defadr Feedback_SetManualScrollingText,0x116F15DC+1
        defadr EqualizerGain_Set,0x111F1580+1
        defadr CANVAS_Get_GviGC,0x105FE504+1
        defadr GVI_BitBlt,0x106AD190+1
        defadr GVI_StretchBlt,0x106AD304+1
        defadr GVI_TransformBlt,0x106AD3C0+1
        defadr GVI_CreatePen,0x106AC438+1
        defadr GVI_CreateDashedPen,0x106AC47C+1
        defadr GVI_CreateSolidBrush,0x106AC348+1
        defadr GVI_Delete_GVI_Object,0x106ABD18+1
        defadr GVI_DrawEllipse,0x106ACAC8+1
        defadr GVI_DrawLine,0x106AD9A4+1
        defadr GVI_DrawLines,0x106AE034+1
        defadr GVI_DrawPolyLine,0x106AE0B8+1
        defadr GVI_DrawRectangle,0x106AE334+1
        defadr GVI_DrawRoundRect,0x106ACFE4+1
        defadr GVI_DrawSolidLines,0x106ADBF8+1
        defadr GVI_DrawSolidPolyLine,0x106ADE00+1
        defadr GVI_DrawSolidRectangle,0x106ADEA4+1
        defadr GVI_FillEllipse,0x106ACEB0+1
        defadr GVI_FillPolygon,0x106AD85C+1
        defadr GVI_FillRectangle,0x106AE1B4+1
        defadr GVI_FillRectangles,0x106AE240+1
        defadr GVI_FillSolidEllipse,0x106ACF5C+1
        defadr GVI_FillSolidRectangle,0x106ADA34+1
        defadr GVI_FillSolidRoundRect,0x106AD134+1
        defadr GVI_FillSolidTriangle,0x106AD7E8+1
        defadr GC_CreateMemoryGC,0x116E624C+1
        defadr GC_FreeGC,0x116E6310+1
        defadr Settings_ShowNumber_Get,0x10F870C4+1
        defadr GVI_CreateBitmap,0x106AC534+1
        defadr GVI_CreateMemoryGC,0x106AE498+1
        defadr GVI_DeleteMemoryGC,0x106DA0D4+1
        defadr StringInput_DispObject_SetLanguage,0x11672258+1
        defadr List_InsertSorted,0x1146552C+1
        defadr ListMenu_SetItemIcon,0x1169A93C+1
        defadr wstrnupr,0x11006AF0+1
        defadr wstrnlwr,0x113412F4+1
        defadr ListMenu_SetItemTextScroll,0x1169AD84+1
        defadr GUIObject_SetListTextColor,0x1169BC64+1
        defadr DispObject_SetTitleTextColor,0x116DD2C4+1
        defadr DispObject_SetListTextColor,0x1168EDF0+1
        defadr DispObject_SetCursorImage,0x1168EDAC+1
        defadr DispObject_SetBackgroundImage,0x1168EDC8+1
        defadr DispObject_SetTitleBackgroundImage,0x116DD2DC+1
        defadr TabMenuBar_SetTabTitle,0x116F5E68+1
        defadr GUIObject_GetBook,0x116E8B84+1
        defadr SoftKeys_GetSelectedAction,0x116FE79C+1
        defadr MonitorFeedback_SetTimer,0x1164CD50+1
        defadr void,0x1169C27D
        defadr ListMenu_DestroyItems,0x1169AB08+1
        defadr DispObject_SetScrollBarBackgroundColor,0x116DF87C+1
        defadr DispObject_SetScrollBarColor,0x116DF854+1
        defadr DispObject_SetSoftkeysColor,0x116FED34+1
        defadr YesNoQuestion_SetIcon,0x116F7F48+1
        defadr GUIObject_SetBacklightTimeout,0x116E8E60+1
        defadr ListMenu_SetHotkeyMode,0x1169A780+1
        defadr ListMenu_SetSearchLanguageMode,0x1169AC68+1
        defadr ListMenu_EnableSearchHeader,0x1169AC90+1
        defadr GUIonMessage_GetSearchString,0x1169B33C+1
        defadr GUIonMessage_GetSearchStringLength,0x1169B35C+1
        defadr EqualizerGain_Get,0x111F1558+1
        defadr Theme_DestroyMenuIcons,0x11707214+1
        defadr CoCreateInstance,0x11748C44+1
        defadr GUIObject_SetSecondRowTitleText,0x116E9244+1
        defadr ListMenu_GetItemCount,0x1169A658+1
        defadr OSE_GetShell,0x1121A594+1
        defadr swscanf,0x105682DC+1
        defadr sscanf,0x100A80C4+1
        defadr BookObj_WindowSetWantsFocus,0x11645DBC+1
        defadr BookObj_StayOnTop,0x11646188+1
        defadr DispObject_WindowSetPosition,0x116DF504+1
        defadr DispObject_WindowSetSize,0x116DF470+1
        defadr Feedback_DispObject_GetText,0x116F1CF8+1
        defadr DispObject_SoftKeys_ExecuteAction,0x116FEAA4+1
        defadr DataBrowserBook_GetCurrentFoldersList,0x11058878+1
        defadr DispObject_SetAnimation,0x116E0340+1
        defadr GUIObject_SetZOrder,0x116E8DA0+1
        defadr StringInput_GetCursorPosition,0x11678BFC+1
        defadr str2PNUM,0x114E8284+1
        defadr pb_ui_search_bk_create_search_menu,0x10FAB104+1
        defadr ThemeImage_Delete,0x116D634C+1
        defadr GUIObject_SoftKeys_SubActionPressedNotification,0x11702700+1
	defadr DisplayGC_AddRef,0x116E6678+1
	defadr GetChipID_int,0x10002960+1

		
	defadr Str2ID,0x116C64E4+1
	defadr TextFree,0x116C677C+1
	defadr int2strID,0x116C6324+1
	defadr BookObj_GetBookID,11646178+1

//////////////////


///////////////

        defadr WALKMAN_DefaultRedraw,0x115FC95C+1
        defadr WALKMAN_Default_ONCREATE,0x115FC6C8+1
        defadr WALKMAN_Default_ONDESTROY,0x115FC8CC+1
		
        defadr DefaultOnNewTrack,0x115FAE3C+1
        defadr Default_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x115FACB8+1
        defadr Default_PATCH_UI_MEDIAPLAYER_CREATED_EVENT,0x115FAAB4+1	
        defadr Default_MUSIC_APP_ON_ENTER_PAGE,0x115F8ED0+1

	EXTERN New_WALKMAN_REDRAW
	EXTERN New_WALKMAN_ONCREATE
	EXTERN New_ON_DESTROY
	EXTERN New_ON_NEW_TRACK
	EXTERN New_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
	EXTERN New_PATCH_UI_MEDIAPLAYER_CREATED_EVENT
	EXTERN New_Action
	EXTERN List_Name
	EXTERN Info_Str
        EXTERN Info_Viz
	EXTERN NewSecondLine
	EXTERN New_MUSIC_APP_ON_ENTER_PAGE_HOOK
	EXTERN LoadLandscapeData
	EXTERN LoadPortraitData
	EXTERN page_Choose_Album_Art
        EXTERN TimerKill
        EXTERN TimerStart
	EXTERN Set_WALKMAN_GUI_STYLE
        EXTERN List_Name_Viz
		
	
	RSEG PATCH_UI_MEDIAPLAYER_CREATED_EVENT_HOOK(2)
	DATA
	DCD New_PATCH_UI_MEDIAPLAYER_CREATED_EVENT

	RSEG MUSIC_APP_ON_ENTER_PAGE_HOOK(2)
	DATA
	DCD New_MUSIC_APP_ON_ENTER_PAGE_HOOK

	RSEG PATCH_REDRAW_HOOK(2)
	DATA
	DCD New_WALKMAN_REDRAW	    

	RSEG PATCH_ON_NEW_TRACK_HOOK(2)
	DATA
	DCD New_ON_NEW_TRACK

	RSEG PATCH_ONDESTROY_HOOK(2)
	DATA
	DCD New_ON_DESTROY
        
	RSEG PATCH_ONCREATE_HOOK(2)
	DATA
	DCD New_WALKMAN_ONCREATE
        
	RSEG PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT_HOOK(2)
	DATA
	DCD New_PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        
	
        RSEG PATCH_UPDATE_ORIENTATION_HOOK(2)
        CODE16
	ldr	r3, =Patch_ORIENTATION
	bx	r3  
		
        RSEG  CODE
        CODE16 	
Patch_ORIENTATION:
	CMP     R5, #0
	BEQ     Portrait
	CMP     R5, #1
	BEQ     Landscape
	CMP     R5, #2
	BEQ     Landscape
	B       Continuer
Portrait:
	BL      LoadPortraitData
	B       Continuer
Landscape: 
	BL      LoadLandscapeData                         
Continuer:                          
	ldr	r3, =0x1164620A+1
	bx	r3


		        
        RSEG PATCH_START_TIMER(2)
        CODE16	  
	ldr	r3, =Play_Event_New
	bx	r3
		
        RSEG PATCH_START_TIMER_2(2)
        CODE16	  
	ldr r3, =Play_Event_New_2
	bx r3

	RSEG PATCH_STOP_TIMER(2)
        CODE16	
	ldr	r3, =Pause_Event_New
	bx	r3

	RSEG PATCH_STOP_TIMER_2(2)
        CODE16	
	ldr	r3, =Stop_Event_New
	bx	r3		

        RSEG  CODE
        CODE16	
Play_Event_New:	
	BL	TimerStart	
	LDR     R1, =0x1193C2D4		// "IAudioPlayer_Resume"
	ADD	R0, R5, #0
	BL      sub_100C88BC
	ldr	r3, =0x10917C28+1
	bx	r3
        
Play_Event_New_2:
        ADD	R4, #8
	ADD	R1, R4, #0
	ADD	R0, R7, #0
	BL	sub_100C88BC
	BL	TimerStart
	ldr	r3, =0x10917AFA+1
	bx	r3
        
Pause_Event_New:		
	LDR     R1, =0x1193C2C0		// "IAudioPlayer_Pause"
	ADD     R0, R5, #0
	BL      sub_100C88BC
        BL	TimerKill
	ldr	r3, =0x10917B4C+1
	bx	r3

Stop_Event_New:
	ADD	R0, R6, #0
	BL	sub_100C88BC
	ADD	R0, R6, #0
        BL	TimerKill
	ldr	r3, =0x10917CDC+1
	bx	r3
sub_100C88BC:
	ldr	r3, =0x1077708C+1
	bx	r3

	RSEG PATCH_NEW_LIST(2)
	CODE16
	ldr	r3, =Add_List
	blx	r3     
        
        RSEG  CODE
        CODE16	
Add_List:
	mov	r2, #0x13
	mov	r1, #0xF 
	BL	sub_GUIObject_SoftKeys_SetItemAsSubItem
	ldr	r0, [r4,#0x1C]
	ldr	r2, =New_Action
	mov	r1, #0x13
	BL	sub_GUIObject_SoftKeys_SetAction
	bl	List_Name
        mov	r2, r0
	ldr	r0, [r4,#0x1C]
	mov	r1, #0x13
	BL	sub_GUIObject_SoftKeys_SetText
        bl      Info_Str
        mov     r2, r0
        LDR	R0, [R4,#0x1C]
        MOV	R1, #0x13
        BL      sub_GUIObject_SoftKeys_SetInfoText
        
	ldr	r0, [r4,#0x1C]
	mov	r2, #0x13
	mov	r1, #0xF
	BL	sub_MediaPlayer_SoftKeys_SetItemAsSubItem		
	ldr	r0, [r4,#0x1C]
	ldr	r2, =New_Action
	mov	r1, #0x13
	BL	sub_MediaPlayer_SoftKeys_SetAction		
	bl	List_Name
        mov	r2, r0
	ldr	r0, [r4,#0x1C]
	mov	r1, #0x13
	BL	sub_MediaPlayer_SoftKeys_SetText
        bl      Info_Str
        mov     r2, r0
        LDR	R0, [R4,#0x1C]
        MOV	R1, #0x13
        BL      sub_MediaPlayer_SoftKeys_AddHelpStr
        
	ldr	r0, [r4,#0x1C]
	mov	r2, #0x14
	mov	r1, #0xF
	BL	sub_GUIObject_SoftKeys_SetItemAsSubItem		
	ldr	r0, [r4,#0x1C]
	ldr	r2, =New_Action_Viz
	mov	r1, #0x14
	BL	sub_GUIObject_SoftKeys_SetAction
	bl	List_Name_Viz
        mov	r2, r0
	ldr	r0, [r4,#0x1C]
	mov	r1, #0x14
	BL	sub_GUIObject_SoftKeys_SetText	
        bl      Info_Viz
        mov     r2, r0
        LDR	R0, [R4,#0x1C]
        MOV	R1, #0x14
        BL      sub_GUIObject_SoftKeys_SetInfoText
        
	ldr	r0, [r4,#0x1C]
	mov	r2, #0x14
	mov	r1, #0xF
	BL	sub_MediaPlayer_SoftKeys_SetItemAsSubItem		
	ldr	r0, [r4,#0x1C]
	ldr	r2, =New_Action_Viz
	mov	r1, #0x14
	BL	sub_MediaPlayer_SoftKeys_SetAction
	bl	List_Name_Viz
        mov	r2, r0
	ldr	r0, [r4,#0x1C]
	mov	r1, #0x14
	BL	sub_MediaPlayer_SoftKeys_SetText
	bl      Info_Viz
        mov     r2, r0
        LDR	R0, [R4,#0x1C]
        MOV	R1, #0x14
        BL      sub_MediaPlayer_SoftKeys_AddHelpStr
        
	ldr	r0, [r4,#0x1C]
	mov	r2, #0xC
	mov	r1, #0xF
	BL	sub_GUIObject_SoftKeys_SetItemAsSubItem	
	ldr	r0, [r4,#0x1C]		
	ldr	r3, =0x115F9DFA+1
	bx	r3
		
New_Action_Viz:		
	PUSH    {LR}            
	MOV     R1, #0x8C   
	MOV     R2, #1          
	STRB    R2, [R0,R1]     
	LDR     R1, =page_Choose_Album_Art                   
	LDR     R3, =BookObj_CallPage
	BLX     R3              
	POP     {PC} 

sub_GUIObject_SoftKeys_SetItemAsSubItem:									
	LDR	R3, =GUIObject_SoftKeys_SetItemAsSubItem
	BX	R3
sub_GUIObject_SoftKeys_SetAction:
	LDR	R3, =GUIObject_SoftKeys_SetAction
	BX	R3
sub_GUIObject_SoftKeys_SetText:
	LDR	R3, =GUIObject_SoftKeys_SetText
	BX	R3
sub_GUIObject_SoftKeys_SetInfoText:
        LDR	R3, =GUIObject_SoftKeys_SetInfoText
        BX	R3
        
sub_MediaPlayer_SoftKeys_SetItemAsSubItem:				
	LDR	R3, =MediaPlayer_SoftKeys_SetItemAsSubItem
	BX	R3		
sub_MediaPlayer_SoftKeys_SetAction:									
	LDR	R3, =MediaPlayer_SoftKeys_SetAction
	BX	R3		
sub_MediaPlayer_SoftKeys_SetText:				
	LDR	R3, =MediaPlayer_SoftKeys_SetText
	BX	R3
sub_MediaPlayer_SoftKeys_AddHelpStr:
        LDR	R3, =MediaPlayer_SoftKeys_AddHelpStr
        BX	R3

        RSEG PATCH_StereoWidening(2)
	CODE16
	NOP
  
        RSEG PATCH_Walkman_GUI(2)
	CODE16
	ldr	r3, =_walkmanGui
	bx	r3
        
	RSEG  CODE
        CODE16 	
_walkmanGui:
	BL	Set_WALKMAN_GUI_STYLE
	ADD	R0, R7, #0
	POP	{R1-R7,PC}


	RSEG PATCH_UPDATE_SHUFFLE_HOOK(2)
	CODE16
	LDR	r3, =_shuffle_fix
	BLX	r3
        
	RSEG  CODE
        CODE16 			
_shuffle_fix:
	bl	NewSecondLine
	MOV	R0, #0x3C
	LDRB    R1, [R4,R0]
	LDR     R0, [R5,#0]
	ldr	R3, =0x115F9358+1
	BX	r3
#endif
        END
          