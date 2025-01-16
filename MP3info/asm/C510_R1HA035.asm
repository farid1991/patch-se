// C510_R1HA035

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x4BA32698
        defadr memfree,0x4BA326C0
        defadr memset,0x14B31C80
        defadr memcpy,0x1428AD94
        defadr memcmp,0x4BA32F18
        defadr debug_printf,0x14B49D0C
        defadr sprintf,0x14405D14+1
        defadr snprintf,0x14087354+1
        defadr snwprintf,0x143EEBC4+1
        defadr strlen,0x14C0BAD4+1
        defadr strncmp,0x141C7A0C+1
        defadr strcpy,0x14C0BAA0+1
        defadr strncpy,0x1016F370+1
        defadr strcat,0x1000188C+1
        defadr strncat,0x100AACAC+1
        defadr str2wstr,0x141C9A44+1
        defadr wstrcpy,0x144D851C+1
        defadr wstrncpy,0x143EEBF8+1
        defadr wstrcat,0x144D8474+1
        defadr wstrncat,0x14178F90+1
        defadr wstrcmp,0x144D9600+1
        defadr wstrlen,0x14178EC8+1

        defadr _fopen,0x141FA214+1
        defadr fclose,0x143CD0A0+1
        defadr fread,0x14178B8C+1
        defadr fwrite,0x143326C8+1
        defadr fstat,0x144D8BBC+1
        defadr lseek,0x141782E0+1
        defadr FILEITEM_GetFname,0x142C7D74+1
        defadr FILEITEM_GetPath,0x142C7CA0+1
        defadr TextID_Create,0x141818E4+1

        defadr List_Create,0x1430E0E0+1
        defadr List_Get,0x140CC3EC+1
        defadr List_InsertFirst,0x1430E4B0+1
        defadr List_InsertLast,0x1417A03C+1
        defadr List_Destroy,0x1430E244+1
        defadr List_DestroyElements,0x140EF194+1


        EXTERN  patch_brw_mp3info

        RSEG PATCH_BRWITEM_MP3
        CODE16
        LDR     R3, =brw_mp3_info
        BX      R3

        RSEG CODE
        CODE16
brw_mp3_info:
        MOV     R2, #6
        MOV     R1, #5
        ADD	R0, SP,	#8
        BL      _TextID_Create
        ADD     R1, R4, #0
        BL	patch_brw_mp3info
        STR     R0, [R5,#0]
        MOV     R0, #0
        ADD     SP, #0x20
        POP     {R4-R7,PC}

_TextID_Create:
        PUSH	{R3}
        LDR	R3, =TextID_Create
        MOV	R12, R3
        POP	{R3}
        BX	R12
        NOP

        END
