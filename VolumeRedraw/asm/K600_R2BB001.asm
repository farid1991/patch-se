//K600_R2BB001

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x20363C0C+1
        defadr memfree,0x20364D24+1
        defadr memset,0x20D66768+1
        defadr debug_printf,0x20D28E84+1
        defadr set_envp,0x2006CF5E+1
        defadr get_envp,0x2006CF4A+1
        defadr current_process,0x200A405C
        defadr get_bid,0x200A4094
        defadr strncmp,0x20D677B0+1
        defadr strcmp,0x20D67710+1
        defadr get_DisplayGC,0x2075B474+1
        defadr BookObj_GetSession,0x2025D594+1
        defadr TextID_GetString,0x202D0C08+1
        defadr _fopen,0x204DBDF4+1
        defadr fstat,0x204DC6B4+1
        defadr fread,0x204DD2F0+1
        defadr fclose,0x204DCFD4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x204D52DC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x204D53F4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x204D5574+1
        defadr DrawRect,0x20267FBC+1
        defadr GC_PutChar,0x2075BF54+1
        defadr GetImageHeight,0x20269678+1
        defadr GetImageWidth,0x20269660+1
        defadr SetFont,0x20268F18+1
        defadr DrawString,0x202683C4+1
        defadr wstrcpy,0x2060F160+1
        defadr TextID_Destroy,0x202D0210+1
        defadr DispObject_GetGUI,0x202642B0+1
        defadr GUIObject_GetBook,0x20280EEC+1
        defadr FindBook,0x20425C9C+1
        defadr TextID_CreateIntegerID,0x202CFB68+1
        defadr TextID_Create,0x202CFF38+1
        defadr TextID_Copy,0x202D00A4+1
        defadr Display_GetWidth,0x2042E154+1
        defadr Display_GetTopBook,0x2025C83C+1
        defadr GUIObject_GetDispObject,0x20280EC4+1
        defadr Display_GetHeight,0x2042E144+1
        defadr DispObject_WindowSetSize,0x202662D8+1
        defadr DispObject_SetLayerColor,0x202678FC+1
        defadr DispObject_SetAnimation,0x20267954+1

        defadr VolumeControl_OnCreate,0x2026B1DC+1
        defadr VolumeControl_OnClose,0x2026B1F4+1
        defadr VolumeControl_OnRedraw,0x2026B1F8+1
        defadr pg_VolumeControl_Active_EnterEvent,0x20548C14+1

//-----------

        EXTERN New_VolumeControl_OnCreate
        EXTERN New_VolumeControl_OnClose
        EXTERN New_VolumeControl_OnRedraw

        EXTERN New_pg_VolumeControl_Active_EnterEvent

        RSEG PATCH_VOLUMEONPAGENTER
        DATA
        DCD New_pg_VolumeControl_Active_EnterEvent

        RSEG PATCH_VOLUMEONCREATE
        DATA
        DCD New_VolumeControl_OnCreate

        RSEG PATCH_VOLUMEONCLOSE
        DATA
        DCD New_VolumeControl_OnClose

        RSEG PATCH_VOLUMEONREDRAW
        DATA
        DCD New_VolumeControl_OnRedraw

        END
