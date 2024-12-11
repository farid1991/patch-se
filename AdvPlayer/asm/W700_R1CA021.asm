//W700_R1CA021
#include "target.h"

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44F89D7C+1
        defadr memfree,0x44F8AE98+1
        defadr memset,0x44B46898+1
        defadr memcmp,0x44B4682C+1
        defadr memcpy,0x44069D54
        defadr debug_printf,0x44AF7014+1
        defadr set_envp,0x44031AB6+1
        defadr get_envp,0x44031AA2+1
        defadr current_process,0x44068DB0
        defadr get_bid,0x44068DE8
        defadr sprintf,0x44B473C0+1
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
        defadr strncmp,0x44B478C4+1
        defadr strcmp,0x44B47824+1
        defadr wstrlen,0x44BF49F4+1
        defadr wstrcmp,0x44BF4A20+1
        defadr wstrcmpi,0x44BF6164+1
        defadr wstrrchr,0x44BF5FDC+1
        defadr wstrcpy,0x44BF4A70+1
        defadr wstrncpy,0x44BF4AB8+1
        defadr wstrcat,0x44BF4B18+1
        defadr wstrwstr,0x44B48110+1
        defadr manifest_GetParam,0x45095244+1
        defadr Timer_ReSet,0x44E87E74+1
        defadr Timer_Set,0x44E87E3C+1
        defadr Timer_Kill,0x44E87EC4+1
        defadr List_Create,0x44E5D390+1
        defadr List_Destroy,0x44E5D3B4+1
        defadr List_DestroyElements,0x44E5D7DC+1
        defadr List_InsertFirst,0x44E5D4D4+1
        defadr List_InsertLast,0x44E5D4E4+1
        defadr List_Get,0x44E5D664+1
        defadr List_GetCount,0x44E5D63C+1
        defadr BookObj_GotoPage,0x44E88854+1
        defadr BookObj_CallPage,0x44E8896C+1
        defadr BookObj_GetBookID,0x44E8927C+1
        defadr FreeBook,0x44E89128+1
        defadr UI_Event,0x45062224+1
        defadr TextID_Create,0x44EFA32C+1
        defadr TextID_CreateIntegerID,0x44EF9F5C+1
        defadr TextID_CreateCharacterID,0x44EF9F54+1
        defadr TextID_Destroy,0x44EFA604+1
        defadr TextID_GetLength,0x44EFA698+1
        defadr Disp_GetTextIDWidth,0x44E95184+1
        defadr strftime,0x44F6D9B4+1
        defadr TextID_CreateFromTextIterator,0x44EFA0A8+1
        defadr count_digit,0x44D3811C+1
        defadr itow,0x44D37D90+1
        defadr MessageBox,0x4506E180+1
        defadr CreateMessageBox,0x4506E1CC+1
        defadr ImageID_Get,0x44F5A660+1
        defadr ImageID_Free,0x44F5AA00+1
        defadr ImageID_GetIndirect,0x44F5A6B8+1
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
        defadr ListMenu_SetHotkeyMode,0x44D68718+1
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
        defadr MediaPlayer_SoftKeys_SetAction,0x44C810FC+1
        defadr MediaPlayer_SoftKeys_SetText,0x44C81130+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x44C8114C+1
        defadr GUIObject_SoftKeys_SetInfoText,0x44D3EF80+1
        defadr MediaPlayer_SoftKeys_Validate,0x44C810DC+1
        defadr CANVAS_Get_GviGC,0x44A40D9C+1
        defadr GVI_BitBlt,0x447845AC+1
        defadr GVI_StretchBlt,0x4478471C+1
        defadr GVI_TransformBlt,0x447847C8+1
        defadr GVI_CreatePen,0x44783C0C+1
        defadr GVI_CreateDashedPen,0x44783C48+1
        defadr GVI_CreateSolidBrush,0x44783B98+1
        defadr GVI_Delete_GVI_Object,0x447835F4+1
        defadr GVI_DrawEllipse,0x447840DC+1
        defadr GVI_DrawLine,0x44784C64+1
        defadr GVI_DrawLines,0x447850FC+1
        defadr GVI_DrawPolyLine,0x44785184+1
        defadr GVI_DrawRectangle,0x4478527C+1
        defadr GVI_DrawRoundRect,0x447844A0+1
        defadr GVI_DrawSolidLines,0x44784D68+1
        defadr GVI_DrawSolidPolyLine,0x44784F44+1
        defadr GVI_DrawSolidRectangle,0x44785004+1
        defadr GVI_FillEllipse,0x44784358+1
        defadr GVI_FillPolygon,0x44784B60+1
        defadr GVI_FillRectangle,0x4478527C+1
        defadr GVI_FillRectangles,0x447852DC+1
        defadr GVI_FillSolidEllipse,0x447843F0+1
        defadr GVI_FillSolidRectangle,0x44785328+1
        defadr GVI_FillSolidRoundRect,0x44784588+1
        defadr GVI_FillSolidTriangle,0x44784AD8+1
        defadr GC_CreateMemoryGC,0x44D46910+1
        defadr GC_FreeGC,0x44D469CC+1
        defadr GVI_CreateBitmap,0x44783CE0+1
        defadr GVI_CreateMemoryGC,0x4478543C+1
        defadr GVI_DeleteMemoryGC,0x447C5740+1
        defadr MediaPlayer_State_Get,0x44F71284+1
        defadr MediaPlayer_Audio_ActionBack,0x44F647D8+1
        defadr MediaPlayer_Audio_ActionLongBack,0x44F64794+1
        defadr pg_MediaPlayer_Audio_Bk_PrevEvent,0x44F66584+1
        defadr pg_MediaPlayer_Audio_Bk_CancelEvent,0x44F665C8+1
        defadr pg_MediaPlayer_Audio_Bk_ExitEvent,0x44F6655C+1
        defadr Call_MM_BrowserAlbumsMain,0x4505339C+1
        defadr pg_MM_Browser_Toplevel_Bk_Start,0x45058854+1
        defadr pg_MM_Browser_Toplevel_Bk_Cancel,0x450588E8+1
        defadr pg_MM_Browser_Toplevel_Bk_Destroy,0x45058920+1
        defadr MediaPlayer_Audio_OnCreate,0x44E32A6C+1
        defadr MediaPlayer_Audio_OnClose,0x44E32B48+1
        defadr MediaPlayer_NowPlaying_OnCreate,0x44E33FCC+1
        defadr MediaPlayer_NowPlaying_OnClose,0x44E34090+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x44E340D4+1
        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x44F66844+1
        defadr pg_MEDIAPLAYER_NEW_TRACK_EVENT,0x44F668C4+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x44F67D98+1
        defadr MediaPlayer_Audio_Rename,0x44F658B8+1

;==================== MEDIAPLAYER =============================

        EXTERN New_MediaPlayer_Audio_OnCreate
        EXTERN New_MediaPlayer_Audio_OnRedraw
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

;======================= GUI ============================

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
        LDR	R3, =0x44E32C42+1
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
        LDR	R3, =0x44F6B898+1
	BLX	R3
        LDR     R1, [R4,#0x18]
        LDR	R3, =0x44F64320+1
	BX      R3

;==================== SoftKeys Action ===========================

        EXTERN New_MediaPlayer_SoftKeys
        EXTERN New_MediaPlayer_SoftKeys_MyMusic

        RSEG    PATCH_MediaPlayer_SoftKeys_Minimize
	CODE16
        LDR	R3, =mp_softkeys_minim
	BX	R3

        RSEG  CODE
        CODE16
mp_softkeys_minim:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys_MyMusic
        LDR	R3, =0x44F64A2C+1
	BX      R3

        RSEG    PATCH_MediaPlayer_SoftKeys
	CODE16
        LDR	R3, =mp_softkeys
	BX	R3

        RSEG  CODE
        CODE16
mp_softkeys:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys
        LDR     R5, =MediaPlayer_Audio_Rename
	LDR	R0, [R4,#0x1C]
        BL	MP_Validate
        CMP	R0, #0
	BEQ	not_valid_exit
        LDR	R3, =0x44F64B28+1
	BX      R3

not_valid_exit:
        LDR     R3, =0x44F64B34+1
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
        LDR     R3, =0x44F6EFFC+1
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
