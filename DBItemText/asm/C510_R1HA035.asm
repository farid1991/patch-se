//C510_R1HA035

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr w_fstat,0x100A6EA0+1
        defadr w_chdir,0x4BA80C30
        defadr w_diropen,0x4BA32468
        defadr w_dirread,0x142E855C+1
        defadr w_dirclose,0x4BA80C10
        defadr TextID_Create,0x141818E4+1
        defadr TextID_CreateIntegerID,0x1401F5BC+1
        defadr TextID_CreateCharacterID,0x1401FD18+1

        EXTERN db_set_secondline_text

        RSEG PATCH_SECONDLINE_FM
        CODE16
	LDR	R3, =SetItemSecondlineText
	BX	R3

        RSEG CODE
        CODE16
SetItemSecondlineText:
        ADD     R0, R5, #0
        ADD     R1, R6, #0
        BL      db_set_secondline_text
        STR     R0, [R4,#0]
	LDR	R3, =0x1574717A+1
	BX	R3

        END
