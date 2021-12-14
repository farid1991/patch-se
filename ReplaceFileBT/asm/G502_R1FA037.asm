//G502_R1FA037

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr memalloc,0x1009ED08
        defadr memfree,0x1009ED30
        defadr memset,0x2A1C07A0
        defadr get_envp,0x100A9A1C+1
        defadr set_envp,0x100A9A30+1
        defadr FileDelete,0x10FDC830+1
        defadr FILEITEM_GetFname,0x1102BF24+1
        defadr FILEITEM_GetPath,0x1102BFB8+1

        defadr BookObj_GotoPage,0x1160376C+1

        defadr GUIObject_Show,0x116A6C4C+1
        defadr GUIObject_Destroy,0x116A6A50+1
        defadr GUIObject_SoftKeys_SetAction,0x116C046C+1

        defadr CreateYesNoQuestion,0x116B5AE4+1
	defadr YesNoQuestion_SetDescriptionText,0x116B5E78+1
	defadr YesNoQuestion_SetQuestionText,0x116B5E68+1

        defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x1100D4A8+1
        defadr FSX_IsFileExists,0x110272DC+1
        defadr DataDownloadBook_onClose,0x1102948C+1

	EXTERN	Question
        EXTERN	File
        EXTERN	Close

        RSEG  	DDB_Question
        CODE16
        ldr	r3, =_DDB_Question
        bx	r3

        RSEG	DDB_File
        CODE16
        ldr	r3, =_File
        bx	r3

        RSEG	DDB_Close
        DATA
        dcd     Close

        RSEG	CODE
        DATA
_DDB_Question:
        ; mov	r1, r4
        ; add	r1, #0x18
        ; ldr	r1, [r1,#4]
        mov	r0, r4
        bl	Question
        ldr	r3, =0x110291DE+1
        bx	r3

_File:
	ldr	r0, [r5,#0]
        bl	File
        ldr	r0, [r5,#0]
        ldr	r3, =FILEITEM_GetPath
        blx	r3
        ldr	r3, =0x11029634+1
        bx	r3

        END
