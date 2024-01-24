//W900_R5BC004

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x2062C09C+1
        defadr memfree,0x2062D0CC+1
        defadr memset,0x211E97E4+1
        defadr debug_printf,0x211A8D30+1
        defadr snwprintf,0x211EAA10+1
        defadr _fopen,0x207AA90C+1
        defadr fread,0x207ABED0+1
        defadr fclose,0x207ABB94+1
        defadr fwrite,0x207AC154+1
        defadr fstat,0x207AB1D0+1
        defadr set_envp,0x200FE506+1
        defadr get_envp,0x200FE4F2+1
        defadr TextID_Create,0x204C9F04+1
        defadr TextID_GetString,0x204CAAF4+1
        defadr TextID_GetWString,0x204CA2B0+1

        defadr GUIonMessage_GetMsg,0x20B987A8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x20B987D4+1
        defadr GUIonMessage_SetMenuItemText,0x20B987E4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x20B98814+1
        defadr GUIonMessage_SetMenuItemIcon,0x20B98824+1
        defadr GUIonMessage_SetItemDisabled,0x20B9887C+1
        defadr GUIonMessage_SetMenuItemInfoText,0x20B987F4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x20B98804+1
        defadr GUIonMessage_SetLineSeparator,0x20B98894+1
        defadr ConnectionManager_Connection_GetState,0x20B334B0+1
        defadr GetSilent,0x2063599C+1
        defadr Bluetooth_GetState,0x20794294+1
        defadr Bluetooth_SetState,0x207942CC+1
        defadr Bluetooth_isBusy,0x20794318+1
        defadr FlightMode_GetState,0x20B769A8+1
        defadr FlightMode_SetState,0x20B769BC+1
        defadr IrDa_GetState,0x2071C2D4+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x208447F4+1
        defadr REQUEST_SYSTEM_RESTART,0x20E31E58+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x20E31E34+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x208446C0+1
        defadr REQUEST_SETTING_SILENCE_SET,0x20843E94+1
        defadr CreateYesNoQuestion,0x20BBF90C+1
        defadr YesNoQuestion_SetQuestionText,0x20BBFC94+1
        defadr YesNoQuestion_SetIcon,0x20BBFCC0+1
        defadr Lock_Keyboard,0x20B7D6B4+1
        defadr Shortcut_Run,0x2083A238+1
        defadr Find_StandbyBook,0x20474ED0+1
        defadr FreeBook,0x20467D84+1
        defadr BookObj_SetFocus,0x204679B8+1
        defadr BookObj_GetSession,0x20467DBC+1
        defadr UI_Event,0x2071795C+1
        defadr GetFreeBytesOnHeap,0x2062E34C+1
        defadr CreateListMenu,0x20B97800+1
        defadr ListMenu_SetItemCount,0x20B97A28+1
        defadr ListMenu_GetSelectedItem,0x20B97A10+1
        defadr ListMenu_SetCursorToItem,0x20B979FC+1
        defadr ListMenu_SetHotkeyMode,0x20B97B98+1
        defadr ListMenu_SetOnMessage,0x20B97B6C+1
        defadr ListMenu_SetItemStyle,0x20B97A74+1
        defadr GUIObject_SetStyle,0x20BBC704+1
        defadr GUIObject_SetTitleType,0x20BBC798+1
        defadr GUIObject_SetTitleText,0x20BBC7BC+1
        defadr GUIObject_SetSecondRowTitleText,0x20BBC7D8+1
        defadr GUIObject_SoftKeys_SetAction,0x20BC4E30+1
        defadr GUIObject_Show,0x20BBC6A4+1
        defadr GUIObject_Destroy,0x20BBC278+1
        defadr hz,0x205D9078+1


        EXTERN  New_QuickAccessMenu_EnterEvent

        RSEG    PATCH_QuickAccessMenu_EnterEvent
        DATA
        DCD     New_QuickAccessMenu_EnterEvent

        END
