#ifndef _SETTING_H_
#define _SETTING_H_

enum ELEM_TYPE
{
    ELEM_TEXT,
    ELEM_RECT,
    ELEM_ICON
};

enum ITEM_SETTING
{
    ITEM_ARTIST,
    ITEM_TITLE,
    ITEM_ALBUM,
    ITEM_YEAR,
    ITEM_GENRE,
    ITEM_FILETYPE,
    ITEM_TOTAL,
    ITEM_ELAPSED,
    ITEM_REMAINING,
    ITEM_BITRATE,
    ITEM_SAMPLERATE,
    ITEM_AUDIOOUTPUT,
    ITEM_TIME_PROGRESS,
    ITEM_VOLUME_PROGRESS,
    ITEM_COVERART,
    ITEM_FRAME,
    ITEM_ARTIST_ICN,
    ITEM_TITLE_ICN,
    ITEM_ALBUM_ICN,
    ITEM_PLAYERSTATE_ICN,
    ITEM_BACKROUND,
    ITEM_ADDITIONAL,
    ITEM_LAST
};

enum BACKGROUND_TYPE
{
    BG_TYPE_IMAGE,
    BG_TYPE_THEME,
    BG_TYPE_COLOR
};

enum EDITOR_TYPE
{
    EDIT_TEXT,
    EDIT_SLIDER,
    EDIT_ICON,
    EDIT_BACKGROUND,
    EDIT_EXTENDED,
    EDIT_LAST
};

enum SUBITEM_TXT
{
    SUBITEM_TXT_STATE,
    SUBITEM_TXT_COLOR,
    SUBITEM_TXT_OVERLAY,
    SUBITEM_TXT_ALIGN,
    SUBITEM_TXT_VISUAL,
    SUBITEM_TXT_LAST
};

enum SUBITEM_IMG
{
    SUBITEM_IMG_STATE,
    SUBITEM_IMG_VISUAL,
    SUBITEM_IMG_LAST
};

enum SUBITEM_PROGRESSBAR
{
    SUBITEM_PB_STATE,
    SUBITEM_PB_SLIDER,
    SUBITEM_PB_ROUND,
    SUBITEM_PB_BCOLOR,
    SUBITEM_PB_FCOLOR,
    SUBITEM_PB_VISUAL,
    SUBITEM_PB_LAST
};

enum SUBITEM_BACKGROUND
{
    SUBITEM_BG_TYPE,
    SUBITEM_BG_COLOR,
    SUBITEM_BG_VISUAL,
    SUBITEM_BG_LAST
};

enum SUBITEM_ADDITIONAL
{
    SUBITEM_ADDITIONAL_1,
    SUBITEM_ADDITIONAL_2,
#ifndef DB3350
    SUBITEM_ADDITIONAL_3,
#endif
    SUBITEM_ADDITIONAL_LAST
};

typedef struct _SETTING_BOOK : BOOK
{
    GUI_LIST *main_menu;
    GUI_LIST *sub_menu;
    GUI_ONEOFMANY *options_menu;
    GUI *question_menu;
    GUI *color_picker;

    uint8_t element;
    uint8_t elem_type;
    bool changed;
    bool is_cover_art;
} SETTING_BOOK;

void DBPlayer_Setting(BOOK *book, GUI *gui);
int DBPlayer_Settings_onEnter(void* data, BOOK* book);
int DBPlayer_Settings_onExit(void* data, BOOK* book);
int DBPlayer_Settings_onPrev(void* data, BOOK* book);
int DBPlayer_Settings_onCancel(void* data, BOOK* book);

const PAGE_MSG base_evtlst[] =
    {
        RETURN_TO_STANDBY_EVENT, DBPlayer_Settings_onCancel,
        NIL_EVENT, NULL};

const PAGE_MSG main_evtlst[] =
    {
        PAGE_ENTER_EVENT, DBPlayer_Settings_onEnter,
        PAGE_EXIT_EVENT, DBPlayer_Settings_onExit,
        PREVIOUS_EVENT, DBPlayer_Settings_onPrev,
        CANCEL_EVENT, DBPlayer_Settings_onCancel,
        NIL_EVENT, NULL};

const PAGE_DESC DBPlayer_Settings_Base_Page = {"DBPlayer_Settings_Base_Page", NULL, base_evtlst};
const PAGE_DESC DBPlayer_Settings_Main_Page = {"DBPlayer_Settings_Main_Page", NULL, main_evtlst};

#endif
