//U10_R7AA071

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr GUIObject_Destroy,0x1459AF78+1
        defadr TextFeedbackWindow,0x140E298C+1
        defadr Feedback_SetTextExtended,0x140D91B0+1
        defadr Feedback_CloseAction,0x140E2494+1
        defadr GUIObject_Show,0x146C5748+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x1599F25C+1
        defadr Sound_SetMessageAlert,0x1517EB24+1
        defadr FILEITEM_GetPath,0x146CA88C+1
	defadr FILEITEM_GetFname,0x146CAC1C+1
        defadr ListMenu_GetSelectedItem,0x14623F80+1
        defadr Sound_SetAlarmsignal,0x154B498C+1
        defadr wstrlen,0x141B2BB4+1
        defadr BookObj_GetBookID,0x143D2C00+1
        defadr Media_AddToContact,0x152EF98C+1
        defadr BookObj_CallPage,0x14101A24+1
        defadr CreateListMenu,0x146628FC+1
        defadr ListMenu_SetItemCount,0x1415CAB0+1
        defadr ListMenu_SetCursorToItem,0x1415C5E0+1
        defadr ListMenu_SetHotkeyMode,0x14676678+1
        defadr ListMenu_SetTexts,0x148112C4+1
        defadr GUIObject_SetTitleText,0x1437103C+1
        defadr GUIObject_SetStyle,0x140E20C4+1
        defadr MusicApp_PrevAction,0x155CA5F4+1
        defadr MusicApp_CancelAction,0x1532FAD8+1
        defadr pg_MusicApplication_PreviousEvent,0x155CA978+1
        defadr pg_MusicApplication_CancelEvent,0x152E2C20+1
        defadr pg_MusicApplication_ExitEvent,0x151F38E4+1

        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143A8AB4+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1

//------------------------------------------------------------------------------

        EXTERN create_new_softkeys

        RSEG  CODE
        CODE16
add_softkeys:
        bl      create_new_softkeys
        mov     R2, #0xA
        mov     R1, #8
        ldr     R0, [R4,#0x20]
        bl      _GUIObject_SoftKeys_SetItemAsSubItem
        ldr     R3, =0x14651090+1
        bx      R3

_GUIObject_SoftKeys_SetItemAsSubItem:
        ldr     R3, =GUIObject_SoftKeys_SetItemAsSubItem
	bx      R3

        RSEG    PATCH_ADD_SOFTKEYS
        CODE16
	ldr     R3, =add_softkeys
	bx      R3

        END
