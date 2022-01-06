//U10_R7AA071

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x4FC00394
		defadr memfree,0x4FC003BC
		defadr memset,0x140E2D1C
        defadr snwprintf,0x1481CAFC+1
        defadr _fopen,0x146EE4EC+1
		defadr fread,0x141B254C+1
		defadr fclose,0x1463D0D0+1
		defadr fwrite,0x146EF4A0+1
		defadr fstat,0x141F09F0+1
        defadr CreateBook,0x1415DBEC+1
        defadr BookObj_GotoPage,0x1459A190+1
        defadr FreeBook,0x141016DC+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr GUIObject_Show,0x146C5748+1
        defadr ListMenu_SetCursorToItem,0x1415C5E0+1
        defadr GUIObject_SetStyle,0x140E20C4+1
        defadr GUIonMessage_GetMsg,0x146C8FE8+1
		defadr GUIonMessage_GetBook,0x146C9190+1
		defadr GUIonMessage_GetCreatedItemIndex,0x146C8C18+1
		defadr GUIonMessage_SetMenuItemText,0x143A2F18+1
		defadr GUIonMessage_SetMenuItemSecondLineText,0x1412D4D4+1
        defadr GUIonMessage_SetMenuItemIcon,0x14533244+1
        defadr ListMenu_GetSelectedItem,0x14623F80+1
        defadr ListMenu_SetItemStyle,0x146765A4+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x156B3298+1
        defadr strcmp,0x1029B60C+1
        defadr TextID_Create,0x14530A4C+1
        defadr TextID_Destroy,0x142B9BF8+1
        defadr ListMenu_SetOnMessage,0x146C7760+1
        defadr UI_Event,0x14274868+1
        defadr CreateListMenu,0x146628FC+1
        defadr ListMenu_SetItemCount,0x1415CAB0+1
        defadr GUIObject_Destroy,0x1459AF78+1
        defadr BookObj_GetSession,0x14599E34+1
        defadr GUIObject_GetBook,0x142B8338+1
        defadr CreateMessageBox,0x147A0C28+1
        defadr FindBook,0x143D2CB0+1
        defadr Find_StandbyBook,0x147CCB84+1
        defadr CreateOneOfMany,0x1480E308+1
        defadr OneOfMany_SetItemCount,0x1480E2D8+1
        defadr OneOfMany_SetChecked,0x1480E1A4+1
        defadr OneOfMany_SetTexts,0x14251630+1
        defadr OneOfMany_GetSelected,0x1475F954+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x14248E0C+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x1415EC78+1
        defadr REQUEST_DATEANDTIME_GET,0x14640198+1
        defadr DATE_GetWeekDay,0x147E7380+1
        defadr GUIObject_SoftKeys_SetVisible,0x143A94C0+1
        defadr ListMenu_DestroyItems,0x145B6598+1
        defadr DynamicMenu_GetElementMsg,0x1458F444+1
        defadr DynamicMenu_SetElement_SecondLineText,0x147DFDB4+1
        defadr GUIObject_GetDispObject,0x145F106C+1
        defadr GetOperatorName,0x147FC0EC+1
        defadr DispObject_StatusIndication_SetItemText,0x141435F0+1

        EXTERN  OnSetText
        
        RSEG    PATCH_StatusIndication_SetItemText(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
        
        END
