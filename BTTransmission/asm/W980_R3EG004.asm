//W980_R3EG004

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x4BB010C4
        defadr set_envp,0x10005AEC+1
        defadr get_envp,0x10005AD8+1
        defadr strcmp,0x106F6FB8+1
        defadr get_DisplayGC,0x109CE290+1
        defadr DisplayGC_AddRef,0x109CE6C8+1
        defadr SetFont,0x109CAEC0+1
        defadr DrawString,0x109CA300+1
        defadr TextID_Create,0x10F685C0+1
        defadr TextID_Destroy,0x10F688FC+1
        defadr snwprintf,0x106F71E4+1
        defadr DispObject_InvalidateRect,0x109C6B64+1
        defadr FindBookEx,0x10DEDC7C+1
        defadr Display_GetTopBook,0x10DEF4C0+1

        defadr StatusRow_OnRedraw,0x1177FD3C+1

        defadr pg_ObEx_ReceiveFile,0x108A121C+1
        defadr pg_ObEx_SendFile,0x108A1F04+1
        defadr pg_ObEx_SendMultipleFiles,0x108A1F68+1
        defadr pg_ObEx_FileSent,0x108A2350+1

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
