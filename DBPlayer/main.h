#ifndef _MAIN_H_
#define _MAIN_H_

/*
;Добавить информацию об аудиозаписи в диспетчер файлов
; - Отображение обложки альбома
; - Отображение прогрессбара, ползунка и обводки
; - Выбор типа прогрессбара: обычный и закругленные концы
; - Отображение времени: полное, текущее, оставшееся
; - Отображение тэгов: исполнитель, альбом, назване, год, жанр
; - Отображение информации: битрейт, частота дискретизации, аудио выход
; - Отображение иконок: фон, рамка
; - Настройка активности, цвета и т.д.
; - Настройка координат и шрифта в реальном времени
; - Возможность использовать цвет на фон
; - Включение/выключение анимации появления окна
; - Возможность свернуть окно
; - Редактирование тэгов в Music Tagger
; - Возможность показать/скрыть статусбар
; - Возможность показать/скрыть софты
; - Автозакрытие окна
; - Атообновление настроек
; - Переход на заданное время
; - Пауза
; - Управление:
; Джойстик вверх/вниз - громкость
; Джойстик влево - воспроизвести сначала
; Удержание джойстик влево/вправо - перемотка
; # - Приглушить/восстановить звук
; * - Блокировка кнопок
;v. 5.1
;(c) E1kolyan
*/

//#define IMEI_CHECK_ON

const int IMEI = 93;

/*
   - -    --  - -
35638503-386525-9; 108 - E1kolyan C510_R1FA035_Orange
35638503-573139-2; 87 - Vov4ik C510_R1FA035_Orange
35402203-491105-3; 60 - D3mon W995_R1GA026
35467703-224195-9; 99 - Velikii C901_R1GA028
35204503-446262-1; 54 - MrGraL C510_R1HA035
35681303-142773-1; 63 - G@S J105_R1HA035
01224900-415550-2; 57 - .:DOC:. J105_R1HA035
35681303-277705-0; 90 - gordan33-92 J105_R1HA035
35467703-238133-4; 93 - Hypnotic C901_R1GA028
   - -    --  - -
*/

#define TEXTFREE(a)      \
  if (a != EMPTY_TEXTID) \
  TextID_Destroy(a)

#define FREE_GUI(g)       \
  if (g)                  \
  {                       \
    GUIObject_Destroy(g); \
    g = NULL;             \
  }

#define ELF_PATH_UTILS L"/usb/other/ZBin/Utils/MusicTagger.elf"
#define ELF_PATH_ZBIN L"/usb/other/ZBin/MusicTagger.elf"

static const char GuiName_DBPlayer[] = "GUI_DBPlayer";
typedef struct GUI GUI_DBPLAYER;

typedef struct _DISP_OBJ_DBP : DISP_OBJ
{
  TEXTID artist;
  TEXTID title;
  TEXTID album;
  TEXTID year;
  TEXTID genre;
  TEXTID ext;
  TEXTID time_t;
  TEXTID time_e;
  TEXTID time_r;
  TEXTID bitrate;
  TEXTID samplerate;
  TEXTID audiooutput;
  TEXTID buf_text;
  int media_volume;
  int cstep;
  int scr_w;
  int scr_h;
} DISP_OBJ_DBP;

enum DBP_ACTION_ID
{
  ACTION_PAUSE,
  ACTION_PLAY,
  ACTION_STOP,
  ACTION_SETTINGS,
#ifndef DB3350
  ACTION_TAG,
#endif
  ACTION_TIME,
  ACTION_MINIMISE,
  ACTION_LAST
};

void *malloc(int size);
void mfree(void *mem);

extern "C"
{
  int pg_Sound_Run__0x17FC(void *pMMEData, BOOK *book);
}
#endif
