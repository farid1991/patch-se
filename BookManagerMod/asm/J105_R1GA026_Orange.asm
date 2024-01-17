//J105_R1GA026_Orange

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA315D0
        defadr memfree,0x4BA315F8
        defadr memset,0x14C5E22C
        defadr memcpy,0x144AF388
        defadr get_envp,0x101EF328+1
        defadr set_envp,0x101EF33C+1
        defadr _fopen,0x1421A8F0+1
        defadr fclose,0x1410DB44+1
        defadr fread,0x14310258+1
        defadr fwrite,0x1456FBC4+1
        defadr lseek,0x1430FE28+1
        defadr fstat,0x1435B64C+1
        defadr w_fstat,0x1017459C+1

        defadr strlen,0x14D456D4+1
        defadr strcmp,0x14D45678+1
        defadr strcpy,0x14D456A0+1
        defadr strncpy,0x144C4A3C+1
        defadr strstr,0x141EB2E0+1
        defadr sprintf,0x1411766C+1
        defadr snprintf,0x141176A4+1
        defadr str2wstr,0x14160498+1
        defadr snwprintf,0x142C711C+1
        defadr wstrcmp,0x14359708+1
        defadr wstrncmp,0x142C84D4+1
        defadr wstrlen,0x14310A10+1
        defadr wstrrchr,0x1409B028+1
        defadr wstrcat,0x1435AE5C+1
        defadr wstrcpy,0x1435AF0C+1

        defadr TextID_Create,0x142269C0+1
        defadr TextID_Destroy,0x14226030+1
        defadr TextID_Copy,0x1422632C+1
        defadr TextID_GetLength,0x1422545C+1
        defadr TextID_GetString,0x1422611C+1
        defadr TextID_GetWString,0x14225C8C+1
        defadr TextObject_SetText,0x142253C4+1
        defadr TextObject_SetFont,0x1419C8F8+1
        defadr RichTextLayout_GetTextWidth,0x1433A5EC+1

        defadr ImageID_Free,0x144BE000+1
        defadr ImageID_GetIndirect,0x150CBC80+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E7C480+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150CD8AC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14F11118+1

        defadr CreateBook,0x144692D4+1
        defadr FreeBook,0x143660F8+1
        defadr BookObj_Hide,0x1422132C+1
        defadr BookObj_GotoPage,0x14026D6C+1
        defadr BookObj_ReturnPage,0x1424718C+1
        defadr BookObj_SetFocus,0x14221630+1
        defadr BookObj_GetSession,0x140274DC+1
        defadr BookObj_GetBookID,0x1402681C+1
        defadr Find_StandbyBook,0x1444C938+1
        defadr UI_Event,0x1431C758+1
        defadr UI_Event_toBookID,0x1431DAB0+1
        defadr UI_Event_toBookIDwData,0x14366044+1
        defadr root_list_get_session_count,0x140636B4+1
        defadr root_list_get_session,0x1419EA6C+1

        defadr DrawRect,0x141154E4+1
        defadr get_DisplayGC,0x14049934+1
        defadr DisplayGC_AddRef,0x1419BFD0+1
        defadr GC_GetRect,0x142E95E0+1
        defadr GC_GetXX,0x140EEA64+1
        defadr GC_SetXX,0x1415CBA4+1
        defadr GC_GetPenColor,0x140FE674+1
        defadr GC_SetPenColor,0x14049994+1
        defadr GC_DrawLine,0x1433B1BC+1

        defadr DISP_DESC_SetName,0x1430BCF8+1
        defadr DISP_DESC_SetSize,0x1430BCF4+1
        defadr DISP_DESC_SetOnCreate,0x1430BC74+1
        defadr DISP_DESC_SetOnClose,0x1430BCFC+1
        defadr DISP_DESC_SetOnRedraw,0x1430BCF0+1
        defadr DISP_DESC_SetOnKey,0x1430B7EC+1
        defadr DISP_DESC_SetOnLayout,0x1430B910+1
        defadr DISP_DESC_SetOnRefresh,0x1430B7F0+1

        defadr BookObj_AddGUIObject,0x1422116C+1
        defadr GUIObject_Create,0x14468B28+1
        defadr GUIObject_Show,0x14468AE0+1
        defadr GUIObject_Destroy,0x14221128+1
        defadr GUIObject_GetDispObject,0x14048758+1
        defadr GUIObject_SetStyle,0x142438E4+1
        defadr GUIObject_SetTitleType,0x143BC844+1
        defadr GUIObject_SetTitleText,0x142E6378+1
        defadr GUIObject_TabTitleRemove,0x1506D43C+1
        defadr GUIObject_SoftKeys_SetText,0x1412AD10+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E3A4+1
        defadr GUIObject_SoftKeys_SetEnable,0x1412B064+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E3F0+1
        defadr GUIObject_SoftKeys_Show,0x1413988C+1
        defadr GUIObject_SoftKeys_Hide,0x1422169C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14241D14+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x14139908+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EA834+1

        defadr Display_GetWidth,0x142E98C4+1
        defadr Display_GetHeight,0x142E98D4+1
        defadr DispObject_GetOnKey,0x14462D8C+1
        defadr DispObject_GetDESC,0x150AAB3C+1
        defadr DispObject_SetBacklightMode,0x1400BB34+1
        defadr DispObject_SetRefreshTimer,0x1411469C+1
        defadr DispObject_KillRefreshTimer,0x14114278+1
        defadr DispObject_SetThemeImage,0x14027650+1
        defadr DispObject_SetLayerColor,0x142E7C6C+1
        defadr DispObject_SetAnimation,0x14EBA4B8+1
        defadr DispObject_InvalidateRect,0x1404A214+1

        defadr FILEITEM_GetPath,0x144DBFDC+1
        defadr FILEITEM_GetFname,0x144DBFE0+1
        defadr FILEITEM_GetFextension,0x144DBA84+1
        defadr FSX_IsFileExists,0x144BE678+1
        defadr FSX_MakeFullPath,0x1435A484+1
        defadr FSX_FreeFullPath,0x1430AAA4+1

        defadr CreateListMenu,0x14221178+1
        defadr ListMenu_SetOnMessage,0x143E8934+1
        defadr ListMenu_SetItemStyle,0x14365810+1
        defadr ListMenu_DestroyItems,0x1443047C+1
        defadr ListMenu_SetItemCount,0x14211344+1
        defadr ListMenu_GetSelectedItem,0x1453FF50+1
        defadr ListMenu_SetCursorToItem,0x14365B3C+1
        defadr ListMenu_SetNoItemText,0x14FBF6E8+1
        defadr ListMenu_SetItemSecondLineText,0x142E5EDC+1

        defadr GUIonMessage_GetMsg,0x1412C92C+1
        defadr GUIonMessage_GetBook,0x1412C728+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CA24+1
        defadr GUIonMessage_GetSelectedItem,0x1453F9CC+1
        defadr GUIonMessage_SetItemDisabled,0x14246BF0+1
        defadr GUIonMessage_SetMenuItemText,0x1453DBD0+1
        defadr GUIonMessage_SetMenuItemIcon,0x14159AA4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453D268+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14FFE788+1

        defadr CreateTabMenuBar,0x142444E4+1
        defadr TabMenuBar_SetOnTabSwitch,0x142444E0+1
        defadr TabMenuBar_GetFocusedTab,0x1453DC34+1
        defadr TabMenuBar_SetTabGui,0x142F616C+1
        defadr TabMenuBar_SetTabTitle,0x143BD408+1

        defadr CreateOneOfMany,0x141BDAC4+1
        defadr OneOfMany_SetTexts,0x141C2424+1
        defadr OneOfMany_SetChecked,0x1428882C+1
        defadr OneOfMany_GetSelected,0x1451C634+1

        defadr CreateYesNoQuestion,0x143F1030+1
        defadr YesNoQuestion_SetDescriptionText,0x14074478+1
        defadr YesNoQuestion_SetQuestionText,0x14074468+1
        defadr YesNoQuestion_SetIcon,0x14F2A6F8+1

        defadr Timer_ReSet,0x142DA9D4+1
        defadr Timer_Set,0x14502F24+1
        defadr Timer_Kill,0x142DA974+1
        defadr Volume_Get,0x1407A02C+1
        defadr Volume_Set,0x14342D2C+1
        defadr OSE_GetShell,0x142DB418+1
        defadr CoCreateInstance,0x14150FA4+1

        defadr MetaData_GetTags,0x14F022D4+1
        defadr CreateMessageBox,0x14EF78FC+1
        defadr CreateKeygrabber,0x15026150+1

        defadr Shortcut_Run,0x1456D6F8+1
        defadr List_DestroyElements,0x1424F6E8+1
        defadr List_Destroy,0x14026234+1
        defadr List_Create,0x142DAB98+1
        defadr List_Get,0x14310ED8+1
        defadr List_GetCount,0x14311164+1
        defadr List_InsertFirst,0x1424C77C+1
        defadr IsVolumeControllerBook,0x141BDC50+1
        defadr IsRightNowBook,0x14009B34+1
        defadr JavaDialog_Open,0x141C75FC+1
        defadr JavaDialog_Close,0x144ED080+1
        defadr JavaAppDesc_GetFirstApp,0x141CB128+1
        defadr JavaAppDesc_GetNextApp,0x144ED188+1
        defadr JavaAppDesc_GetJavaAppInfo,0x144EC170+1
        defadr JavaApp_LogoImageID_Get,0x142B6E8C+1

        defadr Request_ICA_ShutdownAllConnections,0x104F7730+1
        defadr ConnectionManager_Connection_GetState_int,0x144BE1D8+1
        defadr Display_GetBrightness,0x14E11E6C+1

        defadr NewEvents_GetCount,0x14FEE3C8+1
        defadr iconidname2id,0x143588B8+1

        defadr MessageBox,0x15885254+1
        defadr manifest_GetParam,0x14336D2C+1
        defadr GetFreeBytesOnHeap,0x4BA3173C
        defadr REQUEST_SYSTEM_SHUTDOWN,0x1046CF60+1
        defadr REQUEST_SYSTEM_RESTART,0x1046CF80+1
        defadr FlightMode_GetState,0x14153F08+1
        defadr FlightMode_SetState,0x14DB0B70+1

        EXTERN GetFocusTab
        EXTERN CreateBookAndElfsLists
        EXTERN ActivityBook_onClose
        EXTERN EventsTitleText
        EXTERN CreateBookMenu
        EXTERN CreateElfMenu
        EXTERN CreateShortcutMenu

        RSEG   TAB_ICON_1
        CODE16
        ldr     r7, =_IconInternet
        bx      r7

        RSEG   TAB_ICON_2
        DATA
        DCD     0x82E

        RSEG   TAB_FOCUS
        CODE16
        ldr     r3, =_Tabfocus
        bx      r3

        RSEG   GUI_CREATE
        CODE16
        ldr     r3, =_onCreate
        bx      r3

        RSEG   BOOK_CLOSE
        CODE16
        ldr     r3, =_onClose
        bx      r3

        RSEG   EVENTS
        CODE16
        ldr     r3, =EventsTitleText
        bx      r3

        RSEG   INTERNET
        CODE16
        ldr     r3, =_Internet
        bx      r3

        RSEG   SHORTCURTS
        CODE16
        ldr     r3, =_Shortcurts
        bx      r3

        RSEG   ACTIVETASKS
        CODE16
        ldr     r3, =_Activetasks
        bx      r3

        RSEG   CODE
        CODE16
_IconInternet:
        str     r3, [r0,#4]
        ldr     r1, =0x834
        strh    r1, [r0,#8]
        sub     r1, r1, #1
        strh    r1, [r0,#0xA]
        ldr     r1, =0xCEE
        str     r1, [r0,#0xC]
        pop     {r4,r5,pc}

_Tabfocus:
        ldr     r3, =0x14FEE8FC+1
        blx     r3
        cmp     r0, #0
        beq     set_focus
        ldr     r3, =0x14FEE5C8+1
        bx      r3
set_focus:
        bl      GetFocusTab
        add     r5, r0, #0
        ldr     r3, =0x14FEE5E6+1
        bx      r3

_onCreate:
        bl      CreateBookAndElfsLists
        ldr     r1, =0x1402344C+1
        ldr     r0, [r4,#0x24]
        ldr     r3, =TabMenuBar_SetOnTabSwitch
        blx     r3
        ldr     r3, =0x14FEE48C+1
        bx      r3

_onClose:
        bl      ActivityBook_onClose
        add     r0, r4, #0
        ldr     r3, =0x14FF56BC+1
        blx     r3
        pop     {r4,r5,pc}

_Internet:
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateShortcutMenu
        pop     {r4-r6,pc}

_Shortcurts:
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateElfMenu
        pop     {r4-r6,pc}

_Activetasks:
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateBookMenu
        pop     {r4-r6,pc}

        END
