/*
;Ability to move,show/hide items on standby
;(c) Ploik, BigHercules
;(e) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\FmRadio_Book.h"
#include "..\\include\book\MusicApplication_Book.h"

#include "cfg_items.h"
#include "Function.h"
#include "GetSignalQuality.h"
#include "StatusIndication.h"
#include "editor.h"

extern "C" char MySetTrayIcon(wchar_t iconID, char mode);

__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF,size,1,5,"sb_mem",0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,"sb_mem",0);
}

void InvalidateAll(MY_DATA* mydata)
{
    DISP_OBJ ** GUI_status = StatusRow_p();
    DISP_OBJ * GUI_display = mydata->Display_dobj;
    DISP_OBJ * GUI_soft = DispObject_SoftKeys_Get();
  
    if(GUI_display) DispObject_InvalidateRect(GUI_display,NULL);
    if(*GUI_status) DispObject_InvalidateRect(*GUI_status,NULL);
    if(GUI_soft) DispObject_InvalidateRect(GUI_soft,NULL);
}

void onTimer (u16 timerID , LPARAM n)
{
  MY_DATA* mydata = get_mydata();
  InvalidateAll(mydata);
  Timer_ReSet(&mydata->pTimer,INVALIDATE_ALL_TIME,onTimer,n);
}

extern "C"
void TimerRedrawRun(MY_DATA* mydata)
{
  if(mydata) mydata->pTimer = Timer_Set(INVALIDATE_ALL_TIME,onTimer,0);  
}

extern "C"
void TimerRedrawKill(MY_DATA* mydata)
{
  if(mydata)
  {
    if(mydata->pTimer)
    {
      Timer_Kill(&mydata->pTimer);
      mydata->pTimer = 0;
    }
  }
}

int CalcItemHeight(ITEM_DATA *item)
{
  if(item->TstImgID == NOIMAGE)
  {
    int font_old = SetFont(*(item->font));
    TEXTID strID = TextID_Create(L"STR",ENC_UCS2,3);
    *(item->h) = GetImageHeight(strID);
    TextID_Destroy(strID);
    SetFont(font_old);
  }
  else
  {
    *(item->h) = GetImageHeight(item->TstImgID);
  }
  return *(item->h);
}

void CalcIcnParam(ITEM_ICN_DATA *item_icn_data, int font, int align, wchar_t* test_str)
{
  int font_old = SetFont(font);
  int len = wstrlen(test_str);
  TEXTID strID = TextID_Create(test_str,ENC_UCS2,len);
  int height = Disp_GetTextIDHeight(strID);
  int width = Disp_GetTextIDWidth(strID,len);
  TextID_Destroy(strID);
  SetFont(font_old);
  
  item_icn_data->height = height;
  if(align == RIGHT)
  {
    item_icn_data->icn_offset = - width - height - 2;
    item_icn_data->txt_offset = 0;
  }
  else if(align == LEFT)
  {
    item_icn_data->icn_offset = 0;
    item_icn_data->txt_offset = height + 2;
  }
  else
  {
    item_icn_data->icn_offset = ((Display_Width - width - height) >> 1) - 1;
    item_icn_data->txt_offset = height + 4;
  }
}

void LoadIcon(wchar_t *pImageID, int type )
{
  switch(type)
  {
  case 1: *pImageID = ALARM_ICN; break;
  case 2: *pImageID = TIMER_ICN; break;
  case 3: *pImageID = CALL_ICN; break;
  }
}

void LiteUpdateParams(MY_DATA* mydata)
{
  for(int i=0; i<LAST_ITEM; i++)
  {
    *mydata->items[i].y_max = *mydata->items[i].y + CalcItemHeight(&mydata->items[i]);
  }

  mydata->items_cfg.status.y_max = 
      mydata->items_cfg.status.y + mydata->items_cfg.status.h * mydata->items_cfg.status.cfg.row_max;

  mydata->status_was_changed = 1;

}

#pragma segment = "CONFIG_C"
void init_items_cfg(ITEMS_DATA *items_cfg)
{
  void* cfg = ( char* )__segment_begin( "CONFIG_C" );
  unsigned int len = ( char* )__segment_end( "CONFIG_C" ) - ( char* )__segment_begin( "CONFIG_C" );
  memcpy( items_cfg, cfg, len );
}

#define INIT_ITEM(id,item) \
  mydata->items[id].name = mydata->items_cfg.##item.name; \
  mydata->items[id].show = &mydata->items_cfg.##item.cfg.show; \
  mydata->items[id].font = &mydata->items_cfg.##item.cfg.font; \
  mydata->items[id].highlight = &mydata->items_cfg.##item.cfg.highlight; \
  mydata->items[id].color = &mydata->items_cfg.##item.cfg.color; \
  mydata->items[id].border = &mydata->items_cfg.##item.cfg.border; \
  mydata->items[id].align = &mydata->items_cfg.##item.cfg.align; \
  mydata->items[id].x = &mydata->items_cfg.##item.x; \
  mydata->items[id].y = &mydata->items_cfg.##item.y; \
  mydata->items[id].y_max = &mydata->items_cfg.##item.y_max; \
  mydata->items[id].h = &mydata->items_cfg.##item.h; \
  mydata->items[id].w = &mydata->items_cfg.##item.w; \
  mydata->items[id].TstImgID = NOIMAGE

#define INIT_ICON(id,item,imageID) \
  mydata->items[id].name = mydata->items_cfg.##item.name; \
  mydata->items[id].show = &mydata->items_cfg.##item.cfg.show; \
  mydata->items[id].x = &mydata->items_cfg.##item.x; \
  mydata->items[id].y = &mydata->items_cfg.##item.y; \
  mydata->items[id].y_max = &mydata->items_cfg.##item.y_max; \
  mydata->items[id].h = &mydata->items_cfg.##item.h; \
  mydata->items[id].w = &mydata->items_cfg.##item.w; \
  mydata->items[id].TstImgID = imageID

#define INIT_STATUS(id,item,imageID) \
  mydata->items[id].name = mydata->items_cfg.##item.name; \
  mydata->items[id].show = &mydata->items_cfg.##item.cfg.show; \
  mydata->items[id].align = &mydata->items_cfg.##item.cfg.align; \
  mydata->items[id].x = &mydata->items_cfg.##item.x; \
  mydata->items[id].y = &mydata->items_cfg.##item.y; \
  mydata->items[id].y_max = &mydata->items_cfg.##item.y_max; \
  mydata->items[id].h = &mydata->items_cfg.##item.h; \
  mydata->items[id].w = &mydata->items_cfg.##item.w; \
  mydata->items[id].TstImgID = imageID

void init_items(MY_DATA* mydata)
{
  INIT_ITEM(TIME_ITEM,time);
  INIT_ITEM(TIME2_ITEM,time2);
  INIT_ITEM(DATE_ITEM,date);
  INIT_ITEM(DAY_ITEM,day);
  INIT_ITEM(ALARM_ITEM,alarm);
  INIT_ITEM(PROFILE_ITEM,profile);
  INIT_ITEM(HEAP_ITEM,heap);
  INIT_ITEM(TIMER_ITEM,timer);
  INIT_ITEM(CALL_ITEM,call);
  INIT_ITEM(SIGNAL_ITEM,signal);
  INIT_ITEM(OPERATOR_ITEM,oper);
  INIT_ITEM(BATT_ITEM,batt);
  INIT_ITEM(CHARGE_ITEM,charge);
  INIT_ITEM(BATTTEMP_ITEM,batttemp);
  INIT_ITEM(TEMP_ITEM,temp);
  INIT_ITEM(PHONEINFO_ITEM,phone);
  INIT_ITEM(CARDINFO_ITEM,card);

  INIT_ICON(NETICON_ITEM,neticon,C_UI_RSSI_LEV5_ICN);
  INIT_ICON(BATICON_ITEM,baticon,C_UI_BATTERY_LEV0_ICN);

  INIT_STATUS(STATUS_ITEM,status,SILENT_MODE_ICN);

  //INIT_ICON(STATUSBG_ITEM,statusbg,NOIMAGE);
  
  INIT_ITEM(MUSIC_ITEM,music);
  INIT_ITEM(RADIO_ITEM,radio);
}

/*
void init_statusbg(MY_DATA* mydata)
{
  FSTAT _fstat;
  if (fstat(L"/usb/other/ini",L"statusbar.png",&_fstat) >= NULL)
  {
    ImageID_Get(L"/usb/other/ini",L"statusbar.png",&mydata->StatusRowBG);
  }
  else
  {
    mydata->StatusRowBG = NOIMAGE;
  }
}
*/
MY_DATA* create_mydata()
{
  int f;
  FSTAT _fstat;
  int init = TRUE;

  MY_DATA* mydata = (MY_DATA*)malloc(sizeof(MY_DATA));
  memset(mydata,NULL,sizeof(MY_DATA));
  set_envp(NULL,MYDATAVARNAME,(OSADDRESS)mydata);

  if( fstat( MYDATAPATH, MYDATAFILE, &_fstat ) >= NULL )
  {
    if(_fstat.fsize == sizeof(ITEMS_DATA))
    {
      if( ( f = _fopen( MYDATAPATH, MYDATAFILE, FSX_O_RDONLY, FSX_S_IREAD|FSX_S_IWRITE, 0 ) ) >= NULL )
      {
        fread( f, &mydata->items_cfg, sizeof(ITEMS_DATA));
        fclose( f );
        init = FALSE;
      }
    }
  }
  if(init) init_items_cfg(&mydata->items_cfg);

  init_items(mydata);
  
  mydata->cur_item = -1;
  mydata->cnt  = NULL;
  mydata->flag = NULL;
  mydata->CallEnd = NULL;
  mydata->pTimer = NULL;
  mydata->status_list = List_Create();
  mydata->rowcnt = NULL;
  mydata->status_was_changed = TRUE;
  mydata->memcnt = MEMINFO_UPDATE_MAX_CNT + 1;

  mydata->CurrentIconIDNet = NOIMAGE;
  mydata->CurrentIconIDBatt = NOIMAGE;
  
  //init_statusbg(mydata);
  
  mydata->isCharging = NULL;

  for(int i=0; i<LAST_ITEM; i++)
    mydata->items_icons[i].icn = NOIMAGE;
    
  for(int i=0; i<STATUS_ICN_ROW_MAX; i++)
    mydata->status_icn_cnt[i] = 0;

  for(int i=0; i<STATUS_ICN_ROW_MAX; i++)
    for(int j=0; j<STATUS_ICN_COLUMN_MAX; j++)
      mydata->status_bar[i][j] = NOIMAGE;
  
  mydata->phone_memId = EMPTY_TEXTID;
  mydata->card_memId = EMPTY_TEXTID;

  return mydata;
}

MY_DATA* get_mydata()
{
  MY_DATA* mydata = (MY_DATA*)get_envp(NULL,MYDATAVARNAME);
  if(mydata) return mydata;
  return create_mydata();
}

void save_mydata(void)
{
  MY_DATA* mydata = get_mydata();
  int File;
  if( ( File = _fopen( MYDATAPATH, MYDATAFILE, FSX_O_TRUNC|FSX_O_RDWR, FSX_S_IREAD|FSX_S_IWRITE, 0 ) ) >= 0 )
  {
    fwrite( File, &mydata->items_cfg, sizeof(ITEMS_DATA));
    fclose( File );
  }
}

void SetCurrentItem(int item)
{
  MY_DATA* mydata = get_mydata();
  mydata->cur_item = item;
}

int GetCurrentItem()
{
  MY_DATA* mydata = get_mydata();
  return mydata->cur_item;
}

wchar_t* GetItemName(int item)
{
  MY_DATA* mydata = get_mydata();
  return mydata->items[item].name;
}

void *GetItemCfg(int item)
{
  MY_DATA* mydata = get_mydata();
  switch(item)
  {
  case TIME_ITEM:
    return &mydata->items_cfg.time.cfg;
  case TIME2_ITEM:
    return &mydata->items_cfg.time2.cfg;
  case DATE_ITEM:
    return &mydata->items_cfg.date.cfg;
  case DAY_ITEM:
    return &mydata->items_cfg.day.cfg;
  case ALARM_ITEM:
    return &mydata->items_cfg.alarm.cfg;
  case PROFILE_ITEM:
    return &mydata->items_cfg.profile.cfg;
  case HEAP_ITEM:
    return &mydata->items_cfg.heap.cfg;
  case TIMER_ITEM:
    return &mydata->items_cfg.timer.cfg;
  case CALL_ITEM:
    return &mydata->items_cfg.call.cfg;
  case SIGNAL_ITEM:
    return &mydata->items_cfg.signal.cfg;
  case OPERATOR_ITEM:
    return &mydata->items_cfg.oper.cfg;
  case BATT_ITEM:
    return &mydata->items_cfg.batt.cfg;
  case CHARGE_ITEM:
    return &mydata->items_cfg.charge.cfg;
  case BATTTEMP_ITEM:
    return &mydata->items_cfg.batttemp.cfg;    
  case TEMP_ITEM:
    return &mydata->items_cfg.temp.cfg;    
  case PHONEINFO_ITEM:
    return &mydata->items_cfg.phone.cfg;    
  case CARDINFO_ITEM:
    return &mydata->items_cfg.card.cfg;
  case NETICON_ITEM:
    return &mydata->items_cfg.neticon.cfg;
  case BATICON_ITEM:
    return &mydata->items_cfg.baticon.cfg;
  case STATUS_ITEM:
    return &mydata->items_cfg.status.cfg;
  //case STATUSBG_ITEM:
    //return &mydata->items_cfg.statusbg.cfg;
  case MUSIC_ITEM:
    return &mydata->items_cfg.music.cfg;
  case RADIO_ITEM:
    return &mydata->items_cfg.radio.cfg;
  }
  return 0;
}

int GetItemCfgSize(int item)
{
  switch(item)
  {
  case TIME_ITEM:
    return sizeof(cfg_time_t);
  case TIME2_ITEM:
    return sizeof(cfg_time_t);
  case DATE_ITEM:
    return sizeof(cfg_text_t);
  case DAY_ITEM:
    return sizeof(cfg_day_t);
  case ALARM_ITEM:
    return sizeof(cfg_text_t);
  case PROFILE_ITEM:
    return sizeof(cfg_text_t);
  case HEAP_ITEM:
    return sizeof(cfg_heap_t);
  case TIMER_ITEM:
    return sizeof(cfg_text_t);
  case CALL_ITEM:
    return sizeof(cfg_text_t);
  case SIGNAL_ITEM:
    return sizeof(cfg_signal_t);
  case OPERATOR_ITEM:
    return sizeof(cfg_text_t);
  case BATT_ITEM:
    return sizeof(cfg_text_t);
  case CHARGE_ITEM:
    return sizeof(cfg_text_t);
  case BATTTEMP_ITEM:
    return sizeof(cfg_batttemp_t);
  case TEMP_ITEM:
    return sizeof(cfg_text_t);
  case PHONEINFO_ITEM:
    return sizeof(cfg_meminfo_t);
  case CARDINFO_ITEM:
    return sizeof(cfg_meminfo_t);
  case NETICON_ITEM:
    return sizeof(cfg_img_t);
  case BATICON_ITEM:
    return sizeof(cfg_img_t);
  case STATUS_ITEM:
    return sizeof(cfg_status_t);
  //case STATUSBG_ITEM:
    //return sizeof(cfg_img_t);
  case MUSIC_ITEM:
    return sizeof(cfg_music_t);
  case RADIO_ITEM:
    return sizeof(cfg_radio_t);
  }
  return 0;
}

void DrawStr(int Font, TEXTID text_id, int UITextAlignment_t, int XPos, int YPos, int MaxXPos, int MaxYPos, int borderColor, int NormalColor)
{
  SetFont(Font);
  DrawString(text_id,UITextAlignment_t,XPos,YPos,MaxXPos,MaxYPos,0,1,NormalColor,NormalColor);
}

void DrawHighlightStrV1(int Font, TEXTID text_id, int UITextAlignment_t, int XPos, int YPos, int MaxXPos, int MaxYPos, int borderColor, int NormalColor)
{
  SetFont(Font);
  DrawString(text_id,UITextAlignment_t,XPos-1,YPos-1,MaxXPos-1,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos-1,YPos+1,MaxXPos-1,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos+1,YPos-1,MaxXPos+1,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos+1,YPos+1,MaxXPos+1,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos,YPos,MaxXPos,MaxYPos,0,1,NormalColor,NormalColor);
}

void DrawHighlightStrV2(int Font, TEXTID text_id, int UITextAlignment_t, int XPos, int YPos, int MaxXPos, int MaxYPos, int borderColor, int NormalColor)
{
  SetFont(Font);
  DrawString(text_id,UITextAlignment_t,XPos+1,YPos,MaxXPos,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos,YPos+1,MaxXPos,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos-1,YPos,MaxXPos,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos,YPos-1,MaxXPos,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos,YPos,MaxXPos,MaxYPos,0,1,NormalColor,NormalColor);
}

void DrawShadowStr(int Font, TEXTID text_id, int UITextAlignment_t, int XPos, int YPos, int MaxXPos, int MaxYPos, int borderColor, int NormalColor)
{
  SetFont(Font);
  DrawString(text_id,UITextAlignment_t,XPos+1,YPos+1,MaxXPos,MaxYPos,0,1,borderColor,borderColor);
  DrawString(text_id,UITextAlignment_t,XPos,YPos,MaxXPos,MaxYPos,0,1,NormalColor,NormalColor);
}

void CustomDrawString(int Font, TEXTID text_id, int UITextAlignment_t, int XPos, int YPos, int MaxXPos, int MaxYPos, int borderColor, int NormalColor, int type)
{
  //Overlay type
  switch(type){
  case 1: //Full v1
    DrawHighlightStrV1(Font, text_id, UITextAlignment_t,  XPos, YPos, MaxXPos, MaxYPos, borderColor, NormalColor);
    break;
  case 2: //Full v2
    DrawHighlightStrV2(Font, text_id, UITextAlignment_t,  XPos, YPos, MaxXPos, MaxYPos, borderColor, NormalColor);
    break;
  case 3: //Shadow
    DrawShadowStr(Font, text_id, UITextAlignment_t,  XPos, YPos, MaxXPos, MaxYPos, borderColor, NormalColor);
    break;
  default: //No
    DrawStr(Font, text_id, UITextAlignment_t,  XPos, YPos, MaxXPos, MaxYPos, borderColor, NormalColor);
  }
}

int timecmp(const TIME *t1, const TIME *t2)
{
  if(t1->hour > t2->hour) return 1;
  if(t1->hour < t2->hour) return -1;
  if(t1->min > t2->min) return 1;
  if(t1->min < t2->min) return -1;
  return 0;
}

int Alarm_GetCurrentAlarmTime(TIME *AlarmTime)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  
  int status = -1;

  AlarmTime->hour = AlarmTime->min = 0;
 
  wchar_t ID;
  char type;
  WEEK wk;
  DATETIME dt;
  
  if((status = Alarm_GetCurrentTypeAndAlarmID(&type, &ID)) >= 0)
  {
    if((status = Alarm_GetTIME(AlarmTime, ID)) >= 0)
    {
      if(type == 0)
      {
        if((status = Alarm_GetWeekSettings(&wk, ID)) >= 0)
        {
          char WeekDay, nextWeekDay;
          REQUEST_DATEANDTIME_GET(SYNC,&dt);

          DATE_GetWeekDay(&dt.date, &WeekDay);

          nextWeekDay = WeekDay + 1;
          if(nextWeekDay > 6) nextWeekDay = 0;

          if(wk.days[WeekDay])
          {
            if(!wk.days[nextWeekDay])
            {
              if(timecmp(&dt.time, AlarmTime) >= 0) status = -1;
            }
          }
          else
          {
            if(wk.days[nextWeekDay])
            {
              if(timecmp(&dt.time, AlarmTime) < 0) status = -1;
            }
            else status = -1;
          }
        }
      }
      else if(type != 1)
      {
        status = -1;
      }
    }
  }
  return status;
}

void DrawItem(ITEM_DATA *item, TEXTID text_id, int y)
{
  if(*item->align == RIGHT)
    CustomDrawString(*item->font,
                     text_id,
                     *item->align,
                     1, *item->y - y,
                     *item->x, Display_Height,
                     *item->border, *item->color,
                     *item->highlight);
  else
    CustomDrawString(*item->font,
                     text_id,
                     *item->align,
                     *item->x, *item->y - y,
                     Display_Width, Display_Height,
                     *item->border, *item->color,
                     *item->highlight);
}

void DrawItemWithIcon(ITEM_DATA *item, ITEM_ICN_DATA *item_icn, TEXTID text_id, int y)
{
  GC* pGC = get_DisplayGC();
  
  if(*item->align == RIGHT)
    CustomDrawString(*item->font,
                     text_id,
                     *item->align,
                     1, *item->y - y,
                     *item->x + item_icn->txt_offset, Display_Height,
                     *item->border, *item->color,
                     *item->highlight);
  else
    CustomDrawString(*item->font,
                     text_id,
                     *item->align,
                     *item->x + item_icn->txt_offset, *item->y - y, 
                     Display_Width, Display_Height,
                     *item->border, *item->color,
                     *item->highlight);
  
  if(*item->align == CENTER)
    GC_PutChar(pGC,
               (*item->x >> 1) + item_icn->icn_offset, *item->y - y, 
               item_icn->height, item_icn->height,
               item_icn->icn);
  else
    GC_PutChar(pGC,
               *item->x + item_icn->icn_offset, *item->y - y,
               item_icn->height, item_icn->height,
               item_icn->icn);
}
  
void FreeStatusRow(void)
{
  MY_DATA* mydata = get_mydata();
  int row = mydata->rowcnt;
  mydata->rowcnt = NULL;
  if(row)
  {
     for(int i=0; i<row; i++)
     {
       mydata->status_icn_cnt[i] = NULL;
     }
  }
}

void UpdateStatusInfo(void)
{
  MY_DATA* mydata = get_mydata();
  
  if(!mydata->status_was_changed) return;
  mydata->status_was_changed = 0;
  
  LIST* status_list = mydata->status_list;

  FreeStatusRow();
  if(status_list->FirstFree)
  {
    STATUS_ITEM_LIST * si;
    int indx;
    int i = 0;
    int j = 0;
    int rowcnt_tmp = 0;
    
    int column_max = mydata->items_cfg.status.cfg.column_max;
    int row_max = mydata->items_cfg.status.cfg.row_max;

    if(mydata->items_cfg.status.cfg.fill_by_row)
    {
      for (indx=0; indx<status_list->FirstFree; indx++)
      {
        si = (STATUS_ITEM_LIST*)List_Get(status_list,indx);
        mydata->status_bar[i][j++] = si->iconID;
        if(j >= column_max)
        {
          mydata->status_icn_cnt[i++] = j;
          j = 0;
          ++rowcnt_tmp;
          if(i >= row_max) break;
        }
      }
      if(j)
      {
        mydata->status_icn_cnt[i++] = j;
        ++rowcnt_tmp;
      }
      mydata->rowcnt = rowcnt_tmp;
    }
    else
    {
      for (indx=0; indx<status_list->FirstFree; indx++)
      {
        si = (STATUS_ITEM_LIST*)List_Get(status_list,indx);
        mydata->status_bar[i][j] = si->iconID;
        mydata->status_icn_cnt[i++] += 1;
        if(i >= row_max)
        {
          i = 0;
          ++j;
        }
        if(rowcnt_tmp < row_max) ++rowcnt_tmp;
        else if(j >= column_max) break;
      }
      mydata->rowcnt = rowcnt_tmp;
    }
  }
}

TEXTID GetMemInfo(cfg_meminfo_t *mem, wchar_t* root_folder)
{
  int data;
  TEXTID memInfo[3];
  
#ifdef DB3150v1
  VOLUMESIZE vol;
  TUnsigned Full,Free,Info;
  
  GetVolumeSize(root_folder, &vol);
  Full = (unsigned int)vol.TotalSpace;
  Free = (unsigned int)vol.FreeSpace;
#elif DB3150
  VOLUMESIZE_A2 vol;
  long long Full,Free,Info;
  
  GetVolumeSize(root_folder, &vol);
  Full = vol.TotalSpace;
  Free = vol.FreeSpace;    
#endif
  
  memInfo[0] = TextID_Create(mem->msg, ENC_UCS2, TEXTID_ANY_LEN);
    
  if(mem->type == FREE_MEM)
    Info = Free;
  else
    Info = Full - Free;

  switch(mem->format){
  case MEM_PERCENT:
    if(Full == 0) Full = 1;
    data = ((Info*100)/Full);
    memInfo[2] = TextID_Create(L"%%",ENC_UCS2,1);
    break;
  case MEM_MB:
    data = (Info/1024/1024);
    memInfo[2] = TextID_Create(L"MB",ENC_UCS2,2);
    break;
  default:
    data = (Info/1024/1024/1024);
    memInfo[2] = TextID_Create(L"GB",ENC_UCS2,2);
  }
  memInfo[1] = TextID_CreateIntegerID(data);
  return TextID_Create(memInfo,ENC_TEXTID,3);
}

void UpdateMemInfo(MY_DATA* mydata)
{
  if(mydata->memcnt++ < MEMINFO_UPDATE_MAX_CNT) return;
  mydata->memcnt = 0;
    
  TEXTID memInfo;
  cfg_meminfo_t *mem;
  
  
  //--------[ Card ]------------------
  mem = &mydata->items_cfg.card.cfg;
  if(mem->show)
  {
    memInfo = GetMemInfo(mem,L"/card");
    if(mydata->card_memId != EMPTY_TEXTID)  TextID_Destroy(mydata->card_memId);
    mydata->card_memId = memInfo;
  }
  //--------[ Phone ]------------------
  mem = &mydata->items_cfg.phone.cfg;
  if(mem->show)
  {
    memInfo = GetMemInfo(mem,L"/tpa");
    if(mydata->phone_memId != EMPTY_TEXTID)  TextID_Destroy(mydata->phone_memId);
    mydata->phone_memId = memInfo;
  }
}

void DrawIcon(int x, int y, IMAGEID img)
{
  if(img!=NOIMAGE) GC_DrawIcon(x,y,img);
}

void DrawIconsString(int align, int x, int y, wchar_t *icons, int len, int width)
{
  //GC* pGraphicCanvas = get_DisplayGC();
  
  if(align == LEFT)
  {
    int new_x = x;
    for(int i=0; i<len; i++)
    {
      //GC_PutChar(pGraphicCanvas, new_x, y, 0, 0, icons[i]);
      DrawIcon(new_x, y, icons[i]);
      new_x = new_x + width;
    }
  }
  else if(align == RIGHT)
  {
    int new_x = x - width;
    for(int i=len-1; i>=0; i--)
    {
      //GC_PutChar(pGraphicCanvas, new_x, y, 0, 0, icons[i]);
      DrawIcon(new_x, y, icons[i]);
      new_x = new_x - width;
    }
  }
  else
  {
    int full_width = len * width;
    int new_x = x + ((Display_Width - x - full_width) >> 1);
    for(int i=0; i<len; i++)
    {
      //GC_PutChar(pGraphicCanvas, new_x, y, 0, 0, icons[i]);
      DrawIcon(new_x, y, icons[i]);
      new_x = new_x + width;
    }
  }
}

/*
bool isTagEmpty (wchar_t *tag)
{
  if (wstrlen(tag) == 43) return TRUE;
  return FALSE;
}
*/
void DrawParams(int y, int y_max, int isStandby)
{
  int _SYNC = NULL;
  int *SYNC = &_SYNC;
  DATETIME dt;
  BATT batt;
  
  //GC *GC_DISP = get_DisplayGC ();
  MY_DATA* mydata = get_mydata();
  if(mydata)
  {
    ITEM_DATA *item;
    ITEM_ICN_DATA *item_icn;
    int EditMode = mydata->EditMode;

    REQUEST_DATEANDTIME_GET(SYNC,&dt);
    GetBatteryState(SYNC,&batt);

    UpdateMemInfo(mydata);
    
    /*
    //Statusrow Background
    item = &mydata->items[STATUSBG_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        GC_PutChar(GC_DISP, *item->x, *item->y - y, 0, 0, mydata->StatusRowBG);
      }
    }
    */

    //Statusrow icon
    item = &mydata->items[STATUS_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        char state;
        REQUEST_SETTING_ALLOWEDCALLERS_GET(SYNC,-2,&state);
        MySetTrayIcon(CUSTOM_CALLERSFROMLIST_ICN, (state == 1));
        MySetTrayIcon(CUSTOM_NONECALLERS_ICN, (state == 2));
        
        Settings_ShowNumber_Get(&state);
        //0 - Задано сетью //1 - Скрыть номер //2 - Показать номер
        //  MySetTrayIcon(CUSTOM_BY_NET_NUM_ICN, (state == 0));
        MySetTrayIcon(CUSTOM_HIDE_NUM_ICN, (state == 1));
        // MySetTrayIcon(CUSTOM_SHOW_NUM_ICN, (state == 2));
        
        //-------------USB Connected---------------
        int USB_CABLE_ICN;
#ifdef DB3150v1
        iconidname2id( L"USB_CABLE_ICN", -1, &USB_CABLE_ICN);
#else
        iconidname2id( L"USB_MEDIA_TRANSFER_ICN", -1, &USB_CABLE_ICN);
#endif
        MySetTrayIcon( USB_CABLE_ICN, USB_isConnected() );
        //--------------------------------------

        UpdateStatusInfo();
        if(mydata->rowcnt)
        {
          int offset = 0 - y;
          for(int i=0; i<mydata->rowcnt; i++)
          {
            DrawIconsString(*item->align, *item->x, *item->y + offset, &mydata->status_bar[i][0], mydata->status_icn_cnt[i], STATUS_ICN_WIDTH);
            offset += STATUS_ICN_HEIGHT + STATUS_ICN_STEP;
          }
        }
      }
    }

    //Signal Icon
    item = &mydata->items[NETICON_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        //GC_PutChar(GC_DISP, *item->x, *item->y - y, 0, 0, mydata->CurrentIconIDNet);
        DrawIcon( *item->x, *item->y - y, mydata->CurrentIconIDNet );
      }
    }
    
    //Battery Icon
    item = &mydata->items[BATICON_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        //GC_PutChar(GC_DISP, *item->x, *item->y - y, 0, 0, mydata->CurrentIconIDBatt);
        DrawIcon( *item->x, *item->y - y, mydata->CurrentIconIDBatt );
        if((batt.ChargingState == 2) || (batt.ChargingState == 8))
        {
          //GC_PutChar(GC_DISP, *item->x, *item->y - y, 0, 0, C_UI_BATTERY_CHARGING_ICN);
          DrawIcon( *item->x, *item->y - y, C_UI_BATTERY_CHARGING_ICN );
        }
      }
    }

    //Current charging
    item = &mydata->items[CHARGE_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        int currentID;
        
        if((batt.ChargingState == 2/*Charge*/) || (batt.ChargingState == 8/*Completed*/) || (EditMode))
        {
          wchar_t curr[10];
          snwprintf(curr,MAXELEMS(curr),L"%d mA",batt.ChargerCurrent);
          currentID = TextID_Create(curr,ENC_UCS2,MAXELEMS(curr));
          DrawItem(item, currentID, y);
          TextID_Destroy(currentID);
        }
      }
    }
    
    //Battery Temperature
    item = &mydata->items[BATTTEMP_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID batttemptID;
        if((!mydata->items_cfg.batttemp.cfg.in_charge) || (batt.ChargingState == 2) || (batt.ChargingState == 8) || (EditMode))
        {
          wchar_t batt_temp[10];
          int BattTemp=(int)batt.BatteryTemperature;
          snwprintf(batt_temp,MAXELEMS(batt_temp)-1,L"%d%°C", BattTemp);
          batttemptID = TextID_Create(batt_temp,ENC_UCS2,MAXELEMS(batt_temp));
          DrawItem(item, batttemptID, y);
          TextID_Destroy(batttemptID);
        }
      }
    }

    //Time
    item = &mydata->items[TIME_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        char TF;
        TEXTID SIDtime;
        REQUEST_TIMEFORMAT_GET(SYNC, &TF);
        SIDtime=Time2ID(&dt.time,TF,mydata->items_cfg.time.cfg.isSec);
        DrawItem(item, SIDtime, y);
        TextID_Destroy(SIDtime);
      }
    }

    //Time 2
    item = &mydata->items[TIME2_ITEM];
    if((*item->show && !isStandby) || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        char TF;
        TEXTID SIDtime;
        REQUEST_TIMEFORMAT_GET(SYNC, &TF);
        SIDtime=Time2ID(&dt.time,TF,mydata->items_cfg.time2.cfg.isSec);
        DrawItem(item, SIDtime, y);
        TextID_Destroy(SIDtime);
      }
    }
    
    //Date
    item = &mydata->items[DATE_ITEM];
    if(*item->show || EditMode)
    {      
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        char DF;
        TEXTID SIDtime;
        REQUEST_DATEFORMAT_GET(SYNC, &DF);
        SIDtime=Date2ID(&dt.date,DF,1);
        DrawItem(item, SIDtime, y);
        TextID_Destroy(SIDtime);
      }
    }
    
    //Weekday
    item = &mydata->items[DAY_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID SIDtime;
        
        const int days[7]={TEXTID_1,TEXTID_2,TEXTID_3,TEXTID_4,TEXTID_5,TEXTID_6,TEXTID_7};
        const int daysf[7]={TEXTID_F_1,TEXTID_F_2,TEXTID_F_3,TEXTID_F_4,TEXTID_F_5,TEXTID_F_6,TEXTID_F_7};
        
        char weekday;
        DATE_GetWeekDay(&dt.date,&weekday);
        
        if(mydata->items_cfg.day.cfg.mode) 
        {
          SIDtime=daysf[weekday];
          DrawItem(item, SIDtime, y);
          TextID_Destroy(SIDtime);
        } else 
        {
          SIDtime=days[weekday];
          DrawItem(item, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
      }
    }
    
    //Alarm
    item = &mydata->items[ALARM_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TIME alarm;
        TEXTID alarmID;
        if((Alarm_GetCurrentAlarmTime(&alarm) >= 0)  || EditMode)
        {
          wchar_t alarm_msg[11];
          item_icn = &mydata->items_icons[ALARM_ITEM];
          LoadIcon(&item_icn->icn, ALARM );
          CalcIcnParam(item_icn, *item->font, *item->align, L"00:00");
          snwprintf(alarm_msg,10,L"%02d:%02d", alarm.hour, alarm.min);
          alarmID = TextID_Create(alarm_msg,ENC_UCS2,5);
          DrawItemWithIcon(item, item_icn, alarmID, y);
          TextID_Destroy(alarmID);
        }
      }
    }
    
    //Profile
    item = &mydata->items[PROFILE_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        int num;
        TEXTID name;
        TEXTID_DATA GetProfile;
        wchar_t SetName[0x10];
        char error;
        GetProfile.ptr=SetName;
  
        REQUEST_PROFILE_GETACTIVEPROFILE( SYNC, &num );
        REQUEST_PROFILE_GETPROFILENAME( SYNC,-2, &GetProfile, &error );
  
        if(num > 0)
        {
          name=TextID_Create(GetProfile.ptr,ENC_UCS2,GetProfile.lenght);
          DrawItem(item, name, y);
          TextID_Destroy(name);
        }
        else if(EditMode)
        {
          name = TextID_Create(L"Profile",ENC_UCS2,7);
          DrawItem(item, name, y);
          TextID_Destroy(name);
        }
      }
    }
    
    //Free HEAP
    item = &mydata->items[HEAP_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID heapID;
        wchar_t uHeap[16];
        int intHeap = GetFreeBytesOnHeap();
        if(mydata->items_cfg.heap.cfg.format)
        {
          int mb = intHeap/1024/1024;
          int kb = ((intHeap - (mb*1024*1024))*100)/1024/1024;
          snwprintf(uHeap,9,L"%d.%d%MB", mb, kb);
        }
        else
        {
          snwprintf(uHeap,9,L"%dKB",intHeap/1024);
        }
        heapID = TextID_Create(uHeap,ENC_UCS2,TEXTID_ANY_LEN);
        DrawItem(item, heapID, y);
        TextID_Destroy(heapID);
      }
    }
    
    //Timer
    item = &mydata->items[TIMER_ITEM];
    if(*item->show || EditMode)
    {      
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID SIDtime;
        item_icn = &mydata->items_icons[TIMER_ITEM];
        if(FindBook((IS_NEEDED_BOOK)isTimerBook))
        {
          LoadIcon(&item_icn->icn, TIMER );
          CalcIcnParam(item_icn, *item->font, *item->align, L"00:00:00");
          TIME timer;
          GetTimerTime(&timer);
          wchar_t timer_msg[9];
          snwprintf(timer_msg,8,L"%02d:%02d:%02d", timer.hour, timer.min, timer.sec);
          SIDtime = TextID_Create(timer_msg,ENC_UCS2,8);
          DrawItemWithIcon(item, item_icn, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
        else if(EditMode)
        {
          LoadIcon(&item_icn->icn, TIMER );
          CalcIcnParam(item_icn, *item->font, *item->align, L"00:00:00");
          SIDtime = TextID_Create(L"01:23:45",ENC_UCS2,8);
          DrawItemWithIcon(item, item_icn, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
      }
    }
    
    //Call time
    item = &mydata->items[CALL_ITEM];
    if(*item->show || EditMode)
    {      
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID SIDtime;
        item_icn = &mydata->items_icons[CALL_ITEM];
        if(mydata->CallEnd == 1)
        {
          LoadIcon(&item_icn->icn, CALLS );
          CalcIcnParam(item_icn, *item->font, *item->align, L"00:00");
          CALLINFO info;
          signed char error;
          CallInfo_Get(SYNC, 1, &info, &error);
      
          wchar_t call_msg[11];
          snwprintf(call_msg,10,L"%02d:%02d", info.time.min, info.time.sec);
          SIDtime = TextID_Create(call_msg,ENC_UCS2,5);
          DrawItemWithIcon(item, item_icn, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
        else if(EditMode)
        {
          LoadIcon(&item_icn->icn, CALLS );
          CalcIcnParam(item_icn, *item->font, *item->align, L"00:00");
          SIDtime = TextID_Create(L"01:23",ENC_UCS2,5);
          DrawItemWithIcon(item, item_icn, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
      }
    }     
    
     //Signal strenght
    item = &mydata->items[SIGNAL_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID rssiID;
        char ber;
        char rssi = 110;
        GetSignalQuality_dll(&rssi, &ber);

        if(( (rssi<99) && FlightMode_GetState()==FALSE || EditMode))
        {
          int inp = rssi-113;
          if(mydata->items_cfg.signal.cfg.show_dbm)
          {
            int rssi_id[2];
            rssi_id[0] = TextID_CreateIntegerID(inp);
            rssi_id[1] = TextID_Create(" dBm", ENC_GSM, 4);      
            rssiID = TextID_Create(rssi_id, ENC_TEXTID, 2);
          }
          else
          {
            rssiID = TextID_CreateIntegerID(inp);
          }
          DrawItem(item, rssiID, y);
          TextID_Destroy(rssiID);
        }
      }
    }
    
    //Operator name
    item = &mydata->items[OPERATOR_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID name;
        if(FlightMode_GetState())  
        {
          name = TextID_Create(L"Flight Mode", ENC_UCS2, TEXTID_ANY_LEN);
          
        } else 
        {
          //wchar_t buff[128];
          //name = GetOperatorName(buff);
          name = GetCurName();
        }
        DrawItem(item, name, y);
        TextID_Destroy(name);
      }
    }
    
    //Battery Percent
    item = &mydata->items[BATT_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID battID;
        int batt_id[2];
        batt_id[0] = TextID_CreateIntegerID((int)batt.RemainingCapacityInPercent);
        batt_id[1] = TextID_Create("%", ENC_GSM, 1);      
        battID = TextID_Create(batt_id, ENC_TEXTID, 2);
        DrawItem(item, battID, y);
        TextID_Destroy(battID);
      }
    }
    
    //System Temp
    item = &mydata->items[TEMP_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID TempID;
        wchar_t temp_msg[11];
        snwprintf(temp_msg,10,L"%d°C",batt.SystemTemperature);
        TempID = TextID_Create(temp_msg,ENC_UCS2,4);
        DrawItem(item, TempID, y);
        TextID_Destroy(TempID);
      }
    }

    //Phone mem
    item = &mydata->items[PHONEINFO_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        DrawItem(item, mydata->phone_memId, y);
      }
    }

    //Mem card
    item = &mydata->items[CARDINFO_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        DrawItem(item, mydata->card_memId, y);
      }
    }
    
    //WALKMAN
    item = &mydata->items[MUSIC_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID SIDtime;
        MusicApplication_Book* MusicBook = (MusicApplication_Book*)FindBook(IsAudioPlayerBook);
        if(MusicBook)
        {
          wchar_t music_buf[512];
          FILEITEM *f_item = MusicBook->sub_exec->file_item;
          
          wchar_t* path = FILEITEM_GetPath(f_item);
          wchar_t* name = FILEITEM_GetFname(f_item);
          
          wchar_t* artist = MetaData_GetTags(path, name, TAG_ARTIST);
          wchar_t* title = MetaData_GetTags(path, name, TAG_TITLE);
          //wchar_t album[128];
          //MusicBook->pMusicServer->GetItem(MusicBook->current_track_id,128,artist,album,title);
          
          wchar_t* unk_artist = L"Unknown Artist";
          //if(wstrlen(title)==43) wstrcpy(title,name);

          if(mydata->items_cfg.music.cfg.format == MUSIC_TITLE_ARTIST)
          {
            if(artist && title)
            {
              if(mydata->items_cfg.music.cfg.first==TRUE)
              {
                snwprintf(music_buf,MAXELEMS(music_buf),L"%ls - %ls", title, artist);
              }
              else
              {
                snwprintf(music_buf,MAXELEMS(music_buf),L"%ls - %ls", artist, title);
              }
              mfree(title);
              mfree(artist);
            }
            else
            {
              if(mydata->items_cfg.music.cfg.first==TRUE)
                snwprintf(music_buf,MAXELEMS(music_buf),L"%ls\n%ls", name), unk_artist;
              else
                snwprintf(music_buf,MAXELEMS(music_buf),L"%ls\n%ls", unk_artist, name);
            }
          }
          else if(mydata->items_cfg.music.cfg.format == MUSIC_TITLE_ONLY)
          {
            if(title)
            {
              snwprintf(music_buf,MAXELEMS(music_buf),L"%ls", title);
              mfree(title);
            }
            else
              snwprintf(music_buf,MAXELEMS(music_buf),L"%ls", name);
          }
          else if(mydata->items_cfg.music.cfg.format == MUSIC_ARTIST_ONLY)
          {
            if(artist)
            {
              snwprintf(music_buf,MAXELEMS(music_buf),L"%ls", artist);
              mfree(artist);
            }
            else
              snwprintf(music_buf,MAXELEMS(music_buf),L"%ls", unk_artist);
          }
          SIDtime = TextID_Create(music_buf,ENC_UCS2,MAXELEMS(music_buf));
          DrawItem(item, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
        else if(EditMode)
        {
          SIDtime = TextID_Create(L"WALKMAN",ENC_UCS2,TEXTID_ANY_LEN);
          DrawItem(item, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
      }
    }
    
    //Fm Radio
    item = &mydata->items[RADIO_ITEM];
    if(*item->show || EditMode)
    {
      if((*item->y_max >= y) && (*item->y <= y_max))
      {
        TEXTID SIDtime;
        FmRadio_Book* FmBook = (FmRadio_Book*)FindBook(IsFmRadioBook);
        if(FmBook)
        {
          wchar_t tmp_fm[128];
          FUint16 CurrentFrequency;
          char index;
          wchar_t *name;
 
          CurrentFrequency= FmBook->ProgramInfo.Frequency; //CurrentFrequency;
          index = FmBook->CurrentChannel;
          name = FmBook->Channel[index-1].Name;;
          
          wchar_t buf[64];
          snwprintf(buf, MAXELEMS(buf), L"%d", CurrentFrequency );
          
          int len = wstrlen(buf);
          wchar_t* freq = (wchar_t*)malloc(sizeof(wchar_t)*len+1);
          for(int i=0; i<len; i++)
          {
            freq[i]=buf[i];
            if(i==(len-1))
            {
              freq[i]= 0x2e;
              freq[i+1] = buf[i];
              freq[len+1] = L'\0';
            }
          }
          
          if(mydata->items_cfg.radio.cfg.format == FM_FREQ_NAME)
          {
            if(mydata->items_cfg.radio.cfg.first==TRUE)
              snwprintf(tmp_fm,MAXELEMS(tmp_fm),L"%ls, %ls MHz", name, freq);
            else
              snwprintf(tmp_fm,MAXELEMS(tmp_fm),L"%ls MHz, %ls", freq, name);
          }
          else if(mydata->items_cfg.radio.cfg.format == FM_FREQ_ONLY)
          {
            snwprintf(tmp_fm,MAXELEMS(tmp_fm),L"%ls MHz", freq);
          }
          else if(mydata->items_cfg.radio.cfg.format == FM_NAME_ONLY)
          {
            snwprintf(tmp_fm,MAXELEMS(tmp_fm),L"%ls", name);
          }
          SIDtime = TextID_Create(tmp_fm,ENC_UCS2,MAXELEMS(tmp_fm));
          DrawItem(item, SIDtime, y);
          TextID_Destroy(SIDtime);
        } 
        else if(EditMode)
        {
          SIDtime = TextID_Create(L"Fm Radio",ENC_UCS2,TEXTID_ANY_LEN);
          DrawItem(item, SIDtime, y);
          TextID_Destroy(SIDtime);
        }
      }
    }
  }
}

extern "C"
void RunTimer ()
{
  MY_DATA* mydata = get_mydata();
  mydata->CallEnd = TRUE;
}

extern "C"
void KillTimer ()
{
  MY_DATA* mydata = get_mydata();
  mydata->CallEnd = FALSE;
}


extern "C"
void myOnKey( DISP_OBJ* db, int keyID, int unk, int repeat, int press_mode )
{
  MY_DATA* mydata = get_mydata();
  if(mydata)
  {
    if(mydata->flag == 0)
    {
      if(press_mode == KBD_SHORT_PRESS)
      {
        if(keyID == KEY_DIGITAL_0)
        {
          mydata->cnt += 1;
        }
        else
        {
          mydata->cnt = 0;
        }
      }
    }

    if(mydata->cnt < 6)
    {
      mydata->EditMode = 0;
      oldOnKeyMainInput(db, keyID, unk, repeat, press_mode);
    }
    else
    {
      mydata->EditMode = 1;
      if(mydata->flag == 0)
      {
        MainInput_Hide(SBY_GetMainInput(Find_StandbyBook()));
        mydata->flag = 1;
        return;
      }
      if((press_mode == KBD_SHORT_PRESS) || (press_mode == KBD_REPEAT))
      {
        if(keyID == KEY_DIGITAL_0+5)
        {
          save_mydata();
          mydata->cnt = 0;
          mydata->flag = 0;
          mydata->EditMode = 0;
          mydata->cur_item = -1;
          return;
        }

        if(mydata->cur_item < 0)
        {
          if(keyID == KEY_STAR)
          {
            CreateItemsList();
          }
          else
          {
            MessageBox_NoImage( EMPTY_TEXTID, STR("Press '*' to select item\n'#' - to edit item\n'5' - to save and exit."), 1, 2500, NULL );
          }
        }
        else
        {
          ITEM_DATA* item = &mydata->items[mydata->cur_item];
          int step = 1;
          if((press_mode == KBD_REPEAT) && (repeat > 5)) step = 5;
          if(keyID == KEY_DIGITAL_0+2)
          {
            if(*item->y > 0)
            {
              *item->y -= step;
              *item->y_max = *item->y + *item->h;
            }
          }
          else if(keyID == KEY_DIGITAL_0+8)
          {
            if(*item->y < (Display_Height-1))
            {
              *item->y += step;
              *item->y_max = *item->y + *item->h;
            }
          }
          else if(keyID == KEY_DIGITAL_0+4)
          {
            if(*item->x > 0) *item->x -= step;
          }
          else if(keyID == KEY_DIGITAL_0+6)
          {
            if(*item->x < (Display_Width-1)) *item->x += step;
          }
          else if(keyID == KEY_STAR)
          {
            CreateItemsList();
            return;
          }
          else if(keyID == KEY_DIEZ)
          {
            CreateItemsEditor();
            return;
          }
          LiteUpdateParams(mydata);
          InvalidateAll(mydata);
        }
      }
    }
  }
  else
  {
    oldOnKeyMainInput(db, keyID, unk, repeat, press_mode);
  }
}

int StatusMaxY()
{
  return DispObject_GetWindowHeight(*StatusRow_p());
}

int DisplayMaxY()
{
  return Display_Height - DispObject_GetWindowHeight(DispObject_SoftKeys_Get());
}

extern "C"
void onRedrawStatus(DISP_OBJ* disp_obj, int a, int b, int c)
{
  oldRedrawStatus(disp_obj,a,b,c);
  BOOK *topbk = GetTopBook();
  
  int h = DispObject_GetWindowHeight(Display_GetFocusedDispObject(0));
  int isStandby = ((topbk == Find_StandbyBook()) || (topbk == FindBook(IsScreenSaverBook)));

  int orient = 0;
  if(topbk) orient = BookObj_GetDisplayOrientation(topbk);
  if(orient == 0)
  if((isStandby) || (h < Display_Height))
  {
    DrawParams(0, StatusMaxY(), isStandby);
  }
}

extern "C"
void onRedrawDisplay(DISP_OBJ* disp_obj, int a, int b, int c)
{
  BOOK *topbk = GetTopBook();
  int h = DispObject_GetWindowHeight(Display_GetFocusedDispObject(0));
  int isStandby = ((topbk == Find_StandbyBook()) || (topbk == FindBook(IsScreenSaverBook)));

  int orient = 0;
  if(topbk) orient = BookObj_GetDisplayOrientation(topbk);
  if(orient == 0)
  if((isStandby) || (h < Display_Height))
  {
    DrawParams(StatusMaxY(), DisplayMaxY(), isStandby);
  }
  oldRedrawDisplay(disp_obj,a,b,c);
}

extern "C"
void onRedrawSoft(DISP_OBJ* disp_obj, int a, int b, int c)
{
  BOOK *topbk = GetTopBook();
  int h = DispObject_GetWindowHeight(Display_GetFocusedDispObject(0));
  int isStandby = ((topbk == Find_StandbyBook()) || (topbk == FindBook(IsScreenSaverBook)));

  int orient = 0;
  if(topbk) orient = BookObj_GetDisplayOrientation(topbk);
  if(orient == 0)
  if((isStandby) || (h < Display_Height))
  {
    DrawParams(DisplayMaxY(), Display_Height, isStandby);
  }
  oldRedrawSoft(disp_obj,a,b,c);
}

extern "C"
int onCreateDisplay(DISP_OBJ* disp_obj)
{
  int status = oldCreateDisplay(disp_obj);

  MY_DATA* mydata = get_mydata();
  mydata->Display_dobj = disp_obj;

  TimerRedrawRun(mydata);
  return status;
}

extern "C"
void onCloseDisplay(DISP_OBJ* disp_obj)
{
  MY_DATA* mydata = get_mydata();
  mydata->Display_dobj = NULL;
  
  TimerRedrawKill(mydata);
  oldCloseDisplay(disp_obj);
}

int status_item_cmp(void *r0, void *r1)
{
  if((!r0) || (!r1)) return TRUE;
  if (((STATUS_ITEM_LIST*)r0)->iconID == ((STATUS_ITEM_LIST*)r1)->iconID) return FALSE;
  return TRUE;
}

void status_item_free(void * item)
{
  if(item) mfree(item);
}

void RemoveIcon(LIST * status_list, IMAGEID iconID)
{
    STATUS_ITEM_LIST temp_si;
    
    temp_si.iconID = iconID;
    int pos = List_Find(status_list, &temp_si, status_item_cmp);
    if(pos != LIST_ERROR)
    {
      STATUS_ITEM_LIST *si = (STATUS_ITEM_LIST*)List_RemoveAt(status_list, pos);
      status_item_free(si);
    }
}

extern "C"
char MySetTrayIcon(IMAGEID iconID, char mode)
{
  if(iconID)
  {
    MY_DATA* mydata = get_mydata();
    if((iconID >= C_UI_BATTERY_LEV9_ICN) && (iconID <= C_UI_BATTERY_LEV0_ICN))
    {
      if(mode) mydata->CurrentIconIDBatt = iconID;
      return mode;
    }
    if(iconID == C_UI_BATTERY_CHARGING_ICN)
    {
      mydata->isCharging = mode;
      return mode;
    }
    
    if(((iconID >= C_UI_EDGE_ATT_LEV0_ICN) && (iconID <= C_UI_GPRS_DET_LEV9_ICN)) ||
       ((iconID >= C_UI_RSSI_LEV0_ICN) && (iconID <= C_UI_RSSI_LEV5_ICN)) ||
       (iconID == FMODE_RSSI_INDICATION_ICN))
    {
      if(mode) mydata->CurrentIconIDNet = iconID;
      return mode;
    }

    LIST * status_list = mydata->status_list;
    STATUS_ITEM_LIST temp_si;

    temp_si.iconID = iconID;
    int pos = List_Find(status_list, &temp_si, status_item_cmp);
    if(mode)
    {
      if(pos != LIST_ERROR) return mode;
      STATUS_ITEM_LIST *si = (STATUS_ITEM_LIST*)malloc(sizeof(STATUS_ITEM_LIST));
      si->iconID = iconID;
      if(mydata->items_cfg.status.cfg.fill)
        List_InsertLast(status_list, si);
      else
        List_Insert(status_list, 0, si);
      mydata->status_was_changed = TRUE;

      return mode;
    }
    
    if(pos != LIST_ERROR)
    {
      STATUS_ITEM_LIST* si = (STATUS_ITEM_LIST*)List_RemoveAt(status_list, pos);
      status_item_free(si);
      mydata->status_was_changed = TRUE;
    }
  }
  return mode;
}


