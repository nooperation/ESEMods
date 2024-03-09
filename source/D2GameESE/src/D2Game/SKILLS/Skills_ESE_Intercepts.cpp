#include "D2Game/SKILLS/Skills_ESE_Intercepts.h"

sub_6FD0F8B0_t sub_6FD0F8B0_Original = nullptr;
sub_6FD0FA00_t sub_6FD0FA00_Original = nullptr;
sub_6FD0FDD0_t sub_6FD0FDD0_Original = nullptr;
sub_6FD0FE50_t sub_6FD0FE50_Original = nullptr;
sub_6FD0FE80_t sub_6FD0FE80_Original = nullptr;
sub_6FD10140_t sub_6FD10140_Original = nullptr;
sub_6FD10200_t sub_6FD10200_Original = nullptr;
sub_6FD10250_t sub_6FD10250_Original = nullptr;
sub_6FD10360_t sub_6FD10360_Original = nullptr;
SKILLS_FindAuraTarget_t SKILLS_FindAuraTarget_Original = nullptr;
sub_6FD106F0_t sub_6FD106F0_Original = nullptr;
sub_6FD10790_t sub_6FD10790_Original = nullptr;
sub_6FD107E0_t sub_6FD107E0_Original = nullptr;
sub_6FD107F0_t sub_6FD107F0_Original = nullptr;
sub_6FD10880_t sub_6FD10880_Original = nullptr;
sub_6FD108D0_t sub_6FD108D0_Original = nullptr;
D2GAME_SKILLMANA_Consume_6FD10A50_t D2GAME_SKILLMANA_Consume_6FD10A50_Original = nullptr;
D2GAME_SKILLMANA_AuraConsume_6FD10C90_t D2GAME_SKILLMANA_AuraConsume_6FD10C90_Original = nullptr;
sub_6FD10CE0_t sub_6FD10CE0_Original = nullptr;
sub_6FD10D90_t sub_6FD10D90_Original = nullptr;
sub_6FD10E20_t sub_6FD10E20_Original = nullptr;
sub_6FD10E50_t sub_6FD10E50_Original = nullptr;
sub_6FD10EC0_t sub_6FD10EC0_Original = nullptr;
sub_6FD11260_t sub_6FD11260_Original = nullptr;
sub_6FD11340_t sub_6FD11340_Original = nullptr;
sub_6FD11420_t sub_6FD11420_Original = nullptr;
D2GAME_CreateMissile_6FD115E0_t D2GAME_CreateMissile_6FD115E0_Original = nullptr;
sub_6FD11710_t sub_6FD11710_Original = nullptr;
sub_6FD118C0_t sub_6FD118C0_Original = nullptr;
sub_6FD119C0_t sub_6FD119C0_Original = nullptr;
sub_6FD11AE0_t sub_6FD11AE0_Original = nullptr;
D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50_t D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50_Original = nullptr;
sub_6FD11BA0_t sub_6FD11BA0_Original = nullptr;
D2GAME_SKILLS_SetDelay_6FD11C00_t D2GAME_SKILLS_SetDelay_6FD11C00_Original = nullptr;
sub_6FD11C90_t sub_6FD11C90_Original = nullptr;
sub_6FD11D90_t sub_6FD11D90_Original = nullptr;
sub_6FD11E40_t sub_6FD11E40_Original = nullptr;
SKILLS_SrvSt01_Attack_LeftHandSwing_t SKILLS_SrvSt01_Attack_LeftHandSwing_Original = nullptr;
SKILLS_SrvSt65_Throw_LeftHandThrow_t SKILLS_SrvSt65_Throw_LeftHandThrow_Original = nullptr;
SKILLS_SrvSt02_Kick_t SKILLS_SrvSt02_Kick_Original = nullptr;
SKILLS_SrvSt03_Unsummon_t SKILLS_SrvSt03_Unsummon_Original = nullptr;
SKILLS_SrvDo001_Attack_LeftHandSwing_t SKILLS_SrvDo001_Attack_LeftHandSwing_Original = nullptr;
SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws_t SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws_Original = nullptr;
SKILLS_SrvDo004_Unsummon_t SKILLS_SrvDo004_Unsummon_Original = nullptr;
SKILLS_SrvDo003_Throw_t SKILLS_SrvDo003_Throw_Original = nullptr;
SKILLS_SrvDo005_LeftHandThrow_t SKILLS_SrvDo005_LeftHandThrow_Original = nullptr;
sub_6FD12950_t sub_6FD12950_Original = nullptr;
D2GAME_SKILLS_Handler_6FD12BA0_t D2GAME_SKILLS_Handler_6FD12BA0_Original = nullptr;
sub_6FD12FD0_t sub_6FD12FD0_Original = nullptr;
sub_6FD13220_t sub_6FD13220_Original = nullptr;
sub_6FD13260_t sub_6FD13260_Original = nullptr;
sub_6FD13330_t sub_6FD13330_Original = nullptr;
sub_6FD13410_t sub_6FD13410_Original = nullptr;
D2GAME_MONSTERS_AiFunction09_6FD13470_t D2GAME_MONSTERS_AiFunction09_6FD13470_Original = nullptr;
D2GAME_MONSTERS_AiFunction10_6FD13610_t D2GAME_MONSTERS_AiFunction10_6FD13610_Original = nullptr;
sub_6FD136E0_t sub_6FD136E0_Original = nullptr;
D2GAME_AssignSkill_6FD13800_t D2GAME_AssignSkill_6FD13800_Original = nullptr;
D2GAME_CreateLinkPortal_6FD13B20_t D2GAME_CreateLinkPortal_6FD13B20_Original = nullptr;
D2GAME_CreatePortalObject_6FD13DF0_t D2GAME_CreatePortalObject_6FD13DF0_Original = nullptr;
D2GAME_GetXAndYFromTargetUnit_6FD14020_t D2GAME_GetXAndYFromTargetUnit_6FD14020_Original = nullptr;
sub_6FD140D0_t sub_6FD140D0_Original = nullptr;
sub_6FD14120_t sub_6FD14120_Original = nullptr;
sub_6FD14170_t sub_6FD14170_Original = nullptr;
sub_6FD14260_t sub_6FD14260_Original = nullptr;
D2GAME_MONSTERS_AiFunction06_6FD14370_t D2GAME_MONSTERS_AiFunction06_6FD14370_Original = nullptr;
sub_6FD14400_t sub_6FD14400_Original = nullptr;
D2GAME_SummonPet_6FD14430_t D2GAME_SummonPet_6FD14430_Original = nullptr;
sub_6FD146D0_t sub_6FD146D0_Original = nullptr;
sub_6FD14770_t sub_6FD14770_Original = nullptr;
sub_6FD149B0_t sub_6FD149B0_Original = nullptr;
sub_6FD14BD0_t sub_6FD14BD0_Original = nullptr;
sub_6FD14C30_t sub_6FD14C30_Original = nullptr;
D2GAME_SetSkills_6FD14C60_t D2GAME_SetSkills_6FD14C60_Original = nullptr;
D2GAME_RefreshPassiveSkills_6FD14CC0_t D2GAME_RefreshPassiveSkills_6FD14CC0_Original = nullptr;
sub_6FD14D20_t sub_6FD14D20_Original = nullptr;
D2GAME_RollElementalDamage_6FD14DD0_t D2GAME_RollElementalDamage_6FD14DD0_Original = nullptr;
D2GAME_RollPhysicalDamage_6FD14EC0_t D2GAME_RollPhysicalDamage_6FD14EC0_Original = nullptr;
sub_6FD14F70_t sub_6FD14F70_Original = nullptr;
sub_6FD15080_t sub_6FD15080_Original = nullptr;
sub_6FD150A0_t sub_6FD150A0_Original = nullptr;
sub_6FD15190_t sub_6FD15190_Original = nullptr;
sub_6FD15210_t sub_6FD15210_Original = nullptr;
sub_6FD15320_t sub_6FD15320_Original = nullptr;
sub_6FD15340_t sub_6FD15340_Original = nullptr;
sub_6FD15460_t sub_6FD15460_Original = nullptr;
sub_6FD15470_t sub_6FD15470_Original = nullptr;
sub_6FD154D0_t sub_6FD154D0_Original = nullptr;
sub_6FD15500_t sub_6FD15500_Original = nullptr;
D2GAME_GetSummonIdFromSkill_6FD15580_t D2GAME_GetSummonIdFromSkill_6FD15580_Original = nullptr;
sub_6FD155E0_t sub_6FD155E0_Original = nullptr;
sub_6FD15650_t sub_6FD15650_Original = nullptr;
sub_6FD156A0_t sub_6FD156A0_Original = nullptr;
SKILLS_SrvSt18_Attract_t SKILLS_SrvSt18_Attract_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_sub_6FD0F8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nValue)
{
    return ESE_sub_6FD0F8B0(pGame, pUnit, nValue);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, uint32_t nAuraFilter)
{
    return ESE_sub_6FD0FA00(pUnit, pTarget, nAuraFilter);
}

void __fastcall ESE_INTERCEPT_sub_6FD0FDD0(D2UnitStrc* pUnit)
{
    ESE_sub_6FD0FDD0(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD0FE50(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs)
{
    ESE_sub_6FD0FE50(pGame, pUnit, pCallback, pArgs);
}

void __fastcall ESE_INTERCEPT_sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int32_t bCheckMonAuraFlag, const char* szFile, int32_t nLine)
{
    ESE_sub_6FD0FE80(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, pCallback, pCallbackArgs, bCheckMonAuraFlag, szFile, nLine);
}

void __fastcall ESE_INTERCEPT_sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nUnused)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_sub_6FD10140(pGame, pAttackerArg, pUnit, &tempDamageStrc, nUnused);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, D2DamageStrc* pDamage, uint32_t nAuraFilter)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    int32_t result = ESE_sub_6FD10200(pGame, pUnit, nX, nY, nAuraRange, &tempDamageStrc, nAuraFilter);
    tempDamageStrc.WriteToOriginalStruct(pDamage);

    return result;
}

void __fastcall ESE_INTERCEPT_sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nState, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD10250(pGame, pUnit, pTarget, nState, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10360(D2GameStrc* pGame, uint32_t nFlags, D2UnitStrc* pUnit, int32_t nDistance, int32_t(__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs)
{
    return ESE_sub_6FD10360(pGame, nFlags, pUnit, nDistance, pCallback, pArgs);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nAuraRange, int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*))
{
    return ESE_SKILLS_FindAuraTarget(pGame, pUnit, nAuraRange, pCallback);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD106F0(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter)
{
    return ESE_sub_6FD10790(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD107E0(pAuraCallback, pUnit);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t a7, int32_t* a8)
{
    return ESE_sub_6FD107F0(pGame, pUnit, nX, nY, nAuraRange, nAuraFilter, a7, a8);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD10880(pAuraCallback, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD108D0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId)
{
    ESE_sub_6FD108D0(pGame, pUnit, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLMANA_Consume_6FD10A50(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_SKILLMANA_Consume_6FD10A50(pGame, pPlayer, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int32_t nManaCost)
{
    return ESE_D2GAME_SKILLMANA_AuraConsume_6FD10C90(pUnit, nManaCost);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD10CE0(D2UnitStrc* pUnit)
{
    return ESE_sub_6FD10CE0(pUnit);
}

D2UnitFindDataStrc* __fastcall ESE_INTERCEPT_sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSize, int32_t nX, int32_t nY)
{
    return ESE_sub_6FD10D90(pGame, pUnit, nSize, nX, nY);
}

void __fastcall ESE_INTERCEPT_sub_6FD10E20(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData)
{
    ESE_sub_6FD10E20(pGame, pUnitFindData);
}

void __fastcall ESE_INTERCEPT_sub_6FD10E50(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_sub_6FD10E50(pUnit, nState, pStatList);
}

D2StatListStrc* __fastcall ESE_INTERCEPT_sub_6FD10EC0(D2CurseStrc* pCurse)
{
    return ESE_sub_6FD10EC0(pCurse);
}

D2StatListStrc* __fastcall ESE_INTERCEPT_sub_6FD11260(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel, int32_t nStatId, int32_t nState, StatListRemoveCallback pfRemoveStatCallback)
{
    return ESE_sub_6FD11260(pUnit, pTarget, nSkillId, nSkillLevel, nStatId, nState, pfRemoveStatCallback);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD11340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    return ESE_sub_6FD11340(pGame, pUnit, pItem);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD11420(D2GameStrc* pGame, int32_t nMissileId, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t nTargetX, int32_t nTargetY, int32_t bCheckItemQuantity)
{
    return ESE_sub_6FD11420(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, bCheckItemQuantity);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId, int32_t nX, int32_t nY)
{
    return ESE_D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD11710(D2GameStrc* pGame, int32_t nMissileId, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t nTargetX, int32_t nTargetY, int32_t bSkipCheck)
{
    return ESE_sub_6FD11710(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, nX, nY, nTargetX, nTargetY, bSkipCheck);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD118C0(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD119C0(D2UnitStrc* pUnit)
{
    return ESE_sub_6FD119C0(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    ESE_sub_6FD11AE0(pGame, pUnit, pItem);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int32_t nSkillId)
{
    return ESE_D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(pUnit, nSkillId);
}

void __fastcall ESE_INTERCEPT_sub_6FD11BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD11BA0(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nDelay)
{
    ESE_D2GAME_SKILLS_SetDelay_6FD11C00(pGame, pUnit, nDelay);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD11C90(D2UnitStrc* pUnit, int32_t nStateId, int32_t a3)
{
    return ESE_sub_6FD11C90(pUnit, nStateId, a3);
}

void __fastcall ESE_INTERCEPT_sub_6FD11D90(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nLength, int32_t nSkillId)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_sub_6FD11D90(pUnit, &tempDamageStrc, nLength, nSkillId);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

void __fastcall ESE_INTERCEPT_sub_6FD11E40(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nElementalType, int32_t nDamage, int32_t nLength, int32_t* pResistStatId, int32_t* pElementalType)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_sub_6FD11E40(pUnit, &tempDamageStrc, nElementalType, nDamage, nLength, pResistStatId, pElementalType);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt01_Attack_LeftHandSwing(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt65_Throw_LeftHandThrow(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt02_Kick(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt03_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt03_Unsummon(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo001_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo001_Attack_LeftHandSwing(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo004_Unsummon(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo003_Throw(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo005_LeftHandThrow(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD12950(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5)
{
    return ESE_sub_6FD12950(pGame, pUnit, nSkillId, nSkillLevel, a5);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_Handler_6FD12BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5, int32_t a6, int32_t a7)
{
    return ESE_D2GAME_SKILLS_Handler_6FD12BA0(pGame, pUnit, nSkillId, nSkillLevel, a5, a6, a7);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD12FD0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD12FD0(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD13220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_sub_6FD13220(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5)
{
    return ESE_sub_6FD13260(pGame, pUnit, nSkillId, nSkillLevel, a5);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD13330(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel, int32_t a6)
{
    return ESE_sub_6FD13330(pGame, pUnit, a5, nSkillId, nSkillLevel, a6);
}

void __fastcall ESE_INTERCEPT_sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FD13410(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction09_6FD13470(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillIdArg, int32_t a4)
{
    ESE_D2GAME_MONSTERS_AiFunction09_6FD13470(pGame, pUnit, nSkillIdArg, a4);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction10_6FD13610(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nSkillId)
{
    ESE_D2GAME_MONSTERS_AiFunction10_6FD13610(pGame, pUnit, a3, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD136E0(D2UnitStrc* pUnit, int32_t nSkillId)
{
    return ESE_sub_6FD136E0(pUnit, nSkillId);
}

void __fastcall ESE_INTERCEPT_D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int32_t a2, int32_t nSkillId, int32_t nFlags)
{
    ESE_D2GAME_AssignSkill_6FD13800(pUnit, a2, nSkillId, nFlags);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pPortal, int32_t nDestLevel, int32_t nSourceLevel)
{
    return ESE_D2GAME_CreateLinkPortal_6FD13B20(pGame, pPortal, nDestLevel, nSourceLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nDestLevel, D2UnitStrc** ppSourceUnit, int32_t nObjectId, int32_t bPerm)
{
    return ESE_D2GAME_CreatePortalObject_6FD13DF0(pGame, pUnit, pRoom, nX, nY, nDestLevel, ppSourceUnit, nObjectId, bPerm);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t* pX, int32_t* pY)
{
    return ESE_D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, pX, pY);
}

void __fastcall ESE_INTERCEPT_sub_6FD140D0(int32_t* pX, int32_t* pY)
{
    ESE_sub_6FD140D0(pX, pY);
}

void __fastcall ESE_INTERCEPT_sub_6FD14120(int32_t* pX, int32_t* pY)
{
    ESE_sub_6FD14120(pX, pY);
}

void __fastcall ESE_INTERCEPT_sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* a3, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nVelocity)
{
    ESE_sub_6FD14170(pGame, pOwner, a3, nMissileId, nSkillId, nSkillLevel, nVelocity);
}

void __fastcall ESE_INTERCEPT_sub_6FD14260(D2GameStrc* pGame, int32_t nMissiles, D2MissileStrc* missileParams)
{
    ESE_sub_6FD14260(pGame, nMissiles, missileParams);
}

void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction06_6FD14370(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_D2GAME_MONSTERS_AiFunction06_6FD14370(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nDoFunc, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD14400(pGame, pUnit, nDoFunc, nSkillId, nSkillLevel);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg)
{
    return ESE_D2GAME_SummonPet_6FD14430(pGame, pSummonArg);
}

void __fastcall ESE_INTERCEPT_sub_6FD146D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FD146D0(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD14770(D2GameStrc* pGame, int32_t nFlags, D2UnitStrc* pUnit, int32_t nSkillLevel, int32_t nRange, CurseCallbackFunc pfCurse)
{
    ESE_sub_6FD14770(pGame, nFlags, pUnit, nSkillLevel, nRange, pfCurse);
}

void __fastcall ESE_INTERCEPT_sub_6FD149B0(D2GameStrc* pGame, D2EffectStrc* pEffect)
{
    ESE_sub_6FD149B0(pGame, pEffect);
}

void __fastcall ESE_INTERCEPT_sub_6FD14BD0(D2GameStrc* pGame, int32_t nFlags, int32_t nX, int32_t nY, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, void* pfAreaEffect)
{
    ESE_sub_6FD14BD0(pGame, nFlags, nX, nY, pUnit, nSkillId, nSkillLevel, pfAreaEffect);
}

void __fastcall ESE_INTERCEPT_sub_6FD14C30(D2UnitStrc* pUnit)
{
    ESE_sub_6FD14C30(pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t bRemove)
{
    ESE_D2GAME_SetSkills_6FD14C60(pUnit, nSkillId, nSkillLevel, bRemove);
}

void __fastcall ESE_INTERCEPT_D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit)
{
    ESE_D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD14D20(D2UnitStrc* pUnit, int32_t nUnused, D2MonSkillInfoStrc* pMonSkillInfo)
{
    ESE_sub_6FD14D20(pUnit, nUnused, pMonSkillInfo);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    int64_t result = ESE_D2GAME_RollElementalDamage_6FD14DD0(pUnit, &tempDamageStrc, nSkillId, nSkillLevel);
    tempDamageStrc.WriteToOriginalStruct(pDamage);

    return Clamp64To32(result);
}

void __fastcall ESE_INTERCEPT_D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &tempDamageStrc, nSkillId, nSkillLevel);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

void __fastcall ESE_INTERCEPT_sub_6FD14F70(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int32_t nDelay)
{
    ESE_sub_6FD14F70(pGame, pUnused, pUnit, nDelay);
}

void __fastcall ESE_INTERCEPT_sub_6FD15080(D2UnitStrc* pUnit, int32_t a2)
{
    ESE_sub_6FD15080(pUnit, a2);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD150A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return ESE_sub_6FD150A0(pGame, pUnit, pTarget);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD15190(D2UnitStrc* pUnit, int32_t nSpecialState)
{
    return ESE_sub_6FD15190(pUnit, nSpecialState);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_sub_6FD15210(pUnit, pTarget, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD15320(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg)
{
    return ESE_sub_6FD15320(pUnit, pArg);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMissileId)
{
    return ESE_sub_6FD15340(pGame, pUnit, nMissileId);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD15460(D2UnitStrc* pUnit)
{
    return ESE_sub_6FD15460(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FD15470(D2UnitStrc* pUnit, int32_t nAttackRate)
{
    ESE_sub_6FD15470(pUnit, nAttackRate);
}

void __fastcall ESE_INTERCEPT_sub_6FD154D0(D2UnitStrc* pUnit)
{
    ESE_sub_6FD154D0(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD15500(D2UnitStrc* pUnit)
{
    return ESE_sub_6FD15500(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int32_t bFromMonster, int32_t nSkillId, int32_t nSkillLevel, int32_t* pSpawnMode, int32_t* pX, int32_t* pY)
{
    return ESE_D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, bFromMonster, nSkillId, nSkillLevel, pSpawnMode, pX, pY);
}

void __fastcall ESE_INTERCEPT_sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage, int32_t a8)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_sub_6FD155E0(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &tempDamageStrc, a8);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

void __fastcall ESE_INTERCEPT_sub_6FD15650(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, uint16_t wResultFlags, int32_t a5, D2DamageStrc* pDamage, int32_t a7)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_sub_6FD15650(pGame, pOwner, pUnit, wResultFlags, a5, &tempDamageStrc, a7);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

D2UnitEventStrc* __fastcall ESE_INTERCEPT_sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t a4, int32_t a5, int32_t nEventFunc, int32_t a7, int32_t a8)
{
    // It doesn't really matter, all the callers are looking for is a null or non-null return
    return (D2UnitEventStrc * )ESE_sub_6FD156A0(pGame, pUnit, nTimerType, a4, a5, nEventFunc, a7, a8);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt18_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt18_Attract(pGame, pUnit, nSkillId, nSkillLevel);
}
