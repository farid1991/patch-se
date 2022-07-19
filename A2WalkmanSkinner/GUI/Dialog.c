#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\Color.h"

#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"

#include "Dialog.h"
#include "SelectFont.h"

//==============================================================================

int Dialog_OnCreate(DISP_OBJ_DIALOG *disp_obj)
{
  disp_obj->title_text = EMPTY_TEXTID;
  disp_obj->dialog_text = EMPTY_TEXTID;
  return 1;
}

void Dialog_OnClose(DISP_OBJ_DIALOG *disp_obj)
{
  DESTROY_TEXTID(disp_obj->title_text);
  DESTROY_TEXTID(disp_obj->dialog_text);
}

void Dialog_OnRedraw(DISP_OBJ_DIALOG *disp_obj, int r1, int r2, int r3)
{
  /*--------------------------------------------------------------------------*/

  int dialog_h = FONT_HEIGHT(FONT_E_18R) + 16 + 16;
  int dialog_y = 298 - dialog_h;
  DrawString_onRect(FONT_E_18R,
                    disp_obj->dialog_text,
                    clBlue2,
                    0, dialog_y, 240, dialog_h,
                    clBackgroundPlus);

  /*--------------------------------------------------------------------------*/
  int title_h = 40;
  int title_y = dialog_y - title_h;
  DrawString_onRect(FONT_E_20R,
                    disp_obj->title_text,
                    clAlpha,
                    0, title_y, 240, title_h,
                    clBlue2Dark);

  /*--------------------------------------------------------------------------*/
}

void Dialog_OnKey(DISP_OBJ_DIALOG *disp_obj, int key, int count, int repeat, int mode)
{
}

void Dialog_OnLayout(DISP_OBJ_DIALOG *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, clEmpty);
}

void Dialog_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_Dialog);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_DIALOG));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Dialog_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Dialog_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Dialog_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Dialog_OnKey);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)Dialog_OnLayout);
}

void Dialog_destruct(GUI *gui)
{
}

void Dialog_callback(DISP_OBJ* disp, void* msg, GUI* gui)
{
}

void Dialog_SetTitleText(GUI *dialog, TEXTID title_text)
{
  DISP_OBJ_DIALOG *disp_obj = (DISP_OBJ_DIALOG *)GUIObject_GetDispObject(dialog);
  disp_obj->title_text = title_text;
}

void Dialog_SetDialogText(GUI *dialog, TEXTID dialog_text)
{
  DISP_OBJ_DIALOG *disp_obj = (DISP_OBJ_DIALOG *)GUIObject_GetDispObject(dialog);
  disp_obj->dialog_text = dialog_text;
}

GUI *CreateDialog(BOOK *book)
{
  GUI *dialog = (GUI *)malloc(sizeof(GUI));
  if (!GUIObject_Create(dialog, Dialog_destruct, Dialog_construct, book, Dialog_callback, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(dialog);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, dialog);

  GUIObject_SetStyle(dialog, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(dialog, UI_TitleMode_None);
  
  return dialog;
}
