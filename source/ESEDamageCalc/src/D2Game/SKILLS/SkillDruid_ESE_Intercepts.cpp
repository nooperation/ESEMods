#include "D2Game/SKILLS/SkillDruid_ESE_Intercepts.h"

decltype(&SKILLS_SrvDo114_Raven) SKILLS_SrvDo114_Raven_Original = nullptr;
decltype(&SKILLS_SrvDo115_Vines) SKILLS_SrvDo115_Vines_Original = nullptr;
decltype(&sub_6FCFE030) sub_6FCFE030_Original = nullptr;
decltype(&sub_6FCFE0E0) sub_6FCFE0E0_Original = nullptr;
decltype(&sub_6FCFE200) sub_6FCFE200_Original = nullptr;
decltype(&SKILLS_SrvDo116_Wearwolf_Wearbear) SKILLS_SrvDo116_Wearwolf_Wearbear_Original = nullptr;
decltype(&sub_6FCFE4C0) sub_6FCFE4C0_Original = nullptr;
decltype(&SKILLS_SrvDo117_Firestorm) SKILLS_SrvDo117_Firestorm_Original = nullptr;
decltype(&SKILLS_SrvDo118_Twister_Tornado) SKILLS_SrvDo118_Twister_Tornado_Original = nullptr;
decltype(&SKILLS_SrvDo119_DruidSummon) SKILLS_SrvDo119_DruidSummon_Original = nullptr;
decltype(&SKILLS_SrvSt56_FeralRage_Maul) SKILLS_SrvSt56_FeralRage_Maul_Original = nullptr;
decltype(&SKILLS_SrvDo120_FeralRage_Maul) SKILLS_SrvDo120_FeralRage_Maul_Original = nullptr;
decltype(&SKILLS_SrvSt57_Rabies) SKILLS_SrvSt57_Rabies_Original = nullptr;
decltype(&sub_6FCFEDD0) sub_6FCFEDD0_Original = nullptr;
decltype(&SKILLS_SrvDo121_Rabies) SKILLS_SrvDo121_Rabies_Original = nullptr;
decltype(&sub_6FCFF2E0) sub_6FCFF2E0_Original = nullptr;
decltype(&SKILLS_SrvSt58_FireClaws) SKILLS_SrvSt58_FireClaws_Original = nullptr;
decltype(&SKILLS_SrvDo122_Hunger) SKILLS_SrvDo122_Hunger_Original = nullptr;
decltype(&SKILLS_SrvDo123_Volcano) SKILLS_SrvDo123_Volcano_Original = nullptr;
decltype(&SKILLS_SrvDo124_Armageddon_Hurricane) SKILLS_SrvDo124_Armageddon_Hurricane_Original = nullptr;
decltype(&SKILLS_SrvDo145_Unused) SKILLS_SrvDo145_Unused_Original = nullptr;
decltype(&SKILLS_SrvDo146_Unused) SKILLS_SrvDo146_Unused_Original = nullptr;
decltype(&D2GAME_EventFunc25_6FD00140) D2GAME_EventFunc25_6FD00140_Original = nullptr;
decltype(&sub_6FD00370) sub_6FD00370_Original = nullptr;
decltype(&SKILLS_SrvDo125_WakeOfDestruction) SKILLS_SrvDo125_WakeOfDestruction_Original = nullptr;
decltype(&SKILLS_SrvSt59_ImpInferno) SKILLS_SrvSt59_ImpInferno_Original = nullptr;
decltype(&SKILLS_SrvDo126_ImpInferno) SKILLS_SrvDo126_ImpInferno_Original = nullptr;
decltype(&SKILLS_SrvSt60_SuckBlood) SKILLS_SrvSt60_SuckBlood_Original = nullptr;
decltype(&SKILLS_SrvDo127_SuckBlood) SKILLS_SrvDo127_SuckBlood_Original = nullptr;
decltype(&SKILLS_SrvDo128_CryHelp) SKILLS_SrvDo128_CryHelp_Original = nullptr;
decltype(&sub_6FD00EC0) sub_6FD00EC0_Original = nullptr;
decltype(&sub_6FD01010) sub_6FD01010_Original = nullptr;
decltype(&SKILLS_SrvDo129_ImpTeleport) SKILLS_SrvDo129_ImpTeleport_Original = nullptr;
decltype(&SKILLS_SrvSt61_SelfResurrect) SKILLS_SrvSt61_SelfResurrect_Original = nullptr;
decltype(&SKILLS_SrvDo130_VineAttack) SKILLS_SrvDo130_VineAttack_Original = nullptr;
decltype(&SKILLS_SrvDo131_OverseerWhip) SKILLS_SrvDo131_OverseerWhip_Original = nullptr;
decltype(&sub_6FD017F0) sub_6FD017F0_Original = nullptr;
decltype(&SKILLS_SrvDo132_ImpFireMissile) SKILLS_SrvDo132_ImpFireMissile_Original = nullptr;
decltype(&sub_6FD01910) sub_6FD01910_Original = nullptr;
decltype(&SKILLS_SrvDo133_Impregnate) SKILLS_SrvDo133_Impregnate_Original = nullptr;
decltype(&sub_6FD01B00) sub_6FD01B00_Original = nullptr;
decltype(&SKILLS_SrvDo134_SiegeBeastStomp) SKILLS_SrvDo134_SiegeBeastStomp_Original = nullptr;
decltype(&SKILLS_SrvSt62_MinionSpawner) SKILLS_SrvSt62_MinionSpawner_Original = nullptr;
decltype(&SKILLS_SrvDo135_MinionSpawner) SKILLS_SrvDo135_MinionSpawner_Original = nullptr;
decltype(&SKILLS_SrvDo136_DeathMaul) SKILLS_SrvDo136_DeathMaul_Original = nullptr;
decltype(&SKILLS_SrvDo137_FenrisRage) SKILLS_SrvDo137_FenrisRage_Original = nullptr;
decltype(&SKILLS_SrvDo138_Unused) SKILLS_SrvDo138_Unused_Original = nullptr;
decltype(&SKILLS_SrvDo139_BaalColdMissiles) SKILLS_SrvDo139_BaalColdMissiles_Original = nullptr;
decltype(&SKILLS_SrvSt63_Corpse_VineCycler) SKILLS_SrvSt63_Corpse_VineCycler_Original = nullptr;
decltype(&SKILLS_SrvDo147_Unused) SKILLS_SrvDo147_Unused_Original = nullptr;
decltype(&D2GAME_SKILLS_BloodMana_6FD025E0) D2GAME_SKILLS_BloodMana_6FD025E0_Original = nullptr;
decltype(&SKILLS_SrvDo140_BaalTentacle) SKILLS_SrvDo140_BaalTentacle_Original = nullptr;
decltype(&SKILLS_SrvDo141_BaalCorpseExplode) SKILLS_SrvDo141_BaalCorpseExplode_Original = nullptr;
decltype(&SKILLS_AreaEffect_BaalCorpseExplode) SKILLS_AreaEffect_BaalCorpseExplode_Original = nullptr;
decltype(&SKILLS_FindUseableCorpse) SKILLS_FindUseableCorpse_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo114_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    //return SKILLS_SrvDo114_Raven_Original(pGame, pUnit, nSkillId, nSkillLevel);
    return ESE_SKILLS_SrvDo114_Raven(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo115_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo115_Vines(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCFE030(D2UnitStrc* pUnit, int32_t nStateId, D2StatListStrc* pStatList)
{
    ESE_sub_6FCFE030(pUnit, nStateId, pStatList);
}

void __fastcall ESE_INTERCEPT_sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FCFE0E0(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FCFE200(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo116_Wearwolf_Wearbear(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo116_Wearwolf_Wearbear(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCFE4C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSubMissiles, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t a7)
{
    return ESE_sub_6FCFE4C0(pGame, pUnit, nSubMissiles, nMissileId, nSkillId, nSkillLevel, a7);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo117_Firestorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo117_Firestorm(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo118_Twister_Tornado(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo118_Twister_Tornado(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo119_DruidSummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo119_DruidSummon(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt56_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt56_FeralRage_Maul(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo120_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo120_FeralRage_Maul(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt57_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt57_Rabies(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCFEDD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nTimeout, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_sub_6FCFEDD0(pGame, pUnit, pTarget, nTimeout, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo121_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo121_Rabies(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FCFF2E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nRange, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FCFF2E0(pGame, pUnit, pTarget, nRange, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt58_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt58_FireClaws(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo122_Hunger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo122_Hunger(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo123_Volcano(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo123_Volcano(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo124_Armageddon_Hurricane(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo124_Armageddon_Hurricane(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo145_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo145_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo146_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo146_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc25_6FD00140(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_D2GAME_EventFunc25_6FD00140(pGame, nEvent, pAttacker, pUnit, pDamage, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD00370(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillLevel)
{
    return ESE_sub_6FD00370(pGame, pUnit, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo125_WakeOfDestruction(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo125_WakeOfDestruction(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt59_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt59_ImpInferno(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo126_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo126_ImpInferno(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt60_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt60_SuckBlood(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo127_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo127_SuckBlood(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo128_CryHelp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo128_CryHelp(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD00EC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD00EC0(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD01010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int32_t nSkillId, int32_t nSkillLevel)
{
    ESE_sub_6FD01010(pGame, pUnit, pOwner, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo129_ImpTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo129_ImpTeleport(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt61_SelfResurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt61_SelfResurrect(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo130_VineAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo130_VineAttack(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo131_OverseerWhip(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo131_OverseerWhip(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD017F0(int32_t nMonsterId, int32_t nNoInChain)
{
    return ESE_sub_6FD017F0(nMonsterId, nNoInChain);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo132_ImpFireMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo132_ImpFireMissile(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FD01910(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return ESE_sub_6FD01910(pUnit, pTarget);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo133_Impregnate(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo133_Impregnate(pGame, pUnit, nSkillId, nSkillLevel);
}

void __fastcall ESE_INTERCEPT_sub_6FD01B00(D2UnitStrc* pUnit, int32_t nStateId, D2StatListStrc* pStatList)
{
    ESE_sub_6FD01B00(pUnit, nStateId, pStatList);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo134_SiegeBeastStomp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo134_SiegeBeastStomp(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt62_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt62_MinionSpawner(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo135_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo135_MinionSpawner(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo136_DeathMaul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo136_DeathMaul(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo137_FenrisRage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo137_FenrisRage(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo138_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo138_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo139_BaalColdMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo139_BaalColdMissiles(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt63_Corpse_VineCycler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvSt63_Corpse_VineCycler(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo147_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo147_Unused(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int32_t nManaCost)
{
    return ESE_D2GAME_SKILLS_BloodMana_6FD025E0(pUnit, nManaCost);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo140_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo140_BaalTentacle(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo141_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel)
{
    return ESE_SKILLS_SrvDo141_BaalCorpseExplode(pGame, pUnit, nSkillId, nSkillLevel);
}

int32_t __fastcall ESE_INTERCEPT_SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel, int32_t nUnused)
{
    return ESE_SKILLS_AreaEffect_BaalCorpseExplode(pGame, pUnit, pTarget, nSkillLevel, nUnused);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int32_t nUnitSize)
{
    return ESE_SKILLS_FindUseableCorpse(pGame, pUnit, pOwner, nUnitSize);
}


