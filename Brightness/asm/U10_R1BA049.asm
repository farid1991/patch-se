//U10_R1BA049

defadr  MACRO   a,b
        PUBLIC  a
a       equ     b
        ENDM
        
        defadr debug_printf,0x4FC00008
	defadr memalloc,0x4FC00394
        defadr memfree,0x4FC003BC
	defadr memset,0x140EA530
        defadr memcpy,0x1482A864
        defadr CoCreateInstance,0x146C79D0+1
        defadr TextObject_SetText,0x141AADE4+1
        defadr TextObject_SetFont,0x143AC220+1
        defadr get_DisplayGC,0x1470FE3C+1
        defadr DisplayGC_AddRef,0x142CFD04+1
        defadr _fopen,0x146F6100+1
        defadr fread,0x141B4D98+1
        defadr fclose,0x14644828+1
        defadr fwrite,0x146F6F9C+1
        defadr fstat,0x141F353C+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x140CD1E0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x15439164+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x153D0F84+1
        defadr Display_SetBrightness,0x1531A9B8+1
        defadr SaveBrightness,0x1556B618+1
        defadr Display_GetBrightness,0x1518349C+1
        defadr DispObject_SetLayerColor,0x140DB5BC+1
        defadr DispObject_InvalidateRect,0x142BE14C+1
        defadr DISP_DESC_SetName,0x1429F04C+1
        defadr DISP_DESC_SetSize,0x1429F040+1
        defadr DISP_DESC_SetOnCreate,0x1429F048+1
        defadr DISP_DESC_SetOnClose,0x1429F050+1
        defadr DISP_DESC_SetOnRedraw,0x1429EFBC+1
        defadr DISP_DESC_SetOnLayout,0x1429EC2C+1
        defadr DISP_DESC_SetOnKey,0x1429EB70+1
        defadr UI_Event,0x1427AD8C+1
        defadr FreeBook,0x141043A0+1
        defadr GUIObject_Create,0x143AAE58+1
        defadr BookObj_AddGUIObject,0x1466A3D8+1
        defadr GUIObject_SetTitleType,0x14061680+1
        defadr GUIObject_SoftKeys_SetAction,0x143AF444+1
        defadr GUIObject_SoftKeys_SetText,0x14690210+1
        defadr GUIObject_Show,0x146CD3DC+1
        defadr snwprintf,0x148298C8+1
        defadr sscanf,0x102A68B8+1
        defadr TextID_Create,0x145382A0+1
        defadr TextID_Destroy,0x142C03B4+1
        defadr TextID_CreateIntegerID,0x14538140+1
        defadr DynamicMenu_SetElement_SecondLineText,0x147EC468+1

        defadr Display_GetWidth,0x140F54B8
        defadr Display_GetHeight,0x140F54C8

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
