#include <SKILLS/SkillNec_ESE_Intercepts.h>

decltype(&SKILLS_SrvSt15_RaiseSkeleton_Mage) SKILLS_SrvSt15_RaiseSkeleton_Mage_Original = nullptr;
decltype(&SKILLS_SrvSt16_PoisonDagger) SKILLS_SrvSt16_PoisonDagger_Original = nullptr;
decltype(&SKILLS_SrvSt17_Poison_CorpseExplosion) SKILLS_SrvSt17_Poison_CorpseExplosion_Original = nullptr;
decltype(&SKILLS_SrvSt19_BonePrison) SKILLS_SrvSt19_BonePrison_Original = nullptr;
decltype(&SKILLS_SrvSt20_IronGolem) SKILLS_SrvSt20_IronGolem_Original = nullptr;
decltype(&SKILLS_SrvSt21_Revive) SKILLS_SrvSt21_Revive_Original = nullptr;
decltype(&sub_6FD0B250) sub_6FD0B250_Original = nullptr;
decltype(&sub_6FD0B2B0) sub_6FD0B2B0_Original = nullptr;
decltype(&sub_6FD0B3D0) sub_6FD0B3D0_Original = nullptr;
decltype(&sub_6FD0B450) sub_6FD0B450_Original = nullptr;
decltype(&SKILLS_SrvDo030_Curse) SKILLS_SrvDo030_Curse_Original = nullptr;
decltype(&sub_6FD0B9F0) sub_6FD0B9F0_Original = nullptr;
decltype(&SKILLS_SrvDo059_Attract) SKILLS_SrvDo059_Attract_Original = nullptr;
decltype(&sub_6FD0BDA0) sub_6FD0BDA0_Original = nullptr;
decltype(&SKILLS_SrvDo061_Confuse) SKILLS_SrvDo061_Confuse_Original = nullptr;
decltype(&sub_6FD0C060) sub_6FD0C060_Original = nullptr;
decltype(&sub_6FD0C2B0) sub_6FD0C2B0_Original = nullptr;
decltype(&D2GAME_SetSummonResistance_6FD0C2E0) D2GAME_SetSummonResistance_6FD0C2E0_Original = nullptr;
decltype(&D2GAME_SetUnitComponent_6FD0C3A0) D2GAME_SetUnitComponent_6FD0C3A0_Original = nullptr;
decltype(&sub_6FD0C500) sub_6FD0C500_Original = nullptr;
decltype(&D2GAME_SetSummonPassiveStats_6FD0C530) D2GAME_SetSummonPassiveStats_6FD0C530_Original = nullptr;
decltype(&D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10) D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10_Original = nullptr;
decltype(&SKILLS_SrvDo031_RaiseSkeleton_Mage) SKILLS_SrvDo031_RaiseSkeleton_Mage_Original = nullptr;
decltype(&SKILLS_SrvDo032_PoisonDagger) SKILLS_SrvDo032_PoisonDagger_Original = nullptr;
decltype(&sub_6FD0D000) sub_6FD0D000_Original = nullptr;
decltype(&SKILLS_SrvDo055_CorpseExplosion) SKILLS_SrvDo055_CorpseExplosion_Original = nullptr;
decltype(&SKILLS_SrvDo056_Golem) SKILLS_SrvDo056_Golem_Original = nullptr;
decltype(&SKILLS_SrvDo057_IronGolem) SKILLS_SrvDo057_IronGolem_Original = nullptr;
decltype(&SKILLS_SrvDo058_Revive) SKILLS_SrvDo058_Revive_Original = nullptr;
decltype(&sub_6FD0DF40) sub_6FD0DF40_Original = nullptr;
decltype(&SKILLS_SrvDo060_BoneWall) SKILLS_SrvDo060_BoneWall_Original = nullptr;
decltype(&SKILLS_SrvDo062_BonePrison) SKILLS_SrvDo062_BonePrison_Original = nullptr;
decltype(&SKILLS_SrvDo063_PoisonExplosion) SKILLS_SrvDo063_PoisonExplosion_Original = nullptr;
decltype(&D2GAME_EventFunc04_6FD0E840) D2GAME_EventFunc04_6FD0E840_Original = nullptr;
decltype(&D2GAME_EventFunc05_6FD0EDE0) D2GAME_EventFunc05_6FD0EDE0_Original = nullptr;
decltype(&D2GAME_EventFunc22_6FD0F000) D2GAME_EventFunc22_6FD0F000_Original = nullptr;
decltype(&D2GAME_EventFunc23_6FD0F1F0) D2GAME_EventFunc23_6FD0F1F0_Original = nullptr;
decltype(&sub_6FD0F590) sub_6FD0F590_Original = nullptr;
decltype(&D2GAME_EventFunc26_6FD0F5E0) D2GAME_EventFunc26_6FD0F5E0_Original = nullptr;
decltype(&D2GAME_EventFunc27_6FD0F7A0) D2GAME_EventFunc27_6FD0F7A0_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt15_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt15_RaiseSkeleton_Mage(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt16_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt16_PoisonDagger(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt17_Poison_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt17_Poison_CorpseExplosion(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt19_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt19_BonePrison(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt20_IronGolem(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt21_Revive(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD0B250(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_sub_6FD0B250(pUnit, nState, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0B2B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return ESE_sub_6FD0B2B0(pGame, pUnit, pTarget);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0B3D0(D2UnitStrc* pUnit, int32_t nStatId, int32_t nResist)
{
    return ESE_sub_6FD0B3D0(pUnit, nStatId, nResist);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs)
{
    return ESE_sub_6FD0B450(pUnit, pArgs);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo030_Curse(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo030_Curse(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel)
{
    ESE_sub_6FD0B9F0(pGame, pUnit, pTarget, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo059_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo059_Attract(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg)
{
    return ESE_sub_6FD0BDA0(pUnit, pArg);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo061_Confuse(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo061_Confuse(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0C060(D2UnitStrc* pUnit, void* pArg)
{
    return ESE_sub_6FD0C060(pUnit, pArg);
}

void __fastcall ESE_INTERCEPT_sub_6FD0C2B0(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList)
{
    ESE_sub_6FD0C2B0(pUnit, nState, pStatList);
}

void __fastcall ESE_INTERCEPT_D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet)
{
    ESE_D2GAME_SetSummonResistance_6FD0C2E0(pUnit, pPet);
}

void __fastcall ESE_INTERCEPT_D2GAME_SetUnitComponent_6FD0C3A0(D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nLevel, int32_t bHasShield, int32_t bSpecial)
{
    ESE_D2GAME_SetUnitComponent_6FD0C3A0(pUnit, pPet, nLevel, bHasShield, bSpecial);
}

void __fastcall ESE_INTERCEPT_sub_6FD0C500(D2UnitStrc* pMonster, uint8_t nIndex, uint8_t nComponent)
{
    ESE_sub_6FD0C500(pMonster, nIndex, nComponent);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nSkillId, int32_t nSkillLevel, int32_t nItemLevel)
{
    return ESE_D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, nItemLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nPetLevelArg, int32_t nSkillLevel)
{
    return ESE_D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, nPetLevelArg, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo031_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo031_RaiseSkeleton_Mage(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo032_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo032_PoisonDagger(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0D000(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    return ESE_sub_6FD0D000(pAuraCallback, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo055_CorpseExplosion(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo056_Golem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo056_Golem(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo057_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo057_IronGolem(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo058_Revive(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD0DF40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD0DF40(pGame, pUnit, pMonster, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo060_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo060_BoneWall(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo062_BonePrison(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo063_PoisonExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo063_PoisonExplosion(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc04_6FD0E840(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc04_6FD0E840(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc05_6FD0EDE0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc05_6FD0EDE0(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc22_6FD0F000(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc22_6FD0F000(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc23_6FD0F1F0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc23_6FD0F1F0(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD0F590(D2UnitStrc* pUnit, int32_t nValue)
{
    return ESE_sub_6FD0F590(pUnit, nValue);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc26_6FD0F5E0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc26_6FD0F5E0(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc27_6FD0F7A0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc27_6FD0F7A0(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}


