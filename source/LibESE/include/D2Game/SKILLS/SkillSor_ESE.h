#pragma once

#include "../UNIT/SUnitDmg_ESE.h"

#include <../D2MooHeaders.h>
#include <SKILLS/SkillSor.h>
#include <Units/Units.h>

struct D2AuraCallbackStrc;

#pragma pack(push, 1)
struct ESE_D2StaticFieldCallbackArgStrc
{
    int64_t nMinDamage;       //+00
    int64_t nDamagePct;       //+04
    int64_t nStaticFieldMin;  //+08
    int64_t nElementalLength; //+0C
    int32_t nElementalType;   //+10
};
#pragma pack(pop)


//D2Game.0x6FD156F0
int32_t __fastcall ESE_SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId);
//D2Game.0x6FD15940
int32_t __fastcall ESE_SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);
//D2Game.0x6FD15AB0
int32_t __fastcall ESE_SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15B40
int32_t __fastcall ESE_SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15CF0
int32_t __fastcall ESE_SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15D50
int32_t __fastcall ESE_SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15E50
void __fastcall ESE_SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int32_t a2);
//D2Game.0x6FD15EB0
int32_t __fastcall ESE_SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16040
void __fastcall ESE_SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD160A0
int32_t __fastcall ESE_SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16270
int32_t __fastcall ESE_SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD162D0
int32_t __fastcall ESE_SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD163E0
int32_t __fastcall ESE_SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);
//D2Game.0x6FD166A0
int32_t __fastcall ESE_SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD169A0
int32_t __fastcall ESE_SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16A60
int32_t __fastcall ESE_SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16C00
void __fastcall ESE_SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD16D70
int32_t __fastcall ESE_SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17040
int32_t __fastcall ESE_SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17200
int32_t __fastcall ESE_SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD172B0
int32_t __fastcall ESE_SKILLS_SrvDo151_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17450
int32_t __fastcall ESE_SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD174E0
int32_t __fastcall ESE_SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17570
int32_t __fastcall ESE_SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17820
int32_t __fastcall ESE_SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, ESE_D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17C30
int32_t __fastcall ESE_SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17F40
int32_t __fastcall ESE_SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, ESE_D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD180E0
int32_t __fastcall ESE_SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, ESE_D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD18200
int32_t __fastcall ESE_SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, ESE_D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
