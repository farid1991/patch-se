//W810_R4EA031
#include "target.h"

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x45453AA8+1
        defadr memfree,0x454547E0+1
        defadr memset,0x44E24360+1
        defadr memcpy,0x4418E878
        defadr memcmp,0x44E242F4+1
        defadr debug_printf,0x44C9E13C+1
        defadr set_envp,0x44149D0A+1
        defadr get_envp,0x44149CF6+1
        defadr current_process,0x4418D8F0
        defadr get_bid,0x4418D928
        defadr sprintf,0x44E24E88+1
        defadr snwprintf,0x44E25568+1
        defadr sscanf,0x44147BAC+1
        defadr _fopen,0x455B4268+1
        defadr fread,0x455B5700+1
        defadr fclose,0x455B54A0+1
        defadr fwrite,0x455B58E4+1
        defadr fstat,0x455B4ADC+1
        defadr lseek,0x455B5AA8+1
        defadr FileDelete,0x455B4BF4+1
        defadr w_diropen,0x455E5DC0+1
        defadr w_chdir,0x455E40A4+1
        defadr w_dirread,0x4510AA68+1
        defadr w_fstat,0x44B24B64+1
        defadr w_dirclose,0x455E603C+1
        defadr strncmp,0x44E2538C+1
        defadr strcmp,0x44E252EC+1
        defadr strlen,0x44E25354+1
        defadr str2wstr,0x44FEAE4C+1
        defadr str2wstrn,0x44FE9C1C+1
        defadr wstrcpy,0x44E25C34+1
        defadr wstrncpy,0x44E25CE8+1
        defadr wstrcat,0x44E25BD4+1
        defadr wstrlen,0x44FE9B2C+1
        defadr wstrcmp,0x44E25C04+1
        defadr wstrcmpi,0x44FEAFB4+1
        defadr wstrrchr,0x44E25D38+1
        defadr wstrwstr,0x44E25E48+1
        defadr wstrnlwr,0x450D2754+1
        defadr manifest_GetParam,0x45565E94+1
        defadr List_Create,0x4527EFAC+1
        defadr List_InsertFirst,0x4527F0C0+1
        defadr List_InsertLast,0x4527F0D0+1
        defadr List_Destroy,0x4527EFC4+1
        defadr List_DestroyElements,0x4527F3B4+1
        defadr List_Get,0x4527F250+1
        defadr List_GetCount,0x4527F228+1
        defadr strftime,0x454396B0+1
        defadr TextID_CreateFromTextIterator,0x452FE434+1
        defadr TextID_Create,0x452FE69C+1
        defadr TextID_CreateIntegerID,0x452FE300+1
        defadr TextID_CreateCharacterID,0x452FE2F8+1
        defadr TextID_GetLength,0x452FE8FC+1
        defadr TextID_Destroy,0x452FE86C+1
        defadr TextID_GetString,0x452FF248+1
        defadr Disp_GetTextIDWidth,0x45308098+1
        defadr CreateMessageBox,0x45533CE0+1
        defadr FSX_IsFileExists,0x452510D8+1
        defadr Display_GetTopBook,0x4529F01C+1
        defadr GUIObject_GetDispObject,0x45193C40+1
        defadr DispObject_GetGUI,0x453024AC+1
        defadr GUIObject_GetBook,0x45193C54+1
        defadr DispObject_SoftKeys_GetList,0x45199EB4+1
        defadr BookObj_GotoPage,0x4529F4CC+1
        defadr BookObj_CallPage,0x4529F5DC+1
        defadr BookObj_GetBookID,0x4529FD0C+1
        defadr FindBook,0x45531160+1
        defadr FreeBook,0x4529FC78+1
        defadr UI_Event,0x4553127C+1
        defadr IsAudioPlayerBook,0x4542FF58+1
        defadr GUIObject_SetAnimation,0x451533E0+1
        defadr DispObject_InvalidateRect,0x45302A70+1
        defadr DispObject_SetStyle,0x45306190+1
        defadr DispObject_GetStyle,0x453062BC+1
        defadr DispObject_SetLayerColor,0x453060C4+1
        defadr DispObject_WindowSetSize,0x4530476C+1
        defadr DispObject_SetBackgroundColor,0x4530EFFC+1
        defadr DispObject_SetListTextColor,0x452E66F4+1
        defadr DispObject_SetTitleText,0x45304A34+1
        defadr DispObject_SetTitleType,0x45304B98+1
        defadr DispObject_SetSecondRowTitleText,0x45304A8C+1
        defadr DispObject_ListMenu_GetItemCount,0x452DC0FC+1
        defadr DispObject_SetThemeImage,0x45305BE4+1
        defadr DispObject_SetCursorImage,0x452E6680+1
        defadr DispObject_SetBackgroundImage,0x452E669C+1
        defadr ImageID_Get,0x45426B54+1
        defadr ImageID_Free,0x45426B44+1
        defadr ImageID_GetIndirect,0x45426D24+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x455ADDD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x455ADE50+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x455ADEE4+1
        defadr GUIObject_SetStyle,0x45193EC4+1
        defadr GUIObject_SetListTextColor,0x45171F28+1
        defadr GUIObject_SetCursorImage,0x45171EF8+1
        defadr GUIObject_SetBackgroundImage,0x45171F08+1
        defadr GUIObject_SetTitleBackgroundImage,0x45171F18+1
        defadr GUIObject_SetTitleType,0x45193F58+1
        defadr GUIObject_SetTitleText,0x45193F7C+1
        defadr GUIObject_SetTitleTextAlign,0x45193FC8+1
        defadr GUIObject_SetSecondRowTitleText,0x45193F98+1
        defadr GUIObject_Show,0x45193E64+1
        defadr GUIObject_Destroy,0x45193BE4+1
        defadr CreateListMenu,0x45170674+1
        defadr ListMenu_SetItemCount,0x4517089C+1
        defadr ListMenu_GetSelectedItem,0x45170884+1
        defadr ListMenu_SetCursorToItem,0x45170870+1
        defadr ListMenu_SetOnMessage,0x451709D8+1
        defadr ListMenu_SetHotkeyMode,0x45170A04+1
        defadr ListMenu_SetItemSecondLineText,0x45170C98+1
        defadr GUIonMessage_GetMsg,0x45171378+1
        defadr GUIonMessage_GetCreatedItemIndex,0x451713A4+1
        defadr GUIonMessage_SetMenuItemText,0x451713B4+1
        defadr GUIonMessage_SetMenuItemIcon,0x451713F4+1
        defadr CreateOneOfMany,0x4517250C+1
        defadr OneOfMany_SetItemCount,0x451726A0+1
        defadr OneOfMany_SetChecked,0x451726C4+1
        defadr OneOfMany_SetTexts,0x451726F8+1
        defadr OneOfMany_GetSelected,0x451726D4+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x45219CDC+1
        defadr GUIObject_SoftKeys_SetAction,0x4519B824+1
        defadr GUIObject_SoftKeys_SetText,0x4519B90C+1
        defadr GUIObject_SoftKeys_SetInfoText,0x4519B8D0+1
        defadr MessageBox,0x45533C94+1
        defadr GetThemeColor,0x45532A30+1
        defadr Display_GetHeight,0x45547974+1
        defadr Display_GetWidth,0x45547984+1
        defadr GetImageHeight,0x45307FC0+1
        defadr GetImageWidth,0x45307FD8+1
        defadr SetFont,0x45307888+1
        defadr DrawString,0x45306D48+1
        defadr DrawRect,0x45306940+1
        defadr DrawObject,0x45306B64+1
        defadr get_DisplayGC,0x45191A98+1
        defadr GC_PutChar,0x451925BC+1
        defadr GC_CreateMemoryGC,0x45191AA4+1
        defadr GC_FreeGC,0x45191B58+1
        defadr GC_DrawFRect,0x45192E64+1
        defadr CANVAS_Get_GviGC,0x44A4CAF0+1
        defadr GVI_BitBlt,0x44B3EE38+1
        defadr GVI_StretchBlt,0x44B3EFA8+1
        defadr GVI_TransformBlt,0x44B3F054+1
        defadr GVI_CreatePen,0x44B3E498+1
        defadr GVI_CreateDashedPen,0x44B3E4D4+1
        defadr GVI_CreateSolidBrush,0x44B3E424+1
        defadr GVI_Delete_GVI_Object,0x44B3DE80+1
        defadr GVI_DrawEllipse,0x44B3E968+1
        defadr GVI_DrawLine,0x44B3F4F0+1
        defadr GVI_DrawLines,0x44B3F988+1
        defadr GVI_DrawPolyLine,0x44B3FA10+1
        defadr GVI_DrawRectangle,0x44B3FBF8+1
        defadr GVI_DrawRoundRect,0x44B3ED2C+1
        defadr GVI_DrawSolidLines,0x44B3F5F4+1
        defadr GVI_DrawSolidPolyLine,0x44B3F7D0+1
        defadr GVI_DrawSolidRectangle,0x44B3F890+1
        defadr GVI_FillEllipse,0x44B3EBE4+1
        defadr GVI_FillPolygon,0x44B3F3EC+1
        defadr GVI_FillRectangle,0x44B3FB08+1
        defadr GVI_FillRectangles,0x44B3FB68+1
        defadr GVI_FillSolidEllipse,0x44B3EC7C+1
        defadr GVI_FillSolidRectangle,0x44B3FBB4+1
        defadr GVI_FillSolidRoundRect,0x44B3EE14+1
        defadr GVI_FillSolidTriangle,0x44B3F364+1
        defadr GVI_CreateBitmap,0x44B3E56C+1
        defadr GVI_CreateMemoryGC,0x44B3FCC8+1
        defadr GVI_DeleteMemoryGC,0x44B88884+1
        defadr Timer_ReSet,0x4529EAE4+1
        defadr Timer_Set,0x4529EAC0+1
        defadr Timer_Kill,0x4529EB10+1
        defadr arm_int_div,0x443B7634+1
        defadr count_digit,0x451517D0+1
        defadr itow,0x45151444+1
        defadr id3_desc_create,0x455278D0+1
        defadr id3_desc_gettag,0x4552795C+1
        defadr id3_desc_loadtag,0x4552776C+1
        defadr id3_desc_destroy,0x45527A0C+1
        defadr MediaPlayer_State_Get,0x4543CC98+1
        defadr MediaPlayer_SoftKeys_Validate,0x45074F90+1
        defadr MediaPlayer_SoftKeys_SetAction,0x45074FAC+1
        defadr MediaPlayer_SoftKeys_SetText,0x45074FE0+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x45074FFC+1
        defadr MediaPlayer_Audio_Sort,0x4543646C+1
        defadr MediaPlayer_Audio_ActionBack,0x45431080+1
        defadr MediaPlayer_Audio_ActionLongBack,0x4543103C+1
        defadr MediaPlayer_Audio_OnCreate,0x45255F84+1
        defadr MediaPlayer_Audio_OnClose,0x4525604C+1
        defadr MediaPlayer_Audio_OnRefresh,0x452567B8+1
        defadr MediaPlayer_NowPlaying_OnCreate,0x45256DA0+1
        defadr MediaPlayer_NowPlaying_OnClose,0x45256E90+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x45256EC4+1
        defadr pg_MediaPlayer_Audio_Bk_PrevEvent,0x45432C84+1
        defadr pg_MediaPlayer_Audio_Bk_CancelEvent,0x45432CB4+1
        defadr pg_MediaPlayer_Audio_Bk_ExitEvent,0x45432C70+1
        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x45432FB0+1
        defadr pg_MEDIAPLAYER_NEW_TRACK_EVENT,0x45433008+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x45434224+1
        defadr MM_BrowserToplevel_Enter,0x4552EEB8+1
        defadr Call_MM_BrowserAlbumsMain,0x4552AA8C+1
        defadr pg_MM_Browser_Toplevel_Bk_Start,0x4552F270+1
        defadr pg_MM_Browser_Toplevel_Bk_Cancel,0x4552F2A8+1
        defadr pg_MM_Browser_Toplevel_Bk_Destroy,0x4552F2CC+1
        defadr MediaPlayer_Audio_Rename,0x454320B4+1

;==================== MEDIAPLAYER =============================

        EXTERN New_MediaPlayer_Audio_OnCreate
        EXTERN New_MediaPlayer_Audio_OnRedraw
        EXTERN New_MediaPlayer_Audio_OnRefresh
        EXTERN New_MediaPlayer_Audio_SetStyle
        EXTERN New_MediaPlayer_PlayQueue_SetStyle
        EXTERN New_MediaPlayer_PlayQueue_SetTitle
        EXTERN New_MediaPlayer_PlayQueue_List
        EXTERN New_MediaPlayer_NowPlaying_SetSize
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

;==================== Other GUI =============================

        RSEG    PATCH_MediaPlayer_Volume_SetPosition
	CODE16
        NOP
	MOV     R2, #0
	MOV     R1, #0
        LDR     R0, [R4,#0x70]

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

        RSEG    PATCH_MediaPlayer_PlayQueue_SetStyle
	CODE16
        LDR	R3, =mp_playqueue_setstyle
	BX	R3

        RSEG  CODE
        CODE16
mp_playqueue_setstyle:
        LDR     R0, [R4,#0x68]
        BL      New_MediaPlayer_PlayQueue_SetStyle
        LDR	R3, =0x452560E6+1
	BX      R3

        RSEG    PATCH_MediaPlayer_PlayQueue_SetTitle
	CODE16
        LDR	R3, =mp_playqueue_settitle
	BX	R3

        RSEG  CODE
        CODE16
mp_playqueue_settitle:
        LDR	R1, =MP_BR_LISTNOWPLAYING_TXT
        LDR	R3, =DispObject_SetTitleText
	BLX     R3
        LDR     R0, [R5, #0]
        BL      New_MediaPlayer_PlayQueue_SetTitle
        LDR     R0, [R5, #0]
        LDR	R3, =0x45255EF4+1
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
        LDR	R3, =0x452562AA+1
	BX      R3

        RSEG    PATCH_GUI_PLAYMODE
	CODE16
	LDR     R0, [R4,#0x20]
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
        LDR	R3, =0x45256018+1
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
        LDR	R3, =0x454312C4+1
	BX      R3

mp_softkeys:
        ADD     R0, R4,#0
        BL	New_MediaPlayer_SoftKeys
        LDR     R5, =MediaPlayer_Audio_Rename
	LDR	R0, [R4,#0x1C]
        BL	MP_Validate
        CMP	R0, #0
	BEQ	not_valid_exit
        LDR	R3, =0x454313BE+1
	BX      R3
not_valid_exit:
        LDR     R3, =0x454313CA+1
	BX      R3

MP_Validate:
        LDR     R3, =MediaPlayer_SoftKeys_Validate
	BX      R3

;======================OnClose Book=============================

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
        LDR	R3, =0x454376D4+1
	BLX	R3
        LDR     R1, [R4,#0x18]
        LDR	R3, =0x45430C42+1
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
        LDR     R3, =0x4543AFB2+1
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

        RSEG    PATCH_GUI_TOPLEVEL_STYLE
	CODE16
        BX      LR

        RSEG    PATCH_GUI_MM_PLAYLIST
	CODE16
        NOP

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

        RSEG    PATCH_GUI_MM_TRACKS1
	CODE16
	NOP
	NOP
	NOP
	NOP

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
        LDR     R3, =0x4552F118+1
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_LISTCOUNT
	CODE16
        MOV     R0, #6
        NOP

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
        LDR     R3, =0x4552F1D4+1
	BX      R3

        RSEG    PATCH_GUI_MM_BROWSER_LISTICON
	CODE16
	LDR	R3, =listicon_toplevel_browser
	BX      R3

        RSEG  CODE
        CODE16
listicon_toplevel_browser:
        BL      New_ListIcon_TopLevelBrowser
        ADD     R2, R0, #0
        LDR     R3, =0x4552F1E8+1
	BX      R3

        RSEG    PATCH_GUI_MM_TRACKS2
	CODE16
	LDR	R3, =list_tracks_number
	BX      R3

        RSEG  CODE
        CODE16
list_tracks_number:
        LDR     R3, =TextID_Create
	BLX     R3
        ADD     R1, R4, #0
        BL      New_ListText_Track
        ADD     R1, R0, #0
        ADD     R0, R4, #0
        LDR     R3, =0x4552F904+1
	BX      R3

        END
