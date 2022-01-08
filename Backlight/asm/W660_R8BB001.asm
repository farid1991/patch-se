//W660_R8BB001

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
        defadr CreateStringInputVA,0x45458A78+1
        defadr GUIObject_Softkey_SetAction,0x454E3BDC+1
        defadr GUIObject_Softkey_SetText,0x454E3C54+1
        defadr GUIObject_SoftKey_SetVisible,0x454E3CA4+1
        defadr _strcmp,0x446A38C0+1
        defadr wstr2strn,0x44FA6934+1
        defadr Str2ID,0x454A9928+1
        defadr StrID2Str,0x454A9DBC+1
        defadr TextFree,0x454A9AF0+1
        defadr List_Create,0x45314B90+1
        defadr List_Destroy,0x45314BCC+1
        defadr List_InsertFirst,0x45314D40+1
        defadr ListMenu_SetOnMessage,0x45480AFC+1
        defadr List_RemoveAt,0x45314CCC+1
        defadr UI_Event,0x45410324+1
        defadr List_Get,0x45314E64+1
        defadr root_list_get_session_count,0x4541005C+1
        defadr root_list_get_session,0x45410068+1
        defadr CreateListMenu,0x454807A0+1  
        defadr TextCopyId,0x454A9A58+1
        defadr ListMenu_SetItemCount,0x454809D0+1
        defadr isRightNowBook,0x454ED580+1
        defadr isVolumeControllerBook,0x454243AC+1
        defadr GUIObject_Destroy,0x454C7018+1
        defadr GUIInput_SetIcon,0x454C7394+1
        defadr OneOfMany_SetOnMessage,0x45482B6C+1
        defadr strncpy,0x446A398C+1
        defadr ListMenu_SetNoItemText,0x45480BA0+1
        defadr CreateYesNoQuestionVA,0x454D7CBC+1
        defadr CreateTimeInputVA,0x454D78E4+1
        defadr TimeInput_GetTimeInt,0x454D7B2C+1
        defadr unixtime2datetime,0x45164318+1
        defadr Display_GetTopBook,0x45411108+1
        defadr GUIonMessage_GetBook,0x454814DC+1
        defadr ListMenu_SetItemTextScroll,0x45481124+1        
        defadr BookObj_GetSession,0x45411F18+1
        defadr strncmp,0x446A3958+1
        defadr JavaSession_GetName,0x441405D8+1
        defadr strstr,0x446A3A24+1
        defadr GUIObject_GetBook,0x454C709C+1
        defadr int2strID,0x454A9674+1
        defadr CreatePercentInputVA,0x454D641C+1
        defadr Display_GetBrightness,0x454C8628+1
//Нет в либе        
        defadr GUI_SetBacklight,0x454C73FC+1
        defadr StinpSetIcon,0x454D7F74+1
//------
        defadr PATCH_GUI_RET1,0x454C7240+1
        defadr func1,0x454C70EC+1

        defadr DefaultSleep,0x454F6ADC+1
        
        defadr DynamicMenu_SetElement_SecondLineText,0x454E7604+1
        defadr DynamicMenu_GetElementMsg,0x454E763C+1
//Наши функи

	EXTERN  OnShowNewWindow
        EXTERN  OnCreateSleepMode
//------

//Устанавливаем время подсветки в буках

        RSEG  CODE
        CODE16
        
_PATCH_GUI:
	ADD     R5, R1, #0
        BL      OnShowNewWindow
        ADD     R1, R5, #0
        ADD     R0, R4, #0
//------        

//Восстанавливаем затертые данные в SetFocus

	LDR	R3, =func1
	BLX	R3
	CMP     R5, #0
//------

//Возвращаемся после врезки

	LDR	R3, =PATCH_GUI_RET1
	BX	R3
//------

//Врезаемся в SetFocus

        RSEG    PATCH_GUI(2)
        CODE16
	LDR	R3, =_PATCH_GUI
	BX	R3

//Убиваем активацию слипа стандартно

        RSEG    PATCH_SCREENSAVER(2)
        DATA
        DCD     OnCreateSleepMode
        
        END
