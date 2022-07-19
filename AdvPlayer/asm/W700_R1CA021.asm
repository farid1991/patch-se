//W700_R1CA021

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F89D7C+1
        defadr memfree,0x44F8AE98+1
        defadr memset,0x44B46898+1
        defadr debug_printf,0x44AF7014+1

        defadr set_envp,0x44031AB6+1
        defadr get_envp,0x44031AA2+1
        defadr current_process,0x44068DB0
        defadr get_bid,0x44068DE8
        defadr snwprintf,0x44B47AA4+1
        defadr sscanf,0x4402F928+1
        defadr _fopen,0x450EC374+1
        defadr fread,0x450ED870+1
        defadr fclose,0x450ED554+1
        defadr fwrite,0x450EDB0C+1
        defadr fstat,0x450ECC34+1
        defadr lseek,0x450EDC98+1
        defadr FileDelete,0x450ECD88+1
        defadr w_diropen,0x4511B760+1
        defadr w_chdir,0x45119D28+1
        defadr w_dirread,0x44D00464+1
        defadr w_fstat,0x4476D184+1
        defadr w_dirclose,0x4511B9E8+1

        defadr wstrlen,0x44BF49F4+1
        defadr wstrcmp,0x44BF4A20+1
        defadr wstrcmpi,0x44BF6164+1
        defadr wstrrchr,0x44BF5FDC+1
        defadr strncmp,0x44B478C4+1
        defadr strcmp,0x44B47824+1
        defadr wstrcpy,0x44BF4A70+1
        defadr wstrcat,0x44BF4B18+1

        defadr BookObj_GotoPage,0x44E88854+1
        defadr BookObj_CallPage,0x44E8896C+1
        defadr BookObj_GetBookID,0x44E8927C+1

        defadr TextID_Create,0x44EFA32C+1
        defadr TextID_CreateIntegerID,0x44EF9F5C+1
        defadr TextID_CreateFromChar,0x44EF9F54+1
        defadr TextID_Destroy,0x44EFA604+1
        defadr TextID_GetLength,0x44EFA698+1
        defadr Disp_GetTextIDWidth,0x44E95184+1

        defadr Format_Time,0x44F6D9B4+1
        defadr TextIteratorSetTextId,0x44EFA0A8+1

        defadr CreateMessageBox,0x4506E1CC+1

        defadr ImageID_Get,0x44F5A660+1
        defadr ImageID_Free,0x44F5AA00+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x450E575C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x450E5874+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x450E59F4+1

        defadr Display_GetHeight,0x4506A804+1
        defadr Display_GetWidth,0x4506A814+1
        defadr Display_GetTopBook,0x44E88418+1
        defadr GUIObject_GetDispObject,0x44EAC810+1
        defadr DispObject_GetGUI,0x44E8FE1C+1
        defadr GUIObject_GetBook,0x44EAC838+1
        defadr DispObject_SoftKeys_GetList,0x44D3BA80+1

        defadr get_DisplayGC,0x44D46904+1
        defadr GC_PutChar,0x44D473E4+1
        defadr SetFont,0x44E94964+1
        defadr DrawString,0x44E93E10+1
        defadr DrawRect,0x44E93A08+1
        defadr GetImageWidth,0x44E950AC+1
        defadr GetImageHeight,0x44E950C4+1

        defadr GetThemeColor,0x45069B58+1
        defadr DispObject_SetLayerColor,0x44E93388+1
        defadr DispObject_SetThemeImage,0x44E92E50+1
        defadr DispObject_WindowSetSize,0x44E91D64+1
        defadr DispObject_InvalidateRect,0x44E90340+1
        defadr DispObject_SetAnimation,0x44E933E0+1

        defadr CreateListMenu,0x44D68400+1
        defadr ListMenu_SetItemCount,0x44D685BC+1
        defadr ListMenu_SetCursorToItem,0x44D6858C+1
        defadr ListMenu_GetSelectedItem,0x44D685A0+1
        defadr ListMenu_SetOnMessage,0x44D686EC+1
        defadr ListMenu_SetHotKeyMode,0x44D68718+1
        defadr GUIonMessage_GetMsg,0x44D68C34+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D68C60+1
        defadr GUIonMessage_SetMenuItemText,0x44D68C70+1
        defadr GUIonMessage_SetMenuItemIcon,0x44D68CB0+1

        defadr GUIObject_SetTitleType,0x44D3D878+1
        defadr GUIObject_SetTitleText,0x44D3D890+1
        defadr GUIObject_SetTitleTextAlign,0x44D3D8CC+1
        defadr GUIObject_SetSecondRowTitleText,0x44D3D8AC+1
        defadr GUIObject_SetTitleBackgroundImage,0x44D698A8+1
        defadr GUIObject_SetStyle,0x44D3D7E4+1
        defadr GUIObject_Destroy,0x44EAC5C8+1
        defadr GUIObject_Show,0x44D3D794+1

        defadr DispObject_SetStyle,0x44E9340C+1
        defadr DispObject_SetTitleType,0x44E92064+1
        defadr DispObject_SetTitleText,0x44E91F48+1+1
        defadr DispObject_SetSecondRowTitleText,0x44E91F90+1

        defadr GUIObject_SoftKeys_SetText,0x44D3EFBC+1
        defadr GUIObject_SoftKeys_SetAction,0x44D3EED4+1
        defadr MediaPlayer_SoftKeys_SetText,0x44C81130+1
        defadr MediaPlayer_SoftKeys_Validate,0x44C810DC+1

        defadr MediaPlayer_Audio_ActionBack,0x44F647D8+1
        defadr MediaPlayer_Audio_ActionLongBack,0x44F64794+1

        defadr pg_MediaPlayer_Audio_Bk_PrevEvent,0x44F66584+1
        defadr pg_MediaPlayer_Audio_Bk_CancelEvent,0x44F665C8+1
        defadr pg_MediaPlayer_Audio_Bk_ExitEvent,0x44F6655C+1

        defadr Call_MM_BrowserAlbumsMain,0x4505339C+1
        defadr pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Start,0x45058854+1
        defadr pg_MM_Browser_Toplevel_Bk_NowPlayingStartedByChild_Cancel,0x450588E8+1
        defadr pg_MM_Browser_Toplevel_Bk_Videos,0x45058920+1

        defadr MediaPlayer_Audio_OnCreate,0x44E32A6C+1
        defadr MediaPlayer_Audio_OnClose,0x44E32B48+1
        defadr MediaPlayer_NowPlaying_OnCreate,0x44E33FCC+1
        defadr MediaPlayer_NowPlaying_OnClose,0x44E34090+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x44E340D4+1

        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x44F66844+1
        defadr pg_MEDIAPLAYER_NEW_TRACK_EVENT,0x44F668C4+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x44F67D98+1

        EXTERN New_MediaPlayer_Audio_OnCreate
        EXTERN New_MediaPlayer_Audio_OnClose
        EXTERN New_MediaPlayer_Audio_OnRedraw
        EXTERN New_MediaPlayer_Audio_SetStyle
        EXTERN New_MediaPlayer_PlayQueue_SetStyle
        EXTERN New_MediaPlayer_PlayQueue_SetTitle
        EXTERN New_MediaPlayer_NowPlaying_SetSize
        EXTERN New_MediaPlayer_NowPlaying_OnCreate
        EXTERN New_MediaPlayer_NowPlaying_OnClose
        EXTERN New_MediaPlayer_NowPlaying_OnRedraw

        EXTERN New_UI_MEDIAPLAYER_NEW_TRACK_EVENT
        EXTERN New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        EXTERN New_UI_MEDIAPLAYER_CREATED_EVENT

        EXTERN CallSkinSelector
        EXTERN SkinSelect_GetText

        RSEG    PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT
        DATA
        DCD     New_UI_MEDIAPLAYER_NEW_TRACK_EVENT

        RSEG    PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        DATA
        DCD     New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT

        RSEG    PATCH_UI_MEDIAPLAYER_CREATED_EVENT
        DATA
        DCD     New_UI_MEDIAPLAYER_CREATED_EVENT

        RSEG    PATCH_MediaPlayer_Audio_OnCreate
        DATA
        DCD     New_MediaPlayer_Audio_OnCreate

        RSEG    PATCH_MediaPlayer_Audio_OnClose
        DATA
        DCD     New_MediaPlayer_Audio_OnClose

        RSEG    PATCH_MediaPlayer_Audio_OnRedraw
        DATA
        DCD     New_MediaPlayer_Audio_OnRedraw

        RSEG    PATCH_MediaPlayer_NowPlaying_OnCreate
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnCreate

        RSEG    PATCH_MediaPlayer_NowPlaying_OnClose
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnClose

        RSEG    PATCH_MediaPlayer_NowPlaying_OnRedraw
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnRedraw

        RSEG    PATCH_MediaPlayer_Volume_SetPosition
	CODE16
        NOP
	MOV     R2, #0
	MOV     R1, #0

        RSEG    PATCH_MediaPlayer_ScrollText_SetSize
	CODE16
	NOP
        NOP
        MOV     R2, #0
	MOV     R1, #0

;====================PlayQueue=============================
        RSEG    PATCH_MediaPlayer_PlayQueue_RemoveStyle
	CODE16
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_MediaPlayer_PlayQueue_SetStyle
	CODE16
        LDR	R3, =mp_playqueue_setstyle
	BX	R3

        RSEG  CODE
        CODE16
mp_playqueue_setstyle:
        LDR     R0, [R4,#0x68]
        BL      New_MediaPlayer_PlayQueue_SetStyle
        LDR	R3, =0x44E32C42+1
	BX      R3

;====================NowPlaying=============================

        RSEG    PATCH_MediaPlayer_NowPlaying_SetSize
	CODE16
        LDR	R3, =mp_nowplaying_setsize
	BX	R3

        RSEG  CODE
        CODE16
mp_nowplaying_setsize:
        LDR     R0, [R4,#0x74]
        BL      New_MediaPlayer_NowPlaying_SetSize
        LDR	R3, =0x44E32F1C+1
	BX      R3

        RSEG    PATCH_GUI_PLAYMODE
	CODE16
        MOV     R1, #9

        RSEG    PATCH_MediaPlayer_Audio_SetStyle
        CODE16
	LDR	R3, =mp_audio_setstyle
	BX	R3

        RSEG  CODE
        CODE16
mp_audio_setstyle:
        ADD     R0, R4, #0
        BL      New_MediaPlayer_Audio_SetStyle
        LDR	R3, =0x44E32B0C+1
	BX      R3

;====================Skin Select=============================

        RSEG    PATCH_SKIN_SELECTOR_LINK
        DATA
        DCD     CallSkinSelector

        RSEG    PATCH_SKIN_SELECTOR_TEXT1
	CODE16
	LDR	R3, =skinselector_get_text1
	BX	R3

        RSEG    PATCH_SKIN_SELECTOR_TEXT2
	CODE16
	LDR	R3, =skinselector_get_text2
	BX	R3

        RSEG  CODE
        CODE16
skinselector_get_text1:
        BL      SkinSelect_GetText
        ADD     R2, R0, #0
        MOV     R1, #0xE
        LDR     R0, [R4,#0x1C]
        LDR	R3, =MediaPlayer_SoftKeys_SetText
	BLX	R3
        B       _cnt

skinselector_get_text2:
        BL      SkinSelect_GetText
        ADD     R2, R0, #0
        MOV     R1, #0xE
        LDR     R0, [R4,#0x1C]
        LDR	R3, =GUIObject_SoftKeys_SetText
	BLX	R3
_cnt:
        LDR	R3, =0x44F64BA4+1
	BX      R3

;====================TopLevel Parts=============================

        EXTERN New_MainMenu_TopLevelBrowser
        EXTERN New_ListText_TopLevelBrowser
        EXTERN New_ListIcon_TopLevelBrowser
        EXTERN New_ListLink_TopLevelBrowser
        EXTERN New_ListText_Track

        RSEG    PATCH_GUI_TOPLEVEL_STYLE
	CODE16
        BX      LR

        RSEG    PATCH_GUI_MM_ARTIST
	CODE16
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_ALBUM
	CODE16
	NOP
	NOP
	NOP
        NOP

        RSEG    PATCH_GUI_MM_TRACKS1
	CODE16
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_BROWSER_LISTLINK
	CODE16
        PUSH    {LR}
	BL      New_ListLink_TopLevelBrowser
        POP     {PC}

        RSEG    PATCH_GUI_MM_BROWSER_STYLE
	CODE16
	LDR	R3, =menu_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
menu_toplevel_browser:
        LDR     R0, [R4,#0x18]
        BL      New_MainMenu_TopLevelBrowser
        LDR     R3, =0x4505862E+1
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_LISTCOUNT
	CODE16
        NOP
        NOP
        MOV     R0, #6

        RSEG    PATCH_GUI_MM_BROWSER_LISTTEXT
	CODE16
	LDR	R3, =listtext_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
listtext_toplevel_browser:
        BL      New_ListText_TopLevelBrowser
        ADD     R1, R0, #0
        ADD     R0, R4, #0
        LDR     R3, =0x4505871C+1
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_LISTICON
	CODE16
	LDR	R3, =listicon_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
listicon_toplevel_browser:
        ADD     R0, R5, #0
        BL      New_ListIcon_TopLevelBrowser
        ADD     R2, R0, #0
        LDR     R3, =0x4505872E+1
	BX      R3

        RSEG    PATCH_GUI_MM_TRACKS2
	CODE16
	LDR	R3, =list_tracks_number
	BX      R3

        RSEG  CODE
        CODE16
list_tracks_number:
        MOV     R1, #0
        BL      TextID_Create
        LDR     R1, [SP,#0xC]
        BL      New_ListText_Track
        ADD     R1, R0, #0
        LDR     R3, =0x4505909C+1
	BX      R3

        END
