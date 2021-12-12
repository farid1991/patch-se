//#ifdef U10_R1BA049
#include "target.h"

defadr  MACRO   a,b
		PUBLIC  a
a       equ     b
		ENDM
		
		defadr debug_printf,0x4FC00008
		defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
		defadr memset,0x140EA530 //0x1482A884 //0x10293790 //
		defadr get_envp,0x102932CC+1
		defadr set_envp,0x102932E0+1
		defadr FileDelete,0x1465DD28+1
		defadr FILEITEM_GetPath,0x146D2464+1
        defadr FILEITEM_GetFname,0x146D27F0+1

		defadr BookObj_GotoPage,0x145A1C58+1
		defadr BookObj_CallPage,0x141046E8+1
        defadr BookObj_GetBookID,0x143D9B54+1

		defadr GUIObject_Show,0x146CD3DC+1
		defadr GUIObject_Destroy,0x145A2A40+1
		defadr GUIObject_SoftKeys_SetAction,0x143AF444+1

		defadr CreateYesNoQuestion,0x140E5184+1
		defadr YesNoQuestion_SetDescriptionText,0x144A9E18+1
		defadr YesNoQuestion_SetQuestionText,0x145F5040+1

		defadr DataBrowser_ItemDesc_CheckFileToCopyMove,0x14735BD4+1
		defadr FSX_IsFileExists,0x14735B98+1
		defadr DataDownloadBook_onClose,0x15933848+1

		EXTERN Question
		EXTERN File
		EXTERN Close

		RSEG   DDB_Question
        CODE16
        ldr     r3, =_DDB_Question+1
        bx      r3
        
        RSEG   DDB_File
        CODE16
        ldr     r3, =_File+1
        bx      r3
        
        RSEG   DDB_Close
        DATA
        dcd Close
        
        RSEG   CODE
        DATA
_DDB_Question:
        ldr     r0, [sp,#0x18]
        bl      Question
        ldr     r3, =0x15933B86+1
        bx      r3
        
_File:
        ldr     R0, [R4,#0x1C]
		bl      File
        ldr     R0, [R4,#0x1C]
        ldr     r3, =0x15934094+1
        bx      r3
        
        END
