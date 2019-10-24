#ifdef W660_R8BB001_Orange

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
        defadr memalloc,0x44EA0CC8+1
        defadr memfree,0x44EA0CF4+1
        defadr memset,0x20003094
        defadr snwprintf,0x446A3ADC+1
        defadr _fopen,0x44FE64A0+1
        defadr fclose,0x44FE7A6C+1
        defadr fread,0x44FE7CF4+1
        defadr fwrite,0x44FE7EC0+1
        defadr fstat,0x44FE6E34+1
        defadr CreateBook,0x4541189C+1
        defadr BookObj_GotoPage,0x45411618+1
        defadr FreeBook,0x45411EB8+1
        defadr GUIObject_SetTitleText,0x454C77B8+1
        defadr GUIObject_Show,0x454C7288+1
        defadr ListMenu_SetCursorToItem,0x454809A8+1
        defadr GUIObject_SetStyle,0x454C72D8+1
        defadr GUIonMessage_GetCreatedItemIndex,0x454814F8+1
        defadr GUIonMessage_SetMenuItemText,0x45481504+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x45481534+1
        defadr ListMenu_GetSelectedItem,0x454809BC+1
        defadr SetMenuItemStyle,0x45480A0C+1
        defadr CreateStringInput,0x45458A78+1
        defadr GUIObject_Softkey_SetAction,0x454E3BDC+1
        defadr GUIObject_Softkey_SetText,0x454E3C54+1
        defadr GUIObject_SoftKey_SetVisible,0x454E3CA4+1
        defadr _strcmp,0x446A38C0+1
        defadr wstr2strn,0x44FA6934+1
        defadr Str2ID,0x454A9928+1
        defadr StrID2Str,0x454A9DBC+1
        defadr TextFree,0x454A9AF0+1
        defadr List_New,0x45314B90+1
        defadr List_Free,0x45314BCC+1
        defadr ListElement_AddtoTop,0x45314D40+1
        defadr ListMenu_SetOnMessage,0x45480AFC+1
        defadr ListElement_Remove,0x45314CCC+1
        defadr UI_Event,0x45410324+1
        defadr ListElement_GetByIndex,0x45314E64+1
        defadr root_list_get_session_count,0x4541005C+1
        defadr root_list_get_session,0x45410068+1
        defadr CreateListMenu,0x454807A0+1  
        defadr TextCopyId,0x454A9A58+1
        defadr ListMenu_SetItemCount,0x454809D0+1
        defadr isRightNowBook,0x454ED580+1
        defadr isVolumeControllerBook,0x454243AC+1
        defadr GUIObject_Destroy,0x454C7018+1
        defadr InputFeedback_SetIcon,0x454C7394+1
        defadr OneOfMany_SetonMessage,0x45482B6C+1
        defadr strncpy,0x446A398C+1
        defadr ListMenu_SetNoItemText,0x45480BA0+1
        defadr CreateYesNoQuestionVA,0x454D7CBC+1
        defadr CreateTimeInputVA,0x454D78E4+1
        defadr TimeInput_GetTimeInt,0x454D7B2C+1
        defadr unixtime2datetime,0x45164318+1
        defadr DISPLAY_GetTopBook,0x45411108+1
        defadr GUIonMessage_GetBook,0x454814DC+1
        defadr ListMenu_SetItemTextScroll,0x45481124+1        
        defadr Book_GetSession,0x45411F18+1
        defadr strncmp,0x446A3958+1
        defadr JavaSession_GetName,0x441405D8+1
        defadr strstr,0x446A3A24+1
        defadr GUIObject_GetBook,0x454C709C+1
        defadr MessageBox,0x4541CAD8+1
        defadr StatusIndication_SetItemText,0x454D6E64+1
        defadr GUIonMessage_SetMenuItemIcon,0x4548157C+1
        defadr FindBook,0x4540FF5C+1
        defadr Find_StandbyBook,0x45424DD8+1
        defadr CreateOneOfMany,0x4548295C+1
        defadr OneOfMany_SetItemCount,0x45482B24+1
        defadr OneOfMany_SetChecked,0x45482B40+1
        defadr OneOfMany_SetTexts,0x45482B74+1
        defadr OneOfMany_GetSelected,0x45482B50+1
        defadr REQUEST_PROFILE_GETPROFILENAME,0x45448298+1
        defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x4544816C+1
        defadr REQUEST_DATEANDTIME_GET,0x44EA7254+1
        defadr DATE_GetWeekDay,0x45164500+1
        
//////////////////
        defadr DynamicMenu_SetElement_SecondLineText,0x454E7604+1
        defadr DynamicMenu_GetElementMsg,0x454E763C+1
        defadr GUIObject_GetDispObject,0x454C7088+1
        
        defadr GetOperatorName,0x44F306E4+1
        defadr DISP_OBJ_StatusIndication_SetItemText,0x454D3734+1

        EXTERN  OnSetText
        
        RSEG    PATCH_SET_TEXT(2)
        CODE16
        PUSH    {R0-R7, LR}
        LDR     R3,=OnSetText
        BLX     R3
        POP     {R0-R7, PC}
        
#endif
          END
          