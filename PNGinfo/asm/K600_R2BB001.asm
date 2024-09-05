//K600_R2BB001
#include "target.h"

defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr memalloc,0x20363C0C+1
        defadr memfree,0x20364D24+1
        defadr memset,0x20D66768+1
        defadr memcpy,0x200A5000
        defadr debug_printf,0x20D28E84+1
        defadr sprintf,0x20D672A0+1
        defadr snwprintf,0x20D67990+1
        defadr swscanf,0x20D679EC+1
        defadr current_process,0x200A405C
        defadr get_bid,0x200A4094
        defadr set_envp,0x2006CF5E+1
        defadr get_envp,0x2006CF4A+1
        defadr strcat,0x20D676D4+1
        defadr strncat,0x20D67788+1
        defadr strcmp,0x20D67710+1
        defadr strcpy,0x20D67740+1
        defadr strlen,0x20D67778+1
        defadr strncpy,0x20D677EC+1
        defadr strncmp,0x20D677B0+1
        defadr strstr,0x20D67888+1
        defadr str2wstr,0x206105B4+1
        defadr wstrcat,0x2060F208+1
        defadr wstrlen,0x2060F0E4+1
        defadr wstrcpy,0x2060F160+1
        defadr wstrcmpi,0x20610854+1
        defadr wstrcmp,0x2060F110+1
        defadr wstrncpy,0x2060F1A8+1
        defadr wstrrchr,0x206106CC+1
        defadr wstrncmp,0x20610640+1
        defadr wstrwstr,0x20D68178+1
        defadr wstr2strn,0x2060F348+1
        defadr _fopen,0x204DBDF4+1
        defadr fread,0x204DD2F0+1
        defadr fclose,0x204DCFD4+1
        defadr fwrite,0x204DD58C+1
        defadr fstat,0x204DC6B4+1
        defadr List_Create,0x20231DF0+1
        defadr List_InsertFirst,0x20231F34+1
        defadr List_InsertLast,0x20231F44+1
        defadr List_GetCount,0x2023209C+1
        defadr List_Get,0x202320C4+1
        defadr List_Destroy,0x20231E14+1
        defadr List_DestroyElements,0x2023223C+1

        defadr TextID_Create,0x202CFF38+1
        defadr FILEITEM_GetPath,0x204F0EA4+1
        defadr FILEITEM_GetFname,0x204F0DBC+1

        defadr png_create_read_struct_2,0x209BF2C4+1
        defadr png_create_info_struct,0x209BC568+1
        defadr png_destroy_read_struct,0x209BFC14+1
        defadr png_get_io_ptr,0x209BC64C+1
        defadr png_get_IHDR,0x209BF0A4+1
        defadr png_read_info,0x209BF54C+1
        defadr png_set_read_fn,0x209BFD64+1

        EXTERN  patch_brw_png_info

        RSEG PATCH_BRWITEM_PNG
        CODE16
        LDR     R3, =brw_png_info
        BX      R3

        RSEG CODE
        CODE16
brw_png_info:
        MOV     R2, #6
        MOV     R1, #5
        MOV	R0, SP
        BL      _TextID_Create
        ADD     R1, R4, #0
        BL	patch_brw_png_info
        STR     R0, [R5,#0]
        MOV     R0, #0
        ADD     SP, #0x18
        POP     {R4-R6,PC}

_TextID_Create:
        PUSH	{R3}
        LDR	R3, =TextID_Create
        MOV	R12, R3
        POP	{R3}
        BX	R12
        NOP

        END
