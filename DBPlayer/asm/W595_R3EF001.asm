//W595_R3EF001

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010AC
        defadr memcpy,0x10147898
        defadr sprintf,0x106F81E0+1
        defadr snwprintf,0x106F8694+1
        defadr _fopen,0x10957B7C+1
        defadr fclose,0x11700750+1
        defadr fread,0x10959510+1
        defadr fwrite,0x109596DC+1
        defadr fstat,0x109584E0+1
        defadr lseek,0x10959884+1
        defadr strlen,0x106F84C4+1
        defadr strstr,0x106F85D0+1
        defadr strncmp,0x106F8500+1
        defadr strncpy,0x106F8534+1
        defadr strcat,0x106F8430+1
        defadr wstrcpy,0x10D661EC+1
        defadr wstrncpy,0x10D66204+1
        defadr wstrcat,0x106F8D54+1
        defadr wstrncat,0x10D6624C+1
        defadr wstrcmp,0x10D661BC+1
        defadr wstrlen,0x10D661A8+1
        defadr wstrrchr,0x10D6752C+1
        defadr wstr2strn,0x10D662C8+1
        defadr str2wstr,0x10D67470+1
        defadr wstrncmp,0x106F8E28+1
        defadr TextID_CreateIntegerID,0x10F61C68+1
        defadr TextID_Create,0x10F61E3C+1
        defadr TextID_GetString,0x10F62548+1
        defadr TextID_GetWString,0x10F623D0+1
        defadr TextID_GetLength,0x10F62280+1
        defadr TextID_Destroy,0x10F62178+1
        defadr get_envp,0x10005C38+1
        defadr set_envp,0x10005C4C+1
        defadr GC_GetRect,0x109D0624+1
        defadr GC_GetXX,0x109D0920+1
        defadr GC_SetXX,0x109D0914+1
        defadr GC_DrawLine,0x109D0F70+1
        defadr GC_GetPenColor,0x109D082C+1
        defadr GC_SetPenColor,0x109D07F0+1
        defadr GC_ValidateRect,0x109D05D4+1
        defadr BookObj_AddGUIObject,0x10DF0ABC+1
        defadr DrawRect,0x109CBD2C+1
        defadr DrawString,0x109CC078+1
        defadr SetFont,0x109CCC38+1
        defadr Disp_GetTextIDWidth,0x109CD3C4+1
        defadr DispObject_InvalidateRect,0x109C8968+1
        defadr GUIObject_GetDispObject,0x109D201C+1
        defadr GUIObject_Create,0x109D1DCC+1
        defadr get_DisplayGC,0x109CFFE0+1
        defadr DisplayGC_AddRef,0x109D0418+1
        defadr DISP_DESC_SetName,0x109C5418+1
        defadr DISP_DESC_SetSize,0x109C541C+1
        defadr DISP_DESC_SetOnCreate,0x109C5420+1
        defadr DISP_DESC_SetOnClose,0x109C5424+1
        defadr DISP_DESC_SetOnRedraw,0x109C5428+1
        defadr DISP_DESC_SetOnKey,0x109C5430+1
        defadr DISP_DESC_SetOnRefresh,0x109C542C+1
        defadr DISP_DESC_SetMethod06,0x109C5434+1
        defadr DISP_DESC_SetOnLayout,0x109C543C+1
        defadr DISP_DESC_SetOnConfig,0x109C5440+1
        defadr DispObject_SetLayerColor,0x109CAB60+1
        defadr DispObject_SetRefreshTimer,0x109C83D0+1
        defadr DispObject_KillRefreshTimer,0x109C844C+1
        defadr GUIonMessage_GetMsg,0x11A7E9F8+1
        defadr GUIonMessage_GetBook,0x11A7EA00+1
        defadr GUIonMessage_GetGui,0x11A7E9FC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A7EA1C+1
        defadr GUIonMessage_SetMenuItemText,0x11A7EA28+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A7EA58+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11A7EA38+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A7EA48+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A7EA68+1
        defadr GUIonMessage_SetItemDisabled,0x11A7EAD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107A2574+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107A25EC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107A2674+1
        defadr ImageID_Get,0x107A04F4+1
        defadr ImageID_Free,0x107A670C+1
        defadr ImageID_GetIndirect,0x107A058C+1
        defadr Timer_ReSet,0x10DECD40+1
        defadr Timer_Set,0x10DECD0C+1
        defadr Timer_Kill,0x10DECD98+1
        defadr CreateBook,0x10DF072C+1
        defadr BookObj_KillBook,0x10DF0840+1
        defadr BookObj_GotoPage,0x10DF043C+1
        defadr BookObj_ReturnPage,0x10DF05F4+1
        defadr BookObj_Hide,0x10DF0A04+1
        defadr BookObj_Show,0x10DF0A14+1
        defadr FreeBook,0x10DF0DAC+1
        defadr FindBook,0x10DF01F4+1
        defadr Display_GetHeight,0x1177DBF4+1
        defadr Display_GetWidth,0x1177DC00+1
        defadr GetImageWidth,0x109CD310+1
        defadr GetImageHeight,0x109CD324+1
        defadr CreateOneOfMany,0x11A80220+1
        defadr OneOfMany_SetItemCount,0x11A803AC+1
        defadr OneOfMany_SetChecked,0x11A803C8+1
        defadr OneOfMany_SetTexts,0x11A803FC+1
        defadr OneOfMany_GetSelected,0x11A803D8+1
        defadr CreateListMenu,0x11A7DC44+1
        defadr ListMenu_SetItemStyle,0x11A7DE94+1
        defadr ListMenu_SetItemCount,0x11A7DE58+1
        defadr ListMenu_SetOnMessage,0x11A7DF68+1
        defadr ListMenu_GetSelectedItem,0x11A7DE44+1
        defadr ListMenu_SetCursorToItem,0x11A7DE30+1
        defadr ListMenu_SetItemSecondLineText,0x11A7E20C+1
        defadr ListMenu_DestroyItems,0x11A7E2B0+1
        defadr CreateYesNoQuestion,0x1177D3A4+1
        defadr YesNoQuestion_SetDescriptionText,0x1177D70C+1
        defadr YesNoQuestion_SetQuestionText,0x1177D6FC+1
        defadr YesNoQuestion_SetIcon,0x1177D72C+1
        defadr GUIObject_SetStyle,0x109D21DC+1
        defadr GUIObject_SetTitleType,0x109D237C+1
        defadr GUIObject_SetTitleText,0x109D2398+1
        defadr GUIObject_Destroy,0x109D1F90+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D3A4+1
        defadr GUIObject_SoftKeys_SetText,0x1080D41C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6BB38+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D4A0+1
        defadr GUIObject_SoftKeys_Hide,0x1080D75C+1
        defadr GUIObject_SoftKeys_Show,0x1080D768+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1080D774+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1080D780+1
        defadr GUIObject_Show,0x109D2184+1
        defadr GUIObject_SetBacklightOn,0x109D22BC+1
        defadr GUIObject_SetBacklightOff,0x109D22E8+1
        defadr DispObject_SetAnimation,0x109CAC18+1
        defadr DispObject_SetBacklightMode,0x109CB940+1
        defadr DispObject_SetThemeImage,0x109CA6BC+1
        defadr FILEITEM_GetFname,0x117FC5B4+1
        defadr FILEITEM_GetPath,0x117FC648+1
        defadr FILEITEM_GetFextension,0x117FC5B8+1     
        defadr MetaData_GetTags,0x117F79E8+1     
        defadr CreateKeygrabberWindow,0x109D2738+1
        defadr Volume_Get,0x119DF98C+1
        defadr Volume_Set,0x119DF8C0+1
        defadr CoCreateInstance,0x1071BBB0+1
        defadr FSX_MakeFullPath,0x1095B320+1
        defadr FSX_FreeFullPath,0x1095B38C+1
        defadr FSX_IsFileExists,0x117F73D0+1
        defadr CreateMessageBox,0x11A559E8+1
        
        EXTERN CreateInfo

        RSEG   CODE
        CODE16
create_gui:
        ldr     r0, [r6,#4]
        ldr     r3, =FILEITEM_GetFextension
        blx     r3
        ldr     r1, =0x11F59204
        mov     r2, #3
        ldr     r3, =wstrncmp
        blx     r3
        cmp     r0, #0
        beq     isMID
        add     r1, r5, #0
        add     r0, r4, #0
        bl      CreateInfo
        b       _return
isMID:
        add     r0, r5, #0
        ldr     r3, =CreateKeygrabberWindow
        blx     r3
        str     r0, [r6,#0x14]
        cmp     r0, #0
        beq     _return
        ldr     r3, =0x117E75C0+1
        bx      r3

_return:
        mov     r0, #1
        pop     {r4-r7,pc}

        RSEG   CREATE_GUI
        CODE16
        ldr     r3, =create_gui
        bx      r3

        END
