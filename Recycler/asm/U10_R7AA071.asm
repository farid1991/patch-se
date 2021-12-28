//U10_R7AA071

defadr  MACRO   a,b
    	PUBLIC  a
a       EQU     b
    	ENDM

		defadr memalloc,0x4FC00394
		defadr memfree,0x4FC003BC
		defadr memset,0x140E2D1C
		defadr debug_printf,0x4FC00008
		defadr get_envp,0x1029A4E4+1
		defadr set_envp,0x1029A4F8+1
		defadr current_process,0x10299D94
		defadr get_bid,0x10299DCC
		defadr List_GetCount,0x143D2D10+1

		defadr MainDisplay_GetTopBook,0x143A185C+1
		defadr BookObj_GotoPage,0x1459A190+1
		defadr BookObj_ReturnPage,0x14101C54+1
		defadr BookObj_GetBookID,0x143D2C00+1
		defadr UI_Event_toBookID,0x1463FD98+1
		defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
		defadr GUIObject_SoftKeys_SetItemOnKey,0x14660B44+1

		defadr TextID_Create,0x14530A4C+1

		defadr FILEITEM_GetPath,0x146CA88C+1
		defadr FILEITEM_GetFname,0x146CAC1C+1
		defadr FILEITEM_SetPath,0x146CA7A8+1
		defadr FILEITEM_SetFnameAndContentType,0x146CA254+1
		defadr FileMove,0x14656314+1
		defadr FileDelete,0x146566B8+1

		defadr GetMemoryStickStatus,0x1475964C+1
		defadr CreatePasswordInputWindow,0x1415E434+1
		defadr CreateMessageBox,0x147A0C28+1

		defadr CreateYesNoQuestion,0x140E2BCC+1
		defadr YesNoQuestion_SetDescriptionText,0x144A23F8+1
		defadr YesNoQuestion_SetQuestionText,0x145ED8A4+1
		defadr GUIObject_Show,0x146C5748+1
		defadr GUIObject_Destroy,0x1459AF78+1

		defadr DataBrowserDesc_Create,0x145B2E18+1
		defadr DataBrowserDesc_SetHeaderText,0x145B2EBC+1
		defadr DataBrowserDesc_SetBookID,0x145B2D58+1
		defadr DataBrowserDesc_SetFolders,0x145B2EB4+1
		defadr DataBrowserDesc_SetFoldersNumber,0x145B2D68+1
		defadr DataBrowserDesc_Menu_AddFSFunctions,0x151B81E8+1
		defadr DataBrowserDesc_Menu_AddNewFolder, 0x145B2E10+1
		defadr DataBrowserDesc_Menu_AddMarkFiles,0x145B2D60+1
		defadr DataBrowser_Create,0x1416C6CC+1
		defadr DataBrowserDesc_Destroy,0x145B2EC4+1
		defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x14729F78+1

		EXTERN SetFileDelete
		EXTERN SetKey

		RSEG   SET_KEY_FILE_1
		CODE16
		LDR    R3, =set_key_file_1
		BX     R3

		RSEG   SET_KEY_FILE_2
		CODE16
		LDR    R3, =set_key_file_2
		BX     R3

		RSEG   SET_KEY_PATH
		CODE16
		LDR    R3, =set_key_path
		BX     R3

		RSEG   FILE_DELETE
		CODE16
		LDR    R3, =file_delete
		BX     R3

		RSEG   CODE
		CODE16
set_key_file_1:
		lsl     r1, r5, #0
		ldr 	r3, =GUIObject_SoftKeys_SetAction
		blx 	r3
		mov		r2, #0		; is_marked
		mov 	r1, #0		; mode
		ldr 	r0, [r4,#0x14]
		bl		SetKey
		ldr 	r0, [r4,#0x14]
		ldr		r3, =0x151996C4+1
		bx		r3

set_key_file_2:
		lsl     r1, r7, #0
		ldr 	r3, =GUIObject_SoftKeys_SetAction
		blx 	r3
		ldr 	r0, [r5,#0x10]
		mov		r2, #1		; is_marked
		mov 	r1, #0		; mode
		ldr 	r0, [r0,#0x10]
		bl		SetKey
		ldr 	r3, =0x1513A79A+1
		bx		r3

set_key_path:
		ldr 	r1, =0xFC5
		ldr 	r0, [r4,#0x14]
		ldr 	r3, =GUIObject_SoftKeys_SetAction
		blx 	r3
		mov 	r1, #1
		ldr 	r0, [r4,#0x14]
		bl		SetKey
		ldr 	r3, =0x15375FF0+1
		bx		r3

file_delete:
		lsl     r0, r4, #0
		mov		r2, #0
		add		r0, #0xA
		bl		SetFileDelete
		ldr		r3, =0x145A580E+1
		bx		r3

		END
