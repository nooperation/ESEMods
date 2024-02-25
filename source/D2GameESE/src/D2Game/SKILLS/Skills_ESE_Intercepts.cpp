#include "D2Game/SKILLS/Skills_ESE_Intercepts.h"

sub_6FD0F8B0_t sub_6FD0F8B0_Original = nullptr;
sub_6FD0FA00_t sub_6FD0FA00_Original = nullptr;
sub_6FD0FDD0_t sub_6FD0FDD0_Original = nullptr;
sub_6FD0FE50_t sub_6FD0FE50_Original = nullptr;
sub_6FD0FE80_t sub_6FD0FE80_Original = nullptr;
sub_6FD10140_t sub_6FD10140_Original = nullptr;
sub_6FD10200_t sub_6FD10200_Original = nullptr;
sub_6FD10250_t sub_6FD10250_Original = nullptr;
sub_6FD10360_t sub_6FD10360_Original = nullptr;
SKILLS_FindAuraTarget_t SKILLS_FindAuraTarget_Original = nullptr;
sub_6FD106F0_t sub_6FD106F0_Original = nullptr;
sub_6FD10790_t sub_6FD10790_Original = nullptr;
sub_6FD107E0_t sub_6FD107E0_Original = nullptr;
sub_6FD107F0_t sub_6FD107F0_Original = nullptr;
sub_6FD10880_t sub_6FD10880_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_sub_6FD0F8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nValue)
{
    return ESE_sub_6FD0F8B0(pGame, pUnit, nValue);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, uint32_t nAuraFilter)
{
    return ESE_sub_6FD0FA00(pUnit, pTarget, nAuraFilter);
}

void __fastcall ESE_INTERCEPT_sub_6FD0FDD0(D2UnitStrc* pUnit)
{
    ESE_sub_6FD0FDD0(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD0FE50(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs)
{
    ESE_sub_6FD0FE50(pGame, pUnit, pCallback, pArgs);
}

void __fastcall ESE_INTERCEPT_sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int32_t bCheckMonAuraFlag, const char* szFile, int32_t nLine)
{
    ESE_sub_6FD0FE80(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, pCallback, pCallbackArgs, bCheckMonAuraFlag, szFile, nLine);
}

void __fastcall ESE_INTERCEPT_sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nUnused)
{
    ESE_sub_6FD10140(pGame, pAttackerArg, pUnit, pDamage, nUnused);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, D2DamageStrc* pDamage, uint32_t nAuraFilter)
{
    return ESE_sub_6FD10200(pGame, pUnit, nX, nY, nAuraRange, pDamage, nAuraFilter);
}

void __fastcall ESE_INTERCEPT_sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nState, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD10250(pGame, pUnit, pTarget, nState, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10360(D2GameStrc* pGame, uint32_t nFlags, D2UnitStrc* pUnit, int32_t nDistance, int32_t(__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs)
{
    return ESE_sub_6FD10360(pGame, nFlags, pUnit, nDistance, pCallback, pArgs);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nAuraRange, int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*))
{
    return ESE_SKILLS_FindAuraTarget(pGame, pUnit, nAuraRange, pCallback);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD106F0(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter)
{
    return ESE_sub_6FD10790(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD107E0(pAuraCallback, pUnit);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t a7, int32_t* a8)
{
    return ESE_sub_6FD107F0(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, a7, a8);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD10880(pAuraCallback, pUnit);
}


