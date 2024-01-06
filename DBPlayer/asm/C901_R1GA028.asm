//C901_R1GA028

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA322A0
        defadr memfree,0x4BA322C8
        defadr memset,0x14B963E8
        defadr memcpy,0x15020818
        defadr snwprintf,0x144A1298+1
        defadr _fopen,0x1403EC8C+1
        defadr fclose,0x140FC858+1
        defadr fread,0x144C11BC+1
        defadr fwrite,0x141BFE70+1
        defadr fstat,0x14290474+1
	defadr lseek,0x144C3468+1
        defadr CreateBook,0x144AA4FC+1
        defadr BookObj_GotoPage,0x1404559C+1
        defadr BookObj_ReturnPage,0x142C9B50+1
        defadr FreeBook,0x14132BCC+1
        defadr GUIObject_SetTitleText,0x1410F8F0+1
        defadr GUIObject_Show,0x144AB150+1
        defadr ListMenu_SetCursorToItem,0x14131CB8+1
        defadr GUIObject_SetStyle,0x141320D8+1
	defadr GUIonMessage_GetBook,0x142EFB8C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142EFB80+1
        defadr GUIonMessage_SetMenuItemText,0x142EF65C+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FDDAC+1
        defadr ListMenu_GetSelectedItem,0x1411B32C+1
        defadr ListMenu_SetItemStyle,0x140F5D1C+1
        defadr CreateOneOfMany,0x140F5CA0+1
        defadr OneOfMany_SetChecked,0x14110A9C+1
        defadr OneOfMany_SetTexts,0x141ACEE0+1
        defadr OneOfMany_GetSelected,0x14FE1FE4+1
        defadr GUIObject_SoftKeys_SetAction,0x141047B0+1
        defadr GUIObject_SoftKeys_SetText,0x141044E8+1
        defadr GUIObject_SoftKeys_SetVisible,0x1410478C+1
        defadr strlen,0x14C803F0+1
	defadr strncpy,0x14442270+1
	defadr wstrncmp,0x14120ACC+1
	defadr wstrcat,0x1428FDC8+1
	defadr wstr2strn,0x1409DB7C+1
	defadr str2wstr,0x1428E948+1
	defadr wstrcpy,0x1428FE70+1
	defadr wstrrchr,0x1409EB58+1
        defadr wstrlen,0x144C1510+1
        defadr TextID_Create,0x142D6F24+1
        defadr TextID_Destroy,0x1416EC2C+1
        defadr TextID_Copy,0x1416E374+1
        defadr TextID_GetWString,0x1416E898+1
	defadr TextID_GetLength,0x1416F444+1
        defadr GUIObject_GetDispObject,0x1416CEAC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14DF8334+1
        defadr BookObj_Hide,0x142009DC+1
        defadr ListMenu_SetOnMessage,0x142D9214+1
        defadr get_envp,0x101D5524+1
        defadr set_envp,0x101D5538+1
        defadr UI_Event,0x1439F6E8+1
        defadr CreateListMenu,0x141322D4+1
        defadr ListMenu_SetItemCount,0x142D9228+1
        defadr GUIObject_Destroy,0x14510368+1
        defadr get_DisplayGC,0x1416BB04+1
        defadr GC_GetRect,0x14116F48+1
        defadr GC_GetXX,0x142320E0+1
        defadr GC_SetXX,0x1419BFB4+1
        defadr BookObj_AddGUIObject,0x141322C8+1
        defadr DrawRect,0x14107010+1
        defadr DispObject_InvalidateRect,0x1416AB80+1
        defadr GUIObject_Create,0x144AB648+1
        defadr DISP_DESC_SetName,0x145076E0+1
        defadr DISP_DESC_SetSize,0x1450772C+1
        defadr DISP_DESC_SetOnCreate,0x145076D4+1
        defadr DISP_DESC_SetOnClose,0x145076DC+1
        defadr DISP_DESC_SetOnRedraw,0x14507730+1
        defadr DISP_DESC_SetOnKey,0x14507B38+1
        defadr DISP_DESC_SetOnRefresh,0x14507B34+1
        defadr GC_GetPenColor,0x14E1AE08+1
        defadr GC_SetPenColor,0x14107384+1
        defadr GC_DrawLine,0x144E0344+1
        defadr GUIObject_SetTitleType,0x143A114C+1
        defadr GUIonMessage_SetItemDisabled,0x14257F3C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150A1E5C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x150A1EE4+1
        defadr GUIObject_SoftKeys_Hide,0x14510224+1
        defadr ListMenu_SetItemSecondLineText,0x142D9098+1
        defadr ImageID_Free,0x1447FEEC+1
        defadr FILEITEM_GetFname,0x142DAC0C+1
        defadr FILEITEM_GetPath,0x142DAC10+1
        defadr DispObject_SetRefreshTimer,0x14233F70+1
        defadr DispObject_KillRefreshTimer,0x14118678+1
        defadr ImageID_GetIndirect,0x150A0228+1
        defadr DispObject_SetLayerColor,0x144ABD2C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A0014+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1439FE74+1
        defadr GUIonMessage_GetMsg,0x142EFC74+1
        defadr ListMenu_DestroyItems,0x143C2398+1
        defadr CoCreateInstance,0x14460170+1
        defadr DispObject_SetAnimation,0x14E2EEE0+1
        defadr DisplayGC_AddRef,0x143CEE40+1
        defadr TextObject_SetText,0x1416F57C+1
        defadr TextObject_SetFont,0x14172478+1
	defadr RichTextLayout_GetTextWidth,0x14421A98+1
        defadr Timer_ReSet,0x14169C08+1
        defadr Timer_Set,0x1423CE6C+1
        defadr Timer_Kill,0x14169EF8+1
        defadr MetaData_GetTags,0x14DD9954+1
        defadr CreateYesNoQuestion,0x14234CB8+1
        defadr YesNoQuestion_SetDescriptionText,0x14082B70+1
        defadr YesNoQuestion_SetQuestionText,0x14082B60+1
        defadr YesNoQuestion_SetIcon,0x15009C94+1
        defadr CreateMessageBox,0x14E082FC+1
	defadr w_fopen,0x100A6A24+1
        defadr w_lseek,0x10586FD8+1
        defadr w_fclose,0x10139508+1
        defadr w_fread,0x100F27D8+1
        defadr DISP_DESC_SetOnLayout,0x14507ADC+1
        defadr GetIMEI,0x1442CB74+1
        defadr GUIObject_SoftKeys_Show,0x1439FF34+1
	defadr FILEITEM_GetFextension,0x142DA668+1
	defadr Display_GetHeight,0x1411A5F8+1
	defadr Display_GetWidth,0x141A9130+1
	defadr FSX_IsFileExists,0x14EFF400+1
	defadr FSX_MakeFullPath,0x144C033C+1
	defadr FSX_FreeFullPath,0x14043000+1
	defadr Volume_Get,0x14273244+1
	defadr Volume_Set,0x14273440+1
	defadr DispObject_SetBacklightMode,0x14236290+1
	defadr DispObject_SetThemeImage,0x144ADF60+1
	defadr GUIObject_SoftKeys_SetActionAndText,0x143F32EC+1

        EXTERN CreateInfo

        RSEG   CODE
        CODE16
create_gui:
        ldr     r0, [r6,#4]
        ldr     r3, =FILEITEM_GetFextension
        blx     r3
        ldr     r1, =0x15BCD350
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
        ldr     r3, =0x14FE5070+1
        blx     r3
        str     r0, [r6,#0x14]
        cmp     r0, #0
        beq     ret
        ldr     r3, =0x14FE5168+1
        bx      r3
ret:
        mov     r0, #1
        pop     {r4-r7,pc}

        RSEG   CREATE_GUI
        CODE16
        ldr     r3, =create_gui
        bx      r3

        END