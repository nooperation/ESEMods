#pragma once

#include <Windows.h>
#include <cstdint>
#include <D2Constants.h>

void InitD2LangExports();

typedef D2C_Language (__fastcall *STRTABLE_GetLanguage_t)();

extern STRTABLE_GetLanguage_t STRTABLE_GetLanguage;
