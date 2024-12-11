//W800_R1BD001
#include "target.h"

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F8145C+1
        defadr memfree,0x44F82578+1
        defadr memset,0x44B42F8C+1
        defadr memcmp,0x44B42F20+1
        defadr memcpy,0x44069D60
        defadr debug_printf,0x44AC8A7C+1
        defadr set_envp,0x44031AC2+1
        defadr get_envp,0x44031AAE+1
        defadr current_process,0x44068DBC
        defadr get_bid,0x44068DF4
        defadr sprintf,0x44B43AB4+1
        defadr snwprintf,0x44B44198+1
        defadr sscanf,0x4402F934+1
        defadr _fopen,0x450E5728+1
        defadr fread,0x450E6C24+1
        defadr fclose,0x450E6908+1
        defadr fwrite,0x450E6EC0+1
        defadr fstat,0x450E5FE8+1
        defadr lseek,0x450E704C+1
        defadr FileDelete,0x450E613C+1
        defadr w_diropen,0x45114B54+1
        defadr w_chdir,0x4511311C+1
        defadr w_dirread,0x44CFC2AC+1
        defadr w_fstat,0x4480D50C+1
        defadr w_dirclose,0x45114DDC+1
        defadr wstrlen,0x44B4462C+1
        defadr wstrcmp,0x44B445C0+1
        defadr wstrcpy,0x44B445F0+1
        defadr wstrncpy,0x44B446A4+1
        defadr wstrcat,0x44B44590+1
        defadr wstrcmpi,0x44BF1E50+1
        defadr wstrrchr,0x44B446F4+1
        defadr wstrwstr,0x44B44600+1
        defadr strncmp,0x44B43FB8+1
        defadr strcmp,0x44B43F18+1
        defadr strlen,0x44B43F80+1
        defadr manifest_GetParam,0x4508E5E4+1
        defadr Timer_ReSet,0x44E81DDC+1
        defadr Timer_Set,0x44E81DA4+1
        defadr Timer_Kill,0x44E81E2C+1
        defadr List_Create,0x44E57300+1
        defadr List_Destroy,0x44E57324+1
        defadr List_DestroyElements,0x44E5774C+1
        defadr List_InsertFirst,0x44E57444+1
        defadr List_InsertLast,0x44E57454+1
        defadr List_Get,0x44E575D4+1
        defadr List_GetCount,0x44E575AC+1
        defadr BookObj_GotoPage,0x44E827BC+1
        defadr BookObj_CallPage,0x44E828D4+1
        defadr BookObj_GetBookID,0x44E831E4+1
        defadr BookObj_CallSubroutine,0x44E8283C+1
        defadr FreeBook,0x44E83090+1
        defadr UI_Event,0x4505B5E4+1
        defadr TextID_Create,0x44EF41C4+1
        defadr TextID_CreateIntegerID,0x44EF3DF4+1
        defadr TextID_CreateCharacterID,0x44EF3DEC+1
        defadr TextID_Destroy,0x44EF449C+1
        defadr TextID_GetLength,0x44EF4530+1
        defadr Disp_GetTextIDWidth,0x44E8F0EC+1
        defadr strftime,0x44F6649C+1
        defadr TextID_CreateFromTextIterator,0x44EF3F40+1
        defadr count_digit,0x44D33F64+1
        defadr itow,0x44D33BD8+1
        defadr MessageBox,0x45067520+1
        defadr CreateMessageBox,0x4506757C+1
        defadr ImageID_Get,0x44F53180+1
        defadr ImageID_Free,0x44F53520+1
        defadr ImageID_GetIndirect,0x44F531D8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x450DEB10+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x450DEC28+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x450DEDA8+1
        defadr Display_GetHeight,0x45063BA4+1
        defadr Display_GetWidth,0x45063BB4+1
        defadr Display_GetTopBook,0x44E82380+1
        defadr GUIObject_GetDispObject,0x44EA6780+1
        defadr DispObject_GetGUI,0x44E89D84+1
        defadr GUIObject_GetBook,0x44EA67A8+1
        defadr DispObject_SoftKeys_GetList,0x44D378B4+1
        defadr get_DisplayGC,0x44D42738+1
        defadr GC_PutChar,0x44D43218+1
        defadr SetFont,0x44E8E8CC+1
        defadr DrawString,0x44E8DD78+1
        defadr DrawRect,0x44E8D970+1
        defadr GetImageWidth,0x44E8F014+1
        defadr GetImageHeight,0x44E8F02C+1
        defadr GetThemeColor,0x45062EF8+1
        defadr DispObject_SetLayerColor,0x44E8D2F0+1
        defadr DispObject_SetThemeImage,0x44E8CDB8+1
        defadr DispObject_WindowSetSize,0x44E8BCCC+1
        defadr DispObject_InvalidateRect,0x44E8A2A8+1
        defadr DispObject_SetAnimation,0x44E8D348+1
        defadr CreateListMenu,0x44D64144+1
        defadr ListMenu_SetItemCount,0x44D64300+1
        defadr ListMenu_SetCursorToItem,0x44D642D0+1
        defadr ListMenu_GetSelectedItem,0x44D642E4+1
        defadr ListMenu_SetOnMessage,0x44D64430+1
        defadr ListMenu_SetHotkeyMode,0x44D6445C+1
        defadr GUIonMessage_GetMsg,0x44D64978+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D649A4+1
        defadr GUIonMessage_SetMenuItemText,0x44D649B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x44D649F4+1
        defadr GUIObject_SetTitleType,0x44D396AC+1
        defadr GUIObject_SetTitleText,0x44D396C4+1
        defadr GUIObject_SetTitleTextAlign,0x44D39700+1
        defadr GUIObject_SetSecondRowTitleText,0x44D396E0+1
        defadr GUIObject_SetTitleBackgroundImage,0x44D655DC+1
        defadr GUIObject_SetStyle,0x44D39618+1
        defadr GUIObject_Destroy,0x44EA6538+1
        defadr GUIObject_Show,0x44D395C8+1
        defadr DispObject_SetStyle,0x44E8D374+1
        defadr DispObject_SetTitleType,0x44E8BFCC+1
        defadr DispObject_SetTitleText,0x44E8BEB0+1
        defadr DispObject_SetSecondRowTitleText,0x44E8BEF8+1
        defadr GUIObject_SoftKeys_SetText,0x44D3ADF0+1
        defadr GUIObject_SoftKeys_SetInfoText,0x44D3ADB4+1
        defadr GUIObject_SoftKeys_SetAction,0x44D3AD08+1
        defadr MediaPlayer_SoftKeys_SetText,0x44C7CE24+1
        defadr MediaPlayer_SoftKeys_SetAction,0x44C7CDF0+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x44C7CE40+1
        defadr MediaPlayer_SoftKeys_Validate,0x44C7CDD0+1
        defadr CANVAS_Get_GviGC,0x447361D0+1
        defadr GVI_BitBlt,0x44827E24+1
        defadr GVI_StretchBlt,0x44827F94+1
        defadr GVI_TransformBlt,0x44828040+1
        defadr GVI_CreatePen,0x44827484+1
        defadr GVI_CreateDashedPen,0x44B08BD0+1
        defadr GVI_CreateSolidBrush,0x44827410+1
        defadr GVI_Delete_GVI_Object,0x44826E6C+1
        defadr GVI_DrawEllipse,0x44827954+1
        defadr GVI_DrawLine,0x448284DC+1
        defadr GVI_DrawLines,0x44828974+1
        defadr GVI_DrawPolyLine,0x448289FC+1
        defadr GVI_DrawRectangle,0x44828BE4+1
        defadr GVI_DrawRoundRect,0x44827D18+1
        defadr GVI_DrawSolidLines,0x448285E0+1
        defadr GVI_DrawSolidPolyLine,0x448287BC+1
        defadr GVI_DrawSolidRectangle,0x4482887C+1
        defadr GVI_FillEllipse,0x44827BD0+1
        defadr GVI_FillPolygon,0x448283D8+1
        defadr GVI_FillRectangle,0x44828AF4+1
        defadr GVI_FillRectangles,0x44828B54+1
        defadr GVI_FillSolidEllipse,0x44827C68+1
        defadr GVI_FillSolidRectangle,0x44828BA0+1
        defadr GVI_FillSolidRoundRect,0x44827E00+1
        defadr GVI_FillSolidTriangle,0x44828350+1
        defadr GC_CreateMemoryGC,0x44D42744+1
        defadr GC_FreeGC,0x44D42800+1
        defadr GVI_CreateBitmap,0x44827558+1
        defadr GVI_CreateMemoryGC,0x44828CB4+1
        defadr GVI_DeleteMemoryGC,0x44869158+1
        defadr MediaPlayer_State_Get,0x44F69D64+1
        defadr MediaPlayer_Audio_ActionBack,0x44F6245C+1
        defadr MediaPlayer_Audio_ActionLongBack,0x44F5D270+1
        defadr pg_MediaPlayer_Audio_Bk_PrevEvent,0x44F5F068+1
        defadr pg_MediaPlayer_Audio_Bk_CancelEvent,0x44F5F0AC+1
        defadr pg_MediaPlayer_Audio_Bk_ExitEvent,0x44F5F040+1
        defadr Call_MM_BrowserAlbumsMain,0x4504C774+1
        defadr pg_MM_Browser_Toplevel_Bk_Start,0x45051C20+1
        defadr pg_MM_Browser_Toplevel_Bk_Cancel,0x45051CB4+1
        defadr pg_MM_Browser_Toplevel_Bk_Destroy,0x45051CEC+1
        defadr MediaPlayer_Audio_OnCreate,0x44E2C8DC+1
        defadr MediaPlayer_Audio_OnClose,0x44E2C9B8+1
        defadr MediaPlayer_Audio_Rename,0x44F5E398+1
        defadr MediaPlayer_NowPlaying_OnCreate,0x44E2DE3C+1
        defadr MediaPlayer_NowPlaying_OnClose,0x44E2DF00+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x44E2DF44+1
        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x44F5F328+1
        defadr pg_MEDIAPLAYER_NEW_TRACK_EVENT,0x44F5F3A8+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x44F60880+1

;==================== MEDIAPLAYER =============================

        EXTERN New_MediaPlayer_Audio_OnCreate
        EXTERN New_MediaPlayer_Audio_OnRedraw
        EXTERN New_MediaPlayer_PlayQueue_SetTitle
        EXTERN New_MediaPlayer_NowPlaying_OnCreate
        EXTERN New_MediaPlayer_NowPlaying_OnRedraw

        EXTERN New_UI_MEDIAPLAYER_NEW_TRACK_EVENT
        EXTERN New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        EXTERN New_UI_MEDIAPLAYER_CREATED_EVENT

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

        RSEG    PATCH_MediaPlayer_Audio_OnRedraw
        DATA
        DCD     New_MediaPlayer_Audio_OnRedraw

        RSEG    PATCH_MediaPlayer_NowPlaying_OnCreate
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnCreate

        RSEG    PATCH_MediaPlayer_NowPlaying_OnRedraw
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnRedraw

;==================== Other GUI =============================

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

        EXTERN New_MediaPlayer_PlayQueue_SetStyle

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
        LDR	R3, =0x44E2CAB2+1
	BX      R3

;====================OnClose Book=============================

        EXTERN  New_AudioPlayerBook_onClose

        RSEG    PATCH_AudioPlayerBook_onClose
	CODE16
	LDR	R3, =audioplayer_onclose
	BX	R3

        RSEG  CODE
        CODE16
audioplayer_onclose:
        LDR     R0, [SP,#0]
        BL      New_AudioPlayerBook_onClose
        LDR     R0, [SP,#0]
        LDR	R3, =0x44F64380+1
	BLX	R3
        LDR     R1, [R4,#0x18]
        LDR	R3, =0x44F5CDFC+1
	BX      R3

;====================NowPlaying=============================

        EXTERN New_MediaPlayer_NowPlaying_SetSize
        EXTERN New_MediaPlayer_Audio_SetStyle

        RSEG    PATCH_MediaPlayer_NowPlaying_SetSize
	CODE16
        LDR	R3, =mp_nowplaying_setsize
	BX	R3

        RSEG  CODE
        CODE16
mp_nowplaying_setsize:
        LDR     R0, [R4,#0x74]
        BL      New_MediaPlayer_NowPlaying_SetSize
        LDR	R3, =0x44E2CD8C+1
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
        LDR	R3, =0x44E2C97C+1
	BX      R3

;==================== SoftKeys Action ===========================

        EXTERN New_MediaPlayer_SoftKeys
        EXTERN New_MediaPlayer_SoftKeys_MyMusic

        RSEG    PATCH_MediaPlayer_SoftKeys_Minimize
	CODE16
        LDR	R3, =mp_softkeys_minim
	BX	R3

        RSEG    PATCH_MediaPlayer_SoftKeys
	CODE16
        LDR	R3, =mp_softkeys
	BX	R3

        RSEG  CODE
        CODE16
mp_softkeys_minim:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys_MyMusic
        LDR	R3, =0x44F5D50C+1
	BX      R3

mp_softkeys:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys
        LDR     R5, =MediaPlayer_Audio_Rename
	LDR	R0, [R4,#0x1C]
        BL	MP_Validate
        CMP	R0, #0
	BEQ	not_valid_exit
        LDR	R3, =0x44F5D606+1
	BX      R3

not_valid_exit:
        LDR     R3, =0x44F5D612+1
	BX      R3

MP_Validate:
        LDR     R3, =MediaPlayer_SoftKeys_Validate
	BX      R3

;==================== Dynamic Menu =============================

        RSEG    PATCH_MEDIAPLAYER_MENU
	CODE16
	LDR	R3, =start_mediaplayer_audio
	BX      R3

        RSEG  CODE
        CODE16
start_mediaplayer_audio:
        BNE     next_
        MOV     R0, #MEDIAPLAYERKEY_PRESSED_EVENT
        BL      UI_Event
        POP     {R4,R5,PC}
next_:
        LDR     R3, =0x44F67AE4+1
	BX      R3

;====================TopLevel Browser=============================

        EXTERN New_Toplevel_Bk_NowPlaying_PreviousEvent
        EXTERN New_MainMenu_TopLevelBrowser_ActionBack
        EXTERN New_MainMenu_TopLevelBrowser
        EXTERN New_ListText_TopLevelBrowser
        EXTERN New_ListIcon_TopLevelBrowser
        EXTERN New_ListLink_TopLevelBrowser
        EXTERN New_ListText_Track

        RSEG    PATCH_Toplevel_Bk_NowPlaying_PreviousEvent
        DATA
        DCD     New_Toplevel_Bk_NowPlaying_PreviousEvent

        RSEG    PATCH_GUI_TOPLEVEL_ACTION_BACK
        DATA
        DCD     New_MainMenu_TopLevelBrowser_ActionBack

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
        LDR     R3, =0x450519FA+1
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
        LDR     R3, =0x45051AE8+1
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
        LDR     R3, =0x45051AFA+1
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
        LDR     R3, =0x45052464+1
	BX      R3

        END
