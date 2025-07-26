//C702_R3EF001
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x2AF004F8
        defadr memfree,0x2AF00520
        defadr memset,0x1190E3D0+1
        defadr memcpy,0x1190E2D0+1
        defadr debug_printf,0x2AF3A281
        defadr sprintf,0x1076F12C+1
        defadr snwprintf,0x1076F5E0+1
        defadr get_envp,0x10005C44+1
        defadr set_envp,0x10005C58+1
        defadr _fopen,0x109C7E28+1
        defadr fclose,0x1177B338+1
        defadr fread,0x109C97BC+1
        defadr fwrite,0x109C9988+1
        defadr fstat,0x109C878C+1
        defadr lseek,0x109C9B30+1
        defadr w_chdir,0x2AF00320
        defadr w_fopen,0x11308EC4+1
        defadr w_fstat,0x11308F7C+1
        defadr w_fwrite,0x11308F0C+1
        defadr w_fread,0x11308EF4+1
        defadr w_lseek,0x11AC9638+1
        defadr w_fclose,0x11308F24+1
        defadr w_mkdir,0x2AF002B8
        defadr w_diropen,0x2AF002C8
        defadr w_dirread,0x11AC9CC8+1
        defadr w_dirclose,0x2AF00308
        defadr w_rename,0x11AC9D64+1
        defadr w_remove,0x11AC9D18+1
        defadr FILEITEM_GetFname,0x11876838+1
        defadr FILEITEM_GetPath,0x118768CC+1
        defadr getFileExtention,0x109CB498+1
        defadr FSX_IsFileExists,0x1187164C+1
        defadr FSX_MakeFullPath,0x109CB5CC+1
        defadr FSX_FreeFullPath,0x109CB638+1
        defadr wstrcpy,0x10DD7478+1
        defadr wstrncpy,0x10DD7490+1
        defadr wstrcat,0x10DD74BC+1
        defadr wstrncat,0x1076FD60+1
        defadr wstrcmp,0x10DD7448+1
        defadr wstrlen,0x10DD7434+1
        defadr wstrwstr,0x1076FEEC+1
        defadr wstrcmpi,0x10DD8898+1
        defadr wstrchr,0x1076FCD4+1
        defadr wstrrchr,0x10DD87B8+1
        defadr wstrnupr,0x10DD7504+1
        defadr wstrnlwr,0x1106328C+1
        defadr str2wstr,0x10DD86FC+1
        defadr strcmp,0x1076F3B4+1
        defadr strlen,0x1076F410+1
        defadr strncmp,0x1076F44C+1
        defadr strncpy,0x1076F480+1
        defadr strcat,0x1076F37C+1
        defadr strstr,0x1076F51C+1
        defadr wstr2strn,0x10DD7554+1
        defadr TextID_CreateIntegerID,0x10FD4584+1
        defadr TextID_Create,0x10FD4758+1
        defadr TextID_GetString,0x10FD4E64+1
        defadr TextID_GetWString,0x10FD4CEC+1
        defadr TextID_Copy,0x10FD4938+1
        defadr TextID_GetLength,0x10FD4B9C+1
        defadr TextID_Destroy,0x10FD4A94+1
        defadr Timer_ReSet,0x10E5DAD8+1
        defadr Timer_Set,0x10E5DAA4+1
        defadr Timer_Kill,0x10E5DB30+1
        defadr CreateBook,0x10E614C4+1
        defadr BookObj_KillBook,0x10E615D8+1
        defadr BookObj_GotoPage,0x10E611D4+1
        defadr BookObj_CallPage,0x10E61308+1
        defadr BookObj_ReturnPage,0x10E6138C+1
        defadr BookObj_SetFocus,0x10E61774+1
        defadr BookObj_GetBookID,0x10E61C30+1
        defadr BookObj_GetDisplayOrientation,0x10E61CCC+1
        defadr BookObj_SetDisplayOrientation,0x10E61C68+1
        defadr FreeBook,0x10E61B44+1
        defadr FindBook,0x10E5F6FC+1
        defadr FreeAllBook,0x10E9827C+1
        defadr UI_Event,0x10E60264+1
        defadr IsAudioPlayerBook,0x10CF6100+1
        defadr GUIObject_Create,0x10A40B7C+1
        defadr BookObj_AddGUIObject,0x10E61854+1
        defadr GUIObject_SetStyle,0x10A40F8C+1
        defadr GUIObject_GetStyle,0x10A40FA8+1
        defadr GUIObject_SetTitleType,0x10A4112C+1
        defadr GUIObject_Destroy,0x10A40D40+1
        defadr GUIObject_SetTitleText,0x10A41148+1
        defadr GUIObject_SetSecondRowTitleText,0x10A41164+1
        defadr GUIObject_Show,0x10A40F34+1
        defadr GUIObject_GetBook,0x10A40DE0+1
        defadr GUIObject_GetDispObject,0x10A40DCC+1
        defadr DispObject_SetBacklightMode,0x10A3A6F0+1
        defadr DispObject_GetGUI,0x10A36FFC+1
        defadr DISP_DESC_SetName,0x10A341C8+1
        defadr DISP_DESC_SetSize,0x10A341CC+1
        defadr DISP_DESC_SetOnCreate,0x10A341D0+1
        defadr DISP_DESC_SetOnClose,0x10A341D4+1
        defadr DISP_DESC_SetOnRedraw,0x10A341D8+1
        defadr DISP_DESC_SetOnKey,0x10A341E0+1
        defadr DISP_DESC_SetOnRefresh,0x10A341DC+1
        defadr DISP_DESC_SetOnLayout,0x10A341EC+1
        defadr SetFont,0x10A3B9E8+1
        defadr DrawString,0x10A3AE28+1
        defadr DrawRect,0x10A3AADC+1
        defadr get_DisplayGC,0x10A3ED90+1
        defadr GC_PutChar,0x10A3F7CC+1
        defadr GC_GetPenColor,0x10A3F5DC+1
        defadr GC_SetPenColor,0x10A3F5A0+1
        defadr GC_SetPixel,0x10A3F224+1
        defadr GC_DrawLine,0x10A3FD20+1
        defadr GC_DrawFRect,0x10A3FEAC+1
        defadr GC_GetBrushColor,0x10A3F6B8+1
        defadr GC_SetBrushColor,0x10A3F678+1
        defadr GC_GetRect,0x10A3F3D4+1
        defadr GC_GetXX,0x10A3F6D0+1
        defadr GC_SetXX,0x10A3F6C4+1
        defadr GC_ValidateRect,0x10A3F384+1
        defadr CreateListMenu,0x11AF6B30+1
        defadr ListMenu_SetItemStyle,0x11AF6D80+1
        defadr ListMenu_SetItemCount,0x11AF6D44+1
        defadr ListMenu_SetHotkeyMode,0x11AF6E80+1
        defadr ListMenu_SetTexts,0x11AF6E5C+1
        defadr ListMenu_SetOnMessage,0x11AF6E54+1
        defadr ListMenu_GetSelectedItem,0x11AF6D30+1
        defadr ListMenu_SetCursorToItem,0x11AF6D1C+1
        defadr ListMenu_SetNoItemText,0x11AF6ED4+1
        defadr ListMenu_SetItemTextScroll,0x11AF7424+1
        defadr ListMenu_DestroyItems,0x11AF719C+1
        defadr ListMenu_SetItemSecondLineText,0x11AF70F8+1
        defadr GUIonMessage_GetMsg,0x11AF78E4+1
        defadr GUIonMessage_GetBook,0x11AF78EC+1
        defadr GUIonMessage_GetGui,0x11AF78E8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11AF7908+1
        defadr GUIonMessage_SetMenuItemIcon,0x11AF7954+1
        defadr GUIonMessage_SetItemDisabled,0x11AF79BC+1
        defadr GUIonMessage_SetMenuItemText,0x11AF7914+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11AF7944+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11AF7924+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11AF7934+1
        defadr CreateOneOfMany,0x11AF910C+1
        defadr OneOfMany_SetItemCount,0x11AF9298+1
        defadr OneOfMany_SetChecked,0x11AF92B4+1
        defadr OneOfMany_SetTexts,0x11AF92E8+1
        defadr OneOfMany_GetSelected,0x11AF92C4+1
        defadr OneOfMany_SetOnMessage,0x11AF92E0+1
        defadr GUIObject_SoftKeys_SetAction,0x10882D10+1
        defadr GUIObject_SoftKeys_SetText,0x10882D88+1
        defadr GUIObject_SoftKeys_SetInfoText,0x10882D74+1
        defadr GUIObject_SoftKeys_SetEnable,0x10882EAC+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x10882E30+1
        defadr GUIObject_SoftKeys_RemoveItem,0x10882CC4+1
        defadr GUIObject_SoftKeys_SetVisible,0x10882E0C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x10882EAC+1
        defadr GUIObject_SoftKeys_SuppressDefaultAction,0x1088307C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x108830E0+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x108830EC+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x10882F4C+1
        defadr GUIObject_SoftKeys_Hide,0x108830C8+1
        defadr GUIObject_SoftKeys_Show,0x108830D4+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x108830A8+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x1088302C+1
        defadr DispObject_SoftKeys_GetList,0x10880194+1
        defadr MediaPlayer_SoftKeys_SetText,0x10B622D4+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10B6228C+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10B62334+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x10B62364+1
        defadr GetImageWidth,0x10A3C0C0+1
        defadr GetImageHeight,0x10A3C0D4+1
        defadr ImageID_Get,0x10815E50+1
        defadr ImageID_Free,0x1081C070+1
        defadr ImageID_GetIndirect,0x10815EE8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10817ED0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10817F48+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10817FD0+1
        defadr Display_GetWidth,0x117F7D04+1
        defadr Display_GetHeight,0x117F7CF8+1
        defadr Disp_GetTextIDWidth,0x10A3C174+1
        defadr DispObject_SetLayerColor,0x10A39910+1
        defadr DispObject_SetAnimation,0x10A399C8+1
        defadr DispObject_InvalidateRect,0x10A37718+1
        defadr DispObject_SetRefreshTimer,0x10A37180+1
        defadr DispObject_KillRefreshTimer,0x10A371FC+1
        defadr List_DestroyElements,0x11B3D1E4+1
        defadr List_Destroy,0x11B3CEF8+1
        defadr List_Create,0x11B3CED0+1
        defadr List_InsertLast,0x11B3D04C+1
        defadr List_Get,0x11B3D0F0+1
        defadr List_GetCount,0x11B3D0C4+1
        defadr CreateTabMenuBar,0x117F5688+1
        defadr TabMenuBar_SetTabGui,0x117F5758+1
        defadr TabMenuBar_SetTabTitle,0x117F5820+1
        defadr TabMenuBar_SetTabIcon,0x117F57D8+1
        defadr TabMenuBar_SetTabCount,0x117F58E0+1
        defadr TabMenuBar_SetFocusedTab,0x117F573C+1
        defadr CreateStringInput,0x10908564+1
        defadr StringInput_SetMode,0x10908E1C+1
        defadr StringInput_SetFixedText,0x10908F60+1
        defadr StringInput_SetMinLen,0x10908E84+1
        defadr StringInput_SetMaxLen,0x10908F34+1
        defadr StringInput_SetEnableEmptyText,0x10908FA8+1
        defadr StringInput_SetActionOK,0x10908E78+1
        defadr TextFeedbackWindow,0x117F69E8+1
        defadr Feedback_SetTextExtended,0x117F6E58+1
        defadr Feedback_CloseAction,0x117F6DB8+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x11B1392C+1
        defadr Sound_SetMessageAlert,0x10CBF758+1
        defadr Sound_SetAlarmsignal,0x109A5900+1
        defadr Sound_AddToContact,0x10BC25F8+1
        defadr CreateMessageBox,0x11ACE8E4+1
        defadr OSE_GetShell,0x10E80330+1
        defadr CoCreateInstance,0x107918B0+1
        defadr DisplayGC_AddRef,0x10A3F1C8+1
        defadr Volume_Set,0x11A58B80+1
        defadr Volume_Get,0x11A58C4C+1
        defadr MetaData_GetTags,0x11871C64+1
        defadr DispObject_SetStyle,0x10A39DA4+1
        defadr DispObject_GetStyle,0x10A3A044+1
        defadr DispObject_SoftKeys_Show,0x1087F270+1
        defadr DispObject_SoftKeys_Hide,0x1087F238+1
        defadr MusicApplication_PrevAction,0x10CF6A24+1
        defadr MusicApplication_CancelAction,0x10CF7CCC+1
        defadr MusicApplication_ShowMyMusic,0x10CF7CEC+1
        defadr MusicApplication_Minimize,0x10CF7C98+1
        defadr MusicApplication_Keyboard,0x10CF7FF0+1

        defadr pg_MusicApplication_PreviousEvent,0x10CF649C+1
        defadr pg_MusicApplication_CancelEvent,0x10CF6B7C+1
        defadr pg_MusicApplication_ExitEvent,0x10CF6570+1

        defadr Music_Gui_NowPlaying_OnCreate,0x10B5ED14+1
        defadr Music_Gui_NowPlaying_OnClose,0x10B5EEEC+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x10B5EF74+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x10CF8584+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x10CF8388+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x10CF81B4+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x10CF65B0+1

        defadr FeedbackTicker_OnRedraw,0x11ACF718+1

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
	ldr	R3, =Patch_ORIENTATION
	bx	R3

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
	LDR	R3, =0x10E61CC2+1
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
	ADD     R0, R4, #0
        BL      New_SoftKeys
        LDR     R0, [R4,#0x1C]
        MOV     R2, #7
        MOV     R1, #0xF
	LDR	R3, =GUIObject_SoftKeys_SetItemAsSubItem
	BLX	R3
        LDR	R3, =0x10CF739A+1
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
	LDR     R3, =0x10CF69D8+1
	BX      R3

//------------------------------------------------------------------------------
#ifndef STANDART_EQ
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
#endif

        END
