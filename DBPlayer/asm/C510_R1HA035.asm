//C510_R1HA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA32698
        defadr memfree,0x4BA326C0
        defadr memset,0x14B31C80
        defadr memcpy,0x1428AD94
        defadr snwprintf,0x143EEBC4+1
        defadr _fopen,0x141FA214+1
        defadr fclose,0x143CD0A0+1
        defadr fread,0x14178B8C+1
        defadr fwrite,0x143326C8+1
        defadr fstat,0x144D8BBC+1
        defadr lseek,0x141782E0+1
        defadr CreateBook,0x142866FC+1
        defadr BookObj_GotoPage,0x14481B20+1
        defadr BookObj_ReturnPage,0x14212A58+1
        defadr FreeBook,0x141293FC+1
        defadr GUIObject_SetTitleText,0x1443F740+1
        defadr GUIObject_Show,0x144CB9BC+1
        defadr ListMenu_SetCursorToItem,0x14417A80+1
        defadr GUIObject_SetStyle,0x14129878+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142C5BB4+1
        defadr GUIonMessage_SetMenuItemText,0x1438A538+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141326FC+1
        defadr ListMenu_GetSelectedItem,0x142800F8+1
        defadr ListMenu_SetItemStyle,0x140B9BF0+1
        defadr CreateOneOfMany,0x140B9B74+1
        defadr OneOfMany_SetChecked,0x1422CD38+1
        defadr OneOfMany_SetTexts,0x1419F5AC+1
        defadr OneOfMany_GetSelected,0x14457AA8+1
        defadr GUIObject_SoftKeys_SetAction,0x1417BACC+1
        defadr GUIObject_SoftKeys_SetText,0x141C50C8+1
        defadr GUIObject_SoftKeys_SetVisible,0x141C4E24+1
        defadr Timer_ReSet,0x1417A1C4+1
        defadr Timer_Set,0x1449FF70+1
        defadr Timer_Kill,0x1417A7F0+1
        defadr wstrcpy,0x144D851C+1
        defadr wstrncpy,0x143EEBF8+1
        defadr wstrcat,0x144D8474+1
        defadr wstrncat,0x14178F90+1
        defadr wstrcmp,0x144D9600+1
        defadr wstrlen,0x14178EC8+1
        defadr wstrncmp,0x14325C10+1
        defadr str2wstr,0x141C9A44+1
        defadr strcmp,0x14C0BA78+1
        defadr strlen,0x14C0BAD4+1
        defadr strncpy,0x1408B810+1
        defadr wstr2strn,0x140C1BF4+1
        defadr wstrrchr,0x143F196C+1
        defadr TextID_Copy,0x14181E88+1
        defadr TextID_CreateIntegerID,0x1401F5BC+1
        defadr TextID_Create,0x141818E4+1
        defadr TextID_GetString,0x14182108+1
        defadr TextID_GetWString,0x1418243C+1
        defadr TextID_GetLength,0x14183014+1
        defadr TextID_Destroy,0x14182788+1
        defadr GUIObject_GetDispObject,0x140CACD8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x144B9C9C+1
        defadr BookObj_Hide,0x142753C4+1
        defadr ListMenu_SetOnMessage,0x14302734+1
        defadr get_envp,0x101D68A8+1
        defadr set_envp,0x101D68BC+1
        defadr UI_Event,0x140C5938+1
        defadr CreateListMenu,0x14285AF8+1
        defadr ListMenu_SetItemCount,0x14280610+1
        defadr GUIObject_Destroy,0x144CBD98+1
        defadr get_DisplayGC,0x1449E09C+1
        defadr GC_GetRect,0x140C9E80+1
        defadr GC_GetXX,0x1419CE14+1
        defadr GC_SetXX,0x140B2DB8+1
        defadr BookObj_AddGUIObject,0x14285AEC+1
        defadr DrawRect,0x1445A7BC+1
        defadr DispObject_InvalidateRect,0x140CA948+1
        defadr GUIObject_Create,0x144CB8B0+1
        defadr DISP_DESC_SetName,0x142957C4+1
        defadr DISP_DESC_SetSize,0x142958A8+1
        defadr DISP_DESC_SetOnCreate,0x14295844+1
        defadr DISP_DESC_SetOnClose,0x14295840+1
        defadr DISP_DESC_SetOnRedraw,0x14295848+1
        defadr DISP_DESC_SetOnKey,0x14295990+1
        defadr DISP_DESC_SetOnRefresh,0x1429540C+1
        defadr GC_GetPenColor,0x14435440+1
        defadr GC_SetPenColor,0x1449E18C+1
        defadr GC_DrawLine,0x140917BC+1
        defadr GUIObject_SetTitleType,0x14093534+1
        defadr GUIonMessage_SetItemDisabled,0x144DF9F4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150D4864+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x150D48EC+1
        defadr GUIObject_SoftKeys_Hide,0x144CB138+1
        defadr ListMenu_SetItemSecondLineText,0x142A8E24+1
        defadr ImageID_Free,0x14410D58+1
        defadr FILEITEM_GetFname,0x142C7D74+1
        defadr FILEITEM_GetPath,0x142C7CA0+1
        defadr DispObject_SetRefreshTimer,0x1412E1BC+1
        defadr DispObject_KillRefreshTimer,0x1449F134+1
        defadr ImageID_GetIndirect,0x150D2C38+1
        defadr DispObject_SetLayerColor,0x140C6CA0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14129628+1
        defadr GUIonMessage_GetMsg,0x142C5CA4+1
        defadr GUIonMessage_GetBook,0x142C5E94+1
        defadr ListMenu_DestroyItems,0x14280984+1
        defadr CoCreateInstance,0x1401106C+1
        defadr DispObject_SetAnimation,0x14E1B408+1
        defadr DisplayGC_AddRef,0x144CDAA4+1
        defadr TextObject_SetText,0x14183164+1
        defadr TextObject_SetFont,0x1449CD74+1
        defadr RichTextLayout_GetTextWidth,0x14335244+1
        defadr MetaData_GetTags,0x157523B8+1
        defadr CreateYesNoQuestion,0x142CD924+1
        defadr YesNoQuestion_SetDescriptionText,0x14337444+1
        defadr YesNoQuestion_SetQuestionText,0x14337434+1
        defadr YesNoQuestion_SetIcon,0x14337428+1
        defadr MessageBox_NoIMAGE,0x14CE140C+1
        defadr w_fopen,0x100A6E5C+1
        defadr w_lseek,0x10589418+1
        defadr w_fclose,0x1013A908+1
        defadr w_fread,0x100F2E7C+1
        defadr DISP_DESC_SetOnLayout,0x14295474+1
        defadr GUIObject_SoftKeys_Show,0x1412982C+1
        defadr DispObject_SetBacklightMode,0x142F0190+1
        defadr DispObject_SoftKeys_Show,0x141297F4+1
        defadr DispObject_SoftKeys_Hide,0x144CB14C+1
        defadr DispObject_SetThemeImage,0x144815C4+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143AA4E8+1
        defadr FILEITEM_GetFextension,0x142C7EEC+1
        defadr Display_GetHeight,0x140C93BC+1
        defadr Display_GetWidth,0x140C93AC+1
        defadr GetFileLocation,0x1444000C+1
        defadr Volume_Set,0x1432EA7C+1
        defadr Volume_Get,0x1432FD48+1
        defadr FSX_MakeFullPath,0x141779BC+1
        defadr FSX_FreeFullPath,0x14336024+1
        defadr MakeFullPath,0x14298BE0+1
        defadr MessageBox_Animation,0x1585B1EC+1
        defadr CreateMessageBox,0x14CE140C+1
        defadr PlaySystemSound_SendEvent,0x14FA9150+1
        defadr GetMemoryStickStatus,0x142CE30C+1
        defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x14DDA4CC+1
        defadr FSX_IsFileExists,0x14411678+1
        defadr page_Sound_Run__PAGE_EXIT_EVENT, 0x14365430+1

        EXTERN CreateInfo
        EXTERN CloseInfo

        RSEG   CODE
        CODE16
create_gui:
        ldr     r0, [r6,#4]
        ldr     r3, =FILEITEM_GetFextension
        blx     r3
        ldr     r1, =0x15BE8EFC // "MID"
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
        ldr     r3, =0x14CC0D20+1
        blx     r3
        str     r0, [r6,#0x14]
        cmp     r0, #0
        beq     ret
        ldr     r3, =0x14CC0E08+1
        bx      r3
ret:
        mov     r0, #1
        pop     {r4-r7,pc}

        RSEG   CREATE_GUI
        CODE16
        ldr     r3, =create_gui
        bx      r3

        END