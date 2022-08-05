//W910_R1FA037

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x1009840C
        defadr memfree,0x10098434
        defadr memset,0x10B819EC+1
        defadr memcpy,0x10B818EC+1
        defadr debug_printf,0x2A20E309
        defadr sprintf,0x105101D4+1
        defadr snwprintf,0x10510688+1
        defadr _fopen,0x10FB34C4+1
        defadr fclose,0x1157A048+1
        defadr fread,0x10FB4C08+1
        defadr fwrite,0x10FB4DD4+1
        defadr fstat,0x10FB3DBC+1
        defadr lseek,0x10FB4F7C+1
        defadr FileCopy,0x10FB41C4+1
        defadr FileDelete,0x10FB3EE4+1
        defadr w_chdir,0x10098234
        defadr w_fopen,0x107A9DE0+1
        defadr w_fstat,0x107A9E98+1
        defadr w_fwrite,0x107A9E28+1
        defadr w_fread,0x107A9E10+1
        defadr w_lseek,0x113F093C+1
        defadr w_fclose,0x107A9E40+1
        defadr w_mkdir,0x100981CC
        defadr w_diropen,0x100981DC
        defadr w_dirread,0x113F0FCC+1
        defadr w_dirclose,0x1009821C
        defadr w_rename,0x113F1068+1
        defadr w_remove,0x113F101C+1
        defadr getFileExtention,0x10FB6804+1
        defadr FSX_MakeFullPath,0x10FB6938+1
        defadr FSX_FreeFullPath,0x10FB69A4+1
        defadr FSX_IsFileExists,0x10FFE98C+1
        defadr FILEITEM_GetFname,0x110035C8+1
        defadr FILEITEM_GetPath,0x1100365C+1
        defadr get_envp,0x100A3120+1
        defadr set_envp,0x100A3134+1
        defadr TextID_CreateIntegerID,0x116535C4+1
        defadr TextID_Create,0x11653784+1
        defadr TextID_Copy,0x11653928+1
        defadr TextID_Destroy,0x11653A1C+1
        defadr TextID_GetLength,0x11653AF0+1
        defadr TextID_GetString,0x11653D28+1
        defadr TextID_GetWString,0x11653BF0+1
        defadr Disp_GetTextIDWidth,0x1166FBC0+1
        defadr Display_GetHeight,0x1168569C+1
        defadr Display_GetWidth,0x116856A8+1
        defadr GetImageWidth,0x1166FB24+1
        defadr GetImageHeight,0x1166FB38+1
        defadr Volume_Set,0x11190990+1
        defadr Volume_Get,0x11190A5C+1
        defadr wstrcpy,0x10FA4984+1
        defadr wstrncpy,0x10FA499C+1
        defadr wstrcat,0x10FA49C8+1
        defadr wstrncat,0x10510DF0+1
        defadr wstrcmp,0x10FA4954+1
        defadr wstrlen,0x10FA4940+1
        defadr wstrrchr,0x10FA5CC4+1
        defadr wstrwstr,0x10510F7C+1
        defadr wstrcmpi,0x10FA5DA4+1
        defadr wstrchr,0x10510D64+1
        defadr wstrnupr,0x10FA4A10+1
        defadr wstrnlwr,0x112F0DA8+1
        defadr wstrncmp,0x10510E1C+1
        defadr wstr2strn,0x10FA4A60+1
        defadr str2wstr,0x10FA5C08+1
        defadr strcmp,0x1051045C+1
        defadr strlen,0x105104B8+1
        defadr strncmp,0x105104F4+1
        defadr strncpy,0x10510528+1
        defadr strcpy,0x10510484+1
        defadr strcat,0x10510424+1
        defadr strstr,0x105105C4+1
        defadr get_DisplayGC,0x1167362C+1
        defadr DispObject_GetRect,0x1166BA10+1
        defadr GC_PutChar,0x11674074+1
        defadr GC_DrawImage,0x1166E894+1
        defadr GC_GetRect,0x11673C74+1
        defadr GC_GetXX,0x11673F78+1
        defadr GC_SetXX,0x11673F6C+1
        defadr GC_ValidateRect,0x11673C24+1
        defadr GC_GetPenColor,0x11673E80+1
        defadr GC_SetPenColor,0x11673E44+1
        defadr GC_SetPixel,0x11673AC4+1
        defadr GC_DrawLine,0x11674904+1
        defadr GC_DrawFRect,0x11674A8C+1
        defadr GC_WritePixels,0x11673B50+1
        defadr GC_GetBrushColor,0x11673F60+1
        defadr GC_SetBrushColor,0x11673F20+1
        defadr GC_DrawRoundRect,0x11674AD4+1
        defadr BookObj_AddGUIObject,0x115D2EC4+1
        defadr DrawRect,0x1166E6A0+1
        defadr DrawString,0x1166E9A0+1
        defadr SetFont,0x1166F558+1
        defadr XGUIList_AddGUIObject,0x115D3310+1
        defadr DispObject_InvalidateRect,0x1166B7D0+1
        defadr DispObject_WindowSetSize,0x1166C860+1
        defadr GUIObject_Create,0x11675E00+1
        defadr GUIObject_SetStyle,0x11676144+1
        defadr GUIObject_GetStyle,0x1166DC68+1
        defadr GUIObject_SetTitleType,0x116765FC+1
        defadr GUIObject_SetTitleText,0x11676618+1
        defadr GUIObject_SetSecondRowTitleText,0x11676634+1
        defadr GUIObject_Show,0x116760EC+1
        defadr GUIObject_Destroy,0x11675EF0+1
        defadr GUIObject_GetBook,0x11675F74+1
        defadr GUIObject_GetDispObject,0x11675F60+1
        defadr DispObject_GetGUI,0x1166B0C4+1
        defadr DispObject_SetAnimation,0x1166D730+1
        defadr DispObject_SetStyle,0x1166DAD8+1
        defadr DispObject_GetStyle,0x1166DC68+1
        defadr DispObject_SetLayerColor,0x1166D678+1
        defadr DispObject_SetBacklightMode,0x1166E2F0+1
        defadr DispObject_SetBacklightTimeout,0x1166E328+1
        defadr DispObject_SetRefreshTimer,0x1166B250+1
        defadr DispObject_KillRefreshTimer,0x1166B2CC+1
        defadr DISP_DESC_SetName,0x116666AC+1
        defadr DISP_DESC_SetSize,0x116666B0+1
        defadr DISP_DESC_SetOnCreate,0x116666B4+1
        defadr DISP_DESC_SetOnClose,0x116666B8+1
        defadr DISP_DESC_SetOnRedraw,0x116666BC+1
        defadr DISP_DESC_SetOnKey,0x116666C4+1
        defadr DISP_DESC_SetOnRefresh,0x116666C0+1
        defadr DISP_DESC_SetMethod06,0x116666C8+1
        defadr DISP_DESC_SetOnLayout,0x116666D0+1
        defadr DISP_DESC_SetOnConfig,0x116666D4+1
        defadr DISP_DESC_SetMethod0A,0x116666D8+1
        defadr DISP_DESC_SetMethod0B,0x116666DC+1
        defadr DISP_DESC_SetMethod0C,0x116666E0+1
        defadr DispObject_GetOnKey,0x116667A0+1
        defadr DispObject_GetDESC,0x100B236C+1
        defadr Timer_ReSet,0x115CF764+1
        defadr Timer_Set,0x115CF730+1
        defadr Timer_Kill,0x115CF7BC+1
        defadr List_Create,0x113F1718+1
        defadr List_Destroy,0x113F1740+1
        defadr List_InsertFirst,0x113F188C+1
        defadr List_InsertLast,0x113F1894+1
        defadr List_Insert,0x113F1768+1
        defadr List_Find,0x113F19E8+1
        defadr List_Get,0x113F1938+1
        defadr List_GetCount,0x113F190C+1
        defadr List_DestroyElements,0x113F1A2C+1
        defadr CreateBook,0x115D2B70+1
        defadr BookObj_KillBook,0x115D2C8C+1
        defadr BookObj_GotoPage,0x115D28E8+1
        defadr BookObj_ReturnPage,0x115D2A50+1
        defadr BookObj_CallPage,0x115D29E8+1
        defadr BookObj_GetBookID,0x115D3228+1
        defadr BookObj_SetFocus,0x115D2E10+1
        defadr BookObj_GetSession,0x115D31C8+1
        defadr MainDisplay_GetTopBook,0x115D26E0+1
        defadr FreeBook,0x115D317C+1
        defadr FindBook,0x115D26C8+1
        defadr UI_Event,0x115D19B8+1
        defadr FreeAllBook,0x1145A330+1
        defadr Find_StandbyBook,0x115DE66C+1
        defadr UI_Event_toBookID,0x115D1A10+1
        defadr UI_Event_toBookIDwData,0x115D1A24+1
        defadr root_list_get_session_count,0x115D0D48+1
        defadr root_list_get_session,0x115D0D54+1
        defadr IsAudioPlayerBook,0x11584528+1
        defadr IsVolumeControllerBook,0x116AFAC4+1
        defadr IsRightNowBook,0x1169F1D8+1
        defadr BookObj_GetDisplayOrientation,0x115D32C8+1
        defadr BookObj_SetDisplayOrientation,0x115D3260+1
        defadr CreateListMenu,0x116276AC+1
        defadr ListMenu_SetItemCount,0x116278DC+1
        defadr ListMenu_SetCursorToItem,0x116278B4+1
        defadr ListMenu_GetSelectedItem,0x116278C8+1
        defadr ListMenu_SetTexts,0x116279F4+1
        defadr ListMenu_SetItemStyle,0x11627918+1
        defadr ListMenu_SetOnMessage,0x116279EC+1
        defadr ListMenu_SetNoItemText,0x11627A6C+1
        defadr ListMenu_SetItemTextScroll,0x1162801C+1
        defadr ListMenu_DestroyItems,0x11627DA0+1
        defadr ListMenu_SetHotkeyMode,0x11627A18+1
        defadr ListMenu_SetItemSecondLineText,0x11627CC4+1
        defadr GUIonMessage_GetMsg,0x116283B4+1
        defadr GUIonMessage_GetBook,0x116283BC+1
        defadr GUIonMessage_GetGui,0x116283B8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x116283D8+1
        defadr GUIonMessage_SetMenuItemText,0x116283E4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11628414+1
        defadr GUIonMessage_SetMenuItemInfoText,0x116283F4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11628404+1
        defadr GUIonMessage_SetMenuItemIcon,0x11628424+1
        defadr GUIonMessage_SetItemDisabled,0x11628484+1
        defadr GUIonMessage_GetSelectedItem,0x116283C0+1
        defadr CreateOneOfMany,0x11629A10+1
        defadr OneOfMany_SetItemCount,0x11629BBC+1
        defadr OneOfMany_SetChecked,0x11629BD8+1
        defadr OneOfMany_SetTexts,0x11629C0C+1
        defadr OneOfMany_GetSelected,0x11629BE8+1
        defadr OneOfMany_SetOnMessage,0x11629C04+1
        defadr CreateTabMenuBar,0x116830C0+1
        defadr TabMenuBar_SetTabCount,0x116832D8+1
        defadr TabMenuBar_SetTabGui,0x11683190+1
        defadr TabMenuBar_SetTabIcon,0x11683210+1
        defadr TabMenuBar_SetTabTitle,0x11683258+1
        defadr TabMenuBar_GetFocusedTab,0x11683184+1
        defadr TabMenuBar_SetFocusedTab,0x11683174+1
        defadr TextFeedbackWindow,0x11684518+1
        defadr Feedback_SetKeyHook,0x11684920+1
        defadr Feedback_SetOnClose,0x116848C0+1
        defadr Feedback_SetTimeout,0x116847DC+1
        defadr Feedback_SetTextExtended,0x11684984+1
        defadr Feedback_CloseAction,0x116848E8+1
        defadr TabMenuBar_SetOnTabSwitch,0x1168326C+1
        defadr iconidname2id,0x10CD7F38+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10F99E80+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10F99EF8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10F99F80+1
        defadr GUIObject_SoftKeys_SetAction,0x1168F908+1
        defadr GUIObject_SoftKeys_SetText,0x1168F980+1
        defadr GUIObject_SoftKeys_SetEnable,0x1168FA70+1
        defadr GUIObject_SoftKeys_AddErrorStr,0x1168FA28+1
        defadr GUIObject_SoftKeys_RemoveItem,0x1168F8BC+1
        defadr GUIObject_SoftKeys_SetVisible,0x1168FA04+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1168FCEC+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1168FCF8+1
        defadr GUIObject_SoftKeys_SetInfoText,0x1168F96C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1168FAA4+1
        defadr GUIObject_SoftKeys_Hide,0x1168FCD4+1
        defadr GUIObject_SoftKeys_Show,0x1168FCE0+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x1168FCB4+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x1168FC34+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1168FB44+1
        defadr DispObject_SoftKeys_GetList,0x1168CF68+1
        defadr DispObject_SoftKeys_Hide,0x1168C050+1
        defadr DispObject_SoftKeys_Show,0x1168C07C+1
        defadr ImageID_Free,0x10F9DF60+1
        defadr ImageID_GetIndirect,0x10F9D9A8+1
        defadr CoCreateInstance,0x116D60EC+1
        defadr OSE_GetShell,0x111B78E4+1
        defadr MetaData_GetTags,0x10FFEF54+1
        defadr MetaData_GetCover,0x11587F28+1
        defadr CreateMessageBox,0x115D88B8+1
        defadr MessageBox,0x115D886C+1
        defadr manifest_GetParam,0x10FC0B94+1
        defadr GetFreeBytesOnHeap,0x10098588
        defadr GUIObject_TabTitleRemove,0x1162802C+1
        defadr REQUEST_SYSTEM_SHUTDOWN,0x115DFE94+1
        defadr REQUEST_SYSTEM_RESTART,0x115DFEA4+1
        defadr Shortcut_Run,0x116963B4+1
        defadr FlightMode_GetState,0x115DD414+1
        defadr FlightMode_SetState,0x115DDA40+1
        defadr Request_ICA_ShutdownAllConnections,0x10994218+1
        defadr Display_GetBrightness,0x115F48C8+1
        defadr NewEvents_GetCount,0x116A5570+1
        defadr ConnectionManager_Connection_GetState,0x1140E68C+1
        defadr JavaSession_GetName,0x1113617C+1
        defadr JavaDialog_Open,0x10FCDDC8+1
        defadr JavaAppDesc_GetFirstApp,0x10FC3DD4+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10FC38E0+1
        defadr JavaApp_LogoImageID_Get,0x110ACC60+1
        defadr JavaAppDesc_GetNextApp,0x10FC3DDC+1
        defadr JavaDialog_Close,0x10FD14A4+1
        defadr Set_SWF_AsFlashMenu,0x1123896C+1
        defadr GetURIScheme,0x11473A1C+1
        defadr CreateURI,0x11473EB8+1
        defadr Browser_OpenURI,0x10F6EC70+1

        EXTERN FlashmenuPicker

        RSEG   PATCH_FD_SOFTKEYS
        CODE16
        ldr	r3, =fd_softkeys
        bx	r3

        RSEG   PATCH_MM_SOFTKEYS
        CODE16
        ldr	r3, =mm_softkeys
        bx	r3
        
        RSEG   CODE
        CODE16
fd_softkeys:
        ldr     r2, =0x112387A8+1
        ldr	r1, =0xFC2
        ldr     r0, [r5,#0]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x962
        mov     r1, #1
        ldr     r0, [r5,#0]
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #1
        ldr     r0, [r5,#0]
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x1123885A+1
        bx	r3

mm_softkeys:
        ldr     r2, =0x1169531C+1
        ldr	r1, =0xFAF
        add     r0, r4, #0
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr     r2, =0x965
        mov     r1, #6
        add     r0, r4, #0
        ldr	r3, =GUIObject_SoftKeys_SetText
        blx	r3
        ldr     r2, =FlashmenuPicker
        mov     r1, #6
        add     r0, r4, #0
        ldr	r3, =GUIObject_SoftKeys_SetAction
        blx	r3
        ldr	r3, =0x116954D2+1
        bx	r3

        END
