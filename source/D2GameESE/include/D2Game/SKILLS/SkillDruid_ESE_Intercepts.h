#pragma once

#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Game/SKILLS/SkillDruid_ESE.h"

#include <D2StatList.h>
#include <Units/Units.h>

#include <type_traits>
#include <cstdlib>

//D2Game.0x6FCFDCF0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo114_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFDE90
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo115_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE030
void __fastcall ESE_INTERCEPT_sub_6FCFE030(D2UnitStrc* pUnit, int32_t nStateId, D2StatListStrc* pStatList);
//D2Game.0x6FCFE0E0
void __fastcall ESE_INTERCEPT_sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE200
void __fastcall ESE_INTERCEPT_sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE330
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo116_Wearwolf_Wearbear(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE4C0
int32_t __fastcall ESE_INTERCEPT_sub_6FCFE4C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSubMissiles, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t a7);
//D2Game.0x6FCFE5F0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo117_Firestorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE6A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo118_Twister_Tornado(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE750
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo119_DruidSummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFE900
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt56_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFEA60
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo120_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFEC90
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt57_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFEDD0
int32_t __fastcall ESE_INTERCEPT_sub_6FCFEDD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nTimeout, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFEFD0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo121_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFF2E0
void __fastcall ESE_INTERCEPT_sub_6FCFF2E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nRange, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFF3C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt58_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFF4E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo122_Hunger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFF710
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo123_Volcano(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFF870
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo124_Armageddon_Hurricane(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFFAB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo145_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FCFFCA0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo146_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00140
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc25_6FD00140(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00370
int32_t __fastcall ESE_INTERCEPT_sub_6FD00370(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillLevel);
//D2Game.0x6FD004E0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo125_WakeOfDestruction(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00660
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt59_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00710
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo126_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD009F0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt60_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00BE0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo127_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00DC0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo128_CryHelp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD00EC0
void __fastcall ESE_INTERCEPT_sub_6FD00EC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01010
void __fastcall ESE_INTERCEPT_sub_6FD01010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01170
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo129_ImpTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01320
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt61_SelfResurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01360
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo130_VineAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD014A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo131_OverseerWhip(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD017F0
int32_t __fastcall ESE_INTERCEPT_sub_6FD017F0(int32_t nMonsterId, int32_t nNoInChain);
//D2Game.0x6FD01860
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo132_ImpFireMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01910
int32_t __fastcall ESE_INTERCEPT_sub_6FD01910(D2UnitStrc* pUnit, D2UnitStrc* pTarget);
//D2Game.0x6FD019B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo133_Impregnate(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01B00
void __fastcall ESE_INTERCEPT_sub_6FD01B00(D2UnitStrc* pUnit, int32_t nStateId, D2StatListStrc* pStatList);
//D2Game.0x6FD01BB0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo134_SiegeBeastStomp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01CC0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt62_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01D40
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo135_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD01F10
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo136_DeathMaul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD02070
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo137_FenrisRage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD02140
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo138_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD02360
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo139_BaalColdMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD024A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt63_Corpse_VineCycler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD025C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo147_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD025E0
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int32_t nManaCost);
//D2Game.0x6FD026B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo140_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD02950
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo141_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD02A50
int32_t __fastcall ESE_INTERCEPT_SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel, int32_t nUnused);
//D2Game.0x6FD02A80
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int32_t nUnitSize);

extern SKILLS_SrvDo114_Raven_t SKILLS_SrvDo114_Raven_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo114_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo115_Vines_t SKILLS_SrvDo115_Vines_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo115_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FCFE030_t sub_6FCFE030_Original;
void __fastcall ESE_INTERCEPT_sub_6FCFE030(D2UnitStrc* pUnit, int32_t nStateId, D2StatListStrc* pStatList);

extern sub_6FCFE0E0_t sub_6FCFE0E0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCFE0E0(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FCFE200_t sub_6FCFE200_Original;
void __fastcall ESE_INTERCEPT_sub_6FCFE200(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo116_Wearwolf_Wearbear_t SKILLS_SrvDo116_Wearwolf_Wearbear_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo116_Wearwolf_Wearbear(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FCFE4C0_t sub_6FCFE4C0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCFE4C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSubMissiles, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t a7);

extern SKILLS_SrvDo117_Firestorm_t SKILLS_SrvDo117_Firestorm_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo117_Firestorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo118_Twister_Tornado_t SKILLS_SrvDo118_Twister_Tornado_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo118_Twister_Tornado(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo119_DruidSummon_t SKILLS_SrvDo119_DruidSummon_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo119_DruidSummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt56_FeralRage_Maul_t SKILLS_SrvSt56_FeralRage_Maul_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt56_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo120_FeralRage_Maul_t SKILLS_SrvDo120_FeralRage_Maul_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo120_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt57_Rabies_t SKILLS_SrvSt57_Rabies_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt57_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FCFEDD0_t sub_6FCFEDD0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCFEDD0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nTimeout, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo121_Rabies_t SKILLS_SrvDo121_Rabies_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo121_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FCFF2E0_t sub_6FCFF2E0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCFF2E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nRange, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt58_FireClaws_t SKILLS_SrvSt58_FireClaws_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt58_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo122_Hunger_t SKILLS_SrvDo122_Hunger_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo122_Hunger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo123_Volcano_t SKILLS_SrvDo123_Volcano_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo123_Volcano(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo124_Armageddon_Hurricane_t SKILLS_SrvDo124_Armageddon_Hurricane_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo124_Armageddon_Hurricane(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo145_Unused_t SKILLS_SrvDo145_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo145_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo146_Unused_t SKILLS_SrvDo146_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo146_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern D2GAME_EventFunc25_6FD00140_t D2GAME_EventFunc25_6FD00140_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc25_6FD00140(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD00370_t sub_6FD00370_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD00370(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillLevel);

extern SKILLS_SrvDo125_WakeOfDestruction_t SKILLS_SrvDo125_WakeOfDestruction_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo125_WakeOfDestruction(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt59_ImpInferno_t SKILLS_SrvSt59_ImpInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt59_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo126_ImpInferno_t SKILLS_SrvDo126_ImpInferno_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo126_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt60_SuckBlood_t SKILLS_SrvSt60_SuckBlood_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt60_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo127_SuckBlood_t SKILLS_SrvDo127_SuckBlood_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo127_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo128_CryHelp_t SKILLS_SrvDo128_CryHelp_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo128_CryHelp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD00EC0_t sub_6FD00EC0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD00EC0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD01010_t sub_6FD01010_Original;
void __fastcall ESE_INTERCEPT_sub_6FD01010(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo129_ImpTeleport_t SKILLS_SrvDo129_ImpTeleport_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo129_ImpTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt61_SelfResurrect_t SKILLS_SrvSt61_SelfResurrect_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt61_SelfResurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo130_VineAttack_t SKILLS_SrvDo130_VineAttack_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo130_VineAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo131_OverseerWhip_t SKILLS_SrvDo131_OverseerWhip_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo131_OverseerWhip(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD017F0_t sub_6FD017F0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD017F0(int32_t nMonsterId, int32_t nNoInChain);

extern SKILLS_SrvDo132_ImpFireMissile_t SKILLS_SrvDo132_ImpFireMissile_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo132_ImpFireMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD01910_t sub_6FD01910_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD01910(D2UnitStrc* pUnit, D2UnitStrc* pTarget);

extern SKILLS_SrvDo133_Impregnate_t SKILLS_SrvDo133_Impregnate_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo133_Impregnate(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD01B00_t sub_6FD01B00_Original;
void __fastcall ESE_INTERCEPT_sub_6FD01B00(D2UnitStrc* pUnit, int32_t nStateId, D2StatListStrc* pStatList);

extern SKILLS_SrvDo134_SiegeBeastStomp_t SKILLS_SrvDo134_SiegeBeastStomp_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo134_SiegeBeastStomp(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt62_MinionSpawner_t SKILLS_SrvSt62_MinionSpawner_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt62_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo135_MinionSpawner_t SKILLS_SrvDo135_MinionSpawner_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo135_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo136_DeathMaul_t SKILLS_SrvDo136_DeathMaul_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo136_DeathMaul(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo137_FenrisRage_t SKILLS_SrvDo137_FenrisRage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo137_FenrisRage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo138_Unused_t SKILLS_SrvDo138_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo138_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo139_BaalColdMissiles_t SKILLS_SrvDo139_BaalColdMissiles_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo139_BaalColdMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt63_Corpse_VineCycler_t SKILLS_SrvSt63_Corpse_VineCycler_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt63_Corpse_VineCycler(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo147_Unused_t SKILLS_SrvDo147_Unused_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo147_Unused(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern D2GAME_SKILLS_BloodMana_6FD025E0_t D2GAME_SKILLS_BloodMana_6FD025E0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int32_t nManaCost);

extern SKILLS_SrvDo140_BaalTentacle_t SKILLS_SrvDo140_BaalTentacle_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo140_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo141_BaalCorpseExplode_t SKILLS_SrvDo141_BaalCorpseExplode_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo141_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_AreaEffect_BaalCorpseExplode_t SKILLS_AreaEffect_BaalCorpseExplode_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel, int32_t nUnused);

extern SKILLS_FindUseableCorpse_t SKILLS_FindUseableCorpse_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int32_t nUnitSize);

