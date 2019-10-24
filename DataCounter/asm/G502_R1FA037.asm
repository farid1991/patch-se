#ifdef G502_R1FA037

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr TextID_CreateIntegerID_int,0x1168426C+1
        defadr TextID_Create_int,0x1168442C+1
        defadr TextID_CreateASCII,0x11684264+1
//////////

	EXTERN new_int2strID

        org 0x10F41218
        CODE16
	STR     R7, [R0,#0x14] // remove bytes[last sent]
        
        org 0x10F4124A
        CODE16
	STR     R7, [R0,#0x2C] // remove bytes[last recv]

        org 0x10F412E6
        CODE16
	STR     R7, [R0,#0x64] // remove bytes[all sent]
        
        org 0x10F41318
        CODE16
	STR     R7, [R0,#0x7C] // remove bytes[all recv]
        
        RSEG	PATCH_LASTSESSION_SENT
	LDR	R3, =last_session_sent
	BX	R3
        
        RSEG	PATCH_LASTSESSION_RECV
        CODE16
	LDR	R3, =last_session_recv
	BX	R3
        
        
        RSEG	PATCH_ALLSESSION_SENT
        CODE16
	LDR	R3, =all_session_sent
	BX	R3

        RSEG	PATCH_ALLSESSION_RECV
        CODE16
	LDR	R3, =all_session_recv
	BX	R3
        
	RSEG	CODE
        CODE16              
last_session_sent:
	STR     R5, [R6,#4]
	MOV     R2, #0
	ADD     R1, R2, #0
        BL      new_int2strID
	ADD	R1, SP,	#0x20
        LDR     R3, =0x10F4120A+1
        BX      R3
        
last_session_recv:
	STR     R5, [R0,#0x20]
	LDR     R0, [SP,#0x18]
	MOV     R2, #0
	ADD     R1, R2, #0
        BL      new_int2strID
	ADD	R1, SP,	#0x20
        LDR     R3, =0x10F4123C+1
        BX      R3
        
all_session_sent:
	STR     R5, [R0,#0x58]
	LDR     R0, [SP,#0x14]
	MOV     R2, #0
	ADD     R1, R2, #0
        BL      new_int2strID
	ADD	R1, SP,	#0x20
        LDR     R3, =0x10F412D8+1
        BX      R3

all_session_recv:
	LDR     R0, [SP,#0x18]
	MOV     R2, #0
	ADD     R1, R2, #0
        BL      new_int2strID
	ADD	R1, SP,	#0x20
        LDR     R3, =0x10F4130A+1
        BX      R3
  
#endif

        END
