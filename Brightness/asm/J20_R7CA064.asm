//J20_R7CA064

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM

        defadr debug_printf,0x4BC00008
        defadr memalloc,0x4BC00394
        defadr memfree,0x4BC003BC
        defadr memset,0x145D9ECC
        defadr CoCreateInstance,0x144FB65C+1
        defadr TextObject_SetText,0x14280D48+1
        defadr TextObject_SetFont,0x144BCE70+1
        defadr get_DisplayGC,0x142D60A8+1
        defadr DisplayGC_AddRef,0x1437CB6C+1
        defadr _fopen,0x1420C904+1
        defadr fread,0x1429733C+1
        defadr fclose,0x1459B9F0+1
        defadr fwrite,0x142978D0+1
        defadr fstat,0x145CEE28+1
        defadr FSX_IsFileExists,0x149CD5A8+1
        defadr ImageID_Free,0x140233F0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14815408+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x14D66FC0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x14CA0FD0+1
        defadr Display_SetBrightness,0x148411CC+1
        defadr SaveBrightness,0x14FE954C+1
        defadr Display_GetBrightness,0x14B10980+1
        defadr DispObject_SetLayerColor,0x1457A1EC+1
        defadr DispObject_InvalidateRect,0x144E7D00+1
        defadr DISP_DESC_SetName,0x1449B4A0+1
        defadr DISP_DESC_SetSize,0x1449B49C+1
        defadr DISP_DESC_SetOnCreate,0x1449B514+1
        defadr DISP_DESC_SetOnClose,0x1449B4A4+1
        defadr DISP_DESC_SetOnRedraw,0x1449B498+1
        defadr DISP_DESC_SetOnLayout,0x1449B5EC+1
        defadr DISP_DESC_SetOnKey,0x1449B024+1
        defadr UI_Event,0x14023B9C+1
        defadr FreeBook,0x141800F0+1
        defadr GUIObject_Create,0x14180798+1
        defadr BookObj_AddGUIObject,0x1418078C+1
        defadr GUIObject_SetTitleType,0x14400FC0+1
        defadr GUIObject_SoftKeys_SetAction,0x1456E1B4+1
        defadr GUIObject_SoftKeys_SetText,0x1456D190+1
        defadr GUIObject_Show,0x14181538+1
        defadr snwprintf,0x145D8E20+1
        defadr sscanf,0x101A4BD0+1
        defadr TextID_Create,0x145CC91C+1
        defadr TextID_Destroy,0x145CBF78+1
        defadr TextID_CreateIntegerID,0x14283F10+1
        defadr DynamicMenu_SetElement_SecondLineText,0x14B10B88+1

        defadr Display_GetWidth,0x144E6CD0+1
        defadr Display_GetHeight,0x144E6CE0+1

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
