//W980_R3EG004

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr debug_printf,0x4BB37FED
        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr snwprintf,0x106F71E4+1
        defadr _fopen,0x10955B80+1
        defadr fwrite,0x1095763C+1
        defadr fclose,0x1170F520+1
        defadr fread,0x10957474+1
        defadr fstat,0x109564E4+1
        defadr List_RemoveAt,0x11AD3808+1
        defadr List_RemoveFirst,0x11AD38D4+1
        defadr TextID_Destroy,0x10F688FC+1
        defadr List_GetCount,0x11AD38FC+1
        defadr List_Destroy,0x11AD3730+1
        defadr BookObj_GetSession,0x10DF00A0+1
        defadr TextID_GetString,0x10F68CCC+1
        defadr strncmp,0x106F7050+1
        defadr JavaSession_GetName,0x108DCEAC+1
        defadr strcmp,0x106F6FB8+1
        defadr strstr,0x106F7120+1
        defadr TextID_Copy,0x10F687A0+1
        defadr TextID_Create,0x10F685C0+1
        defadr TextID_CreateCharacterID,0x10F683E4+1
        defadr List_Create,0x11AD3708+1
        defadr root_list_get_session_count,0x10DEDD1C+1
        defadr List_Get,0x11AD3928+1
        defadr IsVolumeControllerBook,0x11AC6BFC+1
        defadr IsRightNowBook,0x10B309FC+1
        defadr List_InsertFirst,0x11AD387C+1
        defadr root_list_get_session,0x10DEDD2C+1
        defadr GUIonMessage_GetBook,0x11A8DBF8+1
        defadr GUIonMessage_GetMsg,0x11A8DBF0+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A8DC14+1
        defadr GUIonMessage_SetMenuItemText,0x11A8DC20+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A8DC50+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A8DC60+1
        defadr BookObj_ReturnPage,0x10DEF89C+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr BookObj_CallPage,0x10DEF818+1
        defadr GUIObject_Destroy,0x109D0240+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr GUIObject_SetTitleType,0x109D0640+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_SetSecondRowTitleText,0x109D0678+1
        defadr ListMenu_SetOnMessage,0x11A8D178+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_Show,0x109D0434+1
        defadr Find_StandbyBook,0x10D8C5D0+1
        defadr FreeBook,0x10DF0054+1
        defadr TextID_CreateIntegerID,0x10F683EC+1
        defadr unixtime2datetime,0x10BCB8FC+1
        defadr UI_Event,0x10DEE77C+1
        defadr GUIObject_SetStyle,0x109D048C+1
        defadr ListMenu_SetItemStyle,0x11A8D060+1
        defadr ListMenu_SetItemTextScroll,0x11A8D748+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6A088+1
        defadr ListMenu_SetNoItemText,0x11A8D1F8+1
        defadr CreateBook,0x10DEF9D4+1
        defadr BookObj_GotoPage,0x10DEF6E4+1
        defadr GUIObject_GetBook,0x109D02E0+1
        defadr GUIObject_SetBacklightTimeout,0x109D059C+1
        defadr Display_SetBrightness,0x10DC06F8+1
        defadr Session_SetFocus,0x10DED6C0+1
        defadr TimeInput_GetTimeInt,0x1178C72C+1
        defadr CreateTimeInputVA,0x1178C464+1
        defadr PercentInput_GetPercent,0x1178B234+1
        defadr CreatePercentInputVA,0x1178B0A8+1
        defadr CreateStringInputVA,0x10894B50+1
        defadr CreateYesNoQuestion,0x1178C788+1
        defadr YesNoQuestion_SetDescriptionText,0x1178CAF0+1
        defadr YesNoQuestion_SetQuestionText,0x1178CAE0+1
        defadr YesNoQuestion_SetIcon,0x1178CB10+1
        defadr wstr2strn,0x10D65150+1
        defadr strncpy,0x106F7084+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D510+1
        defadr GUIInput_SetIcon,0x109D0508+1

        defadr DynamicMenu_GetElementMsg,0x10DD9918+1
        defadr DynamicMenu_SetElement_SecondLineText,0x10DD98D8+1

        defadr IsBook_onTop,0x10DEFD50+1
        defadr pg_Screensaver_Sleep,0x108E6B08+1

//Наши функи

	EXTERN  New_GUIObject_SetFocus
        EXTERN  New_pg_Screensaver_Sleep
        EXTERN  New_BookObj_SetFocus
//------

//Устанавливаем время подсветки в буках
        RSEG  CODE
        CODE16
_GUIObject_SetFocus:
	ADD     R5, R1, #0
        BL      New_GUIObject_SetFocus
        ADD     R1, R5, #0
        ADD     R0, R4, #0
	BL      GUI_Func
        ADD     R0, R4, #0
	LDR     R3, =0x109D0404+1
	BX      R3
GUI_Func:
        LDR     R3, =0x109D0338+1
	BX      R3

        RSEG    PATCH_GUIObject_SetFocus(2)
        CODE16
        LDR     R3, =_GUIObject_SetFocus
        BX      R3

//Убиваем активацию слипа стандартно

        RSEG    PATCH_SCREENSAVER(2)
        DATA
        DCD     New_pg_Screensaver_Sleep

        RSEG   PATCH_BookObj_SetFocus(2)
        CODE16
        PUSH   {R0-R7,LR}
        LDR    R3, =New_BookObj_SetFocus
        BLX    R3
        POP    {R0-R7,PC}

        END
