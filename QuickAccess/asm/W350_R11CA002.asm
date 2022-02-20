//W350_R11CA002


defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr memset,0x20105B58
        defadr debug_printf,0x2086B1D0+1
        defadr snwprintf,0x20380BC4+1
        defadr _fopen,0x20C86CB4+1
        defadr fread,0x20C88340+1
        defadr fclose,0x20C880EC+1
        defadr fwrite,0x20C8850C+1
        defadr fstat,0x20C875A0+1
        defadr w_diropen,0x20D76378+1
        defadr w_chdir,0x20D7458C+1
        defadr w_dirread,0x20F7184C+1
        defadr w_fstat,0x2067F638+1
        defadr w_dirclose,0x20D76628+1
        defadr set_envp,0x20144BD4+1
        defadr get_envp,0x20144BC0+1
        defadr BookObj_GetSession,0x210556B4+1
        defadr TextID_GetString,0x210EC274+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x20C424C4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x20C4252C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x20C425DC+1
        defadr FSX_IsFileExists,0x20CC7C34+1
        defadr get_DisplayGC,0x21101BF4+1
        defadr GC_PutChar,0x21102714+1
        defadr DrawRect,0x210FCE28+1
        defadr GetImageHeight,0x210FE238+1
        defadr GetImageWidth,0x210FE224+1
        defadr SetFont,0x210FDBA0+1
        defadr DrawString,0x210FD128+1
        defadr wstrcpy,0x20381198+1
        defadr TextID_Destroy,0x210EBF00+1
        defadr DispObject_GetGUI,0x210F9E84+1
        defadr FindBook,0x21053808+1
        defadr TextID_CreateIntegerID,0x210EBAD0+1
        defadr TextID_Copy,0x210EBE10+1
        defadr Display_GetWidth,0x211170B4+1
        defadr MainDisplay_GetTopBook,0x210548A4+1
        defadr GUIObject_GetDispObject,0x21103F38+1
        defadr Display_GetHeight,0x211170A8+1
        defadr DispObject_WindowSetSize,0x210FB560+1
        defadr DispObject_SetLayerColor,0x210FC31C+1
        defadr DispObject_SetAnimation,0x210FC3D0+1
        defadr TextID_Create,0x210EBC80+1
        defadr TextID_GetWString,0x210EC13C+1
        defadr CreateMessageBox,0x21060634+1
        defadr GUIObject_SoftKeys_SetAction,0x21120904+1
        defadr GUIObject_SoftKeys_SetVisible,0x211209CC+1
        defadr GUIObject_SoftKeys_SetText,0x2112097C+1
        defadr GUIObject_SoftKeys_SetEnable,0x21120A38+1
        defadr GUIObject_GetBook,0x21103F4C+1

        defadr ConnectionManager_Connection_GetState,0x20F85F38+1
        defadr iconidname2id,0x20A453CC+1
        defadr ImageID_Free,0x20C3E70C+1

        defadr Find_StandbyBook,0x21068628+1
        defadr BookObj_SetFocus,0x210552FC+1
        defadr BookObj_GetBookID,0x21055714+1
        defadr UI_Event_toBookID,0x21053BF4+1
        defadr UI_Event_toBookIDwData,0x21053C08+1
        defadr UI_Event,0x21053B9C+1
        defadr MessageBox,0x210605E8+1
        defadr FreeBook,0x2105566C+1
        defadr CreateBook,0x2105506C+1
        defadr BookObj_ReturnPage,0x21054F50+1
        defadr BookObj_CallPage,0x21054EE8+1
        defadr BookObj_GotoPage,0x21054DE8+1
        defadr Shortcut_Get_MenuItemIconID,0x21125A34+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x21125930+1
        defadr Shortcut_Get_MenuItemName,0x2112CA08+1
        defadr MenuBook_Desktop,0x211257B8+1
        defadr BookObj_SoftKeys_SetAction,0x2111B9A0+1
        defadr BookObj_SoftKeys_SetText,0x2111B9D8+1

        defadr wstrlen,0x20C48D0C+1
        defadr wstrncmp,0x20381210+1
        defadr wstrcmpi,0x20C4A130+1
        defadr wstrcmp,0x20C48D20+1
        defadr wstrncpy,0x20C48D68+1
        defadr wstrrchr,0x20381298+1
        defadr str2wstr,0x20C49FD4+1
        defadr strlen,0x20380A04+1
        defadr strstr,0x20380B0C+1
        defadr strcpy,0x203809D0+1
        defadr strcmp,0x203809A8+1
        defadr strncmp,0x20380A40+1

        defadr GUIonMessage_GetMsg,0x210C3CA0+1
        defadr GUIonMessage_GetBook,0x210C3CA8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x210C3CC4+1
        defadr GUIonMessage_SetMenuItemText,0x210C3CD0+1
        defadr GUIonMessage_SetMenuItemIcon,0x210C3D48+1
        defadr GUIonMessage_SetItemDisabled,0x210C3D6C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x210C3CF0+1
        defadr GUIonMessage_GetSelectedItem,0x210C3CAC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x210C3D00+1
        defadr GUIonMessage_SetLineSeparator,0x210C3D84+1
        defadr GetFreeBytesOnHeap,0x20DACCB0+1
        defadr CreateListMenu,0x210C2F7C+1
        defadr ListMenu_SetOnMessage,0x210C32BC+1
        defadr ListMenu_SetItemCount,0x210C3190+1
        defadr ListMenu_SetCursorToItem,0x210C3168+1
        defadr ListMenu_GetSelectedItem,0x210C317C+1
        defadr ListMenu_SetItemTextScroll,0x210C38F0+1
        defadr ListMenu_SetItemStyle,0x210C31CC+1
        defadr ListMenu_SetHotkeyMode,0x210C32E8+1
        defadr GUIObject_TabTitleRemove,0x210C3900+1
        defadr GUIObject_SetTitleType,0x21104658+1
        defadr GUIObject_SetSecondRowTitleText,0x21104690+1
        defadr GUIObject_Destroy,0x21103ECC+1
        defadr GUIObject_SetStyle,0x21104188+1

        defadr DispObject_GetOnKey,0x210F63A0+1
        defadr DispObject_GetDESC,0x20EEC090+1
        defadr DISP_DESC_SetOnKey,0x210F62D0+1
        defadr ListMenu_SetNoItemText,0x210C3360+1
        defadr GUIObject_SetTitleText,0x21104674+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x20BF1B54+1
        defadr GUIObject_Show,0x21104138+1

        defadr GetSilent,0x20DB5DA0+1
        defadr SetSilent,0x20DB5D80+1
        defadr REQUEST_SETTING_SILENCE_SET,0x2108AD64+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x2108B5B8+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x2108B48C+1
        defadr Bluetooth_GetState,0x20B8D42C+1
        defadr Bluetooth_SetState,0x20B8D468+1
        defadr Bluetooth_isBusy,0x20B8D520+1      
        defadr Lock_Keyboard,0x21132608+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x2106B318+1
        defadr REQUEST_SYSTEM_RESTART,0x2106B328+1
        defadr Shortcut_Run,0x2112DDE8+1
        defadr FlightMode_GetState,0x2107AA50+1
        defadr FlightMode_SetState,0x21066F60+1

        defadr CreateYesNoQuestion,0x21114964+1
        defadr YesNoQuestion_SetQuestionText,0x21114CCC+1
        defadr YesNoQuestion_SetDescriptionText,0x21114CDC+1
        defadr YesNoQuestion_SetIcon,0x21114CFC+1

        defadr hz,0x20B89938+1

        EXTERN  New_QuickAccessMenu_EnterEvent
                
        RSEG    PATCH_QuickAccessMenu_EnterEvent
        DATA
        DCD     New_QuickAccessMenu_EnterEvent

        END
