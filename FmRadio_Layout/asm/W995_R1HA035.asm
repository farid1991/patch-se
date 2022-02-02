//W995_R1HA035
#include "target.h"

defadr	MACRO	a,b
	PUBLIC	a
a       equ	b
	ENDM

	defadr memalloc,0x4BA33B64
	defadr memfree,0x4BA33B8C
	defadr memset,0x108F2864
	defadr get_envp,0x101EC73C+1
	defadr set_envp,0x101EC750+1
        defadr current_process,0x101E5C80
        defadr get_bid,0x101E5CB8

	defadr _fopen,0x1403EB5C+1
	defadr fclose,0x140FD63C+1
	defadr fread,0x144C2D80+1
	defadr fwrite,0x141C1358+1
	defadr FSX_IsFileExists,0x14FBB65C+1

	defadr CreateBook,0x144ABFCC+1
	defadr BookObj_GotoPage,0x14045980+1
	defadr BookObj_ReturnPage,0x142CAF34+1
	defadr FreeBook,0x14133830+1

	defadr GUIObject_GetBook,0x14105460+1
	defadr GUIObject_GetDispObject,0x1416DDB4+1
	defadr GUIObject_SetTitleText,0x141105C8+1
	defadr GUIObject_SetTitleType,0x143A26B0+1
	defadr GUIObject_Show,0x144ACC2C+1
	defadr GUIObject_Destroy,0x14512BE0+1

	defadr GUIonMessage_GetMsg,0x142F1378+1
	defadr GUIonMessage_GetCreatedItemIndex,0x142F1284+1
	defadr GUIonMessage_SetMenuItemText,0x142F0CFC+1
	defadr GUIonMessage_SetMenuItemSecondLineText,0x141FF338+1
	defadr GUIonMessage_SetItemDisabled,0x142593D8+1

	defadr CreateListMenu,0x14132F38+1
	defadr ListMenu_SetCursorToItem,0x141328FC+1
	defadr ListMenu_SetItemCount,0x142DA734+1
	defadr ListMenu_GetSelectedItem,0x1411BF24+1
	defadr ListMenu_SetItemStyle,0x140F6AE8+1
	defadr ListMenu_SetOnMessage,0x142DA720+1
	defadr ListMenu_SetItemSecondLineText,0x142DA5A4+1
	defadr ListMenu_DestroyItems,0x143C3870+1

	defadr CreateOneOfMany,0x140F6A6C+1
	defadr OneOfMany_SetItemCount,0x150CE954+1
	defadr OneOfMany_SetChecked,0x141117A0+1
	defadr OneOfMany_SetTexts,0x141AE38C+1
	defadr OneOfMany_GetSelected,0x1509EAB8+1

	defadr GUIObject_SoftKeys_SetAction,0x14105420+1
	defadr GUIObject_SoftKeys_SetText,0x14105150+1
	defadr GUIObject_SoftKeys_SetVisible,0x141053FC+1
	defadr GUIObject_SoftKeys_SetInfoText,0x140A7538+1
	defadr GUIObject_SoftKeys_SetActionAndText,0x15371AE4+1

	defadr TextID_Create,0x142D8380+1
	defadr TextID_Destroy,0x1416FB98+1
	defadr TextID_CreateIntegerID,0x143D6484+1
	defadr snwprintf,0x144A2EF0+1
	defadr CreateMessageBox,0x14EC3AAC+1

	defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x14EB3BFC+1
	defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x1515F1C8+1
	defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x1515F250+1

	defadr get_DisplayGC,0x1416CA0C+1
	defadr GC_GetRect,0x14117B70+1
	defadr GC_GetXX,0x142337A4+1
	defadr GC_SetXX,0x1419D3B0+1
	defadr GC_GetPenColor,0x144E2224+1
	defadr GC_SetPenColor,0x14107FF4+1
	defadr GC_DrawLine,0x144E1F44+1

	defadr BookObj_AddGUIObject,0x14132F2C+1
	defadr DrawRect,0x14107C80+1
	defadr DispObject_InvalidateRect,0x1416BA88+1
	defadr GUIObject_Create,0x144AD124+1
	defadr DispObject_GetGUI,0x14387AF8+1
	defadr DISP_DESC_SetName,0x14509ED0+1
	defadr DISP_DESC_SetSize,0x14509F1C+1
	defadr DISP_DESC_SetOnCreate,0x14509EC4+1
	defadr DISP_DESC_SetOnClose,0x14509ECC+1
	defadr DISP_DESC_SetOnRedraw,0x14509F20+1
	defadr DISP_DESC_SetOnKey,0x1450A328+1

	defadr Display_GetHeight,0x1411B1D0+1
	defadr Display_GetWidth,0x141AA5B8+1

	defadr CreateYesNoQuestion,0x1423638C+1
	defadr YesNoQuestion_SetDescriptionText,0x14082FCC+1
	defadr YesNoQuestion_SetQuestionText,0x14082FBC+1
	defadr YesNoQuestion_SetIcon,0x150C67E4+1

	defadr CoCreateInstance,0x14461E40+1
	defadr DisplayGC_AddRef,0x143D02EC+1
	defadr TextObject_SetText,0x14170568+1
	defadr TextObject_SetFont,0x1417346C+1

	defadr FmRadio_SetActiveSoftKeys,0x14F955B0+1

	defadr FmRadio_Gui_OnCreate,0x14EE8714+1
	defadr FmRadio_Gui_OnClose,0x14F6D2C0+1
	defadr FmRadio_Gui_OnRedraw,0x15040D34+1
	defadr FmRadio_Gui_OnKey,0x15089570+1
	defadr FmRadio_Gui_OnMethod0A,0x14D4A868+1

	defadr pg_FmRadio_Main__PAGE_ENTER_EVENT,0x14F5472C+1

//------------------------------------------------------------------------------

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
	BEQ     cont_
	ADD     R0, R1, #0
	LDR     R1, [R1,#0]
	LDR     R1, [R1,#0xC]
	BLX     R1
	MOV     R0, #0
	STR     R0, [R4,#8]
cont_:
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
	LDR	R3, =0x14FCCB66+1
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
	LDR	R3, =0x14F955DE+1
	BX	R3

	END
