#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\VolumeControllerBook.h"

#include "main.h"

__thumb void* malloc(int size)
{
#ifdef DB2020
  return(memalloc(0, size, 1, 5, "vr", 0));
#elif A2
  return(memalloc(0xFFFFFFFF, size, 1, 5, "vr", 0));
#else
  return(memalloc(size, 1, 5, "vr", 0));
#endif
}

__thumb void mfree(void* mem)
{
#ifdef DB2020
  if(mem) memfree(0, mem, "vr", 0);
#elif A2
  if(mem) memfree(0, mem, "vr", 0);
#else
  memfree(mem, "vr", 0);
#endif
}

int IsOngoingCallBook(BOOK *book)
{
  if(!strcmp(book->xbook->name, (char*)0x11A13DD8 )) return TRUE;
  return FALSE;
}

int IsMOCallBook(BOOK *book)	/* windows that show the connecting arrow */
{
  if(!strcmp(book->xbook->name, (char*)0x11A1525C )) return TRUE;
  return FALSE;
}

wchar_t *getCurrentSkinPath()
{
  wchar_t *path = L"/usb/other/ZBin/Config/VolumeControl";
  int f;
  if((f = _fopen( (wchar_t*)DEFAULT_PATH, L"vol.cfg", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
  {
    CPATH *Data = (CPATH*) malloc(sizeof(CPATH));
    memset(Data, 0, sizeof(CPATH));
    fread(f, Data, sizeof(CPATH));
    path = Data->path;
    fclose(f);
    mfree(Data);
  }
  return path;
}

SkinConfig *getCurrentSkinData(wchar_t *cpath)
{
  int f;
  SkinConfig* Data = (SkinConfig*) malloc(sizeof(SkinConfig));
  memset(Data, NULL, sizeof(SkinConfig));
  if((f = _fopen(cpath, L"skin.vsf", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
  {
    fread(f, Data, sizeof(SkinConfig));
    fclose(f);
  }
  return Data;
}

VolumeFunction *Create_VolumeFunction()
{
  wchar_t *ImageName[] = {
    L"background.png",
    L"call.png",
    L"music.png",
    L"off.png",
    L"blob.png"
  };

  VolumeFunction *Data = (VolumeFunction*) malloc(sizeof(VolumeFunction));

  memset(Data, 0, sizeof(VolumeFunction));
  wstrcpy(Data->cpath, getCurrentSkinPath());
  for(int x = 0; x <= 5; x++)
  {
    if(!fstat(Data->cpath, ImageName[x], 0))
    {
      ImageID_Get(Data->cpath, ImageName[x], &Data->image[x]);
    }
	else Data->image[x]=NOIMAGE; 
  }

  Data->Config = *getCurrentSkinData(Data->cpath);
  Data->blob_h = (GetImageHeight(Data->image[4])) / 2;
  Data->blob_w = (GetImageWidth(Data->image[4])) / 2;
  set_envp(get_bid(current_process()), VOLUME_VAR, (OSADDRESS)Data);
  return(Data);
}

VolumeFunction *Get_VolumeFunction()
{
  VolumeFunction *Data = (VolumeFunction*) get_envp(get_bid(current_process()), VOLUME_VAR);
  if(Data) return Data;
  return(Create_VolumeFunction());
}

BOOL IsJavaBOOK( BOOK* bk )
{
  char s[100];
  TextID_GetString( BookObj_GetSession(bk)->name, s, MAXELEMS(s) );
  
  if ( !strncmp( s, "Foreign app", 11 ) )
  {
    return TRUE;
  }
  
  if ( !strcmp( s, "Java" ) )
  {
    return TRUE;
  }
  return FALSE;
}

extern "C"
int NEW_VOLUMEONPAGENTER(void *pVCBookData, BOOK *pVCBook)
{
  if(DEFAULT_VOLUMEONPAGENTER(pVCBookData, pVCBook))
  {
    VolumeFunction* Data = Create_VolumeFunction();
    Data->IsJava = IsJavaBOOK(GetTopBook());
    if(!Data->IsJava)
    {
      VolumeControllerBook* VCBook = (VolumeControllerBook*) pVCBook;
      DispObject_WindowSetSize(VCBook->vc_gui->disp, SCN_WIDTH, SCN_HEIGHT);
      DispObject_SetLayerColor(VCBook->vc_gui->disp, 0x00000000);
      DispObject_SetAnimation(VCBook->vc_gui->disp, Data->Config.AnimationStyle);
    }
  }
  return TRUE;
}

extern "C"
int NEW_VOLUMEONPAGEXIT(void *pVCBookData, BOOK *pVCBook)
{
  if(DEFAULT_VOLUMEONPAGEXIT(pVCBookData, pVCBook))
  {
    wchar_t*ImageName[] = { 
      L"background.png",
      L"call.png",
      L"music.png",
      L"off.png",
      L"blob.png" 
    };
    
    VolumeFunction* Data = Get_VolumeFunction();
    if(Data)
    {
      for(int x = 0; x <= 5; x++)
      {
        if(!fstat(Data->cpath, ImageName[x], 0))
        {
          ImageID_Free(Data->image[x]);
        }
      }
      DELETE(Data);
    }
  }
  return TRUE;
}

extern "C"
void NEW_VOLUMEONREDRAW(DISP_OBJ* disp, int a, int b, int c)
{
  VolumeFunction*Data = Get_VolumeFunction();
  if(!Data->IsJava)
  {
    VolumeControllerBook* vBook = (VolumeControllerBook*) FindBook(IsVolumeControllerBook);
    int	level = vBook->level;
    int	MaxVol = 0;
    if((FindBook(IsOngoingCallBook)) || (FindBook(IsMOCallBook)))
    {
      MaxVol = 8;
      Data->State = VolState_GetImageID(Data, level, FALSE);
    }
    else
    {
      MaxVol = 15;
      Data->State = VolState_GetImageID(Data, level, TRUE);
    }
	
    GC_DrawIcon( Data->Config.bg_image.x, Data->Config.bg_image.y, Data->image[0]);
    GC_DrawIcon( Data->Config.state_image.x, Data->Config.state_image.y, Data->State);

    if(Data->Config.FontEnable)
    {
      TEXTID SID[2];
      TEXTID txtId;
      float vLevel = (float) ((float) 100 / (float) MaxVol) * (float) level;
      SID[0] = TextID_CreateIntegerID(vLevel);
      SID[1] = TextID_Create("%", ENC_GSM, 1);
      if(Data->Config.PercentageEnable)
      {
        txtId = TextID_Create(SID, ENC_TEXTID, 2);
      }
      else
      {
        txtId = TextID_Copy(SID[0]);
      }
      SetFont(Data->Config.Font_size);
      DrawString(txtId,0,
                 Data->Config.text_pos.x,
                 Data->Config.text_pos.y,
                 SCN_WIDTH,SCN_HEIGHT,
                 0,1,
                 Data->Config.text_color,
                 Data->Config.text_color );
    }
	
    DrawProgressBar(Data,level,MaxVol,
                    Data->Config.progressbar,
                    Data->Config.progressbar_bg_color /* bg */,
                    Data->Config.progressbar_elapsed_color /* elapsed */,
                    Data->Config.EnableProgressbar );
  }
}

IMAGEID VolState_GetImageID(VolumeFunction *Data, int level, int isNotCallbook)
{
  if(level == 0)
    return Data->image[3];
  else if((level > 0) && (isNotCallbook == FALSE))
    return Data->image[1];
  else if((level > 0) && (isNotCallbook == TRUE))
    return Data->image[2];
  return NOIMAGE;
}

void DrawProgressBar(VolumeFunction *Data, int value, int max_value, RECT rect, int Bcolor, int Ecolor, int enableBlob)
{
  int nx2(rect.x1 + (((float) (rect.x2 - rect.x1) / (float) max_value) * (float) value));
  DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor);
  DrawRect(rect.x1, rect.y1, nx2, rect.y2, Ecolor, Ecolor);
  if(enableBlob)
  {
    int blob_x = nx2 - (Data->blob_w);
    int blob_y = (rect.y1 - (Data->blob_h)) + ((rect.y2 - rect.y1) / 2);
    GC_DrawIcon( blob_x, blob_y, Data->image[4]);
  }
}
