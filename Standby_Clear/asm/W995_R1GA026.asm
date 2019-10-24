#ifdef W995_R1GA026

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x15454548+1
        defadr memfree,0x15454580+1
        defadr memset,0x14C4F00C
        defadr snwprintf,0x144A2B14+1
        defadr _fopen,0x1403EDD8+1
        defadr fclose,0x140FD31C+1
        defadr fread,0x144C2A80+1
        defadr fwrite,0x141C0C0C+1
        defadr fstat,0x142915EC+1
        defadr CreateBook,0x144ABDB0+1
        defadr BookObj_GotoPage,0x1404570C+1
        defadr FreeBook,0x1413366C+1
        defadr GUIObject_SetTitleText,0x141103BC+1
        defadr GUIObject_Show,0x144AC9FC+1
        defadr ListMenu_SetCursorToItem,0x14132758+1
        defadr GUIObject_SetStyle,0x14132B78+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142F0E20+1
        defadr GUIonMessage_SetMenuItemText,0x142F08FC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FEBCC+1
        defadr ListMenu_GetSelectedItem,0x1411BDA8+1
        defadr SetMenuItemStyle,0x140F67C8+1
        defadr GUIObject_Softkey_SetAction,0x1410527C+1
        defadr GUIObject_Softkey_SetText,0x14104FB4+1
        defadr Str2ID,0x142D8068+1
        defadr ListMenu_SetOnMessage,0x142DA358+1
        defadr UI_Event,0x143A0CE8+1
        defadr CreateListMenu,0x14132D74+1  
        defadr ListMenu_SetItemCount,0x142DA36C+1
        defadr GUIObject_Destroy,0x1451282C+1
        defadr OneOfMany_SetonMessage,0x14DB6978+1
        defadr GUIonMessage_GetBook,0x142F0E2C+1
        defadr MessageBox,0x1595E738+1
        defadr StatusIndication_SetItemText,0x1434F28C+1
        defadr GUIonMessage_SetMenuItemIcon,0x14045014+1
        defadr FindBook,0x1416E4E0+1
        defadr Find_StandbyBook,0x143883DC+1
        defadr GUIObject_GetDispObject,0x1416D928+1
        defadr CreateOneOfMany,0x140F674C+1
        defadr OneOfMany_SetChecked,0x14111568+1
        defadr OneOfMany_SetTexts,0x141ADC7C+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x150CAC4C+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x141D42FC+1
        
        defadr ListMenu_DestroyItems,0x143C3BD8+1
        defadr GUIObject_SoftKeys_SetVisible,0x14105258+1
        defadr REQUEST_DATEANDTIME_GET,0x1434FAC4+1
        defadr DATE_GetWeekDay,0x1434FC80+1
        defadr TextFree,0x1416F6B8+1
        
//////////////////
        defadr DynamicMenu_SetElement_SecondLineText,0x1450F840+1
        defadr DynamicMenu_GetElementMsg,0x141DD0B0+1
        
        defadr GetOperatorName,0x1450D218+1
        defadr DISP_OBJ_StatusIndication_SetItemText,0x1434F264+1        

        EXTERN  OnSetText
        EXTERN  OnSetText1
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}   
        
#endif
          END
          