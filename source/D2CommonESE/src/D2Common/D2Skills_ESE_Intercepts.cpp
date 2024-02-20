#include "D2Common/D2Skills_ESE_Intercepts.h"

decltype(&SKILLS_GetSpecialParamValue) SKILLS_GetSpecialParamValue_Original = nullptr;
decltype(&SKILLS_GetManaCosts) SKILLS_GetManaCosts_Original = nullptr;
decltype(&SKILLS_CalculateDamageBonusByLevel) SKILLS_CalculateDamageBonusByLevel_Original = nullptr;
decltype(&SKILLS_GetMinPhysDamage) SKILLS_GetMinPhysDamage_Original = nullptr;
decltype(&SKILLS_GetMaxPhysDamage) SKILLS_GetMaxPhysDamage_Original = nullptr;
decltype(&SKILLS_GetMinElemDamage) SKILLS_GetMinElemDamage_Original = nullptr;
decltype(&SKILLS_CalculateMasteryBonus) SKILLS_CalculateMasteryBonus_Original = nullptr;
decltype(&SKILLS_GetMaxElemDamage) SKILLS_GetMaxElemDamage_Original = nullptr;
decltype(&SKILLS_GetElementalLength) SKILLS_GetElementalLength_Original = nullptr;
decltype(&D2Common_11028) D2Common_11028_Original = nullptr;
decltype(&D2Common_11033) D2Common_11033_Original = nullptr;
decltype(&SKILLS_GetConcentrationDamageBonus) SKILLS_GetConcentrationDamageBonus_Original = nullptr;
decltype(&SKILLS_CalculateKickDamage) SKILLS_CalculateKickDamage_Original = nullptr;

int __stdcall ESE_INTERCEPT_SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, uint8_t nParamId, int nSkillId, int nSkillLevel)
{
    return ESE_SKILLS_GetSpecialParamValue(pUnit, nParamId, nSkillId, nSkillLevel);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetManaCosts(int nSkillId, int nSkillLevel)
{
    return ESE_SKILLS_GetManaCosts(nSkillId, nSkillLevel);
}

int __fastcall ESE_INTERCEPT_SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage)
{
    return ESE_SKILLS_CalculateDamageBonusByLevel(nLevel, pLevelDamage);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    return ESE_SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, a4);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    return ESE_SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, a4);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    return ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, a4);
}

int __fastcall ESE_INTERCEPT_SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
    return ESE_SKILLS_CalculateMasteryBonus(pUnit, nElemType, nSrcDamage);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    return ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, a4);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL bUnused)
{
    return ESE_SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, bUnused);
}

int __stdcall ESE_INTERCEPT_D2Common_11028(int a1)
{
    return ESE_D2Common_11028(a1);
}

int __stdcall ESE_INTERCEPT_D2Common_11033(int nLevel, int nParam, int nMax)
{
    return ESE_D2Common_11033(nLevel, nParam, nMax);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId)
{
    return ESE_SKILLS_GetConcentrationDamageBonus(pUnit, nSkillId);
}

void __stdcall ESE_INTERCEPT_SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent)
{
    ESE_SKILLS_CalculateKickDamage(pUnit, pMinDamage, pMaxDamage, pDamagePercent);
}
