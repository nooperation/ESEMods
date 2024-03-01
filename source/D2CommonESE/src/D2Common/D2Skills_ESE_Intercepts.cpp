#include "D2Common/D2Skills_ESE_Intercepts.h"
#include "LibESE.h"

SKILLS_GetSpecialParamValue_t SKILLS_GetSpecialParamValue_Original = nullptr;
SKILLS_GetManaCosts_t SKILLS_GetManaCosts_Original = nullptr;
SKILLS_CalculateDamageBonusByLevel_t SKILLS_CalculateDamageBonusByLevel_Original = nullptr;
SKILLS_GetMinPhysDamage_t SKILLS_GetMinPhysDamage_Original = nullptr;
SKILLS_GetMaxPhysDamage_t SKILLS_GetMaxPhysDamage_Original = nullptr;
SKILLS_GetMinElemDamage_t SKILLS_GetMinElemDamage_Original = nullptr;
SKILLS_CalculateMasteryBonus_t SKILLS_CalculateMasteryBonus_Original = nullptr;
SKILLS_GetMaxElemDamage_t SKILLS_GetMaxElemDamage_Original = nullptr;
SKILLS_GetElementalLength_t SKILLS_GetElementalLength_Original = nullptr;
D2Common_11028_t D2Common_11028_Original = nullptr;
D2Common_11033_t D2Common_11033_Original = nullptr;
SKILLS_GetConcentrationDamageBonus_t SKILLS_GetConcentrationDamageBonus_Original = nullptr;
SKILLS_CalculateKickDamage_t SKILLS_CalculateKickDamage_Original = nullptr;

int __stdcall ESE_INTERCEPT_SKILLS_GetSpecialParamValue(D2UnitStrc* pUnit, uint8_t nParamId, int nSkillId, int nSkillLevel)
{
    auto result = ESE_SKILLS_GetSpecialParamValue(pUnit, nParamId, nSkillId, nSkillLevel);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetManaCosts(int nSkillId, int nSkillLevel)
{
    auto result = ESE_SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    return Clamp64To32(result);
}

int __fastcall ESE_INTERCEPT_SKILLS_CalculateDamageBonusByLevel(int nLevel, int* pLevelDamage)
{
    auto result = ESE_SKILLS_CalculateDamageBonusByLevel(nLevel, pLevelDamage);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    auto result = ESE_SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, a4);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    auto result = ESE_SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, a4);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    auto result = ESE_SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, a4);
    return Clamp64To32(result);
}

int __fastcall ESE_INTERCEPT_SKILLS_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
    auto result = ESE_SKILLS_CalculateMasteryBonus(pUnit, nElemType, nSrcDamage);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL a4)
{
    auto result = ESE_SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, a4);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, BOOL bUnused)
{
    auto result = ESE_SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, bUnused);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_D2Common_11028(int a1)
{
    auto result = ESE_D2Common_11028(a1);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_D2Common_11033(int nLevel, int nParam, int nMax)
{
    auto result = ESE_D2Common_11033(nLevel, nParam, nMax);
    return Clamp64To32(result);
}

int __stdcall ESE_INTERCEPT_SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId)
{
    auto result = ESE_SKILLS_GetConcentrationDamageBonus(pUnit, nSkillId);
    return Clamp64To32(result);
}

void __stdcall ESE_INTERCEPT_SKILLS_CalculateKickDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pDamagePercent)
{
    int64_t pMinDamageTemp = *pMinDamage;
    int64_t pMaxDamageTemp = *pMaxDamage;
    int64_t pDamagePercentTemp = *pDamagePercent;

    ESE_SKILLS_CalculateKickDamage(pUnit, &pMinDamageTemp, &pMaxDamageTemp, &pDamagePercentTemp);

    *pMinDamage = Clamp64To32(pMinDamageTemp);
    *pMaxDamage = Clamp64To32(pMaxDamageTemp);
    *pDamagePercent = Clamp64To32(pDamagePercentTemp);
}
