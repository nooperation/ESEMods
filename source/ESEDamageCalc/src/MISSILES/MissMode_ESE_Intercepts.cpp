#include <MISSILES/MissMode_ESE_Intercepts.h>

decltype(&MISSMODE_UnitFindCallback_CanCollideWithMonster) MISSMODE_UnitFindCallback_CanCollideWithMonster_Original = nullptr;
decltype(&MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit) MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit_Original = nullptr;
decltype(&MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster) MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster_Original = nullptr;
decltype(&MISSMODE_UnitFindCallback_CanMissileDestroy) MISSMODE_UnitFindCallback_CanMissileDestroy_Original = nullptr;
decltype(&MISSMODE_FillDamageParams) MISSMODE_FillDamageParams_Original = nullptr;
decltype(&MISSMODE_RollDamageValue) MISSMODE_RollDamageValue_Original = nullptr;
decltype(&MISSMODE_GetDamageValue) MISSMODE_GetDamageValue_Original = nullptr;
decltype(&MISSMODE_ResetDamageParams) MISSMODE_ResetDamageParams_Original = nullptr;
decltype(&MISSMODE_AddDamageValue) MISSMODE_AddDamageValue_Original = nullptr;
decltype(&MISSMODE_CreatePoisonCloudHitSubmissiles) MISSMODE_CreatePoisonCloudHitSubmissiles_Original = nullptr;
decltype(&MISSMODE_CreateImmolationArrowHitSubmissiles) MISSMODE_CreateImmolationArrowHitSubmissiles_Original = nullptr;
decltype(&MISSMODE_HandleMissileCollision) MISSMODE_HandleMissileCollision_Original = nullptr;
decltype(&MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles) MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles_Original = nullptr;
decltype(&MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap) MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap_Original = nullptr;
decltype(&MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod) MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod_Original = nullptr;
decltype(&MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath) MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath_Original = nullptr;
decltype(&MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker) MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker_Original = nullptr;
decltype(&MISSMODE_SrvDo07_GuidedArrow_BoneSpirit) MISSMODE_SrvDo07_GuidedArrow_BoneSpirit_Original = nullptr;
decltype(&MISSMODE_SrvDo08_MonBlizzCenter) MISSMODE_SrvDo08_MonBlizzCenter_Original = nullptr;
decltype(&MISSMODE_CreateMissileWithCollisionCheck) MISSMODE_CreateMissileWithCollisionCheck_Original = nullptr;
decltype(&MISSMODE_SrvDo09_BatLightningBolt) MISSMODE_SrvDo09_BatLightningBolt_Original = nullptr;
decltype(&MISSMODE_SrvDo10_BlizzardCenter) MISSMODE_SrvDo10_BlizzardCenter_Original = nullptr;
decltype(&MISSMODE_SrvDo11_FingerMageSpider) MISSMODE_SrvDo11_FingerMageSpider_Original = nullptr;
decltype(&MISSMODE_SrvDo12_DiabWallMaker) MISSMODE_SrvDo12_DiabWallMaker_Original = nullptr;
decltype(&MISSMODE_SrvDo13_BoneWallMaker) MISSMODE_SrvDo13_BoneWallMaker_Original = nullptr;
decltype(&MISSMODE_SrvDo14_GrimWard) MISSMODE_SrvDo14_GrimWard_Original = nullptr;
decltype(&MISSMODE_SrvDo15_FrozenOrb) MISSMODE_SrvDo15_FrozenOrb_Original = nullptr;
decltype(&MISSMODE_SrvDo16_FrozenOrbNova) MISSMODE_SrvDo16_FrozenOrbNova_Original = nullptr;
decltype(&MISSMODE_SrvDo17_CairnStones) MISSMODE_SrvDo17_CairnStones_Original = nullptr;
decltype(&MISSMODE_SrvDo18_TowerChestSpawner) MISSMODE_SrvDo18_TowerChestSpawner_Original = nullptr;
decltype(&MISSMODE_SrvDo20_BladeCreeper) MISSMODE_SrvDo20_BladeCreeper_Original = nullptr;
decltype(&MISSMODE_SrvDo21_Distraction) MISSMODE_SrvDo21_Distraction_Original = nullptr;
decltype(&MISSMODE_SrvDo22_LightningTrailingJavelin) MISSMODE_SrvDo22_LightningTrailingJavelin_Original = nullptr;
decltype(&MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker) MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker_Original = nullptr;
decltype(&MISSMODE_SrvDo25_EruptionCenter) MISSMODE_SrvDo25_EruptionCenter_Original = nullptr;
decltype(&MISSMODE_SrvDo26_Vines_PlagueVines) MISSMODE_SrvDo26_Vines_PlagueVines_Original = nullptr;
decltype(&MISSMODE_SrvDo27_Tornado) MISSMODE_SrvDo27_Tornado_Original = nullptr;
decltype(&MISSMODE_SrvDo28_Volcano) MISSMODE_SrvDo28_Volcano_Original = nullptr;
decltype(&MISSMODE_SrvDo29_RecyclerDelay) MISSMODE_SrvDo29_RecyclerDelay_Original = nullptr;
decltype(&MISSMODE_SrvDo33_VineRecyclerDelay) MISSMODE_SrvDo33_VineRecyclerDelay_Original = nullptr;
decltype(&MISSMODE_SrvDo30_RabiesPlague) MISSMODE_SrvDo30_RabiesPlague_Original = nullptr;
decltype(&MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker) MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker_Original = nullptr;
decltype(&MISSMODE_SrvDo32_TigerFury) MISSMODE_SrvDo32_TigerFury_Original = nullptr;
decltype(&MISSMODE_SrvDo34_BaalTauntControl) MISSMODE_SrvDo34_BaalTauntControl_Original = nullptr;

int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithMonster(D2UnitStrc* pUnit, void* pArgument)
{
    return ESE_MISSMODE_UnitFindCallback_CanCollideWithMonster(pUnit, pArgument);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, void* pArgument)
{
    return ESE_MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(pUnit, pArgument);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument)
{
    return ESE_MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(pUnit, pArgument);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_UnitFindCallback_CanMissileDestroy(D2UnitStrc* pUnit, void* pArgument)
{
    return ESE_MISSMODE_UnitFindCallback_CanMissileDestroy(pUnit, pArgument);
}

void __stdcall ESE_INTERCEPT_MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage)
{
    ESE_MISSMODE_FillDamageParams(pMissile, pTarget, pDamage);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat)
{
    return ESE_MISSMODE_RollDamageValue(pUnit, nMinDamStat, nMaxDamStat, nMasteryStat);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    return ESE_MISSMODE_GetDamageValue(pGame, pAttacker, pDefender, pDamage);
}

void __fastcall ESE_INTERCEPT_MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_MISSMODE_ResetDamageParams(pGame, pUnit, pDamage);
}

void __fastcall ESE_INTERCEPT_MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nDamage)
{
    ESE_MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamage);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nSubStep, int32_t nMainStep, int32_t nLoops)
{
    return ESE_MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, pOwner, pOrigin, nMissileId, nSkillId, nSkillLevel, nSubStep, nMainStep, nLoops);
}

void __fastcall ESE_INTERCEPT_MISSMODE_CreateImmolationArrowHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nMissileId, int32_t nRange)
{
    ESE_MISSMODE_CreateImmolationArrowHitSubmissiles(pGame, pUnit, a3, nMissileId, nRange);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_HandleMissileCollision(pGame, pMissile);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int32_t nMissileId, int32_t nRange, int32_t nLoops)
{
    return ESE_MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(pGame, pOrigin, nMissileId, nRange, nLoops);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo08_MonBlizzCenter(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo08_MonBlizzCenter(pGame, pMissile);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_MISSMODE_CreateMissileWithCollisionCheck(D2GameStrc* pGame, D2UnitStrc* pMissile, int32_t nRange, int32_t nFrames, int32_t nMissileId, uint16_t nCollisionMask)
{
    return ESE_MISSMODE_CreateMissileWithCollisionCheck(pGame, pMissile, nRange, nFrames, nMissileId, nCollisionMask);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo09_BatLightningBolt(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo09_BatLightningBolt(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo10_BlizzardCenter(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo10_BlizzardCenter(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo11_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo11_FingerMageSpider(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo12_DiabWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo12_DiabWallMaker(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo13_BoneWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo13_BoneWallMaker(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo14_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo14_GrimWard(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo15_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo15_FrozenOrb(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo16_FrozenOrbNova(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo16_FrozenOrbNova(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo17_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo17_CairnStones(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo18_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo18_TowerChestSpawner(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo20_BladeCreeper(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo21_Distraction(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo21_Distraction(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo22_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo22_LightningTrailingJavelin(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo25_EruptionCenter(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo25_EruptionCenter(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo26_Vines_PlagueVines(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo26_Vines_PlagueVines(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo27_Tornado(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo27_Tornado(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo28_Volcano(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo28_Volcano(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo29_RecyclerDelay(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo33_VineRecyclerDelay(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo30_RabiesPlague(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo30_RabiesPlague(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo32_TigerFury(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo32_TigerFury(pGame, pMissile);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_SrvDo34_BaalTauntControl(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_MISSMODE_SrvDo34_BaalTauntControl(pGame, pMissile);
}


