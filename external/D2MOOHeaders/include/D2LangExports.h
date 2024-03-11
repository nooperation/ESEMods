#pragma once

#include <Windows.h>
#include <cstdint>
#include <D2Constants.h>
#include <D2Unicode.h>

void InitD2LangExports();

typedef D2C_Language (__fastcall *STRTABLE_GetLanguage_t)();

typedef const Unicode* (__fastcall* D2LANG_GetStringByReferenceString_t)(char* string);
typedef const Unicode* (__fastcall* D2LANG_GetStringFromTblIndex_t)(short index);
typedef short(__stdcall* D2LANG_GetTblIndex_t)(char* szReference, const Unicode** pUnicode);

extern STRTABLE_GetLanguage_t STRTABLE_GetLanguage;

extern D2LANG_GetStringByReferenceString_t D2LANG_GetStringByReferenceString;
extern D2LANG_GetStringFromTblIndex_t D2LANG_GetStringFromTblIndex;
extern D2LANG_GetTblIndex_t D2LANG_GetTblIndex;
