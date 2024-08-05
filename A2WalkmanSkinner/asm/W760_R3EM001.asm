//W760_R3EM001

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x11927744+1
        defadr memcpy,0x11927644+1
        defadr debug_printf,0x4BB3A365
        defadr snwprintf,0x10798B34+1
        defadr strstr,0x10798A70+1
        defadr strlen,0x10798964+1
        defadr strncpy,0x107989D4+1
        defadr wstrlen,0x10E01180+1
        defadr wstr2strn,0x10E012A0+1
        defadr wstrnupr,0x10E01250+1
        defadr wstrcpy,0x10E011C4+1
        defadr wstrncpy,0x10E011DC+1
        defadr wstrrchr,0x10E02504+1
        defadr wstrcmp,0x10E01194+1
        defadr wstrcmpi,0x10E025E4+1
        defadr str2wstr,0x10E02448+1
        defadr wstrcat,0x107991F4+1
        defadr _fopen,0x109F5840+1
        defadr fread,0x109F71D4+1
        defadr fclose,0x117A443C+1
        defadr fwrite,0x109F73A0+1
        defadr fstat,0x109F61A4+1
        defadr w_fopen,0x11330F6C+1
        defadr w_lseek,0x11AE3334+1
        defadr w_fread,0x11330F9C+1
        defadr w_fstat,0x11331024+1
        defadr w_fclose,0x11330FCC+1
        defadr w_diropen,0x4BB00354
        defadr w_chdir,0x4BB003AC
        defadr w_dirread,0x11AE39C4+1
        defadr w_dirclose,0x4BB0038C
        defadr List_DestroyElements,0x11B56FA4+1
        defadr List_Destroy,0x11B56CB8+1
        defadr List_Create,0x11B56C90+1
        defadr List_Get,0x11B56EB0+1
        defadr List_InsertLast,0x11B56E0C+1
        defadr List_GetCount,0x11B56E84+1
        defadr TextID_Create,0x10FFBF40+1
        defadr TextID_CreateIntegerID,0x10FFBD6C+1
        defadr TextID_Destroy,0x10FFC27C+1
        defadr TextID_GetLength,0x10FFC384+1
        defadr Disp_GetTextIDWidth,0x10A6AF58+1
        defadr CreateBook,0x10E89BAC+1
        defadr FindBook,0x10E87DE4+1
        defadr IsAudioPlayerBook,0x10D21FC0+1
        defadr BookObj_ReturnPage,0x10E89A74+1
        defadr BookObj_CallPage,0x10E899F0+1
        defadr BookObj_GotoPage,0x10E898BC+1
        defadr BookObj_GetBookID,0x10E8A318+1
        defadr BookObj_SetFocus,0x10E89E5C+1
        defadr FreeBook,0x10E8A22C+1
        defadr UI_Event,0x10E8894C+1
        defadr FreeAllBook,0x10EBEE98+1
        defadr CreateMessageBox,0x11AE85E0+1
        defadr BookObj_SetDisplayOrientation,0x10E8A350+1
        defadr BookObj_GetDisplayOrientation,0x10E8A3B4+1
        defadr GUIObject_SoftKeys_SetAction,0x108AE74C+1
        defadr GUIObject_SoftKeys_SetText,0x108AE7C4+1
        defadr GUIObject_SoftKeys_SetInfoText,0x108AE7B0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x108AE8E8+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x108AEAE4+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x108AE988+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x108AEA68+1
        defadr GUIObject_SoftKeys_Hide,0x108AEB04+1
        defadr GUIObject_SoftKeys_Show,0x108AEB10+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x108AEB1C+1
        defadr DispObject_SoftKeys_Hide,0x108AAC64+1
        defadr DispObject_SoftKeys_Show,0x108AAC9C+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10B90CAC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10B90C04+1
        defadr MediaPlayer_SoftKeys_SetText,0x10B90C4C+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x10B90CDC+1
        defadr DISP_DESC_SetName,0x10A6301C+1
        defadr DISP_DESC_SetSize,0x10A63020+1
        defadr DISP_DESC_SetOnCreate,0x10A63024+1
        defadr DISP_DESC_SetOnClose,0x10A63028+1
        defadr DISP_DESC_SetOnRedraw,0x10A6302C+1
        defadr DISP_DESC_SetOnRefresh,0x10A63030+1
        defadr DISP_DESC_SetOnKey,0x10A63034+1
        defadr DISP_DESC_SetOnLayout,0x10A63040+1
        defadr GUIObject_Create,0x10A6F95C+1
        defadr BookObj_AddGUIObject,0x10E89F3C+1
        defadr GUIObject_SetTitleType,0x10A6FF0C+1
        defadr GUIObject_SetTitleText,0x10A6FF28+1
        defadr GUIObject_SetStyle,0x10A6FD6C+1
        defadr GUIObject_GetStyle,0x10A6FD88+1
        defadr GUIObject_SetSecondRowTitleText,0x10A6FF44+1
        defadr GUIObject_Show,0x10A6FD14+1
        defadr GUIObject_Destroy,0x10A6FB20+1
        defadr GUIObject_GetDispObject,0x10A6FBAC+1
        defadr DispObject_SoftKeys_GetList,0x108ABBC0+1
        defadr DispObject_InvalidateRect,0x10A6653C+1
        defadr DispObject_SetLayerColor,0x10A68734+1
        defadr DispObject_SetAnimation,0x10A687EC+1
        defadr Display_GetWidth,0x11810F14+1
        defadr Display_GetHeight,0x11810F08+1
        defadr DispObject_SetBacklightMode,0x10A694D4+1
        defadr DispObject_SetBacklightTimeout,0x10A6950C+1
        defadr DispObject_GetGUI,0x10A65E20+1
        defadr DispObject_SetStyle,0x10A68BC8+1
        defadr DispObject_GetStyle,0x10A68E68+1
        defadr DispObject_SetRefreshTimer,0x10A65FA4+1
        defadr DispObject_KillRefreshTimer,0x10A66020+1
        defadr GUIObject_GetBook,0x10A6FBC0+1
        defadr CreateOneOfMany,0x11B12B94+1
        defadr OneOfMany_SetChecked,0x11B12D3C+1
        defadr OneOfMany_SetItemCount,0x11B12D20+1
        defadr OneOfMany_SetOnMessage,0x11B12D68+1
        defadr OneOfMany_GetSelected,0x11B12D4C+1
        defadr CreateListMenu,0x11B105D0+1
        defadr ListMenu_SetItemCount,0x11B107E4+1
        defadr ListMenu_SetItemStyle,0x11B10820+1
        defadr ListMenu_SetTexts,0x11B108FC+1
        defadr ListMenu_SetCursorToItem,0x11B107BC+1
        defadr ListMenu_SetHotkeyMode,0x11B10920+1
        defadr ListMenu_SetOnMessage,0x11B108F4+1
        defadr ListMenu_DestroyItems,0x11B10C3C+1
        defadr ListMenu_SetItemTextScroll,0x11B10EC4+1
        defadr ListMenu_GetSelectedItem,0x11B107D0+1
        defadr ListMenu_SetNoItemText,0x11B10974+1
        defadr ListMenu_SetItemSecondLineText,0x11B10B98+1
        defadr GUIonMessage_GetBook,0x11B11374+1
        defadr GUIonMessage_GetMsg,0x11B1136C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11B11390+1
        defadr GUIonMessage_SetMenuItemText,0x11B1139C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11B113CC+1
        defadr GUIonMessage_SetItemDisabled,0x11B11444+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11B113BC+1
        defadr SetFont,0x10A6A7CC+1
        defadr DrawString,0x10A69C0C+1
        defadr DrawRect,0x10A698C0+1
        defadr get_DisplayGC,0x10A6DB74+1
        defadr GetImageWidth,0x10A6AEA4+1
        defadr GetImageHeight,0x10A6AEB8+1
        defadr GC_PutChar,0x10A6E5AC+1
        defadr GC_SetPenColor,0x10A6E380+1
        defadr GC_SetBrushColor,0x10A6E458+1
        defadr GC_DrawLine,0x10A6EB00+1
        defadr GC_GetRect,0x10A6E1B4+1
        defadr GC_GetXX,0x10A6E4B0+1
        defadr GC_SetXX,0x10A6E4A4+1
        defadr GC_ValidateRect,0x10A6E164+1
        defadr GC_GetPenColor,0x10A6E3BC+1
        defadr Timer_Kill,0x10E86218+1
        defadr Timer_ReSet,0x10E861C0+1
        defadr Timer_Set,0x10E8618C+1
        defadr CreateTabMenuBar,0x1180E898+1
        defadr TabMenuBar_SetTabGui,0x1180E968+1
        defadr TabMenuBar_SetTabTitle,0x1180EA30+1
        defadr TabMenuBar_SetTabIcon,0x1180E9E8+1
        defadr TabMenuBar_SetTabCount,0x1180EAF0+1
        defadr TabMenuBar_SetFocusedTab,0x1180E94C+1
        defadr CreateStringInput,0x109342CC+1
        defadr StringInput_SetMode,0x10934B84+1
        defadr StringInput_SetFixedText,0x10934CC8+1
        defadr StringInput_SetMinLen,0x10934BEC+1
        defadr StringInput_SetMaxLen,0x10934C9C+1
        defadr StringInput_SetEnableEmptyText,0x10934D10+1
        defadr StringInput_SetActionOK,0x10934BE0+1
        defadr TextFeedbackWindow,0x1180FBF8+1
        defadr Feedback_SetTextExtended,0x11810068+1
        defadr Feedback_CloseAction,0x1180FFC8+1
        defadr FSX_MakeFullPath,0x109F8FE4+1
        defadr FSX_FreeFullPath,0x109F9050+1
        defadr FSX_IsFileExists,0x1188A9F4+1
        defadr FILEITEM_GetFname,0x1188FBBC+1
        defadr FILEITEM_GetPath,0x1188FC50+1
        defadr getFileExtention,0x109F8EB0+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x11B2D364+1
        defadr Sound_SetMessageAlert,0x10CEB740+1
        defadr Sound_SetAlarmsignal,0x109D3318+1
        defadr Sound_AddToContact,0x10BF13F8+1
        defadr OSE_GetShell,0x10EA6F4C+1
        defadr CoCreateInstance,0x107BC050+1
        defadr DisplayGC_AddRef,0x10A6DFAC+1
        defadr MetaData_GetTags,0x1188B00C+1
        defadr get_envp,0x10005C38+1
        defadr set_envp,0x10005C4C+1
        defadr Volume_Get,0x11A72594+1
        defadr Volume_Set,0x11A724C8+1
        defadr ImageID_Free,0x10847AA8+1
        defadr ImageID_GetIndirect,0x10841928+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10843910+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10843988+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10843A10+1

        defadr MusicApplication_PrevAction,0x10D22AAC+1
        defadr MusicApplication_CancelAction,0x10D23E10+1
        defadr MusicApplication_ShowMyMusic,0x10D23E30+1
        defadr MusicApplication_Minimize,0x10D23DDC+1
        defadr MusicApplication_Keyboard,0x10D24134+1

        defadr pg_MusicApplication_PreviousEvent,0x10D2246C+1
        defadr pg_MusicApplication_CancelEvent,0x10D224CC+1
        defadr pg_MusicApplication_ExitEvent,0x10D225C4+1

        defadr Music_Gui_NowPlaying_OnCreate,0x10B8D68C+1
        defadr Music_Gui_NowPlaying_OnClose,0x10B8D864+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x10B8D8EC+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x10D24738+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x10D2453C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x10D242F8+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x10D22604+1

        defadr FeedbackTicker_OnRedraw,0x11AE9414+1

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

        RSEG PATCH_UPDATE_ORIENTATION_HOOK
        CODE16
	LDR	R3, =Patch_ORIENTATION
	BX	R3

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
	LDR	R3, =0x10E8A3AA+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG    PATCH_Feedback_DrawCoverArt
        DATA
        DCD     Feedback_DrawCoverArt

        RSEG PATCH_Feedback_RemoveIcon
        CODE16
        ADD     SP, #0x20
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
        LDR	R3, =0x10D23466+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_Walkman_GUI
	CODE16
	LDR     R3, =_walkman_gui
	BX      R3

        RSEG  CODE
        CODE16
_walkman_gui:
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
	LDR     R3, =0x10D22A60+1
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
	LDR     R3, =0x10D22A94+1
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
