#ifdef C510_R1HA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
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
        defadr CreateBook,0x142866FC+1
        defadr BookObj_GotoPage,0x14481B20+1
        defadr BookObj_ReturnPage,0x14212A58+1
        defadr FreeBook,0x141293FC+1
        defadr GUIObject_SetTitleText,0x1443F740+1
        defadr GUIObject_Show,0x144CB9BC+1
        defadr ListMenu_SetCursorToItem,0x14417A80+1
        defadr GUIObject_SetStyle,0x14129878+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142C5BB4+1
        defadr GUIonMessage_SetMenuItemText,0x1438A538+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141326FC+1
        defadr ListMenu_GetSelectedItem,0x142800F8+1
        defadr ListMenu_SetItemStyle,0x140B9BF0+1
        defadr CreateOneOfMany,0x140B9B74+1
        defadr OneOfMany_SetChecked,0x1422CD38+1
        defadr OneOfMany_SetTexts,0x1419F5AC+1
        defadr OneOfMany_GetSelected,0x14457AA8+1
        defadr GUIObject_SoftKeys_SetAction,0x1417BACC+1
        defadr GUIObject_SoftKeys_SetText,0x141C50C8+1
        defadr GUIObject_SoftKeys_SetVisible,0x141C4E24+1
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
        defadr TextID_Create,0x141818E4+1
        defadr TextID_Destroy,0x14182788+1
        defadr GUIObject_GetDispObject,0x140CACD8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x144B9C9C+1
        defadr BookObj_Hide,0x142753C4+1
        defadr ListMenu_SetOnMessage,0x14302734+1
        defadr get_envp,0x101D68A8+1
        defadr set_envp,0x101D68BC+1
        defadr UI_Event,0x140C5938+1
        defadr CreateListMenu,0x14285AF8+1
        defadr ListMenu_SetItemCount,0x14280610+1
        defadr GUIObject_Destroy,0x144CBD98+1
        defadr get_DisplayGC,0x1449E09C+1
        defadr GC_GetRect,0x140C9E80+1
        defadr GC_GetXX,0x1419CE14+1
        defadr GC_SetXX,0x140B2DB8+1
        defadr BookObj_AddGUIObject,0x14285AEC+1
        defadr DrawRect,0x1445A7BC+1
        defadr DispObject_InvalidateRect,0x140CA948+1
        defadr GUIObject_Create,0x144CB8B0+1
        defadr DISP_DESC_SetName,0x142957C4+1
        defadr DISP_DESC_SetSize,0x142958A8+1
        defadr DISP_DESC_SetOnCreate,0x14295844+1
        defadr DISP_DESC_SetOnClose,0x14295840+1
        defadr DISP_DESC_SetOnRedraw,0x14295848+1
        defadr DISP_DESC_SetOnKey,0x14295990+1
        defadr DISP_DESC_SetOnRefresh,0x1429540C+1
        defadr DISP_DESC_SetMethod0A,0x142954CC+1
        defadr GC_GetPenColor,0x14435440+1
        defadr GC_SetPenColor,0x1449E18C+1
        defadr GC_DrawLine,0x140917BC+1
        defadr GUIObject_SetTitleType,0x14093534+1
        defadr GUIonMessage_SetItemDisabled,0x144DF9F4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150D4864+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x150D48EC+1
        defadr GUIObject_SoftKeys_Hide,0x144CB138+1
        defadr ListMenu_SetItemSecondLineText,0x142A8E24+1
        defadr ImageID_Get,0x1447947C+1
        defadr ImageID_Free,0x14410D58+1
        defadr FILEITEM_GetFname,0x142C7D74+1
        defadr FILEITEM_GetPath,0x142C7CA0+1
        defadr DispObject_SetRefreshTimer,0x1412E1BC+1
        defadr DispObject_KillRefreshTimer,0x1449F134+1
        defadr ImageID_GetIndirect,0x150D2C38+1
        defadr DispObject_SetLayerColor,0x140C6CA0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14129628+1
        defadr GUIonMessage_GetMsg,0x142C5CA4+1
        defadr ListMenu_DestroyItems,0x14280984+1
        defadr CoCreateInstance,0x1401106C+1
        defadr DispObject_SetAnimation,0x14E1B408+1
        defadr DisplayGC_AddRef,0x144CDAA4+1
        defadr TextObject_SetText,0x14183164+1
        defadr TextObject_SetFont,0x1449CD74+1
        defadr Audio_GetTags,0x157523B8+1
        defadr CreateYesNoQuestion,0x142CD924+1
        defadr YesNoQuestion_SetDescriptionText,0x14337444+1
        defadr YesNoQuestion_SetQuestionText,0x14337434+1
        defadr YesNoQuestion_SetIcon,0x14337428+1
        defadr MessageBox_NoIMAGE,0x14CE140C+1
        defadr w_chdir,0x104F943C+1
        defadr w_fopen,0x100A6E5C+1
        defadr w_fstat,0x100A6EA0+1
        defadr w_fwrite,0x100F2624+1
        defadr w_fread,0x100F2E7C+1
        defadr w_lseek,0x10589418+1
        defadr w_fclose,0x1013A908+1
        defadr w_mkdir,0x104F62FC+1
        defadr DISP_DESC_SetOnLayout,0x14295474+1
        defadr GUIObject_SoftKeys_Show,0x1412982C+1
        defadr FILEITEM_GetFextension,0x142C7EEC+1
        defadr wstrncmp,0x14325C10+1
        defadr Display_GetHeight,0x140C93BC+1
        defadr Display_GetWidth,0x140C93AC+1
        defadr GUIObject_SoftKeys_SetInfoText,0x141283F0+1
        
        defadr FSX_IsFileExists,0x14411678+1
        defadr CreatePalette,0x157089D0+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x1527FEA8+1
	defadr TextID_CreateIntegerID,0x1401F5BC+1
        
        defadr MessageBox_NoImage,0x14CE140C+1
        
        defadr Display_GetBrightness,0x14D35A70+1
        defadr GetBatteryState,0x1016A564+1
        defadr GetFreeBytesOnHeap,0x142188E8+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x14235D1C+1
        
        defadr Charging_GetState,0x141CE354+1
        defadr FlightMode_GetState,0x141B5508+1
        defadr GetOperatorName,0x143FBAF0+1
        
        defadr sscanf,0x101D3E90+1
        
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
        defadr get_mem,0x101CFE6C
        defadr get_bid,0x101CFE24
        defadr strcpy,0x14C0BAA0+1
        
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
        //defadr ProgressBar_SetDescriptionIconOffset,0x+1
        defadr ProgressBar_IsScrolling,0x140723C0+1
        //defadr YesNoQuestion_SetDescriptionIconOffset,0x+1
        defadr NOfMany_SetItemCount,0x144AA700+1
        defadr NOfMany_GetCheckedItem,0x144946B4+1
        defadr CreateStringInput,0x14062C90+1
        defadr StringInput_GetStringAndLen,0x14202700+1
        defadr StringInput_SetMode,0x142CD5A4+1
        defadr StringInput_SetActionOK,0x142CD43C+1
        defadr StringInput_SetActionBack,0x1408E9B8+1
        defadr StringInput_SetActionLongBack,0x142CD440+1
        defadr StringInput_SetStrinpText,0x1401CDA4+1
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
        defadr FILEITEM_GetContentType,0x142C7FF0+1
        defadr FILEITEM_SetContentType,0x142C82B0+1
        defadr GetFileLocation,0x1444000C+1
        defadr Volume_Set,0x1432EA7C+1
        defadr Volume_Get,0x1432FD48+1
        defadr FSX_MakeFullPath,0x141779BC+1
        defadr FSX_FreeFullPath,0x14336024+1
        defadr MakeFullPath,0x14298BE0+1
        defadr MessageBox_Animation,0x1585B1EC+1
        defadr PlaySystemSound_SendEvent,0x14FA9150+1
        defadr GetMemoryStickStatus,0x142CE30C+1
        
        defadr DispObject_GetGUI,0x142A8F2C+1
        defadr GUIObject_GetBook,0x140CAEC8+1

//------------------------------------------------------------------------------

        defadr MusicApp_PrevAction,0x14022A08+1
        defadr MusicApp_CancelAction,0x14F3B420+1
        
        defadr pg_MusicApplication_UnplugPHF__PreviousAction,0x153474EC+1
        defadr pg_MusicApplication_UnplugPHF__CancelAction,0x1534782C+1
        defadr pg_MusicApplication_UnplugPHF__ExitAction,0x14F15900+1
        
        EXTERN New_MusicApplication_Equalizer_EnterAction
        EXTERN New_MusicApplication_Equalizer_CancelAction
        
        EXTERN New_SetEqualizerGain

        RSEG PATCH_Equalizer_EnterAction
        DATA
        DCD New_MusicApplication_Equalizer_EnterAction
        
        RSEG PATCH_Equalizer_CancelAction
        DATA
        DCD New_MusicApplication_Equalizer_CancelAction
        
        RSEG PATCH_SetEqualizerGain
        CODE16
        PUSH    {R4-R6,LR}
        LDR     R3,=New_SetEqualizerGain
        BLX     R3
        MOV     R0, #1
        POP     {R4-R6,PC}
#endif
        END
