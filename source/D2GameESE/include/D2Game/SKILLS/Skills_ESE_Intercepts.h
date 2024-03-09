#pragma once

#include "D2Game/UNIT/SUnitDmg_ESE.h"
#include "D2Game/SKILLS/Skills_ESE.h"

#include <D2StatList.h>
#include <Units/Units.h>
#include <Units/UnitFinds.h>

#include <type_traits>
#include <cstdlib>

//D2Game.0x6FD0F8B0
int32_t __fastcall ESE_INTERCEPT_sub_6FD0F8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nValue);
//D2Game.0x6FD0FA00
int32_t __fastcall ESE_INTERCEPT_sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, uint32_t nAuraFilter);
//D2Game.0x6FD0FDD0
void __fastcall ESE_INTERCEPT_sub_6FD0FDD0(D2UnitStrc* pUnit);
//D2Game.0x6FD0FE50
void __fastcall ESE_INTERCEPT_sub_6FD0FE50(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs);
//D2Game.0x6FD0FE80
void __fastcall ESE_INTERCEPT_sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int32_t bCheckMonAuraFlag, const char* szFile, int32_t nLine);
//D2Game.0x6FD10140
void __fastcall ESE_INTERCEPT_sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nUnused);
//D2Game.0x6FD10200
int32_t __fastcall ESE_INTERCEPT_sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, D2DamageStrc* pDamage, uint32_t nAuraFilter);
//D2Game.0x6FD10250
void __fastcall ESE_INTERCEPT_sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nState, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD10360
int32_t __fastcall ESE_INTERCEPT_sub_6FD10360(D2GameStrc* pGame, uint32_t nFlags, D2UnitStrc* pUnit, int32_t nDistance, int32_t(__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs);
//D2Game.0x6FD10630
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nAuraRange, int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*));
//D2Game.0x6FD106F0
int32_t __fastcall ESE_INTERCEPT_sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD10790
int32_t __fastcall ESE_INTERCEPT_sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter);
//D2Game.0x6FD107E0
int32_t __fastcall ESE_INTERCEPT_sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD107F0
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t a7, int32_t* a8);
//D2Game.0x6FD10880
int32_t __fastcall ESE_INTERCEPT_sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);
//D2Game.0x6FD108D0
void __fastcall ESE_INTERCEPT_sub_6FD108D0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId);
//D2Game.0x6FD10A50
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLMANA_Consume_6FD10A50(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD10C90
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int32_t nManaCost);
//D2Game.0x6FD10CE0
int32_t __fastcall ESE_INTERCEPT_sub_6FD10CE0(D2UnitStrc* pUnit);
//D2Game.0x6FD10D90
D2UnitFindDataStrc* __fastcall ESE_INTERCEPT_sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSize, int32_t nX, int32_t nY);
//D2Game.0x6FD10E20
void __fastcall ESE_INTERCEPT_sub_6FD10E20(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData);
//D2Game.0x6FD10E50
void __fastcall ESE_INTERCEPT_sub_6FD10E50(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);
//D2Game.0x6FD10EC0
D2StatListStrc* __fastcall ESE_INTERCEPT_sub_6FD10EC0(D2CurseStrc* pCurse);
//D2Game.0x6FD11260
D2StatListStrc* __fastcall ESE_INTERCEPT_sub_6FD11260(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel, int32_t nStatId, int32_t nState, StatListRemoveCallback pfRemoveStatCallback);
//D2Game.0x6FD11340
int32_t __fastcall ESE_INTERCEPT_sub_6FD11340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);
//D2Game.0x6FD11420
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD11420(D2GameStrc* pGame, int32_t nMissileId, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t nTargetX, int32_t nTargetY, int32_t bCheckItemQuantity);
//D2Game.0x6FD115E0
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId, int32_t nX, int32_t nY);
//D2Game.0x6FD11710
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD11710(D2GameStrc* pGame, int32_t nMissileId, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t nTargetX, int32_t nTargetY, int32_t bSkipCheck);
//D2Game.0x6FD118C0
int32_t __fastcall ESE_INTERCEPT_sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD119C0
int32_t __fastcall ESE_INTERCEPT_sub_6FD119C0(D2UnitStrc* pUnit);
//D2Game.0x6FD11AE0
void __fastcall ESE_INTERCEPT_sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);
//D2Game.0x6FD11B50
int32_t __fastcall ESE_INTERCEPT_D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int32_t nSkillId);
//D2Game.0x6FD11BA0
void __fastcall ESE_INTERCEPT_sub_6FD11BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD11C00
void __fastcall ESE_INTERCEPT_D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nDelay);
//D2Game.0x6FD11C90
int32_t __fastcall ESE_INTERCEPT_sub_6FD11C90(D2UnitStrc* pUnit, int32_t nStateId, int32_t a3);
//D2Game.0x6FD11D90
void __fastcall ESE_INTERCEPT_sub_6FD11D90(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nLength, int32_t nSkillId);
//D2Game.0x6FD11E40
void __fastcall ESE_INTERCEPT_sub_6FD11E40(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nElementalType, int32_t nDamage, int32_t nLength, int32_t* pResistStatId, int32_t* pElementalType);
//D2Game.0x6FD11FF0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD12060
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD120A0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD12150
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt03_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD12210
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo001_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD123D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD12670
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD126B0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD12800
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD12950
int32_t __fastcall ESE_INTERCEPT_sub_6FD12950(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);
//D2Game.0x6FD12BA0
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_Handler_6FD12BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5, int32_t a6, int32_t a7);
//D2Game.0x6FD12FD0
int32_t __fastcall ESE_INTERCEPT_sub_6FD12FD0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD13220
int32_t __fastcall ESE_INTERCEPT_sub_6FD13220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD13260
int32_t __fastcall ESE_INTERCEPT_sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);
//D2Game.0x6FD13330
int32_t __fastcall ESE_INTERCEPT_sub_6FD13330(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel, int32_t a6);
//D2Game.0x6FD13410
void __fastcall ESE_INTERCEPT_sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD13470
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction09_6FD13470(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillIdArg, int32_t a4);
//D2Game.0x6FD13610
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction10_6FD13610(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nSkillId);
//D2Game.0x6FD136E0
int32_t __fastcall ESE_INTERCEPT_sub_6FD136E0(D2UnitStrc* pUnit, int32_t nSkillId);
//D2Game.0x6FD13800
void __fastcall ESE_INTERCEPT_D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int32_t a2, int32_t nSkillId, int32_t nFlags);
//D2Game.0x6FD13B20
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pPortal, int32_t nDestLevel, int32_t nSourceLevel);
//D2Game.0x6FD13DF0
int32_t __fastcall ESE_INTERCEPT_D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nDestLevel, D2UnitStrc** ppSourceUnit, int32_t nObjectId, int32_t bPerm);
//D2Game.0x6FD14020
int32_t __fastcall ESE_INTERCEPT_D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t* pX, int32_t* pY);
//D2Game.0x6FD140D0
void __fastcall ESE_INTERCEPT_sub_6FD140D0(int32_t* pX, int32_t* pY);
//D2Game.0x6FD14120
void __fastcall ESE_INTERCEPT_sub_6FD14120(int32_t* pX, int32_t* pY);
//D2Game.0x6FD14170
void __fastcall ESE_INTERCEPT_sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* a3, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nVelocity);
//D2Game.0x6FD14260
void __fastcall ESE_INTERCEPT_sub_6FD14260(D2GameStrc* pGame, int32_t nMissiles, D2MissileStrc* missileParams);
//D2Game.0x6FD14370
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction06_6FD14370(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD14400
void __fastcall ESE_INTERCEPT_sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nDoFunc, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD14430
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg);
//D2Game.0x6FD146D0
void __fastcall ESE_INTERCEPT_sub_6FD146D0(D2GameStrc* pGame, D2UnitStrc* pUnit);
//D2Game.0x6FD14770
void __fastcall ESE_INTERCEPT_sub_6FD14770(D2GameStrc* pGame, int32_t nFlags, D2UnitStrc* pUnit, int32_t nSkillLevel, int32_t nRange, CurseCallbackFunc pfCurse);
//D2Game.0x6FD149B0
void __fastcall ESE_INTERCEPT_sub_6FD149B0(D2GameStrc* pGame, D2EffectStrc* pEffect);
//D2Game.0x6FD14BD0
void __fastcall ESE_INTERCEPT_sub_6FD14BD0(D2GameStrc* pGame, int32_t nFlags, int32_t nX, int32_t nY, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, void* pfAreaEffect);
//D2Game.0x6FD14C30
void __fastcall ESE_INTERCEPT_sub_6FD14C30(D2UnitStrc* pUnit);
//D2Game.0x6FD14C60
void __fastcall ESE_INTERCEPT_D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t bRemove);
//D2Game.0x6FD14CC0
void __fastcall ESE_INTERCEPT_D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit);
//D2Game.0x6FD14D20
void __fastcall ESE_INTERCEPT_sub_6FD14D20(D2UnitStrc* pUnit, int32_t nUnused, D2MonSkillInfoStrc* pMonSkillInfo);
//D2Game.0x6FD14DD0
int32_t __fastcall ESE_INTERCEPT_D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD14EC0
void __fastcall ESE_INTERCEPT_D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD14F70
void __fastcall ESE_INTERCEPT_sub_6FD14F70(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int32_t nDelay);
//D2Game.0x6FD15080
void __fastcall ESE_INTERCEPT_sub_6FD15080(D2UnitStrc* pUnit, int32_t a2);
//D2Game.0x6FD150A0
int32_t __fastcall ESE_INTERCEPT_sub_6FD150A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);
//D2Game.0x6FD15190
int32_t __fastcall ESE_INTERCEPT_sub_6FD15190(D2UnitStrc* pUnit, int32_t nSpecialState);
//D2Game.0x6FD15210
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);
//D2Game.0x6FD15320
int32_t __fastcall ESE_INTERCEPT_sub_6FD15320(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg);
//D2Game.0x6FD15340
int32_t __fastcall ESE_INTERCEPT_sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMissileId);
//D2Game.0x6FD15460
int32_t __fastcall ESE_INTERCEPT_sub_6FD15460(D2UnitStrc* pUnit);
//D2Game.0x6FD15470
void __fastcall ESE_INTERCEPT_sub_6FD15470(D2UnitStrc* pUnit, int32_t nAttackRate);
//D2Game.0x6FD154D0
void __fastcall ESE_INTERCEPT_sub_6FD154D0(D2UnitStrc* pUnit);
//D2Game.0x6FD15500
int32_t __fastcall ESE_INTERCEPT_sub_6FD15500(D2UnitStrc* pUnit);
//D2Game.0x6FD15580
int32_t __fastcall ESE_INTERCEPT_D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int32_t bFromMonster, int32_t nSkillId, int32_t nSkillLevel, int32_t* pSpawnMode, int32_t* pX, int32_t* pY);
//D2Game.0x6FD155E0
void __fastcall ESE_INTERCEPT_sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage, int32_t a8);
//D2Game.0x6FD15650
void __fastcall ESE_INTERCEPT_sub_6FD15650(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, uint16_t wResultFlags, int32_t a5, D2DamageStrc* pDamage, int32_t a7);
//D2Game.0x6FD156A0
D2UnitEventStrc* __fastcall ESE_INTERCEPT_sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t a4, int32_t a5, int32_t nEventFunc, int32_t a7, int32_t a8);
//D2Game.0x6FC808D0
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt18_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD0F8B0_t sub_6FD0F8B0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0F8B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nValue);

extern sub_6FD0FA00_t sub_6FD0FA00_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD0FA00(D2UnitStrc* pUnit, D2UnitStrc* pTarget, uint32_t nAuraFilter);

extern sub_6FD0FDD0_t sub_6FD0FDD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0FDD0(D2UnitStrc* pUnit);

extern sub_6FD0FE50_t sub_6FD0FE50_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0FE50(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs);

extern sub_6FD0FE80_t sub_6FD0FE80_Original;
void __fastcall ESE_INTERCEPT_sub_6FD0FE80(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t(__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pCallbackArgs, int32_t bCheckMonAuraFlag, const char* szFile, int32_t nLine);

extern sub_6FD10140_t sub_6FD10140_Original;
void __fastcall ESE_INTERCEPT_sub_6FD10140(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nUnused);

extern sub_6FD10200_t sub_6FD10200_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10200(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, D2DamageStrc* pDamage, uint32_t nAuraFilter);

extern sub_6FD10250_t sub_6FD10250_Original;
void __fastcall ESE_INTERCEPT_sub_6FD10250(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nState, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD10360_t sub_6FD10360_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10360(D2GameStrc* pGame, uint32_t nFlags, D2UnitStrc* pUnit, int32_t nDistance, int32_t(__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs);

extern SKILLS_FindAuraTarget_t SKILLS_FindAuraTarget_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nAuraRange, int32_t(__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*));

extern sub_6FD106F0_t sub_6FD106F0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD106F0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern sub_6FD10790_t sub_6FD10790_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10790(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter);

extern sub_6FD107E0_t sub_6FD107E0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD107E0(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern sub_6FD107F0_t sub_6FD107F0_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD107F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nX, int32_t nY, int32_t nAuraRange, uint32_t nAuraFilter, int32_t a7, int32_t* a8);

extern sub_6FD10880_t sub_6FD10880_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10880(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern sub_6FD108D0_t sub_6FD108D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD108D0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId);

extern D2GAME_SKILLMANA_Consume_6FD10A50_t D2GAME_SKILLMANA_Consume_6FD10A50_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLMANA_Consume_6FD10A50(D2GameStrc* pGame, D2UnitStrc* pPlayer, int32_t nSkillId, int32_t nSkillLevel);

extern D2GAME_SKILLMANA_AuraConsume_6FD10C90_t D2GAME_SKILLMANA_AuraConsume_6FD10C90_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int32_t nManaCost);

extern sub_6FD10CE0_t sub_6FD10CE0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD10CE0(D2UnitStrc* pUnit);

extern sub_6FD10D90_t sub_6FD10D90_Original;
D2UnitFindDataStrc* __fastcall ESE_INTERCEPT_sub_6FD10D90(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSize, int32_t nX, int32_t nY);

extern sub_6FD10E20_t sub_6FD10E20_Original;
void __fastcall ESE_INTERCEPT_sub_6FD10E20(D2GameStrc* pGame, D2UnitFindDataStrc* pUnitFindData);

extern sub_6FD10E50_t sub_6FD10E50_Original;
void __fastcall ESE_INTERCEPT_sub_6FD10E50(D2UnitStrc* pUnit, int32_t nState, D2StatListStrc* pStatList);

extern sub_6FD10EC0_t sub_6FD10EC0_Original;
D2StatListStrc* __fastcall ESE_INTERCEPT_sub_6FD10EC0(D2CurseStrc* pCurse);

extern sub_6FD11260_t sub_6FD11260_Original;
D2StatListStrc* __fastcall ESE_INTERCEPT_sub_6FD11260(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel, int32_t nStatId, int32_t nState, StatListRemoveCallback pfRemoveStatCallback);

extern sub_6FD11340_t sub_6FD11340_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD11340(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

extern sub_6FD11420_t sub_6FD11420_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD11420(D2GameStrc* pGame, int32_t nMissileId, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t nTargetX, int32_t nTargetY, int32_t bCheckItemQuantity);

extern D2GAME_CreateMissile_6FD115E0_t D2GAME_CreateMissile_6FD115E0_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nMissileId, int32_t nX, int32_t nY);

extern sub_6FD11710_t sub_6FD11710_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD11710(D2GameStrc* pGame, int32_t nMissileId, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t nX, int32_t nY, int32_t nTargetX, int32_t nTargetY, int32_t bSkipCheck);

extern sub_6FD118C0_t sub_6FD118C0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD118C0(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern sub_6FD119C0_t sub_6FD119C0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD119C0(D2UnitStrc* pUnit);

extern sub_6FD11AE0_t sub_6FD11AE0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD11AE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

extern D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50_t D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_CheckSkillIfUnitsClassSkill_6FD11B50(D2UnitStrc* pUnit, int32_t nSkillId);

extern sub_6FD11BA0_t sub_6FD11BA0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD11BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern D2GAME_SKILLS_SetDelay_6FD11C00_t D2GAME_SKILLS_SetDelay_6FD11C00_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SKILLS_SetDelay_6FD11C00(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nDelay);

extern sub_6FD11C90_t sub_6FD11C90_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD11C90(D2UnitStrc* pUnit, int32_t nStateId, int32_t a3);

extern sub_6FD11D90_t sub_6FD11D90_Original;
void __fastcall ESE_INTERCEPT_sub_6FD11D90(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nLength, int32_t nSkillId);

extern sub_6FD11E40_t sub_6FD11E40_Original;
void __fastcall ESE_INTERCEPT_sub_6FD11E40(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nElementalType, int32_t nDamage, int32_t nLength, int32_t* pResistStatId, int32_t* pElementalType);

extern SKILLS_SrvSt01_Attack_LeftHandSwing_t SKILLS_SrvSt01_Attack_LeftHandSwing_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt01_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt65_Throw_LeftHandThrow_t SKILLS_SrvSt65_Throw_LeftHandThrow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt65_Throw_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt02_Kick_t SKILLS_SrvSt02_Kick_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt02_Kick(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvSt03_Unsummon_t SKILLS_SrvSt03_Unsummon_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt03_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo001_Attack_LeftHandSwing_t SKILLS_SrvDo001_Attack_LeftHandSwing_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo001_Attack_LeftHandSwing(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws_t SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo002_Kick_PowerStrike_MonIceSpear_Impale_Bash_Stun_Concentrate_BearSmite_Vengeance_Berserk_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo004_Unsummon_t SKILLS_SrvDo004_Unsummon_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo004_Unsummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo003_Throw_t SKILLS_SrvDo003_Throw_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo003_Throw(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern SKILLS_SrvDo005_LeftHandThrow_t SKILLS_SrvDo005_LeftHandThrow_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvDo005_LeftHandThrow(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD12950_t sub_6FD12950_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD12950(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);

extern D2GAME_SKILLS_Handler_6FD12BA0_t D2GAME_SKILLS_Handler_6FD12BA0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_SKILLS_Handler_6FD12BA0(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5, int32_t a6, int32_t a7);

extern sub_6FD12FD0_t sub_6FD12FD0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD12FD0(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern sub_6FD13220_t sub_6FD13220_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD13220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD13260_t sub_6FD13260_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD13260(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t a5);

extern sub_6FD13330_t sub_6FD13330_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD13330(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a5, int32_t nSkillId, int32_t nSkillLevel, int32_t a6);

extern sub_6FD13410_t sub_6FD13410_Original;
void __fastcall ESE_INTERCEPT_sub_6FD13410(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern D2GAME_MONSTERS_AiFunction09_6FD13470_t D2GAME_MONSTERS_AiFunction09_6FD13470_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction09_6FD13470(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillIdArg, int32_t a4);

extern D2GAME_MONSTERS_AiFunction10_6FD13610_t D2GAME_MONSTERS_AiFunction10_6FD13610_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction10_6FD13610(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t a3, int32_t nSkillId);

extern sub_6FD136E0_t sub_6FD136E0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD136E0(D2UnitStrc* pUnit, int32_t nSkillId);

extern D2GAME_AssignSkill_6FD13800_t D2GAME_AssignSkill_6FD13800_Original;
void __fastcall ESE_INTERCEPT_D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int32_t a2, int32_t nSkillId, int32_t nFlags);

extern D2GAME_CreateLinkPortal_6FD13B20_t D2GAME_CreateLinkPortal_6FD13B20_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pPortal, int32_t nDestLevel, int32_t nSourceLevel);

extern D2GAME_CreatePortalObject_6FD13DF0_t D2GAME_CreatePortalObject_6FD13DF0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int32_t nX, int32_t nY, int32_t nDestLevel, D2UnitStrc** ppSourceUnit, int32_t nObjectId, int32_t bPerm);

extern D2GAME_GetXAndYFromTargetUnit_6FD14020_t D2GAME_GetXAndYFromTargetUnit_6FD14020_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t* pX, int32_t* pY);

extern sub_6FD140D0_t sub_6FD140D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD140D0(int32_t* pX, int32_t* pY);

extern sub_6FD14120_t sub_6FD14120_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14120(int32_t* pX, int32_t* pY);

extern sub_6FD14170_t sub_6FD14170_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14170(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* a3, int32_t nMissileId, int32_t nSkillId, int32_t nSkillLevel, int32_t nVelocity);

extern sub_6FD14260_t sub_6FD14260_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14260(D2GameStrc* pGame, int32_t nMissiles, D2MissileStrc* missileParams);

extern D2GAME_MONSTERS_AiFunction06_6FD14370_t D2GAME_MONSTERS_AiFunction06_6FD14370_Original;
void __fastcall ESE_INTERCEPT_D2GAME_MONSTERS_AiFunction06_6FD14370(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD14400_t sub_6FD14400_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14400(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nDoFunc, int32_t nSkillId, int32_t nSkillLevel);

extern D2GAME_SummonPet_6FD14430_t D2GAME_SummonPet_6FD14430_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg);

extern sub_6FD146D0_t sub_6FD146D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD146D0(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern sub_6FD14770_t sub_6FD14770_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14770(D2GameStrc* pGame, int32_t nFlags, D2UnitStrc* pUnit, int32_t nSkillLevel, int32_t nRange, CurseCallbackFunc pfCurse);

extern sub_6FD149B0_t sub_6FD149B0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD149B0(D2GameStrc* pGame, D2EffectStrc* pEffect);

extern sub_6FD14BD0_t sub_6FD14BD0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14BD0(D2GameStrc* pGame, int32_t nFlags, int32_t nX, int32_t nY, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, void* pfAreaEffect);

extern sub_6FD14C30_t sub_6FD14C30_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14C30(D2UnitStrc* pUnit);

extern D2GAME_SetSkills_6FD14C60_t D2GAME_SetSkills_6FD14C60_Original;
void __fastcall ESE_INTERCEPT_D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel, int32_t bRemove);

extern D2GAME_RefreshPassiveSkills_6FD14CC0_t D2GAME_RefreshPassiveSkills_6FD14CC0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit);

extern sub_6FD14D20_t sub_6FD14D20_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14D20(D2UnitStrc* pUnit, int32_t nUnused, D2MonSkillInfoStrc* pMonSkillInfo);

extern D2GAME_RollElementalDamage_6FD14DD0_t D2GAME_RollElementalDamage_6FD14DD0_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern D2GAME_RollPhysicalDamage_6FD14EC0_t D2GAME_RollPhysicalDamage_6FD14EC0_Original;
void __fastcall ESE_INTERCEPT_D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD14F70_t sub_6FD14F70_Original;
void __fastcall ESE_INTERCEPT_sub_6FD14F70(D2GameStrc* pGame, D2UnitStrc* pUnused, D2UnitStrc* pUnit, int32_t nDelay);

extern sub_6FD15080_t sub_6FD15080_Original;
void __fastcall ESE_INTERCEPT_sub_6FD15080(D2UnitStrc* pUnit, int32_t a2);

extern sub_6FD150A0_t sub_6FD150A0_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD150A0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

extern sub_6FD15190_t sub_6FD15190_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD15190(D2UnitStrc* pUnit, int32_t nSpecialState);

extern sub_6FD15210_t sub_6FD15210_Original;
D2UnitStrc* __fastcall ESE_INTERCEPT_sub_6FD15210(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int32_t nSkillId, int32_t nSkillLevel);

extern sub_6FD15320_t sub_6FD15320_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD15320(D2UnitStrc* pUnit, D2UnitFindArgStrc* pArg);

extern sub_6FD15340_t sub_6FD15340_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD15340(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nMissileId);

extern sub_6FD15460_t sub_6FD15460_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD15460(D2UnitStrc* pUnit);

extern sub_6FD15470_t sub_6FD15470_Original;
void __fastcall ESE_INTERCEPT_sub_6FD15470(D2UnitStrc* pUnit, int32_t nAttackRate);

extern sub_6FD154D0_t sub_6FD154D0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD154D0(D2UnitStrc* pUnit);

extern sub_6FD15500_t sub_6FD15500_Original;
int32_t __fastcall ESE_INTERCEPT_sub_6FD15500(D2UnitStrc* pUnit);

extern D2GAME_GetSummonIdFromSkill_6FD15580_t D2GAME_GetSummonIdFromSkill_6FD15580_Original;
int32_t __fastcall ESE_INTERCEPT_D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int32_t bFromMonster, int32_t nSkillId, int32_t nSkillLevel, int32_t* pSpawnMode, int32_t* pX, int32_t* pY);

extern sub_6FD155E0_t sub_6FD155E0_Original;
void __fastcall ESE_INTERCEPT_sub_6FD155E0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int32_t nSkillId, int32_t nSkillLevel, D2DamageStrc* pDamage, int32_t a8);

extern sub_6FD15650_t sub_6FD15650_Original;
void __fastcall ESE_INTERCEPT_sub_6FD15650(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, uint16_t wResultFlags, int32_t a5, D2DamageStrc* pDamage, int32_t a7);

extern sub_6FD156A0_t sub_6FD156A0_Original;
D2UnitEventStrc* __fastcall ESE_INTERCEPT_sub_6FD156A0(D2GameStrc* pGame, D2UnitStrc* pUnit, uint8_t nTimerType, int32_t a4, int32_t a5, int32_t nEventFunc, int32_t a7, int32_t a8);

extern SKILLS_SrvSt18_Attract_t SKILLS_SrvSt18_Attract_Original;
int32_t __fastcall ESE_INTERCEPT_SKILLS_SrvSt18_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int32_t nSkillId, int32_t nSkillLevel);
