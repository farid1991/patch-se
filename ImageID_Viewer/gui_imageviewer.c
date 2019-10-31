#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "..\\include\book\ServiceMenuBook.h"

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "..\\include\dll.h"
#endif

#include "gui_imageviewer.h"
#include "main.h"

TEXTID ImageID_GetOffset( IMAGEID img )
{
  char buf[8];
  sprintf(buf,"0x%X",img);
  return TextID_Create(buf,ENC_GSM,strlen(buf));
}

TEXTID ImageID_GetIMGSize( int w, int h )
{
  char buf[10];
  sprintf(buf,"%d x %d",w,h);
  return TextID_Create(buf,ENC_GSM,strlen(buf));
}

void DrawString_Params(TEXTID text, int font, int align, int x1, int y1, int x2, color_t tcolor, color_t ocolor)
{
  if (text && text!=EMPTY_TEXTID)
  {
    int y2 = y1 + (font&0xFF);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString( text, font, align, x1, y1, x2, y2, tcolor);
#else
    SetFont(font);
    DrawString( text, align, x1, y1, x2, y2, 0, 0, tcolor, ocolor);
#endif
  }
}

int ImageIDViewer_OnCreate(DISP_OBJ_IMG* disp_obj)
{
  disp_obj->textid_imgoffset = EMPTY_TEXTID;
  disp_obj->textid_imgsize = EMPTY_TEXTID;
  
  disp_obj->width = Display_GetWidth(UIDisplay_Main);
  disp_obj->height = Display_GetHeight(UIDisplay_Main);
  
  disp_obj->rect.x1 = 0;
  disp_obj->rect.y1 = 0;
  disp_obj->rect.x2 = disp_obj->width/4;
  disp_obj->rect.y2 = disp_obj->height/4;
  
  disp_obj->img = SEG1_START;
  disp_obj->color = clBlack;
  disp_obj->color_text = clWhite;
  disp_obj->col_set = FALSE;
  return 1;
}

void ImageIDViewer_OnClose(DISP_OBJ_IMG* disp_obj)
{
  TEXT_FREE(disp_obj->textid_imgoffset);
  TEXT_FREE(disp_obj->textid_imgsize);
  
  disp_obj->width = NULL;
  disp_obj->height = NULL;
  
  disp_obj->rect.x1 = NULL;
  disp_obj->rect.y1 = NULL;
  disp_obj->rect.x2 = NULL;
  disp_obj->rect.y2 = NULL;
  
  disp_obj->img = NULL;
  disp_obj->color = NULL;
  disp_obj->color_text = NULL;
  disp_obj->col_set = NULL;
}

void ImageIDViewer_OnRedraw(DISP_OBJ_IMG* disp, int a, int b, int c)
{
  DISP_OBJ_IMG* disp_obj = (DISP_OBJ_IMG*) disp;
  
  GC *pGC = get_DisplayGC();
  
  DispObject_SetLayerColor(disp_obj, disp_obj->color);
  
  disp_obj->textid_imgoffset = ImageID_GetOffset(disp_obj->img);

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
  int img_w = dll_GetImageWidth(disp_obj->img);
  int img_h = dll_GetImageHeight(disp_obj->img);
#else
  int img_w = GetImageWidth(disp_obj->img);
  int img_h = GetImageHeight(disp_obj->img);
#endif
  
  if(img_w && img_h)
  {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_GC_PutChar(pGC,
                   (disp_obj->width-img_w)/2,
                   (disp_obj->height-img_h)/2,
                   img_w,
                   img_h,
                   disp_obj->img );
#else
    GC_PutChar(pGC,
               (disp_obj->width-img_w)/2,
               (disp_obj->height-img_h)/2,
               img_w,
               img_h,
               disp_obj->img );
#endif
    disp_obj->textid_imgsize = ImageID_GetIMGSize(img_w,img_h);
    DrawString_Params(disp_obj->textid_imgsize,
                      FONT_E_18R,
                      UITextAlignment_Center,
                      0,
                      (disp_obj->height*4)/5,
                      disp_obj->width,
                      disp_obj->color_text,
                      clEmpty );
  TEXT_FREE(disp_obj->textid_imgsize);
  }
  else 
  {
    disp_obj->textid_imgsize = STR("NOIMAGE");
    DrawString_Params(disp_obj->textid_imgsize,
                      FONT_E_24R,
                      UITextAlignment_Center,
                      0,
                      disp_obj->height/2,
                      disp_obj->width,
                      disp_obj->color_text,
                      clEmpty );
  TEXT_FREE(disp_obj->textid_imgsize);
  }
  
  DrawString_Params(disp_obj->textid_imgoffset,
                    FONT_E_30R,
                    UITextAlignment_Center,
                    0,
                    disp_obj->height/12,
                    disp_obj->width,
                    disp_obj->color_text, 
                    clEmpty );
  TEXT_FREE(disp_obj->textid_imgoffset);
}

void ImageIDViewer_OnKey(DISP_OBJ_IMG* disp, int key, int unk, int repeat, int mode)
{
  DISP_OBJ_IMG* disp_obj = (DISP_OBJ_IMG*) disp;
  
  if(mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
  {
    switch(key)
    {
    case KEY_RIGHT:
    case KEY_UP:  
      if(disp_obj->img==SEG1_END) disp_obj->img=SEG2_START;
      else if(disp_obj->img==SEG2_END) disp_obj->img=SEG3_START;
      else if(disp_obj->img==SEG3_END) disp_obj->img=SEG4_START;
      else if(disp_obj->img==SEG4_END) disp_obj->img=SEG5_START;
      else if(disp_obj->img==SEG5_END) disp_obj->img=SEG1_START;
      else disp_obj->img++;
      break;
    case KEY_DOWN:
    case KEY_LEFT:
      if(disp_obj->img==SEG1_START) disp_obj->img=SEG5_END;
      else if(disp_obj->img==SEG2_START) disp_obj->img=SEG1_END;
      else if(disp_obj->img==SEG3_START) disp_obj->img=SEG2_END;
      else if(disp_obj->img==SEG4_START) disp_obj->img=SEG3_END;
      else if(disp_obj->img==SEG5_START) disp_obj->img=SEG4_END;
      else disp_obj->img--;
      break;
    case KEY_STAR:
      if(!disp_obj->col_set)
      {
        disp_obj->color = clWhite;
        disp_obj->color_text = clBlack;
        disp_obj->col_set = TRUE;
      }
      else
      {
        disp_obj->color = clBlack;
        disp_obj->color_text = clWhite;
        disp_obj->col_set = FALSE;
      }
      break;
    case KEY_DIGITAL_0: disp_obj->img=SEG1_START; break;  
    case KEY_DIGITAL_0+1: disp_obj->img=disp_obj->img-1; break;
    //case KEY_DIGITAL_0+2: disp_obj->img=; break;
    case KEY_DIGITAL_0+3: disp_obj->img=disp_obj->img+1; break;
    case KEY_DIGITAL_0+4: disp_obj->img=disp_obj->img-10; break;
    //case KEY_DIGITAL_0+5: disp_obj->img=; break;
    case KEY_DIGITAL_0+6: disp_obj->img=disp_obj->img+10; break;
    case KEY_DIGITAL_0+7: disp_obj->img=disp_obj->img-100; break;
    //case KEY_DIGITAL_0+8: disp_obj->img=; break;
    case KEY_DIGITAL_0+9: disp_obj->img=disp_obj->img+100; break;
    }
  }
  DispObject_InvalidateRect(disp_obj,NULL);
}

void ImageIDViewer_create(DISP_DESC *desc)
{
  DISP_DESC_SetName(desc, "ImageIDViewer_GUI");
  DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_IMG));
  DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)ImageIDViewer_OnCreate);
  DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)ImageIDViewer_OnClose);
  DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)ImageIDViewer_OnRedraw);
  DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)ImageIDViewer_OnKey);
}

void ImageIDViewer_destroy(GUI *gui)
{
}

GUI* Create_ImageIDViewer(BOOK* book)
{
  GUI* gui_img = (GUI*)malloc(sizeof(GUI));

  if (!GUIObject_Create(gui_img, ImageIDViewer_destroy, ImageIDViewer_create, book, NULL, UIDisplay_Main, sizeof(GUI)))
  {
    mfree(gui_img);
    return NULL;
  }
  
  if(book) BookObj_AddGUIObject(book,gui_img);
  
  GUIObject_SetStyle(gui_img,UI_OverlayStyle_TrueFullScreen);
  GUIObject_SoftKeys_RemoveBackground(gui_img);
  return gui_img;
}
