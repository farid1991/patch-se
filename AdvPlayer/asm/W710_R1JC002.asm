//W710_R1JC002
#include "target.h"

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44D2EA44+1
        defadr memfree,0x44D2EA70+1
        defadr memset,0x4414535C
        defadr memcpy,0x442D35C0
        defadr memcmp,0x20003118
        defadr sscanf,0x442C1FC4+1
        defadr sprintf,0x445429DC+1
        defadr snwprintf,0x44542FA4+1
        defadr debug_printf,0x44239AE0+1
        defadr set_envp,0x442C3CD4+1
        defadr get_envp,0x442C3CC0+1
        defadr wstrcmp,0x44E33158+1
        defadr wstrcmpi,0x44E34568+1
        defadr wstrcpy,0x445436B0+1
        defadr wstrcat,0x44E331CC+1
        defadr wstrlen,0x44E33144+1
        defadr wstrrchr,0x445437B0+1
        defadr wstrnlwr,0x450BDE20+1
        defadr wstrwstr,0x445437F0+1
        defadr strncmp,0x44542E20+1
        defadr strcmp,0x44542D88+1
        defadr strlen,0x44542DE4+1
        defadr str2wstr,0x44E3440C+1
        defadr str2wstrn,0x44E33238+1
        defadr itow,0x45286AF0+1
        defadr count_digit,0x45286E10+1
        defadr FSX_IsFileExists,0x44EB598C+1
        defadr FileDelete,0x44E73B4C+1
        defadr _fopen,0x44E7306C+1
        defadr fstat,0x44E73A08+1
        defadr fread,0x44E748CC+1
        defadr lseek,0x44E74C48+1
        defadr fwrite,0x44E74A98+1
        defadr fclose,0x44E74650+1
        defadr ImageID_Free,0x44E288FC+1
        defadr ImageID_Get,0x44E27E58+1
        defadr ImageID_GetIndirect,0x44E2807C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x44E2C6E8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x44E2C750+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x44E2C800+1
        defadr TextID_Create,0x4532EDA0+1
        defadr TextID_CreateIntegerID,0x4532EAE8+1
        defadr TextID_GetLength,0x4532F010+1
        defadr TextID_Destroy,0x4532EF70+1
        defadr TextID_CreateFromTextIterator,0x4532EC2C+1
        defadr strftime,0x44F2839C+1
        defadr get_DisplayGC,0x4534A1B8+1
        defadr GC_PutChar,0x4534AC4C+1
        defadr SetFont,0x45346174+1
        defadr DrawString,0x45345718+1
        defadr DrawRect,0x45345418+1
        defadr GetImageWidth,0x45346728+1
        defadr GetImageHeight,0x4534673C+1
        defadr Display_GetHeight,0x4535FA50+1
        defadr Display_GetWidth,0x4535FA5C+1
        defadr DispObject_SetStyle,0x45344D8C+1
        defadr DispObject_SetTitleText,0x453416BC+1
        defadr DispObject_WindowSetSize,0x45343AC4+1
        defadr DispObject_InvalidateRect,0x453429A0+1
        defadr DispObject_SetLayerColor,0x45344910+1
        defadr DispObject_SetThemeImage,0x453444E8+1
        defadr DispObject_SetTitleType,0x45341780+1
        defadr DispObject_SetSecondRowTitleText,0x453416E0+1
        defadr GetThemeColor,0x4536BFC4+1
        defadr GUIObject_SoftKeys_SetAction,0x453693C4+1
        defadr GUIObject_SoftKeys_SetText,0x4536943C+1
        defadr GUIObject_SoftKeys_SetInfoText,0x45369428+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x4536951C+1
        defadr MediaPlayer_SoftKeys_SetAction,0x44F1D15C+1
        defadr MediaPlayer_SoftKeys_SetText,0x44F1D190+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x44F1D1AC+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x44F1D21C+1
        defadr MediaPlayer_SoftKeys_Validate,0x44F1D140+1
        defadr MetaData_Desc_Create,0x4521B788+1
        defadr MetaData_Desc_HasCover,0x4521B898+1
        defadr MetaData_Desc_GetCoverInfo,0x4521B8BC+1
        defadr MetaData_Desc_Destroy,0x4521B814+1
        defadr w_diropen,0x44F75BBC+1
        defadr w_chdir,0x44F73A44+1
        defadr w_fstat,0x4483B444+1
        defadr w_dirread,0x4519C188+1
        defadr w_dirclose,0x44F75F18+1
        defadr FreeBook,0x4528A828+1
        defadr UI_Event,0x45288CA4+1
        defadr BookObj_CallPage,0x4528A088+1
        defadr BookObj_GotoPage,0x45289F88+1
        defadr BookObj_ReturnPage,0x4528A0F0+1
        defadr CreateListMenu,0x45305A90+1
        defadr ListMenu_SetItemCount,0x45305CC0+1
        defadr ListMenu_GetSelectedItem,0x45305CAC+1
        defadr ListMenu_SetCursorToItem,0x45305C98+1
        defadr ListMenu_SetOnMessage,0x45305DD4+1
        defadr ListMenu_SetHotkeyMode,0x45305E00+1
        defadr GUIonMessage_GetMsg,0x4530678C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x453067B0+1
        defadr GUIonMessage_SetMenuItemText,0x453067BC+1
        defadr GUIonMessage_SetMenuItemIcon,0x45306834+1
        defadr GUIObject_SetTitleType,0x4534CDE4+1
        defadr GUIObject_SetTitleText,0x4534CE00+1
        defadr GUIObject_SetTitleTextAlign,0x4534CE54+1
        defadr GUIObject_SetSecondRowTitleText,0x4534CE1C+1
        defadr GUIObject_SetTitleBackgroundImage,0x4534CE90+1
        defadr GUIObject_SetStyle,0x4534C940+1
        defadr GUIObject_Show,0x4534C8F0+1
        defadr GUIObject_Destroy,0x4534C680+1

        defadr manifest_GetParam,0x4525C908+1
        defadr List_Create,0x4519DFE4+1
        defadr List_InsertFirst,0x4519E16C+1
        defadr List_InsertLast,0x4519E17C+1
        defadr List_Destroy,0x4519E018+1
        defadr List_DestroyElements,0x4519E3F8+1
        defadr List_Get,0x4519E2B8+1
        defadr List_GetCount,0x4519E28C+1

        defadr GC_CreateMemoryGC,0x4534A1C8+1
        defadr GC_FreeGC,0x4534A2A0+1
        defadr GC_DrawFRect,0x4534B360+1
        defadr CANVAS_Get_GviGC,0x445E4BAC+1
        defadr GVI_BitBlt,0x449DD3E8+1
        defadr GVI_StretchBlt,0x449DD554+1
        defadr GVI_TransformBlt,0x449DD608+1
        defadr GVI_CreatePen,0x449DC60C+1
        defadr GVI_CreateDashedPen,0x449DC65C+1
        defadr GVI_CreateSolidBrush,0x449DC500+1
        defadr GVI_Delete_GVI_Object,0x449DBEC0+1
        defadr GVI_DrawEllipse,0x449DCCE0+1
        defadr GVI_DrawLine,0x449DDBB4+1
        defadr GVI_DrawLines,0x449DE2C0+1
        defadr GVI_DrawPolyLine,0x449DE354+1
        defadr GVI_DrawRectangle,0x449DE5D8+1
        defadr GVI_DrawRoundRect,0x449DD220+1
        defadr GVI_DrawSolidLines,0x449DDE74+1
        defadr GVI_DrawSolidPolyLine,0x449DE090+1
        defadr GVI_DrawSolidRectangle,0x449DE148+1
        defadr GVI_FillEllipse,0x449DD0B8+1
        defadr GVI_FillPolygon,0x449DDA28+1
        defadr GVI_FillRectangle,0x449DE464+1
        defadr GVI_FillRectangles,0x449DE4FC+1
        defadr GVI_FillSolidEllipse,0x449DD184+1
        defadr GVI_FillSolidRectangle,0x449DE574+1
        defadr GVI_FillSolidRoundRect,0x449DD374+1
        defadr GVI_FillSolidTriangle,0x449DD998+1
        defadr GVI_CreateBitmap,0x449DC740+1
        defadr GVI_CreateMemoryGC,0x449DE780+1
        defadr GVI_DeleteMemoryGC,0x44717774+1
        defadr Timer_ReSet,0x452871D4+1
        defadr Timer_Set,0x452871A0+1
        defadr Timer_Kill,0x4528722C+1

        defadr BookObj_GetBookID,0x4528A8E8+1
        defadr GUIObject_GetDispObject,0x4534C6F0+1
        defadr DispObject_SetAnimation,0x453449C4+1
        defadr Shortcut_Run,0x4536E618+1
        defadr MessageBox,0x452956CC+1

        defadr GUI_GetSomething,0x45306354+1
        defadr Call_MM_BrowserTracksMain,0x452224E8+1
        defadr Call_MM_BrowserAlbumsMain,0x4521C834+1
        defadr pg_MM_Browser_Toplevel_Bk_Start,0x452220E0+1
        defadr pg_MM_Browser_Toplevel_Bk_Cancel,0x45222138+1
        defadr pg_MM_Browser_Toplevel_Bk_Destroy,0x4522215C+1
        defadr pg_MM_Browser_Toplevel_Bk_AlbumsPage_ExitEvent,0x4521D4D8+1

        defadr MediaPlayer_State_Get,0x44F2BC34+1
        defadr MediaPlayer_Audio_ActionBack,0x44F23C94+1
        defadr MediaPlayer_Audio_ActionLongBack,0x44F1EA4C+1
        defadr MediaPlayer_Audio_OnCreate,0x44F1AD00+1
        defadr MediaPlayer_Audio_OnClose,0x44F1ADD0+1
        defadr MediaPlayer_NowPlaying_OnCreate,0x44F1C25C+1
        defadr MediaPlayer_NowPlaying_OnClose,0x44F1C358+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x44F1C394+1
        defadr pg_MediaPlayer_Audio_Bk_PrevEvent,0x44F2028C+1
        defadr pg_MediaPlayer_Audio_Bk_CancelEvent,0x44F202BC+1
        defadr pg_MediaPlayer_Audio_Bk_ExitEvent,0x44F20274+1
        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x44F20620+1
        defadr pg_MEDIAPLAYER_NEW_TRACK_EVENT,0x44F2067C+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x44F212FC+1

;==================== MEDIAPLAYER =============================

        EXTERN New_MediaPlayer_Audio_OnCreate
        EXTERN New_MediaPlayer_Audio_OnClose
        EXTERN New_MediaPlayer_Audio_OnRedraw
        EXTERN New_MediaPlayer_PlayQueue_SetStyle
        EXTERN New_MediaPlayer_NowPlaying_OnCreate
        EXTERN New_MediaPlayer_NowPlaying_OnClose
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

        RSEG    PATCH_MediaPlayer_ScrollText_SetSize
	CODE16
        MOV     R2, #0
	MOV     R1, #0
        LDR     R0, [R7,#0x6C]

        RSEG    PATCH_MediaPlayer_NowPlaying_SetSize
	CODE16
        LDR	R3, =mp_nowplaying_setsize
	BX	R3

        RSEG  CODE
        CODE16
mp_nowplaying_setsize:
        LDR     R0, [R7,#0x70]
        BL      New_MediaPlayer_NowPlaying_SetSize
        LDR	R3, =0x44F1B032+1
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
        ADD     R0, R4, #0
        LDR	R3, =0x44F1ADA4+1
	BX      R3

;====================PlayQueue=============================

        EXTERN New_MediaPlayer_PlayQueue_SetTitle

        RSEG    PATCH_MediaPlayer_PlayQueue_SetTitle
 	CODE16
        LDR	R3, =mp_playqueue_settitle
 	BX	R3

        RSEG  CODE
        CODE16
mp_playqueue_settitle:
        LDR     R0, [R5, #0]
        LDR	R3, =DispObject_SetTitleText
 	BLX     R3
        LDR     R0, [R5, #0]
        BL      New_MediaPlayer_PlayQueue_SetTitle
        LDR     R0, [R5, #0]
        LDR	R3, =0x44F1AC88+1
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
        LDR	R3, =0x44F1AE62+1
 	BX      R3

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

;====================OnClose Book=============================

        EXTERN  New_AudioPlayerBook_onClose

        RSEG    PATCH_AudioPlayerBook_onClose
	CODE16
	LDR	R3, =audioplayer_onclose
	BX	R3

        RSEG  CODE
        CODE16
audioplayer_onclose:
        BL      New_AudioPlayerBook_onClose
        ADD     R0, R4, #0
        ADD     R0, #0x18
        LDR	R3, =MediaPlayer_State_Get
	BLX	R3
        MOV     R1, #0xB9
        LDR	R3, =0x44F1E5B8+1
	BX      R3

;==================== SoftKeys Action ===========================

        EXTERN New_MediaPlayer_SoftKeys
        EXTERN New_MediaPlayer_SoftKeys_MyMusic

        RSEG    PATCH_MediaPlayer_SoftKeys_MyMusic
	CODE16
        LDR	R3, =mp_softkeys_mymusic
	BX	R3

        RSEG    PATCH_MediaPlayer_SoftKeys
	CODE16
	LDR	R3, =mp_softkeys
	BX	R3

        RSEG  CODE
        CODE16
mp_softkeys_mymusic:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys_MyMusic
        LDR     R0, [R4,#0x1C]
        BL	MP_Validate
        CMP     R0, #0
        BEQ     not_valid_m
        LDR	R3, =0x44F1EBC0+1
	BX      R3

not_valid_m:
        LDR	R3, =0x44F1EBCC+1
	BX      R3

mp_softkeys:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys
        LDR     R0, [R4,#0x1C]
        BL	MP_Validate
        CMP     R0, #0
        BEQ     not_valid_s
        LDR	R3, =0x44F1EC02+1
	BX      R3

not_valid_s:
        LDR	R3, =0x44F1EC0E+1
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
        LDR     R3, =0x44F29D66+1
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
	NOP

        RSEG    PATCH_GUI_MM_ALBUM
	CODE16
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_PLAYLIST1
	CODE16
	NOP
	NOP
	NOP

        RSEG    PATCH_GUI_MM_PLAYLIST2
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

        RSEG    PATCH_FIX_TITLE
	CODE16
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
        LDR     R3, =0x45221F9E+1
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
        ADD     R0, R6, #0
        BL      New_ListText_TopLevelBrowser
        ADD     R1, R0, #0
        LDR     R3, =0x45222048+1
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_LISTICON
	CODE16
	LDR	R3, =listicon_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
listicon_toplevel_browser:
        ADD     R0, R6, #0
        BL      New_ListIcon_TopLevelBrowser
        ADD     R2, R0, #0
        LDR     R3, =0x45222058+1
	BX      R3

        RSEG    PATCH_GUI_MM_TRACKS2
	CODE16
	LDR	R3, =list_tracks_number
	BX      R3

        RSEG  CODE
        CODE16
list_tracks_number:
        MOV     R1, #0
        ADD     R0, R5, #0
        LDR     R3, =TextID_Create
	BLX     R3
        LDR     R1, [SP,#4]
        BL      New_ListText_Track
        LDR     R3, =0x452229E8+1
	BX      R3

        END
