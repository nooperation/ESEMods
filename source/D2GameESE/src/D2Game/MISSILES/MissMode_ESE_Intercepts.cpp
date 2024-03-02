#include "D2Game/MISSILES/MissMode_ESE_Intercepts.h"

MISSMODE_FillDamageParams_t MISSMODE_FillDamageParams_Original = nullptr;
MISSMODE_RollDamageValue_t MISSMODE_RollDamageValue_Original = nullptr;
MISSMODE_GetDamageValue_t MISSMODE_GetDamageValue_Original = nullptr;
MISSMODE_ResetDamageParams_t MISSMODE_ResetDamageParams_Original = nullptr;
MISSMODE_AddDamageValue_t MISSMODE_AddDamageValue_Original = nullptr;
MISSMODE_CreatePoisonCloudHitSubmissiles_t MISSMODE_CreatePoisonCloudHitSubmissiles_Original = nullptr;
MISSMODE_CreateImmolationArrowHitSubmissiles_t MISSMODE_CreateImmolationArrowHitSubmissiles_Original = nullptr;
MISSMODE_HandleMissileCollision_t MISSMODE_HandleMissileCollision_Original = nullptr;
MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles_t MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles_Original = nullptr;
MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap_t MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap_Original = nullptr;
MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod_t MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod_Original = nullptr;
MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath_t MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath_Original = nullptr;
MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker_t MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker_Original = nullptr;
MISSMODE_SrvDo07_GuidedArrow_BoneSpirit_t MISSMODE_SrvDo07_GuidedArrow_BoneSpirit_Original = nullptr;
MISSMODE_SrvDo08_MonBlizzCenter_t MISSMODE_SrvDo08_MonBlizzCenter_Original = nullptr;
MISSMODE_CreateMissileWithCollisionCheck_t MISSMODE_CreateMissileWithCollisionCheck_Original = nullptr;
MISSMODE_SrvDo09_BatLightningBolt_t MISSMODE_SrvDo09_BatLightningBolt_Original = nullptr;
MISSMODE_SrvDo10_BlizzardCenter_t MISSMODE_SrvDo10_BlizzardCenter_Original = nullptr;
MISSMODE_SrvDo11_FingerMageSpider_t MISSMODE_SrvDo11_FingerMageSpider_Original = nullptr;
MISSMODE_SrvDo12_DiabWallMaker_t MISSMODE_SrvDo12_DiabWallMaker_Original = nullptr;
MISSMODE_SrvDo13_BoneWallMaker_t MISSMODE_SrvDo13_BoneWallMaker_Original = nullptr;
MISSMODE_SrvDo14_GrimWard_t MISSMODE_SrvDo14_GrimWard_Original = nullptr;
MISSMODE_SrvDo15_FrozenOrb_t MISSMODE_SrvDo15_FrozenOrb_Original = nullptr;
MISSMODE_SrvDo16_FrozenOrbNova_t MISSMODE_SrvDo16_FrozenOrbNova_Original = nullptr;
MISSMODE_SrvDo17_CairnStones_t MISSMODE_SrvDo17_CairnStones_Original = nullptr;
MISSMODE_SrvDo18_TowerChestSpawner_t MISSMODE_SrvDo18_TowerChestSpawner_Original = nullptr;
MISSMODE_SrvDo20_BladeCreeper_t MISSMODE_SrvDo20_BladeCreeper_Original = nullptr;
MISSMODE_SrvDo21_Distraction_t MISSMODE_SrvDo21_Distraction_Original = nullptr;
MISSMODE_SrvDo22_LightningTrailingJavelin_t MISSMODE_SrvDo22_LightningTrailingJavelin_Original = nullptr;
MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker_t MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker_Original = nullptr;
MISSMODE_SrvDo25_EruptionCenter_t MISSMODE_SrvDo25_EruptionCenter_Original = nullptr;
MISSMODE_SrvDo26_Vines_PlagueVines_t MISSMODE_SrvDo26_Vines_PlagueVines_Original = nullptr;
MISSMODE_SrvDo27_Tornado_t MISSMODE_SrvDo27_Tornado_Original = nullptr;
MISSMODE_SrvDo28_Volcano_t MISSMODE_SrvDo28_Volcano_Original = nullptr;
MISSMODE_SrvDo29_RecyclerDelay_t MISSMODE_SrvDo29_RecyclerDelay_Original = nullptr;
MISSMODE_SrvDo33_VineRecyclerDelay_t MISSMODE_SrvDo33_VineRecyclerDelay_Original = nullptr;
MISSMODE_SrvDo30_RabiesPlague_t MISSMODE_SrvDo30_RabiesPlague_Original = nullptr;
MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker_t MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker_Original = nullptr;
MISSMODE_SrvDo32_TigerFury_t MISSMODE_SrvDo32_TigerFury_Original = nullptr;
MISSMODE_SrvDo34_BaalTauntControl_t MISSMODE_SrvDo34_BaalTauntControl_Original = nullptr;

void __stdcall ESE_INTERCEPT_MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);

    ESE_MISSMODE_FillDamageParams(pMissile, pTarget, &tempDamageStrc);

    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int32_t nMinDamStat, int32_t nMaxDamStat, int32_t nMasteryStat)
{
    return ESE_MISSMODE_RollDamageValue(pUnit, nMinDamStat, nMaxDamStat, nMasteryStat);
}

int32_t __fastcall ESE_INTERCEPT_MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    return ESE_MISSMODE_GetDamageValue(pGame, pAttacker, pDefender, &tempDamageStrc);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

void __fastcall ESE_INTERCEPT_MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_MISSMODE_ResetDamageParams(pGame, pUnit, &tempDamageStrc);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
}

void __fastcall ESE_INTERCEPT_MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nDamage)
{
    ESE_D2DamageStrc tempDamageStrc(pDamage);
    ESE_MISSMODE_AddDamageValue(pGame, pMissile, pUnit, &tempDamageStrc, nDamage);
    tempDamageStrc.WriteToOriginalStruct(pDamage);
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


