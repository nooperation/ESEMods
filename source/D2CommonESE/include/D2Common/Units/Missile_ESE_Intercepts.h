#pragma once

#include <D2Common/Units/Missile_ESE.h>

#include <CommonDefinitions.h>
#include <D2Seed.h>
#include <Units/MissileStream.h>
#include <Path/Path.h>

#include <cstdlib>

//D2Common.0x6FDBA5B0
void __stdcall ESE_INTERCEPT_MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel);
//D2Common.0x6FDBAED0
void __fastcall ESE_INTERCEPT_MISSILE_AddStatsToDamage(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift);
//D2Common.0x6FDBB060
void __fastcall ESE_INTERCEPT_MISSILE_CalculateFinalDamage(D2MissileDamageDataStrc* pMissileDamageData, int nSrcDamage);
//D2Common.0x6FDBB1B0
int __fastcall ESE_INTERCEPT_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);
//D2Common.0x6FDBB2E0
void __stdcall ESE_INTERCEPT_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel);
//D2Common.0x6FDBB5A0
int __stdcall ESE_INTERCEPT_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBB710
int __stdcall ESE_INTERCEPT_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBB8C0
int __stdcall ESE_INTERCEPT_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBBA30
int __stdcall ESE_INTERCEPT_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBBBA0
int __stdcall ESE_INTERCEPT_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel);
//D2Common.0x6FDBBC50
int __stdcall ESE_INTERCEPT_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int nLevel);
//D2Common.0x6FDBC060
int __fastcall ESE_INTERCEPT_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData);
//D2Common.0x6FDBC080
int __fastcall ESE_INTERCEPT_MISSILE_GetMinimum(int a1, int a2, int a3, void* pUserData);
//D2Common.0x6FDBC090
int __fastcall ESE_INTERCEPT_MISSILE_GetMaximum(int a1, int a2, int a3, void* pUserData);
//D2Common.0x6FDBC0A0
int __fastcall ESE_INTERCEPT_MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData);
//D2Common.0x6FDBC120
int __fastcall ESE_INTERCEPT_MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData);
//D2Common.0x6FDBC170
int __stdcall ESE_INTERCEPT_MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel);

extern decltype(&MISSILE_CalculateDamageData) MISSILE_CalculateDamageData_Original;
void __stdcall ESE_INTERCEPT_MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel);

extern decltype(&MISSILE_AddStatsToDamage) MISSILE_AddStatsToDamage_Original;
void __fastcall ESE_INTERCEPT_MISSILE_AddStatsToDamage(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift);

extern decltype(&MISSILE_CalculateFinalDamage) MISSILE_CalculateFinalDamage_Original;
void __fastcall ESE_INTERCEPT_MISSILE_CalculateFinalDamage(D2MissileDamageDataStrc* pMissileDamageData, int nSrcDamage);

extern decltype(&MISSILE_CalculateMasteryBonus) MISSILE_CalculateMasteryBonus_Original;
int __fastcall ESE_INTERCEPT_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);

extern decltype(&MISSILE_SetDamageStats) MISSILE_SetDamageStats_Original;
void __stdcall ESE_INTERCEPT_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel);

extern decltype(&MISSILE_GetMinDamage) MISSILE_GetMinDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern decltype(&MISSILE_GetMaxDamage) MISSILE_GetMaxDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern decltype(&MISSILE_GetMinElemDamage) MISSILE_GetMinElemDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern decltype(&MISSILE_GetMaxElemDamage) MISSILE_GetMaxElemDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern decltype(&MISSILE_GetElementalLength) MISSILE_GetElementalLength_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel);

extern decltype(&MISSILE_GetSpecialParamValue) MISSILE_GetSpecialParamValue_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int nLevel);

extern decltype(&MISSILE_GetCalcParamValue) MISSILE_GetCalcParamValue_Original;
int __fastcall ESE_INTERCEPT_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData);

extern decltype(&MISSILE_GetMinimum) MISSILE_GetMinimum_Original;
int __fastcall ESE_INTERCEPT_MISSILE_GetMinimum(int a1, int a2, int a3, void* pUserData);

extern decltype(&MISSILE_GetMaximum) MISSILE_GetMaximum_Original;
int __fastcall ESE_INTERCEPT_MISSILE_GetMaximum(int a1, int a2, int a3, void* pUserData);

extern decltype(&MISSILE_GetRandomNumberInRange) MISSILE_GetRandomNumberInRange_Original;
int __fastcall ESE_INTERCEPT_MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData);

extern decltype(&MISSILE_GetSpecialParamValueForSkillMissile) MISSILE_GetSpecialParamValueForSkillMissile_Original;
int __fastcall ESE_INTERCEPT_MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData);

extern decltype(&MISSILE_EvaluateMissileFormula) MISSILE_EvaluateMissileFormula_Original;
int __stdcall ESE_INTERCEPT_MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel);

