//U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr debug_printf,0x4FC00008
        defadr FILEITEM_GetPath,0x146D2464+1
        defadr FILEITEM_GetFname,0x146D27F0+1

        defadr GUIObject_SetTitleText,0x14378258+1
        defadr GUIObject_SetStyle,0x140E4654+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_SoftKeys_SetText,0x14690210+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x143AFC70+1
        defadr GUIObject_Destroy,0x145A2A40+1
        defadr GUIObject_Show,0x146CD3DC+1

        defadr BookObj_CallPage,0x141046E8+1
        defadr SUB_EXECUTE_Get_FILEITEM,0x146D24D0+1
        defadr FSX_MakeFullPath,0x141F4398+1
        defadr FSX_FreeFullPath,0x1415584C+1

        defadr pg_MusicApplication_PreviousAction,0x155AD0EC+1
        defadr pg_MusicApplication_CancelAction,0x152C2890+1
        defadr pg_MusicApplication_ExitAction,0x151D3464+1

        defadr MusicApplication_PrevAction,0x155AD08C+1
        defadr MusicApplication_CancelAction,0x1530F414+1
        defadr MusicApplication_ExecuteSubroutine,0x155AE2A8+1
        
//------------------------------------------------------------------------------

        EXTERN create_new_softkeys

        RSEG    PATCH_ADD_SOFTKEYS
        CODE16
	ldr     R3, =add_softkeys
	bx      R3

        RSEG  CODE
        CODE16
add_softkeys:
        mov     R1, #0xA
        bl      _GUIObject_SoftKeys_SetText
        ldr     R0, [R4,#0x20]
        bl      create_new_softkeys
        ldr     R2, =0x152B06E4+1
        ldr     R3, =0x146587A8+1
        bx      R3

_GUIObject_SoftKeys_SetText:
        bx      pc
        CODE32
        ldr     pc, =GUIObject_SoftKeys_SetText

        END
