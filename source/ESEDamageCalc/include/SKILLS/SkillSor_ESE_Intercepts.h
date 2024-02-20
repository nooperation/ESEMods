#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <SKILLS/SkillSor_ESE.h>

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

extern decltype(&SKILLS_DoInferno) SKILLS_DoInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId);

extern decltype(&SKILLS_StartInferno) SKILLS_StartInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);

extern decltype(&SKILLS_SrvSt11_Inferno_ArcticBlast) SKILLS_SrvSt11_Inferno_ArcticBlast_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt12_Telekinesis_DragonFlight) SKILLS_SrvSt12_Telekinesis_DragonFlight_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt13_ThunderStorm) SKILLS_SrvSt13_ThunderStorm_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt14_Hydra) SKILLS_SrvSt14_Hydra_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_MissileInit_ChargedBolt) SKILLS_MissileInit_ChargedBolt_Original;
void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int32_t a2);

extern decltype(&SKILLS_SrvDo017_ChargedBolt_BoltSentry) SKILLS_SrvDo017_ChargedBolt_BoltSentry_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_CurseStateCallback_DefensiveBuff) SKILLS_CurseStateCallback_DefensiveBuff_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern decltype(&SKILLS_SrvDo018_DefensiveBuff) SKILLS_SrvDo018_DefensiveBuff_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo019_Inferno_ArcticBlast) SKILLS_SrvDo019_Inferno_ArcticBlast_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo020_StaticField) SKILLS_SrvDo020_StaticField_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_AuraCallback_StaticField) SKILLS_AuraCallback_StaticField_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);

extern decltype(&SKILLS_SrvDo021_Telekinesis) SKILLS_SrvDo021_Telekinesis_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo022_NovaAttack) SKILLS_SrvDo022_NovaAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay) SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_CreateBlazeMissile) SKILLS_CreateBlazeMissile_Original;
void __fastcall ESE_INTERCEPT_SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern decltype(&SKILLS_SrvDo024_FireWall) SKILLS_SrvDo024_FireWall_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo025_Enchant) SKILLS_SrvDo025_Enchant_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo026_ChainLightning) SKILLS_SrvDo026_ChainLightning_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo151_Unused) SKILLS_SrvDo151_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo151_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo027_Teleport) SKILLS_SrvDo027_Teleport_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult) SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo029_ThunderStorm) SKILLS_SrvDo029_ThunderStorm_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_EventFunc24_EnergyShield) SKILLS_EventFunc24_EnergyShield_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo144_Hydra) SKILLS_SrvDo144_Hydra_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_EventFunc01_ChillingArmor) SKILLS_EventFunc01_ChillingArmor_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_EventFunc02_FrozenArmor) SKILLS_EventFunc02_FrozenArmor_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_EventFunc03_ShiverArmor) SKILLS_EventFunc03_ShiverArmor_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

