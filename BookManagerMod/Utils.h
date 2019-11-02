#ifndef _UTILS_H_
  #define _UTILS_H_

#define SC_NAME   L"sc.bin"

__arm void runElf(const wchar_t* elfpath, const wchar_t* param_1, const wchar_t* param_2);
void LoadBcfgedit(const wchar_t* bcfgpath, const wchar_t* bcfgname);

void GetIconByName(wchar_t* name, int &id);
TEXTID GetJavaName( BOOK* book );
void StartJava_ByName(wchar_t* name);
void ExecuteEvent(wchar_t *name);
void OpenFolder(wchar_t * folders);

LIST* LoadShortcut();

#pragma swi_number=0x10D
__swi __arm int elfload( const wchar_t* filename, void* param1, void* param2, void* param3 );

#endif
