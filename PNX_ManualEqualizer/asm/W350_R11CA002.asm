//W350_R11CA002


defadr MACRO a,b
        PUBLIC  a
a       equ b
        ENDM

        defadr GUIObject_SoftKeys_SetVisible,0x211209CC+1
        defadr GUIObject_GetBook,0x21103F4C+1

        EXTERN  New_EQ_SetActive_SoftKeys

        RSEG    PATCH_EQ_SOFTKEYS
        CODE16
        LDR     R3, =New_EQ_SetActive_SoftKeys
        BX      R3

        END
