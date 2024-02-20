#include "D2Game/SKILLS/SkillSor_ESE_Intercepts.h"

decltype(&SKILLS_DoInferno) SKILLS_DoInferno_Original = nullptr;
decltype(&SKILLS_StartInferno) SKILLS_StartInferno_Original = nullptr;
decltype(&SKILLS_SrvSt11_Inferno_ArcticBlast) SKILLS_SrvSt11_Inferno_ArcticBlast_Original = nullptr;
decltype(&SKILLS_SrvSt12_Telekinesis_DragonFlight) SKILLS_SrvSt12_Telekinesis_DragonFlight_Original = nullptr;
decltype(&SKILLS_SrvSt13_ThunderStorm) SKILLS_SrvSt13_ThunderStorm_Original = nullptr;
decltype(&SKILLS_SrvSt14_Hydra) SKILLS_SrvSt14_Hydra_Original = nullptr;
decltype(&SKILLS_MissileInit_ChargedBolt) SKILLS_MissileInit_ChargedBolt_Original = nullptr;
decltype(&SKILLS_SrvDo017_ChargedBolt_BoltSentry) SKILLS_SrvDo017_ChargedBolt_BoltSentry_Original = nullptr;
decltype(&SKILLS_CurseStateCallback_DefensiveBuff) SKILLS_CurseStateCallback_DefensiveBuff_Original = nullptr;
decltype(&SKILLS_SrvDo018_DefensiveBuff) SKILLS_SrvDo018_DefensiveBuff_Original = nullptr;
decltype(&SKILLS_SrvDo019_Inferno_ArcticBlast) SKILLS_SrvDo019_Inferno_ArcticBlast_Original = nullptr;
decltype(&SKILLS_SrvDo020_StaticField) SKILLS_SrvDo020_StaticField_Original = nullptr;
decltype(&SKILLS_AuraCallback_StaticField) SKILLS_AuraCallback_StaticField_Original = nullptr;
decltype(&SKILLS_SrvDo021_Telekinesis) SKILLS_SrvDo021_Telekinesis_Original = nullptr;
decltype(&SKILLS_SrvDo022_NovaAttack) SKILLS_SrvDo022_NovaAttack_Original = nullptr;
decltype(&SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay) SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay_Original = nullptr;
decltype(&SKILLS_CreateBlazeMissile) SKILLS_CreateBlazeMissile_Original = nullptr;
decltype(&SKILLS_SrvDo024_FireWall) SKILLS_SrvDo024_FireWall_Original = nullptr;
decltype(&SKILLS_SrvDo025_Enchant) SKILLS_SrvDo025_Enchant_Original = nullptr;
decltype(&SKILLS_SrvDo026_ChainLightning) SKILLS_SrvDo026_ChainLightning_Original = nullptr;
decltype(&SKILLS_SrvDo151_Unused) SKILLS_SrvDo151_Unused_Original = nullptr;
decltype(&SKILLS_SrvDo027_Teleport) SKILLS_SrvDo027_Teleport_Original = nullptr;
decltype(&SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult) SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult_Original = nullptr;
decltype(&SKILLS_SrvDo029_ThunderStorm) SKILLS_SrvDo029_ThunderStorm_Original = nullptr;
decltype(&SKILLS_EventFunc24_EnergyShield) SKILLS_EventFunc24_EnergyShield_Original = nullptr;
decltype(&SKILLS_SrvDo144_Hydra) SKILLS_SrvDo144_Hydra_Original = nullptr;
decltype(&SKILLS_EventFunc01_ChillingArmor) SKILLS_EventFunc01_ChillingArmor_Original = nullptr;
decltype(&SKILLS_EventFunc02_FrozenArmor) SKILLS_EventFunc02_FrozenArmor_Original = nullptr;
decltype(&SKILLS_EventFunc03_ShiverArmor) SKILLS_EventFunc03_ShiverArmor_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId)
{
    return ESE_SKILLS_DoInferno(pGame, pUnit, nSkillId, nSkillLevel, nMissileId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5)
{
    return ESE_SKILLS_StartInferno(pGame, pUnit, nSkillId, nSkillLevel, a5);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt11_Inferno_ArcticBlast(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt12_Telekinesis_DragonFlight(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt13_ThunderStorm(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt14_Hydra(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_MissileInit_ChargedBolt(D2UnitStrc* pMissile, int32_t a2)
{
    ESE_SKILLS_MissileInit_ChargedBolt(pMissile, a2);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo017_ChargedBolt_BoltSentry(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_CurseStateCallback_DefensiveBuff(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo018_DefensiveBuff(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo019_Inferno_ArcticBlast(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo020_StaticField(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender)
{
    return ESE_SKILLS_AuraCallback_StaticField(pAuraCallback, pDefender);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo021_Telekinesis(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo022_NovaAttack(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_SKILLS_CreateBlazeMissile(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo024_FireWall(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo025_Enchant(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo026_ChainLightning(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo151_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo151_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo027_Teleport(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo029_ThunderStorm(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_EventFunc24_EnergyShield(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo144_Hydra(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_EventFunc01_ChillingArmor(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_EventFunc02_FrozenArmor(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_EventFunc03_ShiverArmor(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}


