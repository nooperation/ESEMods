#include "D2Game/SKILLS/SkillSor_ESE_Intercepts.h"

SKILLS_DoInferno_t SKILLS_DoInferno_Original = nullptr;
SKILLS_StartInferno_t SKILLS_StartInferno_Original = nullptr;
SKILLS_SrvSt11_Inferno_ArcticBlast_t SKILLS_SrvSt11_Inferno_ArcticBlast_Original = nullptr;
SKILLS_SrvSt12_Telekinesis_DragonFlight_t SKILLS_SrvSt12_Telekinesis_DragonFlight_Original = nullptr;
SKILLS_SrvSt13_ThunderStorm_t SKILLS_SrvSt13_ThunderStorm_Original = nullptr;
SKILLS_SrvSt14_Hydra_t SKILLS_SrvSt14_Hydra_Original = nullptr;
SKILLS_MissileInit_ChargedBolt_t SKILLS_MissileInit_ChargedBolt_Original = nullptr;
SKILLS_SrvDo017_ChargedBolt_BoltSentry_t SKILLS_SrvDo017_ChargedBolt_BoltSentry_Original = nullptr;
SKILLS_CurseStateCallback_DefensiveBuff_t SKILLS_CurseStateCallback_DefensiveBuff_Original = nullptr;
SKILLS_SrvDo018_DefensiveBuff_t SKILLS_SrvDo018_DefensiveBuff_Original = nullptr;
SKILLS_SrvDo019_Inferno_ArcticBlast_t SKILLS_SrvDo019_Inferno_ArcticBlast_Original = nullptr;
SKILLS_SrvDo020_StaticField_t SKILLS_SrvDo020_StaticField_Original = nullptr;
SKILLS_AuraCallback_StaticField_t SKILLS_AuraCallback_StaticField_Original = nullptr;
SKILLS_SrvDo021_Telekinesis_t SKILLS_SrvDo021_Telekinesis_Original = nullptr;
SKILLS_SrvDo022_NovaAttack_t SKILLS_SrvDo022_NovaAttack_Original = nullptr;
SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay_t SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay_Original = nullptr;
SKILLS_CreateBlazeMissile_t SKILLS_CreateBlazeMissile_Original = nullptr;
SKILLS_SrvDo024_FireWall_t SKILLS_SrvDo024_FireWall_Original = nullptr;
SKILLS_SrvDo025_Enchant_t SKILLS_SrvDo025_Enchant_Original = nullptr;
SKILLS_SrvDo026_ChainLightning_t SKILLS_SrvDo026_ChainLightning_Original = nullptr;
SKILLS_SrvDo151_Unused_t SKILLS_SrvDo151_Unused_Original = nullptr;
SKILLS_SrvDo027_Teleport_t SKILLS_SrvDo027_Teleport_Original = nullptr;
SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult_t SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult_Original = nullptr;
SKILLS_SrvDo029_ThunderStorm_t SKILLS_SrvDo029_ThunderStorm_Original = nullptr;
SKILLS_EventFunc24_EnergyShield_t SKILLS_EventFunc24_EnergyShield_Original = nullptr;
SKILLS_SrvDo144_Hydra_t SKILLS_SrvDo144_Hydra_Original = nullptr;
SKILLS_EventFunc01_ChillingArmor_t SKILLS_EventFunc01_ChillingArmor_Original = nullptr;
SKILLS_EventFunc02_FrozenArmor_t SKILLS_EventFunc02_FrozenArmor_Original = nullptr;
SKILLS_EventFunc03_ShiverArmor_t SKILLS_EventFunc03_ShiverArmor_Original = nullptr;

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


