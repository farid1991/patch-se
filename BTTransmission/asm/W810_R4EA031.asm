//W810_R4EA031

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x45453AA8+1
        defadr memfree,0x454547E0+1
        defadr memset,0x44E24360+1
        defadr snwprintf,0x44E25568+1
        defadr strcmp,0x44E252EC+1
        defadr TextID_Create,0x452FE69C+1
        defadr TextID_Destroy,0x452FE86C+1
        defadr get_envp,0x44149CF6+1
        defadr set_envp,0x44149D0A+1
        defadr DrawString,0x45306D48+1
        defadr DispObject_InvalidateRect,0x45302A70+1
        defadr SetFont,0x45307888+1
        defadr FindBookEx,0x455311D8+1
        defadr Display_GetTopBook,0x4529F01C+1
        defadr CreateMessageBox,0x45533CE0+1
        defadr IsObExSendBook,0x44FD364C+1

        defadr StatusRow_OnRedraw,0x45308A08+1

        defadr pg_ObEx_ReceiveFile,0x44FD245C+1
        defadr pg_ObEx_SendFile,0x44FD3E2C+1
        defadr pg_ObEx_SendMultipleFiles,0x44FD4058+1
        defadr pg_ObEx_FileSent,0x44FD45C0+1

        EXTERN  New_StatusRow_OnRedraw
        EXTERN  New_ObEx_ReceiveFile
        EXTERN  New_ObEx_SendFile
        EXTERN  New_ObEx_SendMultipleFiles
        EXTERN  New_ObEx_FileSent

        RSEG    PATCH_StatusRow_OnRedraw
        DATA
        DCD     New_StatusRow_OnRedraw

        RSEG    PATCH_ObEx_ReceiveFile
        DATA
        DCD     New_ObEx_ReceiveFile

        RSEG    PATCH_ObEx_SendFile
        DATA
        DCD     New_ObEx_SendFile

        RSEG    PATCH_ObEx_SendMultipleFiles
        DATA
        DCD     New_ObEx_SendMultipleFiles

        RSEG    PATCH_ObEx_FileSent
        DATA
        DCD     New_ObEx_FileSent

        END
