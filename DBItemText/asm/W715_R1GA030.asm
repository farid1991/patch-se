//W715_R1GA030

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr w_fstat,0x100B2D70+1
        defadr w_chdir,0x4BA80C30
        defadr w_diropen,0x4BA3284C
        defadr w_dirread,0x142ECFDC+1
        defadr w_dirclose,0x4BA80C10
        defadr TextID_Create,0x14184D2C+1
        defadr TextID_CreateIntegerID,0x1401F994+1
        defadr TextID_CreateCharacterID,0x14020084+1

        EXTERN SetSecondlineItemText

        RSEG PATCH_SECONDLINE_FM
        CODE16
	LDR	R3, =SetItemText
	BX	R3

        RSEG CODE
        CODE16
SetItemText:
        ADD     R0, R5, #0
        ADD     R1, R6, #0
        BL      SetSecondlineItemText
        STR     R0, [R4,#0]
	LDR	R3, =0x15855730+1
	BX	R3

        END
