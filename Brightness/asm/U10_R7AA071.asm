//U10_R7AA071

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM

        defadr debug_printf,0x4FC00008
        defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
        defadr memset,0x140E2D1C
        defadr CoCreateInstance,0x146BFD3C+1
        defadr TextObject_SetText,0x141A85A8+1
        defadr TextObject_SetFont,0x143A5054+1
        defadr get_DisplayGC,0x1470812C+1
        defadr DisplayGC_AddRef,0x142C9540+1
        defadr _fopen,0x146EE4EC+1
        defadr fread,0x141B254C+1
        defadr fclose,0x1463D0D0+1
        defadr fwrite,0x146EF4A0+1
        defadr fstat,0x141F09F0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x140CAB00+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15459704+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x153F1088+1
        defadr Display_SetBrightness,0x1533B0F0+1
        defadr SaveBrightness,0x1558AA60+1
        defadr Display_GetBrightness,0x151A3C4C+1
        defadr DispObject_SetLayerColor,0x140D8ED0+1
        defadr DispObject_InvalidateRect,0x142B7978+1
        defadr DISP_DESC_SetName,0x142987BC+1
        defadr DISP_DESC_SetSize,0x142987B0+1
        defadr DISP_DESC_SetOnCreate,0x142987B8+1
        defadr DISP_DESC_SetOnClose,0x142987C0+1
        defadr DISP_DESC_SetOnRedraw,0x1429872C+1
        defadr DISP_DESC_SetOnLayout,0x1429839C+1
        defadr DISP_DESC_SetOnKey,0x142982E0+1
        defadr UI_Event,0x14274868+1
        defadr FreeBook,0x141016DC+1
        defadr GUIObject_Create,0x143A3C78+1
        defadr BookObj_AddGUIObject,0x146628F0+1
        defadr GUIObject_SetTitleType,0x140614F0+1
        defadr GUIObject_SoftKeys_SetAction,0x143A8288+1
        defadr GUIObject_SoftKeys_SetText,0x14688408+1
        defadr GUIObject_Show,0x146C5748+1
        defadr snwprintf,0x1481CAFC+1
        defadr sscanf,0x102ADD04+1
        defadr TextID_Create,0x14530A4C+1
        defadr TextID_Destroy,0x142B9BF8+1
        defadr TextID_CreateIntegerID,0x145308EC+1
        defadr DynamicMenu_SetElement_SecondLineText,0x147DFDB4+1

        defadr Display_GetWidth,0x140F2FDC+1
        defadr Display_GetHeight,0x140F2FEC+1

        EXTERN  VisualBrightness
        EXTERN  SecondLineText

        RSEG    ITEM_TEXT
        CODE16
        ldr     r3, =SecondLineText
        bx      r3

        RSEG    BR_1(1)
        CODE16
        cmp     r2, #1

        RSEG    BR_2(1)
        CODE16
        mov     r2, #1

        RSEG    DS_CREATE
        DATA
        DCD     VisualBrightness

        RSEG    DS_CLOSE
        DATA
        DCD     0

        END
