#pragma once

#include <D2StatList.h>
#include <Units/Units.h>
#include <Units/UnitFinds.h>
#include <UNIT/SUnitDmg.h>


struct D2ItemStatCostTxt;
struct D2MissilesTxt;
struct D2PetTypeTxt;
struct D2StatesTxt;

using CurseCallbackFunc = void(__fastcall*)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int32_t);


using SkillStartFunc = int32_t(__fastcall*)(D2GameStrc*, D2UnitStrc*, int32_t, int32_t);
using SkillDoFunc = int32_t(__fastcall*)(D2GameStrc*, D2UnitStrc*, int32_t, int32_t);
extern const SkillDoFunc gpSkillSrvDoFnTable_6FD40A20[];
extern const int32_t gnSkillSrvDoFns;

#pragma pack(push, 1)
struct D2AuraCallbackStrc
{
	D2GameStrc* pGame;  //+00
	D2UnitStrc* pOwner; //+04
	int32_t nCounter;       //+08
	void* pArgs;       //+0C
};

struct D2StaticFieldCallbackArgStrc
{
	int32_t nMinDamage;       //+00
	int32_t nDamagePct;       //+04
	int32_t nStaticFieldMin;  //+08
	int32_t nElementalLength; //+0C
	int32_t nElementalType;   //+10
};

struct D2UnkNecSkillStrc
{
	D2GameStrc* pGame;
	D2UnitStrc* pUnit;
	int32_t unk0x08;
	int32_t bUpdateAnimRate;
	int32_t nSkillId;
	int32_t nSkillLevel;
	int32_t nDuration;
	int32_t nAuraStat[6];
	int32_t nAuraStatCalc[6];
	int32_t nAuraTargetState;
	int32_t nAuraEvent[3];
	int32_t nAuraEventFunc[3];
};

struct D2_6FD106F0_Strc
{
	D2UnitStrc* pUnit;
	int32_t nDistance;
	int32_t nX;
	int32_t nY;
	int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*);
};

struct D2_6FD10880_Strc
{
	D2UnitStrc* unk0x00;
	int32_t unk0x04;
	D2UnitStrc* unk0x08;
	int32_t unk0x0C;
	int32_t unk0x10;
	int32_t unk0x14;
};

struct D2EffectStrc
{
	uint32_t nFlags;
	D2UnitStrc* pUnit;
	int32_t nSkillId;
	int32_t nX;
	int32_t nY;
	int32_t nParam;
	int32_t nSkillLevel;
	int32_t unk0x1C;
	void* pfAreaEffect;
};

struct D2MonSkillInfoStrc
{
	int32_t nMinDamage;
	int32_t nMaxDamage;
	int32_t nToHit;
};

struct D2CurseStrc
{
	D2UnitStrc* pUnit;								//0x00
	D2UnitStrc* pTarget;							//0x04
	int32_t nSkill;									//0x08
	int32_t nSkillLevel;							//0x0C
	int32_t nDuration;								//0x10
	int32_t nStat;									//0x14
	int32_t nStatValue;								//0x18
	int32_t nState;									//0x1C
	StatListRemoveCallback pStateRemoveCallback;	//0x20
};

struct D2SummonArgStrc
{
	uint32_t dwFlags;						//0x00
	D2UnitStrc* pOwner;						//0x04
	int32_t nHcIdx;							//0x08
	int32_t nSpecialAiState;				//0x0C
	int32_t nMonMode;						//0x10
	D2CoordStrc pPosition;					//0x14		
	int32_t nPetType;						//0x1C
	int32_t nPetMax;						//0x20
};

#pragma pack(pop)
