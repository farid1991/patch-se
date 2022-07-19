//W995_R1HA035

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x4BA33B64
        defadr memfree,0x4BA33B8C
        defadr memset,0x108F2864
        defadr memcpy,0x150DD514
        defadr sprintf,0x142D807C+1
        defadr snwprintf,0x144A2EF0+1
        defadr _fopen,0x1403EB5C+1
        defadr fclose,0x140FD63C+1
        defadr fread,0x144C2D80+1
        defadr fwrite,0x141C1358+1
        defadr fstat,0x14291AC4+1
        defadr w_chdir,0x4BA80C30
        defadr w_fopen,0x100B3184+1
        defadr w_fstat,0x100B31C8+1
        defadr w_fwrite,0x100FFA2C+1
        defadr w_fread,0x10100284+1
        defadr w_lseek,0x10646848+1
        defadr w_fclose,0x101487F8+1
        defadr w_mkdir,0x10566A54+1
        defadr w_diropen,0x14115ED4+1
        defadr w_dirread,0x1409E128+1
        defadr w_dirclose,0x4BA80C10
        defadr w_rename,0x141B4298+1
        defadr w_remove,0x141B45E8+1
        defadr getFileExtention,0x144DE868+1
        defadr FILEITEM_GetFname,0x142DC118+1
        defadr FILEITEM_GetPath,0x142DC11C+1
        defadr FSX_MakeFullPath,0x144C1EF8+1
        defadr FSX_FreeFullPath,0x14043398+1
        defadr FSX_IsFileExists,0x14FBB65C+1
        defadr CoCreateInstance,0x14461E40+1
        defadr get_envp,0x101EC73C+1
        defadr set_envp,0x101EC750+1
        defadr wstrcpy,0x144C27CC+1
        defadr wstrncpy,0x144C11C0+1
        defadr wstrcat,0x144C22B8+1
        defadr wstrncat,0x144C3320+1
        defadr wstrcmp,0x144C3140+1
        defadr wstrlen,0x144C353C+1
        defadr wstrnupr,0x141B1570+1
        defadr wstrnlwr,0x1400CBB0+1
        defadr wstrrchr,0x144C30E8+1
        defadr str2wstr,0x1428FF98+1
        defadr strcmp,0x14D3B45C+1
        defadr strlen,0x14D3B4B8+1
        defadr strncmp,0x141AB5B0+1
        defadr strncpy,0x14443898+1
        defadr strcat,0x1547AE90+1
        defadr strstr,0x142C4EE0+1
        defadr wstr2strn,0x1409E950+1
        defadr Volume_Get,0x142748C4+1
        defadr Volume_Set,0x14274AC4+1

        defadr TextID_CreateIntegerID,0x143D6484+1
        defadr TextID_Create,0x142D8380+1
        defadr TextID_Copy,0x1416F2A4+1
        defadr TextID_GetString,0x1416F518+1
        defadr TextID_GetWString,0x1416F7EC+1
        defadr TextID_GetLength,0x14170438+1
        defadr TextID_Destroy,0x1416FB98+1
        defadr TextObject_SetText,0x14170568+1
        defadr TextObject_SetFont,0x1417346C+1
        defadr RichTextLayout_GetTextWidth,0x1442304C+1
        defadr Display_GetHeight,0x1411B1D0+1
        defadr Display_GetWidth,0x141AA5B8+1
        defadr ImageID_Get,0x144551A8+1
        defadr ImageID_Free,0x14481C98+1
        defadr ImageID_GetIndirect,0x1515D594+1
        defadr Timer_ReSet,0x1416AB10+1
        defadr Timer_Set,0x1423E2EC+1
        defadr Timer_Kill,0x1416AE00+1
        defadr List_Create,0x141045D8+1
        defadr List_Destroy,0x141046D0+1
        defadr List_InsertFirst,0x14104840+1
        defadr List_InsertLast,0x1416AD0C+1
        defadr List_Find,0x1416E7B4+1
        defadr List_Get,0x1416E9D4+1
        defadr List_GetCount,0x1416E96C+1
        defadr List_RemoveAt,0x1416B160+1
        defadr List_DestroyElements,0x144DE364+1
        defadr CreateBook,0x144ABFCC+1
        defadr BookObj_KillBook,0x14045BF4+1
        defadr BookObj_CallPage,0x142CB2A0+1
        defadr BookObj_GotoPage,0x14045980+1
        defadr BookObj_ReturnPage,0x142CAF34+1
        defadr BookObj_GetBookID,0x1416EEE8+1
        defadr BookObj_GetDisplayOrientation,0x14046ADC+1
        defadr BookObj_SetDisplayOrientation,0x143A14FC+1
        defadr FreeBook,0x14133830+1
        defadr FindBook,0x1416E970+1
        defadr UI_Event,0x143A0D70+1
        defadr IsAudioPlayerBook,0x14271E28+1

        defadr GUIObject_Create,0x144AD124+1
        defadr GUIObject_SetStyle,0x14132D3C+1
        defadr GUIObject_GetStyle,0x1416DDC0+1
        defadr GUIObject_SetTitleType,0x143A26B0+1
        defadr GUIObject_SetTitleText,0x141105C8+1
        defadr GUIObject_SetSecondRowTitleText,0x144D6804+1
        defadr GUIObject_Show,0x144ACC2C+1
        defadr GUIObject_Destroy,0x14512BE0+1
        defadr GUIObject_GetDispObject,0x1416DDB4+1
        defadr GUIObject_GetBook,0x14105460+1
        defadr DispObject_InvalidateRect,0x1416BA88+1
        defadr DispObject_GetRect,0x1416BD1C+1
        defadr DispObject_GetGUI,0x14387AF8+1
        defadr DispObject_SetLayerColor,0x144AD814+1
        defadr DispObject_SetAnimation,0x14EEA8D0+1

        defadr DISP_DESC_SetName,0x14509ED0+1
        defadr DISP_DESC_SetSize,0x14509F1C+1
        defadr DISP_DESC_SetOnCreate,0x14509EC4+1
        defadr DISP_DESC_SetOnClose,0x14509ECC+1
        defadr DISP_DESC_SetOnRedraw,0x14509F20+1
        defadr DISP_DESC_SetOnKey,0x1450A328+1
        defadr DISP_DESC_SetOnRefresh,0x1450A324+1
        defadr DISP_DESC_SetMethod06,0x1450A188+1
        defadr DISP_DESC_SetOnLayout,0x1450A2CC+1
        defadr DISP_DESC_SetOnConfig,0x1450A18C+1
        defadr DISP_DESC_SetMethod0A,0x1450A1FC+1
        defadr DISP_DESC_SetMethod0B,0x1450A728+1
        defadr DISP_DESC_SetMethod0C,0x1450A3EC+1

        defadr get_DisplayGC,0x1416CA0C+1
        defadr DisplayGC_AddRef,0x143D02EC+1
        defadr DrawRect,0x14107C80+1
        defadr GC_GetRect,0x14117B70+1
        defadr GC_GetXX,0x142337A4+1
        defadr GC_SetXX,0x1419D3B0+1
        defadr GC_GetPenColor,0x144E2224+1
        defadr GC_SetPenColor,0x14107FF4+1
        defadr GC_SetPixel,0x144E21E0+1
        defadr GC_DrawLine,0x144E1F44+1
        defadr GC_DrawFRect,0x1428D204+1
        defadr GC_WritePixels,0x142A93C0+1
        defadr GC_ValidateRect,0x143D0314+1
        defadr GC_GetBrushColor,0x144E4780+1
        defadr GC_SetBrushColor,0x14107EDC+1
        defadr GC_DrawRoundRect,0x14503E08+1
        defadr BookObj_AddGUIObject,0x14132F2C+1

        defadr CreateListMenu,0x14132F38+1
        defadr ListMenu_SetCursorToItem,0x141328FC+1
        defadr ListMenu_GetSelectedItem,0x1411BF24+1
        defadr ListMenu_SetTexts,0x141AE460+1
        defadr ListMenu_SetItemStyle,0x140F6AE8+1
        defadr ListMenu_SetOnMessage,0x142DA720+1
        defadr ListMenu_SetItemCount,0x142DA734+1
        defadr ListMenu_GetItemCount,0x1413E840+1
        defadr ListMenu_SetHotkeyMode,0x1411BC80+1
        defadr ListMenu_SetNoItemText,0x150CE634+1
        defadr ListMenu_DestroyItems,0x143C3870+1
        defadr ListMenu_SetItemTextScroll,0x14110BEC+1
        defadr ListMenu_SetItemSecondLineText,0x142DA5A4+1

        defadr GUIonMessage_GetMsg,0x142F1378+1
        defadr GUIonMessage_GetBook,0x142F1290+1
        defadr GUIonMessage_GetGui,0x142F0E68+1
        defadr GUIonMessage_GetSelectedItem,0x14067918+1
        defadr GUIonMessage_GetPrevSelectedItem,0x1597405C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142F1284+1
        defadr GUIonMessage_SetItemDisabled,0x142593D8+1
        defadr GUIonMessage_SetMenuItemText,0x142F0CFC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FF338+1
        defadr GUIonMessage_SetMenuItemInfoText,0x14067DC8+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14FA5DDC+1
        defadr GUIonMessage_SetMenuItemIcon,0x14045284+1

        defadr CreateOneOfMany,0x140F6A6C+1
        defadr OneOfMany_SetOnMessage,0x14DB8908+1
        defadr OneOfMany_SetItemCount,0x150CE954+1
        defadr OneOfMany_SetChecked,0x141117A0+1
        defadr OneOfMany_SetTexts,0x141AE38C+1
        defadr OneOfMany_GetSelected,0x1509EAB8+1

        defadr CreateTabMenuBar,0x1433D6D8+1
        defadr TabMenuBar_SetTabCount,0x1426F670+1
        defadr TabMenuBar_SetTabGui,0x14513C60+1
        defadr TabMenuBar_SetTabIcon,0x142F3A8C+1
        defadr TabMenuBar_GetFocusedTab,0x141FFEC0+1
        defadr TabMenuBar_SetFocusedTab,0x14513970+1
        defadr TabMenuBar_SetTabTitle,0x1402BD70+1

        defadr TextFeedbackWindow,0x1423613C+1
        defadr Feedback_SetKeyHook,0x14E08514+1
        defadr Feedback_SetOnClose,0x14236110+1
        defadr Feedback_SetTimeout,0x14D54E30+1
        defadr Feedback_CloseAction,0x1414D540+1
        defadr Feedback_SetTextExtended,0x14235FC8+1

        defadr CreateStringInput,0x15072700+1
        defadr StringInput_SetMode,0x1400114C+1
        defadr StringInput_SetFixedText,0x140154EC+1
        defadr StringInput_SetMinLen,0x15072B48+1
        defadr StringInput_SetMaxLen,0x143194FC+1
        defadr StringInput_SetEnableEmptyText,0x14F1BC34+1
        defadr StringInput_SetActionOK,0x1428A2C4+1

        defadr GUIObject_SoftKeys_SetAction,0x14105420+1
        defadr GUIObject_SoftKeys_SetText,0x14105150+1
        defadr GUIObject_SoftKeys_SetEnable,0x1410582C+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x144A8B98+1
        defadr GUIObject_SoftKeys_RemoveItem,0x143CD2E8+1
        defadr GUIObject_SoftKeys_SetVisible,0x141053FC+1
        defadr GUIObject_SoftKeys_SetInfoText,0x140A7538+1
        defadr GUIObject_SoftKeys_Hide,0x14512A9C+1
        defadr GUIObject_SoftKeys_Show,0x143A15B0+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1410546C+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x141C5B08+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A1690+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x143A14F0+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x150E0244+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x140469D8+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x14DC75A8+1
        defadr DispObject_SetStyle,0x141A9D44+1
        defadr DispObject_GetStyle,0x1416DD58+1
        defadr DispObject_SetBacklightMode,0x14237974+1
        defadr DispObject_SoftKeys_Show,0x143A15BC+1
        defadr DispObject_SoftKeys_Hide,0x14512AB0+1
        defadr DispObject_SoftKeys_GetList,0x1416F08C+1
        defadr MediaPlayer_SoftKeys_SetText,0x140B4B28+1
        defadr MediaPlayer_SoftKeys_SetAction,0x140B4B58+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x140B4D58+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x140B4D88+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x140B4D88+1
        defadr MetaData_GetTags,0x14E951C0+1
        defadr CreateMessageBox,0x14EC3AAC+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x159882D0+1
        defadr Sound_SetMessageAlert,0x14E34724+1
        defadr Sound_SetAlarmsignal,0x1523F590+1
        defadr Sound_AddToContact,0x15363B14+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14EB3BFC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1515F1C8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1515F250+1

        defadr FreeAllBook,0x1553F820+1

        defadr MusicApplication_PrevAction,0x14D608B0+1
        defadr MusicApplication_CancelAction,0x14FF4E24+1
        defadr MusicApplication_ShowMyMusic,0x150E03E4+1
        defadr MusicApplication_Minimize,0x14FB4BB0+1
        defadr MusicApplication_Keyboard,0x140B4DD0+1

        defadr pg_MusicApplication_PreviousEvent,0x154381B4+1
        defadr pg_MusicApplication_CancelEvent,0x150B0BD4+1
        defadr pg_MusicApplication_ExitEvent,0x14F68BD8+1

        defadr Music_Gui_NowPlaying_OnCreate,0x14EC0FE4+1
        defadr Music_Gui_NowPlaying_OnClose,0x150AB86C+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x14496AD0+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x140B5070+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x140B55B0+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x14E42994+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x150DFB70+1

        defadr FeedbackTicker_OnRedraw,0x14201574+1

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
	BEQ     exit_code

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_3
        CODE16
	CMP     R0, #0
	BEQ     Continue

        RSEG PATCH_UPDATE_ORIENTATION_HOOK_1
        CODE16
	ADD     r0, r4, #0
	LDR     r3, =IsAudioPlayerBook
	BLX     r3
	CMP     r0, #0
	BEQ     Continue
	CMP     r5, #0
	beq     loadVerticalData
	CMP     r5, #1
	beq     loadHorizontalData
	CMP     r5, #2
	beq     loadHorizontalData
	B       Continue
loadHorizontalData:
	LDR     r3, =LoadLandscapeData
	BLX     r3
	B       Continue
loadVerticalData:
	LDR     r3, =LoadPortraitData
	BLX     r3
Continue:
	LDR     r3, = 0x14045DD0+1
	BLX     r3
exit_code:
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
	LDR     r3, =AddNew_SoftKeys
	BX      r3

        RSEG  CODE
        CODE16
AddNew_SoftKeys:
        LDR     R0, [R4,#0x20]
        ADD     R2, R7, #0
        MOV     R1, #7
	LDR	R3, =MediaPlayer_SoftKeys_AddHelpStr
	BLX	R3
	ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR	R3, =0x14DCCE66+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_Walkman_GUI
	CODE16
	LDR     R3, =_walkman
	BX      R3

        RSEG  CODE
        CODE16
_walkman:
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
	LDR     R3, =0x14F05058+1
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
	LDR     R3, =0x14F0508C+1
	BX      R3

//------------------------------------------------------------------------------

        END
