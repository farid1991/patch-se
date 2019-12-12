//#include "classes.h"
#ifdef USEPNG
#include "png.h"
#endif

#ifdef USEZLIB
#include "zlib.h"
#endif

#include "..\\include\Colors.h"

#include "..\\include\classes\IRoot.h"
#include "..\\include\classes\IShell.h"
#include "..\\include\classes\ISockets.h"

#include "..\\include\classes\IAlarmManager.h"
#include "..\\include\classes\IAudioControlManager.h"
#include "..\\include\classes\IFMRadioManager.h"
#include "..\\include\classes\IClockManager.h"
#include "..\\include\classes\ICopsManager.h"
#include "..\\include\classes\IFlashLightControl.h"
#include "..\\include\classes\ISEMCRegistryManager.h"

#ifdef A2
#include "..\\include\classes\IIlluminationControl.h"
#include "..\\include\classes\IIlluminationManager.h"
#include "..\\include\classes\IIndicationDeviceManager.h"
#include "..\\include\classes\IMetaData.h"
#include "..\\include\classes\IMMEManager.h"
#include "..\\include\classes\IUIMediaCenterManager.h"
#include "..\\include\classes\IMusicServer_Manager.h"

#if defined (DB3200) || defined (DB3210) || defined (DB3350)
#include "..\\include\classes\IUIFontManager.h"
#include "..\\include\classes\IUIRichText.h"
#include "..\\include\classes\IUIRichTextLayoutOptions.h"
#include "..\\include\classes\IUITextRenderingManager.h"
#endif

#include "..\\include\classes\IUITextFactory.h"
#include "..\\include\classes\IUIClipboardManager.h"
#include "..\\include\classes\IUIGraphicManager.h"

//image
#include "..\\include\classes\IUIImageManager.h"

#include "..\\include\classes\IUIUtilManager.h"
#endif


__thumb void* malloc( int size );
__thumb void mfree( void* mem );

extern "C"
{
#pragma swi_number=0x10D
__swi __arm int elfload( const wchar_t* filename, void* param1, void* param2, void* param3 );

#if defined(DB2010)
  void* memalloc( int size, int f1, int f2, const char* fname, int fline );
  void memfree( void* mem, const char* fname, int fline );
#elif defined(DB2020)
  void* memalloc( int zero, int size, int f1, int f2, const char *fname, int fline );
  void memfree( int zero, void * mem, const char* fname, int fline );
#elif defined(A2)
  void* memalloc( int minus_one, int size, int f1, int f2, const char* fname, int fline );
  void memfree( int zero, void* mem, const char* fname, int fline );
  void* memcalloc( int minus_one, int size, int NoOfItems, int f1, int f2, const char* fname, int fline );
#endif

#if defined(A1)
  void* MetaData_Desc_Create( wchar_t* path, wchar_t* name );
  void MetaData_Desc_Destroy( void* MetaData_Desc );
  int MetaData_Desc_GetCoverInfo( void* MetaData_Desc, char* cover_type, int* size, int* cover_offset );
  wchar_t* MetaData_Desc_GetTags( void* MetaData_Desc, int tagID );
  void Display_SetBrightness( int display, int brightness );
  
  int AB_READSTRING( AB_STR_ITEM*, int rec_num, int field_ID );
  int MainInput_isPlus( GUI * gui );
  int MainInput_getCurPos( GUI* );
  void OrangeLED_Control( int _free_val, int or_LED_ID, int level, int fade_time );
  
  void GUIObject_SetTitleBackgroundImage( GUI*, IMAGEID );
  void GUIObject_SetCursorImage( GUI*, IMAGEID );
  void GUIObject_SetBackgroundImage( GUI*, IMAGEID );
  void GUIObject_SetTitleTextColor( GUI*, int color );
  
  int GetChipID( void );
  char* GetIMSI( void );
  int GetRadioState( char* level, char* flag );
  int GetSignalQuality( char* rssi, char* ber );
  int ConnectionManager_Connection_GetState( void );
  int get_CellData( PLMN_LAC_DESC* desc1, RAT_CI_DESC* desc2, char* CSReg );
  
  OSBOOLEAN get_mem( PROCESS pid, OSADDRESS from, void* to, OSADDRESS size );
#else
  void Display_SetBrightness( int level );
#endif

#if defined(A1) || defined(DB3150_V1) || defined(DB3150_V2)
  //FONT_DESC* GetFontDesc( void );
  //int* GetFontCount( void );
  int SetFont( int FontSize );
  void DrawString( TEXTID, int align, int x1, int y1, int x2, int y2, int unk, int unk1, int pen_color, int brush_color );
  void GC_PutChar( GC* gc, int x, int y, int width, int height, IMAGEID img );
  void GC_DrawIcon( int x, int y, IMAGEID );
  void GC_DrawImage( int x, int y, IMAGEID );
  int GetImageHeight( IMAGEID );
  int GetImageWidth( IMAGEID );
  int Disp_GetTextIDHeight( TEXTID );
  int Disp_GetTextIDWidth( TEXTID, int len );
  int GetVolumeSize( wchar_t* root_folder, VOLUMESIZE* );
#else
  int GetVolumeSize( wchar_t* root_folder, VOLUMESIZE_A2* );
#endif
  
  void* memset( void* mem, char chr, int size );
  int memcpy( void* dest, const void* source, int cnt );
  int sprintf( char* buf, const char* fmt, ... );
  int snwprintf( wchar_t* buffer, int size, const wchar_t* fmt, ... );
  int _fopen( const wchar_t* filpath, const wchar_t* filname, unsigned int mode, unsigned int rights, FILELISTITEM* destfname );
  int fclose( int file );
  int fread( int file, void* ptr, int size );
  int fwrite( int file, const void* ptr, int size );
  int fstat( const wchar_t* path, const wchar_t* fname, FSTAT* fstat_stuct );
  DIR_HANDLE* AllocDirHandle( const wchar_t* path );
  FILELISTITEM* GetFname( DIR_HANDLE*, FILELISTITEM* );
  void* DataBrowserDesc_Create( void );
  void DataBrowserDesc_SetItemStyle( void* DataBrowserDesc, int style );
  void DataBrowserDesc_SetHeaderText( void* DataBrowserDesc, TEXTID );
  void DataBrowserDesc_SetFolders( void* DataBrowserDesc, const wchar_t** FolderList );
  void DataBrowserDesc_SetOKSoftKeyText( void* DataBrowserDesc, TEXTID );
  void DataBrowser_Create( void* DataBrowserDesc );
  void DataBrowserDesc_Destroy( void* DataBrowserDesc );
  wchar_t* getFileExtention( wchar_t* fname );
  int DataBrowser_isFileInListExt( const wchar_t* ext_table, const wchar_t* path, const wchar_t* fname );
  void Timer_ReSet( u16* timer, int time, TIMERPROC onTimer, LPARAM lparam );
  u16 Timer_Set( int time, TIMERPROC onTimer, LPARAM lparam );
  void Timer_Kill( u16* timerID );
  int CreateBook( BOOK* pbook, void (*onClose)( BOOK* ), const PAGE_DESC* bp, const char* name, int ParentBookID, const APP_DESC* appdesc );
  void BookObj_KillBook( BOOK* book );
  void BookObj_GotoPage( BOOK* book, const PAGE_DESC* page );
  void BookObj_ReturnPage( BOOK* book, int );
  void FreeBook( BOOK* book );
  BOOK* FindBook( IS_NEEDED_BOOK );
  BOOK* Find_StandbyBook( void );
  void BookObj_SetFocus( BOOK* book, int display );
  void GUIObject_SetTitleText( GUI*, TEXTID );
  void GUIObject_Show( GUI* );
  void ListMenu_SetCursorToItem( GUI_LIST*, int item );
  void GUIObject_SetStyle( GUI*, int UI_OverlayStyle_t );
  int GUIonMessage_GetCreatedItemIndex( GUI_MESSAGE* msg );
  char GUIonMessage_SetMenuItemText( GUI_MESSAGE* msg, TEXTID );
  char GUIonMessage_SetMenuItemSecondLineText( GUI_MESSAGE* msg, TEXTID );
  char GUIonMessage_SetMenuItemInfoText( GUI_MESSAGE* msg, TEXTID );
  char GUIonMessage_SetMenuItemUnavailableText( GUI_MESSAGE* msg, TEXTID );
  void GUIonMessage_SetMenuItemIcon( GUI_MESSAGE* msg, int align, IMAGEID );
  void DispObject_SetTitleText( DISP_OBJ*, TEXTID );
  int ListMenu_GetSelectedItem( GUI_LIST* );
  void ListMenu_SetItemStyle( GUI_LIST*, int style );
  int IsScreenSaverBook( BOOK* bk );
  void StatusIndication_SetItemText( GUI*, int item, TEXTID );
  void StatusIndication_ShowNotes( TEXTID );
  GUI* CreateStringInputVA( int, ... );
  GUI_ONEOFMANY* CreateOneOfMany( BOOK* book );
  void OneOfMany_SetItemCount( GUI_ONEOFMANY*, int count );
  void OneOfMany_SetChecked( GUI_ONEOFMANY*, int checked );
  void OneOfMany_SetTexts( GUI_ONEOFMANY*, TEXTID* strids, int Count );
  int OneOfMany_GetSelected( GUI_ONEOFMANY* );
  void StatusIndication_Item8_SetText( TEXTID );
  void GUIObject_SoftKeys_SetAction( GUI*, u16 actionID, SKACTIONPROC proc );
  void GUIObject_SoftKeys_SetText( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_SetEnable( GUI*, u16 actionID, BOOL );
  void GUIObject_SoftKeys_AddErrorStr( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_RemoveItem( GUI*, u16 actionID );
  void GUIObject_SoftKeys_SetVisible( GUI*, u16 actionID, BOOL );
  void GUIObject_SoftKeys_SuppressDefaultAction( GUI*, u16 actionID );
  wchar_t* wstrcpy( wchar_t* dest, const wchar_t* source );
  wchar_t* wstrncpy( wchar_t* dest, const wchar_t* source, int maxlen );
  wchar_t* wstrcat( wchar_t* wstr, const wchar_t* subwstr );
  wchar_t* wstrncat( wchar_t* wstr, const wchar_t* subwstr, int maxlen );
  int wstrcmp( const wchar_t* wstr1, const wchar_t* wstr2 );
  int wstrlen( const wchar_t* wstr );
  wchar_t* str2wstr( wchar_t* wstr, const char* str );
  int strcmp( const char* str1, const char* str2 );
  int strlen( const char* str );
  char* wstr2strn( char* str, const wchar_t* wstr, int maxlen );

  TEXTID TextID_CreateIntegerID( int num );
  TEXTID TextID_Create( const void* wstr, int TEXT_ENCODING, int len );
  void TextID_GetString( TEXTID, char* str, int maxlen );
  int TextID_GetWString( TEXTID, wchar_t* dest, int maxlen );
  int TextID_GetLength( TEXTID );
  void TextID_Destroy( TEXTID );
  TEXTID TextID_Copy( TEXTID );

  int AB_DEFAULTNBR_GET( int rec_num, void* mem_0x30, int* unk );
  int AB_READPHONENBR( AB_NUM_ITEM*, int rec_num, int field_ID );
  int AB_GETNBROFITEMS( int get_from, int sub_id );
  int PNUM_len( BCD_TEXT pnum );
  void PNUM2str( char* str, BCD_TEXT pnum, int len, int max_len );
  DISP_OBJ* GUIObject_GetDispObject( GUI* );
  LIST* List_Create( void );
  void List_Destroy( LIST* lst );
  int List_InsertFirst( LIST* lst, void* item );
  int REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE( const int* sync, u16* ImageHandler, char* unk );
  void REQUEST_DATEANDTIME_GET( const int* sync, DATETIME* dt );
  void IndicationDevice_Backlight_FadeToLevel( int unk_zero, int bl_level );
  int GetFreeBytesOnHeap( void );
  void BookObj_Hide( BOOK* book, int display );
  void BookObj_Show( BOOK* book, int display );
  void StartAPP( const wchar_t* appname );
  void ListMenu_SetOnMessage( GUI_LIST*, int (*proc)( GUI_MESSAGE* ) );
  char* manifest_GetParam( const char* buf, const char* param_name, int unk );
  int lseek( int file, int offset, int mode );
  void SetLampLevel( int level );
  void* List_RemoveAt( LIST* lst, int index );
  PROCESS GetCurrentPID( void );
  int List_IndexOf( LIST* lst, void* item );
  union SIGNAL* alloc( OSBUFSIZE size, SIGSELECT signo );
  union SIGNAL* receive( const SIGSELECT* sigsel );
  void send( union SIGNAL** sig, PROCESS to );
  PROCESS sender( union SIGNAL** sig );
  void free_buf( union SIGNAL** sig );
  PROCESS create_process( PROCESS_TYPE proc_type, char* name, OSENTRYPOINT* entrypoint, OSADDRESS stack_size, OSPRIORITY priority, OSTIME timeslice, PROCESS pid_block, void* redir_table, OSVECTOR vector, OSUSER user );
  void start( PROCESS pid );
  int get_ptype( PROCESS pid );
  PROCESS current_process( void );
  void delay( OSTIME timeout );
  OSBOOLEAN hunt( const char* name, OSUSER user, PROCESS* name_, union SIGNAL** hunt_sig );
  void kill_proc( PROCESS pid );
  union SIGNAL* receive_w_tmo( OSTIME timeout, SIGSELECT* sel );
  void stop( PROCESS pid );
  OSADDRESS get_envp( PROCESS pid, char* name );
  OSBOOLEAN set_envp( PROCESS pid, char* name, OSADDRESS value );
  PROCESS get_bid( PROCESS pid );
  int datetime2unixtime( DATETIME* dt );
  char* strcpy( char* dest, const char* source );
  char* UIEventName( int event );
  void UI_Event( int event );
  void UI_Event_wData( int event, void* message, void (*free_proc)( void* ) );
  void UI_Event_toBookID( int event, int BookID );
  void UI_Event_toBookIDwData( int event, int BookID, void* message, void (*free_proc)( void* ) );
  int List_Find( LIST* lst, void* itemtofind, LISTFINDCALLBACK cmp_proc );
  void* List_Get( LIST* lst, int index );
  wchar_t* wstrrchr( const wchar_t* wstr, wchar_t wchar );
  void BookObj_CallSubroutine( BOOK* book, BOOK_SUBROUTINE* subr );
  int List_InsertLast( LIST* lst, void* item );
  void debug_printf( const char* fmt, ... );
  int PlayFile( const wchar_t* path, const wchar_t* fname );
  int REQUEST_PROFILE_GETACTIVEPROFILE( const int* sync, int* level );
  int Profile_SetActive( int NUMprof, int set_in_gdfs_flag );
  int isKeylocked( void );
  int IsMediaPlayerVideoBook( BOOK* bk );
  int REQUEST_DATEFORMAT_GET( const int* sync, char* DateFormat );
  int REQUEST_TIMEFORMAT_GET( const int* sync, char* TimeFormat );
  TEXTID Date2ID( DATE*, int DateFormat, int );
  TEXTID Time2ID( TIME*, char TimeFormat, int isSec );
  GUI_LIST* CreateListMenu( BOOK*, int display );
  void ListMenu_SetItemCount( GUI_LIST*, int item_count );
  void GUIObject_SoftKeys_SetInfoText( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_SetItemAsSubItem( GUI*, u16 actionID, int subitem );
  int REQUEST_SYSTEM_SHUTDOWN( void );
  int REQUEST_SYSTEM_RESTART( void );
  void GUIObject_SoftKeys_SetTexts( GUI*, u16 actionID, TEXTID short_text, TEXTID full_text );
  int IsRightNowBook( BOOK* book );
  int IsVolumeControllerBook( BOOK* book );
  GUI_TABMENUBAR* CreateTabMenuBar( BOOK* book );
  void TabMenuBar_SetTabCount( GUI_TABMENUBAR*, int count );
  void TabMenuBar_SetTabGui( GUI_TABMENUBAR*, int tab, GUI* );
  void TabMenuBar_SetTabIcon( GUI_TABMENUBAR*, int tab, IMAGEID, int for_state );
  GUI* GUIObject_Destroy( GUI* );
  void GUIInput_SetIcon( GUI*, IMAGEID );
  int StringInput_GetStringAndLen( GUI*, wchar_t**, u16* );
  int AudioControl_Vibrate( PAudioControl pIAudioControl, int vibratime, int pausetime, int totaltime );
  GUI_NOFMANY* CreateNOfMany( BOOK* book );
  void NOfMany_SetTexts( GUI_NOFMANY*, TEXTID* strids, int items_count );
  void NOfMany_SetChecked( GUI_NOFMANY*, u16* checked_table, int items_count );
  void NOfMany_SetCursor( GUI_NOFMANY*, int item );
  int NOfMany_GetCheckedCount( GUI_NOFMANY* );
  int NOfMany_GetChecked( GUI_NOFMANY*, u16* buffer );
  void NOfMany_SetOnMessage( GUI_NOFMANY*, int (*proc)( GUI_MESSAGE* ) );
  PAudioControl AudioControl_Init( void );
  void OneOfMany_SetFocused( GUI_ONEOFMANY*, int item );
  void OneOfMany_SetOnMessage( GUI_ONEOFMANY*, int (*proc)( GUI_MESSAGE* ) );
  GUI_FEEDBACK* CreateMonitorFeedback( TEXTID, BOOK*, void (*onbusy)( BOOK* ), void (*onedit)( BOOK* ), void (*ondelete)( BOOK* ) );
  void Feedback_SetText( GUI_FEEDBACK*, TEXTID );
  int GetBatteryState( void* unused, BATT* );
  GC* get_DisplayGC( void );
  void DispObject_GetRect( DISP_OBJ*, RECT* );
  void GC_GetRect( GC* gc, RECT* );
  int GC_GetXX( GC* gc );
  void GC_SetXX( GC* gc, int );
  void GC_ValidateRect( GC* gc, RECT* );
  void BookObj_AddGUIObject( BOOK* book, GUI* );
  void DrawRect( int x1, int y1, int x2, int y2, int pen_color, int brush_color );
  void XGUIList_AddGUIObject( XGUILIST* xguilist, GUI* );
  void DispObject_InvalidateRect( DISP_OBJ*, RECT* );
  int GUIObject_Create( GUI*, void (*GuiDestroy)( GUI* ), void (*DispDescCreate)( DISP_DESC* ), BOOK*, void (*DispObjCallBack)( DISP_OBJ*, void* msg, GUI* ), int display, int size_of_gui );
  int root_list_get_session_count( void );
  UI_APP_SESSION* root_list_get_session( int num_session );
  BOOK* SESSION_GetTopBook( UI_APP_SESSION* );
  int MainInput_strlen( GUI* );
  BCD_TEXT MainInput_getPNUM( GUI* );
  int BookObj_GetBookID( BOOK* book );
  int wstrncmp( const wchar_t*, const wchar_t*, int );
  int DispObject_GetAbsoluteXPos( DISP_OBJ* );
  int DispObject_GetAbsoluteYPos( DISP_OBJ* );
  int GetThemeColor( int, int );
  int REQUEST_SETTING_SILENCE_SET( const int* sync, u16 profile, u16 value );
  int REQUEST_SETTING_SILENCE_GET( const int* sync, u16 profile, char* silence_mode );
  void VCALL_Init( void* vc );
  void VCALL_SetName( void* vc, wchar_t* name, unsigned short name_len );
  void VCALL_SetNameIcon( void* vc, IMAGEID );
  void VCALL_SetNumber( void* vc, wchar_t* number, unsigned short num_len );
  void VCALL_SetHZ1( void* vc, int, u16 );
  void VCALL_SetHZ2( void* vc, u16 );void MakeVoiceCall( int SessioID, void* vc, int flag );
  void FileDelete( wchar_t* path, wchar_t* filename, int* error );
  void GUIObject_SetFocus( GUI*, int );
  int MSG_SendMessage_CreateMessage( int, void* );
  int MSG_SendMessage_DestroyMessage( void* );
  int MSG_SendMessage_AddRecipient( void*, wchar_t*, wchar_t*, int, int );
  int MSG_SendMessage_Start( int, void*, int );
  int AB_POSITIONNBR_GET( void* ab_name, char*, u16*, void* ab_num );
  TEXTID AB_NAME_ITEM2TextID( AB_STR_ITEM* ab_name );
  TEXTID AB_NUM_ITEM2TextID( AB_NUM_ITEM* ab_num_item );
  int GetABRecNum( AB_GET_STRUCT* ); //nullsub(void)
  GUI* SBY_GetMainInput( BOOK* StandBy ); // !!!!! Not real !!!!!!
  GUI* SBY_GetStatusIndication( BOOK* StandBy ); // !!!!! Not real !!!!!!
  int REQUEST_PHONEBOOK_ACCESSSTATUS_TOTAL_GET( const int* sync, int* );
  GUI* DispObject_GetGUI( DISP_OBJ* );
  DISP_OBJ* Display_GetFocusedDispObject( int display );
  char DispObject_GetVisible( DISP_OBJ* );
  DISP_DESC* DispObject_GetDESC( DISP_OBJ* ); // !!!!! Not real !!!!!!
  void DISP_DESC_SetName( DISP_DESC*, const char* name );
  char* DispObject_GetName( DISP_OBJ* );
  void DISP_DESC_SetSize( DISP_DESC*, u16 size );
  void DISP_DESC_SetOnCreate( DISP_DESC*, DISP_OBJ_ONCREATE_METHOD );
  DISP_OBJ_ONCREATE_METHOD DispObject_GetOnCreate( DISP_OBJ* );
  void DISP_DESC_SetOnClose( DISP_DESC*, DISP_OBJ_ONCLOSE_METHOD );
  DISP_OBJ_ONCLOSE_METHOD DispObject_GetOnClose( DISP_OBJ* );
  void DISP_DESC_SetOnRedraw( DISP_DESC*, DISP_OBJ_ONREDRAW_METHOD );
  DISP_OBJ_ONREDRAW_METHOD DispObject_GetOnRedraw( DISP_OBJ* );
  void DISP_DESC_SetOnKey( DISP_DESC*, DISP_OBJ_ONKEY_METHOD );
  DISP_OBJ_ONKEY_METHOD DispObject_GetOnKey( DISP_OBJ* );
  void DISP_DESC_SetOnRefresh( DISP_DESC*, DISP_OBJ_METHOD );
  DISP_OBJ_METHOD DispObject_GetonRefresh( DISP_OBJ* );
  void DISP_DESC_SetMethod06( DISP_DESC*, DISP_OBJ_METHOD );
  DISP_OBJ_METHOD DispObject_GetMethod06( DISP_OBJ* );
  void DISP_DESC_SetOnLayout( DISP_DESC*, DISP_OBJ_ONLAYOUT_METHOD );
  DISP_OBJ_METHOD DispObject_GetOnLayout( DISP_OBJ* );
  void DISP_DESC_SetOnConfig( DISP_DESC*, DISP_OBJ_ONCONFIG_METHOD );
  DISP_OBJ_METHOD DispObject_GetOnConfig( DISP_OBJ* );
  void DISP_DESC_SetMethod0A( DISP_DESC*, DISP_OBJ_METHOD );
  DISP_OBJ_METHOD DispObject_GetMethod0A( DISP_OBJ* );
  void JavaSession_Manager( int cmd ); //nullsub(void)
  TEXTID JavaSession_GetName( void ); //nullsub(ret 0x6FFFFFFF)
  UI_APP_SESSION* BookObj_GetSession( BOOK* book );
  void GUIonMessage_SetNumberOfSubItems( GUI_MESSAGE* msg, int unk, int num_sub_items );
  void GUIonMessage_SubItem_SetText( GUI_MESSAGE* msg, TEXTID );
  int GUIonMessage_SubItem_GetCreatedParentIndex( GUI_MESSAGE* msg );
  void GoMusic( void );
  int GUIonMessage_SubItem_GetSelectedIndex( GUI_MESSAGE* msg );
  void GUIonMessage_SubItem_SetDisabled( GUI_MESSAGE* msg, BOOL state );
  int PlayFileV( const wchar_t* path, const wchar_t* fname, int vol );
  BOOL GetSilent( void );
  int GetVibrator( int ignorevibrator, int ignoresilent );
  int GetAudioSettings( int what, char* retvalue );
  int GUIonMessage_SubItem_GetCreatedIndex( GUI_MESSAGE* msg );
  int GUIonMessage_SubItem_GetSelectedParentIndex( GUI_MESSAGE* msg );
  void DestroyDirHandle( DIR_HANDLE* handle );
  void GetOtherExtMethods( FILESUBROUTINE** );
  int MessageBox( TEXTID header_text, TEXTID message_text, IMAGEID, int style, int time, BOOK* book );
  int Display_GetHeight( int display );
  int Display_GetWidth( int display );
  void PlaySystemSound( int SndNumber );
  int TabMenuBar_GetFocusedTab( GUI_TABMENUBAR* );
  void TabMenuBar_SetFocusedTab( GUI_TABMENUBAR*, int tab_num );
  int GC_GetPenColor( GC* gc );
  void GC_SetPenColor( GC* gc, int pen_color );
  void GC_SetPixel( GC* gc, int x1, int y1, int color );
  void GC_DrawLine( GC* gc, int x1, int y1, int x2, int y2 );
  void GC_DrawFRect( GC* gc, int color, int x1, int y1, int x2, int y2 );
  int GC_WritePixels( GC* gc, int x1, int y1, int x2, int y2, int* bmp );
  
#ifdef USEPNG
  png_structp png_create_read_struct_2( png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn );
  void png_destroy_read_struct( png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr );
  png_infop png_create_info_struct( png_structp png_ptr );
  void png_destroy_info_struct( png_structp png_ptr, png_infopp info_ptr_ptr );
  void png_set_progressive_read_fn( png_structp png_ptr, png_voidp progressive_ptr, png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn, png_progressive_end_ptr end_fn );
  void png_process_data( png_structp png_ptr, png_infop info_ptr, png_bytep buffer, png_size_t buffer_size );
  void png_read_update_info( png_structp png_ptr, png_infop info_ptr );
  png_voidp png_get_progressive_ptr( png_structp png_ptr );
  png_uint_32 png_get_IHDR( png_structp png_ptr, png_infop info_ptr, png_uint_32* width, png_uint_32* height, int* bit_depth, int* color_type, int* interlace_method, int* compression_method, int* filter_method );
  void png_set_strip_16( png_structp png_ptr );
  void png_set_gray_1_2_4_to_8( png_structp png_ptr );
  void png_set_gray_to_rgb( png_structp png_ptr );
  png_uint_32 png_get_valid( png_structp png_ptr, png_infop info_ptr, png_uint_32 flag );
  void png_set_tRNS_to_alpha( png_structp png_ptr );
  void png_set_filler( png_structp png_ptr, png_uint_32 filler, int flags );
  void png_set_palette_to_rgb( png_structp png_ptr );
  png_uint_32 png_get_rowbytes( png_structp png_ptr, png_infop info_ptr );
  void png_progressive_combine_row( png_structp png_ptr, png_bytep old_row, png_bytep new_row );
  int png_sig_cmp( png_bytep sig, png_size_t start, png_size_t num_to_check );
#endif
  
  int memcmp( const void* m1, const void* m2, int n );
  int strncmp( const char* s1, const char* s2, int len );
  char* strncpy( char* dest, const char* source, int maxlen );
  char* strcat( char* dest, const char* src );
  void GUIObject_SetTitleType( GUI*, int type );
  void GUIonMessage_SetItemDisabled( GUI_MESSAGE* msg, BOOL );
  int REQUEST_IMAGEHANDLER_INTERNAL_REGISTER( const int* sync, u16 ImageHandler, wchar_t* path, wchar_t* fname, int unk, IMAGEID*, char* error );
  int REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER( const int* sync, u16 ImageHandler, u16*, u16*, IMAGEID, int unk_1, char* error );
  int iconidname2id( const wchar_t* idname, int maxnamelen, int* id );
  int textidname2id( const wchar_t* idname, int maxnamelen, TEXTID* id );
  void ListMenu_SetNoItemText( GUI_LIST*, TEXTID str );
  int IsFmRadioBook( BOOK* bk );
  IS_NEEDED_BOOK get_IsFmRadioBook( void );
  int IsAudioPlayerBook( BOOK* book );
  IS_NEEDED_BOOK get_IsAudioPlayerBook( void );
  void PlayerControl( BOOK* AudioPlayerBook, int );
  void SwitchRadioStationFromList( BOOK* FmRadioBook, int );
  void Shortcut_Run( wchar_t* shortcut_name );
  int mkdir( const wchar_t* path );
  int rmdir( const wchar_t* path, int zero );
  int chmod( const wchar_t* path, const wchar_t* fname, int amode );
  int rename( const wchar_t* oldpath, const wchar_t* oldfname, const wchar_t* newpath, const wchar_t* newfname, int zero );
  void* CallID_GetCallStatusDesc( int CallID );
  wchar_t* CallStatusDesc_GetName( void* CallStatusDesc );
  void List_DestroyElements( LIST* lst, int (*cmp_proc)( void* item ), void (*free_proc)( void* item ) );
  char* strstr( const char* str1, const char* str2 );
  int GPRS_GetLastSessionInfo( int, GPRS_SESSION_INFO* );
  int wstrcmpni( const wchar_t* wstr1, const wchar_t* wstr2, int len );
  int wtoi( const wchar_t* wstr, int len, int* dest );
  void DATE_GetWeekDay( DATE*, char* dest );
  void Cale_GetSettings( int setID, void* );
  wchar_t* wstrwstr( const wchar_t* wstr1, const wchar_t* wstr2 );
  int wstrcmpi( const wchar_t* ws1, const wchar_t* ws2 );
  wchar_t* wstrchr( const wchar_t* source, wchar_t chr );
  void GUIObject_SoftKeys_Hide( GUI* );
  void GUIObject_SoftKeys_Show( GUI* );
  DISP_OBJ* DispObject_SoftKeys_Get( void );
  int ThemeImage_SetImage( int type, int, int, const wchar_t* path, const wchar_t* fname, int );
  GUI* CreateYesNoQuestionVA( int zero, ... );
  void ListMenu_SetItemSecondLineText( GUI_LIST*, u16 Item, TEXTID );
  void _REQUEST_OAF_START_APPLICATION( const int* sync, int __zero, MIDP_DESC*, int ___zero );
  wchar_t* FSX_GetInvalidChar( wchar_t* name );
  void DataBrowserDesc_SetFoldersNumber( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetActions( void* DataBrowserDesc, char* actions );
  void DataBrowserDesc_SetSelectAction( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetSelectActionOnFolders( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetBookID( void* DataBrowserDesc, int BookID );
  void DataBrowserDesc_SetItemFilter( void* DataBrowserDesc, DB_FILE_FILTER );
  void DataBrowserDesc_SetOption( void* DataBrowserDesc, char* option );
  void DataBrowserDesc_SetOpenEmptyFolder( void* DataBrowserDesc, int state );
  void DataBrowserDesc_SetFileExtList( void* DataBrowserDesc, const wchar_t* ExtList );
  void FSX_RemoveIllegalSymbolsName( FILEITEM* );
  FILEITEM* FILEITEM_Create( void );
  void FILEITEM_Destroy( FILEITEM* );
  GUI* CreateDateInputVA( int zero, ... );
  GUI* CreateTimeInputVA( int zero, ... );
  void StringInput_SetCursorPosition( GUI*, u16 curs_pos, char unk );
  void BookObj_CallPage( BOOK* book, const PAGE_DESC* page );
  unsigned int DateInput_GetDateInt( GUI* );
  unsigned int TimeInput_GetTimeInt( GUI* );
  int GC_GetBrushColor( GC* gc );
  void GC_SetBrushColor( GC* gc, int brush_color );
  void GC_DrawRoundRect( GC* gc, RECT*, int arcWidth, int arcHeight, int border_flag, int fill_flag );
  BOOK* MenuBook_Desktop( int mode, int BookID );
  wchar_t* MenuBook_Desktop_GetSelectedItemID( BOOK* MenuBook_Desktop );
  void BookObj_SoftKeys_SetAction( BOOK* book, int actionID, SKACTIONPROC proc );
  void BookObj_SoftKeys_SetText( BOOK* book, int actionID, TEXTID );
  BOOK* FindBookByID( int BookID );
  GUI_FEEDBACK* TextFeedbackWindow( BOOK* book, int zero );
  void Feedback_SetKeyHook( GUI_FEEDBACK*, void (*hook)( BOOK* book, int key, int unk, int unk2 ) );
  void Feedback_SetOnClose( GUI_FEEDBACK*, void (*OnClose)( BOOK* book ) );
  void Feedback_SetTimeout( GUI_FEEDBACK*, int time_ms );
  void Feedback_SetTextExtended( GUI_FEEDBACK*, TEXTID text, int where );
  void TabMenuBar_SetOnTabSwitch( GUI_TABMENUBAR*, void (*proc)( BOOK*, int act_tab ) );
  TEXTID KeyCode2Name( int key_code );
  int ImageID_Get( const wchar_t* fpath, const wchar_t* fname, IMAGEID* );
  void ImageID_Free( IMAGEID );
  SUB_EXECUTE* DataBrowser_CreateSubExecute( int BookID, FILEITEM* );
  int DataBrowser_ExecuteSubroutine( SUB_EXECUTE* sub, int action, u16* unk );
  int FILEITEM_SetFname( FILEITEM*, const wchar_t* fname );
  int FILEITEM_SetPath( FILEITEM*, const wchar_t* fpath );
  wchar_t* FILEITEM_GetFname( FILEITEM* );
  wchar_t* FILEITEM_GetPath( FILEITEM* );
  int FILEITEM_SetFnameAndContentType( FILEITEM*, const wchar_t* fname );
  int FILEITEM_SetPathAndContentType( FILEITEM*, const wchar_t* fpath );
  int JavaDialog_Open( int unk1, char* unk2, void** JavaDesc );
  void JavaDialog_Close( int unk1 );
  int JavaAppDesc_Get( int unk1, void** JavaDesc );
  int JavaAppDesc_GetFirstApp( void* JavaDesc );
  int JavaAppDesc_GetNextApp( void* JavaDesc );
  int JavaAppDesc_GetJavaAppInfo( void* JavaDesc, int ID, wchar_t** wstr );
  void DispObject_SetRefreshTimer( DISP_OBJ*, int time );
  void DispObject_KillRefreshTimer( DISP_OBJ* );
  int IsDataBrowserBook( BOOK* book );
  SUB_EXECUTE* BrowserItem_Get_SUB_EXECUTE( BOOK* BrowserItemBook );
  TEXTID Shortcut_Get_MenuItemName( void* );
  IMAGEID Shortcut_Get_MenuItemIconID( void* );
  BOOK* FindBookEx( int (*cmp_proc)( BOOK* book_from_list, int* param ), int* param );
  FILEITEM* FILEITEM_CreateCopy( FILEITEM* );
  IMAGEID ImageID_Copy( IMAGEID );
  int BookObj_GetSessionID( BOOK* book );
  void UI_Event_toSID( int event, int sess_id );
  void UI_CONTROLLED_SHUTDOWN_RESPONSE( int book_id );
  void MainInput_Hide( GUI* );
  void DispObject_SoftKeys_RestoreDefaultAction( DISP_OBJ*, int action );
  TEXTID PNUM2Name( BCD_TEXT pnum, int isIconNeeded, int only_full_number_flag );
  int SpeedDial_GetPNUM( int _zero, char charter0__9, BCD_TEXT PNUM );
  int DispObject_GetWindowWidth( DISP_OBJ* );
  int DispObject_GetWindowHeight( DISP_OBJ* );
  int get_system_langID( void );
  char* lang_get_name( int langID );
  int w_chdir( const wchar_t* path );
  int w_fopen( const wchar_t* name, int attr, int rights, int err );
  int w_fstat( const wchar_t* name, W_FSTAT* );
  int w_fwrite( int f, void* buf, int size );
  int w_fread( int f, void* buf, int size );
  int w_lseek( int f, int offs, int mode );
  int w_fclose( int f );
  int w_mkdir( const wchar_t* path, int mode );
  int DirHandle_SetFilterStr( DIR_HANDLE*, const wchar_t* filter );
  int ImageID_GetIndirect( void* buf_image, int size, int __NULL, wchar_t* image_type, IMAGEID* );
  void unixtime2datetime( int, DATETIME* );
  int List_Insert( LIST* lst, int i, void* item );
  int FileCopy( wchar_t* src_path, wchar_t* src_name, wchar_t* dest_path, wchar_t* dest_name, int );
  int FileMove( wchar_t* src_path, wchar_t* src_name, wchar_t* dest_path, wchar_t* dest_name, int );
  void DispObject_SetLayerColor( DISP_OBJ*, int color );
  int JavaAppDesc_GetJavaAppID( void* JavaDesc );
  void REQUEST_UI_OAF_START_APPLICATION( const int* sync, int appID, char* flag );
  int JavaApp_LogoImageID_Get( wchar_t* fullpath, IMAGEID* );
  GUI* CreateProgressBar( BOOK* book, int display );
  void ProgressBar_SetText( GUI*, TEXTID text );
  void ProgressBar_SetIcon( GUI*, IMAGEID );
  void ProgressBar_SetPercentValue( GUI*, int value );
  void ProgressBar_SetBarDisabled( GUI*, BOOL );
  void StringInput_DispObject_SetText( DISP_OBJ*, TEXTID );
  void GUIObject_SetTitleIcon( GUI*, IMAGEID );
  void* DispObject_SoftKeys_GetParams( DISP_OBJ* );
  LIST* DispObject_SoftKeys_GetList( DISP_OBJ*, BOOK* book, char __zero );
  int BookObj_GetDisplayOrientation( BOOK* book );
  void BookObj_SetDisplayOrientation( BOOK* book, int orientation );
  BOOK* Display_GetTopBook( int display );
  int Display_GetBrightness( int display );
  void DataBrowserDesc_Menu_AddFSFunctions( void* DataBrowserDesc, int );
  void DataBrowserDesc_Menu_AddNewFolder( void* DataBrowserDesc, int );
  void DataBrowserDesc_Menu_AddMarkFiles( void* DataBrowserDesc, int );
  void SetTheme( wchar_t* path, wchar_t* name, int bookid, int unk_1 );
  void SoftKeys_GetLabel( DISP_OBJ* softkeys, SKLABEL* lbl, int id );
  void SoftKeys_Update( DISP_OBJ* softkeys );
  void* IncommingCall_Reject( BOOK* book );
  void* IncommingCall_Mute( BOOK* book );
  int Bluetooth_GetState( void );
  int Bluetooth_GetPhoneVisibility( void );
  int Bluetooth_isBusy( void );
  int USB_isConnected( void );
  void* w_diropen( const wchar_t* dir );
  wchar_t* w_dirread( void* );
  int w_dirclose( void* );
  int w_rename( const wchar_t* dst, const wchar_t* src );
  int w_remove( const wchar_t* dir );
  int IsCameraBook( BOOK* bk );
  int IsSoundRecorderBook( BOOK* bk );
  void StringInput_MenuItem_SetPriority( GUI* strinp, int prio, int actionID );
  void Video_ActionBack( BOOK* VideoPlayerBook, void* );
  void Video_ExtractFrame( BOOK* VideoPlayerBook, void* );
  void Video_ZoomOn( BOOK* VideoPlayerBook, void* );
  void RightNow_SetActive( int flag );
  void Video_Play( BOOK* VideoPlayerBook, void* );
  void Video_Pause( BOOK* VideoPlayerBook, void* );
  void Audio_Pause( BOOK* );
  void Audio_Play( BOOK* );
  GUI* CreatePercentInputVA( int zero, ... );
  int PercentInput_GetPercent( GUI* PercentInput );
  void GUIonMessage_SetLineSeparator( GUI_MESSAGE* msg, int _unk1 );
  int PHF_GetState( void );
  int CHF_GetState( void );
  void GUIObject_SoftKeys_RemoveBackground( GUI* );
  void GUIObject_SoftKeys_RestoreBackground( GUI* );
  void SetTrayIcon( IMAGEID, char mode );
  int REQUEST_SETTING_RINGVOLUME_SET( const int* sync, int unk, int null, int vol );
  int REQUEST_SETTING_VIBRATOR_SET( const int* sync, int unk, int mode );
  int REQUEST_SETTING_RINGTYPESOUNDFILE_SET( const int* sync, int null, wchar_t* path, wchar_t* name );
  int REQUEST_SETTING_ANSWERINGMODE_SET( const int* sync, int unk, int mode );
  int REQUEST_SETTING_INCREASINGRING_SET( const int* sync, int unk, int unk2, int mode );
  int REQUEST_SETTING_ALLOWEDCALLERS_SET( const int* sync, int unk, int mode );
  int JavaAppDesc_GetJavaAppFullpath( void* JavaDesc, JavaAppFullpath* );
  void* SoundRecorderDesc_Create( void );
  void SoundRecorderDesc_Destroy( void* desc );
  int SoundRecorderDesc_SetBookID( void* desc, int BookID );
  int SoundRecorderDesc_SetType( void* desc, const int type );
  int SoundRecorderDesc_SetFolder( void* desc, const wchar_t* fpath );
  int SoundRecorderDesc_SetFname( void* desc, const wchar_t* fname );
  int SoundRecorderDesc_SetRecordSize( void* desc, const int size );
  int SoundRecorder_Create( void* desc );
  int SoundRecorder_RecordCall( BOOK* OngoingCallBook );
  
  int SoundRecorderDesc_SetRecordTime( void* sd, ... );
  int SoundRecorderDesc_SetRadioVal( void* desc, int value );
  int SoundRecorderDesc_SetTitle( void* desc, TEXTID Title );
  int SoundRecorderDesc_SetStyle( void* desc, int style );
  
  int Browser_OpenURI( BOOK* book, char* URI, int mode );
  char* GetURIScheme( int schemeID );
  char* CreateURI( wchar_t* fpath, wchar_t* fname, char* URIScheme );
  void DataBrowserDesc_SetViewModeAndSortOrder( void* DataBrowserDesc, int view_sort_ID );
  int Alarm_GetCurrentTypeAndAlarmID( char* type, wchar_t* AlarmID );
  int Alarm_GetState( char* state, int AlarmID );
  int Alarm_GetTIME( TIME* AlarmTime, int AlarmID );
  int Alarm_GetWeekSettings( WEEK* week, int AlarmID );
  void REQUEST_SETTING_ALLOWEDCALLERS_GET( const int* sync, int ProfileNum, char* state );
  void* IncommingCall_Accept( BOOK* book );
  void MediaPlayer_SoftKeys_SetText( GUI* player_gui, int actionID, TEXTID );
  void MediaPlayer_SoftKeys_SetAction( GUI* player_gui, int actionID, SKACTIONPROC proc );
  void MediaPlayer_SoftKeys_SetItemAsSubItem( GUI* player_gui, int item, int subitem );
  void DispObject_Show( DISP_OBJ*, int mode );
  int Request_EventChannel_Subscribe( const int* sync, int mode, int event );
  void GUIObject_SoftKeys_ExecuteAction( GUI*, u16 actionID );
  int Request_ICA_ShutdownAllConnections( const int* sync );
  int REQUEST_PROFILE_GETPROFILENAME( const int* sync, int unk, TEXTID_DATA*, char* error );
  int DataBrowserDesc_SetFocusToFILEITEM( void* DataBrowserDesc, FILEITEM* );
  int GUIonMessage_GetMsg( GUI_MESSAGE* msg );
  BOOK* GUIonMessage_GetBook( GUI_MESSAGE* msg );
  GUI* GUIonMessage_GetGui( GUI_MESSAGE* msg );
  int GUIonMessage_GetSelectedItem( GUI_MESSAGE* msg );
  int GUIonMessage_GetPrevSelectedItem( GUI_MESSAGE* msg );
  void ObexSendFile( SEND_OBEX_STRUCT* );
  void Feedback_SetManualScrollingText( DISP_OBJ* feedback_disp_obj, int state );
  int EqualizerGain_Set( int AudioSessionID, int Band, int Level );
  int CANVAS_Get_GviGC( PCANVAS pcanvas, GVI_GC* dest );
  void GVI_BitBlt( GVI_GC destgc, int destx, int desty, int destxsize, int destysize, GVI_GC srcgc, int srcx, int srcy, int _204, int _0, int _0_2, int _0_3 );
  void GVI_StretchBlt( GVI_GC destgc, int destx, int desty, int destxsize, int destysize, GVI_GC srcgc, int srcx, int srcy, int srcxsize, int srcysize, int _204, int _0, int _0_2, int _0_3 );
  void GVI_TransformBlt( GVI_GC destgc, int destx, int desty, GVI_GC srcgc, int srcx, int srcy, int srcxsize, int srcysize, int orientation, int _0 );
  GVI_PEN GVI_CreatePen( char thikness, int color );
  GVI_PEN GVI_CreateDashedPen( char thikness, int color, int bitmask, int step, int offset );
  GVI_BRUSH GVI_CreateSolidBrush( int color );
  BOOL GVI_Delete_GVI_Object( GVI_OBJ* );
  void GVI_DrawEllipse( GVI_GC gc, int x, int y, int w, int h, GVI_PEN pen );
  void GVI_DrawLine( GVI_GC gc, int x1, int y1, int x2, int y2, GVI_PEN pen );
  void GVI_DrawLines( GVI_GC gc, POINT* points, int count, GVI_PEN pen );
  void GVI_DrawPolyLine( GVI_GC gc, POINT* points, int count, GVI_PEN pen, int is_closed );
  void GVI_DrawRectangle( GVI_GC gc, int x, int y, int w, int h, GVI_PEN pen );
  void GVI_DrawRoundRect( GVI_GC gc, int x, int y, int w, int h, int arcw, int arch, GVI_PEN pen );
  void GVI_DrawSolidLines( GVI_GC gc, POINT* points, int count, int color, int width );
  void GVI_DrawSolidPolyLine( GVI_GC gc, POINT* points, int count, int is_closed, int color, int width );
  void GVI_DrawSolidRectangle( GVI_GC gc, int x, int y, int w, int h, int color, int width );
  void GVI_FillEllipse( GVI_GC gc, int x, int y, int w, int h, GVI_BRUSH brush );
  void GVI_FillPolygon( GVI_GC gc, POINT* pp, int count, GVI_BRUSH brush );
  void GVI_FillRectangle( GVI_GC gc, int x, int y, int w, int h, GVI_BRUSH brush );
  void GVI_FillRectangles( GVI_GC gc, GVI_XYWH* rcs, int count, GVI_BRUSH brush );
  void GVI_FillSolidEllipse( GVI_GC gc, int x, int y, int w, int h, int color );
  void GVI_FillSolidRectangle( GVI_GC gc, int x, int y, int w, int h, int color );
  int GVI_FillSolidRoundRect( GVI_GC gc, int x, int y, int w, int h, int arcx, int arcy, int color );
  void GVI_FillSolidTriangle( GVI_GC gc, int x1, int y1, int x2, int y2, int x3, int y3, int color );
  GC* GC_CreateMemoryGC( int xsize, int ysize, int bpp, int unk, void* somefn, int unk2 );
  void GC_FreeGC( GC* gc );
  int Settings_ShowNumber_Get( char* state );
  GVI_BMP GVI_CreateBitmap( int xsize, int ysize, int bpp );
  GVI_GC GVI_CreateMemoryGC( GVI_BMP bitmap );
  void GVI_DeleteMemoryGC( GVI_GC gc );
  int StringInput_DispObject_SetLanguage( DISP_OBJ_STRING_INPUT*, int langID, int flag );
  int List_InsertSorted( LIST* list, void* item, int (*cmp_proc)( void*, void* ) );
  int ListMenu_SetItemIcon( GUI_LIST*, u16 Item, u16 unk_FFFF, int mode, IMAGEID );
  void wstrnupr( wchar_t* wstr, int maxlen );
  void wstrnlwr( wchar_t* wstr, int maxlen );
  int ListMenu_SetItemTextScroll( GUI_LIST*, int scroll );
  void GUIObject_SetListTextColor( GUI*, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro );
  void DispObject_SetTitleTextColor( DISP_OBJ*, int color );
  void DispObject_SetListTextColor( DISP_OBJ*, int unk1, int list_color, int unk2, int unk3, int list_select_color, int unk4, int _zerro );
  void DispObject_SetCursorImage( DISP_OBJ*, IMAGEID );
  void DispObject_SetBackgroundImage( DISP_OBJ*, IMAGEID );
  void DispObject_SetTitleBackgroundImage( DISP_OBJ*, IMAGEID );
  void TabMenuBar_SetTabTitle( GUI_TABMENUBAR*, int tab_num, TEXTID );
  BOOK* GUIObject_GetBook( GUI* );
  u16 SoftKeys_GetSelectedAction( void );
  void MonitorFeedback_SetTimer( GUI_FEEDBACK*, int time, void (*callback)( BOOK*) );
  void ListMenu_DestroyItems( GUI_LIST* );
  void DispObject_SetScrollBarBackgroundColor( DISP_OBJ*, int color );
  void DispObject_SetScrollBarColor( DISP_OBJ*, int color );
  void DispObject_SetSoftkeysColor( DISP_OBJ*, int color );
  void YesNoQuestion_SetIcon( GUI*, IMAGEID );
  void GUIObject_SetBacklightTimeout( GUI*, int time );
  void ListMenu_SetHotkeyMode( GUI_LIST*, LISTMENU_HOTKEY_MODE );
  void ListMenu_SetSearchLanguageMode( GUI_LIST*, int mode );
  void ListMenu_EnableSearchHeader( GUI_LIST*, BOOL );
  wchar_t* GUIonMessage_GetSearchString( GUI_MESSAGE* msg );
  int GUIonMessage_GetSearchStringLength( GUI_MESSAGE* msg );
  int EqualizerGain_Get( int AudioSessionID, int Band, int* Level );
  int Theme_DestroyMenuIcons( void );
  void CoCreateInstance( PUUID cid, PUUID iid, void** pInterface );
  void GUIObject_SetSecondRowTitleText( GUI*, TEXTID );
  int ListMenu_GetItemCount( GUI_LIST* );
  void OSE_GetShell( void** pInterface );
  int swscanf( const wchar_t* buffer, const wchar_t* format, ... );
  int sscanf( const char* buffer, const char* format, ... );
  void BookObj_WindowSetWantsFocus( BOOK* book, int display, BOOL WantsFocus );
  void BookObj_StayOnTop( BOOK* book, int mode );
  void DispObject_WindowSetPosition( DISP_OBJ*, int x, int y );
  void DispObject_WindowSetSize( DISP_OBJ*, int w, int h );
  TEXTID Feedback_DispObject_GetText( DISP_OBJ* );
  void DispObject_SoftKeys_ExecuteAction( DISP_OBJ*, u16 actionID );
  LIST* DataBrowserBook_GetCurrentFoldersList( BOOK* DataBrowserBook );
  void DispObject_SetAnimation( DISP_OBJ*, int style );
  void GUIObject_SetZOrder( GUI*, char, GUI* );
  int StringInput_GetCursorPosition( GUI*, u16* pos, char* _zero );
  void str2PNUM( BCD_TEXT pnum, char* str, int len, int max_len );
  void pb_ui_search_bk_create_search_menu( int BookID, int mode );
  void GUIObject_SoftKeys_SubActionPressedNotification( GUI*, u16 actionID, BOOL );
  int fs_demand_cache_page( int virtAddr, int mode, int intrMask );
  int fs_demand_pagePool_alloc_mem( pagePool* pagePool_p, int intrMask );
  wchar_t fs_demand_get_page_i_from_queue( wchar_t* queue, char only_allocked_pool, int page_count );
  void fs_demand_remove_from_queue( pageCache* page_p_to_remove, wchar_t page_i_to_insert );
  int fs_demand_kick_out_page( wchar_t page_i, int intrMask );
  char* getSWAP_DATA_BASE( void );

#ifdef A2  
// Library DLL function --------------------------------------------------------
  //void DisplayGC_AddRef( GC*, void* pICanvas );
  void DisplayGC_GetCanvas( GC*, void* pICanvas );
  void IUIRichText_SetText( void* pIUIRichText, TEXTID );
  void IUIRichText_SetFont( void* pIUIRichText, void* pIFont, const int pStartIndex, const int pCharsLeftToCompose);
  int IUIRichTextLayout_GetTextWidth( TEXTID, void* pIUIRichTextLayout, void* pIUIFont );
  
  int Illumination_LedID_SetLevel_Gradually( int LED_ID, int level, int fade_time );
  int Illumination_LedID_SetLevel( int LED_ID, int level );
  int Illumination_LedID_Off( int LED_ID );
  
  int REQUEST_HPHONEBOOK_READSTRING( const int* sync, void* buf );
  void AB_STR_ITEM_Copy( AB_STR_ITEM* dest, AB_STR_ITEM* source );
  int Request_SIM_IMSI_Read(const int* sync, const int unk, char* imsi, char* error_cause );
  int get_imsi_const( void );
  int Request_SL_GetRadioState( const int* sync, char* level, char* flag, char* error_cause );
  int Network_INetworkConnection_GetConnectionInfo( CONNECTION_INFO_DESC* desc );
  int GetChipID_int( void );
  OSBOOLEAN get_mem_int( int, int, void* );
  int ConnectionManager_Connection_GetState_int( char* buf );
#endif
  
// DynamicMenu function --------------------------------------------------------
  int DynamicMenu_GetElementMsg( DYNAMIC_MENU_ELEMENT* dme );
  wchar_t* DynamicMenu_GetElementId( DYNAMIC_MENU_ELEMENT* );
  void DynamicMenu_SetElement_FirstLineText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_HelpText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_Icon(DYNAMIC_MENU_ELEMENT* dme, int mode, IMAGEID );
  void DynamicMenu_SetElement_UnavailableState( DYNAMIC_MENU_ELEMENT* dme, BOOL state );
  void DynamicMenu_SetElement_UnavailableText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_SecondLineText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  void DynamicMenu_SetElement_TitleText( DYNAMIC_MENU_ELEMENT* dme, TEXTID );
  
// SoftKeys function -----------------------------------------------------------  
  void BookObj_SoftKeys_SetItemOnKey( BOOK* book, u16 actionID, int key, int mode );
  void BookObj_SoftKeys_SetKey_SoftAction( BOOK* book, u16 actionID, int key, int mode );
  
  void GUIObject_SoftKeys_AllowKeylock( GUI*, BOOL allow );
  void GUIObject_SoftKeys_SetLongSKButtonText( GUI*, u16 actionID, TEXTID );
  void GUIObject_SoftKeys_SetIcon( GUI*, u16 actionID, IMAGEID );
  void GUIObject_SoftKeys_MoveItemAfter( GUI*, u16 actionID, u16 after_actionID );
  void GUIObject_SoftKeys_MoveItemBefore( GUI*, u16 actionID, u16 before_actionID );
  void GUIObject_SoftKeys_MoveItemFirst( GUI*, u16 actionID);
  void GUIObject_SoftKeys_SetDisabledAction( GUI*, u16 actionID, int unk );
  void GUIObject_SoftKeys_SetSubItemHighlight( GUI*, u16 actionID, int subitem );
  void GUIObject_SoftKeys_SetItemOnKey( GUI*, u16 actionID, int key, int mode );
  void GUIObject_SoftKeys_RemoveItemFromKey( GUI*, u16 actionID, int key, int mode );
  void GUIObject_SoftKeys_SetActionAndText( GUI* gui, u16 actionID, SKACTIONPROC proc, TEXTID );
  void GUIObject_SoftKeys_SetAction_SetText_SetInfoText_SetVisible( GUI*, u16 actionID, SKACTIONPROC proc, TEXTID name, TEXTID info, BOOL visible );

  void MediaPlayer_SoftKeys_SetVisible( GUI* player_gui, u16 actionID, BOOL );
  void MediaPlayer_SoftKeys_SetInfoText( GUI* player_gui, u16 actionID, TEXTID );
  void MediaPlayer_SoftKeys_SetEnable( GUI* player_gui, u16 actionID, BOOL);
  void MediaPlayer_SoftKeys_AddErrorStr( GUI* player_gui, u16 actionID, TEXTID );
  
  void DispObject_SoftKeys_SetAction( DISP_OBJ*, BOOK*, int __zero, u16 actionID, SKACTIONPROC );
  void DispObject_SoftKeys_SetIcon( DISP_OBJ*, BOOK*, int __zero, u16 actionID, IMAGEID );
  void DispObject_SoftKeys_SetText( DISP_OBJ*, BOOK*, int __zero, u16 actionID, TEXTID );
  void DispObject_SoftKeys_SetLongSKButtonText( DISP_OBJ*, u16 actionID, TEXTID );
  void DispObject_SoftKeys_SetVisible( DISP_OBJ*, BOOK*, int __zero, u16 actionID, BOOL );
  //
  //
  //
  void DispObject_SoftKeys_AddErrorStr( DISP_OBJ*, BOOK*, int __zero, u16 actionID, TEXTID );
  //
  void DispObject_SoftKeys_MoveItemFirst( DISP_OBJ*, BOOK*, int __zero, u16 actionID);
  void DispObject_SoftKeys_MoveItemBefore( DISP_OBJ*, BOOK*, int __zero, u16 actionID, u16 before_actionID );
  void DispObject_SoftKeys_MoveItemAfter( DISP_OBJ*, BOOK*, int __zero, u16 actionID, u16 after_actionID );
  void DispObject_SoftKeys_SetItemAsSubItem( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int subitem );
  void DispObject_SoftKeys_SetSubItemHighlight( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int subitem );
  void DispObject_SoftKeys_SetItemOnKey( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int key, int mode );
  void DispObject_SoftKeys_RemoveItemFromKey( DISP_OBJ*, BOOK*, int __zero, u16 actionID, int key, int mode );
  void DispObject_SoftKeys_RemoveItem( DISP_OBJ*, BOOK*, int __zero, u16 actionnID );
  void DispObject_SoftKeys_SuppressDefaultAction( DISP_OBJ*, u16 actionID );
  void DispObject_SoftKeys_ExecuteAction( DISP_OBJ*, u16 actionID );
  void DispObject_SoftKeys_IgnoreSoftkeyButton( DISP_OBJ*, u16 );
  void DispObject_SoftKeys_AllowKeylock( DISP_OBJ*, BOOL );
  void DispObject_SoftKeys_Hide( DISP_OBJ* );
  void DispObject_SoftKeys_Show( DISP_OBJ* );
  void DispObject_SoftKeys_RemoveBackground( DISP_OBJ* );
  void DispObject_SoftKeys_RestoreBackground( DISP_OBJ* );
  void DispObject_SoftKeys_SubActionPressedNotification( DISP_OBJ*, BOOK*, int __zero, u16 actionID, BOOL );
  void DispObject_SoftKeys_SetDisabledAction( DISP_OBJ*, int unk);
  
// DISP_OBJ function -----------------------------------------------------------
  
  void ListMenu_DispObject_SetCursorToItem( DISP_OBJ*, int item );
  int ListMenu_DispObject_GetSelectedItem( DISP_OBJ* );
  void ListMenu_DispObject_SetItemCount( DISP_OBJ*, int item_count );
  int ListMenu_DispObject_GetItemCount( DISP_OBJ* );
  void ListMenu_DispObject_SetTexts( DISP_OBJ*, const TEXTID* text, int count );
  void ListMenu_DispObject_SetHotkeyMode( DISP_OBJ*, LISTMENU_HOTKEY_MODE );
  void ListMenu_DispObject_SetNoItemText( DISP_OBJ*, TEXTID str );
  int ListMenu_DispObject_SetItemFirstLineText( DISP_OBJ*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_DispObject_SetHelpText( DISP_OBJ*, u16 Item, u16 unk_FFFF, TEXTID );
  int ListMenu_DispObject_SetItemIcon( DISP_OBJ*, u16 Item, u16 unk_FFFF, int mode, IMAGEID );
  void ListMenu_DispObject_SetItemUnavailableState( DISP_OBJ*, u16 Item, u16 unk_FFFF, char state );
  void ListMenu_DispObject_SetItemUnavailableText( DISP_OBJ*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_Disp_Object_SetItemSecondLineText( DISP_OBJ*, int elem_num, TEXTID );
  
  void DispObject_StatusIndication_SetItemText( DISP_OBJ*, int ID, TEXTID );
  
  void DispObject_SetThemeImage( DISP_OBJ*, int theme_image );
  void DispObject_SetAnimationApp( DISP_OBJ*, char* style );
  int DispObject_GetDisplay( DISP_OBJ* );
  void DispObject_SetStyle( DISP_OBJ*, int style );
  int DispObject_GetStyle( DISP_OBJ* );
  
  void DispObject_SetTitleType( DISP_OBJ*, int type );
  int DispObject_GetTitleType( DISP_OBJ* );
  void DispObject_SetTitleIconHasPriority( DISP_OBJ*, BOOL titleIconHasPrio );
  void DispObject_SetTitleAlignment( DISP_OBJ*, char titleAlignment );
  int DispObject_GetTitleAlignment( DISP_OBJ* );
  
  void DispObject_Backlight( DISP_OBJ*, int mode ); // 0 - on; 1 - off; 2 - blink; 3 - timeout; 4 - restore;
  void DispObject_BacklightBlinkTime( DISP_OBJ*, int time_on, int time_off );
  void DispObject_BacklightRestore( DISP_OBJ* );
  void DispObject_SetInternalBackground( DISP_OBJ*, IMAGEID );
  
  DISP_OBJ* Get_MediaPlayer_DispObject(DISP_OBJ*);
  int DispObject_GetStatusRowHeight( DISP_OBJ* );
  void DispObject_DateInput_MoveCursor( DISP_OBJ*, int offset );
  void DispObject_DateInput_SetDateFormat( DISP_OBJ*, char format );
  void DispObject_DateInput_SetDate( DISP_OBJ*, DATE* );
  void DispObject_TimeInput_SetTime( DISP_OBJ*, TIME*, char* format );
  void DispObject_TimeInput_SetSecEnable( DISP_OBJ*, int state );
  int DispObject_TimeInput_MoveCursor( DISP_OBJ*, int offset );

// GUI function ----------------------------------------------------------------
  GUI* CreateDateInput( BOOK*, int display );
  void DateInput_SetDateFormat( GUI*, char format );
  void DateInput_SetDate( GUI*, DATE* ) ;
  
  GUI* CreatePercentInput( BOOK*, int display );
  void PercentInput_ExecuteOnKey( GUI* PercentInput, void proc(int _unk_0, char value) );
  void PercentInput_SetCurrentPercent( GUI* PercentInput, TEXTID );
  void PercentInput_SetTitleText( GUI* PercentInput, TEXTID );
  void PercentInput_SetRowNumbers( GUI* PercentInput, int row );
  
  GUI* CreateTimeInput( BOOK*, int display );
  void TimeInput_SetTime( GUI*, TIME*, char* time_format );
  void TimeInput_SetEnableSec( GUI*, BOOL );
  
  GUI_LIST* CreateMultiChoiceMenu( BOOK* );
  void MultiChoiceMenu_SetMessage( GUI_LIST*, int offset, TEXTID );
  void MultiChoiceMenu_SetCursorToItem( GUI_LIST*, int item );
  
  GUI* CreateOnOffList( BOOK* book );
  int OnOffList_GetSelected( GUI* OnOffList );
  void OnOffList_SetChecked( GUI*, int checked );
  void OnOffList_SetFirstText( GUI* OnOffList, TEXTID );
  void OnOffList_SetSecondText( GUI* OnOffList, TEXTID );
  
  void Feedback_SetIcon( GUI_FEEDBACK*, IMAGEID );
  void Feedback_CloseAction( GUI_FEEDBACK*, u16 actionID );
  void Feedback_SetTextAlignment( GUI_FEEDBACK*, int UITextAlignment_t );
  void Feedback_SetDescriptionImage( GUI_FEEDBACK*, IMAGEID );
  
  void ProgressBar_SetDescriptionIcon( GUI*, IMAGEID );
  void ProgressBar_SetDescriptionIconOffset( GUI*, int offset);
  int ProgressBar_IsScrolling( GUI* );
  
  GUI* CreateYesNoQuestion( BOOK* book, int display );
  void YesNoQuestion_SetQuestionText( GUI*, TEXTID );
  void YesNoQuestion_SetDescriptionText( GUI*, TEXTID );
  void YesNoQuestion_SetDescriptionIconOffset( GUI*, int offset );
  
  void OneOfMany_SetInfoText( GUI_ONEOFMANY*, u16 actionID, u16 unk_FFFF, TEXTID );  
  int NOfMany_GetItemCount( GUI_NOFMANY* );
  void NOfMany_SetItemCount( GUI_NOFMANY*, int count );
  void NOfMany_ItemGetChecked( GUI_NOFMANY*, int item );
  
  GUI* CreateStringInput( BOOK* book );
  void StringInput_SetMode( GUI*, int mode);
  void StringInput_SetActionOK( GUI* strinp, void (*proc)( BOOK* book, wchar_t* string, int len ) );
  void StringInput_SetActionBack( GUI* strinp, void (*proc)( BOOK* book, wchar_t* string, int len ) );
  void StringInput_SetActionCancel( GUI* strinp, void (*proc)( BOOK* book, wchar_t* string, int len ) );
  void StringInput_SetText( GUI* strinp, TEXTID );
  void StringInput_SetFixedText( GUI* strinp, TEXTID );
  void StringInput_SetMinLen( GUI* strinp, int len );
  void StringInput_SetMaxLen( GUI* strinp, int len );
  void StringInput_SetEnableEmptyText( GUI* strinp, BOOL state );
  void StringInput_DispObject_StartSelectedText( DISP_OBJ* strinp_dispobj );
  void StringInput_DispObject_CopySelectedText( DISP_OBJ* strinp_dispobj );
  
  int ListMenu_SetFirstLineText( GUI_LIST*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_SetInfoText( GUI_LIST*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_SetItemUnavailableState( GUI_LIST*, u16 Item, u16 unk_FFFF, char state );
  void ListMenu_SetItemUnavailableText( GUI_LIST*, u16 Item, u16 unk_FFFF, TEXTID );
  void ListMenu_SetTexts( GUI_LIST*, TEXTID* textids, int Count );
  void ListMenu_Activate_AddCount( GUI_LIST*, int mode );
  void ListMenu_SetMaxItemCount( GUI_LIST*, int count );
  void ListMenu_ErrorAddCount( GUI_LIST*, TEXTID );
  
  void GUIObject_TabTitleRemove( GUI*, BOOL );
  void GUIObject_SetAnimationApp( GUI*, char* style );
  void GUIObject_RefreshLayout( GUI* );
  int GUIObject_GetDisplay( GUI* );
  int GUIObject_GetStyle( GUI* );
  int GUIObject_GetTitleType( GUI* );
  void GUIObject_SetTitleIconHasPriority( GUI*, BOOL titleIconHasPrio );
  void GUIObject_SetTitleAlignment( GUI*, char titleAlignment );
  int GUIObject_GetTitleAlignment( GUI* );
  void GUIObject_BacklightOn( GUI* );
  void GUIObject_BacklightOff( GUI* );
  void GUIObject_BacklightTimeout( GUI* );
  void GUIObject_BacklightBlink( GUI* );
  void GUIObject_BacklightBlinkTime( GUI*, int time_on, int time_off );
  void GUIObject_BacklightRestore( GUI* );
  void GUIObject_SetInternalBackground( GUI*, IMAGEID );
  
  GUI* CreatePalette( BOOK* book, TEXTID title, const unsigned int *color, int num_of_color, char __zero, void (*onCancel)( BOOK*, void* ), void (*onBack)( BOOK*, void* ), void (*onSelect)( BOOK*, unsigned int color) );

  // BOOK function ---------------------------------------------------------------
  BOOL IsBook_onTop( BOOK* book );
  void* BOOK_SetFocus( UI_APP_SESSION* session, int focus );
  BOOK* GetTopBook( void );
  int IsStandbyTickerBook( BOOK* book );
  IS_NEEDED_BOOK get_IsStandbyTickerBook( void );
  
  int IsTimerBook( BOOK* book );
  IS_NEEDED_BOOK get_IsTimerBook( void );
  
  void FreeAllBook(BOOK* book, GUI* gui);
  void Free_RightNowBook(void);
  
  BOOK* DynamicMenu_GetElementBook( DYNAMIC_MENU_ELEMENT* );
  BOOK* DynamicMenu_CreateSetBook( void );
  BOOK* DynamicMenu_CreateXSetBook( int minus_one );

// SUB_EXECUTE function --------------------------------------------------------
  FILEITEM* SUB_EXECUTE_Get_FILEITEM( SUB_EXECUTE* );
  wchar_t* FILEITEM_GetFExtension( FILEITEM* );
  FSTAT* FILEITEM_GetFSTAT( FILEITEM* );
  void* FILEITEM_GetDRMHandle( FILEITEM* );
  char FILEITEM_GetDRM_Flag( FILEITEM* );
  char* FILEITEM_GetContentType( FILEITEM* );
  int FILEITEM_SetContentType( FILEITEM*, char* type );
  int GetFileLocation( wchar_t* fullpath ); // 0 - card, 1 - phone
  int GetMemoryStickStatus( void );
  int DataBrowser_ItemDesc_CheckFileToCopyMove( FILEITEM* );
  
  int FSX_IsFileExists( wchar_t* pDir, wchar_t* pFile );
  wchar_t* FSX_MakeFullPath( wchar_t* pDir, wchar_t* pFile );
  void FSX_FreeFullPath( wchar_t* fullpath );
  int FSX_Attribute( const wchar_t* pDir, const wchar_t* pFile, unsigned long* pAttr, int action );
  wchar_t* MakeFullPath( wchar_t* pDir, wchar_t* pFile );
  
// other function --------------------------------------------------------------
  
  int CallInfo_Get(const int *SYNC, int CallType, CALLINFO*, signed char *error);
  
  void CreateQuickInfo( DISP_OBJ* dispobj, TEXTID, int unk);
  void CreatePasswordInputWindow(int BookID, int mode_0, int password_2, TEXTID title ); // password: 2 - phone
  
  void SaveBrightness( int brightness_level );
  void Generic_DRM_Info( wchar_t* path, wchar_t* name, int BookID );
  
  int Image_SetWallpaper(const wchar_t* path, const wchar_t* fname );
  
  int SETTING_RINGTYPESOUNDFILE_SET( const int* sync, int minus_one, char zero, wchar_t* path, wchar_t* name, char* error );
  int Sound_Check(wchar_t* fname);
  int Sound_SetRingsignal( wchar_t* fpath, wchar_t* fname );
  int Sound_SetMessageAlert( wchar_t* fpath, wchar_t* fname );
  void Sound_SetAlarmsignal( BOOK* book, int one, wchar_t* fpath, wchar_t* fname );
  void Sound_AddToContact( int BookID, wchar_t* fpath, int len_path, wchar_t* fname, int len_name, int zero ); 
  
  wchar_t* MetaData_GetTags( wchar_t* path, wchar_t* name, int tagID );
  IMAGEID MetaData_GetCover( wchar_t* filename );
  
  int MusicApp_GetFocusedItem( BOOK* MusicBook, int itemIndex, int length, \
                                 wchar_t* pArtist, wchar_t* pAlbum, wchar_t* pTitle, \
                                   wchar_t* pFilename, \
                                     void* pPlaylength, void* pResumePosition, \
                                       bool* pContainsAlbumart, bool* pIsRealMediaFile );
  int MusicApp_GetItem( BOOK* MusicBook, int itemIndex, int length, wchar_t* pArtist, wchar_t* pAlbum, wchar_t* pTitle );
  int MusicApp_GetFilename( BOOK* MusicBook, int itemIndex, int length, wchar_t* pFilename );
  int MusicApp_Resume( BOOK* MusicBook );
  int MusicApp_Play( BOOK* MusicBook );
  int MusicApp_Pause( BOOK* MusicBook );
  int MusicApp_FastFoward( BOOK* MusicBook );
  int MusicApp_Rewind( BOOK* MusicBook );
  int MusicServer_Next( BOOK* MusicBook, bool activePress );
  int MusicApp_Previous( BOOK* MusicBook );
  int MusicServer_RemoveFromPlaylist( BOOK* MusicBook, int itemIndex );
  int MusicServer_SavePlayQueue( BOOK* MusicBook, wchar_t* pPlaylistName );
  int MusicApp_SetApplicationWindowMode( BOOK* MusicBook, bool maximized );

  void Volume_Set( int TAudioControl_VolumeType, char volume );
  int Volume_Get( int TAudioControl_VolumeType, char* volume ); // GetAudioSettings
  
  void MessageBox_Animation( TEXTID header_text, TEXTID message_text, IMAGEID, int style, int time, BOOK* book, char* animation );
  void CreateToast( TEXTID header_text, TEXTID message_text, int style, int time, BOOK* book );
  
  //int Get_MediaPlayer_State( DISP_OBJ* );
  void PlaySystemSound_SendEvent(int sound, int event); 
  TEXTID TextID_CreateFromASCII( int );
  
  void OnOffBook_ShuttingDown( void );
  void Shutdown( void );
  void Reboot( void );
  void Keylock_Activate( void );
  BOOL Charging_GetState( void );
  int NewEvent_GetCount( void ); //GetNewEvent(void);
  
  BOOL FlightMode_GetState( void );
  void FlightMode_SetState( BOOL state );
  void Bluetooth_SetState( BOOL state );
  void SetOperatorName( TEXTID, int _null );
  TEXTID GetOperatorName( wchar_t* opname  );
  
  void MSG_Marked_No( BOOK* book); //Защита от удаления сообщений, v. 3
  void Create_BrowserMemory( int BookID, int unk, int mode ); // Отображение свободной памяти в заголовках вкладок Диспетчера файлов, v. 4
  void DataDownloadBook_onClose( BOOK* book ); // Добавить вопрос о замене файла после приема через Bluetooth
 
// LIST function ---------------------------------------------------------------
  void List_Init( LIST* list );
  void List_Erase( LIST* list );
  int List_InsertLast( LIST* lst, void* item );
  int List_InsertBefore( LIST* list, void* pElem, int itemno );
  int List_InsertAfter( LIST* list, void* pElem, int itemno );
  void* List_RemoveFirst( LIST* lst );
  void* List_RemoveLast( LIST* lst );
  int List_GetCount( LIST* );
  void* List_GetFirst( LIST* list );
  void* List_GetLast( LIST* list );
  void* List_FindNext( LIST* list, void* pElem );
  void* List_FindPrev( LIST* list, void* pElem );
  int List_Last( LIST* list );
  int List_Next( LIST* list, int itemno );
  
  // Registry function ----------------------------------------------------
  void Registry_Write( char* name, int type, int size, void* data );
  void Registry_Read( char* name, int type, int size, void* data );
  
  // String function ----------------------------------------------------
  BOOL IsAlnum(char c);
  BOOL IsAlpha(char c);
  BOOL IsCntrl(char c);
  BOOL IsLower(char c);
  BOOL IsPunct(char c);
  BOOL IsSpace(char c);
  BOOL IsUpper(char c);
  BOOL IsGraph(char c);
  
  char ToLower(char c);
  char ToUpper(char c);
  
  // Socket function ----------------------------------------------------
  int socket_create(int domain, int type, int protocol);
  int socket_close( int sock );
  int socket_connect(int socket, sockaddr *address, int address_len);
  int socket_send(int socket, const void *message, int length, int flags);
  int socket_recv(int socket, void *buffer, size_t length, int flags);
  int socket_setsockopt(int socket, int level, int option_name, const void *option_value, int option_len);
  int socket_getsockopt(int socket, int level, int option_name, void *option_value, int *option_len);
  int socket_getpeername(int socket, sockaddr *address, int *address_len);
  int socket_getsockname(int socket, sockaddr *address, int *address_len);
  int socket_shutdown(int socket, int how);
  int socket_accept(int socket, sockaddr *address, int *address_len);
  int socket_bind(int socket, const sockaddr *address, int address_len);
  int socket_listen(int socket, int backlog);
  int socket_sendto(int socket, const void *message, int length, int flags, const sockaddr *dest_addr, int dest_len);
  int socket_recvfrom(int socket, void *buffer, int length, int flags, sockaddr *address, int *address_len);
  int socket_sendmsg(int socket, const struct msghdr *message, int flags);
  int socket_recvmsg(int socket, struct msghdr *message, int flags);
  int socket_select( int nfds, void* readfds, void* writefds, void* exceptfds, void* timeout);
  int fcntl( int fd, int cmd, long arg );
  int socket_lasterror( void );
  int inet_pton(int af, const char *src, void *dst);
  char *inet_ntop(int af, const void *src, char *dst, int size);

};
