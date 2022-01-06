//W980_R3EG004

defadr  MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr snwprintf,0x106F71E4+1
        defadr _fopen,0x10955B80+1
        defadr fwrite,0x1095763C+1
        defadr fclose,0x1170F520+1
        defadr fread,0x10957474+1
        defadr fstat,0x109564E4+1
        defadr CreateBook,0x10DEF9D4+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr FreeBook,0x10DF0054+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_Show,0x109D0434+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6A088+1
        defadr strcmp,0x106F6FB8+1
        defadr TextID_Create,0x10F685C0+1
        defadr TextID_Destroy,0x10F688FC+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr UI_Event,0x10DEE77C+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr BookObj_GetSession,0x10DF00A0+1
        defadr GUIObject_GetBook,0x109D02E0+1
        defadr CreateMessageBox,0x11A64938+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A8DC60+1
        defadr FindBook,0x10DEDC1C+1
        defadr Find_StandbyBook,0x10D8C5D0+1
        defadr CreateOneOfMany,0x11A8F42C+1
        defadr OneOfMany_SetItemCount,0x11A8F5B8+1
        defadr OneOfMany_SetChecked,0x11A8F5D4+1
        defadr OneOfMany_SetTexts,0x11A8F608+1
        defadr OneOfMany_GetSelected,0x11A8F5E4+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x11AAA5AC+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x11AAA464+1
        defadr REQUEST_DATEANDTIME_GET,0x107AC5D4+1
        defadr DATE_GetWeekDay,0x10BCBAE4+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D510+1
        defadr ListMenu_DestroyItems,0x11A8D4C0+1
        defadr DynamicMenu_GetElementMsg,0x10DD9918+1
        defadr DynamicMenu_SetElement_SecondLineText,0x10DD98D8+1
        
//////////////////

        defadr GUIObject_GetDispObject,0x109D02CC+1
        defadr GetOperatorName,0x10FC8BF0+1
        defadr DispObject_StatusIndication_SetItemText,0x10D89054+1

        EXTERN  OnSetText
        
        RSEG    PATCH_StatusIndication_SetItemText(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
        
        END
