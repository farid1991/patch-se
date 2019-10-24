#ifdef W595_R3FE001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010AC
        defadr snwprintf,0x106F8694+1
        defadr _fopen,0x10957B7C+1
        defadr fclose,0x11700750+1
        defadr fread,0x10959510+1
        defadr fwrite,0x109596DC+1
        defadr fstat,0x109584E0+1
        defadr CreateBook,0x10DF072C+1
        defadr BookObj_GotoPage,0x10DF043C+1
        defadr FreeBook,0x10DF0DAC+1
        defadr GUIObject_SetTitleText,0x109D2398+1
        defadr GUIObject_Show,0x109D2184+1
        defadr ListMenu_SetCursorToItem,0x11A7DE30+1
        defadr GUIObject_SetStyle,0x109D21DC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A7EA1C+1
        defadr GUIonMessage_SetMenuItemText,0x11A7EA28+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A7EA58+1
        defadr ListMenu_GetSelectedItem,0x11A7DE44+1
        defadr SetMenuItemStyle,0x11A7DE94+1
        defadr GUIObject_Softkey_SetAction,0x1080D3A4+1
        defadr GUIObject_Softkey_SetText,0x1080D41C+1
        defadr _strcmp,0x106F8468+1
        defadr Str2ID,0x10F61E3C+1
        defadr TextFree,0x10F62178+1
        defadr ListMenu_SetOnMessage,0x11A7DF68+1
        defadr UI_Event,0x10DEF4CC+1
        defadr CreateListMenu,0x11A7DC44+1  
        defadr ListMenu_SetItemCount,0x11A7DE58+1
        defadr GUIObject_Destroy,0x109D1F90+1
        defadr OneOfMany_SetonMessage,0x11A803F4+1
        defadr DISPLAY_GetTopBook,0x10DF0210+1
        defadr GUIonMessage_GetBook,0x11A7EA00+1      
        defadr Book_GetSession,0x10DF0DF8+1
        defadr GUIObject_GetBook,0x109D2030+1
        defadr MessageBox,0x11A55944+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A7EA68+1
        defadr FindBook,0x10DEE964+1
        defadr Find_StandbyBook,0x10D8D768+1
        defadr CreateOneOfMany,0x11A80220+1
        defadr OneOfMany_SetItemCount,0x11A803AC+1
        defadr OneOfMany_SetChecked,0x11A803C8+1
        defadr OneOfMany_SetTexts,0x11A803FC+1
        defadr OneOfMany_GetSelected,0x11A803D8+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11A9B358+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11A9B210+1
        defadr REQUEST_DATEANDTIME_GET,0x107AC558+1
        defadr DATE_GetWeekDay,0x10BCD4BC+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D4A0+1
        defadr ListMenu_DestroyItems,0x11A7E2B0+1
        
//////////////////

        defadr GUIObject_GetDispObject,0x109D201C+1
        
        defadr GetOperatorName,0x10FC0390+1
        
        defadr DISP_OBJ_StatusIndication_SetItemText,0x10D8A1E8+1

        EXTERN  OnSetText
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
        
#endif
          END
          