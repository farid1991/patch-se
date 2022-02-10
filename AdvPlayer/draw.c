#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Color.h"
#include "..\\include\classes\IUnknown.h"
#include "..\\include\book\AudioPlayerBook.h"

#include "Lib.h"
#include "CurrentTrack.h"
#include "data.h"
#include "main.h"
#include "draw.h"

void InvalidateNowPlaying(DISP_OBJ *disp_obj)
{
  INVALIDATE_RECT(disp_obj);
}

void DrawImage(int x, int y, IMAGEID img)
{
  GC *pGC = get_DisplayGC();
  if (img != NOIMAGE)
    GC_PutChar(pGC, x, y, 0, 0, img);
}

void DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, unsigned int text_color)
{
  if (text && (text != EMPTY_TEXTID))
  {
    SetFont(font);
    DrawString(text, align, x_pos, y_pos, x_pos + width, y_pos + height, 0, 1, text_color, clEmpty);
  }
}

void DrawCoverArt(ADVPLAYER_DATA *data)
{
  GC *pGC = get_DisplayGC();

  if (data->HasCover)
  {
    GC_PutChar(pGC,
               data->Skin->coverart_x, data->Skin->coverart_y,
               data->Skin->coverart_w, data->Skin->coverart_h,
               data->CoverArt);
  }
  else
  {
    GC_PutChar(pGC,
               data->Skin->coverart_x, data->Skin->coverart_y,
               data->Skin->coverart_w, data->Skin->coverart_h,
               data->skin_image[MP_NOCOVER_ICN].id);
  }
}

void DrawPlayerState(ADVPLAYER_DATA *data)
{
  if (data->IsPlaying)
    DrawImage(data->Skin->icon_playpause_x, data->Skin->icon_playpause_y, data->skin_image[MP_PAUSE_ICN].id);
  else
    DrawImage(data->Skin->icon_playpause_x, data->Skin->icon_playpause_y, data->skin_image[MP_PLAY_ICN].id);
}

void DrawProgressBar(IMAGEID blob_id, int value, int max_value, RECT rect, int Bcolor, int Ecolor, bool enable_indicator)
{
  int width = rect.x2 - rect.x1;
  int nx2 = rect.x1 + (value * width / max_value);
  DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, Bcolor, Bcolor);
  DrawRect(rect.x1, rect.y1, nx2, rect.y2, Ecolor, Ecolor);

  if (enable_indicator)
  {
    int blob_w = (GetImageWidth(blob_id)) / 2;
    int blob_h = (GetImageHeight(blob_id)) / 2;
    int blob_x = nx2 - blob_w;
    int blob_y = (rect.y1 - blob_h) + ((rect.y2 - rect.y1) / 2);
    DrawImage(blob_x, blob_y, blob_id);
  }
}
