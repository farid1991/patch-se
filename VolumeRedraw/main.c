#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\classes.h"
#include "..\\include\book\VolumeControlBook.h"

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#endif
#include "Lib.h"
#include "main.h"

__thumb void *malloc(int size)
{
#if defined(DB2020)
    return (memalloc(0, size, 1, 5, "V_MEM", 0));
#elif defined(A2)
    return (memalloc(0xFFFFFFFF, size, 1, 5, "V_MEM", 0));
#else
    return (memalloc(size, 1, 5, "V_MEM", 0));
#endif
}

__thumb void mfree(void *mem)
{
#if defined(DB2020)
    if (mem)
        memfree(0, mem, "V_MEM", 0);
#elif defined(A2)
    if (mem)
        memfree(0, mem, "V_MEM", 0);
#else
    memfree(mem, "V_MEM", 0);
#endif
}

Volume_Function *Create_Volume_Function()
{
    Volume_Function *Data = (Volume_Function *)malloc(sizeof(Volume_Function));
    memset(Data, NULL, sizeof(Volume_Function));
    set_envp(NULL, EMP_NAME, (OSADDRESS)Data);
    return (Data);
}

Volume_Function *Get_Volume_Function()
{
    Volume_Function *Data = (Volume_Function *)get_envp(NULL, EMP_NAME);
    if (Data)
        return Data;
    return Create_Volume_Function();
}

void Delete_Volume_Function()
{
    Volume_Function *Data = (Volume_Function *)get_envp(NULL, EMP_NAME);
    if (Data)
    {
        mfree(Data);
        set_envp(NULL, EMP_NAME, OSADDRESS(NULL));
    }
}

int IsOngoingCallBook(BOOK *book)
{
    if (!strcmp(book->xbook->name, (char *)ONGOINGCALLBOOK))
        return TRUE;
    return FALSE;
}

int IsMOCallBook(BOOK *book)
{
    if (!strcmp(book->xbook->name, (char *)MOCALLBOOK))
        return TRUE;
    return FALSE;
}

BOOL IsJavaBOOK(BOOK *book)
{
    char str[100];
    TextID_GetString(BookObj_GetSession(book)->name, str, MAXELEMS(str));

    if (!strncmp(str, "Foreign app", 11))
    {
        return TRUE;
    }

    if (!strcmp(str, "Java"))
    {
        return TRUE;
    }
    return FALSE;
}

wchar_t *GetCurrentSkinPath(Volume_Function *Data)
{
    wchar_t *path = (wchar_t *)OTHER_PATH;
    int file;
    if ((file = _fopen((wchar_t *)DEFAULT_PATH, L"vol.cfg", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
    {
        CPATH *ConfigData = (CPATH *)malloc(sizeof(CPATH));
        memset(ConfigData, NULL, sizeof(CPATH));
        fread(file, ConfigData, sizeof(CPATH));
        path = ConfigData->path;
        fclose(file);
        mfree(ConfigData);
    }
    return path;
}

SkinConfig *GetConfig(wchar_t *cpath)
{
    int file;
    SkinConfig *SkinData = (SkinConfig *)malloc(sizeof(SkinConfig));
    memset(SkinData, NULL, sizeof(SkinConfig));
    if ((file = _fopen(cpath, L"skin.vsf", FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, 0)) >= 0)
    {
        fread(file, SkinData, sizeof(SkinConfig));
        fclose(file);
    }
    return SkinData;
}

void RegisterImage(IMG *img, wchar_t *path, wchar_t *fname)
{
    int _SYNC = NULL;
    int *SYNC = &_SYNC;
    char error_code;
    img->ID = NOIMAGE;
    img->Handle = NOIMAGE;

    if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(SYNC, &img->Handle, &error_code))
        if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(SYNC, img->Handle, path, fname, 0, &img->ID, &error_code))
            if (error_code)
                img->Handle = NOIMAGE;
}

void UnRegisterImage(Volume_Function *Data)
{
    int _SYNC = NULL;
    int *SYNC = &_SYNC;
    char error_code;

    for (int i = 0; i < LAST_IMG; i++)
    {
        if (Data->Vol_Image[i].ID != NOIMAGE)
            REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(SYNC, Data->Vol_Image[i].Handle, NULL, NULL, Data->Vol_Image[i].ID, 1, &error_code);
    }
}

void InitImage(Volume_Function *Data)
{
    const wchar_t *VolumeImages[LAST_IMG] =
        {
            L"background.png",
            L"call.png",
            L"music.png",
            L"off.png",
            L"blob.png"};

    for (int i = 0; i < LAST_IMG; i++)
    {
        if (FSX_IsFileExists(Data->ConfigPath, (wchar_t *)VolumeImages[i]))
            RegisterImage(&Data->Vol_Image[i], Data->ConfigPath, (wchar_t *)VolumeImages[i]);
        else
            Data->Vol_Image[i].ID = NOIMAGE;
    }
}

void DrawImage(int x, int y, IMAGEID img)
{
    GC *pGC = get_DisplayGC();
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
    if (img != NOIMAGE)
        dll_GC_PutChar(pGC, x, y, 0, 0, img);
#else
    if (img != NOIMAGE)
        GC_PutChar(pGC, x, y, 0, 0, img);
#endif
}

void DrawProgressBar(IMAGEID blob_id, int value, int max_value, RECT rect, int Bcolor, int Ecolor, bool enable)
{
    int wid = rect.x2 - rect.x1;
    int nx2 = rect.x1 + (value * wid / max_value);

    DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor);
    DrawRect(rect.x1, rect.y1, nx2, rect.y2, Ecolor, Ecolor);

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
    int blob_h = (dll_GetImageHeight(blob_id)) / 2;
    int blob_w = (dll_GetImageWidth(blob_id)) / 2;
#else
    int blob_h = (GetImageHeight(blob_id)) / 2;
    int blob_w = (GetImageWidth(blob_id)) / 2;
#endif
    if (enable)
    {
        int blob_x = nx2 - blob_w;
        int blob_y = (rect.y1 - blob_h) + ((rect.y2 - rect.y1) / 2);
        DrawImage(blob_x, blob_y, blob_id);
    }
}

void DrawString_Params(int font, TEXTID text, int align, int XPos, int YPos, int width, int NormalColor)
{
    if (text && (text != EMPTY_TEXTID))
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        dll_DrawString(font, text, align, XPos, YPos, XPos + width, YPos + (font & 0xFF), NormalColor);
#else
        SetFont(font);
        DrawString(text, align, XPos, YPos, XPos + width, YPos + (font & 0xFF), 0, 1, NormalColor, clEmpty);
#endif
    }
}

extern "C" int New_VolumeControl_OnCreate(DISP_OBJ *disp_obj)
{
    Volume_Function *Data = Get_Volume_Function();
    Data->vol_textid = EMPTY_TEXTID;

    wstrcpy(Data->ConfigPath, GetCurrentSkinPath(Data));
    Data->Config = *(GetConfig(Data->ConfigPath));

    InitImage(Data);
    VolumeControl_OnCreate(disp_obj);
    return 1;
}

extern "C" void New_VolumeControl_OnClose(DISP_OBJ *disp_obj)
{
    Volume_Function *Data = Get_Volume_Function();
    TEXT_FREE(Data->vol_textid);

    UnRegisterImage(Data);
    Delete_Volume_Function();
    VolumeControl_OnClose(disp_obj);
}

extern "C" void New_VolumeControl_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
#ifdef HASSECONDDISPLAY
    if (IsMainDisplayActive())
    {
#endif
        Volume_Function *Data = Get_Volume_Function();
        if (!Data->IsJava)
        {
            GUI *VolumeControlGUI = DispObject_GetGUI(disp_obj);
            VolumeControlBook *VCBook = (VolumeControlBook *)GUIObject_GetBook(VolumeControlGUI);

            int Vol_Level = 0;
            int Max_Volume = 0;

            Vol_Level = VCBook->level;

            DrawImage(Data->Config.bg_image.x,
                      Data->Config.bg_image.y,
                      Data->Vol_Image[BACKGROUND_IMG].ID);

            if (Vol_Level)
            {
                if ((FindBook(IsOngoingCallBook)) || (FindBook(IsMOCallBook)))
                {
                    Max_Volume = 8;
                    DrawImage(Data->Config.state_image.x,
                              Data->Config.state_image.y,
                              Data->Vol_Image[CALL_IMG].ID);
                }
                else
                {
                    Max_Volume = 15;
                    DrawImage(Data->Config.state_image.x,
                              Data->Config.state_image.y,
                              Data->Vol_Image[MUSIC_IMG].ID);
                }
            }
            else
            {
                DrawImage(Data->Config.state_image.x,
                          Data->Config.state_image.y,
                          Data->Vol_Image[OFF_IMG].ID);
            }

            if (Data->Config.TextEnable)
            {
                TEXTID vText_id[2];
                float vLevel = (float)((float)100 / (float)Max_Volume) * (float)Vol_Level;
                vText_id[0] = TextID_CreateIntegerID(vLevel);
                vText_id[1] = TextID_Create("%", ENC_GSM, 1);
                if (Data->Config.PercentageEnable)
                {
                    Data->vol_textid = TextID_Create(vText_id, ENC_TEXTID, 2);
                }
                else
                {
                    Data->vol_textid = TextID_Copy(vText_id[0]);
                }
                DrawString_Params(Data->Config.Font_size,
                                  Data->vol_textid,
                                  AlignLeft,
                                  Data->Config.text_pos.x,
                                  Data->Config.text_pos.y,
                                  Display_GetWidth(UIDisplay_Main),
                                  Data->Config.text_color);
            }
            DrawProgressBar(Data->Vol_Image[BLOB_IMG].ID,
                            Vol_Level,
                            Max_Volume,
                            Data->Config.progressbar,
                            Data->Config.progressbar_bg_color,
                            Data->Config.progressbar_elapsed_color,
                            Data->Config.EnableProgressbar);
        }
#ifdef HASSECONDDISPLAY
    }
    else
    {
        VolumeControl_OnRedraw(disp_obj, a, b, c);
    }
#endif
}

extern "C" int New_pg_VolumeControl_Active_EnterEvent(void *data, BOOK *book)
{
    if (pg_VolumeControl_Active_EnterEvent(data, book))
    {
#ifdef HASSECONDDISPLAY
        if (IsMainDisplayActive())
        {
#endif
            Volume_Function *Data = Get_Volume_Function();
            Data->IsJava = IsJavaBOOK(MainDisplay_GetTopBook());

            if (!Data->IsJava)
            {
                VolumeControlBook *VCBook = (VolumeControlBook *)book;
                DISP_OBJ *disp_obj = (DISP_OBJ *)GUIObject_GetDispObject(VCBook->VC_GUI);
                DispObject_WindowSetSize(disp_obj, Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main));
                DispObject_SetLayerColor(disp_obj, clEmpty);
                DispObject_SetAnimation(disp_obj, Data->Config.AnimationStyle);
            }
#ifdef HASSECONDDISPLAY
        }
#endif
    }
    return 1;
}
