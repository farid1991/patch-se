#include "temp\target.h"

#include "..\\include\Color.h"
#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\SetBook.h"

#include "dll.h"
#include "main.h"

void *malloc(int size)
{
#if defined(DB2020)
  return (memalloc(NULL, size, 1, 5, "br", NULL));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "br", NULL));
#else
  return (memalloc(size, 1, 5, "br", NULL));
#endif
}

void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(NULL, mem, "br", NULL);
#elif defined(A2)
    memfree(NULL, mem, "br", NULL);
#else
    memfree(mem, "br", NULL);
#endif
}

void ReadConfig(FILE_DATA *data)
{
  const char *format =
      "Title Text Color: %x\r\n"
      "Title Overlay Color: %x\r\n"
      "Title Coordinates: %d,%d,%d,%d\r\n"
      "Title Align: %d\r\n"
      "Title Font: %x\r\n"
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      "Title Bold: %x\r\n"
      "Title Italic: %x\r\n"
#endif
      "Percent Text Color: %x\r\n"
      "Percent Overlay Color: %x\r\n"
      "Percent Coordinates: %d,%d,%d,%d\r\n"
      "Percent Align: %d\r\n"
      "Percent Font: %x\r\n"
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      "Percent Bold: %x\r\n"
      "Percent Italic: %x\r\n"
#endif
      "Background Coordinates: %d,%d\r\n"
      "Level Coordinates: %d,%d\r\n";

  FSTAT fs;
  if (!fstat(CONFIG_PATH, CONFIG_NAME, &fs) && fs.fsize)
  {
    char *buf = (char *)malloc(fs.fsize);
    int file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, NULL);
    fread(file, buf, fs.fsize);
    fclose(file);

    sscanf(buf, format,
           &data->Title_Text_Color, &data->Title_Text_Overlay,
           &data->Title_Text_x1, &data->Title_Text_y1, &data->Title_Text_x2, &data->Title_Text_y2,
           &data->Title_Text_Align,
           &data->Title_Text_Font,
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
           &data->Title_Text_Bold,
           &data->Title_Text_Italic,
#endif

           &data->Percent_Text_Color, &data->Percent_Text_Overlay,
           &data->Percent_Text_x1, &data->Percent_Text_y1, &data->Percent_Text_x2, &data->Percent_Text_y2,
           &data->Percent_Text_Align,
           &data->Percent_Text_Font,
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
           &data->Percent_Text_Bold,
           &data->Percent_Text_Italic,
#endif

           &data->Icon_Background_x, &data->Icon_Background_y,
           &data->Icon_Level_x, &data->Icon_Level_y);
    mfree(buf);
  }
}

void RegisterImage(IMG *img, wchar_t *fpath, wchar_t *fname)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;
  img->id = NOIMAGE;
  img->handle = NOIMAGE;

  if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->handle, &error_code))
    if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->handle, fpath, fname, NULL, &img->id, &error_code))
      if (error_code)
        img->handle = NOIMAGE;
}

void UnLoadImages(DISP_OBJ_BRIGHT *disp_obj)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  char error_code;

  ImageID_Free(disp_obj->image_id);

  for (int i = 0; i < LAST_ICN; i++)
  {
    if (disp_obj->images[i].id != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, disp_obj->images[i].handle, 0, 0, disp_obj->images[i].id, 1, &error_code);
  }
}

void LoadImages(DISP_OBJ_BRIGHT *disp_obj)
{
  const wchar_t *image_list[LAST_ICN] = {
      L"Background.png",
      L"Level_Normal.png",
      L"Level_Up_Max.png",
      L"Level_Down_Max.png"};

  for (int i = 0; i < LAST_ICN; i++)
  {
    if (FSX_IsFileExists(CONFIG_PATH, (wchar_t *)image_list[i]))
    {
      RegisterImage(&disp_obj->images[i], CONFIG_PATH, (wchar_t *)image_list[i]);
    }
    else
    {
      disp_obj->images[i].id = NOIMAGE;
    }
  }
}

void SetBrightness(int bright)
{
#ifdef A1
  Display_SetBrightness(UIDisplay_Main, bright);
#else
  Display_SetBrightness(bright);
#endif
  SaveBrightness(bright);
}

int Bright_onCreate(DISP_OBJ_BRIGHT *disp_obj)
{
  disp_obj->bright = Display_GetBrightness(UIDisplay_Main);
  disp_obj->cstep = 1;
  disp_obj->text_id = EMPTY_TEXTID;

  LoadImages(disp_obj);

  disp_obj->data = (FILE_DATA *)malloc(sizeof(FILE_DATA));
  ReadConfig(disp_obj->data);

  if (disp_obj->bright == BRIGHT_MAX)
    disp_obj->image_id = disp_obj->images[LEVEL_UP_ICN].id;
  else if (disp_obj->bright == BRIGHT_MIN)
    disp_obj->image_id = disp_obj->images[LEVEL_DOWN_ICN].id;
  else
    disp_obj->image_id = disp_obj->images[LEVEL_NORMAL_ICN].id;

  return 1;
}

void Bright_onClose(DISP_OBJ_BRIGHT *disp_obj)
{
  UnLoadImages(disp_obj);
  TextID_Destroy(disp_obj->text_id);
  mfree(disp_obj->data);
}

void DrawString_Params(TEXTID text, int font, int align, int x1, int y1, int x2, int y2, uint32_t t_color, uint32_t o_color)
{
  int font_height = y1 + (font & 0xFF);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString(font, text, align, x1 + 1, y1, x2, font_height, o_color);
  dll_DrawString(font, text, align, x1, y1 + 1, x2, font_height, o_color);
  dll_DrawString(font, text, align, x1 - 1, y1, x2, font_height, o_color);
  dll_DrawString(font, text, align, x1, y1 - 1, x2, font_height, o_color);
  dll_DrawString(font, text, align, x1, y1, x2, y2, t_color);
#else
  SetFont(font);
  DrawString(text, align, x1 + 1, y1, x2, font_height, 0, 0, o_color, 0);
  DrawString(text, align, x1, y1 + 1, x2, font_height, 0, 0, o_color, 0);
  DrawString(text, align, x1 - 1, y1, x2, font_height, 0, 0, o_color, 0);
  DrawString(text, align, x1, y1 - 1, x2, font_height, 0, 0, o_color, 0);
  DrawString(text, align, x1, y1, x2, y2, 0, 0, t_color, 0);
#endif
}

void Bright_onRedraw(DISP_OBJ_BRIGHT *disp_obj, int, int, int)
{
  GC *gc = get_DisplayGC();
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_GC_PutChar(gc, disp_obj->data->Icon_Background_x, disp_obj->data->Icon_Background_y, 0, 0, disp_obj->images[BACKGROUND_ICN].id);
  dll_GC_PutChar(gc, disp_obj->data->Icon_Level_x, disp_obj->data->Icon_Level_y, 0, 0, disp_obj->image_id);
#else
  GC_PutChar(gc, disp_obj->data->Icon_Background_x, disp_obj->data->Icon_Background_y, 0, 0, disp_obj->images[BACKGROUND_ICN].id);
  GC_PutChar(gc, disp_obj->data->Icon_Level_x, disp_obj->data->Icon_Level_y, 0, 0, disp_obj->image_id);
#endif

  TextID_Destroy(disp_obj->text_id);
  disp_obj->text_id = TextID_CreateIntegerID(disp_obj->bright);
  DrawString_Params(disp_obj->text_id,
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
                    disp_obj->data->Percent_Text_Font + (disp_obj->data->Percent_Text_Bold << 8) + (disp_obj->data->Percent_Text_Italic << 9),
#else
                    disp_obj->data->Percent_Text_Font,
#endif
                    disp_obj->data->Percent_Text_Align,
                    disp_obj->data->Percent_Text_x1,
                    disp_obj->data->Percent_Text_y1,
                    disp_obj->data->Percent_Text_x2,
                    disp_obj->data->Percent_Text_y2,
                    disp_obj->data->Percent_Text_Color,
                    disp_obj->data->Percent_Text_Overlay);

  DrawString_Params(TEXTID_BRIGHTNESS,
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
                    disp_obj->data->Title_Text_Font + (disp_obj->data->Title_Text_Bold << 8) + (disp_obj->data->Title_Text_Italic << 9),
#else
                    disp_obj->data->Title_Text_Font,
#endif
                    disp_obj->data->Title_Text_Align,
                    disp_obj->data->Title_Text_x1,
                    disp_obj->data->Title_Text_y1,
                    disp_obj->data->Title_Text_x2,
                    disp_obj->data->Title_Text_y2,
                    disp_obj->data->Title_Text_Color,
                    disp_obj->data->Title_Text_Overlay);
}

void Bright_OnLayout(DISP_OBJ_BRIGHT *disp_obj)
{
  DispObject_SetLayerColor(disp_obj, clEmpty);
}

void Bright_onKey(DISP_OBJ_BRIGHT *disp_obj, int key, int unk, int repeat, int mode)
{
  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    if (mode == KBD_SHORT_RELEASE)
      disp_obj->cstep = 1;
    else if (mode == KBD_REPEAT && repeat > 5)
      disp_obj->cstep = 4;

    switch (key)
    {
    case KEY_UP:
      if ((disp_obj->bright += disp_obj->cstep) >= BRIGHT_MAX)
      {
        disp_obj->bright = BRIGHT_MAX;
        disp_obj->image_id = disp_obj->images[LEVEL_UP_ICN].id;
      }
      else
        disp_obj->image_id = disp_obj->images[LEVEL_NORMAL_ICN].id;
      break;
    case KEY_DOWN:
      if ((disp_obj->bright -= disp_obj->cstep) <= BRIGHT_MIN)
      {
        disp_obj->bright = BRIGHT_MIN;
        disp_obj->image_id = disp_obj->images[LEVEL_DOWN_ICN].id;
      }
      else
        disp_obj->image_id = disp_obj->images[LEVEL_NORMAL_ICN].id;
      break;
    }

    if (mode == KBD_LONG_RELEASE)
      disp_obj->cstep = 1;

    SetBrightness(disp_obj->bright);
    DispObject_InvalidateRect(disp_obj, NULL);
  }
}

void Bright_constr(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, GuiName);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_BRIGHT));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Bright_onCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Bright_onClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Bright_onRedraw);
  DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)Bright_OnLayout);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Bright_onKey);
}

void Bright_destr(GUI *gui)
{
}

void Bright_CallBack(DISP_OBJ *, void *msg, GUI *)
{
}

GUI_BRIGHT *Create_GUIBright(BOOK *book)
{
  GUI_BRIGHT *gui = (GUI_BRIGHT *)malloc(sizeof(GUI_BRIGHT));

  if (!GUIObject_Create(gui, Bright_destr, Bright_constr, book, Bright_CallBack, UIDisplay_Main, sizeof(GUI_BRIGHT)))
  {
    mfree(gui);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gui);

  GUIObject_SetTitleType(gui, UI_TitleMode_None);
  return gui;
}

void Bright_LongClose(BOOK *book, GUI *gui)
{
  SetBook *set_book = (SetBook *)book;
  SetBrightness((int)set_book->bright);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void Bright_Close(BOOK *book, GUI *gui)
{
  SetBook *set_book = (SetBook *)book;
  SetBrightness((int)set_book->bright);
  FreeBook(set_book);
}

void Bright_Save(BOOK *book, GUI *gui)
{
  SetBook *set_book = (SetBook *)book;
  FreeBook(set_book);
}

extern "C" int VisualBrightness(void *data, BOOK *book)
{
  SetBook *set_book = (SetBook *)book;
  set_book->bright = (char *)Display_GetBrightness(UIDisplay_Main);

  if (set_book->gui = Create_GUIBright(set_book))
  {
    GUIObject_SoftKeys_SetAction(set_book->gui, ACTION_LONG_BACK, Bright_LongClose);
    GUIObject_SoftKeys_SetAction(set_book->gui, ACTION_BACK, Bright_Close);
    GUIObject_SoftKeys_SetAction(set_book->gui, ACTION_SELECT1, Bright_Save);
    GUIObject_SoftKeys_SetText(set_book->gui, ACTION_SELECT1, TEXTID_SAVE);
    GUIObject_Show(set_book->gui);
  }
  return 1;
}

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
extern "C" void SecondLineText(DYNAMIC_MENU_ELEMENT *dme)
{
  wchar_t buf[32];
  snwprintf(buf, MAXELEMS(buf), L"Brightness: %d%%", Display_GetBrightness(UIDisplay_Main));
  DynamicMenu_SetElement_SecondLineText(dme, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}
#endif
