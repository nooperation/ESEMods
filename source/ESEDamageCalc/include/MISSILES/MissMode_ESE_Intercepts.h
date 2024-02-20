#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <UNIT/SUnitDmg_ESE.h>

#include <MISSILES/MissMode_ESE.h>

//D2Game.0x6FC55CE0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithMonster(D2UnitStrc* pUnit, void* pArgument);
//D2Game.0x6FC55D90
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, void* pArgument);
//D2Game.0x6FC55E60
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument);
//D2Game.0x6FC55F20
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanMissileDestroy(D2UnitStrc* pUnit, void* pArgument);
//D2Game.0x6FC55F80
void __stdcall ESE_INTERCEPT_MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage);
//D2Game.0x6FC56290
int32_t __fastcall ESE_INTERCEPT_MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat);
//D2Game.0x6FC56480
int32_t __fastcall ESE_INTERCEPT_MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);
//D2Game.0x6FC56730
void __fastcall ESE_INTERCEPT_MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage);
//D2Game.0x6FC567E0
void __fastcall ESE_INTERCEPT_MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nDamage);
//D2Game.0x6FC568F0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nSubStep, int32_t nMainStep, int32_t nLoops);
//D2Game.0x6FC56AB0
void __fastcall ESE_INTERCEPT_MISSMODE_CreateImmolationArrowHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nMissileId, int32_t nRange);
//D2Game.0x6FC56D50
int32_t __fastcall ESE_INTERCEPT_MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC56FA0
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nRange, int32_t nLoops);
//D2Game.0x6FC570B0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57140
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC571D0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC573B0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57510
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57640
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo08_MonBlizzCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC576F0
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreateMissileWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pMissile, int32_t nRange, int32_t nFrames, int32_t nMissileId, uint16_t nCollisionMask);
//D2Game.0x6FC57910
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo09_BatLightningBolt(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57A40
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo10_BlizzardCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57B60
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo11_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57DA0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo12_DiabWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC57F00
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo13_BoneWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58140
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo14_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC581F0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo15_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58340
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo16_FrozenOrbNova(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58480
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo17_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC585E0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo18_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58860
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58940
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo21_Distraction(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58B00
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo22_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58CC0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58E10
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo25_EruptionCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC58F30
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo26_Vines_PlagueVines(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC59040
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo27_Tornado(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC591C0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo28_Volcano(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC594B0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC596C0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC598D0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo30_RabiesPlague(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC59B90
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC59CB0
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo32_TigerFury(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FC59D80
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo34_BaalTauntControl(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_UnitFindCallback_CanCollideWithMonster) MISSMODE_UnitFindCallback_CanCollideWithMonster_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithMonster(D2UnitStrc* pUnit, void* pArgument);

extern decltype(&MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit) MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, void* pArgument);

extern decltype(&MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster) MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument);

extern decltype(&MISSMODE_UnitFindCallback_CanMissileDestroy) MISSMODE_UnitFindCallback_CanMissileDestroy_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanMissileDestroy(D2UnitStrc* pUnit, void* pArgument);

extern decltype(&MISSMODE_FillDamageParams) MISSMODE_FillDamageParams_Original;
void __stdcall ESE_INTERCEPT_MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage);

extern decltype(&MISSMODE_RollDamageValue) MISSMODE_RollDamageValue_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat);

extern decltype(&MISSMODE_GetDamageValue) MISSMODE_GetDamageValue_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);

extern decltype(&MISSMODE_ResetDamageParams) MISSMODE_ResetDamageParams_Original;
void __fastcall ESE_INTERCEPT_MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

extern decltype(&MISSMODE_AddDamageValue) MISSMODE_AddDamageValue_Original;
void __fastcall ESE_INTERCEPT_MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nDamage);

extern decltype(&MISSMODE_CreatePoisonCloudHitSubmissiles) MISSMODE_CreatePoisonCloudHitSubmissiles_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nSubStep, int32_t nMainStep, int32_t nLoops);

extern decltype(&MISSMODE_CreateImmolationArrowHitSubmissiles) MISSMODE_CreateImmolationArrowHitSubmissiles_Original;
void __fastcall ESE_INTERCEPT_MISSMODE_CreateImmolationArrowHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nMissileId, int32_t nRange);

extern decltype(&MISSMODE_HandleMissileCollision) MISSMODE_HandleMissileCollision_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles) MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nRange, int32_t nLoops);

extern decltype(&MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap) MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod) MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath) MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker) MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo07_GuidedArrow_BoneSpirit) MISSMODE_SrvDo07_GuidedArrow_BoneSpirit_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo08_MonBlizzCenter) MISSMODE_SrvDo08_MonBlizzCenter_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo08_MonBlizzCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_CreateMissileWithCollisionCheck) MISSMODE_CreateMissileWithCollisionCheck_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreateMissileWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pMissile, int32_t nRange, int32_t nFrames, int32_t nMissileId, uint16_t nCollisionMask);

extern decltype(&MISSMODE_SrvDo09_BatLightningBolt) MISSMODE_SrvDo09_BatLightningBolt_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo09_BatLightningBolt(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo10_BlizzardCenter) MISSMODE_SrvDo10_BlizzardCenter_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo10_BlizzardCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo11_FingerMageSpider) MISSMODE_SrvDo11_FingerMageSpider_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo11_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo12_DiabWallMaker) MISSMODE_SrvDo12_DiabWallMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo12_DiabWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo13_BoneWallMaker) MISSMODE_SrvDo13_BoneWallMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo13_BoneWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo14_GrimWard) MISSMODE_SrvDo14_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo14_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo15_FrozenOrb) MISSMODE_SrvDo15_FrozenOrb_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo15_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo16_FrozenOrbNova) MISSMODE_SrvDo16_FrozenOrbNova_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo16_FrozenOrbNova(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo17_CairnStones) MISSMODE_SrvDo17_CairnStones_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo17_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo18_TowerChestSpawner) MISSMODE_SrvDo18_TowerChestSpawner_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo18_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo20_BladeCreeper) MISSMODE_SrvDo20_BladeCreeper_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo21_Distraction) MISSMODE_SrvDo21_Distraction_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo21_Distraction(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo22_LightningTrailingJavelin) MISSMODE_SrvDo22_LightningTrailingJavelin_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo22_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker) MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo25_EruptionCenter) MISSMODE_SrvDo25_EruptionCenter_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo25_EruptionCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo26_Vines_PlagueVines) MISSMODE_SrvDo26_Vines_PlagueVines_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo26_Vines_PlagueVines(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo27_Tornado) MISSMODE_SrvDo27_Tornado_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo27_Tornado(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo28_Volcano) MISSMODE_SrvDo28_Volcano_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo28_Volcano(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo29_RecyclerDelay) MISSMODE_SrvDo29_RecyclerDelay_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo33_VineRecyclerDelay) MISSMODE_SrvDo33_VineRecyclerDelay_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo30_RabiesPlague) MISSMODE_SrvDo30_RabiesPlague_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo30_RabiesPlague(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker) MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo32_TigerFury) MISSMODE_SrvDo32_TigerFury_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo32_TigerFury(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern decltype(&MISSMODE_SrvDo34_BaalTauntControl) MISSMODE_SrvDo34_BaalTauntControl_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo34_BaalTauntControl(D2GameStrc* pGame, D2UnitStrc* pMissile);

