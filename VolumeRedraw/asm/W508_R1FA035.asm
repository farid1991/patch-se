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
        defadr current_process,0x101EC87C
        defadr get_bid,0x101EC8B4
        defadr strncmp,0x1433778C+1
        defadr strcmp,0x14D0980C+1
        defadr CoCreateInstance,0x14150FB8+1
        defadr TextObject_SetText,0x14225564+1
        defadr TextObject_SetFont,0x1419C6D0+1
        defadr get_DisplayGC,0x14049D50+1
        defadr DisplayGC_AddRef,0x1419BDB8+1
        defadr BookObj_GetSession,0x140278A4+1
        defadr TextID_GetString,0x142262BC+1
        defadr _fopen,0x1421A92C+1
        defadr fread,0x14310608+1
        defadr fclose,0x1410E040+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14E40DE0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15092030+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14ED5D30+1
        defadr FSX_IsFileExists,0x144BFCC0+1
        defadr DrawRect,0x141158F4+1
        defadr wstrcpy,0x14310568+1
        defadr TextID_Destroy,0x142261D0+1
        defadr IsMainDisplayActive,0x1419E758+1
        defadr DispObject_GetGUI,0x140B8700+1
        defadr GUIObject_GetBook,0x1419E1BC+1
        defadr FindBook,0x143111F8+1
        defadr TextID_CreateIntegerID,0x1452561C+1
        defadr TextID_Create,0x14226B70+1
        defadr TextID_Copy,0x142264CC+1
        defadr Display_GetWidth,0x142E9D78+1
        defadr MainDisplay_GetTopBook,0x140274B8+1
        defadr GUIObject_GetDispObject,0x14048B1C+1
        defadr Display_GetHeight,0x142E9D88+1
        defadr DispObject_WindowSetSize,0x142E8DC4+1
        defadr DispObject_SetLayerColor,0x142E8110+1
        defadr DispObject_SetAnimation,0x14E7EC30+1

        defadr VolumeControl_OnCreate,0x14EFDE1C+1
        defadr VolumeControl_OnClose,0x14D76794+1
        defadr VolumeControl_OnRedraw,0x14ECC3C4+1
        defadr pg_VolumeControl_Active_EnterEvent,0x15039CD0+1

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
