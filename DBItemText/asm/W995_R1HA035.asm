//W995_R1HA035

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr w_fstat,0x100B31C8+1
        defadr w_chdir,0x4BA80C30
        defadr w_diropen,0x4BA33934
        defadr w_dirread,0x1409E128+1
        defadr w_dirclose,0x4BA80C10
        defadr TextID_Create,0x142D8380+1
        defadr TextID_CreateIntegerID,0x143D6484+1
        defadr TextID_CreateCharacterID,0x143D684C+1

        EXTERN SetSecondlineItemText

        RSEG PATCH_SECONDLINE_FM
        CODE16
	LDR	R3, =SetItemSecondlineText
	BX	R3

        RSEG CODE
        CODE16
SetItemSecondlineText:
        ADD     R0, R5, #0
        ADD     R1, R6, #0
        BL      SetSecondlineItemText
        STR     R0, [R4,#0]
	LDR	R3, =0x14EEA762+1
	BX	R3

        END
