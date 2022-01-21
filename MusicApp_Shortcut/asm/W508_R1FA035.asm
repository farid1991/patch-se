//W508_R1FA035
#include "target.h"

defadr  MACRO   a,b
        PUblIC  a
a       EQU     b
        ENDM

        defadr memalloc,0x4BA30DE8
        defadr memfree,0x4BA30E10
        defadr memset,0x14C23C5C
        defadr debug_printf,0x14C39CD0
        defadr current_process,0x101EC87C
        defadr get_bid,0x101EC8B4
        defadr set_envp,0x101F3448+1
        defadr get_envp,0x101F3434+1

        defadr strlen,0x14D09868+1
        defadr strstr,0x141EB45C+1
        defadr strcpy,0x14D09834+1
        defadr str2wstr,0x141604B4+1
        defadr wstrncmp,0x142C89A8+1
        defadr strncmp,0x1433778C+1
        defadr strcmp,0x14D0980C+1
        defadr wstrcpy,0x14310568+1
        defadr wstrncpy,0x14359CB0+1
        defadr wstrcmp,0x14310E1C+1
        defadr wstrlen,0x14311500+1
        defadr wstrcmpi,0x14311DE4+1
        defadr wstrrchr,0x1409B4A4+1
        defadr snwprintf,0x142C75F0+1
        
        defadr _fopen,0x1421A92C+1
        defadr fread,0x14310608+1
        defadr fclose,0x1410E040+1
        defadr fwrite,0x14572374+1
        defadr fstat,0x1435BA9C+1
        defadr w_diropen,0x4BA30BB8
        defadr w_chdir,0x4BA80C30
        defadr w_dirread,0x143AD8EC+1
        defadr w_fstat,0x10177468+1
        defadr w_dirclose,0x4BA80C10
        defadr FSX_IsFileExists,0x144BFCC0+1
        defadr FSX_MakeFullPath,0x142F18E0+1

        defadr GUIonMessage_GetBook,0x1412CA38+1
        defadr GUIonMessage_GetMsg,0x1412CC2C+1
        defadr GUIonMessage_GetCreatedItemIndex,0x1412CD24+1
        defadr GUIonMessage_SetMenuItemText,0x14540388+1
        defadr GUIonMessage_SetMenuItemIcon,0x14159AE8+1
        defadr GUIonMessage_SetMenuItemSecondLineText,0x1453FA40+1
        defadr GUIonMessage_SetItemDisabled,0x14246CC4+1
        defadr GUIonMessage_SetMenuItemUnavailableText,0x14FC395C+1
        defadr GUIonMessage_GetSelectedItem,0x14542184+1

        defadr MenuBook_Desktop,0x14148198+1
        defadr Shortcut_Get_MenuItemIconID,0x142E15F4+1
        defadr MenuBook_Desktop_GetSelectedItemID,0x14FB9F58+1
        defadr Shortcut_Get_MenuItemName,0x1455D97C+1
        defadr Shortcut_Run,0x1456FEB0+1

        defadr TextID_GetString,0x142262BC+1
        defadr TextID_GetWString,0x14225E3C+1
        defadr TextID_CreateIntegerID,0x1452561C+1
        defadr TextID_Create,0x14226B70+1
        defadr TextID_Copy,0x142264CC+1
        defadr TextID_Destroy,0x142261D0+1
        
        defadr FILEITEM_GetFname,0x144DD63C+1
        defadr FILEITEM_GetPath,0x144DD638+1

        defadr DataBrowser_isFileInListExt,0x1421BA8C+1
        defadr DataBrowserDesc_Create,0x141AE618+1
        defadr DataBrowserDesc_SetHeaderText,0x141AE600+1
        defadr DataBrowserDesc_SetBookID,0x141AE390+1
        defadr DataBrowserDesc_SetFolders,0x141AE730+1
        defadr DataBrowserDesc_SetFileExtList,0x141AE78C+1
        defadr DataBrowserDesc_SetItemFilter,0x14E0BCF4+1
        defadr DataBrowserDesc_SetFoldersNumber,0x141AE608+1
        defadr DataBrowserDesc_SetSelectAction,0x141AE610+1
        defadr DataBrowserDesc_Menu_AddFSFunctions,0x14E0B878+1
        defadr DataBrowserDesc_Menu_AddNewFolder,0x141AE738+1
        defadr DataBrowserDesc_Menu_AddMarkFiles,0x141AE578+1
        defadr DataBrowser_Create,0x143678FC+1
        defadr DataBrowserDesc_Destroy,0x141AE580+1

        defadr TabMenuBar_SetOnTabSwitch,0x142445B0+1
        defadr TabMenuBar_SetTabGui,0x142F660C+1
        defadr TabMenuBar_SetTabTitle,0x143BDDFC+1
        defadr TabMenuBar_GetFocusedTab,0x145403EC+1

        defadr CreateStringInput,0x144E4F48+1
        defadr StringInput_SetMode,0x1437F368+1
        defadr StringInput_SetText,0x1501B2A0+1
        defadr StringInput_SetEnableEmptyText,0x1501B258+1
        defadr StringInput_SetMinLen,0x1501B6A8+1
        defadr StringInput_SetMaxLen,0x1501B4C8+1
        defadr StringInput_SetActionOK,0x1501B348+1
        defadr StringInput_SetActionBack,0x1501B340+1
        defadr StringInput_GetStringAndLen,0x140B2CEC+1
        defadr StringInput_MenuItem_SetPriority,0x14F27670+1

        defadr CreateBook,0x1446A50C+1
        defadr FindBook,0x143111F8+1
        defadr FreeBook,0x14366418+1
        defadr BookObj_SetFocus,0x14221660+1
        defadr BookObj_CallPage,0x14247168+1
        defadr BookObj_GotoPage,0x14027124+1
        defadr BookObj_GetSession,0x140278A4+1
        defadr BookObj_ReturnPage,0x14247260+1
        defadr BookObj_GetBookID,0x14026BD4+1
        defadr BookObj_SoftKeys_SetAction,0x144DA404+1
        defadr BookObj_SoftKeys_SetText,0x14D271A8+1
        defadr IsVolumeControllerBook,0x141BD7DC+1
        defadr IsRightNowBook,0x14009A50+1
        defadr Find_StandbyBook,0x1444DBBC+1
        defadr UI_Event,0x1431CA88+1
        defadr UI_Event_toBookID,0x1431DDE4+1
        defadr UI_Event_toBookIDwData,0x14366354+1

        defadr List_Create,0x142DB0F8+1
        defadr List_Get,0x140480B0+1
        defadr List_GetCount,0x143114FC+1
        defadr List_InsertLast,0x142DAFB0+1
        defadr List_InsertFirst,0x1424C85C+1
        defadr List_RemoveAt,0x142C8564+1
        defadr List_RemoveFirst,0x14026BB8+1
        defadr List_DestroyElements,0x1424F7D0+1
        defadr List_Destroy,0x140265EC+1

        defadr CreateYesNoQuestion,0x143F2514+1
        defadr YesNoQuestion_SetQuestionText,0x140749F0+1
        defadr YesNoQuestion_SetDescriptionText,0x14074A00+1
        defadr YesNoQuestion_SetIcon,0x14EEF27C+1
        defadr CreateMessageBox,0x14EBC290+1

        defadr CreateListMenu,0x142211A8+1
        defadr GUIObject_SetTitleText,0x142E6810+1
        defadr ListMenu_SetItemCount,0x1421144C+1
        defadr ListMenu_SetCursorToItem,0x14365EBC+1
        defadr ListMenu_SetOnMessage,0x143E9E50+1
        defadr ListMenu_SetItemTextScroll,0x14541A0C+1
        defadr ListMenu_SetHotkeyMode,0x14365ED0+1
        defadr ListMenu_SetNoItemText,0x14F848D8+1
        defadr ListMenu_SetItemStyle,0x14365B90+1
        defadr ListMenu_GetSelectedItem,0x14542708+1
        defadr GUIObject_SoftKeys_SetVisible,0x1419E1C8+1
        defadr GUIObject_SoftKeys_SetActionAndText,0x143EBD40+1
        defadr GUIObject_SoftKeys_SetAction,0x1419E17C+1
        defadr GUIObject_SoftKeys_SetItemAsSubItem,0x1412B348+1
        defadr GUIObject_Show,0x14469D18+1
        defadr GUIObject_Destroy,0x14221158+1
        defadr GUIObject_SetStyle,0x142439D8+1
        defadr GUIObject_TabTitleRemove,0x15031E6C+1
        defadr GUIObject_SoftKeys_SetItemOnKey,0x140EF634+1
        defadr GUIObject_SoftKeys_SetText,0x1412B034+1
        defadr MediaPlayer_SoftKeys_SetItemAsSubItem,0x145B4FBC+1
        defadr MediaPlayer_SoftKeys_SetAction,0x145B4F44+1
        defadr MediaPlayer_SoftKeys_SetText,0x145B4EEC+1
        defadr GUIObject_SoftKeys_ExecuteAction,0x150DC7FC+1
        defadr OneOfMany_GetSelected,0x1451EC9C+1
        defadr ListMenu_DestroyItems,0x144318D0+1
        defadr CreateOneOfMany,0x141BD674+1
        defadr OneOfMany_SetChecked,0x142889B4+1
        defadr OneOfMany_SetItemCount,0x14F8421C+1
        defadr OneOfMany_SetOnMessage,0x14F84844+1
        defadr GUIObject_GetDispObject,0x14048B1C+1
        defadr DispObject_SoftKeys_GetList,0x1419DE54+1
        
        defadr JavaDialog_Open,0x141C731C+1
        defadr JavaAppDesc_GetFirstApp,0x141CAEE4+1
        defadr JavaAppDesc_GetJavaAppInfo,0x144ED6D0+1
        defadr JavaAppDesc_GetJavaAppID,0x144EDCA8+1
        defadr REQUEST_UI_OAF_START_APPLICATION,0x152FBF7C+1
        defadr JavaAppDesc_GetNextApp,0x144EE720+1
        defadr JavaDialog_Close,0x144EE618+1
        defadr JavaApp_LogoImageID_Get,0x142B7350+1
        defadr JavaSession_GetName,0x15141338+1
        defadr ImageID_Free,0x144BF648+1

        defadr Request_ICA_ShutdownAllConnections,0x1037D4C4+1
        defadr ConnectionManager_Connection_GetState_int,0x144BF820+1
        defadr Display_GetBrightness,0x14DD6C94+1
        defadr root_list_get_session_count,0x14063814+1
        defadr root_list_get_session,0x1419E844+1
        defadr GetNewEvent,0x14FB3440+1
        defadr iconidname2id,0x14358D08+1
        
        defadr MessageBox,0x1583DCFC+1
        defadr manifest_GetParam,0x143370D4+1
        defadr GetFreeBytesOnHeap,0x4BA30F54
        defadr REQUEST_SYSTEM_SHUTDOWN,0x10483E60+1
        defadr REQUEST_SYSTEM_RESTART,0x10483E80+1
        defadr FlightGetState,0x14153F2C+1
        defadr FlightControl,0x14D755AC+1

        defadr MusicApplication_Keyboard,0x1405BDF8+1
        defadr MusicApplication_Minimise,0x14E93600+1
        defadr MusicApplication_CancelAction,0x14F40AA8+1

//------------------------------------------------------------------------------

        EXTERN Set_New_Keyboard
        EXTERN Set_New_SoftKeys
        
        RSEG    PATCH_MUSIC_SOFTKEYS
        CODE16
        ldr     R3, =PATCH_Music_Softkeys
        bx      R3
        
        RSEG  CODE
        CODE16
PATCH_Music_Softkeys:
        ldr     R0, [R4,#0x20]
        bl      Set_New_SoftKeys
        ldr     R0, [R4,#0x20]
        mov     R2, #7
        mov     R1, #0xF
        ldr     r3, =GUIObject_SoftKeys_SetItemAsSubItem
        blx     r3
        ldr     R3, =0x145B4A12+1
        bx      R3
        
//------------------------------------------------------------------------------
        
        RSEG    PATCH_MUSIC_KEYBOARD1
        DATA
        dcd     Set_New_Keyboard
        
        RSEG    PATCH_MUSIC_KEYBOARD2
        DATA
        dcd     Set_New_Keyboard

        END