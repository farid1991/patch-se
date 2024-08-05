#ifndef _EDITTAG_H_
#define _EDITTAG_H_

static wchar_t *ZBIN_INT =L"/usb/other/ZBin";
static wchar_t *ZBIN_EXT= L"/card/other/ZBin";
static wchar_t *MTAGGER =L"MusicTagger.elf";
static wchar_t *TAGEDITOR =L"TagEditor.elf";

static wchar_t *USB_MTAGGER = L"/usb/other/ZBin/MusicTagger.elf";
static wchar_t *USB_TAGEDITOR = L"/usb/other/ZBin/TagEditor.elf";
static wchar_t *CARD_MTAGGER = L"/card/other/ZBin/MusicTagger.elf";
static wchar_t *CARD_TAGEDITOR = L"/card/other/ZBin/TagEditor.elf";

void Enter_EditTag(BOOK *book, GUI *gui);

#endif
