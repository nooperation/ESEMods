#include <UNIT/SUnit_ESE_Intercepts.h>

decltype(&SUNIT_RemoveUnit) SUNIT_RemoveUnit_Original = nullptr;
decltype(&SUNIT_GetNextUnitFromList) SUNIT_GetNextUnitFromList_Original = nullptr;
decltype(&sub_6FCBB190) sub_6FCBB190_Original = nullptr;
decltype(&SUNIT_WarpPlayer) SUNIT_WarpPlayer_Original = nullptr;
decltype(&SUNIT_InitSeed) SUNIT_InitSeed_Original = nullptr;
decltype(&SUNIT_AllocUnitData) SUNIT_AllocUnitData_Original = nullptr;
decltype(&SUNIT_GetServerUnit) SUNIT_GetServerUnit_Original = nullptr;
decltype(&SUNIT_GetOwner) SUNIT_GetOwner_Original = nullptr;
decltype(&SUNIT_GetLastAttacker) SUNIT_GetLastAttacker_Original = nullptr;
decltype(&SUNIT_Add) SUNIT_Add_Original = nullptr;
decltype(&SUNIT_Restore) SUNIT_Restore_Original = nullptr;
decltype(&SUNIT_InitClientInPlayerData) SUNIT_InitClientInPlayerData_Original = nullptr;
decltype(&SUNIT_GetClientFromPlayer) SUNIT_GetClientFromPlayer_Original = nullptr;
decltype(&sub_6FCBC300) sub_6FCBC300_Original = nullptr;
decltype(&SUNIT_AttachSound) SUNIT_AttachSound_Original = nullptr;
decltype(&sub_6FCBC4D0) sub_6FCBC4D0_Original = nullptr;
decltype(&SUNIT_CreatePresetUnit) SUNIT_CreatePresetUnit_Original = nullptr;
decltype(&SUNIT_SpawnPresetUnit) SUNIT_SpawnPresetUnit_Original = nullptr;
decltype(&SUNIT_SpawnPresetUnitsInRoom) SUNIT_SpawnPresetUnitsInRoom_Original = nullptr;
decltype(&sub_6FCBC7E0) sub_6FCBC7E0_Original = nullptr;
decltype(&SUNIT_GetTargetUnit) SUNIT_GetTargetUnit_Original = nullptr;
decltype(&sub_6FCBC930) sub_6FCBC930_Original = nullptr;
decltype(&SUNIT_SetCombatMode) SUNIT_SetCombatMode_Original = nullptr;
decltype(&sub_6FCBC9C0) sub_6FCBC9C0_Original = nullptr;
decltype(&SUNIT_GetPortalOwner) SUNIT_GetPortalOwner_Original = nullptr;
decltype(&SUNIT_IterateUnitsOfType) SUNIT_IterateUnitsOfType_Original = nullptr;
decltype(&SUNIT_IterateLivingPlayers) SUNIT_IterateLivingPlayers_Original = nullptr;
decltype(&SUNIT_SetTimerOnUnit) SUNIT_SetTimerOnUnit_Original = nullptr;
decltype(&SUNIT_GetTimerFromUnit) SUNIT_GetTimerFromUnit_Original = nullptr;
decltype(&D2GAME_DeletePlayerPerFrameEvents_6FCBCE50) D2GAME_DeletePlayerPerFrameEvents_6FCBCE50_Original = nullptr;
decltype(&sub_6FCBCE70) sub_6FCBCE70_Original = nullptr;
decltype(&sub_6FCBCFD0) sub_6FCBCFD0_Original = nullptr;
decltype(&sub_6FCBD120) sub_6FCBD120_Original = nullptr;
decltype(&D2GAME_SKILLS_RewindSkillEx_6FCBD260) D2GAME_SKILLS_RewindSkillEx_6FCBD260_Original = nullptr;
decltype(&sub_6FCBD3A0) sub_6FCBD3A0_Original = nullptr;
decltype(&SUNIT_FillUnitInfo) SUNIT_FillUnitInfo_Original = nullptr;
decltype(&SUNIT_GetInteractUnit) SUNIT_GetInteractUnit_Original = nullptr;
decltype(&SUNIT_RemoveAllItemsFromInventory) SUNIT_RemoveAllItemsFromInventory_Original = nullptr;
decltype(&SUNIT_GetGameFromUnit) SUNIT_GetGameFromUnit_Original = nullptr;
decltype(&D2GAME_SetNecropetFlag_6FCBD760) D2GAME_SetNecropetFlag_6FCBD760_Original = nullptr;
decltype(&D2GAME_GetNecropetFlag_6FCBD790) D2GAME_GetNecropetFlag_6FCBD790_Original = nullptr;
decltype(&D2GAME_SetSparkChest_6FCBD7C0) D2GAME_SetSparkChest_6FCBD7C0_Original = nullptr;
decltype(&D2GAME_CheckIfSparklyChest_6FCBD7F0) D2GAME_CheckIfSparklyChest_6FCBD7F0_Original = nullptr;
decltype(&SUNIT_GetInteractInfo) SUNIT_GetInteractInfo_Original = nullptr;
decltype(&SUNIT_SetInteractInfo) SUNIT_SetInteractInfo_Original = nullptr;
decltype(&SUNIT_ResetInteractInfo) SUNIT_ResetInteractInfo_Original = nullptr;
decltype(&SUNIT_IsDead) SUNIT_IsDead_Original = nullptr;
decltype(&sub_6FCBD900) sub_6FCBD900_Original = nullptr;
decltype(&SUNIT_GetUnitList) SUNIT_GetUnitList_Original = nullptr;
decltype(&SUNIT_CanPetBeTargetedBySkill) SUNIT_CanPetBeTargetedBySkill_Original = nullptr;
decltype(&SUNIT_CanAllyBeTargetedBySkill) SUNIT_CanAllyBeTargetedBySkill_Original = nullptr;
decltype(&SUNIT_AreUnitsAligned) SUNIT_AreUnitsAligned_Original = nullptr;
decltype(&sub_6FCBDD30) sub_6FCBDD30_Original = nullptr;
decltype(&sub_6FCBDE90) sub_6FCBDE90_Original = nullptr;
decltype(&sub_6FCBDF90) sub_6FCBDF90_Original = nullptr;
decltype(&sub_6FCBDFE0) sub_6FCBDFE0_Original = nullptr;
decltype(&SUNIT_GetPartyId) SUNIT_GetPartyId_Original = nullptr;

void __fastcall ESE_INTERCEPT_SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_SUNIT_RemoveUnit(pGame, pUnit);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetNextUnitFromList(pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    ESE_sub_6FCBB190(pGame, pUnit, pRoom);
}

void __fastcall ESE_INTERCEPT_SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pRoomTile)
{
    ESE_SUNIT_WarpPlayer(pGame, pTarget, pRoomTile);
}

void __fastcall ESE_INTERCEPT_SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed)
{
    ESE_SUNIT_InitSeed(pUnit, pSeed);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_AllocUnitData(int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int32_t nMode, DWORD a3)
{
    return ESE_SUNIT_AllocUnitData(nUnitType, nClassId, nX, nY, pGame, pRoom, a7, nMode, a3);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetServerUnit(D2GameStrc* pGame, int32_t nUnitType, int32_t nUnitGUID)
{
    return ESE_SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetOwner(pGame, pUnit);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetLastAttacker(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_SUNIT_Add(D2UnitStrc* pUnit, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t a6)
{
    ESE_SUNIT_Add(pUnit, nX, nY, pGame, pRoom, a6);
}

void __fastcall ESE_INTERCEPT_SUNIT_Restore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY)
{
    ESE_SUNIT_Restore(pGame, pUnit, pRoom, nX, nY);
}

void __fastcall ESE_INTERCEPT_SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    ESE_SUNIT_InitClientInPlayerData(pUnit, pClient);
}

D2ClientStrc* __fastcall ESE_INTERCEPT_SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int32_t nLine)
{
    return ESE_SUNIT_GetClientFromPlayer(pPlayer, szFile, nLine);
}

void __fastcall ESE_INTERCEPT_sub_6FCBC300(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FCBC300(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_SUNIT_AttachSound(D2UnitStrc* pUnit, int32_t nUpdateType, D2UnitStrc* pUpdateUnit)
{
    ESE_SUNIT_AttachSound(pUnit, nUpdateType, pUpdateUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FCBC4D0(D2UnitStrc* pUnit)
{
    ESE_sub_6FCBC4D0(pUnit);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, int32_t nMode, int32_t nUnitFlags)
{
    return ESE_SUNIT_CreatePresetUnit(pGame, pRoom, nUnitType, nClassId, nX, nY, nMode, nUnitFlags);
}

void __fastcall ESE_INTERCEPT_SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    ESE_SUNIT_SpawnPresetUnit(pGame, pRoom, pPresetUnit);
}

void __fastcall ESE_INTERCEPT_SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    ESE_SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
}

void __fastcall ESE_INTERCEPT_sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FCBC7E0(pGame, pUnit);
}

D2UnitStrc* __stdcall ESE_INTERCEPT_SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetTargetUnit(pGame, pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return ESE_sub_6FCBC930(pGame, pMissile);
}

void __fastcall ESE_INTERCEPT_SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMode)
{
    ESE_SUNIT_SetCombatMode(pGame, pUnit, nMode);
}

void __fastcall ESE_INTERCEPT_sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond)
{
    ESE_sub_6FCBC9C0(pFirst, pSecond);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pPortal)
{
    return ESE_SUNIT_GetPortalOwner(pGame, pPortal);
}

void __fastcall ESE_INTERCEPT_SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int32_t nType, void* pArg, int32_t(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*))
{
    ESE_SUNIT_IterateUnitsOfType(pGame, nType, pArg, pfIterate);
}

void __fastcall ESE_INTERCEPT_SUNIT_IterateLivingPlayers(D2GameStrc* pGame, void(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), void* pArg)
{
    ESE_SUNIT_IterateLivingPlayers(pGame, pfIterate, pArg);
}

void __fastcall ESE_INTERCEPT_SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer)
{
    ESE_SUNIT_SetTimerOnUnit(pUnit, pTimer);
}

D2EventTimerStrc* __fastcall ESE_INTERCEPT_SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetTimerFromUnit(pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FCBCE70(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FCBCFD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3)
{
    ESE_sub_6FCBCFD0(pGame, pUnit, a3);
}

void __fastcall ESE_INTERCEPT_sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3)
{
    ESE_sub_6FCBD120(pGame, pUnit, a3);
}

void __fastcall ESE_INTERCEPT_D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3)
{
    ESE_D2GAME_SKILLS_RewindSkillEx_6FCBD260(pGame, pUnit, a3);
}

void __fastcall ESE_INTERCEPT_sub_6FCBD3A0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_sub_6FCBD3A0(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pInfo)
{
    ESE_SUNIT_FillUnitInfo(pUnit, pInfo);
}

D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetInteractUnit(pGame, pUnit);
}

void __fastcall ESE_INTERCEPT_SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    ESE_SUNIT_RemoveAllItemsFromInventory(pGame, pUnit);
}

D2GameStrc* __fastcall ESE_INTERCEPT_SUNIT_GetGameFromUnit(D2UnitStrc* pUnit)
{
    return ESE_SUNIT_GetGameFromUnit(pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_SetNecropetFlag_6FCBD760(D2UnitStrc* pUnit, int32_t nFlag)
{
    ESE_D2GAME_SetNecropetFlag_6FCBD760(pUnit, nFlag);
}

uint32_t __fastcall ESE_INTERCEPT_D2GAME_GetNecropetFlag_6FCBD790(D2UnitStrc* pUnit)
{
    return ESE_D2GAME_GetNecropetFlag_6FCBD790(pUnit);
}

void __fastcall ESE_INTERCEPT_D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, uint8_t nSparkChest)
{
    ESE_D2GAME_SetSparkChest_6FCBD7C0(pUnit, nSparkChest);
}

uint8_t __fastcall ESE_INTERCEPT_D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit)
{
    return ESE_D2GAME_CheckIfSparklyChest_6FCBD7F0(pUnit);
}

int32_t __stdcall ESE_INTERCEPT_SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int32_t* pInteractUnitType, int32_t* pInteractUnitGUID)
{
    return ESE_SUNIT_GetInteractInfo(pUnit, pInteractUnitType, pInteractUnitGUID);
}

void __stdcall ESE_INTERCEPT_SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int32_t nInteractUnitType, int32_t nInteractUnitGUID)
{
    ESE_SUNIT_SetInteractInfo(pUnit, nInteractUnitType, nInteractUnitGUID);
}

void __stdcall ESE_INTERCEPT_SUNIT_ResetInteractInfo(D2UnitStrc* pUnit)
{
    ESE_SUNIT_ResetInteractInfo(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_SUNIT_IsDead(D2UnitStrc* pUnit)
{
    return ESE_SUNIT_IsDead(pUnit);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCBD900(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return ESE_sub_6FCBD900(pGame, pUnit, pTarget);
}

D2UnitStrc** __fastcall ESE_INTERCEPT_SUNIT_GetUnitList(int32_t nUnitType, D2GameStrc* pGame, int32_t nUnitGUID)
{
    return ESE_SUNIT_GetUnitList(nUnitType, pGame, nUnitGUID);
}

int32_t __fastcall ESE_INTERCEPT_SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId)
{
    return ESE_SUNIT_CanPetBeTargetedBySkill(pGame, pOwner, pPet, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId)
{
    return ESE_SUNIT_CanAllyBeTargetedBySkill(pGame, pOwner, pPet, nSkillId);
}

int32_t __fastcall ESE_INTERCEPT_SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit)
{
    return ESE_SUNIT_AreUnitsAligned(pGame, pUnit1, pUnit);
}

void __fastcall ESE_INTERCEPT_sub_6FCBDD30(D2UnitStrc* pUnit, uint8_t nAlignNew, int32_t a3)
{
    ESE_sub_6FCBDD30(pUnit, nAlignNew, a3);
}

void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable)
{
    ESE_sub_6FCBDE90(pUnit, bSetUninterruptable);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t a3, int32_t a4, int32_t a5)
{
    return ESE_sub_6FCBDF90(pGame, pPlayer, a3, a4, a5);
}

int32_t __fastcall ESE_INTERCEPT_sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int32_t nX, int32_t nY, int32_t a6, int32_t a7)
{
    return ESE_sub_6FCBDFE0(pGame, pUnit, pInputRoom, nX, nY, a6, a7);
}

int16_t __fastcall ESE_INTERCEPT_SUNIT_GetPartyId(D2UnitStrc* pPlayer)
{
    return ESE_SUNIT_GetPartyId(pPlayer);
}


