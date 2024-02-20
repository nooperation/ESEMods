#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <SKILLS/SkillNec_ESE.h>

//D2Game.0x6FD0AF30
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt15_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0AF70
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt16_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0B0B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt17_Poison_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0B0F0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt19_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0B120
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0B190
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0B250
void __fastcall ESE_INTERCEPT_sub_6FD0B250(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD0B2B0
int32_t __fastcall ESE_INTERCEPT_sub_6FD0B2B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
//D2Game.0x6FD0B3D0
int32_t __fastcall ESE_INTERCEPT_sub_6FD0B3D0(D2UnitStrc* pUnit, int32_t nStatId, int32_t nResist);
//D2Game.0x6FD0B450
int32_t __fastcall ESE_INTERCEPT_sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs);
//D2Game.0x6FD0B790
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo030_Curse(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0B9F0
void __fastcall ESE_INTERCEPT_sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel);
//D2Game.0x6FD0BB60
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo059_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0BDA0
int32_t __fastcall ESE_INTERCEPT_sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg);
//D2Game.0x6FD0BE50
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo061_Confuse(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0C060
int32_t __fastcall ESE_INTERCEPT_sub_6FD0C060(D2UnitStrc* pUnit, void* pArg);
//D2Game.0x6FD0C2B0
void __fastcall ESE_INTERCEPT_sub_6FD0C2B0(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD0C2E0
void __fastcall ESE_INTERCEPT_D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet);
//D2Game.0x6FD0C3A0
void __fastcall ESE_INTERCEPT_D2GAME_SetUnitComponent_6FD0C3A0(D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nLevel, int32_t bHasShield, int32_t bSpecial);
//D2Game.0x6FD0C500
void __fastcall ESE_INTERCEPT_sub_6FD0C500(D2UnitStrc* pMonster, uint8_t nIndex, uint8_t nComponent);
//D2Game.0x6FD0C530
int32_t __fastcall ESE_INTERCEPT_D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nSkillId, int32_t nSkillLevel, int32_t nItemLevel);
//D2Game.0x6FD0CB10
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nPetLevelArg, int32_t nSkillLevel);
//D2Game.0x6FD0CC10
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo031_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0CFC0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo032_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0D000
int32_t __fastcall ESE_INTERCEPT_sub_6FD0D000(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD0D0D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0D620
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo056_Golem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0D7B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo057_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0DAC0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0DF40
void __fastcall ESE_INTERCEPT_sub_6FD0DF40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0E050
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo060_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0E4C0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0E790
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo063_PoisonExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0E840
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc04_6FD0E840(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0EDE0
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc05_6FD0EDE0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0F000
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc22_6FD0F000(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0F1F0
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc23_6FD0F1F0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0F590
int32_t __fastcall ESE_INTERCEPT_sub_6FD0F590(D2UnitStrc* pUnit, int32_t nValue);
//D2Game.0x6FD0F5E0
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc26_6FD0F5E0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD0F7A0
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc27_6FD0F7A0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt15_RaiseSkeleton_Mage) SKILLS_SrvSt15_RaiseSkeleton_Mage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt15_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt16_PoisonDagger) SKILLS_SrvSt16_PoisonDagger_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt16_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt17_Poison_CorpseExplosion) SKILLS_SrvSt17_Poison_CorpseExplosion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt17_Poison_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt19_BonePrison) SKILLS_SrvSt19_BonePrison_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt19_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt20_IronGolem) SKILLS_SrvSt20_IronGolem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvSt21_Revive) SKILLS_SrvSt21_Revive_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0B250) sub_6FD0B250_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0B250(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern decltype(&sub_6FD0B2B0) sub_6FD0B2B0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0B2B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

extern decltype(&sub_6FD0B3D0) sub_6FD0B3D0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0B3D0(D2UnitStrc* pUnit, int32_t nStatId, int32_t nResist);

extern decltype(&sub_6FD0B450) sub_6FD0B450_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs);

extern decltype(&SKILLS_SrvDo030_Curse) SKILLS_SrvDo030_Curse_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo030_Curse(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0B9F0) sub_6FD0B9F0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0B9F0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo059_Attract) SKILLS_SrvDo059_Attract_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo059_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0BDA0) sub_6FD0BDA0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0BDA0(D2UnitStrc* pUnit, void* pArg);

extern decltype(&SKILLS_SrvDo061_Confuse) SKILLS_SrvDo061_Confuse_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo061_Confuse(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0C060) sub_6FD0C060_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0C060(D2UnitStrc* pUnit, void* pArg);

extern decltype(&sub_6FD0C2B0) sub_6FD0C2B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0C2B0(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern decltype(&D2GAME_SetSummonResistance_6FD0C2E0) D2GAME_SetSummonResistance_6FD0C2E0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet);

extern decltype(&D2GAME_SetUnitComponent_6FD0C3A0) D2GAME_SetUnitComponent_6FD0C3A0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SetUnitComponent_6FD0C3A0(D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nLevel, int32_t bHasShield, int32_t bSpecial);

extern decltype(&sub_6FD0C500) sub_6FD0C500_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0C500(D2UnitStrc* pMonster, uint8_t nIndex, uint8_t nComponent);

extern decltype(&D2GAME_SetSummonPassiveStats_6FD0C530) D2GAME_SetSummonPassiveStats_6FD0C530_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nSkillId, int32_t nSkillLevel, int32_t nItemLevel);

extern decltype(&D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10) D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int32_t nPetLevelArg, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo031_RaiseSkeleton_Mage) SKILLS_SrvDo031_RaiseSkeleton_Mage_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo031_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo032_PoisonDagger) SKILLS_SrvDo032_PoisonDagger_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo032_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0D000) sub_6FD0D000_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0D000(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern decltype(&SKILLS_SrvDo055_CorpseExplosion) SKILLS_SrvDo055_CorpseExplosion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo056_Golem) SKILLS_SrvDo056_Golem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo056_Golem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo057_IronGolem) SKILLS_SrvDo057_IronGolem_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo057_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo058_Revive) SKILLS_SrvDo058_Revive_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0DF40) sub_6FD0DF40_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0DF40(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo060_BoneWall) SKILLS_SrvDo060_BoneWall_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo060_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo062_BonePrison) SKILLS_SrvDo062_BonePrison_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&SKILLS_SrvDo063_PoisonExplosion) SKILLS_SrvDo063_PoisonExplosion_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo063_PoisonExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&D2GAME_EventFunc04_6FD0E840) D2GAME_EventFunc04_6FD0E840_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc04_6FD0E840(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&D2GAME_EventFunc05_6FD0EDE0) D2GAME_EventFunc05_6FD0EDE0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc05_6FD0EDE0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&D2GAME_EventFunc22_6FD0F000) D2GAME_EventFunc22_6FD0F000_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc22_6FD0F000(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&D2GAME_EventFunc23_6FD0F1F0) D2GAME_EventFunc23_6FD0F1F0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc23_6FD0F1F0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&sub_6FD0F590) sub_6FD0F590_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0F590(D2UnitStrc* pUnit, int32_t nValue);

extern decltype(&D2GAME_EventFunc26_6FD0F5E0) D2GAME_EventFunc26_6FD0F5E0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc26_6FD0F5E0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern decltype(&D2GAME_EventFunc27_6FD0F7A0) D2GAME_EventFunc27_6FD0F7A0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_EventFunc27_6FD0F7A0(D2GameStrc* pGame, int32_t nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

