//W350_R11CA002

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr memset,0x20105B58
        defadr memcpy,0x20151A7C
        defadr debug_printf,0x2086B1D0+1
        defadr snwprintf,0x20380BC4+1
        defadr _fopen,0x20C86CB4+1
        defadr fread,0x20C88340+1
        defadr fclose,0x20C880EC+1
        defadr fwrite,0x20C8850C+1
        defadr fstat,0x20C875A0+1
        defadr w_fopen,0x2067F580+1
        defadr w_fwrite,0x2067F5C8+1
        defadr w_fclose,0x2067F5E0+1

        defadr wstrlen,0x20C48D0C+1
        defadr wstrncmp,0x20381210+1
        defadr wstrcpy,0x20381198+1
        defadr wstrcat,0x2038113C+1
        defadr strncmp,0x20380A40+1
        defadr str2wstr,0x20C49FD4+1
        defadr strlen,0x20380A04+1
        defadr strstr,0x20380B0C+1
        defadr strcpy,0x203809D0+1
        defadr strcmp,0x203809A8+1

        defadr TextID_Create,0x210EBC80+1
        defadr TextID_CreateIntegerID,0x210EBAD0+1
        defadr TextID_Copy,0x210EBE10+1
        defadr TextID_GetString,0x210EC274+1
        defadr TextID_Destroy,0x210EBF00+1

        defadr iconidname2id,0x20A453CC+1
        defadr GetFreeBytesOnHeap,0x20DACCB0+1
        defadr REQUEST_DATEANDTIME_GET,0x20B54AE0+1

        defadr Display_GetWidth,0x211170B4+1
        defadr Display_GetHeight,0x211170A8+1

        defadr CreateListMenu,0x210C2F7C+1
        defadr ListMenu_SetOnMessage,0x210C32BC+1
        defadr ListMenu_SetItemCount,0x210C3190+1
        defadr ListMenu_SetCursorToItem,0x210C3168+1
        defadr ListMenu_GetSelectedItem,0x210C317C+1
        defadr ListMenu_SetItemTextScroll,0x210C38F0+1
        defadr ListMenu_SetItemStyle,0x210C31CC+1
        defadr ListMenu_SetHotkeyMode,0x210C32E8+1
        defadr ListMenu_SetTexts,0x210C32C4+1
        defadr ListMenu_DestroyItems,0x210C3670+1
        defadr ListMenu_SetNoItemText,0x210C3360+1

        defadr CreateOneOfMany,0x210C50EC+1
        defadr OneOfMany_GetSelected,0x210C52BC+1
        defadr OneOfMany_SetItemCount,0x210C5290+1
        defadr OneOfMany_SetTexts,0x210C52E0+1
        defadr OneOfMany_SetChecked,0x210C52AC+1
        defadr GUIObject_SetTitleText,0x21104674+1
        defadr GUIObject_SetTitleType,0x21104658+1
        defadr GUIObject_SetSecondRowTitleText,0x21104690+1
        defadr GUIObject_SetStyle,0x21104188+1
        
        defadr GUIObject_Show,0x21104138+1
        defadr GUIObject_Destroy,0x21103ECC+1
        defadr DispObject_SetAnimation,0x210FC3D0+1

        defadr GUIonMessage_GetMsg,0x210C3CA0+1
        defadr GUIonMessage_GetBook,0x210C3CA8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x210C3CC4+1
        defadr GUIonMessage_SetMenuItemText,0x210C3CD0+1
        defadr GUIonMessage_SetMenuItemIcon,0x210C3D48+1
        defadr GUIonMessage_SetItemDisabled,0x210C3D6C+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x210C3CF0+1
        defadr GUIonMessage_GetSelectedItem,0x210C3CAC+1

        defadr UI_Event,0x21053B9C+1
        defadr UI_Event_toBookID,0x21053BF4+1
        defadr Shortcut_Run,0x2112DDE8+1

        defadr CreateBook,0x2105506C+1
        defadr FreeBook,0x2105566C+1
        defadr BookObj_GotoPage,0x21054DE8+1
        defadr BookObj_ReturnPage,0x21054F50+1
        defadr BookObj_GetSession,0x210556B4+1
        defadr BookObj_GetBookID,0x21055714+1

        defadr IsAudioPlayerBook,0x20D2E30C+1
        defadr FindBook,0x21053808+1
        defadr FindBookEx,0x21053868+1
        defadr IsScreenSaverBook,0x21132970+1
        defadr MainDisplay_GetTopBook,0x210548A4+1
        defadr MediaPlayer_Audio_Minimize,0x20D30A68+1

        defadr GetSilent,0x20DB5DA0+1
        defadr PlaySystemSound,0x20DE314C+1

        defadr GoMusic,0x20FC2F84+1
        defadr Create_QuickAccessBook,0x2108203C+1
        defadr Create_RightNowBook,0x21129B10+1
        defadr IsVolumeControllerBook,0x21067CE8+1
        defadr IsRightNowBook,0x21129E8C+1
        defadr Find_StandbyBook,0x21068628+1
        defadr BookObj_SetFocus,0x210552FC+1
        defadr DispObject_GetGUI,0x210F9E84+1
        defadr GUIObject_GetBook,0x21103F4C+1
        defadr GUIObject_GetDispObject,0x21103F38+1
        defadr DispObject_GetOnKey,0x210F63A0+1
        defadr DispObject_GetDESC,0x20EEC090+1
        defadr DISP_DESC_SetOnKey,0x210F62D0+1
        
        defadr JavaDialog_Open,0x20C9B9E8+1
        defadr JavaAppDesc_GetFirstApp,0x20C95748+1
        defadr JavaAppDesc_GetJavaAppInfo,0x20C9537C+1
        defadr JavaApp_LogoImageID_Get,0x20D56F6C+1
        defadr JavaAppDesc_GetNextApp,0x20C95750+1
        defadr JavaDialog_Close,0x20C9F268+1
        defadr JavaSession_GetName,0x20ED384C+1
        defadr manifest_GetParam,0x21024398+1

        defadr List_DestroyElements,0x20F739D0+1
        defadr List_Destroy,0x20F73630+1
        defadr List_Create,0x20F7360C+1
        defadr List_Get,0x20F7388C+1
        defadr List_GetCount,0x20F73860+1
        defadr root_list_get_session_count,0x21053908+1
        defadr root_list_get_session,0x21053914+1
        defadr List_InsertFirst,0x20F73768+1

        defadr GUIObject_SoftKeys_SetAction,0x21120904+1
        defadr GUIObject_SoftKeys_SetText,0x2112097C+1
        defadr GUIObject_SoftKeys_SetVisible,0x211209CC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x21120C58+1

        EXTERN  LinkEditor
        EXTERN  New_OnOffKey_Short_Pressed
        EXTERN  New_OnOffKey_Long_Pressed

        ORG     0x21129B22      ; Fix ActivityMenu
        CODE16
	BEQ     0x21129B34      ; RightNowBook Not Exist => Create One
	BL      0x2105566C      ; RightNowBook Exist => Free RightNowBook
	B       0x21129B30      ; Exit

        RSEG    PATCH_WALKMANKEY1
        CODE16
	NOP
        
        RSEG    PATCH_WALKMANKEY2(1)
        CODE16
	MOV	R0, #0x1E

        RSEG    PATCH_WALKMANKEY3
        CODE16
	NOP

        RSEG    PATCH_WALKMANKEY4(1)
        CODE16
	MOV	R0, #0x1D

        RSEG    PATCH_ONOFFKEY
        DATA
	DCD     New_OnOffKey_Long_Pressed

        RSEG    PATCH_QUICKACCESS
        CODE16
        LDR     R3, =_quickaccess
        BX	R3

        RSEG    PATCH_SC_SOFTKEYS
        CODE16
        LDR     R3, =_softkeys
        BX	R3

        RSEG  CODE
        CODE16
_quickaccess:
        BNE     _exit
        BL      New_OnOffKey_Short_Pressed
_exit:
        MOV     R0, #1
        POP     {PC}

_softkeys:
        LDR     R2, =0x1A80
        MOV     R1, #0x21
        LDR     R0, [R6,#4]
        LDR     R3, =GUIObject_SoftKeys_SetText
        BLX     R3
        LDR     R2, =LinkEditor
        MOV     R1, #0x24
        LDR     R0, [R6,#4]
        LDR     R3, =GUIObject_SoftKeys_SetAction
        BLX     R3
        LDR     R2, =0xED4
        MOV     R1, #0x24
        LDR     R0, [R6,#4]
        LDR     R3, =GUIObject_SoftKeys_SetText
        BLX     R3
        LDR     R3, =0x2112E978+1
        BX	R3

        END
