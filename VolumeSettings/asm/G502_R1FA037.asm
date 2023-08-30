//G502_R1FA037

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr memalloc,0x1009ED08
        defadr memfree,0x1009ED30
        defadr memset,0x10001630
        defadr memcpy,0x100BEDA4
        defadr snwprintf,0x105544CC+1
        defadr _fopen,0x10FDBE10+1
        defadr fclose,0x115AE044+1
        defadr fread,0x10FDD554+1
        defadr fwrite,0x10FDD720+1
        defadr fstat,0x10FDC708+1
        defadr FSX_IsFileExists,0
        defadr CreateBook,0x116039F4+1
        defadr FindBookEx,0x11601B24+1
        defadr FreeBook,0x11604000+1
        defadr FindBook,0x1160354C+1
        defadr BookObj_SetFocus,0x11603C94+1
        defadr TextID_Create,0x1168442C+1
        defadr TextID_CreateIntegerID,0x1168426C+1
        defadr TextID_Destroy,0x116846C4+1
        defadr get_DisplayGC,0x116A418C+1
        defadr DisplayGC_AddRef,0x116A45C8+1
        defadr GC_PutChar,0x116A4BD4+1
        defadr GC_GetPenColor,0x116A49E0+1
        defadr GC_SetPenColor,0x116A49A4+1
        defadr GC_SetPixel,0x116A4624+1
        defadr GC_DrawLine,0x116A5464+1
        defadr GC_DrawFRect,0x116A55EC+1
        defadr GC_DrawBitmap,0x116A46B0+1
        defadr GC_DrawRoundRect,0x116A5634+1
        defadr GC_DrawIcon,0x1169F3E4+1
        defadr SetFont,0x116A00A8+1
        defadr DrawString,0x1169F530+1
        defadr DISP_DESC_SetName,0x116971FC+1
        defadr DISP_DESC_SetSize,0x11697200+1
        defadr DISP_DESC_SetOnCreate,0x11697204+1
        defadr DISP_DESC_SetOnClose,0x11697208+1
        defadr DISP_DESC_SetOnRedraw,0x1169720C+1
        defadr DISP_DESC_SetOnKey,0x11697214+1
        defadr DISP_DESC_SetonRefresh,0x11697210+1
        defadr DISP_DESC_SetMethod06,0x11697218+1
        defadr DISP_DESC_SetMethod08,0x11697220+1
        defadr DISP_DESC_SetMethod09,0x11697224+1
        defadr DISP_DESC_SetMethod0A,0x11697228+1
        defadr DISP_DESC_SetMethod0B,0x1169722C+1
        defadr DISP_DESC_SetMethod0C,0x11697230+1
        defadr DispObject_SetLayerColor,0x1169E1C8+1
        defadr DispObject_InvalidateRect,0x1169C320+1
        defadr BookObj_AddGUIObject,0x11603D48+1
        defadr GUIObject_Create,0x116A6960+1
        defadr GUIObject_SetTitleText,0x116A7178+1
        defadr GUIObject_SetStyle,0x116A6CA4+1
        defadr GUIObject_Show,0x116A6C4C+1
        defadr GUIObject_SoftKeys_SetAction,0x116C046C+1
        defadr GUIObject_SoftKeys_SetText,0x116C04E4+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x116C0850+1
        defadr strcmp,0x105542A0+1
        defadr sscanf,0x100A7A60+1
        defadr GetImageWidth,0x116A0674+1
        defadr GetImageHeight,0x116A0688+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x10FC2844+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x10FC28CC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x10FC27CC+1
        defadr Volume_Get,0x111B93F8+1
        defadr Volume_Set,0x111B932C+1
        defadr REQUEST_SETTING_RINGVOLUME_SET,0x1179EB9C+1
        defadr OSE_GetShell,0x111DFEE0+1
        defadr CoCreateInstance,0x117065BC+1
        defadr onBackPressed,0x10EF1694+1
        defadr onLongBackPressed,0x1149362C+1
        defadr onCloseBook,0x117A1574+1
        defadr onStandyEvent,0x116259D8+1
        defadr StandartRingMenu,0x11624F90+1
        defadr DynamicMenu_GetElementMsg,0x116C4FCC+1
        defadr DynamicMenu_SetElement_FirstLineText, 0x116C4EBC+1
        defadr DynamicMenu_SetElement_SecondLineText,0x116C4F90+1

        END
