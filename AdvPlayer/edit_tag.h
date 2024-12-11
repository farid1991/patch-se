#ifndef _EditTag_h_
#define _EditTag_h_

#define _ELF(__NAME__) ZBIN_PATH L"/" L##__NAME__
#define ELF(__NAME__) _ELF(__NAME__)

void tagedit_start_elf(BOOK *book, GUI *gui);

#endif
