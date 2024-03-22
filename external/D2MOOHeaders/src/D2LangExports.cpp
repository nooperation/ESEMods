#include "../D2LangExports.h"

STRTABLE_GetLanguage_t STRTABLE_GetLanguage = nullptr;
D2LANG_GetStringByReferenceString_t D2LANG_GetStringByReferenceString = nullptr;
D2LANG_GetStringFromTblIndex_t D2LANG_GetStringFromTblIndex = nullptr;
D2LANG_GetTblIndex_t D2LANG_GetTblIndex = nullptr;
D2LANG_Unicode_Personalize_t D2LANG_Unicode_Personalize = nullptr;

void InitD2LangExports()
{
    auto d2LangModule = GetModuleHandle("D2Lang");

    STRTABLE_GetLanguage = (STRTABLE_GetLanguage_t)GetProcAddress(d2LangModule, (LPCSTR)10007);

    D2LANG_GetStringByReferenceString = (D2LANG_GetStringByReferenceString_t)GetProcAddress(d2LangModule, (LPCSTR)10003);
    D2LANG_GetStringFromTblIndex = (D2LANG_GetStringFromTblIndex_t)GetProcAddress(d2LangModule, (LPCSTR)10004);
    D2LANG_GetTblIndex = (D2LANG_GetTblIndex_t)GetProcAddress(d2LangModule, (LPCSTR)10013);

    D2LANG_Unicode_Personalize = (D2LANG_Unicode_Personalize_t)GetProcAddress(d2LangModule, (LPCSTR)10018);
}
