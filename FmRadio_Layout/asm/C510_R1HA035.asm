//C510_R1HA035
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA32698
        defadr memfree,0x4BA326C0
        defadr memset,0x14B31C80
        defadr alloc,0x101CFCE4
        defadr receive,0x101CFD00
        defadr send,0x101CFCF0
        defadr sender,0x101CFD40
        defadr free_buf,0x101CFD10
        defadr create_process,0x101CFDDC
        defadr start,0x101CFFE8
        defadr get_ptype,0x101CFE9C
        defadr current_process,0x101CFDEC
        defadr delay,0x101CFD30
        defadr hunt,0x101CFEE8
        defadr kill_proc,0x101CFF14
        defadr receive_w_tmo,0x101CFD5C
        defadr stop,0x101CFD50
        defadr get_bid,0x101CFE24
        defadr snwprintf,0x143EEBC4+1
        defadr _fopen,0x141FA214+1
        defadr fclose,0x143CD0A0+1
        defadr fread,0x14178B8C+1
        defadr fwrite,0x143326C8+1
        defadr fstat,0x144D8BBC+1
        defadr CreateBook,0x142866FC+1
        defadr BookObj_GotoPage,0x14481B20+1
        defadr BookObj_ReturnPage,0x14212A58+1
        defadr FreeBook,0x141293FC+1
        defadr GUIObject_SetTitleText,0x1443F740+1
        defadr GUIObject_Show,0x144CB9BC+1
        defadr ListMenu_SetCursorToItem,0x14417A80+1
        defadr GUIObject_SetStyle,0x14129878+1
        defadr GUIonMessage_GetCreatedItemIndex,0x142C5BB4+1
        defadr GUIonMessage_SetMenuItemText,0x1438A538+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x141326FC+1
        defadr ListMenu_GetSelectedItem,0x142800F8+1
        defadr ListMenu_SetItemStyle,0x140B9BF0+1
        defadr CreateOneOfMany,0x140B9B74+1
        defadr OneOfMany_SetChecked,0x1422CD38+1
        defadr OneOfMany_SetTexts,0x1419F5AC+1
        defadr OneOfMany_GetSelected,0x14457AA8+1
        defadr GUIObject_SoftKeys_SetAction,0x1417BACC+1
        defadr GUIObject_SoftKeys_SetText,0x141C50C8+1
        defadr GUIObject_SoftKeys_SetVisible,0x141C4E24+1
        defadr wstrlen,0x14178EC8+1
        defadr TextID_Create,0x141818E4+1
        defadr TextID_Destroy,0x14182788+1
        defadr GUIObject_GetDispObject,0x140CACD8+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x144B9C9C+1
        defadr BookObj_Hide,0x142753C4+1
        defadr ListMenu_SetOnMessage,0x14302734+1
        defadr get_envp,0x101D68A8+1
        defadr set_envp,0x101D68BC+1
        defadr UI_Event,0x140C5938+1
        defadr CreateListMenu,0x14285AF8+1
        defadr ListMenu_SetItemCount,0x14280610+1
        defadr GUIObject_Destroy,0x144CBD98+1
        defadr get_DisplayGC,0x1449E09C+1
        defadr GC_GetRect,0x140C9E80+1
        defadr GC_GetXX,0x1419CE14+1
        defadr GC_SetXX,0x140B2DB8+1
        defadr BookObj_AddGUIObject,0x14285AEC+1
        defadr DrawRect,0x1445A7BC+1
        defadr DispObject_InvalidateRect,0x140CA948+1
        defadr GUIObject_Create,0x144CB8B0+1
        defadr DISP_DESC_SetName,0x142957C4+1
        defadr DISP_DESC_SetSize,0x142958A8+1
        defadr DISP_DESC_SetOnCreate,0x14295844+1
        defadr DISP_DESC_SetOnClose,0x14295840+1
        defadr DISP_DESC_SetOnRedraw,0x14295848+1
        defadr DISP_DESC_SetOnKey,0x14295990+1
        defadr DISP_DESC_SetOnRefresh,0x1429540C+1
        defadr DISP_DESC_SetMethod0A,0x142954CC+1
        defadr GC_GetPenColor,0x14435440+1
        defadr GC_SetPenColor,0x1449E18C+1
        defadr GC_DrawLine,0x140917BC+1
        defadr GUIObject_SetTitleType,0x14093534+1
        defadr GUIonMessage_SetItemDisabled,0x144DF9F4+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x150D4864+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x150D48EC+1
        defadr GUIObject_SoftKeys_Hide,0x144CB138+1
        defadr ListMenu_SetItemSecondLineText,0x142A8E24+1
        defadr ImageID_Free,0x14410D58+1
        defadr FILEITEM_GetFname,0x142C7D74+1
        defadr FILEITEM_GetPath,0x142C7CA0+1
        defadr DispObject_SetRefreshTimer,0x1412E1BC+1
        defadr DispObject_KillRefreshTimer,0x1449F134+1
        defadr ImageID_GetIndirect,0x150D2C38+1
        defadr DispObject_SetLayerColor,0x140C6CA0+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x14129628+1
        defadr GUIonMessage_GetMsg,0x142C5CA4+1
        defadr ListMenu_DestroyItems,0x14280984+1
        defadr CoCreateInstance,0x1401106C+1
        defadr DispObject_SetAnimation,0x14E1B408+1
        defadr DisplayGC_AddRef,0x144CDAA4+1
        defadr TextObject_SetText,0x14183164+1
        defadr TextObject_SetFont,0x1449CD74+1
        defadr Audio_GetTags,0x157523B8+1
        defadr CreateYesNoQuestion,0x142CD924+1
        defadr YesNoQuestion_SetDescriptionText,0x14337444+1
        defadr YesNoQuestion_SetQuestionText,0x14337434+1
        defadr YesNoQuestion_SetIcon,0x14337428+1
        defadr MessageBox_NoIMAGE,0x14CE140C+1
        defadr w_chdir,0x104F943C+1
        defadr w_fopen,0x100A6E5C+1
        defadr w_fstat,0x100A6EA0+1
        defadr w_fwrite,0x100F2624+1
        defadr w_fread,0x100F2E7C+1
        defadr w_lseek,0x10589418+1
        defadr w_fclose,0x1013A908+1
        defadr w_mkdir,0x104F62FC+1
        defadr DISP_DESC_SetOnLayout,0x14295474+1
        defadr GUIObject_SoftKeys_Show,0x1412982C+1
        defadr FILEITEM_GetFextension,0x142C7EEC+1
        defadr wstrncmp,0x14325C10+1
        defadr Display_GetHeight,0x140C93BC+1
        defadr Display_GetWidth,0x140C93AC+1
        defadr GUIObject_SoftKeys_SetInfoText,0x141283F0+1
        defadr DispObject_GetGUI,0x142A8F2C+1
        defadr FSX_IsFileExists,0x14411678+1
        defadr CreatePalette,0x157089D0+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x1527FEA8+1
	defadr TextID_CreateIntegerID,0x1401F5BC+1
        defadr CreateMessageBox,0x14CE140C+1
        defadr GUIObject_GetBook,0x140CAEC8+1
        defadr DispObject_SetThemeImage,0x144815C4+1

//------------------------------------------------------------------------------

        defadr FmRadio_SetActiveSoftKeys,0x1554AC48+1

        defadr FmRadio_Gui_OnCreate,0x15548CCC+1
        defadr FmRadio_Gui_OnClose,0x15548D7C+1
        defadr FmRadio_Gui_OnRedraw,0x15548F94+1
        defadr FmRadio_Gui_OnKey,0x15548DD4+1
        defadr FmRadio_Gui_OnMethod0A,0x15548EC4+1

        defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x1554A84C+1
        defadr pg_FmRadio_Base__UI_FMRADIO_CREATED_EVENT,0x1554B238+1

        EXTERN New_FmRadio_Gui_OnCreate
        EXTERN New_FmRadio_Gui_OnClose
        EXTERN New_FmRadio_Gui_OnRedraw
        EXTERN New_FmRadio_Gui_OnKey
        EXTERN FmRadio_NewSoftKeys
        EXTERN FmRadio_UpdateSoftKeys
        EXTERN DeleteData
        EXTERN New_FmRadio_Main__PAGE_ENTER_EVENT

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

        RSEG PATCH_FmRadio_MainPage_Enter
        DATA
        DCD New_FmRadio_Main__PAGE_ENTER_EVENT

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

        RSEG PATCH_FmRadio_NewSoftKeys
	CODE16
	LDR	R3, =new_softkeys
	BX	R3

        RSEG  CODE
        CODE16
new_softkeys:
        LDR     R2, =0x95B
        LDR     R0, [R4,#0x18]
        MOV     R1, #5
        LDR	R3, =GUIObject_SoftKeys_SetInfoText
        BLX     R3
        LDR     R0, [R4,#0x18]
        BL      FmRadio_NewSoftKeys
        LDR	R3, =0x1554AB22+1
	BX	R3

//------------------------------------------------------------------------------

        RSEG PATCH_FmRadio_UpdateSoftKeys
	CODE16
	LDR	R3, =update_softkeys
	BX	R3

        RSEG  CODE
        CODE16
update_softkeys:
        LDR     R0, [R4,#0x18]
        ADD     R2, R5, #0
        MOV     R1, #3
        LDR	R3, =GUIObject_SoftKeys_SetVisible
        BLX	R3
        LDR     R0, [R4,#0x18]
        MOV     R1, #FMRADIO_ACTION_LAYOUT
        ADD     R2, R5, #0
        LDR	R3, =GUIObject_SoftKeys_SetVisible
        BLX	R3
        LDR	R3, =0x1554AC76+1
        BX	R3

        END
