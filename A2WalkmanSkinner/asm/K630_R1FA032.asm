//K630_R1FA032
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x10098358
        defadr memfree,0x10098380
        defadr memset,0x2A1C07A0
        defadr memcpy,0x100B83F4
        defadr set_envp,0x100A3080+1
        defadr get_envp,0x100A306C+1
        defadr snwprintf,0x104E3DB4+1
        defadr wstrlen,0x10F75F1C+1
        defadr wstrcat,0x10F75FA4+1
        defadr wstrcpy,0x10F75F60+1
        defadr wstrncpy,0x10F75F78+1
        defadr wstrcmp,0x10F75F30+1
        defadr wstrcmpi,0x10F77380+1
        defadr wstrncmp,0x104E4548+1
        defadr wstrrchr,0x10F772A0+1
        defadr wstrnupr,0x10F75FEC+1
        defadr wstr2strn,0x10F7603C+1
        defadr str2wstr,0x10F771E4+1
        defadr strlen,0x104E3BE4+1
        defadr strstr,0x104E3CF0+1
        defadr strcmp,0x104E3B88+1
        defadr strncmp,0x104E3C20+1
        defadr strcpy,0x104E3BB0+1
        defadr strncpy,0x104E3C54+1
        defadr fstat,0x10F85398+1
        defadr _fopen,0x10F84AA0+1
        defadr fread,0x10F861E4+1
        defadr fwrite,0x10F863B0+1
        defadr fclose,0x11542130+1
        defadr w_fopen,0x1077F078+1
        defadr w_fread,0x1077F0A8+1
        defadr w_fclose,0x1077F0D8+1
        defadr w_fstat,0x1077F130+1
        defadr w_lseek,0x113BF7F0+1
        defadr w_chdir,0x10098180
        defadr w_diropen,0x10098128
        defadr w_dirclose,0x10098168
        defadr w_dirread,0x113BFE80+1
        defadr FSX_MakeFullPath,0x10F87F14+1
        defadr FSX_FreeFullPath,0x10F87F80+1
        defadr FSX_IsFileExists,0x10FCFF70+1
        defadr FILEITEM_GetFname,0x10FD4BAC+1
        defadr FILEITEM_GetPath,0x10FD4C40+1
        defadr getFileExtention,0x10F87DE0+1
        defadr ImageID_Free,0x10F6F53C+1
        defadr ImageID_GetIndirect,0x10F6EF84+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10F6B45C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10F6B4D4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10F6B55C+1
        defadr iconidname2id,0x10CAAF14+1
        defadr Display_GetWidth,0x11649FB4+1
        defadr Display_GetHeight,0x11649FA8+1
        defadr List_DestroyElements,0x113C08D8+1
        defadr List_Destroy,0x113C05EC+1
        defadr List_Create,0x113C05C4+1
        defadr List_Get,0x113C07E4+1
        defadr List_GetCount,0x113C07B8+1
        defadr List_InsertFirst,0x113C0738+1
        defadr List_InsertLast,0x113C0740+1
        defadr root_list_get_session_count,0x11595814+1
        defadr root_list_get_session,0x11595820+1
        defadr UI_Event,0x11596484+1
        defadr UI_Event_toBookID,0x115964DC+1
        defadr UI_Event_toBookIDwData,0x115964F0+1
        defadr TextID_Create,0x11617FF0+1
        defadr TextID_CreateIntegerID,0x11617E30+1
        defadr TextID_GetLength,0x1161835C+1
        defadr TextID_Destroy,0x11618288+1
        defadr TextID_GetString,0x11618594+1
        defadr Disp_GetTextIDWidth,0x116344D4+1
        defadr Find_StandbyBook,0x115A3184+1
        defadr CreateBook,0x1159763C+1
        defadr FindBook,0x11595714+1
        defadr FreeBook,0x11597C48+1
        defadr FreeAllBook,0x11428D90+1
        defadr BookObj_CallPage,0x115974B4+1
        defadr BookObj_GotoPage,0x115973B4+1
        defadr BookObj_ReturnPage,0x1159751C+1
        defadr BookObj_SetFocus,0x115978DC+1
        defadr BookObj_GetBookID,0x11597CF4+1
        defadr BookObj_SetDisplayOrientation,0x11597D2C+1
        defadr BookObj_GetDisplayOrientation,0x11597D94+1
        defadr BookObj_GetSession,0x11597C94+1
        defadr DISP_DESC_SetName,0x1162AF00+1
        defadr DISP_DESC_SetSize,0x1162AF04+1
        defadr DISP_DESC_SetOnCreate,0x1162AF08+1
        defadr DISP_DESC_SetOnClose,0x1162AF0C+1
        defadr DISP_DESC_SetOnRedraw,0x1162AF10+1
        defadr DISP_DESC_SetOnKey,0x1162AF18+1
        defadr DISP_DESC_SetOnLayout,0x1162AF24+1
        defadr DispObject_GetGUI,0x1162F914+1
        defadr DispObject_SetStyle,0x11632404+1
        defadr DispObject_GetStyle,0x11632594+1
        defadr DispObject_SetLayerColor,0x11631FA4+1
        defadr DispObject_InvalidateRect,0x11630020+1
        defadr DispObject_SetAnimation,0x1163205C+1
        defadr DispObject_SetBacklightMode,0x11632C1C+1
        defadr DispObject_SoftKeys_Show,0x1165092C+1
        defadr DispObject_SoftKeys_Hide,0x116508FC+1
        defadr DispObject_SoftKeys_GetList,0x116517D4+1
        defadr BookObj_AddGUIObject,0x11597990+1
        defadr GUIObject_Create,0x1163A714+1
        defadr GUIObject_GetDispObject,0x1163A874+1
        defadr GUIObject_SetStyle,0x1163AA58+1
        defadr GUIObject_GetStyle,0x1163AA84+1
        defadr GUIObject_SetTitleType,0x1163AF10+1
        defadr GUIObject_SetTitleText,0x1163AF2C+1
        defadr GUIObject_SetSecondRowTitleText,0x1163AF48+1
        defadr GUIObject_Show,0x1163AA00+1
        defadr GUIObject_GetBook,0x1163A888+1
        defadr GUIObject_Destroy,0x1163A804+1
        defadr CreateListMenu,0x115EBF18+1
        defadr ListMenu_SetItemStyle,0x115EC184+1
        defadr ListMenu_SetHotkeyMode,0x115EC284+1
        defadr ListMenu_SetOnMessage,0x115EC258+1
        defadr ListMenu_SetItemCount,0x115EC148+1
        defadr ListMenu_SetCursorToItem,0x115EC120+1
        defadr ListMenu_SetNoItemText,0x115EC2D8+1
        defadr ListMenu_GetSelectedItem,0x115EC134+1
        defadr ListMenu_SetTexts,0x115EC260+1
        defadr ListMenu_SetItemTextScroll,0x115EC888+1
        defadr ListMenu_DestroyItems,0x115EC60C+1
        defadr ListMenu_SetItemSecondLineText,0x115EC530+1
        defadr GUIonMessage_GetBook,0x115ECC28+1
        defadr GUIonMessage_GetMsg,0x115ECC20+1
        defadr GUIonMessage_GetCreatedItemIndex,0x115ECC44+1
        defadr GUIonMessage_SetMenuItemText,0x115ECC50+1
        defadr GUIonMessage_SetMenuItemIcon,0x115ECC90+1
        defadr GUIonMessage_SetItemDisabled,0x115ECCF0+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x115ECC80+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x115ECC70+1
        defadr GUIonMessage_GetSelectedItem,0x115ECC2C+1
        defadr CreateOneOfMany,0x115EE27C+1
        defadr OneOfMany_SetItemCount,0x115EE428+1
        defadr OneOfMany_SetOnMessage,0x115EE470+1
        defadr OneOfMany_SetChecked,0x115EE444+1
        defadr OneOfMany_GetSelected,0x115EE454+1
        defadr CreateTabMenuBar,0x116479CC+1
        defadr TabMenuBar_SetTabGui,0x11647A9C+1
        defadr TabMenuBar_SetTabTitle,0x11647B64+1
        defadr TabMenuBar_SetTabIcon,0x11647B1C+1
        defadr TabMenuBar_SetTabCount,0x11647BE4+1
        defadr TabMenuBar_SetOnTabSwitch,0x11647B64+1
        defadr TabMenuBar_GetFocusedTab,0x11647A90+1
        defadr TabMenuBar_SetFocusedTab,0x11647A80+1
        defadr CreateStringInput,0x115C9D8C+1
        defadr StringInput_SetMode,0x115CA62C+1
        defadr StringInput_SetFixedText,0x115CA764+1
        defadr StringInput_SetMinLen,0x115CA688+1
        defadr StringInput_SetMaxLen,0x115CA738+1
        defadr StringInput_SetEnableEmptyText,0x115CA7AC+1
        defadr StringInput_SetActionOK,0x115CA67C+1
        defadr TextFeedbackWindow,0x11648E24+1
        defadr Feedback_SetTextExtended,0x11649290+1
        defadr Feedback_CloseAction,0x116491F4+1
        defadr GUIObject_SoftKeys_SetEnable,0x116542CC+1
        defadr GUIObject_SoftKeys_SetText,0x116541DC+1
        defadr GUIObject_SoftKeys_SetAction,0x11654164+1
        defadr GUIObject_SoftKeys_SetVisible,0x11654260+1
        defadr GUIObject_SoftKeys_SetInfoText,0x116541C8+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x116543A0+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x11654490+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x11654510+1
        defadr GUIObject_SoftKeys_Hide,0x11654530+1
        defadr GUIObject_SoftKeys_Show,0x1165453C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x11654300+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x11654548+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x11654554+1
        defadr Timer_ReSet,0x11594230+1
        defadr Timer_Set,0x115941FC+1
        defadr Timer_Kill,0x11594288+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x109C4464+1
        defadr REQUEST_SYSTEM_RESTART,0x109C4484+1
        defadr Shortcut_Run,0x1165AC10+1
        defadr FlightMode_GetState,0x115A1ED8+1
        defadr FlightMode_SetState,0x115A250C+1
        defadr Request_ICA_ShutdownAllConnections,0x109672AC+1
        defadr Display_GetBrightness,0x115B9148+1
        defadr ConnectionManager_Connection_GetState,0x113DD28C+1
        defadr MessageBox,0x1159D330+1
        defadr CreateMessageBox,0x1159D37C+1
        defadr IsVolumeControllerBook,0x11673CC0+1
        defadr IsRightNowBook,0x11663A34+1
        defadr IsAudioPlayerBook,0x1154C2FC+1
        defadr JavaDialog_Open,0x10F9F3A4+1
        defadr JavaAppDesc_GetFirstApp,0x10F953B0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10F94EBC+1
        defadr JavaApp_LogoImageID_Get,0x1107E240+1
        defadr JavaAppDesc_GetNextApp,0x10F953B8+1
        defadr JavaDialog_Close,0x10FA2A80+1
        defadr JavaSession_GetName,0x111072B0+1
        defadr manifest_GetParam,0x10F92170+1
        defadr GetImageWidth,0x11634438+1
        defadr GetImageHeight,0x1163444C+1
        defadr get_DisplayGC,0x11637F40+1
        defadr SetFont,0x11633E84+1
        defadr DrawString,0x116332CC+1
        defadr DrawRect,0x11632FCC+1
        defadr GC_PutChar,0x11638988+1
        defadr GC_DrawLine,0x11639218+1
        defadr GC_DrawImage,0x116331C0+1
        defadr GC_GetPenColor,0x11638794+1
        defadr GC_SetPenColor,0x11638758+1
        defadr GC_SetBrushColor,0x11638834+1
        defadr GC_GetXX,0x1163888C+1
        defadr GC_SetXX,0x11638880+1
        defadr GC_GetRect,0x11638588+1
        defadr GC_ValidateRect,0x11638538+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x1173554C+1
        defadr Sound_SetMessageAlert,0x11222924+1
        defadr Sound_SetAlarmsignal,0x10EDEF90+1
        defadr Sound_AddToContact,0x10EFEA08+1
        defadr Volume_Set,0x1116186C+1
        defadr Volume_Get,0x11161938+1
        defadr MetaData_GetTags,0x10FD0538+1
        defadr MetaData_GetCover,0x1154F64C+1
        defadr OSE_GetShell,0x1118869C+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x115522D8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x11552230+1
        defadr MediaPlayer_SoftKeys_SetText,0x11552278+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x11552308+1

        defadr MusicApplication_PrevAction,0x1154CB34+1
        defadr MusicApplication_CancelAction,0x1154DD30+1
        defadr MusicApplication_ShowMyMusic,0x1154DD50+1
        defadr MusicApplication_Minimize,0x1154DD04+1
        defadr MusicApplication_Keyboard,0x1154E028+1
        defadr MusicApplication_GetFilename,0x1154BE40+1
        defadr MusicApplication_GetFocusedItem,0x1154BE00+1
        defadr MusicApplication_SetSettings,0x1154BF68+1

        defadr pg_MusicApplication_PreviousEvent,0x1154C568+1
        defadr pg_MusicApplication_CancelEvent,0x1154CCB8+1
        defadr pg_MusicApplication_ExitEvent,0x1154C634+1

        defadr Music_Gui_NowPlaying_OnCreate,0x1154FA98+1
        defadr Music_Gui_NowPlaying_OnClose,0x1154FC9C+1
        defadr Music_Gui_NowPlaying_OnRedraw,0x1154FD2C+1

        defadr pg_MusicApplication_UI_MEDIAPLAYER_NEW_TRACK_EVENT,0x1154E4DC+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT,0x1154E358+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_CREATED_EVENT,0x1154E19C+1
        defadr pg_MusicApplication_UI_MEDIAPLAYER_ENTER_EVENT,0x1154C68C+1

        defadr FeedbackTicker_OnRedraw,0x1159E04C+1

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
	LDR	R3, =0x11597D86+1
	BX	R3

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
        LDR	R3, =0x1154D57A+1
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
        LDR	R3, =0x11552018+1
	BLX	R3
        MOV     R1, #0
next_:
        ADD     R0, R4, #0
        LDR	R3, =MusicApplication_SetSettings
	BLX	R3
        BL      refresh_gui
        POP     {R4,R5,PC}

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
