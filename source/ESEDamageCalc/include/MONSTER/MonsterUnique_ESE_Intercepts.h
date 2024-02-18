#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <DataTbls/MissilesTbls.h>
#include <DataTbls/MonsterTbls.h>
#include <Drlg/D2DrlgDrlg.h>

#include <MONSTER/MonsterUnique_ESE.h>

//D2Game.0x6FC6AC00
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ToggleUnitFlag(D2UnitStrc* pUnit, int32_t nFlag, int32_t bSet);
//D2Game.0x6FC6AC30
uint8_t* __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit);
//D2Game.0x6FC6AC50
uint16_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit);
//D2Game.0x6FC6AC70
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, uint16_t nFlag);
//D2Game.0x6FC6ACA0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, uint16_t nFlag, int32_t bSet);
//D2Game.0x6FC6ACD0
int16_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit);
//D2Game.0x6FC6ACF0
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_HasUMods(D2UnitStrc* pUnit);
//D2Game.0x6FC6AD10
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC6AD50
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod1_RandomName(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6AD90
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod2_HealthBonus(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6AF70
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage(int32_t a1, int32_t a2, int32_t a3);
//D2Game.0x6FC6AFF0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod4_LevelBonus(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B030
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B210
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B3A0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod37_Fanatic(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B3E0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod38_Possessed(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B4B0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B5D0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod41_AlwaysRun(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B610
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B8C0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod26_Teleport(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6B910
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BA70
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BB80
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod6_Fast(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BC10
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BDD0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6BF90
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C160
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C340
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C4F0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
//D2Game.0x6FC6C5B0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel);
//D2Game.0x6FC6C710
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_FireEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C740
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6C9E0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CAB0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CB40
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CD30
void __fastcall ESE_INTERCEPT_sub_6FC6CD30(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CD60
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastColdUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CDB0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpsePoisonCloud(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CE50
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_KillMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CEC0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused);
//D2Game.0x6FC6CF10
void __fastcall ESE_INTERCEPT_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6CF90
void __fastcall ESE_INTERCEPT_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D030
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ScarabModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D060
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastBugLightningMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D1C0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D410
D2MonUModTxt* __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetMonUModTxtRecord(uint32_t nUMod);
//D2Game.0x6FC6D440
void __fastcall ESE_INTERCEPT_sub_6FC6D440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D690
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_StealBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D800
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_QuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6D8B0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastQueenPoisonCloudMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DA40
void __fastcall ESE_INTERCEPT_sub_6FC6DA40(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DCB0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_LightningEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DCE0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ColdEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DD20
void __fastcall ESE_INTERCEPT_sub_6FC6DD20(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DDE0
void __fastcall ESE_INTERCEPT_sub_6FC6DDE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DFA0
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyShatterState(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6DFC0
void __fastcall ESE_INTERCEPT_sub_6FC6DFC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E070
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_SetTrapDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E240
void __fastcall ESE_INTERCEPT_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E390
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_SuicideModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E410
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E700
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E730
void __fastcall ESE_INTERCEPT_sub_6FC6E730(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E770
void __fastcall ESE_INTERCEPT_sub_6FC6E770(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC6E780
void __fastcall ESE_INTERCEPT_sub_6FC6E780(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile, int32_t nIndex);
//D2Game.0x6FC6E860
void __fastcall ESE_INTERCEPT_sub_6FC6E860(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC6E870
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction08_6FC6E870(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6E890
void __fastcall ESE_INTERCEPT_sub_6FC6E890(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC6E8A0
void __fastcall ESE_INTERCEPT_sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FC6E8B0
void __fastcall ESE_INTERCEPT_sub_6FC6E8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile);
//D2Game.0x6FC6E8D0
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FC6E8D0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int32_t nSuperUniqueId, int32_t a5, uint16_t nX, uint16_t nY, int32_t a8);
//D2Game.0x6FC6E940
void __fastcall ESE_INTERCEPT_sub_6FC6E940(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FC6EBE0
D2MonsterDataStrc* __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetMonsterData(D2UnitStrc* pUnit);
//D2Game.0x6FC6EBF0
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetUModCount(uint8_t* pUMods);
//D2Game.0x6FC6EC10
int32_t __fastcall ESE_INTERCEPT_sub_6FC6EC10(D2UnitStrc* pUnit, D2MonUModTxt* pMonUModTxtRecord, int32_t bExpansion);
//D2Game.0x6FC6EE90
int32_t __fastcall ESE_INTERCEPT_sub_6FC6EE90(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t* a3);
//D2Game.0x6FC6F160
uint32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CheckMonModeFlag(int32_t nMonsterId, int32_t nFlag);
//D2Game.0x6FC6F1D0
uint32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CheckMonStatsFlag(int32_t nMonsterId, int32_t nFlag);
//D2Game.0x6FC6F220
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SpawnMonster_6FC6F220(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int32_t nX, int32_t nY, int32_t nUnitGUID, int32_t nClassId, int32_t a8);
//D2Game.0x6FC6F440
void __fastcall ESE_INTERCEPT_D2GAME_SpawnMinions_6FC6F440(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int32_t bSpawnMinions, int32_t nMinGroup, int32_t nMaxGroup);
//D2Game.0x6FC6F670
void __fastcall ESE_INTERCEPT_sub_6FC6F670(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6F690
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nSuperUnique);
//D2Game.0x6FC6FBA0
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FC6FBA0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nClassId, int32_t nUnitGUID, uint16_t nNameSeed, int32_t bChampion, int32_t bSuperUnique, int16_t nBossHcIdx, uint8_t* pUMods);
//D2Game.0x6FC6FDC0
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FC6FDC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nClassId, int32_t nUnitGUID, uint8_t* pUMods);
//D2Game.0x6FC6FF10
void __fastcall ESE_INTERCEPT_D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
//D2Game.0x6FC6FFD0
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_Unk_6FC6FFD0(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nUMod);

extern decltype(&MONSTERUNIQUE_ToggleUnitFlag) MONSTERUNIQUE_ToggleUnitFlag_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ToggleUnitFlag(D2UnitStrc* pUnit, int32_t nFlag, int32_t bSet);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_ToggleUnitFlag), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_ToggleUnitFlag)>, "ESE_INTERCEPT_MONSTERUNIQUE_ToggleUnitFlag has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetUMods) MONSTERUNIQUE_GetUMods_Original;
uint8_t* __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetUMods), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetUMods)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetUMods has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetNameSeed) MONSTERUNIQUE_GetNameSeed_Original;
uint16_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetNameSeed), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetNameSeed)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetNameSeed has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CheckMonTypeFlag) MONSTERUNIQUE_CheckMonTypeFlag_Original;
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, uint16_t nFlag);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CheckMonTypeFlag), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CheckMonTypeFlag)>, "ESE_INTERCEPT_MONSTERUNIQUE_CheckMonTypeFlag has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_ToggleMonTypeFlag) MONSTERUNIQUE_ToggleMonTypeFlag_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, uint16_t nFlag, int32_t bSet);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_ToggleMonTypeFlag), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_ToggleMonTypeFlag)>, "ESE_INTERCEPT_MONSTERUNIQUE_ToggleMonTypeFlag has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetBossHcIdx) MONSTERUNIQUE_GetBossHcIdx_Original;
int16_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetBossHcIdx), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetBossHcIdx)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetBossHcIdx has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_HasUMods) MONSTERUNIQUE_HasUMods_Original;
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_HasUMods(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_HasUMods), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_HasUMods)>, "ESE_INTERCEPT_MONSTERUNIQUE_HasUMods has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetSuperUniqueBossHcIdx) MONSTERUNIQUE_GetSuperUniqueBossHcIdx_Original;
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetSuperUniqueBossHcIdx), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetSuperUniqueBossHcIdx)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetSuperUniqueBossHcIdx has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod1_RandomName) MONSTERUNIQUE_UMod1_RandomName_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod1_RandomName(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod1_RandomName), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod1_RandomName)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod1_RandomName has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod2_HealthBonus) MONSTERUNIQUE_UMod2_HealthBonus_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod2_HealthBonus(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod2_HealthBonus), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod2_HealthBonus)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod2_HealthBonus has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CalculatePercentage) MONSTERUNIQUE_CalculatePercentage_Original;
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage(int32_t a1, int32_t a2, int32_t a3);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CalculatePercentage), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage)>, "ESE_INTERCEPT_MONSTERUNIQUE_CalculatePercentage has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod4_LevelBonus) MONSTERUNIQUE_UMod4_LevelBonus_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod4_LevelBonus(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod4_LevelBonus), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod4_LevelBonus)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod4_LevelBonus has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod16_Champion) MONSTERUNIQUE_UMod16_Champion_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod16_Champion), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod16_Champion has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod36_Ghostly) MONSTERUNIQUE_UMod36_Ghostly_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod36_Ghostly), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod36_Ghostly has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod37_Fanatic) MONSTERUNIQUE_UMod37_Fanatic_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod37_Fanatic(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod37_Fanatic), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod37_Fanatic)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod37_Fanatic has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod38_Possessed) MONSTERUNIQUE_UMod38_Possessed_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod38_Possessed(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod38_Possessed), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod38_Possessed)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod38_Possessed has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod39_Berserk) MONSTERUNIQUE_UMod39_Berserk_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod39_Berserk), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod39_Berserk has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod41_AlwaysRun) MONSTERUNIQUE_UMod41_AlwaysRun_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod41_AlwaysRun(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod41_AlwaysRun), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod41_AlwaysRun)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod41_AlwaysRun has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod8_Resistant) MONSTERUNIQUE_UMod8_Resistant_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod8_Resistant), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod8_Resistant has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod26_Teleport) MONSTERUNIQUE_UMod26_Teleport_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod26_Teleport(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod26_Teleport), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod26_Teleport)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod26_Teleport has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod30_AuraEnchanted) MONSTERUNIQUE_UMod30_AuraEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod30_AuraEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod30_AuraEnchanted), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod30_AuraEnchanted)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod30_AuraEnchanted has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod5_Strong) MONSTERUNIQUE_UMod5_Strong_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod5_Strong), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod5_Strong has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod6_Fast) MONSTERUNIQUE_UMod6_Fast_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod6_Fast(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod6_Fast), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod6_Fast)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod6_Fast has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod9_FireEnchanted) MONSTERUNIQUE_UMod9_FireEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod9_FireEnchanted), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod9_FireEnchanted has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod17_LightningEnchanted) MONSTERUNIQUE_UMod17_LightningEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod17_LightningEnchanted), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod17_LightningEnchanted has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod18_ColdEnchanted) MONSTERUNIQUE_UMod18_ColdEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod18_ColdEnchanted), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod18_ColdEnchanted has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod23_PoisonEnchanted) MONSTERUNIQUE_UMod23_PoisonEnchanted_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod23_PoisonEnchanted), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod23_PoisonEnchanted has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_UMod25_ManaSteal) MONSTERUNIQUE_UMod25_ManaSteal_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_UMod25_ManaSteal), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal)>, "ESE_INTERCEPT_MONSTERUNIQUE_UMod25_ManaSteal has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastAmplifyDamage) MONSTERUNIQUE_CastAmplifyDamage_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t a4);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastAmplifyDamage), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastAmplifyDamage)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastAmplifyDamage has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage) MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillLevel);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage)>, "ESE_INTERCEPT_MONSTERUNIQUE_CurseCallback_ApplyAmplifyDamage has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_FireEnchantedModeChange) MONSTERUNIQUE_FireEnchantedModeChange_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_FireEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_FireEnchantedModeChange), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_FireEnchantedModeChange)>, "ESE_INTERCEPT_MONSTERUNIQUE_FireEnchantedModeChange has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastCorpseExplode) MONSTERUNIQUE_CastCorpseExplode_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastCorpseExplode), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastCorpseExplode2) MONSTERUNIQUE_CastCorpseExplode2_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastCorpseExplode2), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastCorpseExplode2 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastNova) MONSTERUNIQUE_CastNova_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastNova(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastNova), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastNova)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastNova has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastLightUniqueMissile) MONSTERUNIQUE_CastLightUniqueMissile_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastLightUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastLightUniqueMissile), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastLightUniqueMissile)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastLightUniqueMissile has a different type than previously known.");

extern decltype(&sub_6FC6CD30) sub_6FC6CD30_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6CD30(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6CD30), decltype(&ESE_INTERCEPT_sub_6FC6CD30)>, "ESE_INTERCEPT_sub_6FC6CD30 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastColdUniqueMissile) MONSTERUNIQUE_CastColdUniqueMissile_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastColdUniqueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastColdUniqueMissile), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastColdUniqueMissile)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastColdUniqueMissile has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastCorpsePoisonCloud) MONSTERUNIQUE_CastCorpsePoisonCloud_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastCorpsePoisonCloud(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastCorpsePoisonCloud), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastCorpsePoisonCloud)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastCorpsePoisonCloud has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_KillMinions) MONSTERUNIQUE_KillMinions_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_KillMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_KillMinions), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_KillMinions)>, "ESE_INTERCEPT_MONSTERUNIQUE_KillMinions has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_MinionCallback_KillMinion) MONSTERUNIQUE_MinionCallback_KillMinion_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_MinionCallback_KillMinion(D2UnitStrc* pUnit, void* pGameArg, void* pUnused);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_MinionCallback_KillMinion), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_MinionCallback_KillMinion)>, "ESE_INTERCEPT_MONSTERUNIQUE_MinionCallback_KillMinion has a different type than previously known.");

extern decltype(&sub_6FC6CF10) sub_6FC6CF10_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6CF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6CF10), decltype(&ESE_INTERCEPT_sub_6FC6CF10)>, "ESE_INTERCEPT_sub_6FC6CF10 has a different type than previously known.");

extern decltype(&sub_6FC6CF90) sub_6FC6CF90_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6CF90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6CF90), decltype(&ESE_INTERCEPT_sub_6FC6CF90)>, "ESE_INTERCEPT_sub_6FC6CF90 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_ScarabModeChange) MONSTERUNIQUE_ScarabModeChange_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ScarabModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_ScarabModeChange), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_ScarabModeChange)>, "ESE_INTERCEPT_MONSTERUNIQUE_ScarabModeChange has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastBugLightningMissile) MONSTERUNIQUE_CastBugLightningMissile_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastBugLightningMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastBugLightningMissile), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastBugLightningMissile)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastBugLightningMissile has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_ApplyElementalDamage) MONSTERUNIQUE_ApplyElementalDamage_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_ApplyElementalDamage), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage)>, "ESE_INTERCEPT_MONSTERUNIQUE_ApplyElementalDamage has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetMonUModTxtRecord) MONSTERUNIQUE_GetMonUModTxtRecord_Original;
D2MonUModTxt* __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetMonUModTxtRecord(uint32_t nUMod);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetMonUModTxtRecord), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetMonUModTxtRecord)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetMonUModTxtRecord has a different type than previously known.");

extern decltype(&sub_6FC6D440) sub_6FC6D440_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6D440(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6D440), decltype(&ESE_INTERCEPT_sub_6FC6D440)>, "ESE_INTERCEPT_sub_6FC6D440 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_StealBeltItem) MONSTERUNIQUE_StealBeltItem_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_StealBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_StealBeltItem), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_StealBeltItem)>, "ESE_INTERCEPT_MONSTERUNIQUE_StealBeltItem has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_QuestCompleteModeChange) MONSTERUNIQUE_QuestCompleteModeChange_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_QuestCompleteModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_QuestCompleteModeChange), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_QuestCompleteModeChange)>, "ESE_INTERCEPT_MONSTERUNIQUE_QuestCompleteModeChange has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastQueenPoisonCloudMissile) MONSTERUNIQUE_CastQueenPoisonCloudMissile_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastQueenPoisonCloudMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastQueenPoisonCloudMissile), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastQueenPoisonCloudMissile)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastQueenPoisonCloudMissile has a different type than previously known.");

extern decltype(&sub_6FC6DA40) sub_6FC6DA40_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6DA40(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6DA40), decltype(&ESE_INTERCEPT_sub_6FC6DA40)>, "ESE_INTERCEPT_sub_6FC6DA40 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_LightningEnchantedModeChange) MONSTERUNIQUE_LightningEnchantedModeChange_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_LightningEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_LightningEnchantedModeChange), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_LightningEnchantedModeChange)>, "ESE_INTERCEPT_MONSTERUNIQUE_LightningEnchantedModeChange has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_ColdEnchantedModeChange) MONSTERUNIQUE_ColdEnchantedModeChange_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ColdEnchantedModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_ColdEnchantedModeChange), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_ColdEnchantedModeChange)>, "ESE_INTERCEPT_MONSTERUNIQUE_ColdEnchantedModeChange has a different type than previously known.");

extern decltype(&sub_6FC6DD20) sub_6FC6DD20_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6DD20(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6DD20), decltype(&ESE_INTERCEPT_sub_6FC6DD20)>, "ESE_INTERCEPT_sub_6FC6DD20 has a different type than previously known.");

extern decltype(&sub_6FC6DDE0) sub_6FC6DDE0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6DDE0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6DDE0), decltype(&ESE_INTERCEPT_sub_6FC6DDE0)>, "ESE_INTERCEPT_sub_6FC6DDE0 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_ApplyShatterState) MONSTERUNIQUE_ApplyShatterState_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_ApplyShatterState(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_ApplyShatterState), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_ApplyShatterState)>, "ESE_INTERCEPT_MONSTERUNIQUE_ApplyShatterState has a different type than previously known.");

extern decltype(&sub_6FC6DFC0) sub_6FC6DFC0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6DFC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6DFC0), decltype(&ESE_INTERCEPT_sub_6FC6DFC0)>, "ESE_INTERCEPT_sub_6FC6DFC0 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_SetTrapDamage) MONSTERUNIQUE_SetTrapDamage_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_SetTrapDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_SetTrapDamage), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_SetTrapDamage)>, "ESE_INTERCEPT_MONSTERUNIQUE_SetTrapDamage has a different type than previously known.");

extern decltype(&sub_6FC6E240) sub_6FC6E240_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E240(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6E240), decltype(&ESE_INTERCEPT_sub_6FC6E240)>, "ESE_INTERCEPT_sub_6FC6E240 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_SuicideModeChange) MONSTERUNIQUE_SuicideModeChange_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_SuicideModeChange(D2GameStrc* pGame, D2UnitStrc* pBoss, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_SuicideModeChange), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_SuicideModeChange)>, "ESE_INTERCEPT_MONSTERUNIQUE_SuicideModeChange has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CastSuicideExplodeMissile) MONSTERUNIQUE_CastSuicideExplodeMissile_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CastSuicideExplodeMissile), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile)>, "ESE_INTERCEPT_MONSTERUNIQUE_CastSuicideExplodeMissile has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CreatePainWorm) MONSTERUNIQUE_CreatePainWorm_Original;
void __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CreatePainWorm), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CreatePainWorm)>, "ESE_INTERCEPT_MONSTERUNIQUE_CreatePainWorm has a different type than previously known.");

extern decltype(&sub_6FC6E730) sub_6FC6E730_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E730(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6E730), decltype(&ESE_INTERCEPT_sub_6FC6E730)>, "ESE_INTERCEPT_sub_6FC6E730 has a different type than previously known.");

extern decltype(&sub_6FC6E770) sub_6FC6E770_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E770(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC6E770), decltype(&ESE_INTERCEPT_sub_6FC6E770)>, "ESE_INTERCEPT_sub_6FC6E770 has a different type than previously known.");

extern decltype(&sub_6FC6E780) sub_6FC6E780_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E780(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile, int32_t nIndex);
static_assert(std::is_same_v<decltype(&sub_6FC6E780), decltype(&ESE_INTERCEPT_sub_6FC6E780)>, "ESE_INTERCEPT_sub_6FC6E780 has a different type than previously known.");

extern decltype(&sub_6FC6E860) sub_6FC6E860_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E860(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC6E860), decltype(&ESE_INTERCEPT_sub_6FC6E860)>, "ESE_INTERCEPT_sub_6FC6E860 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_AiFunction08_6FC6E870) D2GAME_MONSTERS_AiFunction08_6FC6E870_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction08_6FC6E870(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_AiFunction08_6FC6E870), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction08_6FC6E870)>, "ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction08_6FC6E870 has a different type than previously known.");

extern decltype(&sub_6FC6E890) sub_6FC6E890_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E890(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC6E890), decltype(&ESE_INTERCEPT_sub_6FC6E890)>, "ESE_INTERCEPT_sub_6FC6E890 has a different type than previously known.");

extern decltype(&sub_6FC6E8A0) sub_6FC6E8A0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E8A0(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FC6E8A0), decltype(&ESE_INTERCEPT_sub_6FC6E8A0)>, "ESE_INTERCEPT_sub_6FC6E8A0 has a different type than previously known.");

extern decltype(&sub_6FC6E8B0) sub_6FC6E8B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile);
static_assert(std::is_same_v<decltype(&sub_6FC6E8B0), decltype(&ESE_INTERCEPT_sub_6FC6E8B0)>, "ESE_INTERCEPT_sub_6FC6E8B0 has a different type than previously known.");

extern decltype(&sub_6FC6E8D0) sub_6FC6E8D0_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FC6E8D0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int32_t nSuperUniqueId, int32_t a5, uint16_t nX, uint16_t nY, int32_t a8);
static_assert(std::is_same_v<decltype(&sub_6FC6E8D0), decltype(&ESE_INTERCEPT_sub_6FC6E8D0)>, "ESE_INTERCEPT_sub_6FC6E8D0 has a different type than previously known.");

extern decltype(&sub_6FC6E940) sub_6FC6E940_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6E940(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
static_assert(std::is_same_v<decltype(&sub_6FC6E940), decltype(&ESE_INTERCEPT_sub_6FC6E940)>, "ESE_INTERCEPT_sub_6FC6E940 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetMonsterData) MONSTERUNIQUE_GetMonsterData_Original;
D2MonsterDataStrc* __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetMonsterData(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetMonsterData), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetMonsterData)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetMonsterData has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_GetUModCount) MONSTERUNIQUE_GetUModCount_Original;
int32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_GetUModCount(uint8_t* pUMods);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_GetUModCount), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_GetUModCount)>, "ESE_INTERCEPT_MONSTERUNIQUE_GetUModCount has a different type than previously known.");

extern decltype(&sub_6FC6EC10) sub_6FC6EC10_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC6EC10(D2UnitStrc* pUnit, D2MonUModTxt* pMonUModTxtRecord, int32_t bExpansion);
static_assert(std::is_same_v<decltype(&sub_6FC6EC10), decltype(&ESE_INTERCEPT_sub_6FC6EC10)>, "ESE_INTERCEPT_sub_6FC6EC10 has a different type than previously known.");

extern decltype(&sub_6FC6EE90) sub_6FC6EE90_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FC6EE90(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t* a3);
static_assert(std::is_same_v<decltype(&sub_6FC6EE90), decltype(&ESE_INTERCEPT_sub_6FC6EE90)>, "ESE_INTERCEPT_sub_6FC6EE90 has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CheckMonModeFlag) MONSTERUNIQUE_CheckMonModeFlag_Original;
uint32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CheckMonModeFlag(int32_t nMonsterId, int32_t nFlag);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CheckMonModeFlag), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CheckMonModeFlag)>, "ESE_INTERCEPT_MONSTERUNIQUE_CheckMonModeFlag has a different type than previously known.");

extern decltype(&MONSTERUNIQUE_CheckMonStatsFlag) MONSTERUNIQUE_CheckMonStatsFlag_Original;
uint32_t __fastcall ESE_INTERCEPT_MONSTERUNIQUE_CheckMonStatsFlag(int32_t nMonsterId, int32_t nFlag);
static_assert(std::is_same_v<decltype(&MONSTERUNIQUE_CheckMonStatsFlag), decltype(&ESE_INTERCEPT_MONSTERUNIQUE_CheckMonStatsFlag)>, "ESE_INTERCEPT_MONSTERUNIQUE_CheckMonStatsFlag has a different type than previously known.");

extern decltype(&D2GAME_SpawnMonster_6FC6F220) D2GAME_SpawnMonster_6FC6F220_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SpawnMonster_6FC6F220(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int32_t nX, int32_t nY, int32_t nUnitGUID, int32_t nClassId, int32_t a8);
static_assert(std::is_same_v<decltype(&D2GAME_SpawnMonster_6FC6F220), decltype(&ESE_INTERCEPT_D2GAME_SpawnMonster_6FC6F220)>, "ESE_INTERCEPT_D2GAME_SpawnMonster_6FC6F220 has a different type than previously known.");

extern decltype(&D2GAME_SpawnMinions_6FC6F440) D2GAME_SpawnMinions_6FC6F440_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SpawnMinions_6FC6F440(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int32_t bSpawnMinions, int32_t nMinGroup, int32_t nMaxGroup);
static_assert(std::is_same_v<decltype(&D2GAME_SpawnMinions_6FC6F440), decltype(&ESE_INTERCEPT_D2GAME_SpawnMinions_6FC6F440)>, "ESE_INTERCEPT_D2GAME_SpawnMinions_6FC6F440 has a different type than previously known.");

extern decltype(&sub_6FC6F670) sub_6FC6F670_Original;
void __fastcall ESE_INTERCEPT_sub_6FC6F670(D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&sub_6FC6F670), decltype(&ESE_INTERCEPT_sub_6FC6F670)>, "ESE_INTERCEPT_sub_6FC6F670 has a different type than previously known.");

extern decltype(&D2GAME_SpawnSuperUnique_6FC6F690) D2GAME_SpawnSuperUnique_6FC6F690_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SpawnSuperUnique_6FC6F690(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nSuperUnique);
static_assert(std::is_same_v<decltype(&D2GAME_SpawnSuperUnique_6FC6F690), decltype(&ESE_INTERCEPT_D2GAME_SpawnSuperUnique_6FC6F690)>, "ESE_INTERCEPT_D2GAME_SpawnSuperUnique_6FC6F690 has a different type than previously known.");

extern decltype(&sub_6FC6FBA0) sub_6FC6FBA0_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FC6FBA0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nClassId, int32_t nUnitGUID, uint16_t nNameSeed, int32_t bChampion, int32_t bSuperUnique, int16_t nBossHcIdx, uint8_t* pUMods);
static_assert(std::is_same_v<decltype(&sub_6FC6FBA0), decltype(&ESE_INTERCEPT_sub_6FC6FBA0)>, "ESE_INTERCEPT_sub_6FC6FBA0 has a different type than previously known.");

extern decltype(&sub_6FC6FDC0) sub_6FC6FDC0_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FC6FDC0(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nClassId, int32_t nUnitGUID, uint8_t* pUMods);
static_assert(std::is_same_v<decltype(&sub_6FC6FDC0), decltype(&ESE_INTERCEPT_sub_6FC6FDC0)>, "ESE_INTERCEPT_sub_6FC6FDC0 has a different type than previously known.");

extern decltype(&D2GAME_BOSSES_AssignUMod_6FC6FF10) D2GAME_BOSSES_AssignUMod_6FC6FF10_Original;
void __fastcall ESE_INTERCEPT_D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nUMod, int32_t bUnique);
static_assert(std::is_same_v<decltype(&D2GAME_BOSSES_AssignUMod_6FC6FF10), decltype(&ESE_INTERCEPT_D2GAME_BOSSES_AssignUMod_6FC6FF10)>, "ESE_INTERCEPT_D2GAME_BOSSES_AssignUMod_6FC6FF10 has a different type than previously known.");

extern decltype(&D2GAME_MONSTERS_Unk_6FC6FFD0) D2GAME_MONSTERS_Unk_6FC6FFD0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_Unk_6FC6FFD0(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nUMod);
static_assert(std::is_same_v<decltype(&D2GAME_MONSTERS_Unk_6FC6FFD0), decltype(&ESE_INTERCEPT_D2GAME_MONSTERS_Unk_6FC6FFD0)>, "ESE_INTERCEPT_D2GAME_MONSTERS_Unk_6FC6FFD0 has a different type than previously known.");

