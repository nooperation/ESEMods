#pragma once

#include <../D2MooHeaders.h>
#include <Units/Missile.h>
#include <CommonDefinitions.h>
#include <D2Seed.h>
#include <Units/MissileStream.h>
#include <Path/Path.h>


struct ESE_D2MissileDamageDataStrc64
{
	int32_t nFlags;								//0x00
	int64_t nMinDamage;							//0x04
	int64_t nMaxDamage;							//0x08
	int64_t nFireMinDamage;						//0x0C
	int64_t nFireMaxDamage;						//0x10
	int64_t nFireLength;						//0x14
	int64_t nLightMinDamage;					//0x18
	int64_t nLightMaxDamage;					//0x1C
	int64_t nMagicMinDamage;					//0x20
	int64_t nMagicMaxDamage;					//0x24
	int64_t nColdMinDamage;						//0x28
	int64_t nColdMaxDamage;						//0x2C
	int64_t nColdLength;						//0x30
	int64_t nPoisonMinDamage;					//0x34
	int64_t nPoisonMaxDamage;					//0x38
	int64_t nPoisonLength;						//0x3C
	int64_t nPoisonCount;						//0x40
	int64_t nLifeDrainMinDamage;				//0x44
	int64_t nLifeDrainMaxDamage;				//0x48
	int64_t nManaDrainMinDamage;				//0x4C
	int64_t nManaDrainMaxDamage;				//0x50
	int64_t nStaminaDrainMinDamage;				//0x54
	int64_t nStaminaDrainMaxDamage;				//0x58
	int64_t nStunLength;						//0x5C
	int64_t nBurningMin;						//0x60
	int64_t nBurningMax;						//0x64
	int64_t nBurnLength;						//0x68
	int64_t nDemonDamagePercent;				//0x6C
	int64_t nUndeadDamagePercent;				//0x70
	int64_t nDamageTargetAC;					//0x74
	int64_t nDamagePercent;						//0x78
};


// Inlined/helper
D2MissilesTxt* __fastcall ESE_DATATBLS_GetMissilesTxtRecord(int nMissileId);

//D2Common.0x6FDBA5B0 (#11217)
void __stdcall ESE_MISSILE_CalculateDamageData(ESE_D2MissileDamageDataStrc64* pMissileDamageData, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel);
//D2Common.0x6FDBAED0
void __fastcall ESE_MISSILE_AddStatsToDamage(ESE_D2MissileDamageDataStrc64* pMissileDamageData, D2UnitStrc* pMissile, uint8_t nShift);
//D2Common.0x6FDBB060
void __fastcall ESE_MISSILE_CalculateFinalDamage(ESE_D2MissileDamageDataStrc64* pMissileDamageData, int64_t nSrcDamage);
//D2Common.0x6FDBB1B0
int64_t __fastcall ESE_MISSILE_CalculateMasteryBonus(D2UnitStrc* pUnit, int nElemType, int64_t nSrcDamage);
//D2Common.0x6FDBB2E0 (#11218)
void __stdcall ESE_MISSILE_SetDamageStats(D2UnitStrc* pOwner, D2UnitStrc* pMissile, ESE_D2MissileDamageDataStrc64* pMissileDamageData, int nLevel);
//D2Common.0x6FDBB5A0 (#11285)
int64_t __stdcall ESE_MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBB710 (#11286)
int64_t __stdcall ESE_MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBB8C0 (#11287)
int64_t __stdcall ESE_MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBBA30 (#11288)
int64_t __stdcall ESE_MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel);
//D2Common.0x6FDBBBA0 (#11221)
int64_t __stdcall ESE_MISSILE_GetElementalLength(int nUnused, D2UnitStrc* pMissile, int nMissileId, int nLevel);
//D2Common.0x6FDBBC50 (#11290)
int64_t __stdcall ESE_MISSILE_GetSpecialParamValue(D2UnitStrc* pMissile, D2UnitStrc* pOwner, uint8_t nParamId, int nMissileId, int64_t nLevel);
//D2Common.0x6FDBC060
int64_t __fastcall ESE_MISSILE_GetCalcParamValue(int32_t nParamId, void* pUserData);
