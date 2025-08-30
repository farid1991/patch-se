#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "main.h"

extern const int TEXT_LABEL[LAST] = {0x11CC, 0x13BE, 0x2FB};
const char KEY_SND_ID[2] = {1, 2};

void set_keysound_id(char keysound_id)
{
    int file = _fopen(SETTINGS_PATH, SETTINGS_FILE, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (file >= 0)
    {
        fwrite(file, &keysound_id, 1);
        fclose(file);
    }
}

extern "C" char get_keysound_id()
{
    char keysound_id = 0;
    int file = _fopen(SETTINGS_PATH, SETTINGS_FILE, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
    if (file >= 0)
    {
        fread(file, &keysound_id, 1);
        fclose(file);
    }
    return keysound_id;
}

extern "C" int get_keysound_txt()
{
    char idx = get_keysound_id();
    return TEXT_LABEL[idx];
}

extern "C" void new_key_sound(int key, int r1, int mode, int r3)
{
    default_key_handler(key, r1, mode, r3); // r2 == is_pressed? r3 == count?
    if (get_keysound_id() == CLICK)
        PlayFileV(SOUND_PATH, L"messageclick.mid", 4);
}

extern "C" void new_checkbox_act(BOOK *book, GUI *gui)
{
    char selected = OneOfMany_GetSelected(gui);
    if (selected < 2)
        REQUEST_SETTING_KEYSOUND_SET(SYNC, -2, KEY_SND_ID[selected]);

    set_keysound_id(selected);
    destroy_bookobj(book);
}
