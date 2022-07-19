#include "..\\temp\target.h"

#include "..\\..\\include\Types.h"
#include "..\\..\\include\Function.h"
#include "..\\..\\include\Color.h"

#include "..\\Draw.h"
#include "..\\main.h"
#include "..\\Function.h"
#include "..\\SaveLoad.h"

#include "EditCoordinates.h"

//==============================================================================

void DrawOwnRect(int _x1, int _y1, int _x2, int _y2, int pen_color, int brush_color)
{
  int x1, x2, y1, y2;

  x1 = MIN(_x1, _x2);
  x2 = MAX(_x1, _x2);
  y1 = MIN(_y1, _y2);
  y2 = MAX(_y1, _y2);

  if (y1 == y2 || x1 == x2)
  {
    GC *gc = get_DisplayGC();
    GC_SetPenColor(gc, pen_color);
    GC_SetBrushColor(gc, brush_color);
    GC_DrawLine(gc, x1, y1, x2, y2);
  }
  else
    DrawRect(x1, y1, x2, y2, pen_color, brush_color);
}

void DrawArrow(int x, int y, int color)
{
  DrawOwnRect(x, y, x + 13, y + 2, clBlack, clBlack);
  DrawOwnRect(x + 11, y + 2, x + 13, y + 6, clBlack, clBlack);
  DrawOwnRect(x + 8, y + 5, x + 16, y + 6, clBlack, clBlack);
  DrawOwnRect(x + 9, y + 6, x + 15, y + 7, clBlack, clBlack);
  DrawOwnRect(x + 10, y + 7, x + 14, y + 8, clBlack, clBlack);
  DrawOwnRect(x + 11, y + 8, x + 13, y + 9, clBlack, clBlack);
};

int EditCoordinates_OnCreate(DISP_OBJ_COORD *disp_obj)
{
  disp_obj->str_id = EMPTY_TEXTID;
  disp_obj->need_str = TRUE;
  disp_obj->is_first_set = FALSE;
  disp_obj->cstep = 1;
  disp_obj->disp_width = Display_GetWidth(UIDisplay_Main);
  disp_obj->disp_height = Display_GetHeight(UIDisplay_Main);
  return 1;
}

void EditCoordinates_OnClose(DISP_OBJ_COORD *disp_obj)
{
  DESTROY_TEXTID(disp_obj->str_id);
}

void EditCoordinates_OnRedraw(DISP_OBJ_COORD *disp_obj, int a, int b, int c)
{
  RECT rc_old, rc_new;
  int gc_xx;

  int font = FONT_E_20R;
  int fsize = 20;

  int colors[4] = {clRed, clGreen, clBlue, clEta};

  GC *pGC = get_DisplayGC();
  wchar_t ustr[32];
  int old_pen;

  GC_GetRect(pGC, &rc_old);
  gc_xx = GC_GetXX(pGC);
  GC_SetXX(pGC, 1);

  rc_new.x1 = 0;
  rc_new.x2 = disp_obj->disp_width;
  rc_new.y1 = 0;
  rc_new.y2 = disp_obj->disp_height;
  GC_ValidateRect(pGC, &rc_new);
#if defined(DB3150v1) || defined(DB3150v2)
  int font_old = SetFont(font);
#endif
  DrawRect(0, 0, disp_obj->disp_width, disp_obj->disp_height, clWhite, clWhite);

  old_pen = GC_GetPenColor(pGC);
  GC_SetPenColor(pGC, colors[3]);

  for (int y_0 = 0; y_0 < disp_obj->disp_height; y_0 += 10)
  {
    GC_DrawLine(pGC, 0, y_0, disp_obj->disp_width, y_0);
  }

  for (int x_0 = 0; x_0 < disp_obj->disp_width; x_0 += 10)
  {
    GC_DrawLine(pGC, x_0, 0, x_0, disp_obj->disp_height);
  }

  GC_SetPenColor(pGC, old_pen);

  if (disp_obj->type)
  {
    DrawOwnRect(disp_obj->old_rect.x1, disp_obj->old_rect.y1, disp_obj->old_rect.x2, disp_obj->old_rect.y2, clEpsilon, clEmpty);
    if (disp_obj->is_first_set)
    {
      DrawOwnRect(disp_obj->x, disp_obj->y, disp_obj->x2, disp_obj->y2, clBlack, clEmpty);
      if (disp_obj->need_str)
      {
        snwprintf(ustr, MAXELEMS(ustr) - 1, L"%d, %d, %d, %d", disp_obj->x2, disp_obj->y2, disp_obj->x, disp_obj->y);
        TextID_Destroy(disp_obj->str_id);
        disp_obj->str_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
        disp_obj->need_str = FALSE;
      }
    }
    else
    {
      if (disp_obj->need_str)
      {
        snwprintf(ustr, MAXELEMS(ustr) - 1, L"%d, %d, %d, %d", disp_obj->x, disp_obj->y, disp_obj->x2, disp_obj->y2);
        TextID_Destroy(disp_obj->str_id);
        disp_obj->str_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
        disp_obj->need_str = FALSE;
      }
    }
  }
  else
  {
    if (disp_obj->need_str)
    {
      snwprintf(ustr, MAXELEMS(ustr) - 1, L"%d, %d", disp_obj->x, disp_obj->y);
      TextID_Destroy(disp_obj->str_id);
      disp_obj->str_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
      disp_obj->need_str = 0;
    }
  }
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  Draw_String(font,
              disp_obj->str_id,
              AlignLeft,
              3,
              disp_obj->disp_height - fsize - 2,
              disp_obj->disp_width - 4,
              disp_obj->disp_height - 1,
              clBlack);
#else
  SetFont(font);
  DrawString(disp_obj->str_id,
             AlignLeft,
             3,
             disp_obj->disp_height - fsize - 2,
             disp_obj->disp_width - 4,
             disp_obj->disp_height - 1,
             0, 0,
             clBlack, clEmpty);
#endif
  old_pen = GC_GetPenColor(pGC);
  GC_SetPenColor(pGC, clBlack);
  GC_DrawLine(pGC, disp_obj->x - 3, disp_obj->y, disp_obj->x + 3, disp_obj->y);
  GC_DrawLine(pGC, disp_obj->x, disp_obj->y - 3, disp_obj->x, disp_obj->y + 3);

  GUI *gui = DispObject_GetGUI(disp_obj);
  BOOK *book = GUIObject_GetBook(gui);
  char orientation = BookObj_GetDisplayOrientation(book);
  if (orientation == UIDisplayOrientationMode_Vertical)
  {
    DrawArrow(disp_obj->disp_width - 19, disp_obj->disp_height - 13, clBlack);
  }
  else
  {
    DrawArrow(disp_obj->disp_width - 19, 3, clBlack);
  }
  GC_SetPenColor(pGC, old_pen);
  GC_ValidateRect(pGC, &rc_old);
#if defined(DB3150v1) || defined(DB3150v2)
  SetFont(font_old);
#endif
  GC_SetXX(pGC, gc_xx);
}

void EditCoordinates_OnKey(DISP_OBJ_COORD *disp_obj, int key, int unk, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (mode == KBD_SHORT_RELEASE)
      disp_obj->cstep = 1;
    else if (mode == KBD_REPEAT && repeat > 10)
      disp_obj->cstep = 8;

    if (key == KEY_DIGITAL_1)
    {
      if ((disp_obj->x -= disp_obj->cstep) < 0)
        disp_obj->x = 0;
      if ((disp_obj->y -= disp_obj->cstep) < 0)
        disp_obj->y = 0;
    }
    else if (key == KEY_DIGITAL_2 || key == KEY_UP)
    {
      if ((disp_obj->y -= disp_obj->cstep) < 0)
        disp_obj->y = 0;
    }
    else if (key == KEY_DIGITAL_3)
    {
      if ((disp_obj->x += disp_obj->cstep) > disp_obj->disp_width)
        disp_obj->x = disp_obj->disp_width;
      if ((disp_obj->y -= disp_obj->cstep) < 0)
        disp_obj->y = 0;
    }
    else if (key == KEY_DIGITAL_4 || key == KEY_LEFT)
    {
      if ((disp_obj->x -= disp_obj->cstep) < 0)
        disp_obj->x = 0;
    }
    else if (key == KEY_DIGITAL_6 || key == KEY_RIGHT)
    {
      if ((disp_obj->x += disp_obj->cstep) > disp_obj->disp_width)
        disp_obj->x = disp_obj->disp_width;
    }
    else if (key == KEY_DIGITAL_7)
    {
      if ((disp_obj->x -= disp_obj->cstep) < 0)
        disp_obj->x = 0;
      if ((disp_obj->y += disp_obj->cstep) > disp_obj->disp_height)
        disp_obj->y = disp_obj->disp_height;
    }
    else if (key == KEY_DIGITAL_8 || key == KEY_DOWN)
    {
      if ((disp_obj->y += disp_obj->cstep) > disp_obj->disp_height)
        disp_obj->y = disp_obj->disp_height;
    }
    else if (key == KEY_DIGITAL_9)
    {
      if ((disp_obj->x += disp_obj->cstep) > disp_obj->disp_width)
        disp_obj->x = disp_obj->disp_width;
      if ((disp_obj->y += disp_obj->cstep) > disp_obj->disp_height)
        disp_obj->y = disp_obj->disp_height;
    }
    disp_obj->need_str = TRUE;
  }

  if (mode == KBD_LONG_RELEASE)
    disp_obj->cstep = 1;

  InvalidateRect(disp_obj);
}

void EditCoordinates_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_Coordinates);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_COORD));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)EditCoordinates_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)EditCoordinates_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)EditCoordinates_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)EditCoordinates_OnKey);
}

void EditCoordinates_destruct(GUI *gui)
{
}

void EditCoordinates_callback(DISP_OBJ *disp, void *msg, GUI *gui)
{
}

void GUIObject_EditCoordinates_SetType(GUI *gui_coord, int type)
{
  DISP_OBJ_COORD *disp_obj = (DISP_OBJ_COORD *)GUIObject_GetDispObject(gui_coord);
  disp_obj->type = type;
}

GUI *Create_EditCoordinates(BOOK *book, int type)
{
  GUI_COORDINATES *gui_coord = (GUI_COORDINATES *)malloc(sizeof(GUI_COORDINATES));
  if (!GUIObject_Create(gui_coord, EditCoordinates_destruct, EditCoordinates_construct, book, EditCoordinates_callback, UIDisplay_Main, sizeof(GUI_COORDINATES)))
  {
    mfree(gui_coord);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gui_coord);

  GUIObject_EditCoordinates_SetType(gui_coord, type);
  GUIObject_SetStyle(gui_coord, UI_OverlayStyle_TrueFullScreen);
  GUIObject_SetTitleType(gui_coord, UI_TitleMode_None);
  GUIObject_SoftKeys_Hide(gui_coord);

  return gui_coord;
}
