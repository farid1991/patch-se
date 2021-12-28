//J105_R1HA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
        defadr memalloc,0x4BA31878
        defadr memfree,0x4BA318A0
        defadr memset,0x14BFE6B0
        defadr snwprintf,0x142C7B60+1
        defadr _fopen,0x1421B238+1
        defadr fclose,0x1410E4AC+1
        defadr fread,0x14310C8C+1
        defadr fwrite,0x14570230+1
        defadr fstat,0x1435C128+1
        defadr CreateBook,0x14469888+1
        defadr BookObj_GotoPage,0x14026BF8+1
        defadr BookObj_ReturnPage,0x14247D54+1
        defadr FreeBook,0x14366C70+1
        defadr GUIObject_SetTitleText,0x142E6CC0+1
        defadr GUIObject_Show,0x14469098+1
        defadr ListMenu_SetCursorToItem,0x143666B4+1
        defadr GUIObject_SetStyle,0x1424449C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412D404+1
        defadr GUIonMessage_SetMenuItemText,0x1453DF98+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453D62C+1
        defadr ListMenu_GetSelectedItem,0x145403DC+1
        defadr ListMenu_SetItemStyle,0x14366388+1
        defadr CreateOneOfMany,0x141BE5B4+1
        defadr OneOfMany_SetChecked,0x14289498+1
        defadr OneOfMany_SetTexts,0x141C2F20+1
        defadr OneOfMany_GetSelected,0x1451C860+1
        defadr GUIObject_SoftKeys_SetAction,0x1419EE8C+1
        defadr GUIObject_SoftKeys_SetText,0x1412B6B4+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419EED8+1
        defadr wstrlen,0x14311444+1
        defadr TextID_Create,0x14227418+1
        defadr TextID_Destroy,0x14226A40+1
        defadr GUIObject_GetDispObject,0x14048674+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E1D360+1
        defadr BookObj_Hide,0x14221C8C+1
        defadr ListMenu_SetOnMessage,0x143E93F0+1
        defadr get_envp,0x101F12DC+1
        defadr set_envp,0x101F12F0+1
        defadr UI_Event,0x1431D17C+1
        defadr CreateListMenu,0x14221AD8+1
        defadr ListMenu_SetItemCount,0x14211C9C+1
        defadr GUIObject_Destroy,0x14221A88+1
        defadr get_DisplayGC,0x14049850+1
        defadr GC_GetRect,0x142E9F44+1
        defadr GC_GetXX,0x140EF38C+1
        defadr GC_SetXX,0x1415D5CC+1
        defadr BookObj_AddGUIObject,0x14221ACC+1
        defadr DrawRect,0x14115E3C+1
        defadr DispObject_InvalidateRect,0x1404A130+1
        defadr GUIObject_Create,0x144690E0+1
        defadr DISP_DESC_SetName,0x1430C704+1
        defadr DISP_DESC_SetSize,0x1430C700+1
        defadr DISP_DESC_SetOnCreate,0x1430C680+1
        defadr DISP_DESC_SetOnClose,0x1430C708+1
        defadr DISP_DESC_SetOnRedraw,0x1430C6FC+1
        defadr DISP_DESC_SetOnKey,0x1430C1F8+1
        defadr DISP_DESC_SetOnRefresh,0x1430C1FC+1
        defadr GC_GetPenColor,0x140FEFBC+1
        defadr GC_SetPenColor,0x140498B0+1
        defadr GC_DrawLine,0x1433BBFC+1
        defadr GUIObject_SetTitleType,0x143BD2F8+1
        defadr GUIonMessage_SetItemDisabled,0x142477B0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15070168+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14EB24D4+1
        defadr GUIObject_SoftKeys_Hide,0x14222004+1
        defadr ListMenu_SetItemSecondLineText,0x142E67F8+1
        defadr ImageID_Free,0x144BE7B0+1
        defadr FILEITEM_GetFname,0x144DC81C+1
        defadr FILEITEM_GetPath,0x144DC818+1
        defadr DispObject_SetRefreshTimer,0x14114FF4+1
        defadr DispObject_KillRefreshTimer,0x14114BD0+1
        defadr ImageID_GetIndirect,0x1506E53C+1
        defadr DispObject_SetLayerColor,0x142E85D0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1424288C+1
        defadr GUIonMessage_GetMsg,0x1412D30C+1
        defadr ListMenu_DestroyItems,0x14430998+1
        defadr CoCreateInstance,0x1415188C+1
        defadr DispObject_SetAnimation,0x14E5B5C4+1
        defadr DisplayGC_AddRef,0x1419CA94+1
        defadr TextObject_SetText,0x14225D4C+1
        defadr TextObject_SetFont,0x1419D3BC+1
        defadr Timer_ReSet,0x142DB25C+1
        defadr Timer_Set,0x14503354+1
        defadr Timer_Kill,0x142DB1FC+1
        defadr Audio_GetTags,0x14EA361C+1
        defadr CreateYesNoQuestion,0x143F1B40+1
        defadr YesNoQuestion_SetDescriptionText,0x140743B0+1
        defadr YesNoQuestion_SetQuestionText,0x140743A0+1
        defadr YesNoQuestion_SetIcon,0x14ECBBCC+1
        defadr MessageBox_NoIMAGE,0x14E98BD8+1
        defadr w_fopen,0x10091AFC+1
        defadr w_lseek,0x142CE2F8+1
        defadr w_fclose,0x10148768+1
        defadr w_fread,0x101765A8+1
        defadr DISP_DESC_SetOnLayout,0x1430C31C+1
        defadr GetIMEI,0x14232CF4+1
        defadr GUIObject_SoftKeys_Show,0x1413A214+1
        defadr FILEITEM_GetFextension,0x144DC2C0+1
        defadr wstrncmp,0x142C8F18+1
        defadr Display_GetHeight,0x142EA238+1
        defadr Display_GetWidth,0x142EA228+1
		
        EXTERN CreateInfo
        
        RSEG   CODE
        CODE16
create_gui:
        ldr r0, [r6,#4]
        ldr r3, =FILEITEM_GetFextension
        blx r3
        ldr r1, =0x15AF9F5C
        mov r2, #3
        ldr r3, =wstrncmp
        blx r3
        cmp r0, #0
        beq isMID
        mov r2, r5
        mov r1, r6
        mov r0, r4
        bl CreateInfo
        b ret
isMID:
        mov r0, r5
        ldr r3, =0x14FC8208+1
        blx r3
        str r0, [r6,#0x14]
        cmp r0, #0
        beq ret
        ldr r3, =0x14D54BD8+1
        bx r3
ret:
        mov r0, #1
        pop {r4-r7,pc}
        
        RSEG   CREATE_GUI
        CODE16
        ldr r3, =create_gui
        bx r3

        END