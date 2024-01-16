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
        defadr fstat,0x1435B64C+1
        defadr lseek,0x1430FE28+1

        defadr strlen,0x14D456D4+1
        defadr strcpy,0x14D456A0+1
        defadr strncpy,0x144C4A3C+1
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
        defadr GUIObject_SoftKeys_SetText,0x1412AD10+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E3A4+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E3F0+1
        defadr GUIObject_SoftKeys_Show,0x1413988C+1
        defadr GUIObject_SoftKeys_Hide,0x1422169C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14241D14+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x14139908+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EA834+1

        defadr Display_GetWidth,0x142E98C4+1
        defadr Display_GetHeight,0x142E98D4+1
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
        defadr ListMenu_SetItemSecondLineText,0x142E5EDC+1

        defadr GUIonMessage_GetMsg,0x1412C92C+1
        defadr GUIonMessage_GetBook,0x1412C728+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CA24+1
        defadr GUIonMessage_SetItemDisabled,0x14246BF0+1
        defadr GUIonMessage_SetMenuItemText,0x1453DBD0+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453D268+1

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

        EXTERN CreateInfo

        RSEG   CODE
        CODE16
create_gui:
        ldr     r0, [r6,#4]
        ldr     r3, =FILEITEM_GetFextension
        blx     r3
        ldr     r1, =0x15B62AF0
        mov     r2, #3
        ldr     r3, =wstrncmp
        blx     r3
        cmp     r0, #0
        beq     isMID
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateInfo
        b       ret
isMID:
        add     r0, r5, #0
        ldr     r3, =CreateKeygrabber
        blx     r3
        str     r0, [r6,#0x14]
        cmp     r0, #0
        beq     ret
        ldr     r3, =0x14DB4524+1
        bx      r3
ret:
        mov     r0, #1
        pop     {r4-r7,pc}

        RSEG   CREATE_GUI
        CODE16
        ldr     r3, =create_gui
        bx      r3

        END
