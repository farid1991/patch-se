//W995_R1GA026

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM
        defadr memalloc,0x4BA3372C
        defadr memfree,0x4BA33754
        defadr memset,0x14C4F00C
        defadr snwprintf,0x144A2B14+1
        defadr _fopen,0x1403EDD8+1
        defadr fclose,0x140FD31C+1
        defadr fread,0x144C2A80+1
        defadr fwrite,0x141C0C0C+1
        defadr fstat,0x142915EC+1
        defadr CreateBook,0x144ABDB0+1
        defadr BookObj_GotoPage,0x1404570C+1
        defadr BookObj_ReturnPage,0x142CAC50+1
        defadr FreeBook,0x1413366C+1
        defadr GUIObject_SetTitleText,0x141103BC+1
        defadr GUIObject_Show,0x144AC9FC+1
        defadr ListMenu_SetCursorToItem,0x14132758+1
        defadr GUIObject_SetStyle,0x14132B78+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142F0E20+1
        defadr GUIonMessage_SetMenuItemText,0x142F08FC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FEBCC+1
        defadr ListMenu_GetSelectedItem,0x1411BDA8+1
        defadr ListMenu_SetItemStyle,0x140F67C8+1
        defadr CreateOneOfMany,0x140F674C+1
        defadr OneOfMany_SetChecked,0x14111568+1
        defadr OneOfMany_SetTexts,0x141ADC7C+1
        defadr OneOfMany_GetSelected,0x1509AE50+1
        defadr GUIObject_SoftKeys_SetAction,0x1410527C+1
        defadr GUIObject_SoftKeys_SetText,0x14104FB4+1
        defadr GUIObject_SoftKeys_SetVisible,0x14105258+1
        defadr wstrlen,0x144C2DD4+1
        defadr TextID_Create,0x142D8068+1
        defadr TextID_Destroy,0x1416F6B8+1
        defadr GUIObject_GetDispObject,0x1416D928+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14EB16C4+1
        defadr BookObj_Hide,0x14201824+1
        defadr ListMenu_SetOnMessage,0x142DA358+1
        defadr get_envp,0x101EB37C+1
        defadr set_envp,0x101EB390+1
        defadr UI_Event,0x143A0CE8+1
        defadr CreateListMenu,0x14132D74+1
        defadr ListMenu_SetItemCount,0x142DA36C+1
        defadr GUIObject_Destroy,0x1451282C+1
        defadr get_DisplayGC,0x1416C580+1
        defadr GC_GetRect,0x14117A14+1
        defadr GC_GetXX,0x14232F48+1
        defadr GC_SetXX,0x1419CD1C+1
        defadr BookObj_AddGUIObject,0x14132D68+1
        defadr DrawRect,0x14107ADC+1
        defadr DispObject_InvalidateRect,0x1416B5FC+1
        defadr GUIObject_Create,0x144ACEF4+1
        defadr DISP_DESC_SetName,0x14509BC0+1
        defadr DISP_DESC_SetSize,0x14509C0C+1
        defadr DISP_DESC_SetOnCreate,0x14509BB4+1
        defadr DISP_DESC_SetOnClose,0x14509BBC+1
        defadr DISP_DESC_SetOnRedraw,0x14509C10+1
        defadr DISP_DESC_SetOnKey,0x1450A018+1
        defadr DISP_DESC_SetOnRefresh,0x1450A014+1
        defadr GC_GetPenColor,0x14ED4020+1
        defadr GC_SetPenColor,0x14107E50+1
        defadr GC_DrawLine,0x144E1BFC+1
        defadr GUIObject_SetTitleType,0x143A2754+1
        defadr GUIonMessage_SetItemDisabled,0x14258EA8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1515ACBC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1515AD44+1
        defadr GUIObject_SoftKeys_Hide,0x145126E8+1
        defadr ListMenu_SetItemSecondLineText,0x142DA1DC+1
        defadr ImageID_Free,0x1448173C+1
        defadr FILEITEM_GetFname,0x142DBD50+1
        defadr FILEITEM_GetPath,0x142DBD54+1
        defadr DispObject_SetRefreshTimer,0x14234DD8+1
        defadr DispObject_KillRefreshTimer,0x141190EC+1
        defadr ImageID_GetIndirect,0x15159088+1
        defadr DispObject_SetLayerColor,0x144AD5E4+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A160C+1
        defadr GUIonMessage_GetMsg,0x142F0F14+1
        defadr ListMenu_DestroyItems,0x143C3BD8+1
        defadr CoCreateInstance,0x144619AC+1
        defadr DispObject_SetAnimation,0x14EE8080+1
        defadr DisplayGC_AddRef,0x143D0680+1
        defadr TextObject_SetText,0x14170008+1
        defadr TextObject_SetFont,0x14172F04+1
        defadr Timer_ReSet,0x1416A684+1
        defadr Timer_Set,0x1423DCEC+1
        defadr Timer_Kill,0x1416A974+1
        defadr Audio_GetTags,0x14E92E78+1
        defadr CreateYesNoQuestion,0x14235B20+1
        defadr YesNoQuestion_SetDescriptionText,0x14082D08+1
        defadr YesNoQuestion_SetQuestionText,0x14082CF8+1
        defadr YesNoQuestion_SetIcon,0x150C289C+1
        defadr MessageBox_NoIMAGE,0x14EC150C+1
        defadr w_fopen,0x100B2D84+1
        defadr w_lseek,0x10644024+1
        defadr w_fclose,0x1014739C+1
        defadr w_fread,0x100FFB8C+1
        defadr DISP_DESC_SetOnLayout,0x14509FBC+1
        defadr GetIMEI,0x1442E3C4+1
        defadr GUIObject_SoftKeys_Show,0x143A152C+1
        defadr FILEITEM_GetFextension,0x142DB7AC+1
        defadr wstrncmp,0x14121538+1
        defadr Display_GetHeight,0x1411B074+1
        defadr Display_GetWidth,0x141A9ECC+1
		
        EXTERN CreateInfo
        
        RSEG   CODE
        CODE16
create_gui:
        ldr r0, [r6,#4]
        ldr r3, =FILEITEM_GetFextension
        blx r3
        ldr r1, =0x15D03358
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
        ldr r3, =0x1509DEDC+1
        blx r3
        str r0, [r6,#0x14]
        cmp r0, #0
        beq ret
        ldr r3, =0x1509DFD4+1
        bx r3
ret:
        mov r0, #1
        pop {r4-r7,pc}
        
        RSEG   CREATE_GUI
        CODE16
        ldr r3, =create_gui
        bx r3

        END