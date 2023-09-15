#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"

#include "..\\Colors.h"
#include "..\\dll.h"
#include "..\\Draw.h"
#include "..\\main.h"

#include "Dialog.h"
#include "SelectFont.h"

//==============================================================================

int Get_Font_Height(int font)
{
#if defined(DB3200) || defined(DB3210)
  return (font & 0xFF);
#else
  SetFont(font);
  return GetImageHeight(' ');
#endif
}

int Dialog_OnCreate(DISP_OBJ_DIALOG *disp_obj)
{
  disp_obj->title_text = EMPTY_TEXTID;
  disp_obj->dialog_text = EMPTY_TEXTID;

  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main) - softkeys_h - status_h;
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

  u16 dialog_h = (Get_Font_Height(FONT_E_18R) << 1) + (Get_Font_Height(FONT_E_18R) >> 1);
  u16 dialog_y = disp_obj->disp_height - dialog_h;
  DrawTextOnRect(FONT_E_18R,
                 disp_obj->dialog_text,
                 0, dialog_y, disp_obj->disp_width, dialog_h,
                 TITLE_TEXT_COLOR,
                 TITLE_BACKGROUND_COLOR);

  /*--------------------------------------------------------------------------*/

  u16 title_h = Get_Font_Height(FONT_E_20B) + (Get_Font_Height(FONT_E_20B) >> 1);
  u16 title_y = dialog_y - title_h;
  DrawTextOnRect(FONT_E_20B,
                 disp_obj->title_text,
                 0, title_y, disp_obj->disp_width, title_h,
                 DARK_TEXT_COLOR,
                 DARK_BACKGROUND_COLOR);

  /*--------------------------------------------------------------------------*/
}

void Dialog_OnKey(DISP_OBJ_DIALOG *disp_obj, int key, int count, int repeat, int mode)
{
}

void Dialog_OnLayout(DISP_OBJ_DIALOG *disp_obj, void *layoutstruct)
{
  DispObject_SetLayerColor(disp_obj, TRANSPARENT_COLOR);
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

void Dialog_callback(DISP_OBJ *disp, void *msg, GUI *gui)
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

  GUIObject_SetStyle(dialog, UI_OverlayStyle_Default);
  GUIObject_SetTitleType(dialog, UI_TitleMode_None);

  return dialog;
}
