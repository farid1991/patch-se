//W350_R11CA002

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x20DAAE3C+1
        defadr memfree,0x20DABCF0+1
        defadr memset,0x20105B58
        defadr debug_printf,0x2086B1D0+1
        defadr snwprintf,0x20380BC4+1
        defadr _fopen,0x20C86CB4+1
        defadr fread,0x20C88340+1
        defadr fclose,0x20C880EC+1
        defadr fwrite,0x20C8850C+1
        defadr fstat,0x20C875A0+1
        defadr strncmp,0x20380A40+1
        defadr set_envp,0x20144BD4+1
        defadr get_envp,0x20144BC0+1
        defadr BookObj_GetSession,0x210556B4+1
        defadr TextID_GetString,0x210EC274+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x20C424C4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x20C4252C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x20C425DC+1
        defadr FSX_IsFileExists,0x20CC7C34+1
        defadr get_DisplayGC,0x21101BF4+1
        defadr GC_PutChar,0x21102714+1
        defadr DrawRect,0x210FCE28+1
        defadr GetImageHeight,0x210FE238+1
        defadr GetImageWidth,0x210FE224+1
        defadr SetFont,0x210FDBA0+1
        defadr DrawString,0x210FD128+1
        defadr wstrcpy,0x20381198+1
        defadr TextID_Destroy,0x210EBF00+1
        defadr DispObject_GetGUI,0x210F9E84+1
        defadr FindBook,0x21053808+1
        defadr TextID_CreateIntegerID,0x210EBAD0+1
        defadr TextID_Copy,0x210EBE10+1
        defadr Display_GetWidth,0x211170B4+1
        defadr MainDisplay_GetTopBook,0x210548A4+1
        defadr GUIObject_GetDispObject,0x21103F38+1
        defadr Display_GetHeight,0x211170A8+1
        defadr DispObject_WindowSetSize,0x210FB560+1
        defadr DispObject_SetLayerColor,0x210FC31C+1
        defadr DispObject_SetAnimation,0x210FC3D0+1
        defadr TextID_Create,0x210EBC80+1
        defadr CreateMessageBox,0x21060634+1
        defadr GUIObject_SoftKeys_SetVisible,0x211209CC+1
        defadr GUIObject_GetBook,0x21103F4C+1

        defadr VolumeControl_OnCreate,0x21061F00+1
        defadr VolumeControl_OnClose,0x21061F18+1
        defadr VolumeControl_OnRedraw,0x21062054+1
        defadr pg_VolumeControl_Active_EnterEvent,0x21067864+1

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
