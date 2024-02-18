#pragma once

#include <UNIT/SUnit_ESE.h>
#include <type_traits>
#include <cstdlib>
#include <Units/Units.h>
#include <Drlg/D2DrlgPreset.h>
#include <GAME/Event.h>

//D2Game.0x6FCBAEE0
void __fastcall ESE_INTERCEPT_SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBB160
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);
//D2Game.0x6FCBB190
void __fastcall ESE_INTERCEPT_sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);
//D2Game.0x6FCBB440
void __fastcall ESE_INTERCEPT_SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pRoomTile);
//D2Game.0x6FCBB630
void __fastcall ESE_INTERCEPT_SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed);
//D2Game.0x6FCBB6C0
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_AllocUnitData(int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int32_t nMode, DWORD a3);
//D2Game.0x6FCBBB00
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetServerUnit(D2GameStrc* pGame, int32_t nUnitType, int32_t nUnitGUID);
//D2Game.0x6FCBBB70
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBBC00
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBBCB0
void __fastcall ESE_INTERCEPT_SUNIT_Add(D2UnitStrc* pUnit, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t a6);
//D2Game.0x6FCBBFE0
void __fastcall ESE_INTERCEPT_SUNIT_Restore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY);
//D2Game.0x6FCBC280
void __fastcall ESE_INTERCEPT_SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient);
//D2Game.0x6FCBC2E0
D2ClientStrc* __fastcall ESE_INTERCEPT_SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int32_t nLine);
//D2Game.0x6FCBC300
void __fastcall ESE_INTERCEPT_sub_6FCBC300(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBC480
void __fastcall ESE_INTERCEPT_SUNIT_AttachSound(D2UnitStrc* pUnit, int32_t nUpdateType, D2UnitStrc* pUpdateUnit);
//D2Game.0x6FCBC4D0
void __fastcall ESE_INTERCEPT_sub_6FCBC4D0(D2UnitStrc* pUnit);
//D2Game.0x6FCBC590
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, int32_t nMode, int32_t nUnitFlags);
//D2Game.0x6FCBC6F0
void __fastcall ESE_INTERCEPT_SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit);
//D2Game.0x6FCBC780
void __fastcall ESE_INTERCEPT_SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);
//D2Game.0x6FCBC7E0
void __fastcall ESE_INTERCEPT_sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBC900
D2UnitStrc* __stdcall ESE_INTERCEPT_SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBC930
int32_t __fastcall ESE_INTERCEPT_sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FCBC9A0
void __fastcall ESE_INTERCEPT_SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FCBC9C0
void __fastcall ESE_INTERCEPT_sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond);
//D2Game.0x6FCBCB30
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pPortal);
//D2Game.0x6FCBCC40
void __fastcall ESE_INTERCEPT_SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int32_t nType, void* pArg, int32_t(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*));
//D2Game.0x6FCBCD70
void __fastcall ESE_INTERCEPT_SUNIT_IterateLivingPlayers(D2GameStrc* pGame, void(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), void* pArg);
//D2Game.0x6FCBCE30
void __fastcall ESE_INTERCEPT_SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer);
//D2Game.0x6FCBCE40
D2EventTimerStrc* __fastcall ESE_INTERCEPT_SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit);
//D2Game.0x6FCBCE50
void __fastcall ESE_INTERCEPT_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBCE70
void __fastcall ESE_INTERCEPT_sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBCFD0
void __fastcall ESE_INTERCEPT_sub_6FCBCFD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FCBD120
void __fastcall ESE_INTERCEPT_sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FCBD260
void __fastcall ESE_INTERCEPT_D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FCBD3A0
void __fastcall ESE_INTERCEPT_sub_6FCBD3A0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBD3D0
void __fastcall ESE_INTERCEPT_SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pInfo);
//D2Game.0x6FCBD4D0
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBD550
void __fastcall ESE_INTERCEPT_SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBD730
D2GameStrc* __fastcall ESE_INTERCEPT_SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);
//D2Game.0x6FCBD760
void __fastcall ESE_INTERCEPT_D2GAME_SetNecropetFlag_6FCBD760(D2UnitStrc* pUnit, int32_t nFlag);
//D2Game.0x6FCBD790
uint32_t __fastcall ESE_INTERCEPT_D2GAME_GetNecropetFlag_6FCBD790(D2UnitStrc* pUnit);
//D2Game.0x6FCBD7C0
void __fastcall ESE_INTERCEPT_D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, uint8_t nSparkChest);
//D2Game.0x6FCBD7F0
uint8_t __fastcall ESE_INTERCEPT_D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit);
//D2Game.0x6FCBD820
int32_t __stdcall ESE_INTERCEPT_SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int32_t* pInteractUnitType, int32_t* pInteractUnitGUID);
//D2Game.0x6FCBD840
void __stdcall ESE_INTERCEPT_SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int32_t nInteractUnitType, int32_t nInteractUnitGUID);
//D2Game.0x6FCBD890
void __stdcall ESE_INTERCEPT_SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);
//D2Game.0x6FCBD8B0
int32_t __fastcall ESE_INTERCEPT_SUNIT_IsDead(D2UnitStrc* pUnit);
//D2Game.0x6FCBD900
int32_t __fastcall ESE_INTERCEPT_sub_6FCBD900(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
//D2Game.0x6FCBDA10
D2UnitStrc** __fastcall ESE_INTERCEPT_SUNIT_GetUnitList(int32_t nUnitType, D2GameStrc* pGame, int32_t nUnitGUID);
//D2Game.0x6FCBDA40
int32_t __fastcall ESE_INTERCEPT_SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId);
//D2Game.0x6FCBDAD0
int32_t __fastcall ESE_INTERCEPT_SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId);
//D2Game.0x6FCBDC60
int32_t __fastcall ESE_INTERCEPT_SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit);
//D2Game.0x6FCBDD30
void __fastcall ESE_INTERCEPT_sub_6FCBDD30(D2UnitStrc* pUnit, uint8_t nAlignNew, int32_t a3);
//D2Game.0x6FCBDE90
void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);
//D2Game.0x6FCBDF90
int32_t __fastcall ESE_INTERCEPT_sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t a3, int32_t a4, int32_t a5);
//D2Game.0x6FCBDFE0
int32_t __fastcall ESE_INTERCEPT_sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int32_t nX, int32_t nY, int32_t a6, int32_t a7);
//D2Game.0x6FCBE2D0
int16_t __fastcall ESE_INTERCEPT_SUNIT_GetPartyId(D2UnitStrc* pPlayer);

extern decltype(&SUNIT_RemoveUnit) SUNIT_RemoveUnit_Original;
void __fastcall ESE_INTERCEPT_SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_RemoveUnit), decltype(&ESE_INTERCEPT_SUNIT_RemoveUnit)>, "ESE_INTERCEPT_SUNIT_RemoveUnit has a different type than previously known.");

extern decltype(&SUNIT_GetNextUnitFromList) SUNIT_GetNextUnitFromList_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetNextUnitFromList), decltype(&ESE_INTERCEPT_SUNIT_GetNextUnitFromList)>, "ESE_INTERCEPT_SUNIT_GetNextUnitFromList has a different type than previously known.");

extern decltype(&sub_6FCBB190) sub_6FCBB190_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);
static_assert(std::is_same_v<decltype(&sub_6FCBB190), decltype(&ESE_INTERCEPT_sub_6FCBB190)>, "ESE_INTERCEPT_sub_6FCBB190 has a different type than previously known.");

extern decltype(&SUNIT_WarpPlayer) SUNIT_WarpPlayer_Original;
void __fastcall ESE_INTERCEPT_SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pRoomTile);
static_assert(std::is_same_v<decltype(&SUNIT_WarpPlayer), decltype(&ESE_INTERCEPT_SUNIT_WarpPlayer)>, "ESE_INTERCEPT_SUNIT_WarpPlayer has a different type than previously known.");

extern decltype(&SUNIT_InitSeed) SUNIT_InitSeed_Original;
void __fastcall ESE_INTERCEPT_SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed);
static_assert(std::is_same_v<decltype(&SUNIT_InitSeed), decltype(&ESE_INTERCEPT_SUNIT_InitSeed)>, "ESE_INTERCEPT_SUNIT_InitSeed has a different type than previously known.");

extern decltype(&SUNIT_AllocUnitData) SUNIT_AllocUnitData_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_AllocUnitData(int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int32_t nMode, DWORD a3);
static_assert(std::is_same_v<decltype(&SUNIT_AllocUnitData), decltype(&ESE_INTERCEPT_SUNIT_AllocUnitData)>, "ESE_INTERCEPT_SUNIT_AllocUnitData has a different type than previously known.");

extern decltype(&SUNIT_GetServerUnit) SUNIT_GetServerUnit_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetServerUnit(D2GameStrc* pGame, int32_t nUnitType, int32_t nUnitGUID);
static_assert(std::is_same_v<decltype(&SUNIT_GetServerUnit), decltype(&ESE_INTERCEPT_SUNIT_GetServerUnit)>, "ESE_INTERCEPT_SUNIT_GetServerUnit has a different type than previously known.");

extern decltype(&SUNIT_GetOwner) SUNIT_GetOwner_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetOwner), decltype(&ESE_INTERCEPT_SUNIT_GetOwner)>, "ESE_INTERCEPT_SUNIT_GetOwner has a different type than previously known.");

extern decltype(&SUNIT_GetLastAttacker) SUNIT_GetLastAttacker_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetLastAttacker), decltype(&ESE_INTERCEPT_SUNIT_GetLastAttacker)>, "ESE_INTERCEPT_SUNIT_GetLastAttacker has a different type than previously known.");

extern decltype(&SUNIT_Add) SUNIT_Add_Original;
void __fastcall ESE_INTERCEPT_SUNIT_Add(D2UnitStrc* pUnit, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t a6);
static_assert(std::is_same_v<decltype(&SUNIT_Add), decltype(&ESE_INTERCEPT_SUNIT_Add)>, "ESE_INTERCEPT_SUNIT_Add has a different type than previously known.");

extern decltype(&SUNIT_Restore) SUNIT_Restore_Original;
void __fastcall ESE_INTERCEPT_SUNIT_Restore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY);
static_assert(std::is_same_v<decltype(&SUNIT_Restore), decltype(&ESE_INTERCEPT_SUNIT_Restore)>, "ESE_INTERCEPT_SUNIT_Restore has a different type than previously known.");

extern decltype(&SUNIT_InitClientInPlayerData) SUNIT_InitClientInPlayerData_Original;
void __fastcall ESE_INTERCEPT_SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient);
static_assert(std::is_same_v<decltype(&SUNIT_InitClientInPlayerData), decltype(&ESE_INTERCEPT_SUNIT_InitClientInPlayerData)>, "ESE_INTERCEPT_SUNIT_InitClientInPlayerData has a different type than previously known.");

extern decltype(&SUNIT_GetClientFromPlayer) SUNIT_GetClientFromPlayer_Original;
D2ClientStrc* __fastcall ESE_INTERCEPT_SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int32_t nLine);
static_assert(std::is_same_v<decltype(&SUNIT_GetClientFromPlayer), decltype(&ESE_INTERCEPT_SUNIT_GetClientFromPlayer)>, "ESE_INTERCEPT_SUNIT_GetClientFromPlayer has a different type than previously known.");

extern decltype(&sub_6FCBC300) sub_6FCBC300_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBC300(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FCBC300), decltype(&ESE_INTERCEPT_sub_6FCBC300)>, "ESE_INTERCEPT_sub_6FCBC300 has a different type than previously known.");

extern decltype(&SUNIT_AttachSound) SUNIT_AttachSound_Original;
void __fastcall ESE_INTERCEPT_SUNIT_AttachSound(D2UnitStrc* pUnit, int32_t nUpdateType, D2UnitStrc* pUpdateUnit);
static_assert(std::is_same_v<decltype(&SUNIT_AttachSound), decltype(&ESE_INTERCEPT_SUNIT_AttachSound)>, "ESE_INTERCEPT_SUNIT_AttachSound has a different type than previously known.");

extern decltype(&sub_6FCBC4D0) sub_6FCBC4D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBC4D0(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FCBC4D0), decltype(&ESE_INTERCEPT_sub_6FCBC4D0)>, "ESE_INTERCEPT_sub_6FCBC4D0 has a different type than previously known.");

extern decltype(&SUNIT_CreatePresetUnit) SUNIT_CreatePresetUnit_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, int32_t nMode, int32_t nUnitFlags);
static_assert(std::is_same_v<decltype(&SUNIT_CreatePresetUnit), decltype(&ESE_INTERCEPT_SUNIT_CreatePresetUnit)>, "ESE_INTERCEPT_SUNIT_CreatePresetUnit has a different type than previously known.");

extern decltype(&SUNIT_SpawnPresetUnit) SUNIT_SpawnPresetUnit_Original;
void __fastcall ESE_INTERCEPT_SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit);
static_assert(std::is_same_v<decltype(&SUNIT_SpawnPresetUnit), decltype(&ESE_INTERCEPT_SUNIT_SpawnPresetUnit)>, "ESE_INTERCEPT_SUNIT_SpawnPresetUnit has a different type than previously known.");

extern decltype(&SUNIT_SpawnPresetUnitsInRoom) SUNIT_SpawnPresetUnitsInRoom_Original;
void __fastcall ESE_INTERCEPT_SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);
static_assert(std::is_same_v<decltype(&SUNIT_SpawnPresetUnitsInRoom), decltype(&ESE_INTERCEPT_SUNIT_SpawnPresetUnitsInRoom)>, "ESE_INTERCEPT_SUNIT_SpawnPresetUnitsInRoom has a different type than previously known.");

extern decltype(&sub_6FCBC7E0) sub_6FCBC7E0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FCBC7E0), decltype(&ESE_INTERCEPT_sub_6FCBC7E0)>, "ESE_INTERCEPT_sub_6FCBC7E0 has a different type than previously known.");

extern decltype(&SUNIT_GetTargetUnit) SUNIT_GetTargetUnit_Original;
D2UnitStrc* __stdcall ESE_INTERCEPT_SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetTargetUnit), decltype(&ESE_INTERCEPT_SUNIT_GetTargetUnit)>, "ESE_INTERCEPT_SUNIT_GetTargetUnit has a different type than previously known.");

extern decltype(&sub_6FCBC930) sub_6FCBC930_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);
static_assert(std::is_same_v<decltype(&sub_6FCBC930), decltype(&ESE_INTERCEPT_sub_6FCBC930)>, "ESE_INTERCEPT_sub_6FCBC930 has a different type than previously known.");

extern decltype(&SUNIT_SetCombatMode) SUNIT_SetCombatMode_Original;
void __fastcall ESE_INTERCEPT_SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMode);
static_assert(std::is_same_v<decltype(&SUNIT_SetCombatMode), decltype(&ESE_INTERCEPT_SUNIT_SetCombatMode)>, "ESE_INTERCEPT_SUNIT_SetCombatMode has a different type than previously known.");

extern decltype(&sub_6FCBC9C0) sub_6FCBC9C0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond);
static_assert(std::is_same_v<decltype(&sub_6FCBC9C0), decltype(&ESE_INTERCEPT_sub_6FCBC9C0)>, "ESE_INTERCEPT_sub_6FCBC9C0 has a different type than previously known.");

extern decltype(&SUNIT_GetPortalOwner) SUNIT_GetPortalOwner_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pPortal);
static_assert(std::is_same_v<decltype(&SUNIT_GetPortalOwner), decltype(&ESE_INTERCEPT_SUNIT_GetPortalOwner)>, "ESE_INTERCEPT_SUNIT_GetPortalOwner has a different type than previously known.");

extern decltype(&SUNIT_IterateUnitsOfType) SUNIT_IterateUnitsOfType_Original;
void __fastcall ESE_INTERCEPT_SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int32_t nType, void* pArg, int32_t(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*));
static_assert(std::is_same_v<decltype(&SUNIT_IterateUnitsOfType), decltype(&ESE_INTERCEPT_SUNIT_IterateUnitsOfType)>, "ESE_INTERCEPT_SUNIT_IterateUnitsOfType has a different type than previously known.");

extern decltype(&SUNIT_IterateLivingPlayers) SUNIT_IterateLivingPlayers_Original;
void __fastcall ESE_INTERCEPT_SUNIT_IterateLivingPlayers(D2GameStrc* pGame, void(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), void* pArg);
static_assert(std::is_same_v<decltype(&SUNIT_IterateLivingPlayers), decltype(&ESE_INTERCEPT_SUNIT_IterateLivingPlayers)>, "ESE_INTERCEPT_SUNIT_IterateLivingPlayers has a different type than previously known.");

extern decltype(&SUNIT_SetTimerOnUnit) SUNIT_SetTimerOnUnit_Original;
void __fastcall ESE_INTERCEPT_SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer);
static_assert(std::is_same_v<decltype(&SUNIT_SetTimerOnUnit), decltype(&ESE_INTERCEPT_SUNIT_SetTimerOnUnit)>, "ESE_INTERCEPT_SUNIT_SetTimerOnUnit has a different type than previously known.");

extern decltype(&SUNIT_GetTimerFromUnit) SUNIT_GetTimerFromUnit_Original;
D2EventTimerStrc* __fastcall ESE_INTERCEPT_SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetTimerFromUnit), decltype(&ESE_INTERCEPT_SUNIT_GetTimerFromUnit)>, "ESE_INTERCEPT_SUNIT_GetTimerFromUnit has a different type than previously known.");

extern decltype(&D2GAME_DeletePlayerPerFrameEvents_6FCBCE50) D2GAME_DeletePlayerPerFrameEvents_6FCBCE50_Original;
void __fastcall ESE_INTERCEPT_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&D2GAME_DeletePlayerPerFrameEvents_6FCBCE50), decltype(&ESE_INTERCEPT_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50)>, "ESE_INTERCEPT_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50 has a different type than previously known.");

extern decltype(&sub_6FCBCE70) sub_6FCBCE70_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FCBCE70), decltype(&ESE_INTERCEPT_sub_6FCBCE70)>, "ESE_INTERCEPT_sub_6FCBCE70 has a different type than previously known.");

extern decltype(&sub_6FCBCFD0) sub_6FCBCFD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBCFD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
static_assert(std::is_same_v<decltype(&sub_6FCBCFD0), decltype(&ESE_INTERCEPT_sub_6FCBCFD0)>, "ESE_INTERCEPT_sub_6FCBCFD0 has a different type than previously known.");

extern decltype(&sub_6FCBD120) sub_6FCBD120_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
static_assert(std::is_same_v<decltype(&sub_6FCBD120), decltype(&ESE_INTERCEPT_sub_6FCBD120)>, "ESE_INTERCEPT_sub_6FCBD120 has a different type than previously known.");

extern decltype(&D2GAME_SKILLS_RewindSkillEx_6FCBD260) D2GAME_SKILLS_RewindSkillEx_6FCBD260_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
static_assert(std::is_same_v<decltype(&D2GAME_SKILLS_RewindSkillEx_6FCBD260), decltype(&ESE_INTERCEPT_D2GAME_SKILLS_RewindSkillEx_6FCBD260)>, "ESE_INTERCEPT_D2GAME_SKILLS_RewindSkillEx_6FCBD260 has a different type than previously known.");

extern decltype(&sub_6FCBD3A0) sub_6FCBD3A0_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBD3A0(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&sub_6FCBD3A0), decltype(&ESE_INTERCEPT_sub_6FCBD3A0)>, "ESE_INTERCEPT_sub_6FCBD3A0 has a different type than previously known.");

extern decltype(&SUNIT_FillUnitInfo) SUNIT_FillUnitInfo_Original;
void __fastcall ESE_INTERCEPT_SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pInfo);
static_assert(std::is_same_v<decltype(&SUNIT_FillUnitInfo), decltype(&ESE_INTERCEPT_SUNIT_FillUnitInfo)>, "ESE_INTERCEPT_SUNIT_FillUnitInfo has a different type than previously known.");

extern decltype(&SUNIT_GetInteractUnit) SUNIT_GetInteractUnit_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetInteractUnit), decltype(&ESE_INTERCEPT_SUNIT_GetInteractUnit)>, "ESE_INTERCEPT_SUNIT_GetInteractUnit has a different type than previously known.");

extern decltype(&SUNIT_RemoveAllItemsFromInventory) SUNIT_RemoveAllItemsFromInventory_Original;
void __fastcall ESE_INTERCEPT_SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_RemoveAllItemsFromInventory), decltype(&ESE_INTERCEPT_SUNIT_RemoveAllItemsFromInventory)>, "ESE_INTERCEPT_SUNIT_RemoveAllItemsFromInventory has a different type than previously known.");

extern decltype(&SUNIT_GetGameFromUnit) SUNIT_GetGameFromUnit_Original;
D2GameStrc* __fastcall ESE_INTERCEPT_SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_GetGameFromUnit), decltype(&ESE_INTERCEPT_SUNIT_GetGameFromUnit)>, "ESE_INTERCEPT_SUNIT_GetGameFromUnit has a different type than previously known.");

extern decltype(&D2GAME_SetNecropetFlag_6FCBD760) D2GAME_SetNecropetFlag_6FCBD760_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SetNecropetFlag_6FCBD760(D2UnitStrc* pUnit, int32_t nFlag);
static_assert(std::is_same_v<decltype(&D2GAME_SetNecropetFlag_6FCBD760), decltype(&ESE_INTERCEPT_D2GAME_SetNecropetFlag_6FCBD760)>, "ESE_INTERCEPT_D2GAME_SetNecropetFlag_6FCBD760 has a different type than previously known.");

extern decltype(&D2GAME_GetNecropetFlag_6FCBD790) D2GAME_GetNecropetFlag_6FCBD790_Original;
uint32_t __fastcall ESE_INTERCEPT_D2GAME_GetNecropetFlag_6FCBD790(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&D2GAME_GetNecropetFlag_6FCBD790), decltype(&ESE_INTERCEPT_D2GAME_GetNecropetFlag_6FCBD790)>, "ESE_INTERCEPT_D2GAME_GetNecropetFlag_6FCBD790 has a different type than previously known.");

extern decltype(&D2GAME_SetSparkChest_6FCBD7C0) D2GAME_SetSparkChest_6FCBD7C0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, uint8_t nSparkChest);
static_assert(std::is_same_v<decltype(&D2GAME_SetSparkChest_6FCBD7C0), decltype(&ESE_INTERCEPT_D2GAME_SetSparkChest_6FCBD7C0)>, "ESE_INTERCEPT_D2GAME_SetSparkChest_6FCBD7C0 has a different type than previously known.");

extern decltype(&D2GAME_CheckIfSparklyChest_6FCBD7F0) D2GAME_CheckIfSparklyChest_6FCBD7F0_Original;
uint8_t __fastcall ESE_INTERCEPT_D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&D2GAME_CheckIfSparklyChest_6FCBD7F0), decltype(&ESE_INTERCEPT_D2GAME_CheckIfSparklyChest_6FCBD7F0)>, "ESE_INTERCEPT_D2GAME_CheckIfSparklyChest_6FCBD7F0 has a different type than previously known.");

extern decltype(&SUNIT_GetInteractInfo) SUNIT_GetInteractInfo_Original;
int32_t __stdcall ESE_INTERCEPT_SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int32_t* pInteractUnitType, int32_t* pInteractUnitGUID);
static_assert(std::is_same_v<decltype(&SUNIT_GetInteractInfo), decltype(&ESE_INTERCEPT_SUNIT_GetInteractInfo)>, "ESE_INTERCEPT_SUNIT_GetInteractInfo has a different type than previously known.");

extern decltype(&SUNIT_SetInteractInfo) SUNIT_SetInteractInfo_Original;
void __stdcall ESE_INTERCEPT_SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int32_t nInteractUnitType, int32_t nInteractUnitGUID);
static_assert(std::is_same_v<decltype(&SUNIT_SetInteractInfo), decltype(&ESE_INTERCEPT_SUNIT_SetInteractInfo)>, "ESE_INTERCEPT_SUNIT_SetInteractInfo has a different type than previously known.");

extern decltype(&SUNIT_ResetInteractInfo) SUNIT_ResetInteractInfo_Original;
void __stdcall ESE_INTERCEPT_SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_ResetInteractInfo), decltype(&ESE_INTERCEPT_SUNIT_ResetInteractInfo)>, "ESE_INTERCEPT_SUNIT_ResetInteractInfo has a different type than previously known.");

extern decltype(&SUNIT_IsDead) SUNIT_IsDead_Original;
int32_t __fastcall ESE_INTERCEPT_SUNIT_IsDead(D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_IsDead), decltype(&ESE_INTERCEPT_SUNIT_IsDead)>, "ESE_INTERCEPT_SUNIT_IsDead has a different type than previously known.");

extern decltype(&sub_6FCBD900) sub_6FCBD900_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCBD900(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
static_assert(std::is_same_v<decltype(&sub_6FCBD900), decltype(&ESE_INTERCEPT_sub_6FCBD900)>, "ESE_INTERCEPT_sub_6FCBD900 has a different type than previously known.");

extern decltype(&SUNIT_GetUnitList) SUNIT_GetUnitList_Original;
D2UnitStrc** __fastcall ESE_INTERCEPT_SUNIT_GetUnitList(int32_t nUnitType, D2GameStrc* pGame, int32_t nUnitGUID);
static_assert(std::is_same_v<decltype(&SUNIT_GetUnitList), decltype(&ESE_INTERCEPT_SUNIT_GetUnitList)>, "ESE_INTERCEPT_SUNIT_GetUnitList has a different type than previously known.");

extern decltype(&SUNIT_CanPetBeTargetedBySkill) SUNIT_CanPetBeTargetedBySkill_Original;
int32_t __fastcall ESE_INTERCEPT_SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SUNIT_CanPetBeTargetedBySkill), decltype(&ESE_INTERCEPT_SUNIT_CanPetBeTargetedBySkill)>, "ESE_INTERCEPT_SUNIT_CanPetBeTargetedBySkill has a different type than previously known.");

extern decltype(&SUNIT_CanAllyBeTargetedBySkill) SUNIT_CanAllyBeTargetedBySkill_Original;
int32_t __fastcall ESE_INTERCEPT_SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId);
static_assert(std::is_same_v<decltype(&SUNIT_CanAllyBeTargetedBySkill), decltype(&ESE_INTERCEPT_SUNIT_CanAllyBeTargetedBySkill)>, "ESE_INTERCEPT_SUNIT_CanAllyBeTargetedBySkill has a different type than previously known.");

extern decltype(&SUNIT_AreUnitsAligned) SUNIT_AreUnitsAligned_Original;
int32_t __fastcall ESE_INTERCEPT_SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit);
static_assert(std::is_same_v<decltype(&SUNIT_AreUnitsAligned), decltype(&ESE_INTERCEPT_SUNIT_AreUnitsAligned)>, "ESE_INTERCEPT_SUNIT_AreUnitsAligned has a different type than previously known.");

extern decltype(&sub_6FCBDD30) sub_6FCBDD30_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBDD30(D2UnitStrc* pUnit, uint8_t nAlignNew, int32_t a3);
static_assert(std::is_same_v<decltype(&sub_6FCBDD30), decltype(&ESE_INTERCEPT_sub_6FCBDD30)>, "ESE_INTERCEPT_sub_6FCBDD30 has a different type than previously known.");

extern decltype(&sub_6FCBDE90) sub_6FCBDE90_Original;
void __fastcall ESE_INTERCEPT_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);
static_assert(std::is_same_v<decltype(&sub_6FCBDE90), decltype(&ESE_INTERCEPT_sub_6FCBDE90)>, "ESE_INTERCEPT_sub_6FCBDE90 has a different type than previously known.");

extern decltype(&sub_6FCBDF90) sub_6FCBDF90_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t a3, int32_t a4, int32_t a5);
static_assert(std::is_same_v<decltype(&sub_6FCBDF90), decltype(&ESE_INTERCEPT_sub_6FCBDF90)>, "ESE_INTERCEPT_sub_6FCBDF90 has a different type than previously known.");

extern decltype(&sub_6FCBDFE0) sub_6FCBDFE0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int32_t nX, int32_t nY, int32_t a6, int32_t a7);
static_assert(std::is_same_v<decltype(&sub_6FCBDFE0), decltype(&ESE_INTERCEPT_sub_6FCBDFE0)>, "ESE_INTERCEPT_sub_6FCBDFE0 has a different type than previously known.");

extern decltype(&SUNIT_GetPartyId) SUNIT_GetPartyId_Original;
int16_t __fastcall ESE_INTERCEPT_SUNIT_GetPartyId(D2UnitStrc* pPlayer);
static_assert(std::is_same_v<decltype(&SUNIT_GetPartyId), decltype(&ESE_INTERCEPT_SUNIT_GetPartyId)>, "ESE_INTERCEPT_SUNIT_GetPartyId has a different type than previously known.");

