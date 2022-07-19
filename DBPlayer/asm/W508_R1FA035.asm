//W508_R1FA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA30DE8
        defadr memfree,0x4BA30E10
        defadr memset,0x14092910+1
        defadr memcpy,0x14044020+1
        defadr strlen,0x140922D8+1
        defadr strstr,0x141EB45C+1
        defadr strncpy,0x144C6004+1

        defadr set_envp,0x101F3448+1
        defadr get_envp,0x101F3434+1
        defadr FSX_FreeFullPath,0x1430AF3C+1
        defadr _fopen,0x1421A92C+1
        defadr fwrite,0x14572374+1
        defadr fclose,0x1410E040+1
        defadr fread,0x14310608+1
        defadr CoCreateInstance,0x14150FB8+1
        defadr TextObject_SetText,0x14225564+1
        defadr TextObject_SetFont,0x1419C6D0+1
        defadr get_DisplayGC,0x14049D50+1
        defadr DisplayGC_AddRef,0x1419BDB8+1
        defadr TextID_Copy,0x142264CC+1
        defadr TextID_GetWString,0x14225E3C+1
        defadr TextID_Create,0x14226B70+1
        defadr RichTextLayout_GetTextWidth,0x1433A98C+1
        defadr TextID_Destroy,0x142261D0+1
        defadr DrawRect,0x141158F4+1
        defadr ListMenu_DestroyItems,0x144318D0+1
        defadr ListMenu_SetItemCount,0x1421144C+1
        defadr ListMenu_GetSelectedItem,0x14542708+1
        defadr ListMenu_SetCursorToItem,0x14365EBC+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E1C8+1
        defadr ListMenu_SetItemSecondLineText,0x142E6374+1
        defadr OneOfMany_GetSelected,0x1451EC9C+1
        defadr GUIObject_Destroy,0x14221158+1
        defadr CreateOneOfMany,0x141BD674+1
        defadr GUIObject_SetTitleText,0x142E6810+1
        defadr OneOfMany_SetTexts,0x141C1F1C+1
        defadr OneOfMany_SetChecked,0x142889B4+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E17C+1
        defadr GUIObject_Show,0x14469D18+1
        defadr GC_GetRect,0x142E9A94+1
        defadr GC_GetXX,0x140EF134+1
        defadr GC_SetXX,0x1415CBC4+1
        defadr snwprintf,0x142C75F0+1
        defadr GC_GetPenColor,0x140FECE4+1
        defadr GC_SetPenColor,0x14049DB0+1
        defadr GC_DrawLine,0x1433B55C+1
        defadr DispObject_InvalidateRect,0x1404A6A0+1
        defadr DISP_DESC_SetName,0x1430C188+1
        defadr DISP_DESC_SetSize,0x1430C184+1
        defadr DISP_DESC_SetOnCreate,0x1430C104+1
        defadr DISP_DESC_SetOnClose,0x1430C18C+1
        defadr DISP_DESC_SetOnRedraw,0x1430C180+1
        defadr DISP_DESC_SetOnKey,0x1430BC7C+1
        defadr DISP_DESC_SetOnLayout,0x1430BDA0+1
        defadr DISP_DESC_SetOnRefresh,0x1430BC80+1
        defadr GUIObject_GetDispObject,0x14048B1C+1
        defadr GUIObject_Create,0x14469D60+1
        defadr BookObj_AddGUIObject,0x1422119C+1
        defadr GUIObject_SetTitleType,0x143BD238+1
        defadr GUIObject_SoftKeys_SetText,0x1412B034+1
        defadr GUIObject_SoftKeys_Show,0x14139C14+1
        defadr GUIObject_SoftKeys_Hide,0x1422173C+1
        defadr FreeBook,0x14366418+1
        defadr lseek,0x143101E8+1
        defadr ImageID_GetIndirect,0x15090404+1
        defadr MetaData_GetTags,0x14EC6C24+1
        defadr wstrlen,0x14311500+1
        defadr fstat,0x1435BA9C+1
        defadr wstrrchr,0x1409B4A4+1
        defadr wstrcat,0x1435AFF0+1
        defadr wstr2strn,0x144C7BE8+1
        defadr str2wstr,0x141604B4+1
        defadr wstrcpy,0x14310568+1
        defadr TextID_GetLength,0x142255FC+1
        defadr Timer_ReSet,0x142DAF34+1
        defadr Timer_Set,0x14505680+1
        defadr Timer_Kill,0x142DAED4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14ED5D30+1
        defadr ImageID_Free,0x144BF648+1
        defadr FSX_IsFileExists,0x144BFCC0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E40DE0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15092030+1
        defadr Volume_Get,0x1407A4B4+1
        defadr Display_GetWidth,0x142E9D78+1
        defadr Display_GetHeight,0x142E9D88+1
        defadr DispObject_SetBacklightMode,0x1400B9AC+1
        defadr DispObject_SetRefreshTimer,0x14114AAC+1
        defadr DispObject_KillRefreshTimer,0x1411468C+1
        defadr DispObject_SetThemeImage,0x14027A18+1
        defadr DispObject_SetLayerColor,0x142E8110+1
        defadr Volume_Set,0x1434309C+1
        defadr CreateMessageBox,0x14EBC290+1
        defadr BookObj_Hide,0x1422135C+1
        defadr BookObj_ReturnPage,0x14247260+1
        defadr GUIObject_SetStyle,0x142439D8+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EBD40+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x14F08DC8+1
        defadr GUIObject_SetBacklightOn,0x142439F4+1
        defadr GUIObject_SetBacklightOff,0x14DFE5B8+1
        defadr DispObject_SetAnimation,0x14E7EC30+1
        defadr FILEITEM_GetPath,0x144DD638+1
        defadr FILEITEM_GetFname,0x144DD63C+1
        defadr FSX_MakeFullPath,0x1435A8D4+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14241EC0+1
        defadr GUIonMessage_GetMsg,0x1412CC2C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CD24+1
        defadr GUIonMessage_SetItemDisabled,0x14246CC4+1
        defadr GUIonMessage_SetMenuItemText,0x14540388+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453FA40+1
        defadr GUIonMessage_GetBook,0x1412CA38+1
        defadr CreateListMenu,0x142211A8+1
        defadr ListMenu_SetOnMessage,0x143E9E50+1
        defadr ListMenu_SetItemStyle,0x14365B90+1
        defadr CreateYesNoQuestion,0x143F2514+1
        defadr YesNoQuestion_SetDescriptionText,0x14074A00+1
        defadr YesNoQuestion_SetQuestionText,0x140749F0+1
        defadr YesNoQuestion_SetIcon,0x14EEF27C+1
        defadr CreateBook,0x1446A50C+1
        defadr BookObj_GotoPage,0x14027124+1


        defadr wstrncmp,0x14310E1C+1
        defadr CreateKeyGrabber,0x14FEAF44+1
        defadr FILEITEM_GetFextension,0x144DD0E0+1

        EXTERN CreateInfo
        
        RSEG   CREATE_GUI
        CODE16
        ldr     r3, =create_gui
        bx      r3
        
        RSEG   CODE
        CODE16
create_gui:
        ldr     r0, [r6,#4]
        ldr     r3, =FILEITEM_GetFextension
        blx     r3
        ldr     r1, =0x15B81912
        mov     r2, #3
        ldr     r3, =wstrncmp
        blx     r3
        cmp     r0, #0
        beq     isMID
        mov     r1, r5
        mov     r0, r4
        bl      CreateInfo
        b       _exit
isMID:
        mov     r0, r5
        ldr     r3, =CreateKeyGrabber
        blx     r3
        str     r0, [r6,#0x14]
        cmp     r0, #0
        beq     _exit
        ldr     r3, =0x14D78E6C+1
        bx      r3
_exit:
        mov     r0, #1
        pop     {r4-r7,pc}

        END
