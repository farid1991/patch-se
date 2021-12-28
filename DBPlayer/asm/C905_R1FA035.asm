//C905_R1FA035

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
        defadr memalloc,0x4BA31FA4
        defadr memfree,0x4BA31FCC
        defadr memset,0x14B7F1AC
        defadr snwprintf,0x14B77F24+1
        defadr _fopen,0x14117C0C+1
        defadr fclose,0x1438BB38+1
        defadr fread,0x141B9F14+1
        defadr fwrite,0x141B9AC8+1
        defadr fstat,0x14260F0C+1
        defadr CreateBook,0x1410E350+1
        defadr BookObj_GotoPage,0x142BB8A0+1
        defadr BookObj_ReturnPage,0x141E5B10+1
        defadr FreeBook,0x143DCA48+1
        defadr GUIObject_SetTitleText,0x1441DDB8+1
        defadr GUIObject_Show,0x144607E8+1
        defadr ListMenu_SetCursorToItem,0x14176DD4+1
        defadr GUIObject_SetStyle,0x1445E0A0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x14396384+1
        defadr GUIonMessage_SetMenuItemText,0x14482F64+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1411BABC+1
        defadr ListMenu_GetSelectedItem,0x14177470+1
        defadr ListMenu_SetItemStyle,0x14127A54+1
        defadr CreateOneOfMany,0x141952D0+1
        defadr OneOfMany_SetChecked,0x14211154+1
        defadr OneOfMany_SetTexts,0x1413A9A8+1
        defadr OneOfMany_GetSelected,0x1446FAE0+1
        defadr GUIObject_SoftKeys_SetAction,0x140FF438+1
        defadr GUIObject_SoftKeys_SetText,0x14397D0C+1
        defadr GUIObject_SoftKeys_SetVisible,0x140FF408+1
        defadr wstrlen,0x141BAAE4+1
        defadr TextID_Create,0x14100290+1
        defadr TextID_Destroy,0x142BD18C+1
        defadr GUIObject_GetDispObject,0x143ABFC8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14251F74+1
        defadr BookObj_Hide,0x14334F40+1
        defadr ListMenu_SetOnMessage,0x141DEA40+1
        defadr get_envp,0x101EDC5C+1
        defadr set_envp,0x101EDC70+1
        defadr UI_Event,0x142BB514+1
        defadr CreateListMenu,0x14460344+1
        defadr ListMenu_SetItemCount,0x14176C00+1
        defadr GUIObject_Destroy,0x144606B8+1
        defadr get_DisplayGC,0x143AB39C+1
        defadr GC_GetRect,0x1418DF04+1
        defadr GC_GetXX,0x141EDBB8+1
        defadr GC_SetXX,0x141EDD4C+1
        defadr BookObj_AddGUIObject,0x14460338+1
        defadr DrawRect,0x140C6440+1
        defadr DispObject_InvalidateRect,0x140E6ED4+1
        defadr GUIObject_Create,0x14460834+1
        defadr DISP_DESC_SetName,0x141596B8+1
        defadr DISP_DESC_SetSize,0x141596A8+1
        defadr DISP_DESC_SetOnCreate,0x141596B4+1
        defadr DISP_DESC_SetOnClose,0x1415962C+1
        defadr DISP_DESC_SetOnRedraw,0x141596B0+1
        defadr DISP_DESC_SetOnKey,0x141591AC+1
        defadr DISP_DESC_SetOnRefresh,0x142754E4+1
        defadr GC_GetPenColor,0x158D27D0+1
        defadr GC_SetPenColor,0x143AE1A4+1
        defadr GC_DrawLine,0x14274084+1
        defadr GUIObject_SetTitleType,0x14389EB4+1
        defadr GUIonMessage_SetItemDisabled,0x143B4018+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1513E1C0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1513E248+1
        defadr GUIObject_SoftKeys_Hide,0x140E5210+1
        defadr ListMenu_SetItemSecondLineText,0x1412A1F4+1
        defadr ImageID_Free,0x14201650+1
        defadr FILEITEM_GetFname,0x1407AA88+1
        defadr FILEITEM_GetPath,0x1407A9B0+1
        defadr DispObject_SetRefreshTimer,0x14200CC4+1
        defadr DispObject_KillRefreshTimer,0x14201098+1
        defadr ImageID_GetIndirect,0x1513C928+1
        defadr DispObject_SetLayerColor,0x1418CA7C+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1445DFBC+1
        defadr GUIonMessage_GetMsg,0x1439654C+1
        defadr ListMenu_DestroyItems,0x14176BB8+1
        defadr CoCreateInstance,0x1431432C+1
        defadr DispObject_SetAnimation,0x14EB3030+1
        defadr DisplayGC_AddRef,0x140C702C+1
        defadr TextObject_SetText,0x142BD794+1
        defadr TextObject_SetFont,0x14125054+1
        defadr Audio_GetTags,0x14E48040+1
        defadr CreateYesNoQuestion,0x141B78F4+1
        defadr YesNoQuestion_SetDescriptionText,0x1405FFF0+1
        defadr YesNoQuestion_SetQuestionText,0x1405FFE0+1
        defadr YesNoQuestion_SetIcon,0x142B92F4+1
        defadr MessageBox_NoIMAGE,0x14437A78+1
        defadr w_fopen,0x100B3BD8+1
        defadr w_lseek,0x1069649C+1
        defadr w_fclose,0x10149610+1
        defadr w_fread,0x10100EEC+1
        defadr DISP_DESC_SetOnLayout,0x141592C0+1
        defadr GUIObject_SoftKeys_Show,0x1445E260+1
        defadr FILEITEM_GetFextension,0x142E67F8+1
        defadr wstrncmp,0x14B784F0+1
        defadr Display_GetHeight,0x1418DC90+1
        defadr Display_GetWidth,0x1418DC9C+1
        defadr page_Sound_Run__PAGE_EXIT_EVENT, 0x14CD9F0C+1
        defadr DispObject_SetThemeImage, 0x14123C88+1
        
        EXTERN CreateInfo
        //EXTERN CloseInfo
        
        RSEG   CODE
        CODE16
create_gui:
        ldr r0, [r6,#4]
        ldr r3, =FILEITEM_GetFextension
        blx r3
        ldr r1, =0x15CB6704
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
        ldr r3, =0x14D204B4+1
        blx r3
        str r0, [r6,#0x14]
        cmp r0, #0
        beq ret
        ldr r3, =0x14D200B8+1
        bx r3
ret:
        mov r0, #1
        pop {r4-r7,pc}
        
        RSEG   CREATE_GUI
        CODE16
        ldr r3, =create_gui
        bx r3
        
        /*RSEG   CLOSE_GUI
        DATA
        dcd CloseInfo*/

        END