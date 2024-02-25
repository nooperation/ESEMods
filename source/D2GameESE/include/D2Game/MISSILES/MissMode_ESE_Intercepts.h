#pragma once

#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>

#include <D2Game/UNIT/SUnitDmg_ESE.h>
#include <D2Game/MISSILES/MissMode_ESE.h>

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

extern MISSMODE_UnitFindCallback_CanCollideWithMonster_t MISSMODE_UnitFindCallback_CanCollideWithMonster_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithMonster(D2UnitStrc* pUnit, void* pArgument);

extern MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit_t MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, void* pArgument);

extern MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster_t MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument);

extern MISSMODE_UnitFindCallback_CanMissileDestroy_t MISSMODE_UnitFindCallback_CanMissileDestroy_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanMissileDestroy(D2UnitStrc* pUnit, void* pArgument);

extern MISSMODE_FillDamageParams_t MISSMODE_FillDamageParams_Original;
void __stdcall ESE_INTERCEPT_MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage);

extern MISSMODE_RollDamageValue_t MISSMODE_RollDamageValue_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat);

extern MISSMODE_GetDamageValue_t MISSMODE_GetDamageValue_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage);

extern MISSMODE_ResetDamageParams_t MISSMODE_ResetDamageParams_Original;
void __fastcall ESE_INTERCEPT_MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

extern MISSMODE_AddDamageValue_t MISSMODE_AddDamageValue_Original;
void __fastcall ESE_INTERCEPT_MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nDamage);

extern MISSMODE_CreatePoisonCloudHitSubmissiles_t MISSMODE_CreatePoisonCloudHitSubmissiles_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nSubStep, int32_t nMainStep, int32_t nLoops);

extern MISSMODE_CreateImmolationArrowHitSubmissiles_t MISSMODE_CreateImmolationArrowHitSubmissiles_Original;
void __fastcall ESE_INTERCEPT_MISSMODE_CreateImmolationArrowHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nMissileId, int32_t nRange);

extern MISSMODE_HandleMissileCollision_t MISSMODE_HandleMissileCollision_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles_t MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nRange, int32_t nLoops);

extern MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap_t MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod_t MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath_t MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker_t MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo07_GuidedArrow_BoneSpirit_t MISSMODE_SrvDo07_GuidedArrow_BoneSpirit_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo08_MonBlizzCenter_t MISSMODE_SrvDo08_MonBlizzCenter_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo08_MonBlizzCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_CreateMissileWithCollisionCheck_t MISSMODE_CreateMissileWithCollisionCheck_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreateMissileWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pMissile, int32_t nRange, int32_t nFrames, int32_t nMissileId, uint16_t nCollisionMask);

extern MISSMODE_SrvDo09_BatLightningBolt_t MISSMODE_SrvDo09_BatLightningBolt_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo09_BatLightningBolt(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo10_BlizzardCenter_t MISSMODE_SrvDo10_BlizzardCenter_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo10_BlizzardCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo11_FingerMageSpider_t MISSMODE_SrvDo11_FingerMageSpider_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo11_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo12_DiabWallMaker_t MISSMODE_SrvDo12_DiabWallMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo12_DiabWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo13_BoneWallMaker_t MISSMODE_SrvDo13_BoneWallMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo13_BoneWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo14_GrimWard_t MISSMODE_SrvDo14_GrimWard_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo14_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo15_FrozenOrb_t MISSMODE_SrvDo15_FrozenOrb_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo15_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo16_FrozenOrbNova_t MISSMODE_SrvDo16_FrozenOrbNova_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo16_FrozenOrbNova(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo17_CairnStones_t MISSMODE_SrvDo17_CairnStones_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo17_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo18_TowerChestSpawner_t MISSMODE_SrvDo18_TowerChestSpawner_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo18_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo20_BladeCreeper_t MISSMODE_SrvDo20_BladeCreeper_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo21_Distraction_t MISSMODE_SrvDo21_Distraction_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo21_Distraction(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo22_LightningTrailingJavelin_t MISSMODE_SrvDo22_LightningTrailingJavelin_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo22_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker_t MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo25_EruptionCenter_t MISSMODE_SrvDo25_EruptionCenter_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo25_EruptionCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo26_Vines_PlagueVines_t MISSMODE_SrvDo26_Vines_PlagueVines_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo26_Vines_PlagueVines(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo27_Tornado_t MISSMODE_SrvDo27_Tornado_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo27_Tornado(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo28_Volcano_t MISSMODE_SrvDo28_Volcano_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo28_Volcano(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo29_RecyclerDelay_t MISSMODE_SrvDo29_RecyclerDelay_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo33_VineRecyclerDelay_t MISSMODE_SrvDo33_VineRecyclerDelay_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo30_RabiesPlague_t MISSMODE_SrvDo30_RabiesPlague_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo30_RabiesPlague(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker_t MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo32_TigerFury_t MISSMODE_SrvDo32_TigerFury_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo32_TigerFury(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern MISSMODE_SrvDo34_BaalTauntControl_t MISSMODE_SrvDo34_BaalTauntControl_Original;
int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo34_BaalTauntControl(D2GameStrc* pGame, D2UnitStrc* pMissile);

