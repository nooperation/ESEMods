#pragma once

#include <Units/Units.h>

#include <D2DataTbls.h>

enum D2DamageResultFlags
{
	DAMAGERESULTFLAG_SUCCESSFULHIT = 0x00000001,
	DAMAGERESULTFLAG_WILLDIE = 0x00000002,
	DAMAGERESULTFLAG_GETHIT = 0x00000004,
	DAMAGERESULTFLAG_KNOCKBACK = 0x00000008,
	DAMAGERESULTFLAG_BLOCK = 0x00000010,
	DAMAGERESULTFLAG_32 = 0x00000020,//TODO: Name
	//DAMAGERESULTFLAG_WILLDIE7 = 0x00000040,
	DAMAGERESULTFLAG_DODGE = 0x00000080,
	DAMAGERESULTFLAG_AVOID = 0x00000100,
	DAMAGERESULTFLAG_EVADE = 0x00000200,
	//DAMAGERESULTFLAG_WILLDIE11 = 0x00000400,
	//DAMAGERESULTFLAG_WILLDIE12 = 0x00000800,
	//DAMAGERESULTFLAG_WILLDIE13 = 0x00001000,
	DAMAGERESULTFLAG_CRITICALSTRIKE = 0x00002000,
	DAMAGERESULTFLAG_SOFTHIT = 0x00004000,
	DAMAGERESULTFLAG_WEAPONBLOCK = 0x00008000,
};

enum D2DamageHitFlags
{
	DAMAGEHITFLAG_1 = 0x00000001,//TODO: Name
	DAMAGEHITFLAG_2 = 0x00000002,//TODO: Name
	DAMAGEHITFLAG_LIFEDRAIN = 0x00000004,
	DAMAGEHITFLAG_MANADRAIN = 0x00000008,
	DAMAGEHITFLAG_STAMINADRAIN = 0x00000010,
	DAMAGEHITFLAG_32 = 0x00000020,//TODO: Name
	//DAMAGEHITFLAG_64 = 0x00000040,
	DAMAGEHITFLAG_128 = 0x00000080,//TODO: Name
	DAMAGEHITFLAG_BYPASSUNDEAD = 0x00000100,
	DAMAGEHITFLAG_BYPASSDEMON = 0x00000200,
	DAMAGEHITFLAG_BYPASSBEASTS = 0x00000400,
	DAMAGEHITFLAG_2048 = 0x00000800,//TODO: Name
	DAMAGEHITFLAG_4096 = 0x00001000,
};

enum D2BlockFlags
{
	BLOCKFLAG_NONE = 0x00000000,
	BLOCKFLAG_BLOCK = 0x00000001,
	BLOCKFLAG_AVOID = 0x00000002,
	BLOCKFLAG_DODGE = 0x00000004,
	BLOCKFLAG_EVADE = 0x00000008,
	BLOCKFLAG_WEAPONBLOCK = 0x00000010,
	BLOCKFLAG_ALL = BLOCKFLAG_BLOCK | BLOCKFLAG_AVOID | BLOCKFLAG_DODGE | BLOCKFLAG_EVADE | BLOCKFLAG_WEAPONBLOCK,
};

enum D2DamageReductionType : uint32_t
{
	DAMAGE_REDUCTION_NONE = 0,
	DAMAGE_REDUCTION_PHYSICAL = 1,
	DAMAGE_REDUCTION_MAGICAL = 2,
	DAMAGE_REDUCTION_TYPES_COUNT
};

#pragma pack(push, 1)

struct D2DamageStrc
{
	uint32_t dwHitFlags;					//0x00
	uint16_t wResultFlags;					//0x04
	uint16_t wExtra;						//0x06
	int32_t dwPhysDamage;					//0x08
	int32_t dwEnDmgPct;						//0x0C
	int32_t dwFireDamage;					//0x10
	int32_t dwBurnDamage;					//0x14
	int32_t dwBurnLen;						//0x18
	int32_t dwLtngDamage;					//0x1C
	int32_t dwMagDamage;					//0x20
	int32_t dwColdDamage;					//0x24
	int32_t dwPoisDamage;					//0x28
	int32_t dwPoisLen;						//0x2C
	int32_t dwColdLen;						//0x30
	int32_t dwFrzLen;						//0x34
	int32_t dwLifeLeech;					//0x38
	int32_t dwManaLeech;					//0x3C
	int32_t dwStamLeech;					//0x40
	int32_t dwStunLen;						//0x44
	int32_t dwAbsLife;						//0x48
	int32_t dwDmgTotal;						//0x4C
	uint32_t unk0x50;						//0x50
	int32_t dwPiercePct;					//0x54
	uint32_t dwDamageRate;					//0x58
	uint32_t unk0x5C;						//0x5C
	uint32_t dwHitClass;					//0x60
	uint8_t nHitClassActiveSet;				//0x64
	int8_t nConvType;						//0x65
	uint8_t unk0x66[2];						//0x66
	int32_t dwConvPct;						//0x68
	int32_t nOverlay;						//0x6C
};

struct D2CombatStrc
{
	D2GameStrc* pGame;						//0x00
	uint32_t dwAttackerType;				//0x04
	uint32_t dwAttackerId;					//0x08
	uint32_t dwDefenderType;				//0x0C
	uint32_t dwDefenderId;					//0x10
	D2DamageStrc tDamage;					//0x14
	D2CombatStrc* pNext;					//0x84
};

struct D2DamageInfoStrc
{
	D2GameStrc* pGame;
	D2DifficultyLevelsTxt* pDifficultyLevelsTxt;
	D2UnitStrc* pAttacker;
	D2UnitStrc* pDefender;
	int32_t bAttackerIsMonster;
	int32_t bDefenderIsMonster;
	D2DamageStrc* pDamage;
	int32_t nDamageReduction[DAMAGE_REDUCTION_TYPES_COUNT];
};

struct D2DamageStatTableStrc
{
	int32_t nOffsetInDamageStrc;
	int32_t nResStatId;
	int32_t nMaxResStatId;
	int32_t nPierceStatId;
	int32_t nAbsorbPctStatId;
	int32_t nAbsorbStatId;
	D2DamageReductionType nDamageReductionType;
	int32_t unk0x1C;
	int32_t unk0x20;
	const char* szName;
	uint8_t unk0x28;
	uint8_t pad0x29;
	uint8_t pad0x2A;
	uint8_t pad0x2B;
};
#pragma pack(pop)
