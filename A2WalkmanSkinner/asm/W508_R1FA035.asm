//W508_R1FA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA30DE8
        defadr memfree,0x4BA30E10
        defadr memset,0x14092910+1
        defadr memcpy,0x14044020+1
        defadr debug_printf,0x14C39CD0
        defadr strstr,0x141EB45C+1
        defadr strlen,0x140922D8+1
        defadr strncpy,0x144C6004+1
        defadr current_process,0x101EC87C
        defadr get_bid,0x101EC8B4
        defadr set_envp,0x101F3448+1
        defadr get_envp,0x101F3434+1
        defadr FSX_FreeFullPath,0x1430AF3C+1
        defadr _fopen,0x1421A92C+1
        defadr fwrite,0x14572374+1
        defadr fclose,0x1410E040+1
        defadr fread,0x14310608+1
        defadr w_fopen,0x1009302C+1
        defadr w_lseek,0x142CDD90+1
        defadr w_fread,0x10177ABC+1
        defadr w_fclose,0x10149D2C+1
        defadr w_diropen,0x4BA30BB8
        defadr w_chdir,0x4BA80C30
        defadr w_dirread,0x143AD8EC+1
        defadr w_fstat,0x10177468+1
        defadr w_dirclose,0x4BA80C10
        defadr CoCreateInstance,0x14150FB8+1
        defadr TextObject_SetText,0x14225564+1
        defadr TextObject_SetFont,0x1419C6D0+1
        defadr get_DisplayGC,0x14049D50+1
        defadr DisplayGC_AddRef,0x1419BDB8+1
        defadr TextID_Copy,0x142264CC+1
        defadr TextID_GetString,0x142262BC+1
        defadr TextID_GetWString,0x14225E3C+1
        defadr TextID_Create,0x14226B70+1
        defadr RichTextLayout_GetTextWidth,0x1433A98C+1
        defadr TextID_Destroy,0x142261D0+1
        defadr DrawRect,0x141158F4+1
        defadr ListMenu_DestroyItems,0x144318D0+1
        defadr ListMenu_SetItemCount,0x1421144C+1
        defadr ListMenu_GetSelectedItem,0x14542708+1
        defadr ListMenu_SetCursorToItem,0x14365EBC+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E1C8+1
        defadr ListMenu_SetItemSecondLineText,0x142E6374+1
        defadr OneOfMany_GetSelected,0x1451EC9C+1
        defadr GUIObject_Destroy,0x14221158+1
        defadr CreateOneOfMany,0x141BD674+1
        defadr GUIObject_SetTitleText,0x142E6810+1
        defadr OneOfMany_SetTexts,0x141C1F1C+1
        defadr OneOfMany_SetChecked,0x142889B4+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E17C+1
        defadr GUIObject_Show,0x14469D18+1
        defadr GC_GetRect,0x142E9A94+1
        defadr GC_GetXX,0x140EF134+1
        defadr GC_SetXX,0x1415CBC4+1
        defadr snwprintf,0x142C75F0+1
        defadr GC_GetPenColor,0x140FECE4+1
        defadr GC_SetPenColor,0x14049DB0+1
        defadr GC_DrawLine,0x1433B55C+1
        defadr DispObject_InvalidateRect,0x1404A6A0+1
        defadr DISP_DESC_SetName,0x1430C188+1
        defadr DISP_DESC_SetSize,0x1430C184+1
        defadr DISP_DESC_SetOnCreate,0x1430C104+1
        defadr DISP_DESC_SetOnClose,0x1430C18C+1
        defadr DISP_DESC_SetOnRedraw,0x1430C180+1
        defadr DISP_DESC_SetOnKey,0x1430BC7C+1
        defadr DISP_DESC_SetOnLayout,0x1430BDA0+1
        defadr DISP_DESC_SetOnRefresh,0x1430BC80+1
        defadr GUIObject_GetDispObject,0x14048B1C+1
        defadr GUIObject_Create,0x14469D60+1
        defadr BookObj_AddGUIObject,0x1422119C+1
        defadr GUIObject_SetTitleType,0x143BD238+1
        defadr GUIObject_SoftKeys_SetText,0x1412B034+1
        defadr GUIObject_SoftKeys_Show,0x14139C14+1
        defadr GUIObject_SoftKeys_Hide,0x1422173C+1
        defadr FreeBook,0x14366418+1
        defadr lseek,0x143101E8+1
        defadr ImageID_GetIndirect,0x15090404+1
        defadr MetaData_GetTags,0x14EC6C24+1
        defadr wstrlen,0x14311500+1
        defadr fstat,0x1435BA9C+1
        defadr wstrrchr,0x1409B4A4+1
        defadr wstrcat,0x1435AFF0+1
        defadr wstr2strn,0x144C7BE8+1
        defadr str2wstr,0x141604B4+1
        defadr wstrcpy,0x14310568+1
        defadr wstrncpy,0x14359CB0+1
        defadr TextID_GetLength,0x142255FC+1
        defadr Timer_ReSet,0x142DAF34+1
        defadr Timer_Set,0x14505680+1
        defadr Timer_Kill,0x142DAED4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14ED5D30+1
        defadr ImageID_Free,0x144BF648+1
        defadr FSX_IsFileExists,0x144BFCC0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E40DE0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15092030+1
        defadr Volume_Get,0x1407A4B4+1
        defadr Display_GetWidth,0x142E9D78+1
        defadr Display_GetHeight,0x142E9D88+1
        defadr GUIObject_SetBacklightTimeout,0x1400C1BC+1
        defadr DispObject_SetBacklightMode,0x1400B9AC+1
        defadr DispObject_SetRefreshTimer,0x14114AAC+1
        defadr DispObject_KillRefreshTimer,0x1411468C+1
        defadr DispObject_SetThemeImage,0x14027A18+1
        defadr DispObject_SetLayerColor,0x142E8110+1
        defadr Volume_Set,0x1434309C+1
        defadr CreateMessageBox,0x14EBC290+1
        defadr BookObj_Hide,0x1422135C+1
        defadr BookObj_ReturnPage,0x14247260+1
        defadr GUIObject_SetStyle,0x142439D8+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EBD40+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x14F08DC8+1
        defadr DispObject_SetAnimation,0x14E7EC30+1
        defadr FILEITEM_GetPath,0x144DD638+1
        defadr FILEITEM_GetFname,0x144DD63C+1
        defadr FSX_MakeFullPath,0x1435A8D4+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14241EC0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1412B348+1
        defadr GUIonMessage_GetMsg,0x1412CC2C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CD24+1
        defadr GUIonMessage_SetItemDisabled,0x14246CC4+1
        defadr GUIonMessage_SetMenuItemText,0x14540388+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453FA40+1
        defadr GUIonMessage_GetBook,0x1412CA38+1
        defadr CreateListMenu,0x142211A8+1
        defadr ListMenu_SetOnMessage,0x143E9E50+1
        defadr ListMenu_SetItemStyle,0x14365B90+1
        defadr CreateYesNoQuestion,0x143F2514+1
        defadr YesNoQuestion_SetDescriptionText,0x14074A00+1
        defadr YesNoQuestion_SetQuestionText,0x140749F0+1
        defadr YesNoQuestion_SetIcon,0x14EEF27C+1
        defadr CreateBook,0x1446A50C+1
        defadr BookObj_GotoPage,0x14027124+1
        defadr BookObj_SetFocus,0x14221660+1
        defadr DispObject_GetGUI,0x140B8700+1
        defadr GUIObject_GetBook,0x1419E1BC+1
        defadr Display_GetFocusedDispObject,0x1419D6A8+1
        defadr DispObject_GetName,0x1419E428+1
        defadr FindBook,0x143111F8+1
        defadr OneOfMany_SetItemCount,0x14F8421C+1
        defadr OneOfMany_SetOnMessage,0x14F84844+1
        defadr BookObj_CallPage,0x14247168+1
        defadr wstrnupr,0x14217614+1
        defadr wstrcmp,0x14310E1C+1
        defadr getFileExtention,0x14359988+1
        defadr GC_SetBrushColor,0x14049DF8+1
        defadr GC_ValidateRect,0x14115AE0+1
        defadr BookObj_GetDisplayOrientation,0x1412ACB0+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x140EF634+1
        defadr BookObj_SetDisplayOrientation,0x14366840+1
        defadr TextID_CreateIntegerID,0x1452561C+1
        defadr ListMenu_SetHotkeyMode,0x14365ED0+1
        defadr ListMenu_SetItemTextScroll,0x14541A0C+1
        defadr GUIObject_GetStyle,0x14048AF4+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x14139C90+1
        defadr DispObject_SoftKeys_GetList,0x1419DE54+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x150DC7FC+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14FC395C+1
        defadr TabMenuBar_SetTabGui,0x142F660C+1
        defadr TabMenuBar_SetTabTitle,0x143BDDFC+1
        defadr TabMenuBar_SetTabIcon,0x143BE014+1
        defadr CreateTabMenuBar,0x142445B4+1
        defadr TabMenuBar_SetTabCount,0x142AA138+1
        defadr TabMenuBar_SetFocusedTab,0x142F6240+1
        defadr CreateStringInput,0x144E4F48+1
        defadr StringInput_SetMode,0x1437F368+1
        defadr StringInput_SetText,0x1501B2A0+1
        defadr StringInput_SetFixedText,0x1501B8F8+1
        defadr StringInput_SetEnableEmptyText,0x1501B258+1
        defadr StringInput_SetMinLen,0x1501B6A8+1
        defadr StringInput_SetMaxLen,0x1501B4C8+1
        defadr StringInput_SetActionOK,0x1501B348+1
        defadr StringInput_SetActionBack,0x1501B340+1
        defadr StringInput_GetStringAndLen,0x140B2CEC+1
        defadr StringInput_MenuItem_SetPriority,0x14F27670+1
        defadr GUIObject_SetSecondRowTitleText,0x143F2F8C+1
        defadr ListMenu_SetNoItemText,0x14F848D8+1
        defadr UI_Event,0x1431CA88+1
        defadr BookObj_KillBook,0x1446A2D0+1
        defadr TextFeedbackWindow,0x143F2710+1
        defadr Feedback_SetTextExtended,0x14524BD4+1
        defadr Feedback_CloseAction,0x1417B850+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x1585EAF8+1
        defadr Sound_SetMessageAlert,0x14E7B110+1
        defadr Sound_SetAlarmsignal,0x15176148+1
        defadr BookObj_GetBookID,0x14026BD4+1
        defadr Sound_AddToContact,0x152658D8+1
        defadr ListMenu_SetTexts,0x1411B408+1
        defadr DispObject_SetStyle,0x142E8570+1
        defadr DispObject_GetStyle,0x14048B00+1
        defadr DispObject_SoftKeys_Show,0x14139C20+1
        defadr DispObject_SoftKeys_Hide,0x14221748+1
        defadr GUIObject_SoftKeys_SetInfoText,0x143EB194+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x145B4FBC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x145B4F44+1
        defadr MediaPlayer_SoftKeys_SetText,0x145B4EEC+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x145B48A8+1

        defadr List_Create,0x142DB0F8+1
        defadr List_Get,0x140480B0+1
        defadr List_GetCount,0x143114FC+1
        defadr List_InsertLast,0x142DAFB0+1
        defadr List_InsertFirst,0x1424C85C+1
        defadr List_RemoveAt,0x142C8564+1
        defadr List_RemoveFirst,0x14026BB8+1
        defadr List_DestroyElements,0x1424F7D0+1
        defadr List_Destroy,0x140265EC+1

        defadr wstrncmp,0x14310E1C+1
        defadr CreateKeyGrabber,0x14FEAF44+1
        defadr FILEITEM_GetFextension,0x144DD0E0+1

        defadr IsAudioPlayerBook,0x14E6D978+1
        defadr FreeAllBook,0x154290E8+1

        defadr MusicApplication_PrevAction,0x1532D2D0+1
        defadr MusicApplication_CancelAction,0x14F40AA8+1
        defadr MusicApplication_ShowMyMusic,0x14E3089C+1
        defadr MusicApplication_Minimize,0x14E93600+1
        defadr MusicApplication_Keyboard,0x1405BDF8+1

        defadr pg_MusicApplication_PreviousEvent,0x1532D0E8+1
        defadr pg_MusicApplication_CancelEvent,0x14FF7FD8+1
        defadr pg_MusicApplication_ExitEvent,0x14ECDD0C+1

        defadr Music_Gui_NowPlaying_OnCreate,0x143ECF94+1
        defadr Music_Gui_NowPlaying_OnClose,0x14FF23A4+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x144F27EC+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x1448233C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x14242518+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x142B9660+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x14F08A5C+1

        defadr FeedbackTicker_OnRedraw,0x1414AC90+1

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

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_2
        CODE16
	CMP     R1, R5
	BEQ     EndFunc

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_3
        CODE16
	CMP     R0, #0
	BEQ     Continue

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_1
        CODE16
	ADD     R0, R4, #0
	LDR     R3, =IsAudioPlayerBook
	BLX     R3
	CMP     R0, #0
	BEQ     Continue
	CMP     R5, #0
	BEQ     loadVerticalData
	CMP     R5, #1
	BEQ     loadHorizontalData
	CMP     R5, #2
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
	LDR     R3, = 0x1424F4FC+1
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
	LDR     R3, =AddNew_SoftKeys
	BX      R3

        RSEG  CODE
        CODE16
AddNew_SoftKeys:
	ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR     R0, [R4,#0x20]
        MOV     R2, #7
        MOV     R1, #0xF
	LDR	R3, =GUIObject_SoftKeys_SetItemAsSubItem
	BLX	R3
        LDR	R3, =0x145B4A12+1
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
        BL      RefreshScreen
	LDRB    R1, [R6,#1]
	LDR     R0, [R5,#0]
	LDR     R3, =0x1532D284+1
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
	LDR     R3, =0x1532D2B8+1
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
