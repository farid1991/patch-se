#ifndef _Main_H_
#define _Main_H_

enum
{
    NONE,
    TONE,
    CLICK,
    LAST
};

#define SETTINGS_FILE L"keysound.bin"

extern "C"
{
    void default_key_handler(int, int, int, int);
    int REQUEST_SETTING_KEYSOUND_SET(const int *sync, int flag, int sound_id);
    void destroy_bookobj(BOOK *book);
}

#endif
