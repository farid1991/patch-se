#ifdef C905_R1FA035

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x1542B884+1
        defadr memfree,0x1542B8B4+1
        defadr memset,0x14B7F1AC
        defadr snwprintf,0x14B77F24+1
        defadr _fopen,0x14117C0C+1
        defadr fclose,0x1438BB38+1
        defadr fread,0x141B9F14+1
        defadr fwrite,0x141B9AC8+1
        defadr fstat,0x14260F0C+1
        defadr CreateBook,0x1410E350+1
        defadr BookObj_GotoPage,0x142BB8A0+1
        defadr FreeBook,0x143DCA48+1
        defadr GUIObject_SetTitleText,0x1441DDB8+1
        defadr GUIObject_Show,0x144607E8+1
        defadr ListMenu_SetCursorToItem,0x14176DD4+1
        defadr GUIObject_SetStyle,0x1445E0A0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x14396384+1
        defadr GUIonMessage_SetMenuItemText,0x14482F64+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1411BABC+1
        defadr ListMenu_GetSelectedItem,0x14177470+1
        defadr SetMenuItemStyle,0x14127A54+1
        defadr GUIObject_Softkey_SetAction,0x140FF438+1
        defadr GUIObject_Softkey_SetText,0x14397D0C+1
        defadr Str2ID,0x14100290+1
        defadr ListMenu_SetOnMessage,0x141DEA40+1        
        defadr UI_Event,0x142BB514+1
        defadr CreateListMenu,0x14460344+1
        defadr ListMenu_SetItemCount,0x14176C00+1
        defadr GUIObject_Destroy,0x144606B8+1
        defadr OneOfMany_SetonMessage,0x1408BE10+1
        defadr GUIonMessage_GetBook,0x14396910+1
        defadr MessageBox,0x1591724C+1
        defadr GUIonMessage_SetMenuItemIcon,0x14482584+1
        defadr FindBook,0x143ACB90+1
        defadr Find_StandbyBook,0x140C8390+1
        defadr GUIObject_GetDispObject,0x143ABFC8+1
        defadr CreateOneOfMany,0x141952D0+1
        defadr OneOfMany_SetChecked,0x14211154+1 //+
        defadr OneOfMany_SetTexts,0x1413A9A8+1   //+
        defadr REQUEST_PROFILE_GETPROFILENAME,0x141863A0+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x14185E00+1
        
        defadr ListMenu_DestroyItems,0x14176BB8+1
        defadr GUIObject_SoftKeys_SetVisible,0x140FF408+1
        defadr REQUEST_DATEANDTIME_GET,0x1410BCC8+1
        defadr DATE_GetWeekDay,0x1409A818+1
        defadr TextFree,0x142BD18C+1
        
//////////////////
        defadr DynamicMenu_SetElement_SecondLineText,0x14400F40+1
        defadr DynamicMenu_GetElementMsg,0x141D2B44+1
        
        defadr GetOperatorName,0x141C4A20+1
        defadr DISP_OBJ_StatusIndication_SetItemText,0x140E22DC+1

        EXTERN  OnSetText
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}   
        
#endif
          END
          