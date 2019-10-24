extern "C"
{
 void oldRedrawStatus(DISP_OBJ*,int a,int b,int c);
 void oldRedrawDisplay(DISP_OBJ*,int a,int b,int c);
 void oldRedrawSoft(DISP_OBJ*,int a,int b,int c);
 int oldCreateDisplay(DISP_OBJ *);
 void oldCloseDisplay(DISP_OBJ *dobj);
 void oldOnKeyMainInput( DISP_OBJ* db, int key, int unk, int repeat, int type );

 int GetCurName();
 int CallInfo_Get( const int *SYNC,int CallType, CALLINFO* ,signed char *error );
 IS_NEEDED_BOOK isTimerBook( void );
 void GetTimerTime(TIME*);
};
