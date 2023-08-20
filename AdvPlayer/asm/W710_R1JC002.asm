//W710_R1JC002

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x44D2EA44+1
        defadr memfree,0x44D2EA70+1
        defadr memset,0x4414535C
        defadr sscanf,0x442C1FC4+1
        defadr snwprintf,0x44542FA4+1
        defadr set_envp,0x442C3CD4+1
        defadr get_envp,0x442C3CC0+1

        defadr wstrcmp,0x44543688+1
        defadr wstrcmpi,0x44E34568+1
        defadr wstrcpy,0x445436B0+1
        defadr wstrlen,0x44E33144+1
        defadr wstrrchr,0x445437B0+1

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
        defadr TextID_GetLength,0x4532F010+1
        defadr TextID_Destroy,0x4532EF70+1
        defadr TextIteratorSetTextId,0x4532EC2C+1
        defadr Format_Time,0x44F2839C+1

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
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x4536951C+1
        defadr MediaPlayer_SoftKeys_SetAction,0x44F1D15C+1
        defadr MediaPlayer_SoftKeys_SetText,0x44F1D190+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x44F1D21C+1
        defadr MediaPlayer_SoftKeys_Validate,0x44F1D140+1

        defadr MetaData_Desc_Create,0x4521B788+1
        defadr MetaData_Desc_GetCoverInfo,0x4521B8BC+1
        defadr MetaData_Desc_Destroy,0x4521B814+1

        defadr w_diropen,0x44F75BBC+1
        defadr w_chdir,0x44F73A44+1
        defadr w_fstat,0x4483B444+1
        defadr w_dirread,0x4519C188+1
        defadr w_dirclose,0x44F75F18+1

        defadr BookObj_CallPage,0x4528A088+1
        defadr BookObj_GotoPage,0x45289F88+1

        defadr CreateListMenu,0x45305A90+1
        defadr ListMenu_SetItemCount,0x45305CC0+1
        defadr ListMenu_GetSelectedItem,0x45305CAC+1
        defadr ListMenu_SetCursorToItem,0x45305C98+1
        defadr ListMenu_SetOnMessage,0x45305DD4+1
        defadr ListMenu_SetHotKeyMode,0x45305E00+1
        defadr GUIonMessage_GetMsg,0x4530678C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x453067B0+1
        defadr GUIonMessage_SetMenuItemText,0x453067BC+1
        defadr GUIonMessage_SetMenuItemIcon,0x45306834+1
        defadr GUIObject_SetTitleType,0x4534CDE4+1
        defadr GUIObject_SetTitleText,0x4534CE00+1
        defadr GUIObject_SetTitleTextAlign,0x4534CE54+1
        defadr GUIObject_SetSecondRowTitleText,0x4534CE1C+1
        defadr GUIObject_SetStyle,0x4534C940+1
        defadr GUIObject_Show,0x4534C8F0+1
        defadr GUIObject_Destroy,0x4534C680+1

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

        RSEG    PATCH_MediaPlayer_Audio_OnClose
        DATA
        DCD     New_MediaPlayer_Audio_OnClose

        RSEG    PATCH_MediaPlayer_NowPlaying_OnCreate
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnCreate

        RSEG    PATCH_MediaPlayer_NowPlaying_OnClose
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnClose

        RSEG    PATCH_MediaPlayer_NowPlaying_OnRedraw
        DATA
        DCD     New_MediaPlayer_NowPlaying_OnRedraw

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

        RSEG    PATCH_SKIN_SELECTOR
	CODE16
	LDR	R3, =skinselector
	BX	R3

        RSEG  CODE
        CODE16
skinselector:
        LDR     R0, [R4,#0x1C]
        LDR	R3, =MediaPlayer_SoftKeys_Validate
	BLX	R3
        CMP     R0, #0
        BEQ     not_valid_s1
        LDR     R0, [R4,#0x1C]
        MOV     R2, #0x18
        MOV     R1, #0x14
        LDR	R3, =MediaPlayer_SoftKeys_SetItemAsSubItem
        BLX	R3
        B       next_intr_a1
not_valid_s1:
        LDR     R0, [R4,#0x1C]
        MOV     R2, #0x18
        MOV     R1, #0x14
        LDR	R3, =GUIObject_SoftKeys_SetItemAsSubItem
        BLX	R3

next_intr_a1:
        LDR     R0, [R4,#0x1C]
        LDR	R3, =MediaPlayer_SoftKeys_Validate
	BLX	R3
        CMP     R0, #0
        BEQ     not_valid_a1
        LDR     R0, [R4,#0x1C]
        LDR     R2, =CallSkinSelector
        MOV     R1, #0x18
        LDR	R3, =MediaPlayer_SoftKeys_SetAction
        BLX	R3
        b       next_set_t1
not_valid_a1:
        LDR     R0, [R4,#0x1C]
        LDR     R2, =CallSkinSelector
        MOV     R1, #0x18
        LDR	R3, =GUIObject_SoftKeys_SetAction
        BLX	R3

next_set_t1:
        LDR     R0, [R4,#0x1C]
        LDR     R6, =0x10B3
        LDR	R3, =MediaPlayer_SoftKeys_Validate
	BLX	R3
        CMP     R0, #0
        BEQ     not_valid_t1
        ADD     R2, R6, #0
        MOV     R1, #0x18
        LDR     R0, [R4,#0x1C]
        LDR	R3, =MediaPlayer_SoftKeys_SetText
        BLX	R3
        B       next_intr_a2
not_valid_t1:
        ADD     R2, R6, #0
        MOV     R1, #0x18
        LDR     R0, [R4,#0x1C]
        LDR	R3, =GUIObject_SoftKeys_SetText
        BLX	R3

next_intr_a2:
        LDR     R0, [R4,#0x1C]
        LDR	R3, =MediaPlayer_SoftKeys_Validate
	BLX	R3
        CMP     R0, #0
        BEQ     not_valid_a2
        LDR	R3, =0x44F1EC02+1
	BX      R3

not_valid_a2:
        LDR	R3, =0x44F1EC0E+1
	BX      R3

        END
