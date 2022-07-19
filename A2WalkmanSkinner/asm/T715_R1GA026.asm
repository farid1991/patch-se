//T715_R1GA026

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x4BA313F0
        defadr memfree,0x4BA31418
        defadr memset,0x141BB54C+1
        defadr memcpy,0x1405752C+1
        defadr get_envp,0x101D53E0+1
        defadr set_envp,0x101D53F4+1
        defadr _fopen,0x1403E950+1
        defadr fread,0x144BB810+1
        defadr fclose,0x140FC3F8+1
        defadr fwrite,0x141BF08C+1
        defadr fstat,0x1428F09C+1
        defadr w_fstat,0x100A69B0+1
        defadr w_diropen,0x4BA311C0
        defadr w_chdir,0x4BA80A64
        defadr w_dirread,0x1409CF54+1
        defadr w_dirclose,0x4BA80A44
        defadr w_fopen,0x100A696C+1
        defadr w_lseek,0x1429C640+1
        defadr w_fread,0x100F2A68+1
        defadr w_fclose,0x10139628+1
        defadr Timer_ReSet,0x14168C8C+1
        defadr Timer_Set,0x1423BDD8+1
        defadr Timer_Kill,0x14168F7C+1
        
        defadr Display_GetWidth,0x141A831C+1
        defadr Display_GetHeight,0x1411A138+1
        defadr DispObject_GetGUI,0x14382E70+1
        defadr GUIObject_GetBook,0x141043A8+1
        defadr Display_GetFocusedDispObject,0x1416B7FC+1
        defadr DispObject_GetName,0x1416BA34+1

        defadr TextID_Create,0x142D5A2C+1
        defadr TextID_GetLength,0x1416E4AC+1
        defadr TextID_Destroy,0x1416DCA4+1
        defadr TextID_CreateIntegerID,0x143D1A74+1
        defadr TextID_Copy,0x1416D3EC+1
        defadr TextID_GetWString,0x1416D910+1
        defadr RichTextLayout_GetTextWidth,0x1441DC80+1
        
        defadr DispObject_SetLayerColor,0x144A64E4+1
        defadr DispObject_InvalidateRect,0x14169C04+1
        defadr DISP_DESC_SetName,0x14501B90+1
        defadr DISP_DESC_SetSize,0x14501BDC+1
        defadr DISP_DESC_SetOnCreate,0x14501B84+1
        defadr DISP_DESC_SetOnClose,0x14501B8C+1
        defadr DISP_DESC_SetOnRedraw,0x14501BE0+1
        defadr DISP_DESC_SetOnLayout,0x14501F8C+1
        defadr DISP_DESC_SetOnKey,0x14501FE8+1
        defadr BookObj_AddGUIObject,0x14131DE0+1
        defadr GUIObject_Create,0x144A5E58+1
        defadr GUIObject_SetStyle,0x14131BF0+1
        defadr GUIObject_GetStyle,0x1416BF3C+1
        defadr GUIObject_SetTitleType,0x1439DD54+1
        defadr GUIObject_SetTitleText,0x1410F488+1
        defadr GUIObject_SetSecondRowTitleText,0x144CF1D8+1
        defadr GUIObject_Show,0x144A59BC+1
        defadr GUIObject_Destroy,0x1450A7A0+1
        defadr GUIObject_GetDispObject,0x1416BF30+1
        defadr DispObject_SetStyle,0x141A7AA8+1
        defadr DispObject_GetStyle,0x1416BED4+1
        defadr DispObject_SetAnimation,0x14E250B0+1
        defadr DispObject_SetBacklightMode,0x142351EC+1
        defadr DispObject_SoftKeys_Show,0x1439CB48+1
        defadr DispObject_SoftKeys_Hide,0x1450A670+1

        defadr CreateOneOfMany,0x140F5828+1
        defadr OneOfMany_SetItemCount,0x1500532C+1
        defadr OneOfMany_SetOnMessage,0x14CF4DA4+1
        defadr OneOfMany_GetSelected,0x14FD5874+1
        defadr OneOfMany_SetChecked,0x14110634+1
        
        defadr wstrlen,0x144BBB64+1
        defadr wstr2strn,0x1409D77C+1
        defadr wstrnupr,0x141AF2C8+1
        defadr wstrcpy,0x1428EA98+1
        defadr wstrrchr,0x1409E758+1
        defadr wstrcmp,0x144B9AD0+1
        defadr str2wstr,0x1428D570+1
        defadr wstrcat,0x1428E9F0+1
        defadr strlen,0x141BBB38+1
        defadr strncpy,0x1443E2F0+1
        defadr strstr,0x142C25FC+1

        defadr MetaData_GetTags,0x14DD04F0+1
        defadr FILEITEM_GetFname,0x142D970C+1
        defadr FILEITEM_GetPath,0x142D9710+1
        defadr getFileExtention,0x144D7250+1
        defadr FSX_MakeFullPath,0x144BA990+1
        defadr FSX_FreeFullPath,0x14042CCC+1
        defadr FSX_IsFileExists,0x14EF3628+1
        
        defadr get_DisplayGC,0x1416AB88+1
        defadr DrawRect,0x14106BBC+1
        defadr snwprintf,0x1449BB54+1
        defadr GC_SetPenColor,0x14106F30+1
        defadr GC_SetBrushColor,0x14106E18+1
        defadr GC_DrawLine,0x144DA91C+1
        defadr GC_GetRect,0x14116AE0+1
        defadr GC_GetXX,0x1423109C+1
        defadr GC_SetXX,0x1419B20C+1
        defadr GC_ValidateRect,0x143CB940+1
        defadr GC_GetPenColor,0x144DABFC+1
        defadr BookObj_GetDisplayOrientation,0x140463A4+1
        defadr BookObj_SetDisplayOrientation,0x1439CA88+1

        defadr CreateListMenu,0x14131DEC+1
        defadr ListMenu_SetTexts,0x141AC1A8+1
        defadr ListMenu_SetItemCount,0x142D7D28+1
        defadr ListMenu_SetHotkeyMode,0x1411ABD0+1
        defadr ListMenu_SetOnMessage,0x142D7D14+1
        defadr ListMenu_SetCursorToItem,0x141317D4+1
        defadr ListMenu_SetItemStyle,0x140F58A4+1
        defadr ListMenu_SetItemTextScroll,0x1410FA9C+1
        defadr ListMenu_DestroyItems,0x143BEEEC+1
        defadr ListMenu_GetSelectedItem,0x1411AE6C+1
        defadr ListMenu_SetNoItemText,0x1500500C+1
        defadr ListMenu_SetItemSecondLineText,0x142D7B98+1
        defadr GUIonMessage_GetMsg,0x142EE8DC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142EE7E8+1
        defadr GUIonMessage_SetMenuItemText,0x142EE2C4+1
        defadr GUIonMessage_GetBook,0x142EE7F4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FCEC8+1
        defadr GUIonMessage_SetItemDisabled,0x14256E00+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14EDE07C+1

        defadr List_DestroyElements,0x144D6D40+1
        defadr List_Destroy,0x141035F4+1
        defadr List_Create,0x141034FC+1
        defadr List_InsertLast,0x14168E88+1
        defadr List_Get,0x1416CAC4+1
        defadr List_GetCount,0x1416CAD8+1

        defadr FreeBook,0x141326E4+1
        defadr CreateBook,0x144A4D98+1
        defadr BookObj_KillBook,0x140454DC+1
        defadr BookObj_CallPage,0x142C89D4+1
        defadr BookObj_ReturnPage,0x142C8668+1
        defadr BookObj_GotoPage,0x14045268+1
        defadr BookObj_SetFocus,0x1450A1AC+1
        defadr FindBook,0x1416CADC+1
        defadr IsAudioPlayerBook,0x1426F6B0+1
        defadr UI_Event,0x1439C2F8+1
        defadr BookObj_GetBookID,0x1416D04C+1
        
        defadr CreateMessageBox,0x14DFE5F4+1
        defadr DispObject_SoftKeys_GetList,0x1416D1F0+1
        defadr GUIObject_SoftKeys_Hide,0x1450A65C+1
        defadr GUIObject_SoftKeys_Show,0x1439CB3C+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x140462A4+1
        defadr GUIObject_SoftKeys_SetText,0x14104060+1
        defadr GUIObject_SoftKeys_SetAction,0x14104368+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x150167D8+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x14D03938+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1439CA7C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x141043B4+1
        defadr GUIObject_SoftKeys_SetInfoText,0x140A6348+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1439CC1C+1

        defadr CreateTabMenuBar,0x1433A668+1
        defadr TabMenuBar_SetTabGui,0x1450B7F4+1
        defadr TabMenuBar_SetTabTitle,0x1402BD68+1
        defadr TabMenuBar_SetTabIcon,0x142F0F58+1
        defadr TabMenuBar_SetTabCount,0x1426CF04+1
        defadr TabMenuBar_SetFocusedTab,0x1450B504+1

        defadr CreateStringInput,0x14FA9774+1
        defadr StringInput_SetMode,0x14001148+1
        defadr StringInput_SetFixedText,0x140157B8+1
        defadr StringInput_SetMinLen,0x14FA9BBC+1
        defadr StringInput_SetMaxLen,0x14316978+1
        defadr StringInput_SetEnableEmptyText,0x14E55AE8+1
        defadr StringInput_SetActionOK,0x142878D8+1

        defadr TextFeedbackWindow,0x14233A24+1
        defadr Feedback_SetTextExtended,0x142338B0+1
        defadr Feedback_CloseAction,0x1414BCB4+1

        defadr SETTING_RINGTYPESOUNDFILE_SET,0x1584E37C+1
        defadr Sound_SetMessageAlert,0x14D6FD30+1
        defadr Sound_SetAlarmsignal,0x1515FB38+1
        defadr Sound_AddToContact,0x1525BBCC+1
        
        defadr CoCreateInstance,0x1445AE3C+1
        defadr TextObject_SetText,0x1416E5E4+1
        defadr TextObject_SetFont,0x141714E8+1
        defadr DisplayGC_AddRef,0x143CB918+1
        
        defadr Volume_Get,0x14271F70+1
        defadr Volume_Set,0x1427216C+1
        defadr ImageID_GetIndirect,0x15091C64+1
        defadr ImageID_Free,0x1447AB4C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14DEE674+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15093898+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14098A7C+1
        
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x140B3B04+1
        defadr MediaPlayer_SoftKeys_SetAction,0x140B3904+1
        defadr MediaPlayer_SoftKeys_SetText,0x140B38D4+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x140B3B34+1

//------------------------------------------------------------------------------

        defadr FreeAllBook,0x15422AD0+1

        defadr MusicApplication_PrevAction,0x14C9D210+1
        defadr MusicApplication_CancelAction,0x14F2C464+1
        defadr MusicApplication_ShowMyMusic,0x14E53588+1
        defadr MusicApplication_Minimize,0x14EECBB0+1
        defadr MusicApplication_Keyboard,0x140B3B7C+1

        defadr pg_MusicApplication_PreviousEvent,0x15325F0C+1
        defadr pg_MusicApplication_CancelEvent,0x14FE7878+1
        defadr pg_MusicApplication_ExitEvent,0x14EA218C+1

        defadr Music_Gui_NowPlaying_OnCreate,0x14DFBB60+1
        defadr Music_Gui_NowPlaying_OnClose,0x14FE2628+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x1448F794+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x140B3E1C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x140B4340+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x14D7E204+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x150161AC+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_EXIT_EVENT,0x14E8BC6C+1

        defadr FeedbackTicker_OnRedraw,0x141FF08C+1

//------------------------------------------------------------------------------

        EXTERN New_Music_Gui_NowPlaying_OnRedraw
        EXTERN New_Music_Gui_NowPlaying_OnCreate
        EXTERN New_Music_Gui_NowPlaying_OnClose
        EXTERN New_Music_Gui_NowPlaying_OnKey

	EXTERN PATCH_UI_MEDIAPLAYER_AUDIO_ON_NEW_TRACK_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_CREATED_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_ON_ENTER_EVENT
	EXTERN PATCH_UI_MEDIAPLAYER_ON_EXIT_EVENT

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

	RSEG PATCH_UI_MEDIAPLAYER_ON_EXIT_PAGE_HOOK
	DATA
	DCD PATCH_UI_MEDIAPLAYER_ON_EXIT_EVENT

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
	LDR     R3, = 0x140456BC+1
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
        MOV     R1, #7
	LDR	R3, =MediaPlayer_SoftKeys_SetInfoText
	BLX	R3
	ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR     R0, [R4,#0x20]
        LDR	R3, =0x14D091D0+1
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
	LDR     R3, =0x14E3F640+1
	BX      R3

//------------------------------------------------------------------------------

        END
