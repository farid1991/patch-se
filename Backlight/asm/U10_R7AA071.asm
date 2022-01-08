//U10_R7AA071

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr debug_printf,0x4FC00008
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr memset,0x140E2D1C
        defadr CoCreateInstance,0x146BFD3C+1
        defadr TextObject_SetText,0x141A85A8+1
        defadr TextObject_SetFont,0x143A5054+1
        defadr get_DisplayGC,0x1470812C+1
        defadr DisplayGC_AddRef,0x142C9540+1
        defadr _fopen,0x146EE4EC+1
        defadr fread,0x141B254C+1
        defadr fclose,0x1463D0D0+1
        defadr fwrite,0x146EF4A0+1
        defadr fstat,0x141F09F0+1
        defadr Display_SetBrightness,0x1533B0F0+1
        defadr SaveBrightness,0x1558AA60+1
        defadr Display_GetBrightness,0x151A3C4C+1
        defadr UI_Event,0x14274868+1
        defadr FreeBook,0x141016DC+1
        defadr GUIObject_Create,0x143A3C78+1
        defadr BookObj_AddGUIObject,0x146628F0+1
        defadr GUIObject_SetTitleType,0x140614F0+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1
        defadr GUIObject_Show,0x146C5748+1
        defadr snwprintf,0x1481CAFC+1
        defadr sscanf,0x102ADD04+1
        defadr TextID_Create,0x14530A4C+1
        defadr TextID_Destroy,0x142B9BF8+1
        defadr TextID_CreateIntegerID,0x145308EC+1
        defadr strcmp,0x1029B60C+1
        defadr strcpy,0x1029B664+1
        defadr List_RemoveFirst,0x143D1F94+1
        defadr List_GetCount,0x143D2D10+1
        defadr List_Destroy,0x142754E4+1
        defadr BookObj_GetSession,0x14599E34+1
        defadr TextID_GetString,0x142B98A0+1
        defadr strncmp,0x1481E0DC+1
        defadr JavaSession_GetName,0x1524409A+1
        defadr strstr,0x1481E3AA+1
        defadr TextID_Copy,0x142B9E94+1
        defadr List_Create,0x142751FC+1
        defadr root_list_get_session_count,0x147DCDA8+1
        defadr List_Get,0x143D2790+1
        defadr IsVolumeControllerBook,0x1424D36C+1
        defadr IsRightNowBook,0x14006FF0+1
        defadr List_InsertFirst,0x14272738+1
        defadr root_list_get_session,0x142B909C+1
        defadr GUIonMessage_GetMsg,0x146C8FE8+1
	defadr GUIonMessage_GetBook,0x146C9190+1
	defadr GUIonMessage_GetCreatedItemIndex,0x146C8C18+1
	defadr GUIonMessage_SetMenuItemText,0x143A2F18+1
	defadr GUIonMessage_SetMenuItemSecondLineText,0x1412D4D4+1
        defadr GUIonMessage_SetMenuItemIcon,0x14533244+1
        defadr GUIObject_Destroy,0x1459AF78+1
        defadr ListMenu_GetSelectedItem,0x14623F80+1
        defadr CreateListMenu,0x146628FC+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr ListMenu_SetOnMessage,0x146C7760+1
        defadr ListMenu_SetItemCount,0x1415CAB0+1
        defadr ListMenu_SetCursorToItem,0x1415C5E0+1
        defadr PercentInput_GetPercent,0x150BDFD8+1
        defadr BookObj_GotoPage,0x1459A190+1
        defadr CreatePercentInputVA,0x15414948+1
        defadr Find_StandbyBook,0x147CCB84+1
        defadr unixtime2datetime,0x147E71BC+1
        defadr TextID_CreateCharacterID,0x142BEFE0+1
        defadr strncpy,0x140E03DC
        defadr CreateYesNoQuestion,0x140E2BCC+1
        defadr YesNoQuestion_SetDescriptionText,0x144A23F8+1
	defadr YesNoQuestion_SetQuestionText,0x145ED8A4+1
	defadr YesNoQuestion_SetIcon,0x144A23EC+1
        defadr GUIObject_SetStyle,0x140E20C4+1
        defadr GUIObject_SetSecondRowTitleText,0x14675584+1
        defadr ListMenu_SetItemStyle,0x146765A4+1
        defadr ListMenu_SetItemTextScroll,0x14313144+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x156B3298+1
        defadr GUIObject_SoftKeys_SetVisible,0x143A94C0+1
        defadr GUIObject_SoftKeys_SetIcon,0x146C6D70+1
        defadr ImageID_Copy,0x145332F4+1
        defadr ListMenu_SetNoItemText,0x1535CE50+1
        defadr CreateBook,0x1415DBEC+1
        defadr GUIObject_GetBook,0x142B8338+1
        defadr GUIObject_SetBacklightTimeout,0x14008440+1
        defadr Session_SetFocus,0x146613F0+1
        defadr wstr2strn,0x14253098+1
        defadr CreateStringInputVA,0x156EDF64+1
        defadr TimeInput_GetTimeInt,0x1520F564+1
        defadr CreateTimeInputVA,0x15414620+1
        defadr GUIInput_SetIcon,0x14001B68+1
        defadr DynamicMenu_SetElement_SecondLineText,0x147DFDB4+1
        defadr DynamicMenu_GetElementMsg,0x1458F444+1
        defadr IsBook_onTop,0x1459751C+1
        defadr pg_Screensaver_Sleep,0x143E9B20+1

//Наши функи

	EXTERN  New_GUIObject_SetFocus
        EXTERN  New_pg_Screensaver_Sleep
        EXTERN  New_BookObj_SetFocus
//------

//Устанавливаем время подсветки в буках
        RSEG  CODE
        CODE16
_GUIObject_SetFocus:
	LSL     R5, R1, #0
        CMP     R0, #0
        BEQ     no_gui
        BL      New_GUIObject_SetFocus
        LSL     R1, R5, #0
	LDR     R3, =0x146C56CC+1
	BX      R3
no_gui:
        POP     {R4-R6,PC}

        RSEG    PATCH_GUIObject_SetFocus
        CODE16
        LDR     R3, =_GUIObject_SetFocus
        BX      R3

//Убиваем активацию слипа стандартно

        RSEG    PATCH_SCREENSAVER
        DATA
        DCD     New_pg_Screensaver_Sleep

        RSEG   PATCH_BookObj_SetFocus
        CODE16
        PUSH   {R0-R7,LR}
        LDR    R3, =New_BookObj_SetFocus
        BLX    R3
        POP    {R0-R7,PC}

        END
