//W595_R3EF001
#include "target.h"

defadr  MACRO   a,b
        PUBLIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BB00584
        defadr memfree,0x4BB005AC
        defadr memset,0x118940EC+1
        defadr memcpy,0x11893FEC+1
        defadr debug_printf,0x4BB39F21
        defadr current_process,0x1017CBFC
        defadr get_bid,0x1017CC34
        defadr sprintf,0x106F81E0+1
        defadr snwprintf,0x106F8694+1
        defadr _fopen,0x10957B7C+1
        defadr fclose,0x11700750+1
        defadr fread,0x10959510+1
        defadr fwrite,0x109596DC+1
        defadr fstat,0x109584E0+1
        defadr lseek,0x10959884+1
        defadr FileCopy,0x10958A78+1
        defadr FileDelete,0x10958770+1
        defadr w_chdir,0x4BB003AC
        defadr w_fopen,0x11293964+1
        defadr w_fstat,0x11293A1C+1
        defadr w_fwrite,0x112939AC+1
        defadr w_fread,0x11293994+1
        defadr w_lseek,0x11A5073C+1
        defadr w_fclose,0x112939C4+1
        defadr w_mkdir,0x4BB00344
        defadr w_diropen,0x4BB00354
        defadr w_dirread,0x11A50DCC+1
        defadr w_dirclose,0x4BB0038C
        defadr w_rename,0x11A50E68+1
        defadr w_remove,0x11A50E1C+1
        defadr strlen,0x106F84C4+1
        defadr strncmp,0x106F8500+1
        defadr strncpy,0x106F8534+1
        defadr strcat,0x106F8430+1
        defadr strstr,0x106F85D0+1
        defadr wstrcpy,0x10D661EC+1
        defadr wstrncpy,0x10D66204+1
        defadr wstrcat,0x106F8D54+1
        defadr wstrncat,0x10D6624C+1
        defadr wstrcmp,0x10D661BC+1
        defadr wstrlen,0x10D661A8+1
        defadr wstrrchr,0x10D6752C+1
        defadr wstrnupr,0x10D66278+1
        defadr wstr2strn,0x10D662C8+1
        defadr str2wstr,0x10D67470+1
        defadr wstrncmp,0x106F8E28+1
        defadr TextID_CreateIntegerID,0x10F61C68+1
        defadr TextID_Create,0x10F61E3C+1
        defadr TextID_GetString,0x10F62548+1
        defadr TextID_GetWString,0x10F623D0+1
        defadr TextID_GetLength,0x10F62280+1
        defadr TextID_Destroy,0x10F62178+1
        defadr get_envp,0x10005C38+1
        defadr set_envp,0x10005C4C+1
        defadr GC_GetRect,0x109D0624+1
        defadr GC_GetXX,0x109D0920+1
        defadr GC_SetXX,0x109D0914+1
        defadr GC_DrawLine,0x109D0F70+1
        defadr GC_GetPenColor,0x109D082C+1
        defadr GC_SetPenColor,0x109D07F0+1
        defadr GC_SetBrushColor,0x109D08C8+1
        defadr GC_ValidateRect,0x109D05D4+1
        defadr BookObj_AddGUIObject,0x10DF0ABC+1
        defadr DrawRect,0x109CBD2C+1
        defadr DrawString,0x109CC078+1
        defadr SetFont,0x109CCC38+1
        defadr Disp_GetTextIDWidth,0x109CD3C4+1
        defadr DispObject_GetGUI,0x109C824C+1
        defadr DispObject_InvalidateRect,0x109C8968+1
        defadr GUIObject_GetBook,0x109D2030+1
        defadr GUIObject_GetDispObject,0x109D201C+1
        defadr GUIObject_Create,0x109D1DCC+1
        defadr get_DisplayGC,0x109CFFE0+1
        defadr DisplayGC_AddRef,0x109D0418+1
        defadr DISP_DESC_SetName,0x109C5418+1
        defadr DISP_DESC_SetSize,0x109C541C+1
        defadr DISP_DESC_SetOnCreate,0x109C5420+1
        defadr DISP_DESC_SetOnClose,0x109C5424+1
        defadr DISP_DESC_SetOnRedraw,0x109C5428+1
        defadr DISP_DESC_SetOnKey,0x109C5430+1
        defadr DISP_DESC_SetOnRefresh,0x109C542C+1
        defadr DISP_DESC_SetMethod06,0x109C5434+1
        defadr DISP_DESC_SetOnLayout,0x109C543C+1
        defadr DISP_DESC_SetOnConfig,0x109C5440+1
        defadr DispObject_SetLayerColor,0x109CAB60+1
        defadr DispObject_SetRefreshTimer,0x109C83D0+1
        defadr DispObject_KillRefreshTimer,0x109C844C+1
        defadr GUIonMessage_GetMsg,0x11A7E9F8+1
        defadr GUIonMessage_GetBook,0x11A7EA00+1
        defadr GUIonMessage_GetGui,0x11A7E9FC+1
        defadr GUIonMessage_GetCreatedItemIndex,0x11A7EA1C+1
        defadr GUIonMessage_SetMenuItemText,0x11A7EA28+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x11A7EA58+1
        defadr GUIonMessage_SetMenuItemInfoText,0x11A7EA38+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x11A7EA48+1
        defadr GUIonMessage_SetMenuItemIcon,0x11A7EA68+1
        defadr GUIonMessage_SetItemDisabled,0x11A7EAD0+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE,0x107A2574+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_REGISTER,0x107A25EC+1
        defadr REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER,0x107A2674+1
        defadr ImageID_Get,0x107A04F4+1
        defadr ImageID_Free,0x107A670C+1
        defadr ImageID_GetIndirect,0x107A058C+1
        defadr Timer_ReSet,0x10DECD40+1
        defadr Timer_Set,0x10DECD0C+1
        defadr Timer_Kill,0x10DECD98+1
        defadr CreateBook,0x10DF072C+1
        defadr BookObj_KillBook,0x10DF0840+1
        defadr BookObj_GotoPage,0x10DF043C+1
        defadr BookObj_CallPage,0x10DF0570+1
        defadr BookObj_ReturnPage,0x10DF05F4+1
        defadr BookObj_SetFocus,0x10DF09DC+1
        defadr BookObj_GetBookID,0x10DF0E98+1
        defadr BookObj_Hide,0x10DF0A04+1
        defadr BookObj_Show,0x10DF0A14+1
        defadr DispObject_SoftKeys_GetParams,0x1080A7E4+1
        defadr DispObject_SoftKeys_GetList,0x1080A828+1
        defadr BookObj_GetDisplayOrientation,0x10DF0F34+1
        defadr BookObj_SetDisplayOrientation,0x10DF0ED0+1
        defadr FreeBook,0x10DF0DAC+1
        defadr FindBook,0x10DF01F4+1
        defadr FindBookByID,0x10DEE930+1
        defadr FreeAllBook,0x10E27514+1
        defadr UI_Event,0x10DEF4CC+1
        defadr UI_Event_toBookID,0x10DEF524+1
        defadr IsAudioPlayerBook,0x10C86AE8+1
        defadr Display_GetHeight,0x1177DBF4+1
        defadr Display_GetWidth,0x1177DC00+1
        defadr GetImageWidth,0x109CD310+1
        defadr GetImageHeight,0x109CD324+1
        defadr CreateOneOfMany,0x11A80220+1
        defadr OneOfMany_SetItemCount,0x11A803AC+1
        defadr OneOfMany_SetChecked,0x11A803C8+1
        defadr OneOfMany_SetTexts,0x11A803FC+1
        defadr OneOfMany_GetSelected,0x11A803D8+1
        defadr OneOfMany_SetOnMessage,0x11A803F4+1
        defadr CreateListMenu,0x11A7DC44+1
        defadr ListMenu_SetItemStyle,0x11A7DE94+1
        defadr ListMenu_SetItemCount,0x11A7DE58+1
        defadr ListMenu_SetHotkeyMode,0x11A7DF94+1
        defadr ListMenu_SetTexts,0x11A7DF70+1
        defadr ListMenu_SetOnMessage,0x11A7DF68+1
        defadr ListMenu_GetSelectedItem,0x11A7DE44+1
        defadr ListMenu_SetCursorToItem,0x11A7DE30+1
        defadr ListMenu_SetNoItemText,0x11A7DFE8+1
        defadr ListMenu_SetItemTextScroll,0x11A7E538+1
        defadr ListMenu_SetItemSecondLineText,0x11A7E20C+1
        defadr ListMenu_DestroyItems,0x11A7E2B0+1
        defadr CreateYesNoQuestion,0x1177D3A4+1
        defadr YesNoQuestion_SetDescriptionText,0x1177D70C+1
        defadr YesNoQuestion_SetQuestionText,0x1177D6FC+1
        defadr YesNoQuestion_SetIcon,0x1177D72C+1
        defadr GUIObject_SetStyle,0x109D21DC+1
        defadr GUIObject_GetStyle,0x109D21F8+1
        defadr GUIObject_SetTitleType,0x109D237C+1
        defadr GUIObject_SetTitleText,0x109D2398+1
        defadr GUIObject_SetSecondRowTitleText,0x109D23B4+1
        defadr GUIObject_Destroy,0x109D1F90+1
        defadr GUIObject_SoftKeys_SetAction,0x1080D3A4+1
        defadr GUIObject_SoftKeys_SetText,0x1080D41C+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x10B6BB38+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1080D540+1
        defadr GUIObject_SoftKeys_SetVisible,0x1080D4A0+1
        defadr GUIObject_SoftKeys_SetInfoText,0x1080D408+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x1080D73C+1
        defadr GUIObject_SoftKeys_AllowKeylock,0x1080D6C0+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x1080D5E0+1
        defadr GUIObject_SoftKeys_Hide,0x1080D75C+1
        defadr GUIObject_SoftKeys_Show,0x1080D768+1
        defadr GUIObject_SoftKeys_RemoveBackground,0x1080D774+1
        defadr GUIObject_SoftKeys_RestoreBackground,0x1080D780+1
        defadr GUIObject_Show,0x109D2184+1
        defadr GUIObject_SetBacklightOn,0x109D22BC+1
        defadr GUIObject_SetBacklightOff,0x109D22E8+1
        defadr DispObject_SetStyle,0x109CAFF4+1
        defadr DispObject_GetStyle,0x109CB294+1
        defadr DispObject_SoftKeys_Show,0x10809904+1
        defadr DispObject_SoftKeys_Hide,0x108098CC+1
        defadr DispObject_SetAnimation,0x109CAC18+1
        defadr DispObject_SetBacklightMode,0x109CB940+1
        defadr DispObject_SetBacklightTimeout,0x109CB978+1
        defadr DispObject_SetThemeImage,0x109CA6BC+1
        defadr MediaPlayer_SoftKeys_SetText,0x10AF30F8+1
        defadr MediaPlayer_SoftKeys_SetAction,0x10AF30B0+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x10AF3158+1
        defadr MediaPlayer_SoftKeys_SetInfoText,0x10AF3188+1
        defadr FILEITEM_GetFname,0x117FC5B4+1
        defadr FILEITEM_GetPath,0x117FC648+1
        defadr FILEITEM_GetFextension,0x117FC5B8+1
        defadr MetaData_GetTags,0x117F79E8+1
        defadr CreateKeygrabberWindow,0x109D2738+1
        defadr Volume_Get,0x119DF98C+1
        defadr Volume_Set,0x119DF8C0+1
        defadr CoCreateInstance,0x1071BBB0+1
        defadr FSX_MakeFullPath,0x1095B320+1
        defadr FSX_FreeFullPath,0x1095B38C+1
        defadr FSX_IsFileExists,0x117F73D0+1
        defadr getFileExtention,0x1095B1EC+1
        defadr CreateMessageBox,0x11A559E8+1
        defadr List_DestroyElements,0x11AC4750+1
        defadr List_Create,0x11AC443C+1
        defadr List_Destroy,0x11AC4464+1
        defadr List_InsertFirst,0x11AC45B0+1
        defadr List_InsertLast,0x11AC45B8+1
        defadr List_Get,0x11AC465C+1
        defadr List_GetCount,0x11AC4630+1
        defadr List_RemoveFirst,0x11AC4608+1
        defadr List_RemoveAt,0x11AC453C+1
        defadr CreateTabMenuBar,0x1177B598+1
        defadr TabMenuBar_SetTabCount,0x1177B7F0+1
        defadr TabMenuBar_SetTabGui,0x1177B668+1
        defadr TabMenuBar_SetTabIcon,0x1177B6E8+1
        defadr TabMenuBar_SetTabTitle,0x1177B730+1
        defadr TabMenuBar_GetFocusedTab,0x1177B65C+1
        defadr TabMenuBar_SetFocusedTab,0x1177B64C+1
        defadr CreateStringInput,0x10892F1C+1
        defadr StringInput_SetMode,0x108937D4+1
        defadr StringInput_SetText,0x108939F0+1
        defadr StringInput_SetFixedText,0x10893918+1
        defadr StringInput_SetMinLen,0x1089383C+1
        defadr StringInput_SetMaxLen,0x108938EC+1
        defadr StringInput_SetEnableEmptyText,0x10893960+1
        defadr StringInput_SetActionOK,0x10893830+1
        defadr StringInput_SetActionBack,0x10893834+1
        defadr StringInput_GetStringAndLen,0x1089386C+1
        defadr StringInput_MenuItem_SetPriority,0x108939C0+1
        defadr TextFeedbackWindow,0x1177C8E4+1
        defadr Feedback_SetKeyHook,0x1177CCF0+1
        defadr Feedback_SetOnClose,0x1177CC8C+1
        defadr Feedback_SetTimeout,0x1177CCBC+1
        defadr Feedback_SetTextExtended,0x1177CD54+1
        defadr Feedback_CloseAction,0x1177CCB4+1
        defadr SETTING_RINGTYPESOUNDFILE_SET,0x11A9AA48+1
        defadr Sound_SetMessageAlert,0x10C500F8+1
        defadr Sound_SetAlarmsignal,0x10935654+1
        defadr Sound_AddToContact,0x10B538A4+1
        defadr OSE_GetShell,0x10E0F5C8+1
        defadr wstrcmpi,0x10D6760C+1
        defadr MainMenu_SetFromUserTheme,0x10DDD544+1
        defadr Set_SWF_AsFlashMenu,0x10D2EF48+1
        defadr MessageBox,0x11A55944+1
        defadr GetURIScheme,0x10E10E14+1
        defadr CreateURI,0x10E112B0+1
        defadr FreeURI,0x10E11404+1
        defadr Browser_OpenURI,0x1077CACC+1
        defadr strcmp,0x106F8468+1
        defadr Shortcut_Run,0x10DDCC9C+1
        defadr Shortcut_Get_MenuItemIconID,0x10DDC674+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x10DDB784+1
        defadr Shortcut_Get_MenuItemName,0x10B34240+1
        defadr MenuBook_Desktop,0x10DDC450+1
        defadr BookObj_SoftKeys_SetAction,0x108079F4+1
        defadr BookObj_SoftKeys_SetText,0x10807A2C+1
        defadr DataBrowser_isFileInListExt,0x10955E00+1
        defadr DataBrowserDesc_Create,0x117F2CF4+1
        defadr DataBrowserDesc_SetHeaderText,0x117F2FA4+1
        defadr DataBrowserDesc_SetBookID,0x117F2EF4+1
        defadr DataBrowserDesc_SetFolders,0x117F2F8C+1
        defadr DataBrowserDesc_SetFileExtList,0x117F2EA0+1
        defadr DataBrowserDesc_SetItemFilter,0x117F2E98+1
        defadr DataBrowserDesc_SetFoldersNumber,0x117F2F94+1
        defadr DataBrowserDesc_SetSelectAction,0x117F2F10+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x117F2EFC+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x117F2F58+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x117F2F60+1
        defadr DataBrowser_Create,0x117EEF60+1
        defadr DataBrowserDesc_Destroy,0x117F2DA4+1
        defadr JavaDialog_Open,0x10B1384C+1
        defadr JavaAppDesc_GetFirstApp,0x10B091E0+1
        defadr JavaAppDesc_GetJavaAppInfo,0x10B08CAC+1
        defadr JavaAppDesc_GetJavaAppID,0x10B170C8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x10C3B420+1
        defadr JavaAppDesc_GetNextApp,0x10B091E8+1
        defadr JavaDialog_Close,0x10B16FA0+1
        defadr JavaApp_LogoImageID_Get,0x10C2FC50+1
        defadr Display_GetTopBook,0x10DF0210+1
	defadr DataBrowserDesc_SetOpenEmptyFolder,0x117F302C+1
	defadr DataBrowserDesc_SetActions,0x117F2F68+1

        EXTERN GotoShortcut

        RSEG STANDBY_SOFTKEY_RIGHT
        DATA
	DCD TITLE_TXT

        RSEG STANDBY_LINK_RIGHT
        DATA
        DCD GotoShortcut

        END
