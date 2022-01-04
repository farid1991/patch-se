//W980_R3EG004

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr GUIObject_Destroy,0x109D0240+1
        defadr TextFeedbackWindow,0x1178BCC8+1
        defadr Feedback_SetTextExtended,0x1178C138+1
        defadr Feedback_CloseAction,0x1178C098+1
        defadr GUIObject_Show,0x109D0434+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x11AA9C9C+1
        defadr Sound_SetMessageAlert,0x10C4E930+1
        defadr FILEITEM_GetPath,0x11808D90+1
        defadr FILEITEM_GetFname,0x11808CFC+1
        defadr ListMenu_GetSelectedItem,0x11A8D010+1
        defadr Sound_SetAlarmsignal,0x1093366C+1
        defadr wstrlen,0x10D65030+1
        defadr BookObj_GetBookID,0x10DF0140+1
        defadr Media_AddToContact,0x10B51EAC+1
        defadr BookObj_CallPage,0x10DEF818+1
        defadr CreateListMenu,0x11A8CE10+1
        defadr ListMenu_SetItemCount,0x11A8D024+1
        defadr ListMenu_SetCursorToItem,0x11A8CFFC+1
        defadr ListMenu_SetHotkeyMode,0x11A8D1A4+1
        defadr ListMenu_SetTexts,0x11A8D180+1
        defadr GUIObject_SetTitleText,0x109D065C+1
        defadr GUIObject_SetStyle,0x109D048C+1

        defadr MusicApp_PrevAction,0x10C86220+1
        defadr MusicApp_CancelAction,0x10C874B8+1
        defadr pg_MusicApplication_PreviousEvent,0x10C85B14+1
        defadr pg_MusicApplication_CancelEvent,0x10C85B68+1
        defadr pg_MusicApplication_ExitEvent,0x10C85CA4+1

        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1080D5B0+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D414+1
        defadr GUIObject_SoftKeys_SetText,0x1080D48C+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AF236C+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AF2324+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AF23CC+1

//------------------------------------------------------------------------------

        EXTERN create_new_softkeys

        RSEG    PATCH_ADD_SOFTKEYS
        CODE16
        ldr     R3, =add_softkeys
        bx      R3

        RSEG  CODE
        CODE16
add_softkeys:
        bl      create_new_softkeys
        mov     R2, #9
        mov     R1, #8
        ldr     R0, [R4,#0x1C]
        ldr     R3, =GUIObject_SoftKeys_SetItemAsSubItem
        blx     R3
        ldr     R3, =0x10C86C9C+1
        bx      R3
        
        END
