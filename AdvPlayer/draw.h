#ifndef Draw_h
#define Draw_h

#define INVALIDATE_RECT(disp)              \
  if (disp)                                \
  {                                        \
    DispObject_InvalidateRect(disp, NULL); \
  }

void InvalidateNowPlaying(DISP_OBJ *disp_obj);

void DrawImage(int x, int y, IMAGEID img);
void DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, unsigned int text_color);
void DrawCoverArt(ADVPLAYER_DATA *data);
void DrawPlayerState(ADVPLAYER_DATA *data);
void DrawProgressBar(IMAGEID blob_id, int value, int max_value, RECT rect, int Bcolor, int Ecolor, bool enable_indicator);

#endif
