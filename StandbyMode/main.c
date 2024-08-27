#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"
#include "..\\include\Color.h"

#include "..\\include\book\StandbyBook.h"

#include "dll.h"
#include "draw.h"
#include "editor.h"
#include "item_text.h"
#include "LNG.h"
#include "standby_data.h"
#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
  return memalloc(0, size, 1, 5, EMP_NAME, 0);
#elif defined(A2)
  return memalloc(0xFFFFFFFF, size, 1, 5, EMP_NAME, 0);
#else
  return memalloc(size, 1, 5, EMP_NAME, 0);
#endif
}

__thumb void mfree(void *mem)
{
  if (mem)
#if defined(DB2020)
    memfree(0, mem, EMP_NAME, 0);
#elif defined(A2)
    memfree(0, mem, EMP_NAME, 0);
#else
    memfree(mem, EMP_NAME, 0);
#endif
}

extern "C" void Start_CallStateTimer()
{
  STANDBY_DATA *standby_data = Get_StandbyData();
  standby_data->call_state = true;
}

extern "C" void Stop_CallStateTimer()
{
  STANDBY_DATA *standby_data = Get_StandbyData();
  standby_data->call_state = false;
}

bool IsInStandby()
{
  return (Display_GetTopBook(UIDisplay_Main) == Find_StandbyBook());
}

void invalidate_all(STANDBY_DATA *standby_data)
{
  DISP_OBJ *status_row = *StatusRow_p();
  DISP_OBJ *softkeys = DispObject_SoftKeys_Get();

  if (status_row)
    DispObject_InvalidateRect(status_row, NULL);

  if (IsInStandby())
  {
    if (standby_data->status_indication)
      DispObject_InvalidateRect(standby_data->status_indication, NULL);
  }

  if (softkeys)
    DispObject_InvalidateRect(softkeys, NULL);
}

void update_datetime(STANDBY_DATA *standby_data)
{
  IClock *pClock = NULL;
  Get_IClock(&pClock);
  pClock->GetDateAndTime(standby_data->now);
  pClock->Release();
  if (standby_data->temp_date->day != standby_data->now->date.day)
  {
    standby_data->temp_date = &standby_data->now->date;
    standby_data->current_day = Get_WeekDay(standby_data);
    standby_data->current_date = Date2ID(standby_data->temp_date, standby_data->settings.date.mode, 1);
  }
}

void update_heap_info(STANDBY_DATA *standby_data)
{
  standby_data->free_heap = Get_FreeHeap(standby_data);
}

void update_battery_info(STANDBY_DATA *standby_data)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  GetBatteryState(SYNC, standby_data->battery_data);
}

void update_redraw(uint16_t timerID, STANDBY_DATA *standby_data)
{
  update_datetime(standby_data);

  if ((standby_data->settings.heap.state || standby_data->edit_mode) && IsInStandby())
    update_heap_info(standby_data);

  update_battery_info(standby_data);
  invalidate_all(standby_data);

  Timer_ReSet(&standby_data->refresh_timer, REFRESH_TIMER, MKTIMERPROC(update_redraw), standby_data);
}

void FreeStatusRow(STANDBY_DATA *standby_data)
{
  if (standby_data->row_count)
  {
    for (int i = 0; i < standby_data->row_count; i++)
    {
      standby_data->status_icn_count[i] = NULL;
    }
  }
  standby_data->row_count = NULL;
}

void UpdateStatusInfo(STANDBY_DATA *standby_data)
{
  if (!standby_data->status_was_changed)
    return;

  standby_data->status_was_changed = FALSE;

  FreeStatusRow(standby_data);

  if (!List_GetCount(standby_data->status_list))
    return;

  STATUS_ITEM_LIST *status_item;
  int index;
  int i = 0;
  int j = 0;
  int row_counter_tmp = 0;

  for (index = 0; index < List_GetCount(standby_data->status_list); index++)
  {
    status_item = (STATUS_ITEM_LIST *)List_Get(standby_data->status_list, index);
    standby_data->status_bar[i][j++] = status_item->image_id;
    if (j >= MAX_COLOMN)
    {
      standby_data->status_icn_count[i++] = j;
      j = 0;
      ++row_counter_tmp;
      if (i >= MAX_ROW)
        break;
    }
  }
  if (j)
  {
    standby_data->status_icn_count[i++] = j;
    ++row_counter_tmp;
  }
  standby_data->row_count = row_counter_tmp;
}

wchar_t *Get_Align(int align)
{
  wchar_t *alignments[] = {L"Left", L"Right", L"Center"};

  if (align >= 0 && align <= 2)
  {
    return alignments[align];
  }
  return NULL;
}

void WidgetAction(int pos)
{
  switch (pos)
  {
  case POS_1:
    GoMusic();
    break;
  case POS_2:
    UI_Event(MEDIAPLAYERKEY_PRESSED_EVENT);
    break;
  case POS_3:
    UI_Event(UI_MEDIAPLAYER_NEXT_TRACK_EVENT);
    break;
  }
}

void DrawWidgetIcons(int XPos, int YPos, int y_pos_start, wchar_t *playPauseIcon, wchar_t *nextIcon)
{
  DrawImageFromPath(playPauseIcon, XPos + 21, (YPos + 27) - y_pos_start);
  DrawImageFromPath(nextIcon, XPos + 204, (YPos + 33) - y_pos_start);
}

void DrawMusicWidget(STANDBY_DATA *standby_data, int y_pos_start)
{
  int XPos = standby_data->settings.music.XPos;
  int YPos = standby_data->settings.music.YPos;
  DrawImageFromPath(L"appwidget_bg.png", XPos, YPos - y_pos_start);

  BOOK *MusicBook = FindBook(IsAudioPlayerBook);
  if (MusicBook)
  {
    if (standby_data->widget_mode)
    {
      switch (standby_data->widget_pos)
      {
      case POS_1:
        DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_pause_focused.png", L"appwidget_next_normal.png");
        break;
      case POS_2:
        DrawImageFromPath(L"appwidget_high.png", XPos, YPos - y_pos_start);
        DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_pause_normal.png", L"appwidget_next_normal.png");
        break;
      case POS_3:
        DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_pause_normal.png", L"appwidget_next_focused.png");
        break;
      }
    }
    else
    {
      DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_pause_normal.png", L"appwidget_next_normal.png");
    }

    TEXTID text_id;
    text_id = Get_TitleTag(MusicBook);
    draw_string_no_style(FONT_E_18R, text_id, AlignLeft, XPos + 53, (YPos + 18) - y_pos_start, XPos + 148, clBlack);
    TextID_Destroy(text_id);

    text_id = Get_ArtistTag(MusicBook);
    draw_string_no_style(FONT_E_18R, text_id, AlignLeft, XPos + 53, (YPos + 41) - y_pos_start, XPos + 148, clBlack);
    TextID_Destroy(text_id);
  }
  else
  {
    if (standby_data->widget_mode)
    {
      switch (standby_data->widget_pos)
      {
      case POS_1:
        DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_play_focused.png", L"appwidget_next_normal.png");
        break;
      case POS_2:
        DrawImageFromPath(L"appwidget_high.png", XPos, YPos - y_pos_start);
        DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_play_normal.png", L"appwidget_next_normal.png");
        break;
      case POS_3:
        DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_play_normal.png", L"appwidget_next_focused.png");
        break;
      }
    }
    else
    {
      DrawWidgetIcons(XPos, YPos, y_pos_start, L"appwidget_play_normal.png", L"appwidget_next_normal.png");
    }
  }
}

void DrawItemsOnScreen(int y_pos_start, int height_max, bool IsStandby)
{
  STANDBY_DATA *standby_data = Get_StandbyData();
  bool edit_mode = standby_data->edit_mode;
  TEXTID text_id;
  GC *gc = get_DisplayGC();

  // statusrow icon;
  if (standby_data->settings.status.state || edit_mode)
  {
    int _SYNC = NULL;
    int *SYNC = &_SYNC;

    char state;
    REQUEST_SETTING_ALLOWEDCALLERS_GET(SYNC, -2, &state);
    SetTrayIcon(CUSTOM_CALLERSFROMLIST_ICN, (state == 1));
    SetTrayIcon(CUSTOM_NONECALLERS_ICN, (state == 2));

    Settings_ShowNumber_Get(&state);
    SetTrayIcon(CUSTOM_HIDE_NUM_ICN, (state == 1));

    UpdateStatusInfo(standby_data);
    if (standby_data->row_count)
    {
      int offset = 0 - y_pos_start;
      for (int i = 0; i < standby_data->row_count; i++)
      {
        DrawIconsArray(gc, standby_data->settings.status.align,
                       standby_data->settings.status.XPos,
                       standby_data->settings.status.YPos + offset,
                       &standby_data->status_bar[i][0],
                       standby_data->status_icn_count[i],
                       STATUS_ICN_WIDTH);
        offset += STATUS_ICN_HEIGHT + STATUS_ICN_STEP;
      }
    }
  }

  // network_icn;
  if (standby_data->settings.net_icn.state || edit_mode)
  {
    DrawIcon(gc, standby_data->settings.net_icn.XPos, standby_data->settings.net_icn.YPos, standby_data->current_network, y_pos_start);
  }

  // batt_icn;
  if (standby_data->settings.batt_icn.state || edit_mode)
  {
    DrawIcon(gc, standby_data->settings.batt_icn.XPos, standby_data->settings.batt_icn.YPos, standby_data->current_battery, y_pos_start);
  }

  // music widget;
  if ((standby_data->settings.music.state && IsStandby) || edit_mode)
  {
    DrawMusicWidget(standby_data, y_pos_start);
  }

  // standbyclock;
  if ((standby_data->settings.standbyclock.state && IsStandby) || edit_mode)
  {
    text_id = Time2ID(&standby_data->now->time, standby_data->settings.standbyclock.mode, FALSE);
    DrawItem(&standby_data->settings.standbyclock, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // statusclock;
  if ((standby_data->settings.statusclock.state && !IsStandby) || edit_mode)
  {
    text_id = Time2ID(&standby_data->now->time, standby_data->settings.statusclock.mode, FALSE);
    DrawItem(&standby_data->settings.statusclock, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // date;
  if ((standby_data->settings.date.state && IsStandby) || edit_mode)
  {
    DrawItem(&standby_data->settings.date, standby_data->current_date, y_pos_start);
  }

  // weekday;
  if ((standby_data->settings.weekday.state && IsStandby) || edit_mode)
  {
    DrawItem(&standby_data->settings.weekday, standby_data->current_day, y_pos_start);
  }

  // alarm;
  if (standby_data->settings.alarm.state || edit_mode)
  {
    TIME alarm;
    if ((Alarm_GetCurrentAlarmTime(standby_data, &alarm) >= 0) || edit_mode)
    {
      if (edit_mode)
      {
        text_id = TextID_Copy(TEXTID_ALARM_MASK);
      }
      else
      {
        wchar_t ustr[32];
        snwprintf(ustr, MAXELEMS(ustr), L"%02d:%02d", alarm.hour, alarm.min);
        text_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
      }
      DrawItemWithIcon(gc, &standby_data->settings.alarm, text_id, ALARM_ON_ICN, y_pos_start);
      TextID_Destroy(text_id);
    }
  }

  // profile;
  if ((standby_data->settings.profile.state && IsStandby) || edit_mode)
  {
    text_id = TextID_Copy(Get_ProfileName());
    DrawItem(&standby_data->settings.profile, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // heap;
  if ((standby_data->settings.heap.state && IsStandby) || edit_mode)
  {
    DrawItem(&standby_data->settings.heap, standby_data->free_heap, y_pos_start);
  }

  // timer;
  if ((standby_data->settings.timer.state && IsStandby) || edit_mode)
  {
    BOOK *timer_book = FindBook(IsTimerBook);

    if (timer_book || edit_mode)
    {
      if (timer_book)
      {
        text_id = Get_TimerTime(timer_book);
      }
      else
      {
        text_id = TextID_Copy(TEXTID_TIMER_MASK);
      }
      DrawItemWithIcon(gc, &standby_data->settings.timer, text_id, TIMER_ACTIVE_ICN, y_pos_start);
      TextID_Destroy(text_id);
    }
  }

  // calltime;
  if ((standby_data->settings.calltime.state && IsStandby) || edit_mode)
  {
    if (standby_data->call_state || edit_mode)
    {
      if (standby_data->call_state)
      {
        text_id = Get_CallTimeInfo();
      }
      else
      {
        text_id = TextID_Copy(TEXTID_TIMER_MASK);
      }
      DrawItemWithIcon(gc, &standby_data->settings.calltime, text_id, UMTS_CALL_ICN, y_pos_start);
      TextID_Destroy(text_id);
    }
  }

  // signal quality;
  if ((standby_data->settings.signal.state && IsStandby) || edit_mode)
  {
    text_id = Get_SignalQuality();
    DrawItem(&standby_data->settings.signal, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // network name;
  if (standby_data->settings.opname.state || edit_mode)
  {
    text_id = TextID_Copy(Get_CurrentOperatorName());
    DrawItem(&standby_data->settings.opname, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // battery;
  if (standby_data->settings.battery.state || edit_mode)
  {
    text_id = Get_BatteryCapacity(standby_data);
    DrawItem(&standby_data->settings.battery, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // charger current;
  if ((standby_data->settings.charge.state && IsStandby) || edit_mode)
  {
    if (standby_data->is_charging || edit_mode)
    {
      text_id = Get_ChargerCurrent(standby_data->battery_data->ChargerCurrent);
      DrawItem(&standby_data->settings.charge, text_id, y_pos_start);
      TextID_Destroy(text_id);
    }
  }

  // batttemp;
  if ((standby_data->settings.batttemp.state && IsStandby) || edit_mode)
  {
    text_id = Get_BatteryTemp(standby_data->battery_data->BatteryTemperature);
    DrawItem(&standby_data->settings.batttemp, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // systemp;
  if ((standby_data->settings.systemp.state && IsStandby) || edit_mode)
  {
    text_id = Get_SystemTemp(standby_data->battery_data->SystemTemperature);
    DrawItem(&standby_data->settings.systemp, text_id, y_pos_start);
    TextID_Destroy(text_id);
  }

  // phone mem;
  if ((standby_data->settings.phone.state && IsStandby) || edit_mode)
  {
    text_id = Get_PhoneVolumeSize(standby_data->settings.phone.mode);
    DrawItemWithIcon(gc, &standby_data->settings.phone, text_id, DB_2ROW_PHONE_ICN, y_pos_start);
    TextID_Destroy(text_id);
  }

  // card mem;
  if ((standby_data->settings.card.state && IsStandby) || edit_mode)
  {
    text_id = Get_CardVolumeSize(standby_data->settings.card.mode);
    DrawItemWithIcon(gc, &standby_data->settings.card, text_id, DB_LIST_M2_ICN, y_pos_start);
    TextID_Destroy(text_id);
  }

  // fmradio;
  if ((standby_data->settings.radio.state && IsStandby) || edit_mode)
  {
    BOOK *fmradio = FindBook(IsFmRadioBook);
    if (fmradio || edit_mode)
    {
      if (fmradio)
      {
        text_id = Get_FMRadioInfo(fmradio, standby_data->settings.radio.mode);
      }
      else
      {
        text_id = STR("FM Radio");
      }
      DrawItem(&standby_data->settings.radio, text_id, y_pos_start);
      TextID_Destroy(text_id);
    }
  }

  if (!standby_data->edit_visual)
    return;

  if (standby_data->edit_text)
  {
    wchar_t ustr[64];
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    int font_size = standby_data->temp.font_size;
    int font_style = font_size >> 8;
    switch (font_style)
    {
    case UIFontStylePlain:
      snwprintf(ustr,
                MAXELEMS(ustr),
                L"X:%d, Y:%d, Align:%ls Font:%d_R",
                standby_data->temp.XPos,
                standby_data->temp.YPos,
                Get_Align(standby_data->temp.align),
                font_size);
      break;
    case UIFontStyleBold:
      snwprintf(ustr,
                MAXELEMS(ustr),
                L"X:%d, Y:%d, Align:%ls Font:%d_B",
                standby_data->temp.XPos,
                standby_data->temp.YPos,
                Get_Align(standby_data->temp.align),
                font_get_height(font_size));
      break;
    case UIFontStyleItalic:
      snwprintf(ustr,
                MAXELEMS(ustr),
                L"X:%d, Y:%d, Align:%ls Font:%d_I",
                standby_data->temp.XPos,
                standby_data->temp.YPos,
                Get_Align(standby_data->temp.align),
                font_get_height(font_size));
      break;
    case UIFontStyleBoldItalic:
      snwprintf(ustr,
                MAXELEMS(ustr),
                L"X:%d, Y:%d, Align:%ls Font:%d_BI",
                standby_data->temp.XPos,
                standby_data->temp.YPos,
                Get_Align(standby_data->temp.align),
                font_get_height(font_size));
      break;
    }
#endif
    text_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
  }
  else
  {
    wchar_t ustr[64];
    snwprintf(ustr, MAXELEMS(ustr), L"X:%d, Y:%d", standby_data->temp.XPos, standby_data->temp.YPos);
    text_id = TextID_Create(ustr, ENC_UCS2, TEXTID_ANY_LEN);
  }

  DrawRect(0, 246, 240, 246 + font_get_height(FONT_E_18R) + 2, clBlack, 0x35FFFFFF);

  draw_string_no_style(FONT_E_18R, text_id, AlignCenter, 1, 248, 238, clBlack);
  TextID_Destroy(text_id);
}

int StatusRow_GetMax_Height()
{
  return DispObject_GetWindowHeight(*StatusRow_p());
}

int StatusIndication_GetMax_Height()
{
  return Display_GetHeight(UIDisplay_Main) - DispObject_GetWindowHeight(DispObject_SoftKeys_Get());
}

extern "C" void New_StatusRow_onRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  BOOK *pTopBook = Display_GetTopBook(UIDisplay_Main);
  if (BookObj_GetDisplayOrientation(pTopBook) != UIDisplayOrientationMode_Vertical)
    return;

  int WindowHeight = DispObject_GetWindowHeight(Display_GetFocusedDispObject(UIDisplay_Main));

  if (IsInStandby() || (WindowHeight < Display_GetHeight(UIDisplay_Main)))
  {
    DrawItemsOnScreen(0, StatusRow_GetMax_Height(), IsInStandby());
  }
}

extern "C" void New_StatusIndication_onRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  BOOK *pTopBook = Display_GetTopBook(UIDisplay_Main);
  int WindowHeight = DispObject_GetWindowHeight(Display_GetFocusedDispObject(UIDisplay_Main));

  if (BookObj_GetDisplayOrientation(pTopBook) == UIDisplayOrientationMode_Vertical)
  {
    if (IsInStandby() || (WindowHeight < Display_GetHeight(UIDisplay_Main)))
    {
      DrawItemsOnScreen(StatusRow_GetMax_Height(), StatusIndication_GetMax_Height(), IsInStandby());
    }
  }
  old_StatusIndication_onRedraw(disp_obj, a, b, c);
}

extern "C" void New_Softkeys_onRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
  BOOK *pTopBook = Display_GetTopBook(UIDisplay_Main);
  int WindowHeight = DispObject_GetWindowHeight(Display_GetFocusedDispObject(UIDisplay_Main));

  if (BookObj_GetDisplayOrientation(pTopBook) == UIDisplayOrientationMode_Vertical)
  {
    if (IsInStandby() || (WindowHeight < Display_GetHeight(UIDisplay_Main)))
    {
      DrawItemsOnScreen(StatusIndication_GetMax_Height(), Display_GetHeight(UIDisplay_Main), IsInStandby());
    }
  }
  old_Softkeys_onRedraw(disp_obj, a, b, c);
}

extern "C" int New_StatusIndication_onCreate(DISP_OBJ *disp_obj)
{
  old_StatusIndication_onCreate(disp_obj);

  STANDBY_DATA *standby_data = Get_StandbyData();
  standby_data->status_indication = disp_obj;
  standby_data->scr_w = Display_GetWidth(UIDisplay_Main);
  standby_data->scr_h = Display_GetHeight(UIDisplay_Main);
  LoadData(standby_data);

  standby_data->refresh_timer = Timer_Set(REFRESH_TIMER, MKTIMERPROC(update_redraw), standby_data);

  return 1;
}

extern "C" void New_StatusIndication_onClose(DISP_OBJ *disp_obj)
{
  STANDBY_DATA *standby_data = Get_StandbyData();

  if (standby_data->refresh_timer)
  {
    Timer_Kill(&standby_data->refresh_timer);
    standby_data->refresh_timer = 0;
  }

  mfree(standby_data->status_indication);
  mfree(standby_data->battery_data);
  mfree(standby_data->now);
  mfree(standby_data->temp_date);

  old_StatusIndication_onClose(disp_obj);
}

extern "C" void New_MainInput_onKey(DISP_OBJ *disp_obj, int key, int count, int repeat, int mode)
{
  StandbyBook *standby_book = (StandbyBook *)Find_StandbyBook();

  STANDBY_DATA *standby_data = Get_StandbyData();
  if (!standby_data)
  {
    old_MainInput_onKey(disp_obj, key, count, repeat, mode);
    return;
  }

  if (standby_data->flag == FALSE)
  {
    if (mode == KBD_SHORT_PRESS)
    {
      if (key == KEY_DIGITAL_0)
      {
        standby_data->count += 1;
      }
      else if (key == KEY_UP && standby_data->settings.music.state)
      {
        standby_data->widget_mode = TRUE;
        standby_data->flag = TRUE;
        standby_data->count = 0;
        return;
      }
      else
      {
        standby_data->count = 0;
      }
    }
  }

  if (standby_data->widget_mode && (MainInput_strlen(standby_book->MainInput) == 0))
  {
    if (mode == KBD_SHORT_PRESS)
    {
      if (key == KEY_LEFT)
      {
        if ((--standby_data->widget_pos) < POS_1)
          standby_data->widget_pos = POS_3;
      }
      else if (key == KEY_RIGHT)
      {
        if (++standby_data->widget_pos > POS_3)
          standby_data->widget_pos = POS_1;
      }
      else if (key == KEY_DOWN)
      {
        standby_data->flag = FALSE;
        standby_data->widget_mode = FALSE;
      }
      else if (key == KEY_DEL)
      {
        WidgetAction(standby_data->widget_pos);
      }
    }
  }

  if (standby_data->count < SECRET_CODES)
  {
    standby_data->edit_mode = FALSE;
    old_MainInput_onKey(disp_obj, key, count, repeat, mode);
  }
  else
  {
    standby_data->edit_mode = TRUE;
    if (standby_data->flag == FALSE)
    {
      MainInput_Hide(standby_book->MainInput);
      standby_data->flag = TRUE;
      CreateMessageBox(EMPTY_TEXTID, STR("Edit Mode"), 0, 1000, standby_book);
      return;
    }

    if ((mode == KBD_SHORT_PRESS) || (mode == KBD_REPEAT))
    {
      standby_data->cstep = 1;
      if (mode == KBD_REPEAT && repeat > 5)
        standby_data->cstep = 5;

      switch (key)
      {
      case KEY_UP:
        if (standby_data->edit_text)
        {
          if (++standby_data->cur_pos >= standby_data->total_fonts)
            standby_data->cur_pos = 0;
        }
        else if (standby_data->edit_icon || standby_data->edit_status)
        {
          if (standby_data->temp.YPos > 0)
          {
            standby_data->temp.YPos -= standby_data->cstep;
            if (standby_data->edit_text)
              standby_data->temp.MaxHeight = standby_data->temp.YPos + standby_data->temp.Height;
          }
        }
        break;
      case KEY_DOWN:
        if (standby_data->edit_text)
        {
          if ((--standby_data->cur_pos) < 0)
            standby_data->cur_pos = standby_data->total_fonts - 1;
        }
        else if (standby_data->edit_icon || standby_data->edit_status)
        {
          if (standby_data->temp.YPos < (standby_data->scr_h - 1))
          {
            standby_data->temp.YPos += standby_data->cstep;
            if (standby_data->edit_text)
              standby_data->temp.MaxHeight = standby_data->temp.YPos + standby_data->temp.Height;
          }
        }
        break;
      case KEY_LEFT:
        if (standby_data->edit_icon || standby_data->edit_status)
        {
          if (standby_data->temp.XPos > 0)
            standby_data->temp.XPos -= standby_data->cstep;
        }
        break;
      case KEY_RIGHT:
        if (standby_data->edit_icon || standby_data->edit_status)
        {
          if (standby_data->temp.XPos < (standby_data->scr_w - 1))
            standby_data->temp.XPos += standby_data->cstep;
        }
        break;
      case KEY_DIGITAL_0:
        if (standby_data->edit_text)
        {
          if (++standby_data->temp.highlight == HighlightLast)
            standby_data->temp.highlight = HighlightOff;
        }
        break;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
      case KEY_DIGITAL_1:
        if (standby_data->edit_text)
        {
          if (standby_data->temp.underline)
            standby_data->temp.underline = FALSE;
          else
            standby_data->temp.underline = TRUE;
        }
        break;
      case KEY_DIGITAL_3:
        if (standby_data->edit_text)
        {
          if (++standby_data->style > UIFontStyleBoldItalic)
            standby_data->style = UIFontStylePlain;
          switch (standby_data->style)
          {
          case UIFontStylePlain:
            standby_data->style_bold = FALSE;
            standby_data->style_italic = FALSE;
            break;
          case UIFontStyleBold:
            standby_data->style_bold = TRUE;
            standby_data->style_italic = FALSE;
            break;
          case UIFontStyleItalic:
            standby_data->style_bold = FALSE;
            standby_data->style_italic = TRUE;
            break;
          case UIFontStyleBoldItalic:
            standby_data->style_bold = TRUE;
            standby_data->style_italic = TRUE;
            break;
          }
        }
        break;
#endif
      case KEY_DIGITAL_5:
        standby_data->count = NULL;
        standby_data->flag = FALSE;
        standby_data->edit_mode = FALSE;
        standby_data->edit_visual = FALSE;
        standby_data->edit_text = FALSE;
        standby_data->edit_icon = FALSE;
        SaveData(TRUE, standby_data->selected_item);
        CreateMessageBox(EMPTY_TEXTID, STR("Saved"), 0, 1000, standby_book);
        Clear_TempData(standby_data);
        break;
      case KEY_DIGITAL_2:
        if (standby_data->temp.YPos > 0)
        {
          standby_data->temp.YPos -= standby_data->cstep;
          if (standby_data->edit_text)
            standby_data->temp.MaxHeight = standby_data->temp.YPos + standby_data->temp.Height;
        }
        break;
      case KEY_DIGITAL_8:
        if (standby_data->temp.YPos < (standby_data->scr_h - 1))
        {
          standby_data->temp.YPos += standby_data->cstep;
          if (standby_data->edit_text)
            standby_data->temp.MaxHeight = standby_data->temp.YPos + standby_data->temp.Height;
        }
        break;
      case KEY_DIGITAL_4:
        if (standby_data->temp.XPos > 0)
          standby_data->temp.XPos -= standby_data->cstep;
        break;
      case KEY_DIGITAL_6:
        if (standby_data->temp.XPos < (standby_data->scr_w - 1))
          standby_data->temp.XPos += standby_data->cstep;
        break;
      case KEY_DIGITAL_7:
        if (standby_data->edit_text || standby_data->edit_status)
        {
          if (++standby_data->temp.align > AlignCenter)
            standby_data->temp.align = AlignLeft;
        }
        break;
      case KEY_STAR:
        Create_ItemsEditor();
        break;
      case KEY_DIEZ:
        standby_data->count = NULL;
        standby_data->flag = FALSE;
        standby_data->edit_mode = FALSE;
        standby_data->edit_visual = FALSE;
        standby_data->edit_text = FALSE;
        standby_data->edit_icon = FALSE;
        LoadData(standby_data);
        CreateMessageBox(EMPTY_TEXTID, STR("Exit without saving"), 0, 1000, standby_book);
        Clear_TempData(standby_data);
        break;
      case KEY_DIGITAL_9:
        CreateMessageBox(EMPTY_TEXTID, STR(HELP_STRING), 0, 0, standby_book);
        break;
      }

      if (standby_data->edit_text)
      {
        standby_data->temp.font_size = ((standby_data->cur_pos + 1) * FONT_STEP) + (standby_data->style_bold << 8) + (standby_data->style_italic << 9);
        standby_data->font_style = standby_data->temp.font_size >> 8;

        standby_data->temp.MaxHeight = standby_data->temp.YPos + font_get_height(standby_data->temp.font_size);
      }

      if (mode == KBD_LONG_RELEASE)
      {
        standby_data->cstep = 1;
      }
      if (standby_data->edit_visual)
      {
        SaveData(FALSE, standby_data->selected_item);
      }
      invalidate_all(standby_data);
    }
  }
}

int status_item_cmp(void *item0, void *item1)
{
  return ((STATUS_ITEM_LIST *)item0)->image_id != ((STATUS_ITEM_LIST *)item1)->image_id;
}

void RemoveIcon(LIST *status_list, IMAGEID image_id)
{
  STATUS_ITEM_LIST temp_si;

  temp_si.image_id = image_id;
  int pos = List_Find(status_list, &temp_si, status_item_cmp);
  if (pos != LIST_ERROR)
  {
    STATUS_ITEM_LIST *si = (STATUS_ITEM_LIST *)List_RemoveAt(status_list, pos);
    mfree(si);
  }
}

#ifdef HAS_WLAN
void RemoveWLAN(LIST *status_list)
{
  RemoveIcon(status_list, WLAN_STATUSBAR_ON_ICN);
  RemoveIcon(status_list, WLAN_STATUSBAR_SEARCHING_ICN);
}
#endif

void Remove3G(LIST *status_list)
{
  RemoveIcon(status_list, C_UI_3G_ICN);
  RemoveIcon(status_list, C_UI_HSDPA_ICN);
  RemoveIcon(status_list, C_UI_HSUPA_ICN);
  RemoveIcon(status_list, C_UI_HSDPA_LOADING_ICN);
  RemoveIcon(status_list, C_UI_HSUPA_LOADING_ICN);
}

extern "C" bool New_SetTrayIcon(IMAGEID image_id, char state)
{
  if (image_id == NOIMAGE)
  {
    return FALSE;
  }

  STANDBY_DATA *standby_data = Get_StandbyData();

  if ((image_id >= C_UI_BATTERY_LEV9_ICN) && (image_id <= C_UI_BATTERY_LEV0_ICN))
  {
    if (state)
    {
      standby_data->current_battery = image_id;
    }
    return state;
  }

  if (image_id == C_UI_BATTERY_CHARGING_ICN)
  {
    standby_data->is_charging = state;
    return state;
  }

  if (((image_id >= C_UI_EDGE_ATT_LEV0_ICN) && (image_id <= C_UI_EDGE_ATT_LEV4_ICN)) ||
      ((image_id >= C_UI_EDGE_ATT_LEV5_ICN) && (image_id <= C_UI_EDGE_AVAIL_LEV4_ICN)) ||
      ((image_id >= C_UI_EDGE_AVAIL_LEV5_ICN) && (image_id <= C_UI_GPRS_ATT_LEV4_ICN)) ||
      ((image_id >= C_UI_GPRS_ATT_LEV5_ICN) && (image_id <= C_UI_GPRS_DET_LEV8_ICN)) ||
      ((image_id >= C_UI_RSSI_LEV0_ICN) && (image_id <= C_UI_RSSI_LEV1_ICN)) ||
      ((image_id >= C_UI_RSSI_LEV2_ICN) && (image_id <= C_UI_UMA_ATT_LEV1_ICN)) ||
      ((image_id >= C_UI_UMA_ATT_LEV2_ICN) && (image_id <= C_UI_UMA_ATT_LEV5_ICN)) ||
      (image_id == C_UI_GPRS_DET_LEV9_ICN) || (image_id == FMODE_RSSI_INDICATION_ICN))
  {
    if (state)
    {
      standby_data->current_network = image_id;
    }
    return state;
  }

  STATUS_ITEM_LIST temp_si;

  switch (image_id)
  {
    // 3G
  case C_UI_3G_ICN:
  case C_UI_HSDPA_ICN:
  case C_UI_HSDPA_LOADING_ICN:
  case C_UI_HSUPA_ICN:
  case C_UI_HSUPA_LOADING_ICN:
    Remove3G(standby_data->status_list);
    standby_data->status_was_changed = TRUE;
    break;
// WLAN
#ifdef HAS_WLAN
  case WLAN_STATUSBAR_ON_ICN:
  case WLAN_STATUSBAR_SEARCHING_ICN:
    RemoveWLAN(standby_data->status_list);
    mydata->status_was_changed = TRUE;
    break;
#endif
  }

  temp_si.image_id = image_id;
  int pos = List_Find(standby_data->status_list, &temp_si, status_item_cmp);
  if (state)
  {
    if (pos != LIST_ERROR)
    {
      return state;
    }
    STATUS_ITEM_LIST *si = (STATUS_ITEM_LIST *)malloc(sizeof(STATUS_ITEM_LIST));
    si->image_id = image_id;
    List_InsertLast(standby_data->status_list, si);
    standby_data->status_was_changed = TRUE;

    return state;
  }

  if (pos != LIST_ERROR)
  {
    STATUS_ITEM_LIST *si = (STATUS_ITEM_LIST *)List_RemoveAt(standby_data->status_list, pos);
    mfree(si);
    standby_data->status_was_changed = TRUE;
  }

  return state;
}
