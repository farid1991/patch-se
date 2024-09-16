//U10_R7AA071

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM

        defadr debug_printf,0x4FC00008
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr memset,0x140E2D1C
        defadr get_envp,0x1029A4E4+1
        defadr set_envp,0x1029A4F8+1
        defadr FileDelete,0x146566B8+1
        defadr FILEITEM_GetPath,0x146CA88C+1
        defadr FILEITEM_GetFname,0x146CAC1C+1
        defadr BookObj_GotoPage,0x1459A190+1
        defadr BookObj_CallPage,0x14101A24+1
        defadr BookObj_GetBookID,0x143D2C00+1
        defadr GUIObject_Show,0x146C5748+1
        defadr GUIObject_Destroy,0x1459AF78+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr CreateYesNoQuestion,0x140E2BCC+1
        defadr YesNoQuestion_SetDescriptionText,0x144A23F8+1
        defadr YesNoQuestion_SetQuestionText,0x145ED8A4+1

        defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x14729F78+1
        defadr FSX_IsFileExists,0x14729F3C+1
        defadr DataDownloadBook_onClose,0x15952394+1

        EXTERN Patch_ReplaceFile_Page
        EXTERN New_ReplaceFile
        EXTERN Close_DataDownloadBook

        RSEG    DDB_Question
        CODE16
        ldr     r3, =_DDB_Question
        bx      r3

        RSEG    FILE_FIX
        CODE16
        NOP
        NOP

        RSEG    DDB_File
        CODE16
        ldr     r3, =_File
        bx      r3

        RSEG    DDB_Close
        DATA
        DCD     Close_DataDownloadBook

        RSEG   CODE
        CODE16
_DDB_Question:
        ldr     r0, [sp,#0x18]
        bl      Patch_ReplaceFile_Page
        ldr     r3, =0x159526D2+1
        bx      r3

_File:
        ldr     R0, [R4,#0x1C]
        bl      New_ReplaceFile
        ldr     R0, [R4,#0x1C]
        ldr     r3, =0x15952BE4+1
        bx      r3

        END
