//W810_R4EA031

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x45453AA8+1
        defadr memfree,0x454547E0+1
        defadr memset,0x44E24360+1
        defadr debug_printf,0x44C9E13C+1
        defadr set_envp,0x44149D0A+1
        defadr get_envp,0x44149CF6+1
        defadr current_process,0x4418D8F0
        defadr get_bid,0x4418D928
        defadr strncmp,0x44E2538C+1
        defadr strcmp,0x44E252EC+1
        defadr get_DisplayGC,0x45191A98+1
        defadr BookObj_GetSession,0x4529FCB0+1
        defadr TextID_GetString,0x452FF248+1
        defadr _fopen,0x455B4268+1
        defadr fread,0x455B5700+1
        defadr fclose,0x455B54A0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x455ADDD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x455ADE50+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x455ADEE4+1
        defadr FSX_IsFileExists,0x452510D8+1
        defadr DrawRect,0x45306940+1
        defadr GC_PutChar,0x451925BC+1
        defadr GetImageHeight,0x45307FD8+1
        defadr GetImageWidth,0x45307FC0+1
        defadr SetFont,0x45307888+1
        defadr DrawString,0x45306D48+1
        defadr wstrcpy,0x44E25C34+1
        defadr TextID_Destroy,0x452FE86C+1
        defadr DispObject_GetGUI,0x453024AC+1
        defadr GUIObject_GetBook,0x45193C54+1
        defadr FindBook,0x45531160+1
        defadr TextID_CreateIntegerID,0x452FE300+1
        defadr TextID_Create,0x452FE69C+1
        defadr TextID_Copy,0x452FE7D0+1
        defadr Display_GetWidth,0x45547984+1
        defadr Display_GetTopBook,0x4529F01C+1
        defadr GUIObject_GetDispObject,0x45193C40+1
        defadr Display_GetHeight,0x45547974+1
        defadr DispObject_WindowSetSize,0x4530476C+1
        defadr DispObject_SetLayerColor,0x453060C4+1
        defadr DispObject_SetAnimation,0x45306134+1

        defadr VolumeControl_OnCreate,0x452A8FFC+1
        defadr VolumeControl_OnClose,0x452A9014+1
        defadr VolumeControl_OnRedraw,0x452A9158+1
        defadr pg_VolumeControl_Active_EnterEvent,0x4564378C+1

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
