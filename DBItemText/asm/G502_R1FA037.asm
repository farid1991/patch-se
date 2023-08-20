//G502_R1FA037

defadr  MACRO a,b
        PUBLIC a
a       EQU b
        ENDM

        defadr w_fstat,0x107E9FD4+1
        defadr TextID_CreateIntegerID,0x1168426C+1
        defadr TextID_Create,0x1168442C+1

        EXTERN SetSecondlineItemText

        RSEG PATCH_SECONDLINE_FM
        CODE16
	LDR	R3, =SetItemText
	BX	R3

        RSEG CODE
        CODE16
SetItemText:
        ADD     R1, R6, #0
        BL      SetSecondlineItemText
        STR     R0, [R4,#0]
	LDR	R3, =0x11012B84+1
	BX	R3

        END
