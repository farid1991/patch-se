#ifndef _LANG_H_
#define _LANG_H_

typedef enum TEXT_ID
{
    ID_PTYPE,
    ID_PTYPE_1,
    ID_PTYPE_2,
    ID_ARTIST,
    ID_TITLE,
    ID_ALBUM,
    ID_YEAR,
    ID_GENRE,
    ID_FILETYPE,
    ID_TOTAL,
    ID_ELAPSED,
    ID_REMAINING,
    ID_BITRATE,
    ID_TIME_PROGRESS,
    ID_VOLUME_PROGRESS,
    ID_COVERART,
    ID_FRAME,
    ID_TEXT_COLOR,
    ID_COLOR_OVERLAY,
    ID_ALIGN,
    ID_ALIGN_LEFT,
    ID_ALIGN_RIGHT,
    ID_ALIGN_CENTER,
    ID_VISUAL_CONFIG,
    ID_SLIDER,
    ID_COLOR_F,
    ID_FULLSCREEN,
    ID_SOFTKEYS,
    ID_SAMPLERATE,
    ID_AUDIOOUTPUT,
    ID_STATE,
    ID_ARTIST_ICN,
    ID_TITLE_ICN,
    ID_ALBUM_ICN,
    ID_PLAYERSTATE_ICN,
    ID_BACKGROUND,
    ID_BACKGROUND_IMAGE,
    ID_BACKGROUND_THEME,
    ID_BACKGROUND_COLOR,
    ID_ADDITIONAL,
    ID_TAG_EDITOR,
} TEXT_ID;

#define TEXT_PTYPE "Type"
#define TEXT_TAG_EDITOR "Edit tag"
#define TEXT_PTYPE_1 "Type 1"
#define TEXT_PTYPE_2 "Type 2"
#define TEXT_ARTIST "Artist"
#define TEXT_TITLE "Title"
#define TEXT_ALBUM "Album"
#define TEXT_YEAR "Year"
#define TEXT_GENRE "Genre"
#define TEXT_FILETYPE "File type"
#define TEXT_TIME_T "Total time"
#define TEXT_TIME_E "Elapsed time"
#define TEXT_TIME_R "Remaining time"
#define TEXT_BITRATE "Bitrate"
#define TEXT_TIME_PROGRESS "Time (bar)"
#define TEXT_VOLUME_PROGRESS "Volume (bar)"
#define TEXT_COVERART "Cover Art"
#define TEXT_FRAME "Frame"
#define TEXT_TEXT_COLOR "Text color"
#define TEXT_COLOR_OVERLAY "Overlay color"
#define TEXT_ALIGN "Align"
#define TEXT_ALIGN_LEFT "Left"
#define TEXT_ALIGN_RIGHT "Right"
#define TEXT_ALIGN_CENTER "Center"
#define TEXT_VISUAL_CONFIG "Visual editor"
#define TEXT_SLIDER "Slider"
#define TEXT_COLOR_F "Fill color"
#define TEXT_FULLSCREEN "Fullscreen"
#define TEXT_SOFTKEYS "SoftKeys"
#define TEXT_SAMPLERATE "Samplerate"
#define TEXT_AUDIOOUTPUT "Audio output"
#define TEXT_STATE "State"
#define TEXT_ARTIST_ICN "Artist Icon"
#define TEXT_TITLE_ICN "Title Icon"
#define TEXT_ALBUM_ICN "Album Icon"
#define TEXT_PLAYERSTATE_ICN "State Icon"
#define TEXT_BACKGROUND "Background"
#define TEXT_BACKGROUND_IMAGE "Image"
#define TEXT_BACKGROUND_THEME "Theme Image"
#define TEXT_BACKGROUND_COLOR "Custom Color"
#define TEXT_ADDITIONAL "Additional"

TEXTID TextID_Global(int id);
TEXTID TextID_Setting(int id);

#endif
