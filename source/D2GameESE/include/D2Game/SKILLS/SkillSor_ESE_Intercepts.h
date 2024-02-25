#pragma once

#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Game/SKILLS/SkillSor_ESE.h"

#include <Units/Units.h>

#include <type_traits>
#include <cstdlib>

//D2Game.0x6FD156F0
int32_t __fastcall ESE_INTERCEPT_SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId);
//D2Game.0x6FD15940
int32_t __fastcall ESE_INTERCEPT_SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);
//D2Game.0x6FD15AB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15B40
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15CF0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15D50
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15E50
void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int32_t a2);
//D2Game.0x6FD15EB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16040
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD160A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16270
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD162D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD163E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);
//D2Game.0x6FD166A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD169A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16A60
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD16C00
void __fastcall ESE_INTERCEPT_SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD16D70
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17040
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17200
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD172B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo151_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17450
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD174E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17570
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17820
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17C30
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD17F40
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD180E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD18200
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_DoInferno_t SKILLS_DoInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId);

extern SKILLS_StartInferno_t SKILLS_StartInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);

extern SKILLS_SrvSt11_Inferno_ArcticBlast_t SKILLS_SrvSt11_Inferno_ArcticBlast_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt12_Telekinesis_DragonFlight_t SKILLS_SrvSt12_Telekinesis_DragonFlight_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt13_ThunderStorm_t SKILLS_SrvSt13_ThunderStorm_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt14_Hydra_t SKILLS_SrvSt14_Hydra_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_MissileInit_ChargedBolt_t SKILLS_MissileInit_ChargedBolt_Original;
void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int32_t a2);

extern SKILLS_SrvDo017_ChargedBolt_BoltSentry_t SKILLS_SrvDo017_ChargedBolt_BoltSentry_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_CurseStateCallback_DefensiveBuff_t SKILLS_CurseStateCallback_DefensiveBuff_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern SKILLS_SrvDo018_DefensiveBuff_t SKILLS_SrvDo018_DefensiveBuff_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo019_Inferno_ArcticBlast_t SKILLS_SrvDo019_Inferno_ArcticBlast_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo020_StaticField_t SKILLS_SrvDo020_StaticField_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AuraCallback_StaticField_t SKILLS_AuraCallback_StaticField_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);

extern SKILLS_SrvDo021_Telekinesis_t SKILLS_SrvDo021_Telekinesis_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo022_NovaAttack_t SKILLS_SrvDo022_NovaAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay_t SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_CreateBlazeMissile_t SKILLS_CreateBlazeMissile_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern SKILLS_SrvDo024_FireWall_t SKILLS_SrvDo024_FireWall_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo025_Enchant_t SKILLS_SrvDo025_Enchant_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo026_ChainLightning_t SKILLS_SrvDo026_ChainLightning_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo151_Unused_t SKILLS_SrvDo151_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo151_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo027_Teleport_t SKILLS_SrvDo027_Teleport_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult_t SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo029_ThunderStorm_t SKILLS_SrvDo029_ThunderStorm_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_EventFunc24_EnergyShield_t SKILLS_EventFunc24_EnergyShield_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo144_Hydra_t SKILLS_SrvDo144_Hydra_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_EventFunc01_ChillingArmor_t SKILLS_EventFunc01_ChillingArmor_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_EventFunc02_FrozenArmor_t SKILLS_EventFunc02_FrozenArmor_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_EventFunc03_ShiverArmor_t SKILLS_EventFunc03_ShiverArmor_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

