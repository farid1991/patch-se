//S700_R3M008

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr _fopen,0x44E44784+1
        defadr fclose,0x44E44FF0+1
        defadr fread,0x44E4460C+1
        defadr fwrite,0x44E44568+1
        defadr fstat,0x44E45164+1
        defadr destroy_bookobj,0x44AD2830+1
        defadr OneOfMany_GetSelected,0x448FF6DC+1
        defadr REQUEST_SETTING_KEYSOUND_SET,0x44E8297C+1
        defadr PlayFile,0x448D9CA4+1
        defadr PlayFileV,0x448D9D5C+1
        defadr default_key_handler,0x44AA1D90+1

        EXTERN new_key_sound
        EXTERN get_keysound_id
        EXTERN get_keysound_txt
        EXTERN new_checkbox_act
        EXTERN TEXT_LABEL

        ORG 0x448F02CA
        CODE16
        MOV     R1, #3

        RSEG KEYPRESS_PATCH
        DATA
        DCD     new_key_sound

        RSEG GUILIST_PATCH
        DATA
        DCD     TEXT_LABEL

        RSEG GUIACTION_PATCH
        DATA
        DCD     new_checkbox_act

        RSEG    KEYSOUND_PATCH
        CODE16
        LDR	R3, =new_checkbox
        BX	R3

        RSEG  CODE
        CODE16
new_checkbox:
        BL	get_keysound_id
        MOV     R6, #0
        ADD     R6, R0, #0
        LDR     R3, =0x448F02B8+1
        BX      R3

        RSEG    MENULIST_PATCH
        CODE16
        LDR	R3, =new_menulist
        BX	R3

        RSEG  CODE
        CODE16
new_menulist:
        BL	get_keysound_txt
	STR	R0, [SP,#0]
	LDR	R1, [SP,#0]
        LDR     R3, =0x44AD1D54+1
        BX      R3

        END
