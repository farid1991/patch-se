//C510_R1FA035

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x4BA311F4
        defadr memfree,0x4BA3121C
        defadr memset,0x14B259A8
        defadr _fopen,0x141F76F4+1
        defadr fclose,0x144DBBB4+1
        defadr fread,0x14176A94+1
        defadr fwrite,0x1432E3F0+1
        defadr fstat,0x144D28EC+1
        defadr CreateBook,0x14282F00+1
        defadr BookObj_GotoPage,0x1447BFCC+1
        defadr FreeBook,0x14127DD0+1
        defadr FindBook,0x140CAC4C+1
        defadr Find_StandbyBook,0x141AA46C+1
        defadr GUIObject_SetTitleText,0x1443A320+1
        defadr GUIObject_Show,0x144C5870+1        
        defadr ListMenu_SetCursorToItem,0x14412684+1
        defadr GUIObject_SetStyle,0x1412824C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142C20B0+1
        defadr GUIonMessage_SetMenuItemText,0x14385D14+1        
        defadr GUIonMessage_SetMenuItemSecondLineText,0x14130EF4+1
        defadr GUIonMessage_SetMenuItemIcon,0x144C6728+1
        defadr DispObject_SetTitleText,0x1443A5D4+1
        defadr ListMenu_GetSelectedItem,0x1427C728+1
        defadr SetMenuItemStyle,0x140B8930+1
        defadr CreateOneOfMany,0x140B88B4+1
        defadr OneOfMany_SetChecked,0x1422A210+1
        defadr OneOfMany_SetTexts,0x1419CFDC+1
        defadr GUIObject_Softkey_SetAction,0x14179968+1
        defadr GUIObject_Softkey_SetText,0x141C2A04+1
        defadr Str2ID,0x1417F6A0+1
        defadr GUIObject_GetDispObject,0x140C9924+1
        defadr ListMenu_SetOnMessage,0x142FE87C+1
        defadr UI_Event,0x140C45C0+1
        defadr CreateListMenu,0x142822FC+1
        defadr ListMenu_SetItemCount,0x1427CC40+1
        defadr GUIObject_Destroy,0x144C5C2C+1
        defadr MessageBox,0x1583C84C+1 //
        defadr GUIonMessage_GetBook,0x142C2390+1
        defadr GUIObject_GetBook,0x140C9B14+1        
        defadr  REQUEST_PROFILE_GETPROFILENAME,0x1423300C+1
//////////////////

        defadr GetOperatorName,0x143F6788+1
        defadr DISP_OBJ_StatusIndication_SetItemText,0x14305FE8+1

        EXTERN  OnSetText
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
   
        END
          