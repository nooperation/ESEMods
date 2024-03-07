#include "../D2LangExports.h"

STRTABLE_GetLanguage_t STRTABLE_GetLanguage = nullptr;

void InitD2LangExports()
{
    auto d2LangModule = GetModuleHandle("D2Lang");

    STRTABLE_GetLanguage = (STRTABLE_GetLanguage_t)GetProcAddress(d2LangModule, (LPCSTR)10007);
}
