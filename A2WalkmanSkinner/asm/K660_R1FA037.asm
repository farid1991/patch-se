//K660_R1FA037

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x1009ED00
        defadr memfree,0x1009ED28
        defadr memset,0x10BCB304+1
        defadr memcpy,0x10BCB204+1
        defadr debug_printf,0x2A20E3E1
        defadr snwprintf,0x105544C4+1
        defadr get_bid,0x100F4138
        defadr current_process,0x100F4100
        defadr get_envp,0x100A9A14+1
        defadr set_envp,0x100A9A28+1
        defadr OSE_GetShell,0x111E172C+1

        defadr _fopen,0x10FDD320+1
        defadr fread,0x10FDEA64+1
        defadr fclose,0x115B0250+1
        defadr fwrite,0x10FDEC30+1
        defadr fstat,0x10FDDC18+1
        defadr w_fopen,0x107E9F1C+1
        defadr w_fread,0x107E9F4C+1
        defadr w_fclose,0x107E9F7C+1
        defadr w_fstat,0x107E9FD4+1
        defadr w_lseek,0x1142B740+1
        defadr w_diropen,0x1009EAD0
        defadr w_chdir,0x1009EB28
        defadr w_dirread,0x1142BDD0+1
        defadr w_dirclose,0x1009EB08

        defadr strlen,0x105542F4+1
        defadr strstr,0x10554400+1
        defadr strncpy,0x10554364+1
        defadr str2wstr,0x10FCFA64+1
        defadr wstrcat,0x10FCE824+1
        defadr wstrlen,0x10FCE79C+1
        defadr wstr2strn,0x10FCE8BC+1
        defadr wstrnupr,0x10FCE86C+1
        defadr wstrcpy,0x10FCE7E0+1+1
        defadr wstrrchr,0x10FCFB20+1
        defadr wstrcmp,0x10FCE7B0+1

        defadr FSX_MakeFullPath,0x10FE0794+1
        defadr FSX_FreeFullPath,0x10FE0800+1
        defadr FSX_IsFileExists,0x110287EC+1
        defadr FILEITEM_GetFname,0x1102D434+1
        defadr FILEITEM_GetPath,0x1102D4C8+1
        defadr getFileExtention,0x10FE0660+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10FC3CDC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10FC3D54+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10FC3DDC+1
        defadr ImageID_Free,0x10FC7DBC+1
        defadr ImageID_GetIndirect,0x10FC7804+1

        defadr Display_GetWidth,0x116B83EC+1
        defadr Display_GetHeight,0x116B83E0+1

        defadr TextID_Create,0x11686620+1
        defadr TextID_CreateIntegerID,0x11686460+1
        defadr TextID_GetLength,0x1168698C+1
        defadr TextID_Destroy,0x116868B8+1
        defadr Disp_GetTextIDWidth,0x116A2904+1

        defadr Volume_Set,0x111BA83C+1
        defadr Volume_Get,0x111BA908+1
        defadr MetaData_GetTags,0x11028DB4+1
        defadr MetaData_GetCover,0x115BD7CC+1
        
        defadr DISP_DESC_SetName,0x116993F0+1
        defadr DISP_DESC_SetSize,0x116993F4+1
        defadr DISP_DESC_SetOnCreate,0x116993F8+1
        defadr DISP_DESC_SetOnClose,0x116993FC+1
        defadr DISP_DESC_SetOnRedraw,0x11699400+1
        defadr DISP_DESC_SetOnKey,0x11699408+1
        defadr DISP_DESC_SetOnLayout,0x11699414+1

        defadr BookObj_AddGUIObject,0x11605F5C+1
        defadr GUIObject_Create,0x116A8B54+1
        defadr GUIObject_SetStyle,0x116A8E98+1
        defadr GUIObject_GetStyle,0x116A8EC4+1
        defadr GUIObject_SetTitleType,0x116A9350+1
        defadr GUIObject_SetTitleText,0x116A936C+1
        defadr GUIObject_SetSecondRowTitleText,0x116A9388+1
        defadr GUIObject_Destroy,0x116A8C44+1
        defadr GUIObject_Show,0x116A8E40+1

        defadr GUIObject_GetDispObject,0x116A8CB4+1
        defadr DispObject_GetGUI,0x1169DE08+1
        defadr GUIObject_GetBook,0x116A8CC8+1
        defadr DispObject_SetStyle,0x116A081C+1
        defadr DispObject_GetStyle,0x116A09AC+1
        defadr DispObject_SetLayerColor,0x116A03BC+1
        defadr DispObject_InvalidateRect,0x1169E514+1
        defadr DispObject_SetAnimation,0x116A0474+1
        defadr DispObject_SetBacklightMode,0x116A1034+1

        defadr SetFont,0x116A229C+1
        defadr DrawString,0x116A1724+1
        defadr DrawRect,0x116A13E4+1
        defadr GetImageWidth,0x116A2868+1
        defadr GetImageHeight,0x116A287C+1
        defadr get_DisplayGC,0x116A6380+1
        defadr GC_PutChar,0x116A6DC8+1
        defadr GC_DrawLine,0x116A7658+1
        defadr GC_DrawImage,0x116A15D8+1
        defadr GC_GetPenColor,0x116A6BD4+1
        defadr GC_SetPenColor,0x116A6B98+1
        defadr GC_SetBrushColor,0x116A6C74+1
        defadr GC_GetXX,0x116A6CCC+1
        defadr GC_SetXX,0x116A6CC0+1
        defadr GC_GetRect,0x116A69C8+1
        defadr GC_ValidateRect,0x116A6978+1

        defadr GUIObject_SoftKeys_Hide,0x116C2A1C+1
        defadr GUIObject_SoftKeys_Show,0x116C2A28+1
        defadr GUIObject_SoftKeys_SetAction,0x116C2650+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x116C288C+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x116C29FC+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x116C27EC+1
        defadr GUIObject_SoftKeys_SetInfoText,0x116C26B4+1
        defadr GUIObject_SoftKeys_SetText,0x116C26C8+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x116C297C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x116C2A34+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x116C2A40+1
        defadr DispObject_SoftKeys_Show,0x116BEDBC+1
        defadr DispObject_SoftKeys_Hide,0x116BED90+1
        defadr DispObject_SoftKeys_GetList,0x116BFCA8+1
        
        defadr CreateListMenu,0x1165A538+1
        defadr ListMenu_SetItemCount,0x1165A768+1
        defadr ListMenu_SetHotkeyMode,0x1165A8A4+1
        defadr ListMenu_SetOnMessage,0x1165A878+1
        defadr ListMenu_SetTexts,0x1165A880+1
        defadr ListMenu_SetCursorToItem,0x1165A740+1
        defadr ListMenu_SetItemStyle,0x1165A7A4+1
        defadr ListMenu_SetItemTextScroll,0x1165AEA8+1
        defadr ListMenu_SetItemSecondLineText,0x1165AB50+1
        defadr ListMenu_GetSelectedItem,0x1165A754+1
        defadr ListMenu_DestroyItems,0x1165AC2C+1
        defadr ListMenu_SetNoItemText,0x1165A8F8+1

        defadr GUIonMessage_GetBook,0x1165B248+1
        defadr GUIonMessage_GetMsg,0x1165B240+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1165B264+1
        defadr GUIonMessage_SetMenuItemText,0x1165B270+1
        defadr GUIonMessage_SetItemDisabled,0x1165B310+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x1165B290+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1165B2A0+1

        defadr CreateOneOfMany,0x1165C89C+1
        defadr OneOfMany_SetItemCount,0x1165CA48+1
        defadr OneOfMany_SetOnMessage,0x1165CA90+1
        defadr OneOfMany_SetChecked,0x1165CA64+1
        defadr OneOfMany_GetSelected,0x1165CA74+1

        defadr CreateTabMenuBar,0x116B5E04+1
        defadr TabMenuBar_SetTabGui,0x116B5ED4+1
        defadr TabMenuBar_SetTabTitle,0x116B5F9C+1
        defadr TabMenuBar_SetTabIcon,0x116B5F54+1
        defadr TabMenuBar_SetTabCount,0x116B601C+1
        defadr TabMenuBar_SetFocusedTab,0x116B5EB8+1

        defadr CreateStringInput,0x11638390+1
        defadr StringInput_SetMode,0x11638C30+1
        defadr StringInput_SetFixedText,0x11638D68+1
        defadr StringInput_SetMinLen,0x11638C8C+1
        defadr StringInput_SetMaxLen,0x11638D3C+1
        defadr StringInput_SetEnableEmptyText,0x11638DB0+1
        defadr StringInput_SetActionOK,0x11638C80+1
        
        defadr TextFeedbackWindow,0x116B725C+1
        defadr Feedback_SetTextExtended,0x116B76C8+1
        defadr Feedback_CloseAction,0x116B762C+1

        defadr List_DestroyElements,0x1142C828+1
        defadr List_Destroy,0x1142C53C+1
        defadr List_Create,0x1142C514+1
        defadr List_InsertLast,0x1142C690+1
        defadr List_Get,0x1142C734+1
        defadr List_GetCount,0x1142C708+1
        
        defadr Timer_ReSet,0x116027FC+1
        defadr Timer_Set,0x116027C8+1
        defadr Timer_Kill,0x11602854+1

        defadr FreeAllBook,0x1149555C+1
        defadr CreateBook,0x11605C08+1
        defadr FreeBook,0x11606214+1
        defadr FindBook,0x11603CE0+1
        defadr UI_Event,0x11604A50+1
        defadr BookObj_GetBookID,0x116062C0+1
        defadr BookObj_GotoPage,0x11605980+1
        defadr BookObj_CallPage,0x11605A80+1
        defadr BookObj_ReturnPage,0x11605AE8+1
        defadr BookObj_SetFocus,0x11605EA8+1
        defadr BookObj_SetDisplayOrientation,0x116062F8+1
        defadr BookObj_GetDisplayOrientation,0x11606360+1
        defadr IsAudioPlayerBook,0x115BA47C+1
        defadr CreateMessageBox,0x1160B950+1
        
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x117A0ED4+1
        defadr Sound_SetMessageAlert,0x1127BC6C+1
        defadr Sound_SetAlarmsignal,0x10F356D4+1
        defadr Sound_AddToContact,0x10F5518C+1
        
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x115C0460+1
        defadr MediaPlayer_SoftKeys_SetAction,0x115C03B8+1
        defadr MediaPlayer_SoftKeys_SetText,0x115C0400+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x115C0490+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x115C0490+1

        defadr MusicApplication_PrevAction,0x115BACB4+1
        defadr MusicApplication_CancelAction,0x115BBEB0+1
        defadr MusicApplication_ShowMyMusic,0x115BBED0+1
        defadr MusicApplication_Minimize,0x115BBE84+1
        defadr MusicApplication_Keyboard,0x115BC1A8+1
        defadr MusicApplication_GetFilename,0x115B9FC0+1
        defadr MusicApplication_GetFocusedItem,0x115B9F80+1
        defadr MusicApplication_SetSettings,0x115BA0E8+1

        defadr pg_MusicApplication_PreviousEvent,0x115BA6E8+1
        defadr pg_MusicApplication_CancelEvent,0x115BA748+1
        defadr pg_MusicApplication_ExitEvent,0x115BA7B4+1

        defadr Music_Gui_NowPlaying_OnCreate,0x115BDC20+1
        defadr Music_Gui_NowPlaying_OnClose,0x115BDE24+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x115BDEB4+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x115BC65C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x115BC4D8+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x115BC31C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x115BA80C+1

        defadr FeedbackTicker_OnRedraw,0x1160C620+1

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

        RSEG PATCH_UPDATE_ORIENTATION_HOOK
        CODE16
	LDR	r3, =Patch_ORIENTATION
	BX	r3

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
	LDR	r3, =0x11606352+1
	BX	r3

//------------------------------------------------------------------------------

        RSEG    PATCH_Feedback_DrawCoverArt
        DATA
        DCD     Feedback_DrawCoverArt

        RSEG PATCH_Feedback_RemoveIcon
        CODE16
	POP     {R4-R7,PC}

//------------------------------------------------------------------------------

 	RSEG PATCH_Walkman_SoftKeys
	CODE16
	LDR     R3, =AddNew_SoftKeys
	BX      R3

        RSEG  CODE
        CODE16
AddNew_SoftKeys:
        LDR     R0, [R4,#0x1C]
        ADD     R2, R7, #0
        MOV     R1, #7
	LDR	R3, =MediaPlayer_SoftKeys_AddHelpStr
	BLX	R3
        ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR	R3, =0x115BB6FA+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_Walkman_GUI
	CODE16
	LDR     R3, =_walkman_gui
	BX      R3

        RSEG  CODE
        CODE16
_walkman_gui:
        BL	Set_WALKMAN_GUI_STYLE
        ADD     R0, R7, #0
        LDR	R3, =GUIObject_SoftKeys_RemoveBackground
	BLX	R3
	ADD	R0, R7, #0
	POP	{R1-R7,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_StereoWidening
	CODE16
	NOP
        
        RSEG PATCH_UPDATE_SHUFFLE_HOOK
	CODE16
	LDR	R3, =fix_shuffle
	BX	R3

        RSEG PATCH_UPDATE_LOOP_HOOK
	CODE16
	LDR	R3, =fix_loop
	BX	R3

	RSEG  CODE
        CODE16
fix_shuffle:
        MOV     R1, #1
        B       next_
fix_loop:
        LDR     R0, [R5,#0]
        LDR	R3, =0x115C01A0+1
	BLX	R3
        MOV     R1, #0
next_:
        ADD     R0, R4, #0
        LDR	R3, =MusicApplication_SetSettings
	BLX	R3
        BL      RefreshScreen
        POP     {R4,R5,PC}

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
