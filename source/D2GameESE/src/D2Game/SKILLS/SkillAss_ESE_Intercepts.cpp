#include "D2Game/SKILLS/SkillAss_ESE_Intercepts.h"

SKILLS_SrvSt22_PsychicHammer_t SKILLS_SrvSt22_PsychicHammer_Original = nullptr;
SKILLS_SrvDo033_PsychicHammer_t SKILLS_SrvDo033_PsychicHammer_Original = nullptr;
SKILLS_SrvSt23_AssasinChargeStrikes_t SKILLS_SrvSt23_AssasinChargeStrikes_Original = nullptr;
SKILLS_StatRemoveCallback_ProgressiveStrike_t SKILLS_StatRemoveCallback_ProgressiveStrike_Original = nullptr;
SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike_t SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike_Original = nullptr;
SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce_t SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce_Original = nullptr;
sub_6FCF5680_t sub_6FCF5680_Original = nullptr;
sub_6FCF5870_t sub_6FCF5870_Original = nullptr;
SKILLS_GetSkillsTxtRecord_t SKILLS_GetSkillsTxtRecord_Original = nullptr;
sub_6FCF5BC0_t sub_6FCF5BC0_Original = nullptr;
sub_6FCF5DE0_t sub_6FCF5DE0_Original = nullptr;
SKILLS_GetProgressiveSkillMissileId_t SKILLS_GetProgressiveSkillMissileId_Original = nullptr;
SKILLS_EvaluateProgressiveSkillCalc_t SKILLS_EvaluateProgressiveSkillCalc_Original = nullptr;
SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2_t SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2_Original = nullptr;
SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3_t SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3_Original = nullptr;
SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2_t SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2_Original = nullptr;
SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3_t SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3_Original = nullptr;
sub_6FCF6600_t sub_6FCF6600_Original = nullptr;
sub_6FCF6C10_t sub_6FCF6C10_Original = nullptr;
SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn_t SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn_Original = nullptr;
sub_6FCF6D70_t sub_6FCF6D70_Original = nullptr;
sub_6FCF7390_t sub_6FCF7390_Original = nullptr;
SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1_t SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1_Original = nullptr;
SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3_t SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3_Original = nullptr;
sub_6FCF77E0_t sub_6FCF77E0_Original = nullptr;
SKILLS_SrvSt24_DragonTalon_t SKILLS_SrvSt24_DragonTalon_Original = nullptr;
sub_6FCF7BC0_t sub_6FCF7BC0_Original = nullptr;
sub_6FCF7CE0_t sub_6FCF7CE0_Original = nullptr;
SKILLS_SrvDo042_DragonTalon_t SKILLS_SrvDo042_DragonTalon_Original = nullptr;
sub_6FCF8330_t sub_6FCF8330_Original = nullptr;
SKILLS_SrvDo043_ShockField_t SKILLS_SrvDo043_ShockField_Original = nullptr;
sub_6FCF8610_t sub_6FCF8610_Original = nullptr;
SKILLS_SrvDo044_BladeSentinel_t SKILLS_SrvDo044_BladeSentinel_Original = nullptr;
SKILLS_SrvDo045_Sentry_t SKILLS_SrvDo045_Sentry_Original = nullptr;
SKILLS_SrvDo046_DragonClaw_t SKILLS_SrvDo046_DragonClaw_Original = nullptr;
sub_6FCF8C70_t sub_6FCF8C70_Original = nullptr;
sub_6FCF8DD0_t sub_6FCF8DD0_Original = nullptr;
SKILLS_SrvDo047_CloakOfShadows_t SKILLS_SrvDo047_CloakOfShadows_Original = nullptr;
SKILLS_AuraCallback_CloakOfShadows_t SKILLS_AuraCallback_CloakOfShadows_Original = nullptr;
SKILLS_SrvDo048_BladeFury_t SKILLS_SrvDo048_BladeFury_Original = nullptr;
SKILLS_SrvSt26_BladeFury_t SKILLS_SrvSt26_BladeFury_Original = nullptr;
SKILLS_StatRemoveCallback_RemoveState_t SKILLS_StatRemoveCallback_RemoveState_Original = nullptr;
sub_6FCF9580_t sub_6FCF9580_Original = nullptr;
SKILLS_SrvDo049_ShadowWarrior_Master_t SKILLS_SrvDo049_ShadowWarrior_Master_Original = nullptr;
SKILLS_SrvSt27_DragonTail_t SKILLS_SrvSt27_DragonTail_Original = nullptr;
SKILLS_SrvDo050_DragonTail_t SKILLS_SrvDo050_DragonTail_Original = nullptr;
SKILLS_StatRemoveCallback_MindBlast_t SKILLS_StatRemoveCallback_MindBlast_Original = nullptr;
SKILLS_AuraCallback_MindBlast_t SKILLS_AuraCallback_MindBlast_Original = nullptr;
SKILLS_SrvDo051_MindBlast_t SKILLS_SrvDo051_MindBlast_Original = nullptr;
SKILLS_SrvDo052_DragonFlight_t SKILLS_SrvDo052_DragonFlight_Original = nullptr;
SKILLS_SrvSt28_BladeShield_t SKILLS_SrvSt28_BladeShield_Original = nullptr;
SKILLS_SrvDo053_Unused_t SKILLS_SrvDo053_Unused_Original = nullptr;
SKILLS_AuraCallback_SrvDo142_t SKILLS_AuraCallback_SrvDo142_Original = nullptr;
SKILLS_SrvDo142_Unused_t SKILLS_SrvDo142_Unused_Original = nullptr;
SKILLS_SrvDo054_BladeShield_t SKILLS_SrvDo054_BladeShield_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt22_PsychicHammer(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo033_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo033_PsychicHammer(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt23_AssasinChargeStrikes(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt23_AssasinChargeStrikes(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_StatRemoveCallback_ProgressiveStrike(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_StatRemoveCallback_ProgressiveStrike(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF5680(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_sub_6FCF5680(pUnit, pDamage);
}

void __fastcall ESE_INTERCEPT_sub_6FCF5870(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_sub_6FCF5870(pUnit, pDamage);
}

D2SkillsTxt* __fastcall ESE_INTERCEPT_SKILLS_GetSkillsTxtRecord(int32_t nSkillId)
{
    return ESE_SKILLS_GetSkillsTxtRecord(nSkillId);
}

void __fastcall ESE_INTERCEPT_sub_6FCF5BC0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    ESE_sub_6FCF5BC0(pUnit, pStatList, pDamage);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCF5DE0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FCF5DE0(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int32_t nSkillId)
{
    return ESE_SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF6600(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nLowSeed, int32_t nMissileId, int32_t nX, int32_t nY, int32_t nSkillId, int32_t nSkillLevel, int32_t nStep)
{
    ESE_sub_6FCF6600(pGame, pUnit, nLowSeed, nMissileId, nX, nY, nSkillId, nSkillLevel, nStep);
}

void __fastcall ESE_INTERCEPT_sub_6FCF6C10(D2UnitStrc* pMissile, int32_t nLowSeed)
{
    ESE_sub_6FCF6C10(pMissile, nLowSeed);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF6D70(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nLowSeed, int32_t nMissileId, int32_t nX, int32_t nY, int32_t nSkillId, int32_t nSkillLevel, int32_t nStep)
{
    ESE_sub_6FCF6D70(pGame, pUnit, nLowSeed, nMissileId, nX, nY, nSkillId, nSkillLevel, nStep);
}

void __fastcall ESE_INTERCEPT_sub_6FCF7390(D2UnitStrc* pMissile, int32_t nInitSeed)
{
    ESE_sub_6FCF7390(pMissile, nInitSeed);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF77E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_sub_6FCF77E0(pGame, pUnit, pDamage);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt24_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt24_DragonTalon(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF7BC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecordArg, int32_t nSkillId, int32_t nSkillLevel, int32_t bKnockback)
{
    ESE_sub_6FCF7BC0(pGame, pUnit, pTarget, pSkillsTxtRecordArg, nSkillId, nSkillLevel, bKnockback);
}

void __fastcall ESE_INTERCEPT_sub_6FCF7CE0(D2GameStrc* pGame, D2DamageStrc* pDamage, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FCF7CE0(pGame, pDamage, pUnit, pTarget, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo042_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo042_DragonTalon(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCF8330(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int32_t nMissileId, int32_t nSubMissiles, int32_t nRange, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_sub_6FCF8330(pGame, pMissile, pUnit, nMissileId, nSubMissiles, nRange, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo043_ShockField(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo043_ShockField(pGame, pUnit, nSkillId, nSkillLevel);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FCF8610(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_sub_6FCF8610(pGame, pUnit, nX, nY, pSkillsTxtRecord, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo044_BladeSentinel(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo044_BladeSentinel(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo045_Sentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo045_Sentry(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo046_DragonClaw(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo046_DragonClaw(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF8C70(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FCF8C70(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCF8DD0(D2UnitStrc* pDefender)
{
    ESE_sub_6FCF8DD0(pDefender);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo047_CloakOfShadows(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo047_CloakOfShadows(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_CloakOfShadows(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_CloakOfShadows(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo048_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo048_BladeFury(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt26_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt26_BladeFury(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_StatRemoveCallback_RemoveState(pUnit, nState, pStatList);
}

void __fastcall ESE_INTERCEPT_sub_6FCF9580(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nSkillId, int32_t nSkillLevel, int32_t nItemLevel, int32_t bCheckOnInit)
{
    ESE_sub_6FCF9580(pGame, pUnit, pPet, nSkillId, nSkillLevel, nItemLevel, bCheckOnInit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo049_ShadowWarrior_Master(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo049_ShadowWarrior_Master(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt27_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt27_DragonTail(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo050_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo050_DragonTail(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_SKILLS_StatRemoveCallback_MindBlast(D2UnitStrc* pItem, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_SKILLS_StatRemoveCallback_MindBlast(pItem, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_MindBlast(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_MindBlast(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo051_MindBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo051_MindBlast(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo052_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo052_DragonFlight(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt28_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt28_BladeShield(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo053_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo053_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AuraCallback_SrvDo142(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_SKILLS_AuraCallback_SrvDo142(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo142_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo142_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo054_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo054_BladeShield(pGame, pUnit, nSkillId, nSkillLevel);
}


