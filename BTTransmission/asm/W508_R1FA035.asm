//W508_R1FA035

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x4BA30DE8
        defadr memfree,0x4BA30E10
        defadr memset,0x14C23C5C
        defadr debug_printf,0x14C39CD0
        defadr set_envp,0x101F3448+1
        defadr get_envp,0x101F3434+1
        defadr strcmp,0x14D0980C+1
        defadr snwprintf,0x142C75F0+1
        
        defadr TextID_Create,0x14226B70+1
        defadr TextID_Destroy,0x142261D0+1

        defadr DispObject_InvalidateRect,0x1404A6A0+1
        defadr FindBookEx,0x1431E218+1
        defadr Display_GetTopBook,0x14ED9DE0+1

        defadr CoCreateInstance,0x14150FB8+1
        defadr TextObject_SetText,0x14225564+1
        defadr TextObject_SetFont,0x1419C6D0+1
        defadr get_DisplayGC,0x14049D50+1
        defadr DisplayGC_AddRef,0x1419BDB8+1

        defadr StatusRow_OnRedraw,0x1417B194+1

        defadr pg_ObEx_ReceiveFile,0x1441509C+1
        defadr pg_ObEx_SendFile,0x1512AD94+1
        defadr pg_ObEx_SendMultipleFiles,0x1512AD94+1
        defadr pg_ObEx_FileSent,0x1512B1BC+1

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
