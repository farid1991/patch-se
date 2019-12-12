#ifndef _UIFOTA_BOOK_H_
#define _UIFOTA_BOOK_H_


typedef struct _ui_fota_bk : BOOK
{
	char dummy_0[0x4];
	GUI* menu;
	char dummy_1[0x8];
	int item;
}ui_fota_bk;

#endif
	