#include "D2Common/Units/Missile_ESE_Intercepts.h"

MISSILE_CalculateDamageData_t MISSILE_CalculateDamageData_Original = nullptr;
MISSILE_AddStatsToDamage_t MISSILE_AddStatsToDamage_Original = nullptr;
MISSILE_CalculateFinalDamage_t MISSILE_CalculateFinalDamage_Original = nullptr;
MISSILE_CalculateMasteryBonus_t MISSILE_CalculateMasteryBonus_Original = nullptr;
MISSILE_SetDamageStats_t MISSILE_SetDamageStats_Original = nullptr;
MISSILE_GetMinDamage_t MISSILE_GetMinDamage_Original = nullptr;
MISSILE_GetMaxDamage_t MISSILE_GetMaxDamage_Original = nullptr;
MISSILE_GetMinElemDamage_t MISSILE_GetMinElemDamage_Original = nullptr;
MISSILE_GetMaxElemDamage_t MISSILE_GetMaxElemDamage_Original = nullptr;
MISSILE_GetElementalLength_t MISSILE_GetElementalLength_Original = nullptr;
MISSILE_GetSpecialParamValue_t MISSILE_GetSpecialParamValue_Original = nullptr;
MISSILE_GetCalcParamValue_t MISSILE_GetCalcParamValue_Original = nullptr;
MISSILE_GetMinimum_t MISSILE_GetMinimum_Original = nullptr;
MISSILE_GetMaximum_t MISSILE_GetMaximum_Original = nullptr;
MISSILE_GetRandomNumberInRange_t MISSILE_GetRandomNumberInRange_Original = nullptr;
MISSILE_GetSpecialParamValueForSkillMissile_t MISSILE_GetSpecialParamValueForSkillMissile_Original = nullptr;
MISSILE_EvaluateMissileFormula_t MISSILE_EvaluateMissileFormula_Original = nullptr;

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
