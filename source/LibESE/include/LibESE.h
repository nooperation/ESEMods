#pragma once

#include <chrono>
#include <thread>
#include <type_traits>
#include <cstdlib>
#include <algorithm>
#include "D2Seed.h"
#include <UNIT/SUnitDmg.h>


int64_t __fastcall ESE_DATATBLS_ApplyRatio(int64_t nValue, int64_t nMultiplier, int64_t nDivisor);
int64_t __fastcall ESE_ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int64_t nMax);

inline constexpr int32_t Clamp64To32(const int64_t value)
{
    return static_cast<int32_t>(std::clamp<int64_t>(value, INT_MIN, INT_MAX));
}
inline constexpr uint32_t Clamp64To32Unsigned(const int64_t value)
{
	return static_cast<uint32_t>(std::clamp<int64_t>(value, 0, UINT32_MAX));
}

#pragma pack(push, 1)
struct D2DamageReportPacket
{
    uint8_t packetId;
    uint8_t isPlayerBeingAttacked;
    uint32_t unitId;
    int64_t damage;
};

struct ESE_D2DamageStrc
{
	ESE_D2DamageStrc();
	ESE_D2DamageStrc(const D2DamageStrc* src);
	void WriteToOriginalStruct(D2DamageStrc* dest);

	uint32_t dwHitFlags;					//0x00
	uint16_t wResultFlags;					//0x04
	uint16_t wExtra;						//0x06
	int64_t dwPhysDamage;					//0x08
	int64_t dwEnDmgPct;						//0x0C
	int64_t dwFireDamage;					//0x10
	int64_t dwBurnDamage;					//0x14
	int64_t dwBurnLen;						//0x18
	int64_t dwLtngDamage;					//0x1C
	int64_t dwMagDamage;					//0x20
	int64_t dwColdDamage;					//0x24
	int64_t dwPoisDamage;					//0x28
	int64_t dwPoisLen;						//0x2C
	int64_t dwColdLen;						//0x30
	int64_t dwFrzLen;						//0x34
	int64_t dwLifeLeech;					//0x38
	int64_t dwManaLeech;					//0x3C
	int64_t dwStamLeech;					//0x40
	int64_t dwStunLen;						//0x44
	int64_t dwAbsLife;						//0x48
	int64_t dwDmgTotal;						//0x4C
	uint32_t unk0x50;						//0x50
	int64_t dwPiercePct;					//0x54
	int64_t dwDamageRate;					//0x58
	uint32_t unk0x5C;						//0x5C
	uint32_t dwHitClass;					//0x60
	uint8_t nHitClassActiveSet;				//0x64
	int8_t nConvType;						//0x65
	uint8_t unk0x66[2];						//0x66
	int32_t dwConvPct;						//0x68
	int32_t nOverlay;						//0x6C
};

struct ESE_D2CombatStrc
{
	D2GameStrc* pGame;						//0x00
	uint32_t dwAttackerType;				//0x04
	uint32_t dwAttackerId;					//0x08
	uint32_t dwDefenderType;				//0x0C
	uint32_t dwDefenderId;					//0x10
	ESE_D2DamageStrc tDamage;					//0x14
	ESE_D2CombatStrc* pNext;					//0x84
};

struct ESE_D2DamageInfoStrc
{
	D2GameStrc* pGame;
	D2DifficultyLevelsTxt* pDifficultyLevelsTxt;
	D2UnitStrc* pAttacker;
	D2UnitStrc* pDefender;
	int32_t bAttackerIsMonster;
	int32_t bDefenderIsMonster;
	ESE_D2DamageStrc* pDamage;
	int64_t nDamageReduction[DAMAGE_REDUCTION_TYPES_COUNT];
};
#pragma pack(pop)

