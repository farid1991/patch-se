//W800_R1BD001

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x44F8145C+1
        defadr memfree,0x44F82578+1
        defadr memset,0x44B42F8C
        defadr snwprintf,0x44B44198+1
        defadr _fopen,0x450E5728+1
        defadr fclose,0x450E6908+1
        defadr fread,0x450E6C24+1
        defadr fwrite,0x450E6EC0+1
        defadr fstat,0x450E5FE8+1
        defadr CreateBook,0x44E82A64+1
        defadr BookObj_GotoPage,0x44E827BC+1
        defadr FreeBook,0x44E83090+1
        defadr GUIObject_SetTitleText,0x44D396C4+1
        defadr GUIObject_Show,0x44D395C8+1
        defadr ListMenu_SetCursorToItem,0x44D642D0+1
        defadr GUIObject_SetStyle,0x44D39618+1
        defadr GUIonMessage_GetCreatedItemIndex,0x44D649A4+1
        defadr GUIonMessage_SetMenuItemText,0x44D649B4+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x44D649E4+1
        defadr ListMenu_GetSelectedItem,0x44D642D0+1
        defadr SetMenuItemStyle,0x44D64330+1
        defadr GUIObject_Softkey_SetAction,0x44D3AD08+1
        defadr GUIObject_Softkey_SetText,0x44D3ADF0+1
        defadr Str2ID,0x44EF41C4+1
        defadr ListMenu_SetOnMessage,0x44D64430+1
        defadr UI_Event,0x4505B5E4+1
        defadr CreateListMenu,0x44D64144+1  
        defadr ListMenu_SetItemCount,0x44D64300+1
        defadr GUIObject_Destroy,0x44EA6538+1
        defadr OneOfMany_SetonMessage,0x44D65A2C+1
        defadr GUIonMessage_GetBook,0x44D64980+1
        defadr MessageBox,0x45067520+1
        defadr FindBook,0x4505B4C8+1
        defadr Find_StandbyBook,0x44EA79F4+1
        defadr CreateOneOfMany,0x44D658B0+1
        defadr OneOfMany_SetChecked,0x44D65A0C+1
        defadr OneOfMany_SetTexts,0x44D65A34+1  
        defadr GUIonMessage_SetMenuItemIcon,0x44D649F4+1
//////////////////

        defadr GUIObject_GetDispObject,0x44EA6780+1
        
        defadr GetOperatorName,0x44F3ECBC+1
        
        defadr DISP_OBJ_StatusIndication_SetItemText,0x44EA18B8+1

        EXTERN  OnSetText
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
        
        END
        