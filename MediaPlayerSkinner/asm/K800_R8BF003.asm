//K800_R8BF003

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x44E4FD44+1
        defadr memfree,0x44E4FD70+1
        defadr memset,0x20003094
        defadr memcpy,0x443FCB18
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

        defadr TextID_Create,0x45446A40+1
        defadr TextID_CreateIntegerID,0x4544678C+1
        defadr TextID_GetLength,0x45446CA4+1
        defadr TextID_Destroy,0x45446C08+1
        defadr TextIteratorSetTextId,0x454468CC+1
        defadr Format_Time,0x4504ADA4+1

        defadr MetaData_Desc_Create,0x4533EA14+1
        defadr MetaData_Desc_GetCoverInfo,0x4533EBC0+1
        defadr MetaData_Desc_Destroy,0x4533EAD4+1

        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x44F4DE88+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x44F4DEF0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x44F4DFA0+1
        defadr ImageID_Free,0x44F4A080+1
        defadr ImageID_GetIndirect,0x44F49800+1

        defadr BookObj_CallPage,0x453AE650+1
        defadr BookObj_GotoPage,0x453AE550+1

        defadr GetImageWidth,0x4545DD18+1
        defadr GetImageHeight,0x4545DD2C+1
        defadr get_DisplayGC,0x45461760+1
        defadr GC_PutChar,0x45462238+1
        
        defadr Display_GetHeight,0x45476E80+1
        defadr Display_GetWidth,0x45476E8C+1

        defadr DrawRect,0x4545CA24+1
        defadr SetFont,0x4545D780+1
        defadr DrawString,0x4545CD24+1
        defadr GC_DrawImage,0x4545CC18+1
        defadr DispObject_InvalidateRect,0x4545A060+1
        defadr DispObject_WindowSetSize,0x4545B0A0+1
        defadr DispObject_SetStyle,0x4545C360+1

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
        defadr ListMenu_SetHotKeyMode,0x4541DC58+1
        defadr GUIObject_SetTitleType,0x45464344+1
        defadr GUIObject_SetTitleText,0x45464360+1
        defadr GUIObject_SetTitleTextAlign,0x454643B4+1
        defadr GUIObject_SetSecondRowTitleText,0x4546437C+1
        defadr GUIObject_SetStyle,0x45463F34+1
        defadr GUIObject_Show,0x45463EE4+1
        defadr GUIObject_SetFocus,0x45463E90+1

        defadr GUIObject_SoftKeys_SetAction,0x454806E0+1
        defadr GUIObject_SoftKeys_SetText,0x45480758+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x45480838+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x45480A7C+1
        defadr DispObject_SoftKeys_RemoveBackground,0x4547D5CC+1

        defadr MediaPlayer_SoftKeys_Validate,0x4503FD98+1
        defadr MediaPlayer_SoftKeys_SetText,0x4503FDE8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x4503FDB4+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x4503FE74+1
        defadr MediaPlayer_SoftKeys_AddHelpStr,0x4503FE04+1

        defadr MediaPlayer_Audio_ActionBack,0x450464F4+1
        defadr MediaPlayer_Audio_ActionLongBack,0x45041538+1

        defadr MediaPlayer_Audio_OnCreate,0x4503E068+1
        defadr MediaPlayer_Audio_OnClose,0x4503E134+1

        defadr MediaPlayer_NowPlaying_OnCreate,0x4503EFA0+1
        defadr MediaPlayer_NowPlaying_OnClose,0x4503F09C+1
        defadr MediaPlayer_NowPlaying_OnRedraw,0x4503F0D0+1

        defadr pg_MEDIAPLAYER_AUDIO_PLAYING_TIME,0x4504309C+1
        defadr pg_MEDIAPLAYER_CREATED_EVENT,0x45044A38+1

        EXTERN New_MediaPlayer_Audio_OnCreate
        EXTERN New_MediaPlayer_Audio_OnClose
        EXTERN New_MediaPlayer_Audio_OnRedraw
        EXTERN New_MediaPlayer_Audio_SetStyle
        EXTERN New_MediaPlayer_NowPlaying_OnCreate
        EXTERN New_MediaPlayer_NowPlaying_OnClose
        EXTERN New_MediaPlayer_NowPlaying_OnRedraw
        EXTERN New_MediaPlayer_NowPlaying_SetSize
        EXTERN New_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        EXTERN New_MEDIAPLAYER_CREATED_EVENT
        EXTERN New_MEDIAPLAYER_NEW_TRACK_EVENT

        EXTERN CallSkinSelector
        EXTERN SkinSelect_GetText

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

        RSEG    PATCH_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
        DATA
        DCD     New_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT

        RSEG    PATCH_MEDIAPLAYER_CREATED_EVENT
        DATA
        DCD     New_MEDIAPLAYER_CREATED_EVENT

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
        ADD     R0, R4, #0
        LDR     R3, =0x45041580+1
	BLX     R3
        ADD     R0, R4, #0
        LDR	R3, =GUIObject_SoftKeys_RemoveBackground
	BLX     R3
        ADD     R0, R4, #0
        LDR	R3, =0x45044F1C+1
	BX      R3

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

        RSEG    PATCH_MediaPlayer_SoftKeys
	CODE16
        LDR	R3, =mp_softkeys
	BX	R3

        RSEG  CODE
        CODE16
mp_softkeys:
        LDR	R0, [R4,#0x1C]
        BL	MP_Validate
	CMP	R0, #0
	BEQ	not_valid1
	LDR	R0, [R4,#0x1C]
	MOV	R2, #0x20
	MOV	R1, #0x14
	BL	MP_SetItemAsSubItem
	B	next_1
not_valid1:
	LDR	R0, [R4,#0x1C]
	MOV	R2, #0x20
	MOV	R1, #0x14
	BL	_SetItemAsSubItem
next_1:
	LDR	R0, [R4,#0x1C]
	BL	MP_Validate
	CMP	R0, #0
	BEQ	not_valid2
        LDR	R2, =CallSkinSelector
	LDR	R0, [R4,#0x1C]
	MOV	R1, #0x20
	BL	MP_SetAction
	B	next_2
not_valid2:
        LDR	R2, =CallSkinSelector
	LDR	R0, [R4,#0x1C]
	MOV	R1, #0x20
	BL	_SetAction
next_2:
	LDR	R0, [R4,#0x1C]
	BL	MP_Validate
	CMP	R0, #0
	BEQ	not_valid3
        BL      SkinSelect_GetText
        MOV	R2, R0
	MOV	R1, #0x20
        LDR	R0, [R4,#0x1C]
	BL	MP_SetText
	B	next_3
not_valid3:
	BL      SkinSelect_GetText
        MOV	R2, R0
	MOV	R1, #0x20
        LDR	R0, [R4,#0x1C]
	BL	_SetText
next_3:
	LDR	R0, [R4,#0x1C]
        BL	MP_Validate
        CMP	R0, #0
	BEQ	not_valid4
        LDR	R3, =0x450417D0+1
	BX      R3

not_valid4:
        LDR     R3, =0x450417DC+1
	BX      R3
MP_Validate:
        LDR     R3, =MediaPlayer_SoftKeys_Validate
	BX      R3
MP_SetItemAsSubItem:
        LDR     R3, =MediaPlayer_SoftKeys_SetItemAsSubItem
	BX      R3
MP_SetAction:
        LDR     R3, =MediaPlayer_SoftKeys_SetAction
	BX      R3
MP_SetText:
        LDR     R3, =MediaPlayer_SoftKeys_SetText
	BX      R3
_SetItemAsSubItem:
        LDR     R3, =GUIObject_SoftKeys_SetItemAsSubItem
	BX      R3
_SetAction:
        LDR     R3, =GUIObject_SoftKeys_SetAction
	BX      R3
_SetText:
        LDR     R3, =GUIObject_SoftKeys_SetText
	BX      R3

        END
