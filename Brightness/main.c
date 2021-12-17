/*
;Расширенный диапазон регулировки яркости
;Позволяет регулировать яркость от 0 до 100%
;Сообщение "При увеличении яркости подсветки..." не появляется
;Имя конфига "Brightness.ini
;Имена изображений "Background.png", "Level_Normal.png", "Level_Up_Max.png", "Level_Down_Max.png
;Путь для конфига и изображений "/card/other/ZBin/Config/Brightness"
;Цвет текста/обводки и размер шрифта указывать в HEX
;v. 3
;(c) IronMaster, E1kolyan
*/
#include "temp\target.h"

#include "..\\include\Color.h"
#include "..\\include\Types.h"
#include "..\\include\book\SetBook.h"

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#endif
#include "Lib.h"
#include "main.h"

void *malloc(int size)
{
#if defined(DB2010)
  return (memalloc(size, 1, 5, "br", 0));
#elif defined(DB2020)
  return (memalloc(0, size, 1, 5, "br", 0));
#elif defined(A2)
  return (memalloc(0xFFFFFFFF, size, 1, 5, "br", 0));
#endif
}

void mfree(void *mem)
{
#if defined(DB2010)
  memfree(mem, "br", 0);
#elif defined(DB2020)
  if (mem)
    memfree(0, mem, "br", 0);
#elif defined(A2)
  if (mem)
    memfree(0, mem, "br", 0);
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
  if (!fstat(FILE_PATH, FILE_NAME, &fs) && fs.fsize)
  {
    char *buf = (char *)malloc(fs.fsize);
    int f = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDONLY, FSX_S_IRUSR | FSX_S_IWUSR, 0);
    fread(f, buf, fs.fsize);
    fclose(f);

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

void RegisterImage(DISP_OBJ_BRIGHT *disp_obj)
{
  const wchar_t *ImageName[] = {L"Background.png", L"Level_Normal.png", L"Level_Up_Max.png", L"Level_Down_Max.png"};
  IMG *img;
  char error_code;
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  for (int i = 0; i < img_count; i++)
  {
    img = &disp_obj->Images[i];
    img->ImageID = NOIMAGE;
    img->ImageHandle = NOIMAGE;
    if (!fstat(FILE_PATH, ImageName[i], 0))
      if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->ImageHandle, &error_code))
        if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->ImageHandle, FILE_PATH, (wchar_t *)ImageName[i], 0, &img->ImageID, &error_code))
          if (error_code)
            img->ImageHandle = NOIMAGE;
  }
}

void UnregisterImage(DISP_OBJ_BRIGHT *disp_obj)
{
  IMG *img;
  char error_code;
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  for (int i = 0; i < img_count; i++)
  {
    img = &disp_obj->Images[i];
    if (img->ImageID != NOIMAGE)
      REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, img->ImageHandle, 0, 0, img->ImageID, 1, &error_code);
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
  disp_obj->text = EMPTY_TEXTID;

  RegisterImage(disp_obj);

  disp_obj->data = (FILE_DATA *)malloc(sizeof(FILE_DATA));
  ReadConfig(disp_obj->data);

  if (disp_obj->bright == 100)
    disp_obj->image = disp_obj->Images[2].ImageID;
  else if (disp_obj->bright == 0)
    disp_obj->image = disp_obj->Images[3].ImageID;
  else
    disp_obj->image = disp_obj->Images[1].ImageID;
    
  return 1;
}

void Bright_onClose(DISP_OBJ_BRIGHT *disp_obj)
{
  UnregisterImage(disp_obj);

  if (disp_obj->text != EMPTY_TEXTID)
    TextID_Destroy(disp_obj->text);

  mfree(disp_obj->data);
}

void DrawString_Params(TEXTID text, int font, int align, int x1, int y1, int x2, int y2, uint32_t tcolor, uint32_t ocolor)
{
  int font_height = y1 + (font & 0xFF);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  dll_DrawString(font, text, align, x1 + 1, y1, x2, font_height, ocolor);
  dll_DrawString(font, text, align, x1, y1 + 1, x2, font_height, ocolor);
  dll_DrawString(font, text, align, x1 - 1, y1, x2, font_height, ocolor);
  dll_DrawString(font, text, align, x1, y1 - 1, x2, font_height, ocolor);
  dll_DrawString(font, text, align, x1, y1, x2, font_height, tcolor);
#else

  SetFont(font);
  DrawString(text, align, x1 + 1, y1, x2, font_height, 0, 0, ocolor, 0);
  DrawString(text, align, x1, y1 + 1, x2, font_height, 0, 0, ocolor, 0);
  DrawString(text, align, x1 - 1, y1, x2, font_height, 0, 0, ocolor, 0);
  DrawString(text, align, x1, y1 - 1, x2, font_height, 0, 0, ocolor, 0);
  DrawString(text, align, x1, y1, x2, font_height, 0, 0, tcolor, 0);
#endif
}

void Bright_onRedraw(DISP_OBJ_BRIGHT *disp_obj, int, int, int)
{
#if defined(A1) || defined(DB3150v1)
  GC_DrawImage(disp_obj->data->Icon_Background_x, disp_obj->data->Icon_Background_y, disp_obj->Images[0].ImageID);
  GC_DrawImage(disp_obj->data->Icon_Level_x, disp_obj->data->Icon_Level_y, disp_obj->image);
#else
  GC *pGC = get_DisplayGC();
  dll_GC_PutChar(pGC,
                 disp_obj->data->Icon_Background_x,
                 disp_obj->data->Icon_Background_y,
                 0,
                 0,
                 disp_obj->Images[0].ImageID);
  dll_GC_PutChar(pGC,
                 disp_obj->data->Icon_Level_x,
                 disp_obj->data->Icon_Level_y,
                 0,
                 0,
                 disp_obj->image);
#endif

  TextID_Destroy(disp_obj->text);
  disp_obj->text = TextID_CreateIntegerID(disp_obj->bright);
  DrawString_Params(disp_obj->text,
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
      if ((disp_obj->bright += disp_obj->cstep) >= 100)
      {
        disp_obj->bright = 100;
        disp_obj->image = disp_obj->Images[2].ImageID;
      }
      else
        disp_obj->image = disp_obj->Images[1].ImageID;
      break;
    case KEY_DOWN:
      if ((disp_obj->bright -= disp_obj->cstep) <= 0)
      {
        disp_obj->bright = 0;
        disp_obj->image = disp_obj->Images[3].ImageID;
      }
      else
        disp_obj->image = disp_obj->Images[1].ImageID;
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

void Bright_LongClose(BOOK *book, GUI *gui)
{
  SetBook *pSetBook = (SetBook *)book;
  SetBrightness((int)pSetBook->bright);
  UI_Event(RETURN_TO_STANDBY_EVENT);
}

void Bright_Close(BOOK *book, GUI *gui)
{
  SetBook *pSetBook = (SetBook *)book;
  SetBrightness((int)pSetBook->bright);
  FreeBook(pSetBook);
}

void Bright_Save(BOOK *book, GUI *gui)
{
  SetBook *pSetBook = (SetBook *)book;
  FreeBook(pSetBook);
}

void Bright_CallBack(DISP_OBJ *, void *msg, GUI *)
{
}

extern "C" int VisualBrightness(void *data, BOOK *book)
{
  SetBook *pSetBook = (SetBook *)book;

  pSetBook->bright = (char *)Display_GetBrightness(UIDisplay_Main);

  GUI_BRIGHT *gui = (GUI_BRIGHT *)malloc(sizeof(GUI_BRIGHT));
  pSetBook->gui = gui;

  if (!GUIObject_Create(pSetBook->gui, Bright_destr, Bright_constr, pSetBook, Bright_CallBack, UIDisplay_Main, sizeof(GUI_BRIGHT)))
    mfree(gui);
  if (pSetBook)
    BookObj_AddGUIObject(pSetBook, pSetBook->gui);

  GUIObject_SetTitleType(pSetBook->gui, UI_TitleMode_None);
  GUIObject_SoftKeys_SetAction(pSetBook->gui, ACTION_LONG_BACK, Bright_LongClose);
  GUIObject_SoftKeys_SetAction(pSetBook->gui, ACTION_BACK, Bright_Close);
  GUIObject_SoftKeys_SetAction(pSetBook->gui, ACTION_SELECT1, Bright_Save);
  GUIObject_SoftKeys_SetText(pSetBook->gui, ACTION_SELECT1, TEXTID_SAVE);

  GUIObject_Show(pSetBook->gui);
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
