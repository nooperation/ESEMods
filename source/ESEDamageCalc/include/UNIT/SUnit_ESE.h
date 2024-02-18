#pragma once

#include <UNIT/SUnit.h>

//D2Game.0x6FCBAEE0
void __fastcall ESE_SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBB160
D2UnitStrc* __fastcall ESE_SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit);
//D2Game.0x6FCBB190
void __fastcall ESE_sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom);
//D2Game.0x6FCBB440
void __fastcall ESE_SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pTarget, D2UnitStrc* pRoomTile);
//D2Game.0x6FCBB630
void __fastcall ESE_SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed);
//D2Game.0x6FCBB6C0
D2UnitStrc* __fastcall ESE_SUNIT_AllocUnitData(int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int32_t nMode, DWORD a3);
//D2Game.0x6FCBBB00
D2UnitStrc* __fastcall ESE_SUNIT_GetServerUnit(D2GameStrc* pGame, int32_t nUnitType, int32_t nUnitGUID);
//D2Game.0x6FCBBB70
D2UnitStrc* __fastcall ESE_SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBBC00
D2UnitStrc* __fastcall ESE_SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBBCB0
void __fastcall ESE_SUNIT_Add(D2UnitStrc* pUnit, int32_t nX, int32_t nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t a6);
//D2Game.0x6FCBBFE0
void __fastcall ESE_SUNIT_Restore(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY);
//D2Game.0x6FCBC280
void __fastcall ESE_SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient);
//D2Game.0x6FCBC2E0
D2ClientStrc* __fastcall ESE_SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int32_t nLine);
//D2Game.0x6FCBC300
void __fastcall ESE_sub_6FCBC300(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBC480
void __fastcall ESE_SUNIT_AttachSound(D2UnitStrc* pUnit, int32_t nUpdateType, D2UnitStrc* pUpdateUnit);
//D2Game.0x6FCBC4D0
void __fastcall ESE_sub_6FCBC4D0(D2UnitStrc* pUnit);
//D2Game.0x6FCBC590
D2UnitStrc* __fastcall ESE_SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int32_t nUnitType, int32_t nClassId, int32_t nX, int32_t nY, int32_t nMode, int32_t nUnitFlags);
//D2Game.0x6FCBC6F0
void __fastcall ESE_SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit);
//D2Game.0x6FCBC780
void __fastcall ESE_SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);
//D2Game.0x6FCBC7E0
void __fastcall ESE_sub_6FCBC7E0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBC900
D2UnitStrc* __stdcall ESE_SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBC930
int32_t __fastcall ESE_sub_6FCBC930(D2GameStrc* pGame, D2UnitStrc* pMissile);
//D2Game.0x6FCBC9A0
void __fastcall ESE_SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMode);
//D2Game.0x6FCBC9C0
void __fastcall ESE_sub_6FCBC9C0(D2UnitStrc* pFirst, D2UnitStrc* pSecond);
//D2Game.0x6FCBCB30
D2UnitStrc* __fastcall ESE_SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pPortal);
//D2Game.0x6FCBCC40
void __fastcall ESE_SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int32_t nType, void* pArg, int32_t(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*));
//D2Game.0x6FCBCD70
void __fastcall ESE_SUNIT_IterateLivingPlayers(D2GameStrc* pGame, void(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), void* pArg);
//D2Game.0x6FCBCE30
void __fastcall ESE_SUNIT_SetTimerOnUnit(D2UnitStrc* pUnit, D2EventTimerStrc* pTimer);
//D2Game.0x6FCBCE40
D2EventTimerStrc* __fastcall ESE_SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit);
//D2Game.0x6FCBCE50
void __fastcall ESE_D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBCE70
void __fastcall ESE_sub_6FCBCE70(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBCFD0
void __fastcall ESE_sub_6FCBCFD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FCBD120
void __fastcall ESE_sub_6FCBD120(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FCBD260
void __fastcall ESE_D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3);
//D2Game.0x6FCBD3A0
void __fastcall ESE_sub_6FCBD3A0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBD3D0
void __fastcall ESE_SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pInfo);
//D2Game.0x6FCBD4D0
D2UnitStrc* __fastcall ESE_SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBD550
void __fastcall ESE_SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FCBD730
D2GameStrc* __fastcall ESE_SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);
//D2Game.0x6FCBD760
void __fastcall ESE_D2GAME_SetNecropetFlag_6FCBD760(D2UnitStrc* pUnit, int32_t nFlag);
//D2Game.0x6FCBD790
uint32_t __fastcall ESE_D2GAME_GetNecropetFlag_6FCBD790(D2UnitStrc* pUnit);
//D2Game.0x6FCBD7C0
void __fastcall ESE_D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, uint8_t nSparkChest);
//D2Game.0x6FCBD7F0
uint8_t __fastcall ESE_D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit);
//D2Game.0x6FCBD820
int32_t __stdcall ESE_SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int32_t* pInteractUnitType, int32_t* pInteractUnitGUID);
//D2Game.0x6FCBD840
void __stdcall ESE_SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int32_t nInteractUnitType, int32_t nInteractUnitGUID);
//D2Game.0x6FCBD890
void __stdcall ESE_SUNIT_ResetInteractInfo(D2UnitStrc* pUnit);
//D2Game.0x6FCBD8B0
int32_t __fastcall ESE_SUNIT_IsDead(D2UnitStrc* pUnit);
//D2Game.0x6FCBD900
int32_t __fastcall ESE_sub_6FCBD900(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
//D2Game.0x6FCBDA10
D2UnitStrc** __fastcall ESE_SUNIT_GetUnitList(int32_t nUnitType, D2GameStrc* pGame, int32_t nUnitGUID);
//D2Game.0x6FCBDA40
int32_t __fastcall ESE_SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId);
//D2Game.0x6FCBDAD0
int32_t __fastcall ESE_SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int32_t nSkillId);
//D2Game.0x6FCBDC60
int32_t __fastcall ESE_SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit);
//D2Game.0x6FCBDD30
void __fastcall ESE_sub_6FCBDD30(D2UnitStrc* pUnit, uint8_t nAlignNew, int32_t a3);
//D2Game.0x6FCBDE90
void __fastcall ESE_sub_6FCBDE90(D2UnitStrc* pUnit, int32_t bSetUninterruptable);
//D2Game.0x6FCBDF90
int32_t __fastcall ESE_sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t a3, int32_t a4, int32_t a5);
//D2Game.0x6FCBDFE0
int32_t __fastcall ESE_sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int32_t nX, int32_t nY, int32_t a6, int32_t a7);
//D2Game.0x6FCBE2D0
int16_t __fastcall ESE_SUNIT_GetPartyId(D2UnitStrc* pPlayer);
