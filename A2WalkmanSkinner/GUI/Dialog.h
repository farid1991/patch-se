#ifndef _DIALOG_H_
#define _DIALOG_H_

static const char Gui_Dialog[] = "Gui_Dialog";

typedef struct GUI GUI_Dialog;

typedef struct _DISP_OBJ_DIALOG : DISP_OBJ
{
  TEXTID title_text;
  TEXTID dialog_text;
} DISP_OBJ_DIALOG;

GUI_Dialog *CreateDialog(BOOK *book);
void Dialog_SetTitleText(GUI_Dialog *dialog, TEXTID title_text);
void Dialog_SetDialogText(GUI_Dialog *dialog, TEXTID dialog_text);

#endif
