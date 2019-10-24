#ifdef C510_R1HA035


defadr  MACRO  a,b
        PUBLIC a
a       EQU    b
        ENDM
        
                defadr GUIObject_SoftKeys_SetAction,0x1410527C+1
                defadr GUIObject_Destroy,0x1451282C+1
                defadr GUIObject_GetDispObject, 0x1416D928+1
                defadr FreeBook,0x1413366C+1
                defadr OSE_GetShell,0x14169D40+1
                defadr CoCreateInstance,0x144619AC+1
                defadr fstat, 0x142915EC+1
                defadr snwprintf,0x144A2B14+1
                defadr _fopen,0x1403EDD8+1
                defadr fclose,0x140FD31C+1
                defadr fread,0x144C2A80+1
                defadr memset,0x14C4F00C
                defadr memalloc, 0x4BA3372C
                defadr memfree, 0x4BA33754
                defadr TextID_Create, 0x142D8069
                defadr GUIObject_Show, 0x144AC9FD
                defadr DynamicMenu_SetElement_FirstLineText, 0x1450FB04+1
                defadr DynamicMenu_SetElement_SecondLineText,0x1450F840+1
                defadr DynamicMenu_GetElementMsg,0x141DD0B0+1
                defadr TextObject_SetText,0x14170008+1
                defadr TextObject_SetFont,0x14172F04+1
                defadr BookObj_SetFocus, 0x14512239
                defadr CreateBook, 0x144ABDB1
                defadr DISP_DESC_SetName,0x14509BC0+1
                defadr DISP_DESC_SetSize,0x14509C0C+1
                defadr DISP_DESC_SetOnCreate,0x14509BB4+1
                defadr DISP_DESC_SetOnClose,0x14509BBC+1
                defadr DISP_DESC_SetOnRedraw,0x14509C10+1
                defadr DISP_DESC_SetOnKey,0x1450A018+1
                defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1515ACBC+1
                defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1515AD44+1
                defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE, 0x14EB16C5
                defadr DisplayGC_AddRef,0x143D0680+1      
                defadr GC_SetPenColor,0x14107E50+1
                defadr BookObj_AddGUIObject,0x14132D68+1
                defadr TextID_CreateIntegerID,0x143D67E4+1
                defadr TextID_Destroy,0x1416F6B8+1
                defadr GUIObject_SetTitleText,0x141103BC+1
                defadr FindBookEx, 0x1439E811
                defadr Display_GetTopBook, 0x14F75ECD
                defadr GUIObject_SoftKeys_RemoveBackground, 0x143A160D
                defadr GUIObject_Create,0x144ACEF4+1
                defadr DispObject_InvalidateRect,0x1416B5FC+1
                defadr GUIObject_SetStyle, 0x14132B79
                defadr REQUEST_SETTING_RINGVOLUME_SET, 0x1597F815
                defadr get_DisplayGC, 0x1416C581
                defadr GC_DrawRoundRect, 0x14503AC5
                defadr GC_DrawFRect, 0x1428CD31
                defadr DispObject_SetLayerColor, 0x144AD5E5
                defadr GetAudioSettings, 0x142743DD
                defadr sscanf, 0x101E8965
                defadr strcmp, 0x14D39935
                
                defadr VolumeSet, 0x142745D9
        
#endif
        END