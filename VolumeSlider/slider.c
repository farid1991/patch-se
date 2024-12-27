#include "temp\target.h"

#include "..\\include\Color.h"
#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "dll.h"
#include "main.h"
#include "slider.h"

//==============================================================================

int division(int num1, int num2)
{
  if (num2 == 0)
  {
    // Handle division by zero here, if necessary.
    return 0; // Or some appropriate value or error handling.
  }

  int quotient = 0;
  int sign = 1; // Store the sign of the result.

  // Handle negative numbers.
  if (num1 < 0)
  {
    num1 = -num1;
    sign = -sign;
  }
  
  if (num2 < 0)
  {
    num2 = -num2;
    sign = -sign;
  }

  while (num1 >= num2)
  {
    num1 -= num2;
    quotient++;
  }

  // Apply the sign.
  return sign * quotient;
}

void SaveVolumeState(uint8_t volume)
{
  FileDelete(VOL_STATE_PATH, VOLUME_DATA, NULL);

  int file = _fopen(VOL_STATE_PATH, VOLUME_DATA, FSX_O_RDWR, FSX_S_IWRITE | FSX_S_IREAD, NULL);
  if (file >= NULL)
  {
    fwrite(file, &volume, sizeof(uint8_t));
    fclose(file);
  }
}

void DrawText(int font, TEXTID text, int align, int XPos, int YPos, int Width, int TextColor)
{
  if (text != EMPTY_TEXTID)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(font, text, align, XPos, YPos, XPos + Width, YPos + (font & 0xFF), TextColor);
#else
    SetFont(font);
    int font_h = GetImageHeight(' ');
    DrawString(text, align, XPos, YPos, XPos + Width, YPos + font_h, 0x14, 0x5, TextColor, clEmpty);
#endif
  }
}

void DrawSlider(int value, int max_value, int rect_y1, int rect_height, TEXTID slider_text, TEXTID value_text, uint32_t text_color, uint32_t cursor_color, uint32_t outline_color, uint32_t slider_color)
{
  // Define the slider rectangle
  int slider_height = rect_height >> 3;

  int slider_x1 = 10;
  int slider_x2 = 230;
  int slider_y1 = rect_y1 + (rect_height >> 1) + (rect_height >> 2);
  int slider_y2 = slider_y1 + slider_height;

  // Calculate the x coordinate for drawing the slider thumb
  int sliderWidth = slider_x2 - slider_x1;
  int thumbWidth = slider_height * 2;
  int thumbX = slider_x1 + division(value * sliderWidth, max_value) - (thumbWidth >> 1); // Center the thumb horizontally

  // Draw the main background rectangle as the background
  DrawRect(0, rect_y1, 240, rect_y1 + rect_height, cursor_color, cursor_color);

  // Draw the slider track
  DrawRect(slider_x1, slider_y1, slider_x2, slider_y2, outline_color, slider_color);

  // Draw the slider thumb and its outline
  DrawRect(thumbX, slider_y1, thumbX + thumbWidth, slider_y2, text_color, text_color);
  DrawRect(thumbX - 1, slider_y1, thumbX, slider_y2, outline_color, outline_color);
  DrawRect(thumbX + thumbWidth, slider_y1, thumbX + thumbWidth + 1, slider_y2, outline_color, outline_color);

  // Draw the slider text
  int textWidth = sliderWidth;
  int textX = slider_x1;
  int textY = rect_y1 + (rect_height >> 3);
  DrawText(FONT_E_20B, slider_text, AlignLeft, textX, textY, textWidth, text_color);
  DrawText(FONT_E_20B, value_text, AlignRight, 0, textY, textWidth, text_color);
}

TEXTID percent_to_textid(int percentage)
{
  char buf[8];
  sprintf(buf, "%d%%", percentage);
  return TextID_Create(buf, ENC_LAT1, TEXTID_ANY_LEN);
}

int Slider_OnCreate(DISP_OBJ_SLIDER *disp_obj)
{
  disp_obj->slider_a_textid = STR("Media");
  disp_obj->slider_b_textid = STR("Ringtone");
  disp_obj->slider_c_textid = STR("Call");

  char media, ring, call;
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &ring);
  Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);

  disp_obj->slider_a = media - 18;
  disp_obj->slider_b = ring;
  disp_obj->slider_c = call - 9;

  disp_obj->slider_a_val = percent_to_textid(vol_table_media[disp_obj->slider_a]);
  disp_obj->slider_b_val = percent_to_textid(vol_table_ring[disp_obj->slider_b]);
  disp_obj->slider_c_val = percent_to_textid(vol_table_ring[disp_obj->slider_c]);

  disp_obj->current_row = ROW_1;

  return 1;
}

void Slider_OnClose(DISP_OBJ_SLIDER *disp_obj)
{
  TextID_Destroy(disp_obj->slider_a_textid);
  TextID_Destroy(disp_obj->slider_b_textid);
  TextID_Destroy(disp_obj->slider_c_textid);
  TextID_Destroy(disp_obj->slider_a_val);
  TextID_Destroy(disp_obj->slider_b_val);
  TextID_Destroy(disp_obj->slider_c_val);
}

void Slider_OnRedraw(DISP_OBJ_SLIDER *disp_obj, int, int, int)
{
  DrawSlider(disp_obj->slider_a, MAX_MEDIAVOLUME,
             40, 50,
             disp_obj->slider_a_textid,
             disp_obj->slider_a_val,
             (disp_obj->current_row == ROW_1) ? clAlpha : clBlueMidDark,
             (disp_obj->current_row == ROW_1) ? clBlueMidDark : clAlpha,
             clCyan,
             clTheta);

  DrawSlider(disp_obj->slider_b, MAX_RINGVOLUME,
             90, 50,
             disp_obj->slider_b_textid,
             disp_obj->slider_b_val,
             (disp_obj->current_row == ROW_2) ? clAlpha : clBlueMidDark,
             (disp_obj->current_row == ROW_2) ? clBlueMidDark : clAlpha,
             clCyan,
             clTheta);

  DrawSlider(disp_obj->slider_c, MAX_CALLVOLUME,
             140, 50,
             disp_obj->slider_c_textid,
             disp_obj->slider_c_val,
             (disp_obj->current_row == ROW_3) ? clAlpha : clBlueMidDark,
             (disp_obj->current_row == ROW_3) ? clBlueMidDark : clAlpha,
             clCyan,
             clTheta);
}

void Slider_OnKey(DISP_OBJ_SLIDER *disp_obj, int key, int r2, int repeat, int mode)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;

  bool save = FALSE;
  char media_volume;

  if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    switch (key)
    {
    case KEY_UP:
    case KEY_DIGITAL_2:
      if ((--disp_obj->current_row) < ROW_1)
        disp_obj->current_row = ROW_3;
      break;

    case KEY_DOWN:
    case KEY_DIGITAL_8:
      if (++disp_obj->current_row > ROW_3)
        disp_obj->current_row = ROW_1;
      break;

    case KEY_LEFT:
    case KEY_DIGITAL_4:
      switch (disp_obj->current_row)
      {
      case ROW_1:
        if (disp_obj->slider_a)
        {
          save = TRUE;
          media_volume = (--disp_obj->slider_a) + 18;
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, media_volume);
        }
        break;

      case ROW_2:
        if (disp_obj->slider_b)
        {
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, --disp_obj->slider_b);
          REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, disp_obj->slider_b);
        }
        break;

      case ROW_3:
        if (disp_obj->slider_c)
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, --disp_obj->slider_c + 9);
        break;
      }
      break;

    case KEY_RIGHT:
    case KEY_DIGITAL_6:
      switch (disp_obj->current_row)
      {
      case ROW_1:
        if (disp_obj->slider_a < MAX_MEDIAVOLUME)
        {
          save = TRUE;
          media_volume = (++disp_obj->slider_a) + 18;
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, media_volume);
        }
        break;

      case ROW_2:
        if (disp_obj->slider_b < MAX_RINGVOLUME)
        {
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, ++disp_obj->slider_b);
          REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, disp_obj->slider_b);
        }
        break;

      case ROW_3:
        if (disp_obj->slider_c < MAX_CALLVOLUME)
          Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, ++disp_obj->slider_c + 9);
        break;
      }
      break;

    case KEY_DEL:
      switch (disp_obj->current_row)
      {
      case ROW_1:
        save = TRUE;
        disp_obj->slider_a = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, 18);
        break;

      case ROW_2:
        disp_obj->slider_b = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, 0);
        REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, 0);
        break;

      case ROW_3:
        disp_obj->slider_c = 0;
        Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, 9);
        break;
      }
      break;
    }

    if (save)
      SaveVolumeState(media_volume);

    disp_obj->slider_a_val = percent_to_textid(vol_table_media[disp_obj->slider_a]);
    disp_obj->slider_b_val = percent_to_textid(vol_table_ring[disp_obj->slider_b]);
    disp_obj->slider_c_val = percent_to_textid(vol_table_ring[disp_obj->slider_c]);
    DispObject_InvalidateRect(disp_obj, NULL);
  }
}

void Slider_construct(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, Gui_Slider);
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_SLIDER));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Slider_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Slider_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Slider_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Slider_OnKey);
}

void Slider_destruct(GUI_SLIDER *gs)
{
}

void Slider_callback(DISP_OBJ *disp, void *msg, GUI_SLIDER *gui)
{
}

GUI_SLIDER *Create_Slider(BOOK *book)
{
  GUI_SLIDER *gs = (GUI_SLIDER *)malloc(sizeof(GUI_SLIDER));
  if (!GUIObject_Create(gs, Slider_destruct, Slider_construct, book, Slider_callback, UIDisplay_Main, sizeof(GUI_SLIDER)))
  {
    mfree(gs);
    return NULL;
  }

  if (book)
    BookObj_AddGUIObject(book, gs);

  GUIObject_SetTitleType(gs, UI_TitleMode_Normal);
  GUIObject_SetTitleText(gs, STR("Volume"));
  return (gs);
}
