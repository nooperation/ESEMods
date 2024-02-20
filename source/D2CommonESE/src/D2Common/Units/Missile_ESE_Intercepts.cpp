#include "D2Common/Units/Missile_ESE_Intercepts.h"

decltype(&MISSILE_CalculateDamageData) MISSILE_CalculateDamageData_Original = nullptr;
decltype(&MISSILE_AddStatsToDamage) MISSILE_AddStatsToDamage_Original = nullptr;
decltype(&MISSILE_CalculateFinalDamage) MISSILE_CalculateFinalDamage_Original = nullptr;
decltype(&MISSILE_CalculateMasteryBonus) MISSILE_CalculateMasteryBonus_Original = nullptr;
decltype(&MISSILE_SetDamageStats) MISSILE_SetDamageStats_Original = nullptr;
decltype(&MISSILE_GetMinDamage) MISSILE_GetMinDamage_Original = nullptr;
decltype(&MISSILE_GetMaxDamage) MISSILE_GetMaxDamage_Original = nullptr;
decltype(&MISSILE_GetMinElemDamage) MISSILE_GetMinElemDamage_Original = nullptr;
decltype(&MISSILE_GetMaxElemDamage) MISSILE_GetMaxElemDamage_Original = nullptr;
decltype(&MISSILE_GetElementalLength) MISSILE_GetElementalLength_Original = nullptr;
decltype(&MISSILE_GetSpecialParamValue) MISSILE_GetSpecialParamValue_Original = nullptr;
decltype(&MISSILE_GetCalcParamValue) MISSILE_GetCalcParamValue_Original = nullptr;
decltype(&MISSILE_GetMinimum) MISSILE_GetMinimum_Original = nullptr;
decltype(&MISSILE_GetMaximum) MISSILE_GetMaximum_Original = nullptr;
decltype(&MISSILE_GetRandomNumberInRange) MISSILE_GetRandomNumberInRange_Original = nullptr;
decltype(&MISSILE_GetSpecialParamValueForSkillMissile) MISSILE_GetSpecialParamValueForSkillMissile_Original = nullptr;
decltype(&MISSILE_EvaluateMissileFormula) MISSILE_EvaluateMissileFormula_Original = nullptr;

void __stdcall ESE_INTERCEPT_MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel)
{
    ESE_MISSILE_CalculateDamageData(pMissileDamageData, pOwner, pOrigin, pMissile, nLevel);
}

void __fastcall ESE_INTERCEPT_MISSILE_AddStatsToDamage(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift)
{
    ESE_MISSILE_AddStatsToDamage(pMissileDamageData, pMissile, nShift);
}

void __fastcall ESE_INTERCEPT_MISSILE_CalculateFinalDamage(D2MissileDamageDataStrc* pMissileDamageData, int nSrcDamage)
{
    ESE_MISSILE_CalculateFinalDamage(pMissileDamageData, nSrcDamage);
}

int __fastcall ESE_INTERCEPT_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage)
{
    return ESE_MISSILE_CalculateMasteryBonus(pUnit, nElemType, nSrcDamage);
}

void __stdcall ESE_INTERCEPT_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel)
{
    ESE_MISSILE_SetDamageStats(pOwner, pMissile, pMissileDamageData, nLevel);
}

int __stdcall ESE_INTERCEPT_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    return ESE_MISSILE_GetMinDamage(pMissile, pOwner, nMissileId, nLevel);
}

int __stdcall ESE_INTERCEPT_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    return ESE_MISSILE_GetMaxDamage(pMissile, pOwner, nMissileId, nLevel);
}

int __stdcall ESE_INTERCEPT_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    return ESE_MISSILE_GetMinElemDamage(pMissile, pOwner, nMissileId, nLevel);
}

int __stdcall ESE_INTERCEPT_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel)
{
    return ESE_MISSILE_GetMaxElemDamage(pMissile, pOwner, nMissileId, nLevel);
}

int __stdcall ESE_INTERCEPT_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel)
{
    return ESE_MISSILE_GetElementalLength(nUnused, pMissile, nMissileId, nLevel);
}

int __stdcall ESE_INTERCEPT_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int nLevel)
{
    return ESE_MISSILE_GetSpecialParamValue(pMissile, pOwner, nParamId, nMissileId, nLevel);
}

int __fastcall ESE_INTERCEPT_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData)
{
    return ESE_MISSILE_GetCalcParamValue(nParamId, pUserData);
}

int __fastcall ESE_INTERCEPT_MISSILE_GetMinimum(int a1, int a2, int a3, void* pUserData)
{
    return ESE_MISSILE_GetMinimum(a1, a2, a3, pUserData);
}

int __fastcall ESE_INTERCEPT_MISSILE_GetMaximum(int a1, int a2, int a3, void* pUserData)
{
    return ESE_MISSILE_GetMaximum(a1, a2, a3, pUserData);
}

int __fastcall ESE_INTERCEPT_MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    return ESE_MISSILE_GetRandomNumberInRange(nMin, nMax, nUnused, pUserData);
}

int __fastcall ESE_INTERCEPT_MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData)
{
    return ESE_MISSILE_GetSpecialParamValueForSkillMissile(nSkillId, nParamId, nUnused, pUserData);
}

int __stdcall ESE_INTERCEPT_MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel)
{
    return ESE_MISSILE_EvaluateMissileFormula(pMissile, pOwner, nCalc, nMissileId, nLevel);
}
