//K800_R8BF003
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x44E4FD44+1
        defadr memfree,0x44E4FD70+1
        defadr memset,0x20003094
        defadr memcpy,0x443FCB18
        defadr memcmp,0x2000310C
        defadr debug_printf,0x4423F208+1
        defadr sprintf,0x4467A294+1
        defadr snwprintf,0x4467A85C+1
        defadr sscanf,0x443EB2A4+1
        defadr _fopen,0x44F945F0+1
        defadr fclose,0x44F95BBC+1
        defadr fread,0x44F95E44+1
        defadr fwrite,0x44F96010+1
        defadr lseek,0x44F961B8+1
        defadr _wstat,0x4498B754+1
        defadr fputs,0x452BCE40+1
        defadr fstat,0x44F94F84+1
        defadr FileDelete,0x44F950C8+1
        defadr w_diropen,0x450971A4+1
        defadr w_chdir,0x45095030+1
        defadr w_fstat,0x4498B754+1
        defadr w_dirread,0x452BD6E8+1
        defadr w_dirclose,0x45097510+1
        defadr FSX_IsFileExists,0x44FD8040+1
        defadr FSX_MakeFullPath,0x44F97808+1
        defadr FSX_FreeFullPath,0x44F97894+1
        defadr get_bid,0x44435AF4
        defadr current_process,0x44435ABC
        defadr get_envp,0x443ED0D0+1
        defadr set_envp,0x443ED0E4+1
        defadr wstrcpy,0x44F549A8+1
        defadr wstrncpy,0x44F549C0+1
        defadr wstrcat,0x44F549EC+1
        defadr wstrncat,0x44F54A08+1
        defadr wstrcmp,0x44F54978+1
        defadr wstrlen,0x44F54964+1
        defadr str2wstr,0x44F55C2C+1
        defadr strcmp,0x4467A640+1
        defadr strlen,0x4467A69C+1
        defadr wstr2strn,0x44F54A84+1
        defadr wstrrchr,0x4467B068+1
        defadr wstrcmpi,0x44F55D88+1
        defadr wstrwstr,0x4467B0A8+1
        defadr itow,0x453AAED0+1
        defadr count_digit,0x453AB1F0+1
        defadr TextID_Create,0x45446A40+1
        defadr TextID_CreateIntegerID,0x4544678C+1
        defadr TextID_GetLength,0x45446CA4+1
        defadr TextID_Destroy,0x45446C08+1
        defadr TextID_CreateFromTextIterator,0x454468CC+1
        defadr strftime,0x4504ADA4+1
        defadr MetaData_Desc_Create,0x4533EA14+1
        defadr MetaData_Desc_GetCoverInfo,0x4533EBC0+1
        defadr MetaData_Desc_Destroy,0x4533EAD4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x44F4DE88+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x44F4DEF0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x44F4DFA0+1
        defadr ImageID_Free,0x44F4A080+1
        defadr ImageID_GetIndirect,0x44F49800+1
        defadr FreeBook,0x453AEDF0+1
        defadr BookObj_CallPage,0x453AE650+1
        defadr BookObj_GotoPage,0x453AE550+1
        defadr GetImageWidth,0x4545DD18+1
        defadr GetImageHeight,0x4545DD2C+1
        defadr get_DisplayGC,0x45461760+1
        defadr GC_PutChar,0x45462238+1
        defadr Display_GetHeight,0x45476E80+1
        defadr Display_GetWidth,0x45476E8C+1
        defadr MessageBox,0x453B9A08+1
        defadr GetThemeColor,0x45483290+1
        defadr DrawRect,0x4545CA24+1
        defadr SetFont,0x4545D780+1
        defadr DrawString,0x4545CD24+1
        defadr GC_DrawImage,0x4545CC18+1
        defadr GUIObject_GetDispObject,0x45463CE4+1
        defadr DispObject_SetLayerColor,0x4545BEE4+1
        defadr DispObject_SetTitleType,0x45458E3C+1
        defadr DispObject_SetSecondRowTitleText,0x45458D9C+1
        defadr DispObject_InvalidateRect,0x4545A060+1
        defadr DispObject_WindowSetSize,0x4545B0A0+1
        defadr DispObject_SetStyle,0x4545C360+1
        defadr DispObject_SetTitleText,0x45458D78+1
        defadr GUIonMessage_GetMsg,0x4541E5B4+1
        defadr GUIonMessage_GetCreatedItemIndex,0x4541E5D8+1
        defadr GUIonMessage_SetMenuItemText,0x4541E5E4+1
        defadr GUIonMessage_SetMenuItemIcon,0x4541E65C+1
        defadr ListMenu_GetSelectedItem,0x4541DB04+1
        defadr GUIObject_Destroy,0x45463C74+1
        defadr CreateListMenu,0x4541D8E8+1
        defadr ListMenu_SetItemCount,0x4541DB18+1
        defadr ListMenu_SetCursorToItem,0x4541DAF0+1
        defadr ListMenu_SetOnMessage,0x4541DC2C+1
        defadr ListMenu_SetHotkeyMode,0x4541DC58+1
        defadr GUIObject_SetTitleType,0x45464344+1
        defadr GUIObject_SetTitleText,0x45464360+1
        defadr GUIObject_SetTitleTextAlign,0x454643B4+1
        defadr GUIObject_SetSecondRowTitleText,0x4546437C+1
        defadr GUIObject_SetStyle,0x45463F34+1
        defadr GUIObject_Show,0x45463EE4+1
        defadr GUIObject_SetFocus,0x45463E90+1
        defadr GUIObject_SoftKeys_SetAction,0x454806E0+1
        defadr GUIObject_SoftKeys_SetText,0x45480758+1
        defadr GUIObject_SoftKeys_SetInfoText,0x45480744+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x45480838+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x45480A7C+1
        defadr GUIObject_SetTitleBackgroundImage,0x454643F0+1
        defadr DispObject_SoftKeys_RemoveBackground,0x4547D5CC+1
        defadr List_Create,0x452BF5F0+1
        defadr List_Destroy,0x452BF62C+1
        defadr List_DestroyElements,0x452BFA04+1
        defadr List_InsertLast,0x452BF7A8+1
        defadr List_Get,0x452BF8C4+1
        defadr List_GetCount,0x452BF898+1
        defadr manifest_GetParam,0x4537F700+1
        defadr Timer_ReSet,0x453AB5B4+1
        defadr Timer_Set,0x453AB580+1
        defadr Timer_Kill,0x453AB60C+1
        defadr CANVAS_Get_GviGC,0x44723EF8+1
        defadr GVI_BitBlt,0x44B1D4E8+1
        defadr GVI_StretchBlt,0x44B1D654+1
        defadr GVI_TransformBlt,0x44B1D708+1
        defadr GVI_CreatePen,0x44B1C70C+1
        defadr GVI_CreateDashedPen,0x44B1C75C+1
        defadr GVI_CreateSolidBrush,0x44B1C600+1
        defadr GVI_Delete_GVI_Object,0x44B1BFC0+1
        defadr GVI_DrawEllipse,0x44B1CDE0+1
        defadr GVI_DrawLine,0x44B1DCB4+1
        defadr GVI_DrawLines,0x44B1E3C0+1
        defadr GVI_DrawPolyLine,0x44B1E454+1
        defadr GVI_DrawRectangle,0x44B1E6D8+1
        defadr GVI_DrawRoundRect,0x44B1D320+1
        defadr GVI_DrawSolidLines,0x44B1DF74+1
        defadr GVI_DrawSolidPolyLine,0x44B1E190+1
        defadr GVI_DrawSolidRectangle,0x44B1E248+1
        defadr GVI_FillEllipse,0x44B1D1B8+1
        defadr GVI_FillPolygon,0x44B1DB28+1
        defadr GVI_FillRectangle,0x44B1E564+1
        defadr GVI_FillRectangles,0x44B1E5FC+1
        defadr GVI_FillSolidEllipse,0x44B1D284+1
        defadr GVI_FillSolidRectangle,0x44B1E674+1
        defadr GVI_FillSolidRoundRect,0x44B1D474+1
        defadr GVI_FillSolidTriangle,0x44B1DA98+1
        defadr GC_CreateMemoryGC,0x45461770+1
        defadr GC_FreeGC,0x45461848+1

        defadr UI_Event,0x453AD25C+1
        defadr DispObject_SetAnimation,0x4545BF98+1
        defadr DispObject_SetTitleTextColor,0x454590C0+1
        defadr DispObject_SetTitleBackgroundImage,0x454590E0+1
        defadr DispObject_SetListBackgroundImage,0x45410824+1
        defadr DispObject_SetBackgroundImage,0x454109A4+1
        defadr DispObject_SetListTextColor,0x454109CC+1
        defadr DispObject_ListMenu_SetItemStyle,0x454052E8+1
        defadr BookObj_GetBookID,0x453AEEB0+1
        defadr Shortcut_Run,0x4548D810+1

        defadr pg_MM_Browser_Toplevel_Bk_Start,0x45345064+1
        defadr pg_MM_Browser_Toplevel_Bk_Cancel,0x45345094+1
        defadr pg_MM_Browser_Toplevel_Bk_Destroy,0x453450B8+1
        defadr Call_MM_BrowserAlbumsMain,0x4533FD04+1

        defadr MediaPlayer_SoftKeys_Validate,0x4503FD98+1
        defadr MediaPlayer_SoftKeys_SetText,0x4503FDE8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x4503FDB4+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x4503FE74+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x4503FE04+1

        defadr pg_MediaPlayer_Audio_Bk_PrevEvent,0x45042D0C+1
        defadr pg_MediaPlayer_Audio_Bk_CancelEvent,0x45042D3C+1
        defadr pg_MediaPlayer_Audio_Bk_ExitEvent,0x45042CF8+1

        defadr MediaPlayer_State_Get,0x4504E610+1
        defadr MediaPlayer_Audio_ActionBack,0x450464F4+1
        defadr MediaPlayer_Audio_ActionLongBack,0x45041538+1

        defadr MediaPlayer_Audio_OnCreate,0x4503E068+1
        defadr MediaPlayer_Audio_OnClose,0x4503E134+1

        defadr MediaPlayer_NowPlaying_OnCreate,0x4503EFA0+1
        defadr MediaPlayer_NowPlaying_OnClose,0x4503F09C+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x4503F0D0+1

        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x4504309C+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x45044A38+1
        defadr pg_MEDIAPLAYER_NEW_TRACK_EVENT,0x450430F4+1

;==================== MEDIAPLAYER =============================

        EXTERN  New_MediaPlayer_Audio_OnCreate
        EXTERN  New_MediaPlayer_Audio_OnClose
        EXTERN  New_MediaPlayer_Audio_OnRedraw
        EXTERN  New_MediaPlayer_PlayQueue_SetStyle
        EXTERN  New_MediaPlayer_NowPlaying_OnCreate
        EXTERN  New_MediaPlayer_NowPlaying_OnClose
        EXTERN  New_MediaPlayer_NowPlaying_OnRedraw

        EXTERN  New_UI_MEDIAPLAYER_NEW_TRACK_EVENT
        EXTERN  New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        EXTERN  New_UI_MEDIAPLAYER_CREATED_EVENT

        RSEG    PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT
        DATA
        DCD     New_UI_MEDIAPLAYER_NEW_TRACK_EVENT

        RSEG    PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        DATA
        DCD     New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT

        RSEG    PATCH_UI_MEDIAPLAYER_CREATED_EVENT
        DATA
        DCD     New_UI_MEDIAPLAYER_CREATED_EVENT

        RSEG    PATCH_MediaPlayer_Audio_OnRedraw
        DATA
        DCD     New_MediaPlayer_Audio_OnRedraw

        RSEG    PATCH_MediaPlayer_Audio_OnCreate
        DATA
        DCD     New_MediaPlayer_Audio_OnCreate

        RSEG    PATCH_MediaPlayer_NowPlaying_OnCreate
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnCreate

        RSEG    PATCH_MediaPlayer_NowPlaying_OnRedraw
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnRedraw

;======================= GUI ============================

        EXTERN New_MediaPlayer_NowPlaying_SetSize
        EXTERN New_MediaPlayer_Audio_SetStyle

        RSEG    PATCH_GUI_PLAYMODE
	CODE16
        LDR     R0, [R4,#0x20]
        MOV     R1, #9

        RSEG    PATCH_GUI_STEREOWIDENING
	CODE16
        LDR     R0, [R4,#0x20]
        MOV     R1, #9

        RSEG    PATCH_GUI_MEDIAPLAYER
	CODE16
        LDR	R3, =mp_gui_player
	BX	R3

        RSEG  CODE
        CODE16
mp_gui_player:
        MOV     R1, #1
        ADD     R0, R4, #0
        LDR	R3, =GUIObject_SetFocus
	BLX     R3
        ADD     R0, R4, #0
        LDR	R3, =GUIObject_SoftKeys_RemoveBackground
	BLX     R3
        ADD     R0, R4, #0
        ADD     SP, #0x10
        POP     {R4-R7,PC}

        RSEG    PATCH_MediaPlayer_NowPlaying_SetSize
	CODE16
        LDR	R3, =mp_nowplaying_setsize
	BX	R3

        RSEG  CODE
        CODE16
mp_nowplaying_setsize:
        LDR     R0, [R7,#0x70]
        BL      New_MediaPlayer_NowPlaying_SetSize
        LDR	R3, =0x4503E342+1
	BX      R3

        RSEG    PATCH_MediaPlayer_Audio_SetStyle
        CODE16
	LDR	R3, =mp_audio_setstyle
	BX	R3

        RSEG  CODE
        CODE16
mp_audio_setstyle:
        STRH    R0, [R5,#0x1C]
        ADD     R0, R4, #0
        BL      New_MediaPlayer_Audio_SetStyle
        LDR	R3, =0x4503E10A+1
	BX      R3

;====================PlayQueue=============================

        EXTERN  New_MediaPlayer_PlayQueue_SetTitle

        RSEG    PATCH_MediaPlayer_PlayQueue_SetTitle
 	CODE16
        LDR	R3, =mp_playqueue_settitle
 	BX	R3

        RSEG  CODE
        CODE16
mp_playqueue_settitle:
        LDR     R0, [R5, #0]
        BL      New_MediaPlayer_PlayQueue_SetTitle
        LDR     R0, [R5, #0]
        MOV     R1, #0
        MOV     R2, #0
        LDR	R3, =0x4547CFDC+1
 	BLX     R3
        LDR	R3, =0x4503E01A+1
 	BX      R3

        RSEG    PATCH_MediaPlayer_PlayQueue_SetStyle
 	CODE16
        LDR	R3, =mp_playqueue_setstyle
 	BX	R3

        RSEG  CODE
        CODE16
 mp_playqueue_setstyle:
        LDR     R0, [R7,#0x68]
        BL      New_MediaPlayer_PlayQueue_SetStyle
        LDR	R3, =0x4503E1BE+1
 	BX      R3

        ;RSEG    PATCH_MediaPlayer_PlayQueue_RemoveStyle
	;CODE16
	;NOP
	;NOP
	;NOP
	;NOP

;====================OnClose Book=============================

        EXTERN  New_AudioPlayerBook_onClose

        RSEG    PATCH_AudioPlayerBook_onClose
	CODE16
	LDR	R3, =audioplayer_onclose
	BX	R3

        RSEG    CODE
        CODE16
audioplayer_onclose:
        BL      New_AudioPlayerBook_onClose
        ADD     R0, #0x18
        LDR	R3, =MediaPlayer_State_Get
	BLX	R3
        MOV     R1, #0xB9
        LDR	R3, =0x45041110+1
	BX      R3

;==================== SoftKeys Action ===========================

        EXTERN  New_MediaPlayer_SoftKeys
        EXTERN  New_MediaPlayer_SoftKeys_MyMusic

        RSEG    PATCH_MediaPlayer_SoftKeys_MyMusic
	CODE16
        LDR	R3, =mp_softkeys_mymusic
	BX	R3

        RSEG    PATCH_MediaPlayer_SoftKeys
	CODE16
        LDR	R3, =mp_softkeys
	BX	R3

        RSEG    CODE
        CODE16
mp_softkeys_mymusic:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys_MyMusic
        LDR     R0, [R4,#0x1C]
        BL	MP_Validate
        CMP     R0, #0
        BEQ     not_valid_m
        LDR	R3, =0x450416A4+1
	BX      R3

not_valid_m:
        LDR	R3, =0x450416B0+1
	BX      R3

mp_softkeys:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys
	LDR	R0, [R4,#0x1C]
        BL	MP_Validate
        CMP	R0, #0
	BEQ	not_valid_s
        LDR	R3, =0x4504174A+1
	BX      R3
not_valid_s:
        LDR     R3, =0x45041756+1
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
        BNE     _next
        MOV     R0, #MEDIAPLAYERKEY_PRESSED_EVENT
        BL      _UI_Event
        POP     {R4,R5,PC}
_next:
        LDR     R3, =0x4504C74A+1
	BX      R3

_UI_Event:
        LDR     R3, =UI_Event
	BX      R3

;====================TopLevel Parts=============================

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

        RSEG    PATCH_GUI_MM_ARTIST
	CODE16
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_ALBUM
	CODE16
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_PLAYLIST1
	CODE16
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_PLAYLIST2
	CODE16
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_TRACKS1
	CODE16
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_NOSTYLE
	CODE16
	NOP
	NOP

        RSEG    PATCH_FIX_TITLE
	CODE16
	NOP
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_BROWSER_ONLINE_LINK
	CODE16
	NOP
	NOP
	MOV     R0, #0

        RSEG    PATCH_GUI_MM_BROWSER_LISTLINK
	CODE16
	LDR	R3, =New_ListLink_TopLevelBrowser
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_STYLE
	CODE16
	LDR	R3, =menu_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
menu_toplevel_browser:
        BL      New_MainMenu_TopLevelBrowser
        LDR     R3, =0x45344EF0+1
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
        ADD     R1, R7, #0
        ADD     R0, R5, #0
        BL      New_ListText_TopLevelBrowser
        LDR     R3, =0x45344FE8+1
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_LISTICON
	CODE16
	LDR	R3, =listicon_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
listicon_toplevel_browser:
        ADD     R1, R7, #0
        ADD     R0, R5, #0
        BL      New_ListIcon_TopLevelBrowser
        LDR     R3, =0x45344FF8+1
	BX      R3

        RSEG    PATCH_GUI_MM_TRACKS2
	CODE16
	LDR	R3, =list_tracks_number
	BX      R3

        RSEG  CODE
        CODE16
list_tracks_number:
        LDR     R2, =0xFFFF
        MOV     R1, #0
        ADD     R0, R5, #0
        LDR     R3, =TextID_Create
	BLX     R3
        LDR     R1, [SP,#4]
        BL      New_ListText_Track
        LDR     R3, =0x453458C6+1
	BX      R3

        END
