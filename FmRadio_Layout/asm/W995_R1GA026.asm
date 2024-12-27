//W995_R1GA026

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA3372C
        defadr memfree,0x4BA33754
        defadr memset,0x14C4F00C
        defadr snwprintf,0x144A2B14+1
        defadr _fopen,0x1403EDD8+1
        defadr fclose,0x140FD31C+1
        defadr fread,0x144C2A80+1
        defadr fwrite,0x141C0C0C+1
        defadr fstat,0x142915EC+1
        defadr CreateBook,0x144ABDB0+1
        defadr BookObj_GotoPage,0x1404570C+1
        defadr BookObj_ReturnPage,0x142CAC50+1
        defadr FreeBook,0x1413366C+1
        defadr FindBook,0x1416E4E0+1
        defadr IsFmRadioBook,0x14F9EB20+1
        defadr GUIObject_SetTitleText,0x141103BC+1
        defadr GUIObject_Show,0x144AC9FC+1
        defadr ListMenu_SetCursorToItem,0x14132758+1
        defadr GUIObject_SetStyle,0x14132B78+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142F0E20+1
        defadr GUIonMessage_SetMenuItemText,0x142F08FC+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141FEBCC+1
        defadr ListMenu_GetSelectedItem,0x1411BDA8+1
        defadr ListMenu_SetItemStyle,0x140F67C8+1
        defadr CreateOneOfMany,0x140F674C+1
        defadr OneOfMany_SetChecked,0x14111568+1
        defadr OneOfMany_SetTexts,0x141ADC7C+1
        defadr OneOfMany_GetSelected,0x1509AE50+1
        defadr GUIObject_SoftKeys_SetAction,0x1410527C+1
        defadr GUIObject_SoftKeys_SetText,0x14104FB4+1
        defadr GUIObject_SoftKeys_SetVisible,0x14105258+1
        defadr GUIObject_SoftKeys_SetInfoText,0x140A71C0+1
        defadr wstrlen,0x144C2DD4+1
        defadr TextID_Create,0x142D8068+1
        defadr TextID_Destroy,0x1416F6B8+1
        defadr GUIObject_GetDispObject,0x1416D928+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14EB16C4+1
        defadr BookObj_Hide,0x14201824+1
        defadr ListMenu_SetOnMessage,0x142DA358+1
        defadr get_envp,0x101EB37C+1
        defadr set_envp,0x101EB390+1
        defadr UI_Event,0x143A0CE8+1
        defadr CreateListMenu,0x14132D74+1
        defadr ListMenu_SetItemCount,0x142DA36C+1
        defadr GUIObject_Destroy,0x1451282C+1
        defadr get_DisplayGC,0x1416C580+1
        defadr GC_GetRect,0x14117A14+1
        defadr GC_GetXX,0x14232F48+1
        defadr GC_SetXX,0x1419CD1C+1
        defadr BookObj_AddGUIObject,0x14132D68+1
        defadr DrawRect,0x14107ADC+1
        defadr DispObject_InvalidateRect,0x1416B5FC+1
        defadr GUIObject_Create,0x144ACEF4+1
        defadr DISP_DESC_SetName,0x14509BC0+1
        defadr DISP_DESC_SetSize,0x14509C0C+1
        defadr DISP_DESC_SetOnCreate,0x14509BB4+1
        defadr DISP_DESC_SetOnClose,0x14509BBC+1
        defadr DISP_DESC_SetOnRedraw,0x14509C10+1
        defadr DISP_DESC_SetOnKey,0x1450A018+1
        defadr DISP_DESC_SetOnRefresh,0x1450A014+1
        defadr DISP_DESC_SetMethod0A,0x14509EEC+1
        defadr GC_GetPenColor,0x14ED4020+1
        defadr GC_SetPenColor,0x14107E50+1
        defadr GC_DrawLine,0x144E1BFC+1
        defadr GUIObject_SetTitleType,0x143A2754+1
        defadr GUIonMessage_SetItemDisabled,0x14258EA8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1515ACBC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1515AD44+1
        defadr GUIObject_SoftKeys_Hide,0x145126E8+1
        defadr ListMenu_SetItemSecondLineText,0x142DA1DC+1
        defadr ImageID_Free,0x1448173C+1
        defadr FILEITEM_GetFname,0x142DBD50+1
        defadr FILEITEM_GetPath,0x142DBD54+1
        defadr DispObject_SetRefreshTimer,0x14234DD8+1
        defadr DispObject_KillRefreshTimer,0x141190EC+1
        defadr ImageID_GetIndirect,0x15159088+1
        defadr DispObject_SetLayerColor,0x144AD5E4+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x143A160C+1
        defadr GUIonMessage_GetMsg,0x142F0F14+1
        defadr ListMenu_DestroyItems,0x143C3BD8+1
        defadr CoCreateInstance,0x144619AC+1
        defadr DispObject_SetAnimation,0x14EE8080+1
        defadr DisplayGC_AddRef,0x143D0680+1
        defadr TextObject_SetText,0x14170008+1
        defadr TextObject_SetFont,0x14172F04+1
        defadr Timer_ReSet,0x1416A684+1
        defadr Timer_Set,0x1423DCEC+1
        defadr Timer_Kill,0x1416A974+1
        defadr Audio_GetTags,0x14E92E78+1
        defadr CreateYesNoQuestion,0x14235B20+1
        defadr YesNoQuestion_SetDescriptionText,0x14082D08+1
        defadr YesNoQuestion_SetQuestionText,0x14082CF8+1
        defadr YesNoQuestion_SetIcon,0x150C289C+1
        defadr MessageBox_NoImage,0x14EC150C+1
        defadr w_fopen,0x100B2D84+1
        defadr w_lseek,0x10644024+1
        defadr w_fclose,0x1014739C+1
        defadr w_fread,0x100FFB8C+1
        defadr DISP_DESC_SetOnLayout,0x14509FBC+1
        defadr GetIMEI,0x1442E3C4+1
        defadr GUIObject_SoftKeys_Show,0x143A152C+1
        defadr FILEITEM_GetFextension,0x142DB7AC+1
        defadr wstrncmp,0x14121538+1
        defadr Display_GetHeight,0x1411B074+1
        defadr Display_GetWidth,0x141A9ECC+1

        defadr FSX_IsFileExists,0x14FB86FC+1
        defadr CreatePalette,0x158218B0+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x1536C51C+1
	defadr TextID_CreateIntegerID,0x143D67E4+1
        //defadr DispObject_SetThemeImage,0x1169DE30+1

////////////////////////////////////////////////////////////////////////////////

        defadr FmRadio_SetActiveSoftKeys,0x14F928A8+1

        defadr FmRadio_Gui_OnCreate,0x14EE5F00+1
        defadr FmRadio_Gui_OnClose,0x14F6A5F4+1
        defadr FmRadio_Gui_OnRedraw,0x1503D510+1
        defadr FmRadio_Gui_OnKey,0x150859A4+1
        defadr FmRadio_Gui_OnMethod0A,0x14D48C9C+1

        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x14F51BA4+1

        EXTERN New_FmRadio_Gui_OnCreate
        EXTERN New_FmRadio_Gui_OnClose
        EXTERN New_FmRadio_Gui_OnRedraw
        EXTERN New_FmRadio_Gui_OnKey
        EXTERN New_FmRadio_Gui_OnLayout
        EXTERN New_FmRadio_Gui_OnRefresh

        EXTERN FmRadio_NewSoftKeys
        EXTERN DeleteData

        EXTERN New_FmRadio_Base__UI_FMRADIO_CREATED_EVENT

        RSEG PATCH_FmRadio_OnCreate
        DATA
        DCD New_FmRadio_Gui_OnCreate

        RSEG PATCH_FmRadio_OnClose
        DATA
        DCD New_FmRadio_Gui_OnClose

        RSEG PATCH_FmRadio_OnRedraw
        DATA
        DCD New_FmRadio_Gui_OnRedraw

        RSEG PATCH_FmRadio_OnKey
        DATA
        DCD New_FmRadio_Gui_OnKey

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_DeleteData
        CODE16
        LDR	R3, =delete_data
	BX	R3

        RSEG  CODE
        CODE16
delete_data:
        CMP     R1, #0
        BEQ     nex_
        ADD     R0, R1, #0
        LDR     R1, [R1,#0]
        LDR     R1, [R1,#0xC]
        BLX     R1
        MOV     R0, #0
        STR     R0, [R4,#8]

nex_:
        BL      DeleteData
        POP     {R2-R7,PC}

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_NewSoftKey
	CODE16
	LDR	R3, =new_softkey
	BX	R3

        RSEG  CODE
        CODE16
new_softkey:
        LDR     R2, =0x95B
        LDR     R0, [R4,#0x18]
        MOV     R1, #5
        LDR	R3, =GUIObject_SoftKeys_SetInfoText
        BLX     R3
        LDR     R0, [R4,#0x18]
        BL      FmRadio_NewSoftKey
        LDR	R3, =0x14FC9C9E+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_UpdateSoftKey
	CODE16
	LDR	R3, =update_softkey
	BX	R3

        RSEG  CODE
        CODE16
update_softkey:
        LDR    R0, [R4,#0x18]
        ADD    R2, R5, #0
        MOV    R1, #3
        LDR	R3, =GUIObject_SoftKeys_SetVisible
        BLX	R3
        LDR    R0, [R4,#0x18]
        ADD    R2, R5, #0
        MOV    R1, #0x1F
        LDR	R3, =GUIObject_SoftKeys_SetVisible
        BLX	R3
        LDR	R3, =0x14F928D6+1
        BX	R3

        END
