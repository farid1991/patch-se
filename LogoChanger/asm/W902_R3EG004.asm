//W902_R3EG004

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x118B5EA8+1
        defadr memcpy,0x118B5DA8+1
        defadr snwprintf,0x107006BC+1
        defadr _fopen,0x10960338+1
        defadr fread,0x10961CCC+1
        defadr fclose,0x11721C80+1
        defadr fwrite,0x10961E98+1
        defadr fstat,0x10960C9C+1
        defadr lseek,0x10962040+1
        defadr w_fopen,0x112B57F4+1
        defadr w_lseek,0x11A761B0+1
        defadr w_fread,0x112B5824+1
        defadr w_fclose,0x112B5854+1
        defadr w_fstat,0x112B58AC+1
        defadr w_dirread,0x11A76840+1
        defadr w_diropen,0x4BB00354
        defadr w_chdir,0x4BB003AC
        defadr w_dirclose,0x4BB0038C
        defadr List_DestroyElements,0x11AEA1E8+1
        defadr List_Destroy,0x11AE9EFC+1
        defadr List_Create,0x11AE9ED4+1
        defadr List_InsertLast,0x11AEA050+1
        defadr List_Get,0x11AEA0F4+1
        defadr List_GetCount,0x11AEA0C8+1
        defadr getFileExtention,0x109639A8+1
        defadr FSX_MakeFullPath,0x10963ADC+1
        defadr FSX_FreeFullPath,0x10963B48+1
        defadr FSX_IsFileExists,0x1181919C+1
        defadr FileDelete,0x10960F2C+1
        defadr FILEITEM_GetFname,0x1181E380+1
        defadr FILEITEM_GetPath,0x1181E414+1
        defadr FILEITEM_GetFextension,0x1181E384+1
        defadr ImageID_Free,0x107AE74C+1
        defadr ImageID_GetIndirect,0x107A85CC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107AA5B4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107AA62C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107AA6B4+1
        defadr strlen,0x107004E4+1
        defadr strncpy,0x1070055C+1
        defadr strstr,0x107005F8+1
        defadr str2wstr,0x10D6F8B8+1
        defadr wstrcat,0x10700D7C+1
        defadr wstrlen,0x10D6E5F0+1
        defadr wstr2strn,0x10D6E710+1
        defadr wstrnupr,0x10D6E6C0+1
        defadr wstrcpy,0x10D6E634+1
        defadr wstrrchr,0x10D6F974+1
        defadr wstrcmp,0x10D6E604+1
        defadr wstrncmp,0x10700E50+1
        defadr Timer_Kill,0x10DF4D0C+1
        defadr Timer_ReSet,0x10DF4CB4+1
        defadr Timer_Set,0x10DF4C80+1
        defadr TextID_Create,0x10F69BBC+1
        defadr TextID_GetLength,0x10F6A000+1
        defadr TextID_Destroy,0x10F69EF8+1
        defadr TextID_CreateIntegerID,0x10F699E8+1
        defadr Disp_GetTextIDWidth,0x109D5A34+1
        defadr FreeBook,0x10DF8D20+1
        defadr FindBook,0x10DF68D8+1
        defadr FreeAllBook,0x10E2F450+1
        defadr CreateBook,0x10DF86A0+1
        defadr UI_Event,0x10DF7440+1
        defadr BookObj_CallPage,0x10DF84E4+1
        defadr BookObj_GotoPage,0x10DF83B0+1
        defadr BookObj_ReturnPage,0x10DF8568+1
        defadr BookObj_AddGUIObject,0x10DF8A30+1
        defadr BookObj_Hide,0x10DF8978+1
        defadr BookObj_GetBookID,0x10DF8E0C+1
        defadr BookObj_SetFocus,0x10DF8950+1
        defadr BookObj_GetDisplayOrientation,0x10DF8EA8+1
        defadr BookObj_SetDisplayOrientation,0x10DF8E44+1
        defadr IsAudioPlayerBook,0x10C8F7AC+1
        defadr CreateMessageBox,0x11A7B45C+1
        defadr DISP_DESC_SetName,0x109CDA88+1
        defadr DISP_DESC_SetSize,0x109CDA8C+1
        defadr DISP_DESC_SetOnCreate,0x109CDA90+1
        defadr DISP_DESC_SetOnClose,0x109CDA94+1
        defadr DISP_DESC_SetOnRedraw,0x109CDA98+1
        defadr DISP_DESC_SetOnKey,0x109CDAA0+1
        defadr DISP_DESC_SetOnLayout,0x109CDAAC+1
        defadr DISP_DESC_SetOnRefresh,0x109CDA9C+1
        defadr GUIObject_Create,0x109DA43C+1
        defadr GUIObject_SetStyle,0x109DA84C+1
        defadr GUIObject_GetStyle,0x109DA868+1
        defadr GUIObject_SetTitleType,0x109DA9EC+1
        defadr GUIObject_SetTitleText,0x109DAA08+1
        defadr GUIObject_Destroy,0x109DA600+1
        defadr GUIObject_Show,0x109DA7F4+1
        defadr GUIObject_GetDispObject,0x109DA68C+1
        defadr GUIObject_GetBook,0x109DA6A0+1
        defadr GUIObject_SetSecondRowTitleText,0x109DAA24+1
        defadr DispObject_GetGUI,0x109D08BC+1
        defadr DispObject_SetBacklightMode,0x109D3FB0+1
        defadr DispObject_InvalidateRect,0x109D0FD8+1
        defadr DispObject_SetLayerColor,0x109D31D0+1
        defadr DispObject_SetAnimation,0x109D3288+1
        defadr DispObject_GetStyle,0x109D3904+1
        defadr DispObject_SetStyle,0x109D3664+1
        defadr DispObject_SetRefreshTimer,0x109D0A40+1
        defadr DispObject_KillRefreshTimer,0x109D0ABC+1
        defadr DispObject_SetThemeImage,0x109D2D2C+1
        defadr GC_PutChar,0x109D908C+1
        defadr GetImageWidth,0x109D5980+1
        defadr GetImageHeight,0x109D5994+1
        defadr Display_GetWidth,0x1179F9B8+1
        defadr Display_GetHeight,0x1179F9AC+1
        defadr SetFont,0x109D52A8+1
        defadr DrawString,0x109D46E8+1
        defadr DrawRect,0x109D439C+1
        defadr get_DisplayGC,0x109D8650+1
        defadr GC_SetPenColor,0x109D8E60+1
        defadr GC_SetBrushColor,0x109D8F38+1
        defadr GC_DrawLine,0x109D95E0+1
        defadr GC_GetRect,0x109D8C94+1
        defadr GC_GetXX,0x109D8F90+1
        defadr GC_SetXX,0x109D8F84+1
        defadr GC_ValidateRect,0x109D8C44+1
        defadr GC_GetPenColor,0x109D8E9C+1
        defadr CreateListMenu,0x11AA36DC+1
        defadr ListMenu_GetSelectedItem,0x11AA38DC+1
        defadr ListMenu_SetItemCount,0x11AA38F0+1
        defadr ListMenu_SetTexts,0x11AA3A08+1
        defadr ListMenu_SetHotkeyMode,0x11AA3A2C+1
        defadr ListMenu_SetOnMessage,0x11AA3A00+1
        defadr ListMenu_SetCursorToItem,0x11AA38C8+1
        defadr ListMenu_SetItemStyle,0x11AA392C+1
        defadr ListMenu_SetNoItemText,0x11AA3A80+1
        defadr ListMenu_DestroyItems,0x11AA3D48+1
        defadr ListMenu_SetItemTextScroll,0x11AA3FD0+1
        defadr ListMenu_SetItemSecondLineText,0x11AA3CA4+1
        defadr GUIonMessage_GetMsg,0x11AA4490+1
        defadr GUIonMessage_GetBook,0x11AA4498+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11AA44B4+1
        defadr GUIonMessage_SetItemDisabled,0x11AA4568+1
        defadr GUIonMessage_SetMenuItemText,0x11AA44C0+1
        defadr GUIonMessage_SetMenuItemIcon,0x11AA4500+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11AA44F0+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11AA44E0+1
        defadr CreateOneOfMany,0x11AA5CB8+1
        defadr OneOfMany_SetTexts,0x11AA5E94+1
        defadr OneOfMany_SetItemCount,0x11AA5E44+1
        defadr OneOfMany_SetOnMessage,0x11AA5E8C+1
        defadr OneOfMany_SetChecked,0x11AA5E60+1
        defadr OneOfMany_GetSelected,0x11AA5E70+1
        defadr CreateTabMenuBar,0x1179D350+1
        defadr TabMenuBar_SetTabGui,0x1179D420+1
        defadr TabMenuBar_SetTabTitle,0x1179D4E8+1
        defadr TabMenuBar_SetTabIcon,0x1179D4A0+1
        defadr TabMenuBar_SetTabCount,0x1179D5A8+1
        defadr TabMenuBar_SetFocusedTab,0x1179D404+1
        defadr CreateStringInput,0x1089AF5C+1
        defadr StringInput_SetMode,0x1089B814+1
        defadr StringInput_SetFixedText,0x1089B958+1
        defadr StringInput_SetMinLen,0x1089B87C+1
        defadr StringInput_SetMaxLen,0x1089B92C+1
        defadr StringInput_SetEnableEmptyText,0x1089B9A0+1
        defadr StringInput_SetActionOK,0x1089B870+1
        defadr StringInput_GetStringAndLen,0x1089B8AC+1
        defadr StringInput_SetText,0x1089BA30+1
        defadr TextFeedbackWindow,0x1179E69C+1
        defadr Feedback_SetTextExtended,0x1179EB0C+1
        defadr Feedback_CloseAction,0x1179EA6C+1
        defadr CreateYesNoQuestion,0x1179F15C+1
        defadr YesNoQuestion_SetDescriptionText,0x1179F4B4+1
        defadr YesNoQuestion_SetQuestionText,0x1179F4C4+1
        defadr YesNoQuestion_SetIcon,0x1179F4E4+1
        defadr DispObject_SoftKeys_GetList,0x10812868+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x1081577C+1
        defadr GUIObject_SoftKeys_SetText,0x1081545C+1
        defadr GUIObject_SoftKeys_SetAction,0x108153E4+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x10815700+1
        defadr GUIObject_SoftKeys_Hide,0x1081579C+1
        defadr GUIObject_SoftKeys_Show,0x108157A8+1
        defadr GUIObject_SoftKeys_SetVisible,0x108154E0+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B74394+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1081564C+1
        defadr GUIObject_SoftKeys_SetInfoText,0x10815448+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x10815580+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x108157B4+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x108157C0+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AFB9AC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AFB904+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AFB94C+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x10AFB9DC+1
        defadr DispObject_SoftKeys_Show,0x10811944+1
        defadr DispObject_SoftKeys_Hide,0x1081190C+1
        defadr OSE_GetShell,0x10E17504+1
        defadr CoCreateInstance,0x10723BF0+1
        defadr DisplayGC_AddRef,0x109D8A88+1
        defadr MetaData_GetTags,0x118197B4+1
        defadr set_envp,0x10005C4C+1
        defadr get_envp,0x10005C38+1
        defadr Volume_Get,0x11A05340+1
        defadr Volume_Set,0x11A05274+1
        defadr KeygrabberWindow,0x109DADA8+1
        defadr MessageBox,0x11A7B3B8+1

        defadr INetworkServices_GetNetworkName,0x10FC8414+1
        defadr GetOperatorName,0x10FC82F0+1
        defadr SetOperatorName,0x10D96C18+1
        defadr GUIObject_SetTitleIcon,0x109DAA40+1

        defadr onBackPressed,0x10A66FC0+1
        defadr onLongBackPressed,0x10A6CA1C+1
        defadr pg_EditPhoneName_EnterEvent,0x10A66E44+1
        defadr pg_EditPhoneName_ExitEvent,0x10A64FC0+1

	EXTERN ReadOnFile
        EXTERN evtlst_EditPhoneName_new

//--------------------------------------

	RSEG	PATCH_NEW_EVENTLIST
	DATA
	DCD	evtlst_EditPhoneName_new

//--------------------------------------

	RSEG	PATCH_GET_NEWOPNAME
	CODE16
	LDR	R3, =Get_NewOpName
	BX	R3

	RSEG	CODE
        CODE16
Get_NewOpName:
        ADD     R5, R2, #0
	BL	ReadOnFile
        CMP     R0, #0
        BEQ     No_Patch
        MOV	R1, #0
        MOV     R2, #0xFF
        B       SetName
No_Patch:
        ADD     R2, R5,	#0
        MOV	R1, #0
	ADD     R0, R6,	#0
SetName:
        BL      j_TextID_Create
	ADD     R4, R0,	#0
        LDR     R3, =0x10FC83CC+1
        BX      R3

j_TextID_Create:
        LDR     R3, =TextID_Create
        BX      R3

        END
