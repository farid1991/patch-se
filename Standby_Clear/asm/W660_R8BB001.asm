#ifdef W660_R8BB001

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM
          
       defadr memalloc,0x44EA0CC8+1
       defadr memfree,0x44EA0CF4+1
       defadr memset,0x441452B8
       defadr snwprintf,0x4467B154+1
       defadr _fopen,0x44FBCAA8+1
       defadr fclose,0x44FBE074+1
       defadr fread,0x44FBE2FC+1
       defadr fwrite,0x44FBE4C8+1
       defadr fstat,0x44FBD43C+1
       defadr CreateBook,0x453E20B0+1
       defadr BookObj_GotoPage,0x453E1E2C+1
       defadr FreeBook,0x453E26CC+1
       defadr GUIObject_SetTitleText,0x4549B8C8+1
       defadr GUIObject_Show,0x4549B398+1
       defadr ListMenu_SetCursorToItem,0x45454A60+1
       defadr GUIObject_SetStyle,0x4549B3E8+1
       defadr GUIonMessage_GetCreatedItemIndex,0x454555B0+1
       defadr GUIonMessage_SetMenuItemText,0x454555BC+1
       defadr GUIonMessage_SetMenuItemSecondLineText,0x45454E7C+1
       defadr ListMenu_GetSelectedItem,0x45454A74+1
       defadr SetMenuItemStyle,0x45454AC4+1
       defadr CreateStringInput,0x4542A724+1
       defadr GUIObject_Softkey_SetAction,0x454B7D28+1
       defadr GUIObject_Softkey_SetText,0x454B7DA0+1
       defadr GUIObject_SoftKey_SetVisible,0x454B7DF0+1
       defadr _strcmp,0x4467AF38+1
       defadr wstr2strn,0x44F7CF3C+1
       defadr Str2ID,0x4547D9E0+1
       defadr StrID2Str,0x4547DE74+1
       defadr TextFree,0x4547DBA8+1
       defadr List_New,0x452EA4AC+1
       defadr List_Free,0x452EA4E8+1
       defadr ListElement_AddtoTop,0x452EA65C+1
       defadr ListMenu_SetOnMessage,0x45454BB4+1
       defadr ListElement_Remove,0x452EA5E8+1
       defadr UI_Event,0x453E0B38+1
       defadr ListElement_GetByIndex,0x452EA780+1
       defadr root_list_get_session_count,0x453E0870+1
       defadr root_list_get_session,0x453E087C+1
       defadr CreateListMenu,0x45454858+1  
       defadr TextCopyId,0x4547DB10+1
       defadr ListMenu_SetItemCount,0x45454A88+1
       defadr isRightNowBook,0x454C16D4+1
       defadr isVolumeControllerBook,0x453F4BC8+1
       defadr GUIObject_Destroy,0x4549B128+1
       defadr InputFeedback_SetIcon,0x4549B4A4+1
       defadr OneOfMany_SetonMessage,0x45456C24+1
       defadr strncpy,0x4467B004+1
       defadr ListMenu_SetNoItemText,0x45454C58+1
       defadr CreateYesNoQuestionVA,0x454ABDCC+1
       defadr CreateTimeInputVA,0x454AB9EC+1
       defadr TimeInput_GetTimeInt,0x454ABC34+1
       defadr unixtime2datetime,0x45139E7C+1
       defadr DISPLAY_GetTopBook,0x453E191C+1
       defadr GUIonMessage_GetBook,0x45455594+1
       defadr ListMenu_SetItemTextScroll,0x454551DC+1        
       defadr Book_GetSession,0x453E272C+1
       defadr strncmp,0x4467AFD0+1
       defadr JavaSession_GetName,0x441405D8+1
       defadr strstr,0x4467B09C+1
       defadr GUIObject_GetBook,0x4549B1AC+1
       defadr MessageBox,0x453ED2F4+1
       defadr StatusIndication_SetItemText,0x454AAF6C+1
       defadr GUIonMessage_SetMenuItemIcon,0x45455634+1
       defadr FindBook,0x453E0770+1
       defadr Find_StandbyBook,0x453F55F4+1
       defadr CreateOneOfMany,0x45456A14+1
       defadr OneOfMany_SetItemCount,0x45456BDC+1
       defadr OneOfMany_SetChecked,0x45456BF8+1
       defadr OneOfMany_SetTexts,0x45456C2C+1
       defadr OneOfMany_GetSelected,0x45456C08+1
       defadr REQUEST_PROFILE_GETPROFILENAME,0x45418CB0+1
       defadr REQUEST_PROFILE_GETACTIVEPROFILE,0x45418B84+1
       defadr REQUEST_DATEANDTIME_GET,0x44E7BDD0+1
       defadr DATE_GetWeekDay,0x4513A064+1
       
//////////////////

        
       defadr GUIObject_GetDispObject,0x4549B198+1
       
       defadr GetOperatorName,0x44F06E80+1
       defadr DISP_OBJ_StatusIndication_SetItemText,0x454A783C+1

       EXTERN  OnSetText
       
       RSEG    PATCH_SET_TEXT(2)
       CODE16
       PUSH    {R0-R7, LR}
       LDR     R3,=OnSetText
       BLX     R3
       POP     {R0-R7, PC}

        
#endif
          END
          