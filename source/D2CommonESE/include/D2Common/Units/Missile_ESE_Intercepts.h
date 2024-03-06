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

extern MISSILE_CalculateDamageData_t MISSILE_CalculateDamageData_Original;
void __stdcall ESE_INTERCEPT_MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel);

extern MISSILE_AddStatsToDamage_t MISSILE_AddStatsToDamage_Original;
void __fastcall ESE_INTERCEPT_MISSILE_AddStatsToDamage(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift);

extern MISSILE_CalculateFinalDamage_t MISSILE_CalculateFinalDamage_Original;
void __fastcall ESE_INTERCEPT_MISSILE_CalculateFinalDamage(D2MissileDamageDataStrc* pMissileDamageData, int nSrcDamage);

extern MISSILE_CalculateMasteryBonus_t MISSILE_CalculateMasteryBonus_Original;
int __fastcall ESE_INTERCEPT_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);

extern MISSILE_SetDamageStats_t MISSILE_SetDamageStats_Original;
void __stdcall ESE_INTERCEPT_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel);

extern MISSILE_GetMinDamage_t MISSILE_GetMinDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern MISSILE_GetMaxDamage_t MISSILE_GetMaxDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern MISSILE_GetMinElemDamage_t MISSILE_GetMinElemDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern MISSILE_GetMaxElemDamage_t MISSILE_GetMaxElemDamage_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);

extern MISSILE_GetElementalLength_t MISSILE_GetElementalLength_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel);

extern MISSILE_GetSpecialParamValue_t MISSILE_GetSpecialParamValue_Original;
int __stdcall ESE_INTERCEPT_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int nLevel);

extern MISSILE_GetCalcParamValue_t MISSILE_GetCalcParamValue_Original;
int __fastcall ESE_INTERCEPT_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData);
