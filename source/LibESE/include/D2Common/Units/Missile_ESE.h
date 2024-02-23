#pragma once

#include <../D2MooHeaders.h>
#include <Units/Missile.h>
#include <CommonDefinitions.h>
#include <D2Seed.h>
#include <Units/MissileStream.h>
#include <Path/Path.h>

// Inlined/helper
D2MissilesTxt* __fastcall ESE_DATATBLS_GetMissilesTxtRecord(int nMissileId);

//D2Common.0x6FDBA5B0 (#11217)
void __stdcall ESE_MISSILE_CalculateDamageData(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel);
//D2Common.0x6FDBAED0
void __fastcall ESE_MISSILE_AddStatsToDamage(D2MissileDamageDataStrc* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift);
//D2Common.0x6FDBB060
void __fastcall ESE_MISSILE_CalculateFinalDamage(D2MissileDamageDataStrc* pMissileDamageData, int nSrcDamage);
//D2Common.0x6FDBB1B0
int __fastcall ESE_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int nSrcDamage);
//D2Common.0x6FDBB2E0 (#11218)
void __stdcall ESE_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2MissileDamageDataStrc* pMissileDamageData, int nLevel);
//D2Common.0x6FDBB5A0 (#11285)
int __stdcall ESE_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBB710 (#11286)
int __stdcall ESE_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBB8C0 (#11287)
int __stdcall ESE_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBBA30 (#11288)
int __stdcall ESE_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBBBA0 (#11221)
int __stdcall ESE_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel);
//D2Common.0x6FDBBC50 (#11290)
int __stdcall ESE_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int nLevel);
//D2Common.0x6FDBC060
int __fastcall ESE_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData);
//D2Common.0x6FDBC080
int __fastcall ESE_MISSILE_GetMinimum(int a1, int a2, int a3, void* pUserData);
//D2Common.0x6FDBC090
int __fastcall ESE_MISSILE_GetMaximum(int a1, int a2, int a3, void* pUserData);
//D2Common.0x6FDBC0A0
int __fastcall ESE_MISSILE_GetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData);
//D2Common.0x6FDBC120
int __fastcall ESE_MISSILE_GetSpecialParamValueForSkillMissile(int nSkillId, int nParamId, int nUnused, void* pUserData);
//D2Common.0x6FDBC170 (#11284)
int __stdcall ESE_MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel);
